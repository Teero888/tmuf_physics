
/* public: void __thiscall GmRectAligned::Archive(class CClassicArchive &) */

void __thiscall GmRectAligned::Archive(GmRectAligned *this,
                                       CClassicArchive *param_1)

{
  CClassicArchive::DoReal(param_1, (float *)this, 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 4), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 8), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0xc), 1);
  return;
}

/* public: void __thiscall GmRectAligned::GetLocalCoordinates(class GmVec2 const
 * &,class GmVec2 &)
 */

void __thiscall GmRectAligned::GetLocalCoordinates(GmRectAligned *this,
                                                   GmVec2 *param_1,
                                                   GmVec2 *param_2)

{
  float fVar1;
  float fVar2;

  fVar1 = *(float *)(this + 0xc);
  fVar2 = *(float *)(this + 4);
  *(float *)param_2 =
      *(float *)param_1 - (*(float *)this + *(float *)(this + 8)) * 0.5;
  *(float *)(param_2 + 4) = *(float *)(param_1 + 4) - (fVar1 + fVar2) * 0.5;
  fVar1 = *(float *)(this + 0xc);
  fVar2 = *(float *)(this + 4);
  if ((1e-05 < *(float *)(this + 8) - *(float *)this) &&
      (1e-05 < fVar1 - fVar2)) {
    *(float *)param_2 =
        *(float *)param_2 / ((*(float *)(this + 8) - *(float *)this) * 0.5);
    *(float *)(param_2 + 4) = *(float *)(param_2 + 4) / ((fVar1 - fVar2) * 0.5);
    return;
  }
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)param_2 = 0;
  return;
}

/* public: void __thiscall GmRectAligned::Inter(class GmRectAligned const &) */

void __thiscall GmRectAligned::Inter(GmRectAligned *this,
                                     GmRectAligned *param_1)

{
  if (*(float *)this < *(float *)param_1 !=
      (NAN(*(float *)this) || NAN(*(float *)param_1))) {
    *(undefined4 *)this = *(undefined4 *)param_1;
  }
  if (*(float *)(this + 4) < *(float *)(param_1 + 4) !=
      (NAN(*(float *)(this + 4)) || NAN(*(float *)(param_1 + 4)))) {
    *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  }
  if (*(float *)(param_1 + 8) < *(float *)(this + 8)) {
    *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  }
  if (*(float *)(param_1 + 0xc) < *(float *)(this + 0xc)) {
    *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  }
  return;
}

/* public: unsigned long __thiscall GmRectAligned::IsInside(class GmVec2 const
 * &)const  */

ulong __thiscall GmRectAligned::IsInside(GmRectAligned *this, GmVec2 *param_1)

{
  if ((((*(float *)this < *(float *)param_1 !=
         (NAN(*(float *)this) || NAN(*(float *)param_1))) &&
        (*(float *)param_1 < *(float *)(this + 8))) &&
       (*(float *)(this + 4) < *(float *)(param_1 + 4) !=
        (NAN(*(float *)(this + 4)) || NAN(*(float *)(param_1 + 4))))) &&
      (*(float *)(param_1 + 4) < *(float *)(this + 0xc))) {
    return 1;
  }
  return 0;
}

/* public: unsigned long __thiscall GmRectAligned::IsNull(void)const  */

ulong __thiscall GmRectAligned::IsNull(GmRectAligned *this)

{
  if ((*(float *)(this + 8) < *(float *)this ==
       (NAN(*(float *)(this + 8)) || NAN(*(float *)this))) &&
      (*(float *)(this + 0xc) < *(float *)(this + 4) ==
       (NAN(*(float *)(this + 0xc)) || NAN(*(float *)(this + 4))))) {
    return 0;
  }
  return 1;
}

/* public: void __thiscall GmRectAligned::Mult(class GmScaleTrans2 const &) */

void __thiscall GmRectAligned::Mult(GmRectAligned *this, GmScaleTrans2 *param_1)

