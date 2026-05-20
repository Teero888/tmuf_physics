// Class implementation: CTrackManiaRaceNetTimeAttack

// =================================================
// Function: CTrackManiaRaceNetTimeAttack::UpdateAsync
// =================================================
void __thiscall
CTrackManiaRaceNetTimeAttack::UpdateAsync(CTrackManiaRaceNetTimeAttack *this,CInputPortDx8 *param_1)
{
{
  CMwId *pCVar1;
  CPlugAudio *this_00;
  CInputPortDx8 *unaff_ESI;
  CPlugAudio *unaff_retaddr;
  
  CTrackManiaRaceNet::UpdateAsync((CTrackManiaRaceNet *)this,unaff_ESI);
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar1 = CPlugAudio::MwGetId(this_00,unaff_retaddr);
  if ((*(uint *)(this + 0x1f0) != 0) && (*(uint *)(this + 0x1f0) <= *(uint *)pCVar1)) {
    if (*(CTrackManiaRaceInterface **)(this + 0x518) != (CTrackManiaRaceInterface *)0x0) {
      CTrackManiaRaceInterface::OnStuntEvent
                (*(CTrackManiaRaceInterface **)(this + 0x518),
                 (CTrackManiaRaceInterface *)(this + 0x204),(SEventStunt *)param_1);
    }
    *(undefined4 *)(this + 0x1f0) = 0;
  }
  return;
}
}

