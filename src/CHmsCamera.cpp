// Class implementation: CHmsCamera

// =================================================
// Function: CHmsCamera::CHmsCamera
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsCamera::CHmsCamera(CHmsCamera *this,CHmsCamera *param_1)
{
{
  undefined4 uVar1;
  CHmsPicker *this_00;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  CMwNod *extraout_EAX_00;
  CHmsPicker *unaff_EBP;
  CMwNod *this_01;
  GmMat43 *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  undefined1 uStack00000008;
  void *in_stack_0000000c;
  undefined1 uStack00000010;
  undefined1 uStack00000014;
  GmMat43 *pGVar3;
  GmMat43 *pGVar4;
  CHmsCamera *pCVar5;
  ulong uVar6;
  CMwNod *pCVar7;
  void *local_c;
  CMwCmdFastCall *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = (CMwCmdFastCall *)&LAB_00a9594a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar5 = this;
  CHmsPoc::CHmsPoc((CHmsPoc *)this,(CHmsPoc *)(DAT_00cca150 ^ (uint)&stack0xffffffd4));
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x1a4,unaff_EDI);
  *(undefined4 *)(this + 0x20c) = 0;
  pGVar4 = _DAT_00b56554;
  pGVar3 = _DAT_00b31460;
  *(undefined4 *)(this + 0x210) = 0;
  GmFrustum::Set(this + 0x118,_DAT_00b36154,0x3f800000);
  uVar2 = _DAT_00b2c060;
  *(undefined4 *)(this + 0x1cc) = 0x3f800000;
  *(undefined4 *)(this + 0x1c4) = uVar2;
  *(undefined4 *)(this + 0x1c8) = uVar2;
  *(undefined4 *)(this + 0x1d0) = 0x3f800000;
  uVar6 = 0x3f800000;
  *(undefined4 *)(this + 0x1d4) = uVar2;
  pCVar7 = (CMwNod *)0x3f800000;
  *(undefined4 *)(this + 0x1d8) = uVar2;
  *(undefined4 *)(this + 0x1dc) = 0x3f800000;
  *(undefined4 *)(this + 0x1e0) = 0x3f800000;
  *(undefined4 *)(this + 0x1e4) = uVar2;
  *(undefined4 *)(this + 0x1e8) = uVar2;
  *(undefined4 *)(this + 0x1ec) = 0x3f800000;
  *(undefined4 *)(this + 0x1f0) = 0x3f800000;
  *(undefined4 *)(this + 0x1f8) = 0;
  *(undefined4 *)(this + 0x1fc) = 1;
  *(undefined4 *)(this + 0x200) = 0;
  *(undefined4 *)(this + 0x134) = 1;
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x148) = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  *(undefined4 *)(this + 0x150) = 0x3f800000;
  *(undefined4 *)(this + 0x154) = 1;
  *(undefined4 *)(this + 0x158) = 1;
  *(undefined4 *)(this + 0x15c) = 1;
  GmIso4::SetIdentity(this + 0x58,pGVar3);
  GmIso4::SetIdentity(this + 0x18,pGVar4);
  GmIso4::SetIdentity(this + 0x88,unaff_ESI);
  *(undefined4 *)(this + 0x160) = 0;
  *(undefined4 *)(this + 0x1b0) = 0xffffffff;
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0x1b4) = 0;
  *(undefined4 *)(this + 0x1b8) = 0;
  this_00 = operator_new(0x10c);
  uStack00000008 = 3;
  if (this_00 == (CHmsPicker *)0x0) {
    uVar2 = 0;
  }
  else {
    CHmsPicker::CHmsPicker(this_00,unaff_EBP);
    uVar2 = extraout_EAX;
  }
  *(undefined4 *)(this + 0x164) = _DAT_00b36adc;
  uVar1 = DAT_00b36188;
  in_stack_0000000c = (void *)CONCAT31(in_stack_0000000c._1_3_,2);
  *(undefined4 *)(this + 0x1a0) = uVar2;
  *(undefined4 *)(this + 0x170) = uVar1;
  *(undefined4 *)(this + 0x168) = 1;
  LensUpdateFocalSize(this,pCVar5);
  *(undefined4 *)(this + 0x178) = _DAT_00b36ad4;
  *(undefined4 *)(this + 0x174) = 0;
  uVar2 = _DAT_00b313ac;
  *(undefined4 *)(this + 0x180) = 0;
  *(undefined4 *)(this + 0x17c) = uVar2;
  uVar2 = _DAT_00b362a4;
  *(undefined4 *)(this + 0x208) = _DAT_00b362a4;
  *(undefined4 *)(this + 0x204) = uVar2;
  *(undefined4 *)(this + 0x184) = 0;
  uVar2 = _DAT_00b33a54;
  *(undefined4 *)(this + 0x188) = 0;
  *(undefined4 *)(this + 0x18c) = 1;
  *(undefined4 *)(this + 400) = 1;
  *(undefined4 *)(this + 0x198) = uVar2;
  uVar2 = _DAT_00b2f720;
  *(undefined4 *)(this + 0x194) = 0;
  *(undefined4 *)(this + 0x19c) = uVar2;
  *(undefined4 *)(this + 500) = 0;
  *(undefined4 *)(this + 0x1c0) = 0;
  local_8 = operator_new(0x24);
  uStack00000010 = 4;
  if (local_8 == (CMwCmdFastCall *)0x0) {
    this_01 = (CMwNod *)0x0;
  }
  else {
    CMwCmdFastCall::CMwCmdFastCall
              (local_8,(CMwCmdFastCall *)this,(CMwNod *)Run,(_func___cdecl_void *)0x1b,uVar6);
    this_01 = extraout_EAX_00;
  }
  uStack00000014 = 2;
  if (this_01 != *(CMwNod **)(this + 0x20c)) {
    if (this_01 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_01,pCVar7);
    }
    if (*(CMwNod **)(this + 0x20c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x20c),pCVar7);
    }
    *(CMwNod **)(this + 0x20c) = this_01;
  }
  ExceptionList = in_stack_0000000c;
  return;
}
}

