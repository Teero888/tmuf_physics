import re

with open("scratch_ComputeForcesModel3.cpp", "r") as f:
    orig = f.read()

orig = orig.replace("extern CSceneVehicleCarTuning* g_tuning;\n", "")
orig = orig.replace("#include <cstdint>\n", "#include <cstdint>\nextern class CSceneVehicleCarTuning* g_tuning;\n")

with open("scratch_ComputeForcesModel3.cpp", "w") as f:
    f.write(orig)

print("Patched global tuning 2")
