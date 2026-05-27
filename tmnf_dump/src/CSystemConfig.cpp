// Class implementation: CSystemConfig

// =================================================
// Function: CSystemConfig::ApplyDynamicPresets
// =================================================
void __thiscall
CSystemConfig::ApplyDynamicPresets(CSystemConfig *this,CSystemConfigDisplay *param_1)
{
{
  uint uVar1;
  int iVar2;
  CSystemConfig *unaff_ESI;
  CSystemConfig *unaff_retaddr;
  
  SetAutoOrPresetAll(this,unaff_ESI);
  uVar1 = *(uint *)(this + 0x16c);
  if (*(uint *)(this + 0x16c) <= DAT_00ccb7c0) {
    uVar1 = DAT_00ccb7c0;
  }
  *(uint *)(this + 0x16c) = uVar1;
  iVar2 = ParentalLock_ComputeIsLocked(this,unaff_retaddr);
  *(int *)(this + 0x1c8) = iVar2;
  CSystemConfigDisplay::ApplyDynamicPresets(*(CSystemConfigDisplay **)(this + 0x24),param_1);
  *(undefined4 *)(this + 0x2c) = 1;
  return;
}
}

// =================================================
// Function: CSystemConfig::CSystemConfig
// =================================================
void __thiscall CSystemConfig::CSystemConfig(CSystemConfig *this,CSystemConfig *param_1)
{
{
  undefined4 extraout_EAX;
  undefined4 uVar1;
  CSystemConfigDisplay *extraout_EAX_00;
  CSystemConfigDisplay *pCVar2;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBP;
  SSystemTime *unaff_ESI;
  CMwNod *unaff_EDI;
  CSystemConfigDisplay *pCStack00000008;
  CSystemConfigDisplay *pCStack0000000c;
  undefined4 in_stack_00000010;
  undefined1 uStack00000018;
  undefined1 uStack0000001c;
  undefined3 uStack0000001d;
  CSystemConfig *pCVar3;
  SSystemTime *in_stack_ffffffec;
  SSystemTime *in_stack_fffffff0;
  GmNat2 *pGVar4;
  CSystemConfig *pCVar5;
  
  pCVar5 = (CSystemConfig *)0xffffffff;
  pGVar4 = (GmNat2 *)&LAB_00a81c6c;
  pCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar3 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffdc),unaff_EDI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined **)(this + 0x1c) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined **)(this + 0x40) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined **)(this + 0x48) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined **)(this + 100) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined **)(this + 0x74) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined **)(this + 0x7c) = PTR_DAT_00bbf7d8;
  SSystemTime::SSystemTime(this + 0x80,unaff_ESI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x88,unaff_EBP);
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined **)(this + 0x9c) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined **)(this + 0xac) = PTR_DAT_00bbf7d8;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0xbc,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar3);
  *(undefined4 *)(this + 0xe4) = 0;
  *(undefined **)(this + 0xe8) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0xec) = 0;
  *(undefined **)(this + 0xf0) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x110) = 0;
  *(undefined **)(this + 0x114) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 300) = 0;
  *(undefined **)(this + 0x130) = PTR_DAT_00bbf7dc;
  *(undefined4 *)(this + 400) = 0;
  *(undefined **)(this + 0x194) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x198) = 0;
  *(undefined **)(this + 0x19c) = PTR_DAT_00bbf7d8;
  in_stack_00000010 = CONCAT31(in_stack_00000010._1_3_,0x10);
  SSystemTime::SSystemTime(this + 0x1a4,in_stack_ffffffec);
  SSystemTime::SSystemTime(this + 0x1ac,in_stack_fffffff0);
  *(undefined4 *)(this + 0x6c) = 1;
  *(undefined4 *)(this + 0x94) = 1;
  *(undefined4 *)(this + 0x20) = 0;
  pCStack00000008 = operator_new(0xd8);
  uStack00000018 = 0x11;
  if (pCStack00000008 == (CSystemConfigDisplay *)0x0) {
    uVar1 = 0;
  }
  else {
    CSystemConfigDisplay::CSystemConfigDisplay(pCStack00000008,pCVar2);
    uVar1 = extraout_EAX;
  }
  uStack0000001c = 0x10;
  *(undefined4 *)(this + 0x24) = uVar1;
  pCStack0000000c = operator_new(0xd8);
  uStack0000001c = 0x12;
  if (pCStack0000000c == (CSystemConfigDisplay *)0x0) {
    pCVar2 = (CSystemConfigDisplay *)0x0;
  }
  else {
    CSystemConfigDisplay::CSystemConfigDisplay(pCStack0000000c,(CSystemConfigDisplay *)pGVar4);
    pCVar2 = extraout_EAX_00;
  }
  _uStack0000001c = (void *)CONCAT31(uStack0000001d,0x10);
  *(CSystemConfigDisplay **)(this + 0x28) = pCVar2;
  pCStack0000000c = (CSystemConfigDisplay *)0x280;
  in_stack_00000010 = 0x1e0;
  CSystemConfigDisplay::SetSafeValues
            (pCVar2,(CSystemConfigDisplay *)0x0,(int)&stack0x0000000c,pGVar4);
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0xa0) = 1;
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0x14) = 1;
  SetDefaultsAll(this,pCVar5);
  ExceptionList = _uStack0000001c;
  return;
}
}

