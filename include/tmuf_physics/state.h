#ifndef TMUF_PHYSICS_STATE_H
#define TMUF_PHYSICS_STATE_H

/*
 * The physics state: the game's own structures, exactly as the simulation
 * uses them (nothing here is a copy or a view).
 *
 * Matrices are row-major (m[row][col]) and a local vector v maps to m * v;
 * quaternions are (w, x, y, z). Speeds are m/s, times ms. Pointers inside a
 * tmuf_sim point into itself or into its track's shared, read-only data:
 * copy simulations with tmuf_world_copy, not by assignment.
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TMUF_MAX_GEARS 16
#define TMUF_MAX_CURVE_KEYS 64
#define TMUF_CAR_MAX_WHEELS 4

/* ---- math (Gm*) ---- */

typedef struct tmuf_vec3 {
  float x, y, z;
} tmuf_vec3;

typedef struct tmuf_quat {
  float w, x, y, z;
} tmuf_quat;

typedef struct tmuf_mat3 {
  float m[3][3];
} tmuf_mat3;

typedef struct tmuf_iso4 {
  tmuf_mat3 r;
  tmuf_vec3 t;
} tmuf_iso4;

typedef struct tmuf_box {
  tmuf_vec3 center, half;
} tmuf_box;

/* ---- constants ---- */

/* CPlugSurface geometry kinds */
enum { TMUF_SURFACE_SPHERE = 0, TMUF_SURFACE_ELLIPSOID = 1, TMUF_SURFACE_BOX = 6, TMUF_SURFACE_MESH = 7 };

/* EPlugSurfaceMaterialId (those the car treats specially) and the car's
   modes */
enum {
  TMUF_MAT_CONCRETE = 0,
  TMUF_MAT_ICE = 3,
  TMUF_MAT_METAL = 4,
  TMUF_MAT_DIRT = 6,
  TMUF_MAT_TURBO = 7,
  TMUF_MAT_RUBBER = 9,
  TMUF_MAT_SLIDING_RUBBER = 10,
  TMUF_MAT_TEST = 11,
  TMUF_MAT_WATER = 13,
  TMUF_MAT_GOLF_BALL = 23,
  TMUF_MAT_GOLF_WALL = 24,
  TMUF_MAT_GOLF_GROUND = 25,
  TMUF_MAT_TURBO2 = 26,
  TMUF_MAT_FREE_WHEELING = 29,
  TMUF_MAT_TURBO_ROULETTE = 30,
  TMUF_MAT_COUNT = 31
};

enum { TMUF_TURBO_NONE = 0, TMUF_TURBO_DIRECT = 1, TMUF_TURBO_ROULETTE = 2 };
enum { TMUF_ENGINE_STEADY = 0, TMUF_ENGINE_GEAR_SHIFT = 1, TMUF_ENGINE_FORWARD = 2, TMUF_ENGINE_REVERSE = 3, TMUF_ENGINE_BURNOUT = 4 };
enum { TMUF_BURNOUT_NONE = 0, TMUF_BURNOUT_SPIN = 1, TMUF_BURNOUT_CIRCLE = 2, TMUF_BURNOUT_EXIT = 3 };
enum { TMUF_IMPACT_NONE = 0, TMUF_IMPACT_LOW = 1, TMUF_IMPACT_HIGH = 2 };
enum { TMUF_RADIUS_IDLE = 0, TMUF_RADIUS_DIRECT = 1, TMUF_RADIUS_CAPTURED = 2 };

/* ---- vehicle tuning (CSceneVehicleCarTuning) ---- */

typedef struct tmuf_curve {
  int present;
  int constant; /* step interpolation (CFuncKeys mode 1), else linear */
  uint32_t count;
  float x[TMUF_MAX_CURVE_KEYS], y[TMUF_MAX_CURVE_KEYS];
} tmuf_curve;

