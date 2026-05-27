// Class implementation: CGbxGame

// =================================================
// Function: CGbxGame::CheckNetwork
// =================================================
int __thiscall CGbxGame::CheckNetwork(CGbxGame *this,CGbxGame *param_1)
{
{
  int extraout_EAX;
  SStringParamInt *pSVar1;
  undefined4 *extraout_EAX_00;
  undefined *puVar2;
  ulong uVar3;
  int iVar4;
  INT_PTR IVar5;
  SStringParam *unaff_EBX;
  ESpriteColor0 *unaff_EBP;
  CVisionViewportDx9 *unaff_ESI;
  uint uVar6;
  CPlugVisualSprite *unaff_EDI;
  undefined4 uStack00000024;
  void *pvStack00000030;
  SStringParam *in_stack_ffffff94;
  wchar_t *in_stack_ffffff98;
  wchar_t *in_stack_ffffff9c;
  SStringParam *in_stack_ffffffa0;
  SStringParam *in_stack_ffffffa4;
  wchar_t *in_stack_ffffffa8;
  wchar_t *in_stack_ffffffac;
  SStringParamInt *in_stack_ffffffb0;
  CSystemConfig *in_stack_ffffffb4;
  CSystemConfig *in_stack_ffffffb8;
  undefined1 local_44 [8];
  char *local_3c;
  DWORD local_38;
  undefined4 local_34;
  undefined *local_30;
  undefined *local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  int local_18;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a80928;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CNetSystem::Init(this,(CLoadGeomDynaSprite *)(DAT_00cca150 ^ (uint)&stack0xffffff84),unaff_EDI,
                   unaff_ESI,unaff_EBP);
  if ((extraout_EAX == 0) || (*(int *)(this + 0x30) == 0)) {
    ExceptionList = param_1;
    return 0;
  }
  local_34 = *(undefined4 *)(this + 0x7c);
  local_38 = *(DWORD *)(this + 0x80);
  local_30 = (undefined *)0x0;
  CFastStringInt::SetString(&DAT_00d53730,(CFastStringInt *)&local_38,unaff_EBX);
  local_24 = 1;
  local_20 = 1;
  local_28 = &DAT_00b2bf78;
  CFastStringInt::Concat(&DAT_00d53730,(CFastStringInt *)&local_28,in_stack_ffffff94);
  pSVar1 = (SStringParamInt *)
           CClassicI18n::GetTranslatedStringInternal
                     ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"Network check",
                      in_stack_ffffff98);
  SStringParamInt::SStringParamInt(&local_8,pSVar1,in_stack_ffffff9c);
  CFastStringInt::Concat(&DAT_00d53730,(CFastStringInt *)&local_4,in_stack_ffffffa0);
  local_3c = "TmForever";
  local_38 = 9;
  CFastStringInt::CFastStringInt(local_44,(CFastStringInt *)&local_3c,in_stack_ffffffa4);
  local_8 = (undefined1 *)extraout_EAX_00[1];
  local_4 = *extraout_EAX_00;
  uStack00000024 = 0;
  pSVar1 = (SStringParamInt *)
           CClassicI18n::GetTranslatedStringInternal
                     ((CClassicI18n *)&DAT_00d71d10,
                      (CClassicI18n *)
                      L"%1 allows you to create internet games and exchange data with other players (peer to peer).\nWe\'re now checking your network connection, so that you can configure your firewall."
                      ,in_stack_ffffffa8);
  SStringParamInt::SStringParamInt(&stack0x00000014,pSVar1,in_stack_ffffffac);
  CFastStringInt::SetCompose
            (&DAT_00d53738,(CFastStringInt *)&stack0x00000018,(SStringParam *)&stack0x00000000,
             in_stack_ffffffb0);
  pvStack00000030 = (void *)0xffffffff;
  if (local_30 != PTR_DAT_00bbf7dc) {
    if ((local_30[-1] & 0x80) == 0) {
      puVar2 = local_30 + -2;
    }
    else {
      puVar2 = local_30 + -4;
    }
    operator_delete__(puVar2);
    local_34 = 0;
    local_30 = PTR_DAT_00bbf7dc;
  }
  CClassicI18n::ConvertStringForWin32((CFastStringInt *)&DAT_00d53738);
  DAT_00d53720 = 0;
  DAT_00d53724 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,ThreadFuncListenSocket,
                              *(LPVOID *)(this + 0x30),0,(LPDWORD)0x0);
  CMwProfiler::GetTimeStamp((int64 *)&local_1c);
  local_38 = 0x103;
  do {
    WaitForSingleObjectEx(DAT_00d53724,500,0);
    GetExitCodeThread(DAT_00d53724,&local_38);
    CMwProfiler::GetTimeStamp((int64 *)&local_24);
    uVar3 = CMwProfiler::GetTimeFromDeltaTimeStamp
                      (CONCAT44((local_20 - local_18) - (uint)(local_24 < local_1c),
                                local_24 - local_1c));
    if (0x5dc < uVar3) {
      if ((local_38 == 0x103) && (DAT_00d53720 != 0)) {
        WaitForSingleObjectEx(DAT_00d53724,500,0);
        GetExitCodeThread(DAT_00d53724,&local_38);
        if (local_38 == 0x103) {
          TerminateThread(DAT_00d53724,0);
          local_38 = 0;
        }
      }
      break;
    }
  } while (local_38 == 0x103);
  uVar6 = 1;
  if ((local_38 == 0x103) ||
     (iVar4 = CSystemConfig::GetNetworkIsFireWallTested
                        (*(CSystemConfig **)(this + 0x30),in_stack_ffffffb4), iVar4 == 0)) {
    IVar5 = DialogBoxParamW(*(HINSTANCE *)(this + 0x2c),(LPCWSTR)0x66,*(HWND *)(this + 0x50),
                            DialogProc_WaitForSocket,0);
    uVar6 = (uint)(IVar5 == 1);
    if (local_38 == 0x103) {
      WaitForSingleObjectEx(DAT_00d53724,500,0);
      GetExitCodeThread(DAT_00d53724,&local_38);
      if (local_38 == 0x103) {
        TerminateThread(DAT_00d53724,0);
      }
    }
    iVar4 = CSystemConfig::GetNetworkIsFireWallTested
                      (*(CSystemConfig **)(this + 0x30),in_stack_ffffffb4);
    if (iVar4 == 0) {
      CSystemConfig::SetNetworkIsFireWallTested(*(CSystemConfig **)(this + 0x30),in_stack_ffffffb8);
      CSystemArchiveNod::Save(*(CMwNod **)(this + 0x30),8,1);
    }
  }
  CloseHandle(DAT_00d53724);
  DAT_00d53724 = (HANDLE)0x0;
  ExceptionList = pvStack00000030;
  return uVar6;
}
}

