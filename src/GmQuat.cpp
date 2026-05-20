// Class implementation: GmQuat

// =================================================
// Function: GmQuat::ArchiveGmQuat
// =================================================
void __thiscall GmQuat::ArchiveGmQuat(void *this,GmQuat *param_1,CClassicArchive *param_2)
{
{
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 4),(float *)0x1,unaff_EDI);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 8),(float *)0x1,unaff_ESI);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0xc),(float *)0x1,
             unaff_retaddr);
  CClassicArchive::DoReal((CClassicArchive *)param_1,this,(float *)0x1,(ulong)param_1);
  return;
}
}

// =================================================
// Function: GmQuat::ArchiveGmQuatCompact
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmQuat::ArchiveGmQuatCompact(void *this,GmQuat *param_1,CClassicArchive *param_2)
{
{
  GmVec3 *pGVar1;
  GmQuat *this_00;
  int unaff_ESI;
  int unaff_EDI;
  undefined2 in_FPUControlWord;
  float10 extraout_ST0;
  float10 fVar2;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  undefined1 local_10;
  float local_8;
  float local_4;
  
  this_00 = param_1;
  if (*(int *)(param_1 + 8) != 0) {
    __CIacos();
    local_8 = *(float *)((int)this + 8);
    local_4 = *(float *)((int)this + 0xc);
    param_1 = (GmQuat *)
              (local_4 * local_4 +
              *(float *)((int)this + 4) * *(float *)((int)this + 4) + local_8 * local_8);
    fVar2 = (float10)func_0x009c1b40();
    param_1 = (GmQuat *)(float)fVar2;
    if (_DAT_00bbd8e4 <= (float)param_1) {
      param_1 = (GmQuat *)(1.0 / (float)param_1);
      local_8 = local_8 * (float)param_1;
      local_4 = (float)param_1 * local_4;
    }
    else {
      local_4 = 0.0;
      local_8 = 0.0;
    }
    param_1 = (GmQuat *)CONCAT22(param_1._2_2_,in_FPUControlWord);
    local_10 = (undefined1)
               (int)ROUND(((float)extraout_ST0 * (float)_DAT_00b55d50) / (float)_DAT_00b36110);
    param_1 = (GmQuat *)CONCAT31(param_1._1_3_,local_10);
    CClassicArchive::DoNat8
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_1,(uchar *)0x1,0,unaff_EDI);
    GmFunc::WriteUnitVec3(*(CClassicBuffer **)(this_00 + 4),(GmVec3 *)&local_8);
    return;
  }
  CClassicArchive::DoNat8
            ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(uchar *)0x1,0,unaff_ESI);
  pGVar1 = (GmVec3 *)((int)this + 4);
  GmFunc::ReadUnitVec3(*(CClassicBuffer **)(this_00 + 4),pGVar1);
  __CIsin();
  param_2 = (CClassicArchive *)(float)extraout_ST0_00;
  *(float *)pGVar1 = (float)param_2 * *(float *)pGVar1;
  *(float *)((int)this + 8) = (float)param_2 * *(float *)((int)this + 8);
  *(float *)((int)this + 0xc) = (float)param_2 * *(float *)((int)this + 0xc);
  __CIcos();
  *(float *)this = (float)extraout_ST0_01;
  return;
}
}

