// Class implementation: CFastBuffer_struct_CSceneVehicleStruct_SSimulationWheel_CFastBuffer_struct_CSceneVehicleStruct

// =================================================
// Function: ~CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>
// =================================================
void __thiscall
CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>::
~CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>
          (void *this,CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,0xc,*(int *)((int)pvVar1 + -4),SPlugGpuLoadFx::~SPlugGpuLoadFx);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  return;
}
}

