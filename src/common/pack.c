#include "common/pack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/compress.h"
#include "common/gbx.h"
#include "common/zlib/zlib.h"

#define PACKLIST_HEADER 10u
#define PACKLIST_SIGNATURE 16u
#define PACKLIST_KEY 32u
#define PACKLIST_MAX_NAME 31u

static const char PACKLIST_NAME_SALT[] = "6611992868945B0B59536FC3226F3FD0";
static const char PACKLIST_SIGNATURE_SALT[] = "E3554B5828AF14F11AA42A5EAF0AEFC8";
static const char PACK_KEY_SALT_EVEN[] = "B97C1205648A66E04F86A1B5D5AF9862";
static const char PACK_KEY_SALT_ODD[] = "1FCF6EFCF41CAAAD0B810C656DF2DE33";

static uint32_t rd32(const uint8_t *p) { return (uint32_t)p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24; }

static char lower(char c) { return c >= 'A' && c <= 'Z' ? (char)(c - 'A' + 'a') : c; }

static int is_name_char(uint8_t c) { return c >= 0x21 && c <= 0x7e && c != '/' && c != '\\'; }

static int is_hex_char(uint8_t c) { return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'); }

static void md5_concat(const char *a, const char *b, const char *c, const char *d, uint8_t digest[16]) {
  tmuf_md5 ctx;
  tmuf_md5_init(&ctx);
  tmuf_md5_update(&ctx, a, strlen(a));
  tmuf_md5_update(&ctx, b, strlen(b));
  if (c)
    tmuf_md5_update(&ctx, c, strlen(c));
  if (d)
    tmuf_md5_update(&ctx, d, strlen(d));
  tmuf_md5_final(&ctx, digest);
}

int tmuf_packlist_parse(const uint8_t *data, size_t size, const char *product, tmuf_packlist *out) {
  memset(out, 0, sizeof *out);
  if (!data || size < PACKLIST_HEADER + PACKLIST_SIGNATURE || data[0] != 1)
    return 0;
  unsigned count = data[1];
  uint32_t product_crc = rd32(data + 2);
  uint32_t seed = rd32(data + 6);
  char seed_text[16];
  snprintf(seed_text, sizeof seed_text, "%u", seed);

  char prod[24];
  size_t plen = strlen(product ? product : "");
  if (count == 0 || count > TMUF_PACKLIST_MAX || plen > 23)
    return 0;
  for (size_t i = 0; i < plen; i++)
    prod[i] = lower(product[i]);
  prod[plen] = 0;

  uint8_t sig_key[16], sig[16];
  md5_concat(PACKLIST_SIGNATURE_SALT, seed_text, NULL, NULL, sig_key);
  tmuf_hmac_md5(sig_key, 16, data, size - PACKLIST_SIGNATURE, sig);
  if (memcmp(sig, data + size - PACKLIST_SIGNATURE, 16) != 0)
    return 0;
  int product_matches = product_crc == tmuf_crc32(0, prod, plen);

  uint8_t name_digest[16];
  md5_concat(PACKLIST_NAME_SALT, seed_text, NULL, NULL, name_digest);

  size_t end = size - PACKLIST_SIGNATURE, pos = PACKLIST_HEADER;
  for (unsigned e = 0; e < count; e++) {
    tmuf_packlist_entry *entry = &out->entries[e];
    if (end - pos < 2)
      return 0;
    entry->flags = data[pos];
    size_t name_len = data[pos + 1];
    if (name_len == 0 || name_len > PACKLIST_MAX_NAME || end - pos < 2 + name_len + PACKLIST_KEY)
      return 0;
    for (size_t i = 0; i < name_len; i++) {
      uint8_t c = data[pos + 2 + i] ^ name_digest[i & 15];
      if (!is_name_char(c))
        return 0;
      entry->name[i] = lower((char)c);
    }
    uint8_t key_digest[16];
    if (entry->flags & 1) {
      if (!product_matches)
        return 0;
      md5_concat(entry->name, seed_text, PACK_KEY_SALT_ODD, prod, key_digest);
    } else {
      md5_concat(entry->name, seed_text, PACK_KEY_SALT_EVEN, NULL, key_digest);
    }
    const uint8_t *enc = data + pos + 2 + name_len;
    for (size_t i = 0; i < PACKLIST_KEY; i++) {
      uint8_t c = enc[i] ^ key_digest[i & 15];
      if (!is_hex_char(c))
        return 0;
      entry->key[i] = (char)c;
    }
    for (unsigned j = 0; j < e; j++)
      if (strcmp(out->entries[j].name, entry->name) == 0)
        return 0;
    pos += 2 + name_len + PACKLIST_KEY;
  }
  if (pos != end)
    return 0;
  out->seed = seed;
  out->count = (int)count;
  return 1;
}

const tmuf_packlist_entry *tmuf_packlist_find(const tmuf_packlist *list, const char *pack_name) {
  char name[40];
  size_t n = strlen(pack_name);
  if (n == 0 || n >= sizeof name)
    return NULL;
  for (size_t i = 0; i <= n; i++)
    name[i] = lower(pack_name[i]);
  if (n > 4 && strcmp(name + n - 4, ".pak") == 0)
    name[n - 4] = 0;
  for (int i = 0; i < list->count; i++)
    if (strcmp(list->entries[i].name, name) == 0)
      return &list->entries[i];
  return NULL;
}

/* ---- crypted stream ---- */

#define CRYPT_PAGE 0x100u

int tmuf_crypt_init(tmuf_crypt *c, const tmuf_blowfish *bf, const uint8_t *src, size_t src_size, size_t cipher_offset) {
  memset(c, 0, sizeof *c);
  if (cipher_offset < 8 || cipher_offset > src_size)
    return 0;
  c->bf = bf;
  c->src = src;
  c->src_size = src_size;
  memcpy(c->iv, src + cipher_offset - 8, 8);
  c->src_pos = cipher_offset;
  c->size = src_size - cipher_offset;
  c->plain_pos = 8;
  c->page_pos = CRYPT_PAGE;
  return 1;
}

static int crypt_next_block(tmuf_crypt *c) {
  if (c->page_pos >= CRYPT_PAGE) {
    uint32_t words[2] = {c->fb_low, c->fb_high};
    for (int i = 0; i < 8; i++)
      c->iv[i] ^= (uint8_t)(words[i >> 2] >> (8 * (i & 3)));
    c->fb_low = c->fb_high = 0;
    c->page_pos = 0;
  }
  if (c->src_size - c->src_pos < 8)
    return 0;
  const uint8_t *cipher = c->src + c->src_pos;
  uint32_t l = rd32(cipher), r = rd32(cipher + 4);
  tmuf_blowfish_decrypt(c->bf, &l, &r);
  for (int i = 0; i < 4; i++) {
    c->plain[i] = (uint8_t)(l >> (8 * i)) ^ c->iv[i];
    c->plain[4 + i] = (uint8_t)(r >> (8 * i)) ^ c->iv[4 + i];
  }
  memcpy(c->iv, cipher, 8);
  c->src_pos += 8;
  c->plain_pos = 0;
  return 1;
}

int tmuf_crypt_read(tmuf_crypt *c, void *out, size_t n) {
  uint8_t *o = out;
  if (c->error || n > c->size - (c->logical < c->size ? c->logical : c->size)) {
    c->error = 1;
    return 0;
  }
  while (n > 0) {
    if (c->plain_pos == 8 && !crypt_next_block(c)) {
      c->error = 1;
      return 0;
    }
    size_t k = 8 - c->plain_pos;
    if (k > n)
      k = n;
    memcpy(o, c->plain + c->plain_pos, k);
    c->plain_pos += (unsigned)k;
    c->page_pos += k;
    c->logical += k;
    o += k;
    n -= k;
  }
  return 1;
}

void tmuf_crypt_mix(tmuf_crypt *c, const uint8_t *bytes, size_t n) {
  for (size_t i = 0; i < n; i++) {
    uint32_t low = c->fb_low, high = c->fb_high;
    uint32_t mixed = (uint32_t)bytes[i] | 0xaau;
    c->fb_low = mixed ^ (low << 13) ^ (high >> 19);
    c->fb_high = (low >> 19) | (high << 13);
  }
}

void tmuf_crypt_mix_u32(tmuf_crypt *c, uint32_t v) {
  uint8_t b[4] = {(uint8_t)v, (uint8_t)(v >> 8), (uint8_t)(v >> 16), (uint8_t)(v >> 24)};
  tmuf_crypt_mix(c, b, 4);
}

/* ---- pack ---- */

typedef struct header_reader {
  tmuf_crypt crypt;
  uint8_t *plain; /* copy of every header byte read, for the MD5 check */
  size_t plain_size, plain_cap;
} header_reader;

static int hr_read(header_reader *h, void *out, size_t n) {
  if (!tmuf_crypt_read(&h->crypt, out, n))
    return 0;
  if (h->plain_size + n > h->plain_cap) {
    size_t cap = h->plain_cap ? h->plain_cap * 2 : 4096;
    while (cap < h->plain_size + n)
      cap *= 2;
    uint8_t *p = realloc(h->plain, cap);
    if (!p)
      return 0;
    h->plain = p;
    h->plain_cap = cap;
  }
  memcpy(h->plain + h->plain_size, out, n);
  h->plain_size += n;
  return 1;
}

static int hr_u32(header_reader *h, uint32_t *v) {
  uint8_t b[4];
  if (!hr_read(h, b, 4))
    return 0;
  *v = rd32(b);
  return 1;
}

static int hr_string(header_reader *h, char **out) {
  uint32_t n;
  if (!hr_u32(h, &n) || n > 0xffff)
    return 0;
  char *s = malloc(n + 1);
  if (!s)
    return 0;
  if (n && !hr_read(h, s, n)) {
    free(s);
    return 0;
  }
  s[n] = 0;
  *out = s;
  return 1;
}

void tmuf_pack_close(tmuf_pack *pack) {
  for (uint32_t i = 0; i < pack->folder_count; i++)
    free(pack->folders[i].name);
  for (uint32_t i = 0; i < pack->file_count; i++)
    free(pack->files[i].name);
  free(pack->folders);
  free(pack->files);
  free(pack->data);
  memset(pack, 0, sizeof *pack);
}

static int pack_load_headers(tmuf_pack *pack) {
  header_reader h = {0};
  int ok = 0;
  uint8_t skip16[16];
  uint32_t skip, folder_count = 0, file_count = 0;
  if (!tmuf_crypt_init(&h.crypt, &pack->bf, pack->data, pack->size, 20))
    goto done;
  if (!hr_read(&h, skip16, 16) || !hr_u32(&h, &skip) || !hr_u32(&h, &pack->data_start) || !hr_u32(&h, &skip) ||
      !hr_u32(&h, &skip) || !hr_read(&h, skip16, 16) || !hr_u32(&h, &skip) || !hr_u32(&h, &folder_count) ||
      folder_count > 4096)
    goto done;
  pack->folders = calloc(folder_count ? folder_count : 1, sizeof *pack->folders);
  if (!pack->folders)
    goto done;
  pack->folder_count = folder_count;
  for (uint32_t i = 0; i < folder_count; i++) {
    tmuf_pack_folder *f = &pack->folders[i];
    if (!hr_u32(&h, &f->parent) || !hr_string(&h, &f->name))
      goto done;
    if (f->parent != 0xffffffffu && (f->parent >= folder_count || f->parent == i))
      goto done;
  }
  /* The game mixes four characters of the third folder name, as UTF-16. */
  if (folder_count > 2 && strlen(pack->folders[2].name) > 4) {
    uint8_t utf16[8] = {0};
    for (int i = 0; i < 4; i++)
      utf16[i * 2] = (uint8_t)pack->folders[2].name[i + 2];
    tmuf_crypt_mix(&h.crypt, utf16, 4);
  }
  if (!hr_u32(&h, &file_count) || file_count > 200000)
    goto done;
  pack->files = calloc(file_count ? file_count : 1, sizeof *pack->files);
  if (!pack->files)
    goto done;
  pack->file_count = file_count;
  for (uint32_t i = 0; i < file_count; i++) {
    tmuf_pack_file *f = &pack->files[i];
    uint8_t flags[8];
    if (!hr_u32(&h, &f->folder) || !hr_string(&h, &f->name) || !hr_u32(&h, &skip) ||
        !hr_u32(&h, &f->uncompressed_size) || !hr_u32(&h, &f->compressed_size) || !hr_u32(&h, &f->offset) ||
        !hr_u32(&h, &f->class_id) || !hr_read(&h, flags, 8))
      goto done;
    f->flags = (uint64_t)rd32(flags) | (uint64_t)rd32(flags + 4) << 32;
    if (f->folder != 0xffffffffu && f->folder >= folder_count)
      goto done;
  }
  if (pack->data_start > pack->size || pack->data_start < 20 || h.plain_size > pack->data_start - 20u ||
      h.plain_size < 16)
    goto done;
  /* The first 16 plain bytes are the MD5 of the header with them zeroed. */
  uint8_t expected[16], computed[16];
  memcpy(expected, h.plain, 16);
  memset(h.plain, 0, 16);
  tmuf_md5_bytes(h.plain, h.plain_size, computed);
  ok = memcmp(expected, computed, 16) == 0;
done:
  free(h.plain);
  return ok;
}

int tmuf_pack_open(tmuf_pack *pack, uint8_t *data, size_t size, const tmuf_packlist *list, const char *pack_name) {
  memset(pack, 0, sizeof *pack);
  pack->data = data;
  pack->size = size;
  const tmuf_packlist_entry *entry = tmuf_packlist_find(list, pack_name);
  if (!data || size < 20 || memcmp(data, "NadeoPak", 8) != 0 || rd32(data + 8) != 3 || !entry) {
    tmuf_pack_close(pack);
    return 0;
  }
  char seed[64];
  uint8_t digest[16], key[16];
  snprintf(seed, sizeof seed, "%sNadeoPak", entry->key);
  tmuf_md5_bytes(seed, strlen(seed), digest);
  /* The key is stored as four big-endian words, fed to Blowfish as bytes of
     the little-endian words. */
  for (int w = 0; w < 4; w++)
    for (int b = 0; b < 4; b++)
      key[w * 4 + b] = digest[w * 4 + 3 - b];
  tmuf_blowfish_init(&pack->bf, key, 16);
  snprintf(pack->name, sizeof pack->name, "%s", entry->name);
  if (!pack_load_headers(pack)) {
    tmuf_pack_close(pack);
    return 0;
  }
  return 1;
}

static int folder_path(const tmuf_pack *pack, uint32_t folder, char *out, size_t out_size, unsigned depth) {
  if (folder == 0xffffffffu)
    return 1;
  if (folder >= pack->folder_count || depth > pack->folder_count)
    return 0;
  if (!folder_path(pack, pack->folders[folder].parent, out, out_size, depth + 1))
    return 0;
  size_t len = strlen(out), add = strlen(pack->folders[folder].name);
  if (len + add >= out_size)
    return 0;
  memcpy(out + len, pack->folders[folder].name, add + 1);
  return 1;
}

int tmuf_pack_file_path(const tmuf_pack *pack, uint32_t index, char *out, size_t out_size) {
  if (index >= pack->file_count || out_size == 0)
    return 0;
  out[0] = 0;
  const tmuf_pack_file *f = &pack->files[index];
  if (!folder_path(pack, f->folder, out, out_size, 0))
    return 0;
  size_t len = strlen(out), add = strlen(f->name);
  if (len + add >= out_size)
    return 0;
  memcpy(out + len, f->name, add + 1);
  return 1;
}

long tmuf_pack_find(const tmuf_pack *pack, const char *path) {
  char buf[512];
  for (uint32_t i = 0; i < pack->file_count; i++)
    if (tmuf_pack_file_path(pack, i, buf, sizeof buf) && strcmp(buf, path) == 0)
      return (long)i;
  return -1;
}

int tmuf_pack_extract(const tmuf_pack *pack, uint32_t index, uint8_t **out, size_t *out_size) {
  *out = NULL;
  *out_size = 0;
  if (index >= pack->file_count)
    return 0;
  const tmuf_pack_file *f = &pack->files[index];
  uint32_t packed = tmuf_pack_file_compressed(f) ? f->compressed_size : f->uncompressed_size;
  size_t offset = (size_t)pack->data_start + f->offset;
  if (offset > pack->size || packed > pack->size - offset)
    return 0;
  uint8_t *payload = malloc(packed ? packed : 1);
  if (!payload)
    return 0;
  if (tmuf_pack_file_encrypted(f)) {
    size_t enc = ((size_t)packed + 7u) & ~(size_t)7u;
    tmuf_crypt c;
    if (8 + enc > pack->size - offset || !tmuf_crypt_init(&c, &pack->bf, pack->data + offset, 8 + enc, 8) ||
        !tmuf_crypt_read(&c, payload, packed)) {
      free(payload);
      return 0;
    }
  } else {
    memcpy(payload, pack->data + offset, packed);
  }
  if (!tmuf_pack_file_compressed(f)) {
    *out = payload;
    *out_size = packed;
    return 1;
  }
  uint8_t *plain = malloc(f->uncompressed_size ? f->uncompressed_size : 1);
  int ok = plain && tmuf_zlib_uncompress(payload, packed, plain, f->uncompressed_size);
  free(payload);
  if (!ok) {
    free(plain);
    return 0;
  }
  *out = plain;
  *out_size = f->uncompressed_size;
  return 1;
}

/* ---- pack stream (the game's crypted + zlib buffer stack) ---- */

static int payload_read(tmuf_pack_stream *s, void *out, size_t n) {
  if (s->encrypted)
    return tmuf_crypt_read(&s->crypt, out, n);
  if (n > s->plain_size - s->plain_pos)
    return 0;
  memcpy(out, s->plain + s->plain_pos, n);
  s->plain_pos += n;
  return 1;
}

/* CClassicBufferZlib read loop (TMUF 0x910a60). */
static int zlib_layer_read(tmuf_pack_stream *s, uint8_t *out, size_t n) {
  z_stream *z = s->z;
  while (n > 0) {
    if (s->out_consumed >= s->out_produced) {
      if (s->z_eof)
        return 0;
      z->next_out = s->out;
      z->avail_out = sizeof s->out;
      s->out_consumed = 0;
      while (z->avail_out > 0) {
        if (z->avail_in == 0) {
          if (s->packed_left == 0) {
            s->z_eof = 1;
            break;
          }
          size_t k = s->packed_left < sizeof s->in ? s->packed_left : sizeof s->in;
          if (!payload_read(s, s->in, k)) {
            s->z_error = s->z_eof = 1;
            break;
          }
          s->packed_left -= k;
          z->next_in = s->in;
          z->avail_in = (uInt)k;
        }
        int r = inflate(z, Z_SYNC_FLUSH);
        if (r != Z_OK) {
          s->z_eof = 1;
          s->z_error = r != Z_STREAM_END;
          break;
        }
      }
      s->out_produced = sizeof s->out - z->avail_out;
      if (s->z_error || s->out_produced == 0)
        return 0;
    }
    size_t k = s->out_produced - s->out_consumed;
    if (k > n)
      k = n;
    memcpy(out, s->out + s->out_consumed, k);
    s->out_consumed += k;
    out += k;
    n -= k;
  }
  return 1;
}

static int pack_stream_read(tmuf_source *src, void *out, size_t n) {
  tmuf_pack_stream *s = (tmuf_pack_stream *)src;
  return s->compressed ? zlib_layer_read(s, out, n) : payload_read(s, out, n);
}

static void pack_stream_mix(tmuf_source *src, const uint8_t *bytes, size_t n) {
  tmuf_pack_stream *s = (tmuf_pack_stream *)src;
  if (s->encrypted)
    tmuf_crypt_mix(&s->crypt, bytes, n);
}

int tmuf_pack_stream_open(tmuf_pack_stream *s, const tmuf_pack *pack, uint32_t index) {
  memset(s, 0, sizeof *s);
  if (index >= pack->file_count)
    return 0;
  const tmuf_pack_file *f = &pack->files[index];
  s->base.read = pack_stream_read;
  s->base.mix = pack_stream_mix;
  s->encrypted = tmuf_pack_file_encrypted(f);
  s->compressed = tmuf_pack_file_compressed(f);
  uint32_t packed = s->compressed ? f->compressed_size : f->uncompressed_size;
  size_t offset = (size_t)pack->data_start + f->offset;
  if (offset > pack->size || packed > pack->size - offset)
    return 0;
  if (s->encrypted) {
    size_t enc = ((size_t)packed + 7u) & ~(size_t)7u;
    if (8 + enc > pack->size - offset || !tmuf_crypt_init(&s->crypt, &pack->bf, pack->data + offset, 8 + enc, 8))
      return 0;
  } else {
    s->plain = pack->data + offset;
    s->plain_size = packed;
  }
  s->packed_left = packed;
  if (s->compressed) {
    z_stream *z = calloc(1, sizeof *z);
    if (!z || inflateInit(z) != Z_OK) {
      free(z);
      return 0;
    }
    s->z = z;
  }
  return 1;
}

void tmuf_pack_stream_close(tmuf_pack_stream *s) {
  if (s->z) {
    inflateEnd(s->z);
    free(s->z);
  }
  s->z = NULL;
}
