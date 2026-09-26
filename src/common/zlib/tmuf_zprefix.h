/* Renames every external symbol of the vendored zlib 1.2.3 inflate so it can
   be linked next to another zlib (frametee links one). Included first by
   zconf.h. */
#ifndef TMUF_ZPREFIX_H
#define TMUF_ZPREFIX_H

#define adler32 tmuf_z_adler32
#define adler32_combine tmuf_z_adler32_combine
#define inflate tmuf_z_inflate
#define inflateCopy tmuf_z_inflateCopy
#define inflateEnd tmuf_z_inflateEnd
#define inflateGetHeader tmuf_z_inflateGetHeader
#define inflateInit_ tmuf_z_inflateInit_
#define inflateInit2_ tmuf_z_inflateInit2_
#define inflatePrime tmuf_z_inflatePrime
#define inflateReset tmuf_z_inflateReset
#define inflateSetDictionary tmuf_z_inflateSetDictionary
#define inflateSync tmuf_z_inflateSync
#define inflateSyncPoint tmuf_z_inflateSyncPoint
#define inflate_copyright tmuf_z_inflate_copyright
#define inflate_fast tmuf_z_inflate_fast
#define inflate_table tmuf_z_inflate_table
#define zcalloc tmuf_z_zcalloc
#define zcfree tmuf_z_zcfree
#define zError tmuf_z_zError
#define z_errmsg tmuf_z_z_errmsg
#define zlibCompileFlags tmuf_z_zlibCompileFlags
#define zlibVersion tmuf_z_zlibVersion
#define zmemcmp tmuf_z_zmemcmp
#define zmemcpy tmuf_z_zmemcpy
#define zmemzero tmuf_z_zmemzero

#endif
