
/* public: void __thiscall GmFrustum::ArchiveFrustum(class CClassicArchive &) */

void __thiscall GmFrustum::ArchiveFrustum(GmFrustum *this,
                                          CClassicArchive *param_1)

{
  CClassicArchive::DoBool(param_1, (int *)this, 1);
  if (*(int *)this != 0) {
    GmBoxAligned::ArchiveABox((GmBoxAligned *)(this + 4), param_1);
    return;
  }
  CClassicArchive::DoData(param_1, this + 4, 0x18);
  return;
}

/* public: void __thiscall GmFrustum::ArchiveFrustumOld1(class CClassicArchive
 * &) */

void __thiscall GmFrustum::ArchiveFrustumOld1(GmFrustum *this,
                                              CClassicArchive *param_1)

{
  float *this_00;
  float fVar1;
  float fVar2;
  float fVar3;

  CClassicArchive::DoBool(param_1, (int *)this, 1);
  this_00 = (float *)(this + 4);
  GmBoxAligned::ArchiveABoxOld1((GmBoxAligned *)this_00, param_1);
  if (*(int *)this == 0) {
    fVar1 = *this_00;
    fVar2 = *(float *)(this + 8);
    fVar3 = *(float *)(this + 0xc);
    *this_00 = *this_00 - *(float *)(this + 0x10);
    *(float *)(this + 8) = *(float *)(this + 8) - *(float *)(this + 0x14);
    *(float *)(this + 0xc) = *(float *)(this + 0xc) - *(float *)(this + 0x18);
    *(float *)(this + 0x10) = *(float *)(this + 0x10) + fVar1;
    *(float *)(this + 0x14) = *(float *)(this + 0x14) + fVar2;
    *(float *)(this + 0x18) = *(float *)(this + 0x18) + fVar3;
  }
  return;
}

/* public: void __thiscall GmFrustum::ChangeHeightByAspect(float) */

void __thiscall GmFrustum::ChangeHeightByAspect(GmFrustum *this, float param_1)

{
  float fVar1;
  float fVar2;

  if (*(int *)this != 0) {
    fVar1 = *(float *)(this + 0x10);
    *(undefined4 *)(this + 4) = *(undefined4 *)(this + 4);
    *(undefined4 *)(this + 8) = *(undefined4 *)(this + 8);
    *(undefined4 *)(this + 0xc) = *(undefined4 *)(this + 0xc);
    *(float *)(this + 0x10) = fVar1;
    *(float *)(this + 0x14) = fVar1 / param_1;
    *(undefined4 *)(this + 0x18) = *(undefined4 *)(this + 0x18);
    return;
  }
  fVar2 = ((*(float *)(this + 0x10) - *(float *)(this + 4)) * 0.5) / param_1;
  fVar1 = (*(float *)(this + 0x14) + *(float *)(this + 8)) * 0.5;
  *(float *)(this + 8) = fVar1 - fVar2;
  *(float *)(this + 0x14) = fVar2 + fVar1;
  return;
}

/* public: void __thiscall GmFrustum::ChangeWidthByAspect(float) */

void __thiscall GmFrustum::ChangeWidthByAspect(GmFrustum *this, float param_1)

{
  float fVar1;
  float fVar2;

  if (*(int *)this != 0) {
    *(undefined4 *)(this + 4) = *(undefined4 *)(this + 4);
    *(undefined4 *)(this + 8) = *(undefined4 *)(this + 8);
    *(undefined4 *)(this + 0xc) = *(undefined4 *)(this + 0xc);
    *(float *)(this + 0x10) = *(float *)(this + 0x14) * param_1;
    *(float *)(this + 0x14) = *(float *)(this + 0x14);
    *(undefined4 *)(this + 0x18) = *(undefined4 *)(this + 0x18);
    return;
  }
  fVar2 = (*(float *)(this + 0x14) - *(float *)(this + 8)) * 0.5 * param_1;
  fVar1 = (*(float *)(this + 4) + *(float *)(this + 0x10)) * 0.5;
  *(float *)(this + 4) = fVar1 - fVar2;
  *(float *)(this + 0x10) = fVar2 + fVar1;
  return;
}

/* public: void __thiscall GmFrustum::ExtrudeFromZ(float,float,float,class
 * GmVec3 &)const  */

void __thiscall GmFrustum::ExtrudeFromZ(GmFrustum *this, float param_1,
                                        float param_2, float param_3,
                                        GmVec3 *param_4)

{
  float fVar1;

  fVar1 = *(float *)(this + 0x14);
  *(float *)param_4 = param_1 * param_3 * *(float *)(this + 0x10);
  *(float *)(param_4 + 4) = fVar1 * param_3 * param_2;
  *(float *)(param_4 + 8) = param_3;
  return;
}

/* public: void __thiscall GmFrustum::GetAspect(class GmRectAligned &)const  */

void __thiscall GmFrustum::GetAspect(GmFrustum *this, GmRectAligned *param_1)

{
  undefined4 uVar1;

  uVar1 = *(undefined4 *)(this + 8);
  *(undefined4 *)param_1 = *(undefined4 *)(this + 4);
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = *(undefined4 *)(this + 0x14);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(this + 0x10);
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return;
}

/* public: void __thiscall GmFrustum::GetBBox(class GmBoxAligned &)const  */

void __thiscall GmFrustum::GetBBox(GmFrustum *this, GmBoxAligned *param_1)

