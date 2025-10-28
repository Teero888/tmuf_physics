
/* public: __thiscall CSceneVehicleCar::SSimulationWheel::SSimulationWheel(void)
 */

SSimulationWheel
    *__thiscall CSceneVehicleCar::SSimulationWheel::SSimulationWheel(
        SSimulationWheel *this)

{
  CSceneVehicle::SSurfaceHandler::SSurfaceHandler(
      (SSurfaceHandler *)(this + 0xc));
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0xac) = 0;
  *(undefined4 *)(this + 0xa8) = 0;
  GmIso4::SetIdentity((GmIso4 *)(this + 0x70));
  *(undefined4 *)(this + 0xa0) = 0x3f800000;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 0xa4) = 0x3f800000;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0x3f800000;
  return this;
}
