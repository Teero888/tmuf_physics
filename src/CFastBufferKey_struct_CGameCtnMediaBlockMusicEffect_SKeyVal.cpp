// Class implementation: CFastBufferKey_struct_CGameCtnMediaBlockMusicEffect_SKeyVal

// =================================================
// Function: CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal>::SetVal
// =================================================
void __thiscall
CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal>::SetVal
          (CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal> *this,
          CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *param_1,ulong param_2,
          SKeyVal *param_3)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                     (this + 4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_retaddr);
  *(undefined4 *)(pSVar1 + 4) = *(undefined4 *)param_3;
  *(undefined4 *)(pSVar1 + 8) = *(undefined4 *)(param_3 + 4);
  return;
}
}

