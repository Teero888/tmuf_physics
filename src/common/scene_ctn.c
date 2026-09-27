/* Challenge construction: United's map loading (BuildReplayChallenge, the
   challenge's field units, CGameCtnChallenge and its blocks, CGameCtnApp and
   the installation stream of the scene placements). */

#include "common/scene_ctn.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { BT_FLAT, BT_FRONTIER, BT_CLASSIC, BT_ROAD, BT_CLIP, BT_PYLON, BT_SLOPE, BT_RECT_ASYM, BT_OTHER };
enum { TER_UNDERGROUND, TER_GROUND, TER_RESERVED, TER_AIR, TER_OUTSIDE };
enum { DIR_N, DIR_W, DIR_S, DIR_E }; /* ECardinalDir */
enum { ORIGIN_AUTHORED, ORIGIN_AUTO_BASE, ORIGIN_CREATED };

#define ARR_PUSH(arr, count, cap, value)                                                                               \
  do {                                                                                                                 \
    if ((count) == (cap)) {                                                                                            \
      uint32_t ncap_ = (cap) ? (cap) * 2 : 16;                                                                         \
      void *np_ = realloc((arr), sizeof *(arr) * ncap_);                                                               \
      if (!np_)                                                                                                        \
        abort();                                                                                                       \
      (arr) = np_;                                                                                                     \
      (cap) = ncap_;                                                                                                   \
    }                                                                                                                  \
    (arr)[(count)++] = (value);                                                                                        \
  } while (0)

typedef struct ctn_info ctn_info;
typedef struct ctn_block ctn_block;
typedef struct ctn_bunit ctn_bunit;

typedef struct ctn_uinfo {
  uint32_t off[3], junction_mask, helper_mask;
  int underground;
  ctn_info *junction[4];
  const char *modifier, *surface;
} ctn_uinfo;

struct ctn_info {
  tmuf_asset *asset;
  const tmuf_block_info *bi;
  int type;
  uint32_t n[2];     /* [isGround] */
  ctn_uinfo *u[2];
  uint32_t size[2][3];
  ctn_info *next;
  /* pylon: generated middle mobils per height */
  uint32_t pylon_generated_count;
};

typedef struct ctn_zone {
  const char *id;
  int frontier, old;
  uint32_t height, depth;
  ctn_info *info, *clip, *pylon;
  const char *parent, *child;
} ctn_zone;

typedef struct ctn_field {
  int terrain;
  ctn_bunit *bunit;
} ctn_field;

typedef struct ctn_column {
  uint32_t count, cap;
  ctn_field **fields;
} ctn_column;

typedef struct ctn_cell {
  const char *zone_id;
  uint8_t height;
} ctn_cell;

struct ctn_bunit {
  ctn_block *block;
  ctn_uinfo *info;
  ctn_field *field;
  uint32_t off[3];
  uint32_t jmask, hmask;
  ctn_info *junction[4];
};

/* A mobil instance (CSceneMobil created by the challenge). */
typedef struct ctn_mobil {
  int kind; /* 0 block main, 1 helper, 2 clip composite, 3 pylon */
  ctn_source src, src2;
  uint32_t raise;
  int generated;
} ctn_mobil;

struct ctn_block {
  ctn_info *info;
  uint32_t coord[3];
  uint32_t dir;
  int ground; /* mobil family */
  uint32_t variant;
  int has_sel;
  uint32_t sel;
  int origin;
  uint32_t tag;
  ctn_bunit **units;
  uint32_t unit_count, unit_cap;
  const ctn_block *suppressed_by;
  float mobil_y;
  const char *modifier;
  int replacement_remap, skin_remap;
  ctn_mobil *main, *helper;
  ctn_source clip_src[4], clip_helper[4];
  int active;
};

typedef struct pylon_col {
  int has_span;
  uint32_t first, last;
  ctn_mobil *single, *triple[3];
} pylon_col;

typedef struct pylon_add {
  uint32_t coord[3];
  uint32_t index, height;
  ctn_mobil *single, *triple[3];
} pylon_add;

typedef struct suppression {
  ctn_block *target;
  const ctn_block *suppressor;
} suppression;

typedef struct ctn {
  tmuf_scene *s;
  uint32_t w, h, d, default_height;
  float sq, sqh;
  ctn_zone *zones;
  uint32_t zone_count;
  ctn_zone *default_zone;
  ctn_info *infos;
  ctn_cell *cells;
  ctn_column *columns;
  ctn_block **blocks;
  uint32_t block_count, block_cap;
  ctn_block **retired;
  uint32_t retired_count, retired_cap;
  ctn_block **adds;
  uint32_t add_head, add_count, add_cap;
  ctn_mobil **removes;
  uint32_t remove_head, remove_count, remove_cap;
  pylon_add *pylon_adds;
  uint32_t pylon_head, pylon_count, pylon_cap;
  suppression *supps;
  uint32_t supp_count, supp_cap;
  int has_pylon_data;
  pylon_col *pn, *ps, *pe, *pw;
  ctn_mobil **mobils;
  uint32_t mobil_count, mobil_cap;
  ctn_result *out;
  const tmuf_collection *coll;
  /* the installation stream keeps the mobil instances of each entry */
  ctn_mobil **inst_main, **inst_helper;
  uint32_t inst_cap;
} ctn;

static int id_eq(const char *a, const char *b) { return a && b && strcmp(a, b) == 0; }

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

/* ---- block infos ---- */

static ctn_info *info_for(ctn *c, tmuf_asset *a);

static ctn_info *info_from_node(ctn *c, tmuf_asset *owner, tmuf_gbx_node *n) {
  tmuf_asset *a;
  tmuf_gbx_node *t = tmuf_assets_follow(&c->s->assets, owner, n, &a);
  if (!t || !t->data || !a || t != &a->gbx.nodes[0])
    return NULL;
  return info_for(c, a);
}

static ctn_info *info_for(ctn *c, tmuf_asset *a) {
  if (!a || !a->root)
    return NULL;
  for (ctn_info *i = c->infos; i; i = i->next)
    if (i->asset == a)
      return i;
  ctn_info *ci = calloc(1, sizeof *ci);
  if (!ci)
    return NULL;
  ci->asset = a;
  ci->bi = a->root;
  ci->type = block_type(a->class_id);
  ci->next = c->infos;
  c->infos = ci;
  for (int g = 0; g < 2; g++) {
    const tmuf_node_list *l = &ci->bi->units[g ? 0 : 1]; /* file: ground, air */
    ci->u[g] = calloc(l->count ? l->count : 1, sizeof(ctn_uinfo));
    ci->size[g][0] = ci->size[g][1] = ci->size[g][2] = 1;
    for (uint32_t k = 0; k < l->count; k++) {
      tmuf_asset *ua;
      tmuf_gbx_node *un = tmuf_assets_follow(&c->s->assets, a, l->nodes[k], &ua);
      if (!un || !un->data || un->class_id != 0x03036000u)
        continue;
      const tmuf_block_unit *bu = un->data;
      ctn_uinfo *u = &ci->u[g][ci->n[g]++];
      memcpy(u->off, bu->offset, sizeof u->off);
      u->junction_mask = bu->junction_mask;
      u->helper_mask = bu->helper ? 0xffu : 0u;
      if (bu->has_helper_mask)
        u->helper_mask = bu->helper_mask;
      u->underground = bu->underground != 0;
      u->modifier = bu->terrain_modifier && bu->terrain_modifier[0] ? bu->terrain_modifier : NULL;
      u->surface = bu->surface;
      for (int k2 = 0; k2 < 3; k2++)
        if (u->off[k2] + 1 > ci->size[g][k2])
          ci->size[g][k2] = u->off[k2] + 1;
    }
  }
  /* junction clips resolved after insertion (they may refer back) */
  for (int g = 0; g < 2; g++) {
    const tmuf_node_list *l = &ci->bi->units[g ? 0 : 1];
    uint32_t m = 0;
    for (uint32_t k = 0; k < l->count; k++) {
      tmuf_asset *ua;
      tmuf_gbx_node *un = tmuf_assets_follow(&c->s->assets, a, l->nodes[k], &ua);
      if (!un || !un->data || un->class_id != 0x03036000u)
        continue;
      const tmuf_block_unit *bu = un->data;
      ctn_uinfo *u = &ci->u[g][m++];
      if (bu->sources.count == 4)
        for (int side = 0; side < 4; side++)
          if (bu->sources.nodes[side])
            u->junction[side] = info_from_node(c, ua, bu->sources.nodes[side]);
    }
  }
  return ci;
}

static const tmuf_node_list *info_variant(const ctn_info *ci, int ground, uint32_t variant) {
  int f = ground ? 0 : 1;
  if (variant >= ci->bi->variant_count[f])
    return NULL;
  return &ci->bi->variants[f][variant];
}

