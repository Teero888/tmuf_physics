/* The lightmap atlas of a track (Stadium's PreLightGen): which corpora the
   game bakes, and where CHmsPackLightMapAlloc places them.

   CHmsZoneVPacker::AddNewSolid hands every static corpus to
   CHmsPackLightMap::BlockAdd, which keeps the ones whose tree has a shader
   sampling PreLightGen and whose solid gives a cell count, with the world
   box of its tree. CHmsPackLightMap::UpdateMapping sorts them by that box
   (CFastRadixSort, six passes) and places them in a grid of cells
   (CHmsPackLightMapAlloc::Reset, AllocBlock, ComputeUv01ToLM).

   The game's x87 code runs at 24-bit precision: every operation below is a
   binary32 operation in the game's order. */

#include "common/lightmap.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

enum {
  CLS_SHADER = 0x09002000u,
  CLS_MATERIAL = 0x09079000u,
  CLS_SAMPLER = 0x0907e000u,
  CLS_SURFACE = 0x0900c000u,
  CLS_SURFACE_GEOM = 0x0900f000u,
  CLS_VISUAL = 0x09006000u
};

/* CHmsPackLightMapAlloc's settings (TmForever: DAT_00cde0e8.., s_WarpLmBlockCount) */
enum {
  LM_PADDING = 1,      /* texels left at both ends of a corpus */
  LM_MIP_LEVELS = 2,   /* for atlases up to 2048: cells start on multiples of 1 << 2 */
  LM_FREE_BLOCKS = 1,  /* the rest of a row a corpus does not fit in is reused */
  LM_WARP_COLUMNS = 6, /* the Warp's reserved cells */
  LM_WARP_ROWS = 10,
};

static uint32_t node_class(const tmuf_gbx_node *n) { return n && n->cls ? n->cls->id : 0; }

static int tree_class(uint32_t cls) { return cls == 0x0904f000u || cls == 0x09015000u || cls == 0x09062000u; }

/* ---- which corpora ---- */

static int samples_prelight(tmuf_scene *s, tmuf_asset *owner, const tmuf_plug_shader *sh) {
  for (uint32_t i = 0; i < sh->address_count; i++) {
    tmuf_asset *aa;
    tmuf_gbx_node *an = tmuf_assets_follow(&s->assets, owner, sh->addresses[i], &aa);
    if (node_class(an) != CLS_SAMPLER || !an->data)
      continue;
    /* CPlugShaderApply::OnNodLoaded: flag 0x1000 for a layer "PreLightGen"
       or "PreLightGenTx" */
    const char *name = ((const tmuf_plug_bitmap_address *)an->data)->sampler;
    if (name && (strcmp(name, "PreLightGen") == 0 || strcmp(name, "PreLightGenTx") == 0))
      return 1;
  }
  return 0;
}

static int node_prelight(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *ref) {
  if (!ref)
    return 0;
  tmuf_asset *na;
  tmuf_gbx_node *n = tmuf_assets_follow(&s->assets, owner, ref, &na);
  if (node_class(n) == CLS_SHADER && n->data)
    return samples_prelight(s, na, n->data);
  if (node_class(n) != CLS_MATERIAL)
    return 0;
  tmuf_asset *sa = NULL, *ca = NULL;
  const tmuf_plug_material_custom *custom = NULL;
  tmuf_gbx_node *sn = tmuf_scene_material_shader(s, owner, ref, &sa, &custom, &ca);
  return node_class(sn) == CLS_SHADER && sn->data && samples_prelight(s, sa, sn->data);
}

/* CPlugTree::CIteratorShader over the tree: a shader with flag 0x1000 */
static int tree_prelight(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *node, int depth) {
  if (depth > 64)
    return 0;
  tmuf_asset *ta;
  tmuf_gbx_node *tn = tmuf_assets_follow(&s->assets, owner, node, &ta);
  if (!tn || !tn->data || !tree_class(node_class(tn)))
    return 0;
  const tmuf_plug_tree *t = tn->data;
  if (node_prelight(s, ta, t->shader) || node_prelight(s, ta, t->material))
    return 1;
  for (uint32_t i = 0; i < t->child_count; i++)
    if (tree_prelight(s, ta, t->children[i], depth + 1))
      return 1;
  return 0;
}

