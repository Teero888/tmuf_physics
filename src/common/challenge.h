#ifndef TMUF_COMMON_CHALLENGE_H
#define TMUF_COMMON_CHALLENGE_H

/* Maps (CGameCtnChallenge), up to and including the block list. */

#include <stddef.h>
#include <stdint.h>

#include "common/arena.h"

/* Block flags (0x0304301f). */
#define TMUF_BLOCK_FLAG_SKIN 0x8000u
#define TMUF_BLOCK_FLAG_WAYPOINT 0x100000u

typedef struct tmuf_challenge_block {
  const char *name;
  uint8_t dir; /* 0 north, 1 east, 2 south, 3 west */
  uint8_t x, y, z;
  uint32_t flags; /* raw archive flags */
  const char *skin_author;
} tmuf_challenge_block;

typedef struct tmuf_challenge {
  /* map ident (uid, collection, author) and decoration ident */
  const char *map[3];
  const char *name;
  const char *decoration[3];
  const char *vehicle[3];
  uint32_t size[3];
  uint32_t block_version;
  uint32_t block_count;
  tmuf_challenge_block *blocks;

  uint32_t kind; /* 0x03043011 */
  int has_laps;
  int lap_race;
  uint32_t laps;
  uint32_t bronze, silver, gold, author_time; /* ms, from the parameters */
  uint32_t time_limit, author_score;          /* stunts */
} tmuf_challenge;

int tmuf_challenge_parse(const uint8_t *data, size_t size, tmuf_arena *arena, tmuf_challenge *out, char *err,
                         size_t err_size);

#endif