/* CGameCtnBlockInfo::GetMobil */
static ctn_source info_mobil(const ctn_info *ci, int ground, uint32_t variant, uint32_t index) {
  ctn_source none = {NULL, NULL};
  const tmuf_node_list *l = info_variant(ci, ground, variant);
  if (!l || l->count == 0)
    return none;
  ctn_source src = {ci->asset, l->nodes[index < l->count ? index : 0]};
  return src.node ? src : none;
}

/* CGameCtnBlockInfo::GetRotatedOffset */
static void rotated_offset(const ctn_info *ci, const ctn_uinfo *u, uint32_t dir, int ground, uint32_t out[3]) {
  uint32_t ox = u->off[0], oz = u->off[2];
  out[0] = ox;
  out[1] = ci->type <= BT_FRONTIER ? 0 : u->off[1];
  out[2] = oz;
  uint32_t dx = ci->size[ground][0], dz = ci->size[ground][2];
  switch (dir & 3) {
  case DIR_W:
    out[2] = ox;
    out[0] = dz - oz - 1u;
    break;
  case DIR_S:
    out[0] = dx - ox - 1u;
    out[2] = dz - oz - 1u;
    break;
  case DIR_E:
    out[0] = oz;
    out[2] = dx - ox - 1u;
    break;
  default:
    break;
  }
}

static int info_part_underground(const ctn_info *ci, int g) {
  for (uint32_t k = 0; k < ci->n[g]; k++)
    if (ci->u[g][k].underground)
      return 1;
  return 0;
}

/* ---- zones ---- */

static ctn_zone *zone_by_id(ctn *c, const char *id) {
  for (uint32_t i = 0; i < c->zone_count; i++)
    if (!c->zones[i].old && id_eq(c->zones[i].id, id))
      return &c->zones[i];
  return NULL;
}

static ctn_zone *zone_old_by_id(ctn *c, const char *id) {
  for (uint32_t i = 0; i < c->zone_count; i++)
    if (c->zones[i].old && id_eq(c->zones[i].id, id))
      return &c->zones[i];
  return NULL;
}

static ctn_zone *zone_flat(ctn *c, const char *id) {
  ctn_zone *z = zone_by_id(c, id);
  return z && !z->frontier ? z : NULL;
}

/* CGameCtnCollection::GetBasicZone */
static ctn_zone *zone_basic(ctn *c, const char *id) {
  ctn_zone *z = zone_by_id(c, id);
  if (z && z->frontier)
    return zone_flat(c, z->child);
  return z && !z->frontier ? z : NULL;
}

/* CGameCtnCollection::GetZoneFromLandBlockInfo */
static ctn_zone *zone_from_land(ctn *c, const ctn_info *ci) {
  for (int pass = 0; pass < 2; pass++)
    for (uint32_t i = 0; i < c->zone_count; i++)
      if (c->zones[i].old == pass && c->zones[i].info == ci)
        return &c->zones[i];
  return NULL;
}

static ctn_zone *zone_any(ctn *c, const char *id) {
  ctn_zone *z = zone_by_id(c, id);
  return z ? z : zone_old_by_id(c, id);
}

/* CGameCtnCollection::GetUpToDateZone */
static ctn_zone *zone_up_to_date(ctn *c, ctn_zone *zone) {
  if (!zone || !zone->old)
    return zone;
  int preserve_frontier = zone->frontier;
  ctn_zone *parent = zone;
  if (zone->frontier)
    parent = zone_any(c, zone->parent);
  ctn_zone *result = zone;
  for (uint32_t t = 0; parent && t <= c->zone_count; t++) {
    ctn_zone *frontier = NULL;
    for (int pass = 0; pass < 2 && !frontier; pass++)
      for (uint32_t i = 0; i < c->zone_count; i++)
        if (c->zones[i].old == pass && c->zones[i].frontier && id_eq(c->zones[i].child, parent->id)) {
          frontier = &c->zones[i];
          break;
        }
    if (!frontier)
      return parent;
    parent = zone_any(c, frontier->parent);
    result = preserve_frontier ? frontier : parent;
    if (!result || !result->old)
      return result;
  }
  return result;
}

/* ---- grid ---- */

static int contains(const ctn *c, const uint32_t p[3]) { return p[0] < c->w && p[1] < c->h && p[2] < c->d; }
static uint32_t grid_index(const ctn *c, uint32_t x, uint32_t z) { return z + x * c->d; }

static ctn_field *field_at(ctn *c, const uint32_t p[3]) {
  if (!contains(c, p))
    return NULL;
  ctn_column *col = &c->columns[grid_index(c, p[0], p[2])];
  return p[1] < col->count ? col->fields[p[1]] : NULL;
}

static ctn_field *field_create(ctn *c, const uint32_t p[3], int terrain) {
  ctn_field *f = calloc(1, sizeof *f);
  if (!f)
    abort();
  f->terrain = terrain;
  ctn_column *col = &c->columns[grid_index(c, p[0], p[2])];
  ARR_PUSH(col->fields, col->count, col->cap, f);
  return f;
}

static ctn_field *field_ensure(ctn *c, const uint32_t p[3], int terrain) {
  ctn_field *f = field_at(c, p);
  if (f) {
    f->terrain = terrain;
    return f;
  }
  return field_create(c, p, terrain);
}

static int terrain_at(ctn *c, const uint32_t p[3]) {
  if (!contains(c, p))
    return TER_OUTSIDE;
  ctn_field *f = field_at(c, p);
  return f ? f->terrain : TER_AIR;
}

static ctn_bunit *bunit_at(ctn *c, const uint32_t p[3]) {
  ctn_field *f = field_at(c, p);
  return f ? f->bunit : NULL;
}

static ctn_block *block_at(ctn *c, const uint32_t p[3]) {
  if (!contains(c, p))
    return NULL;
  ctn_bunit *u = bunit_at(c, p);
  return u ? u->block : NULL;
}

static ctn_cell *cell_at(ctn *c, const uint32_t p[3]) { return &c->cells[grid_index(c, p[0], p[2])]; }

static ctn_zone *real_zone_for_block(ctn *c, ctn_block *b) { return b ? zone_from_land(c, b->info) : NULL; }

static ctn_zone *real_zone(ctn *c, const uint32_t p[3]) {
  uint32_t q[3] = {p[0], 0, p[2]};
  return real_zone_for_block(c, block_at(c, q));
}

static ctn_zone *cell_zone(ctn *c, const uint32_t p[3]) { return zone_by_id(c, cell_at(c, p)->zone_id); }

static void neighbour(const uint32_t p[3], uint32_t dir, uint32_t out[3]) {
  out[0] = p[0];
  out[1] = p[1];
  out[2] = p[2];
  switch (dir & 3) {
  case DIR_N: out[2]++; break;
  case DIR_W: out[0]--; break;
  case DIR_S: out[2]--; break;
  default: out[0]++; break;
  }
}

static uint32_t opposed(uint32_t d) { return (d + 2) & 3; }

/* ---- block units ---- */

static void bunit_coord(const ctn_bunit *u, uint32_t out[3]) {
  const ctn_block *b = u->block;
  for (int k = 0; k < 3; k++)
    out[k] = u->off[k] + b->coord[k];
  if (b->info->type == BT_FLAT || b->info->type == BT_FRONTIER)
    out[1] -= b->coord[1];
}

static void field_set_bunit(ctn_field *f, ctn_bunit *u) {
  if (f->bunit == u)
    return;
  if (f->bunit && f->bunit->field == f)
    f->bunit->field = NULL;
  if (u) {
    if (u->field && u->field != f && u->field->bunit == u)
      u->field->bunit = NULL;
    u->field = f;
  }
  f->bunit = u;
}

static uint32_t cycle_left8(uint32_t v) { return ((v & 0x7fu) << 1) | ((v & 0x80u) ? 1u : 0u); }

static ctn_bunit *attach_unit(ctn_block *b, ctn_uinfo *info, ctn_field *f, const uint32_t off[3], uint32_t jmask,
                              uint32_t hmask) {
  ctn_bunit *u = calloc(1, sizeof *u);
  if (!u)
    abort();
  u->block = b;
  u->info = info;
  memcpy(u->off, off, sizeof u->off);
  if (f)
    field_set_bunit(f, u);
  for (uint32_t side = 0; side < 4; side++)
    u->junction[(side + b->dir) & 3] = info ? info->junction[side] : NULL;
  u->jmask = jmask;
  u->hmask = hmask;
  for (uint32_t i = 0; i < 2 * (b->dir & 3); i++) {
    u->jmask = cycle_left8(u->jmask);
    u->hmask = cycle_left8(u->hmask);
  }
  ARR_PUSH(b->units, b->unit_count, b->unit_cap, u);
  return u;
}

static void unit_disconnect(ctn_bunit *u) {
  if (u->field && u->field->bunit == u)
    u->field->bunit = NULL;
  u->field = NULL;
}

/* ---- lists ---- */

static int block_active(const ctn *c, const ctn_block *b) {
  for (uint32_t i = 0; i < c->block_count; i++)
    if (c->blocks[i] == b)
      return 1;
  return 0;
}

