#ifndef TMUF_COMMON_ASSETS_H
#define TMUF_COMMON_ASSETS_H

/* Loads pack files on demand (each parsed once) and follows node references
   across files. One loader per scene build; not shared between threads. */

#include <stddef.h>
#include <stdint.h>

#include "common/arena.h"
#include "common/gbx.h"
#include "common/packset.h"

typedef struct tmuf_asset {
  tmuf_pack_ref ref;
  char path[512]; /* stored path */
  tmuf_gbx gbx;   /* header, node table; its source is closed */
  void *root;
  uint32_t class_id;
  int failed;
  char error[1024];
} tmuf_asset;

typedef struct tmuf_assets {
  const tmuf_packset *set;
  tmuf_arena arena;
  uint32_t count, cap;
  tmuf_asset **items;
} tmuf_assets;

void tmuf_assets_init(tmuf_assets *a, const tmuf_packset *set);
void tmuf_assets_free(tmuf_assets *a);

tmuf_asset *tmuf_assets_load(tmuf_assets *a, tmuf_pack_ref ref);
tmuf_asset *tmuf_assets_load_path(tmuf_assets *a, const char *plain_path);

/* Target of node reference n found in asset owner: inline nodes as is,
   external ones by loading the referenced file (its root). Sets *owner_out
   to the asset that holds the returned node. NULL if unresolvable. */
tmuf_gbx_node *tmuf_assets_follow(tmuf_assets *a, tmuf_asset *owner, tmuf_gbx_node *n, tmuf_asset **owner_out);

#endif
