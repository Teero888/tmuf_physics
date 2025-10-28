
/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: int __thiscall GmMat3::SetDOVInverse(class GmVec3 const &) */

int __thiscall GmMat3::SetDOVInverse(GmMat3 *this, GmVec3 *param_1)

{
  float fVar1;
  float10 fVar2;

  *(undefined4 *)(this + 0x18) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 8);
  fVar1 = *(float *)(this + 0x20) * *(float *)(this + 0x20) +
          *(float *)(this + 0x18) * *(float *)(this + 0x18) +
          *(float *)(this + 0x1c) * *(float *)(this + 0x1c);
  if (_DAT_00d1a840 < fVar1 == (NAN(_DAT_00d1a840) || NAN(fVar1))) {
    return 0;
  }
  fVar2 = (float10)__CIsqrt();
  fVar1 = 1.0 / (float)fVar2;
  *(float *)(this + 0x18) = fVar1 * *(float *)(this + 0x18);
  *(float *)(this + 0x1c) = *(float *)(this + 0x1c) * fVar1;
  *(float *)(this + 0x20) = fVar1 * *(float *)(this + 0x20);
  *(float *)this = *(float *)(this + 0x20) - *(float *)(this + 0x1c) * 0.0;
  *(float *)(this + 4) =
      *(float *)(this + 0x18) * 0.0 - *(float *)(this + 0x20) * 0.0;
  fVar1 = *(float *)(this + 0x1c) * 0.0 - *(float *)(this + 0x18);
  *(float *)(this + 8) = fVar1;
  fVar2 = (float10)__CIsqrt();
  if ((float)fVar2 < 1e-05) {
    *(float *)(this + 0xc) =
        *(float *)(this + 0x1c) * 0.0 - *(float *)(this + 0x20) * 0.0;
    *(float *)(this + 0x10) =
        *(float *)(this + 0x20) - *(float *)(this + 0x18) * 0.0;
    *(float *)(this + 0x14) =
        *(float *)(this + 0x18) * 0.0 - *(float *)(this + 0x1c);
    *(float *)this = *(float *)(this + 0x10) * *(float *)(this + 0x20) -
                     *(float *)(this + 0x14) * *(float *)(this + 0x1c);
    *(float *)(this + 4) = *(float *)(this + 0x18) * *(float *)(this + 0x14) -
                           *(float *)(this + 0x20) * *(float *)(this + 0xc);
    fVar1 = *(float *)(this + 0xc) * *(float *)(this + 0x1c) -
            *(float *)(this + 0x10) * *(float *)(this + 0x18);
    *(float *)(this + 8) = fVar1;
    fVar1 = *(float *)this * *(float *)this +
            *(float *)(this + 4) * *(float *)(this + 4) + fVar1 * fVar1;
    if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
      fVar2 = (float10)__CIsqrt();
      fVar1 = 1.0 / (float)fVar2;
      *(float *)this = fVar1 * *(float *)this;
      *(float *)(this + 4) = *(float *)(this + 4) * fVar1;
      *(float *)(this + 8) = fVar1 * *(float *)(this + 8);
    }
    *(float *)(this + 0xc) = *(float *)(this + 8) * *(float *)(this + 0x1c) -
                             *(float *)(this + 4) * *(float *)(this + 0x20);
    *(float *)(this + 0x10) = *(float *)(this + 0x20) * *(float *)this -
                              *(float *)(this + 0x18) * *(float *)(this + 8);
    *(float *)(this + 0x14) = *(float *)(this + 4) * *(float *)(this + 0x18) -
                              *(float *)this * *(float *)(this + 0x1c);
    return 1;
  }
  *(float *)(this + 0xc) = *(float *)(this + 0x1c) * fVar1 -
                           *(float *)(this + 0x20) * *(float *)(this + 4);
  *(float *)(this + 0x10) = *(float *)(this + 0x20) * *(float *)this -
                            *(float *)(this + 0x18) * *(float *)(this + 8);
  *(float *)(this + 0x14) = *(float *)(this + 0x18) * *(float *)(this + 4) -
                            *(float *)(this + 0x1c) * *(float *)this;
  fVar1 = *(float *)(this + 0x14) * *(float *)(this + 0x14) +
          *(float *)(this + 0xc) * *(float *)(this + 0xc) +
          *(float *)(this + 0x10) * *(float *)(this + 0x10);
  if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
    fVar2 = (float10)__CIsqrt();
    fVar1 = 1.0 / (float)fVar2;
    *(float *)(this + 0xc) = fVar1 * *(float *)(this + 0xc);
    *(float *)(this + 0x10) = *(float *)(this + 0x10) * fVar1;
    *(float *)(this + 0x14) = fVar1 * *(float *)(this + 0x14);
  }
  *(float *)this = *(float *)(this + 0x10) * *(float *)(this + 0x20) -
                   *(float *)(this + 0x14) * *(float *)(this + 0x1c);
  *(float *)(this + 4) = *(float *)(this + 0x14) * *(float *)(this + 0x18) -
                         *(float *)(this + 0x20) * *(float *)(this + 0xc);
  *(float *)(this + 8) = *(float *)(this + 0x1c) * *(float *)(this + 0xc) -
                         *(float *)(this + 0x10) * *(float *)(this + 0x18);
  return 1;
}
