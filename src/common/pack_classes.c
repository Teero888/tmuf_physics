#include "common/pack_classes.h"

#include <math.h>
#include <string.h>

#include "common/tuning_schema.h"

/* Chunk entries with no payload may also be stored skippable. */
#define NOPAY(id) {(id), TMUF_GBX_MAYBE_SKIP, NULL}
#define READ(id, fn) {(id), TMUF_GBX_MAYBE_SKIP, (fn)}
#define COUNT(a) (sizeof(a) / sizeof((a)[0]))

#define UNUSED(x) (void)(x)

static const void *read_block(tmuf_gbx *g, size_t count, size_t size) {
  if (size && count > (256u << 20) / size) {
    tmuf_gbx_fail(g, "record count %zu", count);
    return NULL;
  }
  size_t bytes = count * size;
  uint8_t *p = tmuf_arena_alloc(g->arena, bytes ? bytes : 1);
  if (!p) {
    tmuf_gbx_fail(g, "out of memory");
    return NULL;
  }
  tmuf_gbx_read(g, p, bytes);
  return p;
}

static void read_floats(tmuf_gbx *g, float *out, int n) {
  for (int i = 0; i < n; i++)
    out[i] = tmuf_gbx_f32(g);
}

static void skip_counted(tmuf_gbx *g, uint32_t size) {
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x1000000u) {
    tmuf_gbx_fail(g, "record count %u", n);
    return;
  }
  tmuf_gbx_skip(g, (size_t)n * size);
}

static void skip_noderef(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_noderef(g);
}

static void skip_id(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_id(g, NULL);
}

#define SKIP_FN(n) \
  static void skip##n(tmuf_gbx *g, void *node, uint32_t id) { \
    UNUSED(node); \
    UNUSED(id); \
    tmuf_gbx_skip(g, n); \
  }
SKIP_FN(4)
SKIP_FN(8)
SKIP_FN(12)
SKIP_FN(16)

SKIP_FN(24)
SKIP_FN(32)
SKIP_FN(80)
SKIP_FN(72)

/* u32 reserved, u32 count, count node references. */
static void skip_noderef_buffer(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_u32(g);
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "node buffer count %u", n);
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++)
    tmuf_gbx_noderef(g);
}

/* ---- CPlugSolid (0x09005000) ---- */

static void solid_mass(tmuf_gbx *g, tmuf_plug_solid *s) {
  s->has_physics = 1;
  s->mass = tmuf_gbx_f32(g);
  read_floats(g, s->center_of_mass, 3);
  read_floats(g, s->inertia, 9);
}

static void c09005006(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_gbx_skip(g, 8); /* legacy linear / angular speed */
  solid_mass(g, node);
}

static void c0900500e(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_solid *s = node;
  solid_mass(g, s);
  s->fluid_friction = tmuf_gbx_f32(g);
  s->response_a = tmuf_gbx_f32(g);
  s->response_b = tmuf_gbx_f32(g);
}

static void c0900500a(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_solid *s = node;
  int use_model = tmuf_gbx_bool(g), has_model = tmuf_gbx_bool(g);
  if (has_model)
    s->model = tmuf_gbx_noderef(g);
  s->use_model = use_model && has_model;
  if (use_model && has_model)
    return;
  uint32_t mode = tmuf_gbx_u32(g);
  int read_primary = tmuf_gbx_bool(g), read_secondary = tmuf_gbx_bool(g);
  if (mode == 3)
    mode = 1;
  if (mode == 0) {
    tmuf_gbx_node *t = tmuf_gbx_noderef(g);
    if (!(!use_model && has_model))
      s->tree = t;
  } else if (mode == 1) {
    int primary_from_model = !use_model && has_model && read_primary;
    if (read_primary)
      s->tree = tmuf_gbx_noderef(g);
    if (primary_from_model)
      s->tree = NULL;
    if (read_secondary) {
      tmuf_gbx_node *t = tmuf_gbx_noderef(g);
      if (!primary_from_model && !s->tree)
        s->tree = t;
    }
  } else if (mode == 2) {
    s->tree = tmuf_gbx_noderef(g);
  } else {
    tmuf_gbx_fail(g, "CPlugSolid tree mode %u", mode);
  }
}

static void c0900500d(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_solid *s = node;
  int use_model = tmuf_gbx_bool(g), has_model = tmuf_gbx_bool(g);
  if (has_model)
    s->model = tmuf_gbx_noderef(g);
  s->use_model = use_model && has_model;
  if (!(use_model && has_model))
    s->tree = tmuf_gbx_noderef(g);
}

static void c09005011(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_solid *s = node;
  int use_model = tmuf_gbx_bool(g), has_model = tmuf_gbx_bool(g);
  if (has_model) {
    if (tmuf_gbx_bool(g))
      s->model = tmuf_gbx_fidref(g);
    else
      s->model = tmuf_gbx_noderef(g);
  }
  s->use_model = use_model && has_model;
  if (!(use_model && has_model))
    s->tree = tmuf_gbx_noderef(g);
}

static void c09005012(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_plug_solid *)node)->lightmap_cells = tmuf_gbx_u8(g);
}

static const tmuf_gbx_chunk SOLID_CHUNKS[] = {
    READ(0x09005000, skip4),        NOPAY(0x09005001),          NOPAY(0x09005002),          NOPAY(0x09005003),
    NOPAY(0x09005004),              NOPAY(0x09005005),          READ(0x09005006, c09005006), READ(0x09005007, skip4),
    NOPAY(0x09005008),              NOPAY(0x09005009),          READ(0x0900500a, c0900500a), READ(0x0900500b, skip32),
    READ(0x0900500c, skip72),       READ(0x0900500d, c0900500d), READ(0x0900500e, c0900500e), READ(0x0900500f, skip8),
    READ(0x09005010, skip_noderef), READ(0x09005011, c09005011), READ(0x09005012, c09005012),
};
static const tmuf_gbx_class SOLID = {0x09005000, "CPlugSolid", sizeof(tmuf_plug_solid), SOLID_CHUNKS,
                                     COUNT(SOLID_CHUNKS), NULL};

/* ---- CPlugTree (0x0904f000) and variants ---- */

static void tree_iso(tmuf_gbx *g, tmuf_plug_tree *t, uint32_t flags) {
  t->flags = flags;
  t->has_iso = (flags & 4) != 0;
  if (t->has_iso)
    read_floats(g, t->iso, 12);
}

static void c0904f006(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_tree *t = node;
  tmuf_gbx_u32(g);
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "tree child count %u", n);
    return;
  }
  t->children = TMUF_ARENA_ARRAY(g->arena, tmuf_gbx_node *, n ? n : 1);
  t->child_count = 0;
  for (uint32_t i = 0; i < n && !g->error; i++) {
    tmuf_gbx_node *c = tmuf_gbx_noderef(g);
    if (c)
      t->children[t->child_count++] = c;
  }
}

static void c0904f00d(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_tree *t = node;
  t->name = tmuf_gbx_id(g, NULL);
  if (tmuf_gbx_noderef(g))
    tmuf_gbx_id(g, NULL);
}

static void c0904f00e(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_tree *t = node;
  t->visual = tmuf_gbx_noderef(g);
  t->shader = tmuf_gbx_noderef(g);
  t->surface = tmuf_gbx_noderef(g);
}

static void c0904f012(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_tree *t = node;
  t->visual = tmuf_gbx_noderef(g);
  t->shader = tmuf_gbx_noderef(g);
  t->surface = tmuf_gbx_noderef(g);
  t->generator = tmuf_gbx_noderef(g);
}

static void c0904f014(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_tree *t = node;
  t->visual = tmuf_gbx_noderef(g);
  t->shader = tmuf_gbx_noderef(g);
  t->material = tmuf_gbx_noderef(g);
  t->surface = tmuf_gbx_noderef(g);
  t->generator = tmuf_gbx_noderef(g);
}

static void c0904f010(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  uint32_t f = tmuf_gbx_u32(g) & 0x1ffffu;
  f = (f & 0xffff9fffu) | 0x2000u | ((((0xffffffffu - (((f | 0x2000u) >> 14) & 1u)) & 1u)) << 14) | 0x8800u;
  tree_iso(g, node, f);
}

static void c0904f018(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  uint32_t f = tmuf_gbx_u32(g);
  tmuf_gbx_skip(g, 4);
  tree_iso(g, node, (f & 0x1ffffu) | 0x2800u);
}

static void c0904f019(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tree_iso(g, node, tmuf_gbx_u32(g) | 0x2800u);
}

static void c0904f01a(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tree_iso(g, node, tmuf_gbx_u32(g) | 0x2000u);
}

static void c09050001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_tree *t = node;
  t->has_iso = tmuf_gbx_bool(g);
  if (t->has_iso)
    read_floats(g, t->iso, 12);
  tmuf_gbx_noderef(g);
  tmuf_gbx_noderef(g);
}

static void c09050002(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_tree *t = node;
  t->has_iso = tmuf_gbx_bool(g);
  if (t->has_iso)
    read_floats(g, t->iso, 12);
}

static void c09050003(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_plug_tree *)node)->surface = tmuf_gbx_noderef(g);
}

static void c0904f011(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_plug_tree *)node)->func = tmuf_gbx_noderef(g);
}

static const tmuf_gbx_chunk TREE_CHUNKS[] = {
    NOPAY(0x0904f000),
    NOPAY(0x0904f001),
    NOPAY(0x0904f002),
    NOPAY(0x0904f003),
    NOPAY(0x0904f004),
    NOPAY(0x0904f005),
    READ(0x0904f006, c0904f006),
    NOPAY(0x0904f007),
    NOPAY(0x0904f008),
    NOPAY(0x0904f009),
    NOPAY(0x0904f00a),
    NOPAY(0x0904f00b),
    NOPAY(0x0904f00c),
    READ(0x0904f00d, c0904f00d),
    READ(0x0904f00e, c0904f00e),
    NOPAY(0x0904f00f),
    READ(0x0904f010, c0904f010),
    READ(0x0904f011, c0904f011),
    READ(0x0904f012, c0904f012),
    NOPAY(0x0904f013),
    READ(0x0904f014, c0904f014),
    NOPAY(0x0904f015),
    READ(0x0904f016, c0904f012),
    NOPAY(0x0904f017),
    READ(0x0904f018, c0904f018),
    READ(0x0904f019, c0904f019),
    READ(0x0904f01a, c0904f01a),
    READ(0x09050000, skip_noderef),
    READ(0x09050001, c09050001),
    READ(0x09050002, c09050002),
    READ(0x09050003, c09050003),
};
static const tmuf_gbx_class TREE = {0x0904f000, "CPlugTree", sizeof(tmuf_plug_tree), TREE_CHUNKS, COUNT(TREE_CHUNKS),
                                    NULL};

static void c09015002(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_tree *t = node;
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "mip child count %u", n);
    return;
  }
  /* the mip levels follow the children the CPlugTree chunks linked */
  tmuf_gbx_node **children = TMUF_ARENA_ARRAY(g->arena, tmuf_gbx_node *, t->child_count + n + 1);
  if (t->child_count)
    memcpy(children, t->children, sizeof *children * t->child_count);
  t->children = children;
  float *distances = TMUF_ARENA_ARRAY(g->arena, float, n ? n : 1);
  float *far_z = TMUF_ARENA_ARRAY(g->arena, float, n ? n : 1);
  uint32_t *level_of = TMUF_ARENA_ARRAY(g->arena, uint32_t, n ? n : 1);
  t->mip_first = t->child_count;
  t->mip_count = 0;
  t->mip_distances = distances;
  t->mip_levels = 0;
  t->mip_far_z = far_z;
  t->mip_level_of = level_of;
  for (uint32_t i = 0; i < n && !g->error; i++) {
    float d;
    read_floats(g, &d, 1);
    tmuf_gbx_node *c = tmuf_gbx_noderef(g);
    far_z[t->mip_levels++] = d;
    if (c) {
      level_of[t->mip_count] = i;
      distances[t->mip_count++] = d;
      t->children[t->child_count++] = c;
    }
  }
}

static const tmuf_gbx_chunk TREE_MIP_CHUNKS[] = {NOPAY(0x09015000), NOPAY(0x09015001), READ(0x09015002, c09015002)};
static const tmuf_gbx_class TREE_MIP = {0x09015000, "CPlugTreeVisualMip", sizeof(tmuf_plug_tree), TREE_MIP_CHUNKS,
                                        COUNT(TREE_MIP_CHUNKS), &TREE};

static void c09062004(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_plug_tree *)node)->light = tmuf_gbx_noderef(g);
}

static const tmuf_gbx_chunk TREE_LIGHT_CHUNKS[] = {NOPAY(0x09062000), NOPAY(0x09062001), NOPAY(0x09062002),
                                                   NOPAY(0x09062003), READ(0x09062004, c09062004)};
static const tmuf_gbx_class TREE_LIGHT = {0x09062000, "CPlugTreeLight", sizeof(tmuf_plug_tree), TREE_LIGHT_CHUNKS,
                                          COUNT(TREE_LIGHT_CHUNKS), &TREE};

/* ---- CPlugVisual family ---- */

static void c09006005(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_visual *v = node;
  const uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "sub-visual count %u", n);
    return;
  }
  uint32_t *s = TMUF_ARENA_ARRAY(g->arena, uint32_t, 3u * (n ? n : 1u));
  if (!s) {
    tmuf_gbx_fail(g, "out of memory");
    return;
  }
  for (uint32_t i = 0; i < 3u * n && !g->error; i++)
    s[i] = tmuf_gbx_u32(g);
  v->sub_visual_count = n;
  v->sub_visuals = s;
}

static void c0900600b(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  skip_counted(g, 32);
}

static void c0900600e(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_visual *v = node;
  v->flags = tmuf_gbx_u32(g);
  v->texcoord_count = tmuf_gbx_u32(g);
  v->vertex_count = tmuf_gbx_u32(g);
  uint32_t stream_refs = tmuf_gbx_u32(g);
  if (v->texcoord_count > TMUF_VISUAL_MAX_TEXCOORDS || v->vertex_count > 0x1000000u || stream_refs != 0) {
    tmuf_gbx_fail(g, "visual header %u texcoords, %u vertices, %u stream refs", v->texcoord_count, v->vertex_count,
                  stream_refs);
    return;
  }
  for (uint32_t i = 0; i < v->texcoord_count && !g->error; i++) {
    uint32_t kind = tmuf_gbx_u32(g) & 0xffu;
    if (kind > 2) {
      tmuf_gbx_fail(g, "texcoord kind %u", kind);
      return;
    }
    v->texcoord_dim[i] = (uint8_t)(2 + kind);
    v->texcoords[i] = read_block(g, v->vertex_count, 4u * v->texcoord_dim[i]);
  }
  if (v->flags & 7u) {
    tmuf_gbx_fail(g, "visual flags %08x", v->flags);
    return;
  }
  read_floats(g, v->bbox, 6);
  skip_counted(g, 0x14); /* bitmap packs */
}

static void c0902c004(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_visual *v = node;
  uint32_t stride = 12;
  if (v->flags & 0x20u)
    stride += 4;
  if (v->flags & 0x40u)
    stride += 4;
  if (g->node_class == 0x09010000u) /* CPlugVisualSprite */
    stride += 8;
  v->vertex_stride = stride;
  v->vertices = read_block(g, v->vertex_count, stride);
  /* tangents, then binormals: one per vertex when present */
  for (int k = 0; k < 2 && !g->error; k++) {
    const uint32_t n = tmuf_gbx_u32(g);
    if (n > 0x1000000u) {
      tmuf_gbx_fail(g, "record count %u", n);
      return;
    }
    const uint32_t *data = read_block(g, n, 4);
    if (n == v->vertex_count && n)
      *(k ? &v->binormals : &v->tangents) = data;
  }
}

static void c0902c002(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_plug_visual *)node)->material = tmuf_gbx_noderef(g);
}

/* CPlugIndexBuffer (0x09057000), archived inline without a node reference. */
typedef struct index_buffer {
  uint32_t count;
  const uint16_t *indices;
} index_buffer;

static void c09057000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  index_buffer *b = node;
  tmuf_gbx_u32(g); /* format */
  b->count = tmuf_gbx_u32(g);
  b->indices = read_block(g, b->count, 2);
}

static const tmuf_gbx_chunk INDEX_BUFFER_CHUNKS[] = {READ(0x09057000, c09057000)};
static const tmuf_gbx_class INDEX_BUFFER = {0x09057000, "CPlugIndexBuffer", sizeof(index_buffer), INDEX_BUFFER_CHUNKS,
                                            1, NULL};

static void c0906a001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_visual *v = node;
  if (!tmuf_gbx_bool(g))
    return;
  index_buffer b = {0, NULL};
  tmuf_gbx_node_body(g, &INDEX_BUFFER, &b);
  v->index_count = b.count;
  v->indices = b.indices;
}

/* CPlugVisualSprite::Chunk */
static void c09010005(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_visual *v = node;
  v->sprite_flags = tmuf_gbx_u32(g);
  read_floats(g, v->sprite_axis, 3);
  read_floats(g, v->sprite_offset, 2);
}

static void c09010006(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_visual *v = node;
  v->sprite_atlas[0] = tmuf_gbx_u16(g);
  v->sprite_atlas[1] = tmuf_gbx_u16(g);
}