static void add_block_to_add_list(ctn *c, ctn_block *b) {
  if (b)
    ARR_PUSH(c->adds, c->add_count, c->add_cap, b);
}

static void add_mobil_to_remove_list(ctn *c, ctn_mobil *m) {
  if (!m)
    return;
  for (uint32_t i = c->remove_head; i < c->remove_count; i++)
    if (c->removes[i] == m)
      return;
  ARR_PUSH(c->removes, c->remove_count, c->remove_cap, m);
}

static void add_block_to_remove_list(ctn *c, ctn_block *b) {
  if (!b)
    return;
  for (uint32_t i = c->add_head; i < c->add_count; i++)
    if (c->adds[i] == b) {
      memmove(&c->adds[i], &c->adds[i + 1], sizeof *c->adds * (c->add_count - i - 1));
      c->add_count--;
      return;
    }
  add_mobil_to_remove_list(c, b->main);
}

static ctn_mobil *new_mobil(ctn *c, int kind) {
  ctn_mobil *m = calloc(1, sizeof *m);
  if (!m)
    abort();
  m->kind = kind;
  ARR_PUSH(c->mobils, c->mobil_count, c->mobil_cap, m);
  return m;
}

/* ---- pylons ---- */

static pylon_col *col_north(ctn *c, const uint32_t p[3]) { return &c->pn[p[0] + (size_t)p[2] * c->w]; }
static pylon_col *col_south(ctn *c, const uint32_t p[3]) { return &c->ps[p[0] + (size_t)p[2] * c->w]; }
static pylon_col *col_east(ctn *c, const uint32_t p[3]) { return &c->pe[p[0] + (size_t)p[2] * (c->w + 1)]; }
static pylon_col *col_west(ctn *c, const uint32_t p[3]) { return &c->pw[p[0] + (size_t)p[2] * (c->w + 1)]; }

static pylon_col *pylon_column(ctn *c, const uint32_t p0[3], uint32_t index) {
  uint32_t p[3] = {p0[0], p0[1], p0[2]};
  uint32_t dir = index >> 1;
  int even = (index & 1u) == 0;
  switch (dir) {
  case DIR_N:
    p[2] += 1;
    return even ? col_north(c, p) : col_south(c, p);
  case DIR_S:
    return even ? col_north(c, p) : col_south(c, p);
  case DIR_E:
    p[0] += 1;
    return even ? col_west(c, p) : col_east(c, p);
  default:
    return even ? col_west(c, p) : col_east(c, p);
  }
}

static const uint8_t NEIGHBOUR_PYLON[8] = {5, 4, 7, 6, 1, 0, 3, 2};

static void update_column_mobils(ctn *c, const uint32_t p[3]);

/* CGameCtnChallenge::UpdatePylons */
static void update_pylons(ctn *c, const uint32_t p[3]) {
  if (!c->has_pylon_data)
    return;
  int changed = 0;
  for (uint32_t i = 0; i < 8; i++) {
    pylon_col *col = pylon_column(c, p, i);
    if (col->has_span) {
      col->has_span = 0;
      changed = 1;
    }
  }
  uint32_t g[3] = {p[0], 0, p[2]};
  ctn_field *gf = field_at(c, g);
  if (gf && gf->bunit) {
    ctn_zone *land = real_zone(c, g);
    ctn_zone *rz = land ? zone_by_id(c, land->id) : NULL;
    if (!rz || !rz->frontier) {
      uint32_t first = (uint32_t)cell_at(c, p)->height + 1u;
      uint32_t scan = c->h - 1u;
      while (scan > first) {
        uint32_t cp[3] = {p[0], scan, p[2]};
        ctn_bunit *center = bunit_at(c, cp);
        for (uint32_t i = 0; i < 8; i++) {
          uint32_t ndir = i < 2 ? 0u : i < 4 ? 1u : i < 6 ? 2u : 3u;
          uint32_t np[3];
          neighbour(cp, ndir, np);
          ctn_bunit *nu = NULL;
          int consider;
          if (!contains(c, np)) {
            consider = 1;
          } else {
            nu = bunit_at(c, np);
            ctn_zone *nz = cell_zone(c, np);
            consider = !(nz && nz->frontier);
          }
          if (!consider)
            continue;
          uint32_t ni = NEIGHBOUR_PYLON[i];
          int cneed = center && ((center->jmask >> i) & 1u);
          int nneed = nu && ((nu->jmask >> ni) & 1u);
          if (!cneed && !nneed)
            continue;
          pylon_col *col = pylon_column(c, cp, i);
          if (col->has_span)
            continue;
          int clear = 1;
          for (uint32_t y = first; y < scan; y++) {
            uint32_t a[3] = {p[0], y, p[2]}, b[3] = {np[0], y, np[2]};
            ctn_bunit *cb = bunit_at(c, a), *nb = bunit_at(c, b);
            int ca = !cb || ((cb->hmask >> i) & 1u);
            int na = !nb || ((nb->hmask >> ni) & 1u);
            if (!ca || !na)
              clear = 0;
          }
          if (clear) {
            col->has_span = 1;
            col->first = first;
            col->last = scan - 1u;
            changed = 1;
          }
        }
        scan--;
      }
    }
  }
  if (changed)
    update_column_mobils(c, p);
}

static void update_column_mobils(ctn *c, const uint32_t p[3]) {
  ctn_zone *z = cell_zone(c, p);
  ctn_info *pi = z && !z->frontier ? z->pylon : NULL;
  for (uint32_t i = 0; i < 8; i++) {
    pylon_col *col = pylon_column(c, p, i);
    if (col->single)
      add_mobil_to_remove_list(c, col->single);
    else
      for (int k = 0; k < 3; k++)
        if (col->triple[k])
          add_mobil_to_remove_list(c, col->triple[k]);
    if (!col->has_span || !pi) {
      col->single = NULL;
      memset(col->triple, 0, sizeof col->triple);
      continue;
    }
    uint32_t variant = col->last - col->first;
    const tmuf_block_info *bi = pi->bi;
    pylon_add pa;
    memset(&pa, 0, sizeof pa);
    pa.coord[0] = p[0];
    pa.coord[1] = col->first;
    pa.coord[2] = p[2];
    pa.index = i;
    pa.height = variant + 1u;
    if (bi->pylon_refs[1]) {
      /* first, generated middle (raised by `variant` levels), last */
      ctn_mobil *m[3];
      for (int k = 0; k < 3; k++) {
        m[k] = new_mobil(c, 3);
        m[k]->src.asset = pi->asset;
        m[k]->src.node = bi->pylon_refs[k];
      }
      m[1]->raise = variant;
      m[1]->generated = 1;
      col->single = NULL;
      memcpy(col->triple, m, sizeof m);
      memcpy(pa.triple, m, sizeof m);
    } else {
      ctn_source src = info_mobil(pi, 1, variant, 0);
      if (!src.node)
        continue;
      ctn_mobil *m = new_mobil(c, 3);
      m->src = src;
      col->single = m;
      memset(col->triple, 0, sizeof col->triple);
      pa.single = m;
    }
    ARR_PUSH(c->pylon_adds, c->pylon_count, c->pylon_cap, pa);
  }
}

/* ---- blocks ---- */

static ctn_block *new_block(ctn *c, ctn_info *ci, const uint32_t coord[3], uint32_t dir, int ground,
                            uint32_t variant, int has_sel, uint32_t sel, int origin, uint32_t tag) {
  ctn_block *b = calloc(1, sizeof *b);
  if (!b)
    abort();
  b->info = ci;
  memcpy(b->coord, coord, sizeof b->coord);
  b->dir = dir & 3;
  b->ground = ground;
  b->variant = variant;
  b->has_sel = has_sel;
  b->sel = sel;
  b->origin = origin;
  b->tag = tag;
  b->active = 1;
  ARR_PUSH(c->blocks, c->block_count, c->block_cap, b);
  return b;
}

/* CGameCtnChallenge::IsBlockOnGround (against the play field) */
static int block_on_ground(ctn *c, const ctn_info *ci, const uint32_t coord[3], uint32_t dir) {
  if (!ci || ci->n[1] == 0)
    return 0;
  uint32_t layer = 0;
  if (info_part_underground(ci, 1)) {
    int have = 0;
    for (uint32_t k = 0; k < ci->n[1]; k++)
      if (!ci->u[1][k].underground && (!have || ci->u[1][k].off[1] < layer)) {
        layer = ci->u[1][k].off[1];
        have = 1;
      }
  }
  for (uint32_t k = 0; k < ci->n[1]; k++) {
    const ctn_uinfo *u = &ci->u[1][k];
    if (u->off[1] != layer || u->underground)
      continue;
    uint32_t o[3];
    rotated_offset(ci, u, dir, 1, o);
    uint32_t q[3] = {coord[0] + o[0], coord[1] + o[1], coord[2] + o[2]};
    if (terrain_at(c, q) != TER_GROUND)
      return 0;
  }
  return 1;
}

