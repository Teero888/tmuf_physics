// Class implementation: CFastBuffer_struct_SIfBlock

// =================================================
// Function: CFastBuffer<struct_SIfBlock>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_SIfBlock>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  CFastBuffer<int>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(*(int *)((int)this + 4) + iVar1 * 4);
}
}

