/* tmuf_clips: a map's MediaTracker in-game clips (tmuf_track_ingame_clips):
   per clip its trigger cells, condition, keep-playing, end and camera blocks.

   tmuf_clips [--visuals] PACKS FILE...

   FILE: a .Challenge.Gbx, or a .Replay.Gbx (its embedded map). --visuals
   loads the tracks with TMUF_TRACK_VISUALS. Ends with the totals (maps,
   clips, cells, camera blocks by id). */

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

/* a name ending in .Replay.Gbx, any case */
static int is_replay(const char *path) {
  static const char ext[] = ".replay.gbx";
  const size_t n = strlen(path), k = sizeof ext - 1;
  if (n < k)
    return 0;
  for (size_t i = 0; i < k; i++) {
    char c = path[n - k + i];
    if (c >= 'A' && c <= 'Z')
      c = (char)(c - 'A' + 'a');
    if (c != ext[i])
      return 0;
  }
  return 1;
}

typedef struct id_count {
  char id[64];
  unsigned n;
} id_count;

static id_count ids[256];
static unsigned id_kinds;

static void count_id(const char *id) {
  for (unsigned i = 0; i < id_kinds; i++)
    if (!strcmp(ids[i].id, id)) {
      ids[i].n++;
      return;
    }
  if (id_kinds < sizeof ids / sizeof ids[0]) {
    snprintf(ids[id_kinds].id, sizeof ids[id_kinds].id, "%s", id);
    ids[id_kinds++].n = 1;
  }
}

int main(int argc, char **argv) {
  int arg = 1;
  uint32_t flags = 0;
  if (arg < argc && !strcmp(argv[arg], "--visuals")) {
    flags |= TMUF_TRACK_VISUALS;
    arg++;
  }
  if (argc - arg < 2) {
    fprintf(stderr, "usage: tmuf_clips [--visuals] PACKS FILE...\n");
    return 2;
  }
  char err[512];
  tmuf_packs *packs = tmuf_packs_open(argv[arg++], err, sizeof err);
  if (!packs) {
    fprintf(stderr, "packs: %s\n", err);
    return 1;
  }
  unsigned maps = 0, failed = 0, with_clips = 0, clips = 0, cells = 0, game = 0, custom = 0, keys = 0;
  unsigned conditions[8] = {0};
  for (; arg < argc; arg++) {
    size_t size;
    void *data = read_file(argv[arg], &size);
    if (!data) {
      printf("%s: cannot read\n", argv[arg]);
      failed++;
      continue;
    }
    const void *map = data;
    size_t map_size = size;
    tmuf_replay *replay = NULL;
    if (is_replay(argv[arg])) {
      replay = tmuf_replay_load(data, size, err, sizeof err);
      if (!replay) {
        printf("%s: replay: %s\n", argv[arg], err);
        free(data);
        failed++;
        continue;
      }
      map = tmuf_replay_map(replay, &map_size);
    }
    tmuf_track_options opt = {0};
    opt.flags = flags;
    tmuf_track *track = tmuf_track_load(packs, map, map_size, &opt, err, sizeof err);
    if (!track) {
      printf("%s: %s\n", argv[arg], err);
      tmuf_replay_free(replay);
      free(data);
      failed++;
      continue;
    }
    maps++;
    float xz, y;
    tmuf_track_trigger_cell_size(track, &xz, &y);
    const tmuf_ingame_clip *c;
    const uint32_t count = tmuf_track_ingame_clips(track, &c);
    printf("%s: %s, %u clips, cell %g x %g\n", argv[arg], tmuf_track_environment(track), count, xz, y);
    with_clips += count ? 1u : 0u;
    for (uint32_t i = 0; i < count; i++) {
      clips++;
      cells += c[i].cell_count;
      conditions[c[i].condition < 7 ? c[i].condition : 7]++;
      printf("  clip %u: cond %u %g keep %d end %g cells", i, c[i].condition, c[i].condition_value, c[i].keep_playing,
             c[i].end);
      for (uint32_t k = 0; k < c[i].cell_count; k++)
        printf(" (%u,%u,%u)", c[i].cells[k][0], c[i].cells[k][1], c[i].cells[k][2]);
      printf("\n");
      for (uint32_t k = 0; k < c[i].camera_count; k++) {
        const tmuf_clip_camera *cam = &c[i].cameras[k];
        if (cam->kind == TMUF_CLIP_CAMERA_GAME) {
          game++;
          count_id(cam->id);
          printf("    CameraGame [%g, %g]%s \"%s\" index %d entity %d\n", cam->start, cam->end,
                 cam->keep ? " keep" : "", cam->id, cam->cam_index, cam->entity);
        } else {
          custom++;
          keys += cam->key_count;
          printf("    CameraCustom [%g, %g]%s %u keys", cam->start, cam->end, cam->keep ? " keep" : "",
                 cam->key_count);
          for (uint32_t j = 0; j < cam->key_count; j++) {
            const tmuf_clip_custom_key *key = &cam->keys[j];
            printf(" | t %g interp %u pos %g %g %g pyr %g %g %g fov %g anchor %d target %d", key->time, key->interp,
                   key->pos[0], key->pos[1], key->pos[2], key->pitch, key->yaw, key->roll, key->fov, key->anchor,
                   key->target);
          }
          printf("\n");
        }
      }
    }
    tmuf_track_free(track);
    tmuf_replay_free(replay);
    free(data);
  }
  printf("total: %u loaded, %u failed, %u with clips, %u clips (triggers), %u cells\n", maps, failed, with_clips,
         clips, cells);
  printf("conditions:");
  for (int i = 0; i < 8; i++)
    printf(" %d:%u", i, conditions[i]);
  printf("\ncameras: %u CameraGame, %u CameraCustom (%u keys)\n", game, custom, keys);
  for (unsigned i = 0; i < id_kinds; i++)
    printf("  \"%s\" %u\n", ids[i].id, ids[i].n);
  tmuf_packs_close(packs);
  return failed ? 1 : 0;
}
