// Class implementation: CCallbackSceneVehicleCarAfterContacts

// =================================================
// Function: CCallbackSceneVehicleCarAfterContacts::AfterContacts
// =================================================
void __thiscall
CCallbackSceneVehicleCarAfterContacts::AfterContacts
          (CCallbackSceneVehicleCarAfterContacts *this,
          CCallbackSceneVehicleBallAfterContacts *param_1,CHmsItem *param_2)
{
{
  CCallbackSceneVehicleBallAfterContacts *unaff_retaddr;
  
  CSceneVehicleCar::AfterContacts
            (*(CSceneVehicleCar **)(param_1 + 0x40),unaff_retaddr,(CHmsItem *)param_1);
  return;
}
}