// =================================================
// Function: CHmsCamera::ForceLocation
// =================================================
void __thiscall CHmsCamera::ForceLocation(CHmsCamera *this,CHmsCamera *param_1,GmIso4 *param_2)
{
{
  int iVar1;
  CHmsCamera *pCVar2;
  CHmsCamera *pCVar3;
  GmScaleTrans2 *pGVar4;
  
  pCVar2 = param_1;
  pCVar3 = this + 0x58;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pCVar3 = *(undefined4 *)pCVar2;
    pCVar2 = pCVar2 + 4;
    pCVar3 = pCVar3 + 4;
  }
  pGVar4 = (GmScaleTrans2 *)(this + 0x18);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pGVar4 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    pGVar4 = pGVar4 + 4;
  }
  GmIso4::SetInverse(this + 0x88,(GmScaleTrans2 *)(this + 0x18),(GmScaleTrans2 *)param_2);
  return;
}
}

// =================================================
// Function: CHmsCamera::GetCamVal
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsCamera::GetCamVal(CHmsCamera *this,GmCamFreeVal *param_1,GmCamVal *param_2)
{
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  CHmsCamera *unaff_EDI;
  GmCamFreeVal *pGVar4;
  float fVar5;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  puVar2 = (undefined4 *)(**(code **)(*(int *)this + 0x78))();
  pGVar4 = param_1;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pGVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    pGVar4 = pGVar4 + 4;
  }
  fVar5 = GetFov(this,unaff_EDI);
  *(float *)(param_1 + 0x30) = fVar5;
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(this + 0x164);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(this + 0x170);
  uVar1 = _DAT_00b2c060;
  if (in_stack_0000000c == 0) {
    *(undefined4 *)(param_1 + 0x3c) = _DAT_00b2c060;
  }
  else if (*(int *)(this + 0x118) == 0) {
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(this + 0x124);
  }
  else {
    *(float *)(param_1 + 0x3c) = *(float *)(this + 0x124) - *(float *)(this + 0x130);
  }
  if (in_stack_00000010 != 0) {
    if (*(int *)(this + 0x118) != 0) {
      *(float *)(param_1 + 0x40) = *(float *)(this + 0x130) + *(float *)(this + 0x124);
      return;
    }
    uVar1 = *(undefined4 *)(this + 0x130);
  }
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  return;
}
}

