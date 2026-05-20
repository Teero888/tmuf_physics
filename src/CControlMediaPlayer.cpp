// Class implementation: CControlMediaPlayer

// =================================================
// Function: CControlMediaPlayer::CControlMediaPlayer
// =================================================
void __thiscall
CControlMediaPlayer::CControlMediaPlayer(CControlMediaPlayer *this,CControlMediaPlayer *param_1)
{
{
  CMwId *unaff_EBX;
  CMwId *unaff_ESI;
  CMwId *unaff_EDI;
  undefined1 uStack00000008;
  undefined1 uStack0000000c;
  void *in_stack_00000010;
  undefined1 uStack00000014;
  CControlMediaPlayer *pCVar1;
  CMwId *pCVar2;
  undefined1 *puVar3;
  
  puVar3 = &LAB_00ac9494;
  pCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CControlFrame::CControlFrame
            ((CControlFrame *)this,(CControlFrame *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x160,unaff_EDI);
  CMwId::CMwId(this + 0x164,unaff_ESI);
  uStack00000008 = 2;
  CMwId::CMwId(this + 0x168,unaff_EBX);
  uStack0000000c = 3;
  CMwId::CMwId(this + 0x16c,(CMwId *)pCVar1);
  in_stack_00000010 = (void *)CONCAT31(in_stack_00000010._1_3_,4);
  CMwId::CMwId(this + 0x170,pCVar2);
  *(undefined4 *)(this + 0x174) = 0;
  *(undefined4 *)(this + 0x18c) = 0;
  *(undefined4 *)(this + 400) = 0;
  *(undefined4 *)(this + 0x1a4) = 0;
  *(undefined4 *)(this + 0x1a8) = 0;
  uStack00000014 = 10;
  *(undefined4 *)(this + 0x1a0) = 0;
  *(undefined4 *)(this + 0x198) = 0;
  *(undefined4 *)(this + 0x194) = 0;
  *(undefined4 *)(this + 0x188) = 1;
  *(undefined4 *)(this + 0x19c) = 1;
  CMwCmdContainer::AddFastCall
            ((CMwCmdContainer *)(this + 0x48),(CMwCmdContainer *)this,(CMwNod *)UpdateIsFinished,
             (_func___cdecl_void *)&DAT_0000000e,(ulong)puVar3);
  *(undefined4 *)(this + 0x180) = 1;
  *(undefined4 *)(this + 0x184) = 1;
  ExceptionList = in_stack_00000010;
  return;
}
}

// =================================================
// Function: CControlMediaPlayer::CreateMediaButton
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CControlMediaPlayer::CreateMediaButton(CControlMediaPlayer *this,CControlMediaPlayer *param_1)
{
{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  CControlButton *pCVar5;
  CControlButton *pCVar6;
  CMwNod *extraout_EAX;
  CMwNod *extraout_EAX_00;
  CMwNod *unaff_EDI;
  CMwNod *pCVar7;
  undefined4 uVar8;
  void *pvStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ac93d6;
  local_c = ExceptionList;
  pCVar5 = (CControlButton *)(DAT_00cca150 ^ (uint)&stack0xffffffc8);
  ExceptionList = &local_c;
  pCVar6 = operator_new(0x178);
  local_4 = 0;
  if (pCVar6 == (CControlButton *)0x0) {
    pCVar7 = (CMwNod *)0x0;
  }
  else {
    CControlButton::CControlButton(pCVar6,pCVar5);
    pCVar7 = extraout_EAX;
  }
  if (pCVar7 != *(CMwNod **)(this + 0x1a4)) {
    if (pCVar7 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar7,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x1a4) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1a4),unaff_EDI);
    }
    *(CMwNod **)(this + 0x1a4) = pCVar7;
  }
  (**(code **)(**(int **)(this + 0x1a4) + 0x4c))();
  *(undefined4 *)(*(int *)(this + 0x1a4) + 0x14c) = 1;
  *(uint *)(*(int *)(this + 0x1a4) + 0xfc) = *(uint *)(*(int *)(this + 0x1a4) + 0xfc) | 2;
  *(uint *)(*(int *)(this + 0x1a4) + 0xfc) = *(uint *)(*(int *)(this + 0x1a4) + 0xfc) & 0xfffff7ff;
  *(uint *)(*(int *)(this + 0x1a4) + 0xfc) = *(uint *)(*(int *)(this + 0x1a4) + 0xfc) & 0xfffffff7;
  iVar3 = *(int *)(this + 0x1a4);
  if (*(int *)(this + 0x118) == 0) {
    *(undefined4 *)(iVar3 + 0x10c) = *(undefined4 *)(this + 0x180);
    *(undefined4 *)(*(int *)(this + 0x1a4) + 0x108) = *(undefined4 *)(this + 0x184);
    (**(code **)(**(int **)(this + 0x1a4) + 0x1b8))(this + 0x178);
  }
  else {
    fVar1 = *(float *)(this + 0x178);
    fVar4 = (float)_DAT_00b313b8;
    fVar2 = *(float *)(this + 0x17c);
    *(undefined4 *)(iVar3 + 0x9c) = 0;
    *(undefined4 *)(iVar3 + 0x98) = 0;
    *(undefined4 *)(iVar3 + 0x94) = 0;
    *(float *)(iVar3 + 0xa0) = fVar1 * fVar4;
    *(float *)(iVar3 + 0xa4) = fVar4 * fVar2;
    *(undefined4 *)(iVar3 + 0xa8) = 0;
    *(undefined4 *)(*(int *)(this + 0x1a4) + 0x10c) = 3;
    *(undefined4 *)(*(int *)(this + 0x1a4) + 0x108) = 3;
  }
  if (*(int *)(this + 0x188) == 0) {
    *(undefined4 *)(*(int *)(this + 0x1a4) + 0x174) = *(undefined4 *)(this + 0x170);
  }
  else if (*(int *)(this + 0x188) == 1) {
    *(undefined4 *)(*(int *)(this + 0x1a4) + 0x174) = *(undefined4 *)(this + 0x16c);
  }
  uVar8 = 0;
  CControlBase::CStyleSheetElem<class_CControlStyle>::Set
            (*(CMwCmdScriptVarBool **)(this + 0x1a4) + 0x110,*(CMwCmdScriptVarBool **)(this + 0x1a4)
             ,*(int *)(this + 0x174));
  pCVar5 = *(CControlButton **)(this + 0x1a4);
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_10 = 0;
  (**(code **)(*(int *)this + 0x1f8))(pCVar5,&uStack_18,uVar8);
  pCVar6 = operator_new(0x178);
  local_c = (void *)0x1;
  if (pCVar6 == (CControlButton *)0x0) {
    pCVar7 = (CMwNod *)0x0;
  }
  else {
    CControlButton::CControlButton(pCVar6,pCVar5);
    pCVar7 = extraout_EAX_00;
  }
  local_c = (void *)0xffffffff;
  if (pCVar7 != *(CMwNod **)(this + 0x1a8)) {
    if (pCVar7 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar7,(CMwNod *)pCVar5);
    }
    if (*(CMwNod **)(this + 0x1a8) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1a8),(CMwNod *)pCVar5);
    }
    *(CMwNod **)(this + 0x1a8) = pCVar7;
  }
  (**(code **)(**(int **)(this + 0x1a8) + 0x4c))();
  *(undefined4 *)(*(int *)(this + 0x1a8) + 0x14c) = 1;
  *(uint *)(*(int *)(this + 0x1a8) + 0xfc) = *(uint *)(*(int *)(this + 0x1a8) + 0xfc) & 0xfffffffd;
  iVar3 = *(int *)(this + 0x1a8);
  *(undefined4 *)(iVar3 + 0x9c) = 0;
  *(undefined4 *)(iVar3 + 0x98) = 0;
  *(undefined4 *)(iVar3 + 0x94) = 0;
  uVar8 = _DAT_00b3cd40;
  *(undefined4 *)(iVar3 + 0xa0) = _DAT_00b3cd40;
  *(undefined4 *)(iVar3 + 0xa4) = uVar8;
  *(undefined4 *)(iVar3 + 0xa8) = 0;
  *(uint *)(*(int *)(this + 0x1a8) + 0xfc) = *(uint *)(*(int *)(this + 0x1a8) + 0xfc) & 0xfffff7ff;
  *(uint *)(*(int *)(this + 0x1a8) + 0xfc) = *(uint *)(*(int *)(this + 0x1a8) + 0xfc) & 0xfffffff7;
  if (*(int *)(this + 0x118) == 0) {
    *(undefined4 *)(*(int *)(this + 0x1a8) + 0x10c) = 1;
    *(undefined4 *)(*(int *)(this + 0x1a8) + 0x108) = 1;
  }
  else {
    *(undefined4 *)(*(int *)(this + 0x1a8) + 0x10c) = 3;
    *(undefined4 *)(*(int *)(this + 0x1a8) + 0x108) = 3;
  }
  *(undefined4 *)(*(int *)(this + 0x1a8) + 0x174) = *(undefined4 *)(this + 0x160);
  uVar8 = 0;
  CControlBase::CStyleSheetElem<class_CControlStyle>::Set
            (*(CMwCmdScriptVarBool **)(this + 0x1a8) + 0x110,*(CMwCmdScriptVarBool **)(this + 0x1a8)
             ,*(int *)(this + 0x174));
  (**(code **)(*(int *)this + 0x1f8))(*(undefined4 *)(this + 0x1a8),&stack0xffffffd0,uVar8);
  (**(code **)(**(int **)(this + 0x1a8) + 0x104))();
  ExceptionList = pvStack_20;
  return;
}
}

