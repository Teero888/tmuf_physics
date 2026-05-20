// Class implementation: CSceneVehicleStruct_SSimulationWheel

// =================================================
// Function: CSceneVehicleStruct::SSimulationWheel::Reset
// =================================================
void __thiscall CSceneVehicleStruct::SSimulationWheel::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  int extraout_ECX;
  GmFrustumIso4 *unaff_retaddr;
  
  SSurfaceId::Reset(this,unaff_retaddr);
  *(undefined4 *)(extraout_ECX + 4) = 0;
  *(undefined4 *)(extraout_ECX + 8) = 0;
  return;
}
}

// =================================================
// Function: CSceneVehicleStruct::SSimulationWheel::SSimulationWheel
// =================================================
void __thiscall
CSceneVehicleStruct::SSimulationWheel::SSimulationWheel(void *this,SSimulationWheel *param_1)
{
{
  SMedalsInfo *unaff_ESI;
  GmFrustumIso4 *unaff_retaddr;
  
  CGameCtnMasterServer::SMedalsInfo::SMedalsInfo(this,unaff_ESI);
  Reset(this,unaff_retaddr);
  return;
}
}