/* ---- boxes (GmBoxAligned: centre, half extents) ---- */

static void box_null(float b[6]) {
  b[0] = b[1] = b[2] = 0.0f;
  b[3] = b[4] = b[5] = -1.0f;
}

/* GmBoxAligned::SetMinMax */
static void box_set_min_max(float b[6], const float mn[3], const float mx[3]) {
  for (int k = 0; k < 3; k++)
    b[k] = (mn[k] + mx[k]) * 0.5f;
  for (int k = 0; k < 3; k++)
    b[3 + k] = (mx[k] - mn[k]) * 0.5f;
}

/* GmBoxAligned::Union */
static void box_union(float a[6], const float b[6]) {
  if (!(a[3] >= 0.0f)) {
    memcpy(a, b, 6 * sizeof *a);
    return;
  }
  if (!(b[3] >= 0.0f))
    return;
  float mn[3], mx[3];
  for (int k = 0; k < 3; k++) {
    const float am = a[k] - a[3 + k], bm = b[k] - b[3 + k];
    mn[k] = am <= bm ? am : bm;
    const float ax = a[k] + a[3 + k], bx = b[3 + k] + b[k];
    mx[k] = ax < bx ? bx : ax;
  }
  box_set_min_max(a, mn, mx);
}

/* GmBoxAligned::SetMult(box, iso), the game's operation order */
static void box_mult(float out[6], const float b[6], const tmuf_iso *iso) {
  const float (*m)[3] = iso->m;
  const float *t = iso->t;
  float r[6];
  r[0] = ((b[0] * m[0][0] + m[0][1] * b[1]) + m[0][2] * b[2]) + t[0];
  r[1] = ((m[1][1] * b[1] + b[0] * m[1][0]) + m[1][2] * b[2]) + t[1];
  r[2] = ((m[2][1] * b[1] + m[2][0] * b[0]) + m[2][2] * b[2]) + t[2];
  for (int k = 0; k < 3; k++)
    r[3 + k] = (fabsf(m[k][1]) * b[4] + fabsf(m[k][0]) * b[3]) + fabsf(m[k][2]) * b[5];
  memcpy(out, r, sizeof r);
}

/* CPlugSurfaceGeom's box, recomputed at load (GmSurf::GetBoundingBox) */
static int surface_box(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *ref, float b[6]) {
  tmuf_asset *sa, *ga;
  tmuf_gbx_node *sn = tmuf_assets_follow(&s->assets, owner, ref, &sa);
  if (node_class(sn) != CLS_SURFACE || !sn->data)
    return 0;
  tmuf_gbx_node *gn = tmuf_assets_follow(&s->assets, sa, ((const tmuf_plug_surface *)sn->data)->geom, &ga);
  if (node_class(gn) != CLS_SURFACE_GEOM || !gn->data)
    return 0;
  const tmuf_plug_surface_geom *g = gn->data;
  box_null(b);
  switch (g->type) {
  case TMUF_SURF_SPHERE:
    b[0] = b[1] = b[2] = 0.0f;
    b[3] = b[4] = b[5] = g->params[0];
    break;
  case TMUF_SURF_ELLIPSOID:
    b[0] = b[1] = b[2] = 0.0f;
    memcpy(b + 3, g->params, 3 * sizeof *b);
    break;
  case TMUF_SURF_BOX:
    memcpy(b, g->params, 6 * sizeof *b);
    break;
  case TMUF_SURF_MESH:
    /* GmSurfMesh::GetMeshBoundingBox: the octree's root cell */
    if (g->cell_count)
      memcpy(b, g->cells + 4, 6 * sizeof *b);
    break;
  default:
    break;
  }
  return 1;
}

