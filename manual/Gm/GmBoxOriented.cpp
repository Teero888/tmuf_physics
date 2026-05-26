// Class implementation: GmBoxOriented

// =================================================
// Function: GmBoxOriented::Mult
// =================================================
void __thiscall GmBoxOriented::Mult(void *this,GmIso3 *param_1,GmIso3 *param_2)
{
{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float afStack_24 [4];
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  fVar1 = *(float *)param_1;
  pfVar3 = this;
  pfVar4 = afStack_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar4 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  *(float *)this =
       fStack_c * *(float *)(param_1 + 8) +
       afStack_24[3] * *(float *)(param_1 + 4) + afStack_24[0] * fVar1;
  *(float *)((int)this + 4) =
       fStack_8 * *(float *)(param_1 + 8) +
       fStack_14 * *(float *)(param_1 + 4) + afStack_24[1] * *(float *)param_1;
  *(float *)((int)this + 8) =
       fStack_4 * *(float *)(param_1 + 8) +
       fStack_10 * *(float *)(param_1 + 4) + *(float *)param_1 * afStack_24[2];
  *(float *)((int)this + 0xc) =
       *(float *)(param_1 + 0x14) * fStack_c +
       afStack_24[0] * *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0x10) * afStack_24[3];
  *(float *)((int)this + 0x10) =
       *(float *)(param_1 + 0x14) * fStack_8 +
       *(float *)(param_1 + 0xc) * afStack_24[1] + *(float *)(param_1 + 0x10) * fStack_14;
  *(float *)((int)this + 0x14) =
       *(float *)(param_1 + 0x14) * fStack_4 +
       *(float *)(param_1 + 0xc) * afStack_24[2] + *(float *)(param_1 + 0x10) * fStack_10;
  *(float *)((int)this + 0x18) =
       *(float *)(param_1 + 0x1c) * afStack_24[3] + *(float *)(param_1 + 0x18) * afStack_24[0] +
       *(float *)(param_1 + 0x20) * fStack_c;
  *(float *)((int)this + 0x1c) =
       *(float *)(param_1 + 0x20) * fStack_8 +
       fStack_14 * *(float *)(param_1 + 0x1c) + *(float *)(param_1 + 0x18) * afStack_24[1];
  *(float *)((int)this + 0x20) =
       *(float *)(param_1 + 0x20) * fStack_4 +
       *(float *)(param_1 + 0x18) * afStack_24[2] + *(float *)(param_1 + 0x1c) * fStack_10;
  GmVec3::Mult((void *)((int)this + 0x24),param_1,param_2);
  return;
}
}

