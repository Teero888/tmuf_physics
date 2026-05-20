
/* public: void __thiscall GmBoxOriented::Mult(class GmIso4 const &) */

void __thiscall GmBoxOriented::Mult(GmBoxOriented *this, GmIso4 *param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float afStack_24[4];
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;

  fVar1 = *(float *)param_1;
  pfVar3 = (float *)this;
  pfVar4 = afStack_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar4 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  *(float *)this = fStack_c * *(float *)(param_1 + 8) +
                   afStack_24[3] * *(float *)(param_1 + 4) +
                   afStack_24[0] * fVar1;
  *(float *)(this + 4) = fStack_8 * *(float *)(param_1 + 8) +
                         fStack_14 * *(float *)(param_1 + 4) +
                         afStack_24[1] * *(float *)param_1;
  *(float *)(this + 8) = fStack_4 * *(float *)(param_1 + 8) +
                         fStack_10 * *(float *)(param_1 + 4) +
                         *(float *)param_1 * afStack_24[2];
  *(float *)(this + 0xc) = *(float *)(param_1 + 0x14) * fStack_c +
                           afStack_24[0] * *(float *)(param_1 + 0xc) +
                           *(float *)(param_1 + 0x10) * afStack_24[3];
  *(float *)(this + 0x10) = *(float *)(param_1 + 0x14) * fStack_8 +
                            *(float *)(param_1 + 0xc) * afStack_24[1] +
                            *(float *)(param_1 + 0x10) * fStack_14;
  *(float *)(this + 0x14) = *(float *)(param_1 + 0x14) * fStack_4 +
                            *(float *)(param_1 + 0xc) * afStack_24[2] +
                            *(float *)(param_1 + 0x10) * fStack_10;
  *(float *)(this + 0x18) = *(float *)(param_1 + 0x1c) * afStack_24[3] +
                            *(float *)(param_1 + 0x18) * afStack_24[0] +
                            *(float *)(param_1 + 0x20) * fStack_c;
  *(float *)(this + 0x1c) = *(float *)(param_1 + 0x20) * fStack_8 +
                            fStack_14 * *(float *)(param_1 + 0x1c) +
                            *(float *)(param_1 + 0x18) * afStack_24[1];
  *(float *)(this + 0x20) = *(float *)(param_1 + 0x20) * fStack_4 +
                            *(float *)(param_1 + 0x18) * afStack_24[2] +
                            *(float *)(param_1 + 0x1c) * fStack_10;
  GmVec3::Mult((GmVec3 *)(this + 0x24), param_1);
  return;
}

/* public: void __thiscall GmBoxOriented::Set(class GmBoxAligned const &) */

void __thiscall GmBoxOriented::Set(GmBoxOriented *this, GmBoxAligned *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;

  GmMat3::SetIdentity((GmMat3 *)this);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 8);
  fVar1 = *(float *)(param_1 + 0x10);
  fVar2 = *(float *)(param_1 + 4);
  fVar3 = *(float *)(param_1 + 0x14);
  fVar4 = *(float *)(param_1 + 8);
  *(float *)(this + 0x30) =
      (*(float *)param_1 + *(float *)(param_1 + 0xc)) - *(float *)(this + 0x24);
  *(float *)(this + 0x34) = (fVar1 + fVar2) - *(float *)(this + 0x28);
  *(float *)(this + 0x38) = (fVar3 + fVar4) - *(float *)(this + 0x2c);
  return;
}

/* public: void __thiscall GmBoxOriented::SetNull(void) */

void __thiscall GmBoxOriented::SetNull(GmBoxOriented *this)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;

  puVar2 = (undefined4 *)PTR_DAT_00d1fb24;
  puVar3 = (undefined4 *)this;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(this + 0x30) = 0xbf800000;
  *(undefined4 *)(this + 0x34) = 0xbf800000;
  *(undefined4 *)(this + 0x38) = 0xbf800000;
  return;
}
