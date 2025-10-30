
/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* unsigned long __cdecl ComputeTriangleTangentUV_Rotated(struct
   GmVec3::STri_PosTexTgt &,unsigned long) */

ulong __cdecl ComputeTriangleTangentUV_Rotated(STri_PosTexTgt *param_1,
                                               ulong param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  bool bVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  uint uVar16;

  pfVar5 = *(float **)
            (param_1 +
            (int)(&`unsigned_long___cdecl_ComputeTriangleTangentUV_Rotated(struct_GmVec3::STri_PosTe xTgt&,unsigned_long)'
                   ::`2'::RotIndexs)[param_2 * 3] * 4);
  pfVar6 = *(float **)
            (param_1 +
            (int)(&`unsigned_long___cdecl_ComputeTriangleTangentUV_Rotated(struct_GmVec3::STri_PosTe xTgt&,unsigned_long)'
                   ::`2'::RotIndexs)[param_2 * 3] * 4 + 0xc);
  pfVar7 = *(float **)(param_1 + *(int *)(&DAT_00d1a8cc + param_2 * 0xc) * 4);
  fVar1 = *pfVar7;
  fVar2 = *pfVar5;
  pfVar8 = *(float **)(param_1 + *(int *)(&DAT_00d1a8d0 + param_2 * 0xc) * 4);
  fVar10 = **(float **)(param_1 + *(int *)(&DAT_00d1a8cc + param_2 * 0xc) * 4 + 0xc) - *pfVar6;
  fVar11 = (*(float **)(param_1 + *(int *)(&DAT_00d1a8cc + param_2 * 0xc) * 4 + 0xc))[1] - pfVar6[1]
  ;
  fVar3 = *pfVar8;
  fVar4 = *pfVar5;
  fVar12 = **(float **)(param_1 + *(int *)(&DAT_00d1a8d0 + param_2 * 0xc) * 4 + 0xc) - *pfVar6;
  fVar13 = (*(float **)(param_1 + *(int *)(&DAT_00d1a8d0 + param_2 * 0xc) * 4 + 0xc))[1] - pfVar6[1]
  ;
  fVar14 = fVar10 * fVar13 - fVar11 * fVar12;
  bVar9 = _DAT_00d1a8f0 < ABS(fVar14) == (NAN(_DAT_00d1a8f0) || NAN(ABS(fVar14)));
  if (bVar9) {
    fVar1 = 0.0;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else {
    *(float *)(param_1 + 0x18) =
        -(fVar11 * (fVar3 - fVar4) - fVar13 * (fVar1 - fVar2)) / fVar14;
    fVar1 = -(fVar12 * (fVar1 - fVar2) - fVar10 * (fVar3 - fVar4)) / fVar14;
  }
  uVar16 = (uint)!bVar9;
  *(float *)(param_1 + 0x24) = fVar1;
  fVar15 = _DAT_00d1a8f0;
  fVar1 = pfVar7[1];
  fVar2 = pfVar5[1];
  fVar3 = pfVar8[1];
  fVar4 = pfVar5[1];
  if (_DAT_00d1a8f0 < ABS(fVar14) == (NAN(_DAT_00d1a8f0) || NAN(ABS(fVar14)))) {
    fVar1 = 0.0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  else {
    uVar16 = uVar16 | 2;
    *(float *)(param_1 + 0x1c) =
        -(fVar11 * (fVar3 - fVar4) - fVar13 * (fVar1 - fVar2)) / fVar14;
    fVar1 = -(fVar12 * (fVar1 - fVar2) - fVar10 * (fVar3 - fVar4)) / fVar14;
  }
  *(float *)(param_1 + 0x28) = fVar1;
  fVar1 = pfVar7[2];
  fVar2 = pfVar5[2];
  fVar3 = pfVar8[2];
  fVar4 = pfVar5[2];
  if (fVar15 < ABS(fVar14)) {
    *(float *)(param_1 + 0x20) =
        -((fVar3 - fVar4) * fVar11 - (fVar1 - fVar2) * fVar13) / fVar14;
    *(float *)(param_1 + 0x2c) =
        -(fVar12 * (fVar1 - fVar2) - fVar10 * (fVar3 - fVar4)) / fVar14;
    return uVar16 | 4;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return uVar16;
}

/* public: static int __cdecl GmVec3::ComputeTriangleTangentUV(struct
 * GmVec3::STri_PosTexTgt &) */

int __cdecl GmVec3::ComputeTriangleTangentUV(STri_PosTexTgt *param_1)

{
  ulong uVar1;
  ulong uVar2;

  uVar2 = 0;
  do {
    uVar1 = ComputeTriangleTangentUV_Rotated(param_1, uVar2);
    if (uVar1 != 0) {
      return uVar1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 3);
  return 0;
}

/* public: static int __cdecl GmVec3::DoesRayIntersectTriangle(class GmVec3
   const &,class GmVec3 const &,class GmVec3 const &,class GmVec3 const &,class
   GmVec3 const &,float &,float &,float &)
    */

int __cdecl GmVec3::DoesRayIntersectTriangle(GmVec3 *param_1, GmVec3 *param_2,
                                             GmVec3 *param_3, GmVec3 *param_4,
                                             GmVec3 *param_5, float *param_6,
                                             float *param_7, float *param_8)

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

  fVar3 = *(float *)param_4 - *(float *)param_3;
  fVar4 = *(float *)(param_4 + 4) - *(float *)(param_3 + 4);
  fVar5 = *(float *)(param_4 + 8) - *(float *)(param_3 + 8);
  fVar6 = *(float *)param_5 - *(float *)param_3;
  fVar7 = *(float *)(param_5 + 4) - *(float *)(param_3 + 4);
  fVar8 = *(float *)(param_5 + 8) - *(float *)(param_3 + 8);
  fVar2 = fVar8 * *(float *)(param_2 + 4) - fVar7 * *(float *)(param_2 + 8);
  fVar10 = fVar6 * *(float *)(param_2 + 8) - *(float *)param_2 * fVar8;
  fVar9 = *(float *)param_2 * fVar7 - fVar6 * *(float *)(param_2 + 4);
  fVar11 = fVar4 * fVar10 + fVar3 * fVar2 + fVar5 * fVar9;
  fVar1 = fVar5 * fVar5 + fVar3 * fVar3 + fVar4 * fVar4;
  if (fVar1 * 1e-05 * fVar1 <= fVar11 * fVar11) {
    fVar1 = (float)((uint)fVar11 & 0x7fffffff);
    fVar12 = *(float *)param_1 - *(float *)param_3;
    fVar13 = *(float *)(param_1 + 4) - *(float *)(param_3 + 4);
    fVar14 = *(float *)(param_1 + 8) - *(float *)(param_3 + 8);
    fVar2 = (float)((uint)(fVar14 * fVar9 + fVar12 * fVar2 + fVar13 * fVar10) ^
                    (uint)fVar11 & 0x80000000);
    if (fVar2 < 0.0 != NAN(fVar2)) {
      return 0;
    }
    if (fVar1 < fVar2 == (NAN(fVar1) || NAN(fVar2))) {
      fVar9 = fVar13 * fVar5 - fVar14 * fVar4;
      fVar5 = fVar14 * fVar3 - fVar12 * fVar5;
      fVar4 = fVar12 * fVar4 - fVar13 * fVar3;
      fVar3 = (float)((uint)(fVar9 * *(float *)param_2 +
                             fVar5 * *(float *)(param_2 + 4) +
                             fVar4 * *(float *)(param_2 + 8)) ^
                      (uint)fVar11 & 0x80000000);
      if (fVar3 < 0.0 != NAN(fVar3)) {
        return 0;
      }
      if (fVar1 < fVar2 + fVar3 == (NAN(fVar1) || NAN(fVar2 + fVar3))) {
        fVar1 = fVar1 / 1.0;
        *param_6 = fVar1 * fVar2;
        *param_7 = fVar1 * fVar3;
        *param_8 = fVar1 * (fVar4 * fVar8 + fVar7 * fVar5 + fVar6 * fVar9);
        *param_8 = (float)((uint)fVar11 & 0x80000000 ^ (uint)*param_8);
        return 1;
      }
      return 0;
    }
  }
  return 0;
}

/* public: static int __cdecl GmVec3::DoesRayIntersectTriangleCull(class GmVec3
   const &,class GmVec3 const &,class GmVec3 const &,class GmVec3 const &,class
   GmVec3 const &,float &,float &,float &)
    */

int __cdecl GmVec3::DoesRayIntersectTriangleCull(
    GmVec3 *param_1, GmVec3 *param_2, GmVec3 *param_3, GmVec3 *param_4,
    GmVec3 *param_5, float *param_6, float *param_7, float *param_8)

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

  fVar1 = *(float *)param_4 - *(float *)param_3;
  fVar2 = *(float *)(param_4 + 4) - *(float *)(param_3 + 4);
  fVar3 = *(float *)(param_4 + 8) - *(float *)(param_3 + 8);
  fVar4 = *(float *)param_5 - *(float *)param_3;
  fVar5 = *(float *)(param_5 + 4) - *(float *)(param_3 + 4);
  fVar6 = *(float *)(param_5 + 8) - *(float *)(param_3 + 8);
  fVar7 = fVar6 * *(float *)(param_2 + 4) - fVar5 * *(float *)(param_2 + 8);
  fVar9 = fVar4 * *(float *)(param_2 + 8) - *(float *)param_2 * fVar6;
  fVar8 = *(float *)param_2 * fVar5 - fVar4 * *(float *)(param_2 + 4);
  fVar10 = fVar2 * fVar9 + fVar1 * fVar7 + fVar3 * fVar8;
  if (fVar10 < 0.0 != NAN(fVar10)) {
    return 0;
  }
  fVar11 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (fVar11 * 1e-05 * fVar11 <= fVar10 * fVar10) {
    fVar11 = *(float *)param_1 - *(float *)param_3;
    fVar12 = *(float *)(param_1 + 4) - *(float *)(param_3 + 4);
    fVar13 = *(float *)(param_1 + 8) - *(float *)(param_3 + 8);
    fVar7 = fVar13 * fVar8 + fVar11 * fVar7 + fVar12 * fVar9;
    if (fVar7 < 0.0 != NAN(fVar7)) {
      return 0;
    }
    if (fVar10 < fVar7 != (NAN(fVar10) || NAN(fVar7))) {
      return 0;
    }
    fVar8 = fVar12 * fVar3 - fVar13 * fVar2;
    fVar3 = fVar13 * fVar1 - fVar11 * fVar3;
    fVar1 = fVar11 * fVar2 - fVar12 * fVar1;
    fVar2 = fVar8 * *(float *)param_2 + fVar3 * *(float *)(param_2 + 4) +
            fVar1 * *(float *)(param_2 + 8);
    if (fVar2 < 0.0 == NAN(fVar2)) {
      if (fVar10 < fVar7 + fVar2 != (NAN(fVar10) || NAN(fVar7 + fVar2))) {
        return 0;
      }
      fVar10 = fVar10 / 1.0;
      *param_6 = fVar10 * fVar7;
      *param_7 = fVar10 * fVar2;
      *param_8 = fVar10 * (fVar1 * fVar6 + fVar5 * fVar3 + fVar4 * fVar8);
      return 1;
    }
  }
  return 0;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: static float __cdecl GmVec3::GetAngle(class GmVec3 const &,class
 * GmVec3 const &) */

float __cdecl GmVec3::GetAngle(GmVec3 *param_1, GmVec3 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  float local_18;
  float local_14;
  float local_10;

  fVar6 = (float10)__CIacos();
  fVar1 = (float)fVar6;
  if (1e-05 < fVar1) {
    local_18 = *(float *)param_1;
    local_14 = *(float *)(param_1 + 4);
    local_10 = *(float *)(param_1 + 8);
    fVar2 = local_10 * local_10 + local_18 * local_18 + local_14 * local_14;
    if (_DAT_00d1a8f0 < fVar2 != (NAN(_DAT_00d1a8f0) || NAN(fVar2))) {
      fVar6 = (float10)__CIsqrt();
      fVar2 = 1.0 / (float)fVar6;
      local_18 = fVar2 * local_18;
      local_14 = local_14 * fVar2;
      local_10 = fVar2 * local_10;
    }
    fVar2 = *(float *)param_2;
    fVar3 = *(float *)(param_2 + 4);
    fVar4 = *(float *)(param_2 + 8);
    fVar5 = fVar3 * fVar3 + fVar2 * fVar2 + fVar4 * fVar4;
    if (_DAT_00d1a8f0 < fVar5 != (NAN(_DAT_00d1a8f0) || NAN(fVar5))) {
      fVar6 = (float10)__CIsqrt();
      fVar5 = 1.0 / (float)fVar6;
      fVar2 = fVar5 * fVar2;
      fVar3 = fVar5 * fVar3;
      fVar4 = fVar5 * fVar4;
    }
    fVar2 = (fVar3 * local_18 - local_14 * fVar2) * 0.0 +
            (local_10 * fVar2 - local_18 * fVar4) +
            (fVar4 * local_14 - local_10 * fVar3) * 0.0;
    if (fVar2 < 0.0 != NAN(fVar2)) {
      fVar1 = -fVar1;
    }
  }
  return fVar1;
}

/* public: static float __cdecl GmVec3::GetInnerAngle(class GmVec3 const &,class
 * GmVec3 const &) */

float __cdecl GmVec3::GetInnerAngle(GmVec3 *param_1, GmVec3 *param_2)

{
  float10 fVar1;

  fVar1 = (float10)__CIacos();
  return (float)fVar1;
}

/* public: unsigned long __thiscall GmVec3::IsNearlyEqual(class GmVec3 const
 * &)const  */

ulong __thiscall GmVec3::IsNearlyEqual(GmVec3 *this, GmVec3 *param_1)

{
  float fVar1;

  fVar1 = *(float *)param_1 - ABS(*(float *)param_1) * 1e-05;
  if (fVar1 < *(float *)this == (fVar1 == *(float *)this)) {
    return 0;
  }
  fVar1 = *(float *)param_1 + ABS(*(float *)param_1) * 1e-05;
  if ((((*(float *)this < fVar1 != (*(float *)this == fVar1)) &&
        (fVar1 = *(float *)(param_1 + 4) - ABS(*(float *)(param_1 + 4)) * 1e-05,
         fVar1 < *(float *)(this + 4) != (fVar1 == *(float *)(this + 4)))) &&
       (fVar1 = *(float *)(param_1 + 4) + ABS(*(float *)(param_1 + 4)) * 1e-05,
        *(float *)(this + 4) < fVar1 != (*(float *)(this + 4) == fVar1))) &&
      ((fVar1 = *(float *)(param_1 + 8) - ABS(*(float *)(param_1 + 8)) * 1e-05,
        fVar1 < *(float *)(this + 8) != (fVar1 == *(float *)(this + 8)) &&
            (fVar1 =
                 *(float *)(param_1 + 8) + ABS(*(float *)(param_1 + 8)) * 1e-05,
             *(float *)(this + 8) < fVar1 !=
                 (*(float *)(this + 8) == fVar1))))) {
    return 1;
  }
  return 0;
}

/* public: void __thiscall GmVec3::Mult(class GmIso4 const &) */

void __thiscall GmVec3::Mult(GmVec3 *this, GmIso4 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;

  fVar1 = *(float *)this;
  fVar2 = *(float *)(this + 4);
  fVar3 = *(float *)(this + 8);
  *(float *)this = fVar2 * *(float *)(param_1 + 4) + fVar1 * *(float *)param_1 +
                   fVar3 * *(float *)(param_1 + 8) + *(float *)(param_1 + 0x24);
  *(float *)(this + 4) =
      *(float *)(param_1 + 0x14) * fVar3 + *(float *)(param_1 + 0x10) * fVar2 +
      *(float *)(param_1 + 0xc) * fVar1 + *(float *)(param_1 + 0x28);
  *(float *)(this + 8) =
      *(float *)(param_1 + 0x18) * fVar1 + *(float *)(param_1 + 0x1c) * fVar2 +
      *(float *)(param_1 + 0x20) * fVar3 + *(float *)(param_1 + 0x2c);
  return;
}

/* public: void __thiscall GmVec3::Mult(class GmMat3 const &) */

void __thiscall GmVec3::Mult(GmVec3 *this, GmMat3 *param_1)

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

  fVar1 = *(float *)(param_1 + 0xc);
  fVar2 = *(float *)this;
  fVar3 = *(float *)(param_1 + 0x10);
  fVar4 = *(float *)(param_1 + 0x14);
  fVar5 = *(float *)(param_1 + 0x18);
  fVar6 = *(float *)this;
  fVar7 = *(float *)(param_1 + 0x1c);
  fVar8 = *(float *)(this + 4);
  fVar9 = *(float *)(param_1 + 0x20);
  *(float *)this = *(float *)(param_1 + 8) * *(float *)(this + 8) +
                   *(float *)param_1 * *(float *)this +
                   *(float *)(param_1 + 4) * *(float *)(this + 4);
  *(float *)(this + 4) = fVar4 * *(float *)(this + 8) +
                         fVar3 * *(float *)(this + 4) + fVar1 * fVar2;
  *(float *)(this + 8) =
      fVar9 * *(float *)(this + 8) + fVar7 * fVar8 + fVar5 * fVar6;
  return;
}

/* public: void __thiscall GmVec3::Mult(class GmMat4 const &) */

void __thiscall GmVec3::Mult(GmVec3 *this, GmMat4 *param_1)

{
  float fVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_20 = *(undefined4 *)this;
  local_1c = *(undefined4 *)(this + 4);
  local_18 = *(undefined4 *)(this + 8);
  local_14 = 0x3f800000;
  GmVec4::SetMult((GmVec4 *)&local_10, (GmVec4 *)&local_20, param_1);
  fVar1 = 1.0 / ABS(local_4);
  *(float *)this = fVar1 * local_10;
  *(float *)(this + 4) = local_c * fVar1;
  *(float *)(this + 8) = fVar1 * local_8;
  return;
}

/* public: void __thiscall GmVec3::MultInverse(class GmIso4 const &) */

void __thiscall GmVec3::MultInverse(GmVec3 *this, GmIso4 *param_1)

{
  float local_c;
  float local_8;
  float local_4;

  local_c = *(float *)this - *(float *)(param_1 + 0x24);
  local_8 = *(float *)(this + 4) - *(float *)(param_1 + 0x28);
  local_4 = *(float *)(this + 8) - *(float *)(param_1 + 0x2c);
  MultTranspose((GmVec3 *)&local_c, (GmMat3 *)param_1);
  *(float *)this = local_c;
  *(float *)(this + 4) = local_8;
  *(float *)(this + 8) = local_4;
  return;
}

/* public: void __thiscall GmVec3::MultTranspose(class GmMat3 const &) */

void __thiscall GmVec3::MultTranspose(GmVec3 *this, GmMat3 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;

  fVar1 = *(float *)this;
  fVar2 = *(float *)(this + 4);
  fVar3 = *(float *)(this + 8);
  *(float *)this = fVar2 * *(float *)(param_1 + 0xc) +
                   fVar1 * *(float *)param_1 +
                   fVar3 * *(float *)(param_1 + 0x18);
  *(float *)(this + 4) = *(float *)(param_1 + 0x1c) * fVar3 +
                         *(float *)(param_1 + 0x10) * fVar2 +
                         *(float *)(param_1 + 4) * fVar1;
  *(float *)(this + 8) = *(float *)(param_1 + 8) * fVar1 +
                         *(float *)(param_1 + 0x14) * fVar2 +
                         *(float *)(param_1 + 0x20) * fVar3;
  return;
}

/* public: void __thiscall GmVec3::SetFromBGRA(unsigned char const *,unsigned
 * long) */

void __thiscall GmVec3::SetFromBGRA(GmVec3 *this, uchar *param_1, ulong param_2)

{
  *(float *)(this + 8) = (float)(uint)*param_1 * 0.003921569;
  *(float *)(this + 4) = (float)(uint)param_1[1] * 0.003921569;
  *(float *)this = (float)(uint)param_1[2] * 0.003921569;
  return;
}

/* public: void __thiscall GmVec3::SetInverseTranslation(class GmIso4 const &)
 */

void __thiscall GmVec3::SetInverseTranslation(GmVec3 *this, GmIso4 *param_1)

{
  *(float *)this = (-*(float *)(param_1 + 0x24) * *(float *)param_1 -
                    *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x28)) -
                   *(float *)(param_1 + 0x18) * *(float *)(param_1 + 0x2c);
  *(float *)(this + 4) =
      (-*(float *)(param_1 + 0x24) * *(float *)(param_1 + 4) -
       *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x28)) -
      *(float *)(param_1 + 0x1c) * *(float *)(param_1 + 0x2c);
  *(float *)(this + 8) =
      (-*(float *)(param_1 + 0x24) * *(float *)(param_1 + 8) -
       *(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x28)) -
      *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x2c);
  return;
}

/* public: void __thiscall GmVec3::SetMult(class GmVec3 const &,class GmMat3
 * const &) */

void __thiscall GmVec3::SetMult(GmVec3 *this, GmVec3 *param_1, GmMat3 *param_2)

{
  *(float *)this = *(float *)(param_2 + 8) * *(float *)(param_1 + 8) +
                   *(float *)param_1 * *(float *)param_2 +
                   *(float *)(param_2 + 4) * *(float *)(param_1 + 4);
  *(float *)(this + 4) = *(float *)(param_2 + 0x14) * *(float *)(param_1 + 8) +
                         *(float *)(param_2 + 0x10) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 0xc) * *(float *)param_1;
  *(float *)(this + 8) = *(float *)(param_2 + 0x20) * *(float *)(param_1 + 8) +
                         *(float *)(param_2 + 0x1c) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 0x18) * *(float *)param_1;
  return;
}

/* public: void __thiscall GmVec3::SetMult(class GmVec3 const &,class GmIso4
 * const &) */

void __thiscall GmVec3::SetMult(GmVec3 *this, GmVec3 *param_1, GmIso4 *param_2)

{
  *(float *)this = *(float *)(param_2 + 8) * *(float *)(param_1 + 8) +
                   *(float *)param_1 * *(float *)param_2 +
                   *(float *)(param_2 + 4) * *(float *)(param_1 + 4) +
                   *(float *)(param_2 + 0x24);
  *(float *)(this + 4) = *(float *)(param_2 + 0x14) * *(float *)(param_1 + 8) +
                         *(float *)(param_2 + 0x10) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 0xc) * *(float *)param_1 +
                         *(float *)(param_2 + 0x28);
  *(float *)(this + 8) = *(float *)(param_2 + 0x20) * *(float *)(param_1 + 8) +
                         *(float *)(param_2 + 0x1c) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 0x18) * *(float *)param_1 +
                         *(float *)(param_2 + 0x2c);
  return;
}

