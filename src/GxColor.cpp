// Class implementation: GxColor

// =================================================
// Function: GxColor::GetHLS
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GxColor::GetHLS(void *this,GxColor *param_1,GmVec3 *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  ulong uVar7;
  
  fVar1 = *(float *)((int)this + 4);
  if (*(float *)this <= fVar1) {
    fVar1 = *(float *)this;
  }
  fVar2 = *(float *)((int)this + 8);
  if (fVar1 <= fVar2) {
    fVar2 = fVar1;
  }
  fVar1 = *(float *)this;
  fVar3 = *(float *)((int)this + 4);
  if (fVar3 < fVar1 != (fVar3 == fVar1)) {
    fVar3 = fVar1;
  }
  fVar1 = *(float *)((int)this + 8);
  if (fVar1 < fVar3 != (fVar1 == fVar3)) {
    fVar1 = fVar3;
  }
  fVar3 = fVar2 + fVar1;
  fVar4 = fVar3 * (float)_DAT_00b313b8;
  *(float *)(param_1 + 4) = fVar4;
  fVar6 = _DAT_00babbb4;
  if (ABS(fVar2 - fVar1) < _DAT_00babbb4) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(float *)param_1 = _DAT_00b31460;
    return;
  }
  fVar2 = fVar1 - fVar2;
  fVar5 = (float)_DAT_00b33a58;
  if (fVar4 < _DAT_00b31460 == (fVar4 == _DAT_00b31460)) {
    fVar3 = fVar5 - fVar3;
  }
  *(float *)(param_1 + 8) = fVar2 / fVar3;
  if (fVar6 <= ABS(*(float *)this - fVar1)) {
    if (fVar6 <= ABS(*(float *)((int)this + 4) - fVar1)) {
      uVar7 = GmFunc::AreNearlyEqual(*(float *)((int)this + 8),fVar1,fVar6);
      if (uVar7 == 0) goto LAB_00837194;
      fVar5 = (*(float *)this - *(float *)((int)this + 4)) / fVar2 + (float)_DAT_00b3d2c8;
    }
    else {
      fVar5 = (*(float *)((int)this + 8) - *(float *)this) / fVar2 + fVar5;
    }
  }
  else {
    fVar5 = (*(float *)((int)this + 4) - *(float *)((int)this + 8)) / fVar2;
  }
  *(float *)param_1 = fVar5;
LAB_00837194:
  fVar1 = *(float *)param_1 / (float)_DAT_00b508a0;
  *(float *)param_1 = fVar1;
  if (0.0 <= fVar1) {
    return;
  }
  *(float *)param_1 = fVar1 + (float)_DAT_00b2c188;
  return;
}
}

// =================================================
// Function: GxColor::GetHSV
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GxColor::GetHSV(void *this,GxColor *param_1,GmVec3 *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  ulong uVar5;
  
  fVar1 = *(float *)((int)this + 4);
  if (*(float *)this <= fVar1) {
    fVar1 = *(float *)this;
  }
  fVar2 = *(float *)((int)this + 8);
  if (fVar1 <= fVar2) {
    fVar2 = fVar1;
  }
  fVar1 = *(float *)this;
  fVar3 = *(float *)((int)this + 4);
  if (fVar3 < fVar1 != (fVar3 == fVar1)) {
    fVar3 = fVar1;
  }
  fVar1 = *(float *)((int)this + 8);
  if (fVar1 < fVar3 != (fVar1 == fVar3)) {
    fVar1 = fVar3;
  }
  *(float *)(param_1 + 8) = fVar1;
  fVar4 = _DAT_00babbb4;
  fVar3 = 0.0;
  if (_DAT_00babbb4 <= ABS(fVar1 - 0.0)) {
    fVar3 = (fVar1 - fVar2) / fVar1;
  }
  *(float *)(param_1 + 4) = fVar3;
  if (ABS(fVar3 - 0.0) < fVar4) {
    *(undefined4 *)param_1 = _DAT_00b31460;
    return;
  }
  fVar2 = fVar1 - fVar2;
  if (fVar4 <= ABS(*(float *)this - fVar1)) {
    if (fVar4 <= ABS(*(float *)((int)this + 4) - fVar1)) {
      uVar5 = GmFunc::AreNearlyEqual(*(float *)((int)this + 8),fVar1,fVar4);
      if (uVar5 == 0) goto LAB_00836dab;
      fVar2 = (*(float *)this - *(float *)((int)this + 4)) / fVar2 + (float)_DAT_00b3d2c8;
    }
    else {
      fVar2 = (*(float *)((int)this + 8) - *(float *)this) / fVar2 + (float)_DAT_00b33a58;
    }
  }
  else {
    fVar2 = (*(float *)((int)this + 4) - *(float *)((int)this + 8)) / fVar2;
  }
  *(float *)param_1 = fVar2;
LAB_00836dab:
  fVar1 = *(float *)param_1 / (float)_DAT_00b508a0;
  *(float *)param_1 = fVar1;
  if (0.0 <= fVar1) {
    return;
  }
  *(float *)param_1 = fVar1 + (float)_DAT_00b2c188;
  return;
}
}

