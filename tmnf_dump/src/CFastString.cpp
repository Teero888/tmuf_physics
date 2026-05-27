// Class implementation: CFastString

// =================================================
// Function: CFastString::CFastString
// =================================================
void __thiscall CFastString::CFastString(CFastString *this,CFastString *param_1,char *param_2)
{
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  void *pvVar5;
  SOldChars *pSVar6;
  CFastStringBase<wchar_t> *pCVar7;
  undefined4 *in_stack_0000000c;
  undefined4 *in_stack_00000010;
  undefined4 *in_stack_00000014;
  undefined4 *in_stack_00000018;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00ae0ae8;
  local_c = ExceptionList;
  pSVar6 = (SOldChars *)(DAT_00cca150 ^ (uint)&stack0xffffffd4);
  ExceptionList = &local_c;
  *(undefined4 *)this = 0;
  *(undefined **)(this + 4) = PTR_DAT_00bbf7d8;
  local_4 = 0;
  uVar1 = *(uint *)(param_1 + 4);
  uVar2 = *(uint *)(param_2 + 4);
  uVar3 = in_stack_00000014[1];
  uVar4 = in_stack_00000010[1];
  pCVar7 = (CFastStringBase<wchar_t> *)(uVar3 + uVar4 + in_stack_0000000c[1] + uVar2 + uVar1);
  if (pCVar7 != *(CFastStringBase<wchar_t> **)this) {
    CFastStringBase<char>::AllocAtLeast((CFastStringBase<char> *)this,pCVar7,1,0,pSVar6);
    pCVar7[*(int *)(this + 4)] = (CFastStringBase<wchar_t>)0x0;
    *(CFastStringBase<wchar_t> **)this = pCVar7;
  }
  pvVar5 = *(void **)(this + 4);
  _memcpy(pvVar5,*(void **)param_2,uVar1);
  _memcpy((void *)((int)pvVar5 + uVar1),(void *)*in_stack_0000000c,uVar2);
  _memcpy((void *)((int)pvVar5 + uVar1 + uVar2),(void *)*in_stack_00000010,uVar4);
  _memcpy((void *)((int)pvVar5 + uVar1 + uVar2 + uVar4),(void *)*in_stack_00000014,uVar3);
  _memcpy((void *)((int)pvVar5 + uVar1 + uVar2 + uVar4 + uVar3),(void *)*in_stack_00000018,
          (uint)(this + 1));
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CFastString::Compare
// =================================================
void __thiscall
CFastString::Compare
          (CFastString *this,SParam_Fids *param_1,SParam *param_2,int *param_3,int *param_4)
{
{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (param_2 != (SParam *)0x0) {
    if ((param_2 <= *(SParam **)this) && (param_2 <= *(SParam **)(param_1 + 4))) {
      _strncmp(*(char **)(this + 4),*(char **)param_1,(uint)param_2);
      return;
    }
    return;
  }
  pcVar3 = *(char **)param_1;
  pcVar2 = *(char **)(this + 4);
  do {
    if (*pcVar2 != *pcVar3) {
      return;
    }
    if (*pcVar2 == '\0') {
      return;
    }
    pcVar1 = pcVar2 + 1;
    if (*pcVar1 != pcVar3[1]) {
      return;
    }
    pcVar2 = pcVar2 + 2;
    pcVar3 = pcVar3 + 2;
  } while (*pcVar1 != '\0');
  return;
}
}

// =================================================
// Function: CFastString::CompareNoCase
// =================================================
int __thiscall
CFastString::CompareNoCase
          (CFastString *this,CFastStringInt *param_1,SStringParam *param_2,ulong param_3)
{
{
  int iVar1;
  
  if (param_2 == (SStringParam *)0x0) {
    iVar1 = __stricmp(*(char **)(this + 4),*(char **)param_1);
    return iVar1;
  }
  if ((param_2 <= *(SStringParam **)this) && (param_2 <= *(SStringParam **)(param_1 + 4))) {
    iVar1 = __strnicmp(*(char **)(this + 4),*(char **)param_1,(uint)param_2);
    return iVar1;
  }
  return -1;
}
}

// =================================================
// Function: CFastString::Concat
// =================================================
void __thiscall CFastString::Concat(CFastString *this,CFastStringInt *param_1,SStringParam *param_2)
{
{
  CFastStringBase<wchar_t> *pCVar1;
  CFastStringBase<wchar_t> *pCVar2;
  SOldChars *unaff_EDI;
  
  pCVar2 = *(CFastStringBase<wchar_t> **)this;
  pCVar1 = pCVar2 + 1;
  if (pCVar1 != pCVar2) {
    CFastStringBase<char>::AllocAtLeast((CFastStringBase<char> *)this,pCVar1,1,0,unaff_EDI);
    pCVar1[*(int *)(this + 4)] = (CFastStringBase<wchar_t>)0x0;
    *(CFastStringBase<wchar_t> **)this = pCVar1;
    pCVar2[*(int *)(this + 4)] = param_2._0_1_;
    return;
  }
  pCVar2[*(int *)(this + 4)] = param_1._0_1_;
  return;
}
}

// =================================================
// Function: CFastString::ConcatAndNewLine
// =================================================
void __thiscall
CFastString::ConcatAndNewLine
          (CFastString *this,CFastString *param_1,SStringParam *param_2,char *param_3)
{
{
  SStringParam SVar1;
  uint uVar2;
  CFastStringBase<wchar_t> *pCVar3;
  SStringParam *pSVar4;
  CFastStringBase<wchar_t> *pCVar5;
  SOldChars *unaff_EDI;
  uint unaff_retaddr;
  
  uVar2 = *(uint *)(param_1 + 4);
  pCVar3 = *(CFastStringBase<wchar_t> **)this;
  pSVar4 = param_2;
  do {
    SVar1 = *pSVar4;
    pSVar4 = pSVar4 + 1;
  } while (SVar1 != (SStringParam)0x0);
  pCVar5 = pCVar3 + (int)(pSVar4 + (uVar2 - (int)(param_2 + 1)));
  if (pCVar5 != pCVar3) {
    CFastStringBase<char>::AllocAtLeast((CFastStringBase<char> *)this,pCVar5,1,0,unaff_EDI);
    pCVar5[*(int *)(this + 4)] = (CFastStringBase<wchar_t>)0x0;
    *(CFastStringBase<wchar_t> **)this = pCVar5;
  }
  _memcpy(pCVar3 + *(int *)(this + 4),*(void **)param_2,uVar2);
  _memcpy(pCVar3 + *(int *)(this + 4) + uVar2,param_3,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CFastString::ConcatBefore
// =================================================
void __thiscall
CFastString::ConcatBefore(CFastString *this,CFastStringInt *param_1,SStringParamInt *param_2)
{
{
  CFastStringBase<wchar_t> *pCVar1;
  uint uVar2;
  uint uVar3;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_EDI;
  undefined4 local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ae0a88;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar2 = *(uint *)(param_1 + 4);
  uVar3 = *(uint *)this;
  if (uVar2 != 0) {
    local_14 = 0;
    local_10 = (void *)0x0;
    local_4 = (void *)0x0;
    pCVar1 = (CFastStringBase<wchar_t> *)(uVar2 + uVar3);
    if (pCVar1 != *(CFastStringBase<wchar_t> **)this) {
      CFastStringBase<char>::AllocAtLeast
                ((CFastStringBase<char> *)this,pCVar1,0,(int)&local_14,
                 (SOldChars *)(DAT_00cca150 ^ (uint)&stack0xffffffdc));
      pCVar1[*(int *)(this + 4)] = (CFastStringBase<wchar_t>)0x0;
      *(CFastStringBase<wchar_t> **)this = pCVar1;
    }
    if (uVar3 != 0) {
      _memmove((void *)(*(int *)(this + 4) + uVar2),local_10,uVar3);
    }
    _memcpy(*(void **)(this + 4),*(void **)param_2,uVar2);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(&local_10,unaff_EDI);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CFastString::ConcatFormat
// =================================================
void __thiscall CFastString::ConcatFormat(CFastString *this,CFastStringInt *param_1,char *param_2)
{
{
  char *pcVar1;
  SStringParam *unaff_EDI;
  uint uVar2;
  char *local_8;
  int local_4;
  
  uVar2 = 0x400;
  if (DAT_00d71c98 == 0) {
    pcVar1 = &DAT_00d71898;
  }
  else {
    pcVar1 = operator_new__(0x400);
  }
  DAT_00d71c98 = DAT_00d71c98 + 1;
  local_4 = __vsnprintf(pcVar1,0x400,param_2,&stack0x0000000c);
  while (local_4 < 0) {
    uVar2 = uVar2 + 0x100;
    if (pcVar1 != &DAT_00d71898) {
      operator_delete__(pcVar1);
    }
    pcVar1 = operator_new__(uVar2);
    local_4 = __vsnprintf(pcVar1,uVar2,param_2,&stack0x0000000c);
  }
  local_8 = pcVar1;
  Concat((CFastString *)param_1,(CFastStringInt *)&local_8,unaff_EDI);
  if (pcVar1 != &DAT_00d71898) {
    operator_delete__(pcVar1);
  }
  DAT_00d71c98 = DAT_00d71c98 + -1;
  return;
}
}

// =================================================
// Function: CFastString::FilterStringForPrintableChars
// =================================================
/* WARNING: Removing unreachable block (ram,0x00900159) */

int __cdecl CFastString::FilterStringForPrintableChars(CFastString *param_1)
{
{
  byte bVar1;
  CFastStringBase<wchar_t> *pCVar2;
  byte *pbVar3;
  byte *pbVar4;
  SOldChars *unaff_EDI;
  CFastStringBase<wchar_t> *pCVar5;
  CFastStringBase<wchar_t> *local_4;
  
  pCVar2 = *(CFastStringBase<wchar_t> **)param_1;
  pCVar5 = (CFastStringBase<wchar_t> *)0x0;
  if (pCVar2 == (CFastStringBase<wchar_t> *)0x0) {
    if (**(char **)(param_1 + 4) == '\0') {
      return 1;
    }
    return 0;
  }
  pbVar3 = *(byte **)(param_1 + 4);
  local_4 = (CFastStringBase<wchar_t> *)0x0;
  pbVar4 = pbVar3;
  if (pCVar2 != (CFastStringBase<wchar_t> *)0x0) {
    do {
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + 1;
      if (bVar1 == 0) break;
      if (bVar1 < 0x20) {
        if (((bVar1 == 9) || (bVar1 == 10)) || (bVar1 == 0xd)) goto LAB_009001a5;
      }
      else if (bVar1 != 0x7f) {
LAB_009001a5:
        *pbVar4 = bVar1;
        pbVar4 = pbVar4 + 1;
        pCVar5 = pCVar5 + 1;
      }
      local_4 = local_4 + 1;
    } while (local_4 < pCVar2);
  }
  if (pCVar5 != *(CFastStringBase<wchar_t> **)param_1) {
    CFastStringBase<char>::AllocAtLeast((CFastStringBase<char> *)param_1,pCVar5,1,0,unaff_EDI);
    pCVar5[*(int *)(param_1 + 4)] = (CFastStringBase<wchar_t>)0x0;
    *(CFastStringBase<wchar_t> **)param_1 = pCVar5;
  }
  return (uint)(pCVar2 == pCVar5);
}
}

// =================================================
// Function: CFastString::FindFirst
// =================================================
ulong __thiscall
CFastString::FindFirst(CFastString *this,CFastStringInt *param_1,ulong param_2,ulong param_3)
{
{
  int iVar1;
  char *pcVar2;
  ulong uVar3;
  ulong unaff_EBP;
  char *unaff_ESI;
  char *pcVar4;
  ulong unaff_EDI;
  undefined4 uStack00000010;
  ulong in_stack_00000018;
  SHeaderCommunity *in_stack_ffffffdc;
  SHeaderCommunity *in_stack_ffffffe0;
  CFastString local_1c [4];
  CFastString local_18 [4];
  undefined1 local_14 [4];
  undefined4 local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ae0c00;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_3 == 0) {
    CFastString(local_1c,this,(char *)(DAT_00cca150 ^ (uint)&stack0xffffffd0));
    UpCase(local_18,(CFastString *)0x0,0xffffffff,unaff_EDI);
    CFastString(local_1c,(CFastString *)0x0,unaff_ESI);
    UpCase(local_18,(CFastString *)0x0,0xffffffff,unaff_EBP);
    local_4 = local_10;
    uVar3 = FindFirst((CFastString *)&local_c,(CFastStringInt *)&local_4,in_stack_00000018,1);
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(local_14,in_stack_ffffffdc);
    uStack00000010 = 0xffffffff;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_8,in_stack_ffffffe0);
    ExceptionList = (void *)0x0;
    return uVar3;
  }
  iVar1 = *(int *)(this + 4);
  pcVar2 = *(char **)param_1;
  pcVar4 = (char *)0x0;
  if (pcVar2[*(int *)(param_1 + 4)] != '\0') {
    pcVar2 = operator_new__(*(int *)(param_1 + 4) + 1);
    _memcpy(pcVar2,*(void **)param_1,*(uint *)(param_1 + 4));
    pcVar2[*(int *)(param_1 + 4)] = '\0';
    pcVar4 = pcVar2;
  }
  pcVar2 = _strstr((char *)(param_2 + iVar1),pcVar2);
  operator_delete__(pcVar4);
  if (pcVar2 != (char *)0x0) {
    ExceptionList = local_c;
    return (int)pcVar2 - iVar1;
  }
  ExceptionList = local_c;
  return 0xffffffff;
}
}

// =================================================
// Function: CFastString::FindFirstCharInSet
// =================================================
ulong __thiscall
CFastString::FindFirstCharInSet
          (CFastString *this,CFastString *param_1,SStringParam *param_2,ulong param_3)
{
{
  int iVar1;
  uint uVar2;
  SStringParam *pSVar3;
  
  iVar1 = *(int *)this;
  uVar2 = _strcspn((char *)(param_2 + *(int *)(this + 4)),*(char **)param_1);
  pSVar3 = param_2 + uVar2;
  if (iVar1 <= (int)pSVar3) {
    pSVar3 = (SStringParam *)0xffffffff;
  }
  return (ulong)pSVar3;
}
}

// =================================================
// Function: CFastString::Format
// =================================================
CFastString * __thiscall CFastString::Format(CFastString *this,CFastString *param_1,char *param_2)
{
{
  char *unaff_ESI;
  
  InternalVFormat(param_1,(CFastString *)param_2,&stack0x0000000c,unaff_ESI);
  return param_1;
}
}

// =================================================
// Function: CFastString::GetInteger
// =================================================
int __thiscall
CFastString::GetInteger(CFastString *this,CFastString *param_1,int *param_2,ulong param_3)
{
{
  int extraout_EAX;
  SOldChars *unaff_ESI;
  bool bVar1;
  int *in_stack_00000010;
  char *in_stack_ffffffec;
  SHeaderCommunity *in_stack_fffffff0;
  SHeaderCommunity *pSVar2;
  undefined1 *local_8;
  int local_4;
  
  local_4 = -1;
  local_8 = &DAT_00ae0c28;
  pSVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  CFastString((CFastString *)&stack0xffffffec,this,(char *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  if (param_3 != 0) {
    if (param_3 < in_stack_fffffff0) {
      TruncBefore((CFastString *)&stack0xfffffff0,(CFastString *)(in_stack_fffffff0 + -param_3),
                  (ulong)unaff_ESI);
    }
    else if (in_stack_fffffff0 != (SHeaderCommunity *)0x0) {
      CFastStringBase<char>::AllocAtLeast
                ((CFastStringBase<char> *)&stack0xfffffff0,(CFastStringBase<wchar_t> *)0x0,1,0,
                 unaff_ESI);
      *local_8 = 0;
      pSVar2 = (SHeaderCommunity *)0x0;
    }
  }
  RemoveAllWhiteSpaces
            ((CFastString *)&stack0xfffffff4,(CFastString *)PTR_DAT_00d34100,in_stack_ffffffec);
  if (local_8 == (undefined1 *)0x0) {
    *in_stack_00000010 = 0;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_8,in_stack_fffffff0);
    ExceptionList = param_1;
    return 0;
  }
  atoi();
  *in_stack_00000010 = extraout_EAX;
  if (extraout_EAX == 0) {
    RemoveAllWhiteSpaces
              ((CFastString *)&local_8,(CFastString *)&DAT_00b2efac,(char *)in_stack_fffffff0);
    bVar1 = local_4 == 0;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_4,pSVar2);
    ExceptionList = param_2;
    return (uint)bVar1;
  }
  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_8,in_stack_fffffff0);
  ExceptionList = param_1;
  return 1;
}
}

// =================================================
// Function: CFastString::GetLineAt
// =================================================
int __thiscall
CFastString::GetLineAt(CFastString *this,CFastString *param_1,ulong param_2,CFastString *param_3)
{
{
  char cVar1;
  char *_Str;
  char *pcVar2;
  SStringParam *unaff_EDI;
  char *local_8;
  char *local_4;
  
  _Str = *(char **)(this + 4);
  while( true ) {
    if (param_1 == (CFastString *)0x0) {
      local_4 = _strchr(_Str,10);
      if (local_4 == (char *)0x0) {
        if (_Str == (char *)0x0) {
          local_4 = (char *)0x0;
        }
        else {
          local_4 = _Str;
          do {
            cVar1 = *local_4;
            local_4 = local_4 + 1;
          } while (cVar1 != '\0');
          local_4 = local_4 + -(int)(_Str + 1);
        }
      }
      else {
        local_4 = local_4 + (-1 - (int)_Str);
      }
      local_8 = _Str;
      SetString((CFastString *)param_2,(CFastStringInt *)&local_8,unaff_EDI);
      return 1;
    }
    pcVar2 = _strchr(_Str,10);
    if ((pcVar2 == (char *)0x0) || (_Str = pcVar2 + 1, pcVar2[1] == '\0')) break;
    param_1 = param_1 + -1;
  }
  local_8 = "";
  local_4 = (char *)0x0;
  SetString((CFastString *)param_2,(CFastStringInt *)&local_8,unaff_EDI);
  return 0;
}
}

// =================================================
// Function: CFastString::GetNatural
// =================================================
int __thiscall
CFastString::GetNatural
          (CFastString *this,CFastString *param_1,ulong *param_2,int param_3,ulong param_4)
{
{
  ulong uVar1;
  SOldChars *unaff_ESI;
  bool bVar2;
  int in_stack_00000014;
  char *in_stack_ffffffec;
  int iVar3;
  SHeaderCommunity *in_stack_fffffff0;
  SHeaderCommunity *pSVar4;
  undefined1 *local_8;
  char *local_4;
  
  local_4 = (char *)0xffffffff;
  local_8 = &DAT_00ae0b18;
  pSVar4 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  CFastString((CFastString *)&stack0xffffffec,this,(char *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  if (param_4 != 0) {
    if (param_4 < in_stack_fffffff0) {
      TruncBefore((CFastString *)&stack0xfffffff0,(CFastString *)(in_stack_fffffff0 + -param_4),
                  (ulong)unaff_ESI);
    }
    else if (in_stack_fffffff0 != (SHeaderCommunity *)0x0) {
      CFastStringBase<char>::AllocAtLeast
                ((CFastStringBase<char> *)&stack0xfffffff0,(CFastStringBase<wchar_t> *)0x0,1,0,
                 unaff_ESI);
      *local_8 = 0;
      pSVar4 = (SHeaderCommunity *)0x0;
    }
  }
  RemoveAllWhiteSpaces
            ((CFastString *)&stack0xfffffff4,(CFastString *)PTR_DAT_00d34100,in_stack_ffffffec);
  if (local_8 == (undefined1 *)0x0) {
    *(undefined4 *)param_4 = 0;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_8,in_stack_fffffff0);
    ExceptionList = param_1;
    return 0;
  }
  if (in_stack_00000014 == 0) {
    iVar3 = 10;
  }
  else {
    iVar3 = 0x10;
  }
  uVar1 = _strtoul(local_4,(char **)0x0,iVar3);
  *(ulong *)param_4 = uVar1;
  if (uVar1 == 0) {
    RemoveAllWhiteSpaces
              ((CFastString *)&local_8,(CFastString *)&DAT_00b2efac,(char *)in_stack_fffffff0);
    bVar2 = local_4 == (char *)0x0;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_4,pSVar4);
    ExceptionList = param_2;
    return (uint)bVar2;
  }
  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_8,in_stack_fffffff0);
  ExceptionList = param_1;
  return 1;
}
}

// =================================================
// Function: CFastString::GetNextToken
// =================================================
int __thiscall
CFastString::GetNextToken(CFastString *this,CFastStringInt *param_1,SFastTokenInt *param_2)
{
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  SStringParam *unaff_EBP;
  char *pcVar4;
  char *local_8;
  uint local_4;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if (*(uint *)this < *(uint *)(param_1 + 0x14)) {
    *(uint *)param_1 = *(uint *)param_1 & 0xfffffffe;
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    if (*(int *)(param_1 + 8) != 0) {
      *(undefined4 *)(param_1 + 8) = 0;
      **(undefined1 **)(param_1 + 0xc) = 0;
    }
    return 0;
  }
  pcVar4 = (char *)(*(int *)(this + 4) + *(uint *)(param_1 + 0x14));
  if (*pcVar4 == '\0') {
    *(uint *)param_1 = *(uint *)param_1 & 0xfffffffe;
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    if (*(int *)(param_1 + 8) != 0) {
      *(undefined4 *)(param_1 + 8) = 0;
      **(undefined1 **)(param_1 + 0xc) = 0;
    }
    return 0;
  }
  uVar2 = _strcspn(pcVar4,*(char **)(param_1 + 0x18));
  *(int *)(param_1 + 4) = (int)pcVar4 - *(int *)(this + 4);
  local_8 = pcVar4;
  local_4 = uVar2;
  SetString((CFastString *)(param_1 + 8),(CFastStringInt *)&local_8,unaff_EBP);
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  cVar1 = pcVar4[uVar2];
  pcVar4 = pcVar4 + uVar2;
  if (((byte)*param_1 & 2) == 0) {
    if ((cVar1 != '\0') &&
       (pcVar3 = _strchr(*(char **)(param_1 + 0x18),(int)cVar1), pcVar3 != (char *)0x0)) {
      pcVar4 = pcVar4 + 1;
    }
  }
  else {
    while ((cVar1 != '\0' &&
           (pcVar3 = _strchr(*(char **)(param_1 + 0x18),(int)cVar1), pcVar3 != (char *)0x0))) {
      cVar1 = pcVar4[1];
      pcVar4 = pcVar4 + 1;
    }
  }
  *(int *)(param_1 + 0x14) = (int)pcVar4 - *(int *)(this + 4);
  *(uint *)param_1 = *(uint *)param_1 ^ ((uint)(*pcVar4 == '\0') ^ *(uint *)param_1) & 1;
  return 1;
}
}

// =================================================
// Function: CFastString::GetReal
// =================================================
int __thiscall CFastString::GetReal(CFastString *this,CFastString *param_1,float *param_2)
{
{
  int iVar1;
  int extraout_EAX;
  char *unaff_ESI;
  int iVar2;
  double dVar3;
  SHeaderCommunity *pSVar4;
  float *in_stack_0000000c;
  void *in_stack_0000001c;
  undefined4 uStack00000020;
  SHeaderCommunity *in_stack_ffffffe4;
  int in_stack_ffffffe8;
  float fVar5;
  int in_stack_fffffff0;
  char *pcVar6;
  int *piVar7;
  int *piVar8;
  
  piVar8 = (int *)0xffffffff;
  piVar7 = (int *)&LAB_00ae0b48;
  pcVar6 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  CFastString((CFastString *)&stack0xffffffec,this,(char *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  pSVar4 = (SHeaderCommunity *)0x0;
  RemoveAllWhiteSpaces((CFastString *)&stack0xfffffff0,(CFastString *)PTR_DAT_00d34100,unaff_ESI);
  if (pcVar6 == (char *)0x0) {
    *in_stack_0000000c = 0.0;
    param_1 = (CFastString *)0xffffffff;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xfffffff4,in_stack_ffffffe4);
    ExceptionList = pSVar4;
    return 0;
  }
  dVar3 = _atof((char *)piVar7);
  fVar5 = (float)dVar3;
  *in_stack_0000000c = fVar5;
  if (fVar5 == 0.0) {
    iVar2 = 1;
    iVar1 = TruncAfterChar((CFastString *)&stack0xfffffff4,(CFastString *)0x64,'\x01',
                           (int)in_stack_ffffffe4);
    if (iVar1 == 0) {
      iVar1 = TruncAfterChar((CFastString *)&stack0xfffffff8,(CFastString *)&DAT_00000044,'\x01',
                             in_stack_ffffffe8);
      if (iVar1 == 0) {
        iVar1 = TruncAfterChar((CFastString *)&stack0xfffffffc,(CFastString *)&DAT_00000065,'\x01',
                               (int)fVar5);
        if (iVar1 == 0) {
          TruncAfterChar((CFastString *)&stack0x00000000,(CFastString *)0x45,'\x01',
                         in_stack_fffffff0);
        }
      }
    }
    if ((param_1 != (CFastString *)0x0) && ((*(char *)param_2 == '+' || (*(char *)param_2 == '-'))))
    {
      TruncBefore((CFastString *)&param_1,param_1 + -1,(ulong)pcVar6);
    }
    RemoveAllWhiteSpaces((CFastString *)&param_1,(CFastString *)&DAT_00b2efac,pcVar6);
    if (param_2 != (float *)0x0) {
      pSVar4 = (SHeaderCommunity *)&DAT_00b2c98c;
      param_1 = (CFastString *)0x1;
      Compare((CFastString *)&param_2,(SParam_Fids *)&stack0x00000000,(SParam *)0x0,piVar7,piVar8);
      if (extraout_EAX != 0) {
        iVar2 = 0;
      }
    }
    uStack00000020 = 0xffffffff;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0x00000010,pSVar4);
    ExceptionList = in_stack_0000001c;
    return iVar2;
  }
  param_1 = (CFastString *)0xffffffff;
  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xfffffff4,in_stack_ffffffe4);
  ExceptionList = pSVar4;
  return 1;
}
}

// =================================================
// Function: CFastString::InternalVFormat
// =================================================
void __thiscall
CFastString::InternalVFormat(CFastString *this,CFastString *param_1,char *param_2,char *param_3)
{
{
  SStringParam *unaff_EBP;
  char *pcVar1;
  uint uVar2;
  char *local_8;
  int local_4;
  
  uVar2 = 0x400;
  if (DAT_00d71c98 == 0) {
    pcVar1 = &DAT_00d71898;
  }
  else {
    pcVar1 = operator_new__(0x400);
  }
  DAT_00d71c98 = DAT_00d71c98 + 1;
  local_4 = __vsnprintf(pcVar1,0x400,(char *)param_1,param_2);
  while (local_4 < 0) {
    uVar2 = uVar2 + 0x100;
    if (pcVar1 != &DAT_00d71898) {
      operator_delete__(pcVar1);
    }
    pcVar1 = operator_new__(uVar2);
    local_4 = __vsnprintf(pcVar1,uVar2,(char *)param_1,param_2);
  }
  local_8 = pcVar1;
  SetString(this,(CFastStringInt *)&local_8,unaff_EBP);
  if (pcVar1 != &DAT_00d71898) {
    operator_delete__(pcVar1);
  }
  DAT_00d71c98 = DAT_00d71c98 + -1;
  return;
}
}

// =================================================
// Function: CFastString::RemoveAllWhiteSpaces
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
CFastString::RemoveAllWhiteSpaces(CFastString *this,CFastString *param_1,char *param_2)
{
{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  uint uVar5;
  SStringParam *unaff_EDI;
  int iVar6;
  CFastString *local_30;
  int local_2c;
  CFastString *local_28;
  undefined1 local_24 [4];
  undefined1 local_20 [28];
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)&stack0xffffffcc;
  uVar1 = *(uint *)this;
  iVar2 = *(int *)(this + 4);
  iVar6 = 0;
  local_30 = param_1;
  local_28 = this;
  if (uVar1 < 0x20) {
    puVar3 = local_24;
  }
  else {
    puVar3 = operator_new__(uVar1);
  }
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      pcVar4 = _strchr((char *)local_30,(int)*(char *)(uVar5 + iVar2));
      if (pcVar4 == (char *)0x0) {
        puVar3[iVar6] = *(undefined1 *)(uVar5 + iVar2);
        iVar6 = iVar6 + 1;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  local_30 = (CFastString *)puVar3;
  local_2c = iVar6;
  SetString(local_28,(CFastStringInt *)&local_30,unaff_EDI);
  if (local_30 != (CFastString *)local_20) {
    operator_delete__(local_30);
  }
  return;
}
}

// =================================================
// Function: CFastString::ReplaceFirst
// =================================================
int __thiscall
CFastString::ReplaceFirst
          (CFastString *this,CFastString *param_1,SStringParam *param_2,SStringParam *param_3,
          ulong param_4,ulong param_5)
{
{
  CFastStringBase<wchar_t> *pCVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  SOldChars *pSVar5;
  uint uVar6;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_ESI;
  SOldChars *unaff_EDI;
  int iVar7;
  void *unaff_retaddr;
  int in_stack_00000018;
  CFastStringBase<wchar_t> *local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae0c58;
  local_c = ExceptionList;
  pSVar5 = (SOldChars *)(DAT_00cca150 ^ (uint)&stack0xffffffd4);
  ExceptionList = &local_c;
  uVar6 = FindFirst(this,(CFastStringInt *)param_1,(ulong)param_3,1);
  iVar7 = 0;
  while( true ) {
    if (uVar6 == 0xffffffff) {
      ExceptionList = unaff_retaddr;
      return iVar7;
    }
    iVar7 = *(int *)(param_1 + 4);
    iVar2 = *(int *)this;
    uVar3 = *(uint *)(param_2 + 4);
    pCVar1 = (CFastStringBase<wchar_t> *)((iVar2 - iVar7) + uVar3);
    local_14 = (CFastStringBase<wchar_t> *)0x0;
    local_10 = (void *)0x0;
    local_4 = 0;
    CFastStringBase<char>::AllocAtLeast
              ((CFastStringBase<char> *)this,pCVar1,0,(int)&local_14,pSVar5);
    pvVar4 = *(void **)(this + 4);
    if ((pvVar4 != local_10) && (uVar6 != 0)) {
      _memcpy(pvVar4,local_10,uVar6);
    }
    _memmove((void *)((int)pvVar4 + uVar6 + uVar3),
             (CFastStringBase<wchar_t> *)((int)local_10 + (int)pCVar1) + uVar6,
             ((iVar2 - iVar7) - uVar6) + 1);
    _memcpy((void *)((int)pvVar4 + uVar6),*(void **)param_3,uVar3);
    pCVar1 = local_14;
    pSVar5 = (SOldChars *)(uVar6 + uVar3);
    if (local_14 != *(CFastStringBase<wchar_t> **)this) {
      CFastStringBase<char>::AllocAtLeast((CFastStringBase<char> *)this,local_14,1,0,unaff_EDI);
      pCVar1[*(int *)(this + 4)] = (CFastStringBase<wchar_t>)0x0;
      *(CFastStringBase<wchar_t> **)this = pCVar1;
    }
    if (in_stack_00000018 == 0) break;
    iVar7 = 1;
    in_stack_00000018 = in_stack_00000018 + -1;
    if (in_stack_00000018 == 0) break;
    uVar6 = FindFirst(this,(CFastStringInt *)param_3,(ulong)pSVar5,1);
    param_1 = (CFastString *)0xffffffff;
    unaff_EDI = (SOldChars *)0x901c84;
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(&local_c,unaff_ESI);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(&local_c,unaff_ESI);
  ExceptionList = unaff_retaddr;
  return 1;
}
}

// =================================================
// Function: CFastString::SetLength
// =================================================
void __thiscall
CFastString::SetLength
          (CFastString *this,CFastString *param_1,ulong param_2,int param_3,char param_4)
{
{
  CFastString *pCVar1;
  SOldChars *unaff_EDI;
  
  pCVar1 = *(CFastString **)this;
  if (param_1 != pCVar1) {
    CFastStringBase<char>::AllocAtLeast
              ((CFastStringBase<char> *)this,(CFastStringBase<wchar_t> *)param_1,1,0,unaff_EDI);
    param_1[*(int *)(this + 4)] = (CFastString)0x0;
    *(CFastString **)this = param_1;
  }
  if ((param_3 != 0) && (pCVar1 < param_1)) {
    _memset(pCVar1 + *(int *)(this + 4),(int)param_4,(int)param_1 - (int)pCVar1);
  }
  return;
}
}

// =================================================
// Function: CFastString::SetNat64
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
CFastString::SetNat64
          (CFastString *this,CFastString *param_1,uint64 param_2,int param_3,ulong param_4,
          int param_5,int param_6,int param_7)
{
{
  char cVar1;
  CFastString CVar2;
  char *pcVar3;
  CFastString *pCVar4;
  CFastString *pCVar5;
  CFastString *pCVar6;
  CFastString CVar7;
  CFastString *pCVar8;
  int iVar9;
  uint uVar10;
  char unaff_DI;
  CFastString *pCVar11;
  undefined1 auStack_48 [4];
  CFastString *local_44;
  CFastString *local_40;
  CFastString *local_3c;
  CFastString *local_38;
  CFastString *local_34;
  uint local_30;
  undefined1 uStack_2c;
  undefined4 local_2b;
  undefined4 local_27;
  undefined2 local_23;
  undefined1 local_21;
  char local_20 [4];
  CFastString local_1c [24];
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)auStack_48;
  local_30 = 0;
  uStack_2c = 0;
  local_2b = 0;
  local_27 = 0;
  local_23 = 0;
  local_21 = 0;
  if (param_4 == 0) {
    pcVar3 = "%I64d";
  }
  else {
    if (param_2._4_4_ != (CFastString *)0x0) {
      pcVar3 = "0x%%.%dI64X";
      if (param_5 == 0) {
        pcVar3 = "%%.%dI64X";
      }
      sprintf_s<16>((char *)&local_30,pcVar3);
      goto LAB_008ff3b1;
    }
    if (param_5 == 0) {
      pcVar3 = "%I64X";
    }
    else {
      pcVar3 = "0x%I64X";
    }
  }
  _strcpy_s((char *)&local_30,0x10,pcVar3);
LAB_008ff3b1:
  sprintf_s<25>(local_20,(char *)&local_30);
  pcVar3 = local_20;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pCVar8 = (CFastString *)(pcVar3 + -(int)(local_20 + 1));
  local_38 = pCVar8;
  if ((param_4 != 0) && (param_5 != 0)) {
    local_38 = pCVar8 + -2;
  }
  local_34 = (CFastString *)((param_4 != 0) + 3);
  pCVar4 = pCVar8;
  if ((int)param_2 != 0) {
    if (local_38 < (CFastString *)0x2) {
      pCVar4 = (CFastString *)0x0;
    }
    else {
      pCVar4 = local_38 + -1;
    }
    pCVar4 = pCVar8 + (uint)pCVar4 / (uint)local_34;
  }
  if (pCVar4 < param_2._4_4_) {
    pCVar4 = param_2._4_4_;
  }
  SetLength(this,pCVar4,0,0x20,unaff_DI);
  local_38 = *(CFastString **)(this + 4);
  CVar7 = (CFastString)((-(param_4 != 0) & 0x10U) + 0x20);
  local_44 = (CFastString *)CONCAT31(local_44._1_3_,CVar7);
  if ((int)param_2 == 0) {
    uVar10 = (int)pCVar4 - (int)pCVar8;
    _memcpy((void *)(uVar10 + (int)local_38),local_1c,(uint)(pCVar8 + 1));
    if (uVar10 != 0) {
      _memset(local_38,(int)local_44,uVar10);
    }
  }
  else {
    pCVar5 = (CFastString *)0x0;
    pCVar11 = (CFastString *)0x0;
    *(CFastString *)((int)local_38 + (int)pCVar4) = (CFastString)0x0;
    local_40 = (CFastString *)0x0;
    if (pCVar8 != (CFastString *)0x0) {
      local_44 = (CFastString *)(local_20 + 3 + (int)pCVar8);
      local_3c = (CFastString *)0x1;
      pCVar6 = pCVar4 + (int)local_38 + -1;
      do {
        if ((((local_3c < pCVar4) && (pCVar11 != (CFastString *)0x0)) &&
            ((uint)pCVar11 % local_30 == 0)) && ((param_5 == 0 || (pCVar11 < local_34)))) {
          local_40 = local_40 + 1;
          local_3c = local_3c + 1;
          *pCVar6 = (CFastString)0x20;
          pCVar6 = pCVar6 + -1;
        }
        CVar2 = *local_44;
        pCVar5 = local_40 + 1;
        local_3c = local_3c + 1;
        local_44 = local_44 + -1;
        *pCVar6 = CVar2;
        pCVar11 = pCVar11 + 1;
        pCVar6 = pCVar6 + -1;
        local_40 = pCVar5;
      } while (pCVar11 < pCVar8);
    }
    if (pCVar5 < pCVar4) {
      pCVar8 = pCVar4 + (int)local_38 + (-1 - (int)pCVar5);
      iVar9 = (int)pCVar4 - (int)pCVar5;
      do {
        *pCVar8 = CVar7;
        pCVar8 = pCVar8 + -1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CFastString::SetNatural
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
CFastString::SetNatural
          (CFastString *this,CFastString *param_1,ulong param_2,int param_3,ulong param_4,
          int param_5,int param_6,int param_7)
{
{
  char cVar1;
  CFastString CVar2;
  CFastString CVar3;
  char *pcVar4;
  CFastString *pCVar5;
  CFastString *pCVar6;
  CFastString *pCVar7;
  CFastString *pCVar8;
  int iVar9;
  uint uVar10;
  char unaff_DI;
  CFastString *pCVar11;
  undefined1 auStack_34 [4];
  CFastString *local_30;
  int local_2c;
  CFastString *local_28;
  CFastString *local_24;
  void *local_20;
  uint local_1c;
  undefined1 uStack_18;
  undefined2 local_17;
  undefined1 local_15;
  char local_14 [4];
  CFastString local_10 [12];
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)auStack_34;
  local_1c = 0;
  uStack_18 = 0;
  local_17 = 0;
  local_15 = 0;
  if (param_5 == 0) {
    pcVar4 = "%d";
  }
  else {
    if (param_3 != 0) {
      pcVar4 = "0x%%.%dX";
      if (param_6 == 0) {
        pcVar4 = "%%.%dX";
      }
      sprintf_s<8>((char *)&local_1c,pcVar4);
      goto LAB_008ff189;
    }
    if (param_6 == 0) {
      pcVar4 = "%X";
    }
    else {
      pcVar4 = "0x%X";
    }
  }
  _strcpy_s((char *)&local_1c,8,pcVar4);
LAB_008ff189:
  sprintf_s<16>(local_14,(char *)&local_1c);
  pcVar4 = local_14;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pCVar8 = (CFastString *)(pcVar4 + -(int)(local_14 + 1));
  local_28 = pCVar8;
  if ((param_5 != 0) && (param_6 != 0)) {
    local_28 = pCVar8 + -2;
  }
  local_20 = (void *)((param_5 != 0) + 3);
  pCVar5 = pCVar8;
  if (param_2 != 0) {
    if (local_28 < (CFastString *)0x2) {
      pCVar5 = (CFastString *)0x0;
    }
    else {
      pCVar5 = local_28 + -1;
    }
    pCVar5 = pCVar8 + (uint)pCVar5 / (uint)local_20;
  }
  if (pCVar5 < (uint)param_3) {
    pCVar5 = (CFastString *)param_3;
  }
  SetLength(this,pCVar5,0,0x20,unaff_DI);
  local_20 = *(void **)(this + 4);
  CVar3 = (CFastString)((-(param_5 != 0) & 0x10U) + 0x20);
  local_2c = CONCAT31(local_2c._1_3_,CVar3);
  if (param_2 == 0) {
    uVar10 = (int)pCVar5 - (int)pCVar8;
    _memcpy((void *)((int)local_20 + uVar10),local_10,(uint)(pCVar8 + 1));
    if (uVar10 != 0) {
      _memset(local_20,local_2c,uVar10);
    }
  }
  else {
    pCVar7 = (CFastString *)0x0;
    pCVar11 = (CFastString *)0x0;
    *(CFastString *)((int)local_20 + (int)pCVar5) = (CFastString)0x0;
    if (pCVar8 != (CFastString *)0x0) {
      local_28 = (CFastString *)(local_14 + 3 + (int)pCVar8);
      local_30 = (CFastString *)0x1;
      pCVar6 = pCVar5 + (int)local_20 + -1;
      do {
        if ((((local_30 < pCVar5) && (pCVar11 != (CFastString *)0x0)) &&
            ((uint)pCVar11 % local_1c == 0)) && ((param_6 == 0 || (pCVar11 < local_24)))) {
          local_30 = local_30 + 1;
          *pCVar6 = (CFastString)0x20;
          pCVar7 = pCVar7 + 1;
          pCVar6 = pCVar6 + -1;
        }
        CVar2 = *local_28;
        local_30 = local_30 + 1;
        local_28 = local_28 + -1;
        *pCVar6 = CVar2;
        pCVar11 = pCVar11 + 1;
        pCVar7 = pCVar7 + 1;
        pCVar6 = pCVar6 + -1;
      } while (pCVar11 < pCVar8);
    }
    if (pCVar7 < pCVar5) {
      pCVar8 = pCVar5 + (int)local_20 + (-1 - (int)pCVar7);
      iVar9 = (int)pCVar5 - (int)pCVar7;
      do {
        *pCVar8 = CVar3;
        pCVar8 = pCVar8 + -1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CFastString::SetReal
// =================================================
void __thiscall
CFastString::SetReal(CFastString *this,CFastString *param_1,float param_2,ulong param_3)
{
{
  char *pcVar1;
  SStringParam *unaff_ESI;
  undefined1 *local_8;
  char *local_4;
  
  sprintf_s<8>(&DAT_00d71ce0,"%%.%ug");
  sprintf_s<32>(&DAT_00d71cc0,&DAT_00d71ce0);
  local_8 = &DAT_00d71cc0;
  pcVar1 = &DAT_00d71cc0;
  do {
    local_4 = pcVar1;
    pcVar1 = local_4 + 1;
  } while (*local_4 != '\0');
  local_4 = local_4 + -0xd71cc0;
  SetString(this,(CFastStringInt *)&local_8,unaff_ESI);
  return;
}
}

// =================================================
// Function: CFastString::SetRealWithoutExponent
// =================================================
void __thiscall
CFastString::SetRealWithoutExponent
          (CFastString *this,CFastString *param_1,float param_2,ulong param_3)
{
{
  char *pcVar1;
  SStringParam *unaff_ESI;
  undefined1 *local_8;
  char *local_4;
  
  sprintf_s<8>(&DAT_00d71d08,"%%.%uf");
  sprintf_s<32>(&DAT_00d71ce8,&DAT_00d71d08);
  local_8 = &DAT_00d71ce8;
  pcVar1 = &DAT_00d71ce8;
  do {
    local_4 = pcVar1;
    pcVar1 = local_4 + 1;
  } while (*local_4 != '\0');
  local_4 = local_4 + -0xd71ce8;
  SetString(this,(CFastStringInt *)&local_8,unaff_ESI);
  return;
}
}

// =================================================
// Function: CFastString::SetString
// =================================================
void __thiscall
CFastString::SetString(CFastString *this,CFastStringInt *param_1,SStringParam *param_2)
{
{
  char unaff_DI;
  
  if (*(int *)(this + 4) != *(int *)param_1) {
    SetLength(this,*(CFastString **)(param_1 + 4),0,0x20,unaff_DI);
    if (*(uint *)(param_1 + 4) != 0) {
      _memmove(*(void **)(this + 4),*(void **)param_1,*(uint *)(param_1 + 4));
    }
  }
  return;
}
}

// =================================================
// Function: CFastString::TrimLeft
// =================================================
void __thiscall CFastString::TrimLeft(CFastString *this,CFastString *param_1,char *param_2)
{
{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  ulong unaff_EDI;
  
  iVar1 = *(int *)(this + 4);
  uVar2 = *(uint *)this;
  uVar4 = 0;
  if (uVar2 != 0) {
    do {
      pcVar3 = _strchr((char *)param_1,(int)*(char *)(uVar4 + iVar1));
      if (pcVar3 == (char *)0x0) break;
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
    if (uVar4 != 0) {
      TruncBefore(this,(CFastString *)(*(int *)this - uVar4),unaff_EDI);
    }
  }
  return;
}
}

// =================================================
// Function: CFastString::TrimRight
// =================================================
void __thiscall CFastString::TrimRight(CFastString *this,CFastString *param_1,char *param_2)
{
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  ulong unaff_ESI;
  int iVar4;
  
  iVar1 = *(int *)(this + 4);
  if (*(int *)this != 0) {
    iVar2 = *(int *)this + -1;
    iVar4 = iVar2;
    while ((-1 < iVar4 &&
           (pcVar3 = _strchr((char *)param_1,(int)*(char *)(iVar4 + iVar1)), pcVar3 != (char *)0x0))
          ) {
      iVar4 = iVar4 + -1;
    }
    if (iVar4 < iVar2) {
      TruncAfter(this,(CFastString *)(iVar4 + 1),unaff_ESI);
    }
  }
  return;
}
}

// =================================================
// Function: CFastString::TruncAfter
// =================================================
void __thiscall CFastString::TruncAfter(CFastString *this,CFastString *param_1,ulong param_2)
{
{
  SOldChars *unaff_EDI;
  
  if (param_1 < *(CFastString **)this) {
    CFastStringBase<char>::AllocAtLeast
              ((CFastStringBase<char> *)this,(CFastStringBase<wchar_t> *)param_1,1,0,unaff_EDI);
    param_1[*(int *)(this + 4)] = (CFastString)0x0;
    *(CFastString **)this = param_1;
  }
  return;
}
}

// =================================================
// Function: CFastString::TruncAfterChar
// =================================================
int __thiscall
CFastString::TruncAfterChar(CFastString *this,CFastString *param_1,char param_2,int param_3)
{
{
  CFastString *pCVar1;
  CFastString *pCVar2;
  ulong unaff_ESI;
  ulong unaff_retaddr;
  
  pCVar1 = (CFastString *)FindFirst(this,(CFastStringInt *)param_1,0,unaff_ESI);
  if (pCVar1 + 1 == (CFastString *)0x0) {
    return 0;
  }
  pCVar2 = pCVar1 + 1;
  if (param_3 != 0) {
    pCVar2 = pCVar1;
  }
  TruncAfter(this,pCVar2,unaff_retaddr);
  return 1;
}
}

// =================================================
// Function: CFastString::TruncBefore
// =================================================
void __thiscall CFastString::TruncBefore(CFastString *this,CFastString *param_1,ulong param_2)
{
{
  CFastString *pCVar1;
  SOldChars *unaff_EDI;
  
  pCVar1 = *(CFastString **)this;
  if ((param_1 < pCVar1 || param_1 == pCVar1) && (param_1 != pCVar1)) {
    if (param_1 != (CFastString *)0x0) {
      _memmove(*(void **)(this + 4),pCVar1 + ((int)*(void **)(this + 4) - (int)param_1),
               (uint)param_1);
    }
    if (param_1 != *(CFastString **)this) {
      CFastStringBase<char>::AllocAtLeast
                ((CFastStringBase<char> *)this,(CFastStringBase<wchar_t> *)param_1,1,0,unaff_EDI);
      param_1[*(int *)(this + 4)] = (CFastString)0x0;
      *(CFastString **)this = param_1;
    }
  }
  return;
}
}

// =================================================
// Function: CFastString::UpCase
// =================================================
void __thiscall
CFastString::UpCase(CFastString *this,CFastString *param_1,ulong param_2,ulong param_3)
{
{
  CFastString *pCVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  pCVar1 = *(CFastString **)this;
  if ((param_1 < pCVar1) && (pCVar1 != (CFastString *)0x0)) {
    if ((uint)((int)pCVar1 - (int)param_1) < param_2) {
      param_2 = (int)pCVar1 - (int)param_1;
    }
    iVar2 = *(int *)(this + 4);
    uVar4 = 0;
    if (param_2 != 0) {
      do {
        iVar3 = _toupper((int)(char)param_1[uVar4 + iVar2]);
        param_1[uVar4 + iVar2] = SUB41(iVar3,0);
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_2);
    }
  }
  return;
}
}

// =================================================
// Function: CFastString::operator<<
// =================================================
CPlugFileGpuBuilder * __thiscall
CFastString::operator<<(CFastString *this,CPlugFileGpuBuilder *param_1,char *param_2)
{
{
  SStringParam *unaff_ESI;
  undefined4 local_8;
  undefined4 local_4;
  
  CFastStringInt::GetLatin1(param_1,(CFastStringInt *)&DAT_00d71d68);
  local_4 = DAT_00d71d68;
  local_8 = DAT_00d71d6c;
  Concat(this,(CFastStringInt *)&local_8,unaff_ESI);
  return (CPlugFileGpuBuilder *)this;
}
}

