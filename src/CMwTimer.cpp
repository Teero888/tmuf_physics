
/* private: void __thiscall CMwTimer::ChopTime(void) */

void __thiscall CMwTimer::ChopTime(CMwTimer *this)

{
  uint uVar1;

  uVar1 = *(uint *)(this + 4);
  if (uVar1 < *(uint *)(this + 0xc)) {
    *(uint *)(this + 0xc) = uVar1;
    *(float *)(this + 0x10) = (float)uVar1 * 0.001;
  }
  uVar1 = *(uint *)this;
  if (*(uint *)(this + 0xc) < uVar1) {
    *(uint *)(this + 0xc) = uVar1;
    *(float *)(this + 0x10) = (float)uVar1 * 0.001;
    return;
  }
  return;
}
/* public: unsigned long __thiscall CMwTimer::GetElapsedTimeSinceInit(void)const
 */

// TODO: CHECK IF THIS FUNCTIONS WASNT GETTING SOMETHING IMRPORTANT FROM THE
// PROFILER
ulong __thiscall CMwTimer::GetElapsedTimeSinceInit(CMwTimer *this)

{
  DWORD DVar1;
  // ulong uVar2;
  // __int64 _Var3;

  // if (*(int *)(this + 0x24) != 0) {
  DVar1 = timeGetTime();
  return DVar1 - *(int *)(this + 0x20);
  // }
  // _Var3 = FUN_00939dd0();
  // uVar2 = CMwProfiler::GetTimeFromDeltaTimeStamp(
  //     CONCAT44(((int)((ulonglong)_Var3 >> 0x20) - *(int *)(this + 0x1c)) -
  //                  (uint)((uint)_Var3 < *(uint *)(this + 0x18)),
  //              (uint)_Var3 - *(uint *)(this + 0x18)));
  // return uVar2;
}

/* public: unsigned long const & __thiscall CMwTimer::GetTickTime(void)const  */

ulong *__thiscall CMwTimer::GetTickTime(CMwTimer *this)

{
  return (ulong *)(this + 8);
}

/* public: void __thiscall CMwTimer::InitTimer(void) */

void __thiscall CMwTimer::InitTimer(CMwTimer *this)

{
  DWORD DVar1;
  __int64 _Var2;

  _Var2 = 0; // FUN_00939dd0(); TODO: USING 0 HERE MIGHT CHANGE STUFF
  *(__int64 *)(this + 0x18) = _Var2;
  DVar1 = timeGetTime();
  *(DWORD *)(this + 0x20) = DVar1;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)this = 1;
  *(undefined4 *)(this + 4) = 100;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  CMwTimer_CalibrateStart();
  return;
}

/* public: static unsigned long __cdecl CMwTimer::SecondsToMwTime(float) */

ulong __cdecl CMwTimer::SecondsToMwTime(float param_1)

{
  ulong local_8;

  local_8 = (ulong)(longlong)ROUND(param_1 * 1000.0);
  return local_8;
}
/* public: void __thiscall CMwTimer::SimulateDeltaTime(unsigned long) */

void __thiscall CMwTimer::SimulateDeltaTime(CMwTimer *this, ulong param_1)

