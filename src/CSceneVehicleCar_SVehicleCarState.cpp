// Class implementation: CSceneVehicleCar_SVehicleCarState

// =================================================
// Function: CSceneVehicleCar::SVehicleCarState::Reset
// =================================================
void __thiscall CSceneVehicleCar::SVehicleCarState::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  SVehicleState *unaff_ESI;
  
  CSceneVehicle::SVehicleState::VehicleStateReset(this,unaff_ESI);
  *(undefined4 *)((int)this + 0x80) = 0;
  *(undefined4 *)((int)this + 0x98) = 0;
  *(undefined4 *)((int)this + 0x84) = 0;
  *(undefined4 *)((int)this + 0xa0) = 0;
  *(undefined4 *)((int)this + 0x88) = 0;
  *(undefined4 *)((int)this + 0x8c) = 0;
  *(undefined4 *)((int)this + 0x90) = 0;
  *(undefined4 *)((int)this + 0x94) = 0;
  *(undefined4 *)((int)this + 0x9c) = 0;
  *(undefined4 *)((int)this + 0xa4) = 0;
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::SVehicleCarState::Set
// =================================================
void __thiscall
CSceneVehicleCar::SVehicleCarState::Set(void *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  SVehicleState *unaff_EDI;
  
  CSceneVehicle::SVehicleState::VehicleStateSet(this,(SVehicleState *)param_1,unaff_EDI);
  *(undefined4 *)((int)this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)((int)this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)((int)this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)((int)this + 0x8c) = *(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)((int)this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  *(undefined4 *)((int)this + 0x94) = *(undefined4 *)(param_1 + 0x94);
  *(undefined4 *)((int)this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)((int)this + 0x9c) = *(undefined4 *)(param_1 + 0x9c);
  *(undefined4 *)((int)this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)((int)this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  return;
}
}

// =================================================
// Function: CSceneVehicleCar::SVehicleCarState::SetBlend
// =================================================
void __thiscall
CSceneVehicleCar::SVehicleCarState::SetBlend
          (void *this,SParam *param_1,SParam *param_2,SParam *param_3,float param_4)
{
{
  float unaff_EDI;
  
  CSceneVehicle::SVehicleState::VehicleStateSetBlend
            (this,(SVehicleState *)param_1,(SVehicleState *)param_2,(SVehicleState *)param_3,
             unaff_EDI);
  *(float *)((int)this + 0x80) =
       (1.0 - param_4) * *(float *)(param_1 + 0x80) + *(float *)(param_2 + 0x80) * param_4;
  *(undefined4 *)((int)this + 0x84) = *(undefined4 *)(param_2 + 0x84);
  *(undefined4 *)((int)this + 0x88) = *(undefined4 *)(param_2 + 0x88);
  *(undefined4 *)((int)this + 0x8c) = *(undefined4 *)(param_2 + 0x8c);
  *(undefined4 *)((int)this + 0x90) = *(undefined4 *)(param_2 + 0x90);
  *(undefined4 *)((int)this + 0x94) = *(undefined4 *)(param_2 + 0x94);
  *(undefined4 *)((int)this + 0x98) = *(undefined4 *)(param_2 + 0x98);
  *(undefined4 *)((int)this + 0x9c) = *(undefined4 *)(param_2 + 0x9c);
  *(undefined4 *)((int)this + 0xa0) = *(undefined4 *)(param_2 + 0xa0);
  *(undefined4 *)((int)this + 0xa4) = *(undefined4 *)(param_2 + 0xa4);
  return;
}
}

