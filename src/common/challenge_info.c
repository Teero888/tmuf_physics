/* What a map's header says about it (tmuf_challenge_info_read): the chunks
   the game reads to list maps without loading them. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/arena.h"
#include "common/gbx.h"
#include "tmuf_physics/tmuf_physics.h"

typedef struct info_store {
  tmuf_challenge_info info; /* first: the pointer handed out */
  tmuf_arena arena;
} info_store;

/* the game's collection numbers (CMwId numbers of the environments) */
static const char *collection_name(uint32_t number) {
  static const char *const names[] = {"Speed", "Alpine", "Rally", "Island", "Bay", "Coast", "Stadium"};
  return number < sizeof names / sizeof names[0] ? names[number] : "";
}

static const char *id_or_number(tmuf_gbx *g, int collection) {
  uint32_t number = 0;
  const char *s = tmuf_gbx_id(g, &number);
  if (s)
    return s;
  if (collection)
    return collection_name(number);
  char buf[16];
  snprintf(buf, sizeof buf, "#%u", number);
  return tmuf_arena_strndup(g->arena, buf, strlen(buf));
}

/* a reader over one header chunk: each is archived on its own, its ids
   with their own lookback */
static void chunk_reader(tmuf_gbx *g, tmuf_mem_source *src, const tmuf_gbx_header_chunk *h, tmuf_arena *arena) {
  tmuf_mem_source_init(src, h->data, h->size);
  tmuf_gbx_init(g, &src->base, arena, NULL, 0);
}

/* CGameCtnChallenge 0x03043002: the description (medal times, mode, laps) */
static void read_description(const tmuf_gbx_header_chunk *h, tmuf_arena *arena, tmuf_challenge_info *o) {
  tmuf_mem_source src;
  tmuf_gbx g;
  chunk_reader(&g, &src, h, arena);
  const uint8_t version = tmuf_gbx_u8(&g);
  if (version < 3) {
    /* the old ident and name come first */
    for (int i = 0; i < 3; i++)
      tmuf_gbx_id(&g, NULL);
    tmuf_gbx_string(&g);
  }
  tmuf_gbx_u32(&g); /* need unlock */
  if (version >= 1) {
    o->bronze = tmuf_gbx_u32(&g);
    o->silver = tmuf_gbx_u32(&g);
    o->gold = tmuf_gbx_u32(&g);
    o->author_time = tmuf_gbx_u32(&g);
  }
  if (version == 2)
    tmuf_gbx_u8(&g);
  if (version >= 4)
    o->cost = tmuf_gbx_u32(&g);
  if (version >= 5)
    o->lap_race = tmuf_gbx_u32(&g) != 0;
  if (version == 6)
    tmuf_gbx_u32(&g); /* multilap */
  if (version >= 6)
    o->play_mode = tmuf_gbx_u32(&g);
  if (version >= 9)
    tmuf_gbx_u32(&g);
  if (version >= 10)
    o->author_score = tmuf_gbx_u32(&g);
  if (version >= 11)
    tmuf_gbx_u32(&g); /* editor mode */
  if (version >= 12)
    tmuf_gbx_u32(&g);
  if (version >= 13) {
    o->checkpoints = tmuf_gbx_u32(&g);
    o->laps = tmuf_gbx_u32(&g);
  }
  if (g.error)
    o->laps = 0;
}

/* 0x03043003: the ident (uid, environment, author), name, kind and mood */
static void read_common(const tmuf_gbx_header_chunk *h, tmuf_arena *arena, tmuf_challenge_info *o) {
  tmuf_mem_source src;
  tmuf_gbx g;
  chunk_reader(&g, &src, h, arena);
  const uint8_t version = tmuf_gbx_u8(&g);
  o->uid = id_or_number(&g, 0);
  o->environment = id_or_number(&g, 1);
  o->author_login = id_or_number(&g, 0);
  o->name = tmuf_gbx_string(&g);
  o->kind = tmuf_gbx_u8(&g);
  if (version >= 1) {
    tmuf_gbx_u32(&g); /* locked */
    tmuf_gbx_string(&g); /* password */
  }
  if (version >= 2) {
    o->decoration = id_or_number(&g, 0);
    id_or_number(&g, 1);
    id_or_number(&g, 0);
  }
  if (g.error) {
    if (!o->name)
      o->name = "";
    o->decoration = o->decoration ? o->decoration : "";
  }
}

