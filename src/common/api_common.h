#ifndef TMUF_COMMON_API_COMMON_H
#define TMUF_COMMON_API_COMMON_H

/* Public objects both backends share (packs, replays) and helpers for the
   backends' tracks. */

#include <stddef.h>

#include <tmuf_physics/tmuf_physics.h>

#include "common/arena.h"
#include "common/challenge.h"
#include "common/packset.h"
#include "common/replay.h"
#include "common/scene.h"
#include "common/vehicle.h"
#include "common/visuals.h"

struct tmuf_packs {
  tmuf_packset set;
};

struct tmuf_replay {
  tmuf_arena arena;
  uint8_t *data;
  tmuf_replay_file file;
  const tmuf_ghost *ghost;
  tmuf_input *inputs;
  uint32_t input_count;
};

/* The map, its scene and its car, as a backend builds its track from. */
typedef struct tmuf_track_base {
  tmuf_arena arena;
  uint8_t *map_data;
  size_t map_size;
  uint32_t seed; /* validation seed the track runs with */
  tmuf_challenge map;
  tmuf_scene scene;
  tmuf_vehicle vehicle;
  const char *vehicle_name;
  tmuf_triangle *triangles;
  uint32_t triangle_count;
  uint32_t laps;
  int has_visuals;
  tmuf_visuals_data visuals; /* with TMUF_TRACK_VISUALS */
  tmuf_vehicle_visuals_data vehicle_visuals;
} tmuf_track_base;

void tmuf_set_error(char *err, size_t err_size, const char *fmt, ...);
int tmuf_track_base_load(tmuf_track_base *b, const tmuf_packs *packs, const void *map, size_t size,
                         const tmuf_track_options *options, char *err, size_t err_size);
void tmuf_track_base_free(tmuf_track_base *b);
/* the backend's track's base */
const tmuf_track_base *tmuf_track_base_of(const tmuf_track *track);

#endif