/* public: void __thiscall GmVec3::SetMult(class GmVec3 const &,class GmMat4
 * const &) */

void __thiscall GmVec3::SetMult(GmVec3 *this, GmVec3 *param_1, GmMat4 *param_2)

{
  float fVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_20 = *(undefined4 *)param_1;
  local_1c = *(undefined4 *)(param_1 + 4);
  local_18 = *(undefined4 *)(param_1 + 8);
  local_14 = 0x3f800000;
  GmVec4::SetMult((GmVec4 *)&local_10, (GmVec4 *)&local_20, param_2);
  fVar1 = 1.0 / ABS(local_4);
  *(float *)this = fVar1 * local_10;
  *(float *)(this + 4) = local_c * fVar1;
  *(float *)(this + 8) = fVar1 * local_8;
  return;
}

/* public: void __thiscall GmVec3::SetMultTranspose(class GmVec3 const &,class
 * GmMat3 const &) */

void __thiscall GmVec3::SetMultTranspose(GmVec3 *this, GmVec3 *param_1,
                                         GmMat3 *param_2)

{
  *(float *)this = *(float *)(param_2 + 0x18) * *(float *)(param_1 + 8) +
                   *(float *)param_1 * *(float *)param_2 +
                   *(float *)(param_2 + 0xc) * *(float *)(param_1 + 4);
  *(float *)(this + 4) = *(float *)(param_2 + 0x1c) * *(float *)(param_1 + 8) +
                         *(float *)(param_2 + 0x10) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 4) * *(float *)param_1;
  *(float *)(this + 8) = *(float *)(param_2 + 0x20) * *(float *)(param_1 + 8) +
                         *(float *)(param_2 + 0x14) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 8) * *(float *)param_1;
  return;
}
