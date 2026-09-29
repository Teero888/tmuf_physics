#ifndef TMUF_COMMON_VISUALS_H
#define TMUF_COMMON_VISUALS_H

/* The public tmuf_visuals of a track, built from its scene's visuals. */

#include <tmuf_physics/tmuf_physics.h>

#include "common/arena.h"
#include "common/scene.h"

typedef struct tmuf_visuals_data {
  tmuf_visuals view;
  tmuf_visual_mesh *meshes;
  tmuf_visual_material *materials;
  tmuf_visual_instance *instances;
} tmuf_visuals_data;

/* Mesh data points into the scene's assets, strings into arena: both must
   outlive the result. */
int tmuf_visuals_build(tmuf_visuals_data *out, tmuf_scene *scene, tmuf_arena *arena);
void tmuf_visuals_free(tmuf_visuals_data *v);

#endif
