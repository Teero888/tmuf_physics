
/* public: static unsigned long __cdecl GmFunc::Mod(int,int) */

ulong __cdecl GmFunc::Mod(int param_1, int param_2)

{
  ulong uVar1;

  uVar1 = param_1 % param_2;
  if ((int)uVar1 < 0) {
    uVar1 = uVar1 + param_2;
  }
  return uVar1;
}

/* public: static unsigned char __cdecl GmFunc::RealToNat7(float,float,float) */

uchar __cdecl GmFunc::RealToNat7(float param_1, float param_2, float param_3)

{
  float fVar1;

  fVar1 = ((param_1 - param_2) / (param_3 - param_2)) * 127.0;
  if (fVar1 < 0.0 == (fVar1 == 0.0)) {
    if (127.0 <= fVar1) {
      fVar1 = 127.0;
    }
  } else {
    fVar1 = 0.0;
  }
  param_2._0_1_ = (uchar)(int)ROUND(fVar1);
  return param_2._0_1_;
}

/* public: static float __cdecl GmFunc::AcosSafe(float) */

float __cdecl GmFunc::AcosSafe(float param_1)

{
  float10 fVar1;

  if (param_1 < -0.999999 != NAN(param_1)) {
    return 3.141593;
  }
  if (0.999999 < param_1) {
    return 0.0;
  }
  fVar1 = (float10)__CIacos();
  return (float)fVar1;
}

/* public: static unsigned long __cdecl
 * GmFunc::AreNearlyEqual(float,float,float) */

ulong __cdecl GmFunc::AreNearlyEqual(float param_1, float param_2,
                                     float param_3)

{
  if (ABS(param_1 - param_2) < param_3) {
    return 1;
  }
  return 0;
}

/* public: static float __cdecl GmFunc::AsinSafe(float) */

float __cdecl GmFunc::AsinSafe(float param_1)

{
  float10 fVar1;

  if (param_1 < -0.999999 != NAN(param_1)) {
    return -1.570796;
  }
  if (0.999999 < param_1) {
    return 1.570796;
  }
  fVar1 = (float10)__CIasin();
  return (float)fVar1;
}
/* public: static float __cdecl GmFunc::BlendAngles(float,float,float) */

float __cdecl GmFunc::BlendAngles(float param_1, float param_2, float param_3)

{
  float fVar1;

  fVar1 = param_2 - param_1;
  if (fVar1 <= 3.141593) {
    if (fVar1 < -3.141593 != NAN(fVar1)) {
      fVar1 = fVar1 + 6.283185;
    }
  } else {
    fVar1 = fVar1 - 6.283185;
  }
  fVar1 = Mod(fVar1 * param_3 + param_1, -3.141593, 3.141593);
  return fVar1;
}

/* public: static int __cdecl GmFunc::CastCeil(float) */

int __cdecl GmFunc::CastCeil(float param_1)

{
  return (int)ROUND(param_1 + 0.5);
}

/* public: static int __cdecl GmFunc::CastFloor(float) */

int __cdecl GmFunc::CastFloor(float param_1)

{
  return (int)ROUND(param_1 - 0.5);
}

/* public: static float __cdecl GmFunc::ClampReal(float,float,float) */

float __cdecl GmFunc::ClampReal(float param_1, float param_2, float param_3)

{
  if ((param_2 < param_1) &&
      (param_2 = param_3, param_3 < param_1 == (param_3 == param_1))) {
    return param_1;
  }
  return param_2;
}

/* public: static void __cdecl GmFunc::ComputeSplineBSpline(float,class GmVec3
 * *,class GmVec3 &) */

