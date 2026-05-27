// Class implementation: CSystemEngine

// =================================================
// Function: CSystemEngine::AddFidNod
// =================================================
void __thiscall
CSystemEngine::AddFidNod
          (CSystemEngine *this,CSystemEngine *param_1,CMwNod *param_2,CSystemFid *param_3,
          CSystemFidParameters *param_4)
{
{
  CPlugMaterial *pCVar1;
  CSystemFid *unaff_EBX;
  GmVec3 *unaff_ESI;
  CSystemFid *unaff_EDI;
  
  pCVar1 = CSystemFid::GetNod((CSystemFid *)param_2,(CSysFidNodRef<class_CPlugMaterial> *)param_3);
  if (pCVar1 == (CPlugMaterial *)0x0) {
    BindFidNod(this,param_1,param_2,unaff_EDI);
    CSystemFidParameters::operator=
              ((CSystemFidParameters *)(param_2 + 0x34),(SNormalDec3N *)param_3,unaff_ESI);
    CSystemFids::AddLeaveIfNot(*(CSystemFids **)(param_2 + 0x14),(CSystemFids *)param_2,unaff_EBX);
  }
  return;
}
}

// =================================================
// Function: CSystemEngine::ApplySystemConfig
// =================================================
void __thiscall
CSystemEngine::ApplySystemConfig
          (CSystemEngine *this,CVisionViewportDx9 *param_1,CSystemConfig *param_2,int param_3)
{
{
  I18nSetLanguage(this,*(CSystemEngine **)(param_1 + 0x1c),(char *)param_2);
  return;
}
}

// =================================================
// Function: CSystemEngine::BindFidNod
// =================================================
void __thiscall
CSystemEngine::BindFidNod
          (CSystemEngine *this,CSystemEngine *param_1,CMwNod *param_2,CSystemFid *param_3)
{
{
  CScene3d *unaff_ESI;
  CSystemFid *unaff_EDI;
  
  if ((param_1 != (CSystemEngine *)0x0) && (param_2 != (CMwNod *)0x0)) {
    if (*(CMwNod **)(param_1 + 8) != (CMwNod *)0x0) {
      UnbindFidNod(this,param_1,*(CMwNod **)(param_1 + 8),unaff_EDI);
    }
    CSystemFid::SetNod((CSystemFid *)param_2,(CSysFidNodRef<class_CScene3d> *)param_1,unaff_ESI);
  }
  return;
}
}

// =================================================
// Function: CSystemEngine::CSystemEngine
// =================================================
void __thiscall CSystemEngine::CSystemEngine(CSystemEngine *this,CSystemEngine *param_1)
{
{
  undefined4 extraout_EAX;
  undefined4 uVar1;
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  void *in_stack_00000008;
  undefined1 uStack0000000c;
  CSystemEngine *pCVar2;
  ulong in_stack_fffffff0;
  void *local_c;
  undefined1 *puStack_8;
  CSystemManagerFile *local_4;
  
  local_4 = (CSystemManagerFile *)0xffffffff;
  puStack_8 = &LAB_00a81724;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar2 = this;
  CMwEngine::CMwEngine((CMwEngine *)this,(CMwEngine *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x38,unaff_EDI);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x44,unaff_ESI);
  *(undefined4 *)(this + 100) = 0;
  *(undefined **)(this + 0x68) = PTR_DAT_00bbf7dc;
  local_4 = operator_new(0x14);
  in_stack_00000008 = (void *)CONCAT31(in_stack_00000008._1_3_,4);
  if (local_4 == (CSystemManagerFile *)0x0) {
    uVar1 = 0;
  }
  else {
    CSystemManagerFile::CSystemManagerFile(local_4,(CSystemManagerFile *)pCVar2);
    uVar1 = extraout_EAX;
  }
  *(undefined4 *)(this + 0x20) = uVar1;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  uStack0000000c = 3;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  DAT_00d7333c = operator_new(0xc);
  if (DAT_00d7333c == (undefined4 *)0x0) {
    DAT_00d7333c = (undefined4 *)0x0;
  }
  else {
    *DAT_00d7333c = CFastCallbackInstance1P<class_CSystemEngine,class_CMwNod*>::vftable;
    DAT_00d7333c[1] = this;
    DAT_00d7333c[2] = UnbindFid;
  }
  CaptureInfoOsCpu();
  SSysGraphicAdapter::CaptureInfoGpu(&DAT_00d542a0,(SSysGraphicAdapter *)0x0,in_stack_fffffff0);
  LogSystemInfos();
  ExceptionList = in_stack_00000008;
  return;
}
}

