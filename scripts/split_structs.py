import os
import json
import re

# Resolve absolute paths relative to this script's location
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

def write_struct_body(name, data, structs, f, indent=""):
    used_types = set()
    for offset_info in data['offsets'].values():
        for t in offset_info['types']:
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
    
    child_names = [s for s in structs if s.startswith(name + "::")]
    direct_children = []
    for cn in child_names:
        suffix = cn[len(name)+2:]
        if "::" not in suffix: direct_children.append(cn)
            
    for dc in sorted(direct_children):
        write_struct_body(dc, structs[dc], structs, f, indent + "    ")
        f.write("\n")

    offsets = data['offsets']
    last_offset = 0
    int_offsets = sorted([int(k) for k in offsets.keys()])
    
    for offset in int_offsets:
        if offset > last_offset:
            f.write(f"{indent}    byte _padding_0x{last_offset:x}[{offset - last_offset}];\n")
        
        info = offsets[str(offset)]
        types = info['types']
        main_type = types[0] if types else "undefined4"
        
        field_name = f"field_0x{offset:x}"
        if offset == 0 and "vtable" not in "".join(types).lower():
            field_name = "vftable"
            main_type = "void**"
        
        f.write(f"{indent}    {main_type} {field_name}; // accesses: {info['count']}\n")
        
        if '*' in main_type or 'undefined4' in main_type or 'int' in main_type or 'float' in main_type:
            last_offset = offset + 4
        elif 'short' in main_type or 'undefined2' in main_type:
            last_offset = offset + 2
        elif 'byte' in main_type or 'char' in main_type or 'undefined1' in main_type:
            last_offset = offset + 1
        else:
            last_offset = offset + 4
    
    if data['functions']:
        f.write(f"\n{indent}    // Member Functions\n")
        for sig in sorted(data['functions']):
            f.write(f"{indent}    {sig};\n")
    f.write(f"{indent}}};\n")

def split_structs(json_file, output_dir):
    if not os.path.isabs(json_file):
        json_file = os.path.join(SCRIPT_DIR, json_file)
    if not os.path.isabs(output_dir):
        output_dir = os.path.join(SCRIPT_DIR, output_dir)

    print(f"Reading {json_file}...")
    try:
        with open(json_file, 'r', encoding='utf-8') as f:
            structs = json.load(f)
    except FileNotFoundError:
        print(f"Error: {json_file} not found.")
        return

    roots = [s for s in structs if "::" not in s]
    print(f"Found {len(roots)} root structs in {output_dir}...")

    import shutil
    if os.path.exists(output_dir):
        shutil.rmtree(output_dir)
    os.makedirs(output_dir)

    for name in roots:
        file_name = re.sub(r'[^a-zA-Z0-9_]', '_', name)
        file_path = os.path.join(output_dir, f"{file_name}.hpp")
        guard = f"{file_name.upper()}_HPP"
        
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(f"#ifndef {guard}\n")
            f.write(f"#define {guard}\n\n")
            f.write("#include \"typedefs.h\"\n\n")
            write_struct_body(name, structs[name], structs, f)
            f.write(f"\n#endif // {guard}\n")

    print("Done.")

if __name__ == "__main__":
    split_structs("reconstructed_structs.json", "../include")
