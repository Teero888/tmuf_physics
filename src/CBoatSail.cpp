// Class implementation: CBoatSail

// =================================================
// Function: CBoatSail::AccelerationGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CBoatSail::AccelerationGet(CBoatSail *this,CBoatSail *param_1,float param_2,float param_3)
{
{
  int iVar1;
  CFuncCurvesReal *this_00;
  float10 extraout_ST0;
  float fVar2;
  
  iVar1 = *(int *)(this + 0x14);
  if (*(int *)(iVar1 + 0xbc) == 0) {
    return *(float *)(iVar1 + 0x84);
  }
  this_00 = *(CFuncCurvesReal **)(this + 0x44);
  if (this_00 == (CFuncCurvesReal *)0x0) {
    return *(float *)(iVar1 + 0x84);
  }
  fVar2 = GmFunc::Mod(param_2,_DAT_00b5b910,_DAT_00baadd4);
  CFuncCurvesReal::GetValue(this_00,(CFuncColorGradient *)param_1,ABS(fVar2));
  return (float)extraout_ST0;
}
}

// =================================================
// Function: CBoatSail::BSGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall CBoatSail::BSGet(CBoatSail *this,CBoatSail *param_1,float param_2,float param_3)
{
{
  CFuncCurvesReal *this_00;
  float10 extraout_ST0;
  float fVar1;
  
  this_00 = *(CFuncCurvesReal **)(this + 0x1c);
  if (this_00 == (CFuncCurvesReal *)0x0) {
    return 0.0;
  }
  fVar1 = GmFunc::Mod(param_2,_DAT_00b5b910,_DAT_00baadd4);
  CFuncCurvesReal::GetValue(this_00,(CFuncColorGradient *)param_1,ABS(fVar1));
  return (float)extraout_ST0;
}
}

// =================================================
// Function: CBoatSail::BestVmgAngleGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CBoatSail::BestVmgAngleGet(CBoatSail *this,CBoatSail *param_1,float param_2,int param_3)
{
{
  float fVar1;
  int iVar2;
  SCasterCat *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  int local_c;
  float local_8;
  float local_4;
  
  if (*(int *)(this + 0x1c) != 0) {
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&local_4;
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&local_c;
    iVar2 = (**(code **)(*(int *)(*(int *)(this + 0x1c) + 0x18) + 0x18))
                      (param_1,pCVar4,&local_8,pCVar5,1);
    if (iVar2 != 0) {
      fVar1 = _DAT_00b2c060;
      if (local_c != 0) {
        fVar1 = 1.0;
      }
      pSVar3 = CFastBuffer<class_GxColor>::operator[](this + 0x20,pCVar4,(ulong)param_1);
      local_8 = *(float *)(pSVar3 + 4);
      pSVar3 = CFastBuffer<class_GxColor>::operator[](this + 0x20,pCVar5,(ulong)pCVar4);
      return (local_4 + fVar1 * (*(float *)(pSVar3 + 4) - local_4)) * local_8;
    }
  }
  return 0.0;
}
}

// =================================================
// Function: CBoatSail::BoomAngleGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CBoatSail::BoomAngleGet(CBoatSail *this,CBoatSail *param_1,float param_2,float param_3)
{
{
  float fVar1;
  float10 extraout_ST0;
  float fVar2;
  
  fVar2 = GmFunc::Mod(param_2,_DAT_00b5b910,_DAT_00baadd4);
  if (*(CFuncCurvesReal **)(this + 0x4c) != (CFuncCurvesReal *)0x0) {
    fVar1 = _DAT_00b2c060;
    if (-1 < (int)param_2) {
      fVar1 = 1.0;
    }
    CFuncCurvesReal::GetValue
              (*(CFuncCurvesReal **)(this + 0x4c),(CFuncColorGradient *)param_1,ABS(ABS(fVar2)));
    return (float)(-(float10)fVar1 * extraout_ST0);
  }
  return 0.0;
}
}

