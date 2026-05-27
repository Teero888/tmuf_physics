// Class implementation: STmValidateParam

// =================================================
// Function: STmValidateParam::Clear
// =================================================
void __thiscall STmValidateParam::Clear(void *this,TiXmlNode *param_1)
{
{
  CMwNod *unaff_ESI;
  
  if (*(CMwNod **)this != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)this,unaff_ESI);
    *(undefined4 *)this = 0;
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0xc) = 0xffffffff;
  *(undefined4 *)((int)this + 0x14) = 0;
  return;
}
}

// =================================================
// Function: STmValidateParam::STmValidateParam
// =================================================
void __thiscall STmValidateParam::STmValidateParam(void *this,STmValidateParam *param_1)
{
{
  CMwNod *pCVar1;
  uint uVar2;
  uint uVar3;
  CMwNod *unaff_EDI;
  int in_stack_00000010;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00a892c8;
  local_c = ExceptionList;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  *(undefined4 *)this = 0;
  local_4 = (void *)0x0;
  if (param_1 != (STmValidateParam *)0x0) {
    CMwNod::MwAddRef((CMwNod *)param_1,pCVar1);
    if (*(CMwNod **)this != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)this,unaff_EDI);
    }
    *(STmValidateParam **)this = param_1;
  }
  uVar3 = -(uint)(*(uint *)(param_1 + 0xf0) != 0xffffffff) & *(uint *)(param_1 + 0xf0);
  uVar2 = -(uint)(*(uint *)(param_1 + 0xe8) != 0xffffffff) & *(uint *)(param_1 + 0xe8);
  *(STmValidateParam **)((int)this + 4) = param_1 + 0x110;
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 0x10c);
  if (in_stack_00000010 != 0) {
    uVar2 = 0xffffffff;
  }
  *(uint *)((int)this + 0xc) = uVar2;
  if (in_stack_00000010 == 0) {
    uVar3 = 0xffffffff;
  }
  *(uint *)((int)this + 0x10) = uVar3;
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x170);
  ExceptionList = local_4;
  return;
}
}

