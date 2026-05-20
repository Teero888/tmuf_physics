import re
import os
import sys

def analyze_offsets(src_dir):
    # Regex to find patterns like: *(float *)(this + 0x68)
    # or: *(int *)(pCVar1 + 0x10)
    # or: this[0x201] = ...
    
    # Pattern 1: *(type *)(ptr + offset)
    ptr_offset_re = re.compile(r'\*\s*\(([\w\s\*]+)\s*\*\)\s*\(([\w]+)\s*\+\s*(0x[0-9a-fA-F]+|[0-9]+)\)')
    
    # Pattern 2: ptr[offset] (less common in Ghidra for structs, but happens)
    ptr_index_re = re.compile(r'([\w]+)\[(0x[0-9a-fA-F]+|[0-9]+)\]')

    structs = {} # class_name -> { offset -> { 'type': set(), 'count': 0 } }

    cpp_files = []
    for dp, dn, fn in os.walk(src_dir):
        for f in fn:
            if f.endswith('.cpp') and f != 'Globals.cpp':
                cpp_files.append(os.path.join(dp, f))

    for file_path in cpp_files:
        class_name = os.path.basename(file_path).replace('.cpp', '')
        if class_name not in structs:
            structs[class_name] = {}
            
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
            
            # Find all matches for Pattern 1
            for match in ptr_offset_re.finditer(content):
                data_type = match.group(1).strip()
                ptr_name = match.group(2)
                offset_str = match.group(3)
                
                # We only care about 'this' or parameters that look like 'this'
                # For now, let's assume if it's in ClassName.cpp, any access like this is relevant
                try:
                    offset = int(offset_str, 0)
                except ValueError:
                    continue
                    
                if offset not in structs[class_name]:
                    structs[class_name][offset] = {'types': set(), 'count': 0}
                
                structs[class_name][offset]['types'].add(data_type)
                structs[class_name][offset]['count'] += 1

    return structs

def generate_headers(structs, output_file):
    with open(output_file, 'w') as f:
        f.write("// Automatically reconstructed structs from field accesses\n\n")
        f.write("#include \"typedefs.h\"\n\n")
        
        for class_name in sorted(structs.keys()):
            offsets = structs[class_name]
            if not offsets:
                continue
                
            f.write(f"struct {class_name} {{\n")
            
            max_offset = max(offsets.keys()) if offsets else 0
            
            last_offset = 0
            for offset in sorted(offsets.keys()):
                # Padding
                if offset > last_offset:
                    f.write(f"    byte _padding_0x{last_offset:x}[{offset - last_offset}];\n")
                
                types = list(offsets[offset]['types'])
                # Heuristic: pick the most specific type or just the first one
                main_type = types[0] if types else "undefined4"
                
                f.write(f"    {main_type} field_0x{offset:x}; // accesses: {offsets[offset]['count']}\n")
                
                # Assume 4 bytes for undefined4/int/float unless we know better
                if 'float' in main_type or 'int' in main_type or 'ulong' in main_type or 'undefined4' in main_type:
                    last_offset = offset + 4
                elif 'short' in main_type or 'undefined2' in main_type:
                    last_offset = offset + 2
                elif 'byte' in main_type or 'char' in main_type or 'undefined1' in main_type:
                    last_offset = offset + 1
                else:
                    last_offset = offset + 4 # Default
                    
            f.write("};\n\n")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python reconstruct_structs.py <src_dir>")
        sys.exit(1)
        
    src_dir = sys.argv[1]
    print(f"Analyzing field accesses in {src_dir}...")
    structs = analyze_offsets(src_dir)
    
    output_file = "reconstructed_structs.h"
    print(f"Generating {output_file}...")
    generate_headers(structs, output_file)
    print("Done.")
