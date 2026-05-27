// Class implementation: CGameMenu

// =================================================
// Function: CGameMenu::SetGame
// =================================================
void __thiscall CGameMenu::SetGame(CGameMenu *this,CGameMenu *param_1,CGameApp *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CGameMenu *unaff_EBP;
  CGameMenu *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  *(CGameMenu **)(this + 0x7c) = param_1;
  *(uint *)(this + 0xb0) = (uint)(param_1 != (CGameMenu *)0x0);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x68,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x68,pCVar3,(ulong)unaff_ESI);
      unaff_ESI = this;
      CGameMenuFrame::SetMenu(*(CGameMenuFrame **)pSVar2,(CGameMenuFrame *)this,unaff_EBP);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

