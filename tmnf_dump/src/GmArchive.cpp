// Class implementation: GmArchive

// =================================================
// Function: GmArchive::ReadQuat_6
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl GmArchive::ReadQuat_6(CClassicBuffer *param_1,GmQuat *param_2)
{
{
  GmVec3 *pGVar1;
  float fVar2;
  CClassicBuffer *pCVar3;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float *unaff_retaddr;
  
  pCVar3 = param_1;
  (**(code **)(*(int *)param_1 + 4))(&param_1,2);
  pGVar1 = (GmVec3 *)(unaff_retaddr + 1);
  ReadVec3Unit_4(pCVar3,pGVar1);
  __CIsin();
  fVar2 = (float)extraout_ST0;
  *(float *)pGVar1 = fVar2 * *(float *)pGVar1;
  unaff_retaddr[2] = unaff_retaddr[2] * fVar2;
  unaff_retaddr[3] = fVar2 * unaff_retaddr[3];
  __CIcos();
  *unaff_retaddr = (float)extraout_ST0_00;
  return;
}
}

// =================================================
// Function: GmArchive::ReadReal_3
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl GmArchive::ReadReal_3(CClassicBuffer *param_1,float *param_2)
{
{
  CClassicBuffer *pCVar1;
  float *unaff_ESI;
  uint uStack_c;
  
  pCVar1 = param_1;
  uStack_c = 1;
  (**(code **)(*(int *)param_1 + 4))(&param_1);
  (**(code **)(*(int *)pCVar1 + 4))(&uStack_c);
  *unaff_ESI = (float)(int)(((uStack_c & 0xff) - 0x80) * 0x10000 + 2) * (float)_DAT_00b55d40;
  return;
}
}

// =================================================
// Function: GmArchive::ReadVec3Pos_12
// =================================================
void __cdecl GmArchive::ReadVec3Pos_12(CClassicBuffer *param_1,GmVec3 *param_2)
{
{
  (**(code **)(*(int *)param_1 + 4))(param_2,4);
  (**(code **)(*(int *)param_1 + 4))(param_2 + 4,4);
  (**(code **)(*(int *)param_1 + 4))(param_2 + 8,4);
  return;
}
}

// =================================================
// Function: GmArchive::ReadVec3Pos_9
// =================================================
void __cdecl GmArchive::ReadVec3Pos_9(CClassicBuffer *param_1,GmVec3 *param_2)
{
{
  ReadReal_3(param_1,(float *)param_2);
  ReadReal_3(param_1,(float *)(param_2 + 4));
  ReadReal_3(param_1,(float *)(param_2 + 8));
  return;
}
}

