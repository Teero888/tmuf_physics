
/* public: void __thiscall GmMat4::ArchiveGmMat4(class CClassicArchive &) */

void __thiscall GmMat4::ArchiveGmMat4(GmMat4 *this, CClassicArchive *param_1)

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
  CClassicArchive::DoReal(param_1, (float *)(this + 0x24), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x28), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x2c), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x30), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x34), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x38), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x3c), 1);
  return;
}

/* public: void __thiscall GmMat4::Mult(class GmMat4 const &) */

void __thiscall GmMat4::Mult(GmMat4 *this, GmMat4 *param_1)

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
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;

  fVar1 = *(float *)this;
  fVar2 = *(float *)(this + 0x10);
  fVar3 = *(float *)(this + 0x20);
  fVar4 = *(float *)(this + 0x30);
  fVar5 = *(float *)(this + 4);
  fVar6 = *(float *)(this + 0x14);
  fVar7 = *(float *)(this + 0x24);
  fVar8 = *(float *)(this + 0x34);
  fVar9 = *(float *)(this + 8);
  fVar10 = *(float *)(this + 0x18);
  fVar11 = *(float *)(this + 0x28);
  fVar12 = *(float *)(this + 0x38);
  fVar13 = *(float *)(this + 0xc);
  fVar14 = *(float *)(this + 0x1c);
  fVar15 = *(float *)(this + 0x2c);
  fVar16 = *(float *)(this + 0x3c);
  fVar17 = *(float *)(param_1 + 4);
  fVar18 = *(float *)param_1;
  fVar19 = *(float *)(param_1 + 8);
  fVar20 = *(float *)(param_1 + 0xc);
  fVar21 = *(float *)param_1;
  fVar22 = *(float *)(param_1 + 4);
  fVar23 = *(float *)(param_1 + 8);
  fVar24 = *(float *)(param_1 + 0xc);
  fVar25 = *(float *)param_1;
  fVar26 = *(float *)(param_1 + 4);
  fVar27 = *(float *)(param_1 + 8);
  fVar28 = *(float *)(param_1 + 0xc);
  *(float *)this = *(float *)(param_1 + 0xc) * fVar4 +
                   *(float *)(param_1 + 8) * fVar3 + *(float *)param_1 * fVar1 +
                   *(float *)(param_1 + 4) * fVar2;
  *(float *)(this + 4) =
      fVar6 * fVar17 + fVar5 * fVar18 + fVar7 * fVar19 + fVar8 * fVar20;
  *(float *)(this + 8) =
      fVar24 * fVar12 + fVar23 * fVar11 + fVar22 * fVar10 + fVar9 * fVar21;
  *(float *)(this + 0xc) =
      fVar28 * fVar16 + fVar27 * fVar15 + fVar26 * fVar14 + fVar25 * fVar13;
  fVar17 = *(float *)(param_1 + 0x14);
  fVar18 = *(float *)(param_1 + 0x10);
  fVar19 = *(float *)(param_1 + 0x18);
  fVar20 = *(float *)(param_1 + 0x1c);
  fVar21 = *(float *)(param_1 + 0x14);
  fVar22 = *(float *)(param_1 + 0x10);
  fVar23 = *(float *)(param_1 + 0x18);
  fVar24 = *(float *)(param_1 + 0x1c);
  fVar25 = *(float *)(param_1 + 0x14);
  fVar26 = *(float *)(param_1 + 0x10);
  fVar27 = *(float *)(param_1 + 0x18);
  fVar28 = *(float *)(param_1 + 0x1c);
  *(float *)(this + 0x10) =
      *(float *)(param_1 + 0x1c) * fVar4 + *(float *)(param_1 + 0x18) * fVar3 +
      *(float *)(param_1 + 0x10) * fVar1 + *(float *)(param_1 + 0x14) * fVar2;
  *(float *)(this + 0x14) =
      fVar20 * fVar8 + fVar19 * fVar7 + fVar18 * fVar5 + fVar17 * fVar6;
  *(float *)(this + 0x18) =
      fVar12 * fVar24 + fVar23 * fVar11 + fVar22 * fVar9 + fVar10 * fVar21;
  *(float *)(this + 0x1c) =
      fVar16 * fVar28 + fVar27 * fVar15 + fVar26 * fVar13 + fVar14 * fVar25;
  fVar17 = *(float *)(param_1 + 0x20);
  fVar18 = *(float *)(param_1 + 0x24);
  fVar19 = *(float *)(param_1 + 0x28);
  fVar20 = *(float *)(param_1 + 0x2c);
  fVar21 = *(float *)(param_1 + 0x20);
  fVar22 = *(float *)(param_1 + 0x24);
  fVar23 = *(float *)(param_1 + 0x28);
  fVar24 = *(float *)(param_1 + 0x2c);
  fVar25 = *(float *)(param_1 + 0x20);
  fVar26 = *(float *)(param_1 + 0x24);
  fVar27 = *(float *)(param_1 + 0x28);
  fVar28 = *(float *)(param_1 + 0x2c);
  *(float *)(this + 0x20) =
      *(float *)(param_1 + 0x2c) * fVar4 + *(float *)(param_1 + 0x28) * fVar3 +
      *(float *)(param_1 + 0x24) * fVar2 + *(float *)(param_1 + 0x20) * fVar1;
  *(float *)(this + 0x24) =
      fVar20 * fVar8 + fVar19 * fVar7 + fVar18 * fVar6 + fVar17 * fVar5;
  *(float *)(this + 0x28) =
      fVar24 * fVar12 + fVar11 * fVar23 + fVar22 * fVar10 + fVar21 * fVar9;
  *(float *)(this + 0x2c) =
      fVar28 * fVar16 + fVar15 * fVar27 + fVar26 * fVar14 + fVar25 * fVar13;
  fVar17 = *(float *)(param_1 + 0x30);
  fVar18 = *(float *)(param_1 + 0x34);
  fVar19 = *(float *)(param_1 + 0x38);
  fVar20 = *(float *)(param_1 + 0x3c);
  fVar21 = *(float *)(param_1 + 0x34);
  fVar22 = *(float *)(param_1 + 0x30);
  fVar23 = *(float *)(param_1 + 0x38);
  fVar24 = *(float *)(param_1 + 0x3c);
  fVar25 = *(float *)(param_1 + 0x34);
  fVar26 = *(float *)(param_1 + 0x30);
  fVar27 = *(float *)(param_1 + 0x38);
  fVar28 = *(float *)(param_1 + 0x3c);
  *(float *)(this + 0x30) =
      *(float *)(param_1 + 0x3c) * fVar4 + *(float *)(param_1 + 0x38) * fVar3 +
      *(float *)(param_1 + 0x34) * fVar2 + *(float *)(param_1 + 0x30) * fVar1;
  *(float *)(this + 0x34) =
      fVar17 * fVar5 + fVar18 * fVar6 + fVar19 * fVar7 + fVar20 * fVar8;
  *(float *)(this + 0x38) =
      fVar12 * fVar24 + fVar23 * fVar11 + fVar10 * fVar21 + fVar22 * fVar9;
  *(float *)(this + 0x3c) =
      fVar16 * fVar28 + fVar27 * fVar15 + fVar26 * fVar13 + fVar14 * fVar25;
  return;
}

