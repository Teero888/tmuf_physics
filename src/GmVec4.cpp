
/* public: void __thiscall GmVec4::Add(class GmVec4) */

void __thiscall GmVec4::Add(GmVec4 *this, float param_1, float param_2,
                            float param_3, float param_4)

{
  *(float *)this = *(float *)this + param_1;
  *(float *)(this + 4) = *(float *)(this + 4) + param_2;
  *(float *)(this + 8) = *(float *)(this + 8) + param_3;
  *(float *)(this + 0xc) = param_4 + *(float *)(this + 0xc);
  return;
}

/* public: void __thiscall GmVec4::GetClipFlag(struct GmClipFlag_HalfCube
 * &)const  */

void __thiscall GmVec4::GetClipFlag(GmVec4 *this, GmClipFlag_HalfCube *param_1)

{
  float fVar1;
  uint uVar2;

  *(undefined4 *)param_1 = 0;
  fVar1 = *(float *)(this + 8);
  *(uint *)param_1 = (uint)(fVar1 < 0.0);
  uVar2 = (uint)(*(float *)(this + 0xc) < *(float *)(this + 8) !=
                 (NAN(*(float *)(this + 0xc)) || NAN(*(float *)(this + 8)))) *
                  2 &
              2 ^
          (uint)(fVar1 < 0.0);
  *(uint *)param_1 = uVar2;
  uVar2 =
      (uint)(*(float *)(this + 4) < -*(float *)(this + 0xc)) * 4 & 4 ^ uVar2;
  *(uint *)param_1 = uVar2;
  uVar2 = (uint)(*(float *)(this + 0xc) < *(float *)(this + 4) !=
                 (NAN(*(float *)(this + 0xc)) || NAN(*(float *)(this + 4)))) *
                  8 &
              8 ^
          uVar2;
  *(uint *)param_1 = uVar2;
  uVar2 = (uint)(*(float *)this < -*(float *)(this + 0xc)) << 4 ^ uVar2;
  *(uint *)param_1 = uVar2;
  if (*(float *)(this + 0xc) < *(float *)this !=
      (NAN(*(float *)(this + 0xc)) || NAN(*(float *)this))) {
    *(uint *)param_1 = uVar2 ^ 0x20;
    return;
  }
  *(uint *)param_1 = uVar2;
  return;
}

/* public: static void __cdecl GmVec4::GetClipFlags(class GmVec4 const *,struct
 *GmClipFlag_HalfCube ,unsigned long) */

void __cdecl GmVec4::GetClipFlags(GmVec4 *param_1, GmClipFlag_HalfCube *param_2,
                                  ulong param_3)

{
  if (param_3 != 0) {
    do {
      GetClipFlag(param_1, param_2);
      param_2 = param_2 + 4;
      param_1 = param_1 + 0x10;
      param_3 = param_3 - 1;
    } while (param_3 != 0);
  }
  return;
}

/* public: void __thiscall GmVec4::Mult(float const &) */

void __thiscall GmVec4::Mult(GmVec4 *this, float *param_1)

{
  *(float *)this = *param_1 * *(float *)this;
  *(float *)(this + 4) = *param_1 * *(float *)(this + 4);
  *(float *)(this + 8) = *(float *)(this + 8) * *param_1;
  *(float *)(this + 0xc) = *param_1 * *(float *)(this + 0xc);
  return;
}

/* public: void __thiscall GmVec4::Mult(class GmMat4 const &) */

void __thiscall GmVec4::Mult(GmVec4 *this, GmMat4 *param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  local_10 = *(undefined4 *)this;
  local_c = *(undefined4 *)(this + 4);
  local_8 = *(undefined4 *)(this + 8);
  local_4 = *(undefined4 *)(this + 0xc);
  SetMult(this, (GmVec4 *)&local_10, param_1);
  return;
}

/* public: void __thiscall GmVec4::Neg(void) */

void __thiscall GmVec4::Neg(GmVec4 *this)

