/* tmuf_lights: a map's lights (tmuf_track_lights) and its car's
   (tmuf_vehicle_visuals: tree lights and lighting renders).

   tmuf_lights PACKS MAP.Challenge.Gbx...

   TMUF_LIGHTS_CAR="r00 r01 r02 r10 r11 r12 r20 r21 r22 tx ty tz" (the car's
   world location, rows of its rotation) lists the lights that reach the
   car's box as the car's vertex lights take them: flags with DIFFUSE
   (TMUF_LIGHTS_MASK), radius [0] (TMUF_LIGHTS_RADIUS), and for spots the
   outer cone reaching the box's bounding sphere,
   with the shaders' constants (Light8Spots/Balls_*) in the frame
   TMUF_LIGHTS_FRAME (same layout; default: the car's). */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <tmuf_physics/tmuf_physics.h>

static void *read_file(const char *path, size_t *size) {
  FILE *f = fopen(path, "rb");
  if (!f)
    return NULL;
  fseek(f, 0, SEEK_END);
  long n = ftell(f);
  fseek(f, 0, SEEK_SET);
  void *d = n > 0 ? malloc((size_t)n) : NULL;
  if (d && fread(d, 1, (size_t)n, f) != (size_t)n) {
    free(d);
    d = NULL;
  }
  fclose(f);
  *size = (size_t)n;
  return d;
}

static const char *kind_name(uint32_t k) {
  static const char *names[] = {"point", "ball", "spot", "other"};
  return k < 4 ? names[k] : "?";
}

static int read_pose(const char *env, float m[3][3], float t[3]) {
  const char *s = getenv(env);
  if (!s)
    return 0;
  float v[12];
  if (sscanf(s, "%f %f %f %f %f %f %f %f %f %f %f %f", &v[0], &v[1], &v[2], &v[3], &v[4], &v[5], &v[6], &v[7],
             &v[8], &v[9], &v[10], &v[11]) != 12)
    return 0;
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
      m[r][c] = v[r * 3 + c];
  for (int k = 0; k < 3; k++)
    t[k] = v[9 + k];
  return 1;
}

/* world -> frame (m rows: the frame's axes in the world) */
static void to_frame(const float m[3][3], const float t[3], const float p[3], float out[3], int point) {
  float d[3];
  for (int k = 0; k < 3; k++)
    d[k] = p[k] - (point ? t[k] : 0.0f);
  for (int k = 0; k < 3; k++)
    out[k] = m[0][k] * d[0] + m[1][k] * d[1] + m[2][k] * d[2];
}

static void print_light(const tmuf_light *l, uint32_t i) {
  printf("%4u %-5s block %08x%s flags %02x (stored %02x) plug %x pos %.4f %.4f %.4f dir %.4f %.4f %.4f\n", i,
         kind_name(l->kind), l->block, l->decorator_hidden ? " (decorator hidden)" : "", l->flags, l->archived_flags,
         l->plug_flags, l->position[0], l->position[1], l->position[2], l->direction[0], l->direction[1],
         l->direction[2]);
  printf("     rgb %.4f %.4f %.4f I %.3f diff %.3f spec %.3f pow %.3f radius %g %g %g %g", l->rgb[0], l->rgb[1],
         l->rgb[2], l->intensity, l->diffuse_intensity, l->specular_intensity, l->specular_power, l->radius[0],
         l->radius[1], l->radius[2], l->radius[3]);
  if (l->kind == TMUF_LIGHT_SPOT)
    printf(" angles %g %g flare %g falloff %g", l->angle_inner, l->angle_outer, l->angle_flare, l->falloff);
  printf("\n     flare I %.3f size %g bias %g picture %s file %s\n", l->flare_intensity, l->flare_size,
         l->flare_bias_z, l->flare_pack_file ? l->flare_pack_file : l->flare_file ? l->flare_file : "-", l->file);
}

