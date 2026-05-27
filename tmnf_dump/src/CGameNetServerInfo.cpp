// Class implementation: CGameNetServerInfo

// =================================================
// Function: CGameNetServerInfo::SetReloadNeeded
// =================================================
void __thiscall
CGameNetServerInfo::SetReloadNeeded
          (CGameNetServerInfo *this,CGameNetServerInfo *param_1,EReload param_2)
{
{
  if (*(int *)(this + 0xb4) < (int)param_1) {
    *(CGameNetServerInfo **)(this + 0xb4) = param_1;
  }
  return;
}
}

