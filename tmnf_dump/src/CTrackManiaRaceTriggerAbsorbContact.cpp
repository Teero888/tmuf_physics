// Class implementation: CTrackManiaRaceTriggerAbsorbContact

// =================================================
// Function: CTrackManiaRaceTriggerAbsorbContact::AbsorbContact
// =================================================
void __thiscall
CTrackManiaRaceTriggerAbsorbContact::AbsorbContact
          (CTrackManiaRaceTriggerAbsorbContact *this,CSceneMobilAbsorbContact *param_1,
          CHmsItem *param_2,CHmsPhysicalContact *param_3)
{
{
  int *piVar1;
  CTrackManiaRace *this_00;
  int iVar2;
  CTrackManiaPlayer *pCVar3;
  CGamePlayer *pCVar4;
  CGameRace *unaff_EBP;
  CSceneMobil *unaff_ESI;
  CTrackManiaPlayer *pCVar5;
  
  if ((*(int *)(this + 4) != 0) &&
     (piVar1 = *(int **)(*(int *)(param_1 + 0x40) + 0x1c), piVar1 != (int *)0x0)) {
    pCVar5 = (CTrackManiaPlayer *)0x3057000;
    iVar2 = (**(code **)(*piVar1 + 0x10))();
    if (iVar2 != 0) {
      this_00 = *(CTrackManiaRace **)(this + 4);
      pCVar3 = CTrackManiaRace::GetPlayerFromMobil
                         (this_00,*(CTrackManiaRace **)
                                   (*(int *)(*(int *)(param_1 + 0x40) + 0x48) + 0x40),unaff_ESI);
      if ((pCVar3 != (CTrackManiaPlayer *)0x0) &&
         ((pCVar4 = CGameRace::GetLocalPlayer((CGameRace *)this_00,unaff_EBP),
          pCVar3 == (CTrackManiaPlayer *)pCVar4 ||
          ((*(int *)(*(int *)(this + 4) + 0x330) != 0 &&
           (pCVar3 == *(CTrackManiaPlayer **)(*(int *)(*(int *)(this + 4) + 0x330) + 0x238))))))) {
        CTrackManiaRace::InternalPrepareEvent
                  (*(CTrackManiaRace **)(this + 4),(CTrackManiaRace *)pCVar3,pCVar5);
        iVar2 = *(int *)(piVar1[9] + 0x11c);
        if (iVar2 != 1) {
          if (iVar2 == 2) {
            (**(code **)(**(int **)(this + 4) + 0x178))(pCVar3,piVar1);
            return;
          }
          if (iVar2 != 4) {
            return;
          }
        }
        (**(code **)(**(int **)(this + 4) + 0x170))(pCVar3,piVar1);
      }
    }
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRaceTriggerAbsorbContact::CTrackManiaRaceTriggerAbsorbContact
// =================================================
void __thiscall
CTrackManiaRaceTriggerAbsorbContact::CTrackManiaRaceTriggerAbsorbContact
          (CTrackManiaRaceTriggerAbsorbContact *this,CTrackManiaRaceTriggerAbsorbContact *param_1,
          CTrackManiaRace *param_2)
{
{
  *(undefined ***)this = vftable;
  *(CTrackManiaRaceTriggerAbsorbContact **)(this + 4) = param_1;
  return;
}
}

