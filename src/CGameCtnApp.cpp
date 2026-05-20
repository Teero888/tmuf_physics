// Class implementation: CGameCtnApp

// =================================================
// Function: CGameCtnApp::Advertising_SetZone
// =================================================
void __thiscall
CGameCtnApp::Advertising_SetZone
          (CGameCtnApp *this,CGameCtnApp *param_1,CGameCtnChallenge *param_2,int param_3)
{
{
  CFastString CVar1;
  CFastString CVar2;
  CFastString CVar3;
  CGameCtnChallenge *pCVar4;
  SGameCtnIdentifier *pSVar5;
  CGameNetwork *this_00;
  int iVar6;
  CFastString *pCVar7;
  SCasterCat *pSVar8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined1 *puVar9;
  undefined *puVar10;
  int *this_01;
  char *unaff_EBX;
  char *unaff_ESI;
  char *unaff_EDI;
  undefined1 uStack00000010;
  undefined *in_stack_00000020;
  void *in_stack_00000028;
  undefined1 uStack0000002c;
  char *in_stack_ffffff74;
  char *in_stack_ffffff78;
  char *in_stack_ffffff7c;
  CFastString *in_stack_ffffff80;
  SHeaderCommunity *in_stack_ffffff84;
  SHeaderCommunity *in_stack_ffffff88;
  SHeaderCommunity *in_stack_ffffff8c;
  SHeaderCommunity *in_stack_ffffff90;
  CCrystalVertex *in_stack_ffffff94;
  SStringParam *in_stack_ffffff98;
  SHeaderCommunity *in_stack_ffffff9c;
  CFastString *pCVar11;
  ulong uVar12;
  undefined4 local_54;
  CFastString *local_50;
  CFastString local_4c [4];
  CFastString *local_48;
  CFastString local_44 [4];
  int local_40;
  int local_3c;
  CFastString local_38 [4];
  undefined4 local_34;
  undefined *local_30;
  undefined4 local_2c;
  undefined *local_28;
  undefined4 local_24;
  undefined *local_20;
  CFastString local_1c [4];
  undefined *local_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  undefined *local_8;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00aa3ea8;
  local_14 = ExceptionList;
  pCVar4 = (CGameCtnChallenge *)(DAT_00cca150 ^ (uint)&stack0xffffff68);
  ExceptionList = &local_14;
  if (*(int *)(this + 0x210) == 0) {
    ExceptionList = in_stack_00000028;
    return;
  }
  if (param_1 == (CGameCtnApp *)0x0) {
    if (param_2 == (CGameCtnChallenge *)0x0) {
      CFastString::CFastString((CFastString *)&local_20,(CFastString *)&DAT_00b2c878,(char *)pCVar4)
      ;
      local_8 = (undefined *)0xe;
      CFastString::CFastString((CFastString *)&local_24,(CFastString *)&DAT_00b2c878,unaff_EDI);
      CFastString::CFastString((CFastString *)&local_28,(CFastString *)&DAT_00b2c878,unaff_ESI);
      CFastString::CFastString((CFastString *)&local_2c,(CFastString *)&DAT_00b2c878,unaff_EBX);
      CFastString::CFastString
                ((CFastString *)&local_30,(CFastString *)&DAT_00b2c878,in_stack_ffffff74);
      CFastString::CFastString
                ((CFastString *)&stack0xffffff8c,(CFastString *)&DAT_00b2c878,in_stack_ffffff78);
      param_3 = CONCAT31(param_3._1_3_,0x13);
      CFastString::CFastString
                ((CFastString *)&stack0xffffff98,(CFastString *)&DAT_00b2c878,in_stack_ffffff7c);
      uStack00000010 = 0x14;
      CGameAdvertising::SetAdvertisingZone
                (*(CGameAdvertising **)(this + 0x210),(CGameAdvertising *)&stack0xffffff9c,
                 (CFastString *)&stack0xffffff94,(CFastString *)&local_24,local_1c,
                 (CFastString *)&local_14,(CFastString *)&local_c,(CFastString *)&stack0xfffffffc,
                 in_stack_ffffff80);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xffffffa0,in_stack_ffffff84);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xffffff9c,in_stack_ffffff88);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_18,in_stack_ffffff8c);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_c,in_stack_ffffff90);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                (&stack0x00000000,(SHeaderCommunity *)in_stack_ffffff94);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                (&param_3,(SHeaderCommunity *)in_stack_ffffff98);
      this_01 = (int *)&stack0x00000018;
    }
    else {
      CFastString::CFastString
                ((CFastString *)&stack0xffffff88,(CFastString *)&DAT_00b2c878,(char *)pCVar4);
      local_8 = (undefined *)0x7;
      CFastString::CFastString
                ((CFastString *)&stack0xffffff94,(CFastString *)&DAT_00b2c878,unaff_EDI);
      CFastString::CFastString
                ((CFastString *)&stack0xffffffa0,(CFastString *)&DAT_00b2c878,unaff_ESI);
      CFastString::CFastString((CFastString *)&local_54,(CFastString *)&DAT_00b2c878,unaff_EBX);
      CFastString::CFastString
                ((CFastString *)&local_48,(CFastString *)&DAT_00b2c878,in_stack_ffffff74);
      CFastString::CFastString
                ((CFastString *)&local_3c,(CFastString *)&DAT_00b2c878,in_stack_ffffff78);
      param_3 = CONCAT31(param_3._1_3_,0xc);
      CFastString::CFastString((CFastString *)&local_30,(CFastString *)"Menus",in_stack_ffffff7c);
      uStack00000010 = 0xd;
      CGameAdvertising::SetAdvertisingZone
                (*(CGameAdvertising **)(this + 0x210),(CGameAdvertising *)&local_2c,
                 (CFastString *)&local_34,(CFastString *)&local_3c,local_44,local_4c,
                 (CFastString *)&local_54,(CFastString *)&stack0xffffffa4,in_stack_ffffff80);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_28,in_stack_ffffff84);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_2c,in_stack_ffffff88);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_30,in_stack_ffffff8c);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_34,in_stack_ffffff90);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                (local_38,(SHeaderCommunity *)in_stack_ffffff94);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                (&local_3c,(SHeaderCommunity *)in_stack_ffffff98);
      this_01 = &local_40;
    }
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(this_01,in_stack_ffffff9c);
    ExceptionList = in_stack_00000028;
    return;
  }
  pSVar5 = CGameCtnChallenge::GetVehicleIdent((CGameCtnChallenge *)param_1,pCVar4);
  local_54 = 0;
  local_50 = (CFastString *)PTR_DAT_00bbf7dc;
  uVar12 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetVehicleDisplayName((CMwId *)pSVar5,(CFastStringInt *)&local_54,(CFastString *)&stack0xffffffa4)
  ;
  pCVar11 = (CFastString *)0x0;
  local_8 = (undefined *)CONCAT31(local_8._1_3_,2);
  puVar10 = PTR_DAT_00bbf7d8;
  CFastStringInt::GetUtf8
            (&local_54,(CFastStringInt *)&stack0xffffff9c,(CFastString *)0x0,(int)unaff_EDI);
  this_00 = (CGameNetwork *)(**(code **)(*(int *)this + 0x118))();
  if (((*(int *)(this_00 + 0x1a8) == 0) ||
      (iVar6 = CGameNetwork::IsConnected(this_00,in_stack_ffffff94), iVar6 == 0)) ||
     (*(int *)(*(int *)(this_00 + 0x23c) + 100) == 0)) {
    pCVar7 = (CFastString *)&DAT_00d71c9c;
  }
  else {
    pCVar7 = (CFastString *)(*(int *)(this_00 + 0x23c) + 100);
  }
  CFastString::CFastString((CFastString *)&local_40,pCVar7,(char *)in_stack_ffffff94);
  in_stack_00000028 = (void *)CONCAT31(in_stack_00000028._1_3_,3);
  if (((*(int *)(this + 0x274) != 0) && (local_3c == 0)) && (*(int *)(this + 0x288) != 0)) {
    local_14 = *(void **)(this + 0x28c);
    puStack_10 = *(undefined1 **)(this + 0x288);
    CFastString::SetString((CFastString *)&local_3c,(CFastStringInt *)&local_14,in_stack_ffffff98);
  }
  if ((*(int *)(this_00 + 0x1a8) != 0) &&
     (iVar6 = CGameNetwork::IsInternet(this_00,(CGameNetwork *)pCVar11), iVar6 != 0)) {
    pCVar11 = (CFastString *)0x0;
    pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00 + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)puVar10);
    if (*(int *)(*(int *)pSVar8 + 0x28) != 0) {
      pCVar11 = (CFastString *)0x5f7a3a;
      pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00 + 0x2fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          uVar12);
      local_50 = (CFastString *)(*(int *)pSVar8 + 0x28);
      goto LAB_005f7a59;
    }
  }
  if (*(int *)(this + 0x168) == 0) {
    local_50 = (CFastString *)&DAT_00d71c9c;
  }
  else {
    local_50 = (CFastString *)(*(int *)(this + 0x168) + 0x34);
  }
