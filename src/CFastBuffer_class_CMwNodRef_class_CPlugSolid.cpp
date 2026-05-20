// Class implementation: CFastBuffer_class_CMwNodRef_class_CPlugSolid

// =================================================
// Function: CFastBuffer<class_CMwNodRef<class_CPlugSolid>_>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<class_CMwNodRef<class_CPlugSolid>_>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