// =================================================
// Function: CSystemEngine::CaptureInfoOsCpu
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CSystemEngine::CaptureInfoOsCpu(void)
{
{
  WCHAR WVar1;
  undefined8 uVar2;
  bool bVar3;
  SOldChars *pSVar4;
  LSTATUS LVar5;
  CPlugFileGpuBuilder *pCVar6;
  int iVar7;
  HANDLE pvVar8;
  HANDLE hProcess;
  undefined *puVar9;
  uint uVar10;
  SStringParam *hKey;
  ulong uVar11;
  int extraout_EAX;
  int extraout_EAX_00;
  HMODULE hModule;
  FARPROC pFVar12;
  WCHAR *pWVar13;
  BOOL BVar14;
  char cVar15;
  CSystemEngine *this;
  uint uVar16;
  SStringParam *hKey_00;
  uint uVar17;
  CFastString *unaff_EBX;
  SStringParam *unaff_ESI;
  CFastStringBase<wchar_t> *pCVar18;
  CFastStringBase<wchar_t> *pCVar19;
  uint uVar20;
  SOldChars *unaff_EDI;
  SStringParam *pSVar21;
  ushort in_FPUControlWord;
  float fVar22;
  undefined4 uStack0000000c;
  void *pvStack0000001c;
  HKEY pHVar23;
  char *pcVar24;
  char *pcVar25;
  char *pcVar26;
  SHeaderCommunity *lpcbData;
  CPlugFileGpuBuilder *pCVar27;
  CPlugFileGpuBuilder *in_stack_fffff6f4;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffff6f8;
  CFastStringBase<wchar_t> in_stack_fffff6fc;
  EKindOS EVar28;
  SStringParam *pSVar29;
  HKEY__ in_stack_fffff700;
  HKEY__ HVar30;
  CFastStringBase<wchar_t> *dwPriorityClass;
  CFastString *in_stack_fffff708;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_fffff70c;
  CFastStringBase<wchar_t> *in_stack_fffff710;
  SStringParam *pSVar31;
  uint *puVar32;
  CFastStringInt *in_stack_fffff714;
  HKEY local_8e8;
  char *local_8e4;
  LPBYTE local_8e0;
  CFastStringBase<wchar_t> *local_8dc;
  HANDLE local_8d8;
  undefined8 uStack_8d4;
  HMODULE local_8cc;
  char *local_8c8;
  undefined *local_8c4;
  undefined *local_8c0;
  undefined *local_8bc;
  int local_8b8;
  undefined4 local_8b4;
  uint local_8b0;
  uint uStack_8ac;
  int local_8a8;
  uint local_8a4;
  int local_8a0;
  undefined1 local_89c [16];
  undefined1 local_88c [4];
  uint local_888;
  undefined4 local_884;
  char *local_878;
  int iStack_874;
  _union_530 a_Stack_86c [4];
  undefined1 local_85c [4];
  CFastStringInt local_858 [16];
  char local_848 [16];
  undefined1 auStack_838 [4];
  undefined1 auStack_834 [4];
  undefined1 auStack_830 [8];
  SStringParam *local_828;
  undefined1 local_824 [18];
  short sStack_812;
  WCHAR WStack_810;
  short sStack_80e;
  short sStack_80c;
  short sStack_80a;
  CFastStringInt aCStack_400 [996];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00a8302e;
  local_14 = ExceptionList;
  local_1c = DAT_00cca150 ^ (uint)&stack0xfffff6f4;
  pSVar4 = (SOldChars *)(DAT_00cca150 ^ (uint)&stack0xfffff6e8);
  ExceptionList = &local_14;
  local_8e4 = (char *)0x0;
  dwPriorityClass = (CFastStringBase<wchar_t> *)0x0;
  LVar5 = RegOpenKeyExA((HKEY)0x80000002,"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",0,0x20019
                        ,(PHKEY)&stack0xfffff714);
  if ((LVar5 == 0) &&
     (LVar5 = RegQueryValueExA((HKEY)in_stack_fffff714,"ProductName",(LPDWORD)0x0,
                               (LPDWORD)&stack0xfffff6f8,(LPBYTE)0x0,(LPDWORD)&stack0xfffff704),
     LVar5 == 0)) {
    if (dwPriorityClass != DAT_00d54288) {
      pCVar18 = dwPriorityClass;
      CFastStringBase<char>::AllocAtLeast
                ((CFastStringBase<char> *)&DAT_00d54288,dwPriorityClass,1,0,pSVar4);
      dwPriorityClass[(int)DAT_00d5428c] = (CFastStringBase<wchar_t>)0x0;
      DAT_00d54288 = dwPriorityClass;
      dwPriorityClass = pCVar18;
    }
    RegQueryValueExA(local_8e8,"ProductName",(LPDWORD)0x0,(LPDWORD)&stack0xfffff6fc,DAT_00d5428c,
                     (LPDWORD)&stack0xfffff708);
    pCVar18 = (CFastStringBase<wchar_t> *)(in_stack_fffff708 + -1);
    if (pCVar18 != DAT_00d54288) {
      CFastStringBase<char>::AllocAtLeast
                ((CFastStringBase<char> *)&DAT_00d54288,pCVar18,1,0,unaff_EDI);
      pCVar18[(int)DAT_00d5428c] = (CFastStringBase<wchar_t>)0x0;
      DAT_00d54288 = pCVar18;
    }
    LVar5 = RegQueryValueExA(local_8e8,"CSDVersion",(LPDWORD)0x0,(LPDWORD)&stack0xfffff6fc,
                             (LPBYTE)0x0,(LPDWORD)&stack0xfffff708);
    if (LVar5 == 0) {
      in_stack_fffff710 = (CFastStringBase<wchar_t> *)0x0;
      uStack_8 = 0;
      pCVar19 = (CFastStringBase<wchar_t> *)in_stack_fffff708;
      pcVar26 = PTR_DAT_00bbf7d8;
      if (in_stack_fffff708 != (CFastString *)0x0) {
        CFastStringBase<char>::AllocAtLeast
                  ((CFastStringBase<char> *)&stack0xfffff710,
                   (CFastStringBase<wchar_t> *)in_stack_fffff708,1,0,unaff_EDI);
        *(CFastStringBase<wchar_t> *)(in_stack_fffff708 + (int)&local_8e8->unused) =
             (CFastStringBase<wchar_t>)0x0;
        pcVar26 = (char *)in_stack_fffff708;
      }
      lpcbData = (SHeaderCommunity *)&stack0xfffff708;
      pCVar18 = (CFastStringBase<wchar_t> *)&stack0xfffff6fc;
      pcVar25 = (char *)0x0;
      in_stack_fffff714 = (CFastStringInt *)pcVar26;
      RegQueryValueExA(local_8e8,"CSDVersion",(LPDWORD)0x0,(LPDWORD)pCVar18,(LPBYTE)pcVar26,
                       (LPDWORD)lpcbData);
      pCVar19 = pCVar19 + -1;
      if (pCVar19 != in_stack_fffff710) {
        lpcbData = (SHeaderCommunity *)0x0;
        pcVar26 = (char *)0x1;
        pcVar25 = (char *)0x43454f;
        pCVar18 = pCVar19;
        CFastStringBase<char>::AllocAtLeast
                  ((CFastStringBase<char> *)&stack0xfffff710,pCVar19,1,0,unaff_EDI);
        pCVar19[(int)&local_8e8->unused] = (CFastStringBase<wchar_t>)0x0;
        in_stack_fffff714 = (CFastStringInt *)pCVar19;
      }
      pcVar24 = &DAT_00b30988;
      pHVar23 = (HKEY)&stack0xfffff700;
    }
    else {
      pcVar24 = "BuildLab";
      pHVar23 = local_8e8;
      LVar5 = RegQueryValueExA(local_8e8,"BuildLab",(LPDWORD)0x0,(LPDWORD)&stack0xfffff6fc,
                               (LPBYTE)0x0,(LPDWORD)&stack0xfffff708);
      if (LVar5 != 0) goto LAB_00434614;
      in_stack_fffff710 = (CFastStringBase<wchar_t> *)0x0;
      uStack_8 = 1;
      in_stack_fffff714 = (CFastStringInt *)PTR_DAT_00bbf7d8;
      CFastString::SetLength
                ((CFastString *)&stack0xfffff710,in_stack_fffff708,(ulong)unaff_EDI,(int)unaff_ESI,
                 (char)unaff_EBX);
      unaff_EDI = (SOldChars *)&stack0xfffff708;
      lpcbData = (SHeaderCommunity *)0x0;
      pcVar26 = "BuildLab";
      pcVar25 = (char *)0x4345c8;
      RegQueryValueExA((HKEY)local_8dc,"BuildLab",(LPDWORD)0x0,(LPDWORD)unaff_EDI,local_8e0,
                       (LPDWORD)&stack0xfffff714);
      unaff_EBX = (CFastString *)(in_stack_fffff714 + -1);
      unaff_ESI = (SStringParam *)0x4345d9;
      CFastString::SetLength
                ((CFastString *)&local_8e4,unaff_EBX,(ulong)in_stack_fffff6f4,(int)in_stack_fffff6f8
                 ,(char)in_stack_fffff6fc);
      in_stack_fffff6f8 = (CFastBuffer<class_CPlugFileSndGen*> *)&local_8d8;
      pCVar18 = local_8dc;
    }
    pCVar6 = CFastString::operator<<
                       ((CFastString *)&DAT_00d54288,(CPlugFileGpuBuilder *)&DAT_00b30b34,
                        (char *)pHVar23);
    pCVar6 = CFastString::operator<<((CFastString *)pCVar6,(CPlugFileGpuBuilder *)pcVar24,pcVar25);
    CFastString::operator<<((CFastString *)pCVar6,(CPlugFileGpuBuilder *)pCVar18,pcVar26);
    uStack_c = 0xffffffff;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xfffff70c,lpcbData);
  }
LAB_00434614:
  RegCloseKey(local_8e8);
  DAT_00d54228 = GetKindOS();
  EVar28 = DAT_00d54228;
  if (DAT_00d54288 == (CFastStringBase<wchar_t> *)0x0) {
    if (DAT_00d54228 == 1) {
      pcVar24 = "95";
    }
    else if (DAT_00d54228 == 2) {
      pcVar24 = "98";
    }
    else if (DAT_00d54228 == 3) {
      pcVar24 = "Me";
    }
    else {
      pcVar24 = "3.1";
    }
    local_8e8 = (HKEY)0xb30b10;
    local_8e4 = (char *)0x12;
    CFastString::SetString
              ((CFastString *)&DAT_00d54288,(CFastStringInt *)&local_8e8,(SStringParam *)unaff_EDI);
    if (pcVar24 == (char *)0x0) {
      local_8e0 = (LPBYTE)0x0;
    }
    else {
      pcVar26 = pcVar24;
      do {
        cVar15 = *pcVar26;
        pcVar26 = pcVar26 + 1;
      } while (cVar15 != '\0');
      local_8e0 = (LPBYTE)(pcVar26 + -(int)(pcVar24 + 1));
    }
    local_8e4 = pcVar24;
    CFastString::Concat((CFastString *)&DAT_00d54288,(CFastStringInt *)&local_8e4,unaff_ESI);
    pcVar24 = &DAT_00ccc50c;
    do {
      cVar15 = *pcVar24;
      pcVar24 = pcVar24 + 1;
    } while (cVar15 != '\0');
    if (pcVar24 != &DAT_00ccc50d) {
      pCVar27 = (CPlugFileGpuBuilder *)&DAT_00b30988;
      pCVar6 = CFastString::operator<<
                         ((CFastString *)&DAT_00d54288,(CPlugFileGpuBuilder *)&DAT_00b30b34,
                          &DAT_00ccc50c);
      pCVar6 = CFastString::operator<<((CFastString *)pCVar6,pCVar27,(char *)unaff_EBX);
      unaff_EBX = (CFastString *)0x4346f4;
      CFastString::operator<<((CFastString *)pCVar6,in_stack_fffff6f4,(char *)in_stack_fffff6f8);
    }
  }
  _memset(&lpBuffer_00d556d8,0,0x40);
  lpBuffer_00d556d8 = (LPMEMORYSTATUSEX)&DAT_00000040;
  GlobalMemoryStatusEx((LPMEMORYSTATUSEX)&lpBuffer_00d556d8);
  DAT_00d5422c = DAT_00d556e0 + 0xfffff >> 0x14 |
                 (DAT_00d556e4 + (uint)(0xfff00000 < DAT_00d556e0)) * 0x1000;
  GetSystemInfo((LPSYSTEM_INFO)(local_89c + 4));
  DAT_00ccb5e8 = 0;
  DAT_00ccb5e0 = local_884;
  _DAT_00ccb5e4 = local_888;
  for (; local_888 != 0; local_888 = local_888 >> 1) {
    if ((local_888 & 1) != 0) {
      DAT_00ccb5e8 = DAT_00ccb5e8 + 1;
    }
  }
  DAT_00d558d8 = GetSystemMetrics(0);
  DAT_00d558dc = GetSystemMetrics(1);
  DAT_00d54230 = 0;
  if (((int)EVar28 < 5) ||
     (GetSystemInfo((LPSYSTEM_INFO)&a_Stack_86c[0].s), a_Stack_86c[0].s.wProcessorArchitecture == 0)
     ) {
    DAT_00d54230 = 1;
    iVar7 = CheckSupportCPUID(local_848);
    if (iVar7 != 0) {
      iVar7 = _strncmp(local_848,"GenuineIntel",0xc);
      if (iVar7 == 0) {
        DAT_00d54230 = 2;
      }
      else {
        iVar7 = _strncmp(local_848,"AuthenticAMD",0xc);
        if (iVar7 == 0) {
          DAT_00d54230 = 3;
        }
      }
      DAT_00d54234 = GetCpuExtHardware();
    }
  }
  pvVar8 = GetCurrentThread();
  hProcess = GetCurrentProcess();
  local_8e8 = (HKEY)GetThreadPriority(pvVar8);
  puVar9 = (undefined *)GetPriorityClass(hProcess);
  SetPriorityClass(hProcess,0x100);
  SetThreadPriority(pvVar8,0xf);
  SetThreadAffinityMask(pvVar8,1);
  uVar2 = rdtsc();
  local_8b8 = (int)((ulonglong)uVar2 >> 0x20);
  local_8bc = (undefined *)uVar2;
  CMwProfiler::GetTimeStamp(&uStack_8d4);
  uVar2 = rdtsc();
  local_8a8 = (int)((ulonglong)uVar2 >> 0x20);
  uStack_8ac = (uint)uVar2;
  Sleep(this,(CMwCmdBlock *)&DAT_00000032,0);
  uVar2 = rdtsc();
  local_8a8 = (int)((ulonglong)uVar2 >> 0x20);
  uStack_8ac = (uint)uVar2;
  CMwProfiler::GetTimeStamp((int64 *)&local_8c4);
  uVar2 = rdtsc();
  local_8b8 = (int)((ulonglong)uVar2 >> 0x20);
  local_8bc = (undefined *)uVar2;
  SetPriorityClass(hProcess,(DWORD)dwPriorityClass);
  SetThreadPriority(pvVar8,(int)local_8e0);
  SetThreadAffinityMask(pvVar8,(DWORD_PTR)in_stack_fffff710);
  uVar16 = local_8a0 + local_8b0 + (uint)CARRY4(local_8a4,local_8b4);
  uVar20 = local_8a4 + local_8b4 >> 1 | uVar16 * -0x80000000;
  uVar10 = local_8b8 + local_8a8 + (uint)CARRY4((uint)local_8bc,uStack_8ac);
  uVar17 = (uint)(local_8bc + uStack_8ac) >> 1 | uVar10 * -0x80000000;
  uVar10 = ((uVar10 >> 1) - (uVar16 >> 1)) - (uint)(uVar17 < uVar20);
  hKey_00 = (SStringParam *)(uVar10 & 0x80000000);
  uStack_8d4 = -(double)(longlong)(((ulonglong)uVar10 & 0x80000000) << 0x20) +
               (double)(CONCAT44(uVar10,uVar17 - uVar20) & 0x7fffffffffffffff);
  fVar22 = CMwProfiler::GetDurationFromDeltaTimeStamp
                     (CONCAT44(local_8c0 + (-(uint)(local_8c4 < local_8cc) - (int)local_8c8),
                               (int)local_8c4 - (int)local_8cc));
  hKey = (SStringParam *)(in_FPUControlWord | 0xc00);
  local_89c._0_8_ = (undefined8)ROUND(((float)uStack_8d4 / fVar22) / (float)_DAT_00b30ae8);
  DAT_00d54238 = local_89c._0_4_;
  pSVar31 = (SStringParam *)0x0;
  LVar5 = RegOpenKeyExA((HKEY)0x80000002,"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",0,
                        0x20019,(PHKEY)&stack0xfffff704);
  if (LVar5 != 0) goto LAB_00434abc;
  LVar5 = RegQueryValueExA((HKEY)hKey,"ProcessorNameString",(LPDWORD)0x0,(LPDWORD)&local_8e0,
                           (LPBYTE)0x0,(LPDWORD)&stack0xfffff710);
  if ((LVar5 == 0) && (pSVar31 != (SStringParam *)0x0)) {
    CFastStringBase<char>::PreAlloc
              ((CFastStringBase<char> *)&DAT_00d54290,(CClassicBufferMemory *)pSVar31,
               (ulong)unaff_EBX);
    LVar5 = RegQueryValueExA((HKEY)hKey_00,"ProcessorNameString",(LPDWORD)0x0,(LPDWORD)&local_8dc,
                             (LPBYTE)DAT_00d54294,(LPDWORD)&stack0xfffff714);
    if (LVar5 != 0) goto LAB_00434a42;
LAB_00434a1e:
    CFastString::SetLength
              ((CFastString *)&DAT_00d54290,(CFastString *)(in_stack_fffff714 + -1),
               (ulong)in_stack_fffff6f4,(int)in_stack_fffff6f8,(char)SUB41(puVar9,0));
    in_stack_fffff6f8 = (CFastBuffer<class_CPlugFileSndGen*> *)0x434a40;
    puVar9 = PTR_DAT_00d34100;
    CFastString::TrimLeft
              ((CFastString *)&DAT_00d54290,(CFastString *)PTR_DAT_00d34100,
               (char *)in_stack_fffff700.unused);
  }
  else {
LAB_00434a42:
    LVar5 = RegQueryValueExA((HKEY)hKey_00,"Identifier",(LPDWORD)0x0,(LPDWORD)&local_8dc,(LPBYTE)0x0
                             ,(LPDWORD)&stack0xfffff714);
    if ((in_stack_fffff714 != (CFastStringInt *)0x0) && (LVar5 == 0)) {
      CFastStringBase<char>::PreAlloc
                ((CFastStringBase<char> *)&DAT_00d54290,(CClassicBufferMemory *)in_stack_fffff714,
                 (ulong)in_stack_fffff6f4);
      in_stack_fffff6f4 = (CPlugFileGpuBuilder *)&local_8e8;
      LVar5 = RegQueryValueExA((HKEY)in_stack_fffff70c,"Identifier",(LPDWORD)0x0,(LPDWORD)&local_8d8
                               ,(LPBYTE)DAT_00d54294,(LPDWORD)in_stack_fffff6f4);
      if (LVar5 == 0) goto LAB_00434a1e;
    }
    uStack_8d4 = (double)CONCAT44("Unknown",(undefined4)uStack_8d4);
    local_8cc = (HMODULE)0x7;
    CFastString::SetString
              ((CFastString *)&DAT_00d54290,(CFastStringInt *)((int)&uStack_8d4 + 4),
               (SStringParam *)in_stack_fffff6f4);
  }
  RegCloseKey((HKEY)in_stack_fffff70c);
LAB_00434abc:
  if (DAT_00d54298 != 0) {
    DAT_00d54298 = 0;
    *DAT_00d5429c = 0;
  }
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (auStack_838,in_stack_fffff6f8);
  uStack0000000c = 2;
  CFastBuffer<struct__IP_ADAPTER_INFO>::AllocSetCount
            (auStack_834,(CFastBuffer<class_GxVertex2> *)0x10,(ulong)puVar9);
  uVar11 = CFastBuffer<class_CCrystalFace*>::GetCount
                     (auStack_830,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffff700.unused);
  pSVar21 = local_828;
  local_8e8 = (HKEY)(uVar11 * 0x288);
  HVar30.unused = (int)&local_8e8;
  pSVar29 = local_828;
  _GetAdaptersInfo_8();
  iVar7 = extraout_EAX;
  if (extraout_EAX == 0x6f) {
    CFastBuffer<struct__IP_ADAPTER_INFO>::AllocSetCount
              (auStack_834,(CFastBuffer<class_GxVertex2> *)((uint)(pSVar31 + 0x287) / 0x288),
               (ulong)pSVar29);
    uVar11 = CFastBuffer<class_CCrystalFace*>::GetCount
                       (auStack_830,(CFastBuffer<class_CCrystalFace*> *)HVar30.unused);
    local_8e8 = (HKEY)(uVar11 * 0x288);
    HVar30.unused = (int)&local_8e8;
    pSVar29 = local_828;
    _GetAdaptersInfo_8();
    iVar7 = extraout_EAX_00;
    pSVar21 = local_828;
  }
  if (iVar7 == 0) {
    do {
      uVar10 = *(uint *)(pSVar21 + 400);
      if (5 < uVar10) {
        uVar16 = 0;
        if (uVar10 != 0) {
          do {
            CFastString::ConcatFormat
                      ((CFastString *)(uint)(byte)pSVar21[uVar16 + 0x194],
                       (CFastStringInt *)&DAT_00d54298,"%02X");
            uVar16 = uVar16 + 1;
          } while (uVar16 < uVar10);
        }
        break;
      }
      pSVar21 = *(SStringParam **)pSVar21;
    } while (pSVar21 != (SStringParam *)0x0);
  }
  else {
    local_8c8 = "DEAD000";
    local_8c4 = (undefined *)0x7;
    CFastString::Concat((CFastString *)&DAT_00d54298,(CFastStringInt *)&local_8c8,pSVar29);
    switch(iVar7) {
    case 0xd:
      SStringParam::SStringParam(&local_8d8,(SStringParam *)&DAT_00b30a74,(char *)HVar30.unused);
      HVar30.unused = (int)&uStack_8d4;
      break;
    default:
      local_8c4 = &DAT_00b2efac;
      local_8c0 = (undefined *)0x1;
      HVar30.unused = (int)&local_8c4;
      break;
    case 0x32:
      SStringParam::SStringParam(local_85c,(SStringParam *)&DAT_00b30a68,(char *)HVar30.unused);
      HVar30.unused = (int)local_858;
      break;
    case 0x57:
      SStringParam::SStringParam
                ((void *)((int)&uStack_8d4 + 4),(SStringParam *)&DAT_00b30a70,(char *)HVar30.unused)
      ;
      HVar30.unused = (int)&local_8cc;
      break;
    case 0x6f:
      SStringParam::SStringParam(local_88c,(SStringParam *)&DAT_00b30a78,(char *)HVar30.unused);
      HVar30.unused = (int)&local_888;
      break;
    case 0xe8:
      SStringParam::SStringParam(&local_8e0,(SStringParam *)&DAT_00b30a6c,(char *)HVar30.unused);
      HVar30.unused = (int)&local_8dc;
    }
    CFastString::Concat((CFastString *)&DAT_00d54298,(CFastStringInt *)HVar30.unused,hKey);
    local_8bc = &DAT_00b30a60;
    local_8b8 = 4;
    CFastString::Concat((CFastString *)&DAT_00d54298,(CFastStringInt *)&local_8bc,hKey_00);
  }
  pvStack0000001c = (void *)0xffffffff;
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(local_824,in_stack_fffff70c)
  ;
  while (DAT_00d54298 < 0xc) {
    CFastString::Concat((CFastString *)&DAT_00d54298,(CFastStringInt *)&DAT_00000030,pSVar31);
  }
  if (DAT_00d54298 != 0xc) {
    CFastStringBase<char>::AllocAtLeast
              ((CFastStringBase<char> *)&DAT_00d54298,(CFastStringBase<wchar_t> *)&DAT_0000000c,1,0,
               (SOldChars *)pSVar31);
    DAT_00d5429c[0xc] = 0;
    DAT_00d54298 = 0xc;
  }
  CFastString::Concat((CFastString *)&DAT_00d54298,(CFastStringInt *)0x2d,pSVar31);
  hModule = LoadLibraryW(L"Kernel32.dll");
  local_8cc = hModule;
  if (hModule != (HMODULE)0x0) {
    pFVar12 = GetProcAddress(hModule,"GetVolumePathNamesForVolumeNameW");
    if ((pFVar12 != (FARPROC)0x0) &&
       (pvVar8 = FindFirstVolumeW(&WStack_810,0x208), local_8d8 = pvVar8,
       pvVar8 != (HANDLE)0xffffffff)) {
      do {
        pWVar13 = &WStack_810;
        do {
          WVar1 = *pWVar13;
          pWVar13 = pWVar13 + 1;
        } while (WVar1 != L'\0');
        if ((((WStack_810 == L'\\') && (sStack_80e == 0x5c)) && (sStack_80c == 0x3f)) &&
           ((sStack_80a == 0x5c && ((&sStack_812)[(int)pWVar13 - (int)&sStack_80e >> 1] == 0x5c))))
        {
          local_8bc = (undefined *)0x208;
          iVar7 = (*pFVar12)();
          if (iVar7 == 0) {
LAB_00434e39:
            bVar3 = false;
          }
          else {
            CFastStringInt::CFastStringInt(&local_8b0,aCStack_400,(SStringParam *)in_stack_fffff714)
            ;
            local_8b0 = local_8b0 | 1;
            in_stack_fffff714 = (CFastStringInt *)&uStack_8ac;
            iVar7 = String_ConcatFixedDriveSerialFromPath
                              ((CFastString *)&DAT_00d54298,in_stack_fffff714);
            if (iVar7 == 0) goto LAB_00434e39;
            bVar3 = true;
          }
          if ((local_8b4 & 1) != 0) {
            local_8b4 = local_8b4 & 0xfffffffe;
            CGameCtnApp::SNationConfig::~SNationConfig
                      (&local_8b0,(SNationConfig *)in_stack_fffff714);
          }
          pvVar8 = local_8d8;
          if (bVar3) break;
        }
        BVar14 = FindNextVolumeW(pvVar8,&WStack_810,0x208);
      } while (BVar14 != 0);
      FindVolumeClose(pvVar8);
      hModule = local_8cc;
    }
    FreeLibrary(hModule);
  }
  if (DAT_00d54298 < 0x15) {
    local_8b4 = 0x5c3a41;
    do {
      local_8c4 = (undefined *)0x0;
      pcVar24 = (char *)&local_8b4;
      local_878 = pcVar24;
      do {
        cVar15 = *pcVar24;
        pcVar24 = pcVar24 + 1;
      } while (cVar15 != '\0');
      iStack_874 = (int)pcVar24 - ((int)&local_8b4 + 1);
      local_8c0 = PTR_DAT_00bbf7dc;
      CFastStringInt::SetString
                (&local_8c4,(CFastStringInt *)&local_878,(SStringParam *)in_stack_fffff714);
      in_stack_fffff714 = (CFastStringInt *)&local_8c0;
      puVar32 = &DAT_00d54298;
      iVar7 = String_ConcatFixedDriveSerialFromPath((CFastString *)&DAT_00d54298,in_stack_fffff714);
      if (iVar7 != 0) {
        if (local_8bc != PTR_DAT_00bbf7dc) {
          if ((local_8bc[-1] & 0x80) == 0) {
            in_stack_fffff714 = (CFastStringInt *)(local_8bc + -2);
          }
          else {
            in_stack_fffff714 = (CFastStringInt *)(local_8bc + -4);
          }
          puVar32 = (uint *)0x434f81;
          operator_delete__(in_stack_fffff714);
          local_8c0 = (undefined *)0x0;
          local_8bc = PTR_DAT_00bbf7dc;
        }
        break;
      }
      if (local_8bc != PTR_DAT_00bbf7dc) {
        in_stack_fffff714 = (CFastStringInt *)(local_8bc + -4);
        if ((local_8bc[-1] & 0x80) == 0) {
          in_stack_fffff714 = (CFastStringInt *)(local_8bc + -2);
        }
        puVar32 = (uint *)0x434f3c;
        operator_delete__(in_stack_fffff714);
        local_8c0 = (undefined *)0x0;
        local_8bc = PTR_DAT_00bbf7dc;
      }
      cVar15 = (char)local_8b0 + '\x01';
      local_8b0 = CONCAT31(local_8b0._1_3_,cVar15);
    } while (cVar15 != 'Z');
    while (DAT_00d54298 < 0x15) {
      CFastString::Concat((CFastString *)&DAT_00d54298,(CFastStringInt *)&DAT_00000030,
                          (SStringParam *)puVar32);
    }
  }
  if (DAT_00d54298 != 0x15) {
    CFastStringBase<char>::AllocAtLeast
              ((CFastStringBase<char> *)&DAT_00d54298,(CFastStringBase<wchar_t> *)0x15,1,0,
               (SOldChars *)in_stack_fffff714);
    DAT_00d5429c[0x15] = 0;
    DAT_00d54298 = 0x15;
  }
  ExceptionList = pvStack0000001c;
  return;
}
}

// =================================================
// Function: CSystemEngine::DetachBuffer
// =================================================
CClassicBuffer * __thiscall
CSystemEngine::DetachBuffer(CSystemEngine *this,CClassicArchive *param_1,int param_2)
{
{
  void *this_00;
  CMwNod *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CClassicBuffer *pCVar4;
  CSystemFid *unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CClassicBuffer *in_stack_0000000c;
  
  this_00 = (void *)(*(int *)(this + 0x4c) + 0x1c);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CClassicBuffer *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    while( true ) {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar5,unaff_ESI);
      pCVar1 = *(CMwNod **)pSVar3;
      if (*(CClassicBuffer **)(pCVar1 + 0x74) == in_stack_0000000c) break;
      pCVar5 = pCVar5 + 1;
      if (pCVar2 <= pCVar5) {
        return in_stack_0000000c;
      }
    }
    CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt
              (this_00,(CFastBufferRef<class_CGameMobil> *)pCVar5,1,unaff_EBP);
    *(undefined4 *)(pCVar1 + 0x14) = 0;
    if (*(CSystemEngine **)(pCVar1 + 0x20) != (CSystemEngine *)0x0) {
      UnbindFidNod((CSystemEngine *)param_2,*(CSystemEngine **)(pCVar1 + 0x20),pCVar1,unaff_EBX);
    }
    pCVar4 = (CClassicBuffer *)(**(code **)(*(int *)pCVar1 + 4))(1);
  }
  return pCVar4;
}
}

// =================================================
// Function: CSystemEngine::FileIniRead
// =================================================
void __cdecl
CSystemEngine::FileIniRead(CFastString *param_1,CFastString *param_2,CFastString *param_3)
{
{
  CFastStringBase<wchar_t> *pCVar1;
  CFastStringBase<wchar_t> *pCVar2;
  SOldChars *unaff_ESI;
  SOldChars *unaff_EDI;
  int in_stack_00000010;
  undefined4 uStack_4;
  
  if (*(int *)param_2 != 0x80) {
    CFastStringBase<char>::AllocAtLeast
              ((CFastStringBase<char> *)param_2,(CFastStringBase<wchar_t> *)&DAT_00000080,1,0,
               unaff_EDI);
    *(undefined1 *)(*(int *)(param_2 + 4) + 0x80) = 0;
    *(undefined4 *)param_2 = 0x80;
  }
  param_3 = (CFastString *)0x0;
  do {
    pCVar2 = (CFastStringBase<wchar_t> *)
             GetPrivateProfileStringA
                       (DAT_00d5435c,*(LPCSTR *)(param_2 + 4),*(LPCSTR *)(in_stack_00000010 + 4),
                        *(LPSTR *)(param_2 + 4),*(DWORD *)param_2,DAT_00d54354);
    pCVar1 = *(CFastStringBase<wchar_t> **)param_2;
    if (pCVar2 + 1 < pCVar1) {
      if (pCVar2 == pCVar1) {
        return;
      }
      CFastStringBase<char>::AllocAtLeast((CFastStringBase<char> *)param_2,pCVar2,1,0,unaff_ESI);
      pCVar2[*(int *)(param_2 + 4)] = (CFastStringBase<wchar_t>)0x0;
      *(CFastStringBase<wchar_t> **)param_2 = pCVar2;
      return;
    }
    pCVar2 = (CFastStringBase<wchar_t> *)((int)pCVar1 * 2);
    if (pCVar2 != pCVar1) {
      CFastStringBase<char>::AllocAtLeast((CFastStringBase<char> *)param_2,pCVar2,1,0,unaff_ESI);
      pCVar2[*(int *)(param_2 + 4)] = (CFastStringBase<wchar_t>)0x0;
      *(CFastStringBase<wchar_t> **)param_2 = pCVar2;
    }
    param_3 = param_3 + 1;
  } while (param_3 < (CFastString *)&DAT_00000005);
  uStack_4 = *(undefined4 *)(in_stack_00000010 + 4);
  CFastString::SetString(param_2,(CFastStringInt *)&uStack_4,(SStringParam *)unaff_ESI);
  return;
}
}

