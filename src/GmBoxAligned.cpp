
/* public: void __thiscall GmBoxAligned::ArchiveABox(class CClassicArchive &) */

void __thiscall GmBoxAligned::ArchiveABox(GmBoxAligned *this,
                                          CClassicArchive *param_1)

{
  CClassicArchive::DoReal(param_1, (float *)this, 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 4), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 8), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0xc), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x10), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x14), 1);
  return;
}

/* public: void __thiscall GmBoxAligned::ArchiveABoxOld1(class CClassicArchive
 * &) */

void __thiscall GmBoxAligned::ArchiveABoxOld1(GmBoxAligned *this,
                                              CClassicArchive *param_1)

{
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_c = *(float *)this - *(float *)(this + 0xc);
  local_8 = *(float *)(this + 4) - *(float *)(this + 0x10);
  local_4 = *(float *)(this + 8) - *(float *)(this + 0x14);
  local_18 = *(float *)(this + 0xc) + *(float *)this;
  local_14 = *(float *)(this + 0x10) + *(float *)(this + 4);
  local_10 = *(float *)(this + 0x14) + *(float *)(this + 8);
  CClassicArchive::DoReal(param_1, &local_c, 1);
  CClassicArchive::DoReal(param_1, &local_8, 1);
  CClassicArchive::DoReal(param_1, &local_4, 1);
  CClassicArchive::DoReal(param_1, &local_18, 1);
  CClassicArchive::DoReal(param_1, &local_14, 1);
  CClassicArchive::DoReal(param_1, &local_10, 1);
  SetMinMax(this, (GmVec3 *)&local_c, (GmVec3 *)&local_18);
  return;
}

/* public: void __thiscall GmBoxAligned::GetDiag(class GmVec3 &)const  */

void __thiscall GmBoxAligned::GetDiag(GmBoxAligned *this, GmVec3 *param_1)

{
  *(float *)param_1 = *(float *)(this + 0xc) * 2.0;
  *(float *)(param_1 + 4) = *(float *)(this + 0x10) * 2.0;
  *(float *)(param_1 + 8) = *(float *)(this + 0x14) * 2.0;
  return;
}

/* public: class GmVec3 __thiscall GmBoxAligned::GetMax(void)const  */

void __thiscall GmBoxAligned::GetMax(GmBoxAligned *this, float *param_1)

{
  *param_1 = *(float *)(this + 0xc) + *(float *)this;
  param_1[1] = *(float *)(this + 0x10) + *(float *)(this + 4);
  param_1[2] = *(float *)(this + 0x14) + *(float *)(this + 8);
  return;
}

/* public: class GmVec3 __thiscall GmBoxAligned::GetMin(void)const  */

void __thiscall GmBoxAligned::GetMin(GmBoxAligned *this, float *param_1)

{
  *param_1 = *(float *)this - *(float *)(this + 0xc);
  param_1[1] = *(float *)(this + 4) - *(float *)(this + 0x10);
  param_1[2] = *(float *)(this + 8) - *(float *)(this + 0x14);
  return;
}

/* public: void __thiscall GmBoxAligned::GetMinMax(class GmVec3 &,class GmVec3
 * &)const  */

void __thiscall GmBoxAligned::GetMinMax(GmBoxAligned *this, GmVec3 *param_1,
                                        GmVec3 *param_2)

{
  *(float *)param_1 = *(float *)this - *(float *)(this + 0xc);
  *(float *)(param_1 + 4) = *(float *)(this + 4) - *(float *)(this + 0x10);
  *(float *)(param_1 + 8) = *(float *)(this + 8) - *(float *)(this + 0x14);
  *(float *)param_2 = *(float *)(this + 0xc) + *(float *)this;
  *(float *)(param_2 + 4) = *(float *)(this + 0x10) + *(float *)(this + 4);
  *(float *)(param_2 + 8) = *(float *)(this + 0x14) + *(float *)(this + 8);
  return;
}

/* public: int __thiscall GmBoxAligned::Inter(class GmBoxAligned const &) */

