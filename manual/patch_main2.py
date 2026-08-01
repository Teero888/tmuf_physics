import re

with open("main.cpp", "r") as f:
    orig = f.read()

orig = orig.replace("CSceneVehicleCarTuning* g_tuning = nullptr;\n", "")
orig = orig.replace("extern \"C\" {", "class CSceneVehicleCarTuning;\nCSceneVehicleCarTuning* g_tuning = nullptr;\n\nextern \"C\" {")

with open("main.cpp", "w") as f:
    f.write(orig)
print("Patched main 2")