/* public: void __thiscall GmMat4::Mult(class GmIso4 const &) */

void __thiscall GmMat4::Mult(GmMat4 *this, GmIso4 *param_1)

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
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;

  fVar1 = *(float *)this;
  fVar2 = *(float *)(this + 0x10);
  fVar3 = *(float *)(this + 0x20);
  fVar4 = *(float *)(this + 0x30);
  fVar5 = *(float *)(this + 4);
  fVar6 = *(float *)(this + 0x14);
  fVar7 = *(float *)(this + 0x24);
  fVar8 = *(float *)(this + 0x34);
  fVar9 = *(float *)(this + 8);
  fVar10 = *(float *)(this + 0x18);
  fVar11 = *(float *)(this + 0x28);
  fVar12 = *(float *)(this + 0x38);
  fVar13 = *(float *)(this + 0xc);
  fVar14 = *(float *)(this + 0x1c);
  fVar15 = *(float *)(this + 0x2c);
  fVar16 = *(float *)(this + 0x3c);
  fVar17 = *(float *)param_1;
  fVar18 = *(float *)(param_1 + 4);
  fVar19 = *(float *)(param_1 + 8);
  fVar20 = *(float *)(param_1 + 0x24);
  fVar21 = *(float *)param_1;
  fVar22 = *(float *)(param_1 + 4);
  fVar23 = *(float *)(param_1 + 8);
  fVar24 = *(float *)(param_1 + 0x24);
  fVar25 = *(float *)param_1;
  fVar26 = *(float *)(param_1 + 4);
  fVar27 = *(float *)(param_1 + 8);
  fVar28 = *(float *)(param_1 + 0x24);
  *(float *)this = *(float *)(param_1 + 8) * fVar3 +
                   *(float *)(param_1 + 4) * fVar2 + *(float *)param_1 * fVar1 +
                   fVar4 * *(float *)(param_1 + 0x24);
  *(float *)(this + 4) =
      fVar19 * fVar7 + fVar18 * fVar6 + fVar5 * fVar17 + fVar8 * fVar20;
  *(float *)(this + 8) =
      fVar23 * fVar11 + fVar22 * fVar10 + fVar21 * fVar9 + fVar12 * fVar24;
  *(float *)(this + 0xc) =
      fVar27 * fVar15 + fVar26 * fVar14 + fVar25 * fVar13 + fVar16 * fVar28;
  fVar17 = *(float *)(param_1 + 0xc);
  fVar18 = *(float *)(param_1 + 0x10);
  fVar19 = *(float *)(param_1 + 0x14);
  fVar20 = *(float *)(param_1 + 0x28);
  fVar21 = *(float *)(param_1 + 0xc);
  fVar22 = *(float *)(param_1 + 0x10);
  fVar23 = *(float *)(param_1 + 0x14);
  fVar24 = *(float *)(param_1 + 0x28);
  fVar25 = *(float *)(param_1 + 0xc);
  fVar26 = *(float *)(param_1 + 0x10);
  fVar27 = *(float *)(param_1 + 0x14);
  fVar28 = *(float *)(param_1 + 0x28);
  *(float *)(this + 0x10) =
      fVar4 * *(float *)(param_1 + 0x28) + *(float *)(param_1 + 0x14) * fVar3 +
      fVar2 * *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0xc) * fVar1;
  *(float *)(this + 0x14) =
      fVar8 * fVar20 + fVar19 * fVar7 + fVar6 * fVar18 + fVar17 * fVar5;
  *(float *)(this + 0x18) =
      fVar12 * fVar24 + fVar23 * fVar11 + fVar10 * fVar22 + fVar21 * fVar9;
  *(float *)(this + 0x1c) =
      fVar16 * fVar28 + fVar27 * fVar15 + fVar14 * fVar26 + fVar25 * fVar13;
  fVar17 = *(float *)(param_1 + 0x1c);
  fVar18 = *(float *)(param_1 + 0x18);
  fVar19 = *(float *)(param_1 + 0x20);
  fVar20 = *(float *)(param_1 + 0x2c);
  fVar21 = *(float *)(param_1 + 0x1c);
  fVar22 = *(float *)(param_1 + 0x18);
  fVar23 = *(float *)(param_1 + 0x20);
  fVar24 = *(float *)(param_1 + 0x2c);
  fVar25 = *(float *)(param_1 + 0x1c);
  fVar26 = *(float *)(param_1 + 0x18);
  fVar27 = *(float *)(param_1 + 0x20);
  fVar28 = *(float *)(param_1 + 0x2c);
  *(float *)(this + 0x20) =
      *(float *)(param_1 + 0x2c) * fVar4 + fVar3 * *(float *)(param_1 + 0x20) +
      *(float *)(param_1 + 0x18) * fVar1 + *(float *)(param_1 + 0x1c) * fVar2;
  *(float *)(this + 0x24) =
      fVar20 * fVar8 + fVar7 * fVar19 + fVar17 * fVar6 + fVar18 * fVar5;
  *(float *)(this + 0x28) =
      fVar24 * fVar12 + fVar11 * fVar23 + fVar22 * fVar9 + fVar21 * fVar10;
  *(float *)(this + 0x2c) =
      fVar28 * fVar16 + fVar15 * fVar27 + fVar26 * fVar13 + fVar25 * fVar14;
  *(float *)(this + 0x30) = fVar4;
  *(float *)(this + 0x34) = fVar8;
  *(float *)(this + 0x38) = fVar12;
  *(float *)(this + 0x3c) = fVar16;
  return;
}