void __cdecl GmFunc::ComputeSplineBSpline(float param_1, GmVec3 *param_2,
                                          GmVec3 *param_3)

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

  fVar1 = *(float *)(param_2 + 0x18);
  fVar2 = *(float *)param_2;
  fVar3 = *(float *)(param_2 + 0x1c);
  fVar4 = *(float *)(param_2 + 4);
  fVar5 = *(float *)(param_2 + 0x20);
  fVar6 = *(float *)(param_2 + 8);
  fVar7 = *(float *)(param_2 + 0x24);
  fVar8 = *(float *)(param_2 + 0xc);
  fVar9 = *(float *)(param_2 + 0x28);
  fVar10 = *(float *)(param_2 + 0x10);
  fVar11 = *(float *)(param_2 + 0x2c);
  fVar12 = *(float *)(param_2 + 0x14);
  fVar17 = param_1 * param_1;
  fVar15 = fVar17 * param_1;
  fVar13 = ((fVar15 + fVar15) - fVar17 * 3.0) + 1.0;
  *(float *)param_3 = fVar13 * *(float *)(param_2 + 0xc);
  *(float *)(param_3 + 4) = *(float *)(param_2 + 0x10) * fVar13;
  *(float *)(param_3 + 8) = fVar13 * *(float *)(param_2 + 0x14);
  fVar16 = fVar17 * 3.0 - (fVar15 + fVar15);
  fVar13 = *(float *)(param_2 + 0x1c);
  fVar14 = *(float *)(param_2 + 0x20);
  *(float *)param_3 = *(float *)param_3 + fVar16 * *(float *)(param_2 + 0x18);
  *(float *)(param_3 + 4) = *(float *)(param_3 + 4) + fVar13 * fVar16;
  *(float *)(param_3 + 8) = *(float *)(param_3 + 8) + fVar16 * fVar14;
  fVar13 = (fVar15 - (fVar17 + fVar17)) + param_1;
  *(float *)param_3 = *(float *)param_3 + fVar13 * (fVar1 - fVar2) * 0.5;
  *(float *)(param_3 + 4) =
      *(float *)(param_3 + 4) + fVar13 * (fVar3 - fVar4) * 0.5;
  *(float *)(param_3 + 8) =
      *(float *)(param_3 + 8) + fVar13 * (fVar5 - fVar6) * 0.5;
  fVar15 = fVar15 - fVar17;
  *(float *)param_3 = *(float *)param_3 + fVar15 * (fVar7 - fVar8) * 0.5;
  *(float *)(param_3 + 4) =
      *(float *)(param_3 + 4) + (fVar9 - fVar10) * 0.5 * fVar15;
  *(float *)(param_3 + 8) =
      *(float *)(param_3 + 8) + fVar15 * (fVar11 - fVar12) * 0.5;
  return;
}

/* public: static void __cdecl GmFunc::ComputeSplineTangentBSpline(float,class
   GmVec3 *,class GmVec3
   &) */

void __cdecl GmFunc::ComputeSplineTangentBSpline(float param_1, GmVec3 *param_2,
                                                 GmVec3 *param_3)

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

  fVar1 = *(float *)(param_2 + 0x18);
  fVar2 = *(float *)param_2;
  fVar3 = *(float *)(param_2 + 0x1c);
  fVar4 = *(float *)(param_2 + 4);
  fVar5 = *(float *)(param_2 + 0x20);
  fVar6 = *(float *)(param_2 + 8);
  fVar7 = *(float *)(param_2 + 0x24);
  fVar8 = *(float *)(param_2 + 0xc);
  fVar9 = *(float *)(param_2 + 0x28);
  fVar10 = *(float *)(param_2 + 0x10);
  fVar11 = *(float *)(param_2 + 0x2c);
  fVar12 = *(float *)(param_2 + 0x14);
  fVar15 = param_1 * param_1 * 6.0;
  fVar13 = fVar15 - param_1 * 6.0;
  *(float *)param_3 = fVar13 * *(float *)(param_2 + 0xc);
  *(float *)(param_3 + 4) = *(float *)(param_2 + 0x10) * fVar13;
  *(float *)(param_3 + 8) = fVar13 * *(float *)(param_2 + 0x14);
  fVar15 = param_1 * 6.0 - fVar15;
  fVar13 = *(float *)(param_2 + 0x1c);
  fVar14 = *(float *)(param_2 + 0x20);
  *(float *)param_3 = *(float *)param_3 + fVar15 * *(float *)(param_2 + 0x18);
  *(float *)(param_3 + 4) = *(float *)(param_3 + 4) + fVar13 * fVar15;
  *(float *)(param_3 + 8) = *(float *)(param_3 + 8) + fVar15 * fVar14;
  fVar13 = (param_1 * param_1 * 3.0 - param_1 * 4.0) + 1.0;
  *(float *)param_3 = *(float *)param_3 + fVar13 * (fVar1 - fVar2) * 0.5;
  *(float *)(param_3 + 4) =
      *(float *)(param_3 + 4) + fVar13 * (fVar3 - fVar4) * 0.5;
  *(float *)(param_3 + 8) =
      *(float *)(param_3 + 8) + fVar13 * (fVar5 - fVar6) * 0.5;
  fVar1 = param_1 * 3.0 - (param_1 + param_1);
  *(float *)param_3 = *(float *)param_3 + fVar1 * (fVar7 - fVar8) * 0.5;
  *(float *)(param_3 + 4) =
      *(float *)(param_3 + 4) + (fVar9 - fVar10) * 0.5 * fVar1;
  *(float *)(param_3 + 8) =
      *(float *)(param_3 + 8) + fVar1 * (fVar11 - fVar12) * 0.5;
  return;
}

