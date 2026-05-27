// Class implementation: CGamePlayerInfo

// =================================================
// Function: CGamePlayerInfo::CGamePlayerInfo
// =================================================
void __thiscall CGamePlayerInfo::CGamePlayerInfo(CGamePlayerInfo *this,CGamePlayerInfo *param_1)
{
{
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBX;
  SSystemTime *unaff_EBP;
  SLadderStats *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  undefined1 uStack00000008;
  void *in_stack_00000014;
  undefined1 uStack00000018;
  CGamePlayerInfo *pCVar1;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffffe8;
  CGameScoresVersion *in_stack_ffffffec;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00aa0ad8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CGameNetPlayerInfo::CGameNetPlayerInfo
            ((CGameNetPlayerInfo *)this,
             (CGameNetPlayerInfo *)(DAT_00cca150 ^ (uint)&stack0xffffffd4));
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x178,unaff_EDI);
  *(undefined4 *)(this + 0x184) = 0;
  *(undefined **)(this + 0x188) = PTR_DAT_00bbf7dc;
  CGameMasterServer::SLadderStats::SLadderStats(this + 0x1a0,unaff_ESI);
  local_c = (void *)0x3f800000;
  *(undefined4 *)(this + 0x1dc) = 0;
  *(undefined4 *)(this + 0x1e4) = 0x3f800000;
  local_8 = (undefined1 *)0x0;
  local_4 = 0;
  *(undefined4 *)(this + 0x1e0) = 0;
  *(undefined4 *)(this + 0x1e8) = 0;
  *(undefined4 *)(this + 0x1ec) = 0;
  *(undefined4 *)(this + 0x1f0) = 0;
  *(undefined4 *)(this + 500) = 0;
  *(undefined **)(this + 0x1f8) = PTR_DAT_00bbf7dc;
  uStack00000008 = 4;
  SSystemTime::SSystemTime(this + 0x1fc,unaff_EBP);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x208,unaff_EBX);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x214,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x220,in_stack_ffffffe8);
  *(undefined4 *)(this + 0x22c) = 0;
  *(undefined **)(this + 0x230) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x234) = 0;
  *(undefined4 *)(this + 0x1b4) = 0;
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0x1cc) = 0;
  uStack00000018 = 8;
  *(undefined4 *)(this + 0x238) = 0;
  *(undefined4 *)(this + 0x1ac) = 0;
  *(undefined4 *)(this + 0x1b0) = 0xffffffff;
  *(undefined4 *)(this + 0x1a0) = 0;
  *(undefined4 *)(this + 0x1a4) = 0;
  *(undefined4 *)(this + 0x1a8) = 0;
  *(undefined4 *)(this + 0x1c4) = 0;
  *(undefined4 *)(this + 0x1c8) = 0xffffffff;
  *(CGamePlayerInfo **)(this + 0x1d0) = this;
  *(undefined4 *)(this + 0x204) = 0;
  SSystemTime::SetInvalid(this + 0x1fc,in_stack_ffffffec);
  CSystemPackDesc::SetChecksumNull((SNat128 *)(this + 400));
  ExceptionList = in_stack_00000014;
  return;
}
}

// =================================================
// Function: CGamePlayerInfo::PlayerTags_IsLoaded
// =================================================
int __thiscall CGamePlayerInfo::PlayerTags_IsLoaded(CGamePlayerInfo *this,CGamePlayerInfo *param_1)
{
{
  int iVar1;
  SShaderCustom *unaff_retaddr;
  
  iVar1 = CFastBuffer<class_CAudioSound*>::IsEmpty(this + 0x208,unaff_retaddr);
  return (uint)(iVar1 == 0);
}
}

