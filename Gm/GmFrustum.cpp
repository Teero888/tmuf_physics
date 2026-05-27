// Class implementation: GmFrustum

// =================================================
// Function: GmFrustum::GetAspect
// =================================================
void __thiscall GmFrustum::GetAspect(void *this,GmFrustum *param_1,GmRectAligned *param_2)
{
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)((int)this + 8);
  *(undefined4 *)param_1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = *(undefined4 *)((int)this + 0x14);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)((int)this + 0x10);
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return;
}
}

// =================================================
// Function: GmFrustum::GetBBox
// =================================================
void __thiscall GmFrustum::GetBBox(void *this,GmFrustum *param_1,GmBoxAligned *param_2)
{
{
  float local_c;
  float local_8;
  undefined4 local_4;
  
  if (*(int *)this != 0) {
    *(undefined4 *)param_1 = *(undefined4 *)((int)this + 4);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)((int)this + 8);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)((int)this + 0xc);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)((int)this + 0x10);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)((int)this + 0x14);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)((int)this + 0x18);
    return;
  }
  local_c = *(float *)((int)this + 4) * *(float *)((int)this + 0x18);
  local_8 = *(float *)((int)this + 8) * *(float *)((int)this + 0x18);
  local_4 = *(undefined4 *)((int)this + 0xc);
  GmBoxAligned::SetMinMax
            (param_1,(GmBoxAligned *)&local_c,(GmVec3 *)&stack0xffffffe8,
             (GmVec3 *)(*(float *)((int)this + 0x10) * *(float *)((int)this + 0x18)));
  return;
}
}

// =================================================
// Function: GmFrustum::GetFarZ
// =================================================
float __thiscall GmFrustum::GetFarZ(void *this,GmFrustum *param_1)
{
{
  if (*(int *)this != 0) {
    return *(float *)((int)this + 0x18) + *(float *)((int)this + 0xc);
  }
  return *(float *)((int)this + 0x18);
}
}

// =================================================
// Function: GmFrustum::GetFovY
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall GmFrustum::GetFovY(void *this,GmFrustum *param_1)
{
{
  float10 extraout_ST0;
  
  __CIatan();
  return (((float)extraout_ST0 + (float)extraout_ST0) / (float)_DAT_00b36110) * (float)_DAT_00b36ab8
  ;
}
}

// =================================================
// Function: GmFrustum::GetNearZ
// =================================================
float __thiscall GmFrustum::GetNearZ(void *this,GmFrustum *param_1)
{
{
  if (*(int *)this != 0) {
    return *(float *)((int)this + 0xc) - *(float *)((int)this + 0x18);
  }
  return *(float *)((int)this + 0xc);
}
}

