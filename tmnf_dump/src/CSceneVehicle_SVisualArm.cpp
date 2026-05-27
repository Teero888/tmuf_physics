// Class implementation: CSceneVehicle_SVisualArm

// =================================================
// Function: CSceneVehicle::SVisualArm::Reset
// =================================================
void __thiscall CSceneVehicle::SVisualArm::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  SVisualHandler::Reset((void *)((int)this + 0x10),param_1);
  return;
}
}

// =================================================
// Function: CSceneVehicle::SVisualArm::SVisualArm
// =================================================
void __thiscall CSceneVehicle::SVisualArm::SVisualArm(void *this,SVisualArm *param_1)
{
{
  SVisualHandler *unaff_ESI;
  SVisualHandler *unaff_retaddr;
  
  SVisualHandler::SVisualHandler((void *)((int)this + 0x10),unaff_ESI);
  SVisualHandler::SVisualHandler((void *)((int)this + 0x7c),unaff_retaddr);
  SVisualHandler::SVisualHandler((void *)((int)this + 0xe8),(SVisualHandler *)param_1);
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x15c) = 0;
  *(undefined4 *)((int)this + 0x158) = 0;
  *(undefined4 *)((int)this + 0x154) = 0;
  *(undefined4 *)((int)this + 0x168) = 0;
  *(undefined4 *)((int)this + 0x164) = 0;
  *(undefined4 *)((int)this + 0x160) = 0;
  *(undefined4 *)((int)this + 0xc) = 0xffffffff;
  *(undefined4 *)((int)this + 0x16c) = 0x3f800000;
  return;
}
}

