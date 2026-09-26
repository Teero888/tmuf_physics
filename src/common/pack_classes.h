#ifndef TMUF_COMMON_PACK_CLASSES_H
#define TMUF_COMMON_PACK_CLASSES_H

/* Readers for the node classes stored in the game's packs (solids, trees,
   visuals, surfaces, lights, ...) and the data kept from them. */

#include <stddef.h>
#include <stdint.h>

#include "common/gbx.h"

typedef struct tmuf_plug_solid {
  tmuf_gbx_node *tree;
  int has_physics;
  float mass, center_of_mass[3], inertia[9];
  float fluid_friction, response_a, response_b;
} tmuf_plug_solid;

typedef struct tmuf_plug_tree {
  const char *name;
  uint32_t flags; /* decoded CPlugTree::SFlags word */
  int has_iso;
  float iso[12]; /* 3x3 rotation (row-major) then translation */
  uint32_t child_count;
  tmuf_gbx_node **children;
  tmuf_gbx_node *visual, *shader, *material, *surface, *generator;
} tmuf_plug_tree;

#define TMUF_VISUAL_MAX_TEXCOORDS 8

typedef struct tmuf_plug_visual {
  uint32_t flags;
  uint32_t vertex_count;
  uint32_t texcoord_count;
  uint8_t texcoord_dim[TMUF_VISUAL_MAX_TEXCOORDS];
  const float *texcoords[TMUF_VISUAL_MAX_TEXCOORDS];
  float bbox[6]; /* center, half extents */
  uint32_t vertex_stride;
  const uint8_t *vertices; /* position, [normal u32], [color u32], [sprite 8] */
  uint32_t index_count;
  const uint16_t *indices;
  tmuf_gbx_node *material;
} tmuf_plug_visual;

typedef struct tmuf_plug_surface_material {
  tmuf_gbx_node *ref; /* explicit material node, or NULL */
  uint16_t id;        /* default material id when ref is NULL */
} tmuf_plug_surface_material;

typedef struct tmuf_plug_surface {
  tmuf_gbx_node *geom;
  uint32_t material_count;
  tmuf_plug_surface_material *materials;
} tmuf_plug_surface;

enum {
  TMUF_SURF_SPHERE = 0,
  TMUF_SURF_ELLIPSOID = 1,
  TMUF_SURF_BOX = 6,
  TMUF_SURF_MESH = 7,
};

typedef struct tmuf_plug_surface_geom {
  uint32_t type;
  float bbox[6];
  uint16_t material_id;
  float params[6]; /* sphere radius / ellipsoid radii / box */
  uint32_t vertex_count, triangle_count, cell_count;
  const float *vertices;    /* 3 floats each */
  const uint8_t *triangles; /* 32 bytes each */
  const uint8_t *cells;     /* 32 bytes each */
} tmuf_plug_surface_geom;

extern const tmuf_gbx_class *const tmuf_pack_classes[];
extern const size_t tmuf_pack_class_count;

#endif
