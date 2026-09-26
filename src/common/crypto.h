#ifndef TMUF_COMMON_CRYPTO_H
#define TMUF_COMMON_CRYPTO_H

/* Primitives needed to read the game's packs: MD5, HMAC-MD5, CRC-32 (zlib
   polynomial) and Blowfish. Not constant-time; only used on game data. */

#include <stddef.h>
#include <stdint.h>

typedef struct tmuf_md5 {
  uint32_t state[4];
  uint64_t length;
  uint8_t block[64];
  size_t used;
} tmuf_md5;

void tmuf_md5_init(tmuf_md5 *ctx);
void tmuf_md5_update(tmuf_md5 *ctx, const void *data, size_t size);
void tmuf_md5_final(tmuf_md5 *ctx, uint8_t digest[16]);
void tmuf_md5_bytes(const void *data, size_t size, uint8_t digest[16]);
void tmuf_hmac_md5(const uint8_t *key, size_t key_size, const void *data, size_t size, uint8_t digest[16]);

uint32_t tmuf_crc32(uint32_t crc, const void *data, size_t size);

typedef struct tmuf_blowfish {
  uint32_t p[18];
  uint32_t s[4][256];
} tmuf_blowfish;

void tmuf_blowfish_init(tmuf_blowfish *bf, const uint8_t *key, size_t key_size);
void tmuf_blowfish_encrypt(const tmuf_blowfish *bf, uint32_t *left, uint32_t *right);
void tmuf_blowfish_decrypt(const tmuf_blowfish *bf, uint32_t *left, uint32_t *right);

#endif
