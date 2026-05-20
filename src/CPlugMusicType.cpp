// Class implementation: CPlugMusicType

// =================================================
// Function: CPlugMusicType::CPlugMusicType
// =================================================
void __thiscall CPlugMusicType::CPlugMusicType(CPlugMusicType *this,CPlugMusicType *param_1)
{
{
  CPlugSound *unaff_ESI;
  
  CPlugSound::CPlugSound((CPlugSound *)this,unaff_ESI);
  *(undefined4 *)(this + 0x20) = 0x3f800000;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined ***)this = vftable;
  return;
}
}

