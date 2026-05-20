// Class implementation: CGameCtnMediaTracker

// =================================================
// Function: CGameCtnMediaTracker::ButFrameKeyAdvanced
// =================================================
void __thiscall
CGameCtnMediaTracker::ButFrameKeyAdvanced(CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  int iVar1;
  code *pcVar2;
  
  iVar1 = *(int *)(this + 0x44c);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) {
    iVar1 = (**(code **)(**(int **)(iVar1 + 0x14) + 0x108))();
    if (iVar1 == 0) {
      pcVar2 = *(code **)(**(int **)(*(int *)(this + 0x44c) + 0x14) + 0x100);
    }
    else {
      pcVar2 = *(code **)(**(int **)(*(int *)(this + 0x44c) + 0x14) + 0x104);
    }
    (*pcVar2)();
                    /* WARNING: Could not recover jumptable at 0x006631d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(*(int *)(this + 0x44c) + 0x14) + 0x1a8))();
    return;
  }
  return;
}
}

// =================================================
// Function: CGameCtnMediaTracker::ClipGet
// =================================================
CGameCtnMediaClip * __thiscall
CGameCtnMediaTracker::ClipGet(CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  return *(CGameCtnMediaClip **)(this + 0xac);
}
}

// =================================================
// Function: CGameCtnMediaTracker::FindBlockEditInfoFromClassId
// =================================================
SBlockEditInfo * __thiscall
CGameCtnMediaTracker::FindBlockEditInfoFromClassId
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1,ulong param_2)
{
{
  CGameCtnMediaTracker *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = this + 0x440;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (this_00,pCVar3,unaff_ESI);
      if (*(ulong *)pSVar2 == param_2) {
        pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                           (this_00,pCVar3,unaff_EBP);
        return (SBlockEditInfo *)pSVar2;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return (SBlockEditInfo *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelBlock
// =================================================
CGameCtnMediaBlock * __thiscall
CGameCtnMediaTracker::GetSelBlock(CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  CFastBufferRef<class_CGameCtnMediaTrack> *pCVar3;
  SCasterCat *pSVar4;
  CGameCtnMediaTracker *this_00;
  CGameCtnMediaTracker *extraout_EDX;
  CGameCtnMediaTracker *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_retaddr;
  ulong in_stack_00000008;
  
  iVar1 = *(int *)(this + 0xcc);
  if (iVar1 == 0) {
    return (CGameCtnMediaBlock *)0x0;
  }
  if ((*(int *)(iVar1 + 0x2c4) != -1) &&
     (pCVar2 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x2c8),
     pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff)) {
    pCVar3 = GetTracks(this,unaff_ESI);
    if (pCVar3 != (CFastBufferRef<class_CGameCtnMediaTrack> *)0x0) {
      pCVar3 = GetTracks(this_00,extraout_EDX);
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pCVar3,unaff_retaddr,(ulong)param_1);
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)pSVar4 + 0x1c),pCVar2,in_stack_00000008);
      return *(CGameCtnMediaBlock **)pSVar4;
    }
  }
  return (CGameCtnMediaBlock *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlock3dStereo>
// =================================================
CGameCtnMediaBlock3dStereo * __thiscall
CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlock3dStereo>
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CGameCtnMediaBlock *pCVar1;
  int iVar2;
  CGameCtnMediaTracker *unaff_ESI;
  
  pCVar1 = GetSelBlock(this,unaff_ESI);
  if (pCVar1 != (CGameCtnMediaBlock *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(*(undefined4 *)(PTR_DAT_00b8ac80 + 4));
    if (iVar2 != 0) {
      return (CGameCtnMediaBlock3dStereo *)pCVar1;
    }
  }
  return (CGameCtnMediaBlock3dStereo *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockCameraCustom>
// =================================================
CGameCtnMediaBlockCameraCustom * __thiscall
CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockCameraCustom>
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CGameCtnMediaBlock *pCVar1;
  int iVar2;
  CGameCtnMediaTracker *unaff_ESI;
  
  pCVar1 = GetSelBlock(this,unaff_ESI);
  if (pCVar1 != (CGameCtnMediaBlock *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(*(undefined4 *)(PTR_DAT_00b898bc + 4));
    if (iVar2 != 0) {
      return (CGameCtnMediaBlockCameraCustom *)pCVar1;
    }
  }
  return (CGameCtnMediaBlockCameraCustom *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockCameraEffectShake>
// =================================================
CGameCtnMediaBlockCameraEffectShake * __thiscall
CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockCameraEffectShake>
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CGameCtnMediaBlock *pCVar1;
  int iVar2;
  CGameCtnMediaTracker *unaff_ESI;
  
  pCVar1 = GetSelBlock(this,unaff_ESI);
  if (pCVar1 != (CGameCtnMediaBlock *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(*(undefined4 *)(PTR_DAT_00b8aab8 + 4));
    if (iVar2 != 0) {
      return (CGameCtnMediaBlockCameraEffectShake *)pCVar1;
    }
  }
  return (CGameCtnMediaBlockCameraEffectShake *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockCameraPath>
// =================================================
CGameCtnMediaBlockCameraPath * __thiscall
CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockCameraPath>
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CGameCtnMediaBlock *pCVar1;
  int iVar2;
  CGameCtnMediaTracker *unaff_ESI;
  
  pCVar1 = GetSelBlock(this,unaff_ESI);
  if (pCVar1 != (CGameCtnMediaBlock *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(*(undefined4 *)(PTR_DAT_00b89a78 + 4));
    if (iVar2 != 0) {
      return (CGameCtnMediaBlockCameraPath *)pCVar1;
    }
  }
  return (CGameCtnMediaBlockCameraPath *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockFxBloom>
// =================================================
CGameCtnMediaBlockFxBloom * __thiscall
CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockFxBloom>
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CGameCtnMediaBlock *pCVar1;
  int iVar2;
  CGameCtnMediaTracker *unaff_ESI;
  
  pCVar1 = GetSelBlock(this,unaff_ESI);
  if (pCVar1 != (CGameCtnMediaBlock *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(*(undefined4 *)(PTR_DAT_00b8a770 + 4));
    if (iVar2 != 0) {
      return (CGameCtnMediaBlockFxBloom *)pCVar1;
    }
  }
  return (CGameCtnMediaBlockFxBloom *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockFxBlurDepth>
// =================================================
CGameCtnMediaBlockFxBlurDepth * __thiscall
CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockFxBlurDepth>
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CGameCtnMediaBlock *pCVar1;
  int iVar2;
  CGameCtnMediaTracker *unaff_ESI;
  
  pCVar1 = GetSelBlock(this,unaff_ESI);
  if (pCVar1 != (CGameCtnMediaBlock *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(*(undefined4 *)(PTR_DAT_00b8a5b4 + 4));
    if (iVar2 != 0) {
      return (CGameCtnMediaBlockFxBlurDepth *)pCVar1;
    }
  }
  return (CGameCtnMediaBlockFxBlurDepth *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockFxColors>
// =================================================
CGameCtnMediaBlockFxColors * __thiscall
CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockFxColors>
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CGameCtnMediaBlock *pCVar1;
  int iVar2;
  CGameCtnMediaTracker *unaff_ESI;
  
  pCVar1 = GetSelBlock(this,unaff_ESI);
  if (pCVar1 != (CGameCtnMediaBlock *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(*(undefined4 *)(PTR_DAT_00b8a418 + 4));
    if (iVar2 != 0) {
      return (CGameCtnMediaBlockFxColors *)pCVar1;
    }
  }
  return (CGameCtnMediaBlockFxColors *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockImage>
// =================================================
CGameCtnMediaBlockImage * __thiscall
CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockImage>
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CGameCtnMediaBlock *pCVar1;
  int iVar2;
  CGameCtnMediaTracker *unaff_ESI;
  
  pCVar1 = GetSelBlock(this,unaff_ESI);
  if (pCVar1 != (CGameCtnMediaBlock *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(*(undefined4 *)(PTR_DAT_00b87bb0 + 4));
    if (iVar2 != 0) {
      return (CGameCtnMediaBlockImage *)pCVar1;
    }
  }
  return (CGameCtnMediaBlockImage *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockMusicEffect>
// =================================================
CGameCtnMediaBlockMusicEffect * __thiscall
CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockMusicEffect>
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CGameCtnMediaBlock *pCVar1;
  int iVar2;
  CGameCtnMediaTracker *unaff_ESI;
  
  pCVar1 = GetSelBlock(this,unaff_ESI);
  if (pCVar1 != (CGameCtnMediaBlock *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(*(undefined4 *)(PTR_DAT_00b8a90c + 4));
    if (iVar2 != 0) {
      return (CGameCtnMediaBlockMusicEffect *)pCVar1;
    }
  }
  return (CGameCtnMediaBlockMusicEffect *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockSound>
// =================================================
CGameCtnMediaBlockSound * __thiscall
CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockSound>
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CGameCtnMediaBlock *pCVar1;
  int iVar2;
  CGameCtnMediaTracker *unaff_ESI;
  
  pCVar1 = GetSelBlock(this,unaff_ESI);
  if (pCVar1 != (CGameCtnMediaBlock *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(*(undefined4 *)(PTR_DAT_00b87528 + 4));
    if (iVar2 != 0) {
      return (CGameCtnMediaBlockSound *)pCVar1;
    }
  }
  return (CGameCtnMediaBlockSound *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockText>
// =================================================
CGameCtnMediaBlockText * __thiscall
CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockText>
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CGameCtnMediaBlock *pCVar1;
  int iVar2;
  CGameCtnMediaTracker *unaff_ESI;
  
  pCVar1 = GetSelBlock(this,unaff_ESI);
  if (pCVar1 != (CGameCtnMediaBlock *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(*(undefined4 *)(PTR_DAT_00b89ed4 + 4));
    if (iVar2 != 0) {
      return (CGameCtnMediaBlockText *)pCVar1;
    }
  }
  return (CGameCtnMediaBlockText *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockTime>
// =================================================
CGameCtnMediaBlockTime * __thiscall
CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockTime>
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CGameCtnMediaBlock *pCVar1;
  int iVar2;
  CGameCtnMediaTracker *unaff_ESI;
  
  pCVar1 = GetSelBlock(this,unaff_ESI);
  if (pCVar1 != (CGameCtnMediaBlock *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(*(undefined4 *)(PTR_DAT_00b8a28c + 4));
    if (iVar2 != 0) {
      return (CGameCtnMediaBlockTime *)pCVar1;
    }
  }
  return (CGameCtnMediaBlockTime *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockTransitionFade>
// =================================================
CGameCtnMediaBlockTransitionFade * __thiscall
CGameCtnMediaTracker::GetSelBlock<class_CGameCtnMediaBlockTransitionFade>
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CGameCtnMediaBlock *pCVar1;
  int iVar2;
  CGameCtnMediaTracker *unaff_ESI;
  
  pCVar1 = GetSelBlock(this,unaff_ESI);
  if (pCVar1 != (CGameCtnMediaBlock *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(*(undefined4 *)(PTR_DAT_00b8a0a8 + 4));
    if (iVar2 != 0) {
      return (CGameCtnMediaBlockTransitionFade *)pCVar1;
    }
  }
  return (CGameCtnMediaBlockTransitionFade *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetSelTrack
// =================================================
CGameCtnMediaTrack * __thiscall
CGameCtnMediaTracker::GetSelTrack(CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CFastBufferRef<class_CGameCtnMediaTrack> *pCVar1;
  SCasterCat *pSVar2;
  CGameCtnMediaTracker *this_00;
  CGameCtnMediaTracker *extraout_EDX;
  CGameCtnMediaTracker *unaff_retaddr;
  ulong in_stack_00000008;
  
  if ((*(int *)(this + 0xcc) != 0) && (*(int *)(*(int *)(this + 0xcc) + 0x2c4) != -1)) {
    pCVar1 = GetTracks(this,unaff_retaddr);
    if (pCVar1 != (CFastBufferRef<class_CGameCtnMediaTrack> *)0x0) {
      pCVar1 = GetTracks(this_00,extraout_EDX);
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                          in_stack_00000008);
      return *(CGameCtnMediaTrack **)pSVar2;
    }
  }
  return (CGameCtnMediaTrack *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::GetTracks
// =================================================
CFastBufferRef<class_CGameCtnMediaTrack> * __thiscall
CGameCtnMediaTracker::GetTracks(CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CGameCtnMediaClip *pCVar1;
  CGameCtnMediaTracker *this_00;
  CGameCtnMediaTracker *unaff_retaddr;
  
  pCVar1 = ClipGet(this,unaff_retaddr);
  if (pCVar1 != (CGameCtnMediaClip *)0x0) {
    pCVar1 = ClipGet(this_00,param_1);
    return (CFastBufferRef<class_CGameCtnMediaTrack> *)(pCVar1 + 0x14);
  }
  return (CFastBufferRef<class_CGameCtnMediaTrack> *)0x0;
}
}

// =================================================
// Function: CGameCtnMediaTracker::IsBlockingMode
// =================================================
int __thiscall
CGameCtnMediaTracker::IsBlockingMode(CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  if ((*(int *)(this + 400) != 0xd) && (*(int *)(this + 400) != 0xf)) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CGameCtnMediaTracker::UpdateAsync
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameCtnMediaTracker::UpdateAsync(CGameCtnMediaTracker *this,CInputPortDx8 *param_1)
{
{
  CGameCtnMediaClipPlayer *this_00;
  int *piVar1;
  GmVec3 *pGVar2;
  CFastStringInt *extraout_EAX;
  GmIso3 *pGVar3;
  ulong uVar4;
  CGameCtnChallenge *extraout_EAX_00;
  CGameCtnChallenge *extraout_EAX_01;
  CGameCtnChallenge *extraout_EAX_02;
  int iVar5;
  CGameCtnZone *pCVar6;
  int iVar7;
  int iVar8;
  CGameCtnMediaTrack *pCVar9;
  CGameCtnMediaBlock *pCVar10;
  CGameCtnMediaBlockText *pCVar11;
  CGameCtnMediaBlockImage *pCVar12;
  CGameCtnMediaBlockCameraCustom *pCVar13;
  CGameCtnMediaBlockCameraPath *pCVar14;
  CGameCtnMediaBlockTime *pCVar15;
  CGameCtnMediaBlockFxColors *pCVar16;
  CGameCtnMediaBlockFxBlurDepth *pCVar17;
  CGameCtnMediaBlockFxBloom *pCVar18;
  CGameCtnMediaBlockMusicEffect *pCVar19;
  CGameCtnMediaBlockSound *pCVar20;
  CGameCtnMediaBlockTransitionFade *pCVar21;
  CGameCtnMediaBlockCameraEffectShake *pCVar22;
  CGameCtnMediaBlock3dStereo *pCVar23;
  SCasterCat *pSVar24;
  SGameCamVal *pSVar25;
  int extraout_EAX_03;
  undefined4 uVar26;
  STransformDesc *unaff_EBX;
  SStringParam *unaff_EBP;
  ulong unaff_ESI;
  int unaff_EDI;
  bool bVar27;
  undefined2 in_FPUControlWord;
  float10 fVar28;
  float fVar29;
  undefined4 uStack00000018;
  GmIso4 *pGVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  CInputPortDx8 *in_stack_fffffeb4;
  GmVec4 *in_stack_fffffeb8;
  undefined4 uVar34;
  float *pfVar35;
  STransformDesc *pSVar36;
  CGameCtnMediaTracker *pCVar37;
  CGameCtnMediaTracker *pCVar38;
  GmCamFreeVal *in_stack_fffffed4;
  CGameCtnChallenge *in_stack_fffffed8;
  GmIso3 *pGVar39;
  CGameCtnMediaTracker *in_stack_fffffedc;
  CGameCtnMediaClipPlayer *in_stack_fffffee0;
  CGameCtnMediaTracker *in_stack_fffffee4;
  undefined8 local_118;
  CGameCtnChallenge *local_110;
  CGameCtnChallenge *local_10c;
  STransformDesc *pSStack_108;
  float local_104;
  CGameCtnChallenge *pCStack_100;
  CGameCtnChallenge *local_fc;
  CGameCtnChallenge *local_f8;
  SKeyVal *local_f4;
  undefined4 local_f0;
  float fStack_ec;
  undefined4 uStack_e8;
  int iStack_e4;
  int iStack_e0;
  int iStack_dc;
  undefined1 auStack_c8 [88];
  undefined1 auStack_70 [8];
  GmCamFreeVal aGStack_68 [16];
  CGameCtnCursor aCStack_58 [4];
  undefined1 auStack_54 [24];
  undefined1 auStack_3c [48];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aaee11;
  local_c = ExceptionList;
  pGVar2 = (GmVec3 *)(DAT_00cca150 ^ (uint)&stack0xfffffec4);
  ExceptionList = &local_c;
  if (*(int *)(this + 0x2c) == 0) {
    iVar7 = *(int *)(this + 0xa0);
    if (iVar7 != 0) {
      if (*(int *)(this + 0xdc) == 0) {
        local_110 = (CGameCtnChallenge *)0x3f800000;
        local_10c = (CGameCtnChallenge *)0x3f800000;
        local_fc = _DAT_00b2c060;
        local_f8 = _DAT_00b2c060;
        local_f4 = (SKeyVal *)0x3f800000;
        local_f0 = 0x3f800000;
        pCVar37 = (CGameCtnMediaTracker *)&local_fc;
        in_stack_fffffed8 = _DAT_00b2c060;
        in_stack_fffffedc = (CGameCtnMediaTracker *)_DAT_00b2c060;
      }
      else {
        pCVar37 = this + 0xe0;
      }
      *(undefined4 *)(iVar7 + 0x2c) = *(undefined4 *)pCVar37;
      *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)(pCVar37 + 4);
      *(undefined4 *)(iVar7 + 0x34) = *(undefined4 *)(pCVar37 + 8);
      *(undefined4 *)(iVar7 + 0x38) = *(undefined4 *)(pCVar37 + 0xc);
      CGameSafeFrame::Update
                (*(CGameSafeFrame **)(this + 0xa0),(SGmSmoothReal2 *)pGVar2,unaff_EDI,unaff_ESI);
    }
    if (*(int *)(this + 0x118) != 0) {
      CFastStringInt::CFastStringInt(&local_104,(CFastStringInt *)0xb78fa0,unaff_EBP);
      CFastStringInt::CFastStringInt
                (&local_118,(CFastStringInt *)&DAT_00b38330,(SStringParam *)unaff_EBX);
      unaff_EBX = (STransformDesc *)0x0;
      unaff_EBP = (SStringParam *)0x0;
      pGVar2 = (GmVec3 *)0x66a148;
      CGameDialogs::DoMessage
                (*(CGameDialogs **)(*(int *)(*(int *)(this + 0x11c) + 0x14) + 0x30),
                 (CGameDialogs *)&local_fc,extraout_EAX,(CFastStringInt *)0x0,(CMwNod *)0x0,
                 (_func___cdecl_void *)in_stack_fffffed4);
      if (local_10c != (CGameCtnChallenge *)PTR_DAT_00bbf7dc) {
        in_stack_fffffed4 = (GmCamFreeVal *)(local_10c + -4);
        if (((byte)local_10c[-1] & 0x80) == 0) {
          in_stack_fffffed4 = (GmCamFreeVal *)(local_10c + -2);
        }
        unaff_EBX = (STransformDesc *)0x66a168;
        operator_delete__(in_stack_fffffed4);
        local_110 = (CGameCtnChallenge *)0x0;
        local_10c = (CGameCtnChallenge *)PTR_DAT_00bbf7dc;
      }
      if (local_f4 != (SKeyVal *)PTR_DAT_00bbf7dc) {
        in_stack_fffffed4 = (GmCamFreeVal *)(local_f4 + -4);
        if (((byte)local_f4[-1] & 0x80) == 0) {
          in_stack_fffffed4 = (GmCamFreeVal *)(local_f4 + -2);
        }
        unaff_EBX = (STransformDesc *)0x66a19c;
        operator_delete__(in_stack_fffffed4);
      }
      *(undefined4 *)(this + 0x118) = 0;
    }
    pfVar35 = (float *)0x66a1ad;
    UpdateToolTips(this,(CGameCtnMediaTracker *)0x0,(int)unaff_EBP);
    if ((*(int *)(this + 0x210) != 0) || (*(int *)(*(int *)(this + 0xcc) + 0x2e8) != 0)) {
      *(undefined4 *)(*(int *)(this + 0xcc) + 0x2e8) = 1;
      (**(code **)(**(int **)(this + 0xcc) + 0x1a8))();
      *(undefined4 *)(this + 0x210) = 0;
    }
    pCStack_100 = *(CGameCtnChallenge **)(DAT_00d731e0 + 0x80);
    if ((*(int *)(this + 400) == 0) || (*(int *)(this + 400) == 0xd)) {
      pSVar36 = (STransformDesc *)0x66a218;
      GmLocVal::Reset(auStack_70,(GmFrustumIso4 *)unaff_EBX);
      GmLensVal::Reset(auStack_3c,(GmFrustumIso4 *)in_stack_fffffed4);
      in_stack_fffffed4 = aGStack_68;
      unaff_EBX = (STransformDesc *)0x66a23d;
      GmCamFreeVal::GetCamVal
                ((void *)(*(int *)(this + 0x288) + 0x158),in_stack_fffffed4,
                 (GmCamVal *)in_stack_fffffed8);
      if (*(int *)(this + 400) == 0xd) {
        iVar7 = *(int *)(this + 0x11c);
        iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 0x14) + 0x24) + 0x74) + 0x30) +
                        0x1a0);
        local_10c = *(CGameCtnChallenge **)(iVar5 + 0x44);
        pSStack_108 = *(STransformDesc **)(iVar5 + 0x48);
        local_104 = *(float *)(iVar5 + 0x4c);
        local_110 = (CGameCtnChallenge *)
                    (local_104 * local_104 +
                    (float)local_10c * (float)local_10c + (float)pSStack_108 * (float)pSStack_108);
        if (_DAT_00cf3768 < (float)local_110) {
          fVar28 = (float10)func_0x009c1b40();
          local_110 = (CGameCtnChallenge *)(1.0 / (float)fVar28);
          local_10c = (CGameCtnChallenge *)((float)local_110 * (float)local_10c);
          pSStack_108 = (STransformDesc *)((float)pSStack_108 * (float)local_110);
          local_104 = (float)local_110 * local_104;
        }
        iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 0x14) + 0x24) + 0x74) + 0x30) +
                        0x1a0);
        fStack_ec = *(float *)(iVar5 + 0x50);
        uStack_e8 = *(undefined4 *)(iVar5 + 0x54);
        iStack_e4 = *(int *)(iVar5 + 0x58);
        pGVar39 = (GmIso3 *)0x0;
        pGVar3 = (GmIso3 *)
                 (**(code **)(**(int **)(*(int *)(*(int *)(iVar7 + 0x14) + 0x24) + 0x74) + 0x7c))();
        unaff_EBX = (STransformDesc *)0x66a32b;
        GmVec3::Mult(&local_110,pGVar3,pGVar39);
        in_stack_fffffed4 = (GmCamFreeVal *)0x66a342;
        pGVar3 = (GmIso3 *)
                 (**(code **)(**(int **)(*(int *)(*(int *)(*(int *)(this + 0x11c) + 0x14) + 0x24) +
                                        0x74) + 0x7c))();
        GmVec3::Mult(&pSStack_108,pGVar3,(GmIso3 *)pGVar2);
        pGVar2 = (GmVec3 *)&stack0xfffffed8;
        in_stack_fffffed8 = (CGameCtnChallenge *)((float)*(int *)(this + 0x194) * _DAT_00ce9478);
        in_stack_fffffeb8 = (GmVec4 *)&local_104;
        local_f8 = (CGameCtnChallenge *)0x0;
        local_f4 = (SKeyVal *)0x3f800000;
        local_f0 = 0;
        fStack_ec = ((float)_DAT_00b56ec0 * 0.0 - (float)in_stack_fffffed8) - 0.0;
        in_stack_fffffeb4 = (CInputPortDx8 *)0x66a39c;
        uVar4 = GmVec4::PlaneEqInterLine
                          (&local_f8,in_stack_fffffeb8,(GmVec3 *)&stack0xfffffedc,pGVar2,pfVar35);
        if (uVar4 != 0) {
          iVar7 = *(int *)(*(int *)(this + 0x11c) + 0x28);
          iStack_e4 = *(int *)(iVar7 + 0xa8);
          iStack_e0 = *(int *)(iVar7 + 0xac);
          iStack_dc = *(int *)(iVar7 + 0xb0);
          local_118 = CONCAT44((float)pCStack_100 +
                               (float)in_stack_fffffedc * (float)in_stack_fffffee0,
                               (SGmSmoothReal2 *)local_118);
          local_110 = (CGameCtnChallenge *)
                      ((float)local_fc + (float)in_stack_fffffee4 * (float)in_stack_fffffedc);
          local_10c = (CGameCtnChallenge *)
                      ((float)local_f8 +
                      (float)in_stack_fffffedc * (float)(SGmSmoothReal2 *)local_118);
          __ftol2_sse();
          in_stack_fffffedc = (CGameCtnMediaTracker *)extraout_EAX_00;
          __ftol2_sse();
          __ftol2_sse();
          iStack_dc = iStack_dc + -1;
          iStack_e0 = iStack_e0 + -1;
          local_f4 = (SKeyVal *)0x0;
          local_f0 = 0;
          fStack_ec = 0.0;
          pGVar2 = (GmVec3 *)&local_f4;
          iStack_e4 = iStack_e4 + -1;
          local_118 = CONCAT44(extraout_EAX_02,(SGmSmoothReal2 *)local_118);
          local_110 = extraout_EAX_01;
          local_10c = extraout_EAX_00;
          pCStack_100 = extraout_EAX_02;
          local_fc = extraout_EAX_01;
          local_f8 = extraout_EAX_00;
          GmVector3<int>::Clamp
                    (&pCStack_100,(GmVector3<int> *)pGVar2,(GmVector3<int> *)&iStack_e4,
                     (GmVector3<int> *)unaff_EBX);
          iVar7 = *(int *)(this + 0x198);
          local_f0 = *(undefined4 *)(iVar7 + 0x14);
          fStack_ec = *(float *)(iVar7 + 0x18);
          uStack_e8 = *(undefined4 *)(iVar7 + 0x1c);
          if (((extraout_EAX_02 == local_fc) && (extraout_EAX_01 == local_f8)) &&
             (in_stack_fffffee0 == (CGameCtnMediaClipPlayer *)local_f4)) {
            unaff_EBX = (STransformDesc *)&local_110;
            iVar5 = GmVector3<int>::operator!=(&local_f0,unaff_EBX,pSVar36);
            if (iVar5 != 0) {
              uVar26 = *(undefined4 *)(iVar7 + 0x1c);
              pCVar6 = CGameCtnChallenge::GetRealZone
                                 (*(CGameCtnChallenge **)(*(int *)(this + 0x11c) + 0x28),
                                  *(CGameCtnChallenge **)(iVar7 + 0x14),
                                  SUB41(*(undefined4 *)(iVar7 + 0x18),0));
              unaff_EBX = pSStack_108;
              if (*(int *)(pCVar6 + 0x1c) == 1) {
                CGameCtnChallenge::GetZoneHeight
                          (*(CGameCtnChallenge **)(this + 0x20),extraout_EAX_02,
                           SUB41(extraout_EAX_01,0));
              }
              else {
                CGameCtnChallenge::GetZoneHeight
                          (*(CGameCtnChallenge **)(this + 0x20),extraout_EAX_02,
                           SUB41(extraout_EAX_01,0));
              }
              pGVar2 = (GmVec3 *)0x0;
              uVar34 = 0;
              in_stack_fffffeb8 = (GmVec4 *)0x1;
              in_stack_fffffeb4 = (CInputPortDx8 *)0x0;
              uVar33 = 0;
              uVar32 = 0;
              uVar31 = 0;
              pGVar30 = (GmIso4 *)0x1;
              CGameCtnCursor::Update(*(CGameCtnCursor **)(this + 0x198),(SGmSmoothReal2 *)0x0,1,0);
              iVar7 = *(int *)(this + 0x198);
              *(CGameCtnChallenge **)(iVar7 + 0x14) = extraout_EAX_02;
              *(undefined4 *)(iVar7 + 0x18) = uVar26;
              *(STransformDesc **)(iVar7 + 0x1c) = unaff_EBX;
              CGameCtnCursor::GetMobilLocation
                        (*(CGameCtnCursor **)(this + 0x198),aCStack_58,pGVar30);
              (**(code **)(**(int **)(*(int *)(this + 0x198) + 0x44) + 0x88))
                        (auStack_54,0,uVar31,uVar32,uVar33,in_stack_fffffeb4,in_stack_fffffeb8,
                         uVar34);
            }
          }
        }
      }
    }
    iVar7 = (**(code **)(**(int **)(this + 0x288) + 0x8c))();
    if (iVar7 != 0) {
      (**(code **)(**(int **)(this + 0x288) + 0x7c))();
    }
    if (*(int *)(*(CControlSimi2 **)(this + 0x228) + 0x38) != 0) {
      in_stack_fffffee4 =
           (CGameCtnMediaTracker *)
           CONCAT22((short)((uint)in_stack_fffffee4 >> 0x10),in_FPUControlWord);
      local_118 = (longlong)ROUND((float)pCStack_100 * (float)_DAT_00c418d8);
      CControlSimi2::Update
                (*(CControlSimi2 **)(this + 0x228),(SGmSmoothReal2 *)local_118,(int)unaff_EBX,
                 (ulong)in_stack_fffffed4);
    }
    iVar7 = (**(code **)(**(int **)(this + 0x28c) + 0x7c))();
    if (iVar7 != 0) {
      in_stack_fffffee4 =
           (CGameCtnMediaTracker *)
           CONCAT22((short)((uint)in_stack_fffffee4 >> 0x10),in_FPUControlWord);
      local_118 = (longlong)ROUND((float)pCStack_100 * (float)_DAT_00c418d8);
      (**(code **)(**(int **)(this + 0x28c) + 0x84))();
    }
    iVar7 = (**(code **)(**(int **)(this + 0x2f0) + 0x7c))();
    if (iVar7 != 0) {
      in_stack_fffffee4 =
           (CGameCtnMediaTracker *)
           CONCAT22((short)((uint)in_stack_fffffee4 >> 0x10),in_FPUControlWord);
      local_118 = (longlong)ROUND((float)pCStack_100 * (float)_DAT_00c418d8);
      (**(code **)(**(int **)(this + 0x2f0) + 0x84))();
    }
    if ((*(int *)(this + 0xcc) != 0) &&
       (iVar7 = CGameCtnMediaClipPlayer::IsPlaying
                          (*(CGameCtnMediaClipPlayer **)(this + 0xb4),(COalAudioSound *)unaff_EBX),
       iVar7 != 0)) {
      in_stack_fffffed4 =
           (GmCamFreeVal *)
           CGameCtnMediaClipPlayer::ClipTimeGet
                     (*(CGameCtnMediaClipPlayer **)(this + 0xb4),
                      (CGameCtnMediaClipPlayer *)in_stack_fffffed4);
      unaff_EBX = (STransformDesc *)0x66a70b;
      CControlTimeLine2::TimeSet
                (*(CControlTimeLine2 **)(this + 0xcc),(CControlTimeLine2 *)in_stack_fffffed4,
                 (float)in_stack_fffffed8);
    }
    iVar5 = IsBlockingMode(this,(CGameCtnMediaTracker *)unaff_EBX);
    iVar7 = *(int *)(this + 0xcc);
    if (iVar5 == 0) {
      pCVar37 = (CGameCtnMediaTracker *)0x66a733;
      fVar29 = CGameCtnMediaClipPlayer::ClipTimeGet
                         (*(CGameCtnMediaClipPlayer **)(this + 0xb4),
                          (CGameCtnMediaClipPlayer *)in_stack_fffffed4);
      local_118 = CONCAT44(fVar29,(SGmSmoothReal2 *)local_118);
      if ((*(int *)(this + 0xfc) != 0) ||
         (iVar8 = CGameCtnMediaClipPlayer::IsPlaying
                            (*(CGameCtnMediaClipPlayer **)(this + 0xb4),
                             (COalAudioSound *)in_stack_fffffed8), iVar8 != 0)) {
        fVar29 = 9.427259e-39;
        iVar8 = CGameCtnMediaClipPlayer::IsPlaying
                          (*(CGameCtnMediaClipPlayer **)(this + 0xb4),
                           (COalAudioSound *)in_stack_fffffedc);
        if (iVar8 == 0) {
          in_stack_fffffedc = (CGameCtnMediaTracker *)0x66a76c;
          CGameCtnMediaClipPlayer::UpdateTracksCmd
                    (*(CGameCtnMediaClipPlayer **)(this + 0xb4),(CGameCtnMediaClipPlayer *)pCVar37);
        }
        pCVar9 = GetSelTrack(this,pCVar37);
        if ((pCVar9 != (CGameCtnMediaTrack *)0x0) &&
           (pCVar10 = GetSelBlock(this,in_stack_fffffedc), pCVar10 != (CGameCtnMediaBlock *)0x0)) {
          switch(*(undefined4 *)(this + 400)) {
          case 1:
            pCVar37 = this + 0x290;
            pCVar13 = GetSelBlock<class_CGameCtnMediaBlockCameraCustom>(this,local_118._4_4_);
            CGameCtnMediaBlockCameraCustom::GetValue(pCVar13,(CFuncColorGradient *)pCVar37,fVar29);
            break;
          case 2:
            pCVar37 = this + 0x2f4;
            pCVar38 = local_118._4_4_;
            pCVar14 = GetSelBlock<class_CGameCtnMediaBlockCameraPath>
                                (this,(CGameCtnMediaTracker *)0x1);
            CGameCtnMediaBlockCameraPath::GetValue
                      (pCVar14,(CFuncColorGradient *)pCVar38,(float)pCVar37);
            break;
          case 4:
            pCVar22 = GetSelBlock<class_CGameCtnMediaBlockCameraEffectShake>(this,in_stack_fffffedc)
            ;
            (**(code **)(*(int *)pCVar22 + 0xec))();
            break;
          case 5:
            pCVar11 = GetSelBlock<class_CGameCtnMediaBlockText>(this,in_stack_fffffedc);
            CControlEffectSimi::GetValue
                      (*(CControlEffectSimi **)(pCVar11 + 0x38),(CFuncColorGradient *)local_110,
                       (float)(this + 0x22c));
            break;
          case 6:
            pCVar37 = this + 0x348;
            pCVar15 = GetSelBlock<class_CGameCtnMediaBlockTime>(this,local_118._4_4_);
            CGameCtnMediaBlockTime::GetValue(pCVar15,(CFuncColorGradient *)pCVar37,fVar29);
            break;
          case 7:
            pCVar37 = this + 0x3ec;
            pCVar21 = GetSelBlock<class_CGameCtnMediaBlockTransitionFade>(this,local_118._4_4_);
            CGameCtnMediaBlockTransitionFade::GetValue(pCVar21,(CFuncColorGradient *)pCVar37,fVar29)
            ;
            break;
          case 9:
            pCVar37 = this + 0x350;
            pCVar16 = GetSelBlock<class_CGameCtnMediaBlockFxColors>(this,local_118._4_4_);
            CGameCtnMediaBlockFxColors::GetValue(pCVar16,(CFuncColorGradient *)pCVar37,fVar29);
            break;
          case 10:
            pCVar37 = this + 0x3c4;
            pCVar17 = GetSelBlock<class_CGameCtnMediaBlockFxBlurDepth>(this,local_118._4_4_);
            CGameCtnMediaBlockFxBlurDepth::GetValue(pCVar17,(CFuncColorGradient *)pCVar37,fVar29);
            UpdateControlsState_FrameBlockFxBlurDepth(this,in_stack_fffffedc);
            break;
          case 0xb:
            pCVar37 = this + 0x3d8;
            pCVar20 = GetSelBlock<class_CGameCtnMediaBlockSound>(this,local_118._4_4_);
            CGameCtnMediaBlockSound::GetValue(pCVar20,(CFuncColorGradient *)pCVar37,fVar29);
            break;
          case 0xc:
            pCVar12 = GetSelBlock<class_CGameCtnMediaBlockImage>(this,in_stack_fffffedc);
            CControlEffectSimi::GetValue
                      (*(CControlEffectSimi **)(pCVar12 + 0x28),(CFuncColorGradient *)local_110,
                       (float)(this + 600));
            break;
          case 0xe:
            pCVar37 = this + 0x3f0;
            pCVar19 = GetSelBlock<class_CGameCtnMediaBlockMusicEffect>(this,local_118._4_4_);
            CGameCtnMediaBlockMusicEffect::GetValue(pCVar19,(CFuncColorGradient *)pCVar37,fVar29);
            break;
          case 0x10:
            pCVar37 = this + 0x3f8;
            pCVar23 = GetSelBlock<class_CGameCtnMediaBlock3dStereo>(this,local_118._4_4_);
            CGameCtnMediaBlock3dStereo::GetValue(pCVar23,(CFuncColorGradient *)pCVar37,fVar29);
            break;
          case 0x11:
            pCVar37 = this + 0x3d0;
            pCVar18 = GetSelBlock<class_CGameCtnMediaBlockFxBloom>(this,local_118._4_4_);
            CGameCtnMediaBlockFxBloom::GetValue(pCVar18,(CFuncColorGradient *)pCVar37,fVar29);
          }
        }
      }
      pCVar37 = *(CGameCtnMediaTracker **)(iVar7 + 0x2cc);
      if (pCVar37 != (CGameCtnMediaTracker *)0xffffffff) {
        switch(*(undefined4 *)(this + 400)) {
        case 1:
          pCVar38 = this + 0x290;
          pCVar13 = GetSelBlock<class_CGameCtnMediaBlockCameraCustom>(this,pCVar37);
          CFastBufferKey<struct_CGameCtnMediaBlockCameraCustom::SKeyVal>::SetVal
                    ((CFastBufferKey<struct_CGameCtnMediaBlockCameraCustom::SKeyVal> *)
                     (pCVar13 + 0x24),
                     (CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *)pCVar38,
                     (ulong)in_stack_fffffedc,(SKeyVal *)in_stack_fffffee0);
          break;
        case 2:
          pCVar38 = this + 0x2f4;
          pCVar14 = GetSelBlock<class_CGameCtnMediaBlockCameraPath>(this,pCVar37);
          CFastBufferKey<struct_CGameCtnMediaBlockCameraPath::SKeyVal>::SetVal
                    ((CFastBufferKey<struct_CGameCtnMediaBlockCameraPath::SKeyVal> *)
                     (pCVar14 + 0x24),
                     (CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *)pCVar38,
                     (ulong)in_stack_fffffedc,(SKeyVal *)in_stack_fffffee0);
          in_stack_fffffee0 = (CGameCtnMediaClipPlayer *)0x66a9c7;
          pCVar14 = GetSelBlock<class_CGameCtnMediaBlockCameraPath>(this,in_stack_fffffee4);
          *(undefined4 *)(pCVar14 + 0x38) = 1;
          break;
        case 4:
          pCVar38 = this + 0x340;
          pCVar22 = GetSelBlock<class_CGameCtnMediaBlockCameraEffectShake>(this,pCVar37);
          CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal>::SetVal
                    ((CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal> *)
                     (pCVar22 + 0x28),
                     (CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *)pCVar38,
                     (ulong)in_stack_fffffedc,(SKeyVal *)in_stack_fffffee0);
          break;
        case 5:
          pCVar11 = GetSelBlock<class_CGameCtnMediaBlockText>(this,in_stack_fffffedc);
          in_stack_fffffedc = this + 0x22c;
          CFastBufferKey<struct_CControlEffectSimi::SKeyVal>::SetVal
                    ((CFastBufferKey<struct_CControlEffectSimi::SKeyVal> *)
                     (*(int *)(pCVar11 + 0x38) + 0x18),
                     *(CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> **)(iVar7 + 0x2cc),
                     (ulong)in_stack_fffffedc,(SKeyVal *)in_stack_fffffee0);
          break;
        case 6:
          pCVar38 = this + 0x348;
          pCVar15 = GetSelBlock<class_CGameCtnMediaBlockTime>(this,pCVar37);
          CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal>::SetVal
                    ((CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal> *)
                     (pCVar15 + 0x24),
                     (CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *)pCVar38,
                     (ulong)in_stack_fffffedc,(SKeyVal *)in_stack_fffffee0);
          break;
        case 7:
          pCVar21 = GetSelBlock<class_CGameCtnMediaBlockTransitionFade>(this,in_stack_fffffedc);
          pSVar24 = CFastBuffer<struct_SFastCat>::operator[]
                              (pCVar21 + 0x28,
                               (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar37,
                               (ulong)in_stack_fffffee0);
          *(undefined4 *)(pSVar24 + 4) = *(undefined4 *)(this + 0x3ec);
          in_stack_fffffedc = pCVar37;
          break;
        case 9:
          pCVar38 = this + 0x350;
          pCVar16 = GetSelBlock<class_CGameCtnMediaBlockFxColors>(this,pCVar37);
          CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal>::SetVal
                    ((CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal> *)(pCVar16 + 0x34),
                     (CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *)pCVar38,
                     (ulong)in_stack_fffffedc,(SKeyVal *)in_stack_fffffee0);
          break;
        case 10:
          pCVar38 = this + 0x3c4;
          pCVar17 = GetSelBlock<class_CGameCtnMediaBlockFxBlurDepth>(this,pCVar37);
          CFastBufferKey<struct_CGameCtnMediaBlockFxBlurDepth::SKeyVal>::SetVal
                    ((CFastBufferKey<struct_CGameCtnMediaBlockFxBlurDepth::SKeyVal> *)
                     (pCVar17 + 0x34),
                     (CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *)pCVar38,
                     (ulong)in_stack_fffffedc,(SKeyVal *)in_stack_fffffee0);
          break;
        case 0xb:
          pCVar38 = this + 0x3d8;
          pCVar20 = GetSelBlock<class_CGameCtnMediaBlockSound>(this,pCVar37);
          CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SetVal
                    ((CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *)(pCVar20 + 0x24),
                     (CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *)pCVar38,
                     (ulong)in_stack_fffffedc,(SKeyVal *)in_stack_fffffee0);
          break;
        case 0xc:
          pCVar12 = GetSelBlock<class_CGameCtnMediaBlockImage>(this,in_stack_fffffedc);
          in_stack_fffffedc = this + 600;
          CFastBufferKey<struct_CControlEffectSimi::SKeyVal>::SetVal
                    ((CFastBufferKey<struct_CControlEffectSimi::SKeyVal> *)
                     (*(int *)(pCVar12 + 0x28) + 0x18),
                     *(CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> **)(iVar7 + 0x2cc),
                     (ulong)in_stack_fffffedc,(SKeyVal *)in_stack_fffffee0);
          break;
        case 0xe:
          pCVar38 = this + 0x3f0;
          pCVar19 = GetSelBlock<class_CGameCtnMediaBlockMusicEffect>(this,pCVar37);
          CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal>::SetVal
                    ((CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal> *)
                     (pCVar19 + 0x24),
                     (CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *)pCVar38,
                     (ulong)in_stack_fffffedc,(SKeyVal *)in_stack_fffffee0);
          break;
        case 0x10:
          pCVar38 = this + 0x3f8;
          pCVar23 = GetSelBlock<class_CGameCtnMediaBlock3dStereo>(this,pCVar37);
          CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal>::SetVal
                    ((CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal> *)
                     (pCVar23 + 0x24),
                     (CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *)pCVar38,
                     (ulong)in_stack_fffffedc,(SKeyVal *)in_stack_fffffee0);
          break;
        case 0x11:
          pCVar38 = this + 0x3d0;
          pCVar18 = GetSelBlock<class_CGameCtnMediaBlockFxBloom>(this,pCVar37);
          CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal>::SetVal
                    ((CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal> *)
                     (pCVar18 + 0x34),
                     (CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *)pCVar38,
                     (ulong)in_stack_fffffedc,(SKeyVal *)in_stack_fffffee0);
        }
      }
      *(undefined4 *)(this + 0xfc) = 0;
      iVar8 = CGameCtnMediaClipPlayer::IsPlaying
                        (*(CGameCtnMediaClipPlayer **)(this + 0xb4),
                         (COalAudioSound *)in_stack_fffffedc);
      if (iVar8 == 0) {
        CGameCtnMediaClipPlayer::UpdateTracksCmd
                  (*(CGameCtnMediaClipPlayer **)(this + 0xb4),in_stack_fffffee0);
      }
      if (*(int **)(this + 0x450) != (int *)0x0) {
        (**(code **)(**(int **)(this + 0x450) + 0x84))();
      }
    }
    (**(code **)(**(int **)(this + 0x288) + 0x88))();
    bVar27 = *(int *)(iVar7 + 0x2cc) == -1;
    if (((iVar5 != 0) || (bVar27)) || ((*(int *)(this + 400) != 5 && (*(int *)(this + 400) != 0xc)))
       ) {
      uVar26 = 0;
    }
    else {
      uVar26 = 1;
    }
    *(undefined4 *)(*(int *)(this + 0x228) + 0x38) = uVar26;
    (**(code **)(**(int **)(this + 0x28c) + 0x78))();
    if (((iVar5 != 0) || (bVar27)) || (*(int *)(this + 400) != 2)) {
      pSVar25 = (SGameCamVal *)0x0;
    }
    else {
      pSVar25 = (SGameCamVal *)0x1;
    }
    (**(code **)(**(int **)(this + 0x2f0) + 0x78))();
    SGameCamVal::SGameCamVal(auStack_c8,pSVar25);
    uStack00000018 = 2;
    iVar7 = (**(code **)(**(int **)(this + 0x288) + 0x8c))();
    if (iVar7 == 0) {
      if (*(int *)(*(int *)(*(int *)(this + 0xb4) + 0x18) + 0x28) != 0) {
        CGamePlayerCameraSet::UpdateAsync
                  (*(CGamePlayerCameraSet **)(*(int *)(*(int *)(this + 0xb4) + 0x18) + 0x28),
                   in_stack_fffffeb4);
      }
      this_00 = *(CGameCtnMediaClipPlayer **)(this + 0xb4);
      if (*(int *)(this_00 + 0xbc) == 0) {
        if ((*(int *)(*(int *)(this_00 + 0x18) + 0x28) == 0) ||
           (CGameControlCameraMaster::GetCamVal
                      (*(CGameControlCameraMaster **)
                        (*(int *)(*(int *)(this_00 + 0x18) + 0x28) + 0x18),
                       (GmCamFreeVal *)&fStack_ec,(GmCamVal *)in_stack_fffffeb4),
           extraout_EAX_03 == 0)) {
          CGameControlCamera::GetGameCamVal
                    (*(CGameControlCamera **)(this + 0x288),(CGameControlCamera *)&fStack_ec,
                     (SGameCamVal *)in_stack_fffffeb4);
        }
      }
      else {
        pSVar25 = CGameCtnMediaClipPlayer::GetCamValDefined
                            (this_00,(CGameCtnMediaClipPlayer *)in_stack_fffffeb4);
        SGameCamVal::operator=(&uStack_e8,(SNormalDec3N *)pSVar25,(GmVec3 *)in_stack_fffffeb8);
      }
      if (*(int *)(*(int *)(this + 0xb4) + 0x1c) != 0) {
        CGameControlCameraMaster::ApplyGlobalEffectsOn
                  (*(CGameControlCameraMaster **)(*(int *)(this + 0xb4) + 0x1c),
                   (CGameControlCameraMaster *)&uStack_e8,(GmCamVal *)in_stack_fffffeb8);
      }
      if (*(int **)(this + 0x120) != (int *)0x0) {
        (**(code **)(**(int **)(this + 0x120) + 0x8c))(&uStack_e8);
      }
      if (*(int *)(*(int *)(*(int *)(this + 0xb4) + 0x18) + 0x28) != 0) {
        (**(code **)(**(int **)(*(int *)(*(int *)(this + 0xb4) + 0x18) + 0x28) + 0x78))(&uStack_e8);
      }
    }
    else {
      CGameControlCamera::GetGameCamVal
                (*(CGameControlCamera **)(this + 0x288),(CGameControlCamera *)&fStack_ec,
                 (SGameCamVal *)in_stack_fffffeb4);
    }
    CGameCamera::SetGameCamVal
              (*(CGameCamera **)(*(int *)(*(int *)(this + 0x11c) + 0x14) + 0x24),
               (CGameCamera *)&uStack_e8,(SGameCamVal *)in_stack_fffffeb8);
    if (iVar5 == 0) {
      fVar29 = CGameCtnMediaClipPlayer::ClipTimeGet
                         (*(CGameCtnMediaClipPlayer **)(this + 0xb4),
                          (CGameCtnMediaClipPlayer *)pGVar2);
      if (*(int **)(this + 0x450) != (int *)0x0) {
        (**(code **)(**(int **)(this + 0x450) + 0x84))(fVar29,0,local_110);
      }
    }
    piVar1 = *(int **)(*(int *)(*(int *)(this + 0x11c) + 0x14) + 0x2c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x78))();
    }
    if (*(CGameSafeFrame **)(this + 0xa0) != (CGameSafeFrame *)0x0) {
      CGameSafeFrame::UpdateCameraFrustum
                (*(CGameSafeFrame **)(this + 0xa0),(CGameSafeFrame *)pGVar2);
    }
    uStack_4 = 0xffffffff;
    OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pGVar2);
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CGameCtnMediaTracker::UpdateControlsState_FrameBlockFxBlurDepth
// =================================================
void __thiscall
CGameCtnMediaTracker::UpdateControlsState_FrameBlockFxBlurDepth
          (CGameCtnMediaTracker *this,CGameCtnMediaTracker *param_1)
{
{
  CControlContainer *this_00;
  int iVar1;
  CMwId CVar2;
  SBlockEditInfo *pSVar3;
  undefined3 extraout_var;
  CPlugTree *pCVar4;
  code *pcVar5;
  void *this_01;
  void *this_02;
  void *this_03;
  CGameCtnMediaTracker *unaff_EDI;
  void *in_stack_00000008;
  undefined4 uStack00000010;
  CGameCtnMediaTracker *pCVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aae648;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar6 = this;
  pSVar3 = FindBlockEditInfoFromClassId
                     (this,(CGameCtnMediaTracker *)0x3081000,DAT_00cca150 ^ (uint)&stack0xffffffe0);
  if ((pSVar3 != (SBlockEditInfo *)0x0) &&
     (this_00 = *(CControlContainer **)(pSVar3 + 0xc), this_00 != (CControlContainer *)0x0)) {
    IsBlockingMode(this,unaff_EDI);
    CControlTools::Connect(this_01,(CCrystalEdge *)this_00);
    CControlTools::Connect(this_02,(CCrystalEdge *)this_00);
    iVar1 = *(int *)(this + 0x3c8);
    CControlTools::Connect(this_03,(CCrystalEdge *)this_00);
    CVar2 = CMwId::CreateFromLocalName((char *)&param_1);
    uStack00000010 = 0;
    pCVar4 = CControlContainer::GetChildFromId
                       (this_00,(CPlugTree *)CONCAT31(extraout_var,CVar2),(CMwId *)0x1);
    uStack00000010 = 0xffffffff;
    OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar6);
    if (pCVar4 != (CPlugTree *)0x0) {
      if (iVar1 == 0) {
        pcVar5 = *(code **)(*(int *)pCVar4 + 0x104);
      }
      else {
        pcVar5 = *(code **)(*(int *)pCVar4 + 0x100);
      }
      (*pcVar5)();
    }
  }
  ExceptionList = in_stack_00000008;
  return;
}
}

