import re
import os

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

# Fix GmVec3 vs void* mistake
code = code.replace("in_stack_ffffff94 = (void*)0;", "in_stack_ffffff94 = GmVec3(0,0,0);")
code = code.replace("fVar15 = GmVec3(0,0,0);", "fVar15 = 0;")
code = code.replace("in_stack_ffffffcc = (CFastBuffer<void*> *)(*(float*)((char*)(size_t)pGVar5 + 4) + 0.0);", "in_stack_ffffffcc = (void*)(size_t)(*(float*)((char*)(size_t)pGVar5 + 4) + 0.0);")

# Fix missing cast for abs
code = code.replace("(int *)std::abs", "(int *)(size_t)std::abs")
code = code.replace("(float *)std::abs", "(float *)(size_t)std::abs")
code = code.replace("param_12 = (float *)(((float)", "param_12 = (float *)(size_t)(((float)")
code = code.replace("pfVar22 = (float *)(float)", "pfVar22 = (float *)(size_t)(float)")

# Missing variables - explicitly add them where fStack_8 is declared
if "float fStack_8=0, fStack_14=0;" in code:
    if "float in_stack_00000040=0;" not in code:
        code = code.replace("float fStack_8=0, fStack_14=0;", "float fStack_8=0, fStack_14=0;\n    float in_stack_00000040=0, in_stack_00000048=0, in_stack_00000044=0, in_stack_00000054=0, in_stack_00000060=0, fStack0000004c=0;")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
