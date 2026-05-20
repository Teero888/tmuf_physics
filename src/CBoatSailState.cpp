// Class implementation: CBoatSailState

// =================================================
// Function: CBoatSailState::BSCoefSailTuningGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CBoatSailState::BSCoefSailTuningGet
          (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4)
{
{
  CFuncCurves2Real *this_00;
  CMwId *pCVar1;
  float unaff_ESI;
  float10 extraout_ST0;
  float fVar2;
  float unaff_retaddr;
  float in_stack_00000014;
  
  if (*(int *)(*(int *)(*(int *)(this + 0x14) + 0x14) + 0xbc) == 0) {
    OptimalSailAngleGet(this,(CBoatSail *)param_1,param_3,unaff_ESI,(CMwId *)this);
    CBoatSail::ShiverAngleGet(*(CBoatSail **)(this + 0x14),(CBoatSail *)param_3,unaff_retaddr);
    return 1.0;
  }
  if (*(int *)(*(int *)(this + 0x14) + 0x50) == 0) {
    return 1.0;
  }
  pCVar1 = _DAT_00b2c060;
  if (-1 < (int)param_3) {
    pCVar1 = (CMwId *)0x3f800000;
  }
  OptimalSailAngleGet(this,(CBoatSail *)param_1,param_3,unaff_ESI,pCVar1);
  this_00 = *(CFuncCurves2Real **)(*(int *)(this + 0x14) + 0x50);
  fVar2 = GmFunc::Mod(in_stack_00000014,_DAT_00b5b910,_DAT_00baab40);
  CFuncCurves2Real::GetValue(this_00,(CFuncColorGradient *)param_3,ABS(fVar2));
  return (float)extraout_ST0;
}
}

// =================================================
// Function: CBoatSailState::HeelGet
// =================================================
float __thiscall
CBoatSailState::HeelGet
          (CBoatSailState *this,CBoatSail *param_1,float param_2,float param_3,float param_4,
          CMwId *param_5,float param_6)
{
{
  CBoatSail *this_00;
  float fVar1;
  float unaff_ESI;
  float fVar2;
  float fVar3;
  CBoatSailState *pCVar4;
  
  this_00 = *(CBoatSail **)(this + 0x14);
  if (*(int *)(*(int *)(this_00 + 0x14) + 0xbc) != 0) {
    fVar2 = CBoatSail::HeelGet(this_00,param_1,param_2,param_3,(float)(this + 0x94),
                               *(CMwId **)(this + 0x84),unaff_ESI);
    return fVar2;
  }
  pCVar4 = this;
  CBoatParam::OldHeelGet
            (*(CBoatParam **)(this_00 + 0x14),(CBoatParam *)this_00,*(CBoatSail **)(this + 0x7c),
             (int)param_2,(float)param_1,unaff_ESI);
  fVar3 = OldHeelCoefGet(this,(CBoatSailState *)param_2,param_3,param_4,(float)pCVar4);
  fVar3 = fVar3 * (float)param_1;
  fVar1 = -*(float *)(*(int *)(*(int *)(this + 0x14) + 0x14) + 0x78);
  fVar2 = *(float *)(*(int *)(*(int *)(this + 0x14) + 0x14) + 0x78);
  if ((fVar1 < fVar3) && (fVar1 = fVar2, fVar2 < fVar3 == (fVar2 == fVar3))) {
    return fVar3;
  }
  return fVar1;
}
}

// =================================================
// Function: CBoatSailState::OldHeelCoefGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CBoatSailState::OldHeelCoefGet
          (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float unaff_ESI;
  float fVar4;
  CMwId *unaff_retaddr;
  
  fVar3 = param_4;
  fVar4 = OptimalSailAngleGet(this,(CBoatSail *)param_1,param_3,unaff_ESI,unaff_retaddr);
  fVar1 = *(float *)(this + 0x84);
  fVar2 = (float)_DAT_00b36be8;
  if (0.0 <= fVar1) {
    if (fVar4 <= fVar1) {
      if (ABS(-param_4 - fVar4) <= _DAT_00baab3c) {
        param_4 = 0.0;
      }
      else {
        param_4 = 1.0 - (fVar1 - fVar4) / (-param_4 - fVar4);
      }
    }
    else {
      param_4 = ((fVar4 - fVar1) * (float)_DAT_00b40f28) / fVar2 + 1.0;
    }
    fVar1 = fVar1 - ((float)_DAT_00b36110 - fVar3);
    if (fVar1 <= (float)_DAT_00b36110) {
      if (fVar1 < (float)_DAT_00b5b918) {
        fVar1 = fVar1 + (float)_DAT_00b59bb8;
      }
    }
    else {
      fVar1 = fVar1 - (float)_DAT_00b59bb8;
    }
    if (fVar1 < 0.0) {
      fVar1 = -fVar1;
    }
    if (fVar2 <= fVar1) {
      fVar1 = fVar1 - fVar2;
    }
    else {
      fVar1 = fVar2 - fVar1;
    }
    return ((float)_DAT_00b313b8 + (1.0 - (fVar1 / fVar2) * (fVar1 / fVar2)) * (float)_DAT_00b313b8)
           * param_4;
  }
  if (fVar1 <= fVar4) {
    if (fVar4 + param_4 == 0.0) {
      param_4 = 0.0;
    }
    else {
      param_4 = 1.0 - -(fVar1 - fVar4) / (fVar4 + param_4);
    }
  }
  else {
    param_4 = ((fVar4 - fVar1) * (float)_DAT_00b9fe48) / fVar2 + 1.0;
  }
  fVar1 = fVar1 - ((float)_DAT_00b36110 - fVar3);
  if (fVar1 <= (float)_DAT_00b36110) {
    if (fVar1 < (float)_DAT_00b5b918) {
      fVar1 = fVar1 + (float)_DAT_00b59bb8;
    }
  }
  else {
    fVar1 = fVar1 - (float)_DAT_00b59bb8;
  }
  if (fVar1 < 0.0) {
    fVar1 = -fVar1;
  }
  if (fVar2 <= fVar1) {
    fVar1 = fVar1 - fVar2;
  }
  else {
    fVar1 = fVar2 - fVar1;
  }
  return ((float)_DAT_00b313b8 + (1.0 - (fVar1 / fVar2) * (fVar1 / fVar2)) * (float)_DAT_00b313b8) *
         param_4;
}
}

// =================================================
// Function: CBoatSailState::OptimalSailAngleGet
// =================================================
float __thiscall
CBoatSailState::OptimalSailAngleGet
          (CBoatSailState *this,CBoatSail *param_1,float param_2,float param_3,CMwId *param_4)
{
{
  float fVar1;
  CMwId *unaff_retaddr;
  
  if (*(int *)(*(int *)(*(CBoatSail **)(this + 0x14) + 0x14) + 0xbc) != 0) {
    fVar1 = CBoatSail::OptimalSailAngleGet
                      (*(CBoatSail **)(this + 0x14),param_1,param_2,(float)(this + 0x94),
                       unaff_retaddr);
    return fVar1;
  }
  return *(float *)(this + 0x6c);
}
}

// =================================================
// Function: CBoatSailState::SheetTargetNormedAngleSet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CBoatSailState::SheetTargetNormedAngleSet
          (CBoatSailState *this,CBoatSailState *param_1,int param_2,float param_3)
{
{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(*(int *)(this + 0x14) + 0x5c);
  fVar2 = _DAT_00b2c060;
  if (param_1 == (CBoatSailState *)0x0) {
    fVar2 = 1.0;
  }
  *(float *)(this + 0x80) =
       (fVar1 + (float)param_2 * (*(float *)(*(int *)(this + 0x14) + 0x60) - fVar1)) * fVar2;
  return;
}
}