{
  *(float *)this = -*(float *)this;
  *(float *)(this + 4) = -*(float *)(this + 4);
  *(float *)(this + 8) = -*(float *)(this + 8);
  *(float *)(this + 0xc) = -*(float *)(this + 0xc);
  return;
}
/* public: unsigned long __thiscall GmVec4::PlaneEqInterLine(class GmVec3 const
   &,class GmVec3 const
   &,float &)const  */

ulong __thiscall GmVec4::PlaneEqInterLine(GmVec4 *this, GmVec3 *param_1,
                                          GmVec3 *param_2, float *param_3)

{
  float fVar1;

  fVar1 = *(float *)(param_2 + 8) * *(float *)(this + 8) +
          *(float *)param_2 * *(float *)this +
          *(float *)(param_2 + 4) * *(float *)(this + 4);
  if (1e-05 < ABS(fVar1)) {
    *param_3 = -((*(float *)(param_1 + 8) * *(float *)(this + 8) +
                  *(float *)param_1 * *(float *)this +
                  *(float *)(param_1 + 4) * *(float *)(this + 4) +
                  *(float *)(this + 0xc)) /
                 fVar1);
    return 1;
  }
  return 0;
}
/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: unsigned long __thiscall GmVec4::PlaneEqInterPlane(class GmVec4 const
   &,class GmLine3
   &)const  */

