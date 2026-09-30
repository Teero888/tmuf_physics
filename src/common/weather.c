#include "common/weather.h"

#include <ctype.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/assets.h"
#include "common/pack_classes.h"
#include "common/packset.h"

/* ---- the time of day (CMotionManagerWeathers, TmForeverFixed 2.11.26) ----

   The manager's sunrise, sunset and transition fraction are its
   constructor's (0x574490): the mood's own sunrise and sunset never reach
   it. Intermediate values follow the x87 code: extended precision (double
   here) where it stays in registers, float where it is stored. */

#define RISE 0.25f
#define SET 0.75f
#define FRACTION (1.0f / 24.0f) /* 0xb5b5f0 */
#define DAY_MS 86400000u

static float timer_time(float t, uint32_t *ms_out) {
  /* CMotionTimerLoop::SetNormedTime (clamped, truncated to whole ms) and
     GetNormedTime */
  if (!(t >= 0.0f))
    t = 0.0f;
  else if (t > 1.0f)
    t = 1.0f;
  const uint32_t ms = (uint32_t)(int64_t)((double)DAY_MS * (double)t);
  *ms_out = ms;
  return (float)((double)ms / (double)DAY_MS);
}

void tmuf_day_time_at(float t, float latitude, tmuf_day_time *o) {
  memset(o, 0, sizeof *o);
  /* CMotionManagerWeathers::JumpToTimeRemapped (0x574170) */
  const double span = (double)SET - (double)RISE;
  const float fa = (float)((double)FRACTION * span);
  const float fb = (float)(span - 2.0 * (double)fa);
  while (t < -0.001f)
    t = (float)((double)t + 1.0);
  while (t > 1.001f)
    t = (float)((double)t - 1.0);
  float clock;
  if (!(t > 0.25f)) {
    clock = (float)((double)SET + (double)t * 4.0 * ((double)RISE + 1.0 - (double)SET));
    if (clock > 1.0f)
      clock = (float)((double)clock - 1.0);
  } else if (!(t > 0.5f)) {
    clock = (float)(((double)t - 0.25) * 4.0 * (double)fa + (double)RISE);
  } else if (!(t > 0.75f)) {
    clock = (float)(((double)t - 0.5) * 4.0 * (double)fb + ((double)fa + (double)RISE));
  } else {
    clock = (float)(((double)t - 0.75) * 4.0 * (double)fa + ((double)SET - (double)fa));
  }
  const float time = timer_time(clock, &o->ms);
  o->time = time;

  /* CMotionManagerWeathers::UpdateAsync (0x572c30) */
  float remapped, sun;
  uint32_t state;
  if (time < RISE || SET < time) {
    const float mid = (float)(((double)SET + (double)RISE) * 0.5);
    double x;
    if (mid >= time) { /* after midnight */
      sun = 0.0f;
      x = (1.0 - (double)SET) + (double)time;
    } else {
      sun = 1.0f;
      x = (double)time - (double)SET;
    }
    remapped = (float)(x * 0.25 / (double)(float)((double)RISE + 1.0 - (double)SET));
    state = TMUF_DAY_NIGHT;
  } else {
    float s = (float)(((double)time - (double)RISE) / ((double)SET - (double)RISE));
    s = s < 0.0f ? 0.0f : s > 1.0f ? 1.0f : s; /* GmFunc::Saturate */
    sun = s;
    const double f = (double)FRACTION;
    if ((double)s < f) {
      state = TMUF_DAY_SUNRISE;
      remapped = (float)((double)s / f * 0.25 + 0.25);
    } else if ((double)s < 1.0 - f) {
      state = TMUF_DAY_DAY;
      remapped = (float)(((double)s - f) / (1.0 - f) * 0.25 + 0.5);
    } else {
      state = TMUF_DAY_SUNSET;
      remapped = (float)((((double)s - 1.0) + f) / f * 0.25 + 0.75);
    }
  }
  o->remapped = remapped;
  o->state = state;
  o->is_day = state == TMUF_DAY_DAY;
  o->sun_position = sun;
  const float night = state == TMUF_DAY_NIGHT     ? 1.0f
                      : state == TMUF_DAY_DAY     ? 0.0f
                      : state == TMUF_DAY_SUNRISE ? (float)(1.0 - ((double)remapped * 4.0 - 1.0))
                                                  : (float)((double)remapped * 4.0 - 3.0);
  o->night = night;
  o->day = (float)(1.0 - (double)night);

  /* the sun: (cos, -sin, 0) of sun * pi, turned by RotateX(-latitude) */
  const float theta = (float)((double)sun * 3.1415927410125732);
  const float lat = (float)((double)latitude * 3.1415927410125732 / 180.0);
  const float st = (float)sin((double)theta), ct = (float)cos((double)theta);
  const float cl = (float)cos(-(double)lat), sl = (float)sin(-(double)lat);
  o->sun_dir[0] = ct;
  o->sun_dir[1] = (float)((double)cl * -(double)st);
  o->sun_dir[2] = (float)((double)sl * -(double)st);
  /* the moon: the manager's frame, SetDOV of normalise(0.8, -0.4, 0.8) */
  const float inv = (float)(1.0 / sqrt(1.44));
  o->moon_dir[0] = (float)(0.8 * (double)inv);
  o->moon_dir[1] = (float)(-0.4 * (double)inv);
  o->moon_dir[2] = (float)(0.8 * (double)inv);
}

