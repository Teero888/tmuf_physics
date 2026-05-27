// Class implementation: CTrackManiaEditorIconPage

// =================================================
// Function: CTrackManiaEditorIconPage::GetIcon
// =================================================
void __thiscall
CTrackManiaEditorIconPage::GetIcon
          (CTrackManiaEditorIconPage *this,CMwParamFastBuffer<class_CMwParamVec4> *param_1,
          EMwIconList *param_2,EMwIconList *param_3)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x1c,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x1c,pCVar4,unaff_ESI);
      if (((*(int *)(*(int *)pSVar3 + 0x14) == 0) &&
          (iVar1 = *(int *)(*(int *)pSVar3 + 0x18), *(EMwIconList *)(iVar1 + 0x18) == *param_2)) &&
         (*(EMwIconList *)(iVar1 + 0x1c) == param_2[1])) {
        return;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return;
}
}

// =================================================
// Function: CTrackManiaEditorIconPage::GetName
// =================================================
CFastString __thiscall
CTrackManiaEditorIconPage::GetName
          (CTrackManiaEditorIconPage *this,CTrackManiaEditorIconPage *param_1)
{
{
  char *unaff_ESI;
  
  CFastString::CFastString((CFastString *)param_1,(CFastString *)(this + 0x14),unaff_ESI);
  return SUB41(param_1,0);
}
}

// =================================================
// Function: CTrackManiaEditorIconPage::GetRepresentativeArticleIcon
// =================================================
CTrackManiaEditorIcon * __thiscall
CTrackManiaEditorIconPage::GetRepresentativeArticleIcon
          (CTrackManiaEditorIconPage *this,CTrackManiaEditorIconPage *param_1)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  while( true ) {
    if (*(int *)(this + 0x28) == 0) {
      uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x1c,unaff_EDI);
      if (uVar1 == 0) {
        return (CTrackManiaEditorIcon *)0x0;
      }
    }
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x1c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)unaff_EDI);
    unaff_EDI = (CFastBuffer<class_CCrystalFace*> *)0x0;
    if (*(int *)(*(int *)pSVar2 + 0x14) == 0) break;
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x1c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI)
    ;
    this = *(CTrackManiaEditorIconPage **)(*(int *)pSVar2 + 0x14);
  }
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x1c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  return *(CTrackManiaEditorIcon **)pSVar2;
}
}