// =================================================
// Function: CBoatSailState::ShowVisibleTrees
// =================================================
void __thiscall
CBoatSailState::ShowVisibleTrees
          (CBoatSailState *this,CBoatSailState *param_1,int param_2,int param_3)
{
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(this + 0x18);
  if ((iVar1 != 0) && (param_1 != (CBoatSailState *)0x0)) {
    uVar2 = *(uint *)(iVar1 + 0x9c) | 0x4000;
    *(uint *)(iVar1 + 0x9c) = (uVar2 >> 0xb ^ uVar2) & 8 ^ uVar2;
  }
  iVar1 = *(int *)(this + 0x1c);
  if (((iVar1 != 0) && (param_1 != (CBoatSailState *)0x0)) && (param_2 == 0)) {
    uVar2 = *(uint *)(iVar1 + 0x9c) | 0x4000;
    *(uint *)(iVar1 + 0x9c) = (uVar2 >> 0xb ^ uVar2) & 8 ^ uVar2;
  }
  iVar1 = *(int *)(this + 0x20);
  if (((iVar1 != 0) && (param_1 != (CBoatSailState *)0x0)) && (param_2 != 0)) {
    uVar2 = *(uint *)(iVar1 + 0x9c) | 0x4000;
    *(uint *)(iVar1 + 0x9c) = (uVar2 >> 0xb ^ uVar2) & 8 ^ uVar2;
  }
  return;
}
}

// =================================================
// Function: CBoatSailState::UpdateAsync
// =================================================
void __thiscall CBoatSailState::UpdateAsync(CBoatSailState *this,CInputPortDx8 *param_1)
{
{
  float fVar1;
  int iVar2;
  CMwNodRef<class_CGameCamera> *pCVar3;
  CBoatSailState *pCVar4;
  float unaff_ESI;
  int unaff_EDI;
  float unaff_retaddr;
  CBoatSailState *in_stack_0000000c;
  float in_stack_00000010;
  CBoatSailState *in_stack_00000014;
  float in_stack_00000018;
  
  iVar2 = *(int *)(this + 0x8c);
  ShowVisibleTrees(this,(CBoatSailState *)(uint)(iVar2 != 5),(int)in_stack_00000014,unaff_EDI);
  if ((CBoatSailState *)(uint)(iVar2 != 5) != (CBoatSailState *)0x0) {
    UpdateRotationAsync(this,*(CBoatSailState **)(this + 0x9c),*(float *)(this + 0xa0),unaff_ESI);
    UpdateShiverAndBulgeAsync
              (this,in_stack_0000000c,in_stack_00000010,(float)in_stack_00000014,in_stack_00000018,
               unaff_retaddr);
    in_stack_0000000c = in_stack_00000014;
  }
  fVar1 = 0.0;
  switch(*(undefined4 *)(this + 0x8c)) {
  case 0:
    switch(*(undefined4 *)(*(int *)(this + 0x14) + 0x18)) {
    case 1:
    case 3:
    case 4:
      goto switchD_0082e439_caseD_1;
    case 2:
    case 5:
switchD_0082e439_caseD_2:
      UpdateHaulUpSpi(this,in_stack_0000000c,in_stack_00000018,fVar1,(float)param_1);
    default:
      break;
    }
  case 1:
    switch(*(undefined4 *)(*(int *)(this + 0x14) + 0x18)) {
    case 1:
    case 3:
    case 4:
      fVar1 = *(float *)(this + 0x90);
      break;
    case 2:
    case 5:
      fVar1 = *(float *)(this + 0x90);
      goto switchD_0082e439_caseD_2;
    default:
      goto switchD_0082e344_default;
    }
switchD_0082e439_caseD_1:
    UpdateHaulUpFrontSail(this,in_stack_0000000c,in_stack_00000018,fVar1,(float)param_1);
    break;
  case 2:
  case 3:
    switch(*(undefined4 *)(*(int *)(this + 0x14) + 0x18)) {
    case 0:
      UpdateGeometryMainSail(this,in_stack_0000000c,in_stack_00000018,(float)param_1);
      break;
    case 1:
    case 3:
    case 4:
      UpdateGeometryFrontSail(this,in_stack_0000000c,in_stack_00000018,(float)param_1);
      break;
    case 2:
      UpdateGeometrySpi(this,in_stack_0000000c,in_stack_00000018,(float)param_1);
      break;
    case 5:
      UpdateGeometrySpiAsym(this,in_stack_0000000c,in_stack_00000018,(float)param_1);
    }
    break;
  case 4:
    switch(*(undefined4 *)(*(int *)(this + 0x14) + 0x18)) {
    case 1:
    case 3:
    case 4:
      UpdateHaulDownFrontSail
                (this,in_stack_0000000c,in_stack_00000018,*(float *)(this + 0x90),(float)param_1);
      break;
    case 2:
    case 5:
      UpdateHaulDownSpi(this,in_stack_0000000c,in_stack_00000018,*(float *)(this + 0x90),
                        (float)param_1);
    }
  }
switchD_0082e344_default:
  if ((*(int *)(this + 0x34) != 0) && (*(int *)(this + 0x30) != 0)) {
    pCVar4 = this + 0x30;
    if (0.0 < in_stack_00000018) {
      pCVar4 = this + 0x34;
    }
    pCVar3 = *(CMwNodRef<class_CGameCamera> **)pCVar4;
    if ((pCVar3 != (CMwNodRef<class_CGameCamera> *)0x0) &&
       (*(CMwNodRef<class_CGameCamera> **)(*(int *)(this + 0x24) + 0x98) != pCVar3)) {
      CMwNodRef<class_CGameCamera>::MwSetNod
                ((void *)(*(int *)(this + 0x24) + 0x98),pCVar3,(CGameCamera *)param_1);
    }
  }
  return;
}
}

// =================================================
// Function: CBoatSailState::UpdateGeometryFrontSail
// =================================================
void __thiscall
CBoatSailState::UpdateGeometryFrontSail
          (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3)
{
{
  CBoatSailState *this_00;
  GmVec3 *unaff_EBX;
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  CPlugVisual *pCVar1;
  float *in_stack_ffffffd8;
  undefined1 local_c [12];
  
  if (*(int *)(this + 0x24) != 0) {
    pCVar1 = *(CPlugVisual **)(this + 0xa8);
    GetVisualExtents(pCVar1,(float)local_c,unaff_EDI,unaff_EBX,unaff_ESI,in_stack_ffffffd8);
    ResetSailVisualToBase(*(CPlugVisual **)(this + 0x24),pCVar1);
    UpdateGeometryFrontSail
              (this_00,*(CBoatSailState **)(this + 0x24),*(float *)(this + 0xac),
               (float)in_stack_ffffffd8);
    (**(code **)(**(int **)(this + 0x18) + 0xbc))(0);
  }
  return;
}
}

// =================================================
// Function: CBoatSailState::UpdateGeometryMainSail
// =================================================
void __thiscall
CBoatSailState::UpdateGeometryMainSail
          (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3)
{
{
  CBoatSailState *this_00;
  GmVec3 *unaff_EBX;
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  CPlugVisual *pCVar1;
  float *in_stack_ffffffd8;
  undefined1 local_18 [24];
  
  if (*(int *)(this + 0x24) != 0) {
    pCVar1 = *(CPlugVisual **)(this + 0xa8);
    GetVisualExtents(pCVar1,(float)local_18,unaff_EDI,unaff_EBX,unaff_ESI,in_stack_ffffffd8);
    ResetSailVisualToBase(*(CPlugVisual **)(this + 0x24),pCVar1);
    UpdateGeometryMainSail
              (this_00,*(CBoatSailState **)(this + 0x24),*(float *)(this + 0xac),
               (float)in_stack_ffffffd8);
    (**(code **)(**(int **)(this + 0x18) + 0xbc))(0);
  }
  return;
}
}

