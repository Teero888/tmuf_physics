// Class implementation: CSceneVehicleCar_SSimulationWheel_SRealTimeState

// =================================================
// Function: CSceneVehicleCar::SSimulationWheel::SRealTimeState::Integrate
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCar::SSimulationWheel::SRealTimeState::Integrate
          (void *this,SRealTimeState *param_1,float param_2)
{
{
  GmMat3 *pGVar1;
  float10 fVar2;
  float fVar3;
  GmVec3 *pGVar4;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  local_10 = *(float *)((int)this + 0x6c) * (float)param_1 + *(float *)((int)this + 0x9c);
  fVar3 = GmFunc::Mod(local_10,0.0,_DAT_00b9ef64);
  *(float *)((int)this + 0x9c) = fVar3;
  pGVar1 = (GmMat3 *)((int)this + 0x90);
  local_10 = *(float *)((int)this + 0x98) * *(float *)((int)this + 0x98) +
             *(float *)pGVar1 * *(float *)pGVar1 +
             *(float *)((int)this + 0x94) * *(float *)((int)this + 0x94);
  if (_DAT_00d06a80 < local_10) {
    pGVar4 = (GmVec3 *)0x7c10da;
    fVar2 = (float10)func_0x009c1b40();
    fVar3 = 1.0 / (float)fVar2;
    *(float *)pGVar1 = fVar3 * *(float *)pGVar1;
    *(float *)((int)this + 0x94) = *(float *)((int)this + 0x94) * fVar3;
    *(float *)((int)this + 0x98) = fVar3 * *(float *)((int)this + 0x98);
    local_10 = *(float *)((int)this + 0x98) * 0.0 - *(float *)((int)this + 0x94) * 0.0;
    fStack_c = *(float *)pGVar1 * 0.0 - *(float *)((int)this + 0x98);
    fStack_8 = *(float *)((int)this + 0x94) - *(float *)pGVar1 * 0.0;
    GmMat3::SetUpVandDOV((void *)((int)this + 0x30),pGVar1,(GmVec3 *)&local_10,pGVar4);
  }
  if (*(float *)((int)this + 0xa4) <= *(float *)((int)this + 0xa0)) {
    fVar3 = *(float *)((int)this + 0xa0) - (float)param_1;
    *(float *)((int)this + 0xa0) = fVar3;
    if (fVar3 < *(float *)((int)this + 0xa4)) {
      *(undefined4 *)((int)this + 0xa0) = *(undefined4 *)((int)this + 0xa4);
    }
  }
  else {
    fVar3 = *(float *)((int)this + 0xa0) + (float)param_1;
    *(float *)((int)this + 0xa0) = fVar3;
    if (*(float *)((int)this + 0xa4) < fVar3) {
      *(undefined4 *)((int)this + 0xa0) = *(undefined4 *)((int)this + 0xa4);
      return;
    }
  }
  return;
}
}

