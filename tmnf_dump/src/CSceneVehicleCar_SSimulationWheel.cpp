// Class implementation: CSceneVehicleCar_SSimulationWheel

// =================================================
// Function: CSceneVehicleCar::SSimulationWheel::SSimulationWheel
// =================================================
void __thiscall
CSceneVehicleCar::SSimulationWheel::SSimulationWheel(void *this,SSimulationWheel *param_1)
{
{
  SSurfaceHandler *unaff_ESI;
  GmMat43 *unaff_retaddr;
  
  CSceneVehicle::SSurfaceHandler::SSurfaceHandler((void *)((int)this + 0xc),unaff_ESI);
  *(undefined4 *)((int)this + 0xb0) = 0;
  *(undefined4 *)((int)this + 0xac) = 0;
  *(undefined4 *)((int)this + 0xa8) = 0;
  GmIso4::SetIdentity((void *)((int)this + 0x70),unaff_retaddr);
  *(undefined4 *)((int)this + 0xa0) = 0x3f800000;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 0xa4) = 0x3f800000;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0x3f800000;
  return;
}
}