static const tmuf_gbx_chunk VISUAL_CHUNKS[] = {
    NOPAY(0x09006000),
    READ(0x09006001, skip_id),
    NOPAY(0x09006002),
    NOPAY(0x09006003),
    READ(0x09006004, skip_noderef),
    READ(0x09006005, c09006005),
    READ(0x09006006, skip4),
    NOPAY(0x09006007),
    NOPAY(0x09006008),
    READ(0x09006009, skip4),
    NOPAY(0x0900600a),
    READ(0x0900600b, c0900600b),
    NOPAY(0x0900600c),
    NOPAY(0x0900600d),
    READ(0x0900600e, c0900600e),
    /* CPlugVisual3D */
    NOPAY(0x0902c000),
    NOPAY(0x0902c001),
    READ(0x0902c002, c0902c002),
    NOPAY(0x0902c003),
    READ(0x0902c004, c0902c004),
    /* CPlugVisualIndexed */
    READ(0x0906a001, c0906a001),
    /* CPlugVisualSprite */
    READ(0x09010005, c09010005),
    READ(0x09010006, c09010006),
};
static const tmuf_gbx_class VISUAL = {0x09006000, "CPlugVisual", sizeof(tmuf_plug_visual), VISUAL_CHUNKS,
                                      COUNT(VISUAL_CHUNKS), NULL};

/* ---- CPlugSurface (0x0900c000) ---- */

static void c0900c000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_surface *s = node;
  s->geom = tmuf_gbx_noderef(g);
  s->material_count = tmuf_gbx_u32(g);
  if (s->material_count > 0x100000u) {
    tmuf_gbx_fail(g, "surface material count %u", s->material_count);
    return;
  }
  s->materials = TMUF_ARENA_ARRAY(g->arena, tmuf_plug_surface_material, s->material_count ? s->material_count : 1);
  for (uint32_t i = 0; i < s->material_count && !g->error; i++) {
    if (tmuf_gbx_bool(g))
      s->materials[i].ref = tmuf_gbx_noderef(g);
    else
      s->materials[i].id = tmuf_gbx_u16(g);
  }
}

static const tmuf_gbx_chunk SURFACE_CHUNKS[] = {READ(0x0900c000, c0900c000)};
static const tmuf_gbx_class SURFACE = {0x0900c000, "CPlugSurface", sizeof(tmuf_plug_surface), SURFACE_CHUNKS, 1, NULL};

/* ---- CPlugSurfaceGeom (0x0900f000) ---- */

static void c0900f003(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_id(g, NULL);
  tmuf_gbx_skip(g, 24);
}

static void c0900f004(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_surface_geom *s = node;
  tmuf_gbx_id(g, NULL);
  read_floats(g, s->bbox, 6);
  /* The game mixes the box's minimum x into the stream feedback. */
  float min_x = s->bbox[0] - s->bbox[3];
  uint32_t bits;
  memcpy(&bits, &min_x, 4);
  tmuf_gbx_mix_u32(g, bits);
  s->type = tmuf_gbx_u32(g);
  switch (s->type) {
  case TMUF_SURF_SPHERE:
    read_floats(g, s->params, 1);
    break;
  case TMUF_SURF_ELLIPSOID:
    read_floats(g, s->params, 3);
    break;
  case TMUF_SURF_BOX:
    read_floats(g, s->params, 6);
    break;
  case TMUF_SURF_MESH:
    if (tmuf_gbx_u32(g) != 3) {
      tmuf_gbx_fail(g, "mesh vertex buffer version");
      return;
    }
    s->vertex_count = tmuf_gbx_u32(g);
    s->vertices = read_block(g, s->vertex_count, 12);
    s->triangle_count = tmuf_gbx_u32(g);
    s->triangles = read_block(g, s->triangle_count, 32);
    if (tmuf_gbx_u32(g) != 3) {
      tmuf_gbx_fail(g, "mesh octree version");
      return;
    }
    s->cell_count = tmuf_gbx_u32(g);
    s->cells = read_block(g, s->cell_count, 32);
    break;
  default:
    tmuf_gbx_fail(g, "surface type %u", s->type);
    return;
  }
  s->material_id = tmuf_gbx_u16(g);
}

static const tmuf_gbx_chunk SURFACE_GEOM_CHUNKS[] = {
    NOPAY(0x0900f000), READ(0x0900c000, skip_id), READ(0x0900c001, skip4), READ(0x0900f003, c0900f003),
    READ(0x0900f004, c0900f004),
};
static const tmuf_gbx_class SURFACE_GEOM = {0x0900f000, "CPlugSurfaceGeom", sizeof(tmuf_plug_surface_geom),
                                            SURFACE_GEOM_CHUNKS, COUNT(SURFACE_GEOM_CHUNKS), NULL};

/* ---- GxLight family ---- */

/* GxLight::Chunk 0x04001009 */
static void c04001009(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_gx_light *l = node;
  read_floats(g, l->rgb, 3);
  l->flags = tmuf_gbx_u32(g);
  l->intensity = tmuf_gbx_f32(g);
  l->diffuse = tmuf_gbx_f32(g);
  l->specular = tmuf_gbx_f32(g);
  l->specular_power = tmuf_gbx_f32(g);
  l->f38 = tmuf_gbx_f32(g);
  l->flare_intensity = tmuf_gbx_f32(g);
  read_floats(g, l->shadow_rgb, 3);
  l->chunks |= 1u;
}

/* GxLightPoint::Chunk 0x04003004 */
static void c04003004(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_gx_light *l = node;
  read_floats(g, l->point, 2);
  l->chunks |= 2u;
}

/* GxLightBall::Chunk 0x04002004..6: flags, radii +0x68, +0x6c, +0x70 (and
   +0x74 from 5 on), then +0x80, +0x78, +0x7c, +0x84, +0x88, +0x8c */
static void gx_light_ball(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_gx_light *l = node;
  l->ball_flags = tmuf_gbx_u32(g);
  read_floats(g, l->radius, id == 0x04002004u ? 3 : 4);
  read_floats(g, l->ball, 6);
  l->chunks |= 4u;
}

/* GxLightSpot::Chunk: 0x0400b000 inner, outer, falloff; 0x0400b001 inner,
   outer, +0x9c, falloff; 0x0400b002 flags, inner, outer, +0x9c, +0xa0,
   +0xa4, falloff */
static void gx_light_spot(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_gx_light *l = node;
  if (id == 0x0400b002u) {
    l->spot_flags = tmuf_gbx_u32(g);
    read_floats(g, l->spot, 6);
    l->chunks |= 8u;
    return;
  }
  l->spot[0] = tmuf_gbx_f32(g);
  l->spot[1] = tmuf_gbx_f32(g);
  l->spot[2] = id == 0x0400b001u ? tmuf_gbx_f32(g) : 2.0f * l->spot[1];
  l->spot[5] = tmuf_gbx_f32(g);
  /* 0x0400b001: the flare angle is its own (flag 1) unless equal to the outer */
  if (id == 0x0400b001u && fabsf(l->spot[2] - l->spot[1]) > 1e-4f)
    l->spot_flags |= 1u;
  l->chunks |= 16u;
}

/* GxLightFrustum::Chunk 0x0400a006: the GmFrustum (flag, x min, y min,
   near, x max, y max, far), then a word */
static void c0400a006(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_gx_light *l = node;
  l->frustum_flag = tmuf_gbx_u32(g);
  read_floats(g, l->frustum, 6);
  tmuf_gbx_u32(g);
  l->chunks |= 1u << 6;
}

/* GxLightAmbient::Chunk 0x04005000: HeightMin, HeightMax */
static void c04005000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_gx_light *l = node;
  read_floats(g, l->ambient_height, 2);
  l->chunks |= 32u;
}

static const tmuf_gbx_chunk LIGHT_CHUNKS[] = {
    NOPAY(0x04001000), NOPAY(0x04001001), NOPAY(0x04001002), NOPAY(0x04001003), NOPAY(0x04001004), NOPAY(0x04001005),
    NOPAY(0x04001006), NOPAY(0x04001007), NOPAY(0x04001008), READ(0x04001009, c04001009),
    /* GxLightPoint, GxLightBall, GxLightSpot (the versions the packs use) */
    READ(0x04003004, c04003004), READ(0x04002004, gx_light_ball), READ(0x04002005, gx_light_ball),
    READ(0x04002006, gx_light_ball), READ(0x0400b000, gx_light_spot), READ(0x0400b001, gx_light_spot),
    READ(0x0400b002, gx_light_spot),
    /* GxLightAmbient */
    READ(0x04005000, c04005000),
    /* GxLightFrustum */
    READ(0x0400a006, c0400a006),
    /* GxLightDirectional */
    READ(0x04007000, skip12), READ(0x04007001, skip16), READ(0x04007002, skip24), READ(0x04007003, skip12),
    READ(0x04007004, skip16), READ(0x04007005, skip8),
};
static const tmuf_gbx_class LIGHT = {0x04001000, "GxLight", sizeof(tmuf_gx_light), LIGHT_CHUNKS, COUNT(LIGHT_CHUNKS),
                                     NULL};

/* CPlugLight (0x0901d000): 0x0901d000 the light and three more references;
   0x0901d001/2 the same then a flag word */
static void plug_light(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_plug_light *l = node;
  l->light = tmuf_gbx_noderef(g);
  l->func = tmuf_gbx_noderef(g);
  l->flare = tmuf_gbx_noderef(g);
  l->projector = tmuf_gbx_noderef(g);
  if (id != 0x0901d000u)
    l->flags = tmuf_gbx_u32(g);
}

static const tmuf_gbx_chunk PLUG_LIGHT_CHUNKS[] = {READ(0x0901d000, plug_light), READ(0x0901d001, plug_light),
                                                   READ(0x0901d002, plug_light)};
static const tmuf_gbx_class PLUG_LIGHT = {0x0901d000, "CPlugLight", sizeof(tmuf_plug_light), PLUG_LIGHT_CHUNKS,
                                          COUNT(PLUG_LIGHT_CHUNKS), NULL};

/* ---- CPlugDecoratorSolid (0x090a3000), CPlugDecoratorTree (0x090a2000) ---- */

static const char *id_text(tmuf_gbx *g);
static void read_node_list(tmuf_gbx *g, tmuf_node_list *l);

static void c090a3000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_gbx_u32(g); /* version */
  read_node_list(g, &((tmuf_decorator_solid *)node)->trees);
}

/* Each chunk of a decorator tree is a complete declaration of one of its
   archived versions (the chunk id selects the layout). */
static void decorator_tree(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_decorator_tree *d = node;
  d->show = d->visible = d->caster = 6u;
  d->collision = 0u;
  if (id == 0x090a2001u) {
    tmuf_gbx_bool(g);
    tmuf_gbx_bool(g);
    return;
  }
  d->tree_id = id_text(g);
  if (id == 0x090a2004u || id == 0x090a2005u)
    tmuf_gbx_u32(g);
  tmuf_gbx_noderef(g); /* material */
  tmuf_gbx_noderef(g); /* visual (root: node pointer) */
  if (id <= 0x090a2005u) {
    tmuf_gbx_bool(g);
    tmuf_gbx_bool(g); /* surface from visual */
    return;
  }
  d->show = tmuf_gbx_u32(g);
  d->visible = tmuf_gbx_u32(g);
  tmuf_gbx_bool(g); /* visible to children */
  d->caster = tmuf_gbx_u32(g);
  tmuf_gbx_bool(g); /* caster to children */
  tmuf_gbx_bool(g); /* surface from visual */
  if (id >= 0x090a2008u)
    tmuf_gbx_bool(g); /* nearly-equal-identity gate */
  if (id == 0x090a2009u)
    d->collision = tmuf_gbx_u32(g);
}

static const tmuf_gbx_chunk DECORATOR_SOLID_CHUNKS[] = {READ(0x090a3000, c090a3000)};
static const tmuf_gbx_class DECORATOR_SOLID = {0x090a3000, "CPlugDecoratorSolid", sizeof(tmuf_decorator_solid),
                                               DECORATOR_SOLID_CHUNKS, 1, NULL};
static const tmuf_gbx_chunk DECORATOR_TREE_CHUNKS[] = {
    READ(0x090a2000, decorator_tree), READ(0x090a2001, decorator_tree), READ(0x090a2002, decorator_tree),
    READ(0x090a2003, decorator_tree), READ(0x090a2004, decorator_tree), READ(0x090a2005, decorator_tree),
    READ(0x090a2006, decorator_tree), READ(0x090a2007, decorator_tree), READ(0x090a2008, decorator_tree),
    READ(0x090a2009, decorator_tree),
};
static const tmuf_gbx_class DECORATOR_TREE = {0x090a2000, "CPlugDecoratorTree", sizeof(tmuf_decorator_tree),
                                              DECORATOR_TREE_CHUNKS, COUNT(DECORATOR_TREE_CHUNKS), NULL};


/* ---- CPlugMaterial (0x09079000) ---- */

static void material_ref(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_gbx_node *n = tmuf_gbx_noderef(g);
  if (id == 0x09079007)
    ((tmuf_plug_material *)node)->custom = n;
}

static void material_device_sets(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_plug_material *m = node;
  tmuf_gbx_node *model = tmuf_gbx_noderef(g);
  if (model) {
    m->model = model;
    return;
  }
  int shader_refs = id == 0x09079009 || id == 0x0907900c || id == 0x0907900d;
  int formats = id == 0x0907900c || id == 0x0907900d;
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "device set count %u", n);
    return;
  }
  m->device_count = n;
  m->device_words = TMUF_ARENA_ARRAY(g->arena, uint32_t, n ? n : 1);
  m->device_shaders = TMUF_ARENA_ARRAY(g->arena, tmuf_gbx_node *, n ? n : 1);
  m->device_day = TMUF_ARENA_ARRAY(g->arena, tmuf_gbx_node *, n ? n : 1);
  m->device_night = TMUF_ARENA_ARRAY(g->arena, tmuf_gbx_node *, n ? n : 1);
  for (uint32_t i = 0; i < n && !g->error; i++) {
    /* UPlugRenderDevice::Archive: u16 device, u8 sub-device, u8 quality;
       compared as quality | sub << 8 | device << 16 */
    uint32_t a = tmuf_gbx_u32(g);
    m->device_words[i] = ((a & 0xffffu) << 16) | ((a & 0xff0000u) >> 8) | ((a & 0xff000000u) >> 24);
    const int is_fid = tmuf_gbx_bool(g);
    m->device_shaders[i] = is_fid ? tmuf_gbx_fidref(g) : tmuf_gbx_noderef(g);
    m->device_day[i] = m->device_night[i] = m->device_shaders[i];
    if (shader_refs) {
      /* Archive_DeviceMat: the day (+0x04) and night (+0x08) fids; an
         inline shader is the same by day and by night */
      tmuf_gbx_node *day = tmuf_gbx_fidref(g);
      tmuf_gbx_node *night = tmuf_gbx_fidref(g);
      if (is_fid) {
        m->device_day[i] = day;
        m->device_night[i] = night;
      }
    }
  }
  if (formats)
    skip_counted(g, 4);
}

static void material_surface(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_plug_material *m = node;
  uint32_t f = tmuf_gbx_u32(g);
  if (id == 0x09079002)
    f = (f & 0x7e1fffffu) | 0x80000000u;
  else if (id == 0x0907900a)
    f |= 0x80000000u;
  m->has_surface = 1;
  m->surface_flags = f;
  m->surface_id = (uint8_t)(f & 0xffu);
}

static const tmuf_gbx_chunk MATERIAL_CHUNKS[] = {
    NOPAY(0x09079000),
    READ(0x09079001, material_ref),
    {0x09079002, TMUF_GBX_MAYBE_SKIP, material_surface},
    NOPAY(0x09079003),
    NOPAY(0x09079004),
    NOPAY(0x09079005),
    NOPAY(0x09079006),
    READ(0x09079007, material_ref),
    {0x09079008, TMUF_GBX_MAYBE_SKIP, material_device_sets},
    {0x09079009, TMUF_GBX_MAYBE_SKIP, material_device_sets},
    {0x0907900a, TMUF_GBX_MAYBE_SKIP, material_surface},
    READ(0x0907900b, material_ref),
    {0x0907900c, TMUF_GBX_MAYBE_SKIP, material_device_sets},
    READ(0x0907900d, material_device_sets),
    READ(0x0907900e, material_surface),
    READ(0x0907900f, skip4),
};
static const tmuf_gbx_class MATERIAL = {0x09079000, "CPlugMaterial", sizeof(tmuf_plug_material), MATERIAL_CHUNKS,
                                        COUNT(MATERIAL_CHUNKS), NULL};

/* ---- CPlugMaterialCustom (0x0903a000) ---- */

static void custom_int_array(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  skip_counted(g, 4);
}

static void custom_bitmaps(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_material_custom *m = node;
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "custom bitmap count %u", n);
    return;
  }
  m->bitmap_count = n;
  m->bitmap_names = TMUF_ARENA_ARRAY(g->arena, const char *, n ? n : 1);
  m->bitmaps = TMUF_ARENA_ARRAY(g->arena, tmuf_gbx_node *, n ? n : 1);
  for (uint32_t i = 0; i < n && !g->error; i++) {
    m->bitmap_names[i] = tmuf_gbx_id(g, NULL);
    tmuf_gbx_skip(g, 4);
    m->bitmaps[i] = tmuf_gbx_noderef(g);
  }
}

static void custom_gpu_fx_array(tmuf_gbx *g) {
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "gpu fx count %u", n);
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++) {
    tmuf_gbx_id(g, NULL);
    uint32_t components = tmuf_gbx_u32(g), registers = tmuf_gbx_u32(g);
    tmuf_gbx_bool(g);
    if (components > 0x100000u || registers > 0x100000u) {
      tmuf_gbx_fail(g, "gpu fx size");
      return;
    }
    tmuf_gbx_skip(g, (size_t)components * registers * 4);
  }
}

static void custom_gpu_fx(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  custom_gpu_fx_array(g);
  custom_gpu_fx_array(g);
}

static void custom_bitmap_skip(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "custom bitmap skip count %u", n);
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++) {
    tmuf_gbx_id(g, NULL);
    tmuf_gbx_bool(g);
  }
}

static void custom_flags(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  uint32_t f = tmuf_gbx_u32(g);
  tmuf_gbx_skip(g, 12);
  if (f & 1)
    tmuf_gbx_skip(g, 4);
}

