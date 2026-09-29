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
 *   // world.sim.body.state.pos, world.sim.car.wheels[i], world.sim.race.finish_time, ...
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

#include <tmuf_physics/state.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TMUF_PHYSICS_VERSION_MAJOR 0
#define TMUF_PHYSICS_VERSION_MINOR 3

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

enum {
  /* keep the world-space triangle list for tmuf_track_triangles (large: every
     static triangle of the map, up to gigabytes on maps with 10k+ blocks) */
  TMUF_TRACK_TRIANGLES = 1u << 0,
  /* score stunts on every map (world.sim.race.stunts); by default only on
     Stunts maps, the only mode that uses the score (the game also records
     it in Race mode ghosts, where nothing checks it) */
  TMUF_TRACK_STUNTS = 1u << 1,
};

typedef struct tmuf_track_options {
  const char *vehicle; /* vehicle id; NULL: the map's, else the environment's car */
  uint32_t seed;       /* validation seed (tmuf_replay_seed), 0 for none */
  uint32_t laps;       /* laps to race (tmuf_replay_laps), 0: the map's */
  uint32_t flags;      /* TMUF_TRACK_* */
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
   decoration (also ones the car never touches, e.g. editor helpers). Only
   for tracks loaded with TMUF_TRACK_TRIANGLES, else 0. The collision itself
   is tmuf_track_sim(track)->world (records reference shared surfaces). */
typedef struct tmuf_triangle {
  float v[3][3];
  uint32_t block; /* the map block that placed it, or a tag with the top bit set */
} tmuf_triangle;

TMUF_API uint32_t tmuf_track_triangles(const tmuf_track *track, const tmuf_triangle **triangles);

/* The track's simulation at time 0, which every world starts as a copy of:
   its static collision (world, triggers), water, race tables and the car's
   definition are the ones all worlds on the track share. */
TMUF_API const tmuf_sim *tmuf_track_sim(const tmuf_track *track);

/* ---- worlds: one car driving a track ---- */

/* One tick of input, as the game reads it. */
typedef struct tmuf_input {
  uint8_t accelerate; /* 0 or 1 */
  uint8_t brake;      /* 0 or 1 */
  uint8_t respawn;    /* 1: respawn at the last checkpoint */
  uint8_t input_event; /* 1: a driving key or axis event this tick that left the input as it was
                          (e.g. a second steering key held); a stunt in the air is only a master
                          jump without input events, and a change of the fields above is one */
  int32_t steer;      /* -65536 (full left) .. 65536 (full right); keys steer +-65536 */
} tmuf_input;

typedef struct tmuf_world {
  const tmuf_track *track;
  uint32_t tick;    /* ticks simulated: the time is tick * TMUF_TICK_MS */
  tmuf_input input; /* used by the next tmuf_world_tick */
  tmuf_sim sim;     /* the simulation itself (tmuf_physics/state.h): sim.body is the
                       car's rigid body, sim.car the car, sim.race the race,
                       sim.world and sim.triggers the track's static collision */
} tmuf_world;

TMUF_API tmuf_world tmuf_world_empty(void);
/* The car at time 0 on the track's start. world must be empty or freed. */
TMUF_API int tmuf_world_init(tmuf_world *world, const tmuf_track *track);
/* to becomes an exact copy of from. Cheap when to already holds a world on
   the same track (its memory is reused); to may also be empty. A world holds
   pointers into itself: copy it with this, never by assignment. */
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
/* Laps of the race settings the replay was driven with (0: none; pass it
   as tmuf_track_options.laps: validation races that many laps). */
TMUF_API uint32_t tmuf_replay_laps(const tmuf_replay *replay);
/* Seed that turns the spawn by a tiny yaw in validation runs (0: none). */
TMUF_API uint32_t tmuf_replay_seed(const tmuf_replay *replay);
/* Recorded race time in ms, UINT32_MAX if the ghost did not finish. */
TMUF_API uint32_t tmuf_replay_race_time(const tmuf_replay *replay);
/* The ghost's recorded respawns and stunt score (UINT32_MAX if not recorded). */
TMUF_API uint32_t tmuf_replay_respawns(const tmuf_replay *replay);
TMUF_API uint32_t tmuf_replay_stunt_score(const tmuf_replay *replay);
/* The ghost's recorded checkpoint crossings (finish lines included): race
   time and stunt score at each (arrays owned by the replay). Returns the
   count, 0 if not recorded. */
TMUF_API uint32_t tmuf_replay_checkpoints(const tmuf_replay *replay, const uint32_t **times, const uint32_t **scores);
/* The ghost's input for every tick from time 0: inputs[i] drives tick i.
   Returns the count; the array is owned by the replay. */
TMUF_API uint32_t tmuf_replay_inputs(const tmuf_replay *replay, const tmuf_input **inputs);

/* ---- writing replays ---- */

typedef struct tmuf_replay_write_options {
  const char *login;    /* the ghost's player login; NULL: "tmuf_physics" */
  const char *nickname; /* NULL: the login */
} tmuf_replay_write_options;

/* A .Replay.Gbx of the run inputs[0..count) drive on track (inputs[i] drives
   tick i, as tmuf_replay_inputs gives them), which the game plays and its
   validator accepts. The run is simulated: it ends at the finish or after
   the last input, and the replay records the map, the inputs, the race time
   (none if the run does not finish), respawns, stunt score, checkpoint times
   and the car's samples. The track's seed and laps (tmuf_track_options) are the
   run's validation seed and race settings.
   A replay has no input before the race starts: inputs[i] for
   i < TMUF_RACE_START_MS / TMUF_TICK_MS - 1 are ignored (the car is held
   during the countdown; the run starts with the input of that tick), so
   count must be larger. options may be NULL.
   On Stunts maps the validator also checks the stunt score, which the
   replay records as the run scored it (on other maps 0, unless the track
   was loaded with TMUF_TRACK_STUNTS).
   Returns the file's bytes (free them with tmuf_free) and their count in
   *size, or NULL. */
TMUF_API void *tmuf_replay_write(const tmuf_track *track, const tmuf_input *inputs, uint32_t count,
                                 const tmuf_replay_write_options *options, size_t *size, char *err,
                                 size_t err_size);
/* Frees memory the library returned (tmuf_replay_write). */
TMUF_API void tmuf_free(void *p);

#ifdef __cplusplus
}
#endif

#endif /* TMUF_PHYSICS_H */
