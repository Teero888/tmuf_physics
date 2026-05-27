// Class implementation: CGamePlayer

// =================================================
// Function: CGamePlayer::CGamePlayer
// =================================================
void __thiscall CGamePlayer::CGamePlayer(CGamePlayer *this,CGamePlayer *param_1)
{
{
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CGameNod *unaff_EDI;
  
  CGameNod::CGameNod((CGameNod *)this,unaff_EDI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined **)(this + 0x34) = PTR_DAT_00bbf7dc;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x38,unaff_ESI);
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  this[0x2c] = (CGamePlayer)0xff;
  *(undefined4 *)(this + 0x48) = 0xffffffff;
  return;
}
}

// =================================================
// Function: CGamePlayer::GetMwClassId
// =================================================
ulong __thiscall CGamePlayer::GetMwClassId(CGamePlayer *this,CControlStyle *param_1)
{
{
  return 0x3002000;
}
}

// =================================================
// Function: CGamePlayer::IsLocalPlayer
// =================================================
int __thiscall CGamePlayer::IsLocalPlayer(CGamePlayer *this,CGamePlayer *param_1)
{
{
  return (uint)(*(int *)(*(int *)(this + 0x1c) + 0x148) == 0);
}
}

// =================================================
// Function: CGamePlayer::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CGamePlayer::MwGetClassInfo(CGamePlayer *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d694b8;
}
}

// =================================================
// Function: CGamePlayer::MwIsKindOf
// =================================================
int __thiscall CGamePlayer::MwIsKindOf(CGamePlayer *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if ((param_1 != (CMwCmdAffectParam *)0x3002000) && (param_1 != (CMwCmdAffectParam *)0x3008000)) {
    return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
  }
  return 1;
}
}

// =================================================
// Function: CGamePlayer::MwNewCGamePlayer
// =================================================
CMwNod * __cdecl CGamePlayer::MwNewCGamePlayer(void)
{
{
  CGamePlayer *pCVar1;
  CMwNod *extraout_EAX;
  CGamePlayer *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00aa222b;
  local_c = ExceptionList;
  pCVar1 = (CGamePlayer *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x4c);
  local_4 = 0;
  if (local_10 != (CGamePlayer *)0x0) {
    CGamePlayer(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CGamePlayer::SetControlPlayer
// =================================================
void __thiscall
CGamePlayer::SetControlPlayer(CGamePlayer *this,CGamePlayer *param_1,CGameControlPlayer *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != (CGamePlayer *)0x0) {
    *(CGamePlayer **)(param_1 + 0x28) = this;
  }
  if (param_1 != *(CGamePlayer **)(this + 0x24)) {
    if (param_1 != (CGamePlayer *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x24) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x24),unaff_ESI);
    }
    *(CGamePlayer **)(this + 0x24) = param_1;
  }
  return;
}
}

// =================================================
// Function: CGamePlayer::SetName
// =================================================
void __thiscall CGamePlayer::SetName(CGamePlayer *this,CGameBuddy *param_1,CFastStringInt *param_2)
{
{
  CFastStringInt::SetString
            (this + 0x30,(CFastStringInt *)&stack0xfffffff4,*(SStringParam **)(param_1 + 4));
  return;
}
}

// =================================================
// Function: CGamePlayer::SetPlayerInfo
// =================================================
void __thiscall
CGamePlayer::SetPlayerInfo(CGamePlayer *this,CGamePlayer *param_1,CGamePlayerInfo *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x1c);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x238) != 0)) {
    *(undefined4 *)(iVar1 + 0x238) = 0;
  }
  *(CGamePlayer **)(this + 0x1c) = param_1;
  if (param_1 != (CGamePlayer *)0x0) {
    *(CGamePlayer **)(param_1 + 0x238) = this;
  }
  return;
}
}

// =================================================
// Function: CGamePlayer::UpdatePlayer
// =================================================
void __thiscall CGamePlayer::UpdatePlayer(CGamePlayer *this,CGamePlayer *param_1,ulong param_2)
{
{
  if (*(int **)(this + 0x24) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e2faf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0x24) + 0x80))();
    return;
  }
  return;
}
}

// =================================================
// Function: CGamePlayer::UpdatePlayerAsync
// =================================================
void __thiscall CGamePlayer::UpdatePlayerAsync(CGamePlayer *this,CGamePlayer *param_1,ulong param_2)
{
{
  if (*(int **)(this + 0x24) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e2fcf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0x24) + 0x84))();
    return;
  }
  return;
}
}

// =================================================
// Function: CGamePlayer::_vector_deleting_destructor_
// =================================================
void * __thiscall
CGamePlayer::_vector_deleting_destructor_(CGamePlayer *this,CRpcCallInternal *param_1,uint param_2)
{
{
  CGamePlayer *unaff_ESI;
  
  ~CGamePlayer(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CGamePlayer::~CGamePlayer
// =================================================
void __thiscall CGamePlayer::~CGamePlayer(CGamePlayer *this,CGamePlayer *param_1)
{
{
  CGamePlayerInfo *pCVar1;
  undefined *puVar2;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_ESI;
  CGamePlayer *pCVar3;
  CGameNod *pCVar4;
  
  pCVar4 = ExceptionList;
  pCVar1 = (CGamePlayerInfo *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &stack0xfffffff4;
  *(undefined ***)this = vftable;
  pCVar3 = this;
  SetPlayerInfo(this,(CGamePlayer *)0x0,pCVar1);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x38,unaff_ESI);
  puVar2 = *(undefined **)(this + 0x34);
  if (puVar2 != PTR_DAT_00bbf7dc) {
    if ((puVar2[-1] & 0x80) == 0) {
      puVar2 = puVar2 + -2;
    }
    else {
      puVar2 = puVar2 + -4;
    }
    operator_delete__(puVar2);
    *(undefined4 *)(this + 0x30) = 0;
    *(undefined **)(this + 0x34) = PTR_DAT_00bbf7dc;
  }
  if (*(CMwNod **)(this + 0x28) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x28),(CMwNod *)pCVar3);
  }
  if (*(CMwNod **)(this + 0x24) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x24),(CMwNod *)pCVar4);
  }
  if (*(CMwNod **)(this + 0x20) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x20),(CMwNod *)pCVar4);
  }
  CGameNod::~CGameNod((CGameNod *)this,pCVar4);
  ExceptionList = param_1;
  return;
}
}

