#ifndef TMUF_COMMON_SCENE_H
#define TMUF_COMMON_SCENE_H

/* Static world of a map: block placements resolved to world-space collision
   surfaces. Shared by both physics backends. */

#include <stddef.h>
#include <stdint.h>

#include <tmuf_physics/tmuf_physics.h>

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
  uint8_t is_static;       /* item flag 0x80000: in its group's static tree, else a
                              non-static corpus of the group (e.g. StadiumWarpFlags) */
  uint8_t materials;       /* TMUF_MATERIALS_* */
  /* race triggers: the block's race role, spawn location and respawn mode */
  uint8_t race_role;       /* TMUF_RACE_* */
  uint8_t respawn_current; /* respawns keep the car's current spawn */
  uint8_t has_spawn;
  tmuf_iso spawn;
} tmuf_scene_corpus;

/* CGameCtnBlockInfo race role (way type) */
enum { TMUF_RACE_NONE, TMUF_RACE_START, TMUF_RACE_CHECKPOINT, TMUF_RACE_FINISH, TMUF_RACE_START_FINISH };

/* Which materials a mobil's solid uses (StaticSolidMaterialVariant): its
   own, or remapped through the collection's terrain-modifier skins. */
enum { TMUF_MATERIALS_OWN, TMUF_MATERIALS_REPLACEMENT, TMUF_MATERIALS_SKIN };

/* A material the terrain-modifier skins replace, and the surface material
   of its replacement. */
typedef struct tmuf_material_remap {
  char source[600]; /* plain path of the material, or of a folder of materials */
  int folder;
  uint8_t replacement_id;
} tmuf_material_remap;

#define TMUF_SCENE_MAX_MATERIAL_REMAPS 128



typedef struct tmuf_scene_catalog_entry {
  const char *name; /* collector identifier */
  tmuf_pack_ref ref;
  uint8_t tag;
} tmuf_scene_catalog_entry;

typedef struct tmuf_scene {
  tmuf_assets assets;
  const char *collection;
  const char *default_vehicle; /* the collection's vehicle collector id */
  float square_size, square_height;
  uint32_t size[3];    /* map size in squares (decoration size) */
  uint32_t base_height; /* default zone height */
  int collect_triangles;
  uint32_t *water_ground_tags; /* geometry water, while building: per cell the tag of the
                                  ground block of a wet zone, UINT32_MAX if none */
  uint32_t triangle_count, triangle_cap;
  tmuf_static_triangle *triangles; /* only with TMUF_SCENE_TRIANGLES */
  uint32_t blocks_placed, blocks_missing;
  uint32_t current_block;
  uint8_t current_trigger;
  uint32_t current_item_flags;
  int helper_depth;
  int force_static;
  uint32_t pylon_raise;
  uint8_t current_materials;
  uint8_t current_race_role, current_respawn_current, current_has_spawn;
  tmuf_iso current_spawn;
  uint32_t material_remap_count;
  tmuf_material_remap material_remaps[TMUF_SCENE_MAX_MATERIAL_REMAPS];
  uint32_t frontier_count;
  const void *frontier_info[64]; /* block infos of frontier zones */
  uint32_t frontier_height[64];
  int has_start;
  tmuf_iso start; /* spawn location of the first start block, else identity */
  uint32_t rand_state;
  uint32_t catalog_count, catalog_cap;
  uint32_t corpus_count, corpus_cap;
  tmuf_scene_corpus *corpora; /* in the order the game adds them */
  tmuf_scene_catalog_entry *catalog;
  tmuf_scene_water water;
  char error[600];
} tmuf_scene;

/* flags */
enum { TMUF_SCENE_TRIANGLES = 1 }; /* collect the world-space triangle list (scene.triangles) */

int tmuf_scene_build(tmuf_scene *scene, const tmuf_packset *set, const tmuf_challenge *map, unsigned flags);
void tmuf_scene_free(tmuf_scene *scene);

/* Surface material id of the material at plain path `path` under the
   corpus material mode `materials`; returns 0 if the material is kept. */
int tmuf_scene_remap_material(const tmuf_scene *scene, uint8_t materials, const char *path, uint8_t *id);

/* CSceneVehicleWaterZone::AcceptsRegion for a box spanning [lower, upper]
   in height around the column at (x, z). */
int tmuf_water_accepts(const tmuf_scene_water *w, float x, float z, float lower, float upper);

/* Game transform math (GmIso4), same operation order. */
void tmuf_iso_identity(tmuf_iso *iso);
void tmuf_iso_from_archive(tmuf_iso *iso, const float v[12]);
/* out = apply a, then b (GmIso4::SetMult(a, b)). */
void tmuf_iso_mult(tmuf_iso *out, const tmuf_iso *a, const tmuf_iso *b);
void tmuf_iso_point(const tmuf_iso *iso, const float p[3], float out[3]);

#endif
