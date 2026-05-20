// Class implementation: CFastBuffer_struct_CPlugVisual_SSplit

// =================================================
// Function: CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  CFastBuffer<class_GxVertex>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(*(int *)((int)this + 4) + iVar1 * 0x28);
}
}

// =================================================
// Function: CFastBuffer<struct_CPlugVisual::SSplit>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<struct_CPlugVisual::SSplit>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  CFastBuffer<class_GxVertex>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

// =================================================
// Function: CFastBuffer<struct_CPlugVisual::SSplit>::CopyFromFastBuffer
// =================================================
void __thiscall
CFastBuffer<struct_CPlugVisual::SSplit>::CopyFromFastBuffer
          (void *this,CFastBuffer<struct_CDx9StateBlock::STexStageState> *param_1,
          CFastBuffer<struct_CDx9StateBlock::STexStageState> *param_2)
{
{
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  int iVar4;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  ulong unaff_EBP;
  int iVar6;
  CFastBuffer<struct_SCtnForcedMods::SEnvMod> *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  undefined4 *puVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000000c;
  undefined4 *in_stack_00000010;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *in_stack_00000018;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff8;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this,unaff_EDI);
  pCVar1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)
           CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize(param_2,unaff_ESI);
  CFastBuffer<class_GxVertex>::SetSizeAtLeast(this,pCVar1,unaff_EBX);
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(param_2,in_stack_fffffff8);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (uVar2 == 0) {
    *(undefined4 *)this = 0;
    return;
  }
  iVar6 = 0;
  do {
    pSVar3 = operator[](param_2,pCVar5,unaff_EBP);
    puVar7 = (undefined4 *)(*(int *)((int)this + 4) + iVar6);
    pCVar5 = pCVar5 + 1;
    iVar6 = iVar6 + 0x28;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *(undefined4 *)pSVar3;
      pSVar3 = pSVar3 + 4;
      puVar7 = puVar7 + 1;
    }
    this = in_stack_00000010;
    param_2 = in_stack_00000018;
  } while (pCVar5 < in_stack_0000000c);
  *in_stack_00000010 = in_stack_0000000c;
  return;
}
}

