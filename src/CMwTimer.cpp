// Class implementation: CMwTimer

// =================================================
// Function: CMwTimer::ChopTime
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CMwTimer::ChopTime(void *this,CMwTimer *param_1)
{
{
  uint uVar1;
  float fVar2;
  
  uVar1 = *(uint *)((int)this + 4);
  fVar2 = (float)_DAT_00b30a18;
  if (uVar1 < *(uint *)((int)this + 0xc)) {
    *(uint *)((int)this + 0xc) = uVar1;
    *(float *)((int)this + 0x10) = (float)(int)uVar1 * fVar2;
  }
  uVar1 = *(uint *)this;
  if (*(uint *)((int)this + 0xc) < uVar1) {
    *(uint *)((int)this + 0xc) = uVar1;
    *(float *)((int)this + 0x10) = fVar2 * (float)(int)uVar1;
    return;
  }
  return;
}
}

// =================================================
// Function: CMwTimer::GetElapsedTimeSinceInit
// =================================================
ulong __thiscall CMwTimer::GetElapsedTimeSinceInit(void *this,CMwTimer *param_1)
{
{
  DWORD DVar1;
  ulong uVar2;
  int64 iVar3;
  
  if (*(int *)((int)this + 0x24) != 0) {
    DVar1 = GetCurrentCounter1();
    return DVar1 - *(int *)((int)this + 0x20);
  }
  iVar3 = GetCurrentCounter0();
  uVar2 = CMwProfiler::GetTimeFromDeltaTimeStamp
                    (CONCAT44(((int)((ulonglong)iVar3 >> 0x20) - *(int *)((int)this + 0x1c)) -
                              (uint)((uint)iVar3 < *(uint *)((int)this + 0x18)),
                              (uint)iVar3 - *(uint *)((int)this + 0x18)));
  return uVar2;
}
}

// =================================================
// Function: CMwTimer::GetHhMmSsTime24StringFromMwTime
// =================================================
void __cdecl CMwTimer::GetHhMmSsTime24StringFromMwTime(ulong param_1,CFastString *param_2)
{
{
  ulong *unaff_ESI;
  SStringParam *in_stack_ffffffec;
  CFastString *in_stack_fffffff0;
  ulong *in_stack_fffffff4;
  undefined *local_8;
  undefined4 local_4;
  
  if (param_1 != 0xffffffff) {
    DecomposeMwTime_24h(param_1,(int *)&stack0xfffffff4,unaff_ESI,(ulong *)in_stack_ffffffec,
                        (ulong *)in_stack_fffffff0,in_stack_fffffff4);
    CFastString::Format(in_stack_fffffff0,param_2,"%.2d:%.2d:%.2d");
    return;
  }
  local_8 = &DAT_00b35358;
  local_4 = 3;
  CFastString::SetString(param_2,(CFastStringInt *)&local_8,in_stack_ffffffec);
  return;
}
}

// =================================================
// Function: CMwTimer::GetHhMmSsTimeStringFromMwTime
// =================================================
void __cdecl CMwTimer::GetHhMmSsTimeStringFromMwTime(ulong param_1,CFastString *param_2)
{
{
  CFastString *in_stack_ffffffec;
  ulong *in_stack_fffffff0;
  ulong local_c;
  undefined *local_8;
  undefined4 local_4;
  
  if (param_1 != 0xffffffff) {
    DecomposeMwTime((ulong)&stack0xfffffff0,(int *)&stack0xffffffec,&param_1,&local_c,
                    (ulong *)in_stack_ffffffec,in_stack_fffffff0);
    CFastString::Format(in_stack_ffffffec,param_2,"%.2d:%.2d:%.2d");
    return;
  }
  local_8 = &DAT_00b35358;
  local_4 = 3;
  CFastString::SetString(param_2,(CFastStringInt *)&local_8,(SStringParam *)in_stack_ffffffec);
  return;
}
}

