
/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall GmMat3::SetDOV(class GmVec3 const &,unsigned long) */

void __thiscall GmMat3::SetDOV(GmMat3 *this, GmVec3 *param_1, ulong param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  GmMat3 *this_00;
  GmMat3 *this_01;
  float10 fVar4;
  undefined8 local_24;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_c = 0.0;
  local_8 = 1.0;
  local_4 = 0.0;
  local_18 = *(float *)(param_1 + 8) - *(float *)(param_1 + 4) * 0.0;
  fVar1 = *(float *)param_1 * 0.0;
  local_14 = fVar1 - *(float *)(param_1 + 8) * 0.0;
  local_10 = *(float *)(param_1 + 4) * 0.0 - *(float *)param_1;
  if (param_2 == 0) {
    if (_DAT_00d1a840 <=
        local_10 * local_10 + local_18 * local_18 + local_14 * local_14) {
      SetDOVandUpV(this, param_1, (GmVec3 *)&local_c);
      return;
    }
    local_c = 1.0;
    local_8 = 0.0;
    local_4 = 0.0;
    SetDOVandUpV(this, param_1, (GmVec3 *)&local_c);
    return;
  }
  fVar2 = *(float *)(param_1 + 8) * 0.0 - *(float *)(param_1 + 4) * 0.0;
  local_1c = *(float *)(param_1 + 4) - fVar1;
  local_24 = (double)local_1c;
  fVar3 = local_18 * local_18 + local_14 * local_14 + local_10 * local_10;
  fVar2 = local_1c * local_1c + fVar2 * fVar2 +
          (fVar1 - *(float *)(param_1 + 8)) * (fVar1 - *(float *)(param_1 + 8));
  if (fVar2 < fVar3 == (NAN(fVar2) || NAN(fVar3))) {
    local_24._0_4_ =
        *(float *)(param_1 + 4) * 0.0 - *(float *)(param_1 + 8) * 0.0;
    local_24._4_4_ = *(float *)(param_1 + 8) - fVar1;
    local_1c = fVar1 - *(float *)(param_1 + 4);
    fVar1 = local_1c * local_1c + (float)local_24 * (float)local_24 +
            local_24._4_4_ * local_24._4_4_;
    if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
      fVar4 = (float10)__CIsqrt();
      fVar1 = 1.0 / (float)fVar4;
      local_24._0_4_ = fVar1 * (float)local_24;
      local_24._4_4_ = local_24._4_4_ * fVar1;
      local_1c = fVar1 * local_1c;
    }
    local_14 = *(float *)(param_1 + 4);
    local_18 = *(float *)param_1;
    local_10 = *(float *)(param_1 + 8);
    fVar1 = local_18 * local_18 + local_14 * local_14 + local_10 * local_10;
    if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
      fVar4 = (float10)__CIsqrt();
      fVar1 = 1.0 / (float)fVar4;
      local_18 = fVar1 * local_18;
      local_14 = local_14 * fVar1;
      local_10 = fVar1 * local_10;
    }
    local_c = local_24._4_4_ * local_10 - local_1c * local_14;
    local_8 = local_18 * local_1c - (float)local_24 * local_10;
    local_4 = (float)local_24 * local_14 - local_18 * local_24._4_4_;
    SetLine(this, 0, (GmVec3 *)&local_c);
    SetLine(this_00, 1, (GmVec3 *)&local_24);
    SetLine(this_01, 2, (GmVec3 *)&local_18);
    return;
  }
  SetDOVandUpV(this, param_1, (GmVec3 *)&local_c);
  return;
}
