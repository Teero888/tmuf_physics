// Class implementation: CTrackManiaEditorTerrain

// =================================================
// Function: CTrackManiaEditorTerrain::AdjustCursorHeight
// =================================================
int __thiscall
CTrackManiaEditorTerrain::AdjustCursorHeight
          (CTrackManiaEditorTerrain *this,CTrackManiaEditorFree *param_1,GmNat3 *param_2)
{
{
  int iVar1;
  CGameCtnFieldUnit *pCVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 1;
  pCVar2 = CGameCtnChallenge::GetFieldUnit
                     (*(CGameCtnChallenge **)(this + 0x20),*(CGameCtnChallenge **)param_1,
                      (GmNat3)0x1);
  while (pCVar2 != (CGameCtnFieldUnit *)0x0) {
    if (*(int *)(pCVar2 + 8) == 1) goto LAB_00474515;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    pCVar2 = CGameCtnChallenge::GetFieldUnit
                       (*(CGameCtnChallenge **)(this + 0x20),*(CGameCtnChallenge **)param_1,
                        SUB41(*(undefined4 *)(param_1 + 4),0));
  }
  *(undefined4 *)(param_1 + 4) = 0;
LAB_00474515:
  return (uint)(*(int *)(param_1 + 4) != iVar1);
}
}

// =================================================
// Function: CTrackManiaEditorTerrain::GetCoordFromIndex
// =================================================
GmNat3 __thiscall
CTrackManiaEditorTerrain::GetCoordFromIndex
          (CTrackManiaEditorTerrain *this,CGameOutlineBox *param_1,ulong param_2,GmNat3 param_3)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(this + 0x20) + 0xb0);
  *(uint *)param_1 = param_2 / uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  *(uint *)(param_1 + 8) = param_2 % uVar1;
  return SUB41(param_1,0);
}
}

// =================================================
// Function: CTrackManiaEditorTerrain::GetIndexFromCoord
// =================================================
ulong __thiscall
CTrackManiaEditorTerrain::GetIndexFromCoord
          (CTrackManiaEditorTerrain *this,CGameOutlineBox *param_1,GmNat3 param_2,GmNat3 param_3)
{
{
  undefined3 in_stack_0000000d;
  
  return *(int *)(*(int *)(this + 0x20) + 0xb0) * (int)param_1 + _param_3;
}
}

