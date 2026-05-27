// Class implementation: CTrackManiaSwitcher

// =================================================
// Function: CTrackManiaSwitcher::Switch
// =================================================
void __thiscall CTrackManiaSwitcher::Switch(CTrackManiaSwitcher *this,CControlUiDockable *param_1)
{
{
  CTrackManiaSwitcher *unaff_retaddr;
  ECardinalDir in_stack_00000008;
  
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(this + 0x14);
  *(CControlUiDockable **)(this + 0x14) = param_1;
  if (param_1 == (CControlUiDockable *)0x1) {
    SwitchToEditor(this,(CGameCtnMediaTracker *)unaff_retaddr);
  }
  else {
    if (param_1 == (CControlUiDockable *)0x2) {
      SwitchToRace(this,(CGameRace *)unaff_retaddr,(GmNat3)0x2,in_stack_00000008);
      return;
    }
    if (param_1 == (CControlUiDockable *)0x3) {
      SwitchToEndRaceReplay(this,unaff_retaddr);
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CTrackManiaSwitcher::SwitchToEditor
// =================================================
void __thiscall
CTrackManiaSwitcher::SwitchToEditor(CTrackManiaSwitcher *this,CGameCtnMediaTracker *param_1)
{
{
  int iVar1;
  CScene3d *this_00;
  CScene3d *pCVar2;
  CTrackManiaEditor *pCVar3;
  CTrackMania *unaff_ESI;
  int unaff_retaddr;
  int iVar4;
  
  iVar1 = *(int *)(this + 0x1c);
  if (*(int *)(iVar1 + 0x414) != 0) {
    if (*(int *)(iVar1 + 0x170) != 0) {
      this_00 = *(CScene3d **)(*(int *)(iVar1 + 0x170) + 0x14);
      iVar4 = 0x30b1000;
      pCVar2 = (CScene3d *)(**(code **)(**(int **)(iVar1 + 0x414) + 0x10))();
      CScene3d::SceneFxGlobalStartStop(this_00,pCVar2,iVar4);
    }
    pCVar3 = CTrackMania::GetTmBlockEditor(*(CTrackMania **)(this + 0x1c),unaff_ESI);
    if (pCVar3 != (CTrackManiaEditor *)0x0) {
      CSceneObjectLink::SetIsActive
                (*(CSceneObjectLink **)(pCVar3 + 0xc4),(CSceneObjectLink *)0x1,unaff_retaddr);
    }
    if (*(int **)(*(int *)(this + 0x1c) + 0x454) != (int *)0x0) {
      (**(code **)(**(int **)(*(int *)(this + 0x1c) + 0x454) + 0xb4))();
    }
                    /* WARNING: Could not recover jumptable at 0x0047902c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(*(int *)(this + 0x1c) + 0x414) + 0x7c))();
    return;
  }
  return;
}
}

// =================================================
// Function: CTrackManiaSwitcher::SwitchToEndRaceReplay
// =================================================
void __thiscall
CTrackManiaSwitcher::SwitchToEndRaceReplay(CTrackManiaSwitcher *this,CTrackManiaSwitcher *param_1)
{
{
  CTrackManiaRace *this_00;
  CGameCtnMediaClipViewer *pCVar1;
  CGameCtnMediaClipViewer *this_01;
  CMwNod *extraout_EAX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  int iVar4;
  CGameCtnMediaContext *this_02;
  CTrackManiaRace *unaff_EBX;
  CGameCtnMediaClipViewer *this_03;
  TiXmlAttribute *unaff_EBP;
  TiXmlAttributeSet *unaff_ESI;
  int *piVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CMwNod *this_04;
  void *this_05;
  void *in_stack_00000010;
  TiXmlAttributeSet *pTVar7;
  TiXmlAttribute *pTVar8;
  CGameApp *pCVar9;
  CTrackManiaRace *pCVar10;
  CTrackManiaRace *pCStack_18;
  CFastBufferRef<class_CGameCtnGhost> aCStack_14 [4];
  CGameCtnMediaClipPlayer *pCStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a87e73;
  local_c = ExceptionList;
  pCVar1 = (CGameCtnMediaClipViewer *)(DAT_00cca150 ^ (uint)&stack0xffffffd0);
  ExceptionList = &local_c;
  this_04 = (CMwNod *)0x0;
  if (*(int **)(*(int *)(this + 0x1c) + 0x414) != (int *)0x0) {
    (**(code **)(**(int **)(*(int *)(this + 0x1c) + 0x414) + 0x78))();
  }
  this_03 = *(CGameCtnMediaClipViewer **)(*(int *)(this + 0x1c) + 0x454);
  pCVar10 = (CTrackManiaRace *)this_03;
  if (this_03 != (CGameCtnMediaClipViewer *)0x0) {
    (**(code **)(*(int *)this_03 + 0xb4))();
  }
  this_01 = operator_new(0x7c);
  uStack_4 = 0;
  if (this_01 != (CGameCtnMediaClipViewer *)0x0) {
    CGameCtnMediaClipViewer::CGameCtnMediaClipViewer(this_01,pCVar1);
    this_04 = extraout_EAX;
  }
  piVar5 = (int *)(*(int *)(this + 0x1c) + 0x1c8);
  uStack_4 = 0xffffffff;
  if (this_04 != (CMwNod *)*piVar5) {
    if (this_04 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_04,(CMwNod *)pCVar1);
    }
    if ((CMwNod *)*piVar5 != (CMwNod *)0x0) {
      CMwNod::MwRelease((CMwNod *)*piVar5,(CMwNod *)pCVar1);
    }
    *piVar5 = (int)this_04;
  }
  pTVar7 = (TiXmlAttributeSet *)0x479651;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (&pCStack_18,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar1);
  if ((this_03 != (CGameCtnMediaClipViewer *)0x0) && (*(int *)(this_03 + 0xb0) != 0)) {
    this_05 = (void *)(*(int *)(this_03 + 0xb0) + 0x18);
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_05,unaff_EDI);
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    this_03 = (CGameCtnMediaClipViewer *)pCStack_18;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_05,pCVar6,(ulong)unaff_ESI);
        pCStack_10 = *(CGameCtnMediaClipPlayer **)pSVar3;
        unaff_ESI = (TiXmlAttributeSet *)&pCStack_10;
        CFastBuffer<class_CDx9TextureKeeper*>::Add(&local_c,unaff_ESI,unaff_EBP);
        pCVar6 = pCVar6 + 1;
        this_03 = (CGameCtnMediaClipViewer *)pCStack_18;
      } while (pCVar6 < pCVar2);
    }
  }
  pCVar9 = (CGameApp *)0x24018000;
  iVar4 = (**(code **)(*(int *)this_03 + 0x10))();
  if (iVar4 != 0) {
    this_00 = (CTrackManiaRace *)(this_03 + 0x52c);
    pTVar8 = (TiXmlAttribute *)0x4796c6;
    this_03 = this_01;
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this_00,(CFastBuffer<class_CCrystalFace*> *)pCVar9);
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    this_01 = this_03;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar6,(ulong)pTVar7);
        this_03 = *(CGameCtnMediaClipViewer **)pSVar3;
        pTVar7 = (TiXmlAttributeSet *)&stack0xffffffe4;
        CFastBuffer<class_CDx9TextureKeeper*>::Add(&pCStack_18,pTVar7,pTVar8);
        pCVar6 = pCVar6 + 1;
        this_01 = this_03;
      } while (pCVar6 < pCVar2);
    }
  }
  pCStack_18 = (CTrackManiaRace *)CGameCtnMediaClip::CreateFromGhosts(aCStack_14,1);
  iVar4 = *(int *)(*(CGameApp **)(this + 0x1c) + 0x1c8);
  this_02 = CGameApp::MediaContextCreate(*(CGameApp **)(this + 0x1c),pCVar9);
  if (this_02 != *(CGameCtnMediaContext **)(iVar4 + 0x78)) {
    if (this_02 != (CGameCtnMediaContext *)0x0) {
      CMwNod::MwAddRef((CMwNod *)this_02,(CMwNod *)unaff_ESI);
    }
    if (*(CMwNod **)(iVar4 + 0x78) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(iVar4 + 0x78),(CMwNod *)unaff_EBP);
    }
    *(CGameCtnMediaContext **)(iVar4 + 0x78) = this_02;
  }
  CGameCtnMediaClipViewer::ClipSet
            (*(CGameCtnMediaClipViewer **)(*(int *)(this + 0x1c) + 0x1c8),pCStack_10,
             (CGameCtnMediaClip *)unaff_EBP);
  CTrackManiaRace::Ghosts_PreviousRaceGhostsClear((CTrackManiaRace *)this_03,unaff_EBX);
  iVar4 = (**(code **)(**(int **)(this + 0x1c) + 0x84))();
  pCVar1 = *(CGameCtnMediaClipViewer **)(iVar4 + 0x188);
  if (pCVar1 == (CGameCtnMediaClipViewer *)0x0) {
    iVar4 = (**(code **)(**(int **)(this + 0x1c) + 0x84))();
    pCVar1 = *(CGameCtnMediaClipViewer **)(iVar4 + 0x184);
    if (pCVar1 == (CGameCtnMediaClipViewer *)0x0) goto LAB_00479792;
  }
  CGameCtnMediaClipViewer::ClipGroupSet
            (*(CGameCtnMediaClipViewer **)(*(int *)(this + 0x1c) + 0x1c8),pCVar1,
             (CGameCtnMediaClipGroup *)pCVar10);
LAB_00479792:
  *(undefined4 *)(*(int *)(*(int *)(this + 0x1c) + 0x1c8) + 0x24) = 0;
  *(undefined4 *)(*(int *)(*(int *)(this + 0x1c) + 0x1c8) + 0x18) = 2;
  CGameCtnMediaClipViewer::Start
            (*(CGameCtnMediaClipViewer **)(*(int *)(this + 0x1c) + 0x1c8),
             (CGameCtnBench *)0x3f800000);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (&stack0x00000000,(CFastBuffer<class_CPlugFileGPUV*> *)this_01);
  ExceptionList = in_stack_00000010;
  return;
}
}