typedef struct tmuf_vt_curves {
  tmuf_curve lateral_contact_slow_down_from_speed;
  tmuf_curve max_side_friction_from_speed;
  tmuf_curve rollover_lateral_from_speed;
  tmuf_curve rollover_lateral_coefficient_from_angle;
  tmuf_curve wheel_visual_steer_angle_from_speed;
  tmuf_curve steering_drive_torque_from_speed;
  tmuf_curve steer_slow_down_from_speed;
  tmuf_curve suspension_damper_absorb_modulation;
  tmuf_curve air_control_z_scale;
  tmuf_curve radius_steering_radius_from_speed;
  tmuf_curve radius_steering_max_friction_from_speed;
  tmuf_curve slip_response_accel_from_speed;
  tmuf_curve slip_response_slipping_accel_from_speed;
  tmuf_curve reverse_gear_accel_from_speed;
  tmuf_curve burnout_rollover_lateral_from_speed_ratio;
  tmuf_curve burnout_radius_from_speed;
  tmuf_curve burnout_lateral_speed_from_radius;
  tmuf_curve donut_rollover_from_speed;
  tmuf_curve burnout_rollover_from_speed;
  tmuf_curve splash_vertical_impulse;
  tmuf_curve splash_horizontal_impulse;
  tmuf_curve water_friction_from_speed;
  tmuf_curve surface_feedback;
  tmuf_curve vehicle_feedback_ramp1;
  tmuf_curve vehicle_feedback_ramp0;
  tmuf_curve vehicle_default30_to100;
} tmuf_vt_curves;

typedef struct tmuf_vt_visual_settings {
  float wheel_speed_base;
  float wheel_speed_scale;
} tmuf_vt_visual_settings;

typedef struct tmuf_vt_steering {
  float slew_rate;
  float assist_full_speed;
  float slow_down_scale;
} tmuf_vt_steering;

typedef struct tmuf_vt_suspension {
  float wheel_spring_coef;
  float wheel_damper_coef;
  float damper_modulation_max_absorb;
  float damper_modulation_min_absorb;
  float wheel_rest_damper_absorb;
  float wheel_static_spring_scale;
  float wheel_absorb_follow_coef;
} tmuf_vt_suspension;

typedef struct tmuf_vt_contact_response {
  float body_impact_feedback_high_threshold;
  float body_impact_feedback_low_threshold;
  float wheel_impact_feedback_high_threshold;
  float wheel_impact_feedback_low_threshold;
  float body_contact_tangent_limit_other;
  float body_contact_tangent_limit_metal;
  float body_contact_impulse_metal;
  float body_contact_impulse_other;
  float wheel_contact_impulse_other;
  float wheel_contact_impulse_metal;
  float point_impulse_angular_y_scale;
  float point_impulse_angular_scale;
  float point_impulse_angular_speed_max;
  float point_impulse_linear_speed_growth_limit_sq;
  float special_contact_impulse_magnitude;
  float special_solid_feedback_value;
  uint32_t single_material;
} tmuf_vt_contact_response;

typedef struct tmuf_vt_body_air_response {
  float solid_physical_mass;
  float solid_inertia_mass;
  float solid_inertia_box_size[3];
  float solid_center_z_half_extent_scale;
  float solid_center_y_offset;
  float solid_physical_response_coef_b;
  float airborne_solid_feedback0;
  float air_torque_linear_coef;
  float air_torque_quadratic_coef;
  float grounded_solid_feedback1;
  float airborne_solid_feedback1;
  float slope_adherence1_min;
  float slope_adherence1_max;
  float slope_adherence2_min;
  float slope_adherence2_max;
  uint32_t air_control_memory_tick_window;
  float air_control_y_switch_threshold;
} tmuf_vt_body_air_response;

typedef struct tmuf_vt_radius_steering {
  float steer_torque_speed_scale;
  float angular_damping_linear;
  float angular_damping_quadratic;
  float lateral_friction_linear;
  float lateral_friction_quadratic;
  float capture_exit_side_speed_max;
  float input_steer_radius_scale;
  float slipping_friction_scale;
  float captured_angle_rate;
  float captured_angle_radius_scale;
  float steer_angle_limit;
  float steer_angle_from_input_scale;
} tmuf_vt_radius_steering;

typedef struct tmuf_vt_slip_response {
  float slipping_accel_scale;
  uint32_t lateral_slow_down_tick_window;
  float rollover_torque_cap;
  uint32_t steering_memory_ticks;
  int slip_slowdown_enabled;
  uint32_t slip_slowdown_ticks;
  float longitudinal_torque_scale;
} tmuf_vt_slip_response;

typedef struct tmuf_vt_transmission {
  float reverse_speed_norm;
  float gear_speed_ratio[TMUF_MAX_GEARS];
  float upshift_threshold[TMUF_MAX_GEARS];
  float downshift_threshold[TMUF_MAX_GEARS];
  float rpm_wanted[TMUF_MAX_GEARS];
  float target_input_bias[TMUF_MAX_GEARS];
  float rpm_delta[TMUF_MAX_GEARS];
  uint32_t gear_count;
} tmuf_vt_transmission;

