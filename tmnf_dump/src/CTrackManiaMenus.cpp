// Class implementation: CTrackManiaMenus

// =================================================
// Function: CTrackManiaMenus::DialogInGameMenu_OnRetire
// =================================================
void __thiscall
CTrackManiaMenus::DialogInGameMenu_OnRetire(CTrackManiaMenus *this,CTrackManiaMenus *param_1)
{
{
  *(undefined4 *)(this + 0x700) = 0x56;
  return;
}
}

// =================================================
// Function: CTrackManiaMenus::MenuCreateChallenge_OnAdvanced
// =================================================
void __thiscall
CTrackManiaMenus::MenuCreateChallenge_OnAdvanced(CTrackManiaMenus *this,CTrackManiaMenus *param_1)
{
{
  CGameManialinkBrowser *this_00;
  COalAudioPort *unaff_ESI;
  int unaff_retaddr;
  CTrackManiaMenus *in_stack_0000000c;
  
  this_00 = CGameApp::GetManialinkBrowser(*(CGameApp **)(this + 0x784),(CGameApp *)0x1);
  CGameManialinkBrowser::SetIsEnabled(this_00,unaff_ESI,unaff_retaddr);
  *(undefined4 *)(*(int *)(this + 0x784) + 0x4b0) = 0;
  MenuCreateChallenge_OnOk(this,in_stack_0000000c);
  return;
}
}

// =================================================
// Function: CTrackManiaMenus::MenuCreateChallenge_OnOk
// =================================================
void __thiscall
CTrackManiaMenus::MenuCreateChallenge_OnOk(CTrackManiaMenus *this,CTrackManiaMenus *param_1)
{
{
  EChallengeType unaff_ESI;
  
  CTrackMania::SetChallengeType
            (*(CTrackMania **)(this + 0x784),(CTrackMania *)&DAT_00000004,unaff_ESI);
  *(undefined4 *)(*(int *)(this + 0x784) + 0x4a8) = 0;
  *(undefined4 *)(this + 0x704) = 2;
  return;
}
}

// =================================================
// Function: CTrackManiaMenus::MenuEditors_OnLoadChallenge_OnAdvanced
// =================================================
void __thiscall
CTrackManiaMenus::MenuEditors_OnLoadChallenge_OnAdvanced
          (CTrackManiaMenus *this,CTrackManiaMenus *param_1)
{
{
  *(undefined4 *)(*(int *)(this + 0x784) + 0x4b0) = 0;
  MenuEditors_OnLoadChallenge_OnOk(this,param_1);
  return;
}
}

// =================================================
// Function: CTrackManiaMenus::MenuEditors_OnLoadChallenge_OnOk
// =================================================
void __thiscall
CTrackManiaMenus::MenuEditors_OnLoadChallenge_OnOk(CTrackManiaMenus *this,CTrackManiaMenus *param_1)
{
{
  *(undefined4 *)(this + 0x7c) = 6;
  MenuPlayChallenge_Edit(this,param_1);
  return;
}
}

// =================================================
// Function: CTrackManiaMenus::MenuMultiPlayerNetworkCreate_OnAdvanced
// =================================================
void __thiscall
CTrackManiaMenus::MenuMultiPlayerNetworkCreate_OnAdvanced
          (CTrackManiaMenus *this,CTrackManiaMenus *param_1)
{
{
  CTrackMania *this_00;
  int iVar1;
  CTrackManiaPlayerProfile *pCVar2;
  CTrackMania *unaff_ESI;
  CTrackMania *unaff_EDI;
  CTrackManiaMenus *in_stack_0000000c;
  
  this_00 = *(CTrackMania **)(this + 0x784);
  pCVar2 = CTrackMania::GetTMCurrentProfile(this_00,unaff_EDI);
  iVar1 = *(int *)(pCVar2 + 0x1e0);
  pCVar2 = CTrackMania::GetTMCurrentProfile(this_00,unaff_ESI);
  *(uint *)(pCVar2 + 0x1e0) = (uint)(iVar1 == 0);
  MenuMultiPlayerNetworkCreate_RefreshDisplay(this,in_stack_0000000c);
  return;
}
}

