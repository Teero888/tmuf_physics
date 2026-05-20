// Class implementation: CFastBuffer_struct_CGameCtnMediaBlockEditorTriangles_SBlockState

// =================================================
// Function: CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  void *pvVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  SParam *unaff_EBP;
  void *unaff_ESI;
  SParam *pSVar6;
  SParam_Set *pSVar7;
  SParam *this_00;
  SParam *in_stack_ffffffc4;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *in_stack_ffffffc8;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *in_stack_ffffffcc;
  void *local_c;
  undefined1 *puStack_8;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *local_4;
  
  local_4 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0xffffffff;
  puStack_8 = &LAB_00ac52fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar4 = *(uint *)((int)this + 8);
  uVar5 = 0;
  if (0 < (int)((int)param_1 - uVar4)) {
    if ((int)((int)param_1 - uVar4) <= (int)(uVar4 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar4 >> 1) + uVar4);
    }
    uVar4 = -(uint)((int)(ZEXT48(param_1) * 0x28 >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 0x28);
    puVar2 = operator_new__(-(uint)(0xfffffffb < uVar4) | uVar4 + 4);
    local_4 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x0;
    if (puVar2 == (uint *)0x0) {
      pSVar6 = (SParam *)0x0;
    }
    else {
      pSVar6 = (SParam *)(puVar2 + 1);
      in_stack_ffffffc8 = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)&DAT_00000028;
      *puVar2 = (uint)param_1;
      in_stack_ffffffc4 = pSVar6;
      in_stack_ffffffcc = param_1;
      _eh_vector_constructor_iterator_
                (pSVar6,0x28,(int)param_1,
                 CGameCtnMediaBlockEditorTriangles::SBlockState::SBlockState,
                 CGameCtnMediaBlockEditorTriangles::SBlockState::~SBlockState);
    }
    if (*(int *)this != 0) {
      this_00 = pSVar6 + 0x1c;
      iVar3 = -0x1c - (int)pSVar6;
      do {
        pSVar7 = (SParam_Set *)(this_00 + *(int *)((int)this + 4) + iVar3);
        CMultiArray<class_GmVec3>::CopyFrom(this_00 + -0x1c,pSVar7,in_stack_ffffffc4);
        CFastBuffer<class_GxColor>::CopyFromFastBuffer
                  (this_00 + -0xc,
                   (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)(pSVar7 + 0x10),
                   in_stack_ffffffc8);
        in_stack_ffffffc8 = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)(pSVar7 + 0x1c);
        in_stack_ffffffc4 = (SParam *)0x75560b;
        CFastBuffer<struct_CGameCtnMediaBlockTriangles::STri>::CopyFromFastBuffer
                  (this_00,in_stack_ffffffc8,
                   (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)in_stack_ffffffcc);
        uVar5 = uVar5 + 1;
        this_00 = this_00 + 0x28;
        iVar3 = -1;
        pSVar6 = unaff_EBP;
        param_1 = local_4;
      } while (uVar5 < *(uint *)this);
    }
    pvVar1 = *(void **)((int)this + 4);
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    if (pvVar1 != (void *)0x0) {
      _eh_vector_destructor_iterator_
                (pvVar1,0x28,*(int *)((int)pvVar1 + -4),
                 CGameCtnMediaBlockEditorTriangles::SBlockState::~SBlockState);
      operator_delete__((void *)((int)pvVar1 + -4));
    }
    *(SParam **)((int)this + 4) = pSVar6;
  }
  ExceptionList = unaff_ESI;
  return;
}
}

