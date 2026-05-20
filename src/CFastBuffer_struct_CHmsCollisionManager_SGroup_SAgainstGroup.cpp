// Class implementation: CFastBuffer_struct_CHmsCollisionManager_SGroup_SAgainstGroup

// =================================================
// Function: CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup>::AddNewElem
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
// Function: CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  void *pvVar1;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar6;
  undefined4 *puVar7;
  void *unaff_EDI;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9550b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar4 = *(uint *)((int)this + 8);
  pCVar6 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x0;
  if (0 < (int)((int)param_1 - uVar4)) {
    if ((int)((int)param_1 - uVar4) <= (int)(uVar4 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar4 >> 1) + uVar4);
    }
    uVar4 = -(uint)((int)(ZEXT48(param_1) * 0x1c >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 0x1c);
    pCVar2 = operator_new__(-(uint)(0xfffffffb < uVar4) | uVar4 + 4);
    local_4 = 0;
    if (pCVar2 != (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x0) {
      pCVar6 = pCVar2 + 4;
      *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)pCVar2 = param_1;
      _eh_vector_constructor_iterator_
                (pCVar6,0x1c,(int)param_1,CHmsCollisionManager::SGroup::SAgainstGroup::SAgainstGroup
                 ,CHmsCollisionManager::SGroup::SAgainstGroup::~SAgainstGroup);
    }
    uVar4 = 0;
    if (*(int *)this != 0) {
      iVar3 = 0;
      do {
        uVar4 = uVar4 + 1;
        puVar7 = (undefined4 *)(*(int *)((int)this + 4) + iVar3);
        pCVar8 = pCVar6 + iVar3;
        for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined4 *)pCVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          pCVar8 = pCVar8 + 4;
        }
        iVar3 = iVar3 + 0x1c;
        param_1 = pCVar2;
      } while (uVar4 < *(uint *)this);
    }
    pvVar1 = *(void **)((int)this + 4);
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    if (pvVar1 != (void *)0x0) {
      _eh_vector_destructor_iterator_
                (pvVar1,0x1c,*(int *)((int)pvVar1 + -4),
                 CHmsCollisionManager::SGroup::SAgainstGroup::~SAgainstGroup);
      operator_delete__((void *)((int)pvVar1 + -4));
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 4) = pCVar6;
  }
  ExceptionList = unaff_EDI;
  return;
}
}