// =================================================
// Function: CSystemEngine::FileIniSetFullName
// =================================================
int __cdecl CSystemEngine::FileIniSetFullName(CFastStringInt *param_1)
{
{
  int iVar1;
  
  CSystemFileName::ConvertToSystemName(param_1,(CFastString *)&DAT_00d54350,1,2);
  iVar1 = CSystemManagerFile::IsFileExists(param_1);
  return iVar1;
}
}

// =================================================
// Function: CSystemEngine::FileIniSetSection
// =================================================
void __cdecl CSystemEngine::FileIniSetSection(CFastString *param_1)
{
{
  CFastString::SetString
            ((CFastString *)&DAT_00d54358,(CFastStringInt *)&stack0xfffffff8,
             *(SStringParam **)(param_1 + 4));
  return;
}
}

// =================================================
// Function: CSystemEngine::FindDriveAndRelName
// =================================================
int __thiscall
CSystemEngine::FindDriveAndRelName
          (CSystemEngine *this,CSystemEngine *param_1,CFastStringInt *param_2,
          CSystemFidsDrive **param_3,CFastStringInt *param_4)
{
{
  char cVar1;
  int *piVar2;
  bool bVar3;
  SStringParam *pSVar4;
  char *pcVar5;
  int iVar6;
  undefined *puVar7;
  uint uVar8;
  CSystemEngine *local_30;
  undefined4 local_28;
  undefined *local_24;
  char *local_20;
  int local_1c;
  void *local_14;
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0xffffffff;
  local_10 = &LAB_00a81328;
  local_14 = ExceptionList;
  pSVar4 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffc0);
  ExceptionList = &local_14;
  if ((*(int *)param_1 == 0) || (bVar3 = true, **(short **)(param_1 + 4) != 0x3a)) {
    bVar3 = false;
  }
  local_30 = this + 0x24;
  uVar8 = 0;
  puVar7 = PTR_DAT_00bbf7dc;
  do {
    piVar2 = *(int **)local_30;
    if (piVar2 != (int *)0x0) {
      local_28 = 0;
      local_c = 0;
      local_24 = puVar7;
      if (bVar3) {
        local_20 = *(char **)((int)&PTR_s__resource___00ccb5f8 + uVar8);
        if (local_20 == (char *)0x0) {
          local_1c = 0;
          CFastStringInt::SetString(&local_28,(CFastStringInt *)&local_20,pSVar4);
        }
        else {
          pcVar5 = local_20;
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          local_1c = (int)pcVar5 - (int)(local_20 + 1);
          CFastStringInt::SetString(&local_28,(CFastStringInt *)&local_20,pSVar4);
        }
      }
      else {
        (**(code **)(*piVar2 + 0x98))(&local_28,0);
      }
      pSVar4 = (SStringParam *)param_3;
      iVar6 = CSystemFileName::GetRelativeName
                        ((CFastStringInt *)param_1,(CFastStringInt *)&local_24,
                         (CFastStringInt *)param_3);
      if (iVar6 != 0) {
        *(int **)param_2 = piVar2;
        if (local_20 != PTR_DAT_00bbf7dc) {
          if ((local_20[-1] & 0x80U) != 0) {
            operator_delete__(local_20 + -4);
            ExceptionList = local_10;
            return 1;
          }
          operator_delete__(local_20 + -2);
        }
        ExceptionList = local_10;
        return 1;
      }
      local_8 = 0xffffffff;
      puVar7 = PTR_DAT_00bbf7dc;
      if (local_20 != PTR_DAT_00bbf7dc) {
        if ((local_20[-1] & 0x80U) == 0) {
          pSVar4 = (SStringParam *)(local_20 + -2);
        }
        else {
          pSVar4 = (SStringParam *)(local_20 + -4);
        }
        operator_delete__(pSVar4);
        local_24 = (undefined *)0x0;
        local_20 = PTR_DAT_00bbf7dc;
        puVar7 = PTR_DAT_00bbf7dc;
      }
    }
    local_30 = local_30 + 4;
    uVar8 = uVar8 + 4;
    if (0x13 < uVar8) {
      *(undefined4 *)param_2 = 0;
      local_20 = "";
      local_1c = 0;
      CFastStringInt::SetString(param_3,(CFastStringInt *)&local_20,pSVar4);
      ExceptionList = local_10;
      return 0;
    }
  } while( true );
}
}

// =================================================
// Function: CSystemEngine::FindFid
// =================================================
CSystemFid * __thiscall
CSystemEngine::FindFid
          (CSystemEngine *this,CSystemFids *param_1,CFastStringInt *param_2,int param_3,
          EFindWay param_4)
{
{
  void *this_00;
  CSystemFid *pCVar1;
  CSystemFidFile *pCVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  int iVar5;
  CSystemFidFile *unaff_EBX;
  CSystemFids *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  if ((*(uint *)(param_1 + 0x18) & 1) == 0) {
    this_00 = (void *)(*(int *)(param_1 + 0x14) + 0x1c);
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar6,(ulong)unaff_ESI);
        unaff_ESI = param_1;
        iVar5 = (**(code **)(**(int **)pSVar4 + 0x78))();
        if (iVar5 != 0) {
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar6,(ulong)unaff_ESI);
          return *(CSystemFid **)pSVar4;
        }
        pCVar6 = pCVar6 + 1;
      } while (pCVar6 < pCVar3);
    }
    return (CSystemFid *)0x0;
  }
  if ((*(uint *)(param_1 + 0x18) & 4) == 0) {
    pCVar2 = FindFidFile(this,(CSystemEngine *)param_1,unaff_EBX);
    return (CSystemFid *)pCVar2;
  }
  pCVar1 = FindFidResource(this,(CSystemEngine *)param_1,unaff_EBX);
  return pCVar1;
}
}

// =================================================
// Function: CSystemEngine::FindFidFile
// =================================================
CSystemFidFile * __thiscall
CSystemEngine::FindFidFile(CSystemEngine *this,CSystemEngine *param_1,CSystemFidFile *param_2)
{
{
  void *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  CSystemEngine *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    return (CSystemFidFile *)0x0;
  }
  this_00 = (void *)(*(int *)(param_1 + 0x14) + 0x1c);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar4,(ulong)unaff_ESI);
      unaff_ESI = param_1;
      iVar3 = (**(code **)(**(int **)pSVar2 + 0x78))();
      if (iVar3 != 0) {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar4,(ulong)unaff_ESI);
        return *(CSystemFidFile **)pSVar2;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return (CSystemFidFile *)0x0;
}
}

// =================================================
// Function: CSystemEngine::FindFidFromBaseNameAndClassId
// =================================================
CSystemFid * __thiscall
CSystemEngine::FindFidFromBaseNameAndClassId
          (CSystemEngine *this,CSystemFids *param_1,CFastStringInt *param_2,ulong param_3)
{
{
  int iVar1;
  CSystemFid *pCVar2;
  ulong unaff_ESI;
  CFastStringInt *in_stack_00000010;
  CSystemFidsDrive *local_14;
  undefined *local_10;
  undefined *local_c;
  undefined1 *local_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  local_8 = &LAB_00a813b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 != (CSystemFids *)0x0) {
    pCVar2 = CSystemFids::FindFidFromBaseNameAndClassId
                       (param_1,(CSystemFids *)param_2,(CFastStringInt *)param_3,
                        (ulong)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
    ExceptionList = local_8;
    return pCVar2;
  }
  local_14 = (CSystemFidsDrive *)0x0;
  local_10 = PTR_DAT_00bbf7dc;
  local_4 = (void *)0x0;
  iVar1 = FindDriveAndRelName(this,(CSystemEngine *)param_2,(CFastStringInt *)&param_2,&local_14,
                              (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  if (iVar1 != 0) {
    pCVar2 = CSystemFids::FindFidFromBaseNameAndClassId
                       ((CSystemFids *)param_3,(CSystemFids *)&local_10,in_stack_00000010,unaff_ESI)
    ;
    if (local_8 != PTR_DAT_00bbf7dc) {
      if ((local_8[-1] & 0x80) != 0) {
        operator_delete__(local_8 + -4);
        ExceptionList = local_4;
        return pCVar2;
      }
      operator_delete__(local_8 + -2);
    }
    ExceptionList = local_4;
    return pCVar2;
  }
  if (local_c != PTR_DAT_00bbf7dc) {
    if ((local_c[-1] & 0x80) != 0) {
      operator_delete__(local_c + -4);
      ExceptionList = local_8;
      return (CSystemFid *)0x0;
    }
    operator_delete__(local_c + -2);
  }
  ExceptionList = local_8;
  return (CSystemFid *)0x0;
}
}

// =================================================
// Function: CSystemEngine::FindFidResource
// =================================================
CSystemFid * __thiscall
CSystemEngine::FindFidResource(CSystemEngine *this,CSystemEngine *param_1,CSystemFidFile *param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x44,
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(param_1 + 0x7c),
                      unaff_retaddr);
  return *(CSystemFid **)pSVar1;
}
}

// =================================================
// Function: CSystemEngine::FindOrAddFidAt
// =================================================
CSystemFidFile * __thiscall
CSystemEngine::FindOrAddFidAt
          (CSystemEngine *this,CSystemEngine *param_1,CSystemFids *param_2,CFastStringInt *param_3,
          int *param_4)
{
{
  CFastStringInt *pCVar1;
  CSystemFidFile *this_00;
  int iVar2;
  CSystemFids *pCVar3;
  CSystemEngine *pCVar4;
  CSystemFidFile *pCVar5;
  CSystemEngine *unaff_EBX;
  CFastStringInt *unaff_ESI;
  CFastStringInt *unaff_EDI;
  undefined4 in_stack_00000014;
  uint *in_stack_00000024;
  int in_stack_ffffffec;
  CSystemFidFile *in_stack_fffffff0;
  undefined *puVar6;
  
  puVar6 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  this_00 = CSystemManagerFile::CreateFidFile
                      (*(CSystemManagerFile **)(this + 0x20),
                       (CSystemManagerFile *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  pCVar1 = param_3;
  if (param_2 == (CSystemFids *)0x0) {
    in_stack_fffffff0 = (CSystemFidFile *)0x0;
    puVar6 = PTR_DAT_00bbf7dc;
    iVar2 = FindDriveAndRelName(this,(CSystemEngine *)param_3,(CFastStringInt *)&param_3,
                                (CSystemFidsDrive **)&stack0xfffffff0,unaff_EDI);
    if (iVar2 == 0) {
      CSystemFidFile::SetFileName(this_00,(CSystemFidFile *)pCVar1,unaff_ESI);
      pCVar3 = GetLocationData(this,unaff_EBX);
      *(CSystemFids **)(this_00 + 0x14) = pCVar3;
      CSystemFid::MergeLocation((CSystemFid *)this_00,(CSystemFid *)0x0,in_stack_ffffffec);
    }
    else {
      CSystemFidFile::SetFileName(this_00,(CSystemFidFile *)&stack0xfffffff4,unaff_ESI);
      *(undefined4 *)(this_00 + 0x14) = in_stack_00000014;
      CSystemFid::ConcatLocation((CSystemFid *)this_00,(CSystemFid *)0x0,(int)unaff_EBX);
    }
    param_4 = (int *)0xffffffff;
    if (param_1 != (CSystemEngine *)PTR_DAT_00bbf7dc) {
      if (((byte)param_1[-1] & 0x80) == 0) {
        pCVar4 = param_1 + -2;
      }
      else {
        pCVar4 = param_1 + -4;
      }
      operator_delete__(pCVar4);
    }
  }
  else {
    CSystemFidFile::SetFileName(this_00,(CSystemFidFile *)param_3,unaff_EDI);
    *(CSystemFids **)(this_00 + 0x14) = param_2;
    CSystemFid::ConcatLocation((CSystemFid *)this_00,(CSystemFid *)0x0,(int)unaff_ESI);
  }
  pCVar5 = FindFidFile(this,(CSystemEngine *)this_00,in_stack_fffffff0);
  if (in_stack_00000024 != (uint *)0x0) {
    *in_stack_00000024 = (uint)(pCVar5 == (CSystemFidFile *)0x0);
  }
  if (pCVar5 != (CSystemFidFile *)0x0) {
    (**(code **)(*(int *)this_00 + 4))();
    ExceptionList = param_2;
    return pCVar5;
  }
  CSystemFid::ConcatLocation((CSystemFid *)this_00,(CSystemFid *)0x1,(int)puVar6);
  *(uint *)(this_00 + 0x1c) = *(uint *)(this_00 + 0x1c) & 0xfffff7ff;
  ExceptionList = param_4;
  return this_00;
}
}

// =================================================
// Function: CSystemEngine::GetConfigFile
// =================================================
CSystemFidFile * __thiscall
CSystemEngine::GetConfigFile
          (CSystemEngine *this,CSystemEngine *param_1,CFastStringInt *param_2,EMode param_3,
          int param_4)
{
{
  CSystemEngine *pCVar1;
  CSystemFids *pCVar2;
  CSystemFids *extraout_EAX;
  undefined1 *puVar3;
  CSystemFid *pCVar4;
  CSystemEngine *unaff_EBX;
  int unaff_ESI;
  SStringParam *unaff_EDI;
  int in_stack_00000014;
  int in_stack_00000018;
  EFindWay in_stack_ffffffe4;
  undefined1 local_18 [8];
  char *local_10;
  undefined1 *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  pCVar1 = param_1;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a81508;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_3 == 0) {
    pCVar2 = GetLocationUser(this,(CSystemEngine *)(DAT_00cca150 ^ (uint)&stack0xffffffd8));
    if (pCVar2 == (CSystemFids *)0x0) goto LAB_0041e1a4;
    local_10 = "Config\\";
    local_c = &DAT_00000007;
    CFastStringInt::CFastStringInt(local_18,(CFastStringInt *)&local_10,unaff_EDI);
    param_1 = (CSystemEngine *)0x0;
    pCVar2 = CSystemFids::FindOrAddLocationDown
                       (pCVar2,extraout_EAX,(CFastStringInt *)0x0,(ulong *)0x0,unaff_ESI);
    param_2 = (CFastStringInt *)0xffffffff;
    if (local_c != PTR_DAT_00bbf7dc) {
      if ((local_c[-1] & 0x80) == 0) {
        puVar3 = local_c + -2;
      }
      else {
        puVar3 = local_c + -4;
      }
      operator_delete__(puVar3);
      local_10 = (char *)0x0;
      local_c = PTR_DAT_00bbf7dc;
    }
  }
  else {
    pCVar2 = GetLocationShared(this,(CSystemEngine *)(DAT_00cca150 ^ (uint)&stack0xffffffd8));
  }
  if (pCVar2 != (CSystemFids *)0x0) {
    if (in_stack_00000014 == 2) {
      pCVar4 = CSystemFids::FindOrAddFid
                         (pCVar2,(CSystemFids *)pCVar1,(CFastStringInt *)0x0,(ulong *)0x0,
                          (int)unaff_EBX);
    }
    else {
      pCVar4 = CSystemFids::FindFid
                         (pCVar2,(CSystemFids *)pCVar1,(CFastStringInt *)0x1,0,(EFindWay)unaff_EBX);
    }
    if (pCVar4 != (CSystemFid *)0x0) {
      ExceptionList = param_2;
      return (CSystemFidFile *)pCVar4;
    }
  }
LAB_0041e1a4:
  pCVar2 = GetLocationData(this,unaff_EBX);
  if (pCVar2 == (CSystemFids *)0x0) {
    ExceptionList = param_1;
    return (CSystemFidFile *)0x0;
  }
  if (in_stack_00000018 != 2) {
    pCVar4 = CSystemFids::FindFid
                       (pCVar2,(CSystemFids *)pCVar1,(CFastStringInt *)0x1,0,in_stack_ffffffe4);
    ExceptionList = param_2;
    return (CSystemFidFile *)pCVar4;
  }
  pCVar4 = CSystemFids::FindOrAddFid
                     (pCVar2,(CSystemFids *)pCVar1,(CFastStringInt *)0x0,(ulong *)0x0,
                      in_stack_ffffffe4);
  ExceptionList = param_2;
  return (CSystemFidFile *)pCVar4;
}
}

// =================================================
// Function: CSystemEngine::GetCpuExtHardware
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00431e44) */
/* WARNING: Removing unreachable block (ram,0x00431e26) */

ECpuExt __cdecl CSystemEngine::GetCpuExtHardware(void)
{
{
  int iVar1;
  ECpuExt EVar2;
  uint uVar3;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_00cca150 ^ 0xc68e48;
  ExceptionList = &local_14;
  cpuid_basic_info(0);
  local_8 = 0xfffffffe;
  iVar1 = cpuid_Version_info(1);
  uVar3 = *(uint *)(iVar1 + 8);
  if (((uVar3 & 0x2000000) == 0) || (iVar1 = CpuExtCheckOsSupport(1), iVar1 == 0)) {
    EVar2 = 0;
  }
  else if ((uVar3 & 0x4000000) == 0) {
    EVar2 = 1;
  }
  else {
    iVar1 = CpuExtCheckOsSupport(2);
    EVar2 = (iVar1 != 0) + 1;
  }
  ExceptionList = local_14;
  return EVar2;
}
}

// =================================================
// Function: CSystemEngine::GetCurrentDir
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl CSystemEngine::GetCurrentDir(CFastStringInt *param_1)
{
{
  WCHAR WVar1;
  WCHAR *pWVar2;
  void *this;
  SStringParam *unaff_ESI;
  WCHAR *local_218;
  int local_214;
  undefined4 local_210;
  WCHAR local_20c;
  undefined1 local_20a [518];
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)&local_218;
  GetCurrentDirectoryW(0x103,&local_20c);
  local_218 = &local_20c;
  pWVar2 = local_218;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  local_214 = (int)pWVar2 - (int)local_20a >> 1;
  local_210 = 1;
  CFastStringInt::SetString(param_1,(CFastStringInt *)&local_218,unaff_ESI);
  CSystemFileName::Normalize(this,(GmQuat *)param_1);
  return;
}
}

// =================================================
// Function: CSystemEngine::GetExeCheckSum
// =================================================
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

