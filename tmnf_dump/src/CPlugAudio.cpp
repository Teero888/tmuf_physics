// Class implementation: CPlugAudio

// =================================================
// Function: CPlugAudio::CPlugAudio
// =================================================
void __thiscall CPlugAudio::CPlugAudio(CPlugAudio *this,CPlugAudio *param_1)
{
{
  CMwId *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ade2b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CPlug::CPlug((CPlug *)this,(CPlug *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x14,unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CPlugAudio::MwGetId
// =================================================
CMwId * __thiscall CPlugAudio::MwGetId(CPlugAudio *this,CPlugAudio *param_1)
{
{
  return (CMwId *)(this + 0x14);
}
}

