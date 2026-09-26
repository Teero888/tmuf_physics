#include "common/replay.h"

#include <stdio.h>
#include <string.h>

#include "common/gbx.h"

#define MAX_COUNT 0x10000000u

/* ---- CGameGhost (0x0303f000) ---- */

static void ghost_samples(tmuf_gbx *g, tmuf_ghost *gh) {
  gh->samples_size = tmuf_gbx_u32(g);
  gh->samples_packed_size = tmuf_gbx_u32(g);
  if (gh->samples_packed_size > (64u << 20)) {
    tmuf_gbx_fail(g, "ghost samples size %u", gh->samples_packed_size);
    return;
  }
  uint8_t *d = tmuf_arena_alloc(g->arena, gh->samples_packed_size ? gh->samples_packed_size : 1);
  tmuf_gbx_read(g, d, gh->samples_packed_size);
  gh->samples = d;
}

static void c0303f005(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  ghost_samples(g, node);
}

static void c0303f006(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  tmuf_gbx_u32(g);
  ghost_samples(g, node);
}

static const tmuf_gbx_chunk GAME_GHOST_CHUNKS[] = {
    {0x0303f005, 0, c0303f005},
    {0x0303f006, 0, c0303f006},
};

static const tmuf_gbx_class GAME_GHOST = {
    0x0303f000, "CGameGhost", sizeof(tmuf_ghost), GAME_GHOST_CHUNKS, 2, NULL,
};

/* ---- CGameCtnGhost (0x03092000) ---- */

static void skip_u32_value(tmuf_gbx *g, uint32_t *out, int *has) {
  *out = tmuf_gbx_u32(g);
  *has = 1;
}

static void c03092005(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  tmuf_ghost *gh = node;
  skip_u32_value(g, &gh->race_time, &gh->has_race_time);
}

static void c03092008(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  tmuf_ghost *gh = node;
  skip_u32_value(g, &gh->respawns, &gh->has_respawns);
}

static void c0309200a(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  tmuf_ghost *gh = node;
  skip_u32_value(g, &gh->stunt_score, &gh->has_stunt_score);
}

static void c0309200c(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  tmuf_gbx_u32(g);
}

static void read_vehicle(tmuf_gbx *g, tmuf_ghost *gh) {
  for (int i = 0; i < 3; i++) {
    uint32_t number;
    const char *s = tmuf_gbx_id(g, &number);
    if (!s) {
      char buf[16];
      snprintf(buf, sizeof buf, "%u", number);
      s = tmuf_arena_strndup(g->arena, buf, strlen(buf));
    }
    gh->vehicle[i] = s;
  }
}

static void c0309200d(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  read_vehicle(g, node);
  tmuf_gbx_string(g);
  tmuf_gbx_skip(g, 16);
  tmuf_gbx_string(g);
}

static void c_one_id(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  tmuf_gbx_id(g, NULL);
}

static void c0309200f(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  ((tmuf_ghost *)node)->login = tmuf_gbx_string(g);
}

static void c03092012(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  tmuf_gbx_skip(g, 20);
}

static void c03092018(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  read_vehicle(g, node);
}

static void validation_inputs(tmuf_gbx *g, tmuf_ghost *gh, int has_seed) {
  gh->has_validation_seed = has_seed;
  gh->input_duration = tmuf_gbx_u32(g);
  if (gh->input_duration == 0)
    return;
  gh->has_inputs = 1;
  gh->input_version = tmuf_gbx_u32(g);
  gh->action_count = tmuf_gbx_u32(g);
  if (gh->action_count > 256) {
    tmuf_gbx_fail(g, "input action count %u", gh->action_count);
    return;
  }
  gh->actions = TMUF_ARENA_ARRAY(g->arena, const char *, gh->action_count ? gh->action_count : 1);
  for (uint32_t i = 0; i < gh->action_count; i++) {
    const char *s = tmuf_gbx_id(g, NULL);
    gh->actions[i] = s ? s : "";
  }
  gh->event_count = tmuf_gbx_u32(g);
  tmuf_gbx_u32(g); /* capacity */
  if (gh->event_count > MAX_COUNT) {
    tmuf_gbx_fail(g, "input event count %u", gh->event_count);
    return;
  }
  gh->events = TMUF_ARENA_ARRAY(g->arena, tmuf_input_event, gh->event_count ? gh->event_count : 1);
  if (!gh->events) {
    tmuf_gbx_fail(g, "out of memory");
    return;
  }
  for (uint32_t i = 0; i < gh->event_count && !g->error; i++) {
    gh->events[i].time = tmuf_gbx_u32(g);
    gh->events[i].action = tmuf_gbx_u8(g);
    gh->events[i].value = tmuf_gbx_u32(g);
  }
  tmuf_gbx_string(g);
  tmuf_gbx_skip(g, 12);
  tmuf_gbx_string(g);
  if (has_seed)
    gh->validation_seed = tmuf_gbx_u32(g);
}

static void c03092011(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  validation_inputs(g, node, 0);
}

static void c03092019(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  validation_inputs(g, node, 1);
}

