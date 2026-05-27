// Class implementation: CFastBuffer_class_GmNat2

// =================================================
// Function: CFastBuffer<class_GmNat2>::Add
// =================================================
void __thiscall
CFastBuffer<class_GmNat2>::Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  int iVar1;
  int iVar2;
  int iVar3;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  CFastBuffer<struct_SBindingToSort>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  iVar2 = *(int *)this;
  iVar3 = *(int *)((int)this + 4);
  *(undefined4 *)(iVar3 + iVar2 * 8) = *(undefined4 *)param_2;
  *(undefined4 *)(iVar3 + 4 + iVar2 * 8) = *(undefined4 *)(param_2 + 4);
  *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this =
       (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1);
  return;
}
}

// =================================================
// Function: CFastBuffer<class_GmNat2>::Find
// =================================================
int __thiscall
CFastBuffer<class_GmNat2>::Find
          (void *this,CFastArray<class_GxTexCoordSet> *param_1,GxTexCoordSet *param_2)
{
{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  if (*(uint *)this != 0) {
    piVar2 = *(int **)((int)this + 4);
    do {
      if ((*piVar2 == *(int *)param_1) && (piVar2[1] == *(int *)(param_1 + 4))) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
      piVar2 = piVar2 + 2;
    } while (uVar1 < *(uint *)this);
  }
  return -1;
}
}

// =================================================
// Function: CFastBuffer<class_GmNat2>::InsertElemAt
// =================================================
void __thiscall
CFastBuffer<class_GmNat2>::InsertElemAt
          (void *this,CFastBuffer<struct_CInputDevice::SRumble> *param_1,ulong param_2,
          SRumble *param_3)
{
{
  undefined4 uVar1;
  SBitmapSpecular *pSVar2;
  ulong unaff_retaddr;
  
  pSVar2 = InsertNewElemAt(this,(CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *)param_1,
                           unaff_retaddr);
  uVar1 = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)pSVar2 = *(undefined4 *)param_3;
  *(undefined4 *)(pSVar2 + 4) = uVar1;
  return;
}
}

