
/* public: void __thiscall GmMat2::Mult(class GmMat2 const &) */

void __thiscall GmMat2::Mult(GmMat2 *this, GmMat2 *param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  local_10 = *(undefined4 *)this;
  local_c = *(undefined4 *)(this + 4);
  local_8 = *(undefined4 *)(this + 8);
  local_4 = *(undefined4 *)(this + 0xc);
  SetMult(this, (GmMat2 *)&local_10, param_1);
  return;
}

/* public: void __thiscall GmMat2::Rotate(float) */

void __thiscall GmMat2::Rotate(GmMat2 *this, float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float10 *extraout_ECX;
  undefined4 in_EDX;
  undefined4 extraout_EDX;
  float10 fVar4;

  fVar4 = (float10)__CIsin((float10 *)this, in_EDX);
  fVar1 = (float)fVar4;
  fVar4 = (float10)__CIcos(extraout_ECX, extraout_EDX);
  fVar2 = (float)fVar4;
  fVar3 = *(float *)this;
  *(float *)this = fVar2 * fVar3 - fVar1 * *(float *)(this + 8);
  *(float *)(this + 8) = fVar2 * *(float *)(this + 8) + fVar1 * fVar3;
  fVar3 = *(float *)(this + 4);
  *(float *)(this + 4) = fVar3 * fVar2 - *(float *)(this + 0xc) * fVar1;
  *(float *)(this + 0xc) = fVar3 * fVar1 + *(float *)(this + 0xc) * fVar2;
  return;
}

/* public: void __thiscall GmMat2::SetIdentity(void) */

void __thiscall GmMat2::SetIdentity(GmMat2 *this)

{
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0x3f800000;
  return;
}

/* public: void __thiscall GmMat2::SetMult(class GmMat2 const &,class GmMat2
 * const &) */

void __thiscall GmMat2::SetMult(GmMat2 *this, GmMat2 *param_1, GmMat2 *param_2)

{
  int iVar1;
  uint uVar2;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  SetTranspose((GmMat2 *)&local_10, param_1);
  uVar2 = 0;
  do {
    iVar1 = uVar2 * 8;
    uVar2 = uVar2 + 1;
    *(float *)this = *(float *)(param_2 + uVar2 * 8 + -4) * local_c +
                     *(float *)(param_2 + iVar1) * local_10;
    *(float *)((int)this + 4) = *(float *)(param_2 + uVar2 * 8 + -4) * local_4 +
                                *(float *)(param_2 + uVar2 * 8 + -8) * local_8;
    this = (GmMat2 *)((int)this + 8);
  } while (uVar2 < 2);
  return;
}

/* public: void __thiscall GmMat2::SetRotation(float) */

void __thiscall GmMat2::SetRotation(GmMat2 *this, float param_1)

{
  float10 *extraout_ECX;
  undefined4 in_EDX;
  undefined4 extraout_EDX;
  float10 fVar1;
  float10 fVar2;

  fVar1 = (float10)__CIsin((float10 *)this, in_EDX);
  fVar2 = (float10)__CIcos(extraout_ECX, extraout_EDX);
  *(float *)this = (float)fVar2;
  *(float *)(this + 8) = -(float)fVar1;
  *(float *)(this + 4) = (float)fVar1;
  *(float *)(this + 0xc) = (float)fVar2;
  return;
}

/* public: void __thiscall GmMat2::SetTranspose(class GmMat2 const &) */

void __thiscall GmMat2::SetTranspose(GmMat2 *this, GmMat2 *param_1)

{
  float *pfVar1;

  pfVar1 = GmVec2::operator[]((GmVec2 *)param_1, 0);
  *(float *)this = *pfVar1;
  pfVar1 = GmVec2::operator[]((GmVec2 *)(param_1 + 8), 0);
  *(float *)(this + 4) = *pfVar1;
  pfVar1 = GmVec2::operator[]((GmVec2 *)param_1, 1);
  *(float *)(this + 8) = *pfVar1;
  pfVar1 = GmVec2::operator[]((GmVec2 *)(param_1 + 8), 1);
  *(float *)(this + 0xc) = *pfVar1;
  return;
}