/* public: class GmVec4 const & __thiscall GmMat4::operator[](unsigned
 * long)const  */

GmVec4 *__thiscall GmMat4::operator[](GmMat4 *this, ulong param_1)

{
  return (GmVec4 *)(this + param_1 * 0x10);
}

/* public: void __thiscall GmMat4::Set(class GmMat4 const &) */

void __thiscall GmMat4::Set(GmMat4 *this, GmMat4 *param_1)

{
  int iVar1;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)this = *(undefined4 *)param_1;
    param_1 = (GmMat4 *)((int)param_1 + 4);
    this = (GmMat4 *)((int)this + 4);
  }
  return;
}

/* public: void __thiscall GmMat4::Set(class GmIso4 const &) */

void __thiscall GmMat4::Set(GmMat4 *this, GmIso4 *param_1)

{
  undefined4 uVar1;

  uVar1 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x1c) = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x2c) = uVar1;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0x3f800000;
  return;
}

/* public: void __thiscall GmMat4::SetFrustumProjection(class GmFrustum const
 * &,unsigned long) */

void __thiscall GmMat4::SetFrustumProjection(GmMat4 *this, GmFrustum *param_1,
                                             ulong param_2)

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
  float local_20;
  float local_c;

  if (*(int *)param_1 != 0) {
    fVar5 = *(float *)(param_1 + 4);
    fVar6 = *(float *)(param_1 + 8);
    fVar1 = 2.0 / (*(float *)(param_1 + 0x10) * 2.0);
    if (param_2 == 0) {
      fVar2 = 2.0 / (*(float *)(param_1 + 0x18) * 2.0);
    } else {
      fVar2 = 1.0 / (*(float *)(param_1 + 0x18) * 2.0);
    }
    local_c = 2.0 / (*(float *)(param_1 + 0x14) * 2.0);
    local_20 = -fVar2 * *(float *)(param_1 + 0xc);
    if (param_2 != 0) {
      local_20 = local_20 + 0.5;
    }
    *(float *)this = fVar1;
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)(this + 8) = 0;
    *(float *)(this + 0xc) = -fVar1 * fVar5;
    *(undefined4 *)(this + 0x10) = 0;
    *(undefined4 *)(this + 0x18) = 0;
    *(float *)(this + 0x14) = local_c;
    *(float *)(this + 0x1c) = -local_c * fVar6;
    *(undefined4 *)(this + 0x20) = 0;
    *(undefined4 *)(this + 0x24) = 0;
    *(float *)(this + 0x28) = fVar2;
    *(float *)(this + 0x2c) = local_20;
    *(undefined4 *)(this + 0x30) = 0;
    *(undefined4 *)(this + 0x34) = 0;
    *(undefined4 *)(this + 0x38) = 0;
    *(undefined4 *)(this + 0x3c) = 0x3f800000;
    return;
  }
  fVar5 = *(float *)(param_1 + 0xc);
  fVar6 = *(float *)(param_1 + 0x18);
  fVar1 = *(float *)(param_1 + 4);
  fVar2 = *(float *)(param_1 + 8);
  fVar3 = *(float *)(param_1 + 0x10);
  fVar4 = *(float *)(param_1 + 0x14);
  fVar8 = fVar3 - fVar1;
  fVar7 = fVar4 - fVar2;
  if (param_2 == 0) {
    fVar9 = (fVar6 - fVar5) / 1.0;
    param_2 = (ulong)(fVar9 * (fVar6 + fVar5));
    fVar6 = fVar6 * -2.0 * fVar5;
  } else {
    param_2 = (ulong)((fVar6 - fVar5) / fVar6);
    fVar6 = -(float)param_2;
    fVar9 = fVar5;
  }
  *(float *)this = fVar8 / 2.0;
  *(undefined4 *)(this + 4) = 0;
  *(float *)(this + 8) = -(fVar8 / (fVar3 + fVar1));
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(float *)(this + 0x14) = fVar7 / 2.0;
  *(float *)(this + 0x18) = -((fVar4 + fVar2) / fVar7);
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(ulong *)(this + 0x28) = param_2;
  *(float *)(this + 0x2c) = fVar6 * fVar9;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0x3f800000;
  *(undefined4 *)(this + 0x3c) = 0;
  return;
}

