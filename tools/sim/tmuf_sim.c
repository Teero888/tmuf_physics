#define _POSIX_C_SOURCE 200809L
/* Development harness: simulate a replay with the reference backend and
   compare every tick with an oracle dump (tools/oracle).

   tmuf_sim PACKS REPLAY [ORACLE.tmor[.gz]] [--from N] [--ticks N] [--verbose] */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/challenge.h"
#include "common/packset.h"
#include "common/replay.h"
#include "common/scene.h"
#include "common/vehicle.h"
#include "reference/sim.h"

static uint8_t *read_file(const char *path, size_t *size) {
  FILE *f = fopen(path, "rb");
  if (!f)
    return NULL;
  fseek(f, 0, SEEK_END);
  long n = ftell(f);
  fseek(f, 0, SEEK_SET);
  uint8_t *d = malloc((size_t)n + 1);
  if (d && fread(d, 1, (size_t)n, f) != (size_t)n) {
    free(d);
    d = NULL;
  }
  fclose(f);
  *size = (size_t)n;
  return d;
}

/* oracle states: every DYNA record (180 bytes) in order */
typedef struct oracle {
  uint32_t count, cap;
  float (*states)[45];
  uint32_t *steps; /* step index of each state */
} oracle;

static int load_oracle(const char *path, oracle *o) {
  memset(o, 0, sizeof *o);
  char cmd[1024];
  size_t len = strlen(path);
  FILE *f;
  int pipe = len > 3 && strcmp(path + len - 3, ".gz") == 0;
  if (pipe) {
    snprintf(cmd, sizeof cmd, "gzip -dc '%s'", path);
    f = popen(cmd, "r");
  } else {
    f = fopen(path, "rb");
  }
  if (!f)
    return 0;
  char magic[4];
  uint32_t version, size;
  if (fread(magic, 1, 4, f) != 4 || memcmp(magic, "TMOR", 4) != 0 || fread(&version, 4, 1, f) != 1 ||
      fread(&size, 4, 1, f) != 1 || size != 180) {
    pipe ? pclose(f) : fclose(f);
    return 0;
  }
  uint32_t step = 0;
  for (;;) {
    int type = fgetc(f);
    if (type == EOF)
      break;
    if (type == 1) {
      uint32_t w[2];
      if (fread(w, 4, 2, f) != 2)
        break;
      step = w[0];
    } else if (type == 2) {
      uint32_t ptr;
      float st[45];
      if (fread(&ptr, 4, 1, f) != 1 || fread(st, 4, 45, f) != 45)
        break;
      if (o->count == o->cap) {
        o->cap = o->cap ? o->cap * 2 : 4096;
        o->states = realloc(o->states, sizeof *o->states * o->cap);
        o->steps = realloc(o->steps, sizeof *o->steps * o->cap);
      }
      memcpy(o->states[o->count], st, sizeof st);
      o->steps[o->count] = step;
      o->count++;
    } else {
      break;
    }
  }
  pipe ? pclose(f) : fclose(f);
  return 1;
}

static void state_floats(const dyna_state *s, float out[45]) {
  memset(out, 0, sizeof(float) * 45);
  memcpy(out, s, sizeof(float) * 44);
}

static const char *FIELD[45] = {"qw", "qx", "qy", "qz", "r00", "r01", "r02", "r10", "r11", "r12", "r20", "r21",
                                "r22", "px", "py", "pz", "vx", "vy", "vz", "cx", "cy", "cz", "wx", "wy",
                                "wz", "fx", "fy", "fz", "tx", "ty", "tz", "i00", "i01", "i02", "i10", "i11",
                                "i12", "i20", "i21", "i22", "tw", "tvx", "tvy", "tvz", "pad"};

