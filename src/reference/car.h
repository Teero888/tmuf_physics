#ifndef TMUF_REFERENCE_CAR_H
#define TMUF_REFERENCE_CAR_H

/* CSceneVehicleCar: wheels, engine, handling models and contact handling.
   The car talks to its rigid body through the local-space wrappers of
   CHmsItem (forces, speeds and impulses in the car frame). */

#include <stdint.h>

#include "common/scene.h"
#include "common/vehicle_tuning.h"
#include "reference/collide.h"
#include "reference/dyna.h"
#include "reference/gm.h"

enum {
  MAT_CONCRETE = 0,
  MAT_ICE = 3,
  MAT_METAL = 4,
  MAT_DIRT = 6,
  MAT_TURBO = 7,
  MAT_RUBBER = 9,
  MAT_SLIDING_RUBBER = 10,
  MAT_TEST = 11,
  MAT_WATER = 13,
  MAT_GOLF_BALL = 23,
  MAT_GOLF_WALL = 24,
  MAT_GOLF_GROUND = 25,
  MAT_TURBO2 = 26,
  MAT_FREE_WHEELING = 29,
  MAT_TURBO_ROULETTE = 30,
  MAT_COUNT = 31
};

enum { HANDLING_STANDARD = 0, HANDLING_LATERAL = 1, HANDLING_RADIUS = 3, HANDLING_SLIP = 4, HANDLING_GEARED = 5 };
enum { WHEEL_FORCE_SPRING = 0, WHEEL_FORCE_FOLLOW = 1, WHEEL_FORCE_FOLLOW_IMPULSE = 2 };
enum { TURBO_NONE = 0, TURBO_DIRECT = 1, TURBO_ROULETTE = 2 };
enum { ENGINE_STEADY = 0, ENGINE_GEAR_SHIFT = 1, ENGINE_FORWARD = 2, ENGINE_REVERSE = 3, ENGINE_BURNOUT = 4 };
enum { BURNOUT_NONE = 0, BURNOUT_SPIN = 1, BURNOUT_CIRCLE = 2, BURNOUT_EXIT = 3 };
enum { IMPACT_NONE = 0, IMPACT_LOW = 1, IMPACT_HIGH = 2 };
enum { RADIUS_IDLE = 0, RADIUS_DIRECT = 1, RADIUS_CAPTURED = 2 };

/* CSceneVehicleMaterial */
typedef struct car_material {
  float x, y, z, w; /* SBlendableVals */
  int fake_contact;  /* has the fake contact bitmap */
  float fake_period_x, fake_period_z, fake_speed_scale, fake_depth_max;
  float feedback_speed_divisor, feedback_scale;
  uint32_t natural_id;
} car_material;

/* Fake contact texture (8-bit samples, the first byte of each pixel). */
typedef struct car_fake_texture {
  uint32_t width, height, stride, bpp;
  const uint8_t *pixels;
} car_fake_texture;

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

typedef struct tmuf_car_def {
  tmuf_vehicle_tuning tuning;
  uint32_t wheel_count;
  struct {
    int kills_lateral_speed, front;
    ref_mtree *tree;
    gm_vec3 force_point; /* rest surface point in the car frame */
  } wheels[CAR_MAX_WHEELS];
  float linear_speed_cap, reverse_gear_speed_threshold;
  gm_box water_box;
  uint32_t material_count;
  car_material materials[MAT_COUNT];
  uint32_t material_remap[MAT_COUNT];
  car_fake_texture fake_texture;
  ref_mtree *root; /* collision tree */
} car_def;

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
