// Class implementation: GmFunc

// =================================================
// Function: GmFunc::AreNearlyEqual
// =================================================
ulong __cdecl GmFunc::AreNearlyEqual(float param_1,float param_2,float param_3)
{
{
  if (ABS(param_1 - param_2) < param_3) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmFunc::AsinSafe
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __cdecl GmFunc::AsinSafe(float param_1)
{
{
  float10 fVar1;
  
  if (param_1 < (float)_DAT_00b36100) {
    return _DAT_00b36108;
  }
  if ((float)_DAT_00b360f8 < param_1) {
    return _DAT_00b360f4;
  }
  fVar1 = (float10)func_0x009c1d90();
  return (float)fVar1;
}
}

// =================================================
// Function: GmFunc::ClampReal
// =================================================
float __cdecl GmFunc::ClampReal(float param_1,float param_2,float param_3)
{
{
  if ((param_2 < param_1) && (param_2 = param_3, param_3 < param_1 == (param_3 == param_1))) {
    return param_1;
  }
  return param_2;
}
}

// =================================================
// Function: GmFunc::Div
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __cdecl GmFunc::Div(float *param_1,float param_2,float param_3)
{
{
  if (ABS(param_2) * (float)_DAT_00b36288 < ABS(param_3)) {
    *param_1 = param_2 / param_3;
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmFunc::IsANumber
// =================================================
int __cdecl GmFunc::IsANumber(float param_1)
{
{
  if ((param_1 <= 0.0) && (param_1 < 0.0 == (param_1 == 0.0))) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: GmFunc::IsZero
// =================================================
ulong __cdecl GmFunc::IsZero(float param_1,float param_2)
{
{
  if (ABS(param_1) < param_2) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmFunc::Max
// =================================================
void __thiscall
GmFunc::Max(void *this,GmVector3<unsigned_long> *param_1,GmVector3<unsigned_long> *param_2)
{
{
  if ((float)param_2 < (float)param_1 != ((float)param_2 == (float)param_1)) {
    return;
  }
  return;
}
}

// =================================================
// Function: GmFunc::Min
// =================================================
void __thiscall
GmFunc::Min(void *this,GmVector3<unsigned_long> *param_1,GmVector3<unsigned_long> *param_2)
{
{
  return;
}
}

// =================================================
// Function: GmFunc::Mod
// =================================================
float __cdecl GmFunc::Mod(float param_1,float param_2,float param_3)
{
{
  float fVar1;
  float10 extraout_ST0;
  
  if ((param_2 < param_1 != (param_2 == param_1)) && (param_1 < param_3)) {
    return param_1;
  }
  __CIfmod();
  fVar1 = (float)extraout_ST0;
  if (fVar1 < 0.0) {
    fVar1 = fVar1 + (param_3 - param_2);
  }
  return fVar1 + param_2;
}
}

// =================================================
// Function: GmFunc::RandReal
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __cdecl GmFunc::RandReal(float param_1,float param_2)
{
{
  int iVar1;
  
  iVar1 = _rand();
  return (param_2 - param_1) * ((float)iVar1 / (float)_DAT_00b530f8) + param_1;
}
}

// =================================================
// Function: GmFunc::ReadUnitVec3
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl GmFunc::ReadUnitVec3(CClassicBuffer *param_1,GmVec3 *param_2)
{
{
  CClassicBuffer *pCVar1;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  CClassicBuffer **ppCVar2;
  float *pfStack_8;
  char acStack_4 [4];
  
  pCVar1 = param_1;
  ppCVar2 = &param_1;
  (**(code **)(*(int *)param_1 + 4))(ppCVar2,1);
  (**(code **)(*(int *)pCVar1 + 4))
            (acStack_4,1,ppCVar2,
             ((float)(int)acStack_4[0] * (float)_DAT_00b36110) / (float)_DAT_00b55d48);
  __CIcos();
  __CIcos();
  *pfStack_8 = (float)extraout_ST0_00 * (float)extraout_ST0;
  __CIsin();
  pfStack_8[1] = (float)extraout_ST0_01 * (float)extraout_ST0;
  __CIsin();
  pfStack_8[2] = (float)extraout_ST0_02;
  return;
}
}

// =================================================
// Function: GmFunc::RealToNat16
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort __cdecl GmFunc::RealToNat16(float param_1,float param_2,float param_3)
{
{
  float fVar1;
  float fVar2;
  
  fVar1 = ((param_1 - param_2) / (param_3 - param_2)) * (float)_DAT_00b52a58;
  fVar2 = 0.0;
  if ((fVar1 < 0.0 == (fVar1 == 0.0)) && (fVar2 = fVar1, (float)_DAT_00b52a58 <= fVar1)) {
    fVar2 = _DAT_00b9f5d8;
  }
  param_2._0_2_ = (ushort)(int)ROUND(fVar2);
  return param_2._0_2_;
}
}

// =================================================
// Function: GmFunc::RealToNat7
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uchar __cdecl GmFunc::RealToNat7(float param_1,float param_2,float param_3)
{
{
  float fVar1;
  float fVar2;
  
  fVar1 = ((param_1 - param_2) / (param_3 - param_2)) * (float)_DAT_00b55d48;
  fVar2 = 0.0;
  if ((fVar1 < 0.0 == (fVar1 == 0.0)) && (fVar2 = fVar1, (float)_DAT_00b55d48 <= fVar1)) {
    fVar2 = _DAT_00b9f5d4;
  }
  param_2._0_1_ = (uchar)(int)ROUND(fVar2);
  return param_2._0_1_;
}
}

// =================================================
// Function: GmFunc::RealToNat8
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uchar __cdecl GmFunc::RealToNat8(float param_1,float param_2,float param_3)
{
{
  float fVar1;
  float fVar2;
  
  fVar1 = ((param_1 - param_2) / (param_3 - param_2)) * (float)_DAT_00b55d50;
  fVar2 = 0.0;
  if ((fVar1 < 0.0 == (fVar1 == 0.0)) && (fVar2 = fVar1, (float)_DAT_00b55d50 <= fVar1)) {
    fVar2 = _DAT_00b5e844;
  }
  param_2._0_1_ = (uchar)(int)ROUND(fVar2);
  return param_2._0_1_;
}
}

// =================================================
// Function: GmFunc::Saturate
// =================================================
void __thiscall GmFunc::Saturate(void *this,SParam *param_1)
{
{
  if (((float)param_1 < 0.0 == ((float)param_1 == 0.0)) &&
     (!NAN((float)param_1) && 1.0 < (float)param_1 != ((float)param_1 == 1.0))) {
    return;
  }
  return;
}
}

// =================================================
// Function: GmFunc::SetRandSeed
// =================================================
void __cdecl GmFunc::SetRandSeed(ulong param_1)
{
{
  if (param_1 == 0xffffffff) {
    __time64((__time64_t *)0x0);
    FUN_009c2270();
    return;
  }
  FUN_009c2270();
  return;
}
}

// =================================================
// Function: GmFunc::Sign
// =================================================
float __cdecl GmFunc::Sign(float param_1,float param_2)
{
{
  if (NAN(param_1) || 0.0 < param_1 == (param_1 == 0.0)) {
    param_2 = -param_2;
  }
  return param_2;
}
}

// =================================================
// Function: GmFunc::SolveLinearSystem2
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __cdecl
GmFunc::SolveLinearSystem2
          (float *param_1,float *param_2,float param_3,float param_4,float param_5,float param_6,
          float param_7,float param_8)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar2 = param_7 * param_3 - param_6 * param_4;
  fVar4 = ABS(fVar2) * _DAT_00d14af8;
  fVar3 = param_5 * param_7 - param_8 * param_4;
  fVar1 = param_3 * param_8 - param_5 * param_6;
  if (ABS(fVar3) < fVar4) {
    if (ABS(fVar1) < fVar4) {
      fVar2 = 1.0 / fVar2;
      *param_1 = fVar2 * fVar3;
      *param_2 = fVar1 * fVar2;
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: GmFunc::WriteUnitVec3
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl GmFunc::WriteUnitVec3(CClassicBuffer *param_1,GmVec3 *param_2)
{
{
  float fVar1;
  GmVec3 *pGVar2;
  GmVec3 *pGVar3;
  undefined1 extraout_AL;
  float10 fVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  pGVar3 = param_2;
  fVar4 = (float10)func_0x009c1d90();
  param_2 = (GmVec3 *)(float)fVar4;
  __CIcos();
  fVar1 = (float)extraout_ST0;
  if (_DAT_00bbd8e4 <= ABS(fVar1)) {
    pGVar2 = (GmVec3 *)(*(float *)pGVar3 / fVar1);
    param_2 = _DAT_00b2c060;
    if (((float)pGVar2 < (float)_DAT_00b2c060 == ((float)pGVar2 == (float)_DAT_00b2c060)) &&
       (param_2 = pGVar2, 1.0 < (float)pGVar2 != ((float)pGVar2 == 1.0))) {
      param_2 = (GmVec3 *)0x3f800000;
    }
    __CIacos();
    param_2 = (GmVec3 *)(float)extraout_ST0_00;
    if (*(float *)(pGVar3 + 4) * fVar1 < (float)_PTR_00b2c178) {
      param_2 = (GmVec3 *)-(float)param_2;
    }
  }
  else {
    param_2 = (GmVec3 *)0x0;
  }
  __ftol2_sse();
  param_2 = (GmVec3 *)CONCAT31(param_2._1_3_,extraout_AL);
  (**(code **)(*(int *)param_1 + 8))(&param_2,1);
  __ftol2_sse();
  (**(code **)(*(int *)param_1 + 8))(&stack0x00000000,1);
  return;
}
}