int __thiscall GmBoxAligned::Inter(GmBoxAligned *this, GmBoxAligned *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_18 = *(float *)this - *(float *)(this + 0xc);
  local_14 = *(float *)(this + 4) - *(float *)(this + 0x10);
  local_10 = *(float *)(this + 8) - *(float *)(this + 0x14);
  local_24 = *(float *)(this + 0xc) + *(float *)this;
  local_20 = *(float *)(this + 0x10) + *(float *)(this + 4);
  local_1c = *(float *)(this + 0x14) + *(float *)(this + 8);
  fVar1 = *(float *)param_1 - *(float *)(param_1 + 0xc);
  fVar2 = *(float *)(param_1 + 4) - *(float *)(param_1 + 0x10);
  fVar3 = *(float *)(param_1 + 8) - *(float *)(param_1 + 0x14);
  if (local_18 < fVar1 != (NAN(local_18) || NAN(fVar1))) {
    local_18 = fVar1;
  }
  if (local_14 < fVar2 != (NAN(local_14) || NAN(fVar2))) {
    local_14 = fVar2;
  }
  if (local_10 < fVar3 != (NAN(local_10) || NAN(fVar3))) {
    local_10 = fVar3;
  }
  local_c = *(float *)(param_1 + 0xc) + *(float *)param_1;
  local_8 = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 4);
  local_4 = *(float *)(param_1 + 0x14) + *(float *)(param_1 + 8);
  if (local_c < local_24) {
    local_24 = local_c;
  }
  if (local_8 < local_20) {
    local_20 = local_8;
  }
  if (local_4 < local_1c) {
    local_1c = local_4;
  }
  if (((local_18 < local_24 == (local_18 == local_24)) ||
       (local_14 < local_20 == (local_14 == local_20))) ||
      (local_10 < local_1c == (local_10 == local_1c))) {
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 0xc) = 0xbf800000;
    *(undefined4 *)(this + 0x10) = 0xbf800000;
    *(undefined4 *)(this + 0x14) = 0xbf800000;
  } else {
    SetMinMax(this, (GmVec3 *)&local_18, (GmVec3 *)&local_24);
  }
  if (0.0 <= *(float *)(this + 0xc)) {
    return 1;
  }
  return 0;
}

/* public: int __thiscall GmBoxAligned::IsIncluded(class GmFrustum const &)const
 */

int __thiscall GmBoxAligned::IsIncluded(GmBoxAligned *this, GmFrustum *param_1)