/* public: static unsigned long __cdecl GmFunc::Div(float &,float,float) */

ulong __cdecl GmFunc::Div(float *param_1, float param_2, float param_3)

{
  if (ABS(param_2) * 1e-05 < ABS(param_3) !=
      (NAN(ABS(param_2) * 1e-05) || NAN(ABS(param_3)))) {
    *param_1 = param_2 / param_3;
    return 1;
  }
  return 0;
}

/* public: static float __cdecl GmFunc::Frac(float) */

float __cdecl GmFunc::Frac(float param_1)

{
  double dVar1;
  undefined8 local_8;

  dVar1 = _modf((double)param_1, (double *)&local_8);
  local_8._0_4_ = 0;
  local_8._4_4_ = 0x3f800000;
  return *(float *)((int)&local_8 + ((int)(float)dVar1 >> 0x1f) * -4) +
         (float)dVar1;
}

/* public: static unsigned long __cdecl GmFunc::GetMinPowerOfTwo(unsigned long)
 */

ulong __cdecl GmFunc::GetMinPowerOfTwo(ulong param_1)

{
  int iVar1;

  iVar1 = 0x1f;
  if (param_1 != 0) {
    for (; param_1 >> iVar1 == 0; iVar1 = iVar1 + -1) {
    }
  }
  if (1 << ((byte)iVar1 & 0x1f) != param_1) {
    param_1 = 1 << ((byte)iVar1 + 1 & 0x1f);
  }
  return param_1;
}

/* public: static int __cdecl GmFunc::IsANumber(float) */

int __cdecl GmFunc::IsANumber(float param_1)

{
  if ((param_1 <= 0.0) && (param_1 < 0.0 == (param_1 == 0.0))) {
    return 0;
  }
  return 1;
}

/* public: static unsigned long __cdecl GmFunc::IsPowerOfTwo(unsigned long) */

ulong __cdecl GmFunc::IsPowerOfTwo(ulong param_1)

