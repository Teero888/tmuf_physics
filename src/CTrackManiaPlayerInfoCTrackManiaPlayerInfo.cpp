
/* public: __thiscall CTrackManiaPlayerInfo::CTrackManiaPlayerInfo(void) */

CTrackManiaPlayerInfo *__thiscall CTrackManiaPlayerInfo::CTrackManiaPlayerInfo(
    CTrackManiaPlayerInfo *this)

{
  CInputEventsStore *this_00;
  CMwId *pCVar1;
  CMwId local_14[4];
  CTrackManiaPlayerInfo *local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a8bbbc;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = this;
  CGamePlayerInfo::CGamePlayerInfo((CGamePlayerInfo *)this);
  local_4 = 0;
  *(undefined ***)this = vftable;
  CFastArray<>::CFastArray<>((CFastArray<> *)(this + 0x2f8));
  CFastArray<>::CFastArray<>((CFastArray<> *)(this + 0x300));
  *(undefined4 *)(this + 0x30c) = 0;
  *(wchar_t **)(this + 0x310) = L"";
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x324));
  this_00 = (CInputEventsStore *)(this + 0x350);
  local_4._0_1_ = 4;
  CInputEventsStore::CInputEventsStore(this_00, 0, 1);
  *(undefined4 *)(this + 0x3a0) = 0;
  *(char **)(this + 0x3a4) = "";
  *(undefined4 *)(this + 0x3a8) = 0;
  *(wchar_t **)(this + 0x3ac) = L"";
  local_4._0_1_ = 6;
  *(undefined4 *)(this + 0x240) = 0;
  *(undefined4 *)(this + 0x318) = 0;
  *(undefined4 *)(this + 0x348) = 0;
  *(undefined4 *)(this + 0x34c) = 0;
  *(undefined4 *)(this + 0x2ac) = 0xffffffff;
  *(undefined4 *)(this + 0x2b8) = 0xffffffff;
  *(undefined4 *)(this + 0x2a4) = 0xffffffff;
  *(undefined4 *)(this + 0x2e4) = 0;
  *(undefined4 *)(this + 0x330) = 0;
  *(undefined4 *)(this + 0x334) = 0;
  *(undefined4 *)(this + 0x2cc) = 0;
  ResetPerformance(this);
  *(undefined4 *)(this + 0x314) = 2;
  GmIso4::SetIdentity((GmIso4 *)(this + 0x274));
  GmIso4::SetIdentity((GmIso4 *)(this + 0x244));
  *(undefined4 *)(this + 800) = 0;
  *(undefined4 *)(this + 0x238) = 0;
  *(undefined4 *)(this + 0x308) = 0;
  *(undefined4 *)(this + 0x31c) = 0;
  *(undefined4 *)(this + 0x2c4) = 0;
  *(undefined4 *)(this + 0x2d4) = 0;
  *(undefined4 *)(this + 0x338) = 0;
  *(undefined4 *)(this + 0x33c) = 0;
  *(undefined4 *)(this + 0x340) = 0;
  *(undefined4 *)(this + 0x344) = 0;
  *(undefined4 *)(this + 0x2f0) = 0xffffffff;
  *(undefined4 *)(this + 0x2f4) = 0xffffffff;
  *(undefined4 *)(this + 0x2e8) = 0;
  ResetAverageRank(this);
  SRpcPlayerQuickInfo::Reset((SRpcPlayerQuickInfo *)(this + 0x39c));
  pCVar1 = CMwId::CreateFromLocalName(local_14, "SteerLeft");
  local_4._0_1_ = 7;
  CInputEventsStore::RegisterInput(
      this_00, (SInputActionDesc *)CTrackManiaRace::ActionVehicleSteerLeft_1,
      pCVar1);
  local_4._0_1_ = 6;
  CScene2d::OnNodLoaded((CScene2d *)local_14);
  pCVar1 = CMwId::CreateFromLocalName(local_14, "SteerRight");
  local_4._0_1_ = 8;
  CInputEventsStore::RegisterInput(
      this_00, (SInputActionDesc *)CTrackManiaRace::ActionVehicleSteerRight_1,
      pCVar1);
  local_4._0_1_ = 6;
  CScene2d::OnNodLoaded((CScene2d *)local_14);
  pCVar1 = CMwId::CreateFromLocalName(local_14, "Steer");
  local_4._0_1_ = 9;
  CInputEventsStore::RegisterInput(
      this_00, (SInputActionDesc *)CTrackManiaRace::ActionVehicleSteer_1,
      pCVar1);
  local_4._0_1_ = 6;
  CScene2d::OnNodLoaded((CScene2d *)local_14);
  pCVar1 = CMwId::CreateFromLocalName(local_14, "Brake");
  local_4._0_1_ = 10;
  CInputEventsStore::RegisterInput(
      this_00, (SInputActionDesc *)CTrackManiaRace::ActionVehicleBrake_1,
      pCVar1);
  local_4._0_1_ = 6;
  CScene2d::OnNodLoaded((CScene2d *)local_14);
  pCVar1 = CMwId::CreateFromLocalName(local_14, "Accelerate");
  local_4._0_1_ = 0xb;
  CInputEventsStore::RegisterInput(
      this_00, (SInputActionDesc *)CTrackManiaRace::ActionVehicleAccelerate_1,
      pCVar1);
  local_4._0_1_ = 6;
  CScene2d::OnNodLoaded((CScene2d *)local_14);
  pCVar1 = CMwId::CreateFromLocalName(local_14, "Gas");
  local_4._0_1_ = 0xc;
  CInputEventsStore::RegisterInput(
      this_00, (SInputActionDesc *)CTrackManiaRace::ActionVehicleGas_1, pCVar1);
  local_4._0_1_ = 6;
  CScene2d::OnNodLoaded((CScene2d *)local_14);
  pCVar1 = CMwId::CreateFromLocalName(local_14, "Respawn");
  local_4._0_1_ = 0xd;
  CInputEventsStore::RegisterInput(
      this_00, (SInputActionDesc *)CTrackManiaRace::ActionRespawn_1, pCVar1);
  local_4._0_1_ = 6;
  CScene2d::OnNodLoaded((CScene2d *)local_14);
  pCVar1 = CMwId::CreateFromLocalName(local_14, "Horn");
  local_4._0_1_ = 0xe;
  CInputEventsStore::RegisterInput(
      this_00, (SInputActionDesc *)CTrackManiaRace::ActionVehicleHorn_1,
      pCVar1);
  local_4._0_1_ = 6;
  CScene2d::OnNodLoaded((CScene2d *)local_14);
  pCVar1 = CMwId::CreateFromLocalName(local_14, "_FakeFinishLine");
  local_4._0_1_ = 0xf;
  CInputEventsStore::RegisterInput(
      this_00, (SInputActionDesc *)CTrackManiaRace::ActionFakeFinishLine,
      pCVar1);
  local_4._0_1_ = 6;
  CScene2d::OnNodLoaded((CScene2d *)local_14);
  pCVar1 = CMwId::CreateFromLocalName(local_14, "_FakeIsRaceRunning");
  local_4._0_1_ = 0x10;
  CInputEventsStore::RegisterInput(
      this_00, (SInputActionDesc *)CTrackManiaRace::ActionFakeIsRaceRunning,
      pCVar1);
  local_4 = CONCAT31(local_4._1_3_, 6);
  CScene2d::OnNodLoaded((CScene2d *)local_14);
  ExceptionList = local_c;
  return this;
}