{
  float local_18;
  float local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  undefined4 local_4;

  if (*(int *)this != 0) {
    *(undefined4 *)param_1 = *(undefined4 *)(this + 4);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(this + 8);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(this + 0xc);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(this + 0x10);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(this + 0x14);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(this + 0x18);
    return;
  }
  local_c = *(float *)(this + 4) * *(float *)(this + 0x18);
  local_8 = *(float *)(this + 8) * *(float *)(this + 0x18);
  local_4 = *(undefined4 *)(this + 0xc);
  local_18 = *(float *)(this + 0x10) * *(float *)(this + 0x18);
  local_14 = *(float *)(this + 0x14) * *(float *)(this + 0x18);
  local_10 = *(undefined4 *)(this + 0x18);
  GmBoxAligned::SetMinMax(param_1, (GmVec3 *)&local_c, (GmVec3 *)&local_18);
  return;
}

/* public: float __thiscall GmFrustum::GetFarZ(void)const  */

float __thiscall GmFrustum::GetFarZ(GmFrustum *this)

{
  if (*(int *)this != 0) {
    return *(float *)(this + 0x18) + *(float *)(this + 0xc);
  }
  return *(float *)(this + 0x18);
}

/* public: float __thiscall GmFrustum::GetFovY(void)const  */

float __thiscall GmFrustum::GetFovY(GmFrustum *this)

{
  float10 fVar1;

  fVar1 = (float10)__CIatan();
  return (((float)fVar1 + (float)fVar1) / 3.141593) * 180.0;
}

/* public: float __thiscall GmFrustum::GetNearZ(void)const  */

float __thiscall GmFrustum::GetNearZ(GmFrustum *this)