// =================================================
// Function: CMwTimer::GetHhMmTimeStringFromMwTime
// =================================================
void __cdecl CMwTimer::GetHhMmTimeStringFromMwTime(ulong param_1,CFastString *param_2)
{
{
  ulong *unaff_ESI;
  SStringParam *in_stack_ffffffec;
  ulong *in_stack_fffffff0;
  ulong *in_stack_fffffff4;
  undefined *local_8;
  undefined4 local_4;
  
  if (param_1 != 0xffffffff) {
    DecomposeMwTime_24h(param_1,(int *)&stack0xfffffff0,unaff_ESI,(ulong *)in_stack_ffffffec,
                        in_stack_fffffff0,in_stack_fffffff4);
    CFastString::Format(param_2,param_2,"%.2d:%.2d");
    return;
  }
  local_8 = &DAT_00b35358;
  local_4 = 3;
  CFastString::SetString(param_2,(CFastStringInt *)&local_8,in_stack_ffffffec);
  return;
}
}

// =================================================
// Function: CMwTimer::GetMmSsCcTimeStringFromMwTime
// =================================================
void __cdecl CMwTimer::GetMmSsCcTimeStringFromMwTime(ulong param_1,CFastString *param_2)
{
{
  SStringParam *in_stack_ffffffec;
  ulong *in_stack_fffffff0;
  CFastString *local_c;
  CFastString *local_8;
  undefined4 local_4;
  
  if (param_1 == 0xffffffff) {
    local_8 = (CFastString *)&DAT_00b35358;
    local_4 = 3;
    CFastString::SetString(param_2,(CFastStringInt *)&local_8,in_stack_ffffffec);
    return;
  }
  DecomposeMwTime((ulong)&local_8,(int *)&local_c,(ulong *)&stack0xfffffff0,
                  (ulong *)&stack0xffffffec,(ulong *)in_stack_ffffffec,in_stack_fffffff0);
  if (local_8 == (CFastString *)0x0) {
    CFastString::Format(local_c,param_2,"%s%d:%.2d.%.2d");
    return;
  }
  CFastString::Format(local_8,param_2,"%s%d:%.2d:%.2d.%.2d");
  return;
}
}

// =================================================
// Function: CMwTimer::GetMmSsTimeStringFromMwTime
// =================================================
void __cdecl CMwTimer::GetMmSsTimeStringFromMwTime(ulong param_1,CFastString *param_2)
{
{
  CFastString *in_stack_ffffffec;
  ulong *in_stack_fffffff0;
  undefined1 local_c [4];
  undefined *local_8;
  undefined4 local_4;
  
  if (param_1 != 0xffffffff) {
    DecomposeMwTime((ulong)local_c,(int *)&stack0xffffffec,&param_1,(ulong *)&stack0xfffffff0,
                    (ulong *)in_stack_ffffffec,in_stack_fffffff0);
    CFastString::Format(in_stack_ffffffec,param_2,"%d:%.2d");
    return;
  }
  local_8 = &DAT_00b35358;
  local_4 = 3;
  CFastString::SetString(param_2,(CFastStringInt *)&local_8,(SStringParam *)in_stack_ffffffec);
  return;
}
}

// =================================================
// Function: CMwTimer::GetMwTimeFromHhMmSsTimeString
// =================================================
int __cdecl CMwTimer::GetMwTimeFromHhMmSsTimeString(char *param_1,ulong *param_2)
{
{
  uint uVar1;
  int local_c;
  int local_8;
  int local_4;
  
  uVar1 = _sscanf_s(param_1,"%d:%d:%d");
  if (uVar1 < 3) {
    local_c = 0;
  }
  if (uVar1 < 2) {
    local_8 = 0;
  }
  if (uVar1 == 0) {
    return 0;
  }
  *param_2 = (local_c + (local_8 + local_4 * 0x3c) * 0x3c) * 1000;
  return 1;
}
}

// =================================================
// Function: CMwTimer::GetMwTimeFromHhMmTimeString
// =================================================
int __cdecl CMwTimer::GetMwTimeFromHhMmTimeString(char *param_1,ulong *param_2)
{
{
  uint uVar1;
  int local_8;
  int local_4;
  
  uVar1 = _sscanf_s(param_1,"%d:%d");
  if (uVar1 < 2) {
    local_8 = 0;
  }
  if (uVar1 == 0) {
    return 0;
  }
  *param_2 = (local_8 + local_4 * 0x3c) * 60000;
  return 1;
}
}