/* CPlugTree::UpdateBoundingBox(0) (GetDecorationBoundingBox for the tree's
   own visual and surface; all children, the levels of a CPlugTreeVisualMip
   included). Returns the box's validity as the game uses it. */
static int tree_box(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *node, float out[6], int depth) {
  box_null(out);
  if (depth > 64)
    return 0;
  tmuf_asset *ta;
  tmuf_gbx_node *tn = tmuf_assets_follow(&s->assets, owner, node, &ta);
  if (!tn || !tn->data || !tree_class(node_class(tn)))
    return 0;
  const tmuf_plug_tree *t = tn->data;
  float box[6];
  box_null(box);
  int own = 0;
  if (t->visual) {
    tmuf_asset *va;
    tmuf_gbx_node *vn = tmuf_assets_follow(&s->assets, ta, t->visual, &va);
    if (vn && vn->data && node_class(vn) == CLS_VISUAL) {
      memcpy(box, ((const tmuf_plug_visual *)vn->data)->bbox, sizeof box);
      own = 1;
    }
  }
  float sb[6];
  if (t->surface && surface_box(s, ta, t->surface, sb) && sb[3] >= 0.0f) {
    if (own)
      box_union(box, sb);
    else
      memcpy(box, sb, sizeof box);
    own = 1;
  }
  uint32_t i = 0;
  if (!own) {
    if (!t->child_count) {
      /* CPlugTree::SFlags bit 3 (visible) clear: valid, with a null box */
      return (int)(~(t->flags >> 3) & 1u);
    }
    for (; i < t->child_count; i++) {
      float cb[6];
      if (tree_box(s, ta, t->children[i], cb, depth + 1) && cb[3] >= 0.0f) {
        memcpy(box, cb, sizeof box);
        break;
      }
    }
    if (i == t->child_count)
      return 0;
    i++;
  }
  for (; i < t->child_count; i++) {
    float cb[6];
    if (tree_box(s, ta, t->children[i], cb, depth + 1) && cb[3] >= 0.0f)
      box_union(box, cb);
  }
  if (t->has_iso) {
    tmuf_iso local;
    tmuf_iso_from_archive(&local, t->iso);
    box_mult(out, box, &local);
  } else {
    memcpy(out, box, sizeof box);
  }
  return 1;
}

/* ---- order: CFastRadixSort::Sort (float keys, ranks kept between calls) ---- */

typedef struct radix {
  uint32_t n;
  uint32_t *ranks, *ranks2;
  int valid;
} radix;

static uint32_t key_bits(float f) {
  uint32_t u;
  memcpy(&u, &f, 4);
  return u;
}

