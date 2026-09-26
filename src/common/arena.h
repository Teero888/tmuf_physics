#ifndef TMUF_COMMON_ARENA_H
#define TMUF_COMMON_ARENA_H

/* Bump allocator: everything parsed from one file lives in one arena and is
   freed at once. */

#include <stddef.h>

typedef struct tmuf_arena_block tmuf_arena_block;

typedef struct tmuf_arena {
  tmuf_arena_block *head;
  size_t used, cap;
} tmuf_arena;

void tmuf_arena_init(tmuf_arena *a);
void tmuf_arena_free(tmuf_arena *a);
/* Zeroed, 16-byte aligned. NULL on allocation failure. */
void *tmuf_arena_alloc(tmuf_arena *a, size_t size);
char *tmuf_arena_strndup(tmuf_arena *a, const char *s, size_t n);

/* n elements of size bytes, NULL on overflow. */
void *tmuf_arena_array(tmuf_arena *a, size_t n, size_t size);

#define TMUF_ARENA_NEW(a, type) ((type *)tmuf_arena_alloc((a), sizeof(type)))
#define TMUF_ARENA_ARRAY(a, type, n) ((type *)tmuf_arena_array((a), (size_t)(n), sizeof(type)))

#endif
