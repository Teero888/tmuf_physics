// Class implementation: CGameCtnMenus_SFrameLadderRankingsStepOld

// =================================================
// Function: CGameCtnMenus::SFrameLadderRankingsStepOld::~SFrameLadderRankingsStepOld
// =================================================
void __thiscall
CGameCtnMenus::SFrameLadderRankingsStepOld::~SFrameLadderRankingsStepOld
          (void *this,SFrameLadderRankingsStepOld *param_1)
{
{
  undefined *puVar1;
  
  puVar1 = *(undefined **)((int)this + 0xc);
  if (puVar1 != PTR_DAT_00bbf7dc) {
    if ((puVar1[-1] & 0x80) == 0) {
      puVar1 = puVar1 + -2;
    }
    else {
      puVar1 = puVar1 + -4;
    }
    operator_delete__(puVar1);
    *(undefined4 *)((int)this + 8) = 0;
    *(undefined **)((int)this + 0xc) = PTR_DAT_00bbf7dc;
  }
  return;
}
}

