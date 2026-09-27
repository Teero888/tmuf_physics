#include "reference/world.h"

#include <stdlib.h>
#include <string.h>

#define TREE_COLLISION 0x80u /* CPlugTree::SFlags collisionEnabled */

static void *grow(void *p, uint32_t *cap, uint32_t count, size_t size) {
  if (count < *cap)
    return p;
  uint32_t n = *cap ? *cap * 2 : 256;
  void *q = realloc(p, size * n);
  if (q)
    *cap = n;
  return q;
}

static gm_iso4 iso_from_archive(const float v[12]) {
  gm_iso4 iso;
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
      iso.r.m[r][c] = v[r * 3 + c];
  iso.t = v3(v[9], v[10], v[11]);
  return iso;
}

static gm_iso4 iso_from_scene(const tmuf_iso *s) {
  gm_iso4 iso;
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
      iso.r.m[r][c] = s->m[r][c];
  iso.t = v3(s->t[0], s->t[1], s->t[2]);
  return iso;
}

typedef struct build_ctx {
  ref_world *w;
  tmuf_assets *assets;
  uint32_t corpus;
  int error;
  const tmuf_scene *scene;
  uint8_t materials; /* TMUF_MATERIALS_* of the corpus */
} build_ctx;

static const ref_surf *get_surf(build_ctx *b, tmuf_asset *owner, tmuf_gbx_node *surface_node) {
  tmuf_asset *sa;
  tmuf_gbx_node *sn = tmuf_assets_follow(b->assets, owner, surface_node, &sa);
  if (!sn || !sn->data || sn->class_id != 0x0900c000u)
    return NULL;
  /* one ref_surf per surface node and material mode */
  for (uint32_t i = b->w->surf_count; i-- > 0;)
    if (b->w->surfs[i]->key == sn && b->w->surfs[i]->materials == b->materials)
      return b->w->surfs[i];
  const tmuf_plug_surface *surf = sn->data;
  tmuf_asset *ga;
  tmuf_gbx_node *gn = tmuf_assets_follow(b->assets, sa, surf->geom, &ga);
  if (!gn || !gn->data || gn->class_id != 0x0900f000u)
    return NULL;
  const tmuf_plug_surface_geom *geom = gn->data;
  ref_surf *r = calloc(1, sizeof *r);
  uint8_t *mats = calloc(surf->material_count ? surf->material_count : 1, 1);
  if (!r || !mats) {
    free(r);
    free(mats);
    b->error = 1;
    return NULL;
  }
  r->key = sn;
  r->materials = b->materials;
  r->type = geom->type;
  r->geom_box.center = v3(geom->bbox[0], geom->bbox[1], geom->bbox[2]);
  r->geom_box.half = v3(geom->bbox[3], geom->bbox[4], geom->bbox[5]);
  r->material = geom->material_id;
  memcpy(r->params, geom->params, sizeof r->params);
  r->vertex_count = geom->vertex_count;
  r->triangle_count = geom->triangle_count;
  r->cell_count = geom->cell_count;
  r->vertices = geom->vertices;
  r->triangles = geom->triangles;
  r->cells = geom->cells;
  r->material_count = surf->material_count;
  for (uint32_t i = 0; i < surf->material_count; i++) {
    const tmuf_plug_surface_material *m = &surf->materials[i];
    uint8_t id = (uint8_t)m->id;
    if (m->ref) {
      tmuf_asset *ma;
      tmuf_gbx_node *mn = tmuf_assets_follow(b->assets, sa, m->ref, &ma);
      if (mn && mn->data && mn->class_id == 0x09079000u && ((tmuf_plug_material *)mn->data)->has_surface)
        id = ((tmuf_plug_material *)mn->data)->surface_id;
      /* StaticSolidSurfaceAssembler::ApplyMaterialRemapToSurface */
      char path[600];
      uint8_t remapped;
      if (b->materials != TMUF_MATERIALS_OWN && m->ref->external &&
          tmuf_packset_resolve(b->assets->set, &sa->gbx, m->ref, sa->path, path, sizeof path).pack >= 0 &&
          tmuf_scene_remap_material(b->scene, b->materials, path, &remapped))
        id = remapped;
    }
    mats[i] = id;
  }
  r->material_ids = mats;
  ref_world *w = b->w;
  ref_surf **s = grow(w->surfs, &w->surf_cap, w->surf_count, sizeof *s);
  if (!s) {
    b->error = 1;
    free(r);
    free(mats);
    return NULL;
  }
  w->surfs = s;
  w->surfs[w->surf_count++] = r;
  return r;
}

