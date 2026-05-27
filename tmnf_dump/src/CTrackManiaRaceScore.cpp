// Class implementation: CTrackManiaRaceScore

// =================================================
// Function: CTrackManiaRaceScore::CTrackManiaRaceScore
// =================================================
void __thiscall
CTrackManiaRaceScore::CTrackManiaRaceScore(CTrackManiaRaceScore *this,CTrackManiaRaceScore *param_1)
{
{
  CMwNod *unaff_ESI;
  void *unaff_retaddr;
  CTrackManiaRaceScore *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a84d63;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec),unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  Reset(this,(GmFrustumIso4 *)pCVar1);
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CTrackManiaRaceScore::GetPlayerUid
// =================================================
uchar __thiscall
CTrackManiaRaceScore::GetPlayerUid(CTrackManiaRaceScore *this,CTrackManiaRaceScore *param_1)
{
{
  if (*(int *)(this + 0x54) != 0) {
    return *(uchar *)(*(int *)(this + 0x54) + 0x24);
  }
  return 0xff;
}
}

// =================================================
// Function: CTrackManiaRaceScore::InitScores
// =================================================
void __thiscall
CTrackManiaRaceScore::InitScores
          (CTrackManiaRaceScore *this,CTrackManiaRaceScore *param_1,CTrackManiaPlayerInfo *param_2,
          int param_3)
{
{
  int iVar1;
  CMwNod *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  
  iVar1 = *(int *)(this + 0x4c);
  if (param_2 != (CTrackManiaPlayerInfo *)0x0) {
    Reset(this,unaff_EDI);
  }
  if (param_2 != *(CTrackManiaPlayerInfo **)(this + 0x54)) {
    if (param_2 != (CTrackManiaPlayerInfo *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_2,unaff_ESI);
    }
    if (*(CMwNod **)(this + 0x54) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x54),unaff_ESI);
    }
    *(CTrackManiaPlayerInfo **)(this + 0x54) = param_2;
  }
  if ((iVar1 == 0) && (*(int *)(param_2 + 0x1dc) == 0)) {
    *(undefined4 *)(this + 0x50) = 0;
    *(undefined4 *)(this + 0x4c) = 0;
    return;
  }
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x4c) = 1;
  return;
}
}

// =================================================
// Function: CTrackManiaRaceScore::IsNullScore
// =================================================
int __thiscall
CTrackManiaRaceScore::IsNullScore(CTrackManiaRaceScore *this,CTrackManiaRaceScore *param_1)
{
{
  if (((*(int *)(this + 0x14) == 0) && (*(int *)(this + 0x18) == -1)) &&
     (*(int *)(this + 0x1c) == 0)) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CTrackManiaRaceScore::IsPureSpectator
// =================================================
int __thiscall
CTrackManiaRaceScore::IsPureSpectator(CTrackManiaRaceScore *this,CTrackManiaPlayerInfo *param_1)
{
{
  int iVar1;
  int extraout_ECX;
  CTrackManiaRaceScore *unaff_retaddr;
  CTrackManiaPlayerInfo *in_stack_00000008;
  
  iVar1 = IsNullScore(this,unaff_retaddr);
  if ((iVar1 != 0) &&
     (*(CTrackManiaPlayerInfo **)(extraout_ECX + 0x54) != (CTrackManiaPlayerInfo *)0x0)) {
    iVar1 = CTrackManiaPlayerInfo::IsPureSpectator
                      (*(CTrackManiaPlayerInfo **)(extraout_ECX + 0x54),in_stack_00000008);
    return iVar1;
  }
  return 0;
}
}

