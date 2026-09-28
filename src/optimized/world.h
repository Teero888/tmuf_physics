#ifndef TMUF_REFERENCE_WORLD_H
#define TMUF_REFERENCE_WORLD_H

/* The static collision world: surfaces of the static items in the order the
   game registers them, and the bintree the game builds over them
   (CHmsCollisionManager::SGroup::UpdateStaticCollisionTrees). */

#include <stdint.h>

#include "common/pack_classes.h"
#include "common/scene.h"
#include "optimized/gm.h"

#define SURF_SPHERE TMUF_SURFACE_SPHERE
#define SURF_ELLIPSOID TMUF_SURFACE_ELLIPSOID
#define SURF_BOX TMUF_SURFACE_BOX
#define SURF_MESH TMUF_SURFACE_MESH

typedef tmuf_surface ref_surf;
typedef tmuf_static_cell ref_static_cell;
typedef tmuf_static_record ref_static_record;
typedef tmuf_static_world ref_world;

enum { REF_WORLD_STATIC, REF_WORLD_TRIGGERS, REF_WORLD_NONSTATIC };

/* The static items of collision group 4, or the race triggers (group 1). */
int ref_world_build(ref_world *w, tmuf_scene *scene, int group);
/* Surface of another (moving) item; owned by the world. */
ref_surf *ref_world_surface(ref_world *w, tmuf_assets *assets, tmuf_asset *owner, tmuf_gbx_node *surface);
void ref_world_free(ref_world *w);

/* Mesh access */
static inline gm_vec3 ref_mesh_vertex(const ref_surf *s, uint32_t i) {
  const float *v = s->vertices + (size_t)i * 3;
  return v3(v[0], v[1], v[2]);
}

#endif
