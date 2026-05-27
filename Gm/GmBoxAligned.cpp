// Class implementation: GmBoxAligned

// =================================================
// Function: GmBoxAligned::ArchiveABox
// =================================================
void __thiscall GmBoxAligned::ArchiveABox(void *this,GmBoxAligned *param_1,CClassicArchive *param_2)
{
{
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  ulong in_stack_0000000c;
  
  CClassicArchive::DoReal((CClassicArchive *)param_1,this,(float *)0x1,unaff_EDI);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 4),(float *)0x1,unaff_ESI);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 8),(float *)0x1,
             unaff_retaddr);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0xc),(float *)0x1,
             (ulong)param_1);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x10),(float *)0x1,
             (ulong)param_2);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x14),(float *)0x1,
             in_stack_0000000c);
  return;
}
}

// =================================================
// Function: GmBoxAligned::ArchiveABoxOld1
// =================================================
void __thiscall
GmBoxAligned::ArchiveABoxOld1(void *this,GmBoxAligned *param_1,CClassicArchive *param_2)
{
{
  GmBoxAligned *this_00;
  ulong unaff_ESI;
  ulong unaff_EDI;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  GmVec3 *pGVar5;
  float local_4;
  
  this_00 = param_1;
  fVar4 = *(float *)this - *(float *)((int)this + 0xc);
  pGVar5 = (GmVec3 *)(*(float *)((int)this + 4) - *(float *)((int)this + 0x10));
  local_4 = *(float *)((int)this + 8) - *(float *)((int)this + 0x14);
  fVar1 = *(float *)((int)this + 0xc) + *(float *)this;
  fVar2 = *(float *)((int)this + 0x10) + *(float *)((int)this + 4);
  fVar3 = *(float *)((int)this + 0x14) + *(float *)((int)this + 8);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffff4,(float *)0x1,unaff_EDI);
  CClassicArchive::DoReal
            ((CClassicArchive *)this_00,(CClassicArchive *)&local_4,(float *)0x1,unaff_ESI);
  CClassicArchive::DoReal
            ((CClassicArchive *)this_00,(CClassicArchive *)&param_1,(float *)0x1,(ulong)fVar1);
  CClassicArchive::DoReal
            ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xfffffff4,(float *)0x1,
             (ulong)fVar2);
  CClassicArchive::DoReal
            ((CClassicArchive *)this_00,(CClassicArchive *)&local_4,(float *)0x1,(ulong)fVar3);
  CClassicArchive::DoReal
            ((CClassicArchive *)this_00,(CClassicArchive *)&param_1,(float *)0x1,(ulong)fVar4);
  SetMinMax(this,(GmBoxAligned *)&stack0x0000000c,(GmVec3 *)&stack0x00000000,pGVar5);
  return;
}
}

// =================================================
// Function: GmBoxAligned::GetDiag
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmBoxAligned::GetDiag(void *this,GmBoxAligned *param_1,GmVec3 *param_2)
{
{
  float fVar1;
  
  fVar1 = (float)_DAT_00b33a58;
  *(float *)param_1 = *(float *)((int)this + 0xc) * fVar1;
  *(float *)(param_1 + 4) = *(float *)((int)this + 0x10) * fVar1;
  *(float *)(param_1 + 8) = fVar1 * *(float *)((int)this + 0x14);
  return;
}
}

// =================================================
// Function: GmBoxAligned::GetMin
// =================================================
GmVec3 __thiscall GmBoxAligned::GetMin(void *this,GmBoxAligned *param_1)
{
{
  *(float *)param_1 = *(float *)this - *(float *)((int)this + 0xc);
  *(float *)(param_1 + 4) = *(float *)((int)this + 4) - *(float *)((int)this + 0x10);
  *(float *)(param_1 + 8) = *(float *)((int)this + 8) - *(float *)((int)this + 0x14);
  return SUB41(param_1,0);
}
}