static const tmuf_gbx_chunk MATERIAL_CUSTOM_CHUNKS[] = {
    READ(0x0903a004, custom_int_array), READ(0x0903a006, custom_bitmaps), READ(0x0903a00a, custom_gpu_fx),
    READ(0x0903a00c, custom_bitmap_skip), READ(0x0903a00d, custom_flags), {0x0903a00f, 1, NULL}, {0x0903a011, 1, NULL},
};
static const tmuf_gbx_class MATERIAL_CUSTOM = {0x0903a000, "CPlugMaterialCustom", sizeof(tmuf_plug_material_custom),
                                               MATERIAL_CUSTOM_CHUNKS,
                                               COUNT(MATERIAL_CUSTOM_CHUNKS), NULL};

/* ---- CPlugShader family (0x09002000: Generic, Apply) ---- */

static void noderef_array(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "node array count %u", n);
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++)
    tmuf_gbx_noderef(g);
}

/* CPlugShader::Chunk 0x0900200e: the func shader (+0x34), the passes
   (+0x2c), then more references */
static void c0900200e(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_plug_shader *s = node;
  s->func = tmuf_gbx_noderef(g);
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x10000u) {
    tmuf_gbx_fail(g, "shader pass count %u", n);
    return;
  }
  s->pass_count = n;
  s->passes = TMUF_ARENA_ARRAY(g->arena, tmuf_gbx_node *, n ? n : 1);
  for (uint32_t i = 0; i < n && !g->error; i++)
    s->passes[i] = tmuf_gbx_noderef(g);
  tmuf_gbx_noderef(g);
  noderef_array(g, node, id);
}

static void c09002016(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_shader *s = node;
  s->flags[0] = tmuf_gbx_u32(g);
  s->flags[1] = tmuf_gbx_u32(g);
  s->has_flags = 1;
  tmuf_gbx_skip(g, 4);
  tmuf_gbx_noderef(g);
  s->visible_id = tmuf_gbx_u16(g);
}

/* CPlugShaderApply: its bitmap addresses */
static void c09026002(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_shader *s = node;
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "node array count %u", n);
    return;
  }
  s->address_count = n;
  s->addresses = TMUF_ARENA_ARRAY(g->arena, tmuf_gbx_node *, n ? n : 1);
  for (uint32_t i = 0; i < n && !g->error; i++)
    s->addresses[i] = tmuf_gbx_noderef(g);
}

/* CPlugShaderApply::Chunk 0x09026004: the old render state word,
   converted as ApplyFieldLoadAndSetFromOld does (bit 0x2000: alpha test,
   function 3, else none, 6) */
static void c09026004(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_shader *s = node;
  const uint32_t old = tmuf_gbx_u32(g);
  const uint32_t func = (old & 0x2000u) ? 3u : 6u;
  s->apply_state[0] = ((old & 0xf8ffdfffu) | func << 24) & 0x1f3fffffu;
  s->apply_state[1] = 0;
  s->has_apply_state = 1;
}

/* CPlugShaderApply::Chunk 0x09026008: the render state words */
static void c09026008(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_shader *s = node;
  s->apply_state[0] = tmuf_gbx_u32(g) & 0x1fffffffu;
  s->apply_state[1] = tmuf_gbx_u32(g) & 0x7fffffu;
  s->has_apply_state = 1;
}

/* CPlugShaderGeneric::Chunk 0x09004001..3: its 0x58-byte block (+0x38),
   whose last word is its flags +0x8c (masked as the game does) */
static void c09004003(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_plug_shader *s = node;
  uint8_t block[0x58];
  tmuf_gbx_read(g, block, sizeof block);
  uint32_t f = (uint32_t)block[0x54] | (uint32_t)block[0x55] << 8 | (uint32_t)block[0x56] << 16 | (uint32_t)block[0x57] << 24;
  f &= 0x7ffu;
  if (id == 0x09004001u)
    f = (f & 0x4ffu) | 0x200u;
  else if (id == 0x09004002u)
    f = (f & 0x5ffu) | 0x200u;
  s->generic_flags = f;
  s->has_generic = 1;
}

static const tmuf_gbx_chunk SHADER_CHUNKS[] = {
    READ(0x0900200e, c0900200e), READ(0x09002016, c09002016), READ(0x09004001, c09004003),
    READ(0x09004002, c09004003), READ(0x09004003, c09004003),
    READ(0x09026002, c09026002), READ(0x09026004, c09026004), READ(0x09026008, c09026008),
};
static const tmuf_gbx_class SHADER = {0x09002000, "CPlugShader", sizeof(tmuf_plug_shader), SHADER_CHUNKS,
                                      COUNT(SHADER_CHUNKS), NULL};

/* ---- CPlugShaderPass (0x09067000) ---- */

/* a GPU program: enabled, its file, then (enabled) the constants it
   loads: their names (each with 4 words), then their values (float4) */
static void gpu_pipeline(tmuf_gbx *g, tmuf_plug_gpu_program *p) {
  p->enabled = tmuf_gbx_bool(g);
  p->file = tmuf_gbx_noderef(g);
  if (!p->enabled)
    return;
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "gpu load fx count %u", n);
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++) {
    const char *name = tmuf_gbx_id(g, NULL);
    if (i < TMUF_PASS_MAX_CONSTANTS)
      p->constant_names[i] = name ? name : "";
    tmuf_gbx_skip(g, 16);
  }
  uint32_t m = tmuf_gbx_u32(g);
  if (m > 0x100000u) {
    tmuf_gbx_fail(g, "gpu load fx value count %u", m);
    return;
  }
  for (uint32_t i = 0; i < m && !g->error; i++) {
    float v[4];
    read_floats(g, v, 4);
    if (i < TMUF_PASS_MAX_CONSTANTS)
      memcpy(p->constants[i], v, sizeof v);
  }
  n = n < m ? n : m;
  p->constant_count = n < TMUF_PASS_MAX_CONSTANTS ? n : TMUF_PASS_MAX_CONSTANTS;
}

static void c0906700a(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_shader_pass *pass = node;
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "pipeline id count %u", n);
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++)
    tmuf_gbx_id(g, NULL);
  gpu_pipeline(g, &pass->programs[0]);
  gpu_pipeline(g, &pass->programs[1]);
}

static const tmuf_gbx_chunk SHADER_PASS_CHUNKS[] = {
    READ(0x09067006, noderef_array), READ(0x09067007, skip4), READ(0x0906700a, c0906700a),
};
static const tmuf_gbx_class SHADER_PASS = {0x09067000, "CPlugShaderPass", sizeof(tmuf_plug_shader_pass),
                                           SHADER_PASS_CHUNKS, COUNT(SHADER_PASS_CHUNKS), NULL};

/* ---- CPlugBitmapSampler family (0x0907e000: Address, Apply) ---- */

static void c0907e008(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_bitmap_address *a = node;
  a->sampler = tmuf_gbx_id(g, NULL);
  a->bitmap = tmuf_gbx_noderef(g);
  tmuf_gbx_skip(g, 8);
}

static void c09047007(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_bitmap_address *a = node;
  a->address_flags = tmuf_gbx_u32(g);
  a->has_address = 1;
  tmuf_gbx_noderef(g);
  /* CPlugBitmapAddress::Chunk 0x09047007: bit 0 a GmIso3 (2x3), bit 1 a
     GmMat4 texcoord transform, archived in that order */
  uint8_t has_transform = tmuf_gbx_u8(g);
  if (has_transform > 3) {
    tmuf_gbx_fail(g, "bitmap address transform flag %u", has_transform);
    return;
  }
  a->has_transform = has_transform & 1;
  for (int i = 0; i < 6 && a->has_transform; i++)
    a->transform[i] = tmuf_gbx_f32(g);
  a->has_matrix = (has_transform >> 1) & 1;
  for (int i = 0; i < 16 && a->has_matrix; i++)
    a->matrix[i] = tmuf_gbx_f32(g);
}

static const tmuf_gbx_chunk BITMAP_SAMPLER_CHUNKS[] = {
    READ(0x0907e008, c0907e008), READ(0x09047007, c09047007), READ(0x09047009, skip4), READ(0x09012004, skip4),
};
static const tmuf_gbx_class BITMAP_SAMPLER = {0x0907e000, "CPlugBitmapSampler", sizeof(tmuf_plug_bitmap_address),
                                              BITMAP_SAMPLER_CHUNKS, COUNT(BITMAP_SAMPLER_CHUNKS), NULL};

/* ---- CPlugBitmap (0x09011000) and the renders it can be updated by ---- */

static void skip_n(tmuf_gbx *g, uint32_t id) {
  static const struct {
    uint32_t id, n;
  } SIZES[] = {{0x09011019, 4}, {0x0901101b, 4}, {0x0901101f, 4}, {0x09011021, 4}, {0x09011023, 4},
               {0x09011024, 4}, {0x0901102e, 4}, {0x0901101c, 20}, {0x0901101d, 4}, {0x09011025, 24},
               {0x09011028, 8}, {0x09086003, 8}, {0x0908600a, 4}, {0x0908600d, 4}, {0x0908600e, 4}};
  for (size_t i = 0; i < COUNT(SIZES); i++)
    if (SIZES[i].id == id) {
      tmuf_gbx_skip(g, SIZES[i].n);
      return;
    }
}

static void bitmap_fixed(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  skip_n(g, id);
}

static void bitmap_tc_transform(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_bitmap *b = node;
  b->tc_scale[0] = tmuf_gbx_f32(g);
  b->tc_scale[1] = tmuf_gbx_f32(g);
  b->tc_offset[0] = tmuf_gbx_f32(g);
  b->tc_offset[1] = tmuf_gbx_f32(g);
  b->tc_rotation = tmuf_gbx_f32(g);
  b->has_tc_transform = !g->error;
}

static void bitmap_flags(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_bitmap *b = node;
  b->flags = tmuf_gbx_u32(g);
  b->has_flags = !g->error;
}

static void bitmap_empty(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(g);
  UNUSED(node);
  UNUSED(id);
}

static void bitmap_vec2_array(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  skip_counted(g, 8);
}

static void bitmap_u32_array(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  skip_counted(g, 4);
}

/* image: the file (inline CPlugFileGen or external), then for 018/022 with
   an inline image the render updating it */
static void bitmap_image(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_plug_bitmap *b = node;
  b->image = tmuf_gbx_noderef(g);
  uint8_t data[8];
  tmuf_gbx_read(g, data, 8);
  b->usage = (uint32_t)data[0] | (uint32_t)data[1] << 8 | (uint32_t)data[2] << 16 | (uint32_t)data[3] << 24;
  b->has_usage = 1;
  tmuf_gbx_skip(g, 16);
  if (id != 0x09011018 && id != 0x09011022)
    return;
  /* CPlugBitmap::ArchivePixelUpdateOld22, by the pixel update mode (the
     second byte of the 8 at +0x4c): 4 the render updating it, 7 specular
     highlights, 8 a natural */
  switch (data[1]) {
  case 4:
    b->render = tmuf_gbx_noderef(g);
    break;
  case 5:
    tmuf_gbx_fail(g, "bitmap pixel update 5");
    break;
  case 7: {
    uint32_t n = tmuf_gbx_u32(g);
    if (n > 0x10000u) {
      tmuf_gbx_fail(g, "bitmap highlights %u", n);
      return;
    }
    tmuf_gbx_skip(g, (size_t)n * 16);
    break;
  }
  case 8:
    tmuf_gbx_skip(g, 4);
    break;
  default:
    break;
  }
}

static const tmuf_gbx_chunk BITMAP_CHUNKS[] = {
    READ(0x09011014, bitmap_image),      READ(0x09011015, bitmap_image),    READ(0x09011018, bitmap_image),
    READ(0x09011019, bitmap_fixed),      READ(0x0901101b, bitmap_fixed),    READ(0x0901101c, bitmap_tc_transform),
    READ(0x0901101d, bitmap_fixed),      READ(0x0901101e, bitmap_vec2_array), READ(0x0901101f, bitmap_fixed),
    READ(0x09011020, bitmap_u32_array),  READ(0x09011021, bitmap_fixed),    READ(0x09011022, bitmap_image),
    READ(0x09011023, bitmap_fixed),      READ(0x09011024, bitmap_flags),    READ(0x09011025, bitmap_fixed),
    READ(0x09011028, bitmap_fixed),      READ(0x0901102e, bitmap_fixed),    READ(0x09011030, bitmap_empty),
};
static const tmuf_gbx_class BITMAP = {0x09011000, "CPlugBitmap", sizeof(tmuf_plug_bitmap), BITMAP_CHUNKS,
                                      COUNT(BITMAP_CHUNKS), NULL};

static void render_clear(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_skip(g, 8);
  tmuf_gbx_noderef(g);
  tmuf_gbx_skip(g, 8);
}

static void render_sub(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_noderef(g);
}

/* CPlugBitmapRender (0x09086000) family; the water render's own state
   chunks (09087005/6) are skippable */
static const tmuf_gbx_chunk BITMAP_RENDER_CHUNKS[] = {
    READ(0x09086003, bitmap_fixed), READ(0x0908600a, bitmap_fixed), READ(0x0908600b, render_clear),
    READ(0x0908600c, render_sub),   READ(0x0908600d, bitmap_fixed), READ(0x0908600e, bitmap_fixed),
};
static const tmuf_gbx_class BITMAP_RENDER = {0x09086000, "CPlugBitmapRender", sizeof(tmuf_plug_bitmap_render),
                                             BITMAP_RENDER_CHUNKS, COUNT(BITMAP_RENDER_CHUNKS), NULL};

/* CPlugBitmapRenderHemisphere::Chunk_Crypted: 0x09058000 layout, ExpL;
   0x09058001 layout, ExpL (+0x5c), ExpA (+0x60), six more reals */
static void render_hemisphere(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_plug_bitmap_render *r = node;
  r->has_hemisphere = 1;
  r->hemi_layout = tmuf_gbx_u32(g);
  r->exp_l = tmuf_gbx_f32(g);
  if (id == 0x09058001u) {
    r->exp_a = tmuf_gbx_f32(g);
    tmuf_gbx_skip(g, 24);
  }
}

static const tmuf_gbx_chunk BITMAP_RENDER_HEMI_CHUNKS[] = {READ(0x09058000, render_hemisphere),
                                                           READ(0x09058001, render_hemisphere)};
static const tmuf_gbx_class BITMAP_RENDER_HEMI = {0x09058000, "CPlugBitmapRenderHemisphere",
                                                  sizeof(tmuf_plug_bitmap_render), BITMAP_RENDER_HEMI_CHUNKS,
                                                  COUNT(BITMAP_RENDER_HEMI_CHUNKS), &BITMAP_RENDER};

/* CPlugBitmapRenderLightFromMap::Chunk: grid (+0x80), max grid (+0x84), then
   +0x88, +0x8c, +0x94, +0x98 and, from 0x09021001, +0x9c, +0xa0, +0xa4, +0xa8 */
static void render_light_from_map(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_plug_bitmap_render *r = node;
  r->has_light_from_map = 1;
  r->lfm_grid = tmuf_gbx_u32(g);
  r->lfm_grid_max = tmuf_gbx_u32(g);
  read_floats(g, r->lfm, id == 0x09021001u ? 8 : 4);
}

static const tmuf_gbx_chunk BITMAP_RENDER_LFM_CHUNKS[] = {READ(0x09021000, render_light_from_map),
                                                          READ(0x09021001, render_light_from_map)};
static const tmuf_gbx_class BITMAP_RENDER_LFM = {0x09021000, "CPlugBitmapRenderLightFromMap",
                                                 sizeof(tmuf_plug_bitmap_render), BITMAP_RENDER_LFM_CHUNKS,
                                                 COUNT(BITMAP_RENDER_LFM_CHUNKS), &BITMAP_RENDER};

/* CPlugFileGen (0x0902f000): archived inline without chunks */
static void file_gen_archive(tmuf_gbx *g, void *node) {
  UNUSED(node);
  uint32_t v = tmuf_gbx_u32(g);
  if (v & 0x80000000u) {
    uint32_t version = v & 0x7fffffffu;
    if (version > 5u) {
      tmuf_gbx_fail(g, "file gen version %u", version);
      return;
    }
    tmuf_gbx_u32(g); /* kind */
    skip_counted(g, 4);
    skip_counted(g, 16);
    skip_counted(g, 4);
    if (version > 2u)
      tmuf_gbx_string(g);
    if (version > 3u) {
      uint32_t n = tmuf_gbx_u32(g);
      if (n > 0x100000u) {
        tmuf_gbx_fail(g, "file gen refs %u", n);
        return;
      }
      for (uint32_t i = 0; i < n && !g->error; i++)
        tmuf_gbx_noderef(g);
    }
  } else {
    if (v > 0x32u) {
      tmuf_gbx_fail(g, "file gen version %u", v);
      return;
    }
    skip_counted(g, 4);
    skip_counted(g, 16);
  }
}

static const tmuf_gbx_class FILE_GEN = {0x0902f000, "CPlugFileGen", 1, NULL, 0, NULL, NULL, NULL, file_gen_archive};

/* ---- shared helpers for node lists ---- */

static void read_node_list(tmuf_gbx *g, tmuf_node_list *l) {
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "node list count %u", n);
    return;
  }
  l->nodes = TMUF_ARENA_ARRAY(g->arena, tmuf_gbx_node *, n ? n : 1);
  l->count = n;
  for (uint32_t i = 0; i < n && !g->error; i++)
    l->nodes[i] = tmuf_gbx_noderef(g);
}

static const char *id_text(tmuf_gbx *g) {
  uint32_t number;
  const char *s = tmuf_gbx_id(g, &number);
  return s ? s : "";
}

/* ---- CGameCtnCollector (0x0301a000) ---- */

