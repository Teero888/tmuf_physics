#!/usr/bin/env python3
"""Map functions from the PDB-matched exe to another TmForever build.

TmForeverFixed.exe (2.11.26, 2011) has a PDB; the TMUF exe we run as the
oracle (2.11.26, 2010) does not. The code is nearly identical, so each
function is located by searching for its first bytes with relocated absolute
addresses and relative branch targets masked out.

  sigmap.py PDB_EXE PDB TARGET_EXE NAME [NAME...]   -> "NAME 0xVA" lines

NAME is the exact public symbol name, e.g. CHmsZoneDynamic::PhysicsStep2.
Needs: llvm-pdbutil, pefile, capstone.
"""
import re
import subprocess
import sys

import capstone
import pefile

MIN_PATTERN = 24
MAX_PATTERN = 96


def load_publics(pdb_path):
    out = subprocess.run(["llvm-pdbutil", "dump", "-publics", pdb_path],
                         capture_output=True, text=True, check=True).stdout
    syms = {}
    name = None
    for line in out.splitlines():
        m = re.search(r"S_PUB32 \[size = \d+\] `(.*)`", line)
        if m:
            name = m.group(1)
            continue
        m = re.search(r"flags = (.*), addr = (\d+):(\d+)", line)
        if m and name is not None:
            if "function" in m.group(1):
                syms.setdefault(name, []).append((int(m.group(2)), int(m.group(3))))
            name = None
    return syms


class Image:
    def __init__(self, path):
        self.pe = pefile.PE(path)
        self.base = self.pe.OPTIONAL_HEADER.ImageBase
        self.text = next(s for s in self.pe.sections if s.Name.rstrip(b"\0") == b".text")
        self.text_va = self.base + self.text.VirtualAddress
        self.text_data = self.text.get_data()
        self.relocs = set()
        for block in getattr(self.pe, "DIRECTORY_ENTRY_BASERELOC", []):
            for e in block.entries:
                if e.type == 3:  # HIGHLOW
                    self.relocs.add(self.base + e.rva)

    def section_va(self, section_index, offset):
        s = self.pe.sections[section_index - 1]
        return self.base + s.VirtualAddress + offset


def build_pattern(img, va):
    """Masked regex for the function at va, one instruction at a time."""
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    off = va - img.text_va
    code = img.text_data[off:off + MAX_PATTERN + 16]
    parts, length = [], 0
    for ins in md.disasm(code, va):
        raw = bytearray(ins.bytes)
        mask = [True] * len(raw)
        # Relocated absolute addresses (globals, vtables, jump tables).
        for i in range(len(raw) - 3):
            if ins.address + i in img.relocs:
                mask[i:i + 4] = [False] * 4
        # Relative branch targets move with the layout.
        if raw[0] in (0xE8, 0xE9) and len(raw) == 5:
            mask[1:5] = [False] * 4
        if len(raw) == 6 and raw[0] == 0x0F and 0x80 <= raw[1] <= 0x8F:
            mask[2:6] = [False] * 4
        for b, keep in zip(raw, mask):
            parts.append(re.escape(bytes([b])) if keep else b".")
        length += len(raw)
        if length >= MAX_PATTERN or ins.mnemonic in ("ret", "jmp", "int3"):
            break
    return b"".join(parts), length


def find(target, pattern):
    return [target.text_va + m.start()
            for m in re.finditer(pattern, target.text_data, re.DOTALL)]


def main():
    if len(sys.argv) < 5:
        print(__doc__, file=sys.stderr)
        sys.exit(2)
    src = Image(sys.argv[1])
    syms = load_publics(sys.argv[2])
    dst = Image(sys.argv[3])
    status = 0
    for name in sys.argv[4:]:
        locs = syms.get(name)
        if not locs:
            print(f"{name} NOT_IN_PDB")
            status = 1
            continue
        va = src.section_va(*locs[0])
        pattern, length = build_pattern(src, va)
        hits = find(dst, pattern) if length >= MIN_PATTERN else []
        if len(hits) == 1:
            print(f"{name} 0x{hits[0]:08x} (pdb 0x{va:08x}, {length} bytes)")
        else:
            print(f"{name} {'AMBIGUOUS' if hits else 'NOT_FOUND'} {len(hits)} "
                  f"(pdb 0x{va:08x}, {length} bytes)")
            status = 1
    sys.exit(status)


if __name__ == "__main__":
    main()
