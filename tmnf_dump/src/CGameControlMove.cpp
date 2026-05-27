// Class implementation: CGameControlMove

// =================================================
// Function: CGameControlMove::CGameControlMove
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameControlMove::CGameControlMove(CGameControlMove *this,CGameControlMove *param_1)
{
{
  undefined *puVar1;
  GmIso4 *unaff_ESI;
  CMwNod *unaff_EDI;
  void *unaff_retaddr;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ac6043;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe8),unaff_EDI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  puVar1 = PTR_DAT_00d00604;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x9c) = _DAT_00b36144;
  *(undefined4 *)(this + 0xa0) = _DAT_00b33a54;
  LocationSet(this,(CGameControlMove *)puVar1,unaff_ESI);
  *(undefined4 *)(this + 0xa4) = 0;
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CGameControlMove::LocationRefUpdate
// =================================================
void __thiscall
CGameControlMove::LocationRefUpdate(CGameControlMove *this,CGameControlMove *param_1)
{
{
  int iVar1;
  CGameControlMove *pCVar2;
  CGameControlMove *pCVar3;
  
  if (*(int *)(this + 0x7c) == 0) {
    *(undefined4 *)(this + 0x70) = *(undefined4 *)(this + 0x40);
    *(undefined4 *)(this + 0x74) = *(undefined4 *)(this + 0x44);
    *(undefined4 *)(this + 0x78) = *(undefined4 *)(this + 0x48);
    GmMat3::SetIdentity(this + 0x4c,(GmMat43 *)param_1);
    return;
  }
  if (*(int *)(this + 0x7c) == 1) {
    pCVar2 = this + 0x1c;
    pCVar3 = this + 0x4c;
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)pCVar3 = *(undefined4 *)pCVar2;
      pCVar2 = pCVar2 + 4;
      pCVar3 = pCVar3 + 4;
    }
  }
  return;
}
}

// =================================================
// Function: CGameControlMove::LocationSet
// =================================================
void __thiscall
CGameControlMove::LocationSet(CGameControlMove *this,CGameControlMove *param_1,GmIso4 *param_2)
{
{
  int iVar1;
  CGameControlMove *unaff_EDI;
  CGameControlMove *pCVar2;
  
  pCVar2 = this + 0x1c;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pCVar2 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    pCVar2 = pCVar2 + 4;
  }
  LocationRefUpdate(this,unaff_EDI);
  return;
}
}