// =================================================
// Function: CMwTimer::GetMwTimeFromMmSsCcTimeString
// =================================================
int __cdecl CMwTimer::GetMwTimeFromMmSsCcTimeString(char *param_1,ulong *param_2)
{
{
  uint uVar1;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  uVar1 = _sscanf_s(param_1,"%d:%d:%d.%d");
  if (uVar1 < 4) {
    local_8 = 0;
    uVar1 = _sscanf_s(param_1,"%d:%d.%d");
  }
  if (uVar1 < 3) {
    local_10 = 0;
  }
  if (uVar1 < 2) {
    local_c = 0;
  }
  if (uVar1 == 0) {
    return 0;
  }
  *param_2 = ((local_c + (local_4 + local_8 * 0x3c) * 0x3c) * 100 + local_10) * 10;
  return 1;
}
}

// =================================================
// Function: CMwTimer::GetMwTimeFromMmSsTimeString
// =================================================
int __cdecl CMwTimer::GetMwTimeFromMmSsTimeString(char *param_1,ulong *param_2)
{
{
  uint uVar1;
  int local_8;
  int local_4;
  
  uVar1 = _sscanf_s(param_1,"%d:%d");
  if (uVar1 < 2) {
    local_8 = 0;
  }
  if (uVar1 == 0) {
    return 0;
  }
  *param_2 = (local_8 + local_4 * 0x3c) * 1000;
  return 1;
}
}

// =================================================
// Function: CMwTimer::GetTickTime
// =================================================
ulong * __thiscall CMwTimer::GetTickTime(void *this,CMwTimerAdapter *param_1)
{
{
  return (ulong *)((int)this + 8);
}
}

// =================================================
// Function: CMwTimer::InitTimer
// =================================================
void __thiscall
CMwTimer::InitTimer(void *this,CMwTimerAdapter *param_1,CMwTimer *param_2,float param_3)
{
{
  DWORD DVar1;
  int64 iVar2;
  
  iVar2 = GetCurrentCounter0();
  *(int64 *)((int)this + 0x18) = iVar2;
  DVar1 = GetCurrentCounter1();
  *(DWORD *)((int)this + 0x20) = DVar1;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)this = 1;
  *(undefined4 *)((int)this + 4) = 100;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  CMwTimer_CalibrateStart();
  return;
}
}

// =================================================
// Function: CMwTimer::SecondsToMwTime
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __cdecl CMwTimer::SecondsToMwTime(float param_1)
{
{
  undefined4 local_8;
  
  local_8 = (ulong)(longlong)ROUND(param_1 * (float)_DAT_00c418d8);
  return local_8;
}
}

// =================================================
// Function: CMwTimer::SimulateDeltaTime
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CMwTimer::SimulateDeltaTime(void *this,CMwTimer *param_1,ulong param_2)
{
{
  uint *puVar1;
  uint uVar2;
  ulong uVar3;
  float10 fVar4;
  ulong *puVar5;
  uint extraout_EAX;
  ulong uVar6;
  void *this_00;
  int extraout_EDX;
  CMwTimer *unaff_ESI;
  CMwTimerAdapter *unaff_EDI;
  float10 extraout_ST0;
  float10 fVar7;
  int in_stack_0000000c;
  
  puVar5 = GetTickTime(this,unaff_EDI);
  uVar3 = *puVar5;
  GetElapsedTimeSinceInit(this_00,unaff_ESI);
  GetCurrentCounter0Frequency();
  __ftol2();
  puVar1 = (uint *)((int)this + 0x18);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + extraout_EAX;
  *(int *)((int)this + 0x1c) =
       *(int *)((int)this + 0x1c) + extraout_EDX + (uint)CARRY4(uVar2,extraout_EAX);
  uVar6 = GetCurrentCounter1Frequency();
  fVar7 = (float10)(int)uVar6;
  if ((int)uVar6 < 0) {
    fVar7 = fVar7 + (float10)_DAT_00b3dca0;
  }
  *(ulong *)((int)this + 8) = uVar3 + param_2;
  fVar4 = (float10)_DAT_00b57078;
  *(ulong *)((int)this + 0xc) = param_2;
  *(int *)((int)this + 0x20) =
       *(int *)((int)this + 0x20) + (int)(longlong)ROUND(extraout_ST0 * fVar4 * fVar7);
  *(float *)((int)this + 0x10) = (float)in_stack_0000000c * (float)_DAT_00b30a18;
  return;
}
}

