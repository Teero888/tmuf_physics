#ifndef TMUF_COMMON_REPLAY_H
#define TMUF_COMMON_REPLAY_H

/* Replay files (CGameCtnReplayRecord) and their ghosts (CGameCtnGhost). */

#include <stddef.h>
#include <stdint.h>

#include "common/arena.h"

typedef struct tmuf_input_event {
  uint32_t time; /* ms, including the input clock offset */
  uint8_t action; /* index into tmuf_ghost.actions */
  uint32_t value;
} tmuf_input_event;

typedef struct tmuf_ghost {
  int has_race_time, has_respawns, has_stunt_score;
  uint32_t race_time, respawns, stunt_score;
  const char *vehicle[3]; /* id, collection, author */
  const char *login;

  /* Validation inputs (0x03092019, or 0x03092011 without seed). */
  int has_inputs;
  int has_validation_seed;
  uint32_t input_duration;
  uint32_t input_version;
  uint32_t action_count;
  const char **actions;
  uint32_t event_count;
  tmuf_input_event *events;
  uint32_t validation_seed;

  /* CGameGhost state samples (zlib). */
  const uint8_t *samples;
  uint32_t samples_size, samples_packed_size;
} tmuf_ghost;

typedef struct tmuf_replay_file {
  uint32_t class_id;
  const uint8_t *challenge; /* embedded CGameCtnChallenge GBX */
  uint32_t challenge_size;
  uint32_t ghost_count;
  tmuf_ghost **ghosts;
  int deprecated_ghost_chunk; /* TMr.6 layout (0x03093004) */
} tmuf_replay_file;

/* Everything is allocated from arena. On failure returns 0 and writes a
   message to err. */
int tmuf_replay_parse(const uint8_t *data, size_t size, tmuf_arena *arena, tmuf_replay_file *out, char *err,
                      size_t err_size);

#endif