ulong __thiscall GmVec4::PlaneEqInterPlane(GmVec4 *this, GmVec4 *param_1,
                                           GmLine3 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;

  *(float *)(param_2 + 0xc) = *(float *)(param_1 + 8) * *(float *)(this + 4) -
                              *(float *)(param_1 + 4) * *(float *)(this + 8);
  *(float *)(param_2 + 0x10) = *(float *)(this + 8) * *(float *)param_1 -
                               *(float *)(param_1 + 8) * *(float *)this;
  fVar1 = *(float *)(param_1 + 4) * *(float *)this -
          *(float *)param_1 * *(float *)(this + 4);
  *(float *)(param_2 + 0x14) = fVar1;
  fVar1 = *(float *)(param_2 + 0xc) * *(float *)(param_2 + 0xc) +
          *(float *)(param_2 + 0x10) * *(float *)(param_2 + 0x10) +
          fVar1 * fVar1;
  if (_DAT_00d1a8ac < fVar1 != (NAN(_DAT_00d1a8ac) || NAN(fVar1))) {
    fVar7 = (float10)__CIsqrt();
    fVar3 = 1.0 / (float)fVar7;
    fVar1 = *(float *)(param_2 + 0xc);
    *(float *)(param_2 + 0xc) = fVar3 * fVar1;
    fVar2 = *(float *)(param_2 + 0x10);
    *(float *)(param_2 + 0x10) = fVar3 * fVar2;
    *(float *)(param_2 + 0x14) = *(float *)(param_2 + 0x14) * fVar3;
    fVar1 = ABS(fVar3 * fVar1);
    if (0.5 < fVar1 == NAN(fVar1)) {
      fVar1 = ABS(fVar3 * fVar2);
      if (0.5 < fVar1 == NAN(fVar1)) {
        iVar6 = 2;
        iVar5 = 1;
      } else {
        iVar6 = 1;
        iVar5 = 2;
      }
      iVar4 = 0;
    } else {
      iVar6 = 0;
      iVar4 = 1;
      iVar5 = 2;
    }
    *(undefined4 *)(param_2 + iVar6 * 4) = 0;
    GmFunc::SolveLinearSystem2(
        (float *)(param_2 + iVar4 * 4), (float *)(param_2 + iVar5 * 4),
        *(float *)(this + iVar4 * 4), *(float *)(this + iVar5 * 4),
        -*(float *)(this + 0xc), *(float *)(param_1 + iVar4 * 4),
        *(float *)(param_1 + iVar5 * 4), -*(float *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}

/* public: unsigned long __thiscall GmVec4::PlaneEqIsNearlyEqual(class GmVec4
   const
   &,float,float)const  */

ulong __thiscall GmVec4::PlaneEqIsNearlyEqual(GmVec4 *this, GmVec4 *param_1,
                                              float param_2, float param_3)

{
  float fVar1;

  fVar1 = *(float *)(param_1 + 8) * *(float *)(this + 8) +
          *(float *)param_1 * *(float *)this +
          *(float *)(param_1 + 4) * *(float *)(this + 4);
  if (fVar1 < 0.99 == NAN(fVar1)) {
    if (ABS(*(float *)(this + 0xc) - *(float *)(param_1 + 0xc)) <= 0.1) {
      return 1;
    }
  }
  return 0;
}

/* public: void __thiscall GmVec4::PlaneEqMult(class GmIso4 const &) */

void __thiscall GmVec4::PlaneEqMult(GmVec4 *this, GmIso4 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;

  fVar1 = *(float *)(param_1 + 8) * *(float *)(this + 8) +
          *(float *)param_1 * *(float *)this +
          *(float *)(param_1 + 4) * *(float *)(this + 4);
  fVar2 = *(float *)(param_1 + 0x14) * *(float *)(this + 8) +
          *(float *)(param_1 + 0x10) * *(float *)(this + 4) +
          *(float *)(param_1 + 0xc) * *(float *)this;
  fVar3 = *(float *)(param_1 + 0x20) * *(float *)(this + 8) +
          *(float *)(param_1 + 0x1c) * *(float *)(this + 4) +
          *(float *)(param_1 + 0x18) * *(float *)this;
  *(float *)this = fVar1;
  *(float *)(this + 4) = fVar2;
  *(float *)(this + 8) = fVar3;
  *(float *)(this + 0xc) =
      *(float *)(this + 0xc) -
      (fVar3 * *(float *)(param_1 + 0x2c) + *(float *)(param_1 + 0x28) * fVar2 +
       *(float *)(param_1 + 0x24) * fVar1);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: unsigned long __thiscall GmVec4::PlaneEqSetFrom3Pos(class GmVec3
   const &,class GmVec3 const &,class GmVec3 const &) */

ulong __thiscall GmVec4::PlaneEqSetFrom3Pos(GmVec4 *this, GmVec3 *param_1,
                                            GmVec3 *param_2, GmVec3 *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 fVar5;

  fVar2 = (*(float *)(param_2 + 4) - *(float *)(param_1 + 4)) *
              (*(float *)(param_3 + 8) - *(float *)(param_1 + 8)) -
          (*(float *)(param_2 + 8) - *(float *)(param_1 + 8)) *
              (*(float *)(param_3 + 4) - *(float *)(param_1 + 4));
  fVar1 = (*(float *)param_3 - *(float *)param_1) *
              (*(float *)(param_2 + 8) - *(float *)(param_1 + 8)) -
          (*(float *)param_2 - *(float *)param_1) *
              (*(float *)(param_3 + 8) - *(float *)(param_1 + 8));
  fVar3 = (*(float *)(param_3 + 4) - *(float *)(param_1 + 4)) *
              (*(float *)param_2 - *(float *)param_1) -
          (*(float *)(param_2 + 4) - *(float *)(param_1 + 4)) *
              (*(float *)param_3 - *(float *)param_1);
  fVar4 = fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1;
  if (_DAT_00d07588 < fVar4 != (NAN(_DAT_00d07588) || NAN(fVar4))) {
    fVar5 = (float10)__CIsqrt();
    fVar4 = 1.0 / (float)fVar5;
    *(float *)this = fVar4 * fVar2;
    *(float *)(this + 4) = fVar4 * fVar1;
    *(float *)(this + 8) = fVar4 * fVar3;
    *(float *)(this + 0xc) = (-(fVar4 * fVar2) * *(float *)param_1 -
                              *(float *)(param_1 + 4) * fVar4 * fVar1) -
                             *(float *)(param_1 + 8) * fVar4 * fVar3;
    return 1;
  }
  return 0;
}

/* public: void __thiscall GmVec4::PlaneEqSetMult(class GmVec4 const &,class
 * GmIso4 const &) */

void __thiscall GmVec4::PlaneEqSetMult(GmVec4 *this, GmVec4 *param_1,
                                       GmIso4 *param_2)

{
  float fVar1;

  *(float *)this = *(float *)(param_2 + 8) * *(float *)(param_1 + 8) +
                   *(float *)param_1 * *(float *)param_2 +
                   *(float *)(param_2 + 4) * *(float *)(param_1 + 4);
  *(float *)(this + 4) = *(float *)(param_2 + 0x14) * *(float *)(param_1 + 8) +
                         *(float *)(param_2 + 0x10) * *(float *)(param_1 + 4) +
                         *(float *)(param_2 + 0xc) * *(float *)param_1;
  fVar1 = *(float *)(param_2 + 0x20) * *(float *)(param_1 + 8) +
          *(float *)(param_2 + 0x1c) * *(float *)(param_1 + 4) +
          *(float *)(param_2 + 0x18) * *(float *)param_1;
  *(float *)(this + 8) = fVar1;
  *(float *)(this + 0xc) = *(float *)(param_1 + 0xc) -
                           (*(float *)(param_2 + 0x24) * *(float *)this +
                            *(float *)(param_2 + 0x28) * *(float *)(this + 4) +
                            *(float *)(param_2 + 0x2c) * fVar1);
  return;
}

/* public: void __thiscall GmVec4::PlaneEqSetNormPos(class GmVec3 const &,class
 * GmVec3 const &) */

void __thiscall GmVec4::PlaneEqSetNormPos(GmVec4 *this, GmVec3 *param_1,
                                          GmVec3 *param_2)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(float *)(this + 0xc) = (-*(float *)param_1 * *(float *)param_2 -
                            *(float *)(param_2 + 4) * *(float *)(param_1 + 4)) -
                           *(float *)(param_2 + 8) * *(float *)(param_1 + 8);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: static void __cdecl GmVec4::PolygonClip(class CFastBuffer<class
   GmVec4> &,class CFastBuffer<struct GmClipFlag_HalfCube> &) */

void __cdecl GmVec4::PolygonClip(CFastBuffer<> *param_1, CFastBuffer<> *param_2)

{
  double dVar1;
  double dVar2;
  uint uVar3;
  ulong uVar4;
  float *pfVar5;
  double *pdVar6;
  int iVar7;
  SRpcSkinInfo *pSVar8;
  CDx9TextureKeeper **ppCVar9;
  uint uVar10;
  double *pdVar11;
  double *this;
  uint *puVar12;
  SRpcSkinInfo *_Dst;
  GmVector2<> *_Src;
  GmVector2<> *_Dst_00;
  size_t sVar13;
  ulong uVar14;
  uint local_34;
  uint local_24;
  uint local_18;
  CDx9TextureKeeper *local_14;
  double local_10;

  if ((_DAT_00d706d0 & 1) == 0) {
    _DAT_00d706d0 = _DAT_00d706d0 | 1;
    CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)&DAT_00d706c4);
    _atexit((_func_4879 *)&LAB_00b241f0);
  }
  uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)param_1);
  CFastBuffer<>::AllocSetCount((CFastBuffer<> *)&DAT_00d706c4, uVar4);
  uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)&DAT_00d706c4);
  uVar14 = 0;
  if (uVar4 != 0) {
    do {
      pfVar5 =
          (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)param_1, uVar14);
      pdVar6 = (double *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)&DAT_00d706c4, uVar14);
      *pdVar6 = (double)*pfVar5;
      uVar14 = uVar14 + 1;
      pdVar6[1] = (double)pfVar5[1];
      pdVar6[2] = (double)pfVar5[2];
      pdVar6[3] = (double)pfVar5[3];
    } while (uVar14 < uVar4);
  }
  local_34 = 0;
  do {
    iVar7 = 2 - (local_34 >> 1);
    uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)&DAT_00d706c4);
    uVar4 = uVar4 * 2 + 3;
    CFastBuffer<>::SetSizeAtLeast((CFastBuffer<> *)&DAT_00d706c4, uVar4);
    CFastBuffer<int>::SetSizeAtLeast((CFastBuffer<int> *)param_2, uVar4);
    pSVar8 = CFastBuffer<>::operator[]((CFastBuffer<> *)&DAT_00d706c4, 0);
    CFastBuffer<>::Add((CFastBuffer<> *)&DAT_00d706c4, (GmReal4_64 *)pSVar8);
    ppCVar9 = (CDx9TextureKeeper **)CFastBuffer<>::operator[](
        (CFastBuffer<> *)param_2, 0);
    CFastBuffer<>::Add((CFastBuffer<> *)param_2, ppCVar9);
    uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)&DAT_00d706c4);
    local_24 = 0;
    if (uVar4 != 0) {
      uVar10 = 1 << ((byte)local_34 & 0x1f);
      do {
        pdVar6 = (double *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)&DAT_00d706c4, local_24);
        ppCVar9 = (CDx9TextureKeeper **)CFastBuffer<>::operator[](
            (CFastBuffer<> *)param_2, local_24);
        local_14 = *ppCVar9;
        uVar3 = (uint)((uVar10 & (uint)local_14) == 0);
        if ((local_24 != 0) && (local_18 != uVar3)) {
          pdVar11 = (double *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)&DAT_00d706c4, local_24 - 1);
          local_10 = pdVar11[iVar7];
          dVar1 = pdVar11[3];
          dVar2 = pdVar6[iVar7];
          if (local_34 == 0) {
            dVar2 = local_10 - dVar2;
          LAB_008e619a:
            local_10 = local_10 / dVar2;
          } else {
            if ((local_34 & 1) != 0) {
              local_10 = dVar1 - local_10;
              dVar2 = (dVar2 + local_10) - pdVar6[3];
              goto LAB_008e619a;
            }
            local_10 = (-dVar1 - local_10) /
                       (pdVar6[3] + (dVar2 - (dVar1 + local_10)));
          }
          this = (double *)CFastBuffer<>::AddNewElem(
              (CFastBuffer<> *)&DAT_00d706c4);
          puVar12 = (uint *)CFastBuffer<>::AddNewElem((CFastBuffer<> *)param_2);
          dVar1 = 0.0;
          if ((local_10 < 0.0 == NAN(local_10)) &&
              (dVar1 = local_10, 1.0 < local_10 != NAN(local_10))) {
            dVar1 = 1.0;
          }
          dVar2 = 1.0 - dVar1;
          *this = *pdVar11 * dVar2 + *pdVar6 * dVar1;
          this[1] = pdVar6[1] * dVar1 + pdVar11[1] * dVar2;
          this[2] = pdVar6[2] * dVar1 + pdVar11[2] * dVar2;
          this[3] = dVar2 * pdVar11[3] + pdVar6[3] * dVar1;
          GmReal4_64::GetClipFlag((GmReal4_64 *)this,
                                  (GmClipFlag_HalfCube *)puVar12);
          *puVar12 = *puVar12 & ~uVar10;
        }
        if ((uVar3 != 0) && (local_24 < uVar4 - 1)) {
          CFastBuffer<>::Add((CFastBuffer<> *)&DAT_00d706c4,
                             (GmReal4_64 *)pdVar6);
          CFastBuffer<>::Add((CFastBuffer<> *)param_2, &local_14);
        }
        local_24 = local_24 + 1;
        local_18 = uVar3;
      } while (local_24 < uVar4);
    }
    uVar14 = CFastBuffer<>::GetCount((CFastBuffer<> *)&DAT_00d706c4);
    iVar7 = uVar14 - uVar4;
    if (iVar7 != 0) {
      sVar13 = iVar7 * 0x20;
      pSVar8 = CFastBuffer<>::operator[]((CFastBuffer<> *)&DAT_00d706c4, uVar4);
      _Dst = CFastBuffer<>::operator[]((CFastBuffer<> *)&DAT_00d706c4, 0);
      _memmove(_Dst, pSVar8, sVar13);
      sVar13 = iVar7 * 4;
      _Src = CFastBuffer<>::operator[]((CFastBuffer<> *)param_2, uVar4);
      _Dst_00 = CFastBuffer<>::operator[]((CFastBuffer<> *)param_2, 0);
      _memmove(_Dst_00, _Src, sVar13);
    }
    _DAT_00d706c4 = iVar7;
    *(int *)param_2 = iVar7;
    if ((iVar7 == 0) || (local_34 = local_34 + 1, 5 < local_34)) {
      uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)&DAT_00d706c4);
      CFastBuffer<>::AllocSetCount(param_1, uVar4);
      uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)param_1);
      uVar14 = 0;
      if (uVar4 != 0) {
        do {
          pfVar5 = (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)param_1,
                                                      uVar14);
          pdVar6 = (double *)CFastBuffer<>::operator[](
              (CFastBuffer<> *)&DAT_00d706c4, uVar14);
          *pfVar5 = (float)*pdVar6;
          uVar14 = uVar14 + 1;
          pfVar5[1] = (float)pdVar6[1];
          pfVar5[2] = (float)pdVar6[2];
          pfVar5[3] = (float)pdVar6[3];
        } while (uVar14 < uVar4);
      }
      return;
    }
  } while (true);
}

