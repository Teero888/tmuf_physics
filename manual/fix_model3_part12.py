import re

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

code = code.replace("(GmVec3 *)\n            GmVec3(0,0,0);", "(GmVec3 *)0;")
code = code.replace("pCVar21 = (void*)\n                GmVec3(0,0,0);", "pCVar21 = (void*)0;")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
