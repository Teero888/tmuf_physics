#include "common/scene.h"
#include "common/scene_ctn.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/pack_classes.h"

/* ---- GmIso4 math, in the game's operation order ---- */

static float dot3(const float a[3], const float b[3]) {
  float xy = a[0] * b[0] + a[1] * b[1];
  return xy + a[2] * b[2];
}

void tmuf_iso_identity(tmuf_iso *iso) {
  memset(iso, 0, sizeof *iso);
  iso->m[0][0] = iso->m[1][1] = iso->m[2][2] = 1.0f;
}

void tmuf_iso_from_archive(tmuf_iso *iso, const float v[12]) {
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
      iso->m[r][c] = v[r * 3 + c];
  iso->t[0] = v[9];
  iso->t[1] = v[10];
  iso->t[2] = v[11];
}

void tmuf_iso_point(const tmuf_iso *iso, const float p[3], float out[3]) {
  float r[3];
  for (int i = 0; i < 3; i++)
    r[i] = dot3(iso->m[i], p) + iso->t[i];
  memcpy(out, r, sizeof r);
}

/* GmMath::Compose(a.rotation, b.rotation): each basis (column) of a mapped
   by b; translation = b applied to a's translation. */
void tmuf_iso_mult(tmuf_iso *out, const tmuf_iso *a, const tmuf_iso *b) {
  tmuf_iso r;
  for (int c = 0; c < 3; c++) {
    float col[3] = {a->m[0][c], a->m[1][c], a->m[2][c]};
    for (int i = 0; i < 3; i++)
      r.m[i][c] = dot3(b->m[i], col);
  }
  tmuf_iso_point(b, a->t, r.t);
  *out = r;
}

/* GmMat3::SetRotateQuarterY. */
static void rotate_quarter_y(tmuf_iso *iso, unsigned quarter) {
  static const float COS[4] = {1.0f, 0.0f, -1.0f, 0.0f};
  float c = COS[quarter & 3], s = COS[(quarter + 3) & 3];
  memset(iso->m, 0, sizeof iso->m);
  /* rows: X = (c, 0, -s), Y = (0, 1, 0), Z = (s, 0, c) */
  iso->m[0][0] = c;
  iso->m[0][2] = -s;
  iso->m[1][1] = 1.0f;
  iso->m[2][0] = s;
  iso->m[2][2] = c;
}

static int debug_enabled(void) {
  static int v = -1;
  if (v < 0)
    v = getenv("TMUF_SCENE_DEBUG") != NULL;
  return v;
}

/* ---- output ---- */

static void add_triangle(tmuf_scene *s, const float a[3], const float b[3], const float c[3], uint16_t material) {
  if (s->triangle_count == s->triangle_cap) {
    uint32_t cap = s->triangle_cap ? s->triangle_cap * 2 : 4096;
    tmuf_static_triangle *t = realloc(s->triangles, sizeof *t * cap);
    if (!t)
      return;
    s->triangles = t;
    s->triangle_cap = cap;
  }
  tmuf_static_triangle *t = &s->triangles[s->triangle_count++];
  memcpy(t->v[0], a, 12);
  memcpy(t->v[1], b, 12);
  memcpy(t->v[2], c, 12);
  t->material = material;
  t->block = s->current_block;
}

/* ---- solids and trees ---- */

static void emit_surface(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *surface_node, const tmuf_iso *world) {
  tmuf_asset *sa;
  tmuf_gbx_node *sn = tmuf_assets_follow(&s->assets, owner, surface_node, &sa);
  if (debug_enabled() && (!sn || !sn->data || sn->class_id != 0x0900c000u))
    fprintf(stderr, "      surface %p class %08x data %p skipped\n", (void *)sn, sn ? sn->class_id : 0, sn ? sn->data : NULL);
  if (!sn || !sn->data || sn->class_id != 0x0900c000u)
    return;
  const tmuf_plug_surface *surf = sn->data;
  tmuf_asset *ga;
  tmuf_gbx_node *gn = tmuf_assets_follow(&s->assets, sa, surf->geom, &ga);
  if (debug_enabled())
    fprintf(stderr, "      geom %p class %08x type %u tris %u\n", (void *)gn, gn ? gn->class_id : 0,
            gn && gn->data ? ((tmuf_plug_surface_geom *)gn->data)->type : 99,
            gn && gn->data ? ((tmuf_plug_surface_geom *)gn->data)->triangle_count : 0);
  if (!gn || !gn->data || gn->class_id != 0x0900f000u)
    return;
  const tmuf_plug_surface_geom *geom = gn->data;
  if (geom->type != TMUF_SURF_MESH)
    return;
  for (uint32_t i = 0; i < geom->triangle_count; i++) {
    const uint8_t *rec = geom->triangles + (size_t)i * 32;
    uint32_t idx[3];
    uint16_t mat;
    memcpy(idx, rec + 16, 12);
    memcpy(&mat, rec + 28, 2);
    float w[3][3];
    int ok = 1;
    for (int k = 0; k < 3; k++) {
      if (idx[k] >= geom->vertex_count) {
        ok = 0;
        break;
      }
      tmuf_iso_point(world, geom->vertices + (size_t)idx[k] * 3, w[k]);
    }
    if (ok)
      add_triangle(s, w[0], w[1], w[2], mat);
  }
}

