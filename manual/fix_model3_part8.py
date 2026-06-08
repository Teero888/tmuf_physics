import re
import os

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

# Fix GmVec3 vs size_t casts
code = code.replace("(size_t)in_stack_ffffff94", "(*(size_t*)&in_stack_ffffff94)")
code = code.replace("(size_t)in_stack_ffffffb8", "(*(size_t*)&in_stack_ffffffb8)")
code = code.replace("(size_t)in_stack_ffffffbc", "(*(size_t*)&in_stack_ffffffbc)")
code = code.replace("(size_t)in_stack_ffffffc0", "(*(size_t*)&in_stack_ffffffc0)")
code = code.replace("(size_t)in_stack_ffffffc4", "(*(size_t*)&in_stack_ffffffc4)")
code = code.replace("(size_t)in_stack_ffffffc8", "(*(size_t*)&in_stack_ffffffc8)")
code = code.replace("(size_t)in_stack_ffffffcc", "(*(size_t*)&in_stack_ffffffcc)")
code = code.replace("(size_t)unaff_EBP", "(*(size_t*)&unaff_EBP)")
code = code.replace("(size_t)unaff_EBX", "(*(size_t*)&unaff_EBX)")
code = code.replace("(size_t)fStack_18", "(*(size_t*)&fStack_18)")

# float to SBlendableVals*
code = code.replace("param_10 = (SBlendableVals *)(fVar15", "param_10 = (SBlendableVals *)(size_t)(fVar15")
code = code.replace("param_10 = (SBlendableVals *)", "param_10 = (SBlendableVals *)(size_t)")

# float to int*
code = code.replace("(int *)(*(float *)", "(int *)(size_t)(*(float *)")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