// =================================================
// Function: CSystemConfig::GetNetworkIsFireWallTested
// =================================================
int __thiscall CSystemConfig::GetNetworkIsFireWallTested(CSystemConfig *this,CSystemConfig *param_1)
{
{
  int iVar1;
  GxTexCoordSet *unaff_ESI;
  CSystemConfig *local_4;
  
  local_4 = this;
  local_4 = (CSystemConfig *)CSystemEngine::GetExeCheckSum();
  iVar1 = CFastArray<class_CGameMenuFrame*>::Find
                    (this + 0x88,(CFastArray<class_GxTexCoordSet> *)&local_4,unaff_ESI);
  return (uint)(iVar1 != -1);
}
}

// =================================================
// Function: CSystemConfig::ParentalLock_ComputeIsLocked
// =================================================
int __thiscall
CSystemConfig::ParentalLock_ComputeIsLocked(CSystemConfig *this,CSystemConfig *param_1)
{
{
  int iVar1;
  SSystemTime *unaff_ESI;
  int64 iVar2;
  SSystemTime *in_stack_fffffff8;
  SSystemTime *in_stack_fffffffc;
  
  if ((*(int *)(this + 0x1b8) == 0 && *(int *)(this + 0x1bc) == 0) &&
     (*(int *)(this + 0x1c0) == 0 && *(int *)(this + 0x1c4) == 0)) {
    return 0;
  }
  iVar1 = SSystemTime::IsInvalid((SSystemTime *)(this + 0x1ac),unaff_ESI);
  if (iVar1 == 0) {
    SSystemTime::SSystemTime(&stack0xfffffffc,in_stack_fffffff8);
    SSystemTime::SetFromLocalTime(&stack0x00000000,in_stack_fffffffc);
    iVar2 = SSystemTime::GetT2SubT1InMilliseconds
                      ((SSystemTime *)(this + 0x1ac),(SSystemTime *)&param_1);
    if (((int)((ulonglong)iVar2 >> 0x20) == 0) && ((uint)iVar2 < 120000)) {
      return 0;
    }
  }
  return 1;
}
}

// =================================================
// Function: CSystemConfig::SetAutoOrPresetAll
// =================================================
void __thiscall CSystemConfig::SetAutoOrPresetAll(CSystemConfig *this,CSystemConfig *param_1)
{
{
  CSystemConfig *unaff_ESI;
  CSystemConfig *in_stack_00000008;
  
  SetAutoOrPresetVsk3(this,unaff_ESI);
  SetAutoOrPresetTM(this,in_stack_00000008);
  return;
}
}

