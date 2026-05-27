// Class implementation: CHmsDyna

// =================================================
// Function: CHmsDyna::AddForce
// =================================================
void __thiscall CHmsDyna::AddForce(void *this,CHmsItem *param_1,GmVec3 *param_2,GmVec3 *param_3)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  *(float *)(iVar1 + 100) = *(float *)(iVar1 + 100) + *(float *)param_1;
  *(float *)(iVar1 + 0x68) = *(float *)(param_1 + 4) + *(float *)(iVar1 + 0x68);
  *(float *)(iVar1 + 0x6c) = *(float *)(param_1 + 8) + *(float *)(iVar1 + 0x6c);
  return;
}
}

// =================================================
// Function: CHmsDyna::AddHistoryPoint
// =================================================
SHistoryPoint * __thiscall
CHmsDyna::AddHistoryPoint
          (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmMat3 *param_3,ulong param_4)
{
{
  ulong uVar1;
  uint uVar2;
  SBlockState *pSVar3;
  int iVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  undefined4 *puVar5;
  CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> *unaff_EDI;
  SBlockState *pSVar6;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0x344),unaff_ESI);
  if (uVar1 != 0) {
    uVar2 = *(uint *)((int)this + 0x350);
    if (*(uint *)((int)this + 0x34c) <= uVar2) {
      uVar2 = uVar2 - *(uint *)((int)this + 0x34c);
    }
    if (param_4 <= *(uint *)(uVar2 * 0xe0 + 0xa8 + *(int *)((int)this + 0x348))) {
      return (SHistoryPoint *)0x0;
    }
  }
  pSVar3 = CFastBufferWheel<struct_CHmsDyna::SHistoryPoint>::PushNewElem
                     ((void *)((int)this + 0x344),unaff_EDI);
  *(undefined4 *)pSVar3 = *(undefined4 *)param_3;
  *(undefined4 *)(pSVar3 + 4) = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)(pSVar3 + 8) = *(undefined4 *)(param_3 + 8);
  puVar5 = (undefined4 *)param_4;
  pSVar6 = pSVar3 + 0x24;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pSVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    pSVar6 = pSVar6 + 4;
  }
  *(undefined4 *)(pSVar3 + 0x14) = 0;
  *(undefined4 *)(pSVar3 + 0x10) = 0;
  *(undefined4 *)(pSVar3 + 0xc) = 0;
  *(undefined4 *)(pSVar3 + 0x50) = 0;
  *(undefined4 *)(pSVar3 + 0x4c) = 0;
  *(undefined4 *)(pSVar3 + 0x48) = 0;
  *(undefined4 *)(pSVar3 + 0x5c) = 0;
  *(undefined4 *)(pSVar3 + 0x58) = 0;
  *(undefined4 *)(pSVar3 + 0x54) = 0;
  *(undefined4 *)(pSVar3 + 0x68) = 0;
  *(undefined4 *)(pSVar3 + 100) = 0;
  *(undefined4 *)(pSVar3 + 0x60) = 0;
  *(ulong *)(pSVar3 + 0xa8) = param_4;
  *(undefined4 *)(pSVar3 + 0xac) = 0;
  return (SHistoryPoint *)pSVar3;
}
}

// =================================================
// Function: CHmsDyna::AddImpulse
// =================================================
void __thiscall CHmsDyna::AddImpulse(void *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  
  if (*(int *)((int)this + 0x340) != 2) {
    if (*(int *)((int)this + 0x33c) == 0) {
      *(undefined4 *)((int)this + 0x33c) = 1;
    }
    fVar4 = 1.0 / **(float **)((int)this + 0x108);
    fVar1 = *(float *)(param_1 + 4);
    fVar2 = *(float *)(param_1 + 8);
    iVar3 = *(int *)((int)this + 0x32c);
    *(float *)(iVar3 + 0x40) = fVar4 * *(float *)param_1 + *(float *)(iVar3 + 0x40);
    *(float *)(iVar3 + 0x44) = *(float *)(iVar3 + 0x44) + fVar1 * fVar4;
    *(float *)(iVar3 + 0x48) = fVar4 * fVar2 + *(float *)(iVar3 + 0x48);
  }
  return;
}
}

// =================================================
// Function: CHmsDyna::AddLocalForce
// =================================================
void __thiscall CHmsDyna::AddLocalForce(void *this,CHmsDyna *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  AddForce(this,(CHmsItem *)&stack0xfffffff4,
           (GmVec3 *)
           (*(float *)(iVar1 + 0x18) * *(float *)(param_1 + 8) +
           *(float *)(iVar1 + 0x10) * *(float *)param_1 +
           *(float *)(iVar1 + 0x14) * *(float *)(param_1 + 4)),
           (GmVec3 *)
           (*(float *)(iVar1 + 0x24) * *(float *)(param_1 + 8) +
           *(float *)(iVar1 + 0x20) * *(float *)(param_1 + 4) +
           *(float *)(iVar1 + 0x1c) * *(float *)param_1));
  return;
}
}

// =================================================
// Function: CHmsDyna::AddLocalImpulse
// =================================================
void __thiscall CHmsDyna::AddLocalImpulse(void *this,CHmsDyna *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  AddImpulse(this,(CHmsItem *)&stack0xfffffff4,
             (GmVec3 *)
             (*(float *)(iVar1 + 0x18) * *(float *)(param_1 + 8) +
             *(float *)(iVar1 + 0x10) * *(float *)param_1 +
             *(float *)(iVar1 + 0x14) * *(float *)(param_1 + 4)));
  return;
}
}

// =================================================
// Function: CHmsDyna::AddLocalTorque
// =================================================
void __thiscall CHmsDyna::AddLocalTorque(void *this,CHmsDyna *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  AddTorque(this,(CHmsItem *)&stack0xfffffff4,
            (GmVec3 *)
            (*(float *)(iVar1 + 0x18) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x10) * *(float *)param_1 +
            *(float *)(iVar1 + 0x14) * *(float *)(param_1 + 4)));
  return;
}
}

// =================================================
// Function: CHmsDyna::AddReplacement
// =================================================
void __thiscall CHmsDyna::AddReplacement(void *this,CHmsDyna *param_1,GmVec3 *param_2)
{
{
  if (*(int *)((int)this + 0x33c) == 0) {
    *(undefined4 *)((int)this + 0x33c) = 1;
  }
  CFastBuffer<struct_CInputEventsStore::SCachedValue>::Add
            ((void *)((int)this + 0x330),(TiXmlAttributeSet *)param_1,(TiXmlAttribute *)param_2);
  return;
}
}

// =================================================
// Function: CHmsDyna::AddStateForPrediction
// =================================================
void __thiscall
CHmsDyna::AddStateForPrediction
          (void *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,ulong param_3,
          ulong param_4)
{
{
  uchar unaff_SI;
  CHmsStateDyna *in_stack_ffffff4c;
  undefined1 local_b0 [176];
  
  CHmsStateDyna::RestoreState
            (&stack0xffffff4c,(CHmsStateDyna *)param_1,(CClassicBufferMemory *)param_3,unaff_SI);
  DoPHBInterpolation(this,(CHmsDyna *)param_3,(ulong)local_b0,in_stack_ffffff4c);
  return;
}
}

// =================================================
// Function: CHmsDyna::AddTorque
// =================================================
void __thiscall CHmsDyna::AddTorque(void *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  *(float *)(iVar1 + 0x70) = *(float *)(iVar1 + 0x70) + *(float *)param_1;
  *(float *)(iVar1 + 0x74) = *(float *)(param_1 + 4) + *(float *)(iVar1 + 0x74);
  *(float *)(iVar1 + 0x78) = *(float *)(param_1 + 8) + *(float *)(iVar1 + 0x78);
  return;
}
}

// =================================================
// Function: CHmsDyna::ApplyReplacement
// =================================================
void __thiscall CHmsDyna::ApplyReplacement(void *this,CHmsDyna *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  *(float *)(iVar1 + 0x34) = *(float *)(iVar1 + 0x34) + *(float *)param_1;
  *(float *)(iVar1 + 0x38) = *(float *)(param_1 + 4) + *(float *)(iVar1 + 0x38);
  *(float *)(iVar1 + 0x3c) = *(float *)(param_1 + 8) + *(float *)(iVar1 + 0x3c);
  return;
}
}

// =================================================
// Function: CHmsDyna::CHmsDyna
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsDyna::CHmsDyna(void *this,CHmsDyna *param_1)
{
{
  GmFrustumIso4 *unaff_EBX;
  CFastBufferWheel<float> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *unaff_retaddr;
  
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x330),unaff_EDI);
  CFastBufferWheel<float>::CFastBufferWheel<float>((void *)((int)this + 0x344),unaff_ESI);
  *(undefined4 *)((int)this + 0xc4) = _DAT_00b3d270;
  *(void **)((int)this + 0x1bc) = this;
  *(void **)((int)this + 0x270) = this;
  *(undefined4 *)((int)this + 0x33c) = 1;
  *(undefined4 *)((int)this + 0x340) = 0;
  *(undefined4 *)((int)this + 0x108) = 0;
  *(undefined4 *)((int)this + 0xc0) = 0;
  Reset(this,unaff_EBX);
  CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::ClearWheel
            ((void *)((int)this + 0x344),unaff_retaddr);
  *(undefined4 *)((int)this + 0x360) = 0;
  *(undefined4 *)((int)this + 0x35c) = 0;
  *(undefined4 *)((int)this + 0x358) = 0;
  *(undefined4 *)((int)this + 0x36c) = 0;
  *(undefined4 *)((int)this + 0x368) = 0;
  *(undefined4 *)((int)this + 0x364) = 0;
  *(undefined4 *)((int)this + 900) = 0;
  *(undefined4 *)((int)this + 0x380) = 0;
  *(undefined4 *)((int)this + 0x37c) = 0;
  *(undefined4 *)((int)this + 0x390) = 0;
  *(undefined4 *)((int)this + 0x38c) = 0;
  *(undefined4 *)((int)this + 0x388) = 0;
  *(undefined4 *)((int)this + 0x39c) = 0;
  *(undefined4 *)((int)this + 0x398) = 0;
  *(undefined4 *)((int)this + 0x394) = 0;
  *(undefined4 *)((int)this + 0x3a8) = 0;
  *(undefined4 *)((int)this + 0x3a4) = 0;
  *(undefined4 *)((int)this + 0x3a0) = 0;
  *(undefined4 *)((int)this + 0x3b4) = 0;
  *(undefined4 *)((int)this + 0x3b0) = 0;
  *(undefined4 *)((int)this + 0x3ac) = 0;
  *(undefined4 *)((int)this + 0x3c0) = 0;
  *(undefined4 *)((int)this + 0x3bc) = 0;
  *(undefined4 *)((int)this + 0x3b8) = 0;
  *(undefined4 *)((int)this + 0x400) = 0;
  *(undefined4 *)((int)this + 0x440) = 0;
  *(undefined4 *)((int)this + 0x43c) = 0;
  *(undefined4 *)((int)this + 0x438) = 0;
  *(undefined4 *)((int)this + 0x44c) = 0;
  *(undefined4 *)((int)this + 0x448) = 0;
  *(undefined4 *)((int)this + 0x444) = 0;
  *(undefined4 *)((int)this + 0x464) = 0;
  *(undefined4 *)((int)this + 0x460) = 0;
  *(undefined4 *)((int)this + 0x45c) = 0;
  *(undefined4 *)((int)this + 0x470) = 0;
  *(undefined4 *)((int)this + 0x46c) = 0;
  *(undefined4 *)((int)this + 0x468) = 0;
  *(undefined4 *)((int)this + 0x47c) = 0;
  *(undefined4 *)((int)this + 0x478) = 0;
  *(undefined4 *)((int)this + 0x474) = 0;
  *(undefined4 *)((int)this + 0x488) = 0;
  *(undefined4 *)((int)this + 0x484) = 0;
  *(undefined4 *)((int)this + 0x480) = 0;
  *(undefined4 *)((int)this + 0x494) = 0;
  *(undefined4 *)((int)this + 0x490) = 0;
  *(undefined4 *)((int)this + 0x48c) = 0;
  *(undefined4 *)((int)this + 0x4a0) = 0;
  *(undefined4 *)((int)this + 0x49c) = 0;
  *(undefined4 *)((int)this + 0x498) = 0;
  *(undefined4 *)((int)this + 0x104) = 0;
  *(undefined4 *)((int)this + 0x4e0) = 0;
  *(undefined4 *)((int)this + 0x518) = 0;
  *(undefined4 *)((int)this + 0x51c) = 0;
  *(undefined4 *)((int)this + 0x520) = 0;
  *(undefined4 *)((int)this + 0x524) = 0;
  *(undefined4 *)((int)this + 0x528) = 0;
  *(undefined4 *)((int)this + 0x58c) = 0;
  return;
}
}