static void emit_tree(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *tree_node, const tmuf_iso *parent, int depth) {
  if (depth > 64)
    return;
  tmuf_asset *ta;
  tmuf_gbx_node *tn = tmuf_assets_follow(&s->assets, owner, tree_node, &ta);
  if (debug_enabled())
    fprintf(stderr, "    %*stree -> %p class %08x cls %s data %p\n", depth * 2, "", (void *)tn, tn ? tn->class_id : 0,
            tn && tn->cls ? tn->cls->name : "-", tn ? tn->data : NULL);
  if (!tn || !tn->data)
    return;
  uint32_t cls = tn->cls ? tn->cls->id : 0;
  if (cls != 0x0904f000u && cls != 0x09015000u && cls != 0x09062000u)
    return; /* not a CPlugTree (generators, ...) */
  const tmuf_plug_tree *t = tn->data;
  tmuf_iso world = *parent;
  if (t->has_iso) {
    tmuf_iso local;
    tmuf_iso_from_archive(&local, t->iso);
    tmuf_iso_mult(&world, &local, parent);
  }
  if (t->surface)
    emit_surface(s, ta, t->surface, &world);
  for (uint32_t i = 0; i < t->child_count; i++)
    emit_tree(s, ta, t->children[i], &world, depth + 1);
}

static void add_corpus(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *tree, const tmuf_iso *iso) {
  if (s->corpus_count == s->corpus_cap) {
    uint32_t cap = s->corpus_cap ? s->corpus_cap * 2 : 1024;
    tmuf_scene_corpus *c = realloc(s->corpora, sizeof *c * cap);
    if (!c)
      return;
    s->corpora = c;
    s->corpus_cap = cap;
  }
  tmuf_scene_corpus *c = &s->corpora[s->corpus_count++];
  c->owner = owner;
  c->tree = tree;
  c->iso = *iso;
  c->tag = s->current_block;
  c->trigger = s->current_trigger;
  c->item_flags = s->current_item_flags;
  /* Helper trees hang below a new CHALLENGEHELPERTREE tree without the
     collision flag: never collided. Other mobils keep their item group. */
  c->collision_group = s->helper_depth ? 0
                        : (s->force_static || !c->item_flags) ? 4
                                                               : (uint8_t)((c->item_flags >> 13) & 15u);
}

static void emit_solid(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *solid_node, const tmuf_iso *world, int depth) {
  tmuf_asset *sa;
  tmuf_gbx_node *sn = tmuf_assets_follow(&s->assets, owner, solid_node, &sa);
  if (debug_enabled())
    fprintf(stderr, "    solid %s ext %d -> %p class %08x data %p (%s)\n", solid_node->file ? solid_node->file : "", solid_node->external, (void *)sn,
            sn ? sn->class_id : 0, sn ? sn->data : NULL, sa ? sa->path : "");
  if (!sn || !sn->data || sn->class_id != 0x09005000u)
    return;
  const tmuf_plug_solid *solid = sn->data;
  if (solid->use_model) {
    if (depth < 8)
      emit_solid(s, sa, solid->model, world, depth + 1);
    return;
  }
  if (solid->tree) {
    add_corpus(s, sa, solid->tree, world);
    emit_tree(s, sa, solid->tree, world, 0);
  }
}

