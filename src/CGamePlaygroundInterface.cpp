// Class implementation: CGamePlaygroundInterface

// =================================================
// Function: CGamePlaygroundInterface::ChatIsAllowed
// =================================================
int __thiscall
CGamePlaygroundInterface::ChatIsAllowed
          (CGamePlaygroundInterface *this,CGamePlaygroundInterface *param_1)
{
{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)this + 0x94))();
  iVar1 = CGameApp::Profile_IsChatEnabled(*(CGameApp **)(iVar1 + 0x18),(CGameApp *)param_1);
  return iVar1;
}
}

// =================================================
// Function: CGamePlaygroundInterface::HideMusicInfo
// =================================================
void __thiscall
CGamePlaygroundInterface::HideMusicInfo
          (CGamePlaygroundInterface *this,CGamePlaygroundInterface *param_1)
{
{
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x2c),0);
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  return;
}
}

// =================================================
// Function: CGamePlaygroundInterface::SetAvatarMessage
// =================================================
void __thiscall
CGamePlaygroundInterface::SetAvatarMessage
          (CGamePlaygroundInterface *this,CGamePlaygroundInterface *param_1,CGamePlayerInfo *param_2
          ,CFastStringInt *param_3,EAvatarVariant param_4)
{
{
  int iVar1;
  ulong *puVar2;
  CFastStringInt *unaff_EBX;
  EAvatarVariant unaff_ESI;
  CGamePlayerInfo *unaff_EDI;
  
  if ((param_1 != (CGamePlaygroundInterface *)0x0) || (*(int *)param_2 != 0)) {
    iVar1 = (**(code **)(*(int *)this + 0x98))();
    if ((*(byte *)(iVar1 + 0x80) & 1) != 0) {
      iVar1 = (**(code **)(*(int *)this + 0x94))();
      iVar1 = CGameApp::Profile_IsAvatarsEnabled(*(CGameApp **)(iVar1 + 0x18),(CGameApp *)param_3);
      CGameControlPlayerAvatar::Display
                (this + 0x4c,(CGameControlPlayerAvatar *)(-(uint)(iVar1 != 0) & (uint)param_1),
                 unaff_EDI,unaff_ESI);
      if (*(CControlLabel **)(this + 0x68) != (CControlLabel *)0x0) {
        CControlLabel::SetLabel
                  (*(CControlLabel **)(this + 0x68),(CControlButton *)param_2,unaff_EBX);
        unaff_EBX = (CFastStringInt *)0x5e1be7;
        (**(code **)(**(int **)(this + 0x68) + 0x1a8))();
      }
      CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x68),1);
      puVar2 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),(CMwTimerAdapter *)unaff_EBX);
      *(ulong *)(this + 0x98) = *puVar2;
      return;
    }
  }
  CGameControlPlayerAvatar::Display
            (this + 0x4c,(CGameControlPlayerAvatar *)0x0,(CGamePlayerInfo *)0x0,
             (EAvatarVariant)unaff_EDI);
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x68),0);
  *(undefined4 *)(this + 0x98) = 0;
  return;
}
}

// =================================================
// Function: CGamePlaygroundInterface::UpdateAsync
// =================================================
void __thiscall
CGamePlaygroundInterface::UpdateAsync(CGamePlaygroundInterface *this,CInputPortDx8 *param_1)
{
{
  CGamePlaygroundInterface *unaff_ESI;
  CGamePlaygroundInterface *unaff_retaddr;
  CGamePlaygroundInterface *in_stack_0000000c;
  
  UpdateAvatarMessage(this,unaff_ESI);
  UpdateMusicInfo(this,unaff_retaddr);
  UpdateManiaLinkPage(this,in_stack_0000000c);
  return;
}
}