// =================================================
// Function: CSystemConfig::SetAutoOrPresetTM
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSystemConfig::SetAutoOrPresetTM(CSystemConfig *this,CSystemConfig *param_1)
{
{
  int iVar1;
  uint uVar2;
  CPlugFileGpuBuilder *pCVar3;
  char *unaff_EBP;
  CPlugFileGpuBuilder *unaff_ESI;
  CSystemConfigDisplay *unaff_EDI;
  CSystemConfigDisplay *this_00;
  
  if (*(int *)(this + 0x20) == 0) {
    this_00 = *(CSystemConfigDisplay **)(this + 0x24);
  }
  else {
    this_00 = *(CSystemConfigDisplay **)(this + 0x28);
  }
  if (*(int *)(this_00 + 0x40) == 0) {
    iVar1 = CSystemConfigDisplay::IsGraphicAdpaterMain_NVidia_C51(this_00,unaff_EDI);
    if (iVar1 == 0) {
      if ((float)_DAT_00b2f748 <= DAT_00d542e8) {
        if ((float)_DAT_00b2f718 <= DAT_00d542e8) {
          if ((float)_DAT_00b2f740 <= DAT_00d542e8) {
            uVar2 = 4;
            if ((float)_DAT_00b2f738 <= DAT_00d542e8) {
              uVar2 = 5;
            }
          }
          else {
            uVar2 = 3;
          }
        }
        else {
          uVar2 = 2;
        }
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 1;
    }
    if (*(int *)(this_00 + 0x3c) == 0) {
      if (1 < uVar2) {
        uVar2 = uVar2 - 1;
      }
    }
    else if ((*(int *)(this_00 + 0x3c) == 2) && (uVar2 < 5)) {
      uVar2 = uVar2 + 1;
    }
  }
  else {
    uVar2 = *(uint *)(this_00 + 0x44);
  }
  switch(uVar2) {
  case 1:
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar3 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)"[Sys] GameConfigPreset = Minimum",
                        (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)pCVar3,unaff_ESI,unaff_EBP);
    CClassicLog::AddLogStringInFile();
    *(undefined4 *)(this + 0x158) = 0;
    *(undefined4 *)(this + 0x15c) = 0;
    *(undefined4 *)(this + 0x160) = 0;
    *(undefined4 *)(this + 0x164) = 0;
    *(undefined4 *)(this + 0x170) = 0;
    *(undefined4 *)(this + 0x16c) = 4;
    return;
  case 2:
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar3 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)"[Sys] GameConfigPreset = Low",
                        (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)pCVar3,unaff_ESI,unaff_EBP);
    CClassicLog::AddLogStringInFile();
    *(undefined4 *)(this + 0x158) = 1;
    *(undefined4 *)(this + 0x15c) = 1;
    *(undefined4 *)(this + 0x160) = 0;
    *(undefined4 *)(this + 0x164) = 0;
    *(undefined4 *)(this + 0x170) = 0;
    *(undefined4 *)(this + 0x16c) = 6;
    return;
  case 3:
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar3 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)"[Sys] GameConfigPreset = Medium",
                        (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)pCVar3,unaff_ESI,unaff_EBP);
    CClassicLog::AddLogStringInFile();
    *(undefined4 *)(this + 0x158) = 1;
    *(undefined4 *)(this + 0x15c) = 1;
    *(undefined4 *)(this + 0x160) = 1;
    *(undefined4 *)(this + 0x170) = 0;
    *(undefined4 *)(this + 0x164) = 1;
    *(undefined4 *)(this + 0x16c) = 8;
    return;
  case 4:
    break;
  case 5:
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar3 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)"[Sys] GameConfigPreset = VeryHigh",
                        (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)pCVar3,unaff_ESI,unaff_EBP);
    CClassicLog::AddLogStringInFile();
    if (*(int *)(this_00 + 0x40) == 0) {
      *(undefined4 *)(this + 0x158) = 2;
      *(undefined4 *)(this + 0x15c) = 2;
      *(undefined4 *)(this + 0x16c) = 0x10;
    }
    else {
      *(undefined4 *)(this + 0x158) = 3;
      *(undefined4 *)(this + 0x15c) = 3;
      *(undefined4 *)(this + 0x16c) = 0x18;
    }
    *(undefined4 *)(this + 0x170) = 2;
    *(undefined4 *)(this + 0x160) = 2;
    *(undefined4 *)(this + 0x164) = 1;
  default:
    return;
  }
  if (DAT_00d71e54 != 0) {
    DAT_00d71e54 = 0;
    *DAT_00d71e58 = 0;
  }
  pCVar3 = CFastString::operator<<
                     ((CFastString *)&DAT_00d71e54,
                      (CPlugFileGpuBuilder *)"[Sys] GameConfigPreset = High",
                      (char *)&lpOutputString_00b2bcc4);
  CFastString::operator<<((CFastString *)pCVar3,unaff_ESI,unaff_EBP);
  CClassicLog::AddLogStringInFile();
  iVar1 = *(int *)(this_00 + 0x40);
  *(undefined4 *)(this + 0x164) = 1;
  *(undefined4 *)(this + 0x170) = 1;
  if (iVar1 == 0) {
    *(undefined4 *)(this + 0x158) = 1;
    *(undefined4 *)(this + 0x15c) = 1;
    *(undefined4 *)(this + 0x160) = 1;
    *(undefined4 *)(this + 0x16c) = 0xc;
    return;
  }
  *(undefined4 *)(this + 0x158) = 2;
  *(undefined4 *)(this + 0x15c) = 2;
  *(undefined4 *)(this + 0x160) = 2;
  *(undefined4 *)(this + 0x16c) = 0x10;
  return;
}
}

