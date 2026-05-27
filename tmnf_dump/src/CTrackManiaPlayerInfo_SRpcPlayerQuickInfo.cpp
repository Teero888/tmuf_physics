// Class implementation: CTrackManiaPlayerInfo_SRpcPlayerQuickInfo

// =================================================
// Function: CTrackManiaPlayerInfo::SRpcPlayerQuickInfo::Reset
// =================================================
void __thiscall CTrackManiaPlayerInfo::SRpcPlayerQuickInfo::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  SStringParam *unaff_ESI;
  SStringParam *unaff_EDI;
  undefined1 *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined1 *)this = 0xff;
  local_c = &DAT_00b2c878;
  local_8 = 0;
  CFastString::SetString((CFastString *)((int)this + 4),(CFastStringInt *)&local_c,unaff_EDI);
  local_8 = DAT_00d71d5c;
  local_4 = DAT_00d71d58;
  CFastStringInt::SetString((void *)((int)this + 0xc),(CFastStringInt *)&local_8,unaff_ESI);
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined2 *)((int)this + 2) = 0;
  *(undefined1 *)((int)this + 1) = 0xff;
  return;
}
}