// =================================================
// Function: CGamePlaygroundInterface::UpdateAvatarMessage
// =================================================
void __thiscall
CGamePlaygroundInterface::UpdateAvatarMessage
          (CGamePlaygroundInterface *this,CGamePlaygroundInterface *param_1)
{
{
  CGamePlaygroundInterface *this_00;
  CGamePlaygroundInterface *this_01;
  uint uVar1;
  uint uVar2;
  bool bVar3;
  ulong *puVar4;
  ulong uVar5;
  int iVar6;
  GmVec3 *pGVar7;
  CFastBufferWheel<class_GmVec3> *unaff_EBX;
  SShaderCustom *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CMwTimerAdapter *unaff_EDI;
  GmVec3 *unaff_retaddr;
  CMwNod *in_stack_00000008;
  CMwNod *in_stack_0000000c;
  CFastBufferWheel<float> *in_stack_00000020;
  float *in_stack_00000024;
  
  bVar3 = false;
  if (*(int *)(this + 0x98) != 0) {
    puVar4 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_EDI);
    uVar1 = *puVar4;
    uVar2 = *(uint *)(this + 0x98);
    if (uVar2 < uVar1) {
      if ((*(uint *)(this + 0x90) < uVar1 - uVar2) &&
         (uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x6c,unaff_ESI), uVar5 != 0)) {
        bVar3 = true;
      }
      if ((uVar2 < uVar1) && (*(uint *)(this + 0x94) < uVar1 - uVar2)) {
        SetAvatarMessage(this,(CGamePlaygroundInterface *)0x0,(CGamePlayerInfo *)&DAT_00d71d58,
                         (CFastStringInt *)0x0,(EAvatarVariant)unaff_EBP);
        goto LAB_005e21db;
      }
    }
    if (!bVar3) {
      return;
    }
  }
LAB_005e21db:
  this_00 = this + 0x6c;
  iVar6 = CFastBuffer<class_CAudioSound*>::IsEmpty(this_00,unaff_EBP);
  if (iVar6 != 0) {
    return;
  }
  pGVar7 = CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::Tail
                     (this_00,unaff_EBX);
  this_01 = this + 0x80;
  SAvatarMessage::operator=(this_01,(SNormalDec3N *)pGVar7,unaff_retaddr);
  SetAvatarMessage(this,*(CGamePlaygroundInterface **)this_01,(CGamePlayerInfo *)(this + 0x88),
                   *(CFastStringInt **)(this + 0x84),(EAvatarVariant)param_1);
  if (*(CMwNod **)this_01 != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)this_01,in_stack_00000008);
    *(undefined4 *)this_01 = 0;
  }
  if (*(CMwNod **)pGVar7 != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)pGVar7,in_stack_0000000c);
    *(undefined4 *)pGVar7 = 0;
  }
  CFastBufferWheel<class_GmVec2>::Pull(this_00,in_stack_00000020,in_stack_00000024);
  return;
}
}

