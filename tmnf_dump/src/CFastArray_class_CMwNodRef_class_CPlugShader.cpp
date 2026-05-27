// Class implementation: CFastArray_class_CMwNodRef_class_CPlugShader

// =================================================
// Function: CFastArray<class_CMwNodRef<class_CPlugShader>_>::SetCount
// =================================================
void __thiscall
CFastArray<class_CMwNodRef<class_CPlugShader>_>::SetCount
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
  local_8 = &LAB_00accf1b;
  local_c = ExceptionList;
  pvVar3 = (void *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  pCVar1 = *(CFastBuffer<class_CSystemFidsFolder*> **)this;
  if (param_1 == pCVar1) {
    ExceptionList = &LAB_00accf1b;
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
      pcVar6 = CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>;
      *puVar4 = param_1;
      _eh_vector_constructor_iterator_
                (puVar4 + 1,4,(int)param_1,
                 CMwNodRef<class_CGameManialinkEntry>::CMwNodRef<class_CGameManialinkEntry>,
                 CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
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
              (pvVar2,4,*(int *)((int)pvVar2 + -4),
               CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
    operator_delete__((void *)((int)pvVar2 + -4));
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  ExceptionList = pvVar3;
  return;
}
}

