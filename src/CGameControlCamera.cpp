// Class implementation: CGameControlCamera

// =================================================
// Function: CGameControlCamera::GetGameCamVal
// =================================================
void __thiscall
CGameControlCamera::GetGameCamVal
          (CGameControlCamera *this,CGameControlCamera *param_1,SGameCamVal *param_2)
{
{
  (**(code **)(*(int *)this + 0x78))(param_1);
  (**(code **)(*(int *)this + 0x84))(param_1 + 0x44);
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(this + 0x14);
  if (*(int *)(this + 0x18) != 0) {
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(this + 0xb4);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(this + 0xb4);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(this + 0x1c);
    return;
  }
  *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(this + 0xb4);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(this + 0x1c);
  return;
}
}

// =================================================
// Function: CGameControlCamera::SetFollowedGameMobilId
// =================================================
void __thiscall
CGameControlCamera::SetFollowedGameMobilId
          (CGameControlCamera *this,CGameControlCamera *param_1,ulong param_2)
{
{
  *(CGameControlCamera **)(this + 0xb4) = param_1;
  return;
}
}

