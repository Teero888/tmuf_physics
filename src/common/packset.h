#ifndef TMUF_COMMON_PACKSET_H
#define TMUF_COMMON_PACKSET_H

/* All installed packs of a Packs directory with a path index. Read-only
   after tmuf_packset_open, so it can be shared between threads. */

#include <stddef.h>
#include <stdint.h>

#include "common/gbx.h"
#include "common/pack.h"

typedef struct tmuf_packset_entry {
  uint64_t hash; /* 0: empty slot */
  uint16_t pack;
  uint32_t file;
} tmuf_packset_entry;

typedef struct tmuf_packset {
  char dir[1024]; /* the Packs directory */
  tmuf_packlist list;
  int pack_count;
  tmuf_pack packs[TMUF_PACKLIST_MAX];
  uint32_t table_cap; /* power of two */
  tmuf_packset_entry *table;
} tmuf_packset;

typedef struct tmuf_pack_ref {
  int pack; /* -1 if not found */
  uint32_t file;
} tmuf_pack_ref;

/* Opens every pack listed in packlist.dat that exists in dir. */
int tmuf_packset_open(tmuf_packset *set, const char *dir, char *err, size_t err_size);
void tmuf_packset_close(tmuf_packset *set);

/* Stored path (as in the pack), case-insensitive. */
tmuf_pack_ref tmuf_packset_find_stored(const tmuf_packset *set, const char *path);
/* Plain path: stored as is, or with the file name hidden as the game does
   (length byte + MD5 of the lower-case path relative to a parent folder). */
tmuf_pack_ref tmuf_packset_find(const tmuf_packset *set, const char *plain_path);

/* External node of g, referenced from the file at stored path `from`.
   Hashed files hide their subfolders, so every possible depth is tried. */
/* The file an external reference points to outside the packs (textures and
   other media under the installation's GameData, beside Packs): its path on
   disk, the directories and name matched case-insensitively. 0 if there is
   none. */
int tmuf_packset_resolve_file(const tmuf_packset *set, const tmuf_gbx *g, const tmuf_gbx_node *node, const char *from,
                              char *out, size_t out_size);

tmuf_pack_ref tmuf_packset_resolve(const tmuf_packset *set, const tmuf_gbx *g, const tmuf_gbx_node *node,
                                   const char *from, char *plain_out, size_t plain_out_size);

void tmuf_hash_file_name(const char *relative, char out[35]);

#endif