{
  *(float *)this = *(float *)param_1 * *(float *)this + *(float *)(param_1 + 8);
  *(float *)(this + 4) = *(float *)(param_1 + 4) * *(float *)(this + 4) +
                         *(float *)(param_1 + 0xc);
  *(float *)(this + 8) =
      *(float *)(this + 8) * *(float *)param_1 + *(float *)(param_1 + 8);
  *(float *)(this + 0xc) = *(float *)(this + 0xc) * *(float *)(param_1 + 4) +
                           *(float *)(param_1 + 0xc);
  return;
}

/* public: void __thiscall GmRectAligned::ScaleByEpsilon(void) */

void __thiscall GmRectAligned::ScaleByEpsilon(GmRectAligned *this)

{
  *(float *)this = *(float *)this - ABS(*(float *)this) * 1e-05;
  *(float *)(this + 4) =
      *(float *)(this + 4) - ABS(*(float *)(this + 4)) * 1e-05;
  *(float *)(this + 8) =
      ABS(*(float *)(this + 8)) * 1e-05 + *(float *)(this + 8);
  *(float *)(this + 0xc) =
      ABS(*(float *)(this + 0xc)) * 1e-05 + *(float *)(this + 0xc);
  return;
}

/* public: void __thiscall GmRectAligned::SetBoxProjection(class GmBoxAligned
   const &,class GmFrustum const &) */

void __thiscall GmRectAligned::SetBoxProjection(GmRectAligned *this,
                                                GmBoxAligned *param_1,
                                                GmFrustum *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float local_10[4];

  if (*(int *)param_2 == 0) {
    local_10[0] = *(float *)(param_2 + 0xc);
    if ((local_10[0] < *(float *)(param_1 + 0x14) + *(float *)(param_1 + 8) !=
         (NAN(local_10[0]) ||
          NAN(*(float *)(param_1 + 0x14) + *(float *)(param_1 + 8)))) &&
        (fVar1 = *(float *)(param_1 + 8) - *(float *)(param_1 + 0x14),
         fVar1 < *(float *)(param_2 + 0x18))) {
      if (local_10[0] <= fVar1) {
        local_10[0] = fVar1;
      }
      fVar4 = (*(float *)(param_2 + 0x10) + *(float *)(param_2 + 4)) * 0.5;
      fVar3 = (*(float *)(param_2 + 0x14) + *(float *)(param_2 + 8)) * 0.5;
      fVar1 = (*(float *)(param_2 + 0x10) - *(float *)(param_2 + 4)) * 0.5;
      fVar2 = (*(float *)(param_2 + 0x14) - *(float *)(param_2 + 8)) * 0.5;
      local_10[1] = *(float *)(param_1 + 0x14) + *(float *)(param_1 + 8);
      fVar5 = *(float *)param_1 - *(float *)(param_1 + 0xc);
      *(float *)this =
          (fVar5 - fVar4 * local_10[-((int)~(uint)fVar5 >> 0x1f)]) /
          (fVar1 * local_10[-((int)~(uint)fVar5 >> 0x1f)]);
      iVar6 = (int)(*(float *)param_1 + *(float *)(param_1 + 0xc)) >> 0x1f;
      *(float *)(this + 8) = ((*(float *)param_1 + *(float *)(param_1 + 0xc)) -
                              local_10[-iVar6] * fVar4) /
                             (fVar1 * local_10[-iVar6]);
      *(float *)(this + 4) =
          ((*(float *)(param_1 + 4) - *(float *)(param_1 + 0x10)) -
           fVar3 * local_10[-((int)~(uint)(*(float *)(param_1 + 4) -
                                           *(float *)(param_1 + 0x10)) >>
                              0x1f)]) /
          (fVar2 * local_10[-((int)~(uint)(*(float *)(param_1 + 4) -
                                           *(float *)(param_1 + 0x10)) >>
                              0x1f)]);
      iVar6 =
          (int)(*(float *)(param_1 + 0x10) + *(float *)(param_1 + 4)) >> 0x1f;
      *(float *)(this + 0xc) =
          ((*(float *)(param_1 + 0x10) + *(float *)(param_1 + 4)) -
           local_10[-iVar6] * fVar3) /
          (fVar2 * local_10[-iVar6]);
      return;
    }
  } else if ((*(float *)(param_2 + 0xc) - *(float *)(param_2 + 0x18) <
                  *(float *)(param_1 + 0x14) + *(float *)(param_1 + 8) !=
              (NAN(*(float *)(param_2 + 0xc) - *(float *)(param_2 + 0x18)) ||
               NAN(*(float *)(param_1 + 0x14) + *(float *)(param_1 + 8)))) &&
             (*(float *)(param_1 + 8) - *(float *)(param_1 + 0x14) <
              *(float *)(param_2 + 0x18) + *(float *)(param_2 + 0xc))) {
    fVar4 = ((*(float *)(param_2 + 4) - *(float *)(param_2 + 0x10)) +
             *(float *)(param_2 + 4) + *(float *)(param_2 + 0x10)) *
            0.5;
    fVar3 = ((*(float *)(param_2 + 8) - *(float *)(param_2 + 0x14)) +
             *(float *)(param_2 + 0x14) + *(float *)(param_2 + 8)) *
            0.5;
    fVar1 = ((*(float *)(param_2 + 4) + *(float *)(param_2 + 0x10)) -
             (*(float *)(param_2 + 4) - *(float *)(param_2 + 0x10))) /
            2.0;
    fVar2 = 2.0 / ((*(float *)(param_2 + 0x14) + *(float *)(param_2 + 8)) -
                   (*(float *)(param_2 + 8) - *(float *)(param_2 + 0x14)));
    *(float *)this =
        fVar1 * ((*(float *)param_1 - *(float *)(param_1 + 0xc)) - fVar4);
    *(float *)(this + 8) =
        ((*(float *)param_1 + *(float *)(param_1 + 0xc)) - fVar4) * fVar1;
    *(float *)(this + 4) =
        fVar2 *
        ((*(float *)(param_1 + 4) - *(float *)(param_1 + 0x10)) - fVar3);
    *(float *)(this + 0xc) =
        ((*(float *)(param_1 + 0x10) + *(float *)(param_1 + 4)) - fVar3) *
        fVar2;
    return;
  }
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)(this + 4) = 0x3f800000;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  return;
}

