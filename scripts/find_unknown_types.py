import re
import os
import sys

def find_unknown_types(include_dir):
    # Standard types
    known_types = {
        'void', 'int', 'char', 'float', 'double', 'long', 'short', 'unsigned', 'signed',
        'bool', 'uint', 'ulong', 'ushort', 'uchar', 'byte', 'word', 'dword', 'qword',
        'longlong', 'undefined', 'undefined1', 'undefined2', 'undefined3', 'undefined4', 
        'undefined5', 'undefined6', 'undefined7', 'undefined8', 'code', 'float10',
        '__int64', '__uint64', 'TimeInt32', 'wchar_t'
    }
    
    # Nadeo structs - Parse ALL defined structs in headers (including nested)
    struct_def_re = re.compile(r'struct\s+(\w+)\b')
    
    for f in os.listdir(include_dir):
        if f.endswith('.hpp'):
            with open(os.path.join(include_dir, f), 'r', encoding='utf-8', errors='ignore') as file:
                content = file.read()
                # Find all struct definitions in this header
                for match in struct_def_re.finditer(content):
                    known_types.add(match.group(1))
            
    unknown_types = set()
    type_re = re.compile(r'\b([a-zA-Z_]\w+)\b')
    
    for f in os.listdir(include_dir):
        if f.endswith('.hpp'):
            with open(os.path.join(include_dir, f), 'r', encoding='utf-8', errors='ignore') as file:
                content = file.read()
                # Remove comments
                content = re.sub(r'//.*', '', content)
                content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
                
                for match in type_re.finditer(content):
                    t = match.group(1)
                    if t not in known_types and not t.isupper() and not t.isdigit():
                        if re.match(r'^[CSE][A-Z]', t):
                             unknown_types.add(t)

    return unknown_types

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python find_unknown_types.py <new_include_dir>")
        sys.exit(1)
    
    include_dir = sys.argv[1]
    unknown = find_unknown_types(include_dir)
    print("Potential unknown types (mostly Enums or missing structs):")
    for t in sorted(list(unknown)):
        print(t)
