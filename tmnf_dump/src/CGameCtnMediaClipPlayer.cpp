// Class implementation: CGameCtnMediaClipPlayer

// =================================================
// Function: CGameCtnMediaClipPlayer::CGameCtnMediaClipPlayer
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameCtnMediaClipPlayer::CGameCtnMediaClipPlayer
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1)
{
{
  CMwNod *extraout_EAX;
  CMwNod *extraout_EAX_00;
  CMwNod *extraout_EAX_01;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBX;
  CMwNod *pCVar1;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBP;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CMwNod *unaff_EDI;
  CMwCmdFastCall *pCStack00000008;
  CScene2d *pCStack0000000c;
  undefined4 uStack00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000018;
  undefined1 uStack0000001c;
  void *in_stack_00000020;
  undefined1 uStack00000024;
  CGameCtnMediaClipPlayer *pCVar2;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffffe4;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffffe8;
  SGameCamVal *in_stack_ffffffec;
  ulong in_stack_fffffff0;
  GmRectAligned *pGVar3;
  
  pGVar3 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar2 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffd0),unaff_EDI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 100,unaff_ESI);
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x80,unaff_EBP);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x8c,unaff_EBX);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x98,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar2);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0xa4,in_stack_ffffffe4);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0xb0,in_stack_ffffffe8);
  uStack0000001c = 0xe;
  SGameCamVal::SGameCamVal(this + 0xc0,in_stack_ffffffec);
  pCStack00000008 = operator_new(0x24);
  in_stack_00000020 = (void *)CONCAT31(in_stack_00000020._1_3_,0x10);
  if (pCStack00000008 == (CMwCmdFastCall *)0x0) {
    pCVar1 = (CMwNod *)0x0;
  }
  else {
    CMwCmdFastCall::CMwCmdFastCall
              (pCStack00000008,(CMwCmdFastCall *)this,(CMwNod *)UpdateClipTime,
               (_func___cdecl_void *)&DAT_00000006,in_stack_fffffff0);
    pCVar1 = extraout_EAX;
  }
  uStack00000024 = 0xf;
  if (pCVar1 != *(CMwNod **)(this + 0x48)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,(CMwNod *)pGVar3);
    }
    if (*(CMwNod **)(this + 0x48) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x48),(CMwNod *)pGVar3);
    }
    *(CMwNod **)(this + 0x48) = pCVar1;
  }
  pCStack0000000c = operator_new(0x24);
  uStack00000024 = 0x11;
  if (pCStack0000000c == (CScene2d *)0x0) {
    pCVar1 = (CMwNod *)0x0;
  }
  else {
    CMwCmdFastCall::CMwCmdFastCall
              ((CMwCmdFastCall *)pCStack0000000c,(CMwCmdFastCall *)this,(CMwNod *)UpdateTracksCmd,
               (_func___cdecl_void *)&DAT_00000017,(ulong)pGVar3);
    pCVar1 = extraout_EAX_00;
  }
  uStack00000024 = 0xf;
  if (pCVar1 != *(CMwNod **)(this + 0x30)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,(CMwNod *)pGVar3);
    }
    if (*(CMwNod **)(this + 0x30) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x30),(CMwNod *)pGVar3);
    }
    *(CMwNod **)(this + 0x30) = pCVar1;
  }
  uStack00000010 = _DAT_00b2c060;
  uStack00000014 = 0x3f800000;
  uStack00000018 = 0x3f800000;
  pCStack0000000c = (CScene2d *)_DAT_00b2c060;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x20) = uStack00000010;
  *(undefined4 *)(this + 0x24) = uStack00000010;
  *(undefined4 *)(this + 0x28) = 0x3f800000;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x2c) = 0x3f800000;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0x5c) = 0xffffffff;
  pCStack0000000c = operator_new(0xb8);
  uStack00000024 = 0x12;
  if (pCStack0000000c == (CScene2d *)0x0) {
    pCVar1 = (CMwNod *)0x0;
  }
  else {
    CScene2d::CScene2d(pCStack0000000c,(CScene2d *)pGVar3);
    pCVar1 = extraout_EAX_01;
  }
  uStack00000024 = 0xf;
  if (pCVar1 != *(CMwNod **)(this + 0x54)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,(CMwNod *)pGVar3);
    }
    if (*(CMwNod **)(this + 0x54) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x54),(CMwNod *)pGVar3);
    }
    *(CMwNod **)(this + 0x54) = pCVar1;
  }
  CScene2d::CreateOverlay(*(CScene2d **)(this + 0x54),(CScene2d *)(this + 0x20),pGVar3);
  *(undefined4 *)(this + 300) = 0x3f800000;
  *(undefined4 *)(this + 0x70) = *(undefined4 *)(this + 0x54);
  *(CGameCtnMediaClipPlayer **)(this + 0x7c) = this;
  ExceptionList = in_stack_00000020;
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::CacheUpdate
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::CacheUpdate(CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1)
{
{
  CGameCtnMediaClipPlayer *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CGameCtnMediaClipPlayer *pCVar5;
  GmFrustumIso4 *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  GmFrustumIso4 *unaff_EBP;
  GmFrustumIso4 *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  undefined4 uVar7;
  void *unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000008;
  void *in_stack_0000000c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000010;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000014;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000018;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000001c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000028;
  CFastBufferRef<class_CGameCtnMediaTrack> *in_stack_ffffffe8;
  SItTracksBlock *pSVar8;
  TiXmlAttributeSet *in_stack_ffffffec;
  TiXmlAttribute *in_stack_fffffff0;
  ulong in_stack_fffffff4;
  CGameCtnGhost *in_stack_fffffff8;
  CGameCtnMediaClipPlayer *in_stack_fffffffc;
  
  this_00 = this + 0x80;
  pCVar5 = this;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_00,unaff_EDI);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x8c,unaff_ESI);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x98,unaff_EBP);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0xa4,unaff_EBX);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0xb0,(GmFrustumIso4 *)pCVar5);
  SItTracksBlock::SItTracksBlock(&stack0x00000000,(SItTracksBlock *)(this + 100),in_stack_ffffffe8);
  if (in_stack_00000010 < in_stack_00000014) {
    do {
      pCVar6 = in_stack_00000010;
      if (in_stack_00000010 == in_stack_00000014 + -1) {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (param_1,in_stack_00000008,(ulong)in_stack_ffffffec);
        uVar7 = *(undefined4 *)(*(int *)pSVar2 + 0x28);
      }
      else {
        uVar7 = 0;
      }
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_1,in_stack_00000008,(ulong)in_stack_ffffffec);
      pSVar8 = (SItTracksBlock *)0x6944fa;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)pSVar2 + 0x1c),pCVar6,(ulong)in_stack_fffffff0);
      *(undefined4 *)(*(int *)pSVar2 + 0x1c) = uVar7;
      in_stack_ffffffec = (TiXmlAttributeSet *)0x69450d;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (in_stack_0000000c,in_stack_00000010,in_stack_fffffff4);
      in_stack_fffffff0 = (TiXmlAttribute *)0x69451c;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)pSVar2 + 0x1c),in_stack_0000001c,(ulong)in_stack_fffffff8
                         );
      in_stack_00000010 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar2;
      in_stack_fffffff4 = 0x69452e;
      CFastBuffer<class_CDx9TextureKeeper*>::Add
                (this_00,(TiXmlAttributeSet *)&stack0x00000010,(TiXmlAttribute *)in_stack_fffffffc);
      in_stack_fffffff8 = (CGameCtnGhost *)0x69453c;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (in_stack_00000018,in_stack_0000001c,(ulong)unaff_retaddr);
      in_stack_fffffffc = (CGameCtnMediaClipPlayer *)0x69454b;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)pSVar2 + 0x1c),in_stack_00000028,(ulong)param_1);
      param_1 = (CGameCtnMediaClipPlayer *)0x30e5000;
      unaff_retaddr = (void *)0x694559;
      iVar3 = (**(code **)(**(int **)pSVar2 + 0x10))();
      if (iVar3 != 0) {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (unaff_retaddr,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                            (ulong)pSVar8);
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)pSVar2 + 0x1c),in_stack_00000010,
                            (ulong)in_stack_ffffffec);
        param_1 = *(CGameCtnMediaClipPlayer **)pSVar2;
        in_stack_ffffffec = (TiXmlAttributeSet *)&param_1;
        pSVar8 = (SItTracksBlock *)0x694590;
        CFastBuffer<class_CDx9TextureKeeper*>::Add(this + 0xa4,in_stack_ffffffec,in_stack_fffffff0);
      }
      SItTracksBlock::NextBlock(&stack0x00000000,pSVar8);
    } while (in_stack_00000010 < in_stack_00000014);
  }
  if ((*(int *)(this + 0x14) != 0) &&
     (SItTracksBlock::SItTracksBlock
                (&param_1,(SItTracksBlock *)(*(int *)(this + 0x14) + 0x14),
                 (CFastBufferRef<class_CGameCtnMediaTrack> *)in_stack_ffffffec),
     pCVar6 = in_stack_00000018, pCVar4 = in_stack_00000014, in_stack_00000014 < in_stack_00000018))
  {
    do {
      pCVar1 = in_stack_00000008;
      if (pCVar4 == pCVar6 + -1) {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (param_1,in_stack_00000008,(ulong)in_stack_ffffffec);
        uVar7 = *(undefined4 *)(*(int *)pSVar2 + 0x28);
      }
      else {
        uVar7 = 0;
      }
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_1,pCVar1,(ulong)in_stack_ffffffec);
      pSVar8 = (SItTracksBlock *)0x694604;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)pSVar2 + 0x1c),pCVar4,(ulong)in_stack_fffffff0);
      *(undefined4 *)(*(int *)pSVar2 + 0x1c) = uVar7;
      in_stack_ffffffec = (TiXmlAttributeSet *)0x694617;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (in_stack_0000000c,in_stack_00000010,in_stack_fffffff4);
      in_stack_fffffff0 = (TiXmlAttribute *)0x694626;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)pSVar2 + 0x1c),in_stack_0000001c,(ulong)in_stack_fffffff8
                         );
      in_stack_00000010 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar2;
      in_stack_fffffff4 = 0x694638;
      CFastBuffer<class_CDx9TextureKeeper*>::Add
                (this_00,(TiXmlAttributeSet *)&stack0x00000010,(TiXmlAttribute *)in_stack_fffffffc);
      in_stack_fffffff8 = (CGameCtnGhost *)0x694646;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (in_stack_00000018,in_stack_0000001c,(ulong)unaff_retaddr);
      this = (CGameCtnMediaClipPlayer *)0x694655;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)pSVar2 + 0x1c),in_stack_00000028,(ulong)param_1);
      param_1 = (CGameCtnMediaClipPlayer *)0x30e5000;
      unaff_retaddr = (void *)0x694663;
      iVar3 = (**(code **)(**(int **)pSVar2 + 0x10))();
      if (iVar3 != 0) {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (unaff_retaddr,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                            (ulong)pSVar8);
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)pSVar2 + 0x1c),in_stack_00000010,
                            (ulong)in_stack_ffffffec);
        param_1 = *(CGameCtnMediaClipPlayer **)pSVar2;
        in_stack_ffffffec = (TiXmlAttributeSet *)&param_1;
        pSVar8 = (SItTracksBlock *)0x69469e;
        CFastBuffer<class_CDx9TextureKeeper*>::Add
                  ((void *)((int)unaff_retaddr + 0x98),in_stack_ffffffec,in_stack_fffffff0);
      }
      SItTracksBlock::NextBlock(&stack0x00000000,pSVar8);
      pCVar6 = in_stack_00000014;
      pCVar4 = in_stack_00000010;
      in_stack_fffffffc = this;
    } while (in_stack_00000010 < in_stack_00000014);
  }
  param_1 = (CGameCtnMediaClipPlayer *)
            CFastBuffer<class_CCrystalFace*>::GetCount
                      (this_00,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffffec);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (param_1 != (CGameCtnMediaClipPlayer *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar6,(ulong)in_stack_fffffff0);
      pCVar5 = *(CGameCtnMediaClipPlayer **)pSVar2;
      in_stack_fffffff0 = (TiXmlAttribute *)0x3085000;
      param_1 = pCVar5;
      iVar3 = (**(code **)(*(int *)pCVar5 + 0x10))();
      if (iVar3 == 0) {
        iVar3 = (**(code **)(*(int *)pCVar5 + 0x10))(0x30e5000);
        if (iVar3 == 0) {
          pCVar5 = this + 0xb0;
          goto LAB_0069471a;
        }
      }
      else {
        pCVar5 = this + 0x8c;
LAB_0069471a:
        CFastBuffer<class_CDx9TextureKeeper*>::Add
                  (pCVar5,(TiXmlAttributeSet *)&stack0x00000000,in_stack_fffffff0);
      }
      pCVar6 = pCVar6 + 1;
    } while (pCVar6 < param_1);
  }
  if (*(int *)(this + 0x14) == 0) {
    LocalPlayerGhostSet(this,(CGameCtnMediaClipPlayer *)0x0,(CGameCtnGhost *)in_stack_fffffff0);
  }
  else {
    pCVar6 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)(this + 0x14) + 0x38);
    if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
      if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        pCVar6 = pCVar6 + -1;
      }
      pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (this + 0x98,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffff0);
      if (pCVar6 < pCVar4) {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x98,pCVar6,in_stack_fffffff4);
        LocalPlayerGhostSet(this,*(CGameCtnMediaClipPlayer **)(*(int *)pSVar2 + 0x30),
                            in_stack_fffffff8);
        return;
      }
    }
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::ClipPreClean
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::ClipPreClean
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,CGameCtnMediaClip *param_2
          )
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  ulong unaff_ESI;
  CGameCtnMediaClipPlayer *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  ulong unaff_EDI;
  
  if (param_1 != (CGameCtnMediaClipPlayer *)0x0) {
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(param_1 + 0x14,unaff_EBP);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    this_00 = param_1 + 0x14;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar5,unaff_EDI)
        ;
        iVar1 = *(int *)pSVar3;
        unaff_EDI = 0x69424f;
        pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           ((void *)(iVar1 + 0x1c),(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
        pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            unaff_EDI = 0x69425f;
            unaff_EBX = pCVar6;
            pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar1 + 0x1c),pCVar6,unaff_ESI);
            unaff_ESI = 0x69426b;
            (**(code **)(**(int **)pSVar3 + 0xe4))();
            pCVar6 = pCVar6 + 1;
          } while (pCVar6 < pCVar4);
        }
        pCVar5 = pCVar5 + 1;
        this_00 = (CGameCtnMediaClipPlayer *)param_2;
      } while (pCVar5 < pCVar2);
    }
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::ClipPreload
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::ClipPreload
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,CGameCtnMediaClip *param_2
          )
{
{
  void *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CGameCtnMediaClipPlayer *this_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  ulong unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000010;
  CGameCtnMediaClipPlayer *pCVar6;
  
  if (param_1 != (CGameCtnMediaClipPlayer *)0x0) {
    this_01 = param_1 + 0x14;
    pCVar6 = this_01;
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_01,unaff_EBP);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_01,pCVar4,unaff_EDI)
        ;
        this_00 = (void *)(*(int *)pSVar2 + 0x1c);
        unaff_EDI = 0x6941ad;
        pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBX);
        pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            unaff_EDI = 0x6941c8;
            pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar5,(ulong)unaff_ESI);
            *(CGameCtnMediaClipPlayer **)(*(int *)pSVar2 + 0x20) = param_1 + 0x70;
            unaff_EBX = (CFastBuffer<class_CCrystalFace*> *)0x6941d5;
            unaff_ESI = pCVar5;
            pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar5,(ulong)pCVar6);
            pCVar6 = (CGameCtnMediaClipPlayer *)0x6941e1;
            (**(code **)(**(int **)pSVar2 + 0xe0))();
            pCVar5 = pCVar5 + 1;
            pCVar4 = in_stack_00000010;
          } while (pCVar5 < pCVar3);
        }
        pCVar4 = pCVar4 + 1;
        this_01 = this;
      } while (pCVar4 < pCVar1);
    }
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::ClipSet
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::ClipSet
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,CGameCtnMediaClip *param_2
          )
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  CGameCtnMediaClipPlayer *unaff_retaddr;
  
  if (param_1 != *(CGameCtnMediaClipPlayer **)(this + 0x14)) {
    if (param_1 != (CGameCtnMediaClipPlayer *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x14) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x14),unaff_ESI);
    }
    *(CGameCtnMediaClipPlayer **)(this + 0x14) = param_1;
  }
  EndClipTimeSetFromClip(this,(CGameCtnMediaClipPlayer *)unaff_ESI);
  CacheUpdate(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::ClipTimeGet
// =================================================
float __thiscall
CGameCtnMediaClipPlayer::ClipTimeGet(CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1)
{
{
  return *(float *)(this + 0x4c);
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::ClipTimeSet
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::ClipTimeSet
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,float param_2)
{
{
  *(CGameCtnMediaClipPlayer **)(this + 0x4c) = param_1;
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::CompatConvertOldCameraBlocks
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::CompatConvertOldCameraBlocks
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1)
{
{
  int iVar1;
  int *piVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  int iVar6;
  CGameControlCamera *pCVar7;
  CGameControlCamera *unaff_EBX;
  CGamePlayerCameraSet *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  ulong unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CGamePlayerCameraSet *pCVar10;
  ulong in_stack_fffffff4;
  
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     ((void *)(*(int *)(this + 0x14) + 0x14),unaff_ESI);
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 0x14) + 0x14),pCVar8,unaff_EDI);
      iVar1 = *(int *)pSVar4;
      unaff_EDI = 0x6947de;
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         ((void *)(iVar1 + 0x1c),(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
      pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          unaff_EDI = 0x6947f0;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar1 + 0x1c),pCVar9,(ulong)unaff_EBX);
          piVar2 = *(int **)pSVar4;
          unaff_EBX = (CGameControlCamera *)0x307c000;
          unaff_EBP = (CGamePlayerCameraSet *)0x694800;
          iVar6 = (**(code **)(*piVar2 + 0x10))();
          if (iVar6 != 0) {
            unaff_EBP = (CGamePlayerCameraSet *)0x3084000;
            unaff_EDI = 0x694812;
            iVar6 = (**(code **)(*piVar2 + 0x10))();
            if ((iVar6 != 0) &&
               (pCVar10 = (CGamePlayerCameraSet *)piVar2[0xb],
               pCVar10 != (CGamePlayerCameraSet *)0xffffffff)) {
              unaff_EDI = 0x69482a;
              pCVar7 = CGamePlayerCameraSet::CamPtrGet
                                 (*(CGamePlayerCameraSet **)(*(int *)(this + 0x18) + 0x28),pCVar10,
                                  (ulong)unaff_EBX);
              if (pCVar7 == (CGameControlCamera *)0x0) {
                pCVar10 = (CGamePlayerCameraSet *)0x69483a;
                unaff_EBX = pCVar7;
                pCVar7 = CGamePlayerCameraSet::CamPtrGet
                                   (*(CGamePlayerCameraSet **)(*(int *)(this + 0x18) + 0x28),
                                    (CGamePlayerCameraSet *)0x0,in_stack_fffffff4);
              }
              piVar2[0xc] = *(int *)(pCVar7 + 0x14);
              piVar2[0xb] = -1;
              unaff_EBP = pCVar10;
            }
          }
          pCVar9 = pCVar9 + 1;
          pCVar8 = pCVar3;
        } while (pCVar9 < pCVar5);
      }
      pCVar8 = pCVar8 + 1;
    } while (pCVar8 < pCVar3);
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::ContextSet
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::ContextSet
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipViewer *param_1,
          CGameCtnMediaContext *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CGameCtnMediaClipViewer **)(this + 0x18)) {
    if (param_1 != (CGameCtnMediaClipViewer *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x18) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x18),unaff_ESI);
    }
    *(CGameCtnMediaClipViewer **)(this + 0x18) = param_1;
  }
  *(CGameCtnMediaClipViewer **)(this + 0x74) = param_1;
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::Create
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::Create(CGameCtnMediaClipPlayer *this,CDx9VertexBuffer *param_1)
{
{
  int iVar1;
  CMwNod *extraout_EAX;
  CGameControlCameraMaster *this_00;
  CMwNod *extraout_EAX_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CGameCtnMediaClipPlayer *this_01;
  CGameCtnMediaClipPlayer *unaff_EBX;
  CMwNod *unaff_EBP;
  CGameControlCameraMaster *unaff_ESI;
  CScene2d *unaff_EDI;
  CMwNod *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CGameCtnMediaClipPlayer *this_02;
  CGameCtnMediaClipPlayer *pCVar6;
  undefined4 uStack00000008;
  void *in_stack_00000014;
  GmRectAligned *pGVar7;
  
  ExceptionList = &stack0xfffffff4;
  pCVar6 = this;
  if (*(CGameCtnMediaClip **)(this + 0x14) == (CGameCtnMediaClip *)0x0) {
    this_02 = (CGameCtnMediaClipPlayer *)0x0;
  }
  else {
    this_02 = (CGameCtnMediaClipPlayer *)
              CGameCtnMediaClip::StartTimeGet
                        (*(CGameCtnMediaClip **)(this + 0x14),
                         (CGameCtnMediaClip *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  }
  *(CGameCtnMediaClipPlayer **)(this + 0x4c) = this_02;
  *(undefined4 *)(this + 0x44) = 0;
  if (*(int *)(this + 0x54) == 0) {
    pGVar7 = (GmRectAligned *)0xb8;
    this_02 = operator_new(0xb8);
    if (this_02 == (CGameCtnMediaClipPlayer *)0x0) {
      pCVar4 = (CMwNod *)0x0;
    }
    else {
      pGVar7 = (GmRectAligned *)0x694b25;
      CScene2d::CScene2d((CScene2d *)this_02,unaff_EDI);
      pCVar4 = extraout_EAX;
    }
    if (pCVar4 != *(CMwNod **)(this + 0x54)) {
      if (pCVar4 != (CMwNod *)0x0) {
        pGVar7 = (GmRectAligned *)0x694b3f;
        CMwNod::MwAddRef(pCVar4,(CMwNod *)unaff_EDI);
      }
      if (*(CMwNod **)(this + 0x54) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x54),(CMwNod *)pGVar7);
      }
      *(CMwNod **)(this + 0x54) = pCVar4;
    }
    CScene2d::CreateOverlay(*(CScene2d **)(this + 0x54),(CScene2d *)(this + 0x20),pGVar7);
  }
  else {
    iVar1 = *(int *)(*(int *)(this + 0x54) + 0xa0);
    *(undefined4 *)(iVar1 + 0x13c) = *(undefined4 *)(this + 0x20);
    *(undefined4 *)(iVar1 + 0x140) = *(undefined4 *)(this + 0x24);
    *(undefined4 *)(iVar1 + 0x144) = *(undefined4 *)(this + 0x28);
    *(undefined4 *)(iVar1 + 0x148) = *(undefined4 *)(this + 0x2c);
  }
  CHmsViewport::OverlayAdd
            (*(CHmsViewport **)(*(int *)(this + 0x18) + 0x18),
             *(CHmsViewport **)(*(int *)(this + 0x54) + 0xa0),(CHmsZoneOverlay *)0x0,
             (ulong)unaff_EDI);
  this_00 = operator_new(0x1c0);
  if (this_00 == (CGameControlCameraMaster *)0x0) {
    pCVar4 = (CMwNod *)0x0;
  }
  else {
    CGameControlCameraMaster::CGameControlCameraMaster(this_00,unaff_ESI);
    pCVar4 = extraout_EAX_00;
  }
  uStack00000008 = 0xffffffff;
  if (pCVar4 != *(CMwNod **)(this + 0x1c)) {
    if (pCVar4 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar4,unaff_EBP);
    }
    if (*(CMwNod **)(this + 0x1c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1c),unaff_EBP);
    }
    *(CMwNod **)(this + 0x1c) = pCVar4;
  }
  CompatConvertOldCameraBlocks(this,(CGameCtnMediaClipPlayer *)unaff_EBP);
  CacheUpdate(this,unaff_EBX);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this + 0x80,(CFastBuffer<class_CCrystalFace*> *)pCVar6);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x80,pCVar5,(ulong)this_02);
      this_02 = *(CGameCtnMediaClipPlayer **)pSVar3;
      InternalBlockInstall(this,this_02,(CGameCtnMediaBlock *)this_00);
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar2);
  }
  pCVar6 = (CGameCtnMediaClipPlayer *)ClipTimeGet(this,(CGameCtnMediaClipPlayer *)0x0);
  TracksUpdate(this_01,pCVar6,(float)this_02,(float)this_00);
  *(undefined4 *)(this + 0x34) = 1;
  ExceptionList = in_stack_00000014;
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::Destroy
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::Destroy(CGameCtnMediaClipPlayer *this,CGameAdvertisingNadeo *param_1)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CGameCtnMediaBlock *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CGameCtnMediaClipPlayer *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  if (*(int *)(this + 0x34) != 0) {
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x80,unaff_EDI);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x80,pCVar5,(ulong)unaff_ESI);
        unaff_ESI = *(CGameCtnMediaClipPlayer **)pSVar3;
        InternalBlockUninstall(this,unaff_ESI,unaff_EBX);
        pCVar5 = pCVar5 + 1;
      } while (pCVar5 < pCVar2);
    }
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this + 100,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 100,pCVar5,(ulong)unaff_EBX);
        iVar1 = *(int *)pSVar3;
        unaff_EBX = (CGameCtnMediaBlock *)0x694370;
        pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar1 + 0x1c),unaff_EBP);
        pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar1 + 0x1c),pCVar6,(ulong)unaff_EBX);
            unaff_EBX = (CGameCtnMediaBlock *)0x69438c;
            (**(code **)(**(int **)pSVar3 + 0xe4))();
            pCVar6 = pCVar6 + 1;
          } while (pCVar6 < pCVar4);
        }
        pCVar5 = pCVar5 + 1;
      } while (pCVar5 < pCVar2);
    }
    if (*(int *)(this + 0x54) != 0) {
      CHmsViewport::OverlayRemove
                (*(CHmsViewport **)(*(int *)(this + 0x18) + 0x18),
                 *(CHmsViewport **)(*(int *)(this + 0x54) + 0xa0),(CHmsZoneOverlay *)unaff_EBX);
    }
    if (*(int **)(this + 0x48) != (int *)0x0) {
      (**(code **)(**(int **)(this + 0x48) + 0x80))();
    }
    if (*(int **)(this + 0x30) != (int *)0x0) {
      (**(code **)(**(int **)(this + 0x30) + 0x80))();
    }
    if (*(CMwNod **)(this + 0x1c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1c),(CMwNod *)unaff_EBX);
      *(undefined4 *)(this + 0x1c) = 0;
    }
    *(undefined4 *)(this + 0x34) = 0;
    *(undefined4 *)(this + 0x5c) = 0xffffffff;
    if (*(int *)(*(int *)(this + 0x18) + 0x1c) != 0) {
      *(undefined4 *)(*(int *)(*(int *)(this + 0x18) + 0x1c) + 0x38) = 0x3f800000;
    }
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::DrawRectSet
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::DrawRectSet
          (CGameCtnMediaClipPlayer *this,CControlField2 *param_1,GmRectAligned *param_2)
{
{
  int iVar1;
  GmRectAligned *unaff_EDI;
  
  *(undefined4 *)(this + 0x20) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0xc);
  if (*(int *)(*(int *)(this + 0x18) + 0x24) != 0) {
    CHmsCamera::SetDrawRect
              (*(CHmsCamera **)(*(int *)(*(int *)(*(int *)(this + 0x18) + 0x24) + 0x74) + 0x30),
               (CHmsCamera *)(this + 0x20),unaff_EDI);
  }
  if (*(int *)(this + 0x54) != 0) {
    iVar1 = *(int *)(*(int *)(this + 0x54) + 0xa0);
    *(undefined4 *)(iVar1 + 0x13c) = *(undefined4 *)(this + 0x20);
    *(undefined4 *)(iVar1 + 0x140) = *(undefined4 *)(this + 0x24);
    *(undefined4 *)(iVar1 + 0x144) = *(undefined4 *)(this + 0x28);
    *(undefined4 *)(iVar1 + 0x148) = *(undefined4 *)(this + 0x2c);
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::EndClipCallBackSet
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::EndClipCallBackSet
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,CMwNod *param_2,
          _func___cdecl_void *param_3)
{
{
  *(CGameCtnMediaClipPlayer **)(this + 0x38) = param_1;
  *(CMwNod **)(this + 0x3c) = param_2;
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::EndClipTimeSetFromClip
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameCtnMediaClipPlayer::EndClipTimeSetFromClip
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1)
{
{
  CGameCtnMediaClipPlayer *pCVar1;
  int iVar2;
  ulong uVar3;
  SCasterCat *pSVar4;
  CGameCtnMediaClip *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  float10 fVar6;
  float fVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack0000000c;
  CGameCtnMediaClip *in_stack_fffffff4;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff8;
  ulong in_stack_fffffffc;
  
  if (*(CGameCtnMediaClip **)(this + 0x14) == (CGameCtnMediaClip *)0x0) {
    *(undefined4 *)(this + 0x40) = 0;
    return;
  }
  iVar2 = CGameCtnMediaClip::KeepPlayingGet(*(CGameCtnMediaClip **)(this + 0x14),unaff_EBX);
  fVar7 = _DAT_00b7ccec;
  if (iVar2 == 0) {
    fVar7 = CGameCtnMediaClip::StopTimeGet(*(CGameCtnMediaClip **)(this + 0x14),in_stack_fffffff4);
  }
  *(float *)(this + 0x40) = fVar7;
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                    ((void *)(*(int *)(this + 0x14) + 0x14),in_stack_fffffff8);
  if (uVar3 == 0) {
    pCStack0000000c =
         (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
         CFastBuffer<class_CCrystalFace*>::GetCount(this + 100,unaff_EDI);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCStack0000000c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        param_1 = (CGameCtnMediaClipPlayer *)0x0;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 100,pCVar5,unaff_ESI);
        iVar2 = *(int *)pSVar4;
        unaff_ESI = 0x693a8a;
        uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                          ((void *)(iVar2 + 0x1c),(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
        if (uVar3 != 0) {
          unaff_EBP = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar3 - 1);
          unaff_ESI = 0x693a99;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(iVar2 + 0x1c),unaff_EBP,in_stack_fffffffc);
          in_stack_fffffffc = 0x693aa5;
          fVar6 = (float10)(**(code **)(**(int **)pSVar4 + 0xa4))();
          if (0.0 < (float)fVar6) {
            param_1 = (CGameCtnMediaClipPlayer *)(float)fVar6;
          }
        }
        pCVar1 = *(CGameCtnMediaClipPlayer **)(this + 0x40);
        if ((float)param_1 < (float)pCVar1 != ((float)param_1 == (float)pCVar1)) {
          param_1 = pCVar1;
        }
        pCVar5 = pCVar5 + 1;
        *(CGameCtnMediaClipPlayer **)(this + 0x40) = param_1;
      } while (pCVar5 < pCStack0000000c);
    }
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::GetCamValDefined
// =================================================
SGameCamVal * __thiscall
CGameCtnMediaClipPlayer::GetCamValDefined
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1)
{
{
  return (SGameCamVal *)(this + 0xc0);
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::GhostIdToGameMobilId
// =================================================
ulong __thiscall
CGameCtnMediaClipPlayer::GhostIdToGameMobilId
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,ulong param_2)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  if (param_1 == (CGameCtnMediaClipPlayer *)0x0) {
    if ((*(int *)(this + 0x60) != 0) && (iVar1 = *(int *)(*(int *)(this + 0x60) + 0x90), iVar1 != 0)
       ) {
      return *(ulong *)(iVar1 + 0x18);
    }
    if (*(ulong *)(this + 0x5c) != 0xffffffff) {
      return *(ulong *)(this + 0x5c);
    }
  }
  if (param_1 != (CGameCtnMediaClipPlayer *)0x0) {
    param_1 = param_1 + -1;
  }
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x98,unaff_EDI);
  if (pCVar2 <= param_1) {
    return 0xffffffff;
  }
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x98,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_ESI);
  return *(ulong *)(*(int *)(*(int *)(*(int *)pSVar3 + 0x30) + 0x90) + 0x18);
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::InternalBlockInstall
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::InternalBlockInstall
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,
          CGameCtnMediaBlock *param_2)
{
{
  *(CGameCtnMediaClipPlayer **)(param_1 + 0x20) = this + 0x70;
  (**(code **)(*(int *)param_1 + 0x78))();
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::InternalBlockUninstall
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::InternalBlockUninstall
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,
          CGameCtnMediaBlock *param_2)
{
{
  (**(code **)(*(int *)param_1 + 0x84))();
  (**(code **)(*(int *)param_1 + 0x7c))();
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::InternalUpdateBlocks
// =================================================
void __cdecl
CGameCtnMediaClipPlayer::InternalUpdateBlocks
          (float param_1,float param_2,CFastBuffer<class_CGameCtnMediaBlock*> *param_3)
{
{
  int *piVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  float unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  float10 fVar5;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_3,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_3,pCVar4,(ulong)unaff_ESI);
      piVar1 = *(int **)pSVar3;
      fVar5 = (float10)(**(code **)(*piVar1 + 0x98))();
      if (((fVar5 <= (float10)param_1) &&
          (fVar5 = (float10)(**(code **)(*piVar1 + 0xa4))(), (float10)param_1 <= fVar5)) ||
         ((piVar1[7] != 0 &&
          (fVar5 = (float10)(**(code **)(*piVar1 + 0xa4))(),
          fVar5 < (float10)param_1 != (fVar5 == (float10)param_1))))) {
        (**(code **)(*piVar1 + 0x80))();
        unaff_ESI = param_2;
        (**(code **)(*piVar1 + 0x88))(param_1);
      }
      else {
        unaff_ESI = 9.664985e-39;
        (**(code **)(*piVar1 + 0x84))();
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::InternalUpdateBlocksGhosts
// =================================================
void __cdecl
CGameCtnMediaClipPlayer::InternalUpdateBlocksGhosts
          (float param_1,float param_2,float param_3,CFastBuffer<class_CGameCtnMediaBlock*> *param_4
          )
{
{
  int *piVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  code *pcVar4;
  float unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  float10 fVar6;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_4,unaff_EDI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_4,pCVar5,(ulong)unaff_ESI);
      piVar1 = *(int **)pSVar3;
      fVar6 = (float10)(**(code **)(*piVar1 + 0x98))();
      if (((fVar6 <= (float10)param_1) &&
          (fVar6 = (float10)(**(code **)(*piVar1 + 0xa4))(), (float10)param_1 <= fVar6)) ||
         ((piVar1[7] != 0 &&
          (fVar6 = (float10)(**(code **)(*piVar1 + 0xa4))(),
          fVar6 < (float10)param_1 != (fVar6 == (float10)param_1))))) {
        pcVar4 = *(code **)(*piVar1 + 0x80);
      }
      else {
        pcVar4 = *(code **)(*piVar1 + 0x84);
      }
      (*pcVar4)();
      unaff_ESI = param_3;
      (**(code **)(*piVar1 + 0x88))(param_2);
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar2);
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::IsPlaying
// =================================================
int __thiscall
CGameCtnMediaClipPlayer::IsPlaying(CGameCtnMediaClipPlayer *this,COalAudioSound *param_1)
{
{
  return *(uint *)(*(int *)(this + 0x48) + 0x18) & 1;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::LocalPlayerGameMobilGet
// =================================================
CGameMobil * __thiscall
CGameCtnMediaClipPlayer::LocalPlayerGameMobilGet
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1)
{
{
  CGameMobil *pCVar1;
  ulong unaff_retaddr;
  
  if (*(int *)(this + 0x60) != 0) {
    return *(CGameMobil **)(*(int *)(this + 0x60) + 0x90);
  }
  if (*(CGameScene **)(this + 0x5c) != (CGameScene *)0xffffffff) {
    pCVar1 = CGameScene::GameMobilGetFromId
                       (*(CGameScene **)(*(int *)(this + 0x18) + 0x20),*(CGameScene **)(this + 0x5c)
                        ,unaff_retaddr);
    return pCVar1;
  }
  return (CGameMobil *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::LocalPlayerGameMobilIdSet
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::LocalPlayerGameMobilIdSet
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,ulong param_2)
{
{
  CMwNod *unaff_ESI;
  
  *(CGameCtnMediaClipPlayer **)(this + 0x5c) = param_1;
  if (*(CMwNod **)(this + 0x60) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x60),unaff_ESI);
    *(undefined4 *)(this + 0x60) = 0;
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::LocalPlayerGhostSet
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::LocalPlayerGhostSet
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,CGameCtnGhost *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CGameCtnMediaClipPlayer **)(this + 0x60)) {
    if (param_1 != (CGameCtnMediaClipPlayer *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x60) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x60),unaff_ESI);
    }
    *(CGameCtnMediaClipPlayer **)(this + 0x60) = param_1;
  }
  *(undefined4 *)(this + 0x5c) = 0xffffffff;
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::Play
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::Play
          (CGameCtnMediaClipPlayer *this,CPlugFileVideo *param_1,EPlugVideoTimer param_2,int param_3
          ,ulong param_4)
{
{
  CMwCmdFiber *unaff_retaddr;
  
  *(CPlugFileVideo **)(this + 0x44) = param_1;
  (**(code **)(**(int **)(this + 0x48) + 0x7c))();
  (**(code **)(**(int **)(this + 0x30) + 0x7c))();
  if (*(CGameControlCameraMaster **)(this + 0x1c) != (CGameControlCameraMaster *)0x0) {
    CGameControlCameraMaster::Install(*(CGameControlCameraMaster **)(this + 0x1c),unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::PrioritySet
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::PrioritySet
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,ulong param_2)
{
{
  if (param_1 == (CGameCtnMediaClipPlayer *)0x1) {
    CMwCmd::SetSchemeLocation(*(CMwCmd **)(this + 0x30),(CMwCmd *)&DAT_00000017,param_2);
    return;
  }
  if (param_1 == (CGameCtnMediaClipPlayer *)0x2) {
    CMwCmd::SetSchemeLocation(*(CMwCmd **)(this + 0x30),(CMwCmd *)0x18,param_2);
    return;
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::Stop
// =================================================
void __thiscall CGameCtnMediaClipPlayer::Stop(CGameCtnMediaClipPlayer *this,STmRaceLowFps *param_1)
{
{
  (**(code **)(**(int **)(this + 0x48) + 0x80))();
  (**(code **)(**(int **)(this + 0x30) + 0x80))();
  if (*(CGameControlCameraMaster **)(this + 0x1c) != (CGameControlCameraMaster *)0x0) {
    CGameControlCameraMaster::Uninstall
              (*(CGameControlCameraMaster **)(this + 0x1c),(CMwCmdContainer *)param_1);
    return;
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::TracksUpdate
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::TracksUpdate
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1,float param_2,
          float param_3)
{
{
  int iVar1;
  float fVar2;
  float fVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  ulong unaff_EBX;
  void *this_00;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  float unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  float in_stack_00000014;
  
  *(undefined4 *)(this + 300) = 0x3f800000;
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0x120) = 0;
  if ((((*(int *)(this + 0x18) != 0) && (iVar1 = *(int *)(*(int *)(this + 0x18) + 0x34), iVar1 != 0)
       ) && (*(CAudioPort **)(iVar1 + 0x17c) != (CAudioPort *)0x0)) &&
     (*(CAudioPort **)(iVar1 + 0x68) != (CAudioPort *)0x0)) {
    CAudioPort::SetSecondaryVolume
              (*(CAudioPort **)(iVar1 + 0x68),*(CAudioPort **)(iVar1 + 0x17c),(CAudioSound *)0x1,
               0x3f800000,unaff_EDI);
  }
  InternalUpdateBlocks(param_2,param_3,(CFastBuffer<class_CGameCtnMediaBlock*> *)(this + 0x8c));
  fVar2 = param_3;
  fVar3 = param_2;
  if (*(int *)(this + 0x120) != 0) {
    fVar2 = *(float *)(this + 0x128);
    fVar3 = *(float *)(this + 0x124);
  }
  InternalUpdateBlocksGhosts
            (param_2,fVar3,fVar2,(CFastBuffer<class_CGameCtnMediaBlock*> *)(this + 0x98));
  InternalUpdateBlocksGhosts
            (param_2,fVar3,fVar2,(CFastBuffer<class_CGameCtnMediaBlock*> *)(this + 0xa4));
  InternalUpdateBlocks(param_2,param_3,(CFastBuffer<class_CGameCtnMediaBlock*> *)(this + 0xb0));
  if (*(int *)(this + 0x50) != 0) {
    this_00 = (void *)(*(int *)(*(int *)(this + 0x18) + 0x20) + 0x1c);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
    if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar6,unaff_EBX)
        ;
        if (*(int **)(*(int *)pSVar5 + 0x14) != (int *)0x0) {
          unaff_EBX = 0x200;
          (**(code **)(**(int **)(*(int *)pSVar5 + 0x14) + 0x10c))(0.0 < in_stack_00000014);
        }
        pCVar6 = pCVar6 + 1;
      } while (pCVar6 < pCVar4);
    }
  }
  if (*(int *)(*(int *)(this + 0x18) + 0x1c) != 0) {
    *(undefined4 *)(*(int *)(*(int *)(this + 0x18) + 0x1c) + 0x38) = *(undefined4 *)(this + 300);
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaClipPlayer::UpdateTracksCmd
// =================================================
void __thiscall
CGameCtnMediaClipPlayer::UpdateTracksCmd
          (CGameCtnMediaClipPlayer *this,CGameCtnMediaClipPlayer *param_1)
{
{
  float fVar1;
  int iVar2;
  CGameCtnMediaClipPlayer *this_00;
  CGameCtnMediaClipPlayer *this_01;
  CGameCtnMediaClipPlayer *in_stack_fffffff8;
  COalAudioSound *in_stack_fffffffc;
  
  ClipTimeGet(this,in_stack_fffffff8);
  iVar2 = IsPlaying(this_00,in_stack_fffffffc);
  if (iVar2 == 0) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = *(float *)(this_01 + 0x44);
  }
  TracksUpdate(this_01,param_1,fVar1,fVar1);
  return;
}
}