/* public: void __thiscall GmMat4::SetIdentity(void) */

void __thiscall GmMat4::SetIdentity(GmMat4 *this)

{
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x14) = 0x3f800000;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x28) = 0x3f800000;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0x3f800000;
  return;
}

/* public: void __thiscall GmMat4::SetMult(class GmIso4 const &,class GmMat4
 * const &) */

void __thiscall GmMat4::SetMult(GmMat4 *this, GmIso4 *param_1, GmMat4 *param_2)

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
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;

  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_1 + 0xc);
  fVar3 = *(float *)(param_1 + 0x18);
  fVar4 = *(float *)(param_1 + 4);
  fVar5 = *(float *)(param_1 + 0x10);
  fVar6 = *(float *)(param_1 + 0x1c);
  fVar7 = *(float *)(param_1 + 8);
  fVar8 = *(float *)(param_1 + 0x14);
  fVar9 = *(float *)(param_1 + 0x20);
  fVar10 = *(float *)(param_1 + 0x24);
  fVar11 = *(float *)(param_1 + 0x28);
  fVar12 = *(float *)(param_1 + 0x2c);
  fVar13 = *(float *)(param_2 + 4);
  fVar14 = *(float *)param_2;
  fVar15 = *(float *)(param_2 + 8);
  fVar16 = *(float *)(param_2 + 4);
  fVar17 = *(float *)param_2;
  fVar18 = *(float *)(param_2 + 8);
  fVar19 = *(float *)(param_2 + 4);
  fVar20 = *(float *)param_2;
  fVar21 = *(float *)(param_2 + 8);
  fVar22 = *(float *)(param_2 + 0xc);
  *(float *)this = *(float *)(param_2 + 8) * fVar3 + *(float *)param_2 * fVar1 +
                   *(float *)(param_2 + 4) * fVar2;
  *(float *)(this + 4) = fVar5 * fVar13 + fVar4 * fVar14 + fVar6 * fVar15;
  *(float *)(this + 8) = fVar18 * fVar9 + fVar8 * fVar16 + fVar7 * fVar17;
  *(float *)(this + 0xc) =
      fVar21 * fVar12 + fVar20 * fVar10 + fVar19 * fVar11 + fVar22;
  fVar13 = *(float *)(param_2 + 0x10);
  fVar14 = *(float *)(param_2 + 0x14);
  fVar15 = *(float *)(param_2 + 0x18);
  fVar16 = *(float *)(param_2 + 0x10);
  fVar17 = *(float *)(param_2 + 0x14);
  fVar18 = *(float *)(param_2 + 0x18);
  fVar19 = *(float *)(param_2 + 0x10);
  fVar20 = *(float *)(param_2 + 0x14);
  fVar21 = *(float *)(param_2 + 0x18);
  fVar22 = *(float *)(param_2 + 0x1c);
  *(float *)(this + 0x10) = *(float *)(param_2 + 0x18) * fVar3 +
                            fVar2 * *(float *)(param_2 + 0x14) +
                            *(float *)(param_2 + 0x10) * fVar1;
  *(float *)(this + 0x14) = fVar15 * fVar6 + fVar5 * fVar14 + fVar13 * fVar4;
  *(float *)(this + 0x18) = fVar18 * fVar9 + fVar8 * fVar17 + fVar16 * fVar7;
  *(float *)(this + 0x1c) =
      fVar21 * fVar12 + fVar11 * fVar20 + fVar19 * fVar10 + fVar22;
  fVar13 = *(float *)(param_2 + 0x24);
  fVar14 = *(float *)(param_2 + 0x20);
  fVar15 = *(float *)(param_2 + 0x28);
  fVar16 = *(float *)(param_2 + 0x20);
  fVar17 = *(float *)(param_2 + 0x24);
  fVar18 = *(float *)(param_2 + 0x28);
  fVar19 = *(float *)(param_2 + 0x24);
  fVar20 = *(float *)(param_2 + 0x20);
  fVar21 = *(float *)(param_2 + 0x28);
  fVar22 = *(float *)(param_2 + 0x2c);
  *(float *)(this + 0x20) = fVar3 * *(float *)(param_2 + 0x28) +
                            *(float *)(param_2 + 0x20) * fVar1 +
                            *(float *)(param_2 + 0x24) * fVar2;
  *(float *)(this + 0x24) = fVar6 * fVar15 + fVar14 * fVar4 + fVar13 * fVar5;
  *(float *)(this + 0x28) = fVar9 * fVar18 + fVar17 * fVar8 + fVar16 * fVar7;
  *(float *)(this + 0x2c) =
      fVar12 * fVar21 + fVar20 * fVar10 + fVar19 * fVar11 + fVar22;
  fVar13 = *(float *)(param_2 + 0x30);
  fVar14 = *(float *)(param_2 + 0x34);
  fVar15 = *(float *)(param_2 + 0x38);
  fVar16 = *(float *)(param_2 + 0x30);
  fVar17 = *(float *)(param_2 + 0x34);
  fVar18 = *(float *)(param_2 + 0x38);
  fVar19 = *(float *)(param_2 + 0x34);
  fVar20 = *(float *)(param_2 + 0x30);
  fVar21 = *(float *)(param_2 + 0x38);
  fVar22 = *(float *)(param_2 + 0x3c);
  *(float *)(this + 0x30) = *(float *)(param_2 + 0x38) * fVar3 +
                            fVar2 * *(float *)(param_2 + 0x34) +
                            *(float *)(param_2 + 0x30) * fVar1;
  *(float *)(this + 0x34) = fVar13 * fVar4 + fVar14 * fVar5 + fVar15 * fVar6;
  *(float *)(this + 0x38) = fVar18 * fVar9 + fVar7 * fVar16 + fVar17 * fVar8;
  *(float *)(this + 0x3c) =
      fVar21 * fVar12 + fVar20 * fVar10 + fVar11 * fVar19 + fVar22;
  return;
}