static void c0301a009(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_string(g);
  if (tmuf_gbx_bool(g))
    tmuf_gbx_noderef(g);
  tmuf_gbx_id(g, NULL);
}

static void c0301a00b(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_block_info *b = node;
  for (int i = 0; i < 3; i++)
    b->collector_ident[i] = id_text(g);
}

#define COLLECTOR_CHUNKS \
  READ(0x0301a006, skip4), READ(0x0301a007, skip24), READ(0x0301a009, c0301a009), READ(0x0301a00a, skip_id), \
      READ(0x0301a00b, c0301a00b)

/* ---- CGameCtnBlockInfo (0x0304e000) and variants, CGameCtnBlock ---- */

static void block_info_base(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_block_info *b = node;
  b->base_chunk = id;
  b->name = id_text(g);
  tmuf_gbx_read(g, b->base_words, 24);
  b->base_ref = tmuf_gbx_noderef(g);
  read_node_list(g, &b->units[0]);
  read_node_list(g, &b->units[1]);
  for (int k = 0; k < 2 && !g->error; k++) {
    uint32_t n = tmuf_gbx_u32(g);
    if (n > 0x10000u) {
      tmuf_gbx_fail(g, "block variant count %u", n);
      return;
    }
    b->variant_count[k] = n;
    b->variants[k] = TMUF_ARENA_ARRAY(g->arena, tmuf_node_list, n ? n : 1);
    for (uint32_t v = 0; v < n && !g->error; v++)
      read_node_list(g, &b->variants[k][v]);
  }
  if (id == 0x0304e004 || id == 0x0304e005 || id == 0x0304e008)
    tmuf_gbx_read(g, b->extra, 7);
  if (id == 0x0304e005 || id == 0x0304e008)
    tmuf_gbx_read(g, b->extra + 7, 2);
  if (id == 0x0304e008)
    tmuf_gbx_string(g);
}

/* 0x0304e007: one spawn location for both families; 0x0304e00c: ground then
   air. */
static void c0304e007(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_block_info *b = node;
  read_floats(g, b->spawn[0], 12);
  if (id == 0x0304e00cu)
    read_floats(g, b->spawn[1], 12);
  else
    memcpy(b->spawn[1], b->spawn[0], sizeof b->spawn[0]);
  b->has_spawn = 1;
}

/* CGameCtnBlockInfo: respawn at the car's current spawn instead of the
   block's (checkpoints that must not move the respawn point) */
static void c0304e00f(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_block_info *)node)->respawn_current = tmuf_gbx_u32(g) != 0;
}

/* 0x0304e00a/00b/00e: u32, then helper mobils: ground, air(, common). */
static void c0304e00e(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_block_info *b = node;
  b->way_type = tmuf_gbx_u32(g);
  b->has_way_type = 1;
  b->helpers[0] = tmuf_gbx_noderef(g);
  b->helpers[1] = tmuf_gbx_noderef(g);
  if (id != 0x0304e00a)
    b->helpers[2] = tmuf_gbx_noderef(g);
}

static void c03052000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_block_info *)node)->road_ref = tmuf_gbx_noderef(g);
}

static void c03053002(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_block_info *)node)->clip_id = id_text(g);
}

static void c03055000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_block_info *b = node;
  for (int i = 0; i < 3; i++)
    b->pylon_refs[i] = tmuf_gbx_noderef(g);
}


static const tmuf_gbx_chunk BLOCK_INFO_CHUNKS[] = {
    COLLECTOR_CHUNKS,
    READ(0x0304e000, block_info_base),
    READ(0x0304e001, block_info_base),
    NOPAY(0x0304e002),
    NOPAY(0x0304e003),
    READ(0x0304e004, block_info_base),
    READ(0x0304e005, block_info_base),
    NOPAY(0x0304e006),
    READ(0x0304e007, c0304e007),
    READ(0x0304e008, block_info_base),
    READ(0x0304e009, skip4),
    READ(0x0304e00a, c0304e00e),
    READ(0x0304e00b, c0304e00e),
    READ(0x0304e00c, c0304e007),
    READ(0x0304e00d, skip4),
    READ(0x0304e00e, c0304e00e),
    READ(0x0304e00f, c0304e00f),
    READ(0x03052000, c03052000),
    READ(0x03053002, c03053002),
    READ(0x03055000, c03055000),
};
static const tmuf_gbx_class BLOCK_INFO = {0x0304e000, "CGameCtnBlockInfo", sizeof(tmuf_block_info),
                                          BLOCK_INFO_CHUNKS, COUNT(BLOCK_INFO_CHUNKS), NULL};
static const tmuf_gbx_class BLOCK = {0x03057000, "CGameCtnBlock", sizeof(tmuf_block_info), BLOCK_INFO_CHUNKS,
                                     COUNT(BLOCK_INFO_CHUNKS), NULL};

/* ---- CGameCtnBlockUnitInfo (0x03036000) ---- */

static void c03036000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_block_unit *u = node;
  u->junction_mask = tmuf_gbx_u32(g);
  u->helper = tmuf_gbx_u32(g);
  tmuf_gbx_u32(g);
  for (int i = 0; i < 3; i++)
    u->offset[i] = tmuf_gbx_u32(g);
  read_node_list(g, &u->sources);
}

static void c03036001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_block_unit *u = node;
  u->surface = id_text(g);
  tmuf_gbx_read(g, u->surface_extra, 8);
}

static void c03036002(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_block_unit *)node)->underground = tmuf_gbx_u32(g);
}

static void c03036003(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_block_unit *u = node;
  u->replacement = tmuf_gbx_noderef(g);
  u->junction = id_text(g);
  tmuf_gbx_read(g, u->junction_extra, 8);
}

static void c03036004(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_block_unit *)node)->helper_mask = tmuf_gbx_u32(g);
  ((tmuf_block_unit *)node)->has_helper_mask = 1;
}

static void c03036005(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_block_unit *)node)->terrain_modifier = id_text(g);
}

static const tmuf_gbx_chunk BLOCK_UNIT_CHUNKS[] = {
    READ(0x03036000, c03036000), READ(0x03036001, c03036001), READ(0x03036002, c03036002),
    READ(0x03036003, c03036003), READ(0x03036004, c03036004), READ(0x03036005, c03036005),
};
static const tmuf_gbx_class BLOCK_UNIT = {0x03036000, "CGameCtnBlockUnitInfo", sizeof(tmuf_block_unit),
                                          BLOCK_UNIT_CHUNKS, COUNT(BLOCK_UNIT_CHUNKS), NULL};

/* ---- CHmsItem (0x06003000), CHmsLight, CHmsSoundSource: archived inline ---- */

static void c06003001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_hms_item *)node)->solid = tmuf_gbx_noderef(g);
}

static void hms_state(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_hms_item *h = node;
  h->has_state = 1;
  h->physics_flags = tmuf_gbx_u32(g);
  h->rendering_flags = tmuf_gbx_u32(g);
  h->visibility = tmuf_gbx_u16(g);
}

#define SKIPN(name, n) \
  static void name(tmuf_gbx *g, void *node, uint32_t id) { \
    UNUSED(node); \
    UNUSED(id); \
    tmuf_gbx_skip(g, n); \
  }
SKIPN(skip17, 17)
SKIPN(skip20, 20)
SKIPN(skip21, 21)
SKIPN(skip25, 25)

static const tmuf_gbx_chunk HMS_ITEM_CHUNKS[] = {
    READ(0x06003000, skip16),          READ(0x06003001, c06003001), READ(0x06003002, skip_noderef_buffer),
    READ(0x06003003, skip20),          READ(0x06003004, skip17),    READ(0x06003005, skip21),
    READ(0x06003006, skip25),          READ(0x06003007, skip25),    READ(0x06003008, skip12),
    READ(0x06003009, skip4),           READ(0x0600300a, skip8),     READ(0x0600300b, hms_state),
    READ(0x0600300c, hms_state),       READ(0x0600300d, hms_state), READ(0x0600300e, hms_state),
    READ(0x0600300f, hms_state),       READ(0x06003010, hms_state), READ(0x06003011, hms_state),
};
static const tmuf_gbx_class HMS_ITEM = {0x06003000, "CHmsItem", sizeof(tmuf_hms_item), HMS_ITEM_CHUNKS,
                                        COUNT(HMS_ITEM_CHUNKS), NULL};

/* CHmsLight::Chunk: 0x0600c000 flags and the GxLight; each later version
   first archives the one before, then 0x0600c001 +0x70 (a kind 4 light
   only: none of the game's), 0x0600c002 +0x68, 0x0600c003 +0x6c */
static void hms_light(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_hms_light *l = node;
  l->flags = tmuf_gbx_u32(g) & 3u;
  l->light = tmuf_gbx_noderef(g);
  if (id >= 0x0600c002u)
    l->bitmaps[0] = tmuf_gbx_noderef(g);
  if (id >= 0x0600c003u)
    l->bitmaps[1] = tmuf_gbx_noderef(g);
}

static const tmuf_gbx_chunk HMS_LIGHT_CHUNKS[] = {
    READ(0x0600c000, hms_light), READ(0x0600c001, hms_light), READ(0x0600c002, hms_light), READ(0x0600c003, hms_light),
};
static const tmuf_gbx_class HMS_LIGHT = {0x0600c000, "CHmsLight", sizeof(tmuf_hms_light), HMS_LIGHT_CHUNKS,
                                         COUNT(HMS_LIGHT_CHUNKS), NULL};

static void c0600d005(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_noderef(g);
  tmuf_gbx_skip(g, 8);
}

static const tmuf_gbx_chunk HMS_SOUND_CHUNKS[] = {
    NOPAY(0x0600d000),         READ(0x0600d001, skip_noderef), READ(0x0600d002, skip8),
    READ(0x0600d003, skip12), READ(0x0600d004, skip12),       READ(0x0600d005, c0600d005),
    READ(0x0600d006, skip4),
};
static const tmuf_gbx_class HMS_SOUND = {0x0600d000, "CHmsSoundSource", 1, HMS_SOUND_CHUNKS, COUNT(HMS_SOUND_CHUNKS),
                                         NULL};

/* ---- CSceneObject (0x0a005000): CScenePoc, CSceneMobil, ... ---- */

static void c0a005001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_scene_object *)node)->name = id_text(g);
}

static void c0a005003(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_scene_object *)node)->motion = tmuf_gbx_noderef(g);
}

static void c0a011003(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  read_node_list(g, &((tmuf_scene_object *)node)->children);
}

static void c0a011005(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_scene_object *o = node;
  o->has_item = 1;
  tmuf_gbx_node_body(g, &HMS_ITEM, &o->item);
}

static void c0a00b000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_scene_object *o = node;
  o->has_light = 1;
  tmuf_gbx_node_body(g, &HMS_LIGHT, &o->light);
}

static void c0a00e000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  uint8_t dummy;
  tmuf_gbx_node_body(g, &HMS_SOUND, &dummy);
}

static void c_fast_buffer_nod(tmuf_gbx *g, void *node, uint32_t id);

/* CSceneVehicle 0x0a060000: tunings, materials remap, two references, then
   the vehicle struct. */
static void c0a060000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_scene_object *o = node;
  o->vehicle_tunings = tmuf_gbx_noderef(g);
  o->vehicle_materials = tmuf_gbx_noderef(g);
  tmuf_gbx_noderef(g);
  tmuf_gbx_noderef(g);
  o->vehicle_struct = tmuf_gbx_noderef(g);
}

static void c0a02b003(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_scene_object *)node)->vehicle_tunings = tmuf_gbx_noderef(g);
}

static void c0a02b008(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_scene_object *)node)->vehicle_materials = tmuf_gbx_noderef(g);
}

static void c0a02b014(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_scene_object *)node)->vehicle_struct = tmuf_gbx_noderef(g);
}

static void noderef_skip12(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_noderef(g);
  tmuf_gbx_skip(g, 12);
}

static void noderef3(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  for (int i = 0; i < 3; i++)
    tmuf_gbx_noderef(g);
}

static void noderef2(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_noderef(g);
  tmuf_gbx_noderef(g);
}

static void c0a02b002(tmuf_gbx *g, void *node, uint32_t id) {
  c_fast_buffer_nod(g, node, id);
  tmuf_gbx_u32(g);
}

/* CSceneVehicleCar physical parameters */
static void c0a02b00c(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_scene_object *o = node;
  o->has_physical_params = 1;
  for (int i = 0; i < 8; i++)
    o->physical_params[i] = tmuf_gbx_f32(g);
}

static const tmuf_gbx_chunk SCENE_OBJECT_CHUNKS[] = {
    READ(0x0a060000, c0a060000),    READ(0x0a02b002, c0a02b002),   READ(0x0a02b003, c0a02b003),
    READ(0x0a02b004, skip_noderef), READ(0x0a02b005, noderef_skip12), READ(0x0a02b006, noderef3),
    READ(0x0a02b007, noderef_skip12), READ(0x0a02b008, c0a02b008), READ(0x0a02b00a, skip16),
    READ(0x0a02b00b, noderef2),     READ(0x0a02b00c, c0a02b00c),      NOPAY(0x0a02b00d),
    NOPAY(0x0a02b00e),              NOPAY(0x0a02b00f),             NOPAY(0x0a02b010),
    NOPAY(0x0a02b011),              NOPAY(0x0a02b012),             READ(0x0a02b014, c0a02b014),
    NOPAY(0x01001000),          NOPAY(0x0a005000),         READ(0x0a005001, c0a005001),
    READ(0x0a005002, skip4),    READ(0x0a005003, c0a005003), READ(0x0a005004, skip4),
    READ(0x0a009000, skip4),    READ(0x0a00b000, c0a00b000), READ(0x0a00e000, c0a00e000),
    NOPAY(0x0a011000),          NOPAY(0x0a011001),         NOPAY(0x0a011002),
    READ(0x0a011003, c0a011003), NOPAY(0x0a011004),        READ(0x0a011005, c0a011005),
    READ(0x0a011006, skip_noderef),
};
static const tmuf_gbx_class SCENE_OBJECT = {0x0a005000, "CSceneObject", sizeof(tmuf_scene_object),
                                            SCENE_OBJECT_CHUNKS, COUNT(SCENE_OBJECT_CHUNKS), NULL};

/* CSceneMobilLeaves::Chunk: 0x0a05e000 (the oldest, some values dropped),
   001, 002 (+ curvature), 003 (+ the emitter's cap); the others keep the
   ctor's defaults */
static void c0a05e000(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_scene_mobil_leaves *l = node;
  *l = (tmuf_scene_mobil_leaves){l->object, NULL, 0.05f, 0.03f, 100, 20, 1.0f, 0.5f, 4.0f, 4.0f, 0.5f, 0.5f,
                                 1.0f, 1.0f, {0.0f, 0.0f, 0.0f}, 3500.0f, 50.0f, 0.2f};
  l->shader = tmuf_gbx_noderef(g);
  l->radius = tmuf_gbx_f32(g);
  l->radius_random = tmuf_gbx_f32(g);
  if (id == 0x0a05e000u) {
    tmuf_gbx_skip(g, 8);
    l->max_count = tmuf_gbx_u32(g);
    l->fall = tmuf_gbx_f32(g);
    l->alpha_speed_max = tmuf_gbx_f32(g);
    l->beta_speed_max = tmuf_gbx_f32(g);
    tmuf_gbx_skip(g, 12);
    for (int k = 0; k < 3; k++)
      l->wind[k] = tmuf_gbx_f32(g);
    tmuf_gbx_skip(g, 16);
    l->respawn_period = tmuf_gbx_f32(g);
    tmuf_gbx_skip(g, 4);
    return;
  }
  l->max_count = tmuf_gbx_u32(g);
  if (id == 0x0a05e003u)
    l->emitter_max_count = tmuf_gbx_u32(g);
  l->fall = tmuf_gbx_f32(g);
  l->fall_random = tmuf_gbx_f32(g);
  l->alpha_speed_max = tmuf_gbx_f32(g);
  l->beta_speed_max = tmuf_gbx_f32(g);
  l->swing_radius = tmuf_gbx_f32(g);
  l->swing_radius_random = tmuf_gbx_f32(g);
  l->swing_rate = tmuf_gbx_f32(g);
  l->swing_rate_random = tmuf_gbx_f32(g);
  for (int k = 0; k < 3; k++)
    l->wind[k] = tmuf_gbx_f32(g);
  l->respawn_period = tmuf_gbx_f32(g);
  l->far_z = tmuf_gbx_f32(g);
  if (id != 0x0a05e001u)
    l->curvature = tmuf_gbx_f32(g);
}

static const tmuf_gbx_chunk MOBIL_LEAVES_CHUNKS[] = {READ(0x0a05e000, c0a05e000), READ(0x0a05e001, c0a05e000),
                                                     READ(0x0a05e002, c0a05e000), READ(0x0a05e003, c0a05e000)};
static const tmuf_gbx_class MOBIL_LEAVES = {0x0a05e000, "CSceneMobilLeaves", sizeof(tmuf_scene_mobil_leaves),
                                            MOBIL_LEAVES_CHUNKS, COUNT(MOBIL_LEAVES_CHUNKS), &SCENE_OBJECT};

/* ---- CSceneVehicleTunings (0x0a030000) ---- */

static void c0a030000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_vehicle_tunings *t = node;
  tmuf_gbx_u32(g);
  read_node_list(g, &t->tunings);
  t->selected = tmuf_gbx_u32(g);
}

static const tmuf_gbx_chunk TUNINGS_CHUNKS[] = {READ(0x0a030000, c0a030000)};
static const tmuf_gbx_class TUNINGS = {0x0a030000, "CSceneVehicleTunings", sizeof(tmuf_vehicle_tunings),
                                       TUNINGS_CHUNKS, 1, NULL};

/* ---- CSceneVehicleTuning (0x0a02e000) / CSceneVehicleCarTuning (0x0a029000) ---- */