/* public: void __thiscall GmRectAligned::SetMult(class GmRectAligned const
   &,class GmScaleTrans2 const &) */

void __thiscall GmRectAligned::SetMult(GmRectAligned *this,
                                       GmRectAligned *param_1,
                                       GmScaleTrans2 *param_2)

{
  *(float *)this =
      *(float *)param_1 * *(float *)param_2 + *(float *)(param_2 + 8);
  *(float *)(this + 4) = *(float *)(param_1 + 4) * *(float *)(param_2 + 4) +
                         *(float *)(param_2 + 0xc);
  *(float *)(this + 8) =
      *(float *)(param_1 + 8) * *(float *)param_2 + *(float *)(param_2 + 8);
  *(float *)(this + 0xc) = *(float *)(param_1 + 0xc) * *(float *)(param_2 + 4) +
                           *(float *)(param_2 + 0xc);
  return;
}

/* public: void __thiscall GmRectAligned::SetSubRectFrom_m1p1(class
   GmRectAligned const &,class GmRectAligned const &) */

void __thiscall GmRectAligned::SetSubRectFrom_m1p1(GmRectAligned *this,
                                                   GmRectAligned *param_1,
                                                   GmRectAligned *param_2)

{
  GmScaleTrans2 local_10[16];

  GmScaleTrans2::SetRect_ConvTo_Rectm1p1(local_10, param_1);
  SetMult(this, param_2, local_10);
  return;
}

/* public: unsigned long __thiscall GmRectAligned::TestInter(class GmRectAligned
 * const &)const  */

ulong __thiscall GmRectAligned::TestInter(GmRectAligned *this,
                                          GmRectAligned *param_1)

