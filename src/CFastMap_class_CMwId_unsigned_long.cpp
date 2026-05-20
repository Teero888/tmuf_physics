// Class implementation: CFastMap_class_CMwId_unsigned_long

// =================================================
// Function: unsigned_long>::GetIndex
// =================================================
ulong __thiscall
CFastMap<class_CMwId,unsigned_long>::GetIndex
          (CFastMap<class_CMwId,unsigned_long> *this,SStackLocation *param_1,SLocationAlloc *param_2
          )
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 4,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    iVar1 = *(int *)param_2;
    do {
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this + 4,pCVar4,unaff_ESI);
      if (*(int *)pSVar3 == iVar1) {
        return (ulong)pCVar4;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return 0xffffffff;
}
}

