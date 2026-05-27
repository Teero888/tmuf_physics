// Class implementation: CFastBufferCat_class_CMwCmd_struct_SFastCat

// =================================================
// Function: struct_SFastCat>
// =================================================
void __thiscall
CFastBufferCat<class_CMwCmd*,struct_SFastCat>::CFastBufferCat<class_CMwCmd*,struct_SFastCat>
          (void *this,CFastBufferCat<class_CMwCmd*,struct_SFastCat> *param_1,ulong param_2,
          ulong param_3)
{
{
  SCasterCat *pSVar1;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *in_stack_00000014;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  void *pvVar4;
  
  pvVar4 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar3 = this;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this,(CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0xc),unaff_EDI);
  CFastBuffer<struct_SBindingToSort>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_3,unaff_ESI);
  CFastBuffer<int>::SetSizeAtLeast((void *)((int)this + 0xc),in_stack_00000014,unaff_EBP);
  CFastBuffer<class_CSystemFidsFolder*>::SetCount
            (this,(CFastBuffer<class_CSystemFidsFolder*> *)param_3,unaff_EBX);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (param_3 != 0) {
    do {
      pSVar1 = CFastBuffer<struct_SFastCat>::operator[](this,pCVar2,(ulong)pCVar3);
      *(undefined4 *)pSVar1 = 0;
      pCVar3 = pCVar2;
      pSVar1 = CFastBuffer<struct_SFastCat>::operator[](this,pCVar2,(ulong)pvVar4);
      pCVar2 = pCVar2 + 1;
      *(undefined4 *)(pSVar1 + 4) = 0;
    } while (pCVar2 < param_3);
  }
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0xffffffff;
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)((int)this + 0x10);
  ExceptionList = (void *)param_2;
  return;
}
}

// =================================================
// Function: struct_SFastCat>::FindIndexInAll
// =================================================
int __thiscall
CFastBufferCat<class_CMwCmd*,struct_SFastCat>::FindIndexInAll
          (void *this,CFastBufferCat<class_CMwCmd*,struct_SFastCat> *param_1,CMwCmd **param_2,
          ulong *param_3,ulong *param_4)
{
{
  ulong uVar1;
  ulong unaff_ESI;
  CFastBufferCat<class_CMwCmd*,struct_SFastCat> *pCVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 *in_stack_00000014;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
  pCVar2 = (CFastBufferCat<class_CMwCmd*,struct_SFastCat> *)0x0;
  if (uVar1 != 0) {
    do {
      uVar1 = CFastBufferCat<class_CNetHttpResult*,struct_SFastCat>::FindIndexInCat
                        (this,(CFastBufferCat<class_CNetHttpResult*,struct_SFastCat> *)param_2,
                         (CNetHttpResult **)pCVar2,unaff_ESI);
      *param_3 = uVar1;
      if (uVar1 != 0xffffffff) {
        *in_stack_00000014 = pCVar2;
        return 1;
      }
      pCVar2 = pCVar2 + 1;
    } while (pCVar2 < param_1);
  }
  return 0;
}
}

// =================================================
// Function: struct_SFastCat>::ReplaceByLastInCatAt
// =================================================
void __thiscall
CFastBufferCat<class_CMwCmd*,struct_SFastCat>::ReplaceByLastInCatAt
          (void *this,CFastBufferCat<class_CMwCmd*,struct_SFastCat> *param_1,ulong param_2,
          ulong param_3)
{
{
  int iVar1;
  undefined4 uVar2;
  ulong uVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  ulong unaff_retaddr;
  uint in_stack_00000010;
  uint uStack00000014;
  int in_stack_00000018;
  undefined4 *in_stack_00000020;
  
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar3 - 1);
  if ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_3 != pCVar5) {
    CFastBufferCat<class_CPlugTree*,struct_SFastCat>::ChangeCatAt
              (this,(CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> *)
                    param_2,param_3,(ulong)pCVar5,unaff_ESI);
  }
  pSVar4 = CFastBuffer<struct_SFastCat>::operator[](this,pCVar5,unaff_retaddr);
  uStack00000014 = *(int *)(pSVar4 + 4) - 1;
  if (in_stack_00000010 < uStack00000014) {
    pSVar4 = CFastBuffer<struct_SFastCat>::operator[](this,pCVar5,unaff_EBP);
    iVar1 = *(int *)pSVar4;
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)((int)this + 0xc),
               (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(iVar1 + in_stack_00000018),
               unaff_EBX);
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)((int)this + 0xc),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        (iVar1 + in_stack_00000018),(ulong)param_1);
    uVar2 = *(undefined4 *)pSVar4;
    *(undefined4 *)pSVar4 = *in_stack_00000020;
    *in_stack_00000020 = uVar2;
  }
  pSVar4 = CFastBuffer<struct_SFastCat>::operator[](this,pCVar5,in_stack_00000010);
  *(int *)(pSVar4 + 4) = *(int *)(pSVar4 + 4) + -1;
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1;
  return;
}
}

