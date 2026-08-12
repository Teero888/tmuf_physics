#!/usr/bin/env python3
"""Disassemble a range of TmForeverFixed.exe with call targets named.

objdump understands the PE directly, so no Ghidra export is needed:

    python3 tools/disasm.py 0x7C3E80 0x7C6830        # by address range
    python3 tools/disasm.py CSceneVehicleCar::ComputeForcesModel6

Passing a symbol name disassembles from that symbol up to the next one in
tools/symbols.txt.  Every ``call`` is annotated with the callee's name, which
is what makes the decompiled Ghidra output in ../tmnf_dump readable: that dump
loses argument order and stack-slot identity, while this view keeps both.
"""

import re
import subprocess
import sys
import os

HERE = os.path.dirname(os.path.abspath(__file__))
EXE = os.path.join(HERE, "..", "..", "exe", "TmForeverFixed.exe")
SYMBOLS = os.path.join(HERE, "symbols.txt")


def load_symbols():
    table = {}
    with open(SYMBOLS) as handle:
        for line in handle:
            address, rest = line.split(" ", 1)
            table[int(address, 16)] = rest.split(" | ")[0]
    return table


def resolve(symbols, argument):
    try:
        return int(argument, 0)
    except ValueError:
        pass
    for address, name in symbols.items():
        if name == argument:
            return address
    raise SystemExit("unknown symbol: %s" % argument)


def main():
    if len(sys.argv) < 2:
        raise SystemExit(__doc__)
    symbols = load_symbols()
    start = resolve(symbols, sys.argv[1])
    if len(sys.argv) > 2:
        stop = resolve(symbols, sys.argv[2])
    else:
        later = [a for a in symbols if a > start]
        stop = min(later) if later else start + 0x400

    text = subprocess.run(
        ["objdump", "-d", "-M", "intel",
         "--start-address=0x%x" % start, "--stop-address=0x%x" % stop, EXE],
        check=True, capture_output=True, text=True).stdout

    for line in text.splitlines():
        match = re.search(r"call\s+0x([0-9a-f]+)", line)
        if match:
            target = int(match.group(1), 16)
            if target in symbols:
                line = "%-70s ; %s" % (line, symbols[target])
        print(line)


if __name__ == "__main__":
    main()
