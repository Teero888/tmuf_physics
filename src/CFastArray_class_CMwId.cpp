// Class implementation: CFastArray_class_CMwId

// =================================================
// Function: CFastArray<class_CMwId>::AddTail
// =================================================
void __thiscall
CFastArray<class_CMwId>::AddTail
          (void *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,SFormat *param_2)
{
{
  ulong unaff_ESI;
  
  if (*(int *)this == 0) {
    SetCount(this,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_ESI);
    **(undefined4 **)((int)this + 4) = *(undefined4 *)param_2;
    return;
  }
  AllocateMore(this,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)0x1,unaff_ESI);
  *(undefined4 *)(*(int *)((int)this + 4) + -4 + *(int *)this * 4) = *(undefined4 *)param_2;
  return;
}
}

// =================================================
// Function: CFastArray<class_CMwId>::SetCount
// =================================================
void __thiscall
CFastArray<class_CMwId>::SetCount
          (void *this,CFastBuffer<class_CSystemFidsFolder*> *param_1,ulong param_2)
{
{
  CFastBuffer<class_CSystemFidsFolder*> *pCVar1;
  void *pvVar2;
  void *pvVar3;
  undefined4 *puVar4;
  uint uVar5;
  code *pcVar6;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a99a2b;
  local_c = ExceptionList;
  pvVar3 = (void *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  pCVar1 = *(CFastBuffer<class_CSystemFidsFolder*> **)this;
  if (param_1 == pCVar1) {
    ExceptionList = &LAB_00a99a2b;
    return;
  }
  pvVar2 = *(void **)((int)this + 4);
  if (pvVar2 == (void *)0x0) {
    if (param_1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
      *(CFastBuffer<class_CSystemFidsFolder*> **)this = param_1;
      uVar5 = -(uint)((int)(ZEXT48(param_1) * 4 >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 4);
      puVar4 = operator_new__(-(uint)(0xfffffffb < uVar5) | uVar5 + 4);
      local_4 = 0;
      if (puVar4 == (undefined4 *)0x0) {
        *(undefined4 *)((int)this + 4) = 0;
        ExceptionList = local_c;
        return;
      }
      pcVar6 = OnAccessViolation_ConcatToCrashFileName;
      *puVar4 = param_1;
      _eh_vector_constructor_iterator_
                (puVar4 + 1,4,(int)param_1,CMwId::CMwId,OnAccessViolation_ConcatToCrashFileName);
      *(undefined4 **)((int)this + 4) = puVar4 + 1;
      ExceptionList = pcVar6;
      return;
    }
  }
  else if (param_1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
    if (pCVar1 <= param_1) {
      AllocateMore(this,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)(param_1 + -(int)pCVar1),
                   (ulong)pvVar3);
      ExceptionList = local_8;
      return;
    }
    AllocateLess(this,(CFastArray<struct_CHmsWaterRegion::SCell> *)(pCVar1 + -(int)param_1),
                 (ulong)pvVar3);
    ExceptionList = local_8;
    return;
  }
  if (pvVar2 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar2,4,*(int *)((int)pvVar2 + -4),OnAccessViolation_ConcatToCrashFileName);
    operator_delete__((void *)((int)pvVar2 + -4));
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  ExceptionList = pvVar3;
  return;
}
}

