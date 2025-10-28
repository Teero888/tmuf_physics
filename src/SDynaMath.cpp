
/* public: static void __cdecl SDynaMath::ComputeImpulse(float,class GmMat3
   const &,float,class GmVec3 const &,class GmVec3 const &,class GmVec3 const
   &,class GmVec3 &) */

void __cdecl SDynaMath::ComputeImpulse(float param_1, GmMat3 *param_2,
                                       float param_3, GmVec3 *param_4,
                                       GmVec3 *param_5, GmVec3 *param_6,
                                       GmVec3 *param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float local_18;
  float local_14;
  float local_10;

  local_18 = *(float *)(param_5 + 8) * *(float *)(param_6 + 4) -
             *(float *)(param_5 + 4) * *(float *)(param_6 + 8);
  local_14 = *(float *)param_5 * *(float *)(param_6 + 8) -
             *(float *)param_6 * *(float *)(param_5 + 8);
  local_10 = *(float *)(param_5 + 4) * *(float *)param_6 -
             *(float *)param_5 * *(float *)(param_6 + 4);
  GmVec3::Mult((GmVec3 *)&local_18, param_2);
  fVar1 = *(float *)(param_4 + 4);
  fVar2 = *(float *)(param_5 + 4);
  fVar3 = *(float *)param_4;
  fVar4 = *(float *)param_5;
  fVar5 = *(float *)(param_4 + 8);
  fVar6 = *(float *)(param_5 + 8);
  fVar7 = 1.0 / param_1 +
          (local_18 * *(float *)(param_6 + 4) - *(float *)param_6 * local_14) *
              *(float *)(param_5 + 8) +
          *(float *)(param_5 + 4) * (*(float *)param_6 * local_10 -
                                     local_18 * *(float *)(param_6 + 8)) +
          *(float *)param_5 * (*(float *)(param_6 + 8) * local_14 -
                               local_10 * *(float *)(param_6 + 4));
  fVar8 = ABS(fVar7);
  if (fVar8 < 1e-05 != NAN(fVar8)) {
    *(undefined4 *)(param_7 + 8) = 0;
    *(undefined4 *)(param_7 + 4) = 0;
    *(undefined4 *)param_7 = 0;
  }
  fVar7 = ((param_3 - 1.0) * (fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2)) /
          fVar7;
  *(float *)param_7 = fVar7 * *(float *)param_5;
  *(float *)(param_7 + 4) = *(float *)(param_5 + 4) * fVar7;
  *(float *)(param_7 + 8) = fVar7 * *(float *)(param_5 + 8);
  return;
}
