/* The scenery lighting of the vertex-lit environments (tmuf_scenery_light)
   and the game's prelight bake (CHmsZoneVPacker::PrecalcLighting,
   TmForeverFixed 2.11.26 0x560b90). */

#include "common/scenery.h"

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/assets.h"
#include "common/pack.h"
#include "common/pack_classes.h"
#include "common/packset.h"

enum { CLS_BITMAP = 0x09011000u, CLS_GX_LIGHT_AMBIENT = 0x04005000u };

static const char *dup(tmuf_arena *a, const char *s) { return s ? tmuf_arena_strndup(a, s, strlen(s)) : NULL; }

/* the image file of a CPlugBitmap reference: in the packs, else on disk */
static tmuf_weather_file bitmap_image(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *ref, tmuf_arena *arena) {
  tmuf_weather_file f = {NULL, NULL};
  tmuf_asset *ba;
  tmuf_gbx_node *bn = ref ? tmuf_assets_follow(&s->assets, owner, ref, &ba) : NULL;
  if (!bn || !bn->data || !bn->cls || bn->cls->id != CLS_BITMAP)
    return f;
  const tmuf_plug_bitmap *bm = bn->data;
  if (!bm->image || !bm->image->external)
    return f;
  char path[1200];
  if (tmuf_packset_resolve(s->assets.set, &ba->gbx, bm->image, ba->path, path, sizeof path).pack >= 0)
    f.pack_file = dup(arena, path);
  else if (tmuf_packset_resolve_file(s->assets.set, &ba->gbx, bm->image, ba->path, path, sizeof path))
    f.file = dup(arena, path);
  return f;
}

static uint8_t *read_image(const tmuf_scene *s, tmuf_weather_file f, size_t *size) {
  *size = 0;
  if (f.pack_file) {
    const tmuf_pack_ref ref = tmuf_packset_find(s->assets.set, f.pack_file);
    uint8_t *data = NULL;
    if (ref.pack < 0 || !tmuf_pack_extract(&s->assets.set->packs[ref.pack], ref.file, &data, size))
      return NULL;
    return data;
  }
  if (!f.file)
    return NULL;
  FILE *fp = fopen(f.file, "rb");
  if (!fp)
    return NULL;
  uint8_t *data = NULL;
  if (fseek(fp, 0, SEEK_END) == 0) {
    const long n = ftell(fp);
    if (n > 0 && fseek(fp, 0, SEEK_SET) == 0 && (data = malloc((size_t)n)) != NULL) {
      if (fread(data, 1, (size_t)n, fp) == (size_t)n) {
        *size = (size_t)n;
      } else {
        free(data);
        data = NULL;
      }
    }
  }
  fclose(fp);
  return data;
}

static uint32_t le32(const uint8_t *p) { return (uint32_t)p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24; }

static uint32_t mask_shift(uint32_t mask) {
  uint32_t k = 0;
  while (mask && !(mask & 1u)) {
    mask >>= 1;
    k++;
  }
  return k;
}

/* An uncompressed 24 or 32 bit DDS (2D or cube): its mip 0 as RGB bytes,
   faces one after the other in the file's order, rows as stored. */
static uint8_t *dds_rgb(const uint8_t *d, size_t size, uint32_t *w, uint32_t *h, uint32_t *faces, tmuf_arena *arena) {
  if (size < 128 || memcmp(d, "DDS ", 4) != 0)
    return NULL;
  const uint32_t height = le32(d + 12), width = le32(d + 16), mips_field = le32(d + 28);
  const uint32_t pf_flags = le32(d + 80), bits = le32(d + 88);
  const uint32_t masks[3] = {le32(d + 92), le32(d + 96), le32(d + 100)};
  const uint32_t caps2 = le32(d + 112);
  if (!(pf_flags & 0x40u) || (bits != 24 && bits != 32) || !width || !height || width > 16384 || height > 16384)
    return NULL;
  const uint32_t mips = mips_field ? mips_field : 1u;
  const uint32_t nf = (caps2 & 0x200u) ? 6u : 1u;
  const size_t bpp = bits / 8u;
  size_t face_bytes = 0;
  for (uint32_t m = 0, mw = width, mh = height; m < mips; m++) {
    face_bytes += (size_t)mw * mh * bpp;
    mw = mw > 1 ? mw / 2 : 1;
    mh = mh > 1 ? mh / 2 : 1;
  }
  if (128 + face_bytes * (nf - 1) + (size_t)width * height * bpp > size)
    return NULL;
  uint8_t *out = TMUF_ARENA_ARRAY(arena, uint8_t, (size_t)width * height * 3u * nf);
  if (!out)
    return NULL;
  uint32_t shift[3];
  for (int c = 0; c < 3; c++)
    shift[c] = mask_shift(masks[c]);
  for (uint32_t f = 0; f < nf; f++) {
    const uint8_t *src = d + 128 + face_bytes * f;
    uint8_t *dst = out + (size_t)width * height * 3u * f;
    for (size_t i = 0; i < (size_t)width * height; i++) {
      const uint32_t v = bpp == 4 ? le32(src + i * 4) : (uint32_t)src[i * 3] | (uint32_t)src[i * 3 + 1] << 8 | (uint32_t)src[i * 3 + 2] << 16;
      for (int c = 0; c < 3; c++)
        dst[i * 3 + (size_t)c] = (uint8_t)((v & masks[c]) >> shift[c]);
    }
  }
  *w = width;
  *h = height;
  *faces = nf;
  return out;
}