void tmuf_weather_at(const tmuf_weather *w, const tmuf_day_time *t, tmuf_weather_fog *fog, float *spec_intensity, float *spec_power) {
  const double n = (double)t->night, d = (double)t->day;
  if (fog) {
    const tmuf_weather_fog *a = &w->fogs[0], *b = &w->fogs[1];
    for (int i = 0; i < 3; i++) /* night + (day - night) * d */
      fog->rgb[i] = (float)((double)a->rgb[i] + (double)(float)((double)(float)((double)b->rgb[i] - (double)a->rgb[i]) * d));
    fog->start = (float)((double)b->start * d + (double)a->start * n);
    fog->end = (float)((double)b->end * d + (double)a->end * n);
    fog->density = (float)((double)b->density * d + (double)a->density * n);
    fog->flags = b->flags;
  }
  if (spec_intensity)
    *spec_intensity = (float)(d * (double)w->spec_intensity[1] + n * (double)w->spec_intensity[0]);
  if (spec_power)
    *spec_power = (float)((double)w->spec_power[0] * n + (double)w->spec_power[1] * d);
}

int tmuf_day_time_light(const tmuf_day_time *t, const uint8_t sun_rgb[3], const uint8_t moon_rgb[3], float dir[3]) {
  const double k = 0.003921568859368563; /* 0xb3d080 */
  float sun2 = 0.0f, moon2 = 0.0f;
  double s = 0.0, m = 0.0;
  for (int i = 0; i < 3; i++) {
    const float a = (float)(sun_rgb[i] * k), b = (float)(moon_rgb[i] * k);
    s += (double)a * (double)a;
    m += (double)b * (double)b;
  }
  sun2 = (float)s;
  moon2 = (float)m;
  const int moon = !(moon2 < sun2);
  if (dir)
    memcpy(dir, moon ? t->moon_dir : t->sun_dir, sizeof t->sun_dir);
  return moon;
}

/* CPlugFileImg::FilterWrappedPixel (0x850110) with a filter and wrapping:
   the first texel by round-to-nearest of (x - 0.5) - 0.5, bytes truncated */
void tmuf_picture_sample(const uint8_t *pixels, uint32_t width, uint32_t height, uint32_t pixel_bytes, float u, float v, uint8_t *out) {
  if (!width || !height || !pixel_bytes) {
    memset(out, 0xff, pixel_bytes);
    return;
  }
  const float x = (float)width * u, y = (float)height * v;
  const float xi = nearbyintf((float)((double)x - 0.5 - 0.5)), yi = nearbyintf((float)((double)y - 0.5 - 0.5));
  const float fx = (float)((double)x - ((double)xi + 0.5)), fy = (float)((double)y - ((double)yi + 0.5));
  const int64_t ix = (int64_t)xi, iy = (int64_t)yi;
  const uint32_t x0 = (uint32_t)(((ix % width) + width) % width), x1 = (uint32_t)((((ix + 1) % width) + width) % width);
  const uint32_t y0 = (uint32_t)(((iy % height) + height) % height), y1 = (uint32_t)((((iy + 1) % height) + height) % height);
  const double dx = (double)fx, dy = (double)fy;
  const float w00 = (float)((1.0 - dx) * (1.0 - dy)), w10 = (float)(dx * (1.0 - dy)), w01 = (float)((1.0 - dx) * dy), w11 = (float)(dy * dx);
  const float norm = (float)(1.0 / ((double)w11 + (double)w01 + (double)w00 + (double)w10));
  const size_t row = (size_t)width * pixel_bytes;
  const uint8_t *p00 = pixels + y0 * row + x0 * pixel_bytes, *p10 = pixels + y0 * row + x1 * pixel_bytes;
  const uint8_t *p01 = pixels + y1 * row + x0 * pixel_bytes, *p11 = pixels + y1 * row + x1 * pixel_bytes;
  for (uint32_t c = 0; c < pixel_bytes; c++) {
    const double sum = (double)p11[c] * (double)w11 + (double)p01[c] * (double)w01 + (double)p00[c] * (double)w00 + (double)p10[c] * (double)w10;
    const double value = sum * (double)norm;
    out[c] = (uint8_t)(value <= 0.0 ? 0 : value >= 255.0 ? 255 : (int)value);
  }
}

