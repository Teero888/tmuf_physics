// Class implementation: CAudioPort_SFadingSound

// =================================================
// Function: CAudioPort::SFadingSound::Reset
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CAudioPort::SFadingSound::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  *(undefined4 *)((int)this + 8) = _DAT_00b313ac;
  *(GmFrustumIso4 **)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0x3f800000;
  *(undefined4 *)((int)this + 0x1c) = 0x3f800000;
  *(undefined4 *)((int)this + 0x14) = 0x3f800000;
  *(undefined4 *)((int)this + 0x20) = 0x3f800000;
  *(undefined4 *)((int)this + 0x18) = 0x3f800000;
  *(undefined4 *)((int)this + 0x24) = 0x3f800000;
  *(undefined4 *)((int)this + 0x28) = 0x3f800000;
  return;
}
}

