
/* public: unsigned long __thiscall GmIso4::IsNearlyEqual(class GmIso4 const
 * &)const  */

ulong __thiscall GmIso4::IsNearlyEqual(GmIso4 *this, GmIso4 *param_1)

{
  ulong uVar1;

  uVar1 = GmVec3::IsNearlyEqual((GmVec3 *)(this + 0x24),
                                (GmVec3 *)(param_1 + 0x24));
  if (uVar1 != 0) {
    uVar1 = GmMat3::IsNearlyEqual((GmMat3 *)this, (GmMat3 *)param_1);
    if (uVar1 != 0) {
      return 1;
    }
  }
  return 0;
}
