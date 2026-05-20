// Class implementation: CCrystalVertex

// =================================================
// Function: CCrystalVertex::IsConnected
// =================================================
int __thiscall CCrystalVertex::IsConnected(CCrystalVertex *this,CCrystalVertex *param_1)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  iVar1 = *(int *)(this + 0x38);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar1 + 0x10),unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x10),pCVar4,unaff_ESI);
      if ((*(CCrystalVertex **)(*(int *)pSVar3 + 0x58) == this) ||
         (*(CCrystalVertex **)(*(int *)pSVar3 + 0x5c) == this)) {
        return 1;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return 0;
}
}

