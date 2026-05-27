// Class implementation: CPlugEngine

// =================================================
// Function: CPlugEngine::CPlugEngine
// =================================================
void __thiscall CPlugEngine::CPlugEngine(CPlugEngine *this,CPlugEngine *param_1)
{
{
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00ad67e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwEngine::CMwEngine((CMwEngine *)this,(CMwEngine *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x20) = 0;
  CPlugSurface::StaticInit();
  ExceptionList = local_8;
  return;
}
}