static void c0a02e000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_car_tuning *t = node;
  t->name = id_text(g);
  t->base_ref = tmuf_gbx_noderef(g);
  t->base_real = tmuf_gbx_f32(g);
  /* The game mixes the first four characters of the tuning name. */
  size_t n = strlen(t->name);
  if (n > 3)
    tmuf_gbx_mix_u32(g, (uint32_t)(uint8_t)t->name[0] | (uint32_t)(uint8_t)t->name[1] << 8 |
                            (uint32_t)(uint8_t)t->name[2] << 16 | (uint32_t)(uint8_t)t->name[3] << 24);
}

static const tmuf_tuning_chunk_schema *tuning_schema(uint32_t id) {
  size_t lo = 0, hi = sizeof TMUF_TUNING_SCHEMA / sizeof TMUF_TUNING_SCHEMA[0];
  while (lo < hi) {
    size_t mid = (lo + hi) / 2;
    if (TMUF_TUNING_SCHEMA[mid].chunk_id < id)
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo < sizeof TMUF_TUNING_SCHEMA / sizeof TMUF_TUNING_SCHEMA[0] && TMUF_TUNING_SCHEMA[lo].chunk_id == id
             ? &TMUF_TUNING_SCHEMA[lo]
             : NULL;
}

static void car_tuning_chunk(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_car_tuning *t = node;
  const tmuf_tuning_chunk_schema *sc = tuning_schema(id);
  if (!sc) {
    tmuf_gbx_fail(g, "no schema for tuning chunk %08x", id);
    return;
  }
  if (t->chunk_count == t->chunk_cap) {
    uint32_t cap = t->chunk_cap ? t->chunk_cap * 2 : 64;
    tmuf_tuning_chunk *c = TMUF_ARENA_ARRAY(g->arena, tmuf_tuning_chunk, cap);
    if (!c) {
      tmuf_gbx_fail(g, "out of memory");
      return;
    }
    if (t->chunk_count)
      memcpy(c, t->chunks, sizeof *c * t->chunk_count);
    t->chunks = c;
    t->chunk_cap = cap;
  }
  tmuf_tuning_chunk *c = &t->chunks[t->chunk_count++];
  c->chunk_id = id;
  c->field_count = (uint32_t)strlen(sc->fields);
  c->fields = TMUF_ARENA_ARRAY(g->arena, tmuf_tuning_field, c->field_count ? c->field_count : 1);
  for (uint32_t i = 0; i < c->field_count && !g->error; i++) {
    tmuf_tuning_field *f = &c->fields[i];
    f->kind = sc->fields[i];
    switch (f->kind) {
    case 'R':
    case 'N':
    case 'B':
      f->raw = tmuf_gbx_u32(g);
      break;
    case 'O':
      f->node = tmuf_gbx_noderef(g);
      break;
    case 'F':
      f->float_count = tmuf_gbx_u32(g);
      f->floats = read_block(g, f->float_count, 4);
      break;
    case 'I':
      f->id = id_text(g);
      break;
    }
  }
}

static int car_tuning_accepts(uint32_t id) { return tuning_schema(id) != NULL; }

static const tmuf_gbx_chunk CAR_TUNING_CHUNKS[] = {READ(0x0a02e000, c0a02e000)};
static const tmuf_gbx_class CAR_TUNING = {
    0x0a02e000, "CSceneVehicleTuning", sizeof(tmuf_car_tuning), CAR_TUNING_CHUNKS, 1, NULL,
    car_tuning_accepts, car_tuning_chunk,
};

/* ---- CFuncKeys (0x05002000): CFuncKeysReal ---- */

static void func_floats(tmuf_gbx *g, uint32_t *count, const float **out) {
  *count = tmuf_gbx_u32(g);
  if (*count > 0x100000u) {
    tmuf_gbx_fail(g, "curve key count %u", *count);
    return;
  }
  *out = read_block(g, *count, 4);
}

static void c05002000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_string(g);
}

static void c05002001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_keys *f = node;
  func_floats(g, &f->x_count, &f->xs);
}

static void c05002002(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_keys *f = node;
  read_floats(g, f->range, 2);
}

static void c05002003(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_func_keys *)node)->name = id_text(g);
}

static void c0501a000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_keys *f = node;
  func_floats(g, &f->y_count, &f->ys);
}

static void c0501a001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_keys *f = node;
  func_floats(g, &f->y_count, &f->ys);
  f->mode = tmuf_gbx_u32(g);
}

/* CFuncKeysSkel: skeleton, then per frame one location (quaternion,
   translation) per bone. */
static void c05006000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_func_keys *)node)->skeleton = tmuf_gbx_noderef(g);
}

static void c05006001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_keys *f = node;
  uint32_t frames = tmuf_gbx_u32(g);
  if (g->error)
    return;
  if (!f->skeleton || !f->skeleton->data || !f->skeleton->cls || f->skeleton->cls->id != 0x05005000u) {
    tmuf_gbx_fail(g, "CFuncKeysSkel without a loaded skeleton");
    return;
  }
  uint32_t bones = ((tmuf_func_skel *)f->skeleton->data)->bone_count;
  uint64_t n = (uint64_t)frames * bones;
  if (n > 0x1000000u) {
    tmuf_gbx_fail(g, "skeleton key count %llu", (unsigned long long)n);
    return;
  }
  tmuf_gbx_skip(g, (size_t)n * 28);
}

/* CFuncKeysNatural: its values (naturals) */
static void c05030000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_keys *f = node;
  const uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "natural key count %u", n);
    return;
  }
  uint32_t *v = TMUF_ARENA_ARRAY(g->arena, uint32_t, n ? n : 1u);
  if (!v) {
    tmuf_gbx_fail(g, "out of memory");
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++)
    v[i] = tmuf_gbx_u32(g);
  f->natural_count = n;
  f->naturals = v;
}

static const tmuf_gbx_chunk FUNC_KEYS_CHUNKS[] = {
    READ(0x05002000, c05002000), READ(0x05002001, c05002001), READ(0x05002002, c05002002),
    READ(0x05002003, c05002003), READ(0x0501a000, c0501a000), READ(0x0501a001, c0501a001),
    READ(0x05006000, c05006000), READ(0x05006001, c05006001), READ(0x05030000, c05030000),
};
static const tmuf_gbx_class FUNC_KEYS = {0x05002000, "CFuncKeys", sizeof(tmuf_func_keys), FUNC_KEYS_CHUNKS,
                                         COUNT(FUNC_KEYS_CHUNKS), NULL};

/* ---- CFuncSkel (0x05005000) ---- */

static void func_skel_bones(tmuf_gbx *g, tmuf_func_skel *k, int element_arrays) {
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "bone count %u", n);
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++) {
    tmuf_gbx_id(g, NULL);
    if (element_arrays)
      skip_counted(g, 4);
  }
  k->bone_count = n;
}

static void func_skel_legacy(tmuf_gbx *g, int ids) {
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "skeleton table count %u", n);
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++) {
    if (ids)
      tmuf_gbx_id(g, NULL);
    else
      tmuf_gbx_string(g);
    tmuf_gbx_u32(g);
  }
}

static void c05005000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  func_skel_legacy(g, 0);
  func_skel_bones(g, node, 1);
}

static void c05005001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  func_skel_legacy(g, 1);
  func_skel_bones(g, node, 1);
}

static void c05005002(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  func_skel_bones(g, node, 0);
}

static const tmuf_gbx_chunk FUNC_SKEL_CHUNKS[] = {READ(0x05005000, c05005000), READ(0x05005001, c05005001),
                                                  READ(0x05005002, c05005002)};
static const tmuf_gbx_class FUNC_SKEL = {0x05005000, "CFuncSkel", sizeof(tmuf_func_skel), FUNC_SKEL_CHUNKS,
                                         COUNT(FUNC_SKEL_CHUNKS), NULL};

/* ---- CFuncPlug (0x0500b000) and CFuncTreeSubVisualSequence ---- */

static void skip4_id(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_skip(g, 4);
  tmuf_gbx_id(g, NULL);
}

static void skip16_id(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_skip(g, 16);
  tmuf_gbx_id(g, NULL);
}

static void c05031000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_func_keys keys;
  memset(&keys, 0, sizeof keys);
  tmuf_gbx_node_body_as(g, &FUNC_KEYS, 0x05030000u, &keys); /* CFuncKeysNatural */
}

static const tmuf_gbx_chunk FUNC_PLUG_CHUNKS[] = {
    READ(0x0500b000, skip4),     READ(0x0500b001, skip4_id), READ(0x0500b002, skip8),
    READ(0x0500b003, skip12),    READ(0x0500b004, skip16),   READ(0x0500b005, skip16_id),
    READ(0x05031000, c05031000), READ(0x05031001, skip_id),  READ(0x05031002, skip_noderef),
    READ(0x05031003, skip12),
    /* CFuncShaders::Chunk: its CFuncShader nodes */
    READ(0x05014000, noderef_array),
};
static const tmuf_gbx_class FUNC_PLUG = {0x0500b000, "CFuncPlug", 1, FUNC_PLUG_CHUNKS, COUNT(FUNC_PLUG_CHUNKS), NULL};

/* CFuncTreeSubVisualSequence (0x05031000) */
static void c0500b005_seq(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_tree_sequence *f = node;
  f->period = tmuf_gbx_f32(g);
  f->phase = tmuf_gbx_f32(g);
  f->has_period = 1;
  f->auto_motion = tmuf_gbx_bool(g) != 0;
  tmuf_gbx_bool(g);
  tmuf_gbx_id(g, NULL);
}

static void c05031000_seq(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_tree_sequence *f = node;
  tmuf_gbx_node_body_as(g, &FUNC_KEYS, 0x05030000u, &f->inline_keys); /* CFuncKeysNatural */
  f->has_inline_keys = !g->error;
}

static void c05031002_seq(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_func_tree_sequence *)node)->keys = tmuf_gbx_noderef(g);
}

static const tmuf_gbx_chunk FUNC_TREE_SEQUENCE_CHUNKS[] = {
    READ(0x0500b005, c0500b005_seq), READ(0x05031000, c05031000_seq), READ(0x05031001, skip_id),
    READ(0x05031002, c05031002_seq), READ(0x05031003, skip12),
};
static const tmuf_gbx_class FUNC_TREE_SEQUENCE = {0x05031000, "CFuncTreeSubVisualSequence",
                                                  sizeof(tmuf_func_tree_sequence), FUNC_TREE_SEQUENCE_CHUNKS,
                                                  COUNT(FUNC_TREE_SEQUENCE_CHUNKS), &FUNC_PLUG};

/* ---- CMotion (0x08001000) family ---- */

static const tmuf_gbx_chunk MOTION_CMD_BASE_CHUNKS[] = {READ(0x08029000, skip16), READ(0x08029001, skip20),
                                                        READ(0x08029002, skip24)};
static const tmuf_gbx_class MOTION_CMD_BASE = {0x08029000, "CMotionCmdBase", 1, MOTION_CMD_BASE_CHUNKS,
                                               COUNT(MOTION_CMD_BASE_CHUNKS), NULL};

static void optional_noderef(tmuf_gbx *g) {
  if (tmuf_gbx_bool(g))
    tmuf_gbx_noderef(g);
}

static void c08034000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  optional_noderef(g);
}

static void c08034001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  optional_noderef(g);
  tmuf_gbx_id(g, NULL);
}

/* 0x08034002: track, command, ...; 003: command, ...; 004: command, u32,
   bool, ... . Each ends with an id and a node array. */
static void c08034002(tmuf_gbx *g, void *node, uint32_t id) {
  if (id == 0x08034002u)
    tmuf_gbx_noderef(g);
  uint8_t cmd;
  tmuf_gbx_node_body(g, &MOTION_CMD_BASE, &cmd);
  tmuf_gbx_skip(g, 4);
  if (id == 0x08034004u)
    tmuf_gbx_bool(g);
  tmuf_gbx_id(g, NULL);
  noderef_array(g, node, id);
}

static void c0802b000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  for (int i = 0; i < 3; i++)
    tmuf_gbx_noderef(g);
}

/* 0x0804c000: manager, centre, one radius (half = r, r, r); 001: manager,
   centre, half extents */
static void c0804c000(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_motion_emitter_leaves *e = node;
  e->manager = tmuf_gbx_noderef(g);
  for (int k = 0; k < 3; k++)
    e->center[k] = tmuf_gbx_f32(g);
  if (id == 0x0804c000u) {
    e->half[0] = e->half[1] = e->half[2] = tmuf_gbx_f32(g);
    return;
  }
  for (int k = 0; k < 3; k++)
    e->half[k] = tmuf_gbx_f32(g);
}

/* CMotionManagerLeaves' only chunk (the emitter's class number) */
static void c0804d_mobil(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_motion_manager_leaves *)node)->mobil = tmuf_gbx_noderef(g);
}

static void c08055000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_noderef(g);
  tmuf_gbx_skip(g, 8);
}

static const tmuf_gbx_chunk MOTION_CHUNKS[] = {
    READ(0x08001000, skip_id),   READ(0x08028000, noderef_array), READ(0x08028001, noderef_array),
    READ(0x08034000, c08034000), READ(0x08034001, c08034001),     READ(0x08034002, c08034002),
    READ(0x08034003, c08034002), READ(0x08034004, c08034002),     READ(0x08054000, skip_noderef),
    READ(0x08055000, c08055000),
};
static const tmuf_gbx_class MOTION = {0x08001000, "CMotion", 1, MOTION_CHUNKS, COUNT(MOTION_CHUNKS), NULL};

static const tmuf_gbx_chunk EMITTER_LEAVES_CHUNKS[] = {READ(0x0804c000, c0804c000), READ(0x0804c001, c0804c000)};
static const tmuf_gbx_class EMITTER_LEAVES = {0x0804c000, "CMotionEmitterLeaves", sizeof(tmuf_motion_emitter_leaves),
                                              EMITTER_LEAVES_CHUNKS, COUNT(EMITTER_LEAVES_CHUNKS), &MOTION};
static const tmuf_gbx_chunk MANAGER_LEAVES_CHUNKS[] = {READ(0x0804c000, c0804d_mobil)};
static const tmuf_gbx_class MANAGER_LEAVES = {0x0804d000, "CMotionManagerLeaves", sizeof(tmuf_motion_manager_leaves),
                                              MANAGER_LEAVES_CHUNKS, COUNT(MANAGER_LEAVES_CHUNKS), &MOTION};

/* CMotionTrack (0x08033000) derives from CMwCmdContainer, not CMotion. */
static const tmuf_gbx_chunk MOTION_TRACK_CHUNKS[] = {READ(0x0802b000, c0802b000), READ(0x08037000, skip_noderef)};
static const tmuf_gbx_class MOTION_TRACK = {0x08033000, "CMotionTrack", 1, MOTION_TRACK_CHUNKS,
                                            COUNT(MOTION_TRACK_CHUNKS), NULL};

/* ---- CSceneVehicleStruct (0x0a039000) ---- */

static uint32_t vs_count(tmuf_gbx *g) {
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u)
    tmuf_gbx_fail(g, "vehicle struct count %u", n);
  return g->error ? 0 : n;
}

static void vs_visual_id(tmuf_gbx *g, tmuf_visual_id *out) {
  out->name = id_text(g);
  out->flag = tmuf_gbx_bool(g);
}

static void c0a039005(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_vehicle_struct *v = node;
  v->wheel_count = vs_count(g);
  v->wheels = TMUF_ARENA_ARRAY(g->arena, tmuf_vehicle_wheel_def, v->wheel_count ? v->wheel_count : 1);
  for (uint32_t i = 0; i < v->wheel_count && !g->error; i++) {
    v->wheels[i].flags[0] = tmuf_gbx_bool(g);
    v->wheels[i].flags[1] = tmuf_gbx_bool(g);
    v->wheels[i].name = id_text(g);
  }
}

static void c0a039006(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_vehicle_struct *v = node;
  v->visual_vehicle_count = vs_count(g);
  v->has_visual_vehicle_count = !g->error;
  v->visual_vehicles = TMUF_ARENA_ARRAY(g->arena, tmuf_visual_vehicle_def,
                                        v->visual_vehicle_count ? v->visual_vehicle_count : 1);
  if (v->visual_vehicles)
    memset(v->visual_vehicles, 0, sizeof *v->visual_vehicles * (v->visual_vehicle_count ? v->visual_vehicle_count : 1));
}

static int vs_need_count(tmuf_gbx *g, tmuf_vehicle_struct *v) {
  if (!v->has_visual_vehicle_count || !v->visual_vehicles)
    tmuf_gbx_fail(g, "vehicle struct visual chunk before count");
  return v->has_visual_vehicle_count && v->visual_vehicles;
}

/* arms: SVisualId arm, from, to; bools; wheel */
static void c0a039009(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_vehicle_struct *v = node;
  if (!vs_need_count(g, v))
    return;
  for (uint32_t k = 0; k < v->visual_vehicle_count && !g->error; k++) {
    tmuf_visual_vehicle_def *vv = &v->visual_vehicles[k];
    uint32_t n = vs_count(g);
    vv->arms = TMUF_ARENA_ARRAY(g->arena, tmuf_visual_arm_def, n ? n : 1);
    vv->arm_count = vv->arms ? n : 0;
    for (uint32_t i = 0; i < vv->arm_count && !g->error; i++) {
      tmuf_visual_arm_def *a = &vv->arms[i];
      vs_visual_id(g, &a->arm);
      vs_visual_id(g, &a->from);
      vs_visual_id(g, &a->to);
      a->flag0 = tmuf_gbx_bool(g);
      a->rolls = tmuf_gbx_bool(g);
      a->wheel = tmuf_gbx_u32(g);
    }
  }
}