static int ieq(const char *a, const char *b) {
  for (; *a && *b; a++, b++) {
    int x = (unsigned char)*a, y = (unsigned char)*b;
    x = x >= 'A' && x <= 'Z' ? x + 32 : x == '/' ? '\\' : x;
    y = y >= 'A' && y <= 'Z' ? y + 32 : y == '/' ? '\\' : y;
    if (x != y)
      return 0;
  }
  return *a == *b;
}

/* the file the mood's skin swaps f for (e.g. "AmbCube", "AmbGrad") */
static tmuf_weather_file skinned(const tmuf_weather *w, tmuf_weather_file f) {
  for (uint32_t i = 0; w && i < w->skin_entry_count; i++) {
    const tmuf_weather_file d = w->skin_entries[i].default_file;
    if ((f.pack_file && d.pack_file && ieq(f.pack_file, d.pack_file)) || (f.file && d.file && ieq(f.file, d.file)))
      return w->skin_entries[i].file;
  }
  return f;
}

/* the decoration scene's ambient light: the first CSceneLight whose light
   is a GxLightAmbient */
static void ambient_light(tmuf_scenery_light *v, tmuf_scene *s, const tmuf_weather *weather, tmuf_arena *arena) {
  tmuf_asset *sa = s->decoration_scene_asset;
  if (!sa || !sa->root)
    return;
  const tmuf_scene3d *sc = sa->root;
  for (int k = 0; k < 6 && !v->has_ambient; k++)
    for (uint32_t i = 0; i < sc->objects[k].count && !v->has_ambient; i++) {
      tmuf_asset *oa;
      tmuf_gbx_node *on = tmuf_assets_follow(&s->assets, sa, sc->objects[k].nodes[i], &oa);
      if (!on || !on->data || !on->cls || on->cls->id != 0x0a005000u)
        continue;
      const tmuf_scene_object *o = on->data;
      if (!o->has_light || !o->light.light)
        continue;
      tmuf_asset *la;
      tmuf_gbx_node *ln = tmuf_assets_follow(&s->assets, oa, o->light.light, &la);
      if (!ln || !ln->data || ln->class_id != CLS_GX_LIGHT_AMBIENT)
        continue;
      const tmuf_gx_light *g = ln->data;
      v->has_ambient = 1;
      memcpy(v->ambient_rgb, g->rgb, sizeof v->ambient_rgb);
      v->ambient_intensity = g->intensity;
      v->ambient_flags = g->flags;
      v->height_min = g->ambient_height[0];
      v->height_max = g->ambient_height[1];
      v->ambient_cube = skinned(weather, bitmap_image(s, oa, o->light.bitmaps[0], arena));
      v->ambient_gradient = skinned(weather, bitmap_image(s, oa, o->light.bitmaps[1], arena));
    }
  if (!v->has_ambient)
    return;
  size_t n;
  uint8_t *data = read_image(s, v->ambient_cube, &n);
  uint32_t w, h, faces;
  const uint8_t *px = data ? dds_rgb(data, n, &w, &h, &faces, arena) : NULL;
  if (px && faces == 6 && w == h) {
    v->cube_size = w;
    v->cube_pixels = px;
  }
  free(data);
  data = read_image(s, v->ambient_gradient, &n);
  px = data ? dds_rgb(data, n, &w, &h, &faces, arena) : NULL;
  if (px && faces == 1) {
    /* the game keeps a 2D DDS flipped: its row 0 is the file's last */
    v->gradient_width = w;
    v->gradient_row = px + (size_t)w * (h - 1u) * 3u;
  }
  free(data);
}

static float clamp01(float x) { return x < 0.0f ? 0.0f : x > 1.0f ? 1.0f : x; }