ulong __cdecl CSystemEngine::GetExeCheckSum(void)
{
{
  long lVar1;
  ulong uVar2;
  CClassicLog *pCVar3;
  CSystemFile *pCVar4;
  undefined *puVar5;
  undefined *local_1038;
  CSystemFile local_1034 [4124];
  void *local_18;
  undefined1 local_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00a812a6;
  local_c = ExceptionList;
  uStack_10 = 0x41c3f8;
  ExceptionList = &local_c;
  uVar2 = DAT_00d5423c;
  if (DAT_00d5423c == 0) {
    local_1038 = PTR_DAT_00bbf7dc;
    local_4 = 0;
    CSystemFile::CSystemFile(local_1034,(CSystemFile *)(DAT_00cca150 ^ (uint)&stack0xffffefc0));
    CSystemManagerFile::GetExeFullName((CFastStringInt *)&local_1038);
    puVar5 = (undefined *)0x0;
    pCVar4 = (CSystemFile *)0x1;
    pCVar3 = (CClassicLog *)&local_1038;
    lVar1 = CSystemFile::Open((_D3DXINCLUDE_TYPE)pCVar3,(char *)0x1,(void *)0x0,(void **)0x1,
                              (uint *)0x0);
    if (lVar1 == 0) {
      DAT_00d5423c = 0xffffffff;
    }
    else {
      DAT_00d5423c = CFastAlgo::ComputeCrc32((CClassicBuffer *)&stack0xffffefb8,0xffffffff);
      CSystemFile::Close((CSystemFile *)&stack0xffffefb8,pCVar3);
    }
    uVar2 = DAT_00d5423c;
    local_14 = 0;
    CSystemFile::~CSystemFile((CSystemFile *)&stack0xffffefbc,pCVar4);
    if (puVar5 != PTR_DAT_00bbf7dc) {
      if ((puVar5[-1] & 0x80) == 0) {
        puVar5 = puVar5 + -2;
      }
      else {
        puVar5 = puVar5 + -4;
      }
      operator_delete__(puVar5);
    }
  }
  ExceptionList = local_18;
  return uVar2;
}
}

// =================================================
// Function: CSystemEngine::GetExeDir
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl CSystemEngine::GetExeDir(CFastStringInt *param_1)
{
{
  WCHAR WVar1;
  SStringParam *pSVar2;
  WCHAR *pWVar3;
  undefined *puVar4;
  void *extraout_ECX;
  void *extraout_ECX_00;
  void *this;
  SStringParam *unaff_ESI;
  void *unaff_retaddr;
  undefined1 auStack_22c [4];
  undefined1 local_228 [4];
  WCHAR *local_224;
  undefined *local_220;
  undefined4 local_21c;
  WCHAR local_218;
  undefined1 local_216 [2];
  CFastStringInt local_214 [516];
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a8306b;
  local_c = ExceptionList;
  local_10 = DAT_00cca150 ^ (uint)auStack_22c;
  pSVar2 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xfffffdd0);
  ExceptionList = &local_c;
  GetModuleFileNameW((HMODULE)0x0,&local_218,0x103);
  local_224 = &local_218;
  pWVar3 = local_224;
  do {
    WVar1 = *pWVar3;
    pWVar3 = pWVar3 + 1;
  } while (WVar1 != L'\0');
  local_220 = (undefined *)((int)pWVar3 - (int)local_216 >> 1);
  local_21c = 1;
  CFastStringInt::SetString(param_1,(CFastStringInt *)&local_224,pSVar2);
  CFastStringInt::CFastStringInt(local_228,local_214,unaff_ESI);
  CSystemFileName::ExtractFullPathName((CFastStringInt *)&local_224,param_1);
  this = extraout_ECX;
  if (local_220 != PTR_DAT_00bbf7dc) {
    if ((local_220[-1] & 0x80) == 0) {
      puVar4 = local_220 + -2;
    }
    else {
      puVar4 = local_220 + -4;
    }
    operator_delete__(puVar4);
    local_224 = (WCHAR *)0x0;
    local_220 = PTR_DAT_00bbf7dc;
    this = extraout_ECX_00;
  }
  CSystemFileName::Normalize(this,(GmQuat *)param_1);
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CSystemEngine::GetFidFromResource
// =================================================
CSystemFidFile * __thiscall
CSystemEngine::GetFidFromResource(CSystemEngine *this,CSystemEngine *param_1,ulong param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x44,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((uint)param_1 ^ 0x40000000)
                      ,unaff_retaddr);
  return *(CSystemFidFile **)pSVar1;
}
}

// =================================================
// Function: CSystemEngine::GetLocationBuffer
// =================================================
CSystemFids * __thiscall
CSystemEngine::GetLocationBuffer(CSystemEngine *this,CSystemEngine *param_1)
{
{
  return *(CSystemFids **)(this + 0x4c);
}
}

// =================================================
// Function: CSystemEngine::GetLocationData
// =================================================
CSystemFids * __thiscall CSystemEngine::GetLocationData(CSystemEngine *this,CSystemEngine *param_1)
{
{
  return *(CSystemFids **)(this + 0x50);
}
}

// =================================================
// Function: CSystemEngine::GetLocationShared
// =================================================
CSystemFids * __thiscall
CSystemEngine::GetLocationShared(CSystemEngine *this,CSystemEngine *param_1)
{
{
  CSystemFids *pCVar1;
  
  pCVar1 = *(CSystemFids **)(this + 0x30);
  if ((pCVar1 == (CSystemFids *)0x0) &&
     (pCVar1 = *(CSystemFids **)(this + 0x28), pCVar1 == (CSystemFids *)0x0)) {
    pCVar1 = *(CSystemFids **)(this + 0x50);
  }
  return pCVar1;
}
}

// =================================================
// Function: CSystemEngine::GetLocationUser
// =================================================
CSystemFids * __thiscall CSystemEngine::GetLocationUser(CSystemEngine *this,CSystemEngine *param_1)
{
{
  CSystemFids *pCVar1;
  
  pCVar1 = *(CSystemFids **)(this + 0x28);
  if (pCVar1 == (CSystemFids *)0x0) {
    pCVar1 = *(CSystemFids **)(this + 0x50);
  }
  return pCVar1;
}
}

// =================================================
// Function: CSystemEngine::GetLogRootPath
// =================================================
/* WARNING: Removing unreachable block (ram,0x0041ec2f) */

void __cdecl
CSystemEngine::GetLogRootPath
          (CFastString *param_1,CFastStringInt *param_2,CFastStringInt *param_3,
          CFastStringInt *param_4)
{
{
  undefined *puVar1;
  CFastStringInt *unaff_ESI;
  CFastStringInt *unaff_EDI;
  undefined *local_38;
  undefined *local_34;
  undefined *local_30;
  undefined *local_2c;
  undefined *local_28;
  undefined *local_24;
  undefined *local_20;
  undefined4 local_1c;
  undefined *local_14;
  undefined *local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a81660;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_20 = DAT_00d71d58;
  local_24 = (undefined *)DAT_00d71d5c;
  local_1c = 0;
  CFastStringInt::SetString
            (param_4,(CFastStringInt *)&local_24,
             (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffac));
  local_28 = (undefined *)0x0;
  local_24 = PTR_DAT_00bbf7dc;
  local_38 = (undefined *)0x0;
  local_34 = PTR_DAT_00bbf7dc;
  local_30 = (undefined *)0x0;
  local_2c = PTR_DAT_00bbf7dc;
  InternalComputePaths
            ((CFastString *)param_2,param_3,param_4,(CFastStringInt *)&local_38,
             (CFastStringInt *)&local_30,unaff_EDI,unaff_ESI);
  local_c = (void *)0x0;
  local_10 = local_38;
  local_14 = local_34;
  CFastStringInt::SetString(param_4,(CFastStringInt *)&local_14,(SStringParam *)unaff_EDI);
  if (local_28 != PTR_DAT_00bbf7dc) {
    puVar1 = local_28 + -4;
    if ((local_28[-1] & 0x80) == 0) {
      puVar1 = local_28 + -2;
    }
    operator_delete__(puVar1);
    local_2c = (undefined *)0x0;
    local_28 = PTR_DAT_00bbf7dc;
  }
  if (local_38 != PTR_DAT_00bbf7dc) {
    puVar1 = local_38 + -4;
    if ((local_38[-1] & 0x80) == 0) {
      puVar1 = local_38 + -2;
    }
    operator_delete__(puVar1);
    local_38 = PTR_DAT_00bbf7dc;
  }
  if (local_30 != PTR_DAT_00bbf7dc) {
    puVar1 = local_30 + -4;
    if ((local_30[-1] & 0x80) == 0) {
      puVar1 = local_30 + -2;
    }
    operator_delete__(puVar1);
    local_34 = (undefined *)0x0;
    local_30 = PTR_DAT_00bbf7dc;
  }
  if (local_20 != PTR_DAT_00bbf7dc) {
    puVar1 = local_20 + -4;
    if ((local_20[-1] & 0x80) == 0) {
      puVar1 = local_20 + -2;
    }
    operator_delete__(puVar1);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CSystemEngine::GetMyDocumentsDir
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl CSystemEngine::GetMyDocumentsDir(CFastStringInt *param_1)
{
{
  short sVar1;
  int iVar2;
  short *psVar3;
  void *extraout_ECX;
  void *extraout_ECX_00;
  void *this;
  SStringParam *pSVar4;
  short *psStack_22c;
  int iStack_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined1 auStack_218 [12];
  undefined1 local_20c [520];
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)auStack_218;
  uStack_220 = local_20c;
  uStack_224 = 0;
  iStack_228 = 0;
  psStack_22c = (short *)0x8005;
  pSVar4 = (SStringParam *)0x0;
  iVar2 = SHGetFolderPathW();
  if (-1 < iVar2) {
    psVar3 = (short *)&uStack_220;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    if (1 < (uint)((int)psVar3 - ((int)&uStack_220 + 2) >> 1)) {
      psStack_22c = (short *)&uStack_220;
      psVar3 = psStack_22c;
      do {
        sVar1 = *psVar3;
        psVar3 = psVar3 + 1;
      } while (sVar1 != 0);
      iStack_228 = (int)psVar3 - ((int)&uStack_220 + 2) >> 1;
      uStack_224 = 1;
      CFastStringInt::SetString(param_1,(CFastStringInt *)&psStack_22c,pSVar4);
      this = extraout_ECX;
      goto LAB_00432dd3;
    }
  }
  GetRunDir(param_1);
  this = extraout_ECX_00;
LAB_00432dd3:
  CSystemFileName::Normalize(this,(GmQuat *)param_1);
  return;
}
}

// =================================================
// Function: CSystemEngine::GetResourceFromId
// =================================================
CMwNod * __thiscall
CSystemEngine::GetResourceFromId(CSystemEngine *this,CSystemEngine *param_1,ulong param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x44,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((uint)param_1 ^ 0x40000000)
                      ,unaff_retaddr);
  return *(CMwNod **)(*(int *)pSVar1 + 0x20);
}
}

// =================================================
// Function: CSystemEngine::GetRunDir
// =================================================
void __cdecl CSystemEngine::GetRunDir(CFastStringInt *param_1)
{
{
  if (DAT_00ccb5f4 != 0) {
    GetCurrentDir(param_1);
    return;
  }
  GetExeDir(param_1);
  return;
}
}

// =================================================
// Function: CSystemEngine::GetSharedAppDir
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl CSystemEngine::GetSharedAppDir(CFastStringInt *param_1)
{
{
  short sVar1;
  int iVar2;
  short *psVar3;
  void *extraout_ECX;
  void *extraout_ECX_00;
  void *this;
  SStringParam *pSVar4;
  short *psStack_22c;
  int iStack_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined1 auStack_218 [12];
  undefined1 local_20c [520];
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)auStack_218;
  uStack_220 = local_20c;
  uStack_224 = 0;
  iStack_228 = 0;
  psStack_22c = (short *)0x8023;
  pSVar4 = (SStringParam *)0x0;
  iVar2 = SHGetFolderPathW();
  if (-1 < iVar2) {
    psVar3 = (short *)&uStack_220;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    if (1 < (uint)((int)psVar3 - ((int)&uStack_220 + 2) >> 1)) {
      psStack_22c = (short *)&uStack_220;
      psVar3 = psStack_22c;
      do {
        sVar1 = *psVar3;
        psVar3 = psVar3 + 1;
      } while (sVar1 != 0);
      iStack_228 = (int)psVar3 - ((int)&uStack_220 + 2) >> 1;
      uStack_224 = 1;
      CFastStringInt::SetString(param_1,(CFastStringInt *)&psStack_22c,pSVar4);
      this = extraout_ECX;
      goto LAB_00432e93;
    }
  }
  GetRunDir(param_1);
  this = extraout_ECX_00;
LAB_00432e93:
  CSystemFileName::Normalize(this,(GmQuat *)param_1);
  return;
}
}

// =================================================
// Function: CSystemEngine::I18nGetSystemLanguage
// =================================================
char * __thiscall CSystemEngine::I18nGetSystemLanguage(CSystemEngine *this,CSystemEngine *param_1)
{
{
  LANGID LVar1;
  
  LVar1 = GetSystemDefaultLangID();
  switch(LVar1 & 0x3ff) {
  case 4:
    return "zh";
  case 5:
    return "cz";
  default:
    return "en";
  case 7:
    return "de";
  case 10:
    return "es";
  case 0xc:
    return "fr";
  case 0xe:
    return "hu";
  case 0x10:
    return "it";
  case 0x11:
    return "jp";
  case 0x12:
    return "ko";
  case 0x15:
    return "pl";
  case 0x19:
    return "ru";
  case 0x1e:
    return "th";
  case 0x39:
    return "hi";
  }
}
}

// =================================================
// Function: CSystemEngine::I18nLoadMessageCatalog
// =================================================
int __thiscall
CSystemEngine::I18nLoadMessageCatalog
          (CSystemEngine *this,CSystemEngine *param_1,CSystemFid *param_2,char *param_3)
{
{
  CFastString *pCVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uStack_14;
  undefined *puStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a814d8;
  local_c = ExceptionList;
  pCVar1 = (CFastString *)(DAT_00cca150 ^ (uint)&stack0xffffffe0);
  ExceptionList = &local_c;
  if (param_1 != (CSystemEngine *)0x0) {
    iVar2 = (**(code **)(*(int *)param_1 + 0x10))(0xb00a000);
    if (iVar2 != 0) {
      pcVar3 = (char *)(**(code **)**(undefined4 **)(param_1 + 0x6c))(param_1,1,0);
      if (pcVar3 != (char *)0x0) {
        uStack_14 = 0;
        puStack_10 = PTR_DAT_00bbf7d8;
        uStack_4 = 0;
        iVar2 = CClassicI18n::LoadMessageCatalog
                          ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)param_2,pcVar3,
                           (CClassicBuffer *)&uStack_14,pCVar1);
        (**(code **)(**(int **)(param_1 + 0x6c) + 4))(param_1,pcVar3);
        CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                  (&stack0xffffffe8,(SHeaderCommunity *)param_1);
        ExceptionList = local_c;
        return iVar2;
      }
    }
  }
  ExceptionList = local_c;
  return 0;
}
}