static void remove_ground_block_at(ctn *c, uint32_t x, uint32_t z) {
  uint32_t q[3] = {x, 0, z};
  add_block_to_remove_list(c, block_at(c, q));
}

/* CGameCtnChallenge::AdjustRoadJunctionMask */
static uint32_t adjust_road_mask(ctn *c, const ctn_block *b, uint32_t mask) {
  if (b->info->type != BT_ROAD || mask == 0)
    return mask;
  ctn_zone *rz = real_zone(c, b->coord);
  if (!rz)
    return mask;
  ctn_zone *zone = zone_by_id(c, rz->id);
  if (zone && zone->frontier)
    return 0;
  ctn_zone *flat = zone_flat(c, rz->id);
  if (!flat)
    return mask;
  if (!flat->pylon)
    return 0;
  switch (b->variant) {
  case 0: case 5: return 255;
  case 1: return 3;
  case 2: return 15;
  case 3: return 51;
  case 4: return 63;
  default: return mask;
  }
}

/* CGameCtnChallenge::UpdateFieldUnits */
static int update_field_units(ctn *c, ctn_block *b) {
  ctn_info *ci = b->info;
  int create_units = b->unit_count == 0;
  int ground = 1;
  if (ci->type >= BT_CLASSIC)
    ground = block_on_ground(c, ci, b->coord, b->dir);
  uint32_t n = ci->n[ground];
  if (n == 0)
    ground = block_on_ground(c, ci, b->coord, b->dir);
  for (uint32_t k = 0; k < n; k++) {
    uint32_t o[3];
    rotated_offset(ci, &ci->u[ground][k], b->dir, ground, o);
    uint32_t q[3] = {b->coord[0] + o[0], b->coord[1] + o[1], b->coord[2] + o[2]};
    if (!contains(c, q))
      return 0;
  }
  if (ci->type <= BT_FRONTIER) {
    uint32_t x = b->coord[0], z = b->coord[2];
    int32_t y = (int32_t)b->coord[1];
    cell_at(c, b->coord)->height = (uint8_t)y;
    for (uint32_t yy = 0; y >= 0 && yy <= (uint32_t)y; yy++) {
      uint32_t q[3] = {x, yy, z};
      field_ensure(c, q, TER_UNDERGROUND);
    }
    uint32_t top[3] = {x, (uint32_t)y + 1u, z};
    field_ensure(c, top, TER_GROUND);
    ctn_uinfo *u0 = ci->n[ground] ? &ci->u[ground][0] : NULL;
    uint32_t o[3] = {0, 0, 0};
    if (u0)
      rotated_offset(ci, u0, b->dir, ground, o);
    uint32_t q0[3] = {x, 0, z};
    ctn_bunit *nu = attach_unit(b, u0, field_at(c, q0), o, 0, 0);
    ctn_zone *zone = zone_from_land(c, ci);
    int32_t zh = zone ? (int32_t)zone->height : 0, zd = zone ? (int32_t)zone->depth : 0;
    if (zd != 0) {
      int32_t first = y - zd - zh;
      if (first < 0)
        first = 0;
      int32_t last = y - zh;
      if (last < 0)
        last = 0;
      for (int32_t yy = first + 1; yy <= last; yy++) {
        uint32_t q[3] = {x, (uint32_t)yy, z}, off[3] = {0, (uint32_t)yy, 0};
        nu = attach_unit(b, u0, field_at(c, q), off, 0, 0);
      }
    }
    uint32_t uc[3];
    bunit_coord(nu, uc);
    update_pylons(c, uc);
    return 1;
  }
  for (uint32_t k = 0; k < n; k++) {
    ctn_uinfo *u = &ci->u[ground][k];
    uint32_t o[3];
    rotated_offset(ci, u, b->dir, ground, o);
    uint32_t q[3] = {b->coord[0] + o[0], b->coord[1] + o[1], b->coord[2] + o[2]};
    ctn_field *f = field_at(c, q);
    if (!f) {
      for (uint32_t yy = 0; yy <= q[1]; yy++) {
        uint32_t fq[3] = {q[0], yy, q[2]};
        if (!field_at(c, fq))
          field_create(c, fq, TER_AIR);
      }
      f = field_at(c, q);
    }
    uint32_t jmask = adjust_road_mask(c, b, u->junction_mask);
    ctn_bunit *bu;
    if (create_units)
      bu = attach_unit(b, u, f, o, jmask, u->helper_mask);
    else
      bu = k < b->unit_count ? b->units[k] : NULL;
    if (bu) {
      uint32_t uc[3];
      bunit_coord(bu, uc);
      update_pylons(c, uc);
    }
    if (f && f->terrain == TER_GROUND)
      remove_ground_block_at(c, q[0], q[2]);
  }
  return 1;
}

/* CGameCtnChallenge::GetNeighbourBlockUnitJunction */
static ctn_info *neighbour_junction(ctn *c, const uint32_t p[3], uint32_t dir) {
  uint32_t np[3];
  neighbour(p, dir, np);
  if (!contains(c, np))
    return NULL;
  ctn_bunit *u = bunit_at(c, np);
  return u ? u->junction[opposed(dir)] : NULL;
}

static int is_full_underground(ctn *c, const uint32_t p[3]) {
  if (terrain_at(c, p) != TER_UNDERGROUND)
    return 0;
  ctn_zone *z = real_zone(c, p);
  /* unsigned char - unsigned long: unsigned arithmetic */
  return !z || !z->frontier || p[1] <= (uint32_t)cell_at(c, p)->height - z->height;
}

static void set_mobils(ctn *c, ctn_block *b, ctn_mobil *main, ctn_mobil *helper) {
  (void)c;
  b->main = main;
  b->helper = helper;
}

/* CGameCtnBlock::CreateBlockMobil */
static void create_block_mobil(ctn *c, ctn_block *b) {
  ctn_info *ci = b->info;
  int family = b->ground;
  if (!b->has_sel) {
    const tmuf_node_list *l = info_variant(ci, family, b->variant);
    b->sel = l && l->count > 1 ? scene_rand_nat(c->s, 0, l->count - 1) : 0;
    b->has_sel = 1;
    if (scene_debug())
      fprintf(stderr, "block mobil %s family %d variant %u choices %u sel %u\n", ci->bi->name, family, b->variant,
              l ? l->count : 0, b->sel);
  }
  ctn_source main = info_mobil(ci, family, b->variant, b->sel);
  ctn_mobil *helper = NULL;
  const tmuf_block_info *bi = ci->bi;
  tmuf_gbx_node *fh = bi->helpers[family ? 0 : 1], *ch = bi->helpers[2];
  if (fh || ch) {
    helper = new_mobil(c, 1);
    helper->src.asset = ci->asset;
    helper->src.node = fh;
    helper->src2.asset = ci->asset;
    helper->src2.node = ch;
  }
  if (!main.node && (ci->type != BT_RECT_ASYM || b->variant != 0))
    main = info_mobil(ci, !family, b->variant, b->sel);
  ctn_mobil *mm = NULL;
  if (main.node) {
    mm = new_mobil(c, 0);
    mm->src = main;
  }
  set_mobils(c, b, mm, helper);
}

/* CGameCtnChallenge::CreateMobilForClip */
static void create_mobil_for_clip(ctn *c, ctn_block *b) {
  memset(b->clip_src, 0, sizeof b->clip_src);
  memset(b->clip_helper, 0, sizeof b->clip_helper);
  set_mobils(c, b, NULL, NULL);
  if (b->unit_count == 0)
    return;
  ctn_info *default_clip = c->default_zone ? c->default_zone->clip : NULL;
  uint32_t land[3] = {b->coord[0], 0, b->coord[2]};
  ctn_block *lb = block_at(c, land);
  if (!lb || !real_zone_for_block(c, lb))
    return;
  ctn_info *selected = NULL;
  if (is_full_underground(c, b->coord)) {
    selected = default_clip;
  } else {
    ctn_zone *rz = real_zone(c, b->coord);
    ctn_zone *zone = rz ? zone_by_id(c, rz->id) : NULL;
    if (!zone)
      return;
    ctn_zone *sz;
    if (!zone->frontier) {
      sz = zone_flat(c, rz->id);
    } else {
      if (b->ground)
        return;
      sz = zone_basic(c, rz->id);
    }
    if (!sz)
      return;
    selected = sz->clip ? sz->clip : default_clip;
  }
  if (!selected)
    return;
  int family = b->ground;
  uint32_t variant = b->variant & 0x3fu;
  int has_primary = 0, has_helper = 0;
  ctn_bunit *first = b->unit_count ? b->units[0] : NULL;
  for (uint32_t side = 0; side < 4; side++) {
    ctn_info *side_clip = selected;
    uint32_t np[3];
    neighbour(b->coord, side, np);
    ctn_block *nb = block_at(c, np);
    if (nb && nb->info->type != BT_ROAD && nb->info->type != BT_CLIP) {
      ctn_info *j = neighbour_junction(c, b->coord, side);
      if (j)
        side_clip = j;
    }
    if (first) {
      first->junction[side] = side_clip;
      side_clip = first->junction[side];
    }
    ctn_source primary = info_mobil(side_clip, family, variant, 0);
    if (!primary.node)
      continue;
    b->clip_src[side] = primary;
    has_primary = 1;
    tmuf_gbx_node *h = side_clip->bi->helpers[family ? 0 : 1];
    if (h) {
      b->clip_helper[side].asset = side_clip->asset;
      b->clip_helper[side].node = h;
      has_helper = 1;
    }
  }
  if (has_primary) {
    ctn_mobil *mm = new_mobil(c, 2);
    ctn_mobil *hm = has_helper ? new_mobil(c, 1) : NULL;
    set_mobils(c, b, mm, hm);
  }
}

