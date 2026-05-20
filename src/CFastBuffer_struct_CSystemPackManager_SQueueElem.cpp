// Class implementation: CFastBuffer_struct_CSystemPackManager_SQueueElem

// =================================================
// Function: CFastBuffer<struct_CSystemPackManager::SQueueElem>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_CSystemPackManager::SQueueElem>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(*(int *)((int)this + 4) + iVar1 * 0x1c);
}
}

// =================================================
// Function: CFastBuffer<struct_CSystemPackManager::SQueueElem>::ReplaceByLastAt
// =================================================
void __thiscall
CFastBuffer<struct_CSystemPackManager::SQueueElem>::ReplaceByLastAt
          (void *this,CFastBufferRef<class_CGameMobil> *param_1,ulong param_2,ulong param_3)
{
{
  int iVar1;
  uint uVar2;
  int iVar3;
  SStringParam *unaff_EDI;
  int iVar4;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar2 = (*(int *)this - (int)param_1) - param_2;
  if (param_2 <= uVar2) {
    uVar2 = param_2;
  }
  if (uVar2 != 0) {
    iVar3 = (int)param_1 * 0x1c;
    iVar4 = (*(int *)this - uVar2) * 0x1c;
    do {
      iVar1 = *(int *)((int)this + 4);
      *(undefined4 *)(iVar3 + iVar1) = *(undefined4 *)(iVar4 + iVar1);
      local_8 = *(undefined4 *)(iVar4 + 8 + iVar1);
      local_4 = *(undefined4 *)(iVar4 + 4 + iVar1);
      CFastString::SetString
                ((CFastString *)(iVar3 + 4 + iVar1),(CFastStringInt *)&local_8,unaff_EDI);
      *(undefined4 *)(iVar3 + 0xc + iVar1) = *(undefined4 *)(iVar4 + 0xc + iVar1);
      *(undefined4 *)(iVar3 + 0x10 + iVar1) = *(undefined4 *)(iVar4 + 0x10 + iVar1);
      *(undefined4 *)(iVar3 + 0x14 + iVar1) = *(undefined4 *)(iVar4 + 0x14 + iVar1);
      *(undefined4 *)(iVar3 + 0x18 + iVar1) = *(undefined4 *)(iVar4 + 0x18 + iVar1);
      iVar4 = iVar4 + 0x1c;
      iVar3 = iVar3 + 0x1c;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
    *(ulong *)this = *(int *)this - param_3;
    return;
  }
  *(ulong *)this = *(int *)this - param_2;
  return;
}
}

