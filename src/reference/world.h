#ifndef TMUF_REFERENCE_WORLD_H
#define TMUF_REFERENCE_WORLD_H

/* The static collision world: surfaces of the static items in the order the
   game registers them, and the bintree the game builds over them
   (CHmsCollisionManager::SGroup::UpdateStaticCollisionTrees). */

#include <stdint.h>

#include "common/pack_classes.h"
#include "common/scene.h"
#include "reference/gm.h"

enum { SURF_SPHERE = 0, SURF_ELLIPSOID = 1, SURF_BOX = 6, SURF_MESH = 7 };

/* A GmSurf (CPlugSurface geometry) with its material table. */
typedef struct ref_surf {
  const void *key; /* surface node */
  uint32_t type;
  gm_box geom_box;          /* archived bounds */
  uint16_t material;        /* primitive's local material */
  float params[6];          /* sphere radius / ellipsoid radii / box center, half */
  uint32_t vertex_count, triangle_count, cell_count;
  const float *vertices;    /* 3 floats each */
  const uint8_t *triangles; /* normal, plane distance, 3 indices, u16 material */
  const uint8_t *cells;     /* u32 subtree count, center, half, i32 triangle */
  uint32_t material_count;
  const uint8_t *material_ids; /* EPlugSurfaceMaterialId per local material */
} ref_surf;

typedef struct ref_static_cell {
  gm_box bounds;
  uint32_t subtree_count;
  int32_t record; /* index into records, -1 for a branch */
} ref_static_cell;

typedef struct ref_static_record {
  gm_box bounds;
  gm_iso4 iso;
  const ref_surf *surf;
  uint32_t tree_flags;
  uint32_t corpus;
} ref_static_record;

typedef struct ref_world {
  uint32_t surf_count, surf_cap;
  ref_surf **surfs;
  uint32_t record_count, record_cap;
  ref_static_record *records;
  uint32_t cell_count, cell_cap;
  ref_static_cell *cells;
} ref_world;

int ref_world_build(ref_world *w, tmuf_scene *scene);
void ref_world_free(ref_world *w);

/* Mesh access */
static inline gm_vec3 ref_mesh_vertex(const ref_surf *s, uint32_t i) {
  const float *v = s->vertices + (size_t)i * 3;
  return v3(v[0], v[1], v[2]);
}

#endif
