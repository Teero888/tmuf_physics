// Class implementation: CSceneVehicleBall_SVehicleBallState

// =================================================
// Function: CSceneVehicleBall::SVehicleBallState::BallStateReset
// =================================================
void __thiscall
CSceneVehicleBall::SVehicleBallState::BallStateReset(void *this,SVehicleBallState *param_1)
{
{
  GmMat43 *unaff_ESI;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  GmIso4::SetIdentity((void *)((int)this + 0x34),unaff_ESI);
  *(undefined4 *)((int)this + 100) = 1;
  *(undefined4 *)((int)this + 0x68) = 1;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x70) = 0;
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  return;
}
}

// =================================================
// Function: CSceneVehicleBall::SVehicleBallState::BallStateSet
// =================================================
void __thiscall
CSceneVehicleBall::SVehicleBallState::BallStateSet
          (void *this,SVehicleBallState *param_1,SVehicleBallState *param_2)
{
{
  int iVar1;
  SVehicleBallState *pSVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  pSVar2 = param_1 + 0x34;
  puVar3 = (undefined4 *)((int)this + 0x34);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)pSVar2;
    pSVar2 = pSVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)((int)this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  *(undefined4 *)((int)this + 0x70) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)((int)this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)((int)this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)((int)this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)((int)this + 0x78) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)((int)this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)((int)this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  return;
}
}

// =================================================
// Function: CSceneVehicleBall::SVehicleBallState::BallStateSetBlend
// =================================================
void __thiscall
CSceneVehicleBall::SVehicleBallState::BallStateSetBlend
          (void *this,SVehicleBallState *param_1,SVehicleBallState *param_2,
          SVehicleBallState *param_3,float param_4)
{
{
  float unaff_retaddr;
  
  CSceneVehicle::SVehicleState::VehicleStateSetBlend
            (this,(SVehicleState *)param_1,(SVehicleState *)param_2,(SVehicleState *)param_3,
             unaff_retaddr);
  return;
}
}

