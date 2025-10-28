
/* public: void __thiscall CSceneVehicleStruct::SSimulationWheel::Reset(void) */

void __thiscall CSceneVehicleStruct::SSimulationWheel::Reset(
    SSimulationWheel *this)

{
  int extraout_ECX;

  SSurfaceId::Reset((SSurfaceId *)this);
  *(undefined4 *)(extraout_ECX + 4) = 0;
  *(undefined4 *)(extraout_ECX + 8) = 0;
  return;
}