// =================================================
// Function: CBoatSailState::UpdateGeometrySpi
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CBoatSailState::UpdateGeometrySpi
          (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3)
{
{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  GmVec3 *unaff_EBX;
  float *unaff_EBP;
  int iVar9;
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  float10 extraout_ST0;
  float fVar10;
  CPlugVisual *local_98;
  float fStack_94;
  float fStack_90;
  float local_8c;
  float fStack_88;
  uint local_84;
  CBoatSailState *local_80;
  float fStack_7c;
  uint uStack_78;
  int *local_74;
  CPlugVisual *local_70;
  uint uStack_6c;
  float fStack_68;
  float fStack_64;
  float local_60;
  int iStack_5c;
  undefined4 uStack_58;
  int *local_54;
  int iStack_50;
  int *local_4c;
  int iStack_48;
  float local_44;
  float fStack_40;
  float local_3c;
  float local_38;
  float local_34;
  float fStack_2c;
  float local_28;
  undefined4 uStack_24;
  float local_1c;
  float local_18;
  float local_c;
  float local_8;
  
  if (((*(int *)(this + 0x24) != 0) && (*(int *)(this + 0x28) != 0)) && (*(int *)(this + 0x2c) != 0)
     ) {
    local_80 = this;
    fVar10 = GmFunc::Mod(param_2,_DAT_00b5b910,_DAT_00baab40);
    local_84 = (uint)(_DAT_00c418e0 <= fVar10);
    local_98 = (CPlugVisual *)ABS(*(float *)(this + 0xa8));
    local_70 = local_98;
    GetVisualExtents(local_98,(float)&local_1c,unaff_EDI,unaff_EBX,unaff_ESI,unaff_EBP);
    if (local_84 == 0) {
      local_8c = local_c - local_38 * *(float *)(this + 0xa4);
    }
    else {
      local_8c = local_1c + local_38 * *(float *)(this + 0xa4);
    }
    piVar6 = *(int **)(this + 0x2c);
    piVar7 = *(int **)(this + 0x24);
    fVar10 = (float)_DAT_00b313b8;
    piVar8 = *(int **)(this + 0x28);
    local_3c = (local_1c + local_c) * fVar10;
    local_44 = (local_18 + local_8) * fVar10;
    local_98 = (CPlugVisual *)(fVar10 * local_34);
    local_60 = 1.0 / ((float)local_98 * (float)local_98);
    local_28 = local_38 * (float)_DAT_00b362c0;
    local_74 = piVar7;
    local_54 = piVar8;
    local_4c = piVar6;
    uStack_58 = (**(code **)(*piVar6 + 0x8c))();
    uStack_24 = (**(code **)(*piVar8 + 0x8c))();
    local_98 = (CPlugVisual *)(**(code **)(*piVar7 + 0x8c))();
    while (local_98 != (CPlugVisual *)0xffffffff) {
      (**(code **)(*piVar7 + 0x90))(&local_98,&uStack_6c,&iStack_50);
      (**(code **)(*piVar6 + 0x90))(&fStack_64,&fStack_2c,&local_54);
      (**(code **)(*piVar8 + 0x90))(&local_3c,&local_28,&local_74);
      uStack_78 = 0;
      if (uStack_6c != 0) {
        iVar9 = 0;
        do {
          fStack_64 = *(float *)(iStack_48 + iVar9);
          fStack_68 = *(float *)(iStack_48 + 4 + iVar9);
          iVar1 = iStack_48 + iVar9;
          pfVar2 = (float *)(iStack_5c + iVar9);
          fVar10 = *(float *)(iVar1 + 8);
          pfVar3 = (float *)(iStack_50 + iVar9);
          fStack_7c = *pfVar2;
          fStack_40 = pfVar2[1];
          fStack_2c = pfVar2[2];
          fStack_90 = fStack_64 + *(float *)(local_80 + 0xac);
          if (local_84 == 0) {
            if (fStack_64 <= local_8c) {
LAB_0082d271:
              fStack_94 = 0.0;
            }
            else {
              fStack_94 = (fStack_64 - local_8c) / local_38;
            }
          }
          else {
            if (local_8c <= fStack_64) goto LAB_0082d271;
            fStack_94 = (local_8c - fStack_64) / local_38;
          }
          fStack_88 = fStack_94 * (1.0 - (fStack_68 - local_44) * (fStack_68 - local_44) * local_60)
          ;
          __CIsin();
          fStack_90 = fStack_88 * *(float *)(*(int *)(local_80 + 0x14) + 0x94) * (float)extraout_ST0
                      * local_28;
          fStack_7c = (float)local_70 * (fStack_7c - fStack_64) + fStack_64;
          *pfVar3 = fStack_7c + (local_3c - fStack_7c) * (float)_DAT_00b313b8 * fStack_88;
          pfVar3[1] = fStack_68 + (float)local_70 * (fStack_40 - fStack_68);
          pfVar3[2] = fVar10 + (float)local_70 * (fStack_2c - fVar10) + fStack_90;
          pfVar3[3] = pfVar2[3] - *(float *)(iVar1 + 0xc);
          pfVar3[4] = pfVar2[4] - *(float *)(iVar1 + 0x10);
          pfVar3[5] = pfVar2[5] - *(float *)(iVar1 + 0x14);
          fVar10 = pfVar3[3];
          pfVar3[3] = fVar10 * (float)local_70;
          fVar4 = pfVar3[4];
          pfVar3[4] = (float)local_70 * fVar4;
          fVar5 = pfVar3[5];
          pfVar3[5] = fVar5 * (float)local_70;
          pfVar3[3] = *(float *)(iVar1 + 0xc) + fVar10 * (float)local_70;
          uStack_78 = uStack_78 + 1;
          iVar9 = iVar9 + 0x28;
          pfVar3[4] = *(float *)(iVar1 + 0x10) + (float)local_70 * fVar4;
          pfVar3[5] = fVar5 * (float)local_70 + *(float *)(iVar1 + 0x14);
          piVar6 = local_4c;
          piVar7 = local_74;
          piVar8 = local_54;
          this = local_80;
        } while (uStack_78 < uStack_6c);
      }
    }
    (**(code **)(**(int **)(this + 0x18) + 0xbc))(1);
  }
  return;
}
}

