// Class implementation: CClassicBuffer

// =================================================
// Function: CClassicBuffer::AddCompressedBlock
// =================================================
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall
CClassicBuffer::AddCompressedBlock
          (CClassicBuffer *this,CClassicBuffer *param_1,CClassicBufferMemory *param_2)
{
{
  uint uVar1;
  void *pvVar2;
  undefined4 unaff_ESI;
  uint uStack_1000c;
  uint uStack_10008;
  uint uStack_10004;
  
  uStack_1000c = *(uint *)(param_1 + 0x10);
  uVar1 = (uStack_1000c >> 6) + 0x13 + uStack_1000c;
  pvVar2 = operator_new__(uVar1);
  uStack_10004 = uVar1;
  lzo1x_1_compress();
  uStack_10008 = uStack_10004;
  (**(code **)(*(int *)this + 8))(&uStack_1000c,4);
  (**(code **)(*(int *)this + 8))(&stack0xfffefff0,4);
  (**(code **)(*(int *)this + 8))(pvVar2,unaff_ESI);
  operator_delete__(pvVar2);
  return;
}
}

// =================================================
// Function: CClassicBuffer::CClassicBuffer
// =================================================
void __thiscall CClassicBuffer::CClassicBuffer(CClassicBuffer *this,CClassicBuffer *param_1)
{
{
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}
}

// =================================================
// Function: CClassicBuffer::CopyFrom
// =================================================
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall CClassicBuffer::CopyFrom(CClassicBuffer *this,SParam_Set *param_1,SParam *param_2)
{
{
  void *pvVar1;
  int iVar2;
  ulong unaff_ESI;
  void *unaff_EDI;
  void *pvVar3;
  CClassicBuffer aCStack_1004 [4];
  CClassicBuffer aCStack_1000 [4092];
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)aCStack_1004;
  pvVar1 = (void *)(**(code **)(*(int *)param_1 + 0x18))();
  while( true ) {
    if ((int)pvVar1 < 1) {
      return;
    }
    pvVar3 = (void *)0x1000;
    if ((int)pvVar1 < 0x1001) {
      pvVar3 = pvVar1;
    }
    iVar2 = ReadAll((CClassicBuffer *)param_1,aCStack_1004,pvVar3,(ulong)unaff_EDI);
    if (iVar2 == 0) break;
    unaff_EDI = pvVar3;
    iVar2 = WriteAll(this,aCStack_1000,pvVar3,unaff_ESI);
    if (iVar2 == 0) {
      return;
    }
    pvVar1 = (void *)((int)pvVar1 - (int)pvVar3);
  }
  return;
}
}

