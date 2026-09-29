/* What a track draws (tmuf_track_visuals): the scene's visible visuals as
   plain data. Meshes and materials are shared between the instances that
   place them; a material names the texture files its shader samples. */

#include "common/visuals.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { CLS_VISUAL = 0x09006000u, CLS_SHADER = 0x09002000u, CLS_MATERIAL = 0x09079000u, CLS_SAMPLER = 0x0907e000u,
       CLS_BITMAP = 0x09011000u };

static uint32_t node_class(const tmuf_gbx_node *n) { return n && n->cls ? n->cls->id : 0; }

/* pointer -> index, open addressing */
typedef struct ptr_map {
  uint32_t cap;
  const void **keys;
  uint32_t *values;
} ptr_map;

static int map_init(ptr_map *m, uint32_t n) {
  m->cap = 64;
  while (m->cap < n * 2u)
    m->cap *= 2;
  m->keys = calloc(m->cap, sizeof *m->keys);
  m->values = calloc(m->cap, sizeof *m->values);
  return m->keys && m->values;
}

static void map_free(ptr_map *m) {
  free(m->keys);
  free(m->values);
}

static uint32_t *map_slot(ptr_map *m, const void *key, int *found) {
  uint32_t h = (uint32_t)(((uintptr_t)key >> 4) * 2654435761u) & (m->cap - 1u);
  while (m->keys[h] && m->keys[h] != key)
    h = (h + 1u) & (m->cap - 1u);
  *found = m->keys[h] != NULL;
  m->keys[h] = key;
  return &m->values[h];
}

static const char *dup(tmuf_arena *a, const char *s) { return s ? tmuf_arena_strndup(a, s, strlen(s)) : NULL; }

typedef struct builder {
  tmuf_scene *scene;
  tmuf_arena *arena;
  tmuf_visual_mesh *meshes;
  tmuf_visual_material *materials;
  uint32_t mesh_count, material_count;
  ptr_map mesh_map, material_map;
  int oom;
} builder;

/* the image file a bitmap loads: on disk, else inside the packs */
static void bitmap_file(builder *b, tmuf_asset *owner, tmuf_gbx_node *bitmap, tmuf_visual_texture *t) {
  t->file = t->pack_file = NULL;
  tmuf_asset *ba;
  tmuf_gbx_node *bn = tmuf_assets_follow(&b->scene->assets, owner, bitmap, &ba);
  if (node_class(bn) != CLS_BITMAP || !bn->data)
    return;
  const tmuf_plug_bitmap *bm = bn->data;
  char path[1200];
  if (bm->image && bm->image->external &&
      tmuf_packset_resolve(b->scene->assets.set, &ba->gbx, bm->image, ba->path, path, sizeof path).pack >= 0) {
    t->pack_file = dup(b->arena, path);
    return;
  }
  if (!bm->image || !tmuf_packset_resolve_file(b->scene->assets.set, &ba->gbx, bm->image, ba->path, path, sizeof path)) {
    if (getenv("TMUF_VISUALS_DEBUG")) {
      char stored[600] = "";
      if (bm->image && bm->image->external)
        tmuf_gbx_external_path(&ba->gbx, bm->image, "", stored, sizeof stored);
      char inpack[600] = "";
      if (bm->image && bm->image->external)
        tmuf_packset_resolve(b->scene->assets.set, &ba->gbx, bm->image, ba->path, inpack, sizeof inpack);
      fprintf(stderr, "bitmap [pack: %s] %s: image %s %s class %08x file %s ancestor %u\n", inpack, ba->path,
              bm->image ? (bm->image->external ? "external" : "inline") : "none", stored,
              bm->image ? bm->image->class_id : 0, bm->image && bm->image->file ? bm->image->file : "-",
              ba->gbx.ancestor_level);
    }
    return;
  }
  t->file = dup(b->arena, path);
}

/* the textures of a shader: its sampler addresses, the material's custom
   bitmaps replacing those of the same sampler name */
