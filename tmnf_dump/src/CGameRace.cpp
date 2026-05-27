// Class implementation: CGameRace

// =================================================
// Function: CGameRace::ApplyProfileInputSettings
// =================================================
void __thiscall CGameRace::ApplyProfileInputSettings(CGameRace *this,CGameRace *param_1)
{
{
  CGameCtnChallenge *this_00;
  SGameCtnIdentifier *pSVar1;
  CGamePlayerProfile *pCVar2;
  SGameCtnIdentifier *unaff_ESI;
  CGameCtnChallenge *unaff_EDI;
  undefined4 in_stack_00000008;
  float *in_stack_fffffffc;
  
  if ((*(int *)(this + 0x20) != 0) && (*(int *)(*(int *)(this + 0x18) + 0x168) != 0)) {
    pCVar2 = *(CGamePlayerProfile **)(*(int *)(this + 0x18) + 0x168);
    this_00 = (CGameCtnChallenge *)(**(code **)(*(int *)this + 0xb8))();
    pSVar1 = CGameCtnChallenge::GetVehicleIdent(this_00,unaff_EDI);
    pCVar2 = (CGamePlayerProfile *)
             CGamePlayerProfile::FindVehicleProfileFromVehicleIdent
                       (pCVar2,(CGamePlayerProfile *)pSVar1,unaff_ESI);
    if (pCVar2 != (CGamePlayerProfile *)0xffffffff) {
      CGamePlayerProfile::GetAnalogSensibility
                (*(CGamePlayerProfile **)(*(int *)(this + 0x18) + 0x168),pCVar2,(ulong)&param_1,
                 (float *)&stack0x00000000,in_stack_fffffffc);
      (**(code **)(**(int **)(this + 0x20) + 0x7c))(in_stack_00000008,param_1);
    }
    *(undefined4 *)(*(int *)(this + 0x20) + 0x28) =
         *(undefined4 *)(*(int *)(*(int *)(this + 0x18) + 0x168) + 0x130);
  }
  return;
}
}

// =================================================
// Function: CGameRace::CGameRace
// =================================================
void __thiscall CGameRace::CGameRace(CGameRace *this,CGameRace *param_1)
{
{
  ulong unaff_EBX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_EDI;
  undefined1 uStack00000008;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aa1b1a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CGamePlayground::CGamePlayground
            ((CGamePlayground *)this,(CGamePlayground *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 100,unaff_EDI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x8c,unaff_ESI);
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0xb4) = 0;
  uStack00000008 = 9;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 1;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = 1;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x9c) = 0;
  CFastArray<struct_CGameRace::SCameraPreset>::SetCount
            (this + 100,(CFastBuffer<class_CSystemFidsFolder*> *)&DAT_00000009,unaff_EBX);
  *(undefined4 *)(this + 0xa8) = 5;
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CGameRace::Chunk
// =================================================
void __thiscall
CGameRace::Chunk(CGameRace *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  ulong uVar1;
  CClassicArchive *pCVar2;
  CClassicArchive *unaff_EDI;
  
  uVar1 = CMwDeprecated::WrapClassId((uint)param_2 & 0xfffff000);
  pCVar2 = param_2;
  if (((uint)param_2 & 0xfffff000) != uVar1) {
    pCVar2 = (CClassicArchive *)((uint)param_2 & 0xfff | uVar1);
  }
  if (pCVar2 != (CClassicArchive *)0x3073000) {
    CGameNod::Chunk((CGameNod *)this,param_1,param_2,(ulong)unaff_EDI);
    return;
  }
  CMwId::Archive(this + 0x14,(CFastCrypt<unsigned_long> *)param_1,unaff_EDI);
  (**(code **)(*(int *)param_1 + 8))(this + 0x54);
  return;
}
}

// =================================================
// Function: CGameRace::Clean
// =================================================
void __thiscall CGameRace::Clean(CGameRace *this,CHmsOcclusion *param_1)
{
{
  CGameCtnReplayRecord *unaff_ESI;
  CMwNod *unaff_retaddr;
  CHmsOcclusion *in_stack_00000008;
  
  SetReplayRecord(this,(CGameRace *)0x0,unaff_ESI);
  if (*(CMwNod **)(this + 0xb4) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xb4),unaff_retaddr);
    *(undefined4 *)(this + 0xb4) = 0;
  }
  CGamePlayground::Clean((CGamePlayground *)this,in_stack_00000008);
  return;
}
}

// =================================================
// Function: CGameRace::FindSpecPlayerInfoFromPlayerInfo
// =================================================
ulong __thiscall
CGameRace::FindSpecPlayerInfoFromPlayerInfo
          (CGameRace *this,CGameRace *param_1,CGamePlayerInfo *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x8c,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CPlugBitmapRenderSolid::SSolid>::operator[]
                         (this + 0x8c,pCVar3,unaff_ESI);
      if (*(CGamePlayerInfo **)pSVar2 == param_2) {
        return (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CGameRace::FindSpecPlayerInfoFromUid
// =================================================
ulong __thiscall
CGameRace::FindSpecPlayerInfoFromUid(CGameRace *this,CGameRace *param_1,uchar param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x8c,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CPlugBitmapRenderSolid::SSolid>::operator[]
                         (this + 0x8c,pCVar3,unaff_ESI);
      if (pSVar2[0x10] == (SCasterCat)param_2) {
        return (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CGameRace::GetChunkInfo
// =================================================
ulong __thiscall CGameRace::GetChunkInfo(CGameRace *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  CFuncSegment *pCVar2;
  ulong unaff_EDI;
  
  uVar1 = CMwDeprecated::WrapClassId((uint)param_1 & 0xfffff000);
  pCVar2 = param_1;
  if (((uint)param_1 & 0xfffff000) != uVar1) {
    pCVar2 = (CFuncSegment *)((uint)param_1 & 0xfff | uVar1);
  }
  if (pCVar2 != (CFuncSegment *)0x3073000) {
    uVar1 = CGameNod::GetChunkInfo((CGameNod *)this,param_1,unaff_EDI);
    return uVar1;
  }
  return 3;
}
}

// =================================================
// Function: CGameRace::GetLocalPlayer
// =================================================
CGamePlayer * __thiscall CGameRace::GetLocalPlayer(CGameRace *this,CGameRace *param_1)
{
{
  CGamePlayerInfo *pCVar1;
  CGameRace *unaff_retaddr;
  
  pCVar1 = GetLocalPlayerInfo(this,unaff_retaddr);
  return *(CGamePlayer **)(pCVar1 + 0x238);
}
}

// =================================================
// Function: CGameRace::GetLocalPlayerInfo
// =================================================
CGamePlayerInfo * __thiscall CGameRace::GetLocalPlayerInfo(CGameRace *this,CGameRace *param_1)
{
{
  int iVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  
  if (*(int **)(this + 0x18) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(this + 0x18) + 0x118))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(**(int **)(this + 0x18) + 0x118))();
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x2fc),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
      return *(CGamePlayerInfo **)pSVar2;
    }
  }
  return (CGamePlayerInfo *)0x0;
}
}

