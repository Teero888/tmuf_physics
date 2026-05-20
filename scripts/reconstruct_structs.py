import re
import os
import sys
import json

# Resolve absolute paths relative to this script's location
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

def analyze_src(src_dir):
    if not os.path.isabs(src_dir):
        src_dir = os.path.join(SCRIPT_DIR, src_dir)
        
    ptr_offset_re = re.compile(r'\*\s*\(([\w\s\*:]+)\s*\*\)\s*\(\s*(?:\(int\))?\s*([\w]+)\s*\+\s*(0x[0-9a-fA-F]+|[0-9]+)\s*\)')
    ptr_zero_re = re.compile(r'\*\s*\(([\w\s\*:]+)\s*\*\)\s*([\w]+)\b')
    
    structs = {} # name -> {'offsets': {}, 'functions': []}

    cpp_files = []
    for dp, dn, fn in os.walk(src_dir):
        for f in fn:
            if f.endswith('.cpp') and f != 'Globals.cpp':
                cpp_files.append(os.path.join(dp, f))

    print(f"Analyzing {len(cpp_files)} files in {src_dir}...")
    for file_path in cpp_files:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
            
            # Find all function blocks
            # Pattern: // =+ // Function: ... // =+ Signature { body }
            pattern = r'// =+\n// Function: (.*?)\n// =+\n(.*?)\n\{(.*?)\n\}'
            for match in re.finditer(pattern, content, re.DOTALL):
                header_name = match.group(1).strip()
                signature = match.group(2).strip()
                body = match.group(3)
                
                # 1. Parse signature to get parameter types
                # Example: void __thiscall GmVec3::Mult(void *this,GmIso3 *param_1,GmIso3 *param_2)
                type_map = {} # ptr_name -> struct_name
                
                # Extract class name from header
                if "::" in header_name:
                    current_class = header_name.rsplit("::", 1)[0].strip().lstrip(": ")
                    type_map['this'] = current_class
                
                # Extract params
                # Regex for (Type *Name, ...)
                param_re = re.compile(r'([\w<>:]+)\s*\*+([\w]+)\b')
                for p_match in param_re.finditer(signature):
                    p_type = p_match.group(1).strip()
                    p_name = p_match.group(2).strip()
                    if p_type not in ['void', 'int', 'char', 'float', 'undefined', 'undefined4']:
                        type_map[p_name] = p_type

                # 2. Analyze offsets in body
                for m in ptr_offset_re.finditer(body):
                    ptr_name = m.group(2)
                    offset_str = m.group(3)
                    if ptr_name in type_map:
                        target_class = type_map[ptr_name]
                        if target_class not in structs: structs[target_class] = {'offsets': {}, 'functions': []}
                        
                        try:
                            offset = int(offset_str, 0)
                            if offset not in structs[target_class]['offsets']:
                                structs[target_class]['offsets'][offset] = {'types': set(), 'count': 0}
                            structs[target_class]['offsets'][offset]['types'].add(m.group(1).strip())
                            structs[target_class]['offsets'][offset]['count'] += 1
                        except ValueError: continue

                # 3. Analyze zero offsets
                for m in ptr_zero_re.finditer(body):
                    ptr_name = m.group(2)
                    if ptr_name in type_map:
                        target_class = type_map[ptr_name]
                        if target_class not in structs: structs[target_class] = {'offsets': {}, 'functions': []}
                        
                        offset = 0
                        if offset not in structs[target_class]['offsets']:
                            structs[target_class]['offsets'][offset] = {'types': set(), 'count': 0}
                        structs[target_class]['offsets'][offset]['types'].add(m.group(1).strip())
                        structs[target_class]['offsets'][offset]['count'] += 1
                
                # 4. Save function signature to its class
                if "::" in header_name:
                    class_name = header_name.rsplit("::", 1)[0].strip().lstrip(": ")
                    if class_name not in structs: structs[class_name] = {'offsets': {}, 'functions': []}
                    
                    # Clean signature
                    clean_sig = signature
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
    save_struct_data(structs, "reconstructed_structs.json")
    print("Done.")