// =================================================
// Function: CBoatSailState::UpdateGeometrySpiAsym
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CBoatSailState::UpdateGeometrySpiAsym
          (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3)
{
{
  float *pfVar1;
  float *pfVar2;
  int *piVar3;
  float fVar4;
  int iVar5;
  GmVec3 *unaff_EBX;
  int iVar6;
  GmVec3 *unaff_EBP;
  GmVec3 *unaff_ESI;
  GmMat3 *unaff_EDI;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar7;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float fStack_64;
  float fStack_60;
  float local_5c;
  float local_58;
  undefined4 uStack_54;
  float local_50;
  float fStack_4c;
  float fStack_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float local_18;
  float local_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  undefined1 auStack_4 [4];
  
  iVar5 = *(int *)(this + 0x28);
  if ((iVar5 != 0) && (piVar3 = *(int **)(this + 0x24), piVar3 != (int *)0x0)) {
    local_18 = *(float *)(iVar5 + 0x40);
    local_14 = *(float *)(iVar5 + 0x44);
    local_10 = *(float *)(iVar5 + 0x48);
    local_50 = local_10 + local_10;
    fVar4 = (float)param_1 * (float)_DAT_00b5b9c0;
    local_5c = DAT_00b36188;
    if ((fVar4 < DAT_00b36188 == (fVar4 == DAT_00b36188)) &&
       (local_5c = fVar4, _DAT_00b3d620 < fVar4 != (_DAT_00b3d620 == fVar4))) {
      local_5c = _DAT_00b3d620;
    }
    local_5c = local_5c / (float)_DAT_00b508a0;
    __CIsin();
    local_44 = (float)extraout_ST0;
    __CIcos();
    local_40 = (float)extraout_ST0_00;
    local_30 = local_44;
    local_3c = local_44;
    local_2c = 0.0;
    local_38 = 0.0;
    local_34 = local_40;
    local_28 = local_40;
    GmVec3::MultTranspose(&local_3c,(GmMat3 *)(*(int *)(this + 0x18) + 0x5c),unaff_EDI);
    iVar5 = *(int *)(this + 0x14);
    local_34 = local_34 * (float)_DAT_00b313b8;
    local_30 = ((float)_DAT_00b313b8 / *(float *)(iVar5 + 0x74)) * local_30;
    if (_DAT_00d0f8c8 < local_38 * local_38 + local_34 * local_34 + local_30 * local_30) {
      fVar7 = (float10)func_0x009c1b40();
      fVar4 = 1.0 / (float)fVar7;
      local_38 = fVar4 * local_38;
      local_34 = fVar4 * local_34;
      local_30 = fVar4 * local_30;
    }
    fVar4 = *(float *)(iVar5 + 0x70) * local_58;
    local_38 = fVar4 * local_38;
    local_34 = fVar4 * local_34;
    local_30 = fVar4 * local_30;
    fStack_60 = *(float *)(this + 0xa4) * (float)_DAT_00ba79c8;
    iVar5 = (**(code **)(*piVar3 + 0x8c))();
    uStack_54 = (**(code **)(**(int **)(this + 0x28) + 0x8c))();
    while (iVar5 != -1) {
      (**(code **)(**(int **)(this + 0x28) + 0x90))(&uStack_54,&local_40,&param_3);
      (**(code **)(**(int **)(this + 0x24) + 0x90))(auStack_4,&fStack_64,&local_5c);
      local_14 = *(float *)param_3;
      iVar6 = 0;
      local_10 = *(float *)((int)param_3 + 4);
      local_5c = 0.0;
      fStack_c = *(float *)((int)param_3 + 8);
      fStack_20 = *(float *)param_3;
      fStack_1c = *(float *)((int)param_3 + 4);
      local_18 = *(float *)((int)param_3 + 8);
      if (local_58 != 0.0) {
        local_44 = local_34 + (float)_PTR_00b2c178;
        do {
          pfVar1 = (float *)(iVar6 + (int)param_3);
          pfVar2 = (float *)(iVar6 + (int)local_50);
          fStack_64 = (*(float *)(iVar6 + 8 + (int)param_3) * (float)_DAT_00b32ea0) / fStack_4c +
                      *(float *)(this + 0xac);
          __CIcos();
          fStack_48 = (float)extraout_ST0_01;
          fStack_8 = fStack_48 * fStack_60;
          __CIsin();
          fStack_48 = (float)extraout_ST0_02;
          local_2c = fStack_8 + local_38;
          local_28 = local_44;
          fStack_24 = fStack_48 * fStack_60 * (float)_DAT_00b362c0 + local_30;
          UpdateGeometrySpiAsym_MoveVertex(unaff_EBX,unaff_ESI,unaff_EBP);
          fStack_48 = *pfVar1;
          pfVar2[3] = pfVar1[3];
          pfVar2[4] = pfVar1[4];
          local_2c = fStack_48 * local_2c;
          pfVar2[5] = pfVar1[5];
          local_28 = local_28 * fStack_48;
          fStack_24 = fStack_48 * fStack_24;
          if (*pfVar2 < local_14) {
            local_14 = *pfVar2;
          }
          if (pfVar2[1] < local_10) {
            local_10 = pfVar2[1];
          }
          if (pfVar2[2] < fStack_c) {
            fStack_c = pfVar2[2];
          }
          if (fStack_20 < *pfVar2) {
            fStack_20 = *pfVar2;
          }
          if (fStack_1c < pfVar2[1]) {
            fStack_1c = pfVar2[1];
          }
          if (local_18 < pfVar2[2]) {
            local_18 = pfVar2[2];
          }
          local_5c = (float)((int)local_5c + 1);
          iVar6 = iVar6 + 0x28;
        } while ((uint)local_5c < (uint)local_58);
      }
    }
    CPlugVisual::SetBoundingMinMax
              (*(CPlugVisual **)(this + 0x24),(CPlugVisual *)&local_14,(GmVec3 *)&fStack_20,
               unaff_ESI);
    (**(code **)(**(int **)(this + 0x24) + 0x120))();
  }
  return;
}
}

// =================================================
// Function: CBoatSailState::UpdateHaulDownFrontSail
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CBoatSailState::UpdateHaulDownFrontSail
          (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4)
{
{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int *piVar5;
  float *pfVar6;
  float *unaff_EBX;
  GmVec3 *unaff_EBP;
  uint uVar7;
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  int iVar8;
  float10 extraout_ST0;
  float fStack_58;
  uint uStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  GxVertex *local_48;
  float local_44;
  int *local_40;
  int *local_3c;
  float local_38;
  float fStack_34;
  float fStack_30;
  float afStack_2c [3];
  float local_20;
  float local_1c;
  float fStack_10;
  undefined1 local_c [4];
  float fStack_8;
  
  if ((*(int *)(this + 0x24) != 0) && (*(int *)(this + 0x28) != 0)) {
    GetVisualExtents(*(CPlugVisual **)(this + 0xa8),(float)local_c,unaff_EDI,unaff_ESI,unaff_EBP,
                     unaff_EBX);
    local_38 = local_20 * (float)_DAT_00b87260;
    piVar4 = *(int **)(this + 0x28);
    piVar5 = *(int **)(this + 0x24);
    local_48 = (GxVertex *)(1.0 / local_1c);
    local_40 = piVar5;
    local_3c = piVar4;
    uStack_4c = (**(code **)(*piVar4 + 0x8c))();
    if (*(int *)(*(int *)(this + 0x14) + 0x8c) == 0) {
      fStack_50 = local_20 * param_3 + fStack_8;
      fStack_58 = (float)(**(code **)(*piVar5 + 0x8c))();
      while (fStack_58 != -NAN) {
        (**(code **)(*piVar5 + 0x90))(&fStack_58,&uStack_54,afStack_2c);
        (**(code **)(*piVar4 + 0x90))(&fStack_58,&fStack_34,&local_3c);
        uVar7 = 0;
        if (uStack_54 != 0) {
          iVar8 = 0;
          do {
            fVar3 = *(float *)((int)fStack_30 + 4 + iVar8);
            pfVar6 = (float *)((int)fStack_30 + iVar8);
            pfVar1 = (float *)(iVar8 + (int)afStack_2c[0]);
            if (fStack_50 < fVar3 == (fStack_50 == fVar3)) {
              __CIsin();
              *pfVar1 = (float)extraout_ST0 * local_38;
              fVar3 = (*(float *)(*(int *)(this + 0x14) + 0x90) + fStack_8) -
                      pfVar1[2] * (float)_DAT_00b4fbd0;
            }
            else {
              fVar2 = pfVar6[2];
              *pfVar1 = *pfVar6;
              pfVar1[1] = pfVar6[1];
              fStack_34 = (float)local_48 * (fStack_10 - fVar2);
              pfVar1[2] = pfVar6[2];
              MoveVertexFrontSail(local_48,fStack_34,*(float *)(this + 0xac),local_44,
                                  *(float *)(*(int *)(this + 0x14) + 0x94),*(float *)(this + 0xa4),
                                  (float)unaff_EDI);
              fVar3 = fVar3 - fStack_50;
            }
            uVar7 = uVar7 + 1;
            pfVar1[1] = fVar3;
            iVar8 = iVar8 + 0x28;
            piVar4 = local_3c;
            piVar5 = local_40;
          } while (uVar7 < uStack_54);
        }
      }
    }
    else {
      fStack_58 = fStack_10 - local_1c * param_3;
      fStack_50 = (float)(**(code **)(*piVar5 + 0x8c))();
      while (fStack_50 != -NAN) {
        (**(code **)(*piVar5 + 0x90))(&fStack_50,&uStack_54,&local_38);
        (**(code **)(*piVar4 + 0x90))(&fStack_58,&fStack_34,&local_40);
        uVar7 = 0;
        if (uStack_54 != 0) {
          iVar8 = 0;
          fVar3 = fStack_58;
          do {
            fStack_30 = *(float *)((int)fStack_34 + iVar8);
            pfVar6 = (float *)((int)fStack_34 + iVar8);
            afStack_2c[0] = pfVar6[1];
            pfVar1 = (float *)(iVar8 + (int)local_38);
            fVar2 = pfVar6[2];
            if (fVar2 < fVar3 == (fVar2 == fVar3)) {
              *pfVar1 = fStack_30;
              pfVar1[1] = afStack_2c[0];
              fVar2 = fStack_10;
            }
            else {
              *pfVar1 = *pfVar6;
              pfVar1[1] = pfVar6[1];
              pfVar1[2] = pfVar6[2];
              fStack_30 = (float)local_48 * (fVar3 - fVar2);
              MoveVertexFrontSail(local_48,fStack_30,*(float *)(this + 0xac),local_44,
                                  *(float *)(*(int *)(this + 0x14) + 0x94),*(float *)(this + 0xa4),
                                  (float)unaff_EDI);
              fVar3 = fStack_58;
              fVar2 = fVar2 - fStack_58;
            }
            uVar7 = uVar7 + 1;
            pfVar1[2] = fVar2;
            iVar8 = iVar8 + 0x28;
            piVar4 = local_3c;
            piVar5 = local_40;
          } while (uVar7 < uStack_54);
        }
      }
    }
    (**(code **)(**(int **)(this + 0x18) + 0xbc))(1);
  }
  return;
}
}