/* ---- the weather's files ---- */

static const char *dup(tmuf_arena *a, const char *s) { return s ? tmuf_arena_strndup(a, s, strlen(s)) : NULL; }

static int ieq(const char *a, const char *b) {
  for (; *a && *b; a++, b++)
    if (tolower((unsigned char)*a) != tolower((unsigned char)*b))
      return 0;
  return *a == *b;
}

static int ends_with(const char *s, const char *suffix) {
  size_t n = strlen(s), m = strlen(suffix);
  return n >= m && ieq(s + n - m, suffix);
}

typedef struct wbuild {
  tmuf_scene *scene;
  const tmuf_packset *set;
  tmuf_arena *arena;
  const char *folder; /* the mood's */
  uint32_t entry_count;
  tmuf_weather_skin_entry *entries;
} wbuild;

/* the file an external node of owner names: in the packs, else on disk */
static tmuf_weather_file node_file(wbuild *b, tmuf_asset *owner, tmuf_gbx_node *n) {
  tmuf_weather_file f = {NULL, NULL};
  if (!owner || !n || !n->external)
    return f;
  char path[1200];
  if (tmuf_packset_resolve(b->set, &owner->gbx, n, owner->path, path, sizeof path).pack >= 0)
    f.pack_file = dup(b->arena, path);
  else if (tmuf_packset_resolve_file(b->set, &owner->gbx, n, owner->path, path, sizeof path))
    f.file = dup(b->arena, path);
  return f;
}

static int same_file(tmuf_weather_file a, tmuf_weather_file b) {
  if (a.pack_file && b.pack_file)
    return ieq(a.pack_file, b.pack_file);
  if (a.file && b.file)
    return ieq(a.file, b.file);
  return 0;
}

/* the file the game uses in place of f: the skin entry's that names it */
static tmuf_weather_file skinned(const wbuild *b, tmuf_weather_file f) {
  for (uint32_t i = 0; i < b->entry_count; i++)
    if (same_file(b->entries[i].default_file, f))
      return b->entries[i].file;
  return f;
}

static tmuf_weather_file picture(wbuild *b, tmuf_asset *owner, tmuf_gbx_node *n) { return skinned(b, node_file(b, owner, n)); }

/* a CPlugBitmap's image (the flares' pictures are Texture.Gbx bitmaps):
   the image its bitmap names, the node's own file when it is no bitmap */
static tmuf_weather_file bitmap_picture(wbuild *b, tmuf_asset *owner, tmuf_gbx_node *n) {
  tmuf_weather_file f = picture(b, owner, n);
  tmuf_asset *ba = NULL;
  tmuf_gbx_node *bn = n ? tmuf_assets_follow(&b->scene->assets, owner, n, &ba) : NULL;
  if (!bn || !ba || !bn->data || !bn->cls || bn->cls->id != 0x09011000u)
    return f;
  const tmuf_plug_bitmap *bm = bn->data;
  if (!bm->image || !bm->image->external)
    return f;
  char path[1200];
  tmuf_weather_file img = {NULL, NULL};
  if (tmuf_packset_resolve(b->set, &ba->gbx, bm->image, ba->path, path, sizeof path).pack >= 0)
    img.pack_file = dup(b->arena, path);
  else if (tmuf_packset_resolve_file(b->set, &ba->gbx, bm->image, ba->path, path, sizeof path))
    img.file = dup(b->arena, path);
  return img.file || img.pack_file ? img : f;
}

/* an external node of a file whose name ends with suffix */
static tmuf_gbx_node *find_external(tmuf_asset *a, const char *suffix) {
  if (!a)
    return NULL;
  for (uint32_t i = 1; i <= a->gbx.node_count; i++) {
    tmuf_gbx_node *n = &a->gbx.nodes[i];
    if (n->external && n->file && ends_with(n->file, suffix))
      return n;
  }
  return NULL;
}

/* CPlugGameSkin: each entry's file, the mood folder's <name><ext> when the
   packs or GameData have it */