typedef struct tmuf_vt_burnout {
  float reverse_force_threshold;
  float donut_speed_high;
  float donut_speed_low;
  float lateral_correction_scale;
  float angle_torque_scale;
  float angular_damping_linear;
  float angle_return_quadratic;
  float tangent_angular_damping;
  float radius_correction_scale;
  float radius_correction_speed_scale;
  float radius_min;
  float tangent_speed_max;
  float angle_limit;
  float angle_limit_positive;
  float angle_limit_negative;
  uint32_t duration_ticks;
  float drive_fade_scale;
  float side_force_fade_scale;
  uint32_t exit_duration_ticks;
  float exit_accel_fade_scale;
  float exit_min_speed;
  float exit_steer_grip_scale;
  float exit_bonus_accel_scale;
  float wheel_angular_speed_override;
  float exit_side_friction_scale;
} tmuf_vt_burnout;

typedef struct tmuf_vt_engine_input {
  float engine_input_maximum;
  float burnout_hold_input_rise;
  float airborne_input_rise;
  float airborne_input_fall;
  float ground_input_brake;
  float ground_input_rise;
  float transition_input_rise;
  float ground_input_fall;
  float forward_transition_speed_high;
  float forward_transition_speed_low;
  float reverse_transition_speed_high;
  float reverse_transition_speed_low;
} tmuf_vt_engine_input;

typedef struct tmuf_vt_geared_drive {
  float forward_accel_base;
  float forward_accel_speed_coef;
  float forward_accel_cap_when_slipping;
  float forward_accel_cap;
  float speed_limit_force;
  float force_z_scale;
  float side_force_to_drive_torque_scale;
  float slipping_steer_torque_scale;
  float lateral_force_scale;
  float slipping_side_friction_scale;
  float side_friction_slip_blend;
  float drive_side_friction_slip_blend;
  float slip_ratio_scale;
  float current_force_torque_min;
  float current_torque_x_scale;
  float current_torque_z_scale;
  float per_slipping_wheel_accel_scale;
  float low_speed_b_slipping_grip_scale;
  float forward_accel_cap_when_slipping_reverse;
  float forward_accel_cap_reverse;
  float dirt_slide_side_force_scale;
  float dirt_slide_gate_scale;
  float dirt_slide_forward_force_scale;
  float dirt_slide_forward_gate_scale;
  tmuf_vt_transmission transmission;
  tmuf_vt_burnout burnout;
  tmuf_vt_engine_input input;
} tmuf_vt_geared_drive;

typedef struct tmuf_vt_water {
  float buoyancy_force;
  float splash_horizontal_speed_threshold;
  float splash_total_speed_threshold;
  float angular_linear_damping;
  float angular_speed_damping;
} tmuf_vt_water;

typedef struct tmuf_vt_turbo {
  float impulse_scale_a;
  float impulse_scale_b;
  uint32_t duration_a;
  uint32_t duration_b;
} tmuf_vt_turbo;

typedef struct tmuf_vt_feedback {
  float surface_base_rate;
  float force_divisor;
} tmuf_vt_feedback;

typedef struct tmuf_vehicle_tuning {
  float engine_speed_norm;
  float low_speed_friction_magnitude;
  float low_speed_linear_damping;
  uint32_t wheel_force_mode;
  uint32_t handling_model;
  tmuf_vt_visual_settings visual;
  tmuf_vt_steering steering;
  tmuf_vt_suspension suspension;
  tmuf_vt_contact_response contact_response;
  tmuf_vt_body_air_response body_air_response;
  tmuf_vt_radius_steering radius_steering;
  tmuf_vt_slip_response slip_response;
  tmuf_vt_geared_drive geared_drive;
  tmuf_vt_water water;
  tmuf_vt_turbo turbo;
  tmuf_vt_feedback feedback;
  tmuf_vt_curves curves;
} tmuf_vehicle_tuning;

enum { TMUF_WHEEL_FORCE_DIRECT_SPRING = 0, TMUF_WHEEL_FORCE_FOLLOW_ABSORB = 1, TMUF_WHEEL_FORCE_FOLLOW_ABSORB_IMPULSE = 2 };
enum {
  TMUF_HANDLING_STANDARD = 0,
  TMUF_HANDLING_LATERAL = 1,
  TMUF_HANDLING_RADIUS_STEERING = 3,
  TMUF_HANDLING_SLIP_RESPONSE = 4,
  TMUF_HANDLING_GEARED_DRIVE = 5
};

