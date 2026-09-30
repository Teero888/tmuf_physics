#ifndef TMUF_COMMON_SCENERY_H
#define TMUF_COMMON_SCENERY_H

/* The scenery lighting of a track (tmuf_scenery_light): the collection's
   vertex lighting and shadow settings, the decoration scene's ambient light
   and its pictures, the static objects' box. */

#include <tmuf_physics/tmuf_physics.h>

#include "common/arena.h"
#include "common/scene.h"

typedef struct tmuf_scenery_data {
  tmuf_scenery_light view;
  int found;
  /* the lamps the bake takes (tmuf_track_prelight_instance) */
  uint32_t lamp_count;
  tmuf_light *lamps;
} tmuf_scenery_data;

/* visuals: the track's (for the static box); weather: its (the mood skin's
   file swaps), may be NULL. Strings and pixels in arena. */
/* lights: the track's tree lights. */
int tmuf_scenery_build(tmuf_scenery_data *out, tmuf_scene *scene, const tmuf_visuals *visuals, const tmuf_weather *weather, const tmuf_light *lights,
                       uint32_t light_count, tmuf_arena *arena);

#endif