{
  int iVar1;

  iVar1 = GmFrustum::TestInter(param_1, *(float *)this + *(float *)(this + 0xc),
                               *(float *)(this + 4) + *(float *)(this + 0x10),
                               *(float *)(this + 8) + *(float *)(this + 0x14));
  if (iVar1 != 0) {
    iVar1 = GmFrustum::TestInter(
        param_1, *(float *)this + *(float *)(this + 0xc) * -1.0,
        *(float *)(this + 4) + *(float *)(this + 0x10),
        *(float *)(this + 8) + *(float *)(this + 0x14));
    if (iVar1 != 0) {
      iVar1 = GmFrustum::TestInter(
          param_1, *(float *)this + *(float *)(this + 0xc),
          *(float *)(this + 4) + *(float *)(this + 0x10) * -1.0,
          *(float *)(this + 8) + *(float *)(this + 0x14));
      if (iVar1 != 0) {
        iVar1 = GmFrustum::TestInter(
            param_1, *(float *)this + *(float *)(this + 0xc) * -1.0,
            *(float *)(this + 4) + *(float *)(this + 0x10) * -1.0,
            *(float *)(this + 8) + *(float *)(this + 0x14));
        if (iVar1 != 0) {
          iVar1 = GmFrustum::TestInter(
              param_1, *(float *)this + *(float *)(this + 0xc),
              *(float *)(this + 4) + *(float *)(this + 0x10),
              *(float *)(this + 8) + *(float *)(this + 0x14) * -1.0);
          if (iVar1 != 0) {
            iVar1 = GmFrustum::TestInter(
                param_1, *(float *)this + *(float *)(this + 0xc) * -1.0,
                *(float *)(this + 4) + *(float *)(this + 0x10),
                *(float *)(this + 8) + *(float *)(this + 0x14) * -1.0);
            if (iVar1 != 0) {
              iVar1 = GmFrustum::TestInter(
                  param_1, *(float *)this + *(float *)(this + 0xc),
                  *(float *)(this + 4) + *(float *)(this + 0x10) * -1.0,
                  *(float *)(this + 8) + *(float *)(this + 0x14) * -1.0);
              if (iVar1 != 0) {
                iVar1 = GmFrustum::TestInter(
                    param_1, *(float *)this + *(float *)(this + 0xc) * -1.0,
                    *(float *)(this + 4) + *(float *)(this + 0x10) * -1.0,
                    *(float *)(this + 8) + *(float *)(this + 0x14) * -1.0);
                return (uint)(iVar1 != 0);
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

/* public: int __thiscall GmBoxAligned::IsIncluded(class GmBoxAligned const
 * &)const  */

int __thiscall GmBoxAligned::IsIncluded(GmBoxAligned *this,
                                        GmBoxAligned *param_1)

{
  float fVar1;
  int iVar2;
  float local_c;
  float local_8;
  float local_4;

  local_c = *(float *)this - *(float *)(this + 0xc);
  fVar1 = *(float *)(this + 4) - *(float *)(this + 0x10);
  local_4 = *(float *)(this + 8) - *(float *)(this + 0x14);
  if ((((*(float *)(this + 0x14) + *(float *)(this + 8) <=
         *(float *)(param_1 + 0x14) + *(float *)(param_1 + 8)) &&
        (*(float *)(param_1 + 8) - *(float *)(param_1 + 0x14) < local_4 !=
         (*(float *)(param_1 + 8) - *(float *)(param_1 + 0x14) == local_4))) &&
       (*(float *)(this + 0xc) + *(float *)this <=
        *(float *)(param_1 + 0xc) + *(float *)param_1)) &&
      ((*(float *)param_1 - *(float *)(param_1 + 0xc) < local_c !=
            (*(float *)param_1 - *(float *)(param_1 + 0xc) == local_c) &&
        (*(float *)(this + 0x10) + *(float *)(this + 4) <=
         *(float *)(param_1 + 0x10) + *(float *)(param_1 + 4))))) {
    local_8 = fVar1;
    iVar2 = GetMin(param_1, &local_c);
    if (*(float *)(iVar2 + 4) < fVar1 != (*(float *)(iVar2 + 4) == fVar1)) {
      return 1;
    }
  }
  return 0;
}

/* public: int __thiscall GmBoxAligned::IsNull(void)const  */

int __thiscall GmBoxAligned::IsNull(GmBoxAligned *this)

{
  if (*(float *)(this + 0xc) < 0.0) {
    return 1;
  }
  return 0;
}

/* public: void __thiscall GmBoxAligned::Mult(class GmIso4 const &) */

void __thiscall GmBoxAligned::Mult(GmBoxAligned *this, GmIso4 *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  local_18 = *(undefined4 *)this;
  local_14 = *(undefined4 *)(this + 4);
  local_10 = *(undefined4 *)(this + 8);
  local_c = *(undefined4 *)(this + 0xc);
  local_8 = *(undefined4 *)(this + 0x10);
  local_4 = *(undefined4 *)(this + 0x14);
  SetMult(this, (GmBoxAligned *)&local_18, param_1);
  return;
}

/* public: void __thiscall GmBoxAligned::Set(class GmBoxAligned const &) */

void __thiscall GmBoxAligned::Set(GmBoxAligned *this, GmBoxAligned *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  return;
}

/* public: void __thiscall GmBoxAligned::Set(class GmBoxOriented const &) */

void __thiscall GmBoxAligned::Set(GmBoxAligned *this, GmBoxOriented *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_c = *(undefined4 *)(param_1 + 0x30);
  local_8 = *(undefined4 *)(param_1 + 0x34);
  local_4 = *(undefined4 *)(param_1 + 0x38);
  SetMult(this, (GmBoxAligned *)&local_18, (GmIso4 *)param_1);
  return;
}

/* public: void __thiscall GmBoxAligned::SetCenter0HalfDiag(class GmVec3 const
 * &) */

void __thiscall GmBoxAligned::SetCenter0HalfDiag(GmBoxAligned *this,
                                                 GmVec3 *param_1)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 0xc) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 8);
  return;
}

/* public: void __thiscall GmBoxAligned::SetCenterHalfDiag(class GmVec3 const
   &,class GmVec3 const
   &) */

void __thiscall GmBoxAligned::SetCenterHalfDiag(GmBoxAligned *this,
                                                GmVec3 *param_1,
                                                GmVec3 *param_2)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)param_2;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_2 + 8);
  return;
}

/* public: void __thiscall GmBoxAligned::SetFromConeAndRadius(class GmCone3
 * const &,float) */

void __thiscall GmBoxAligned::SetFromConeAndRadius(GmBoxAligned *this,
                                                   GmCone3 *param_1,
                                                   float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  uint uVar8;
  float10 fVar9;
  float10 fVar10;
  float local_18[6];

  fVar1 = *(float *)(param_1 + 0x18);
  fVar9 = (float10)__CIsqrt();
  pfVar7 = (float *)(param_1 + 0xc);
  uVar8 = 0;
  do {
    fVar2 = *pfVar7;
    fVar10 = (float10)__CIsqrt();
    fVar3 = param_2;
    if (fVar1 < fVar2 == (NAN(fVar1) || NAN(fVar2))) {
      fVar3 = fVar2 * fVar1 + (float)fVar10 * (float)fVar9;
      if (fVar3 < 0.0 != (fVar3 == 0.0)) {
        fVar3 = 0.0;
      }
      fVar3 = fVar3 * param_2;
    }
    *(float *)((int)local_18 + uVar8 + 0xc) = fVar3;
    fVar3 = -param_2;
    if (-fVar2 <= fVar1) {
      fVar2 = (float)fVar10 * (float)fVar9 - fVar2 * fVar1;
      if (fVar2 < 0.0 != (fVar2 == 0.0)) {
        fVar2 = 0.0;
      }
      fVar3 = -param_2 * fVar2;
    }
    *(float *)((int)local_18 + uVar8) = fVar3;
    uVar8 = uVar8 + 4;
    pfVar7 = pfVar7 + 1;
  } while (uVar8 < 0xc);
  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_1 + 4);
  fVar3 = *(float *)(param_1 + 8);
  fVar4 = *(float *)param_1;
  fVar5 = *(float *)(param_1 + 4);
  fVar6 = *(float *)(param_1 + 8);
  *(float *)this = (fVar1 + local_18[0] + fVar4 + local_18[3]) * 0.5;
  *(float *)(this + 4) = (fVar2 + local_18[1] + fVar5 + local_18[4]) * 0.5;
  *(float *)(this + 8) = (fVar6 + local_18[5] + fVar3 + local_18[2]) * 0.5;
  *(float *)(this + 0xc) = (fVar4 + local_18[3]) - (fVar1 + local_18[0]);
  *(float *)(this + 0x10) = (fVar5 + local_18[4]) - (fVar2 + local_18[1]);
  *(float *)(this + 0x14) = (fVar6 + local_18[5]) - (fVar3 + local_18[2]);
  *(float *)(this + 0xc) = *(float *)(this + 0xc) * 0.5;
  *(float *)(this + 0x10) = *(float *)(this + 0x10) * 0.5;
  *(float *)(this + 0x14) = *(float *)(this + 0x14) * 0.5;
  return;
}

/* public: void __thiscall GmBoxAligned::SetMinMax(class GmVec3 const &,class
 * GmVec3 const &) */

void __thiscall GmBoxAligned::SetMinMax(GmBoxAligned *this, GmVec3 *param_1,
                                        GmVec3 *param_2)

{
  *(float *)this = *(float *)param_1 + *(float *)param_2;
  *(float *)(this + 4) = *(float *)(param_1 + 4) + *(float *)(param_2 + 4);
  *(float *)(this + 8) = *(float *)(param_1 + 8) + *(float *)(param_2 + 8);
  *(float *)this = *(float *)this * 0.5;
  *(float *)(this + 4) = *(float *)(this + 4) * 0.5;
  *(float *)(this + 8) = *(float *)(this + 8) * 0.5;
  *(float *)(this + 0xc) = *(float *)param_2 - *(float *)param_1;
  *(float *)(this + 0x10) = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  *(float *)(this + 0x14) = *(float *)(param_2 + 8) - *(float *)(param_1 + 8);
  *(float *)(this + 0xc) = *(float *)(this + 0xc) * 0.5;
  *(float *)(this + 0x10) = *(float *)(this + 0x10) * 0.5;
  *(float *)(this + 0x14) = *(float *)(this + 0x14) * 0.5;
  return;
}

/* public: void __thiscall GmBoxAligned::SetMult(class GmBoxAligned const
 * &,class GmIso4 const &) */

void __thiscall GmBoxAligned::SetMult(GmBoxAligned *this, GmBoxAligned *param_1,
                                      GmIso4 *param_2)

{
  *(float *)this = *(float *)(param_2 + 8) * *(float *)(param_1 + 8) +
                   *(float *)(param_2 + 4) * *(float *)(param_1 + 4) +
                   *(float *)param_1 * *(float *)param_2 +
                   *(float *)(param_2 + 0x24);
  *(float *)(this + 4) = *(float *)(param_2 + 0x14) * *(float *)(param_1 + 8) +
                         *(float *)param_1 * *(float *)(param_2 + 0xc) +
                         *(float *)(param_2 + 0x10) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 0x28);
  *(float *)(this + 8) = *(float *)(param_2 + 0x20) * *(float *)(param_1 + 8) +
                         *(float *)(param_2 + 0x18) * *(float *)param_1 +
                         *(float *)(param_2 + 0x1c) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 0x2c);
  *(float *)(this + 0xc) =
      ABS(*(float *)(param_2 + 8)) * *(float *)(param_1 + 0x14) +
      ABS(*(float *)param_2) * *(float *)(param_1 + 0xc) +
      ABS(*(float *)(param_2 + 4)) * *(float *)(param_1 + 0x10);
  *(float *)(this + 0x10) =
      ABS(*(float *)(param_2 + 0x14)) * *(float *)(param_1 + 0x14) +
      ABS(*(float *)(param_2 + 0xc)) * *(float *)(param_1 + 0xc) +
      ABS(*(float *)(param_2 + 0x10)) * *(float *)(param_1 + 0x10);
  *(float *)(this + 0x14) =
      ABS(*(float *)(param_2 + 0x20)) * *(float *)(param_1 + 0x14) +
      ABS(*(float *)(param_2 + 0x18)) * *(float *)(param_1 + 0xc) +
      ABS(*(float *)(param_2 + 0x1c)) * *(float *)(param_1 + 0x10);
  return;
}

