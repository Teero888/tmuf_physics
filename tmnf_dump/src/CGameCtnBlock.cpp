// Class implementation: CGameCtnBlock

// =================================================
// Function: CGameCtnBlock::GetMobilLoc
// =================================================
void __thiscall
CGameCtnBlock::GetMobilLoc(CGameCtnBlock *this,CGameCtnBlock *param_1,GmIso4 *param_2)
{
{
  GetMobilLoc(param_1,param_1,(GmIso4 *)(this + 0x48));
  return;
}
}

// =================================================
// Function: CGameCtnBlock::GetSpawnLoc
// =================================================
void __thiscall
CGameCtnBlock::GetSpawnLoc
          (CGameCtnBlock *this,CGameCtnBlock *param_1,GmIso4 *param_2,ulong param_3,ulong param_4)
{
{
  GmIso4 *pGVar1;
  GmNat3 *unaff_ESI;
  GmIso4 *unaff_retaddr;
  
  pGVar1 = (GmIso4 *)(*(int *)(this + 0x24) + 0x80);
  if ((*(uint *)(this + 0x60) >> 0xc & 1) == 0) {
    pGVar1 = (GmIso4 *)(*(int *)(this + 0x24) + 0xb0);
  }
  InternalGetSpawnLoc(pGVar1,(GmNat3 *)param_2,param_3,unaff_ESI,unaff_retaddr,(ulong)param_1,
                      (ulong)param_2);
  return;
}
}

// =================================================
// Function: CGameCtnBlock::GetType
// =================================================
EBlockType __thiscall CGameCtnBlock::GetType(CGameCtnBlock *this,CGameCtnBlock *param_1)
{
{
  if (*(int *)(this + 0x24) != 0) {
    return *(EBlockType *)(*(int *)(this + 0x24) + 0x7c);
  }
  return 0;
}
}

