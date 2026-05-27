// Class implementation: CPlugGpuFxLocator

// =================================================
// Function: CPlugGpuFxLocator::CPlugGpuFxLocator
// =================================================
void __thiscall
CPlugGpuFxLocator::CPlugGpuFxLocator(CPlugGpuFxLocator *this,CPlugGpuFxLocator *param_1)
{
{
  CMwId *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ada243;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CPlug::CPlug((CPlug *)this,(CPlug *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x18,unaff_ESI);
  *(undefined4 *)(this + 0x14) = 0;
  Reset(this,(GmFrustumIso4 *)0x0);
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CPlugGpuFxLocator::Reset
// =================================================
void __thiscall CPlugGpuFxLocator::Reset(CPlugGpuFxLocator *this,GmFrustumIso4 *param_1)
{
{
  CFastStringInt *unaff_ESI;
  
  if (param_1 != (GmFrustumIso4 *)0x0) {
    CMwId::SetLocalName(this + 0x18,(CMwId *)param_1,unaff_ESI);
  }
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  *(undefined4 *)(this + 0x24) = 0xffffffff;
  *(undefined4 *)(this + 0x1c) = 0xffffffff;
  *(undefined4 *)(this + 0x20) = 2;
  *(undefined4 *)(this + 0x28) = 0;
  return;
}
}

