#include "common/challenge.h"

#include <stdio.h>
#include <string.h>

#include "common/gbx.h"

#define MAX_BLOCKS 0x100000u

/* Lookback id as text; numeric ids become "#<n>". */
static const char *id_text(tmuf_gbx *g) {
  uint32_t number;
  const char *s = tmuf_gbx_id(g, &number);
  if (s)
    return s;
  char buf[16];
  snprintf(buf, sizeof buf, "#%u", number);
  return tmuf_arena_strndup(g->arena, buf, strlen(buf));
}

static void ident(tmuf_gbx *g, const char *out[3]) {
  for (int i = 0; i < 3; i++)
    out[i] = id_text(g);
}

/* CSystemPackDesc file reference. */
static void pack_desc(tmuf_gbx *g) {
  uint8_t version = tmuf_gbx_u8(g);
  if (version >= 3)
    tmuf_gbx_skip(g, 32);
  const char *path = tmuf_gbx_string(g);
  if ((path[0] && version >= 1) || version >= 3)
    tmuf_gbx_string(g);
}

/* ---- CGameCtnCollectorList (0x0301b000): puzzle block stock ---- */

static void c0301b000(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  uint32_t n = tmuf_gbx_u32(g);
  if (n > 65536) {
    tmuf_gbx_fail(g, "block stock count %u", n);
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++) {
    const char *model[3];
    ident(g, model);
    tmuf_gbx_u32(g);
  }
}

static const tmuf_gbx_chunk COLLECTOR_LIST_CHUNKS[] = {{0x0301b000, 0, c0301b000}};
static const tmuf_gbx_class COLLECTOR_LIST = {0x0301b000, "CGameCtnCollectorList", 1, COLLECTOR_LIST_CHUNKS, 1, NULL};

/* ---- CGameCtnChallengeParameters (0x0305b000) ---- */

typedef struct params {
  uint32_t bronze, silver, gold, author_time, time_limit, author_score;
  int has_time_limit;
} params;

static void c0305b001(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  for (int i = 0; i < 4; i++)
    tmuf_gbx_string(g);
}

static void c0305b004(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  params *p = node;
  p->bronze = tmuf_gbx_u32(g);
  p->silver = tmuf_gbx_u32(g);
  p->gold = tmuf_gbx_u32(g);
  p->author_time = tmuf_gbx_u32(g);
  tmuf_gbx_u32(g);
}

/* 0x0305b005: three naturals; 0x0305b006: a counted list of naturals;
   0x0305b007: a natural (none used here) */
static void c0305b005(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  tmuf_gbx_skip(g, 12);
}

static void c0305b006(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  const uint32_t n = tmuf_gbx_u32(g);
  if (n > 0x100000u) {
    tmuf_gbx_fail(g, "challenge parameters list of %u", n);
    return;
  }
  tmuf_gbx_skip(g, (size_t)n * 4);
}

static void c0305b007(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  tmuf_gbx_skip(g, 4);
}

static void c0305b008(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  params *p = node;
  p->time_limit = tmuf_gbx_u32(g);
  p->author_score = tmuf_gbx_u32(g);
  p->has_time_limit = 1;
}

static void c0305b00d(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  if (tmuf_gbx_u32(g) != TMUF_GBX_NULL_NODE)
    tmuf_gbx_fail(g, "challenge parameters with a validation ghost");
}

static const tmuf_gbx_chunk PARAMS_CHUNKS[] = {
    {0x0305b001, 0, c0305b001},
    {0x0305b004, 0, c0305b004},
    {0x0305b005, 0, c0305b005},
    {0x0305b006, 0, c0305b006},
    {0x0305b007, 0, c0305b007},
    {0x0305b008, 0, c0305b008},
    {0x0305b00d, 0, c0305b00d},
};
static const tmuf_gbx_class PARAMS = {
    0x0305b000, "CGameCtnChallengeParameters", sizeof(params), PARAMS_CHUNKS,
    sizeof PARAMS_CHUNKS / sizeof PARAMS_CHUNKS[0], NULL,
};

/* ---- CGameCtnBlockSkin (0x03059000) ---- */

static void c03059000(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  tmuf_gbx_string(g);
  tmuf_gbx_string(g);
}

static void c03059001(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  tmuf_gbx_string(g);
  pack_desc(g);
}

static void c03059002(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  tmuf_gbx_string(g);
  pack_desc(g);
  pack_desc(g);
}

static const tmuf_gbx_chunk SKIN_CHUNKS[] = {
    {0x03059000, 0, c03059000},
    {0x03059001, 0, c03059001},
    {0x03059002, 0, c03059002},
};
static const tmuf_gbx_class SKIN = {0x03059000, "CGameCtnBlockSkin", 1, SKIN_CHUNKS, 3, NULL};

/* ---- CGameCtnChallenge (0x03043000) ---- */

static void c0304300d(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  ident(g, ((tmuf_challenge *)node)->vehicle);
}

