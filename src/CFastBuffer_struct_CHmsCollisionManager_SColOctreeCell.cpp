// Class implementation: CFastBuffer_struct_CHmsCollisionManager_SColOctreeCell

// =================================================
// Function: CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::Add
// =================================================
void __thiscall
CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::Add
          (void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  int iVar1;
  int iVar2;
  ulong unaff_EDI;
  undefined4 *puVar3;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  puVar3 = (undefined4 *)(*(int *)this * 0x58 + *(int *)((int)this + 4));
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this =
       (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1);
  return;
}
}

// =================================================
// Function: CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(iVar1 * 0x58 + *(int *)((int)this + 4));
}
}

// =================================================
// Function: CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>::SetSizeAtLeast
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
    pvVar1 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 0x58 >> 0x20) != 0) |
                            (uint)(ZEXT48(param_1) * 0x58));
    uVar4 = 0;
    if (*(int *)this != 0) {
      iVar2 = 0;
      do {
        uVar4 = uVar4 + 1;
        puVar5 = (undefined4 *)(*(int *)((int)this + 4) + iVar2);
        puVar6 = (undefined4 *)(iVar2 + (int)pvVar1);
        for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        iVar2 = iVar2 + 0x58;
      } while (uVar4 < *(uint *)this);
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    operator_delete__(*(void **)((int)this + 4));
    *(void **)((int)this + 4) = pvVar1;
  }
  return;
}
}

