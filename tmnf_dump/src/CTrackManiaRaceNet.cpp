// Class implementation: CTrackManiaRaceNet

// =================================================
// Function: CTrackManiaRaceNet::EndRunScoresVisible
// =================================================
int __thiscall
CTrackManiaRaceNet::EndRunScoresVisible(CTrackManiaRaceNet *this,CTrackManiaRaceNet *param_1)
{
{
  uint uVar1;
  CMwId *pCVar2;
  int iVar3;
  uint uVar4;
  CPlugAudio *this_00;
  CPlugAudio *unaff_EDI;
  
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar2 = CPlugAudio::MwGetId(this_00,unaff_EDI);
  uVar1 = *(uint *)pCVar2;
  iVar3 = (**(code **)(*(int *)this + 0x10))(0x24045000);
  if (iVar3 != 0) {
    iVar3 = *(int *)(this + 600);
    if (((iVar3 != 0) && (iVar3 + 3000U < uVar1)) && (uVar1 < iVar3 + 8000U)) {
      uVar4 = (**(code **)(*(int *)this + 0x1a8))();
      if (uVar1 < uVar4) {
        return 1;
      }
    }
    return 0;
  }
  return 0;
}
}

// =================================================
// Function: CTrackManiaRaceNet::NotifyNewTime
// =================================================
void __thiscall
CTrackManiaRaceNet::NotifyNewTime
          (CTrackManiaRaceNet *this,CTrackManiaRaceNet *param_1,ulong param_2,ulong param_3,
          uchar param_4)
{
{
  CGameNetwork *this_00;
  undefined3 in_stack_00000011;
  CNetConnectedClient *in_stack_ffffff28;
  CNetNod *pCVar1;
  CTrackManiaNetForm *pCVar2;
  CTrackManiaNetForm local_bc [68];
  undefined4 local_78;
  ulong local_74;
  CTrackManiaRaceNet *local_70;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a8c02b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(this + 0x330) == 0) {
    if (param_1 != (CTrackManiaRaceNet *)0x0) {
      RaceInputsSendToServer(this,(CTrackManiaRaceNet *)0x1,DAT_00cca150 ^ (uint)&stack0xffffff38);
    }
    CTrackManiaNetForm::CTrackManiaNetForm(local_bc,(CTrackManiaNetForm *)0x0);
    local_78 = *(undefined4 *)(this + 0x5c0);
    local_74 = param_3;
    local_70 = param_1;
    pCVar2 = local_bc;
    pCVar1 = (CNetNod *)0x4b6462;
    this_00 = (CGameNetwork *)(**(code **)(**(int **)(this + 0x18) + 0x118))(pCVar2,_param_4);
    CGameNetwork::Send(this_00,in_stack_ffffff28,pCVar1);
    puStack_8 = (undefined1 *)0xffffffff;
    CTrackManiaNetForm::~CTrackManiaNetForm((CTrackManiaNetForm *)&stack0xffffff3c,pCVar2);
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CTrackManiaRaceNet::RaceInputsSendToServer
// =================================================
void __thiscall
CTrackManiaRaceNet::RaceInputsSendToServer
          (CTrackManiaRaceNet *this,CTrackManiaRaceNet *param_1,int param_2)
{
{
  int iVar1;
  CGamePlayerInfo *pCVar2;
  ulong uVar3;
  int iVar4;
  CGamePlayer *pCVar5;
  uint uVar6;
  CGameNetwork *this_00;
  CGameNetFormAdmin *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CClassicBufferMemory *unaff_ESI;
  CGameRace *unaff_EDI;
  int unaff_retaddr;
  CClassicBufferMemory *in_stack_fffffff4;
  
  if ((*(int *)(this + 0x330) == 0) &&
     ((pCVar2 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,unaff_EDI), iVar1 = param_2,
      param_2 != 0 ||
      (uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar2 + 0x350,unaff_EBP), uVar3 != 0))))
  {
    if (*(int *)(this + 0x5b8) != 0) {
      CClassicBufferMemory::Empty((CClassicBufferMemory *)(*(int *)(this + 0x5b4) + 0x24),unaff_ESI)
      ;
      *(undefined4 *)(this + 0x5bc) = 0;
    }
    iVar4 = (**(code **)(*(int *)(*(int *)(this + 0x5b4) + 0x24) + 0x14))();
    if ((iVar4 == 0) || (*(int *)(this + 0x5b8) != 0)) {
      pCVar5 = CGameRace::GetLocalPlayer((CGameRace *)this,(CGameRace *)unaff_ESI);
      *(CGamePlayer *)(*(int *)(this + 0x5b4) + 0x44) = pCVar5[0x2c];
      *(bool *)(*(int *)(this + 0x5b4) + 0x45) = *(int *)(this + 0x5b8) != 0;
      if (*(int *)(this + 0x5b8) != 0) {
        *(undefined4 *)(*(int *)(this + 0x5b4) + 0x48) = *(undefined4 *)(pCVar2 + 0x394);
      }
    }
    *(undefined4 *)(this + 0x5b8) = 0;
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (pCVar2 + 0x350,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
    uVar6 = *(uint *)(this + 0x5bc);
    while (uVar6 < uVar3) {
      uVar6 = (*(int *)(pCVar2 + 0x35c) - *(int *)(this + 0x5bc)) + -1 + uVar3;
      if (*(uint *)(pCVar2 + 0x358) <= uVar6) {
        uVar6 = uVar6 - *(uint *)(pCVar2 + 0x358);
      }
      param_1 = *(CTrackManiaRaceNet **)(*(int *)(pCVar2 + 0x354) + uVar6 * 8);
      param_2 = *(int *)(*(int *)(pCVar2 + 0x354) + 4 + uVar6 * 8);
      (**(code **)(*(int *)(*(int *)(this + 0x5b4) + 0x24) + 8))(&param_1,8);
      *(int *)(this + 0x5bc) = *(int *)(this + 0x5bc) + 1;
      if ((iVar1 == 0) &&
         (uVar6 = (**(code **)(*(int *)(*(int *)(this + 0x5b4) + 0x24) + 0x14))(), 1000 < uVar6))
      goto LAB_004b5b5e;
      uVar6 = *(uint *)(this + 0x5bc);
    }
    if (iVar1 != 0) {
LAB_004b5b5e:
      *(undefined4 *)(*(int *)(this + 0x5b4) + 0x4c) = *(undefined4 *)(unaff_retaddr + 0x398);
      this_00 = (CGameNetwork *)(**(code **)(**(int **)(this + 0x18) + 0x118))();
      CGameNetwork::SendToServer(this_00,*(CGameNetwork **)(this + 0x5b4),unaff_EBX);
      CClassicBufferMemory::Empty
                ((CClassicBufferMemory *)(*(int *)(this + 0x5b4) + 0x24),in_stack_fffffff4);
    }
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRaceNet::SpectatorCameraChange
// =================================================
void __thiscall
CTrackManiaRaceNet::SpectatorCameraChange(CTrackManiaRaceNet *this,CTrackManiaRaceNet *param_1)
{
{
  CFastString *this_00;
  code *pcVar1;
  int extraout_EAX;
  CGameNetPlayerInfo *pCVar2;
  int iVar3;
  CPlugAudio *this_01;
  SCasterCat *pSVar4;
  ulong uVar5;
  int iVar6;
  undefined4 uVar7;
  CGameControlCamera *pCVar8;
  CGamePlayerInfo *pCVar9;
  CGamePlayer *pCVar10;
  CTrackManiaRaceNet *pCVar11;
  CGamePlayerInfo CVar12;
  CGamePlayerCameraSet *unaff_EBX;
  ulong unaff_EBP;
  CPlugAudio *unaff_ESI;
  CFastString *unaff_EDI;
  CGameRace *pCVar13;
  bool bVar14;
  CGameRace *pCVar15;
  CGameRace *in_stack_00000008;
  CGameRace *in_stack_0000000c;
  CGameRace *in_stack_00000010;
  int in_stack_00000018;
  CPlugVertexStream *in_stack_00000038;
  int in_stack_0000003c;
  CGamePlayerCameraSet *in_stack_fffffff0;
  CGamePlayerCameraSet *pCVar16;
  CGameRace *pCVar17;
  CGameRace *in_stack_fffffff8;
  ulong in_stack_fffffffc;
  
  if ((DAT_00d693b0 != 0xff) && (DAT_00d693b0 != *(int *)(this + 0x6c))) {
    (**(code **)(*(int *)this + 0xd4))(DAT_00d693b0);
  }
  if (DAT_00d693e8 == 0) {
    (**(code **)(*(int *)this + 0xd8))(1);
    *(undefined4 *)(this + 0x7c) = 0;
  }
  else if ((((*(int *)(this + 0x7c) == 0) ||
            (this_00 = (CFastString *)(*(int *)(this + 0x7c) + 0x28),
            in_stack_fffffff8 = DAT_00d693ec, in_stack_fffffffc = DAT_00d693e8,
            DAT_00d693e8 != *(ulong *)this_00)) ||
           (CFastString::Compare
                      (this_00,(SParam_Fids *)&stack0xfffffff8,(SParam *)0x0,(int *)unaff_EDI,
                       (int *)unaff_ESI), extraout_EAX != 0)) &&
          ((pCVar2 = CGameNetwork::FindPlayerInfoFromLogin
                               (*(CGameNetwork **)(*(int *)(this + 0x18) + 300),
                                (CGameNetwork *)&DAT_00d693e8,unaff_EDI),
           pCVar2 != (CGameNetPlayerInfo *)0x0 &&
           (iVar3 = (**(code **)(*(int *)this + 0xe4))(pCVar2), iVar3 != 0)))) {
    pcVar1 = *(code **)(*(int *)this + 0xd8);
    *(CGameNetPlayerInfo **)(this + 0x7c) = pCVar2;
    (*pcVar1)(0);
  }
  pCVar13 = *(CGameRace **)(this + 0x9c);
  if (pCVar13 != (CGameRace *)0x0) {
    *(undefined4 *)(this + 0x98) = 0;
  }
  this_01 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_01 == (CPlugAudio *)0x0) {
    this_01 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar17 = pCVar13;
  CPlugAudio::MwGetId(this_01,unaff_ESI);
  *(undefined4 *)(this + 0x9c) = 0;
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x24,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBP);
  iVar3 = *(int *)pSVar4;
  iVar6 = *(int *)(this + 0x6c);
  param_1 = *(CTrackManiaRaceNet **)(iVar3 + 0x24);
  pCVar15 = *(CGameRace **)(this + 0x98);
  if (*(int *)(this + 0x74) == iVar6) {
    if (iVar6 == 0) {
      iVar6 = CGameRace::MediaClipIsPlaying((CGameRace *)this,(CGameRace *)unaff_EBX);
      if (iVar6 == 0) {
        uVar5 = CGamePlayerCameraSet::CamGetCur
                          (*(CGamePlayerCameraSet **)(iVar3 + 0x20),in_stack_fffffff0);
        bVar14 = uVar5 == *(ulong *)(param_1 + 0x3c);
        goto LAB_004b8e13;
      }
    }
    else {
      if (iVar6 == 1) {
        uVar5 = CGamePlayerCameraSet::CamGetCur(*(CGamePlayerCameraSet **)(iVar3 + 0x20),unaff_EBX);
        bVar14 = uVar5 == *(ulong *)(param_1 + 0x2c);
      }
      else {
        if (iVar6 != 2) goto LAB_004b8e1d;
        uVar5 = CGamePlayerCameraSet::CamGetCur(*(CGamePlayerCameraSet **)(iVar3 + 0x20),unaff_EBX);
        bVar14 = uVar5 == *(ulong *)(param_1 + 0x38);
      }
LAB_004b8e13:
      if (!bVar14) goto LAB_004b8e15;
    }
  }
  else {
LAB_004b8e15:
    param_1 = (CTrackManiaRaceNet *)0x1;
  }
LAB_004b8e1d:
  if (*(int *)(this + 0x98) == 0) {
    pCVar13 = (CGameRace *)0x1;
  }
  iVar6 = *(int *)(this + 0x70);
  if ((*(int *)(this + 0x78) != iVar6) && (pCVar13 = (CGameRace *)0x1, iVar6 == 1)) {
    *(undefined4 *)(this + 0x558) = 0xffffffff;
  }
  if ((iVar6 == 0) &&
     ((iVar6 = (**(code **)(*(int *)this + 0xe4))(*(undefined4 *)(this + 0x7c)), iVar6 == 0 ||
      (*(int *)(this + 0x7c) != *(int *)(this + 0x98))))) {
    pCVar13 = (CGameRace *)0x1;
  }
  if ((*(int *)(this + 0x6c) != 2) && (*(int *)(this + 0x84) != 0)) {
    pCVar13 = (CGameRace *)0x1;
  }
  if ((*(int *)(this + 0x70) == 1) && (*(int *)(this + 0x74) != 2)) {
    pCVar13 = (CGameRace *)0x1;
  }
  if (param_1 == (CTrackManiaRaceNet *)0x0) {
    if (pCVar13 == (CGameRace *)0x0) {
      return;
    }
LAB_004b8ed3:
    if (*(int *)(this + 0x70) == 0) {
      if ((*(int *)(this + 0x7c) == 0) ||
         (iVar6 = (**(code **)(*(int *)this + 0xe4))(*(int *)(this + 0x7c)), iVar6 == 0)) {
        uVar7 = (**(code **)(*(int *)this + 0xdc))(0);
        *(undefined4 *)(this + 0x7c) = uVar7;
      }
      in_stack_00000008 = *(CGameRace **)(this + 0x7c);
    }
    else if (*(int *)(this + 0x70) == 1) {
      if (*(int *)(this + 0x78) != 1) {
        *(undefined4 *)(this + 0x98) = 0;
      }
      in_stack_00000008 = (CGameRace *)(**(code **)(*(int *)this + 0xe0))();
    }
    *(undefined4 *)(this + 0x78) = *(undefined4 *)(this + 0x70);
  }
  else {
    if ((*(int *)(this + 0x74) == 2) && (*(int *)(this + 0x98) == 0)) {
      pCVar13 = (CGameRace *)0x1;
    }
    if (((*(int *)(this + 0x74) == 0) &&
        (iVar6 = CGameRace::MediaClipIsPlaying((CGameRace *)this,pCVar17), iVar6 != 0)) &&
       (*(int *)(this + 0xa8) != 0)) {
      pCVar17 = (CGameRace *)0x4b8ecf;
      CGameRace::MediaClipStop((CGameRace *)this,in_stack_fffffff8);
    }
    if (pCVar13 != (CGameRace *)0x0) goto LAB_004b8ed3;
  }
  bVar14 = false;
  if (((in_stack_00000008 == *(CGameRace **)(this + 0x98)) ||
      (in_stack_00000008 != (CGameRace *)0x0)) ||
     (pCVar11 = (CTrackManiaRaceNet *)0x1, *(int *)(this + 0x84) != 0)) {
    pCVar11 = param_1;
  }
  pCVar13 = *(CGameRace **)(this + 0x84);
  if (((*(int *)(this + 0x6c) == 2) && (in_stack_00000008 != (CGameRace *)0x0)) &&
     (pCVar13 != (CGameRace *)0x0)) {
    *(undefined4 *)(this + 0x84) = 0;
    *(undefined4 *)(this + 0x6c) = *(undefined4 *)(this + 0x88);
  }
  else if (pCVar11 == (CTrackManiaRaceNet *)0x0) goto LAB_004b906c;
  if ((in_stack_00000008 == (CGameRace *)0x0) && (*(int *)(this + 0x6c) != 2)) {
    if (*(int *)(this + 0x84) == 0) {
      *(undefined4 *)(this + 0x84) = 1;
      *(int *)(this + 0x88) = *(int *)(this + 0x6c);
    }
    (**(code **)(*(int *)this + 0xd4))(2);
  }
  if (((*(int *)(this + 0x74) == 2) && (*(int *)(this + 0x6c) != 2)) &&
     (pCVar8 = CGamePlayerCameraSet::CamPtrGet
                         (*(CGamePlayerCameraSet **)(iVar3 + 0x20),
                          *(CGamePlayerCameraSet **)(in_stack_0000000c + 0x38),(ulong)pCVar17),
     pCVar8 != (CGameControlCamera *)0x0)) {
    pCVar17 = (CGameRace *)0x306d000;
    iVar6 = (**(code **)(*(int *)pCVar8 + 0x10))();
    if (iVar6 != 0) {
      (**(code **)(*(int *)pCVar8 + 0xa4))();
    }
  }
  iVar6 = *(int *)(this + 0x6c);
  if (iVar6 == 0) {
    pCVar16 = *(CGamePlayerCameraSet **)(in_stack_0000000c + 0x3c);
LAB_004b9044:
    CGamePlayerCameraSet::CamSwitchTo
              (*(CGamePlayerCameraSet **)(iVar3 + 0x20),pCVar16,(ulong)pCVar17);
    *(undefined4 *)(this + 0x84) = 0;
LAB_004b9052:
    bVar14 = true;
  }
  else {
    if (iVar6 == 1) {
      pCVar16 = *(CGamePlayerCameraSet **)(in_stack_0000000c + 0x2c);
      goto LAB_004b9044;
    }
    if (iVar6 == 2) {
      CGamePlayerCameraSet::CamSwitchTo
                (*(CGamePlayerCameraSet **)(iVar3 + 0x20),
                 *(CGamePlayerCameraSet **)(in_stack_0000000c + 0x38),(ulong)pCVar17);
      in_stack_0000000c = (CGameRace *)0x0;
      goto LAB_004b9052;
    }
  }
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(this + 0x6c);
  if (*(CTrackManiaRaceInterface **)(this + 0x518) != (CTrackManiaRaceInterface *)0x0) {
    CTrackManiaRaceInterface::OnNetSpectatorCameraChange
              (*(CTrackManiaRaceInterface **)(this + 0x518),(CTrackManiaRaceInterface *)pCVar17);
  }
LAB_004b906c:
  pCVar9 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,pCVar17);
  CVar12 = pCVar9[0x78];
  pCVar17 = *(CGameRace **)(this + 0x98);
  if (in_stack_0000000c == pCVar17) {
    if (bVar14) {
      CVar12 = (CGamePlayerInfo)0xff;
      this[0x1c] = (CTrackManiaRaceNet)0xff;
      if ((*(int *)(this + 0x6c) != 2) && (pCVar17 != (CGameRace *)0x0)) {
        if (*(int *)(this + 0x70) == 1) {
          this[0x1c] = *(CTrackManiaRaceNet *)(pCVar17 + 0x24);
          CVar12 = (CGamePlayerInfo)0xfc;
        }
        else {
          CVar12 = *(CGamePlayerInfo *)(pCVar17 + 0x24);
        }
      }
    }
  }
  else {
    *(CGameRace **)(this + 0x98) = in_stack_0000000c;
    if (in_stack_0000000c == (CGameRace *)0x0) {
      iVar3 = (**(code **)(*(int *)this + 0xec))();
      if (((iVar3 != 0) && (*(int *)(this + 0x84) == 0)) && (in_stack_00000018 == 0)) {
        (**(code **)(*(int *)this + 0x1b8))();
      }
      if (*(int *)(this + 0x70) == 1) {
        this[0x1c] = (CTrackManiaRaceNet)0xff;
        CVar12 = (CGamePlayerInfo)0xfc;
      }
      else {
        CVar12 = (CGamePlayerInfo)0xff;
      }
    }
    else {
      *(CGameRace **)(this + 700) = in_stack_0000000c;
      pCVar10 = CGameRace::GetLocalPlayer((CGameRace *)this,in_stack_fffffff8);
      if (*(int *)(*(int *)(this + 0x98) + 0x238) != 0) {
        CGamePlayerCameraSet::PlayerGameMobilIdSet
                  (*(CGamePlayerCameraSet **)(pCVar10 + 0x20),
                   *(CGamePlayerCameraSet **)
                    (*(int *)(*(int *)(*(int *)(this + 0x98) + 0x238) + 0x28) + 0x18),
                   in_stack_fffffffc);
        iVar3 = CGameRace::MediaClipIsPlaying((CGameRace *)this,pCVar15);
        if ((iVar3 != 0) && (*(int *)(this + 0xa8) != 0)) {
          CGameRace::MediaClipStop((CGameRace *)this,pCVar13);
        }
      }
      CVar12 = (CGamePlayerInfo)0xff;
      this[0x1c] = (CTrackManiaRaceNet)0xff;
      if (*(int *)(this + 0x6c) != 2) {
        if (*(int *)(this + 0x70) == 1) {
          this[0x1c] = *(CTrackManiaRaceNet *)(*(int *)(this + 0x98) + 0x24);
          CVar12 = (CGamePlayerInfo)0xfc;
        }
        else {
          CVar12 = *(CGamePlayerInfo *)(*(int *)(this + 0x98) + 0x24);
        }
        iVar3 = (**(code **)(*(int *)this + 0xec))();
        if (iVar3 != 0) {
          (**(code **)(*(int *)this + 0x1b8))();
        }
      }
    }
  }
  pCVar9 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,in_stack_00000008);
  if (CVar12 == pCVar9[0x78]) {
    return;
  }
  pCVar9 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,in_stack_0000000c);
  pCVar9[0x78] = CVar12;
  pCVar9 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,in_stack_00000010);
  CGameNetPlayerInfo::SetDirty((CGameNetPlayerInfo *)pCVar9,in_stack_00000038,in_stack_0000003c);
  return;
}
}

