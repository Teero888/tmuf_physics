#ifndef TMUF_COMMON_COMPRESS_H
#define TMUF_COMMON_COMPRESS_H

#include <stddef.h>
#include <stdint.h>

/* zlib stream (RFC 1950/1951) into a buffer of exactly out_size bytes.
   Returns 1 if the stream is valid, fills the buffer exactly, the Adler-32
   matches and all input is consumed. */
/* a raw deflate stream (zip entries) of exactly out_size bytes */
int tmuf_inflate_raw(const uint8_t *in, size_t in_size, uint8_t *out, size_t out_size);
int tmuf_zlib_uncompress(const uint8_t *in, size_t in_size, uint8_t *out, size_t out_size);

/* Raw LZO1X stream (GBX bodies). Same exactness rules as above. */
int tmuf_lzo1x_decompress(const uint8_t *in, size_t in_size, uint8_t *out, size_t out_size);

#endif
