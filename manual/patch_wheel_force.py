import re

with open("scratch_WheelAddForceToVehicle.cpp", "r") as f:
    orig = f.read()

# Replace Ghidra artifacts
orig = orig.replace("void __thiscall\nCSceneVehicleCar::WheelAddForceToVehicle\n          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,SSimulationWheel *param_2,\n          GmVec3 *param_3)", "void CSceneVehicleCar::WheelAddForceToVehicle(CSceneVehicleCar *param_1, void *param_2_void, void *param_3_void, void *param_4)")
orig = orig.replace("{\n{\n", "{\n    SSimulationWheel* param_2 = (SSimulationWheel*)param_2_void;\n    GmVec3* param_3 = (GmVec3*)param_3_void;\n")
orig = orig.replace("  ulong unaff_EBX;\n  ulong unaff_EBP;\n  ulong unaff_ESI;\n  ulong unaff_EDI;", "")

orig = orig.replace("CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]\n                     ((void *)(iVar1 + 0x14),\n                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),unaff_EDI)", "DUMMY_CFAST_CALL((void*)(iVar1 + 0x14), (void*)0, 0)")
orig = orig.replace("CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]\n                         ((void *)(iVar1 + 0x14),\n                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),\n                          unaff_ESI)", "DUMMY_CFAST_CALL((void*)(iVar1 + 0x14), (void*)0, 0)")
orig = orig.replace("CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]\n                     ((void *)(iVar1 + 0x14),\n                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),unaff_EBP)", "DUMMY_CFAST_CALL((void*)(iVar1 + 0x14), (void*)0, 0)")
orig = orig.replace("CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]\n                         ((void *)(iVar1 + 0x14),\n                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x24),\n                          unaff_EBX)", "DUMMY_CFAST_CALL((void*)(iVar1 + 0x14), (void*)0, 0)")

orig = orig.replace("AddVehicleForce(this,(CSceneVehicleCar *)&local_14,(GmVec3 *)(pSVar3 + 0xa8),in_stack_ffffffdc\n                     );", "GmVec3 f(local_14, local_14, local_14); AddVehicleForce(this, (CSceneVehicleCar*)&f, (GmVec3*)((char*)pSVar3 + 0xa8), in_stack_ffffffdc);")
orig = orig.replace("AddVehicleForce(this,(CSceneVehicleCar *)&param_1,(GmVec3 *)(pSVar3 + 0xa8),in_stack_ffffffdc)", "GmVec3 f((float)(size_t)param_1, (float)(size_t)param_1, (float)(size_t)param_1); AddVehicleForce(this, (CSceneVehicleCar*)&f, (GmVec3*)((char*)pSVar3 + 0xa8), in_stack_ffffffdc)")
orig = orig.replace("AddVehicleForce(this,(CSceneVehicleCar *)&local_8,(GmVec3 *)(pSVar3 + 0xa8),in_stack_ffffffdc);", "GmVec3 f((float)local_8, (float)local_8, (float)local_8); AddVehicleForce(this, (CSceneVehicleCar*)&f, (GmVec3*)((char*)pSVar3 + 0xa8), in_stack_ffffffdc);")

orig = orig.replace("param_2 + 0x124", "(char*)param_2 + 0x124")
orig = orig.replace("param_2 + 0xb4", "(char*)param_2 + 0xb4")
orig = orig.replace("param_2 + 0xb8", "(char*)param_2 + 0xb8")
orig = orig.replace("pSVar3 + 0xb4", "(char*)pSVar3 + 0xb4")
orig = orig.replace("pSVar3 + 0xb8", "(char*)pSVar3 + 0xb8")

with open("Scene/CSceneVehicleCar.cpp", "r") as f:
    scenecar = f.read()

scenecar = re.sub(r'void CSceneVehicleCar::WheelAddForceToVehicle\(CSceneVehicleCar \*param_1, void \*param_2, void \*param_3, void \*param_4\) \{\}', orig, scenecar)

with open("Scene/CSceneVehicleCar_new.cpp", "w") as f:
    f.write(scenecar)

print("Generated Scene/CSceneVehicleCar_new.cpp")
