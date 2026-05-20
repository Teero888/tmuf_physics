// Class implementation: CCallbackSceneToyBoatComputeForces

// =================================================
// Function: CCallbackSceneToyBoatComputeForces::ComputeForces
// =================================================
void __thiscall
CCallbackSceneToyBoatComputeForces::ComputeForces
          (CCallbackSceneToyBoatComputeForces *this,
          CCallbackSceneToyBroomStickComputeForces *param_1,CHmsItem *param_2,float param_3)
{
{
  CHmsItem *unaff_retaddr;
  
  CSceneToyBoat::ComputeForces
            (*(CSceneToyBoat **)(param_1 + 0x40),(CCallbackSceneToyBroomStickComputeForces *)param_2
             ,unaff_retaddr,(float)param_1);
  return;
}
}