LAB_005f7a59:
  if ((*(int *)(this_00 + 0x1a8) == 0) || (*(int *)(this_00 + 0x1d0) != 0)) {
    local_48 = (CFastString *)&DAT_00d71c9c;
  }
  else {
    local_48 = (CFastString *)(**(code **)(**(int **)(this_00 + 0x23c) + 0x9c))();
  }
  CVar1 = CMwId::GetName((void *)(local_40 + 8),(CTrackManiaEditorIconPage *)&stack0x00000018);
  uStack0000002c = 4;
  CVar2 = CMwId::GetName(param_1 + 0xe4,(CTrackManiaEditorIconPage *)&puStack_10);
  uStack0000002c = 5;
  CVar3 = CMwId::GetName(param_1 + 0xe0,(CTrackManiaEditorIconPage *)&local_18);
  uStack0000002c = 6;
  CGameAdvertising::SetAdvertisingZone
            (*(CGameAdvertising **)(this + 0x210),
             (CGameAdvertising *)CONCAT31(extraout_var_01,CVar3),
             (CFastString *)CONCAT31(extraout_var_00,CVar2),(CFastString *)&local_30,
             (CFastString *)CONCAT31(extraout_var,CVar1),local_48,local_50,local_38,pCVar11);
  if (puStack_10 != PTR_DAT_00bbf7d8) {
    puVar9 = puStack_10 + -1;
    if ((puStack_10[-1] & 0x80) != 0) {
      puVar9 = puStack_10 + -4;
    }
    operator_delete__(puVar9);
    local_14 = (void *)0x0;
    puStack_10 = PTR_DAT_00bbf7d8;
  }
  if (local_8 != PTR_DAT_00bbf7d8) {
    puVar10 = local_8 + -1;
    if ((local_8[-1] & 0x80) != 0) {
      puVar10 = local_8 + -4;
    }
    operator_delete__(puVar10);
    local_c = 0;
    local_8 = PTR_DAT_00bbf7d8;
  }
  if (in_stack_00000020 != PTR_DAT_00bbf7d8) {
    puVar10 = in_stack_00000020 + -1;
    if ((in_stack_00000020[-1] & 0x80) != 0) {
      puVar10 = in_stack_00000020 + -4;
    }
    operator_delete__(puVar10);
  }
  if (local_30 != PTR_DAT_00bbf7d8) {
    puVar10 = local_30 + -1;
    if ((local_30[-1] & 0x80) != 0) {
      puVar10 = local_30 + -4;
    }
    operator_delete__(puVar10);
    local_34 = 0;
    local_30 = PTR_DAT_00bbf7d8;
  }
  if (local_28 != PTR_DAT_00bbf7d8) {
    puVar10 = local_28 + -1;
    if ((local_28[-1] & 0x80) != 0) {
      puVar10 = local_28 + -4;
    }
    operator_delete__(puVar10);
    local_2c = 0;
    local_28 = PTR_DAT_00bbf7d8;
  }
  if (local_20 != PTR_DAT_00bbf7d8) {
    puVar10 = local_20 + -1;
    if ((local_20[-1] & 0x80) != 0) {
      puVar10 = local_20 + -4;
    }
    operator_delete__(puVar10);
    local_24 = 0;
    local_20 = PTR_DAT_00bbf7d8;
  }
  if (local_18 == PTR_DAT_00bbf7dc) {
    ExceptionList = in_stack_00000028;
    return;
  }
  if ((local_18[-1] & 0x80) != 0) {
    operator_delete__(local_18 + -4);
    ExceptionList = in_stack_00000028;
    return;
  }
  operator_delete__(local_18 + -2);
  ExceptionList = in_stack_00000028;
  return;
}
}

