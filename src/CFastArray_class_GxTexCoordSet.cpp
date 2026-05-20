// Class implementation: CFastArray_class_GxTexCoordSet

// =================================================
// Function: CFastArray<class_GxTexCoordSet>::AddTail
// =================================================
void __thiscall
CFastArray<class_GxTexCoordSet>::AddTail
          (void *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,SFormat *param_2)
{
{
  SFormat *pSVar1;
  ulong unaff_EDI;
  
  if (*(int *)this == 0) {
    SetCount(this,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_EDI);
    pSVar1 = *(SFormat **)((int)this + 4);
  }
  else {
    AllocateMore(this,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)0x1,unaff_EDI);
    pSVar1 = (SFormat *)(*(int *)((int)this + 4) + -8 + *(int *)this * 8);
  }
  if (*(void **)(pSVar1 + 4) != *(void **)(param_2 + 4)) {
    *pSVar1 = *param_2;
    if ((*(uint *)pSVar1 & 0x100) != 0) {
      operator_delete__(*(void **)(pSVar1 + 4));
    }
    *(uint *)(pSVar1 + 4) = *(uint *)(param_2 + 4);
    if ((*(uint *)param_2 & 0x100) != 0) {
      *(undefined4 *)(param_2 + 4) = 0;
    }
    *(uint *)pSVar1 = *(uint *)pSVar1 ^ (*(uint *)pSVar1 ^ *(uint *)param_2) & 0x100;
  }
  return;
}
}

// =================================================
// Function: CFastArray<class_GxTexCoordSet>::SetCount
// =================================================
void __thiscall
CFastArray<class_GxTexCoordSet>::SetCount
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
  local_8 = &LAB_00ad60cb;
  local_c = ExceptionList;
  pvVar3 = (void *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  pCVar1 = *(CFastBuffer<class_CSystemFidsFolder*> **)this;
  if (param_1 == pCVar1) {
    ExceptionList = &LAB_00ad60cb;
    return;
  }
  pvVar2 = *(void **)((int)this + 4);
  if (pvVar2 == (void *)0x0) {
    if (param_1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
      *(CFastBuffer<class_CSystemFidsFolder*> **)this = param_1;
      uVar5 = -(uint)((int)(ZEXT48(param_1) * 8 >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 8);
      puVar4 = operator_new__(-(uint)(0xfffffffb < uVar5) | uVar5 + 4);
      local_4 = 0;
      if (puVar4 == (undefined4 *)0x0) {
        *(undefined4 *)((int)this + 4) = 0;
        ExceptionList = local_c;
        return;
      }
      pcVar6 = GxTexCoordSet::~GxTexCoordSet;
      *puVar4 = param_1;
      _eh_vector_constructor_iterator_
                (puVar4 + 1,8,(int)param_1,GxTexCoordSet::GxTexCoordSet,
                 GxTexCoordSet::~GxTexCoordSet);
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
              (pvVar2,8,*(int *)((int)pvVar2 + -4),GxTexCoordSet::~GxTexCoordSet);
    operator_delete__((void *)((int)pvVar2 + -4));
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  ExceptionList = pvVar3;
  return;
}
}

