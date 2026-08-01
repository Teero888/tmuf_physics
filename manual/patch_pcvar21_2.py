import re

with open("scratch_ComputeForcesModel3.cpp", "r") as f:
    lines = f.readlines()

for i in range(len(lines)):
    if "pCVar21 = (void*)0;" in lines[i]:
        if i != 104: # line 105 is index 104
            lines[i] = lines[i].replace("pCVar21 = (void*)0;", "// pCVar21 = (void*)0;")

with open("scratch_ComputeForcesModel3.cpp", "w") as f:
    f.writelines(lines)
print("Patched pCVar21 2")