// =================================================
// Function: CClassicBuffer::CreateUncompressedBlock
// =================================================
CClassicBufferMemory * __thiscall
CClassicBuffer::CreateUncompressedBlock(CClassicBuffer *this,CClassicBuffer *param_1)
{
{
  int iVar1;
  CPlugFileGpuBuilder *pCVar2;
  CClassicBufferMemory *this_00;
  int extraout_EAX;
  CClassicBufferRef *unaff_EBX;
  CPlugFileGpuBuilder *unaff_ESI;
  ulong unaff_EDI;
  SLadderResult *unaff_retaddr;
  LPCSTR *in_stack_00000008;
  char *in_stack_00000010;
  SHeaderCommunity *in_stack_00000014;
  undefined4 uStack00000018;
  char *in_stack_0000001c;
  void *in_stack_0000002c;
  undefined4 uStack00000030;
  undefined1 in_stack_00000034;
  undefined1 in_stack_00000044;
  CPlugFileGpuBuilder *pCVar3;
  CPlugFileGpuBuilder *pCVar4;
  LPCSTR *ppCVar5;
  CPlugFileGpuBuilder *in_stack_ffffffdc;
  CClassicBufferMemory *in_stack_ffffffe0;
  CPlugFileGpuBuilder *in_stack_ffffffe4;
  SLadderResult *in_stack_ffffffe8;
  char *in_stack_ffffffec;
  CClassicBufferMemory *in_stack_fffffff0;
  char *pcVar6;
  char *pcVar7;
  SHeaderCommunity *this_01;
  
  this_01 = (SHeaderCommunity *)0xffffffff;
  pcVar6 = &DAT_00ae1b90;
  pCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  iVar1 = ReadAll(this,(CClassicBuffer *)&stack0xffffffdc,&DAT_00000004,
                  DAT_00cca150 ^ (uint)&stack0xffffffd0);
  if (iVar1 == 0) {
    ExceptionList = in_stack_0000002c;
    return (CClassicBufferMemory *)0x0;
  }
  iVar1 = ReadAll(this,(CClassicBuffer *)&stack0xffffffe8,&DAT_00000004,unaff_EDI);
  if (iVar1 == 0) {
    ExceptionList = in_stack_0000002c;
    return (CClassicBufferMemory *)0x0;
  }
  if ((CPlugFileGpuBuilder *)0xfffffff < in_stack_ffffffe4) {
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    ppCVar5 = &lpOutputString_00b2bcc4;
    pCVar4 = (CPlugFileGpuBuilder *)&DAT_00b30988;
    pCVar3 = (CPlugFileGpuBuilder *)&DAT_00b4905c;
    pCVar2 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,
                        (CPlugFileGpuBuilder *)"[CrashInfo] Corrupted compressed Block? (size = ",
                        (char *)in_stack_ffffffe4);
    pCVar2 = CFastString::operator<<((CFastString *)pCVar2,pCVar3,in_stack_ffffffec);
    pCVar2 = CFastString::operator<<((CFastString *)pCVar2,pCVar4,(char *)ppCVar5);
    pCVar2 = CFastString::operator<<((CFastString *)pCVar2,unaff_ESI,(char *)unaff_EBX);
    pCVar2 = CFastString::operator<<
                       ((CFastString *)pCVar2,in_stack_ffffffdc,(char *)in_stack_ffffffe0);
    CFastString::operator<<((CFastString *)pCVar2,in_stack_ffffffe4,(char *)in_stack_ffffffe8);
    CClassicLog::AddLogStringInFile();
    ExceptionList = in_stack_00000014;
    return (CClassicBufferMemory *)0x0;
  }
  this_00 = sBufferMemoryGetNew();
  CClassicBufferMemory::PreAlloc(this_00,(CClassicBufferMemory *)in_stack_ffffffe4,(ulong)unaff_ESI)
  ;
  CClassicBufferRef::CClassicBufferRef(&stack0xffffffec,unaff_EBX);
  pCVar3 = (CPlugFileGpuBuilder *)0x0;
  CClassicBufferMemory::PreAlloc
            (in_stack_fffffff0,(CClassicBufferMemory *)pCVar2,(ulong)in_stack_ffffffdc);
  CClassicBufferMemory::Empty((CClassicBufferMemory *)pCVar2,in_stack_ffffffe0);
  iVar1 = ReadAll(this,*(CClassicBuffer **)(pcVar6 + 0xc),this_01,(ulong)in_stack_ffffffe4);
  if (iVar1 == 0) {
    CGameMasterServer::SLadderResult::SLadderResult(&stack0x00000008,in_stack_ffffffe8);
    in_stack_0000001c = (char *)CONCAT31(in_stack_0000001c._1_3_,1);
    CFastString::Format((CFastString *)this_01,(CFastString *)&stack0x0000000c,
                        "[CrashInfo] Could not read all compressed data. (CompressedSize = %d, UncompressedSize=%d)"
                       );
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar3 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)&stack0x00000014,
                        (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)pCVar3,pCVar2,pcVar6);
    CClassicLog::AddLogStringInFile();
    if (this_00 != (CClassicBufferMemory *)0x0) {
      (*(code *)**(undefined4 **)this_00)();
    }
    in_stack_0000002c = (void *)((uint)in_stack_0000002c & 0xffffff00);
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0x0000001c,this_01);
    goto LAB_00908ff1;
  }
  *(SLadderResult **)(this_01 + 0x10) = unaff_retaddr;
  pcVar7 = pcVar6;
  lzo1x_decompress_safe();
  if (extraout_EAX == 0) {
    if (pcVar6 <= pcVar7) {
      *(char **)(this_00 + 0x10) = pcVar6;
      uStack00000018 = 0xffffffff;
      CClassicBufferRef::~CClassicBufferRef(&stack0xfffffffc,(CClassicBufferRef *)in_stack_ffffffe8)
      ;
      ExceptionList = in_stack_00000014;
      return this_00;
    }
LAB_00908f7a:
    CGameMasterServer::SLadderResult::SLadderResult(&stack0x00000020,unaff_retaddr);
    in_stack_00000034 = 3;
    CFastString::Format((CFastString *)&stack0x00000024,(CFastString *)&stack0x00000024,
                        &DAT_00bbfa40);
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    in_stack_00000008 = &lpOutputString_00b2bcc4;
    unaff_retaddr = (SLadderResult *)0x908fce;
    pCVar2 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)&stack0x0000002c,
                        (char *)&lpOutputString_00b2bcc4);
    in_stack_00000008 = (LPCSTR *)0x908fd5;
    CFastString::operator<<((CFastString *)pCVar2,pCVar3,in_stack_00000010);
    in_stack_00000010 = (char *)0x908fda;
    CClassicLog::AddLogStringInFile();
    in_stack_00000044 = 0;
    in_stack_00000010 = (char *)0x908fe7;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0x00000034,in_stack_00000014);
  }
  else {
    CGameMasterServer::SLadderResult::SLadderResult(&stack0x00000008,in_stack_ffffffe8);
    in_stack_0000001c = (char *)CONCAT31(in_stack_0000001c._1_3_,2);
    CFastString::Format((CFastString *)&stack0x0000000c,(CFastString *)&stack0x0000000c,
                        &DAT_00bbfa94);
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar4 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)&stack0x00000014,
                        (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)pCVar4,pCVar2,pcVar7);
    CClassicLog::AddLogStringInFile();
    in_stack_0000002c = (void *)((uint)in_stack_0000002c & 0xffffff00);
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0x0000001c,this_01);
    if (in_stack_00000010 < in_stack_0000001c) goto LAB_00908f7a;
  }
  (*(code *)**(undefined4 **)this_00)();
