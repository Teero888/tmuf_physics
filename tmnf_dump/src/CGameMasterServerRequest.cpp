// Class implementation: CGameMasterServerRequest

// =================================================
// Function: CGameMasterServerRequest::SetRequestFailureCallBack
// =================================================
void __thiscall
CGameMasterServerRequest::SetRequestFailureCallBack
          (CGameMasterServerRequest *this,CGameMasterServerRequest *param_1,CMwNod *param_2,
          _func___cdecl_void_CGameMasterServerRequest_ptr *param_3)
{
{
  *(CGameMasterServerRequest **)(this + 0x60) = param_1;
  *(CMwNod **)(this + 100) = param_2;
  return;
}
}

// =================================================
// Function: CGameMasterServerRequest::SetRequestSuccessCallBack
// =================================================
void __thiscall
CGameMasterServerRequest::SetRequestSuccessCallBack
          (CGameMasterServerRequest *this,CGameMasterServerRequest *param_1,CMwNod *param_2,
          _func___cdecl_void_CGameMasterServerRequest_ptr *param_3)
{
{
  *(CGameMasterServerRequest **)(this + 0x58) = param_1;
  *(CMwNod **)(this + 0x5c) = param_2;
  return;
}
}

