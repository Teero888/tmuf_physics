#include "common/api_common.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/compress.h"
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
const char *tmuf_replay_skin(const tmuf_replay *r) { return r->ghost->skin ? r->ghost->skin : ""; }

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
     the packs lack (custom ids) runs as the environment's car; the asked
     name copied (the caller's, a replay's, may go once the track is made) */
  const char *name = options && options->vehicle && options->vehicle[0]
                         ? tmuf_arena_strndup(&b->arena, options->vehicle, strlen(options->vehicle))
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
    tmuf_weather_build(&b->weather, &b->scene, &b->arena);
    const int is_night = b->weather.found && b->weather.view.is_night;
    const char *mood_folder = b->weather.found ? b->weather.view.mood.folder : NULL;
    if (!tmuf_lightmap_build(&b->lightmap, &b->scene, 2048) ||
        !tmuf_visuals_build(&b->visuals, &b->scene, b->lightmap.of_scene_corpus, is_night, &b->arena) ||
        !tmuf_vehicle_visuals_build(&b->vehicle_visuals, &b->scene, &b->vehicle, is_night, mood_folder, &b->arena) ||
        !tmuf_track_lights_build(&b->lights, &b->scene, is_night, mood_folder, &b->arena) ||
        !tmuf_scenery_build(&b->scenery, &b->scene, &b->visuals.view, b->weather.found ? &b->weather.view : NULL,
                            b->lights.lights, b->lights.count, &b->arena)) {
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

const char *tmuf_track_decoration(const tmuf_track *track) {
  const tmuf_track_base *b = track ? tmuf_track_base_of(track) : NULL;
  return b && b->map.decoration[0] ? b->map.decoration[0] : "";
}

const tmuf_visuals *tmuf_track_visuals(const tmuf_track *track) {
  const tmuf_track_base *b = track ? tmuf_track_base_of(track) : NULL;
  return b && b->has_visuals ? &b->visuals.view : NULL;
}

const tmuf_weather *tmuf_track_weather(const tmuf_track *track) {
  const tmuf_track_base *b = track ? tmuf_track_base_of(track) : NULL;
  return b && b->has_visuals && b->weather.found ? &b->weather.view : NULL;
}

const tmuf_lightmap *tmuf_track_lightmap(const tmuf_track *track) {
  const tmuf_track_base *b = track ? tmuf_track_base_of(track) : NULL;
  return b && b->has_visuals ? &b->lightmap.view : NULL;
}

/* Std.PointsInSphere.Gbx (CPlugPointsInSphereOpt) as the pack */
#define POINTS_IN_SPHERE_FILE "Techno\\Media\\529F0C306598AC140409474EA21F378A3F"

uint32_t tmuf_track_sphere_points(const tmuf_track *track, uint32_t count, const float **points) {
  tmuf_track_base *b = track ? (tmuf_track_base *)tmuf_track_base_of(track) : NULL;
  if (points)
    *points = NULL;
  if (!b)
    return 0;
  tmuf_asset *a = tmuf_assets_load_path(&b->scene.assets, POINTS_IN_SPHERE_FILE);
  const tmuf_points_in_sphere *p = a && a->root && a->class_id == 0x09066000u ? a->root : NULL;
  if (!p || !p->pack_count)
    return 0;
  /* GetPointsInSphereCloseCount: lo the last pack below count, hi the first
     at or above it; the closer one, lo on a tie */
  uint32_t hi = 0;
  while (hi < p->pack_count && p->packs[2 * hi] < count)
    hi++;
  uint32_t k = hi;
  if (hi == p->pack_count)
    k = p->pack_count - 1;
  else if (hi > 0 && count - p->packs[2 * (hi - 1)] <= p->packs[2 * hi] - count)
    k = hi - 1;
  const uint32_t n = p->packs[2 * k], first = p->packs[2 * k + 1];
  if ((uint64_t)first + n > p->point_count)
    return 0;
  if (points)
    *points = p->points + 3u * first;
  return n;
}

uint32_t tmuf_track_lights(const tmuf_track *track, const tmuf_light **lights) {
  const tmuf_track_base *b = track ? tmuf_track_base_of(track) : NULL;
  if (!b || !b->has_visuals) {
    if (lights)
      *lights = NULL;
    return 0;
  }
  if (lights)
    *lights = b->lights.lights;
  return b->lights.count;
}

const tmuf_block_skin *tmuf_track_block_skin(const tmuf_track *track, uint32_t block) {
  const tmuf_track_base *b = track ? tmuf_track_base_of(track) : NULL;
  if (!b || block >= b->scene.block_skin_count || !b->scene.block_skins[block].file)
    return NULL;
  return &b->scene.block_skins[block];
}

const tmuf_scenery_light *tmuf_track_scenery_light(const tmuf_track *track) {
  const tmuf_track_base *b = track ? tmuf_track_base_of(track) : NULL;
  return b && b->has_visuals && b->scenery.found ? &b->scenery.view : NULL;
}

uint32_t tmuf_track_prelight_instance(const tmuf_track *track, uint32_t instance, uint8_t *bgra) {
  const tmuf_track_base *b = track ? tmuf_track_base_of(track) : NULL;
  if (!b || !b->has_visuals || !b->scenery.found || instance >= b->visuals.view.instance_count)
    return 0;
  const tmuf_visuals *v = &b->visuals.view;
  const tmuf_visual_instance *in = &v->instances[instance];
  if (in->mesh >= v->mesh_count)
    return 0;
  const tmuf_visual_mesh *m = &v->meshes[in->mesh];
  if (!(m->flags & TMUF_VISUAL_NORMAL) || (m->flags & TMUF_VISUAL_SPRITES))
    return 0;
  const uint32_t flags = in->material < v->material_count ? v->materials[in->material].generic_flags : 0u;
  const float (*r)[3] = in->location.r.m;
  const float t[3] = {in->location.t.x, in->location.t.y, in->location.t.z};
  for (uint32_t i = 0; i < m->vertex_count; i++) {
    const uint8_t *vx = m->vertices + (size_t)i * m->vertex_stride;
    float p[3], packed_n[3], wp[3], wn[3];
    uint32_t pn;
    memcpy(p, vx, sizeof p);
    memcpy(&pn, vx + 12, sizeof pn);
    for (int k = 0; k < 3; k++) {
      const int32_t c = (int32_t)(pn << (22 - 10 * k)) >> 22;
      packed_n[k] = (float)c / 511.0f;
    }
    for (int k = 0; k < 3; k++) {
      wp[k] = r[k][0] * p[0] + r[k][1] * p[1] + r[k][2] * p[2] + t[k];
      wn[k] = r[k][0] * packed_n[0] + r[k][1] * packed_n[1] + r[k][2] * packed_n[2];
    }
    tmuf_scenery_prelight(&b->scenery.view, flags, wp, wn, b->scenery.lamps, b->scenery.lamp_count, bgra + (size_t)i * 4u);
  }
  return m->vertex_count;
}

const tmuf_vehicle_visuals *tmuf_track_vehicle_visuals(const tmuf_track *track) {
  const tmuf_track_base *b = track ? tmuf_track_base_of(track) : NULL;
  return b && b->has_visuals ? &b->vehicle_visuals.view : NULL;
}

void tmuf_track_base_free(tmuf_track_base *b) {
  tmuf_visuals_free(&b->visuals);
  tmuf_vehicle_visuals_free(&b->vehicle_visuals);
  tmuf_lights_free(&b->lights);
  tmuf_lightmap_free(&b->lightmap);
  tmuf_weather_free(&b->weather);
  free(b->triangles);
  tmuf_scene_free(&b->scene);
  tmuf_arena_free(&b->arena);
  free(b->map_data);
  memset(b, 0, sizeof *b);
}

/* ---- zip archives (skins, lightmap caches) ---- */

static uint32_t zip_u32(const uint8_t *p) { return (uint32_t)p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24; }
static uint32_t zip_u16(const uint8_t *p) { return (uint32_t)p[0] | (uint32_t)p[1] << 8; }

static int zip_name_eq(const uint8_t *a, uint32_t n, const char *b) {
  if (strlen(b) != n)
    return 0;
  for (uint32_t i = 0; i < n; i++) {
    int x = a[i], y = (unsigned char)b[i];
    if (x >= 'A' && x <= 'Z') x += 32;
    if (y >= 'A' && y <= 'Z') y += 32;
    if (x != y)
      return 0;
  }
  return 1;
}

void *tmuf_zip_extract(const void *zip, size_t size, const char *name, size_t *out_size) {
  const uint8_t *z = zip;
  if (!z || size < 22 || !name)
    return NULL;
  /* the end of central directory record, within its comment's reach */
  size_t eocd = size - 22;
  for (;; eocd--) {
    if (zip_u32(z + eocd) == 0x06054b50u)
      break;
    if (eocd == 0 || size - eocd > 22 + 65535)
      return NULL;
  }
  const uint32_t entries = zip_u16(z + eocd + 10), cd = zip_u32(z + eocd + 16);
  size_t at = cd;
  for (uint32_t i = 0; i < entries; i++) {
    if (at + 46 > size || zip_u32(z + at) != 0x02014b50u)
      return NULL;
    const uint32_t method = zip_u16(z + at + 10), csize = zip_u32(z + at + 20), usize = zip_u32(z + at + 24);
    const uint32_t nlen = zip_u16(z + at + 28), xlen = zip_u16(z + at + 30), clen = zip_u16(z + at + 32);
    const uint32_t local = zip_u32(z + at + 42);
    if (at + 46 + nlen > size)
      return NULL;
    if (zip_name_eq(z + at + 46, nlen, name)) {
      if ((size_t)local + 30 > size || zip_u32(z + local) != 0x04034b50u)
        return NULL;
      const size_t data = (size_t)local + 30 + zip_u16(z + local + 26) + zip_u16(z + local + 28);
      if (data + csize > size || (method != 0 && method != 8))
        return NULL;
      uint8_t *out = malloc(usize ? usize : 1);
      if (!out)
        return NULL;
      if (method == 0 ? (csize == usize && (memcpy(out, z + data, usize), 1))
                      : tmuf_inflate_raw(z + data, csize, out, usize)) {
        *out_size = usize;
        return out;
      }
      free(out);
      return NULL;
    }
    at += 46 + nlen + xlen + clen;
  }
  return NULL;
}
