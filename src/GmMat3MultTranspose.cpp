
/* public: void __thiscall GmMat3::MultTranspose(class GmMat3 const &) */

void __thiscall GmMat3::MultTranspose(GmMat3 *this, GmMat3 *param_1)

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
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;

  fVar1 = *(float *)this;
  fVar2 = *(float *)(this + 0xc);
  fVar3 = *(float *)(this + 0x18);
  fVar4 = *(float *)(this + 4);
  fVar5 = *(float *)(this + 0x10);
  fVar6 = *(float *)(this + 0x1c);
  fVar7 = *(float *)(this + 8);
  fVar8 = *(float *)(this + 0x14);
  fVar9 = *(float *)(this + 0x20);
  fVar10 = *(float *)param_1;
  fVar11 = *(float *)(param_1 + 0xc);
  fVar12 = *(float *)(param_1 + 0x18);
  fVar13 = *(float *)(param_1 + 4);
  fVar14 = *(float *)(param_1 + 0x10);
  fVar15 = *(float *)(param_1 + 0x1c);
  fVar16 = *(float *)(param_1 + 8);
  fVar17 = *(float *)(param_1 + 0x14);
  fVar18 = *(float *)(param_1 + 0x20);
  *(float *)this = fVar12 * fVar3 + fVar2 * fVar11 + fVar1 * fVar10;
  *(float *)(this + 4) = fVar12 * fVar6 + fVar10 * fVar4 + fVar11 * fVar5;
  *(float *)(this + 8) = fVar8 * fVar11 + fVar7 * fVar10 + fVar9 * fVar12;
  *(float *)(this + 0xc) = fVar15 * fVar3 + fVar13 * fVar1 + fVar14 * fVar2;
  *(float *)(this + 0x10) = fVar15 * fVar6 + fVar13 * fVar4 + fVar14 * fVar5;
  *(float *)(this + 0x14) = fVar15 * fVar9 + fVar13 * fVar7 + fVar14 * fVar8;
  *(float *)(this + 0x18) = fVar18 * fVar3 + fVar17 * fVar2 + fVar16 * fVar1;
  *(float *)(this + 0x1c) = fVar18 * fVar6 + fVar16 * fVar4 + fVar17 * fVar5;
  *(float *)(this + 0x20) = fVar9 * fVar18 + fVar8 * fVar17 + fVar16 * fVar7;
  return;
}