// =================================================
// Function: CGameCtnApp::GetCurrentInputBindings
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CInputBindingsConfig * __thiscall
CGameCtnApp::GetCurrentInputBindings(CGameCtnApp *this,CGameCtnApp *param_1,int param_2)
{
{
  CMwNod *pCVar1;
  CInputBindingsConfig *pCVar2;
  CInputBindingsConfig *pCVar3;
  CMwNod *extraout_EAX;
  CMwNod *extraout_EAX_00;
  _func___cdecl_void_CInputBindingsConfig_ptr_CInputDevice_ptr_ulong *unaff_ESI;
  CMwNod *pCVar4;
  CMwNod *unaff_EDI;
  void *unaff_retaddr;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00aa3f26;
  local_c = ExceptionList;
  pCVar2 = (CInputBindingsConfig *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  pCVar4 = *(CMwNod **)(this + 0x168);
  if (pCVar4 != (CMwNod *)0x0) {
    if ((param_1 == (CGameCtnApp *)0x0) ||
       (pCVar2 = *(CInputBindingsConfig **)(pCVar4 + 0x148), pCVar2 == (CInputBindingsConfig *)0x0))
    {
      pCVar2 = *(CInputBindingsConfig **)(pCVar4 + 0x144);
    }
    return pCVar2;
  }
  ExceptionList = &local_c;
  if (param_1 == (CGameCtnApp *)0x0) {
    if ((_DAT_00d695f0 & 2) == 0) {
      _DAT_00d695f0 = _DAT_00d695f0 | 2;
      DAT_00d695e8 = (CMwNod *)0x0;
      _atexit(`public:_class_CInputBindingsConfig*___thiscall_CGameCtnApp::
              GetCurrentInputBindings(int)'::__l13::
              _dynamic_atexit_destructor_for__DefaultInputBidings__);
    }
    if (DAT_00d695e8 == (CMwNod *)0x0) {
      pCVar3 = operator_new(0x50);
      local_4 = 1;
      if (pCVar3 == (CInputBindingsConfig *)0x0) {
        pCVar4 = (CMwNod *)0x0;
      }
      else {
        CInputBindingsConfig::CInputBindingsConfig(pCVar3,pCVar2);
        pCVar4 = extraout_EAX_00;
      }
      unaff_retaddr = (void *)0xffffffff;
      pCVar1 = DAT_00d695e8;
      if (pCVar4 != DAT_00d695e8) {
        if (pCVar4 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(pCVar4,unaff_EDI);
        }
        pCVar1 = pCVar4;
        if (DAT_00d695e8 != (CMwNod *)0x0) {
          CMwNod::MwRelease(DAT_00d695e8,unaff_EDI);
        }
      }
      DAT_00d695e8 = pCVar1;
      InputsInitActions(this,(CGameCtnApp *)DAT_00d695e8,(CInputBindingsConfig *)0x0,
                        (_func___cdecl_void_CInputBindingsConfig_ptr *)unaff_EDI);
      InputsSetDefault(this,(CGameCtnApp *)DAT_00d695e8,(CInputBindingsConfig *)0x0,unaff_ESI);
    }
    ExceptionList = unaff_retaddr;
    return (CInputBindingsConfig *)DAT_00d695e8;
  }
  if ((_DAT_00d695f0 & 1) == 0) {
    _DAT_00d695f0 = _DAT_00d695f0 | 1;
    DAT_00d695ec = pCVar4;
    _atexit(`public:_class_CInputBindingsConfig*___thiscall_CGameCtnApp::
            GetCurrentInputBindings(int)'::__l8::
            _dynamic_atexit_destructor_for__DefaultMultiLocalInputBidings__);
  }
  if (DAT_00d695ec == (CMwNod *)0x0) {
    pCVar3 = operator_new(0x50);
    local_4 = 0;
    if (pCVar3 == (CInputBindingsConfig *)0x0) {
      pCVar4 = (CMwNod *)0x0;
    }
    else {
      CInputBindingsConfig::CInputBindingsConfig(pCVar3,pCVar2);
      pCVar4 = extraout_EAX;
    }
    unaff_retaddr = (void *)0xffffffff;
    pCVar1 = DAT_00d695ec;
    if (pCVar4 != DAT_00d695ec) {
      if (pCVar4 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar4,unaff_EDI);
      }
      pCVar1 = pCVar4;
      if (DAT_00d695ec != (CMwNod *)0x0) {
        CMwNod::MwRelease(DAT_00d695ec,unaff_EDI);
      }
    }
    DAT_00d695ec = pCVar1;
    InputsInitActions(this,(CGameCtnApp *)DAT_00d695ec,*(CInputBindingsConfig **)(this + 0x2c8),
                      (_func___cdecl_void_CInputBindingsConfig_ptr *)unaff_EDI);
    InputsSetDefault(this,(CGameCtnApp *)DAT_00d695ec,*(CInputBindingsConfig **)(this + 0x2d0),
                     unaff_ESI);
  }
  ExceptionList = unaff_retaddr;
  return (CInputBindingsConfig *)DAT_00d695ec;
}
}

// =================================================
// Function: CGameCtnApp::GetMasterServer
// =================================================
CGameCtnMasterServer * __thiscall
CGameCtnApp::GetMasterServer(CGameCtnApp *this,CGameCtnApp *param_1)
{
{
  if (*(int *)(this + 300) != 0) {
    return *(CGameCtnMasterServer **)(*(int *)(this + 300) + 0x1b0);
  }
  return (CGameCtnMasterServer *)0x0;
}
}

// =================================================
// Function: CGameCtnApp::GetVehicleDisplayName
// =================================================
void __cdecl
CGameCtnApp::GetVehicleDisplayName(CMwId *param_1,CFastStringInt *param_2,CFastString *param_3)
{
{
  SStringParam *pSVar1;
  int iVar2;
  SFastTokenInt *unaff_EBX;
  int unaff_ESI;
  SStringParam *unaff_EDI;
  CFastString *in_stack_00000010;
  void *in_stack_00000014;
  SStringParam *pSVar3;
  SFastTokenInt *pSVar4;
  SFastTokenInt *pSVar5;
  SFastTokenInt *pSVar6;
  undefined1 local_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00aa3ab0;
  local_c = ExceptionList;
  pSVar1 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffb4);
  ExceptionList = &local_c;
  pSVar3 = (SStringParam *)0x0;
  local_4 = 0;
  pSVar4 = (SFastTokenInt *)PTR_DAT_00bbf7dc;
  CMwId::GetName(param_1,(CTrackManiaEditorIconPage *)&stack0xffffffc0);
  pSVar5 = pSVar4;
  CFastStringInt::SetString(param_2,(CFastStringInt *)&stack0xffffffc8,pSVar1);
  pSVar6 = (SFastTokenInt *)&DAT_00b2c878;
  CFastString::SetString(in_stack_00000010,(CFastStringInt *)&stack0xffffffcc,unaff_EDI);
  SFastTokenInt::SFastTokenInt
            (&local_24,(SFastTokenInt *)PTR_lpOutputString_00b2bcc4_00d34104,(char *)0x1,unaff_ESI);
  iVar2 = CFastStringInt::GetNextToken(&stack0xffffffcc,(CFastStringInt *)&local_20,unaff_EBX);
  if (iVar2 != 0) {
    local_28 = local_14;
    local_24 = local_18;
    local_20 = 0;
    CFastStringInt::SetString(param_2,(CFastStringInt *)&local_28,pSVar3);
  }
  iVar2 = CFastStringInt::GetNextToken(local_2c,(CFastStringInt *)&local_18,pSVar4);
  if (iVar2 != 0) {
    CFastStringInt::GetAscii(local_10,(CFastStringInt *)in_stack_00000010,(CFastString *)pSVar5);
  }
  SFastTokenInt::~SFastTokenInt(local_10,pSVar6);
  if (local_1c != PTR_DAT_00bbf7dc) {
    if ((local_1c[-1] & 0x80) == 0) {
      local_1c = local_1c + -2;
    }
    else {
      local_1c = local_1c + -4;
    }
    operator_delete__(local_1c);
  }
  ExceptionList = in_stack_00000014;
  return;
}
}

