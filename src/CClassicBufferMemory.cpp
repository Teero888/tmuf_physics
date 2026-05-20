// Class implementation: CClassicBufferMemory

// =================================================
// Function: CClassicBufferMemory::AdvanceOffset
// =================================================
void __thiscall
CClassicBufferMemory::AdvanceOffset
          (CClassicBufferMemory *this,CClassicBufferMemory *param_1,ulong param_2)
{
{
  *(CClassicBufferMemory **)(this + 0x14) = param_1 + *(int *)(this + 0x14);
  return;
}
}

// =================================================
// Function: CClassicBufferMemory::Attach
// =================================================
void __thiscall
CClassicBufferMemory::Attach
          (CClassicBufferMemory *this,CClassicBufferMemory *param_1,void *param_2,ulong param_3)
{
{
  *(CClassicBufferMemory **)(this + 0xc) = param_1;
  *(undefined4 *)(this + 0x14) = 0;
  *(void **)(this + 0x18) = param_2;
  *(void **)(this + 0x10) = param_2;
  *(uint *)(this + 0x1c) = (-(uint)(param_1 != (CClassicBufferMemory *)0x0) & 0xffffffe0) + 0x20;
  return;
}
}

// =================================================
// Function: CClassicBufferMemory::CClassicBufferMemory
// =================================================
void __thiscall
CClassicBufferMemory::CClassicBufferMemory(CClassicBufferMemory *this,CClassicBufferMemory *param_1)
{
{
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00ae1bb8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CClassicBuffer::CClassicBuffer
            ((CClassicBuffer *)this,(CClassicBuffer *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0x20;
  *(undefined4 *)(this + 4) = 3;
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CClassicBufferMemory::Empty
// =================================================
void __thiscall
CClassicBufferMemory::Empty(CClassicBufferMemory *this,CClassicBufferMemory *param_1)
{
{
  int extraout_ECX;
  GmFrustumIso4 *unaff_retaddr;
  
  Reset(this,unaff_retaddr);
  *(undefined4 *)(extraout_ECX + 0x10) = 0;
  return;
}
}

// =================================================
// Function: CClassicBufferMemory::IsEqualBuffer
// =================================================
int __thiscall
CClassicBufferMemory::IsEqualBuffer
          (CClassicBufferMemory *this,CClassicBufferMemory *param_1,CClassicBufferMemory *param_2)
{
{
  bool bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  
  uVar2 = *(uint *)(this + 0x10);
  if (uVar2 != *(uint *)(param_1 + 0x10)) {
    return 0;
  }
  pbVar4 = *(byte **)(param_1 + 0xc);
  pbVar3 = *(byte **)(this + 0xc);
  for (; 3 < uVar2; uVar2 = uVar2 - 4) {
    if (*(int *)pbVar3 != *(int *)pbVar4) goto LAB_009092a8;
    pbVar4 = pbVar4 + 4;
    pbVar3 = pbVar3 + 4;
  }
  if (uVar2 == 0) {
LAB_00909311:
    bVar1 = false;
  }
  else {
LAB_009092a8:
    iVar5 = (uint)*pbVar3 - (uint)*pbVar4;
    if (iVar5 == 0) {
      if (uVar2 == 1) goto LAB_00909311;
      iVar5 = (uint)pbVar3[1] - (uint)pbVar4[1];
      if (iVar5 == 0) {
        if (uVar2 == 2) goto LAB_00909311;
        iVar5 = (uint)pbVar3[2] - (uint)pbVar4[2];
        if (iVar5 == 0) {
          if ((uVar2 == 3) || (iVar5 = (uint)pbVar3[3] - (uint)pbVar4[3], iVar5 == 0))
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
}

// =================================================
// Function: CClassicBufferMemory::PreAlloc
// =================================================
void __thiscall
CClassicBufferMemory::PreAlloc
          (CClassicBufferMemory *this,CClassicBufferMemory *param_1,ulong param_2)
{
{
  void *pvVar1;
  
  if (*(CClassicBufferMemory **)(this + 0x18) < param_1) {
    pvVar1 = operator_new__((uint)param_1);
    _memcpy(pvVar1,*(void **)(this + 0xc),*(uint *)(this + 0x14));
    operator_delete__(*(void **)(this + 0xc));
    *(void **)(this + 0xc) = pvVar1;
    *(CClassicBufferMemory **)(this + 0x18) = param_1;
  }
  if (*(uint *)(this + 0x18) < *(uint *)(this + 0x1c)) {
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c);
    return;
  }
  *(uint *)(this + 0x1c) = *(uint *)(this + 0x18);
  return;
}
}

// =================================================
// Function: CClassicBufferMemory::Reset
// =================================================
void __thiscall CClassicBufferMemory::Reset(CClassicBufferMemory *this,GmFrustumIso4 *param_1)
{
{
  *(undefined4 *)(this + 0x14) = 0;
  return;
}
}

// =================================================
// Function: CClassicBufferMemory::WriteVoid
// =================================================
ulong __thiscall
CClassicBufferMemory::WriteVoid
          (CClassicBufferMemory *this,CClassicBufferMemory *param_1,ulong param_2)
{
{
  uint uVar1;
  ulong unaff_EDI;
  
  if (*(int *)(this + 8) != 0) {
    return (ulong)param_1;
  }
  if (*(CClassicBufferMemory **)(this + 0x18) < param_1 + *(int *)(this + 0x14)) {
    PreAlloc(this,(CClassicBufferMemory *)
                  (((uint)(param_1 + *(int *)(this + 0x14)) / *(uint *)(this + 0x1c) + 1) *
                  *(uint *)(this + 0x1c)),unaff_EDI);
  }
  *(CClassicBufferMemory **)(this + 0x14) = param_1 + *(int *)(this + 0x14);
  uVar1 = *(uint *)(this + 0x14);
  if (*(uint *)(this + 0x14) <= *(uint *)(this + 0x10)) {
    uVar1 = *(uint *)(this + 0x10);
  }
  *(uint *)(this + 0x10) = uVar1;
  return (ulong)param_1;
}
}

// =================================================
// Function: CClassicBufferMemory::~CClassicBufferMemory
// =================================================
void __thiscall
CClassicBufferMemory::~CClassicBufferMemory
          (CClassicBufferMemory *this,CClassicBufferMemory *param_1)
{
{
  CClassicBuffer *pCVar1;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00ae1be8;
  local_c = ExceptionList;
  pCVar1 = (CClassicBuffer *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 0;
  if (*(int *)(this + 0x1c) != 0) {
    operator_delete__(*(void **)(this + 0xc));
  }
  local_4 = 0xffffffff;
  CClassicBuffer::~CClassicBuffer((CClassicBuffer *)this,pCVar1);
  ExceptionList = local_8;
  return;
}
}

