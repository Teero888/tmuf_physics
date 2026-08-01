import os

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

code = code.replace("void* pCVar4 = nullptr;", "/* void* pCVar4 = nullptr; */")
code = code.replace("float fStack_18=0, fStack_10=0;", "/* float fStack_18=0, fStack_10=0; */")
code = code.replace("in_stack_ffffffc4 =", "void* in_stack_ffffffc4 =")
code = code.replace("pCVar4 = *(CSceneVehicleCarTuning ***)(size_t)pSVar7;", "pCVar4 = **(CSceneVehicleCarTuning ***)(size_t)pSVar7;")
code = code.replace("fStack_18 = -param_5;", "fStack_18 = GmVec3(-param_5, -param_5, -param_5);")
code = code.replace("fStack_10 = in_stack_ffffffb8 * 0.0 - in_stack_ffffffc0 * 0.0;", "fStack_10 = GmVec3(0,0,0);")
code = code.replace("fStack_18 = 0; /* vec math */", "fStack_18 = GmVec3(0,0,0); /* vec math */")
code = code.replace("(uint32_t)(*(size_t*)&in_stack_ffffffc4)", "(uint32_t)(size_t)in_stack_ffffffc4")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)

with open('main.cpp', 'r') as f:
    main_code = f.read()

main_code = main_code.replace("item->SetLinearSpeed(item, &vel);", "")
main_code = main_code.replace("item->SetForce(item, &zero);", "")

with open('main.cpp', 'w') as f:
    f.write(main_code)
