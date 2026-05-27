// Class implementation: CMwEngineInfo

// =================================================
// Function: CMwEngineInfo::AddClass
// =================================================
void __thiscall
CMwEngineInfo::AddClass(CMwEngineInfo *this,CMwEngineInfo *param_1,CMwClassInfo *param_2)
{
{
  CMwEngineInfo *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  undefined4 in_stack_00000010;
  
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(*(uint *)(param_1 + 4) >> 0xc & 0xfff)
  ;
  this_00 = this + 0xc;
  if (*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0xc) <= pCVar4) {
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
    pCVar3 = (CFastBuffer<class_CSystemFidsFolder*> *)(pCVar4 + 1);
    if (pCVar3 < (CFastBuffer<class_CSystemFidsFolder*> *)&DAT_00000020) {
      pCVar3 = (CFastBuffer<class_CSystemFidsFolder*> *)&DAT_00000020;
    }
    CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount(this_00,pCVar3,unaff_EBX);
    for (; pCVar1 < pCVar3; pCVar1 = pCVar1 + 1) {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar1,unaff_EDI);
      *(undefined4 *)pSVar2 = 0;
    }
  }
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_retaddr);
  *(undefined4 *)pSVar2 = in_stack_00000010;
  return;
}
}

// =================================================
// Function: CMwEngineInfo::CMwEngineInfo
// =================================================
void __thiscall CMwEngineInfo::CMwEngineInfo(CMwEngineInfo *this,CMwEngineInfo *param_1)
{
{
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0xc,unaff_ESI);
  return;
}
}

