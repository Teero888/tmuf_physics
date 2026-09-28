#ifndef TMUF_REFERENCE_COLLIDE_H
#define TMUF_REFERENCE_COLLIDE_H

/* Surface collisions (GmCollision_*) and the moving-tree vs static-world
   traversal (CHmsCollisionManager::SZone). */

#include <stdint.h>

#include "optimized/gm.h"
#include "optimized/world.h"

typedef tmuf_collision ref_collision;
typedef tmuf_collision_buffer ref_cbuf;

ref_collision *ref_cbuf_add(ref_cbuf *b);
void ref_cbuf_clear(ref_cbuf *b);
void ref_cbuf_free(ref_cbuf *b);

typedef tmuf_collision_tree ref_mtree;
typedef tmuf_detect ref_detect;

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
