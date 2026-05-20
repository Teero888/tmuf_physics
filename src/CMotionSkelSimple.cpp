// Class implementation: CMotionSkelSimple

// =================================================
// Function: CMotionSkelSimple::CMotionSkelSimple
// =================================================
void __thiscall
CMotionSkelSimple::CMotionSkelSimple(CMotionSkelSimple *this,CMotionSkelSimple *param_1)
{
{
  ulong unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  CMotionSkelSimple *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a99913;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CMotionTrack::CMotionTrack
            ((CMotionTrack *)this,(CMotionTrack *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x34,unaff_EDI);
  param_1 = (CMotionSkelSimple *)CONCAT31(param_1._1_3_,1);
  CFastBuffer<int>::SetSizeAtLeast
            (this + 0x34,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)&DAT_0000000a,unaff_ESI);
  CMotionSkelBlender::StaticAddRef();
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  CMwCmdContainer::AddFastCall
            ((CMwCmdContainer *)this,(CMwCmdContainer *)this,(CMwNod *)_vcall__156__flat______,
             (_func___cdecl_void *)&DAT_00000012,(ulong)pCVar1);
  ExceptionList = param_1;
  return;
}
}

