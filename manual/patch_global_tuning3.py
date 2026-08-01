import re

with open("scratch_ComputeForcesModel3.cpp", "r") as f:
    orig = f.read()

orig = orig.replace("((uint32_t)(uintptr_t)g_tuning)", "((uintptr_t)g_tuning)")

with open("scratch_ComputeForcesModel3.cpp", "w") as f:
    f.write(orig)
print("Patched global tuning 3")
