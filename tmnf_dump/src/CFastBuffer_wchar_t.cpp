// Class implementation: CFastBuffer_wchar_t

// =================================================
// Function: CFastBuffer<wchar_t>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<wchar_t>::AllocSetCount(void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  CFastBuffer<unsigned_short>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

