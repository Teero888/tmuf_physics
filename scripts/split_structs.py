import os
import json
import re

# Resolve absolute paths relative to this script's location
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

# Standard sizes for core math types in Nadeo engine
HARDCODED_SIZES = {
    'GmVec2': 8, 'GmVec3': 12, 'GmVec4': 16, 'GmQuat': 16,
    'GmMat2': 16, 'GmMat3': 36, 'GmMat4': 64, 'GmIso3': 36, 'GmIso4': 48,
    'GmBoxAligned': 24, 'GmBoxOriented': 64, 'GmRectAligned': 16,
    'GmFrustum': 96, 'GmCone3': 16, 'GmLine3': 24, 'GmPlane': 16, 'GmSphere': 16
}

def get_best_type(type_counts, offset, class_name):
    if not type_counts:
        return "undefined4"
    
    # 1. Math Classes ('Gm' prefix) -> Always prefer float
    if class_name.startswith('Gm'):
        return 'float'

    # 2. Game Classes ('C' prefix) -> Offset 0 is vftable
    if offset == 0 and class_name.startswith('C'):
        return "void**"

    # 3. Specific Struct Pointers
    ptrs = {t: c for t, c in type_counts.items() if '*' in t}
    for t in sorted(ptrs, key=ptrs.get, reverse=True):
        if t.strip() not in ['void *', 'void**', 'void * *', 'undefined4 *', 'undefined *', 'undefined1 *', 'undefined2 *', 'undefined8 *']:
            return t

    # 4. Fallback to most frequent
    sorted_types = sorted(type_counts.items(), key=lambda x: x[1], reverse=True)
    return sorted_types[0][0]

def write_struct_body(name, data, structs, sizes, f, indent=""):
    used_types = set()
    for offset_info in data['offsets'].values():
        for t in offset_info.keys():
            clean_t = re.sub(r'[*&]', '', t).strip()
            if clean_t in structs and not clean_t.startswith(name + "::") and clean_t != name:
                used_types.add(clean_t)
    
    if used_types:
        for ut in sorted(list(used_types)):
            root = ut.split("::")[0]
            if root != name.split("::")[0]:
                f.write(f"{indent}struct {ut};\n")
        f.write("\n")

    short_name = name.split("::")[-1]
    f.write(f"{indent}struct {short_name} {{\n")
    
    # Nested Structs
    child_names = [s for s in structs if s.startswith(name + "::")]
    direct_children = [cn for cn in child_names if "::" not in cn[len(name)+2:]]
    for dc in sorted(direct_children):
        write_struct_body(dc, structs[dc], structs, sizes, f, indent + "    ")
        f.write("\n")

    offsets = data['offsets']
    max_size = sizes.get(name, HARDCODED_SIZES.get(name, 0))
    
    # Ensure vftable for 'C' classes with functions
    if '0' not in offsets and name.startswith('C') and data['functions']:
        offsets['0'] = {"void**": 0}

    if not offsets and max_size == 0:
        f.write(f"{indent}    // No fields detected\n")
    else:
        int_offsets = sorted([int(k) for k in offsets.keys()])
        last_offset = 0
        
        for offset in int_offsets:
            # ONLY filter if we are over the real known size
            if max_size > 0 and offset >= max_size: continue
                
            if offset > last_offset:
                f.write(f"{indent}    byte _padding_0x{last_offset:x}[{offset - last_offset}];\n")
            
            type_counts = offsets[str(offset)]
            main_type = get_best_type(type_counts, offset, name)
            field_name = f"field_0x{offset:x}"
            if offset == 0 and main_type == "void**": field_name = "vftable"
            
            count = sum(type_counts.values())
            count_suffix = f" // accesses: {count}" if count > 0 else ""
            f.write(f"{indent}    {main_type} {field_name};{count_suffix}\n")
            
            if '*' in main_type or 'undefined4' in main_type or 'int' in main_type or 'float' in main_type:
                last_offset = offset + 4
            elif 'short' in main_type or 'undefined2' in main_type:
                last_offset = offset + 2
            elif 'byte' in main_type or 'char' in main_type or 'undefined1' in main_type:
                last_offset = offset + 1
            else:
                last_offset = offset + 4
        
        if max_size > last_offset:
            f.write(f"{indent}    byte _final_padding[0x{max_size - last_offset:x}]; // Total size: 0x{max_size:x}\n")

    if data['functions']:
        f.write(f"\n{indent}    // Member Functions\n")
        for sig in sorted(data['functions']):
            f.write(f"{indent}    {sig};\n")
    f.write(f"{indent}}};\n")

def split_structs(json_file, size_file, output_dir):
    if not os.path.isabs(json_file): json_file = os.path.join(SCRIPT_DIR, json_file)
    if not os.path.isabs(size_file): size_file = os.path.join(SCRIPT_DIR, size_file)
    if not os.path.isabs(output_dir): output_dir = os.path.join(SCRIPT_DIR, output_dir)

    try:
        with open(json_file, 'r', encoding='utf-8') as f:
            structs = json.load(f)
    except FileNotFoundError: return

    sizes = {}
    if os.path.exists(size_file):
        with open(size_file, 'r', encoding='utf-8') as f:
            sizes = json.load(f)

    roots = [s for s in structs if "::" not in s]
    import shutil
    if os.path.exists(output_dir):
        shutil.rmtree(output_dir)
    os.makedirs(output_dir)

    for name in sorted(roots):
        file_name = re.sub(r'[^a-zA-Z0-9_]', '_', name)
        file_path = os.path.join(output_dir, f"{file_name}.hpp")
        guard = f"{file_name.upper()}_HPP"
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(f"#ifndef {guard}\n#define {guard}\n\n#include \"typedefs.h\"\n\n")
            write_struct_body(name, structs[name], structs, sizes, f)
            f.write(f"\n#endif // {guard}\n")

if __name__ == "__main__":
    split_structs("reconstructed_structs.json", "struct_sizes.json", "../include")
    print("Done.")
