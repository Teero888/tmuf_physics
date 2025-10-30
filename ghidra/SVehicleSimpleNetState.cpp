
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

/* public: void __thiscall SVehicleSimpleNetState::SaveToStruct(struct
   CSceneVehicleCar::SVehicleCarState const &,float,unsigned long,int,struct
   CSceneVehicleCar::SSimulationWheel::SState const &,int,struct
   CSceneVehicleCar::SSimulationWheel::SState const &,int,struct
   CSceneVehicleCar::SSimulationWheel::SState const &,int,struct
   CSceneVehicleCar::SSimulationWheel::SState const &,int) */

void __thiscall SVehicleSimpleNetState::SaveToStruct(
    SVehicleSimpleNetState *this, SVehicleCarState *param_1, float param_2,
    ulong param_3, int param_4, SState *param_5, int param_6, SState *param_7,
    int param_8, SState *param_9, int param_10, SState *param_11, int param_12)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  uchar uVar4;
  SVehicleSimpleNetState SVar5;
  float10 fVar6;
  float fVar7;
  float fVar8;

  sVar1 = *(short *)(param_5 + 0xc);
  if (((((sVar1 == 0) || (sVar1 == 0x10)) || (sVar1 == 0x13)) &&
       (*(int *)(param_5 + 0x10) != 0)) &&
      ((*(int *)(param_5 + 0x14) != 0 ||
        ((*(int *)(param_1 + 0x1c) != 0 && (param_6 == 0)))))) {
    bVar2 = 1;
  } else {
    bVar2 = 0;
  }
  *this = (SVehicleSimpleNetState)((byte) * this ^ ((byte) * this ^ bVar2) & 1);
  sVar1 = *(short *)(param_7 + 0xc);
  if (((((sVar1 == 0) || (sVar1 == 0x10)) || (sVar1 == 0x13)) &&
       (*(int *)(param_7 + 0x10) != 0)) &&
      ((*(int *)(param_7 + 0x14) != 0 ||
        ((*(int *)(param_1 + 0x1c) != 0 && (param_8 == 0)))))) {
    cVar3 = '\x01';
  } else {
    cVar3 = '\0';
  }
  SVar5 = (SVehicleSimpleNetState)((cVar3 * '\x02' ^ (byte) * this) & 2 ^
                                   (byte) * this);
  *this = SVar5;
  sVar1 = *(short *)(param_9 + 0xc);
  if ((((sVar1 == 0) || (sVar1 == 0x10)) || (sVar1 == 0x13)) &&
      ((*(int *)(param_9 + 0x10) != 0 &&
        ((*(int *)(param_9 + 0x14) != 0 ||
          ((*(int *)(param_1 + 0x1c) != 0 && (param_10 == 0)))))))) {
    cVar3 = '\x01';
  } else {
    cVar3 = '\0';
  }
  SVar5 = (SVehicleSimpleNetState)((cVar3 * '\x04' ^ (byte)SVar5) & 4 ^
                                   (byte)SVar5);
  *this = SVar5;
  sVar1 = *(short *)(param_11 + 0xc);
  if ((((sVar1 == 0) || (sVar1 == 0x10)) || (sVar1 == 0x13)) &&
      ((*(int *)(param_11 + 0x10) != 0 &&
        ((*(int *)(param_11 + 0x14) != 0 ||
          ((*(int *)(param_1 + 0x1c) != 0 && (param_12 == 0)))))))) {
    cVar3 = '\x01';
  } else {
    cVar3 = '\0';
  }
  SVar5 =
      (SVehicleSimpleNetState)((cVar3 << 3 ^ (byte)SVar5) & 8 ^ (byte)SVar5);
  *this = SVar5;
  fVar8 = 1.0;
  *this =
      (SVehicleSimpleNetState)(((char)param_1[100] << 4 ^ (byte)SVar5) & 0x30 ^
                               (byte)SVar5);
  fVar7 = 0.0;
  fVar6 = (float10)__CIpow();
  uVar4 = GmFunc::RealToNat7((float)fVar6, fVar7, fVar8);
  *this = (SVehicleSimpleNetState)((byte) * this & 0x3f | (char)param_3 << 6);
  this[1] = (SVehicleSimpleNetState)(param_4 != 0 ^ uVar4 * '\x02');
  return;
}
