
/* protected: void __thiscall
   CSceneVehicleCar::WheelUpdateSpeedFromVehicleSpeed(struct
   CSceneVehicleCar::SSimulationWheel &,float,float) */

void __thiscall CSceneVehicleCar::WheelUpdateSpeedFromVehicleSpeed(
    CSceneVehicleCar *this, SSimulationWheel *param_1, float param_2,
    float param_3)

{
  float fVar1;
  SSimulationWheel *pSVar2;
  int *piVar3;

  pSVar2 = param_1;
  if (*(int *)(param_1 + 0x124) != 0) {
    if ((*(int *)(this + 0x6a0) != 0) && (*(int *)(this + 0x73c) == 0)) {
      piVar3 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(*(int *)(this + 100) + 0x14),
          *(ulong *)(*(int *)(this + 100) + 0x24));
      *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(*piVar3 + 700);
      return;
    }
    *(float *)(param_1 + 0x120) = param_2 / *(float *)(param_1 + 8);
    return;
  }
  param_2 = 0.0;
  param_1 = (SSimulationWheel *)0x0;
  if (1e-05 < *(float *)(this + 0x54) == NAN(*(float *)(this + 0x54))) {
    if (((1e-05 < *(float *)(this + 0x50) == NAN(*(float *)(this + 0x50))) ||
         (*(int *)(this + 0x73c) != 0)) ||
        (*(int *)(this + 0x60c) != 0)) {
      *(float *)(pSVar2 + 0x120) = *(float *)(pSVar2 + 0x120) * 0.995;
    } else {
      param_1 = (SSimulationWheel *)(*(float *)(this + 0x50) * 200.0);
      param_2 = 100.0;
    }
  } else {
    param_1 = (SSimulationWheel *)(1.0 - *(float *)(this + 0x54));
    if ((float)param_1 < 0.0 == ((float)param_1 == 0.0)) {
      if (1.0 < (float)param_1 == ((float)param_1 == 1.0)) {
        param_2 = -100.0;
      } else {
        param_1 = (SSimulationWheel *)&DAT_3f800000;
        param_2 = -100.0;
      }
    } else {
      param_1 = (SSimulationWheel *)0x0;
      param_2 = -100.0;
    }
  }
  if (ABS(param_2) < 1e-05 == NAN(ABS(param_2))) {
    fVar1 = param_2 * param_3 + *(float *)(pSVar2 + 0x120);
    *(float *)(pSVar2 + 0x120) = fVar1;
    if ((0.0 < param_2) &&
        ((float)param_1 < fVar1 != (NAN((float)param_1) || NAN(fVar1)))) {
      *(SSimulationWheel **)(pSVar2 + 0x120) = param_1;
      return;
    }
    if ((param_2 < 0.0 != NAN(param_2)) && (fVar1 < (float)param_1)) {
      *(SSimulationWheel **)(pSVar2 + 0x120) = param_1;
      return;
    }
  }
  return;
}
