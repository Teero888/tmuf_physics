// Class implementation: CFastBuffer_struct_CVisionViewportDx9_SRenderTarget

// =================================================
// Function: CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>::GetLastElem
// =================================================
SNewTriangleVert * __thiscall
CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>::GetLastElem
          (void *this,
          CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *param_1)
{
{
  return (SNewTriangleVert *)(*(int *)((int)this + 4) + -0x48 + *(int *)this * 0x48);
}
}

