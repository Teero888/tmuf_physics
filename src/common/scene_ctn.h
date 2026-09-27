#ifndef TMUF_COMMON_SCENE_CTN_H
#define TMUF_COMMON_SCENE_CTN_H

/* Challenge construction: which block mobils, clips and pylons end up in the
   game's zone, in the order the game adds them (CGameCtnChallenge,
   CGameCtnApp::UpdateBlockMobils / AddClipsToScene). Internal to
   scene.c. */

#include <stdint.h>

#include "common/challenge.h"
#include "common/pack_classes.h"
#include "common/scene.h"

/* A mobil source: a CSceneObject node in an asset. */
typedef struct ctn_source {
  tmuf_asset *asset;
  tmuf_gbx_node *node;
} ctn_source;

enum { CTN_INSTALL_BLOCK, CTN_INSTALL_CLIP, CTN_INSTALL_PYLON };
enum { CTN_MATERIAL_BLOCK, CTN_MATERIAL_REPLACEMENT, CTN_MATERIAL_SKIN };

/* One entry of the installation stream (ReplaySceneInstallation). */
typedef struct ctn_install {
  int kind;
  int active, suppressed;
  tmuf_iso iso;
  uint32_t tag; /* map block index, 0x80000000|i automatic, 0xa0000000|i clip, 0xb0000000|i pylon */
  ctn_source main;
  ctn_source helper[2];  /* family, common (never collided) */
  ctn_source clip[4];    /* clip side sources */
  uint32_t pylon_raise;  /* pylon middle: levels its mesh vertices are raised by */
  int pylon_generated;
  int material;
  const char *terrain_modifier;
  int start_line; /* way type start or start/finish */
  const tmuf_block_info *info;
  int ground;
} ctn_install;

typedef struct ctn_result {
  uint32_t count, cap;
  ctn_install *items;
  uint32_t blocks_placed, blocks_missing;
} ctn_result;

/* Builds the installation stream of a map. */
int ctn_build(tmuf_scene *s, const tmuf_challenge *map, tmuf_asset *collection_asset, ctn_result *out);
void ctn_result_free(ctn_result *r);

/* scene.c helpers used by the construction */
tmuf_asset *scene_block_info(tmuf_scene *s, const char *name);
uint32_t scene_rand_nat(tmuf_scene *s, uint32_t lo, uint32_t hi);
int scene_debug(void);
void tmuf_iso_rotate_quarter_y(tmuf_iso *iso, unsigned quarter);

#endif
