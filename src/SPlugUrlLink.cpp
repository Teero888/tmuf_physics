// Class implementation: SPlugUrlLink

// =================================================
// Function: SPlugUrlLink::Clear
// =================================================
void __thiscall SPlugUrlLink::Clear(void *this,TiXmlNode *param_1)
{
{
  SStringParam *unaff_ESI;
  SOldChars *unaff_EDI;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(int *)this != 0) {
    CFastStringBase<wchar_t>::AllocAtLeast(this,(CFastStringBase<wchar_t> *)0x0,1,0,unaff_EDI);
    **(undefined2 **)((int)this + 4) = 0;
    *(undefined4 *)this = 0;
  }
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  local_8 = DAT_00d71d5c;
  local_4 = DAT_00d71d58;
  CFastStringInt::SetString((void *)((int)this + 0x10),(CFastStringInt *)&local_8,unaff_ESI);
  *(undefined4 *)((int)this + 0x18) = 0;
  return;
}
}

// =================================================
// Function: SPlugUrlLink::Set
// =================================================
void __thiscall SPlugUrlLink::Set(void *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  SStringParam *unaff_ESI;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  undefined4 *in_stack_00000018;
  undefined4 in_stack_00000020;
  SStringParam *pSVar1;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = *(undefined4 *)param_1;
  pSVar1 = *(SStringParam **)(param_1 + 4);
  local_4 = 0;
  CFastStringInt::SetString(this,(CFastStringInt *)&stack0xfffffff4,unaff_ESI);
  *(undefined4 *)((int)this + 0xc) = in_stack_00000014;
  *(undefined4 *)((int)this + 8) = in_stack_0000000c;
  *(undefined4 *)((int)this + 0x1c) = in_stack_00000010;
  local_8 = in_stack_00000018[1];
  local_4 = *in_stack_00000018;
  CFastStringInt::SetString((void *)((int)this + 0x10),(CFastStringInt *)&local_8,pSVar1);
  *(undefined4 *)((int)this + 0x18) = in_stack_00000020;
  return;
}
}

// =================================================
// Function: SPlugUrlLink::~SPlugUrlLink
// =================================================
void __thiscall SPlugUrlLink::~SPlugUrlLink(void *this,SPlugUrlLink *param_1)
{
{
  undefined *puVar1;
  
  puVar1 = *(undefined **)((int)this + 0x14);
  if (puVar1 != PTR_DAT_00bbf7dc) {
    if ((puVar1[-1] & 0x80) == 0) {
      puVar1 = puVar1 + -2;
    }
    else {
      puVar1 = puVar1 + -4;
    }
    operator_delete__(puVar1);
    *(undefined4 *)((int)this + 0x10) = 0;
    *(undefined **)((int)this + 0x14) = PTR_DAT_00bbf7dc;
  }
  puVar1 = *(undefined **)((int)this + 4);
  if (puVar1 != PTR_DAT_00bbf7dc) {
    if ((puVar1[-1] & 0x80) == 0) {
      puVar1 = puVar1 + -2;
    }
    else {
      puVar1 = puVar1 + -4;
    }
    operator_delete__(puVar1);
    *(undefined4 *)this = 0;
    *(undefined **)((int)this + 4) = PTR_DAT_00bbf7dc;
  }
  return;
}
}

