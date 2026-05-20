// Class implementation: CPlugShaderLoadIds

// =================================================
// Function: CPlugShaderLoadIds::FindOrAddLoadId
// =================================================
GmVec4 * __thiscall
CPlugShaderLoadIds::FindOrAddLoadId(void *this,CPlugShaderLoadIds *param_1,ELoadId param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](this,pCVar3,unaff_ESI);
      if (*(ELoadId *)(pSVar2 + 8) == param_2) goto LAB_008707a5;
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  CFastBufferCat<class_GmVec4,struct_CPlugShaderLoadIds::SFxCat>::AddCatOfElems
            (this,(CFastBufferCat<class_GmVec4,struct_CPlugShaderLoadIds::SFxCat> *)
                  (&DAT_00d154f8)[param_2],unaff_ESI);
  pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](this,pCVar3,unaff_EBP);
  *(ELoadId *)(pSVar2 + 8) = param_2;
LAB_008707a5:
  pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](this,pCVar3,unaff_EBX);
  return (GmVec4 *)(*(int *)pSVar2 * 0x10 + *(int *)((int)this + 0x10));
}
}

