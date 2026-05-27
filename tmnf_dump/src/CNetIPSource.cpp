// Class implementation: CNetIPSource

// =================================================
// Function: CNetIPSource::CanContact
// =================================================
int __thiscall CNetIPSource::CanContact(CNetIPSource *this,CNetIPSource *param_1)
{
{
  if (((*(int *)(this + 0x98) != 0) && (*(int *)(this + 0x9c) == 0)) &&
     (((DAT_00cd8f58 == 0 || (this[0xb0] == (CNetIPSource)0xff)) ||
      ((*(int *)(this + 0xa4) != 0 && (*(int *)(this + 0xa8) == 0)))))) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CNetIPSource::CanContactThroughServer
// =================================================
int __thiscall CNetIPSource::CanContactThroughServer(CNetIPSource *this,CNetIPSource *param_1)
{
{
  if (((DAT_00cd8f58 != 0) && (this[0xb0] != (CNetIPSource)0xff)) &&
     ((*(int *)(this + 0xa4) == 0 || (*(int *)(this + 0xa8) != 0)))) {
    return 1;
  }
  return 0;
}
}

