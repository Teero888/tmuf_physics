/* public: void __thiscall CTrackManiaRace::Validate(struct SMwFiberContext *
   &,struct STmValidateParam const &,enum ETmValidateResult &,class
   CFastStringInt &,int,int,int) */

void __thiscall CTrackManiaRace::Validate(CTrackManiaRace *this,
                                          SMwFiberContext **param_1,
                                          STmValidateParam *param_2,
                                          ETmValidateResult *param_3,
                                          CFastStringInt *param_4, int param_5,
                                          int param_6, int param_7)

{
  CGameNetPlayerInfo **this_00;
  wchar_t **ppwVar1;
  uint uVar2;
  CInputEventsStore *this_01;
  uint uVar3;
  uint *puVar4;
  SContext *this_02;
  SMwFiberContext *pSVar5;
  int iVar6;
  undefined4 *puVar7;
  CTrackManiaPlayerInfo *this_03;
  CGameCamera *pCVar8;
  CMwId *pCVar9;
  CGamePlayer *pLocalPlayer;
  wchar_t *pwVar10;
  CGameDialogs *pCVar11;
  ulong uVar12;
  int *piVar13;
  CMwCmdBufferCore *this_04;
  uint uVar14;
  undefined4 unaff_EBX;
  STmValidateParam **ppSVar15;
  CFastStringInt *pCVar16;
  CFastStringInt *pCVar17;
  undefined8 uVar18;
  CMwId aCStack_60[4];
  CMwId aCStack_5c[4];
  CMwId aCStack_58[4];
  CMwId aCStack_54[4];
  CMwId aCStack_50[4];
  CMwId aCStack_4c[4];
  CMwId aCStack_48[4];
  CMwId aCStack_44[4];
  CMwId aCStack_40[4];
  wchar_t *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  CFastStringInt aCStack_30[4];
  undefined auStack_2c[4];
  SHeaderCommunity aSStack_28[8];
  SStringParam aSStack_20[4];
  int *piStack_1c;
  wchar_t *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a885eb;
  local_c = ExceptionList;
  uVar3 = ___security_cookie ^ (uint)&stack0xffffff8c;
  ExceptionList = &local_c;
  this_04 = *(CMwCmdBufferCore **)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x14);
  if (this_04 == (CMwCmdBufferCore *)0x0) {
    this_04 = CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0;
  }
  puVar4 = (uint *)CPlugAudio::MwGetId((CPlugAudio *)this_04);
  uVar14 = *puVar4;
  if (*param_1 == (SMwFiberContext *)0xffffffff) {
    ExceptionList = local_c;
    return;
  }
  if (*param_1 == (SMwFiberContext *)0x0) {
    this_02 = (SContext *)operator_new(0x28);
    if (this_02 == (SContext *)0x0) {
      pSVar5 = (SMwFiberContext *)0x0;
    } else {
    pSVar5 = (SMwFiberContext *)
               `public
        : _void___thiscall_CTrackManiaRace::Validate(
              struct_SMwFiberContext *&, struct_ST mValidateParam_const &,
              enum_ETmValidateResult &, class_CFastStringInt &, int, int,
              int) ' ::`5' ::SContext::SContext(this_02);
    }
    *param_1 = pSVar5;
  }
  uVar2 = *(uint *)(*param_1 + 4);
  if (0x5b7 < uVar2) {
    if (uVar2 == 0x60d) {
      if (*(int *)(this + 0x288) == 0) {
        (**(code **)(*(int *)this + 0x168))(0xffffffff, 0xffffffff, uVar3);
        CGameRace::SetStatus((CGameRace *)this, 3);
        iVar6 = (**(code **)(*(int *)this + 0x10))(0x24044000);
        if (iVar6 != 0) {
          CTrackManiaNetwork::Hack_ResetAfterValidation(
              *(CTrackManiaNetwork **)(*(int *)(this + 0x18) + 300));
        }
      }
      *param_3 = *(ETmValidateResult *)(*param_1 + 0x1c);
      local_3c = *(wchar_t **)(*param_1 + 0x24);
      local_38 = *(undefined4 *)(*param_1 + 0x20);
      ppwVar1 = &local_3c;
      local_34 = 0;
    } else {
      if (uVar2 != 0xffffffff)
        goto LAB_004831a4;
    LAB_00483055:
      if (param_5 != 0) {
        pCVar11 = CGameApp::GetBasicDialogs(*(CGameApp **)(this + 0x18));
        CGameDialogs::HideDialogs(pCVar11);
      }
      if (*(int *)(this + 0x32c) != 0) {
        uVar12 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x24));
        if (uVar12 != 0) {
          piVar13 = (int *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x24), 0);
          iVar6 = *(int *)(*piVar13 + 0x28);
          pLocalPlayer = CGameRace::GetLocalPlayer((CGameRace *)this);
          CGamePlayerCameraSet::PlayerGameMobilIdSet(
              *(CGamePlayerCameraSet **)(pLocalPlayer + 0x20),
              *(ulong *)(iVar6 + 0x18));
        }
      }
      ValidateCleanup(this);
      CGameRace::GetLocalPlayerInfo((CGameRace *)this);
      CGameRace::GetLocalPlayer((CGameRace *)this);
      pLocalPlayer = CGameRace::GetLocalPlayer((CGameRace *)this);
      CHmsItem::SetCollisionGroup(
          *(CHmsItem **)(*(int *)(*(int *)(pLocalPlayer + 0x28) + 0x14) + 0x28),
          3);
      CMwCmdBufferCore::SetSimulationRelativeSpeed(
          CMwCmdBufferCore::TheCoreCmdBuffer, 1.0);
      CMwCmdBufferCore::SetSimulationCurrentTime(
          CMwCmdBufferCore::TheCoreCmdBuffer, *(ulong *)(*param_1 + 0x10));
      CInputPort::ClearInputs(*(CInputPort **)(this + 0x20), 1);
      ppwVar1 = &local_18;
      *param_3 = 0;
      local_18 = L"Validation interrupted";
      local_14 = 0x16;
      local_10 = 1;
    }
    CFastStringInt::SetString(param_4, (SStringParamInt *)ppwVar1);
  LAB_004831a4:
    puVar7 = (undefined4 *)*param_1;
    if ((puVar7 != (undefined4 *)0xffffffff) && (puVar7 != (undefined4 *)0x0)) {
      (**(code **)*puVar7)();
    }
    *param_1 = (SMwFiberContext *)0xffffffff;
    ExceptionList = local_c;
    return;
  }
  if (uVar2 == 0x5b7) {
    if (*(int *)(this + 0x330) == 0)
      goto LAB_00483055;
    if ((*(uint *)(*(int *)(this + 0x2fc) + 0xec) == 0xffffffff) ||
        (*(uint *)(this + 800) <= *(uint *)(*(int *)(this + 0x2fc) + 0xec)))
      goto LAB_00482dd5;
  } else {
    if (uVar2 == 0) {
      *(int *)(this + 0x32c) = param_6;
      STmValidateParam::operator=((STmValidateParam *)(this + 0x2fc), param_2);
      *(undefined4 *)(*param_1 + 0x1c) = 2;
      CFastStringInt::SetLength((CFastStringInt *)(*param_1 + 0x20), 0);
      (**(code **)(*(int *)this + 0x80))();
      this_01 = *(CInputEventsStore **)(this + 0x300);
      pCVar9 = CMwId::CreateFromLocalName((CMwId *)&param_6, "SteerLeft");
      uStack_4 = 0;
      CInputEventsStore::RegisterInput(
          this_01, (SInputActionDesc *)ActionVehicleSteerLeft_1, pCVar9);
      uStack_4 = 0xffffffff;
      CScene2d::OnNodLoaded((CScene2d *)&param_6);
      pCVar9 = CMwId::CreateFromLocalName(aCStack_60, "SteerRight");
      uStack_4 = 1;
      CInputEventsStore::RegisterInput(
          this_01, (SInputActionDesc *)ActionVehicleSteerRight_1, pCVar9);
      uStack_4 = 0xffffffff;
      CScene2d::OnNodLoaded((CScene2d *)aCStack_60);
      pCVar9 = CMwId::CreateFromLocalName(aCStack_5c, "Steer");
      uStack_4 = 2;
      CInputEventsStore::RegisterInput(
          this_01, (SInputActionDesc *)ActionVehicleSteer_1, pCVar9);
      uStack_4 = 0xffffffff;
      CScene2d::OnNodLoaded((CScene2d *)aCStack_5c);
      pCVar9 = CMwId::CreateFromLocalName(aCStack_58, "Brake");
      uStack_4 = 3;
      CInputEventsStore::RegisterInput(
          this_01, (SInputActionDesc *)ActionVehicleBrake_1, pCVar9);
      uStack_4 = 0xffffffff;
      CScene2d::OnNodLoaded((CScene2d *)aCStack_58);
      pCVar9 = CMwId::CreateFromLocalName(aCStack_54, "Accelerate");
      uStack_4 = 4;
      CInputEventsStore::RegisterInput(
          this_01, (SInputActionDesc *)ActionVehicleAccelerate_1, pCVar9);
      uStack_4 = 0xffffffff;
      CScene2d::OnNodLoaded((CScene2d *)aCStack_54);
      pCVar9 = CMwId::CreateFromLocalName(aCStack_50, "Gas");
      uStack_4 = 5;
      CInputEventsStore::RegisterInput(
          this_01, (SInputActionDesc *)ActionVehicleGas_1, pCVar9);
      uStack_4 = 0xffffffff;
      CScene2d::OnNodLoaded((CScene2d *)aCStack_50);
      pCVar9 = CMwId::CreateFromLocalName(aCStack_4c, "Respawn");
      uStack_4 = 6;
      CInputEventsStore::RegisterInput(
          this_01, (SInputActionDesc *)ActionRespawn_1, pCVar9);
      uStack_4 = 0xffffffff;
      CScene2d::OnNodLoaded((CScene2d *)aCStack_4c);
      pCVar9 = CMwId::CreateFromLocalName(aCStack_48, "Horn");
      uStack_4 = 7;
      CInputEventsStore::RegisterInput(
          this_01, (SInputActionDesc *)ActionVehicleHorn_1, pCVar9);
      uStack_4 = 0xffffffff;
      CScene2d::OnNodLoaded((CScene2d *)aCStack_48);
      pCVar9 = CMwId::CreateFromLocalName(aCStack_44, "_FakeFinishLine");
      uStack_4 = 8;
      CInputEventsStore::RegisterInput(
          this_01, (SInputActionDesc *)ActionFakeFinishLine, pCVar9);
      uStack_4 = 0xffffffff;
      CScene2d::OnNodLoaded((CScene2d *)aCStack_44);
      pCVar9 = CMwId::CreateFromLocalName(aCStack_40, "_FakeIsRaceRunning");
      uStack_4 = 9;
      CInputEventsStore::RegisterInput(
          this_01, (SInputActionDesc *)ActionFakeIsRaceRunning, pCVar9);
      uStack_4 = 0xffffffff;
      CScene2d::OnNodLoaded((CScene2d *)aCStack_40);
      *(undefined4 *)(this + 0x31c) = 0;
      *(undefined4 *)(this + 0x328) = 0;
      *(undefined4 *)(this + 0x318) = *(undefined4 *)(this + 0x304);
      *(undefined4 *)(this + 800) = 0;
      *(undefined4 *)(this + 0x324) = 0xffffffff;
      pLocalPlayer = CGameRace::GetLocalPlayer((CGameRace *)this);
      piVar13 = *(int **)(*(int *)(pLocalPlayer + 0x28) + 0x14);
      (**(code **)(*piVar13 + 0x13c))();
      CHmsItem::SetCollisionGroup((CHmsItem *)piVar13[10], 0);
      StopReplayRecordAndKeepCopy(this, 1);
      if (param_5 != 0) {
        pwVar10 = CClassicI18n::GetTranslatedStringInternal(
            &CClassicI18n::TheClassicI18n, L"Validating ...");
        CFastStringInt::CFastStringInt(aCStack_30, pwVar10);
        uVar18 = 0;
        pCVar17 = &CFastStringInt::s_Null;
        pCVar16 = aCStack_30;
        uStack_4 = 10;
        pCVar11 = CGameApp::GetBasicDialogs(*(CGameApp **)(this + 0x18));
        CGameDialogs::DoMessage(pCVar11, pCVar16, pCVar17, (CMwNod *)uVar18,
                                (_func_void *)((ulonglong)uVar18 >> 0x20));
        CGameCtnApp::SNationConfig::~SNationConfig((SNationConfig *)aCStack_30);
      }
      *(undefined4 *)(*param_1 + 4) = 0x56d;
      ExceptionList = local_c;
      return;
    }
    if (uVar2 != 0x56d) {
      if (uVar2 != 0x5ac)
        goto LAB_004831a4;
      goto LAB_00482fa6;
    }
    if ((*(int *)(this + 0x2fc) != 0) &&
        (*(int *)(*(int *)(this + 0x2fc) + 0x168) != 0)) {
      iVar6 = (**(code **)(*(int *)this + 0x10))();
      puVar7 = (undefined4 *)(**(code **)(*(int *)this + 0xa4))(auStack_2c);
      local_3c = (wchar_t *)puVar7[1];
      local_38 = *puVar7;
      uStack_4 = 0xb;
      CFastString::SetString((CFastString *)(*param_1 + 0x14),
                             (SStringParam *)&local_3c);
      uStack_4 = 0xffffffff;
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(aSStack_28);
      CGamePlayground::UpdateFromSettings(
          (CGamePlayground *)this,
          (CFastString *)(*(int *)(this + 0x2fc) + 0x168), iVar6);
    }
    this_03 = (CTrackManiaPlayerInfo *)operator_new(0x3b8);
    uStack_4 = 0xc;
    if (this_03 == (CTrackManiaPlayerInfo *)0x0) {
      pCVar8 = (CGameCamera *)0x0;
    } else {
      pCVar8 =
          (CGameCamera *)CTrackManiaPlayerInfo::CTrackManiaPlayerInfo(this_03);
    }
    this_00 = (CGameNetPlayerInfo **)(this + 0x330);
    uStack_4 = 0xffffffff;
    CMwNodRef<>::MwSetNod((CMwNodRef<> *)this_00, pCVar8);
    (*this_00)[0x24] = (CGameNetPlayerInfo)0xfb;
    CGameNetwork::SetPlayerInfoType(*this_00, 0);
    local_3c = L"*validation*";
    local_38 = 0xc;
    CFastString::SetString((CFastString *)(*this_00 + 0x28),
                           (SStringParam *)&local_3c);
    (**(code **)(*(int *)this + 0x98))();
    CTrackManiaPlayerInfo::SetSpawnLoc((CTrackManiaPlayerInfo *)*this_00,
                                       (GmIso4 *)(this + 0x28c), 1);
    *(undefined4 *)(this + 0x334) = *(undefined4 *)(this_03 + 0x14);
    ppSVar15 = &param_2;
    (**(code **)(*(int *)this + 0x110))(unaff_EBX, ppSVar15, &param_3, 0);
    (**(code **)(*(int *)this + 0x164))(*(undefined4 *)(*this_00 + 0x238),
                                        puStack_8, uStack_4);
    local_18 = *(wchar_t **)(*(int *)(*this_00 + 0x238) + 0x28);
    piStack_1c = *(int **)(local_18 + 10);
    if (*(int *)(this + 0x32c) != 0) {
      pLocalPlayer = CGameRace::GetLocalPlayer((CGameRace *)this);
      CGamePlayerCameraSet::PlayerGameMobilIdSet(
          *(CGamePlayerCameraSet **)(pLocalPlayer + 0x20),
          *(ulong *)(local_18 + 0xc));
      (**(code **)(**(int **)(*(int *)(this + 0x34) + 0x74) + 0xb0))();
    }
    (**(code **)(*piStack_1c + 0x13c))(1);
    *(wchar_t **)(this + 0x314) = local_18;
    *(STmValidateParam ***)(*param_1 + 0x10) = ppSVar15;
    (**(code **)(*(int *)this + 0x84))();
    CMwCmdBufferCore::StartSimulation(CMwCmdBufferCore::TheCoreCmdBuffer, 0, 0,
                                      1.0);
    CGameRace::SetStatus((CGameRace *)this, 0);
    if ((*(uint *)(this + 0x308) != 0xffffffff) &&
        (*(uint *)(this + 0x304) < *(uint *)(this + 0x308))) {
      *(undefined4 *)(*param_1 + 0x1c) = 0;
      local_3c = L"InputsDuration is too small";
      local_38 = 0x1b;
      local_34 = 1;
      CFastStringInt::SetString((CFastStringInt *)(*param_1 + 0x20),
                                (SStringParamInt *)&local_3c);
      *(undefined4 *)(*param_1 + 4) = 0x5ac;
      ExceptionList = local_c;
      return;
    }
    if (*(int *)(this + 0x32c) == 0) {
      CMwCmdBufferCore::SetSimulationRelativeSpeed(
          CMwCmdBufferCore::TheCoreCmdBuffer, 5.0);
      CMwCmdBufferCore::SetIsSimulationOnly(CMwCmdBufferCore::TheCoreCmdBuffer,
                                            1);
    }
  LAB_00482dd5:
    if ((uVar14 <
         (uint)(*(int *)(this + 0x318) + 100 + *(int *)(this + 0x314))) &&
        (*(int *)(*(int *)(this + 0x330) + 0x314) != 2)) {
      *(undefined4 *)(*param_1 + 4) = 0x5b7;
      ExceptionList = local_c;
      return;
    }
  }
  piVar13 = (int *)(this + 0x330);
  *(undefined4 *)(*param_1 + 0x1c) = 2;
  if (*(float *)(this + 0x31c) < 0.1 == NAN(*(float *)(this + 0x31c))) {
    *(undefined4 *)(*param_1 + 0x1c) = 2;
    CFastStringInt::ConcatFormat(
        *(CFastStringInt **)(this + 0x324), (char *)(*param_1 + 0x20),
        "Deviates : time=%d, dist=%.3g", *(CFastStringInt **)(this + 0x324),
        (double)*(float *)(this + 0x328));
  } else if (((*(int *)(*piVar13 + 0x314) == 2) ||
              (*(int *)(this + 0xf4) != 0)) ||
             ((*(int *)(*(int *)(this + 0xc4) + 0xf4) != 0 &&
               (*(int *)(this + 0xec) == 1)))) {
    *(undefined4 *)(*param_1 + 0x1c) = 1;
    if (*(int *)(this + 0x308) != -1) {
      if (*(int *)(*piVar13 + 0x2a8) == -1) {
        *(undefined4 *)(*param_1 + 0x1c) = 0;
        CFastStringInt::ConcatFormat(
            *(CFastStringInt **)(this + 0x308), (char *)(*param_1 + 0x20),
            "Expecting %d RaceTime instead of unfinished race");
      } else {
        uVar3 = *(int *)(this + 0x308) - *(int *)(*piVar13 + 0x2a8);
        uVar14 = (int)uVar3 >> 0x1f;
        if (10 < (int)((uVar3 ^ uVar14) - uVar14)) {
          *(undefined4 *)(*param_1 + 0x1c) = 0;
          CFastStringInt::ConcatFormat(*(CFastStringInt **)(this + 0x308),
                                       (char *)(*param_1 + 0x20),
                                       "Expecting %d RaceTime instead of %d",
                                       *(CFastStringInt **)(this + 0x308));
        }
      }
    }
    if ((*(int *)(this + 0x30c) != -1) &&
        (*(int *)(this + 0x30c) != *(int *)(*piVar13 + 0x2a8))) {
      pCVar16 = (CFastStringInt *)*param_1;
      *(undefined4 *)(pCVar16 + 0x1c) = 0;
      CFastStringInt::ConcatFormat(pCVar16, (char *)(*param_1 + 0x20),
                                   "Expecting %d StuntsScore instead of %d",
                                   *(undefined4 *)(this + 0x30c));
    }
    if (((*(int *)(this + 0x2fc) != 0) &&
         (iVar6 = *(int *)(*(int *)(this + 0x2fc) + 0xec), iVar6 != -1)) &&
        (iVar6 != *(int *)(this + 800))) {
      *(undefined4 *)(*param_1 + 0x1c) = 0;
      CFastStringInt::ConcatFormat(
          *(CFastStringInt **)(*(int *)(this + 0x2fc) + 0xec),
          (char *)(*param_1 + 0x20), "Expecting %d Respawns instead of %d",
          *(CFastStringInt **)(*(int *)(this + 0x2fc) + 0xec));
    }
  } else {
    *(undefined4 *)(*param_1 + 0x1c) = 0;
    SStringParam::SStringParam(aSStack_20, "Expecting completed race");
    CFastStringInt::Concat((CFastStringInt *)(*param_1 + 0x20), aSStack_20);
  }