// =================================================
// Function: CHmsCamera::GetFov
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall CHmsCamera::GetFov(CHmsCamera *this,CHmsCamera *param_1)
{
{
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  if (*(int *)(this + 0x134) != 2) {
    __CIatan();
    return (((float)extraout_ST0 + (float)extraout_ST0) / (float)_DAT_00b36110) *
           (float)_DAT_00b36ab8;
  }
  __CIatan();
  return (((float)extraout_ST0_00 + (float)extraout_ST0_00) / (float)_DAT_00b36110) *
         (float)_DAT_00b36ab8;
}
}

// =================================================
// Function: CHmsCamera::GetRenderFrustum
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsCamera::GetRenderFrustum(CHmsCamera *this,CHmsCamera *param_1,GmFrustum *param_2)
{
{
  int iVar1;
  GmRectAligned *unaff_ESI;
  CHmsCamera *pCVar2;
  GmRectAligned *unaff_EDI;
  void *in_stack_00000014;
  GmIso4 *pGVar3;
  GmIso3 *pGVar4;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  CMwCmdScriptVarBool *local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  SPlugFaceCull local_18 [8];
  undefined1 local_10 [12];
  GmIso3 local_4 [4];
  
  if (*(int *)(this + 0x200) != 0) {
    if (*(int *)(this + 0x118) == 0) {
      pGVar4 = *(GmIso3 **)(this + 0x124);
    }
    else {
      pGVar4 = (GmIso3 *)(*(float *)(this + 0x124) - *(float *)(this + 0x130));
    }
    if (*(int *)(this + 0x118) == 0) {
      pGVar3 = *(GmIso4 **)(this + 0x130);
    }
    else {
      pGVar3 = (GmIso4 *)(*(float *)(this + 0x130) + *(float *)(this + 0x124));
    }
    local_40 = *(undefined4 *)(this + 0x11c);
    local_3c = *(undefined4 *)(this + 0x120);
    local_38 = *(undefined4 *)(this + 0x128);
    local_34 = *(undefined4 *)(this + 300);
    GmScaleTrans2::SetRect_ConvTo_Rectm1p1(local_10,(GmScaleTrans2 *)&local_40,unaff_EDI);
    GmScaleTrans2::SetRect_MoveTo_Rect
              (&local_1c,(GmScaleTrans2 *)(this + 0x1e4),(GmRectAligned *)(this + 0x1c4),unaff_ESI);
    local_40 = 0x3f800000;
    local_3c = 0x3f800000;
    local_20 = 0x3f800000;
    local_24 = _DAT_00b2c060;
    local_28 = _DAT_00b2c060;
    local_1c = 0x3f800000;
    GmRectAligned::SetMult(&local_38,(SPlugFaceCull *)&local_28,local_18,pGVar3);
    GmRectAligned::Mult(&local_34,local_4,pGVar4);
    GmFrustum::Set(in_stack_00000014,local_30,local_2c);
    return;
  }
  pCVar2 = this + 0x118;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)param_1 = *(undefined4 *)pCVar2;
    pCVar2 = pCVar2 + 4;
    param_1 = param_1 + 4;
  }
  return;
}
}

