// Class implementation: CFastBuffer_class_CFastStringIntForArray

// =================================================
// Function: CFastBuffer<class_CFastStringIntForArray>::InsertNewElemAt
// =================================================
SBitmapSpecular * __thiscall
CFastBuffer<class_CFastStringIntForArray>::InsertNewElemAt
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *param_1,ulong param_2
          )
{
{
  SNormalDec3N *pSVar1;
  int iVar2;
  GmVec3 *unaff_ESI;
  ulong unaff_EDI;
  
  iVar2 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar2 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  while (iVar2 = iVar2 + -1, (int)param_2 <= iVar2) {
    pSVar1 = (SNormalDec3N *)(*(int *)((int)this + 4) + iVar2 * 8);
    CFastStringIntForArray::operator=(pSVar1 + 8,pSVar1,unaff_ESI);
  }
  return (SBitmapSpecular *)(*(int *)((int)this + 4) + param_2 * 8);
}
}

