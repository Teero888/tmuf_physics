// Class implementation: CTrackManiaRace2PTurnBased

// =================================================
// Function: CTrackManiaRace2PTurnBased::UpdateAsync
// =================================================
void __thiscall
CTrackManiaRace2PTurnBased::UpdateAsync(CTrackManiaRace2PTurnBased *this,CInputPortDx8 *param_1)
{
{
  CInputPortDx8 *unaff_ESI;
  CTrackManiaRace *in_stack_00000008;
  
  CTrackManiaRace::UpdateAsync((CTrackManiaRace *)this,unaff_ESI);
  CTrackManiaRace::Ghosts_UpdateAsync((CTrackManiaRace *)this,in_stack_00000008);
  return;
}
}

