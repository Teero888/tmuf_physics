// Class implementation: CSceneVehicle_SVehicleState

// =================================================
// Function: CSceneVehicle::SVehicleState::VehicleStateReset
// =================================================
void __thiscall CSceneVehicle::SVehicleState::VehicleStateReset(void *this,SVehicleState *param_1)
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
// Function: CSceneVehicle::SVehicleState::VehicleStateSet
// =================================================
void __thiscall
CSceneVehicle::SVehicleState::VehicleStateSet
          (void *this,SVehicleState *param_1,SVehicleState *param_2)
{
{
  int iVar1;
  SVehicleState *pSVar2;
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
// Function: CSceneVehicle::SVehicleState::VehicleStateSetBlend
// =================================================
void __thiscall
CSceneVehicle::SVehicleState::VehicleStateSetBlend
          (void *this,SVehicleState *param_1,SVehicleState *param_2,SVehicleState *param_3,
          float param_4)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float unaff_EDI;
  float unaff_retaddr;
  
  *(float *)this = *(float *)param_2 * (float)param_3 + (1.0 - (float)param_3) * *(float *)param_1;
  *(float *)((int)this + 4) =
       *(float *)(param_2 + 4) * (float)param_3 + (1.0 - (float)param_3) * *(float *)(param_1 + 4);
  GmIso4::SetBlend((void *)((int)this + 0x34),(SParam *)(param_1 + 0x34),(SParam *)(param_2 + 0x34),
                   (SParam *)param_3,unaff_EDI);
  *(float *)((int)this + 0x6c) = *(float *)(param_2 + 0x6c) - *(float *)(param_1 + 0x6c);
  *(float *)((int)this + 0x70) = *(float *)(param_2 + 0x70) - *(float *)(param_1 + 0x70);
  *(float *)((int)this + 0x74) = *(float *)(param_2 + 0x74) - *(float *)(param_1 + 0x74);
  fVar1 = param_4 * *(float *)((int)this + 0x6c);
  *(float *)((int)this + 0x6c) = fVar1;
  fVar2 = *(float *)((int)this + 0x70) * param_4;
  *(float *)((int)this + 0x70) = fVar2;
  fVar3 = *(float *)((int)this + 0x74) * param_4;
  *(float *)((int)this + 0x74) = fVar3;
  *(float *)((int)this + 0x6c) = *(float *)(param_1 + 0x6c) + fVar1;
  *(float *)((int)this + 0x70) = fVar2 + *(float *)(param_1 + 0x70);
  *(float *)((int)this + 0x74) = fVar3 + *(float *)(param_1 + 0x74);
  *(float *)((int)this + 8) =
       *(float *)(param_2 + 8) * param_4 + unaff_retaddr * *(float *)(param_1 + 8);
  *(float *)((int)this + 0xc) =
       *(float *)(param_2 + 0xc) * param_4 + *(float *)(param_1 + 0xc) * unaff_retaddr;
  *(float *)((int)this + 0x10) =
       *(float *)(param_2 + 0x10) * param_4 + *(float *)(param_1 + 0x10) * unaff_retaddr;
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_2 + 0x14);
  *(float *)((int)this + 0x18) =
       *(float *)(param_2 + 0x18) * param_4 + *(float *)(param_1 + 0x18) * unaff_retaddr;
  *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  *(float *)((int)this + 0x20) =
       *(float *)(param_2 + 0x20) * param_4 + *(float *)(param_1 + 0x20) * unaff_retaddr;
  *(float *)((int)this + 0x24) =
       *(float *)(param_2 + 0x24) * param_4 + *(float *)(param_1 + 0x24) * unaff_retaddr;
  *(float *)((int)this + 0x28) =
       *(float *)(param_2 + 0x28) * param_4 + *(float *)(param_1 + 0x28) * unaff_retaddr;
  *(float *)((int)this + 0x30) =
       *(float *)(param_2 + 0x30) * param_4 + *(float *)(param_1 + 0x30) * unaff_retaddr;
  *(float *)((int)this + 0x2c) =
       *(float *)(param_2 + 0x2c) * param_4 + *(float *)(param_1 + 0x2c) * unaff_retaddr;
  *(float *)((int)this + 0x7c) =
       *(float *)(param_2 + 0x7c) * param_4 + *(float *)(param_1 + 0x7c) * unaff_retaddr;
  *(float *)((int)this + 0x78) =
       unaff_retaddr * *(float *)(param_1 + 0x78) + *(float *)(param_2 + 0x78) * param_4;
  *(undefined4 *)((int)this + 100) = *(undefined4 *)(param_2 + 100);
  *(undefined4 *)((int)this + 0x68) = *(undefined4 *)(param_2 + 0x68);
  return;
}
}

