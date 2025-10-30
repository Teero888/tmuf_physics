
/* public: virtual void * __thiscall CClassicBufferMemory::`scalar deleting destructor'(unsigned
   int) */

void *__thiscall CClassicBufferMemory::`scalar_deleting_destructor'(CClassicBufferMemory *this,uint param_1)

{
  ~CClassicBufferMemory(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: virtual void __thiscall CClassicBufferMemory::AdvanceOffset(unsigned long) */

void __thiscall CClassicBufferMemory::AdvanceOffset(CClassicBufferMemory *this, ulong param_1)

{
  *(ulong *)(this + 0x14) = *(int *)(this + 0x14) + param_1;
  return;
}

/* public: void __thiscall CClassicBufferMemory::Attach(void *,unsigned long) */

void __thiscall CClassicBufferMemory::Attach(CClassicBufferMemory *this, void *param_1, ulong param_2)

{
  *(void **)(this + 0xc) = param_1;
  *(undefined4 *)(this + 0x14) = 0;
  *(ulong *)(this + 0x18) = param_2;
  *(ulong *)(this + 0x10) = param_2;
  *(uint *)(this + 0x1c) = (-(uint)(param_1 != (void *)0x0) & 0xffffffe0) + 0x20;
  return;
}

/* public: __thiscall CClassicBufferMemory::CClassicBufferMemory(void) */

CClassicBufferMemory *__thiscall CClassicBufferMemory::CClassicBufferMemory(CClassicBufferMemory *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae1bb8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CClassicBuffer::CClassicBuffer((CClassicBuffer *)this);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0x20;
  *(undefined4 *)(this + 4) = 3;
  ExceptionList = local_c;
  return this;
}

/* public: virtual int __thiscall CClassicBufferMemory::Close(void) */

int __thiscall CClassicBufferMemory::Close(CClassicBufferMemory *this)

{
  Reset(this);
  return 1;
}

/* public: void __thiscall CClassicBufferMemory::CopyAndDetachBufferMemory(class
   CClassicBufferMemory &) */

void __thiscall CClassicBufferMemory::CopyAndDetachBufferMemory(CClassicBufferMemory *this, CClassicBufferMemory *param_1)

{
  if (*(int *)(this + 0x1c) != 0) {
    operator_delete[](*(void **)(this + 0xc));
  }
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0x20;
  return;
}

/* public: void __thiscall CClassicBufferMemory::Empty(void) */

void __thiscall CClassicBufferMemory::Empty(CClassicBufferMemory *this)

{
  int extraout_ECX;

  Reset(this);
  *(undefined4 *)(extraout_ECX + 0x10) = 0;
  return;
}

/* public: void __thiscall CClassicBufferMemory::EmptyAndFreeMemory(void) */

void __thiscall CClassicBufferMemory::EmptyAndFreeMemory(CClassicBufferMemory *this)

{
  Empty(this);
  operator_delete[](*(void **)(this + 0xc));
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0x20;
  return;
}

/* public: virtual unsigned long __thiscall CClassicBufferMemory::GetActualSize(void)const  */

ulong __thiscall CClassicBufferMemory::GetActualSize(CClassicBufferMemory *this)

{
  return *(ulong *)(this + 0x10);
}

/* public: int __thiscall CClassicBufferMemory::IsEqualBuffer(class CClassicBufferMemory const
   &)const  */

int __thiscall CClassicBufferMemory::IsEqualBuffer(CClassicBufferMemory *this, CClassicBufferMemory *param_1)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;

  uVar2 = *(uint *)(this + 0x10);
  if (uVar2 != *(uint *)(param_1 + 0x10)) {
    return 0;
  }
  piVar4 = *(int **)(param_1 + 0xc);
  piVar3 = *(int **)(this + 0xc);
  for (; 3 < uVar2; uVar2 = uVar2 - 4) {
    if (*piVar3 != *piVar4)
      goto LAB_009092a8;
    piVar4 = piVar4 + 1;
    piVar3 = piVar3 + 1;
  }
  if (uVar2 == 0) {
  LAB_00909311:
    bVar1 = false;
  } else {
  LAB_009092a8:
    iVar5 = (uint) * (byte *)piVar3 - (uint) * (byte *)piVar4;
    if (iVar5 == 0) {
      if (uVar2 == 1)
        goto LAB_00909311;
      iVar5 = (uint) * (byte *)((int)piVar3 + 1) - (uint) * (byte *)((int)piVar4 + 1);
      if (iVar5 == 0) {
        if (uVar2 == 2)
          goto LAB_00909311;
        iVar5 = (uint) * (byte *)((int)piVar3 + 2) - (uint) * (byte *)((int)piVar4 + 2);
        if (iVar5 == 0) {
          if ((uVar2 == 3) ||
              (iVar5 = (uint) * (byte *)((int)piVar3 + 3) - (uint) * (byte *)((int)piVar4 + 3),
               iVar5 == 0))
            goto LAB_00909311;
        }
      }
    }
    bVar1 = true;
    if (iVar5 < 1) {
      return 0;
    }
  }
  return (uint)!bVar1;
}

/* public: void __thiscall CClassicBufferMemory::PreAlloc(unsigned long) */

void __thiscall CClassicBufferMemory::PreAlloc(CClassicBufferMemory *this, ulong param_1)

{
  void *_Dst;

  if (*(uint *)(this + 0x18) < param_1) {
    _Dst = operator_new[](param_1);
    _memcpy(_Dst, *(void **)(this + 0xc), *(size_t *)(this + 0x14));
    operator_delete[](*(void **)(this + 0xc));
    *(void **)(this + 0xc) = _Dst;
    *(ulong *)(this + 0x18) = param_1;
  }
  if (*(uint *)(this + 0x18) < *(uint *)(this + 0x1c)) {
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c);
    return;
  }
  *(uint *)(this + 0x1c) = *(uint *)(this + 0x18);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned long __thiscall CClassicBufferMemory::Read(void *,unsigned long) */

ulong __thiscall CClassicBufferMemory::Read(CClassicBufferMemory *this, void *param_1, ulong param_2)

{
  CFastString *pCVar1;
  ulong uVar2;
  char *pcVar3;
  char *pcVar4;
  ulong uVar5;
  char *pcVar6;
  char *pcVar7;

  if (*(uint *)(this + 0x10) < *(int *)(this + 0x14) + param_2) {
    if (_s_LogStringToAdd != 0) {
      _s_LogStringToAdd = 0;
      *DAT_00d71e58 = 0;
    }
    uVar5 = *(ulong *)(this + 0x10);
    uVar2 = *(ulong *)(this + 0x14);
    pcVar7 = "\r\n";
    pcVar6 = ")";
    pcVar4 = " > ";
    pcVar3 = " + ";
    pCVar1 = CFastString::operator<<(&CClassicLog::s_LogStringToAdd,
                                     "[CrashInfo] Trying to read pass end of memorybuffer. (");
    pCVar1 = CFastString::operator<<(pCVar1, uVar2);
    pCVar1 = CFastString::operator<<(pCVar1, pcVar3);
    pCVar1 = CFastString::operator<<(pCVar1, param_2);
    pCVar1 = CFastString::operator<<(pCVar1, pcVar4);
    pCVar1 = CFastString::operator<<(pCVar1, uVar5);
    pCVar1 = CFastString::operator<<(pCVar1, pcVar6);
    CFastString::operator<<(pCVar1, pcVar7);
    CClassicLog::AddLogStringInFile();
    if (CClassicArchive::s_ThrowCorruptedArchive != (_func_void *)0x0) {
      (*CClassicArchive::s_ThrowCorruptedArchive)();
    }
    return 0;
  }
  _memcpy(param_1, (void *)(*(int *)(this + 0xc) + *(int *)(this + 0x14)), param_2);
  *(ulong *)(this + 0x14) = *(int *)(this + 0x14) + param_2;
  return param_2;
}

/* public: void __thiscall CClassicBufferMemory::Reset(void) */

void __thiscall CClassicBufferMemory::Reset(CClassicBufferMemory *this)

{
  *(undefined4 *)(this + 0x14) = 0;
  return;
}

/* public: virtual void __thiscall CClassicBufferMemory::SetCurOffset(unsigned long) */

void __thiscall CClassicBufferMemory::SetCurOffset(CClassicBufferMemory *this, ulong param_1)

{
  if (param_1 == 0xffffffff) {
    param_1 = *(ulong *)(this + 0x10);
  }
  *(ulong *)(this + 0x14) = param_1;
  return;
}

/* public: virtual unsigned long __thiscall CClassicBufferMemory::Write(void const *,unsigned long)
 */

ulong __thiscall CClassicBufferMemory::Write(CClassicBufferMemory *this, void *param_1, ulong param_2)

{
  uint uVar1;

  if (*(int *)(this + 8) != 0) {
    return param_2;
  }
  if (*(uint *)(this + 0x18) < *(int *)(this + 0x14) + param_2) {
    PreAlloc(this, ((*(int *)(this + 0x14) + param_2) / *(uint *)(this + 0x1c) + 1) *
                       *(uint *)(this + 0x1c));
  }
  _memcpy((void *)(*(int *)(this + 0xc) + *(int *)(this + 0x14)), param_1, param_2);
  *(ulong *)(this + 0x14) = *(int *)(this + 0x14) + param_2;
  uVar1 = *(uint *)(this + 0x14);
  if (*(uint *)(this + 0x14) <= *(uint *)(this + 0x10)) {
    uVar1 = *(uint *)(this + 0x10);
  }
  *(uint *)(this + 0x10) = uVar1;
  return param_2;
}

/* public: unsigned long __thiscall CClassicBufferMemory::WriteCopy(class CClassicBuffer *,unsigned
   long) */

ulong __thiscall CClassicBufferMemory::WriteCopy(CClassicBufferMemory *this, CClassicBuffer *param_1, ulong param_2)

{
  ulong uVar1;

  if (*(uint *)(this + 0x18) < *(int *)(this + 0x14) + param_2) {
    PreAlloc(this, ((*(int *)(this + 0x14) + param_2) / *(uint *)(this + 0x1c) + 1) *
                       *(uint *)(this + 0x1c));
  }
  uVar1 = (**(code **)(*(int *)param_1 + 4))(*(int *)(this + 0xc) + *(int *)(this + 0x14), param_2);
  *(ulong *)(this + 0x14) = *(int *)(this + 0x14) + uVar1;
  if (*(uint *)(this + 0x14) <= *(uint *)(this + 0x10)) {
    *(uint *)(this + 0x10) = *(uint *)(this + 0x10);
    return uVar1;
  }
  *(uint *)(this + 0x10) = *(uint *)(this + 0x14);
  return uVar1;
}

/* public: unsigned long __thiscall CClassicBufferMemory::WriteVoid(unsigned long) */

ulong __thiscall CClassicBufferMemory::WriteVoid(CClassicBufferMemory *this, ulong param_1)

{
  uint uVar1;

  if (*(int *)(this + 8) != 0) {
    return param_1;
  }
  if (*(uint *)(this + 0x18) < *(int *)(this + 0x14) + param_1) {
    PreAlloc(this, ((*(int *)(this + 0x14) + param_1) / *(uint *)(this + 0x1c) + 1) *
                       *(uint *)(this + 0x1c));
  }
  *(ulong *)(this + 0x14) = *(int *)(this + 0x14) + param_1;
  uVar1 = *(uint *)(this + 0x14);
  if (*(uint *)(this + 0x14) <= *(uint *)(this + 0x10)) {
    uVar1 = *(uint *)(this + 0x10);
  }
  *(uint *)(this + 0x10) = uVar1;
  return param_1;
}

/* public: virtual __thiscall CClassicBufferMemory::~CClassicBufferMemory(void) */

void __thiscall CClassicBufferMemory::~CClassicBufferMemory(CClassicBufferMemory *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00ae1be8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 0;
  if (*(int *)(this + 0x1c) != 0) {
    operator_delete[](*(void **)(this + 0xc));
  }
  local_4 = 0xffffffff;
  CClassicBuffer::~CClassicBuffer((CClassicBuffer *)this);
  ExceptionList = local_c;
  return;
}
