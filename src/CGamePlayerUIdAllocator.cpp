// Class implementation: CGamePlayerUIdAllocator

// =================================================
// Function: CGamePlayerUIdAllocator::AssociatePlayerInfo
// =================================================
void __thiscall
CGamePlayerUIdAllocator::AssociatePlayerInfo
          (void *this,CGamePlayerUIdAllocator *param_1,uchar param_2,CGameNetPlayerInfo *param_3)
{
{
  undefined3 in_stack_00000009;
  
  *(undefined4 *)((int)this + ((uint)param_1 & 0xff) * 4 + 0x10c) = _param_2;
  return;
}
}

// =================================================
// Function: CGamePlayerUIdAllocator::GetUnallocatedRange
// =================================================
void __thiscall
CGamePlayerUIdAllocator::GetUnallocatedRange
          (void *this,CGamePlayerUIdAllocator *param_1,uchar *param_2,uchar *param_3)
{
{
  char cVar1;
  
  cVar1 = *(char *)((int)this + 0x50c);
  if ((cVar1 == -1) && (*(char *)((int)this + 0x50d) == -1)) {
    *param_1 = (CGamePlayerUIdAllocator)0x0;
    *param_2 = 0xfa;
    return;
  }
  if ((cVar1 == '\0') && (*(byte *)((int)this + 0x50d) < 0xfa)) {
    *param_1 = (CGamePlayerUIdAllocator)(*(byte *)((int)this + 0x50d) + 1);
    *param_2 = 0xfa;
    return;
  }
  if ((cVar1 != '\0') && (*(char *)((int)this + 0x50d) == -6)) {
    *param_1 = (CGamePlayerUIdAllocator)0x0;
    *param_2 = *(char *)((int)this + 0x50c) + 0xff;
    return;
  }
  *param_1 = (CGamePlayerUIdAllocator)0xff;
  *param_2 = 0xff;
  return;
}
}