/* public: void __thiscall GmMat4::SetMult(class GmMat4 const &,class GmMat4
 * const &) */

void __thiscall GmMat4::SetMult(GmMat4 *this, GmMat4 *param_1, GmMat4 *param_2)

{
  float *pfVar1;
  float *extraout_EDX;
  ulong uVar2;
  ulong uVar3;
  float *pfVar4;
  GmMat4 local_40[64];

  SetTranspose(local_40, param_1);
  uVar2 = 0;
  do {
    uVar3 = 0;
    operator[](param_2, uVar2);
    pfVar4 = (float *)this;
    do {
      pfVar1 = (float *)operator[](local_40, uVar3);
      uVar3 = uVar3 + 1;
      this = (GmMat4 *)(pfVar4 + 1);
      *pfVar4 = pfVar1[3] * extraout_EDX[3] + pfVar1[2] * extraout_EDX[2] +
                *extraout_EDX * *pfVar1 + pfVar1[1] * extraout_EDX[1];
      pfVar4 = (float *)this;
    } while (uVar3 < 4);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  return;
}

/* public: void __thiscall GmMat4::SetShadowPlaneProjection(class GmVec4 const
   &,class GmVec4 const
   &) */

void __thiscall GmMat4::SetShadowPlaneProjection(GmMat4 *this, GmVec4 *param_1,
                                                 GmVec4 *param_2)

{
  float fVar1;
  float fVar2;

  fVar2 = -(*(float *)(param_1 + 0xc) * *(float *)(param_2 + 0xc) +
            *(float *)(param_1 + 8) * *(float *)(param_2 + 8) +
            *(float *)(param_1 + 4) * *(float *)(param_2 + 4) +
            *(float *)param_1 * *(float *)param_2);
  fVar1 = *(float *)param_1;
  *(float *)this = fVar1 * *(float *)param_2;
  *(float *)(this + 4) = fVar1 * *(float *)(param_2 + 4);
  *(float *)(this + 8) = *(float *)(param_2 + 8) * fVar1;
  *(float *)(this + 0xc) = fVar1 * *(float *)(param_2 + 0xc);
  *(float *)this = fVar2 + *(float *)this;
  fVar1 = *(float *)(param_1 + 4);
  *(float *)(this + 0x10) = fVar1 * *(float *)param_2;
  *(float *)(this + 0x14) = fVar1 * *(float *)(param_2 + 4);
  *(float *)(this + 0x18) = *(float *)(param_2 + 8) * fVar1;
  *(float *)(this + 0x1c) = fVar1 * *(float *)(param_2 + 0xc);
  *(float *)(this + 0x14) = *(float *)(this + 0x14) + fVar2;
  fVar1 = *(float *)(param_1 + 8);
  *(float *)(this + 0x20) = fVar1 * *(float *)param_2;
  *(float *)(this + 0x24) = fVar1 * *(float *)(param_2 + 4);
  *(float *)(this + 0x28) = *(float *)(param_2 + 8) * fVar1;
  *(float *)(this + 0x2c) = fVar1 * *(float *)(param_2 + 0xc);
  *(float *)(this + 0x28) = fVar2 + *(float *)(this + 0x28);
  fVar1 = *(float *)(param_1 + 0xc);
  *(float *)(this + 0x30) = fVar1 * *(float *)param_2;
  *(float *)(this + 0x34) = fVar1 * *(float *)(param_2 + 4);
  *(float *)(this + 0x38) = *(float *)(param_2 + 8) * fVar1;
  *(float *)(this + 0x3c) = fVar1 * *(float *)(param_2 + 0xc);
  *(float *)(this + 0x3c) = fVar2 + *(float *)(this + 0x3c);
  return;
}

/* public: void __thiscall GmMat4::SetShadowPlaneProjectionDirectional(class
   GmVec3 const &,class GmVec4 const &) */

void __thiscall GmMat4::SetShadowPlaneProjectionDirectional(GmMat4 *this,
                                                            GmVec3 *param_1,
                                                            GmVec4 *param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  local_10 = *(undefined4 *)param_1;
  local_c = *(undefined4 *)(param_1 + 4);
  local_8 = *(undefined4 *)(param_1 + 8);
  local_4 = 0;
  SetShadowPlaneProjection(this, (GmVec4 *)&local_10, param_2);
  return;
}

/* public: void __thiscall GmMat4::SetShadowPlaneProjectionPoint(class GmVec3
   const &,class GmVec4 const &) */

void __thiscall GmMat4::SetShadowPlaneProjectionPoint(GmMat4 *this,
                                                      GmVec3 *param_1,
                                                      GmVec4 *param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  local_10 = *(undefined4 *)param_1;
  local_c = *(undefined4 *)(param_1 + 4);
  local_8 = *(undefined4 *)(param_1 + 8);
  local_4 = 0x3f800000;
  SetShadowPlaneProjection(this, (GmVec4 *)&local_10, param_2);
  return;
}

/* public: void __thiscall GmMat4::SetTranspose(class GmMat4 const &) */

void __thiscall GmMat4::SetTranspose(GmMat4 *this, GmMat4 *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x2c);
  return;
}