// =================================================
// Function: GmBoxAligned::GetMinMax
// =================================================
void __thiscall
GmBoxAligned::GetMinMax(void *this,GmBoxAligned *param_1,GmVec3 *param_2,GmVec3 *param_3)
{
{
  *(float *)param_1 = *(float *)this - *(float *)((int)this + 0xc);
  *(float *)(param_1 + 4) = *(float *)((int)this + 4) - *(float *)((int)this + 0x10);
  *(float *)(param_1 + 8) = *(float *)((int)this + 8) - *(float *)((int)this + 0x14);
  *(float *)param_2 = *(float *)((int)this + 0xc) + *(float *)this;
  *(float *)(param_2 + 4) = *(float *)((int)this + 0x10) + *(float *)((int)this + 4);
  *(float *)(param_2 + 8) = *(float *)((int)this + 0x14) + *(float *)((int)this + 8);
  return;
}
}

// =================================================
// Function: GmBoxAligned::IsIncluded
// =================================================
int __thiscall GmBoxAligned::IsIncluded(void *this,GmBoxAligned *param_1,GmBoxAligned *param_2)
{
{
  float fVar1;
  float fVar2;
  GmVec3 GVar3;
  undefined3 extraout_var;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *(float *)this - *(float *)((int)this + 0xc);
  fVar2 = *(float *)((int)this + 4) - *(float *)((int)this + 0x10);
  local_4 = *(float *)((int)this + 8) - *(float *)((int)this + 0x14);
  if ((((*(float *)((int)this + 0x14) + *(float *)((int)this + 8) <=
         *(float *)(param_1 + 0x14) + *(float *)(param_1 + 8)) &&
       (*(float *)(param_1 + 8) - *(float *)(param_1 + 0x14) < local_4 !=
        (*(float *)(param_1 + 8) - *(float *)(param_1 + 0x14) == local_4))) &&
      (*(float *)((int)this + 0xc) + *(float *)this <= *(float *)(param_1 + 0xc) + *(float *)param_1
      )) && ((*(float *)param_1 - *(float *)(param_1 + 0xc) < local_c !=
              (*(float *)param_1 - *(float *)(param_1 + 0xc) == local_c) &&
             (*(float *)((int)this + 0x10) + *(float *)((int)this + 4) <=
              *(float *)(param_1 + 0x10) + *(float *)(param_1 + 4))))) {
    local_8 = fVar2;
    GVar3 = GetMin(param_1,(GmBoxAligned *)&local_c);
    fVar1 = *(float *)(CONCAT31(extraout_var,GVar3) + 4);
    if (fVar1 < fVar2 != (fVar1 == fVar2)) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: GmBoxAligned::IsNull
// =================================================
int __thiscall GmBoxAligned::IsNull(void *this,CSysFidNodRef<class_CPlugBitmap> *param_1)
{
{
  if (*(float *)((int)this + 0xc) < 0.0) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmBoxAligned::Mult
// =================================================
void __thiscall GmBoxAligned::Mult(void *this,GmIso3 *param_1,GmIso3 *param_2)
{
{
  SetMult(this,(SPlugFaceCull *)&stack0xffffffe8,(SPlugFaceCull *)param_1,*(GmIso4 **)this);
  return;
}
}

// =================================================
// Function: GmBoxAligned::SetCenterHalfDiag
// =================================================
void __thiscall
GmBoxAligned::SetCenterHalfDiag(void *this,GmBoxAligned *param_1,GmVec3 *param_2,GmVec3 *param_3)
{
{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)param_2;
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_2 + 8);
  return;
}
}

// =================================================
// Function: GmBoxAligned::SetFromConeAndRadius
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmBoxAligned::SetFromConeAndRadius(void *this,GmBoxAligned *param_1,GmCone3 *param_2,float param_3)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  GmCone3 *pGVar7;
  float fVar8;
  GmBoxAligned *pGVar9;
  uint uVar10;
  float10 fVar11;
  float10 fVar12;
  float afStack_18 [6];
  
  fVar1 = *(float *)(param_1 + 0x18);
  fVar11 = (float10)func_0x009c1b40();
  pGVar9 = param_1 + 0xc;
  uVar10 = 0;
  do {
    fVar2 = *(float *)pGVar9;
    fVar12 = (float10)func_0x009c1b40();
    pGVar7 = param_2;
    if (fVar2 <= fVar1) {
      fVar3 = fVar2 * fVar1 + (float)fVar12 * (float)fVar11;
      if (fVar3 < (float)_PTR_00b2c178 != (fVar3 == (float)_PTR_00b2c178)) {
        fVar3 = 0.0;
      }
      pGVar7 = (GmCone3 *)(fVar3 * (float)param_2);
    }
    *(GmCone3 **)((int)afStack_18 + uVar10 + 0xc) = pGVar7;
    fVar3 = -(float)param_2;
    if (-fVar2 <= fVar1) {
      fVar2 = (float)fVar12 * (float)fVar11 - fVar2 * fVar1;
      if (fVar2 < (float)_PTR_00b2c178 != (fVar2 == (float)_PTR_00b2c178)) {
        fVar2 = 0.0;
      }
      fVar3 = -(float)param_2 * fVar2;
    }
    *(float *)((int)afStack_18 + uVar10) = fVar3;
    uVar10 = uVar10 + 4;
    pGVar9 = pGVar9 + 4;
  } while (uVar10 < 0xc);
  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_1 + 4);
  fVar3 = *(float *)(param_1 + 8);
  fVar4 = *(float *)param_1;
  fVar5 = *(float *)(param_1 + 4);
  fVar6 = *(float *)(param_1 + 8);
  fVar8 = (float)_DAT_00b313b8;
  *(float *)this = (fVar1 + afStack_18[0] + fVar4 + afStack_18[3]) * fVar8;
  *(float *)((int)this + 4) = (fVar2 + afStack_18[1] + fVar5 + afStack_18[4]) * fVar8;
  *(float *)((int)this + 8) = (fVar6 + afStack_18[5] + fVar3 + afStack_18[2]) * fVar8;
  *(float *)((int)this + 0xc) = (fVar4 + afStack_18[3]) - (fVar1 + afStack_18[0]);
  *(float *)((int)this + 0x10) = (fVar5 + afStack_18[4]) - (fVar2 + afStack_18[1]);
  *(float *)((int)this + 0x14) = (fVar6 + afStack_18[5]) - (fVar3 + afStack_18[2]);
  *(float *)((int)this + 0xc) = *(float *)((int)this + 0xc) * fVar8;
  *(float *)((int)this + 0x10) = *(float *)((int)this + 0x10) * fVar8;
  *(float *)((int)this + 0x14) = fVar8 * *(float *)((int)this + 0x14);
  return;
}
}