static void emit_mobil(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *mobil_node, const tmuf_iso *world, int depth) {
  if (depth > 16)
    return;
  tmuf_asset *ma;
  tmuf_gbx_node *mn = tmuf_assets_follow(&s->assets, owner, mobil_node, &ma);
  if (debug_enabled())
    fprintf(stderr, "  %*smobil %p class %08x cls %s data %p item %d flags %08x\n", depth * 2, "", (void *)mn,
            mn ? mn->class_id : 0, mn && mn->cls ? mn->cls->name : "-", mn ? mn->data : NULL,
            mn && mn->data && mn->cls && mn->cls->id == 0x0a005000u ? ((tmuf_scene_object *)mn->data)->has_item : -1,
            mn && mn->data && mn->cls && mn->cls->id == 0x0a005000u ? ((tmuf_scene_object *)mn->data)->item.physics_flags : 0);
  if (!mn || !mn->data)
    return;
  if (!mn->cls || mn->cls->id != 0x0a005000u)
    return;
  const tmuf_scene_object *m = mn->data;
  /* CGameCtnBlock::SetMobilAndHelper: the linked trigger mobils */
  uint8_t saved_trigger = s->current_trigger;
  uint32_t saved_flags = s->current_item_flags;
  if (m->name && (strcmp(m->name, "TriggerCheckpoint") == 0 || strcmp(m->name, "TriggerFinishLine") == 0))
    s->current_trigger = 1;
  s->current_item_flags = m->has_item ? m->item.physics_flags : 0;
  if (m->has_item && m->item.solid)
    emit_solid(s, ma, m->item.solid, world, 0);
  for (uint32_t i = 0; i < m->children.count; i++) {
    tmuf_asset *la;
    tmuf_gbx_node *ln = tmuf_assets_follow(&s->assets, ma, m->children.nodes[i], &la);
    if (!ln || !ln->data || !ln->cls || ln->cls->id != 0x0a014000u)
      continue;
    const tmuf_object_link *link = ln->data;
    tmuf_iso local, linked;
    tmuf_iso_from_archive(&local, link->iso);
    tmuf_iso_mult(&linked, &local, world);
    emit_mobil(s, la, link->object, &linked, depth + 1);
  }
  s->current_trigger = saved_trigger;
  s->current_item_flags = saved_flags;
}

/* ---- blocks ---- */

/* Identifier of a collector file (header chunk 0x0301a003: version, then the
   ident: name, collection, author). The game indexes block infos by it. */
static const char *collector_name(tmuf_scene *s, tmuf_pack_ref ref) {
  const tmuf_pack *pack = &s->assets.set->packs[ref.pack];
  tmuf_pack_stream ps;
  if (!tmuf_pack_stream_open(&ps, pack, ref.file))
    return NULL;
  tmuf_gbx g;
  tmuf_gbx_init(&g, &ps.base, &s->assets.arena, NULL, 0);
  const char *name = NULL;
  if (tmuf_gbx_read_header(&g)) {
    for (uint32_t i = 0; i < g.header_chunk_count; i++) {
      if (g.header_chunks[i].id != 0x0301a003u)
        continue;
      tmuf_mem_source ms;
      tmuf_mem_source_init(&ms, g.header_chunks[i].data, g.header_chunks[i].size);
      tmuf_gbx h;
      tmuf_gbx_init(&h, &ms.base, &s->assets.arena, NULL, 0);
      const char *id = tmuf_gbx_id(&h, NULL);
      if (!h.error && id && *id)
        name = id;
      break;
    }
  }
  tmuf_pack_stream_close(&ps);
  return name;
}

static int ieq(const char *a, const char *b) {
  for (; *a && *b; a++, b++) {
    char x = *a >= 'A' && *a <= 'Z' ? (char)(*a + 32) : *a;
    char y = *b >= 'A' && *b <= 'Z' ? (char)(*b + 32) : *b;
    if (x != y)
      return 0;
  }
  return *a == *b;
}

/* Appends every collector under folder whose file name contains kind (e.g.
   ".TMED", ".TMDecoration.") to the catalog. */
/* CGameCtnBlockInfoFlat .. CGameCtnBlockInfoRectAsym (Rally stores the
   latter as .EDRectAsym, the others as .TMED*) */
static int is_block_info_class(uint32_t id) { return id >= 0x0304f000u && id <= 0x03056000u && !(id & 0xfffu); }

static void build_catalog(tmuf_scene *s, const char *folder, const char *kind, uint8_t tag) {
  const tmuf_packset *set = s->assets.set;
  char path[512];
  size_t flen = strlen(folder);
  for (int p = 0; p < set->pack_count; p++)
    for (uint32_t f = 0; f < set->packs[p].file_count; f++) {
      if (!tmuf_pack_file_path(&set->packs[p], f, path, sizeof path) || strncmp(path, folder, flen) != 0)
        continue;
      if (kind ? !strstr(path, kind) : !is_block_info_class(set->packs[p].files[f].class_id))
        continue;
      const char *name = collector_name(s, (tmuf_pack_ref){p, f});
      if (!name)
        continue;
      if (s->catalog_count == s->catalog_cap) {
        uint32_t cap = s->catalog_cap ? s->catalog_cap * 2 : 256;
        tmuf_scene_catalog_entry *c = realloc(s->catalog, sizeof *c * cap);
        if (!c)
          return;
        s->catalog = c;
        s->catalog_cap = cap;
      }
      s->catalog[s->catalog_count++] = (tmuf_scene_catalog_entry){name, {p, f}, tag};
    }
}

