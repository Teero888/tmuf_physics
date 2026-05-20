// Class implementation: CFastBuffer_struct_CSceneVehicle_SVisualArm

// =================================================
// Function: CFastBuffer<struct_CSceneVehicle::SVisualArm>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<struct_CSceneVehicle::SVisualArm>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

