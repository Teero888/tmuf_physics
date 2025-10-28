
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
