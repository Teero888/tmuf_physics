
/* public: void __thiscall GmIso4::SetBlend(class GmIso4 const &,class GmIso4
 * const &,float) */

void __thiscall GmIso4::SetBlend(GmIso4 *this, GmIso4 *param_1, GmIso4 *param_2,
                                 float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;

  *(float *)(this + 0x24) =
      *(float *)(param_2 + 0x24) - *(float *)(param_1 + 0x24);
  *(float *)(this + 0x28) =
      *(float *)(param_2 + 0x28) - *(float *)(param_1 + 0x28);
  *(float *)(this + 0x2c) =
      *(float *)(param_2 + 0x2c) - *(float *)(param_1 + 0x2c);
  fVar1 = *(float *)(this + 0x24);
  *(float *)(this + 0x24) = param_3 * fVar1;
  fVar2 = *(float *)(this + 0x28);
  *(float *)(this + 0x28) = fVar2 * param_3;
  fVar3 = *(float *)(this + 0x2c);
  *(float *)(this + 0x2c) = fVar3 * param_3;
  *(float *)(this + 0x24) = *(float *)(param_1 + 0x24) + param_3 * fVar1;
  *(float *)(this + 0x28) = fVar2 * param_3 + *(float *)(param_1 + 0x28);
  *(float *)(this + 0x2c) = fVar3 * param_3 + *(float *)(param_1 + 0x2c);
  GmMat3::SetBlend((GmMat3 *)this, (GmMat3 *)param_1, (GmMat3 *)param_2,
                   param_3);
  return;
}