// =================================================
// Function: CGameRace::GetMwClassId
// =================================================
ulong __thiscall CGameRace::GetMwClassId(CGameRace *this,CControlStyle *param_1)
{
{
  return 0x3073000;
}
}

// =================================================
// Function: CGameRace::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CGameRace::GetUidChunkFromIndex(CGameRace *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if ((CMwCmdExpIso4Ident *)0x1 < param_1) {
    return (uint)(param_1 + -2) | 0x3073000;
  }
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0x3008000;
}
}

// =================================================
// Function: CGameRace::Init
// =================================================
void __thiscall
CGameRace::Init(CGameRace *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2,
               CVisionViewportDx9 *param_3,ESpriteColor0 *param_4)
{
{
  CMwNod *pCVar1;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  *(CLoadGeomDynaSprite **)(this + 0x18) = param_1;
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x6c);
  if (*(CMwNod **)(this + 0x44) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x44),unaff_EDI);
    *(undefined4 *)(this + 0x44) = 0;
  }
  pCVar1 = *(CMwNod **)(param_1 + 0x170);
  if (pCVar1 != *(CMwNod **)(this + 0x30)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_ESI);
    }
    if (*(CMwNod **)(this + 0x30) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x30),unaff_ESI);
    }
    *(CMwNod **)(this + 0x30) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(param_1 + 0x174);
  if (pCVar1 != *(CMwNod **)(this + 0x34)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_ESI);
    }
    if (*(CMwNod **)(this + 0x34) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x34),unaff_ESI);
    }
    *(CMwNod **)(this + 0x34) = pCVar1;
  }
  return;
}
}