/* CHmsCollisionManager::SGroup::AddStaticSurfacesFromTree: children first,
   then the tree's own surface. */
static void add_tree(build_ctx *b, tmuf_asset *owner, tmuf_gbx_node *tree_node, const gm_iso4 *parent, int depth) {
  if (depth > 64 || b->error)
    return;
  tmuf_asset *ta;
  tmuf_gbx_node *tn = tmuf_assets_follow(b->assets, owner, tree_node, &ta);
  if (!tn || !tn->data || !tn->cls)
    return;
  uint32_t cls = tn->cls->id;
  if (cls != 0x0904f000u && cls != 0x09015000u && cls != 0x09062000u)
    return;
  const tmuf_plug_tree *t = tn->data;
  if (!(t->flags & TREE_COLLISION))
    return;
  gm_iso4 iso = *parent;
  if (t->has_iso) {
    gm_iso4 local = iso_from_archive(t->iso);
    iso = iso4_mult(&local, parent);
  }
  for (uint32_t i = 0; i < t->child_count; i++)
    add_tree(b, ta, t->children[i], &iso, depth + 1);
  if (!t->surface)
    return;
  const ref_surf *surf = get_surf(b, ta, t->surface);
  if (!surf || 0.0f > surf->geom_box.half.x)
    return;
  ref_world *w = b->w;
  ref_static_record *rec = grow(w->records, &w->record_cap, w->record_count, sizeof *rec);
  if (!rec) {
    b->error = 1;
    return;
  }
  w->records = rec;
  rec = &w->records[w->record_count++];
  rec->bounds = box_transform(&surf->geom_box, &iso);
  rec->iso = iso;
  rec->surf = surf;
  rec->tree_flags = t->flags;
  rec->corpus = b->corpus;
}

/* ---- GmOctree<SColOctreeCell>::Build with useBintree = 1, no depth,
   leaf or volume limits ---- */

static uint32_t push_cell(ref_world *w, gm_box bounds, int32_t record) {
  ref_static_cell *c = grow(w->cells, &w->cell_cap, w->cell_count, sizeof *c);
  if (!c)
    return ~0u;
  w->cells = c;
  c = &w->cells[w->cell_count];
  c->bounds = bounds;
  c->subtree_count = 1;
  c->record = record;
  return w->cell_count++;
}

static gm_box span_bounds(const ref_world *w, const uint32_t *idx, uint32_t n) {
  gm_box b = w->records[idx[0]].bounds;
  for (uint32_t i = 1; i < n; i++)
    box_union(&b, &w->records[idx[i]].bounds);
  return b;
}

static int should_split(const gm_box *b, uint32_t count) {
  if (count <= 1)
    return 0;
  float e2 = b->half.x * b->half.x + b->half.y * b->half.y + b->half.z * b->half.z;
  return e2 != 0.0f;
}

enum { PART_OVERLAP, PART_BELOW, PART_ABOVE };

static void append_leaf(ref_world *w, uint32_t record) { push_cell(w, w->records[record].bounds, (int32_t)record); }

/* Moves the entries of `sel_part` out of (rem, parts) into sel, filling the
   gap with the last entry (the game's tail-remove order). */
static uint32_t extract(uint32_t *rem, uint8_t *parts, uint32_t *rem_n, uint8_t sel_part, uint32_t *sel) {
  uint32_t n = 0, i = 0;
  while (i < *rem_n) {
    if (parts[i] != sel_part) {
      i++;
      continue;
    }
    sel[n++] = rem[i];
    rem[i] = rem[*rem_n - 1];
    parts[i] = parts[*rem_n - 1];
    (*rem_n)--;
  }
  return n;
}