// =================================================
// Function: CSystemConfig::SetAutoOrPresetVsk3
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSystemConfig::SetAutoOrPresetVsk3(CSystemConfig *this,CSystemConfig *param_1)
{
{
  float fVar1;
  int iVar2;
  uint uVar3;
  CPlugFileGpuBuilder *pCVar4;
  char *unaff_EBP;
  CPlugFileGpuBuilder *unaff_ESI;
  CSystemConfigDisplay *unaff_EDI;
  CSystemConfigDisplay *this_00;
  float fVar5;
  
  iVar2 = DAT_00d54238;
  if (*(int *)(this + 0x20) == 0) {
    this_00 = *(CSystemConfigDisplay **)(this + 0x24);
  }
  else {
    this_00 = *(CSystemConfigDisplay **)(this + 0x28);
  }
  if (*(int *)(this_00 + 0x40) == 0) {
    fVar5 = CSystemConfigDisplay::MultiThreadGetScale(this_00,unaff_EDI);
    fVar1 = (float)iVar2;
    if (iVar2 < 0) {
      fVar1 = fVar1 + _DAT_00c418d0;
    }
    fVar1 = fVar1 * fVar5;
    if ((DAT_00d542e8 < _DAT_00b2f730) || (fVar1 < (float)_DAT_00b2f728)) {
      uVar3 = 1;
    }
    else if ((DAT_00d542e8 < _DAT_00b2f720) || (fVar1 < (float)_DAT_00c418d8)) {
      uVar3 = 2;
    }
    else if (DAT_00d542e8 < (float)_DAT_00b2f718) {
      uVar3 = 3;
    }
    else if (fVar1 < (float)_DAT_00b2f710) {
      uVar3 = 3;
    }
    else if ((DAT_00d542e8 < _DAT_00b2f708) || (fVar1 < _DAT_00b2f704)) {
      uVar3 = 4;
    }
    else {
      uVar3 = 5;
    }
    if (*(int *)(this_00 + 0x3c) == 0) {
      if (1 < uVar3) {
        uVar3 = uVar3 - 1;
      }
    }
    else if ((*(int *)(this_00 + 0x3c) == 2) && (uVar3 < 5)) {
      uVar3 = uVar3 + 1;
    }
  }
  else {
    uVar3 = *(uint *)(this_00 + 0x44);
  }
  switch(uVar3) {
  case 1:
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar4 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)"[Sys] GameConfigPreset = Minimum",
                        (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)pCVar4,unaff_ESI,unaff_EBP);
    CClassicLog::AddLogStringInFile();
    *(undefined4 *)(this + 0x148) = 0;
    *(undefined4 *)(this + 0x14c) = 0;
    *(undefined4 *)(this + 0x150) = 0;
    *(undefined4 *)(this + 0x154) = 0;
    *(undefined4 *)(this + 0x170) = 0;
    return;
  case 2:
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar4 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)"[Sys] GameConfigPreset = Low",
                        (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)pCVar4,unaff_ESI,unaff_EBP);
    CClassicLog::AddLogStringInFile();
    *(undefined4 *)(this + 0x148) = 0;
    *(undefined4 *)(this + 0x14c) = 1;
    *(undefined4 *)(this + 0x150) = 1;
    *(undefined4 *)(this + 0x154) = 1;
    *(undefined4 *)(this + 0x170) = 0;
    return;
  case 3:
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar4 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)"[Sys] GameConfigPreset = Medium",
                        (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)pCVar4,unaff_ESI,unaff_EBP);
    CClassicLog::AddLogStringInFile();
    *(undefined4 *)(this + 0x148) = 1;
    *(undefined4 *)(this + 0x14c) = 1;
    *(undefined4 *)(this + 0x150) = 1;
    *(undefined4 *)(this + 0x154) = 1;
    *(undefined4 *)(this + 0x170) = 1;
    return;
  case 4:
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar4 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)"[Sys] GameConfigPreset = High",
                        (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)pCVar4,unaff_ESI,unaff_EBP);
    CClassicLog::AddLogStringInFile();
    *(undefined4 *)(this + 0x148) = 2;
    break;
  case 5:
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar4 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)"[Sys] GameConfigPreset = VeryHigh",
                        (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)pCVar4,unaff_ESI,unaff_EBP);
    CClassicLog::AddLogStringInFile();
    *(undefined4 *)(this + 0x148) = 3;
    break;
  default:
    goto switchD_00421c10_default;
  }
  *(undefined4 *)(this + 0x170) = 2;
  *(undefined4 *)(this + 0x154) = 2;
  *(undefined4 *)(this + 0x150) = 2;
  *(undefined4 *)(this + 0x14c) = 2;
