#!/bin/bash

# Move to the working directory
cd "$(dirname "$0")" || exit 1

# Required include directories
INCLUDES="-I. -I./Fast -I./Archive -I./Classic -I./Mw -I./Gm"

SUCCESS=0
FAIL=0

# Create build directory
mkdir -p build

echo "======================================"
echo "           compiling garbage          "
echo "======================================"

# Use process substitution to keep variables in current shell
while IFS= read -r file; do
    echo -n "Compiling $file ... "
    
    # Extract filename for object and log, replacing / with _
    obj_name=$(echo "$file" | sed 's|^\./||' | sed 's|/|_|g' | sed 's|\.cpp$||')
    
    # Attempt to compile
    g++ -c "$file" $INCLUDES -o "build/${obj_name}.o" > "build/${obj_name}.log" 2>&1
    
    if [ $? -eq 0 ]; then
        echo -e "\e[32mSUCCESS\e[0m"
        SUCCESS=$((SUCCESS + 1))
        rm "build/${obj_name}.o" 2>/dev/null
        rm "build/${obj_name}.log"
    else
        echo -e "\e[31mFAILED\e[0m (Errors saved to build/${obj_name}.log)"
        FAIL=$((FAIL + 1))
    fi
done < <(find . -name "*.cpp" -not -path "./build/*")

echo ""
echo "======================================"
echo " $SUCCESS compiled successfully, $FAIL failed."
echo "======================================"

if [ $FAIL -gt 0 ]; then
    exit 1
fi
exit 0
