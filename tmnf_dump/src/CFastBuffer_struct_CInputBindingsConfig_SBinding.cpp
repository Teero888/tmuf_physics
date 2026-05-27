// Class implementation: CFastBuffer_struct_CInputBindingsConfig_SBinding

// =================================================
// Function: CFastBuffer<struct_CInputBindingsConfig::SBinding>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_CInputBindingsConfig::SBinding>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(*(int *)((int)this + 4) + iVar1 * 0xc);
}
}

// =================================================
// Function: CFastBuffer<struct_CInputBindingsConfig::SBinding>::ReplaceByLastAt
// =================================================
void __thiscall
CFastBuffer<struct_CInputBindingsConfig::SBinding>::ReplaceByLastAt
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
    iVar4 = (int)param_1 * 0xc;
    iVar3 = (*(int *)this - uVar2) * 0xc;
    do {
      iVar1 = *(int *)((int)this + 4);
      *(undefined4 *)(iVar4 + iVar1) = *(undefined4 *)(iVar3 + iVar1);
      *(undefined4 *)(iVar4 + 4 + iVar1) = *(undefined4 *)(iVar3 + 4 + iVar1);
      *(undefined4 *)(iVar4 + 8 + iVar1) = *(undefined4 *)(iVar3 + 8 + iVar1);
      iVar3 = iVar3 + 0xc;
      iVar4 = iVar4 + 0xc;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  *(ulong *)this = *(int *)this - param_2;
  return;
}
}

// =================================================
// Function: CFastBuffer<struct_CInputBindingsConfig::SBinding>::ResetAndFreeMemory
// =================================================
void __thiscall
CFastBuffer<struct_CInputBindingsConfig::SBinding>::ResetAndFreeMemory
          (void *this,CFastBuffer<struct_SInputActionDesc_const*> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,0xc,*(int *)((int)pvVar1 + -4),SCustomBitmapOld::~SCustomBitmapOld);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}
}