/* ---- the track's water (CSceneVehicleWaterZone) ---- */

/* CSceneVehicleWaterZone: where the car floats. A grid over the map's
   columns (1: water) and the water surface height. */
typedef struct tmuf_scene_water {
  int enabled;
  float cell_size[2], origin[2]; /* x, z */
  uint32_t dims[2];
  uint8_t outside;
  uint8_t *cells; /* dims[0] * dims[1], x fastest */
  float surface_height, secondary_cull_height;
} tmuf_scene_water;

/* ---- static collision (CHmsCollisionManager static group) ---- */

/* A GmSurf (CPlugSurface geometry) with its material table. */
typedef struct tmuf_surface {
  const void *key; /* surface node */
  uint8_t materials; /* TMUF_MATERIALS_* its material ids were resolved with */
  uint32_t type;
  tmuf_box geom_box;          /* archived bounds */
  uint16_t material;        /* primitive's local material */
  float params[6];          /* sphere radius / ellipsoid radii / box center, half */
  uint32_t vertex_count, triangle_count, cell_count;
  const float *vertices;    /* 3 floats each */
  const uint8_t *triangles; /* normal, plane distance, 3 indices, u16 material */
  const uint8_t *cells;     /* u32 subtree count, center, half, i32 triangle */
  uint32_t material_count;
  const uint8_t *material_ids; /* EPlugSurfaceMaterialId per local material */
  uint32_t pylon_raise; /* a pylon middle's mesh raised by this many squares: own
                           copy of vertices and triangles (CreateNewPylonMobil) */
  const float *tri_vertices; /* backend-private (optimized): per triangle its three
                                vertices, 9 floats */
} tmuf_surface;

typedef struct tmuf_static_cell {
  tmuf_box bounds;
  uint32_t subtree_count;
  int32_t record; /* index into records, -1 for a branch */
} tmuf_static_cell;

typedef struct tmuf_static_record {
  tmuf_box bounds;
  tmuf_iso4 iso;
  const tmuf_surface *surf;
  uint32_t tree_flags;
  uint32_t corpus;
} tmuf_static_record;

typedef struct tmuf_static_world {
  uint32_t surf_count, surf_cap;
  tmuf_surface **surfs;
  uint32_t record_count, record_cap;
  tmuf_static_record *records;
  uint32_t cell_count, cell_cap;
  tmuf_static_cell *cells;
} tmuf_static_world;

/* ---- collisions and the car's collision trees ---- */

/* SHmsPhysicalCollision */
typedef struct tmuf_collision {
  tmuf_vec3 separation, normal, point; /* impulse normal, contact point */
  uint16_t local_mat_a, local_mat_b;
  uint8_t mat_a, mat_b; /* EPlugSurfaceMaterialId */
  uint8_t sphere_merge_primary;
  tmuf_vec3 extra_negated;
  /* actors: moving body (A) and the static record or other body (B) */
  int32_t corpus_a, corpus_b; /* -1: the car; else a static corpus index */
  const void *tree_a, *tree_b;
  uint32_t group_pair;
} tmuf_collision;

typedef struct tmuf_collision_buffer {
  uint32_t count, cap;
  tmuf_collision *items;
} tmuf_collision_buffer;

/* A tree of the moving body (car): surfaces with local transforms. */
typedef struct tmuf_collision_tree {
  uint32_t flags; /* CPlugTree flags: 0x80 collision, 0x4 local transform */
  tmuf_iso4 local;
  const tmuf_surface *surf;
  tmuf_box box; /* CPlugTree::Box, in the parent frame */
  uint32_t child_count;
  struct tmuf_collision_tree **children;
  /* per-tree sphere contact buffer (SHmsSphereBufferContact) */
  tmuf_collision_buffer sphere;
  int queued;
} tmuf_collision_tree;

typedef struct tmuf_detect {
  const tmuf_static_world *world;
  tmuf_collision_buffer *out;
  tmuf_collision_tree *queued[64];
  uint32_t queued_count;
  uint32_t group_pair;
} tmuf_detect;

/* ---- the car's rigid body (CHmsDyna) ---- */

/* CHmsDyna::CHmsStateDyna, 180 bytes, the game's memory layout (the oracle
   dumps exactly this). */