// =================================================
// Function: CBoatSail::HeelGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CBoatSail::HeelGet(CBoatSail *this,CBoatSail *param_1,float param_2,float param_3,float param_4,
                  CMwId *param_5,float param_6)
{
{
  CFuncCurvesReal *this_00;
  CFuncCurves2Real *this_01;
  float fVar1;
  float fVar2;
  CFuncColorGradient *pCVar3;
  CMwId *unaff_EDI;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float fVar4;
  
  this_00 = *(CFuncCurvesReal **)(this + 0x38);
  if (this_00 == (CFuncCurvesReal *)0x0) {
    return 0.0;
  }
  fVar4 = GmFunc::Mod(param_2,_DAT_00b5b910,_DAT_00baadd4);
  CFuncCurvesReal::GetValue(this_00,(CFuncColorGradient *)param_1,ABS(fVar4));
  if ((int)fVar4 < 0) {
    param_2 = (float)_DAT_00b2c060;
  }
  else {
    param_2 = 1.0;
  }
  this_01 = *(CFuncCurves2Real **)(this + 0x54);
  fVar4 = -param_2;
  param_2 = 1.0;
  if (this_01 != (CFuncCurves2Real *)0x0) {
    pCVar3 = _DAT_00b2c060;
    if (-1 < (int)param_3) {
      pCVar3 = (CFuncColorGradient *)0x3f800000;
    }
    OptimalSailAngleGet(this,param_1,param_3,param_4,unaff_EDI);
    CFuncCurves2Real::GetValue(this_01,pCVar3,ABS(param_4));
    param_2 = (float)extraout_ST0_00;
  }
  fVar1 = param_2 * fVar4 * (float)extraout_ST0;
  fVar2 = -*(float *)(*(int *)(this + 0x14) + 100);
  fVar4 = *(float *)(*(int *)(this + 0x14) + 100);
  if ((fVar2 < fVar1) && (fVar2 = fVar4, fVar4 < fVar1 == (fVar4 == fVar1))) {
    return fVar1;
  }
  return fVar2;
}
}

// =================================================
// Function: CBoatSail::LuffAngleSpeedGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CBoatSail::LuffAngleSpeedGet
          (CBoatSail *this,CBoatSail *param_1,float param_2,float param_3,float param_4,
          CMwId *param_5,float param_6,float param_7)
{
{
  CFuncCurvesReal *this_00;
  CFuncCurves2Real *this_01;
  float fVar1;
  CFuncColorGradient *pCVar2;
  CFuncColorGradient *pCVar3;
  float fVar4;
  float fVar5;
  CMwId *unaff_EDI;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float fVar6;
  
  if (*(int *)(*(int *)(this + 0x14) + 0xbc) == 0) {
    if (*(int *)(this + 0x18) == 2) {
      if ((float)_PTR_00b2c178 <= (float)param_5 * param_2) {
        return 0.0;
      }
      fVar4 = ABS(param_2);
      fVar6 = *(float *)(this + 0xa4);
      param_3 = 1.0;
      param_2 = 1.0;
      if (fVar6 <= fVar4) {
        if (*(float *)(this + 0xac) <= fVar4) {
          fVar6 = (((fVar4 - (float)_DAT_00b36be8) - (float)_DAT_00b5b8d8) * (float)_DAT_00b55920) /
                  (float)_DAT_00b5b8d8;
          if (fVar4 <= (float)_DAT_00b77ee8) {
            fVar6 = 1.0 - fVar6;
            param_3 = (1.0 - fVar6 * fVar6) * (float)_DAT_00b4fbd0 + (float)_DAT_00b40f78;
          }
          else {
            fVar6 = fVar6 + (float)_DAT_00b2c188;
            param_3 = fVar6 * fVar6 * (float)_DAT_00b40f78;
          }
        }
        else {
          fVar5 = (*(float *)(this + 0xac) - fVar6) * (float)_DAT_00b313b8;
          fVar1 = ((fVar4 - fVar6) - fVar5) / fVar5;
          if (fVar5 + fVar6 <= fVar4) {
            fVar1 = 1.0 - fVar1;
          }
          else {
            fVar1 = fVar1 + 1.0;
          }
          param_2 = fVar1 * fVar1 + fVar1 * fVar1 + 1.0;
        }
      }
      else {
        param_2 = (fVar4 * fVar4 * fVar4 * fVar4) / (fVar6 * fVar6 * fVar6 * fVar6);
      }
      fVar6 = (float)param_5 * param_3;
      return fVar6 * fVar6 * fVar6 * fVar6 * fVar6 * param_2 *
             *(float *)(*(int *)(this + 0x14) + 0x7c) * (float)_DAT_00b40f28;
    }
  }
  else {
    this_00 = *(CFuncCurvesReal **)(this + 0x3c);
    if (this_00 != (CFuncCurvesReal *)0x0) {
      fVar6 = GmFunc::Mod(param_2,_DAT_00b5b910,_DAT_00baadd4);
      pCVar2 = _DAT_00b2c060;
      if (-1 < (int)fVar6) {
        pCVar2 = (CFuncColorGradient *)0x3f800000;
      }
      CFuncCurvesReal::GetValue(this_00,(CFuncColorGradient *)param_1,ABS(fVar6));
      this_01 = *(CFuncCurves2Real **)(this + 0x54);
      if (this_01 == (CFuncCurves2Real *)0x0) {
        return (float)(-(float10)(float)pCVar2 * extraout_ST0) * 1.0;
      }
      pCVar3 = _DAT_00b2c060;
      if (-1 < (int)param_3) {
        pCVar3 = (CFuncColorGradient *)0x3f800000;
      }
      OptimalSailAngleGet(this,param_1,param_3,param_4,unaff_EDI);
      CFuncCurves2Real::GetValue(this_01,pCVar3,ABS(param_4));
      return (float)extraout_ST0_00 * (float)(-(float10)(float)pCVar2 * extraout_ST0);
    }
  }
  return 0.0;
}
}

