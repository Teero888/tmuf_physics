// Class implementation: CFastBufferCat_struct_CInputPort_SMappedAction_struct_SFastCat

// =================================================
// Function: struct_SFastCat>::AddInCat
// =================================================
void __thiscall
CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat>::AddInCat
          (void *this,CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *param_1,
          CHmsCorpus **param_2,ulong param_3)
{
{
  CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> *pCVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  TiXmlAttribute *unaff_EDI;
  ulong unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000018;
  
  CFastBuffer<class_GmNat2>::Add((void *)((int)this + 0xc),(TiXmlAttributeSet *)param_1,unaff_EDI);
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_ESI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar2 - 1);
  pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this,pCVar4,unaff_EBX);
  pCVar1 = *(CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> **)(pSVar3 + 4)
  ;
  pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this,pCVar4,unaff_retaddr);
  *(int *)(pSVar3 + 4) = *(int *)(pSVar3 + 4) + 1;
  if (in_stack_00000018 != pCVar4) {
    ChangeCatAt(this,pCVar1,(ulong)pCVar4,(ulong)in_stack_00000018,(ulong)param_1);
  }
  return;
}
}

// =================================================
// Function: struct_SFastCat>::SetParsingCat
// =================================================
ulong __thiscall
CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat>::SetParsingCat
          (void *this,CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *param_1,
          ulong param_2,ulong param_3)
{
{
  SCasterCat *pSVar1;
  ulong uVar2;
  ulong unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  uint uVar3;
  uint in_stack_00000010;
  uint in_stack_00000014;
  
  *(CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> **)((int)this + 0x18) = param_1
  ;
  *(ulong *)((int)this + 0x1c) = param_2;
  pSVar1 = CFastBuffer<struct_SFastCat>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_EDI);
  *(int *)((int)this + 0x20) = *(int *)((int)this + 0x10) + *(int *)pSVar1 * 8;
  pSVar1 = CFastBuffer<struct_SFastCat>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_ESI);
  uVar2 = *(ulong *)(pSVar1 + 4);
  uVar3 = 1;
  if (1 < in_stack_00000010) {
    do {
      pSVar1 = CFastBuffer<struct_SFastCat>::operator[]
                         (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_1 + uVar3),
                          unaff_EBP);
      uVar2 = uVar2 + *(int *)(pSVar1 + 4);
      uVar3 = uVar3 + 1;
    } while (uVar3 < in_stack_00000014);
  }
  return uVar2;
}
}

