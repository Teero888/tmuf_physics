#!/bin/bash

# 1. Extract subset
python3 scripts/recursive_extract.py scripts/dump.cpp CTrackManiaRace::Validate

# 2. Split source
python3 scripts/split_classes.py

# 3. Reconstruct layouts (fields and functions)
python3 scripts/reconstruct_structs.py

# 4. Extract real class sizes from dump
python3 scripts/extract_struct_sizes.py scripts/dump.cpp

# 5. Split headers (using layouts and sizes)
python3 scripts/split_structs.py

# 6. Finalize dependencies (typedefs and enums)
grep -ohP "\bE[A-Z]\w+\b" src/*.cpp | sort | uniq > scripts/potential_enums.txt
python3 scripts/find_unknown_types.py
python3 scripts/make_typedefs.py

echo "Pipeline complete."
