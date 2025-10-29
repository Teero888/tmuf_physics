
import re
import os
import sys

def analyze_files(root_dir):
    defined_functions = set()
    called_functions = set()

    # Regex to find C++ qualified function names.
    # Handles: MyClass::MyFunc, MyClass::~MyFunc, MyClass<T>::Func,
    # MyClass::`vector deleting destructor`, MyClass::operator[]
    func_pattern = re.compile(r'([a-zA-Z_][\w<>]*::(?:~?\w+|`[^`]+`|operator\s*\[\]))')

    cpp_files = []
    for dp, dn, fn in os.walk(root_dir):
        for f in fn:
            if f.endswith('.cpp'):
                cpp_files.append(os.path.join(dp, f))

    for file_path in cpp_files:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            lines = f.readlines()
            for i, line in enumerate(lines):
                # Heuristic for a definition line:
                # - Contains __thiscall or __cdecl
                # - Is followed by an opening brace on the next line
                is_definition = False
                if '::' in line and '(' in line:
                    if '__thiscall' in line or '__cdecl' in line:
                        is_definition = True
                    elif i + 1 < len(lines) and lines[i+1].strip() == '{':
                        is_definition = True

                for match in func_pattern.finditer(line):
                    func_name = match.group(1)
                    # Normalize by removing template arguments for consistent matching
                    normalized_name = re.sub(r'<.*?>', '', func_name)
                    
                    if is_definition:
                        defined_functions.add(normalized_name)
                    else:
                        # Basic check to avoid commented out code
                        if not line.strip().startswith('//') and not line.strip().startswith('/*'):
                            called_functions.add(normalized_name)

    undefined_functions = called_functions - defined_functions

    if undefined_functions:
        print("Called but not defined functions:")
        for func in sorted(list(undefined_functions)):
            print(func)
    else:
        print("No called but not defined functions found.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <path_to_src_directory>")
        sys.exit(1)
    
    src_directory = sys.argv[1]
    if not os.path.isdir(src_directory):
        print(f"Error: Directory not found at {src_directory}")
        sys.exit(1)
        
    analyze_files(src_directory)
