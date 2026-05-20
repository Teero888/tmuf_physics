// Class implementation: CFastBufferCat_struct_CDx9StateBlock_SSamplerState_struct_CDx9StateBlock_SSamplerCat

// =================================================
// Function: GetElemInCat
// =================================================
SSamplerState * __thiscall
CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>::
GetElemInCat(void *this,
            CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
            *param_1,ulong param_2,ulong param_3)
{
{
  SCasterCat *pSVar1;
  ulong unaff_ESI;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                     (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,unaff_ESI);
  pSVar1 = CFastBuffer<struct_SFastCat>::operator[]
                     ((void *)((int)this + 0xc),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(*(int *)pSVar1 + param_2),
                      unaff_retaddr);
  return (SSamplerState *)pSVar1;
}
}