switchD_00421c10_default:
  return;
}
}

// =================================================
// Function: CSystemConfig::SetDefaultLanguage
// =================================================
void __thiscall CSystemConfig::SetDefaultLanguage(CSystemConfig *this,CSystemConfig *param_1)
{
{
  SCasterCat *pSVar1;
  CFastString *pCVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  char *unaff_EBX;
  CSystemEngine *unaff_ESI;
  undefined *unaff_retaddr;
  void *in_stack_00000008;
  undefined1 uStack0000000c;
  char *in_stack_ffffffdc;
  SStringParam *in_stack_ffffffe0;
  CFastString local_14 [4];
  undefined4 local_10;
  undefined *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a81a28;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d73300 + 0x20),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                      DAT_00cca150 ^ (uint)&stack0xffffffd4);
  pCVar2 = (CFastString *)CSystemEngine::I18nGetSystemLanguage(*(CSystemEngine **)pSVar1,unaff_ESI);
  CFastString::CFastString((CFastString *)&local_c,pCVar2,unaff_EBX);
  in_stack_00000008 = (void *)CONCAT31(in_stack_00000008._1_3_,1);
  CFastString::CFastString((CFastString *)&local_10,(CFastString *)0xb2f750,in_stack_ffffffdc);
  uStack0000000c = 2;
  CSystemEngine::FileIniRead((CFastString *)&local_c,local_14,(CFastString *)&local_4);
  if (local_8 != PTR_DAT_00bbf7d8) {
    puVar3 = local_8 + -1;
    if ((local_8[-1] & 0x80) != 0) {
      puVar3 = local_8 + -4;
    }
    operator_delete__(puVar3);
    local_c = (undefined *)0x0;
    local_8 = PTR_DAT_00bbf7d8;
  }
  uStack0000000c = 0;
  if (unaff_retaddr != PTR_DAT_00bbf7d8) {
    puVar4 = unaff_retaddr + -1;
    if ((unaff_retaddr[-1] & 0x80) != 0) {
      puVar4 = unaff_retaddr + -4;
    }
    operator_delete__(puVar4);
  }
  local_4 = local_10;
  CFastString::SetString((CFastString *)(this + 0x18),(CFastStringInt *)&local_4,in_stack_ffffffe0);
  if (local_c != PTR_DAT_00bbf7d8) {
    puVar4 = local_c + -1;
    if ((local_c[-1] & 0x80) != 0) {
      puVar4 = local_c + -4;
    }
    operator_delete__(puVar4);
  }
  ExceptionList = in_stack_00000008;
  return;
}
}