// =================================================
// Function: CHmsDyna::ChooseInterpolationMethods
// =================================================
void __thiscall
CHmsDyna::ChooseInterpolationMethods
          (void *this,CHmsDyna *param_1,GmVec3 *param_2,SPredictionTypeVector *param_3,
          SPredictionTypeVector *param_4)
{
{
  SPredictionTypeVector *unaff_EBP;
  SPredictionTypeVector *unaff_ESI;
  SPredictionTypeVector *unaff_EDI;
  
  ChooseInterpolationMethods(this,*(CHmsDyna **)param_1,param_2,param_3,unaff_EDI);
  ChooseInterpolationMethods(this,*(CHmsDyna **)(param_1 + 4),param_2 + 4,param_3 + 4,unaff_ESI);
  ChooseInterpolationMethods(this,*(CHmsDyna **)(param_1 + 8),param_2 + 8,param_3 + 8,unaff_EBP);
  return;
}
}

// =================================================
// Function: CHmsDyna::ComputeEmbraceAngle
// =================================================
void __thiscall
CHmsDyna::ComputeEmbraceAngle
          (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4,
          float param_5,float param_6,float param_7,GmVec3 *param_8)
{
{
  float fVar1;
  CHmsDyna *pCVar2;
  float unaff_EBP;
  float unaff_ESI;
  float unaff_EDI;
  float fVar3;
  float fVar4;
  int in_stack_00000024;
  int in_stack_00000028;
  
  pCVar2 = (CHmsDyna *)(*(float *)param_1 - *(float *)param_2);
  fVar3 = ComputeEmbraceAngleForValue
                    (this,pCVar2,*(float *)param_3 - *(float *)param_2,(float)param_4 - param_5,
                     param_6 - param_5,unaff_EDI);
  *(float *)param_8 = fVar3;
  fVar3 = *(float *)(param_1 + 4);
  fVar1 = *(float *)(param_2 + 4);
  fVar4 = ComputeEmbraceAngleForValue
                    (this,(CHmsDyna *)(fVar3 - fVar1),
                     *(float *)(param_3 + 4) - *(float *)(param_2 + 4),(float)pCVar2,
                     (float)param_4 - param_5,unaff_ESI);
  *(float *)(in_stack_00000024 + 4) = fVar4;
  fVar3 = ComputeEmbraceAngleForValue
                    (this,(CHmsDyna *)(*(float *)(param_1 + 8) - *(float *)(param_2 + 8)),
                     *(float *)(param_3 + 8) - *(float *)(param_2 + 8),fVar3 - fVar1,(float)pCVar2,
                     unaff_EBP);
  *(float *)(in_stack_00000028 + 8) = fVar3;
  return;
}
}

// =================================================
// Function: CHmsDyna::ComputeEmbraceAngleForValue
// =================================================
float __thiscall
CHmsDyna::ComputeEmbraceAngleForValue
          (void *this,CHmsDyna *param_1,float param_2,float param_3,float param_4,float param_5)
{
{
  float10 extraout_ST0;
  
  func_0x009c1b40();
  __CIacos();
  return (float)extraout_ST0;
}
}

// =================================================
// Function: CHmsDyna::ComputeInterpolationConvergencePoint
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsDyna::ComputeInterpolationConvergencePoint(void *this,CHmsDyna *param_1)
{
{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  GmVec3 *pGVar6;
  ulong uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  CHmsDyna *pCVar11;
  int extraout_EDX;
  GmMat3 *unaff_EBX;
  GmVec3 *unaff_EBP;
  GmMat3 *unaff_ESI;
  undefined4 *puVar12;
  CHmsDyna *pCVar13;
  float unaff_EDI;
  undefined4 *puVar14;
  int unaff_retaddr;
  GmVec3 *in_stack_fffffff8;
  SParam *local_4;
  
  uVar10 = *(uint *)((int)this + 0x350);
  if (*(uint *)((int)this + 0x34c) <= uVar10) {
    uVar10 = uVar10 - *(uint *)((int)this + 0x34c);
  }
  pCVar11 = (CHmsDyna *)(uVar10 * 0xe0 + *(int *)((int)this + 0x348));
  *(undefined4 *)((int)this + 0x358) = *(undefined4 *)((int)this + 0x52c);
  uVar1 = *(undefined4 *)((int)this + 0x534);
  *(undefined4 *)((int)this + 0x35c) = *(undefined4 *)((int)this + 0x530);
  puVar12 = (undefined4 *)((int)this + 0x538);
  puVar14 = (undefined4 *)((int)this + 0x37c);
  for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar14 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar14 = puVar14 + 1;
  }
  *(undefined4 *)((int)this + 0x364) = *(undefined4 *)((int)this + 0x55c);
  *(undefined4 *)((int)this + 0x360) = uVar1;
  *(undefined4 *)((int)this + 0x368) = *(undefined4 *)((int)this + 0x560);
  uVar10 = *(uint *)((int)this + 0x58c);
  *(undefined4 *)((int)this + 0x36c) = *(undefined4 *)((int)this + 0x564);
  puVar12 = (undefined4 *)((int)this + 0x568);
  puVar14 = (undefined4 *)((int)this + 0x3a0);
  for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar14 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar14 = puVar14 + 1;
  }
  *(uint *)((int)this + 0x400) = uVar10;
  if ((uVar10 < *(uint *)((int)this + 0x51c)) ||
     (uVar9 = uVar10 - *(uint *)((int)this + 0x51c), 99 < uVar9)) {
    uVar9 = 100;
  }
  if (uVar10 + uVar9 <= *(uint *)(pCVar11 + 0xa8)) {
    if (uVar9 == 0) {
      *(undefined4 *)((int)this + 0x528) = 0;
      return;
    }
    *(undefined4 *)((int)this + 0x520) = 0;
    *(undefined4 *)((int)this + 0x51c) = 0;
    *(undefined4 *)((int)this + 0x4e0) = *(undefined4 *)(pCVar11 + 0xa8);
    *(undefined4 *)((int)this + 0x438) = *(undefined4 *)pCVar11;
    *(undefined4 *)((int)this + 0x43c) = *(undefined4 *)(pCVar11 + 4);
    *(undefined4 *)((int)this + 0x440) = *(undefined4 *)(pCVar11 + 8);
    pCVar13 = pCVar11 + 0x24;
    puVar12 = (undefined4 *)((int)this + 0x45c);
    for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar12 = *(undefined4 *)pCVar13;
      pCVar13 = pCVar13 + 4;
      puVar12 = puVar12 + 1;
    }
    *(undefined4 *)((int)this + 0x444) = *(undefined4 *)(pCVar11 + 0xc);
    *(undefined4 *)((int)this + 0x448) = *(undefined4 *)(pCVar11 + 0x10);
    *(undefined4 *)((int)this + 0x44c) = *(undefined4 *)(pCVar11 + 0x14);
    pCVar11 = pCVar11 + 0x48;
    puVar12 = (undefined4 *)((int)this + 0x480);
    for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar12 = *(undefined4 *)pCVar11;
      pCVar11 = pCVar11 + 4;
      puVar12 = puVar12 + 1;
    }
    return;
  }
  if (uVar9 < 0x33) {
    uVar9 = 0x32;
  }
  *(uint *)((int)this + 0x4e0) = uVar10 + uVar9;
  pGVar6 = (GmVec3 *)((uVar10 + uVar9) - *(int *)(pCVar11 + 0xa8));
  ComputeNextPosition(this,pCVar11,(GmVec3 *)(pCVar11 + 0xc),(GmVec3 *)(pCVar11 + 0x18),pGVar6,
                      (int)this + 0x438,unaff_EBP);
  fVar2 = (float)(int)pGVar6;
  if ((int)pGVar6 < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  fVar3 = (float)_DAT_00b30a18;
  fVar5 = (float)*(int *)(extraout_EDX + 0xa8);
  if (*(int *)(extraout_EDX + 0xa8) < 0) {
    fVar5 = fVar5 + _DAT_00c418d0;
  }
  fVar4 = (float)*(int *)(unaff_retaddr + 0xa8);
  if (*(int *)(unaff_retaddr + 0xa8) < 0) {
    fVar4 = fVar4 + _DAT_00c418d0;
  }
  local_4 = (SParam *)((fVar2 * fVar3) / (fVar5 * fVar3 - fVar4 * fVar3) + (float)_DAT_00b2c188);
  if ((float)_DAT_00b313ac < (float)local_4) {
    local_4 = _DAT_00b313ac;
  }
  GmMat3::SetBlend((void *)((int)this + 0x45c),(SParam *)(unaff_retaddr + 0x24),
                   (SParam *)(extraout_EDX + 0x24),local_4,unaff_EDI);
  uVar7 = GmMat3::IsOrthonormal((void *)((int)this + 0x45c),unaff_ESI);
  if (uVar7 == 0) {
    GmMat3::OrthoNormalize((void *)((int)this + 0x45c),unaff_EBX);
  }
  ComputeNextSpeed(this,pCVar11 + 0xc,(GmVec3 *)(pCVar11 + 0x18),pGVar6,(int)this + 0x444,
                   in_stack_fffffff8);
  return;
}
}

// =================================================
// Function: CHmsDyna::ComputeInterpolationMethods
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsDyna::ComputeInterpolationMethods(void *this,CHmsDyna *param_1)
{
{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  CHmsDyna *pCVar7;
  GmVec3 *pGVar8;
  int unaff_EBX;
  ulong unaff_EBP;
  SPredictionTypeVector *unaff_ESI;
  GmVec3 *unaff_EDI;
  uint uVar9;
  GmVec3 *pGVar10;
  GmVec3 *pGVar11;
  int in_stack_ffffffc4;
  CHmsDyna local_38 [20];
  undefined1 local_24 [20];
  undefined1 local_10 [16];
  
  uVar1 = *(uint *)((int)this + 0x34c);
  uVar6 = *(int *)((int)this + 0x350) + 2;
  if (uVar1 <= uVar6) {
    uVar6 = uVar6 - uVar1;
  }
  pCVar7 = (CHmsDyna *)(uVar6 * 0xe0 + *(int *)((int)this + 0x348));
  uVar6 = *(int *)((int)this + 0x350) + 1;
  if (uVar1 <= uVar6) {
    uVar6 = uVar6 - uVar1;
  }
  uVar9 = *(uint *)((int)this + 0x350);
  pGVar8 = (GmVec3 *)(uVar6 * 0xe0 + *(int *)((int)this + 0x348));
  if (uVar1 <= uVar9) {
    uVar9 = uVar9 - uVar1;
  }
  pGVar10 = (GmVec3 *)(uVar9 * 0xe0 + *(int *)((int)this + 0x348));
  fVar2 = (float)*(int *)(pGVar10 + 0xa8);
  if (*(int *)(pGVar10 + 0xa8) < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  fVar3 = (float)_DAT_00b30a18;
  fVar5 = (float)*(int *)(pGVar8 + 0xa8);
  if (*(int *)(pGVar8 + 0xa8) < 0) {
    fVar5 = fVar5 + _DAT_00c418d0;
  }
  fVar4 = (float)*(int *)(pCVar7 + 0xa8);
  if (*(int *)(pCVar7 + 0xa8) < 0) {
    fVar4 = fVar4 + _DAT_00c418d0;
  }
  pGVar11 = (GmVec3 *)(fVar4 * fVar3);
  ComputeEmbraceAngle(this,pCVar7,pGVar8,pGVar10,pGVar11,fVar5 * fVar3,fVar2 * fVar3,
                      (float)&stack0xffffffc4,unaff_EDI);
  ChooseInterpolationMethods
            (this,local_38,pGVar10 + 0xb0,(SPredictionTypeVector *)((int)this + 0x4e8),unaff_ESI);
  ComputeInterpolationParameters
            (this,(CHmsDyna *)(pGVar10 + 0xc),pGVar10 + 0x18,pGVar10 + 0xb0,
             (SPredictionTypeVector *)pCVar7,pGVar8,pGVar10,*(GmVec3 **)(pCVar7 + 0xa8),
             *(ulong *)(pGVar8 + 0xa8),*(ulong *)(pGVar10 + 0xa8),unaff_EBP);
  GmQuat::Set(local_24,(CMwCmdScriptVarBool *)(pCVar7 + 0x24),unaff_EBX);
  GmQuat::Set(local_10,(CMwCmdScriptVarBool *)(pGVar8 + 0x24),(int)pGVar11);
  GmQuat::Set(&param_1,(CMwCmdScriptVarBool *)(pGVar10 + 0x24),in_stack_ffffffc4);
  return;
}
}

// =================================================
// Function: CHmsDyna::ComputeInterpolationParameters
// =================================================
void __thiscall
CHmsDyna::ComputeInterpolationParameters
          (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3,
          SPredictionTypeVector *param_4,GmVec3 *param_5,GmVec3 *param_6,GmVec3 *param_7,
          ulong param_8,ulong param_9,ulong param_10)
{
{
  ulong unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  
  ComputeInterpolationParameters
            (this,param_1,param_2,*(GmVec3 **)param_3,*(SPredictionTypeVector **)param_4,
             *(GmVec3 **)param_5,*(GmVec3 **)param_6,param_7,param_8,param_9,unaff_EDI);
  ComputeInterpolationParameters
            (this,(CHmsDyna *)(param_2 + 4),param_3 + 4,*(GmVec3 **)(param_4 + 4),
             *(SPredictionTypeVector **)(param_5 + 4),*(GmVec3 **)(param_6 + 4),
             *(GmVec3 **)(param_7 + 4),param_7,param_8,param_9,unaff_ESI);
  ComputeInterpolationParameters
            (this,(CHmsDyna *)(param_3 + 8),(GmVec3 *)(param_4 + 8),*(GmVec3 **)(param_5 + 8),
             *(SPredictionTypeVector **)(param_6 + 8),*(GmVec3 **)(param_7 + 8),
             *(GmVec3 **)(param_8 + 8),param_7,param_8,param_9,unaff_EBP);
  return;
}
}

// =================================================
// Function: CHmsDyna::ComputeNextPosition
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsDyna::ComputeNextPosition
          (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4,
          ulong param_5,GmVec3 *param_6)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar6 = (float)(int)param_4;
  if ((int)param_4 < 0) {
    fVar6 = fVar6 + _DAT_00c418d0;
  }
  fVar6 = fVar6 * (float)_DAT_00b30a18;
  fVar1 = *(float *)(param_2 + 4);
  fVar2 = *(float *)(param_2 + 8);
  fVar7 = (float)_DAT_00b313b8 * fVar6 * fVar6;
  fVar3 = *(float *)param_3;
  fVar4 = *(float *)(param_3 + 4);
  fVar5 = *(float *)(param_3 + 8);
  *(float *)param_5 = *(float *)param_1 + fVar6 * *(float *)param_2;
  *(float *)(param_5 + 4) = *(float *)(param_1 + 4) + fVar1 * fVar6;
  *(float *)(param_5 + 8) = *(float *)(param_1 + 8) + fVar2 * fVar6;
  *(float *)param_5 = *(float *)param_5 + fVar7 * fVar3;
  *(float *)(param_5 + 4) = *(float *)(param_5 + 4) + fVar4 * fVar7;
  *(float *)(param_5 + 8) = *(float *)(param_5 + 8) + fVar7 * fVar5;
  return;
}
}