LAB_00908ff1:
  uStack00000030 = 0xffffffff;
  CClassicBufferRef::~CClassicBufferRef(&stack0x00000014,(CClassicBufferRef *)unaff_retaddr);
  ExceptionList = in_stack_0000002c;
  return (CClassicBufferMemory *)0x0;
}
}

// =================================================
// Function: CClassicBuffer::IsEqualBuffer
// =================================================
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall
CClassicBuffer::IsEqualBuffer
          (CClassicBuffer *this,CClassicBufferMemory *param_1,CClassicBufferMemory *param_2)
{
{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  void *unaff_EBX;
  ulong in_stack_ffffdfe0;
  CClassicBuffer *local_200c;
  CClassicBufferMemory *local_2008;
  byte abStack_2004 [4088];
  CClassicBuffer aCStack_100c [8];
  byte abStack_1004 [4096];
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)&local_200c;
  local_2008 = param_1;
  local_200c = this;
  pvVar1 = (void *)(**(code **)(*(int *)this + 0x18))();
  pvVar2 = (void *)(**(code **)(*(int *)param_1 + 0x18))();
  if (pvVar2 == pvVar1) {
    iVar3 = (**(code **)(*(int *)this + 0x14))();
    if (iVar3 != 0) {
      iVar3 = (**(code **)(*(int *)this + 0x1c))();
      if (iVar3 == 0) goto LAB_00908ae3;
      in_stack_ffffdfe0 = 0x908b12;
      (**(code **)(*(int *)this + 0x20))(0);
    }
    iVar3 = (**(code **)(*(int *)param_1 + 0x14))();
    if (iVar3 != 0) {
      iVar3 = (**(code **)(*(int *)param_1 + 0x1c))();
      if (iVar3 == 0) goto LAB_00908ae3;
      in_stack_ffffdfe0 = 0x908b37;
      (**(code **)(*(int *)param_1 + 0x20))(0);
    }
    for (; 0 < (int)pvVar1; pvVar1 = (void *)((int)pvVar1 - (int)pvVar2)) {
      pvVar2 = (void *)0x1000;
      if ((int)pvVar1 < 0x1001) {
        pvVar2 = pvVar1;
      }
      iVar3 = ReadAll(this,aCStack_100c,pvVar2,(ulong)unaff_EBX);
      if (iVar3 == 0) {
        return 0;
      }
      unaff_EBX = pvVar2;
      iVar3 = ReadAll(local_200c,(CClassicBuffer *)&local_2008,pvVar2,in_stack_ffffdfe0);
      if (iVar3 == 0) {
        return 0;
      }
      pbVar6 = abStack_2004;
      pbVar7 = abStack_1004;
      for (pvVar4 = pvVar2; (void *)0x3 < pvVar4; pvVar4 = (void *)((int)pvVar4 - 4)) {
        if (*(int *)pbVar7 != *(int *)pbVar6) goto LAB_00908baa;
        pbVar6 = pbVar6 + 4;
        pbVar7 = pbVar7 + 4;
      }
      if (pvVar4 == (void *)0x0) {
LAB_00908c0f:
        iVar5 = 0;
      }
      else {
LAB_00908baa:
        iVar3 = (uint)*pbVar7 - (uint)*pbVar6;
        this = local_200c;
        if (iVar3 == 0) {
          if (pvVar4 == (void *)0x1) goto LAB_00908c0f;
          iVar3 = (uint)pbVar7[1] - (uint)pbVar6[1];
          if (iVar3 == 0) {
            if (pvVar4 == (void *)0x2) goto LAB_00908c0f;
            iVar3 = (uint)pbVar7[2] - (uint)pbVar6[2];
            if (iVar3 == 0) {
              if ((pvVar4 == (void *)0x3) || (iVar3 = (uint)pbVar7[3] - (uint)pbVar6[3], iVar3 == 0)
                 ) goto LAB_00908c0f;
            }
          }
        }
        iVar5 = 1;
        if (iVar3 < 1) {
          iVar5 = -1;
        }
      }
      if (iVar5 != 0) {
        return 0;
      }
    }
    iVar3 = 1;
  }
  else {
LAB_00908ae3:
    iVar3 = 0;
  }
  return iVar3;
}
}