// =================================================
// Function: CBoatSailState::UpdateHaulDownSpi
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CBoatSailState::UpdateHaulDownSpi
          (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4)
{
{
  float *pfVar1;
  int *piVar2;
  int *piVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  float unaff_EBP;
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  int iVar7;
  float10 fVar8;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  GmVec3 *in_stack_ffffff78;
  float *in_stack_ffffff7c;
  float fVar9;
  uint uStack_74;
  int iStack_70;
  int *local_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  undefined4 uStack_50;
  float fStack_4c;
  float fStack_48;
  float local_44;
  float fStack_40;
  int iStack_3c;
  float fStack_38;
  int *local_34;
  int iStack_30;
  undefined4 uStack_2c;
  float fStack_28;
  undefined1 local_24 [4];
  float local_20;
  undefined1 local_18 [4];
  float local_14;
  
  if ((*(int *)(this + 0x24) != 0) && (*(int *)(this + 0x28) != 0)) {
    if (*(int *)(*(int *)(this + 0x14) + 0x18) == 2) {
      UpdateGeometrySpi(this,param_1,param_2,unaff_EBP);
    }
    else if (*(int *)(*(int *)(this + 0x14) + 0x18) == 5) {
      UpdateGeometrySpiAsym(this,param_1,param_2,unaff_EBP);
    }
    GetVisualExtents(*(CPlugVisual **)(this + 0xa8),(float)local_24,unaff_EDI,unaff_ESI,
                     in_stack_ffffff78,in_stack_ffffff7c);
    piVar2 = *(int **)(this + 0x28);
    local_44 = (float)_DAT_00b30a10 * local_14;
    piVar3 = *(int **)(this + 0x24);
    fVar5 = local_14 * param_4 + local_20;
    local_6c = piVar3;
    local_34 = piVar2;
    uStack_2c = (**(code **)(*piVar2 + 0x8c))();
    iStack_70 = (**(code **)(*piVar3 + 0x8c))();
    while (iStack_70 != -1) {
      (**(code **)(*piVar3 + 0x90))(&iStack_70,&uStack_74,&iStack_30);
      (**(code **)(*piVar2 + 0x90))(&fStack_38,local_18,&fStack_48);
      uVar6 = 0;
      if (uStack_74 != 0) {
        fVar8 = (float10)func_0x009c2390();
        fStack_28 = (float)fVar8;
        iVar7 = 0;
        do {
          pfVar1 = (float *)(iVar7 + iStack_30);
          fStack_4c = *(float *)(iVar7 + 4 + iStack_3c);
          uStack_50 = *(undefined4 *)(iVar7 + iStack_3c);
          fStack_48 = *(float *)(iVar7 + 8 + iStack_3c);
          fStack_58 = pfVar1[1];
          fStack_54 = pfVar1[2];
          fStack_5c = *pfVar1;
          if (fStack_4c <= fVar5) {
            fStack_68 = (float)_DAT_00b362c0 * 0.0;
            fStack_64 = *(float *)(*(int *)(this + 0x14) + 0x90) + local_20;
            __CIsin();
            fStack_60 = (float)extraout_ST0_01 * local_44;
          }
          else {
            __CIatan();
            fStack_38 = (float)extraout_ST0 * (float)_DAT_00baac20;
            fVar4 = (fStack_4c - fVar5) / local_14;
            fVar9 = 1.0 - fVar4;
            __CIsin();
            fStack_40 = (float)extraout_ST0_00;
            fVar9 = *(float *)(*(int *)(this + 0x14) + 0x94) * fStack_38 * fVar9;
            fStack_68 = fVar4 * (fStack_5c - 0.0) + 0.0 +
                        ((fStack_40 + fStack_40) - (float)_DAT_00b541b8 * 0.0) * fVar9;
            fStack_64 = (fStack_4c + local_20) - fVar5;
            fStack_60 = fVar9 * (fStack_40 + fStack_40) +
                        fStack_48 + (fStack_54 - fStack_48) * fVar4;
          }
          uVar6 = uVar6 + 1;
          iVar7 = iVar7 + 0x28;
          *pfVar1 = fStack_28 * (fStack_68 - fStack_5c) + fStack_5c;
          pfVar1[1] = fStack_58 + (fStack_64 - fStack_58) * fStack_28;
          pfVar1[2] = fStack_54 + fStack_28 * (fStack_60 - fStack_54);
          piVar2 = local_34;
          piVar3 = local_6c;
        } while (uVar6 < uStack_74);
      }
    }
    (**(code **)(**(int **)(this + 0x18) + 0xbc))(1);
  }
  return;
}
}