static void radix_sort(radix *r, const float *keys, uint32_t n) {
  if (!r->valid) {
    for (uint32_t i = 0; i < n; i++)
      r->ranks[i] = i;
    r->valid = 1;
  }
  if (!n)
    return;
  /* already sorted in the current order: nothing changes */
  uint32_t k = 1;
  float prev = keys[r->ranks[0]];
  for (; k < n; k++) {
    const float v = keys[r->ranks[k]];
    if (v < prev)
      break;
    prev = v;
  }
  if (k == n)
    return;
  static uint32_t count[4][256];
  memset(count, 0, sizeof count);
  for (uint32_t i = 0; i < n; i++) {
    const uint32_t u = key_bits(keys[i]);
    for (int b = 0; b < 4; b++)
      count[b][(u >> (8 * b)) & 0xffu]++;
  }
  uint32_t negatives = 0;
  for (int i = 128; i < 256; i++)
    negatives += count[3][i];
  uint32_t link[256];
  for (int b = 0; b < 4; b++) {
    const uint32_t first = (key_bits(keys[0]) >> (8 * b)) & 0xffu;
    const int unique = count[b][first] == n;
    if (b < 3) {
      if (unique)
        continue;
      link[0] = 0;
      for (int i = 1; i < 256; i++)
        link[i] = link[i - 1] + count[b][i - 1];
      for (uint32_t i = 0; i < n; i++) {
        const uint32_t id = r->ranks[i];
        r->ranks2[link[(key_bits(keys[id]) >> (8 * b)) & 0xffu]++] = id;
      }
    } else if (unique) {
      if (first < 128)
        continue;
      for (uint32_t i = 0; i < n; i++)
        r->ranks2[i] = r->ranks[n - 1 - i];
    } else {
      /* positives after the negatives; negatives filled from the back */
      link[0] = negatives;
      for (int i = 1; i < 128; i++)
        link[i] = link[i - 1] + count[3][i - 1];
      link[255] = 0;
      for (int i = 0; i < 127; i++)
        link[254 - i] = link[255 - i] + count[3][255 - i];
      for (int i = 128; i < 256; i++)
        link[i] += count[3][i];
      for (uint32_t i = 0; i < n; i++) {
        const uint32_t id = r->ranks[i];
        const uint32_t top = key_bits(keys[id]) >> 24;
        if (top < 128)
          r->ranks2[link[top]++] = id;
        else
          r->ranks2[--link[top]] = id;
      }
    }
    uint32_t *t = r->ranks;
    r->ranks = r->ranks2;
    r->ranks2 = t;
  }
}

/* ---- placement: CHmsPackLightMapAlloc ---- */

typedef struct free_block {
  uint32_t x, y, len;
} free_block;

typedef struct alloc {
  uint32_t size, cols, rows, align;
  uint32_t reserve_cols, reserve_rows;
  uint32_t cur_x, cur_y;
  uint32_t *col_start, *col_width, *row_start, *row_height;
  free_block *free;
  uint32_t free_count;
} alloc;

/* CHmsPackLightMapAlloc::GetMipMapLevelCount */
static uint32_t mip_levels(uint32_t size) {
  if (size <= 2048)
    return LM_MIP_LEVELS;
  uint32_t bits = 0;
  while ((size >> bits) > 1)
    bits++;
  return LM_MIP_LEVELS + bits - 11u;
}

static void edges(uint32_t n, uint32_t size, uint32_t align, uint32_t *start, uint32_t *width) {
  for (uint32_t j = 0; j < n; j++) {
    const float at = (float)j / (float)n * (float)size;
    start[j] = align * (uint32_t)lrintf(at / (float)align);
    if (j)
      width[j - 1] = start[j] - start[j - 1];
  }
  if (n)
    width[n - 1] = size - start[n - 1];
}

/* CHmsPackLightMapAlloc::Reset */
static int alloc_reset(alloc *a, uint32_t total, uint32_t size, uint32_t reserve_cols, uint32_t reserve_rows) {
  memset(a, 0, sizeof *a);
  a->size = size;
  a->reserve_cols = reserve_cols;
  a->reserve_rows = reserve_rows;
  if (total) {
    a->cols = (uint32_t)lrintf(sqrtf((float)total) + 0.5f);
    a->rows = a->cols - 1;
    while (a->rows * a->cols < total)
      a->rows++;
  }
  a->align = 1u << mip_levels(size);
  const uint32_t nc = a->cols ? a->cols : 1, nr = a->rows ? a->rows : 1;
  a->col_start = calloc(nc, sizeof *a->col_start);
  a->col_width = calloc(nc, sizeof *a->col_width);
  a->row_start = calloc(nr, sizeof *a->row_start);
  a->row_height = calloc(nr, sizeof *a->row_height);
  a->free = malloc(sizeof *a->free * (nr + 1));
  if (!a->col_start || !a->col_width || !a->row_start || !a->row_height || !a->free)
    return 0;
  edges(a->cols, size, a->align, a->col_start, a->col_width);
  edges(a->rows, size, a->align, a->row_start, a->row_height);
  a->cur_x = reserve_cols;
  a->cur_y = 0;
  return 1;
}

