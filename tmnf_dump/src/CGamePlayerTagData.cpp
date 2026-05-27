// Class implementation: CGamePlayerTagData

// =================================================
// Function: CGamePlayerTagData::GetBitmap
// =================================================
CPlugBitmap * __thiscall
CGamePlayerTagData::GetBitmap(CGamePlayerTagData *this,CGamePlayerTagData *param_1)
{
{
  if (*(int *)(this + 0x14) != 0) {
    return *(CPlugBitmap **)(this + 0x14);
  }
  return DAT_00d691cc;
}
}

