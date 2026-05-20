// Class implementation: CFastBuffer_struct_CGameCtnMenus_SMenuLeaguePathStepInfos

// =================================================
// Function: CFastBuffer<struct_CGameCtnMenus::SMenuLeaguePathStepInfos>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_CGameCtnMenus::SMenuLeaguePathStepInfos>::AddNewElem
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
// Function: CFastBuffer<struct_CGameCtnMenus::SMenuLeaguePathStepInfos>::GetLastElem
// =================================================
SNewTriangleVert * __thiscall
CFastBuffer<struct_CGameCtnMenus::SMenuLeaguePathStepInfos>::GetLastElem
          (void *this,
          CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *param_1)
{
{
  return (SNewTriangleVert *)(*(int *)this * 0x10 + -0x10 + *(int *)((int)this + 4));
}
}

// =================================================
// Function: CFastBuffer<struct_CGameCtnMenus::SMenuLeaguePathStepInfos>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<struct_CGameCtnMenus::SMenuLeaguePathStepInfos>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  SStringParam *this_00;
  CFastStringInt *in_stack_ffffffac;
  SStringParam *in_stack_ffffffb0;
  SStringParam *local_40;
  undefined4 *local_28;
  undefined4 local_24;
  void *local_20;
  undefined4 local_18;
  void *local_c;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)&LAB_00aab07b;
  local_c = ExceptionList;
  local_40 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffc4);
  ExceptionList = &local_c;
  uVar3 = *(uint *)((int)this + 8);
  iVar4 = 0;
  if (0 < (int)((int)param_1 - uVar3)) {
    if ((int)((int)param_1 - uVar3) <= (int)(uVar3 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar3 >> 1) + uVar3);
    }
    uVar3 = -(uint)((int)(ZEXT48(param_1) * 0x10 >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 0x10);
    local_28 = operator_new__(-(uint)(0xfffffffb < uVar3) | uVar3 + 4);
    local_4 = 0;
    if (local_28 != (undefined4 *)0x0) {
      local_40 = (SStringParam *)(local_28 + 1);
      in_stack_ffffffb0 = (SStringParam *)0x10;
      *local_28 = param_1;
      in_stack_ffffffac = (CFastStringInt *)local_40;
      _eh_vector_constructor_iterator_
                (local_40,0x10,(int)param_1,CGameCtnApp::STip::STip,CGameCtnApp::STip::~STip);
    }
    local_18 = 0xffffffff;
    this_00 = local_40;
    if (*(int *)this != 0) {
      do {
        iVar1 = *(int *)(*(int *)((int)this + 4) + iVar4);
        iVar5 = *(int *)((int)this + 4) + iVar4;
        CFastStringInt::SetString
                  (this_00,(CFastStringInt *)&stack0xffffffc8,(SStringParam *)in_stack_ffffffac);
        local_28 = *(undefined4 **)(iVar5 + 0xc);
        local_24 = *(undefined4 *)(iVar5 + 8);
        in_stack_ffffffac = (CFastStringInt *)&local_28;
        local_20 = (void *)0x0;
        CFastStringInt::SetString(this_00 + 8,in_stack_ffffffac,in_stack_ffffffb0);
        iVar4 = iVar4 + 0x10;
        param_1 = local_8;
        this_00 = this_00 + 0x10;
      } while (iVar1 + 1U < *(uint *)this);
    }
    pvVar2 = *(void **)((int)this + 4);
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    if (pvVar2 != (void *)0x0) {
      _eh_vector_destructor_iterator_
                (pvVar2,0x10,*(int *)((int)pvVar2 + -4),CGameCtnApp::STip::~STip);
      operator_delete__((void *)((int)pvVar2 + -4));
    }
    *(SStringParam **)((int)this + 4) = local_40;
  }
  ExceptionList = local_20;
  return;
}
}

