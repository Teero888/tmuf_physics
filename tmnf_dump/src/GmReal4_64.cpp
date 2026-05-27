// Class implementation: GmReal4_64

// =================================================
// Function: GmReal4_64::GetClipFlag
// =================================================
void __thiscall GmReal4_64::GetClipFlag(void *this,GmReal4_64 *param_1,GmClipFlag_HalfCube *param_2)
{
{
  uint uVar1;
  
  *(undefined4 *)param_1 = 0;
  uVar1 = (uint)(*(double *)((int)this + 0x10) < 0.0);
  *(uint *)param_1 = uVar1;
  uVar1 = (uint)(*(double *)((int)this + 0x18) < *(double *)((int)this + 0x10)) * 2 ^ uVar1;
  *(uint *)param_1 = uVar1;
  uVar1 = (uint)(*(double *)((int)this + 8) < -*(double *)((int)this + 0x18)) * 4 ^ uVar1;
  *(uint *)param_1 = uVar1;
  uVar1 = (uint)(*(double *)((int)this + 0x18) < *(double *)((int)this + 8)) * 8 ^ uVar1;
  *(uint *)param_1 = uVar1;
  uVar1 = (uint)(*(double *)this < -*(double *)((int)this + 0x18)) << 4 ^ uVar1;
  *(uint *)param_1 = uVar1;
  if (*(double *)((int)this + 0x18) < *(double *)this) {
    *(uint *)param_1 = uVar1 ^ 0x20;
    return;
  }
  *(uint *)param_1 = uVar1;
  return;
}
}

