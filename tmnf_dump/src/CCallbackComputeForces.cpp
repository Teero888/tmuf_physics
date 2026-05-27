// Class implementation: CCallbackComputeForces

// =================================================
// Function: CCallbackComputeForces::ComputeForces
// =================================================
void __thiscall
CCallbackComputeForces::ComputeForces
          (CCallbackComputeForces *this,CCallbackSceneToyBroomStickComputeForces *param_1,
          CHmsItem *param_2,float param_3)
{
{
  CHmsItem *unaff_retaddr;
  
  CSceneVehicleGlider::ComputeForces
            (*(CSceneVehicleGlider **)(param_1 + 0x40),
             (CCallbackSceneToyBroomStickComputeForces *)param_2,unaff_retaddr,(float)param_1);
  return;
}
}

