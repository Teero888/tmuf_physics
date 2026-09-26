# zlib 1.2.3 (inflate only)

Unmodified inflate sources from zlib 1.2.3 (zlib.net/fossils,
`zlib-1.2.3.tar.gz`, SHA-256
`1795c7d067a43174113fdf03447532f373e1c6c57c08d61d9e4e9be5e244b05e`), the
version linked into TmForever 2.11.26. Decrypting compressed pack files
depends on exactly when inflate consumes input, so this version is kept.

The only change: `zconf.h` includes `tmuf_zprefix.h`, which renames all
external symbols to `tmuf_z_*`.

zlib is (C) 1995-2005 Jean-loup Gailly and Mark Adler, under the zlib
license (see `zlib.h`).
