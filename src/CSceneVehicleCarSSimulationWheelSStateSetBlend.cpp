
/* public: void __thiscall
   CSceneVehicleCar::SSimulationWheel::SState::SetBlend(struct
   CSceneVehicleCar::SSimulationWheel::SState const &,struct
   CSceneVehicleCar::SSimulationWheel::SState const &,float) */

void __thiscall CSceneVehicleCar::SSimulationWheel::SState::SetBlend(
    SState *this, SState *param_1, SState *param_2, float param_3)

{
  float fVar1;
  SState *pSVar2;
  SState *pSVar3;
  undefined4 uVar4;

  pSVar3 = param_2;
  pSVar2 = param_1;
  fVar1 = 1.0 - param_3;
  *(float *)this = *(float *)param_1 * fVar1 + *(float *)param_2 * param_3;
  param_1 = *(SState **)(param_1 + 4);
  param_2 = *(SState **)(param_2 + 4);
  OrderWindowedValues((float *)&param_1, (float *)&param_2, 1608.495);
  *(float *)(this + 4) = fVar1 * (float)param_1 + param_3 * (float)param_2;
  *(float *)(this + 8) =
      fVar1 * *(float *)(pSVar2 + 8) + *(float *)(pSVar3 + 8) * param_3;
  if ((*(int *)(pSVar2 + 0x10) == 0) || (*(int *)(pSVar3 + 0x10) == 0)) {
    uVar4 = 0;
  } else {
    uVar4 = 1;
  }
  *(undefined4 *)(this + 0x10) = uVar4;
  *(undefined2 *)(this + 0xc) = *(undefined2 *)(pSVar2 + 0xc);
  if ((*(int *)(pSVar2 + 0x14) != 0) && (*(int *)(pSVar3 + 0x14) != 0)) {
    *(undefined4 *)(this + 0x14) = 1;
    return;
  }
  *(undefined4 *)(this + 0x14) = 0;
  return;
}