// =================================================
// Function: CHmsDyna::ComputeNextSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsDyna::ComputeNextSpeed
          (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3,ulong param_4,
          GmVec3 *param_5)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = (float)(int)param_3;
  if ((int)param_3 < 0) {
    fVar3 = fVar3 + _DAT_00c418d0;
  }
  fVar3 = fVar3 * (float)_DAT_00b30a18;
  fVar1 = *(float *)(param_2 + 4);
  fVar2 = *(float *)(param_2 + 8);
  *(float *)param_4 = *(float *)param_1 + fVar3 * *(float *)param_2;
  *(float *)(param_4 + 4) = *(float *)(param_1 + 4) + fVar1 * fVar3;
  *(float *)(param_4 + 8) = *(float *)(param_1 + 8) + fVar3 * fVar2;
  return;
}
}

// =================================================
// Function: CHmsDyna::ComputeSpeed
// =================================================
void __thiscall
CHmsDyna::ComputeSpeed
          (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4,
          ulong param_5,ulong param_6)
{
{
  ulong unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  
  ComputeSpeed(this,param_1,*(GmVec3 **)param_2,*(GmVec3 **)param_3,param_4,param_5,unaff_EDI);
  ComputeSpeed(this,(CHmsDyna *)(param_2 + 4),*(GmVec3 **)(param_3 + 4),*(GmVec3 **)(param_3 + 4),
               param_4,param_5,unaff_ESI);
  ComputeSpeed(this,(CHmsDyna *)(param_3 + 8),*(GmVec3 **)(param_4 + 8),*(GmVec3 **)(param_3 + 8),
               param_4,param_5,unaff_EBP);
  return;
}
}

// =================================================
// Function: CHmsDyna::ComputeSpeedAndAccelerationAtTime2
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsDyna::ComputeSpeedAndAccelerationAtTime2
          (void *this,CHmsDyna *param_1,float *param_2,float *param_3,float param_4,float param_5,
          float param_6,ulong param_7,ulong param_8,ulong param_9)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = (float)(int)param_7;
  if ((int)param_7 < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  fVar3 = (float)_DAT_00b30a18;
  fVar2 = (float)(int)param_6;
  if ((int)param_6 < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  fVar2 = fVar1 * fVar3 - fVar2 * fVar3;
  fVar4 = (float)(int)param_8;
  if ((int)param_8 < 0) {
    fVar4 = fVar4 + _DAT_00c418d0;
  }
  fVar1 = fVar4 * fVar3 - fVar1 * fVar3;
  if ((_DAT_00b55d34 <= fVar2) && (_DAT_00b55d34 <= fVar1)) {
    fVar4 = 1.0 / fVar2;
    fVar3 = 1.0 / fVar1;
    fVar2 = 1.0 / (fVar1 + fVar2);
    *(float *)param_1 =
         (fVar2 + fVar3) * param_5 +
         (fVar4 * fVar2 * (float)param_3 * fVar1 - param_4 * (fVar3 + fVar4));
    fVar1 = (float)_DAT_00b33a58;
    *param_2 = fVar2 * param_5 * fVar1 * fVar3 +
               (fVar4 * fVar2 * (float)param_3 * fVar1 - fVar3 * param_4 * fVar1 * fVar4);
    return;
  }
  *(undefined4 *)param_1 = 0;
  *param_2 = 0.0;
  return;
}
}

// =================================================
// Function: CHmsDyna::ComputeSynthetizedReplacement
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsDyna::ComputeSynthetizedReplacement(void *this,CHmsDyna *param_1,GmVec3 *param_2)
{
{
  void *this_00;
  float fVar1;
  float fVar2;
  float fVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  ulong unaff_EBX;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float10 fVar7;
  float *in_stack_0000000c;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  this_00 = (void *)((int)this + 0x330);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (pCVar4 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    *(undefined4 *)(param_2 + 8) = 0;
    *(undefined4 *)(param_2 + 4) = 0;
    *(undefined4 *)param_2 = 0;
    return;
  }
  pSVar5 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  local_10 = *(float *)pSVar5;
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
  local_c = *(float *)(pSVar5 + 4);
  local_8 = *(float *)(pSVar5 + 8);
  if ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1 < pCVar4) {
    do {
      pSVar5 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this_00,pCVar6,unaff_EBX);
      fVar1 = local_4 * *(float *)(pSVar5 + 8) +
              local_8 * *(float *)(pSVar5 + 4) + local_c * *(float *)pSVar5;
      local_10 = fVar1;
      if ((0.0 < fVar1) &&
         (local_10 = local_c * local_c + local_8 * local_8 + local_4 * local_4,
         _DAT_00cdb690 < local_10)) {
        if (local_10 < fVar1) {
          fVar1 = local_10;
        }
        local_10 = fVar1 / local_10;
        local_c = local_c - local_10 * local_c;
        local_8 = local_8 - local_10 * local_8;
        local_4 = local_4 - local_10 * local_4;
      }
      pCVar6 = pCVar6 + 1;
      local_c = *(float *)pSVar5 + local_c;
      local_8 = local_8 + *(float *)(pSVar5 + 4);
      local_4 = local_4 + *(float *)(pSVar5 + 8);
    } while (pCVar6 < pCVar4);
  }
  if (local_10 * local_10 + local_c * local_c + local_8 * local_8 <= _DAT_00cdb67c * _DAT_00cdb67c)
  {
    in_stack_0000000c[2] = 0.0;
    in_stack_0000000c[1] = 0.0;
    *in_stack_0000000c = 0.0;
    return;
  }
  fVar7 = (float10)func_0x009c1b40();
  fVar1 = 1.0 / (float)fVar7;
  fVar2 = _DAT_00cdb67c * local_c * fVar1;
  fVar3 = _DAT_00cdb67c * local_8 * fVar1;
  *in_stack_0000000c = local_10 - _DAT_00cdb67c * local_10 * fVar1;
  in_stack_0000000c[1] = local_c - fVar2;
  in_stack_0000000c[2] = local_8 - fVar3;
  return;
}
}

// =================================================
// Function: CHmsDyna::CopyStateToTemp
// =================================================
void __thiscall CHmsDyna::CopyStateToTemp(void *this,CHmsDyna *param_1)
{
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)((int)this + 0x32c);
  puVar3 = (undefined4 *)((int)this + 0x274);
  for (iVar1 = 0x2d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}
}

// =================================================
// Function: CHmsDyna::CopyTempToState
// =================================================
void __thiscall CHmsDyna::CopyTempToState(void *this,CHmsDyna *param_1)
{
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)((int)this + 0x274);
  puVar3 = *(undefined4 **)((int)this + 0x328);
  for (iVar1 = 0x2d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}
}

// =================================================
// Function: CHmsDyna::DoPHBInterpolation
// =================================================
void __thiscall
CHmsDyna::DoPHBInterpolation(void *this,CHmsDyna *param_1,ulong param_2,CHmsStateDyna *param_3)
{
{
  CPlugAudio *this_00;
  CMwId *pCVar1;
  SHistoryPoint *pSVar2;
  int iVar3;
  ulong uVar4;
  int iVar5;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  ulong unaff_ESI;
  CPlugAudio *unaff_EDI;
  CHmsDyna *pCVar6;
  CHmsDyna *unaff_retaddr;
  CHmsDyna *in_stack_00000010;
  ulong uStack00000014;
  uint in_stack_00000018;
  
  *(undefined4 *)((int)this + 4) = 1;
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar1 = CPlugAudio::MwGetId(this_00,unaff_EDI);
  pCVar6 = *(CHmsDyna **)pCVar1;
  UpdateHistory(this,pCVar6,unaff_ESI);
  if ((param_3 <= pCVar6 + DAT_00cdb688) &&
     (pSVar2 = AddHistoryPoint(this,in_stack_00000010 + 0x34,(GmVec3 *)(in_stack_00000010 + 0x10),
                               (GmMat3 *)param_3,unaff_EBX), pSVar2 != (SHistoryPoint *)0x0)) {
    uStack00000014 =
         CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0x344),unaff_EBP);
    iVar3 = TestIfRespawn(this,unaff_retaddr);
    *(int *)(pSVar2 + 0xac) = iVar3;
    if (DAT_00d67524 < pCVar6) {
      pCVar6 = pCVar6 + -(int)DAT_00d67524;
    }
    else {
      pCVar6 = (CHmsDyna *)0x0;
    }
    if ((iVar3 == 0) && (1 < in_stack_00000018)) {
      uVar4 = GetTimeLastHistoryPointMinusOne(this,param_1);
      if (((int)param_3 - uVar4 < 1000) && (pCVar6 < (CHmsDyna *)(param_3 + 1000))) {
        if ((in_stack_00000018 < 3) ||
           (pSVar2 = GetLastHistoryPointMinusOne(this,(CHmsDyna *)param_2),
           *(int *)(pSVar2 + 0xb0) == 2)) {
          SetAllInterpolationLinear(this,(CHmsDyna *)param_3);
        }
        else {
          ComputeInterpolationMethods(this,(CHmsDyna *)param_3);
        }
        iVar3 = *(int *)((int)this + 0x524);
        if (iVar3 == 0) {
          if (*(int *)((int)this + 0x518) != 0) {
            *(int *)((int)this + 0x518) = *(int *)((int)this + 0x518) + -1;
          }
        }
        else {
          iVar5 = IsTwoLastHistoryPointsDifferent(this,in_stack_00000010);
          if ((iVar5 != 0) &&
             (*(int *)((int)this + 0x518) = *(int *)((int)this + 0x518) + 1,
             0x32 < *(uint *)((int)this + 0x518))) {
            *(undefined4 *)((int)this + 0x518) = 0x32;
          }
        }
        if (*(int *)((int)this + 0x520) == 0) {
          return;
        }
        if (iVar3 != 0) {
          return;
        }
        *(undefined4 *)((int)this + 0x528) = 1;
        ComputeInterpolationConvergencePoint(this,in_stack_00000010);
        return;
      }
      iVar3 = IsTwoLastHistoryPointsDifferent(this,(CHmsDyna *)param_2);
      if ((iVar3 != 0) &&
         (*(int *)((int)this + 0x518) = *(int *)((int)this + 0x518) + 1,
         0x32 < *(uint *)((int)this + 0x518))) {
        *(undefined4 *)((int)this + 0x518) = 0x32;
      }
    }
    SetAllInterpolationConstant(this,(CHmsDyna *)param_3);
  }
  return;
}
}