// =================================================
// Function: CSystemEngine::I18nSetLanguage
// =================================================
int __thiscall
CSystemEngine::I18nSetLanguage(CSystemEngine *this,CSystemEngine *param_1,char *param_2)
{
{
  CSystemEngine *pCVar1;
  CSystemFids *pCVar2;
  CSystemFids *extraout_EAX;
  CSystemFids *this_00;
  CSystemFids *extraout_EAX_00;
  int iVar3;
  int iVar4;
  EFindWay unaff_EBX;
  SStringParam *unaff_ESI;
  CSystemFid *pCVar5;
  char *unaff_EDI;
  CSystemEngine *pCVar6;
  bool bVar7;
  undefined4 in_stack_0000000c;
  void *in_stack_00000010;
  undefined4 uStack00000014;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  void *in_stack_00000028;
  undefined1 in_stack_0000002c;
  CSystemEngine *in_stack_ffffff74;
  char *pcVar8;
  SStringParam *in_stack_ffffff7c;
  SNationConfig *pSVar9;
  CSystemEngine *pCVar10;
  EFindWay EVar11;
  CSystemFids *in_stack_ffffff84;
  SStringParam *in_stack_ffffff88;
  SStringParamInt *pSVar12;
  CSystemFids *in_stack_ffffff8c;
  EFindWay EVar13;
  EFindWay in_stack_ffffff90;
  SNationConfig *pSVar14;
  CSystemFids *in_stack_ffffff94;
  SStringParam *in_stack_ffffff98;
  SStringParamInt *in_stack_ffffff9c;
  EFindWay in_stack_ffffffa0;
  CFastStringInt local_5c [4];
  CSystemFids *pCStack_58;
  CSystemFids *local_54;
  undefined *puStack_50;
  undefined1 *local_4c;
  CSystemFids *local_48;
  CSystemEngine *local_44;
  CSystemFids local_40 [4];
  undefined4 local_3c;
  char *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 auStack_2c [8];
  undefined1 local_24 [4];
  CFastStringInt local_20 [4];
  undefined1 local_1c [4];
  undefined *local_18;
  CSystemFids *local_14;
  undefined1 *local_10;
  undefined *local_c;
  CSystemFids *local_8;
  
  local_c = (undefined *)0xffffffff;
  local_10 = &LAB_00a8180a;
  local_14 = ExceptionList;
  pCVar1 = (CSystemEngine *)(DAT_00cca150 ^ (uint)&stack0xffffff68);
  ExceptionList = &local_14;
  pcVar8 = (char *)0x0;
  if ((param_1 == (CSystemEngine *)0x0) || (*param_1 == (CSystemEngine)0x0)) {
LAB_0041fb43:
    CClassicI18n::Reset((CClassicI18n *)&DAT_00d71d10,(GmFrustumIso4 *)pCVar1);
    ExceptionList = local_10;
    return 1;
  }
  iVar4 = 3;
  bVar7 = true;
  pCVar10 = param_1;
  pCVar6 = (CSystemEngine *)&DAT_00b2ee64;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pCVar10 == *pCVar6;
    pCVar10 = pCVar10 + 1;
    pCVar6 = pCVar6 + 1;
  } while (bVar7);
  if (bVar7) goto LAB_0041fb43;
  iVar4 = __stricmp((char *)param_1,"xx");
  if (iVar4 == 0) goto LAB_0041fb43;
  pCVar10 = this;
  pCVar2 = GetLocationData(this,pCVar1);
  if (pCVar2 == (CSystemFids *)0x0) {
    pCVar10 = (CSystemEngine *)0x0;
  }
  else {
    SStringParam::SStringParam(&stack0xffffffa0,(SStringParam *)"Translations",unaff_EDI);
    CFastStringInt::CFastStringInt(&local_54,local_5c,unaff_ESI);
    in_stack_ffffff84 = (CSystemFids *)0x1;
    in_stack_ffffff8c =
         CSystemFids::FindLocationDown(pCVar2,extraout_EAX,(CFastStringInt *)0x1,0,unaff_EBX);
  }
  param_1 = (CSystemEngine *)0xffffffff;
  if (((uint)in_stack_ffffff88 & 1) != 0) {
    in_stack_ffffff88 = (SStringParam *)((uint)in_stack_ffffff88 & 0xfffffffe);
    CGameCtnApp::SNationConfig::~SNationConfig(&local_4c,(SNationConfig *)in_stack_ffffff74);
  }
  this_00 = GetLocationUser(this,in_stack_ffffff74);
  if ((this_00 == (CSystemFids *)0x0) || (this_00 == pCVar2)) {
    pCVar2 = (CSystemFids *)0x0;
  }
  else {
    SStringParam::SStringParam(local_40,(SStringParam *)"Translations",pcVar8);
    CFastStringInt::CFastStringInt(&local_34,(CFastStringInt *)&local_3c,in_stack_ffffff7c);
    in_stack_ffffff94 = (CSystemFids *)((uint)in_stack_ffffff94 | 2);
    in_stack_00000010 = (void *)0x1;
    pCVar2 = CSystemFids::FindLocationDown
                       (this_00,extraout_EAX_00,(CFastStringInt *)0x1,0,(EFindWay)pCVar10);
  }
  uStack00000014 = 0xffffffff;
  if (((uint)in_stack_ffffff98 & 2) != 0) {
    CGameCtnApp::SNationConfig::~SNationConfig(auStack_2c,(SNationConfig *)in_stack_ffffff84);
  }
  if ((in_stack_ffffff9c == (SStringParamInt *)0x0) && (pCVar2 == (CSystemFids *)0x0))
  goto LAB_0041f75c;
  pCVar5 = (CSystemFid *)0x0;
  pSVar9 = (SNationConfig *)0x41f78f;
  SStringParam::SStringParam(local_24,(SStringParam *)param_1,(char *)in_stack_ffffff84);
  CFastStringInt::CFastStringInt(&puStack_50,local_20,in_stack_ffffff88);
  local_54 = (CSystemFids *)0x0;
  puStack_50 = PTR_DAT_00bbf7dc;
  local_10 = local_4c;
  in_stack_0000001c = 3;
  local_14 = local_48;
  local_c = (undefined *)0x0;
  local_8 = local_48;
  SStringParam::SStringParam(local_1c,(SStringParam *)"%1\\%2.mo",(char *)in_stack_ffffff8c);
  in_stack_ffffff84 = (CSystemFids *)&local_18;
  EVar11 = 0x41f804;
  CFastStringInt::SetCompose
            (&puStack_50,(CFastStringInt *)in_stack_ffffff84,(SStringParam *)&stack0xfffffffc,
             (SStringParamInt *)&local_10);
  if (pCVar2 != (CSystemFids *)0x0) {
    in_stack_ffffff84 = (CSystemFids *)&puStack_50;
    EVar11 = 0x41f817;
    pCVar5 = CSystemFids::FindFid
                       (pCVar2,in_stack_ffffff84,(CFastStringInt *)0x1,0,in_stack_ffffff90);
  }
  if (local_54 == (CSystemFids *)0x0) {
LAB_0041f834:
    if (pCVar5 != (CSystemFid *)0x0) goto LAB_0041f838;
    param_1 = local_44;
    param_2 = (char *)0x0;
    SStringParam::SStringParam(&local_14,(SStringParam *)"%1.mo",(char *)in_stack_ffffff94);
    in_stack_ffffff94 = (CSystemFids *)&param_1;
    CFastStringInt::SetCompose
              (&local_48,(CFastStringInt *)&local_10,(SStringParam *)in_stack_ffffff94,
               (SStringParamInt *)in_stack_ffffff98);
    if (pCVar2 != (CSystemFids *)0x0) {
      in_stack_ffffff98 = (SStringParam *)0x0;
      in_stack_ffffff94 = (CSystemFids *)0x1;
      pCVar5 = CSystemFids::FindFid
                         (pCVar2,(CSystemFids *)&local_44,(CFastStringInt *)0x1,0,
                          (EFindWay)in_stack_ffffff9c);
    }
    if (local_54 != (CSystemFids *)0x0) {
      if (pCVar5 != (CSystemFid *)0x0) goto LAB_0041f838;
      in_stack_ffffff84 = (CSystemFids *)0x41f8f9;
      pCVar5 = CSystemFids::FindFid
                         (local_54,(CSystemFids *)&local_4c,(CFastStringInt *)0x1,0,
                          (EFindWay)in_stack_ffffff94);
    }
    if (pCVar5 != (CSystemFid *)0x0) goto LAB_0041f838;
    pSVar12 = (SStringParamInt *)0x41f911;
    CClassicI18n::GetPrimaryLanguage((char *)param_1,(char *)&pCStack_58);
    EVar13 = 0x41f922;
    SStringParam::SStringParam(&local_14,(SStringParam *)&pCStack_58,(char *)in_stack_ffffff94);
    CFastStringInt::CFastStringInt(&local_38,(CFastStringInt *)&local_10,in_stack_ffffff98);
    param_2 = local_38;
    uStack00000014 = local_30;
    in_stack_0000002c = 4;
    in_stack_0000000c = local_3c;
    in_stack_00000010 = (void *)0x0;
    in_stack_00000018 = local_34;
    in_stack_0000001c = 0;
    SStringParam::SStringParam
              (&stack0xfffffffc,(SStringParam *)"%1\\%2.mo",(char *)in_stack_ffffff9c);
    in_stack_ffffff9c = (SStringParamInt *)&stack0x0000000c;
    in_stack_ffffff98 = (SStringParam *)&stack0x00000018;
    pSVar14 = (SNationConfig *)0x41f98c;
    in_stack_ffffff94 = (CSystemFids *)register0x00000010;
    CFastStringInt::SetCompose
              (local_40,(CFastStringInt *)&stack0x00000000,in_stack_ffffff98,in_stack_ffffff9c);
    if (pCVar2 != (CSystemFids *)0x0) {
      in_stack_ffffff9c = (SStringParamInt *)0x0;
      in_stack_ffffff98 = (SStringParam *)0x1;
      in_stack_ffffff94 = local_40;
      pSVar14 = (SNationConfig *)0x41f99f;
      pCVar5 = CSystemFids::FindFid
                         (pCVar2,in_stack_ffffff94,(CFastStringInt *)0x1,0,in_stack_ffffffa0);
    }
    if (in_stack_ffffff94 != (CSystemFids *)0x0) {
      if (pCVar5 == (CSystemFid *)0x0) {
        pCVar5 = CSystemFids::FindFid
                           (in_stack_ffffff94,(CSystemFids *)&stack0xffffff9c,(CFastStringInt *)0x1,
                            0,(EFindWay)pSVar9);
        goto LAB_0041f9bc;
      }
LAB_0041f9c0:
      iVar4 = 1;
      CGameCtnApp::SNationConfig::~SNationConfig(&local_54,pSVar9);
      goto LAB_0041f83d;
    }
LAB_0041f9bc:
    if (pCVar5 != (CSystemFid *)0x0) goto LAB_0041f9c0;
    local_8 = local_54;
    local_14 = local_54;
    local_c = puStack_50;
    local_18 = puStack_50;
    local_10 = (undefined1 *)0x0;
    SStringParam::SStringParam(local_24,(SStringParam *)"%1\\%2.mo",(char *)pSVar9);
    CFastStringInt::SetCompose
              (&stack0xffffffa0,local_20,(SStringParam *)&local_14,(SStringParamInt *)&local_8);
    if (pCVar2 != (CSystemFids *)0x0) {
      pCVar5 = CSystemFids::FindFid
                         (pCVar2,(CSystemFids *)&stack0xffffffa0,(CFastStringInt *)0x1,0,EVar11);
    }
    if (in_stack_ffffff9c != (SStringParamInt *)0x0) {
      if (pCVar5 == (CSystemFid *)0x0) {
        pCVar5 = CSystemFids::FindFid
                           ((CSystemFids *)in_stack_ffffff9c,(CSystemFids *)local_5c,
                            (CFastStringInt *)0x1,0,(EFindWay)in_stack_ffffff84);
        goto LAB_0041fa4c;
      }
LAB_0041fa50:
      iVar4 = 0;
      CGameCtnApp::SNationConfig::~SNationConfig(&local_4c,(SNationConfig *)in_stack_ffffff84);
      goto LAB_0041f83d;
    }
LAB_0041fa4c:
    if (pCVar5 != (CSystemFid *)0x0) goto LAB_0041fa50;
    param_1 = (CSystemEngine *)0x0;
    SStringParam::SStringParam(local_1c,(SStringParam *)"%1.mo",(char *)in_stack_ffffff84);
    in_stack_ffffff84 = (CSystemFids *)register0x00000010;
    CFastStringInt::SetCompose
              (&pCStack_58,(CFastStringInt *)&local_18,(SStringParam *)&stack0x00000000,pSVar12);
    if (pCVar2 != (CSystemFids *)0x0) {
      in_stack_ffffff84 = (CSystemFids *)0x1;
      pCVar5 = CSystemFids::FindFid(pCVar2,(CSystemFids *)&local_54,(CFastStringInt *)0x1,0,EVar13);
    }
    if (pCStack_58 != (CSystemFids *)0x0) {
      if (pCVar5 == (CSystemFid *)0x0) {
        in_stack_ffffff84 = (CSystemFids *)&puStack_50;
        pCVar5 = CSystemFids::FindFid
                           (pCStack_58,in_stack_ffffff84,(CFastStringInt *)0x1,0,(EFindWay)pSVar14);
        goto LAB_0041fac8;
      }
LAB_0041facc:
      iVar4 = 0;
      CGameCtnApp::SNationConfig::~SNationConfig(local_40,pSVar14);
      goto LAB_0041f83d;
    }
LAB_0041fac8:
    if (pCVar5 != (CSystemFid *)0x0) goto LAB_0041facc;
    CGameCtnApp::SNationConfig::~SNationConfig(local_40,pSVar14);
    CGameCtnApp::SNationConfig::~SNationConfig(&local_4c,(SNationConfig *)in_stack_ffffff94);
    in_stack_00000028 = (void *)0xffffffff;
    CGameCtnApp::SNationConfig::~SNationConfig(local_40,(SNationConfig *)in_stack_ffffff98);
  }
  else {
    if (pCVar5 == (CSystemFid *)0x0) {
      in_stack_ffffff84 = (CSystemFids *)0x41f832;
      pCVar5 = CSystemFids::FindFid
                         (local_54,(CSystemFids *)&local_4c,(CFastStringInt *)0x1,0,
                          (EFindWay)in_stack_ffffff94);
      goto LAB_0041f834;
    }
LAB_0041f838:
    iVar4 = 1;
LAB_0041f83d:
    CGameCtnApp::SNationConfig::~SNationConfig(&local_4c,(SNationConfig *)in_stack_ffffff94);
    in_stack_00000028 = (void *)0xffffffff;
    CGameCtnApp::SNationConfig::~SNationConfig(local_40,(SNationConfig *)in_stack_ffffff98);
    if (pCVar5 != (CSystemFid *)0x0) {
      iVar3 = I18nLoadMessageCatalog
                        ((CSystemEngine *)local_48,(CSystemEngine *)pCVar5,(CSystemFid *)param_1,
                         (char *)in_stack_ffffff9c);
      if (iVar3 != 0) {
        ExceptionList = in_stack_00000028;
        return iVar4;
      }
      goto LAB_0041f75c;
    }
  }
  iVar4 = __stricmp((char *)param_1,"en");
  if (iVar4 != 0) {
    I18nSetLanguage((CSystemEngine *)local_48,(CSystemEngine *)&DAT_00b2ee48,
                    (char *)in_stack_ffffff9c);
    ExceptionList = in_stack_00000028;
    return 0;
  }
LAB_0041f75c:
  CClassicI18n::Reset((CClassicI18n *)&DAT_00d71d10,(GmFrustumIso4 *)in_stack_ffffff84);
  ExceptionList = in_stack_00000010;
  return 0;
}
}

// =================================================
// Function: CSystemEngine::InitForGbxGame
// =================================================
void __thiscall
CSystemEngine::InitForGbxGame
          (CSystemEngine *this,CSystemEngine *param_1,ulong param_2,CFastString *param_3,
          CFastString *param_4,CFastStringInt *param_5,CFastStringInt *param_6)
{
{
  CFastStringInt *pCVar1;
  undefined *puVar2;
  void *pvVar3;
  int iVar4;
  EMakeDir EVar5;
  CSystemEngine *extraout_EAX;
  undefined *puVar6;
  undefined1 *puVar7;
  char *pcVar8;
  CFastString *pCVar9;
  undefined4 unaff_EBP;
  char *unaff_ESI;
  CFastStringInt *unaff_EDI;
  undefined1 uStack0000001c;
  void *in_stack_00000020;
  undefined1 uStack00000024;
  char *in_stack_ffffffa8;
  char *pcVar10;
  SStringParam *pSVar11;
  char *pcVar12;
  ulong uVar13;
  CFastStringInt *pCVar14;
  SStringParam *in_stack_ffffffc8;
  CFastStringInt *in_stack_ffffffcc;
  CSystemEngine *local_2c;
  int local_28;
  undefined *local_24;
  undefined4 local_20;
  undefined *local_1c;
  undefined *local_18;
  undefined *local_14;
  undefined1 *local_10;
  undefined *local_c;
  char *local_8;
  
  local_c = (undefined *)0xffffffff;
  local_10 = &LAB_00a81620;
  local_14 = ExceptionList;
  pCVar1 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffa0);
  ExceptionList = &local_14;
  *(CSystemEngine **)(this + 0x54) = param_1;
  if (*(int *)param_2 != 0) {
    RegistrySetApplicationPath(*(char **)(param_2 + 4));
  }
  local_28 = 0;
  local_24 = PTR_DAT_00bbf7dc;
  uVar13 = 0;
  pcVar12 = (char *)0x0;
  pcVar10 = (char *)0x0;
  local_c = (undefined *)0x3;
  pSVar11 = (SStringParam *)PTR_DAT_00bbf7dc;
  pcVar8 = PTR_DAT_00bbf7dc;
  pCVar14 = (CFastStringInt *)PTR_DAT_00bbf7dc;
  InternalComputePaths
            (param_3,(CFastStringInt *)param_4,param_5,(CFastStringInt *)&stack0xffffffc0,
             (CFastStringInt *)&stack0xffffffb0,pCVar1,unaff_EDI);
  CFastString::CFastString((CFastString *)&local_20,(CFastString *)"0.0.0.0",(char *)pCVar1);
  local_8 = (char *)CONCAT31(local_8._1_3_,4);
  CFastString::CFastString((CFastString *)&local_2c,(CFastString *)"Version",(char *)unaff_EDI);
  FileIniRead((CFastString *)&local_28,(CFastString *)&DAT_00d54340,(CFastString *)&local_18);
  if (local_24 != PTR_DAT_00bbf7d8) {
    puVar6 = local_24 + -1;
    if ((local_24[-1] & 0x80) != 0) {
      puVar6 = local_24 + -4;
    }
    operator_delete__(puVar6);
    local_28 = 0;
    local_24 = PTR_DAT_00bbf7d8;
  }
  puVar6 = (undefined *)CONCAT31((int3)((uint)unaff_EBP >> 8),3);
  if (local_14 != PTR_DAT_00bbf7d8) {
    puVar2 = local_14 + -1;
    if ((local_14[-1] & 0x80) != 0) {
      puVar2 = local_14 + -4;
    }
    operator_delete__(puVar2);
  }
  CFastString::CFastString((CFastString *)&local_18,(CFastString *)&DAT_00b2c878,unaff_ESI);
  CFastString::CFastString((CFastString *)&local_24,(CFastString *)"Distro",in_stack_ffffffa8);
  param_1 = (CSystemEngine *)CONCAT31(param_1._1_3_,7);
  FileIniRead((CFastString *)&local_20,(CFastString *)&DAT_00d54328,(CFastString *)&local_10);
  if (local_1c != PTR_DAT_00bbf7d8) {
    puVar2 = local_1c + -1;
    if ((local_1c[-1] & 0x80) != 0) {
      puVar2 = local_1c + -4;
    }
    operator_delete__(puVar2);
    local_20 = 0;
    local_1c = PTR_DAT_00bbf7d8;
  }
  param_1 = (CSystemEngine *)CONCAT31(param_1._1_3_,3);
  if (local_c != PTR_DAT_00bbf7d8) {
    puVar2 = local_c + -1;
    if ((local_c[-1] & 0x80) != 0) {
      puVar2 = local_c + -4;
    }
    operator_delete__(puVar2);
  }
  CFastString::CFastString((CFastString *)&local_10,(CFastString *)&DAT_00b2c878,(char *)this);
  param_2 = CONCAT31(param_2._1_3_,8);
  CFastString::CFastString((CFastString *)&local_1c,(CFastString *)"WindowTitle",pcVar10);
  param_3 = (CFastString *)CONCAT31(param_3._1_3_,9);
  FileIniRead((CFastString *)&local_18,(CFastString *)&DAT_00d54318,(CFastString *)&local_8);
  if (local_14 != PTR_DAT_00bbf7d8) {
    puVar2 = local_14 + -1;
    if ((local_14[-1] & 0x80) != 0) {
      puVar2 = local_14 + -4;
    }
    operator_delete__(puVar2);
    local_18 = (undefined *)0x0;
    local_14 = PTR_DAT_00bbf7d8;
  }
  param_3 = (CFastString *)CONCAT31(param_3._1_3_,3);
  if (puVar6 != PTR_DAT_00bbf7d8) {
    puVar2 = puVar6 + -1;
    if ((puVar6[-1] & 0x80) != 0) {
      puVar2 = puVar6 + -4;
    }
    operator_delete__(puVar2);
  }
  if (DAT_00d54318 == 0) {
    local_8 = "TmForever";
    CFastString::SetString((CFastString *)&DAT_00d54318,(CFastStringInt *)&local_8,pSVar11);
  }
  local_1c = (undefined *)0x0;
  local_18 = PTR_DAT_00bbf7d8;
  param_4 = (CFastString *)CONCAT31(param_4._1_3_,10);
  CFastString::CFastString((CFastString *)&stack0xfffffffc,(CFastString *)&DAT_00b2c878,pcVar12);
  param_5 = (CFastStringInt *)CONCAT31(param_5._1_3_,0xb);
  CFastString::CFastString((CFastString *)&local_10,(CFastString *)&DAT_00b2ed20,pcVar8);
  param_6 = (CFastStringInt *)CONCAT31(param_6._1_3_,0xc);
  FileIniRead((CFastString *)&local_c,(CFastString *)&local_14,(CFastString *)&param_1);
  if (local_8 != PTR_DAT_00bbf7d8) {
    pcVar8 = local_8 + -1;
    if ((local_8[-1] & 0x80U) != 0) {
      pcVar8 = local_8 + -4;
    }
    operator_delete__(pcVar8);
    local_c = (undefined *)0x0;
    local_8 = PTR_DAT_00bbf7d8;
  }
  param_6 = (CFastStringInt *)CONCAT31(param_6._1_3_,10);
  if ((undefined *)param_2 != PTR_DAT_00bbf7d8) {
    pvVar3 = (void *)(param_2 - 1);
    if ((*(byte *)(param_2 - 1) & 0x80) != 0) {
      pvVar3 = (void *)(param_2 - 4);
    }
    operator_delete__(pvVar3);
  }
  param_1 = (CSystemEngine *)&DAT_00b2ed1c;
  param_2 = 3;
  if (local_14 == (undefined *)0x3) {
    iVar4 = CFastString::CompareNoCase
                      ((CFastString *)&local_14,(CFastStringInt *)&param_1,(SStringParam *)0x0,
                       uVar13);
    DAT_00d54240 = (uint)(iVar4 == 0);
  }
  else {
    DAT_00d54240 = 0;
  }
  uStack0000001c = 3;
  if (local_c != PTR_DAT_00bbf7d8) {
    puVar6 = local_c + -1;
    if ((local_c[-1] & 0x80) != 0) {
      puVar6 = local_c + -4;
    }
    operator_delete__(puVar6);
  }
  if (local_28 != 0) {
    EVar5 = CSystemManagerFile::MakeDir((CFastStringInt *)&local_28);
    if (EVar5 != 2) {
      CSystemManagerFile::GiveDirAllRights((CFastStringInt *)&local_28);
    }
  }
  SetDrives(local_2c,(CSystemEngine *)&stack0x00000000,(CFastStringInt *)&local_18,
            (CFastStringInt *)&local_20,(CFastStringInt *)&local_28,pCVar14);
  CFastStringInt::CFastStringInt(&param_3,(CFastStringInt *)L"GameData\\",in_stack_ffffffc8);
  uStack00000024 = 0xd;
  SetLocationDataShortName(local_2c,extraout_EAX,in_stack_ffffffcc);
  if (param_6 != (CFastStringInt *)PTR_DAT_00bbf7dc) {
    pCVar1 = param_6 + -4;
    if (((byte)param_6[-1] & 0x80) == 0) {
      pCVar1 = param_6 + -2;
    }
    operator_delete__(pCVar1);
  }
  if (local_18 != PTR_DAT_00bbf7dc) {
    puVar6 = local_18 + -4;
    if ((local_18[-1] & 0x80) == 0) {
      puVar6 = local_18 + -2;
    }
    operator_delete__(puVar6);
    local_1c = (undefined *)0x0;
    local_18 = PTR_DAT_00bbf7dc;
  }
  if (local_10 != PTR_DAT_00bbf7dc) {
    puVar7 = local_10 + -4;
    if ((local_10[-1] & 0x80) == 0) {
      puVar7 = local_10 + -2;
    }
    operator_delete__(puVar7);
    local_14 = (undefined *)0x0;
    local_10 = PTR_DAT_00bbf7dc;
  }
  if (local_8 != PTR_DAT_00bbf7dc) {
    pcVar8 = local_8 + -4;
    if ((local_8[-1] & 0x80U) == 0) {
      pcVar8 = local_8 + -2;
    }
    operator_delete__(pcVar8);
    local_c = (undefined *)0x0;
    local_8 = PTR_DAT_00bbf7dc;
  }
  if (param_4 != (CFastString *)PTR_DAT_00bbf7dc) {
    pCVar9 = param_4 + -4;
    if (((byte)param_4[-1] & 0x80) == 0) {
      pCVar9 = param_4 + -2;
    }
    operator_delete__(pCVar9);
  }
  ExceptionList = in_stack_00000020;
  return;
}
}