/* lights: SVisualId, kind */
static void c0a03900a(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_vehicle_struct *v = node;
  if (!vs_need_count(g, v))
    return;
  for (uint32_t k = 0; k < v->visual_vehicle_count && !g->error; k++) {
    tmuf_visual_vehicle_def *vv = &v->visual_vehicles[k];
    uint32_t n = vs_count(g);
    vv->lights = TMUF_ARENA_ARRAY(g->arena, tmuf_visual_light_def, n ? n : 1);
    vv->light_count = vv->lights ? n : 0;
    for (uint32_t i = 0; i < vv->light_count && !g->error; i++) {
      vs_visual_id(g, &vv->lights[i].tree);
      vv->lights[i].kind = tmuf_gbx_u32(g);
    }
  }
}

/* wheels: SVisualId x4 (at +0, +0x10, +8, +0x18 of SVisualWheel), wheel, steers */
static void c0a03900f(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_vehicle_struct *v = node;
  if (!vs_need_count(g, v))
    return;
  for (uint32_t k = 0; k < v->visual_vehicle_count && !g->error; k++) {
    tmuf_visual_vehicle_def *vv = &v->visual_vehicles[k];
    uint32_t n = vs_count(g);
    vv->wheels = TMUF_ARENA_ARRAY(g->arena, tmuf_visual_wheel_def, n ? n : 1);
    vv->wheel_count = vv->wheels ? n : 0;
    for (uint32_t i = 0; i < vv->wheel_count && !g->error; i++) {
      tmuf_visual_wheel_def *w = &vv->wheels[i];
      vs_visual_id(g, &w->rolling);
      vs_visual_id(g, &w->fixed);
      vs_visual_id(g, &w->bouncing);
      vs_visual_id(g, &w->steering);
      w->wheel = tmuf_gbx_u32(g);
      w->steers = tmuf_gbx_bool(g);
    }
  }
}

/* per level: SVisualId at +0xc (body), +4 (pilot head), +0x14, +0x1c; quality */
static void c0a039010(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_vehicle_struct *v = node;
  if (!vs_need_count(g, v))
    return;
  for (uint32_t k = 0; k < v->visual_vehicle_count && !g->error; k++) {
    tmuf_visual_vehicle_def *vv = &v->visual_vehicles[k];
    vs_visual_id(g, &vv->body);
    vs_visual_id(g, &vv->pilot_head);
    vs_visual_id(g, &vv->shadow);
    vs_visual_id(g, &vv->extra);
    vv->quality = tmuf_gbx_u32(g);
  }
}

static void c0a039012(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_gbx_u32(g);
  read_node_list(g, &((tmuf_vehicle_struct *)node)->material_groups);
}

static void c0a039014(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_gbx_u32(g);
  read_node_list(g, &((tmuf_vehicle_struct *)node)->emitters);
}

static void c0a039013(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_vehicle_struct *v = node;
  for (int i = 0; i < 3; i++)
    v->feedback_curves[i] = tmuf_gbx_noderef(g);
}

static const tmuf_gbx_chunk VEHICLE_STRUCT_CHUNKS[] = {
    READ(0x0a039005, c0a039005), READ(0x0a039006, c0a039006), READ(0x0a039009, c0a039009),
    READ(0x0a03900a, c0a03900a), READ(0x0a03900f, c0a03900f), READ(0x0a039010, c0a039010),
    READ(0x0a039012, c0a039012), READ(0x0a039013, c0a039013), READ(0x0a039014, c0a039014),
};
static const tmuf_gbx_class VEHICLE_STRUCT = {0x0a039000, "CSceneVehicleStruct", sizeof(tmuf_vehicle_struct),
                                              VEHICLE_STRUCT_CHUNKS, COUNT(VEHICLE_STRUCT_CHUNKS), NULL};

static void c0a015000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_vehicle_material_group *m = node;
  const uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x10000u) {
    tmuf_gbx_fail(g, "material group size %u", n);
    return;
  }
  uint32_t *ids = TMUF_ARENA_ARRAY(g->arena, uint32_t, n ? n : 1u);
  if (!ids) {
    tmuf_gbx_fail(g, "out of memory");
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++)
    ids[i] = tmuf_gbx_u32(g);
  m->count = n;
  m->ids = ids;
}

static const tmuf_gbx_chunk VEHICLE_MATERIAL_GROUP_CHUNKS[] = {READ(0x0a015000, c0a015000)};
static const tmuf_gbx_class VEHICLE_MATERIAL_GROUP = {0x0a015000, "CSceneVehicleMaterialGroup",
                                                      sizeof(tmuf_vehicle_material_group),
                                                      VEHICLE_MATERIAL_GROUP_CHUNKS, 1, NULL};

static void c0a010002(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_vehicle_emitter_def *)node)->orient_to_speed = tmuf_gbx_bool(g) != 0;
}

static void c0a010004(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_vehicle_emitter_def *e = node;
  e->kind = tmuf_gbx_u32(g);
  for (int i = 0; i < 3; i++)
    e->models[i] = tmuf_gbx_noderef(g);
  e->wheel = tmuf_gbx_u32(g);
  e->part = tmuf_gbx_u32(g);
  e->group = tmuf_gbx_u32(g);
  e->needs_sliding = tmuf_gbx_bool(g) != 0;
  e->use_owner_loc = tmuf_gbx_bool(g) != 0;
  e->event = tmuf_gbx_bool(g) != 0;
  read_floats(g, e->iso, 12);
  read_floats(g, e->params, 14);
}

static void c0a010005(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_vehicle_emitter_def *)node)->needs_all_sliding = tmuf_gbx_bool(g) != 0;
}

static const tmuf_gbx_chunk VEHICLE_EMITTER_CHUNKS[] = {
    READ(0x0a010002, c0a010002), READ(0x0a010003, skip24), READ(0x0a010004, c0a010004), READ(0x0a010005, c0a010005),
};
static const tmuf_gbx_class VEHICLE_EMITTER = {0x0a010000, "CSceneVehicleEmitter", sizeof(tmuf_vehicle_emitter_def),
                                               VEHICLE_EMITTER_CHUNKS, COUNT(VEHICLE_EMITTER_CHUNKS), NULL};

/* ---- particles: CMotionParticleEmitterModel, CMotionParticleType and their functions ---- */

static void c05036000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_envelope *f = node;
  read_floats(g, f->v, 4);
  f->t1 = tmuf_gbx_f32(g);
  f->t2 = tmuf_gbx_f32(g);
  f->freq = tmuf_gbx_f32(g);
  f->amp = tmuf_gbx_f32(g);
  f->cos = tmuf_gbx_u32(g);
}
static const tmuf_gbx_chunk FUNC_ENVELOPE_CHUNKS[] = {READ(0x05036000, c05036000)};
static const tmuf_gbx_class FUNC_ENVELOPE = {0x05036000, "CFuncEnvelope", sizeof(tmuf_func_envelope),
                                             FUNC_ENVELOPE_CHUNKS, COUNT(FUNC_ENVELOPE_CHUNKS), NULL};

static void c05038000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_gradient *f = node;
  for (int i = 0; i < 4; i++)
    read_floats(g, f->c[i], 3);
  f->t1 = tmuf_gbx_f32(g);
  f->t2 = tmuf_gbx_f32(g);
}
static const tmuf_gbx_chunk FUNC_GRADIENT_CHUNKS[] = {READ(0x05038000, c05038000)};
static const tmuf_gbx_class FUNC_GRADIENT = {0x05038000, "CFuncColorGradient", sizeof(tmuf_func_gradient),
                                             FUNC_GRADIENT_CHUNKS, COUNT(FUNC_GRADIENT_CHUNKS), NULL};

static void c0805b000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_gbx_u32(g);
  read_node_list(g, &((tmuf_particle_model_def *)node)->types);
}
static const tmuf_gbx_chunk PARTICLE_MODEL_CHUNKS[] = {READ(0x0805b000, c0805b000)};
static const tmuf_gbx_class PARTICLE_MODEL = {0x0805b000, "CMotionParticleEmitterModel",
                                              sizeof(tmuf_particle_model_def), PARTICLE_MODEL_CHUNKS,
                                              COUNT(PARTICLE_MODEL_CHUNKS), NULL};

static void pair(tmuf_gbx *g, float out[2]) { read_floats(g, out, 2); }

/* CMotionParticleType::Chunk (the game's own reader's order) */
static void c0805a0xx(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_particle_type_def *p = node;
  switch (id & 0xfffu) {
  case 0x11: {
    p->material = tmuf_gbx_noderef(g);
    if (!p->material)
      p->shader = tmuf_gbx_noderef(g);
    p->ratio_xy = tmuf_gbx_f32(g);
    read_floats(g, p->ref_pos, 2);
    pair(g, p->pitch);
    pair(g, p->yaw);
    p->color_gradient = tmuf_gbx_noderef(g);
    p->color_gradient_use = tmuf_gbx_u32(g);
    p->color_modulate_with_transparency = tmuf_gbx_u32(g);
    p->max_particle_count = tmuf_gbx_u32(g);
    p->birth_period = tmuf_gbx_f32(g);
    pair(g, p->life);
    pair(g, p->size);
    pair(g, p->velocity);
    pair(g, p->weight);
    pair(g, p->roll_speed);
    pair(g, p->transparency);
    p->size_over_life = tmuf_gbx_noderef(g);
    p->transparency_over_life = tmuf_gbx_noderef(g);
    p->particle_type = tmuf_gbx_u32(g);
    tmuf_gbx_u32(g);
    p->multi_state_render_mode = tmuf_gbx_u32(g);
    p->one_part_period = tmuf_gbx_u32(g);
    p->birth_step_type = tmuf_gbx_u32(g);
    p->birth_min_dist = tmuf_gbx_f32(g);
    p->size_gen_period = tmuf_gbx_f32(g);
    p->size_gen = tmuf_gbx_u32(g);
    p->u_scale_dist = tmuf_gbx_f32(g);
    p->standard_render_mode = tmuf_gbx_u32(g);
    p->v_scale_dist = tmuf_gbx_f32(g);
    pair(g, p->fluid_friction);
    p->size_x_over_life = tmuf_gbx_noderef(g);
    p->size_use_size_x = tmuf_gbx_u32(g);
    p->size_use_emission_zone = tmuf_gbx_u32(g);
    p->vert_per_part_count = tmuf_gbx_u32(g);
    tmuf_gbx_u32(g);
    break;
  }
  case 0x13:
    p->splash_part_count = tmuf_gbx_u32(g);
    read_floats(g, p->splash, 8);
    break;
  case 0x15:
    p->size_use_intensity = tmuf_gbx_u32(g);
    p->color_use_intensity = tmuf_gbx_u32(g);
    p->transparency_use_intensity = tmuf_gbx_u32(g);
    read_floats(g, p->birth_pos, 3);
    break;
  case 0x16:
    p->size_emission_zone_scale = tmuf_gbx_f32(g);
    p->birth_pos_type = tmuf_gbx_u32(g);
    break;
  case 0x17:
    p->fluid_friction_intensity_base = tmuf_gbx_f32(g);
    p->fluid_friction_use_intensity = tmuf_gbx_u32(g);
    break;
  case 0x18: p->intensity_filter = tmuf_gbx_noderef(g); break;
  case 0x19: tmuf_gbx_id(g, NULL); break;
  case 0x1a: p->distor = tmuf_gbx_noderef(g); break;
  case 0x1b:
    p->multi_state_async_link = tmuf_gbx_u32(g);
    p->multi_state_static_parts = tmuf_gbx_u32(g);
    break;
  case 0x1c:
    for (int i = 0; i < 4; i++)
      p->texture_atlas[i] = tmuf_gbx_u32(g);
    break;
  case 0x1d: pair(g, p->roll); break;
  case 0x1e: p->view_dist2_max = tmuf_gbx_f32(g); break;
  case 0x1f: p->size_speed_scale = tmuf_gbx_f32(g); break;
  case 0x20:
    for (int i = 0; i < 3; i++)
      p->precalc[i] = tmuf_gbx_u32(g);
    p->physics_enable = tmuf_gbx_u32(g);
    p->physics_bounce = tmuf_gbx_f32(g);
    p->physics_radius = tmuf_gbx_f32(g);
    break;
  case 0x21: p->physics_damper = tmuf_gbx_f32(g); break;
  case 0x22: p->sort_sprites = tmuf_gbx_u32(g); break;
  case 0x23: p->use_game_timer = tmuf_gbx_u32(g); break;
  default: break;
  }
}
static const tmuf_gbx_chunk PARTICLE_TYPE_CHUNKS[] = {
    READ(0x0805a011, c0805a0xx), READ(0x0805a013, c0805a0xx), READ(0x0805a015, c0805a0xx),
    READ(0x0805a016, c0805a0xx), READ(0x0805a017, c0805a0xx), READ(0x0805a018, c0805a0xx),
    READ(0x0805a019, c0805a0xx), READ(0x0805a01a, c0805a0xx), READ(0x0805a01b, c0805a0xx),
    READ(0x0805a01c, c0805a0xx), READ(0x0805a01d, c0805a0xx), READ(0x0805a01e, c0805a0xx),
    READ(0x0805a01f, c0805a0xx), READ(0x0805a020, c0805a0xx), READ(0x0805a021, c0805a0xx),
    READ(0x0805a022, c0805a0xx), READ(0x0805a023, c0805a0xx),
};
static const tmuf_gbx_class PARTICLE_TYPE = {0x0805a000, "CMotionParticleType", sizeof(tmuf_particle_type_def),
                                             PARTICLE_TYPE_CHUNKS, COUNT(PARTICLE_TYPE_CHUNKS), NULL};

/* ---- CPlugPointsInSphereOpt (0x09066000): CFastBuffer<SPack>, CFastBuffer<GmVec3> ---- */

static void c09066000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_points_in_sphere *p = node;
  const uint32_t np = tmuf_gbx_u32(g);
  if (g->error || np > 0x10000u) {
    tmuf_gbx_fail(g, "points in sphere: %u packs", np);
    return;
  }
  uint32_t *packs = TMUF_ARENA_ARRAY(g->arena, uint32_t, 2u * np + 1u);
  tmuf_gbx_read(g, packs, (size_t)np * 8u);
  const uint32_t n = tmuf_gbx_u32(g);
  if (g->error || n > 0x1000000u) {
    tmuf_gbx_fail(g, "points in sphere: %u points", n);
    return;
  }
  float *pts = TMUF_ARENA_ARRAY(g->arena, float, 3u * n + 1u);
  tmuf_gbx_read(g, pts, (size_t)n * 12u);
  p->pack_count = np, p->packs = packs, p->point_count = n, p->points = pts;
}
static const tmuf_gbx_chunk POINTS_IN_SPHERE_CHUNKS[] = {READ(0x09066000, c09066000)};
static const tmuf_gbx_class POINTS_IN_SPHERE = {0x09066000, "CPlugPointsInSphereOpt", sizeof(tmuf_points_in_sphere),
                                                POINTS_IN_SPHERE_CHUNKS, COUNT(POINTS_IN_SPHERE_CHUNKS), NULL};

/* ---- CSceneVehicleMaterial (0x0a031000) ---- */

static void c0a031004(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_vehicle_material *m = node;
  m->fake_bitmap = tmuf_gbx_noderef(g);
  m->fake_period_x = tmuf_gbx_f32(g);
  m->fake_period_z = tmuf_gbx_f32(g);
}

static void c0a031005(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_vehicle_material *m = node;
  m->blend[0] = tmuf_gbx_f32(g);
  m->blend[3] = tmuf_gbx_f32(g);
  m->blend[1] = tmuf_gbx_f32(g);
  m->blend[2] = tmuf_gbx_f32(g);
}

static void c0a03100e(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_vehicle_material *m = node;
  m->natural_id = tmuf_gbx_u8(g);
  m->fake_speed_scale = tmuf_gbx_f32(g);
  m->fake_depth_max = tmuf_gbx_f32(g);
}

static void c0a03100f(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_vehicle_material *m = node;
  m->feedback_speed_divisor = tmuf_gbx_f32(g);
  m->feedback_scale = tmuf_gbx_f32(g);
}

static const tmuf_gbx_chunk VEHICLE_MATERIAL_CHUNKS[] = {
    READ(0x0a031004, c0a031004), READ(0x0a031005, c0a031005), READ(0x0a03100e, c0a03100e),
    READ(0x0a03100f, c0a03100f)};
static const tmuf_gbx_class VEHICLE_MATERIAL = {0x0a031000, "CSceneVehicleMaterial", sizeof(tmuf_vehicle_material),
                                                VEHICLE_MATERIAL_CHUNKS, COUNT(VEHICLE_MATERIAL_CHUNKS), NULL};

/* ---- CGameCtnZone (0x0305c000): Flat, Frontier ---- */

static void zone_c000(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_zone *z = node;
  tmuf_gbx_u32(g);
  if (id == 0x0305c000)
    tmuf_gbx_u32(g); /* local name index */
  else
    z->name = id_text(g);
  z->type = tmuf_gbx_u32(g);
  if (id != 0x0305c002)
    read_node_list(g, &z->refs);
}

static void c0305c003(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_zone *z = node;
  z->height = tmuf_gbx_u32(g);
  z->name = id_text(g);
  z->basic_name = id_text(g);
  z->type = tmuf_gbx_u32(g);
}

static void c0305c004(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_zone *z = node;
  z->depth = tmuf_gbx_u32(g);
  z->old_zone = tmuf_gbx_u32(g) != 0;
}

static void c0305c005(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_zone *)node)->has_water = tmuf_gbx_u32(g) != 0;
}

static void zone_flat(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_zone *z = node;
  int n = id == 0x0305d000 ? 3 : 4;
  for (int i = 0; i < n; i++)
    z->block_infos[i] = tmuf_gbx_noderef(g);
}

/* Two bools, or a larger skippable form. */
static void c0305d002(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_skip(g, g->chunk_size != 0xffffffffu ? g->chunk_size : 8);
}

