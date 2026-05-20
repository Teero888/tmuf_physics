// Class implementation: CZoneNode

// =================================================
// Function: CZoneNode::GetHeightStep
// =================================================
ulong __thiscall CZoneNode::GetHeightStep(void *this,CZoneNode *param_1)
{
{
  void *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  if (*(int *)((int)this + 8) == 0) {
    return 0;
  }
  this_00 = (void *)((int)this + 0x10);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar4,(ulong)unaff_ESI);
      unaff_ESI = pCVar4;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_EBP);
      if (*(int *)(*(int *)pSVar3 + 0x34) == *(int *)(*(int *)pSVar2 + 0x38)) {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_EBX)
        ;
        return *(ulong *)(*(int *)pSVar2 + 0x20);
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return 0;
}
}

