
/* public: void __thiscall GmMat3::RotateZ(float) */

void __thiscall GmMat3::RotateZ(GmMat3 *this, float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 *extraout_ECX;
  undefined4 in_EDX;
  undefined4 extraout_EDX;
  float10 fVar5;

  fVar5 = (float10)__CIsin((float10 *)this, in_EDX);
  fVar1 = (float)fVar5;
  fVar5 = (float10)__CIcos(extraout_ECX, extraout_EDX);
  fVar2 = (float)fVar5;
  fVar4 = -fVar1;
  fVar3 = *(float *)this;
  *(float *)this = fVar4 * *(float *)(this + 0xc) + fVar2 * fVar3;
  *(float *)(this + 0xc) = *(float *)(this + 0xc) * fVar2 + fVar1 * fVar3;
  fVar3 = *(float *)(this + 4);
  *(float *)(this + 4) = fVar3 * fVar2 + *(float *)(this + 0x10) * fVar4;
  *(float *)(this + 0x10) = *(float *)(this + 0x10) * fVar2 + fVar1 * fVar3;
  fVar3 = *(float *)(this + 8);
  *(float *)(this + 8) = fVar3 * fVar2 + fVar4 * *(float *)(this + 0x14);
  *(float *)(this + 0x14) = *(float *)(this + 0x14) * fVar2 + fVar3 * fVar1;
  return;
}
