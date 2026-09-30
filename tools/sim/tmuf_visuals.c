/* tmuf_visuals: what a map draws (tmuf_track_visuals), for checking the
   scene data for rendering.

   tmuf_visuals PACKS MAP.Challenge.Gbx [--materials] */

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

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "usage: tmuf_visuals PACKS MAP [--materials]\n");
    return 2;
  }
  char err[512];
  tmuf_packs *packs = tmuf_packs_open(argv[1], err, sizeof err);
  if (!packs) {
    fprintf(stderr, "packs: %s\n", err);
    return 1;
  }
  size_t size;
  void *map = read_file(argv[2], &size);
  if (!map) {
    fprintf(stderr, "cannot read %s\n", argv[2]);
    return 1;
  }
  tmuf_track_options opt = {NULL, 0, 0, TMUF_TRACK_VISUALS};
  tmuf_track *track = tmuf_track_load(packs, map, size, &opt, err, sizeof err);
  if (!track) {
    fprintf(stderr, "%s\n", err);
    return 1;
  }
  const tmuf_vehicle_visuals *car = tmuf_track_vehicle_visuals(track);
  if (car) {
    uint32_t tris = 0;
    for (uint32_t i = 0; i < car->visuals.instance_count; i++)
      tris += car->visuals.meshes[car->visuals.instances[i].mesh].index_count / 3u;
    printf("vehicle %s: %u parts, %u levels, %u meshes, %u materials, %u instances, %u triangles\n",
           tmuf_track_vehicle(track), car->part_count, car->level_count, car->visuals.mesh_count,
           car->visuals.material_count, car->visuals.instance_count, tris);
    for (uint32_t k = 0; k < car->level_count; k++) {
      const tmuf_vehicle_visual_level *l = &car->levels[k];
      printf("  level quality %u root %s body %s head %s wheels %u arms %u lights %u\n", l->quality,
             l->root != TMUF_VEHICLE_NO_PART ? car->parts[l->root].name : "-",
             l->body != TMUF_VEHICLE_NO_PART ? car->parts[l->body].name : "-",
             l->pilot_head != TMUF_VEHICLE_NO_PART ? car->parts[l->pilot_head].name : "-", l->wheel_count,
             l->arm_count, l->light_count);
    }
    if (argc > 3 && strcmp(argv[3], "--materials") == 0)
      for (uint32_t i = 0; i < car->visuals.material_count; i++) {
        const tmuf_visual_material *m = &car->visuals.materials[i];
        printf("  car material %u %s flags %08x:", i, m->name, m->shader_flags[0]);
        for (uint32_t t = 0; t < m->texture_count; t++)
          printf(" %s=%s", m->textures[t].sampler,
                 m->textures[t].file ? m->textures[t].file : m->textures[t].pack_file ? m->textures[t].pack_file : "-");
        printf("\n");
      }
  }
  const tmuf_visuals *v = tmuf_track_visuals(track);
  uint64_t triangles = 0, vertices = 0;
  uint32_t no_material = 0;
  uint64_t near_triangles = 0;
  for (uint32_t i = 0; i < v->instance_count; i++) {
    if (v->instances[i].lod_near == 0.0f)
      near_triangles += v->meshes[v->instances[i].mesh].index_count / 3u;
    triangles += v->meshes[v->instances[i].mesh].index_count / 3u;
    vertices += v->meshes[v->instances[i].mesh].vertex_count;
    no_material += v->instances[i].material == UINT32_MAX;
  }
  uint32_t textures = 0, found = 0, no_textures = 0;
  for (uint32_t i = 0; i < v->material_count; i++) {
    no_textures += v->materials[i].texture_count == 0;
    for (uint32_t k = 0; k < v->materials[i].texture_count; k++) {
      textures++;
      found += v->materials[i].textures[k].file != NULL;
    }
  }
  printf("%s: %u instances of %u meshes, %llu triangles (%llu in the nearest levels), %llu vertices; %u materials (%u without textures), "
         "%u instances without material; %u texture references, %u files found\n",
         tmuf_track_name(track), v->instance_count, v->mesh_count, (unsigned long long)triangles,
         (unsigned long long)near_triangles,
         (unsigned long long)vertices, v->material_count, no_textures, no_material, textures, found);
  if (argc > 3 && strcmp(argv[3], "--materials") == 0)
    for (uint32_t i = 0; i < v->material_count; i++) {
      const tmuf_visual_material *m = &v->materials[i];
      uint32_t uses = 0;
      for (uint32_t k = 0; k < v->instance_count; k++)
        uses += v->instances[k].material == i;
      printf("material %u (%u uses) %s state %d %08x flags %08x %08x alpha test %u ref %u\n", i, uses, m->name, m->has_render_state, m->render_state[0], m->shader_flags[0],
             m->shader_flags[1], m->has_render_state ? (m->render_state[0] >> 24) & 7u : 9u,
             (m->render_state[0] >> 14) & 0xffu);
      static const char *lists[] = {"opaque", "alpha-test", "blended", "sort-custom"};
      printf("  draw: class %08x flags %08x list %s%s%s%s%s blend %d %u/%u op %u, alpha test %d ref %u func %u, alpha "
             "texture %d usage %08x%s, generic %d %x",
             m->shader_class, m->draw_flags, lists[m->draw_list & 3u], m->prepass ? " prepass" : "", m->static_shadow ? " static-shadow" : "",
             m->double_sided ? " double-sided" : "", m->shadow_caster_disable ? " no-caster" : "", m->alpha_blend, m->blend_src, m->blend_dst,
             m->blend_op, m->alpha_test, m->alpha_ref, m->alpha_func, (int)m->alpha_texture, m->alpha_texture_usage,
             m->alpha_to_coverage ? " atoc" : "", m->has_generic_flags, m->generic_flags);
      if (m->shadow_depth_bias_extra)
        printf(" bias-extra");
      printf(", visible id %04x%s\n", m->visible_id, m->hidden ? " HIDDEN" : "");
      for (uint32_t k = 0; k < m->pass_count; k++) {
        const tmuf_visual_program *pr[2] = {&m->passes[k].vertex, &m->passes[k].pixel};
        for (int j = 0; j < 2; j++) {
          printf("  pass %u %s %s", k, j ? "ps" : "vs", pr[j]->file ? pr[j]->file : "-");
          for (uint32_t c = 0; c < pr[j]->constant_count; c++)
            printf(" %s=(%g %g %g %g)", pr[j]->constant_names[c], (double)pr[j]->constants[c][0], (double)pr[j]->constants[c][1],
                   (double)pr[j]->constants[c][2], (double)pr[j]->constants[c][3]);
          printf("\n");
        }
      }
      for (uint32_t k = 0; k < m->texture_count; k++)
      {
        const tmuf_visual_texture *t = &m->textures[k];
        printf("  %-12s %s uv %u gen %u", t->sampler, t->file ? t->file : t->pack_file ? t->pack_file : "(not found)",
               t->texcoord, t->generate);
        if (t->has_transform)
          printf(" transform %g %g %g %g %g %g", t->transform[0], t->transform[1], t->transform[2], t->transform[3],
                 t->transform[4], t->transform[5]);
        if (t->has_anim)
          printf(" anim%s type %u period %g start %g %g delta %g %g scale %g %g cells %u %u %u%s (%s)",
                 t->anim_auto ? "" : " (driven)", t->anim_type, t->anim_period, t->anim_start[0], t->anim_start[1],
                 t->anim_delta[0], t->anim_delta[1], t->anim_scale[0], t->anim_scale[1], t->anim_cells[0],
                 t->anim_cells[1], t->anim_cells[2], t->anim_flip_v ? " flip" : "", t->anim_file);
        printf("\n");
      }
      for (uint32_t k = 0; k < v->instance_count; k++)
        if (v->instances[k].material == i) {
          const tmuf_visual_mesh *me = &v->meshes[v->instances[k].mesh];
          printf("  first use: mesh flags %x stride %u uv sets %u at %.1f %.1f %.1f bounds y %.1f..%.1f\n", me->flags,
                 me->vertex_stride, me->uv_set_count, v->instances[k].location.t.x, v->instances[k].location.t.y,
                 v->instances[k].location.t.z, me->bounds[1] - me->bounds[4], me->bounds[1] + me->bounds[4]);
          break;
        }
    }
  tmuf_track_free(track);
  free(map);
  tmuf_packs_close(packs);
  return 0;
}
