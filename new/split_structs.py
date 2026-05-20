import re
import os
import sys

def split_structs(input_file, output_dir):
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    print(f"Reading {input_file}...")
    try:
        with open(input_file, 'r', encoding='utf-8') as f:
            content = f.read()
    except FileNotFoundError:
        print(f"Error: {input_file} not found.")
        return

    # Pattern to match: struct Name { ... };
    # We use a non-greedy match for the body and DOTALL for multiline
    struct_pattern = re.compile(r'struct\s+(\w+)\s+\{(.*?)\};', re.DOTALL)
    
    matches = list(struct_pattern.finditer(content))
    print(f"Found {len(matches)} structs. Splitting...")

    for match in matches:
        name = match.group(1)
        body = match.group(2).strip()
        
        file_path = os.path.join(output_dir, f"{name}.hpp")
        guard = f"{name.upper()}_HPP"
        
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(f"#ifndef {guard}\n")
            f.write(f"#define {guard}\n\n")
            f.write("#include \"typedefs.h\"\n\n")
            f.write(f"struct {name} {{\n")
            if body:
                f.write(f"    {body}\n")
            f.write("};\n\n")
            f.write(f"#endif // {guard}\n")

    print(f"Done. Files are in {output_dir}")

if __name__ == "__main__":
    # If run from root, use new/include, if run from new, use include
    # But user said assume execution in 'new'
    split_structs("reconstructed_structs.h", "include")
