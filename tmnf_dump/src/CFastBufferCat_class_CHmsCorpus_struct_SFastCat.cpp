// Class implementation: CFastBufferCat_class_CHmsCorpus_struct_SFastCat

// =================================================
// Function: struct_SFastCat>::GetCountInCats
// =================================================
ulong __thiscall
CFastBufferCat<class_CHmsCorpus*,struct_SFastCat>::GetCountInCats
          (void *this,CFastBufferCat<class_CHmsCorpus*,struct_SFastCat> *param_1,ulong param_2,
          ulong param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong uVar3;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_1 + param_2);
  pSVar2 = CFastBuffer<struct_SFastCat>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_EDI);
  uVar3 = *(ulong *)(pSVar2 + 4);
  while (param_1 = param_1 + 1, param_1 < pCVar1) {
    pSVar2 = CFastBuffer<struct_SFastCat>::operator[]
                       (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_ESI);
    uVar3 = uVar3 + *(int *)(pSVar2 + 4);
  }
  return uVar3;
}
}

// =================================================
// Function: struct_SFastCat>::ReplaceByLastInAll
// =================================================
void __thiscall
CFastBufferCat<class_CHmsCorpus*,struct_SFastCat>::ReplaceByLastInAll
          (void *this,CFastBufferCat<class_CHmsCorpus*,struct_SFastCat> *param_1,
          CHmsCorpus **param_2,ulong *param_3)
{
{
  CHmsCorpus **ppCVar1;
  ulong unaff_ESI;
  ulong *unaff_EDI;
  CFastBufferCat<class_CMwCmd*,struct_SFastCat> *unaff_retaddr;
  undefined4 *in_stack_00000010;
  CMwCmd *local_4;
  
  local_4 = this;
  CFastBufferCat<class_CMwCmd*,struct_SFastCat>::FindIndexInAll
            (this,(CFastBufferCat<class_CMwCmd*,struct_SFastCat> *)param_1,&local_4,
             (ulong *)&param_1,unaff_EDI);
  ppCVar1 = param_2;
  CFastBufferCat<class_CMwCmd*,struct_SFastCat>::ReplaceByLastInCatAt
            (this,unaff_retaddr,(ulong)param_2,unaff_ESI);
  if (in_stack_00000010 != (undefined4 *)0x0) {
    *in_stack_00000010 = ppCVar1;
  }
  return;
}
}

