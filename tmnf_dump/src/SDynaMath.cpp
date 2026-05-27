// Class implementation: SDynaMath

// =================================================
// Function: SDynaMath::ComputeImpulse
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
SDynaMath::ComputeImpulse
          (void *this,CSceneVehicleSpeedBoat *param_1,float param_2,GmMat3 *param_3,float param_4,
          GmVec3 *param_5,GmVec3 *param_6,GmVec3 *param_7,GmVec3 *param_8)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  GmIso3 *unaff_EDI;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  local_18 = *(float *)(param_5 + 8) * *(float *)(param_6 + 4) -
             *(float *)(param_5 + 4) * *(float *)(param_6 + 8);
  local_14 = *(float *)param_5 * *(float *)(param_6 + 8) -
             *(float *)param_6 * *(float *)(param_5 + 8);
  local_10 = *(float *)(param_5 + 4) * *(float *)param_6 -
             *(float *)param_5 * *(float *)(param_6 + 4);
  GmVec3::Mult(&local_18,(GmIso3 *)param_2,unaff_EDI);
  fVar1 = *(float *)(param_5 + 4);
  fVar2 = *(float *)(param_5 + 4);
  fVar3 = *(float *)param_5;
  fVar4 = *(float *)param_5;
  fVar5 = *(float *)(param_5 + 8);
  fVar6 = *(float *)(param_5 + 8);
  fVar7 = 1.0 / param_2 +
          (local_14 * *(float *)(param_6 + 4) - *(float *)param_6 * local_10) *
          *(float *)(param_5 + 8) +
          *(float *)(param_5 + 4) *
          (*(float *)param_6 * local_c - local_14 * *(float *)(param_6 + 8)) +
          *(float *)param_5 *
          (*(float *)(param_6 + 8) * local_10 - local_c * *(float *)(param_6 + 4));
  if (ABS(fVar7) < _DAT_00b9ef4c) {
    *(undefined4 *)(param_8 + 8) = 0;
    *(undefined4 *)(param_8 + 4) = 0;
    *(undefined4 *)param_8 = 0;
  }
  fVar7 = ((param_4 - 1.0) * (fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2)) / fVar7;
  *(float *)param_8 = fVar7 * *(float *)param_5;
  *(float *)(param_8 + 4) = *(float *)(param_5 + 4) * fVar7;
  *(float *)(param_8 + 8) = fVar7 * *(float *)(param_5 + 8);
  return;
}
}

