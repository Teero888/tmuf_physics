// Class implementation: CFastMapTable_unsigned_long_SScanner

// =================================================
// Function: CFastMapTable<unsigned_long>::SScanner::GetNext
// =================================================
int __thiscall
CFastMapTable<unsigned_long>::SScanner::GetNext
          (void *this,SScanner *param_1,ulong *param_2,SFillValue *param_3)
{
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)this;
  if (*(uint *)((int)this + 4) < *(uint *)(iVar1 + 0xc)) {
    do {
      iVar2 = *(int *)((int)this + 4);
      *(int *)((int)this + 4) = iVar2 + 1;
      if (*(int *)(*(int *)(iVar1 + 4) + iVar2 * 8) != -1) {
        *param_2 = *(ulong *)(*(int *)(iVar1 + 4) + 4 + iVar2 * 8);
        *(undefined4 *)param_1 = *(undefined4 *)(*(int *)(*(int *)this + 4) + iVar2 * 8);
        return 1;
      }
    } while (*(uint *)((int)this + 4) < *(uint *)(iVar1 + 0xc));
  }
  return 0;
}
}

