// Class implementation: CFastBuffer_struct_CHmsCameraFx_SBitmapOutput

// =================================================
// Function: CFastBuffer<struct_CHmsCameraFx::SBitmapOutput>::ReplaceByLastAt
// =================================================
void __thiscall
CFastBuffer<struct_CHmsCameraFx::SBitmapOutput>::ReplaceByLastAt
          (void *this,CFastBufferRef<class_CGameMobil> *param_1,ulong param_2,ulong param_3)
{
{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = (*(int *)this - (int)param_1) - param_2;
  if (param_2 <= uVar3) {
    uVar3 = param_2;
  }
  if (uVar3 != 0) {
    iVar6 = (int)param_1 * 0xc;
    iVar5 = (*(int *)this - uVar3) * 0xc;
    do {
      iVar2 = *(int *)((int)this + 4);
      iVar1 = iVar5 + iVar2;
      puVar4 = (undefined4 *)(iVar2 + iVar6);
      *puVar4 = *(undefined4 *)(iVar5 + iVar2);
      puVar4[1] = *(undefined4 *)(iVar1 + 4);
      iVar5 = iVar5 + 0xc;
      iVar6 = iVar6 + 0xc;
      uVar3 = uVar3 - 1;
      puVar4[2] = *(undefined4 *)(iVar1 + 8);
    } while (uVar3 != 0);
    *(ulong *)this = *(int *)this - param_2;
    return;
  }
  *(ulong *)this = *(int *)this - param_2;
  return;
}
}

