// Class implementation: CSceneVehicleCar_SSimulationWheel_SState

// =================================================
// Function: CSceneVehicleCar::SSimulationWheel::SState::Reset
// =================================================
void __thiscall CSceneVehicleCar::SSimulationWheel::SState::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  GmMat43 *unaff_EDI;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined2 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  GmMat3::SetIdentity((void *)((int)this + 0x30),unaff_EDI);
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::SSimulationWheel::SState::SetBlend
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::SSimulationWheel::SState::SetBlend
          (void *this,SParam *param_1,SParam *param_2,SParam *param_3,float param_4)
{
{
  float fVar1;
  SParam *pSVar2;
  SParam *pSVar3;
  undefined4 uVar4;
  
  pSVar3 = param_2;
  pSVar2 = param_1;
  fVar1 = 1.0 - (float)param_3;
  *(float *)this = *(float *)param_1 * fVar1 + *(float *)param_2 * (float)param_3;
  param_1 = *(SParam **)(param_1 + 4);
  param_2 = *(SParam **)(param_2 + 4);
  OrderWindowedValues((float *)&param_1,(float *)&param_2,_DAT_00b9ef64);
  *(float *)((int)this + 4) = fVar1 * (float)param_1 + (float)param_3 * (float)param_2;
  *(float *)((int)this + 8) =
       fVar1 * *(float *)(pSVar2 + 8) + *(float *)(pSVar3 + 8) * (float)param_3;
  if ((*(int *)(pSVar2 + 0x10) == 0) || (*(int *)(pSVar3 + 0x10) == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  *(undefined4 *)((int)this + 0x10) = uVar4;
  *(undefined2 *)((int)this + 0xc) = *(undefined2 *)(pSVar2 + 0xc);
  if ((*(int *)(pSVar2 + 0x14) != 0) && (*(int *)(pSVar3 + 0x14) != 0)) {
    *(undefined4 *)((int)this + 0x14) = 1;
    return;
  }
  *(undefined4 *)((int)this + 0x14) = 0;
  return;
}
}

