// Class implementation: CFastBuffer_struct_CGameCtnMenus_SFrameLadderRankingsStepOld_CFastBuffer_struct_CGameCtnMenus

// =================================================
// Function: ~CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStepOld>
// =================================================
void __thiscall
CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStepOld>::
~CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStepOld>
          (void *this,CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStepOld> *param_1)
{
{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,0x10,*(int *)((int)pvVar1 + -4),
               CGameCtnMenus::SFrameLadderRankingsStepOld::~SFrameLadderRankingsStepOld);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  return;
}
}