{
  if ((((*(float *)param_1 < *(float *)(this + 8) !=
         (*(float *)param_1 == *(float *)(this + 8))) &&
        (*(float *)this <= *(float *)(param_1 + 8))) &&
       (*(float *)(param_1 + 4) < *(float *)(this + 0xc) !=
        (*(float *)(param_1 + 4) == *(float *)(this + 0xc)))) &&
      (*(float *)(this + 4) <= *(float *)(param_1 + 0xc))) {
    return 1;
  }
  return 0;
}

/* public: unsigned long __thiscall GmRectAligned::TestInterSegment(class GmVec2
   const &,class GmVec2 const &)const  */

ulong __thiscall GmRectAligned::TestInterSegment(GmRectAligned *this,
                                                 GmVec2 *param_1,
                                                 GmVec2 *param_2)

{
  GmVec2 *pGVar1;
  float fVar2;
  float fVar3;
  GmVec2 *pGVar4;
  ushort uVar5;
  uint uVar6;
  char cVar7;
  ulong uVar8;
  char cVar9;
  char cVar10;
  float fVar11;
  undefined4 local_8;
  float local_4;

  pGVar4 = param_1;
  local_8._0_2_ = 0;
  if (*(float *)(this + 8) < *(float *)param_1 ==
      (NAN(*(float *)(this + 8)) || NAN(*(float *)param_1))) {
    if (*(float *)param_1 < *(float *)this) {
      local_8._0_2_ = 1;
    }
  } else {
    local_8._0_2_ = 2;
  }
  if (*(float *)(this + 0xc) < *(float *)(param_1 + 4) ==
      (NAN(*(float *)(this + 0xc)) || NAN(*(float *)(param_1 + 4)))) {
    if (*(float *)(this + 4) <= *(float *)(param_1 + 4)) {
      cVar10 = '\0';
    } else {
      cVar10 = '\x01';
      local_8._0_2_ = CONCAT11(1, (char)local_8);
    }
  } else {
    cVar10 = '\x02';
    local_8._0_2_ = CONCAT11(2, (char)local_8);
  }
  uVar5 = (ushort)local_8;
  if ((ushort)local_8 == 0) {
    return 1;
  }
  local_8 = (uint)(ushort)local_8;
  uVar6 = local_8;
  if (*(float *)(this + 8) < *(float *)param_2 ==
      (NAN(*(float *)(this + 8)) || NAN(*(float *)param_2))) {
    if (*(float *)this <= *(float *)param_2) {
      local_8._2_1_ = '\0';
      cVar9 = local_8._2_1_;
      local_8 = uVar6;
    } else {
      local_8._0_3_ = CONCAT12(1, uVar5);
      local_8 = (uint)(uint3)local_8;
      cVar9 = '\x01';
    }
  } else {
    local_8._0_3_ = CONCAT12(2, uVar5);
    local_8 = (uint)(uint3)local_8;
    cVar9 = '\x02';
  }
  if (*(float *)(this + 0xc) < *(float *)(param_2 + 4) ==
      (NAN(*(float *)(this + 0xc)) || NAN(*(float *)(param_2 + 4)))) {
    if (*(float *)(this + 4) <= *(float *)(param_2 + 4)) {
      cVar7 = '\0';
    } else {
      cVar7 = '\x01';
      local_8 = CONCAT13(1, (uint3)local_8);
    }
  } else {
    cVar7 = '\x02';
    local_8 = CONCAT13(2, (uint3)local_8);
  }
  if (local_8._2_2_ == 0) {
    return 1;
  }
  if ((ushort)local_8 == local_8._2_2_) {
    return 0;
  }
  if ((char)local_8 == cVar9) {
    return (uint)((char)local_8 == '\0');
  }
  if (cVar10 == cVar7) {
    return (uint)(cVar10 == '\0');
  }
  if ((char)local_8 == '\0') {
    if (cVar10 == '\x01') {
      pGVar1 = *(GmVec2 **)(this + 4);
    } else {
      pGVar1 = *(GmVec2 **)(this + 0xc);
    }
    fVar11 = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
    param_2 = (GmVec2 *)(*(float *)param_2 - *(float *)param_1);
    param_1 = pGVar1;
  LAB_008ec3f4:
    uVar8 = GmFunc::Div((float *)&param_2, (float)param_2, fVar11);
    if (uVar8 == 0) {
      return 0;
    }
    fVar11 = ((float)param_1 - *(float *)(pGVar4 + 4)) * (float)param_2 +
             *(float *)pGVar4;
    if (fVar11 < *(float *)this) {
      return 0;
    }
    fVar2 = *(float *)(this + 8);
  } else {
    if (cVar10 == '\0') {
      if ((char)local_8 == '\x01') {
        pGVar1 = *(GmVec2 **)this;
      } else {
        pGVar1 = *(GmVec2 **)(this + 8);
      }
      fVar11 = *(float *)param_2 - *(float *)param_1;
      param_2 = (GmVec2 *)(*(float *)(param_2 + 4) - *(float *)(param_1 + 4));
      param_1 = pGVar1;
    LAB_008ec487:
      uVar8 = GmFunc::Div((float *)&param_2, (float)param_2, fVar11);
      if (uVar8 == 0) {
        return 0;
      }
      fVar11 = ((float)param_1 - *(float *)pGVar4) * (float)param_2 +
               *(float *)(pGVar4 + 4);
      if (fVar11 < *(float *)(this + 4)) {
        return 0;
      }
    } else {
      if (cVar9 == '\0') {
        if (cVar7 == '\x01') {
          pGVar1 = *(GmVec2 **)(this + 4);
        } else {
          pGVar1 = *(GmVec2 **)(this + 0xc);
        }
        fVar11 = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
        param_2 = (GmVec2 *)(*(float *)param_2 - *(float *)param_1);
        param_1 = pGVar1;
        goto LAB_008ec3f4;
      }
      if (cVar7 == '\0') {
        if (cVar9 == '\x01') {
          pGVar1 = *(GmVec2 **)this;
        } else {
          pGVar1 = *(GmVec2 **)(this + 8);
        }
        fVar11 = *(float *)param_2 - *(float *)param_1;
        param_2 = (GmVec2 *)(*(float *)(param_2 + 4) - *(float *)(param_1 + 4));
        param_1 = pGVar1;
        goto LAB_008ec487;
      }
      if (cVar10 == '\x01') {
        fVar11 = *(float *)(this + 4);
      } else {
        fVar11 = *(float *)(this + 0xc);
      }
      fVar2 = *(float *)(param_2 + 4);
      fVar3 = *(float *)(param_1 + 4);
      param_2 = (GmVec2 *)(*(float *)param_2 - *(float *)param_1);
      uVar8 = GmFunc::Div(&local_4, (float)param_2, fVar2 - fVar3);
      if (((uVar8 != 0) &&
           (fVar11 = (fVar11 - *(float *)(param_1 + 4)) * local_4 +
                     *(float *)param_1,
            *(float *)this <= fVar11)) &&
          (fVar11 <= *(float *)(this + 8))) {
        return 1;
      }
      if ((char)local_8 == '\x01') {
        fVar11 = *(float *)this;
      } else {
        fVar11 = *(float *)(this + 8);
      }
      uVar8 = GmFunc::Div((float *)&param_2, fVar2 - fVar3, (float)param_2);
      if (uVar8 == 0) {
        return 0;
      }
      fVar11 = (fVar11 - *(float *)param_1) * (float)param_2 +
               *(float *)(param_1 + 4);
      if (fVar11 < *(float *)(this + 4)) {
        return 0;
      }
    }
    fVar2 = *(float *)(this + 0xc);
  }
  if (fVar2 < fVar11) {
    return 0;
  }
  return 1;
}

