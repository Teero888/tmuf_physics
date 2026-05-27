// Class implementation: CGameManialinkEntry

// =================================================
// Function: CGameManialinkEntry::CGameManialinkEntry
// =================================================
void __thiscall
CGameManialinkEntry::CGameManialinkEntry(CGameManialinkEntry *this,CGameManialinkEntry *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined **)(this + 0x18) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined **)(this + 0x20) = PTR_DAT_00bbf7dc;
  *(undefined4 *)(this + 0x24) = 0;
  return;
}
}