// =================================================
// Function: CSystemEngine::LoadGraphicPerformance
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl CSystemEngine::LoadGraphicPerformance(void)
{
{
  SCriteria *pSVar1;
  int iVar2;
  ELoadGfxPerfResult EVar3;
  CPlugFileGpuBuilder *pCVar4;
  char *pcVar5;
  undefined *puVar6;
  SHeaderCommunity *unaff_ESI;
  void *unaff_retaddr;
  LPCSTR *ppCVar7;
  SNationConfig *pSVar8;
  CPlugFileGpuBuilder *pCVar9;
  char *pcVar10;
  undefined *local_34;
  undefined4 local_30;
  undefined *local_2c;
  undefined *local_28;
  undefined *local_24;
  undefined4 local_20;
  LPCSTR *local_1c;
  undefined4 local_18;
  undefined *local_14;
  undefined1 *local_10;
  undefined4 local_c;
  void *local_8;
  
  local_10 = &LAB_00a81958;
  local_14 = ExceptionList;
  pSVar1 = (SCriteria *)(DAT_00cca150 ^ (uint)&stack0xffffffb8);
  if ((DAT_00d542a0 == 0) || (DAT_00d542a4 == 0)) {
    ExceptionList = &LAB_00a81958;
    return 0;
  }
  if (DAT_00d542b0 == 0) {
    DAT_00d542e8 = 0;
    DAT_00d542ec = 0;
    _DAT_00d542f0 = 0;
    _DAT_00d542f4 = 0;
    _DAT_00d542f8 = 0;
    _DAT_00d542fc = 0;
    _DAT_00d54300 = 0;
    _DAT_00d54304 = 0;
    _DAT_00d54308 = 0;
    _DAT_00d5430c = 1;
    return 1;
  }
  pcVar10 = (char *)0x0;
  pSVar8 = (SNationConfig *)0x0;
  local_2c = (undefined *)0x0;
  local_28 = PTR_DAT_00bbf7d8;
  local_34 = (undefined *)0x2;
  local_30 = 0xffffffff;
  local_24 = (undefined *)0x0;
  local_20 = 0;
  local_1c = &lpOutputString_00b2bcc4;
  local_c = 2;
  ExceptionList = &local_14;
  pCVar9 = (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8;
  iVar2 = GpuPerfFile_ReadContent
                    ((CFastString *)&stack0xffffffbc,(SFastToken *)&local_34,
                     (CFastStringInt *)&stack0xffffffc4);
  if (iVar2 == 0) {
    CGameMasterServer::SCriteria::~SCriteria(&local_34,pSVar1);
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xffffffc0,unaff_ESI);
    CGameCtnApp::SNationConfig::~SNationConfig(&local_34,pSVar8);
    ExceptionList = local_8;
    return 0;
  }
  _DAT_00d5430c = _DAT_00d5430c & 0xfffffff8;
  do {
    iVar2 = CFastString::GetNextToken
                      ((CFastString *)&stack0xffffffbc,(CFastStringInt *)&local_34,
                       (SFastTokenInt *)pSVar1);
    if (iVar2 == 0) {
      if (local_24 != PTR_DAT_00bbf7d8) {
        puVar6 = local_24 + -1;
        if ((local_24[-1] & 0x80) != 0) {
          puVar6 = local_24 + -4;
        }
        operator_delete__(puVar6);
        local_28 = (undefined *)0x0;
        local_24 = PTR_DAT_00bbf7d8;
      }
      if (pcVar10 != PTR_DAT_00bbf7d8) {
        pcVar5 = pcVar10 + -1;
        if ((pcVar10[-1] & 0x80U) != 0) {
          pcVar5 = pcVar10 + -4;
        }
        operator_delete__(pcVar5);
      }
      if (local_34 == PTR_DAT_00bbf7dc) {
        ExceptionList = local_10;
        return 0;
      }
      if ((local_34[-1] & 0x80) != 0) {
        puVar6 = local_34 + -4;
        goto LAB_00420d9a;
      }
LAB_00420d97:
      puVar6 = local_34 + -2;
LAB_00420d9a:
      operator_delete__(puVar6);
      ExceptionList = local_10;
      return 0;
    }
    pSVar1 = (SCriteria *)&DAT_00d542e8;
    EVar3 = CSystemEngine__LoadGraphicPerformance
                      ((CFastString *)&local_28,(ulong *)&DAT_00d542a0,(ulong *)&DAT_00d542a4,
                       (SSysGraphicPerformance *)&DAT_00d542e8);
    if ((EVar3 == 2) || (2 < (int)EVar3)) {
      if (local_24 != PTR_DAT_00bbf7d8) {
        puVar6 = local_24 + -1;
        if ((local_24[-1] & 0x80) != 0) {
          puVar6 = local_24 + -4;
        }
        operator_delete__(puVar6);
        local_28 = (undefined *)0x0;
        local_24 = PTR_DAT_00bbf7d8;
      }
      if (pcVar10 != PTR_DAT_00bbf7d8) {
        pcVar5 = pcVar10 + -1;
        if ((pcVar10[-1] & 0x80U) != 0) {
          pcVar5 = pcVar10 + -4;
        }
        operator_delete__(pcVar5);
      }
      if (local_34 == PTR_DAT_00bbf7dc) {
        ExceptionList = local_10;
        return 0;
      }
      if ((local_34[-1] & 0x80) != 0) {
        puVar6 = local_34 + -4;
        goto LAB_00420d9a;
      }
      goto LAB_00420d97;
    }
    if (EVar3 != 1) {
      _DAT_00d5430c = _DAT_00d5430c | 1;
      SSysGraphicPerformance::UpdateCpuDependant(&DAT_00d542e8,(SSysGraphicPerformance *)0x420bc0);
      if (DAT_00d71e54 != 0) {
        DAT_00d71e54 = 0;
        *DAT_00d71e58 = 0;
      }
      ppCVar7 = &lpOutputString_00b2bcc4;
      pCVar4 = CFastString::operator<<
                         ((CFastString *)&DAT_00d71e54,
                          (CPlugFileGpuBuilder *)"[Sys] GpuPerf found in ",(char *)&local_34);
      pCVar4 = CFastString::operator<<
                         ((CFastString *)pCVar4,(CPlugFileGpuBuilder *)ppCVar7,(char *)pSVar8);
      CFastString::operator<<((CFastString *)pCVar4,pCVar9,pcVar10);
      CClassicLog::AddLogStringInFile();
      if (local_14 != PTR_DAT_00bbf7d8) {
        puVar6 = local_14 + -1;
        if ((local_14[-1] & 0x80) != 0) {
          puVar6 = local_14 + -4;
        }
        operator_delete__(puVar6);
        local_18 = 0;
        local_14 = PTR_DAT_00bbf7d8;
      }
      if (local_2c != PTR_DAT_00bbf7d8) {
        puVar6 = local_2c + -1;
        if ((local_2c[-1] & 0x80) != 0) {
          puVar6 = local_2c + -4;
        }
        operator_delete__(puVar6);
        local_30 = 0;
        local_2c = PTR_DAT_00bbf7d8;
      }
      if (local_24 != PTR_DAT_00bbf7dc) {
        if ((local_24[-1] & 0x80) != 0) {
          operator_delete__(local_24 + -4);
          ExceptionList = unaff_retaddr;
          return 1;
        }
        operator_delete__(local_24 + -2);
      }
      ExceptionList = unaff_retaddr;
      return 1;
    }
  } while( true );
}
}

