import os
import re
import sys

# Resolve absolute paths relative to this script's location
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

def generate_typedefs(include_dir, enum_file, unknown_file, output_file):
    if not os.path.isabs(include_dir): include_dir = os.path.join(SCRIPT_DIR, include_dir)
    if not os.path.isabs(enum_file): enum_file = os.path.join(SCRIPT_DIR, enum_file)
    if not os.path.isabs(unknown_file): unknown_file = os.path.join(SCRIPT_DIR, unknown_file)
    if not os.path.isabs(output_file): output_file = os.path.join(SCRIPT_DIR, output_file)

    with open(output_file, 'w') as f:
        f.write("#ifndef TYPEDEFS_H\n")
        f.write("#define TYPEDEFS_H\n\n")
        f.write("#include <cstdint>\n")
        f.write("#include <cstddef>\n\n")
        f.write("// Calling conventions\n")
        f.write("#define __cdecl\n")
        f.write("#define __thiscall\n")
        f.write("#define __stdcall\n")
        f.write("#define __fastcall\n\n")
        f.write("// Basic types\n")
        f.write("typedef uint8_t  byte;\n")
        f.write("typedef uint16_t word;\n")
        f.write("typedef uint32_t dword;\n")
        f.write("typedef uint64_t qword;\n")
        f.write("typedef uint8_t  uchar;\n")
        f.write("typedef uint32_t uint;\n")
        f.write("typedef uint16_t ushort;\n")
        f.write("typedef uint32_t ulong;\n")
        f.write("typedef int64_t  longlong;\n")
        f.write("typedef uint64_t ulonglong;\n\n")
        f.write("// Ghidra undefined types\n")
        f.write("typedef uint8_t  undefined;\n")
        f.write("typedef uint8_t  undefined1;\n")
        f.write("typedef uint16_t undefined2;\n")
        f.write("typedef uint32_t undefined4;\n")
        f.write("typedef uint64_t undefined8;\n")
        f.write("typedef void     code;\n")
        f.write("typedef double   float10;\n\n")
        f.write("// Nadeo specific base types\n")
        f.write("typedef uint32_t TimeInt32;\n\n")
        f.write("// Enums (defined as uint for compatibility)\n")
        if os.path.exists(enum_file):
            with open(enum_file, 'r') as ef:
                for line in ef:
                    e = line.strip()
                    if e: f.write(f"typedef uint {e};\n")
        f.write("\n")
        f.write("// Missing Classes/Structs\n")
        if os.path.exists(unknown_file):
            with open(unknown_file, 'r') as uf:
                lines = uf.readlines()
                for line in lines:
                    t = line.strip()
                    if not t or "unknown types" in t: continue
                    if any(x in t for x in ["CFastBuffer", "CFastArray", "CFixedArray"]): continue
                    f.write(f"struct {t};\n")
        f.write("\n")
        f.write("// Common Nadeo Templates (opaque for now)\n")
        f.write("template<typename T> struct CFastBuffer { uint count; T* data; };\n")
        f.write("template<typename T> struct CFastArray { uint count; uint capacity; T* data; };\n")
        f.write("template<typename T, int N, typename S> struct CFixedArray { T data[N]; };\n\n")
        f.write("#endif // TYPEDEFS_H\n")

if __name__ == "__main__":
    generate_typedefs("../include", "potential_enums.txt", "unknown_types.txt", "../include/typedefs.h")
    print("include/typedefs.h generated.")
