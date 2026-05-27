// Class implementation: CNetConnection

// =================================================
// Function: CNetConnection::Disconnect
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CNetMasterServerRequest * __thiscall
CNetConnection::Disconnect(CNetConnection *this,CGameMasterServer *param_1)
{
{
  CNetConnection *this_00;
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong *puVar4;
  CNetMasterServerRequest *pCVar5;
  CNetMasterServerRequest *extraout_EAX;
  CNetMasterServerRequest *extraout_EAX_00;
  CNetTcpConnectedSocket *unaff_EBX;
  GmFrustumIso4 *unaff_EBP;
  CMwTimerAdapter *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CClassicLog *in_stack_00000014;
  
  iVar1 = *(int *)(this + 0x1c);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  *(undefined4 *)(this + 0x30) = 0;
  if ((((iVar1 == 0) || (iVar1 == 2)) || (iVar1 == 0x80)) || (iVar1 == 1)) {
    Close(this,(CClassicLog *)param_1);
    return extraout_EAX_00;
  }
  this_00 = this + 0x40;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this_00,pCVar6,(ulong)unaff_EBP);
      if (*(undefined4 **)pSVar3 != (undefined4 *)0x0) {
        unaff_EBP = (GmFrustumIso4 *)0x1;
        (**(code **)**(undefined4 **)pSVar3)();
      }
      pCVar6 = pCVar6 + 1;
    } while (pCVar6 < pCVar2);
  }
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_00,unaff_EBP);
  *(undefined4 *)(this + 0x1c) = 0x80;
  puVar4 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_ESI);
  *(ulong *)(this + 0x30) = *puVar4 + _DAT_00cdab8c;
  pCVar5 = (CNetMasterServerRequest *)CNetTcpConnectedSocket::Shutdown(this + 0x18,unaff_EBX);
  if (pCVar5 == (CNetMasterServerRequest *)0x0) {
    Close(this,in_stack_00000014);
    return extraout_EAX;
  }
  return pCVar5;
}
}

// =================================================
// Function: CNetConnection::GetConfig
// =================================================
SNetConfig * __thiscall CNetConnection::GetConfig(CNetConnection *this,CNetConnection *param_1)
{
{
  if (*(int *)(this + 0x9c) != 0) {
    return *(SNetConfig **)(*(int *)(this + 0xa0) + 0xa4);
  }
  return *(SNetConfig **)(*(int *)(this + 0xa4) + 0xd0);
}
}

// =================================================
// Function: CNetConnection::GetState
// =================================================
EState __thiscall CNetConnection::GetState(CNetConnection *this,CMwCmdFiber *param_1)
{
{
  switch(*(undefined4 *)(this + 0x1c)) {
  case 0:
  case 2:
  case 4:
  case 8:
  case 0x10:
  case 0x20:
    return 0;
  default:
    return 2;
  case 0x40:
    return 1;
  }
}
}

