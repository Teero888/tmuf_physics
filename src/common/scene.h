#ifndef TMUF_COMMON_SCENE_H
#define TMUF_COMMON_SCENE_H

/* Static world of a map: block placements resolved to world-space collision
   surfaces. Shared by both physics backends. */

#include <stddef.h>
#include <stdint.h>

#include <tmuf_physics/tmuf_physics.h>

#include "common/assets.h"
#include "common/challenge.h"
#include "common/pack_classes.h"
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
  uint32_t pylon_raise; /* a pylon middle: levels its mesh vertices are raised by */
  /* baked lighting: the cells its solid takes in the lightmap atlas (0:
     none), and whether it is the decoration's "Warp" mobil */
  uint8_t lightmap_cells;
  uint8_t warp;
  uint8_t remap_set; /* the visual material remaps of its block (tmuf_visual_remap.set), TMUF_REMAP_SET_NONE */
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

/* A material the game loads in place of another for a block's mobil
   (CGameSkin::AddRemappingParams while CGameCtnChallenge::CreateMobilForBlock
   creates it): set is the collection's surface replacement index for
   replacement materials, TMUF_REMAP_SET_DECORATION for the decoration's
   terrain modifier (blocks in modified columns). */
typedef struct tmuf_visual_remap {
  char source[600]; /* plain path of the material, or of a folder of materials */
  int folder;
  uint8_t set;
  char replacement[600]; /* plain path of the replacement material */
} tmuf_visual_remap;

#define TMUF_REMAP_SET_DECORATION 0xfeu
#define TMUF_REMAP_SET_NONE 0xffu
#define TMUF_SCENE_MAX_VISUAL_REMAPS 256



/* A visible visual of a placed solid (only with TMUF_SCENE_VISUALS): the
   tree's visual and material references (in the asset holding the tree) and
   where it is drawn. */
typedef struct tmuf_scene_visual {
  tmuf_asset *owner;
  tmuf_gbx_node *visual;
  tmuf_gbx_node *material, *shader; /* the tree's own, either may be NULL */
  tmuf_gbx_node *func;              /* the tree's function (CPlugTree 0x0904f011), NULL for none */
  tmuf_iso iso;
  uint32_t tag; /* as tmuf_scene_corpus.tag */
  float lod_near, lod_far; /* camera distances it is drawn at (visual mips) */
  uint32_t corpus; /* index into tmuf_scene.corpora */
  /* the innermost CPlugTreeVisualMip level it belongs to: index into
     tmuf_scene.mips (UINT32_MAX for none) and the level */
  uint32_t mip, mip_level;
} tmuf_scene_visual;

/* A placed CPlugTreeVisualMip (only with TMUF_SCENE_VISUALS), see
   tmuf_visual_mip */
typedef struct tmuf_scene_mip {
  uint32_t corpus;
  uint32_t parent, parent_level; /* the mip level holding it, UINT32_MAX for none */
  uint32_t rule;                 /* TMUF_VISUAL_MIP_* */
  float box[6];                  /* the tree's box (CPlugTree+0x34) in world */
  float sphere[4];               /* its lowest level's packed box: centre, half diagonal */
  uint32_t level_count;
  const float *far_z;
} tmuf_scene_mip;

/* A light a placed solid's tree carries (CPlugTreeLight, only with
   TMUF_SCENE_VISUALS): its CPlugLight reference (in the asset holding the
   tree) and the tree's world location. */
typedef struct tmuf_scene_light {
  tmuf_asset *owner;
  tmuf_gbx_node *light;
  tmuf_iso iso;
  uint32_t tag;
  float lod_near, lod_far;
  uint8_t hidden; /* below a decorator tree not shown at the highest quality */
  float reflect_plane[4]; /* tmuf_light.reflect_plane */
} tmuf_scene_light;

typedef struct tmuf_scene_catalog_entry {
  const char *name; /* collector identifier */
  tmuf_pack_ref ref;
  uint8_t tag;
} tmuf_scene_catalog_entry;

/* A CMotionEmitterLeaves placed with its mobil (only with
   TMUF_SCENE_VISUALS): the ellipsoid's centre in world, its half extents
   (world axes) */
typedef struct tmuf_scene_leaf_emitter {
  float center[3], half[3];
  uint32_t tag;
} tmuf_scene_leaf_emitter;

