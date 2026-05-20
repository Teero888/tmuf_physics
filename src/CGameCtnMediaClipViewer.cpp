// Class implementation: CGameCtnMediaClipViewer

// =================================================
// Function: CGameCtnMediaClipViewer::CGameCtnMediaClipViewer
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameCtnMediaClipViewer::CGameCtnMediaClipViewer
          (CGameCtnMediaClipViewer *this,CGameCtnMediaClipViewer *param_1)
{
{
  undefined4 uVar1;
  CMwNod *extraout_EAX;
  CMwNod *extraout_EAX_00;
  CMwNod *extraout_EAX_01;
  CMwNod *unaff_EBP;
  CMwNod *pCVar2;
  ulong unaff_ESI;
  CMwNod *unaff_EDI;
  void *unaff_retaddr;
  undefined1 uStack00000008;
  CMwCmdFastCall *local_c;
  CMwCmdFastCall *pCStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pCStack_8 = (CMwCmdFastCall *)&LAB_00aaf5a7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffd4),unaff_EDI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x14) = 3;
  *(undefined4 *)(this + 0x18) = 2;
  *(undefined4 *)(this + 0x24) = 1;
  local_c = operator_new(0x24);
  if (local_c == (CMwCmdFastCall *)0x0) {
    pCVar2 = (CMwNod *)0x0;
  }
  else {
    CMwCmdFastCall::CMwCmdFastCall
              (local_c,(CMwCmdFastCall *)this,(CMwNod *)UpdateInput,
               (_func___cdecl_void *)&DAT_0000000e,unaff_ESI);
    pCVar2 = extraout_EAX;
  }
  uStack00000008 = 10;
  if (pCVar2 != *(CMwNod **)(this + 0x34)) {
    if (pCVar2 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar2,unaff_EBP);
    }
    if (*(CMwNod **)(this + 0x34) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x34),unaff_EBP);
    }
    *(CMwNod **)(this + 0x34) = pCVar2;
  }
  pCStack_8 = operator_new(0x24);
  uStack00000008 = 0xc;
  if (pCStack_8 == (CMwCmdFastCall *)0x0) {
    pCVar2 = (CMwNod *)0x0;
  }
  else {
    CMwCmdFastCall::CMwCmdFastCall
              (pCStack_8,(CMwCmdFastCall *)this,(CMwNod *)UpdateCams,
               (_func___cdecl_void *)&DAT_0000001a,(ulong)unaff_EBP);
    pCVar2 = extraout_EAX_00;
  }
  uStack00000008 = 10;
  if (pCVar2 != *(CMwNod **)(this + 0x38)) {
    if (pCVar2 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar2,unaff_EBP);
    }
    if (*(CMwNod **)(this + 0x38) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x38),unaff_EBP);
    }
    *(CMwNod **)(this + 0x38) = pCVar2;
  }
  pCStack_8 = operator_new(0x24);
  uStack00000008 = 0xd;
  if (pCStack_8 == (CMwCmdFastCall *)0x0) {
    pCVar2 = (CMwNod *)0x0;
  }
  else {
    CMwCmdFastCall::CMwCmdFastCall
              (pCStack_8,(CMwCmdFastCall *)this,(CMwNod *)ClipGroupCheckTriggers,
               (_func___cdecl_void *)&DAT_0000000e,(ulong)unaff_EBP);
    pCVar2 = extraout_EAX_01;
  }
  uStack00000008 = 10;
  if (pCVar2 != *(CMwNod **)(this + 0x74)) {
    if (pCVar2 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar2,unaff_EBP);
    }
    if (*(CMwNod **)(this + 0x74) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x74),unaff_EBP);
    }
    *(CMwNod **)(this + 0x74) = pCVar2;
  }
  *(undefined4 *)(this + 0x70) = 0;
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)(this + 0x54) = _DAT_00b2c060;
  *(undefined4 *)(this + 0x3c) = 0x3f800000;
  *(undefined4 *)(this + 0x58) = uVar1;
  *(undefined4 *)(this + 0x5c) = 0x3f800000;
  *(undefined4 *)(this + 0x60) = 0x3f800000;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipViewer::ClipGroupSet
