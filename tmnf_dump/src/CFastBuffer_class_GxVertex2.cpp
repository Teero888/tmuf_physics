// Class implementation: CFastBuffer_class_GxVertex2

// =================================================
// Function: CFastBuffer<class_GxVertex2>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<class_GxVertex2>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  CFastBuffer<struct_CGameCtnMediaTracker::SBlockEditInfo>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

