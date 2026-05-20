# Extract subset
python3 scripts/recursive_extract.py scripts/dump.cpp CTrackManiaRace::Validate

# Split source
python3 scripts/split_classes.py

# Reconstruct layouts
python3 scripts/reconstruct_structs.py

# Split headers
python3 scripts/split_structs.py

# Finalize dependencies
grep -ohP "\bE[A-Z]\w+\b" src/*.cpp | sort | uniq > scripts/potential_enums.txt
python3 scripts/find_unknown_types.py
python3 scripts/make_typedefs.py