// =================================================
// Function: GmQuat::ComputeSquad
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmQuat::ComputeSquad
          (void *this,GmQuat *param_1,GmQuat *param_2,GmQuat *param_3,GmQuat *param_4,
          GmQuat *param_5,float param_6)
{
{
  float fVar1;
  GmQuat *pGVar2;
  SPlugFaceCull *extraout_ECX;
  SPlugFaceCull *extraout_ECX_00;
  float extraout_ECX_01;
  GmIso4 *unaff_EBX;
  GmIso4 *unaff_ESI;
  GmScaleTrans2 *unaff_EDI;
  float10 fVar3;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  CMwCmdScriptVarBool *in_stack_00000024;
  float fStack00000028;
  undefined1 *puVar4;
  GmIso4 *in_stack_ffffff9c;
  GmScaleTrans2 *in_stack_ffffffa0;
  GmIso4 *in_stack_ffffffa4;
  GmIso4 *pGVar5;
  float *pfVar6;
  GmMat43 *pGVar7;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float local_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  float local_2c;
  float local_28;
  SPlugFaceCull aSStack_24 [4];
  float local_20;
  float fStack_1c;
  float local_18 [2];
  float fStack_10;
  float fStack_c;
  float fStack_8;
  undefined1 auStack_4 [4];
  
  SetInverse(&local_20,(GmScaleTrans2 *)param_2,unaff_EDI);
  pGVar2 = param_4;
  SetMult(&local_3c,extraout_ECX,(SPlugFaceCull *)param_4,unaff_ESI);
  SetMult(&local_28,(SPlugFaceCull *)local_18,(SPlugFaceCull *)param_3,unaff_EBX);
  param_5 = (GmQuat *)(local_28 * local_28 + local_30 * local_30 + local_2c * local_2c);
  fVar3 = (float10)func_0x009c1b40();
  param_5 = (GmQuat *)(float)fVar3;
  fVar3 = (float10)func_0x009c1d90();
  param_6 = (float)fVar3;
  fStack_38 = 0.0;
  if ((float)param_5 <= _DAT_00bbd8e4) {
    local_3c = 0.0;
    fStack_40 = param_6;
  }
  else {
    fStack_38 = param_6 / (float)param_5;
    fStack_40 = fStack_38 * local_30;
    local_3c = local_2c * fStack_38;
    fStack_38 = fStack_38 * local_28;
  }
  param_5 = (GmQuat *)(local_18[0] * local_18[0] + local_20 * local_20 + fStack_1c * fStack_1c);
  fVar3 = (float10)func_0x009c1b40();
  param_5 = (GmQuat *)(float)fVar3;
  fVar3 = (float10)func_0x009c1d90();
  param_6 = (float)fVar3;
  if ((float)param_5 <= _DAT_00bbd8e4) {
    fStack_44 = 0.0;
    fStack_48 = 0.0;
    fStack_4c = param_6;
  }
  else {
    fStack_44 = param_6 / (float)param_5;
    fStack_4c = fStack_44 * local_20;
    fStack_48 = fStack_1c * fStack_44;
    fStack_44 = fStack_44 * local_18[0];
  }
  fVar1 = (float)_DAT_00bbd900;
  pGVar5 = (GmIso4 *)((fStack_4c + fStack_40) * fVar1);
  pGVar7 = (GmMat43 *)((fStack_48 + local_3c) * fVar1);
  fVar1 = fVar1 * (fStack_44 + fStack_38);
  param_5 = (GmQuat *)
            ((float)pGVar7 * (float)pGVar7 + (float)pGVar5 * (float)pGVar5 + fVar1 * fVar1);
  fVar3 = (float10)func_0x009c1b40();
  param_5 = (GmQuat *)(float)fVar3;
  if ((float)param_5 <= _DAT_00bbd8e4) {
    SetIdentity(&fStack_34,(GmMat43 *)in_stack_ffffff9c);
  }
  else {
    __CIsin();
    param_6 = (float)extraout_ST0;
    puVar4 = &stack0xffffffa8;
    param_5 = (GmQuat *)(param_6 / (float)param_5);
    pGVar5 = (GmIso4 *)((float)param_5 * (float)pGVar5);
    pGVar7 = (GmMat43 *)((float)pGVar7 * (float)param_5);
    __CIcos();
    param_5 = (GmQuat *)(float)extraout_ST0_00;
    Set(&fStack_34,(CMwCmdScriptVarBool *)param_5,(int)puVar4);
  }
  SetMult(auStack_4,(SPlugFaceCull *)param_2,(SPlugFaceCull *)&fStack_34,in_stack_ffffff9c);
  SetInverse(&fStack_10,(GmScaleTrans2 *)pGVar2,in_stack_ffffffa0);
  SetMult(&local_2c,extraout_ECX_00,(SPlugFaceCull *)in_stack_00000024,in_stack_ffffffa4);
  SetMult(local_18,(SPlugFaceCull *)&fStack_8,(SPlugFaceCull *)param_2,pGVar5);
  in_stack_00000024 =
       (CMwCmdScriptVarBool *)
       (local_18[0] * local_18[0] + local_20 * local_20 + fStack_1c * fStack_1c);
  fVar3 = (float10)func_0x009c1b40();
  in_stack_00000024 = (CMwCmdScriptVarBool *)(float)fVar3;
  fVar3 = (float10)func_0x009c1d90();
  fStack00000028 = (float)fVar3;
  if ((float)in_stack_00000024 <= _DAT_00bbd8e4) {
    local_28 = 0.0;
    local_2c = 0.0;
    local_30 = fStack00000028;
  }
  else {
    local_28 = fStack00000028 / (float)in_stack_00000024;
    local_30 = local_28 * local_20;
    local_2c = fStack_1c * local_28;
    local_28 = local_28 * local_18[0];
  }
  in_stack_00000024 =
       (CMwCmdScriptVarBool *)(fStack_8 * fStack_8 + fStack_10 * fStack_10 + fStack_c * fStack_c);
  fVar3 = (float10)func_0x009c1b40();
  in_stack_00000024 = (CMwCmdScriptVarBool *)(float)fVar3;
  fVar3 = (float10)func_0x009c1d90();
  fStack00000028 = (float)fVar3;
  if ((float)in_stack_00000024 <= _DAT_00bbd8e4) {
    fStack_34 = 0.0;
    fStack_38 = 0.0;
    local_3c = fStack00000028;
  }
  else {
    fStack_34 = fStack00000028 / (float)in_stack_00000024;
    local_3c = fStack_34 * fStack_10;
    fStack_38 = fStack_c * fStack_34;
    fStack_34 = fStack_34 * fStack_8;
  }
  fStack_40 = (float)_DAT_00bbd900;
  fStack_48 = (local_3c + local_30) * fStack_40;
  fStack_44 = (fStack_38 + local_2c) * fStack_40;
  fStack_40 = fStack_40 * (fStack_34 + local_28);
  in_stack_00000024 =
       (CMwCmdScriptVarBool *)
       (fStack_44 * fStack_44 + fStack_48 * fStack_48 + fStack_40 * fStack_40);
  fVar3 = (float10)func_0x009c1b40();
  in_stack_00000024 = (CMwCmdScriptVarBool *)(float)fVar3;
  if ((float)in_stack_00000024 <= _DAT_00bbd8e4) {
    SetIdentity(aSStack_24,pGVar7);
  }
  else {
    __CIsin();
    fStack00000028 = (float)extraout_ST0_01;
    pfVar6 = &fStack_48;
    in_stack_00000024 = (CMwCmdScriptVarBool *)(fStack00000028 / (float)in_stack_00000024);
    fStack_48 = (float)in_stack_00000024 * fStack_48;
    fStack_44 = fStack_44 * (float)in_stack_00000024;
    fStack_40 = (float)in_stack_00000024 * fStack_40;
    __CIcos();
    in_stack_00000024 = (CMwCmdScriptVarBool *)(float)extraout_ST0_02;
    Set(aSStack_24,in_stack_00000024,(int)pfVar6);
  }
  SetMult(auStack_4,(SPlugFaceCull *)pGVar2,aSStack_24,(GmIso4 *)pGVar7);
  SetSquad(this,*(GmQuat **)param_2,SUB41(*(undefined4 *)(param_2 + 4),0),*(GmQuat **)(param_2 + 8),
           *(GmQuat **)(param_2 + 0xc),(GmQuat *)&param_4,extraout_ECX_01);
  return;
}
}