// =================================================
// Function: CHmsDyna::DoPostCollisionDynamic
// =================================================
void __thiscall CHmsDyna::DoPostCollisionDynamic(void *this,CHmsDyna *param_1)
{
{
  GmVec3 *unaff_ESI;
  GmVec3 *in_stack_fffffff4;
  CHmsDyna local_8 [8];
  
  ComputeSynthetizedReplacement(this,(CHmsDyna *)&stack0xfffffff4,unaff_ESI);
  ApplyReplacement(this,local_8,in_stack_fffffff4);
  return;
}
}

// =================================================
// Function: CHmsDyna::DoPreCollisionDynamic
// =================================================
void __thiscall CHmsDyna::DoPreCollisionDynamic(void *this,CHmsDyna *param_1,float param_2)
{
{
  CHmsStateDyna *pCVar1;
  int iVar2;
  GmFrustumIso4 *unaff_ESI;
  CHmsStateDyna *pCVar3;
  float unaff_EDI;
  CHmsDyna *pCVar4;
  CHmsDyna local_c0 [188];
  
  pCVar1 = *(CHmsStateDyna **)((int)this + 0x32c);
  pCVar3 = pCVar1;
  pCVar4 = local_c0;
  for (iVar2 = 0x2d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pCVar4 = *(undefined4 *)pCVar3;
    pCVar3 = pCVar3 + 4;
    pCVar4 = pCVar4 + 4;
  }
  IntegrateStep(this,local_c0,pCVar1,(CHmsStateDyna *)param_1,unaff_EDI);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset((void *)((int)this + 0x330),unaff_ESI)
  ;
  return;
}
}

// =================================================
// Function: CHmsDyna::GetAngularSpeed
// =================================================
void __thiscall CHmsDyna::GetAngularSpeed(void *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  *(undefined4 *)param_1 = *(undefined4 *)(iVar1 + 0x58);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar1 + 0x5c);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0x60);
  return;
}
}

// =================================================
// Function: CHmsDyna::GetForce
// =================================================
void __thiscall CHmsDyna::GetForce(void *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  *(undefined4 *)param_1 = *(undefined4 *)(iVar1 + 100);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar1 + 0x68);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0x6c);
  return;
}
}

// =================================================
// Function: CHmsDyna::GetLastHistoryPointMinusOne
// =================================================
SHistoryPoint * __thiscall CHmsDyna::GetLastHistoryPointMinusOne(void *this,CHmsDyna *param_1)
{
{
  uint uVar1;
  
  uVar1 = *(int *)((int)this + 0x350) + 1;
  if (*(uint *)((int)this + 0x34c) <= uVar1) {
    uVar1 = uVar1 - *(uint *)((int)this + 0x34c);
  }
  return (SHistoryPoint *)(uVar1 * 0xe0 + *(int *)((int)this + 0x348));
}
}

// =================================================
// Function: CHmsDyna::GetLastHistoryPointMinusTwo
// =================================================
SHistoryPoint * __thiscall CHmsDyna::GetLastHistoryPointMinusTwo(void *this,CHmsDyna *param_1)
{
{
  uint uVar1;
  
  uVar1 = *(int *)((int)this + 0x350) + 2;
  if (*(uint *)((int)this + 0x34c) <= uVar1) {
    uVar1 = uVar1 - *(uint *)((int)this + 0x34c);
  }
  return (SHistoryPoint *)(uVar1 * 0xe0 + *(int *)((int)this + 0x348));
}
}

// =================================================
// Function: CHmsDyna::GetLinearSpeed
// =================================================
void __thiscall CHmsDyna::GetLinearSpeed(void *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  *(undefined4 *)param_1 = *(undefined4 *)(iVar1 + 0x40);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar1 + 0x44);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0x48);
  return;
}
}

