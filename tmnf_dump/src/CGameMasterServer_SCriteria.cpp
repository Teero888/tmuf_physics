// Class implementation: CGameMasterServer_SCriteria

// =================================================
// Function: CGameMasterServer::SCriteria::~SCriteria
// =================================================
void __thiscall CGameMasterServer::SCriteria::~SCriteria(void *this,SCriteria *param_1)
{
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = *(undefined **)((int)this + 0xc);
  if (puVar1 != PTR_DAT_00bbf7d8) {
    puVar2 = puVar1 + -1;
    if ((puVar1[-1] & 0x80) != 0) {
      puVar2 = puVar1 + -4;
    }
    operator_delete__(puVar2);
    *(undefined4 *)((int)this + 8) = 0;
    *(undefined **)((int)this + 0xc) = PTR_DAT_00bbf7d8;
  }
  return;
}
}

