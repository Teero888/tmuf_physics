
/* public: unsigned long __thiscall CMwTimer::GetElapsedTimeSinceInit(void)const
 */

ulong __thiscall CMwTimer::GetElapsedTimeSinceInit(CMwTimer *this)

{
  DWORD DVar1;
  ulong uVar2;
  __int64 _Var3;

  if (*(int *)(this + 0x24) != 0) {
    DVar1 = timeGetTime();
    return DVar1 - *(int *)(this + 0x20);
  }
  _Var3 = FUN_00939dd0();
  uVar2 = CMwProfiler::GetTimeFromDeltaTimeStamp(
      CONCAT44(((int)((ulonglong)_Var3 >> 0x20) - *(int *)(this + 0x1c)) -
                   (uint)((uint)_Var3 < *(uint *)(this + 0x18)),
               (uint)_Var3 - *(uint *)(this + 0x18)));
  return uVar2;
}
