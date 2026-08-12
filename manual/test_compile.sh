#!/bin/bash

# Move to the working directory
cd "$(dirname "$0")" || exit 1

# Required include directories
INCLUDES="-I. -I./Fast -I./Archive -I./Classic -I./Mw -I./Gm -I./Hms -I./Stubs -I./Plug -I./Scene -I./Game -I../gbx_map/include"
LIBS="-L../gbx_map/build -lgbx_map -L../gbx_map/build -lminilzo"

# -ffp-contract=off keeps the compiler from fusing multiply-adds, so an
# optimised build reproduces the same float results as an unoptimised one.
# Verified bit-identical against -O0 on the A01 replay trace.
OPTFLAGS="-O3 -ffp-contract=off -g"
export OPTFLAGS INCLUDES

SUCCESS=0
FAIL=0

# Create build directory
mkdir -p build

# Find all .cpp files except main.cpp
FILES=$(find . -maxdepth 2 -name "*.cpp" -not -path "./build/*" -not -path "./visualization/*" -not -name "main.cpp" -not -name "dump_tuning.cpp")

echo "======================================"
echo "           compiling objects          "
echo "======================================"

OBJECTS=""
for file in $FILES; do
    obj_name=$(echo "$file" | sed 's|^\./||; s|/|_|g; s|\.cpp$|.o|')
    OBJECTS="$OBJECTS build/$obj_name"
done

# Optimised builds are slow enough that compiling one file at a time is the
# longest part of the edit/test loop; fan out over the available cores.
compile_object() {
    file="$1"
    obj_name=$(echo "$file" | sed 's|^\./||; s|/|_|g; s|\.cpp$|.o|')
    log="build/${obj_name%.o}.log"
    if g++ -c "$file" -o "build/$obj_name" $INCLUDES -fpermissive -w \
        $OPTFLAGS > "$log" 2>&1; then
        rm -f "$log"
        echo "SUCCESS $file"
    else
        echo "FAILED $file (errors saved to $log)"
    fi
}
export -f compile_object

RESULTS=$(printf '%s\n' $FILES | \
    xargs -P "$(nproc)" -I{} bash -c 'compile_object "$@"' _ {})
echo "$RESULTS" | sed 's/^SUCCESS /Compiled /; s/^FAILED /FAILED  /'
SUCCESS=$(echo "$RESULTS" | grep -c '^SUCCESS ')
FAIL=$(echo "$RESULTS" | grep -c '^FAILED ')

echo ""
echo "======================================"
echo "           linking harness            "
echo "======================================"

