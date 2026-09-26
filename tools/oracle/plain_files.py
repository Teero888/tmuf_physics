#!/usr/bin/env python3
"""Split a `--trace plain` capture into the plain bytes of each pack file.

  plain_files.py PACKS_LS_DIR CAPTURE(.plain or .plain.gz) OUT_DIR

Writes OUT_DIR/<pack>/<path> (the GBX as the game parsed it: decrypted and,
for compressed files, inflated) and prints one line per file.
"""
import glob
import gzip
import os
import struct
import sys


def load_listings(directory):
    by_offset = {}
    for path in glob.glob(os.path.join(directory, "*.txt")):
        pack = os.path.basename(path)[:-4]
        for line in open(path):
            parts = line.split(None, 5)
            if len(parts) == 6:
                by_offset.setdefault(int(parts[4]), []).append((pack, parts[5].strip(), parts[1]))
    return by_offset


def main():
    by_offset = load_listings(sys.argv[1])
    opener = gzip.open if sys.argv[2].endswith(".gz") else open
    data = opener(sys.argv[2], "rb").read()
    out_dir = sys.argv[3]

    current = {}  # crypted stream -> [file, bytes]
    zlib_src = {}  # zlib buffer -> crypted stream
    zlib_data = {}  # zlib buffer -> [file, bytes]
    files = []
    pos = 0
    while pos + 17 <= len(data):
        kind = chr(data[pos])
        a, b, c, d = struct.unpack_from("<4I", data, pos + 1)
        pos += 17
        if kind == "I":
            cands = by_offset.get(c, [])
            f = cands[0] if len(cands) == 1 else None
            entry = [f, bytearray(), False]
            current[a] = entry
            files.append(entry)
        elif kind == "O":
            zlib_src[a] = b
            src = current.get(b)
            entry = [src[0] if src else None, bytearray(), True]
            zlib_data[a] = entry
            files.append(entry)
            if src:
                src[2] = True  # the crypted stream feeds a zlib buffer
        elif kind in "CZ":
            chunk = data[pos:pos + b]
            pos += b
            target = current.get(a) if kind == "C" else zlib_data.get(a)
            if target is not None:
                target[1] += chunk
        else:
            raise SystemExit(f"bad record {kind!r} at {pos - 17}")

    written = 0
    for f, content, is_zlib_or_fed in files:
        if f is None or not content:
            continue
        pack, path, flags = f
        compressed = "Z" in flags
        # For compressed files keep the inflated stream, else the crypted one.
        if compressed and not (is_zlib_or_fed and content[:3] == b"GBX"):
            continue
        dst = os.path.join(out_dir, pack, path.replace("\\", "/"))
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "wb") as o:
            o.write(content)
        written += 1
        print(f"{pack}\t{path}\t{len(content)}")
    print(f"# {written} files", file=sys.stderr)


if __name__ == "__main__":
    main()
