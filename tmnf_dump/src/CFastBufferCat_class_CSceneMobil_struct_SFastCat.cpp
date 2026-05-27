// Class implementation: CFastBufferCat_class_CSceneMobil_struct_SFastCat

// =================================================
// Function: struct_SFastCat>::ResetCatDescs
// =================================================
void __thiscall
CFastBufferCat<class_CSceneMobil*,struct_SFastCat>::ResetCatDescs
          (void *this,
          CFastBufferCat<enum__D3DFORMAT,struct_CDx9DeviceCaps::STextureRenderCat> *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_SFastCat>::operator[](this,pCVar3,(ulong)unaff_ESI);
      *(undefined4 *)pSVar2 = 0;
      unaff_ESI = pCVar3;
      pSVar2 = CFastBuffer<struct_SFastCat>::operator[](this,pCVar3,unaff_EBX);
      pCVar3 = pCVar3 + 1;
      *(undefined4 *)(pSVar2 + 4) = 0;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

