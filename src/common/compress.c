#include "common/compress.h"

#include <string.h>


#include "common/zlib/zlib.h"

/* ---- zlib (vendored 1.2.3 inflate) ---- */

int tmuf_zlib_uncompress(const uint8_t *in, size_t in_size, uint8_t *out, size_t out_size) {
  z_stream z;
  memset(&z, 0, sizeof z);
  if (in_size > 0xffffffffu || out_size > 0xffffffffu || inflateInit(&z) != Z_OK)
    return 0;
  z.next_in = (Bytef *)(uintptr_t)in;
  z.avail_in = (uInt)in_size;
  z.next_out = out;
  z.avail_out = (uInt)out_size;
  int status = inflate(&z, Z_FINISH);
  int ok = status == Z_STREAM_END && z.avail_out == 0 && z.avail_in == 0;
  inflateEnd(&z);
  return ok;
}

int tmuf_inflate_raw(const uint8_t *in, size_t in_size, uint8_t *out, size_t out_size) {
  z_stream z;
  memset(&z, 0, sizeof z);
  if (in_size > 0xffffffffu || out_size > 0xffffffffu || inflateInit2(&z, -MAX_WBITS) != Z_OK)
    return 0;
  z.next_in = (Bytef *)(uintptr_t)in;
  z.avail_in = (uInt)in_size;
  z.next_out = out;
  z.avail_out = (uInt)out_size;
  int status = inflate(&z, Z_FINISH);
  int ok = status == Z_STREAM_END && z.avail_out == 0;
  inflateEnd(&z);
  return ok;
}

/* ---- LZO1X ---- */

int tmuf_lzo1x_decompress(const uint8_t *in, size_t in_size, uint8_t *out, size_t out_size) {
  const uint8_t *ip = in, *ip_end = in + in_size;
  uint8_t *op = out, *op_end = out + out_size;
  size_t t;
  const uint8_t *m_pos;

#define NEED_IP(n) \
  if ((size_t)(ip_end - ip) < (size_t)(n)) \
    return 0
#define NEED_OP(n) \
  if ((size_t)(op_end - op) < (size_t)(n)) \
    return 0
#define CHECK_LB(p) \
  if ((p) < out || (p) >= op) \
    return 0

  NEED_IP(1);
  if (*ip > 17) {
    t = (size_t)(*ip++ - 17);
    if (t < 4)
      goto match_next;
    NEED_OP(t);
    NEED_IP(t + 1);
    do
      *op++ = *ip++;
    while (--t > 0);
    goto first_literal_run;
  }

  for (;;) {
    NEED_IP(3);
    t = *ip++;
    if (t >= 16)
      goto match;
    if (t == 0) {
      while (*ip == 0) {
        t += 255;
        ip++;
        NEED_IP(1);
      }
      t += (size_t)(15 + *ip++);
    }
    NEED_OP(t + 3);
    NEED_IP(t + 4);
    for (size_t i = 0; i < t + 3; i++)
      *op++ = *ip++;

  first_literal_run:
    t = *ip++;
    if (t >= 16)
      goto match;
    m_pos = op - (1 + 0x0800);
    m_pos -= t >> 2;
    m_pos -= (size_t)*ip++ << 2;
    CHECK_LB(m_pos);
    NEED_OP(3);
    *op++ = *m_pos++;
    *op++ = *m_pos++;
    *op++ = *m_pos;
    goto match_done;

    for (;;) {
    match:
      if (t >= 64) {
        m_pos = op - 1;
        m_pos -= (t >> 2) & 7;
        m_pos -= (size_t)*ip++ << 3;
        t = (t >> 5) - 1;
        CHECK_LB(m_pos);
        NEED_OP(t + 2);
        goto copy_match;
      } else if (t >= 32) {
        t &= 31;
        if (t == 0) {
          while (*ip == 0) {
            t += 255;
            ip++;
            NEED_IP(1);
          }
          t += (size_t)(31 + *ip++);
          NEED_IP(2);
        }
        m_pos = op - 1;
        m_pos -= (size_t)(ip[0] >> 2) + ((size_t)ip[1] << 6);
        ip += 2;
      } else if (t >= 16) {
        m_pos = op;
        m_pos -= (t & 8) << 11;
        t &= 7;
        if (t == 0) {
          while (*ip == 0) {
            t += 255;
            ip++;
            NEED_IP(1);
          }
          t += (size_t)(7 + *ip++);
          NEED_IP(2);
        }
        m_pos -= (size_t)(ip[0] >> 2) + ((size_t)ip[1] << 6);
        ip += 2;
        if (m_pos == op)
          goto eof_found;
        m_pos -= 0x4000;
      } else {
        m_pos = op - 1;
        m_pos -= t >> 2;
        m_pos -= (size_t)*ip++ << 2;
        CHECK_LB(m_pos);
        NEED_OP(2);
        *op++ = *m_pos++;
        *op++ = *m_pos;
        goto match_done;
      }
      CHECK_LB(m_pos);
      NEED_OP(t + 2);
    copy_match:
      *op++ = *m_pos++;
      *op++ = *m_pos++;
      do
        *op++ = *m_pos++;
      while (--t > 0);
    match_done:
      t = ip[-2] & 3;
      if (t == 0)
        break;
    match_next:
      NEED_OP(t);
      NEED_IP(t + 3);
      *op++ = *ip++;
      if (t > 1) {
        *op++ = *ip++;
        if (t > 2)
          *op++ = *ip++;
      }
      t = *ip++;
    }
  }

eof_found:
  return t == 1 && ip == ip_end && op == op_end;
#undef NEED_IP
#undef NEED_OP
#undef CHECK_LB
}
