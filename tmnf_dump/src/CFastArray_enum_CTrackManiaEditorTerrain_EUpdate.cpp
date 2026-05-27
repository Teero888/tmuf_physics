// Class implementation: CFastArray_enum_CTrackManiaEditorTerrain_EUpdate

// =================================================
// Function: CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
// =================================================
void __thiscall
CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
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
      pvVar2 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 4 >> 0x20) != 0) |
                              (uint)(ZEXT48(param_1) * 4));
      *(void **)((int)this + 4) = pvVar2;
      return;
    }
  }
  else if (param_1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
    if (pCVar1 <= param_1) {
      CFastArray<class_CFastBuffer<class_CGameCtnFieldUnit*>*>::AllocateMore
                (this,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)(param_1 + -(int)pCVar1),
                 unaff_ESI);
      return;
    }
    CFastArray<struct_CHmsWaterRegion::SCell>::AllocateLess
              (this,(CFastArray<struct_CHmsWaterRegion::SCell> *)(pCVar1 + -(int)param_1),unaff_ESI)
    ;
    return;
  }
  operator_delete__(*(void **)((int)this + 4));
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}
}

