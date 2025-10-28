
/* public: void __thiscall
 * CSceneVehicleCar::SSimulationWheel::SState::Reset(void) */

void __thiscall CSceneVehicleCar::SSimulationWheel::SState::Reset(SState *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined2 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  GmMat3::SetIdentity((GmMat3 *)(this + 0x30));
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  return;
}
