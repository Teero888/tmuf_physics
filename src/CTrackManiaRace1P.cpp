// Class implementation: CTrackManiaRace1P

// =================================================
// Function: CTrackManiaRace1P::UpdateAsync
// =================================================
void __thiscall CTrackManiaRace1P::UpdateAsync(CTrackManiaRace1P *this,CInputPortDx8 *param_1)
{
{
  CInputPortDx8 *unaff_ESI;
  CTrackManiaRace *in_stack_00000008;
  
  CTrackManiaRace::UpdateAsync((CTrackManiaRace *)this,unaff_ESI);
  CTrackManiaRace::Ghosts_UpdateAsync((CTrackManiaRace *)this,in_stack_00000008);
  return;
}
}

