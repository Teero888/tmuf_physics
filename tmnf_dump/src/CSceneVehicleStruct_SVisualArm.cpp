// Class implementation: CSceneVehicleStruct_SVisualArm

// =================================================
// Function: CSceneVehicleStruct::SVisualArm::Reset
// =================================================
void __thiscall CSceneVehicleStruct::SVisualArm::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  int extraout_EAX;
  GmFrustumIso4 *unaff_retaddr;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  SVisualId::Reset((void *)((int)this + 0x1c),unaff_retaddr);
  *(undefined4 *)(extraout_EAX + 8) = 0xffffffff;
  return;
}
}

