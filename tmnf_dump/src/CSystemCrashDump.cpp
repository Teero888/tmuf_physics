// Class implementation: CSystemCrashDump

// =================================================
// Function: CSystemCrashDump::ContextPop
// =================================================
void __thiscall CSystemCrashDump::ContextPop(CSystemCrashDump *this,CSystemCrashDump *param_1)
{
{
  CSystemCrashDump *this_00;
  ulong uVar1;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = this + 0x1c;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (uVar1 != 0) {
    *(int *)this_00 = *(int *)this_00 + -1;
    *(uint *)(this + 0x28) = (uint)(*(int *)this_00 != 0);
  }
  return;
}
}

// =================================================
// Function: CSystemCrashDump::ContextPush
// =================================================
void __thiscall
CSystemCrashDump::ContextPush(CSystemCrashDump *this,CSystemCrashDump *param_1,char *param_2)
{
{
  SLoadedLight *this_00;
  int iVar1;
  SStringParam *unaff_ESI;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EDI;
  CPlugFileGpuBuilder *in_stack_0000000c;
  char *in_stack_fffffff8;
  undefined4 uStack_4;
  
  this_00 = CFastBuffer<class_CFastString>::AddNewElem(this + 0x1c,unaff_EDI);
  iVar1 = (**(code **)(*(int *)this + 0x10))();
  uStack_4 = *(undefined4 *)(iVar1 + 4);
  CFastString::SetString((CFastString *)this_00,(CFastStringInt *)&uStack_4,unaff_ESI);
  CFastString::operator<<((CFastString *)this_00,in_stack_0000000c,in_stack_fffffff8);
  *(undefined4 *)(this + 0x28) = 1;
  return;
}
}

// =================================================
// Function: CSystemCrashDump::IsValid
// =================================================
int __thiscall CSystemCrashDump::IsValid(CSystemCrashDump *this,CGameScoresVersion *param_1)
{
{
  int iVar1;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_00cca150 ^ 0xc680d8;
  ExceptionList = &local_14;
  local_8 = 0;
  iVar1 = CMwNod_MwCheckThisRelease((CMwNod *)param_1);
  ExceptionList = local_14;
  return iVar1;
}
}

