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
      printf("material %u %s flags %08x %08x\n", i, m->name, m->shader_flags[0], m->shader_flags[1]);
      for (uint32_t k = 0; k < m->texture_count; k++)
        printf("  %-12s %s\n", m->textures[k].sampler, m->textures[k].file ? m->textures[k].file : "(not found)");
    }
  tmuf_track_free(track);
  free(map);
  tmuf_packs_close(packs);
  return 0;
}
