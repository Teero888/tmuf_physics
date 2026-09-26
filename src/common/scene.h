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

/* A static item as the game adds it to the collision zone: a solid's tree
   (in the asset that holds it) at a world location. */
typedef struct tmuf_scene_corpus {
  tmuf_asset *owner;
  tmuf_gbx_node *tree;
  tmuf_iso iso;
  uint32_t tag; /* map block index, 0x80000000|i automatic, 0xc0000000|i decoration */
  uint8_t trigger; /* TriggerCheckpoint / TriggerFinishLine: not part of the static world */
  uint32_t item_flags; /* archived CHmsItem physics word of its mobil, 0 if none */
  uint8_t collision_group; /* CHmsItem::ECollisionGroup the game gives it (4: static) */
} tmuf_scene_corpus;

typedef struct tmuf_scene_catalog_entry {
  const char *name; /* collector identifier */
  tmuf_pack_ref ref;
  uint8_t tag;
} tmuf_scene_catalog_entry;

typedef struct tmuf_scene {
  tmuf_assets assets;
  const char *collection;
  float square_size, square_height;
  uint32_t size[3];    /* map size in squares (decoration size) */
  uint32_t base_height; /* default zone height */
  uint32_t triangle_count, triangle_cap;
  tmuf_static_triangle *triangles;
  uint32_t blocks_placed, blocks_missing;
  uint32_t current_block;
  uint8_t current_trigger;
  uint32_t current_item_flags;
  int helper_depth;
  uint32_t frontier_count;
  const void *frontier_info[64]; /* block infos of frontier zones */
  uint32_t frontier_height[64];
  int has_start;
  tmuf_iso start; /* spawn location of the first start block */
  uint32_t rand_state;
  uint32_t catalog_count, catalog_cap;
  uint32_t corpus_count, corpus_cap;
  tmuf_scene_corpus *corpora; /* in the order the game adds them */
  tmuf_scene_catalog_entry *catalog;
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
