// Class implementation: SGameCamVal

// =================================================
// Function: SGameCamVal::Reset
// =================================================
void __thiscall SGameCamVal::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  GmFrustumIso4 *unaff_ESI;
  GmFrustumIso4 *unaff_retaddr;
  
  GmLocVal::Reset(this,unaff_ESI);
  GmLensVal::Reset((void *)((int)this + 0x30),unaff_retaddr);
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x50) = 0xffffffff;
  *(undefined4 *)((int)this + 0x54) = 0xffffffff;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0xffffffff;
  return;
}
}

// =================================================
// Function: SGameCamVal::SGameCamVal
// =================================================
void __thiscall SGameCamVal::SGameCamVal(void *this,SGameCamVal *param_1)
{
{
  GmFrustumIso4 *unaff_EBX;
  CMwId *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  void *pvStack00000008;
  GmFrustumIso4 *pGVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a87f7b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pGVar1 = this;
  GmLocVal::Reset(this,(GmFrustumIso4 *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  GmLensVal::Reset((void *)((int)this + 0x30),unaff_EDI);
  CMwId::CMwId((undefined4 *)((int)this + 0x5c),unaff_ESI);
  pvStack00000008 = (void *)0x0;
  GmLocVal::Reset(this,unaff_EBX);
  GmLensVal::Reset((void *)((int)this + 0x30),pGVar1);
  *(undefined4 *)((int)this + 0x50) = 0xffffffff;
  *(undefined4 *)((int)this + 0x54) = 0xffffffff;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0xffffffff;
  ExceptionList = pvStack00000008;
  return;
}
}