static void zone_frontier(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_zone *z = node;
  z->block_infos[0] = tmuf_gbx_noderef(g);
  z->frontier_parent = id_text(g);
  z->frontier_child = id_text(g);
}

static const tmuf_gbx_chunk ZONE_CHUNKS[] = {
    READ(0x0305c000, zone_c000), READ(0x0305c001, zone_c000), READ(0x0305c002, zone_c000),
    READ(0x0305c003, c0305c003), READ(0x0305c004, c0305c004), READ(0x0305c005, c0305c005),
    READ(0x0305d000, zone_flat), READ(0x0305d001, zone_flat), READ(0x0305d002, c0305d002),
    READ(0x0305e000, zone_frontier), READ(0x0305e001, zone_frontier),
};
static const tmuf_gbx_class ZONE = {0x0305c000, "CGameCtnZone", sizeof(tmuf_zone), ZONE_CHUNKS, COUNT(ZONE_CHUNKS),
                                    NULL};

/* ---- CSceneObjectLink (0x0a014000) ---- */

/* CSceneMobil::ArchiveOwnDataOld (reading), for a model instance. */
static void mobil_own_data_into(tmuf_gbx *g, const char **name, tmuf_node_list *children) {
  uint32_t version = tmuf_gbx_u32(g);
  if (version == 0) {
    *name = id_text(g);
    return;
  }
  if (version == 2) {
    /* (class, size) pairs until -1; CSceneMobil does not consume the data. */
    for (int guard = 0; guard < 4096 && !g->error; guard++) {
      if (tmuf_wrap_class_id(tmuf_gbx_u32(g)) == 0xffffffffu)
        break;
      tmuf_gbx_u32(g);
    }
  } else if (version != 1) {
    return;
  }
  *name = id_text(g);
  read_node_list(g, children);
}

static void mobil_own_data(tmuf_gbx *g, tmuf_object_link *l) {
  mobil_own_data_into(g, &l->instance_name, &l->instance_children);
}

/* CSceneMobil::DoMobilPtr (versioned): -1 null, -2 plain node reference,
   else an internal reference slot whose first use carries the model
   reference and the instance's own data. */
static tmuf_mobil_instance *do_mobil_ptr(tmuf_gbx *g) {
  uint32_t v = tmuf_gbx_u32(g);
  if (g->error || v == 0xffffffffu)
    return NULL;
  tmuf_mobil_instance *m = TMUF_ARENA_NEW(g->arena, tmuf_mobil_instance);
  if (!m) {
    tmuf_gbx_fail(g, "out of memory");
    return NULL;
  }
  if (v == 0xfffffffeu) {
    m->model = tmuf_gbx_noderef(g);
    return m;
  }
  void **slot = tmuf_gbx_internal_ref(g, v);
  if (!slot)
    return NULL;
  if (*slot)
    return *slot;
  m->model = tmuf_gbx_noderef(g);
  if (m->model)
    mobil_own_data_into(g, &m->name, &m->children);
  *slot = m;
  return m;
}

static void link_read_iso_active(tmuf_gbx *g, tmuf_object_link *l) {
  read_floats(g, l->iso, 12);
  l->active = tmuf_gbx_bool(g);
}

static void c0a014000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_object_link *l = node;
  l->object = tmuf_gbx_noderef(g);
  link_read_iso_active(g, l);
}

/* CSceneObjectLink::Chunk 0x0a014001: a mobil goes through
   CSceneMobil::DoMobilPtr (model reference, then the new instance's own
   data), anything else is a plain reference. */
static void c0a014001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_object_link *l = node;
  l->is_mobil = tmuf_gbx_bool(g);
  l->object = tmuf_gbx_noderef(g);
  if (l->is_mobil && l->object)
    mobil_own_data(g, l);
  link_read_iso_active(g, l);
}

static void c0a014002(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_object_link *l = node;
  l->tree_id = id_text(g);
  tmuf_gbx_bool(g);
  tmuf_gbx_bool(g);
}

static void c0a014003(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_object_link *)node)->tree_id = id_text(g);
}

static void c0a00f001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_object_link *l = node;
  tmuf_gbx_skip(g, 24);
  l->active = tmuf_gbx_bool(g);
}

static void c0a00f002(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_object_link *)node)->active = tmuf_gbx_bool(g);
}

static const tmuf_gbx_chunk OBJECT_LINK_CHUNKS[] = {
    READ(0x0a00f000, c0a014000), READ(0x0a00f001, c0a00f001), READ(0x0a00f002, c0a00f002),
    READ(0x0a014000, c0a014000), READ(0x0a014001, c0a014001), READ(0x0a014002, c0a014002),
    READ(0x0a014003, c0a014003),
};
static const tmuf_gbx_class OBJECT_LINK = {0x0a014000, "CSceneObjectLink", sizeof(tmuf_object_link),
                                           OBJECT_LINK_CHUNKS, COUNT(OBJECT_LINK_CHUNKS), NULL};

static void count4_array(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  skip_counted(g, 4);
}

/* ---- CGameCtnCollection (0x03033000) ---- */

static void c03033009(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_collection *c = node;
  c->name = id_text(g);
  c->zone_tag = tmuf_gbx_u32(g);
  read_node_list(g, &c->zones);
  c->default_zone = tmuf_gbx_noderef(g);
  tmuf_gbx_u32(g);
  c->square_size = tmuf_gbx_f32(g);
  c->square_height = tmuf_gbx_f32(g);
  for (int i = 0; i < 3; i++)
    c->vehicle[i] = id_text(g);
}

static void c0303300d(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_collection *c = node;
  for (int i = 0; i < 2; i++) {
    tmuf_gbx_u32(g);
    c->scene_refs[i] = tmuf_gbx_noderef(g);
  }
}

static void c0303301d(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_collection *c = node;
  c->surface_replacement_count = tmuf_gbx_u32(g);
  if (c->surface_replacement_count > 0x100000u) {
    tmuf_gbx_fail(g, "surface replacement count %u", c->surface_replacement_count);
    return;
  }
  c->surface_replacements = TMUF_ARENA_ARRAY(g->arena, const char *, 2 * c->surface_replacement_count + 1);
  for (uint32_t i = 0; i < c->surface_replacement_count && !g->error; i++) {
    c->surface_replacements[2 * i] = id_text(g);
    c->surface_replacements[2 * i + 1] = id_text(g);
  }
  /* CFastBuffer of CGameCtnDecorationTerrainModifier: version, count, refs */
  uint32_t version = tmuf_gbx_u32(g);
  uint32_t n = tmuf_gbx_u32(g);
  if (version != 10u || n > 128u) {
    tmuf_gbx_fail(g, "terrain modifier buffer %u/%u", version, n);
    return;
  }
  c->terrain_modifier_count = n;
  c->terrain_modifiers = TMUF_ARENA_ARRAY(g->arena, tmuf_gbx_node *, n ? n : 1);
  for (uint32_t i = 0; i < n && !g->error; i++)
    c->terrain_modifiers[i] = tmuf_gbx_noderef(g);
}

static void c0303301e(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_collection *c = node;
  c->has_water_heights = 1;
  c->water_surface = tmuf_gbx_f32(g);
  c->water_secondary = tmuf_gbx_f32(g);
  c->water_render_cull = tmuf_gbx_f32(g);
  c->default_water = tmuf_gbx_bool(g);
}

/* CGameCtnCollection::Chunk 0x03033024: +0x84, +0x90, +0x8c, +0x88,
   +0xac VertexLighting, +0xb0 ColorVertexMin, +0xb4 ColorVertexMax */
static void c03033024(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_collection *c = node;
  c->shadow_mode = tmuf_gbx_u32(g);
  c->shadow_90 = tmuf_gbx_u32(g);
  c->shadow_8c = tmuf_gbx_bool(g);
  c->shadow_88 = tmuf_gbx_f32(g);
  c->vertex_lighting = tmuf_gbx_u32(g);
  c->color_vertex_min = tmuf_gbx_f32(g);
  c->color_vertex_max = tmuf_gbx_f32(g);
  c->has_lighting = 1;
}

static void c03033022(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_collection *c = node;
  c->has_geometry_water = 1;
  c->geometry_water_planes = tmuf_gbx_u32(g) != 0;
}

static void c03033020(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_collection *c = node;
  for (int i = 0; i < 4; i++)
    c->folders[i] = tmuf_gbx_string(g);
}

static void c03033021(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_collection *)node)->display_name = tmuf_gbx_string(g);
}

static void skip48(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_skip(g, 48);
}

static const tmuf_gbx_chunk COLLECTION_CHUNKS[] = {
    READ(0x03033009, c03033009), READ(0x0303300c, skip8),   READ(0x0303300d, c0303300d),
    READ(0x0303300e, skip4),     READ(0x03033011, skip4),   READ(0x03033019, skip4),
    READ(0x0303301a, skip48),    READ(0x0303301d, c0303301d), READ(0x0303301e, c0303301e),
    READ(0x0303301f, count4_array), READ(0x03033020, c03033020), READ(0x03033021, c03033021),
    READ(0x03033022, c03033022),     READ(0x03033023, skip4),   READ(0x03033024, c03033024),
};
static const tmuf_gbx_class COLLECTION = {0x03033000, "CGameCtnCollection", sizeof(tmuf_collection),
                                          COLLECTION_CHUNKS, COUNT(COLLECTION_CHUNKS), NULL};

/* ---- CGameCtnDecorationTerrainModifier (0x0303c000) ---- */

static void c0303c000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_terrain_modifier *m = node;
  m->skin = tmuf_gbx_noderef(g);
  m->folder = tmuf_gbx_string(g);
}

static void c0303c001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_terrain_modifier *)node)->name = id_text(g);
}

static const tmuf_gbx_chunk TERRAIN_MODIFIER_CHUNKS[] = {READ(0x0303c000, c0303c000), READ(0x0303c001, c0303c001)};
static const tmuf_gbx_class TERRAIN_MODIFIER = {0x0303c000, "CGameCtnDecorationTerrainModifier",
                                                sizeof(tmuf_terrain_modifier), TERRAIN_MODIFIER_CHUNKS,
                                                COUNT(TERRAIN_MODIFIER_CHUNKS), NULL};

/* ---- CPlugGameSkin (0x03031000) ---- */

static void c03031003(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_string(g);
  tmuf_gbx_string(g);
}

static void c03031004(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_game_skin *k = node;
  uint8_t version = tmuf_gbx_u8(g);
  if (version != 4u) {
    tmuf_gbx_fail(g, "game skin version %u", version);
    return;
  }
  for (int i = 0; i < 3; i++)
    tmuf_gbx_string(g);
  uint8_t n = tmuf_gbx_u8(g);
  k->rules = TMUF_ARENA_ARRAY(g->arena, tmuf_skin_rule, n ? n : 1);
  k->rule_count = 0;
  for (uint32_t i = 0; i < n && !g->error; i++) {
    tmuf_skin_rule *r = &k->rules[k->rule_count++];
    r->class_id = tmuf_gbx_u32(g);
    r->prefix = tmuf_gbx_string(g);
    r->has_target = tmuf_gbx_u32(g) != 0;
    r->target = tmuf_gbx_noderef(g);
    if (tmuf_gbx_u32(g) != 0u)
      tmuf_gbx_fail(g, "game skin pack element index");
  }
}

static const tmuf_gbx_chunk GAME_SKIN_CHUNKS[] = {READ(0x03031003, c03031003), READ(0x03031004, c03031004)};
static const tmuf_gbx_class GAME_SKIN = {0x03031000, "CPlugGameSkin", sizeof(tmuf_game_skin), GAME_SKIN_CHUNKS,
                                         COUNT(GAME_SKIN_CHUNKS), NULL};

/* ---- CGameCtnDecoration (0x03038000) ---- */

static void decoration_ref(tmuf_gbx *g, void *node, uint32_t id) {
  ((tmuf_decoration *)node)->refs[(id & 0xfff) - 0x11] = tmuf_gbx_noderef(g);
  /* Only the size (0x03038011, the first) matters for physics; the audio and
     mood nodes that follow use crypted chunks, so stop here. */
  if (id == 0x03038011u)
    g->stop = 1;
}

static void decoration_ident(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_decoration *d = node;
  for (int i = 0; i < 3; i++)
    d->collector_ident[i] = id_text(g);
}

static const tmuf_gbx_chunk DECORATION_CHUNKS[] = {
    READ(0x0301a006, skip4),          READ(0x0301a007, skip24),         READ(0x0301a009, c0301a009),
    READ(0x0301a00a, skip_id),        READ(0x0301a00b, decoration_ident), READ(0x03038011, decoration_ref),
    READ(0x03038012, decoration_ref), READ(0x03038013, decoration_ref), READ(0x03038014, decoration_ref),
    READ(0x03038015, decoration_ref), READ(0x03038016, decoration_ref),
};
static const tmuf_gbx_class DECORATION = {0x03038000, "CGameCtnDecoration", sizeof(tmuf_decoration),
                                          DECORATION_CHUNKS, COUNT(DECORATION_CHUNKS), NULL};

/* ---- CGameCtnDecorationSize (0x0303b000) ---- */

static void c0303b001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_decoration_size *d = node;
  d->base_height = tmuf_gbx_u32(g);
  for (int i = 0; i < 3; i++)
    d->size[i] = tmuf_gbx_u32(g);
  d->scene = tmuf_gbx_noderef(g);
}

static const tmuf_gbx_chunk DECORATION_SIZE_CHUNKS[] = {READ(0x0303b000, skip20), READ(0x0303b001, c0303b001)};
static const tmuf_gbx_class DECORATION_SIZE = {0x0303b000, "CGameCtnDecorationSize", sizeof(tmuf_decoration_size),
                                               DECORATION_SIZE_CHUNKS, COUNT(DECORATION_SIZE_CHUNKS), NULL};

/* ---- CScene3d (0x0a003000) with CScene (0x0a001000) ---- */

static void fast_buffer_nod(tmuf_gbx *g, tmuf_node_list *out) {
  uint32_t version = tmuf_gbx_u32(g);
  if (version != 10) {
    tmuf_gbx_fail(g, "fast buffer version %u", version);
    return;
  }
  read_node_list(g, out);
}

static void c_fast_buffer_nod(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_node_list l;
  fast_buffer_nod(g, &l);
}

static void c0a001004(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  skip_counted(g, 4);
}

static void c0a003004(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "scene buffer count %u", n);
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++) {
    tmuf_gbx_noderef(g);
    tmuf_gbx_noderef(g);
    tmuf_gbx_skip(g, 48);
  }
}

static void c0a003007(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_skip(g, 4 + 48);
}

static void c0a003008(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "scene field count %u", n);
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++) {
    tmuf_gbx_noderef(g);
    tmuf_gbx_noderef(g);
  }
}

static void c0a00300b(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_noderef(g);
  tmuf_gbx_string(g);
}

static void c0a00300f(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_gbx_noderef(g);
  c_fast_buffer_nod(g, node, id);
}

static void c0a003012(tmuf_gbx *g, void *node, uint32_t id) {
  c_fast_buffer_nod(g, node, id);
  tmuf_gbx_u32(g);
}

static void c0a003013(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_noderef(g);
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "scene fx count %u", n);
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++)
    tmuf_gbx_noderef(g);
}

/* CScene::InternalArchiveSceneObjectBuffer */
static void scene_object_buffer(tmuf_gbx *g, tmuf_scene3d *sc, int mobils, tmuf_node_list *objects) {
  uint32_t count;
  tmuf_mobil_instance **list = NULL;
  if (mobils) {
    count = tmuf_gbx_u32(g);
    if (count > 0x100000u) {
      tmuf_gbx_fail(g, "scene object count %u", count);
      return;
    }
    list = TMUF_ARENA_ARRAY(g->arena, tmuf_mobil_instance *, count ? count : 1);
    for (uint32_t i = 0; i < count && !g->error; i++)
      list[i] = do_mobil_ptr(g);
  } else {
    tmuf_node_list l = {0};
    fast_buffer_nod(g, &l);
    count = l.count;
    if (objects)
      *objects = l;
  }
  uint32_t locs = tmuf_gbx_u32(g);
  if (locs > 0x100000u) {
    tmuf_gbx_fail(g, "scene loc count %u", locs);
    return;
  }
  tmuf_scene_loc *loc = TMUF_ARENA_ARRAY(g->arena, tmuf_scene_loc, locs ? locs : 1);
  for (uint32_t i = 0; i < locs && !g->error; i++) {
    loc[i].sector = tmuf_gbx_noderef(g);
    read_floats(g, loc[i].iso, 12);
  }
  if (mobils && !g->error) {
    sc->mobil_count = count;
    sc->mobils = list;
    sc->loc_count = locs;
    sc->locs = loc;
  }
}

static void c0a003016(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_scene3d *sc = node;
  uint32_t version = id == 0x0a003016u ? 1 : id == 0x0a003017u ? 2 : 3;
  fast_buffer_nod(g, &sc->sectors);
  if (version > 2)
    tmuf_gbx_u32(g);
  scene_object_buffer(g, sc, version > 2, &sc->objects[0]);
  for (int i = 1; i <= 5 && !g->error; i++)
    scene_object_buffer(g, sc, 0, &sc->objects[i]);
  if (version > 1)
    c_fast_buffer_nod(g, node, id); /* gates */
  c_fast_buffer_nod(g, node, id);   /* paths */
  /* then Chunk(0x0a00300e) (reads nothing here), Chunk(0x0a00300f),
     Chunk(0x0a003015) */
  c0a00300f(g, node, 0x0a00300fu);
  tmuf_gbx_noderef(g);
}

