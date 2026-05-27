// Class implementation: GmVec2

// =================================================
// Function: GmVec2::ArchiveGmVec2
// =================================================
void __thiscall GmVec2::ArchiveGmVec2(void *this,GmVec2 *param_1,CClassicArchive *param_2)
{
{
  ulong unaff_ESI;
  ulong unaff_EDI;
  
  CClassicArchive::DoReal((CClassicArchive *)param_1,this,(float *)0x1,unaff_EDI);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 4),(float *)0x1,unaff_ESI);
  return;
}
}

// =================================================
// Function: GmVec2::GetLength
// =================================================
float __thiscall GmVec2::GetLength(void *this,CPlugFileSnd *param_1)
{
{
  float10 fVar1;
  
  fVar1 = (float10)func_0x009c1b40(*(float *)this * *(float *)this +
                                   *(float *)((int)this + 4) * *(float *)((int)this + 4));
  return (float)fVar1;
}
}

// =================================================
// Function: GmVec2::IsInTriangle
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __cdecl
GmVec2::IsInTriangle
          (GmVec2 *param_1,GmVec2 *param_2,GmVec2 *param_3,GmVec2 *param_4,float *param_5,
          float *param_6,int *param_7)
{
{
  float fVar1;
  ulong uVar2;
  
  uVar2 = GmFunc::SolveLinearSystem2
                    (param_5,param_6,*(float *)param_2 - *(float *)param_1,
                     *(float *)param_3 - *(float *)param_1,*(float *)param_4 - *(float *)param_1,
                     *(float *)(param_2 + 4) - *(float *)(param_1 + 4),
                     *(float *)(param_3 + 4) - *(float *)(param_1 + 4),
                     *(float *)(param_4 + 4) - *(float *)(param_1 + 4));
  if (uVar2 == 0) {
    if (param_7 != (int *)0x0) {
      *param_7 = 0;
      return 0;
    }
  }
  else {
    if (param_7 != (int *)0x0) {
      *param_7 = 1;
    }
    fVar1 = *param_5;
    if (((!NAN(fVar1) && 0.0 < fVar1 != (fVar1 == 0.0)) &&
        (fVar1 = *param_6, !NAN(fVar1) && 0.0 < fVar1 != (fVar1 == 0.0))) &&
       (*param_5 + *param_6 < (float)_DAT_00b2c188 != (*param_5 + *param_6 == (float)_DAT_00b2c188))
       ) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: GmVec2::IsNearlyEqual
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall GmVec2::IsNearlyEqual(void *this,GmVec2 *param_1,GmVec2 *param_2)
{
{
  float fVar1;
  
  fVar1 = *(float *)((int)this + 4) - *(float *)(param_1 + 4);
  if (fVar1 * fVar1 + (*(float *)this - *(float *)param_1) * (*(float *)this - *(float *)param_1) <
      _DAT_00d1a968) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmVec2::Mult
// =================================================
void __thiscall GmVec2::Mult(void *this,GmIso3 *param_1,GmIso3 *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *(float *)(param_1 + 8);
  fVar2 = *(float *)this;
  fVar3 = *(float *)(param_1 + 0xc);
  *(float *)this =
       *(float *)param_1 * *(float *)this + *(float *)(param_1 + 4) * *(float *)((int)this + 4);
  *(float *)((int)this + 4) = fVar3 * *(float *)((int)this + 4) + fVar1 * fVar2;
  return;
}
}

// =================================================
// Function: GmVec2::Normalize
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmVec2::Normalize(void *this,GmQuat *param_1)
{
{
  float10 fVar1;
  
  if (_DAT_00ccfe00 <
      *(float *)this * *(float *)this + *(float *)((int)this + 4) * *(float *)((int)this + 4)) {
    fVar1 = (float10)func_0x009c1b40();
    *(float *)this = (1.0 / (float)fVar1) * *(float *)this;
    *(float *)((int)this + 4) = (1.0 / (float)fVar1) * *(float *)((int)this + 4);
    return;
  }
  return;
}
}

// =================================================
// Function: GmVec2::SetBlend
// =================================================
void __thiscall
GmVec2::SetBlend(void *this,SParam *param_1,SParam *param_2,SParam *param_3,float param_4)
{
{
  float fVar1;
  float fVar2;
  
  *(float *)this = *(float *)param_2 - *(float *)param_1;
  *(float *)((int)this + 4) = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  fVar1 = *(float *)this;
  *(float *)this = (float)param_3 * fVar1;
  fVar2 = *(float *)((int)this + 4) * (float)param_3;
  *(float *)((int)this + 4) = fVar2;
  *(float *)this = *(float *)param_1 + (float)param_3 * fVar1;
  *(float *)((int)this + 4) = fVar2 + *(float *)(param_1 + 4);
  return;
}
}

// =================================================
// Function: GmVec2::SetBlendTri
// =================================================
void __thiscall
GmVec2::SetBlendTri(void *this,GmVec2 *param_1,GmVec2 *param_2,GmVec2 *param_3,GmVec2 *param_4,
                   float param_5,float param_6)
{
{
  float fVar1;
  
  fVar1 = (1.0 - (float)param_4) - param_5;
  *(float *)this = fVar1 * *(float *)param_1;
  *(float *)((int)this + 4) = fVar1 * *(float *)(param_1 + 4);
  fVar1 = *(float *)(param_2 + 4);
  *(float *)this = *(float *)this + *(float *)param_2 * (float)param_4;
  *(float *)((int)this + 4) = *(float *)((int)this + 4) + fVar1 * (float)param_4;
  fVar1 = *(float *)(param_3 + 4);
  *(float *)this = *(float *)this + *(float *)param_3 * param_5;
  *(float *)((int)this + 4) = *(float *)((int)this + 4) + param_5 * fVar1;
  return;
}
}

// =================================================
// Function: GmVec2::SetMultInverse
// =================================================
void __thiscall GmVec2::SetMultInverse(void *this,GmVec2 *param_1,GmVec2 *param_2,GmIso3 *param_3)
{
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
  *(float *)this = *(float *)param_2 * (fVar1 - fVar2) + *(float *)(param_2 + 8) * (fVar3 - fVar4);
  *(float *)((int)this + 4) = fVar6 * (fVar3 - fVar4) + fVar5 * (fVar1 - fVar2);
  return;
}
}

