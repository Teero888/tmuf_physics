#include "common/crypto.h"

#include <string.h>

#include "common/blowfish_tables.h"

/* ---- MD5 (RFC 1321) ---- */

static uint32_t rotl32(uint32_t v, unsigned n) { return (v << n) | (v >> (32u - n)); }

static const uint32_t MD5_K[64] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391,
};

static const uint8_t MD5_R[64] = {
    7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 5, 9,  14, 20, 5, 9,  14, 20, 5, 9,  14, 20, 5, 9,  14, 20,
    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21,
};

static void md5_block(uint32_t state[4], const uint8_t block[64]) {
  uint32_t m[16];
  for (int i = 0; i < 16; i++)
    m[i] = (uint32_t)block[i * 4] | (uint32_t)block[i * 4 + 1] << 8 | (uint32_t)block[i * 4 + 2] << 16 |
           (uint32_t)block[i * 4 + 3] << 24;
  uint32_t a = state[0], b = state[1], c = state[2], d = state[3];
  for (unsigned i = 0; i < 64; i++) {
    uint32_t f;
    unsigned g;
    if (i < 16) {
      f = (b & c) | (~b & d);
      g = i;
    } else if (i < 32) {
      f = (d & b) | (~d & c);
      g = (5 * i + 1) & 15;
    } else if (i < 48) {
      f = b ^ c ^ d;
      g = (3 * i + 5) & 15;
    } else {
      f = c ^ (b | ~d);
      g = (7 * i) & 15;
    }
    uint32_t t = d;
    d = c;
    c = b;
    b = b + rotl32(a + f + MD5_K[i] + m[g], MD5_R[i]);
    a = t;
  }
  state[0] += a;
  state[1] += b;
  state[2] += c;
  state[3] += d;
}

void tmuf_md5_init(tmuf_md5 *ctx) {
  ctx->state[0] = 0x67452301;
  ctx->state[1] = 0xefcdab89;
  ctx->state[2] = 0x98badcfe;
  ctx->state[3] = 0x10325476;
  ctx->length = 0;
  ctx->used = 0;
}

void tmuf_md5_update(tmuf_md5 *ctx, const void *data, size_t size) {
  const uint8_t *p = data;
  ctx->length += size;
  while (size > 0) {
    size_t n = 64 - ctx->used;
    if (n > size)
      n = size;
    memcpy(ctx->block + ctx->used, p, n);
    ctx->used += n;
    p += n;
    size -= n;
    if (ctx->used == 64) {
      md5_block(ctx->state, ctx->block);
      ctx->used = 0;
    }
  }
}

void tmuf_md5_final(tmuf_md5 *ctx, uint8_t digest[16]) {
  uint64_t bits = ctx->length * 8;
  static const uint8_t pad = 0x80;
  static const uint8_t zero[64];
  tmuf_md5_update(ctx, &pad, 1);
  size_t fill = ctx->used <= 56 ? 56 - ctx->used : 120 - ctx->used;
  tmuf_md5_update(ctx, zero, fill);
  uint8_t len[8];
  for (int i = 0; i < 8; i++)
    len[i] = (uint8_t)(bits >> (8 * i));
  tmuf_md5_update(ctx, len, 8);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      digest[i * 4 + j] = (uint8_t)(ctx->state[i] >> (8 * j));
}

void tmuf_md5_bytes(const void *data, size_t size, uint8_t digest[16]) {
  tmuf_md5 ctx;
  tmuf_md5_init(&ctx);
  tmuf_md5_update(&ctx, data, size);
  tmuf_md5_final(&ctx, digest);
}

void tmuf_hmac_md5(const uint8_t *key, size_t key_size, const void *data, size_t size, uint8_t digest[16]) {
  uint8_t k[64] = {0}, pad[64], inner[16];
  if (key_size > 64)
    tmuf_md5_bytes(key, key_size, k);
  else
    memcpy(k, key, key_size);
  tmuf_md5 ctx;
  for (int i = 0; i < 64; i++)
    pad[i] = k[i] ^ 0x36;
  tmuf_md5_init(&ctx);
  tmuf_md5_update(&ctx, pad, 64);
  tmuf_md5_update(&ctx, data, size);
  tmuf_md5_final(&ctx, inner);
  for (int i = 0; i < 64; i++)
    pad[i] = k[i] ^ 0x5c;
  tmuf_md5_init(&ctx);
  tmuf_md5_update(&ctx, pad, 64);
  tmuf_md5_update(&ctx, inner, 16);
  tmuf_md5_final(&ctx, digest);
}

/* ---- CRC-32 ---- */

uint32_t tmuf_crc32(uint32_t crc, const void *data, size_t size) {
  const uint8_t *p = data;
  crc = ~crc;
  while (size--) {
    crc ^= *p++;
    for (int i = 0; i < 8; i++)
      crc = (crc >> 1) ^ (0xedb88320u & (0u - (crc & 1u)));
  }
  return ~crc;
}

/* ---- Blowfish ---- */

static uint32_t bf_f(const tmuf_blowfish *bf, uint32_t x) {
  return ((bf->s[0][x >> 24] + bf->s[1][(x >> 16) & 0xff]) ^ bf->s[2][(x >> 8) & 0xff]) + bf->s[3][x & 0xff];
}

void tmuf_blowfish_encrypt(const tmuf_blowfish *bf, uint32_t *left, uint32_t *right) {
  uint32_t l = *left, r = *right;
  for (int i = 0; i < 16; i += 2) {
    l ^= bf->p[i];
    r ^= bf_f(bf, l);
    r ^= bf->p[i + 1];
    l ^= bf_f(bf, r);
  }
  l ^= bf->p[16];
  r ^= bf->p[17];
  *left = r;
  *right = l;
}

void tmuf_blowfish_decrypt(const tmuf_blowfish *bf, uint32_t *left, uint32_t *right) {
  uint32_t l = *left, r = *right;
  for (int i = 16; i > 0; i -= 2) {
    l ^= bf->p[i + 1];
    r ^= bf_f(bf, l);
    r ^= bf->p[i];
    l ^= bf_f(bf, r);
  }
  l ^= bf->p[1];
  r ^= bf->p[0];
  *left = r;
  *right = l;
}

void tmuf_blowfish_init(tmuf_blowfish *bf, const uint8_t *key, size_t key_size) {
  memcpy(bf->p, BLOWFISH_P_INIT, sizeof bf->p);
  memcpy(bf->s, BLOWFISH_S_INIT, sizeof bf->s);
  size_t k = 0;
  for (int i = 0; i < 18; i++) {
    uint32_t w = 0;
    for (int j = 0; j < 4; j++) {
      w = (w << 8) | key[k];
      k = (k + 1) % key_size;
    }
    bf->p[i] ^= w;
  }
  uint32_t l = 0, r = 0;
  for (int i = 0; i < 18; i += 2) {
    tmuf_blowfish_encrypt(bf, &l, &r);
    bf->p[i] = l;
    bf->p[i + 1] = r;
  }
  for (int b = 0; b < 4; b++)
    for (int i = 0; i < 256; i += 2) {
      tmuf_blowfish_encrypt(bf, &l, &r);
      bf->s[b][i] = l;
      bf->s[b][i + 1] = r;
    }
}
