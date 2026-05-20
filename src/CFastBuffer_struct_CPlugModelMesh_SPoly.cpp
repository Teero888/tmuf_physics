// Class implementation: CFastBuffer_struct_CPlugModelMesh_SPoly

// =================================================
// Function: CFastBuffer<struct_CPlugModelMesh::SPoly>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<struct_CPlugModelMesh::SPoly>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  CFastBuffer<struct_SBindingToSort>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