// =================================================
// Function: CHmsDyna::GetLocalAngularSpeed
// =================================================
void __thiscall CHmsDyna::GetLocalAngularSpeed(void *this,CHmsDyna *param_1,GmVec3 *param_2)
{
{
  int extraout_EDX;
  GmVec3 *unaff_ESI;
  GmMat3 *unaff_retaddr;
  
  GetAngularSpeed(this,(CHmsItem *)param_1,unaff_ESI);
  GmVec3::MultTranspose(param_1,(GmMat3 *)(extraout_EDX + 0x10),unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsDyna::GetLocalForce
// =================================================
void __thiscall CHmsDyna::GetLocalForce(void *this,CHmsDyna *param_1,GmVec3 *param_2)
{
{
  int extraout_EDX;
  GmVec3 *unaff_ESI;
  GmMat3 *unaff_retaddr;
  
  GetForce(this,(CHmsItem *)param_1,unaff_ESI);
  GmVec3::MultTranspose(param_1,(GmMat3 *)(extraout_EDX + 0x10),unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsDyna::GetLocalLinearSpeed
// =================================================
void __thiscall CHmsDyna::GetLocalLinearSpeed(void *this,CHmsDyna *param_1,GmVec3 *param_2)
{
{
  int extraout_EDX;
  GmVec3 *unaff_ESI;
  GmMat3 *unaff_retaddr;
  
  GetLinearSpeed(this,(CHmsItem *)param_1,unaff_ESI);
  GmVec3::MultTranspose(param_1,(GmMat3 *)(extraout_EDX + 0x10),unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsDyna::GetSpeed
// =================================================
void __thiscall CHmsDyna::GetSpeed(void *this,CScenePoc *param_1,GmVec3 *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  GmIso4 *unaff_EDI;
  float unaff_retaddr;
  undefined1 local_c [4];
  float local_8;
  float local_4;
  
  iVar7 = *(int *)((int)this + 0x32c);
  if (*(int *)((int)this + 0x340) == 2) {
    *(undefined4 *)(param_2 + 8) = 0;
    *(undefined4 *)(param_2 + 4) = 0;
    *(undefined4 *)param_2 = 0;
    return;
  }
  *(undefined4 *)param_2 = *(undefined4 *)(iVar7 + 0x40);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(iVar7 + 0x44);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar7 + 0x48);
  if (*(int *)((int)this + 0x340) == 1) {
    GmVec3::SetMult(local_c,(SPlugFaceCull *)(*(int *)((int)this + 0x108) + 0x38),
                    (SPlugFaceCull *)(iVar7 + 0x10),unaff_EDI);
    fVar1 = *(float *)param_2;
    fVar2 = *(float *)(param_2 + 4);
    fVar3 = *(float *)(iVar7 + 0x60);
    fVar4 = *(float *)(iVar7 + 0x58);
    fVar5 = *(float *)(iVar7 + 0x58);
    fVar6 = *(float *)(iVar7 + 0x5c);
    *(float *)param_2 =
         *(float *)param_2 +
         ((*(float *)(param_2 + 8) - unaff_retaddr) * *(float *)(iVar7 + 0x5c) -
         (fVar2 - local_4) * *(float *)(iVar7 + 0x60));
    *(float *)(param_2 + 4) =
         *(float *)(param_2 + 4) +
         ((fVar1 - local_8) * fVar3 - fVar4 * (*(float *)(param_2 + 8) - unaff_retaddr));
    *(float *)(param_2 + 8) =
         *(float *)(param_2 + 8) + ((fVar2 - local_4) * fVar5 - fVar6 * (fVar1 - local_8));
  }
  return;
}
}

// =================================================
// Function: CHmsDyna::GetTimeLastHistoryPointMinusOne
// =================================================
ulong __thiscall CHmsDyna::GetTimeLastHistoryPointMinusOne(void *this,CHmsDyna *param_1)
{
{
  uint uVar1;
  
  uVar1 = *(int *)((int)this + 0x350) + 1;
  if (*(uint *)((int)this + 0x34c) <= uVar1) {
    uVar1 = uVar1 - *(uint *)((int)this + 0x34c);
  }
  return *(ulong *)(uVar1 * 0xe0 + 0xa8 + *(int *)((int)this + 0x348));
}
}

// =================================================
// Function: CHmsDyna::IntegrateStep
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsDyna::IntegrateStep
          (void *this,CHmsDyna *param_1,CHmsStateDyna *param_2,CHmsStateDyna *param_3,float param_4)
{
{
  CHmsStateDyna *pCVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  CHmsStateDyna *pCVar8;
  SPlugFaceCull *pSVar9;
  int iVar10;
  GmMat2 *unaff_EBX;
  GmQuat *unaff_EBP;
  int unaff_ESI;
  GmIso4 *unaff_EDI;
  float10 fVar11;
  float unaff_retaddr;
  float in_stack_00000014;
  float in_stack_00000018;
  GmIso4 *pGVar12;
  GmIso4 *pGVar13;
  GmIso3 *pGVar14;
  GmIso3 *pGVar15;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  pCVar8 = param_2;
  if (*(int *)((int)this + 0x340) == 2) {
    for (iVar10 = 0x2d; iVar10 != 0; iVar10 = iVar10 + -1) {
      *(undefined4 *)param_2 = *(undefined4 *)param_1;
      param_1 = param_1 + 4;
      param_2 = param_2 + 4;
    }
    return;
  }
  fVar7 = 1.0 / **(float **)((int)this + 0x108);
  fVar2 = *(float *)(param_1 + 100);
  fVar3 = *(float *)(param_1 + 0x68);
  fVar4 = *(float *)(param_1 + 0x6c);
  fVar5 = *(float *)(param_1 + 0x44);
  fVar6 = *(float *)(param_1 + 0x48);
  *(float *)(param_2 + 0x34) =
       (float)param_3 * *(float *)(param_1 + 0x40) + *(float *)(param_1 + 0x34);
  *(float *)(param_2 + 0x38) = *(float *)(param_1 + 0x38) + fVar5 * (float)param_3;
  *(float *)(param_2 + 0x3c) = *(float *)(param_1 + 0x3c) + fVar6 * (float)param_3;
  fVar5 = *(float *)(param_1 + 0x50);
  fVar6 = *(float *)(param_1 + 0x54);
  *(float *)(param_2 + 0x34) =
       *(float *)(param_2 + 0x34) + *(float *)(param_1 + 0x4c) * (float)param_3;
  *(float *)(param_2 + 0x38) = *(float *)(param_2 + 0x38) + fVar5 * (float)param_3;
  *(float *)(param_2 + 0x3c) = *(float *)(param_2 + 0x3c) + fVar6 * (float)param_3;
  *(undefined4 *)(param_2 + 0x54) = 0;
  *(undefined4 *)(param_2 + 0x50) = 0;
  *(undefined4 *)(param_2 + 0x4c) = 0;
  pGVar14 = (GmIso3 *)(fVar7 * fVar2 * (float)param_3);
  pGVar15 = (GmIso3 *)(fVar3 * fVar7 * (float)param_3);
  *(float *)(param_2 + 0x40) = *(float *)(param_1 + 0x40) + (float)pGVar14;
  *(float *)(param_2 + 0x44) = *(float *)(param_1 + 0x44) + (float)pGVar15;
  *(float *)(param_2 + 0x48) = *(float *)(param_1 + 0x48) + (float)param_3 * fVar7 * fVar4;
  if (*(int *)((int)this + 0x340) != 0) {
    GmVec3::SetMult(&local_c,(SPlugFaceCull *)(param_1 + 0x70),(SPlugFaceCull *)(param_1 + 0x7c),
                    unaff_EDI);
    pCVar1 = (CHmsStateDyna *)
             (*(float *)(param_1 + 0x60) * *(float *)(param_1 + 0x60) +
             *(float *)(param_1 + 0x58) * *(float *)(param_1 + 0x58) +
             *(float *)(param_1 + 0x5c) * *(float *)(param_1 + 0x5c));
    if ((float)pCVar1 <= _DAT_00cdb690) {
      GmMat3::Set(param_2 + 0x10,(CMwCmdScriptVarBool *)(param_1 + 0x10),unaff_ESI);
      GmVec4::Set(param_2,(CMwCmdScriptVarBool *)param_1,(int)unaff_EBP);
      param_2 = pCVar1;
    }
    else {
      local_c = (float)_DAT_00b313b8;
      local_18 = ((-*(float *)(param_1 + 0x58) * *(float *)(param_1 + 4) -
                  *(float *)(param_1 + 0x5c) * *(float *)(param_1 + 8)) -
                 *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x60)) * local_c;
      local_14 = ((*(float *)(param_1 + 0x5c) * *(float *)(param_1 + 0xc) +
                  *(float *)param_1 * *(float *)(param_1 + 0x58)) -
                 *(float *)(param_1 + 8) * *(float *)(param_1 + 0x60)) * local_c;
      local_10 = (*(float *)(param_1 + 0x60) * *(float *)(param_1 + 4) +
                 (*(float *)(param_1 + 0x5c) * *(float *)param_1 -
                 *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x58))) * local_c;
      local_c = (*(float *)param_1 * *(float *)(param_1 + 0x60) +
                (*(float *)(param_1 + 8) * *(float *)(param_1 + 0x58) -
                *(float *)(param_1 + 0x5c) * *(float *)(param_1 + 4))) * local_c;
      GmVec4::Set(param_2,(CMwCmdScriptVarBool *)param_1,unaff_ESI);
      *(float *)param_2 = *(float *)param_2 + in_stack_00000014 * local_14;
      *(float *)(param_2 + 4) = local_10 * in_stack_00000014 + *(float *)(param_2 + 4);
      *(float *)(param_2 + 8) = local_c * in_stack_00000014 + *(float *)(param_2 + 8);
      *(float *)(param_2 + 0xc) = in_stack_00000014 * local_8 + *(float *)(param_2 + 0xc);
      GmQuat::Normalize(param_2,unaff_EBP);
      pGVar12 = *(GmIso4 **)(param_2 + 8);
      pGVar13 = *(GmIso4 **)(param_2 + 0xc);
      GmMat3::Set((SPlugFaceCull *)(param_2 + 0x10),*(CMwCmdScriptVarBool **)param_2,
                  *(int *)(param_2 + 4));
      pSVar9 = (SPlugFaceCull *)(*(int *)((int)this + 0x108) + 0x38);
      GmVec3::SetMult(&local_18,pSVar9,(SPlugFaceCull *)(param_1 + 0x10),pGVar12);
      GmVec3::SetMult(&local_20,(SPlugFaceCull *)param_3,(SPlugFaceCull *)(param_2 + 0x10),pGVar13);
      local_20 = local_14 - local_8;
      *(float *)(param_2 + 0x34) = *(float *)(param_2 + 0x34) - (local_1c - local_10);
      *(float *)(param_2 + 0x38) = *(float *)(param_2 + 0x38) - (local_18 - local_c);
      *(float *)(param_2 + 0x3c) = *(float *)(param_2 + 0x3c) - local_20;
      param_2 = (CHmsStateDyna *)pSVar9;
    }
    *(float *)(pCVar8 + 0x58) = *(float *)(param_1 + 0x58) + in_stack_00000018 * unaff_retaddr;
    *(float *)(pCVar8 + 0x5c) = *(float *)(param_1 + 0x5c) + fVar7 * in_stack_00000018;
    *(float *)(pCVar8 + 0x60) = *(float *)(param_1 + 0x60) + in_stack_00000018 * (float)param_2;
    if ((*(int *)((int)this + 0xc0) != 0) &&
       (fVar2 = *(float *)((int)this + 0xc4),
       fVar2 * fVar2 <
       *(float *)(pCVar8 + 0x60) * *(float *)(pCVar8 + 0x60) +
       *(float *)(pCVar8 + 0x58) * *(float *)(pCVar8 + 0x58) +
       *(float *)(pCVar8 + 0x5c) * *(float *)(pCVar8 + 0x5c))) {
      fVar11 = (float10)func_0x009c1b40();
      fVar2 = fVar2 / (float)fVar11;
      *(float *)(pCVar8 + 0x58) = fVar2 * *(float *)(pCVar8 + 0x58);
      *(float *)(pCVar8 + 0x5c) = fVar2 * *(float *)(pCVar8 + 0x5c);
      *(float *)(pCVar8 + 0x60) = fVar2 * *(float *)(pCVar8 + 0x60);
    }
    pCVar1 = pCVar8 + 0x7c;
    GmMat3::SetTranspose(pCVar1,(GmMat2 *)(pCVar8 + 0x10),unaff_EBX);
    GmMat3::Mult(pCVar1,(GmIso3 *)(*(int *)((int)this + 0x108) + 4),pGVar14);
    GmMat3::Mult(pCVar1,(GmIso3 *)(pCVar8 + 0x10),pGVar15);
    return;
  }
  GmMat3::Set(param_2 + 0x10,(CMwCmdScriptVarBool *)(param_1 + 0x10),(int)unaff_EDI);
  return;
}
}

// =================================================
// Function: CHmsDyna::Interpolate
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsDyna::Interpolate
          (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmMat3 *param_3,GmVec3 *param_4,
          GmMat3 *param_5,ulong param_6,SHistoryPoint *param_7,SHistoryPoint *param_8)
{
{
  GmVec3 *pGVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  ulong uVar5;
  GmMat3 *unaff_ESI;
  GmMat3 *unaff_EDI;
  
  fVar2 = (float)*(int *)(param_6 + 0xa8);
  if (*(int *)(param_6 + 0xa8) < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  fVar3 = (float)_DAT_00b30a18;
  fVar4 = (float)*(int *)(param_7 + 0xa8);
  if (*(int *)(param_7 + 0xa8) < 0) {
    fVar4 = fVar4 + _DAT_00c418d0;
  }
  pGVar1 = (GmVec3 *)(fVar4 * fVar3 - fVar2 * fVar3);
  fVar4 = (float)(int)param_5;
  if ((int)param_5 < 0) {
    fVar4 = fVar4 + _DAT_00c418d0;
  }
  Interpolate(this,(CHmsDyna *)((fVar4 * fVar3 - fVar2 * fVar3) / (float)pGVar1),pGVar1,
              (GmMat3 *)(param_7 + 0xb0),(GmVec3 *)param_6,(GmMat3 *)param_7,param_6 + 0xc,
              param_7 + 0xc,(SHistoryPoint *)param_1);
  GmMat3::SetBlend(param_1,(SParam *)(param_6 + 0x24),(SParam *)(param_7 + 0x24),(SParam *)param_5,
                   (float)param_3);
  uVar5 = GmMat3::IsOrthonormal(param_1,unaff_EDI);
  if (uVar5 == 0) {
    GmMat3::OrthoNormalize(param_1,unaff_ESI);
  }
  return;
}
}

// =================================================
// Function: CHmsDyna::IsStateDifferentFrom
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall CHmsDyna::IsStateDifferentFrom(void *this,CHmsItem *param_1,GmIso4 *param_2)
{
{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  iVar1 = *(int *)((int)this + 0x328);
  fVar2 = *(float *)(param_1 + 0x24) - *(float *)(iVar1 + 0x34);
  fVar3 = *(float *)(param_1 + 0x28) - *(float *)(iVar1 + 0x38);
  fVar4 = *(float *)(param_1 + 0x2c) - *(float *)(iVar1 + 0x3c);
  if ((((fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3 <= _DAT_00b55d34) &&
       (fVar2 = *(float *)param_1 - *(float *)(iVar1 + 0x10),
       fVar3 = *(float *)(param_1 + 4) - *(float *)(iVar1 + 0x14),
       fVar4 = *(float *)(param_1 + 8) - *(float *)(iVar1 + 0x18),
       fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3 <= _DAT_00b55d34)) &&
      (fVar2 = *(float *)(param_1 + 0xc) - *(float *)(iVar1 + 0x1c),
      fVar3 = *(float *)(param_1 + 0x10) - *(float *)(iVar1 + 0x20),
      fVar4 = *(float *)(param_1 + 0x14) - *(float *)(iVar1 + 0x24),
      fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3 <= _DAT_00b55d34)) &&
     (fVar2 = *(float *)(param_1 + 0x18) - *(float *)(iVar1 + 0x28),
     fVar3 = *(float *)(param_1 + 0x1c) - *(float *)(iVar1 + 0x2c),
     fVar4 = *(float *)(param_1 + 0x20) - *(float *)(iVar1 + 0x30),
     fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3 <= _DAT_00b55d34)) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CHmsDyna::IsTwoLastHistoryPointsDifferent
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall CHmsDyna::IsTwoLastHistoryPointsDifferent(void *this,CHmsDyna *param_1)
{
{
  uint uVar1;
  float *pfVar2;
  float *pfVar3;
  
  uVar1 = *(uint *)((int)this + 0x350);
  if (*(uint *)((int)this + 0x34c) <= uVar1) {
    uVar1 = uVar1 - *(uint *)((int)this + 0x34c);
  }
  pfVar2 = (float *)(uVar1 * 0xe0 + *(int *)((int)this + 0x348));
  uVar1 = *(int *)((int)this + 0x350) + 1;
  if (*(uint *)((int)this + 0x34c) <= uVar1) {
    uVar1 = uVar1 - *(uint *)((int)this + 0x34c);
  }
  pfVar3 = (float *)(uVar1 * 0xe0 + *(int *)((int)this + 0x348));
  if (((((pfVar2[2] - pfVar3[2]) * (pfVar2[2] - pfVar3[2]) +
         (pfVar2[1] - pfVar3[1]) * (pfVar2[1] - pfVar3[1]) +
         (*pfVar2 - *pfVar3) * (*pfVar2 - *pfVar3) <= _DAT_00b55d34) &&
       ((pfVar2[0xb] - pfVar3[0xb]) * (pfVar2[0xb] - pfVar3[0xb]) +
        (pfVar2[10] - pfVar3[10]) * (pfVar2[10] - pfVar3[10]) +
        (pfVar2[9] - pfVar3[9]) * (pfVar2[9] - pfVar3[9]) <= _DAT_00b55d34)) &&
      ((pfVar2[0xe] - pfVar3[0xe]) * (pfVar2[0xe] - pfVar3[0xe]) +
       (pfVar2[0xd] - pfVar3[0xd]) * (pfVar2[0xd] - pfVar3[0xd]) +
       (pfVar2[0xc] - pfVar3[0xc]) * (pfVar2[0xc] - pfVar3[0xc]) <= _DAT_00b55d34)) &&
     ((pfVar2[0x11] - pfVar3[0x11]) * (pfVar2[0x11] - pfVar3[0x11]) +
      (pfVar2[0x10] - pfVar3[0x10]) * (pfVar2[0x10] - pfVar3[0x10]) +
      (pfVar2[0xf] - pfVar3[0xf]) * (pfVar2[0xf] - pfVar3[0xf]) <= _DAT_00b55d34)) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CHmsDyna::OldRestoreStaticState
// =================================================
void __thiscall
CHmsDyna::OldRestoreStaticState
          (void *this,CHmsCorpus *param_1,CClassicBufferMemory *param_2,int param_3,uchar param_4,
          int param_5)
{
{
  uchar unaff_retaddr;
  
  if (param_2 != (CClassicBufferMemory *)0x0) {
    CHmsStateDyna::OldRestoreState
              (*(void **)((int)this + 0x328),(CHmsStateDyna *)param_1,
               (CClassicBufferMemory *)param_3,unaff_retaddr);
    return;
  }
  CHmsStateDyna::OldRestoreState
            (*(void **)((int)this + 0x32c),(CHmsStateDyna *)param_1,(CClassicBufferMemory *)param_3,
             unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsDyna::PredictPointForInterpolation
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsDyna::PredictPointForInterpolation
          (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmMat3 *param_3,ulong param_4)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  ulong uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  CHmsDyna *pCVar10;
  SHistoryPoint *pSVar11;
  float unaff_EBX;
  GmMat3 *pGVar12;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CHmsDyna *unaff_ESI;
  SHistoryPoint *pSVar13;
  CHmsDyna *pCVar14;
  GmVec3 *pGVar15;
  GmVec3 *unaff_EDI;
  bool bVar16;
  GmVec3 *in_stack_00000014;
  CHmsDyna *in_stack_00000020;
  GmMat3 *in_stack_ffffffc8;
  GmVec3 *pGVar17;
  ulong in_stack_ffffffd4;
  GmVec3 local_20 [4];
  CHmsDyna *local_1c;
  undefined1 local_18 [4];
  GmMat3 aGStack_14 [12];
  GmVec3 aGStack_8 [8];
  
  uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0x344),unaff_EBP);
  pSVar11 = (SHistoryPoint *)0x0;
  if (uVar5 == 0) {
    return;
  }
  if (uVar5 == 1) {
    uVar6 = *(uint *)((int)this + 0x350);
    if (*(uint *)((int)this + 0x34c) <= uVar6) {
      uVar6 = uVar6 - *(uint *)((int)this + 0x34c);
    }
    puVar7 = (undefined4 *)(uVar6 * 0xe0 + *(int *)((int)this + 0x348));
    *(undefined4 *)param_2 = *puVar7;
    *(undefined4 *)(param_2 + 4) = puVar7[1];
    *(undefined4 *)(param_2 + 8) = puVar7[2];
    uVar6 = *(uint *)((int)this + 0x350);
    if (*(uint *)((int)this + 0x34c) <= uVar6) {
      uVar6 = uVar6 - *(uint *)((int)this + 0x34c);
    }
    puVar7 = (undefined4 *)(uVar6 * 0xe0 + 0x24 + *(int *)((int)this + 0x348));
    pGVar12 = param_3;
    for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined4 *)pGVar12 = *puVar7;
      puVar7 = puVar7 + 1;
      pGVar12 = pGVar12 + 4;
    }
    uVar6 = *(uint *)((int)this + 0x350);
    if (*(uint *)((int)this + 0x34c) <= uVar6) {
      uVar6 = uVar6 - *(uint *)((int)this + 0x34c);
    }
    uVar9 = *(uint *)((int)this + 0x350);
    if (*(uint *)((int)this + 0x34c) <= uVar9) {
      uVar9 = uVar9 - *(uint *)((int)this + 0x34c);
    }
    pCVar14 = (CHmsDyna *)(uVar6 * 0xe0 + 0x48 + *(int *)((int)this + 0x348));
    pGVar12 = (GmMat3 *)(uVar9 * 0xe0 + 0xc + *(int *)((int)this + 0x348));
  }
  else {
    if ((*(int *)((int)this + 0x528) == 0) || (*(uint *)((int)this + 0x4e0) <= param_4)) {
      *(undefined4 *)((int)this + 0x528) = 0;
      uVar6 = *(int *)((int)this + 0x350) + -1 + uVar5;
      if (*(uint *)((int)this + 0x34c) <= uVar6) {
        uVar6 = uVar6 - *(uint *)((int)this + 0x34c);
      }
      if (param_4 < *(uint *)(uVar6 * 0xe0 + 0xa8 + *(int *)((int)this + 0x348))) {
        uVar6 = *(int *)((int)this + 0x350) + -1 + uVar5;
        if (*(uint *)((int)this + 0x34c) <= uVar6) {
          uVar6 = uVar6 - *(uint *)((int)this + 0x34c);
        }
        puVar7 = (undefined4 *)(uVar6 * 0xe0 + *(int *)((int)this + 0x348));
        *(undefined4 *)param_2 = *puVar7;
        *(undefined4 *)(param_2 + 4) = puVar7[1];
        *(undefined4 *)(param_2 + 8) = puVar7[2];
        uVar6 = *(int *)((int)this + 0x350) + -1 + uVar5;
        if (*(uint *)((int)this + 0x34c) <= uVar6) {
          uVar6 = uVar6 - *(uint *)((int)this + 0x34c);
        }
        puVar7 = (undefined4 *)(uVar6 * 0xe0 + 0x24 + *(int *)((int)this + 0x348));
        pGVar12 = param_3;
        for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
          *(undefined4 *)pGVar12 = *puVar7;
          puVar7 = puVar7 + 1;
          pGVar12 = pGVar12 + 4;
        }
        uVar6 = *(int *)((int)this + 0x350) + -1 + uVar5;
        if (*(uint *)((int)this + 0x34c) <= uVar6) {
          uVar6 = uVar6 - *(uint *)((int)this + 0x34c);
        }
        uVar9 = *(int *)((int)this + 0x350) + -1 + uVar5;
        if (*(uint *)((int)this + 0x34c) <= uVar9) {
          uVar9 = uVar9 - *(uint *)((int)this + 0x34c);
        }
        pCVar14 = (CHmsDyna *)(uVar6 * 0xe0 + 0x48 + *(int *)((int)this + 0x348));
        pGVar12 = (GmMat3 *)(uVar9 * 0xe0 + 0xc + *(int *)((int)this + 0x348));
        goto LAB_005368db;
      }
      iVar8 = uVar5 - 1;
      bVar16 = iVar8 == 0;
      if (!bVar16) {
        do {
          uVar6 = *(int *)((int)this + 0x350) + -1 + iVar8;
          if (*(uint *)((int)this + 0x34c) <= uVar6) {
            uVar6 = uVar6 - *(uint *)((int)this + 0x34c);
          }
        } while ((*(uint *)(uVar6 * 0xe0 + 0xa8 + *(int *)((int)this + 0x348)) <= param_4) &&
                (iVar8 = iVar8 + -1, iVar8 != 0));
        bVar16 = iVar8 == 0;
      }
      uVar6 = *(uint *)((int)this + 0x350);
      uVar9 = *(uint *)((int)this + 0x34c);
      if (bVar16) {
        if (uVar9 <= uVar6) {
          uVar6 = uVar6 - uVar9;
        }
        iVar8 = *(int *)(uVar6 * 0xe0 + 0xa8 + *(int *)((int)this + 0x348));
        pGVar12 = (GmMat3 *)(iVar8 + 500);
        if (pGVar12 < param_4) {
          *(undefined4 *)((int)this + 0x524) = 1;
          param_4 = (ulong)pGVar12;
        }
        else {
          *(undefined4 *)((int)this + 0x524) = 0;
        }
        uVar6 = *(uint *)((int)this + 0x350);
        if (*(uint *)((int)this + 0x34c) <= uVar6) {
          uVar6 = uVar6 - *(uint *)((int)this + 0x34c);
        }
        pCVar10 = (CHmsDyna *)(uVar6 * 0xe0 + *(int *)((int)this + 0x348));
        *(undefined4 *)((int)this + 0x520) = 1;
        if (*(int *)((int)this + 0x51c) == 0) {
          *(int *)((int)this + 0x51c) = iVar8;
        }
      }
      else {
        uVar6 = uVar6 + iVar8;
        if (uVar9 <= uVar6) {
          uVar6 = uVar6 - uVar9;
        }
        pCVar10 = (CHmsDyna *)(uVar6 * 0xe0 + *(int *)((int)this + 0x348));
        uVar6 = *(int *)((int)this + 0x350) + -1 + iVar8;
        if (uVar9 <= uVar6) {
          uVar6 = uVar6 - uVar9;
        }
        pSVar11 = (SHistoryPoint *)(uVar6 * 0xe0 + *(int *)((int)this + 0x348));
        *(undefined4 *)((int)this + 0x520) = 0;
        *(undefined4 *)((int)this + 0x524) = 0;
        *(undefined4 *)((int)this + 0x51c) = 0;
        if (*(int *)(pSVar11 + 0xb0) == 2) {
          *(undefined4 *)param_2 = *(undefined4 *)pSVar11;
          *(undefined4 *)(param_2 + 4) = *(undefined4 *)(pSVar11 + 4);
          *(undefined4 *)(param_2 + 8) = *(undefined4 *)(pSVar11 + 8);
          pSVar13 = pSVar11 + 0x24;
          pGVar12 = param_3;
          for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
            *(undefined4 *)pGVar12 = *(undefined4 *)pSVar13;
            pSVar13 = pSVar13 + 4;
            pGVar12 = pGVar12 + 4;
          }
          SetLastPrediction(this,(CHmsDyna *)param_2,(GmVec3 *)param_3,(GmMat3 *)(pSVar11 + 0xc),
                            (GmVec3 *)(pSVar11 + 0x48),(GmMat3 *)param_4,(ulong)unaff_EDI);
          return;
        }
      }
    }
    else {
      pCVar10 = (CHmsDyna *)((int)this + 0x358);
      pSVar11 = (SHistoryPoint *)((int)this + 0x438);
    }
    if (*(GmMat3 **)(pCVar10 + 0xa8) <= param_4) {
      if (pSVar11 == (SHistoryPoint *)0x0) {
        if (100 < *(uint *)((int)this + 0x518)) {
          *(undefined4 *)param_2 = *(undefined4 *)pCVar10;
          *(undefined4 *)(param_2 + 4) = *(undefined4 *)(pCVar10 + 4);
          *(undefined4 *)(param_2 + 8) = *(undefined4 *)(pCVar10 + 8);
          pCVar14 = pCVar10 + 0x24;
          pGVar12 = param_3;
          for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
            *(undefined4 *)pGVar12 = *(undefined4 *)pCVar14;
            pCVar14 = pCVar14 + 4;
            pGVar12 = pGVar12 + 4;
          }
          SetLastPrediction(this,(CHmsDyna *)param_2,(GmVec3 *)param_3,(GmMat3 *)(pCVar10 + 0xc),
                            (GmVec3 *)(pCVar10 + 0x48),(GmMat3 *)param_4,(ulong)unaff_EDI);
          *(undefined4 *)((int)this + 0x528) = 0;
          *(undefined4 *)((int)this + 0x520) = 0;
          return;
        }
        if (*(int *)(pCVar10 + 0xb0) == 2) {
          *(undefined4 *)param_2 = *(undefined4 *)pCVar10;
          *(undefined4 *)(param_2 + 4) = *(undefined4 *)(pCVar10 + 4);
          *(undefined4 *)(param_2 + 8) = *(undefined4 *)(pCVar10 + 8);
          pCVar14 = pCVar10 + 0x24;
          pGVar12 = param_3;
          for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
            *(undefined4 *)pGVar12 = *(undefined4 *)pCVar14;
            pCVar14 = pCVar14 + 4;
            pGVar12 = pGVar12 + 4;
          }
          SetLastPrediction(this,(CHmsDyna *)param_2,(GmVec3 *)param_3,(GmMat3 *)(pCVar10 + 0xc),
                            (GmVec3 *)(pCVar10 + 0x48),(GmMat3 *)param_4,(ulong)unaff_EDI);
          return;
        }
        pGVar15 = (GmVec3 *)(param_4 + -(int)*(GmMat3 **)(pCVar10 + 0xa8));
        pGVar17 = (GmVec3 *)(pCVar10 + 0xc);
        ComputeNextPosition(this,pCVar10,pGVar17,(GmVec3 *)(pCVar10 + 0x18),pGVar15,(ulong)param_2,
                            unaff_EDI);
        pSVar11 = GetLastHistoryPointMinusOne(this,unaff_ESI);
        fVar1 = (float)(int)pGVar15;
        if ((int)pGVar15 < 0) {
          fVar1 = fVar1 + _DAT_00c418d0;
        }
        fVar2 = (float)_DAT_00b30a18;
        fVar4 = (float)*(int *)(pCVar10 + 0xa8);
        if (*(int *)(pCVar10 + 0xa8) < 0) {
          fVar4 = fVar4 + _DAT_00c418d0;
        }
        fVar3 = (float)*(int *)(pSVar11 + 0xa8);
        if (*(int *)(pSVar11 + 0xa8) < 0) {
          fVar3 = fVar3 + _DAT_00c418d0;
        }
        GmMat3::SetBlend(in_stack_00000014,(SParam *)(pSVar11 + 0x24),(SParam *)(pCVar10 + 0x24),
                         (SParam *)
                         ((fVar1 * fVar2) / (fVar4 * fVar2 - fVar3 * fVar2) + (float)_DAT_00b2c188),
                         unaff_EBX);
        uVar5 = GmMat3::IsOrthonormal(in_stack_00000014,in_stack_ffffffc8);
        if (uVar5 == 0) {
          GmMat3::OrthoNormalize(in_stack_00000014,(GmMat3 *)param_4);
        }
        ComputeNextSpeed(this,local_1c,(GmVec3 *)(pCVar10 + 0x18),pGVar15,(ulong)local_18,pGVar17);
        param_3 = (GmMat3 *)in_stack_00000014;
      }
      else {
        Interpolate(this,(CHmsDyna *)param_2,(GmVec3 *)param_3,(GmMat3 *)&stack0xffffffd4,local_20,
                    (GmMat3 *)param_4,(ulong)pCVar10,pSVar11,(SHistoryPoint *)unaff_EDI);
      }
      SetLastPrediction(this,in_stack_00000020,(GmVec3 *)param_3,aGStack_14,aGStack_8,
                        (GmMat3 *)local_1c,in_stack_ffffffd4);
      return;
    }
    *(undefined4 *)param_2 = *(undefined4 *)pCVar10;
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(pCVar10 + 4);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(pCVar10 + 8);
    pCVar14 = pCVar10 + 0x24;
    pGVar12 = param_3;
    for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined4 *)pGVar12 = *(undefined4 *)pCVar14;
      pCVar14 = pCVar14 + 4;
      pGVar12 = pGVar12 + 4;
    }
    pCVar14 = pCVar10 + 0x48;
    pGVar12 = (GmMat3 *)(pCVar10 + 0xc);
  }
LAB_005368db:
  SetLastPrediction(this,(CHmsDyna *)param_2,(GmVec3 *)param_3,pGVar12,(GmVec3 *)pCVar14,
                    (GmMat3 *)param_4,(ulong)unaff_EDI);
  *(undefined4 *)((int)this + 0x528) = 0;
  *(undefined4 *)((int)this + 0x520) = 0;
  *(undefined4 *)((int)this + 0x524) = 0;
  *(undefined4 *)((int)this + 0x51c) = 0;
  return;
}
}

// =================================================
// Function: CHmsDyna::Reset
// =================================================
void __thiscall CHmsDyna::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_ECX;
  GmFrustumIso4 *unaff_ESI;
  GmFrustumIso4 *unaff_retaddr;
  GmFrustumIso4 *in_stack_00000008;
  
  CHmsStateDyna::Reset((void *)((int)this + 0x10c),unaff_ESI);
  CHmsStateDyna::Reset((void *)((int)this + 0x1c0),unaff_retaddr);
  *(undefined4 *)((int)this + 0x32c) = extraout_ECX;
  *(undefined4 *)((int)this + 0x328) = extraout_EAX;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset((void *)((int)this + 0x330),param_1);
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 8) = 0;
  CHmsStateDyna::Reset((void *)((int)this + 0xc),in_stack_00000008);
  *(undefined4 *)((int)this + 4) = extraout_EAX_00;
  return;
}
}

