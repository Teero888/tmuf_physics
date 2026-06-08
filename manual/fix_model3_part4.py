import re
import os

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

decls = """
    int* in_stack_0000006c = nullptr;
    float in_stack_00000040=0, in_stack_00000048=0, in_stack_00000044=0, in_stack_00000054=0, in_stack_00000060=0, fStack0000004c=0;
"""
code = code.replace("int* in_stack_0000006c = nullptr;", decls)

code = re.sub(r'CFastBuffer<void\*>::GetCount[^;]+;', '0;', code)

# Clean up GetMaxSideFrictionFromSpeed
code = re.sub(r'->GetMaxSideFrictionFromSpeed\s*\([^,]+,[^,]+,\s*([^)]+)\)', r'->GetMaxSideFrictionFromSpeed(\1)', code)

# Clean up GetSteerSlowDownFromSpeed
# Wait, GetSteerSlowDownFromSpeed doesn't exist?
code = code.replace("->GetSteerSlowDownFromSpeed", "->GetSteerDriveTorqueFromSpeed")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
