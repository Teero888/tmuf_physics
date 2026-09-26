#include "common/pack_classes.h"

#include <string.h>

/* Chunk entries with no payload may also be stored skippable. */
#define NOPAY(id) {(id), TMUF_GBX_MAYBE_SKIP, NULL}
#define READ(id, fn) {(id), 0, (fn)}
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
SKIP_FN(1)
SKIP_FN(4)
SKIP_FN(8)
SKIP_FN(12)
SKIP_FN(16)
SKIP_FN(24)
SKIP_FN(32)
SKIP_FN(52)
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
    tmuf_gbx_noderef(g);
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
    tmuf_gbx_noderef(g);
  if (!(use_model && has_model))
    s->tree = tmuf_gbx_noderef(g);
}

static void c09005011(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(id);
  tmuf_plug_solid *s = node;
  int use_model = tmuf_gbx_bool(g), has_model = tmuf_gbx_bool(g);
  if (has_model) {
    if (tmuf_gbx_bool(g))
      tmuf_gbx_u32(g); /* model fid reference index */
    else
      tmuf_gbx_noderef(g);
  }
  if (!(use_model && has_model))
    s->tree = tmuf_gbx_noderef(g);
}

static const tmuf_gbx_chunk SOLID_CHUNKS[] = {
    READ(0x09005000, skip4),        NOPAY(0x09005001),          NOPAY(0x09005002),          NOPAY(0x09005003),
    NOPAY(0x09005004),              NOPAY(0x09005005),          READ(0x09005006, c09005006), READ(0x09005007, skip4),
    NOPAY(0x09005008),              NOPAY(0x09005009),          READ(0x0900500a, c0900500a), READ(0x0900500b, skip32),
    READ(0x0900500c, skip72),       READ(0x0900500d, c0900500d), READ(0x0900500e, c0900500e), READ(0x0900500f, skip8),
    READ(0x09005010, skip_noderef), READ(0x09005011, c09005011), READ(0x09005012, skip1),
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
    READ(0x0904f011, skip_noderef),
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
  t->children = TMUF_ARENA_ARRAY(g->arena, tmuf_gbx_node *, n ? n : 1);
  t->child_count = 0;
  for (uint32_t i = 0; i < n && !g->error; i++) {
    tmuf_gbx_skip(g, 4); /* distance */
    tmuf_gbx_node *c = tmuf_gbx_noderef(g);
    if (c)
      t->children[t->child_count++] = c;
  }
}

static const tmuf_gbx_chunk TREE_MIP_CHUNKS[] = {NOPAY(0x09015000), NOPAY(0x09015001), READ(0x09015002, c09015002)};
static const tmuf_gbx_class TREE_MIP = {0x09015000, "CPlugTreeVisualMip", sizeof(tmuf_plug_tree), TREE_MIP_CHUNKS,
                                        COUNT(TREE_MIP_CHUNKS), &TREE};

static const tmuf_gbx_chunk TREE_LIGHT_CHUNKS[] = {NOPAY(0x09062000), NOPAY(0x09062001), NOPAY(0x09062002),
                                                   NOPAY(0x09062003), READ(0x09062004, skip_noderef)};
static const tmuf_gbx_class TREE_LIGHT = {0x09062000, "CPlugTreeLight", sizeof(tmuf_plug_tree), TREE_LIGHT_CHUNKS,
                                          COUNT(TREE_LIGHT_CHUNKS), &TREE};

/* ---- CPlugVisual family ---- */

static void c09006005(tmuf_gbx *g, void *node, uint32_t id) {
  UNUSED(node);
  UNUSED(id);
  skip_counted(g, 12);
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
  skip_counted(g, 4); /* tangents */
  skip_counted(g, 4); /* binormals */
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
    READ(0x09010005, skip24),
    READ(0x09010006, skip4),
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

static const tmuf_gbx_chunk LIGHT_CHUNKS[] = {
    NOPAY(0x04001000), NOPAY(0x04001001), NOPAY(0x04001002), NOPAY(0x04001003), NOPAY(0x04001004), NOPAY(0x04001005),
    NOPAY(0x04001006), NOPAY(0x04001007), NOPAY(0x04001008), READ(0x04001009, skip52),
    /* GxLightAmbient */
    READ(0x04005000, skip8),
    /* GxLightDirectional */
    READ(0x04007000, skip12), READ(0x04007001, skip16), READ(0x04007002, skip24), READ(0x04007003, skip12),
    READ(0x04007004, skip16), READ(0x04007005, skip8),
};
static const tmuf_gbx_class LIGHT = {0x04001000, "GxLight", 1, LIGHT_CHUNKS, COUNT(LIGHT_CHUNKS), NULL};

/* ---- CPlugDecoratorSolid (0x090a3000) ---- */

static const tmuf_gbx_chunk DECORATOR_SOLID_CHUNKS[] = {READ(0x090a3000, skip_noderef_buffer)};
static const tmuf_gbx_class DECORATOR_SOLID = {0x090a3000, "CPlugDecoratorSolid", 1, DECORATOR_SOLID_CHUNKS, 1, NULL};

const tmuf_gbx_class *const tmuf_pack_classes[] = {
    &SOLID, &TREE, &TREE_MIP, &TREE_LIGHT, &VISUAL, &SURFACE, &SURFACE_GEOM, &LIGHT, &DECORATOR_SOLID,
};
const size_t tmuf_pack_class_count = COUNT(tmuf_pack_classes);
