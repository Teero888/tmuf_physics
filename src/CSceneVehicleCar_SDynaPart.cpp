// Class implementation: CSceneVehicleCar_SDynaPart

// =================================================
// Function: CSceneVehicleCar::SDynaPart::Reset
// =================================================
void __thiscall CSceneVehicleCar::SDynaPart::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  GmSpring<float>::ClearVals((void *)((int)this + 0x1c),(GmSpring<float> *)param_1);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::SDynaPart::SDynaPart
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneVehicleCar::SDynaPart::SDynaPart(void *this,SDynaPart *param_1)
{
{
  GmSpring<float> *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00acc968;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwId::CMwId(this,(CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  GmSpring<float>::GmSpring<float>((undefined4 *)((int)this + 0x1c),unaff_EDI);
  *(undefined4 *)((int)this + 0x1c) = _DAT_00b65608;
  *(undefined4 *)((int)this + 0x20) = DAT_00b36188;
  ExceptionList = local_4;
  return;
}
}