// =================================================
// Function: CBoatSailState::UpdateHaulUpFrontSail
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CBoatSailState::UpdateHaulUpFrontSail
          (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4)
{
{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int *piVar5;
  float *pfVar6;
  float *unaff_EBX;
  GmVec3 *unaff_EBP;
  uint uVar7;
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  int iVar8;
  float10 extraout_ST0;
  float fStack_58;
  uint uStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  GxVertex *local_48;
  float local_44;
  int *local_40;
  int *local_3c;
  float local_38;
  float fStack_34;
  float fStack_30;
  float afStack_2c [3];
  float local_20;
  float local_1c;
  float fStack_14;
  float fStack_10;
  undefined1 local_c [4];
  float fStack_8;
  float fStack_4;
  
  if ((*(int *)(this + 0x24) != 0) && (*(int *)(this + 0x28) != 0)) {
    GetVisualExtents(*(CPlugVisual **)(this + 0xa8),(float)local_c,unaff_EDI,unaff_ESI,unaff_EBP,
                     unaff_EBX);
    local_38 = local_20 * (float)_DAT_00b87260;
    piVar4 = *(int **)(this + 0x28);
    piVar5 = *(int **)(this + 0x24);
    local_48 = (GxVertex *)(1.0 / local_1c);
    local_40 = piVar5;
    local_3c = piVar4;
    uStack_4c = (**(code **)(*piVar4 + 0x8c))();
    if (*(int *)(*(int *)(this + 0x14) + 0x8c) == 0) {
      fStack_50 = fStack_14 - local_20 * param_3;
      fStack_58 = (float)(**(code **)(*piVar5 + 0x8c))();
      while (fStack_58 != -NAN) {
        (**(code **)(*piVar5 + 0x90))(&fStack_58,&uStack_54,afStack_2c);
        (**(code **)(*piVar4 + 0x90))(&fStack_58,&fStack_34,&local_3c);
        uVar7 = 0;
        if (uStack_54 != 0) {
          iVar8 = 0;
          do {
            fVar3 = *(float *)((int)fStack_30 + 4 + iVar8);
            pfVar6 = (float *)((int)fStack_30 + iVar8);
            pfVar1 = (float *)(iVar8 + (int)afStack_2c[0]);
            if (fStack_50 < fVar3 == (fStack_50 == fVar3)) {
              __CIsin();
              *pfVar1 = (float)extraout_ST0 * local_38;
              fVar3 = (*(float *)(*(int *)(this + 0x14) + 0x90) + fStack_8) -
                      pfVar1[2] * (float)_DAT_00b4fbd0;
            }
            else {
              fVar2 = pfVar6[2];
              *pfVar1 = *pfVar6;
              pfVar1[1] = pfVar6[1];
              fStack_34 = (float)local_48 * (fStack_10 - fVar2);
              pfVar1[2] = pfVar6[2];
              MoveVertexFrontSail(local_48,fStack_34,*(float *)(this + 0xac),local_44,
                                  *(float *)(*(int *)(this + 0x14) + 0x94),*(float *)(this + 0xa4),
                                  (float)unaff_EDI);
              fVar3 = fVar3 - fStack_50;
            }
            uVar7 = uVar7 + 1;
            pfVar1[1] = fVar3;
            iVar8 = iVar8 + 0x28;
            piVar4 = local_3c;
            piVar5 = local_40;
          } while (uVar7 < uStack_54);
        }
      }
    }
    else {
      fStack_58 = local_1c * param_3 + fStack_4;
      fStack_50 = (float)(**(code **)(*piVar5 + 0x8c))();
      while (fStack_50 != -NAN) {
        (**(code **)(*piVar5 + 0x90))(&fStack_50,&uStack_54,&local_38);
        (**(code **)(*piVar4 + 0x90))(&fStack_58,&fStack_34,&local_40);
        uVar7 = 0;
        if (uStack_54 != 0) {
          iVar8 = 0;
          fVar3 = fStack_58;
          do {
            fStack_30 = *(float *)((int)fStack_34 + iVar8);
            pfVar6 = (float *)((int)fStack_34 + iVar8);
            afStack_2c[0] = pfVar6[1];
            pfVar1 = (float *)(iVar8 + (int)local_38);
            fVar2 = pfVar6[2];
            if (fVar2 < fVar3 == (fVar2 == fVar3)) {
              *pfVar1 = fStack_30;
              pfVar1[1] = afStack_2c[0];
              fVar2 = fStack_10;
            }
            else {
              *pfVar1 = *pfVar6;
              pfVar1[1] = pfVar6[1];
              pfVar1[2] = pfVar6[2];
              fStack_30 = (float)local_48 * (fVar3 - fVar2);
              MoveVertexFrontSail(local_48,fStack_30,*(float *)(this + 0xac),local_44,
                                  *(float *)(*(int *)(this + 0x14) + 0x94),*(float *)(this + 0xa4),
                                  (float)unaff_EDI);
              fVar3 = fStack_58;
              fVar2 = fVar2 - fStack_58;
            }
            uVar7 = uVar7 + 1;
            pfVar1[2] = fVar2;
            iVar8 = iVar8 + 0x28;
            piVar4 = local_3c;
            piVar5 = local_40;
          } while (uVar7 < uStack_54);
        }
      }
    }
    (**(code **)(**(int **)(this + 0x18) + 0xbc))(1);
  }
  return;
}
}

// =================================================
// Function: CBoatSailState::UpdateHaulUpSpi
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CBoatSailState::UpdateHaulUpSpi
          (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4)
{
{
  float *pfVar1;
  float fVar2;
  float fVar3;
  CPlugVisual *this_00;
  int *piVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  float unaff_EBP;
  GmVec3 *unaff_EDI;
  int iVar10;
  float10 extraout_ST0;
  float10 fVar11;
  uint uStack_58;
  uint uStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  float local_44;
  float fStack_40;
  float fStack_3c;
  int *local_38;
  CPlugVisual *local_34;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if ((*(int *)(this + 0x24) != 0) && (*(int *)(this + 0x28) != 0)) {
    fVar2 = (float)_DAT_00b41ea8;
    if (param_3 <= fVar2) {
      local_44 = param_3 / fVar2;
      param_3 = 0.0;
    }
    else {
      local_44 = 1.0;
      param_3 = (param_3 - fVar2) / (float)_DAT_00baac18;
    }
    if (*(int *)(*(int *)(this + 0x14) + 0x18) == 2) {
      UpdateGeometrySpi(this,param_1,param_2,unaff_EBP);
    }
    else if (*(int *)(*(int *)(this + 0x14) + 0x18) == 5) {
      UpdateGeometrySpiAsym(this,param_1,param_2,unaff_EBP);
    }
    this_00 = *(CPlugVisual **)(this + 0x24);
    piVar4 = *(int **)(this + 0x28);
    local_38 = piVar4;
    local_34 = this_00;
    uStack_4c = (**(code **)(*piVar4 + 0x8c))();
    fVar2 = *(float *)(this_00 + 0x38);
    fVar3 = *(float *)(this_00 + 0x44);
    fVar5 = *(float *)(this_00 + 0x44) + *(float *)(this_00 + 0x44);
    iStack_50 = (**(code **)(*(int *)this_00 + 0x8c))();
    while (iStack_50 != -1) {
      (**(code **)(*(int *)this_00 + 0x90))(&iStack_50,&uStack_54,&param_2);
      (**(code **)(*piVar4 + 0x90))(&uStack_58,&fStack_3c,&uStack_54);
      fStack_20 = *(float *)param_2;
      uStack_58 = 0;
      fStack_1c = *(float *)((int)param_2 + 4);
      fStack_18 = *(float *)((int)param_2 + 8);
      fStack_2c = *(float *)param_2;
      fStack_28 = *(float *)((int)param_2 + 4);
      fStack_24 = *(float *)((int)param_2 + 8);
      if (uStack_54 != 0) {
        iVar10 = 0;
        fStack_3c = param_4 * param_4;
        do {
          iVar9 = iStack_48;
          pfVar1 = (float *)(iVar10 + (int)param_2);
          fVar7 = (*(float *)(iVar10 + 4 + iStack_48) - (fVar2 - fVar3)) / fVar5;
          param_3 = (*(float *)(iVar10 + 4 + iStack_48) / fVar5) * (float)_DAT_00b36bd8 +
                    *(float *)(this + 0xac);
          __CIsin();
          local_44 = (float)extraout_ST0 * *(float *)(*(int *)(this + 0x14) + 0x94);
          fStack_14 = *pfVar1;
          fStack_10 = pfVar1[1];
          fStack_c = pfVar1[2];
          param_3 = (1.0 - fVar7) * param_4;
          fVar11 = (float10)func_0x009c2390();
          fVar8 = (float)fVar11 * (float)_DAT_00b40f28;
          fVar6 = 0.0;
          if ((fVar8 < 0.0 == (fVar8 == 0.0)) &&
             (fVar6 = fVar8, !NAN(fVar8) && 1.0 < fVar8 != (fVar8 == 1.0))) {
            fVar6 = 1.0;
          }
          fVar6 = fVar6 * (float)_DAT_00b362c0 + (float)_DAT_00b30a10;
          fStack_8 = *(float *)(iVar10 + iVar9) * fVar6 - fVar6 * local_44;
          fStack_4 = (fVar2 - fVar3) + fVar5 * fVar7 * fStack_40;
          fVar6 = *(float *)(iVar10 + 8 + iVar9) * fVar6 + fVar6 * local_44;
          fVar7 = fStack_3c * (fStack_14 - fStack_8) + fStack_8;
          *pfVar1 = fVar7;
          pfVar1[1] = fStack_4 + (fStack_10 - fStack_4) * fStack_3c;
          param_3 = (fStack_c - fVar6) * fStack_3c;
          pfVar1[2] = param_3 + fVar6;
          if (fVar7 < fStack_20) {
            fStack_20 = fVar7;
          }
          if (pfVar1[1] < fStack_1c) {
            fStack_1c = pfVar1[1];
          }
          if (pfVar1[2] < fStack_18) {
            fStack_18 = pfVar1[2];
          }
          if (fStack_2c < *pfVar1) {
            fStack_2c = *pfVar1;
          }
          if (fStack_28 < pfVar1[1]) {
            fStack_28 = pfVar1[1];
          }
          if (fStack_24 < pfVar1[2]) {
            fStack_24 = pfVar1[2];
          }
          uStack_58 = uStack_58 + 1;
          iVar10 = iVar10 + 0x28;
          this_00 = local_34;
          piVar4 = local_38;
        } while (uStack_58 < uStack_54);
      }
    }
    CPlugVisual::SetBoundingMinMax(this_00,(CPlugVisual *)&fStack_20,(GmVec3 *)&fStack_2c,unaff_EDI)
    ;
    (**(code **)(**(int **)(this + 0x18) + 0xbc))(0);
  }
  return;
}
}