// =================================================
// Function: GmBoxAligned::SetMinMax
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmBoxAligned::SetMinMax(void *this,GmBoxAligned *param_1,GmVec3 *param_2,GmVec3 *param_3)
{
{
  float fVar1;
  
  *(float *)this = *(float *)param_1 + *(float *)param_2;
  *(float *)((int)this + 4) = *(float *)(param_1 + 4) + *(float *)(param_2 + 4);
  *(float *)((int)this + 8) = *(float *)(param_1 + 8) + *(float *)(param_2 + 8);
  fVar1 = (float)_DAT_00b313b8;
  *(float *)this = *(float *)this * fVar1;
  *(float *)((int)this + 4) = *(float *)((int)this + 4) * fVar1;
  *(float *)((int)this + 8) = *(float *)((int)this + 8) * fVar1;
  *(float *)((int)this + 0xc) = *(float *)param_2 - *(float *)param_1;
  *(float *)((int)this + 0x10) = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  *(float *)((int)this + 0x14) = *(float *)(param_2 + 8) - *(float *)(param_1 + 8);
  *(float *)((int)this + 0xc) = *(float *)((int)this + 0xc) * fVar1;
  *(float *)((int)this + 0x10) = *(float *)((int)this + 0x10) * fVar1;
  *(float *)((int)this + 0x14) = fVar1 * *(float *)((int)this + 0x14);
  return;
}
}

