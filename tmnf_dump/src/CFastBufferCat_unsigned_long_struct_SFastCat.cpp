// Class implementation: CFastBufferCat_unsigned_long_struct_SFastCat

// =================================================
// Function: struct_SFastCat>::QSortEachCatArithmetic
// =================================================
void __thiscall
CFastBufferCat<unsigned_long,struct_SFastCat>::QSortEachCatArithmetic
          (void *this,CFastBufferCat<unsigned_long,struct_SFastCat> *param_1,int param_2,
          ulong param_3,ulong param_4)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  code *pcVar3;
  code *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pcVar3 = CPlugPointsInSphereOpt::SPack::sCompareCount;
  if (param_1 == (CFastBufferCat<unsigned_long,struct_SFastCat> *)0x0) {
    pcVar3 = SortDescending;
  }
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_SFastCat>::operator[](this,pCVar4,(ulong)unaff_ESI);
      unaff_ESI = pcVar3;
      func_0x009c1270(*(int *)((int)this + 0x10) + *(int *)pSVar2 * 4,*(undefined4 *)(pSVar2 + 4),4)
      ;
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return;
}
}

