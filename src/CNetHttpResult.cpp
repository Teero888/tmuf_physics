// Class implementation: CNetHttpResult

// =================================================
// Function: CNetHttpResult::Cancel
// =================================================
void __thiscall CNetHttpResult::Cancel(CNetHttpResult *this,CNetHttpResult *param_1)
{
{
  CNetHttpResult *unaff_retaddr;
  
  *(undefined4 *)(this + 0x50) = 6;
  if (*(CNetHttpClient **)(this + 0x54) != (CNetHttpClient *)0x0) {
    CNetHttpClient::TerminateReq
              (*(CNetHttpClient **)(this + 0x54),(CNetHttpClient *)this,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CNetHttpResult::Pause
// =================================================
void __thiscall CNetHttpResult::Pause(CNetHttpResult *this,CGameCtnMediaTracker *param_1)
{
{
  CNetHttpResult *unaff_retaddr;
  
  *(undefined4 *)(this + 0x50) = 5;
  if (*(CNetHttpClient **)(this + 0x54) != (CNetHttpClient *)0x0) {
    CNetHttpClient::TerminateReq
              (*(CNetHttpClient **)(this + 0x54),(CNetHttpClient *)this,unaff_retaddr);
  }
  return;
}
}

