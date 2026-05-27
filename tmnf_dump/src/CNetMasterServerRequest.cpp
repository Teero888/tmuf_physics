// Class implementation: CNetMasterServerRequest

// =================================================
// Function: CNetMasterServerRequest::Abort
// =================================================
void __thiscall
CNetMasterServerRequest::Abort(CNetMasterServerRequest *this,CNetMasterServerRequest *param_1)
{
{
  if (*(CNetHttpResult **)(this + 0x50) != (CNetHttpResult *)0x0) {
    CNetHttpResult::Cancel(*(CNetHttpResult **)(this + 0x50),(CNetHttpResult *)param_1);
    return;
  }
  return;
}
}

