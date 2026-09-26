#!/usr/bin/env python3
"""Build a symbol map for the TMUF exe from the PDB of TmForeverFixed.exe.

Both exes are 2.11.26 builds with nearly identical code. Each instruction is
normalised (absolute addresses and branch targets removed); every PDB
function start is then looked up by the hash of its first WINDOW normalised
instructions in the target. Unique hits are taken directly; functions with
several identical-looking candidates take the one nearest to where the
closest uniquely mapped function predicts it.

  symmap.py PDB_EXE PDB TARGET_EXE > tmuf_symbols.txt   ("0xADDR name" lines)
"""
import bisect
import hashlib
import re
import sys

import capstone
import pefile

sys.path.insert(0, __import__("os").path.dirname(__file__))
from sigmap import load_publics  # noqa: E402

WINDOW = 12
MAX_DRIFT = 0x400  # bytes a function may move relative to its nearest anchor
ADDR_RE = re.compile(r"0x[0-9a-f]{6,8}")


def normalise(ins, lo, hi):
    ops = ins.op_str
    m = ins.mnemonic
    if (m[0] == "j" or m == "call" or m.startswith("loop")) and ops.startswith("0x"):
        ops = "T"
    ops = ADDR_RE.sub(lambda m: "A" if lo <= int(m.group(0), 16) < hi else m.group(0), ops)
    return ins.mnemonic + " " + ops


def disassemble(path):
    pe = pefile.PE(path, fast_load=True)
    base = pe.OPTIONAL_HEADER.ImageBase
    lo, hi = base, base + pe.OPTIONAL_HEADER.SizeOfImage
    text = next(s for s in pe.sections if s.Name.rstrip(b"\0") == b".text")
    va0 = base + text.VirtualAddress
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.skipdata = True
    addrs, toks = [], []
    for ins in md.disasm(text.get_data(), va0):
        addrs.append(ins.address)
        toks.append(normalise(ins, lo, hi))
    return pe, addrs, toks


def window_hash(toks, i):
    return hashlib.blake2b("\n".join(toks[i:i + WINDOW]).encode(), digest_size=8).digest()


def main():
    src_pe, src_addrs, src_toks = disassemble(sys.argv[1])
    print(f"# source: {len(src_addrs)} instructions", file=sys.stderr)
    dst_pe, dst_addrs, dst_toks = disassemble(sys.argv[3])
    print(f"# target: {len(dst_addrs)} instructions", file=sys.stderr)

    index = {}
    for i in range(len(dst_toks) - WINDOW):
        lst = index.setdefault(window_hash(dst_toks, i), [])
        if len(lst) < 256:
            lst.append(i)

    src_pos = {a: i for i, a in enumerate(src_addrs)}
    base = src_pe.OPTIONAL_HEADER.ImageBase
    syms = load_publics(sys.argv[2])
    entries = []  # (source va, name, candidate target indices)
    for name, locs in syms.items():
        sec, off = locs[0]
        va = base + src_pe.sections[sec - 1].VirtualAddress + off
        i = src_pos.get(va)
        cands = index.get(window_hash(src_toks, i), []) if i is not None and i + WINDOW <= len(src_toks) else []
        entries.append((va, name, cands))
    entries.sort()

    # Pass 1: unique hits give (source, target) anchors. Pass 2: ambiguous
    # hits take the candidate closest to the position predicted by the
    # nearest anchor below; code layout drifts slowly between the builds.
    anchors = [(va, dst_addrs[c[0]]) for va, _, c in entries if len(c) == 1]
    anchor_src = [a[0] for a in anchors]
    out, unique, resolved, missing = [], 0, 0, 0
    for va, name, cands in entries:
        if len(cands) == 1:
            out.append((dst_addrs[cands[0]], name))
            unique += 1
            continue
        k = bisect.bisect_right(anchor_src, va) - 1
        if not cands or k < 0:
            missing += 1
            continue
        predicted = va + (anchors[k][1] - anchors[k][0])
        best = min(cands, key=lambda c: abs(dst_addrs[c] - predicted))
        if abs(dst_addrs[best] - predicted) <= MAX_DRIFT:
            out.append((dst_addrs[best], name))
            resolved += 1
        else:
            missing += 1
    out.sort()
    for addr, name in out:
        print(f"0x{addr:08x} {name}")
    print(f"# unique {unique}, resolved by position {resolved}, unmapped {missing}", file=sys.stderr)


if __name__ == "__main__":
    main()