// =================================================
// Function: CSystemConfig::SetDefaultsAdvertising
// =================================================
void __thiscall CSystemConfig::SetDefaultsAdvertising(CSystemConfig *this,CSystemConfig *param_1)
{
{
  *(undefined4 *)(this + 0x184) = 1;
  *(undefined4 *)(this + 0x18c) = 0;
  *(undefined4 *)(this + 0x188) = 0;
  return;
}
}

// =================================================
// Function: CSystemConfig::SetDefaultsAll
// =================================================
void __thiscall CSystemConfig::SetDefaultsAll(CSystemConfig *this,CSystemConfig *param_1)
{
{
  CSystemConfig *this_00;
  CSystemConfig *this_01;
  CSystemConfig *unaff_ESI;
  CSystemConfigDisplay *unaff_retaddr;
  CSystemConfig *in_stack_00000008;
  CSystemConfig *in_stack_0000000c;
  CSystemConfig *in_stack_00000010;
  CSystemConfig *in_stack_00000014;
  CSystemConfig *in_stack_00000018;
  CSystemConfig *in_stack_0000001c;
  CSystemConfig *in_stack_00000020;
  CSystemConfig *in_stack_00000024;
  CSystemConfig *in_stack_00000030;
  
  SetDefaultLanguage(this,unaff_ESI);
  SetDefaultsDisplay(this,unaff_retaddr);
  SetDefaultsNetwork(this,param_1);
  SetDefaultsFileTransfer(this,in_stack_00000008);
  SetDefaultsAudio(this,in_stack_0000000c);
  SetDefaultsGameCommon(this,in_stack_00000010);
  SetDefaultsVsk3(this,in_stack_00000014);
  SetDefaultsTM(this,in_stack_00000018);
  SetDefaultsInputs(this,in_stack_0000001c);
  SetDefaultsAdvertising(this_00,in_stack_00000020);
  SetDefaultsLauncherSettings(this_01,in_stack_00000024);
  SetDefaultsParentalLock(this,in_stack_00000030);
  return;
}
}

// =================================================
// Function: CSystemConfig::SetDefaultsAudio
// =================================================
void __thiscall CSystemConfig::SetDefaultsAudio(CSystemConfig *this,CSystemConfig *param_1)
{
{
  SStringParam *unaff_EDI;
  char *local_8;
  undefined4 local_4;
  
  *(undefined4 *)(this + 0x100) = 0x3f800000;
  *(undefined4 *)(this + 0x104) = 0x3f800000;
  *(undefined4 *)(this + 0xfc) = 1;
  *(undefined4 *)(this + 0x10c) = 0;
  *(undefined4 *)(this + 0x108) = 0;
  local_8 = "|Device|Default";
  local_4 = 0xf;
  CFastString::SetString((CFastString *)(this + 0x110),(CFastStringInt *)&local_8,unaff_EDI);
  *(undefined4 *)(this + 0x11c) = 0;
  *(undefined4 *)(this + 0x124) = 0;
  *(undefined4 *)(this + 0x120) = 0;
  *(undefined4 *)(this + 0x118) = 1;
  *(undefined4 *)(this + 0x128) = 1;
  return;
}
}