static void alloc_free(alloc *a) { free(a->col_start), free(a->col_width), free(a->row_start), free(a->row_height), free(a->free); }

/* CHmsPackLightMapAlloc::ComputeUv01ToLM */
static void uv_to_lightmap(const alloc *a, tmuf_lightmap_corpus *c) {
  const uint32_t nx = c->whole ? a->reserve_cols : c->cells, ny = c->whole ? a->reserve_rows : 1;
  int32_t w = 0, h = 0;
  for (uint32_t i = 0; i < nx && c->column + i < a->cols; i++)
    w += (int32_t)a->col_width[c->column + i];
  for (uint32_t i = 0; i < ny && c->row + i < a->rows; i++)
    h += (int32_t)a->row_height[c->row + i];
  const float size = (float)a->size;
  c->scale[0] = (float)(w - 2 * LM_PADDING) / size;
  c->scale[1] = (float)(h - 2 * LM_PADDING) / size;
  if (!c->whole)
    c->scale[0] = c->scale[0] / (float)nx;
  c->offset[0] = (float)((int32_t)a->col_start[c->column] + LM_PADDING) / size;
  c->offset[1] = (float)((int32_t)a->row_start[c->row] + LM_PADDING) / size;
}

/* CHmsPackLightMapAlloc::AddFreeBlock */
static void add_free_block(alloc *a, uint32_t x, uint32_t y, uint32_t len) {
  for (uint32_t i = 0; i < a->free_count; i++) {
    free_block *f = &a->free[i];
    if (f->y != y)
      continue;
    if (f->x == x + len) {
      f->x -= len;
      f->len += len;
      return;
    }
    if (f->x + f->len == x) {
      f->len += len;
      return;
    }
  }
  a->free[a->free_count++] = (free_block){x, y, len};
}

/* CHmsPackLightMapAlloc::AllocBlock */
static int alloc_block(alloc *a, tmuf_lightmap_corpus *c) {
  if (c->whole) {
    c->column = c->row = 0;
    uv_to_lightmap(a, c);
    return 1;
  }
  const uint32_t n = c->cells;
  uint32_t best = UINT32_MAX, best_len = UINT32_MAX;
  for (uint32_t i = 0; i < a->free_count; i++)
    if (n <= a->free[i].len && a->free[i].len < best_len) {
      best = i;
      best_len = a->free[i].len;
    }
  if (best != UINT32_MAX) {
    free_block *f = &a->free[best];
    c->column = f->x;
    c->row = f->y;
    f->x += n;
    f->len -= n;
    if (!f->len)
      a->free[best] = a->free[--a->free_count];
    uv_to_lightmap(a, c);
    return 1;
  }
  uint32_t x = a->cur_x, y = a->cur_y;
  if (x + n > a->cols) {
    if (LM_FREE_BLOCKS)
      add_free_block(a, x, y, a->cols - x);
    y++;
    x = y < a->reserve_rows ? a->reserve_cols : 0;
  }
  if (y >= a->rows)
    return 0;
  c->column = x;
  c->row = y;
  uv_to_lightmap(a, c);
  x += n;
  if (x >= a->cols) {
    y++;
    x = y < a->reserve_rows ? a->reserve_cols : 0;
  }
  a->cur_x = x;
  a->cur_y = y;
  return 1;
}

