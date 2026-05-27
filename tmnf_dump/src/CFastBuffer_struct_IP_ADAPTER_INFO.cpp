// Class implementation: CFastBuffer_struct_IP_ADAPTER_INFO

// =================================================
// Function: CFastBuffer<struct__IP_ADAPTER_INFO>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<struct__IP_ADAPTER_INFO>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

