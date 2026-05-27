// Class implementation: CFastBuffer_struct_CSceneTrafficGraph_SEdge

// =================================================
// Function: CFastBuffer<struct_CSceneTrafficGraph::SEdge>::InitSize
// =================================================
void __thiscall
CFastBuffer<struct_CSceneTrafficGraph::SEdge>::InitSize
          (void *this,CFastBuffer<struct_SMeshOctreeCell> *param_1,ulong param_2)
{
{
  void *pvVar1;
  
  *(CFastBuffer<struct_SMeshOctreeCell> **)((int)this + 8) = param_1;
  pvVar1 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 0xc >> 0x20) != 0) |
                          (uint)(ZEXT48(param_1) * 0xc));
  *(void **)((int)this + 4) = pvVar1;
  *(undefined4 *)this = 0;
  return;
}
}