static uint32_t build_bintree(ref_world *w, const uint32_t *src, uint32_t n, int *err) {
  if (n == 0 || *err)
    return 0;
  gm_box span = span_bounds(w, src, n);
  w->cells[w->cell_count - 1].bounds = span;
  if (!should_split(&span, n)) {
    for (uint32_t i = 0; i < n; i++)
      append_leaf(w, src[i]);
    return n + 1;
  }
  int axis = box_longest_axis(&span);
  float plane = v3_comp(span.center, axis);
  uint32_t *rem = malloc(sizeof *rem * n), *sel = malloc(sizeof *sel * n);
  uint8_t *parts = malloc(n);
  if (!rem || !sel || !parts) {
    free(rem), free(sel), free(parts);
    *err = 1;
    return 0;
  }
  memcpy(rem, src, sizeof *rem * n);
  for (uint32_t i = 0; i < n; i++) {
    const gm_box *b = &w->records[src[i]].bounds;
    float c = v3_comp(b->center, axis), h = v3_comp(b->half, axis);
    parts[i] = c + h <= plane ? PART_BELOW : c - h >= plane ? PART_ABOVE : PART_OVERLAP;
  }
  uint32_t rem_n = n, emitted = 1;
  static const uint8_t ORDER[2] = {PART_BELOW, PART_ABOVE};
  for (int k = 0; k < 2; k++) {
    uint32_t sel_n = extract(rem, parts, &rem_n, ORDER[k], sel);
    if (sel_n == 1) {
      append_leaf(w, sel[0]);
      emitted++;
    } else if (sel_n > 1) {
      uint32_t *copy = malloc(sizeof *copy * sel_n);
      if (!copy) {
        *err = 1;
        break;
      }
      memcpy(copy, sel, sizeof *copy * sel_n);
      uint32_t internal = push_cell(w, span_bounds(w, copy, sel_n), -1);
      uint32_t child = build_bintree(w, copy, sel_n, err);
      w->cells[internal].subtree_count = child;
      emitted += child;
      free(copy);
    }
  }
  if (rem_n != n && rem_n > 1) {
    uint32_t internal = push_cell(w, span_bounds(w, rem, rem_n), -1);
    uint32_t child = build_bintree(w, rem, rem_n, err);
    w->cells[internal].subtree_count = child;
    emitted += child;
  } else {
    for (uint32_t i = 0; i < rem_n; i++)
      append_leaf(w, rem[i]);
    emitted += rem_n;
  }
  free(rem), free(sel), free(parts);
  return emitted;
}

ref_surf *ref_world_surface(ref_world *w, tmuf_assets *assets, tmuf_asset *owner, tmuf_gbx_node *surface) {
  build_ctx b = {w, assets, 0, 0, NULL, TMUF_MATERIALS_OWN};
  return (ref_surf *)get_surf(&b, owner, surface);
}

int ref_world_build(ref_world *w, tmuf_scene *scene) {
  memset(w, 0, sizeof *w);
  build_ctx b = {w, &scene->assets, 0, 0, scene, TMUF_MATERIALS_OWN};
  for (uint32_t i = 0; i < scene->corpus_count && !b.error; i++) {
    if (scene->corpora[i].trigger || scene->corpora[i].collision_group != 4)
      continue; /* race triggers and non-static items are not in the static group */
    b.corpus = i;
    b.materials = scene->corpora[i].materials;
    gm_iso4 iso = iso_from_scene(&scene->corpora[i].iso);
    add_tree(&b, scene->corpora[i].owner, scene->corpora[i].tree, &iso, 0);
  }
  if (b.error)
    return 0;
  gm_box empty = {{0, 0, 0}, {0, 0, 0}};
  push_cell(w, empty, -1);
  if (w->record_count) {
    uint32_t *src = malloc(sizeof *src * w->record_count);
    if (!src)
      return 0;
    for (uint32_t i = 0; i < w->record_count; i++)
      src[i] = i;
    int err = 0;
    build_bintree(w, src, w->record_count, &err);
    free(src);
    if (err)
      return 0;
  }
  w->cells[0].subtree_count = w->cell_count;
  return 1;
}

void ref_world_free(ref_world *w) {
  for (uint32_t i = 0; i < w->surf_count; i++) {
    free((void *)w->surfs[i]->material_ids);
    free(w->surfs[i]);
  }
  free(w->surfs);
  free(w->records);
  free(w->cells);
  memset(w, 0, sizeof *w);
}