// =================================================
// Function: GmFrustum::GetPlaneEqs6
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmFrustum::GetPlaneEqs6(void *this,GmFrustum *param_1,GmVec4 *param_2,GmIso4 *param_3)
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
  float fVar15;
  GmIso4 *unaff_EDI;
  int iVar16;
  float10 fVar17;
  float local_c;
  float local_8;
  
  if (*(int *)this == 0) {
    fVar1 = *(float *)((int)this + 0xc);
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    local_c = _DAT_00b2c060;
    *(float *)(param_1 + 8) = _DAT_00b2c060;
    fVar2 = (float)_DAT_00b56ec0 * 0.0 - 0.0;
    *(float *)(param_1 + 0xc) = fVar2 - fVar1 * (float)_DAT_00b55920;
    local_8 = 0.0;
    fVar1 = *(float *)((int)this + 4);
    fVar3 = (float)_DAT_00b2c188 + 0.0;
    if (_DAT_00d1a830 < fVar1 * fVar1 + fVar3) {
      fVar17 = (float10)func_0x009c1b40();
      fVar4 = 1.0 / (float)fVar17;
      local_c = (float)_DAT_00b55920 * fVar4;
      local_8 = fVar4 * 0.0;
      fVar1 = fVar1 * fVar4;
    }
    *(float *)(param_1 + 0x10) = local_c;
    *(float *)(param_1 + 0x14) = local_8;
    *(float *)(param_1 + 0x18) = fVar1;
    *(float *)(param_1 + 0x1c) = (-local_c * 0.0 - local_8 * 0.0) - fVar1 * 0.0;
    local_c = 1.0;
    local_8 = 0.0;
    fVar1 = -*(float *)((int)this + 0x10);
    if (_DAT_00d1a830 < fVar1 * fVar1 + fVar3) {
      fVar17 = (float10)func_0x009c1b40();
      local_c = 1.0 / (float)fVar17;
      local_8 = local_c * 0.0;
      fVar1 = fVar1 * local_c;
    }
    *(float *)(param_1 + 0x20) = local_c;
    *(float *)(param_1 + 0x24) = local_8;
    *(float *)(param_1 + 0x28) = fVar1;
    *(float *)(param_1 + 0x2c) = (-local_c * 0.0 - local_8 * 0.0) - fVar1 * 0.0;
    local_c = 0.0;
    local_8 = _DAT_00b2c060;
    fVar1 = *(float *)((int)this + 8);
    if (_DAT_00d1a830 < fVar1 * fVar1 + fVar3) {
      fVar17 = (float10)func_0x009c1b40();
      fVar4 = 1.0 / (float)fVar17;
      local_c = fVar4 * 0.0;
      local_8 = fVar4 * (float)_DAT_00b55920;
      fVar1 = fVar1 * fVar4;
    }
    *(float *)(param_1 + 0x30) = local_c;
    *(float *)(param_1 + 0x34) = local_8;
    *(float *)(param_1 + 0x38) = fVar1;
    *(float *)(param_1 + 0x3c) = (-local_c * 0.0 - local_8 * 0.0) - fVar1 * 0.0;
    local_c = 0.0;
    local_8 = 1.0;
    fVar1 = -*(float *)((int)this + 0x14);
    if (_DAT_00d1a830 < fVar1 * fVar1 + fVar3) {
      fVar17 = (float10)func_0x009c1b40();
      local_8 = 1.0 / (float)fVar17;
      local_c = local_8 * 0.0;
      fVar1 = local_8 * fVar1;
    }
    *(float *)(param_1 + 0x40) = local_c;
    *(float *)(param_1 + 0x44) = local_8;
    *(float *)(param_1 + 0x48) = fVar1;
    *(float *)(param_1 + 0x4c) = (-local_c * 0.0 - local_8 * 0.0) - fVar1 * 0.0;
    if (*(int *)this == 0) {
      fVar1 = *(float *)((int)this + 0x18);
    }
    else {
      fVar1 = *(float *)((int)this + 0x18) + *(float *)((int)this + 0xc);
    }
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined4 *)(param_1 + 0x58) = 0x3f800000;
    fVar2 = fVar2 - fVar1;
  }
  else {
    fVar1 = *(float *)((int)this + 4);
    fVar2 = *(float *)((int)this + 0x10);
    fVar3 = *(float *)((int)this + 8);
    fVar4 = *(float *)((int)this + 0x14);
    fVar5 = *(float *)((int)this + 0xc);
    fVar6 = *(float *)((int)this + 0x18);
    fVar7 = *(float *)((int)this + 4);
    fVar8 = *(float *)((int)this + 0x10);
    fVar9 = *(float *)((int)this + 0x14);
    fVar10 = *(float *)((int)this + 8);
    fVar11 = *(float *)((int)this + 0x18);
    fVar12 = *(float *)((int)this + 0xc);
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    fVar15 = _DAT_00b2c060;
    *(float *)(param_1 + 8) = _DAT_00b2c060;
    fVar13 = (float)_DAT_00b56ec0 * 0.0;
    fVar14 = (float)_DAT_00b55920;
    *(float *)(param_1 + 0xc) = (fVar13 - 0.0) - (fVar5 - fVar6) * fVar14;
    *(float *)(param_1 + 0x10) = fVar15;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(float *)(param_1 + 0x1c) = ((fVar1 - fVar2) - 0.0) - 0.0;
    *(undefined4 *)(param_1 + 0x20) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(float *)(param_1 + 0x2c) = ((fVar7 + fVar8) * fVar14 - 0.0) - 0.0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(float *)(param_1 + 0x34) = fVar15;
    *(float *)(param_1 + 0x3c) = (fVar13 - (fVar3 - fVar4) * fVar14) - 0.0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0x3f800000;
    *(float *)(param_1 + 0x4c) = (fVar13 - (fVar9 + fVar10)) - 0.0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined4 *)(param_1 + 0x58) = 0x3f800000;
    fVar2 = (fVar13 - 0.0) - (fVar11 + fVar12);
  }
  *(float *)(param_1 + 0x5c) = fVar2;
  if (param_2 != (GmVec4 *)0x0) {
    iVar16 = 6;
    do {
      GmVec4::PlaneEqMult(param_1,param_2,unaff_EDI);
      param_1 = param_1 + 0x10;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
  }
  return;
}
}

