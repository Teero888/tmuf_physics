import re

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

code = code.replace("#define DUMMY_CFAST_CALL(...) (0.0f)", "#define DUMMY_CFAST_CALL(...) 0")
code = code.replace("pCVar6 = GmVec3(0,0,0); //", "pCVar6 = (void*)0; //")
code = code.replace("unaff_EBX = GmVec3(0,0,0);", "unaff_EBX = (void*)0;")
code = code.replace("0.0f;", "0;")
code = code.replace("in_stack_ffffffb4 = (void *)(size_t)-(float)(size_t)extraout_ST0_00;", "in_stack_ffffffb4 = (float)(size_t)extraout_ST0_00;")
code = code.replace("(int *)(-*(float *)(*(int*)(size_t)pSVar10 + 0xa4)", "(int *)(size_t)(-*(float *)(*(int*)(size_t)pSVar10 + 0xa4)")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
