// Class implementation: CFastArray_struct_CHmsViewport_SDisplayMode

// =================================================
// Function: CFastArray<struct_CHmsViewport::SDisplayMode>::AddNewTailElem
// =================================================
SPackedDesc * __thiscall
CFastArray<struct_CHmsViewport::SDisplayMode>::AddNewTailElem
          (void *this,CFastArray<struct_CDx9StateBlock::SPackedDesc> *param_1)
{
{
  ulong unaff_ESI;
  
  if (*(int *)this == 0) {
    SetCount(this,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_ESI);
    return *(SPackedDesc **)((int)this + 4);
  }
  AllocateMore(this,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)0x1,unaff_ESI);
  return (SPackedDesc *)(*(int *)((int)this + 4) + -0x18 + *(int *)this * 0x18);
}
}

// =================================================
// Function: CFastArray<struct_CHmsViewport::SDisplayMode>::SetCount
// =================================================
void __thiscall
CFastArray<struct_CHmsViewport::SDisplayMode>::SetCount
          (void *this,CFastBuffer<class_CSystemFidsFolder*> *param_1,ulong param_2)
{
{
  CFastBuffer<class_CSystemFidsFolder*> *pCVar1;
  void *pvVar2;
  ulong unaff_ESI;
  
  pCVar1 = *(CFastBuffer<class_CSystemFidsFolder*> **)this;
  if (param_1 == pCVar1) {
    return;
  }
  if (*(void **)((int)this + 4) == (void *)0x0) {
    if (param_1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
      *(CFastBuffer<class_CSystemFidsFolder*> **)this = param_1;
      pvVar2 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 0x18 >> 0x20) != 0) |
                              (uint)(ZEXT48(param_1) * 0x18));
      *(void **)((int)this + 4) = pvVar2;
      return;
    }
  }
  else if (param_1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
    if (pCVar1 <= param_1) {
      AllocateMore(this,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)(param_1 + -(int)pCVar1),
                   unaff_ESI);
      return;
    }
    AllocateLess(this,(CFastArray<struct_CHmsWaterRegion::SCell> *)(pCVar1 + -(int)param_1),
                 unaff_ESI);
    return;
  }
  operator_delete__(*(void **)((int)this + 4));
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}
}

