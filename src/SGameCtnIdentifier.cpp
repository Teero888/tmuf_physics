// Class implementation: SGameCtnIdentifier

// =================================================
// Function: SGameCtnIdentifier::SGameCtnIdentifier
// =================================================
void __thiscall SGameCtnIdentifier::SGameCtnIdentifier(void *this,SGameCtnIdentifier *param_1)
{
{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a84e23;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwId::CMwId(this,(CMwId *)param_1);
  local_4 = 0;
  CMwId::CMwId((void *)((int)this + 4),(CMwId *)(param_1 + 4));
  local_4 = CONCAT31(local_4._1_3_,1);
  CMwId::CMwId((void *)((int)this + 8),(CMwId *)(param_1 + 8));
  ExceptionList = local_c;
  return;
}
}

