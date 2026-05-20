// Class implementation: CFastBuffer_struct_GmOctree_struct_SMeshOctreeCell_SEntInfo

// =================================================
// Function: CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
// =================================================
void __thiscall
CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>::ReplaceByLastAt
          (void *this,CFastBufferRef<class_CGameMobil> *param_1,ulong param_2,ulong param_3)
{
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = (*(int *)this - (int)param_1) - param_2;
  if (param_2 <= uVar2) {
    uVar2 = param_2;
  }
  if (uVar2 != 0) {
    iVar4 = (int)param_1 * 8;
    iVar3 = (*(int *)this - uVar2) * 8;
    do {
      iVar1 = *(int *)((int)this + 4);
      *(undefined4 *)(iVar4 + iVar1) = *(undefined4 *)(iVar3 + iVar1);
      *(undefined4 *)(iVar4 + 4 + iVar1) = *(undefined4 *)(iVar3 + 4 + iVar1);
      iVar3 = iVar3 + 8;
      iVar4 = iVar4 + 8;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  *(ulong *)this = *(int *)this - param_2;
  return;
}
}

