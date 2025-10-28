
/* public: void __thiscall GmMat3::RotateX(float) */

void __thiscall GmMat3::RotateX(GmMat3 *this, float param_1)

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
  fVar3 = *(float *)(this + 0xc);
  *(float *)(this + 0xc) = fVar4 * *(float *)(this + 0x18) + fVar2 * fVar3;
  *(float *)(this + 0x18) = *(float *)(this + 0x18) * fVar2 + fVar1 * fVar3;
  fVar3 = *(float *)(this + 0x10);
  *(float *)(this + 0x10) = fVar3 * fVar2 + *(float *)(this + 0x1c) * fVar4;
  *(float *)(this + 0x1c) = *(float *)(this + 0x1c) * fVar2 + fVar1 * fVar3;
  fVar3 = *(float *)(this + 0x14);
  *(float *)(this + 0x14) = fVar3 * fVar2 + fVar4 * *(float *)(this + 0x20);
  *(float *)(this + 0x20) = *(float *)(this + 0x20) * fVar2 + fVar3 * fVar1;
  return;
}
