// Class implementation: CFastBuffer_struct_SHmsCameraProjection

// =================================================
// Function: CFastBuffer<struct_SHmsCameraProjection>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_SHmsCameraProjection>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  CFastBuffer<struct_CPlugBitmapRenderHemisphere::SHemiObject>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(iVar1 * 0xd0 + *(int *)((int)this + 4));
}
}

// =================================================
// Function: CFastBuffer<struct_SHmsCameraProjection>::GetLastElem
// =================================================
SNewTriangleVert * __thiscall
CFastBuffer<struct_SHmsCameraProjection>::GetLastElem
          (void *this,
          CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *param_1)
{
{
  return (SNewTriangleVert *)(*(int *)this * 0xd0 + -0xd0 + *(int *)((int)this + 4));
}
}