// =================================================
// Function: CGamePlaygroundInterface::UpdateManiaLinkPage
// =================================================
void __thiscall
CGamePlaygroundInterface::UpdateManiaLinkPage
          (CGamePlaygroundInterface *this,CGamePlaygroundInterface *param_1)
{
{
  int iVar1;
  int *piVar2;
  CFastBuffer<class_CCrystalFace*> *pCVar3;
  int iVar4;
  ulong uVar5;
  SCasterCat *pSVar6;
  CGameManialinkPage *this_00;
  code *pcVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  void *this_01;
  SBuildPageParams *unaff_EDI;
  SBuildPageParams *pSVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  int iStack_64;
  int iStack_60;
  undefined1 auStack_5c [8];
  EErrorCode EStack_54;
  undefined1 auStack_50 [4];
  SBuildPageParams aSStack_4c [8];
  undefined4 uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_38;
  code *pcStack_34;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aa21b8;
  local_c = ExceptionList;
  pCVar3 = (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffff88);
  ExceptionList = &local_c;
  iVar4 = (**(code **)(*(int *)this + 0x98))();
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (((iVar4 != 0) && (*(int *)(this + 0x48) != 0)) && (*(int *)(this + 0x44) != 0)) {
    this_01 = (void *)(iVar4 + 0x74);
    iStack_64 = 0;
    uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount(this_01,pCVar3);
    if (uVar5 != 0) {
      do {
        pSVar9 = (SBuildPageParams *)0x5e2d48;
        pCVar10 = pCVar8;
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_01,pCVar8,(ulong)unaff_EDI);
        iVar1 = *(int *)pSVar6;
        EStack_54 = 0;
        if (*(int *)(iVar1 + 0x28) == 0) {
LAB_005e2e42:
          if (*(CControlFrame **)(*(int *)(*(CGameManialinkPage **)(iVar1 + 0x14) + 0x2c) + 0x6c) !=
              *(CControlFrame **)(this + 0x44)) {
            CGameManialink::AddPageToContainer
                      (*(CGameManialinkPage **)(iVar1 + 0x14),*(CControlFrame **)(this + 0x44),1.0);
          }
        }
        else {
          CGameManialink::SBuildPageParams::SBuildPageParams(auStack_50,(SBuildPageParams *)pCVar10)
          ;
          uStack_44 = *(undefined4 *)(iVar1 + 0x28);
          uStack_40 = *(undefined4 *)(this + 0x48);
          uStack_28 = 1;
          uStack_24 = 1;
          uStack_20 = 1;
          unaff_EDI = aSStack_4c;
          pcStack_34 = CGameNetwork::ManialinkPage_SetAnswer;
          pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x5e2dae;
          iStack_3c = iVar4;
          iStack_38 = iVar4;
          this_00 = CGameManialink::BuildPage(unaff_EDI,&EStack_54);
          if (this_00 != *(CGameManialinkPage **)(iVar1 + 0x14)) {
            if (this_00 != (CGameManialinkPage *)0x0) {
              CMwNod::MwAddRef((CMwNod *)this_00,(CMwNod *)pSVar9);
            }
            if (*(CMwNod **)(iVar1 + 0x14) != (CMwNod *)0x0) {
              CMwNod::MwRelease(*(CMwNod **)(iVar1 + 0x14),(CMwNod *)pSVar9);
            }
            *(CGameManialinkPage **)(iVar1 + 0x14) = this_00;
          }
          CGameManialink::AddPageToContainer
                    (*(CGameManialinkPage **)(iVar1 + 0x14),*(CControlFrame **)(this + 0x44),1.0);
          *(undefined4 *)(iVar1 + 0x28) = 0;
          if (*(CMwNod **)(iVar1 + 0x2c) != (CMwNod *)0x0) {
            CMwNod::MwRelease(*(CMwNod **)(iVar1 + 0x2c),(CMwNod *)pSVar9);
            *(undefined4 *)(iVar1 + 0x2c) = 0;
          }
          puStack_8 = (undefined1 *)0xffffffff;
          CGameManialink::SBuildPageParams::~SBuildPageParams(auStack_5c,pSVar9);
          if (iStack_60 == 0) {
            iVar4 = 1;
            goto LAB_005e2e42;
          }
          CFastBufferRef<class_CGameMobil>::ReplaceByLastAt
                    ((void *)0x75,(CFastBufferRef<class_CGameMobil> *)pCVar8,1,(ulong)pCVar10);
          pCVar8 = pCVar8 + -1;
          iVar4 = iStack_64;
        }
        this_01 = (void *)(iVar4 + 0x74);
        pCVar8 = pCVar8 + 1;
        pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                  CFastBuffer<class_CCrystalFace*>::GetCount
                            (this_01,(CFastBuffer<class_CCrystalFace*> *)pCVar10);
      } while (pCVar8 < pCVar10);
      if (iStack_60 != 0) {
        (**(code **)(**(int **)(this + 0x44) + 0x1a8))();
      }
    }
    piVar2 = *(int **)(this + 0x44);
    uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (this_01,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
    if (uVar5 == 0) {
      pcVar7 = *(code **)(*piVar2 + 0x104);
    }
    else {
      pcVar7 = *(code **)(*piVar2 + 0x100);
    }
    (*pcVar7)();
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CGamePlaygroundInterface::UpdateMusicInfo
// =================================================
void __thiscall
CGamePlaygroundInterface::UpdateMusicInfo
          (CGamePlaygroundInterface *this,CGamePlaygroundInterface *param_1)
{
{
  CMwId *pCVar1;
  CPlugAudio *this_00;
  CPlugAudio *unaff_ESI;
  CGamePlaygroundInterface *in_stack_00000008;
  
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar1 = CPlugAudio::MwGetId(this_00,unaff_ESI);
  if ((*(int *)(this + 0x40) != -1) && (10000 < (uint)(*(int *)pCVar1 - *(int *)(this + 0x40)))) {
    HideMusicInfo(this,in_stack_00000008);
    return;
  }
  return;
}
}