// =================================================
// Function: GmArchive::ReadVec3Unit_4
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl GmArchive::ReadVec3Unit_4(CClassicBuffer *param_1,GmVec3 *param_2)
{
{
  CClassicBuffer *pCVar1;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  CClassicBuffer **ppCVar2;
  float *pfStack_8;
  short asStack_4 [2];
  
  pCVar1 = param_1;
  ppCVar2 = &param_1;
  (**(code **)(*(int *)param_1 + 4))(ppCVar2,2);
  (**(code **)(*(int *)pCVar1 + 4))
            (asStack_4,2,ppCVar2,
             ((float)(int)asStack_4[0] * (float)_DAT_00b36110) / (float)_DAT_00b530f8);
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
// Function: GmArchive::ReadVec3_4
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl GmArchive::ReadVec3_4(CClassicBuffer *param_1,GmVec3 *param_2)
{
{
  float fVar1;
  CClassicBuffer *pCVar2;
  short in_CX;
  float10 extraout_ST0;
  GmVec3 *unaff_retaddr;
  
  pCVar2 = param_1;
  (**(code **)(*(int *)param_1 + 4))(&param_1,2);
  if (in_CX == -0x8000) {
    fVar1 = 0.0;
  }
  else {
    __CIexp();
    fVar1 = (float)extraout_ST0;
  }
  GmFunc::ReadUnitVec3(pCVar2,unaff_retaddr);
  *(float *)unaff_retaddr = fVar1 * *(float *)unaff_retaddr;
  *(float *)(unaff_retaddr + 4) = *(float *)(unaff_retaddr + 4) * fVar1;
  *(float *)(unaff_retaddr + 8) = fVar1 * *(float *)(unaff_retaddr + 8);
  return;
}
}

// =================================================
// Function: GmArchive::WriteQuat_6
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl GmArchive::WriteQuat_6(CClassicBuffer *param_1,GmQuat *param_2)
{
{
  GmQuat *pGVar1;
  float10 extraout_ST0;
  
  pGVar1 = param_2;
  __CIacos();
  param_2 = (GmQuat *)
            (*(float *)(pGVar1 + 0xc) * *(float *)(pGVar1 + 0xc) +
            *(float *)(pGVar1 + 8) * *(float *)(pGVar1 + 8) +
            *(float *)(pGVar1 + 4) * *(float *)(pGVar1 + 4));
  func_0x009c1b40();
  param_2 = (GmQuat *)
            ((int)ROUND(((float)extraout_ST0 * (float)_DAT_00b52a58) / (float)_DAT_00b36110) &
            0xffff);
  (**(code **)(*(int *)param_1 + 8))(&param_2,2);
  WriteVec3Unit_4(param_1,(GmVec3 *)&stack0xffffffec);
  return;
}
}

// =================================================
// Function: GmArchive::WriteReal_3
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl GmArchive::WriteReal_3(CClassicBuffer *param_1,float param_2)
{
{
  float fVar1;
  undefined2 in_FPUControlWord;
  undefined4 uStack_10;
  int local_8;
  
  fVar1 = param_2 / (float)_DAT_00bbdc00;
  uStack_10 = 1;
  param_2 = (float)CONCAT22(param_2._2_2_,in_FPUControlWord);
  local_8 = (int)(longlong)ROUND(fVar1);
  param_2 = (float)CONCAT31(param_2._1_3_,(char)((uint)(0x800000 - local_8) >> 0x10));
  (**(code **)(*(int *)param_1 + 8))(&param_2);
  (**(code **)(*(int *)param_1 + 8))(&uStack_10,2);
  return;
}
}

// =================================================
// Function: GmArchive::WriteVec3Pos_12
// =================================================
void __cdecl GmArchive::WriteVec3Pos_12(CClassicBuffer *param_1,GmVec3 *param_2)
{
{
  (**(code **)(*(int *)param_1 + 8))(param_2,4);
  (**(code **)(*(int *)param_1 + 8))(param_2 + 4,4);
  (**(code **)(*(int *)param_1 + 8))(param_2 + 8,4);
  return;
}
}

// =================================================
// Function: GmArchive::WriteVec3Pos_9
// =================================================
void __cdecl GmArchive::WriteVec3Pos_9(CClassicBuffer *param_1,GmVec3 *param_2)
{
{
  WriteReal_3(param_1,*(float *)param_2);
  WriteReal_3(param_1,*(float *)(param_2 + 4));
  WriteReal_3(param_1,*(float *)(param_2 + 8));
  return;
}
}

// =================================================
// Function: GmArchive::WriteVec3Unit_2
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl GmArchive::WriteVec3Unit_2(CClassicBuffer *param_1,GmVec3 *param_2)
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
  if (_DAT_00bbdbe4 <= ABS(fVar1)) {
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

// =================================================
// Function: GmArchive::WriteVec3Unit_4
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl GmArchive::WriteVec3Unit_4(CClassicBuffer *param_1,GmVec3 *param_2)
{
{
  float fVar1;
  GmVec3 *pGVar2;
  GmVec3 *pGVar3;
  uint extraout_EAX;
  float10 fVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  pGVar3 = param_2;
  fVar4 = (float10)func_0x009c1d90();
  param_2 = (GmVec3 *)(float)fVar4;
  __CIcos();
  fVar1 = (float)extraout_ST0;
  if (_DAT_00bbdbe4 <= ABS(fVar1)) {
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
  param_2 = (GmVec3 *)(extraout_EAX & 0xffff);
  (**(code **)(*(int *)param_1 + 8))(&param_2,2);
  __ftol2_sse();
  (**(code **)(*(int *)param_1 + 8))(&stack0x00000000,2);
  return;
}
}

// =================================================
// Function: GmArchive::WriteVec3_4
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl GmArchive::WriteVec3_4(CClassicBuffer *param_1,GmVec3 *param_2)
{
{
  uint extraout_EAX;
  float10 fVar1;
  float10 extraout_ST0;
  undefined4 uStack_14;
  
  param_2 = (GmVec3 *)
            (*(float *)(param_2 + 8) * *(float *)(param_2 + 8) +
            *(float *)(param_2 + 4) * *(float *)(param_2 + 4) +
            *(float *)param_2 * *(float *)param_2);
  fVar1 = (float10)func_0x009c1b40();
  if (_DAT_00bbdbe4 <= (float)fVar1) {
    param_2 = (GmVec3 *)(1.0 / (float)fVar1);
    __CIlog();
    param_2 = (GmVec3 *)((float)extraout_ST0 * (float)_DAT_00c418d8);
    if ((float)param_2 < (float)DAT_00b9cfa4) {
      param_2 = DAT_00b9cfa4;
    }
    if ((float)_DAT_00b530f8 < (float)param_2) {
      param_2 = DAT_00b9cfa8;
    }
    __ftol2_sse();
    param_2 = (GmVec3 *)(extraout_EAX & 0xffff);
  }
  else {
    param_2 = (GmVec3 *)0xffff8000;
  }
  uStack_14 = 2;
  (**(code **)(*(int *)param_1 + 8))(&param_2);
  WriteVec3Unit_2(param_1,(GmVec3 *)&uStack_14);
  return;
}
}

