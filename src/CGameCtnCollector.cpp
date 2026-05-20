// Class implementation: CGameCtnCollector

// =================================================
// Function: CGameCtnCollector::CGameCtnCollector
// =================================================
void __thiscall
CGameCtnCollector::CGameCtnCollector(CGameCtnCollector *this,CGameCtnCollector *param_1)
{
{
  CMwId *unaff_EBX;
  CMwId *unaff_EBP;
  SGameCtnIdentifier *unaff_ESI;
  CMwNod *unaff_EDI;
  undefined1 uStack00000008;
  undefined1 uStack0000000c;
  void *in_stack_00000010;
  CGameCtnCollector *pCVar1;
  CFastStringInt *in_stack_ffffffec;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00abf93f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffd8),unaff_EDI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined **)(this + 0x18) = PTR_DAT_00bbf7d8;
  SGameCtnIdentifier::SGameCtnIdentifier(this + 0x24,unaff_ESI);
  uStack00000008 = 2;
  CMwId::CMwId(this + 0x48,unaff_EBP);
  uStack0000000c = 3;
  CMwId::CMwId(this + 0x4c,unaff_EBX);
  *(undefined4 *)(this + 0x50) = 0;
  in_stack_00000010 = (void *)CONCAT31(in_stack_00000010._1_3_,5);
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 1;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = 100;
  *(undefined4 *)(this + 0x44) = 10;
  *(undefined4 *)(this + 0x54) = 0;
  CFastString::SetString
            ((CFastString *)(this + 0x14),(CFastStringInt *)&stack0x00000000,(SStringParam *)pCVar1)
  ;
  CMwId::SetLocalName(this + 0x2c,(CMwId *)&DAT_00b38e9c,in_stack_ffffffec);
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x4c) = 0xffffffff;
  ExceptionList = in_stack_00000010;
  return;
}
}

