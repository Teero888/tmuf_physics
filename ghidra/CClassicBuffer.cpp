
/* public: virtual void * __thiscall CClassicBuffer::`scalar deleting destructor'(unsigned int) */

void *__thiscall CClassicBuffer::`scalar_deleting_destructor'(CClassicBuffer *this,uint param_1)

{
  ~CClassicBuffer(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* public: void __thiscall CClassicBuffer::AddCompressedBlock(class CClassicBufferMemory const &) */

void __thiscall CClassicBuffer::AddCompressedBlock(CClassicBuffer *this, CClassicBufferMemory *param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined4 unaff_ESI;
  uint uStack_1000c;
  byte *pbStack_10008;
  byte *pbStack_10004;
  undefined local_10000[65532];
  undefined4 uStack_4;

  uStack_4 = 0x90886a;
  uStack_1000c = *(uint *)(param_1 + 0x10);
  pbVar1 = (byte *)((uStack_1000c >> 6) + 0x13 + uStack_1000c);
  pbVar2 = (byte *)operator_new[]((uint)pbVar1);
  pbStack_10004 = pbVar1;
  _lzo1x_1_compress(*(short **)(param_1 + 0xc), uStack_1000c, pbVar2, &pbStack_10004, (int)local_10000);
  pbStack_10008 = pbStack_10004;
  (**(code **)(*(int *)this + 8))(&uStack_1000c, 4);
  (**(code **)(*(int *)this + 8))(&stack0xfffefff0, 4);
  (**(code **)(*(int *)this + 8))(pbVar2, unaff_ESI);
  operator_delete[](pbVar2);
  return;
}

/* public: __thiscall CClassicBuffer::CClassicBuffer(void) */

void __thiscall CClassicBuffer::CClassicBuffer(CClassicBuffer *this)

{
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* public: int __thiscall CClassicBuffer::CopyFrom(class CClassicBuffer *) */

int __thiscall CClassicBuffer::CopyFrom(CClassicBuffer *this, CClassicBuffer *param_1)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  undefined auStack_1004[4096];
  uint local_4;

  local_4 = ___security_cookie ^ (uint)auStack_1004;
  for (uVar1 = (**(code **)(*(int *)param_1 + 0x18))(); 0 < (int)uVar1; uVar1 = uVar1 - uVar3) {
    uVar3 = 0x1000;
    if ((int)uVar1 < 0x1001) {
      uVar3 = uVar1;
    }
    iVar2 = ReadAll(param_1, auStack_1004, uVar3);
    if ((iVar2 == 0) || (iVar2 = WriteAll(this, auStack_1004, uVar3), iVar2 == 0))
      break;
  }
  iVar2 = @__security_check_cookie @4(local_4 ^ (uint)auStack_1004);
  return iVar2;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class CClassicBufferMemory * __thiscall CClassicBuffer::CreateUncompressedBlock(void) */

CClassicBufferMemory *__thiscall CClassicBuffer::CreateUncompressedBlock(CClassicBuffer *this)

{
  int iVar1;
  CFastString *pCVar2;
  undefined4 *this_00;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  CFastString *local_24;
  CClassicBufferMemory *local_20;
  ulong local_1c;
  CFastString *local_18;
  SLadderResult local_14[8];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae1b90;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = ReadAll(this, &local_24, 4);
  if (iVar1 == 0) {
    ExceptionList = local_c;
    return (CClassicBufferMemory *)0x0;
  }
  iVar1 = ReadAll(this, &local_1c, 4);
  if (iVar1 == 0) {
    ExceptionList = local_c;
    return (CClassicBufferMemory *)0x0;
  }
  if ((CFastString *)0xfffffff < local_24) {
    if (_s_LogStringToAdd != 0) {
      _s_LogStringToAdd = 0;
      *DAT_00d71e58 = 0;
    }
    pcVar5 = "\r\n";
    pcVar4 = ")";
    pcVar3 = ", ";
    pCVar2 = CFastString::operator<<(&CClassicLog::s_LogStringToAdd,
                                     "[CrashInfo] Corrupted compressed Block? (size = ");
    pCVar2 = CFastString::operator<<(pCVar2, (ulong)local_24);
    pCVar2 = CFastString::operator<<(pCVar2, pcVar3);
    pCVar2 = CFastString::operator<<(pCVar2, local_1c);
    pCVar2 = CFastString::operator<<(pCVar2, pcVar4);
    CFastString::operator<<(pCVar2, pcVar5);
    CClassicLog::AddLogStringInFile();
    ExceptionList = local_c;
    return (CClassicBufferMemory *)0x0;
  }
  this_00 = (undefined4 *)sBufferMemoryGetNew();
  CClassicBufferMemory::PreAlloc((CClassicBufferMemory *)this_00, (ulong)local_24);
  CClassicBufferRef::CClassicBufferRef((CClassicBufferRef *)&local_20);
  local_4 = 0;
  CClassicBufferMemory::PreAlloc(local_20, local_1c);
  CClassicBufferMemory::Empty(local_20);
  iVar1 = ReadAll(this, *(void **)(local_20 + 0xc), local_1c);
  if (iVar1 == 0) {
    CGameMasterServer::SLadderResult::SLadderResult(local_14);
    local_4 = CONCAT31(local_4._1_3_, 1);
    CFastString::Format(local_24, (char *)local_14,
                        "[CrashInfo] Could not read all compressed data. (CompressedSize = %d, Uncom pressedSize=%d)", local_1c, local_24);
    if (_s_LogStringToAdd != 0) {
      _s_LogStringToAdd = 0;
      *DAT_00d71e58 = 0;
    }
    pcVar3 = "\r\n";
    pCVar2 = CFastString::operator<<(&CClassicLog::s_LogStringToAdd, (CFastString *)local_14);
    CFastString::operator<<(pCVar2, pcVar3);
    CClassicLog::AddLogStringInFile();
    if (this_00 != (undefined4 *)0x0) {
      (**(code **)*this_00)(1);
    }
    local_4 = local_4 & 0xffffff00;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity((SHeaderCommunity *)local_14);
    goto LAB_00908ff1;
  }
  *(ulong *)(local_20 + 0x10) = local_1c;
  local_18 = local_24;
  iVar1 = _lzo1x_decompress_safe(*(undefined4 **)(local_20 + 0xc), *(int *)(local_20 + 0x10),
                                 (undefined4 *)this_00[3], (byte **)&local_18);
  if (iVar1 == 0) {
    if (local_18 <= local_24) {
      this_00[4] = local_18;
      local_4 = 0xffffffff;
      CClassicBufferRef::~CClassicBufferRef((CClassicBufferRef *)&local_20);
      ExceptionList = local_c;
      return (CClassicBufferMemory *)this_00;
    }
  LAB_00908f7a:
    CGameMasterServer::SLadderResult::SLadderResult(local_14);
    local_4._0_1_ = 3;
    CFastString::Format((CFastString *)local_14,(char *)(CFastString *)local_14,
                        s_[CrashInfo]_Donn_es_corrompues?_,local_18,local_24);
    if (_s_LogStringToAdd != 0) {
      _s_LogStringToAdd = 0;
      *DAT_00d71e58 = 0;
    }
    pcVar3 = "\r\n";
    pCVar2 = CFastString::operator<<(&CClassicLog::s_LogStringToAdd, (CFastString *)local_14);
    CFastString::operator<<(pCVar2, pcVar3);
    CClassicLog::AddLogStringInFile();
    local_4 = (uint)local_4._1_3_ << 8;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity((SHeaderCommunity *)local_14);
  } else {
    CGameMasterServer::SLadderResult::SLadderResult(local_14);
    local_4._0_1_ = 2;
    CFastString::Format((CFastString *)local_14,(char *)(CFastString *)local_14,
                        s_[CrashInfo]_Donn_es_corrompues?_,iVar1);
    if (_s_LogStringToAdd != 0) {
      _s_LogStringToAdd = 0;
      *DAT_00d71e58 = 0;
    }
    pcVar3 = "\r\n";
    pCVar2 = CFastString::operator<<(&CClassicLog::s_LogStringToAdd, (CFastString *)local_14);
    CFastString::operator<<(pCVar2, pcVar3);
    CClassicLog::AddLogStringInFile();
    local_4 = (uint)local_4._1_3_ << 8;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity((SHeaderCommunity *)local_14);
    if (local_24 < local_18)
      goto LAB_00908f7a;
  }
  (**(code **)*this_00)(1);
LAB_00908ff1:
  local_4 = 0xffffffff;
  CClassicBufferRef::~CClassicBufferRef((CClassicBufferRef *)&local_20);
  ExceptionList = local_c;
  return (CClassicBufferMemory *)0x0;
}

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* public: int __thiscall CClassicBuffer::IsEqualBuffer(class CClassicBuffer &) */

int __thiscall CClassicBuffer::IsEqualBuffer(CClassicBuffer *this, CClassicBuffer *param_1)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  CClassicBuffer *local_200c;
  CClassicBuffer *local_2008;
  undefined4 uStack_2004;
  undefined4 uStack_1004;
  uint local_4;

  local_4 = ___security_cookie ^ (uint)&local_200c;
  local_2008 = param_1;
  local_200c = this;
  uVar1 = (**(code **)(*(int *)this + 0x18))();
  uVar2 = (**(code **)(*(int *)param_1 + 0x18))();
  if (uVar2 == uVar1) {
    iVar5 = (**(code **)(*(int *)this + 0x14))();
    if (iVar5 != 0) {
      iVar5 = (**(code **)(*(int *)this + 0x1c))();
      if (iVar5 == 0)
        goto LAB_00908c25;
      (**(code **)(*(int *)this + 0x20))(0);
    }
    iVar5 = (**(code **)(*(int *)param_1 + 0x14))();
    if (iVar5 != 0) {
      iVar5 = (**(code **)(*(int *)param_1 + 0x1c))();
      if (iVar5 == 0)
        goto LAB_00908c25;
      (**(code **)(*(int *)param_1 + 0x20))(0);
    }
    for (; 0 < (int)uVar1; uVar1 = uVar1 - uVar2) {
      uVar2 = 0x1000;
      if ((int)uVar1 < 0x1001) {
        uVar2 = uVar1;
      }
      iVar5 = ReadAll(this, &uStack_1004, uVar2);
      if ((iVar5 == 0) || (iVar5 = ReadAll(local_2008, &uStack_2004, uVar2), iVar5 == 0))
        break;
      piVar6 = &uStack_2004;
      piVar7 = &uStack_1004;
      for (uVar3 = uVar2; 3 < uVar3; uVar3 = uVar3 - 4) {
        if (*piVar7 != *piVar6)
          goto LAB_00908baa;
        piVar6 = piVar6 + 1;
        piVar7 = piVar7 + 1;
      }
      if (uVar3 == 0) {
      LAB_00908c0f:
        iVar4 = 0;
      } else {
      LAB_00908baa:
        iVar5 = (uint) * (byte *)piVar7 - (uint) * (byte *)piVar6;
        this = local_200c;
        if (iVar5 == 0) {
          if (uVar3 == 1)
            goto LAB_00908c0f;
          iVar5 = (uint) * (byte *)((int)piVar7 + 1) - (uint) * (byte *)((int)piVar6 + 1);
          if (iVar5 == 0) {
            if (uVar3 == 2)
              goto LAB_00908c0f;
            iVar5 = (uint) * (byte *)((int)piVar7 + 2) - (uint) * (byte *)((int)piVar6 + 2);
            if (iVar5 == 0) {
              if ((uVar3 == 3) ||
                  (iVar5 = (uint) * (byte *)((int)piVar7 + 3) - (uint) * (byte *)((int)piVar6 + 3),
                   iVar5 == 0))
                goto LAB_00908c0f;
            }
          }
        }
        iVar4 = 1;
        if (iVar5 < 1) {
          iVar4 = -1;
        }
      }
      if (iVar4 != 0)
        break;
    }
  }
LAB_00908c25:
  iVar5 = @__security_check_cookie @4(local_4 ^ (uint)&local_200c);
  return iVar5;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall CClassicBuffer::ReadAll(void *,unsigned long) */

int __thiscall CClassicBuffer::ReadAll(CClassicBuffer *this, void *param_1, ulong param_2)

{
  int iVar1;
  CFastString *pCVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;

  iVar3 = 0;
  do {
    iVar1 = (**(code **)(*(int *)this + 4))(iVar3 + (int)param_1, param_2);
    if (iVar1 == 0) {
      if (_s_LogStringToAdd != 0) {
        _s_LogStringToAdd = 0;
        *DAT_00d71e58 = 0;
      }
      pcVar5 = "\r\n";
      pcVar4 = " bytes.";
      pCVar2 = CFastString::operator<<(&CClassicLog::s_LogStringToAdd, "[CrashInfo] ReadAll failed, missing ");
      pCVar2 = CFastString::operator<<(pCVar2, param_2);
      pCVar2 = CFastString::operator<<(pCVar2, pcVar4);
      CFastString::operator<<(pCVar2, pcVar5);
      CClassicLog::AddLogStringInFile();
      return 0;
    }
    param_2 = param_2 - iVar1;
    iVar3 = iVar3 + iVar1;
  } while (0 < (int)param_2);
  return 1;
}

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* public: unsigned long __thiscall CClassicBuffer::Skip(unsigned long) */

ulong __thiscall CClassicBuffer::Skip(CClassicBuffer *this, ulong param_1)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  undefined auStack_1004[4096];
  uint local_4;

  local_4 = ___security_cookie ^ (uint)auStack_1004;
  iVar1 = (**(code **)(*(int *)this + 0x1c))();
  if (iVar1 == 0) {
    if (param_1 != 0) {
      do {
        uVar2 = param_1;
        if (0xfff < param_1) {
          uVar2 = 0x1000;
        }
        iVar1 = (**(code **)(*(int *)this + 4))(auStack_1004, uVar2);
        param_1 = param_1 - iVar1;
      } while ((iVar1 != 0) && (param_1 != 0));
    }
  } else {
    iVar1 = (**(code **)(*(int *)this + 0x14))();
    (**(code **)(*(int *)this + 0x20))(iVar1 + param_1);
    (**(code **)(*(int *)this + 0x14))();
  }
  uVar3 = @__security_check_cookie @4(local_4 ^ (uint)auStack_1004);
  return uVar3;
}

/* public: int __thiscall CClassicBuffer::WriteAll(void const *,unsigned long) */

int __thiscall CClassicBuffer::WriteAll(CClassicBuffer *this, void *param_1, ulong param_2)

{
  int iVar1;
  int iVar2;

  iVar2 = 0;
  do {
    iVar1 = (**(code **)(*(int *)this + 8))(iVar2 + (int)param_1, param_2);
    if (iVar1 == 0) {
      return 0;
    }
    param_2 = param_2 - iVar1;
    iVar2 = iVar2 + iVar1;
  } while (0 < (int)param_2);
  return 1;
}

/* public: virtual __thiscall CClassicBuffer::~CClassicBuffer(void) */

void __thiscall CClassicBuffer::~CClassicBuffer(CClassicBuffer *this)

{
  *(undefined ***)this = vftable;
  return;
}