/* CGameCtnCollection::SurfaceReplacementIndex != -1 */
static int has_surface_replacement(ctn *c, const char *source, const char *target) {
  for (uint32_t i = 0; i < c->coll->surface_replacement_count; i++)
    if (id_eq(c->coll->surface_replacements[2 * i], source) && id_eq(c->coll->surface_replacements[2 * i + 1], target))
      return 1;
  return 0;
}

/* ReplaySceneSurfaceResolver::ReplacementRemapApplies for an authored
   non-clip block: its ground surface differs from its column's zone and the
   collection replaces one by the other. */
static int block_replacement_applies(ctn *c, ctn_block *b) {
  if (!b->ground || b->info->type <= BT_FRONTIER || b->info->type == BT_CLIP || b->unit_count == 0 ||
      b->info->n[1] == 0)
    return 0;
  uint32_t uc[3];
  bunit_coord(b->units[0], uc);
  ctn_zone *rz = real_zone(c, uc);
  const char *source = b->info->u[1][0].surface;
  if (!rz || !source || !source[0] || id_eq(source, rz->id))
    return 0;
  return has_surface_replacement(c, source, rz->id);
}

/* CGameCtnChallenge::CreateMobilForBlock (materials are resolved later) */
static void create_mobil_for_block(ctn *c, ctn_block *b) {
  if (b->info->type == BT_CLIP) {
    /* a ground clip between its zone and a junction of another surface
       uses the replacement materials */
    int replacement = 0;
    if (b->ground && b->unit_count) {
      uint32_t uc[3];
      bunit_coord(b->units[0], uc);
      ctn_zone *rz = real_zone(c, uc);
      if (rz) {
        const char *target = rz->id, *source = rz->id;
        for (uint32_t side = 0; side < 4; side++) {
          ctn_info *j = neighbour_junction(c, b->coord, side);
          if (!j || j->n[1] == 0)
            continue;
          const char *cand = j->u[1][0].surface;
          if (!id_eq(cand, target))
            source = cand;
        }
        if (!id_eq(source, target) && has_surface_replacement(c, source, target))
          replacement = 1;
      }
    }
    b->replacement_remap = replacement;
    create_mobil_for_clip(c, b);
    return;
  }
  create_block_mobil(c, b);
}

/* CGameCtnChallenge::FindColumnTerrainModifierUnit / GetColumnModifierId */
static const char *column_modifier(ctn *c, const uint32_t p[3]) {
  for (uint32_t y = (uint32_t)cell_at(c, p)->height + 2u; y < c->h; y++) {
    uint32_t q[3] = {p[0], y, p[2]};
    ctn_bunit *u = bunit_at(c, q);
    if (u && u->info && u->info->modifier)
      return u->info->modifier;
  }
  return NULL;
}

static void replace_block(ctn *c, ctn_block *b) {
  const char *mod = NULL;
  if (b->ground || b->info->type == BT_FLAT || b->info->type == BT_FRONTIER)
    for (uint32_t i = 0; i < b->unit_count; i++) {
      const char *cand = column_modifier(c, b->coord);
      if (cand)
        mod = cand;
    }
  if (id_eq(mod, b->modifier) || (!mod && !b->modifier))
    return;
  add_block_to_remove_list(c, b);
  b->modifier = mod;
  create_mobil_for_block(c, b);
  add_block_to_add_list(c, b);
}

static void rebind_suppressed(ctn *c, ctn_block *removed) {
  for (uint32_t i = 0; i < c->block_count; i++) {
    ctn_block *t = c->blocks[i];
    if (t == removed || t->suppressed_by != removed)
      continue;
    t->suppressed_by = NULL;
    for (uint32_t k = 0; k < c->supp_count; k++)
      if (c->supps[k].target == t && c->supps[k].suppressor != removed && block_active(c, c->supps[k].suppressor)) {
        t->suppressed_by = c->supps[k].suppressor;
        break;
      }
  }
  uint32_t w = 0;
  for (uint32_t k = 0; k < c->supp_count; k++)
    if (c->supps[k].target != removed && c->supps[k].suppressor != removed)
      c->supps[w++] = c->supps[k];
  c->supp_count = w;
}

/* CGameCtnChallenge::RemoveBlock */
static int remove_block(ctn *c, ctn_block *b) {
  uint32_t idx = UINT32_MAX;
  for (uint32_t i = 0; i < c->block_count; i++)
    if (c->blocks[i] == b)
      idx = i;
  if (idx == UINT32_MAX)
    return 0;
  uint32_t n = b->unit_count;
  uint32_t (*coords)[3] = calloc(n ? n : 1, sizeof *coords);
  if (!coords)
    abort();
  for (uint32_t i = 0; i < n; i++)
    bunit_coord(b->units[i], coords[i]);
  for (uint32_t i = 0; i < n; i++) {
    ctn_bunit *u = b->units[i];
    const uint32_t *p = coords[i];
    ctn_field *f = field_at(c, p);
    unit_disconnect(u);
    if (b->info->type == BT_FLAT || b->info->type == BT_FRONTIER) {
      uint32_t q0[3] = {p[0], 0, p[2]}, q1[3] = {p[0], 1, p[2]};
      if (field_at(c, q0))
        field_at(c, q0)->terrain = TER_UNDERGROUND;
      if (field_at(c, q1))
        field_at(c, q1)->terrain = TER_GROUND;
      for (uint32_t y = 2; y < c->h; y++) {
        uint32_t q[3] = {p[0], y, p[2]};
        ctn_field *cf = field_at(c, q);
        if (!cf)
          break;
        cf->terrain = TER_AIR;
      }
    } else if (f && f->terrain == TER_GROUND) {
      uint32_t g[3] = {p[0], 0, p[2]};
      ctn_block *gb = block_at(c, g);
      add_block_to_add_list(c, gb);
      if (gb) {
        const char *m = column_modifier(c, g);
        if (!(id_eq(gb->modifier, m) || (!gb->modifier && !m)))
          replace_block(c, gb);
      }
    }
    uint32_t hp[3] = {p[0], p[1] + 1u, p[2]};
    ctn_field *higher = p[1] + 1u < c->h ? field_at(c, hp) : NULL;
    if (!higher) {
      uint32_t pp[3] = {p[0], p[1], p[2]};
      while (pp[1] > 1u) {
        ctn_field *cand = field_at(c, pp);
        ctn_column *col = &c->columns[grid_index(c, pp[0], pp[2])];
        if (!cand || cand->bunit || cand->terrain != TER_AIR || pp[1] + 1u != col->count)
          break;
        free(col->fields[pp[1]]);
        col->count--;
        pp[1]--;
      }
    }
  }
  add_block_to_remove_list(c, b);
  rebind_suppressed(c, b);
  b->active = 0;
  ARR_PUSH(c->retired, c->retired_count, c->retired_cap, b);
  memmove(&c->blocks[idx], &c->blocks[idx + 1], sizeof *c->blocks * (c->block_count - idx - 1));
  c->block_count--;
  for (uint32_t i = 0; i < n; i++)
    update_pylons(c, coords[i]);
  free(coords);
  return 1;
}

static void register_suppression(ctn *c, ctn_block *target, const ctn_block *suppressor) {
  if (!target || !suppressor || target == suppressor || !block_active(c, target) || !block_active(c, suppressor))
    return;
  int exists = 0;
  for (uint32_t k = 0; k < c->supp_count; k++)
    if (c->supps[k].target == target && c->supps[k].suppressor == suppressor)
      exists = 1;
  if (!exists) {
    suppression sp = {target, suppressor};
    ARR_PUSH(c->supps, c->supp_count, c->supp_cap, sp);
  }
  if (!target->suppressed_by)
    target->suppressed_by = suppressor;
}

