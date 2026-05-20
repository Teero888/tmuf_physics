// Class implementation: CTrackManiaEditorPuzzle

// =================================================
// Function: CTrackManiaEditorPuzzle::CreateDefaultParams
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CTrackManiaEditorPuzzle::CreateDefaultParams
          (CTrackManiaEditorPuzzle *this,CTrackManiaEditor *param_1,SStartParameters *param_2)
{
{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  CGameCtnBlock *pCVar4;
  uint uVar5;
  ulong unaff_ESI;
  SStartParameters *unaff_EDI;
  
  CTrackManiaEditorFree::CreateDefaultParams((CTrackManiaEditorFree *)this,param_1,unaff_EDI);
  pCVar4 = CGameCtnChallenge::GetStartLine
                     (*(CGameCtnChallenge **)(this + 0x20),(CGameCtnChallenge *)0x0,unaff_ESI);
  if (pCVar4 != (CGameCtnBlock *)0x0) {
    *(undefined4 *)param_1 = *(undefined4 *)(pCVar4 + 0x48);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(pCVar4 + 0x4c);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(pCVar4 + 0x50);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(pCVar4 + 0x54);
    switch(*(undefined4 *)(pCVar4 + 0x54)) {
    case 0:
      uVar1 = 0;
      break;
    case 1:
      uVar1 = _DAT_00b36108;
      break;
    case 2:
      uVar1 = _DAT_00b3c858;
      break;
    case 3:
      uVar1 = _DAT_00b3c85c;
      break;
    default:
      goto switchD_004718eb_default;
    }
    *(undefined4 *)(param_1 + 0x2c) = uVar1;
  }
switchD_004718eb_default:
  fVar3 = (float)_DAT_00b33a58;
  uVar5 = *(uint *)param_1;
  if (uVar5 < *(int *)(*(int *)(this + 0x20) + 0xa8) - 2U) {
    fVar2 = fVar3;
    if (1 < uVar5) goto LAB_0047194f;
  }
  else {
    uVar5 = *(int *)(*(int *)(this + 0x20) + 0xa8) - 3;
LAB_0047194f:
    fVar2 = (float)(int)uVar5;
    if ((int)uVar5 < 0) {
      fVar2 = fVar2 + _DAT_00c418d0;
    }
  }
  *(float *)(param_1 + 0x1c) = fVar2 * _DAT_00ce9474;
  uVar5 = *(uint *)(param_1 + 8);
  if (uVar5 < *(int *)(*(int *)(this + 0x20) + 0xb0) - 2U) {
    if (uVar5 < 2) goto LAB_0047199d;
  }
  else {
    uVar5 = *(int *)(*(int *)(this + 0x20) + 0xb0) - 3;
  }
  fVar3 = (float)(int)uVar5;
  if ((int)uVar5 < 0) {
    fVar3 = fVar3 + _DAT_00c418d0;
  }
LAB_0047199d:
  *(float *)(param_1 + 0x24) = fVar3 * _DAT_00ce9474;
  fVar3 = (float)*(int *)(param_1 + 4);
  if (*(int *)(param_1 + 4) < 0) {
    fVar3 = fVar3 + _DAT_00c418d0;
  }
  fVar3 = fVar3 * _DAT_00ce9478;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(float *)(param_1 + 0x20) = fVar3;
  return;
}
}

// =================================================
// Function: CTrackManiaEditorPuzzle::Start
// =================================================
void __thiscall CTrackManiaEditorPuzzle::Start(CTrackManiaEditorPuzzle *this,CGameCtnBench *param_1)
{
{
  CSceneToyMotorbike *unaff_ESI;
  
  CTrackManiaEditorFree::Start((CTrackManiaEditorFree *)this,param_1);
  (**(code **)(*(int *)this + 200))();
  CTrackManiaEditorInterface::Show(*(CTrackManiaEditorInterface **)(this + 0xb8),unaff_ESI);
  (**(code **)(*(int *)this + 0xd4))(1);
  return;
}
}