static void read_skin(wbuild *b, tmuf_asset *ka) {
  const tmuf_game_skin *skin = ka->root;
  b->entries = TMUF_ARENA_ARRAY(b->arena, tmuf_weather_skin_entry, skin->rule_count ? skin->rule_count : 1);
  if (!b->entries)
    return;
  for (uint32_t i = 0; i < skin->rule_count; i++) {
    const tmuf_skin_rule *r = &skin->rules[i];
    if (!r->prefix || !r->prefix[0])
      continue;
    tmuf_weather_skin_entry *e = &b->entries[b->entry_count++];
    e->name = dup(b->arena, r->prefix);
    e->class_id = r->class_id;
    e->default_file = r->has_target ? node_file(b, ka, r->target) : (tmuf_weather_file){NULL, NULL};
    e->file = e->default_file;
    const char *def = e->default_file.pack_file ? e->default_file.pack_file : e->default_file.file;
    if (!def || !b->folder || !b->folder[0])
      continue;
    const char *base = def + strlen(def);
    while (base > def && base[-1] != '\\' && base[-1] != '/')
      base--;
    const char *ext = strchr(r->prefix, '.') ? "" : strchr(base, '.');
    char path[1200];
    const size_t fl = strlen(b->folder);
    snprintf(path, sizeof path, "%s%s%s%s", b->folder, b->folder[fl - 1] == '\\' ? "" : "\\", r->prefix, ext ? ext : "");
    if (tmuf_packset_find(b->set, path).pack >= 0) {
      e->file = (tmuf_weather_file){NULL, dup(b->arena, path)};
    } else {
      char disk[1200];
      if (tmuf_packset_find_file(b->set, path, disk, sizeof disk))
        e->file = (tmuf_weather_file){dup(b->arena, disk), NULL};
    }
  }
}

static tmuf_asset *load_pack_file(wbuild *b, tmuf_weather_file f, uint32_t class_id) {
  if (!f.pack_file)
    return NULL;
  tmuf_asset *a = tmuf_assets_load_path(&b->scene->assets, f.pack_file);
  return a && a->root && a->class_id == class_id ? a : NULL;
}

/* ---- the 3D clouds (CSceneMobilClouds) ---- */

/* CMotionWeather::ChangeClouds loads CFuncClouds' solids; BuildInstances
   duplicates their trees, whose children OnRenderBefore places one by one. */
static void build_sky_clouds(tmuf_weather_data *wd, tmuf_scene *s, tmuf_arena *arena, tmuf_asset *ca, const tmuf_func_clouds *c) {
  tmuf_weather_sky_clouds *k = &wd->view.sky_clouds;
  k->grid_size[0] = k->grid_size[1] = 16000.0f; /* CSceneMobilClouds::CSceneMobilClouds (0xb9fd28) */
  k->wind_speed = c->real50;                    /* * WindSpeed 1 */
  k->wind_dir = 0.0f;
  k->view_dependent = 1;
  k->has_center = c->nat30 != 0;
  k->center[0] = c->real34;
  k->center[1] = c->real38;
  k->height0 = c->real3c;
  k->height_far = c->real4c;
  k->key_count = c->key_count;
  k->keys = (const float (*)[2])c->keys;
  k->solid_count = c->solids.count;

  tmuf_scene_visual *list = NULL;
  tmuf_weather_cloud_piece *pieces = NULL;
  uint32_t n = 0, cap = 0;
  for (uint32_t i = 0; i < c->solids.count; i++) {
    tmuf_asset *sa;
    tmuf_gbx_node *sn = tmuf_assets_follow(&s->assets, ca, c->solids.nodes[i], &sa);
    for (int d = 0; d < 8 && sn && sn->data && sn->class_id == 0x09005000u && ((const tmuf_plug_solid *)sn->data)->use_model; d++)
      sn = tmuf_assets_follow(&s->assets, sa, ((const tmuf_plug_solid *)sn->data)->model, &sa);
    if (!sn || !sn->data || sn->class_id != 0x09005000u)
      continue;
    tmuf_asset *ra;
    tmuf_gbx_node *rn = tmuf_assets_follow(&s->assets, sa, ((const tmuf_plug_solid *)sn->data)->tree, &ra);
    if (!rn || !rn->data || !rn->cls || (rn->cls->id != 0x0904f000u && rn->cls->id != 0x09015000u && rn->cls->id != 0x09062000u))
      continue;
    const tmuf_plug_tree *root = rn->data;
    for (uint32_t j = 0; j < root->child_count; j++) {
      tmuf_asset *ta, *va;
      tmuf_gbx_node *tn = tmuf_assets_follow(&s->assets, ra, root->children[j], &ta);
      if (!tn || !tn->data || !tn->cls || (tn->cls->id != 0x0904f000u && tn->cls->id != 0x09015000u && tn->cls->id != 0x09062000u))
        continue;
      const tmuf_plug_tree *t = tn->data;
      tmuf_gbx_node *vn = t->visual ? tmuf_assets_follow(&s->assets, ta, t->visual, &va) : NULL;
      if (!vn || !vn->data || !vn->cls || vn->cls->id != 0x09006000u)
        continue; /* OnRenderBefore places the children with a visual */
      if (n == cap) {
        cap = cap ? cap * 2 : 64;
        tmuf_scene_visual *l = realloc(list, sizeof *l * cap);
        tmuf_weather_cloud_piece *p = realloc(pieces, sizeof *p * cap);
        if (l)
          list = l;
        if (p)
          pieces = p;
        if (!l || !p)
          break;
      }
      tmuf_scene_visual *v = &list[n];
      memset(v, 0, sizeof *v);
      v->owner = ta;
      v->visual = t->visual;
      v->material = t->material;
      v->shader = t->shader;
      /* the child's own rotation stays; its translation is the placement's */
      tmuf_iso local = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {0, 0, 0}};
      if (t->has_iso)
        tmuf_iso_from_archive(&local, t->iso);
      local.t[0] = local.t[1] = local.t[2] = 0.0f;
      v->iso = local;
      v->tag = n;
      v->lod_near = 0.0f;
      v->lod_far = FLT_MAX;
      const tmuf_plug_visual *pv = vn->data;
      pieces[n].solid = i;
      pieces[n].instance = UINT32_MAX;
      memcpy(pieces[n].center, pv->bbox, sizeof pieces[n].center);
      n++;
    }
  }
  /* the pieces' meshes and materials, as the track's own visuals */
  const int ok = n && tmuf_visuals_build_list(&wd->cloud_visuals, s, list, n, wd->view.is_night, arena);
  free(list);
  if (!ok) {
    free(pieces);
    k->solid_count = 0;
    return;
  }
  tmuf_weather_cloud_piece *kept = TMUF_ARENA_ARRAY(arena, tmuf_weather_cloud_piece, n);
  if (kept) {
    const tmuf_visuals *vis = &wd->cloud_visuals.view;
    for (uint32_t i = 0; i < vis->instance_count; i++)
      if (vis->instances[i].block < n)
        pieces[vis->instances[i].block].instance = i;
    uint32_t m = 0;
    for (uint32_t i = 0; i < n; i++)
      if (pieces[i].instance != UINT32_MAX)
        kept[m++] = pieces[i];
    k->pieces = kept;
    k->piece_count = m;
    k->visuals = *vis;
  }
  free(pieces);
}

