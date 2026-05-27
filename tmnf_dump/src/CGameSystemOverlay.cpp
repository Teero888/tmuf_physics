// Class implementation: CGameSystemOverlay

// =================================================
// Function: CGameSystemOverlay::ToolBarSetForceOpen
// =================================================
void __thiscall
CGameSystemOverlay::ToolBarSetForceOpen
          (CGameSystemOverlay *this,CGameSystemOverlay *param_1,int param_2,EForceOpen param_3)
{
{
  if (param_1 != (CGameSystemOverlay *)0x0) {
    *(uint *)(this + 0x38) = *(uint *)(this + 0x38) | param_2;
    return;
  }
  *(uint *)(this + 0x38) = *(uint *)(this + 0x38) & ~param_2;
  return;
}
}