// =================================================
// Function: CBoatSail::OptimalSailAngleGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CBoatSail::OptimalSailAngleGet
          (CBoatSail *this,CBoatSail *param_1,float param_2,float param_3,CMwId *param_4)
{
{
  CBoatSail *this_00;
  float fVar1;
  float fVar2;
  int iVar3;
  ulong uVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float10 extraout_ST0;
  CBoatSail *unaff_retaddr;
  float fStack00000014;
  
  this_00 = this + 0x2c;
  uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if ((uVar4 != 0) && (iVar3 = *(int *)param_4, iVar3 != -1)) {
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBX);
    pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    this = unaff_retaddr;
    if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar7,unaff_EBP)
        ;
        if (*(int *)(*(int *)pSVar6 + 0x14) == iVar3) break;
        pCVar7 = pCVar7 + 1;
      } while (pCVar7 < pCVar5);
    }
  }
  fStack00000014 = _DAT_00b41d80;
  if (param_1 != (CBoatSail *)0x0) {
    fStack00000014 = GmFunc::Mod((float)param_4,_DAT_00b5b910,_DAT_00baadd4);
    fStack00000014 = ABS(fStack00000014);
    CFuncCurvesReal::GetValue
              ((CFuncCurvesReal *)param_1,(CFuncColorGradient *)param_3,fStack00000014);
    fStack00000014 = (float)extraout_ST0;
  }
  fVar1 = *(float *)(this + 0x5c);
  fVar2 = *(float *)(this + 0x60);
  if ((fVar1 < fStack00000014) &&
     (fVar1 = fStack00000014, fVar2 < fStack00000014 != (fVar2 == fStack00000014))) {
    fVar1 = fVar2;
  }
  fVar2 = _DAT_00b2c060;
  if (-1 < (int)param_4) {
    fVar2 = 1.0;
  }
  return -fVar2 * fVar1;
}
}

// =================================================
// Function: CBoatSail::RevolveAngleSpeedGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CBoatSail::RevolveAngleSpeedGet(CBoatSail *this,CBoatSail *param_1,float param_2,float param_3)
{
{
  CFuncCurvesReal *this_00;
  float fVar1;
  float10 extraout_ST0;
  float fVar2;
  
  this_00 = *(CFuncCurvesReal **)(this + 0x40);
  if (this_00 != (CFuncCurvesReal *)0x0) {
    fVar2 = GmFunc::Mod(param_2,_DAT_00b5b910,_DAT_00baadd4);
    fVar1 = _DAT_00b2c060;
    if (-1 < (int)fVar2) {
      fVar1 = 1.0;
    }
    CFuncCurvesReal::GetValue(this_00,(CFuncColorGradient *)param_1,ABS(fVar2));
    return (float)(extraout_ST0 * (float10)fVar1);
  }
  return 0.0;
}
}

// =================================================
// Function: CBoatSail::SheetAngleMaxGet
// =================================================
float __thiscall CBoatSail::SheetAngleMaxGet(CBoatSail *this,CBoatSail *param_1,float param_2)
{
{
  float10 extraout_ST0;
  
  if (*(CFuncKeysReal **)(this + 0x58) != (CFuncKeysReal *)0x0) {
    CFuncKeysReal::GetValue
              (*(CFuncKeysReal **)(this + 0x58),(CFuncColorGradient *)ABS((float)param_1),0.0);
    return (float)extraout_ST0;
  }
  return *(float *)(this + 0x60);
}
}

// =================================================
// Function: CBoatSail::ShiverAngleGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall CBoatSail::ShiverAngleGet(CBoatSail *this,CBoatSail *param_1,float param_2)
{
{
  CBoatSail **local_8;
  undefined4 local_4;
  
  local_4 = _DAT_00ba3ef0;
  if (*(CFuncKeysReal **)(this + 0x48) != (CFuncKeysReal *)0x0) {
    local_8 = &param_1;
    CFuncKeysReal::GetValue
              (*(CFuncKeysReal **)(this + 0x48),(CFuncColorGradient *)param_1,(float)&local_4);
  }
  return (float)local_8;
}
}

