// Class implementation: CMotionPlayer

// =================================================
// Function: CMotionPlayer::AddTrack
// =================================================
ulong __thiscall
CMotionPlayer::AddTrack(CMotionPlayer *this,CMotionPlayer *param_1,CMotionTrack *param_2)
{
{
  CMotionPlayer *this_00;
  CMotionTrack *this_01;
  ulong uVar1;
  CMotionTrack *unaff_EBX;
  SFormat *unaff_ESI;
  GxTexCoordSet *unaff_EDI;
  CMwNod *unaff_retaddr;
  
  this_00 = this + 0x50;
  uVar1 = CFastArray<class_CGameMenuFrame*>::Find
                    (this_00,(CFastArray<class_GxTexCoordSet> *)&param_1,unaff_EDI);
  this_01 = param_2;
  if (uVar1 == 0xffffffff) {
    ConnectTrack(this,(CMotionPlayer *)param_2,unaff_EBX);
    CFastArray<class_CFastBuffer<class_CSceneMobil*>*>::AddTail
              (this_00,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)&stack0x0000000c,unaff_ESI);
    CMwNod::MwAddRef((CMwNod *)this_01,unaff_retaddr);
    uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (this_00,(CFastBuffer<class_CCrystalFace*> *)param_1);
    uVar1 = uVar1 - 1;
  }
  return uVar1;
}
}

// =================================================
// Function: CMotionPlayer::CMotionPlayer
// =================================================
void __thiscall CMotionPlayer::CMotionPlayer(CMotionPlayer *this,CMotionPlayer *param_1)
{
{
  CMotionCmdBase *this_00;
  CMwNod *extraout_EAX;
  CMwCmdFastCall *this_01;
  CMwNod *extraout_EAX_00;
  CMwNod *pCVar1;
  CMotionCmdBase *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_EDI;
  undefined1 uStack00000008;
  undefined1 uStack0000000c;
  void *in_stack_00000014;
  CMotionPlayer *pCVar2;
  _func___cdecl_void *in_stack_fffffff0;
  void *pvVar3;
  int iVar4;
  
  iVar4 = -1;
  pvVar3 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar2 = this;
  CMotion::CMotion((CMotion *)this,(CMotion *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x50,unaff_EDI);
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x48) = 2;
  *(undefined4 *)(this + 0x4c) = 2;
  this_00 = operator_new(0x50);
  if (this_00 == (CMotionCmdBase *)0x0) {
    pCVar1 = (CMwNod *)0x0;
  }
  else {
    CMotionCmdBase::CMotionCmdBase(this_00,unaff_ESI);
    pCVar1 = extraout_EAX;
  }
  uStack00000008 = 1;
  *(CMwNod **)(this + 0x30) = pCVar1;
  CMwNod::MwAddRef(pCVar1,(CMwNod *)pCVar2);
  *(CMotionPlayer **)(*(int *)(this + 0x30) + 0x40) = this;
  this_01 = operator_new(0x24);
  uStack0000000c = 3;
  if (this_01 == (CMwCmdFastCall *)0x0) {
    pCVar1 = (CMwNod *)0x0;
  }
  else {
    CMwCmdFastCall::CMwCmdFastCall
              (this_01,(CMwCmdFastCall *)this,(CMwNod *)UpdateIntensity,in_stack_fffffff0,
               (ulong)pvVar3);
    pCVar1 = extraout_EAX_00;
  }
  in_stack_00000014 = (void *)CONCAT31(in_stack_00000014._1_3_,1);
  *(CMwNod **)(this + 0x34) = pCVar1;
  CMwNod::MwAddRef(pCVar1,(CMwNod *)this_00);
  SetIsPhysics(this,(CMotionTrackTree *)0x0,iVar4);
  *(undefined4 *)(this + 0x24) = 0x3f800000;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x2c) = 1;
  ExceptionList = in_stack_00000014;
  return;
}
}

// =================================================
// Function: CMotionPlayer::ConnectTrack
// =================================================
void __thiscall
CMotionPlayer::ConnectTrack(CMotionPlayer *this,CMotionPlayer *param_1,CMotionTrack *param_2)
{
{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(int *)param_1 + 0x88);
  *(CMotionPlayer **)(param_1 + 0x28) = this;
  (*pcVar1)(*(undefined4 *)(this + 0x20));
  (**(code **)(*(int *)param_1 + 0x90))(*(undefined4 *)(this + 0x28));
  return;
}
}

// =================================================
// Function: CMotionPlayer::IsPlaying
// =================================================
int __thiscall CMotionPlayer::IsPlaying(CMotionPlayer *this,COalAudioSound *param_1)
{
{
  return (uint)(*(int *)(this + 0x48) == 0);
}
}

// =================================================
// Function: CMotionPlayer::SetIsPhysics
// =================================================
void __thiscall
CMotionPlayer::SetIsPhysics(CMotionPlayer *this,CMotionTrackTree *param_1,int param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CMotionPlayer *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  CMwCmd *pCVar4;
  
  *(CMotionTrackTree **)(this + 0x28) = param_1;
  if (param_1 == (CMotionTrackTree *)0x0) {
    CMwCmd::SetSchemeLocation(*(CMwCmd **)(this + 0x30),(CMwCmd *)&DAT_00000009,unaff_EDI);
    pCVar4 = (CMwCmd *)&DAT_00000009;
  }
  else {
    CMwCmd::SetSchemeLocation(*(CMwCmd **)(this + 0x30),(CMwCmd *)0x85,unaff_EDI);
    pCVar4 = (CMwCmd *)0x85;
  }
  CMwCmd::SetSchemeLocation(*(CMwCmd **)(this + 0x34),pCVar4,unaff_ESI);
  UpdateTimeBaseParams(this,unaff_EBP);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x50,unaff_EBX);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x50,pCVar3,unaff_retaddr);
      unaff_retaddr = *(ulong *)(this + 0x28);
      (**(code **)(**(int **)pSVar2 + 0x90))();
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CMotionPlayer::UpdateTimeBaseParams
// =================================================
void __thiscall CMotionPlayer::UpdateTimeBaseParams(CMotionPlayer *this,CMotionPlayer *param_1)
{
{
  int iVar1;
  CTrackManiaEditorIcon *pCVar2;
  CTrackManiaEditorIconPage *pCVar3;
  
  if (*(int *)(this + 0x20) != 0) {
    pCVar3 = (CTrackManiaEditorIconPage *)0xa011000;
    iVar1 = (**(code **)(**(int **)(this + 0x20) + 0x10))();
    if (iVar1 != 0) {
      if (*(int *)(this + 0x28) != 0) {
        CTrackManiaEditorIcon::SetMotherPage
                  (*(CTrackManiaEditorIcon **)(this + 0x30),(CTrackManiaEditorIcon *)0x0,pCVar3);
        return;
      }
      pCVar2 = (CTrackManiaEditorIcon *)(**(code **)(**(int **)(this + 0x20) + 0xd4))();
      CTrackManiaEditorIcon::SetMotherPage(*(CTrackManiaEditorIcon **)(this + 0x30),pCVar2,pCVar3);
      return;
    }
    CTrackManiaEditorIcon::SetMotherPage
              (*(CTrackManiaEditorIcon **)(this + 0x30),(CTrackManiaEditorIcon *)0x2,pCVar3);
  }
  return;
}
}

