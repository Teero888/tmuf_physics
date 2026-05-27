// Class implementation: CGameRace_SCameraPreset

// =================================================
// Function: CGameRace::SCameraPreset::SCameraPreset
// =================================================
void __thiscall CGameRace::SCameraPreset::SCameraPreset(void *this,SCameraPreset *param_1)
{
{
  GmFrustumIso4 *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  GmFrustumIso4 *unaff_retaddr;
  
  GmLocFreeVal::Reset((void *)((int)this + 4),unaff_EDI);
  GmLensVal::Reset((void *)((int)this + 0x1c),unaff_ESI);
  *(undefined4 *)this = 0;
  GmLocFreeVal::Reset((void *)((int)this + 4),unaff_retaddr);
  GmLensVal::Reset((void *)((int)this + 0x1c),(GmFrustumIso4 *)param_1);
  return;
}
}