// =================================================
// Function: CHmsCamera::LensUpdateFocalSize
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsCamera::LensUpdateFocalSize(CHmsCamera *this,CHmsCamera *param_1)
{
{
  float fVar1;
  
  fVar1 = (*(float *)(this + 300) - *(float *)(this + 0x120)) * (float)_DAT_00b313b8;
  if (*(int *)(this + 0x168) == 0) {
    *(float *)(this + 0x170) = *(float *)(this + 0x16c) * fVar1;
    return;
  }
  *(float *)(this + 0x16c) = *(float *)(this + 0x170) / fVar1;
  return;
}
}

// =================================================
// Function: CHmsCamera::ScissorRectSet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsCamera::ScissorRectSet(CHmsCamera *this,CHmsCamera *param_1,GmRectAligned *param_2)
{
{
  CHmsCamera *this_00;
  float fVar1;
  ulong uVar2;
  GmVec2 *unaff_ESI;
  GmVec2 *unaff_EDI;
  float local_10;
  float local_c;
  undefined4 local_4;
  
  this_00 = this + 0x1d4;
  *(float *)this_00 = *(float *)param_1;
  *(undefined4 *)(this + 0x1d8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x1dc) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x1e0) = *(undefined4 *)(param_1 + 0xc);
  local_10 = _DAT_00b2c060;
  fVar1 = (float)_DAT_00b55920;
  if (*(float *)this_00 < fVar1) {
    *(float *)this_00 = _DAT_00b2c060;
  }
  if (*(float *)(this + 0x1d8) < fVar1) {
    *(float *)(this + 0x1d8) = local_10;
  }
  if (1.0 < *(float *)(this + 0x1dc)) {
    *(undefined4 *)(this + 0x1dc) = 0x3f800000;
  }
  if (1.0 < *(float *)(this + 0x1e0)) {
    *(undefined4 *)(this + 0x1e0) = 0x3f800000;
  }
  local_c = local_10;
  uVar2 = GmVec2::IsNearlyEqual(this_00,(GmVec2 *)&local_10,unaff_EDI);
  if (uVar2 != 0) {
    local_4 = 0x3f800000;
    uVar2 = GmVec2::IsNearlyEqual(this + 0x1dc,(GmVec2 *)&local_4,unaff_ESI);
    if (uVar2 != 0) {
      *(undefined4 *)(this + 0x1f8) = 0;
      return;
    }
  }
  *(undefined4 *)(this + 0x1f8) = 1;
  return;
}
}

// =================================================
// Function: CHmsCamera::ScissorRectSetEnable
// =================================================
void __thiscall CHmsCamera::ScissorRectSetEnable(CHmsCamera *this,CHmsCamera *param_1,int param_2)
{
{
  *(CHmsCamera **)(this + 0x1fc) = param_1;
  return;
}
}

// =================================================
// Function: CHmsCamera::SetCamVal
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsCamera::SetCamVal
          (CHmsCamera *this,CSceneCamera *param_1,GmCamVal *param_2,GmVec3 *param_3,int param_4)
{
{
  float unaff_ESI;
  GmIso4 *unaff_EDI;
  float unaff_retaddr;
  
  if (param_2 == (GmCamVal *)0x0) {
    (**(code **)(*(int *)this + 0x7c))();
  }
  else {
    ForceLocation(this,(CHmsCamera *)param_1,unaff_EDI);
  }
  SetFov(this,*(CHmsCamera **)(param_1 + 0x30),unaff_ESI);
  *(undefined4 *)(this + 0x164) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x170) = *(undefined4 *)(param_1 + 0x38);
  if (_DAT_00b2c060 != *(float *)(param_1 + 0x40)) {
    SetFarZ(this,*(CHmsCamera **)(param_1 + 0x40),unaff_retaddr);
  }
  if (_DAT_00b2c060 != *(float *)(param_1 + 0x3c)) {
    SetNearZ(this,*(GmFrustum **)(param_1 + 0x3c),(float)param_1);
  }
  return;
}
}

// =================================================
// Function: CHmsCamera::SetDrawRect
// =================================================
void __thiscall CHmsCamera::SetDrawRect(CHmsCamera *this,CHmsCamera *param_1,GmRectAligned *param_2)
{
{
  *(undefined4 *)(this + 0x1c4) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x1c8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x1cc) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x1d0) = *(undefined4 *)(param_1 + 0xc);
  return;
}
}

