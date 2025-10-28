
/* public: void __thiscall GmMat3::ArchiveGmMat3(class CClassicArchive &) */

void __thiscall GmMat3::ArchiveGmMat3(GmMat3 *this, CClassicArchive *param_1)

{
  CClassicArchive::DoReal(param_1, (float *)this, 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 4), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 8), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0xc), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x10), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x14), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x18), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x1c), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x20), 1);
  return;
}

/* public: void __thiscall GmMat3::GetLine(unsigned long,class GmVec3 &)const */

void __thiscall GmMat3::GetLine(GmMat3 *this, ulong param_1, GmVec3 *param_2)

{
  *(undefined4 *)param_2 = *(undefined4 *)(this + param_1 * 4);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(this + param_1 * 4 + 0xc);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(this + param_1 * 4 + 0x18);
  return;
}

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

/* public: unsigned long __thiscall GmMat3::IsIndirect(void)const  */

ulong __thiscall GmMat3::IsIndirect(GmMat3 *this)

{
  float fVar1;

  fVar1 =
      *(float *)(this + 0x20) *
          (*(float *)(this + 0x10) * *(float *)this -
           *(float *)(this + 0xc) * *(float *)(this + 4)) +
      *(float *)(this + 0x18) *
          (*(float *)(this + 0x14) * *(float *)(this + 4) -
           *(float *)(this + 0x10) * *(float *)(this + 8)) +
      *(float *)(this + 0x1c) * (*(float *)(this + 8) * *(float *)(this + 0xc) -
                                 *(float *)(this + 0x14) * *(float *)this);
  if (fVar1 < 0.0 != NAN(fVar1)) {
    return 1;
  }
  return 0;
}

/* public: unsigned long __thiscall GmMat3::IsNearlyEqual(class GmMat3 const
 * &)const  */

ulong __thiscall GmMat3::IsNearlyEqual(GmMat3 *this, GmMat3 *param_1)

{
  ulong uVar1;

  uVar1 = GmVec3::IsNearlyEqual((GmVec3 *)this, (GmVec3 *)param_1);
  if (uVar1 != 0) {
    uVar1 = GmVec3::IsNearlyEqual((GmVec3 *)(this + 0xc),
                                  (GmVec3 *)(param_1 + 0xc));
    if (uVar1 != 0) {
      uVar1 = GmVec3::IsNearlyEqual((GmVec3 *)(this + 0x18),
                                    (GmVec3 *)(param_1 + 0x18));
      if (uVar1 != 0) {
        return 1;
      }
    }
  }
  return 0;
}

/* public: unsigned long __thiscall GmMat3::IsOrthogonal(void)const  */

ulong __thiscall GmMat3::IsOrthogonal(GmMat3 *this)

{
  float fVar1;

  if (((ABS(*(float *)(this + 0x14) * *(float *)(this + 8) +
            *(float *)(this + 0xc) * *(float *)this +
            *(float *)(this + 0x10) * *(float *)(this + 4)) < 0.001) &&
       (fVar1 = ABS(*(float *)(this + 0x20) * *(float *)(this + 8) +
                    *(float *)(this + 0x18) * *(float *)this +
                    *(float *)(this + 0x1c) * *(float *)(this + 4)),
        fVar1 < 0.001 != NAN(fVar1))) &&
      (ABS(*(float *)(this + 0x20) * *(float *)(this + 0x14) +
           *(float *)(this + 0xc) * *(float *)(this + 0x18) +
           *(float *)(this + 0x1c) * *(float *)(this + 0x10)) < 0.001)) {
    return 1;
  }
  return 0;
}

/* public: unsigned long __thiscall GmMat3::IsOrthonormal(void)const  */

ulong __thiscall GmMat3::IsOrthonormal(GmMat3 *this)

