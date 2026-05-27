// Class implementation: CFastBuffer_struct_CPlugFont_CUrlLinks_SUrlLink

// =================================================
// Function: CFastBuffer<struct_CPlugFont::CUrlLinks::SUrlLink>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_CPlugFont::CUrlLinks::SUrlLink>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(*(int *)((int)this + 4) + iVar1 * 0x38);
}
}

