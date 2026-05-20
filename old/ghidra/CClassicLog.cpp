
/* public: virtual void * __thiscall CClassicLog::`scalar deleting
 * destructor'(unsigned int) */

void *__thiscall CClassicLog::`scalar_deleting_destructor'(CClassicLog *this,uint param_1)

{
  ~CClassicLog(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: static void __cdecl CClassicLog::AddLogStringInFile(void) */

void __cdecl CClassicLog::AddLogStringInFile(void)

{
  InternalAddLogString(0, 1, 0);
  return;
}

/* public: __thiscall CClassicLog::CClassicLog(void) */

CClassicLog *__thiscall CClassicLog::CClassicLog(CClassicLog *this)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00ae1359;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x18) = 0;
  *(wchar_t **)(this + 0x1c) = L"";
  *(undefined4 *)(this + 0x20) = 0;
  *(wchar_t **)(this + 0x24) = L"";
  *(undefined4 *)(this + 0x2c) = 0;
  *(wchar_t **)(this + 0x30) = L"";
  local_4 = 5;
  local_10 = 1;
  *(undefined4 **)(this + 4) = &DAT_00d71de8;
  *(undefined4 *)(this + 0x14) = 0;
  local_18 = 0;
  local_14 = 0;
  CFastStringInt::SetString((CFastStringInt *)(this + 0x2c),
                            (SStringParamInt *)&local_18);
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  ExceptionList = local_c;
  return this;
}

/* public: void __thiscall CClassicLog::Close(void) */

void __thiscall CClassicLog::Close(CClassicLog *this)

{
  int *piVar1;

  piVar1 = *(int **)(this + 0x14);
  if (piVar1 != (int *)0x0) {
    if (piVar1 != &DAT_00d71de8) {
      (***(code ***)(*(int *)(*piVar1 + 4) + (int)piVar1))(1);
    }
    *(undefined4 *)(this + 0x14) = 0;
    if (*(int *)(this + 4) == 0) {
      *(undefined4 **)(this + 4) = &DAT_00d71de8;
    }
  }
  return;
}

/* public: void __thiscall CClassicLog::CloseTempOutputFile(void) */

void __thiscall CClassicLog::CloseTempOutputFile(CClassicLog *this)

{
  int *piVar1;

  piVar1 = *(int **)(this + 0x28);
  if (piVar1 != (int *)0x0) {
    (***(code ***)(*(int *)(*piVar1 + 4) + (int)piVar1))(1);
    *(undefined4 *)(this + 0x28) = 0;
  }
  return;
}

/* public: static void __cdecl CClassicLog::ConsoleAddLogString(unsigned
   long,class CFastString const &) */

void __cdecl CClassicLog::ConsoleAddLogString(ulong param_1,
                                              CFastString *param_2)

{
  CFastString *pCVar1;
  HANDLE hConsoleOutput;
  void *lpBuffer;
  DWORD nNumberOfCharsToWrite;
  ulong *lpNumberOfCharsWritten;
  LPVOID lpReserved;
  SSystemTime aSStack_14[8];
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  pCVar1 = param_2;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a94d26;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((param_1 & DAT_00cdae84) != 0) {
    if ((CGbxApp::TheApp != (CGbxApp *)0x0) &&
        (*(int *)(CGbxApp::TheApp + 0xac) != 0)) {
      nNumberOfCharsToWrite = *(DWORD *)param_2;
      lpBuffer = *(void **)(param_2 + 4);
      lpReserved = (LPVOID)0x0;
      lpNumberOfCharsWritten = &param_1;
      param_1 = 0;
      hConsoleOutput = GetStdHandle(0xfffffff5);
      WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite,
                    lpNumberOfCharsWritten, lpReserved);
    }
    if (*(int *)(CGbxApp::TheApp + 0xec) != 0) {
      SSystemTime::SSystemTime(aSStack_14);
      SSystemTime::SetFromLocalTime(aSStack_14);
      if ((DAT_00d6701c & 1) == 0) {
        DAT_00d6701c = DAT_00d6701c | 1;
        uStack_4 = 0;
        CGameMasterServer::SLadderResult::SLadderResult(
            (SLadderResult *)&DAT_00d67014);
        _atexit((_func_4879 *)&LAB_00b1d490);
        uStack_4 = 0xffffffff;
      }
      SSystemTime::GetAsString_YMD_HMS(aSStack_14, (CFastString *)&DAT_00d67014,
                                       1);
      (**(code **)(**(int **)(CGbxApp::TheApp + 0xec) + 8))(DAT_00d67018,
                                                            DAT_00d67014);
      (**(code **)(**(int **)(CGbxApp::TheApp + 0xec) + 8))(
          *(undefined4 *)(pCVar1 + 4), *(undefined4 *)pCVar1);
      CSystemFile::Flush(*(CSystemFile **)(CGbxApp::TheApp + 0xec));
    }
    if (pCVar1 == &s_LogStringToAdd) {
      CFastString::CFastString((CFastString *)aSStack_14, &s_LogStringToAdd);
      uStack_4 = 0xffffffff;
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(
          (SHeaderCommunity *)aSStack_14);
    }
  }
  ExceptionList = local_c;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall CClassicLog::FlushWhenTimeOut(int) */

void __thiscall CClassicLog::FlushWhenTimeOut(CClassicLog *this, int param_1)

{
  int iVar1;

  if (*(int *)(this + 8) == 0) {
    if (param_1 == 0) {
      return;
    }
  } else {
    iVar1 = _DAT_00d71e7c;
    if ((param_1 == 0) && (iVar1 = (**(code **)(this + 0x10))(),
                           (uint)(iVar1 - _DAT_00d71e7c) < s_FlushTimeOut)) {
      return;
    }
    _DAT_00d71e7c = iVar1;
    (**(code **)(this + 0xc))(this);
  }
  if (*(basic_ostream<> **)(this + 0x14) != (basic_ostream<> *)0x0) {
    std::basic_ostream<>::flush(*(basic_ostream<> **)(this + 0x14));
  }
  if (*(basic_ostream<> **)(this + 0x28) != (basic_ostream<> *)0x0) {
    std::basic_ostream<>::flush(*(basic_ostream<> **)(this + 0x28));
  }
  return;
}

/* private: static void __cdecl CClassicLog::InternalAddLogString(int,int,int)
 */

void __cdecl CClassicLog::InternalAddLogString(int param_1, int param_2,
                                               int param_3)

{
  if (s_IsOutputDisable == 0) {
    if (((param_2 != 0) && (DAT_00d71e34 == (basic_ostream<> *)0x0)) ||
        (param_3 != 0)) {
      if (DAT_00d71e24 == (basic_ostream<> *)0x0) {
        param_2 = 1;
      } else {
        std::operator<< <>(DAT_00d71e24, DAT_00d71e58);
      }
    }
    if (((s_IsOutputToFileEnable != 0) || (param_2 != 0)) &&
        (DAT_00d71e34 != (basic_ostream<> *)0x0)) {
      std::operator<< <>(DAT_00d71e34, DAT_00d71e58);
    }
    if (((s_IsTempOutputToFileEnable != 0) || (param_2 != 0)) &&
        (DAT_00d71e48 != (basic_ostream<> *)0x0)) {
      std::operator<< <>(DAT_00d71e48, DAT_00d71e58);
    }
    if ((DAT_00d71e24 == (basic_ostream<> *)0x0) && (DAT_00d71de0 < 0x25a0)) {
      std::operator<< <>((basic_ostream<> *)&DAT_00d71de8, DAT_00d71e58);
    }
    FlushWhenTimeOut(&TheClassicLog, param_1);
  }
  return;
}

/* public: void __thiscall CClassicLog::SetOutputFile(class CFastStringInt const
   &,class CFastStringInt const &,int) */

void __thiscall CClassicLog::SetOutputFile(CClassicLog *this,
                                           CFastStringInt *param_1,
                                           CFastStringInt *param_2, int param_3)

{
  CFastStringInt *this_00;
  basic_ofstream<> *this_01;
  basic_ostream<> *this_02;
  int *piVar1;
  undefined4 local_20;
  char *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae1aeb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastStringBase<char>::PreAlloc((CFastStringBase<char> *)&s_LogStringToAdd,
                                  4000);
  CFastStringBase<char>::PreAlloc((CFastStringBase<char> *)&s_StatusString,
                                  0x100);
  local_14 = *(undefined4 *)param_1;
  local_18 = *(undefined4 *)(param_1 + 4);
  local_10 = 0;
  CFastStringInt::SetString((CFastStringInt *)(this + 0x20),
                            (SStringParamInt *)&local_18);
  if (*(int *)param_2 != 0) {
    local_14 = *(undefined4 *)param_1;
    local_18 = *(undefined4 *)(param_1 + 4);
    this_00 = (CFastStringInt *)(this + 0x18);
    local_10 = 0;
    CFastStringInt::SetString(this_00, (SStringParamInt *)&local_18);
    local_14 = *(undefined4 *)param_2;
    local_18 = *(undefined4 *)(param_2 + 4);
    local_10 = 0;
    CFastStringInt::Concat(this_00, (SStringParamInt *)&local_18);
    local_20 = 0;
    local_1c = "";
    local_4 = 1;
    CSystemFileName_ConvertToSystemName_AndCreate(this_00,
                                                  (CFastString *)&local_20);
    this_01 = (basic_ofstream<> *)operator_new(0x88);
    local_4._0_1_ = 2;
    if (this_01 == (basic_ofstream<> *)0x0) {
      this_02 = (basic_ostream<> *)0x0;
    } else {
      this_02 = (basic_ostream<> *)std::basic_ofstream<>::basic_ofstream<>(
          this_01, local_1c, 0x32, 0x40);
    }
    local_4 = CONCAT31(local_4._1_3_, 1);
    piVar1 = *(int **)(this + 0x14);
    if ((piVar1 != (int *)0x0) ||
        (piVar1 = *(int **)(this + 4), piVar1 != (int *)0x0)) {
      std::basic_ostream<>::operator<<(
          this_02,
          *(basic_streambuf<> **)(*(int *)(*piVar1 + 4) + 0x28 + (int)piVar1));
    }
    piVar1 = *(int **)(this + 0x14);
    if ((piVar1 != (int *)0x0) && (piVar1 != &DAT_00d71de8)) {
      (***(code ***)(*(int *)(*piVar1 + 4) + (int)piVar1))(1);
    }
    *(basic_ostream<> **)(this + 0x14) = this_02;
    if (param_3 != 0) {
      *(undefined4 *)(this + 4) = 0;
    }
    local_4 = 0xffffffff;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(
        (SHeaderCommunity *)&local_20);
  }
  ExceptionList = local_c;
  return;
}

/* public: static void __cdecl CClassicLog::StatusStringFlush(void) */

void __cdecl CClassicLog::StatusStringFlush(void)

{
  if (s_CallbackFlushStatusString != (CFastCallback *)0x0) {
    /* WARNING: Could not recover jumptable at 0x009047ce. Too many branches */
    /* WARNING: Treating indirect jump as call */
    (***(code ***)s_CallbackFlushStatusString)();
    return;
  }
  return;
}

/* public: virtual __thiscall CClassicLog::~CClassicLog(void) */

void __thiscall CClassicLog::~CClassicLog(CClassicLog *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00ae13a1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 2;
  CloseTempOutputFile(this);
  Close(this);
  local_4._0_1_ = 1;
  CGameCtnApp::SNationConfig::~SNationConfig((SNationConfig *)(this + 0x2c));
  local_4 = (uint)local_4._1_3_ << 8;
  CGameCtnApp::SNationConfig::~SNationConfig((SNationConfig *)(this + 0x20));
  local_4 = 0xffffffff;
  CGameCtnApp::SNationConfig::~SNationConfig((SNationConfig *)(this + 0x18));
  ExceptionList = local_c;
  return;
}
