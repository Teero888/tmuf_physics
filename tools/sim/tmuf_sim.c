#define _POSIX_C_SOURCE 200809L
/* Development harness: simulate replays with the reference backend and
   compare every tick with oracle dumps (tools/oracle). The oracle records
   the dyna state at the start of each tick, so our tick i is compared with
   oracle state i + 1.

   tmuf_sim PACKS REPLAY [ORACLE] [--ticks N] [--verbose] [--print]
   tmuf_sim PACKS --batch LIST     (lines: REPLAY ORACLE; one result line each) */

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

typedef struct oracle {
  uint32_t count, cap;
  float (*states)[45];
} oracle;

static int load_oracle(const char *path, oracle *o) {
  memset(o, 0, sizeof *o);
  size_t len = strlen(path);
  int pipe = len > 3 && strcmp(path + len - 3, ".gz") == 0;
  FILE *f;
  if (pipe) {
    char cmd[1200];
    snprintf(cmd, sizeof cmd, "gzip -dc '%s'", path);
    f = popen(cmd, "r");
  } else {
    f = fopen(path, "rb");
  }
  if (!f)
    return 0;
  char magic[4];
  uint32_t version, size;
  int ok = fread(magic, 1, 4, f) == 4 && memcmp(magic, "TMOR", 4) == 0 && fread(&version, 4, 1, f) == 1 &&
           fread(&size, 4, 1, f) == 1 && size == 180;
  while (ok) {
    int type = fgetc(f);
    if (type == EOF)
      break;
    if (type == 1) {
      uint32_t w[2];
      if (fread(w, 4, 2, f) != 2)
        break;
    } else if (type == 2) {
      uint32_t ptr;
      float st[45];
      if (fread(&ptr, 4, 1, f) != 1 || fread(st, 4, 45, f) != 45)
        break;
      if (o->count == o->cap) {
        o->cap = o->cap ? o->cap * 2 : 4096;
        o->states = realloc(o->states, sizeof *o->states * o->cap);
      }
      memcpy(o->states[o->count++], st, sizeof st);
    } else {
      break;
    }
  }
  pipe ? pclose(f) : fclose(f);
  return ok;
}

static const char *FIELD[45] = {"qw", "qx", "qy", "qz", "r00", "r01", "r02", "r10", "r11", "r12", "r20", "r21",
                                "r22", "px", "py", "pz", "vx", "vy", "vz", "cx", "cy", "cz", "wx", "wy",
                                "wz", "fx", "fy", "fz", "tx", "ty", "tz", "i00", "i01", "i02", "i10", "i11",
                                "i12", "i20", "i21", "i22", "tw", "tvx", "tvy", "tvz", "pad"};

/* compared fields: quaternion .. inverse inertia (0..39) */
static int diff_states(const float *a, const float *b, int verbose, int *first_field) {
  int bad = 0;
  for (int i = 0; i < 40; i++) {
    uint32_t ua, ub;
    memcpy(&ua, &a[i], 4);
    memcpy(&ub, &b[i], 4);
    if (ua != ub) {
      if (verbose)
        printf("    %-4s ours %.9g oracle %.9g\n", FIELD[i], a[i], b[i]);
      if (!bad && first_field)
        *first_field = i;
      bad++;
    }
  }
  return bad;
}

typedef struct opts {
  uint32_t max_ticks;
  int verbose, print, summary;
  const char *ext; /* an external trace */
} opts;

/* trace records: u32 tick, u32 time, 19 floats */
typedef struct ext_rec {
  uint32_t tick, time;
  float f[19];
} ext_rec;

static ext_rec *load_ext(const char *path, uint32_t *n) {
  size_t size;
  uint8_t *d = read_file(path, &size);
  *n = d ? (uint32_t)(size / sizeof(ext_rec)) : 0;
  return (ext_rec *)d;
}