// =================================================
// Function: CHmsCamera::SetFov
// =================================================
void __thiscall CHmsCamera::SetFov(CHmsCamera *this,CHmsCamera *param_1,float param_2)
{
{
  CHmsCamera *this_00;
  float fVar1;
  float fVar2;
  float fVar3;
  
  this_00 = this + 0x118;
  if (*(int *)this_00 == 0) {
    fVar1 = *(float *)(this + 0x124);
  }
  else {
    fVar1 = *(float *)(this + 0x124) - *(float *)(this + 0x130);
  }
  if (*(int *)this_00 == 0) {
    fVar2 = *(float *)(this + 0x130);
  }
  else {
    fVar2 = *(float *)(this + 0x130) + *(float *)(this + 0x124);
  }
  fVar3 = ((*(float *)(this + 0x128) + *(float *)(this + 0x11c)) -
          (*(float *)(this + 0x11c) - *(float *)(this + 0x128))) /
          ((*(float *)(this + 300) + *(float *)(this + 0x120)) -
          (*(float *)(this + 0x120) - *(float *)(this + 300)));
  if (*(int *)(this + 0x134) != 2) {
    GmFrustum::SetFovY(this_00,(GmFrustum *)param_1,fVar3,fVar1,fVar2,fVar2);
    return;
  }
  GmFrustum::SetFovX(this_00,(GmFrustum *)param_1,fVar3,fVar1,fVar2,fVar2);
  return;
}
}

// =================================================
// Function: CHmsCamera::SetFrustum
// =================================================
void __thiscall CHmsCamera::SetFrustum(CHmsCamera *this,CHmsCamera *param_1,GmFrustum *param_2)
{
{
  GmFrustum::Set(this + 0x118,(CMwCmdScriptVarBool *)param_1,(int)param_2);
  return;
}
}

// =================================================
// Function: CHmsCamera::SetLocation
// =================================================
void __thiscall CHmsCamera::SetLocation(CHmsCamera *this,CPlugTree *param_1,GmIso4 *param_2)
{
{
  int iVar1;
  CHmsCamera *pCVar2;
  
  pCVar2 = this + 0x58;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pCVar2 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    pCVar2 = pCVar2 + 4;
  }
  return;
}
}

// =================================================
// Function: CHmsCamera::SetNearZ
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsCamera::SetNearZ(CHmsCamera *this,GmFrustum *param_1,float param_2)
{
{
  GmFrustum::Set(this + 0x118,*(CMwCmdScriptVarBool **)(this + 0x11c),*(int *)(this + 0x120));
  return;
}
}