typedef struct tmuf_dyna_state {
  tmuf_quat quat;
  tmuf_mat3 rot;
  tmuf_vec3 pos;
  tmuf_vec3 lin;       /* linear speed */
  tmuf_vec3 lin_corr;  /* linear correction speed */
  tmuf_vec3 ang;       /* angular speed */
  tmuf_vec3 force;
  tmuf_vec3 torque;
  tmuf_mat3 inv_inertia_world;
  uint32_t tweaked_valid;
  tmuf_vec3 tweaked_lin;
} tmuf_dyna_state;

typedef enum tmuf_dyna_type { TMUF_DYNA_LINEAR_ONLY = 0, TMUF_DYNA_FULL = 1, TMUF_DYNA_FROZEN = 2 } tmuf_dyna_type;

typedef struct tmuf_dyna_params {
  float mass;
  tmuf_mat3 inv_inertia_local; /* body inverse inertia ("bodyInertiaLike") */
  tmuf_vec3 com;               /* local center of mass */
  float max_step_distance;
  float linear_damping_scale, angular_damping_scale;
  float force_scale; /* scales the force fields (gravity) */
} tmuf_dyna_params;


typedef struct tmuf_dyna {
  tmuf_dyna_params params;
  tmuf_dyna_state state; /* currentState: the working state */
  tmuf_dyna_state write; /* writeState: GetLocation() */
  tmuf_dyna_state temp;  /* tempState */
  tmuf_dyna_type type;
  int active;
  int has_max_ang;
  float max_ang;
  uint32_t replacement_count, replacement_cap;
  tmuf_vec3 *replacements; /* pending collision replacements (grown, freed by dyna_free) */
} tmuf_dyna;

/* ---- the car (CSceneVehicleCar) ---- */

/* CSceneVehicleMaterial */
typedef struct tmuf_car_material {
  float x, y, z, w; /* SBlendableVals */
  int fake_contact;  /* has the fake contact bitmap */
  float fake_period_x, fake_period_z, fake_speed_scale, fake_depth_max;
  float feedback_speed_divisor, feedback_scale;
  uint32_t natural_id;
} tmuf_car_material;

/* Fake contact texture (8-bit samples, the first byte of each pixel). */
typedef struct tmuf_car_fake_texture {
  uint32_t width, height, stride, bpp;
  const uint8_t *pixels;
} tmuf_car_fake_texture;

/* GmSpring<float> */
typedef struct tmuf_car_spring {
  float stiffness, damping, value, velocity;
} tmuf_car_spring;

/* CSceneVehicleCar::SSimulationWheel (simulation part) */
typedef struct tmuf_car_wheel {
  int kills_lateral_speed;
  int front;
  float rolling_radius;
  struct tmuf_collision_tree *tree;           /* collision tree of the wheel surface */
  tmuf_iso4 rest_iso, cur_iso; /* SSurfaceHandler */
  tmuf_vec3 force_point;
  /* SRealTimeState */
  float damper_absorb, damper_velocity, max_replacement_y;
  tmuf_mat3 visual_rotation, contact_frame;
  tmuf_vec3 latest_contact_point;
  float angular_speed;
  int contact;
  uint8_t contact_material;
  int slipping;
  tmuf_vec3 peer_z_local;
  uint32_t peer_corpus;
  uint32_t normal_samples;
  tmuf_vec3 normal_sum;
  float spin_angle, steer_angle, steer_target;
  int rejected;
  tmuf_vec3 rejected_point;
} tmuf_car_wheel;

