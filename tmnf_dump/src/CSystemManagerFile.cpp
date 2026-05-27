// Class implementation: CSystemManagerFile

// =================================================
// Function: CSystemManagerFile::CSystemManagerFile
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSystemManagerFile::CSystemManagerFile(CSystemManagerFile *this,CSystemManagerFile *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  _DAT_00d543c0 = _DAT_00d543c0 | 3;
  return;
}
}

// =================================================
// Function: CSystemManagerFile::CompareFileTime
// =================================================
int __cdecl CSystemManagerFile::CompareFileTime(uint64 param_1,uint64 param_2)
{
{
  LONG LVar1;
  
  LVar1 = ::CompareFileTime((FILETIME *)&param_1,(FILETIME *)&param_2);
  return LVar1;
}
}

// =================================================
// Function: CSystemManagerFile::CopyFileW
// =================================================
int __cdecl
CSystemManagerFile::CopyFileW(CFastStringInt *param_1,CFastStringInt *param_2,int param_3)
{
{
  int iVar1;
  EMakeDir EVar2;
  BOOL BVar3;
  undefined *puVar4;
  undefined4 local_14;
  undefined *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00a831e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_14 = 0;
  local_10 = PTR_DAT_00bbf7dc;
  local_4 = 0;
  CSystemFileName::ExtractFullPathName(param_2,(CFastStringInt *)&local_14);
  iVar1 = IsFolderExists((CFastStringInt *)&local_14);
  if (((iVar1 != 0) || (EVar2 = MakeDir((CFastStringInt *)&local_14), EVar2 != 2)) &&
     (BVar3 = ::CopyFileW(*(LPCWSTR *)(param_1 + 4),*(LPCWSTR *)(param_2 + 4),param_3), BVar3 != 0))
  {
    if (local_10 != PTR_DAT_00bbf7dc) {
      if ((local_10[-1] & 0x80) == 0) {
        puVar4 = local_10 + -2;
      }
      else {
        puVar4 = local_10 + -4;
      }
      operator_delete__(puVar4);
    }
    ExceptionList = local_c;
    return 1;
  }
  if (local_10 != PTR_DAT_00bbf7dc) {
    if ((local_10[-1] & 0x80) != 0) {
      operator_delete__(local_10 + -4);
      ExceptionList = local_c;
      return 0;
    }
    operator_delete__(local_10 + -2);
  }
  ExceptionList = local_c;
  return 0;
}
}

// =================================================
// Function: CSystemManagerFile::CreateFidFile
// =================================================
CSystemFidFile * __thiscall
CSystemManagerFile::CreateFidFile(CSystemManagerFile *this,CSystemManagerFile *param_1)
{
{
  CSystemFidFile *pCVar1;
  
  pCVar1 = (CSystemFidFile *)(**(code **)(*(int *)this + 0x7c))();
  *(undefined4 *)(pCVar1 + 0x18) = 1;
  return pCVar1;
}
}

// =================================================
// Function: CSystemManagerFile::CreateFidFromType
// =================================================
CSystemFid * __thiscall
CSystemManagerFile::CreateFidFromType
          (CSystemManagerFile *this,CSystemManagerFile *param_1,EFidType param_2)
{
{
  CSystemFid *pCVar1;
  CSystemFidMemory *pCVar2;
  CSystemManagerFile *unaff_EBX;
  
  if (((uint)param_1 & 1) != 0) {
    pCVar1 = (CSystemFid *)(**(code **)(*(int *)this + 0x7c))();
    *(CSystemManagerFile **)(pCVar1 + 0x18) = param_1;
    return pCVar1;
  }
  pCVar2 = CreateFidMemory(this,unaff_EBX);
  return (CSystemFid *)pCVar2;
}
}