// =================================================
// Function: CHmsDyna::RestoreStaticState
// =================================================
void __thiscall
CHmsDyna::RestoreStaticState
          (void *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,int param_3,ulong param_4
          ,ulong param_5,int param_6)
{
{
  uchar unaff_retaddr;
  
  if (param_2 != (CClassicBufferMemory *)0x0) {
    CHmsStateDyna::RestoreState
              (*(void **)((int)this + 0x328),(CHmsStateDyna *)param_1,
               (CClassicBufferMemory *)param_3,unaff_retaddr);
    return;
  }
  CHmsStateDyna::RestoreState
            (*(void **)((int)this + 0x32c),(CHmsStateDyna *)param_1,(CClassicBufferMemory *)param_3,
             unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsDyna::RotateOf
// =================================================
void __thiscall CHmsDyna::RotateOf(void *this,CHmsCorpus *param_1,GmMat3 *param_2)
{
{
  GmIso4 *unaff_ESI;
  GmMat3 *in_stack_ffffffd0;
  GmIso4 *in_stack_ffffffd4;
  CPlugTree local_28 [36];
  undefined4 local_4;
  
  GmMat3::SetMult(&stack0xffffffd0,(SPlugFaceCull *)param_1,
                  (SPlugFaceCull *)(*(int *)((int)this + 0x32c) + 0x10),unaff_ESI);
  GmMat3::OrthoNormalize(&stack0xffffffd4,in_stack_ffffffd0);
  local_4 = *(undefined4 *)(*(int *)((int)this + 0x32c) + 0x34);
  SetLocation(this,local_28,in_stack_ffffffd4);
  return;
}
}

// =================================================
// Function: CHmsDyna::SaveState
// =================================================
void __thiscall
CHmsDyna::SaveState(void *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,ulong *param_3,
                   ulong param_4)
{
{
  GmQuat *pGVar1;
  GmQuat *pGVar2;
  
  pGVar1 = *(GmQuat **)((int)this + 0x328);
  if (param_2 == (CClassicBufferMemory *)0x0) {
    GmArchive::WriteVec3Pos_9((CClassicBuffer *)param_1,(GmVec3 *)(pGVar1 + 0x34));
    GmArchive::WriteQuat_6((CClassicBuffer *)param_1,pGVar1);
  }
  else if (param_2 == (CClassicBufferMemory *)0x1) {
    GmArchive::WriteVec3Pos_12((CClassicBuffer *)param_1,(GmVec3 *)(pGVar1 + 0x34));
    GmArchive::WriteQuat_6((CClassicBuffer *)param_1,pGVar1);
    if ((DAT_00cdc700 == 0) || (pGVar2 = pGVar1 + 0xa4, *(int *)(pGVar1 + 0xa0) == 0)) {
      pGVar2 = pGVar1 + 0x40;
    }
    GmArchive::WriteVec3_4((CClassicBuffer *)param_1,(GmVec3 *)pGVar2);
    GmArchive::WriteVec3_4((CClassicBuffer *)param_1,(GmVec3 *)(pGVar1 + 0x58));
    return;
  }
  return;
}
}

// =================================================
// Function: CHmsDyna::SetAllInterpolationConstant
// =================================================
void __thiscall CHmsDyna::SetAllInterpolationConstant(void *this,CHmsDyna *param_1)
{
{
  uint uVar1;
  int extraout_EDX;
  EPredictionType unaff_ESI;
  EPredictionType unaff_retaddr;
  
  *(undefined4 *)((int)this + 0x528) = 0;
  uVar1 = *(uint *)((int)this + 0x350);
  if (*(uint *)((int)this + 0x34c) <= uVar1) {
    uVar1 = uVar1 - *(uint *)((int)this + 0x34c);
  }
  SetAllInterpolationMethods
            (this,(CHmsDyna *)(uVar1 * 0xe0 + *(int *)((int)this + 0x348)),(SHistoryPoint *)0x2,
             unaff_ESI);
  SetAllInterpolationMethods
            (this,(CHmsDyna *)((int)this + 0x438),(SHistoryPoint *)0x2,unaff_retaddr);
  *(undefined4 *)(extraout_EDX + 0xc) = 0;
  *(undefined4 *)(extraout_EDX + 0x10) = 0;
  *(undefined4 *)(extraout_EDX + 0x14) = 0;
  *(undefined4 *)(extraout_EDX + 0x18) = 0;
  *(undefined4 *)(extraout_EDX + 0x1c) = 0;
  *(undefined4 *)(extraout_EDX + 0x20) = 0;
  *(undefined4 *)(extraout_EDX + 0x48) = 0;
  *(undefined4 *)(extraout_EDX + 0x4c) = 0;
  *(undefined4 *)(extraout_EDX + 0x50) = 0;
  *(undefined4 *)(extraout_EDX + 0x6c) = 0;
  *(undefined4 *)(extraout_EDX + 0x70) = 0;
  *(undefined4 *)(extraout_EDX + 0x74) = 0;
  *(undefined4 *)(extraout_EDX + 0x60) = 0;
  *(undefined4 *)(extraout_EDX + 100) = 0;
  *(undefined4 *)(extraout_EDX + 0x68) = 0;
  *(undefined4 *)(extraout_EDX + 0x84) = 0;
  *(undefined4 *)(extraout_EDX + 0x88) = 0;
  *(undefined4 *)(extraout_EDX + 0x8c) = 0;
  return;
}
}

// =================================================
// Function: CHmsDyna::SetAllInterpolationLinear
// =================================================
void __thiscall CHmsDyna::SetAllInterpolationLinear(void *this,CHmsDyna *param_1)
{
{
  uint uVar1;
  uint uVar2;
  GmVec3 *pGVar3;
  ulong unaff_EBX;
  EPredictionType unaff_ESI;
  uint uVar4;
  CHmsDyna *pCVar5;
  EPredictionType unaff_EDI;
  ulong unaff_retaddr;
  
  uVar1 = *(uint *)((int)this + 0x34c);
  uVar2 = *(int *)((int)this + 0x350) + 1;
  if (uVar1 <= uVar2) {
    uVar2 = uVar2 - uVar1;
  }
  uVar4 = *(uint *)((int)this + 0x350);
  pGVar3 = (GmVec3 *)(uVar2 * 0xe0 + *(int *)((int)this + 0x348));
  if (uVar1 <= uVar4) {
    uVar4 = uVar4 - uVar1;
  }
  pCVar5 = (CHmsDyna *)(uVar4 * 0xe0 + *(int *)((int)this + 0x348));
  SetAllInterpolationMethods(this,pCVar5,(SHistoryPoint *)0x3,unaff_EDI);
  SetAllInterpolationMethods(this,(CHmsDyna *)((int)this + 0x438),(SHistoryPoint *)0x3,unaff_ESI);
  ComputeSpeed(this,pCVar5 + 0xc,pGVar3,(GmVec3 *)pCVar5,*(GmVec3 **)(pGVar3 + 0xa8),
               *(ulong *)(pCVar5 + 0xa8),unaff_EBX);
  *(undefined4 *)(pCVar5 + 0x18) = 0;
  *(undefined4 *)(pCVar5 + 0x1c) = 0;
  *(undefined4 *)(pCVar5 + 0x20) = 0;
  ComputeSpeed(this,pCVar5 + 0x48,pGVar3 + 0x24,(GmVec3 *)(pCVar5 + 0x24),
               *(GmVec3 **)(pGVar3 + 0xa8),*(ulong *)(pCVar5 + 0xa8),unaff_retaddr);
  *(undefined4 *)(pCVar5 + 0x6c) = 0;
  *(undefined4 *)(pCVar5 + 0x70) = 0;
  *(undefined4 *)(pCVar5 + 0x74) = 0;
  ComputeSpeed(this,pCVar5 + 0x60,pGVar3 + 0x3c,(GmVec3 *)(pCVar5 + 0x3c),
               *(GmVec3 **)(pGVar3 + 0xa8),*(ulong *)(pCVar5 + 0xa8),(ulong)param_1);
  *(undefined4 *)(pCVar5 + 0x84) = 0;
  *(undefined4 *)(pCVar5 + 0x88) = 0;
  *(undefined4 *)(pCVar5 + 0x8c) = 0;
  return;
}
}

// =================================================
// Function: CHmsDyna::SetAllInterpolationMethods
// =================================================
void __thiscall
CHmsDyna::SetAllInterpolationMethods
          (void *this,CHmsDyna *param_1,SHistoryPoint *param_2,EPredictionType param_3)
{
{
  *(SHistoryPoint **)(param_1 + 0xb0) = param_2;
  *(SHistoryPoint **)(param_1 + 0xb4) = param_2;
  *(SHistoryPoint **)(param_1 + 0xb8) = param_2;
  *(SHistoryPoint **)(param_1 + 0xbc) = param_2;
  *(SHistoryPoint **)(param_1 + 0xc0) = param_2;
  *(SHistoryPoint **)(param_1 + 0xc4) = param_2;
  *(SHistoryPoint **)(param_1 + 0xd4) = param_2;
  *(SHistoryPoint **)(param_1 + 0xd8) = param_2;
  *(SHistoryPoint **)(param_1 + 0xdc) = param_2;
  return;
}
}

// =================================================
// Function: CHmsDyna::SetAngularSpeed
// =================================================
void __thiscall CHmsDyna::SetAngularSpeed(void *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)param_1;
  *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)(param_1 + 8);
  return;
}
}

