import re
import os
import sys
import json

# Resolve absolute paths relative to this script's location
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

def analyze_src(src_dir):
    # If path is relative, resolve it relative to SCRIPT_DIR
    if not os.path.isabs(src_dir):
        src_dir = os.path.join(SCRIPT_DIR, src_dir)
        
    ptr_offset_re = re.compile(r'\*\s*\(([\w\s\*:]+)\s*\*\)\s*\(([\w]+)\s*\+\s*(0x[0-9a-fA-F]+|[0-9]+)\)')
    structs = {}

    cpp_files = []
    for dp, dn, fn in os.walk(src_dir):
        for f in fn:
            if f.endswith('.cpp') and f != 'Globals.cpp':
                cpp_files.append(os.path.join(dp, f))

    print(f"Analyzing {len(cpp_files)} files in {src_dir}...")
    for file_path in cpp_files:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
            header_match = re.search(r'// Function: (.*?)$', content, re.MULTILINE)
            if not header_match: continue
            
            full_func_name = header_match.group(1).strip()
            if "::" not in full_func_name: continue
            
            class_name = full_func_name.rsplit("::", 1)[0].strip().lstrip(": ")
            if class_name not in structs:
                structs[class_name] = {'offsets': {}, 'functions': []}
            
            for match in ptr_offset_re.finditer(content):
                data_type = match.group(1).strip()
                offset_str = match.group(3)
                try:
                    offset = int(offset_str, 0)
                except ValueError: continue
                    
                if offset not in structs[class_name]['offsets']:
                    structs[class_name]['offsets'][offset] = {'types': set(), 'count': 0}
                structs[class_name]['offsets'][offset]['types'].add(data_type)
                structs[class_name]['offsets'][offset]['count'] += 1

            pattern = r'// =+\n// Function: (.*?)\n// =+\n(.*?)\n\{'
            for match in re.finditer(pattern, content, re.DOTALL):
                signature = match.group(2).strip()
                clean_sig = signature
                if "::" in clean_sig:
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
                structs[class_name]['functions'].append(clean_sig)

    return structs

def save_struct_data(structs, output_file):
    if not os.path.isabs(output_file):
        output_file = os.path.join(SCRIPT_DIR, output_file)
        
    serializable = {}
    for name, data in structs.items():
        serializable[name] = {
            'offsets': {str(k): {'types': list(v['types']), 'count': v['count']} for k, v in data['offsets'].items()},
            'functions': data['functions']
        }
    with open(output_file, 'w') as f:
        json.dump(serializable, f, indent=2)

if __name__ == "__main__":
    src_dir = sys.argv[1] if len(sys.argv) > 1 else "../src"
    structs = analyze_src(src_dir)
    
    # Text output for sanity check
    output_h = os.path.join(SCRIPT_DIR, "reconstructed_structs.h")
    with open(output_h, 'w') as f:
        f.write("// Reconstructed structs with hierarchy\n\n")
        for class_name in sorted(structs.keys()):
            f.write(f"struct {class_name} {{ ... }};\n")
            
    save_struct_data(structs, "reconstructed_structs.json")
    print("Done.")