// =================================================
// Function: GmFrustum::GetRatioXY
// =================================================
float __thiscall GmFrustum::GetRatioXY(void *this,GmFrustum *param_1)
{
{
  return ((*(float *)((int)this + 0x10) + *(float *)((int)this + 4)) -
         (*(float *)((int)this + 4) - *(float *)((int)this + 0x10))) /
         ((*(float *)((int)this + 0x14) + *(float *)((int)this + 8)) -
         (*(float *)((int)this + 8) - *(float *)((int)this + 0x14)));
}
}

// =================================================
// Function: GmFrustum::GetRectZ
// =================================================
void __thiscall
GmFrustum::GetRectZ(void *this,GmFrustum *param_1,float param_2,GmRectAligned *param_3)
{
{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)((int)this + 8);
  if (*(int *)this != 0) {
    fVar2 = *(float *)((int)this + 0x14);
    *(float *)param_2 = *(float *)((int)this + 4) - *(float *)((int)this + 0x10);
    *(float *)((int)param_2 + 4) = fVar1 - fVar2;
    fVar1 = *(float *)((int)this + 0x14);
    fVar2 = *(float *)((int)this + 8);
    *(float *)((int)param_2 + 8) = *(float *)((int)this + 0x10) + *(float *)((int)this + 4);
    *(float *)((int)param_2 + 0xc) = fVar1 + fVar2;
    return;
  }
  *(float *)param_2 = *(float *)((int)this + 4) * (float)param_1;
  *(float *)((int)param_2 + 4) = (float)param_1 * fVar1;
  fVar1 = *(float *)((int)this + 0x14);
  *(float *)((int)param_2 + 8) = (float)param_1 * *(float *)((int)this + 0x10);
  *(float *)((int)param_2 + 0xc) = fVar1 * (float)param_1;
  return;
}
}

// =================================================
// Function: GmFrustum::GetVertices4AtZ
// =================================================
void __thiscall
GmFrustum::GetVertices4AtZ(void *this,GmFrustum *param_1,GmVec3 *param_2,float param_3)
{
{
  float fVar1;
  
  fVar1 = *(float *)((int)this + 8);
  *(float *)param_1 = *(float *)((int)this + 4) * (float)param_2;
  *(float *)(param_1 + 4) = (float)param_2 * fVar1;
  *(GmVec3 **)(param_1 + 8) = param_2;
  fVar1 = *(float *)((int)this + 8);
  *(float *)(param_1 + 0xc) = *(float *)((int)this + 0x10) * (float)param_2;
  *(float *)(param_1 + 0x10) = (float)param_2 * fVar1;
  *(GmVec3 **)(param_1 + 0x14) = param_2;
  fVar1 = *(float *)((int)this + 0x14);
  *(float *)(param_1 + 0x18) = *(float *)((int)this + 4) * (float)param_2;
  *(float *)(param_1 + 0x1c) = fVar1 * (float)param_2;
  *(GmVec3 **)(param_1 + 0x20) = param_2;
  fVar1 = *(float *)((int)this + 0x14);
  *(float *)(param_1 + 0x24) = *(float *)((int)this + 0x10) * (float)param_2;
  *(float *)(param_1 + 0x28) = fVar1 * (float)param_2;
  *(GmVec3 **)(param_1 + 0x2c) = param_2;
  return;
}
}

// =================================================
// Function: GmFrustum::IsValid
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall GmFrustum::IsValid(void *this,CGameScoresVersion *param_1)
{
{
  float fVar1;
  
  if (*(int *)this != 0) {
    if (0.0 <= *(float *)((int)this + 0x10)) {
      return 1;
    }
    return 0;
  }
  fVar1 = (float)_DAT_00b36288;
  if (((fVar1 < *(float *)((int)this + 0x10) - *(float *)((int)this + 4)) &&
      (fVar1 < *(float *)((int)this + 0x14) - *(float *)((int)this + 8))) &&
     (fVar1 < *(float *)((int)this + 0x18) - *(float *)((int)this + 0xc))) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmFrustum::Set
// =================================================
void __thiscall GmFrustum::Set(void *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  float fVar1;
  float fVar2;
  
  *(float *)((int)this + 0xc) = *(float *)(param_1 + 8) - *(float *)(param_1 + 0x14);
  *(float *)((int)this + 0x18) = *(float *)(param_1 + 0x14) + *(float *)(param_1 + 8);
  *(float *)((int)this + 4) =
       (*(float *)param_1 - *(float *)(param_1 + 0xc)) / *(float *)((int)this + 0xc);
  *(float *)((int)this + 0x10) =
       (*(float *)(param_1 + 0xc) + *(float *)param_1) / *(float *)((int)this + 0xc);
  *(float *)((int)this + 8) =
       (*(float *)(param_1 + 4) - *(float *)(param_1 + 0x10)) / *(float *)((int)this + 0xc);
  fVar1 = *(float *)(param_1 + 0x10);
  fVar2 = *(float *)(param_1 + 4);
  *(undefined4 *)this = 0;
  *(float *)((int)this + 0x14) = (fVar1 + fVar2) / *(float *)((int)this + 0xc);
  return;
}
}

// =================================================
// Function: GmFrustum::SetFarZ
// =================================================
void __thiscall GmFrustum::SetFarZ(void *this,CHmsCamera *param_1,float param_2)
{
{
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)this != 0) {
    local_c = *(float *)((int)this + 4) - *(float *)((int)this + 0x10);
    local_8 = *(float *)((int)this + 8) - *(float *)((int)this + 0x14);
    local_4 = *(float *)((int)this + 0xc) - *(float *)((int)this + 0x18);
    GmBoxAligned::SetMinMax
              ((float *)((int)this + 4),(GmBoxAligned *)&local_c,(GmVec3 *)&stack0xffffffe8,
               (GmVec3 *)(*(float *)((int)this + 4) + *(float *)((int)this + 0x10)));
    return;
  }
  *(CHmsCamera **)((int)this + 0x18) = param_1;
  return;
}
}

