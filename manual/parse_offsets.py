import re

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    content = f.read()

offsets = set(re.findall(r'\*\(\w+\s*\*\)\(\*\(\w+\*\)\(size_t\)(p[a-zA-Z0-9_]+) \+ (0x[0-9a-f]+)\)', content))
for var, offset in sorted(offsets):
    print(f"{var} -> {offset}")

offsets_direct = set(re.findall(r'\*\(\w+\s*\*\)\(\(int\)\(size_t\)(in_stack[a-zA-Z0-9_]*) \+ (0x[0-9a-f]+)\)', content))
for var, offset in sorted(offsets_direct):
    print(f"{var} -> {offset}")
