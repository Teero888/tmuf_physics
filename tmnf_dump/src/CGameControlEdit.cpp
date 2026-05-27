// Class implementation: CGameControlEdit

// =================================================
// Function: CGameControlEdit::Create
// =================================================
void __thiscall CGameControlEdit::Create(CGameControlEdit *this,CDx9VertexBuffer *param_1)
{
{
  int iVar1;
  CGameControlSelection *pCVar2;
  CGameControlSelection *this_00;
  CMwNod *extraout_EAX;
  CMwNod *extraout_EAX_00;
  CMwNod *extraout_EAX_01;
  CMwNod *unaff_EDI;
  CMwNod *pCVar3;
  CGameControlMove *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ac6081;
  local_c = ExceptionList;
  pCVar2 = (CGameControlSelection *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  this_00 = operator_new(0x54);
  local_4 = 0;
  if (this_00 == (CGameControlSelection *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  }
  else {
    CGameControlSelection::CGameControlSelection(this_00,pCVar2);
    pCVar3 = extraout_EAX;
  }
  if (pCVar3 != *(CMwNod **)(this + 0x1c)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x1c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1c),unaff_EDI);
    }
    *(CMwNod **)(this + 0x1c) = pCVar3;
  }
  pCVar3 = *(CMwNod **)(this + 0x14);
  iVar1 = *(int *)(this + 0x1c);
  if (pCVar3 != *(CMwNod **)(iVar1 + 0x14)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3,unaff_EDI);
    }
    if (*(CMwNod **)(iVar1 + 0x14) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(iVar1 + 0x14),unaff_EDI);
    }
    *(CMwNod **)(iVar1 + 0x14) = pCVar3;
  }
  local_c = operator_new(0xa8);
  if (local_c == (CGameControlMove *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  }
  else {
    CGameControlMove::CGameControlMove(local_c,(CGameControlMove *)unaff_EDI);
    pCVar3 = extraout_EAX_00;
  }
  if (pCVar3 != *(CMwNod **)(this + 0x20)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x20) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x20),unaff_EDI);
    }
    *(CMwNod **)(this + 0x20) = pCVar3;
  }
  pCVar3 = *(CMwNod **)(this + 0x14);
  iVar1 = *(int *)(this + 0x20);
  if (pCVar3 != *(CMwNod **)(iVar1 + 0x14)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3,unaff_EDI);
    }
    if (*(CMwNod **)(iVar1 + 0x14) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(iVar1 + 0x14),unaff_EDI);
    }
    *(CMwNod **)(iVar1 + 0x14) = pCVar3;
  }
  local_c = operator_new(0x20);
  if (local_c == (CGameControlMove *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  }
  else {
    CGameControlRotate::CGameControlRotate
              ((CGameControlRotate *)local_c,(CGameControlRotate *)unaff_EDI);
    pCVar3 = extraout_EAX_01;
  }
  if (pCVar3 != *(CMwNod **)(this + 0x24)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x24) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x24),unaff_EDI);
    }
    *(CMwNod **)(this + 0x24) = pCVar3;
  }
  ExceptionList = puStack_8;
  return;
}
}