// =================================================
// Function: CSystemManagerFile::CreateFidMemory
// =================================================
CSystemFidMemory * __thiscall
CSystemManagerFile::CreateFidMemory(CSystemManagerFile *this,CSystemManagerFile *param_1)
{
{
  CSystemFidMemory *pCVar1;
  CSystemFidMemory *extraout_EAX;
  CSystemManagerFile *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a834ab;
  local_c = ExceptionList;
  pCVar1 = (CSystemFidMemory *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = this;
  local_10 = operator_new(0x7c);
  local_4 = 0;
  if (local_10 == (CSystemManagerFile *)0x0) {
    pCVar1 = (CSystemFidMemory *)0x0;
  }
  else {
    CSystemFidMemory::CSystemFidMemory((CSystemFidMemory *)local_10,pCVar1);
    pCVar1 = extraout_EAX;
  }
  *(undefined4 *)(pCVar1 + 0x18) = 8;
  ExceptionList = local_8;
  return pCVar1;
}
}

// =================================================
// Function: CSystemManagerFile::CreateFidResourceFile
// =================================================
CSystemFidFile * __thiscall
CSystemManagerFile::CreateFidResourceFile(CSystemManagerFile *this,CSystemManagerFile *param_1)
{
{
  CSystemFidFile *pCVar1;
  
  pCVar1 = (CSystemFidFile *)(**(code **)(*(int *)this + 0x7c))();
  *(undefined4 *)(pCVar1 + 0x18) = 5;
  return pCVar1;
}
}

// =================================================
// Function: CSystemManagerFile::CreateFidsFolder
// =================================================
CSystemFidsFolder * __thiscall
CSystemManagerFile::CreateFidsFolder(CSystemManagerFile *this,CSystemManagerFile *param_1)
{
{
  CSystemFidsFolder *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00436bf5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = (CSystemFidsFolder *)(**(code **)(*(int *)this + 0x78))();
  return pCVar1;
}
}

// =================================================
// Function: CSystemManagerFile::DeleteFileW
// =================================================
int __cdecl
CSystemManagerFile::DeleteFileW(CFastStringInt *param_1,CSystemFids *param_2,int param_3)
{
{
  undefined *puVar1;
  SStringParam *pSVar2;
  int iVar3;
  uint uStack_28;
  undefined *local_20;
  undefined *local_1c;
  undefined4 uStack_18;
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 *local_4;
  
  puStack_8 = &LAB_00a83508;
  local_c = ExceptionList;
  uStack_28 = DAT_00cca150 ^ (uint)&stack0xffffffdc;
  ExceptionList = &local_c;
  local_20 = (undefined *)0x0;
  local_1c = PTR_DAT_00bbf7dc;
  iVar3 = 0;
  pSVar2 = (SStringParam *)&local_20;
  local_4 = (undefined4 *)0x0;
  (**(code **)(*(int *)param_2 + 0x98))();
  local_20 = (undefined *)local_4[1];
  local_1c = (undefined *)*local_4;
  uStack_18 = 0;
  CFastStringInt::Concat(&uStack_28,(CFastStringInt *)&local_20,pSVar2);
  iVar3 = DeleteFileW((CFastStringInt *)&stack0xffffffdc,param_2,iVar3);
  if (local_20 != PTR_DAT_00bbf7dc) {
    if ((local_20[-1] & 0x80) == 0) {
      puVar1 = local_20 + -2;
    }
    else {
      puVar1 = local_20 + -4;
    }
    operator_delete__(puVar1);
  }
  ExceptionList = pvStack_10;
  return iVar3;
}
}

// =================================================
// Function: CSystemManagerFile::GetExeFullName
// =================================================
void __cdecl CSystemManagerFile::GetExeFullName(CFastStringInt *param_1)
{
{
  WCHAR WVar1;
  int iVar2;
  WCHAR WVar3;
  SStringParam *unaff_ESI;
  LPWSTR local_c;
  int local_8;
  undefined4 local_4;
  
  for (local_c = GetCommandLineW(); (*local_c == L' ' || (*local_c == L'\t')); local_c = local_c + 1
      ) {
  }
  if (*local_c == L'\"') {
    WVar3 = L'\"';
    local_c = local_c + 1;
  }
  else {
    WVar3 = L' ';
  }
  local_8 = 0;
  WVar1 = *local_c;
  while ((WVar1 != L'\0' && (WVar1 != WVar3))) {
    iVar2 = local_8 + 1;
    local_8 = local_8 + 1;
    WVar1 = local_c[iVar2];
  }
  local_4 = 1;
  CFastStringInt::SetString(param_1,(CFastStringInt *)&local_c,unaff_ESI);
  return;
}
}

// =================================================
// Function: CSystemManagerFile::GetTimeWrite
// =================================================
int __cdecl CSystemManagerFile::GetTimeWrite(CFastStringInt *param_1,uint64 *param_2)
{
{
  int iVar1;
  HANDLE hFile;
  BOOL BVar2;
  _FILETIME local_8;
  
  iVar1 = CSystemFileName::IsDirectoryName(param_1);
  hFile = CreateFileW(*(LPCWSTR *)(param_1 + 4),0x80,1,(LPSECURITY_ATTRIBUTES)0x0,3,
                      (-(uint)(iVar1 != 0) & 0x1ffff80) + 0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    GetLastError();
    return 0;
  }
  BVar2 = GetFileTime(hFile,(LPFILETIME)0x0,(LPFILETIME)0x0,&local_8);
  if (BVar2 == 0) {
    CloseHandle(hFile);
    return 0;
  }
  *(DWORD *)param_2 = local_8.dwLowDateTime;
  *(DWORD *)((int)param_2 + 4) = local_8.dwHighDateTime;
  CloseHandle(hFile);
  return 1;
}
}

// =================================================
// Function: CSystemManagerFile::GiveDirAllRights
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl CSystemManagerFile::GiveDirAllRights(CFastStringInt *param_1)
{
{
  HANDLE handle;
  DWORD DVar1;
  BOOL BVar2;
  uint uVar3;
  PACL local_3c;
  PACL local_38;
  LPWSTR local_34;
  PSECURITY_DESCRIPTOR local_30;
  _EXPLICIT_ACCESS_W local_2c;
  _SID_IDENTIFIER_AUTHORITY local_c;
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)&local_3c;
  uVar3 = 0;
  local_30 = (HLOCAL)0x0;
  local_34 = (LPWSTR)0x0;
  local_3c = (PACL)0x0;
  local_38 = (PACL)0x0;
  local_c.Value[0] = '\0';
  local_c.Value[1] = '\0';
  local_c.Value[2] = '\0';
  local_c.Value[3] = '\0';
  local_c.Value[4] = '\0';
  local_c.Value[5] = '\x05';
  local_2c.grfAccessPermissions = 0;
  local_2c.grfAccessMode = NOT_USED_ACCESS;
  local_2c.grfInheritance = 0;
  local_2c.Trustee.pMultipleTrustee = (_TRUSTEE_W *)0x0;
  local_2c.Trustee.MultipleTrusteeOperation = NO_MULTIPLE_TRUSTEE;
  local_2c.Trustee.TrusteeForm = TRUSTEE_IS_SID;
  local_2c.Trustee.TrusteeType = TRUSTEE_IS_UNKNOWN;
  local_2c.Trustee.ptstrName = (LPWSTR)0x0;
  handle = CreateFileW(*(LPCWSTR *)(param_1 + 4),0x60000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x2000000,
                       (HANDLE)0x0);
  if (handle == (HANDLE)0xffffffff) {
    return 0;
  }
  DVar1 = GetSecurityInfo(handle,SE_FILE_OBJECT,4,(PSID *)0x0,(PSID *)0x0,&local_3c,(PACL *)0x0,
                          &local_30);
  if (DVar1 == 0) {
    BVar2 = AllocateAndInitializeSid(&local_c,'\x02',0x20,0x221,0,0,0,0,0,0,&local_34);
    if (BVar2 == 0) {
      GetLastError();
    }
    else {
      local_2c.Trustee.ptstrName = local_34;
      local_2c.grfAccessMode = GRANT_ACCESS;
      local_2c.grfAccessPermissions = 0x10000000;
      local_2c.grfInheritance = 3;
      local_2c.Trustee.TrusteeType = TRUSTEE_IS_GROUP;
      local_2c.Trustee.TrusteeForm = TRUSTEE_IS_SID;
      DVar1 = SetEntriesInAclW(1,&local_2c,local_3c,&local_38);
      if ((DVar1 == 0) && (local_38 != (PACL)0x0)) {
        DVar1 = SetSecurityInfo(handle,SE_FILE_OBJECT,4,(PSID)0x0,(PSID)0x0,local_38,(PACL)0x0);
        uVar3 = (uint)(DVar1 == 0);
      }
    }
  }
  if (local_34 != (LPWSTR)0x0) {
    FreeSid(local_34);
  }
  if (local_38 != (PACL)0x0) {
    LocalFree(local_38);
  }
  if (local_30 != (HLOCAL)0x0) {
    LocalFree(local_30);
  }
  if (local_3c != (PACL)0x0) {
    LocalFree(local_3c);
  }
  CloseHandle(handle);
  return uVar3;
}
}

