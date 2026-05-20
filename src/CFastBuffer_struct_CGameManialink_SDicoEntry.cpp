// Class implementation: CFastBuffer_struct_CGameManialink_SDicoEntry

// =================================================
// Function: CFastBuffer<struct_CGameManialink::SDicoEntry>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_CGameManialink::SDicoEntry>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(*(int *)((int)this + 4) + iVar1 * 8);
}
}

// =================================================
// Function: CFastBuffer<struct_CGameManialink::SDicoEntry>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<struct_CGameManialink::SDicoEntry>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