/* public: int __thiscall GmBoxAligned::TestInter(class GmBoxAligned const
 * &)const  */

int __thiscall GmBoxAligned::TestInter(GmBoxAligned *this,
                                       GmBoxAligned *param_1)

{
  if (ABS(*(float *)(param_1 + 8) - *(float *)(this + 8)) <=
      *(float *)(param_1 + 0x14) + *(float *)(this + 0x14)) {
    if (ABS(*(float *)(param_1 + 4) - *(float *)(this + 4)) <=
        *(float *)(param_1 + 0x10) + *(float *)(this + 0x10)) {
      if (ABS(*(float *)param_1 - *(float *)this) <=
          *(float *)(param_1 + 0xc) + *(float *)(this + 0xc)) {
        return 1;
      }
    }
  }
  return 0;
}

/* public: int __thiscall GmBoxAligned::TestInter(class GmVec3 const &)const  */

int __thiscall GmBoxAligned::TestInter(GmBoxAligned *this, GmVec3 *param_1)

{
  if (ABS(*(float *)param_1 - *(float *)this) <= *(float *)(this + 0xc)) {
    if (ABS(*(float *)(param_1 + 4) - *(float *)(this + 4)) <=
        *(float *)(this + 0x10)) {
      if (ABS(*(float *)(param_1 + 8) - *(float *)(this + 8)) <=
          *(float *)(this + 0x14)) {
        return 1;
      }
    }
  }
  return 0;
}

