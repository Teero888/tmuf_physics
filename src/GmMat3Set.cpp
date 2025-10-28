
/* public: void __thiscall GmMat3::Set(class GmMat3 const &) */

void __thiscall GmMat3::Set(GmMat3 *this, GmMat3 *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  return;
}

/* public: void __thiscall GmMat3::Set(class GmQuat) */

void __thiscall GmMat3::Set(GmMat3 *this, float param_1, float param_2,
                            float param_3, float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;

  fVar2 = param_3 * 2.0;
  fVar1 = param_4 * 2.0;
  fVar3 = param_2 * 2.0 * param_1;
  *(float *)this = (1.0 - param_3 * fVar2) - param_4 * fVar1;
  *(float *)(this + 0xc) = fVar1 * param_1 + param_2 * fVar2;
  *(float *)(this + 0x18) = fVar1 * param_2 - fVar2 * param_1;
  *(float *)(this + 4) = param_2 * fVar2 - fVar1 * param_1;
  fVar4 = 1.0 - param_2 * param_2 * 2.0;
  *(float *)(this + 0x10) = fVar4 - param_4 * fVar1;
  *(float *)(this + 0x1c) = fVar3 + param_3 * fVar1;
  *(float *)(this + 8) = fVar2 * param_1 + fVar1 * param_2;
  *(float *)(this + 0x14) = param_3 * fVar1 - fVar3;
  *(float *)(this + 0x20) = fVar4 - param_3 * fVar2;
  return;
}
