#include "common/scene.h"

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
  if (solid->tree)
    emit_tree(s, sa, solid->tree, world, 0);
}

static void emit_mobil(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *mobil_node, const tmuf_iso *world, int depth) {
  if (depth > 16)
    return;
  tmuf_asset *ma;
  tmuf_gbx_node *mn = tmuf_assets_follow(&s->assets, owner, mobil_node, &ma);
  if (debug_enabled())
    fprintf(stderr, "  %*smobil %p class %08x cls %s data %p item %d\n", depth * 2, "", (void *)mn, mn ? mn->class_id : 0,
            mn && mn->cls ? mn->cls->name : "-", mn ? mn->data : NULL,
            mn && mn->data && mn->cls && mn->cls->id == 0x0a005000u ? ((tmuf_scene_object *)mn->data)->has_item : -1);
  if (!mn || !mn->data)
    return;
  if (!mn->cls || mn->cls->id != 0x0a005000u)
    return;
  const tmuf_scene_object *m = mn->data;
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
static void build_catalog(tmuf_scene *s, const char *folder, const char *kind, uint8_t tag) {
  const tmuf_packset *set = s->assets.set;
  char path[512];
  size_t flen = strlen(folder);
  for (int p = 0; p < set->pack_count; p++)
    for (uint32_t f = 0; f < set->packs[p].file_count; f++) {
      if (!tmuf_pack_file_path(&set->packs[p], f, path, sizeof path) || strncmp(path, folder, flen) != 0 ||
          !strstr(path, kind))
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

static void block_size(tmuf_scene *s, tmuf_asset *bi_asset, const tmuf_block_info *bi, int ground, uint32_t size[3]) {
  size[0] = size[1] = size[2] = 1;
  const tmuf_node_list *units = &bi->units[ground ? 0 : 1];
  for (uint32_t i = 0; i < units->count; i++) {
    tmuf_asset *ua;
    tmuf_gbx_node *un = tmuf_assets_follow(&s->assets, bi_asset, units->nodes[i], &ua);
    if (!un || !un->data || un->class_id != 0x03036000u)
      continue;
    const tmuf_block_unit *u = un->data;
    for (int k = 0; k < 3; k++)
      if (u->offset[k] + 1 > size[k])
        size[k] = u->offset[k] + 1;
  }
}

/* CGameCtnBlock::GetMobilLoc. */
static void block_location(const tmuf_scene *s, const tmuf_challenge_block *b, const uint32_t size[3], tmuf_iso *iso) {
  float sq = s->square_size, h = s->square_height;
  tmuf_iso_identity(iso);
  iso->t[0] = (float)b->x * sq;
  iso->t[1] = (float)b->y * h;
  iso->t[2] = (float)b->z * sq;
  unsigned quarter = 0;
  switch (b->dir & 3) {
  case 0: /* north */
    break;
  case 1: /* east */
    iso->t[0] = (float)size[2] * sq + iso->t[0];
    quarter = 1;
    break;
  case 2: /* south */
    iso->t[0] = (float)size[0] * sq + iso->t[0];
    iso->t[2] = (float)size[2] * sq + iso->t[2];
    quarter = 2;
    break;
  case 3: /* west */
    iso->t[2] = (float)size[0] * sq + iso->t[2];
    quarter = 3;
    break;
  }
  rotate_quarter_y(iso, quarter);
}

/* The game's rand() (MSVC LCG) as used by GmFunc::RandNat. */
static uint32_t rand_nat(tmuf_scene *s, uint32_t lo, uint32_t hi) {
  s->rand_state = s->rand_state * 214013u + 2531011u;
  uint32_t r = (s->rand_state >> 16) & 0x7fffu;
  float unit = (float)r / 32768.0f;
  float scaled = unit * (float)(hi - lo + 1u);
  return (uint32_t)(scaled + (float)lo);
}

enum { BT_FLAT, BT_FRONTIER, BT_CLASSIC, BT_ROAD, BT_CLIP, BT_SLOPE, BT_PYLON, BT_RECT_ASYM, BT_OTHER };

static int block_type(uint32_t class_id) {
  switch (class_id) {
  case 0x0304f000u: return BT_FLAT;
  case 0x03050000u: return BT_FRONTIER;
  case 0x03051000u: return BT_CLASSIC;
  case 0x03052000u: return BT_ROAD;
  case 0x03053000u: return BT_CLIP;
  case 0x03054000u: return BT_SLOPE;
  case 0x03055000u: return BT_PYLON;
  case 0x03056000u: return BT_RECT_ASYM;
  default: return BT_OTHER;
  }
}

typedef struct placed_block {
  tmuf_challenge_block b; /* coord, dir, flags */
  tmuf_asset *asset;
  const tmuf_block_info *info;
  int type;
  uint32_t map_index; /* ~0 for automatic blocks */
  int removed;
} placed_block;

/* Unit offsets of a block rotated into map axes (CGameCtnBlockInfo::
   GetRotatedOffset). Returns the number of units written. */
static uint32_t rotated_units(tmuf_scene *s, const placed_block *pb, int ground, uint32_t (*out)[3], uint32_t cap) {
  uint32_t size[3];
  block_size(s, pb->asset, pb->info, ground, size);
  const tmuf_node_list *units = &pb->info->units[ground ? 0 : 1];
  uint32_t n = 0;
  for (uint32_t i = 0; i < units->count && n < cap; i++) {
    tmuf_asset *ua;
    tmuf_gbx_node *un = tmuf_assets_follow(&s->assets, pb->asset, units->nodes[i], &ua);
    if (!un || !un->data || un->class_id != 0x03036000u)
      continue;
    const uint32_t *o = ((const tmuf_block_unit *)un->data)->offset;
    uint32_t r[3];
    switch (pb->b.dir & 3) {
    case 0: r[0] = o[0]; r[2] = o[2]; break;
    case 1: r[0] = size[2] - 1 - o[2]; r[2] = o[0]; break;
    case 2: r[0] = size[0] - 1 - o[0]; r[2] = size[2] - 1 - o[2]; break;
    default: r[0] = o[2]; r[2] = size[0] - 1 - o[0]; break;
    }
    r[1] = o[1];
    out[n][0] = pb->b.x + r[0];
    out[n][1] = pb->b.y + r[1];
    out[n][2] = pb->b.z + r[2];
    n++;
  }
  return n;
}

static const tmuf_node_list *mobil_list(const tmuf_block_info *bi, int ground, uint32_t variant) {
  int f = ground ? 0 : 1;
  if (variant >= bi->variant_count[f])
    return NULL;
  const tmuf_node_list *l = &bi->variants[f][variant];
  return l->count ? l : NULL;
}

/* CGameCtnBlock::CreateBlockMobil + CGameCtnBlockInfo::BuildBlockMobil. */
static void place_block(tmuf_scene *s, placed_block *pb, uint32_t tag) {
  uint32_t flags = pb->b.flags;
  int ground = (flags & 0x1000u) != 0;
  uint32_t variant = flags & 0x3fu;
  uint32_t selection = (flags >> 6) & 0x3fu;
  if (selection == 0x3fu) {
    const tmuf_node_list *l = mobil_list(pb->info, ground, variant);
    selection = l && l->count > 1 ? rand_nat(s, 0, l->count - 1) : 0;
  }
  const tmuf_node_list *mobils = mobil_list(pb->info, ground, variant);
  if (!mobils) {
    ground = !ground;
    mobils = mobil_list(pb->info, ground, variant);
  }
  if (!mobils) {
    s->blocks_missing++;
    return;
  }
  if (selection >= mobils->count)
    selection = 0;
  uint32_t size[3];
  block_size(s, pb->asset, pb->info, ground, size);
  tmuf_iso loc;
  block_location(s, &pb->b, size, &loc);
  s->current_block = tag;
  if (debug_enabled())
    fprintf(stderr, "place %s at %u %u %u dir %u ground %d variant %u mobil %u/%u\n", pb->b.name ? pb->b.name : "(auto)",
            pb->b.x, pb->b.y, pb->b.z, pb->b.dir, ground, variant, selection, mobils->count);
  emit_mobil(s, pb->asset, mobils->nodes[selection], &loc, 0);
  /* CGameCtnBlockInfo::BuildBlockHelperMobil: family helper (by the
     requested family), then the common helper */
  int helper_ground = (flags & 0x1000u) != 0;
  const tmuf_gbx_node *fh = pb->info->helpers[helper_ground ? 0 : 1];
  if (fh)
    emit_mobil(s, pb->asset, (tmuf_gbx_node *)fh, &loc, 0);
  if (pb->info->helpers[2])
    emit_mobil(s, pb->asset, pb->info->helpers[2], &loc, 0);
  s->blocks_placed++;
  const char *probe = getenv("TMUF_SCENE_PROBE");
  if (probe && pb->b.name && strcmp(pb->b.name, probe) == 0) {
    for (int f = 0; f < 2; f++)
      for (uint32_t v = 0; v < pb->info->variant_count[f]; v++)
        for (uint32_t m = 0; m < pb->info->variants[f][v].count; m++) {
          uint32_t sz2[3];
          block_size(s, pb->asset, pb->info, f == 0, sz2);
          block_location(s, &pb->b, sz2, &loc);
          s->current_block = 0x40000000u | (uint32_t)f << 16 | v << 8 | m;
          emit_mobil(s, pb->asset, pb->info->variants[f][v].nodes[m], &loc, 0);
        }
  }
}

#define MAX_UNITS 256

int tmuf_scene_build(tmuf_scene *s, const tmuf_packset *set, const tmuf_challenge *map) {
  memset(s, 0, sizeof *s);
  s->rand_state = 1;
  tmuf_assets_init(&s->assets, set);
  const char *env = map->decoration[1];
  char path[512];
  snprintf(path, sizeof path, "Collections\\%s.TMCollection.Gbx", env);
  tmuf_asset *ca = tmuf_assets_load_path(&s->assets, path);
  if (!ca || ca->class_id != 0x03033000u) {
    snprintf(s->error, sizeof s->error, "no collection %s", path);
    return 0;
  }
  const tmuf_collection *coll = ca->root;
  s->collection = coll->name;
  s->square_size = coll->square_size;
  s->square_height = coll->square_height;
  build_catalog(s, coll->folders[0], ".TMED", CATALOG_BLOCK_INFO);
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

  /* default zone: flat, clip and pylon block infos */
  tmuf_asset *za;
  tmuf_gbx_node *zn = tmuf_assets_follow(&s->assets, ca, coll->default_zone, &za);
  const tmuf_zone *zone = zn && zn->data && zn->class_id == 0x0305d000u ? zn->data : NULL;
  tmuf_asset *base_asset = NULL;
  if (zone) {
    tmuf_gbx_node *fn = tmuf_assets_follow(&s->assets, za, zone->block_infos[0], &base_asset);
    if (!fn || !fn->data || !base_asset || fn != &base_asset->gbx.nodes[0])
      base_asset = NULL;
  }

  uint32_t sx = s->size[0], sy = s->size[1], sz = s->size[2];
  size_t columns = (size_t)sx * sz;
  uint8_t *zone_height = malloc(columns ? columns : 1);
  uint8_t *has_terrain = calloc(columns ? columns : 1, 1);
  int32_t *ground_block = malloc(sizeof(int32_t) * (columns ? columns : 1));
  placed_block *blocks = calloc(map->block_count + columns + 1, sizeof *blocks);
  uint32_t (*units)[3] = malloc(sizeof *units * MAX_UNITS);
  if (!zone_height || !has_terrain || !ground_block || !blocks || !units) {
    free(zone_height), free(has_terrain), free(ground_block), free(blocks), free(units);
    snprintf(s->error, sizeof s->error, "out of memory");
    return 0;
  }
  for (size_t c = 0; c < columns; c++) {
    zone_height[c] = (uint8_t)s->base_height;
    ground_block[c] = -1;
  }

  uint32_t count = 0;
  for (uint32_t i = 0; i < map->block_count; i++) {
    const tmuf_challenge_block *b = &map->blocks[i];
    tmuf_asset *ba = tmuf_assets_load(&s->assets, find_collector(s, b->name, CATALOG_BLOCK_INFO));
    if (debug_enabled())
      fprintf(stderr, "block %s flags %08x -> %s\n", b->name, b->flags, ba ? ba->path : "(none)");
    if (!ba || !ba->root) {
      s->blocks_missing++;
      continue;
    }
    placed_block *pb = &blocks[count++];
    pb->b = *b;
    pb->asset = ba;
    pb->info = ba->root;
    pb->type = block_type(ba->class_id);
    pb->map_index = i;
  }

  /* 1. terrain blocks: zone heights, then their mobils */
  for (uint32_t i = 0; i < count; i++) {
    placed_block *pb = &blocks[i];
    if (pb->type > BT_FRONTIER || pb->b.x >= sx || pb->b.z >= sz)
      continue;
    size_t c = (size_t)pb->b.x * sz + pb->b.z;
    zone_height[c] = pb->b.y;
    has_terrain[c] = 1;
  }
  for (uint32_t i = 0; i < count; i++) {
    placed_block *pb = &blocks[i];
    if (pb->type > BT_FRONTIER)
      continue;
    if (pb->b.x < sx && pb->b.z < sz)
      ground_block[(size_t)pb->b.x * sz + pb->b.z] = (int32_t)i;
    place_block(s, pb, pb->map_index);
  }

  /* 2. default zone fill of the remaining columns (x outer, z inner) */
  uint32_t auto_first = count;
  if (base_asset) {
    for (uint32_t x = 0; x < sx; x++)
      for (uint32_t z = 0; z < sz; z++) {
        size_t c = (size_t)x * sz + z;
        if (has_terrain[c])
          continue;
        placed_block *pb = &blocks[count];
        memset(pb, 0, sizeof *pb);
        pb->b.x = (uint8_t)x;
        pb->b.y = (uint8_t)s->base_height;
        pb->b.z = (uint8_t)z;
        pb->b.flags = 0x1000u | 0xfc0u; /* ground, variant 0, automatic mobil */
        pb->asset = base_asset;
        pb->info = base_asset->root;
        pb->type = BT_FLAT;
        pb->map_index = ~0u;
        ground_block[c] = (int32_t)count;
        count++;
      }
  }

  /* 3. other blocks: their ground-level units remove the terrain below */
  for (uint32_t i = 0; i < auto_first; i++) {
    placed_block *pb = &blocks[i];
    if (pb->type <= BT_FRONTIER)
      continue;
    int ground = (pb->b.flags & 0x1000u) != 0;
    uint32_t n = rotated_units(s, pb, ground, units, MAX_UNITS);
    int inside = 1;
    for (uint32_t k = 0; k < n; k++)
      if (units[k][0] >= sx || units[k][1] >= sy || units[k][2] >= sz)
        inside = 0;
    if (!inside) {
      if (debug_enabled())
        fprintf(stderr, "removed %s at %u %u %u (outside)\n", pb->b.name, pb->b.x, pb->b.y, pb->b.z);
      pb->removed = 1;
      continue;
    }
    for (uint32_t k = 0; k < n; k++) {
      size_t c = (size_t)units[k][0] * sz + units[k][2];
      if (units[k][1] == (uint32_t)zone_height[c] + 1u && ground_block[c] >= 0)
        blocks[ground_block[c]].removed = 1;
    }
  }

  /* mobils in the game's add order: terrain (above), fill, others */
  for (uint32_t i = auto_first; i < count; i++)
    if (!blocks[i].removed)
      place_block(s, &blocks[i], 0x80000000u | i);
  for (uint32_t i = 0; i < auto_first; i++)
    if (blocks[i].type > BT_FRONTIER && !blocks[i].removed)
      place_block(s, &blocks[i], blocks[i].map_index);

  free(zone_height), free(has_terrain), free(ground_block), free(blocks), free(units);
  return 1;
}

void tmuf_scene_free(tmuf_scene *s) {
  free(s->triangles);
  free(s->catalog);
  tmuf_assets_free(&s->assets);
  memset(s, 0, sizeof *s);
}