int tmuf_scenery_build(tmuf_scenery_data *out, tmuf_scene *s, const tmuf_visuals *visuals, const tmuf_weather *weather, const tmuf_light *lights,
                       uint32_t light_count, tmuf_arena *arena) {
  memset(out, 0, sizeof *out);
  tmuf_scenery_light *v = &out->view;
  const tmuf_collection *c = s->collection_info;
  if (c && c->has_lighting) {
    v->vertex_lighting = c->vertex_lighting;
    v->color_vertex_min = c->color_vertex_min;
    v->color_vertex_max = c->color_vertex_max;
    v->shadow_mode = c->shadow_mode;
    v->shadow_88 = c->shadow_88;
    v->shadow_8c = c->shadow_8c;
    v->shadow_90 = c->shadow_90;
  } else {
    v->color_vertex_max = 1.0f;
  }
  /* CHmsZoneVPacker::SetCreateParams */
  v->prelight_scale = clamp01(v->color_vertex_max - v->color_vertex_min);
  v->prelight_trans = clamp01(v->color_vertex_min);
  ambient_light(v, s, weather, arena);

  /* the static box: the map's blocks and automatic blocks (terrain) */
  float lo[3] = {FLT_MAX, FLT_MAX, FLT_MAX}, hi[3] = {-FLT_MAX, -FLT_MAX, -FLT_MAX};
  for (uint32_t i = 0; visuals && i < visuals->instance_count; i++) {
    const tmuf_visual_instance *in = &visuals->instances[i];
    if ((in->block & 0xc0000000u) == 0xc0000000u || in->mesh >= visuals->mesh_count)
      continue;
    const float *b = visuals->meshes[in->mesh].bounds;
    const float (*r)[3] = in->location.r.m;
    const float t[3] = {in->location.t.x, in->location.t.y, in->location.t.z};
    for (int k = 0; k < 3; k++) {
      const float cen = r[k][0] * b[0] + r[k][1] * b[1] + r[k][2] * b[2] + t[k];
      const float half = fabsf(r[k][0]) * b[3] + fabsf(r[k][1]) * b[4] + fabsf(r[k][2]) * b[5];
      lo[k] = fminf(lo[k], cen - half);
      hi[k] = fmaxf(hi[k], cen + half);
    }
  }
  for (int k = 0; k < 3 && lo[0] <= hi[0]; k++) {
    v->static_box[k] = 0.5f * (lo[k] + hi[k]);
    v->static_box[3 + k] = 0.5f * (hi[k] - lo[k]);
  }
  /* the lamps: the bake's (ball and spot, DIFFUSE); a NightOnly light
     on a day map has none (CPlugTreeLight::ApplyFidParameters drops its
     light: the global it tests is 1 and never written) */
  const int night = weather && weather->is_night;
  out->lamps = TMUF_ARENA_ARRAY(arena, tmuf_light, light_count ? light_count : 1);
  if (!out->lamps)
    return 0;
  for (uint32_t i = 0; i < light_count; i++) {
    const tmuf_light *l = &lights[i];
    if ((l->kind == TMUF_LIGHT_BALL || l->kind == TMUF_LIGHT_SPOT) && (l->flags & TMUF_LIGHT_FLAG_DIFFUSE) && !(l->night_only && !night))
      out->lamps[out->lamp_count++] = *l;
  }
  out->found = 1;
  return 1;
}

/* ---- the bake ---- */

/* CPlugFileImg::FilterCubePixel, point: the major axis picks the face
   (ties: x before y before z), then D3D's face coordinates over |major| */
static void cube_point(const tmuf_scenery_light *v, const float n[3], float rgb[3]) {
  const float ax = fabsf(n[0]), ay = fabsf(n[1]), az = fabsf(n[2]);
  int axis = ay > ax ? 1 : 0;
  const float m = axis ? ay : ax;
  if (m < az)
    axis = 2;
  const float ma = fabsf(n[axis]);
  const int face = 2 * axis + (n[axis] < 0.0f || (n[axis] == 0.0f && signbit(n[axis])));
  float sc, tc;
  switch (face) {
  case 0:
    sc = -n[2];
    tc = -n[1];
    break;
  case 1:
    sc = n[2];
    tc = -n[1];
    break;
  case 2:
    sc = n[0];
    tc = n[2];
    break;
  case 3:
    sc = n[0];
    tc = -n[2];
    break;
  case 4:
    sc = n[0];
    tc = -n[1];
    break;
  default:
    sc = -n[0];
    tc = -n[1];
    break;
  }
  float u = 0.0f, w = 0.0f;
  if (ma > 1e-6f) {
    const float inv = 1.0f / ma;
    u = inv * sc;
    w = inv * tc;
  }
  u = u * 0.5f + 0.5f;
  w = w * 0.5f + 0.5f;
  const uint32_t size = v->cube_size;
  uint32_t x = (uint32_t)(int32_t)(u * (float)size), y = (uint32_t)(int32_t)(w * (float)size);
  x %= size;
  y %= size;
  const uint8_t *p = v->cube_pixels + (((size_t)face * size + y) * size + x) * 3u;
  for (int k = 0; k < 3; k++)
    rgb[k] = (float)p[k] / 255.0f;
}

