import re
import os
import sys

# Resolve absolute paths relative to this script's location
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

def analyze_files(root_dir):
    if not os.path.isabs(root_dir): root_dir = os.path.join(SCRIPT_DIR, root_dir)
    defined_functions = set()
    called_functions = set()
    func_pattern = re.compile(r'([a-zA-Z_][\w<>]*::(?:~?\w+|`[^`]+`|operator\s*\[\]))')
    header_pattern = re.compile(r'^// Function: (.*)$')
    cpp_files = []
    for dp, dn, fn in os.walk(root_dir):
        for f in fn:
            if f.endswith('.cpp'): cpp_files.append(os.path.join(dp, f))
    for file_path in cpp_files:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
            lines = content.splitlines()
            for line in lines:
                header_match = header_pattern.match(line.strip())
                if header_match:
                    func_name = header_match.group(1).strip()
                    normalized_name = re.sub(r'<.*?>', '', func_name)
                    defined_functions.add(normalized_name)
            for line in lines:
                if line.strip().startswith('//'): continue
                for match in func_pattern.finditer(line):
                    func_name = match.group(1)
                    normalized_name = re.sub(r'<.*?>', '', func_name)
                    called_functions.add(normalized_name)
    undefined_functions = called_functions - defined_functions
    if undefined_functions:
        print(f"Total defined: {len(defined_functions)}")
        print(f"Total called: {len(called_functions)}")
        print(f"\nCalled but not defined functions ({len(undefined_functions)}):")
        for func in sorted(list(undefined_functions)): print(func)
    else: print("No called but not defined functions found.")

if __name__ == "__main__":
    src_directory = sys.argv[1] if len(sys.argv) > 1 else "../src"
    analyze_files(src_directory)
