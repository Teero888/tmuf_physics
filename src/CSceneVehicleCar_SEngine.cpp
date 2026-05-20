// Class implementation: CSceneVehicleCar_SEngine

// =================================================
// Function: CSceneVehicleCar::SEngine::Reset
// =================================================
void __thiscall CSceneVehicleCar::SEngine::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x2c) = 1;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x20) = 0x3f800000;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::SEngine::SEngine
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneVehicleCar::SEngine::SEngine(void *this,SEngine *param_1)
{
{
  GmFrustumIso4 *unaff_retaddr;
  
  *(undefined4 *)this = _DAT_00b9efb0;
  *(undefined4 *)((int)this + 4) = 0x3f800000;
  *(undefined4 *)((int)this + 8) = 0x3f800000;
  *(undefined4 *)((int)this + 0xc) = 0x3f800000;
  *(undefined4 *)((int)this + 0x10) = 0;
  Reset(this,unaff_retaddr);
  return;
}
}