/* public: int __thiscall GmBoxAligned::TestInterSegment(class GmVec3 const
   &,class GmVec3 const
   &)const  */

int __thiscall GmBoxAligned::TestInterSegment(GmBoxAligned *this,
                                              GmVec3 *param_1, GmVec3 *param_2)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_18 = (*(float *)param_1 + *(float *)param_2) * 0.5;
  local_14 = (*(float *)(param_1 + 4) + *(float *)(param_2 + 4)) * 0.5;
  local_10 = (*(float *)(param_1 + 8) + *(float *)(param_2 + 8)) * 0.5;
  local_c = *(float *)param_2 - *(float *)param_1;
  local_8 = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  local_4 = *(float *)(param_2 + 8) - *(float *)(param_1 + 8);
  iVar1 = TestInterSegment_MiddleVectAB(this, (GmVec3 *)&local_18,
                                        (GmVec3 *)&local_c);
  return iVar1;
}

/* public: int __thiscall GmBoxAligned::TestInterSegment_MiddleVectAB(class
   GmVec3 const &,class GmVec3 const &)const  */

int __thiscall GmBoxAligned::TestInterSegment_MiddleVectAB(GmBoxAligned *this,
                                                           GmVec3 *param_1,
                                                           GmVec3 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;

  fVar1 = *(float *)this - *(float *)param_1;
  fVar2 = *(float *)(this + 4) - *(float *)(param_1 + 4);
  fVar3 = *(float *)(this + 8) - *(float *)(param_1 + 8);
  fVar4 = ABS(*(float *)param_2);
  fVar5 = *(float *)(this + 0xc) + fVar4 * 0.5;
  if ((((fVar5 < ABS(fVar1) == (NAN(fVar5) || NAN(ABS(fVar1)))) &&
        (fVar6 = ABS(*(float *)(param_2 + 4)),
         fVar5 = fVar6 * 0.5 + *(float *)(this + 0x10),
         fVar5 < ABS(fVar2) == (NAN(fVar5) || NAN(ABS(fVar2))))) &&
       (fVar7 = ABS(*(float *)(param_2 + 8)),
        fVar5 = *(float *)(this + 0x14) + fVar7 * 0.5,
        fVar5 < ABS(fVar3) == (NAN(fVar5) || NAN(ABS(fVar3))))) &&
      (((fVar8 = ABS(*(float *)(param_2 + 8) * fVar2 -
                     *(float *)(param_2 + 4) * fVar3),
         fVar5 =
             *(float *)(this + 0x10) * fVar7 + fVar6 * *(float *)(this + 0x14),
         fVar5 < fVar8 == (NAN(fVar5) || NAN(fVar8)) &&
             (fVar5 = ABS(fVar3 * *(float *)param_2 -
                          fVar1 * *(float *)(param_2 + 8)),
              fVar3 = fVar4 * *(float *)(this + 0x14) +
                      *(float *)(this + 0xc) * fVar7,
              fVar3 < fVar5 == (NAN(fVar3) || NAN(fVar5)))) &&
        (fVar2 =
             ABS(fVar1 * *(float *)(param_2 + 4) - *(float *)param_2 * fVar2),
         fVar1 =
             *(float *)(this + 0xc) * fVar6 + *(float *)(this + 0x10) * fVar4,
         fVar1 < fVar2 == (NAN(fVar1) || NAN(fVar2)))))) {
    return 1;
  }
  return 0;
}