// =================================================
// Function: CSystemConfig::SetDefaultsDisplay
// =================================================
void __thiscall CSystemConfig::SetDefaultsDisplay(CSystemConfig *this,CSystemConfigDisplay *param_1)
{
{
  if ((*(int *)(this + 0x20) == 0) &&
     (*(CSystemConfigDisplay **)(this + 0x24) != (CSystemConfigDisplay *)0x0)) {
    CSystemConfigDisplay::SetDefaultsDisplay(*(CSystemConfigDisplay **)(this + 0x24),param_1);
    return;
  }
  return;
}
}

// =================================================
// Function: CSystemConfig::SetDefaultsFileTransfer
// =================================================
void __thiscall CSystemConfig::SetDefaultsFileTransfer(CSystemConfig *this,CSystemConfig *param_1)
{
{
  *(undefined4 *)(this + 200) = 1;
  *(undefined4 *)(this + 0xcc) = 1;
  *(undefined4 *)(this + 0xd4) = 1;
  *(undefined4 *)(this + 0xd8) = 1;
  *(undefined4 *)(this + 0xdc) = 1;
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xd0) = 0x25800000;
  CFastString::SetString
            ((CFastString *)(this + 0xe4),(CFastStringInt *)&stack0xfffffff8,
             (SStringParam *)&DAT_00b2c878);
  return;
}
}

// =================================================
// Function: CSystemConfig::SetDefaultsGameCommon
// =================================================
void __thiscall CSystemConfig::SetDefaultsGameCommon(CSystemConfig *this,CSystemConfig *param_1)
{
{
  SStringParam *unaff_EDI;
  CGameScoresVersion *in_stack_00000008;
  undefined1 *local_8;
  undefined4 local_4;
  
  *(undefined4 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x140) = 3;
  *(undefined4 *)(this + 0x13c) = 2;
  local_8 = &DAT_00b2c878;
  local_4 = 0;
  CFastStringInt::SetString(this + 300,(CFastStringInt *)&local_8,unaff_EDI);
  *(undefined4 *)(this + 0xf8) = 0;
  SSystemTime::SetInvalid(this + 0x80,in_stack_00000008);
  return;
}
}

// =================================================
// Function: CSystemConfig::SetDefaultsInputs
// =================================================
void __thiscall CSystemConfig::SetDefaultsInputs(CSystemConfig *this,CSystemConfig *param_1)
{
{
  *(undefined4 *)(this + 0x174) = 0;
  *(undefined4 *)(this + 0x180) = 0;
  *(undefined4 *)(this + 0x178) = 1;
  *(undefined4 *)(this + 0x17c) = 1;
  return;
}
}

// =================================================
// Function: CSystemConfig::SetDefaultsLauncherSettings
// =================================================
void __thiscall
CSystemConfig::SetDefaultsLauncherSettings(CSystemConfig *this,CSystemConfig *param_1)
{
{
  SStringParam *unaff_ESI;
  SStringParam *pSVar1;
  undefined1 *puVar2;
  
  pSVar1 = (SStringParam *)&DAT_00b2c878;
  CFastString::SetString((CFastString *)(this + 400),(CFastStringInt *)&stack0xfffffff8,unaff_ESI);
  puVar2 = &DAT_00b2c878;
  CFastString::SetString((CFastString *)(this + 0x198),(CFastStringInt *)&stack0xfffffffc,pSVar1);
  *(undefined4 *)(this + 0x1a0) = 0x15180;
  SSystemTime::SetFromFileTime(this + 0x1a4,(SSystemTime *)0x0,ZEXT48(puVar2));
  return;
}
}