static tmuf_pack_ref find_collector(const tmuf_scene *s, const char *name, uint8_t tag) {
  for (uint32_t i = 0; i < s->catalog_count; i++)
    if (s->catalog[i].tag == tag && ieq(s->catalog[i].name, name))
      return s->catalog[i].ref;
  return (tmuf_pack_ref){-1, 0};
}

enum { CATALOG_BLOCK_INFO, CATALOG_DECORATION };

/* Collections live under Collections\ (.TMCollection or .TMElementColl);
   matched by the name stored in their body. */
static tmuf_asset *find_collection(tmuf_scene *s, const char *name) {
  const tmuf_packset *set = s->assets.set;
  char path[512];
  for (int p = 0; p < set->pack_count; p++)
    for (uint32_t f = 0; f < set->packs[p].file_count; f++) {
      if (!tmuf_pack_file_path(&set->packs[p], f, path, sizeof path) || strncmp(path, "Collections\\", 12) != 0)
        continue;
      tmuf_asset *a = tmuf_assets_load(&s->assets, (tmuf_pack_ref){p, f});
      if (a && a->class_id == 0x03033000u && a->root && ((tmuf_collection *)a->root)->name &&
          ieq(((tmuf_collection *)a->root)->name, name))
        return a;
    }
  return NULL;
}

/* The game's rand() (MSVC LCG) as used by GmFunc::RandNat. */
uint32_t scene_rand_nat(tmuf_scene *s, uint32_t lo, uint32_t hi) {
  s->rand_state = s->rand_state * 214013u + 2531011u;
  uint32_t r = (s->rand_state >> 16) & 0x7fffu;
  float unit = (float)r / 32768.0f;
  float scaled = unit * (float)(hi - lo + 1u);
  return (uint32_t)(scaled + (float)lo);
}

tmuf_asset *scene_block_info(tmuf_scene *s, const char *name) {
  tmuf_pack_ref r = find_collector(s, name, CATALOG_BLOCK_INFO);
  if (r.pack < 0)
    return NULL;
  tmuf_asset *a = tmuf_assets_load(&s->assets, r);
  return a && a->root ? a : NULL;
}

int scene_debug(void) { return debug_enabled(); }

/* GmMat3::SetRotateQuarterY(quarter) (rotate_quarter_y counts the other way) */
void tmuf_iso_rotate_quarter_y(tmuf_iso *iso, unsigned quarter) { rotate_quarter_y(iso, (4u - quarter) & 3u); }

/* ClipSideTransform */
static void clip_side(unsigned side, float sq, tmuf_iso *out) {
  static const unsigned QUARTER[4] = {0, 3, 2, 1};
  tmuf_iso_identity(out);
  tmuf_iso_rotate_quarter_y(out, QUARTER[side & 3]);
  out->t[0] = (side == 1 || side == 2) ? sq : 0.0f;
  out->t[1] = 0.0f;
  out->t[2] = (side == 2 || side == 3) ? sq : 0.0f;
}

/* AppendBlockPlacementModels for one installation */
static void emit_install(tmuf_scene *s, const ctn_install *in) {
  if (!in->active || in->suppressed)
    return;
  s->current_block = in->tag;
  s->force_static = 1;
  if (in->kind == CTN_INSTALL_CLIP) {
    for (unsigned side = 0; side < 4; side++) {
      if (!in->clip[side].node)
        continue;
      tmuf_iso local, world;
      clip_side(side, s->square_size, &local);
      tmuf_iso_mult(&world, &local, &in->iso);
      emit_mobil(s, in->clip[side].asset, in->clip[side].node, &world, 0);
    }
  } else if (in->kind == CTN_INSTALL_PYLON) {
    s->pylon_raise = in->pylon_raise;
    emit_mobil(s, in->main.asset, in->main.node, &in->iso, 0);
    s->pylon_raise = 0;
  } else {
    if (in->main.node)
      emit_mobil(s, in->main.asset, in->main.node, &in->iso, 0);
    s->force_static = 0;
    s->helper_depth++;
    for (int k = 0; k < 2; k++)
      if (in->helper[k].node)
        emit_mobil(s, in->helper[k].asset, in->helper[k].node, &in->iso, 0);
    s->helper_depth--;
  }
  s->force_static = 0;
  s->blocks_placed++;
}


