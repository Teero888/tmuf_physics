import re

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

# Replace // AddVehicleTorque 1
code = code.replace(
    "in_stack_ffffff7c = 0x7fac1e;\n              // AddVehicleTorque",
    "in_stack_ffffff7c = 0x7fac1e;\n              this->AddVehicleTorque(this, (CSceneVehicleCar*)&fStack_18, nullptr);"
)

# Replace // AddVehicleTorque 2
code = code.replace(
    "fStack_14 = 0;\n      // AddVehicleTorque",
    "fStack_14 = 0;\n      this->AddVehicleTorque(this, (CSceneVehicleCar*)&fStack_10, nullptr);"
)

# Replace // AddVehicleTorque 3
code = code.replace(
    "param_8 = -in_stack_00000058 * *(float *)(*(int*)(size_t)pSVar10 + 0xc0);\n  // AddVehicleTorque",
    "param_8 = -in_stack_00000058 * *(float *)(*(int*)(size_t)pSVar10 + 0xc0);\n  this->AddVehicleTorque(this, (CSceneVehicleCar*)&param_8, nullptr);"
)

# Replace // AddVehicleCentralForce 1
code = code.replace(
    "in_stack_00000070 = in_stack_00000038;\n  // AddVehicleCentralForce",
    "in_stack_00000070 = in_stack_00000038;\n  this->AddVehicleCentralForce(this, (CSceneVehicleCar*)&param_12, nullptr);"
)

# Replace // AddVehicleCentralForce 2
code = code.replace(
    "pSStack00000080 = param_10;\n  // AddVehicleCentralForce",
    "pSStack00000080 = param_10;\n  this->AddVehicleCentralForce(this, (CSceneVehicleCar*)&param_8, nullptr);"
)

# Replace // WheelAddForce 1
code = code.replace(
    "pSVar10 = pSVar7;\n      // WheelAddForce",
    "pSVar10 = pSVar7;\n      this->WheelAddForceToVehicle(this, (CSceneVehicleCar*)pSVar7, (SSimulationWheel*)param_4, (GmVec3*)unaff_EBP);"
)

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
