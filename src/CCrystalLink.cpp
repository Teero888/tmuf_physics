// Class implementation: CCrystalLink

// =================================================
// Function: CCrystalLink::Disable
// =================================================
void __thiscall CCrystalLink::Disable(CCrystalLink *this,CCrystalLink *param_1)
{
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (*(int *)(this + 0xc) != 0) {
    uVar3 = 0;
    if (*(int *)(this + 0x4c) != 0) {
      iVar4 = 0;
      do {
        iVar1 = *(int *)(*(int *)(this + 0x44) + uVar3 * 4);
        iVar2 = *(int *)(this + 0x48) + iVar4;
        *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(*(int *)(this + 0x48) + iVar4);
        *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 4);
        uVar3 = uVar3 + 1;
        iVar4 = iVar4 + 0xc;
        *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar2 + 8);
      } while (uVar3 < *(uint *)(this + 0x4c));
    }
    operator_delete__(*(void **)(this + 0x48));
    *(undefined4 *)(this + 0x48) = 0;
    *(undefined4 *)(this + 0xc) = 0;
    *(uint *)(*(int *)(this + 4) + 4) = *(uint *)(*(int *)(this + 4) + 4) | 8;
  }
  return;
}
}