if [ $FAIL -eq 0 ]; then
    echo -n "Compiling main.cpp and linking ... "
    if g++ main.cpp $OBJECTS -o physics_harness $INCLUDES $LIBS -fpermissive -w $OPTFLAGS; then
        echo "SUCCESS"
    else
        echo "FAILED"
        exit 1
    fi

    echo -n "Compiling tuning curve regression ... "
    if g++ tests/unit/tuning_curve_test.cpp $OBJECTS -o build/tuning_curve_test $INCLUDES $LIBS -fpermissive -w $OPTFLAGS; then
        echo "SUCCESS"
    else
        echo "FAILED"
        exit 1
    fi

    if ! ./build/tuning_curve_test; then
        exit 1
    fi

    echo -n "Compiling surface material regression ... "
    if g++ tests/unit/surface_material_test.cpp $OBJECTS -o build/surface_material_test $INCLUDES $LIBS -fpermissive -w $OPTFLAGS; then
        echo "SUCCESS"
    else
        echo "FAILED"
        exit 1
    fi

    if ! ./build/surface_material_test; then
        exit 1
    fi

    echo -n "Compiling original executable constants regression ... "
    if g++ tests/unit/original_constants_test.cpp -o build/original_constants_test $INCLUDES -fpermissive -w $OPTFLAGS; then
        echo "SUCCESS"
    else
        echo "FAILED"
        exit 1
    fi

    if ! ./build/original_constants_test; then
        exit 1
    fi

    echo -n "Compiling original Model6 dispatch/layout regression ... "
    if g++ tests/unit/original_model6_dispatch_test.cpp -o build/original_model6_dispatch_test $INCLUDES -fpermissive -w $OPTFLAGS; then
        echo "SUCCESS"
    else
        echo "FAILED"
        exit 1
    fi

    if ! ./build/original_model6_dispatch_test; then
        exit 1
    fi

    echo -n "Compiling vehicle state regression ... "
    if g++ tests/unit/vehicle_state_test.cpp $OBJECTS -o build/vehicle_state_test $INCLUDES $LIBS -fpermissive -w $OPTFLAGS; then
        echo "SUCCESS"
    else
        echo "FAILED"
        exit 1
    fi

    if ! ./build/vehicle_state_test; then
        exit 1
    fi

    echo -n "Compiling zone dynamic force lifecycle regression ... "
    if g++ tests/unit/zone_dynamic_forces_test.cpp $OBJECTS -o build/zone_dynamic_forces_test $INCLUDES $LIBS -fpermissive -w $OPTFLAGS; then
        echo "SUCCESS"
    else
        echo "FAILED"
        exit 1
    fi

    if ! ./build/zone_dynamic_forces_test; then
        exit 1
    fi

    echo -n "Compiling Gm archive regression ... "
    if g++ tests/unit/gm_archive_test.cpp $OBJECTS -o build/gm_archive_test $INCLUDES $LIBS -fpermissive -w $OPTFLAGS; then
        echo "SUCCESS"
    else
        echo "FAILED"
        exit 1
    fi

    if ! ./build/gm_archive_test; then
        exit 1
    fi

    echo -n "Compiling track collision loader/raycast regression ... "
    if g++ tests/unit/track_collision_test.cpp $OBJECTS -o build/track_collision_test $INCLUDES $LIBS -fpermissive -w $OPTFLAGS; then
        echo "SUCCESS"
    else
        echo "FAILED"
        exit 1
    fi

    A01_MAP="../steamdata/GameData/Tracks/Campaigns/Nations/White/A01-Race.Challenge.Gbx"
    PACKS_DIR="../steamdata/Packs"
    EXTRACTOR_PROJECT="TrackCollisionExtractor/TrackCollisionExtractor.csproj"
    if command -v dotnet >/dev/null 2>&1 && [ -f "$A01_MAP" ] && \
       [ -f "$PACKS_DIR/Stadium.pak" ] && [ -f "$PACKS_DIR/packlist.dat" ] && \
       [ -f "$EXTRACTOR_PROJECT" ]; then
        if ! ./build/track_collision_test \
            "$A01_MAP" "$PACKS_DIR" "$EXTRACTOR_PROJECT"; then
            exit 1
        fi
    else
        echo "A01 GBX integration inputs unavailable; running cache-format test only."
        if ! ./build/track_collision_test; then
            exit 1
        fi
    fi

    echo -n "Compiling geometry/collision regression ... "
    if g++ tests/unit/geometry_collision_test.cpp $OBJECTS -o build/geometry_collision_test $INCLUDES $LIBS -fpermissive -w $OPTFLAGS; then
        echo "SUCCESS"
    else
        echo "FAILED"
        exit 1
    fi

    if ! ./build/geometry_collision_test; then
        exit 1
    fi

    echo -n "Compiling collision manager regression ... "
    if g++ tests/unit/collision_manager_test.cpp $OBJECTS -o build/collision_manager_test $INCLUDES $LIBS -fpermissive -w $OPTFLAGS; then
        echo "SUCCESS"
    else
        echo "FAILED"
        exit 1
    fi

    if ! ./build/collision_manager_test; then
        exit 1
    fi

    echo ""
    echo "Run './physics_harness' to validate simulation."
else
    echo "Skipping link due to compilation errors."
fi

echo ""
echo "======================================"
echo " $SUCCESS compiled successfully, $FAIL failed."
echo "======================================"

if [ $FAIL -gt 0 ]; then
    exit 1
fi
exit 0
