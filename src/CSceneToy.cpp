// Class implementation: CSceneToy

// =================================================
// Function: CSceneToy::CSceneToy
// =================================================
void __thiscall CSceneToy::CSceneToy(CSceneToy *this,CSceneToy *param_1)
{
{
  CMwCmdContainer *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00acf408;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSceneMobil::CSceneMobil
            ((CSceneMobil *)this,(CSceneMobil *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined ***)this = vftable;
  CMwCmdContainer::CMwCmdContainer((CMwCmdContainer *)(this + 0x48),unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

