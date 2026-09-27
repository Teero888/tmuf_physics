#ifndef TMUF_REFERENCE_SIM_H
#define TMUF_REFERENCE_SIM_H

/* One car in the static world: the zone step (CHmsZoneDynamic::PhysicsStep2),
   collision response and the replay control ticks. */

#include <stdint.h>

#include "common/scene.h"
#include "common/vehicle.h"
#include "reference/car.h"
#include "reference/collide.h"
#include "reference/world.h"

/* ReplayRaceTransitionActions + controls of one 10 ms control tick */
typedef struct ref_tick {
  uint32_t period_ms, time_ms;
  int establish_spawn, enable_race, reset_at_race_start, finish_race;
  uint32_t respawns;
  float gate_a, gate_b, steering;
} ref_tick;

/* CTrackManiaRace: checkpoint slots and the respawn location */
typedef struct ref_race {
  int has_spawn;
  gm_iso4 current, previous; /* CTrackManiaPlayerInfo spawn locations */
  uint32_t checkpoint_count, laps, lap_checkpoints, completed_laps, checkpoints_passed;
  int completed;
  uint8_t *passed; /* checkpoint_count + 1 slots (the last: finish) */
  /* per scene corpus */
  int32_t *slot; /* checkpoint slot, -1 if none */
  uint8_t *role, *respawn_current;
  gm_iso4 *spawn;
} ref_race;

typedef struct ref_sim {
  ref_world world;
  ref_world triggers;
  ref_race race;
  car_def def;
  car car;
  dyna body;
  ref_cbuf buf;
  ref_detect det;
  uint32_t tree_count;
  ref_mtree *trees;
  ref_mtree **child_ptrs;
  gm_iso4 *corpus_iso;
  uint32_t corpus_count;
  float gravity_y, linear_damping, angular_damping;
  uint32_t tick_ms, period_ms;
  int first_step;
  uint32_t substeps; /* of the last step */
} ref_sim;

/* Builds the world from the scene and the car from the vehicle; spawns at
   `spawn` rotated by the validation seed. Races one lap (see race.laps). */
int ref_sim_init(ref_sim *s, tmuf_scene *scene, const tmuf_vehicle *vehicle, const gm_iso4 *spawn, uint32_t seed,
                 const ref_tick *first, char *err, size_t err_size);
void ref_sim_free(ref_sim *s);
void ref_sim_step(ref_sim *s, const ref_tick *tick);

/* Control ticks of a replay (ReplayControlPlan for input-only validation).
   Returns the tick count; *out is malloc'ed. */
typedef struct tmuf_ghost tmuf_ghost;
uint32_t ref_control_ticks(const tmuf_ghost *ghost, ref_tick **out);

#endif