// =================================================
void __thiscall
CGameCtnMediaClipViewer::ClipGroupSet
          (CGameCtnMediaClipViewer *this,CGameCtnMediaClipViewer *param_1,
          CGameCtnMediaClipGroup *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CGameCtnMediaClipPlayer *pCVar3;
  CMwNod *extraout_EAX;
  CGameCtnMediaClip *unaff_ESI;
  CGameCtnMediaClipPlayer *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CMwNod *this_00;
  CGameCtnMediaContext *in_stack_ffffffdc;
  ulong uVar5;
  CFastBuffer<class_CCrystalFace*> *pCVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aaf41b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(this + 0x44) != 0) {
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       ((void *)(*(int *)(this + 0x44) + 0x14),
                        (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe8))
    ;
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)(this + 0x44) + 0x14),pCVar4,(ulong)unaff_EDI);
        unaff_EDI = *(CGameCtnMediaClipPlayer **)pSVar2;
        CGameCtnMediaClipPlayer::ClipPreClean
                  (*(CGameCtnMediaClipPlayer **)(this + 0x4c),unaff_EDI,unaff_ESI);
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar1);
    }
    if (*(CMwNod **)(this + 0x4c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x4c),(CMwNod *)unaff_EDI);
      *(undefined4 *)(this + 0x4c) = 0;
    }
  }
  if (param_2 != *(CGameCtnMediaClipGroup **)(this + 0x44)) {
    if (param_2 != (CGameCtnMediaClipGroup *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_2,(CMwNod *)unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x44) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x44),(CMwNod *)unaff_EDI);
    }
    *(CGameCtnMediaClipGroup **)(this + 0x44) = param_2;
  }
  if (*(int *)(this + 0x44) != 0) {
    pCVar6 = (CFastBuffer<class_CCrystalFace*> *)0x130;
    uVar5 = 0x673628;
    pCVar3 = operator_new(0x130);
    if (pCVar3 == (CGameCtnMediaClipPlayer *)0x0) {
      this_00 = (CMwNod *)0x0;
    }
    else {
      pCVar6 = (CFastBuffer<class_CCrystalFace*> *)0x673642;
      CGameCtnMediaClipPlayer::CGameCtnMediaClipPlayer(pCVar3,unaff_EDI);
      this_00 = extraout_EAX;
    }
    if (this_00 != *(CMwNod **)(this + 0x4c)) {
      if (this_00 != (CMwNod *)0x0) {
        pCVar6 = (CFastBuffer<class_CCrystalFace*> *)0x673660;
        CMwNod::MwAddRef(this_00,(CMwNod *)unaff_EDI);
      }
      if (*(CMwNod **)(this + 0x4c) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x4c),(CMwNod *)in_stack_ffffffdc);
      }
      *(CMwNod **)(this + 0x4c) = this_00;
    }
    CGameCtnMediaClipPlayer::ContextSet
              (*(CGameCtnMediaClipPlayer **)(this + 0x4c),*(CGameCtnMediaClipViewer **)(this + 0x78)
               ,in_stack_ffffffdc);
    CGameCtnMediaClipPlayer::PrioritySet
              (*(CGameCtnMediaClipPlayer **)(this + 0x4c),(CGameCtnMediaClipPlayer *)0x2,uVar5);
    pCVar3 = (CGameCtnMediaClipPlayer *)0x67368d;
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(param_2 + 0x14,pCVar6);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)(this + 0x44) + 0x14),pCVar4,(ulong)pCVar3);
        pCVar3 = *(CGameCtnMediaClipPlayer **)pSVar2;
        CGameCtnMediaClipPlayer::ClipPreload
                  (*(CGameCtnMediaClipPlayer **)(this + 0x4c),pCVar3,(CGameCtnMediaClip *)pCVar6);
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar1);
    }
  }
  ExceptionList = puStack_8;
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipViewer::ClipSet
// =================================================
void __thiscall
CGameCtnMediaClipViewer::ClipSet
          (CGameCtnMediaClipViewer *this,CGameCtnMediaClipPlayer *param_1,CGameCtnMediaClip *param_2
          )
{
{
  CGameCtnMediaClipPlayer *this_00;
  CMwNod *extraout_EAX;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  CMwNod *this_01;
  CMwNod *in_stack_0000000c;
  CGameCtnMediaContext *pCVar1;
  CGameCtnMediaClip *pCVar2;
  void *local_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00aaf3eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(CGameCtnMediaClipPlayer **)(this + 0x2c) != (CGameCtnMediaClipPlayer *)0x0) {
    CGameCtnMediaClipPlayer::ClipPreClean
              (*(CGameCtnMediaClipPlayer **)(this + 0x30),*(CGameCtnMediaClipPlayer **)(this + 0x2c)
               ,(CGameCtnMediaClip *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
    if (*(CMwNod **)(this + 0x30) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x30),unaff_EDI);
      *(undefined4 *)(this + 0x30) = 0;
    }
  }
  if (in_stack_0000000c != *(CMwNod **)(this + 0x2c)) {
    if (in_stack_0000000c != (CMwNod *)0x0) {
      CMwNod::MwAddRef(in_stack_0000000c,unaff_ESI);
    }
    if (*(CMwNod **)(this + 0x2c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x2c),unaff_ESI);
    }
    *(CMwNod **)(this + 0x2c) = in_stack_0000000c;
  }
  if (*(int *)(this + 0x2c) != 0) {
    pCVar2 = (CGameCtnMediaClip *)0x130;
    pCVar1 = (CGameCtnMediaContext *)0x67350a;
    this_00 = operator_new(0x130);
    if (this_00 == (CGameCtnMediaClipPlayer *)0x0) {
      this_01 = (CMwNod *)0x0;
    }
    else {
      pCVar2 = (CGameCtnMediaClip *)0x673524;
      CGameCtnMediaClipPlayer::CGameCtnMediaClipPlayer(this_00,(CGameCtnMediaClipPlayer *)unaff_ESI)
      ;
      this_01 = extraout_EAX;
    }
    if (this_01 != *(CMwNod **)(this + 0x30)) {
      if (this_01 != (CMwNod *)0x0) {
        pCVar2 = (CGameCtnMediaClip *)0x673542;
        CMwNod::MwAddRef(this_01,unaff_ESI);
      }
      if (*(CMwNod **)(this + 0x30) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x30),(CMwNod *)pCVar1);
      }
      *(CMwNod **)(this + 0x30) = this_01;
    }
    CGameCtnMediaClipPlayer::ContextSet
              (*(CGameCtnMediaClipPlayer **)(this + 0x30),*(CGameCtnMediaClipViewer **)(this + 0x78)
               ,pCVar1);
    CGameCtnMediaClipPlayer::ClipPreload
              (*(CGameCtnMediaClipPlayer **)(this + 0x30),*(CGameCtnMediaClipPlayer **)(this + 0x2c)
               ,pCVar2);
  }
  ExceptionList = pvStack_4;
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipViewer::Start
// =================================================
void __thiscall CGameCtnMediaClipViewer::Start(CGameCtnMediaClipViewer *this,CGameCtnBench *param_1)
{
{
  CGameCtnMediaClipPlayer *this_00;
  CGamePlayerCameraSet *this_01;
  int iVar1;
  CMwNod *this_02;
  CGameCtnMediaClipPlayer *pCVar2;
  CGameMobil *pCVar3;
  CMwNod *unaff_EBX;
  CGameCtnMediaClip *unaff_ESI;
  _func___cdecl_void *unaff_EDI;
  CDx9VertexBuffer *unaff_retaddr;
  int in_stack_00000008;
  ulong in_stack_0000000c;
  CPlugFileVideo *in_stack_00000010;
  ulong in_stack_00000014;
  ulong in_stack_00000018;
  CGameCtnMediaClipPlayer *in_stack_0000001c;
  CGameCtnMediaClipPlayer *in_stack_00000020;
  ulong in_stack_00000024;
  CGamePlayerCameraSet *in_stack_00000028;
  ulong in_stack_0000002c;
  CMwNod *in_stack_00000030;
  undefined4 in_stack_0000003c;
  
  if (*(int *)(this + 0x2c) != 0) {
    if (*(int *)(this + 0x44) != 0) {
      (**(code **)(**(int **)(this + 0x74) + 0x7c))();
    }
    CGameCtnMediaClipPlayer::EndClipCallBackSet
              (*(CGameCtnMediaClipPlayer **)(this + 0x30),(CGameCtnMediaClipPlayer *)this,
               (CMwNod *)OnEndClip,unaff_EDI);
    CGameCtnMediaClipPlayer::ClipSet
              (*(CGameCtnMediaClipPlayer **)(this + 0x30),*(CGameCtnMediaClipPlayer **)(this + 0x2c)
               ,unaff_ESI);
    CGameCtnMediaClipPlayer::Create(*(CGameCtnMediaClipPlayer **)(this + 0x30),unaff_retaddr);
    CGameCtnMediaClipPlayer::Play
              (*(CGameCtnMediaClipPlayer **)(this + 0x30),in_stack_00000010,(EPlugVideoTimer)param_1
               ,in_stack_00000008,in_stack_0000000c);
    CGameCtnMediaClipPlayer::DrawRectSet
              (*(CGameCtnMediaClipPlayer **)(this + 0x30),(CControlField2 *)(this + 0x54),
               (GmRectAligned *)in_stack_00000010);
    this_00 = *(CGameCtnMediaClipPlayer **)(this + 0x30);
    pCVar2 = (CGameCtnMediaClipPlayer *)
             CGameCtnMediaClipPlayer::GhostIdToGameMobilId
                       (this_00,*(CGameCtnMediaClipPlayer **)(*(int *)(this + 0x2c) + 0x38),
                        in_stack_00000014);
    CGameCtnMediaClipPlayer::LocalPlayerGameMobilIdSet(this_00,pCVar2,in_stack_00000018);
    if (*(int *)(*(int *)(*(CGameCtnMediaClipPlayer **)(this + 0x30) + 0x18) + 0x28) != 0) {
      pCVar3 = CGameCtnMediaClipPlayer::LocalPlayerGameMobilGet
                         (*(CGameCtnMediaClipPlayer **)(this + 0x30),in_stack_0000001c);
      if (pCVar3 != (CGameMobil *)0x0) {
        this_01 = *(CGamePlayerCameraSet **)
                   (*(int *)(*(CGameCtnMediaClipPlayer **)(this + 0x30) + 0x18) + 0x28);
        pCVar3 = CGameCtnMediaClipPlayer::LocalPlayerGameMobilGet
                           (*(CGameCtnMediaClipPlayer **)(this + 0x30),in_stack_00000020);
        CGamePlayerCameraSet::PlayerGameMobilIdSet
                  (this_01,*(CGamePlayerCameraSet **)(pCVar3 + 0x18),in_stack_00000024);
      }
      CGamePlayerCameraSet::CamsReset
                (*(CGamePlayerCameraSet **)(*(int *)(*(int *)(this + 0x30) + 0x18) + 0x28),
                 in_stack_00000028);
      in_stack_00000028 = (CGamePlayerCameraSet *)0x0;
      CGamePlayerCameraSet::CamSwitchTo
                (*(CGamePlayerCameraSet **)(*(int *)(*(int *)(this + 0x30) + 0x18) + 0x28),
                 (CGamePlayerCameraSet *)0x0,in_stack_0000002c);
    }
    *(undefined4 *)(this + 0x50) = 0xffffffff;
    *(undefined4 *)(this + 0x3c) = in_stack_0000003c;
    *(undefined4 *)(this + 0x6c) = 0;
    *(undefined4 *)(this + 0x68) = 0;
    *(undefined4 *)(this + 100) = 0;
    *(undefined4 *)(this + 0x70) = 0;
    if (*(int *)(this + 0x24) != 0) {
      iVar1 = *(int *)(this + 0x1c);
      if (iVar1 != 0) {
        this_02 = *(CMwNod **)(this + 0x2c);
        if (this_02 != *(CMwNod **)(iVar1 + 0x18)) {
          if (this_02 != (CMwNod *)0x0) {
            in_stack_00000028 = (CGamePlayerCameraSet *)0x673af2;
            CMwNod::MwAddRef(this_02,unaff_EBX);
          }
          if (*(CMwNod **)(iVar1 + 0x18) != (CMwNod *)0x0) {
            CMwNod::MwRelease(*(CMwNod **)(iVar1 + 0x18),in_stack_00000030);
          }
          *(CMwNod **)(iVar1 + 0x18) = this_02;
        }
        CGameCtnBench::Start(*(CGameCtnBench **)(this + 0x1c),(CGameCtnBench *)in_stack_00000028);
      }
      (**(code **)(**(int **)(this + 0x34) + 0x7c))();
    }
    (**(code **)(**(int **)(this + 0x38) + 0x7c))();
    (**(code **)(**(int **)(this + 0x38) + 0x78))();
    StatusSet(this,(CGameCtnMediaClipViewer *)0x0,(EStatus)in_stack_00000030);
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipViewer::StatusSet
// =================================================
void __thiscall
CGameCtnMediaClipViewer::StatusSet
          (CGameCtnMediaClipViewer *this,CGameCtnMediaClipViewer *param_1,EStatus param_2)
{
{
  STmRaceLowFps *unaff_EDI;
  
  if (param_1 != (CGameCtnMediaClipViewer *)0x0) {
    Stop(this,unaff_EDI);
  }
  *(CGameCtnMediaClipViewer **)(this + 0x28) = param_1;
  return;
}
}

