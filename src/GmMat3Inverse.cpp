
/* public: unsigned long __thiscall GmMat3::Inverse(void) */

ulong __thiscall GmMat3::Inverse(GmMat3 *this)

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

  fVar1 = *(float *)this;
  fVar2 = *(float *)(this + 4);
  fVar3 = *(float *)(this + 8);
  fVar4 = *(float *)(this + 0xc);
  fVar5 = *(float *)(this + 0x10);
  fVar6 = *(float *)(this + 0x14);
  fVar7 = *(float *)(this + 0x18);
  fVar8 = *(float *)(this + 0x1c);
  fVar9 = *(float *)(this + 0x20);
  fVar12 = fVar5 * fVar9 - fVar6 * fVar8;
  fVar13 = fVar3 * fVar8 - fVar2 * fVar9;
  fVar11 = fVar2 * fVar6 - fVar3 * fVar5;
  fVar10 = fVar13 * fVar4 + fVar12 * fVar1 + fVar11 * fVar7;
  if (NAN(fVar10) != (fVar10 == 0.0)) {
    return 0;
  }
  fVar10 = 1.0 / fVar10;
  *(float *)this = fVar10 * fVar12;
  *(float *)(this + 0xc) = fVar10 * (fVar7 * fVar6 - fVar4 * fVar9);
  *(float *)(this + 0x18) = fVar10 * (fVar4 * fVar8 - fVar7 * fVar5);
  *(float *)(this + 4) = fVar13 * fVar10;
  *(float *)(this + 0x10) = fVar10 * (fVar1 * fVar9 - fVar3 * fVar7);
  *(float *)(this + 0x1c) = fVar10 * (fVar2 * fVar7 - fVar1 * fVar8);
  *(float *)(this + 8) = fVar10 * fVar11;
  *(float *)(this + 0x14) = fVar10 * (fVar3 * fVar4 - fVar1 * fVar6);
  *(float *)(this + 0x20) = fVar10 * (fVar1 * fVar5 - fVar2 * fVar4);
  return 1;
}
