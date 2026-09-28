/* Drives replays through the public API and compares the car with oracle
   dumps (tools/oracle), switching worlds with tmuf_world_copy on the way.

   tmuf_api_check PACKS LIST   (LIST: lines "REPLAY ORACLE") */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <tmuf_physics/tmuf_physics.h>

static unsigned char *read_file(const char *path, size_t *size) {
  FILE *f = fopen(path, "rb");
  if (!f)
    return NULL;
  fseek(f, 0, SEEK_END);
  long n = ftell(f);
  fseek(f, 0, SEEK_SET);
  unsigned char *d = malloc(n > 0 ? (size_t)n : 1);
  if (d && fread(d, 1, (size_t)n, f) != (size_t)n) {
    free(d);
    d = NULL;
  }
  fclose(f);
  *size = (size_t)n;
  return d;
}

/* start-of-tick states: 45 floats (quaternion w x y z, rotation, position,
   linear speed, ..., angular speed at 22) */
static float (*load_oracle(const char *path, unsigned *count))[45] {
  char cmd[1200];
  snprintf(cmd, sizeof cmd, "gzip -dc '%s'", path);
  FILE *f = popen(cmd, "r");
  *count = 0;
  if (!f)
    return NULL;
  char magic[4];
  unsigned version, size;
  float(*st)[45] = NULL;
  unsigned cap = 0;
  if (fread(magic, 1, 4, f) == 4 && memcmp(magic, "TMOR", 4) == 0 && fread(&version, 4, 1, f) == 1 &&
      fread(&size, 4, 1, f) == 1 && size == 180) {
    for (;;) {
      int type = fgetc(f);
      if (type == EOF)
        break;
      unsigned w[2];
      float s[45];
      if (type == 1) {
        if (fread(w, 4, 2, f) != 2)
          break;
      } else if (type == 2) {
        if (fread(w, 4, 1, f) != 1 || fread(s, 4, 45, f) != 45)
          break;
        if (*count == cap) {
          cap = cap ? cap * 2 : 4096;
          st = realloc(st, sizeof *st * cap);
        }
        memcpy(st[(*count)++], s, sizeof s);
      } else {
        break;
      }
    }
  }
  pclose(f);
  return st;
}

/* the body state is the game's CHmsDyna state layout, as dumped */
static int differs(const tmuf_world *w, const float *o) { return memcmp(&w->body->state, o, 44 * sizeof(float)) != 0; }

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "usage: tmuf_api_check PACKS LIST\n");
    return 2;
  }
  char err[600];
  tmuf_packs *packs = tmuf_packs_open(argv[1], err, sizeof err);
  if (!packs) {
    fprintf(stderr, "%s\n", err);
    return 1;
  }
  FILE *list = fopen(argv[2], "r");
  if (!list)
    return 1;
  char line[4096];
  unsigned ok = 0, bad = 0;
  /* TMUF_API_COPY_EVERY=N: continue in the other world every N ticks (0: never) */
  const char *ce = getenv("TMUF_API_COPY_EVERY");
  uint32_t copy_every = ce ? (uint32_t)atoi(ce) : 50u;
  while (fgets(line, sizeof line, list)) {
    char rp[2048], op[2048];
    if (sscanf(line, "%2047s %2047s", rp, op) != 2)
      continue;
    const char *name = strrchr(rp, '/') ? strrchr(rp, '/') + 1 : rp;
    size_t size;
    unsigned char *data = read_file(rp, &size);
    tmuf_replay *r = data ? tmuf_replay_load(data, size, err, sizeof err) : NULL;
    free(data);
    if (!r) {
      printf("%s ERROR replay %s\n", name, err);
      bad++;
      continue;
    }
    size_t map_size;
    const void *map = tmuf_replay_map(r, &map_size);
    tmuf_track_options opt = {tmuf_replay_vehicle(r), tmuf_replay_seed(r)};
    tmuf_track *t = tmuf_track_load(packs, map, map_size, &opt, err, sizeof err);
    if (!t) {
      printf("%s ERROR track %s\n", name, err);
      tmuf_replay_free(r);
      bad++;
      continue;
    }
    unsigned ocount;
    float(*o)[45] = load_oracle(op, &ocount);
    const tmuf_input *in;
    uint32_t n = tmuf_replay_inputs(r, &in);
    uint32_t race = tmuf_replay_race_time(r);
    uint32_t end_ms = race == UINT32_MAX ? UINT32_MAX : TMUF_RACE_START_MS + race;
    tmuf_world worlds[2] = {tmuf_world_empty(), tmuf_world_empty()};
    int cur = 0;
    tmuf_world_init(&worlds[0], t);
    uint32_t diverged = UINT32_MAX, copies = 0;
    for (uint32_t i = 0; i < n; i++) {
      if (copy_every && i % copy_every == copy_every / 2) {
        /* continue in the other world */
        tmuf_world_copy(&worlds[!cur], &worlds[cur]);
        cur = !cur;
        copies++;
      }
      tmuf_world *w = &worlds[cur];
      w->input = in[i];
      tmuf_world_tick(w);
      uint32_t time = w->tick * TMUF_TICK_MS;
      /* the oracle dumps a tick's respawn before its physics */
      int respawn_next = i + 1 < n && in[i + 1].respawn;
      if (diverged == UINT32_MAX && time <= end_ms && i + 1 < ocount && !respawn_next && differs(w, o[i + 1]))
        diverged = i;
    }
    const tmuf_race *rc = worlds[cur].race;
    int finish_ok = race == UINT32_MAX || (rc->completed && rc->finish_time == race);
    if (diverged == UINT32_MAX && finish_ok) {
      ok++;
      printf("%s MATCH %s %u ticks, %u copies, finish %u\n", name, tmuf_track_vehicle(t), n, copies,
             rc->completed ? rc->finish_time : 0);
    } else {
      bad++;
      printf("%s DIVERGE tick %u finish %d/%u race %u\n", name, diverged, rc->completed, rc->finish_time, race);
    }
    tmuf_world_free(&worlds[0]);
    tmuf_world_free(&worlds[1]);
    free(o);
    tmuf_track_free(t);
    tmuf_replay_free(r);
    fflush(stdout);
  }
  fclose(list);
  tmuf_packs_close(packs);
  printf("%u ok, %u bad\n", ok, bad);
  return bad != 0;
}
