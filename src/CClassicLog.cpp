// Class implementation: CClassicLog

// =================================================
// Function: CClassicLog::AddLogStringInFile
// =================================================
void __cdecl CClassicLog::AddLogStringInFile(void)
{
{
  InternalAddLogString(0,1,0);
  return;
}
}

// =================================================
// Function: CClassicLog::ConsoleAddLogString
// =================================================
void __cdecl CClassicLog::ConsoleAddLogString(ulong param_1,CFastString *param_2)
{
{
  CFastString *pCVar1;
  SSystemTime *pSVar2;
  HANDLE hConsoleOutput;
  SLadderResult *unaff_ESI;
  SSystemTime *unaff_EDI;
  void *lpBuffer;
  DWORD nNumberOfCharsToWrite;
  ulong *lpNumberOfCharsWritten;
  LPVOID lpReserved;
  CGameAdvertisingRadial *pCVar3;
  CFastString *in_stack_ffffffec;
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  pCVar1 = param_2;
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a94d26;
  local_c = ExceptionList;
  pSVar2 = (SSystemTime *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  if ((param_1 & DAT_00cdae84) != 0) {
    if ((DAT_00d66ff8 != 0) && (*(int *)(DAT_00d66ff8 + 0xac) != 0)) {
      nNumberOfCharsToWrite = *(DWORD *)param_2;
      lpBuffer = *(void **)(param_2 + 4);
      lpReserved = (LPVOID)0x0;
      lpNumberOfCharsWritten = &param_1;
      param_1 = 0;
      hConsoleOutput = GetStdHandle(0xfffffff5);
      WriteConsoleA(hConsoleOutput,lpBuffer,nNumberOfCharsToWrite,lpNumberOfCharsWritten,lpReserved)
      ;
    }
    if (*(int *)(DAT_00d66ff8 + 0xec) != 0) {
      SSystemTime::SSystemTime(&stack0xffffffec,pSVar2);
      SSystemTime::SetFromLocalTime(local_10,unaff_EDI);
      if ((DAT_00d6701c & 1) == 0) {
        DAT_00d6701c = DAT_00d6701c | 1;
        param_1 = 0;
        CGameMasterServer::SLadderResult::SLadderResult(&DAT_00d67014,unaff_ESI);
        _atexit(`public:_static_void___cdecl_CClassicLog::
                ConsoleAddLogString(unsigned_long,class_CFastString_const&)'::__l10::
                _dynamic_atexit_destructor_for__TimeStamp__);
        param_2 = (CFastString *)0xffffffff;
      }
      SSystemTime::GetAsString_YMD_HMS
                (&local_8,(SSystemTime *)&DAT_00d67014,(CFastString *)0x1,in_stack_ffffffec);
      (**(code **)(**(int **)(DAT_00d66ff8 + 0xec) + 8))();
      unaff_EDI = *(SSystemTime **)pCVar1;
      pSVar2 = *(SSystemTime **)(pCVar1 + 4);
      pCVar3 = (CGameAdvertisingRadial *)0x52b879;
      (**(code **)(**(int **)(DAT_00d66ff8 + 0xec) + 8))();
      CSystemFile::Flush(*(CSystemFile **)(DAT_00d66ff8 + 0xec),pCVar3);
    }
    if (pCVar1 == (CFastString *)&DAT_00d71e54) {
      CFastString::CFastString
                ((CFastString *)&stack0xffffffec,(CFastString *)&DAT_00d71e54,(char *)pSVar2);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(local_10,(SHeaderCommunity *)unaff_EDI)
      ;
    }
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CClassicLog::FlushWhenTimeOut
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CClassicLog::FlushWhenTimeOut(CClassicLog *this,CClassicLog *param_1,int param_2)
{
{
  int iVar1;
  basic_ostream<char,struct_std::char_traits<char>_> *unaff_ESI;
  
  if (*(int *)(this + 8) == 0) {
    if (param_1 == (CClassicLog *)0x0) {
      return;
    }
  }
  else {
    iVar1 = _DAT_00d71e7c;
    if ((param_1 == (CClassicLog *)0x0) &&
       (iVar1 = (**(code **)(this + 0x10))(), (uint)(iVar1 - _DAT_00d71e7c) < DAT_00d34134)) {
      return;
    }
    _DAT_00d71e7c = iVar1;
    (**(code **)(this + 0xc))(this);
  }
  if (*(basic_ostream<char,struct_std::char_traits<char>_> **)(this + 0x14) !=
      (basic_ostream<char,struct_std::char_traits<char>_> *)0x0) {
    std::basic_ostream<char,struct_std::char_traits<char>_>::flush
              (*(basic_ostream<char,struct_std::char_traits<char>_> **)(this + 0x14),unaff_ESI);
  }
  if (*(basic_ostream<char,struct_std::char_traits<char>_> **)(this + 0x28) !=
      (basic_ostream<char,struct_std::char_traits<char>_> *)0x0) {
    std::basic_ostream<char,struct_std::char_traits<char>_>::flush
              (*(basic_ostream<char,struct_std::char_traits<char>_> **)(this + 0x28),unaff_ESI);
  }
  return;
}
}

// =================================================
// Function: CClassicLog::InternalAddLogString
// =================================================
void __cdecl CClassicLog::InternalAddLogString(int param_1,int param_2,int param_3)
{
{
  int unaff_retaddr;
  
  if (DAT_00d71d88 == 0) {
    if (((param_2 != 0) &&
        (DAT_00d71e34 == (basic_ostream<char,struct_std::char_traits<char>_> *)0x0)) ||
       (param_3 != 0)) {
      if (DAT_00d71e24 == (basic_ostream<char,struct_std::char_traits<char>_> *)0x0) {
        param_2 = 1;
      }
      else {
        std::operator<<<struct_std::char_traits<char>_>(DAT_00d71e24,DAT_00d71e58);
      }
    }
    if (((DAT_00d71d8c != 0) || (param_2 != 0)) &&
       (DAT_00d71e34 != (basic_ostream<char,struct_std::char_traits<char>_> *)0x0)) {
      std::operator<<<struct_std::char_traits<char>_>(DAT_00d71e34,DAT_00d71e58);
    }
    if (((DAT_00d71d90 != 0) || (param_2 != 0)) &&
       (DAT_00d71e48 != (basic_ostream<char,struct_std::char_traits<char>_> *)0x0)) {
      std::operator<<<struct_std::char_traits<char>_>(DAT_00d71e48,DAT_00d71e58);
    }
    if ((DAT_00d71e24 == (basic_ostream<char,struct_std::char_traits<char>_> *)0x0) &&
       (DAT_00d71de0 < 0x25a0)) {
      std::operator<<<struct_std::char_traits<char>_>
                ((basic_ostream<char,struct_std::char_traits<char>_> *)&DAT_00d71de8,DAT_00d71e58);
    }
    FlushWhenTimeOut((CClassicLog *)&DAT_00d71e20,(CClassicLog *)param_1,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CClassicLog::SetOutputFile
// =================================================
void __thiscall
CClassicLog::SetOutputFile
          (CClassicLog *this,CClassicLog *param_1,CFastStringInt *param_2,CFastStringInt *param_3,
          int param_4)
{
{
  CFastStringInt *this_00;
  basic_ostream<char,struct_std::char_traits<char>_> *extraout_EAX;
  int *piVar1;
  SStringParam *unaff_EBX;
  SStringParam *unaff_EBP;
  SStringParam *unaff_ESI;
  basic_ostream<char,struct_std::char_traits<char>_> *this_01;
  ulong unaff_EDI;
  int *in_stack_00000014;
  basic_ofstream<char,struct_std::char_traits<char>_> *pbStack00000018;
  int in_stack_00000024;
  char *in_stack_ffffffe0;
  SHeaderCommunity *in_stack_ffffffe4;
  undefined4 local_10;
  void *local_c;
  basic_ofstream<char,struct_std::char_traits<char>_> *local_8;
  int local_4;
  
  local_4 = 0xffffffff;
  local_8 = (basic_ofstream<char,struct_std::char_traits<char>_> *)&LAB_00ae1aeb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastStringBase<char>::PreAlloc
            ((CFastStringBase<char> *)&DAT_00d71e54,(CClassicBufferMemory *)0xfa0,
             DAT_00cca150 ^ (uint)&stack0xffffffd0);
  CFastStringBase<char>::PreAlloc
            ((CFastStringBase<char> *)&DAT_00d71e5c,(CClassicBufferMemory *)0x100,unaff_EDI);
  local_c = *(void **)param_3;
  local_10 = *(undefined4 *)(param_3 + 4);
  local_8 = (basic_ofstream<char,struct_std::char_traits<char>_> *)0x0;
  CFastStringInt::SetString(this + 0x20,(CFastStringInt *)&local_10,unaff_ESI);
  if (*in_stack_00000014 != 0) {
    local_8 = *(basic_ofstream<char,struct_std::char_traits<char>_> **)param_3;
    local_c = *(void **)(param_3 + 4);
    this_00 = (CFastStringInt *)(this + 0x18);
    local_4 = 0;
    CFastStringInt::SetString(this_00,(CFastStringInt *)&local_c,unaff_EBP);
    local_4 = *in_stack_00000014;
    local_8 = (basic_ofstream<char,struct_std::char_traits<char>_> *)in_stack_00000014[1];
    CFastStringInt::Concat(this_00,(CFastStringInt *)&local_8,unaff_EBX);
    local_c = (void *)0x0;
    local_8 = (basic_ofstream<char,struct_std::char_traits<char>_> *)PTR_DAT_00bbf7d8;
    CSystemFileName_ConvertToSystemName_AndCreate(this_00,(CFastString *)&local_c);
    pbStack00000018 = operator_new(0x88);
    if (pbStack00000018 == (basic_ofstream<char,struct_std::char_traits<char>_> *)0x0) {
      this_01 = (basic_ostream<char,struct_std::char_traits<char>_> *)0x0;
    }
    else {
      std::basic_ofstream<char,struct_std::char_traits<char>_>::
      basic_ofstream<char,struct_std::char_traits<char>_>
                (pbStack00000018,local_8,&DAT_00000032,0x40,1);
      this_01 = extraout_EAX;
    }
    param_4 = 1;
    piVar1 = *(int **)(this + 0x14);
    if ((piVar1 != (int *)0x0) || (piVar1 = *(int **)(this + 4), piVar1 != (int *)0x0)) {
      std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<
                (this_01,*(CPlugFileGpuBuilder **)(*(int *)(*piVar1 + 4) + 0x28 + (int)piVar1),
                 in_stack_ffffffe0);
    }
    piVar1 = *(int **)(this + 0x14);
    if ((piVar1 != (int *)0x0) && (piVar1 != &DAT_00d71de8)) {
      (*(code *)**(undefined4 **)(*(int *)(*piVar1 + 4) + (int)piVar1))();
    }
    *(basic_ostream<char,struct_std::char_traits<char>_> **)(this + 0x14) = this_01;
    if (in_stack_00000024 != 0) {
      *(undefined4 *)(this + 4) = 0;
    }
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_8,in_stack_ffffffe4);
  }
  ExceptionList = (void *)param_4;
  return;
}
}