// =================================================
// Function: GmQuat::GetRotation
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmQuat::GetRotation(void *this,GmQuat *param_1,float *param_2,GmVec3 *param_3)
{
{
  float fVar1;
  float10 fVar2;
  float10 extraout_ST0;
  
  *param_2 = *(float *)((int)this + 4);
  param_2[1] = *(float *)((int)this + 8);
  fVar1 = *(float *)((int)this + 0xc);
  param_2[2] = fVar1;
  if (_DAT_00d1a87c < *param_2 * *param_2 + param_2[1] * param_2[1] + fVar1 * fVar1) {
    fVar2 = (float10)func_0x009c1b40();
    fVar1 = 1.0 / (float)fVar2;
    *param_2 = fVar1 * *param_2;
    param_2[1] = param_2[1] * fVar1;
    param_2[2] = fVar1 * param_2[2];
    __CIatan2();
    *(float *)param_1 = (float)extraout_ST0 + (float)extraout_ST0;
    return;
  }
  *param_2 = 1.0;
  param_2[1] = 0.0;
  param_2[2] = 0.0;
  *(undefined4 *)param_1 = 0;
  return;
}
}

// =================================================
// Function: GmQuat::GetYawPitchRoll
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmQuat::GetYawPitchRoll(void *this,GmQuat *param_1,float *param_2,float *param_3,float *param_4)
{
{
  float fVar1;
  float fVar2;
  float10 extraout_ST0;
  float10 fVar3;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  
  fVar1 = *(float *)((int)this + 8) * *(float *)((int)this + 4) +
          *(float *)((int)this + 0xc) * *(float *)this;
  fVar2 = fVar1 - (float)_DAT_00b313b8;
  if ((ABS(fVar2) < _DAT_00bbd8e4) || (-1 < (int)fVar2)) {
    __CIatan2();
    *(float *)param_1 = (float)extraout_ST0_02 * (float)_DAT_00b36290;
    *param_3 = _DAT_00bbd8f0;
    *param_2 = 0.0;
    return;
  }
  fVar1 = fVar1 + (float)_DAT_00b313b8;
  if ((_DAT_00bbd8e4 <= ABS(fVar1)) && (((uint)fVar1 & 0x80000000) == 0)) {
    __CIatan2();
    *(float *)param_1 = (float)extraout_ST0;
    fVar3 = (float10)func_0x009c1d90();
    *param_3 = (float)fVar3;
    __CIatan2();
    *param_2 = (float)extraout_ST0_00;
    return;
  }
  __CIatan2();
  *(float *)param_1 = (float)extraout_ST0_01 + (float)extraout_ST0_01;
  *param_3 = _DAT_00b36108;
  *param_2 = 0.0;
  return;
}
}

