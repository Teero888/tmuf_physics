/* tmuf_rollout: a replay's inputs up to a time, then random inputs; written
   as a new replay (uncompressed body) for the game's validator, which gives
   an oracle dump of runs no player drove.

   tmuf_rollout IN.Replay.Gbx OUT.Replay.Gbx SEED [FROM_MS [LENGTH_MS]]
   tmuf_rollout IN OUT --plain   (uncompressed copy; prints the ghost samples' offset)
     FROM_MS: race time the random inputs start at (default: random within
     the run), LENGTH_MS: how long they last (default: random 2-20 s).
   Prints "FROM LENGTH EVENTS" on success. */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/arena.h"
#include "common/replay.h"

static uint8_t *read_file(const char *path, size_t *size) {
  FILE *f = fopen(path, "rb");
  if (!f)
    return NULL;
  fseek(f, 0, SEEK_END);
  long n = ftell(f);
  fseek(f, 0, SEEK_SET);
  uint8_t *d = n > 0 ? malloc((size_t)n) : NULL;
  if (d && fread(d, 1, (size_t)n, f) != (size_t)n) {
    free(d);
    d = NULL;
  }
  fclose(f);
  *size = (size_t)n;
  return d;
}

static uint64_t rng;
static uint32_t rnd(uint32_t n) {
  rng ^= rng << 13, rng ^= rng >> 7, rng ^= rng << 17;
  return (uint32_t)((rng >> 16) % n);
}

static int find_action(const tmuf_ghost *g, const char *name) {
  for (uint32_t i = 0; i < g->action_count; i++)
    if (strcmp(g->actions[i], name) == 0)
      return (int)i;
  return -1;
}

typedef struct ev {
  uint32_t time;
  uint8_t action;
  uint32_t value;
} ev;

static void put32(uint8_t *p, uint32_t v) { memcpy(p, &v, 4); }

