#ifndef TMUF_REFERENCE_SIM_H
#define TMUF_REFERENCE_SIM_H

/* One car in the static world: the zone step (CHmsZoneDynamic::PhysicsStep2),
   collision response and the replay control ticks. */

#include <stdint.h>

#include "common/scene.h"
#include "common/controls.h"
#include "common/vehicle.h"
#include "reference/car.h"
#include "reference/collide.h"
#include "reference/world.h"

typedef tmuf_control_tick ref_tick;

typedef tmuf_race ref_race;

typedef struct ref_sim {
  ref_world world;
  ref_world triggers;
  ref_race race;
  tmuf_scene_water water; /* copy of the scene's (cells owned here) */
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
  int shared; /* a clone: the static world, triggers, race tables and water belong to the template */
} ref_sim;

/* Builds the world from the scene and the car from the vehicle; spawns at
   `spawn` rotated by the validation seed. Races one lap (see race.laps). */
int ref_sim_init(ref_sim *s, tmuf_scene *scene, const tmuf_vehicle *vehicle, const gm_iso4 *spawn, uint32_t seed,
                 const ref_tick *first, char *err, size_t err_size);
void ref_sim_free(ref_sim *s);

/* A simulation equal to `tpl` that shares its immutable parts (static world,
   triggers, race tables, water); `tpl` must outlive it. Returns 0 on
   allocation failure. */
int ref_sim_clone(ref_sim *dst, const ref_sim *tpl);

/* Snapshots: everything that changes while simulating, as a flat buffer that
   can be loaded into any simulation cloned from the same template. */
void ref_sim_copy_state(ref_sim *dst, const ref_sim *src);
size_t ref_sim_snapshot_size(const ref_sim *s);
void ref_sim_save(const ref_sim *s, void *buf);
void ref_sim_load(ref_sim *s, const void *buf);
void ref_sim_step(ref_sim *s, const ref_tick *tick);



#endif
