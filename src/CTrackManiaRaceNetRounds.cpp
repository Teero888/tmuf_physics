// Class implementation: CTrackManiaRaceNetRounds

// =================================================
// Function: CTrackManiaRaceNetRounds::SwitchToRace
// =================================================
void __thiscall
CTrackManiaRaceNetRounds::SwitchToRace
          (CTrackManiaRaceNetRounds *this,CGameRace *param_1,GmNat3 param_2,ECardinalDir param_3)
{
{
  *(undefined4 *)(this + 0x688) = 0;
  CTrackManiaRaceNet::SwitchToRace((CTrackManiaRaceNet *)this,param_1,param_2,param_3);
  return;
}
}

// =================================================
// Function: CTrackManiaRaceNetRounds::UpdateAsync
// =================================================
void __thiscall
CTrackManiaRaceNetRounds::UpdateAsync(CTrackManiaRaceNetRounds *this,CInputPortDx8 *param_1)
{
{
  CPlugAudio *this_00;
  CInputPortDx8 *unaff_retaddr;
  CPlugAudio *in_stack_00000008;
  
  CTrackManiaRaceNet::UpdateAsync((CTrackManiaRaceNet *)this,unaff_retaddr);
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  CPlugAudio::MwGetId(this_00,in_stack_00000008);
  return;
}
}

