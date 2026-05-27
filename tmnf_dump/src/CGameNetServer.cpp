// Class implementation: CGameNetServer

// =================================================
// Function: CGameNetServer::FindConnection
// =================================================
CNetConnectedClient * __thiscall
CGameNetServer::FindConnection(CGameNetServer *this,CGameNetServer *param_1,ulong param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xd4,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0xd4,pCVar3,unaff_ESI);
      if (*(byte *)(*(int *)(*(CNetConnectedClient **)pSVar2 + 0x10) + 4) == param_2) {
        return *(CNetConnectedClient **)pSVar2;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return (CNetConnectedClient *)0x0;
}
}

// =================================================
// Function: CGameNetServer::SendAll
// =================================================
void __thiscall
CGameNetServer::SendAll(CGameNetServer *this,CGameNetServer *param_1,CNetNod *param_2)
{
{
  undefined4 *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  EState EVar3;
  CNetNod *unaff_EBX;
  CNetConnectedClient *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  ulong unaff_EDI;
  CNetConnectedClient *in_stack_00000010;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x134,unaff_ESI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x134,pCVar4,unaff_EDI);
      this_00 = *(undefined4 **)pSVar2;
      unaff_EDI = 0x70e691;
      EVar3 = CNetConnection::GetState((CNetConnection *)*this_00,(CMwCmdFiber *)unaff_EBP);
      if (EVar3 == 1) {
        unaff_EDI = 0x70e6a2;
        unaff_EBP = in_stack_00000010;
        CNetConnectedClient::Send(this_00,in_stack_00000010,unaff_EBX);
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CGameNetServer::SendAllExcept
// =================================================
void __thiscall
CGameNetServer::SendAllExcept
          (CGameNetServer *this,CGameNetServer *param_1,CNetNod *param_2,
          CNetConnectedClient *param_3)
{
{
  undefined4 *this_00;
  CNetConnection *this_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  EState EVar3;
  CNetNod *unaff_EBX;
  CNetConnectedClient *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CNetConnectedClient *in_stack_00000010;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x134,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x134,pCVar4,unaff_ESI);
      this_00 = *(undefined4 **)pSVar2;
      this_01 = (CNetConnection *)*this_00;
      if (this_01 != *(CNetConnection **)param_3) {
        unaff_ESI = 0x70e6e6;
        EVar3 = CNetConnection::GetState(this_01,(CMwCmdFiber *)unaff_EBP);
        if (EVar3 == 1) {
          unaff_ESI = 0x70e6f7;
          unaff_EBP = in_stack_00000010;
          CNetConnectedClient::Send(this_00,in_stack_00000010,unaff_EBX);
        }
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return;
}
}

