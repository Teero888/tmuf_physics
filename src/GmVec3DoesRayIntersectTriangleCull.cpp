
/* public: static int __cdecl GmVec3::DoesRayIntersectTriangleCull(class GmVec3
   const &,class GmVec3 const &,class GmVec3 const &,class GmVec3 const &,class
   GmVec3 const &,float &,float &,float &)
    */

int __cdecl GmVec3::DoesRayIntersectTriangleCull(
    GmVec3 *param_1, GmVec3 *param_2, GmVec3 *param_3, GmVec3 *param_4,
    GmVec3 *param_5, float *param_6, float *param_7, float *param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;

  fVar1 = *(float *)param_4 - *(float *)param_3;
  fVar2 = *(float *)(param_4 + 4) - *(float *)(param_3 + 4);
  fVar3 = *(float *)(param_4 + 8) - *(float *)(param_3 + 8);
  fVar4 = *(float *)param_5 - *(float *)param_3;
  fVar5 = *(float *)(param_5 + 4) - *(float *)(param_3 + 4);
  fVar6 = *(float *)(param_5 + 8) - *(float *)(param_3 + 8);
  fVar7 = fVar6 * *(float *)(param_2 + 4) - fVar5 * *(float *)(param_2 + 8);
  fVar9 = fVar4 * *(float *)(param_2 + 8) - *(float *)param_2 * fVar6;
  fVar8 = *(float *)param_2 * fVar5 - fVar4 * *(float *)(param_2 + 4);
  fVar10 = fVar2 * fVar9 + fVar1 * fVar7 + fVar3 * fVar8;
  if (fVar10 < 0.0 != NAN(fVar10)) {
    return 0;
  }
  fVar11 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (fVar11 * 1e-05 * fVar11 <= fVar10 * fVar10) {
    fVar11 = *(float *)param_1 - *(float *)param_3;
    fVar12 = *(float *)(param_1 + 4) - *(float *)(param_3 + 4);
    fVar13 = *(float *)(param_1 + 8) - *(float *)(param_3 + 8);
    fVar7 = fVar13 * fVar8 + fVar11 * fVar7 + fVar12 * fVar9;
    if (fVar7 < 0.0 != NAN(fVar7)) {
      return 0;
    }
    if (fVar10 < fVar7 != (NAN(fVar10) || NAN(fVar7))) {
      return 0;
    }
    fVar8 = fVar12 * fVar3 - fVar13 * fVar2;
    fVar3 = fVar13 * fVar1 - fVar11 * fVar3;
    fVar1 = fVar11 * fVar2 - fVar12 * fVar1;
    fVar2 = fVar8 * *(float *)param_2 + fVar3 * *(float *)(param_2 + 4) +
            fVar1 * *(float *)(param_2 + 8);
    if (fVar2 < 0.0 == NAN(fVar2)) {
      if (fVar10 < fVar7 + fVar2 != (NAN(fVar10) || NAN(fVar7 + fVar2))) {
        return 0;
      }
      fVar10 = fVar10 / 1.0;
      *param_6 = fVar10 * fVar7;
      *param_7 = fVar10 * fVar2;
      *param_8 = fVar10 * (fVar1 * fVar6 + fVar5 * fVar3 + fVar4 * fVar8);
      return 1;
    }
  }
  return 0;
}