/* CGameCtnChallenge::CreateBlock (clips created by UpdateClip) */
static ctn_block *create_block(ctn *c, ctn_info *ci, const uint32_t coord[3], uint32_t dir, int ground, uint32_t tag) {
  ctn_block *b = new_block(c, ci, coord, dir, ground, 0, 0, 0, ORIGIN_CREATED, tag);
  const char *mod = NULL;
  if (ground || ci->type == BT_FLAT || ci->type == BT_FRONTIER)
    for (uint32_t k = 0; k < ci->n[ground]; k++) {
      uint32_t o[3];
      rotated_offset(ci, &ci->u[ground][k], dir, ground, o);
      uint32_t q[3] = {coord[0] + o[0], coord[1] + o[1], coord[2] + o[2]};
      const char *cand = column_modifier(c, q);
      if (cand)
        mod = cand;
    }
  if (mod) {
    b->modifier = mod;
    b->replacement_remap = 0;
    b->skin_remap = 1;
  }
  update_field_units(c, b);
  create_mobil_for_block(c, b);
  add_block_to_add_list(c, b);
  return b;
}

static int clip_compatible(const ctn_info *a, const ctn_info *b) {
  if (!a)
    return 0;
  if (!a->bi->clip_id || !a->bi->clip_id[0])
    return a == b;
  return b && b->bi->name && id_eq(a->bi->clip_id, b->bi->collector_ident[0] ? b->bi->collector_ident[0] : b->bi->name);
}

/* CGameCtnChallenge::UpdateClip */
static int update_clip(ctn *c, const uint32_t coord[3], uint32_t *clip_tag) {
  ctn_block *b = block_at(c, coord);
  if (b) {
    if (b->info->type != BT_CLIP)
      return 0;
    remove_block(c, b);
  }
  int ground = terrain_at(c, coord) == TER_GROUND;
  uint32_t land[3] = {coord[0], 0, coord[2]};
  ctn_block *lb = block_at(c, land);
  if (!lb || !real_zone_for_block(c, lb))
    return 0;
  ctn_zone *rz = real_zone(c, coord);
  ctn_zone *basic = zone_basic(c, rz->id);
  if (!basic)
    return 0;
  ctn_zone *flat = zone_flat(c, basic->id);
  if (!flat)
    return 0;
  ctn_info *sel = flat->clip;
  if (!sel)
    sel = c->default_zone ? c->default_zone->clip : NULL;
  if (!sel)
    return 0;
  int replace = 0;
  for (uint32_t side = 0; side < 4; side++) {
    ctn_info *j = neighbour_junction(c, coord, side);
    uint32_t np[3];
    neighbour(coord, side, np);
    ctn_block *nb = block_at(c, np);
    if (j && nb && !clip_compatible(j, sel) && nb->info->type != BT_ROAD &&
        (info_mobil(sel, ground, 0, 0).node || info_mobil(j, ground, 0, 0).node)) {
      replace = 1;
      break;
    }
  }
  if (!replace)
    return 1;
  ctn_zone *z = real_zone(c, coord);
  if (z && z->frontier && !is_full_underground(c, coord) && coord[1] <= (uint32_t)cell_at(c, coord)->height + 1u)
    return 0;
  create_block(c, sel, coord, DIR_N, ground, 0xa0000000u | (*clip_tag)++);
  return 1;
}

/* ---- installation stream (CGameCtnApp::UpdateBlockMobils) ---- */

static void install_grow(ctn *c) {
  ctn_result *r = c->out;
  if (r->count < r->cap)
    return;
  uint32_t ncap = r->cap ? r->cap * 2 : 256;
  ctn_install *ni = realloc(r->items, sizeof *ni * ncap);
  ctn_mobil **nm = realloc(c->inst_main, sizeof *nm * ncap);
  ctn_mobil **nh = nm ? realloc(c->inst_helper, sizeof *nh * ncap) : NULL;
  if (!ni || !nm || !nh)
    abort();
  r->items = ni;
  c->inst_main = nm;
  c->inst_helper = nh;
  r->cap = ncap;
  c->inst_cap = ncap;
}

static void block_location(ctn *c, const ctn_block *b, tmuf_iso *iso) {
  const uint32_t *size = b->info->size[b->ground];
  tmuf_iso_identity(iso);
  iso->t[0] = (float)b->coord[0] * c->sq;
  iso->t[1] = (float)b->coord[1] * c->sqh;
  iso->t[2] = (float)b->coord[2] * c->sq;
  unsigned q = 0;
  switch (b->dir) {
  case DIR_W:
    iso->t[0] += (float)size[2] * c->sq;
    q = 3;
    break;
  case DIR_S:
    iso->t[0] += (float)size[0] * c->sq;
    iso->t[2] += (float)size[2] * c->sq;
    q = 2;
    break;
  case DIR_E:
    iso->t[2] += (float)size[0] * c->sq;
    q = 1;
    break;
  default:
    break;
  }
  tmuf_iso_rotate_quarter_y(iso, q);
  iso->t[1] += b->mobil_y;
}

static int placement_contains(ctn *c, const ctn_mobil *m) {
  if (!m)
    return 0;
  for (uint32_t i = 0; i < c->out->count; i++)
    if (c->out->items[i].active && (c->inst_main[i] == m || c->inst_helper[i] == m))
      return 1;
  return 0;
}

static void append_block(ctn *c, ctn_block *b) {
  if (!b->main || placement_contains(c, b->main))
    return;
  install_grow(c);
  ctn_install *in = &c->out->items[c->out->count];
  memset(in, 0, sizeof *in);
  in->kind = b->info->type == BT_CLIP ? CTN_INSTALL_CLIP : CTN_INSTALL_BLOCK;
  in->active = 1;
  in->suppressed = b->suppressed_by != NULL;
  block_location(c, b, &in->iso);
  in->tag = b->tag;
  in->info = b->info->bi;
  in->ground = b->ground;
  in->start_line = b->info->bi->has_way_type && (b->info->bi->way_type == 0 || b->info->bi->way_type == 4);
  if (in->kind == CTN_INSTALL_CLIP) {
    memcpy(in->clip, b->clip_src, sizeof in->clip);
  } else {
    in->main = b->main->src;
    if (b->helper) {
      in->helper[0] = b->helper->src;
      in->helper[1] = b->helper->src2;
    }
  }
  in->material = b->replacement_remap ? CTN_MATERIAL_REPLACEMENT : b->skin_remap ? CTN_MATERIAL_SKIN : CTN_MATERIAL_BLOCK;
  in->terrain_modifier = b->modifier;
  c->inst_main[c->out->count] = b->main;
  c->inst_helper[c->out->count] = b->helper;
  c->out->count++;
}

typedef struct pylon_side {
  float x_near, z_near;
  int x_far, z_far;
  unsigned quarter;
} pylon_side;

static const pylon_side PYLON_SIDES[8] = {
    {4.0f, 0.0f, 1, 1, 2}, {4.0f, 0.0f, 0, 1, 0}, {0.0f, 4.0f, 0, 1, 1}, {0.0f, 4.0f, 0, 0, 3},
    {4.0f, 0.0f, 0, 0, 0}, {4.0f, 0.0f, 1, 0, 2}, {0.0f, 4.0f, 1, 0, 3}, {0.0f, 4.0f, 1, 1, 1},
};

static void append_pylon_part(ctn *c, ctn_mobil *m, const tmuf_iso *iso, uint32_t tag) {
  install_grow(c);
  ctn_install *in = &c->out->items[c->out->count];
  memset(in, 0, sizeof *in);
  in->kind = CTN_INSTALL_PYLON;
  in->active = 1;
  in->iso = *iso;
  in->tag = tag;
  in->main = m->src;
  in->pylon_raise = m->raise;
  in->pylon_generated = m->generated;
  c->inst_main[c->out->count] = m;
  c->inst_helper[c->out->count] = NULL;
  c->out->count++;
}

static void add_pylon_to_scene(ctn *c, const pylon_add *pa, uint32_t tag) {
  if (pa->index >= 8)
    return;
  ctn_mobil *first = pa->single ? pa->single : pa->triple[0];
  if (!first || placement_contains(c, first))
    return;
  const pylon_side *side = &PYLON_SIDES[pa->index];
  tmuf_iso iso;
  tmuf_iso_identity(&iso);
  tmuf_iso_rotate_quarter_y(&iso, side->quarter);
  iso.t[0] = (float)pa->coord[0] * c->sq + (side->x_far ? c->sq - side->x_near : side->x_near);
  iso.t[1] = (float)pa->coord[1] * c->sqh;
  iso.t[2] = (float)pa->coord[2] * c->sq + (side->z_far ? c->sq - side->z_near : side->z_near);
  append_pylon_part(c, first, &iso, tag);
  if (pa->single)
    return;
  append_pylon_part(c, pa->triple[1], &iso, tag);
  iso.t[1] += (float)pa->height * c->sqh;
  append_pylon_part(c, pa->triple[2], &iso, tag);
}