// =================================================
// Function: CHmsDyna::SetAsyncPrevDeltaT_End
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsDyna::SetAsyncPrevDeltaT_End(void *this,CHmsDyna *param_1,GmIso4 *param_2)
{
{
  SParam *this_00;
  SParam *pSVar1;
  GmIso3 *unaff_EBX;
  GmScaleTrans2 *unaff_ESI;
  float unaff_EDI;
  float unaff_retaddr;
  undefined1 local_30 [8];
  GmIso3 local_28 [40];
  
  if (_DAT_00cdbdd8 <= 0.0) {
    pSVar1 = (SParam *)0x3f800000;
  }
  else {
    pSVar1 = (SParam *)(_DAT_00cdbdd8 / (*(float *)(DAT_00d731e0 + 0x80) + (float)_DAT_00b30a18));
  }
  this_00 = (SParam *)((int)this + 200);
  GmIso4::SetBlend(local_30,(SParam *)param_1,this_00,pSVar1,unaff_EDI);
  GmIso4::SetInverse(this_00,(GmScaleTrans2 *)param_1,unaff_ESI);
  GmIso4::Mult(this_00,local_28,unaff_EBX);
  *(float *)((int)this + 0xf8) = unaff_retaddr - *(float *)(param_1 + 0x24);
  *(float *)((int)this + 0xfc) = (float)param_1 - *(float *)(param_1 + 0x28);
  *(float *)((int)this + 0x100) = (float)param_2 - *(float *)(param_1 + 0x2c);
  return;
}
}

// =================================================
// Function: CHmsDyna::SetDynamicType
// =================================================
void __thiscall CHmsDyna::SetDynamicType(void *this,CHmsItem *param_1,EDynamicType param_2)
{
{
  int iVar1;
  
  *(CHmsItem **)((int)this + 0x340) = param_1;
  iVar1 = *(int *)((int)this + 0x328);
  *(undefined4 *)(iVar1 + 0x60) = 0;
  *(undefined4 *)(iVar1 + 0x5c) = 0;
  *(undefined4 *)(iVar1 + 0x58) = 0;
  iVar1 = *(int *)((int)this + 0x32c);
  *(undefined4 *)(iVar1 + 0x60) = 0;
  *(undefined4 *)(iVar1 + 0x5c) = 0;
  *(undefined4 *)(iVar1 + 0x58) = 0;
  iVar1 = *(int *)((int)this + 0x328);
  *(undefined4 *)(iVar1 + 0x78) = 0;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  *(undefined4 *)(iVar1 + 0x70) = 0;
  iVar1 = *(int *)((int)this + 0x32c);
  *(undefined4 *)(iVar1 + 0x78) = 0;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  *(undefined4 *)(iVar1 + 0x70) = 0;
  return;
}
}

// =================================================
// Function: CHmsDyna::SetForce
// =================================================
void __thiscall CHmsDyna::SetForce(void *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  *(undefined4 *)(iVar1 + 100) = *(undefined4 *)param_1;
  *(undefined4 *)(iVar1 + 0x68) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(param_1 + 8);
  return;
}
}

// =================================================
// Function: CHmsDyna::SetLastPrediction
// =================================================
void __thiscall
CHmsDyna::SetLastPrediction
          (void *this,CHmsDyna *param_1,GmVec3 *param_2,GmMat3 *param_3,GmVec3 *param_4,
          GmMat3 *param_5,ulong param_6)
{
{
  int iVar1;
  GmVec3 *unaff_EDI;
  undefined4 *puVar2;
  
  *(undefined4 *)((int)this + 0x52c) = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 0x530) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 0x534) = *(undefined4 *)(param_1 + 8);
  puVar2 = (undefined4 *)((int)this + 0x538);
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)((int)this + 0x55c) = *(undefined4 *)param_3;
  *(undefined4 *)((int)this + 0x560) = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)((int)this + 0x564) = *(undefined4 *)(param_3 + 8);
  puVar2 = (undefined4 *)((int)this + 0x568);
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *(undefined4 *)param_4;
    param_4 = param_4 + 4;
    puVar2 = puVar2 + 1;
  }
  *(GmMat3 **)((int)this + 0x58c) = param_5;
  SetLinearSpeed(this,(CHmsItem *)param_3,unaff_EDI);
  return;
}
}

