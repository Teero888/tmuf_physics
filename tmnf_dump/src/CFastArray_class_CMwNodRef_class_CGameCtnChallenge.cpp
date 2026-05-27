// Class implementation: CFastArray_class_CMwNodRef_class_CGameCtnChallenge

// =================================================
// Function: CFastArray<class_CMwNodRef<class_CGameCtnChallenge>_>::AllocateLess
// =================================================
void __thiscall
CFastArray<class_CMwNodRef<class_CGameCtnChallenge>_>::AllocateLess
          (void *this,CFastArray<struct_CHmsWaterRegion::SCell> *param_1,ulong param_2)
{
{
  CMwNod *this_00;
  void *pvVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  CMwNod *pCVar5;
  void *unaff_EDI;
  uint uVar6;
  CMwNod *in_stack_ffffffc8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a84fdb;
  local_c = ExceptionList;
  puVar2 = (uint *)(DAT_00cca150 ^ (uint)&stack0xffffffe0);
  ExceptionList = &local_c;
  uVar6 = *(int *)this - (int)param_1;
  uVar4 = -(uint)((int)((ulonglong)uVar6 * 4 >> 0x20) != 0) | (uint)((ulonglong)uVar6 * 4);
  puVar3 = operator_new__(-(uint)(0xfffffffb < uVar4) | uVar4 + 4);
  uVar4 = 0;
  local_4 = 0;
  if (puVar3 == (uint *)0x0) {
    pCVar5 = (CMwNod *)0x0;
  }
  else {
    pCVar5 = (CMwNod *)(puVar3 + 1);
    *puVar3 = uVar6;
    in_stack_ffffffc8 = pCVar5;
    _eh_vector_constructor_iterator_
              (pCVar5,4,uVar6,
               CMwNodRef<class_CGameManialinkEntry>::CMwNodRef<class_CGameManialinkEntry>,
               CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
  }
  if (uVar6 != 0) {
    do {
      this_00 = *(CMwNod **)(*(uint *)((int)this + 4) + uVar4 * 4);
      if (this_00 != *(CMwNod **)(pCVar5 + uVar4 * 4)) {
        if (this_00 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(this_00,in_stack_ffffffc8);
        }
        if (*(CMwNod **)(pCVar5 + uVar4 * 4) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(pCVar5 + uVar4 * 4),in_stack_ffffffc8);
        }
        *(CMwNod **)(pCVar5 + uVar4 * 4) = this_00;
      }
      uVar4 = uVar4 + 1;
      this = puVar2;
    } while (uVar4 < uVar6);
  }
  pvVar1 = *(void **)((int)this + 4);
  *(CMwNod **)((int)this + 4) = pCVar5;
  *(uint *)this = uVar6;
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,4,*(int *)((int)pvVar1 + -4),
               CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  ExceptionList = unaff_EDI;
  return;
}
}

// =================================================
// Function: CFastArray<class_CMwNodRef<class_CGameCtnChallenge>_>::AllocateMore
// =================================================
void __thiscall
CFastArray<class_CMwNodRef<class_CGameCtnChallenge>_>::AllocateMore
          (void *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,ulong param_2)
{
{
  CMwNod *this_00;
  void *pvVar1;
  uint uVar2;
  CFastArray<struct_CDx9DeviceCaps::SFormat> *pCVar3;
  uint uVar4;
  CFastArray<struct_CDx9DeviceCaps::SFormat> *pCVar5;
  void *unaff_ESI;
  CFastArray<struct_CDx9DeviceCaps::SFormat> *pCVar6;
  CFastArray<struct_CDx9DeviceCaps::SFormat> *in_stack_ffffffc4;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a84fab;
  local_c = ExceptionList;
  uVar2 = DAT_00cca150 ^ (uint)&stack0xffffffdc;
  ExceptionList = &local_c;
  pCVar5 = param_1 + *(int *)this;
  uVar4 = -(uint)((int)(ZEXT48(pCVar5) * 4 >> 0x20) != 0) | (uint)(ZEXT48(pCVar5) * 4);
  pCVar3 = operator_new__(-(uint)(0xfffffffb < uVar4) | uVar4 + 4);
  uVar4 = 0;
  local_4 = 0;
  if (pCVar3 == (CFastArray<struct_CDx9DeviceCaps::SFormat> *)0x0) {
    pCVar6 = (CFastArray<struct_CDx9DeviceCaps::SFormat> *)0x0;
  }
  else {
    pCVar6 = pCVar3 + 4;
    *(CFastArray<struct_CDx9DeviceCaps::SFormat> **)pCVar3 = pCVar5;
    in_stack_ffffffc4 = pCVar6;
    _eh_vector_constructor_iterator_
              (pCVar6,4,(int)pCVar5,
               CMwNodRef<class_CGameManialinkEntry>::CMwNodRef<class_CGameManialinkEntry>,
               CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
  }
  if (uVar2 != 0) {
    do {
      this_00 = *(CMwNod **)(*(int *)((int)this + 4) + uVar4 * 4);
      if (this_00 != *(CMwNod **)(pCVar6 + uVar4 * 4)) {
        if (this_00 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(this_00,(CMwNod *)in_stack_ffffffc4);
        }
        if (*(CMwNod **)(pCVar6 + uVar4 * 4) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(pCVar6 + uVar4 * 4),(CMwNod *)in_stack_ffffffc4);
        }
        *(CMwNod **)(pCVar6 + uVar4 * 4) = this_00;
      }
      uVar4 = uVar4 + 1;
      pCVar5 = pCVar3;
    } while (uVar4 < uVar2);
  }
  pvVar1 = *(void **)((int)this + 4);
  *(CFastArray<struct_CDx9DeviceCaps::SFormat> **)((int)this + 4) = pCVar6;
  *(CFastArray<struct_CDx9DeviceCaps::SFormat> **)this = pCVar5;
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,4,*(int *)((int)pvVar1 + -4),
               CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  ExceptionList = unaff_ESI;
  return;
}
}

// =================================================
// Function: CFastArray<class_CMwNodRef<class_CGameCtnChallenge>_>::SetCount
// =================================================
void __thiscall
CFastArray<class_CMwNodRef<class_CGameCtnChallenge>_>::SetCount
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
  local_8 = &LAB_00a8503b;
  local_c = ExceptionList;
  pvVar3 = (void *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  pCVar1 = *(CFastBuffer<class_CSystemFidsFolder*> **)this;
  if (param_1 == pCVar1) {
    ExceptionList = &LAB_00a8503b;
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