static void remove_mobil_from_scene(ctn *c, const ctn_mobil *m) {
  for (uint32_t i = 0; i < c->out->count; i++) {
    ctn_install *in = &c->out->items[i];
    if (!in->active)
      continue;
    if (c->inst_main[i] == m) {
      c->inst_main[i] = NULL;
      in->active = 0; /* no main or trigger left */
    } else if (c->inst_helper[i] == m) {
      c->inst_helper[i] = NULL;
      memset(in->helper, 0, sizeof in->helper);
    }
  }
}

static void update_block_mobils(ctn *c) {
  uint32_t pylon_tag = 0;
  while (c->add_head < c->add_count)
    append_block(c, c->adds[c->add_head++]);
  while (c->pylon_head < c->pylon_count)
    add_pylon_to_scene(c, &c->pylon_adds[c->pylon_head++], 0xb0000000u | pylon_tag++);
  while (c->remove_head < c->remove_count)
    remove_mobil_from_scene(c, c->removes[c->remove_head++]);
}

/* ---- BuildReplayChallenge ---- */

typedef struct field_unit_rec {
  int32_t pos[3];
  int type;
  uint32_t ordinal; /* authored index */
} field_unit_rec;

typedef struct marker {
  int32_t x, y, z;
  ctn_block *block;
} marker;

static int markers_contain(const marker *m, uint32_t n, int32_t x, int32_t y, int32_t z) {
  for (uint32_t i = n; i-- > 0;)
    if (m[i].x == x && m[i].z == z && m[i].y >= y)
      return m[i].y == y;
  return 0;
}

/* replay_challenge_field_units.cpp IsBlockOnGround (against top markers) */
static int on_ground_markers(const ctn_info *ci, const marker *m, uint32_t n, const tmuf_challenge_block *pb) {
  if (ci->type <= BT_FRONTIER)
    return 1;
  if (ci->n[1] == 0)
    return 0;
  int has_ug = info_part_underground(ci, 1);
  uint32_t layer = 0;
  if (has_ug) {
    int found = 0;
    for (uint32_t k = 0; k < ci->n[1]; k++)
      if (!ci->u[1][k].underground && (!found || ci->u[1][k].off[1] < layer)) {
        layer = ci->u[1][k].off[1];
        found = 1;
      }
  }
  for (uint32_t k = 0; k < ci->n[1]; k++) {
    const ctn_uinfo *u = &ci->u[1][k];
    if (u->underground || u->off[1] != layer)
      continue;
    uint32_t o[3];
    rotated_offset(ci, u, pb->dir, 1, o);
    if (!markers_contain(m, n, (int32_t)pb->x + (int32_t)o[0], (int32_t)pb->y + (int32_t)o[1],
                         (int32_t)pb->z + (int32_t)o[2]))
      return 0;
  }
  return 1;
}