{
  ulong uVar1;
  float10 fVar2;

  fVar2 = (float10)__CIsqrt();
  if (ABS((float)fVar2 - 1.0) < 0.001 != NAN(ABS((float)fVar2 - 1.0))) {
    fVar2 = (float10)__CIsqrt();
    if (ABS((float)fVar2 - 1.0) < 0.001 != NAN(ABS((float)fVar2 - 1.0))) {
      fVar2 = (float10)__CIsqrt();
      if (ABS((float)fVar2 - 1.0) < 0.001 != NAN(ABS((float)fVar2 - 1.0))) {
        uVar1 = IsOrthogonal(this);
        if (uVar1 != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}

/* public: void __thiscall GmMat3::LeftMult(class GmMat3 const &) */

void __thiscall GmMat3::LeftMult(GmMat3 *this, GmMat3 *param_1)

{
  GmMat3 *extraout_ECX;
  GmMat3 *this_00;
  GmMat3 local_24[36];

  Set(local_24, this);
  SetMult(this_00, param_1, extraout_ECX);
  return;
}

/* public: void __thiscall GmMat3::Mult(float) */

void __thiscall GmMat3::Mult(GmMat3 *this, float param_1)

{
  *(float *)this = param_1 * *(float *)this;
  *(float *)(this + 4) = *(float *)(this + 4) * param_1;
  *(float *)(this + 8) = param_1 * *(float *)(this + 8);
  *(float *)(this + 0xc) = *(float *)(this + 0xc) * param_1;
  *(float *)(this + 0x10) = param_1 * *(float *)(this + 0x10);
  *(float *)(this + 0x14) = *(float *)(this + 0x14) * param_1;
  *(float *)(this + 0x18) = *(float *)(this + 0x18) * param_1;
  *(float *)(this + 0x1c) = *(float *)(this + 0x1c) * param_1;
  *(float *)(this + 0x20) = param_1 * *(float *)(this + 0x20);
  return;
}

/* public: void __thiscall GmMat3::Mult(class GmMat3 const &) */

void __thiscall GmMat3::Mult(GmMat3 *this, GmMat3 *param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float local_24[4];
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  fVar1 = *(float *)param_1;
  pfVar3 = (float *)this;
  pfVar4 = local_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar4 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  *(float *)this = local_24[0] * fVar1 + local_24[3] * *(float *)(param_1 + 4) +
                   local_c * *(float *)(param_1 + 8);
  *(float *)(this + 4) = *(float *)(param_1 + 8) * local_8 +
                         local_24[1] * *(float *)param_1 +
                         local_14 * *(float *)(param_1 + 4);
  *(float *)(this + 8) = *(float *)(param_1 + 8) * local_4 +
                         *(float *)(param_1 + 4) * local_10 +
                         *(float *)param_1 * local_24[2];
  *(float *)(this + 0xc) = *(float *)(param_1 + 0x14) * local_c +
                           local_24[0] * *(float *)(param_1 + 0xc) +
                           *(float *)(param_1 + 0x10) * local_24[3];
  *(float *)(this + 0x10) = *(float *)(param_1 + 0x14) * local_8 +
                            *(float *)(param_1 + 0xc) * local_24[1] +
                            *(float *)(param_1 + 0x10) * local_14;
  *(float *)(this + 0x14) = *(float *)(param_1 + 0x14) * local_4 +
                            *(float *)(param_1 + 0xc) * local_24[2] +
                            *(float *)(param_1 + 0x10) * local_10;
  *(float *)(this + 0x18) = *(float *)(param_1 + 0x1c) * local_24[3] +
                            *(float *)(param_1 + 0x18) * local_24[0] +
                            *(float *)(param_1 + 0x20) * local_c;
  *(float *)(this + 0x1c) = *(float *)(param_1 + 0x20) * local_8 +
                            local_14 * *(float *)(param_1 + 0x1c) +
                            *(float *)(param_1 + 0x18) * local_24[1];
  *(float *)(this + 0x20) = *(float *)(param_1 + 0x20) * local_4 +
                            *(float *)(param_1 + 0x18) * local_24[2] +
                            *(float *)(param_1 + 0x1c) * local_10;
  return;
}

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

/* public: void __thiscall GmMat3::RotateX(float) */

void __thiscall GmMat3::RotateX(GmMat3 *this, float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 *extraout_ECX;
  undefined4 in_EDX;
  undefined4 extraout_EDX;
  float10 fVar5;

  fVar5 = (float10)__CIsin((float10 *)this, in_EDX);
  fVar1 = (float)fVar5;
  fVar5 = (float10)__CIcos(extraout_ECX, extraout_EDX);
  fVar2 = (float)fVar5;
  fVar4 = -fVar1;
  fVar3 = *(float *)(this + 0xc);
  *(float *)(this + 0xc) = fVar4 * *(float *)(this + 0x18) + fVar2 * fVar3;
  *(float *)(this + 0x18) = *(float *)(this + 0x18) * fVar2 + fVar1 * fVar3;
  fVar3 = *(float *)(this + 0x10);
  *(float *)(this + 0x10) = fVar3 * fVar2 + *(float *)(this + 0x1c) * fVar4;
  *(float *)(this + 0x1c) = *(float *)(this + 0x1c) * fVar2 + fVar1 * fVar3;
  fVar3 = *(float *)(this + 0x14);
  *(float *)(this + 0x14) = fVar3 * fVar2 + fVar4 * *(float *)(this + 0x20);
  *(float *)(this + 0x20) = *(float *)(this + 0x20) * fVar2 + fVar3 * fVar1;
  return;
}

/* public: void __thiscall GmMat3::RotateY(float) */

void __thiscall GmMat3::RotateY(GmMat3 *this, float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 *extraout_ECX;
  undefined4 in_EDX;
  undefined4 extraout_EDX;
  float10 fVar5;

  fVar5 = (float10)__CIsin((float10 *)this, in_EDX);
  fVar1 = (float)fVar5;
  fVar5 = (float10)__CIcos(extraout_ECX, extraout_EDX);
  fVar2 = (float)fVar5;
  fVar4 = -fVar1;
  fVar3 = *(float *)this;
  *(float *)this = *(float *)(this + 0x18) * fVar1 + fVar2 * fVar3;
  *(float *)(this + 0x18) = *(float *)(this + 0x18) * fVar2 + fVar4 * fVar3;
  fVar3 = *(float *)(this + 4);
  *(float *)(this + 4) = fVar3 * fVar2 + *(float *)(this + 0x1c) * fVar1;
  *(float *)(this + 0x1c) = *(float *)(this + 0x1c) * fVar2 + fVar4 * fVar3;
  fVar3 = *(float *)(this + 8);
  *(float *)(this + 8) = fVar3 * fVar2 + *(float *)(this + 0x20) * fVar1;
  *(float *)(this + 0x20) = *(float *)(this + 0x20) * fVar2 + fVar4 * fVar3;
  return;
}

/* public: void __thiscall GmMat3::RotateZ(float) */

void __thiscall GmMat3::RotateZ(GmMat3 *this, float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 *extraout_ECX;
  undefined4 in_EDX;
  undefined4 extraout_EDX;
  float10 fVar5;

  fVar5 = (float10)__CIsin((float10 *)this, in_EDX);
  fVar1 = (float)fVar5;
  fVar5 = (float10)__CIcos(extraout_ECX, extraout_EDX);
  fVar2 = (float)fVar5;
  fVar4 = -fVar1;
  fVar3 = *(float *)this;
  *(float *)this = fVar4 * *(float *)(this + 0xc) + fVar2 * fVar3;
  *(float *)(this + 0xc) = *(float *)(this + 0xc) * fVar2 + fVar1 * fVar3;
  fVar3 = *(float *)(this + 4);
  *(float *)(this + 4) = fVar3 * fVar2 + *(float *)(this + 0x10) * fVar4;
  *(float *)(this + 0x10) = *(float *)(this + 0x10) * fVar2 + fVar1 * fVar3;
  fVar3 = *(float *)(this + 8);
  *(float *)(this + 8) = fVar3 * fVar2 + fVar4 * *(float *)(this + 0x14);
  *(float *)(this + 0x14) = *(float *)(this + 0x14) * fVar2 + fVar3 * fVar1;
  return;
}

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

/* public: void __thiscall GmMat3::SetBlend(class GmMat3 const &,class GmMat3
 * const &,float) */

void __thiscall GmMat3::SetBlend(GmMat3 *this, GmMat3 *param_1, GmMat3 *param_2,
                                 float param_3)

{
  ulong uVar1;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10[4];

  GmQuat::Set((GmQuat *)&local_30, param_1);
  GmQuat::Set((GmQuat *)local_10, param_2);
  GmQuat::SetSlerp((GmQuat *)&local_20, local_30, local_2c, local_28, local_24,
                   local_10, param_3);
  if ((((ABS(local_2c - local_1c) < 1e-05) &&
        (ABS(local_28 - local_18) < 1e-05 != NAN(ABS(local_28 - local_18)))) &&
       (ABS(local_24 - local_14) < 1e-05 != NAN(ABS(local_24 - local_14)))) &&
      (uVar1 = GmFunc::AreNearlyEqual(local_30, local_20, 1e-05), uVar1 != 0)) {
    Set(this, param_1);
    return;
  }
  Set(this, local_20, local_1c, local_18, local_14);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall GmMat3::SetDOV(class GmVec3 const &,unsigned long) */

void __thiscall GmMat3::SetDOV(GmMat3 *this, GmVec3 *param_1, ulong param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  GmMat3 *this_00;
  GmMat3 *this_01;
  float10 fVar4;
  undefined8 local_24;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_c = 0.0;
  local_8 = 1.0;
  local_4 = 0.0;
  local_18 = *(float *)(param_1 + 8) - *(float *)(param_1 + 4) * 0.0;
  fVar1 = *(float *)param_1 * 0.0;
  local_14 = fVar1 - *(float *)(param_1 + 8) * 0.0;
  local_10 = *(float *)(param_1 + 4) * 0.0 - *(float *)param_1;
  if (param_2 == 0) {
    if (_DAT_00d1a840 <=
        local_10 * local_10 + local_18 * local_18 + local_14 * local_14) {
      SetDOVandUpV(this, param_1, (GmVec3 *)&local_c);
      return;
    }
    local_c = 1.0;
    local_8 = 0.0;
    local_4 = 0.0;
    SetDOVandUpV(this, param_1, (GmVec3 *)&local_c);
    return;
  }
  fVar2 = *(float *)(param_1 + 8) * 0.0 - *(float *)(param_1 + 4) * 0.0;
  local_1c = *(float *)(param_1 + 4) - fVar1;
  local_24 = (double)local_1c;
  fVar3 = local_18 * local_18 + local_14 * local_14 + local_10 * local_10;
  fVar2 = local_1c * local_1c + fVar2 * fVar2 +
          (fVar1 - *(float *)(param_1 + 8)) * (fVar1 - *(float *)(param_1 + 8));
  if (fVar2 < fVar3 == (NAN(fVar2) || NAN(fVar3))) {
    local_24._0_4_ =
        *(float *)(param_1 + 4) * 0.0 - *(float *)(param_1 + 8) * 0.0;
    local_24._4_4_ = *(float *)(param_1 + 8) - fVar1;
    local_1c = fVar1 - *(float *)(param_1 + 4);
    fVar1 = local_1c * local_1c + (float)local_24 * (float)local_24 +
            local_24._4_4_ * local_24._4_4_;
    if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
      fVar4 = (float10)__CIsqrt();
      fVar1 = 1.0 / (float)fVar4;
      local_24._0_4_ = fVar1 * (float)local_24;
      local_24._4_4_ = local_24._4_4_ * fVar1;
      local_1c = fVar1 * local_1c;
    }
    local_14 = *(float *)(param_1 + 4);
    local_18 = *(float *)param_1;
    local_10 = *(float *)(param_1 + 8);
    fVar1 = local_18 * local_18 + local_14 * local_14 + local_10 * local_10;
    if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
      fVar4 = (float10)__CIsqrt();
      fVar1 = 1.0 / (float)fVar4;
      local_18 = fVar1 * local_18;
      local_14 = local_14 * fVar1;
      local_10 = fVar1 * local_10;
    }
    local_c = local_24._4_4_ * local_10 - local_1c * local_14;
    local_8 = local_18 * local_1c - (float)local_24 * local_10;
    local_4 = (float)local_24 * local_14 - local_18 * local_24._4_4_;
    SetLine(this, 0, (GmVec3 *)&local_c);
    SetLine(this_00, 1, (GmVec3 *)&local_24);
    SetLine(this_01, 2, (GmVec3 *)&local_18);
    return;
  }
  SetDOVandUpV(this, param_1, (GmVec3 *)&local_c);
  return;
}

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall GmMat3::SetDOVandLeftV(class GmVec3 const &,class
 * GmVec3 const &) */

void __thiscall GmMat3::SetDOVandLeftV(GmMat3 *this, GmVec3 *param_1,
                                       GmVec3 *param_2)

{
  float fVar1;
  GmMat3 *this_00;
  float10 fVar2;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_24 = *(float *)(param_1 + 4) * *(float *)(param_2 + 8) -
             *(float *)(param_1 + 8) * *(float *)(param_2 + 4);
  local_20 = *(float *)(param_1 + 8) * *(float *)param_2 -
             *(float *)param_1 * *(float *)(param_2 + 8);
  local_1c = *(float *)param_1 * *(float *)(param_2 + 4) -
             *(float *)param_2 * *(float *)(param_1 + 4);
  fVar1 = local_1c * local_1c + local_24 * local_24 + local_20 * local_20;
  if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
    fVar2 = (float10)__CIsqrt();
    fVar1 = 1.0 / (float)fVar2;
    local_24 = fVar1 * local_24;
    local_20 = local_20 * fVar1;
    local_1c = fVar1 * local_1c;
  }
  local_18 = *(float *)param_1;
  local_14 = *(float *)(param_1 + 4);
  local_10 = *(float *)(param_1 + 8);
  fVar1 = local_14 * local_14 + local_18 * local_18 + local_10 * local_10;
  if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
    fVar2 = (float10)__CIsqrt();
    fVar1 = 1.0 / (float)fVar2;
    local_18 = fVar1 * local_18;
    local_14 = fVar1 * local_14;
    local_10 = fVar1 * local_10;
  }
  local_c = local_20 * local_10 - local_1c * local_14;
  local_8 = local_18 * local_1c - local_24 * local_10;
  local_4 = local_24 * local_14 - local_20 * local_18;
  SetLine(this, 0, (GmVec3 *)&local_c);
  SetLine(this, 1, (GmVec3 *)&local_24);
  SetLine(this_00, 2, (GmVec3 *)&local_18);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall GmMat3::SetDOVandUpV(class GmVec3 const &,class
 * GmVec3 const &) */

void __thiscall GmMat3::SetDOVandUpV(GmMat3 *this, GmVec3 *param_1,
                                     GmVec3 *param_2)

{
  float fVar1;
  GmMat3 *this_00;
  float10 fVar2;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_24 = *(float *)(param_1 + 8) * *(float *)(param_2 + 4) -
             *(float *)(param_1 + 4) * *(float *)(param_2 + 8);
  local_20 = *(float *)param_1 * *(float *)(param_2 + 8) -
             *(float *)param_2 * *(float *)(param_1 + 8);
  local_1c = *(float *)(param_1 + 4) * *(float *)param_2 -
             *(float *)param_1 * *(float *)(param_2 + 4);
  fVar1 = local_1c * local_1c + local_24 * local_24 + local_20 * local_20;
  if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
    fVar2 = (float10)__CIsqrt();
    fVar1 = 1.0 / (float)fVar2;
    local_24 = fVar1 * local_24;
    local_20 = local_20 * fVar1;
    local_1c = fVar1 * local_1c;
  }
  local_18 = *(float *)param_1;
  local_14 = *(float *)(param_1 + 4);
  local_10 = *(float *)(param_1 + 8);
  fVar1 = local_14 * local_14 + local_18 * local_18 + local_10 * local_10;
  if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
    fVar2 = (float10)__CIsqrt();
    fVar1 = 1.0 / (float)fVar2;
    local_18 = fVar1 * local_18;
    local_14 = fVar1 * local_14;
    local_10 = fVar1 * local_10;
  }
  local_c = local_1c * local_14 - local_20 * local_10;
  local_8 = local_24 * local_10 - local_18 * local_1c;
  local_4 = local_20 * local_18 - local_14 * local_24;
  SetLine(this, 0, (GmVec3 *)&local_24);
  SetLine(this, 1, (GmVec3 *)&local_c);
  SetLine(this_00, 2, (GmVec3 *)&local_18);
  return;
}