void tmuf_weather_free(tmuf_weather_data *wd) {
  if (wd->cloud_visuals.view.mesh_count || wd->cloud_visuals.meshes)
    tmuf_visuals_free(&wd->cloud_visuals);
  memset(&wd->cloud_visuals, 0, sizeof wd->cloud_visuals);
}

#define D(x) ((double)(x))

static float frac_positive(float x) {
  /* modf, then +1 when negative (OnRenderBefore's table lookup on the sign) */
  double ip;
  const float f = (float)modf(D(x), &ip);
  return (float)(D(f < 0.0f ? 1.0f : 0.0f) + D(f));
}

/* ((frac(x / tile + 0.5) - 0.5) * tile: the wrap into [-tile/2, tile/2) */
static float wrap(float x, float tile) {
  const float a = (float)(D((float)(D(x) / D(tile))) + 0.5);
  return (float)((D(frac_positive(a)) - 0.5) * D(tile));
}

uint32_t tmuf_weather_clouds_place(const tmuf_weather *w, const float eye[3], float far_distance, uint32_t time_ms, tmuf_cloud_draw *out,
                                   uint32_t cap) {
  const tmuf_weather_sky_clouds *k = w ? &w->sky_clouds : NULL;
  if (!k || !k->solid_count || !k->piece_count)
    return 0;
  /* OnRenderBefore: AutoSizeFarZ sets the instance counts from the far
     distance (fistp: round to nearest) */
  const double twice = 2.0 * D(far_distance);
  const uint32_t nz = (uint32_t)(int64_t)nearbyint(D((float)(D((float)(twice / D(k->grid_size[1]))) + 0.5))) + 1;
  const uint32_t nx = (uint32_t)(int64_t)nearbyint(D((float)(D((float)(twice / D(k->grid_size[0]))) + 0.5))) + 1;
  const float tile_x = (float)(D(nx) * D(k->grid_size[0])), tile_z = (float)(D(nz) * D(k->grid_size[1]));
  /* the wind: WindSpeed * CFuncClouds' speed * ms * 0.001 */
  const float drift = (float)(D(k->wind_speed) * D(time_ms) * 0.0010000000474974513);
  const float wind[3] = {(float)(D(drift) * -D((float)sin(D(k->wind_dir)))), 0.0f, (float)(D(drift) * -D((float)cos(D(k->wind_dir))))};
  uint32_t count = 0, solid = 0;
  for (uint32_t iz = 0; iz < nz; iz++) {
    for (uint32_t ix = 0; ix < nx; ix++) {
      /* BuildInstances: RotateY(((iz & 1) + 2 (ix & 1)) * pi / 2), cell origin */
      const float a = (float)(D((iz & 1u) + 2u * (ix & 1u)) * 3.1415927410125732 * 0.5);
      const float ca = (float)cos(D(a)), sa = (float)sin(D(a));
      const float r[3][3] = {{ca, 0.0f, sa}, {0.0f, 1.0f, 0.0f}, {-sa, 0.0f, ca}};
      const float t[3] = {(float)(D(ix) * D(k->grid_size[0])), 0.0f, (float)(D(iz) * D(k->grid_size[1]))};
      /* IsViewDep: relative to the camera horizontally */
      const float tr[3] = {k->view_dependent ? (float)(D(t[0]) - D(eye[0])) : t[0], t[1], k->view_dependent ? (float)(D(t[2]) - D(eye[2])) : t[2]};
      for (uint32_t pi = 0; pi < k->piece_count; pi++) {
        if (k->pieces[pi].solid != solid)
          continue;
        const float *c = k->pieces[pi].center;
        float p[3], q[3];
        for (int i = 0; i < 3; i++)
          p[i] = (float)(D(r[i][1]) * D(c[1]) + D(c[0]) * D(r[i][0]) + D(r[i][2]) * D(c[2]) + D(tr[i]));
        for (int i = 0; i < 3; i++)
          q[i] = (float)(D(p[i]) + D(wind[i]));
        q[0] = wrap(q[0], tile_x);
        q[2] = wrap(q[2], tile_z);
        float d[3], dl[3];
        for (int i = 0; i < 3; i++)
          d[i] = (float)(D(q[i]) - D(p[i]));
        for (int i = 0; i < 3; i++) /* into the instance's frame */
          dl[i] = (float)(D(r[0][i]) * D(d[0]) + D(r[1][i]) * D(d[1]) + D(r[2][i]) * D(d[2]));
        /* the height over the horizontal distance */
        float hx = q[0], hz = q[2];
        if (k->has_center) {
          if (k->view_dependent) {
            hx = (float)(D(hx) + D(eye[0]));
            hz = (float)(D(hz) + D(eye[2]));
          }
          hx = (float)(D(hx) - D(k->center[0]));
          hz = (float)(D(hz) - D(k->center[1]));
        }
        const float dist = (float)sqrt(D((float)(D(hx) * D(hx) + D(hz) * D(hz))));
        float prev[2] = {0.0f, k->height0}, next[2] = {far_distance, k->height_far};
        uint32_t ki = 0;
        while (ki < k->key_count && !(k->keys[ki][0] > dist)) {
          prev[0] = k->keys[ki][0];
          prev[1] = k->keys[ki][1];
          ki++;
        }
        if (ki < k->key_count) {
          next[0] = k->keys[ki][0];
          next[1] = k->keys[ki][1];
        }
        const float f = (float)((D(dist) - D(prev[0])) / (D(next[0]) - D(prev[0])));
        dl[1] = (float)(D(prev[1]) + (D(next[1]) - D(prev[1])) * D(f));
        if (out && count < cap) {
          tmuf_cloud_draw *o = &out[count];
          o->piece = pi;
          const tmuf_iso4 *own = &k->visuals.instances[k->pieces[pi].instance].location;
          for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
              o->location.r.m[i][j] = (float)(D(r[i][0]) * D(own->r.m[0][j]) + D(r[i][1]) * D(own->r.m[1][j]) + D(r[i][2]) * D(own->r.m[2][j]));
          float tw[3];
          for (int i = 0; i < 3; i++)
            tw[i] = (float)(D(r[i][0]) * D(dl[0]) + D(r[i][1]) * D(dl[1]) + D(r[i][2]) * D(dl[2]) + D(t[i]));
          o->location.t = (tmuf_vec3){tw[0], tw[1], tw[2]};
        }
        count++;
      }
      solid = solid + 1 >= k->solid_count ? 0 : solid + 1;
    }
  }
  return count;
}