static const tmuf_gbx_chunk SCENE3D_CHUNKS[] = {
    NOPAY(0x0a001000),              NOPAY(0x0a001001),              READ(0x0a001003, skip_noderef),
    READ(0x0a001004, c0a001004),    READ(0x0a001005, c_fast_buffer_nod),
    READ(0x0a003000, noderef_array), READ(0x0a003001, noderef_array), NOPAY(0x0a003002),
    NOPAY(0x0a003003),              READ(0x0a003004, c0a003004),    READ(0x0a003005, c_fast_buffer_nod),
    NOPAY(0x0a003006),              READ(0x0a003007, c0a003007),    READ(0x0a003008, c0a003008),
    READ(0x0a003009, c0a003004),    NOPAY(0x0a00300a),              READ(0x0a00300b, c0a00300b),
    READ(0x0a00300c, skip4),        NOPAY(0x0a00300d),              READ(0x0a00300f, c0a00300f),
    READ(0x0a003010, skip16),       READ(0x0a003011, skip_noderef), READ(0x0a003012, c0a003012),
    READ(0x0a003013, c0a003013),    READ(0x0a003014, skip80),       READ(0x0a003015, skip_noderef),
    READ(0x0a003016, c0a003016),    READ(0x0a003017, c0a003016),    READ(0x0a003018, c0a003016),
};
static const tmuf_gbx_class SCENE3D = {0x0a003000, "CScene3d", sizeof(tmuf_scene3d), SCENE3D_CHUNKS,
                                       COUNT(SCENE3D_CHUNKS), NULL};

/* ---- CSceneTrafficGraph (0x0a062000) ---- */

static void c0a062004(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  uint32_t nodes = tmuf_gbx_u32(g), links = tmuf_gbx_u32(g);
  if (nodes > 0x100000u || links) {
    tmuf_gbx_fail(g, "traffic graph %u nodes %u links", nodes, links);
    return;
  }
  tmuf_gbx_skip(g, (size_t)nodes * 4);
}

static const tmuf_gbx_chunk TRAFFIC_GRAPH_CHUNKS[] = {NOPAY(0x0a062000), NOPAY(0x0a062001), NOPAY(0x0a062002),
                                                      NOPAY(0x0a062003), READ(0x0a062004, c0a062004),
                                                      NOPAY(0x0a062005)};
static const tmuf_gbx_class TRAFFIC_GRAPH = {0x0a062000, "CSceneTrafficGraph", 1, TRAFFIC_GRAPH_CHUNKS,
                                             COUNT(TRAFFIC_GRAPH_CHUNKS), NULL};

/* ---- CSceneSector (0x0a004000) ---- */

static void c0a004000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  tmuf_gbx_noderef(g);
  tmuf_gbx_noderef(g);
}

static const tmuf_gbx_chunk SECTOR_CHUNKS[] = {READ(0x0a004000, c0a004000), READ(0x0a004001, skip48),
                                               READ(0x0a004002, skip_id), READ(0x0a004004, skip24)};
static const tmuf_gbx_class SECTOR = {0x0a004000, "CSceneSector", 1, SECTOR_CHUNKS, COUNT(SECTOR_CHUNKS), NULL};

/* ---- CHmsZone (0x06004000) ---- */

static void c06004002(tmuf_gbx *g, void *node, uint32_t id) {
  c_fast_buffer_nod(g, node, id);
  tmuf_gbx_skip(g, 28); /* GxFogGlobal: color, start, end, density, flags */
}

static void c06004003(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  if (tmuf_gbx_bool(g))
    tmuf_gbx_skip(g, 24);
}

static const tmuf_gbx_chunk HMS_ZONE_CHUNKS[] = {
    READ(0x06004000, skip4),         NOPAY(0x06004001),         READ(0x06004002, c06004002),
    READ(0x06004003, c06004003),     READ(0x06004004, skip_noderef), READ(0x06004005, c_fast_buffer_nod),
    READ(0x06004006, skip_noderef),
};
static const tmuf_gbx_class HMS_ZONE = {0x06004000, "CHmsZone", 1, HMS_ZONE_CHUNKS, COUNT(HMS_ZONE_CHUNKS), NULL};

/* ---- CMwRefBuffer (0x01026000) ---- */

static void c01026000(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_gbx_u32(g);
  tmuf_gbx_bool(g);
  fast_buffer_nod(g, node);
  UNUSED(id);
}

static const tmuf_gbx_chunk REF_BUFFER_CHUNKS[] = {READ(0x01026000, c01026000)};
static const tmuf_gbx_class REF_BUFFER = {0x01026000, "CMwRefBuffer", sizeof(tmuf_node_list), REF_BUFFER_CHUNKS, 1,
                                          NULL};

/* ---- CSceneVehicleEnvironment (0x0a033000) ---- */

static const tmuf_gbx_chunk VEHICLE_ENV_CHUNKS[] = {READ(0x0a033000, skip4), NOPAY(0x0a033001),
                                                    READ(0x0a033002, noderef_array)};
static const tmuf_gbx_class VEHICLE_ENV = {0x0a033000, "CSceneVehicleEnvironment", 1, VEHICLE_ENV_CHUNKS,
                                           COUNT(VEHICLE_ENV_CHUNKS), NULL};

/* ---- the weather: CGameCtnDecorationMood, CMotionManagerWeathers,
   CFuncWeather, CFuncClouds, CFuncShaderLayerUV ---- */

/* CGameCtnDecorationMood::Chunk_Crypted / Chunk (0x0303a000..005) */
static void c0303a000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_mood *m = node;
  m->latitude = tmuf_gbx_f32(g);
  m->real18 = tmuf_gbx_f32(g);
  m->real1c = tmuf_gbx_f32(g);
  m->time_sun_rise = tmuf_gbx_u32(g);
  m->time_sun_fall = tmuf_gbx_u32(g);
}

static void c0303a001(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_mood *m = node;
  m->remapped_start_day_time = tmuf_gbx_f32(g);
  m->light_map = tmuf_gbx_noderef(g);
  m->folder = tmuf_gbx_string(g);
}

static void c0303a002(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_mood *m = node;
  m->shadow_count_car_human = tmuf_gbx_u32(g);
  m->shadow_count_car_opponent = tmuf_gbx_u32(g);
  m->shadow_car_intensity = tmuf_gbx_f32(g);
  m->shadow_scene = tmuf_gbx_bool(g);
  m->background_is_locally_lighted = tmuf_gbx_bool(g);
}

static void c0303a004(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_mood *)node)->pack_light_map = tmuf_gbx_noderef(g);
}

static void c0303a005(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  ((tmuf_mood *)node)->ambient_occ = tmuf_gbx_noderef(g);
}

static const tmuf_gbx_chunk MOOD_CHUNKS[] = {
    READ(0x0303a000, c0303a000), READ(0x0303a001, c0303a001), READ(0x0303a002, c0303a002),
    READ(0x0303a003, skip4),     READ(0x0303a004, c0303a004), READ(0x0303a005, c0303a005),
};
static const tmuf_gbx_class MOOD = {0x0303a000, "CGameCtnDecorationMood", sizeof(tmuf_mood), MOOD_CHUNKS,
                                    COUNT(MOOD_CHUNKS), NULL};

/* CHmsAmbientOcc::Chunk 0x06026000 */
static void c06026000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_ambient_occ *a = node;
  a->radius = tmuf_gbx_f32(g);
  a->power = tmuf_gbx_f32(g);
  a->blur_texels = tmuf_gbx_u32(g);
  read_floats(g, a->mid_gray, 3);
}

static const tmuf_gbx_chunk AMBIENT_OCC_CHUNKS[] = {READ(0x06026000, c06026000)};
static const tmuf_gbx_class AMBIENT_OCC = {0x06026000, "CHmsAmbientOcc", sizeof(tmuf_ambient_occ), AMBIENT_OCC_CHUNKS,
                                           COUNT(AMBIENT_OCC_CHUNKS), NULL};

/* CMotionManagerWeathers::Chunk */
static void c08053000(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_motion_weathers *w = node;
  fast_buffer_nod(g, &w->weathers);
  if (id == 0x08053001u)
    w->specular_dir = tmuf_gbx_noderef(g);
}

static const tmuf_gbx_chunk MOTION_WEATHERS_CHUNKS[] = {READ(0x08053000, c08053000), READ(0x08053001, c08053000)};
static const tmuf_gbx_class MOTION_WEATHERS = {0x08053000, "CMotionManagerWeathers", sizeof(tmuf_motion_weathers),
                                               MOTION_WEATHERS_CHUNKS, COUNT(MOTION_WEATHERS_CHUNKS), NULL};

/* CFuncWeather::Chunk, the chunks of the game's files */
static void c0503400b(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_weather *w = node;
  for (int i = 0; i < 4; i++)
    w->sky_materials[i] = tmuf_gbx_noderef(g);
  for (int i = 0; i < 2; i++)
    w->sea_materials[i] = tmuf_gbx_noderef(g);
}

static void c0503400d(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_weather *w = node;
  /* 0x05034006: +0xe8, +0xd4, +0xdc, six reals +0x108..+0x11c */
  read_floats(g, w->vec_e8, 2);
  read_floats(g, w->spec_intensity, 2);
  read_floats(g, w->spec_power, 2);
  read_floats(g, w->reals108, 6);
  read_floats(g, w->vec_f0, 2);
  read_floats(g, w->vec_f8, 2);
  read_floats(g, w->vec_100, 2);
}

static void c0503400e(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_weather *w = node;
  for (int i = 0; i < 2; i++) { /* GxFogGlobal::ArchiveFog: 0x1c bytes */
    read_floats(g, w->fogs[i].rgb, 3);
    w->fogs[i].start = tmuf_gbx_f32(g);
    w->fogs[i].end = tmuf_gbx_f32(g);
    w->fogs[i].density = tmuf_gbx_f32(g);
    w->fogs[i].flags = tmuf_gbx_u32(g) & 0xfu;
  }
  w->name = id_text(g);
  w->light_ambient = tmuf_gbx_noderef(g);
  w->light_sun = tmuf_gbx_noderef(g);
  w->light_moon = tmuf_gbx_noderef(g);
  w->flare_sun = tmuf_gbx_noderef(g);
  w->flare_moon = tmuf_gbx_noderef(g);
  w->flare_size_sun = tmuf_gbx_f32(g);
  w->flare_size_moon = tmuf_gbx_f32(g);
  read_floats(g, w->reals_c4, 3);
  w->real_d0 = tmuf_gbx_f32(g);
  w->nodes_bc[0] = tmuf_gbx_noderef(g);
  w->nodes_bc[1] = tmuf_gbx_noderef(g);
}

#define WEATHER_REF(fn, field) \
  static void fn(tmuf_gbx *g, void *node, uint32_t id) { \
    UNUSED(id); \
    ((tmuf_func_weather *)node)->field = tmuf_gbx_noderef(g); \
  }
WEATHER_REF(c0503400f, light_double_sided)
WEATHER_REF(c05034011, sky_gradient)
WEATHER_REF(c05034013, fog_color)
WEATHER_REF(c05034014, sea_color)
WEATHER_REF(c05034016, clouds)
WEATHER_REF(c05034017, fog_blender)

static const tmuf_gbx_chunk FUNC_WEATHER_CHUNKS[] = {
    NOPAY(0x05034007),           READ(0x0503400b, c0503400b), READ(0x0503400d, c0503400d),
    READ(0x0503400e, c0503400e), READ(0x0503400f, c0503400f), READ(0x05034011, c05034011),
    READ(0x05034013, c05034013), READ(0x05034014, c05034014), READ(0x05034016, c05034016),
    READ(0x05034017, c05034017),
};
static const tmuf_gbx_class FUNC_WEATHER = {0x05034000, "CFuncWeather", sizeof(tmuf_func_weather),
                                            FUNC_WEATHER_CHUNKS, COUNT(FUNC_WEATHER_CHUNKS), NULL};

/* CFuncClouds::Chunk */
static void c0503a000(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_func_clouds *c = node;
  read_node_list(g, &c->solids);
  c->real3c = tmuf_gbx_f32(g);
  c->real4c = tmuf_gbx_f32(g);
  c->color_min = tmuf_gbx_noderef(g);
  c->color_max = tmuf_gbx_noderef(g);
  c->nat54 = tmuf_gbx_u32(g);
  if (id == 0x0503a001u) /* scaled at load by the double at 0xb5b9c0 */
    c->real50 = (float)((double)tmuf_gbx_f32(g) * 1.9438400268554688);
  else if (id == 0x0503a004u)
    c->real50 = tmuf_gbx_f32(g);
}

static void c0503a002(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_clouds *c = node;
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x10000u) {
    tmuf_gbx_fail(g, "cloud key count %u", n);
    return;
  }
  c->keys = (float(*)[2])tmuf_arena_alloc(g->arena, sizeof(float[2]) * (n ? n : 1));
  c->key_count = n;
  for (uint32_t i = 0; i < n && !g->error; i++)
    read_floats(g, c->keys[i], 2);
}

static void c0503a003(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_clouds *c = node;
  c->nat30 = tmuf_gbx_u32(g);
  c->real34 = tmuf_gbx_f32(g);
  c->real38 = tmuf_gbx_f32(g);
}

static const tmuf_gbx_chunk FUNC_CLOUDS_CHUNKS[] = {
    READ(0x0503a000, c0503a000), READ(0x0503a002, c0503a002), READ(0x0503a003, c0503a003),
    READ(0x0503a004, c0503a000),
};
static const tmuf_gbx_class FUNC_CLOUDS = {0x0503a000, "CFuncClouds", sizeof(tmuf_func_clouds), FUNC_CLOUDS_CHUNKS,
                                           COUNT(FUNC_CLOUDS_CHUNKS), NULL};

/* CFuncShaderLayerUV::Chunk (and CFuncPlug::Chunk 0x0500b005 for its period) */
static void c0500b005_layer(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_layer_uv *f = node;
  f->period = tmuf_gbx_f32(g);
  f->phase = tmuf_gbx_f32(g);
  f->has_period = 1;
  f->auto_motion = tmuf_gbx_bool(g) != 0;
  tmuf_gbx_bool(g);
  tmuf_gbx_id(g, NULL);
}

static void c05015005(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_layer_uv *f = node;
  f->layer = tmuf_gbx_string(g);
  f->signal = tmuf_gbx_u32(g) & 0xffu;
}

static void c0501500d(tmuf_gbx *g, void *node, uint32_t id) {
  tmuf_func_layer_uv *f = node;
  read_floats(g, f->vec28, 2);
  if (id == 0x0501500bu)
    return;
  read_floats(g, f->vec30, 2);
  if (id == 0x05015009u)
    return;
  read_floats(g, f->vec38, 2);
}

static void c05015015(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_func_layer_uv *f = node;
  for (int i = 0; i < 3; i++)
    f->cells[i] = tmuf_gbx_u32(g);
  f->flip_v = tmuf_gbx_bool(g) & 1;
}

static const tmuf_gbx_chunk FUNC_LAYER_UV_CHUNKS[] = {
    READ(0x0500b005, c0500b005_layer), READ(0x05015005, c05015005), READ(0x05015009, c0501500d),
    READ(0x0501500a, c0501500d),       READ(0x0501500b, c0501500d), READ(0x0501500d, c0501500d),
    READ(0x05015013, c0501500d),       READ(0x05015015, c05015015),
};
static const tmuf_gbx_class FUNC_LAYER_UV = {0x05015000, "CFuncShaderLayerUV", sizeof(tmuf_func_layer_uv),
                                             FUNC_LAYER_UV_CHUNKS, COUNT(FUNC_LAYER_UV_CHUNKS), &FUNC_PLUG};

static void c05014000(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  read_node_list(g, &((tmuf_func_shaders *)node)->funcs);
}

static const tmuf_gbx_chunk FUNC_SHADERS_CHUNKS[] = {READ(0x05014000, c05014000)};
static const tmuf_gbx_class FUNC_SHADERS = {0x05014000, "CFuncShaders", sizeof(tmuf_func_shaders),
                                            FUNC_SHADERS_CHUNKS, COUNT(FUNC_SHADERS_CHUNKS), &FUNC_PLUG};

const tmuf_gbx_class *const tmuf_pack_classes[] = {
    &SOLID,           &TREE,  &TREE_MIP,        &TREE_LIGHT, &VISUAL,          &SURFACE, &SURFACE_GEOM,
    &PLUG_LIGHT,      &BITMAP_RENDER_HEMI, &BITMAP_RENDER_LFM,
    &LIGHT,           &DECORATOR_SOLID, &DECORATOR_TREE, &MATERIAL, &MATERIAL_CUSTOM, &SHADER, &SHADER_PASS, &BITMAP_SAMPLER,
    &BITMAP,          &BITMAP_RENDER, &FILE_GEN,
    &BLOCK_INFO,      &BLOCK, &BLOCK_UNIT, &SCENE_OBJECT, &TUNINGS, &CAR_TUNING, &FUNC_KEYS,
    &VEHICLE_STRUCT,  &VEHICLE_MATERIAL, &VEHICLE_MATERIAL_GROUP, &VEHICLE_EMITTER, &ZONE,
    &OBJECT_LINK,     &COLLECTION, &DECORATION, &FUNC_SKEL, &FUNC_PLUG, &MOTION, &EMITTER_LEAVES, &MANAGER_LEAVES, &MOBIL_LEAVES, &MOTION_CMD_BASE,
    &MOTION_TRACK,    &DECORATION_SIZE, &SCENE3D, &SECTOR, &HMS_ZONE, &REF_BUFFER,
    &TRAFFIC_GRAPH,   &VEHICLE_ENV, &TERRAIN_MODIFIER, &GAME_SKIN,
    &MOOD,            &AMBIENT_OCC, &MOTION_WEATHERS, &FUNC_WEATHER, &FUNC_CLOUDS, &FUNC_LAYER_UV, &FUNC_SHADERS,
    &FUNC_TREE_SEQUENCE, &FUNC_ENVELOPE, &FUNC_GRADIENT, &PARTICLE_MODEL, &PARTICLE_TYPE, &POINTS_IN_SPHERE,
};
const size_t tmuf_pack_class_count = COUNT(tmuf_pack_classes);