{
  if (*(int *)this != 0) {
    return *(float *)(this + 0xc) - *(float *)(this + 0x18);
  }
  return *(float *)(this + 0xc);
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall GmFrustum::GetPlaneEqs6(class GmVec4 *,class GmIso4
 * const *)const  */

void __thiscall GmFrustum::GetPlaneEqs6(GmFrustum *this, GmVec4 *param_1,
                                        GmIso4 *param_2)

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
  int iVar12;
  float10 fVar13;
  float local_c;
  float local_8;

  if (*(int *)this == 0) {
    fVar11 = *(float *)(this + 0xc);
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0xbf800000;
    *(float *)(param_1 + 0xc) = -0.0 - fVar11 * -1.0;
    local_c = -1.0;
    local_8 = 0.0;
    fVar11 = *(float *)(this + 4);
    fVar1 = fVar11 * fVar11 + 1.0;
    if (_DAT_00d1a830 < fVar1 != (NAN(_DAT_00d1a830) || NAN(fVar1))) {
      fVar13 = (float10)__CIsqrt();
      fVar1 = 1.0 / (float)fVar13;
      local_c = fVar1 * -1.0;
      local_8 = fVar1 * 0.0;
      fVar11 = fVar11 * fVar1;
    }
    *(float *)(param_1 + 0x10) = local_c;
    *(float *)(param_1 + 0x14) = local_8;
    *(float *)(param_1 + 0x18) = fVar11;
    *(float *)(param_1 + 0x1c) =
        (-local_c * 0.0 - local_8 * 0.0) - fVar11 * 0.0;
    local_c = 1.0;
    local_8 = 0.0;
    fVar1 = -*(float *)(this + 0x10);
    fVar11 = fVar1 * fVar1 + 1.0;
    if (_DAT_00d1a830 < fVar11 != (NAN(_DAT_00d1a830) || NAN(fVar11))) {
      fVar13 = (float10)__CIsqrt();
      local_c = 1.0 / (float)fVar13;
      local_8 = local_c * 0.0;
      fVar1 = fVar1 * local_c;
    }
    *(float *)(param_1 + 0x20) = local_c;
    *(float *)(param_1 + 0x24) = local_8;
    *(float *)(param_1 + 0x28) = fVar1;
    *(float *)(param_1 + 0x2c) = (-local_c * 0.0 - local_8 * 0.0) - fVar1 * 0.0;
    local_c = 0.0;
    local_8 = -1.0;
    fVar11 = *(float *)(this + 8);
    fVar1 = fVar11 * fVar11 + 1.0;
    if (_DAT_00d1a830 < fVar1 != (NAN(_DAT_00d1a830) || NAN(fVar1))) {
      fVar13 = (float10)__CIsqrt();
      fVar1 = 1.0 / (float)fVar13;
      local_c = fVar1 * 0.0;
      local_8 = fVar1 * -1.0;
      fVar11 = fVar11 * fVar1;
    }
    *(float *)(param_1 + 0x30) = local_c;
    *(float *)(param_1 + 0x34) = local_8;
    *(float *)(param_1 + 0x38) = fVar11;
    *(float *)(param_1 + 0x3c) =
        (-local_c * 0.0 - local_8 * 0.0) - fVar11 * 0.0;
    local_c = 0.0;
    local_8 = 1.0;
    fVar1 = -*(float *)(this + 0x14);
    fVar11 = fVar1 * fVar1 + 1.0;
    if (_DAT_00d1a830 < fVar11 != (NAN(_DAT_00d1a830) || NAN(fVar11))) {
      fVar13 = (float10)__CIsqrt();
      local_8 = 1.0 / (float)fVar13;
      local_c = local_8 * 0.0;
      fVar1 = local_8 * fVar1;
    }
    *(float *)(param_1 + 0x40) = local_c;
    *(float *)(param_1 + 0x44) = local_8;
    *(float *)(param_1 + 0x48) = fVar1;
    *(float *)(param_1 + 0x4c) = (-local_c * 0.0 - local_8 * 0.0) - fVar1 * 0.0;
    if (*(int *)this == 0) {
      fVar11 = *(float *)(this + 0x18);
    } else {
      fVar11 = *(float *)(this + 0x18) + *(float *)(this + 0xc);
    }
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined4 *)(param_1 + 0x58) = 0x3f800000;
  } else {
    fVar1 = *(float *)(this + 4);
    fVar2 = *(float *)(this + 0x10);
    fVar3 = *(float *)(this + 8);
    fVar4 = *(float *)(this + 0x14);
    fVar5 = *(float *)(this + 0xc);
    fVar6 = *(float *)(this + 0x18);
    fVar7 = *(float *)(this + 4);
    fVar8 = *(float *)(this + 0x10);
    fVar9 = *(float *)(this + 0x14);
    fVar10 = *(float *)(this + 8);
    fVar11 = *(float *)(this + 0x18) + *(float *)(this + 0xc);
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0xbf800000;
    *(float *)(param_1 + 0xc) = -0.0 - (fVar5 - fVar6) * -1.0;
    *(undefined4 *)(param_1 + 0x10) = 0xbf800000;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(float *)(param_1 + 0x1c) = ((fVar1 - fVar2) - 0.0) - 0.0;
    *(undefined4 *)(param_1 + 0x20) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(float *)(param_1 + 0x2c) = ((fVar7 + fVar8) * -1.0 - 0.0) - 0.0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0xbf800000;
    *(float *)(param_1 + 0x3c) = (-0.0 - (fVar3 - fVar4) * -1.0) - 0.0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0x3f800000;
    *(float *)(param_1 + 0x4c) = (-0.0 - (fVar9 + fVar10)) - 0.0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined4 *)(param_1 + 0x58) = 0x3f800000;
  }
  *(float *)(param_1 + 0x5c) = -0.0 - fVar11;
  if (param_2 != (GmIso4 *)0x0) {
    iVar12 = 6;
    do {
      GmVec4::PlaneEqMult(param_1, param_2);
      param_1 = param_1 + 0x10;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  return;
}

/* public: float __thiscall GmFrustum::GetRatioXY(void)const  */

float __thiscall GmFrustum::GetRatioXY(GmFrustum *this)

{
  return ((*(float *)(this + 0x10) + *(float *)(this + 4)) -
          (*(float *)(this + 4) - *(float *)(this + 0x10))) /
         ((*(float *)(this + 0x14) + *(float *)(this + 8)) -
          (*(float *)(this + 8) - *(float *)(this + 0x14)));
}

/* public: void __thiscall GmFrustum::GetRectZ(float,class GmRectAligned &)const
 */

void __thiscall GmFrustum::GetRectZ(GmFrustum *this, float param_1,
                                    GmRectAligned *param_2)

{
  float fVar1;
  float fVar2;

  fVar1 = *(float *)(this + 8);
  if (*(int *)this != 0) {
    fVar2 = *(float *)(this + 0x14);
    *(float *)param_2 = *(float *)(this + 4) - *(float *)(this + 0x10);
    *(float *)(param_2 + 4) = fVar1 - fVar2;
    fVar1 = *(float *)(this + 0x14);
    fVar2 = *(float *)(this + 8);
    *(float *)(param_2 + 8) = *(float *)(this + 0x10) + *(float *)(this + 4);
    *(float *)(param_2 + 0xc) = fVar1 + fVar2;
    return;
  }
  *(float *)param_2 = *(float *)(this + 4) * param_1;
  *(float *)(param_2 + 4) = param_1 * fVar1;
  fVar1 = *(float *)(this + 0x14);
  *(float *)(param_2 + 8) = param_1 * *(float *)(this + 0x10);
  *(float *)(param_2 + 0xc) = fVar1 * param_1;
  return;
}

/* public: void __thiscall GmFrustum::GetVertices4AtZ(class GmVec3 *,float)const
 */

void __thiscall GmFrustum::GetVertices4AtZ(GmFrustum *this, GmVec3 *param_1,
                                           float param_2)

{
  float fVar1;

  fVar1 = *(float *)(this + 8);
  *(float *)param_1 = *(float *)(this + 4) * param_2;
  *(float *)(param_1 + 4) = param_2 * fVar1;
  *(float *)(param_1 + 8) = param_2;
  fVar1 = *(float *)(this + 8);
  *(float *)(param_1 + 0xc) = *(float *)(this + 0x10) * param_2;
  *(float *)(param_1 + 0x10) = param_2 * fVar1;
  *(float *)(param_1 + 0x14) = param_2;
  fVar1 = *(float *)(this + 0x14);
  *(float *)(param_1 + 0x18) = *(float *)(this + 4) * param_2;
  *(float *)(param_1 + 0x1c) = fVar1 * param_2;
  *(float *)(param_1 + 0x20) = param_2;
  fVar1 = *(float *)(this + 0x14);
  *(float *)(param_1 + 0x24) = *(float *)(this + 0x10) * param_2;
  *(float *)(param_1 + 0x28) = fVar1 * param_2;
  *(float *)(param_1 + 0x2c) = param_2;
  return;
}

/* public: unsigned long __thiscall GmFrustum::IsValid(void)const  */

ulong __thiscall GmFrustum::IsValid(GmFrustum *this)

{
  if (*(int *)this != 0) {
    if (0.0 <= *(float *)(this + 0x10)) {
      return 1;
    }
    return 0;
  }
  if (((1e-05 < *(float *)(this + 0x10) - *(float *)(this + 4) !=
        NAN(*(float *)(this + 0x10) - *(float *)(this + 4))) &&
       (1e-05 < *(float *)(this + 0x14) - *(float *)(this + 8))) &&
      (1e-05 < *(float *)(this + 0x18) - *(float *)(this + 0xc))) {
    return 1;
  }
  return 0;
}

/* public: void __thiscall GmFrustum::Scale(float,float) */

void __thiscall GmFrustum::Scale(GmFrustum *this, float param_1, float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;

  if (*(int *)this != 0) {
    *(undefined4 *)(this + 4) = *(undefined4 *)(this + 4);
    *(undefined4 *)(this + 8) = *(undefined4 *)(this + 8);
    *(undefined4 *)(this + 0xc) = *(undefined4 *)(this + 0xc);
    *(float *)(this + 0x10) = *(float *)(this + 0x10) * param_1;
    *(float *)(this + 0x14) = *(float *)(this + 0x14) * param_2;
    *(undefined4 *)(this + 0x18) = *(undefined4 *)(this + 0x18);
    return;
  }
  fVar1 = (*(float *)(this + 0x10) - *(float *)(this + 4)) * param_1 * 0.5;
  fVar2 = (*(float *)(this + 0x14) - *(float *)(this + 8)) * param_2 * 0.5;
  fVar3 = (*(float *)(this + 4) + *(float *)(this + 0x10)) * 0.5;
  fVar4 = (*(float *)(this + 0x14) + *(float *)(this + 8)) * 0.5;
  *(float *)(this + 4) = fVar3 - fVar1;
  *(float *)(this + 0x10) = fVar1 + fVar3;
  *(float *)(this + 8) = fVar4 - fVar2;
  *(float *)(this + 0x14) = fVar2 + fVar4;
  return;
}

/* public: void __thiscall GmFrustum::Set(float,float,float,float) */

void __thiscall GmFrustum::Set(GmFrustum *this, float param_1, float param_2,
                               float param_3, float param_4)

{
  float fVar1;
  undefined4 in_EDX;
  float10 fVar2;

  fVar2 = (float10)__CItan((float10 *)this, in_EDX);
  fVar1 = (float)fVar2;
  *(undefined4 *)this = 0;
  *(float *)(this + 0xc) = param_3;
  *(float *)(this + 0x18) = param_4;
  *(float *)(this + 0x10) = fVar1 * param_2;
  *(float *)(this + 4) = -(fVar1 * param_2);
  *(float *)(this + 0x14) = fVar1;
  *(float *)(this + 8) = -fVar1;
  return;
}

/* public: void __thiscall GmFrustum::Set(class GmBoxOriented const &) */

void __thiscall GmFrustum::Set(GmFrustum *this, GmBoxOriented *param_1)

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

  fVar1 = *(float *)(param_1 + 0x30);
  fVar2 = *(float *)(param_1 + 0x34);
  fVar3 = *(float *)(param_1 + 0x38);
  fVar4 = *(float *)(param_1 + 0x34);
  fVar5 = *(float *)(param_1 + 4);
  fVar6 = *(float *)param_1;
  fVar7 = *(float *)(param_1 + 0x30);
  fVar8 = *(float *)(param_1 + 8);
  fVar9 = *(float *)(param_1 + 0x38);
  fVar10 = *(float *)(param_1 + 0x24);
  fVar11 = *(float *)(param_1 + 0x10);
  fVar12 = *(float *)(param_1 + 0x34);
  fVar13 = *(float *)(param_1 + 0xc);
  fVar14 = *(float *)(param_1 + 0x30);
  fVar15 = *(float *)(param_1 + 0x14);
  fVar16 = *(float *)(param_1 + 0x38);
  fVar17 = *(float *)(param_1 + 0x28);
  fVar18 = *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x38) +
           *(float *)(param_1 + 0x18) * *(float *)(param_1 + 0x30) +
           *(float *)(param_1 + 0x1c) * *(float *)(param_1 + 0x34) +
           *(float *)(param_1 + 0x2c);
  *(float *)(this + 0xc) = fVar18;
  *(float *)(this + 0x18) = fVar18;
  fVar4 = (fVar8 * fVar9 + fVar6 * fVar7 + fVar4 * fVar5 + fVar10) / fVar18;
  *(float *)(this + 0x10) = fVar4;
  *(float *)(this + 4) = fVar4;
  fVar18 =
      (fVar15 * fVar16 + fVar13 * fVar14 + fVar11 * fVar12 + fVar17) / fVar18;
  *(float *)(this + 0x14) = fVar18;
  *(float *)(this + 8) = fVar18;
  fVar13 = -fVar1;
  fVar4 = *(float *)param_1;
  fVar5 = *(float *)(param_1 + 4);
  fVar6 = *(float *)(param_1 + 8);
  fVar7 = *(float *)(param_1 + 0x24);
  fVar8 = *(float *)(param_1 + 0x10);
  fVar9 = *(float *)(param_1 + 0xc);
  fVar10 = *(float *)(param_1 + 0x14);
  fVar11 = *(float *)(param_1 + 0x28);
  fVar12 = *(float *)(param_1 + 0x2c) + *(float *)(param_1 + 0x20) * fVar3 +
           *(float *)(param_1 + 0x1c) * fVar2 +
           *(float *)(param_1 + 0x18) * fVar13;
  if (fVar12 < *(float *)(this + 0xc)) {
    *(float *)(this + 0xc) = fVar12;
  }
  if (*(float *)(this + 0x18) < fVar12 !=
      (NAN(*(float *)(this + 0x18)) || NAN(fVar12))) {
    *(float *)(this + 0x18) = fVar12;
  }
  fVar5 =
      (1.0 / fVar12) * (fVar2 * fVar5 + fVar13 * fVar4 + fVar3 * fVar6 + fVar7);
  fVar4 = (1.0 / fVar12) *
          (fVar10 * fVar3 + fVar13 * fVar9 + fVar8 * fVar2 + fVar11);
  if (*(float *)(this + 0x10) < fVar5 ==
      (NAN(*(float *)(this + 0x10)) || NAN(fVar5))) {
    if (fVar5 < *(float *)(this + 4)) {
      *(float *)(this + 4) = fVar5;
    }
  } else {
    *(float *)(this + 0x10) = fVar5;
  }
  if (*(float *)(this + 0x14) < fVar4 ==
      (NAN(*(float *)(this + 0x14)) || NAN(fVar4))) {
    if (fVar4 < *(float *)(this + 8)) {
      *(float *)(this + 8) = fVar4;
    }
  } else {
    *(float *)(this + 0x14) = fVar4;
  }
  fVar12 = -fVar2;
  fVar4 = *(float *)(param_1 + 4);
  fVar5 = *(float *)param_1;
  fVar6 = *(float *)(param_1 + 8);
  fVar7 = *(float *)(param_1 + 0x24);
  fVar8 = *(float *)(param_1 + 0x10);
  fVar9 = *(float *)(param_1 + 0xc);
  fVar10 = *(float *)(param_1 + 0x14);
  fVar11 = *(float *)(param_1 + 0x28);
  fVar14 = *(float *)(param_1 + 0x20) * fVar3 +
           fVar1 * *(float *)(param_1 + 0x18) +
           fVar12 * *(float *)(param_1 + 0x1c) + *(float *)(param_1 + 0x2c);
  if (fVar14 < *(float *)(this + 0xc)) {
    *(float *)(this + 0xc) = fVar14;
  }
  if (*(float *)(this + 0x18) < fVar14 !=
      (NAN(*(float *)(this + 0x18)) || NAN(fVar14))) {
    *(float *)(this + 0x18) = fVar14;
  }
  fVar5 =
      (1.0 / fVar14) * (fVar6 * fVar3 + fVar5 * fVar1 + fVar12 * fVar4 + fVar7);
  fVar4 = (1.0 / fVar14) *
          (fVar10 * fVar3 + fVar1 * fVar9 + fVar8 * fVar12 + fVar11);
  if (*(float *)(this + 0x10) < fVar5 ==
      (NAN(*(float *)(this + 0x10)) || NAN(fVar5))) {
    if (fVar5 < *(float *)(this + 4)) {
      *(float *)(this + 4) = fVar5;
    }
  } else {
    *(float *)(this + 0x10) = fVar5;
  }
  if (*(float *)(this + 0x14) < fVar4 ==
      (NAN(*(float *)(this + 0x14)) || NAN(fVar4))) {
    if (fVar4 < *(float *)(this + 8)) {
      *(float *)(this + 8) = fVar4;
    }
  } else {
    *(float *)(this + 0x14) = fVar4;
  }
  fVar4 = *(float *)param_1;
  fVar5 = *(float *)(param_1 + 4);
  fVar6 = *(float *)(param_1 + 8);
  fVar7 = *(float *)(param_1 + 0x24);
  fVar8 = *(float *)(param_1 + 0x10);
  fVar9 = *(float *)(param_1 + 0xc);
  fVar10 = *(float *)(param_1 + 0x14);
  fVar11 = *(float *)(param_1 + 0x28);
  fVar14 = *(float *)(param_1 + 0x20) * fVar3 +
           fVar12 * *(float *)(param_1 + 0x1c) +
           *(float *)(param_1 + 0x18) * fVar13 + *(float *)(param_1 + 0x2c);
  if (fVar14 < *(float *)(this + 0xc)) {
    *(float *)(this + 0xc) = fVar14;
  }
  if (*(float *)(this + 0x18) < fVar14 !=
      (NAN(*(float *)(this + 0x18)) || NAN(fVar14))) {
    *(float *)(this + 0x18) = fVar14;
  }
  fVar5 = (fVar14 / 1.0) *
          (fVar7 + fVar6 * fVar3 + fVar12 * fVar5 + fVar13 * fVar4);
  fVar4 = (fVar14 / 1.0) *
          (fVar10 * fVar3 + fVar13 * fVar9 + fVar8 * fVar12 + fVar11);
  if (*(float *)(this + 0x10) < fVar5 ==
      (NAN(*(float *)(this + 0x10)) || NAN(fVar5))) {
    if (fVar5 < *(float *)(this + 4)) {
      *(float *)(this + 4) = fVar5;
    }
  } else {
    *(float *)(this + 0x10) = fVar5;
  }
  if (*(float *)(this + 0x14) < fVar4 ==
      (NAN(*(float *)(this + 0x14)) || NAN(fVar4))) {
    if (fVar4 < *(float *)(this + 8)) {
      *(float *)(this + 8) = fVar4;
    }
  } else {
    *(float *)(this + 0x14) = fVar4;
  }
  fVar3 = -fVar3;
  fVar4 = *(float *)param_1;
  fVar5 = *(float *)(param_1 + 4);
  fVar6 = *(float *)(param_1 + 8);
  fVar7 = *(float *)(param_1 + 0x24);
  fVar8 = *(float *)(param_1 + 0x10);
  fVar9 = *(float *)(param_1 + 0xc);
  fVar10 = *(float *)(param_1 + 0x14);
  fVar11 = *(float *)(param_1 + 0x28);
  fVar14 = fVar1 * *(float *)(param_1 + 0x18) +
           *(float *)(param_1 + 0x1c) * fVar2 +
           *(float *)(param_1 + 0x20) * fVar3 + *(float *)(param_1 + 0x2c);
  if (fVar14 < *(float *)(this + 0xc)) {
    *(float *)(this + 0xc) = fVar14;
  }
  if (*(float *)(this + 0x18) < fVar14 !=
      (NAN(*(float *)(this + 0x18)) || NAN(fVar14))) {
    *(float *)(this + 0x18) = fVar14;
  }
  fVar5 =
      (fVar14 / 1.0) * (fVar2 * fVar5 + fVar4 * fVar1 + fVar3 * fVar6 + fVar7);
  fVar4 = (fVar14 / 1.0) *
          (fVar10 * fVar3 + fVar1 * fVar9 + fVar8 * fVar2 + fVar11);
  if (*(float *)(this + 0x10) < fVar5 ==
      (NAN(*(float *)(this + 0x10)) || NAN(fVar5))) {
    if (fVar5 < *(float *)(this + 4)) {
      *(float *)(this + 4) = fVar5;
    }
  } else {
    *(float *)(this + 0x10) = fVar5;
  }
  if (*(float *)(this + 0x14) < fVar4 ==
      (NAN(*(float *)(this + 0x14)) || NAN(fVar4))) {
    if (fVar4 < *(float *)(this + 8)) {
      *(float *)(this + 8) = fVar4;
    }
  } else {
    *(float *)(this + 0x14) = fVar4;
  }
  fVar4 = *(float *)param_1;
  fVar5 = *(float *)(param_1 + 4);
  fVar6 = *(float *)(param_1 + 8);
  fVar7 = *(float *)(param_1 + 0x24);
  fVar8 = *(float *)(param_1 + 0x10);
  fVar9 = *(float *)(param_1 + 0xc);
  fVar10 = *(float *)(param_1 + 0x14);
  fVar11 = *(float *)(param_1 + 0x28);
  fVar14 = *(float *)(param_1 + 0x2c) + *(float *)(param_1 + 0x1c) * fVar2 +
           *(float *)(param_1 + 0x18) * fVar13 +
           *(float *)(param_1 + 0x20) * fVar3;
  if (fVar14 < *(float *)(this + 0xc)) {
    *(float *)(this + 0xc) = fVar14;
  }
  if (*(float *)(this + 0x18) < fVar14 !=
      (NAN(*(float *)(this + 0x18)) || NAN(fVar14))) {
    *(float *)(this + 0x18) = fVar14;
  }
  fVar4 =
      (1.0 / fVar14) * (fVar2 * fVar5 + fVar13 * fVar4 + fVar3 * fVar6 + fVar7);
  fVar2 = (1.0 / fVar14) *
          (fVar10 * fVar3 + fVar13 * fVar9 + fVar8 * fVar2 + fVar11);
  if (*(float *)(this + 0x10) < fVar4 ==
      (NAN(*(float *)(this + 0x10)) || NAN(fVar4))) {
    if (fVar4 < *(float *)(this + 4)) {
      *(float *)(this + 4) = fVar4;
    }
  } else {
    *(float *)(this + 0x10) = fVar4;
  }
  if (*(float *)(this + 0x14) < fVar2 ==
      (NAN(*(float *)(this + 0x14)) || NAN(fVar2))) {
    if (fVar2 < *(float *)(this + 8)) {
      *(float *)(this + 8) = fVar2;
    }
  } else {
    *(float *)(this + 0x14) = fVar2;
  }
  fVar2 = *(float *)(param_1 + 4);
  fVar4 = *(float *)param_1;
  fVar5 = *(float *)(param_1 + 8);
  fVar6 = *(float *)(param_1 + 0x24);
  fVar7 = *(float *)(param_1 + 0x10);
  fVar8 = *(float *)(param_1 + 0xc);
  fVar9 = *(float *)(param_1 + 0x14);
  fVar10 = *(float *)(param_1 + 0x28);
  fVar11 = *(float *)(param_1 + 0x2c) + fVar3 * *(float *)(param_1 + 0x20) +
           *(float *)(param_1 + 0x1c) * fVar12 +
           *(float *)(param_1 + 0x18) * fVar1;
  if (fVar11 < *(float *)(this + 0xc)) {
    *(float *)(this + 0xc) = fVar11;
  }
  if (*(float *)(this + 0x18) < fVar11 !=
      (NAN(*(float *)(this + 0x18)) || NAN(fVar11))) {
    *(float *)(this + 0x18) = fVar11;
  }
  fVar2 =
      (fVar11 / 1.0) * (fVar4 * fVar1 + fVar12 * fVar2 + fVar3 * fVar5 + fVar6);
  fVar1 = (fVar11 / 1.0) *
          (fVar9 * fVar3 + fVar1 * fVar8 + fVar7 * fVar12 + fVar10);
  if (*(float *)(this + 0x10) < fVar2 ==
      (NAN(*(float *)(this + 0x10)) || NAN(fVar2))) {
    if (fVar2 < *(float *)(this + 4)) {
      *(float *)(this + 4) = fVar2;
    }
  } else {
    *(float *)(this + 0x10) = fVar2;
  }
  if (*(float *)(this + 0x14) < fVar1 ==
      (NAN(*(float *)(this + 0x14)) || NAN(fVar1))) {
    if (fVar1 < *(float *)(this + 8)) {
      *(float *)(this + 8) = fVar1;
    }
  } else {
    *(float *)(this + 0x14) = fVar1;
  }
  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_1 + 4);
  fVar4 = *(float *)(param_1 + 8);
  fVar5 = *(float *)(param_1 + 0x24);
  fVar6 = *(float *)(param_1 + 0x10);
  fVar7 = *(float *)(param_1 + 0xc);
  fVar8 = *(float *)(param_1 + 0x14);
  fVar9 = *(float *)(param_1 + 0x28);
  fVar10 = fVar3 * *(float *)(param_1 + 0x20) +
           fVar12 * *(float *)(param_1 + 0x1c) +
           *(float *)(param_1 + 0x18) * fVar13 + *(float *)(param_1 + 0x2c);
  if (fVar10 < *(float *)(this + 0xc)) {
    *(float *)(this + 0xc) = fVar10;
  }
  if (*(float *)(this + 0x18) < fVar10 !=
      (NAN(*(float *)(this + 0x18)) || NAN(fVar10))) {
    *(float *)(this + 0x18) = fVar10;
  }
  fVar2 = (1.0 / fVar10) *
          (fVar12 * fVar2 + fVar13 * fVar1 + fVar3 * fVar4 + fVar5);
  fVar1 = (1.0 / fVar10) *
          (fVar8 * fVar3 + fVar13 * fVar7 + fVar6 * fVar12 + fVar9);
  if (*(float *)(this + 0x10) < fVar2 ==
      (NAN(*(float *)(this + 0x10)) || NAN(fVar2))) {
    if (fVar2 < *(float *)(this + 4)) {
      *(float *)(this + 4) = fVar2;
    }
  } else {
    *(float *)(this + 0x10) = fVar2;
  }
  if (*(float *)(this + 0x14) < fVar1 ==
      (NAN(*(float *)(this + 0x14)) || NAN(fVar1))) {
    if (*(float *)(this + 8) <= fVar1) {
      *(undefined4 *)this = 0;
      return;
    }
    *(float *)(this + 8) = fVar1;
    *(undefined4 *)this = 0;
    return;
  }
  *(float *)(this + 0x14) = fVar1;
  *(undefined4 *)this = 0;
  return;
}

