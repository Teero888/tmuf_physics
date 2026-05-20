// Class implementation: CGameCtnGhost

// =================================================
// Function: CGameCtnGhost::CanValidate
// =================================================
int __thiscall
CGameCtnGhost::CanValidate
          (CGameCtnGhost *this,CGameCtnGhost *param_1,CGameApp *param_2,CFastStringInt *param_3)
{
{
  wchar_t wVar1;
  SStringParam *pSVar2;
  undefined4 *extraout_EAX;
  undefined4 *extraout_EAX_00;
  undefined *puVar3;
  SStringParam *unaff_ESI;
  undefined4 unaff_retaddr;
  void *in_stack_00000014;
  wchar_t *pwVar4;
  undefined4 local_58;
  undefined *local_54;
  undefined *local_50;
  undefined1 local_4c [4];
  undefined *local_48;
  wchar_t *local_44;
  undefined *local_40;
  undefined *local_3c;
  undefined *local_38 [4];
  undefined *local_28;
  wchar_t *local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18 [2];
  undefined4 local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  puVar3 = PTR_DAT_00bbf7d8;
  local_8 = &LAB_00aa1dd0;
  local_c = ExceptionList;
  pSVar2 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffff9c);
  if (*(EReplayGhostVersion *)(this + 0x100) != DAT_00cec200) {
    local_58 = 0;
    local_54 = PTR_DAT_00bbf7d8;
    pwVar4 = (wchar_t *)0x0;
    local_4 = 1;
    ExceptionList = &local_c;
    CGameCtnReplayRecord::GetVersionString
              (*(EReplayGhostVersion *)(this + 0x100),(CFastString *)&local_58);
    CGameCtnReplayRecord::GetVersionString(DAT_00cec200,(CFastString *)&stack0xffffffa0);
    local_48 = puVar3;
    local_44 = pwVar4;
    CFastStringInt::CFastStringInt(local_38,(CFastStringInt *)&local_48,pSVar2);
    local_20 = extraout_EAX[1];
    local_1c = *extraout_EAX;
    local_38[0] = local_54;
    local_18[0] = 0;
    local_3c = local_50;
    CFastStringInt::CFastStringInt(local_4c,(CFastStringInt *)&local_3c,unaff_ESI);
    local_10 = extraout_EAX_00[1];
    local_c = (void *)*extraout_EAX_00;
    local_8 = (undefined1 *)0x0;
    local_24 = CClassicI18n::GetTranslatedStringInternal
                         ((CClassicI18n *)&DAT_00d71d10,
                          (CClassicI18n *)
                          L"Replay version: %1\nis not compatible with the current\ngame version: %2."
                          ,pwVar4);
    if (local_24 == (wchar_t *)0x0) {
      local_20 = 0;
    }
    else {
      pwVar4 = local_24;
      do {
        wVar1 = *pwVar4;
        pwVar4 = pwVar4 + 1;
      } while (wVar1 != L'\0');
      local_20 = (int)pwVar4 - (int)(local_24 + 1) >> 1;
    }
    local_1c = 1;
    CFastStringInt::SetCompose
              (in_stack_00000014,(CFastStringInt *)&local_24,(SStringParam *)&local_c,
               (SStringParamInt *)local_18);
    if (local_40 != PTR_DAT_00bbf7dc) {
      if ((local_40[-1] & 0x80) == 0) {
        local_40 = local_40 + -2;
      }
      else {
        local_40 = local_40 + -4;
      }
      operator_delete__(local_40);
      local_44 = (wchar_t *)0x0;
      local_40 = PTR_DAT_00bbf7dc;
    }
    if (local_28 != PTR_DAT_00bbf7dc) {
      if ((local_28[-1] & 0x80) == 0) {
        local_28 = local_28 + -2;
      }
      else {
        local_28 = local_28 + -4;
      }
      operator_delete__(local_28);
    }
    if (local_50 != PTR_DAT_00bbf7d8) {
      puVar3 = local_50 + -1;
      if ((local_50[-1] & 0x80) != 0) {
        puVar3 = local_50 + -4;
      }
      operator_delete__(puVar3);
      local_54 = (undefined *)0x0;
      local_50 = PTR_DAT_00bbf7d8;
    }
    if (local_48 != PTR_DAT_00bbf7d8) {
      puVar3 = local_48 + -1;
      if ((local_48[-1] & 0x80) != 0) {
        puVar3 = local_48 + -4;
      }
      operator_delete__(puVar3);
    }
    ExceptionList = (void *)CONCAT31((int3)((uint)unaff_retaddr >> 8),2);
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CGameCtnGhost::IsSameSystem
// =================================================
int __thiscall
CGameCtnGhost::IsSameSystem(CGameCtnGhost *this,CGameCtnGhost *param_1,CFastStringInt *param_2)
{
{
  CFastStringInt::SetString
            (param_1,(CFastStringInt *)&stack0xfffffff8,(SStringParam *)&DAT_00b2c878);
  return 1;
}
}

// =================================================
// Function: CGameCtnGhost::SetContextSettings
// =================================================
void __thiscall
CGameCtnGhost::SetContextSettings(CGameCtnGhost *this,CGameCtnGhost *param_1,CFastString *param_2)
{
{
  CFastString::SetString
            ((CFastString *)(this + 0x168),(CFastStringInt *)&stack0xfffffff8,
             *(SStringParam **)(param_1 + 4));
  return;
}
}

// =================================================
// Function: CGameCtnGhost::SetRaceTime
// =================================================
void __thiscall
CGameCtnGhost::SetRaceTime
          (CGameCtnGhost *this,CGameCtnGhost *param_1,ulong param_2,ulong param_3,ulong param_4)
{
{
  *(CGameCtnGhost **)(this + 0xe8) = param_1;
  *(ulong *)(this + 0xec) = param_2;
  *(ulong *)(this + 0xf0) = param_3;
  return;
}
}

