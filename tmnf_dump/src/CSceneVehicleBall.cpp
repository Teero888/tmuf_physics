// Class implementation: CSceneVehicleBall

// =================================================
// Function: CSceneVehicleBall::AfterContacts
// =================================================
void __thiscall
CSceneVehicleBall::AfterContacts
          (CSceneVehicleBall *this,CCallbackSceneVehicleBallAfterContacts *param_1,CHmsItem *param_2
          )
{
{
  SCasterCat *pSVar1;
  int iVar2;
  ulong unaff_ESI;
  CSceneVehicleBall *pCVar3;
  float *pfVar4;
  GmVec3 *unaff_EDI;
  CSceneVehicleBall *pCVar5;
  float unaff_retaddr;
  CHmsItem local_c [8];
  float local_4;
  
  pCVar3 = this + 0x460;
  pCVar5 = this + 0x3e0;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pCVar5 = *(undefined4 *)pCVar3;
    pCVar3 = pCVar3 + 4;
    pCVar5 = pCVar5 + 4;
  }
  CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28),local_c,unaff_EDI);
  *(undefined4 *)(this + 0x468) = *(undefined4 *)(this + 0x58);
  *(undefined4 *)(this + 0x470) = *(undefined4 *)(this + 0x54);
  *(undefined4 *)(this + 0x46c) = *(undefined4 *)(this + 0x50);
  *(float *)(this + 0x460) = unaff_retaddr;
  *(undefined4 *)(this + 0x484) = *(undefined4 *)(this + 0x21c);
  *(undefined4 *)(this + 0x488) = *(undefined4 *)(this + 0x230);
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 0x28) + 0x34),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  iVar2 = *(int *)(*(int *)pSVar1 + 0x58);
  if (iVar2 == 0) {
    pfVar4 = (float *)(*(int *)pSVar1 + 0x18);
  }
  else {
    pfVar4 = (float *)(*(int *)(iVar2 + 0x32c) + 0x10);
  }
  pCVar3 = this + 0x494;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(float *)pCVar3 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pCVar3 = pCVar3 + 4;
  }
  *(float *)(this + 0x4cc) =
       unaff_retaddr * *(float *)(this + 0x498) + local_4 * *(float *)(this + 0x494) +
       (float)param_1 * *(float *)(this + 0x49c);
  *(float *)(this + 0x4d0) =
       *(float *)(this + 0x4a8) * (float)param_1 +
       *(float *)(this + 0x4a4) * unaff_retaddr + *(float *)(this + 0x4a0) * local_4;
  *(float *)(this + 0x4d4) =
       *(float *)(this + 0x4ac) * local_4 + *(float *)(this + 0x4b0) * unaff_retaddr +
       *(float *)(this + 0x4b4) * (float)param_1;
  return;
}
}