static void shader_textures(builder *b, tmuf_visual_material *m, tmuf_asset *sa, const tmuf_plug_shader *sh,
                            const tmuf_plug_material_custom *custom, tmuf_asset *ca) {
  tmuf_visual_texture *t = TMUF_ARENA_ARRAY(b->arena, tmuf_visual_texture, sh->address_count ? sh->address_count : 1);
  if (!t) {
    b->oom = 1;
    return;
  }
  uint32_t n = 0;
  for (uint32_t i = 0; i < sh->address_count; i++) {
    tmuf_asset *aa;
    tmuf_gbx_node *an = tmuf_assets_follow(&b->scene->assets, sa, sh->addresses[i], &aa);
    if (node_class(an) != CLS_SAMPLER || !an->data)
      continue;
    const tmuf_plug_bitmap_address *ad = an->data;
    tmuf_gbx_node *bitmap = ad->bitmap;
    tmuf_asset *bowner = aa;
    for (uint32_t k = 0; custom && k < custom->bitmap_count; k++)
      if (custom->bitmap_names[k] && ad->sampler && strcmp(custom->bitmap_names[k], ad->sampler) == 0) {
        bitmap = custom->bitmaps[k];
        bowner = ca;
        break;
      }
    t[n].sampler = dup(b->arena, ad->sampler ? ad->sampler : "");
    t[n].file = t[n].pack_file = NULL;
    if (bitmap)
      bitmap_file(b, bowner, bitmap, &t[n]);
    n++;
  }
  m->textures = t;
  m->texture_count = n;
}

/* the material of a visual: the tree's material, else its shader, else the
   visual's own material; UINT32_MAX for none */
static uint32_t material_of(builder *b, const tmuf_scene_visual *v, tmuf_asset *visual_owner,
                            const tmuf_plug_visual *visual) {
  struct {
    tmuf_asset *owner;
    tmuf_gbx_node *ref;
  } refs[3] = {{v->owner, v->material}, {v->owner, v->shader}, {visual_owner, visual->material}};
  for (int r = 0; r < 3; r++) {
    if (!refs[r].ref)
      continue;
    tmuf_asset *na;
    tmuf_gbx_node *n = tmuf_assets_follow(&b->scene->assets, refs[r].owner, refs[r].ref, &na);
    const uint32_t cls = node_class(n);
    if (!n || !n->data || (cls != CLS_MATERIAL && cls != CLS_SHADER))
      continue;
    int found;
    uint32_t *slot = map_slot(&b->material_map, n, &found);
    if (found)
      return *slot;
    tmuf_visual_material *m = &b->materials[b->material_count];
    memset(m, 0, sizeof *m);
    m->name = dup(b->arena, refs[r].ref->external ? na->path : "");
    tmuf_asset *sa = na, *ca = NULL;
    const tmuf_plug_material_custom *custom = NULL;
    tmuf_gbx_node *sn = cls == CLS_SHADER ? n
                                          : tmuf_scene_material_shader(b->scene, refs[r].owner, refs[r].ref, &sa,
                                                                       &custom, &ca);
    if (node_class(sn) == CLS_SHADER && sn->data) {
      const tmuf_plug_shader *sh = sn->data;
      m->has_shader_flags = sh->has_flags;
      m->shader_flags[0] = sh->flags[0];
      m->shader_flags[1] = sh->flags[1];
      m->has_render_state = sh->has_apply_state;
      m->render_state[0] = sh->apply_state[0];
      m->render_state[1] = sh->apply_state[1];
      shader_textures(b, m, sa, sh, custom, ca);
    }
    *slot = b->material_count++;
    return *slot;
  }
  return UINT32_MAX;
}

