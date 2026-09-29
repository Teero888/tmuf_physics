#include "common/api_common.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/controls.h"

void tmuf_set_error(char *err, size_t err_size, const char *fmt, ...) {
  if (!err || !err_size)
    return;
  va_list ap;
  va_start(ap, fmt);
  vsnprintf(err, err_size, fmt, ap);
  va_end(ap);
}

/* ---- packs ---- */

tmuf_packs *tmuf_packs_open(const char *dir, char *err, size_t err_size) {
  tmuf_packs *p = calloc(1, sizeof *p);
  if (!p) {
    tmuf_set_error(err, err_size, "out of memory");
    return NULL;
  }
  char e[512] = "";
  if (!tmuf_packset_open(&p->set, dir, e, sizeof e)) {
    tmuf_set_error(err, err_size, "%s", e);
    free(p);
    return NULL;
  }
  return p;
}

void tmuf_packs_close(tmuf_packs *p) {
  if (!p)
    return;
  tmuf_packset_close(&p->set);
  free(p);
}

void *tmuf_packs_read(const tmuf_packs *packs, const char *path, size_t *size) {
  if (size)
    *size = 0;
  if (!packs || !path)
    return NULL;
  const tmuf_pack_ref ref = tmuf_packset_find(&packs->set, path);
  if (ref.pack < 0)
    return NULL;
  uint8_t *data = NULL;
  size_t n = 0;
  if (!tmuf_pack_extract(&packs->set.packs[ref.pack], ref.file, &data, &n))
    return NULL;
  if (size)
    *size = n;
  return data;
}

/* ---- replays ---- */

tmuf_replay *tmuf_replay_load(const void *data, size_t size, char *err, size_t err_size) {
  tmuf_replay *r = calloc(1, sizeof *r);
  if (!r || !(r->data = malloc(size ? size : 1))) {
    free(r);
    tmuf_set_error(err, err_size, "out of memory");
    return NULL;
  }
  memcpy(r->data, data, size);
  tmuf_arena_init(&r->arena);
  char e[512] = "";
  if (!tmuf_replay_parse(r->data, size, &r->arena, &r->file, e, sizeof e) || !r->file.challenge ||
      r->file.ghost_count == 0) {
    tmuf_set_error(err, err_size, "replay: %s", e[0] ? e : "no map or ghost");
    tmuf_replay_free(r);
    return NULL;
  }
  r->ghost = r->file.ghosts[0];
  if (r->ghost->has_inputs) {
    tmuf_control_tick *ticks = NULL;
    uint32_t n = tmuf_control_ticks(r->ghost, &ticks);
    r->inputs = calloc(n ? n : 1, sizeof *r->inputs);
    if (!r->inputs) {
      free(ticks);
      tmuf_set_error(err, err_size, "out of memory");
      tmuf_replay_free(r);
      return NULL;
    }
    for (uint32_t i = 0; i < n; i++) {
      r->inputs[i].accelerate = ticks[i].accelerate;
      r->inputs[i].brake = ticks[i].brake;
      r->inputs[i].steer = ticks[i].steer;
      r->inputs[i].respawn = ticks[i].respawns != 0;
      r->inputs[i].input_event = ticks[i].input_event;
    }
    r->input_count = n;
    free(ticks);
  }
  return r;
}

void tmuf_replay_free(tmuf_replay *r) {
  if (!r)
    return;
  free(r->inputs);
  tmuf_arena_free(&r->arena);
  free(r->data);
  free(r);
}

const void *tmuf_replay_map(const tmuf_replay *r, size_t *size) {
  if (size)
    *size = r->file.challenge_size;
  return r->file.challenge;
}

const char *tmuf_replay_vehicle(const tmuf_replay *r) { return r->ghost->vehicle[0] ? r->ghost->vehicle[0] : ""; }

uint32_t tmuf_replay_laps(const tmuf_replay *r) { return r->ghost->settings_laps; }

uint32_t tmuf_replay_seed(const tmuf_replay *r) {
  return r->ghost->has_validation_seed ? r->ghost->validation_seed : 0u;
}

uint32_t tmuf_replay_race_time(const tmuf_replay *r) {
  return r->ghost->has_race_time ? r->ghost->race_time : UINT32_MAX;
}

uint32_t tmuf_replay_respawns(const tmuf_replay *r) {
  return r->ghost->has_respawns ? r->ghost->respawns : UINT32_MAX;
}

uint32_t tmuf_replay_stunt_score(const tmuf_replay *r) {
  return r->ghost->has_stunt_score ? r->ghost->stunt_score : UINT32_MAX;
}

uint32_t tmuf_replay_checkpoints(const tmuf_replay *r, const uint32_t **times, const uint32_t **scores) {
  if (times)
    *times = r->ghost->checkpoint_times;
  if (scores)
    *scores = r->ghost->checkpoint_scores;
  return r->ghost->checkpoint_count;
}