// =================================================
// Function: CSystemEngine::LoadResourceTable
// =================================================
void __thiscall CSystemEngine::LoadResourceTable(CSystemEngine *this,CSystemEngine *param_1)
{
{
  CSystemEngine *this_00;
  SCasterCat *pSVar1;
  CSystemFidFile *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  undefined4 *unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  SStringParam *pSVar5;
  ulong in_stack_00000008;
  SStringParam *pSVar6;
  ulong uVar7;
  CFastStringInt *in_stack_00000014;
  char *pcVar8;
  ulong uVar9;
  CFastStringInt *in_stack_00000020;
  char *pcVar10;
  CFastStringInt *in_stack_0000002c;
  CFastStringInt *in_stack_00000038;
  CFastStringInt *in_stack_00000044;
  CFastStringInt *in_stack_00000050;
  CFastStringInt *in_stack_0000005c;
  CFastStringInt *in_stack_00000068;
  CFastStringInt *in_stack_00000074;
  CFastStringInt *in_stack_00000080;
  CFastStringInt *in_stack_0000008c;
  CFastStringInt *in_stack_00000098;
  CFastStringInt *in_stack_000000a4;
  CFastStringInt *in_stack_000000b0;
  CFastStringInt *in_stack_000000bc;
  CFastStringInt *in_stack_000000c8;
  CFastStringInt *in_stack_000000d4;
  CFastStringInt *in_stack_000000e0;
  CFastStringInt *in_stack_000000ec;
  CFastStringInt *in_stack_000000f8;
  CFastStringInt *in_stack_00000104;
  CFastStringInt *in_stack_00000110;
  CFastStringInt *in_stack_0000011c;
  CFastStringInt *in_stack_00000128;
  CFastStringInt *in_stack_00000134;
  CFastStringInt *in_stack_00000140;
  CFastStringInt *in_stack_0000014c;
  CFastStringInt *in_stack_00000158;
  CFastStringInt *in_stack_00000164;
  CFastStringInt *in_stack_00000170;
  CFastStringInt *in_stack_0000017c;
  CFastStringInt *in_stack_00000188;
  CFastStringInt *in_stack_00000194;
  CFastStringInt *in_stack_000001a0;
  CFastStringInt *in_stack_000001ac;
  CFastStringInt *in_stack_000001b8;
  CFastStringInt *in_stack_000001c4;
  CFastStringInt *in_stack_000001d0;
  CFastStringInt *in_stack_000001dc;
  CFastStringInt *in_stack_000001e8;
  CFastStringInt *in_stack_000001f4;
  ulong in_stack_00000200;
  int iVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000020c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  ulong in_stack_fffffff0;
  SStringParam *in_stack_fffffff4;
  
  pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&stack0xfffffffc;
  if (*(int *)(this + 0x24) != 0) {
    this_00 = this + 0x44;
    CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
              (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)0x2d,unaff_EDI);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_ESI);
      pCVar2 = CSystemManagerFile::CreateFidResourceFile
                         (*(CSystemManagerFile **)(this + 0x20),(CSystemManagerFile *)pCVar12);
      *unaff_EBP = pCVar2;
      unaff_ESI = 0x41c7aa;
      pCVar12 = pCVar4;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_EBX);
      pCVar4 = pCVar4 + 1;
      *(undefined4 *)(*(int *)pSVar3 + 0x14) = *(undefined4 *)(this + 0x24);
    } while (pCVar4 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2d);
    pSVar5 = (SStringParam *)&DAT_00b2c878;
    param_1 = (CSystemEngine *)0x0;
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        in_stack_fffffff0);
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar3 + 0x74),(CFastStringInt *)&param_1,in_stack_fffffff4);
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)pSVar1)
    ;
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0;
    pSVar6 = (SStringParam *)&DAT_00b2c878;
    uVar7 = 0;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                        (ulong)unaff_EBP);
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),(CFastStringInt *)&stack0x00000010,pSVar5);
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,(ulong)param_1
                       );
    param_1 = (CSystemEngine *)0x2;
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 1;
    pcVar8 = "Media\\Texture\\HotGrid.Texture.gbx";
    uVar9 = 0x21;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                        in_stack_00000008);
    param_1 = (CSystemEngine *)0x41c846;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),(CFastStringInt *)&stack0x0000001c,pSVar6);
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 2;
    pcVar10 = "Media\\Texture\\MeshDefault.Texture.gbx";
    uVar7 = 0x25;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                        (ulong)in_stack_00000014);
    in_stack_00000014 = (CFastStringInt *)&stack0x00000028;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000014,(SStringParam *)pcVar8);
    in_stack_00000014 = (CFastStringInt *)0x41c889;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 3;
    pcVar8 = "Media\\Texture\\NoBitmap.Texture.gbx";
    uVar9 = 0x22;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004,
                        (ulong)in_stack_00000020);
    in_stack_00000020 = (CFastStringInt *)&stack0x00000034;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000020,(SStringParam *)pcVar10);
    in_stack_00000020 = (CFastStringInt *)0x41c8c3;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004,
                        uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 4;
    pcVar10 = "Media\\Font\\Arial.Font.gbx";
    uVar7 = 0x19;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000005,
                        (ulong)in_stack_0000002c);
    in_stack_0000002c = (CFastStringInt *)&stack0x00000040;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_0000002c,(SStringParam *)pcVar8);
    in_stack_0000002c = (CFastStringInt *)0x41c8fd;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000005,
                        uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 5;
    pcVar8 = "Media\\Texture\\Light.Texture.gbx";
    uVar9 = 0x1f;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000006,
                        (ulong)in_stack_00000038);
    in_stack_00000038 = (CFastStringInt *)&stack0x0000004c;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000038,(SStringParam *)pcVar10);
    in_stack_00000038 = (CFastStringInt *)0x41c937;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000006,
                        uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 6;
    pcVar10 = "Media\\Text\\vsh\\Sprites.vsh.txt";
    uVar7 = 0x1e;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000007,
                        (ulong)in_stack_00000044);
    in_stack_00000044 = (CFastStringInt *)&stack0x00000058;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000044,(SStringParam *)pcVar8);
    in_stack_00000044 = (CFastStringInt *)0x41c972;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000007,
                        uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 7;
    pcVar8 = "Media\\Text\\vsh\\SpritesOrtho.vsh.txt";
    uVar9 = 0x23;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000008,
                        (ulong)in_stack_00000050);
    in_stack_00000050 = (CFastStringInt *)&stack0x00000064;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000050,(SStringParam *)pcVar10);
    in_stack_00000050 = (CFastStringInt *)0x41c9ad;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000008,
                        uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 8;
    pcVar10 = "Media\\Solid\\Cube.Solid.Gbx";
    uVar7 = 0x1a;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000009,
                        (ulong)in_stack_0000005c);
    in_stack_0000005c = (CFastStringInt *)&stack0x00000070;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_0000005c,(SStringParam *)pcVar8);
    in_stack_0000005c = (CFastStringInt *)0x41c9e7;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000009,
                        uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 9;
    pcVar8 = "Media\\Solid\\BrowsedShader.Solid.Gbx";
    uVar9 = 0x23;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000a,
                        (ulong)in_stack_00000068);
    in_stack_00000068 = (CFastStringInt *)&stack0x0000007c;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000068,(SStringParam *)pcVar10);
    in_stack_00000068 = (CFastStringInt *)0x41ca1d;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000a,
                        uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 10;
    pcVar10 = "Media\\Solid\\Location.Solid.Gbx";
    uVar7 = 0x1e;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                        (ulong)in_stack_00000074);
    in_stack_00000074 = (CFastStringInt *)&stack0x00000088;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000074,(SStringParam *)pcVar8);
    in_stack_00000074 = (CFastStringInt *)0x41ca53;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                        uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0xb;
    pcVar8 = "Media\\Solid\\Camera.Solid.Gbx";
    uVar9 = 0x1c;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000c,
                        (ulong)in_stack_00000080);
    in_stack_00000080 = (CFastStringInt *)&stack0x00000094;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000080,(SStringParam *)pcVar10);
    in_stack_00000080 = (CFastStringInt *)0x41ca8d;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000c,
                        uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0xc;
    pcVar10 = "Media\\Solid\\LightPoint.Solid.Gbx";
    uVar7 = 0x20;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000d,
                        (ulong)in_stack_0000008c);
    in_stack_0000008c = (CFastStringInt *)&stack0x000000a0;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_0000008c,(SStringParam *)pcVar8);
    in_stack_0000008c = (CFastStringInt *)0x41cac8;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000d,
                        uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0xd;
    pcVar8 = "Media\\Solid\\LightDirectional.Solid.Gbx";
    uVar9 = 0x26;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000e,
                        (ulong)in_stack_00000098);
    in_stack_00000098 = (CFastStringInt *)&stack0x000000ac;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000098,(SStringParam *)pcVar10);
    in_stack_00000098 = (CFastStringInt *)0x41cb02;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000e,
                        uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0xe;
    pcVar10 = "Media\\Solid\\LightFrustum.Solid.Gbx";
    uVar7 = 0x22;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000f,
                        (ulong)in_stack_000000a4);
    in_stack_000000a4 = (CFastStringInt *)&stack0x000000b8;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000000a4,(SStringParam *)pcVar8);
    in_stack_000000a4 = (CFastStringInt *)0x41cb3c;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000f,
                        uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0xf;
    pcVar8 = "Media\\Solid\\Sound.Solid.Gbx";
    uVar9 = 0x1b;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x10,
                        (ulong)in_stack_000000b0);
    in_stack_000000b0 = (CFastStringInt *)&stack0x000000c4;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000000b0,(SStringParam *)pcVar10);
    in_stack_000000b0 = (CFastStringInt *)0x41cb77;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x10,uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x10;
    pcVar10 = "Media\\Solid\\Music.Solid.Gbx";
    uVar7 = 0x1b;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000011,
                        (ulong)in_stack_000000bc);
    in_stack_000000bc = (CFastStringInt *)&stack0x000000d0;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000000bc,(SStringParam *)pcVar8);
    in_stack_000000bc = (CFastStringInt *)0x41cbad;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000011,
                        uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x11;
    pcVar8 = "Media\\Solid\\LinkPortal.Solid.Gbx";
    uVar9 = 0x20;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000012,
                        (ulong)in_stack_000000c8);
    in_stack_000000c8 = (CFastStringInt *)&stack0x000000dc;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000000c8,(SStringParam *)pcVar10);
    in_stack_000000c8 = (CFastStringInt *)0x41cbe3;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000012,
                        uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x12;
    pcVar10 = "Media\\Solid\\LinkPath.Solid.Gbx";
    uVar7 = 0x1e;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000013,
                        (ulong)in_stack_000000d4);
    in_stack_000000d4 = (CFastStringInt *)&stack0x000000e8;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000000d4,(SStringParam *)pcVar8);
    in_stack_000000d4 = (CFastStringInt *)0x41cc1d;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000013,
                        uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x13;
    pcVar8 = "Media\\Solid\\LinkStreet.Solid.Gbx";
    uVar9 = 0x20;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000014,
                        (ulong)in_stack_000000e0);
    in_stack_000000e0 = (CFastStringInt *)&stack0x000000f4;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000000e0,(SStringParam *)pcVar10);
    in_stack_000000e0 = (CFastStringInt *)0x41cc53;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000014,
                        uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x14;
    pcVar10 = "Media\\Text\\vsh\\Blend2.vsh.txt";
    uVar7 = 0x1d;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x15,
                        (ulong)in_stack_000000ec);
    in_stack_000000ec = (CFastStringInt *)&stack0x00000100;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000000ec,(SStringParam *)pcVar8);
    in_stack_000000ec = (CFastStringInt *)0x41cc8d;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x15,uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x15;
    pcVar8 = "Media\\Solid\\Field.Solid.Gbx";
    uVar9 = 0x1b;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000016,
                        (ulong)in_stack_000000f8);
    in_stack_000000f8 = (CFastStringInt *)&stack0x0000010c;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000000f8,(SStringParam *)pcVar10);
    in_stack_000000f8 = (CFastStringInt *)0x41ccc3;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000016,
                        uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x16;
    pcVar10 = "Media\\Texture\\CubeNormalsZPos.Texture.gbx";
    uVar7 = 0x29;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000017,
                        (ulong)in_stack_00000104);
    in_stack_00000104 = (CFastStringInt *)&stack0x00000118;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000104,(SStringParam *)pcVar8);
    in_stack_00000104 = (CFastStringInt *)0x41ccfd;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000017,
                        uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x17;
    pcVar8 = "Media\\Texture\\Arial.Texture.gbx";
    uVar9 = 0x1f;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x18,
                        (ulong)in_stack_00000110);
    in_stack_00000110 = (CFastStringInt *)&stack0x00000124;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000110,(SStringParam *)pcVar10);
    in_stack_00000110 = (CFastStringInt *)0x41cd37;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x18,uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x18;
    pcVar10 = "Media\\Texture\\WhiteFlare1.Texture.gbx";
    uVar7 = 0x25;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x19,
                        (ulong)in_stack_0000011c);
    in_stack_0000011c = (CFastStringInt *)&stack0x00000130;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_0000011c,(SStringParam *)pcVar8);
    in_stack_0000011c = (CFastStringInt *)0x41cd71;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x19,uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x19;
    pcVar8 = "Media\\Texture\\RenderEnv2D1.Texture.gbx";
    uVar9 = 0x26;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000001a,
                        (ulong)in_stack_00000128);
    in_stack_00000128 = (CFastStringInt *)&stack0x0000013c;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000128,(SStringParam *)pcVar10);
    in_stack_00000128 = (CFastStringInt *)0x41cdab;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000001a,
                        uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x1a;
    pcVar10 = "Media\\Texture\\RenderEnv2D2.Texture.gbx";
    uVar7 = 0x26;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1b,
                        (ulong)in_stack_00000134);
    in_stack_00000134 = (CFastStringInt *)&stack0x00000148;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000134,(SStringParam *)pcVar8);
    in_stack_00000134 = (CFastStringInt *)0x41cde3;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1b,uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x1b;
    pcVar8 = "Media\\Texture\\RenderEnvCube1.Texture.gbx";
    uVar9 = 0x28;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1c,
                        (ulong)in_stack_00000140);
    in_stack_00000140 = (CFastStringInt *)&stack0x00000154;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000140,(SStringParam *)pcVar10);
    in_stack_00000140 = (CFastStringInt *)0x41ce19;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1c,uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x1c;
    pcVar10 = "Media\\Shader\\Default.ShaderSprite.gbx";
    uVar7 = 0x25;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000001d,
                        (ulong)in_stack_0000014c);
    in_stack_0000014c = (CFastStringInt *)&stack0x00000160;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_0000014c,(SStringParam *)pcVar8);
    in_stack_0000014c = (CFastStringInt *)0x41ce53;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000001d,
                        uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x1d;
    pcVar8 = "Media\\Text\\Vsh\\ShadowSmooth1.vsh.txt";
    uVar9 = 0x24;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1e,
                        (ulong)in_stack_00000158);
    in_stack_00000158 = (CFastStringInt *)&stack0x0000016c;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000158,(SStringParam *)pcVar10);
    in_stack_00000158 = (CFastStringInt *)0x41ce8d;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1e,uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x1e;
    pcVar10 = "Media\\Text\\Vsh\\Projector1.vsh.txt";
    uVar7 = 0x21;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1f,
                        (ulong)in_stack_00000164);
    in_stack_00000164 = (CFastStringInt *)&stack0x00000178;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000164,(SStringParam *)pcVar8);
    in_stack_00000164 = (CFastStringInt *)0x41cec3;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1f,uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x1f;
    pcVar8 = "Media\\ControlStyle\\Default.ControlStyle.Gbx";
    uVar9 = 0x2b;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000020,
                        (ulong)in_stack_00000170);
    in_stack_00000170 = (CFastStringInt *)&stack0x00000184;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000170,(SStringParam *)pcVar10);
    in_stack_00000170 = (CFastStringInt *)0x41cefc;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000020,
                        uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x20;
    pcVar10 = "Media\\Text\\VHlsl\\Common.VHlsl.txt";
    uVar7 = 0x21;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x21,
                        (ulong)in_stack_0000017c);
    in_stack_0000017c = (CFastStringInt *)&stack0x00000190;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_0000017c,(SStringParam *)pcVar8);
    in_stack_0000017c = (CFastStringInt *)0x41cf2c;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x21,uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x21;
    pcVar8 = "Media\\Text\\PHlsl\\Common.PHlsl.txt";
    uVar9 = 0x21;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x22,
                        (ulong)in_stack_00000188);
    in_stack_00000188 = (CFastStringInt *)&stack0x0000019c;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000188,(SStringParam *)pcVar10);
    in_stack_00000188 = (CFastStringInt *)0x41cf5e;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x22,uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x22;
    pcVar10 = "Media\\Text\\PHlsl\\ShadowBufferSoft.PHlsl.Cry";
    uVar7 = 0x2b;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000023,
                        (ulong)in_stack_00000194);
    in_stack_00000194 = (CFastStringInt *)&stack0x000001a8;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_00000194,(SStringParam *)pcVar8);
    in_stack_00000194 = (CFastStringInt *)0x41cf94;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000023,
                        uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x23;
    pcVar8 = "Media\\Texture\\Arrow.Texture.gbx";
    uVar9 = 0x1f;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x24,
                        (ulong)in_stack_000001a0);
    in_stack_000001a0 = (CFastStringInt *)&stack0x000001b4;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000001a0,(SStringParam *)pcVar10);
    in_stack_000001a0 = (CFastStringInt *)0x41cfce;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x24,uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x24;
    pcVar10 = "Required\\Camera.SuperTree.Gbx";
    uVar7 = 0x1d;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000025,
                        (ulong)in_stack_000001ac);
    in_stack_000001ac = (CFastStringInt *)&stack0x000001c0;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000001ac,(SStringParam *)pcVar8);
    in_stack_000001ac = (CFastStringInt *)0x41d008;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000025,
                        uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x25;
    pcVar8 = "Required\\LightSpot.SuperTree.Gbx";
    uVar9 = 0x20;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000026,
                        (ulong)in_stack_000001b8);
    in_stack_000001b8 = (CFastStringInt *)&stack0x000001cc;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000001b8,(SStringParam *)pcVar10);
    in_stack_000001b8 = (CFastStringInt *)0x41d03e;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000026,
                        uVar7);
    uVar7 = 0x20;
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x26;
    pcVar10 = "Required\\LightOmni.SuperTree.Gbx";
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x27,
                        (ulong)in_stack_000001c4);
    in_stack_000001c4 = (CFastStringInt *)&stack0x000001d8;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000001c4,(SStringParam *)pcVar8);
    in_stack_000001c4 = (CFastStringInt *)0x41d077;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x27,uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x27;
    pcVar8 = "Required\\LightDirectional.SuperTree.Gbx";
    uVar9 = 0x27;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000028,
                        (ulong)in_stack_000001d0);
    in_stack_000001d0 = (CFastStringInt *)&stack0x000001e4;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000001d0,(SStringParam *)pcVar10);
    in_stack_000001d0 = (CFastStringInt *)0x41d0a9;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000028,
                        uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x28;
    pcVar10 = "Required\\Sprite1.Texture.gbx";
    uVar7 = 0x1c;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000029,
                        (ulong)in_stack_000001dc);
    in_stack_000001dc = (CFastStringInt *)&stack0x000001f0;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000001dc,(SStringParam *)pcVar8);
    in_stack_000001dc = (CFastStringInt *)0x41d0e4;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000029,
                        uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x29;
    pcVar8 = "Required\\preferences.gbx";
    uVar9 = 0x18;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000002a,
                        (ulong)in_stack_000001e8);
    in_stack_000001e8 = (CFastStringInt *)&stack0x000001fc;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000001e8,(SStringParam *)pcVar10);
    in_stack_000001e8 = (CFastStringInt *)0x41d11e;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000002a,
                        uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x2a;
    pcVar10 = "Required\\Locator.Texture.gbx";
    uVar7 = 0x1c;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000002b,
                        (ulong)in_stack_000001f4);
    in_stack_000001f4 = (CFastStringInt *)&stack0x00000208;
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),in_stack_000001f4,(SStringParam *)pcVar8);
    in_stack_000001f4 = (CFastStringInt *)0x41d152;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000002b,
                        uVar9);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x2b;
    pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00b2c878;
    uVar9 = 0;
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000002c,
                        in_stack_00000200);
    CFastStringInt::SetString
              ((void *)(*(int *)pSVar1 + 0x74),(CFastStringInt *)&stack0x00000214,
               (SStringParam *)pcVar10);
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000002c,
                        uVar7);
    *(undefined4 *)(*(int *)pSVar1 + 0x7c) = 0x2c;
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      uVar7 = 0x41d19b;
      pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar4,(ulong)in_stack_0000020c);
      if (*(int *)(*(int *)pSVar1 + 0x74) == 0) {
        pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar4,(ulong)pCVar12);
        if (*(int **)pSVar1 != (int *)0x0) {
          (**(code **)(**(int **)pSVar1 + 4))();
        }
        in_stack_0000020c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x41d1c2;
        pCVar12 = pCVar4;
        pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,uVar9);
        *(undefined4 *)pSVar1 = 0;
      }
      else {
        iVar11 = 0x41d1cf;
        in_stack_0000020c = pCVar4;
        pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar4,(ulong)pCVar12);
        pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x41d1db;
        (**(code **)(**(int **)pSVar1 + 0x8c))();
        pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,uVar7);
        CSystemFid::ConcatLocation(*(CSystemFid **)pSVar1,(CSystemFid *)0x1,iVar11);
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2d);
  }
  return;
}
}

// =================================================
// Function: CSystemEngine::LoadSystemConfigAndBindToFid
// =================================================
int __thiscall
CSystemEngine::LoadSystemConfigAndBindToFid
          (CSystemEngine *this,CSystemEngine *param_1,CFastStringInt *param_2,int param_3,
          CMwNodRef<class_CSystemConfig> *param_4)
{
{
  CSystemEngine *extraout_EAX;
  SCasterCat *pSVar1;
  CSystemFids *pCVar2;
  void *pvVar3;
  CSystemFid *pCVar4;
  int iVar5;
  CPlugFileGpuBuilder *this_00;
  CMwNod *extraout_EAX_00;
  undefined *puVar6;
  ulong *unaff_EBX;
  ulong unaff_EBP;
  SStringParam *unaff_ESI;
  CMwNod *this_01;
  SStringParam *unaff_EDI;
  undefined1 uStack00000014;
  CMwNodRef<class_CGameCamera> *in_stack_00000018;
  CSystemConfig *in_stack_00000020;
  int *in_stack_00000024;
  CSystemFids *pCVar7;
  CFastStringInt *pCVar8;
  int in_stack_ffffffdc;
  EFindWay in_stack_ffffffe0;
  char *pcVar9;
  CMwNod *in_stack_ffffffe4;
  char *local_18;
  undefined4 local_14 [2];
  char *local_c;
  undefined1 *local_8;
  undefined *local_4;
  
  local_4 = (undefined *)0xffffffff;
  local_8 = &LAB_00a8169b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastStringInt::CFastStringInt
            (&stack0xffffffdc,(CFastStringInt *)param_1,
             (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffcc));
  if (in_stack_ffffffe0 == 0) {
    local_18 = "Default.SystemConfig.Gbx";
    local_14[0] = 0x18;
    CFastStringInt::SetString(&stack0xffffffe0,(CFastStringInt *)&local_18,unaff_EDI);
  }
  local_c = "Config\\";
  local_8 = (undefined1 *)0x7;
  CFastStringInt::CFastStringInt(local_14,(CFastStringInt *)&local_c,unaff_ESI);
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d73300 + 0x20),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,unaff_EBP);
  pCVar8 = (CFastStringInt *)0x0;
  pCVar7 = (CSystemFids *)0x0;
  pCVar2 = GetLocationUser(*(CSystemEngine **)pSVar1,extraout_EAX);
  pCVar2 = CSystemFids::FindOrAddLocationDown(pCVar2,pCVar7,pCVar8,unaff_EBX,in_stack_ffffffdc);
  uStack00000014 = 0;
  if (PTR_DAT_00bbf7dc != (undefined *)0x0) {
    if ((bRamffffffff & 0x80) == 0) {
      pvVar3 = (void *)0xfffffffe;
    }
    else {
      pvVar3 = (void *)0xfffffffc;
    }
    operator_delete__(pvVar3);
    local_4 = (undefined *)0x0;
  }
  if ((in_stack_00000020 == (CSystemConfig *)0x0) ||
     (pCVar4 = CSystemFids::FindFid
                         (pCVar2,(CSystemFids *)&local_c,(CFastStringInt *)0x1,0,in_stack_ffffffe0),
     pCVar4 != (CSystemFid *)0x0)) {
    pcVar9 = &DAT_00000007;
    pCVar7 = pCVar2;
    iVar5 = CSystemArchiveNod::LoadFileFrom
                      ((CFastStringInt *)&local_8,(CMwNod **)&stack0x00000020,pCVar2,7);
    if ((iVar5 != 0) && (in_stack_00000020 != (CSystemConfig *)0x0)) {
      pcVar9 = (char *)0xb005000;
      pCVar7 = (CSystemFids *)0x41ee47;
      iVar5 = (**(code **)(*(int *)in_stack_00000020 + 0x10))();
      if (iVar5 != 0) {
        CMwNodRef<class_CGameCamera>::MwSetNod
                  (in_stack_00000024,in_stack_00000018,(CGameCamera *)pCVar7);
        goto LAB_0041ee99;
      }
    }
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    this_00 = CFastString::operator<<
                        ((CFastString *)&DAT_00d71e54,
                         (CPlugFileGpuBuilder *)"ERROR: Invalid SystemConfig File.",
                         (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)this_00,(CPlugFileGpuBuilder *)pCVar7,pcVar9);
    CClassicLog::ConsoleAddLogString(1,(CFastString *)&DAT_00d71e54);
  }
