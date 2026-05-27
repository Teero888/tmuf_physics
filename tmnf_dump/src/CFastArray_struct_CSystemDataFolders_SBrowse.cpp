// Class implementation: CFastArray_struct_CSystemDataFolders_SBrowse

// =================================================
// Function: CFastArray<struct_CSystemDataFolders::SBrowse>::AllocateLess
// =================================================
void __thiscall
CFastArray<struct_CSystemDataFolders::SBrowse>::AllocateLess
          (void *this,CFastArray<struct_CHmsWaterRegion::SCell> *param_1,ulong param_2)
{
{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(int *)this - (int)param_1;
  pvVar3 = operator_new__(-(uint)((int)((ulonglong)uVar5 * 8 >> 0x20) != 0) |
                          (uint)((ulonglong)uVar5 * 8));
  uVar4 = 0;
  if (uVar5 != 0) {
    do {
      iVar1 = *(int *)((int)this + 4);
      *(undefined4 *)((int)pvVar3 + uVar4 * 8) = *(undefined4 *)(iVar1 + uVar4 * 8);
      *(undefined4 *)((int)pvVar3 + uVar4 * 8 + 4) = *(undefined4 *)(iVar1 + 4 + uVar4 * 8);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar5);
  }
  pvVar2 = *(void **)((int)this + 4);
  *(void **)((int)this + 4) = pvVar3;
  *(uint *)this = uVar5;
  operator_delete__(pvVar2);
  return;
}
}

