// Class implementation: CMwProfiler

// =================================================
// Function: CMwProfiler::CMwProfiler
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CMwProfiler::CMwProfiler(CMwProfiler *this,CMwProfiler *param_1)
{
{
  CMwNod *unaff_ESI;
  int64 iVar1;
  CMwNod *in_stack_fffffff8;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,in_stack_fffffff8);
  *(undefined ***)this = vftable;
  if (_DAT_00d73308 == 0.0) {
    iVar1 = GetCPUFrequency();
    _DAT_00d73308 = _DAT_00c418d8 / (double)iVar1;
  }
  return;
}
}

// =================================================
// Function: CMwProfiler::GetCPUFrequency
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int64 __cdecl CMwProfiler::GetCPUFrequency(void)
{
{
  BOOL BVar1;
  LARGE_INTEGER local_10;
  LARGE_INTEGER local_8;
  
  if (DAT_00d73320 == 0 && DAT_00d73324 == 0) {
    BVar1 = QueryPerformanceFrequency(&local_10);
    if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      _exit(-1);
    }
    DAT_00d73320 = local_10.s.LowPart;
    DAT_00d73324 = local_10.s.HighPart;
    BVar1 = QueryPerformanceCounter(&local_8);
    if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      _exit(-1);
    }
    _DAT_00d73310 = local_8.s.LowPart;
    _DAT_00d73314 = local_8.s.HighPart;
  }
  return CONCAT44(DAT_00d73324,DAT_00d73320);
}
}

// =================================================
// Function: CMwProfiler::GetDurationFromDeltaTimeStamp
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __cdecl CMwProfiler::GetDurationFromDeltaTimeStamp(int64 param_1)
{
{
  return (float)((float10)param_1 * (float10)_DAT_00d73308 * (float10)_DAT_00bc6138);
}
}

// =================================================
// Function: CMwProfiler::GetTimeFromDeltaTimeStamp
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __cdecl CMwProfiler::GetTimeFromDeltaTimeStamp(int64 param_1)
{
{
  undefined4 local_8;
  
  local_8 = (ulong)(longlong)ROUND((double)param_1 * _DAT_00d73308);
  return local_8;
}
}

// =================================================
// Function: CMwProfiler::GetTimeStamp
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CMwProfiler::GetTimeStamp(int64 *param_1)
{
{
  BOOL BVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  LARGE_INTEGER local_8;
  
  BVar1 = QueryPerformanceCounter(&local_8);
  if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  uVar3 = local_8.s.LowPart - _DAT_00d73310;
  iVar2 = (local_8.s.HighPart - _DAT_00d73314) - (uint)(local_8.s.LowPart < _DAT_00d73310);
  if ((iVar2 < 1) && (iVar2 < 0)) {
    uVar3 = 0;
    iVar2 = 0;
  }
  bVar4 = CARRY4(DAT_00d73318,uVar3);
  DAT_00d73318 = DAT_00d73318 + uVar3;
  iVar2 = DAT_00d7331c + iVar2 + (uint)bVar4;
  _DAT_00d73314 = local_8.s.HighPart;
  _DAT_00d73310 = local_8.s.LowPart;
  DAT_00d7331c = iVar2;
  *(uint *)param_1 = DAT_00d73318;
  *(int *)((int)param_1 + 4) = iVar2;
  return;
}
}

