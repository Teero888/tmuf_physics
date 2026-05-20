// Class implementation: CFastBufferKey_struct_CGameCtnMediaBlockFxBlurDepth_SKeyVal

// =================================================
// Function: CFastBufferKey<struct_CGameCtnMediaBlockFxBlurDepth::SKeyVal>::SetVal
// =================================================
void __thiscall
CFastBufferKey<struct_CGameCtnMediaBlockFxBlurDepth::SKeyVal>::SetVal
          (CFastBufferKey<struct_CGameCtnMediaBlockFxBlurDepth::SKeyVal> *this,
          CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *param_1,ulong param_2,
          SKeyVal *param_3)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<class_GxColor>::operator[]
                     (this + 4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_retaddr);
  *(undefined4 *)(pSVar1 + 4) = *(undefined4 *)param_3;
  *(undefined4 *)(pSVar1 + 8) = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)(pSVar1 + 0xc) = *(undefined4 *)(param_3 + 8);
  return;
}
}

