// Class implementation: CMotionTrackTree

// =================================================
// Function: CMotionTrackTree::CMotionTrackTree
// =================================================
void __thiscall CMotionTrackTree::CMotionTrackTree(CMotionTrackTree *this,CMotionTrackTree *param_1)
{
{
  CMwCmdFastCall *pCVar1;
  ulong unaff_ESI;
  CMwId *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a99573;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMotionTrack::CMotionTrack
            ((CMotionTrack *)this,(CMotionTrack *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x3c,unaff_EDI);
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  pCVar1 = CMwCmdContainer::AddFastCall
                     ((CMwCmdContainer *)this,(CMwCmdContainer *)this,(CMwNod *)UpdateTree,
                      (_func___cdecl_void *)&DAT_00000012,unaff_ESI);
  *(CMwCmdFastCall **)(this + 0x38) = pCVar1;
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: CMotionTrackTree::SetFuncTree
// =================================================
void __thiscall
CMotionTrackTree::SetFuncTree(CMotionTrackTree *this,CPlugTree *param_1,CFuncTree *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != (CPlugTree *)0x0) {
    CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
  }
  if (*(CMwNod **)(this + 0x30) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x30),unaff_ESI);
  }
  *(CPlugTree **)(this + 0x30) = param_1;
  return;
}
}

// =================================================
// Function: CMotionTrackTree::SetIsPhysics
// =================================================
void __thiscall
CMotionTrackTree::SetIsPhysics(CMotionTrackTree *this,CMotionTrackTree *param_1,int param_2)
{
{
  if (param_1 != (CMotionTrackTree *)0x0) {
    CMwCmd::SetSchemeLocation(*(CMwCmd **)(this + 0x38),(CMwCmd *)0x85,param_2);
    return;
  }
  CMwCmd::SetSchemeLocation(*(CMwCmd **)(this + 0x38),(CMwCmd *)&DAT_00000012,param_2);
  return;
}
}

