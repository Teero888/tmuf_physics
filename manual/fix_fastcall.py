import re
import sys

def analyze_file(path):
    with open(path, 'r') as f:
        content = f.read()

    # Find all DUMMY_CFAST_CALL(...) allowing newlines
    matches = re.finditer(r'DUMMY_CFAST_CALL\s*\(\s*(.*?)\s*\)', content, re.DOTALL)
    for m in matches:
        args = m.group(1).split(',')
        print(f"Match: {args}")

if __name__ == "__main__":
    analyze_file("scratch_ComputeForcesModel3.cpp")