// =================================================
// Function: CSystemManagerFile::IsFileExists
// =================================================
int __cdecl CSystemManagerFile::IsFileExists(CFastStringInt *param_1)
{
{
  DWORD DVar1;
  
  DVar1 = GetFileAttributesW(*(LPCWSTR *)(param_1 + 4));
  if ((DVar1 != 0xffffffff) && ((DVar1 & 0x10) == 0)) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CSystemManagerFile::IsFolderExists
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl CSystemManagerFile::IsFolderExists(CFastStringInt *param_1)
{
{
  DWORD DVar1;
  wchar_t *unaff_EDI;
  WCHAR local_210 [262];
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)local_210;
  PrepareStringForSystemCall(param_1,unaff_EDI);
  DVar1 = GetFileAttributesW(local_210);
  if ((DVar1 != 0xffffffff) && ((DVar1 & 0x10) != 0)) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CSystemManagerFile::MakeDir
// =================================================
EMakeDir __cdecl CSystemManagerFile::MakeDir(CFastStringInt *param_1)
{
{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  LPCWSTR pWVar4;
  undefined *puVar5;
  ulong local_2c;
  undefined4 local_28;
  LPCWSTR local_24;
  undefined4 local_20;
  undefined *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00a83180;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_2c = 0;
  local_20 = 0;
  local_1c = PTR_DAT_00bbf7dc;
  local_28 = 0;
  local_24 = (LPCWSTR)PTR_DAT_00bbf7dc;
  local_c = 1;
  CSystemFileName::SplitFirstDirectory(param_1,(CFastStringInt *)&local_28,&local_2c);
  iVar1 = CSystemFileName::SplitFirstDirectory(param_1,(CFastStringInt *)&local_20,&local_2c);
  if (iVar1 != 0) {
    do {
      DVar3 = 0;
      CSystemFileName::ConcatDirectory((CFastStringInt *)&local_28,(CFastStringInt *)&local_20);
      BVar2 = CreateDirectoryW(local_24,(LPSECURITY_ATTRIBUTES)0x0);
      if (((BVar2 == 0) && (DVar3 = GetLastError(), DVar3 != 0)) && (DVar3 != 0xb7)) break;
      iVar1 = CSystemFileName::SplitFirstDirectory(param_1,(CFastStringInt *)&local_20,&local_2c);
    } while (iVar1 != 0);
    if (DVar3 != 0) {
      if (DVar3 == 0xb7) {
        if (local_24 != (LPCWSTR)PTR_DAT_00bbf7dc) {
          if ((*(byte *)((int)local_24 + -1) & 0x80) == 0) {
            pWVar4 = local_24 + -1;
          }
          else {
            pWVar4 = local_24 + -2;
          }
          operator_delete__(pWVar4);
          local_28 = 0;
          local_24 = (LPCWSTR)PTR_DAT_00bbf7dc;
        }
        if (local_1c != PTR_DAT_00bbf7dc) {
          if ((local_1c[-1] & 0x80) != 0) {
            operator_delete__(local_1c + -4);
            ExceptionList = local_14;
            return 1;
          }
          operator_delete__(local_1c + -2);
        }
        ExceptionList = local_14;
        return 1;
      }
      if (local_24 != (LPCWSTR)PTR_DAT_00bbf7dc) {
        if ((*(byte *)((int)local_24 + -1) & 0x80) == 0) {
          pWVar4 = local_24 + -1;
        }
        else {
          pWVar4 = local_24 + -2;
        }
        operator_delete__(pWVar4);
        local_28 = 0;
        local_24 = (LPCWSTR)PTR_DAT_00bbf7dc;
      }
      if (local_1c != PTR_DAT_00bbf7dc) {
        if ((local_1c[-1] & 0x80) != 0) {
          operator_delete__(local_1c + -4);
          ExceptionList = local_14;
          return 2;
        }
        operator_delete__(local_1c + -2);
      }
      ExceptionList = local_14;
      return 2;
    }
  }
  if (local_24 != (LPCWSTR)PTR_DAT_00bbf7dc) {
    if ((*(byte *)((int)local_24 + -1) & 0x80) == 0) {
      pWVar4 = local_24 + -1;
    }
    else {
      pWVar4 = local_24 + -2;
    }
    operator_delete__(pWVar4);
    local_28 = 0;
    local_24 = (LPCWSTR)PTR_DAT_00bbf7dc;
  }
  if (local_1c != PTR_DAT_00bbf7dc) {
    if ((local_1c[-1] & 0x80) == 0) {
      puVar5 = local_1c + -2;
    }
    else {
      puVar5 = local_1c + -4;
    }
    operator_delete__(puVar5);
  }
  ExceptionList = local_14;
  return 0;
}
}

// =================================================
// Function: CSystemManagerFile::MakeWritable
// =================================================
int __cdecl CSystemManagerFile::MakeWritable(CFastStringInt *param_1)
{
{
  DWORD DVar1;
  BOOL BVar2;
  
  DVar1 = GetFileAttributesW(*(LPCWSTR *)(param_1 + 4));
  if (DVar1 == 0xffffffff) {
    return 0;
  }
  BVar2 = SetFileAttributesW(*(LPCWSTR *)(param_1 + 4),DVar1 & 0xfffffffe);
  return (uint)(BVar2 != 0);
}
}

// =================================================
// Function: CSystemManagerFile::MoveFileW
// =================================================
int __cdecl
CSystemManagerFile::MoveFileW(CFastStringInt *param_1,CFastStringInt *param_2,int param_3)
{
{
  SNationConfig *pSVar1;
  int iVar2;
  EMakeDir EVar3;
  BOOL BVar4;
  undefined *puVar5;
  undefined4 local_14;
  undefined *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00a83268;
  local_c = ExceptionList;
  pSVar1 = (SNationConfig *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  local_14 = 0;
  local_10 = PTR_DAT_00bbf7dc;
  local_4 = 0;
  CSystemFileName::ExtractFullPathName(param_2,(CFastStringInt *)&local_14);
  iVar2 = IsFolderExists((CFastStringInt *)&local_14);
  if (iVar2 == 0) {
    EVar3 = MakeDir((CFastStringInt *)&local_14);
    if (EVar3 == 2) {
      if (local_10 != PTR_DAT_00bbf7dc) {
        if ((local_10[-1] & 0x80) != 0) {
          operator_delete__(local_10 + -4);
          ExceptionList = local_c;
          return 0;
        }
        operator_delete__(local_10 + -2);
      }
      ExceptionList = local_c;
      return 0;
    }
  }
  if (param_3 == 0) {
    if (DAT_00ccc508 == 2) {
      iVar2 = MoveFileExW(*(LPCWSTR *)(param_1 + 4),*(LPCWSTR *)(param_2 + 4),0xb);
    }
    else {
      iVar2 = IsFileExists(param_2);
      if (iVar2 != 0) {
        iVar2 = MakeWritable(param_2);
        if (iVar2 == 0) goto LAB_00435f93;
      }
      BVar4 = ::CopyFileW(*(LPCWSTR *)(param_1 + 4),*(LPCWSTR *)(param_2 + 4),0);
      if (BVar4 == 0) goto LAB_00435f93;
      iVar2 = MakeWritable(param_1);
      if (iVar2 == 0) goto LAB_00435f93;
      iVar2 = ::DeleteFileW(*(LPCWSTR *)(param_1 + 4));
    }
  }
  else {
    iVar2 = ::MoveFileW(*(LPCWSTR *)(param_1 + 4),*(LPCWSTR *)(param_2 + 4));
  }
  if (iVar2 != 0) {
    if (local_10 != PTR_DAT_00bbf7dc) {
      if ((local_10[-1] & 0x80) == 0) {
        puVar5 = local_10 + -2;
      }
      else {
        puVar5 = local_10 + -4;
      }
      operator_delete__(puVar5);
    }
    ExceptionList = local_c;
    return 1;
  }
LAB_00435f93:
  CGameCtnApp::SNationConfig::~SNationConfig(&local_14,pSVar1);
  ExceptionList = local_8;
  return 0;
}
}

