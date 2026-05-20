// Class implementation: CGameCtnMediaClipGroup

// =================================================
// Function: CGameCtnMediaClipGroup::ClipFind
// =================================================
ulong __thiscall
CGameCtnMediaClipGroup::ClipFind
          (CGameCtnMediaClipGroup *this,CGameCtnMediaClipGroup *param_1,GmNat3 *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  GxTexCoordSet *unaff_EBP;
  CFastArray<class_GxTexCoordSet> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CMotionSkelBlender::CBlendedBone>::operator[]
                         (this + 0x20,pCVar4,(ulong)param_2);
      iVar3 = CFastBuffer<class_GmNat3>::Find(pSVar2 + 0x18,unaff_ESI,unaff_EBP);
      if (iVar3 != -1) {
        return (ulong)pCVar4;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return 0xffffffff;
}
}

