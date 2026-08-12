# Reverse-engineering tools

These replace guesswork against `../../scripts/dump.cpp` with three sources that
can be checked directly against `../../exe/TmForeverFixed.exe`.

## `symbols.txt` — 55,778 named function addresses

`TmForeverFixed.pdb` still carries its full public-symbol stream. Regenerate it
with:

```sh
python3 tools/extract_symbols.py > tools/symbols.txt
```

Each line is `VA name | flags`, sorted by address. `llvm-pdbutil pretty` needs
DIA and fails on Linux; `dump -publics` uses the native reader and works. Class
type records in the PDB are forward declarations only, so member layouts are not
available from it — those still have to come from code that reads them.

The publics are functions. Recovering a *data* address means finding the
instruction that loads it, which is what the next tool is for.

## `disasm.py` — annotated disassembly

```sh
python3 tools/disasm.py CSceneVehicleCar::ComputeForcesModel6
python3 tools/disasm.py 0x7C62B1 0x7C62F0
```

`objdump` reads the PE directly. Prefer this over the Ghidra pseudocode in
`../../tmnf_dump`: that dump reuses one C variable for several unrelated stack
slots and drops x87 stack order, which has already produced at least one wrong
translation (a `[esp+0x10]` compare that reads as a float test in the
pseudocode is really the integer ApplyWaterForces result). Facts worth
re-deriving from the disassembly rather than the dump:

- x87 operand order. `DE E9 fsubp st(1),st` is `st(1) - st(0)`; `DE E1 fsubrp`
  is the reverse. Both appear in the same function.
- `fcom` + `fnstsw` + `test ah,X` + `jp/jnp/jne` idioms, which decide whether a
  branch takes NaN and equality.
- Stack parameters. With `sub esp,0x130` plus four pushes, argument *i* of
  `ComputeForcesModel6` is `[esp+0x144+4i]`, and any `push` inside the frame
  shifts every following displacement.

## `tuning_chunk_offsets.py` — tuning field offsets

```sh
python3 tools/tuning_chunk_offsets.py
```

Prints, per GBX chunk id, the ordered archive reads and their member offsets in
`CSceneVehicleCarTuning`. Aligning that order against
`gbx-net/Src/GBX.NET/Engines/Plug/CPlugVehicleCarPhyTuning.chunkl` names each
offset. The reflection table `SMwParamInfos_CSceneVehicleCarTuning::s_Params` at
`.data 0x00D093C0` stores the same offsets independently and agrees.

## `DumpTuning` — the authoritative Stadium tuning values

```sh
cd tools/DumpTuning
dotnet run --project DumpTuning.csproj ../../../StadiumCar.VehicleTunings.Gbx
```

Prints every property of every tuning in the file, including the gear/RPM
arrays and the chunk ids present. **The Stadium car is `tuning[29]`** —
`tuning[0]` is a different car with, for example, an `AccelCurve` that peaks at
35 instead of 16, so reading the wrong index silently swaps in the wrong
physics. Use this to check any value in `../../TuningData.hpp` rather than
trusting a transcription; a diff of all 73 scalars and 26 curves against it
passes today.

Note that a value only comes from the file if its chunk id is listed under
"chunks present". Anything else keeps the default that
`CSceneVehicleCarTuning::CSceneVehicleCarTuning` (0x7F43B0) writes, and those
defaults have to be read out of the constructor's x87 stream.

## Reading a constant

`.text`, `.rdata`, and `.data` are all loaded at `virtual_address - 0x00400000`
in the file, so a constant can be read straight out of the executable at that
offset. Section bases are `.text 0x00401000`, `.rdata 0x00B28000`,
`.data 0x00CCA000`. New constants belong in
`tests/unit/original_constants_test.cpp` with their address and raw bits, and a
value widened from float to double must keep the widened value, not a rounded
decimal.
