#ifndef TMUF_COMMON_GBX_H
#define TMUF_COMMON_GBX_H

/*
 * GameBox (GBX) archive reader.
 *
 * Errors are sticky: after the first failure every read returns zeros and
 * g->error stays set, so chunk readers can read straight through and check
 * once at the end.
 */

#include <stddef.h>
#include <stdint.h>

#include "common/arena.h"

#define TMUF_GBX_FACADE 0xfacade01u
#define TMUF_GBX_SKIP 0x534b4950u /* "PIKS" */
#define TMUF_GBX_NULL_NODE 0xffffffffu

/* Byte source. mix is the game's archive feedback (NULL if the source has
   none). */
typedef struct tmuf_source tmuf_source;
struct tmuf_source {
  int (*read)(tmuf_source *s, void *out, size_t n);
  void (*mix)(tmuf_source *s, const uint8_t *bytes, size_t n);
};

typedef struct tmuf_mem_source {
  tmuf_source base;
  const uint8_t *data;
  size_t size, pos;
} tmuf_mem_source;

void tmuf_mem_source_init(tmuf_mem_source *s, const uint8_t *data, size_t size);

typedef struct tmuf_gbx tmuf_gbx;
typedef struct tmuf_gbx_class tmuf_gbx_class;

typedef void (*tmuf_chunk_fn)(tmuf_gbx *g, void *node, uint32_t chunk_id);

/* tmuf_gbx_chunk.skippable: 0 never, 1 always ("PIKS" + u32 size + data),
   TMUF_GBX_MAYBE_SKIP: skippable if "PIKS" follows. */
#define TMUF_GBX_MAYBE_SKIP 2

typedef struct tmuf_gbx_chunk {
  uint32_t id;       /* current chunk id (class id wrapped) */
  int skippable;
  tmuf_chunk_fn read; /* NULL: skip; only valid for skippable chunks */
} tmuf_gbx_chunk;

struct tmuf_gbx_class {
  uint32_t id; /* current class id */
  const char *name;
  size_t size; /* node struct size, allocated zeroed from the arena */
  const tmuf_gbx_chunk *chunks;
  size_t chunk_count;
  const tmuf_gbx_class *base; /* chunks of base classes are searched too */
};

typedef struct tmuf_gbx_node {
  uint32_t class_id;
  const tmuf_gbx_class *cls;
  void *data;          /* NULL for external nodes */
  const char *file;    /* external nodes: file name as stored */
  int external;
} tmuf_gbx_node;

typedef struct tmuf_gbx_header_chunk {
  uint32_t id;
  uint32_t size;
  int heavy;
  const uint8_t *data;
} tmuf_gbx_header_chunk;

struct tmuf_gbx {
  tmuf_source *src;
  tmuf_arena *arena;
  const tmuf_gbx_class *const *classes;
  size_t class_count;
  int feedback; /* mix node parent class ids into the source, as the game does */

  int error;
  uint32_t node_class; /* actual class id of the node being read */
  int stop; /* set by a chunk reader to end the current node early */
  char message[192];
  uint64_t pos; /* bytes consumed from src */
  uint8_t peek_buf[4];
  int peeked;

  /* lookback strings (CMwId) */
  int id_version_read;
  const char **ids;
  uint32_t id_count, id_cap;

  /* header */
  uint16_t version;
  uint8_t format[4];
  uint32_t class_id;
  uint32_t header_chunk_count;
  tmuf_gbx_header_chunk *header_chunks;
  uint32_t node_count;
  tmuf_gbx_node *nodes; /* index 1..node_count */

  /* memory source used for LZO-compressed bodies */
  tmuf_mem_source body_src;
  uint8_t *body; /* arena */
  size_t body_size;
};

void tmuf_gbx_init(tmuf_gbx *g, tmuf_source *src, tmuf_arena *arena, const tmuf_gbx_class *const *classes,
                   size_t class_count);
void tmuf_gbx_fail(tmuf_gbx *g, const char *fmt, ...);

/* Header, reference table and, for compressed bodies, decompression (the
   reader then continues on the decompressed body). */
int tmuf_gbx_read_header(tmuf_gbx *g);
/* Root node body. Returns the node struct, NULL on error. */
void *tmuf_gbx_read_root(tmuf_gbx *g);

/* Primitives. */
int tmuf_gbx_read(tmuf_gbx *g, void *out, size_t n);
int tmuf_gbx_skip(tmuf_gbx *g, size_t n);
uint32_t tmuf_gbx_peek_u32(tmuf_gbx *g);
uint8_t tmuf_gbx_u8(tmuf_gbx *g);
uint16_t tmuf_gbx_u16(tmuf_gbx *g);
uint32_t tmuf_gbx_u32(tmuf_gbx *g);
uint64_t tmuf_gbx_u64(tmuf_gbx *g);
float tmuf_gbx_f32(tmuf_gbx *g);
int tmuf_gbx_bool(tmuf_gbx *g);
/* Length-prefixed string, NUL-terminated copy in the arena ("" on error). */
const char *tmuf_gbx_string(tmuf_gbx *g);
/* Lookback string. Numeric ids (no string) are returned in *number with
   NULL; empty ids return "" . number may be NULL. */
const char *tmuf_gbx_id(tmuf_gbx *g, uint32_t *number);
/* External file reference by node index (no inline node). NULL for null. */
tmuf_gbx_node *tmuf_gbx_fidref(tmuf_gbx *g);
/* Node reference; parses inline nodes on first sight. NULL for null refs. */
tmuf_gbx_node *tmuf_gbx_noderef(tmuf_gbx *g);
/* Parse a node's chunk stream until FACADE01 (with the node feedback of
   CMwNod::Archive). _as gives the node's actual class when it is read with
   an ancestor's reader. */
void tmuf_gbx_node_body(tmuf_gbx *g, const tmuf_gbx_class *cls, void *node);
void tmuf_gbx_node_body_as(tmuf_gbx *g, const tmuf_gbx_class *cls, uint32_t class_id, void *node);
/* Mix a value into the source feedback (class-specific archive feedback). */
void tmuf_gbx_mix_u32(tmuf_gbx *g, uint32_t v);

uint32_t tmuf_wrap_class_id(uint32_t archive_id);
uint32_t tmuf_unwrap_class_id(uint32_t current_id);
static inline uint32_t tmuf_wrap_chunk_id(uint32_t id) { return tmuf_wrap_class_id(id & 0xfffff000u) | (id & 0xfffu); }
/* Parent class id (0 for the root), 0xffffffff if unknown. */
uint32_t tmuf_class_parent(uint32_t class_id);
const char *tmuf_class_name(uint32_t class_id);

#endif