// =================================================
// Function: CHmsCamera::SetZone
// =================================================
void __thiscall CHmsCamera::SetZone(CHmsCamera *this,CSceneSector *param_1,CHmsZone *param_2)
{
{
  GmIso4 *unaff_retaddr;
  
  *(CSceneSector **)(this + 0x14) = param_1;
  ForceLocation(this,(CHmsCamera *)param_2,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsCamera::ZClipCompute
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsCamera::ZClipCompute
          (CHmsCamera *this,CHmsCamera *param_1,float param_2,GmFrustum *param_3,
          SHmsRenderRect *param_4)
{
{
  float fVar1;
  CMwCmdScriptVarBool *pCVar2;
  int iVar3;
  CHmsCamera *pCVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  int iVar12;
  GmRectAligned *unaff_EBX;
  GmRectAligned *unaff_EBP;
  GmFrustum *unaff_ESI;
  GmFrustum *unaff_EDI;
  float fVar13;
  void *in_stack_00000014;
  GmIso4 *in_stack_ffffffd8;
  undefined1 local_14 [4];
  SPlugFaceCull aSStack_10 [4];
  CMwCmdScriptVarBool *local_c;
  float local_8;
  float local_4;
  
  if ((*(int *)(this + 0x194) == 0) || (*(int *)(this + 500) == *(int *)(DAT_00d731e0 + 0xc0)))
  goto LAB_0053fd7d;
  *(int *)(this + 500) = *(int *)(DAT_00d731e0 + 0xc0);
  fVar13 = (*(float *)(this + 0x198) * ((float)param_1 - 1.0) + 1.0) * *(float *)(this + 0x178);
  *(float *)(this + 0x178) = fVar13;
  if (*(float *)(this + 0x19c) <= fVar13) {
    if (*(int *)(this + 0x118) == 0) {
      fVar1 = *(float *)(this + 0x130);
    }
    else {
      fVar1 = *(float *)(this + 0x130) + *(float *)(this + 0x124);
    }
    if (fVar1 * (float)_DAT_00b44a20 < fVar13) {
      fVar13 = GmFrustum::GetFarZ(this + 0x118,unaff_EDI);
      fVar13 = fVar13 * (float)_DAT_00b565e8;
      goto LAB_0053fd2e;
    }
  }
  else {
    fVar13 = *(float *)(this + 0x19c);
LAB_0053fd2e:
    *(float *)(this + 0x178) = fVar13;
  }
  if (*(int *)(this + 0x118) == 0) {
    fVar13 = *(float *)(this + 0x130);
  }
  else {
    fVar13 = *(float *)(this + 0x130) + *(float *)(this + 0x124);
  }
  *(uint *)(this + 0x174) = (uint)(*(float *)(this + 0x178) < fVar13 * (float)_DAT_00b44a20);
LAB_0053fd7d:
  GetRenderFrustum(this,(CHmsCamera *)param_3,unaff_ESI);
  if ((*(int *)(this + 0x1f8) != 0) && (*(int *)(this + 0x1fc) != 0)) {
    SHmsRenderRect::CutScissorRect(in_stack_00000014,(SHmsRenderRect *)(this + 0x1d4),unaff_EBP);
    local_4 = *(float *)(this + 0x11c);
    pCVar2 = *(CMwCmdScriptVarBool **)(this + 0x128);
    iVar12 = *(int *)(this + 300);
    GmScaleTrans2::SetRect_ConvTo_Rectm1p1(local_14,(GmScaleTrans2 *)&local_4,unaff_EBX);
    GmRectAligned::SetMult
              (&stack0x00000000,(SPlugFaceCull *)(this + 0x1d4),aSStack_10,in_stack_ffffffd8);
    unaff_ESI = param_3;
    GmFrustum::Set(param_3,pCVar2,iVar12);
  }
  if (*(int *)(this + 0x174) != 0) {
    if (*(int *)(this + 0x118) == 0) {
      fVar13 = *(float *)(this + 0x130);
    }
    else {
      fVar13 = *(float *)(this + 0x130) + *(float *)(this + 0x124);
    }
    pCVar4 = (CHmsCamera *)(fVar13 * (float)_DAT_00b44a20);
    if ((float)*(CHmsCamera **)(this + 0x178) <= (float)pCVar4) {
      pCVar4 = *(CHmsCamera **)(this + 0x178);
    }
    *(CHmsCamera **)(this + 0x178) = pCVar4;
    GmFrustum::SetFarZ(param_3,pCVar4,(float)unaff_ESI);
    if (*(int *)(DAT_00d54380 + 0x20) == 0) {
      iVar12 = *(int *)(DAT_00d54380 + 0x24);
    }
    else {
      iVar12 = *(int *)(DAT_00d54380 + 0x28);
    }
    if (*(int *)(iVar12 + 0xac) == 0) {
      *(undefined4 *)((int)in_stack_00000014 + 4) = *(undefined4 *)(this + 0x204);
    }
  }
  if (*(int *)(this + 0x180) != 0) {
    iVar12 = *(int *)(this + 0x210);
    iVar3 = *(int *)(this + 0x18c);
    fVar13 = (float)*(int *)(this + 0x184);
    if (*(int *)(this + 0x184) < 0) {
      fVar13 = fVar13 + _DAT_00c418d0;
    }
    fVar1 = (float)(iVar3 + -1);
    if (iVar3 + -1 < 0) {
      fVar1 = fVar1 + _DAT_00c418d0;
    }
    fVar5 = (float)_DAT_00b313b8;
    fVar7 = (float)*(int *)(iVar12 + 0x2a4);
    if (*(int *)(iVar12 + 0x2a4) < 0) {
      fVar7 = fVar7 + _DAT_00c418d0;
    }
    fVar10 = (float)iVar3;
    if (iVar3 < 0) {
      fVar10 = fVar10 + _DAT_00c418d0;
    }
    iVar3 = *(int *)(this + 400);
    fVar8 = (float)*(int *)(this + 0x188);
    if (*(int *)(this + 0x188) < 0) {
      fVar8 = fVar8 + _DAT_00c418d0;
    }
    fVar9 = (float)(iVar3 + -1);
    if (iVar3 + -1 < 0) {
      fVar9 = fVar9 + _DAT_00c418d0;
    }
    fVar6 = (float)*(int *)(iVar12 + 0x2a8);
    if (*(int *)(iVar12 + 0x2a8) < 0) {
      fVar6 = fVar6 + _DAT_00c418d0;
    }
    fVar11 = (float)iVar3;
    if (iVar3 < 0) {
      fVar11 = fVar11 + _DAT_00c418d0;
    }
    local_4 = ((fVar13 - fVar1 * fVar5) /
              (fVar10 * fVar7 * (*(float *)(this + 0x1cc) - *(float *)(this + 0x1c4)) * fVar5)) *
              (*(float *)(param_3 + 0x10) - *(float *)(param_3 + 4));
    local_c = (CMwCmdScriptVarBool *)(local_4 + *(float *)(param_3 + 4));
    local_8 = ((fVar8 - fVar9 * fVar5) /
              (fVar11 * fVar6 * (*(float *)(this + 0x1d0) - *(float *)(this + 0x1c8)) * fVar5)) *
              (*(float *)(param_3 + 0x14) - *(float *)(param_3 + 8)) + *(float *)(param_3 + 8);
    local_4 = *(float *)(param_3 + 0x10) + local_4;
    GmFrustum::Set(param_3,local_c,(int)local_8);
  }
  return;
}
}

// =================================================
// Function: CHmsCamera::~CHmsCamera
// =================================================
void __thiscall CHmsCamera::~CHmsCamera(CHmsCamera *this,CHmsCamera *param_1)
{
{
  CFastBuffer<class_CPlugFileGPUV*> *pCVar1;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_EDI;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar2;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00a959c4;
  local_c = ExceptionList;
  pCVar1 = (CFastBuffer<class_CPlugFileGPUV*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = (void *)0x2;
  (**(code **)(**(int **)(this + 0x20c) + 0x80))();
  if (*(int **)(this + 0x1a0) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x1a0) + 4))(1);
  }
  pCVar2 = *(CFastBuffer<class_CPlugFileGPUV*> **)(this + 0x1bc);
  if (pCVar2 != (CFastBuffer<class_CPlugFileGPUV*> *)0x0) {
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(pCVar2 + 0x18,pCVar1);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(pCVar2 + 4,unaff_EDI);
    pCVar1 = (CFastBuffer<class_CPlugFileGPUV*> *)0x54022a;
    operator_delete(pCVar2);
    unaff_EDI = pCVar2;
  }
  local_4 = (void *)CONCAT31(local_4._1_3_,1);
  if (*(CMwNod **)(this + 0x20c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x20c),(CMwNod *)pCVar1);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x1a4,pCVar1);
  CHmsPoc::~CHmsPoc((CHmsPoc *)this,(CHmsPoc *)unaff_EDI);
  ExceptionList = local_4;
  return;
}
}

