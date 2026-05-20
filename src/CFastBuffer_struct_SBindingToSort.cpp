// Class implementation: CFastBuffer_struct_SBindingToSort

// =================================================
// Function: CFastBuffer<struct_SBindingToSort>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<struct_SBindingToSort>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  
  uVar3 = *(uint *)((int)this + 8);
  if (0 < (int)((int)param_1 - uVar3)) {
    if ((int)((int)param_1 - uVar3) <= (int)(uVar3 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar3 >> 1) + uVar3);
    }
    pvVar2 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 8 >> 0x20) != 0) |
                            (uint)(ZEXT48(param_1) * 8));
    uVar3 = 0;
    if (*(int *)this != 0) {
      do {
        iVar1 = *(int *)((int)this + 4);
        *(undefined4 *)((int)pvVar2 + uVar3 * 8) = *(undefined4 *)(iVar1 + uVar3 * 8);
        *(undefined4 *)((int)pvVar2 + uVar3 * 8 + 4) = *(undefined4 *)(iVar1 + 4 + uVar3 * 8);
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)this);
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    operator_delete__(*(void **)((int)this + 4));
    *(void **)((int)this + 4) = pvVar2;
  }
  return;
}
}

