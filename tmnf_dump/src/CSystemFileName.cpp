// Class implementation: CSystemFileName

// =================================================
// Function: CSystemFileName::ConcatDirectory
// =================================================
void __cdecl CSystemFileName::ConcatDirectory(CFastStringInt *param_1,CFastStringInt *param_2)
{
{
  SStringParam *in_stack_ffffffe0;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  local_14 = *(int *)param_2;
  local_18 = *(int *)(param_2 + 4);
  if (*(short *)(local_18 + -2 + local_14 * 2) != 0x5c) {
    local_c = *(int *)(param_1 + 4);
    local_8 = *(int *)param_1;
    local_10 = 0;
    local_4 = 0;
    CFastStringInt::SetCompose
              (param_1,(CFastStringInt *)&stack0xffffffe0,(SStringParam *)&local_c,
               (SStringParamInt *)&local_18);
    return;
  }
  local_4 = 0;
  local_c = local_18;
  local_8 = local_14;
  CFastStringInt::Concat(param_1,(CFastStringInt *)&local_c,in_stack_ffffffe0);
  return;
}
}

// =================================================
// Function: CSystemFileName::ConvertToSystemName
// =================================================
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl
CSystemFileName::ConvertToSystemName
          (CFastStringInt *param_1,CFastString *param_2,int param_3,EMode param_4)
{
{
  CFastString *pCVar1;
  int iVar2;
  CSystemFile *pCVar3;
  CFastStringInt *in_stack_ffffefb4;
  CFastString *in_stack_ffffefb8;
  CSystemFile local_1034 [4124];
  void *local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a832cb;
  local_c = ExceptionList;
  uStack_10 = 0x436298;
  pCVar1 = (CFastString *)(DAT_00cca150 ^ (uint)&stack0xffffefc4);
  ExceptionList = &local_c;
  if (param_3 != 0) {
    if ((param_4 & 2) != 0) {
      in_stack_ffffefb8 = (CFastString *)0x4362d4;
      iVar2 = CSystemManagerFile::IsFileExists(param_1);
      if (iVar2 == 0) {
        CSystemFile::CSystemFile(local_1034,(CSystemFile *)pCVar1);
        in_stack_ffffefb8 = (CFastString *)0x0;
        in_stack_ffffefb4 = (CFastStringInt *)0x0;
        pCVar3 = (CSystemFile *)0x2;
        CSystemFile::Open((_D3DXINCLUDE_TYPE)param_1,(char *)0x2,(void *)0x0,(void **)0x0,
                          (uint *)0x0);
        CSystemFile::Close((CSystemFile *)&stack0xffffefb8,(CClassicLog *)param_1);
        local_14 = 0xffffffff;
        CSystemFile::~CSystemFile((CSystemFile *)&stack0xffffefbc,pCVar3);
      }
    }
    GetANSIPathName(in_stack_ffffefb4,in_stack_ffffefb8);
    ExceptionList = local_18;
    return;
  }
  CFastStringInt::GetUtf8OrAscii(param_1,(CFastStringInt *)param_2,pCVar1);
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CSystemFileName::ExtractFullPathName
// =================================================
void __cdecl CSystemFileName::ExtractFullPathName(CFastStringInt *param_1,CFastStringInt *param_2)
{
{
  SStringParam *pSVar1;
  undefined *puVar2;
  undefined4 local_20;
  undefined *local_1c;
  undefined *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00a82bf8;
  local_c = ExceptionList;
  pSVar1 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  ExceptionList = &local_c;
  local_20 = 0;
  local_1c = PTR_DAT_00bbf7dc;
  local_4 = 0;
  SplitPath(param_1,param_2,(CFastStringInt *)&local_20,(CFastStringInt *)0x0,(CFastStringInt *)0x0,
            (CFastStringInt *)0x0);
  local_14 = local_20;
  local_18 = local_1c;
  local_10 = 0;
  CFastStringInt::Concat(param_2,(CFastStringInt *)&local_18,pSVar1);
  if (local_18 != PTR_DAT_00bbf7dc) {
    if ((local_18[-1] & 0x80) == 0) {
      puVar2 = local_18 + -2;
    }
    else {
      puVar2 = local_18 + -4;
    }
    operator_delete__(puVar2);
  }
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CSystemFileName::ExtractShortBaseName
// =================================================
void __cdecl CSystemFileName::ExtractShortBaseName(CFastStringInt *param_1,CFastStringInt *param_2)
{
{
  SplitPath(param_1,(CFastStringInt *)0x0,(CFastStringInt *)0x0,param_2,(CFastStringInt *)0x0,
            (CFastStringInt *)0x0);
  return;
}
}

// =================================================
// Function: CSystemFileName::ExtractShortName
// =================================================
void __cdecl CSystemFileName::ExtractShortName(CFastStringInt *param_1,CFastStringInt *param_2)
{
{
  SStringParam *pSVar1;
  undefined *puVar2;
  undefined4 local_20;
  undefined *local_1c;
  undefined *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00a82bc8;
  local_c = ExceptionList;
  pSVar1 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  ExceptionList = &local_c;
  local_20 = 0;
  local_1c = PTR_DAT_00bbf7dc;
  local_4 = 0;
  SplitPath(param_1,(CFastStringInt *)0x0,(CFastStringInt *)0x0,param_2,(CFastStringInt *)&local_20,
            (CFastStringInt *)0x0);
  local_14 = local_20;
  local_18 = local_1c;
  local_10 = 0;
  CFastStringInt::Concat(param_2,(CFastStringInt *)&local_18,pSVar1);
  if (local_18 != PTR_DAT_00bbf7dc) {
    if ((local_18[-1] & 0x80) == 0) {
      puVar2 = local_18 + -2;
    }
    else {
      puVar2 = local_18 + -4;
    }
    operator_delete__(puVar2);
  }
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CSystemFileName::FixFileName
// =================================================
void __cdecl CSystemFileName::FixFileName(CFastStringInt *param_1,ulong param_2)
{
{
  bool bVar1;
  bool bVar2;
  CFastStringInt *this;
  CFastStringBase<wchar_t> *pCVar3;
  short sVar4;
  int extraout_EAX;
  void *pvVar5;
  int extraout_EAX_00;
  undefined *puVar6;
  short sVar7;
  ulong *unaff_EBP;
  SOldChars *unaff_ESI;
  short *psVar8;
  int iVar9;
  SStringParam *unaff_EDI;
  CFastStringInt *in_stack_0000000c;
  int iStack00000010;
  SStringParam *pSVar10;
  CFastStringInt *pCVar11;
  undefined *puStack_40;
  CFastStringBase<wchar_t> *local_3c;
  short *local_38;
  undefined *local_34;
  undefined *local_30;
  int local_2c;
  undefined *local_28;
  uint local_24;
  void *local_20;
  uint local_1c;
  void *local_18;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  this = param_1;
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a82ca0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_24 = param_2 & 1;
  local_20 = (void *)(param_2 & 2);
  local_28 = (undefined *)(param_2 & 4);
  local_10 = (void *)(param_2 & 8);
  local_18 = (void *)(param_2 & 0x10);
  local_1c = param_2 & 0x20;
  if (*(int *)param_1 != 0) {
    if ((param_2 & 0x40) != 0) {
      local_34 = (undefined *)0x0;
      local_30 = PTR_DAT_00bbf7d8;
      local_4 = (void *)0x0;
      CFastStringInt::GetEscaped
                (param_1,(CFastStringInt *)&local_34,
                 (CFastString *)(DAT_00cca150 ^ (uint)&stack0xffffffac));
      local_3c = (CFastStringBase<wchar_t> *)local_2c;
      local_38 = (short *)local_30;
      CFastStringInt::SetString(param_1,(CFastStringInt *)&local_3c,unaff_EDI);
      param_1 = (CFastStringInt *)0xffffffff;
      if (local_28 != PTR_DAT_00bbf7d8) {
        puVar6 = local_28 + -1;
        if ((local_28[-1] & 0x80) != 0) {
          puVar6 = local_28 + -4;
        }
        operator_delete__(puVar6);
      }
    }
    psVar8 = *(short **)(this + 4);
    sVar4 = *psVar8;
    iStack00000010 = 2;
    bVar1 = true;
    local_3c = (CFastStringBase<wchar_t> *)0x0;
    local_2c = 0;
    local_38 = psVar8;
    while (sVar4 != 0) {
      psVar8 = psVar8 + 1;
      sVar7 = *psVar8;
      if (sVar4 == 0x2f) {
        sVar4 = 0x5c;
      }
      if (sVar7 == 0x2f) {
        sVar7 = 0x5c;
      }
      bVar2 = false;
      if ((((iStack00000010 != 0) && (sVar4 != 0x5c)) && (sVar4 != 0x3a)) && (sVar7 != 0x3a)) {
        iStack00000010 = 0;
      }
      switch(sVar4) {
      case 0x22:
      case 0x2a:
      case 0x3c:
      case 0x3e:
      case 0x7c:
        goto switchD_0042edc2_caseD_22;
      case 0x2e:
        if (bVar1) {
          if (sVar7 == 0x2e) {
            local_2c = 1;
          }
          else if (sVar7 == 0x5c) {
            local_2c = 1;
          }
        }
        break;
      case 0x3a:
        pvVar5 = local_20;
        if (iStack00000010 != 0) goto LAB_0042ee43;
        goto switchD_0042edc2_caseD_22;
      case 0x3f:
        pvVar5 = local_10;
LAB_0042ee43:
        if (pvVar5 == (void *)0x0) goto switchD_0042edc2_caseD_22;
        break;
      case 0x5c:
        if ((iStack00000010 == 0) || (local_20 != (void *)0x0)) {
          if ((local_18 == (void *)0x0) && ((local_1c == 0 || (sVar7 != 0))))
          goto switchD_0042edc2_caseD_22;
          if ((sVar7 != 0x5c) || ((iStack00000010 != 0 && (local_14 != 0)))) break;
        }
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0xc:
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x10:
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1a:
      case 0x1b:
      case 0x1c:
      case 0x1d:
      case 0x1e:
      case 0x1f:
      case 0x7f:
        bVar2 = true;
      }
      if ((sVar4 == 0x5c) && (sVar7 != 0x5c)) {
        bVar1 = true;
      }
      else {
LAB_0042ee4a:
        bVar1 = false;
      }
      if (iStack00000010 != 0) {
        iStack00000010 = iStack00000010 + -1;
      }
      if (!bVar2) {
        *local_38 = sVar4;
        local_38 = local_38 + 1;
        local_3c = local_3c + 1;
      }
      sVar4 = *psVar8;
    }
    *local_38 = 0;
    if ((CFastStringBase<wchar_t> *)0x102 < local_3c) {
      local_3c = (CFastStringBase<wchar_t> *)0x102;
    }
    pCVar3 = local_3c;
    if (local_3c != *(CFastStringBase<wchar_t> **)this) {
      CFastStringBase<wchar_t>::AllocAtLeast(this,local_3c,1,0,unaff_ESI);
      *(undefined2 *)(*(int *)(this + 4) + (int)pCVar3 * 2) = 0;
      *(CFastStringBase<wchar_t> **)this = pCVar3;
    }
    if (*(int *)this != 0) {
      if ((local_1c != 0) && (*(short *)(*(int *)(this + 4) + -2 + *(int *)this * 2) != 0x5c)) {
        CFastStringInt::Concat(this,(CFastStringInt *)&DAT_0000005c,(SStringParam *)unaff_ESI);
      }
      if (local_2c != 0) {
        local_28 = *(undefined **)this;
        local_2c = *(int *)(this + 4);
        local_24 = 0;
        CFastStringInt::SetString
                  (&DAT_00d71d60,(CFastStringInt *)&local_2c,(SStringParam *)unaff_ESI);
        iVar9 = 0;
        if (*(int *)this != 0) {
          *(undefined4 *)this = 0;
          **(undefined2 **)(this + 4) = 0;
        }
        local_c = (void *)0x0;
        puStack_8 = PTR_DAT_00bbf7dc;
        pCVar11 = (CFastStringInt *)&DAT_00d71d60;
        pSVar10 = (SStringParam *)0x42ef47;
        SplitFirstDirectory((CFastStringInt *)&DAT_00d71d60,(CFastStringInt *)&local_c,unaff_EBP);
        pvVar5 = local_c;
        while (pvVar5 != (void *)0x0) {
          local_34 = &DAT_00b30508;
          local_30 = (undefined *)0x2;
          local_2c = 1;
          if ((pvVar5 != (void *)0x2) ||
             (CFastStringInt::Compare
                        (&local_18,(SParam_Fids *)&local_34,(SParam *)0x0,(int *)pSVar10,
                         (int *)pCVar11), pvVar5 = local_10, extraout_EAX != 0)) {
            puStack_40 = &DAT_00b30500;
            local_3c = (CFastStringBase<wchar_t> *)0x3;
            local_38 = (short *)0x1;
            if ((pvVar5 == (void *)0x3) &&
               (CFastStringInt::Compare
                          (&local_18,(SParam_Fids *)&puStack_40,(SParam *)0x0,(int *)pSVar10,
                           (int *)pCVar11), extraout_EAX_00 == 0)) {
              iVar9 = iVar9 + -1;
              if (iVar9 < 0) {
                if (puStack_8 != (undefined *)0x0) {
                  pCVar11 = (CFastStringInt *)&local_10;
                  pSVar10 = (SStringParam *)in_stack_0000000c;
                  goto LAB_0042f008;
                }
              }
              else {
                pCVar11 = (CFastStringInt *)&local_10;
                pSVar10 = (SStringParam *)in_stack_0000000c;
                SplitLastDirectory(in_stack_0000000c,pCVar11);
              }
            }
            else {
              iVar9 = iVar9 + 1;
              pSVar10 = (SStringParam *)param_1;
LAB_0042f008:
              ConcatDirectory((CFastStringInt *)pSVar10,pCVar11);
            }
          }
          SplitFirstDirectory((CFastStringInt *)&DAT_00d71d60,(CFastStringInt *)&local_18,
                              (ulong *)pSVar10);
          this = param_1;
          pvVar5 = local_18;
        }
        local_2c = 0;
        local_34 = (undefined *)DAT_00d71d64;
        local_30 = (undefined *)DAT_00d71d60;
        CFastStringInt::Concat(this,(CFastStringInt *)&local_34,pSVar10);
        CGameCtnApp::SNationConfig::~SNationConfig(&local_14,(SNationConfig *)pCVar11);
      }
    }
  }
  ExceptionList = local_4;
  return;
switchD_0042edc2_caseD_22:
  sVar4 = 0x5f;
  goto LAB_0042ee4a;
}
}

// =================================================
// Function: CSystemFileName::GetRelativeName
// =================================================
int __cdecl
CSystemFileName::GetRelativeName
          (CFastStringInt *param_1,CFastStringInt *param_2,CFastStringInt *param_3)
{
{
  int iVar1;
  void *this;
  void *this_00;
  ulong unaff_ESI;
  SStringParam *unaff_EDI;
  ulong uVar2;
  undefined4 local_8;
  SStringParam *local_4;
  
  uVar2 = *(ulong *)(param_1 + 4);
  local_8 = *(undefined4 *)param_1;
  local_4 = (SStringParam *)0x0;
  CFastStringInt::SetString(param_3,(CFastStringInt *)&stack0xfffffff4,unaff_EDI);
  local_4 = *(SStringParam **)param_3;
  local_8 = *(undefined4 *)(param_3 + 4);
  iVar1 = CFastStringInt::CompareNoCase(param_3,(CFastStringInt *)&local_8,local_4,unaff_ESI);
  if (iVar1 != 0) {
    Normalize(this,(GmQuat *)param_3);
    return 0;
  }
  CFastStringInt::TruncBeforeIndex(param_3,(CFastStringInt *)(*(int *)param_3 + -1),uVar2);
  Normalize(this_00,(GmQuat *)param_3);
  return 1;
}
}

// =================================================
// Function: CSystemFileName::IsDirectoryName
// =================================================
int __cdecl CSystemFileName::IsDirectoryName(CFastStringInt *param_1)
{
{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)param_1;
  if (uVar1 == 0) {
    return 1;
  }
  if ((1 < uVar1) && (*(short *)(*(int *)(param_1 + 4) + -2 + uVar1 * 2) == 0x5c)) {
    iVar2 = IsNormalized(param_1);
    return (uint)(iVar2 != 0);
  }
  return 0;
}
}

// =================================================
// Function: CSystemFileName::IsExtension
// =================================================
int __cdecl CSystemFileName::IsExtension(CFastStringInt *param_1,char *param_2)
{
{
  int iVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  pcVar3 = param_2;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  uVar4 = (int)pcVar3 - (int)(param_2 + 1);
  if (*(uint *)param_1 <= uVar4) {
    return 0;
  }
  uVar7 = 0;
  iVar1 = *(int *)(param_1 + 4) + (*(uint *)param_1 - uVar4) * 2;
  if (uVar4 != 0) {
    do {
      if (0x7f < *(ushort *)(iVar1 + uVar7 * 2)) {
        return 0;
      }
      iVar5 = _tolower((int)param_2[uVar7]);
      iVar6 = _tolower((int)*(char *)(iVar1 + uVar7 * 2));
      if ((char)iVar5 != (char)iVar6) {
        return 0;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar4);
  }
  return 1;
}
}

// =================================================
// Function: CSystemFileName::IsExtensionGbx
// =================================================
int __cdecl CSystemFileName::IsExtensionGbx(CFastStringInt *param_1)
{
{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)param_1;
  if (((((4 < uVar2) &&
        (iVar1 = *(int *)(param_1 + 4) + -8 + uVar2 * 2,
        *(short *)(*(int *)(param_1 + 4) + -8 + uVar2 * 2) == 0x2e)) &&
       ((*(short *)(iVar1 + 2) == 0x47 || (*(short *)(iVar1 + 2) == 0x67)))) &&
      ((*(short *)(iVar1 + 4) == 0x42 || (*(short *)(iVar1 + 4) == 0x62)))) &&
     ((*(short *)(iVar1 + 6) == 0x58 || (*(short *)(iVar1 + 6) == 0x78)))) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CSystemFileName::IsNormalized
// =================================================
int __cdecl CSystemFileName::IsNormalized(CFastStringInt *param_1)
{
{
  wchar_t *pwVar1;
  
  pwVar1 = _wcschr(*(wchar_t **)(param_1 + 4),L'/');
  return (uint)(pwVar1 == (wchar_t *)0x0);
}
}

// =================================================
// Function: CSystemFileName::IsValidShortFileName
// =================================================
int __cdecl CSystemFileName::IsValidShortFileName(CFastStringInt *param_1)
{
{
  short sVar1;
  short *psVar2;
  
  psVar2 = *(short **)(param_1 + 4);
  do {
    sVar1 = *psVar2;
    switch(sVar1) {
    case 0x22:
    case 0x2a:
    case 0x2f:
    case 0x3a:
    case 0x3c:
    case 0x3e:
    case 0x3f:
    case 0x5c:
    case 0x7c:
      return 0;
    }
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  return 1;
}
}

// =================================================
// Function: CSystemFileName::Normalize
// =================================================
void __thiscall CSystemFileName::Normalize(void *this,GmQuat *param_1)
{
{
  int in_stack_00000008;
  
  FixFileName((CFastStringInt *)param_1,in_stack_00000008 != 0 | 0x16);
  return;
}
}

// =================================================
// Function: CSystemFileName::SplitFirstDirectory
// =================================================
int __cdecl
CSystemFileName::SplitFirstDirectory(CFastStringInt *param_1,CFastStringInt *param_2,ulong *param_3)
{
{
  wchar_t *pwVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  SStringParam *unaff_EDI;
  wchar_t *local_c;
  int local_8;
  undefined4 local_4;
  
  pwVar1 = (wchar_t *)(*(int *)(param_1 + 4) + *param_3 * 2);
  pwVar3 = pwVar1;
  if (((*param_3 == 0) && (*pwVar1 == L'\\')) && (pwVar1[1] == L'\\')) {
    pwVar3 = pwVar1 + 2;
  }
  pwVar3 = _wcschr(pwVar3,L'\\');
  local_c = pwVar1;
  if (pwVar3 != (wchar_t *)0x0) {
    local_8 = ((int)pwVar3 - (int)pwVar1 >> 1) + 1;
    local_4 = 1;
    CFastStringInt::SetString(param_2,(CFastStringInt *)&local_c,unaff_EDI);
    pwVar4 = pwVar3 + 1;
    wVar2 = pwVar3[1];
    while (wVar2 == L'\\') {
      pwVar4 = pwVar4 + 1;
      wVar2 = *pwVar4;
    }
    *param_3 = *param_3 + ((int)pwVar4 - (int)pwVar1 >> 1);
    return 1;
  }
  if (pwVar1 == (wchar_t *)0x0) {
    local_8 = 0;
  }
  else {
    pwVar3 = pwVar1;
    do {
      wVar2 = *pwVar3;
      pwVar3 = pwVar3 + 1;
    } while (wVar2 != L'\0');
    local_8 = (int)pwVar3 - (int)(pwVar1 + 1) >> 1;
  }
  local_4 = 1;
  CFastStringInt::SetString(param_2,(CFastStringInt *)&local_c,unaff_EDI);
  return 0;
}
}

// =================================================
// Function: CSystemFileName::SplitLastDirectory
// =================================================
void __cdecl CSystemFileName::SplitLastDirectory(CFastStringInt *param_1,CFastStringInt *param_2)
{
{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  ulong unaff_EBX;
  SStringParam *unaff_EBP;
  CFastStringBase<wchar_t> *unaff_ESI;
  SStringParam *unaff_EDI;
  int iVar4;
  void *in_stack_0000000c;
  undefined1 *local_c;
  int local_8 [2];
  
  local_8[0] = *(int *)param_1;
  if (local_8[0] == 0) {
    local_c = &DAT_00b2c878;
    CFastStringInt::SetString(param_2,(CFastStringInt *)&local_c,unaff_EBP);
    return;
  }
  pwVar2 = *(wchar_t **)(param_1 + 4);
  iVar4 = local_8[0] + -1;
  wVar1 = pwVar2[local_8[0] + -1];
  while (wVar1 == L'\\') {
    pwVar2[iVar4] = L'\0';
    iVar4 = iVar4 + -1;
    wVar1 = pwVar2[iVar4];
  }
  pwVar3 = _wcsrchr(pwVar2,L'\\');
  pwVar2[iVar4 + 1] = L'\\';
  if (pwVar3 != (wchar_t *)0x0) {
    SStringParamInt::SStringParamInt(&local_c,(SStringParamInt *)(pwVar3 + 1),(wchar_t *)unaff_ESI);
    CFastStringInt::SetString(in_stack_0000000c,(CFastStringInt *)local_8,unaff_EDI);
    wVar1 = *pwVar3;
    while ((wVar1 == L'\\' && (pwVar2 < pwVar3))) {
      pwVar3 = pwVar3 + -1;
      wVar1 = *pwVar3;
    }
    CFastStringInt::TruncAfterIndex
              (param_1,(CFastStringInt *)(((int)pwVar3 - (int)pwVar2 >> 1) + 2),unaff_EBX);
    return;
  }
  CFastStringBase<wchar_t>::CopyAndClear(param_2,(CFastStringBase<wchar_t> *)param_1,unaff_ESI);
  return;
}
}

// =================================================
// Function: CSystemFileName::SplitPath
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
CSystemFileName::SplitPath
          (CFastStringInt *param_1,CFastStringInt *param_2,CFastStringInt *param_3,
          CFastStringInt *param_4,CFastStringInt *param_5,CFastStringInt *param_6)
{
{
  wchar_t wVar1;
  wchar_t wVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  CFastStringInt *pCVar5;
  wchar_t *pwVar6;
  CFastStringInt *pCVar7;
  int iVar8;
  SStringParam *unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_GxVertex2> *pCVar9;
  CFastStringInt *pCVar10;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  void *in_stack_0000001c;
  void *in_stack_00000020;
  void *in_stack_00000024;
  void *in_stack_00000028;
  SStringParam *in_stack_fffffff4;
  
  pCVar5 = param_1;
  pCVar3 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_1;
  pCVar9 = (CFastBuffer<class_GxVertex2> *)(pCVar3 + 1);
  if ((_DAT_00d5564c & 1) == 0) {
    _DAT_00d5564c = _DAT_00d5564c | 1;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&DAT_00d55640,unaff_EDI);
    _atexit(`public:_static_void___cdecl_CSystemFileName::
            SplitPath(class_CFastStringInt_const&,class_CSystemFileName*,class_CSystemFileName*,class_CSystemFileName*,class_CSystemFileName*,class_CSystemFileName*)'
            ::__l2::_dynamic_atexit_destructor_for__PathBuf__);
  }
  CFastBuffer<wchar_t>::AllocSetCount(&DAT_00d55640,pCVar9,unaff_ESI);
  _memmove(DAT_00d55644,*(void **)(pCVar5 + 4),(int)pCVar9 * 2);
  pSVar4 = CFastBuffer<unsigned_short>::operator[](&DAT_00d55640,pCVar3,unaff_EBP);
  *(undefined2 *)pSVar4 = 0;
  pCVar7 = DAT_00d55644;
  wVar1 = *(wchar_t *)DAT_00d55644;
  pCVar5 = DAT_00d55644;
  while (wVar1 != L'\0') {
    if (*(wchar_t *)pCVar5 == L'/') {
      *(wchar_t *)pCVar5 = L'\\';
    }
    pCVar5 = pCVar5 + 2;
    wVar1 = *(wchar_t *)pCVar5;
  }
  pwVar6 = _wcschr((wchar_t *)pCVar7,L':');
  if (pwVar6 == (wchar_t *)0x0) {
    pCVar5 = pCVar7;
    if (param_5 != (CFastStringInt *)0x0) {
      param_1 = (CFastStringInt *)0x0;
      CFastStringInt::SetString(param_5,(CFastStringInt *)&stack0x00000000,unaff_EBX);
    }
  }
  else {
    pCVar5 = (CFastStringInt *)(pwVar6 + 1);
    if (param_5 != (CFastStringInt *)0x0) {
      param_1 = (CFastStringInt *)((int)pCVar5 - (int)pCVar7 >> 1);
      param_2 = (CFastStringInt *)0x1;
      CFastStringInt::SetString(param_5,(CFastStringInt *)&stack0x00000000,unaff_EBX);
    }
  }
  pwVar6 = _wcsrchr((wchar_t *)pCVar5,L'\\');
  if ((pwVar6 == (wchar_t *)0x0) &&
     (pwVar6 = _wcschr((wchar_t *)pCVar5,L':'), pwVar6 == (wchar_t *)0x0)) {
    pCVar7 = pCVar5;
    if (in_stack_0000001c != (void *)0x0) {
      param_1 = (CFastStringInt *)&DAT_00b2c878;
      param_2 = (CFastStringInt *)0x0;
      CFastStringInt::SetString(in_stack_0000001c,(CFastStringInt *)&param_1,in_stack_fffffff4);
    }
  }
  else {
    pCVar7 = (CFastStringInt *)(pwVar6 + 1);
    if (in_stack_0000001c != (void *)0x0) {
      wVar1 = *(wchar_t *)pCVar7;
      *(wchar_t *)pCVar7 = L'\0';
      if (pCVar5 == (CFastStringInt *)0x0) {
        param_2 = (CFastStringInt *)0x0;
      }
      else {
        pCVar10 = pCVar5;
        do {
          wVar2 = *(wchar_t *)pCVar10;
          pCVar10 = pCVar10 + 2;
        } while (wVar2 != L'\0');
        param_2 = (CFastStringInt *)((int)pCVar10 - (int)(pCVar5 + 2) >> 1);
      }
      param_3 = (CFastStringInt *)0x1;
      param_1 = pCVar5;
      CFastStringInt::SetString(in_stack_0000001c,(CFastStringInt *)&param_1,in_stack_fffffff4);
      *(wchar_t *)pCVar7 = wVar1;
    }
  }
  pCVar5 = (CFastStringInt *)_wcschr((wchar_t *)pCVar7,L'.');
  if (pCVar5 == (CFastStringInt *)0x0) {
    if (in_stack_00000020 != (void *)0x0) {
      if (pCVar7 == (CFastStringInt *)0x0) {
        param_2 = (CFastStringInt *)0x0;
      }
      else {
        pCVar5 = pCVar7;
        do {
          wVar1 = *(wchar_t *)pCVar5;
          pCVar5 = pCVar5 + 2;
        } while (wVar1 != L'\0');
        param_2 = (CFastStringInt *)((int)pCVar5 - (int)(pCVar7 + 2) >> 1);
      }
      param_3 = (CFastStringInt *)0x1;
      param_1 = pCVar7;
      CFastStringInt::SetString(in_stack_00000020,(CFastStringInt *)&param_1,in_stack_fffffff4);
    }
    if (in_stack_00000024 != (void *)0x0) {
      param_1 = (CFastStringInt *)&DAT_00b2c878;
      param_2 = (CFastStringInt *)0x0;
      CFastStringInt::SetString(in_stack_00000024,(CFastStringInt *)&param_1,in_stack_fffffff4);
    }
    if (in_stack_00000028 == (void *)0x0) {
      return;
    }
  }
  else {
    if (in_stack_00000020 != (void *)0x0) {
      *(wchar_t *)pCVar5 = L'\0';
      if (pCVar7 == (CFastStringInt *)0x0) {
        param_2 = (CFastStringInt *)0x0;
      }
      else {
        pCVar10 = pCVar7;
        do {
          wVar1 = *(wchar_t *)pCVar10;
          pCVar10 = pCVar10 + 2;
        } while (wVar1 != L'\0');
        param_2 = (CFastStringInt *)((int)pCVar10 - (int)(pCVar7 + 2) >> 1);
      }
      param_3 = (CFastStringInt *)0x1;
      param_1 = pCVar7;
      CFastStringInt::SetString(in_stack_00000020,(CFastStringInt *)&param_1,in_stack_fffffff4);
      *(wchar_t *)pCVar5 = L'.';
    }
    if (in_stack_00000024 != (void *)0x0) {
      pCVar7 = pCVar5;
      do {
        wVar1 = *(wchar_t *)pCVar7;
        pCVar7 = pCVar7 + 2;
      } while (wVar1 != L'\0');
      param_2 = (CFastStringInt *)((int)pCVar7 - (int)(pCVar5 + 2) >> 1);
      param_3 = (CFastStringInt *)0x1;
      param_1 = pCVar5;
      CFastStringInt::SetString(in_stack_00000024,(CFastStringInt *)&param_1,in_stack_fffffff4);
    }
    if (in_stack_00000028 == (void *)0x0) {
      return;
    }
    pwVar6 = _wcsrchr((wchar_t *)pCVar5,L'.');
    if ((pwVar6 != (wchar_t *)0x0) && (iVar8 = __wcsicmp(pwVar6,L".gbx"), iVar8 == 0)) {
      *pwVar6 = L'\0';
      pCVar7 = (CFastStringInt *)_wcsrchr((wchar_t *)pCVar5,L'.');
      if (pCVar7 != (CFastStringInt *)0x0) {
        pCVar5 = pCVar7;
      }
      param_1 = pCVar5 + 2;
      if (param_1 == (CFastStringInt *)0x0) {
        param_2 = (CFastStringInt *)0x0;
      }
      else {
        pCVar7 = param_1;
        do {
          wVar1 = *(wchar_t *)pCVar7;
          pCVar7 = pCVar7 + 2;
        } while (wVar1 != L'\0');
        param_2 = (CFastStringInt *)((int)pCVar7 - (int)(pCVar5 + 4) >> 1);
      }
      param_3 = (CFastStringInt *)0x1;
      CFastStringInt::SetString(in_stack_00000028,(CFastStringInt *)&param_1,in_stack_fffffff4);
      return;
    }
  }
  param_1 = (CFastStringInt *)&DAT_00b2c878;
  param_2 = (CFastStringInt *)0x0;
  CFastStringInt::SetString(in_stack_00000028,(CFastStringInt *)&param_1,in_stack_fffffff4);
  return;
}
}

// =================================================
// Function: CSystemFileName::StripExtension
// =================================================
void __cdecl CSystemFileName::StripExtension(CFastStringInt *param_1,CFastStringInt *param_2)
{
{
  undefined *puVar1;
  undefined *puStack_50;
  undefined *puStack_4c;
  undefined *puStack_48;
  undefined *puStack_44;
  undefined *puStack_40;
  undefined *puStack_3c;
  char *pcStack_38;
  undefined4 uStack_34;
  undefined *puStack_30;
  undefined *puStack_2c;
  undefined4 uStack_28;
  undefined *puStack_24;
  undefined *puStack_20;
  undefined4 uStack_1c;
  undefined *puStack_18;
  undefined *puStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &LAB_00a82c38;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  puStack_40 = (undefined *)0x0;
  puStack_3c = PTR_DAT_00bbf7dc;
  puStack_48 = (undefined *)0x0;
  puStack_44 = PTR_DAT_00bbf7dc;
  puStack_50 = (undefined *)0x0;
  puStack_4c = PTR_DAT_00bbf7dc;
  uStack_4 = 2;
  SplitPath(param_1,(CFastStringInt *)&puStack_40,(CFastStringInt *)&puStack_48,
            (CFastStringInt *)&puStack_50,(CFastStringInt *)0x0,(CFastStringInt *)0x0);
  puStack_30 = puStack_4c;
  puStack_2c = puStack_50;
  puStack_20 = puStack_48;
  puStack_24 = puStack_44;
  puStack_18 = puStack_3c;
  puStack_14 = puStack_40;
  uStack_28 = 0;
  uStack_1c = 0;
  pvStack_10 = (void *)0x0;
  pcStack_38 = "%1%2%3";
  uStack_34 = 6;
  CFastStringInt::SetCompose
            (param_2,(CFastStringInt *)&pcStack_38,(SStringParam *)&puStack_18,
             (SStringParamInt *)&puStack_24);
  if (puStack_50 != PTR_DAT_00bbf7dc) {
    puVar1 = puStack_50 + -4;
    if ((puStack_50[-1] & 0x80) == 0) {
      puVar1 = puStack_50 + -2;
    }
    operator_delete__(puVar1);
    puStack_50 = PTR_DAT_00bbf7dc;
  }
  if (puStack_48 != PTR_DAT_00bbf7dc) {
    puVar1 = puStack_48 + -4;
    if ((puStack_48[-1] & 0x80) == 0) {
      puVar1 = puStack_48 + -2;
    }
    operator_delete__(puVar1);
    puStack_4c = (undefined *)0x0;
    puStack_48 = PTR_DAT_00bbf7dc;
  }
  if (puStack_40 != PTR_DAT_00bbf7dc) {
    puVar1 = puStack_40 + -4;
    if ((puStack_40[-1] & 0x80) == 0) {
      puVar1 = puStack_40 + -2;
    }
    operator_delete__(puVar1);
  }
  ExceptionList = pvStack_10;
  return;
}
}

// =================================================
// Function: CSystemFileName::StripTrailingSlash
// =================================================
void __cdecl CSystemFileName::StripTrailingSlash(CFastStringInt *param_1)
{
{
  CFastStringBase<wchar_t> *pCVar1;
  short sVar2;
  int iVar3;
  SOldChars *unaff_EDI;
  
  iVar3 = *(int *)param_1;
  while( true ) {
    if (iVar3 == 0) {
      return;
    }
    sVar2 = *(short *)(*(int *)(param_1 + 4) + -2 + (int)*(CFastStringBase<wchar_t> **)param_1 * 2);
    if ((sVar2 != 0x5c) && (sVar2 != 0x2f)) break;
    pCVar1 = (CFastStringBase<wchar_t> *)(iVar3 + -1);
    if (pCVar1 != *(CFastStringBase<wchar_t> **)param_1) {
      CFastStringBase<wchar_t>::AllocAtLeast(param_1,pCVar1,1,0,unaff_EDI);
      *(undefined2 *)(*(int *)(param_1 + 4) + (int)pCVar1 * 2) = 0;
      *(CFastStringBase<wchar_t> **)param_1 = pCVar1;
    }
    iVar3 = *(int *)param_1;
  }
  return;
}
}