/* public: void __thiscall GmFrustum::Set(class GmRectAligned,float,float) */

void __thiscall GmFrustum::Set(GmFrustum *this, undefined4 param_1,
                               undefined4 param_2, undefined4 param_3,
                               undefined4 param_4, undefined4 param_5,
                               undefined4 param_6)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = param_1;
  *(undefined4 *)(this + 8) = param_2;
  *(undefined4 *)(this + 0x10) = param_3;
  *(undefined4 *)(this + 0x14) = param_4;
  *(undefined4 *)(this + 0xc) = param_5;
  *(undefined4 *)(this + 0x18) = param_6;
  return;
}

/* public: void __thiscall GmFrustum::Set(class GmFrustum const &) */

void __thiscall GmFrustum::Set(GmFrustum *this, GmFrustum *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  return;
}

/* public: void __thiscall GmFrustum::Set(class GmBoxAligned const &) */

void __thiscall GmFrustum::Set(GmFrustum *this, GmBoxAligned *param_1)

{
  float fVar1;
  float fVar2;

  *(float *)(this + 0xc) = *(float *)(param_1 + 8) - *(float *)(param_1 + 0x14);
  *(float *)(this + 0x18) =
      *(float *)(param_1 + 0x14) + *(float *)(param_1 + 8);
  *(float *)(this + 4) =
      (*(float *)param_1 - *(float *)(param_1 + 0xc)) / *(float *)(this + 0xc);
  *(float *)(this + 0x10) =
      (*(float *)(param_1 + 0xc) + *(float *)param_1) / *(float *)(this + 0xc);
  *(float *)(this + 8) =
      (*(float *)(param_1 + 4) - *(float *)(param_1 + 0x10)) /
      *(float *)(this + 0xc);
  fVar1 = *(float *)(param_1 + 0x10);
  fVar2 = *(float *)(param_1 + 4);
  *(undefined4 *)this = 0;
  *(float *)(this + 0x14) = (fVar1 + fVar2) / *(float *)(this + 0xc);
  return;
}

