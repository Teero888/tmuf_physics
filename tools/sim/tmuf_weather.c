/* tmuf_weather: a map's weather (tmuf_track_weather) and the light it
   gives at its start time, the pictures sampled as the game does (TGA
   pictures only).

   tmuf_weather PACKS MAP.Challenge.Gbx...

   TMUF_WEATHER_CLOUDS="EYEX EYEY EYEZ FAR MS" also lists the 3D clouds as
   placed for that camera and clock. */

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

/* a TGA's pixels (BGR or BGRA), rows as stored */
typedef struct picture {
  uint32_t w, h, bytes;
  uint8_t *pixels;
} picture;

static int load_tga(const tmuf_packs *packs, const tmuf_weather_file *f, picture *p) {
  memset(p, 0, sizeof *p);
  size_t n = 0;
  uint8_t *d = f->file ? read_file(f->file, &n) : f->pack_file ? tmuf_packs_read(packs, f->pack_file, &n) : NULL;
  if (!d || n < 18) {
    free(d);
    return 0;
  }
  const uint32_t type = d[2], w = d[12] | (uint32_t)d[13] << 8, h = d[14] | (uint32_t)d[15] << 8, bpp = d[16];
  const size_t px = bpp / 8u;
  size_t o = 18u + d[0], need = (size_t)w * h * px;
  if ((type != 2 && type != 10) || (px != 3 && px != 4) || !(p->pixels = malloc(need ? need : 1))) {
    free(d);
    return 0;
  }
  if (type == 2) {
    if (o + need > n) {
      free(d);
      free(p->pixels);
      return 0;
    }
    memcpy(p->pixels, d + o, need);
  } else {
    size_t out = 0;
    while (out < need && o < n) {
      const uint8_t c = d[o++];
      const size_t count = (size_t)(c & 0x7f) + 1;
      for (size_t k = 0; k < count && out < need; k++) {
        if (o + px > n)
          break;
        memcpy(p->pixels + out, d + o, px);
        out += px;
        if (!(c & 0x80))
          o += px;
      }
      if (c & 0x80)
        o += px;
    }
  }
  free(d);
  p->w = w;
  p->h = h;
  p->bytes = (uint32_t)px;
  return 1;
}

static const char *name_of(const tmuf_weather_file *f) { return f->pack_file ? f->pack_file : f->file ? f->file : "-"; }

/* the picture at (time, 0) as rgb bytes; 1,1,1 (255) when not loaded */
static void sample(const tmuf_packs *packs, const char *what, const tmuf_weather_file *f, float u, uint8_t rgb[3]) {
  picture p;
  rgb[0] = rgb[1] = rgb[2] = 255;
  if (!f->file && !f->pack_file) {
    printf("  %-22s none\n", what);
    return;
  }
  if (load_tga(packs, f, &p)) {
    uint8_t out[4];
    tmuf_picture_sample(p.pixels, p.w, p.h, p.bytes, u, 0.0f, out);
    rgb[0] = out[2];
    rgb[1] = out[1];
    rgb[2] = out[0];
    free(p.pixels);
  }
  printf("  %-22s (%3u,%3u,%3u) = (%.6f, %.6f, %.6f)  %s\n", what, rgb[0], rgb[1], rgb[2], rgb[0] / 255.0, rgb[1] / 255.0, rgb[2] / 255.0,
         name_of(f));
}