// =================================================
// Function: GmBoxAligned::SetMult
// =================================================
void __thiscall
GmBoxAligned::SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3)
{
{
  *(float *)this =
       *(float *)(param_2 + 8) * *(float *)(param_1 + 8) +
       *(float *)(param_2 + 4) * *(float *)(param_1 + 4) + *(float *)param_1 * *(float *)param_2 +
       *(float *)(param_2 + 0x24);
  *(float *)((int)this + 4) =
       *(float *)(param_2 + 0x14) * *(float *)(param_1 + 8) +
       *(float *)param_1 * *(float *)(param_2 + 0xc) +
       *(float *)(param_2 + 0x10) * *(float *)(param_1 + 4) + *(float *)(param_2 + 0x28);
  *(float *)((int)this + 8) =
       *(float *)(param_2 + 0x20) * *(float *)(param_1 + 8) +
       *(float *)(param_2 + 0x18) * *(float *)param_1 +
       *(float *)(param_2 + 0x1c) * *(float *)(param_1 + 4) + *(float *)(param_2 + 0x2c);
  *(float *)((int)this + 0xc) =
       ABS(*(float *)(param_2 + 8)) * *(float *)(param_1 + 0x14) +
       ABS(*(float *)param_2) * *(float *)(param_1 + 0xc) +
       ABS(*(float *)(param_2 + 4)) * *(float *)(param_1 + 0x10);
  *(float *)((int)this + 0x10) =
       ABS(*(float *)(param_2 + 0x14)) * *(float *)(param_1 + 0x14) +
       ABS(*(float *)(param_2 + 0xc)) * *(float *)(param_1 + 0xc) +
       ABS(*(float *)(param_2 + 0x10)) * *(float *)(param_1 + 0x10);
  *(float *)((int)this + 0x14) =
       ABS(*(float *)(param_2 + 0x20)) * *(float *)(param_1 + 0x14) +
       ABS(*(float *)(param_2 + 0x18)) * *(float *)(param_1 + 0xc) +
       ABS(*(float *)(param_2 + 0x1c)) * *(float *)(param_1 + 0x10);
  return;
}
}

// =================================================
// Function: GmBoxAligned::TestInter
// =================================================
int __thiscall
GmBoxAligned::TestInter
          (void *this,CPlugVolumeProjector *param_1,GmBoxAligned *param_2,GmIso4 *param_3)
{
{
  if (ABS(*(float *)param_1 - *(float *)this) <= *(float *)((int)this + 0xc)) {
    if (ABS(*(float *)(param_1 + 4) - *(float *)((int)this + 4)) <= *(float *)((int)this + 0x10)) {
      if (ABS(*(float *)(param_1 + 8) - *(float *)((int)this + 8)) <= *(float *)((int)this + 0x14))
      {
        return 1;
      }
    }
  }
  return 0;
}
}

// =================================================
// Function: GmBoxAligned::TestInterSegment
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
GmBoxAligned::TestInterSegment(void *this,GmRectAligned *param_1,GmVec2 *param_2,GmVec2 *param_3)
{
{
  ulong uVar1;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *(float *)param_2 - *(float *)param_1;
  local_8 = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  local_4 = *(float *)(param_2 + 8) - *(float *)(param_1 + 8);
  uVar1 = TestInterSegment_MiddleVectAB
                    (this,(GmBoxAligned *)&stack0xffffffe8,(GmVec3 *)&local_c,
                     (GmVec3 *)((*(float *)param_1 + *(float *)param_2) * (float)_DAT_00b313b8));
  return uVar1;
}
}

