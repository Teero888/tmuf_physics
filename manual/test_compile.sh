#!/bin/bash

# Move to the working directory
cd "$(dirname "$0")" || exit 1

# Required include directories
INCLUDES="-I. -I./Fast -I./Archive -I./Classic -I./Mw -I./Gm -I./Hms -I./Stubs -I./Plug -I./Scene -I./Game -I../gbx_map/include"
LIBS="-L../gbx_map/build -lgbx_map -L../gbx_map/build -lminilzo"

SUCCESS=0
FAIL=0

# Create build directory
mkdir -p build

# Find all .cpp files except main.cpp
FILES=$(find . -maxdepth 2 -name "*.cpp" -not -path "./build/*" -not -name "main.cpp" -not -name "dump_tuning.cpp")

echo "======================================"
echo "           compiling objects          "
echo "======================================"

OBJECTS=""
for file in $FILES; do
    obj_name=$(echo "$file" | sed 's|^\./||; s|/|_|g; s|\.cpp$|.o|')
    obj_path="build/$obj_name"
    
    echo -n "Compiling $file ... "
    if g++ -c "$file" -o "$obj_path" $INCLUDES -fpermissive -w -g; then
        echo "SUCCESS"
        SUCCESS=$((SUCCESS + 1))
        OBJECTS="$OBJECTS $obj_path"
    else
        echo "FAILED (Errors saved to build/${obj_name%.o}.log)"
        g++ -c "$file" -o "$obj_path" $INCLUDES -fpermissive -w -g > "build/${obj_name%.o}.log" 2>&1
        FAIL=$((FAIL + 1))
    fi
done

echo ""
echo "======================================"
echo "           linking harness            "
echo "======================================"

if [ $FAIL -eq 0 ]; then
    echo -n "Compiling main.cpp and linking ... "
    if g++ main.cpp $OBJECTS -o physics_harness $INCLUDES $LIBS -fpermissive -w -g; then
        echo "SUCCESS"
        echo ""
        echo "Run './physics_harness' to validate simulation."
    else
        echo "FAILED"
        exit 1
    fi
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