static void print_sky_clouds(const tmuf_weather *w) {
  const tmuf_weather_sky_clouds *k = &w->sky_clouds;
  printf("sky clouds: %u solids, %u pieces, grid %g x %g, wind %g/s dir %g, center %s (%g, %g), heights %g .. %g\n", k->solid_count, k->piece_count,
         (double)k->grid_size[0], (double)k->grid_size[1], (double)k->wind_speed, (double)k->wind_dir, k->has_center ? "yes" : "no",
         (double)k->center[0], (double)k->center[1], (double)k->height0, (double)k->height_far);
  for (uint32_t i = 0; i < k->key_count; i++)
    printf("  key distance %g height %g\n", (double)k->keys[i][0], (double)k->keys[i][1]);
  for (uint32_t i = 0; i < k->piece_count; i++) {
    const tmuf_weather_cloud_piece *p = &k->pieces[i];
    const tmuf_visual_instance *in = &k->visuals.instances[p->instance];
    const tmuf_visual_mesh *m = &k->visuals.meshes[in->mesh];
    const tmuf_visual_material *mat = in->material < k->visuals.material_count ? &k->visuals.materials[in->material] : NULL;
    printf("  piece %u solid %u mesh %u (%u sprites, flags %x, atlas %ux%u, axis (%g %g %g) offset (%g %g)) center (%g, %g, "
           "%g) half (%g, %g, %g) material %s",
           i, p->solid, in->mesh, m->vertex_count, m->sprite_flags, m->sprite_atlas[0], m->sprite_atlas[1], (double)m->sprite_axis[0],
           (double)m->sprite_axis[1], (double)m->sprite_axis[2], (double)m->sprite_offset[0], (double)m->sprite_offset[1], (double)p->center[0],
           (double)p->center[1], (double)p->center[2], (double)m->bounds[3], (double)m->bounds[4], (double)m->bounds[5], mat ? mat->name : "-");
    for (uint32_t t = 0; mat && t < mat->texture_count; t++)
      printf(" [%s %s]", mat->textures[t].sampler ? mat->textures[t].sampler : "-",
             mat->textures[t].pack_file ? mat->textures[t].pack_file
             : mat->textures[t].file    ? mat->textures[t].file
                                        : "generated");
    printf("\n");
  }
  const char *env = getenv("TMUF_WEATHER_CLOUDS");
  float eye[3], far_distance;
  unsigned ms;
  if (!env || sscanf(env, "%f %f %f %f %u", &eye[0], &eye[1], &eye[2], &far_distance, &ms) != 5)
    return;
  const uint32_t n = tmuf_weather_clouds_place(w, eye, far_distance, ms, NULL, 0);
  tmuf_cloud_draw *d = malloc(sizeof *d * (n ? n : 1));
  if (!d)
    return;
  tmuf_weather_clouds_place(w, eye, far_distance, ms, d, n);
  for (uint32_t i = 0; i < n; i++) {
    const tmuf_iso4 *l = &d[i].location;
    printf("  draw %u piece %u t (%.2f, %.2f, %.2f) r (%g %g %g | %g %g %g | %g %g %g)\n", i, d[i].piece, (double)l->t.x, (double)l->t.y,
           (double)l->t.z, (double)l->r.m[0][0], (double)l->r.m[0][1], (double)l->r.m[0][2], (double)l->r.m[1][0], (double)l->r.m[1][1],
           (double)l->r.m[1][2], (double)l->r.m[2][0], (double)l->r.m[2][1], (double)l->r.m[2][2]);
  }
  free(d);
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "usage: tmuf_weather PACKS MAP...\n");
    return 2;
  }
  char err[512];
  tmuf_packs *packs = tmuf_packs_open(argv[1], err, sizeof err);
  if (!packs) {
    fprintf(stderr, "packs: %s\n", err);
    return 1;
  }
  for (int a = 2; a < argc; a++) {
    size_t size;
    void *map = read_file(argv[a], &size);
    if (!map) {
      fprintf(stderr, "cannot read %s\n", argv[a]);
      continue;
    }
    tmuf_track_options opt = {NULL, 0, 0, TMUF_TRACK_VISUALS};
    tmuf_track *track = tmuf_track_load(packs, map, size, &opt, err, sizeof err);
    free(map);
    if (!track) {
      fprintf(stderr, "%s: %s\n", argv[a], err);
      continue;
    }
    printf("== %s: %s %s\n", argv[a], tmuf_track_environment(track), tmuf_track_decoration(track));
    const tmuf_weather *w = tmuf_track_weather(track);
    if (!w) {
      printf("no weather\n");
      tmuf_track_free(track);
      continue;
    }
    const tmuf_scenery_light *sl = tmuf_track_scenery_light(track);
    if (sl) {
      printf("scenery: vertex lighting %u color vertex %g..%g scale/trans (%g, %g) shadow %u (+88 %g +8c %u +90 %u)\n", sl->vertex_lighting,
             (double)sl->color_vertex_min, (double)sl->color_vertex_max, (double)sl->prelight_scale, (double)sl->prelight_trans, sl->shadow_mode,
             (double)sl->shadow_88, sl->shadow_8c, sl->shadow_90);
      printf("  ambient %d: rgb (%g, %g, %g) intensity %g flags %x heights %g..%g cube %s (%u) gradient %s (%u)\n", sl->has_ambient,
             (double)sl->ambient_rgb[0], (double)sl->ambient_rgb[1], (double)sl->ambient_rgb[2], (double)sl->ambient_intensity, sl->ambient_flags,
             (double)sl->height_min, (double)sl->height_max, name_of(&sl->ambient_cube), sl->cube_size, name_of(&sl->ambient_gradient),
             sl->gradient_width);
      const float *b = sl->static_box;
      printf("  static box x %g..%g y %g..%g z %g..%g\n", (double)(b[0] - b[3]), (double)(b[0] + b[3]), (double)(b[1] - b[4]), (double)(b[1] + b[4]),
             (double)(b[2] - b[5]), (double)(b[2] + b[5]));
      const float up[3] = {0, 1, 0}, side[3] = {0, 0, 1};
      for (float y = 0.0f; y <= 160.0f; y += 40.0f) {
        const float pos[3] = {100.0f, y, 100.0f};
        uint8_t c[4], d[4];
        tmuf_scenery_prelight(sl, 4u, pos, up, NULL, 0, c);
        tmuf_scenery_prelight(sl, 4u, pos, side, NULL, 0, d);
        printf("  prelight at y %g: up (%u, %u, %u, %u) side +z (%u, %u, %u)\n", (double)y, c[2], c[1], c[0], c[3], d[2], d[1], d[0]);
      }
    }
    const tmuf_weather_mood *m = &w->mood;
    printf("mood: latitude %g start %g (sunrise %gh sunset %gh, unused) folder %s\n", (double)m->latitude, (double)m->remapped_start_day_time,
           m->time_sun_rise / 3.6e6, m->time_sun_fall / 3.6e6, m->folder);
    printf("  shadows: human %u opponent %u intensity %g scene %d background locally lighted %d; pack lightmap %s\n", m->shadow_count_car_human,
           m->shadow_count_car_opponent, (double)m->shadow_car_intensity, m->shadow_scene, m->background_is_locally_lighted,
           name_of(&m->pack_light_map));
    const tmuf_ambient_occlusion *ao = &m->ambient_occlusion;
    printf("  ambient occlusion%s %s: radius %g power %g blur %u mid gray (%g, %g, %g)\n", ao->from_file ? "" : " (defaults)",
           ao->from_file ? name_of(&ao->file) : "-", (double)ao->radius, (double)ao->power, ao->blur_texels, (double)ao->mid_gray[0],
           (double)ao->mid_gray[1], (double)ao->mid_gray[2]);
    printf("manager %s weather %s\n", w->manager ? w->manager : "-", w->name ? w->name : "-");
    for (int i = 0; i < 2; i++)
      printf("  fog %s: rgb (%g, %g, %g) start %g end %g density %g flags %x\n", i ? "day  " : "night", (double)w->fogs[i].rgb[0],
             (double)w->fogs[i].rgb[1], (double)w->fogs[i].rgb[2], (double)w->fogs[i].start, (double)w->fogs[i].end, (double)w->fogs[i].density,
             w->fogs[i].flags);
    printf("  spec intensity %g/%g power %g/%g; flares %g/%g %s %s\n", (double)w->spec_intensity[0], (double)w->spec_intensity[1],
           (double)w->spec_power[0], (double)w->spec_power[1], (double)w->flare_size_sun, (double)w->flare_size_moon, name_of(&w->flare_sun),
           name_of(&w->flare_moon));
    printf("  sky materials %s %s %s %s; sea %s %s\n", name_of(&w->sky_materials[0]), name_of(&w->sky_materials[1]), name_of(&w->sky_materials[2]),
           name_of(&w->sky_materials[3]), name_of(&w->sea_materials[0]), name_of(&w->sea_materials[1]));
    printf("  pictures: sea %s sky gradient %s; clouds %s\n", name_of(&w->sea_color), name_of(&w->sky_gradient), name_of(&w->clouds));
    printf("  clouds layer %s: scale (%g, %g) speed (%g, %g) offset (%g, %g) period %g s\n", w->has_clouds_layer ? name_of(&w->clouds_layer) : "none",
           (double)w->clouds_scale[0], (double)w->clouds_scale[1], (double)w->clouds_speed[0], (double)w->clouds_speed[1],
           (double)w->clouds_offset[0], (double)w->clouds_offset[1], (double)w->clouds_period);
    for (uint32_t i = 0; i < w->skin_entry_count; i++) {
      const tmuf_weather_skin_entry *e = &w->skin_entries[i];
      printf("  skin %-16s %08x %s%s%s\n", e->name, e->class_id, name_of(&e->default_file),
             e->file.file != e->default_file.file || e->file.pack_file != e->default_file.pack_file ? " -> " : "",
             e->file.file != e->default_file.file || e->file.pack_file != e->default_file.pack_file ? name_of(&e->file) : "");
    }
    const tmuf_day_time *t = &w->start;
    printf("time: ms %u T %.9g R %.9g state %u day %d sun %.9g night %.9g day %.9g\n", t->ms, (double)t->time, (double)t->remapped, t->state,
           t->is_day, (double)t->sun_position, (double)t->night, (double)t->day);
    printf("  GbxDayTime (%.6f, %.6f, 0, 1)\n", (double)t->time, (double)t->remapped);
    uint8_t sun[3], moon[3], amb[3], dbl[3], cmin[3], cmax[3], fogc[3];
    sample(packs, "light sun", &w->light_sun, t->remapped, sun);
    sample(packs, "light moon", &w->light_moon, t->remapped, moon);
    sample(packs, "light ambient", &w->light_ambient, t->remapped, amb);
    printf("  %-22s w = %.6f\n", "ambient", 1.0 - (amb[0] + amb[1] + amb[2]) / 3.0 / 255.0);
    if (w->light_double_sided.file || w->light_double_sided.pack_file)
      sample(packs, "light double sided", &w->light_double_sided, t->remapped, dbl);
    sample(packs, "clouds min", &w->clouds_min, t->remapped, cmin);
    sample(packs, "clouds max", &w->clouds_max, t->remapped, cmax);
    float dir[3];
    const int is_moon = tmuf_day_time_light(t, sun, moon, dir);
    printf("  light %s dir (%.6f, %.6f, %.6f)\n", is_moon ? "moon" : "sun", (double)dir[0], (double)dir[1], (double)dir[2]);
    tmuf_weather_fog fog;
    float si, sp;
    tmuf_weather_at(w, t, &fog, &si, &sp);
    printf("  fog start %g end %g density %g rgb (%g, %g, %g) = (%g, %g, %g)/255\n", (double)fog.start, (double)fog.end, (double)fog.density,
           (double)fog.rgb[0], (double)fog.rgb[1], (double)fog.rgb[2], (double)fog.rgb[0] * 255, (double)fog.rgb[1] * 255, (double)fog.rgb[2] * 255);
    if (w->fog_color.file || w->fog_color.pack_file)
      sample(packs, "fog colour picture", &w->fog_color, t->remapped, fogc);
    printf("  spec intensity %g power %g\n", (double)si, (double)sp);
    if (w->has_clouds_layer) {
      const double s2 = sqrt(2.0), s6 = sqrt(6.0);
      printf("  clouds rows u (0, %.9g, %.9g) v (%.9g, %.9g, %.9g)\n", -w->clouds_scale[0] / s2, w->clouds_scale[0] / s2, 2 * w->clouds_scale[1] / s6,
             w->clouds_scale[1] / s6, -w->clouds_scale[1] / s6);
    }
    print_sky_clouds(w);
    tmuf_track_free(track);
  }
  tmuf_packs_close(packs);
  return 0;
}