// =================================================
// Function: CTrackManiaMenus::MenuMultiPlayerNetworkCreate_RefreshDisplay
// =================================================
void __thiscall
CTrackManiaMenus::MenuMultiPlayerNetworkCreate_RefreshDisplay
          (CTrackManiaMenus *this,CTrackManiaMenus *param_1)
{
{
  CMwId CVar1;
  undefined3 extraout_var;
  CMotionPlayer *pCVar2;
  int iVar3;
  CTrackManiaPlayerProfile *pCVar4;
  void *this_00;
  void *this_01;
  void *this_02;
  void *this_03;
  void *this_04;
  void *this_05;
  void *this_06;
  void *this_07;
  void *this_08;
  void *this_09;
  void *this_10;
  void *this_11;
  void *this_12;
  void *this_13;
  void *this_14;
  void *this_15;
  void *this_16;
  void *this_17;
  void *this_18;
  void *this_19;
  void *this_20;
  void *this_21;
  void *this_22;
  void *this_23;
  void *this_24;
  void *this_25;
  void *this_26;
  void *this_27;
  void *this_28;
  void *this_29;
  void *this_30;
  void *this_31;
  void *this_32;
  void *this_33;
  void *this_34;
  void *this_35;
  void *this_36;
  void *this_37;
  void *this_38;
  void *this_39;
  void *this_40;
  void *this_41;
  void *this_42;
  void *this_43;
  void *this_44;
  void *this_45;
  void *this_46;
  void *this_47;
  void *this_48;
  void *this_49;
  void *this_50;
  void *this_51;
  void *this_52;
  CGameNetwork *unaff_EBP;
  CFastStringInt *unaff_ESI;
  CMwId *unaff_EDI;
  char *pcStack0000001c;
  char *pcStack0000002c;
  char *pcStack00000058;
  void *in_stack_0000006c;
  undefined4 uStack00000074;
  int in_stack_0000007c;
  void *in_stack_00000088;
  int in_stack_00000094;
  CTrackManiaMenus *pCStack00000098;
  char *pcStack0000009c;
  void *in_stack_000000a0;
  void *in_stack_000000a4;
  int in_stack_000000b0;
  int in_stack_000000d4;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  ExceptionList = &stack0xfffffff4;
  CTrackManiaNetwork::GetServerInfo
            (*(CTrackManiaNetwork **)(this + 0x840),
             (CTrackManiaNetwork *)(DAT_00cca150 ^ (uint)&stack0xffffffbc));
  CVar1 = CMwId::CreateFromLocalName(&stack0xfffffff4);
  pCVar2 = CFastBuffer<class_CMotionPlayer*>::GetNodFromId
                     ((void *)(*(int *)(this + 0x788) + 0x68),
                      (CFastBuffer<class_CMotionPlayer*> *)CONCAT31(extraout_var,CVar1),unaff_EDI);
  OnAccessViolation_ConcatToCrashFileName(unaff_ESI);
  if ((pCVar2 != (CMotionPlayer *)0x0) &&
     (iVar3 = (**(code **)(*(int *)pCVar2 + 0x108))(), iVar3 != 0)) {
    pCVar4 = CTrackMania::GetTMCurrentProfile
                       (*(CTrackMania **)(this + 0x784),(CTrackMania *)unaff_ESI);
    iVar3 = *(int *)(pCVar4 + 0x1e0);
    CGameNetwork::IsInternet(*(CGameNetwork **)(this + 0x840),unaff_EBP);
    CControlTools::Connect(this_00,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_01,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_02,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_03,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_04,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_05,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_06,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_07,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_08,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_09,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_10,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_11,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_12,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_13,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_14,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_15,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_16,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_17,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_18,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_19,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_20,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(*(void **)(this + 0x840),(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_21,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_22,(CCrystalEdge *)pCVar2);
    pcStack0000001c = (char *)(uint)(iVar3 == 0);
    CControlTools::Connect(this_23,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_24,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_25,(CCrystalEdge *)pCVar2);
    pcStack0000002c = (char *)0x0;
    pcStack0000001c = "ButtonAllowDownload";
    CControlTools::Connect(this_26,(CCrystalEdge *)pCVar2);
    local_4 = (void *)0x46e011;
    CControlTools::Connect(this_27,(CCrystalEdge *)pCVar2);
    pcStack0000002c = "ServerInfo.NextEswcCupWarmUpDuration";
    if (in_stack_0000006c == (void *)0x0) {
      pcStack0000002c = "ServerInfo.NextAllWarmUpDuration";
    }
    pcStack0000001c = (char *)0x46e037;
    CControlTools::Connect(this_28,(CCrystalEdge *)pCVar2);
    pcStack0000002c = (char *)0x0;
    CControlTools::Connect(this_29,(CCrystalEdge *)pCVar2);
    pcStack0000002c = "ButtonRoundUseNewRules";
    CControlTools::Connect(this_30,(CCrystalEdge *)pCVar2);
    pcStack0000001c = &DAT_00b2c878;
    CControlTools::Connect(this_31,(CCrystalEdge *)pCVar2);
    pcStack0000002c = (char *)0x46e0e6;
    CControlTools::Connect(in_stack_0000006c,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_32,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_33,(CCrystalEdge *)pCVar2);
    pcStack0000002c = &DAT_00b2c878;
    pcStack0000001c = (char *)0x46e16b;
    CControlTools::Connect(this_34,(CCrystalEdge *)pCVar2);
    pcStack00000058 = (char *)0x0;
    CControlTools::Connect(in_stack_00000088,(CCrystalEdge *)pCVar2);
    pcStack00000058 = (char *)0x0;
    CControlTools::Connect(this_35,(CCrystalEdge *)pCVar2);
    if ((iVar3 == 0) || (in_stack_0000007c == 0)) {
      pcStack00000058 = (char *)0x1;
    }
    else {
      pcStack00000058 = (char *)0x0;
    }
    CControlTools::Connect(this_36,(CCrystalEdge *)pCVar2);
    pcStack00000058 = &DAT_00b2c878;
    CControlTools::Connect(this_37,(CCrystalEdge *)pCVar2);
    pcStack00000058 = (char *)this;
    CControlTools::Connect(this_38,(CCrystalEdge *)pCVar2);
    pcStack0000009c = (char *)(uint)(in_stack_00000094 == 0);
    CControlTools::Connect(this_39,(CCrystalEdge *)pCVar2);
    pcStack0000002c = "ServerInfo.NextLapsNbLaps";
    pcStack0000001c = (char *)0x46e2a9;
    CControlTools::Connect(in_stack_000000a0,(CCrystalEdge *)pCVar2);
    uStack00000074 = 0;
    pcStack00000058 = (char *)0x46e2d7;
    CControlTools::Connect(this_40,(CCrystalEdge *)pCVar2);
    uStack00000074 = 0;
    CControlTools::Connect(this_41,(CCrystalEdge *)pCVar2);
    pcStack00000058 = (char *)(uint)(in_stack_000000b0 == 0);
    pCStack00000098 = (CTrackManiaMenus *)pcStack00000058;
    CControlTools::Connect(this_42,(CCrystalEdge *)pCVar2);
    pcStack0000002c = (char *)0x46e342;
    CControlTools::Connect(this_43,(CCrystalEdge *)pCVar2);
    uStack00000074 = 0;
    CControlTools::Connect(this_44,(CCrystalEdge *)pCVar2);
    pcStack00000058 = "EntryEswcCupRoundsPerChallenge";
    CControlTools::Connect(in_stack_000000a4,(CCrystalEdge *)pCVar2);
    CControlTools::Connect(this_45,(CCrystalEdge *)pCVar2);
    uStack00000074 = 0x46e3b2;
    CControlTools::Connect(this_46,(CCrystalEdge *)pCVar2);
    uStack00000074 = 0;
    CControlTools::Connect(this_47,(CCrystalEdge *)pCVar2);
    pcStack00000058 = (char *)(uint)(iVar3 == 0);
    CControlTools::Connect(this_48,(CCrystalEdge *)pCVar2);
    pcStack0000009c = (char *)0x0;
    pCStack00000098 = (CTrackManiaMenus *)0x0;
    CControlTools::Connect(this_49,(CCrystalEdge *)pCVar2);
    if ((iVar3 == 0) || (in_stack_000000d4 == 0)) {
      pCStack00000098 = (CTrackManiaMenus *)0x1;
    }
    else {
      pCStack00000098 = (CTrackManiaMenus *)0x0;
    }
    pcStack0000009c = (char *)0x0;
    CControlTools::Connect(this_50,(CCrystalEdge *)pCVar2);
    if ((iVar3 == 0) || (in_stack_000000d4 == 0)) {
      pcStack0000009c = (char *)0x1;
    }
    else {
      pcStack0000009c = (char *)0x0;
    }
    pCStack00000098 = (CTrackManiaMenus *)&DAT_00b2c878;
    CControlTools::Connect(this_51,(CCrystalEdge *)pCVar2);
    pcStack0000009c = "ServerInfo.ValidationMode";
    pCStack00000098 = this;
    CControlTools::Connect(this_52,(CCrystalEdge *)pCVar2);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CTrackManiaMenus::MenuPlayChallenge_Edit
// =================================================
void __thiscall
CTrackManiaMenus::MenuPlayChallenge_Edit(CTrackManiaMenus *this,CTrackManiaMenus *param_1)
{
{
  int iVar1;
  undefined *puVar2;
  EChallengeType unaff_ESI;
  undefined4 uStack00000010;
  char *pcVar3;
  CGameApp *pCVar4;
  char *in_stack_ffffffec;
  void *pvVar5;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a8e5e0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pcVar3 = "Challenges\\My Challenges\\";
  pCVar4 = (CGameApp *)0x19;
  CFastStringInt::SetString
            (this + 0x1a0,(CFastStringInt *)&stack0xffffffe4,
             (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  *(undefined4 *)(*(int *)(this + 0x784) + 0x4a8) = 0;
  CTrackMania::SetChallengeType
            (*(CTrackMania **)(this + 0x784),(CTrackMania *)&DAT_00000004,unaff_ESI);
  CGameCtnMenus::MenuChooseChallenge_ResetCurrentSelection
            ((CGameCtnMenus *)this,(CGameCtnMenus *)pcVar3);
  iVar1 = CGameApp::IsPayingSolo(*(CGameApp **)(this + 0x784),pCVar4);
  if (iVar1 == 0) {
    CFastString::CFastString((CFastString *)&local_4,(CFastString *)&DAT_00b2c878,in_stack_ffffffec)
    ;
    pvVar5 = (void *)0x0;
    uStack00000010 = 1;
    (**(code **)(*(int *)this + 0x20c))(0,&DAT_00b48470,&DAT_00b48468);
  }
  else {
    CFastString::CFastString((CFastString *)&local_c,(CFastString *)&DAT_00b2c878,in_stack_ffffffec)
    ;
    pvVar5 = (void *)0x0;
    register0x00000010 = (BADSPACEBASE *)0x0;
    uStack00000010 = 0;
    (**(code **)(*(int *)this + 0x20c))(0,&DAT_00b48470,&DAT_00b48480);
  }
  if ((undefined *)register0x00000010 != PTR_DAT_00bbf7d8) {
    puVar2 = (undefined *)((int)register0x00000010 + -1);
    if ((*(byte *)((int)register0x00000010 + -1) & 0x80) != 0) {
      puVar2 = (undefined *)((int)register0x00000010 + -4);
    }
    operator_delete__(puVar2);
  }
  ExceptionList = pvVar5;
  return;
}
}

