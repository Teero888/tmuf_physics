
/* public: void __thiscall GmVec3::MultTranspose(class GmMat3 const &) */

void __thiscall GmVec3::MultTranspose(GmVec3 *this, GmMat3 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;

  fVar1 = *(float *)this;
  fVar2 = *(float *)(this + 4);
  fVar3 = *(float *)(this + 8);
  *(float *)this = fVar2 * *(float *)(param_1 + 0xc) +
                   fVar1 * *(float *)param_1 +
                   fVar3 * *(float *)(param_1 + 0x18);
  *(float *)(this + 4) = *(float *)(param_1 + 0x1c) * fVar3 +
                         *(float *)(param_1 + 0x10) * fVar2 +
                         *(float *)(param_1 + 4) * fVar1;
  *(float *)(this + 8) = *(float *)(param_1 + 8) * fVar1 +
                         *(float *)(param_1 + 0x14) * fVar2 +
                         *(float *)(param_1 + 0x20) * fVar3;
  return;
}
