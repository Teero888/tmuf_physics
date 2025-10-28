
/* protected: void __thiscall CSceneVehicleCar::WheelReset(struct
   CSceneVehicleCar::SSimulationWheel
   &) */

void __thiscall CSceneVehicleCar::WheelReset(CSceneVehicleCar *this,
                                             SSimulationWheel *param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;

  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  piVar3 = (int *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
      *(ulong *)(*(int *)(this + 100) + 0x24));
  fVar1 = *(float *)(*piVar3 + 0x124);
  *(float *)(param_1 + 0xb4) = fVar1;
  fVar1 = -fVar1;
  fVar2 = fVar1 * 0.0;
  CSceneVehicle::SSurfaceHandler::Reset((SSurfaceHandler *)(param_1 + 0xc));
  *(float *)(param_1 + 100) = *(float *)(param_1 + 100) + fVar2;
  *(float *)(param_1 + 0x68) = *(float *)(param_1 + 0x68) + fVar1;
  *(float *)(param_1 + 0x6c) = *(float *)(param_1 + 0x6c) + fVar2;
  CSceneVehicle::SSurfaceHandler::UpdateSurface(
      (SSurfaceHandler *)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  GmIso4::SetIdentity((GmIso4 *)(param_1 + 0xe4));
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined2 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  SSimulationWheel::SState::Reset((SState *)(param_1 + 0x234));
  SSimulationWheel::SState::Reset((SState *)(param_1 + 0x298));
  SSimulationWheel::SState::Reset((SState *)(param_1 + 0x16c));
  SSimulationWheel::SState::Reset((SState *)(param_1 + 0x1d0));
  return;
}
