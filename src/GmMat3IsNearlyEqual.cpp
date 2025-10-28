
/* public: unsigned long __thiscall GmMat3::IsNearlyEqual(class GmMat3 const
 * &)const  */

ulong __thiscall GmMat3::IsNearlyEqual(GmMat3 *this, GmMat3 *param_1)

{
  ulong uVar1;

  uVar1 = GmVec3::IsNearlyEqual((GmVec3 *)this, (GmVec3 *)param_1);
  if (uVar1 != 0) {
    uVar1 = GmVec3::IsNearlyEqual((GmVec3 *)(this + 0xc),
                                  (GmVec3 *)(param_1 + 0xc));
    if (uVar1 != 0) {
      uVar1 = GmVec3::IsNearlyEqual((GmVec3 *)(this + 0x18),
                                    (GmVec3 *)(param_1 + 0x18));
      if (uVar1 != 0) {
        return 1;
      }
    }
  }
  return 0;
}
