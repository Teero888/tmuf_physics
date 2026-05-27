// Class implementation: CFastBuffer_struct_CGameCtnMenus_SFrameLadderRankingsStep

// =================================================
// Function: CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStep>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStep>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(iVar1 * 0x10 + *(int *)((int)this + 4));
}
}

// =================================================
// Function: CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStep>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStep>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  void *pvVar1;
  undefined4 *puVar2;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar3;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar4;
  uint uVar5;
  uint uVar6;
  SStringParam *pSVar7;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar8;
  SStringParam *pSVar9;
  SStringParam *in_stack_ffffffb8;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *local_20;
  SStringParam *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00aaa7db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar5 = *(uint *)((int)this + 8);
  uVar6 = 0;
  if (0 < (int)((int)param_1 - uVar5)) {
    if ((int)((int)param_1 - uVar5) <= (int)(uVar5 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar5 >> 1) + uVar5);
    }
    uVar5 = -(uint)((int)(ZEXT48(param_1) * 0x10 >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 0x10);
    puVar2 = operator_new__(-(uint)(0xfffffffb < uVar5) | uVar5 + 4);
    local_4 = 0;
    if (puVar2 == (undefined4 *)0x0) {
      pSVar7 = (SStringParam *)0x0;
    }
    else {
      pSVar7 = (SStringParam *)(puVar2 + 1);
      *puVar2 = param_1;
      in_stack_ffffffb8 = pSVar7;
      _eh_vector_constructor_iterator_
                (pSVar7,0x10,(int)param_1,CGamePopUp::SItem::SItem,CGamePopUp::SItem::~SItem);
    }
    pCVar3 = param_1;
    if (*(int *)this != 0) {
      pCVar3 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(-0xc - (int)pSVar7);
      pSVar9 = pSVar7 + 0xc;
      pCVar4 = pCVar3;
      do {
        pCVar8 = pCVar4 + *(int *)((int)this + 4);
        *(undefined4 *)(pSVar9 + -0xc) = *(undefined4 *)(pCVar8 + (int)pSVar9);
        pCVar4 = *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)(pCVar8 + (int)pSVar9 + 8);
        CFastStringInt::SetString(pSVar9 + -8,(CFastStringInt *)&stack0xffffffd4,in_stack_ffffffb8);
        *(undefined4 *)pSVar9 = *(undefined4 *)(pCVar8 + (int)pSVar9 + 0xc);
        uVar6 = uVar6 + 1;
        pSVar9 = pSVar9 + 0x10;
        pSVar7 = local_c;
      } while (uVar6 < *(uint *)this);
    }
    pvVar1 = *(void **)((int)this + 4);
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = pCVar3;
    if (pvVar1 != (void *)0x0) {
      _eh_vector_destructor_iterator_
                (pvVar1,0x10,*(int *)((int)pvVar1 + -4),CGamePopUp::SItem::~SItem);
      operator_delete__((void *)((int)pvVar1 + -4));
    }
    *(SStringParam **)((int)this + 4) = pSVar7;
    local_20 = param_1;
  }
  ExceptionList = local_20;
  return;
}
}