void tmuf_cloud_sprite_quad(const tmuf_visual_mesh *mesh, uint32_t sprite, const float right[3], const float up[3], float corners[4][3],
                            float uv[4][2]) {
  const uint8_t *v = mesh->vertices + (size_t)sprite * mesh->vertex_stride;
  float pos[3], size, aspect;
  uint32_t cell;
  memcpy(pos, v, sizeof pos);
  memcpy(&size, v + 12, 4);
  memcpy(&cell, v + 16, 4);
  memcpy(&aspect, v + 20, 4);
  /* CLoadGeomDynaSprite::LoadSprite, flags 0x40 (atlas cell, no roll):
     A = 0.5 size up, B = 0.5 size aspect left (the camera's first axis) */
  const float a = (float)(0.5 * D(size)), b = (float)(0.5 * D(size) * D(aspect));
  static const float sa[4] = {-1, -1, 1, 1}, sb[4] = {1, -1, 1, -1};
  for (int c = 0; c < 4; c++)
    for (int i = 0; i < 3; i++)
      corners[c][i] = (float)(D(pos[i]) + D(sa[c]) * D(a) * D(up[i]) - D(sb[c]) * D(b) * D(right[i]));
  /* CPlugVisualSprite::UpdateAtlasTexCoords: cell = row * columns + column */
  const uint32_t cols = mesh->sprite_atlas[0] ? mesh->sprite_atlas[0] : 1u, rows = mesh->sprite_atlas[1] ? mesh->sprite_atlas[1] : 1u;
  if (!(mesh->sprite_flags & 0x40u) || cell >= cols * rows)
    cell = 0;
  const float u0 = (float)(D(cell % cols) / D(cols)), u1 = (float)(D(cell % cols + 1) / D(cols));
  const float v0 = (float)(D(cell / cols) / D(rows)), v1 = (float)(D(cell / cols + 1) / D(rows));
  const float us[4] = {u0, u1, u0, u1}, vs[4] = {v0, v0, v1, v1};
  for (int c = 0; c < 4; c++) {
    uv[c][0] = us[c];
    uv[c][1] = vs[c];
  }
}

