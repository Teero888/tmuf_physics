
/* public: void __thiscall GmIso4::UScaleSetInverse(class GmIso4 const &) */

void __thiscall GmIso4::UScaleSetInverse(GmIso4 *this, GmIso4 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;

  fVar1 = *(float *)(param_1 + 4);
  fVar2 = *(float *)param_1;
  fVar3 = *(float *)(param_1 + 8);
  GmMat3::SetTranspose((GmMat3 *)this, (GmMat3 *)param_1);
  GmMat3::Mult((GmMat3 *)this,
               1.0 / (fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1));
  *(float *)(this + 0x24) = -*(float *)(param_1 + 0x24);
  *(float *)(this + 0x28) = -*(float *)(param_1 + 0x28);
  *(float *)(this + 0x2c) = -*(float *)(param_1 + 0x2c);
  GmVec3::Mult((GmVec3 *)(this + 0x24), (GmMat3 *)this);
  return;
}
