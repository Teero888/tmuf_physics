// Class implementation: CFastBuffer_struct_CHmsViewport_SClippingFrustum

// =================================================
// Function: CFastBuffer<struct_CHmsViewport::SClippingFrustum>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_CHmsViewport::SClippingFrustum>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(iVar1 * 0x138 + *(int *)((int)this + 4));
}
}

// =================================================
// Function: CFastBuffer<struct_CHmsViewport::SClippingFrustum>::GetLastElem
// =================================================
SNewTriangleVert * __thiscall
CFastBuffer<struct_CHmsViewport::SClippingFrustum>::GetLastElem
          (void *this,
          CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *param_1)
{
{
  return (SNewTriangleVert *)(*(int *)this * 0x138 + -0x138 + *(int *)((int)this + 4));
}
}

// =================================================
// Function: CFastBuffer<struct_CHmsViewport::SClippingFrustum>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<struct_CHmsViewport::SClippingFrustum>::SetSizeAtLeast
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
    pvVar1 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 0x138 >> 0x20) != 0) |
                            (uint)(ZEXT48(param_1) * 0x138));
    uVar4 = 0;
    if (*(int *)this != 0) {
      iVar2 = 0;
      do {
        uVar4 = uVar4 + 1;
        puVar5 = (undefined4 *)(*(int *)((int)this + 4) + iVar2);
        puVar6 = (undefined4 *)(iVar2 + (int)pvVar1);
        for (iVar3 = 0x4e; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        iVar2 = iVar2 + 0x138;
      } while (uVar4 < *(uint *)this);
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    operator_delete__(*(void **)((int)this + 4));
    *(void **)((int)this + 4) = pvVar1;
  }
  return;
}
}

