#ifndef TMUF_COMMON_SCENE_H
#define TMUF_COMMON_SCENE_H

/* Static world of a map: block placements resolved to world-space collision
   surfaces. Shared by both physics backends. */

#include <stddef.h>
#include <stdint.h>

#include "common/assets.h"
#include "common/challenge.h"
#include "common/packset.h"

typedef struct tmuf_iso {
  float m[3][3]; /* m[row][col]; a point p maps to m * p + t */
  float t[3];
} tmuf_iso;

typedef struct tmuf_static_triangle {
  float v[3][3];
  uint16_t material; /* surface-local material index */
  uint32_t block;    /* index of the map block that placed it */
} tmuf_static_triangle;

typedef struct tmuf_scene {
  tmuf_assets assets;
  const char *collection;
  float square_size, square_height;
  uint32_t triangle_count, triangle_cap;
  tmuf_static_triangle *triangles;
  uint32_t blocks_placed, blocks_missing;
  uint32_t current_block;
  char error[600];
} tmuf_scene;

int tmuf_scene_build(tmuf_scene *scene, const tmuf_packset *set, const tmuf_challenge *map);
void tmuf_scene_free(tmuf_scene *scene);

/* Game transform math (GmIso4), same operation order. */
void tmuf_iso_identity(tmuf_iso *iso);
void tmuf_iso_from_archive(tmuf_iso *iso, const float v[12]);
/* out = apply a, then b (GmIso4::SetMult(a, b)). */
void tmuf_iso_mult(tmuf_iso *out, const tmuf_iso *a, const tmuf_iso *b);
void tmuf_iso_point(const tmuf_iso *iso, const float p[3], float out[3]);

#endif
