with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

code = code.replace(
    "this->WheelAddForceToVehicle(this, (CSceneVehicleCar*)pSVar7, (SSimulationWheel*)param_4, (GmVec3*)unaff_EBP);",
    "this->WheelAddForceToVehicle(this, (void*)pSVar7, (void*)&param_4, (void*)&unaff_EBP);"
)

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