typedef struct tmuf_scene {
  tmuf_assets assets;
  const char *collection;
  const char *default_vehicle; /* the collection's vehicle collector id */
  float square_size, square_height;
  uint32_t size[3];    /* map size in squares (decoration size) */
  uint32_t base_height; /* default zone height */
  int collect_triangles;
  int collect_visuals;
  uint32_t visual_count, visual_cap;
  tmuf_scene_visual *visuals; /* only with TMUF_SCENE_VISUALS */
  uint32_t light_count, light_cap;
  tmuf_scene_light *lights; /* only with TMUF_SCENE_VISUALS */
  uint32_t mip_count, mip_cap;
  tmuf_scene_mip *mips;                    /* only with TMUF_SCENE_VISUALS */
  uint32_t leaf_emitter_count, leaf_emitter_cap;
  tmuf_scene_leaf_emitter *leaf_emitters; /* only with TMUF_SCENE_VISUALS */
  /* the first emitter's manager model (its CMotionManagerLeaves) */
  tmuf_asset *leaf_manager_owner;
  tmuf_gbx_node *leaf_manager;
  uint32_t current_mip, current_mip_level; /* while emitting */
  int decorator_hidden_depth;
  uint32_t *water_ground_tags; /* geometry water, while building: per cell the tag of the
                                  ground block of a wet zone, UINT32_MAX if none */
  uint32_t triangle_count, triangle_cap;
  tmuf_static_triangle *triangles; /* only with TMUF_SCENE_TRIANGLES */
  uint32_t blocks_placed, blocks_missing;
  uint32_t current_block;
  int current_has_reflect_plane; /* while emitting a solid's tree: its "PlaneReflect" */
  float current_reflect_plane[4];
  float current_root_up[3]; /* and its root's up axis (world) */
  const char *current_mobil; /* name of the mobil being placed */
  uint8_t current_lightmap_cells;
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
  uint8_t current_remap_set;
  uint32_t visual_remap_count;
  tmuf_visual_remap *visual_remaps; /* TMUF_SCENE_MAX_VISUAL_REMAPS, with TMUF_SCENE_VISUALS */
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
  /* the distinct water planes of the corpora (Zone_UpdateWaterHeights; geometry
     water only): their levels, -d, in the order the cells' index + 1 names */
  uint32_t water_plane_count;
  float water_plane_level[255];
  /* the decoration (CGameCtnDecoration) and its scene (CScene3d) files,
     NULL if not found */
  tmuf_asset *decoration_asset, *decoration_scene_asset;
  const tmuf_collection *collection_info; /* the map's collection */
  char error[600];
  uint32_t block_skin_count; /* per map block (NULL file: none) */
  tmuf_block_skin *block_skins;
} tmuf_scene;

/* flags */
enum {
  TMUF_SCENE_TRIANGLES = 1, /* collect the world-space triangle list (scene.triangles) */
  TMUF_SCENE_VISUALS = 2,   /* collect the visible visuals (scene.visuals) */
};

/* CPlugMaterial::GetSupportedShader for a material reference in owner: the
   shader the game draws with, its asset, and the material's custom bitmaps
   (sampler substitutions) if any. NULL if node is not a material.
   is_night: the fid parameter IsNight (tmuf_weather.is_night), which picks
   the device set's day or night shader (CPlugMaterial::ApplyFidParameters) */
tmuf_gbx_node *tmuf_scene_material_shader(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *node, int is_night,
                                          tmuf_asset **shader_owner, const tmuf_plug_material_custom **custom,
                                          tmuf_asset **custom_owner);

int tmuf_scene_build(tmuf_scene *scene, const tmuf_packset *set, const tmuf_challenge *map, unsigned flags);
void tmuf_scene_free(tmuf_scene *scene);

/* Surface material id of the material at plain path `path` under the
   corpus material mode `materials`; returns 0 if the material is kept. */
int tmuf_scene_remap_material(const tmuf_scene *scene, uint8_t materials, const char *path, uint8_t *id);

/* The material the game draws a corpus with in place of the material at
   plain path `path` (its tmuf_scene_corpus.remap_set): the replacement's
   plain path, or NULL when it keeps it. */
const char *tmuf_scene_visual_remap(const tmuf_scene *scene, uint8_t set, const char *path);

/* CGameCtnChallenge::CreateNewPylonMobil for a pylon middle's mesh: a copy
   of the vertices and triangles with the vertices above half a square
   raised by `raise` squares and every triangle's plane recomputed
   (GmSurfMesh::ComputePlane); the octree stays the archived one. Returns 0
   when out of memory. */
struct tmuf_plug_surface_geom;
int tmuf_scene_raise_mesh(const struct tmuf_plug_surface_geom *geom, uint32_t raise, float square_height,
                          float **vertices, uint8_t **triangles);

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
