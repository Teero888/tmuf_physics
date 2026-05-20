// Class implementation: CTrackManiaEditorFree

// =================================================
// Function: CTrackManiaEditorFree::CreateDefaultParams
// =================================================
/* WARNING: Removing unreachable block (ram,0x004a00d1) */
/* WARNING: Removing unreachable block (ram,0x004a0126) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CTrackManiaEditorFree::CreateDefaultParams
          (CTrackManiaEditorFree *this,CTrackManiaEditor *param_1,SStartParameters *param_2)
{
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  
  uVar1 = *(uint *)(*(int *)(this + 0x20) + 0xb0);
  uVar2 = *(uint *)(*(int *)(this + 0x20) + 0xa8);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  uVar6 = _DAT_00b41130;
  *(uint *)(param_1 + 8) = uVar1 >> 1;
  *(undefined4 *)(param_1 + 0x28) = uVar6;
  *(uint *)param_1 = uVar2 >> 1;
  *(undefined4 *)(param_1 + 4) = 1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  iVar3 = *(int *)(this + 0x20);
  iVar7 = *(int *)(*(int *)(*(int *)(iVar3 + 0x114) + 0x58) + 0x38) + 1;
  fVar5 = (float)iVar7;
  if (iVar7 < 0) {
    fVar5 = fVar5 + _DAT_00c418d0;
  }
  fVar5 = fVar5 * _DAT_00ce9478;
  fVar4 = (float)(*(uint *)(iVar3 + 0xb0) >> 1) * _DAT_00ce9474;
  *(float *)(param_1 + 0x1c) = _DAT_00ce9474 * (float)(*(uint *)(iVar3 + 0xa8) >> 1);
  *(float *)(param_1 + 0x20) = fVar5;
  *(float *)(param_1 + 0x24) = fVar4;
  fVar5 = _DAT_00ce9474 * (float)_DAT_00b40f20;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x18) = 0;
  fVar4 = (float)_DAT_00b33620;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(float *)(param_1 + 0x30) = fVar5 * fVar4;
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}
}

// =================================================
// Function: CTrackManiaEditorFree::Start
// =================================================
void __thiscall CTrackManiaEditorFree::Start(CTrackManiaEditorFree *this,CGameCtnBench *param_1)
{
{
  int iVar1;
  GmNat3 *unaff_ESI;
  undefined4 unaff_retaddr;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  CTrackManiaEditor::Start((CTrackManiaEditor *)this,param_1);
  if (*(int *)(this + 0x514) == 0) {
    *(undefined4 *)(this + 0x514) = 0xffffffff;
  }
  iVar1 = *(int *)(this + 0xbc);
  local_c = *(undefined4 *)(iVar1 + 0x14);
  local_8 = *(undefined4 *)(iVar1 + 0x18);
  local_4 = *(undefined4 *)(iVar1 + 0x1c);
  iVar1 = AdjustCursorHeight(this,(CTrackManiaEditorFree *)&local_c,unaff_ESI);
  if (iVar1 != 0) {
    iVar1 = *(int *)(this + 0xbc);
    *(undefined4 *)(iVar1 + 0x14) = local_8;
    *(undefined4 *)(iVar1 + 0x18) = local_4;
    *(undefined4 *)(iVar1 + 0x1c) = unaff_retaddr;
  }
  return;
}
}

