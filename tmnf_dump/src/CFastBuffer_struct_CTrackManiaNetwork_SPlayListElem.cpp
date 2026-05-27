// Class implementation: CFastBuffer_struct_CTrackManiaNetwork_SPlayListElem

// =================================================
// Function: CFastBuffer<struct_CTrackManiaNetwork::SPlayListElem>::CopyFromFastBuffer
// =================================================
void __thiscall
CFastBuffer<struct_CTrackManiaNetwork::SPlayListElem>::CopyFromFastBuffer
          (void *this,CFastBuffer<struct_CDx9StateBlock::STexStageState> *param_1,
          CFastBuffer<struct_CDx9StateBlock::STexStageState> *param_2)
{
{
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastStringInt *unaff_EBP;
  int iVar5;
  CFastBuffer<struct_SCtnForcedMods::SEnvMod> *unaff_ESI;
  void *this_00;
  GmFrustumIso4 *unaff_EDI;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *this_01;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *in_stack_0000001c;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffec;
  SStringParam *pSVar6;
  
  pSVar6 = this;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this,unaff_EDI);
  this_01 = param_2;
  pCVar1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)
           CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize(param_2,unaff_ESI);
  SetSizeAtLeast(this,pCVar1,unaff_EBX);
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_01,in_stack_ffffffec);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (uVar2 == 0) {
    *(undefined4 *)this = 0;
    return;
  }
  iVar5 = 0;
  do {
    pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (this_01,pCVar4,(ulong)unaff_EBP);
    in_stack_0000000c = *(undefined4 *)pSVar3;
    param_2 = *(CFastBuffer<struct_CDx9StateBlock::STexStageState> **)(pSVar3 + 4);
    unaff_EBP = (CFastStringInt *)&param_2;
    this_00 = (void *)(*(int *)((int)this + 4) + iVar5);
    in_stack_00000010 = 0;
    CFastStringInt::SetString(this_00,unaff_EBP,pSVar6);
    pCVar4 = pCVar4 + 1;
    iVar5 = iVar5 + 0xc;
    *(undefined4 *)((int)this_00 + 8) = *(undefined4 *)(pSVar3 + 8);
    this = param_2;
    this_01 = in_stack_0000001c;
  } while (pCVar4 < param_1);
  *(CFastBuffer<struct_CDx9StateBlock::STexStageState> **)param_2 = param_1;
  return;
}
}