{
  uint *puVar1;
  uint uVar2;
  ulong uVar3;
  ulong *puVar4;
  int iVar5;
  CMwTimer *this_00;
  float10 extraout_ST0;
  float10 fVar6;
  ulonglong uVar7;
  int local_8;

  puVar4 = GetTickTime(this);
  uVar3 = *puVar4;
  GetElapsedTimeSinceInit(this_00);
  CMwProfiler::GetCPUFrequency();
  uVar7 = __ftol2();
  puVar1 = (uint *)(this + 0x18);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + (uint)uVar7;
  *(uint *)(this + 0x1c) = *(int *)(this + 0x1c) + (int)(uVar7 >> 0x20) +
                           (uint)CARRY4(uVar2, (uint)uVar7);
  iVar5 = FUN_00939e10();
  fVar6 = (float10)iVar5;
  if (iVar5 < 0) {
    fVar6 = fVar6 + (float10)4294967296.0;
  }
  *(ulong *)(this + 8) = uVar3 + param_1;
  *(ulong *)(this + 0xc) = param_1;
  local_8 = (int)(longlong)ROUND(extraout_ST0 * (float10)-0.001000000047497451 *
                                 fVar6);
  *(int *)(this + 0x20) = *(int *)(this + 0x20) + local_8;
  *(float *)(this + 0x10) = (float)param_1 * 0.001;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall CMwTimer::Tick(void) */

void __thiscall CMwTimer::Tick(CMwTimer *this)

{
  uint *puVar1;
  uint uVar2;
  ulong *puVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  ulong uVar7;
  CFastString *this_00;
  int extraout_ECX;
  int iVar8;
  __int64 _Var9;
  undefined8 uVar10;
  longlong lVar11;
  char *pcVar12;

  puVar3 = GetTickTime(this);
  uVar2 = *puVar3;
  if ((DAT_00d73ab8 == 0) && (DAT_00d3590c < uVar2)) {
    iVar4 = CMwTimer_CalibrateEnd_ShouldSwitchOff();
    uVar5 = GetElapsedTimeSinceInit(this);
    if (iVar4 == 0) {
      if (*(int *)(this + 0x24) != 0) {
        *(undefined4 *)(this + 0x24) = 0;
        uVar7 = GetElapsedTimeSinceInit(this);
        _Var9 = CMwProfiler::GetCPUFrequency();
        uVar10 =
            __aulldiv((uint)_Var9, (uint)((ulonglong)_Var9 >> 0x20), 1000, 0);
        lVar11 = __allmul((uint)uVar10, (uint)((ulonglong)uVar10 >> 0x20),
                          uVar7 - uVar5, 0);
        puVar1 = (uint *)(this + 0x18);
        uVar6 = *puVar1;
        *puVar1 = *puVar1 + (uint)lVar11;
        *(uint *)(this + 0x1c) = *(int *)(this + 0x1c) +
                                 (int)((ulonglong)lVar11 >> 0x20) +
                                 (uint)CARRY4(uVar6, (uint)lVar11);
        s_CounterSwitchCount = s_CounterSwitchCount + 1;
      }
    } else if (*(int *)(this + 0x24) == 0) {
      *(undefined4 *)(this + 0x24) = 1;
      GetElapsedTimeSinceInit(this);
      uVar6 = FUN_00939e10();
      *(uint *)(this + 0x20) =
          *(int *)(this + 0x20) + (uVar6 / 1000) * (extraout_ECX - uVar5);
      s_CounterSwitchCount = s_CounterSwitchCount + 1;
    }
    GetElapsedTimeSinceInit(this);
    uVar5 = GetElapsedTimeSinceInit(this);
    DAT_00d3590c = uVar5 + 90000;
    CMwTimer_CalibrateStart();
  }
  uVar5 = GetElapsedTimeSinceInit(this);
  *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + 1;
  iVar8 = uVar5 - uVar2;
  *(int *)(this + 0x28) = *(int *)(this + 0x28) + iVar8;
  *(int *)(this + 0xc) = iVar8;
  iVar4 = *(int *)(this + 0x28);
  *(ulong *)(this + 8) = uVar5;
  *(float *)(this + 0x10) = (float)iVar8 * 0.001;
  if (*(int *)(this + 0x2c) == 0x14) {
    *(undefined4 *)(this + 0x2c) = 0;
    *(undefined4 *)(this + 0x28) = 0;
    *(float *)(this + 0x14) = 20.0 / ((float)iVar4 * 0.001);
  }
  if (0xffff159f < uVar5) {
    if (_s_LogStringToAdd != 0) {
      _s_LogStringToAdd = 0;
      *DAT_00d71e58 = 0;
    }
    pcVar12 = "\r\n";
    this_00 = CFastString::operator<<(&CClassicLog::s_LogStringToAdd,
                                      "[MwTimer] MwTime limit reached.");
    CFastString::operator<<(this_00, pcVar12);
    CClassicLog::AddLogStringInFile();
    ___except_list = 0;
  }
  return;
}
