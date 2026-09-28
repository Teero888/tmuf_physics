/* tmuf_rewrite: a replay's inputs written anew with tmuf_replay_write (the
   round trip the game's validator checks).

   tmuf_rewrite PACKS IN.Replay.Gbx OUT.Replay.Gbx
   Prints "RACE_TIME RESPAWNS BYTES". */

#include <stdio.h>
#include <stdlib.h>

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
  if (argc < 4) {
    fprintf(stderr, "usage: tmuf_rewrite PACKS IN.Replay.Gbx OUT.Replay.Gbx\n");
    return 2;
  }
  char err[512];
  tmuf_packs *packs = tmuf_packs_open(argv[1], err, sizeof err);
  if (!packs) {
    fprintf(stderr, "packs: %s\n", err);
    return 1;
  }
  size_t size;
  void *data = read_file(argv[2], &size);
  tmuf_replay *replay = data ? tmuf_replay_load(data, size, err, sizeof err) : NULL;
  if (!replay) {
    fprintf(stderr, "%s: %s\n", argv[2], data ? err : "cannot read");
    return 1;
  }
  size_t map_size;
  const void *map = tmuf_replay_map(replay, &map_size);
  tmuf_track_options opt = {tmuf_replay_vehicle(replay), tmuf_replay_seed(replay), tmuf_replay_laps(replay), 0};
  tmuf_track *track = tmuf_track_load(packs, map, map_size, &opt, err, sizeof err);
  if (!track) {
    fprintf(stderr, "%s: %s\n", argv[2], err);
    return 1;
  }
  const tmuf_input *inputs;
  const uint32_t n = tmuf_replay_inputs(replay, &inputs);
  size_t out_size;
  void *out = tmuf_replay_write(track, inputs, n, NULL, &out_size, err, sizeof err);
  if (!out) {
    fprintf(stderr, "%s: %s\n", argv[2], err);
    return 1;
  }
  FILE *f = fopen(argv[3], "wb");
  if (!f || fwrite(out, 1, out_size, f) != out_size) {
    fprintf(stderr, "cannot write %s\n", argv[3]);
    return 1;
  }
  fclose(f);
  /* read back */
  tmuf_replay *back = tmuf_replay_load(out, out_size, err, sizeof err);
  if (!back) {
    fprintf(stderr, "%s: written replay does not load: %s\n", argv[3], err);
    return 1;
  }
  printf("%d %zu\n", (int)tmuf_replay_race_time(back), out_size);
  tmuf_replay_free(back);
  tmuf_free(out);
  tmuf_track_free(track);
  tmuf_replay_free(replay);
  free(data);
  tmuf_packs_close(packs);
  return 0;
}
