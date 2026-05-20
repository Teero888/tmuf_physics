// Class implementation: CFastArray_struct_SNodFid

// =================================================
// Function: CFastArray<struct_SNodFid>::SetCount
// =================================================
void __thiscall
CFastArray<struct_SNodFid>::SetCount
          (void *this,CFastBuffer<class_CSystemFidsFolder*> *param_1,ulong param_2)
{
{
  CFastBuffer<class_CSystemFidsFolder*> *pCVar1;
  void *pvVar2;
  void *pvVar3;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00acb9bb;
  local_c = ExceptionList;
  pvVar2 = (void *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  pCVar1 = *(CFastBuffer<class_CSystemFidsFolder*> **)this;
  if (param_1 == pCVar1) {
    ExceptionList = &LAB_00acb9bb;
    return;
  }
  if (*(void **)((int)this + 4) == (void *)0x0) {
    if (param_1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
      *(CFastBuffer<class_CSystemFidsFolder*> **)this = param_1;
      pvVar3 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 8 >> 0x20) != 0) |
                              (uint)(ZEXT48(param_1) * 8));
      local_4 = 0;
      if (pvVar3 == (void *)0x0) {
        *(undefined4 *)((int)this + 4) = 0;
        ExceptionList = local_c;
        return;
      }
      _vector_constructor_iterator_
                (pvVar3,8,(int)param_1,CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>)
      ;
      *(void **)((int)this + 4) = pvVar3;
      ExceptionList = pvVar2;
      return;
    }
  }
  else if (param_1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
    if (pCVar1 <= param_1) {
      AllocateMore(this,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)(param_1 + -(int)pCVar1),
                   (ulong)pvVar2);
      ExceptionList = local_8;
      return;
    }
    AllocateLess(this,(CFastArray<struct_CHmsWaterRegion::SCell> *)(pCVar1 + -(int)param_1),
                 (ulong)pvVar2);
    ExceptionList = local_8;
    return;
  }
  operator_delete__(*(void **)((int)this + 4));
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  ExceptionList = local_c;
  return;
}
}

