// Class implementation: CFastBuffer_struct_CGameCtnMediaTracker_SBlockEditInfo

// =================================================
// Function: CFastBuffer<struct_CGameCtnMediaTracker::SBlockEditInfo>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<struct_CGameCtnMediaTracker::SBlockEditInfo>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  void *pvVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar4 = *(uint *)((int)this + 8);
  if (0 < (int)((int)param_1 - uVar4)) {
    if ((int)((int)param_1 - uVar4) <= (int)(uVar4 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar4 >> 1) + uVar4);
    }
    pvVar1 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 0x20 >> 0x20) != 0) |
                            (uint)(ZEXT48(param_1) * 0x20));
    uVar4 = 0;
    if (*(int *)this != 0) {
      iVar2 = 0;
      do {
        uVar4 = uVar4 + 1;
        puVar5 = (undefined4 *)(*(int *)((int)this + 4) + iVar2);
        puVar6 = (undefined4 *)(iVar2 + (int)pvVar1);
        for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        iVar2 = iVar2 + 0x20;
      } while (uVar4 < *(uint *)this);
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    operator_delete__(*(void **)((int)this + 4));
    *(void **)((int)this + 4) = pvVar1;
  }
  return;
}
}

