// Class implementation: CFastBuffer_struct_CHmsVPackerCell_SLightSpotLoc

// =================================================
// Function: CFastBuffer<struct_CHmsVPackerCell::SLightSpotLoc>::ReplaceByLastAt
// =================================================
void __thiscall
CFastBuffer<struct_CHmsVPackerCell::SLightSpotLoc>::ReplaceByLastAt
          (void *this,CFastBufferRef<class_CGameMobil> *param_1,ulong param_2,ulong param_3)
{
{
  CFastBufferRef<class_CGameMobil> *pCVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  pCVar1 = (CFastBufferRef<class_CGameMobil> *)((*(int *)this - (int)param_1) - param_2);
  if (param_2 <= pCVar1) {
    pCVar1 = (CFastBufferRef<class_CGameMobil> *)param_2;
  }
  if (pCVar1 != (CFastBufferRef<class_CGameMobil> *)0x0) {
    iVar4 = (int)param_1 << 5;
    iVar3 = (*(int *)this - (int)pCVar1) * 0x20;
    param_1 = pCVar1;
    do {
      puVar5 = (undefined4 *)(iVar3 + *(int *)((int)this + 4));
      puVar6 = (undefined4 *)(iVar4 + *(int *)((int)this + 4));
      iVar3 = iVar3 + 0x20;
      iVar4 = iVar4 + 0x20;
      param_1 = param_1 + -1;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
    } while (param_1 != (CFastBufferRef<class_CGameMobil> *)0x0);
    *(ulong *)this = *(int *)this - param_2;
    return;
  }
  *(ulong *)this = *(int *)this - param_2;
  return;
}
}

