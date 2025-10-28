
/* public: void __thiscall SVehicleSimpleNetState::RestoreFromStruct(struct
   CSceneVehicleCar::SVehicleCarState &,float,struct
   CSceneVehicleCar::SSimulationWheel::SState
   &,struct CSceneVehicleCar::SSimulationWheel::SState &,struct
   CSceneVehicleCar::SSimulationWheel::SState &,struct
   CSceneVehicleCar::SSimulationWheel::SState &)
    */

void __thiscall SVehicleSimpleNetState::RestoreFromStruct(
    SVehicleSimpleNetState *this, SVehicleCarState *param_1, float param_2,
    SState *param_3, SState *param_4, SState *param_5, SState *param_6)

{
  SVehicleSimpleNetState SVar1;
  float10 fVar2;

  SVar1 = *this;
  *(undefined2 *)(param_3 + 0xc) = 0x10;
  if (((byte)SVar1 & 1) == 0) {
    *(undefined4 *)(param_3 + 0x14) = 0;
    *(undefined4 *)(param_3 + 0x10) = 0;
  } else {
    *(undefined4 *)(param_3 + 0x14) = 1;
    *(undefined4 *)(param_3 + 0x10) = 1;
  }
  SVar1 = *this;
  *(undefined2 *)(param_4 + 0xc) = 0x10;
  if (((byte)SVar1 & 2) == 0) {
    *(undefined4 *)(param_4 + 0x14) = 0;
    *(undefined4 *)(param_4 + 0x10) = 0;
  } else {
    *(undefined4 *)(param_4 + 0x14) = 1;
    *(undefined4 *)(param_4 + 0x10) = 1;
  }
  SVar1 = *this;
  *(undefined2 *)(param_5 + 0xc) = 0x10;
  if (((byte)SVar1 & 4) == 0) {
    *(undefined4 *)(param_5 + 0x14) = 0;
    *(undefined4 *)(param_5 + 0x10) = 0;
  } else {
    *(undefined4 *)(param_5 + 0x14) = 1;
    *(undefined4 *)(param_5 + 0x10) = 1;
  }
  SVar1 = *this;
  *(undefined2 *)(param_6 + 0xc) = 0x10;
  if (((byte)SVar1 & 8) == 0) {
    *(undefined4 *)(param_6 + 0x14) = 0;
    *(undefined4 *)(param_6 + 0x10) = 0;
  } else {
    *(undefined4 *)(param_6 + 0x14) = 1;
    *(undefined4 *)(param_6 + 0x10) = 1;
  }
  *(uint *)(param_1 + 100) = (byte) * this >> 4 & 3;
  fVar2 = (float10)__CIpow();
  *(float *)(param_1 + 0x80) = (float)fVar2 * param_2;
  return;
}