int main(int argc, char **argv) {
  if (argc < 4) {
    fprintf(stderr, "usage: tmuf_rollout IN OUT SEED [FROM_MS [LENGTH_MS]]\n");
    return 2;
  }
  rng = strtoull(argv[3], NULL, 10) * 0x9e3779b97f4a7c15ull + 1;
  size_t size;
  uint8_t *data = read_file(argv[1], &size);
  if (!data) {
    fprintf(stderr, "cannot read %s\n", argv[1]);
    return 1;
  }
  tmuf_arena arena;
  tmuf_arena_init(&arena);
  tmuf_replay_file r;
  char err[512];
  if (!tmuf_replay_parse(data, size, &arena, &r, err, sizeof err)) {
    fprintf(stderr, "%s: %s\n", argv[1], err);
    return 1;
  }
  const tmuf_ghost *g = r.ghosts[0];
  if (strcmp(argv[3], "--plain") == 0) {
    /* the same replay with an uncompressed body; prints the ghost samples'
       offset in the output file */
    FILE *f = fopen(argv[2], "wb");
    if (!f)
      return 1;
    uint8_t *head = malloc((size_t)r.body_offset);
    memcpy(head, data, (size_t)r.body_offset);
    head[7] = 'U';
    fwrite(head, 1, (size_t)r.body_offset, f);
    fwrite(r.body, 1, r.body_size, f);
    fclose(f);
    const uint64_t base = r.body_compressed ? 0 : r.body_offset;
    printf("%llu\n", (unsigned long long)(r.body_offset + g->samples_pos - base));
    return 0;
  }
  const int acc = find_action(g, "Accelerate"), brk = find_action(g, "Brake");
  const int steer = find_action(g, "Steer"), left = find_action(g, "SteerLeft"), right = find_action(g, "SteerRight");
  if (!g->has_inputs || !g->has_race_time || acc < 0 || (steer < 0 && (left < 0 || right < 0)) ||
      g->race_time == UINT32_MAX || g->race_time < 100) {
    fprintf(stderr, "%s: no usable inputs\n", argv[1]);
    return 1;
  }
  /* body offsets: relative to the body (file offsets for an uncompressed one) */
  const uint64_t base = r.body_compressed ? 0 : r.body_offset;
  const uint64_t pos_rt = g->race_time_pos - base, pos_dur = g->duration_pos - base,
                 pos_cnt = g->event_count_pos - base, pos_ev = g->events_pos - base, pos_end = g->events_end - base;
  if (!(pos_rt + 4 <= pos_dur && pos_dur < pos_cnt && pos_cnt + 8 == pos_ev && pos_ev <= pos_end &&
        pos_end <= r.body_size)) {
    fprintf(stderr, "%s: unexpected input layout\n", argv[1]);
    return 1;
  }
  const uint32_t from = argc > 4 ? (uint32_t)atoi(argv[4]) : rnd(g->race_time / 10u) * 10u;
  const uint32_t length = argc > 5 ? (uint32_t)atoi(argv[5]) : (200u + rnd(1801u)) * 10u;
  /* event times: 100000 at the race start (the controls' sample clock) */
  const uint32_t start = 100000u + from, end = start + length;
  ev *evs = malloc(sizeof *evs * (g->event_count + 3u * (length / 20u + 2u)));
  uint32_t n = 0;
  for (uint32_t i = 0; i < g->event_count; i++)
    if (g->events[i].time < start)
      evs[n++] = (ev){g->events[i].time, g->events[i].action, g->events[i].value};
  /* random inputs, each held 20-500 ms */
  int cur_acc = -1, cur_brk = -1, cur_l = -1, cur_r = -1;
  int32_t cur_st = INT32_MIN;
  for (uint32_t t = start; t < end;) {
    const int a = rnd(100) < 75, b = rnd(100) < 15;
    int32_t s;
    const uint32_t k = rnd(100);
    s = k < 40 ? 0 : k < 60 ? -65536 : k < 80 ? 65536 : (int32_t)rnd(131073) - 65536;
    if (a != cur_acc)
      evs[n++] = (ev){t, (uint8_t)acc, (uint32_t)a}, cur_acc = a;
    if (brk >= 0 && b != cur_brk) /* only the actions the run has (no Brake: never) */
      evs[n++] = (ev){t, (uint8_t)brk, (uint32_t)b}, cur_brk = b;
    if (steer >= 0) {
      if (s != cur_st) /* the controls read steer = -signed24(value) */
        evs[n++] = (ev){t, (uint8_t)steer, (uint32_t)(-s) & 0x00ffffffu}, cur_st = s;
    } else {
      const int l = s < 0, rr = s > 0;
      if (l != cur_l)
        evs[n++] = (ev){t, (uint8_t)left, (uint32_t)l}, cur_l = l;
      if (rr != cur_r)
        evs[n++] = (ev){t, (uint8_t)right, (uint32_t)rr}, cur_r = rr;
    }
    t += (2u + rnd(49u)) * 10u;
  }
  /* the new body: race time and input duration = the rollout's end */
  const size_t old_ev = (size_t)(pos_end - pos_ev), new_ev = (size_t)n * 9u;
  const size_t nsize = r.body_size - old_ev + new_ev;
  uint8_t *body = malloc(nsize);
  memcpy(body, r.body, (size_t)pos_ev);
  put32(body + pos_rt, from + length);
  put32(body + pos_dur, from + length);
  put32(body + pos_cnt, n);
  put32(body + pos_cnt + 4, n);
  for (uint32_t i = 0; i < n; i++) {
    uint8_t *p = body + pos_ev + (size_t)i * 9u;
    put32(p, evs[i].time);
    p[4] = evs[i].action;
    put32(p + 5, evs[i].value);
  }
  memcpy(body + pos_ev + new_ev, r.body + pos_end, r.body_size - (size_t)pos_end);
  FILE *f = fopen(argv[2], "wb");
  if (!f) {
    fprintf(stderr, "cannot write %s\n", argv[2]);
    return 1;
  }
  uint8_t *head = malloc((size_t)r.body_offset);
  memcpy(head, data, (size_t)r.body_offset);
  head[7] = 'U'; /* "GBX" u16 version, format "BUCR": body not compressed */
  fwrite(head, 1, (size_t)r.body_offset, f);
  fwrite(body, 1, nsize, f);
  fclose(f);
  printf("%u %u %u\n", from, length, n);
  free(head), free(body), free(evs), free(data);
  tmuf_arena_free(&arena);
  return 0;
}