typedef struct tmuf_car {
  struct tmuf_car_def *def;
  struct tmuf_vehicle_tuning *t; /* &def->tuning (curves change interpolation) */
  struct tmuf_dyna *body;
  uint32_t tick; /* timer tick time, ms */

  /* dyna params derived from the solid physical parameters */
  float solid_mass;
  tmuf_vec3 solid_com;
  float contact_feedback_scale, linear_fluid_friction;

  tmuf_car_wheel wheels[TMUF_CAR_MAX_WHEELS];
  uint32_t wheel_count;

  struct {
    float gate_a, gate_b, steering, special_gate, current_steering;
    int forced_low_speed_friction;
    int special_mode;
    int no_ground_friction_guard;
  } controls;
  struct {
    tmuf_car_spring forward, side;
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
    tmuf_vec3 memory_angular;
  } air;
  struct {
    int body_impact, front_impact, rear_impact, peak_rear, peak_front, peak_body;
    uint8_t last_body_material, last_wheel_material, peak_wheel_material, peak_body_material;
    int body_contact, lateral_slowdown_contact;
    uint32_t lateral_slowdown_tick, special_cooldown_until;
    float front_bucket, rear_bucket, body_bucket;
    uint32_t wheel_contact_count, body_contact_count;
    tmuf_vec3 body_point_sum, body_normal_sum;
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
    tmuf_iso4 frame_iso;
    tmuf_vec3 scaled_force, burnout_center;
    float burnout_base_radius, burnout_target_radius;
    uint32_t burnout_start, burnout_exit_start;
    tmuf_vec3 burnout_normal;
    float burnout_direction;
    tmuf_vec3 local_speed;
    float active_steer_slowdown;
    int drive_speed_inhibited, input_window_exceeded, shift_down;
    float wheel_span;
  } geared;
  struct {
    tmuf_vec3 force, impulse;
  } acc;
  uint32_t last_forces_tick;
  int water_splash_events;
  tmuf_vec3 water_splash_speed;
  const struct tmuf_scene_water *water; /* the zone's water, NULL if none */
  /* frame state used by the race and replays */
  struct {
    float forward_speed, side_speed;
    int has_wheel_contact, has_body_contact;
  } frame;
} tmuf_car;

typedef struct tmuf_car_def {
  tmuf_vehicle_tuning tuning;
  uint32_t wheel_count;
  struct {
    int kills_lateral_speed, front;
    tmuf_collision_tree *tree;
    tmuf_vec3 force_point; /* rest surface point in the car frame */
  } wheels[TMUF_CAR_MAX_WHEELS];
  float linear_speed_cap, reverse_gear_speed_threshold;
  tmuf_box water_box;
  uint32_t material_count;
  tmuf_car_material materials[TMUF_MAT_COUNT];
  uint32_t material_remap[TMUF_MAT_COUNT];
  tmuf_car_fake_texture fake_texture;
  tmuf_collision_tree *root; /* collision tree */
} tmuf_car_def;

/* ---- the race (CTrackManiaRace) ---- */

/* CTrackManiaRace: checkpoint slots and the respawn location */
typedef struct tmuf_race {
  int has_spawn;
  tmuf_iso4 current, previous; /* CTrackManiaPlayerInfo spawn locations */
  uint32_t checkpoint_count, laps, lap_checkpoints, completed_laps, checkpoints_passed;
  int completed;
  uint32_t finish_time; /* race time of the finish, ms */
  uint32_t respawns;    /* respawns done */
  /* race time (ms) of every checkpoint taken, in order, the finish line of
     each lap included: checkpoint_time_count entries (the ghost's
     checkpoint list; the array grows as the race goes) */
  uint32_t *checkpoint_times;
  uint32_t checkpoint_time_count, checkpoint_time_cap;
  uint8_t *passed; /* checkpoint_count + 1 slots (the last: finish) */
  /* per scene corpus */
  int32_t *slot; /* checkpoint slot, -1 if none */
  uint8_t *role, *respawn_current;
  tmuf_iso4 *spawn;
} tmuf_race;

/* ---- the simulation ---- */

/* The simulation of one car on one track (the world's state). */
typedef struct tmuf_sim {
  tmuf_static_world world;     /* static corpora of group 4 (the game's static octree) */
  tmuf_static_world triggers;  /* race triggers (group 1) */
  tmuf_static_world nonstatic; /* non-static corpora of group 4 (decoration items without the static flag) */
  tmuf_race race;
  tmuf_scene_water water; /* copy of the scene's (cells owned here) */
  tmuf_car_def def;
  tmuf_car car;
  tmuf_dyna body;
  tmuf_collision_buffer buf;
  tmuf_detect det;
  uint32_t tree_count;
  tmuf_collision_tree *trees;
  tmuf_collision_tree **child_ptrs;
  tmuf_iso4 *corpus_iso;
  uint32_t corpus_count;
  float gravity_y, linear_damping, angular_damping;
  uint32_t tick_ms, period_ms;
  int first_step;
  uint32_t substeps; /* of the last step */
  int shared; /* a clone: the static worlds, race tables and water belong to the template */
} tmuf_sim;

#ifdef __cplusplus
}
#endif

#endif /* TMUF_PHYSICS_STATE_H */