// =================================================
// Function: CMwTimer::Tick
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CMwTimer::Tick(void *this,CNetIPC *param_1)
{
{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  ulong *puVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  uint extraout_EAX;
  CPlugFileGpuBuilder *this_00;
  int extraout_ECX;
  int extraout_EDX;
  undefined4 unaff_EBX;
  CMwTimer *unaff_EBP;
  CMwTimer *unaff_ESI;
  CMwTimerAdapter *unaff_EDI;
  uint64 uVar9;
  undefined8 uVar10;
  CPlugFileGpuBuilder *in_stack_00000008;
  char *in_stack_0000000c;
  float fStack00000014;
  void *pvVar11;
  CMwTimer *pCVar12;
  
  pvVar11 = this;
  puVar5 = GetTickTime(this,unaff_EDI);
  uVar3 = *puVar5;
  if ((DAT_00d73ab8 == 0) && (DAT_00d3590c < uVar3)) {
    iVar6 = CMwTimer_CalibrateEnd_ShouldSwitchOff();
    uVar7 = GetElapsedTimeSinceInit(this,unaff_EBP);
    uVar10 = CONCAT44(pvVar11,unaff_EBX);
    if (iVar6 == 0) {
      if (*(int *)((int)this + 0x24) != 0) {
        *(undefined4 *)((int)this + 0x24) = 0;
        GetElapsedTimeSinceInit(this,unaff_ESI);
        uVar9 = GetCurrentCounter0Frequency();
        uVar10 = func_0x009c1810(uVar9,1000,0);
        param_1 = (CNetIPC *)0x0;
        __allmul();
        puVar1 = (uint *)((int)this + 0x18);
        uVar2 = *puVar1;
        *puVar1 = *puVar1 + extraout_EAX;
        *(int *)((int)this + 0x1c) =
             *(int *)((int)this + 0x1c) + extraout_EDX + (uint)CARRY4(uVar2,extraout_EAX);
        DAT_00d73ab4 = DAT_00d73ab4 + 1;
      }
    }
    else {
      uVar10 = CONCAT44(pvVar11,unaff_EBX);
      if (*(int *)((int)this + 0x24) == 0) {
        *(undefined4 *)((int)this + 0x24) = 1;
        GetElapsedTimeSinceInit(this,unaff_ESI);
        uVar8 = GetCurrentCounter1Frequency();
        uVar10 = CONCAT44(pvVar11,unaff_EBX);
        *(int *)((int)this + 0x20) =
             *(int *)((int)this + 0x20) + (uVar8 / 1000) * (extraout_ECX - uVar7);
        DAT_00d73ab4 = DAT_00d73ab4 + 1;
      }
    }
    pCVar12 = (CMwTimer *)((ulonglong)uVar10 >> 0x20);
    GetElapsedTimeSinceInit(this,(CMwTimer *)uVar10);
    uVar7 = GetElapsedTimeSinceInit(this,pCVar12);
    DAT_00d3590c = uVar7 + 90000;
    CMwTimer_CalibrateStart();
  }
  uVar7 = GetElapsedTimeSinceInit(this,(CMwTimer *)param_1);
  *(int *)((int)this + 0x2c) = *(int *)((int)this + 0x2c) + 1;
  iVar6 = uVar7 - uVar3;
  *(int *)((int)this + 0x28) = *(int *)((int)this + 0x28) + iVar6;
  *(int *)((int)this + 0xc) = iVar6;
  fVar4 = (float)_DAT_00b30a18;
  fStack00000014 = *(float *)((int)this + 0x28);
  *(ulong *)((int)this + 8) = uVar7;
  *(float *)((int)this + 0x10) = (float)iVar6 * fVar4;
  if (*(int *)((int)this + 0x2c) == 0x14) {
    fStack00000014 = fVar4 * (float)(int)fStack00000014;
    *(undefined4 *)((int)this + 0x2c) = 0;
    *(undefined4 *)((int)this + 0x28) = 0;
    *(float *)((int)this + 0x14) = (float)_DAT_00b48cb8 / fStack00000014;
  }
  if (0xffff159f < uVar7) {
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    this_00 = CFastString::operator<<
                        ((CFastString *)&DAT_00d71e54,
                         (CPlugFileGpuBuilder *)"[MwTimer] MwTime limit reached.",
                         (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)this_00,in_stack_00000008,in_stack_0000000c);
    CClassicLog::AddLogStringInFile();
    _DAT_00000000 = 0;
  }
  return;
}
}