// =================================================
// Function: CGameRace::LoadPreset
// =================================================
int __thiscall
CGameRace::LoadPreset(CGameRace *this,CGameRace *param_1,ulong param_2,GmCamFreeVal *param_3)
{
{
  CGameRace *this_00;
  ulong uVar1;
  SCasterCat *pSVar2;
  int iVar3;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ulong unaff_retaddr;
  undefined4 *in_stack_00000014;
  
  this_00 = this + 100;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (param_2 < uVar1) {
    pSVar2 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
             ::operator[](this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                          unaff_ESI);
    if (*(int *)pSVar2 != 0) {
      pSVar2 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
               ::operator[](this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                            unaff_retaddr);
      for (iVar3 = 0xb; pSVar2 = pSVar2 + 4, iVar3 != 0; iVar3 = iVar3 + -1) {
        *in_stack_00000014 = *(undefined4 *)pSVar2;
        in_stack_00000014 = in_stack_00000014 + 1;
      }
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CGameRace::MediaClipCheckInGameTriggers
// =================================================
void __thiscall
CGameRace::MediaClipCheckInGameTriggers
          (CGameRace *this,CGameRace *param_1,CGamePlayer *param_2,CGameCtnMediaClipGroup *param_3)
{
{
  CGameRace *pCVar1;
  int iVar2;
  int iVar3;
  CGameCtnChallenge *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  CGamePlayerInfo *this_01;
  CGameCtnMediaClip *pCVar6;
  SGameCtnMediaTriggerZone *unaff_EBP;
  ulong unaff_ESI;
  GmNat3 *unaff_EDI;
  GmField2Base *pGVar7;
  GmVec2 *pGVar8;
  GmNat2 *pGVar9;
  CGamePlayer *pCVar10;
  CGameRace *pCVar11;
  CGameNetPlayerInfo *pCVar12;
  int in_stack_fffffff0;
  CGameCtnMediaClipGroup aCStack_c [12];
  
  if ((((param_2 != (CGamePlayer *)0x0) && (iVar3 = *(int *)(param_1 + 0x28), iVar3 != 0)) &&
      (*(int *)(iVar3 + 0x1c) != -1)) &&
     (iVar2 = (**(code **)(*(int *)this + 0xb8))(), *(int *)(iVar2 + 0x90) != 0)) {
    pGVar9 = (GmNat2 *)0x0;
    iVar3 = (**(code **)(**(int **)(iVar3 + 0x14) + 0x80))();
    pCVar10 = *(CGamePlayer **)(iVar3 + 0x24);
    pCVar11 = *(CGameRace **)(iVar3 + 0x28);
    pCVar12 = *(CGameNetPlayerInfo **)(iVar3 + 0x2c);
    pGVar8 = (GmVec2 *)&stack0xffffffe4;
    pGVar7 = (GmField2Base *)&stack0xfffffff0;
    this_00 = (CGameCtnChallenge *)(**(code **)(*(int *)this + 0xb8))();
    CGameCtnChallenge::GetCoordFromPos(this_00,pGVar7,pGVar8,pGVar9);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CGameCtnMediaClipGroup::ClipFind((CGameCtnMediaClipGroup *)param_2,aCStack_c,unaff_EDI)
    ;
    if ((pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) &&
       (*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(param_1 + 0x48) != pCVar4)) {
      CFastBuffer<struct_CMotionSkelBlender::CBlendedBone>::operator[]
                (param_2 + 0x20,pCVar4,unaff_ESI);
      iVar3 = ClipTriggerConditionOk(unaff_EBP,pCVar10);
      if (iVar3 != 0) {
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pCVar4 + 0x48) = pCVar4;
        CFastBuffer<class_CGamePlayerScore*>::FindOrAdd
                  (pCVar4 + 0x38,(CFastBuffer<class_CGamePlayerScore*> *)&stack0x00000010,
                   (CGamePlayerScore **)unaff_EBP);
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (param_2 + 0x14,pCVar4,(ulong)pCVar10);
        pCVar1 = *(CGameRace **)pSVar5;
        this_01 = GetLocalPlayerInfo(this,pCVar11);
        pCVar6 = (CGameCtnMediaClip *)
                 CGameNetPlayerInfo::IsSpectator((CGameNetPlayerInfo *)this_01,pCVar12);
        MediaClipStart(this,pCVar1,pCVar6,in_stack_fffffff0);
      }
    }
  }
  return;
}
}

// =================================================
// Function: CGameRace::MediaClipIsPlaying
// =================================================
int __thiscall CGameRace::MediaClipIsPlaying(CGameRace *this,CGameRace *param_1)
{
{
  int iVar1;
  COalAudioSound *unaff_retaddr;
  
  if (*(CGameCtnMediaClipPlayer **)(this + 0xa0) != (CGameCtnMediaClipPlayer *)0x0) {
    iVar1 = CGameCtnMediaClipPlayer::IsPlaying
                      (*(CGameCtnMediaClipPlayer **)(this + 0xa0),unaff_retaddr);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CGameRace::MediaClipIsPlayingGlobal
// =================================================
int __thiscall CGameRace::MediaClipIsPlayingGlobal(CGameRace *this,CGameRace *param_1)
{
{
  int iVar1;
  COalAudioSound *unaff_retaddr;
  
  if (*(CGameCtnMediaClipPlayer **)(this + 0xa4) != (CGameCtnMediaClipPlayer *)0x0) {
    iVar1 = CGameCtnMediaClipPlayer::IsPlaying
                      (*(CGameCtnMediaClipPlayer **)(this + 0xa4),unaff_retaddr);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CGameRace::MediaClipIsPlayingIntro
// =================================================
int __thiscall CGameRace::MediaClipIsPlayingIntro(CGameRace *this,CGameRace *param_1)
{
{
  int iVar1;
  CGameRace *unaff_ESI;
  
  iVar1 = MediaClipIsPlaying(this,unaff_ESI);
  if ((iVar1 != 0) && (*(int *)(this + 0xa8) == 0)) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CGameRace::MediaClipStart
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CGameRace::MediaClipStart(CGameRace *this,CGameRace *param_1,CGameCtnMediaClip *param_2,int param_3)
{
{
  int iVar1;
  
  iVar1 = MediaClipStart(this,param_1,param_2,5);
  return iVar1;
}
}

// =================================================
// Function: CGameRace::MediaClipStartCutScene
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameRace::MediaClipStartCutScene
          (CGameRace *this,CGameRace *param_1,EChallengeCutScene param_2,float param_3,int param_4)
{
{
  CGamePlayerInfo *pCVar1;
  CMwNod *this_00;
  CMwNodRef<class_CGameCamera> *pCVar2;
  int iVar3;
  int *piVar4;
  CGameRace *unaff_EBX;
  CGameRace *unaff_ESI;
  CGameCtnMediaClip *unaff_EDI;
  CGameRace *pCVar5;
  undefined4 in_stack_00000014;
  CGameCamera *pCVar6;
  CGameCtnMediaClip *pCVar7;
  undefined4 uVar8;
  
  pCVar1 = GetLocalPlayerInfo(this,unaff_ESI);
  if (((*(int *)(pCVar1 + 0x70) == 0) && (*(int *)(pCVar1 + 0x74) == 0)) || (param_2 == 0)) {
    if (param_2 == 0) {
      pCVar5 = this + 0x58;
      if (*(int *)(this + 0x58) == 0) {
        pCVar6 = (CGameCamera *)0x5de9eb;
        iVar3 = (**(code **)(*(int *)this + 0xb8))();
        CMwNodRef<class_CGameCamera>::MwSetNod
                  (pCVar5,*(CMwNodRef<class_CGameCamera> **)(iVar3 + 0x17c),pCVar6);
        if (*(int *)pCVar5 == 0) {
          pCVar6 = (CGameCamera *)0x5dea0f;
          pCVar2 = (CMwNodRef<class_CGameCamera> *)(**(code **)(*(int *)this + 0xc0))();
          CMwNodRef<class_CGameCamera>::MwSetNod(pCVar5,pCVar2,pCVar6);
        }
      }
      CGameCtnMediaClipPlayer::ClipPreload
                (*(CGameCtnMediaClipPlayer **)(this + 0xa0),*(CGameCtnMediaClipPlayer **)pCVar5,
                 unaff_EDI);
      pCVar5 = *(CGameRace **)pCVar5;
    }
    else {
      if (param_2 != 2) {
        return;
      }
      if (*(CGameCtnMediaClipPlayer **)(this + 0x60) != (CGameCtnMediaClipPlayer *)0x0) {
        CGameCtnMediaClipPlayer::ClipPreClean
                  (*(CGameCtnMediaClipPlayer **)(this + 0xa0),
                   *(CGameCtnMediaClipPlayer **)(this + 0x60),unaff_EDI);
      }
      pCVar7 = (CGameCtnMediaClip *)0x5de9a1;
      this_00 = (CMwNod *)(**(code **)(*(int *)this + 0xc4))();
      if (this_00 != *(CMwNod **)(this + 0x60)) {
        if (this_00 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(this_00,(CMwNod *)pCVar7);
        }
        if (*(CMwNod **)(this + 0x60) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(this + 0x60),(CMwNod *)pCVar7);
        }
        *(CMwNod **)(this + 0x60) = this_00;
      }
      CGameCtnMediaClipPlayer::ClipPreload
                (*(CGameCtnMediaClipPlayer **)(this + 0xa0),
                 *(CGameCtnMediaClipPlayer **)(this + 0x60),pCVar7);
      pCVar5 = *(CGameRace **)(this + 0x60);
    }
    if (pCVar5 != (CGameRace *)0x0) {
      pCVar1 = GetLocalPlayerInfo(this,unaff_EBX);
      if ((*(int *)(pCVar1 + 0x70) == 0) && (*(int *)(pCVar1 + 0x74) == 0)) {
        pCVar7 = (CGameCtnMediaClip *)0x0;
      }
      else {
        pCVar7 = (CGameCtnMediaClip *)0x1;
      }
      uVar8 = _DAT_00b2c060;
      iVar3 = MediaClipStart(this,pCVar5,pCVar7,param_2);
      if (((iVar3 != 0) &&
          (iVar3 = (**(code **)(*(int *)this + 0x94))(in_stack_00000014,uVar8), iVar3 != 0)) &&
         (param_2 == 0)) {
        piVar4 = (int *)(**(code **)(*(int *)this + 0x94))();
        (**(code **)(*piVar4 + 0x8c))(0);
      }
    }
  }
  return;
}
}

// =================================================
// Function: CGameRace::MediaClipStartGlobal
// =================================================
void __thiscall CGameRace::MediaClipStartGlobal(CGameRace *this,CGameRace *param_1)
{
{
  CGameCtnMediaClipPlayer *pCVar1;
  CGamePlayerInfo *pCVar2;
  int iVar3;
  CGameRace *unaff_ESI;
  CGameRace *unaff_EDI;
  CGameRace *unaff_retaddr;
  _func___cdecl_void *in_stack_00000008;
  CGameCtnMediaClip *in_stack_0000000c;
  CDx9VertexBuffer *in_stack_00000010;
  float in_stack_00000014;
  EPlugVideoTimer in_stack_00000018;
  int in_stack_0000001c;
  ulong in_stack_00000020;
  
  pCVar2 = GetLocalPlayerInfo(this,unaff_ESI);
  if ((*(int *)(pCVar2 + 0x70) == 0) && (*(int *)(pCVar2 + 0x74) == 0)) {
    iVar3 = (**(code **)(*(int *)this + 0xb8))();
    pCVar1 = *(CGameCtnMediaClipPlayer **)(iVar3 + 0x180);
    if (pCVar1 != (CGameCtnMediaClipPlayer *)0x0) {
      iVar3 = MediaClipIsPlayingGlobal(this,unaff_EDI);
      if (iVar3 != 0) {
        MediaClipStopGlobal(this,unaff_retaddr);
      }
      GetLocalPlayer(this,param_1);
      if (*(CGameCtnMediaClipPlayer **)(this + 0xa4) != (CGameCtnMediaClipPlayer *)0x0) {
        CGameCtnMediaClipPlayer::EndClipCallBackSet
                  (*(CGameCtnMediaClipPlayer **)(this + 0xa4),(CGameCtnMediaClipPlayer *)this,
                   (CMwNod *)MediaClipStopGlobal,in_stack_00000008);
        CGameCtnMediaClipPlayer::ClipSet
                  (*(CGameCtnMediaClipPlayer **)(this + 0xa4),pCVar1,in_stack_0000000c);
        CGameCtnMediaClipPlayer::Create
                  (*(CGameCtnMediaClipPlayer **)(this + 0xa4),in_stack_00000010);
        CGameCtnMediaClipPlayer::ClipTimeSet
                  (*(CGameCtnMediaClipPlayer **)(this + 0xa4),(CGameCtnMediaClipPlayer *)0x0,
                   in_stack_00000014);
        CGameCtnMediaClipPlayer::Play
                  (*(CGameCtnMediaClipPlayer **)(this + 0xa4),(CPlugFileVideo *)0x3f800000,
                   in_stack_00000018,in_stack_0000001c,in_stack_00000020);
      }
    }
  }
  return;
}
}

// =================================================
// Function: CGameRace::MediaClipStop
// =================================================
void __thiscall CGameRace::MediaClipStop(CGameRace *this,CGameRace *param_1)
{
{
  int iVar1;
  int *piVar2;
  CGamePlayer *pCVar3;
  CGamePlayer *pCVar4;
  CGameRace *unaff_ESI;
  STmRaceLowFps *unaff_EDI;
  CGameAdvertisingNadeo *unaff_retaddr;
  CGameRace *in_stack_00000008;
  ulong in_stack_0000000c;
  ulong in_stack_00000010;
  
  iVar1 = MediaClipIsPlaying(this,unaff_ESI);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*(int *)this + 0x94))();
    if (iVar1 != 0) {
      piVar2 = (int *)(**(code **)(*(int *)this + 0x94))();
      (**(code **)(*piVar2 + 0x8c))(1);
    }
    CGameCtnMediaClipPlayer::Stop(*(CGameCtnMediaClipPlayer **)(this + 0xa0),unaff_EDI);
    CGameCtnMediaClipPlayer::Destroy(*(CGameCtnMediaClipPlayer **)(this + 0xa0),unaff_retaddr);
    pCVar3 = GetLocalPlayer(this,param_1);
    *(undefined4 *)(this + 0xa8) = 5;
    if (*(int *)(this + 0xac) != 0) {
      if (*(int *)(this + 0x6c) == 0) {
        pCVar4 = SpectatorGetTargetPlayer(this,in_stack_00000008);
        if (pCVar4 != (CGamePlayer *)0x0) {
          CGamePlayerCameraSet::PlayerGameMobilIdSet
                    (*(CGamePlayerCameraSet **)(pCVar3 + 0x20),
                     *(CGamePlayerCameraSet **)(*(int *)(pCVar4 + 0x28) + 0x18),in_stack_0000000c);
        }
        CGamePlayerCameraSet::CamSwitchTo
                  (*(CGamePlayerCameraSet **)(pCVar3 + 0x20),*(CGamePlayerCameraSet **)(this + 0x80)
                   ,in_stack_00000010);
      }
      *(undefined4 *)(pCVar3 + 0x48) = 0xffffffff;
      return;
    }
    CGamePlayerCameraSet::CamSwitchTo
              (*(CGamePlayerCameraSet **)(pCVar3 + 0x20),
               *(CGamePlayerCameraSet **)(*(int *)(pCVar3 + 0x24) + 0x2c),(ulong)in_stack_00000008);
    CGamePlayerCameraSet::PlayerGameMobilIdSet
              (*(CGamePlayerCameraSet **)(pCVar3 + 0x20),
               *(CGamePlayerCameraSet **)(*(int *)(pCVar3 + 0x28) + 0x18),in_stack_0000000c);
  }
  return;
}
}

// =================================================
// Function: CGameRace::MediaClipStopGlobal
// =================================================
void __thiscall CGameRace::MediaClipStopGlobal(CGameRace *this,CGameRace *param_1)
{
{
  int iVar1;
  CGameRace *unaff_ESI;
  STmRaceLowFps *unaff_retaddr;
  CGameAdvertisingNadeo *in_stack_0000000c;
  
  iVar1 = MediaClipIsPlayingGlobal(this,unaff_ESI);
  if (iVar1 != 0) {
    CGameCtnMediaClipPlayer::Stop(*(CGameCtnMediaClipPlayer **)(this + 0xa4),unaff_retaddr);
    CGameCtnMediaClipPlayer::Destroy(*(CGameCtnMediaClipPlayer **)(this + 0xa4),in_stack_0000000c);
    return;
  }
  return;
}
}

// =================================================
// Function: CGameRace::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CGameRace::MwGetClassInfo(CGameRace *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d693bc;
}
}

// =================================================
// Function: CGameRace::MwIsKindOf
// =================================================
int __thiscall CGameRace::MwIsKindOf(CGameRace *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if (((param_1 != (CMwCmdAffectParam *)0x3073000) && (param_1 != (CMwCmdAffectParam *)0x300d000))
     && (param_1 != (CMwCmdAffectParam *)0x3008000)) {
    return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
  }
  return 1;
}
}

// =================================================
// Function: CGameRace::NetPlayerIsPlaying
// =================================================
int __thiscall
CGameRace::NetPlayerIsPlaying(CGameRace *this,CGameRace *param_1,CGamePlayerInfo *param_2)
{
{
  if (((param_1 != (CGameRace *)0x0) && (*(int *)(param_1 + 0x70) == 0)) &&
     (*(int *)(param_1 + 0x74) == 0)) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CGameRace::OnLocalPlayerSpectatorChange
// =================================================
void __thiscall CGameRace::OnLocalPlayerSpectatorChange(CGameRace *this,CGameRace *param_1)
{
{
  CGameScene *pCVar1;
  CGamePlayer *pCVar2;
  CGamePlayerInfo *pCVar3;
  CGameRace *unaff_ESI;
  CGameRace *unaff_EDI;
  CGameRace *unaff_retaddr;
  ulong in_stack_00000008;
  
  MediaClipStop(this,unaff_EDI);
  pCVar2 = GetLocalPlayer(this,unaff_ESI);
  pCVar3 = GetLocalPlayerInfo(this,unaff_retaddr);
  if ((*(int *)(pCVar3 + 0x70) == 0) && (*(int *)(pCVar3 + 0x74) == 0)) {
    if (*(int *)(*(int *)(pCVar2 + 0x28) + 0x14) != 0) {
      CGamePlayerCameraSet::PlayerGameMobilIdSet
                (*(CGamePlayerCameraSet **)(pCVar2 + 0x20),
                 *(CGamePlayerCameraSet **)(*(int *)(pCVar2 + 0x28) + 0x18),(ulong)param_1);
      CGamePlayerCameraSet::CamSwitchTo
                (*(CGamePlayerCameraSet **)(pCVar2 + 0x20),
                 *(CGamePlayerCameraSet **)(*(int *)(pCVar2 + 0x24) + 0x2c),in_stack_00000008);
      return;
    }
  }
  else {
    *(undefined4 *)(this + 0x9c) = 1;
    pCVar1 = *(CGameScene **)(pCVar2 + 0x28);
    if ((pCVar1 != (CGameScene *)0x0) && (*(int *)(pCVar1 + 0x1c) != -1)) {
      CGameScene::GameMobilRemove(*(CGameScene **)(this + 0x30),pCVar1,(CGameMobil *)param_1);
    }
  }
  return;
}
}

// =================================================
// Function: CGameRace::SavePreset
// =================================================
void __thiscall
CGameRace::SavePreset(CGameRace *this,CGameRace *param_1,ulong param_2,GmCamFreeVal *param_3)
{
{
  CGameRace *this_00;
  ulong uVar1;
  SCasterCat *pSVar2;
  int iVar3;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ulong unaff_retaddr;
  undefined4 *in_stack_00000014;
  
  this_00 = this + 100;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (param_2 < uVar1) {
    pSVar2 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
             ::operator[](this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                          unaff_ESI);
    *(undefined4 *)pSVar2 = 1;
    pSVar2 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
             ::operator[](this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                          unaff_retaddr);
    for (iVar3 = 0xb; pSVar2 = pSVar2 + 4, iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined4 *)pSVar2 = *in_stack_00000014;
      in_stack_00000014 = in_stack_00000014 + 1;
    }
  }
  return;
}
}

// =================================================
// Function: CGameRace::SetReplayRecord
// =================================================
void __thiscall
CGameRace::SetReplayRecord(CGameRace *this,CGameRace *param_1,CGameCtnReplayRecord *param_2)
{
{
  int *piVar1;
  CMwNod *unaff_EDI;
  
  piVar1 = *(int **)(this + 0xb0);
  if ((piVar1 != (int *)0x0) && (piVar1[0xb] != -1)) {
    (**(code **)(*piVar1 + 0x7c))();
  }
  if (param_1 != *(CGameRace **)(this + 0xb0)) {
    if (param_1 != (CGameRace *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0xb0) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xb0),unaff_EDI);
    }
    *(CGameRace **)(this + 0xb0) = param_1;
  }
  return;
}
}

// =================================================
// Function: CGameRace::SetStatus
// =================================================
void __thiscall CGameRace::SetStatus(CGameRace *this,CGameRace *param_1,EStatus param_2)
{
{
  if ((*(CGameRace **)(this + 0x50) != param_1) &&
     (*(CGameRace **)(this + 0x50) = param_1, param_1 == (CGameRace *)0x0)) {
    (**(code **)(*(int *)this + 0x84))();
  }
  return;
}
}

// =================================================
// Function: CGameRace::SpectatorGetTargetPlayer
// =================================================
CGamePlayer * __thiscall CGameRace::SpectatorGetTargetPlayer(CGameRace *this,CGameRace *param_1)
{
{
  if (*(int *)(this + 0x98) == 0) {
    return (CGamePlayer *)0x0;
  }
  return *(CGamePlayer **)(*(int *)(this + 0x98) + 0x238);
}
}

// =================================================
// Function: CGameRace::SpectatorMode_Set
// =================================================
void __thiscall
CGameRace::SpectatorMode_Set
          (CGameRace *this,CGameRace *param_1,CGamePlayerInfo *param_2,ESpectatorCameraType param_3)
{
{
  if (param_1 != (CGameRace *)0x0) {
    SpectatorMode_Set(this,param_1 + 0x28,param_2,param_3);
    return;
  }
  SpectatorMode_Set(this,(CGameRace *)&DAT_00d71c9c,param_2,param_3);
  return;
}
}

// =================================================
// Function: CGameRace::SpectatorSetCameraTarget
// =================================================
void __thiscall
CGameRace::SpectatorSetCameraTarget
          (CGameRace *this,CGameRace *param_1,ESpectatorCameraTarget param_2)
{
{
  *(CGameRace **)(this + 0x70) = param_1;
  return;
}
}

// =================================================
// Function: CGameRace::SpectatorSetCameraType
// =================================================
void __thiscall
CGameRace::SpectatorSetCameraType(CGameRace *this,CGameRace *param_1,ESpectatorCameraType param_2)
{
{
  int iVar1;
  CGameRace *unaff_ESI;
  CGameRace *unaff_retaddr;
  
  iVar1 = MediaClipIsPlaying(this,unaff_ESI);
  if (iVar1 == 0) {
    *(ESpectatorCameraType *)(this + 0x6c) = param_2;
    return;
  }
  if (*(int *)(this + 0xac) != 0) {
    if (*(int *)(this + 0xa8) != 0) {
      MediaClipStop(this,unaff_retaddr);
    }
    *(ESpectatorCameraType *)(this + 0x6c) = param_2;
    return;
  }
  *(ESpectatorCameraType *)(this + 0x6c) = param_2;
  return;
}
}

// =================================================
// Function: CGameRace::SwitchFromRace
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameRace::SwitchFromRace(CGameRace *this,CGameRace *param_1)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  int *piVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CGamePlayground *unaff_EDI;
  CGameCtnMediaClipPlayer *in_stack_ffffffe0;
  CGameCtnMediaClip *in_stack_ffffffe4;
  CGameCtnMediaClip *pCVar6;
  int iStack_8;
  
  CGamePlayground::CommonSwitchFrom((CGamePlayground *)this,unaff_EDI);
  _DAT_00cdbddc = 0x3f800000;
  if (*(int **)(this + 0xb0) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0xb0) + 0x7c))();
  }
  if (*(CGameCtnMediaClipPlayer **)(this + 0xa0) != (CGameCtnMediaClipPlayer *)0x0) {
    CGameCtnMediaClipPlayer::Destroy
              (*(CGameCtnMediaClipPlayer **)(this + 0xa0),(CGameAdvertisingNadeo *)unaff_ESI);
  }
  if (*(CGameCtnMediaClipPlayer **)(this + 0xa4) != (CGameCtnMediaClipPlayer *)0x0) {
    CGameCtnMediaClipPlayer::Destroy
              (*(CGameCtnMediaClipPlayer **)(this + 0xa4),(CGameAdvertisingNadeo *)unaff_ESI);
  }
  iVar1 = (**(code **)(*(int *)this + 0xb8))();
  if (*(CGameCtnMediaClipPlayer **)(this + 0xa0) != (CGameCtnMediaClipPlayer *)0x0) {
    pCVar6 = (CGameCtnMediaClip *)0x5dda79;
    CGameCtnMediaClipPlayer::ClipPreClean
              (*(CGameCtnMediaClipPlayer **)(this + 0xa0),*(CGameCtnMediaClipPlayer **)(this + 0x58)
               ,(CGameCtnMediaClip *)unaff_ESI);
    piVar4 = (int *)(iVar1 + 0x184);
    iVar1 = 2;
    unaff_ESI = unaff_EBX;
    do {
      if (*piVar4 != 0) {
        pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount((void *)(*piVar4 + 0x14),unaff_ESI);
        pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(*piVar4 + 0x14),pCVar5,(ulong)in_stack_ffffffe0);
            in_stack_ffffffe0 = *(CGameCtnMediaClipPlayer **)pSVar3;
            CGameCtnMediaClipPlayer::ClipPreClean
                      (*(CGameCtnMediaClipPlayer **)(this + 0xa0),in_stack_ffffffe0,
                       in_stack_ffffffe4);
            pCVar5 = pCVar5 + 1;
          } while (pCVar5 < pCVar2);
        }
      }
      piVar4 = piVar4 + 1;
      iStack_8 = iStack_8 + -1;
    } while (iStack_8 != 0);
    CGameCtnMediaClipPlayer::ClipPreClean
              (*(CGameCtnMediaClipPlayer **)(this + 0xa0),*(CGameCtnMediaClipPlayer **)(this + 0x60)
               ,pCVar6);
  }
  if ((*(CGameCtnMediaClipPlayer **)(iVar1 + 0x180) != (CGameCtnMediaClipPlayer *)0x0) &&
     (*(CGameCtnMediaClipPlayer **)(this + 0xa4) != (CGameCtnMediaClipPlayer *)0x0)) {
    CGameCtnMediaClipPlayer::ClipPreClean
              (*(CGameCtnMediaClipPlayer **)(this + 0xa4),
               *(CGameCtnMediaClipPlayer **)(iVar1 + 0x180),(CGameCtnMediaClip *)unaff_ESI);
  }
  if (*(CMwNod **)(this + 0x58) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x58),(CMwNod *)unaff_ESI);
    *(undefined4 *)(this + 0x58) = 0;
  }
  if (*(CMwNod **)(this + 0x60) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x60),(CMwNod *)unaff_ESI);
    *(undefined4 *)(this + 0x60) = 0;
  }
  if (*(CMwNod **)(this + 0xa0) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xa0),(CMwNod *)unaff_ESI);
    *(undefined4 *)(this + 0xa0) = 0;
  }
  if (*(CMwNod **)(this + 0xa4) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xa4),(CMwNod *)unaff_ESI);
    *(undefined4 *)(this + 0xa4) = 0;
  }
  return;
}
}

