// Class implementation: CFastBuffer_struct_CSceneVehicleStruct_SVisualWheel_CFastBuffer_struct_CSceneVehicleStruct

// =================================================
// Function: ~CFastBuffer<struct_CSceneVehicleStruct::SVisualWheel>
// =================================================
void __thiscall
CFastBuffer<struct_CSceneVehicleStruct::SVisualWheel>::
~CFastBuffer<struct_CSceneVehicleStruct::SVisualWheel>
          (void *this,CFastBuffer<struct_CSceneVehicleStruct::SVisualWheel> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,0x28,*(int *)((int)pvVar1 + -4),
               CSceneVehicleStruct::SVisualWheel::~SVisualWheel);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  return;
}
}

