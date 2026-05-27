// Class implementation: CMwCmdBufferCore

// =================================================
// Function: CMwCmdBufferCore::AddNotifySetTime
// =================================================
CMwCmdFastCall * __thiscall
CMwCmdBufferCore::AddNotifySetTime
          (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,CMwNod *param_2,
          _func___cdecl_void *param_3)
{
{
  CMwCmdBuffer *pCVar1;
  CMwCmdBufferCore *this_00;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCVar3;
  GmQuat *pGVar4;
  int iVar5;
  CMwCmdFastCall *extraout_EAX_00;
  uchar **unaff_EBX;
  ulong unaff_EBP;
  _func___cdecl_void *unaff_ESI;
  CMwCmdFastCall *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCVar7;
  CMwNod *in_stack_00000010;
  void *local_c;
  CMwCmdFastCall *pCStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  pCStack_8 = (CMwCmdFastCall *)&LAB_00ae2e86;
  local_c = ExceptionList;
  pCVar1 = (CMwCmdBuffer *)(DAT_00cca150 ^ (uint)&stack0xffffffe0);
  ExceptionList = &local_c;
  pCVar7 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0;
  this_00 = this;
  if (*(int *)(this + 0x100) == 0) {
    this_00 = operator_new(0x48);
    local_4 = (void *)0x0;
    if (this_00 == (CMwCmdBufferCore *)0x0) {
      uVar2 = 0;
    }
    else {
      CMwCmdBuffer::CMwCmdBuffer((CMwCmdBuffer *)this_00,pCVar1);
      uVar2 = extraout_EAX;
    }
    *(undefined4 *)(this + 0x100) = uVar2;
  }
  pCVar3 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     ((void *)(*(int *)(this + 0x100) + 0x2c),unaff_EDI);
  if (pCVar3 != (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0) {
    do {
      pGVar4 = CFastBufferCat<int,struct_SFastCat>::GetElemInAll
                         ((void *)(*(int *)(this + 0x100) + 0x20),pCVar7,(ulong)unaff_ESI);
      pCVar6 = *(CMwCmdFastCall **)pGVar4;
      if (pCVar6 != (CMwCmdFastCall *)0x0) {
        unaff_ESI = (_func___cdecl_void *)0x1012000;
        iVar5 = (**(code **)(*(int *)pCVar6 + 0x10))();
        if ((((iVar5 != 0) && (*(_func___cdecl_void **)(pCVar6 + 0x20) == param_3)) &&
            (*(CMwNod **)(pCVar6 + 0x1c) == in_stack_00000010)) && (((byte)pCVar6[0x18] & 2) == 0))
        {
          ExceptionList = local_4;
          return pCVar6;
        }
      }
      pCVar7 = pCVar7 + 1;
    } while (pCVar7 < pCVar3);
  }
  pCStack_8 = operator_new(0x24);
  if (pCStack_8 == (CMwCmdFastCall *)0x0) {
    pCVar6 = (CMwCmdFastCall *)0x0;
  }
  else {
    CMwCmdFastCall::CMwCmdFastCall
              (pCStack_8,(CMwCmdFastCall *)param_3,in_stack_00000010,unaff_ESI,unaff_EBP);
    pCVar6 = extraout_EAX_00;
  }
  CInputEventsStore::Lock
            (pCVar6,*(CDx9DynamicVB **)(this + 0x100),(ulong)unaff_ESI,unaff_EBP,unaff_EBX,
             (ulong *)this_00);
  (**(code **)(*(int *)pCVar6 + 0x7c))();
  ExceptionList = local_4;
  return pCVar6;
}
}

// =================================================
// Function: CMwCmdBufferCore::CMwCmdBufferCore
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CMwCmdBufferCore::CMwCmdBufferCore(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1)
{
{
  CFastArray<class_CManoeuvre*> *unaff_EBX;
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  CMwNod *unaff_EDI;
  SMwSchemeTimedProperties *unaff_retaddr;
  undefined1 uStack0000000c;
  void *in_stack_00000018;
  CMwCmdBufferCore *pCVar1;
  CMwTimer *pCVar2;
  undefined1 *puVar3;
  float fVar4;
  
  fVar4 = -NAN;
  puVar3 = &LAB_00ae2d6e;
  pCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe4),unaff_EDI);
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x1c,unaff_ESI);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x24,unaff_EBX);
  uStack0000000c = 2;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  MwSystemTimerInit();
  *(undefined4 *)(this + 0x44) = _DAT_00b36160;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x74) = 100;
  *(undefined4 *)(this + 0x48) = _DAT_00b36138;
  *(undefined4 *)(this + 0x50) = DAT_00b3d2a0;
  CMwTimer::InitTimer((CMwTimerAdapter *)(this + 0x70),(CMwTimerAdapter *)pCVar1,pCVar2,
                      (float)puVar3);
  CMwTimerAdapter::InitTimer
            (this + 0xa0,(CMwTimerAdapter *)(this + 0x70),(CMwTimer *)0x3f800000,fVar4);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0xc4) = 0;
  *(undefined4 *)(this + 0xc0) = 1;
  *(undefined4 *)(this + 0x100) = 0;
  SetSchemePatternsProperties(this,(CMwCmdBufferCore *)0x0,unaff_retaddr);
  ExceptionList = in_stack_00000018;
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::CreateCoreCmdBuffer
// =================================================
void __cdecl CMwCmdBufferCore::CreateCoreCmdBuffer(void)
{
{
  CMwCmdBufferCore *pCVar1;
  undefined4 extraout_EAX;
  CMwCmdBufferCore *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ae2ddb;
  local_c = ExceptionList;
  pCVar1 = (CMwCmdBufferCore *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x108);
  local_4 = 0;
  if (local_10 != (CMwCmdBufferCore *)0x0) {
    CMwCmdBufferCore(local_10,pCVar1);
    DAT_00d731e0 = extraout_EAX;
    ExceptionList = local_8;
    return;
  }
  DAT_00d731e0 = 0;
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::DestroyCoreCmdBuffer
// =================================================
void __cdecl CMwCmdBufferCore::DestroyCoreCmdBuffer(void)
{
{
  if (DAT_00d731e0 != (int *)0x0) {
    (**(code **)(*DAT_00d731e0 + 4))(1);
  }
  DAT_00d731e0 = (int *)0x0;
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::Disable
// =================================================
void __thiscall CMwCmdBufferCore::Disable(CMwCmdBufferCore *this,CCrystalLink *param_1)
{
{
  if (*(int *)(this + 0x30) != 0) {
    *(undefined4 *)(this + 0x30) = 0;
    HighFrequencyLeaveSafeSection(this,(CMwCmdBufferCore *)param_1);
    return;
  }
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::Enable
// =================================================
void __thiscall CMwCmdBufferCore::Enable(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1)
{
{
  ulong unaff_retaddr;
  
  if (*(int *)(this + 0x30) == 0) {
    *(undefined4 *)(this + 0x30) = 1;
    HighFrequencyEnterSafeSection(this,(CMwCmdBufferCore *)0x1,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::EnableFixedTickFrequency
// =================================================
void __thiscall
CMwCmdBufferCore::EnableFixedTickFrequency
          (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,int param_2,ulong param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  ulong unaff_EDI;
  
  if (param_1 != (CMwCmdBufferCore *)0x0) {
    if (param_2 == 0) {
      param_2 = 1;
    }
    iVar1 = (int)(1000 / (ulonglong)(uint)param_2);
    iVar2 = iVar1 * param_2;
    uVar4 = iVar2 * -0x80000000;
    uVar3 = func_0x009c1810(uVar4,1000U - iVar2 >> 1,param_2,0);
    EnableFixedTickTime(this,param_1,iVar1,uVar3,uVar4);
    return;
  }
  EnableFixedTickTime(this,(CMwCmdBufferCore *)0x0,0,0,unaff_EDI);
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::EnableFixedTickTime
// =================================================
void __thiscall
CMwCmdBufferCore::EnableFixedTickTime
          (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,int param_2,ulong param_3,ulong param_4)
{
{
  if (param_1 != (CMwCmdBufferCore *)0x0) {
    *(ulong *)(this + 0x3c) = param_3;
    *(int *)(this + 0x38) = param_2;
    *(undefined4 *)(this + 0x40) = 0x40000000;
    *(int *)(this + 0x18) = param_2;
    return;
  }
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x40) = 0x40000000;
  *(undefined4 *)(this + 0x18) = 0;
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::ForceFpuCwForSimulationX86
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CMwCmdBufferCore::ForceFpuCwForSimulationX86(char *param_1)
{
{
  ushort in_FPUControlWord;
  
  if ((in_FPUControlWord & 0x300) != 0) {
    _DAT_00d732f0 = _DAT_00d732f0 + 1;
    in_FPUControlWord = in_FPUControlWord & 0xfcff;
  }
  if ((in_FPUControlWord & 0xc00) != 0) {
    _DAT_00d732ec = _DAT_00d732ec + 1;
  }
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::GetMwClassId
// =================================================
ulong __thiscall CMwCmdBufferCore::GetMwClassId(CMwCmdBufferCore *this,CControlStyle *param_1)
{
{
  return 0x1020000;
}
}

// =================================================
// Function: CMwCmdBufferCore::GetSchemePeriod
// =================================================
ulong __thiscall
CMwCmdBufferCore::GetSchemePeriod(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,ulong param_2)
{
{
  EMwSchemeTimedPatterns EVar1;
  int extraout_ECX;
  
  EVar1 = MwGetSchemeTimedPattern((ulong)param_1);
  return *(ulong *)(extraout_ECX + 200 + EVar1 * 8);
}
}

// =================================================
// Function: CMwCmdBufferCore::GetSchemeProperies
// =================================================
SMwSchemeTimedProperties * __thiscall
CMwCmdBufferCore::GetSchemeProperies(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,ulong param_2)
{
{
  EMwSchemeTimedPatterns EVar1;
  int extraout_ECX;
  
  EVar1 = MwGetSchemeTimedPattern((ulong)param_1);
  return (SMwSchemeTimedProperties *)(extraout_ECX + 200 + EVar1 * 8);
}
}

// =================================================
// Function: CMwCmdBufferCore::HighFrequencyAddCmd
// =================================================
void __thiscall
CMwCmdBufferCore::HighFrequencyAddCmd
          (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,CMwNod *param_2,
          _func___cdecl_void *param_3)
{
{
  _func___cdecl_void *p_Var1;
  CMwCmdFastCall *this_00;
  int *extraout_EAX;
  ulong unaff_ESI;
  int *this_01;
  ulong unaff_EDI;
  uchar **ppuVar2;
  ulong *puVar3;
  
  puVar3 = (ulong *)&LAB_00ae2d2b;
  p_Var1 = (_func___cdecl_void *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ppuVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  this_00 = operator_new(0x24);
  this_01 = (int *)0x0;
  if (this_00 != (CMwCmdFastCall *)0x0) {
    CMwCmdFastCall::CMwCmdFastCall(this_00,(CMwCmdFastCall *)param_1,param_2,p_Var1,unaff_EDI);
    this_01 = extraout_EAX;
  }
  CInputEventsStore::Lock
            (this_01,*(CDx9DynamicVB **)(this + 0x2c),unaff_ESI,(ulong)this_00,ppuVar2,puVar3);
  (**(code **)(*this_01 + 0x7c))();
  ExceptionList = param_3;
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::HighFrequencyEnterSafeSection
// =================================================
void __thiscall
CMwCmdBufferCore::HighFrequencyEnterSafeSection
          (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,ulong param_2)
{
{
  *(int *)(this + 0x60) = *(int *)(this + 0x60) + 1;
  HighFrequencyRun(this,param_1,param_2);
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::HighFrequencyLeaveSafeSection
// =================================================
void __thiscall
CMwCmdBufferCore::HighFrequencyLeaveSafeSection(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1)
{
{
  *(int *)(this + 0x60) = *(int *)(this + 0x60) + -1;
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::HighFrequencyRun
// =================================================
void __thiscall
CMwCmdBufferCore::HighFrequencyRun(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,ulong param_2)
{
{
  bool bVar1;
  bool bVar2;
  uint extraout_EAX;
  int iVar3;
  int extraout_EDX;
  uint local_8;
  int local_4;
  
  if ((((0 < *(int *)(this + 0x60)) && (*(int *)(this + 0x30) != 0)) && (*(int *)(this + 0x68) == 0)
      ) && (*(int *)(this + 100) = *(int *)(this + 100) + 1,
           param_1 <= *(CMwCmdBufferCore **)(this + 100))) {
    bVar1 = DAT_00d732f8 == 0;
    bVar2 = DAT_00d732fc == 0;
    *(undefined4 *)(this + 100) = 0;
    if (bVar1 && bVar2) {
      CMwProfiler::GetCPUFrequency();
      __ftol2();
      DAT_00d732f8 = extraout_EAX;
      DAT_00d732fc = extraout_EDX;
    }
    CMwProfiler::GetTimeStamp((int64 *)&local_8);
    iVar3 = (local_4 - *(int *)(this + 0x5c)) - (uint)(local_8 < *(uint *)(this + 0x58));
    if ((DAT_00d732fc <= iVar3) &&
       ((DAT_00d732fc < iVar3 || (DAT_00d732f8 < local_8 - *(uint *)(this + 0x58))))) {
      *(uint *)(this + 0x58) = local_8;
      *(int *)(this + 0x5c) = local_4;
      *(undefined4 *)(this + 0x68) = 1;
      CMwCmdBuffer::Run(*(CMwCmdBuffer **)(this + 0x2c),(CMwCmdExpStringConcat *)0x0);
      ForceFpuCwForSimulationX86("HighFreq");
      *(undefined4 *)(this + 0x68) = 0;
    }
  }
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::HighFrequencySubCmd
// =================================================
void __thiscall
CMwCmdBufferCore::HighFrequencySubCmd
          (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,CMwNod *param_2,
          _func___cdecl_void *param_3)
{
{
  CMwNod *this_00;
  CMwCmdBuffer *this_01;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCVar1;
  GmQuat *pGVar2;
  int iVar3;
  CMwNod *unaff_EDI;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCVar4;
  GxTexCoordSet *pGVar5;
  int iVar6;
  CMwNod *local_c;
  CMwNod *pCStack_8;
  undefined4 local_4;
  
  pCStack_8 = (CMwNod *)&LAB_00ae2eb8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar4 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0;
  local_4 = 0;
  pCVar1 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     ((void *)(*(int *)(this + 0x2c) + 0x2c),
                      (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  if (pCVar1 != (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0) {
    do {
      pGVar5 = (GxTexCoordSet *)0x9238a2;
      pGVar2 = CFastBufferCat<int,struct_SFastCat>::GetElemInAll
                         ((void *)(*(int *)(this + 0x2c) + 0x20),pCVar4,(ulong)unaff_EDI);
      this_00 = *(CMwNod **)pGVar2;
      if (this_00 != (CMwNod *)0x0) {
        unaff_EDI = (CMwNod *)0x1012000;
        iVar3 = (**(code **)(*(int *)this_00 + 0x10))();
        if (((iVar3 != 0) && (*(CMwNod **)(this_00 + 0x20) == param_2)) &&
           (*(_func___cdecl_void **)(this_00 + 0x1c) == param_3)) {
          iVar6 = 0x9238dc;
          CMwNod::MwAddRef(this_00,unaff_EDI);
          unaff_EDI = (CMwNod *)0x9238ec;
          pCStack_8 = this_00;
          (**(code **)(*(int *)this_00 + 0x80))();
          this_01 = *(CMwCmdBuffer **)(this + 0x2c);
          iVar3 = CFastArray<class_CGameMenuFrame*>::Find
                            (this_01 + 0x2c,(CFastArray<class_GxTexCoordSet> *)&stack0x00000000,
                             pGVar5);
          if (iVar3 != -1) {
            CMwCmdBuffer::UnistallCmd(this_01,(CMwCmdBuffer *)this_00,(CMwCmd *)0x1,iVar6);
          }
          break;
        }
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  if (local_c != (CMwNod *)0x0) {
    CMwNod::MwRelease(local_c,unaff_EDI);
  }
  ExceptionList = pCStack_8;
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::HighFrequencyYield
// =================================================
void __thiscall
CMwCmdBufferCore::HighFrequencyYield(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,ulong param_2)
{
{
  ulong unaff_retaddr;
  
  HighFrequencyEnterSafeSection(DAT_00d731e0,param_1,unaff_retaddr);
  HighFrequencyLeaveSafeSection(DAT_00d731e0,param_1);
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::InitCmdBuffer
// =================================================
void __thiscall CMwCmdBufferCore::InitCmdBuffer(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1)
{
{
  CMwCmdBufferCore *this_00;
  CMwCmdBuffer *this_01;
  undefined4 extraout_EAX;
  SCasterCat *pSVar1;
  CMwCmdBuffer *pCVar2;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
  *unaff_EBX;
  CMwCmdBuffer *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CMwCmdBuffer *unaff_EDI;
  undefined4 uVar4;
  void *pvStack00000014;
  undefined4 uStack00000018;
  CMwCmdBufferCore *pCVar5;
  CMwCmdBufferCore *pCVar6;
  
  pCVar6 = (CMwCmdBufferCore *)&LAB_00ae2e21;
  ExceptionList = &stack0xfffffff4;
  pCVar5 = this;
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (this + 0x1c,(CFastBuffer<class_CSystemFidsFolder*> *)0x22,
             DAT_00cca150 ^ (uint)&stack0xffffffe0);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  do {
    this_01 = operator_new(0x48);
    uVar4 = 0;
    if (this_01 != (CMwCmdBuffer *)0x0) {
      CMwCmdBuffer::CMwCmdBuffer(this_01,unaff_EDI);
      uVar4 = extraout_EAX;
    }
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x1c,pCVar3,(ulong)unaff_EDI);
    pCVar3 = pCVar3 + 1;
    *(undefined4 *)pSVar1 = uVar4;
  } while (pCVar3 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x22);
  this_00 = this + 0x24;
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)&DAT_00000012,unaff_ESI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  do {
    pCVar2 = operator_new(0x48);
    if (pCVar2 == (CMwCmdBuffer *)0x0) {
      uVar4 = 0;
    }
    else {
      CMwCmdBuffer::CMwCmdBuffer(pCVar2,unaff_EBP);
      uVar4 = extraout_EAX_00;
    }
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,pCVar3,(ulong)unaff_EBP);
    *(undefined4 *)pSVar1 = uVar4;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,pCVar3,(ulong)unaff_EBX);
    unaff_EBX = *(CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                  **)(this + (&DAT_00bc5ee0)[(int)pCVar3] * 8 + 0xcc);
    unaff_EBP = (CMwCmdBuffer *)0x923585;
    CMwCmdBuffer::SetCatCount(*(CMwCmdBuffer **)pSVar1,unaff_EBX,(ulong)pCVar5);
    pCVar3 = pCVar3 + 1;
  } while (pCVar3 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000012);
  pCVar2 = operator_new(0x48);
  pvStack00000014 = (void *)0x2;
  if (pCVar2 == (CMwCmdBuffer *)0x0) {
    uVar4 = 0;
  }
  else {
    CMwCmdBuffer::CMwCmdBuffer(pCVar2,this_01);
    uVar4 = extraout_EAX_01;
  }
  uStack00000018 = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = uVar4;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  StopSimulation(this,pCVar6);
  ExceptionList = pvStack00000014;
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall
CMwCmdBufferCore::MwGetClassInfo(CMwCmdBufferCore *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d732c0;
}
}

// =================================================
// Function: CMwCmdBufferCore::MwIsKindOf
// =================================================
int __thiscall
CMwCmdBufferCore::MwIsKindOf(CMwCmdBufferCore *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdAffectParam *)0x1020000) {
    return 1;
  }
  return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
}
}

// =================================================
// Function: CMwCmdBufferCore::MwNewCMwCmdBufferCore
// =================================================
CMwNod * __cdecl CMwCmdBufferCore::MwNewCMwCmdBufferCore(void)
{
{
  CMwCmdBufferCore *pCVar1;
  CMwNod *extraout_EAX;
  CMwCmdBufferCore *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ae2e4b;
  local_c = ExceptionList;
  pCVar1 = (CMwCmdBufferCore *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x108);
  local_4 = 0;
  if (local_10 != (CMwCmdBufferCore *)0x0) {
    CMwCmdBufferCore(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CMwCmdBufferCore::Run
// =================================================
void __thiscall CMwCmdBufferCore::Run(CMwCmdBufferCore *this,CMwCmdExpStringConcat *param_1)
{
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  CMwId *pCVar4;
  SCasterCat *pSVar5;
  CMwTimer *pCVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CMwTimerAdapter *unaff_EBX;
  uint uVar8;
  CMwTimer *unaff_EBP;
  CNetIPC *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CMwCmdBufferCore *unaff_EDI;
  ulong unaff_retaddr;
  ulong in_stack_00000008;
  ulong in_stack_0000000c;
  uint uVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000014;
  uint in_stack_00000018;
  CMwTimerAdapter *in_stack_fffffff4;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff8;
  CPlugAudio *in_stack_fffffffc;
  
  if (*(int *)(this + 0x30) != 0) {
    if (DAT_00d731e0 != (CMwCmdBufferCore *)0x0) {
      HighFrequencyLeaveSafeSection(DAT_00d731e0,unaff_EDI);
    }
    if ((*(int *)(this + 0x38) == 0) && (*(int *)(this + 0x3c) == 0)) {
      CMwTimer::Tick(this + 0x70,unaff_ESI);
    }
    else {
      pCVar6 = (CMwTimer *)
               (*(int *)(this + 0x38) - (*(int *)(this + 0x3c) + *(int *)(this + 0x40) >> 0x1f));
      *(uint *)(this + 0x40) = *(int *)(this + 0x3c) + *(int *)(this + 0x40) & 0x7fffffff;
      *(CMwTimer **)(this + 0x18) = pCVar6;
      CMwTimer::SimulateDeltaTime(this + 0x70,pCVar6,(ulong)unaff_ESI);
    }
    CMwTimer::ChopTime(this + 0x70,unaff_EBP);
    CMwTimerAdapter::Resync(this + 0xa0,unaff_EBX);
    CMwTimerAdapter::ComputeTimeAtHumanTick(this + 0xa0,in_stack_fffffff4);
    if (*(int *)(this + 0x34) != 0) {
      ForceFpuCwForSimulationX86("CoreCmd_Simulation");
      in_stack_00000008 = 0;
      in_stack_00000014 =
           (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x24,in_stack_fffffff8);
LAB_00922e60:
      uVar8 = DAT_00d731ec;
      uVar10 = DAT_00d731ec;
      if ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1 < in_stack_00000014) {
        puVar3 = &DAT_00d731f8;
        pCVar7 = in_stack_00000014 + -1;
        do {
          uVar1 = *puVar3;
          if (uVar1 < uVar8) {
            uVar8 = uVar1;
            uVar10 = uVar1;
          }
          puVar3 = puVar3 + 3;
          pCVar7 = pCVar7 + -1;
        } while (pCVar7 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0);
      }
      if (*(int *)(this + 0xc4) != 0) {
LAB_00922eb7:
        in_stack_0000000c = in_stack_0000000c + 1;
        pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        *(uint *)(this + 0xbc) = uVar8;
        if (in_stack_00000014 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          puVar3 = &DAT_00d731f0;
          do {
            if (puVar3[-1] <= uVar8) {
              iVar2 = (&DAT_00bc5ee0)[(int)pCVar7];
              *(undefined4 *)(this + 0xb8) = *(undefined4 *)(this + iVar2 * 8 + 200);
              pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (this + 0x24,pCVar7,(ulong)in_stack_fffffffc);
              CMwCmdBuffer::Run(*(CMwCmdBuffer **)pSVar5,(CMwCmdExpStringConcat *)*puVar3);
              *puVar3 = *puVar3 + 1;
              if (*puVar3 < *(uint *)(this + iVar2 * 8 + 0xcc)) {
                puVar3[-1] = puVar3[-1] +
                             *(uint *)(this + iVar2 * 8 + 200) / *(uint *)(this + iVar2 * 8 + 0xcc);
              }
              else {
                *puVar3 = 0;
                puVar3[-1] = puVar3[-2];
                puVar3[-2] = *(int *)(this + iVar2 * 8 + 200) + puVar3[-2];
              }
              in_stack_fffffffc = (CPlugAudio *)0x1;
              HighFrequencyYield(this,(CMwCmdBufferCore *)0x1,unaff_retaddr);
              uVar8 = in_stack_00000018;
            }
            pCVar7 = pCVar7 + 1;
            puVar3 = puVar3 + 3;
          } while (pCVar7 < in_stack_00000014);
        }
        *(int *)(this + 0xc0) = *(int *)(this + 0xc0) + 1;
        goto LAB_00922e60;
      }
      pCVar4 = CPlugAudio::MwGetId((CPlugAudio *)(this + 0xa0),in_stack_fffffffc);
      if (uVar8 <= *(uint *)pCVar4) {
        if (999 < uVar10) goto LAB_00922f6b;
        goto LAB_00922eb7;
      }
      if (uVar10 < 1000) goto LAB_00922f8a;
LAB_00922f6b:
      CMwTimerAdapter::SetCurrentTimeAtHumanTick
                ((CPlugAudio *)(this + 0xa0),*(CMwTimerAdapter **)(this + 0xbc),unaff_retaddr);
      if (*(CMwCmdBuffer **)(this + 0x100) != (CMwCmdBuffer *)0x0) {
        CMwCmdBuffer::Run(*(CMwCmdBuffer **)(this + 0x100),(CMwCmdExpStringConcat *)0x0);
      }
    }
LAB_00922f8a:
    ForceFpuCwForSimulationX86("CoreCmd_Async");
    pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this + 0x1c,(CFastBuffer<class_CCrystalFace*> *)param_1);
    pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar7 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x1c,pCVar9,in_stack_00000008);
        CMwCmdBuffer::Run(*(CMwCmdBuffer **)pSVar5,(CMwCmdExpStringConcat *)0x0);
        in_stack_00000008 = 1;
        HighFrequencyYield(this,(CMwCmdBufferCore *)0x1,in_stack_0000000c);
        pCVar9 = pCVar9 + 1;
      } while (pCVar9 < pCVar7);
    }
    *(int *)(this + 0xc0) = *(int *)(this + 0xc0) + 1;
    if (DAT_00d731e0 != (CMwCmdBufferCore *)0x0) {
      HighFrequencyEnterSafeSection(DAT_00d731e0,(CMwCmdBufferCore *)0x1,(ulong)in_stack_00000014);
    }
  }
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::SetIsSimulationOnly
// =================================================
void __thiscall
CMwCmdBufferCore::SetIsSimulationOnly(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,int param_2)
{
{
  *(CMwCmdBufferCore **)(this + 0xc4) = param_1;
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::SetSchemePatternsProperties
// =================================================
void __thiscall
CMwCmdBufferCore::SetSchemePatternsProperties
          (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,SMwSchemeTimedProperties *param_2)
{
{
  int iVar1;
  CMwCmdBufferCore *pCVar2;
  
  if (param_1 == (CMwCmdBufferCore *)0x0) {
    param_1 = (CMwCmdBufferCore *)&DAT_00bc5f28;
  }
  pCVar2 = this + 200;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pCVar2 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    pCVar2 = pCVar2 + 4;
  }
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::SetSimulationCurrentTime
// =================================================
void __thiscall
CMwCmdBufferCore::SetSimulationCurrentTime
          (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,ulong param_2)
{
{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  int *piVar5;
  ulong unaff_EDI;
  uint uVar6;
  int in_stack_0000000c;
  
  CMwTimerAdapter::SetCurrentTimeAtHumanTick(this + 0xa0,(CMwTimerAdapter *)param_1,unaff_EDI);
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x24,unaff_EBP);
  if (uVar3 != 0) {
    uVar6 = 0;
    piVar5 = &DAT_00d731ec;
    do {
      iVar1 = (&DAT_00bc5ee0)[uVar6];
      piVar5[1] = 0;
      uVar2 = *(uint *)(this + iVar1 * 8 + 200);
      uVar6 = uVar6 + 1;
      iVar4 = (((uVar2 - 1) + in_stack_0000000c) / uVar2) * uVar2;
      *piVar5 = iVar4;
      piVar5[-1] = *(uint *)(this + iVar1 * 8 + 200) + iVar4;
      piVar5 = piVar5 + 3;
    } while (uVar6 < uVar3);
  }
  if (*(CMwCmdBuffer **)(this + 0x100) != (CMwCmdBuffer *)0x0) {
    CMwCmdBuffer::Run(*(CMwCmdBuffer **)(this + 0x100),(CMwCmdExpStringConcat *)0x0);
  }
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::SetSimulationRelativeSpeed
// =================================================
void __thiscall
CMwCmdBufferCore::SetSimulationRelativeSpeed
          (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  if ((*(int *)(this + 0x34) != 0) && ((float)param_1 < 0.0)) {
    param_1 = (CMwCmdBufferCore *)0x0;
  }
  CMwTimerAdapter::SetRelativeSpeed(this + 0xa0,(CMwTimerAdapter *)param_1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::SnapTimeToPreviousSchemePeriod
// =================================================
ulong __thiscall
CMwCmdBufferCore::SnapTimeToPreviousSchemePeriod
          (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,EMwSchemeTimedPatterns param_2,
          ulong param_3)
{
{
  ulong uVar1;
  ulong unaff_retaddr;
  
  uVar1 = GetSchemePeriod(this,param_1,unaff_retaddr);
  return (param_3 / uVar1) * uVar1;
}
}

// =================================================
// Function: CMwCmdBufferCore::SnapTimeToSchemePeriod
// =================================================
ulong __thiscall
CMwCmdBufferCore::SnapTimeToSchemePeriod
          (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,EMwSchemeTimedPatterns param_2,
          ulong param_3)
{
{
  ulong uVar1;
  ulong unaff_retaddr;
  
  uVar1 = GetSchemePeriod(this,param_1,unaff_retaddr);
  return (((uVar1 - 1) + param_3) / uVar1) * uVar1;
}
}

// =================================================
// Function: CMwCmdBufferCore::StartSimulation
// =================================================
void __thiscall
CMwCmdBufferCore::StartSimulation
          (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,int param_2,int param_3,float param_4)
{
{
  int iVar1;
  uint uVar2;
  CMwId *pCVar3;
  ulong uVar4;
  int iVar5;
  int *piVar6;
  float unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CPlugAudio *unaff_EDI;
  uint uVar7;
  CMwTimerAdapter *in_stack_00000014;
  
  uVar7 = 0;
  if (param_1 == (CMwCmdBufferCore *)0x0) {
    pCVar3 = CPlugAudio::MwGetId((CPlugAudio *)(this + 0xa0),unaff_EDI);
    if (((param_3 != 0) && (*(uint *)(this + 0xbc) <= *(uint *)pCVar3)) &&
       (*(uint *)pCVar3 <= *(uint *)(this + 0xbc) + 1000)) goto LAB_009230b3;
  }
  else {
    CMwTimerAdapter::SetCurrentTimeAtHumanTick
              ((CPlugAudio *)(this + 0xa0),(CMwTimerAdapter *)0x1,(ulong)unaff_EDI);
    *(undefined4 *)(this + 0xbc) = 1;
    *(undefined4 *)(this + 0xb4) = 1;
  }
  if (*(CMwCmdBuffer **)(this + 0x100) != (CMwCmdBuffer *)0x0) {
    CMwCmdBuffer::Run(*(CMwCmdBuffer **)(this + 0x100),(CMwCmdExpStringConcat *)0x0);
  }
LAB_009230b3:
  uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x24,unaff_ESI);
  if (uVar4 != 0) {
    piVar6 = &DAT_00d731ec;
    do {
      iVar1 = (&DAT_00bc5ee0)[uVar7];
      piVar6[1] = 0;
      uVar2 = *(uint *)(this + iVar1 * 8 + 200);
      uVar7 = uVar7 + 1;
      iVar5 = (((uVar2 - 1) + param_3) / uVar2) * uVar2;
      *piVar6 = iVar5;
      piVar6[-1] = *(uint *)(this + iVar1 * 8 + 200) + iVar5;
      piVar6 = piVar6 + 3;
    } while (uVar7 < uVar4);
  }
  *(undefined4 *)(this + 0x34) = 1;
  CMwTimerAdapter::SetRelativeSpeed(param_1,in_stack_00000014,unaff_EBP);
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::StopSimulation
// =================================================
void __thiscall CMwCmdBufferCore::StopSimulation(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1)
{
{
  float unaff_ESI;
  
  CMwTimerAdapter::SetRelativeSpeed(this + 0xa0,(CMwTimerAdapter *)0x0,unaff_ESI);
  *(undefined4 *)(this + 0x34) = 0;
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::SubNotifySetTime
// =================================================
void __thiscall
CMwCmdBufferCore::SubNotifySetTime
          (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,CMwNod *param_2,
          _func___cdecl_void *param_3)
{
{
  int *piVar1;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCVar2;
  GmQuat *pGVar3;
  int iVar4;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCVar5;
  
  if (*(int *)(this + 0x100) != 0) {
    pCVar2 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       ((void *)(*(int *)(this + 0x100) + 0x2c),unaff_EDI);
    pCVar5 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0;
    if (pCVar2 != (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0) {
      do {
        pGVar3 = CFastBufferCat<int,struct_SFastCat>::GetElemInAll
                           ((void *)(*(int *)(this + 0x100) + 0x20),pCVar5,unaff_ESI);
        piVar1 = *(int **)pGVar3;
        if (piVar1 != (int *)0x0) {
          unaff_ESI = 0x1012000;
          iVar4 = (**(code **)(*piVar1 + 0x10))();
          if ((((iVar4 != 0) && ((CMwNod *)piVar1[8] == param_2)) &&
              ((_func___cdecl_void *)piVar1[7] == param_3)) && ((*(byte *)(piVar1 + 6) & 2) == 0)) {
            (**(code **)(*piVar1 + 0x80))();
            break;
          }
        }
        pCVar5 = pCVar5 + 1;
      } while (pCVar5 < pCVar2);
    }
    piVar1 = *(int **)(this + 0x100);
    if (piVar1[7] == 0) {
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(1);
      }
      *(undefined4 *)(this + 0x100) = 0;
    }
  }
  return;
}
}

// =================================================
// Function: CMwCmdBufferCore::VirtualParam_Get
// =================================================
ulong __thiscall
CMwCmdBufferCore::VirtualParam_Get
          (CMwCmdBufferCore *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong *puVar4;
  CMwId *pCVar5;
  ulong uVar6;
  CPlugAudio *this_00;
  CMwTimerAdapter *unaff_EDI;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (0x1020003 < uVar3) {
    if (uVar3 == 0x1020004) {
      *(CMwStack **)param_2 = param_2 + 4;
      pCVar5 = CPlugAudio::MwGetId((CPlugAudio *)(this + 0xa0),(CPlugAudio *)unaff_EDI);
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)pCVar5;
    }
    else if (uVar3 != 0xffffffff) goto LAB_00922d7e;
    return 0;
  }
  if (uVar3 == 0x1020003) {
    this_00 = *(CPlugAudio **)(this + 0x14);
    if (this_00 == (CPlugAudio *)0x0) {
      this_00 = (CPlugAudio *)(this + 0xa0);
    }
    *(CMwStack **)param_2 = param_2 + 4;
    pCVar5 = CPlugAudio::MwGetId(this_00,(CPlugAudio *)unaff_EDI);
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)pCVar5;
    return 0;
  }
  if (uVar3 == 0x1020001) {
    *(CMwStack **)param_2 = param_2 + 4;
    puVar4 = CMwTimer::GetTickTime(this + 0x70,unaff_EDI);
    *(ulong *)(param_2 + 4) = *puVar4;
    return 0;
  }
  if (uVar3 == 0x1020002) {
    *(CMwStack **)param_2 = param_2 + 4;
    puVar4 = CMwTimer::GetTickTime(this + 0x70,unaff_EDI);
    *(ulong *)(param_2 + 4) = *puVar4;
    return 0;
  }
LAB_00922d7e:
  *(int *)(param_1 + 0x18) = iVar1;
  uVar6 = CMwNod::VirtualParam_Get((CMwNod *)this,param_1,param_2,param_3);
  return uVar6;
}
}

// =================================================
// Function: CMwCmdBufferCore::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CMwCmdBufferCore::_scalar_deleting_destructor_
          (CMwCmdBufferCore *this,CPfmHeap *param_1,uint param_2)
{
{
  CMwCmdBufferCore *unaff_ESI;
  
  ~CMwCmdBufferCore(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CMwCmdBufferCore::~CMwCmdBufferCore
// =================================================
void __thiscall
CMwCmdBufferCore::~CMwCmdBufferCore(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1)
{
{
  CCrystalLink *pCVar1;
  CFastArray<class_CFuncShader*> *unaff_EBX;
  CFastArray<class_CCrystalEdge*> *unaff_ESI;
  CFastArray<class_CCrystalEdge*> *unaff_EDI;
  void *in_stack_0000000c;
  undefined4 uStack00000010;
  CMwCmdBufferCore *pCVar2;
  CMwNod *pCVar3;
  
  pCVar3 = ExceptionList;
  pCVar1 = (CCrystalLink *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &stack0xfffffff4;
  *(undefined ***)this = vftable;
  pCVar2 = this;
  Disable(this,pCVar1);
  CFastArray<class_CManoeuvre*>::DeleteAll(this + 0x1c,unaff_EDI);
  CFastArray<class_CManoeuvre*>::DeleteAll(this + 0x24,unaff_ESI);
  CMwCmdBuffer::Run(*(CMwCmdBuffer **)(this + 0x2c),(CMwCmdExpStringConcat *)0x0);
  if (*(int **)(this + 0x2c) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x2c) + 4))();
  }
  MwSystemTimerDestroy();
  if (*(int **)(this + 0x100) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x100) + 4))();
  }
  DAT_00d731e0 = 0;
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>(this + 0x24,unaff_EBX);
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>
            (this + 0x1c,(CFastArray<class_CFuncShader*> *)pCVar2);
  uStack00000010 = 0xffffffff;
  CMwNod::~CMwNod((CMwNod *)this,pCVar3);
  ExceptionList = in_stack_0000000c;
  return;
}
}

