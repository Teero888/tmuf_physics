// Class implementation: CFastBuffer_struct_CFastBufferKey_struct_CFuncSegment_SKey_SKey

// =================================================
// Function: CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  CFastBuffer<struct_CSystemArchiveNod::SExternalRef>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

