import re
import os

# Fix tuning methods
with open('Scene/CSceneVehicleCarTuning.cpp', 'r') as f:
    code = f.read()

code = re.sub(r'float CSceneVehicleCarTuning::GetLateralContactSlowDownFromSpeed.*?\n}', '', code, flags=re.DOTALL)
code = re.sub(r'float CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed.*?\n}', '', code, flags=re.DOTALL)

with open('Scene/CSceneVehicleCarTuning.cpp', 'w') as f:
    f.write(code)

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

# Replace any void* <-> GmVec3
code = code.replace("GmVec3(0,0,0); /* void ptr to vec */", "(void*)0;")
code = code.replace("if (pCVar6 != GmVec3(0,0,0)) {", "if (pCVar6 != nullptr) {")
code = code.replace("if (pCVar21 != GmVec3(0,0,0)) {", "if (pCVar21 != nullptr) {")
code = code.replace("unaff_EBX = *(void**)pSVar8;", "unaff_EBX = GmVec3(0,0,0);")
code = code.replace("in_stack_ffffff94 = *(void**)(iVar1 + 0x24);", "in_stack_ffffff94 = GmVec3(0,0,0);")
code = code.replace("in_stack_ffffffcc = *(void**)(param_6 + 8);", "in_stack_ffffffcc = *(GmVec3*)(param_6 + 8);")
code = code.replace("unaff_EBX = (GmVec3*)(size_t)(fStack_4 + in_stack_ffffffbc);", "unaff_EBX = GmVec3(0,0,0);")
code = code.replace("(GmVec3*)(size_t)((float)(size_t)in_stack_ffffffb4 + in_stack_ffffffc0);", "0.0f;")
code = code.replace("unaff_EBX = (GmVec3*)(size_t)(fStack_4 * fVar19);", "unaff_EBX = GmVec3(0,0,0);")
code = code.replace("(GmVec3*)(size_t)(fStack_4 * fVar20);", "0;")

# in_stack_0000006c
code = code.replace("int* in_stack_0000006c = nullptr;", "int* in_stack_0000003c = nullptr;")
code = code.replace("in_stack_0000006c", "in_stack_0000003c")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)

