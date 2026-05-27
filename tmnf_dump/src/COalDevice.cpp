// Class implementation: COalDevice

// =================================================
// Function: COalDevice::COalDevice
// =================================================
void __thiscall COalDevice::COalDevice(COalDevice *this,COalDevice *param_1)
{
{
  CMwNod *unaff_ESI;
  void *unaff_retaddr;
  COalDevice *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00acac04;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec),unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined **)(this + 0x18) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined **)(this + 0x20) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined **)(this + 0x30) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined **)(this + 0x38) = PTR_DAT_00bbf7d8;
  Reset(this,(GmFrustumIso4 *)pCVar1);
  ExceptionList = unaff_retaddr;
  return;
}
}

