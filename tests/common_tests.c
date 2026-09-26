/* Known-answer tests for the primitives in src/common. */
#include <stdio.h>
#include <string.h>

#include "common/compress.h"
#include "common/crypto.h"
#include "zlib_vectors.h"

static int failures;

#define CHECK(cond) \
  do { \
    if (!(cond)) { \
      fprintf(stderr, "%s:%d: CHECK failed: %s\n", __FILE__, __LINE__, #cond); \
      failures++; \
    } \
  } while (0)

static void hex(const uint8_t *d, size_t n, char *out) {
  for (size_t i = 0; i < n; i++)
    sprintf(out + 2 * i, "%02x", d[i]);
}

static int md5_is(const char *text, const char *expected) {
  uint8_t d[16];
  char h[33];
  tmuf_md5_bytes(text, strlen(text), d);
  hex(d, 16, h);
  return strcmp(h, expected) == 0;
}

static void test_md5(void) {
  CHECK(md5_is("", "d41d8cd98f00b204e9800998ecf8427e"));
  CHECK(md5_is("abc", "900150983cd24fb0d6963f7d28e17f72"));
  CHECK(md5_is("The quick brown fox jumps over the lazy dog", "9e107d9d372bb6826bd81d3542a419d6"));
  CHECK(md5_is("12345678901234567890123456789012345678901234567890123456789012345678901234567890",
               "57edf4a22be3c955ac49da2e2107b67a"));

  /* Incremental updates across block boundaries. */
  tmuf_md5 ctx;
  uint8_t a[16], b[16];
  const char *msg = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
  tmuf_md5_init(&ctx);
  for (size_t i = 0; i < strlen(msg); i += 7)
    tmuf_md5_update(&ctx, msg + i, strlen(msg) - i < 7 ? strlen(msg) - i : 7);
  tmuf_md5_final(&ctx, a);
  tmuf_md5_bytes(msg, strlen(msg), b);
  CHECK(memcmp(a, b, 16) == 0);
}

static void test_hmac_md5(void) {
  uint8_t key[16], d[16];
  char h[33];
  memset(key, 0x0b, sizeof key);
  tmuf_hmac_md5(key, sizeof key, "Hi There", 8, d);
  hex(d, 16, h);
  CHECK(strcmp(h, "9294727a3638bb1c13f48ef8158bfc9d") == 0);
  tmuf_hmac_md5((const uint8_t *)"Jefe", 4, "what do ya want for nothing?", 28, d);
  hex(d, 16, h);
  CHECK(strcmp(h, "750c783e6ab0b503eaa86e310a5db738") == 0);
}

static void test_crc32(void) {
  CHECK(tmuf_crc32(0, "123456789", 9) == 0xcbf43926u);
  CHECK(tmuf_crc32(0, "", 0) == 0);
}

static void test_blowfish(void) {
  static const struct {
    uint8_t key[8];
    uint32_t pl, pr, cl, cr;
  } v[] = {
      {{0, 0, 0, 0, 0, 0, 0, 0}, 0x00000000, 0x00000000, 0x4ef99745, 0x6198dd78},
      {{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, 0xffffffff, 0xffffffff, 0x51866fd5, 0xb85ecb8a},
      {{0x30, 0, 0, 0, 0, 0, 0, 0}, 0x10000000, 0x00000001, 0x7d856f9a, 0x613063f2},
      {{0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef}, 0x11111111, 0x11111111, 0x61f9c380, 0x2281b096},
  };
  for (size_t i = 0; i < sizeof v / sizeof v[0]; i++) {
    tmuf_blowfish bf;
    tmuf_blowfish_init(&bf, v[i].key, 8);
    uint32_t l = v[i].pl, r = v[i].pr;
    tmuf_blowfish_encrypt(&bf, &l, &r);
    CHECK(l == v[i].cl && r == v[i].cr);
    tmuf_blowfish_decrypt(&bf, &l, &r);
    CHECK(l == v[i].pl && r == v[i].pr);
  }
}

static void check_zlib(const uint8_t *in, size_t in_size, const uint8_t *plain, size_t plain_size) {
  static uint8_t out[8192];
  CHECK(plain_size <= sizeof out);
  memset(out, 0, sizeof out);
  CHECK(tmuf_zlib_uncompress(in, in_size, out, plain_size));
  CHECK(memcmp(out, plain, plain_size) == 0);
  /* Wrong expected size and truncated input must fail. */
  CHECK(!tmuf_zlib_uncompress(in, in_size, out, plain_size - 1));
  CHECK(!tmuf_zlib_uncompress(in, in_size - 1, out, plain_size));
}

static void test_zlib(void) {
  check_zlib(ZLIB_STORED, sizeof ZLIB_STORED, ZLIB_PLAIN, sizeof ZLIB_PLAIN);
  check_zlib(ZLIB_FAST, sizeof ZLIB_FAST, ZLIB_PLAIN, sizeof ZLIB_PLAIN);
  check_zlib(ZLIB_BEST, sizeof ZLIB_BEST, ZLIB_PLAIN, sizeof ZLIB_PLAIN);
  check_zlib(ZLIB_SHORT, sizeof ZLIB_SHORT, ZLIB_SHORT_PLAIN, sizeof ZLIB_SHORT_PLAIN);
}

int main(void) {
  test_md5();
  test_hmac_md5();
  test_crc32();
  test_blowfish();
  test_zlib();
  if (failures)
    fprintf(stderr, "%d check(s) failed\n", failures);
  else
    printf("common tests passed\n");
  return failures != 0;
}
