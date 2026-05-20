// Class implementation: SFastTokenInt

// =================================================
// Function: SFastTokenInt::SFastTokenInt
// =================================================
void __thiscall
SFastTokenInt::SFastTokenInt(void *this,SFastTokenInt *param_1,char *param_2,int param_3)
{
{
  SFastTokenInt *pSVar1;
  SFastTokenInt SVar2;
  SStringParam *pSVar3;
  SFastTokenInt *local_14;
  int local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00aa39eb;
  local_c = ExceptionList;
  pSVar3 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffe0);
  ExceptionList = &local_c;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined **)((int)this + 8) = PTR_DAT_00bbf7dc;
  local_4 = 0;
  local_14 = param_1;
  if (param_1 == (SFastTokenInt *)0x0) {
    local_10 = 0;
  }
  else {
    pSVar1 = param_1 + 1;
    do {
      SVar2 = *param_1;
      param_1 = param_1 + 1;
    } while (SVar2 != (SFastTokenInt)0x0);
    local_10 = (int)param_1 - (int)pSVar1;
  }
  CFastStringInt::CFastStringInt((void *)((int)this + 0x18),(CFastStringInt *)&local_14,pSVar3);
  *(undefined4 *)((int)this + 0xc) = 0xffffffff;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(uint *)this = (uint)(param_3 != 0) * 2;
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: SFastTokenInt::~SFastTokenInt
// =================================================
void __thiscall SFastTokenInt::~SFastTokenInt(void *this,SFastTokenInt *param_1)
{
{
  undefined *puVar1;
  
  puVar1 = *(undefined **)((int)this + 0x1c);
  if (puVar1 != PTR_DAT_00bbf7dc) {
    if ((puVar1[-1] & 0x80) == 0) {
      puVar1 = puVar1 + -2;
    }
    else {
      puVar1 = puVar1 + -4;
    }
    operator_delete__(puVar1);
    *(undefined4 *)((int)this + 0x18) = 0;
    *(undefined **)((int)this + 0x1c) = PTR_DAT_00bbf7dc;
  }
  puVar1 = *(undefined **)((int)this + 8);
  if (puVar1 != PTR_DAT_00bbf7dc) {
    if ((puVar1[-1] & 0x80) == 0) {
      puVar1 = puVar1 + -2;
    }
    else {
      puVar1 = puVar1 + -4;
    }
    operator_delete__(puVar1);
    *(undefined4 *)((int)this + 4) = 0;
    *(undefined **)((int)this + 8) = PTR_DAT_00bbf7dc;
  }
  return;
}
}