// =================================================
// Function: CTrackManiaRaceNet::SwitchToRace
// =================================================
void __thiscall
CTrackManiaRaceNet::SwitchToRace
          (CTrackManiaRaceNet *this,CGameRace *param_1,GmNat3 param_2,ECardinalDir param_3)
{
{
  CTrackManiaRaceScore *pCVar1;
  CTrackManiaRaceScore *extraout_EAX;
  CTrackManiaPlayerInfo *this_00;
  undefined *puVar2;
  CTrackManiaRaceScore *pCVar3;
  CTrackManiaPlayerInfo *unaff_EBX;
  int iVar4;
  void *unaff_EBP;
  CFastString *unaff_ESI;
  SRpcPlayerInfo *unaff_EDI;
  CTrackManiaRaceScore *this_01;
  CFastBuffer<class_CSystemPackDesc*> *in_stack_00000010;
  TiXmlAttribute *pTVar5;
  char *pcVar6;
  CMwNod *pCVar7;
  CTrackManiaRaceScore *local_2c;
  CTrackManiaPlayerInfo local_28 [8];
  undefined4 local_20;
  undefined *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *local_c;
  
  local_c = (undefined *)0xffffffff;
  puStack_10 = &LAB_00a8c14b;
  local_14 = ExceptionList;
  pCVar1 = (CTrackManiaRaceScore *)(DAT_00cca150 ^ (uint)&stack0xffffffc8);
  ExceptionList = &local_14;
  CTrackManiaRace::SwitchToRace((CTrackManiaRace *)this,param_1,param_2,param_3);
  CFastBuffer<class_CSystemPackDesc*>::ReleaseAll(this + 0x5a8,in_stack_00000010);
  iVar4 = 0;
  local_20 = 0;
  local_1c = PTR_DAT_00bbf7dc;
  local_c = (undefined *)0x0;
  do {
    local_2c = operator_new(0x5c);
    local_c._0_1_ = 1;
    if (local_2c == (CTrackManiaRaceScore *)0x0) {
      this_01 = (CTrackManiaRaceScore *)0x0;
    }
    else {
      CTrackManiaRaceScore::CTrackManiaRaceScore(local_2c,pCVar1);
      this_01 = extraout_EAX;
    }
    pcVar6 = (char *)&local_20;
    local_c._0_1_ = 0;
    local_2c = this_01;
    (**(code **)(*(int *)this + 0x198))(iVar4);
    CFastString::CFastString((CFastString *)&local_2c,(CFastString *)&DAT_00b2c878,pcVar6);
    pCVar7 = (CMwNod *)0x0;
    pTVar5 = (TiXmlAttribute *)0x0;
    local_c = (undefined *)CONCAT31(local_c._1_3_,2);
    CTrackManiaRaceScore::InitScores(this_01,(CTrackManiaRaceScore *)&local_20,local_28,iVar4);
    local_14 = (void *)((uint)local_14 & 0xffffff00);
    if (local_2c != (CTrackManiaRaceScore *)PTR_DAT_00bbf7d8) {
      pCVar3 = local_2c + -1;
      if (((byte)local_2c[-1] & 0x80) != 0) {
        pCVar3 = local_2c + -4;
      }
      operator_delete__(pCVar3);
      unaff_EBX = (CTrackManiaPlayerInfo *)0x0;
      local_2c = (CTrackManiaRaceScore *)PTR_DAT_00bbf7d8;
    }
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (this + 0x5a8,(TiXmlAttributeSet *)&stack0xffffffcc,pTVar5);
    CMwNod::MwAddRef((CMwNod *)this_01,pCVar7);
    iVar4 = iVar4 + 1;
  } while ((ushort)iVar4 < 2);
  (**(code **)(*(int *)this + 0x24c))();
  *(undefined4 *)(this + 0x5c0) = 0;
  this_00 = (CTrackManiaPlayerInfo *)
            CTrackMania::GetPlayerInfo
                      (*(CTrackMania **)(this + 0x18),(CTrackManiaNetwork *)0x0,
                       (CFastString *)pCVar1,unaff_EDI,unaff_ESI);
  CTrackManiaPlayerInfo::ResetPerformance(this_00,unaff_EBX);
  *(undefined4 *)(this + 0x5c4) = 0xffffffff;
  *(undefined4 *)(DAT_00d54250 + 0x20) = 1;
  if (local_c != PTR_DAT_00bbf7dc) {
    if ((local_c[-1] & 0x80) == 0) {
      puVar2 = local_c + -2;
    }
    else {
      puVar2 = local_c + -4;
    }
    operator_delete__(puVar2);
  }
  ExceptionList = unaff_EBP;
  return;
}
}

