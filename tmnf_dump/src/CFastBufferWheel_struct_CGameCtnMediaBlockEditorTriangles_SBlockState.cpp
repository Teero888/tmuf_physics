// Class implementation: CFastBufferWheel_struct_CGameCtnMediaBlockEditorTriangles_SBlockState

// =================================================
// Function: CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>::Head
// =================================================
SBlockState * __thiscall
CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>::Head
          (void *this,
          CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> *param_1)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)((int)this + 0xc);
  if (*(uint *)((int)this + 8) <= uVar1) {
    uVar1 = uVar1 - *(uint *)((int)this + 8);
  }
  return (SBlockState *)(*(int *)((int)this + 4) + uVar1 * 0x28);
}
}

// =================================================
// Function: CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>::InsertNewElemFromStart
// =================================================
SHistoryPoint * __thiscall
CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>::InsertNewElemFromStart
          (void *this,CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *param_1,ulong param_2)
{
{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *unaff_EBX;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar5;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *unaff_EBP;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar6;
  uint uVar7;
  SParam *unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar8;
  CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *pCVar9;
  SParam_Set *pSVar10;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *in_stack_0000000c;
  uint in_stack_00000014;
  
  if ((*(int *)((int)this + 0x10) == 0) || (*(int *)this != *(int *)((int)this + 0x10))) {
    pCVar5 = *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8);
    pCVar8 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(*(int *)this + 1);
    if (pCVar5 < pCVar8) {
      CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>::SetSizeAtLeast
                (this,pCVar8,unaff_EDI);
      pCVar6 = pCVar5 + -1;
      if (*(int *)((int)this + 0xc) <= (int)pCVar6) {
        pCVar9 = (CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *)((int)pCVar6 * 0x28);
        do {
          pSVar10 = (SParam_Set *)(pCVar9 + *(int *)((int)this + 4));
          pvVar1 = (void *)(*(int *)((int)this + 4) +
                           (int)(pCVar6 + (*(int *)((int)this + 8) - (int)pCVar5)) * 0x28);
          CMultiArray<class_GmVec3>::CopyFrom(pvVar1,pSVar10,unaff_ESI);
          CFastBuffer<class_GxColor>::CopyFromFastBuffer
                    ((void *)((int)pvVar1 + 0x10),
                     (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)(pSVar10 + 0x10),
                     unaff_EBP);
          unaff_EBP = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)(pSVar10 + 0x1c);
          unaff_ESI = (SParam *)0x755a1c;
          CFastBuffer<struct_CGameCtnMediaBlockTriangles::STri>::CopyFromFastBuffer
                    ((void *)((int)pvVar1 + 0x1c),unaff_EBP,unaff_EBX);
          pCVar9 = param_1 + -0x28;
          pCVar6 = pCVar6 + -1;
          pCVar5 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_2;
          pCVar8 = in_stack_0000000c;
          param_1 = pCVar9;
        } while (*(int *)((int)this + 0xc) <= (int)pCVar6);
      }
      *(int *)((int)this + 0xc) =
           *(int *)((int)this + 0xc) + (*(int *)((int)this + 8) - (int)pCVar5);
    }
    else if (*(int *)((int)this + 0xc) == 0) {
      *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 0xc) = pCVar5;
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this = pCVar8;
  }
  else if (*(int *)((int)this + 0xc) == 0) {
    *(undefined4 *)((int)this + 0xc) = *(undefined4 *)((int)this + 8);
  }
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1;
  uVar7 = 0;
  if (param_2 != 0) {
    do {
      uVar2 = *(uint *)((int)this + 8);
      uVar4 = *(int *)((int)this + 0xc) + uVar7;
      uVar3 = uVar4 + 1;
      if (uVar2 <= uVar3) {
        uVar3 = uVar3 - uVar2;
      }
      if (uVar2 <= uVar4) {
        uVar4 = uVar4 - uVar2;
      }
      pSVar10 = (SParam_Set *)(*(int *)((int)this + 4) + uVar3 * 0x28);
      pvVar1 = (void *)(*(int *)((int)this + 4) + uVar4 * 0x28);
      CMultiArray<class_GmVec3>::CopyFrom(pvVar1,pSVar10,unaff_ESI);
      CFastBuffer<class_GxColor>::CopyFromFastBuffer
                ((void *)((int)pvVar1 + 0x10),
                 (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)(pSVar10 + 0x10),unaff_EBP);
      unaff_EBP = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)(pSVar10 + 0x1c);
      unaff_ESI = (SParam *)0x755a8d;
      CFastBuffer<struct_CGameCtnMediaBlockTriangles::STri>::CopyFromFastBuffer
                ((void *)((int)pvVar1 + 0x1c),unaff_EBP,unaff_EBX);
      uVar7 = uVar7 + 1;
    } while (uVar7 < in_stack_00000014);
  }
  uVar7 = *(int *)((int)this + 0xc) + param_2;
  if (*(uint *)((int)this + 8) <= uVar7) {
    uVar7 = uVar7 - *(uint *)((int)this + 8);
  }
  return (SHistoryPoint *)(*(int *)((int)this + 4) + uVar7 * 0x28);
}
}

// =================================================
// Function: CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>::PushNewElem
// =================================================
SBlockState * __thiscall
CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>::PushNewElem
          (void *this,
          CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> *param_1)
{
{
  SHistoryPoint *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = InsertNewElemFromStart
                     (this,(CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *)0x0,unaff_retaddr);
  return (SBlockState *)pSVar1;
}
}

