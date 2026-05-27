// Class implementation: GmCollision

// =================================================
// Function: GmCollision::Neg
// =================================================
void __thiscall GmCollision::Neg(void *this,GmCollision *param_1)
{
{
  undefined2 uVar1;
  
  *(float *)((int)this + 0xc) = -*(float *)((int)this + 0xc);
  *(float *)((int)this + 0x10) = -*(float *)((int)this + 0x10);
  *(float *)((int)this + 0x14) = -*(float *)((int)this + 0x14);
  uVar1 = *(undefined2 *)((int)this + 0x24);
  *(undefined2 *)((int)this + 0x24) = *(undefined2 *)((int)this + 0x26);
  *(float *)this = -*(float *)this;
  *(undefined2 *)((int)this + 0x26) = uVar1;
  *(float *)((int)this + 4) = -*(float *)((int)this + 4);
  *(float *)((int)this + 8) = -*(float *)((int)this + 8);
  *(float *)((int)this + 0x2c) = -*(float *)((int)this + 0x2c);
  *(float *)((int)this + 0x30) = -*(float *)((int)this + 0x30);
  *(float *)((int)this + 0x34) = -*(float *)((int)this + 0x34);
  return;
}
}