/* public: void __thiscall GmBoxAligned::Union(class GmBoxAligned const &) */

void __thiscall GmBoxAligned::Union(GmBoxAligned *this, GmBoxAligned *param_1)

{
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  if (*(float *)(this + 0xc) < 0.0) {
    *(undefined4 *)this = *(undefined4 *)param_1;
    *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
    return;
  }
  if (0.0 <= *(float *)(param_1 + 0xc)) {
    local_18 = *(float *)this - *(float *)(this + 0xc);
    local_14 = *(float *)(this + 4) - *(float *)(this + 0x10);
    local_10 = *(float *)(this + 8) - *(float *)(this + 0x14);
    local_24 = *(float *)this + *(float *)(this + 0xc);
    local_20 = *(float *)(this + 0x10) + *(float *)(this + 4);
    local_1c = *(float *)(this + 0x14) + *(float *)(this + 8);
    if (*(float *)param_1 - *(float *)(param_1 + 0xc) < local_18) {
      local_18 = *(float *)param_1 - *(float *)(param_1 + 0xc);
    }
    if (*(float *)(param_1 + 4) - *(float *)(param_1 + 0x10) < local_14) {
      local_14 = *(float *)(param_1 + 4) - *(float *)(param_1 + 0x10);
    }
    if (*(float *)(param_1 + 8) - *(float *)(param_1 + 0x14) < local_10) {
      local_10 = *(float *)(param_1 + 8) - *(float *)(param_1 + 0x14);
    }
    local_c = *(float *)(param_1 + 0xc) + *(float *)param_1;
    local_8 = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 4);
    local_4 = *(float *)(param_1 + 0x14) + *(float *)(param_1 + 8);
    if (local_24 < local_c != (NAN(local_24) || NAN(local_c))) {
      local_24 = local_c;
    }
    if (local_20 < local_8 != (NAN(local_20) || NAN(local_8))) {
      local_20 = local_8;
    }
    if (local_1c < local_4 != (NAN(local_1c) || NAN(local_4))) {
      local_1c = local_4;
      SetMinMax(this, (GmVec3 *)&local_18, (GmVec3 *)&local_24);
      return;
    }
    SetMinMax(this, (GmVec3 *)&local_18, (GmVec3 *)&local_24);
  }
  return;
}