// =================================================
// Function: GmQuat::Mult
// =================================================
void __thiscall GmQuat::Mult(void *this,GmIso3 *param_1,GmIso3 *param_2)
{
{
  GmVec4::Set(this,(CMwCmdScriptVarBool *)&stack0xfffffff0,
              (int)(*(float *)param_1 * *(float *)this -
                   (*(float *)((int)this + 0xc) * *(float *)(param_1 + 0xc) +
                   *(float *)((int)this + 4) * *(float *)(param_1 + 4) +
                   *(float *)((int)this + 8) * *(float *)(param_1 + 8))));
  return;
}
}

// =================================================
// Function: GmQuat::Normalize
// =================================================
void __thiscall GmQuat::Normalize(void *this,GmQuat *param_1)
{
{
  float fVar1;
  float10 fVar2;
  
  fVar2 = (float10)func_0x009c1b40();
  fVar1 = 1.0 / (float)fVar2;
  *(float *)this = fVar1 * *(float *)this;
  *(float *)((int)this + 4) = *(float *)((int)this + 4) * fVar1;
  *(float *)((int)this + 8) = *(float *)((int)this + 8) * fVar1;
  *(float *)((int)this + 0xc) = fVar1 * *(float *)((int)this + 0xc);
  return;
}
}

// =================================================
// Function: GmQuat::Set
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmQuat::Set(void *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  int iVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  float10 fVar5;
  
  if (0.0 < *(float *)param_1 + *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0x20)) {
    fVar5 = (float10)func_0x009c1b40();
    fVar3 = (float)_DAT_00b313b8;
    *(float *)this = (float)fVar5 * fVar3;
    fVar3 = fVar3 / (float)fVar5;
    *(float *)((int)this + 4) = fVar3 * (*(float *)(param_1 + 0x1c) - *(float *)(param_1 + 0x14));
    *(float *)((int)this + 8) = (*(float *)(param_1 + 8) - *(float *)(param_1 + 0x18)) * fVar3;
    *(float *)((int)this + 0xc) = (*(float *)(param_1 + 0xc) - *(float *)(param_1 + 4)) * fVar3;
    return;
  }
  uVar4 = (uint)(*(float *)param_1 < *(float *)(param_1 + 0x10));
  if (*(float *)(param_1 + uVar4 * 0x10) < *(float *)(param_1 + 0x20)) {
    uVar4 = 2;
  }
  iVar1 = *(int *)(&DAT_00d1a86c + uVar4 * 4);
  iVar2 = *(int *)(&DAT_00d1a86c + iVar1 * 4);
  fVar5 = (float10)func_0x009c1b40();
  fVar3 = (float)_DAT_00b313b8;
  *(float *)((int)this + uVar4 * 4 + 4) = (float)fVar5 * fVar3;
  fVar3 = fVar3 / (float)fVar5;
  *(float *)this =
       fVar3 * (*(float *)(param_1 + (iVar2 * 3 + iVar1) * 4) -
               *(float *)(param_1 + (iVar1 * 3 + iVar2) * 4));
  *(float *)((int)this + iVar1 * 4 + 4) =
       (*(float *)(param_1 + (uVar4 * 3 + iVar1) * 4) +
       *(float *)(param_1 + (iVar1 * 3 + uVar4) * 4)) * fVar3;
  *(float *)((int)this + iVar2 * 4 + 4) =
       (*(float *)(param_1 + (uVar4 * 3 + iVar2) * 4) +
       *(float *)(param_1 + (iVar2 * 3 + uVar4) * 4)) * fVar3;
  return;
}
}