// =================================================
// Function: GxColor::SetFromBGRA
// =================================================
/* WARNING: Removing unreachable block (ram,0x0071d12a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GxColor::SetFromBGRA(void *this,GmVec3 *param_1,uchar *param_2,ulong param_3)
{
{
  float fVar1;
  
  fVar1 = (float)_DAT_00b3d080;
  *(float *)this = (float)((uint)param_1 >> 0x10 & 0xff) * fVar1;
  *(float *)((int)this + 4) = (float)((uint)param_1 >> 8 & 0xff) * fVar1;
  *(float *)((int)this + 8) = (float)((uint)param_1 & 0xff) * fVar1;
  *(float *)((int)this + 0xc) = (float)((uint)param_1 >> 0x18) * fVar1;
  return;
}
}

// =================================================
// Function: GxColor::SetHLS
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GxColor::SetHLS(void *this,GxColor *param_1,GmVec3 *param_2,float param_3)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  float *extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  float *extraout_EDX;
  float *extraout_EDX_00;
  float fVar4;
  float fVar5;
  
  if (_DAT_00b31460 < *(float *)(param_1 + 4)) {
    fVar5 = (*(float *)(param_1 + 8) + *(float *)(param_1 + 4)) -
            *(float *)(param_1 + 8) * *(float *)(param_1 + 4);
  }
  else {
    fVar5 = (*(float *)(param_1 + 8) + (float)_DAT_00b2c188) * *(float *)(param_1 + 4);
  }
  fVar3 = (*(float *)(param_1 + 4) + *(float *)(param_1 + 4)) - fVar5;
  if (ABS(*(float *)(param_1 + 8) - (float)_PTR_00b2c178) < _DAT_00babbb4) {
    uVar1 = *(undefined4 *)(param_1 + 4);
    uVar2 = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)this = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)((int)this + 4) = uVar1;
    *(undefined4 *)((int)this + 8) = uVar2;
    *(GmVec3 **)((int)this + 0xc) = param_2;
    return;
  }
  fVar4 = ValueHLS(fVar3,fVar5,*(float *)param_1 + (float)_DAT_00b90648);
  *extraout_ECX = fVar4;
  fVar4 = ValueHLS(fVar3,fVar5,*extraout_EDX);
  *(float *)(extraout_ECX_00 + 4) = fVar4;
  fVar5 = ValueHLS(fVar3,fVar5,*extraout_EDX_00 - (float)_DAT_00b90648);
  *(float *)(extraout_ECX_01 + 8) = fVar5;
  *(GmVec3 **)(extraout_ECX_01 + 0xc) = param_2;
  return;
}
}

// =================================================
// Function: GxColor::SetHSV
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GxColor::SetHSV(void *this,GxColor *param_1,GmVec3 *param_2,float param_3)
{
{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  GxColor *pGVar4;
  float local_4;
  
  pGVar4 = param_1;
  if (_DAT_00babbb4 <= ABS(*(float *)(param_1 + 4) - (float)_PTR_00b2c178)) {
    param_1 = *(GxColor **)param_1;
    if (ABS((float)param_1 - (float)_DAT_00b2c188) < _DAT_00babbb4) {
      param_1 = (GxColor *)0x0;
    }
    iVar1 = (int)ROUND((float)param_1 * (float)_DAT_00b508a0 - (float)_DAT_00b313b8);
    fVar2 = (float)iVar1;
    if (iVar1 < 0) {
      fVar2 = fVar2 + _DAT_00c418d0;
    }
    fVar2 = (float)param_1 * (float)_DAT_00b508a0 - fVar2;
    param_1 = (GxColor *)(*(float *)(pGVar4 + 8) * (1.0 - *(float *)(pGVar4 + 4)));
    local_4 = *(float *)(pGVar4 + 8) * (1.0 - fVar2 * *(float *)(pGVar4 + 4));
    fVar2 = (1.0 - (1.0 - fVar2) * *(float *)(pGVar4 + 4)) * *(float *)(pGVar4 + 8);
    switch(iVar1) {
    case 0:
      *(undefined4 *)this = *(undefined4 *)(pGVar4 + 8);
      *(float *)((int)this + 4) = fVar2;
      *(GxColor **)((int)this + 8) = param_1;
      *(GmVec3 **)((int)this + 0xc) = param_2;
      return;
    case 1:
      uVar3 = *(undefined4 *)(pGVar4 + 8);
      *(float *)this = local_4;
      *(undefined4 *)((int)this + 4) = uVar3;
      *(GxColor **)((int)this + 8) = param_1;
      *(GmVec3 **)((int)this + 0xc) = param_2;
      return;
    case 2:
      uVar3 = *(undefined4 *)(pGVar4 + 8);
      *(GxColor **)this = param_1;
      *(undefined4 *)((int)this + 4) = uVar3;
      *(float *)((int)this + 8) = fVar2;
      *(GmVec3 **)((int)this + 0xc) = param_2;
      return;
    case 3:
      uVar3 = *(undefined4 *)(pGVar4 + 8);
      *(GxColor **)this = param_1;
      *(float *)((int)this + 4) = local_4;
      *(undefined4 *)((int)this + 8) = uVar3;
      *(GmVec3 **)((int)this + 0xc) = param_2;
      return;
    case 4:
      local_4 = *(float *)(pGVar4 + 8);
      break;
    case 5:
      goto switchD_00836f0e_caseD_5;
    default:
      goto switchD_00836f0e_default;
    }
  }
  else {
    local_4 = *(float *)(param_1 + 8);
    param_1 = *(GxColor **)(param_1 + 8);
switchD_00836f0e_caseD_5:
    fVar2 = *(float *)(pGVar4 + 8);
  }
  *(float *)this = fVar2;
  *(GxColor **)((int)this + 4) = param_1;
  *(float *)((int)this + 8) = local_4;
switchD_00836f0e_default:
  *(GmVec3 **)((int)this + 0xc) = param_2;
  return;
}
}

