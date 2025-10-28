
/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall GmMat3::OrthoNormalize(void) */

void __thiscall GmMat3::OrthoNormalize(GmMat3 *this)

{
  float fVar1;
  float10 fVar2;

  fVar1 = *(float *)(this + 8) * *(float *)(this + 8) +
          *(float *)this * *(float *)this +
          *(float *)(this + 4) * *(float *)(this + 4);
  if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
    fVar2 = (float10)__CIsqrt();
    fVar1 = 1.0 / (float)fVar2;
    *(float *)this = fVar1 * *(float *)this;
    *(float *)(this + 4) = fVar1 * *(float *)(this + 4);
    *(float *)(this + 8) = fVar1 * *(float *)(this + 8);
  }
  *(float *)(this + 0x18) = *(float *)(this + 0x14) * *(float *)(this + 4) -
                            *(float *)(this + 8) * *(float *)(this + 0x10);
  *(float *)(this + 0x1c) = *(float *)(this + 0xc) * *(float *)(this + 8) -
                            *(float *)(this + 0x14) * *(float *)this;
  *(float *)(this + 0x20) = *(float *)this * *(float *)(this + 0x10) -
                            *(float *)(this + 0xc) * *(float *)(this + 4);
  fVar1 = *(float *)(this + 0x20) * *(float *)(this + 0x20) +
          *(float *)(this + 0x18) * *(float *)(this + 0x18) +
          *(float *)(this + 0x1c) * *(float *)(this + 0x1c);
  if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
    fVar2 = (float10)__CIsqrt();
    fVar1 = 1.0 / (float)fVar2;
    *(float *)(this + 0x18) = fVar1 * *(float *)(this + 0x18);
    *(float *)(this + 0x1c) = *(float *)(this + 0x1c) * fVar1;
    *(float *)(this + 0x20) = fVar1 * *(float *)(this + 0x20);
  }
  *(float *)(this + 0xc) = *(float *)(this + 0x1c) * *(float *)(this + 8) -
                           *(float *)(this + 0x20) * *(float *)(this + 4);
  *(float *)(this + 0x10) = *(float *)this * *(float *)(this + 0x20) -
                            *(float *)(this + 8) * *(float *)(this + 0x18);
  *(float *)(this + 0x14) = *(float *)(this + 0x18) * *(float *)(this + 4) -
                            *(float *)(this + 0x1c) * *(float *)this;
  return;
}
