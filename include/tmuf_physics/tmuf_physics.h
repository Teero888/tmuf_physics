#ifndef TMUF_PHYSICS_H
#define TMUF_PHYSICS_H

/*
 * tmuf_physics: TrackMania United Forever physics with bit-exact parity to
 * the original game.
 *
 * Usage, in the manner of ddnet_physics:
 *
 *   tmuf_packs *packs = tmuf_packs_open("…/Packs", err, sizeof err);
 *   tmuf_track *track = tmuf_track_load(packs, map, map_size, NULL, err, sizeof err);
 *
 *   tmuf_world world = tmuf_world_empty();
 *   tmuf_world_init(&world, track);
 *   world.input = (tmuf_input){.accelerate = 1};
 *   tmuf_world_tick(&world);           // one 10 ms tick
 *   // world.body->state.pos, world.car->wheels[i], world.race->finish_time, ...
 *
 *   tmuf_world copy = tmuf_world_empty();
 *   tmuf_world_copy(&copy, &world);    // cheap: reuses copy's memory
 *
 *   tmuf_world_free(&copy);
 *   tmuf_world_free(&world);
 *   tmuf_track_free(track);
 *   tmuf_packs_close(packs);
 *
 * Threading: no global mutable state. Packs and tracks are immutable once
 * loaded and can be shared by any number of threads; a world belongs to one
 * thread at a time.
 *
 * Time: a world starts at time 0 on the start block, held for the countdown;
 * each tick advances TMUF_TICK_MS and the race starts on the tick that
 * reaches TMUF_RACE_START_MS. Race time = time - TMUF_RACE_START_MS.
 */

#include <stddef.h>
#include <stdint.h>

#if defined(TMUF_PHYSICS_BUILD_SHARED) && defined(_WIN32)
#define TMUF_API __declspec(dllexport)
#elif defined(TMUF_PHYSICS_USE_SHARED) && defined(_WIN32)
#define TMUF_API __declspec(dllimport)
#elif defined(TMUF_PHYSICS_BUILD_SHARED)
#define TMUF_API __attribute__((visibility("default")))
#else
#define TMUF_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define TMUF_PHYSICS_VERSION_MAJOR 0
#define TMUF_PHYSICS_VERSION_MINOR 2

#define TMUF_TICK_MS 10u
#define TMUF_RACE_START_MS 2600u

typedef enum tmuf_backend {
  TMUF_BACKEND_REFERENCE = 0,
  TMUF_BACKEND_OPTIMIZED = 1,
} tmuf_backend;

TMUF_API const char *tmuf_version_string(void);

/* Backend compiled into this build of the library. */
TMUF_API tmuf_backend tmuf_backend_id(void);

/* Functions that can fail take an optional error buffer (err may be NULL)
   and return NULL or 0 on failure. */

/* ---- packs ---- */

typedef struct tmuf_packs tmuf_packs;

/* dir: the game's Packs directory (with packlist.dat). */
TMUF_API tmuf_packs *tmuf_packs_open(const char *dir, char *err, size_t err_size);
TMUF_API void tmuf_packs_close(tmuf_packs *packs);

/* ---- tracks: everything about a map that does not change while driving ---- */

typedef struct tmuf_track tmuf_track;

typedef struct tmuf_track_options {
  const char *vehicle; /* vehicle id; NULL: the map's, else the environment's car */
  uint32_t seed;       /* validation seed (tmuf_replay_seed), 0 for none */
} tmuf_track_options;

/* map: .Challenge.Gbx bytes (copied). options may be NULL. The packs must
   outlive the track. Takes around a second (decoding the blocks). */
TMUF_API tmuf_track *tmuf_track_load(const tmuf_packs *packs, const void *map, size_t size,
                                     const tmuf_track_options *options, char *err, size_t err_size);
TMUF_API void tmuf_track_free(tmuf_track *track);

TMUF_API const char *tmuf_track_name(const tmuf_track *track);
TMUF_API const char *tmuf_track_environment(const tmuf_track *track); /* collection: Stadium, Alpine, ... */
TMUF_API const char *tmuf_track_vehicle(const tmuf_track *track);     /* the car it runs */
TMUF_API uint32_t tmuf_track_checkpoints(const tmuf_track *track);    /* per lap, without the finish */
TMUF_API uint32_t tmuf_track_laps(const tmuf_track *track);

/* Static triangles in world space: every surface of the map's blocks and
   decoration (also ones the car never touches, e.g. editor helpers). */
