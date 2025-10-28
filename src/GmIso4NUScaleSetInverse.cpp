
/* public: void __thiscall GmIso4::NUScaleSetInverse(class GmIso4 const &) */

void __thiscall GmIso4::NUScaleSetInverse(GmIso4 *this, GmIso4 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;

  GmMat3::SetTranspose((GmMat3 *)this, (GmMat3 *)param_1);
  fVar1 = (*(float *)(this + 8) * *(float *)(this + 8) +
           *(float *)this * *(float *)this +
           *(float *)(this + 4) * *(float *)(this + 4)) /
          1.0;
  fVar2 = 1.0 / (*(float *)(this + 0x14) * *(float *)(this + 0x14) +
                 *(float *)(this + 0xc) * *(float *)(this + 0xc) +
                 *(float *)(this + 0x10) * *(float *)(this + 0x10));
  fVar3 = 1.0 / (*(float *)(this + 0x20) * *(float *)(this + 0x20) +
                 *(float *)(this + 0x18) * *(float *)(this + 0x18) +
                 *(float *)(this + 0x1c) * *(float *)(this + 0x1c));
  *(float *)this = fVar1 * *(float *)this;
  *(float *)(this + 4) = fVar1 * *(float *)(this + 4);
  *(float *)(this + 8) = fVar1 * *(float *)(this + 8);
  *(float *)(this + 0xc) = fVar2 * *(float *)(this + 0xc);
  *(float *)(this + 0x10) = *(float *)(this + 0x10) * fVar2;
  *(float *)(this + 0x14) = fVar2 * *(float *)(this + 0x14);
  *(float *)(this + 0x18) = fVar3 * *(float *)(this + 0x18);
  *(float *)(this + 0x1c) = *(float *)(this + 0x1c) * fVar3;
  *(float *)(this + 0x20) = fVar3 * *(float *)(this + 0x20);
  *(float *)(this + 0x24) = -*(float *)(param_1 + 0x24);
  *(float *)(this + 0x28) = -*(float *)(param_1 + 0x28);
  *(float *)(this + 0x2c) = -*(float *)(param_1 + 0x2c);
  GmVec3::Mult((GmVec3 *)(this + 0x24), (GmMat3 *)this);
  return;
}
