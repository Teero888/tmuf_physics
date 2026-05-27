// Class implementation: CCallbackSceneToyCharacterComputeForces

// =================================================
// Function: CCallbackSceneToyCharacterComputeForces::ComputeForces
// =================================================
void __thiscall
CCallbackSceneToyCharacterComputeForces::ComputeForces
          (CCallbackSceneToyCharacterComputeForces *this,
          CCallbackSceneToyBroomStickComputeForces *param_1,CHmsItem *param_2,float param_3)
{
{
  CHmsItem *unaff_retaddr;
  
  CSceneToyCharacter::ComputeForces
            (*(CSceneToyCharacter **)(param_1 + 0x40),
             (CCallbackSceneToyBroomStickComputeForces *)param_2,unaff_retaddr,(float)param_1);
  return;
}
}

