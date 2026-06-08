import re

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

code = code.replace("unaff_EBX = (void*)0;", "unaff_EBX = GmVec3(0,0,0);")

lines = code.split('\n')
for i, line in enumerate(lines):
    if line.strip() == "0;":
        # Look around to see if it's the 0; that replaced (GmVec3*)(...)
        lines[i] = line.replace("0;", "GmVec3(0,0,0);")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write('\n'.join(lines))