// =================================================
// Function: CSystemCrashDump::IsValid_DumpFidAndMwId
// =================================================
int __thiscall
CSystemCrashDump::IsValid_DumpFidAndMwId
          (CSystemCrashDump *this,CSystemCrashDump *param_1,CFastString *param_2,char *param_3,
          CMwNod *param_4,int param_5)
{
{
  CSystemFidFile *this_00;
  int iVar1;
  CPlugFileGpuBuilder *pCVar2;
  void *this_01;
  int extraout_EAX;
  CPlugFileGpuBuilder *extraout_EAX_00;
  CPlugFileGpuBuilder *unaff_EBX;
  CFastString *unaff_ESI;
  CPlugFileGpuBuilder *unaff_EDI;
  CFastString *unaff_retaddr;
  CPlugFileGpuBuilder *in_stack_00000018;
  char *pcVar3;
  CPlugFileGpuBuilder *pCVar4;
  
  iVar1 = IsValid(this,(CGameScoresVersion *)param_3);
  if (iVar1 == 0) {
    if (param_4 != (CMwNod *)0x0) {
      (**(code **)(*(int *)this + 0x1c))(param_1);
    }
    pcVar3 = " pointer=";
    pCVar2 = CFastString::operator<<
                       ((CFastString *)param_1,(CPlugFileGpuBuilder *)"!! Invalid ",(char *)param_2)
    ;
    pCVar2 = CFastString::operator<<((CFastString *)pCVar2,(CPlugFileGpuBuilder *)pcVar3,param_3);
    pCVar2 = CFastString::operator<<((CFastString *)pCVar2,unaff_EDI,(char *)unaff_ESI);
    CFastString::operator<<((CFastString *)pCVar2,unaff_EBX,(char *)unaff_retaddr);
    return 0;
  }
  this_00 = *(CSystemFidFile **)(param_3 + 8);
  if (this_00 != (CSystemFidFile *)0x0) {
    iVar1 = (**(code **)(*(int *)this_00 + 0x10))(0xb00a000);
    if (iVar1 != 0) {
      pcVar3 = (char *)0x0;
      CSystemFidFile::GetFullName(this_00,(CPlugFile *)&DAT_00d554a0,(CFastStringInt *)0x0);
      if (param_3 != (char *)0x0) {
        (**(code **)(*(int *)this + 0x1c))(unaff_retaddr);
      }
      pCVar4 = (CPlugFileGpuBuilder *)&DAT_00d554a0;
      pCVar2 = CFastString::operator<<(unaff_retaddr,(CPlugFileGpuBuilder *)param_1,"=");
      pCVar2 = CFastString::operator<<((CFastString *)pCVar2,pCVar4,pcVar3);
      CFastString::operator<<((CFastString *)pCVar2,unaff_EDI,(char *)unaff_ESI);
      return 1;
    }
  }
  this_01 = (void *)(**(code **)(*(int *)param_3 + 0x14))();
  if (this_01 != (void *)0x0) {
    CMwId::GetString(this_01,(CMwStatsValue *)unaff_EDI,unaff_ESI);
    if (extraout_EAX != 0) {
      if (in_stack_00000018 != (CPlugFileGpuBuilder *)0x0) {
        (**(code **)(*(int *)this + 0x1c))(param_3);
      }
      CMwId::GetString(this_01,(CMwStatsValue *)unaff_EBX,unaff_retaddr);
      pCVar2 = extraout_EAX_00;
      pCVar4 = CFastString::operator<<((CFastString *)param_3,in_stack_00000018," MwId=");
      pCVar2 = CFastString::operator<<((CFastString *)pCVar4,pCVar2,(char *)param_1);
      CFastString::operator<<((CFastString *)pCVar2,(CPlugFileGpuBuilder *)param_2,param_3);
    }
  }
  return 1;
}
}

// =================================================
// Function: CSystemCrashDump::StringCatVec3
// =================================================
void __thiscall
CSystemCrashDump::StringCatVec3
          (CSystemCrashDump *this,CSystemCrashDump *param_1,CFastString *param_2,GmVec3 *param_3)
{
{
  CPlugFileGpuBuilder *pCVar1;
  char *unaff_retaddr;
  char *in_stack_00000010;
  CPlugFileGpuBuilder *in_stack_00000014;
  char *in_stack_00000018;
  CPlugFileGpuBuilder *pCVar2;
  char *pcVar3;
  CPlugFileGpuBuilder *pCVar4;
  char *pcVar5;
  CPlugFileGpuBuilder *pCVar6;
  
  pcVar5 = *(char **)(param_2 + 8);
  pCVar6 = (CPlugFileGpuBuilder *)&DAT_00b2fe1c;
  pCVar4 = (CPlugFileGpuBuilder *)&DAT_00b2fe18;
  pcVar3 = *(char **)(param_2 + 4);
  pCVar2 = (CPlugFileGpuBuilder *)&DAT_00b2fe18;
  pCVar1 = CFastString::operator<<
                     ((CFastString *)param_1,(CPlugFileGpuBuilder *)&DAT_00b2fe14,*(char **)param_2)
  ;
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,pCVar2,pcVar3);
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,pCVar4,pcVar5);
  pCVar1 = CFastString::operator<<((CFastString *)pCVar1,pCVar6,unaff_retaddr);
  pCVar1 = CFastString::operator<<
                     ((CFastString *)pCVar1,(CPlugFileGpuBuilder *)param_1,(char *)param_2);
  pCVar1 = CFastString::operator<<
                     ((CFastString *)pCVar1,(CPlugFileGpuBuilder *)param_3,in_stack_00000010);
  CFastString::operator<<((CFastString *)pCVar1,in_stack_00000014,in_stack_00000018);
  return;
}
}