// =================================================
// Function: CGbxGame::Init
// =================================================
void __thiscall
CGbxGame::Init(CGbxGame *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2,
              CVisionViewportDx9 *param_3,ESpriteColor0 *param_4)
{
{
  CPlugFileGpuBuilder *pCVar1;
  int extraout_EAX;
  SCasterCat *pSVar2;
  CTrackManiaEngine *this_00;
  CMwEngine *extraout_EAX_00;
  wchar_t *lpText;
  int iVar3;
  CPlugFileGpuBuilder *unaff_ESI;
  SStringParam *unaff_EDI;
  CMwEngine *this_01;
  CVisionViewportDx9 *unaff_retaddr;
  wchar_t *in_stack_00000014;
  CMwEngine *in_stack_00000018;
  UINT uType;
  void *in_stack_00000038;
  void *in_stack_0000003c;
  void *in_stack_00000040;
  CPlugFileGpuBuilder *pCVar4;
  char *pcVar5;
  CPlugFileGpuBuilder *pCVar6;
  LPCSTR *ppCVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  CPlugFileGpuBuilder *in_stack_fffffff0;
  char *pcVar11;
  CLoadGeomDynaSprite *pCVar12;
  CPlugVisualSprite *pCVar13;
  
  pCVar13 = (CPlugVisualSprite *)0xffffffff;
  pCVar12 = (CLoadGeomDynaSprite *)&LAB_00a8095b;
  pcVar8 = "2010-03-15";
  pcVar11 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  CFastString::SetString
            ((CFastString *)&DAT_00d54348,(CFastStringInt *)&stack0xffffffe4,
             (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffdc));
  pcVar9 = "2.11.26";
  pcVar10 = &DAT_00000007;
  CFastString::SetString((CFastString *)&DAT_00d54340,(CFastStringInt *)&stack0xffffffe8,unaff_EDI);
  if (DAT_00d71e54 != 0) {
    DAT_00d71e54 = 0;
    *DAT_00d71e58 = 0;
  }
  ppCVar7 = &lpOutputString_00b2bcc4;
  pCVar6 = (CPlugFileGpuBuilder *)&DAT_00b2c020;
  pcVar5 = &DAT_00d54348;
  pCVar4 = (CPlugFileGpuBuilder *)&DAT_00b2c01c;
  pCVar1 = CFastString::operator<<
                     ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"Starting ",
                      (char *)&DAT_00d54310);
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,pCVar4,pcVar5);
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,pCVar6,(char *)ppCVar7);
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,unaff_ESI,pcVar8);
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,(CPlugFileGpuBuilder *)pcVar9,pcVar10);
  CFastString::operator<<((CFastString *)pCVar1,in_stack_fffffff0,pcVar11);
  CClassicLog::ConsoleAddLogString(4,(CFastString *)&DAT_00d71e54);
  CGbxApp::Init((CGbxApp *)this,pCVar12,pCVar13,unaff_retaddr,(ESpriteColor0 *)param_1);
  if (extraout_EAX != 0) {
    this_00 = DAT_00d5431c;
    uType = DAT_00d54318;
    CFastStringInt::SetString
              (this + 0x7c,(CFastStringInt *)&stack0x0000001c,(SStringParam *)param_2);
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (DAT_00d73300 + 0x20,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x24,
                        (ulong)param_3);
    if (*(int *)pSVar2 == 0) {
      this_00 = operator_new(0x20);
      if (this_00 == (CTrackManiaEngine *)0x0) {
        this_01 = (CMwEngine *)0x0;
      }
      else {
        CTrackManiaEngine::CTrackManiaEngine(this_00,(CTrackManiaEngine *)param_4);
        this_01 = extraout_EAX_00;
      }
      in_stack_00000038 = (void *)0xffffffff;
      *(undefined4 *)(this_01 + 0x14) = 0x24000000;
      CMwEngine::AllocateGroups(this_01,(CMwEngine *)in_stack_00000014);
      CMwEngineMain::AddEngine
                (DAT_00d73300,(CMwEngineMain *)0x24000000,(ulong)this_01,in_stack_00000018);
    }
    if ((*(int *)(this + 0x100) != 0) || (DAT_00d54240 == 0)) goto LAB_00402399;
    if (*(int *)(*(int *)(this + 0x30) + 0xb0) == 0) {
      in_stack_00000014 = *(wchar_t **)(this + 0x80);
      in_stack_00000018 = (CMwEngine *)0x0;
    }
    else {
      if (*(int *)(*(int *)(this + 0x30) + 0xb4) == 0) {
LAB_00402399:
        iVar3 = (**(code **)(*(int *)this + 0x90))();
        if (iVar3 == 0) {
          CheckNetwork(this,(CGbxGame *)this_00);
          ExceptionList = in_stack_0000003c;
          return;
        }
        ExceptionList = in_stack_00000038;
        return;
      }
      iVar3 = CClassicI18n::IsLatinCharsInCurCatalog
                        ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)0x0,(ulong)this_00);
      if (iVar3 == 0) goto LAB_00402399;
      in_stack_00000018 = *(CMwEngine **)(this + 0x80);
      this_00 = (CTrackManiaEngine *)0x0;
      in_stack_00000014 = L"Bad language file";
    }
    lpText = CClassicI18n::GetTranslatedStringInternal
                       ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)in_stack_00000014,
                        (wchar_t *)in_stack_00000018);
    MessageBoxW((HWND)0x0,lpText,(LPCWSTR)this_00,uType);
  }
  ExceptionList = in_stack_00000040;
  return;
}
}

// =================================================
// Function: CGbxGame::IsForceWindowed
// =================================================
int __thiscall CGbxGame::IsForceWindowed(CGbxGame *this,CGbxGame *param_1)
{
{
  if ((((*(int *)(this + 0x100) == 0) || (*(int *)(this + 0x104) != 0)) ||
      (*(int *)(this + 0x10c) != 0)) && (*(int *)(this + 0x11c) == 0)) {
    return (uint)(*(int *)(this + 0x3c) != 0);
  }
  return 1;
}
}