// =================================================
// Function: CBoatSailState::UpdateRotationAsync
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CBoatSailState::UpdateRotationAsync
          (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3)
{
{
  float fVar1;
  int iVar2;
  GmMat43 *unaff_EBX;
  float unaff_ESI;
  CBoatSailState *pCVar3;
  undefined4 *puVar4;
  GmMat43 *unaff_EDI;
  GmIso3 *pGVar5;
  GmIso4 *in_stack_00000014;
  float in_stack_ffffff54;
  GmIso4 *in_stack_ffffff58;
  GmMat43 *in_stack_ffffff5c;
  GmIso3 *in_stack_ffffff60;
  undefined4 local_9c;
  GmIso4 *in_stack_ffffff6c;
  float in_stack_ffffff70;
  GmMat2 local_88 [4];
  undefined1 local_84 [4];
  undefined1 local_80 [12];
  GmScaleTrans2 local_74 [36];
  undefined4 local_50 [2];
  undefined1 local_48 [4];
  CPlugTree local_44 [40];
  undefined1 local_1c [4];
  GmIso3 local_18 [24];
  
  GmMat3::SetIdentity(local_84,unaff_EBX);
  if (*(int *)(*(int *)(this + 0x14) + 0x18) == 2) {
    fVar1 = _DAT_00b2c060;
    if (-1 < (int)param_2) {
      fVar1 = 1.0;
    }
    param_2 = param_2 - fVar1 * (float)_DAT_00b36110 * (float)_DAT_00b313b8;
    in_stack_ffffff58 = (GmIso4 *)param_2;
  }
  else if (*(int *)(*(int *)(this + 0x14) + 0x18) == 5) {
    param_2 = param_2 - param_3;
    in_stack_ffffff58 = (GmIso4 *)param_2;
  }
  GmMat3::RotateY(local_80,(GmIso4 *)param_2,in_stack_ffffff54);
  GmMat3::SetIdentity(&stack0xffffff60,unaff_EDI);
  GmMat3::RotateY(&local_9c,in_stack_00000014,unaff_ESI);
  pCVar3 = this + 0x38;
  puVar4 = local_50;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *(undefined4 *)pCVar3;
    pCVar3 = pCVar3 + 4;
    puVar4 = puVar4 + 1;
  }
  GmMat3::LeftMult(local_50,local_74,(GmScaleTrans2 *)in_stack_ffffff58);
  if (*(int *)(*(int *)(this + 0x14) + 0x18) == 5) {
    GmIso4::SetIdentity(local_1c,in_stack_ffffff5c);
    puVar4 = (undefined4 *)&stack0xffffff70;
    pGVar5 = local_18;
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined4 *)pGVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      pGVar5 = pGVar5 + 4;
    }
    GmIso4::Mult(local_48,local_18,in_stack_ffffff60);
  }
  if (*(CPlugTree **)(this + 0x18) != (CPlugTree *)0x0) {
    local_9c = 0x82af33;
    CPlugTree::SetLocation(*(CPlugTree **)(this + 0x18),local_44,in_stack_ffffff6c);
  }
  if (*(CPlugTree **)(this + 0x1c) != (CPlugTree *)0x0) {
    CPlugTree::SetRotation(*(CPlugTree **)(this + 0x1c),local_88,in_stack_ffffff70);
    in_stack_ffffff70 = 0.0;
    (**(code **)(**(int **)(this + 0x1c) + 0xbc))();
  }
  if (*(CPlugTree **)(this + 0x20) != (CPlugTree *)0x0) {
    CPlugTree::SetRotation(*(CPlugTree **)(this + 0x20),local_88,in_stack_ffffff70);
    (**(code **)(**(int **)(this + 0x20) + 0xbc))();
  }
  return;
}
}