// =================================================
// Function: CGameCtnApp::GetWritableDir
// =================================================
CSystemFidsFolder * __thiscall
CGameCtnApp::GetWritableDir(CGameCtnApp *this,CGameCtnApp *param_1,EDirectory param_2)
{
{
  CSystemFidsFolder *pCVar1;
  
  pCVar1 = CSystemDataFolders::GetUserDir(this + 0x148,(CSystemDataFolders *)param_1,param_2);
  return pCVar1;
}
}

// =================================================
// Function: CGameCtnApp::HideDialogs
// =================================================
void __thiscall CGameCtnApp::HideDialogs(CGameCtnApp *this,CGameCtnMenus *param_1)
{
{
  CGameApp_MenuContext *pCVar1;
  CGameMenu *unaff_retaddr;
  
  pCVar1 = *(CGameApp_MenuContext **)(*(int *)(this + 0x194) + 0x78c);
  if ((pCVar1 != (CGameApp_MenuContext *)0x0) && (*(int *)(pCVar1 + 0xb0) != 0)) {
    CGameApp::HideMenu((CGameApp *)this,pCVar1,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CGameCtnApp::InputsInitActions
// =================================================
void __thiscall
CGameCtnApp::InputsInitActions
          (CGameCtnApp *this,CGameCtnApp *param_1,CInputBindingsConfig *param_2,
          _func___cdecl_void_CInputBindingsConfig_ptr *param_3)
{
{
  void *pvVar1;
  CPlugVisualSprite *unaff_ESI;
  char *unaff_EDI;
  undefined4 uStack00000010;
  CVisionViewportDx9 *in_stack_ffffffec;
  ESpriteColor0 *in_stack_fffffff0;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aa32d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((param_2 != (CInputBindingsConfig *)0x0) ||
     (param_2 = *(CInputBindingsConfig **)(this + 0x2c4), param_2 != (CInputBindingsConfig *)0x0)) {
    CInputBindingsConfig::ClearActions
              ((CInputBindingsConfig *)param_1,
               (CInputBindingsConfig *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
    CFastString::CFastString((CFastString *)&stack0xfffffff0,(CFastString *)&DAT_00b352f8,unaff_EDI)
    ;
    CInputBindingsConfig::Init
              ((CInputBindingsConfig *)param_1,(CLoadGeomDynaSprite *)&local_c,unaff_ESI,
               in_stack_ffffffec,in_stack_fffffff0);
    uStack00000010 = 0xffffffff;
    if (PTR_DAT_00bbf7d8 != (undefined *)0x0) {
      pvVar1 = (void *)0xffffffff;
      if ((bRamffffffff & 0x80) != 0) {
        pvVar1 = (void *)0xfffffffc;
      }
      operator_delete__(pvVar1);
    }
    (*(code *)param_2)();
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CGameCtnApp::InputsSetDefault
// =================================================
void __thiscall
CGameCtnApp::InputsSetDefault
          (CGameCtnApp *this,CGameCtnApp *param_1,CInputBindingsConfig *param_2,
          _func___cdecl_void_CInputBindingsConfig_ptr_CInputDevice_ptr_ulong *param_3)
{
{
  _func___cdecl_void_CInputBindingsConfig_ptr_CInputDevice_ptr_ulong *unaff_ESI;
  CMwId *unaff_EDI;
  
  CInputBindingsConfig::ClearAllBindings((CInputBindingsConfig *)param_1,DAT_00d739e4,unaff_EDI);
  InputsSetToDefaultUnbidedDevices(this,param_1,(CInputBindingsConfig *)param_3,unaff_ESI);
  return;
}
}

// =================================================
// Function: CGameCtnApp::InputsSetToDefaultUnbidedDevices
// =================================================
void __thiscall
CGameCtnApp::InputsSetToDefaultUnbidedDevices
          (CGameCtnApp *this,CGameCtnApp *param_1,CInputBindingsConfig *param_2,
          _func___cdecl_void_CInputBindingsConfig_ptr_CInputDevice_ptr_ulong *param_3)
{
{
  CGameCtnApp *this_00;
  CInputBindingsConfig *pCVar1;
  CMwId *pCVar2;
  int iVar3;
  CMwId *pCVar4;
  ulong local_18;
  CInputBindingsConfig *local_14;
  code *pcStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00aa2478;
  local_c = ExceptionList;
  pCVar2 = (CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffd8);
  if (param_2 == (CInputBindingsConfig *)0x0) {
    local_14 = *(CInputBindingsConfig **)(this + 0x2cc);
    if (local_14 == (CInputBindingsConfig *)0x0) {
      return;
    }
  }
  else {
    local_14 = param_2;
  }
  pCVar1 = local_14;
  pCVar4 = (CMwId *)0x0;
  ExceptionList = &local_c;
  iVar3 = CInputPort::FindDevice
                    (*(CInputPort **)(this + 0x6c),(CInputPort *)0x0,(CMwId *)0x0,&local_18,
                     (CInputDevice **)&param_2);
  this_00 = param_1;
  while (iVar3 != 0) {
    pCVar4 = pCVar4 + 1;
    CMwId::CMwId(&param_1,(CMwId *)(param_2 + 0x34));
    local_4 = 0;
    iVar3 = CInputBindingsConfig::IsDeviceConfigured
                      ((CInputBindingsConfig *)this_00,(CInputBindingsConfig *)&param_1,pCVar2);
    if (iVar3 == 0) {
      pCVar2 = pCVar4;
      (*(code *)pCVar1)(this_00,param_3);
    }
    local_4 = 0xffffffff;
    OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar2);
    iVar3 = CInputPort::FindDevice
                      (*(CInputPort **)(this + 0x6c),(CInputPort *)0x0,pCVar4,&local_18,
                       (CInputDevice **)&param_2);
  }
  pCVar4 = (CMwId *)0x0;
  iVar3 = CInputPort::FindDevice
                    (*(CInputPort **)(this + 0x6c),(CInputPort *)0x1,(CMwId *)0x0,&local_18,
                     (CInputDevice **)&param_2);
  while (iVar3 != 0) {
    pCVar4 = pCVar4 + 1;
    CMwId::CMwId(&param_1,(CMwId *)(param_2 + 0x34));
    local_4 = 1;
    iVar3 = CInputBindingsConfig::IsDeviceConfigured
                      ((CInputBindingsConfig *)this_00,(CInputBindingsConfig *)&param_1,pCVar2);
    if (iVar3 == 0) {
      pCVar2 = pCVar4;
      (*(code *)pCVar1)(this_00,param_3);
    }
    local_4 = 0xffffffff;
    OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar2);
    iVar3 = CInputPort::FindDevice
                      (*(CInputPort **)(this + 0x6c),(CInputPort *)0x1,pCVar4,&local_18,
                       (CInputDevice **)&param_2);
  }
  pCVar4 = (CMwId *)0x0;
  iVar3 = CInputPort::FindDevice
                    (*(CInputPort **)(this + 0x6c),(CInputPort *)0x2,(CMwId *)0x0,&local_18,
                     (CInputDevice **)&param_2);
  while (iVar3 != 0) {
    pCVar4 = pCVar4 + 1;
    CMwId::CMwId(&pcStack_10,(CMwId *)(param_2 + 0x34));
    local_4 = 2;
    iVar3 = CInputBindingsConfig::IsDeviceConfigured
                      ((CInputBindingsConfig *)this_00,(CInputBindingsConfig *)&pcStack_10,pCVar2);
    if (iVar3 == 0) {
      pCVar2 = pCVar4;
      (*pcStack_10)(this_00,param_3);
    }
    local_4 = 0xffffffff;
    OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar2);
    iVar3 = CInputPort::FindDevice
                      (*(CInputPort **)(this + 0x6c),(CInputPort *)0x2,pCVar4,&local_18,
                       (CInputDevice **)&param_2);
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CGameCtnApp::SaveValidationReplay
// =================================================
void __thiscall
CGameCtnApp::SaveValidationReplay
          (CGameCtnApp *this,CGameCtnApp *param_1,CGameCtnReplayRecord *param_2,int param_3)
{
{
  undefined4 *extraout_EAX;
  undefined4 *extraout_EAX_00;
  undefined4 *puVar1;
  CSystemFidsFolder *pCVar2;
  int iVar3;
  SCasterCat *pSVar4;
  undefined *puVar5;
  SNationConfig *unaff_EBX;
  SStringParamInt *unaff_ESI;
  SStringParam *unaff_EDI;
  void *in_stack_00000014;
  SStringParam *pSVar6;
  ulong in_stack_ffffffe0;
  CMwNod *in_stack_ffffffe4;
  undefined1 local_18 [4];
  CFastStringInt local_14 [4];
  char *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined *local_4;
  
  local_8 = &LAB_00aa2cc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pSVar6 = (SStringParam *)0x0;
  local_4 = (undefined *)0x0;
  if ((param_1 != (CGameCtnApp *)0x0) && (*(int *)(param_1 + 0x24) != 0)) {
    puVar5 = PTR_DAT_00bbf7dc;
    CGameCtnReplayRecord::BuildReplayDefaultFileName
              ((CGameCtnReplayRecord *)param_1,(CGameCtnReplayRecord *)&stack0xffffffd8,
               (CFastStringInt *)0x1,1,0xd71c9c,
               (CFastString *)(DAT_00cca150 ^ (uint)&stack0xffffffcc));
    if (param_3 == 0) {
      CFastStringInt::CFastStringInt(&stack0xffffffe4,(CFastStringInt *)L"Validation_",unaff_EDI);
      puVar1 = extraout_EAX_00;
    }
    else {
      CFastStringInt::CFastStringInt
                (&stack0xffffffe4,(CFastStringInt *)L"LocalValidation_",unaff_EDI);
      puVar1 = extraout_EAX;
    }
    local_10 = (char *)puVar1[1];
    local_c = (void *)*puVar1;
    local_8 = (undefined1 *)0x0;
    CFastStringInt::ConcatBefore(&stack0xffffffe0,(CFastStringInt *)&local_10,unaff_ESI);
    SNationConfig::~SNationConfig(local_14,unaff_EBX);
    local_10 = ".Replay.Gbx";
    local_c = (void *)0xb;
    CFastStringInt::Concat(local_18,(CFastStringInt *)&local_10,pSVar6);
    CSystemFileName::FixFileName(local_14,2);
    pCVar2 = GetWritableDir(this,(CGameCtnApp *)&DAT_00000005,(EDirectory)puVar5);
    iVar3 = CSystemArchiveNod::SaveFile
                      ((CFastStringInt *)&local_10,(CMwNod *)param_1,(CSystemFids *)pCVar2,10,7,1);
    if (iVar3 != 0) {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(DAT_00d73300 + 0x20),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                          in_stack_ffffffe0);
      CSystemEngine::UnbindFid(*(CSystemEngine **)pSVar4,(CSystemEngine *)param_1,in_stack_ffffffe4)
      ;
    }
    if (local_4 != PTR_DAT_00bbf7dc) {
      if ((local_4[-1] & 0x80) == 0) {
        puVar5 = local_4 + -2;
      }
      else {
        puVar5 = local_4 + -4;
      }
      operator_delete__(puVar5);
    }
  }
  ExceptionList = in_stack_00000014;
  return;
}
}

// =================================================
// Function: CGameCtnApp::ShowDialogs
// =================================================
void __thiscall
CGameCtnApp::ShowDialogs(CGameCtnApp *this,CGameCtnMenus *param_1,CControlFrame *param_2)
{
{
  CGameApp_MenuContext *pCVar1;
  CGameMenu *unaff_ESI;
  
  pCVar1 = *(CGameApp_MenuContext **)(*(int *)(this + 0x194) + 0x78c);
  if (pCVar1 != (CGameApp_MenuContext *)0x0) {
    if (*(int *)(pCVar1 + 0xb0) == 0) {
      CGameApp::ShowMenu((CGameApp *)this,pCVar1,unaff_ESI);
    }
    (**(code **)(**(int **)(*(int *)(this + 0x194) + 0x550) + 0x100))();
    CGameApp::EnablePick((CGameApp *)this,(CGameApp *)param_2);
    return;
  }
  return;
}
}

// =================================================
// Function: CGameCtnApp::UpdateAsync
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameCtnApp::UpdateAsync(CGameCtnApp *this,CInputPortDx8 *param_1)
{
{
  float fVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ulong *puVar6;
  CMwTimerAdapter *unaff_ESI;
  float10 extraout_ST0;
  GmRectAligned *in_stack_ffffffec;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  if (*(int *)(this + 0x340) != *(int *)(this + 0x33c)) {
    puVar6 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_ESI);
    uVar2 = *(uint *)(this + 0x348);
    uVar3 = *puVar6;
    if (uVar2 == 0xfffffffe) {
      *(undefined4 *)(this + 0x348) = 0xffffffff;
    }
    else if (uVar2 == 0xffffffff) {
      *(uint *)(this + 0x348) = uVar3;
    }
    else {
      if (((_DAT_00b66804 < *(float *)(this + 0x344)) && (uVar2 <= uVar3)) &&
         (1.0 <= ((float)(int)(uVar3 - uVar2) * (float)_DAT_00b30a18) / *(float *)(this + 0x344))) {
        *(undefined4 *)(this + 0x33c) = *(undefined4 *)(this + 0x340);
      }
      __CIsin();
      fVar1 = (float)extraout_ST0;
      if (*(int *)(this + 0x340) == 0) {
        fVar1 = 1.0 - fVar1;
      }
      iVar4 = *(int *)(this + 0x174);
      if (iVar4 != 0) {
        iVar5 = *(int *)(*(int *)(iVar4 + 0x74) + 0x30);
        local_c = *(undefined4 *)(iVar5 + 0x1d4);
        local_4 = *(undefined4 *)(iVar5 + 0x1dc);
        local_8 = fVar1 * (float)_DAT_00b3d298 - 1.0;
        CHmsCamera::ScissorRectSet
                  (*(CHmsCamera **)(*(int *)(iVar4 + 0x74) + 0x30),(CHmsCamera *)&local_c,
                   in_stack_ffffffec);
      }
    }
  }
  if (*(int **)(this + 0x194) == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005e5dcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(this + 0x194) + 0x94))();
  return;
}
}