/* public: void __thiscall GmVec4::Set(float,float,float,float) */

void __thiscall GmVec4::Set(GmVec4 *this, float param_1, float param_2,
                            float param_3, float param_4)

{
  *(float *)this = param_1;
  *(float *)(this + 4) = param_2;
  *(float *)(this + 8) = param_3;
  *(float *)(this + 0xc) = param_4;
  return;
}

/* public: void __thiscall GmVec4::Set(class GmVec3 const &,float) */

void __thiscall GmVec4::Set(GmVec4 *this, GmVec3 *param_1, float param_2)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(float *)(this + 0xc) = param_2;
  return;
}

/* public: void __thiscall GmVec4::Set(class GmVec4 const &) */

void __thiscall GmVec4::Set(GmVec4 *this, GmVec4 *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  return;
}

/* public: void __thiscall GmVec4::SetBlend(class GmVec4 const &,class GmVec4
 * const &,float) */

void __thiscall GmVec4::SetBlend(GmVec4 *this, GmVec4 *param_1, GmVec4 *param_2,
                                 float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;

  fVar1 = 1.0 - param_3;
  *(float *)this = fVar1 * *(float *)param_1;
  *(float *)(this + 4) = *(float *)(param_1 + 4) * fVar1;
  *(float *)(this + 8) = *(float *)(param_1 + 8) * fVar1;
  *(float *)(this + 0xc) = fVar1 * *(float *)(param_1 + 0xc);
  fVar1 = *(float *)(param_2 + 4);
  fVar2 = *(float *)(param_2 + 8);
  fVar3 = *(float *)(param_2 + 0xc);
  *(float *)this = *(float *)this + *(float *)param_2 * param_3;
  *(float *)(this + 4) = fVar1 * param_3 + *(float *)(this + 4);
  *(float *)(this + 8) = fVar2 * param_3 + *(float *)(this + 8);
  *(float *)(this + 0xc) = param_3 * fVar3 + *(float *)(this + 0xc);
  return;
}

