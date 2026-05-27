// Class implementation: CFastBufferCat_struct_CHmsViewport_SVisibleCamera_struct_CHmsViewport_SVisibleZoneCat

// =================================================
// Function: SetCatCount
// =================================================
void __thiscall
CFastBufferCat<struct_CHmsViewport::SVisibleCamera,struct_CHmsViewport::SVisibleZoneCat>::
SetCatCount(void *this,
           CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
           *param_1,ulong param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_retaddr;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
  if ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2 != pCVar1) {
    CFastBuffer<class_GmVec3>::SetSizeAtLeast
              (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_2,unaff_ESI);
    CFastBuffer<class_CSystemFidsFolder*>::SetCount
              (this,(CFastBuffer<class_CSystemFidsFolder*> *)param_2,unaff_EBX);
    if (param_2 <= pCVar1) {
      CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat>::SetParsingAll
                (this,(CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat> *)unaff_retaddr);
      return;
    }
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0xc),unaff_EBP);
    for (; pCVar1 < param_2; pCVar1 = pCVar1 + 1) {
      pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this,pCVar1,(ulong)unaff_retaddr);
      *(ulong *)pSVar3 = uVar2;
      unaff_retaddr = pCVar1;
      pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this,pCVar1,(ulong)param_1);
      *(undefined4 *)(pSVar3 + 4) = 0;
    }
  }
  return;
}
}