/* public: void __thiscall GmMat3::SetIdentity(void) */

void __thiscall GmMat3::SetIdentity(GmMat3 *this)

{
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x10) = 0x3f800000;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0x3f800000;
  return;
}

/* public: void __thiscall GmMat3::SetLine(unsigned long,class GmVec3 const &)
 */

void __thiscall GmMat3::SetLine(GmMat3 *this, ulong param_1, GmVec3 *param_2)

{
  *(undefined4 *)(this + param_1 * 4) = *(undefined4 *)param_2;
  *(undefined4 *)(this + param_1 * 4 + 0xc) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + param_1 * 4 + 0x18) = *(undefined4 *)(param_2 + 8);
  return;
}

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

/* public: void __thiscall GmMat3::SetRotateQuarterY(unsigned long) */

void __thiscall GmMat3::SetRotateQuarterY(GmMat3 *this, ulong param_1)

{
  undefined4 uVar1;
  float fVar2;

  uVar1 = *(undefined4 *)(&DAT_00bbd760 + (param_1 & 3) * 4);
  fVar2 = *(float *)(&DAT_00bbd760 + (param_1 - 1 & 3) * 4);
  *(undefined4 *)this = uVar1;
  *(undefined4 *)(this + 4) = 0;
  *(float *)(this + 8) = fVar2;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0x3f800000;
  *(undefined4 *)(this + 0x14) = 0;
  *(float *)(this + 0x18) = -fVar2;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = uVar1;
  return;
}

