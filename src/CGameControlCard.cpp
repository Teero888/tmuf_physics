// Class implementation: CGameControlCard

// =================================================
// Function: CGameControlCard::CardSetReadOnly
// =================================================
void __thiscall
CGameControlCard::CardSetReadOnly(CGameControlCard *this,CGameControlCard *param_1,int param_2)
{
{
  *(CGameControlCard **)(this + 0x1c8) = param_1;
  *(uint *)(this + 0xfc) =
       *(uint *)(this + 0xfc) ^
       ((uint)(param_1 != (CGameControlCard *)0x0) * 2 ^ *(uint *)(this + 0xfc)) & 2;
  if (*(int *)(this + 0x1bc) != 0) {
    *(uint *)(*(int *)(this + 0x1bc) + 0x134) = (uint)(param_1 != (CGameControlCard *)0x0);
    (**(code **)(**(int **)(this + 0x1bc) + 0x1a8))();
  }
  return;
}
}

// =================================================
// Function: CGameControlCard::ForceReconfig
// =================================================
void __thiscall CGameControlCard::ForceReconfig(CGameControlCard *this,CGameControlCard *param_1)
{
{
  (**(code **)(*(int *)this + 0x178))();
  (**(code **)(*(int *)this + 0x254))(*(undefined4 *)(this + 0x17c));
  return;
}
}