/* public: void __thiscall GmFrustum::SetComplementX(class GmFrustum const &) */

void __thiscall GmFrustum::SetComplementX(GmFrustum *this, GmFrustum *param_1)

{
  float fVar1;

  *(undefined4 *)this = 0;
  if (*(int *)param_1 == 0) {
    fVar1 = *(float *)(param_1 + 0xc);
  } else {
    fVar1 = *(float *)(param_1 + 0xc) - *(float *)(param_1 + 0x18);
  }
  *(float *)(this + 0xc) = fVar1;
  if (*(int *)param_1 == 0) {
    fVar1 = *(float *)(param_1 + 0x18);
  } else {
    fVar1 = *(float *)(param_1 + 0x18) + *(float *)(param_1 + 0xc);
  }
  *(float *)(this + 0x18) = fVar1;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(float *)(this + 4) = *(float *)(param_1 + 0x10) / -1.0;
  *(float *)(this + 0x10) = -1.0 / *(float *)(param_1 + 4);
  return;
}

/* public: void __thiscall GmFrustum::SetComplementY(class GmFrustum const &) */

void __thiscall GmFrustum::SetComplementY(GmFrustum *this, GmFrustum *param_1)

{
  float fVar1;

  *(undefined4 *)this = 0;
  if (*(int *)param_1 == 0) {
    fVar1 = *(float *)(param_1 + 0xc);
  } else {
    fVar1 = *(float *)(param_1 + 0xc) - *(float *)(param_1 + 0x18);
  }
  *(float *)(this + 0xc) = fVar1;
  if (*(int *)param_1 == 0) {
    fVar1 = *(float *)(param_1 + 0x18);
  } else {
    fVar1 = *(float *)(param_1 + 0x18) + *(float *)(param_1 + 0xc);
  }
  *(float *)(this + 0x18) = fVar1;
  *(float *)(this + 8) = *(float *)(param_1 + 0x14) / -1.0;
  *(float *)(this + 0x14) = -1.0 / *(float *)(param_1 + 8);
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  return;
}

