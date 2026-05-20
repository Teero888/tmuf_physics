// Class implementation: CFastBufferKey_struct_CGameCtnMediaBlockSound_SKeyVal

// =================================================
// Function: CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SetVal
// =================================================
void __thiscall
CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SetVal
          (CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *this,
          CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *param_1,ulong param_2,
          SKeyVal *param_3)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                     (this + 4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_retaddr);
  *(undefined4 *)(pSVar1 + 4) = *(undefined4 *)param_3;
  *(undefined4 *)(pSVar1 + 8) = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)(pSVar1 + 0xc) = *(undefined4 *)(param_3 + 8);
  *(undefined4 *)(pSVar1 + 0x10) = *(undefined4 *)(param_3 + 0xc);
  *(undefined4 *)(pSVar1 + 0x14) = *(undefined4 *)(param_3 + 0x10);
  return;
}
}

