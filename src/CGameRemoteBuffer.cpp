// Class implementation: CGameRemoteBuffer

// =================================================
// Function: CGameRemoteBuffer::CleanRequestingUser
// =================================================
int __thiscall
CGameRemoteBuffer::CleanRequestingUser
          (CGameRemoteBuffer *this,CGameRemoteBuffer *param_1,SUser *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  SUser **unaff_EBX;
  CFastBuffer<struct_CGameRemoteBuffer::SUser*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x74,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x74,pCVar3,(ulong)unaff_ESI);
      unaff_ESI = (CFastBuffer<struct_CGameRemoteBuffer::SUser*> *)&stack0x0000000c;
      CFastBuffer<struct_CGameRemoteBuffer::SUser*>::ReplaceByLastIfFound
                ((void *)(*(int *)pSVar2 + 0x14),unaff_ESI,unaff_EBX);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 1;
}
}

// =================================================
// Function: CGameRemoteBuffer::InternalGetNewUserSlot
// =================================================
ulong __thiscall
CGameRemoteBuffer::InternalGetNewUserSlot(CGameRemoteBuffer *this,CGameRemoteBuffer *param_1)
{
{
  CGameRemoteBuffer *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong uVar3;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = this + 0x50;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar4,(ulong)unaff_ESI);
      if (*(int *)pSVar2 == 0) {
        return (ulong)pCVar4;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
  CFastBuffer<struct_SIfBlock>::AddNewElem(this_00,unaff_EBX);
  return uVar3;
}
}

// =================================================
// Function: CGameRemoteBuffer::Register
// =================================================
ulong __thiscall
CGameRemoteBuffer::Register
          (CGameRemoteBuffer *this,CGameRemoteBuffer *param_1,
          CFastCallback3P<unsigned_long,unsigned_long,int&> *param_2,
          CFastCallback2P<unsigned_long,unsigned_long> *param_3,CFastCallback1P<int> *param_4)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  undefined4 *puVar3;
  ulong unaff_ESI;
  CGameRemoteBuffer *unaff_EDI;
  undefined4 in_stack_00000014;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)InternalGetNewUserSlot(this,unaff_EDI);
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this + 0x50,pCVar1,unaff_ESI);
  puVar3 = operator_new(0xc);
  *(undefined4 **)pSVar2 = puVar3;
  *puVar3 = param_3;
  *(CFastCallback1P<int> **)(*(int *)pSVar2 + 4) = param_4;
  *(undefined4 *)(*(int *)pSVar2 + 8) = in_stack_00000014;
  return (ulong)pCVar1;
}
}

// =================================================
// Function: CGameRemoteBuffer::Unregister
// =================================================
int __thiscall
CGameRemoteBuffer::Unregister(CGameRemoteBuffer *this,CGameRemoteBuffer *param_1,ulong param_2)
{
{
  CGameRemoteBuffer *this_00;
  ulong uVar1;
  SCasterCat *pSVar2;
  SUser *unaff_EBX;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ulong unaff_retaddr;
  
  this_00 = this + 0x50;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (uVar1 <= param_2) {
    return 0;
  }
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,unaff_ESI);
  CleanRequestingUser(this,*(CGameRemoteBuffer **)pSVar2,unaff_EBX);
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                      unaff_retaddr);
  operator_delete(*(void **)pSVar2);
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                      (ulong)param_1);
  *(undefined4 *)pSVar2 = 0;
  return 1;
}
}

