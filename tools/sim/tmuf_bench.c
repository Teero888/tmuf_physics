/* Single-threaded throughput of the public API on one map.

   tmuf_bench PACKS MAP [--ticks N] [--episode T] [--seed S] [--replay REPLAY]

   Random mode (default): episodes of T ticks from the start (countdown
   included; each episode begins with tmuf_world_copy of the time-0 world),
   inputs held for 1..20 ticks: accelerate 80 %, brake 15 %, steer full
   left / right / straight / analog. Replay mode: the replay's inputs. */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

static double now(void) {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return (double)ts.tv_sec + (double)ts.tv_nsec * 1e-9;
}

/* CPU time of this thread: unaffected by other processes taking the core */
static double cpu(void) {
  struct timespec ts;
  clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts);
  return (double)ts.tv_sec + (double)ts.tv_nsec * 1e-9;
}

static uint64_t rng_state;
static uint32_t rnd(void) {
  rng_state ^= rng_state << 13;
  rng_state ^= rng_state >> 7;
  rng_state ^= rng_state << 17;
  return (uint32_t)(rng_state >> 11);
}

static tmuf_input random_input(void) {
  tmuf_input in = {0, 0, 0, 0};
  in.accelerate = rnd() % 100 < 80;
  in.brake = rnd() % 100 < 15;
  switch (rnd() % 4) {
  case 0:
    in.steer = -65536;
    break;
  case 1:
    in.steer = 65536;
    break;
  case 2:
    in.steer = 0;
    break;
  default:
    in.steer = (int32_t)(rnd() % 131073u) - 65536;
  }
  return in;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "usage: tmuf_bench PACKS MAP [--ticks N] [--episode T] [--seed S] [--replay REPLAY]\n");
    return 2;
  }
  uint64_t ticks = 1000000;
  uint32_t episode = 3000;
  uint64_t seed = 1;
  const char *replay_path = NULL;
  for (int i = 3; i + 1 < argc; i += 2) {
    if (!strcmp(argv[i], "--ticks"))
      ticks = strtoull(argv[i + 1], NULL, 10);
    else if (!strcmp(argv[i], "--episode"))
      episode = (uint32_t)atoi(argv[i + 1]);
    else if (!strcmp(argv[i], "--seed"))
      seed = strtoull(argv[i + 1], NULL, 10);
    else if (!strcmp(argv[i], "--replay"))
      replay_path = argv[i + 1];
  }
  rng_state = seed ? seed : 1;
  char err[600];
  double t0 = now();
  tmuf_packs *packs = tmuf_packs_open(argv[1], err, sizeof err);
  if (!packs) {
    fprintf(stderr, "packs: %s\n", err);
    return 1;
  }
  size_t size;
  unsigned char *map = read_file(argv[2], &size);
  if (!map) {
    fprintf(stderr, "cannot read %s\n", argv[2]);
    return 1;
  }
  double t1 = now();
  tmuf_track *track = tmuf_track_load(packs, map, size, NULL, err, sizeof err);
  free(map);
  if (!track) {
    fprintf(stderr, "track: %s\n", err);
    return 1;
  }
  double t2 = now();
  const tmuf_sim *ts = tmuf_track_sim(track);
  printf("map %s (%s, %s): %u static records, %u triggers\n", tmuf_track_name(track), tmuf_track_environment(track),
         tmuf_track_vehicle(track), ts->world.record_count, ts->triggers.record_count);
  printf("load: packs %.3f s, track %.3f s; sizeof(tmuf_world) %zu bytes\n", t1 - t0, t2 - t1, sizeof(tmuf_world));

  tmuf_world start = tmuf_world_empty(), w = tmuf_world_empty();
  tmuf_world_init(&start, track);

  if (replay_path) {
    unsigned char *rd = read_file(replay_path, &size);
    tmuf_replay *r = rd ? tmuf_replay_load(rd, size, err, sizeof err) : NULL;
    free(rd);
    if (!r) {
      fprintf(stderr, "replay: %s\n", err);
      return 1;
    }
    const tmuf_input *in;
    uint32_t n = tmuf_replay_inputs(r, &in);
    uint64_t done = 0;
    double best = 1e30, total = 0;
    int runs = 0;
    while (done < ticks || runs < 3) {
      tmuf_world_copy(&w, &start);
      double a = cpu();
      for (uint32_t i = 0; i < n; i++) {
        w.input = in[i];
        tmuf_world_tick(&w);
      }
      double b = cpu() - a;
      total += b;
      if (b < best)
        best = b;
      done += n;
      runs++;
    }
    printf("replay %u ticks, finish %u ms (recorded %u): %d runs, %.0f ticks/s cpu mean, %.0f best\n", n,
           w.sim.race.completed ? w.sim.race.finish_time : UINT32_MAX, tmuf_replay_race_time(r), runs,
           (double)done / total, (double)n / best);
    tmuf_replay_free(r);
  } else {
    uint64_t done = 0, copies = 0, substeps = 0;
    double tick_time = 0, copy_time = 0, tick_cpu = 0;
    while (done < ticks) {
      double a = now();
      tmuf_world_copy(&w, &start);
      double b = now();
      copy_time += b - a;
      copies++;
      uint32_t hold = 0;
      tmuf_input in = {0, 0, 0, 0};
      double c = now(), cc = cpu();
      for (uint32_t i = 0; i < episode && done < ticks; i++, done++) {
        if (hold == 0) {
          in = random_input();
          hold = 1 + rnd() % 20;
        }
        hold--;
        w.input = in;
        tmuf_world_tick(&w);
        substeps += w.sim.substeps;
      }
      tick_time += now() - c;
      tick_cpu += cpu() - cc;
    }
    printf("random: %llu ticks in %.3f s: %.0f ticks/s wall, %.0f ticks/s cpu (%.2f us/tick cpu, %.2f substeps/tick); "
           "%llu copies, %.2f us each\n",
           (unsigned long long)done, tick_time, (double)done / tick_time, (double)done / tick_cpu,
           tick_cpu * 1e6 / (double)done, (double)substeps / (double)done, (unsigned long long)copies,
           copy_time * 1e6 / (double)copies);
  }
  tmuf_world_free(&w);
  tmuf_world_free(&start);
  tmuf_track_free(track);
  tmuf_packs_close(packs);
  return 0;
}