static float sat(float x) { return x < 0.0f ? 0.0f : x > 1.0f ? 1.0f : x; }

void tmuf_scenery_prelight(const tmuf_scenery_light *v, uint32_t generic_flags, const float p[3], const float n[3], const tmuf_light *lights,
                           uint32_t light_count, uint8_t bgra[4]) {
  float c[3] = {0.0f, 0.0f, 0.0f}, a = 1.0f;
  const int diffuse = (generic_flags & 4u) != 0;
  if (v && diffuse && (v->cube_pixels || v->gradient_row)) {
    float cube[3] = {1.0f, 1.0f, 1.0f}, grad[3] = {0.5f, 0.5f, 0.5f};
    if (v->cube_pixels && v->cube_size)
      cube_point(v, n, cube);
    if (v->gradient_row && v->gradient_width) {
      float t = (p[1] - v->height_min) / (v->height_max - v->height_min);
      t = t < 0.0f ? 0.0f : t > 0.9999f ? 0.9999f : t;
      const uint32_t x = (uint32_t)(int32_t)(t * (float)v->gradient_width);
      for (int k = 0; k < 3; k++)
        grad[k] = (float)v->gradient_row[x * 3u + (uint32_t)k] / 255.0f;
    }
    for (int k = 0; k < 3; k++)
      c[k] = cube[k] * 2.0f * grad[k];
  } else if (v) {
    for (int k = 0; k < 3; k++)
      c[k] = v->ambient_rgb[k] * v->ambient_intensity;
  }
  for (uint32_t i = 0; i < light_count; i++) {
    const tmuf_light *l = &lights[i];
    if (!(l->flags & TMUF_LIGHT_FLAG_DIFFUSE) || (l->kind != TMUF_LIGHT_BALL && l->kind != TMUF_LIGHT_SPOT))
      continue;
    const float L[3] = {l->position[0] - p[0], l->position[1] - p[1], l->position[2] - p[2]};
    const float d = sqrtf(L[0] * L[0] + L[1] * L[1] + L[2] * L[2]), r = l->radius[0];
    if (d <= 1e-5f || d > r)
      continue;
    float att = (l->ball_flags & 0x38u) ? 1.0f - (d / r) * (d / r) : 1.0f / (1.0f + l->attenuation[0] * d + l->attenuation[1] * d * d);
    const float ndl = (n[0] * L[0] + n[1] * L[1] + n[2] * L[2]) / d;
    if (l->kind == TMUF_LIGHT_SPOT) {
      /* PrecalcLighting_Spot: the cone about the spot's +Z */
      const float cosa = -(l->direction[0] * L[0] + l->direction[1] * L[1] + l->direction[2] * L[2]) / d;
      if (cosa <= l->cos_outer)
        continue;
      if (cosa < l->cos_inner)
        att *= powf((cosa - l->cos_outer) / (l->cos_inner - l->cos_outer), l->falloff);
      if (!(att > 1e-4f))
        continue;
      if (diffuse)
        att *= fmaxf(0.0f, ndl);
      for (int k = 0; k < 3; k++)
        c[k] += att * l->diffuse_rgb[k];
      continue;
    }
    const float f = diffuse ? att * fmaxf(0.0f, ndl) : att;
    if (l->intensity >= 0.0f) {
      for (int k = 0; k < 3; k++)
        c[k] += att * l->intensity * l->ambient_rgb[k] + f * l->diffuse_rgb[k];
    } else {
      a *= sat(1.0f - att * sat(1.0f - l->ambient_rgb[0]));
      a *= sat(1.0f - f * sat(1.0f - l->rgb[0]));
    }
  }
  /* GxBGRAColor::Set: truncated */
  bgra[0] = (uint8_t)(int32_t)(255.0f * sat(c[2]));
  bgra[1] = (uint8_t)(int32_t)(255.0f * sat(c[1]));
  bgra[2] = (uint8_t)(int32_t)(255.0f * sat(c[0]));
  bgra[3] = (uint8_t)(int32_t)(255.0f * sat(a));
}
