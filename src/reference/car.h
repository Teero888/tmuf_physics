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

/* GmSpring<float> */
typedef struct car_spring {
  float stiffness, damping, value, velocity;
} car_spring;

/* CSceneVehicleCar::SSimulationWheel (simulation part) */
typedef struct car_wheel {
  int kills_lateral_speed;
  int front;
  float rolling_radius;
  ref_mtree *tree;           /* collision tree of the wheel surface */
  gm_iso4 rest_iso, cur_iso; /* SSurfaceHandler */
  gm_vec3 force_point;
  /* SRealTimeState */
  float damper_absorb, damper_velocity, max_replacement_y;
  gm_mat3 visual_rotation, contact_frame;
  gm_vec3 latest_contact_point;
  float angular_speed;
  int contact;
  uint8_t contact_material;
  int slipping;
  gm_vec3 peer_z_local;
  uint32_t peer_corpus;
  uint32_t normal_samples;
  gm_vec3 normal_sum;
  float spin_angle, steer_angle, steer_target;
  int rejected;
  gm_vec3 rejected_point;
} car_wheel;

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

#define CAR_MAX_WHEELS 4

typedef struct car_def {
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

typedef struct car {
  car_def *def;
  tmuf_vehicle_tuning *t; /* &def->tuning (curves change interpolation) */
  dyna *body;
  uint32_t tick; /* timer tick time, ms */

  /* dyna params derived from the solid physical parameters */
  float solid_mass;
  gm_vec3 solid_com;
  float contact_feedback_scale, linear_fluid_friction;

  car_wheel wheels[CAR_MAX_WHEELS];
  uint32_t wheel_count;

  struct {
    float gate_a, gate_b, steering, special_gate, current_steering;
    int forced_low_speed_friction;
    int special_mode;
    int no_ground_friction_guard;
  } controls;
  struct {
    car_spring forward, side;
    float ramp0, ramp1, drive_limit, velocity_limit, value_limit, surface;
  } feedback;
  float linear_speed_cap, reverse_gear_speed_threshold;
  struct {
    int update_wheel_visuals, integrate_wheels, integrate_engine, zero_horizontal_speed;
    int speed_blocked, speed_blocked2;
  } integration;
  struct {
    float input_max, low_feedback_gate_scale, low_feedback_friction_scale, low_feedback_force;
    float input_memory, target_input, slip_rpm_scale, shift_cooldown;
    int use_gate_b;
    int gear;
  } engine;
  struct {
    uint32_t roulette_origin;
    float progress, impulse_scale;
    uint32_t start_tick, end_tick;
    int type;
    uint32_t source_corpus;
    float type2_phase;
  } turbo;
  struct {
    int refresh_memory;
    uint32_t memory_tick;
    gm_vec3 memory_angular;
  } air;
  struct {
    int body_impact, front_impact, rear_impact, peak_rear, peak_front, peak_body;
    uint8_t last_body_material, last_wheel_material, peak_wheel_material, peak_body_material;
    int body_contact, lateral_slowdown_contact;
    uint32_t lateral_slowdown_tick, special_cooldown_until;
    float front_bucket, rear_bucket, body_bucket;
    uint32_t wheel_contact_count, body_contact_count;
    gm_vec3 body_point_sum, body_normal_sum;
  } contacts;
  struct {
    float steer_angle, previous_sign;
    int phase;
  } radius;
  struct {
    int active;
    uint32_t last_tick, start_tick, elapsed, steering_tick;
    int steering_slip;
  } slip;
  struct {
    int engine_state, burnout_phase, wheel_speed_override;
    gm_iso4 frame_iso;
    gm_vec3 scaled_force, burnout_center;
    float burnout_base_radius, burnout_target_radius;
    uint32_t burnout_start, burnout_exit_start;
    gm_vec3 burnout_normal;
    float burnout_direction;
    gm_vec3 local_speed;
    float active_steer_slowdown;
    int drive_speed_inhibited, input_window_exceeded, shift_down;
    float wheel_span;
  } geared;
  struct {
    gm_vec3 force, impulse;
  } acc;
  uint32_t last_forces_tick;
  int water_splash_events;
  gm_vec3 water_splash_speed;
  const tmuf_scene_water *water; /* the zone's water, NULL if none */
  /* frame state used by the race and replays */
  struct {
    float forward_speed, side_speed;
    int has_wheel_contact, has_body_contact;
  } frame;
} car;

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