int tmuf_weather_build(tmuf_weather_data *wd, tmuf_scene *s, tmuf_arena *arena) {
  memset(wd, 0, sizeof *wd);
  tmuf_weather *w = &wd->view;
  wbuild b = {s, s->assets.set, arena, NULL, 0, NULL};

  /* the decoration's mood (its chunk is crypted: follow the reference table) */
  tmuf_asset *ma = NULL;
  tmuf_gbx_node *mn = find_external(s->decoration_asset, ".TMDecorationMood.Gbx");
  mn = mn ? tmuf_assets_follow(&s->assets, s->decoration_asset, mn, &ma) : NULL;
  if (!mn || !mn->data || mn->class_id != 0x0303a000u)
    return 0;
  const tmuf_mood *mood = mn->data;
  w->mood.latitude = mood->latitude;
  w->mood.remapped_start_day_time = mood->remapped_start_day_time;
  w->mood.time_sun_rise = mood->time_sun_rise;
  w->mood.time_sun_fall = mood->time_sun_fall;
  w->mood.folder = dup(arena, mood->folder ? mood->folder : "");
  w->mood.shadow_count_car_human = mood->shadow_count_car_human;
  w->mood.shadow_count_car_opponent = mood->shadow_count_car_opponent;
  w->mood.shadow_car_intensity = mood->shadow_car_intensity;
  w->mood.shadow_scene = mood->shadow_scene;
  w->mood.background_is_locally_lighted = mood->background_is_locally_lighted;
  w->mood.pack_light_map = node_file(&b, ma, mood->pack_light_map);
  /* its ambient occlusion (CHmsAmbientOcc's defaults when it names none) */
  tmuf_ambient_occlusion *ao = &w->mood.ambient_occlusion;
  ao->radius = 0.024f;
  ao->power = 3.0f;
  ao->blur_texels = 15;
  ao->mid_gray[0] = ao->mid_gray[1] = ao->mid_gray[2] = 0.5f;
  if (mood->ambient_occ) {
    tmuf_gbx_node *an = tmuf_assets_follow(&s->assets, ma, mood->ambient_occ, NULL);
    if (an && an->data && an->class_id == 0x06026000u) {
      const tmuf_ambient_occ *o = an->data;
      ao->from_file = 1;
      ao->file = node_file(&b, ma, mood->ambient_occ);
      ao->radius = o->radius;
      ao->power = o->power;
      ao->blur_texels = o->blur_texels;
      memcpy(ao->mid_gray, o->mid_gray, sizeof ao->mid_gray);
    }
  }
  b.folder = w->mood.folder;
  tmuf_day_time_at(w->mood.remapped_start_day_time, w->mood.latitude, &w->start);
  w->is_night = !(0.25f < w->mood.remapped_start_day_time && w->mood.remapped_start_day_time < 0.75f);

  /* the mood's skin */
  tmuf_asset *ka = NULL;
  tmuf_gbx_node *kn = find_external(ma, ".GameSkin.gbx");
  kn = kn ? tmuf_assets_follow(&s->assets, ma, kn, &ka) : NULL;
  if (kn && kn->data && kn->class_id == 0x03031000u && ka)
    read_skin(&b, ka);
  w->skin_entry_count = b.entry_count;
  w->skin_entries = b.entries;

  /* the environment's weather manager and its (first) weather */
  tmuf_asset *wa = NULL, *fa = NULL;
  tmuf_gbx_node *wn = find_external(s->decoration_scene_asset, ".MotionManagerWeathers.Gbx");
  if (wn) {
    tmuf_weather_file mf = node_file(&b, s->decoration_scene_asset, wn);
    w->manager = mf.pack_file;
    wn = tmuf_assets_follow(&s->assets, s->decoration_scene_asset, wn, &wa);
  }
  const tmuf_motion_weathers *mw = wn && wn->data && wn->class_id == 0x08053000u ? wn->data : NULL;
  tmuf_gbx_node *fn = mw && mw->weathers.count ? tmuf_assets_follow(&s->assets, wa, mw->weathers.nodes[0], &fa) : NULL;
  if (fn && fn->data && fn->class_id == 0x05034000u) {
    const tmuf_func_weather *f = fn->data;
    w->name = dup(arena, f->name);
    for (int i = 0; i < 2; i++) {
      memcpy(w->fogs[i].rgb, f->fogs[i].rgb, sizeof w->fogs[i].rgb);
      w->fogs[i].start = f->fogs[i].start;
      w->fogs[i].end = f->fogs[i].end;
      w->fogs[i].density = f->fogs[i].density;
      w->fogs[i].flags = f->fogs[i].flags;
      w->spec_intensity[i] = f->spec_intensity[i];
      w->spec_power[i] = f->spec_power[i];
    }
    w->light_ambient = picture(&b, fa, f->light_ambient);
    w->light_sun = picture(&b, fa, f->light_sun);
    w->light_moon = picture(&b, fa, f->light_moon);
    w->light_double_sided = picture(&b, fa, f->light_double_sided);
    w->fog_color = picture(&b, fa, f->fog_color);
    w->sea_color = picture(&b, fa, f->sea_color);
    w->sky_gradient = picture(&b, fa, f->sky_gradient);
    w->flare_sun = bitmap_picture(&b, fa, f->flare_sun);
    w->sun_flare = w->start.state != TMUF_DAY_NIGHT && f->flare_sun != NULL;
    w->flare_moon = bitmap_picture(&b, fa, f->flare_moon);
    w->flare_size_sun = f->flare_size_sun;
    w->flare_size_moon = f->flare_size_moon;
    for (int i = 0; i < 4; i++)
      w->sky_materials[i] = picture(&b, fa, f->sky_materials[i]);
    for (int i = 0; i < 2; i++)
      w->sea_materials[i] = picture(&b, fa, f->sea_materials[i]);

    /* its clouds: inline, or a file the skin may swap */
    tmuf_asset *ca = NULL;
    tmuf_gbx_node *cn = NULL;
    if (f->clouds && f->clouds->external) {
      w->clouds = picture(&b, fa, f->clouds);
      ca = load_pack_file(&b, w->clouds, 0x0503a000u);
      cn = ca ? &ca->gbx.nodes[0] : NULL;
    } else if (f->clouds) {
      cn = tmuf_assets_follow(&s->assets, fa, f->clouds, &ca);
    }
    if (cn && cn->data && cn->class_id == 0x0503a000u) {
      const tmuf_func_clouds *c = cn->data;
      w->clouds_min = picture(&b, ca, c->color_min);
      w->clouds_max = picture(&b, ca, c->color_max);
      build_sky_clouds(wd, s, arena, ca, c);
    }
  }

  /* the clouds map's layer: the skin's "Clouds" CFuncShaderLayerUV */
  for (uint32_t i = 0; i < b.entry_count && !w->has_clouds_layer; i++) {
    const tmuf_weather_skin_entry *e = &b.entries[i];
    if (!ieq(e->name, "Clouds"))
      continue;
    tmuf_weather_file lf = e->file;
    tmuf_asset *la = load_pack_file(&b, lf, 0x05015000u);
    if (!la) {
      lf = e->default_file;
      la = load_pack_file(&b, lf, 0x05015000u);
    }
    const tmuf_func_layer_uv *l = la ? la->root : NULL;
    if (!l || l->signal != 4u)
      continue;
    w->has_clouds_layer = 1;
    w->clouds_layer = lf;
    memcpy(w->clouds_offset, l->vec28, sizeof w->clouds_offset);
    memcpy(w->clouds_speed, l->vec30, sizeof w->clouds_speed);
    memcpy(w->clouds_scale, l->vec38, sizeof w->clouds_scale);
    w->clouds_period = l->has_period ? l->period : 1.0f;
  }
  wd->found = 1;
  return 1;
}
