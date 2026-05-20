// Class implementation: CDx9DeviceCaps

// =================================================
// Function: CDx9DeviceCaps::BeforeCreateDevice
// =================================================
void __thiscall
CDx9DeviceCaps::BeforeCreateDevice
          (CDx9DeviceCaps *this,CDx9DeviceCaps *param_1,IDirect3D9 *param_2,ulong param_3,
          _D3DDEVTYPE param_4)
{
{
  char cVar1;
  CDx9DeviceCaps CVar2;
  ulong uVar3;
  EDx9Vendor EVar4;
  DWORD DVar5;
  undefined4 *extraout_EAX;
  undefined4 *extraout_EAX_00;
  undefined4 *extraout_EAX_01;
  undefined4 *extraout_EAX_02;
  SStringParamInt *pSVar6;
  char *pcVar7;
  CDx9DeviceCaps *pCVar8;
  int iVar9;
  CDx9DeviceCaps *pCVar10;
  CDx9DeviceCaps *pCVar11;
  HWND in_stack_ffffff10;
  LPCWSTR in_stack_ffffff14;
  LPCWSTR in_stack_ffffff18;
  UINT in_stack_ffffff1c;
  SNationConfig *pSVar12;
  SHeaderCommunity *pSVar13;
  CFastString *pCVar14;
  SHeaderCommunity *pSVar15;
  SStringParam *pSVar16;
  SStringParam *pSVar17;
  wchar_t *pwVar18;
  SNationConfig *pSVar19;
  wchar_t *pwVar20;
  SNationConfig *pSVar21;
  wchar_t *pwVar22;
  SNationConfig *pSStack_98;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  SNationConfig aSStack_6c [8];
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 auStack_5c [2];
  SStringParamInt aSStack_54 [4];
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [12];
  undefined1 auStack_40 [4];
  CFastStringInt aCStack_3c [20];
  undefined1 auStack_28 [12];
  undefined1 auStack_1c [4];
  CFastStringInt aCStack_18 [20];
  
  pCVar8 = this + 0x14;
  (**(code **)(*(int *)param_1 + 0x14))();
  (**(code **)(*(int *)param_1 + 0x38))();
  uVar3 = *(ulong *)(this + 0x43c);
  pCVar10 = this + 0x464;
  pCVar11 = this + 0x594;
  for (iVar9 = 0x4c; iVar9 != 0; iVar9 = iVar9 + -1) {
    *(undefined4 *)pCVar11 = *(undefined4 *)pCVar10;
    pCVar10 = pCVar10 + 4;
    pCVar11 = pCVar11 + 4;
  }
  EVar4 = GetDx9VendorFromId(uVar3);
  *(EDx9Vendor *)(this + 0x460) = EVar4;
  if ((int)EVar4 < 0xc) {
    pSVar16 = (SStringParam *)0x982dfe;
    DVar5 = GetVersion();
    pwVar18 = (wchar_t *)PTR_DAT_00bbf7d8;
    pcVar7 = *(char **)(&DAT_00d779f0 + *(int *)(this + 0x460) * 0x18);
    iVar9 = *(int *)(this + 0x460) * 0x18;
    pSVar17 = *(SStringParam **)(&DAT_00d779f4 + iVar9);
    if ((((DAT_00cdae94 != 0) && ((~(DVar5 >> 0x1f) & 1) != 0)) &&
        (*(SStringParam **)(this + 0x438) <= pSVar17)) &&
       ((*(SStringParam **)(this + 0x438) < pSVar17 || (*(char **)(this + 0x434) < pcVar7)))) {
      pCVar14 = (CFastString *)&stack0xffffff58;
      CFastString_GetDriverVersion(pCVar14,(uint64 *)pSVar16);
      pSVar12 = (SNationConfig *)0x982e9b;
      CFastString_GetDriverVersion((CFastString *)&stack0xffffff50,(uint64 *)pCVar14);
      pwVar22 = (wchar_t *)PTR_DAT_00bbf7dc;
      pSVar13 = (SHeaderCommunity *)0x982eb8;
      SStringParam::SStringParam
                (&uStack_60,*(SStringParam **)(&DAT_00d779f8 + iVar9),(char *)pSVar16);
      pSVar15 = (SHeaderCommunity *)0x982ec9;
      CFastStringInt::CFastStringInt
                (aCStack_3c,(CFastStringInt *)auStack_5c,(SStringParam *)param_1);
      uStack_78 = extraout_EAX[1];
      uStack_74 = *extraout_EAX;
      pwVar20 = (wchar_t *)0x0;
      uStack_70 = 0;
      pSVar16 = (SStringParam *)0x982efb;
      CFastStringInt::CFastStringInt
                (auStack_40,(CFastStringInt *)&stack0xffffff44,(SStringParam *)param_2);
      uStack_80 = extraout_EAX_00[1];
      uStack_7c = *extraout_EAX_00;
      uStack_78 = 0;
      param_1 = (CDx9DeviceCaps *)0x982f2d;
      CFastStringInt::CFastStringInt
                (auStack_4c,(CFastStringInt *)&stack0xffffff50,(SStringParam *)param_3);
      uStack_64 = extraout_EAX_01[1];
      uStack_60 = *extraout_EAX_01;
      auStack_5c[0] = 0;
      SStringParam::SStringParam(auStack_40,(SStringParam *)(this + 0x214),pcVar7);
      CFastStringInt::CFastStringInt(aSStack_54,aCStack_3c,pSVar17);
      uStack_80 = extraout_EAX_02[1];
      uStack_7c = *extraout_EAX_02;
      uStack_78 = 0;
      pSVar6 = (SStringParamInt *)
               CClassicI18n::GetTranslatedStringInternal
                         ((CClassicI18n *)&DAT_00d71d10,
                          (CClassicI18n *)
                          L"Your video adapter\'s (%1) driver is old (%2).\nThis game works better with the %3 (or more recent) driver version.\n\na) If you\'ve a desktop computer,\n    You can find a recent graphic driver on the video card vendor page:\n%4\n\nb) If you\'ve a laptop computer,\n    You may check for an update on your laptop vendor page."
                          ,pwVar18);
      SStringParamInt::SStringParamInt(auStack_1c,pSVar6,pwVar20);
      pSVar21 = (SNationConfig *)&uStack_60;
      pSVar19 = aSStack_6c;
      CFastStringInt::SetCompose(&uStack_80,aCStack_18,(SStringParam *)&uStack_78,aSStack_54);
      CGameCtnApp::SNationConfig::~SNationConfig(auStack_50,pSVar19);
      CGameCtnApp::SNationConfig::~SNationConfig(aCStack_3c,pSVar21);
      CGameCtnApp::SNationConfig::~SNationConfig(auStack_28,(SNationConfig *)pCVar8);
      CGameCtnApp::SNationConfig::~SNationConfig(auStack_1c,pSStack_98);
      CClassicI18n::GetTranslatedStringInternal
                ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"Warning",pwVar22);
      MessageBoxW(in_stack_ffffff10,in_stack_ffffff14,in_stack_ffffff18,in_stack_ffffff1c);
      CGameCtnApp::SNationConfig::~SNationConfig(&stack0xffffff54,pSVar12);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xffffff48,pSVar13);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xffffff54,pSVar15);
    }
    pcVar7 = *(char **)(&DAT_00d779e8 + iVar9);
    if (pcVar7 == (char *)0x0) {
      CFastString::SetString
                ((CFastString *)&DAT_00d542c4,(CFastStringInt *)&stack0xffffff3c,pSVar16);
    }
    else {
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      CFastString::SetString
                ((CFastString *)&DAT_00d542c4,(CFastStringInt *)&stack0xffffff3c,pSVar16);
    }
  }
  DAT_00d542a0 = *(undefined4 *)(this + 0x43c);
  DAT_00d542a4 = *(undefined4 *)(this + 0x440);
  DAT_00d542a8 = *(undefined4 *)(this + 0x434);
  pCVar8 = this + 0x214;
  DAT_00d542ac = *(undefined4 *)(this + 0x438);
  if (pCVar8 != (CDx9DeviceCaps *)0x0) {
    do {
      CVar2 = *pCVar8;
      pCVar8 = pCVar8 + 1;
    } while (CVar2 != (CDx9DeviceCaps)0x0);
  }
  CFastString::SetString
            ((CFastString *)&DAT_00d542bc,(CFastStringInt *)&stack0xffffff40,(SStringParam *)param_1
            );
  DAT_00d542d8 = SaveDeviceCaps;
  return;
}
}

