// Class implementation: CCallbackSceneVehicleBallAfterContacts

// =================================================
// Function: CCallbackSceneVehicleBallAfterContacts::AfterContacts
// =================================================
void __thiscall
CCallbackSceneVehicleBallAfterContacts::AfterContacts
          (CCallbackSceneVehicleBallAfterContacts *this,
          CCallbackSceneVehicleBallAfterContacts *param_1,CHmsItem *param_2)
{
{
  CCallbackSceneVehicleBallAfterContacts *unaff_retaddr;
  
  CSceneVehicleBall::AfterContacts
            (*(CSceneVehicleBall **)(param_1 + 0x40),unaff_retaddr,(CHmsItem *)param_1);
  return;
}
}

