
/* public: unsigned long __thiscall GmMat3::IsOrthonormal(void)const  */

ulong __thiscall GmMat3::IsOrthonormal(GmMat3 *this)

{
  ulong uVar1;
  float10 fVar2;

  fVar2 = (float10)__CIsqrt();
  if (ABS((float)fVar2 - 1.0) < 0.001 != NAN(ABS((float)fVar2 - 1.0))) {
    fVar2 = (float10)__CIsqrt();
    if (ABS((float)fVar2 - 1.0) < 0.001 != NAN(ABS((float)fVar2 - 1.0))) {
      fVar2 = (float10)__CIsqrt();
      if (ABS((float)fVar2 - 1.0) < 0.001 != NAN(ABS((float)fVar2 - 1.0))) {
        uVar1 = IsOrthogonal(this);
        if (uVar1 != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}
