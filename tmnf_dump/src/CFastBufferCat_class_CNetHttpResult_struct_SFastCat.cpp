// Class implementation: CFastBufferCat_class_CNetHttpResult_struct_SFastCat

// =================================================
// Function: struct_SFastCat>::FindIndexInCat
// =================================================
ulong __thiscall
CFastBufferCat<class_CNetHttpResult*,struct_SFastCat>::FindIndexInCat
          (void *this,CFastBufferCat<class_CNetHttpResult*,struct_SFastCat> *param_1,
          CNetHttpResult **param_2,ulong param_3)
{
{
  CNetHttpResult *pCVar1;
  int iVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  ulong uVar4;
  ulong unaff_EDI;
  uint in_stack_00000010;
  
  pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,unaff_EDI);
  uVar4 = 0;
  if (*(int *)(pSVar3 + 4) != 0) {
    pCVar1 = *param_2;
    iVar2 = *(int *)pSVar3;
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)((int)this + 0xc),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar4 + iVar2),
                          unaff_ESI);
      if (*(CNetHttpResult **)pSVar3 == pCVar1) {
        return uVar4;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < in_stack_00000010);
  }
  return 0xffffffff;
}
}

