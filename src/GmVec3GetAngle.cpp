
/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: static float __cdecl GmVec3::GetAngle(class GmVec3 const &,class
 * GmVec3 const &) */

float __cdecl GmVec3::GetAngle(GmVec3 *param_1, GmVec3 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  float local_18;
  float local_14;
  float local_10;

  fVar6 = (float10)__CIacos();
  fVar1 = (float)fVar6;
  if (1e-05 < fVar1) {
    local_18 = *(float *)param_1;
    local_14 = *(float *)(param_1 + 4);
    local_10 = *(float *)(param_1 + 8);
    fVar2 = local_10 * local_10 + local_18 * local_18 + local_14 * local_14;
    if (_DAT_00d1a8f0 < fVar2 != (NAN(_DAT_00d1a8f0) || NAN(fVar2))) {
      fVar6 = (float10)__CIsqrt();
      fVar2 = 1.0 / (float)fVar6;
      local_18 = fVar2 * local_18;
      local_14 = local_14 * fVar2;
      local_10 = fVar2 * local_10;
    }
    fVar2 = *(float *)param_2;
    fVar3 = *(float *)(param_2 + 4);
    fVar4 = *(float *)(param_2 + 8);
    fVar5 = fVar3 * fVar3 + fVar2 * fVar2 + fVar4 * fVar4;
    if (_DAT_00d1a8f0 < fVar5 != (NAN(_DAT_00d1a8f0) || NAN(fVar5))) {
      fVar6 = (float10)__CIsqrt();
      fVar5 = 1.0 / (float)fVar6;
      fVar2 = fVar5 * fVar2;
      fVar3 = fVar5 * fVar3;
      fVar4 = fVar5 * fVar4;
    }
    fVar2 = (fVar3 * local_18 - local_14 * fVar2) * 0.0 +
            (local_10 * fVar2 - local_18 * fVar4) +
            (fVar4 * local_14 - local_10 * fVar3) * 0.0;
    if (fVar2 < 0.0 != NAN(fVar2)) {
      fVar1 = -fVar1;
    }
  }
  return fVar1;
}
