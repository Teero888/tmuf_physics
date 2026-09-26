#ifndef TMUF_COMMON_PACK_H
#define TMUF_COMMON_PACK_H

/* Game packs: packlist.dat (per-pack keys) and NadeoPak v3 .pak files. */

#include <stddef.h>
#include <stdint.h>

#include "common/crypto.h"

#define TMUF_PACKLIST_MAX 64

typedef struct tmuf_packlist_entry {
  char name[32]; /* lower case, without .pak */
  char key[33];  /* 32 hex characters */
  uint8_t flags;
} tmuf_packlist_entry;

typedef struct tmuf_packlist {
  uint32_t seed;
  int count;
  tmuf_packlist_entry entries[TMUF_PACKLIST_MAX];
} tmuf_packlist;

/* product may be "" (entries that need a product name then fail to load). */
int tmuf_packlist_parse(const uint8_t *data, size_t size, const char *product, tmuf_packlist *out);
const tmuf_packlist_entry *tmuf_packlist_find(const tmuf_packlist *list, const char *pack_name);

/*
 * Blowfish-CBC reader with the game's page feedback: every 256 plain bytes,
 * before the next block is decrypted, a 64-bit value accumulated from
 * tmuf_crypt_mix() calls is XORed into the IV. The archive parser decides
 * which values to mix, which couples decryption to parsing.
 */
typedef struct tmuf_crypt {
  const tmuf_blowfish *bf;
  const uint8_t *src;
  size_t src_size;
  size_t src_pos;
  size_t logical, size;
  uint8_t iv[8];
  uint8_t plain[8];
  unsigned plain_pos;
  size_t page_pos;
  uint32_t fb_low, fb_high;
  int error;
} tmuf_crypt;

/* Ciphertext starts at src + cipher_offset; the IV is the 8 bytes before. */
int tmuf_crypt_init(tmuf_crypt *c, const tmuf_blowfish *bf, const uint8_t *src, size_t src_size, size_t cipher_offset);
int tmuf_crypt_read(tmuf_crypt *c, void *out, size_t n);
void tmuf_crypt_mix(tmuf_crypt *c, const uint8_t *bytes, size_t n);
void tmuf_crypt_mix_u32(tmuf_crypt *c, uint32_t v);

typedef struct tmuf_pack_folder {
  uint32_t parent; /* 0xffffffff for root */
  char *name;
} tmuf_pack_folder;

typedef struct tmuf_pack_file {
  uint32_t folder;
  char *name;
  uint32_t uncompressed_size;
  uint32_t compressed_size;
  uint32_t offset; /* relative to data_start */
  uint32_t class_id;
  uint64_t flags;
} tmuf_pack_file;

#define TMUF_PACK_FLAG_COMPRESSION 0x3cull
#define TMUF_PACK_FLAG_PUBLIC 0x2000000000000ull
#define TMUF_PACK_FLAG_NO_CRYPT 0x4000000000000ull

typedef struct tmuf_pack {
  char name[32];
  uint8_t *data; /* owned */
  size_t size;
  tmuf_blowfish bf;
  uint32_t data_start;
  uint32_t folder_count, file_count;
  tmuf_pack_folder *folders;
  tmuf_pack_file *files;
} tmuf_pack;

/* Takes ownership of data (malloc'd) on success and on failure. */
int tmuf_pack_open(tmuf_pack *pack, uint8_t *data, size_t size, const tmuf_packlist *list, const char *pack_name);
void tmuf_pack_close(tmuf_pack *pack);

int tmuf_pack_file_path(const tmuf_pack *pack, uint32_t index, char *out, size_t out_size);
/* Index of the file with this full path (folders joined as stored), or -1. */
long tmuf_pack_find(const tmuf_pack *pack, const char *path);

static inline int tmuf_pack_file_encrypted(const tmuf_pack_file *f) {
  return !(f->flags & (TMUF_PACK_FLAG_PUBLIC | TMUF_PACK_FLAG_NO_CRYPT));
}
static inline int tmuf_pack_file_compressed(const tmuf_pack_file *f) { return (f->flags & TMUF_PACK_FLAG_COMPRESSION) != 0; }

/* Decrypt and inflate a file without archive feedback. Works for every file
   whose content does not depend on parser feedback. *out is malloc'd. */
int tmuf_pack_extract(const tmuf_pack *pack, uint32_t index, uint8_t **out, size_t *out_size);

#endif
