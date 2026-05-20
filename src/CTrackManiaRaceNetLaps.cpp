// Class implementation: CTrackManiaRaceNetLaps

// =================================================
// Function: CTrackManiaRaceNetLaps::UpdateAsync
// =================================================
void __thiscall
CTrackManiaRaceNetLaps::UpdateAsync(CTrackManiaRaceNetLaps *this,CInputPortDx8 *param_1)
{
{
  CMwId *pCVar1;
  CGamePlayerInfo *pCVar2;
  int iVar3;
  CGameCtnNetwork *pCVar4;
  ulong uVar5;
  CPlugAudio *this_00;
  CGameRace *unaff_EBX;
  int iVar6;
  CInputPortDx8 *unaff_ESI;
  CPlugAudio *unaff_EDI;
  int unaff_retaddr;
  CGameRace *in_stack_00000008;
  CGameRace *in_stack_0000000c;
  CTrackManiaRaceNet *in_stack_00000018;
  CGameRace *in_stack_0000001c;
  CGameCtnNetwork *in_stack_00000020;
  CGameCtnNetwork *in_stack_0000002c;
  
  CTrackManiaRace::UpdateAsync((CTrackManiaRace *)this,unaff_ESI);
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar1 = CPlugAudio::MwGetId(this_00,unaff_EDI);
  iVar6 = *(int *)pCVar1;
  pCVar2 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,unaff_EBX);
  if ((*(int *)(pCVar2 + 0x70) == 0) && (*(int *)(pCVar2 + 0x74) == 0)) {
    CTrackManiaRaceNet::RaceInputsSendToServer
              ((CTrackManiaRaceNet *)this,(CTrackManiaRaceNet *)0x0,unaff_retaddr);
  }
  else {
    iVar3 = (**(code **)(*(int *)this + 0xec))();
    if ((iVar3 != 0) && (*(int *)(this + 0x680) != 0)) {
      iVar3 = (**(code **)(*(int *)this + 0x260))();
      if (iVar3 != 0) {
        iVar3 = (**(code **)(*(int *)this + 0x264))();
        if (iVar3 != 0) {
          (**(code **)(*(int *)this + 0x268))();
          *(undefined4 *)(this + 0x680) = 0;
          if (*(int *)(this + 0x98) != 0) {
            (**(code **)(*(int *)this + 0x1b8))();
          }
        }
      }
    }
  }
  pCVar2 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,(CGameRace *)param_1);
  if ((*(int *)(pCVar2 + 0x314) == 2) && (*(int *)(this + 0x5c4) == -1)) {
    pCVar2 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,in_stack_00000008);
    if ((*(int *)(pCVar2 + 0x70) == 0) && (*(int *)(pCVar2 + 0x74) == 0)) {
      iVar6 = iVar6 + 2000;
    }
    else {
      iVar6 = iVar6 + 500;
    }
    *(int *)(this + 0x5c4) = iVar6;
    *(undefined4 *)(this + 0x74) = 0xffffffff;
    *(undefined4 *)(this + 0x78) = 0xffffffff;
  }
  pCVar2 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,in_stack_0000000c);
  if ((*(int *)(pCVar2 + 0x70) != 0) || (*(int *)(pCVar2 + 0x74) != 0)) {
    CTrackManiaRaceNet::SpectatorCameraChange((CTrackManiaRaceNet *)this,in_stack_00000018);
  }
  if (*(int *)(this + 0x50) == 0) {
    iVar6 = (**(code **)(*(int *)this + 0x1a0))();
    if (iVar6 != 0) {
      CGameRace::SetStatus((CGameRace *)this,(CGameRace *)&DAT_00000004,(EStatus)in_stack_0000001c);
    }
    pCVar2 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,in_stack_0000001c);
    if (((*(int *)(pCVar2 + 0x70) == 0) && (*(int *)(pCVar2 + 0x74) == 0)) &&
       (*(int **)(this + 0x18) != (int *)0x0)) {
      iVar6 = (**(code **)(**(int **)(this + 0x18) + 0x118))();
      if (iVar6 != 0) {
        pCVar4 = (CGameCtnNetwork *)(**(code **)(**(int **)(this + 0x18) + 0x118))();
        uVar5 = CGameCtnNetwork::GetNbAutoSpectators(pCVar4,in_stack_00000020);
        if (uVar5 != 0) {
          iVar6 = (**(code **)(*(int *)this + 0xe0))();
          if (iVar6 == 0) {
            this[0x1c] = (CTrackManiaRaceNetLaps)0xff;
          }
          else {
            this[0x1c] = *(CTrackManiaRaceNetLaps *)(iVar6 + 0x24);
          }
          if (iVar6 != *(int *)(this + 0x98)) {
            *(int *)(this + 0x98) = iVar6;
            pCVar4 = (CGameCtnNetwork *)(**(code **)(**(int **)(this + 0x18) + 0x118))();
            CGameCtnNetwork::UpdateSpectatorsCounts(pCVar4,in_stack_0000002c);
            return;
          }
        }
      }
    }
  }
  return;
}
}

