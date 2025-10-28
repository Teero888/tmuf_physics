
/* public: void __thiscall GmVec3::SetMultTranspose(class GmVec3 const &,class
 * GmMat3 const &) */

void __thiscall GmVec3::SetMultTranspose(GmVec3 *this, GmVec3 *param_1,
                                         GmMat3 *param_2)

{
  *(float *)this = *(float *)(param_2 + 0x18) * *(float *)(param_1 + 8) +
                   *(float *)param_1 * *(float *)param_2 +
                   *(float *)(param_2 + 0xc) * *(float *)(param_1 + 4);
  *(float *)(this + 4) = *(float *)(param_2 + 0x1c) * *(float *)(param_1 + 8) +
                         *(float *)(param_2 + 0x10) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 4) * *(float *)param_1;
  *(float *)(this + 8) = *(float *)(param_2 + 0x20) * *(float *)(param_1 + 8) +
                         *(float *)(param_2 + 0x14) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 8) * *(float *)param_1;
  return;
}
