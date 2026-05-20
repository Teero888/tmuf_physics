// Class implementation: CGameCtnCatalog

// =================================================
// Function: CGameCtnCatalog::GetChapter
// =================================================
CGameCtnChapter * __thiscall
CGameCtnCatalog::GetChapter(CGameCtnCatalog *this,CGameCtnChallenge *param_1)
{
{
  CGameCtnCatalog *this_00;
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  iVar1 = *(int *)param_1;
  if (iVar1 == -1) {
    return (CGameCtnChapter *)0x0;
  }
  this_00 = this + 0x20;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_ESI);
      if (*(int *)(*(int *)pSVar3 + 0xac) == iVar1) {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_EBX)
        ;
        return *(CGameCtnChapter **)pSVar3;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return (CGameCtnChapter *)0x0;
}
}

