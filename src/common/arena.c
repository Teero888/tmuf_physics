#include "common/arena.h"

#include <stdlib.h>
#include <string.h>

struct tmuf_arena_block {
  tmuf_arena_block *next;
  size_t size;
  /* data follows, 16-byte aligned */
};

#define BLOCK_HEADER ((sizeof(tmuf_arena_block) + 15u) & ~(size_t)15u)
#define MIN_BLOCK (64u * 1024u)

void tmuf_arena_init(tmuf_arena *a) { memset(a, 0, sizeof *a); }

void tmuf_arena_free(tmuf_arena *a) {
  tmuf_arena_block *b = a->head;
  while (b) {
    tmuf_arena_block *next = b->next;
    free(b);
    b = next;
  }
  memset(a, 0, sizeof *a);
}

void *tmuf_arena_alloc(tmuf_arena *a, size_t size) {
  size = (size + 15u) & ~(size_t)15u;
  if (size == 0)
    size = 16;
  if (!a->head || a->cap - a->used < size) {
    size_t block = size > MIN_BLOCK ? size : MIN_BLOCK;
    tmuf_arena_block *b = malloc(BLOCK_HEADER + block);
    if (!b)
      return NULL;
    b->next = a->head;
    b->size = block;
    a->head = b;
    a->used = 0;
    a->cap = block;
  }
  void *p = (char *)a->head + BLOCK_HEADER + a->used;
  a->used += size;
  memset(p, 0, size);
  return p;
}

char *tmuf_arena_strndup(tmuf_arena *a, const char *s, size_t n) {
  char *p = tmuf_arena_alloc(a, n + 1);
  if (p) {
    memcpy(p, s, n);
    p[n] = 0;
  }
  return p;
}

void *tmuf_arena_array(tmuf_arena *a, size_t n, size_t size) {
  if (size && n > (size_t)-1 / size)
    return NULL;
  return tmuf_arena_alloc(a, n * size);
}
