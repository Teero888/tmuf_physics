// Class implementation: CBoatParam

// =================================================
// Function: CBoatParam::BSCoefFromHeelGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall CBoatParam::BSCoefFromHeelGet(CBoatParam *this,CBoatParam *param_1,float param_2)
{
{
  float fVar1;
  CFuncColorGradient *pCVar2;
  float10 extraout_ST0;
  float fVar3;
  
  pCVar2 = (CFuncColorGradient *)ABS((float)param_1);
  if (*(int *)(this + 0xbc) != 0) {
    if (*(CFuncKeysReal **)(this + 0xc0) == (CFuncKeysReal *)0x0) {
      return 1.0;
    }
    CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0xc0),pCVar2,0.0);
    return (float)extraout_ST0;
  }
  if ((float)pCVar2 <= _DAT_00ba3ed8) {
    return 1.0;
  }
  if ((float)pCVar2 < _DAT_00b36144) {
    return ((float)pCVar2 * (float)_DAT_00b32ea0 - (float)_DAT_00b48cb0) * *(float *)(this + 0x80) +
           (float)_DAT_00b2c188;
  }
  if ((float)pCVar2 < (float)_DAT_00ba3ed0) {
    return ((float)_DAT_00ba3ec8 - ((float)pCVar2 + (float)pCVar2)) * *(float *)(this + 0x80) +
           (float)_DAT_00b2c188;
  }
  if ((float)pCVar2 < *(float *)(this + 0x78)) {
    fVar1 = *(float *)(this + 0x78);
    fVar3 = GmFunc::ClampReal(fVar1 - (float)pCVar2,0.0,1.0);
    return (1.0 - fVar3 / (fVar1 - (float)_DAT_00ba3ed0)) *
           (1.0 - *(float *)(this + 0x80) * (float)_DAT_00ba3ec0);
  }
  return 0.0;
}
}

// =================================================
// Function: CBoatParam::DecelerationFromTillerGet
// =================================================
float __thiscall
CBoatParam::DecelerationFromTillerGet
          (CBoatParam *this,CBoatParam *param_1,float param_2,float param_3,int param_4)
{
{
  CFuncCurvesReal *this_00;
  float10 extraout_ST0;
  
  this_00 = *(CFuncCurvesReal **)(this + 0x38);
  if ((param_3 == 0.0) && (*(CFuncCurvesReal **)(this + 0x3c) != (CFuncCurvesReal *)0x0)) {
    this_00 = *(CFuncCurvesReal **)(this + 0x3c);
  }
  if (this_00 == (CFuncCurvesReal *)0x0) {
    return 0.0;
  }
  CFuncCurvesReal::GetValue(this_00,(CFuncColorGradient *)param_1,ABS(param_2));
  return (float)extraout_ST0;
}
}

// =================================================
// Function: CBoatParam::OldHeelGet
// =================================================
/* WARNING: Removing unreachable block (ram,0x007ffe57) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CBoatParam::OldHeelGet
          (CBoatParam *this,CBoatParam *param_1,CBoatSail *param_2,int param_3,float param_4,
          float param_5)
{
{
  float fVar1;
  CBoatParam *pCVar2;
  float fVar3;
  CBoatSail *pCVar4;
  float unaff_EBX;
  float unaff_ESI;
  float unaff_retaddr;
  
  pCVar4 = param_2;
  if ((param_2 != (CBoatSail *)0x0) && (*(int *)(param_1 + 0x18) != 2)) {
    return 0.0;
  }
  param_4 = ABS((float)param_3);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x8c),(CFuncColorGradient *)param_4,(float)&param_2);
  if (*(CFuncKeysReal **)(this + 0x88) != (CFuncKeysReal *)0x0) {
    unaff_EBX = 1.0;
    CFuncKeysReal::GetValue
              (*(CFuncKeysReal **)(this + 0x88),(CFuncColorGradient *)param_3,
               (float)&stack0xfffffff4);
    unaff_retaddr = unaff_ESI * unaff_retaddr;
  }
  pCVar2 = (CBoatParam *)(unaff_retaddr * 1.0 * unaff_EBX);
  if (pCVar4 == (CBoatSail *)0x0) {
    pCVar2 = (CBoatParam *)(*(float *)(param_1 + 0xd0) * (float)pCVar2);
  }
  param_1 = pCVar2;
  fVar1 = *(float *)(this + 0x78);
  fVar3 = -fVar1;
  if ((fVar3 < (float)param_1) && (fVar3 = fVar1, (float)param_1 < fVar1)) {
    return -(float)param_1;
  }
  return -fVar3;
}
}

