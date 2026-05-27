// Class implementation: CSystemFile

// =================================================
// Function: CSystemFile::CSystemFile
// =================================================
void __thiscall CSystemFile::CSystemFile(CSystemFile *this,CSystemFile *param_1)
{
{
  CClassicBuffer *unaff_ESI;
  
  CClassicBuffer::CClassicBuffer((CClassicBuffer *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined **)(this + 0x18) = PTR_DAT_00bbf7dc;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  return;
}
}

// =================================================
// Function: CSystemFile::Close
// =================================================
void __thiscall CSystemFile::Close(CSystemFile *this,CClassicLog *param_1)
{
{
  undefined4 *puVar1;
  undefined *puVar2;
  
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  if (*(HANDLE *)(this + 0xc) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(this + 0xc));
    *(undefined4 *)(this + 0xc) = 0;
    if (*(CFastStringInt **)(this + 0x10) != (CFastStringInt *)0x0) {
      CSystemManagerFile::MoveFileW
                (*(CFastStringInt **)(this + 0x10),(CFastStringInt *)(this + 0x14),0);
      puVar1 = *(undefined4 **)(this + 0x10);
      if (puVar1 != (undefined4 *)0x0) {
        puVar2 = (undefined *)puVar1[1];
        if (puVar2 != PTR_DAT_00bbf7dc) {
          if ((puVar2[-1] & 0x80) == 0) {
            puVar2 = puVar2 + -2;
          }
          else {
            puVar2 = puVar2 + -4;
          }
          operator_delete__(puVar2);
          *puVar1 = 0;
          puVar1[1] = PTR_DAT_00bbf7dc;
        }
        operator_delete(puVar1);
      }
      *(undefined4 *)(this + 0x10) = 0;
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CSystemFile::Flush
// =================================================
void __thiscall CSystemFile::Flush(CSystemFile *this,CGameAdvertisingRadial *param_1)
{
{
  if (*(HANDLE *)(this + 0xc) != (HANDLE)0x0) {
    FlushFileBuffers(*(HANDLE *)(this + 0xc));
  }
  return;
}
}

// =================================================
// Function: CSystemFile::GetLength
// =================================================
float __thiscall CSystemFile::GetLength(CSystemFile *this,CPlugFileSnd *param_1)
{
{
  float10 extraout_ST0;
  
  GetFileSize(*(HANDLE *)(this + 0xc),(LPDWORD)0x0);
  return (float)extraout_ST0;
}
}

// =================================================
// Function: CSystemFile::InternalChunkedRead
// =================================================
ulong __thiscall
CSystemFile::InternalChunkedRead(CSystemFile *this,CSystemFile *param_1,void *param_2,ulong param_3)
{
{
  int iVar1;
  CSystemFile *pCVar2;
  void *pvVar3;
  
  pvVar3 = param_2;
  pCVar2 = param_1;
  if (param_2 <= *(void **)(this + 0x20)) {
    _memcpy(param_1,this + *(int *)(this + 0x24) + 0x28,(uint)param_2);
    *(int *)(this + 0x24) = *(int *)(this + 0x24) + (int)pvVar3;
    *(int *)(this + 0x20) = *(int *)(this + 0x20) - (int)pvVar3;
    return (ulong)pvVar3;
  }
  _memcpy(param_1,this + *(int *)(this + 0x24) + 0x28,(uint)*(void **)(this + 0x20));
  iVar1 = *(int *)(this + 0x20);
  *(int *)(this + 0x24) = *(int *)(this + 0x24) + iVar1;
  param_2 = pCVar2 + iVar1;
  *(undefined4 *)(this + 0x20) = 0;
  param_1 = (CSystemFile *)0x0;
  if ((void *)0x1000 < pvVar3) {
    ReadFile(*(HANDLE *)(this + 0xc),param_2,(int)pvVar3 - iVar1,(LPDWORD)&param_1,(LPOVERLAPPED)0x0
            );
    return (ulong)(param_1 + iVar1);
  }
  ReadFile(*(HANDLE *)(this + 0xc),this + 0x28,0x1000,(LPDWORD)&param_1,(LPOVERLAPPED)0x0);
  *(undefined4 *)(this + 0x24) = 0;
  *(CSystemFile **)(this + 0x20) = param_1;
  if ((CSystemFile *)((int)pvVar3 - iVar1) < param_1) {
    param_1 = (CSystemFile *)((int)pvVar3 - iVar1);
  }
  pCVar2 = param_1;
  _memcpy(param_2,this + 0x28,(uint)param_1);
  *(CSystemFile **)(this + 0x24) = pCVar2 + *(int *)(this + 0x24);
  *(int *)(this + 0x20) = *(int *)(this + 0x20) - (int)pCVar2;
  return (ulong)(pCVar2 + iVar1);
}
}

// =================================================
// Function: CSystemFile::Open
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl
CSystemFile::Open(_D3DXINCLUDE_TYPE param_1,char *param_2,void *param_3,void **param_4,uint *param_5
                 )
{
{
  undefined *lpPathName;
  SStringParam *pSVar1;
  SNationConfig *hObject;
  UINT UVar2;
  long lVar3;
  undefined4 *this;
  DWORD dwFlagsAndAttributes;
  HANDLE pvVar4;
  CSystemFile *in_ECX;
  DWORD dwDesiredAccess;
  DWORD dwShareMode;
  void *pvVar5;
  SStringParamInt *lpFileName;
  ulong unaff_EDI;
  DWORD dwCreationDisposition;
  int in_stack_00000018;
  int in_stack_0000001c;
  SNationConfig *pSVar6;
  undefined1 auStack_238 [8];
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228 [2];
  SStringParamInt local_220 [528];
  uint local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a830ab;
  local_c = ExceptionList;
  local_10 = DAT_00cca150 ^ (uint)auStack_238;
  pSVar1 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xfffffdb8);
  ExceptionList = &local_c;
  pvVar5 = param_3;
  if ((param_3 != (void *)0x0) && (param_2 == (char *)0x1)) {
    pvVar5 = (void *)0x0;
  }
  *(char **)(in_ECX + 4) = param_2;
  local_230 = *(undefined4 *)(param_1 + 4);
  local_22c = *(undefined4 *)param_1;
  local_228[0] = 0;
  CFastStringInt::SetString(in_ECX + 0x14,(CFastStringInt *)&local_230,pSVar1);
  lpFileName = *(SStringParamInt **)(in_ECX + 0x18);
  if (pvVar5 == (void *)0x0) {
LAB_0043536f:
    if (param_3 == (void *)0x2) {
      dwDesiredAccess = 0x40000000;
      dwShareMode = (DWORD)(in_stack_0000001c != 0);
      dwCreationDisposition = (uint)(param_5 == (uint *)0x0) * 2 + 2;
      dwFlagsAndAttributes = 0x8000000;
    }
    else {
      dwShareMode = 1;
      dwDesiredAccess = 0x80000000;
      dwCreationDisposition = 3;
      dwFlagsAndAttributes = 0;
    }
    if (in_stack_00000018 != 0) {
      dwFlagsAndAttributes = dwFlagsAndAttributes | 0x40000000;
    }
    pvVar4 = CreateFileW((LPCWSTR)lpFileName,dwDesiredAccess,dwShareMode,(LPSECURITY_ATTRIBUTES)0x0,
                         dwCreationDisposition,dwFlagsAndAttributes,(HANDLE)0x0);
    *(HANDLE *)(in_ECX + 0xc) = pvVar4;
    if (pvVar4 == (HANDLE)0xffffffff) {
      *(undefined4 *)(in_ECX + 0xc) = 0;
      lVar3 = 0;
    }
    else {
      *(undefined4 *)(in_ECX + 0x1c) = 0;
      *(undefined4 *)(in_ECX + 0x20) = 0;
      *(undefined4 *)(in_ECX + 0x24) = 0;
      if ((param_3 == (void *)0x2) && (param_5 == (uint *)0x0)) {
        SetOffset(in_ECX,(CSystemFile *)0xffffffff,unaff_EDI);
      }
      lVar3 = 1;
    }
  }
  else {
    pSVar6 = (SNationConfig *)&DAT_00000004;
    hObject = CreateFileW((LPCWSTR)lpFileName,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,0x8000000,
                          (HANDLE)0x0);
    if (hObject != (SNationConfig *)0xffffffff) {
      pSVar1 = (SStringParam *)0x4352d7;
      CloseHandle(hObject);
      lpPathName = PTR_DAT_00bbf7dc;
      local_c = (void *)0x0;
      CSystemFileName::ExtractFullPathName
                ((CFastStringInt *)param_1,(CFastStringInt *)&stack0xfffffdc0);
      UVar2 = GetTempFileNameW((LPCWSTR)lpPathName,(LPCWSTR)&lpPrefixString_00b30b90,0,
                               (LPWSTR)local_220);
      if (UVar2 != 0) {
        lpFileName = local_220;
        this = operator_new(8);
        if (this == (undefined4 *)0x0) {
          this = (undefined4 *)0x0;
        }
        else {
          *this = 0;
          this[1] = PTR_DAT_00bbf7dc;
        }
        *(undefined4 **)(in_ECX + 0x10) = this;
        SStringParamInt::SStringParamInt(&local_22c,local_220,(wchar_t *)pSVar6);
        CFastStringInt::SetString(this,(CFastStringInt *)local_228,pSVar1);
        CGameCtnApp::SNationConfig::~SNationConfig(auStack_238,hObject);
        goto LAB_0043536f;
      }
      CGameCtnApp::SNationConfig::~SNationConfig(&stack0xfffffdc0,pSVar6);
    }
    lVar3 = 0;
  }
  ExceptionList = local_8;
  return lVar3;
}
}

// =================================================
// Function: CSystemFile::Read
// =================================================
ulong __thiscall
CSystemFile::Read(CSystemFile *this,CClassicBufferCrypted *param_1,void *param_2,ulong param_3)
{
{
  int iVar1;
  ulong uVar2;
  GxTexCoordSet *unaff_ESI;
  TiXmlAttribute *unaff_EDI;
  CSystemFile *pCVar3;
  CSystemFile *in_stack_00000010;
  CSystemFile *pCVar4;
  
  DAT_00d54254 = 1;
  pCVar4 = this;
  iVar1 = CFastArray<class_CGameMenuFrame*>::Find
                    (&DAT_00d55728,(CFastArray<class_GxTexCoordSet> *)&stack0xfffffffc,unaff_ESI);
  if (iVar1 != -1) {
    return 0;
  }
  pCVar3 = this;
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (&DAT_00d55728,(TiXmlAttributeSet *)&stack0x00000000,unaff_EDI);
  DAT_00d55750 = in_stack_00000010 + (int)DAT_00d55750;
  if ((DAT_00d55750 < (CSystemFile *)0x40001) || (DAT_00d55718 != 0)) {
    uVar2 = InternalChunkedRead(this,(CSystemFile *)param_3,in_stack_00000010,(ulong)pCVar4);
  }
  else {
    CMwCmdBufferCore::HighFrequencyEnterSafeSection
              (DAT_00d731e0,(CMwCmdBufferCore *)0x1,(ulong)pCVar4);
    uVar2 = InternalChunkedRead(this,in_stack_00000010,in_stack_00000010,(ulong)pCVar3);
    CMwCmdBufferCore::HighFrequencyLeaveSafeSection(DAT_00d731e0,(CMwCmdBufferCore *)param_1);
    if (DAT_00d55968 != 0) {
      ReadCallbackByteReaded(uVar2);
    }
    DAT_00d55750 = (CSystemFile *)0x0;
  }
  *(ulong *)(this + 0x1c) = *(int *)(this + 0x1c) + uVar2;
  if (DAT_00d55728 != 0) {
    DAT_00d55728 = DAT_00d55728 + -1;
  }
  return uVar2;
}
}

// =================================================
// Function: CSystemFile::ReadCallbackByteReaded
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CSystemFile::ReadCallbackByteReaded(ulong param_1)
{
{
  uint uVar1;
  bool bVar2;
  
  if (DAT_00d55968 != (undefined4 *)0x0) {
    bVar2 = CARRY4(DAT_00d55970,param_1);
    DAT_00d55970 = DAT_00d55970 + param_1;
    DAT_00d55974 = DAT_00d55974 + bVar2;
    uVar1 = _DAT_00d5597c + CARRY4(DAT_00d5596c,_DAT_00d55978);
    if ((uVar1 <= DAT_00d55974) &&
       (((uVar1 < DAT_00d55974 || (DAT_00d5596c + _DAT_00d55978 < DAT_00d55970)) &&
        (_DAT_00d55978 = DAT_00d55970, _DAT_00d5597c = DAT_00d55974, DAT_00d55980 == 0)))) {
      DAT_00d55980 = 1;
      (**(code **)*DAT_00d55968)(DAT_00d55970,DAT_00d55974);
      DAT_00d55980 = 0;
    }
  }
  return;
}
}

// =================================================
// Function: CSystemFile::SetOffset
// =================================================
int __thiscall CSystemFile::SetOffset(CSystemFile *this,CSystemFile *param_1,ulong param_2)
{
{
  DWORD DVar1;
  HANDLE hFile;
  DWORD DVar2;
  
  if (param_1 == (CSystemFile *)0xffffffff) {
    hFile = *(HANDLE *)(this + 0xc);
    DVar2 = 2;
    param_1 = (CSystemFile *)0x0;
  }
  else {
    hFile = *(HANDLE *)(this + 0xc);
    DVar2 = 0;
  }
  DVar2 = SetFilePointer(hFile,(LONG)param_1,(PLONG)0x0,DVar2);
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  if (DVar2 == 0xffffffff) {
    DVar1 = GetLastError();
    if (DVar1 != 0) {
      return 0;
    }
  }
  *(DWORD *)(this + 0x1c) = DVar2;
  return 1;
}
}

// =================================================
// Function: CSystemFile::UpdateAsyncIO
// =================================================
void __cdecl CSystemFile::UpdateAsyncIO(void)
{
{
  if (DAT_00ccc4f0 != 0) {
    SleepEx(0,1);
  }
  return;
}
}

// =================================================
// Function: CSystemFile::~CSystemFile
// =================================================
void __thiscall CSystemFile::~CSystemFile(CSystemFile *this,CSystemFile *param_1)
{
{
  undefined4 *puVar1;
  CClassicLog *pCVar2;
  undefined *puVar3;
  CClassicBuffer *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00a83883;
  local_c = ExceptionList;
  pCVar2 = (CClassicLog *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = (void *)0x1;
  if (*(int *)(this + 0xc) != 0) {
    Close(this,pCVar2);
  }
  puVar1 = *(undefined4 **)(this + 0x10);
  if (puVar1 != (undefined4 *)0x0) {
    puVar3 = (undefined *)puVar1[1];
    if (puVar3 != PTR_DAT_00bbf7dc) {
      if ((puVar3[-1] & 0x80) == 0) {
        puVar3 = puVar3 + -2;
      }
      else {
        puVar3 = puVar3 + -4;
      }
      operator_delete__(puVar3);
      *puVar1 = 0;
      puVar1[1] = PTR_DAT_00bbf7dc;
    }
    operator_delete(puVar1);
  }
  puVar3 = *(undefined **)(this + 0x18);
  if (puVar3 != PTR_DAT_00bbf7dc) {
    if ((puVar3[-1] & 0x80) == 0) {
      puVar3 = puVar3 + -2;
    }
    else {
      puVar3 = puVar3 + -4;
    }
    operator_delete__(puVar3);
    *(undefined4 *)(this + 0x14) = 0;
    *(undefined **)(this + 0x18) = PTR_DAT_00bbf7dc;
  }
  CClassicBuffer::~CClassicBuffer((CClassicBuffer *)this,unaff_EDI);
  ExceptionList = local_4;
  return;
}
}