// =================================================
// Function: CSceneVehicleBall::AsyncStateCompute
// =================================================
void __thiscall
CSceneVehicleBall::AsyncStateCompute(CSceneVehicleBall *this,CSceneVehicleBall *param_1)
{
{
  undefined4 *puVar1;
  int iVar2;
  SVehicleBallState *unaff_ESI;
  CSceneVehicleBall *pCVar3;
  CSceneVehicle *unaff_EDI;
  CSceneVehicleBall *pCVar4;
  CSceneVehicleBall *pCVar5;
  SVehicleBallState *pSVar6;
  
  pCVar5 = this + 0x2e0;
  pCVar3 = pCVar5;
  pCVar4 = this + 0x360;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pCVar4 = *(undefined4 *)pCVar3;
    pCVar3 = pCVar3 + 4;
    pCVar4 = pCVar4 + 4;
  }
  pSVar6 = (SVehicleBallState *)
           CSceneVehicle::VehicleStateComputeBlendVal((CSceneVehicle *)this,unaff_EDI);
  if ((float)pSVar6 == 0.0) {
    SVehicleBallState::BallStateSet(pCVar5,(SVehicleBallState *)(this + 0x3e0),unaff_ESI);
  }
  else if ((float)pSVar6 == 1.0) {
    SVehicleBallState::BallStateSet(pCVar5,(SVehicleBallState *)(this + 0x460),unaff_ESI);
  }
  else {
    SVehicleBallState::BallStateSetBlend
              (pCVar5,(SVehicleBallState *)(this + 0x3e0),(SVehicleBallState *)(this + 0x460),pSVar6
               ,(float)unaff_ESI);
  }
  puVar1 = (undefined4 *)(**(code **)(*(int *)this + 0x80))(0);
  pCVar5 = this + 0x314;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pCVar5 = *puVar1;
    puVar1 = puVar1 + 1;
    pCVar5 = pCVar5 + 4;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleBall::VehicleReset
// =================================================
void __thiscall CSceneVehicleBall::VehicleReset(CSceneVehicleBall *this,CSceneVehicleBall *param_1)
{
{
  CSceneVehicleBall *unaff_ESI;
  SVehicleBallState *unaff_retaddr;
  SVehicleBallState *in_stack_00000008;
  SVehicleBallState *in_stack_00000014;
  
  CSceneVehicle::VehicleReset((CSceneVehicle *)this,unaff_ESI);
  SVehicleBallState::BallStateReset(this + 0x2e0,unaff_retaddr);
  SVehicleBallState::BallStateReset(this + 0x360,(SVehicleBallState *)param_1);
  SVehicleBallState::BallStateReset(this + 0x3e0,in_stack_00000008);
  SVehicleBallState::BallStateReset(this + 0x460,in_stack_00000014);
  return;
}
}

// =================================================
// Function: CSceneVehicleBall::VehicleUpdateAsync
// =================================================
void __thiscall
CSceneVehicleBall::VehicleUpdateAsync(CSceneVehicleBall *this,CSceneVehicleBall *param_1)
{
{
  int iVar1;
  GmMat3 *unaff_EBX;
  SVisualHandler *unaff_EBP;
  CSceneVehicle *unaff_ESI;
  CSceneVehicleBall *pCVar2;
  undefined4 *puVar3;
  CSceneVehicleBall *unaff_EDI;
  CSceneVehicleBall *pCVar4;
  SVisualHandler *in_stack_ffffffa0;
  SVisualHandler *in_stack_ffffffa4;
  GmMat43 *in_stack_ffffffa8;
  GmIso3 *in_stack_ffffffac;
  GmIso3 *in_stack_ffffffb0;
  SVisualHandler *in_stack_ffffffb4;
  undefined1 local_48 [4];
  GmIso3 local_44 [36];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined4 local_c [3];
  
  AsyncStateCompute(this,unaff_EDI);
  CSceneVehicle::VisualUpdateAsync((CSceneVehicle *)this,unaff_ESI);
  iVar1 = CSceneVehicle::SVisualHandler::IsInit(this + 0x104,unaff_EBP);
  if (iVar1 != 0) {
    pCVar2 = this + 0x10c;
    pCVar4 = this + 0x13c;
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)pCVar4 = *(undefined4 *)pCVar2;
      pCVar2 = pCVar2 + 4;
      pCVar4 = pCVar4 + 4;
    }
    GmMat3::MultTranspose(this + 0x13c,(GmMat3 *)(this + 0x314),unaff_EBX);
    CSceneVehicle::SVisualHandler::UpdateVisual(this + 0x104,in_stack_ffffffa0);
  }
  iVar1 = CSceneVehicle::SVisualHandler::IsInit(this + 0x170,in_stack_ffffffa4);
  if (iVar1 != 0) {
    pCVar2 = this + 0x178;
    puVar3 = &local_18;
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *(undefined4 *)pCVar2;
      pCVar2 = pCVar2 + 4;
      puVar3 = puVar3 + 1;
    }
    GmIso4::SetIdentity(local_48,in_stack_ffffffa8);
    local_20 = *(undefined4 *)(this + 0x338);
    local_1c = *(undefined4 *)(this + 0x33c);
    local_18 = *(undefined4 *)(this + 0x340);
    GmIso4::Mult(local_14,local_44,in_stack_ffffffac);
    GmIso4::MultInverse(local_10,(GmIso3 *)(this + 0x314),in_stack_ffffffb0);
    puVar3 = local_c;
    pCVar2 = this + 0x1a8;
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)pCVar2 = *puVar3;
      puVar3 = puVar3 + 1;
      pCVar2 = pCVar2 + 4;
    }
    CSceneVehicle::SVisualHandler::UpdateVisual(this + 0x170,in_stack_ffffffb4);
  }
  return;
}
}

