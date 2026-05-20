// Class implementation: CNetConnectedClient

// =================================================
// Function: CNetConnectedClient::Poll
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall CNetConnectedClient::Poll(void *this,CNetServer *param_1)
{
{
  int iVar1;
  void *local_94;
  undefined1 *puStack_90;
  undefined4 local_8c;
  undefined1 local_88 [128];
  CNetServer *local_8;
  
  puStack_90 = &LAB_00a944eb;
  local_94 = ExceptionList;
  local_8 = (CNetServer *)(DAT_00cca150 ^ (uint)local_88);
  ExceptionList = &local_94;
  if (((*(int *)(*(int *)this + 0x90) == 0) && (iVar1 = *(int *)(*(int *)this + 0x1c), iVar1 != 1))
     && (iVar1 != 0x80)) {
    local_8c = 0;
    CNetConnection::Poll(*(CNetConnection **)this,local_8);
  }
  ExceptionList = local_94;
  return;
}
}

// =================================================
// Function: CNetConnectedClient::Send
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall CNetConnectedClient::Send(void *this,CNetConnectedClient *param_1,CNetNod *param_2)
{
{
  CNetConnection *this_00;
  EState EVar1;
  int iVar2;
  ulong uVar3;
  CMwTimer *unaff_EDI;
  float fVar4;
  void *local_94;
  undefined1 *puStack_90;
  undefined4 local_8c;
  undefined1 local_88 [128];
  CMwCmdFiber *local_8;
  
  local_8c = 0xffffffff;
  puStack_90 = &LAB_00a9444b;
  local_94 = ExceptionList;
  local_8 = (CMwCmdFiber *)(DAT_00cca150 ^ (uint)local_88);
  ExceptionList = &local_94;
  this_00 = *(CNetConnection **)this;
  if (((this_00 != (CNetConnection *)0x0) && (*(int *)(this_00 + 0x90) == 0)) &&
     (EVar1 = CNetConnection::GetState(this_00,local_8), EVar1 != 2)) {
    iVar2 = (**(code **)(*(int *)param_1 + 0x10))();
    if (iVar2 != 0) {
      if (*(uint *)((int)this + 0xc) <= *(uint *)(*(int *)(*(int *)this + 0xa4) + 0x120)) {
        ExceptionList = local_94;
        return;
      }
      uVar3 = CMwTimer::GetElapsedTimeSinceInit((void *)(DAT_00d731e0 + 0x70),unaff_EDI);
      if (*(int *)((int)this + 0xc) + 5000U <= uVar3) {
        ExceptionList = local_94;
        return;
      }
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)((int)this + 4);
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)((int)this + 8);
      uVar3 = GetGlobalTime();
      *(ulong *)(param_1 + 0x24) = uVar3;
      fVar4 = GetGlobalTimeSpeed();
      *(float *)(param_1 + 0x28) = fVar4;
      if (*(uint *)(param_1 + 0x24) < *(uint *)(param_1 + 0x20)) {
        ExceptionList = local_94;
        return;
      }
    }
    local_8c = 0;
    CNetConnection::Send(*(CNetConnection **)this,param_1,(CNetNod *)0x0);
  }
  ExceptionList = local_94;
  return;
}
}

