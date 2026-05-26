// Class implementation: GmLocFreeVal

// =================================================
// Function: GmLocFreeVal::GetLocVal
// =================================================
void __thiscall GmLocFreeVal::GetLocVal(void *this,GmLocFreeVal *param_1,GmLocVal *param_2)
{
{
  float unaff_ESI;
  GmMat43 *unaff_EDI;
  float in_stack_ffffffdc;
  GmMat43 *in_stack_ffffffe0;
  float in_stack_ffffffe4;
  GmScaleTrans2 *in_stack_ffffffe8;
  undefined1 auStack_14 [4];
  GmScaleTrans2 aGStack_10 [16];
  
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)this;
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)((int)this + 8);
  GmMat3::SetIdentity(param_1,unaff_EDI);
  GmMat3::RotateX(param_1,*(GmIso4 **)((int)this + 0xc),unaff_ESI);
  GmMat3::RotateY(param_1,*(GmIso4 **)((int)this + 0x10),in_stack_ffffffdc);
  GmMat3::SetIdentity(&stack0xffffffe8,in_stack_ffffffe0);
  GmMat3::RotateZ(auStack_14,*(GmIso4 **)((int)this + 0x14),in_stack_ffffffe4);
  GmMat3::LeftMult(param_1,aGStack_10,in_stack_ffffffe8);
  return;
}
}

// =================================================
// Function: GmLocFreeVal::Reset
// =================================================
void __thiscall GmLocFreeVal::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  return;
}
}

