/* The game's sounds (CPlugSound and its subclasses) as the public
   tmuf_sound: their samples' paths on disk and the parameters the game plays
   them with (tmuf_work/audio_data_spec.md 2-6). */

#include "common/sounds.h"

#include <string.h>

static const tmuf_plug_sound_def *sound_def(tmuf_assets *assets, tmuf_asset *owner, tmuf_gbx_node *ref,
                                            tmuf_asset **out_owner) {
  tmuf_asset *a = NULL;
  tmuf_gbx_node *n = ref ? tmuf_assets_follow(assets, owner, ref, &a) : NULL;
  if (!n || !n->data || !n->cls)
    return NULL;
  const uint32_t c = n->cls->id;
  if (c != 0x0901a000u && c != 0x0908e000u && c != 0x0905e000u && c != 0x09064000u)
    return NULL;
  *out_owner = a ? a : owner;
  return n->data;
}

/* an external sample's path on disk, NULL if there is none */
static const char *sample_path(tmuf_assets *assets, tmuf_asset *owner, tmuf_gbx_node *ref, tmuf_arena *arena) {
  char path[1200];
  if (!ref || !tmuf_packset_resolve_file(assets->set, &owner->gbx, ref, owner->path, path, sizeof path))
    return NULL;
  const size_t n = strlen(path) + 1;
  char *out = tmuf_arena_alloc(arena, n);
  if (out)
    memcpy(out, path, n);
  return out;
}

static const tmuf_sound_component *component_of(tmuf_assets *assets, tmuf_asset *owner, tmuf_gbx_node *ref,
                                                tmuf_arena *arena) {
  tmuf_asset *a = NULL;
  tmuf_gbx_node *n = ref ? tmuf_assets_follow(assets, owner, ref, &a) : NULL;
  if (!n || !n->data || !n->cls || n->cls->id != 0x0908f000u)
    return NULL;
  if (!a)
    a = owner;
  const tmuf_sound_component_def *d = n->data;
  tmuf_sound_component *c = TMUF_ARENA_ARRAY(arena, tmuf_sound_component, 1);
  if (!c)
    return NULL;
  c->file = sample_path(assets, a, d->file, arena);
  c->min_volume = d->min_volume;
  c->max_volume = d->max_volume;
  c->fade_in_start = d->fade_in_start;
  c->fade_in_end = d->fade_in_end;
  c->fade_out_start = d->fade_out_start;
  c->fade_out_end = d->fade_out_end;
  c->min_pitch = d->min_pitch;
  c->max_pitch = d->max_pitch;
  c->pitch_shift_start = d->pitch_shift_start;
  c->pitch_shift_end = d->pitch_shift_end;
  return c;
}

/* a CFuncKeysReal as a curve (piecewise linear, or steps for interp 1) */
static void curve_of(const tmuf_func_keys *k, tmuf_curve *out) {
  memset(out, 0, sizeof *out);
  uint32_t n = k->x_count < k->y_count ? k->x_count : k->y_count;
  if (n > TMUF_MAX_CURVE_KEYS)
    n = TMUF_MAX_CURVE_KEYS;
  out->present = n > 0;
  out->constant = k->mode == 1;
  out->count = n;
  for (uint32_t i = 0; i < n; i++) {
    out->x[i] = k->xs[i];
    out->y[i] = k->ys[i];
  }
}