// =================================================
// Function: GmBoxAligned::TestInterSegment_MiddleVectAB
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
GmBoxAligned::TestInterSegment_MiddleVectAB
          (void *this,GmBoxAligned *param_1,GmVec3 *param_2,GmVec3 *param_3)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar1 = *(float *)this - *(float *)param_1;
  fVar2 = *(float *)((int)this + 4) - *(float *)(param_1 + 4);
  fVar3 = *(float *)((int)this + 8) - *(float *)(param_1 + 8);
  fVar4 = ABS(*(float *)param_2);
  fVar7 = (float)_DAT_00b313b8;
  if ((((ABS(fVar1) <= *(float *)((int)this + 0xc) + fVar4 * fVar7) &&
       (fVar5 = ABS(*(float *)(param_2 + 4)),
       ABS(fVar2) <= fVar5 * fVar7 + *(float *)((int)this + 0x10))) &&
      (fVar6 = ABS(*(float *)(param_2 + 8)),
      ABS(fVar3) <= *(float *)((int)this + 0x14) + fVar6 * fVar7)) &&
     (((ABS(*(float *)(param_2 + 8) * fVar2 - *(float *)(param_2 + 4) * fVar3) <=
        *(float *)((int)this + 0x10) * fVar6 + fVar5 * *(float *)((int)this + 0x14) &&
       (ABS(fVar3 * *(float *)param_2 - fVar1 * *(float *)(param_2 + 8)) <=
        fVar4 * *(float *)((int)this + 0x14) + *(float *)((int)this + 0xc) * fVar6)) &&
      (ABS(fVar1 * *(float *)(param_2 + 4) - *(float *)param_2 * fVar2) <=
       *(float *)((int)this + 0xc) * fVar5 + *(float *)((int)this + 0x10) * fVar4)))) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmBoxAligned::Union
// =================================================
void __thiscall GmBoxAligned::Union(void *this,GmRectAligned *param_1,GmVec2 *param_2)
{
{
  GmVec3 *pGVar1;
  float local_18;
  float local_14;
  float local_10;
  GmVec3 *local_c;
  float local_8;
  float local_4;
  
  if (*(float *)((int)this + 0xc) < 0.0) {
    *(undefined4 *)this = *(undefined4 *)param_1;
    *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x14);
    return;
  }
  if (0.0 <= *(float *)(param_1 + 0xc)) {
    local_18 = *(float *)this - *(float *)((int)this + 0xc);
    local_14 = *(float *)((int)this + 4) - *(float *)((int)this + 0x10);
    local_10 = *(float *)((int)this + 8) - *(float *)((int)this + 0x14);
    pGVar1 = (GmVec3 *)(*(float *)this + *(float *)((int)this + 0xc));
    if (*(float *)param_1 - *(float *)(param_1 + 0xc) < local_18) {
      local_18 = *(float *)param_1 - *(float *)(param_1 + 0xc);
    }
    if (*(float *)(param_1 + 4) - *(float *)(param_1 + 0x10) < local_14) {
      local_14 = *(float *)(param_1 + 4) - *(float *)(param_1 + 0x10);
    }
    if (*(float *)(param_1 + 8) - *(float *)(param_1 + 0x14) < local_10) {
      local_10 = *(float *)(param_1 + 8) - *(float *)(param_1 + 0x14);
    }
    local_c = (GmVec3 *)(*(float *)(param_1 + 0xc) + *(float *)param_1);
    local_8 = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 4);
    local_4 = *(float *)(param_1 + 0x14) + *(float *)(param_1 + 8);
    if ((float)pGVar1 < (float)local_c) {
      pGVar1 = local_c;
    }
    if (*(float *)((int)this + 0x14) + *(float *)((int)this + 8) < local_4) {
      SetMinMax(this,(GmBoxAligned *)&local_18,(GmVec3 *)&stack0xffffffdc,pGVar1);
      return;
    }
    SetMinMax(this,(GmBoxAligned *)&local_18,(GmVec3 *)&stack0xffffffdc,pGVar1);
  }
  return;
}
}

