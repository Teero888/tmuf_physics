import re

with open("scratch_ComputeForcesModel3.cpp", "r") as f:
    orig = f.read()

orig = orig.replace("this->m_field_64", "((uint32_t)(uintptr_t)g_tuning)")

top_decl = "extern CSceneVehicleCarTuning* g_tuning;\n"
orig = top_decl + orig

with open("scratch_ComputeForcesModel3.cpp", "w") as f:
    f.write(orig)

with open("main.cpp", "r") as f:
    main_code = f.read()
    
main_code = "CSceneVehicleCarTuning* g_tuning = nullptr;\n" + main_code
main_code = main_code.replace("car->m_field_64 = (uint32_t)(size_t)tuning;", "car->m_field_64 = 0; g_tuning = tuning;")

with open("main.cpp", "w") as f:
    f.write(main_code)

print("Patched global tuning")