const tmuf_sound *tmuf_sound_build(tmuf_assets *assets, tmuf_asset *owner, tmuf_gbx_node *ref, tmuf_arena *arena) {
  tmuf_asset *a = NULL;
  const tmuf_plug_sound_def *d = sound_def(assets, owner, ref, &a);
  if (!d)
    return NULL;
  tmuf_gbx_node *n = tmuf_assets_follow(assets, owner, ref, NULL);
  tmuf_sound *s = TMUF_ARENA_ARRAY(arena, tmuf_sound, 1);
  if (!s)
    return NULL;
  memset(s, 0, sizeof *s);
  const uint32_t cls = n->cls->id;
  s->kind = cls == 0x0908e000u ? TMUF_SOUND_ENGINE
          : cls == 0x0905e000u ? TMUF_SOUND_SURFACE
          : cls == 0x09064000u ? TMUF_SOUND_MULTI
                               : TMUF_SOUND_PLAIN;
  s->file = sample_path(assets, a, d->file, arena);
  s->mode = d->mode;
  s->volume = d->volume;
  s->looping = d->looping != 0;
  s->continuous = d->continuous != 0;
  s->priority = d->priority;
  s->ref_distance = d->ref_distance;
  s->max_distance_omni = d->max_distance_omni;
  s->enable_doppler = d->enable_doppler != 0;
  s->doppler_factor = d->doppler_factor;
  if (s->kind == TMUF_SOUND_ENGINE) {
    s->max_rpm = d->max_rpm;
    tmuf_sound_component *cs = TMUF_ARENA_ARRAY(arena, tmuf_sound_component, d->components.count ? d->components.count : 1);
    for (uint32_t i = 0; cs && i < d->components.count; i++) {
      const tmuf_sound_component *c = component_of(assets, a, d->components.nodes[i], arena);
      if (c)
        cs[s->component_count++] = *c;
    }
    s->components = cs;
    curve_of(&d->curves[0], &s->volume_speed);
    curve_of(&d->curves[1], &s->volume_distance);
    curve_of(&d->curves[2], &s->volume_rpm);
    curve_of(&d->curves[3], &s->volume_accel);
  } else if (s->kind == TMUF_SOUND_SURFACE) {
    s->small_impact_attenuation = d->small_impact_attenuation;
    s->big_impact_attenuation = d->big_impact_attenuation;
    for (uint32_t m = 0; m < TMUF_SOUND_MATERIALS; m++) {
      s->materials[m].small_impact = sample_path(assets, a, d->small_impact[m], arena);
      s->materials[m].big_impact = sample_path(assets, a, d->big_impact[m], arena);
      s->materials[m].texture = component_of(assets, a, d->texture[m], arena);
      s->materials[m].skid = component_of(assets, a, d->skid[m], arena);
    }
  } else if (s->kind == TMUF_SOUND_MULTI) {
    /* variant 0 is the sound's own sample, then the ref buffer's */
    tmuf_asset *ba = NULL;
    tmuf_gbx_node *bn = d->variants ? tmuf_assets_follow(assets, a, d->variants, &ba) : NULL;
    const tmuf_node_list *list = bn && bn->data && bn->cls && bn->cls->id == 0x01026000u ? bn->data : NULL;
    const uint32_t n_variants = 1 + (list ? list->count : 0);
    const char **v = TMUF_ARENA_ARRAY(arena, const char *, n_variants);
    if (v) {
      v[0] = s->file;
      for (uint32_t i = 0; list && i < list->count; i++)
        v[1 + i] = sample_path(assets, ba ? ba : a, list->nodes[i], arena);
      s->variants = v;
      s->variant_count = n_variants;
    }
    s->force_random = d->force_random != 0;
  }
  return s;
}

/* CSceneVehicle::RetrieveSounds: the car mobil's links by name */
static const char *const kCarSoundNames[TMUF_CAR_SOUND_COUNT] = {
    "SoundHorn",       "SoundWheelSurface", "SoundEngine",      "SoundTurbo", "SoundWheelSurfaceFront", "SoundBrakes",
    "SoundBodySurface", "SoundGearChange",  "SoundBrakeLights", "SoundRoar",  "SoundVibrations",
};

void tmuf_car_sounds_build(tmuf_car_sound out[TMUF_CAR_SOUND_COUNT], tmuf_assets *assets, tmuf_asset *mobil_owner,
                           const tmuf_scene_object *mobil, tmuf_arena *arena) {
  memset(out, 0, sizeof(tmuf_car_sound) * TMUF_CAR_SOUND_COUNT);
  for (uint32_t i = 0; mobil && i < mobil->children.count; i++) {
    tmuf_asset *la = NULL;
    tmuf_gbx_node *ln = tmuf_assets_follow(assets, mobil_owner, mobil->children.nodes[i], &la);
    if (!ln || !ln->data || !ln->cls || ln->cls->id != 0x0a014000u)
      continue;
    const tmuf_object_link *link = ln->data;
    tmuf_asset *oa = NULL;
    tmuf_gbx_node *on = tmuf_assets_follow(assets, la, link->object, &oa);
    const tmuf_scene_object *o = on && on->data && on->cls && on->cls->id == 0x0a005000u ? on->data : NULL;
    if (!o || !o->has_sound || !o->name)
      continue;
    for (int k = 0; k < TMUF_CAR_SOUND_COUNT; k++) {
      if (strcmp(o->name, kCarSoundNames[k]) != 0 || out[k].sound)
        continue;
      out[k].sound = tmuf_sound_build(assets, oa ? oa : la, o->sound.sound, arena);
      tmuf_iso iso;
      tmuf_iso_from_archive(&iso, link->iso);
      for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
          out[k].location.r.m[r][c] = iso.m[r][c];
      out[k].location.t = (tmuf_vec3){iso.t[0], iso.t[1], iso.t[2]};
    }
  }
}