LAB_0041ee99:
  if (*in_stack_00000024 == 0) {
    in_stack_00000020 = operator_new(0x1d0);
    if (in_stack_00000020 == (CSystemConfig *)0x0) {
      this_01 = (CMwNod *)0x0;
    }
    else {
      CSystemConfig::CSystemConfig(in_stack_00000020,(CSystemConfig *)in_stack_ffffffe4);
      this_01 = extraout_EAX_00;
    }
    if (this_01 != (CMwNod *)*in_stack_00000024) {
      if (this_01 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(this_01,in_stack_ffffffe4);
      }
      if ((CMwNod *)*in_stack_00000024 != (CMwNod *)0x0) {
        CMwNod::MwRelease((CMwNod *)*in_stack_00000024,in_stack_ffffffe4);
      }
      *in_stack_00000024 = (int)this_01;
    }
    CSystemArchiveNod::SaveFile
              ((CFastStringInt *)&local_8,(CMwNod *)*in_stack_00000024,pCVar2,8,7,1);
    if (local_4 != PTR_DAT_00bbf7dc) {
      if ((local_4[-1] & 0x80) != 0) {
        operator_delete__(local_4 + -4);
        ExceptionList = param_4;
        return 1;
      }
      operator_delete__(local_4 + -2);
    }
    iVar5 = 1;
  }
  else {
    if (local_4 != PTR_DAT_00bbf7dc) {
      if ((local_4[-1] & 0x80) == 0) {
        puVar6 = local_4 + -2;
      }
      else {
        puVar6 = local_4 + -4;
      }
      operator_delete__(puVar6);
    }
    iVar5 = 0;
  }
  ExceptionList = param_4;
  return iVar5;
}
}

// =================================================
// Function: CSystemEngine::LogSystemInfos
// =================================================
void __cdecl CSystemEngine::LogSystemInfos(void)
{
{
  char *pcVar1;
  CPlugFileGpuBuilder *pCVar2;
  CPlugFileGpuBuilder *pCVar3;
  uint uVar4;
  CFastString *this;
  CPlugFileGpuBuilder *unaff_EBX;
  char *unaff_retaddr;
  CPlugFileGpuBuilder *in_stack_00000004;
  char *in_stack_00000008;
  CPlugFileGpuBuilder *in_stack_0000000c;
  char *in_stack_00000010;
  CPlugFileGpuBuilder *in_stack_00000014;
  char *in_stack_00000018;
  CPlugFileGpuBuilder *in_stack_0000001c;
  char *in_stack_00000020;
  CPlugFileGpuBuilder *in_stack_00000024;
  char *in_stack_00000028;
  CPlugFileGpuBuilder *in_stack_0000002c;
  char *in_stack_00000030;
  CPlugFileGpuBuilder *in_stack_00000034;
  char *in_stack_00000038;
  char *in_stack_0000004c;
  char *in_stack_00000050;
  undefined4 uStack00000054;
  undefined *in_stack_0000005c;
  void *in_stack_00000060;
  LPCSTR *ppCVar5;
  char *in_stack_ffffffec;
  char *in_stack_fffffff0;
  char *pcVar6;
  CPlugFileGpuBuilder *pCVar7;
  
  pCVar3 = ExceptionList;
  pCVar7 = (CPlugFileGpuBuilder *)0xffffffff;
  pcVar6 = &LAB_00a816c8;
  pcVar1 = (char *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &stack0xfffffff4;
  if (DAT_00d71e34 != 0) {
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    ppCVar5 = &lpOutputString_00b2bcc4;
    pCVar2 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"[Sys] Os = ",
                        (char *)&DAT_00d54288);
    pCVar2 = CFastString::operator<<((CFastString *)pCVar2,(CPlugFileGpuBuilder *)ppCVar5,pcVar1);
    CFastString::operator<<((CFastString *)pCVar2,unaff_EBX,in_stack_ffffffec);
    CClassicLog::AddLogStringInFile();
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    ppCVar5 = &lpOutputString_00b2bcc4;
    pCVar2 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"[Sys] Cpu = ",
                        &DAT_00d54290);
    pCVar2 = CFastString::operator<<
                       ((CFastString *)pCVar2,(CPlugFileGpuBuilder *)ppCVar5,in_stack_fffffff0);
    CFastString::operator<<((CFastString *)pCVar2,pCVar3,pcVar6);
    CClassicLog::AddLogStringInFile();
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    ppCVar5 = &lpOutputString_00b2bcc4;
    pcVar1 = "MHz (bench)";
    pCVar3 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"[Sys] Cpu = ",
                        DAT_00d54238);
    pCVar3 = CFastString::operator<<
                       ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)pcVar1,(char *)ppCVar5);
    pCVar3 = CFastString::operator<<((CFastString *)pCVar3,pCVar7,unaff_retaddr);
    CFastString::operator<<((CFastString *)pCVar3,in_stack_00000004,in_stack_00000008);
    CClassicLog::AddLogStringInFile();
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar3 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)"[Sys] Physical memory = ",DAT_00d5422c);
    pCVar3 = CFastString::operator<<
                       ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)&DAT_00b2edec,
                        (char *)&lpOutputString_00b2bcc4);
    pCVar3 = CFastString::operator<<((CFastString *)pCVar3,in_stack_0000000c,in_stack_00000010);
    CFastString::operator<<((CFastString *)pCVar3,in_stack_00000014,in_stack_00000018);
    CClassicLog::AddLogStringInFile();
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pcVar1 = DAT_00d542d0;
    uVar4 = (uint)DAT_00d542d4;
    pCVar3 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)"[Sys] Windows GDI resolution = ",DAT_00d542cc);
    pCVar3 = CFastString::operator<<
                       ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)&DAT_00b2edc8,pcVar1);
    pCVar3 = CFastString::operator<<
                       ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)&DAT_00b2edc8,
                        (char *)(uVar4 * 8));
    pCVar3 = CFastString::operator<<
                       ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)&DAT_00b2edcc,
                        (char *)&lpOutputString_00b2bcc4);
    pCVar3 = CFastString::operator<<((CFastString *)pCVar3,in_stack_0000001c,in_stack_00000020);
    pCVar3 = CFastString::operator<<((CFastString *)pCVar3,in_stack_00000024,in_stack_00000028);
    pCVar3 = CFastString::operator<<((CFastString *)pCVar3,in_stack_0000002c,in_stack_00000030);
    CFastString::operator<<((CFastString *)pCVar3,in_stack_00000034,in_stack_00000038);
    CClassicLog::AddLogStringInFile();
    pcVar1 = (char *)0x0;
    uStack00000054 = 0;
    pCVar3 = (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8;
    GetExeCheckSum();
    CFastString::Format(this,(CFastString *)&stack0x00000044,"0x%08X");
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    ppCVar5 = &lpOutputString_00b2bcc4;
    pCVar7 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"[Sys] ExeChecksum = ",
                        in_stack_00000050);
    pCVar7 = CFastString::operator<<((CFastString *)pCVar7,(CPlugFileGpuBuilder *)ppCVar5,pcVar1);
    CFastString::operator<<((CFastString *)pCVar7,pCVar3,in_stack_0000004c);
    in_stack_0000004c = (char *)0x41f1c8;
    CClassicLog::AddLogStringInFile();
    in_stack_0000004c = (char *)0x41f1cd;
    CSystemEngine__LogSystemInfos_Win32();
    if (in_stack_0000005c != PTR_DAT_00bbf7d8) {
      in_stack_0000004c = in_stack_0000005c + -1;
      if ((in_stack_0000005c[-1] & 0x80) != 0) {
        in_stack_0000004c = in_stack_0000005c + -4;
      }
      operator_delete__(in_stack_0000004c);
    }
  }
  ExceptionList = in_stack_00000060;
  return;
}
}

// =================================================
// Function: CSystemEngine::RegistrySetApplicationPath
// =================================================
void __cdecl CSystemEngine::RegistrySetApplicationPath(char *param_1)
{
{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  if (param_1 == (char *)0x0) {
    CFastString::SetString
              ((CFastString *)&DAT_00d54360,(CFastStringInt *)&stack0xfffffff8,(SStringParam *)0x0);
    return;
  }
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  CFastString::SetString
            ((CFastString *)&DAT_00d54360,(CFastStringInt *)&stack0xfffffff8,(SStringParam *)param_1
            );
  return;
}
}

// =================================================
// Function: CSystemEngine::RemoveAndDeleteFid
// =================================================
void __thiscall
CSystemEngine::RemoveAndDeleteFid(CSystemEngine *this,CSystemEngine *param_1,CSystemFid *param_2)
{
{
  CSystemEngine *pCVar1;
  CFastBufferKeyBase *pCVar2;
  ulong uVar3;
  SCasterCat *pSVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CGameCtnMediaBlockFxBlurDepth *unaff_EDI;
  CSystemFid *unaff_retaddr;
  CGameCtnMediaBlockFxBlurDepth *in_stack_0000000c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000010;
  ulong in_stack_00000014;
  CGameCtnMediaBlockFxBlurDepth *pCVar5;
  CFastBuffer<class_CCrystalFace*> *pCVar6;
  
  if (param_1 != (CSystemEngine *)0x0) {
    pCVar2 = CGameCtnMediaBlockCameraOrbital::GetFastBufferKey
                       ((CGameCtnMediaBlockCameraOrbital *)param_1,unaff_EDI);
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar2,unaff_ESI);
    pCVar1 = param_1;
    while (uVar3 != 0) {
      pCVar5 = (CGameCtnMediaBlockFxBlurDepth *)0x41c179;
      pCVar2 = CGameCtnMediaBlockCameraOrbital::GetFastBufferKey
                         ((CGameCtnMediaBlockCameraOrbital *)param_1,
                          (CGameCtnMediaBlockFxBlurDepth *)0x0);
      pCVar6 = (CFastBuffer<class_CCrystalFace*> *)0x41c180;
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pCVar2,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)unaff_retaddr,
                          (ulong)pCVar1);
      pCVar1 = *(CSystemEngine **)pSVar4;
      unaff_retaddr = (CSystemFid *)0x41c18a;
      RemoveFid(this,pCVar1,param_2);
      CGameCtnMediaBlockCameraOrbital::GetFastBufferKey
                ((CGameCtnMediaBlockCameraOrbital *)param_1,in_stack_0000000c);
      param_2 = (CSystemFid *)0x41c19a;
      pCVar2 = CGameCtnMediaBlockCameraOrbital::GetFastBufferKey
                         ((CGameCtnMediaBlockCameraOrbital *)param_1,
                          (CGameCtnMediaBlockFxBlurDepth *)0x0);
      in_stack_0000000c = (CGameCtnMediaBlockFxBlurDepth *)0x41c1a1;
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pCVar2,in_stack_00000010,in_stack_00000014);
      if (*(int **)pSVar4 != (int *)0x0) {
        in_stack_00000014 = 1;
        in_stack_00000010 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x41c1b0;
        (**(code **)(**(int **)pSVar4 + 4))();
      }
      pCVar2 = CGameCtnMediaBlockCameraOrbital::GetFastBufferKey
                         ((CGameCtnMediaBlockCameraOrbital *)param_1,pCVar5);
      uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar2,pCVar6);
    }
    RemoveFid(this,param_1,unaff_retaddr);
    (**(code **)(*(int *)param_1 + 4))();
  }
  return;
}
}

// =================================================
// Function: CSystemEngine::RemoveFid
// =================================================
void __thiscall
CSystemEngine::RemoveFid(CSystemEngine *this,CSystemEngine *param_1,CSystemFid *param_2)
{
{
  CMwNod *unaff_ESI;
  CSystemFid *unaff_EDI;
  CGameCtnMediaBlockFxBlurDepth *unaff_retaddr;
  
  if (*(CSystemFids **)(param_1 + 0x14) != (CSystemFids *)0x0) {
    CSystemFids::RemoveLeaveSafe(*(CSystemFids **)(param_1 + 0x14),(CSystemFids *)param_1,unaff_EDI)
    ;
  }
  UnbindFid(this,*(CSystemEngine **)(param_1 + 0x20),unaff_ESI);
  CGameCtnMediaBlockCameraOrbital::GetFastBufferKey
            ((CGameCtnMediaBlockCameraOrbital *)param_1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CSystemEngine::SetDrives
// =================================================
void __thiscall
CSystemEngine::SetDrives
          (CSystemEngine *this,CSystemEngine *param_1,CFastStringInt *param_2,
          CFastStringInt *param_3,CFastStringInt *param_4,CFastStringInt *param_5)
{
{
  CSystemFidsDrive *pCVar1;
  CSystemFidsDrive *pCVar2;
  CSystemFidsDrive *extraout_EAX;
  CSystemFidsDrive *extraout_EAX_00;
  CSystemFidsDrive *extraout_EAX_01;
  CSystemFidsDrive *extraout_EAX_02;
  CFastStringInt *pCVar3;
  CSystemEngine *pCVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a814ac;
  local_c = ExceptionList;
  pCVar1 = (CSystemFidsDrive *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  if (*(int *)param_1 != 0) {
    if (*(int **)(this + 0x24) != (int *)0x0) {
      (**(code **)(**(int **)(this + 0x24) + 4))(1);
    }
    pCVar4 = (CSystemEngine *)0x48;
    pCVar3 = (CFastStringInt *)0x41dd79;
    pCVar2 = operator_new(0x48);
    uStack_4 = 0;
    if (pCVar2 == (CSystemFidsDrive *)0x0) {
      pCVar2 = (CSystemFidsDrive *)0x0;
    }
    else {
      pCVar4 = (CSystemEngine *)0x41dd93;
      CSystemFidsDrive::CSystemFidsDrive(pCVar2,pCVar1);
      pCVar2 = extraout_EAX;
    }
    local_c = (void *)0xffffffff;
    *(CSystemFidsDrive **)(this + 0x24) = pCVar2;
    CSystemFidsDrive::SetDriveName(pCVar2,(CSystemFidsDrive *)param_1,pCVar3);
    LoadResourceTable(this,pCVar4);
  }
  if (*(int *)param_2 != 0) {
    if (*(int **)(this + 0x2c) != (int *)0x0) {
      (**(code **)(**(int **)(this + 0x2c) + 4))(1);
    }
    pCVar3 = (CFastStringInt *)0x48;
    pCVar2 = operator_new(0x48);
    uStack_4 = 1;
    if (pCVar2 == (CSystemFidsDrive *)0x0) {
      pCVar2 = (CSystemFidsDrive *)0x0;
    }
    else {
      pCVar3 = (CFastStringInt *)0x41dde7;
      CSystemFidsDrive::CSystemFidsDrive(pCVar2,pCVar1);
      pCVar2 = extraout_EAX_00;
    }
    puStack_8 = (undefined1 *)0xffffffff;
    *(CSystemFidsDrive **)(this + 0x2c) = pCVar2;
    CSystemFidsDrive::SetDriveName(pCVar2,(CSystemFidsDrive *)param_2,pCVar3);
  }
  if (*(int *)param_3 != 0) {
    if (*(int **)(this + 0x28) != (int *)0x0) {
      (**(code **)(**(int **)(this + 0x28) + 4))(1);
    }
    pCVar3 = (CFastStringInt *)0x48;
    pCVar2 = operator_new(0x48);
    uStack_4 = 2;
    if (pCVar2 == (CSystemFidsDrive *)0x0) {
      pCVar2 = (CSystemFidsDrive *)0x0;
    }
    else {
      pCVar3 = (CFastStringInt *)0x41de34;
      CSystemFidsDrive::CSystemFidsDrive(pCVar2,pCVar1);
      pCVar2 = extraout_EAX_01;
    }
    puStack_8 = (undefined1 *)0xffffffff;
    *(CSystemFidsDrive **)(this + 0x28) = pCVar2;
    CSystemFidsDrive::SetDriveName(pCVar2,(CSystemFidsDrive *)param_3,pCVar3);
    CSystemEngine__CheckCorruptedFiles((CSystemFids *)pCVar1);
  }
  if (*(int *)param_4 != 0) {
    if (*(int **)(this + 0x30) != (int *)0x0) {
      (**(code **)(**(int **)(this + 0x30) + 4))(1);
    }
    pCVar3 = (CFastStringInt *)0x48;
    pCVar2 = operator_new(0x48);
    uStack_4 = 3;
    if (pCVar2 == (CSystemFidsDrive *)0x0) {
      pCVar2 = (CSystemFidsDrive *)0x0;
    }
    else {
      pCVar3 = (CFastStringInt *)0x41de89;
      CSystemFidsDrive::CSystemFidsDrive(pCVar2,pCVar1);
      pCVar2 = extraout_EAX_02;
    }
    puStack_8 = (undefined1 *)0xffffffff;
    *(CSystemFidsDrive **)(this + 0x30) = pCVar2;
    CSystemFidsDrive::SetDriveName(pCVar2,(CSystemFidsDrive *)param_4,pCVar3);
    CSystemEngine__CheckCorruptedFiles((CSystemFids *)pCVar1);
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CSystemEngine::SetLocationDataShortName
// =================================================
void __thiscall
CSystemEngine::SetLocationDataShortName
          (CSystemEngine *this,CSystemEngine *param_1,CFastStringInt *param_2)
{
{
  CSystemFids *pCVar1;
  int unaff_ESI;
  
  pCVar1 = CSystemFids::FindOrAddLocationDown
                     (*(CSystemFids **)(this + 0x2c),(CSystemFids *)param_1,(CFastStringInt *)0x0,
                      (ulong *)0x0,unaff_ESI);
  *(CSystemFids **)(this + 0x50) = pCVar1;
  return;
}
}

// =================================================
// Function: CSystemEngine::Sleep
// =================================================
void __thiscall CSystemEngine::Sleep(CSystemEngine *this,CMwCmdBlock *param_1,ulong param_2)
{
{
  if (param_2 != 0) {
    SleepEx((DWORD)param_1,1);
    return;
  }
  ::Sleep((DWORD)param_1);
  return;
}
}

// =================================================
// Function: CSystemEngine::UnbindFid
// =================================================
void __thiscall CSystemEngine::UnbindFid(CSystemEngine *this,CSystemEngine *param_1,CMwNod *param_2)
{
{
  CSystemFid *unaff_retaddr;
  
  if ((param_1 != (CSystemEngine *)0x0) && (*(CMwNod **)(param_1 + 8) != (CMwNod *)0x0)) {
    UnbindFidNod(this,param_1,*(CMwNod **)(param_1 + 8),unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CSystemEngine::UnbindFidNod
// =================================================
void __thiscall
CSystemEngine::UnbindFidNod
          (CSystemEngine *this,CSystemEngine *param_1,CMwNod *param_2,CSystemFid *param_3)
{
{
  CMwNod *unaff_retaddr;
  
  if ((param_1 != (CSystemEngine *)0x0) && (param_2 != (CMwNod *)0x0)) {
    CSystemFid::DetachNod((CSystemFid *)param_2,(CSystemFid *)param_1,unaff_retaddr);
  }
  return;
}
}

