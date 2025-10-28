
/* public: static int __cdecl GmVec3::DoesRayIntersectTriangle(class GmVec3
   const &,class GmVec3 const &,class GmVec3 const &,class GmVec3 const &,class
   GmVec3 const &,float &,float &,float &)
    */

int __cdecl GmVec3::DoesRayIntersectTriangle(GmVec3 *param_1, GmVec3 *param_2,
                                             GmVec3 *param_3, GmVec3 *param_4,
                                             GmVec3 *param_5, float *param_6,
                                             float *param_7, float *param_8)

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
  float fVar14;

  fVar3 = *(float *)param_4 - *(float *)param_3;
  fVar4 = *(float *)(param_4 + 4) - *(float *)(param_3 + 4);
  fVar5 = *(float *)(param_4 + 8) - *(float *)(param_3 + 8);
  fVar6 = *(float *)param_5 - *(float *)param_3;
  fVar7 = *(float *)(param_5 + 4) - *(float *)(param_3 + 4);
  fVar8 = *(float *)(param_5 + 8) - *(float *)(param_3 + 8);
  fVar2 = fVar8 * *(float *)(param_2 + 4) - fVar7 * *(float *)(param_2 + 8);
  fVar10 = fVar6 * *(float *)(param_2 + 8) - *(float *)param_2 * fVar8;
  fVar9 = *(float *)param_2 * fVar7 - fVar6 * *(float *)(param_2 + 4);
  fVar11 = fVar4 * fVar10 + fVar3 * fVar2 + fVar5 * fVar9;
  fVar1 = fVar5 * fVar5 + fVar3 * fVar3 + fVar4 * fVar4;
  if (fVar1 * 1e-05 * fVar1 <= fVar11 * fVar11) {
    fVar1 = (float)((uint)fVar11 & 0x7fffffff);
    fVar12 = *(float *)param_1 - *(float *)param_3;
    fVar13 = *(float *)(param_1 + 4) - *(float *)(param_3 + 4);
    fVar14 = *(float *)(param_1 + 8) - *(float *)(param_3 + 8);
    fVar2 = (float)((uint)(fVar14 * fVar9 + fVar12 * fVar2 + fVar13 * fVar10) ^
                    (uint)fVar11 & 0x80000000);
    if (fVar2 < 0.0 != NAN(fVar2)) {
      return 0;
    }
    if (fVar1 < fVar2 == (NAN(fVar1) || NAN(fVar2))) {
      fVar9 = fVar13 * fVar5 - fVar14 * fVar4;
      fVar5 = fVar14 * fVar3 - fVar12 * fVar5;
      fVar4 = fVar12 * fVar4 - fVar13 * fVar3;
      fVar3 = (float)((uint)(fVar9 * *(float *)param_2 +
                             fVar5 * *(float *)(param_2 + 4) +
                             fVar4 * *(float *)(param_2 + 8)) ^
                      (uint)fVar11 & 0x80000000);
      if (fVar3 < 0.0 != NAN(fVar3)) {
        return 0;
      }
      if (fVar1 < fVar2 + fVar3 == (NAN(fVar1) || NAN(fVar2 + fVar3))) {
        fVar1 = fVar1 / 1.0;
        *param_6 = fVar1 * fVar2;
        *param_7 = fVar1 * fVar3;
        *param_8 = fVar1 * (fVar4 * fVar8 + fVar7 * fVar5 + fVar6 * fVar9);
        *param_8 = (float)((uint)fVar11 & 0x80000000 ^ (uint)*param_8);
        return 1;
      }
      return 0;
    }
  }
  return 0;
}
