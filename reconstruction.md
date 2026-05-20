# TrackMania Physics Reconstruction Guide

This guide explains how to go from a raw Ghidra C dump to a modular, semi-compilable C++ physics library using the automated pipeline in the `new/` directory.

## Prerequisites
- A full C dump from Ghidra named `dump.cpp` (or `dump.c`).
- Python 3.x

## Step-by-Step Pipeline

Run all commands from within the `new/` directory.

### 1. Extract the Physics Subset
Extracts only the code reachable from `CTrackManiaRace::Validate` and core physics classes/keywords (whitelisted in the script).
```bash
python3 recursive_extract.py dump.cpp CTrackManiaRace::Validate
```
- **Output:** `physics_extracted_code.c`

### 2. Split into Modular Source Files
Breaks the massive extracted file into individual `.cpp` files in the `src/` directory, organized by class name.
```bash
python3 split_classes.py
```
- **Output:** `src/*.cpp`, `src/Globals.cpp`

### 3. Reconstruct Struct Layouts & Signatures
Performs static analysis on the `src/` files to identify memory offsets (fields), data types, and member function signatures for every class.
```bash
python3 reconstruct_structs.py src
```
- **Output:** `reconstructed_structs.json` (Database), `reconstructed_structs.h` (Flat view)

### 4. Split into Modular Header Files
Generates individual `.hpp` files in the `include/` directory. This script automatically handles **nested structs** (placing them inside their parent class) and adds member function declarations.
```bash
python3 split_structs.py
```
- **Output:** `include/*.hpp`

### 5. Finalize Dependencies (Typedefs)
Analyzes the generated headers to find any types that were referenced but not defined (e.g., enums or external classes) and creates `typedefs.h`.
```bash
# 1. Generate the list of unknown types
python3 find_unknown_types.py include > unknown_types.txt

# 2. Build the comprehensive typedefs header
python3 make_typedefs.py
```
- **Output:** `include/typedefs.h`

