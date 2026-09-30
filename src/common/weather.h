#ifndef TMUF_COMMON_WEATHER_H
#define TMUF_COMMON_WEATHER_H

/* The map's weather: its decoration's mood, the environment's
   CMotionManagerWeathers and the mood skin's file swaps (tmuf_weather). */

#include <tmuf_physics/tmuf_physics.h>

#include "common/arena.h"
#include "common/scene.h"
#include "common/visuals.h"

typedef struct tmuf_weather_data {
  tmuf_weather view;
  int found;
  tmuf_visuals_data cloud_visuals; /* the cloud pieces' meshes and materials */
} tmuf_weather_data;

/* Reads the weather of a built scene (its decoration and decoration scene
   assets) into w, strings and arrays in arena. 0 when there is none. */
int tmuf_weather_build(tmuf_weather_data *w, tmuf_scene *scene, tmuf_arena *arena);
void tmuf_weather_free(tmuf_weather_data *w);

#endif
