
/* public: void __thiscall GmMat3::SetMult(class GmMat3 const &,class GmMat3
 * const &) */

void __thiscall GmMat3::SetMult(GmMat3 *this, GmMat3 *param_1, GmMat3 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;

  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_1 + 0xc);
  fVar3 = *(float *)(param_1 + 0x18);
  fVar4 = *(float *)(param_1 + 4);
  fVar5 = *(float *)(param_1 + 0x10);
  fVar6 = *(float *)(param_1 + 0x1c);
  fVar7 = *(float *)(param_1 + 8);
  fVar8 = *(float *)(param_1 + 0x14);
  fVar9 = *(float *)(param_1 + 0x20);
  *(float *)this = fVar3 * *(float *)(param_2 + 8) +
                   fVar2 * *(float *)(param_2 + 4) + fVar1 * *(float *)param_2;
  *(float *)(this + 4) = fVar6 * *(float *)(param_2 + 8) +
                         fVar5 * *(float *)(param_2 + 4) +
                         fVar4 * *(float *)param_2;
  *(float *)(this + 8) = fVar9 * *(float *)(param_2 + 8) +
                         fVar8 * *(float *)(param_2 + 4) +
                         *(float *)param_2 * fVar7;
  *(float *)(this + 0xc) = *(float *)(param_2 + 0x14) * fVar3 +
                           *(float *)(param_2 + 0xc) * fVar1 +
                           *(float *)(param_2 + 0x10) * fVar2;
  *(float *)(this + 0x10) = *(float *)(param_2 + 0x14) * fVar6 +
                            fVar4 * *(float *)(param_2 + 0xc) +
                            *(float *)(param_2 + 0x10) * fVar5;
  *(float *)(this + 0x14) = *(float *)(param_2 + 0x14) * fVar9 +
                            *(float *)(param_2 + 0xc) * fVar7 +
                            *(float *)(param_2 + 0x10) * fVar8;
  *(float *)(this + 0x18) = *(float *)(param_2 + 0x1c) * fVar2 +
                            *(float *)(param_2 + 0x18) * fVar1 +
                            *(float *)(param_2 + 0x20) * fVar3;
  *(float *)(this + 0x1c) = *(float *)(param_2 + 0x20) * fVar6 +
                            fVar5 * *(float *)(param_2 + 0x1c) +
                            *(float *)(param_2 + 0x18) * fVar4;
  *(float *)(this + 0x20) = *(float *)(param_2 + 0x20) * fVar9 +
                            *(float *)(param_2 + 0x18) * fVar7 +
                            *(float *)(param_2 + 0x1c) * fVar8;
  return;
}