/* public: void __thiscall GmVec4::SetLeftMult(class GmIso4 const &,class GmVec4
 * const &) */

void __thiscall GmVec4::SetLeftMult(GmVec4 *this, GmIso4 *param_1,
                                    GmVec4 *param_2)

{
  *(float *)this = *(float *)(param_2 + 8) * *(float *)(param_1 + 0x18) +
                   *(float *)(param_2 + 4) * *(float *)(param_1 + 0xc) +
                   *(float *)param_1 * *(float *)param_2;
  *(float *)(this + 4) = *(float *)(param_1 + 0x1c) * *(float *)(param_2 + 8) +
                         *(float *)(param_1 + 4) * *(float *)param_2 +
                         *(float *)(param_1 + 0x10) * *(float *)(param_2 + 4);
  *(float *)(this + 8) = *(float *)(param_1 + 0x20) * *(float *)(param_2 + 8) +
                         *(float *)(param_1 + 8) * *(float *)param_2 +
                         *(float *)(param_1 + 0x14) * *(float *)(param_2 + 4);
  *(float *)(this + 0xc) =
      *(float *)(param_1 + 0x2c) * *(float *)(param_2 + 8) +
      *(float *)(param_1 + 0x24) * *(float *)param_2 +
      *(float *)(param_1 + 0x28) * *(float *)(param_2 + 4) +
      *(float *)(param_2 + 0xc);
  return;
}

