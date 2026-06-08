import re

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

# Fix bool
if "bool bVar2 = false;" not in code:
    code = code.replace("float in_stack_00000040=0,", "bool bVar2 = false;\n    float in_stack_00000040=0,")

code = code.replace("pCVar6 = (void*)", "pCVar6 = GmVec3(0,0,0); //")
code = code.replace("dVar24 = (double)(size_t)(uint64_t)(size_t)(in_stack_ffffffb0,in_stack_ffffffac);", "dVar24 = 0;")
code = code.replace("unaff_EBX = (void*)0;", "unaff_EBX = GmVec3(0,0,0);")
code = code.replace("(GmVec3*)(size_t)(fStack_4 * fVar20);", "GmVec3(0,0,0);")
code = code.replace("in_stack_ffffffb4 = (void *)-(float)(size_t)extraout_ST0_00;", "in_stack_ffffffb4 = (void *)(size_t)-(float)(size_t)extraout_ST0_00;")
code = code.replace("fStack_4 = (float)(float*)0 * (float)(size_t)in_stack_ffffffb4;", "fStack_4 = 0.0f;")
code = code.replace("unaff_EBX = (GmVec3*)(size_t)(fStack_4 * fVar19);", "unaff_EBX = GmVec3(0,0,0);")
code = code.replace("pCVar3 = (CSceneVehicleCar *)", "pCVar3 = (CSceneVehicleCar *)(size_t)")
code = code.replace("pSVar8 = (void *)-(float)(size_t)pSVar10;", "pSVar8 = (void *)(size_t)-(float)(size_t)pSVar10;")
code = code.replace("in_stack_00000068 = 1.1724596e-38;", "in_stack_00000068 = (float*)(size_t)0;")
code = code.replace("pCVar4 = (CSceneVehicleCarTuning *)std::abs", "pCVar4 = (CSceneVehicleCarTuning *)(size_t)std::abs")
code = code.replace("#define DUMMY_CFAST_CALL(...) ((void*)0)", "#define DUMMY_CFAST_CALL(...) (0.0f)")
code = code.replace("in_stack_ffffffcc = (void*)(size_t)(*(float*)((char*)(size_t)pGVar5 + 4) + 0.0);", "in_stack_ffffffcc = GmVec3(0,0,0);")
code = code.replace("pGVar18 = (GmVec3*)(size_t)0x7fad8b;", "pGVar18 = GmVec3(0,0,0);")
code = code.replace("param_12 = *(float*)(*(int*)(size_t)pSVar10 + 0x74);", "param_12 = (float*)(size_t)*(float*)(*(int*)(size_t)pSVar10 + 0x74);")
code = code.replace("in_stack_0000003c = (int *)(fVar14 *", "in_stack_0000003c = (int *)(size_t)(fVar14 *")
code = code.replace("(size_t)in_stack_ffffffe0", "(*(size_t*)&in_stack_ffffffe0)")
code = code.replace("fStack_8 = GmVec3(0,0,0);", "fStack_8 = 0.0f;")
code = code.replace("(float)(size_t)pSVar8", "(float)(size_t)0")
code = code.replace("(float)(size_t)param_1", "(float)(size_t)0")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
