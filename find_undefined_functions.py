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

    # Regex for our specific dump headers: // Function: ClassName::MethodName
    header_pattern = re.compile(r'^// Function: (.*)$')

    cpp_files = []
    for dp, dn, fn in os.walk(root_dir):
        for f in fn:
            if f.endswith('.cpp'):
                cpp_files.append(os.path.join(dp, f))

    for file_path in cpp_files:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
            lines = content.splitlines()
            
            # Step 1: Find definitions using headers
            for line in lines:
                header_match = header_pattern.match(line.strip())
                if header_match:
                    func_name = header_match.group(1).strip()
                    # Normalize by removing template arguments for consistent matching
                    normalized_name = re.sub(r'<.*?>', '', func_name)
                    defined_functions.add(normalized_name)

            # Step 2: Find calls (any qualified name that isn't part of a definition header)
            # We skip the headers to avoid double counting definitions as calls
            for line in lines:
                if line.strip().startswith('//'):
                    continue
                
                for match in func_pattern.finditer(line):
                    func_name = match.group(1)
                    normalized_name = re.sub(r'<.*?>', '', func_name)
                    called_functions.add(normalized_name)

    # Functions that are called but not in our defined set
    undefined_functions = called_functions - defined_functions

    if undefined_functions:
        print(f"Total defined: {len(defined_functions)}")
        print(f"Total called: {len(called_functions)}")
        print(f"\nCalled but not defined functions ({len(undefined_functions)}):")
        for func in sorted(list(undefined_functions)):
            print(func)
    else:
        print("No called but not defined functions found.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python find_undefined_functions.py <path_to_src_directory>")
        sys.exit(1)
    
    src_directory = sys.argv[1]
    if not os.path.isdir(src_directory):
        print(f"Error: Directory not found at {src_directory}")
        sys.exit(1)
        
    analyze_files(src_directory)