/* public: void __thiscall GmFrustum::SetFarZ(float) */

void __thiscall GmFrustum::SetFarZ(GmFrustum *this, float param_1)

{
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  if (*(int *)this != 0) {
    local_18 = *(float *)(this + 4) + *(float *)(this + 0x10);
    local_14 = *(float *)(this + 0x14) + *(float *)(this + 8);
    local_10 = param_1;
    local_c = *(float *)(this + 4) - *(float *)(this + 0x10);
    local_8 = *(float *)(this + 8) - *(float *)(this + 0x14);
    local_4 = *(float *)(this + 0xc) - *(float *)(this + 0x18);
    GmBoxAligned::SetMinMax((GmBoxAligned *)(this + 4), (GmVec3 *)&local_c,
                            (GmVec3 *)&local_18);
    return;
  }
  *(float *)(this + 0x18) = param_1;
  return;
}

/* public: void __thiscall GmFrustum::SetFovX(float,float,float,float) */

void __thiscall GmFrustum::SetFovX(GmFrustum *this, float param_1,
                                   float param_2, float param_3, float param_4)

{
  float fVar1;
  undefined4 in_EDX;
  float10 fVar2;

  fVar2 = (float10)__CItan((float10 *)this, in_EDX);
  fVar1 = (float)fVar2;
  *(undefined4 *)this = 0;
  *(float *)(this + 0xc) = param_3;
  *(float *)(this + 0x18) = param_4;
  *(float *)(this + 0x10) = fVar1;
  *(float *)(this + 4) = -fVar1;
  *(float *)(this + 0x14) = fVar1 / param_2;
  *(float *)(this + 8) = -(fVar1 / param_2);
  return;
}

