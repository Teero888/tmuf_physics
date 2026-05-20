import re
import os
import sys
import json

# Resolve absolute paths relative to this script's location
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

def extract_sizes(dump_file):
    print(f"Reading {dump_file} line by line...")
    
    sizes = {}
    current_class = None
    in_mwnew = False
    in_init_class = False

    # Regex for headers
    # // Function: MwNewClassName @ 00401000
    mwnew_header_re = re.compile(r'// Function: MwNew([\w<>:]+)\b')
    # // Function: __InitClassInfo_ClassName @ 00401000
    init_header_re = re.compile(r'// Function: __InitClassInfo_([\w<>:]+)\b')
    
    # Regex for operator_new
    new_re = re.compile(r'operator_new\((0x[0-9a-fA-F]+|[0-9]+)\)')
    
    # Regex for class info size assignment (param_1 + 0x24) = 0xSIZE
    size_assign_re = re.compile(r'param_1\s*\+\s*0x24\)\s*=\s*(0x[0-9a-fA-F]+|[0-9]+);')

    try:
        with open(dump_file, 'r', encoding='utf-8', errors='ignore') as f:
            for line in f:
                # 1. Detect function headers
                if line.startswith("// Function:"):
                    m_mwnew = mwnew_header_re.search(line)
                    if m_mwnew:
                        current_class = m_mwnew.group(1).strip()
                        in_mwnew = True
                        in_init_class = False
                        continue
                        
                    m_init = init_header_re.search(line)
                    if m_init:
                        current_class = m_init.group(1).strip()
                        in_init_class = True
                        in_mwnew = False
                        continue
                    
                    # New function start, reset
                    in_mwnew = False
                    in_init_class = False
                    current_class = None

                # 2. Extract sizes from operator_new in MwNew
                if in_mwnew and current_class:
                    m_new = new_re.search(line)
                    if m_new:
                        try:
                            size = int(m_new.group(1), 0)
                            if size > 0:
                                sizes[current_class] = size
                            in_mwnew = False # Done for this function
                        except ValueError: pass

                # 3. Extract sizes from __InitClassInfo assignments
                if in_init_class and current_class:
                    m_size = size_assign_re.search(line)
                    if m_size:
                        try:
                            size = int(m_size.group(1), 0)
                            # In Nadeo engine, offset 0x24 in ClassInfo is often the allocation size
                            # We only take it if we haven't already found a size (MwNew is more reliable)
                            if size > 0 and size < 0x10000 and current_class not in sizes:
                                sizes[current_class] = size
                            # We don't reset in_init_class yet as there might be multiple assignments
                        except ValueError: pass
                        
    except FileNotFoundError:
        print(f"Error: {dump_file} not found.")
        return {}

    return sizes

if __name__ == "__main__":
    if len(sys.argv) < 2:
        dump_path = os.path.join(SCRIPT_DIR, "dump.cpp")
    else:
        dump_path = sys.argv[1]

    found_sizes = extract_sizes(dump_path)
    
    output_json = os.path.join(SCRIPT_DIR, "struct_sizes.json")
    with open(output_json, 'w') as f:
        json.dump(found_sizes, f, indent=2)
    
    print(f"Extracted {len(found_sizes)} class sizes to {output_json}")
    
    # Print some key examples
    examples = ["CSceneVehicleCar", "CHmsDyna", "GmVec3", "GmMat4", "CTrackManiaRace"]
    for ex in examples:
        if ex in found_sizes:
            print(f"{ex}: {hex(found_sizes[ex])}")
