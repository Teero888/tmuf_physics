// Class implementation: CMotionPath

// =================================================
// Function: CMotionPath::CMotionPath
// =================================================
void __thiscall CMotionPath::CMotionPath(CMotionPath *this,CMotionPath *param_1)
{
{
  ulong unaff_EBP;
  CMwId *unaff_ESI;
  CMwId *unaff_EDI;
  undefined1 uStack00000008;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a99bae;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMotionTrack::CMotionTrack
            ((CMotionTrack *)this,(CMotionTrack *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x3c,unaff_EDI);
  param_1 = (CMotionPath *)CONCAT31(param_1._1_3_,1);
  CMwId::CMwId(this + 0x44,unaff_ESI);
  uStack00000008 = 2;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x34) = 1;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x30) = 1;
  *(undefined4 *)(this + 0x44) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 1;
  *(undefined4 *)(this + 0x48) = 0;
  CMwCmdContainer::AddFastCall
            ((CMwCmdContainer *)this,(CMwCmdContainer *)this,(CMwNod *)FollowPath,
             (_func___cdecl_void *)&DAT_00000012,unaff_EBP);
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CMotionPath::InternalSetPath
// =================================================
void __thiscall
CMotionPath::InternalSetPath(CMotionPath *this,CMotionPath *param_1,CScenePath *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CMotionPath **)(this + 0x38)) {
    if (param_1 != (CMotionPath *)0x0) {
      CMwNod::MwAddDependant((CMwNod *)param_1,(CMwNod *)this,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x38) != (CMwNod *)0x0) {
      CMwNod::MwSubDependant(*(CMwNod **)(this + 0x38),(CMwNod *)this,unaff_ESI);
    }
    *(CMotionPath **)(this + 0x38) = param_1;
  }
  return;
}
}

// =================================================
// Function: CMotionPath::SetPath
// =================================================
void __thiscall CMotionPath::SetPath(CMotionPath *this,CSceneToySubway *param_1,CScenePath *param_2)
{
{
  int *piVar1;
  undefined4 *puVar2;
  CScenePath *unaff_EDI;
  
  if (((*(int *)(this + 0x30) != 0) && (param_1 != (CSceneToySubway *)0x0)) &&
     (piVar1 = (int *)(**(code **)(*(int *)param_1 + 0x14))(), *piVar1 == -1)) {
    return;
  }
  if (*(int *)(this + 0x34) != 0) {
    InternalSetPath(this,(CMotionPath *)param_1,unaff_EDI);
    return;
  }
  if (param_1 == (CSceneToySubway *)0x0) {
    *(undefined4 *)(this + 0x3c) = 0xffffffff;
    return;
  }
  puVar2 = (undefined4 *)(**(code **)(*(int *)param_1 + 0x14))();
  *(undefined4 *)(this + 0x3c) = *puVar2;
  return;
}
}