/* public: void __thiscall GmFrustum::SetFovY(float,float,float,float) */

void __thiscall GmFrustum::SetFovY(GmFrustum *this, float param_1,
                                   float param_2, float param_3, float param_4)

{
  Set(this, param_1, param_2, param_3, param_4);
  return;
}

/* public: void __thiscall GmFrustum::SetNearZ(float) */

void __thiscall GmFrustum::SetNearZ(GmFrustum *this, float param_1)

{
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  if (*(int *)this != 0) {
    local_c = *(float *)(this + 4) - *(float *)(this + 0x10);
    local_8 = *(float *)(this + 8) - *(float *)(this + 0x14);
    local_4 = param_1;
    local_18 = *(float *)(this + 0x10) + *(float *)(this + 4);
    local_14 = *(float *)(this + 0x14) + *(float *)(this + 8);
    local_10 = *(float *)(this + 0x18) + *(float *)(this + 0xc);
    GmBoxAligned::SetMinMax((GmBoxAligned *)(this + 4), (GmVec3 *)&local_c,
                            (GmVec3 *)&local_18);
    return;
  }
  *(float *)(this + 0xc) = param_1;
  return;
}

/* public: void __thiscall GmFrustum::SetOrtho(class GmBoxAligned const &) */

void __thiscall GmFrustum::SetOrtho(GmFrustum *this, GmBoxAligned *param_1)

