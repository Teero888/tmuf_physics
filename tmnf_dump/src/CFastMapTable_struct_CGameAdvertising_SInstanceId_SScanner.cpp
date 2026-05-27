// Class implementation: CFastMapTable_struct_CGameAdvertising_SInstanceId_SScanner

// =================================================
// Function: CFastMapTable<struct_CGameAdvertising::SInstanceId>::SScanner::GetNext
// =================================================
int __thiscall
CFastMapTable<struct_CGameAdvertising::SInstanceId>::SScanner::GetNext
          (void *this,SScanner *param_1,ulong *param_2,SFillValue *param_3)
{
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)this;
  if (*(uint *)((int)this + 4) < *(uint *)(iVar1 + 0xc)) {
    do {
      iVar2 = *(int *)((int)this + 4);
      *(int *)((int)this + 4) = iVar2 + 1;
      iVar3 = *(int *)(iVar1 + 4);
      if (*(int *)(iVar3 + iVar2 * 0xc) != -1) {
        iVar2 = iVar2 * 0xc;
        *param_2 = *(ulong *)(iVar3 + 4 + iVar2);
        param_2[1] = *(ulong *)(iVar3 + 8 + iVar2);
        *(undefined4 *)param_1 = *(undefined4 *)(iVar2 + *(int *)(*(int *)this + 4));
        return 1;
      }
    } while (*(uint *)((int)this + 4) < *(uint *)(iVar1 + 0xc));
  }
  return 0;
}
}