// =================================================
// Function: GmQuat::SetIdentity
// =================================================
void __thiscall GmQuat::SetIdentity(void *this,GmMat43 *param_1)
{
{
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  return;
}
}

// =================================================
// Function: GmQuat::SetInverse
// =================================================
void __thiscall GmQuat::SetInverse(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2)
{
{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(float *)((int)this + 4) = -*(float *)(param_1 + 4);
  *(float *)((int)this + 8) = -*(float *)(param_1 + 8);
  *(float *)((int)this + 0xc) = -*(float *)(param_1 + 0xc);
  return;
}
}

// =================================================
// Function: GmQuat::SetMult
// =================================================
void __thiscall
GmQuat::SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3)
{
{
  *(float *)this =
       *(float *)param_1 * *(float *)param_2 -
       (*(float *)(param_1 + 0xc) * *(float *)(param_2 + 0xc) +
       *(float *)(param_1 + 4) * *(float *)(param_2 + 4) +
       *(float *)(param_1 + 8) * *(float *)(param_2 + 8));
  *(float *)((int)this + 4) =
       (*(float *)(param_1 + 8) * *(float *)(param_2 + 0xc) +
       *(float *)param_1 * *(float *)(param_2 + 4) + *(float *)(param_1 + 4) * *(float *)param_2) -
       *(float *)(param_1 + 0xc) * *(float *)(param_2 + 8);
  *(float *)((int)this + 8) =
       (*(float *)(param_1 + 0xc) * *(float *)(param_2 + 4) +
       *(float *)(param_1 + 8) * *(float *)param_2 + *(float *)param_1 * *(float *)(param_2 + 8)) -
       *(float *)(param_2 + 0xc) * *(float *)(param_1 + 4);
  *(float *)((int)this + 0xc) =
       (*(float *)(param_1 + 4) * *(float *)(param_2 + 8) +
       *(float *)param_2 * *(float *)(param_1 + 0xc) + *(float *)(param_2 + 0xc) * *(float *)param_1
       ) - *(float *)(param_1 + 8) * *(float *)(param_2 + 4);
  return;
}
}

// =================================================
// Function: GmQuat::SetRotation
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmQuat::SetRotation(void *this,GmMat2 *param_1,float param_2)
{
{
  float fVar1;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  __CIcos();
  *(float *)this = (float)extraout_ST0;
  __CIsin();
  fVar1 = (float)extraout_ST0_00;
  *(float *)((int)this + 4) = fVar1 * *(float *)param_2;
  *(float *)((int)this + 8) = *(float *)((int)param_2 + 4) * fVar1;
  *(float *)((int)this + 0xc) = fVar1 * *(float *)((int)param_2 + 8);
  return;
}
}

