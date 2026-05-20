// Class implementation: CFastBuffer_class_CSystemFidParameters

// =================================================
// Function: CFastBuffer<class_CSystemFidParameters>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<class_CSystemFidParameters>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(iVar1 * 0x30 + *(int *)((int)this + 4));
}
}

// =================================================
// Function: CFastBuffer<class_CSystemFidParameters>::ResetAndFreeMemory
// =================================================
void __thiscall
CFastBuffer<class_CSystemFidParameters>::ResetAndFreeMemory
          (void *this,CFastBuffer<struct_SInputActionDesc_const*> *param_1)
{
{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)((int)this + 4);
  if (puVar1 != (undefined4 *)0x0) {
    if (puVar1[-1] == 0) {
      operator_delete__(puVar1 + -1);
    }
    else {
      (**(code **)*puVar1)(3);
    }
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}
}

