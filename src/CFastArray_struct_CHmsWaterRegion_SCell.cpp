// Class implementation: CFastArray_struct_CHmsWaterRegion_SCell

// =================================================
// Function: CFastArray<struct_CHmsWaterRegion::SCell>::AllocateLess
// =================================================
void __thiscall
CFastArray<struct_CHmsWaterRegion::SCell>::AllocateLess
          (void *this,CFastArray<struct_CHmsWaterRegion::SCell> *param_1,ulong param_2)
{
{
  void *pvVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(int *)this - (int)param_1;
  pvVar2 = operator_new__(-(uint)((int)((ulonglong)uVar4 * 4 >> 0x20) != 0) |
                          (uint)((ulonglong)uVar4 * 4));
  uVar3 = 0;
  if (uVar4 != 0) {
    do {
      *(undefined4 *)((int)pvVar2 + uVar3 * 4) =
           *(undefined4 *)(*(int *)((int)this + 4) + uVar3 * 4);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  pvVar1 = *(void **)((int)this + 4);
  *(void **)((int)this + 4) = pvVar2;
  *(uint *)this = uVar4;
  operator_delete__(pvVar1);
  return;
}
}

