// Class implementation: SSysGraphicPerformance

// =================================================
// Function: SSysGraphicPerformance::UpdateCpuDependant
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
SSysGraphicPerformance::UpdateCpuDependant(void *this,SSysGraphicPerformance *param_1)
{
{
  float fVar1;
  float fVar2;
  
  if (DAT_00d542b8 == 0) {
    fVar1 = (float)DAT_00d54238;
    if (DAT_00d54238 < 0) {
      fVar1 = fVar1 + _DAT_00c418d0;
    }
    fVar2 = _DAT_00b32ea8;
    if (DAT_00ccb5e0 < 2) {
      fVar2 = 1.0;
    }
    fVar1 = fVar2 * (fVar1 / (float)_DAT_00c418d8) * (float)_DAT_00b32ea0;
    if (fVar1 < 0.0 != (fVar1 == 0.0)) {
      *(undefined4 *)this = 0;
      return;
    }
    if ((float)_DAT_00b2f748 <= fVar1) {
      fVar1 = _DAT_00b32e98;
    }
    *(float *)this = fVar1;
  }
  return;
}
}

