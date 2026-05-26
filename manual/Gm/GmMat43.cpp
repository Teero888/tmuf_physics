// Class implementation: GmMat43

// =================================================
// Function: GmMat43::Set
// =================================================
void __thiscall GmMat43::Set(void *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((int)this + 0x18) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)this + 0x1c) = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)this + 0x2c) = uVar1;
  return;
}
}

// =================================================
// Function: GmMat43::SetIdentity
// =================================================
void __thiscall GmMat43::SetIdentity(void *this,GmMat43 *param_1)
{
{
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x14) = 0x3f800000;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x28) = 0x3f800000;
  return;
}
}

