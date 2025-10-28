
/* public: void __thiscall GmIso4::GetPlaneEq(unsigned long,class GmVec4 &)const
 */

void __thiscall GmIso4::GetPlaneEq(GmIso4 *this, ulong param_1, GmVec4 *param_2)

{
  float local_c;
  float local_8;
  float local_4;

  GmMat3::GetLine((GmMat3 *)this, param_1, (GmVec3 *)&local_c);
  *(float *)param_2 = local_c;
  *(float *)(param_2 + 4) = local_8;
  *(float *)(param_2 + 8) = local_4;
  *(float *)(param_2 + 0xc) =
      (-local_c * *(float *)(this + 0x24) - *(float *)(this + 0x28) * local_8) -
      *(float *)(this + 0x2c) * local_4;
  return;
}
