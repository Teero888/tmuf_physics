import re

with open("main.cpp", "r") as f:
    orig = f.read()

orig = orig.replace("CSceneVehicleCarTuning* tuning = new CSceneVehicleCarTuning();", "static CSceneVehicleCarTuning static_tuning;\n    CSceneVehicleCarTuning* tuning = &static_tuning;")

with open("main.cpp", "w") as f:
    f.write(orig)

print("Patched tuning")
