#include "common/assets.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/pack_classes.h"

void tmuf_assets_init(tmuf_assets *a, const tmuf_packset *set) {
  memset(a, 0, sizeof *a);
  a->set = set;
  tmuf_arena_init(&a->arena);
}

void tmuf_assets_free(tmuf_assets *a) {
  free(a->items);
  tmuf_arena_free(&a->arena);
  memset(a, 0, sizeof *a);
}

tmuf_asset *tmuf_assets_load(tmuf_assets *a, tmuf_pack_ref ref) {
  if (ref.pack < 0)
    return NULL;
  for (uint32_t i = 0; i < a->count; i++)
    if (a->items[i]->ref.pack == ref.pack && a->items[i]->ref.file == ref.file)
      return a->items[i]->failed ? NULL : a->items[i];
  if (a->count == a->cap) {
    uint32_t cap = a->cap ? a->cap * 2 : 64;
    tmuf_asset **items = realloc(a->items, sizeof *items * cap);
    if (!items)
      return NULL;
    a->items = items;
    a->cap = cap;
  }
  tmuf_asset *as = TMUF_ARENA_NEW(&a->arena, tmuf_asset);
  if (!as)
    return NULL;
  a->items[a->count++] = as;
  as->ref = ref;
  const tmuf_pack *pack = &a->set->packs[ref.pack];
  tmuf_pack_file_path(pack, ref.file, as->path, sizeof as->path);
  tmuf_pack_stream ps;
  if (!tmuf_pack_stream_open(&ps, pack, ref.file)) {
    as->failed = 1;
    snprintf(as->error, sizeof as->error, "cannot open %s", as->path);
    return NULL;
  }
  tmuf_gbx_init(&as->gbx, &ps.base, &a->arena, tmuf_pack_classes, tmuf_pack_class_count);
  as->gbx.feedback = 1;
  if (tmuf_gbx_read_header(&as->gbx))
    as->root = tmuf_gbx_read_root(&as->gbx);
  as->class_id = as->gbx.class_id;
  tmuf_pack_stream_close(&ps);
  as->gbx.src = NULL;
  if (as->gbx.error || !as->root) {
    as->failed = 1;
    snprintf(as->error, sizeof as->error, "%s: %s", as->path, as->gbx.message);
    fprintf(stderr, "asset: %s\n", as->error);
    return NULL;
  }
  return as;
}

tmuf_asset *tmuf_assets_load_path(tmuf_assets *a, const char *plain_path) {
  return tmuf_assets_load(a, tmuf_packset_find(a->set, plain_path));
}

tmuf_gbx_node *tmuf_assets_follow(tmuf_assets *a, tmuf_asset *owner, tmuf_gbx_node *n, tmuf_asset **owner_out) {
  if (owner_out)
    *owner_out = owner;
  if (!n)
    return NULL;
  if (!n->external)
    return n->data ? n : NULL;
  tmuf_pack_ref ref = tmuf_packset_resolve(a->set, &owner->gbx, n, owner->path, NULL, 0);
  tmuf_asset *target = tmuf_assets_load(a, ref);
  if (!target)
    return NULL;
  if (owner_out)
    *owner_out = target;
  return &target->gbx.nodes[0];
}
