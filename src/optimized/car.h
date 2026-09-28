#ifndef TMUF_REFERENCE_CAR_H
#define TMUF_REFERENCE_CAR_H

/* CSceneVehicleCar: wheels, engine, handling models and contact handling.
   The car talks to its rigid body through the local-space wrappers of
   CHmsItem (forces, speeds and impulses in the car frame). */

#include <stdint.h>

#include "common/scene.h"
#include "common/vehicle_tuning.h"
#include "optimized/collide.h"
#include "optimized/dyna.h"
#include "optimized/gm.h"

#define MAT_CONCRETE TMUF_MAT_CONCRETE
#define MAT_ICE TMUF_MAT_ICE
#define MAT_METAL TMUF_MAT_METAL
#define MAT_DIRT TMUF_MAT_DIRT
#define MAT_TURBO TMUF_MAT_TURBO
#define MAT_RUBBER TMUF_MAT_RUBBER
#define MAT_SLIDING_RUBBER TMUF_MAT_SLIDING_RUBBER
#define MAT_TEST TMUF_MAT_TEST
#define MAT_WATER TMUF_MAT_WATER
#define MAT_GOLF_BALL TMUF_MAT_GOLF_BALL
#define MAT_GOLF_WALL TMUF_MAT_GOLF_WALL
#define MAT_GOLF_GROUND TMUF_MAT_GOLF_GROUND
#define MAT_TURBO2 TMUF_MAT_TURBO2
#define MAT_FREE_WHEELING TMUF_MAT_FREE_WHEELING
#define MAT_TURBO_ROULETTE TMUF_MAT_TURBO_ROULETTE
#define MAT_COUNT TMUF_MAT_COUNT
#define HANDLING_STANDARD TMUF_HANDLING_STANDARD
#define HANDLING_LATERAL TMUF_HANDLING_LATERAL
#define HANDLING_RADIUS TMUF_HANDLING_RADIUS_STEERING
#define HANDLING_SLIP TMUF_HANDLING_SLIP_RESPONSE
#define HANDLING_GEARED TMUF_HANDLING_GEARED_DRIVE
#define WHEEL_FORCE_SPRING TMUF_WHEEL_FORCE_DIRECT_SPRING
#define WHEEL_FORCE_FOLLOW TMUF_WHEEL_FORCE_FOLLOW_ABSORB
#define WHEEL_FORCE_FOLLOW_IMPULSE TMUF_WHEEL_FORCE_FOLLOW_ABSORB_IMPULSE
#define TURBO_NONE TMUF_TURBO_NONE
#define TURBO_DIRECT TMUF_TURBO_DIRECT
#define TURBO_ROULETTE TMUF_TURBO_ROULETTE
#define ENGINE_STEADY TMUF_ENGINE_STEADY
#define ENGINE_GEAR_SHIFT TMUF_ENGINE_GEAR_SHIFT
#define ENGINE_FORWARD TMUF_ENGINE_FORWARD
#define ENGINE_REVERSE TMUF_ENGINE_REVERSE
#define ENGINE_BURNOUT TMUF_ENGINE_BURNOUT
#define BURNOUT_NONE TMUF_BURNOUT_NONE
#define BURNOUT_SPIN TMUF_BURNOUT_SPIN
#define BURNOUT_CIRCLE TMUF_BURNOUT_CIRCLE
#define BURNOUT_EXIT TMUF_BURNOUT_EXIT
#define IMPACT_NONE TMUF_IMPACT_NONE
#define IMPACT_LOW TMUF_IMPACT_LOW
#define IMPACT_HIGH TMUF_IMPACT_HIGH
#define RADIUS_IDLE TMUF_RADIUS_IDLE
#define RADIUS_DIRECT TMUF_RADIUS_DIRECT
#define RADIUS_CAPTURED TMUF_RADIUS_CAPTURED

typedef tmuf_car_material car_material;
typedef tmuf_car_fake_texture car_fake_texture;

typedef tmuf_car_spring car_spring;

typedef tmuf_car_wheel car_wheel;

/* CHmsPhysicalContact, as seen by the car */
typedef struct car_contact {
  const void *tree;  /* contact tree of the car (NULL for fake contacts) */
  int has_peer;
  uint32_t peer_corpus;
  gm_vec3 peer_z;    /* peer location Z axis (GetDir), world */
  uint8_t own_material, peer_material;
  gm_vec3 normal;    /* local impulse normal */
  gm_vec3 point;     /* local contact point */
  gm_vec3 speed;     /* local relative speed */
  gm_vec3 replacement;
  int accepted;
} car_contact;

#define CAR_MAX_WHEELS TMUF_CAR_MAX_WHEELS

typedef tmuf_car_def car_def;

typedef tmuf_car car;

/* Build the car from its definition and bind it to its body. */
void car_init(car *c, car_def *def, dyna *body);
/* CSceneVehicleCar::VehicleReset */
void car_reset(car *c);
/* CSceneVehicleCar::UpdateParamsFromTuning; also installs the dyna params */
void car_update_params(car *c);
/* The dyna parameters the car installs on a respawn (BuildDynaParameters). */
void car_default_dyna_params(const car *c, dyna_params *p);
void car_begin_race(car *c);
void car_set_controls(car *c, float gate_a, float gate_b, float steering);
void car_establish_spawn(car *c, const gm_iso4 *spawn);

/* CHmsItem callbacks */
void car_compute_forces(car *c, float dt);
void car_absorb_contact(car *c, car_contact *contact);
void car_after_contacts(car *c);

/* CHmsCorpus::RefreshFromSolid for the car body */
void car_refresh_dyna_params(car *c);

/* Wheel tree locations after a surface update (UpdateSurface) */
void car_update_wheel_trees(car *c);

float tmuf_curve_eval(const tmuf_curve *curve, float x);

#endif
