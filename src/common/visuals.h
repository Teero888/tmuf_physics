#ifndef TMUF_COMMON_VISUALS_H
#define TMUF_COMMON_VISUALS_H

/* The public tmuf_visuals of a track, built from its scene's visuals. */

#include <tmuf_physics/tmuf_physics.h>

#include "common/arena.h"
#include "common/scene.h"
#include "common/vehicle.h"

typedef struct tmuf_visuals_data {
  tmuf_visuals view;
  tmuf_visual_mesh *meshes;
  tmuf_visual_material *materials;
  tmuf_visual_instance *instances;
} tmuf_visuals_data;

/* Mesh data points into the scene's assets, strings into arena: both must
   outlive the result. */
/* lightmap_of_corpus: per scene corpus, its index in the track's
   tmuf_lightmap (or NULL) */
int tmuf_visuals_build(tmuf_visuals_data *out, tmuf_scene *scene, const uint32_t *lightmap_of_corpus,
                       tmuf_arena *arena);
/* The visuals of a list of scene visuals (not the scene's), sprite visuals
   included (TMUF_VISUAL_SPRITES meshes). */
int tmuf_visuals_build_list(tmuf_visuals_data *out, tmuf_scene *scene, const tmuf_scene_visual *list, uint32_t n,
                            tmuf_arena *arena);
void tmuf_visuals_free(tmuf_visuals_data *v);

typedef struct tmuf_vehicle_visuals_data {
  tmuf_vehicle_visuals view;
  tmuf_visuals_data visuals;
  tmuf_vehicle_part *parts;
} tmuf_vehicle_visuals_data;

int tmuf_vehicle_visuals_build(tmuf_vehicle_visuals_data *out, tmuf_scene *scene, const tmuf_vehicle *vehicle,
                               tmuf_arena *arena);
void tmuf_vehicle_visuals_free(tmuf_vehicle_visuals_data *v);

#endif