static void c03043011(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  tmuf_challenge *c = node;
  tmuf_gbx_noderef(g); /* block stock */
  tmuf_gbx_node *p = tmuf_gbx_noderef(g);
  if (p && p->cls == &PARAMS) {
    const params *pp = p->data;
    c->bronze = pp->bronze;
    c->silver = pp->silver;
    c->gold = pp->gold;
    c->author_time = pp->author_time;
    c->time_limit = pp->time_limit;
    c->author_score = pp->author_score;
    c->has_time_limit = pp->has_time_limit;
  }
  c->kind = tmuf_gbx_u32(g);
}

static void c03043018(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  tmuf_challenge *c = node;
  c->has_laps = 1;
  c->lap_race = tmuf_gbx_bool(g);
  c->laps = tmuf_gbx_u32(g);
}

static void c0304301f(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  tmuf_challenge *c = node;
  ident(g, c->map);
  c->name = tmuf_gbx_string(g);
  ident(g, c->decoration);
  for (int i = 0; i < 3; i++)
    c->size[i] = tmuf_gbx_u32(g);
  tmuf_gbx_u32(g); /* need unlock / lightmap */
  c->block_version = tmuf_gbx_u32(g);
  c->block_count = tmuf_gbx_u32(g);
  if (c->block_count > MAX_BLOCKS) {
    tmuf_gbx_fail(g, "block count %u", c->block_count);
    return;
  }
  c->blocks = TMUF_ARENA_ARRAY(g->arena, tmuf_challenge_block, c->block_count ? c->block_count : 1);
  if (!c->blocks) {
    tmuf_gbx_fail(g, "out of memory");
    return;
  }
  for (uint32_t i = 0; i < c->block_count && !g->error; i++) {
    tmuf_challenge_block *b = &c->blocks[i];
    b->name = id_text(g);
    b->dir = tmuf_gbx_u8(g);
    b->x = tmuf_gbx_u8(g);
    b->y = tmuf_gbx_u8(g);
    b->z = tmuf_gbx_u8(g);
    b->flags = tmuf_gbx_u32(g);
    /* CGameCtnBlock::ArchiveBlock reads nothing else. TMUnlimiter maps
       start with a pseudo block (flags 0xffffffff, so with a skin) whose
       name is a "TMUnlimiter is required" message; the game finds no block
       info for it and skips it, and ignores TMUnlimiter's own chunks. */
    if (b->flags & TMUF_BLOCK_FLAG_SKIN) {
      b->skin_author = id_text(g);
      tmuf_gbx_noderef(g);
    }
  }
  /* Everything after the blocks (MediaTracker clips, music, ...) is not
     needed for simulation. */
  g->stop = 1;
}

static const tmuf_gbx_chunk CHALLENGE_CHUNKS[] = {
    {0x0304300d, 0, c0304300d},
    {0x03043011, 0, c03043011},
    {0x03043018, 1, c03043018},
    {0x0304301f, 0, c0304301f},
};
static const tmuf_gbx_class CHALLENGE = {
    0x03043000, "CGameCtnChallenge", sizeof(tmuf_challenge), CHALLENGE_CHUNKS,
    sizeof CHALLENGE_CHUNKS / sizeof CHALLENGE_CHUNKS[0], NULL,
};

/* the play mode of the description header chunk (0x03043002, version 6+) */
static uint32_t header_play_mode(const tmuf_gbx *g) {
  for (uint32_t i = 0; i < g->header_chunk_count; i++) {
    const tmuf_gbx_header_chunk *h = &g->header_chunks[i];
    if (h->id != 0x03043002u || h->size < 1)
      continue;
    const uint8_t *d = h->data;
    const uint8_t version = d[0];
    if (version < 6)
      return 0;
    size_t at = 1 + 4 + 16 + 4 + 4; /* need unlock, 4 times, cost, lap race */
    if (h->size < at + 4)
      return 0;
    return (uint32_t)d[at] | (uint32_t)d[at + 1] << 8 | (uint32_t)d[at + 2] << 16 | (uint32_t)d[at + 3] << 24;
  }
  return 0;
}

static const tmuf_gbx_class *const CHALLENGE_CLASSES[] = {&CHALLENGE, &COLLECTOR_LIST, &PARAMS, &SKIN};

int tmuf_challenge_parse(const uint8_t *data, size_t size, tmuf_arena *arena, tmuf_challenge *out, char *err,
                         size_t err_size) {
  memset(out, 0, sizeof *out);
  tmuf_mem_source src;
  tmuf_mem_source_init(&src, data, size);
  tmuf_gbx g;
  tmuf_gbx_init(&g, &src.base, arena, CHALLENGE_CLASSES, sizeof CHALLENGE_CLASSES / sizeof CHALLENGE_CLASSES[0]);
  tmuf_challenge *c = NULL;
  if (tmuf_gbx_read_header(&g))
    c = tmuf_gbx_read_root(&g);
  if (!g.error && c && !c->blocks)
    tmuf_gbx_fail(&g, "challenge has no block chunk");
  if (g.error || !c) {
    if (err && err_size)
      snprintf(err, err_size, "%s", g.message);
    return 0;
  }
  *out = *c;
  if (!out->has_time_limit)
    out->time_limit = 60000; /* CGameCtnChallengeParameters' default */
  out->play_mode = header_play_mode(&g);
  return 1;
}
