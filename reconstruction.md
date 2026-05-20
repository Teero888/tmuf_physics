# TrackMania Physics Reconstruction Guide

This guide explains how to go from a raw Ghidra C dump to a modular, semi-compilable C++ physics library.

## Prerequisites
- A full C dump from Ghidra named `dump.cpp` (or `dump.c`) placed in the `scripts/` directory.
- Python 3.x

## Step-by-Step Pipeline

**All commands should be executed from within the `scripts/` directory.**

### 1. Extract the Physics Subset
Extracts only the code reachable from `CTrackManiaRace::Validate` and core physics classes.
```bash
cd scripts
python3 recursive_extract.py dump.cpp CTrackManiaRace::Validate
```
- **Output:** `scripts/physics_extracted_code.c`

### 2. Split into Modular Source Files
Breaks the extracted file into individual `.cpp` files in the root `src/` directory.
```bash
python3 split_classes.py
```
- **Output:** `src/*.cpp` (root directory)

### 3. Reconstruct Struct Layouts & Signatures
Performs static analysis on the `src/` files to identify memory offsets and function signatures.
```bash
python3 reconstruct_structs.py
```
- **Output:** `scripts/reconstructed_structs.json`, `scripts/reconstructed_structs.h`

### 4. Split into Modular Header Files
Generates individual `.hpp` files in the root `include/` directory.
```bash
python3 split_structs.py
```
- **Output:** `include/*.hpp` (root directory)

### 5. Finalize Dependencies (Typedefs)
Analyzes the generated headers to find unknown types and creates `typedefs.h`.
```bash
# 1. Extract potential enums from the source code
grep -ohP "\bE[A-Z]\w+\b" ../src/*.cpp | sort | uniq > potential_enums.txt

# 2. Generate the list of unknown types
python3 find_unknown_types.py > unknown_types.txt

# 3. Build the comprehensive typedefs header
python3 make_typedefs.py
```

- **Output:** `include/typedefs.h` (root directory)