// =================================================
// Function: CNetConnection::Poll
// =================================================
void __thiscall CNetConnection::Poll(CNetConnection *this,CNetServer *param_1)
{
{
  int *piVar1;
  int iVar2;
  ulong *puVar3;
  SCasterCat *pSVar4;
  int iVar5;
  int extraout_EAX;
  EState EVar6;
  CNetTcpConnectedSocket *unaff_EBX;
  SShaderCustom *unaff_EBP;
  ulong unaff_ESI;
  CNetServer *unaff_EDI;
  SShaderCustom *unaff_retaddr;
  int in_stack_00000008;
  CNetServer *in_stack_0000000c;
  CNetNod *pCVar7;
  SShaderCustom *pSVar8;
  undefined4 *puVar9;
  CNetConnection *pCVar10;
  
  *(undefined4 *)(this + 0x20) = 0;
  if ((*(int *)(this + 0x1c) == 2) &&
     (pCVar10 = this, iVar2 = CNetTcpConnectedSocket::Writable(this + 0x18,unaff_EBX), iVar2 != 0))
  {
    *(undefined4 *)(this + 0x1c) = 4;
    puVar3 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),(CMwTimerAdapter *)pCVar10);
    *(ulong *)(this + 0x28) = *puVar3;
  }
  if (((byte)this[0x1c] & 0x7c) != 0) {
    pCVar10 = this + 0x40;
    iVar2 = CFastBuffer<class_CAudioSound*>::IsEmpty(pCVar10,unaff_EBP);
    if (iVar2 == 0) {
      iVar2 = *(int *)(this + 0x90);
      while (iVar2 == 0) {
        do {
          pSVar4 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                             (pCVar10,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              (ulong)unaff_EDI);
          piVar1 = *(int **)pSVar4;
          iVar2 = (**(code **)(*piVar1 + 0x18))();
          iVar5 = (**(code **)(*piVar1 + 0x14))();
          in_stack_0000000c = (CNetServer *)(iVar2 - iVar5);
          if ((CNetServer *)0x4000 < in_stack_0000000c) {
            in_stack_0000000c = (CNetServer *)0x4000;
          }
          puVar9 = &stack0x0000000c;
          pCVar7 = (CNetNod *)0x51f365;
          iVar2 = (**(code **)(*piVar1 + 0x14))();
          CNetTcpConnectedSocket::Send
                    (this + 0x18,(CNetConnectedClient *)(iVar2 + piVar1[3]),pCVar7);
          if (extraout_EAX == 2) goto LAB_0051f3eb;
          pSVar4 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                             (pCVar10,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              (ulong)puVar9);
          UpdateSendingInfo(this,in_stack_0000000c,1,*(EProtocol *)(pSVar4 + 8));
          unaff_EDI = in_stack_0000000c;
          (**(code **)(*piVar1 + 0x28))();
          iVar2 = (**(code **)(*piVar1 + 0x18))();
          iVar5 = (**(code **)(*piVar1 + 0x14))();
        } while (iVar5 != iVar2);
        UpdateSendingNodInfo(this,(CNetServer *)0x1,(EProtocol)unaff_EDI);
        pSVar8 = (SShaderCustom *)0x0;
        CFastBuffer<struct_CNetConnection::SEmmissionElem>::RemoveAt
                  (pCVar10,(CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)0x0,1,
                   unaff_ESI);
        unaff_ESI = 1;
        unaff_EDI = (CNetServer *)0x51f3d9;
        (**(code **)*piVar1)();
        iVar2 = CFastBuffer<class_CAudioSound*>::IsEmpty(pCVar10,pSVar8);
      }
    }
  }
LAB_0051f3eb:
  iVar2 = CFastBuffer<class_CAudioSound*>::IsEmpty(this + 0x40,unaff_retaddr);
  if (((iVar2 == 0) && (EVar6 = GetState(this,(CMwCmdFiber *)param_1), EVar6 != 2)) &&
     (*(int *)(this + 0x90) == 0)) {
    *(undefined4 *)(this + 0x24) = 1;
    CSceneMobil::VehicleBlockSpeed2Set
              ((CSceneMobil *)(this + 0x18),(CSceneMobil *)0x1,in_stack_00000008);
    return;
  }
  *(undefined4 *)(this + 0x24) = 0;
  CSceneMobil::VehicleBlockSpeed2Set
            ((CSceneMobil *)(this + 0x18),(CSceneMobil *)0x0,in_stack_00000008);
  return;
}
}

