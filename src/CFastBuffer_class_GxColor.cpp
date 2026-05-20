// Class implementation: CFastBuffer_class_GxColor

// =================================================
// Function: CFastBuffer<class_GxColor>::CopyFromFastBuffer
// =================================================
void __thiscall
CFastBuffer<class_GxColor>::CopyFromFastBuffer
          (void *this,CFastBuffer<struct_CDx9StateBlock::STexStageState> *param_1,
          CFastBuffer<struct_CDx9StateBlock::STexStageState> *param_2)
{
{
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  undefined4 *puVar4;
  ulong unaff_EBX;
  CFastBuffer<struct_SCtnForcedMods::SEnvMod> *unaff_EBP;
  GmFrustumIso4 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  ulong unaff_EDI;
  int iVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_retaddr;
  void *in_stack_00000014;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this,unaff_ESI);
  pCVar1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)
           CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize(param_2,unaff_EBP);
  CFastBuffer<class_GmInt4>::SetSizeAtLeast(this,pCVar1,unaff_EBX);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_2,unaff_retaddr);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    iVar6 = 0;
    do {
      pSVar3 = operator[](in_stack_00000014,pCVar5,unaff_EDI);
      puVar4 = (undefined4 *)(*(int *)((int)this + 4) + iVar6);
      *puVar4 = *(undefined4 *)pSVar3;
      puVar4[1] = *(undefined4 *)(pSVar3 + 4);
      puVar4[2] = *(undefined4 *)(pSVar3 + 8);
      pCVar5 = pCVar5 + 1;
      iVar6 = iVar6 + 0x10;
      puVar4[3] = *(undefined4 *)(pSVar3 + 0xc);
    } while (pCVar5 < pCVar2);
  }
  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this = pCVar2;
  return;
}
}

