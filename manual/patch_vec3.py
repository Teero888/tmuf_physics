with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

code = code.replace(
    "in_stack_ffffff7c = 0x7fac1e;\n              this->AddVehicleTorque(this, (CSceneVehicleCar*)&fStack_18, nullptr);",
    "in_stack_ffffff7c = 0x7fac1e;\n              GmVec3 torque1(fStack_18, fStack_14, fStack_10);\n              this->AddVehicleTorque(this, (CSceneVehicleCar*)&torque1, nullptr);"
)

code = code.replace(
    "fStack_14 = fStack_18;\n      this->AddVehicleTorque(this, (CSceneVehicleCar*)&fStack_10, nullptr);",
    "fStack_14 = fStack_18;\n      GmVec3 torque2(fStack_10, fStack_c, fStack_8);\n      this->AddVehicleTorque(this, (CSceneVehicleCar*)&torque2, nullptr);"
)

code = code.replace(
    "param_8 = -in_stack_00000058 * *(float *)(*(int*)(size_t)pSVar10 + 0xc0);\n  this->AddVehicleTorque(this, (CSceneVehicleCar*)&param_8, nullptr);",
    "param_8 = -in_stack_00000058 * *(float *)(*(int*)(size_t)pSVar10 + 0xc0);\n  GmVec3 torque3(param_8, 0.0f, 0.0f);\n  this->AddVehicleTorque(this, (CSceneVehicleCar*)&torque3, nullptr);"
)

code = code.replace(
    "in_stack_00000070 = in_stack_00000038;\n  this->AddVehicleCentralForce(this, (CSceneVehicleCar*)&param_12, nullptr);",
    "in_stack_00000070 = in_stack_00000038;\n  GmVec3 cforce1(*(float*)&param_12, 0.0f, 0.0f);\n  this->AddVehicleCentralForce(this, (CSceneVehicleCar*)&cforce1, nullptr);"
)

code = code.replace(
    "pSStack00000080 = param_10;\n  this->AddVehicleCentralForce(this, (CSceneVehicleCar*)&param_8, nullptr);",
    "pSStack00000080 = param_10;\n  GmVec3 cforce2(param_8, (float)param_9, 0.0f);\n  this->AddVehicleCentralForce(this, (CSceneVehicleCar*)&cforce2, nullptr);"
)

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
