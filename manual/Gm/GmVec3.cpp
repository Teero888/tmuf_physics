// Class implementation: GmVec3

// =================================================
// Function: GmVec3::ComputeTriangleTangentUV
// =================================================
int __cdecl GmVec3::ComputeTriangleTangentUV(STri_PosTexTgt *param_1)
{
{
  ulong uVar1;
  ulong uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = ComputeTriangleTangentUV_Rotated(param_1,uVar2);
    if (uVar1 != 0) {
      return uVar1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 3);
  return 0;
}
}

// =================================================
// Function: GmVec3::DoesRayIntersectTriangle
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
GmVec3::DoesRayIntersectTriangle
          (GmVec3 *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4,GmVec3 *param_5,
          float *param_6,float *param_7,float *param_8)
{
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
  if ((float)_DAT_00b36288 * fVar1 * fVar1 <= fVar11 * fVar11) {
    fVar1 = ABS(fVar11);
    fVar12 = *(float *)param_1 - *(float *)param_3;
    fVar13 = *(float *)(param_1 + 4) - *(float *)(param_3 + 4);
    fVar14 = *(float *)(param_1 + 8) - *(float *)(param_3 + 8);
    fVar2 = (float)((uint)(fVar14 * fVar9 + fVar12 * fVar2 + fVar13 * fVar10) ^
                   (uint)fVar11 & 0x80000000);
    if (fVar2 < 0.0) {
      return 0;
    }
    if (fVar2 <= fVar1) {
      fVar9 = fVar13 * fVar5 - fVar14 * fVar4;
      fVar5 = fVar14 * fVar3 - fVar12 * fVar5;
      fVar4 = fVar12 * fVar4 - fVar13 * fVar3;
      fVar3 = (float)((uint)(fVar9 * *(float *)param_2 + fVar5 * *(float *)(param_2 + 4) +
                            fVar4 * *(float *)(param_2 + 8)) ^ (uint)fVar11 & 0x80000000);
      if (fVar3 < 0.0) {
        return 0;
      }
      if (fVar2 + fVar3 <= fVar1) {
        fVar1 = 1.0 / fVar1;
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
}

// =================================================
// Function: GmVec3::DoesRayIntersectTriangleCull
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
GmVec3::DoesRayIntersectTriangleCull
          (GmVec3 *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4,GmVec3 *param_5,
          float *param_6,float *param_7,float *param_8)
{
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
  if (fVar10 < 0.0) {
    return 0;
  }
  fVar11 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if ((float)_DAT_00b36288 * fVar11 * fVar11 <= fVar10 * fVar10) {
    fVar11 = *(float *)param_1 - *(float *)param_3;
    fVar12 = *(float *)(param_1 + 4) - *(float *)(param_3 + 4);
    fVar13 = *(float *)(param_1 + 8) - *(float *)(param_3 + 8);
    fVar7 = fVar13 * fVar8 + fVar11 * fVar7 + fVar12 * fVar9;
    if (fVar7 < 0.0) {
      return 0;
    }
    if (fVar10 < fVar7) {
      return 0;
    }
    fVar8 = fVar12 * fVar3 - fVar13 * fVar2;
    fVar3 = fVar13 * fVar1 - fVar11 * fVar3;
    fVar1 = fVar11 * fVar2 - fVar12 * fVar1;
    fVar2 = fVar8 * *(float *)param_2 + fVar3 * *(float *)(param_2 + 4) +
            fVar1 * *(float *)(param_2 + 8);
    if (0.0 <= fVar2) {
      if (fVar10 < fVar7 + fVar2) {
        return 0;
      }
      fVar10 = 1.0 / fVar10;
      *param_6 = fVar10 * fVar7;
      *param_7 = fVar10 * fVar2;
      *param_8 = fVar10 * (fVar1 * fVar6 + fVar5 * fVar3 + fVar4 * fVar8);
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: GmVec3::GetAngle
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __cdecl GmVec3::GetAngle(GmVec3 *param_1,GmVec3 *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float10 extraout_ST0;
  float10 fVar6;
  float local_18;
  float local_14;
  float local_10;
  
  __CIacos();
  fVar1 = (float)extraout_ST0;
  if (_DAT_00bbdb0c < fVar1) {
    local_18 = *(float *)param_1;
    local_14 = *(float *)(param_1 + 4);
    local_10 = *(float *)(param_1 + 8);
    if (_DAT_00d1a8f0 < local_10 * local_10 + local_18 * local_18 + local_14 * local_14) {
      fVar6 = (float10)func_0x009c1b40();
      fVar2 = 1.0 / (float)fVar6;
      local_18 = fVar2 * local_18;
      local_14 = local_14 * fVar2;
      local_10 = fVar2 * local_10;
    }
    fVar2 = *(float *)param_2;
    fVar3 = *(float *)(param_2 + 4);
    fVar4 = *(float *)(param_2 + 8);
    if (_DAT_00d1a8f0 < fVar3 * fVar3 + fVar2 * fVar2 + fVar4 * fVar4) {
      fVar6 = (float10)func_0x009c1b40();
      fVar5 = 1.0 / (float)fVar6;
      fVar2 = fVar5 * fVar2;
      fVar3 = fVar5 * fVar3;
      fVar4 = fVar5 * fVar4;
    }
    if ((fVar3 * local_18 - local_14 * fVar2) * 0.0 +
        (local_10 * fVar2 - local_18 * fVar4) + (fVar4 * local_14 - local_10 * fVar3) * 0.0 <
        _DAT_00c418e0) {
      fVar1 = -fVar1;
    }
  }
  return fVar1;
}
}

// =================================================
// Function: GmVec3::GetInnerAngle
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __cdecl GmVec3::GetInnerAngle(GmVec3 *param_1,GmVec3 *param_2)
{
{
  float10 extraout_ST0;
  
  __CIacos();
  return (float)extraout_ST0;
}
}

// =================================================
// Function: GmVec3::IsNearlyEqual
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall GmVec3::IsNearlyEqual(void *this,GmVec2 *param_1,GmVec2 *param_2)
{
{
  float fVar1;
  float fVar2;
  
  fVar2 = (float)_DAT_00b36288;
  fVar1 = *(float *)param_1 - ABS(*(float *)param_1) * fVar2;
  if (fVar1 < *(float *)this == (fVar1 == *(float *)this)) {
    return 0;
  }
  fVar1 = *(float *)param_1 + ABS(*(float *)param_1) * fVar2;
  if ((((*(float *)this < fVar1 != (*(float *)this == fVar1)) &&
       (fVar1 = *(float *)(param_1 + 4) - ABS(*(float *)(param_1 + 4)) * fVar2,
       fVar1 < *(float *)((int)this + 4) != (fVar1 == *(float *)((int)this + 4)))) &&
      (fVar1 = *(float *)(param_1 + 4) + ABS(*(float *)(param_1 + 4)) * fVar2,
      *(float *)((int)this + 4) < fVar1 != (*(float *)((int)this + 4) == fVar1))) &&
     ((fVar1 = *(float *)(param_1 + 8) - fVar2 * ABS(*(float *)(param_1 + 8)),
      fVar1 < *(float *)((int)this + 8) != (fVar1 == *(float *)((int)this + 8)) &&
      (fVar1 = *(float *)(param_1 + 8) + fVar2 * ABS(*(float *)(param_1 + 8)),
      *(float *)((int)this + 8) < fVar1 != (*(float *)((int)this + 8) == fVar1))))) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmVec3::Mult
// =================================================
void __thiscall GmVec3::Mult(void *this,GmIso3 *param_1,GmIso3 *param_2)
{
{
  float fVar1;
  GmIso4 *unaff_ESI;
  float unaff_retaddr;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  float local_c;
  float local_8;
  float local_4;
  
  local_20 = *(undefined4 *)this;
  local_1c = *(undefined4 *)((int)this + 4);
  local_18 = *(undefined4 *)((int)this + 8);
  local_14 = 0x3f800000;
  GmVec4::SetMult(local_10,(SPlugFaceCull *)&local_20,(SPlugFaceCull *)param_1,unaff_ESI);
  fVar1 = 1.0 / ABS(unaff_retaddr);
  *(float *)this = fVar1 * local_c;
  *(float *)((int)this + 4) = local_8 * fVar1;
  *(float *)((int)this + 8) = fVar1 * local_4;
  return;
}
}

// =================================================
// Function: GmVec3::MultInverse
// =================================================
void __thiscall GmVec3::MultInverse(void *this,GmIso3 *param_1,GmIso3 *param_2)
{
{
  GmMat3 *unaff_ESI;
  undefined4 unaff_retaddr;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *(float *)this - *(float *)(param_1 + 0x24);
  local_8 = *(float *)((int)this + 4) - *(float *)(param_1 + 0x28);
  local_4 = *(float *)((int)this + 8) - *(float *)(param_1 + 0x2c);
  MultTranspose(&local_c,(GmMat3 *)param_1,unaff_ESI);
  *(float *)this = local_8;
  *(float *)((int)this + 4) = local_4;
  *(undefined4 *)((int)this + 8) = unaff_retaddr;
  return;
}
}

// =================================================
// Function: GmVec3::MultTranspose
// =================================================
void __thiscall GmVec3::MultTranspose(void *this,GmMat3 *param_1,GmMat3 *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *(float *)this;
  fVar2 = *(float *)((int)this + 4);
  fVar3 = *(float *)((int)this + 8);
  *(float *)this =
       fVar2 * *(float *)(param_1 + 0xc) + fVar1 * *(float *)param_1 +
       fVar3 * *(float *)(param_1 + 0x18);
  *(float *)((int)this + 4) =
       *(float *)(param_1 + 0x1c) * fVar3 +
       *(float *)(param_1 + 0x10) * fVar2 + *(float *)(param_1 + 4) * fVar1;
  *(float *)((int)this + 8) =
       *(float *)(param_1 + 8) * fVar1 + *(float *)(param_1 + 0x14) * fVar2 +
       *(float *)(param_1 + 0x20) * fVar3;
  return;
}
}

// =================================================
// Function: GmVec3::SetFromBGRA
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmVec3::SetFromBGRA(void *this,GmVec3 *param_1,uchar *param_2,ulong param_3)
{
{
  float fVar1;
  
  fVar1 = (float)_DAT_00b3d080;
  *(float *)((int)this + 8) = (float)(byte)*param_1 * fVar1;
  *(float *)((int)this + 4) = (float)(byte)param_1[1] * fVar1;
  *(float *)this = (float)(byte)param_1[2] * fVar1;
  return;
}
}

// =================================================
// Function: GmVec3::SetInverseTranslation
// =================================================
void __thiscall GmVec3::SetInverseTranslation(void *this,GmVec3 *param_1,GmIso4 *param_2)
{
{
  *(float *)this =
       (-*(float *)(param_1 + 0x24) * *(float *)param_1 -
       *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x28)) -
       *(float *)(param_1 + 0x18) * *(float *)(param_1 + 0x2c);
  *(float *)((int)this + 4) =
       (-*(float *)(param_1 + 0x24) * *(float *)(param_1 + 4) -
       *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x28)) -
       *(float *)(param_1 + 0x1c) * *(float *)(param_1 + 0x2c);
  *(float *)((int)this + 8) =
       (-*(float *)(param_1 + 0x24) * *(float *)(param_1 + 8) -
       *(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x28)) -
       *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x2c);
  return;
}
}

// =================================================
// Function: GmVec3::SetMult
// =================================================
void __thiscall
GmVec3::SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3)
{
{
  float fVar1;
  GmIso4 *unaff_ESI;
  float unaff_retaddr;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  float local_c;
  float local_8;
  float local_4;
  
  local_20 = *(undefined4 *)param_1;
  local_1c = *(undefined4 *)(param_1 + 4);
  local_18 = *(undefined4 *)(param_1 + 8);
  local_14 = 0x3f800000;
  GmVec4::SetMult(local_10,(SPlugFaceCull *)&local_20,param_2,unaff_ESI);
  fVar1 = 1.0 / ABS(unaff_retaddr);
  *(float *)this = fVar1 * local_c;
  *(float *)((int)this + 4) = local_8 * fVar1;
  *(float *)((int)this + 8) = fVar1 * local_4;
  return;
}
}

// =================================================
// Function: GmVec3::SetMultTranspose
// =================================================
void __thiscall GmVec3::SetMultTranspose(void *this,GmVec3 *param_1,GmVec3 *param_2,GmMat3 *param_3)
{
{
  *(float *)this =
       *(float *)(param_2 + 0x18) * *(float *)(param_1 + 8) +
       *(float *)param_1 * *(float *)param_2 + *(float *)(param_2 + 0xc) * *(float *)(param_1 + 4);
  *(float *)((int)this + 4) =
       *(float *)(param_2 + 0x1c) * *(float *)(param_1 + 8) +
       *(float *)(param_2 + 0x10) * *(float *)(param_1 + 4) +
       *(float *)(param_2 + 4) * *(float *)param_1;
  *(float *)((int)this + 8) =
       *(float *)(param_2 + 0x20) * *(float *)(param_1 + 8) +
       *(float *)(param_2 + 0x14) * *(float *)(param_1 + 4) +
       *(float *)(param_2 + 8) * *(float *)param_1;
  return;
}
}