// =================================================
// Function: CTrackManiaRaceNet::UpdateAsync
// =================================================
void __thiscall CTrackManiaRaceNet::UpdateAsync(CTrackManiaRaceNet *this,CInputPortDx8 *param_1)
{
{
  CMwId *pCVar1;
  CGamePlayerInfo *pCVar2;
  int iVar3;
  CGameCtnNetwork *pCVar4;
  ulong uVar5;
  CPlugAudio *this_00;
  CGameRace *unaff_EBX;
  int iVar6;
  CInputPortDx8 *unaff_ESI;
  CPlugAudio *unaff_EDI;
  int unaff_retaddr;
  CGameRace *in_stack_00000008;
  CGameRace *in_stack_0000000c;
  CTrackManiaRaceNet *in_stack_00000018;
  CGameRace *in_stack_0000001c;
  CGameCtnNetwork *in_stack_00000020;
  CGameCtnNetwork *in_stack_0000002c;
  
  CTrackManiaRace::UpdateAsync((CTrackManiaRace *)this,unaff_ESI);
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar1 = CPlugAudio::MwGetId(this_00,unaff_EDI);
  iVar6 = *(int *)pCVar1;
  pCVar2 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,unaff_EBX);
  if ((*(int *)(pCVar2 + 0x70) == 0) && (*(int *)(pCVar2 + 0x74) == 0)) {
    RaceInputsSendToServer(this,(CTrackManiaRaceNet *)0x0,unaff_retaddr);
  }
  else {
    iVar3 = (**(code **)(*(int *)this + 0xec))();
    if ((iVar3 != 0) && (*(int *)(this + 0x680) != 0)) {
      iVar3 = (**(code **)(*(int *)this + 0x260))();
      if (iVar3 != 0) {
        iVar3 = (**(code **)(*(int *)this + 0x264))();
        if (iVar3 != 0) {
          (**(code **)(*(int *)this + 0x268))();
          *(undefined4 *)(this + 0x680) = 0;
          if (*(int *)(this + 0x98) != 0) {
            (**(code **)(*(int *)this + 0x1b8))();
          }
        }
      }
    }
  }
  pCVar2 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,(CGameRace *)param_1);
  if ((*(int *)(pCVar2 + 0x314) == 2) && (*(int *)(this + 0x5c4) == -1)) {
    pCVar2 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,in_stack_00000008);
    if ((*(int *)(pCVar2 + 0x70) == 0) && (*(int *)(pCVar2 + 0x74) == 0)) {
      iVar6 = iVar6 + 2000;
    }
    else {
      iVar6 = iVar6 + 500;
    }
    *(int *)(this + 0x5c4) = iVar6;
    *(undefined4 *)(this + 0x74) = 0xffffffff;
    *(undefined4 *)(this + 0x78) = 0xffffffff;
  }
  pCVar2 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,in_stack_0000000c);
  if ((*(int *)(pCVar2 + 0x70) != 0) || (*(int *)(pCVar2 + 0x74) != 0)) {
    SpectatorCameraChange(this,in_stack_00000018);
  }
  if (*(int *)(this + 0x50) == 0) {
    iVar6 = (**(code **)(*(int *)this + 0x1a0))();
    if (iVar6 != 0) {
      CGameRace::SetStatus((CGameRace *)this,(CGameRace *)&DAT_00000004,(EStatus)in_stack_0000001c);
    }
    pCVar2 = CGameRace::GetLocalPlayerInfo((CGameRace *)this,in_stack_0000001c);
    if (((*(int *)(pCVar2 + 0x70) == 0) && (*(int *)(pCVar2 + 0x74) == 0)) &&
       (*(int **)(this + 0x18) != (int *)0x0)) {
      iVar6 = (**(code **)(**(int **)(this + 0x18) + 0x118))();
      if (iVar6 != 0) {
        pCVar4 = (CGameCtnNetwork *)(**(code **)(**(int **)(this + 0x18) + 0x118))();
        uVar5 = CGameCtnNetwork::GetNbAutoSpectators(pCVar4,in_stack_00000020);
        if (uVar5 != 0) {
          iVar6 = (**(code **)(*(int *)this + 0xe0))();
          if (iVar6 == 0) {
            this[0x1c] = (CTrackManiaRaceNet)0xff;
          }
          else {
            this[0x1c] = *(CTrackManiaRaceNet *)(iVar6 + 0x24);
          }
          if (iVar6 != *(int *)(this + 0x98)) {
            *(int *)(this + 0x98) = iVar6;
            pCVar4 = (CGameCtnNetwork *)(**(code **)(**(int **)(this + 0x18) + 0x118))();
            CGameCtnNetwork::UpdateSpectatorsCounts(pCVar4,in_stack_0000002c);
            return;
          }
        }
      }
    }
  }
  return;
}
}