{
  int iVar1;
  ulong uVar2;

  uVar2 = 0;
  iVar1 = 0;
  if (param_1 != 0) {
    for (; (param_1 >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
    }
  }
  if (param_1 != 0) {
    uVar2 = (ulong)(param_1 >> ((char)iVar1 + 1U & 0x1f) == 0);
  }
  return uVar2;
}

/* public: static unsigned long __cdecl GmFunc::IsZero(float,float) */

ulong __cdecl GmFunc::IsZero(float param_1, float param_2)

{
  if (ABS(param_1) < param_2) {
    return 1;
  }
  return 0;
}

/* public: static float __cdecl GmFunc::Max(float,float) */

float __cdecl GmFunc::Max(float param_1, float param_2)

{
  if (param_2 < param_1 != (param_2 == param_1)) {
    return param_1;
  }
  return param_2;
}

/* public: static float __cdecl GmFunc::Min(float,float) */

float __cdecl GmFunc::Min(float param_1, float param_2)

{
  if (param_1 <= param_2) {
    return param_1;
  }
  return param_2;
}

/* public: static unsigned long __cdecl GmFunc::Min(unsigned long,unsigned long)
 */

ulong __cdecl GmFunc::Min(ulong param_1, ulong param_2)

{
  if (param_2 < param_1) {
    param_1 = param_2;
  }
  return param_1;
}

/* public: static unsigned long __cdecl GmFunc::Mod(int,int) */

ulong __cdecl GmFunc::Mod(int param_1, int param_2)

{
  ulong uVar1;

  uVar1 = param_1 % param_2;
  if ((int)uVar1 < 0) {
    uVar1 = uVar1 + param_2;
  }
  return uVar1;
}

/* public: static float __cdecl GmFunc::Mod(float,float,float) */

float __cdecl GmFunc::Mod(float param_1, float param_2, float param_3)

{
  float fVar1;
  undefined4 in_ECX;
  float10 fVar2;

  if ((param_2 < param_1 != (param_2 == param_1)) && (param_1 < param_3)) {
    return param_1;
  }
  fVar2 = (float10)__CIfmod(in_ECX);
  fVar1 = (float)fVar2;
  if (fVar1 < 0.0 != NAN(fVar1)) {
    fVar1 = fVar1 + (param_3 - param_2);
  }
  return fVar1 + param_2;
}

/* public: static float __cdecl GmFunc::Nat16ToReal(unsigned short,float,float)
 */

float __cdecl GmFunc::Nat16ToReal(ushort param_1, float param_2, float param_3)

{
  return param_2 + ((float)(uint)param_1 / 65535.0) * (param_3 - param_2);
}

/* public: static unsigned long __cdecl GmFunc::RandNat(unsigned long,unsigned
 * long) */

ulong __cdecl GmFunc::RandNat(ulong param_1, ulong param_2)

{
  double dVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  ulong local_8;

  iVar3 = _rand();
  iVar4 = (param_2 - param_1) + 1;
  dVar2 = (double)iVar4;
  if (iVar4 < 0) {
    dVar2 = dVar2 + 4294967296.0;
  }
  dVar1 = (double)param_1;
  if ((int)param_1 < 0) {
    dVar1 = dVar1 + 4294967296.0;
  }
  local_8 =
      (ulong)(longlong)ROUND(dVar1 + dVar2 * (double)iVar3 * 3.0517578125e-05);
  return local_8;
}

/* public: static float __cdecl GmFunc::RandReal(float,float) */

float __cdecl GmFunc::RandReal(float param_1, float param_2)

{
  int iVar1;

  iVar1 = _rand();
  return (param_2 - param_1) * ((float)iVar1 / 32767.0) + param_1;
}

/* public: static void __cdecl GmFunc::ReadUnitVec3(class CClassicBuffer &,class
 * GmVec3 &) */

void __cdecl GmFunc::ReadUnitVec3(CClassicBuffer *param_1, GmVec3 *param_2)

{
  CClassicBuffer *pCVar1;
  float10 *extraout_ECX;
  float10 *extraout_ECX_00;
  float10 *extraout_ECX_01;
  float10 *extraout_ECX_02;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  float10 fVar2;
  float10 fVar3;
  CClassicBuffer **ppCVar4;
  float *pfStack_8;
  char acStack_4[4];

  pCVar1 = param_1;
  ppCVar4 = &param_1;
  (**(code **)(*(int *)param_1 + 4))(ppCVar4, 1);
  (**(code **)(*(int *)pCVar1 + 4))(
      acStack_4, 1, ppCVar4, ((float)(int)acStack_4[0] * 3.141593) / 127.0);
  fVar2 = (float10)__CIcos(extraout_ECX, extraout_EDX);
  fVar3 = (float10)__CIcos(extraout_ECX_00, extraout_EDX_00);
  *pfStack_8 = (float)fVar3 * (float)fVar2;
  fVar3 = (float10)__CIsin(extraout_ECX_01, extraout_EDX_01);
  pfStack_8[1] = (float)fVar3 * (float)fVar2;
  fVar2 = (float10)__CIsin(extraout_ECX_02, extraout_EDX_02);
  pfStack_8[2] = (float)fVar2;
  return;
}

/* public: static unsigned short __cdecl GmFunc::RealToNat16(float,float,float)
 */

ushort __cdecl GmFunc::RealToNat16(float param_1, float param_2, float param_3)

{
  float fVar1;

  fVar1 = ((param_1 - param_2) / (param_3 - param_2)) * 65535.0;
  if (fVar1 < 0.0 == (fVar1 == 0.0)) {
    if (65535.0 <= fVar1) {
      fVar1 = 65535.0;
    }
  } else {
    fVar1 = 0.0;
  }
  param_2._0_2_ = (ushort)(int)ROUND(fVar1);
  return param_2._0_2_;
}

/* public: static unsigned char __cdecl GmFunc::RealToNat7(float,float,float) */

uchar __cdecl GmFunc::RealToNat7(float param_1, float param_2, float param_3)

{
  float fVar1;

  fVar1 = ((param_1 - param_2) / (param_3 - param_2)) * 127.0;
  if (fVar1 < 0.0 == (fVar1 == 0.0)) {
    if (127.0 <= fVar1) {
      fVar1 = 127.0;
    }
  } else {
    fVar1 = 0.0;
  }
  param_2._0_1_ = (uchar)(int)ROUND(fVar1);
  return param_2._0_1_;
}

/* public: static unsigned char __cdecl GmFunc::RealToNat8(float,float,float) */

uchar __cdecl GmFunc::RealToNat8(float param_1, float param_2, float param_3)

{
  float fVar1;

  fVar1 = ((param_1 - param_2) / (param_3 - param_2)) * 255.0;
  if (fVar1 < 0.0 == (fVar1 == 0.0)) {
    if (255.0 <= fVar1) {
      fVar1 = 255.0;
    }
  } else {
    fVar1 = 0.0;
  }
  param_2._0_1_ = (uchar)(int)ROUND(fVar1);
  return param_2._0_1_;
}

/* public: static float __cdecl GmFunc::Saturate(float) */

float __cdecl GmFunc::Saturate(float param_1)

{
  float fVar1;

  fVar1 = 0.0;
  if ((param_1 < 0.0 == (param_1 == 0.0)) &&
      (fVar1 = param_1, 1.0 < param_1 != (param_1 == 1.0))) {
    return 1.0;
  }
  return fVar1;
}

/* public: static void __cdecl GmFunc::SetRandSeed(unsigned long) */

void __cdecl GmFunc::SetRandSeed(ulong param_1)

{
  __time64_t _Var1;

  if (param_1 == 0xffffffff) {
    _Var1 = __time64((__time64_t *)0x0);
    _srand((uint)_Var1 ^ 0xbb40e64e);
    return;
  }
  _srand(param_1);
  return;
}

/* public: static float __cdecl GmFunc::Sign(float) */

float __cdecl GmFunc::Sign(float param_1)

{
  if (-1 < (int)param_1) {
    return 1.0;
  }
  return -1.0;
}

/* public: static float __cdecl GmFunc::Sign(float,float) */

float __cdecl GmFunc::Sign(float param_1, float param_2)

{
  if (0.0 < param_1 == (param_1 == 0.0)) {
    param_2 = -param_2;
  }
  return param_2;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: static unsigned long __cdecl GmFunc::SolveLinearSystem2(float &,float
   &,float,float,float,float,float,float) */

ulong __cdecl GmFunc::SolveLinearSystem2(float *param_1, float *param_2,
                                         float param_3, float param_4,
                                         float param_5, float param_6,
                                         float param_7, float param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;

  fVar2 = param_7 * param_3 - param_6 * param_4;
  fVar5 = ABS(fVar2) * _DAT_00d14af8;
  fVar3 = param_5 * param_7 - param_8 * param_4;
  fVar1 = param_3 * param_8 - param_5 * param_6;
  fVar4 = ABS(fVar3);
  if (fVar4 < fVar5 != (NAN(fVar4) || NAN(fVar5))) {
    fVar4 = ABS(fVar1);
    if (fVar4 < fVar5 != (NAN(fVar4) || NAN(fVar5))) {
      fVar2 = fVar2 / 1.0;
      *param_1 = fVar2 * fVar3;
      *param_2 = fVar1 * fVar2;
      return 1;
    }
  }
  return 0;
}

/* public: static void __cdecl GmFunc::WriteUnitVec3(class CClassicBuffer
 * &,class GmVec3 const &) */

void __cdecl GmFunc::WriteUnitVec3(CClassicBuffer *param_1, GmVec3 *param_2)

{
  float fVar1;
  GmVec3 *pGVar2;
  GmVec3 *pGVar3;
  float10 *extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar4;
  undefined4 extraout_ECX_02;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar5;
  undefined4 extraout_EDX_02;
  float10 fVar6;
  ulonglong uVar7;

  pGVar3 = param_2;
  fVar6 = (float10)__CIasin();
  param_2 = (GmVec3 *)(float)fVar6;
  fVar6 = (float10)__CIcos(extraout_ECX, extraout_EDX);
  fVar1 = (float)fVar6;
  if (ABS(fVar1) < 1e-05 == NAN(ABS(fVar1))) {
    pGVar2 = (GmVec3 *)(*(float *)pGVar3 / fVar1);
    param_2 = (GmVec3 *)0xbf800000;
    if (((float)pGVar2 < -1.0 == ((float)pGVar2 == -1.0)) &&
        (param_2 = pGVar2, 1.0 < (float)pGVar2 != ((float)pGVar2 == 1.0))) {
      param_2 = (GmVec3 *)&DAT_3f800000;
    }
    fVar6 = (float10)__CIacos();
    param_2 = (GmVec3 *)(float)fVar6;
    fVar1 = *(float *)(pGVar3 + 4) * fVar1;
    uVar4 = extraout_ECX_01;
    uVar5 = extraout_EDX_01;
    if (fVar1 < 0.0 != NAN(fVar1)) {
      param_2 = (GmVec3 *)-(float)param_2;
    }
  } else {
    param_2 = (GmVec3 *)0x0;
    uVar4 = extraout_ECX_00;
    uVar5 = extraout_EDX_00;
  }
  uVar7 = __ftol2_sse(uVar4, uVar5);
  param_2 = (GmVec3 *)CONCAT31(param_2._1_3_, (char)uVar7);
  (**(code **)(*(int *)param_1 + 8))(&param_2, 1);
  __ftol2_sse(extraout_ECX_02, extraout_EDX_02);
  (**(code **)(*(int *)param_1 + 8))(&stack0x00000000, 1);
  return;
}