// =================================================
// Function: CHmsDyna::SetLinearSpeed
// =================================================
void __thiscall CHmsDyna::SetLinearSpeed(void *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)param_1;
  *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(param_1 + 8);
  return;
}
}

// =================================================
// Function: CHmsDyna::SetLocalAngularSpeed
// =================================================
void __thiscall CHmsDyna::SetLocalAngularSpeed(void *this,CHmsDyna *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  SetAngularSpeed(this,(CHmsItem *)&stack0xfffffff4,
                  (GmVec3 *)
                  (*(float *)(iVar1 + 0x18) * *(float *)(param_1 + 8) +
                  *(float *)(iVar1 + 0x10) * *(float *)param_1 +
                  *(float *)(iVar1 + 0x14) * *(float *)(param_1 + 4)));
  return;
}
}

// =================================================
// Function: CHmsDyna::SetLocalForce
// =================================================
void __thiscall CHmsDyna::SetLocalForce(void *this,CHmsDyna *param_1,GmVec3 *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  
  iVar7 = *(int *)((int)this + 0x32c);
  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_1 + 4);
  fVar3 = *(float *)(param_1 + 8);
  fVar4 = *(float *)param_1;
  fVar5 = *(float *)(param_1 + 4);
  fVar6 = *(float *)(param_1 + 8);
  *(float *)(iVar7 + 100) =
       *(float *)(iVar7 + 0x18) * *(float *)(param_1 + 8) +
       *(float *)(iVar7 + 0x10) * *(float *)param_1 +
       *(float *)(iVar7 + 0x14) * *(float *)(param_1 + 4);
  *(float *)(iVar7 + 0x68) =
       *(float *)(iVar7 + 0x24) * fVar3 +
       *(float *)(iVar7 + 0x20) * fVar2 + *(float *)(iVar7 + 0x1c) * fVar1;
  *(float *)(iVar7 + 0x6c) =
       *(float *)(iVar7 + 0x30) * fVar6 +
       *(float *)(iVar7 + 0x2c) * fVar5 + *(float *)(iVar7 + 0x28) * fVar4;
  return;
}
}

// =================================================
// Function: CHmsDyna::SetLocalLinearSpeed
// =================================================
void __thiscall CHmsDyna::SetLocalLinearSpeed(void *this,CHmsDyna *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  SetLinearSpeed(this,(CHmsItem *)&stack0xfffffff4,
                 (GmVec3 *)
                 (*(float *)(iVar1 + 0x18) * *(float *)(param_1 + 8) +
                 *(float *)(iVar1 + 0x10) * *(float *)param_1 +
                 *(float *)(iVar1 + 0x14) * *(float *)(param_1 + 4)));
  return;
}
}

// =================================================
// Function: CHmsDyna::SetLocalTorque
// =================================================
void __thiscall CHmsDyna::SetLocalTorque(void *this,CHmsDyna *param_1,GmVec3 *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  
  iVar7 = *(int *)((int)this + 0x32c);
  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_1 + 4);
  fVar3 = *(float *)(param_1 + 8);
  fVar4 = *(float *)param_1;
  fVar5 = *(float *)(param_1 + 4);
  fVar6 = *(float *)(param_1 + 8);
  *(float *)(iVar7 + 0x70) =
       *(float *)(iVar7 + 0x18) * *(float *)(param_1 + 8) +
       *(float *)(iVar7 + 0x10) * *(float *)param_1 +
       *(float *)(iVar7 + 0x14) * *(float *)(param_1 + 4);
  *(float *)(iVar7 + 0x74) =
       *(float *)(iVar7 + 0x24) * fVar3 +
       *(float *)(iVar7 + 0x20) * fVar2 + *(float *)(iVar7 + 0x1c) * fVar1;
  *(float *)(iVar7 + 0x78) =
       *(float *)(iVar7 + 0x30) * fVar6 +
       *(float *)(iVar7 + 0x2c) * fVar5 + *(float *)(iVar7 + 0x28) * fVar4;
  return;
}
}

// =================================================
// Function: CHmsDyna::SetLocation
// =================================================
void __thiscall CHmsDyna::SetLocation(void *this,CPlugTree *param_1,GmIso4 *param_2)
{
{
  int iVar1;
  int unaff_EBX;
  GmMat3 *unaff_EBP;
  GmIso4 *unaff_ESI;
  CPlugTree *pCVar2;
  int unaff_EDI;
  undefined4 *puVar3;
  int unaff_retaddr;
  
  GmQuat::Set(*(void **)((int)this + 0x328),(CMwCmdScriptVarBool *)param_1,unaff_EDI);
  pCVar2 = param_1;
  puVar3 = (undefined4 *)(*(int *)((int)this + 0x328) + 0x10);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)pCVar2;
    pCVar2 = pCVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  GmMat3::SetMult((void *)(*(int *)((int)this + 0x328) + 0x7c),
                  (SPlugFaceCull *)(*(int *)((int)this + 0x328) + 0x10),
                  (SPlugFaceCull *)(*(int *)((int)this + 0x108) + 4),unaff_ESI);
  GmMat3::MultTranspose
            ((void *)(*(int *)((int)this + 0x328) + 0x7c),
             (GmMat3 *)(*(int *)((int)this + 0x328) + 0x10),unaff_EBP);
  GmVec4::Set(*(void **)((int)this + 0x32c),*(CMwCmdScriptVarBool **)((int)this + 0x328),unaff_EBX);
  puVar3 = (undefined4 *)(*(int *)((int)this + 0x32c) + 0x10);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    puVar3 = puVar3 + 1;
  }
  GmMat3::Set((void *)(*(int *)((int)this + 0x32c) + 0x7c),
              (CMwCmdScriptVarBool *)(*(int *)((int)this + 0x328) + 0x7c),unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsDyna::SetTorque
// =================================================
void __thiscall CHmsDyna::SetTorque(void *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x32c);
  *(undefined4 *)(iVar1 + 0x70) = *(undefined4 *)param_1;
  *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x78) = *(undefined4 *)(param_1 + 8);
  return;
}
}

// =================================================
// Function: CHmsDyna::SetTranslation
// =================================================
void __thiscall CHmsDyna::SetTranslation(void *this,GmIso4 *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x328);
  *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)param_1;
  *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(param_1 + 8);
  iVar1 = *(int *)((int)this + 0x32c);
  *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)param_1;
  *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(param_1 + 8);
  return;
}
}

// =================================================
// Function: CHmsDyna::TestIfRespawn
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall CHmsDyna::TestIfRespawn(void *this,CHmsDyna *param_1)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  ulong uVar7;
  uint uVar8;
  float *pfVar9;
  float *pfVar10;
  SHistoryPoint *pSVar11;
  int iVar12;
  CHmsDyna *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ushort uVar13;
  float local_8;
  float local_4;
  
  uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0x344),unaff_EDI);
  if (uVar7 < 2) {
    return 1;
  }
  uVar8 = *(uint *)((int)this + 0x350);
  if (*(uint *)((int)this + 0x34c) <= uVar8) {
    uVar8 = uVar8 - *(uint *)((int)this + 0x34c);
  }
  pfVar9 = (float *)(uVar8 * 0xe0 + *(int *)((int)this + 0x348));
  uVar8 = *(int *)((int)this + 0x350) + 1;
  if (*(uint *)((int)this + 0x34c) <= uVar8) {
    uVar8 = uVar8 - *(uint *)((int)this + 0x34c);
  }
  pfVar10 = (float *)(uVar8 * 0xe0 + *(int *)((int)this + 0x348));
  fVar1 = pfVar10[0x2a];
  iVar12 = (int)pfVar9[0x2a] - (int)fVar1;
  if (iVar12 != 0) {
    fVar4 = (float)iVar12;
    if (iVar12 < 0) {
      fVar4 = fVar4 + _DAT_00c418d0;
    }
    fVar4 = 1.0 / fVar4;
    fVar2 = fVar4 * (*pfVar9 - *pfVar10);
    fVar3 = (pfVar9[1] - pfVar10[1]) * fVar4;
    fVar4 = fVar4 * (pfVar9[2] - pfVar10[2]);
    if (_DAT_00cdb68c < fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2) {
      return 1;
    }
    uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0x344),unaff_ESI);
    if ((((2 < uVar7) &&
         (pSVar11 = GetLastHistoryPointMinusTwo(this,unaff_EBX), pfVar10[0x2b] == 0.0)) &&
        (*(int *)(pSVar11 + 0xac) == 0)) &&
       (iVar12 = (int)fVar1 - *(int *)(pSVar11 + 0xa8), iVar12 != 0)) {
      fVar1 = (float)iVar12;
      if (iVar12 < 0) {
        fVar1 = fVar1 + _DAT_00c418d0;
      }
      fVar1 = 1.0 / fVar1;
      fVar3 = fVar1 * (*pfVar10 - *(float *)pSVar11);
      fVar5 = (pfVar10[1] - *(float *)(pSVar11 + 4)) * fVar1;
      fVar1 = fVar1 * (pfVar10[2] - *(float *)(pSVar11 + 8));
      fVar6 = fVar5 * fVar5 + fVar3 * fVar3 + fVar1 * fVar1;
      if (fVar6 <= (float)_DAT_00b48cc0) {
        uVar13 = (ushort)(fVar2 < (float)_DAT_00b36298) << 8 |
                 (ushort)(fVar2 == (float)_DAT_00b36298) << 0xe;
      }
      else {
        fVar1 = fVar4 * fVar3 + local_8 * fVar5 + local_4 * fVar1;
        fVar4 = (fVar1 * fVar1) / fVar6;
        if (fVar1 < 0.0) {
          return 1;
        }
        if (fVar6 + fVar6 < fVar4) {
          return 1;
        }
        uVar13 = (ushort)(fVar2 * (float)_DAT_00b43310 < fVar4) << 8 |
                 (ushort)(fVar2 * (float)_DAT_00b43310 == fVar4) << 0xe;
      }
      if (uVar13 == 0) {
        return 1;
      }
    }
  }
  return 0;
}
}

// =================================================
// Function: CHmsDyna::UpdateHistory
// =================================================
void __thiscall CHmsDyna::UpdateHistory(void *this,CHmsDyna *param_1,ulong param_2)
{
{
  void *this_00;
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  CFastBufferWheel<float> *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *unaff_EDI;
  int iVar4;
  
  this_00 = (void *)((int)this + 0x344);
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
  if (uVar1 != 0) {
    uVar2 = *(uint *)((int)this + 0x350);
    if (*(uint *)((int)this + 0x34c) <= uVar2) {
      uVar2 = uVar2 - *(uint *)((int)this + 0x34c);
    }
    if (DAT_00cdb688 + param_2 < *(uint *)(uVar2 * 0xe0 + 0xa8 + *(int *)((int)this + 0x348))) {
      CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::ClearWheel
                (this_00,unaff_EDI);
      return;
    }
    if (3 < uVar1) {
      iVar4 = 0;
      if (uVar1 != 0) {
        uVar3 = uVar1;
        do {
          uVar2 = *(int *)((int)this + 0x350) + -1 + uVar3;
          if (*(uint *)((int)this + 0x34c) <= uVar2) {
            uVar2 = uVar2 - *(uint *)((int)this + 0x34c);
          }
          if (param_2 - 1000 <= *(uint *)(uVar2 * 0xe0 + 0xa8 + *(int *)((int)this + 0x348))) break;
          iVar4 = iVar4 + 1;
          uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
        if (iVar4 != 0) {
          if (uVar1 - iVar4 < 3) {
            iVar4 = uVar1 - 3;
          }
          for (; iVar4 != 0; iVar4 = iVar4 + -1) {
            CFastBufferWheel<class_GmVec2>::Pull(this_00,unaff_EBP,(float *)unaff_EDI);
          }
        }
      }
    }
  }
  return;
}
}

// =================================================
// Function: CHmsDyna::ValidateDynamicState
// =================================================
void __thiscall CHmsDyna::ValidateDynamicState(void *this,CHmsDyna *param_1)
{
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)((int)this + 0x32c);
  puVar3 = *(undefined4 **)((int)this + 0x328);
  for (iVar1 = 0x2d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}
}

// =================================================
// Function: CHmsDyna::~CHmsDyna
// =================================================
void __thiscall CHmsDyna::~CHmsDyna(void *this,CHmsDyna *param_1)
{
{
  CFastBuffer<class_CPlugFileGPUV*> *unaff_ESI;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_00000008;
  
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x344),unaff_ESI);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x330),in_stack_00000008);
  return;
}
}

