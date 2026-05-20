// Class implementation: CGameMasterServer_SLadderStats

// =================================================
// Function: CGameMasterServer::SLadderStats::SLadderStats
// =================================================
void __thiscall CGameMasterServer::SLadderStats::SLadderStats(void *this,SLadderStats *param_1)
{
{
  SSystemTime *pSVar1;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00aa07fb;
  local_c = ExceptionList;
  pSVar1 = (SSystemTime *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined **)((int)this + 0x20) = PTR_DAT_00bbf7dc;
  local_4 = 0;
  SSystemTime::SSystemTime((void *)((int)this + 0x34),pSVar1);
  ExceptionList = local_8;
  return;
}
}