/* public: void __thiscall GmVec4::SetMult(float,class GmVec4 const &) */

void __thiscall GmVec4::SetMult(GmVec4 *this, float param_1, GmVec4 *param_2)

{
  *(float *)this = param_1 * *(float *)param_2;
  *(float *)(this + 4) = *(float *)(param_2 + 4) * param_1;
  *(float *)(this + 8) = *(float *)(param_2 + 8) * param_1;
  *(float *)(this + 0xc) = param_1 * *(float *)(param_2 + 0xc);
  return;
}

/* public: void __thiscall GmVec4::SetMult(class GmVec4 const &,class GmMat4
 * const &) */

void __thiscall GmVec4::SetMult(GmVec4 *this, GmVec4 *param_1, GmMat4 *param_2)

{
  float *pfVar1;

  pfVar1 = (float *)GmMat4::operator[](param_2, 0);
  *(float *)this = pfVar1[3] * *(float *)(param_1 + 0xc) +
                   pfVar1[2] * *(float *)(param_1 + 8) +
                   *pfVar1 * *(float *)param_1 +
                   pfVar1[1] * *(float *)(param_1 + 4);
  pfVar1 = (float *)GmMat4::operator[](param_2, 1);
  *(float *)(this + 4) = pfVar1[3] * *(float *)(param_1 + 0xc) +
                         pfVar1[2] * *(float *)(param_1 + 8) +
                         *pfVar1 * *(float *)param_1 +
                         pfVar1[1] * *(float *)(param_1 + 4);
  pfVar1 = (float *)GmMat4::operator[](param_2, 2);
  *(float *)(this + 8) = pfVar1[3] * *(float *)(param_1 + 0xc) +
                         pfVar1[2] * *(float *)(param_1 + 8) +
                         *pfVar1 * *(float *)param_1 +
                         pfVar1[1] * *(float *)(param_1 + 4);
  pfVar1 = (float *)GmMat4::operator[](param_2, 3);
  *(float *)(this + 0xc) = pfVar1[3] * *(float *)(param_1 + 0xc) +
                           pfVar1[2] * *(float *)(param_1 + 8) +
                           *(float *)param_1 * *pfVar1 +
                           pfVar1[1] * *(float *)(param_1 + 4);
  return;
}

/* public: void __thiscall GmVec4::SetSub(class GmVec4 const &,class GmVec4
 * const &) */

void __thiscall GmVec4::SetSub(GmVec4 *this, GmVec4 *param_1, GmVec4 *param_2)

{
  *(float *)this = *(float *)param_1 - *(float *)param_2;
  *(float *)(this + 4) = *(float *)(param_1 + 4) - *(float *)(param_2 + 4);
  *(float *)(this + 8) = *(float *)(param_1 + 8) - *(float *)(param_2 + 8);
  *(float *)(this + 0xc) =
      *(float *)(param_1 + 0xc) - *(float *)(param_2 + 0xc);
  return;
}

/* public: void __thiscall GmVec4::Sub(class GmVec4) */

void __thiscall GmVec4::Sub(GmVec4 *this, float param_1, float param_2,
                            float param_3, float param_4)

{
  *(float *)this = *(float *)this - param_1;
  *(float *)(this + 4) = *(float *)(this + 4) - param_2;
  *(float *)(this + 8) = *(float *)(this + 8) - param_3;
  *(float *)(this + 0xc) = *(float *)(this + 0xc) - param_4;
  return;
}