// =================================================
// Function: GmFrustum::SetFovX
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmFrustum::SetFovX(void *this,GmFrustum *param_1,float param_2,float param_3,float param_4,
                  float param_5)
{
{
  float fVar1;
  float10 extraout_ST0;
  
  __CItan();
  fVar1 = (float)extraout_ST0;
  *(undefined4 *)this = 0;
  *(float *)((int)this + 0xc) = param_3;
  *(float *)((int)this + 0x18) = param_4;
  *(float *)((int)this + 0x10) = fVar1;
  *(float *)((int)this + 4) = -fVar1;
  *(float *)((int)this + 0x14) = fVar1 / param_2;
  *(float *)((int)this + 8) = -(fVar1 / param_2);
  return;
}
}

// =================================================
// Function: GmFrustum::SetFovY
// =================================================
void __thiscall
GmFrustum::SetFovY(void *this,GmFrustum *param_1,float param_2,float param_3,float param_4,
                  float param_5)
{
{
  Set(this,(CMwCmdScriptVarBool *)param_1,(int)param_2);
  return;
}
}

// =================================================
// Function: GmFrustum::SetOrtho
// =================================================
void __thiscall GmFrustum::SetOrtho(void *this,GmFrustum *param_1,GmBoxAligned *param_2)
{
{
  *(undefined4 *)((int)this + 4) = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((int)this + 0x18) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)this = 1;
  return;
}
}

// =================================================
// Function: GmFrustum::TestInter
// =================================================
int __thiscall
GmFrustum::TestInter(void *this,CPlugVolumeProjector *param_1,GmBoxAligned *param_2,GmIso4 *param_3)
{
{
  int iVar1;
  GmBoxAligned *in_stack_ffffffe0;
  GmIso4 *in_stack_ffffffe4;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)this != 0) {
    iVar1 = GmBoxAligned::TestInter
                      ((void *)((int)this + 4),param_1,in_stack_ffffffe0,in_stack_ffffffe4);
    return iVar1;
  }
  if ((*(float *)((int)this + 0xc) <= *(float *)(param_1 + 0x14) + *(float *)(param_1 + 8)) &&
     ((param_2 != (GmBoxAligned *)0x0 ||
      (*(float *)(param_1 + 8) - *(float *)(param_1 + 0x14) <= *(float *)((int)this + 0x18))))) {
    local_10 = *(float *)(&stack0xffffffe0 + (*(int *)((int)this + 4) >> 0x1f) * -4) *
               *(float *)((int)this + 4);
    local_c = *(float *)(&stack0xffffffe0 + (*(int *)((int)this + 8) >> 0x1f) * -4) *
              *(float *)((int)this + 8);
    local_8 = *(float *)(&stack0xffffffe0 + ((int)~*(uint *)((int)this + 0x10) >> 0x1f) * -4) *
              *(float *)((int)this + 0x10);
    local_4 = *(float *)(&stack0xffffffe0 + ((int)~*(uint *)((int)this + 0x14) >> 0x1f) * -4) *
              *(float *)((int)this + 0x14);
    iVar1 = GmRectAligned::TestInter
                      (&local_10,(CPlugVolumeProjector *)&stack0xffffffe0,
                       (GmBoxAligned *)(*(float *)param_1 - *(float *)(param_1 + 0xc)),
                       (GmIso4 *)(*(float *)(param_1 + 4) - *(float *)(param_1 + 0x10)));
    return iVar1;
  }
  return 0;
}
}