// =================================================
// Function: CGameRace::SwitchToRace
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameRace::SwitchToRace(CGameRace *this,CGameRace *param_1,GmNat3 param_2,ECardinalDir param_3)
{
{
  CGameCtnMediaContext *pCVar1;
  int iVar2;
  CGameCtnApp *this_00;
  CMwNod *extraout_EAX;
  CGameCtnMediaClipViewer *pCVar3;
  CGamePlayer *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  CMwNod *extraout_EAX_00;
  CGameCtnMediaClipPlayer *unaff_EBX;
  int *piVar7;
  CMwNod *pCVar8;
  CGameCtnMediaClipViewer *unaff_EBP;
  CGamePlayerCameraSet *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CGameRace *unaff_EDI;
  CGameApp *in_stack_ffffffbc;
  CGameRace *in_stack_ffffffc0;
  CGameCtnMediaClipPlayer *pCVar10;
  CGameCtnMediaContext *in_stack_ffffffc8;
  CGameCtnMediaClip *pCVar11;
  CGameCtnMediaContext *pCVar12;
  CGameCtnMediaClip *pCVar13;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aa19e6;
  local_c = ExceptionList;
  pCVar1 = (CGameCtnMediaContext *)(DAT_00cca150 ^ (uint)&stack0xffffffd8);
  ExceptionList = &local_c;
  iVar2 = (**(code **)(*(int *)this + 0xb8))();
  this_00 = (CGameCtnApp *)0x0;
  if (iVar2 != 0) {
    pCVar13 = (CGameCtnMediaClip *)0x130;
    pCVar12 = (CGameCtnMediaContext *)0x5de09b;
    this_00 = operator_new(0x130);
    uStack_4 = 0;
    if (this_00 == (CGameCtnApp *)0x0) {
      pCVar8 = (CMwNod *)0x0;
    }
    else {
      pCVar13 = (CGameCtnMediaClip *)0x5de0b5;
      CGameCtnMediaClipPlayer::CGameCtnMediaClipPlayer
                ((CGameCtnMediaClipPlayer *)this_00,(CGameCtnMediaClipPlayer *)pCVar1);
      pCVar8 = extraout_EAX;
    }
    uStack_4 = 0xffffffff;
    if (pCVar8 != *(CMwNod **)(this + 0xa0)) {
      if (pCVar8 != (CMwNod *)0x0) {
        pCVar13 = (CGameCtnMediaClip *)0x5de0d6;
        CMwNod::MwAddRef(pCVar8,(CMwNod *)pCVar1);
      }
      if (*(CMwNod **)(this + 0xa0) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0xa0),(CMwNod *)in_stack_ffffffbc);
      }
      *(CMwNod **)(this + 0xa0) = pCVar8;
    }
    pCVar3 = (CGameCtnMediaClipViewer *)
             CGameApp::MediaContextCreate(*(CGameApp **)(this + 0x18),in_stack_ffffffbc);
    pCVar1 = (CGameCtnMediaContext *)pCVar3;
    pCVar4 = GetLocalPlayer(this,in_stack_ffffffc0);
    pCVar8 = *(CMwNod **)(pCVar4 + 0x20);
    if (pCVar8 != *(CMwNod **)(pCVar3 + 0x28)) {
      if (pCVar8 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar8,(CMwNod *)in_stack_ffffffc8);
      }
      if (*(CMwNod **)(pCVar3 + 0x28) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(pCVar3 + 0x28),(CMwNod *)in_stack_ffffffc8);
      }
      *(CMwNod **)(pCVar3 + 0x28) = pCVar8;
    }
    *(undefined4 *)(pCVar3 + 0x38) = 0;
    *(undefined4 *)(pCVar3 + 0x3c) = 0;
    pCVar10 = (CGameCtnMediaClipPlayer *)pCVar3;
    CGameCtnMediaClipPlayer::ContextSet
              (*(CGameCtnMediaClipPlayer **)(this + 0xa0),pCVar3,in_stack_ffffffc8);
    piVar7 = (int *)(iVar2 + 0x184);
    iVar2 = 2;
    do {
      if (*piVar7 != 0) {
        pCVar11 = (CGameCtnMediaClip *)0x5de152;
        pCVar3 = unaff_EBP;
        pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           ((void *)(*piVar7 + 0x14),(CFastBuffer<class_CCrystalFace*> *)pCVar12);
        pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        unaff_EBP = pCVar3;
        if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(*piVar7 + 0x14),pCVar9,(ulong)pCVar10);
            pCVar10 = *(CGameCtnMediaClipPlayer **)pSVar6;
            CGameCtnMediaClipPlayer::ClipPreload
                      (*(CGameCtnMediaClipPlayer **)(this + 0xa0),pCVar10,pCVar11);
            pCVar9 = pCVar9 + 1;
            unaff_EBP = pCVar3;
          } while (pCVar9 < pCVar5);
        }
      }
      piVar7 = piVar7 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    unaff_EBX = operator_new(0x130);
    local_c = (void *)0x1;
    if (unaff_EBX == (CGameCtnMediaClipPlayer *)0x0) {
      pCVar8 = (CMwNod *)0x0;
    }
    else {
      CGameCtnMediaClipPlayer::CGameCtnMediaClipPlayer(unaff_EBX,(CGameCtnMediaClipPlayer *)pCVar12)
      ;
      pCVar8 = extraout_EAX_00;
    }
    local_c = (void *)0xffffffff;
    if (pCVar8 != *(CMwNod **)(this + 0xa4)) {
      if (pCVar8 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar8,(CMwNod *)pCVar12);
      }
      if (*(CMwNod **)(this + 0xa4) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0xa4),(CMwNod *)pCVar12);
      }
      *(CMwNod **)(this + 0xa4) = pCVar8;
    }
    CGameCtnMediaClipPlayer::ContextSet(*(CGameCtnMediaClipPlayer **)(this + 0xa4),pCVar3,pCVar12);
    if (*(CGameCtnMediaClipPlayer **)(this_00 + 0x180) != (CGameCtnMediaClipPlayer *)0x0) {
      CGameCtnMediaClipPlayer::ClipPreload
                (*(CGameCtnMediaClipPlayer **)(this + 0xa4),
                 *(CGameCtnMediaClipPlayer **)(this_00 + 0x180),pCVar13);
    }
  }
  *(undefined4 *)(this + 0x98) = 0;
  _DAT_00cdbddc = 0;
  pCVar4 = GetLocalPlayer(this,(CGameRace *)pCVar1);
  if (pCVar4 != (CGamePlayer *)0x0) {
    pCVar4 = GetLocalPlayer(this,unaff_EDI);
    CGamePlayerCameraSet::CamsReset(*(CGamePlayerCameraSet **)(pCVar4 + 0x20),unaff_ESI);
  }
  *(undefined4 *)(this + 0x74) = 0xffffffff;
  CGameCtnApp::Advertising_SetZone
            (*(CGameCtnApp **)(this + 0x18),this_00,(CGameCtnChallenge *)0x0,(int)unaff_EBP);
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)unaff_EBX);
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CGameRace::UpdateAsync
// =================================================
void __thiscall CGameRace::UpdateAsync(CGameRace *this,CInputPortDx8 *param_1)
{
{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*(int *)this + 0x94))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*(int *)this + 0x94))();
                    /* WARNING: Could not recover jumptable at 0x005dd8f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar2 + 0x88))();
    return;
  }
  return;
}
}

// =================================================
// Function: CGameRace::VirtualParam_Get
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CGameRace::VirtualParam_Get
          (CGameRace *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  CMwValueStd *unaff_ESI;
  SStringParam *in_stack_fffffff4;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0x3073004) {
    if ((_DAT_00d693f8 & 1) == 0) {
      _DAT_00d693f8 = _DAT_00d693f8 | 1;
      DAT_00d693f0 = 0;
      DAT_00d693f4 = (undefined2 *)PTR_DAT_00bbf7dc;
      _atexit(`public:_virtual_unsigned_long___thiscall_CGameRace::
              VirtualParam_Get(class_CMwStack*,class_CMwValueStd*)'::__l6::
              _dynamic_atexit_destructor_for__TargetName__);
    }
    if (DAT_00d693f0 != 0) {
      CFastStringBase<wchar_t>::AllocAtLeast
                (&DAT_00d693f0,(CFastStringBase<wchar_t> *)0x0,1,0,(SOldChars *)unaff_ESI);
      *DAT_00d693f4 = 0;
      DAT_00d693f0 = 0;
    }
    iVar1 = *(int *)(this + 0x98);
    if (iVar1 != 0) {
      local_8 = *(undefined4 *)(iVar1 + 0x18);
      local_4 = *(undefined4 *)(iVar1 + 0x14);
      CFastStringInt::SetString(&DAT_00d693f0,(CFastStringInt *)&local_8,in_stack_fffffff4);
    }
    *(int **)param_3 = &DAT_00d693f0;
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CGamePlayground::VirtualParam_Get((CGamePlayground *)this,param_1,param_2,unaff_ESI);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CGameRace::VirtualParam_Set
// =================================================
ulong __thiscall
CGameRace::VirtualParam_Set(CGameRace *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  uint uVar3;
  CGameRace *pCVar4;
  ulong uVar5;
  void *unaff_EDI;
  ESpectatorCameraType EVar6;
  ESpectatorCameraType EVar7;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 < 0x3073003) {
    if (uVar3 == 0x3073002) {
      EVar6 = *(ESpectatorCameraType *)param_2;
      EVar7 = EVar6;
      (**(code **)(*(int *)this + 0xd8))();
      if (EVar6 == 1) {
        SpectatorMode_Set(this,(CGameRace *)0x0,DAT_00d693b0,EVar7);
        return 0;
      }
      pCVar4 = *(CGameRace **)(this + 0x7c);
      if ((pCVar4 == (CGameRace *)0x0) &&
         (pCVar4 = *(CGameRace **)(this + 0x98), pCVar4 == (CGameRace *)0x0)) {
        pCVar4 = (CGameRace *)(**(code **)(*(int *)this + 0xdc))(0);
      }
      SpectatorMode_Set(this,pCVar4,DAT_00d693b0,EVar7);
      return 0;
    }
    if (uVar3 == 0x3073000) {
      if (-1 < iVar1 + -1) {
        CMwParamClass::SetValue((CMwParamClass *)0x0,(CMwCmdAffectParamBool *)(this + 0x54));
        return 0;
      }
      if (param_2 == (CMwStack *)0x0) {
        *(undefined4 *)(this + 0x54) = 0;
        return 0;
      }
      *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_2 + 8);
      return 0;
    }
    if (uVar3 == 0x3073001) {
      EVar6 = *(ESpectatorCameraType *)param_2;
      (**(code **)(*(int *)this + 0xd4))();
      SpectatorMode_Set(this,(CGameRace *)&DAT_00d693e8,*(CGamePlayerInfo **)param_2,EVar6);
      return 0;
    }
  }
  else if (uVar3 == 0xffffffff) {
    return 0;
  }
  *(int *)(param_1 + 0x18) = iVar1;
  uVar5 = CGamePlayground::VirtualParam_Set((CGamePlayground *)this,param_1,param_2,unaff_EDI);
  return uVar5;
}
}

// =================================================
// Function: CGameRace::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CGameRace::_scalar_deleting_destructor_(CGameRace *this,CPfmHeap *param_1,uint param_2)
{
{
  CGameRace *unaff_ESI;
  
  ~CGameRace(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CGameRace::~CGameRace
// =================================================
void __thiscall CGameRace::~CGameRace(CGameRace *this,CGameRace *param_1)
{
{
  CMwNod *pCVar1;
  CMwNod *unaff_ESI;
  void *in_stack_00000008;
  CGameRace *pCVar2;
  CMwNod *pCVar3;
  CGamePlayground *pCVar4;
  
  pCVar3 = ExceptionList;
  pCVar4 = (CGamePlayground *)&LAB_00aa1bac;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &stack0xfffffff4;
  *(undefined ***)this = vftable;
  pCVar2 = this;
  if (*(CMwNod **)(this + 0xb4) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xb4),pCVar1);
  }
  if (*(CMwNod **)(this + 0xb0) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xb0),unaff_ESI);
  }
  if (*(CMwNod **)(this + 0xa4) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xa4),unaff_ESI);
  }
  if (*(CMwNod **)(this + 0xa0) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xa0),unaff_ESI);
  }
  CFastBuffer<struct_CGameRace::SPlayerInfosForTargetting>::
  ~CFastBuffer<struct_CGameRace::SPlayerInfosForTargetting>
            (this + 0x8c,(CFastBuffer<struct_CGameRace::SPlayerInfosForTargetting> *)unaff_ESI);
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>
            (this + 100,(CFastArray<class_CFuncShader*> *)pCVar2);
  in_stack_00000008 = (void *)CONCAT31(in_stack_00000008._1_3_,2);
  if (*(CMwNod **)(this + 0x60) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x60),pCVar3);
  }
  if (*(CMwNod **)(this + 0x5c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x5c),(CMwNod *)pCVar4);
  }
  if (*(CMwNod **)(this + 0x58) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x58),(CMwNod *)pCVar4);
  }
  CGamePlayground::~CGamePlayground((CGamePlayground *)this,pCVar4);
  ExceptionList = in_stack_00000008;
  return;
}
}

