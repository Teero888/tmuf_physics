// Class implementation: CFastBuffer_struct_CTrackManiaNetwork_SReplayToValidateData

// =================================================
// Function: CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData>::GetLastElem
// =================================================
SNewTriangleVert * __thiscall
CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData>::GetLastElem
          (void *this,
          CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *param_1)
{
{
  return (SNewTriangleVert *)(*(int *)this * 0x20 + -0x20 + *(int *)((int)this + 4));
}
}

// =================================================
// Function: CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData>::RemoveLastElem
// =================================================
void __thiscall
CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData>::RemoveLastElem
          (void *this,CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData> *param_1)
{
{
  *(int *)this = *(int *)this + -1;
  return;
}
}

