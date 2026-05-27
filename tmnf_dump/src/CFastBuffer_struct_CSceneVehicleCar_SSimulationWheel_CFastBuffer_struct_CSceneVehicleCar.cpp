// Class implementation: CFastBuffer_struct_CSceneVehicleCar_SSimulationWheel_CFastBuffer_struct_CSceneVehicleCar

// =================================================
// Function: ~CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>
// =================================================
void __thiscall
CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::
~CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>
          (void *this,CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,0x2fc,*(int *)((int)pvVar1 + -4),OnAccessViolation_ConcatToCrashFileName);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  return;
}
}