/* 0x03043007: the thumbnail (a JPEG, its rows bottom first) and comments */
static void read_thumbnail(const tmuf_gbx_header_chunk *h, tmuf_arena *arena, tmuf_challenge_info *o) {
  tmuf_mem_source src;
  tmuf_gbx g;
  chunk_reader(&g, &src, h, arena);
  const uint32_t version = tmuf_gbx_u32(&g);
  if (version < 1)
    return;
  const uint32_t size = tmuf_gbx_u32(&g);
  if (g.error || size > h->size)
    return;
  tmuf_gbx_skip(&g, 15); /* "<Thumbnail.jpg>" */
  uint8_t *jpeg = tmuf_arena_alloc(arena, size ? size : 1);
  if (!jpeg)
    return;
  tmuf_gbx_read(&g, jpeg, size);
  if (g.error)
    return;
  o->thumbnail = jpeg;
  o->thumbnail_size = size;
  tmuf_gbx_skip(&g, 16); /* "</Thumbnail.jpg>" */
  tmuf_gbx_skip(&g, 10); /* "<Comments>" */
  const char *comments = tmuf_gbx_string(&g);
  if (!g.error)
    o->comments = comments;
}

/* 0x03043008: the author's nickname and zone */
static void read_author(const tmuf_gbx_header_chunk *h, tmuf_arena *arena, tmuf_challenge_info *o) {
  tmuf_mem_source src;
  tmuf_gbx g;
  chunk_reader(&g, &src, h, arena);
  tmuf_gbx_u32(&g); /* version */
  tmuf_gbx_u32(&g); /* author version */
  const char *login = tmuf_gbx_string(&g);
  const char *nickname = tmuf_gbx_string(&g);
  const char *zone = tmuf_gbx_string(&g);
  if (g.error)
    return;
  if (login[0])
    o->author_login = login;
  o->author_nickname = nickname;
  o->author_zone = zone;
}

tmuf_challenge_info *tmuf_challenge_info_read(const void *data, size_t size, char *err, size_t err_size) {
  info_store *store = calloc(1, sizeof *store);
  if (!store) {
    if (err && err_size)
      snprintf(err, err_size, "out of memory");
    return NULL;
  }
  tmuf_arena_init(&store->arena);
  tmuf_mem_source src;
  tmuf_mem_source_init(&src, data, size);
  tmuf_gbx g;
  tmuf_gbx_init(&g, &src.base, &store->arena, NULL, 0);
  if (!tmuf_gbx_read_header(&g) || g.class_id != 0x03043000u) {
    if (err && err_size)
      snprintf(err, err_size, "%s", g.error ? g.message : "not a challenge");
    tmuf_arena_free(&store->arena);
    free(store);
    return NULL;
  }
  tmuf_challenge_info *o = &store->info;
  o->name = o->uid = o->environment = o->author_login = o->author_nickname = o->author_zone = o->decoration = "";
  o->comments = "";
  for (uint32_t i = 0; i < g.header_chunk_count; i++) {
    const tmuf_gbx_header_chunk *h = &g.header_chunks[i];
    switch (h->id) {
    case 0x03043002u: read_description(h, &store->arena, o); break;
    case 0x03043003u: read_common(h, &store->arena, o); break;
    case 0x03043007u: read_thumbnail(h, &store->arena, o); break;
    case 0x03043008u: read_author(h, &store->arena, o); break;
    default: break;
    }
  }
  return o;
}

void tmuf_challenge_info_free(tmuf_challenge_info *info) {
  if (!info)
    return;
  info_store *store = (info_store *)info;
  tmuf_arena_free(&store->arena);
  free(store);
}
