// Class implementation: CFastBuffer_class_GmVector2_unsigned_short

// =================================================
// Function: CFastBuffer<class_GmVector2<unsigned_short>_>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<class_GmVector2<unsigned_short>_>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  CFastBuffer<int>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

