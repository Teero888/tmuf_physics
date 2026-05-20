import re
import os
import sys
import shutil

# Resolve absolute paths relative to this script's location
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
ROOT_DIR = os.path.join(SCRIPT_DIR, "..")

def extract_class_name(signature):
    paren_pos = signature.find('(')
    if paren_pos == -1: return None
    colon_pos = signature.rfind('::', 0, paren_pos)
    if colon_pos == -1: return None
    
    start_pos = colon_pos
    bracket_level = 0
    while start_pos > 0:
        char = signature[start_pos - 1]
        if char == '>': bracket_level += 1
        elif char == '<': bracket_level -= 1
        elif bracket_level == 0 and char in (' ', '\n', '\t', '\r'): break
        start_pos -= 1
    
    class_name = signature[start_pos:colon_pos].strip()
    class_name = re.sub(r'\s+', ' ', class_name)
    
    prefixes = ['void', 'int', 'char', 'float', 'double', 'long', 'short', 'unsigned', 'signed',
                '__thiscall', '__cdecl', '__stdcall', '__fastcall', 'static', 'virtual', 'inline', 'const', 'struct', 'class',
                'undefined', 'undefined1', 'undefined2', 'undefined4', 'undefined8', 'byte', 'word', 'dword', 'qword']
    while True:
        changed = False
        parts = class_name.split(' ', 1)
        if len(parts) > 1 and parts[0] in prefixes:
            class_name = parts[1].strip()
            changed = True
        if not changed: break
    return class_name

def split_classes(input_file, output_dir):
    if not os.path.isabs(input_file):
        input_file = os.path.join(SCRIPT_DIR, input_file)
    if not os.path.isabs(output_dir):
        output_dir = os.path.join(SCRIPT_DIR, output_dir)
        
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    print(f"Reading {input_file}...")
    try:
        with open(input_file, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
    except FileNotFoundError:
        print(f"Error: {input_file} not found.")
        return

    print("Splitting into functions...")
    pattern = r'// =+\n// Function: (.*)\n// =+'
    chunks = re.split(pattern, content)
    
    globals_header = chunks[0]
    class_files = {} 
    globals_chunks = []

    std_names = {'std', 'basic_string', 'basic_ofstream', 'basic_ifstream', 'basic_fstream', 'basic_iostream',
                 'vector', 'map', 'set', 'list', 'deque', 'ostream', 'istream', 'iostream', 'allocator', 
                 'char_traits', 'string', 'wstring', 'pair', 'pair_long', 'locale', '_LocaleUpdate'}

    print(f"Processing {len(chunks)//2} functions...")
    for i in range(1, len(chunks), 2):
        func_name_from_header = chunks[i].strip()
        body_with_sig = chunks[i+1].strip()
        
        brace_pos = body_with_sig.find('{')
        if brace_pos != -1:
            signature = body_with_sig[:brace_pos].strip()
            class_name = extract_class_name(signature)
        else:
            class_name = None

        if not class_name and "::" in func_name_from_header:
             class_name = func_name_from_header.rsplit("::", 1)[0].strip().lstrip(": ")

        if class_name:
            is_std = False
            if 'std::' in class_name or class_name.startswith('std_'):
                is_std = True
            else:
                base_name = class_name.split('::')[0].split('<')[0]
                if base_name in std_names: is_std = True
            
            if is_std: continue

            file_name = re.sub(r'[^a-zA-Z0-9_]', '_', class_name)
            file_name = re.sub(r'_+', '_', file_name).strip('_')
            
            if file_name not in class_files:
                class_files[file_name] = []
            
            full_chunk = f"// =================================================\n// Function: {func_name_from_header}\n// =================================================\n{body_with_sig}\n"
            class_files[file_name].append(full_chunk)
        else:
            full_chunk = f"// =================================================\n// Function: {func_name_from_header}\n// =================================================\n{body_with_sig}\n"
            globals_chunks.append(full_chunk)

    print(f"Writing {len(class_files)} class files to {output_dir}...")
    if os.path.exists(output_dir):
        shutil.rmtree(output_dir)
    os.makedirs(output_dir)

    for file_name, class_chunks in class_files.items():
        if not file_name: continue
        if len(file_name) > 200: file_name = file_name[:200]
            
        file_path = os.path.join(output_dir, f"{file_name}.cpp")
        with open(file_path, 'w') as f:
            f.write(f"// Class implementation: {file_name}\n\n")
            for chunk in class_chunks:
                f.write(chunk)
                f.write("\n")

    print(f"Writing Globals.cpp...")
    with open(os.path.join(output_dir, "Globals.cpp"), 'w') as f:
        f.write("// Global Functions and Headers\n\n")
        f.write(globals_header)
        for chunk in globals_chunks:
            f.write(chunk)
            f.write("\n")

    print("Done.")

if __name__ == "__main__":
    split_classes("physics_extracted_code.c", "../src")