int tmuf_scene_build(tmuf_scene *s, const tmuf_packset *set, const tmuf_challenge *map) {
  memset(s, 0, sizeof *s);
  s->rand_state = 1;
  tmuf_assets_init(&s->assets, set);
  tmuf_asset *ca = find_collection(s, map->decoration[1]);
  if (!ca) {
    snprintf(s->error, sizeof s->error, "no collection %s", map->decoration[1]);
    return 0;
  }
  const tmuf_collection *coll = ca->root;
  s->collection = coll->name;
  s->square_size = coll->square_size;
  s->square_height = coll->square_height;
  build_catalog(s, coll->folders[0], NULL, CATALOG_BLOCK_INFO);
  build_catalog(s, coll->folders[2], ".TMDecoration.", CATALOG_DECORATION);
  tmuf_asset *da = tmuf_assets_load(&s->assets, find_collector(s, map->decoration[0], CATALOG_DECORATION));
  if (!da || da->class_id != 0x03038000u) {
    snprintf(s->error, sizeof s->error, "no decoration %s", map->decoration[0]);
    return 0;
  }
  tmuf_asset *dsa;
  tmuf_gbx_node *dsn = tmuf_assets_follow(&s->assets, da, ((tmuf_decoration *)da->root)->refs[0], &dsa);
  if (!dsn || !dsn->data || dsn->class_id != 0x0303b000u) {
    snprintf(s->error, sizeof s->error, "no decoration size for %s", map->decoration[0]);
    return 0;
  }
  const tmuf_decoration_size *dsize = dsn->data;
  s->size[0] = dsize->size[0];
  s->size[1] = dsize->size[1];
  s->size[2] = dsize->size[2];
  s->base_height = dsize->base_height;
  if (debug_enabled())
    fprintf(stderr, "collection %s folders %s | %s | %s | %s; decoration %s %s %s\n", coll->name, coll->folders[0],
            coll->folders[1], coll->folders[2], coll->folders[3], map->decoration[0], map->decoration[1],
            map->decoration[2]);

  /* decoration scene (added to the zone before the map) */
  tmuf_asset *sa;
  tmuf_gbx_node *sn = tmuf_assets_follow(&s->assets, dsa, dsize->scene, &sa);
  if (sn && sn->data && sn->class_id == 0x0a003000u) {
    const tmuf_scene3d *sc = sn->data;
    for (uint32_t i = 0; i < sc->mobil_count && i < sc->loc_count; i++) {
      if (!sc->mobils[i] || !sc->mobils[i]->model)
        continue;
      tmuf_iso loc;
      tmuf_iso_from_archive(&loc, sc->locs[i].iso);
      s->current_block = 0xc0000000u | i;
      emit_mobil(s, sa, sc->mobils[i]->model, &loc, 0);
    }
  } else if (debug_enabled()) {
    fprintf(stderr, "no decoration scene\n");
  }

  /* the map's blocks, clips and pylons, in the game's add order */
  ctn_result cr;
  if (!ctn_build(s, map, ca, &cr)) {
    snprintf(s->error, sizeof s->error, "challenge construction failed");
    return 0;
  }
  s->blocks_missing = cr.blocks_missing;
  /* ReplaySceneBlockPlacements::FirstSurvivingStartLineSpawn:
     CGameCtnBlock::SpawnLocation of the first start block */
  for (uint32_t i = 0; i < cr.count && !s->has_start; i++) {
    const ctn_install *in = &cr.items[i];
    if (in->kind != CTN_INSTALL_BLOCK || !in->start_line)
      continue;
    tmuf_iso local;
    tmuf_iso_identity(&local);
    if (in->info->has_spawn)
      tmuf_iso_from_archive(&local, in->info->spawn[in->ground ? 0 : 1]);
    tmuf_iso_mult(&s->start, &local, &in->iso);
    s->has_start = 1;
  }
  for (uint32_t i = 0; i < cr.count; i++)
    emit_install(s, &cr.items[i]);
  ctn_result_free(&cr);
  return 1;
}

void tmuf_scene_free(tmuf_scene *s) {
  free(s->triangles);
  free(s->catalog);
  free(s->corpora);
  tmuf_assets_free(&s->assets);
  memset(s, 0, sizeof *s);
}
