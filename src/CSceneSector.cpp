// Class implementation: CSceneSector

// =================================================
// Function: CSceneSector::CSceneSector
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneSector::CSceneSector(CSceneSector *this,CSceneSector *param_1)
{
{
  undefined4 uVar1;
  CMwId *unaff_ESI;
  CMwNod *unaff_EDI;
  void *unaff_retaddr;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00acf4f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe8),unaff_EDI);
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x18,unaff_ESI);
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)(this + 0x2c) = _DAT_00b2c060;
  *(undefined4 *)(this + 0x30) = uVar1;
  *(undefined4 *)(this + 0x34) = uVar1;
  ExceptionList = unaff_retaddr;
  return;
}
}

