
/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall GmMat3::SetDOVandLeftV(class GmVec3 const &,class
 * GmVec3 const &) */

void __thiscall GmMat3::SetDOVandLeftV(GmMat3 *this, GmVec3 *param_1,
                                       GmVec3 *param_2)

{
  float fVar1;
  GmMat3 *this_00;
  float10 fVar2;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_24 = *(float *)(param_1 + 4) * *(float *)(param_2 + 8) -
             *(float *)(param_1 + 8) * *(float *)(param_2 + 4);
  local_20 = *(float *)(param_1 + 8) * *(float *)param_2 -
             *(float *)param_1 * *(float *)(param_2 + 8);
  local_1c = *(float *)param_1 * *(float *)(param_2 + 4) -
             *(float *)param_2 * *(float *)(param_1 + 4);
  fVar1 = local_1c * local_1c + local_24 * local_24 + local_20 * local_20;
  if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
    fVar2 = (float10)__CIsqrt();
    fVar1 = 1.0 / (float)fVar2;
    local_24 = fVar1 * local_24;
    local_20 = local_20 * fVar1;
    local_1c = fVar1 * local_1c;
  }
  local_18 = *(float *)param_1;
  local_14 = *(float *)(param_1 + 4);
  local_10 = *(float *)(param_1 + 8);
  fVar1 = local_14 * local_14 + local_18 * local_18 + local_10 * local_10;
  if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
    fVar2 = (float10)__CIsqrt();
    fVar1 = 1.0 / (float)fVar2;
    local_18 = fVar1 * local_18;
    local_14 = fVar1 * local_14;
    local_10 = fVar1 * local_10;
  }
  local_c = local_20 * local_10 - local_1c * local_14;
  local_8 = local_18 * local_1c - local_24 * local_10;
  local_4 = local_24 * local_14 - local_20 * local_18;
  SetLine(this, 0, (GmVec3 *)&local_c);
  SetLine(this, 1, (GmVec3 *)&local_24);
  SetLine(this_00, 2, (GmVec3 *)&local_18);
  return;
}
