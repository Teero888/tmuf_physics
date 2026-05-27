// Class implementation: CFastBufferWheel_struct_CGameCtnMediaBlockEditorTriangles_SBlockState_CFastBufferWheel_struct_CGameCtnMediaBlockEditorTriangles

// =================================================
// Function: ~CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>
// =================================================
void __thiscall
CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>::
~CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>
          (void *this,
          CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,0x28,*(int *)((int)pvVar1 + -4),
               CGameCtnMediaBlockEditorTriangles::SBlockState::~SBlockState);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  return;
}
}

