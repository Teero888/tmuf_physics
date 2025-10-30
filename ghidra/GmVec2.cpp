
/* public: void __thiscall GmVec2::ArchiveGmVec2(class CClassicArchive &) */

void __thiscall GmVec2::ArchiveGmVec2(GmVec2 *this, CClassicArchive *param_1)

{
  CClassicArchive::DoReal(param_1, (float *)this, 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 4), 1);
  return;
}

/* public: float __thiscall GmVec2::GetLength(void)const  */

float __thiscall GmVec2::GetLength(GmVec2 *this)

{
  float10 fVar1;

  fVar1 = (float10)__CIsqrt();
  return (float)fVar1;
}

/* public: static unsigned long __cdecl GmVec2::IsInTriangle(class GmVec2 const
   &,class GmVec2 const
   &,class GmVec2 const &,class GmVec2 const &,float &,float &,int *) */

ulong __cdecl GmVec2::IsInTriangle(GmVec2 *param_1, GmVec2 *param_2,
                                   GmVec2 *param_3, GmVec2 *param_4,
                                   float *param_5, float *param_6, int *param_7)

{
  ulong uVar1;

  uVar1 = GmFunc::SolveLinearSystem2(
      param_5, param_6, *(float *)param_2 - *(float *)param_1,
      *(float *)param_3 - *(float *)param_1,
      *(float *)param_4 - *(float *)param_1,
      *(float *)(param_2 + 4) - *(float *)(param_1 + 4),
      *(float *)(param_3 + 4) - *(float *)(param_1 + 4),
      *(float *)(param_4 + 4) - *(float *)(param_1 + 4));
  if (uVar1 == 0) {
    if (param_7 != (int *)0x0) {
      *param_7 = 0;
      return 0;
    }
  } else {
    if (param_7 != (int *)0x0) {
      *param_7 = 1;
    }
    if (((0.0 < *param_5 != (*param_5 == 0.0)) &&
         (0.0 < *param_6 != (*param_6 == 0.0))) &&
        (*param_5 + *param_6 < 1.0 != (*param_5 + *param_6 == 1.0))) {
      return 1;
    }
  }
  return 0;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: unsigned long __thiscall GmVec2::IsNearlyEqual(class GmVec2 const
 * &)const  */

ulong __thiscall GmVec2::IsNearlyEqual(GmVec2 *this, GmVec2 *param_1)

{
  if ((*(float *)(this + 4) - *(float *)(param_1 + 4)) *
              (*(float *)(this + 4) - *(float *)(param_1 + 4)) +
          (*(float *)this - *(float *)param_1) *
              (*(float *)this - *(float *)param_1) <
      _DAT_00d1a968) {
    return 1;
  }
  return 0;
}

/* public: void __thiscall GmVec2::Mult(class GmMat2 const &) */

void __thiscall GmVec2::Mult(GmVec2 *this, GmMat2 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;

  fVar1 = *(float *)(param_1 + 8);
  fVar2 = *(float *)this;
  fVar3 = *(float *)(param_1 + 0xc);
  *(float *)this = *(float *)param_1 * *(float *)this +
                   *(float *)(param_1 + 4) * *(float *)(this + 4);
  *(float *)(this + 4) = fVar3 * *(float *)(this + 4) + fVar1 * fVar2;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: unsigned long __thiscall GmVec2::Normalize(void) */

ulong __thiscall GmVec2::Normalize(GmVec2 *this)

{
  float fVar1;
  float10 fVar2;

  fVar1 = *(float *)this * *(float *)this +
          *(float *)(this + 4) * *(float *)(this + 4);
  if (_DAT_00ccfe00 < fVar1 != (NAN(_DAT_00ccfe00) || NAN(fVar1))) {
    fVar2 = (float10)__CIsqrt();
    *(float *)this = (1.0 / (float)fVar2) * *(float *)this;
    *(float *)(this + 4) = (1.0 / (float)fVar2) * *(float *)(this + 4);
    return 1;
  }
  return 0;
}

/* public: float const & __thiscall GmVec2::operator[](unsigned long)const  */

float *__thiscall GmVec2::operator[](GmVec2 *this, ulong param_1)

{
  return (float *)(this + param_1 * 4);
}

/* public: void __thiscall GmVec2::SetBlend(class GmVec2 const &,class GmVec2
 * const &,float) */

void __thiscall GmVec2::SetBlend(GmVec2 *this, GmVec2 *param_1, GmVec2 *param_2,
                                 float param_3)

{
  float fVar1;
  float fVar2;

  *(float *)this = *(float *)param_2 - *(float *)param_1;
  *(float *)(this + 4) = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  fVar1 = *(float *)this;
  *(float *)this = param_3 * fVar1;
  fVar2 = *(float *)(this + 4);
  *(float *)(this + 4) = fVar2 * param_3;
  *(float *)this = *(float *)param_1 + param_3 * fVar1;
  *(float *)(this + 4) = fVar2 * param_3 + *(float *)(param_1 + 4);
  return;
}

/* public: void __thiscall GmVec2::SetBlendTri(class GmVec2 const &,class GmVec2
   const &,class GmVec2 const &,float,float) */

void __thiscall GmVec2::SetBlendTri(GmVec2 *this, GmVec2 *param_1,
                                    GmVec2 *param_2, GmVec2 *param_3,
                                    float param_4, float param_5)

{
  float fVar1;

  fVar1 = (1.0 - param_4) - param_5;
  *(float *)this = fVar1 * *(float *)param_1;
  *(float *)(this + 4) = fVar1 * *(float *)(param_1 + 4);
  fVar1 = *(float *)(param_2 + 4);
  *(float *)this = *(float *)this + *(float *)param_2 * param_4;
  *(float *)(this + 4) = *(float *)(this + 4) + fVar1 * param_4;
  fVar1 = *(float *)(param_3 + 4);
  *(float *)this = *(float *)this + *(float *)param_3 * param_5;
  *(float *)(this + 4) = *(float *)(this + 4) + param_5 * fVar1;
  return;
}

/* public: void __thiscall GmVec2::SetMultInverse(class GmVec2 const &,class
 * GmIso3 const &) */

void __thiscall GmVec2::SetMultInverse(GmVec2 *this, GmVec2 *param_1,
                                       GmIso3 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;

  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_2 + 0x10);
  fVar3 = *(float *)(param_1 + 4);
  fVar4 = *(float *)(param_2 + 0x14);
  fVar5 = *(float *)(param_2 + 4);
  fVar6 = *(float *)(param_2 + 0xc);
  *(float *)this = *(float *)param_2 * (fVar1 - fVar2) +
                   *(float *)(param_2 + 8) * (fVar3 - fVar4);
  *(float *)(this + 4) = fVar6 * (fVar3 - fVar4) + fVar5 * (fVar1 - fVar2);
  return;
}