/* public: void __thiscall GmMat4::SetTranspose(class GmIso4 const &) */

void __thiscall GmMat4::SetTranspose(GmMat4 *this, GmIso4 *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x3c) = 0x3f800000;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  return;
}

/* public: void __thiscall GmMat4::SetTransposeXY(class GmIso3 const &) */

void __thiscall GmMat4::SetTransposeXY(GmMat4 *this, GmIso3 *param_1)

{
  undefined4 uVar1;
  float *pfVar2;

  pfVar2 = GmVec2::operator[]((GmVec2 *)param_1, 0);
  *(float *)this = *pfVar2;
  pfVar2 = GmVec2::operator[]((GmVec2 *)(param_1 + 8), 1);
  *(float *)(this + 0x14) = *pfVar2;
  pfVar2 = GmVec2::operator[]((GmVec2 *)(param_1 + 8), 0);
  *(float *)(this + 4) = *pfVar2;
  pfVar2 = GmVec2::operator[]((GmVec2 *)param_1, 1);
  *(float *)(this + 0x10) = *pfVar2;
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x34) = uVar1;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0x3f800000;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0x3f800000;
  *(undefined4 *)(this + 0x2c) = 0;
  return;
}

/* public: void __thiscall GmMat4::SetTransposeXY_TransZ(class GmIso3 const &)
 */

