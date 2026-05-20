// Class implementation: CFastBuffer_class_CMwNodRef_class_CGameCtnGhostInfo

// =================================================
// Function: CFastBuffer<class_CMwNodRef<class_CGameCtnGhostInfo>_>::SwapElemsAt
// =================================================
void __thiscall
CFastBuffer<class_CMwNodRef<class_CGameCtnGhostInfo>_>::SwapElemsAt
          (void *this,CFastBuffer<struct_CVisionViewport::SDelayedToSort64b> *param_1,ulong param_2,
          ulong param_3)
{
{
  int iVar1;
  int iVar2;
  CMwNod *pCVar3;
  CMwNod *this_00;
  CMwNod *pCVar4;
  CMwNod *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a87818;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = (int)param_1 * 4;
  pCVar4 = *(CMwNod **)(*(int *)((int)this + 4) + iVar2);
  this_00 = (CMwNod *)0x0;
  if (pCVar4 != (CMwNod *)0x0) {
    CMwNod::MwAddRef(pCVar4,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
    this_00 = pCVar4;
  }
  iVar1 = *(int *)((int)this + 4);
  pCVar3 = (CMwNod *)(param_3 * 4);
  pCVar4 = *(CMwNod **)(pCVar3 + iVar1);
  if (pCVar4 != *(CMwNod **)(iVar1 + iVar2)) {
    if (pCVar4 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar4,unaff_EDI);
      this_00 = pCVar3;
    }
    if (*(CMwNod **)(iVar1 + iVar2) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(iVar1 + iVar2),unaff_EDI);
      this_00 = pCVar3;
    }
    *(CMwNod **)(iVar1 + iVar2) = pCVar4;
  }
  pCVar4 = pCVar3 + *(int *)((int)this + 4);
  if (this_00 != *(CMwNod **)pCVar4) {
    if (this_00 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_00,unaff_EDI);
      this_00 = pCVar3;
    }
    if (*(CMwNod **)pCVar4 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)pCVar4,unaff_EDI);
      this_00 = pCVar3;
    }
    *(CMwNod **)pCVar4 = this_00;
  }
  if (this_00 != (CMwNod *)0x0) {
    CMwNod::MwRelease(this_00,unaff_EDI);
  }
  ExceptionList = puStack_8;
  return;
}
}

