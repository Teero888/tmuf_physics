// Class implementation: CFastBufferCat_struct_CDx9StateBlock_STexStageState_struct_CDx9StateBlock_STexStageCat

// =================================================
// Function: AddNewElemInCat
// =================================================
SHmsItem_CallbackSortCustom_Elem * __thiscall
CFastBufferCat<struct_CDx9StateBlock::STexStageState,struct_CDx9StateBlock::STexStageCat>::
AddNewElemInCat(void *this,
               CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> *param_1,
               ulong param_2)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> *pCVar3;
  SSamplerState *pSVar4;
  ulong unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EDI;
  ulong unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000014;
  
  CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem((void *)((int)this + 0xc),unaff_EDI);
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_ESI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar1 - 1);
  pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](this,pCVar5,unaff_EBP);
  pCVar3 = *(CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> **)(pSVar2 + 4)
  ;
  pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](this,pCVar5,unaff_EBX);
  *(int *)(pSVar2 + 4) = *(int *)(pSVar2 + 4) + 1;
  if (in_stack_00000014 != pCVar5) {
    pCVar3 = (CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> *)
             ChangeCatAt(this,pCVar3,(ulong)pCVar5,(ulong)in_stack_00000014,unaff_retaddr);
  }
  pSVar4 = CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>::
           GetElemInCat(this,(CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                              *)pCVar3,(ulong)in_stack_00000014,unaff_retaddr);
  return (SHmsItem_CallbackSortCustom_Elem *)pSVar4;
}
}

// =================================================
// Function: ChangeCatAt
// =================================================
ulong __thiscall
CFastBufferCat<struct_CDx9StateBlock::STexStageState,struct_CDx9StateBlock::STexStageCat>::
ChangeCatAt(void *this,
           CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> *param_1,
           ulong param_2,ulong param_3,ulong param_4)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  SCasterCat *pSVar3;
  SCasterCat *pSVar4;
  SCasterCat *pSVar5;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000014;
  
  pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,unaff_EDI);
  if (param_2 < param_4) {
    do {
      if (param_1 < (CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> *)
                    (*(int *)(pSVar3 + 4) - 1U)) {
        pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                           ((void *)((int)this + 0xc),
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                            ((CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat>
                              *)(*(int *)(pSVar3 + 4) - 1U) + *(int *)pSVar3),(ulong)unaff_ESI);
        unaff_ESI = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_1 + *(int *)pSVar3);
        pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                           ((void *)((int)this + 0xc),unaff_ESI,unaff_EBP);
        uVar1 = *(undefined4 *)pSVar5;
        uVar2 = *(undefined4 *)(pSVar5 + 4);
        *(undefined4 *)pSVar5 = *(undefined4 *)pSVar4;
        *(undefined4 *)(pSVar5 + 4) = *(undefined4 *)(pSVar4 + 4);
        *(undefined4 *)pSVar4 = uVar1;
        *(undefined4 *)(pSVar4 + 4) = uVar2;
        param_2 = param_4;
      }
      *(int *)(pSVar3 + 4) = *(int *)(pSVar3 + 4) + -1;
      param_2 = param_2 + 1;
      pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                          (ulong)unaff_ESI);
      *(int *)pSVar3 = *(int *)pSVar3 + -1;
      *(int *)(pSVar3 + 4) = *(int *)(pSVar3 + 4) + 1;
      param_1 = (CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> *)0x0;
    } while (param_2 < in_stack_00000014);
    return 0;
  }
  do {
    if (param_1 != (CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> *)0x0) {
      pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                         ((void *)((int)this + 0xc),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar3,
                          (ulong)unaff_ESI);
      unaff_ESI = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_1 + *(int *)pSVar3);
      pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                         ((void *)((int)this + 0xc),unaff_ESI,unaff_EBP);
      uVar1 = *(undefined4 *)pSVar5;
      uVar2 = *(undefined4 *)(pSVar5 + 4);
      *(undefined4 *)pSVar5 = *(undefined4 *)pSVar4;
      *(undefined4 *)(pSVar5 + 4) = *(undefined4 *)(pSVar4 + 4);
      *(undefined4 *)pSVar4 = uVar1;
      *(undefined4 *)(pSVar4 + 4) = uVar2;
      param_2 = param_4;
    }
    *(int *)pSVar3 = *(int *)pSVar3 + 1;
    *(int *)(pSVar3 + 4) = *(int *)(pSVar3 + 4) + -1;
    param_2 = param_2 + -1;
    pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                        (ulong)unaff_ESI);
    param_1 = *(CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> **)
               (pSVar3 + 4);
    *(CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> **)(pSVar3 + 4) =
         param_1 + 1;
  } while (in_stack_00000014 < param_2);
  return (ulong)param_1;
}
}