// =================================================
// Function: CNetConnection::Send
// =================================================
void __thiscall
CNetConnection::Send(CNetConnection *this,CNetConnectedClient *param_1,CNetNod *param_2)
{
{
  CNetNod *this_00;
  EState EVar1;
  int iVar2;
  SNetConfig *pSVar3;
  CNetNod *extraout_EAX;
  SNetConfig *pSVar4;
  CClassicBufferMemory *pCVar5;
  ulong *unaff_EBX;
  SNetConfig *unaff_ESI;
  CNetNod *pCVar6;
  CClassicBufferMemory *unaff_EDI;
  _func___cdecl_void_ulong *in_stack_0000000c;
  CClassicBufferMemory *in_stack_00000018;
  ulong uVar7;
  ulong *puVar8;
  CNetConnection *pCVar9;
  CClassicBufferMemory *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a93a1b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar9 = this;
  EVar1 = GetState(this,(CMwCmdFiber *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  this_00 = param_2;
  if ((EVar1 != 2) && (*(int *)(this + 0x90) == 0)) {
    iVar2 = (**(code **)(*(int *)param_2 + 0x78))();
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*(int *)this_00 + 0x10))(0x12010000);
      if ((iVar2 != 0) || (*(int *)(this + 0x88) != 0)) {
        CClassicBufferMemory::Empty(*(CClassicBufferMemory **)(this + 0x70),unaff_EDI);
        pSVar3 = GetConfig(this,this + 0xe4);
        CNetNod::DumpToBuffer
                  (this_00,*(CNetNod **)(this + 0x70),(CClassicBufferMemory *)pSVar3,unaff_ESI,
                   unaff_EBX);
        SendUDP(this,*(CNetConnection **)(this + 0x70),in_stack_00000018,
                (_func___cdecl_void_ulong *)pCVar9);
        ExceptionList = param_2;
        return;
      }
    }
    local_c = operator_new(0x20);
    if (local_c == (CClassicBufferMemory *)0x0) {
      pCVar6 = (CNetNod *)0x0;
    }
    else {
      CClassicBufferMemory::CClassicBufferMemory(local_c,unaff_EDI);
      pCVar6 = extraout_EAX;
    }
    param_2 = (CNetNod *)0x0;
    puVar8 = (ulong *)&DAT_00000004;
    pSVar3 = (SNetConfig *)&param_2;
    (**(code **)(*(int *)pCVar6 + 8))();
    pSVar4 = GetConfig(this,this + 0xec);
    CNetNod::DumpToBuffer(this_00,pCVar6,(CClassicBufferMemory *)pSVar4,pSVar3,puVar8);
    iVar2 = (**(code **)(*(int *)pCVar6 + 0x18))();
    **(int **)(pCVar6 + 0xc) = iVar2 + -4;
    uVar7 = 0x51fc03;
    pCVar5 = (CClassicBufferMemory *)(**(code **)(*(int *)this_00 + 0x84))();
    SendTCP(this,(CNetConnection *)pCVar6,pCVar5,uVar7,in_stack_0000000c);
  }
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CNetConnection::SendTCP
// =================================================
void __thiscall
CNetConnection::SendTCP
          (CNetConnection *this,CNetConnection *param_1,CClassicBufferMemory *param_2,ulong param_3,
          _func___cdecl_void_ulong *param_4)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<struct_CInputDevice::SRumble> *pCVar3;
  TiXmlAttribute *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CInputDevice::SRumble> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  GmFrustumIso4 *unaff_EDI;
  CNetConnection *this_00;
  uint in_stack_00000014;
  CNetConnection *pCVar6;
  
  pCVar6 = this;
  CClassicBufferMemory::Reset((CClassicBufferMemory *)param_1,unaff_EDI);
  this_00 = this + 0x40;
  pCVar4 = (CFastBuffer<struct_CInputDevice::SRumble> *)0xffffffff;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this_00,pCVar5,(ulong)unaff_EBP);
      if (pCVar5 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        *(undefined4 *)(pSVar2 + 4) = 0;
      }
      if (*(int *)(pSVar2 + 4) != 0) {
        *(int *)(pSVar2 + 4) = *(int *)(pSVar2 + 4) + -1;
      }
      if ((in_stack_00000014 < *(uint *)(pSVar2 + 4)) &&
         (pCVar4 == (CFastBuffer<struct_CInputDevice::SRumble> *)0xffffffff)) {
        pCVar4 = (CFastBuffer<struct_CInputDevice::SRumble> *)pCVar5;
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar1);
  }
  pCVar3 = (CFastBuffer<struct_CInputDevice::SRumble> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
  if (pCVar4 < pCVar3) {
    CFastBuffer<struct_CInputDevice::SRumble>::InsertElemAt
              (this_00,pCVar4,(ulong)&stack0x00000000,(SRumble *)unaff_EBX);
  }
  else {
    CFastBuffer<struct_CInputEventsStore::SCachedValue>::Add
              (this_00,(TiXmlAttributeSet *)&stack0x00000000,unaff_EBX);
  }
  CSceneMobil::VehicleBlockSpeed2Set((CSceneMobil *)(param_4 + 0x18),(CSceneMobil *)0x1,(int)pCVar6)
  ;
  return;
}
}

