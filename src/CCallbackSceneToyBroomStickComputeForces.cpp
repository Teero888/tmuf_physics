// Class implementation: CCallbackSceneToyBroomStickComputeForces

// =================================================
// Function: CCallbackSceneToyBroomStickComputeForces::ComputeForces
// =================================================
void __thiscall
CCallbackSceneToyBroomStickComputeForces::ComputeForces
          (CCallbackSceneToyBroomStickComputeForces *this,
          CCallbackSceneToyBroomStickComputeForces *param_1,CHmsItem *param_2,float param_3)
{
{
  CHmsItem *unaff_retaddr;
  
  CSceneToyBroomstick::ComputeForces
            (*(CSceneToyBroomstick **)(param_1 + 0x40),
             (CCallbackSceneToyBroomStickComputeForces *)param_2,unaff_retaddr,(float)param_1);
  return;
}
}