typedef struct tmuf_triangle {
  float v[3][3];
  uint32_t block; /* the map block that placed it, or a tag with the top bit set */
} tmuf_triangle;

TMUF_API uint32_t tmuf_track_triangles(const tmuf_track *track, const tmuf_triangle **triangles);

/* ---- the physics state: the game's own structures ---- *
 *
 * Matrices are row-major (m[row][col]) and a local vector v maps to m * v;
 * quaternions are (w, x, y, z). Speeds are m/s, times ms. These are the
 * structures the simulation works on, not copies. */

#define TMUF_CAR_MAX_WHEELS 4

struct tmuf_collision_tree; /* the car's collision trees (internal) */
struct tmuf_car_def;        /* the car's definition (internal) */
struct tmuf_vehicle_tuning; /* the car's tunings (internal) */
struct tmuf_scene_water;    /* the track's water (internal) */

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

/* CTrackManiaRace: checkpoint slots and the respawn location */
typedef struct tmuf_race {
  int has_spawn;
  tmuf_iso4 current, previous; /* CTrackManiaPlayerInfo spawn locations */
  uint32_t checkpoint_count, laps, lap_checkpoints, completed_laps, checkpoints_passed;
  int completed;
  uint32_t finish_time; /* race time of the finish, ms */
  uint32_t respawns;    /* respawns done */
  uint8_t *passed; /* checkpoint_count + 1 slots (the last: finish) */
  /* per scene corpus */
  int32_t *slot; /* checkpoint slot, -1 if none */
  uint8_t *role, *respawn_current;
  tmuf_iso4 *spawn;
} tmuf_race;

/* ---- worlds: one car driving a track ---- */

/* One tick of input, as the game reads it. */
typedef struct tmuf_input {
  uint8_t accelerate; /* 0 or 1 */
  uint8_t brake;      /* 0 or 1 */
  uint8_t respawn;    /* 1: respawn at the last checkpoint */
  int32_t steer;      /* -65536 (full left) .. 65536 (full right); keys steer +-65536 */
} tmuf_input;

typedef struct tmuf_world_state tmuf_world_state; /* owns the structures below */

typedef struct tmuf_world {
  const tmuf_track *track;
  uint32_t tick;    /* ticks simulated: the time is tick * TMUF_TICK_MS */
  tmuf_input input; /* used by the next tmuf_world_tick */
  tmuf_dyna *body;  /* the car's rigid body (CHmsDyna); body->state is its state */
  tmuf_car *car;    /* the car (CSceneVehicleCar) */
  tmuf_race *race;  /* checkpoints, laps, finish and respawn (CTrackManiaRace) */
  tmuf_world_state *state;
} tmuf_world;

TMUF_API tmuf_world tmuf_world_empty(void);
/* The car at time 0 on the track's start. world must be empty or freed. */
TMUF_API int tmuf_world_init(tmuf_world *world, const tmuf_track *track);
/* to becomes an exact copy of from. Cheap when to already holds a world on
   the same track (its memory is reused); to may also be empty. */
TMUF_API int tmuf_world_copy(tmuf_world *to, const tmuf_world *from);
/* One tick with world->input. */
TMUF_API void tmuf_world_tick(tmuf_world *world);
TMUF_API void tmuf_world_free(tmuf_world *world);

/* ---- replays ---- */

typedef struct tmuf_replay tmuf_replay;

/* Copies what it needs; data may be freed afterwards. */
TMUF_API tmuf_replay *tmuf_replay_load(const void *data, size_t size, char *err, size_t err_size);
TMUF_API void tmuf_replay_free(tmuf_replay *replay);

/* The embedded map (.Challenge.Gbx bytes, owned by the replay). */
TMUF_API const void *tmuf_replay_map(const tmuf_replay *replay, size_t *size);
TMUF_API const char *tmuf_replay_vehicle(const tmuf_replay *replay); /* "" if none */
/* Seed that turns the spawn by a tiny yaw in validation runs (0: none). */
TMUF_API uint32_t tmuf_replay_seed(const tmuf_replay *replay);
/* Recorded race time in ms, UINT32_MAX if the ghost did not finish. */
TMUF_API uint32_t tmuf_replay_race_time(const tmuf_replay *replay);
/* The ghost's input for every tick from time 0: inputs[i] drives tick i.
   Returns the count; the array is owned by the replay. */
TMUF_API uint32_t tmuf_replay_inputs(const tmuf_replay *replay, const tmuf_input **inputs);

#ifdef __cplusplus
}
#endif

#endif /* TMUF_PHYSICS_H */
