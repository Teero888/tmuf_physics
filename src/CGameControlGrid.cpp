// Class implementation: CGameControlGrid

// =================================================
// Function: CGameControlGrid::Remote_Clean
// =================================================
void __thiscall CGameControlGrid::Remote_Clean(CGameControlGrid *this,CGameControlGrid *param_1)
{
{
  CGameRemoteBufferPool *unaff_retaddr;
  
  Remote_SetPool(this,(CGameControlGrid *)0x0,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CGameControlGrid::Remote_InternalGetBuffer
// =================================================
CGameRemoteBuffer * __thiscall
CGameControlGrid::Remote_InternalGetBuffer
          (CGameControlGrid *this,CGameControlGrid *param_1,int param_2)
{
{
  CGameRemoteBuffer *pCVar1;
  int unaff_retaddr;
  
  pCVar1 = Remote_InternalGetBufferFromParams
                     (this,this + 0x208,(CGameMasterServerRequestParams *)param_1,unaff_retaddr);
  return pCVar1;
}
}

// =================================================
// Function: CGameControlGrid::Remote_InternalGetBufferFromParams
// =================================================
CGameRemoteBuffer * __thiscall
CGameControlGrid::Remote_InternalGetBufferFromParams
          (CGameControlGrid *this,CGameControlGrid *param_1,CGameMasterServerRequestParams *param_2,
          int param_3)
{
{
  CGameRemoteBufferPool *this_00;
  CGameRemoteBuffer *pCVar1;
  CGameMasterServerRequestParams *unaff_retaddr;
  
  this_00 = *(CGameRemoteBufferPool **)(this + 0x204);
  if (this_00 == (CGameRemoteBufferPool *)0x0) {
    return (CGameRemoteBuffer *)0x0;
  }
  if (param_2 != (CGameMasterServerRequestParams *)0x0) {
    pCVar1 = CGameRemoteBufferPool::GetOrCreateRemoteBuffer
                       (this_00,(CGameRemoteBufferPool *)param_1,unaff_retaddr);
    return pCVar1;
  }
  pCVar1 = CGameRemoteBufferPool::GetRemoteBuffer
                     (this_00,(CGameRemoteBufferPool *)param_1,unaff_retaddr);
  return pCVar1;
}
}

// =================================================
// Function: CGameControlGrid::Remote_RegisterToBuffer
// =================================================
void __thiscall
CGameControlGrid::Remote_RegisterToBuffer(CGameControlGrid *this,CGameControlGrid *param_1)
{
{
  CGameRemoteBuffer *this_00;
  ulong uVar1;
  int unaff_ESI;
  CFastCallback1P<int> *unaff_retaddr;
  
  if (*(int *)(this + 0x218) == DAT_00cfab68) {
    this_00 = Remote_InternalGetBuffer(this,(CGameControlGrid *)0x1,unaff_ESI);
    if (this_00 != (CGameRemoteBuffer *)0x0) {
      uVar1 = CGameRemoteBuffer::Register
                        (this_00,*(CGameRemoteBuffer **)(this + 0x21c),
                         *(CFastCallback3P<unsigned_long,unsigned_long,int&> **)(this + 0x220),
                         *(CFastCallback2P<unsigned_long,unsigned_long> **)(this + 0x224),
                         unaff_retaddr);
      *(ulong *)(this + 0x218) = uVar1;
    }
  }
  return;
}
}

// =================================================
// Function: CGameControlGrid::Remote_SetPool
// =================================================
void __thiscall
CGameControlGrid::Remote_SetPool
          (CGameControlGrid *this,CGameControlGrid *param_1,CGameRemoteBufferPool *param_2)
{
{
  CGameControlGrid *unaff_ESI;
  CGameControlGrid *unaff_EDI;
  
  if (*(CGameControlGrid **)(this + 0x204) != param_1) {
    Remote_UnregisterFromBuffer(this,unaff_EDI);
    *(CGameControlGrid **)(this + 0x204) = param_1;
    if (param_1 != (CGameControlGrid *)0x0) {
      Remote_RegisterToBuffer(this,unaff_ESI);
    }
  }
  return;
}
}

// =================================================
// Function: CGameControlGrid::Remote_UnregisterFromBuffer
// =================================================
void __thiscall
CGameControlGrid::Remote_UnregisterFromBuffer(CGameControlGrid *this,CGameControlGrid *param_1)
{
{
  CGameRemoteBuffer *this_00;
  int unaff_ESI;
  ulong unaff_retaddr;
  
  this_00 = Remote_InternalGetBuffer(this,(CGameControlGrid *)0x0,unaff_ESI);
  if (this_00 != (CGameRemoteBuffer *)0x0) {
    CGameRemoteBuffer::Unregister(this_00,*(CGameRemoteBuffer **)(this + 0x218),unaff_retaddr);
    *(undefined4 *)(this + 0x218) = DAT_00cfab68;
    return;
  }
  *(undefined4 *)(this + 0x218) = DAT_00cfab68;
  return;
}
}

// =================================================
// Function: CGameControlGrid::SetForcedPageCountFromDataCount
// =================================================
void __thiscall
CGameControlGrid::SetForcedPageCountFromDataCount
          (CGameControlGrid *this,CGameControlGrid *param_1,ulong param_2)
{
{
  uint uVar1;
  
  if (param_1 == (CGameControlGrid *)0xffffffff) {
    *(undefined4 *)(this + 0x1d0) = 0xffffffff;
    return;
  }
  uVar1 = (**(code **)(*(int *)this + 0x230))();
  if (uVar1 == 0) {
    uVar1 = 1;
  }
  *(uint *)(this + 0x1d0) = (uint)param_1 / uVar1;
  if ((uint)param_1 % uVar1 != 0) {
    *(uint *)(this + 0x1d0) = (uint)param_1 / uVar1 + 1;
  }
  return;
}
}

