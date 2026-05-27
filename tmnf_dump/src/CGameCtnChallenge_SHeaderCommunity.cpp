// Class implementation: CGameCtnChallenge_SHeaderCommunity

// =================================================
// Function: CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
// =================================================
void __thiscall
CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(void *this,SHeaderCommunity *param_1)
{
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = *(undefined **)((int)this + 4);
  if (puVar1 != PTR_DAT_00bbf7d8) {
    puVar2 = puVar1 + -1;
    if ((puVar1[-1] & 0x80) != 0) {
      puVar2 = puVar1 + -4;
    }
    operator_delete__(puVar2);
    *(undefined4 *)this = 0;
    *(undefined **)((int)this + 4) = PTR_DAT_00bbf7d8;
  }
  return;
}
}

