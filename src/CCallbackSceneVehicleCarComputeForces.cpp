// Class implementation: CCallbackSceneVehicleCarComputeForces

// =================================================
// Function: CCallbackSceneVehicleCarComputeForces::ComputeForces
// =================================================
void __thiscall
CCallbackSceneVehicleCarComputeForces::ComputeForces
          (CCallbackSceneVehicleCarComputeForces *this,
          CCallbackSceneToyBroomStickComputeForces *param_1,CHmsItem *param_2,float param_3)
{
{
  CHmsItem *unaff_retaddr;
  
  CSceneVehicleCar::ComputeForces
            (*(CSceneVehicleCar **)(param_1 + 0x40),
             (CCallbackSceneToyBroomStickComputeForces *)param_2,unaff_retaddr,(float)param_1);
  return;
}
}

