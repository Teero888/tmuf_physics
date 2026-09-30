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
  tmuf_visual_mip *mips;
} tmuf_visuals_data;

/* Mesh data points into the scene's assets, strings into arena: both must
   outlive the result. */
/* lightmap_of_corpus: per scene corpus, its index in the track's
   tmuf_lightmap (or NULL). is_night: the map's (tmuf_weather), the fid
   parameter IsNight that picks each material's day or night shader. */
int tmuf_visuals_build(tmuf_visuals_data *out, tmuf_scene *scene, const uint32_t *lightmap_of_corpus, int is_night,
                       tmuf_arena *arena);
/* The visuals of a list of scene visuals (not the scene's), sprite visuals
   included (TMUF_VISUAL_SPRITES meshes). */
int tmuf_visuals_build_list(tmuf_visuals_data *out, tmuf_scene *scene, const tmuf_scene_visual *list, uint32_t n,
                            int is_night, tmuf_arena *arena);
void tmuf_visuals_free(tmuf_visuals_data *v);

/* Lights (tmuf_light) of a list of tree lights */
typedef struct tmuf_lights_data {
  uint32_t count;
  tmuf_light *lights;
} tmuf_lights_data;

/* The scene's tree lights; is_night, mood_folder: the map's (tmuf_weather) */
int tmuf_track_lights_build(tmuf_lights_data *out, tmuf_scene *scene, int is_night, const char *mood_folder,
                            tmuf_arena *arena);
void tmuf_lights_free(tmuf_lights_data *l);

typedef struct tmuf_vehicle_visuals_data {
  tmuf_vehicle_visuals view;
  tmuf_visuals_data visuals;
  tmuf_vehicle_part *parts;
  tmuf_lights_data lights;
} tmuf_vehicle_visuals_data;

/* is_night, mood_folder: the map's (tmuf_weather), for the materials' and
   the lights' fid parameters */
int tmuf_vehicle_visuals_build(tmuf_vehicle_visuals_data *out, tmuf_scene *scene, const tmuf_vehicle *vehicle,
                               int is_night, const char *mood_folder, tmuf_arena *arena);
void tmuf_vehicle_visuals_free(tmuf_vehicle_visuals_data *v);

#endif
