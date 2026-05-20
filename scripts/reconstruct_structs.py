import re
import os
import sys
import json
from collections import Counter

# Resolve absolute paths relative to this script's location
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

def analyze_src(src_dir):
    if not os.path.isabs(src_dir):
        src_dir = os.path.join(SCRIPT_DIR, src_dir)
        
    ptr_offset_re = re.compile(r'\*\s*\(([\w\s\*:]+)\s*\*\)\s*\(\s*(?:\(int\))?\s*([\w]+)\s*\+\s*(0x[0-9a-fA-F]+|[0-9]+)\s*\)')
    ptr_zero_re = re.compile(r'\*\s*\(([\w\s\*:]+)\s*\*\)\s*([\w]+)\b')
    
    structs = {}

    cpp_files = []
    for dp, dn, fn in os.walk(src_dir):
        for f in fn:
            if f.endswith('.cpp') and f != 'Globals.cpp':
                cpp_files.append(os.path.join(dp, f))

    print(f"Analyzing {len(cpp_files)} files in {src_dir} (Strict Local Mode)...")
    for file_path in cpp_files:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
            
            pattern = r'// =+\n// Function: (.*?)\n// =+\n(.*?)\n\{(.*?)\n\}'
            for match in re.finditer(pattern, content, re.DOTALL):
                header_name = match.group(1).strip()
                signature = match.group(2).strip()
                body = match.group(3)
                
                if "::" not in header_name: continue
                
                class_name = header_name.rsplit("::", 1)[0].strip().lstrip(": ")
                if class_name not in structs:
                    structs[class_name] = {'offsets': {}, 'functions': []}

                # 1. Analyze offsets on 'this'
                for m in ptr_offset_re.finditer(body):
                    ptr_name = m.group(2)
                    offset_str = m.group(3)
                    if ptr_name == 'this':
                        try:
                            offset = int(offset_str, 0)
                            if offset not in structs[class_name]['offsets']:
                                structs[class_name]['offsets'][offset] = Counter()
                            structs[class_name]['offsets'][offset][m.group(1).strip()] += 1
                        except ValueError: continue

                # 2. Analyze zero offsets on 'this'
                for m in ptr_zero_re.finditer(body):
                    ptr_name = m.group(2)
                    if ptr_name == 'this':
                        offset = 0
                        if offset not in structs[class_name]['offsets']:
                            structs[class_name]['offsets'][offset] = Counter()
                        structs[class_name]['offsets'][offset][m.group(1).strip()] += 1
                
                # 3. Save function signature
                clean_sig = signature
                
                # REMOVE DECOMPILER WARNINGS
                # Match /* WARNING: ... */ and remove it
                clean_sig = re.sub(r'/\* WARNING:.*?\*/', '', clean_sig, flags=re.DOTALL)
                
                paren_pos = clean_sig.find('(')
                if paren_pos != -1:
                    colon_pos = clean_sig.rfind('::', 0, paren_pos)
                    if colon_pos != -1:
                        method_part = clean_sig[colon_pos+2:]
                        start_pos = colon_pos
                        bracket_level = 0
                        while start_pos > 0:
                            char = clean_sig[start_pos - 1]
                            if char == '>': bracket_level += 1
                            elif char == '<': bracket_level -= 1
                            elif bracket_level == 0 and char in (' ', '\n', '\t', '\r'): break
                            start_pos -= 1
                        return_type_part = clean_sig[:start_pos].strip()
                        clean_sig = f"{return_type_part} {method_part}" if return_type_part else method_part
                
                clean_sig = re.sub(r'\s+', ' ', clean_sig).strip()
                if clean_sig not in structs[class_name]['functions']:
                    structs[class_name]['functions'].append(clean_sig)

    return structs

def save_struct_data(structs, output_file):
    if not os.path.isabs(output_file):
        output_file = os.path.join(SCRIPT_DIR, output_file)
    serializable = {}
    for name, data in structs.items():
        serializable[name] = {
            'offsets': {str(k): dict(v) for k, v in data['offsets'].items()},
            'functions': data['functions']
        }
    with open(output_file, 'w') as f:
        json.dump(serializable, f, indent=2)

if __name__ == "__main__":
    src_dir = sys.argv[1] if len(sys.argv) > 1 else "../src"
    structs = analyze_src(src_dir)
    save_struct_data(structs, "reconstructed_structs.json")
    print("Done.")