/* CHmsPackLightMap::UpdateMapping */
static int place(tmuf_lightmap_corpus *corpora, uint32_t n, uint32_t size, uint32_t *cols, uint32_t *rows) {
  *cols = *rows = 0;
  for (uint32_t i = 0; i < n; i++) {
    corpora[i].column = corpora[i].row = UINT32_MAX;
    corpora[i].scale[0] = corpora[i].scale[1] = corpora[i].offset[0] = corpora[i].offset[1] = 0.0f;
  }
  if (!n)
    return 1;
  radix r = {n, malloc(sizeof(uint32_t) * n), malloc(sizeof(uint32_t) * n), 0};
  float *keys = malloc(sizeof *keys * n);
  alloc a;
  memset(&a, 0, sizeof a);
  int ok = r.ranks && r.ranks2 && keys;
  uint32_t total = 0, whole = 0;
  for (uint32_t i = 0; ok && i < n; i++) {
    total += corpora[i].cells;
    whole += corpora[i].whole != 0;
  }
  /* keys: the half extents x, y, z, then the centre x, y, z */
  static const int key_of_pass[6] = {3, 4, 5, 0, 1, 2};
  for (int pass = 0; ok && pass < 6; pass++) {
    for (uint32_t i = 0; i < n; i++)
      keys[i] = corpora[i].box[key_of_pass[pass]];
    radix_sort(&r, keys, n);
  }
  if (ok)
    ok = alloc_reset(&a, total, size, whole == 1 ? LM_WARP_COLUMNS : 0, whole == 1 ? LM_WARP_ROWS : 0);
  if (ok) {
    for (uint32_t i = 0; i < n; i++)
      if (!alloc_block(&a, &corpora[r.ranks[i]]))
        break;
    *cols = a.cols;
    *rows = a.rows;
  }
  alloc_free(&a);
  free(r.ranks), free(r.ranks2), free(keys);
  return ok;
}

void tmuf_lightmap_place(const tmuf_lightmap *lightmap, uint32_t size, tmuf_lightmap_corpus *corpora, tmuf_lightmap *out) {
  memmove(corpora, lightmap->corpora, sizeof *corpora * lightmap->corpus_count);
  out->size = size;
  out->corpus_count = lightmap->corpus_count;
  out->corpora = corpora;
  place(corpora, out->corpus_count, size, &out->columns, &out->rows);
}

/* ---- the scene's lightmapped corpora ---- */

int tmuf_lightmap_build(tmuf_lightmap_data *out, tmuf_scene *s, uint32_t size) {
  memset(out, 0, sizeof *out);
  out->scene_corpus_count = s->corpus_count;
  out->of_scene_corpus = malloc(sizeof *out->of_scene_corpus * (s->corpus_count ? s->corpus_count : 1));
  out->corpora = malloc(sizeof *out->corpora * (s->corpus_count ? s->corpus_count : 1));
  if (!out->of_scene_corpus || !out->corpora) {
    tmuf_lightmap_free(out);
    return 0;
  }
  uint32_t n = 0;
  for (uint32_t i = 0; i < s->corpus_count; i++) {
    const tmuf_scene_corpus *sc = &s->corpora[i];
    out->of_scene_corpus[i] = UINT32_MAX;
    if (!sc->lightmap_cells || !tree_prelight(s, sc->owner, sc->tree, 0))
      continue;
    tmuf_lightmap_corpus *c = &out->corpora[n];
    memset(c, 0, sizeof *c);
    c->block = sc->tag;
    c->whole = sc->lightmap_cells == 1 && sc->warp;
    c->cells = c->whole ? LM_WARP_COLUMNS * LM_WARP_ROWS : sc->lightmap_cells;
    for (int r = 0; r < 3; r++)
      for (int k = 0; k < 3; k++)
        c->location.r.m[r][k] = sc->iso.m[r][k];
    c->location.t = (tmuf_vec3){sc->iso.t[0], sc->iso.t[1], sc->iso.t[2]};
    tree_box(s, sc->owner, sc->tree, c->tree_box, 0);
    box_mult(c->box, c->tree_box, &sc->iso);
    out->of_scene_corpus[i] = n++;
  }
  out->view.size = size;
  out->view.corpus_count = n;
  out->view.corpora = out->corpora;
  if (!place(out->corpora, n, size, &out->view.columns, &out->view.rows)) {
    tmuf_lightmap_free(out);
    return 0;
  }
  return 1;
}

void tmuf_lightmap_free(tmuf_lightmap_data *lm) {
  free(lm->corpora);
  free(lm->of_scene_corpus);
  memset(lm, 0, sizeof *lm);
}