LAB_00482fa6:
  if (param_5 != 0) {
    pCVar11 = CGameApp::GetBasicDialogs(*(CGameApp **)(this + 0x18));
    CGameDialogs::HideDialogs(pCVar11);
  }
  ValidateCleanup(this);
  if (*(int *)(*param_1 + 0x14) != 0) {
    CGamePlayground::UpdateFromSettings((CGamePlayground *)this,
                                        (CFastString *)(*param_1 + 0x14), 0);
  }
  pLocalPlayer = CGameRace::GetLocalPlayer((CGameRace *)this);
  CHmsItem::SetCollisionGroup(
      *(CHmsItem **)(*(int *)(*(int *)(pLocalPlayer + 0x28) + 0x14) + 0x28), 3);
  pLocalPlayer = CGameRace::GetLocalPlayer((CGameRace *)this);
  CHmsItem::SetDynamicType(
      *(CHmsItem **)(*(int *)(*(int *)(pLocalPlayer + 0x28) + 0x14) + 0x28), 2);
  CMwCmdBufferCore::SetSimulationRelativeSpeed(
      CMwCmdBufferCore::TheCoreCmdBuffer, 1.0);
  CMwCmdBufferCore::SetSimulationCurrentTime(CMwCmdBufferCore::TheCoreCmdBuffer,
                                             *(ulong *)(*param_1 + 0x10));
  CInputPort::ClearInputs(*(CInputPort **)(this + 0x20), 1);
  *(undefined4 *)(*param_1 + 4) = 0x60d;
  ExceptionList = local_c;
  return;
}