{
  *(undefined4 *)(this + 4) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)this = 1;
  return;
}

/* public: void __thiscall GmFrustum::SetRangeZ(float,float) */

void __thiscall GmFrustum::SetRangeZ(GmFrustum *this, float param_1,
                                     float param_2)

{
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  if (*(int *)this != 0) {
    local_c = *(float *)(this + 4) - *(float *)(this + 0x10);
    local_8 = *(float *)(this + 8) - *(float *)(this + 0x14);
    local_18 = *(float *)(this + 4) + *(float *)(this + 0x10);
    local_14 = *(float *)(this + 0x14) + *(float *)(this + 8);
    local_4 = param_1;
    local_10 = param_2;
    GmBoxAligned::SetMinMax((GmBoxAligned *)(this + 4), (GmVec3 *)&local_c,
                            (GmVec3 *)&local_18);
    return;
  }
  *(float *)(this + 0xc) = param_1;
  *(float *)(this + 0x18) = param_2;
  return;
}

/* public: unsigned long __thiscall GmFrustum::TestInter(class GmVec3)const  */

int __thiscall GmFrustum::TestInter(GmFrustum *this, float param_1,
                                    float param_2, float param_3)

{
  int iVar1;

  if (*(int *)this != 0) {
    iVar1 =
        GmBoxAligned::TestInter((GmBoxAligned *)(this + 4), (GmVec3 *)&param_1);
    return iVar1;
  }
  if ((((*(float *)(this + 0xc) <= param_3) &&
        (*(float *)(this + 0x18) < param_3 ==
         (NAN(*(float *)(this + 0x18)) || NAN(param_3)))) &&
       (*(float *)(this + 4) * param_3 < param_1 !=
        (*(float *)(this + 4) * param_3 == param_1))) &&
      (((param_1 <= *(float *)(this + 0x10) * param_3 &&
         (*(float *)(this + 8) * param_3 < param_2 !=
          (*(float *)(this + 8) * param_3 == param_2))) &&
        (param_2 < *(float *)(this + 0x14) * param_3 !=
         (param_2 == *(float *)(this + 0x14) * param_3))))) {
    return 1;
  }
  return 0;
}

/* public: unsigned long __thiscall GmFrustum::TestInter(class GmBoxAligned
   const &,unsigned long)const  */

ulong __thiscall GmFrustum::TestInter(GmFrustum *this, GmBoxAligned *param_1,
                                      ulong param_2)

{
  ulong uVar1;
  float local_20[4];
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  if (*(int *)this != 0) {
    uVar1 = GmBoxAligned::TestInter((GmBoxAligned *)(this + 4), param_1);
    return uVar1;
  }
  if ((*(float *)(this + 0xc) <=
       *(float *)(param_1 + 0x14) + *(float *)(param_1 + 8)) &&
      ((local_20[0] = *(float *)(param_1 + 8) - *(float *)(param_1 + 0x14),
        param_2 != 0 ||
            (*(float *)(this + 0x18) < local_20[0] ==
             (NAN(*(float *)(this + 0x18)) || NAN(local_20[0])))))) {
    local_20[1] = *(float *)(param_1 + 0x14) + *(float *)(param_1 + 8);
    local_10 = local_20[-(*(int *)(this + 4) >> 0x1f)] * *(float *)(this + 4);
    local_c = local_20[-(*(int *)(this + 8) >> 0x1f)] * *(float *)(this + 8);
    local_8 = local_20[-((int)~*(uint *)(this + 0x10) >> 0x1f)] *
              *(float *)(this + 0x10);
    local_4 = local_20[-((int)~*(uint *)(this + 0x14) >> 0x1f)] *
              *(float *)(this + 0x14);
    local_20[0] = *(float *)param_1 - *(float *)(param_1 + 0xc);
    local_20[1] = *(float *)(param_1 + 4) - *(float *)(param_1 + 0x10);
    local_20[2] = *(float *)param_1 + *(float *)(param_1 + 0xc);
    local_20[3] = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 4);
    uVar1 = GmRectAligned::TestInter((GmRectAligned *)&local_10,
                                     (GmRectAligned *)local_20);
    return uVar1;
  }
  return 0;
}