void __thiscall GmMat4::SetTransposeXY_TransZ(GmMat4 *this, GmIso3 *param_1)

{
  undefined4 uVar1;
  float *pfVar2;

  pfVar2 = GmVec2::operator[]((GmVec2 *)param_1, 0);
  *(float *)this = *pfVar2;
  pfVar2 = GmVec2::operator[]((GmVec2 *)(param_1 + 8), 1);
  *(float *)(this + 0x14) = *pfVar2;
  pfVar2 = GmVec2::operator[]((GmVec2 *)(param_1 + 8), 0);
  *(float *)(this + 4) = *pfVar2;
  pfVar2 = GmVec2::operator[]((GmVec2 *)param_1, 1);
  *(float *)(this + 0x10) = *pfVar2;
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x24) = uVar1;
  *(undefined4 *)(this + 0x28) = 0x3f800000;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0x3f800000;
  return;
}

/* public: void __thiscall GmMat4::SetXY(class GmIso3 const &) */

void __thiscall GmMat4::SetXY(GmMat4 *this, GmIso3 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;

  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar1;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = uVar2;
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  uVar2 = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x14) = uVar1;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = uVar2;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0x3f800000;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0x3f800000;
  return;
}

/* public: void __thiscall GmMat4::Transpose(void) */

void __thiscall GmMat4::Transpose(GmMat4 *this)

{
  undefined4 uVar1;

  uVar1 = *(undefined4 *)(this + 4);
  *(undefined4 *)(this + 4) = *(undefined4 *)(this + 0x10);
  *(undefined4 *)(this + 0x10) = uVar1;
  uVar1 = *(undefined4 *)(this + 8);
  *(undefined4 *)(this + 8) = *(undefined4 *)(this + 0x20);
  *(undefined4 *)(this + 0x20) = uVar1;
  uVar1 = *(undefined4 *)(this + 0xc);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(this + 0x30);
  *(undefined4 *)(this + 0x30) = uVar1;
  uVar1 = *(undefined4 *)(this + 0x18);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(this + 0x24);
  *(undefined4 *)(this + 0x24) = uVar1;
  uVar1 = *(undefined4 *)(this + 0x1c);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(this + 0x34);
  *(undefined4 *)(this + 0x34) = uVar1;
  uVar1 = *(undefined4 *)(this + 0x2c);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(this + 0x38);
  *(undefined4 *)(this + 0x38) = uVar1;
  return;
}
