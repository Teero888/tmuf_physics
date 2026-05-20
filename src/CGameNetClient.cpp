// Class implementation: CGameNetClient

// =================================================
// Function: CGameNetClient::IsConnected
// =================================================
int __thiscall CGameNetClient::IsConnected(CGameNetClient *this,CCrystalVertex *param_1)
{
{
  EState EVar1;
  CMwCmdFiber *unaff_retaddr;
  
  if (*(CNetConnection **)(this + 0x15c) != (CNetConnection *)0x0) {
    EVar1 = CNetConnection::GetState(*(CNetConnection **)(this + 0x15c),unaff_retaddr);
    if (EVar1 == 1) {
      return 1;
    }
  }
  return 0;
}
}