// =================================================
// Function: GmQuat::SetSlerp
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmQuat::SetSlerp(void *this,GmQuat *param_1,GmQuat param_2,GmQuat *param_3,float param_4)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  undefined3 in_stack_00000009;
  float *in_stack_00000014;
  float in_stack_00000018;
  
  fVar1 = (float)param_1 * *in_stack_00000014 +
          (float)param_3 * in_stack_00000014[2] + _param_2 * in_stack_00000014[1] +
          param_4 * in_stack_00000014[3];
  if (fVar1 < 0.0) {
    fVar1 = -fVar1;
    _param_2 = -_param_2;
    param_3 = (GmQuat *)-(float)param_3;
    param_4 = -param_4;
    param_1 = (GmQuat *)-(float)param_1;
  }
  fVar3 = 1.0 - in_stack_00000018;
  fVar2 = ABS(fVar3);
  fVar4 = ABS(in_stack_00000018);
  if (fVar2 < fVar4 != (fVar2 == fVar4)) {
    fVar2 = fVar4;
  }
  if ((float)_DAT_00b36288 < fVar2 * (1.0 - fVar1)) {
    __CIacos();
    __CIsin();
    if (_DAT_00bbd8e4 <= ABS((float)extraout_ST0)) {
      fVar1 = 1.0 / (float)extraout_ST0;
      __CIsin();
      fVar3 = (float)extraout_ST0_00 * fVar1;
      __CIsin();
      in_stack_00000018 = (float)extraout_ST0_01 * fVar1;
    }
  }
  *(float *)((int)this + 4) = in_stack_00000018 * in_stack_00000014[1] + fVar3 * _param_2;
  *(float *)((int)this + 8) = fVar3 * (float)param_3 + in_stack_00000014[2] * in_stack_00000018;
  *(float *)((int)this + 0xc) = fVar3 * param_4 + in_stack_00000014[3] * in_stack_00000018;
  *(float *)this = in_stack_00000018 * *in_stack_00000014 + (float)param_1 * fVar3;
  return;
}
}

// =================================================
// Function: GmQuat::SetSquad
// =================================================
void __thiscall
GmQuat::SetSquad(void *this,GmQuat *param_1,GmQuat param_2,GmQuat *param_3,GmQuat *param_4,
                GmQuat *param_5,float param_6)
{
{
  float unaff_retaddr;
  undefined3 in_stack_00000009;
  undefined1 local_18 [4];
  GmQuat *local_c;
  GmQuat local_8;
  GmQuat *local_4;
  
  SetSlerp(&param_1,param_1,param_2,param_3,(float)param_4);
  SetSlerp(local_18,*(GmQuat **)param_3,SUB41(*(undefined4 *)(param_3 + 4),0),
           *(GmQuat **)(param_3 + 8),*(float *)(param_3 + 0xc));
  SetSlerp(this,local_c,local_8,local_4,unaff_retaddr);
  return;
}
}

// =================================================
// Function: GmQuat::SetYawPitchRoll
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmQuat::SetYawPitchRoll(void *this,GmQuat *param_1,float param_2,float param_3,float param_4)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST0_04;
  
  __CIsin();
  __CIcos();
  __CIsin();
  __CIcos();
  __CIsin();
  fVar1 = (float)extraout_ST0_03;
  __CIcos();
  fVar2 = (float)extraout_ST0_04;
  fVar6 = (float)extraout_ST0 * (float)extraout_ST0_01;
  fVar4 = (float)extraout_ST0_00 * (float)extraout_ST0_02;
  fVar3 = (float)extraout_ST0_00 * (float)extraout_ST0_01;
  fVar5 = (float)extraout_ST0 * (float)extraout_ST0_02;
  *(float *)this = fVar1 * fVar6 - fVar2 * fVar4;
  *(float *)((int)this + 4) = -fVar6 * fVar2 - fVar1 * fVar4;
  *(float *)((int)this + 8) = -fVar3 * fVar1 - fVar5 * fVar2;
  *(float *)((int)this + 0xc) = fVar5 * fVar1 - fVar3 * fVar2;
  return;
}
}

