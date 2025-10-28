
/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall
 * CSceneVehicleCar::SSimulationWheel::SRealTimeState::Integrate(float) */

void __thiscall CSceneVehicleCar::SSimulationWheel::SRealTimeState::Integrate(
    SRealTimeState *this, float param_1)

{
  float *pfVar1;
  float10 fVar2;
  float fVar3;
  float local_c;
  float local_8;
  float local_4;

  fVar3 =
      GmFunc::Mod(*(float *)(this + 0x6c) * param_1 + *(float *)(this + 0x9c),
                  0.0, 1608.495);
  *(float *)(this + 0x9c) = fVar3;
  pfVar1 = (float *)(this + 0x90);
  fVar3 = *(float *)(this + 0x98) * *(float *)(this + 0x98) +
          *pfVar1 * *pfVar1 + *(float *)(this + 0x94) * *(float *)(this + 0x94);
  if (_DAT_00d06a80 < fVar3 != (NAN(_DAT_00d06a80) || NAN(fVar3))) {
    fVar2 = (float10)__CIsqrt();
    fVar3 = 1.0 / (float)fVar2;
    *pfVar1 = fVar3 * *pfVar1;
    *(float *)(this + 0x94) = *(float *)(this + 0x94) * fVar3;
    *(float *)(this + 0x98) = fVar3 * *(float *)(this + 0x98);
    local_c = *(float *)(this + 0x98) * 0.0 - *(float *)(this + 0x94) * 0.0;
    local_8 = *pfVar1 * 0.0 - *(float *)(this + 0x98);
    local_4 = *(float *)(this + 0x94) - *pfVar1 * 0.0;
    GmMat3::SetUpVandDOV((GmMat3 *)(this + 0x30), (GmVec3 *)pfVar1,
                         (GmVec3 *)&local_c);
  }
  if (*(float *)(this + 0xa4) <= *(float *)(this + 0xa0)) {
    fVar3 = *(float *)(this + 0xa0) - param_1;
    *(float *)(this + 0xa0) = fVar3;
    if (fVar3 < *(float *)(this + 0xa4)) {
      *(undefined4 *)(this + 0xa0) = *(undefined4 *)(this + 0xa4);
    }
  } else {
    fVar3 = *(float *)(this + 0xa0) + param_1;
    *(float *)(this + 0xa0) = fVar3;
    if (*(float *)(this + 0xa4) < fVar3 !=
        (NAN(*(float *)(this + 0xa4)) || NAN(fVar3))) {
      *(undefined4 *)(this + 0xa0) = *(undefined4 *)(this + 0xa4);
      return;
    }
  }
  return;
}
