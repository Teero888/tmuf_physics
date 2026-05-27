// Class implementation: CTrackManiaEditorSimple

// =================================================
// Function: CTrackManiaEditorSimple::CreateDefaultParams
// =================================================
/* WARNING: Removing unreachable block (ram,0x00445833) */
/* WARNING: Removing unreachable block (ram,0x00445888) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CTrackManiaEditorSimple::CreateDefaultParams
          (CTrackManiaEditorSimple *this,CTrackManiaEditor *param_1,SStartParameters *param_2)
{
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  SStartParameters *unaff_EDI;
  
  CTrackManiaEditorPuzzle::CreateDefaultParams((CTrackManiaEditorPuzzle *)this,param_1,unaff_EDI);
  uVar1 = *(uint *)(*(int *)(this + 0x20) + 0xb0);
  uVar2 = *(uint *)(*(int *)(this + 0x20) + 0xa8);
  *(undefined4 *)(param_1 + 0x2c) = _DAT_00b3347c;
  *(undefined4 *)(param_1 + 0x28) = _DAT_00b33628;
  *(uint *)param_1 = uVar2 / 3;
  *(undefined4 *)(param_1 + 4) = 1;
  *(uint *)(param_1 + 8) = uVar1 >> 1;
  iVar3 = *(int *)(this + 0x20);
  iVar6 = *(int *)(*(int *)(*(int *)(iVar3 + 0x114) + 0x58) + 0x38) + 1;
  fVar5 = (float)iVar6;
  if (iVar6 < 0) {
    fVar5 = fVar5 + _DAT_00c418d0;
  }
  fVar5 = fVar5 * _DAT_00ce9478;
  fVar4 = (float)(*(uint *)(iVar3 + 0xb0) >> 1) * _DAT_00ce9474;
  *(float *)(param_1 + 0x1c) = _DAT_00ce9474 * (float)(*(uint *)(iVar3 + 0xa8) / 3);
  *(float *)(param_1 + 0x20) = fVar5;
  *(float *)(param_1 + 0x24) = fVar4;
  fVar5 = _DAT_00ce9474 * (float)_DAT_00b2f718;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(float *)(param_1 + 0x30) = fVar5 * (float)_DAT_00b33620;
  return;
}
}

// =================================================
// Function: CTrackManiaEditorSimple::Start
// =================================================
void __thiscall CTrackManiaEditorSimple::Start(CTrackManiaEditorSimple *this,CGameCtnBench *param_1)
{
{
  int unaff_ESI;
  
  CTrackManiaEditorPuzzle::Start((CTrackManiaEditorPuzzle *)this,param_1);
  CGameCtnChallenge::SetIsBlockHelpers
            (*(CGameCtnChallenge **)(this + 0x20),(CGameCtnChallenge *)0x0,0,unaff_ESI);
  *(undefined4 *)(*(int *)(this + 0xbc) + 0xf4) = 0;
  return;
}
}

