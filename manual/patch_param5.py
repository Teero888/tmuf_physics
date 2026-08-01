import re

with open("scratch_ComputeForcesModel3_patched.cpp", "r") as f:
    code = f.read()

# Fix the std::abs on a pointer:
code = code.replace("pCVar4 = (CSceneVehicleCarTuning *)(size_t)std::abs((float)(size_t)in_stack_ffffffa0);",
                    "pCVar4 = (CSceneVehicleCarTuning *)(size_t)std::abs(*(float*)((char*)(size_t)this->m_field_64 + 0x24));")

# Fix the param_5 calculation to not multiply by 0:
code = re.sub(r'param_5 = fVar15 \* \(float\)\(size_t\)pCVar4 \*[^;]+;',
              'param_5 = fVar15 * (float)(size_t)pCVar4 * fVar13;', code)

with open("scratch_ComputeForcesModel3_patched2.cpp", "w") as f:
    f.write(code)

print("Patched param_5")