// =================================================
// Function: CNetConnection::SendUDP
// =================================================
void __thiscall
CNetConnection::SendUDP
          (CNetConnection *this,CNetConnection *param_1,CClassicBufferMemory *param_2,
          _func___cdecl_void_ulong *param_3)
{
{
  CNetUDP *pCVar1;
  ERetCode EVar2;
  CNetServer *pCVar3;
  EProtocol unaff_ESI;
  CClassicBufferMemory *unaff_EDI;
  ulong uVar4;
  
  if (*(int *)(this + 0x9c) == 0) {
    pCVar1 = (CNetUDP *)(*(int *)(this + 0xa0) + 0x44);
  }
  else {
    pCVar1 = (CNetUDP *)(*(int *)(this + 0xa4) + 0x5c);
  }
  EVar2 = CNetUDP::SendTo(this + 0x14,pCVar1,(CNetIPAddress *)param_1,unaff_EDI);
  uVar4 = 2;
  *(uint *)(this + 0x20) = (uint)(EVar2 == 2);
  pCVar3 = (CNetServer *)(**(code **)(*(int *)param_1 + 0x18))();
  UpdateSendingInfo(this,pCVar3,uVar4,(EProtocol)param_3);
  UpdateSendingNodInfo(this,(CNetServer *)0x2,unaff_ESI);
  return;
}
}

// =================================================
// Function: CNetConnection::UpdateSendingInfo
// =================================================
void __thiscall
CNetConnection::UpdateSendingInfo
          (CNetConnection *this,CNetServer *param_1,ulong param_2,EProtocol param_3)
{
{
  int *piVar1;
  
  *(int *)(this + 0xb4) = *(int *)(this + 0xb4) + 1;
  if (param_2 == 1) {
    *(int *)(this + 0xbc) = *(int *)(this + 0xbc) + 1;
  }
  else if (param_2 == 2) {
    *(int *)(this + 0xb8) = *(int *)(this + 0xb8) + 1;
  }
  if (*(int *)(this + 0x9c) == 0) {
    piVar1 = *(int **)(this + 0xa4);
  }
  else {
    piVar1 = *(int **)(this + 0xa0);
  }
  (**(code **)(*piVar1 + 0x7c))(param_1,param_2);
  if (param_1 != (CNetServer *)0x0) {
    (*(code *)param_1)(param_1);
  }
  return;
}
}

// =================================================
// Function: CNetConnection::UpdateSendingNodInfo
// =================================================
void __thiscall
CNetConnection::UpdateSendingNodInfo(CNetConnection *this,CNetServer *param_1,EProtocol param_2)
{
{
  *(int *)(this + 0xcc) = *(int *)(this + 0xcc) + 1;
  if (param_1 == (CNetServer *)0x1) {
    *(int *)(this + 0xd4) = *(int *)(this + 0xd4) + 1;
  }
  else if (param_1 == (CNetServer *)0x2) {
    *(int *)(this + 0xd0) = *(int *)(this + 0xd0) + 1;
  }
  if (*(int *)(this + 0x9c) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0051ef21. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0xa0) + 0x80))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0051ef31. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(this + 0xa4) + 0x80))();
  return;
}
}

