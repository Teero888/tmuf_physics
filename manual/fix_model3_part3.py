import re
import os

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

code = code.replace("int* in_stack_0000003c = nullptr;", "int* in_stack_0000003c = nullptr;\n    int* in_stack_0000006c = nullptr;")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