static const tmuf_gbx_chunk CTN_GHOST_CHUNKS[] = {
    {0x03092005, 1, c03092005}, {0x03092008, 1, c03092008}, {0x0309200a, 1, c0309200a},
    {0x0309200c, 0, c0309200c}, {0x0309200d, 0, c0309200d}, {0x0309200e, 0, c_one_id},
    {0x0309200f, 0, c0309200f}, {0x03092010, 0, c_one_id},  {0x03092011, 0, c03092011},
    {0x03092012, 0, c03092012}, {0x03092015, 0, c_one_id},  {0x03092018, 0, c03092018},
    {0x03092019, 0, c03092019},
};

static const tmuf_gbx_class CTN_GHOST = {
    0x03092000,
    "CGameCtnGhost",
    sizeof(tmuf_ghost),
    CTN_GHOST_CHUNKS,
    sizeof CTN_GHOST_CHUNKS / sizeof CTN_GHOST_CHUNKS[0],
    &GAME_GHOST,
};

/* ---- CGameCtnReplayRecord (0x03093000) ---- */

static void c03093002(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  tmuf_replay_file *r = node;
  r->challenge_size = tmuf_gbx_u32(g);
  if (r->challenge_size > (64u << 20)) {
    tmuf_gbx_fail(g, "challenge size %u", r->challenge_size);
    return;
  }
  uint8_t *d = tmuf_arena_alloc(g->arena, r->challenge_size ? r->challenge_size : 1);
  tmuf_gbx_read(g, d, r->challenge_size);
  r->challenge = d;
}

static void read_ghosts(tmuf_gbx *g, tmuf_replay_file *r) {
  r->ghost_count = tmuf_gbx_u32(g);
  if (r->ghost_count > 4096) {
    tmuf_gbx_fail(g, "ghost count %u", r->ghost_count);
    return;
  }
  r->ghosts = TMUF_ARENA_ARRAY(g->arena, tmuf_ghost *, r->ghost_count ? r->ghost_count : 1);
  for (uint32_t i = 0; i < r->ghost_count && !g->error; i++) {
    tmuf_gbx_node *n = tmuf_gbx_noderef(g);
    if (!g->error && (!n || n->cls != &CTN_GHOST))
      tmuf_gbx_fail(g, "ghost %u is not a CGameCtnGhost", i);
    else if (n)
      r->ghosts[i] = n->data;
  }
}

static void c03093004(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  tmuf_replay_file *r = node;
  tmuf_gbx_u32(g); /* version */
  tmuf_gbx_u32(g); /* array version */
  r->deprecated_ghost_chunk = 1;
  read_ghosts(g, r);
  g->stop = 1;
}

static void c03093014(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  tmuf_replay_file *r = node;
  tmuf_gbx_u32(g); /* version */
  read_ghosts(g, r);
  tmuf_gbx_u32(g);
  uint32_t extras = tmuf_gbx_u32(g);
  if (extras > MAX_COUNT) {
    tmuf_gbx_fail(g, "extras count %u", extras);
    return;
  }
  tmuf_gbx_skip(g, (size_t)extras * 8);
  /* Later chunks (MediaTracker clips) are not needed. */
  g->stop = 1;
}

/* 0x0309300e: a node reference (null in every replay seen). */
static void c0309300e(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  if (tmuf_gbx_u32(g) != TMUF_GBX_NULL_NODE)
    tmuf_gbx_fail(g, "chunk 0309300e with a node");
}

/* 0x03093011: no payload. */
static void c03093011(tmuf_gbx *g, void *node, uint32_t id) {
  (void)g;
  (void)node;
  (void)id;
}

static const tmuf_gbx_chunk REPLAY_CHUNKS[] = {
    {0x03093002, 0, c03093002}, {0x03093004, 0, c03093004}, {0x0309300e, 0, c0309300e},
    {0x03093011, 0, c03093011}, {0x03093014, 0, c03093014},
};

static const tmuf_gbx_class REPLAY = {
    0x03093000, "CGameCtnReplayRecord", sizeof(tmuf_replay_file), REPLAY_CHUNKS,
    sizeof REPLAY_CHUNKS / sizeof REPLAY_CHUNKS[0], NULL,
};

static const tmuf_gbx_class *const REPLAY_CLASSES[] = {&REPLAY, &CTN_GHOST};

int tmuf_replay_parse(const uint8_t *data, size_t size, tmuf_arena *arena, tmuf_replay_file *out, char *err,
                      size_t err_size) {
  memset(out, 0, sizeof *out);
  tmuf_mem_source src;
  tmuf_mem_source_init(&src, data, size);
  tmuf_gbx g;
  tmuf_gbx_init(&g, &src.base, arena, REPLAY_CLASSES, 2);
  tmuf_replay_file *r = NULL;
  if (tmuf_gbx_read_header(&g)) {
    r = tmuf_gbx_read_root(&g);
  }
  if (!g.error && r && r->ghost_count == 0)
    tmuf_gbx_fail(&g, "replay has no ghost");
  if (g.error || !r) {
    if (err && err_size)
      snprintf(err, err_size, "%s", g.message);
    return 0;
  }
  *out = *r;
  out->class_id = g.class_id;
  return 1;
}