int ctn_build(tmuf_scene *s, const tmuf_challenge *map, tmuf_asset *ca, ctn_result *out) {
  memset(out, 0, sizeof *out);
  ctn cc;
  ctn *c = &cc;
  memset(c, 0, sizeof *c);
  c->s = s;
  c->out = out;
  c->w = s->size[0];
  c->h = s->size[1];
  c->d = s->size[2];
  c->default_height = s->base_height;
  c->sq = s->square_size;
  c->sqh = s->square_height;
  const tmuf_collection *coll = ca->root;
  c->coll = coll;

  /* zones */
  c->zones = calloc(coll->zones.count + 1, sizeof *c->zones);
  if (!c->zones)
    return 0;
  tmuf_asset *dza;
  tmuf_gbx_node *dzn = tmuf_assets_follow(&s->assets, ca, coll->default_zone, &dza);
  for (uint32_t i = 0; i < coll->zones.count; i++) {
    tmuf_asset *za;
    tmuf_gbx_node *zn = tmuf_assets_follow(&s->assets, ca, coll->zones.nodes[i], &za);
    if (!zn || !zn->data || (zn->class_id != 0x0305d000u && zn->class_id != 0x0305e000u))
      continue;
    const tmuf_zone *z = zn->data;
    ctn_zone *cz = &c->zones[c->zone_count++];
    cz->id = z->name;
    cz->frontier = zn->class_id == 0x0305e000u;
    cz->old = z->old_zone;
    cz->height = z->height;
    cz->depth = z->depth;
    cz->info = z->block_infos[0] ? info_from_node(c, za, z->block_infos[0]) : NULL;
    if (!cz->frontier) {
      cz->clip = z->block_infos[1] ? info_from_node(c, za, z->block_infos[1]) : NULL;
      cz->pylon = z->block_infos[3] ? info_from_node(c, za, z->block_infos[3]) : NULL;
    } else {
      cz->parent = z->frontier_parent;
      cz->child = z->frontier_child;
    }
    if (zn == dzn)
      c->default_zone = cz;
  }
  if (!c->default_zone) {
    free(c->zones);
    return 0;
  }
  c->has_pylon_data = c->default_zone->pylon != NULL;

  size_t cols = (size_t)c->w * c->d;
  c->cells = calloc(cols ? cols : 1, sizeof *c->cells);
  c->columns = calloc(cols ? cols : 1, sizeof *c->columns);
  c->pn = calloc((size_t)c->w * (c->d + 1) + 1, sizeof *c->pn);
  c->ps = calloc((size_t)c->w * (c->d + 1) + 1, sizeof *c->ps);
  c->pe = calloc((size_t)c->d * (c->w + 1) + c->w + 2, sizeof *c->pe);
  c->pw = calloc((size_t)c->d * (c->w + 1) + c->w + 2, sizeof *c->pw);
  if (!c->cells || !c->columns || !c->pn || !c->ps || !c->pe || !c->pw)
    return 0;

  /* authored block infos */
  uint32_t nb = map->block_count;
  ctn_info **infos = calloc(nb ? nb : 1, sizeof *infos);
  if (!infos)
    return 0;
  for (uint32_t i = 0; i < nb; i++) {
    infos[i] = info_for(c, scene_block_info(s, map->blocks[i].name));
    if (!infos[i])
      out->blocks_missing++;
  }

  /* ChallengeFieldUnits::Build: terrain top markers, then the units of the
     placed mobils with their ground/air family */
  field_unit_rec *fus = NULL;
  uint32_t fu_count = 0, fu_cap = 0;
  marker *mk = NULL;
  uint32_t mk_count = 0, mk_cap = 0;
  uint8_t *occupied = calloc(cols ? cols : 1, 1);
  if (!occupied)
    return 0;
  for (uint32_t i = 0; i < nb; i++) {
    const ctn_info *ci = infos[i];
    if (!ci || ci->type > BT_FRONTIER)
      continue;
    const tmuf_challenge_block *pb = &map->blocks[i];
    int ground = 1; /* terrain blocks */
    if (ci->n[ground] == 0)
      continue;
    field_unit_rec r = {{pb->x, pb->y, pb->z}, ci->type, i};
    ARR_PUSH(fus, fu_count, fu_cap, r);
  }
  for (uint32_t i = 0; i < fu_count; i++) {
    marker m = {fus[i].pos[0], fus[i].pos[1] + 1, fus[i].pos[2], NULL};
    ARR_PUSH(mk, mk_count, mk_cap, m);
    if (fus[i].pos[0] >= 0 && fus[i].pos[2] >= 0 && (uint32_t)fus[i].pos[0] < c->w && (uint32_t)fus[i].pos[2] < c->d)
      occupied[grid_index(c, (uint32_t)fus[i].pos[0], (uint32_t)fus[i].pos[2])] = 1;
  }
  for (uint32_t x = 0; x < c->w; x++)
    for (uint32_t z = 0; z < c->d; z++)
      if (!occupied[grid_index(c, x, z)]) {
        marker m = {(int32_t)x, (int32_t)c->default_height + 1, (int32_t)z, NULL};
        ARR_PUSH(mk, mk_count, mk_cap, m);
      }
  for (uint32_t i = 0; i < nb; i++) {
    const ctn_info *ci = infos[i];
    if (!ci || ci->type <= BT_FRONTIER)
      continue;
    const tmuf_challenge_block *pb = &map->blocks[i];
    int ground = on_ground_markers(ci, mk, mk_count, pb);
    for (uint32_t k = 0; k < ci->n[ground]; k++) {
      uint32_t o[3];
      rotated_offset(ci, &ci->u[ground][k], pb->dir, ground, o);
      field_unit_rec r = {{(int32_t)pb->x + (int32_t)o[0], (int32_t)pb->y + (int32_t)o[1], (int32_t)pb->z + (int32_t)o[2]},
                          ci->type,
                          i};
      ARR_PUSH(fus, fu_count, fu_cap, r);
    }
  }

  /* authored blocks */
  ctn_block **authored = calloc(nb ? nb : 1, sizeof *authored);
  if (!authored)
    return 0;
  for (uint32_t i = 0; i < nb; i++) {
    if (!infos[i])
      continue;
    const tmuf_challenge_block *pb = &map->blocks[i];
    uint32_t sel = (pb->flags >> 6) & 0x3fu;
    uint32_t coord[3] = {pb->x, pb->y, pb->z};
    ctn_block *b = new_block(c, infos[i], coord, pb->dir, (pb->flags & 0x1000u) != 0, pb->flags & 0x3fu, sel != 0x3fu,
                             sel, ORIGIN_AUTHORED, i);
    /* UsesCollectionLandZoneHeight */
    if (b->info->type == BT_FRONTIER) {
      ctn_zone *z = zone_from_land(c, b->info);
      if (z && !z->old)
        b->mobil_y = -(float)z->height * c->sqh;
    }
    authored[i] = b;
  }

  /* automatic base: columns without a terrain top marker */
  ctn_block **autob = NULL;
  uint32_t auto_count = 0, auto_cap = 0;
  ctn_info *base = c->default_zone->info;
  if (base)
    for (uint32_t x = 0; x < c->w; x++)
      for (uint32_t z = 0; z < c->d; z++) {
        if (occupied[grid_index(c, x, z)])
          continue;
        uint32_t coord[3] = {x, c->default_height, z};
        ctn_block *b = new_block(c, base, coord, DIR_N, 1, 0, 0, 0, ORIGIN_AUTO_BASE,
                                 0x80000000u | (x * c->d + z));
        ARR_PUSH(autob, auto_count, auto_cap, b);
      }

  /* ApplyFieldUnitRemoval */
  {
    marker *tm = NULL;
    uint32_t tn = 0, tc = 0;
    for (uint32_t i = 0; i < fu_count; i++) {
      if (fus[i].type > BT_FRONTIER || fus[i].pos[1] < 0 || !authored[fus[i].ordinal])
        continue;
      marker m = {fus[i].pos[0], fus[i].pos[1] + 1, fus[i].pos[2], authored[fus[i].ordinal]};
      ARR_PUSH(tm, tn, tc, m);
    }
    for (uint32_t i = 0; i < auto_count; i++) {
      marker m = {(int32_t)autob[i]->coord[0], (int32_t)autob[i]->coord[1] + 1, (int32_t)autob[i]->coord[2], autob[i]};
      ARR_PUSH(tm, tn, tc, m);
    }
    for (uint32_t i = 0; i < fu_count; i++) {
      if (fus[i].type <= BT_FRONTIER || !authored[fus[i].ordinal])
        continue;
      ctn_block *remover = authored[fus[i].ordinal];
      int32_t x = fus[i].pos[0], y = fus[i].pos[1], z = fus[i].pos[2];
      int found = 0;
      int32_t my = 0;
      for (uint32_t k = tn; k-- > 0;)
        if (tm[k].x == x && tm[k].z == z && tm[k].y >= y) {
          found = 1;
          my = tm[k].y;
          break;
        }
      if (!found || my != y)
        continue;
      for (uint32_t k = tn; k-- > 0;)
        if (tm[k].x == x && tm[k].z == z) {
          register_suppression(c, tm[k].block, remover);
          break;
        }
    }
    free(tm);
  }

  /* InstallConstructedChallengeZones: zone grid */
  for (size_t i = 0; i < cols; i++) {
    c->cells[i].zone_id = c->default_zone->id;
    c->cells[i].height = (uint8_t)c->default_height;
  }
  for (uint32_t i = 0; i < c->block_count; i++) {
    ctn_block *b = c->blocks[i];
    if (b->info->type > BT_FRONTIER)
      continue;
    /* CheckTerrainBlock */
    ctn_zone *z0 = zone_from_land(c, b->info);
    if (z0 && (z0->old || (z0->frontier && b->coord[1] == 0))) {
      ctn_zone *up = zone_up_to_date(c, z0);
      if (up && up->info) {
        b->info = up->info;
        b->coord[1] = z0->height;
      }
    }
    ctn_zone *rz = zone_from_land(c, b->info);
    ctn_zone *basic = rz ? zone_basic(c, rz->id) : NULL;
    if (!basic)
      continue;
    if (b->coord[0] < c->w && b->coord[2] < c->d) {
      cell_at(c, b->coord)->zone_id = basic->id;
      cell_at(c, b->coord)->height = (uint8_t)b->coord[1];
    }
  }

  /* pass 0: terrain field units; pass 1: the others (mobils right away) */
  for (int pass = 0; pass < 2; pass++) {
    uint32_t i = 0;
    while (i < c->block_count) {
      ctn_block *b = c->blocks[i];
      int terrain = b->info->type <= BT_FRONTIER;
      if ((b->suppressed_by && !terrain) || terrain != (pass == 0)) {
        i++;
        continue;
      }
      int attached = update_field_units(c, b);
      if (pass != 0 && !attached) {
        if (!remove_block(c, b))
          i++;
        continue;
      }
      if (pass != 0 && b->origin == ORIGIN_AUTHORED) {
        if (block_replacement_applies(c, b))
          b->replacement_remap = 1;
        create_mobil_for_block(c, b);
      }
      i++;
    }
  }

  /* QueueInitialBlockMobils: authored terrain, automatic base, others */
  for (uint32_t i = 0; i < nb; i++)
    if (authored[i] && authored[i]->info->type <= BT_FRONTIER && block_active(c, authored[i])) {
      create_mobil_for_block(c, authored[i]);
      add_block_to_add_list(c, authored[i]);
    }
  for (uint32_t i = 0; i < auto_count; i++)
    if (block_active(c, autob[i])) {
      create_mobil_for_block(c, autob[i]);
      add_block_to_add_list(c, autob[i]);
    }
  for (uint32_t i = 0; i < nb; i++)
    if (authored[i] && authored[i]->info->type > BT_FRONTIER && block_active(c, authored[i]))
      add_block_to_add_list(c, authored[i]);

  /* SynchronizeColumnTerrainModifiers */
  for (uint32_t i = 0; i < c->block_count; i++) {
    ctn_block *b = c->blocks[i];
    if (!b->ground && b->info->type != BT_FLAT && b->info->type != BT_FRONTIER)
      continue;
    const char *mod = NULL;
    for (uint32_t k = 0; k < b->unit_count; k++) {
      uint32_t uc[3];
      bunit_coord(b->units[k], uc);
      const char *cand = column_modifier(c, uc);
      if (cand)
        mod = cand;
    }
    int ground = b->ground;
    int self_modifier = 0;
    for (uint32_t k = 0; k < b->info->n[ground]; k++)
      if (b->info->u[ground][k].modifier)
        self_modifier = 1;
    if (!mod || self_modifier)
      continue;
    int replacement = b->replacement_remap;
    b->modifier = mod;
    b->skin_remap = replacement ? b->skin_remap : 1;
    create_mobil_for_block(c, b);
  }

  /* ReplaySceneBlockPlacements::PopulateFromChallenge */
  update_block_mobils(c);
  /* CGameCtnApp::AddClipsToScene */
  {
    uint32_t idx = 0, remaining = c->block_count, clip_tag = 0;
    int saw = 0;
    while (idx < remaining) {
      ctn_block *b = idx < c->block_count ? c->blocks[idx] : NULL;
      if (!b || b->info->type != BT_CLIP) {
        idx++;
        continue;
      }
      uint32_t coord[3] = {b->coord[0], b->coord[1], b->coord[2]};
      update_clip(c, coord, &clip_tag);
      remaining--;
      saw = 1;
    }
    if (saw)
      update_block_mobils(c);
  }
  out->blocks_placed = c->block_count;

  /* cleanup */
  free(infos);
  free(authored);
  free(autob);
  free(fus);
  free(mk);
  free(occupied);
  for (uint32_t i = 0; i < c->block_count; i++) {
    for (uint32_t k = 0; k < c->blocks[i]->unit_count; k++)
      free(c->blocks[i]->units[k]);
    free(c->blocks[i]->units);
    free(c->blocks[i]);
  }
  for (uint32_t i = 0; i < c->retired_count; i++) {
    for (uint32_t k = 0; k < c->retired[i]->unit_count; k++)
      free(c->retired[i]->units[k]);
    free(c->retired[i]->units);
    free(c->retired[i]);
  }
  free(c->blocks);
  free(c->retired);
  for (size_t i = 0; i < cols; i++) {
    for (uint32_t k = 0; k < c->columns[i].count; k++)
      free(c->columns[i].fields[k]);
    free(c->columns[i].fields);
  }
  free(c->columns);
  free(c->cells);
  free(c->pn), free(c->ps), free(c->pe), free(c->pw);
  free(c->adds);
  free(c->removes);
  free(c->pylon_adds);
  free(c->supps);
  for (uint32_t i = 0; i < c->mobil_count; i++)
    free(c->mobils[i]);
  free(c->mobils);
  free(c->inst_main);
  free(c->inst_helper);
  while (c->infos) {
    ctn_info *n = c->infos->next;
    free(c->infos->u[0]);
    free(c->infos->u[1]);
    free(c->infos);
    c->infos = n;
  }
  free(c->zones);
  return 1;
}

void ctn_result_free(ctn_result *r) {
  free(r->items);
  memset(r, 0, sizeof *r);
}
