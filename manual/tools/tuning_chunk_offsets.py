#!/usr/bin/env python3
"""Recover CSceneVehicleCarTuning's chunk-id to member-offset mapping.

The tuning values used by the physics come from StadiumCar.VehicleTunings.Gbx.
GBX.NET names the fields (see gbx-net CPlugVehicleCarPhyTuning.chunkl) but says
nothing about where they land in the native object, and no parameter-name
strings survive in the release executable.  Two independent facts recover the
mapping:

  * CSceneVehicleCarTuning::Chunk (0x7F5EB0) dispatches on the chunk id through
    a jump table at 0x7F78B4 covering 0x0A029000..0x0A029034.  Each case reads
    its fields in file order with CClassicArchive::DoReal / DoNatural / DoBool /
    MwDoNodRef, and the destination is an ``lea reg,[esi+offset]`` on ``this``.

  * SMwParamInfos_CSceneVehicleCarTuning::s_Params, the reflection table at
    .data 0x00D093C0, stores each parameter's member offset directly.  Its
    entries confirm the offsets found above (parameter 2 -> 0x34, parameter 3
    -> 0x1E0, and so on).

Lining a chunk's native read order up against the same chunk in the .chunkl
gives name <-> offset.  Cross-checks that came out of this: +0x34 AccelCurve
(also the curve M5GetAccelFromSpeed loads), +0x1E0/+0x1E4 the M5 slipping accel
curve and its coefficient, +0x2C MaxSpeed, +0x30 ReverseMaxSpeed, +0x40..+0x4C
BrakeBase/BrakeCoef/BrakeMax/BrakeMaxDynamic, +0x6C/+0x70 SteerRadiusMin/Coef,
+0xA4 SideFriction1, +0xAC MaxSideFriction, +0xB8 RolloverLateral, +0x114..+0x124
the AbsorbingVal block, +0x160 GravityCoef, +0x350 ShockModel.

A handful of reads still print ``?``: those load the destination through a
register form this scanner does not model.  Read them out of the disassembly
directly (tools/disasm.py) rather than trusting a guessed alignment.

Usage:
    python3 tools/tuning_chunk_offsets.py
"""

import os
import re
import struct
import subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
EXE = os.path.join(HERE, "..", "..", "exe", "TmForeverFixed.exe")
SYMBOLS = os.path.join(HERE, "symbols.txt")

CHUNK_FUNCTION = 0x7F5EB0
CHUNK_FUNCTION_END = 0x7F7900
JUMP_TABLE = 0x7F78B4
JUMP_TABLE_COUNT = 0x35
CHUNK_BASE_ID = 0x0A029000
DEFAULT_TAIL = 0x7F786C


def load_symbols():
    table = {}
    with open(SYMBOLS) as handle:
        for line in handle:
            address, rest = line.split(" ", 1)
            table[int(address, 16)] = rest.split(" | ")[0]
    return table


def load_jump_table():
    with open(EXE, "rb") as handle:
        image = handle.read()
    targets = []
    for index in range(JUMP_TABLE_COUNT):
        offset = JUMP_TABLE + 4 * index - 0x400000
        targets.append(struct.unpack("<I", image[offset:offset + 4])[0])
    return targets


def disassemble():
    text = subprocess.run(
        ["objdump", "-d", "-M", "intel",
         "--start-address=0x%x" % CHUNK_FUNCTION,
         "--stop-address=0x%x" % CHUNK_FUNCTION_END, EXE],
        check=True, capture_output=True, text=True).stdout
    instructions = []
    for line in text.splitlines():
        match = re.match(r"\s+([0-9a-f]+):\t[0-9a-f ]+\t(.*)", line)
        if match:
            instructions.append((int(match.group(1), 16), match.group(2).strip()))
    return instructions


def scan_case(instructions, symbols, start, stop):
    fields = []
    registers = {}
    pushed = []
    for address, text in instructions:
        if address < start or address >= stop:
            continue
        match = re.match(r"lea\s+(\w+),\[esi([+-]0x[0-9a-f]+)?\]$", text)
        if match:
            registers[match.group(1)] = (
                int(match.group(2), 16) if match.group(2) else 0)
            continue
        match = re.match(r"mov\s+(\w+),esi$", text)
        if match:
            registers[match.group(1)] = 0
            continue
        match = re.match(r"push\s+(\w+)$", text)
        if match:
            pushed.append(registers.get(match.group(1)))
            continue
        if re.match(r"push\s+0x", text):
            pushed.append(None)
            continue
        match = re.match(r"call\s+0x([0-9a-f]+)", text)
        if match:
            name = symbols.get(int(match.group(1), 16), match.group(1))
            if "Do" in name:
                candidates = [p for p in pushed if p is not None]
                fields.append((candidates[-1] if candidates else None,
                               name.split("::")[-1]))
            pushed = []
    return fields


def main():
    symbols = load_symbols()
    targets = load_jump_table()
    instructions = disassemble()
    bounds = sorted(targets) + [DEFAULT_TAIL]
    for index, start in enumerate(targets):
        stop = min(b for b in bounds if b > start)
        fields = scan_case(instructions, symbols, start, stop)
        if not fields:
            continue
        rendered = ", ".join(
            "%s@%s" % (kind, hex(offset) if offset is not None else "?")
            for offset, kind in fields)
        print("chunk 0x%08X (0x%03X): %s" % (CHUNK_BASE_ID + index, index,
                                             rendered))


if __name__ == "__main__":
    main()
