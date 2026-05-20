// Class implementation: CMotion

// =================================================
// Function: CMotion::CMotion
// =================================================
void __thiscall CMotion::CMotion(CMotion *this,CMotion *param_1)
{
{
  CMwNod *unaff_ESI;
  void *unaff_retaddr;
  CMotion *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a982a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec),unaff_ESI);
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x14,(CMwId *)pCVar1);
  ExceptionList = unaff_retaddr;
  return;
}
}

