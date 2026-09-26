#!/usr/bin/env python3
"""Resolve the streams of a feedback trace to pack files.

  trace_files.py PACKS_LS_DIR TRACE [TRACE...] > streams.jsonl

PACKS_LS_DIR holds one `tmuf_inspect ls` listing per pack (<pack>.txt). Each
output line is one crypted stream: pack, path, class id, flags and the
sequence of values the game mixed into it (hex u32, in order). Streams of
the same file are merged if their sequences agree.
"""
import glob
import json
import os
import sys


def load_listings(directory):
    by_offset = {}
    for path in glob.glob(os.path.join(directory, "*.txt")):
        pack = os.path.basename(path)[:-4]
        for line in open(path):
            parts = line.split(None, 5)
            if len(parts) < 6:
                continue
            class_id, flags, size, csize, offset, name = parts
            by_offset.setdefault(int(offset), []).append({
                "pack": pack, "path": name.strip(), "class": class_id, "flags": flags,
                "size": int(size), "csize": int(csize)})
    return by_offset


def main():
    by_offset = load_listings(sys.argv[1])
    files = {}
    unresolved = 0
    for trace in sys.argv[2:]:
        streams, order = {}, []
        for line in open(trace):
            p = line.split()
            if p[0] == "I":
                key = (p[1], len(order))
                streams[p[1]] = {"offset": int(p[3], 16), "size": int(p[4], 16), "mix": []}
                order.append(p[1])
                streams[p[1]]["_id"] = key
            elif p[0] == "F" and p[1] in streams:
                streams[p[1]]["mix"].append(p[3])
        # A stream object can be reused; re-split by I lines.
        seen = []
        cur = {}
        for line in open(trace):
            p = line.split()
            if p[0] == "I":
                s = {"offset": int(p[3], 16), "size": int(p[4], 16), "mix": []}
                cur[p[1]] = s
                seen.append(s)
            elif p[0] == "F" and p[1] in cur:
                cur[p[1]]["mix"].append(p[3])
        for s in seen:
            cands = by_offset.get(s["offset"], [])
            if len(cands) != 1:
                unresolved += 1
                continue
            f = cands[0]
            key = (f["pack"], f["path"])
            if key in files and files[key]["mix"] != s["mix"]:
                files[key].setdefault("conflicts", 0)
                files[key]["conflicts"] += 1
                continue
            files.setdefault(key, dict(f, mix=s["mix"]))
    for f in files.values():
        print(json.dumps(f))
    print(f"# {len(files)} files, {unresolved} unresolved streams", file=sys.stderr)


if __name__ == "__main__":
    main()
