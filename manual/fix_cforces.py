import re
with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

code = code.replace("GmVec3 cforce1(*(float*)&param_12, 0, 0);", "GmVec3 cforce1(0.0f, 0.0f, in_stack_00000070);")
code = code.replace("GmVec3 cforce1(*(float*)&param_12, 0.0f, 0.0f);", "GmVec3 cforce1(0.0f, 0.0f, in_stack_00000070);")

code = code.replace("GmVec3 cforce2(param_8, (float)param_9, 0);", "GmVec3 cforce2(0.0f, 0.0f, *(float*)&param_10);")
code = code.replace("GmVec3 cforce2(param_8, (float)param_9, 0.0f);", "GmVec3 cforce2(0.0f, 0.0f, *(float*)&param_10);")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