static int boxes_meet(const float a[6], const float b[6]) {
  for (int k = 0; k < 3; k++)
    if (fabsf(a[k] - b[k]) > a[3 + k] + b[3 + k])
      return 0;
  return 1;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "usage: tmuf_lights PACKS MAP.Challenge.Gbx...\n");
    return 2;
  }
  char err[600];
  tmuf_packs *packs = tmuf_packs_open(argv[1], err, sizeof err);
  if (!packs) {
    fprintf(stderr, "packs: %s\n", err);
    return 1;
  }
  const int verbose = getenv("TMUF_LIGHTS_ALL") != NULL;
  for (int a = 2; a < argc; a++) {
    size_t size;
    void *map = read_file(argv[a], &size);
    if (!map) {
      fprintf(stderr, "%s: cannot read\n", argv[a]);
      continue;
    }
    tmuf_track_options opt = {0};
    opt.flags = TMUF_TRACK_VISUALS;
    tmuf_track *track = tmuf_track_load(packs, map, size, &opt, err, sizeof err);
    free(map);
    if (!track) {
      fprintf(stderr, "%s: %s\n", argv[a], err);
      continue;
    }
    const tmuf_weather *w = tmuf_track_weather(track);
    const tmuf_light *lights;
    const uint32_t n = tmuf_track_lights(track, &lights);
    uint32_t kinds[4] = {0}, flare = 0, night = 0, pictures = 0, hidden = 0;
    for (uint32_t i = 0; i < n; i++) {
      kinds[lights[i].kind < 4 ? lights[i].kind : 3]++;
      flare += (lights[i].flags & TMUF_LIGHT_FLAG_LENS_FLARE) != 0;
      night += lights[i].night_only;
      pictures += lights[i].flare_file || lights[i].flare_pack_file;
      hidden += lights[i].decorator_hidden;
    }
    printf("%s (%s %s): %u lights: %u point, %u ball, %u spot, %u other; %u with a flare, %u night-only, %u "
           "flare pictures, %u under decorator-hidden trees; is_night %d sun_flare %d\n",
           tmuf_track_name(track), tmuf_track_environment(track), tmuf_track_decoration(track), n, kinds[0], kinds[1],
           kinds[2], kinds[3], flare, night, pictures, hidden, w ? w->is_night : -1, w ? w->sun_flare : -1);
    if (verbose)
      for (uint32_t i = 0; i < n; i++)
        print_light(&lights[i], i);
    const tmuf_vehicle_visuals *vv = tmuf_track_vehicle_visuals(track);
    if (vv) {
      const tmuf_vehicle_lighting *g = &vv->lighting;
      printf("car %s: box %.4f %.4f %.4f / %.4f %.4f %.4f\n", tmuf_track_vehicle(track), g->box[0], g->box[1],
             g->box[2], g->box[3], g->box[4], g->box[5]);
      printf("  hemisphere %d: exp %g %g layout %u\n", g->has_hemisphere, g->hemi_exp_l, g->hemi_exp_a,
             g->hemi_layout);
      printf("  light from map %d: grid %u (max %u) footprint %g top %g depth %g white %g values %g %g %g %g %g %g "
             "up_min %g\n",
             g->has_light_from_map, g->lfm_grid, g->lfm_grid_max, g->lfm_footprint, g->lfm_top, g->lfm_depth,
             g->lfm_white, g->lfm_values[0], g->lfm_values[1], g->lfm_values[2], g->lfm_values[3], g->lfm_values[4],
             g->lfm_values[5], g->lfm_up_min);
      for (uint32_t i = 0; i < vv->light_count; i++) {
        printf("  light of part %s:\n", vv->parts[vv->lights[i].block].name);
        print_light(&vv->lights[i], i);
      }
    }
    float cm[3][3], ct[3], fm[3][3], ft[3];
    if (vv && read_pose("TMUF_LIGHTS_CAR", cm, ct)) {
      if (!read_pose("TMUF_LIGHTS_FRAME", fm, ft)) {
        memcpy(fm, cm, sizeof fm);
        memcpy(ft, ct, sizeof ft);
      }
      const char *rs = getenv("TMUF_LIGHTS_RADIUS"), *ms = getenv("TMUF_LIGHTS_MASK");
      const uint32_t which = rs ? (uint32_t)atoi(rs) : 0u, mask = ms ? (uint32_t)strtoul(ms, NULL, 0) : 1u;
      /* the car's world box: its tree box moved by its location
         (GmBoxAligned::SetMult) */
      const float *b = vv->lighting.box;
      float box[6];
      for (int k = 0; k < 3; k++) {
        box[k] = cm[k][0] * b[0] + cm[k][1] * b[1] + cm[k][2] * b[2] + ct[k];
        box[3 + k] = fabsf(cm[k][0]) * b[3] + fabsf(cm[k][1]) * b[4] + fabsf(cm[k][2]) * b[5];
      }
      printf("car world box %.3f %.3f %.3f / %.3f %.3f %.3f\n", box[0], box[1], box[2], box[3], box[4], box[5]);
      for (uint32_t i = 0; i < n; i++) {
        const tmuf_light *l = &lights[i];
        /* AddInteractLightsWithCell: the sphere's box at the pass's radius */
        float lb[6];
        for (int k = 0; k < 3; k++) {
          lb[k] = l->position[k];
          lb[3 + k] = l->radius[which < 4 ? which : 0];
        }
        if (!boxes_meet(box, lb) || l->kind > TMUF_LIGHT_SPOT || (l->flags & mask) != mask)
          continue;
        if (l->kind == TMUF_LIGHT_SPOT) {
          /* the outer cone reaches the box's bounding sphere */
          float d[3], len = 0.0f, rad = 0.0f;
          for (int k = 0; k < 3; k++) {
            d[k] = box[k] - l->position[k];
            len += d[k] * d[k];
            rad += box[3 + k] * box[3 + k];
          }
          len = sqrtf(len);
          rad = sqrtf(rad);
          if (len > rad) {
            const float cs = (d[0] * l->direction[0] + d[1] * l->direction[1] + d[2] * l->direction[2]) / len;
            const float angle = acosf(cs > 1.0f ? 1.0f : cs < -1.0f ? -1.0f : cs) - asinf(rad / len);
            if (angle > acosf(l->cos_outer))
              continue;
          }
        }
        float p[3], d[3];
        to_frame(fm, ft, l->position, p, 1);
        to_frame(fm, ft, l->direction, d, 0);
        const float r0 = l->radius[0];
        printf("%4u %-5s Rgb_IRad2 %.6g %.6g %.6g %.6g Pos %.4f %.4f %.4f", i, kind_name(l->kind), l->diffuse_rgb[0],
               l->diffuse_rgb[1], l->diffuse_rgb[2], r0 > 0.0f ? 1.0f / (r0 * r0) : 0.0f, p[0], p[1], p[2]);
        if (l->kind == TMUF_LIGHT_SPOT)
          printf(" ICosR %.6g Dir %.6f %.6f %.6f CosOt %.6f", 1.0f / (l->cos_inner - l->cos_outer), d[0], d[1], d[2],
                 l->cos_outer);
        printf(" flags %02x\n", l->flags);
      }
    }
    tmuf_track_free(track);
  }
  tmuf_packs_close(packs);
  return 0;
}