static int diff_states(const float *a, const float *b, int verbose) {
  int bad = 0;
  for (int i = 0; i < 40; i++) {
    uint32_t ua, ub;
    memcpy(&ua, &a[i], 4);
    memcpy(&ub, &b[i], 4);
    if (ua != ub) {
      if (verbose)
        printf("    %-4s ours %.9g oracle %.9g\n", FIELD[i], a[i], b[i]);
      bad++;
    }
  }
  return bad;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "usage: tmuf_sim PACKS REPLAY [ORACLE] [--ticks N] [--verbose] [--print]\n");
    return 2;
  }
  const char *packs = argv[1], *replay_path = argv[2], *oracle_path = NULL;
  uint32_t max_ticks = UINT32_MAX;
  int verbose = 0, print = 0;
  int64_t shift = 0;
  for (int i = 3; i < argc; i++) {
    if (strcmp(argv[i], "--ticks") == 0 && i + 1 < argc)
      max_ticks = (uint32_t)atoi(argv[++i]);
    else if (strcmp(argv[i], "--verbose") == 0)
      verbose = 1;
    else if (strcmp(argv[i], "--shift") == 0 && i + 1 < argc)
      shift = atoi(argv[++i]);
    else if (strcmp(argv[i], "--print") == 0)
      print = 1;
    else
      oracle_path = argv[i];
  }
  size_t size;
  uint8_t *data = read_file(replay_path, &size);
  if (!data) {
    fprintf(stderr, "cannot read %s\n", replay_path);
    return 1;
  }
  tmuf_arena arena;
  tmuf_arena_init(&arena);
  char err[1024] = "";
  tmuf_replay_file r;
  if (!tmuf_replay_parse(data, size, &arena, &r, err, sizeof err) || !r.challenge || r.ghost_count == 0) {
    fprintf(stderr, "replay: %s\n", err);
    return 1;
  }
  const tmuf_ghost *ghost = r.ghosts[0];
  if (!ghost->has_inputs) {
    fprintf(stderr, "replay has no inputs\n");
    return 1;
  }
  tmuf_challenge map;
  if (!tmuf_challenge_parse(r.challenge, r.challenge_size, &arena, &map, err, sizeof err)) {
    fprintf(stderr, "map: %s\n", err);
    return 1;
  }
  tmuf_packset set;
  if (!tmuf_packset_open(&set, packs, err, sizeof err)) {
    fprintf(stderr, "packs: %s\n", err);
    return 1;
  }
  tmuf_scene scene;
  if (!tmuf_scene_build(&scene, &set, &map) || !scene.has_start) {
    fprintf(stderr, "scene: %s\n", scene.error);
    return 1;
  }
  tmuf_vehicle vehicle;
  const char *vname = ghost->vehicle[0] ? ghost->vehicle[0] : "StadiumCar";
  if (!tmuf_vehicle_load(&vehicle, &scene.assets, vname, err, sizeof err)) {
    fprintf(stderr, "vehicle: %s\n", err);
    return 1;
  }
  ref_tick *ticks;
  uint32_t tick_count = ref_control_ticks(ghost, &ticks);
  gm_iso4 spawn;
  for (int i = 0; i < 3; i++)
    for (int k = 0; k < 3; k++)
      spawn.r.m[i][k] = scene.start.m[i][k];
  spawn.t = v3(scene.start.t[0], scene.start.t[1], scene.start.t[2]);
  static ref_sim sim;
  if (!ref_sim_init(&sim, &scene, &vehicle, &spawn, ghost->has_validation_seed ? ghost->validation_seed : 0, &ticks[0],
                    err, sizeof err)) {
    fprintf(stderr, "sim: %s\n", err);
    return 1;
  }
  printf("map %s, vehicle %s, %u ticks, handling %u, %u static records\n", map.name ? map.name : "?", vname,
         tick_count, vehicle.tuning.handling_model, sim.world.record_count);

  oracle o = {0};
  if (oracle_path && !load_oracle(oracle_path, &o)) {
    fprintf(stderr, "cannot read oracle %s\n", oracle_path);
    return 1;
  }
  if (oracle_path)
    printf("oracle: %u states\n", o.count);
  /* align: the first oracle state whose position equals our spawn */
  uint32_t first_mismatch = UINT32_MAX;
  uint32_t n = tick_count < max_ticks ? tick_count : max_ticks;
  int64_t offset = -1;
  for (uint32_t i = 0; i < n; i++) {
    ref_sim_step(&sim, &ticks[i]);
    float ours[45];
    state_floats(&sim.body.state, ours);
    if (print)
      printf("t=%u pos %.9g %.9g %.9g vel %.9g %.9g %.9g sub %u contacts %d%d%d%d\n", ticks[i].time_ms, ours[13], ours[14],
             ours[15], ours[16], ours[17], ours[18], sim.substeps, sim.car.wheels[0].contact, sim.car.wheels[1].contact,
             sim.car.wheels[2].contact, sim.car.wheels[3].contact);
    if (!o.count)
      continue;
    if (offset < 0) {
      /* find the oracle state matching our first tick */
      for (uint32_t k = 0; k < o.count; k++)
        if (diff_states(ours, o.states[k], 0) == 0) {
          offset = (int64_t)k - (int64_t)i + shift;
          printf("aligned: our tick %u = oracle state %u (step %u)\n", i, k, o.steps[k]);
          break;
        }
      if (offset < 0) {
        printf("no oracle state matches tick %u\n", i);
        uint32_t best = 0;
        int best_bad = 99;
        for (uint32_t k = 0; k < o.count; k++) {
          int b = diff_states(ours, o.states[k], 0);
          if (b < best_bad)
            best_bad = b, best = k;
        }
        printf("  closest oracle state %u (%d fields differ):\n", best, best_bad);
        diff_states(ours, o.states[best], 1);
        break;
      }
      continue;
    }
    uint64_t k = (uint64_t)((int64_t)i + offset);
    if (k >= o.count)
      break;
    int bad = diff_states(ours, o.states[k], 0);
    if (bad) {
      first_mismatch = i;
      printf("tick %u (t=%u ms, oracle %llu): %d fields differ, substeps %u\n", i, ticks[i].time_ms,
             (unsigned long long)k, bad, sim.substeps);
      diff_states(ours, o.states[k], 1);
      if (!verbose)
        break;
    }
  }
  if (o.count && first_mismatch == UINT32_MAX && offset >= 0)
    printf("all %u ticks match\n", n);
  ref_sim_free(&sim);
  return 0;
}
