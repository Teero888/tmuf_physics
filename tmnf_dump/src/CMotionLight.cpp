// Class implementation: CMotionLight

// =================================================
// Function: CMotionLight::CMotionLight
// =================================================
void __thiscall CMotionLight::CMotionLight(CMotionLight *this,CMotionLight *param_1)
{
{
  ulong unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a99718;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMotionTrack::CMotionTrack
            ((CMotionTrack *)this,(CMotionTrack *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  CMwCmdContainer::AddFastCall
            ((CMwCmdContainer *)this,(CMwCmdContainer *)this,(CMwNod *)DoLinks,
             (_func___cdecl_void *)&DAT_0000000a,unaff_EDI);
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CMotionLight::SetLight
// =================================================
void __thiscall CMotionLight::SetLight(CMotionLight *this,CMotionLight *param_1,GxLight *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  if (*(CMwNod **)(this + 0x2c) != (CMwNod *)0x0) {
    CMwNod::MwSubDependant(*(CMwNod **)(this + 0x2c),(CMwNod *)this,unaff_ESI);
  }
  *(GxLight **)(this + 0x2c) = param_2;
  if (param_2 != (GxLight *)0x0) {
    CMwNod::MwAddDependant((CMwNod *)param_2,(CMwNod *)this,unaff_retaddr);
  }
  return;
}
}

