// Class implementation: CMotionSkelBlender

// =================================================
// Function: CMotionSkelBlender::CMotionSkelBlender
// =================================================
void __thiscall
CMotionSkelBlender::CMotionSkelBlender(CMotionSkelBlender *this,CMotionSkelBlender *param_1)
{
{
  CMwCmdFastCall *this_00;
  CMwNod *extraout_EAX;
  CMwNod *this_01;
  CMwNod *unaff_ESI;
  undefined1 uStack00000008;
  void *in_stack_00000010;
  CMotionSkelBlender *pCVar1;
  _func___cdecl_void *in_stack_fffffff0;
  void *pvVar2;
  CMwNod *pCVar3;
  
  pCVar3 = (CMwNod *)&LAB_00a9a0be;
  pvVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe8),unaff_ESI);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x18,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar1);
  uStack00000008 = 1;
  this_00 = operator_new(0x24);
  uStack00000008 = 2;
  if (this_00 == (CMwCmdFastCall *)0x0) {
    this_01 = (CMwNod *)0x0;
  }
  else {
    CMwCmdFastCall::CMwCmdFastCall
              (this_00,(CMwCmdFastCall *)this,(CMwNod *)DoGlobalBlend,in_stack_fffffff0,
               (ulong)pvVar2);
    this_01 = extraout_EAX;
  }
  in_stack_00000010 = (void *)CONCAT31(in_stack_00000010._1_3_,1);
  *(CMwNod **)(this + 0x14) = this_01;
  CMwNod::MwAddRef(this_01,pCVar3);
  CMwCmd::SetSchemeLocation(*(CMwCmd **)(this + 0x14),(CMwCmd *)&DAT_00000013,(ulong)this_00);
  ExceptionList = in_stack_00000010;
  return;
}
}

// =================================================
// Function: CMotionSkelBlender::StaticAddRef
// =================================================
void __cdecl CMotionSkelBlender::StaticAddRef(void)
{
{
  CMotionSkelBlender *pCVar1;
  undefined4 extraout_EAX;
  CMotionSkelBlender *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a9a14b;
  local_c = ExceptionList;
  pCVar1 = (CMotionSkelBlender *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  if (DAT_00d68334 == 0) {
    local_10 = operator_new(0x24);
    local_4 = 0;
    if (local_10 == (CMotionSkelBlender *)0x0) {
      DAT_00d68330 = 0;
    }
    else {
      CMotionSkelBlender(local_10,pCVar1);
      DAT_00d68330 = extraout_EAX;
    }
  }
  DAT_00d68334 = DAT_00d68334 + 1;
  ExceptionList = local_8;
  return;
}
}

