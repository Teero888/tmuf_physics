// Class implementation: CCallbackSceneToyCharacterAfterContacts

// =================================================
// Function: CCallbackSceneToyCharacterAfterContacts::AfterContacts
// =================================================
void __thiscall
CCallbackSceneToyCharacterAfterContacts::AfterContacts
          (CCallbackSceneToyCharacterAfterContacts *this,
          CCallbackSceneVehicleBallAfterContacts *param_1,CHmsItem *param_2)
{
{
  (**(code **)(**(int **)(param_1 + 0x40) + 0x174))();
  return;
}
}

