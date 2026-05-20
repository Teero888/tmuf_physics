// Class implementation: CFastBuffer_class_CMwNodRef_class_CPlugModelMesh

// =================================================
// Function: CFastBuffer<class_CMwNodRef<class_CPlugModelMesh>_>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<class_CMwNodRef<class_CPlugModelMesh>_>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(*(int *)((int)this + 4) + iVar1 * 4);
}
}

