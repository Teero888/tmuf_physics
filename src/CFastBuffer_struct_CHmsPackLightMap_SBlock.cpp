// Class implementation: CFastBuffer_struct_CHmsPackLightMap_SBlock

// =================================================
// Function: CFastBuffer<struct_CHmsPackLightMap::SBlock>::ReplaceByLastAt
// =================================================
void __thiscall
CFastBuffer<struct_CHmsPackLightMap::SBlock>::ReplaceByLastAt
          (void *this,CFastBufferRef<class_CGameMobil> *param_1,ulong param_2,ulong param_3)
{
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  uVar1 = (*(int *)this - (int)param_1) - param_2;
  uVar5 = param_2;
  if (uVar1 < param_2) {
    uVar5 = uVar1;
  }
  if (uVar5 != 0) {
    iVar4 = (int)param_1 * 0x30;
    iVar2 = (*(int *)this - uVar5) * 0x30;
    do {
      puVar6 = (undefined4 *)(iVar2 + *(int *)((int)this + 4));
      puVar7 = (undefined4 *)(iVar4 + *(int *)((int)this + 4));
      iVar2 = iVar2 + 0x30;
      iVar4 = iVar4 + 0x30;
      uVar5 = uVar5 - 1;
      for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    } while (uVar5 != 0);
    *(ulong *)this = *(int *)this - param_2;
    return;
  }
  *(ulong *)this = *(int *)this - param_2;
  return;
}
}

