
/* public: void __thiscall GmIso4::NUGetIso4AndScale(class GmIso4 &,class GmVec3
 * &)const  */

void __thiscall GmIso4::NUGetIso4AndScale(GmIso4 *this, GmIso4 *param_1,
                                          GmVec3 *param_2)

{
  float fVar1;
  ulong uVar2;
  int iVar3;
  undefined4 *puVar4;
  float10 fVar5;

  puVar4 = (undefined4 *)param_1;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *(undefined4 *)this;
    this = (GmIso4 *)((int)this + 4);
    puVar4 = puVar4 + 1;
  }
  GmMat3::Transpose((GmMat3 *)param_1);
  fVar5 = (float10)__CIsqrt();
  *(float *)param_2 = (float)fVar5;
  fVar5 = (float10)__CIsqrt();
  *(float *)(param_2 + 4) = (float)fVar5;
  fVar5 = (float10)__CIsqrt();
  *(float *)(param_2 + 8) = (float)fVar5;
  fVar1 = *(float *)param_2 / 1.0;
  *(float *)param_1 = fVar1 * *(float *)param_1;
  *(float *)(param_1 + 4) = *(float *)(param_1 + 4) * fVar1;
  *(float *)(param_1 + 8) = fVar1 * *(float *)(param_1 + 8);
  fVar1 = 1.0 / *(float *)(param_2 + 4);
  *(float *)(param_1 + 0xc) = fVar1 * *(float *)(param_1 + 0xc);
  *(float *)(param_1 + 0x10) = fVar1 * *(float *)(param_1 + 0x10);
  *(float *)(param_1 + 0x14) = fVar1 * *(float *)(param_1 + 0x14);
  fVar1 = 1.0 / *(float *)(param_2 + 8);
  *(float *)(param_1 + 0x18) = fVar1 * *(float *)(param_1 + 0x18);
  *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) * fVar1;
  *(float *)(param_1 + 0x20) = fVar1 * *(float *)(param_1 + 0x20);
  uVar2 = GmMat3::IsIndirect((GmMat3 *)param_1);
  if (uVar2 != 0) {
    *(float *)param_1 = -*(float *)param_1;
    *(float *)(param_1 + 4) = -*(float *)(param_1 + 4);
    *(float *)(param_1 + 8) = -*(float *)(param_1 + 8);
    *(float *)param_2 = -*(float *)param_2;
  }
  GmMat3::Transpose((GmMat3 *)param_1);
  return;
}
