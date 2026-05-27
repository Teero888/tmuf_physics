// Class implementation: CMotionTrackVisual

// =================================================
// Function: CMotionTrackVisual::CMotionTrackVisual
// =================================================
void __thiscall
CMotionTrackVisual::CMotionTrackVisual(CMotionTrackVisual *this,CMotionTrackVisual *param_1)
{
{
  ulong unaff_ESI;
  CMwId *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a99693;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMotionTrack::CMotionTrack
            ((CMotionTrack *)this,(CMotionTrack *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x38,unaff_EDI);
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  CMwCmdContainer::AddFastCall
            ((CMwCmdContainer *)this,(CMwCmdContainer *)this,(CMwNod *)ComputeVisual,
             (_func___cdecl_void *)&DAT_00000012,unaff_ESI);
  ExceptionList = (void *)0x0;
  return;
}
}

