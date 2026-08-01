with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

code = code.replace(
"""    GmVec3 stack0xffffffa4(0,0,0);
    GmVec3 fStack_18(0,0,0);
    GmVec3 fStack_10(0,0,0);
    GmVec3 pGVar18(0,0,0);""",
"""    GmVec3 stack0xffffffa4(0,0,0);
    float fStack_18=0, fStack_14=0, fStack_10=0, fStack_8=0, fStack_c=0;
    GmVec3 pGVar18(0,0,0);"""
)

code = code.replace(
"""              fStack_8 = -param_5;
              fStack_18 = GmVec3(0,0,0);
              fStack_14 = in_stack_ffffffb8 * 0.0 - in_stack_ffffffc0 * 0.0;
              fStack_10 = GmVec3(0,0,0);
              in_stack_ffffff7c = 0x7fac1e;
              // AddVehicleTorque""",
"""              fStack_8 = -param_5;
              fStack_18 = in_stack_ffffffc0 * fStack_8 - in_stack_ffffffbc * 0.0;
              fStack_14 = in_stack_ffffffb8 * 0.0 - in_stack_ffffffc0 * 0.0;
              fStack_10 = in_stack_ffffffbc * 0.0 - fStack_8 * in_stack_ffffffb8;
              in_stack_ffffff7c = 0x7fac1e;
              GmVec3 torque1(fStack_18, fStack_14, fStack_10);
              this->AddVehicleTorque(this, (CSceneVehicleCar*)&torque1, nullptr);"""
)

code = code.replace(
"""      fStack_18 = GmVec3(0,0,0);
      fStack_10 = GmVec3(0,0,0); /* vec math */
      fStack_c = 0; /* vec math */
      fStack_8 = 0; /* vec math */
      pCVar17 = (void*)0;
      param_9 = (int)(*(size_t*)&fStack_18);
      fStack_14 = 0;
      // AddVehicleTorque""",
"""      fStack_10 = fStack_18 * 0.0 - (float)pCVar6 * fStack_18;
      fStack_c = (float)param_9 * (float)pCVar6 - fStack_18 * 0.0;
      fStack_8 = fStack_18 * 0.0 - (float)param_9 * 0.0;
      pCVar17 = (void*)0;
      param_9 = (int)fStack_18;
      fStack_14 = fStack_18;
      GmVec3 torque2(fStack_10, fStack_c, fStack_8);
      this->AddVehicleTorque(this, (CSceneVehicleCar*)&torque2, nullptr);"""
)

code = code.replace(
"""  param_8 = -in_stack_00000058 * *(float *)(*(int*)(size_t)pSVar10 + 0xc0);
  // AddVehicleTorque""",
"""  param_8 = -in_stack_00000058 * *(float *)(*(int*)(size_t)pSVar10 + 0xc0);
  GmVec3 torque3(param_8, 0, 0);
  this->AddVehicleTorque(this, (CSceneVehicleCar*)&torque3, nullptr);"""
)

code = code.replace(
"""  in_stack_00000070 = in_stack_00000038;
  // AddVehicleCentralForce""",
"""  in_stack_00000070 = in_stack_00000038;
  GmVec3 cforce1(*(float*)&param_12, 0, 0);
  this->AddVehicleCentralForce(this, (CSceneVehicleCar*)&cforce1, nullptr);"""
)

code = code.replace(
"""  pSStack00000080 = param_10;
  // AddVehicleCentralForce""",
"""  pSStack00000080 = param_10;
  GmVec3 cforce2(param_8, (float)param_9, 0);
  this->AddVehicleCentralForce(this, (CSceneVehicleCar*)&cforce2, nullptr);"""
)

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)

