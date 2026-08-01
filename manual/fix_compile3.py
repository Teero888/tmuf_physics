import re

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    lines = f.readlines()

new_lines = []
for line in lines:
    if "pCVar4 =" in line and "pSVar7" in line:
        continue
    if "in_stack_ffffffc0 =" in line and "param_6" in line:
        continue
    if "in_stack_ffffffc0 =" in line and "iVar9" in line:
        continue
    new_lines.append(line)

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.writelines(new_lines)