static int run_one(const tmuf_packset *set, const char *replay_path, const char *oracle_path, const opts *op) {
  char err[1024] = "";
  const char *name = strrchr(replay_path, '/');
  name = name ? name + 1 : replay_path;
  size_t size;
  uint8_t *data = read_file(replay_path, &size);
  if (!data) {
    printf("%s ERROR read\n", name);
    return 1;
  }
  tmuf_arena arena;
  tmuf_arena_init(&arena);
  int rc = 1;
  tmuf_replay_file r;
  tmuf_challenge map;
  static tmuf_scene scene;
  static tmuf_vehicle vehicle;
  static ref_sim sim;
  ref_tick *ticks = NULL;
  oracle o = {0};
  int scene_built = 0, sim_built = 0;
  ext_rec *ext = NULL;
  if (!tmuf_replay_parse(data, size, &arena, &r, err, sizeof err) || !r.challenge || r.ghost_count == 0) {
    printf("%s ERROR replay %s\n", name, err);
    goto done;
  }
  const tmuf_ghost *ghost = r.ghosts[0];
  if (!ghost->has_inputs) {
    printf("%s ERROR no-inputs\n", name);
    goto done;
  }
  if (!tmuf_challenge_parse(r.challenge, r.challenge_size, &arena, &map, err, sizeof err)) {
    printf("%s ERROR map %s\n", name, err);
    goto done;
  }
  scene_built = 1;
  if (!tmuf_scene_build(&scene, set, &map)) {
    printf("%s ERROR scene %s\n", name, scene.error);
    goto done;
  }
  const char *vname = ghost->vehicle[0] && ghost->vehicle[0][0] ? ghost->vehicle[0] : "StadiumCar";
  /* a vehicle the packs do not have (custom car ids): the game plays the
     environment's own car */
  if (!tmuf_vehicle_load(&vehicle, &scene.assets, vname, err, sizeof err) && scene.default_vehicle &&
      scene.default_vehicle[0] && strcmp(scene.default_vehicle, vname) != 0)
    vname = scene.default_vehicle;
  if (!tmuf_vehicle_load(&vehicle, &scene.assets, vname, err, sizeof err)) {
    printf("%s ERROR vehicle %s\n", name, err);
    goto done;
  }
  uint32_t tick_count = ref_control_ticks(ghost, &ticks);
  gm_iso4 spawn;
  for (int i = 0; i < 3; i++)
    for (int k = 0; k < 3; k++)
      spawn.r.m[i][k] = scene.start.m[i][k];
  spawn.t = v3(scene.start.t[0], scene.start.t[1], scene.start.t[2]);
  if (!ref_sim_init(&sim, &scene, &vehicle, &spawn, ghost->has_validation_seed ? ghost->validation_seed : 0, &ticks[0],
                    err, sizeof err)) {
    printf("%s ERROR sim %s\n", name, err);
    goto done;
  }
  sim_built = 1;
  /* ConfigureReplayRace: the map's laps for a lap race, else one */
  sim.race.laps = map.has_laps && map.lap_race ? map.laps : 1;
  if (!op->summary)
    printf("race: %u checkpoints, %u laps, %u trigger records\n", sim.race.checkpoint_count, sim.race.laps,
           sim.triggers.record_count);
  if (getenv("TMUF_SIM_CORPUS")) {
    uint32_t ci = (uint32_t)atoi(getenv("TMUF_SIM_CORPUS"));
    if (ci < scene.corpus_count) {
      const tmuf_scene_corpus *c = &scene.corpora[ci];
      uint32_t tag = c->tag;
      printf("corpus %u tag %08x trigger %d item_flags %08x (group %u) block %s asset %s\n", ci, tag, c->trigger,
             c->item_flags, (c->item_flags >> 13) & 15u,
             tag < map.block_count && map.blocks[tag].name ? map.blocks[tag].name : "?",
             c->owner ? c->owner->path : "?");
    }
  }
  if (!op->summary)
    printf("map %s, vehicle %s, %u ticks, handling %u, %u static records\n", map.name ? map.name : "?", vname,
           tick_count, vehicle.tuning.handling_model, sim.world.record_count);
  if (oracle_path && !load_oracle(oracle_path, &o)) {
    printf("%s ERROR oracle\n", name);
    goto done;
  }
  /* A replay the game rejects ("Wrong Simu") ends its run early: the car is
     put back at its spawn and stays there. Compare up to that point. */
  uint32_t oracle_stop = 0;
  for (uint32_t k = o.count; k-- > 262;) {
    const float *a = o.states[k], *s0 = o.states[1];
    int still = a[16] == 0.0f && a[17] == 0.0f && a[18] == 0.0f && a[22] == 0.0f && a[23] == 0.0f && a[24] == 0.0f;
    if (!still || memcmp(&a[13], &s0[13], 12) != 0)
      break;
    oracle_stop = k;
  }
  /* only an abort before the recorded finish */
  if (oracle_stop && ghost->has_race_time && ghost->race_time != UINT32_MAX &&
      (uint64_t)oracle_stop * 10u < 2600u + (uint64_t)ghost->race_time)
    o.count = oracle_stop;
  else
    oracle_stop = 0;
  uint32_t finish_ms = 0;
  uint32_t ext_count = 0, ext_bad = 0;
  ext = op->ext ? load_ext(op->ext, &ext_count) : NULL;
  uint32_t n = tick_count < op->max_ticks ? tick_count : op->max_ticks;
  /* the game restarts the race once it is finished: compare up to the
     recorded race time */
  uint32_t end_ms = ghost->has_race_time && ghost->race_time != UINT32_MAX ? 2600u + ghost->race_time : UINT32_MAX;
  if (!op->summary)
    printf("race time %u, input duration %u\n", ghost->race_time, ghost->input_duration);
  uint32_t matched = 0;
  int diverged = 0;
  for (uint32_t i = 0; i < n; i++) {
    ref_sim_step(&sim, &ticks[i]);
    if (sim.race.completed && !finish_ms)
      finish_ms = ticks[i].time_ms;
    float ours[45];
    memset(ours, 0, sizeof ours);
    memcpy(ours, &sim.body.state, sizeof(float) * 44);
    if (op->print)
      printf("t=%u pos %.9g %.9g %.9g vel %.9g %.9g %.9g sub %u mats %d %d %d %d in %.2f %.2f %.2f\n", ticks[i].time_ms,
             ours[13], ours[14], ours[15], ours[16], ours[17], ours[18], sim.substeps,
             sim.car.wheels[0].contact ? sim.car.wheels[0].contact_material : -1,
             sim.car.wheels[1].contact ? sim.car.wheels[1].contact_material : -1,
             sim.car.wheels[2].contact ? sim.car.wheels[2].contact_material : -1,
             sim.car.wheels[3].contact ? sim.car.wheels[3].contact_material : -1, ticks[i].gate_a, ticks[i].gate_b,
             ticks[i].steering);
    if (ext && !ext_bad) {
      for (uint32_t k = 0; k < ext_count; k++)
        if (ext[k].time == ticks[i].time_ms) {
          /* quat x y z w, pos, lin, ang */
          const float ours_ext[13] = {ours[1], ours[2], ours[3], ours[0], ours[13], ours[14], ours[15],
                                     ours[16], ours[17], ours[18], ours[22], ours[23], ours[24]};
          for (int j = 0; j < 13; j++)
            if (memcmp(&ours_ext[j], &ext[k].f[j], 4) != 0) {
              printf("The trace differs first at tick %u t=%u: field %d ours %.9g ext %.9g\n", i, ticks[i].time_ms, j,
                     (double)ours_ext[j], (double)ext[k].f[j]);
              ext_bad = 1;
              break;
            }
          break;
        }
    }
    if (!o.count || diverged || ticks[i].time_ms > end_ms)
      continue;
    uint32_t k = i + 1;
    if (k >= o.count)
      break;
    /* the oracle dumps at the start of a tick, after that tick's respawns */
    if (i + 1 < n && ticks[i + 1].respawns) {
      matched++;
      continue;
    }
    int field = -1;
    int bad = diff_states(ours, o.states[k], 0, &field);
    if (!bad) {
      matched++;
      continue;
    }
    diverged = 1;
    if (op->summary) {
      printf("%s DIVERGE %s tick %u/%u t=%u field %s ours %.9g oracle %.9g nfields %d\n", name, vname, i, n,
             ticks[i].time_ms, FIELD[field], ours[field], o.states[k][field], bad);
    } else {
      printf("tick %u (t=%u ms): %d fields differ, substeps %u\n", i, ticks[i].time_ms, bad, sim.substeps);
      diff_states(ours, o.states[k], 1, NULL);
    }
    if (!op->verbose && !op->print)
      break;
  }
  char finish[96];
  if (ghost->has_race_time && ghost->race_time != UINT32_MAX)
    snprintf(finish, sizeof finish, finish_ms == 2600u + ghost->race_time ? "finish ok" : "finish %u race %u",
             finish_ms ? finish_ms - 2600u : 0u, ghost->race_time);
  else
    snprintf(finish, sizeof finish, "finish %u", finish_ms ? finish_ms - 2600u : 0u);
  if (o.count && !diverged)
    printf("%s%sMATCH %s %u/%u ticks (oracle %u states%s) %s\n", op->summary ? name : "", op->summary ? " " : "",
           vname, matched, n, o.count, oracle_stop ? ", game stopped the run" : "", finish);
  rc = 0;
done:
  if (sim_built)
    ref_sim_free(&sim);
  if (scene_built)
    tmuf_scene_free(&scene);
  free(ticks);
  free(o.states);
  free(ext);
  free(data);
  tmuf_arena_free(&arena);
  fflush(stdout);
  return rc;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "usage: tmuf_sim PACKS REPLAY [ORACLE] [--ticks N] [--verbose] [--print]\n"
                    "       tmuf_sim PACKS --batch LIST\n");
    return 2;
  }
  opts op = {UINT32_MAX, 0, 0, 0, NULL};
  const char *replay = NULL, *oracle_path = NULL, *batch = NULL;
  for (int i = 2; i < argc; i++) {
    if (strcmp(argv[i], "--ticks") == 0 && i + 1 < argc)
      op.max_ticks = (uint32_t)atoi(argv[++i]);
    else if (strcmp(argv[i], "--verbose") == 0)
      op.verbose = 1;
    else if (strcmp(argv[i], "--print") == 0)
      op.print = 1;
    else if (strcmp(argv[i], "--ext") == 0 && i + 1 < argc)
      op.ext = argv[++i];
    else if (strcmp(argv[i], "--batch") == 0 && i + 1 < argc)
      batch = argv[++i];
    else if (!replay)
      replay = argv[i];
    else
      oracle_path = argv[i];
  }
  char err[1024];
  static tmuf_packset set;
  if (!tmuf_packset_open(&set, argv[1], err, sizeof err)) {
    fprintf(stderr, "packs: %s\n", err);
    return 1;
  }
  if (batch) {
    op.summary = 1;
    FILE *f = strcmp(batch, "-") == 0 ? stdin : fopen(batch, "r");
    if (!f)
      return 1;
    char line[4096];
    while (fgets(line, sizeof line, f)) {
      char a[2048], b[2048];
      int n = sscanf(line, "%2047s %2047s", a, b);
      if (n >= 1)
        run_one(&set, a, n >= 2 ? b : NULL, &op);
    }
    return 0;
  }
  return run_one(&set, replay, oracle_path, &op);
}
