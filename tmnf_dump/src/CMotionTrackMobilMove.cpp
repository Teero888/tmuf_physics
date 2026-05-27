// Class implementation: CMotionTrackMobilMove

// =================================================
// Function: CMotionTrackMobilMove::CMotionTrackMobilMove
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionTrackMobilMove::CMotionTrackMobilMove
          (CMotionTrackMobilMove *this,CMotionTrackMobilMove *param_1)
{
{
  ulong unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a997be;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMotionTrack::CMotionTrack
            ((CMotionTrack *)this,(CMotionTrack *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = _DAT_00b2c060;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  CMwCmdContainer::AddFastCall
            ((CMwCmdContainer *)this,(CMwCmdContainer *)this,(CMwNod *)MoveMobil,
             (_func___cdecl_void *)&DAT_0000000b,unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