// =================================================
// Function: CBoatSailState::UpdateSailPhysics
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CBoatSailState::UpdateSailPhysics
          (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4,
          float param_5)
{
{
  int iVar1;
  int iVar2;
  float fVar3;
  CBoatSailState *pCVar4;
  float unaff_EBX;
  CMwId *unaff_ESI;
  float unaff_EDI;
  float10 extraout_ST0;
  float fVar5;
  float fVar6;
  float unaff_retaddr;
  float fVar7;
  float in_stack_00000018;
  float in_stack_0000001c;
  float in_stack_00000020;
  float in_stack_fffffff0;
  float local_8;
  
  iVar1 = *(int *)(*(int *)(this + 0x14) + 0x18);
  if (*(int *)(this + 0x70) != 0) {
    fVar5 = OptimalSailAngleGet(this,(CBoatSail *)param_1,param_2,unaff_EDI,unaff_ESI);
    if ((*(int *)(this + 0x78) == 0) ||
       (iVar2 = *(int *)(this + 0x14), *(float *)(iVar2 + 0x6c) <= _DAT_00baab3c)) {
      *(float *)(this + 0x80) = fVar5;
    }
    else {
      fVar6 = *(float *)(this + 0x80);
      __CIsin();
      unaff_retaddr = (float)extraout_ST0;
      if (unaff_retaddr < _DAT_00b31460 == (unaff_retaddr == _DAT_00b31460)) {
        local_8 = unaff_retaddr;
        if (1.0 < unaff_retaddr != (unaff_retaddr == 1.0)) {
          local_8 = 1.0;
        }
      }
      else {
        local_8 = _DAT_00b31460;
      }
      local_8 = local_8 * in_stack_00000018 * *(float *)(iVar2 + 0x6c);
      if (1.0 < local_8) {
        local_8 = 1.0;
      }
      *(float *)(this + 0x80) = local_8 * (fVar5 - fVar6) + *(float *)(this + 0x80);
    }
    *(float *)(this + 0x74) = param_4;
    param_2 = param_4;
  }
  if (*(int *)(this + 0x7c) != 0) {
    *(float *)(this + 0x80) = -param_2;
  }
  switch(*(undefined4 *)(this + 0x8c)) {
  case 0:
  case 4:
  case 5:
    break;
  case 1:
    break;
  case 2:
  case 3:
  }
  fVar5 = *(float *)(*(CBoatSail **)(this + 0x14) + 0x5c);
  fVar6 = CBoatSail::SheetAngleMaxGet(*(CBoatSail **)(this + 0x14),(CBoatSail *)param_5,unaff_EBX);
  if ((int)param_5 < 0) {
    param_1 = _DAT_00b2c060;
  }
  else {
    param_1 = (CBoatSailState *)0x3f800000;
  }
  fVar7 = 1.0;
  fVar3 = ABS(*(float *)(this + 0x80));
  if ((unaff_retaddr < fVar3) && (unaff_retaddr = fVar3, fVar6 < fVar3 != (fVar6 == fVar3))) {
    unaff_retaddr = fVar6;
  }
  fVar6 = _DAT_00b3380c;
  if ((fVar5 < (float)_DAT_00b362c0 != (fVar5 == (float)_DAT_00b362c0)) ||
     (fVar6 = fVar5, fVar5 < 1.0)) {
    fVar7 = fVar6;
  }
  fVar5 = -(float)param_1 * unaff_retaddr * fVar7;
  *(float *)(this + 0x80) = fVar5;
  if ((iVar1 != 5) ||
     (fVar6 = GmFunc::Mod(*(float *)(this + 0x84),_DAT_00b5b910,_DAT_00baab40),
     (float)_DAT_00b5ca28 <= fVar6 * fVar5)) {
    fVar6 = ABS(param_5);
    if (fVar6 < ABS(fVar5)) {
      if ((int)fVar5 < 0) {
        fVar5 = (float)_DAT_00b2c060 * fVar6;
      }
      else {
        fVar5 = fVar6 * 1.0;
      }
    }
  }
  else {
    in_stack_00000018 = 1.4013e-45;
    fVar5 = *(float *)(this + 0x84);
    if (NAN(fVar5) || 0.0 < fVar5 == (fVar5 == 0.0)) {
      in_stack_00000018 = -NAN;
    }
    fVar5 = (float)(int)in_stack_00000018 * (float)_DAT_00b77ec0;
  }
  fVar6 = fVar5 - *(float *)(this + 0x84);
  *(undefined4 *)(this + 0x98) = 0;
  fVar3 = ABS(fVar6);
  if ((_DAT_00baab3c < fVar3) && (iVar2 = *(int *)(this + 0x14), *(int *)(iVar2 + 0x18) != 2)) {
    if ((-param_5 - *(float *)(this + 0x84)) * fVar6 <= (float)_PTR_00b2c178) {
      *(undefined4 *)(this + 0x98) = 1;
      fVar5 = *(float *)(iVar2 + 100);
    }
    else {
      *(undefined4 *)(this + 0x98) = 2;
      fVar5 = *(float *)(iVar2 + 0x68);
    }
    in_stack_00000018 = (fVar3 + (float)_DAT_00ba1300) * in_stack_0000001c * fVar5;
    if (fVar3 < _DAT_00ba3fb8) {
      *(undefined4 *)(this + 0x98) = 0;
    }
    if (fVar3 < in_stack_00000018) {
      in_stack_00000018 = fVar3;
    }
    pCVar4 = (CBoatSailState *)0x3f800000;
    if ((int)fVar6 < 0) {
      pCVar4 = _DAT_00b2c060;
    }
    fVar5 = (float)pCVar4 * in_stack_00000018 + *(float *)(this + 0x84);
  }
  *(float *)(this + 0x84) = fVar5;
  fVar5 = GmFunc::Mod(*(float *)(this + 0x84),_DAT_00b5b910,_DAT_00baab40);
  *(float *)(this + 0x84) = fVar5;
  if ((iVar1 == 5) || (iVar1 == 2)) {
    fVar5 = CBoatSail::BoomAngleGet
                      (*(CBoatSail **)(this + 0x14),(CBoatSail *)param_4,param_5,in_stack_fffffff0);
    fVar5 = (fVar5 * fVar7 - *(float *)(this + 0x88)) * in_stack_00000020 *
            *(float *)(*(int *)(this + 0x14) + 0x78) + *(float *)(this + 0x88);
  }
  *(float *)(this + 0x88) = fVar5;
  return;
}
}

// =================================================
// Function: CBoatSailState::UpdateShiverAndBulgeAsync
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CBoatSailState::UpdateShiverAndBulgeAsync
          (CBoatSailState *this,CBoatSailState *param_1,float param_2,float param_3,float param_4,
          float param_5)
{
{
  int iVar1;
  float fVar2;
  float unaff_EDI;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 fVar3;
  float10 fVar4;
  float10 extraout_ST0_03;
  float fVar5;
  
  CBoatSail::ShiverAngleGet(*(CBoatSail **)(this + 0x14),(CBoatSail *)param_1,unaff_EDI);
  __CIsin();
  iVar1 = *(int *)(this + 0x14);
  if ((*(int *)(iVar1 + 0xa0) != 0) ||
     (ABS(*(float *)(this + 0x9c) - -param_4) < (float)_DAT_00b36be8)) {
    __CIsin();
    fVar5 = ABS((float)extraout_ST0_00 / ((float)extraout_ST0 + (float)_DAT_00b36298));
    fVar2 = 0.0;
    if ((fVar5 < 0.0 == (fVar5 == 0.0)) &&
       (fVar2 = fVar5, !NAN(fVar5) && 1.0 < fVar5 != (fVar5 == 1.0))) {
      fVar2 = 1.0;
    }
    fVar5 = 1.0 - fVar2 * fVar2;
  }
  else {
    fVar5 = 0.0;
  }
  *(float *)(this + 0xa4) = fVar5;
  if (*(int *)(iVar1 + 0x18) == 0) {
    __CIsin();
    fVar3 = extraout_ST0_01;
  }
  else {
    __CIsin();
    fVar3 = extraout_ST0_02;
  }
  fVar4 = (float10)func_0x009c2390();
  __CIexp();
  param_2 = (float)extraout_ST0_03 * (float)fVar4;
  *(float *)(this + 0xa8) = param_2;
  if ((int)(float)fVar3 < 0) {
    param_4 = _DAT_00b2c060;
  }
  else {
    param_4 = 1.0;
  }
  if (param_2 < 0.0 == (param_2 == 0.0)) {
    if (1.0 <= param_2) {
      param_2 = 1.0;
    }
  }
  else {
    param_2 = 0.0;
  }
  *(float *)(this + 0xa8) = param_4 * (float)_DAT_00b5b5d0 * *(float *)(iVar1 + 0x70) * param_2;
  fVar5 = *(float *)(iVar1 + 0x98) * param_3;
  if (*(float *)(iVar1 + 0x9c) <= fVar5) {
    fVar5 = *(float *)(iVar1 + 0x9c);
  }
  fVar5 = GmFunc::Mod(fVar5 * param_5 + *(float *)(this + 0xac),0.0,_DAT_00baab44);
  *(float *)(this + 0xac) = fVar5;
  return;
}
}

