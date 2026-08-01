import re
with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

# Fix fStack_c redeclaration at top
code = code.replace("fStack_4=0, fStack_c=0;", "fStack_4=0;")

# Fix fStack_8, fStack_14 redeclaration
code = code.replace("float fStack_8=0, fStack_14=0;", "fStack_8=0; fStack_14=0;")

# Fix WheelAddForceToVehicle
code = code.replace(
    "(SSimulationWheel*)param_4, (GmVec3*)unaff_EBP",
    "(SSimulationWheel*)(size_t)param_4, &unaff_EBP"
)

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
