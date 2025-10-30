
/* public: __thiscall
 * CSceneVehicleStruct::SSimulationVehicle::~SSimulationVehicle(void) */

void __thiscall CSceneVehicleStruct::SSimulationVehicle::~SSimulationVehicle(
    SSimulationVehicle *this)

{
  void *pvVar1;

  pvVar1 = *(void **)(this + 4);
  if (pvVar1 != (void *)0x0) {
    `eh_vector_destructor_iterator' (pvVar1, 0xc, *(int *)((int)pvVar1 + -4),
                                     SPlugGpuLoadFx::~SPlugGpuLoadFx);
    operator_delete[]((void *)((int)pvVar1 + -4));
  }
  return;
}

/* public: void __thiscall CSceneVehicleStruct::SSimulationWheel::Reset(void) */

void __thiscall CSceneVehicleStruct::SSimulationWheel::Reset(
    SSimulationWheel *this)

{
  int extraout_ECX;

  SSurfaceId::Reset((SSurfaceId *)this);
  *(undefined4 *)(extraout_ECX + 4) = 0;
  *(undefined4 *)(extraout_ECX + 8) = 0;
  return;
}

/* public: __thiscall
 * CSceneVehicleStruct::SSimulationWheel::SSimulationWheel(void) */

SSimulationWheel
    *__thiscall CSceneVehicleStruct::SSimulationWheel::SSimulationWheel(
        SSimulationWheel *this)

{
  CGameCtnMasterServer::SMedalsInfo::SMedalsInfo((SMedalsInfo *)this);
  Reset(this);
  return this;
}
