
/* public: unsigned long __thiscall GmVec3::IsNearlyEqual(class GmVec3 const
 * &)const  */

ulong __thiscall GmVec3::IsNearlyEqual(GmVec3 *this, GmVec3 *param_1)

{
  float fVar1;

  fVar1 = *(float *)param_1 - ABS(*(float *)param_1) * 1e-05;
  if (fVar1 < *(float *)this == (fVar1 == *(float *)this)) {
    return 0;
  }
  fVar1 = *(float *)param_1 + ABS(*(float *)param_1) * 1e-05;
  if ((((*(float *)this < fVar1 != (*(float *)this == fVar1)) &&
        (fVar1 = *(float *)(param_1 + 4) - ABS(*(float *)(param_1 + 4)) * 1e-05,
         fVar1 < *(float *)(this + 4) != (fVar1 == *(float *)(this + 4)))) &&
       (fVar1 = *(float *)(param_1 + 4) + ABS(*(float *)(param_1 + 4)) * 1e-05,
        *(float *)(this + 4) < fVar1 != (*(float *)(this + 4) == fVar1))) &&
      ((fVar1 = *(float *)(param_1 + 8) - ABS(*(float *)(param_1 + 8)) * 1e-05,
        fVar1 < *(float *)(this + 8) != (fVar1 == *(float *)(this + 8)) &&
            (fVar1 =
                 *(float *)(param_1 + 8) + ABS(*(float *)(param_1 + 8)) * 1e-05,
             *(float *)(this + 8) < fVar1 !=
                 (*(float *)(this + 8) == fVar1))))) {
    return 1;
  }
  return 0;
}
