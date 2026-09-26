# Pack format and stream feedback

Findings from TmForever.exe 2.11.26 (TMUF, SHA-256 `4b6a7b31…d2d4`) and the PDB
of TmForeverFixed.exe. Addresses are TMUF unless marked PDB.

## packlist.dat

- `u8 version (1)`, `u8 count`, `u32 product_crc`, `u32 seed`, entries,
  16-byte HMAC-MD5 signature over everything before it.
- Signature key: `MD5("E3554B5828AF14F11AA42A5EAF0AEFC8" + seed)`.
- Entry: `u8 flags`, `u8 name_len`, name XOR `MD5("6611992868945B0B59536FC3226F3FD0" + seed)`,
  32-byte key XOR `MD5(name + seed + salt [+ product])`, salt
  `B97C1205648A66E04F86A1B5D5AF9862` (flags even) or
  `1FCF6EFCF41CAAAD0B810C656DF2DE33` + lower-case product (flags odd).
- Seeds are the decimal text of the u32.

## .pak (NadeoPak v3)

- `"NadeoPak"`, `u32 3`, 8-byte IV, then Blowfish-CBC.
- Blowfish key: `MD5(key_hex + "NadeoPak")` as four big-endian words, fed to
  Blowfish as the bytes of the little-endian words. Blocks are also read as
  little-endian words.
- Header (encrypted): 16-byte MD5, u32, `u32 data_start`, u32, u32, 16 bytes,
  u32, `u32 folder_count`, folders `(u32 parent, string)`, then four characters
  of folder 2's name (offset 2) are mixed as UTF-16 (see feedback), `u32
  file_count`, files `(u32 folder, string, u32, u32 size, u32 csize, u32
  offset, u32 class_id, u64 flags)`. The MD5 covers all header bytes read,
  with the MD5 field zeroed.
- Strings: `u32 length` + bytes.
- File flags: `0x3c` compressed (zlib), `0x2000000000000` public,
  `0x4000000000000` no-crypt; other files are encrypted. An encrypted file
  starts at `data_start + offset` with its own 8-byte IV.

## Stream feedback

`CClassicBufferCrypted` (0x9112c0 `Blowfish_InitForReading`, 0x9113a0
`BlowfishCBC_Read`, 0x911490 `BlowfishCBC_Write`) decrypts whole 256-byte
pages. Before each page it XORs a 64-bit feedback value into the IV and
clears it. Object fields: IV at +0x38, feedback at +0x40/+0x44, page buffer
at +0x50, page position at +0x150.

`Write` on a stream whose `+8` flag is set does not write: every byte `b`
updates the feedback as `fb = rotl64(fb, 13) ^ (b | 0xaa)` (low word gets the
XOR). `CMwNod::Archive` (0x924130) sets that flag on the archive's buffer
around one call: at the start of every node it writes
`UnWrapClassId(parent_class_id)` (with `0x07031000` replaced by
`0x07001000`), only if the class has a parent. Nothing else is mixed while
reading nodes, so decrypting needs the exact byte offset of every node start.

- `UnWrapClassId` (0x936660, PDB `CMwDeprecated::UnWrapClassId`): table in
  `src/common/class_id_table.h`.
- Class hierarchy: `src/common/class_tree.h`, from the `CMwClassInfo`
  initializers.

### Compressed and encrypted files

`CClassicBufferZlib` (0x9109c0 `OpenForReading`, 0x910a60 read loop) sits on
top of the crypted stream. Its input buffer is 0x100 bytes and its output
buffer 0x400 bytes. When the output buffer is drained it refills it with
`inflate(Z_SYNC_FLUSH)` (zlib 1.2.3), reading `min(remaining, 0x100)`
compressed bytes whenever `avail_in == 0`. `Write` passes through to the
crypted stream, so node feedback lands on the compressed page after the one
the inflater is currently consuming. Matching this needs zlib 1.2.3's exact
input consumption.

## Oracle traces

`tools/oracle` with `--trace feedback` logs every mixed value per stream
(`I` = stream start, `F stream caller bytes chain…`). Our parser must produce
the same sequence for the same file.