/* the mesh of a visual (shared), UINT32_MAX when it has no indexed triangles */
static uint32_t mesh_of(builder *b, tmuf_gbx_node *vn) {
  int found;
  uint32_t *slot = map_slot(&b->mesh_map, vn, &found);
  if (found)
    return *slot;
  const tmuf_plug_visual *pv = vn->data;
  if (!pv->vertices || !pv->indices || pv->index_count < 3) {
    *slot = UINT32_MAX;
    return UINT32_MAX;
  }
  tmuf_visual_mesh *m = &b->meshes[b->mesh_count];
  memset(m, 0, sizeof *m);
  m->vertex_count = pv->vertex_count;
  m->vertex_stride = pv->vertex_stride;
  m->vertices = pv->vertices;
  m->flags = ((pv->flags & 0x20u) ? TMUF_VISUAL_NORMAL : 0u) | ((pv->flags & 0x40u) ? TMUF_VISUAL_COLOR : 0u);
  m->uv_set_count = pv->texcoord_count;
  for (uint32_t i = 0; i < pv->texcoord_count && i < TMUF_VISUAL_MAX_UV_SETS; i++) {
    m->uv_sets[i] = pv->texcoords[i];
    m->uv_dims[i] = pv->texcoord_dim[i];
  }
  m->index_count = pv->index_count - pv->index_count % 3u;
  m->indices = pv->indices;
  memcpy(m->bounds, pv->bbox, sizeof m->bounds);
  *slot = b->mesh_count++;
  return *slot;
}

int tmuf_visuals_build(tmuf_visuals_data *out, tmuf_scene *scene, tmuf_arena *arena) {
  memset(out, 0, sizeof *out);
  const uint32_t n = scene->visual_count;
  builder b = {scene, arena, NULL, NULL, 0, 0, {0}, {0}, 0};
  b.meshes = malloc(sizeof *b.meshes * (n ? n : 1));
  b.materials = malloc(sizeof *b.materials * (n ? 3u * n : 1));
  tmuf_visual_instance *instances = malloc(sizeof *instances * (n ? n : 1));
  if (!b.meshes || !b.materials || !instances || !map_init(&b.mesh_map, n) || !map_init(&b.material_map, 3u * n)) {
    free(b.meshes), free(b.materials), free(instances);
    map_free(&b.mesh_map), map_free(&b.material_map);
    return 0;
  }
  uint32_t count = 0;
  for (uint32_t i = 0; i < n && !b.oom; i++) {
    const tmuf_scene_visual *v = &scene->visuals[i];
    tmuf_asset *va;
    tmuf_gbx_node *vn = tmuf_assets_follow(&scene->assets, v->owner, v->visual, &va);
    if (node_class(vn) != CLS_VISUAL || !vn->data)
      continue;
    const uint32_t mesh = mesh_of(&b, vn);
    if (mesh == UINT32_MAX)
      continue;
    tmuf_visual_instance *in = &instances[count++];
    in->mesh = mesh;
    in->material = material_of(&b, v, va, vn->data);
    for (int r = 0; r < 3; r++)
      for (int c = 0; c < 3; c++)
        in->location.r.m[r][c] = v->iso.m[r][c];
    in->location.t = (tmuf_vec3){v->iso.t[0], v->iso.t[1], v->iso.t[2]};
    in->block = v->tag;
    in->lod_near = v->lod_near;
    in->lod_far = v->lod_far;
  }
  map_free(&b.mesh_map);
  map_free(&b.material_map);
  if (b.oom) {
    free(b.meshes), free(b.materials), free(instances);
    return 0;
  }
  out->meshes = b.meshes;
  out->materials = b.materials;
  out->instances = instances;
  out->view.mesh_count = b.mesh_count;
  out->view.material_count = b.material_count;
  out->view.instance_count = count;
  out->view.meshes = b.meshes;
  out->view.materials = b.materials;
  out->view.instances = instances;
  return 1;
}

void tmuf_visuals_free(tmuf_visuals_data *v) {
  free(v->meshes);
  free(v->materials);
  free(v->instances);
  memset(v, 0, sizeof *v);
}
