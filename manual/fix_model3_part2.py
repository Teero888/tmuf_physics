import re
import os

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

code = code.replace("CFastBuffer<void<unsigned_short>_>::operator[]", "DUMMY_CFAST_CALL")

# Fix missing (size_t) before pointer casts in assignments
code = re.sub(r'\(int \*\)\(\*\s*\(float', r'(int *)(size_t)(*(float', code)
code = re.sub(r'\(float \*\)\(\*\s*\(float', r'(float *)(size_t)(*(float', code)
code = re.sub(r'\(float \*\)in_stack_', r'(float *)(size_t)in_stack_', code)
code = re.sub(r'\(float \*\)\(in_stack_', r'(float *)(size_t)(in_stack_', code)
code = re.sub(r'\(SBlendableVals \*\)\n\s*\(\(', r'(SBlendableVals *)(size_t)((', code)

# Fix *(void*)(iVar9 + 0x24) -> *(void**)((char*)(size_t)iVar9 + 0x24)
code = re.sub(r'\*\(\s*void\s*\*\)\(\s*iVar9\s*\+\s*0x24\s*\)', r'*(void**)((char*)(size_t)iVar9 + 0x24)', code)
code = re.sub(r'\*\(\s*void\s*\*\)\(\s*\(\s*int\s*\)\(\s*size_t\s*\)this->m_field_64\s*\+\s*0x24\s*\)', r'*(void**)((char*)(size_t)this->m_field_64 + 0x24)', code)


with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
