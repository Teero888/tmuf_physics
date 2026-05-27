// Class implementation: CGameControlCameraFree

// =================================================
// Function: CGameControlCameraFree::SetKeysAction
// =================================================
void __thiscall
CGameControlCameraFree::SetKeysAction
          (CGameControlCameraFree *this,CGameControlCameraFree *param_1,SInputActionDesc *param_2,
          SInputActionDesc *param_3,SInputActionDesc *param_4,SInputActionDesc *param_5,
          SInputActionDesc *param_6,SInputActionDesc *param_7,SInputActionDesc *param_8)
{
{
  *(CGameControlCameraFree **)(this + 0x1c8) = param_1;
  *(SInputActionDesc **)(this + 0x1cc) = param_2;
  *(SInputActionDesc **)(this + 0x1d0) = param_3;
  *(SInputActionDesc **)(this + 0x1d4) = param_4;
  *(SInputActionDesc **)(this + 0x1d8) = param_5;
  *(SInputActionDesc **)(this + 0x1dc) = param_6;
  *(SInputActionDesc **)(this + 0x1e0) = param_7;
  return;
}
}

