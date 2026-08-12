#!/usr/bin/env python3
"""Rebuild tools/symbols.txt from the shipped PDB.

TmForeverFixed.pdb keeps a full public-symbol stream, so every function in the
executable can be recovered by name and address without Ghidra.  llvm-pdbutil's
``pretty`` mode needs DIA and is unavailable on Linux, but ``dump -publics``
uses the native reader and works.

Public records carry a (section, offset) pair rather than a virtual address.
The section bases come from the PE headers (``objdump -h``):

    1 .text   0x00401000
    2 .rdata  0x00B28000
    3 .data   0x00CCA000

Only .text carries public symbols in practice; the tuning/physics constants
live in .rdata and .data and have to be reached through the code that reads
them.  For every loaded section the file offset is ``virtual_address -
0x00400000``, which is what tests/unit/original_constants_test.cpp uses.

Usage:
    python3 tools/extract_symbols.py [path/to/TmForeverFixed.pdb] > tools/symbols.txt
"""

import re
import subprocess
import sys

SECTION_BASES = {1: 0x401000, 2: 0xB28000, 3: 0xCCA000}


def extract(pdb_path):
    output = subprocess.run(
        ["llvm-pdbutil", "dump", "-publics", pdb_path],
        check=True, capture_output=True, text=True, errors="replace").stdout

    records = []
    pending_name = None
    for line in output.splitlines():
        match = re.search(r"S_PUB32 \[size = \d+\] `(.*)`", line)
        if match:
            pending_name = match.group(1)
            continue
        match = re.search(r"flags = (.*), addr = (\d+):(\d+)", line)
        if match and pending_name is not None:
            section = int(match.group(2))
            base = SECTION_BASES.get(section)
            if base is not None:
                records.append(
                    (base + int(match.group(3)), pending_name, match.group(1)))
            pending_name = None
    records.sort()
    return records


def main():
    pdb_path = sys.argv[1] if len(sys.argv) > 1 else "../exe/TmForeverFixed.pdb"
    for address, name, flags in extract(pdb_path):
        print("%08X %s | %s" % (address, name, flags))


if __name__ == "__main__":
    main()
