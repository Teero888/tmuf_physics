#ifndef TMUF_REFERENCE_COLLIDE_H
#define TMUF_REFERENCE_COLLIDE_H

/* Surface collisions (GmCollision_*) and the moving-tree vs static-world
   traversal (CHmsCollisionManager::SZone). */

#include <stdint.h>

#include "reference/gm.h"
#include "reference/world.h"

/* SHmsPhysicalCollision */
typedef struct ref_collision {
  gm_vec3 separation, normal, point; /* impulse normal, contact point */
  uint16_t local_mat_a, local_mat_b;
  uint8_t mat_a, mat_b; /* EPlugSurfaceMaterialId */
  uint8_t sphere_merge_primary;
  gm_vec3 extra_negated;
  /* actors: moving body (A) and the static record or other body (B) */
  int32_t corpus_a, corpus_b; /* -1: the car; else a static corpus index */
  const void *tree_a, *tree_b;
  uint32_t group_pair;
} ref_collision;

typedef struct ref_cbuf {
  uint32_t count, cap;
  ref_collision *items;
} ref_cbuf;

ref_collision *ref_cbuf_add(ref_cbuf *b);
void ref_cbuf_clear(ref_cbuf *b);
void ref_cbuf_free(ref_cbuf *b);

/* A tree of the moving body (car): surfaces with local transforms. */
typedef struct tmuf_collision_tree {
  uint32_t flags; /* CPlugTree flags: 0x80 collision, 0x4 local transform */
  gm_iso4 local;
  const ref_surf *surf;
  gm_box box; /* CPlugTree::Box, in the parent frame */
  uint32_t child_count;
  struct tmuf_collision_tree **children;
  /* per-tree sphere contact buffer (SHmsSphereBufferContact) */
  ref_cbuf sphere;
  int queued;
} ref_mtree;

typedef struct ref_detect {
  const ref_world *world;
  ref_cbuf *out;
  ref_mtree *queued[64];
  uint32_t queued_count;
  uint32_t group_pair;
} ref_detect;

/* CPlugSurface::ComputeCollision: a (moving) against b; materials resolved. */
int ref_surface_collide(const ref_surf *a, const gm_iso4 *iso_a, const ref_surf *b, const gm_iso4 *iso_b,
                        ref_cbuf *out);

/* SZone::DetectCollisionBetweenTreeAndStaticCollisionTree for one moving
   tree hierarchy, then MergeQueuedSphereContacts. */
void ref_detect_static(ref_detect *d, ref_mtree *tree, const gm_iso4 *moving_iso);
void ref_detect_merge(ref_detect *d);

/* CPlugTree::UpdateBoundingBox for moving trees (surfaces only). */
int ref_mtree_update_box(ref_mtree *t);

#endif
