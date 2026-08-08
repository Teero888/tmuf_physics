#!/bin/bash
set -euo pipefail

VISUALIZATION_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$VISUALIZATION_DIR/.."

if ! pkg-config --exists sdl2; then
    echo "SDL2 development files are required (pkg-config could not find sdl2)." >&2
    exit 1
fi

# Reuse the project's normal build so this executable is always linked against
# the same objects that passed the regression suite.
./test_compile.sh

INCLUDES="-I. -I./Fast -I./Archive -I./Classic -I./Mw -I./Gm -I./Hms -I./Stubs -I./Plug -I./Scene -I./Game -I../gbx_map/include"
LIBS="-L../gbx_map/build -lgbx_map -lminilzo"
FILES=$(find . -maxdepth 2 -name "*.cpp" -not -path "./build/*" -not -path "./visualization/*" -not -name "main.cpp" -not -name "dump_tuning.cpp")
OBJECTS=""
for file in $FILES; do
    obj_name=$(echo "$file" | sed 's|^\./||; s|/|_|g; s|\.cpp$|.o|')
    OBJECTS="$OBJECTS build/$obj_name"
done

mkdir -p visualization/build
g++ -c visualization/VehicleTrackSimulation.cpp \
    -o visualization/build/VehicleTrackSimulation.o \
    $INCLUDES -std=c++20 -fpermissive -w -g

g++ visualization/main.cpp visualization/build/VehicleTrackSimulation.o \
    $OBJECTS -o visualization/interactive_physics_test \
    $INCLUDES $LIBS $(pkg-config --cflags --libs sdl2) \
    -std=c++20 -fpermissive -w -g

echo "Built ./visualization/interactive_physics_test"
