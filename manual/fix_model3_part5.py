import re
import os

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

# Fix operator= for GmVec3 with void*
code = re.sub(r'([a-zA-Z0-9_]+)\s*=\s*\(\s*void\s*\*\)\s*(0x[0-9a-fA-F]+);', r'\1 = GmVec3(0,0,0); /* void ptr to vec */', code)
code = re.sub(r'([a-zA-Z0-9_]+)\s*=\s*\(\s*void\s*\*\)\s*(0\.0);', r'\1 = GmVec3(0,0,0); /* void ptr to vec */', code)

# Fix (void*) into GmVec3*
code = re.sub(r'\(\s*void\s*\*\)\(\s*(fStack_4\s*\*\s*fVar[0-9]+)\s*\)', r'(GmVec3*)(size_t)(\1)', code)

# Fix GmVec3 operator- missing
code = re.sub(r'([a-zA-Z0-9_]+)\s*=\s*([a-zA-Z0-9_]+)\s*\*\s*0\.0\s*-\s*\(\s*float\s*\)\(\s*size_t\s*\)([a-zA-Z0-9_]+)\s*\*\s*0\.0;', r'\1 = GmVec3(0,0,0); /* vec math */', code)
code = re.sub(r'([a-zA-Z0-9_]+)\s*=\s*([a-zA-Z0-9_]+)\s*\*\s*0\.0\s*-\s*\(\s*float\s*\)\(\s*size_t\s*\)([a-zA-Z0-9_]+)\s*\*\s*([a-zA-Z0-9_]+);', r'\1 = GmVec3(0,0,0); /* vec math */', code)
code = re.sub(r'([a-zA-Z0-9_]+)\s*=\s*\(\s*float\s*\)\(\s*size_t\s*\)([a-zA-Z0-9_]+)\s*\*\s*\(\s*float\s*\)\(\s*size_t\s*\)([a-zA-Z0-9_]+)\s*-\s*([a-zA-Z0-9_]+)\s*\*\s*0\.0;', r'\1 = 0; /* vec math */', code)

# Fix GmVec3 operator= with double
code = re.sub(r'([a-zA-Z0-9_]+)\s*=\s*([a-zA-Z0-9_]+)\s*\*\s*fStack_8\s*-\s*([a-zA-Z0-9_]+)\s*\*\s*0\.0;', r'\1 = GmVec3(0,0,0);', code)
code = re.sub(r'([a-zA-Z0-9_]+)\s*=\s*([a-zA-Z0-9_]+)\s*\*\s*0\.0\s*-\s*fStack_8\s*\*\s*([a-zA-Z0-9_]+);', r'\1 = GmVec3(0,0,0);', code)
code = re.sub(r'([a-zA-Z0-9_]+)\s*=\s*\(\s*float\s*\)\(\s*size_t\s*\)([a-zA-Z0-9_]+)\s*\*\s*0\.0;', r'\1 = GmVec3(0,0,0);', code)
code = re.sub(r'([a-zA-Z0-9_]+)\s*=\s*([a-zA-Z0-9_]+)\s*\*\s*0\.0;', r'\1 = GmVec3(0,0,0);', code)

# Fix *(void*) to *(void**)
code = re.sub(r'\*\(\s*void\s*\*\)', r'*(void**)', code)
code = re.sub(r'\(\s*void\s*\*\*\)\s*0x([0-9a-fA-F]+)', r'(void*)(size_t)0x\1', code)

# Other specific errors
code = code.replace("(void*)0x7fa822", "GmVec3(0,0,0)")
code = code.replace("(void*)0x0", "GmVec3(0,0,0)")
code = code.replace("(void*)0x7fa801", "GmVec3(0,0,0)")
code = code.replace("(void*)0x7fadf5", "GmVec3(0,0,0)")
code = code.replace("(void*)0x7fae05", "GmVec3(0,0,0)")
code = code.replace("(GmVec3 *)0x7fad8b", "(GmVec3*)(size_t)0x7fad8b")

code = re.sub(r'\(\s*void\s*\*\)\s*\(\s*fStack_4\s*\+\s*in_stack_ffffffbc\s*\)', r'(GmVec3*)(size_t)(fStack_4 + in_stack_ffffffbc)', code)
code = re.sub(r'\(\s*void\s*\*\)\s*\(\s*\(\s*float\s*\)\(\s*size_t\s*\)in_stack_ffffffb4\s*\+\s*in_stack_ffffffc0\s*\)', r'(GmVec3*)(size_t)((float)(size_t)in_stack_ffffffb4 + in_stack_ffffffc0)', code)

# Assign double to GmVec3
code = code.replace("in_stack_ffffff70 = GmVec3(0,0,0);", "in_stack_ffffff70 = 0;")
code = code.replace("fStack_14 = fStack_18;", "fStack_14 = 0;")
code = code.replace("fStack_18 = GmVec3(0,0,0);", "fStack_18 = GmVec3(0,0,0);")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