// =================================================
// Function: CSystemConfig::SetDefaultsNetwork
// =================================================
void __thiscall CSystemConfig::SetDefaultsNetwork(CSystemConfig *this,CSystemConfig *param_1)
{
{
  SStringParam *unaff_ESI;
  SStringParam *unaff_EDI;
  undefined4 uStack00000008;
  char *pcVar1;
  SStringParam *pSVar2;
  
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x4c) = 0x92e;
  *(undefined4 *)(this + 0x50) = 0xd7a;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x58) = 10;
  *(undefined4 *)(this + 0x5c) = 0;
  pcVar1 = "0.0.0.0:0";
  CFastString::SetString((CFastString *)(this + 0x60),(CFastStringInt *)&stack0xfffffff8,unaff_EDI);
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x30) = 0x10000;
  *(undefined4 *)(this + 0x34) = 0x100000;
  *(undefined4 *)(this + 0x6c) = 1;
  pSVar2 = (SStringParam *)&DAT_00b2c878;
  CFastString::SetString((CFastString *)(this + 0x70),(CFastStringInt *)&stack0xfffffffc,unaff_ESI);
  param_1 = (CSystemConfig *)0x0;
  CFastString::SetString
            ((CFastString *)(this + 0x78),(CFastStringInt *)&stack0x00000000,(SStringParam *)pcVar1)
  ;
  *(undefined4 *)(this + 0xf4) = 1;
  param_1 = (CSystemConfig *)&DAT_00b2c878;
  uStack00000008 = 0;
  CFastString::SetString((CFastString *)(this + 0xec),(CFastStringInt *)&param_1,pSVar2);
  return;
}
}

// =================================================
// Function: CSystemConfig::SetDefaultsParentalLock
// =================================================
void __thiscall CSystemConfig::SetDefaultsParentalLock(CSystemConfig *this,CSystemConfig *param_1)
{
{
  CGameScoresVersion *unaff_ESI;
  
  SSystemTime::SetInvalid(this + 0x1ac,unaff_ESI);
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0x1c0) = 0;
  *(undefined4 *)(this + 0x1c4) = 0;
  *(undefined4 *)(this + 0x1c8) = 0;
  return;
}
}

// =================================================
// Function: CSystemConfig::SetDefaultsTM
// =================================================
void __thiscall CSystemConfig::SetDefaultsTM(CSystemConfig *this,CSystemConfig *param_1)
{
{
  *(undefined4 *)(this + 0x158) = 1;
  *(undefined4 *)(this + 0x15c) = 1;
  *(undefined4 *)(this + 0x160) = 1;
  *(undefined4 *)(this + 0x164) = 0;
  *(undefined4 *)(this + 0x168) = 1;
  *(undefined4 *)(this + 0x170) = 2;
  *(undefined4 *)(this + 0x16c) = 0xffffffff;
  SetAutoOrPresetTM(this,param_1);
  return;
}
}

// =================================================
// Function: CSystemConfig::SetDefaultsVsk3
// =================================================
void __thiscall CSystemConfig::SetDefaultsVsk3(CSystemConfig *this,CSystemConfig *param_1)
{
{
  *(undefined4 *)(this + 0x148) = 1;
  *(undefined4 *)(this + 0x14c) = 1;
  *(undefined4 *)(this + 0x150) = 1;
  *(undefined4 *)(this + 0x154) = 1;
  SetAutoOrPresetVsk3(this,param_1);
  return;
}
}

// =================================================
// Function: CSystemConfig::SetNetworkIsFireWallTested
// =================================================
void __thiscall
CSystemConfig::SetNetworkIsFireWallTested(CSystemConfig *this,CSystemConfig *param_1)
{
{
  int iVar1;
  CSystemConfig *unaff_ESI;
  CSystemConfig *pCVar2;
  
  pCVar2 = this;
  iVar1 = GetNetworkIsFireWallTested(this,unaff_ESI);
  if (iVar1 == 0) {
    CSystemEngine::GetExeCheckSum();
    CFastBuffer<class_CNetFileTransferUpload*>::InsertElemAt
              (this + 0x88,(CFastBuffer<struct_CInputDevice::SRumble> *)0x0,(ulong)&stack0x00000000,
               (SRumble *)pCVar2);
  }
  return;
}
}