/* public: void __thiscall GmMat3::SetTranspose(class GmMat3 const &) */

void __thiscall GmMat3::SetTranspose(GmMat3 *this, GmMat3 *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x14);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall GmMat3::SetUpVandDOV(class GmVec3 const &,class
 * GmVec3 const &) */

void __thiscall GmMat3::SetUpVandDOV(GmMat3 *this, GmVec3 *param_1,
                                     GmVec3 *param_2)

{
  float fVar1;
  GmMat3 *this_00;
  float10 fVar2;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_24 = *(float *)(param_1 + 4) * *(float *)(param_2 + 8) -
             *(float *)(param_1 + 8) * *(float *)(param_2 + 4);
  local_20 = *(float *)(param_1 + 8) * *(float *)param_2 -
             *(float *)param_1 * *(float *)(param_2 + 8);
  local_1c = *(float *)param_1 * *(float *)(param_2 + 4) -
             *(float *)param_2 * *(float *)(param_1 + 4);
  fVar1 = local_1c * local_1c + local_24 * local_24 + local_20 * local_20;
  if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
    fVar2 = (float10)__CIsqrt();
    fVar1 = 1.0 / (float)fVar2;
    local_24 = fVar1 * local_24;
    local_20 = local_20 * fVar1;
    local_1c = fVar1 * local_1c;
  }
  local_18 = *(float *)param_1;
  local_14 = *(float *)(param_1 + 4);
  local_10 = *(float *)(param_1 + 8);
  fVar1 = local_14 * local_14 + local_18 * local_18 + local_10 * local_10;
  if (_DAT_00d1a840 < fVar1 != (NAN(_DAT_00d1a840) || NAN(fVar1))) {
    fVar2 = (float10)__CIsqrt();
    fVar1 = 1.0 / (float)fVar2;
    local_18 = fVar1 * local_18;
    local_14 = fVar1 * local_14;
    local_10 = fVar1 * local_10;
  }
  local_c = local_20 * local_10 - local_1c * local_14;
  local_8 = local_18 * local_1c - local_24 * local_10;
  local_4 = local_24 * local_14 - local_20 * local_18;
  SetLine(this, 0, (GmVec3 *)&local_24);
  SetLine(this, 1, (GmVec3 *)&local_18);
  SetLine(this_00, 2, (GmVec3 *)&local_c);
  return;
}

/* public: void __thiscall GmMat3::Transpose(void) */

void __thiscall GmMat3::Transpose(GmMat3 *this)

{
  undefined4 uVar1;

  uVar1 = *(undefined4 *)(this + 4);
  *(undefined4 *)(this + 4) = *(undefined4 *)(this + 0xc);
  *(undefined4 *)(this + 0xc) = uVar1;
  uVar1 = *(undefined4 *)(this + 8);
  *(undefined4 *)(this + 8) = *(undefined4 *)(this + 0x18);
  *(undefined4 *)(this + 0x18) = uVar1;
  uVar1 = *(undefined4 *)(this + 0x14);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 0x1c);
  *(undefined4 *)(this + 0x1c) = uVar1;
  return;
}