// =================================================
// Function: CClassicBuffer::ReadAll
// =================================================
int __thiscall
CClassicBuffer::ReadAll(CClassicBuffer *this,CClassicBuffer *param_1,void *param_2,ulong param_3)
{
{
  int iVar1;
  CPlugFileGpuBuilder *pCVar2;
  char *unaff_EBX;
  CPlugFileGpuBuilder *unaff_EBP;
  char *unaff_ESI;
  CPlugFileGpuBuilder *unaff_EDI;
  int iVar3;
  char *pcVar4;
  LPCSTR *ppCVar5;
  
  iVar3 = 0;
  do {
    iVar1 = (**(code **)(*(int *)this + 4))(param_1 + iVar3,param_2);
    if (iVar1 == 0) {
      if (DAT_00d71e54 != 0) {
        DAT_00d71e54 = 0;
        *DAT_00d71e58 = 0;
      }
      ppCVar5 = &lpOutputString_00b2bcc4;
      pcVar4 = " bytes.";
      pCVar2 = CFastString::operator<<
                         ((CFastString *)&DAT_00d71e54,
                          (CPlugFileGpuBuilder *)"[CrashInfo] ReadAll failed, missing ",param_2);
      pCVar2 = CFastString::operator<<
                         ((CFastString *)pCVar2,(CPlugFileGpuBuilder *)pcVar4,(char *)ppCVar5);
      pCVar2 = CFastString::operator<<((CFastString *)pCVar2,unaff_EDI,unaff_ESI);
      CFastString::operator<<((CFastString *)pCVar2,unaff_EBP,unaff_EBX);
      CClassicLog::AddLogStringInFile();
      return 0;
    }
    param_2 = (void *)((int)param_2 + -iVar1);
    iVar3 = iVar3 + iVar1;
  } while (0 < (int)param_2);
  return 1;
}
}

// =================================================
// Function: CClassicBuffer::Skip
// =================================================
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulong __thiscall CClassicBuffer::Skip(CClassicBuffer *this,CClassicBuffer *param_1,ulong param_2)
{
{
  int iVar1;
  CClassicBuffer *pCVar2;
  CClassicBuffer *pCVar3;
  undefined1 auStack_1004 [4096];
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)auStack_1004;
  iVar1 = (**(code **)(*(int *)this + 0x1c))();
  pCVar2 = param_1;
  if (iVar1 == 0) {
    do {
      if (pCVar2 == (CClassicBuffer *)0x0) break;
      pCVar3 = pCVar2;
      if ((CClassicBuffer *)0xfff < pCVar2) {
        pCVar3 = (CClassicBuffer *)0x1000;
      }
      iVar1 = (**(code **)(*(int *)this + 4))(auStack_1004,pCVar3);
      pCVar2 = pCVar2 + -iVar1;
    } while (iVar1 != 0);
  }
  else {
    pCVar2 = (CClassicBuffer *)(**(code **)(*(int *)this + 0x14))();
    (**(code **)(*(int *)this + 0x20))(pCVar2 + (int)param_1);
    param_1 = (CClassicBuffer *)(**(code **)(*(int *)this + 0x14))();
  }
  return (int)param_1 - (int)pCVar2;
}
}

// =================================================
// Function: CClassicBuffer::WriteAll
// =================================================
int __thiscall
CClassicBuffer::WriteAll(CClassicBuffer *this,CClassicBuffer *param_1,void *param_2,ulong param_3)
{
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(*(int *)this + 8))(param_1 + iVar2,param_2);
    if (iVar1 == 0) {
      return 0;
    }
    param_2 = (void *)((int)param_2 - iVar1);
    iVar2 = iVar2 + iVar1;
  } while (0 < (int)param_2);
  return 1;
}
}

// =================================================
// Function: CClassicBuffer::~CClassicBuffer
// =================================================
void __thiscall CClassicBuffer::~CClassicBuffer(CClassicBuffer *this,CClassicBuffer *param_1)
{
{
  *(undefined ***)this = vftable;
  return;
}
}

