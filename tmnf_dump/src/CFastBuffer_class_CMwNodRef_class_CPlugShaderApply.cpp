// Class implementation: CFastBuffer_class_CMwNodRef_class_CPlugShaderApply

// =================================================
// Function: CFastBuffer<class_CMwNodRef<class_CPlugShaderApply>_>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<class_CMwNodRef<class_CPlugShaderApply>_>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  CMwNod *this_00;
  void *pvVar1;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar2;
  uint uVar3;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar4;
  uint uVar5;
  void *unaff_EDI;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *in_stack_ffffffc8;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ad307b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar3 = *(uint *)((int)this + 8);
  uVar5 = 0;
  if (0 < (int)((int)param_1 - uVar3)) {
    if ((int)((int)param_1 - uVar3) <= (int)(uVar3 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar3 >> 1) + uVar3);
    }
    uVar3 = -(uint)((int)(ZEXT48(param_1) * 4 >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 4);
    pCVar2 = operator_new__(-(uint)(0xfffffffb < uVar3) | uVar3 + 4);
    local_4 = 0;
    if (pCVar2 == (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x0) {
      pCVar4 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x0;
    }
    else {
      pCVar4 = pCVar2 + 4;
      *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)pCVar2 = param_1;
      in_stack_ffffffc8 = pCVar4;
      _eh_vector_constructor_iterator_
                (pCVar4,4,(int)param_1,
                 CMwNodRef<class_CGameManialinkEntry>::CMwNodRef<class_CGameManialinkEntry>,
                 CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
    }
    if (*(int *)this != 0) {
      do {
        this_00 = *(CMwNod **)(*(int *)((int)this + 4) + uVar5 * 4);
        if (this_00 != *(CMwNod **)(pCVar4 + uVar5 * 4)) {
          if (this_00 != (CMwNod *)0x0) {
            CMwNod::MwAddRef(this_00,(CMwNod *)in_stack_ffffffc8);
          }
          if (*(CMwNod **)(pCVar4 + uVar5 * 4) != (CMwNod *)0x0) {
            CMwNod::MwRelease(*(CMwNod **)(pCVar4 + uVar5 * 4),(CMwNod *)in_stack_ffffffc8);
          }
          *(CMwNod **)(pCVar4 + uVar5 * 4) = this_00;
        }
        uVar5 = uVar5 + 1;
        param_1 = pCVar2;
      } while (uVar5 < *(uint *)this);
    }
    pvVar1 = *(void **)((int)this + 4);
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    if (pvVar1 != (void *)0x0) {
      _eh_vector_destructor_iterator_
                (pvVar1,4,*(int *)((int)pvVar1 + -4),
                 CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
      operator_delete__((void *)((int)pvVar1 + -4));
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 4) = pCVar4;
  }
  ExceptionList = unaff_EDI;
  return;
}
}