uint32_t tmuf_replay_inputs(const tmuf_replay *r, const tmuf_input **inputs) {
  if (inputs)
    *inputs = r->inputs;
  return r->input_count;
}

/* ---- tracks (backend independent part) ---- */

int tmuf_track_base_load(tmuf_track_base *b, const tmuf_packs *packs, const void *map, size_t size,
                         const tmuf_track_options *options, char *err, size_t err_size) {
  memset(b, 0, sizeof *b);
  tmuf_arena_init(&b->arena);
  if (!(b->map_data = malloc(size ? size : 1))) {
    tmuf_set_error(err, err_size, "out of memory");
    return 0;
  }
  memcpy(b->map_data, map, size);
  b->map_size = size;
  b->seed = options ? options->seed : 0;
  char e[600] = "";
  if (!tmuf_challenge_parse(b->map_data, size, &b->arena, &b->map, e, sizeof e)) {
    tmuf_set_error(err, err_size, "map: %s", e);
    return 0;
  }
  const unsigned scene_flags = (options && (options->flags & TMUF_TRACK_TRIANGLES) ? TMUF_SCENE_TRIANGLES : 0u) |
                               (options && (options->flags & TMUF_TRACK_VISUALS) ? TMUF_SCENE_VISUALS : 0u);
  if (!tmuf_scene_build(&b->scene, &packs->set, &b->map, scene_flags)) {
    tmuf_set_error(err, err_size, "scene: %s", b->scene.error);
    return 0;
  }
  /* the car: asked for, else the map's, else the environment's; a vehicle
     the packs lack (custom ids) runs as the environment's car */
  const char *name = options && options->vehicle && options->vehicle[0] ? options->vehicle
                     : b->map.vehicle[0] && b->map.vehicle[0][0]      ? b->map.vehicle[0]
                                                                      : b->scene.default_vehicle;
  if (!name || !tmuf_vehicle_load(&b->vehicle, &b->scene.assets, name, e, sizeof e)) {
    name = b->scene.default_vehicle;
    if (!name || !tmuf_vehicle_load(&b->vehicle, &b->scene.assets, name, e, sizeof e)) {
      tmuf_set_error(err, err_size, "vehicle: %s", e);
      return 0;
    }
  }
  b->vehicle_name = name;
  /* CTrackManiaRace::InitNbLapsAndCheckpoints: the race settings' laps (a
     replay's, see tmuf_replay_laps), else the map's for a lap race, else one */
  b->laps = options && options->laps ? options->laps : b->map.has_laps && b->map.lap_race ? b->map.laps : 1;
  if (scene_flags & TMUF_SCENE_VISUALS) {
    if (!tmuf_visuals_build(&b->visuals, &b->scene, &b->arena) ||
        !tmuf_vehicle_visuals_build(&b->vehicle_visuals, &b->scene, &b->vehicle, &b->arena)) {
      tmuf_set_error(err, err_size, "out of memory");
      return 0;
    }
    b->has_visuals = 1;
    free(b->scene.visuals); /* the list is not needed any more */
    b->scene.visuals = NULL;
    b->scene.visual_count = b->scene.visual_cap = 0;
  }
  b->triangle_count = b->scene.triangle_count;
  b->triangles = malloc(sizeof *b->triangles * (b->triangle_count ? b->triangle_count : 1));
  if (!b->triangles) {
    tmuf_set_error(err, err_size, "out of memory");
    return 0;
  }
  for (uint32_t i = 0; i < b->triangle_count; i++) {
    memcpy(b->triangles[i].v, b->scene.triangles[i].v, sizeof b->triangles[i].v);
    b->triangles[i].block = b->scene.triangles[i].block;
  }
  free(b->scene.triangles);
  b->scene.triangles = NULL;
  b->scene.triangle_count = b->scene.triangle_cap = 0;
  return 1;
}

const tmuf_visuals *tmuf_track_visuals(const tmuf_track *track) {
  const tmuf_track_base *b = track ? tmuf_track_base_of(track) : NULL;
  return b && b->has_visuals ? &b->visuals.view : NULL;
}

const tmuf_vehicle_visuals *tmuf_track_vehicle_visuals(const tmuf_track *track) {
  const tmuf_track_base *b = track ? tmuf_track_base_of(track) : NULL;
  return b && b->has_visuals ? &b->vehicle_visuals.view : NULL;
}

void tmuf_track_base_free(tmuf_track_base *b) {
  tmuf_visuals_free(&b->visuals);
  tmuf_vehicle_visuals_free(&b->vehicle_visuals);
  free(b->triangles);
  tmuf_scene_free(&b->scene);
  tmuf_arena_free(&b->arena);
  free(b->map_data);
  memset(b, 0, sizeof *b);
}