// =================================================
// Function: CControlMediaPlayer::MediaPlay
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CControlMediaPlayer::MediaPlay(CControlMediaPlayer *this,CControlMediaPlayer *param_1)
{
{
  int iVar1;
  EPlugVideoTimer unaff_ESI;
  int unaff_retaddr;
  
  if (*(int *)(this + 0x1a0) == 0) {
    *(undefined4 *)(this + 0x1a0) = 1;
    if (*(CAudioSound **)(this + 0x194) == (CAudioSound *)0x0) {
      if (*(int **)(this + 0x18c) != (int *)0x0) {
        iVar1 = (**(code **)(**(int **)(this + 0x18c) + 0xb8))();
        if (iVar1 != 0) {
          (**(code **)(**(int **)(this + 0x18c) + 0xb0))(1);
        }
        (**(code **)(**(int **)(this + 0x18c) + 0xac))(1,*(undefined4 *)(this + 0x19c),0xffffffff);
      }
    }
    else {
      CAudioSound::Play(*(CAudioSound **)(this + 0x194),_DAT_00b2c060,unaff_ESI,unaff_retaddr,
                        (ulong)param_1);
    }
  }
  if (*(int *)(this + 0x188) == 0) {
    if (*(int **)(this + 0x1a8) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0078e9f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(this + 0x1a8) + 0x104))();
      return;
    }
  }
  else if ((*(int *)(this + 0x188) == 1) && (*(int *)(this + 0x1a4) != 0)) {
    *(undefined4 *)(*(int *)(this + 0x1a4) + 0x174) = *(undefined4 *)(this + 0x168);
                    /* WARNING: Could not recover jumptable at 0x0078e9db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0x1a4) + 0x1a8))();
    return;
  }
  return;
}
}

// =================================================
// Function: CControlMediaPlayer::MediaStop
// =================================================
void __thiscall
CControlMediaPlayer::MediaStop(CControlMediaPlayer *this,CControlMediaPlayer *param_1)
{
{
  STmRaceLowFps *unaff_ESI;
  
  if (*(int *)(this + 0x1a0) != 0) {
    *(undefined4 *)(this + 0x1a0) = 0;
    if (*(CAudioSound **)(this + 0x194) == (CAudioSound *)0x0) {
      if (*(int **)(this + 0x18c) != (int *)0x0) {
        (**(code **)(**(int **)(this + 0x18c) + 0xb0))(0);
      }
    }
    else {
      CAudioSound::Stop(*(CAudioSound **)(this + 0x194),unaff_ESI);
    }
  }
  if ((*(int *)(this + 0x188) == 1) && (*(int *)(this + 0x1a4) != 0)) {
    *(undefined4 *)(*(int *)(this + 0x1a4) + 0x174) = *(undefined4 *)(this + 0x164);
                    /* WARNING: Could not recover jumptable at 0x0078ea6d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0x1a4) + 0x1a8))();
    return;
  }
  return;
}
}

// =================================================
// Function: CControlMediaPlayer::SetMediaData
// =================================================
void __thiscall
CControlMediaPlayer::SetMediaData
          (CControlMediaPlayer *this,CControlMediaPlayer *param_1,CSystemData *param_2)
{
{
  CSystemData *this_00;
  CSystemFids *extraout_EAX;
  SCasterCat *pSVar1;
  undefined *puVar2;
  CSystemFid *pCVar3;
  int unaff_EBP;
  CSystemFid *unaff_ESI;
  SStringParam *unaff_EDI;
  undefined *unaff_retaddr;
  undefined4 in_stack_0000000c;
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ac9548;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(this + 0x1a4) == 0) {
    CreateMediaButton(this,(CControlMediaPlayer *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  }
  this_00 = param_2;
  if (param_2 != (CSystemData *)0x0) {
    if (DAT_00d6c8c8 == (CMwNod *)0x0) {
      CFastStringInt::CFastStringInt(local_10,(CFastStringInt *)L"DefaultDummyMedia",unaff_EDI);
      pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(DAT_00d73300 + 0x20),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                          (ulong)unaff_ESI);
      unaff_ESI = (CSystemFid *)0x0;
      unaff_EDI = (SStringParam *)0x0;
      DAT_00d6c8c8 = (CMwNod *)
                     CSystemFids::FindOrAddFid
                               (*(CSystemFids **)(*(int *)pSVar1 + 0x34),extraout_EAX,
                                (CFastStringInt *)0x0,(ulong *)0x0,unaff_EBP);
      in_stack_0000000c = 0xffffffff;
      if (unaff_retaddr != PTR_DAT_00bbf7dc) {
        if ((unaff_retaddr[-1] & 0x80) == 0) {
          puVar2 = unaff_retaddr + -2;
        }
        else {
          puVar2 = unaff_retaddr + -4;
        }
        unaff_ESI = (CSystemFid *)0x78f1e0;
        operator_delete__(puVar2);
        local_4 = 0;
      }
    }
    param_2 = (CSystemData *)0x9020000;
    pCVar3 = CSystemData::GetFid(this_00,(CSystemData *)this,DAT_00d6c8c8,(CSystemFid *)&param_2,
                                 (ulong *)unaff_EDI);
    if ((pCVar3 != (CSystemFid *)0x0) && (pCVar3 != (CSystemFid *)DAT_00d6c8c8)) {
      SetMediaFileFid(this,(CControlMediaPlayer *)pCVar3,unaff_ESI);
    }
  }
  ExceptionList = puStack_8;
  return;
}
}

// =================================================
// Function: CControlMediaPlayer::SetMediaFileFid
// =================================================
void __thiscall
CControlMediaPlayer::SetMediaFileFid
          (CControlMediaPlayer *this,CControlMediaPlayer *param_1,CSystemFid *param_2)
{
{
  code *pcVar1;
  CControlMediaPlayer *pCVar2;
  int iVar3;
  SCasterCat *pSVar4;
  CPlugBitmap *this_00;
  CPlugBitmap *extraout_EAX;
  CMwCmdAffectParamBool *this_01;
  CFuncEnum *pCVar5;
  CFuncEnum *extraout_EAX_00;
  CPlugSoundVideo *this_02;
  CMwNod *extraout_EAX_01;
  CMwNod *extraout_EAX_02;
  CAudioSound *pCVar6;
  CMwNod *unaff_EBP;
  CMwNod *pCVar7;
  CAudioSound *unaff_ESI;
  CAudioPort *unaff_EDI;
  CFuncEnum *this_03;
  CMwNod *this_04;
  CMwNod *unaff_retaddr;
  CPlugSound *pCVar8;
  CControlMediaPlayer *pCVar9;
  CPlugBitmap *pCVar10;
  CAudioPort *pCVar11;
  CMwNod *pCStack_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ac94ec;
  local_c = ExceptionList;
  pCVar2 = (CControlMediaPlayer *)(DAT_00cca150 ^ (uint)&stack0xffffffd8);
  ExceptionList = &local_c;
  iVar3 = CSystemArchiveNod::LoadFromFid((CMwNod **)&param_1,(CSystemFid *)param_1,7);
  if (iVar3 == 0) {
    ExceptionList = local_c;
    return;
  }
  if (*(int *)(this + 0x1a4) == 0) {
    CreateMediaButton(this,pCVar2);
  }
  pCVar11 = *(CAudioPort **)(this + 0x194);
  if (pCVar11 != (CAudioPort *)0x0) {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(DAT_00d73300 + 0x20),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x10,(ulong)unaff_EDI);
    CAudioPort::RemoveSound(*(CAudioPort **)(*(int *)pSVar4 + 0x2c),pCVar11,unaff_ESI);
    *(undefined4 *)(this + 0x194) = 0;
    unaff_EDI = pCVar11;
  }
  pCVar10 = (CPlugBitmap *)0x9060000;
  iVar3 = (**(code **)(*(int *)param_2 + 0x10))();
  pCVar2 = param_1;
  if (iVar3 == 0) {
    pCVar9 = (CControlMediaPlayer *)0x9030000;
    iVar3 = (**(code **)(*(int *)param_1 + 0x10))();
    if (iVar3 == 0) goto LAB_0078efd7;
    if (unaff_retaddr != *(CMwNod **)(this + 400)) {
      if (unaff_retaddr != (CMwNod *)0x0) {
        CMwNod::MwAddRef(unaff_retaddr,(CMwNod *)pCVar9);
      }
      if (*(CMwNod **)(this + 400) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 400),(CMwNod *)pCVar9);
      }
      *(CMwNod **)(this + 400) = unaff_retaddr;
    }
    puStack_8 = (undefined1 *)0x4;
    pCVar8 = operator_new(0x70);
    puStack_8._0_1_ = 5;
    if (pCVar8 == (CPlugSound *)0x0) {
      pCVar7 = (CMwNod *)0x0;
    }
    else {
      CPlugSound::CPlugSound(pCVar8,(CPlugSound *)pCVar9);
      pCVar7 = extraout_EAX_02;
    }
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,4);
    this_04 = (CMwNod *)0x0;
    pCStack_18 = unaff_retaddr;
    if (pCVar7 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar7,(CMwNod *)pCVar9);
      this_04 = pCVar7;
      pCStack_18 = pCVar7;
    }
    if (pCStack_18 != *(CMwNod **)(this_04 + 0x18)) {
      if (pCStack_18 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCStack_18,(CMwNod *)pCVar9);
      }
      if (*(CMwNod **)(this_04 + 0x18) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this_04 + 0x18),(CMwNod *)pCVar9);
      }
      *(CMwNod **)(this_04 + 0x18) = pCStack_18;
    }
    *(undefined4 *)(this_04 + 0x24) = *(undefined4 *)(this + 0x19c);
    *(undefined4 *)(this_04 + 0x28) = 1;
    *(undefined4 *)(this_04 + 0x1c) = 0;
    *(undefined4 *)(this_04 + 0x20) = 0x3f800000;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(DAT_00d73300 + 0x20),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x10,(ulong)pCVar9);
    pCVar8 = (CPlugSound *)0x0;
  }
  else {
    this_01 = *(CMwCmdAffectParamBool **)(param_1 + 0x44);
    this_03 = (CFuncEnum *)0x0;
    if (this_01 == (CMwCmdAffectParamBool *)0x0) {
      this_00 = operator_new(0x78);
      uStack_4 = 0;
      if (this_00 == (CPlugBitmap *)0x0) {
        this_01 = (CMwCmdAffectParamBool *)0x0;
      }
      else {
        CPlugBitmap::CPlugBitmap(this_00,pCVar10);
        this_01 = (CMwCmdAffectParamBool *)extraout_EAX;
      }
      uStack_4 = 0xffffffff;
      CPlugBitmap::SetImage
                ((CPlugBitmap *)this_01,(CVisionTexConverter *)pCVar2,(CPlugFileImg *)pCVar10);
    }
    pCVar5 = operator_new(0x50);
    uStack_4 = 1;
    if (pCVar5 != (CFuncEnum *)0x0) {
      CFuncEnum::CFuncEnum(pCVar5,(CFuncEnum *)pCVar10);
      this_03 = extraout_EAX_00;
    }
    uStack_4 = 0xffffffff;
    CControlButton::InitFuncEnum(this_03);
    pCVar5 = (CFuncEnum *)0x0;
    CFuncEnum::SetValue(this_03,this_01);
    CControlButton::SetIcons(*(CControlButton **)(this + 0x1a4),(CControlButton *)this_03,pCVar5);
    *(undefined4 *)(*(int *)(this + 0x1a4) + 0x174) = 0xffffffff;
    if (pCVar2 != *(CControlMediaPlayer **)(this + 0x18c)) {
      CMwNod::MwAddRef((CMwNod *)pCVar2,(CMwNod *)pCVar10);
      if (*(CMwNod **)(this + 0x18c) != (CMwNod *)0x0) {
        pCVar10 = (CPlugBitmap *)0x78ede7;
        CMwNod::MwRelease(*(CMwNod **)(this + 0x18c),(CMwNod *)unaff_EDI);
      }
      *(CControlMediaPlayer **)(this + 0x18c) = pCVar2;
    }
    pcVar1 = *(code **)(*(int *)pCVar2 + 0xb0);
    *(undefined4 *)(pCVar2 + 0x3c) = *(undefined4 *)(this + 0x19c);
    pCVar9 = (CControlMediaPlayer *)0x0;
    (*pcVar1)();
    iVar3 = (**(code **)(**(int **)(this + 0x18c) + 0xa4))();
    if (iVar3 == 0) goto LAB_0078efd7;
    puStack_8 = (undefined1 *)0x2;
    this_02 = operator_new(0x78);
    puStack_8._0_1_ = 3;
    if (this_02 == (CPlugSoundVideo *)0x0) {
      pCVar7 = (CMwNod *)0x0;
    }
    else {
      CPlugSoundVideo::CPlugSoundVideo(this_02,(CPlugSoundVideo *)pCVar9);
      pCVar7 = extraout_EAX_01;
    }
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
    this_04 = (CMwNod *)0x0;
    if (pCVar7 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar7,(CMwNod *)pCVar9);
      this_04 = pCVar7;
    }
    if (pCVar2 != *(CControlMediaPlayer **)(this_04 + 0x70)) {
      CMwNod::MwAddRef((CMwNod *)pCVar2,(CMwNod *)pCVar9);
      if (*(CMwNod **)(this_04 + 0x70) != (CMwNod *)0x0) {
        pCVar9 = (CControlMediaPlayer *)0x78ee7c;
        CMwNod::MwRelease(*(CMwNod **)(this_04 + 0x70),(CMwNod *)0x78ee7c);
      }
      *(CControlMediaPlayer **)(this_04 + 0x70) = pCVar2;
    }
    *(undefined4 *)(this_04 + 0x24) = *(undefined4 *)(this + 0x19c);
    *(undefined4 *)(this_04 + 0x28) = 1;
    *(undefined4 *)(this_04 + 0x20) = 0x3f800000;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(DAT_00d73300 + 0x20),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x10,(ulong)pCVar9);
    pCVar8 = (CPlugSound *)0x1;
  }
  pCVar9 = (CControlMediaPlayer *)0x0;
  pCVar6 = CAudioPort::AddSound
                     (*(CAudioPort **)(*(int *)pSVar4 + 0x2c),(CAudioPort *)this_04,pCVar8,0,
                      (int)pCVar10);
  *(CAudioSound **)(this + 0x194) = pCVar6;
  if (pCVar6 != (CAudioSound *)0x0) {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(DAT_00d73300 + 0x20),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x10,(ulong)unaff_EDI);
    pCVar9 = (CControlMediaPlayer *)0x78efc8;
    CAudioPort::AutoBalance_Add
              (*(CAudioPort **)(*(int *)pSVar4 + 0x2c),(CAudioPort *)pCVar6,
               (CAudioSound *)0xffffffff,(ulong)unaff_ESI);
  }
  param_2 = (CSystemFid *)0xffffffff;
  CMwNod::MwRelease(this_04,unaff_EBP);
LAB_0078efd7:
  *(uint *)(*(int *)(this + 0x1a4) + 0xfc) = *(uint *)(*(int *)(this + 0x1a4) + 0xfc) & 0xfffffffd;
  (**(code **)(**(int **)(this + 0x1a4) + 0x1a8))();
  if (*(int *)(this + 0x198) == 0) {
    if ((*(int *)(this + 0x188) == 0) && (*(int **)(this + 0x1a8) != (int *)0x0)) {
      (**(code **)(**(int **)(this + 0x1a8) + 0x100))();
    }
    MediaStop(this,pCVar9);
  }
  else {
    MediaPlay(this,pCVar9);
  }
  (**(code **)(*(int *)this + 0x1a8))();
  ExceptionList = local_c;
  return;
}
}

