// Class implementation: CNetServer

// =================================================
// Function: CNetServer::Disconnect
// =================================================
CNetMasterServerRequest * __thiscall
CNetServer::Disconnect(CNetServer *this,CGameMasterServer *param_1)
{
{
  CNetConnection *this_00;
  CNetMasterServerRequest *extraout_EAX;
  CNetMasterServerRequest *extraout_EAX_00;
  EState EVar1;
  CNetMasterServerRequest *pCVar2;
  CMwCmdFiber *unaff_ESI;
  SStringParam *unaff_EDI;
  undefined4 *in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  this_00 = *(CNetConnection **)param_1;
  if (*(int *)(this + 0x9c) == 0) {
    pCVar2 = *(CNetMasterServerRequest **)(this_00 + 0x1c);
    *(undefined4 *)(this_00 + 0x90) = 0;
    if ((pCVar2 != (CNetMasterServerRequest *)0x1) &&
       (pCVar2 != (CNetMasterServerRequest *)&DAT_00000080)) {
      EVar1 = CNetConnection::GetState(this_00,unaff_ESI);
      pCVar2 = CNetConnection::Disconnect(this_00,(CGameMasterServer *)unaff_EDI);
      if (EVar1 == 1) {
        pCVar2 = (CNetMasterServerRequest *)
                 (**(code **)(*(int *)this + 0x98))(in_stack_0000000c,in_stack_00000010);
      }
    }
    return pCVar2;
  }
  *(undefined4 *)(this_00 + 0x90) = 1;
  if (in_stack_00000008 != (undefined4 *)0x0) {
    puStack_8 = (undefined1 *)in_stack_00000008[1];
    uStack_4 = *in_stack_00000008;
    CFastString::SetString((CFastString *)(this_00 + 0x94),(CFastStringInt *)&puStack_8,unaff_EDI);
    return extraout_EAX;
  }
  puStack_8 = &DAT_00b2c878;
  uStack_4 = 0;
  CFastString::SetString((CFastString *)(this_00 + 0x94),(CFastStringInt *)&puStack_8,unaff_EDI);
  return extraout_EAX_00;
}
}

