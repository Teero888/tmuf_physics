#ifndef TMUF_COMMON_CONTROLS_H
#define TMUF_COMMON_CONTROLS_H

/* The per-tick controls the game derives from a ghost's input events
   (ReplayControlPlan for input-only validation). Plain data shared by both
   backends. */

#include <stdint.h>

#include "common/replay.h"

#define TMUF_CONTROL_TICK_MS 10u
#define TMUF_CONTROL_RACE_START_MS 2600u

/* ReplayRaceTransitionActions + controls of one 10 ms control tick */
typedef struct tmuf_control_tick {
  uint32_t period_ms, time_ms;
  int establish_spawn, enable_race, reset_at_race_start, finish_race;
  uint32_t respawns;
  /* the input as the game reads it, and the car controls it sets */
  uint8_t accelerate, brake;
  int32_t steer; /* -65536 .. 65536 */
  float gate_a, gate_b, steering;
} tmuf_control_tick;

/* Control ticks of a ghost. Returns the count; *out is malloc'ed. */
uint32_t tmuf_control_ticks(const tmuf_ghost *ghost, tmuf_control_tick **out);

/* The control tick number `index` (from time 0) of a live run: the race
   starts at TMUF_CONTROL_RACE_START_MS as in every replay. */
tmuf_control_tick tmuf_control_tick_at(uint32_t index, int accelerate, int brake, int32_t steer, uint32_t respawns);

#endif
