// Class implementation: CFastBuffer_struct_CGameCtnMediaBlockEditorTriangles_SNewTriangleVert

// =================================================
// Function: CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>::GetLastElem
// =================================================
SNewTriangleVert * __thiscall
CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>::GetLastElem
          (void *this,
          CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *param_1)
{
{
  return (SNewTriangleVert *)(*(int *)((int)this + 4) + -8 + *(int *)this * 8);
}
}