/* public: unsigned long __thiscall GmRectAligned::TestInterTriangle(class
   GmVec2 const &,class GmVec2 const &,class GmVec2 const &,int &,float *,float
   *,int *,int)const  */

ulong __thiscall GmRectAligned::TestInterTriangle(
    GmRectAligned *this, GmVec2 *param_1, GmVec2 *param_2, GmVec2 *param_3,
    int *param_4, float *param_5, float *param_6, int *param_7, int param_8)

{
  float fVar1;
  GmVec2 *pGVar2;
  GmVec2 *pGVar3;
  GmVec2 *pGVar4;
  int *piVar5;
  float *pfVar6;
  float *pfVar7;
  ulong uVar8;
  int iVar9;
  float fVar10;
  float local_8;
  float local_4;

  piVar5 = param_4;
  pGVar3 = param_2;
  pGVar2 = param_1;
  fVar10 = *(float *)(this + 0xc);
  fVar1 = *(float *)(this + 4);
  local_8 = (*(float *)(this + 8) + *(float *)this) * 0.5;
  *param_4 = 1;
  local_4 = (fVar10 + fVar1) * 0.5;
  uVar8 = GmVec2::IsInTriangle(param_1, param_2, param_3, (GmVec2 *)&local_8,
                               (float *)&param_4, (float *)&param_2,
                               (int *)&param_1);
  if (uVar8 != 0) {
    if (param_5 != (float *)0x0) {
      *param_5 = (float)param_4;
      *param_6 = (float)param_2;
      *param_7 = (int)param_1;
    }
    return 1;
  }
  if (param_7 != (int *)0x0) {
    *param_7 = (int)param_1;
  }
  *piVar5 = 0;
  uVar8 = TestInterSegment(this, pGVar2, pGVar3);
  pfVar7 = param_6;
  pfVar6 = param_5;
  pGVar4 = param_3;
  if (uVar8 != 0) {
    if (((param_8 != 0) && (param_5 != (float *)0x0)) &&
        (param_6 != (float *)0x0)) {
      iVar9 = FUN_008ecb50(&local_8, (float *)pGVar3, (float *)&param_4);
      if (iVar9 != 0) {
        fVar10 = GmFunc::ClampReal((float)param_4, 0.0, 1.0);
        *pfVar6 = fVar10;
        *pfVar7 = 0.0;
      }
    }
    return 1;
  }
  uVar8 = TestInterSegment(this, param_3, pGVar3);
  pfVar7 = param_6;
  pfVar6 = param_5;
  if (uVar8 != 0) {
    if (((param_8 != 0) && (param_5 != (float *)0x0)) &&
        (param_6 != (float *)0x0)) {
      iVar9 = FUN_008ecb50(&local_8, (float *)pGVar3, (float *)&param_4);
      if (iVar9 != 0) {
        fVar10 = GmFunc::ClampReal((float)param_4, 0.0, 1.0);
        *pfVar6 = fVar10;
        *pfVar7 = 1.0 - fVar10;
      }
    }
    return 1;
  }
  uVar8 = TestInterSegment(this, pGVar2, pGVar4);
  pfVar7 = param_6;
  pfVar6 = param_5;
  if (uVar8 != 0) {
    if (((param_8 != 0) && (param_5 != (float *)0x0)) &&
        (param_6 != (float *)0x0)) {
      iVar9 = FUN_008ecb50(&local_8, (float *)pGVar4, (float *)&param_2);
      if (iVar9 != 0) {
        *pfVar6 = 0.0;
        fVar10 = GmFunc::ClampReal((float)param_2, 0.0, 1.0);
        *pfVar7 = fVar10;
      }
    }
    return 1;
  }
  return 0;
}

/* public: void __thiscall GmRectAligned::Union(class GmVec2 const &) */

void __thiscall GmRectAligned::Union(GmRectAligned *this, GmVec2 *param_1)

{
  if (*(float *)param_1 < *(float *)this) {
    *(undefined4 *)this = *(undefined4 *)param_1;
  }
  if (*(float *)(param_1 + 4) < *(float *)(this + 4)) {
    *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  }
  if (*(float *)(this + 8) < *(float *)param_1 !=
      (NAN(*(float *)(this + 8)) || NAN(*(float *)param_1))) {
    *(undefined4 *)(this + 8) = *(undefined4 *)param_1;
  }
  if (*(float *)(this + 0xc) < *(float *)(param_1 + 4) !=
      (NAN(*(float *)(this + 0xc)) || NAN(*(float *)(param_1 + 4)))) {
    *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 4);
  }
  return;
}
