
/* public: void __thiscall GmMat3::SetBlend(class GmMat3 const &,class GmMat3
 * const &,float) */

void __thiscall GmMat3::SetBlend(GmMat3 *this, GmMat3 *param_1, GmMat3 *param_2,
                                 float param_3)

{
  ulong uVar1;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10[4];

  GmQuat::Set((GmQuat *)&local_30, param_1);
  GmQuat::Set((GmQuat *)local_10, param_2);
  GmQuat::SetSlerp((GmQuat *)&local_20, local_30, local_2c, local_28, local_24,
                   local_10, param_3);
  if ((((ABS(local_2c - local_1c) < 1e-05) &&
        (ABS(local_28 - local_18) < 1e-05 != NAN(ABS(local_28 - local_18)))) &&
       (ABS(local_24 - local_14) < 1e-05 != NAN(ABS(local_24 - local_14)))) &&
      (uVar1 = GmFunc::AreNearlyEqual(local_30, local_20, 1e-05), uVar1 != 0)) {
    Set(this, param_1);
    return;
  }
  Set(this, local_20, local_1c, local_18, local_14);
  return;
}
