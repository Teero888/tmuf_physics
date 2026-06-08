import re

with open('../tmnf_dump/src/CHmsZoneDynamic.cpp', 'r') as f:
    lines = f.readlines()

start_idx = -1
end_idx = -1
for i, line in enumerate(lines):
    if "CHmsZoneDynamic::ComputeCollisionResponse" in line and "void __thiscall" in lines[i-1]:
        start_idx = i - 1
    if start_idx != -1 and line.startswith("}") and i > start_idx + 10:
        if lines[i-1].startswith("}"):
            end_idx = i + 1
            break

if start_idx == -1 or end_idx == -1:
    print("Could not find ComputeCollisionResponse")
    exit(1)

code = "".join(lines[start_idx:end_idx])

with open('scratch_ComputeCollisionResponse.cpp', 'w') as f:
    f.write(code)

print("Saved to scratch_ComputeCollisionResponse.cpp")
