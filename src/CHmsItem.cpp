// Class implementation: CHmsItem

// =================================================
// Function: CHmsItem::AddCorpus
// =================================================
void __thiscall CHmsItem::AddCorpus(CHmsItem *this,SZone *param_1,CHmsCorpus *param_2)
{
{
  TiXmlAttribute *unaff_retaddr;
  
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (this + 0x34,(TiXmlAttributeSet *)&param_1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsItem::AddForce
// =================================================
void __thiscall CHmsItem::AddForce(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2,GmVec3 *param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  GmVec3 *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x34,pCVar3,(ulong)unaff_EBP);
      if (*(void **)(*(int *)pSVar2 + 0x58) != (void *)0x0) {
        unaff_EBP = param_3;
        CHmsDyna::AddLocalForce(*(void **)(*(int *)pSVar2 + 0x58),(CHmsDyna *)param_3,param_3);
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CHmsItem::AddImpulse
// =================================================
void __thiscall CHmsItem::AddImpulse(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  GmVec3 *unaff_EBP;
  GmVec3 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x34,pCVar3,(ulong)unaff_EBP);
      if (*(void **)(*(int *)pSVar2 + 0x58) != (void *)0x0) {
        unaff_EBP = param_2;
        CHmsDyna::AddLocalImpulse(*(void **)(*(int *)pSVar2 + 0x58),(CHmsDyna *)param_2,unaff_ESI);
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CHmsItem::AddStateForPrediction
// =================================================
void __thiscall
CHmsItem::AddStateForPrediction
          (CHmsItem *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,ulong param_3,
          ulong param_4)
{
{
  SCasterCat *pSVar1;
  ulong unaff_ESI;
  ulong unaff_retaddr;
  ulong in_stack_00000014;
  ulong in_stack_00000018;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x34,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  if (*(int *)(*(int *)pSVar1 + 0x58) != 0) {
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x34,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        unaff_retaddr);
    CHmsDyna::AddStateForPrediction
              (*(void **)(*(int *)pSVar1 + 0x58),(CSceneToyBoat *)param_3,
               (CClassicBufferMemory *)param_4,in_stack_00000014,in_stack_00000018);
    return;
  }
  return;
}
}

// =================================================
// Function: CHmsItem::AddTorque
// =================================================
void __thiscall CHmsItem::AddTorque(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  GmVec3 *unaff_EBP;
  GmVec3 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x34,pCVar3,(ulong)unaff_EBP);
      if (*(void **)(*(int *)pSVar2 + 0x58) != (void *)0x0) {
        unaff_EBP = param_2;
        CHmsDyna::AddLocalTorque(*(void **)(*(int *)pSVar2 + 0x58),(CHmsDyna *)param_2,unaff_ESI);
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CHmsItem::CHmsItem
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsItem::CHmsItem(CHmsItem *this,CHmsItem *param_1)
{
{
  undefined4 uVar1;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBX;
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  CMwNod *unaff_EDI;
  void *in_stack_00000008;
  undefined1 uStack0000000c;
  CHmsItem *pCVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a957d9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar2 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe4),unaff_EDI);
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x28,unaff_ESI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x34,unaff_EBX);
  *(undefined4 *)(this + 0x44) = 0;
  uStack0000000c = 3;
  CFastBuffer<int>::SetSizeAtLeast
            (this + 0x34,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x1,(ulong)pCVar2);
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x50) = uVar1;
  this[0x18] = (CHmsItem)0x0;
  *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0xff8004ff | 0x19800000;
  *(undefined4 *)(this + 0x1c) = 0xfff1c000;
  *(undefined2 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0xffffffff;
  ExceptionList = in_stack_00000008;
  return;
}
}

// =================================================
// Function: CHmsItem::CallbackSet
// =================================================
void __thiscall
CHmsItem::CallbackSet(CHmsItem *this,CHmsItem *param_1,ECallback param_2,CCallback *param_3)
{
{
  int iVar1;
  int *piVar2;
  CHmsItem *pCVar3;
  void *this_00;
  undefined4 extraout_EAX;
  undefined4 uVar4;
  SCallbackList *unaff_EDI;
  
  if ((param_2 != 0) &&
     (pCVar3 = (CHmsItem *)(**(code **)(*(int *)param_2 + 8))(), pCVar3 != param_1)) {
    return;
  }
  if (*(int *)(this + 0x24) == 0) {
    if (param_2 == 0) {
      return;
    }
    this_00 = operator_new(0x18);
    if (this_00 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      SCallbackList::SCallbackList(this_00,unaff_EDI);
      uVar4 = extraout_EAX;
    }
    *(undefined4 *)(this + 0x24) = uVar4;
  }
  iVar1 = *(int *)(this + 0x24);
  piVar2 = *(int **)(iVar1 + (int)param_1 * 4);
  if (piVar2 != (int *)param_2) {
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))();
    }
    *(ECallback *)(iVar1 + (int)param_1 * 4) = param_2;
  }
  return;
}
}

// =================================================
// Function: CHmsItem::CallbackSetRenderBeforeTree
// =================================================
void __cdecl CHmsItem::CallbackSetRenderBeforeTree(CCallbackRenderBeforeTree *param_1)
{
{
  DAT_00d67560 = param_1;
  return;
}
}

// =================================================
// Function: CHmsItem::Chunk
// =================================================
void __thiscall
CHmsItem::Chunk(CHmsItem *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  CNetNod_CheckedArchive *pCVar1;
  uint uVar2;
  CFuncSegment *this_00;
  CPlugSolid *pCVar3;
  ECollisionGroup unaff_EBX;
  CFastArray<class_CCrystalEdge*> *unaff_ESI;
  CClassicArchive *unaff_EDI;
  EDynamicType unaff_retaddr;
  uint in_stack_00000010;
  CClassicArchive *in_stack_00000014;
  CHmsItem *in_stack_00000018;
  CHmsItem *in_stack_00000020;
  ECollisionGroup in_stack_ffffffe8;
  EContactInterest in_stack_ffffffec;
  EContactInterest in_stack_fffffff0;
  EDynamicType in_stack_fffffff4;
  EDynamicType in_stack_fffffff8;
  ulong in_stack_fffffffc;
  
  this_00 = param_1;
  if ((CClassicArchive *)0x6003009 < param_2) {
    if (param_2 < (CClassicArchive *)0x600300f) {
      if (param_2 == (CClassicArchive *)0x600300e) {
        *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0x1fffffff;
        pCVar1 = (CNetNod_CheckedArchive *)(this + 0x18);
        CClassicArchive::DoData((CClassicArchive *)param_1,pCVar1,&DAT_00000008,(ulong)unaff_EDI);
        CClassicArchive::DoNat16
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x20),(ushort *)0x1,0,
                   (int)unaff_ESI);
        *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0xfff00000;
        *(uint *)pCVar1 = *(uint *)pCVar1 & 0xfffffbff | 0x11000000;
        return;
      }
      switch(param_2) {
      case (CClassicArchive *)0x600300a:
        CClassicArchive::DoData
                  ((CClassicArchive *)param_1,(CNetNod_CheckedArchive *)&stack0xfffffff8,
                   &DAT_00000008,(ulong)unaff_EDI);
        *(ulong *)(this + 0x18) = in_stack_fffffffc;
        *(EDynamicType *)(this + 0x1c) = unaff_retaddr;
        if (0xb < (unaff_retaddr & 0xfff)) {
          unaff_retaddr = 0;
        }
        *(uint *)(this + 0x1c) =
             1 << ((byte)unaff_retaddr & 0x1f) & 0xfffU | *(uint *)(this + 0x1c) & 0x7000 |
             0xfff18000;
        *(ushort *)(this + 0x20) = (ushort)(byte)(in_stack_fffffffc >> 0x18);
        *(ulong *)(this + 0x18) = in_stack_fffffffc & 0xefffbff | 0x11000000;
        SetLightEmitter(this,(CHmsItem *)(in_stack_fffffffc >> 10 & 1),(int)unaff_ESI);
        return;
      case (CClassicArchive *)0x600300b:
        *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0x1fffffff;
        pCVar1 = (CNetNod_CheckedArchive *)(this + 0x18);
        CClassicArchive::DoData((CClassicArchive *)param_1,pCVar1,&DAT_00000008,(ulong)unaff_EDI);
        *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) & 0x7fff | 0xfff18000;
        *(uint *)pCVar1 = *(uint *)pCVar1 & 0xfffffbff | 0x11000000;
        CClassicArchive::DoNat16
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x20),(ushort *)0x1,0,
                   (int)unaff_ESI);
        if (0xb < (*(uint *)(this + 0x1c) & 0xfff)) {
          *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) & 0xfffff000;
        }
        uVar2 = *(uint *)(this + 0x1c);
        *(uint *)(this + 0x1c) = (1 << ((byte)uVar2 & 0x1f) ^ uVar2) & 0xfff ^ uVar2;
        return;
      case (CClassicArchive *)0x600300c:
        *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0x1fffffff;
        pCVar1 = (CNetNod_CheckedArchive *)(this + 0x18);
        CClassicArchive::DoData((CClassicArchive *)param_1,pCVar1,&DAT_00000008,(ulong)unaff_EDI);
        *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) & 0x7fff | 0xfff18000;
        *(uint *)pCVar1 = *(uint *)pCVar1 & 0xfffffbff | 0x11000000;
        CClassicArchive::DoNat16
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x20),(ushort *)0x1,0,
                   (int)unaff_ESI);
        return;
      case (CClassicArchive *)0x600300d:
        *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0x1fffffff;
        pCVar1 = (CNetNod_CheckedArchive *)(this + 0x18);
        CClassicArchive::DoData((CClassicArchive *)param_1,pCVar1,&DAT_00000008,(ulong)unaff_EDI);
        CClassicArchive::DoNat16
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x20),(ushort *)0x1,0,
                   (int)unaff_ESI);
        *(uint *)pCVar1 = *(uint *)pCVar1 & 0xfffffbff | 0x11000000;
        *(uint *)(this + 0x1c) = *(ushort *)(this + 0x1c) | 0xfff10000;
        return;
      }
    }
    else if (param_2 < (CClassicArchive *)0x6003012) {
      if (param_2 == (CClassicArchive *)0x6003011) {
        *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0x1fffffff;
        CClassicArchive::DoData
                  ((CClassicArchive *)param_1,(CNetNod_CheckedArchive *)(this + 0x18),&DAT_00000008,
                   (ulong)unaff_EDI);
        CClassicArchive::DoNat16
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x20),(ushort *)0x1,0,
                   (int)unaff_ESI);
        return;
      }
      if (param_2 == (CClassicArchive *)0x600300f) {
        *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0x1fffffff;
        pCVar1 = (CNetNod_CheckedArchive *)(this + 0x18);
        CClassicArchive::DoData((CClassicArchive *)param_1,pCVar1,&DAT_00000008,(ulong)unaff_EDI);
        CClassicArchive::DoNat16
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x20),(ushort *)0x1,0,
                   (int)unaff_ESI);
        *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0xfff00000;
        *(uint *)pCVar1 = *(uint *)pCVar1 & 0xfffffbff | 0x10000000;
        return;
      }
      if (param_2 == (CClassicArchive *)0x6003010) {
        *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0x1fffffff;
        pCVar1 = (CNetNod_CheckedArchive *)(this + 0x18);
        CClassicArchive::DoData((CClassicArchive *)param_1,pCVar1,&DAT_00000008,(ulong)unaff_EDI);
        CClassicArchive::DoNat16
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x20),(ushort *)0x1,0,
                   (int)unaff_ESI);
        *(uint *)pCVar1 = *(uint *)pCVar1 | 0x10000000;
        return;
      }
    }
    else if (param_2 == (CClassicArchive *)0xffffffff) {
      return;
    }
switchD_0053e0ec_default:
    CMwNod::Chunk((CMwNod *)this,param_1,param_2,(ulong)unaff_EDI);
    return;
  }
  if (param_2 == (CClassicArchive *)0x6003009) {
    CClassicArchive::DoData
              ((CClassicArchive *)param_1,(CNetNod_CheckedArchive *)&param_1,&DAT_00000004,
               (ulong)unaff_EDI);
    *(uint *)(this + 0x1c) =
         (uint)(((uint)param_2 & 0xff) != 0) | *(uint *)(this + 0x1c) & 0x7000 | 0xfff18000;
    *(uint *)(this + 0x18) = (uint)param_2 & 0xfffffbff | 0x11000000;
    SetLightEmitter(this,(CHmsItem *)((uint)param_2 >> 10 & 1),(int)unaff_ESI);
    return;
  }
  switch(param_2) {
  case (CClassicArchive *)0x6003000:
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffff4,(ulong *)0x1,0,
               (int)unaff_EDI);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_2,(int *)0x1,(ulong)unaff_ESI);
    SetCollisionGroup(this,(CHmsItem *)(-(uint)(param_3 != 0) & 4),unaff_EBX);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000014,(int *)0x1,
               in_stack_ffffffe8);
    SetContactInterest(this,(CHmsItem *)(-(uint)(in_stack_00000018 != (CHmsItem *)0x0) & 2),
                       in_stack_ffffffec);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xfffffffc,(int *)0x1,
               in_stack_fffffff0);
    SetDynamicType(this,(CHmsItem *)(uint)(unaff_retaddr != 0),in_stack_fffffff4);
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0xfff00000;
    *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0xfffffbff | 0x10000000;
    return;
  case (CClassicArchive *)0x6003001:
    param_2 = *(CClassicArchive **)(this + 0x14);
    pCVar3 = (CPlugSolid *)&param_2;
    (**(code **)(*(int *)param_1 + 4))();
    if (*(int *)(this_00 + 8) != 0) {
      return;
    }
    if (*(int *)(param_1 + 8) != 0) {
      pCVar3 = CPlugSolid::CreateModelInstance((CPlugSolid *)param_1,pCVar3);
      SetSolid(this,(CSceneToyMotorbike *)pCVar3,(CPlugSolid *)unaff_EDI);
      return;
    }
    SetSolid(this,(CSceneToyMotorbike *)param_1,pCVar3);
    return;
  case (CClassicArchive *)0x6003002:
    CFastArray<class_CPlugSoundEngineComponent*>::ArchiveCountAndNods
              (this + 0x28,(CFastArray<class_CPlugSoundEngineComponent*> *)param_1,unaff_EDI);
    CFastArray<class_CManoeuvre*>::DeleteAll(this + 0x28,unaff_ESI);
    return;
  case (CClassicArchive *)0x6003003:
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffff4,(ulong *)0x1,0,
               (int)unaff_EDI);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_2,(int *)0x1,(ulong)unaff_ESI);
    SetCollisionGroup(this,(CHmsItem *)(-(uint)(param_3 != 0) & 4),unaff_EBX);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000014,(int *)0x1,
               in_stack_ffffffe8);
    SetContactInterest(this,(CHmsItem *)(-(uint)(in_stack_00000018 != (CHmsItem *)0x0) & 2),
                       in_stack_ffffffec);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xfffffffc,(int *)0x1,
               in_stack_fffffff0);
    SetDynamicType(this,(CHmsItem *)(uint)(unaff_retaddr != 0),in_stack_fffffff4);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_2,(int *)0x1,in_stack_fffffff8);
    in_stack_00000020 = (CHmsItem *)((byte)-(param_3 != 0) & 2);
    break;
  case (CClassicArchive *)0x6003004:
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffff4,(ulong *)0x1,0,
               (int)unaff_EDI);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_2,(int *)0x1,(ulong)unaff_ESI);
    SetCollisionGroup(this,(CHmsItem *)(-(uint)(param_3 != 0) & 4),unaff_EBX);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000014,(int *)0x1,
               in_stack_ffffffe8);
    SetContactInterest(this,(CHmsItem *)(-(uint)(in_stack_00000018 != (CHmsItem *)0x0) & 2),
                       in_stack_ffffffec);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000000,(int *)0x1,
               in_stack_fffffff0);
    SetDynamicType(this,(CHmsItem *)(uint)(param_1 != (CFuncSegment *)0x0),in_stack_fffffff4);
    CClassicArchive::DoNat8
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_1,(uchar *)0x1,0,
               in_stack_fffffff8);
    in_stack_00000014 = param_2;
    goto LAB_0053e2cd;
  case (CClassicArchive *)0x6003005:
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffff4,(ulong *)0x1,0,
               (int)unaff_EDI);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_2,(int *)0x1,(ulong)unaff_ESI);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000010,(int *)0x1,unaff_EBX);
    *(uint *)(this + 0x18) =
         *(uint *)(this + 0x18) ^
         ((uint)(in_stack_00000010 != 0) << 9 ^ *(uint *)(this + 0x18)) & 0x200;
    SetCollisionGroup(this,(CHmsItem *)(-(uint)(in_stack_00000014 != (CClassicArchive *)0x0) & 4),
                      in_stack_ffffffe8);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xfffffffc,(int *)0x1,
               in_stack_ffffffec);
    SetContactInterest(this,(CHmsItem *)(-(uint)(unaff_retaddr != 0) & 2),in_stack_fffffff0);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000000,(int *)0x1,
               in_stack_fffffff4);
    SetDynamicType(this,(CHmsItem *)(uint)(param_1 != (CFuncSegment *)0x0),in_stack_fffffff8);
    CClassicArchive::DoNat8
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000010,(uchar *)0x1,0,
               in_stack_fffffffc);
LAB_0053e2cd:
    SetCountShadowTexCasted(this,(CHmsItem *)in_stack_00000014,'\x01',unaff_retaddr);
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0xfff00000;
    *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0xfffffbff | 0x10000000;
    return;
  case (CClassicArchive *)0x6003006:
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffff8,(ulong *)0x1,0,
               (int)unaff_EDI);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_3,(int *)0x1,(ulong)unaff_ESI);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_3,(int *)0x1,unaff_EBX);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xfffffffc,(int *)0x1,
               in_stack_ffffffe8);
    *(uint *)(this + 0x18) =
         *(uint *)(this + 0x18) ^
         ((uint)(in_stack_00000014 != (CClassicArchive *)0x0) << 9 ^ *(uint *)(this + 0x18)) & 0x200
    ;
    SetLightEmitter(this,in_stack_00000018,in_stack_ffffffec);
    SetCollisionGroup(this,(CHmsItem *)(-(uint)(param_1 != (CFuncSegment *)0x0) & 4),
                      in_stack_fffffff0);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_1,(int *)0x1,in_stack_fffffff4);
    SetContactInterest(this,(CHmsItem *)(-(uint)(param_2 != (CClassicArchive *)0x0) & 2),
                       in_stack_fffffff8);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_2,(int *)0x1,in_stack_fffffffc);
    SetDynamicType(this,(CHmsItem *)(uint)(param_3 != 0),unaff_retaddr);
    CClassicArchive::DoNat8
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x0000001c,(uchar *)0x1,0,
               (int)param_1);
    break;
  case (CClassicArchive *)0x6003007:
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffff8,(ulong *)0x1,0,
               (int)unaff_EDI);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_3,(int *)0x1,(ulong)unaff_ESI);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_3,(int *)0x1,unaff_EBX);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000000,(int *)0x1,
               in_stack_ffffffe8);
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0xfff00000;
    *(uint *)(this + 0x18) =
         (in_stack_00000014 != (CClassicArchive *)0x0 | 0x80000) << 9 |
         *(uint *)(this + 0x18) & 0xfffffdff;
    SetLightEmitter(this,in_stack_00000018,in_stack_ffffffec);
    SetCollisionGroup(this,(CHmsItem *)(-(uint)(param_2 != (CClassicArchive *)0x0) & 4),
                      in_stack_fffffff0);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_2,(int *)0x1,in_stack_fffffff4);
    SetContactInterest(this,(CHmsItem *)(-(uint)(param_3 != 0) & 2),in_stack_fffffff8);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_3,(int *)0x1,in_stack_fffffffc);
    SetDynamicType(this,(CHmsItem *)(uint)(in_stack_00000010 != 0),unaff_retaddr);
    CClassicArchive::DoNat8
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000010,(uchar *)0x1,0,
               (int)param_1);
    param_1 = (CFuncSegment *)0x1;
    SetCountShadowTexCasted(this,(CHmsItem *)in_stack_00000014,'\x01',(int)param_2);
    return;
  case (CClassicArchive *)0x6003008:
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffff8,(ulong *)0x1,0,
               (int)unaff_EDI);
    CClassicArchive::DoData
              ((CClassicArchive *)this_00,(CNetNod_CheckedArchive *)&param_2,&DAT_00000004,
               (ulong)unaff_ESI);
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0xfff00000;
    this[0x18] = SUB41(param_3,0);
    *(uint *)(this + 0x18) =
         *(uint *)(this + 0x18) & 0xfff600ff | param_3 & 0x100 | (param_3 & 0x100) << 0xb |
         param_3 & 0x200 | (param_3 & 0x800 | 0x1100000) << 4;
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000010,(int *)0x1,unaff_EBX);
    SetLightEmitter(this,(CHmsItem *)(in_stack_00000010 >> 10 & 1),in_stack_ffffffe8);
    SetContactInterest(this,(CHmsItem *)(-(uint)(in_stack_00000018 != (CHmsItem *)0x0) & 2),
                       in_stack_ffffffec);
    *(undefined2 *)(this + 0x20) = 0;
    return;
  default:
    goto switchD_0053e0ec_default;
  }
  param_1 = (CFuncSegment *)0x1;
  SetCountShadowTexCasted(this,in_stack_00000020,'\x01',(int)param_2);
  *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0xfff00000;
  *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0xfffffbff | 0x10000000;
  return;
}
}

// =================================================
// Function: CHmsItem::CreateDefaultData
// =================================================
void __thiscall CHmsItem::CreateDefaultData(CHmsItem *this,CCrystal *param_1)
{
{
  CPlugSolid *pCVar1;
  CPlugSolid *this_00;
  CSceneToyMotorbike *extraout_EAX;
  CSceneToyMotorbike *pCVar2;
  CPlugSolid *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a958bb;
  local_c = ExceptionList;
  pCVar1 = (CPlugSolid *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  this_00 = operator_new(0x74);
  pCVar2 = (CSceneToyMotorbike *)0x0;
  local_4 = (void *)0x0;
  if (this_00 != (CPlugSolid *)0x0) {
    CPlugSolid::CPlugSolid(this_00,pCVar1);
    pCVar2 = extraout_EAX;
  }
  (**(code **)(*(int *)pCVar2 + 0x4c))();
  SetSolid(this,pCVar2,unaff_EDI);
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CHmsItem::CreatePortal
// =================================================
void __thiscall
CHmsItem::CreatePortal(CHmsItem *this,CHmsItem *param_1,CHmsPortal **param_2,CPlugTree *param_3)
{
{
  undefined1 *puVar1;
  CHmsPortal *pCVar2;
  CHmsPortal *this_00;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  SFormat *unaff_ESI;
  CPlugTree *unaff_EDI;
  CMwNod *pCVar4;
  CHmsItem *pCVar5;
  
  pCVar5 = (CHmsItem *)&LAB_00a958eb;
  pCVar2 = (CHmsPortal *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  puVar1 = &stack0xfffffff4;
  pCVar4 = ExceptionList;
  if (*(int *)param_1 == 0) {
    ExceptionList = &stack0xfffffff4;
    this_00 = operator_new(0x108);
    if (this_00 == (CHmsPortal *)0x0) {
      uVar3 = 0;
    }
    else {
      CHmsPortal::CHmsPortal(this_00,pCVar2);
      uVar3 = extraout_EAX;
    }
    *(undefined4 *)param_1 = uVar3;
    puVar1 = ExceptionList;
  }
  ExceptionList = puVar1;
  CHmsPortal::BindToBuild(*(CHmsPortal **)param_1,(CHmsPortal *)this,(CHmsItem *)param_3,unaff_EDI);
  CFastArray<class_CFastBuffer<class_CSceneMobil*>*>::AddTail
            (this + 0x28,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)param_1,unaff_ESI);
  CMwNod::MwAddRef(*(CMwNod **)param_1,pCVar4);
  UpdateIsBuild(this,pCVar5);
  ExceptionList = param_2;
  return;
}
}

// =================================================
// Function: CHmsItem::GetAngularSpeed
// =================================================
void __thiscall CHmsItem::GetAngularSpeed(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_retaddr;
  CHmsDyna *in_stack_0000000c;
  GmVec3 *in_stack_00000010;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_ESI);
  if (uVar1 != 0) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x34,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        unaff_retaddr);
    if (*(void **)(*(int *)pSVar2 + 0x58) != (void *)0x0) {
      CHmsDyna::GetLocalAngularSpeed
                (*(void **)(*(int *)pSVar2 + 0x58),in_stack_0000000c,in_stack_00000010);
      return;
    }
  }
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)param_2 = 0;
  return;
}
}

// =================================================
// Function: CHmsItem::GetAsyncBlendBetweenPreviousAndNextStates
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CHmsItem::GetAsyncBlendBetweenPreviousAndNextStates(CHmsItem *this,CHmsItem *param_1)
{
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  CMwId *pCVar5;
  SMwSchemeTimedProperties *pSVar6;
  CMwCmdBufferCore *this_00;
  CPlugAudio *unaff_ESI;
  int iVar7;
  float fVar8;
  
  this_00 = *(CMwCmdBufferCore **)(DAT_00d731e0 + 0x14);
  if ((*(uint *)(this + 0x18) & 0x200000) == 0) {
    if (this_00 == (CMwCmdBufferCore *)0x0) {
      this_00 = DAT_00d731e0 + 0xa0;
    }
    pCVar5 = CPlugAudio::MwGetId((CPlugAudio *)this_00,unaff_ESI);
    uVar1 = *(uint *)pCVar5;
    pSVar6 = CMwCmdBufferCore::GetSchemeProperies
                       (DAT_00d731e0,(CMwCmdBufferCore *)&DAT_0000008c,(ulong)this);
    uVar2 = *(uint *)pSVar6;
    iVar7 = uVar1 - (uVar1 / uVar2) * uVar2;
    fVar8 = (float)iVar7;
    if (iVar7 < 0) {
      fVar8 = fVar8 + _DAT_00c418d0;
    }
    fVar4 = (float)(int)uVar2;
    if ((int)uVar2 < 0) {
      fVar4 = fVar4 + _DAT_00c418d0;
    }
    return fVar8 / fVar4;
  }
  if (this_00 == (CMwCmdBufferCore *)0x0) {
    this_00 = DAT_00d731e0 + 0xa0;
  }
  pCVar5 = CPlugAudio::MwGetId((CPlugAudio *)this_00,unaff_ESI);
  uVar1 = *(uint *)pCVar5;
  uVar2 = *(uint *)(this + 0x4c);
  if (((uVar2 != 0xffffffff) && (uVar3 = *(uint *)(this + 0x48), uVar2 != uVar3)) &&
     (uVar3 <= uVar1)) {
    fVar8 = 1.0;
    if (uVar1 <= uVar2) {
      fVar8 = (float)(int)(uVar1 - uVar3);
      if ((int)(uVar1 - uVar3) < 0) {
        fVar8 = fVar8 + _DAT_00c418d0;
      }
      fVar4 = (float)(int)(uVar2 - uVar3);
      if ((int)(uVar2 - uVar3) < 0) {
        fVar4 = fVar4 + _DAT_00c418d0;
      }
      fVar8 = GmFunc::ClampReal(fVar8 / fVar4,0.0,1.0);
    }
    return fVar8;
  }
  return 0.0;
}
}

// =================================================
// Function: CHmsItem::GetChunkInfo
// =================================================
ulong __thiscall CHmsItem::GetChunkInfo(CHmsItem *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 < (CFuncSegment *)0x600300a) {
    if (param_1 != (CFuncSegment *)0x6003009) {
      switch(param_1) {
      case (CFuncSegment *)0x6003000:
      case (CFuncSegment *)0x6003002:
      case (CFuncSegment *)0x6003003:
      case (CFuncSegment *)0x6003004:
      case (CFuncSegment *)0x6003005:
      case (CFuncSegment *)0x6003006:
      case (CFuncSegment *)0x6003007:
      case (CFuncSegment *)0x6003008:
        break;
      case (CFuncSegment *)0x6003001:
        return 3;
      default:
        goto switchD_0053b578_default;
      }
    }
  }
  else {
    if ((CFuncSegment *)0x600300e < param_1) {
      if (param_1 < (CFuncSegment *)0x6003012) {
        if (param_1 == (CFuncSegment *)0x6003011) {
          return 3;
        }
        if (param_1 == (CFuncSegment *)0x600300f) {
          return 1;
        }
        if (param_1 == (CFuncSegment *)0x6003010) {
          return 1;
        }
      }
      else if (param_1 == (CFuncSegment *)0xffffffff) {
        return 0xffffffff;
      }
switchD_0053b578_default:
      uVar1 = CMwNod::GetChunkInfo((CMwNod *)this,param_1,param_2);
      return uVar1;
    }
    if (param_1 != (CFuncSegment *)0x600300e) {
      switch(param_1) {
      case (CFuncSegment *)0x600300a:
      case (CFuncSegment *)0x600300b:
      case (CFuncSegment *)0x600300c:
      case (CFuncSegment *)0x600300d:
        break;
      default:
        goto switchD_0053b578_default;
      }
    }
  }
  return 1;
}
}

// =================================================
// Function: CHmsItem::GetCorpus
// =================================================
CHmsCorpus * __thiscall CHmsItem::GetCorpus(CHmsItem *this,CHmsItem *param_1,CHmsZone *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x34,pCVar3,unaff_ESI);
      if (*(CHmsZone **)(*(CHmsCorpus **)pSVar2 + 0x14) == param_2) {
        return *(CHmsCorpus **)pSVar2;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return (CHmsCorpus *)0x0;
}
}

// =================================================
// Function: CHmsItem::GetCorpusCat
// =================================================
EHmsCorpusCat __thiscall CHmsItem::GetCorpusCat(CHmsItem *this,CHmsItem *param_1)
{
{
  uint uVar1;
  int unaff_ESI;
  int unaff_retaddr;
  
  uVar1 = *(uint *)(this + 0x18);
  if ((uVar1 & 0x200) != 0) {
    SetCountShadowTexCasted(this,(CHmsItem *)0x0,'\x01',unaff_ESI);
    SetIsVisionStatic(this,(CHmsItem *)0x0,unaff_retaddr);
    return 4;
  }
  if ((char)uVar1 != '\0') {
    return 2 - ((uVar1 & 0x100) != 0);
  }
  return (-(uint)((uVar1 & 0x100) != 0) & 0xfffffffd) + 3;
}
}

// =================================================
// Function: CHmsItem::GetCorpusIndex
// =================================================
ulong __thiscall CHmsItem::GetCorpusIndex(CHmsItem *this,CHmsItem *param_1,CHmsZone *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x34,pCVar3,unaff_ESI);
      if (*(CHmsZone **)(*(int *)pSVar2 + 0x14) == param_2) {
        return (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CHmsItem::GetCurrentCorpus
// =================================================
CHmsCorpus * __thiscall CHmsItem::GetCurrentCorpus(CHmsItem *this,CHmsItem *param_1)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_retaddr;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_ESI);
  if (uVar1 != 0) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x34,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        unaff_retaddr);
    return *(CHmsCorpus **)pSVar2;
  }
  return (CHmsCorpus *)0x0;
}
}

// =================================================
// Function: CHmsItem::GetForce
// =================================================
void __thiscall CHmsItem::GetForce(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_retaddr;
  CHmsDyna *in_stack_0000000c;
  GmVec3 *in_stack_00000010;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_ESI);
  if (uVar1 != 0) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x34,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        unaff_retaddr);
    if (*(void **)(*(int *)pSVar2 + 0x58) != (void *)0x0) {
      CHmsDyna::GetLocalForce(*(void **)(*(int *)pSVar2 + 0x58),in_stack_0000000c,in_stack_00000010)
      ;
      return;
    }
  }
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)param_2 = 0;
  return;
}
}

// =================================================
// Function: CHmsItem::GetLinearSpeed
// =================================================
void __thiscall CHmsItem::GetLinearSpeed(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_retaddr;
  CHmsDyna *in_stack_0000000c;
  GmVec3 *in_stack_00000010;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_ESI);
  if (uVar1 != 0) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x34,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        unaff_retaddr);
    if (*(void **)(*(int *)pSVar2 + 0x58) != (void *)0x0) {
      CHmsDyna::GetLocalLinearSpeed
                (*(void **)(*(int *)pSVar2 + 0x58),in_stack_0000000c,in_stack_00000010);
      return;
    }
  }
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)param_2 = 0;
  return;
}
}

// =================================================
// Function: CHmsItem::GetLocation
// =================================================
void __thiscall CHmsItem::GetLocation(CHmsItem *this,GmLocFreeVal *param_1,GmIso4 *param_2)
{
{
  CHmsCorpus *pCVar1;
  CHmsZone *unaff_retaddr;
  
  pCVar1 = GetCorpus(this,(CHmsItem *)param_1,unaff_retaddr);
  (**(code **)(*(int *)pCVar1 + 0x78))();
  return;
}
}

// =================================================
// Function: CHmsItem::GetMwClassId
// =================================================
ulong __thiscall CHmsItem::GetMwClassId(CHmsItem *this,CControlStyle *param_1)
{
{
  return 0x6003000;
}
}

// =================================================
// Function: CHmsItem::GetSaveStateSize
// =================================================
ulong __thiscall
CHmsItem::GetSaveStateSize
          (CHmsItem *this,CMwClassInfoCSceneToyBoat *param_1,EMobilStateQuality param_2)
{
{
  if (param_1 == (CMwClassInfoCSceneToyBoat *)0x0) {
    return 0xf;
  }
  if (param_1 != (CMwClassInfoCSceneToyBoat *)0x1) {
    return 0;
  }
  return 0x1a;
}
}

// =================================================
// Function: CHmsItem::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CHmsItem::GetUidChunkFromIndex(CHmsItem *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0x6003000;
}
}

// =================================================
// Function: CHmsItem::GetZone
// =================================================
CGameCtnZone * __thiscall
CHmsItem::GetZone(CHmsItem *this,CGameCtnCollection *param_1,CMwId *param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x34,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_retaddr);
  return *(CGameCtnZone **)(*(int *)pSVar1 + 0x14);
}
}

// =================================================
// Function: CHmsItem::IsStateDifferentFrom
// =================================================
int __thiscall CHmsItem::IsStateDifferentFrom(CHmsItem *this,CHmsItem *param_1,GmIso4 *param_2)
{
{
  SCasterCat *pSVar1;
  int iVar2;
  ulong unaff_retaddr;
  GmIso4 *in_stack_0000000c;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x34,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      unaff_retaddr);
  if (*(void **)(*(int *)pSVar1 + 0x58) != (void *)0x0) {
    iVar2 = CHmsDyna::IsStateDifferentFrom
                      (*(void **)(*(int *)pSVar1 + 0x58),(CHmsItem *)param_2,in_stack_0000000c);
    return iVar2;
  }
  return 0;
}
}

// =================================================
// Function: CHmsItem::IsVisibleSet
// =================================================
void __thiscall CHmsItem::IsVisibleSet(CHmsItem *this,CHmsItem *param_1,int param_2)
{
{
  uint uVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  uVar1 = *(uint *)(this + 0x1c);
  if ((uVar1 >> 0xf & 1) != (uint)(param_1 != (CHmsItem *)0x0)) {
    *(uint *)(this + 0x1c) = ((uint)(param_1 != (CHmsItem *)0x0) << 0xf ^ uVar1) & 0x8000 ^ uVar1;
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EDI);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x34,pCVar4,unaff_EBX);
        unaff_EBX = *(ulong *)pSVar3;
        (**(code **)(**(int **)(unaff_EBX + 0x14) + 0x80))();
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar2);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsItem::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CHmsItem::MwGetClassInfo(CHmsItem *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d67564;
}
}

// =================================================
// Function: CHmsItem::MwIsKindOf
// =================================================
int __thiscall CHmsItem::MwIsKindOf(CHmsItem *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdAffectParam *)0x6003000) {
    return 1;
  }
  return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
}
}

// =================================================
// Function: CHmsItem::MwNewCHmsItem
// =================================================
CMwNod * __cdecl CHmsItem::MwNewCHmsItem(void)
{
{
  CHmsItem *pCVar1;
  CMwNod *extraout_EAX;
  CHmsItem *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a9583b;
  local_c = ExceptionList;
  pCVar1 = (CHmsItem *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x58);
  local_4 = 0;
  if (local_10 != (CHmsItem *)0x0) {
    CHmsItem(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CHmsItem::OldRestoreStaticState
// =================================================
void __thiscall
CHmsItem::OldRestoreStaticState
          (CHmsItem *this,CHmsCorpus *param_1,CClassicBufferMemory *param_2,int param_3,
          uchar param_4,int param_5)
{
{
  SCasterCat *pSVar1;
  ulong unaff_ESI;
  int unaff_retaddr;
  uchar in_stack_00000018;
  
  if (param_2 == (CClassicBufferMemory *)0x0) {
    *(int *)(this + 0x4c) = param_3;
  }
  else {
    *(int *)(this + 0x48) = param_3;
  }
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x34,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  CHmsCorpus::OldRestoreStaticState
            (*(CHmsCorpus **)pSVar1,(CHmsCorpus *)param_2,param_2,param_5,in_stack_00000018,
             unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsItem::OnCrashDump
// =================================================
int __thiscall CHmsItem::OnCrashDump(CHmsItem *this,CMwNod *param_1,CFastString *param_2)
{
{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  CFastString *unaff_EDI;
  int unaff_retaddr;
  
  iVar2 = CMwNod::OnCrashDump((CMwNod *)this,param_1,unaff_EDI);
  if (iVar2 == 0) {
    return 0;
  }
  (**(code **)(DAT_00d5546c + 0x14))();
  CSystemCrashDump::IsValid_DumpFidAndMwId
            ((CSystemCrashDump *)&DAT_00d5546c,(CSystemCrashDump *)param_1,
             (CFastString *)"SceneMobil",*(char **)(this + 0x40),(CMwNod *)0x1,unaff_ESI);
  piVar1 = *(int **)(this + 0x14);
  iVar2 = CSystemCrashDump::IsValid_DumpFidAndMwId
                    ((CSystemCrashDump *)&DAT_00d5546c,(CSystemCrashDump *)param_1,
                     (CFastString *)0xb56048,(char *)piVar1,(CMwNod *)0x1,unaff_retaddr);
  if (iVar2 != 0) {
    (**(code **)(*piVar1 + 0x58))();
  }
  (**(code **)(DAT_00d5546c + 0x18))();
  return 1;
}
}

// =================================================
// Function: CHmsItem::OnNodLoaded
// =================================================
void __thiscall CHmsItem::OnNodLoaded(CHmsItem *this,CDx9DeviceCaps *param_1)
{
{
  CFastStringInt *unaff_ESI;
  
  OnAccessViolation_ConcatToCrashFileName(unaff_ESI);
  if (((*(uint *)(this + 0x18) & 0x200) != 0) &&
     (*(CPlugSolid **)(this + 0x14) != (CPlugSolid *)0x0)) {
    CPlugSolid::ExclusionEllipsoidRadiusCompute(*(CPlugSolid **)(this + 0x14),(CPlugSolid *)param_1)
    ;
    return;
  }
  return;
}
}

// =================================================
// Function: CHmsItem::OnVisible_WakeOrKeepAwake
// =================================================
void __thiscall CHmsItem::OnVisible_WakeOrKeepAwake(CHmsItem *this,CHmsItem *param_1)
{
{
  int *piVar1;
  uint uVar2;
  
  if ((*(int **)(this + 0x24) != (int *)0x0) &&
     (piVar1 = (int *)**(int **)(this + 0x24), piVar1 != (int *)0x0)) {
    uVar2 = *(uint *)(this + 0x1c);
    if ((uVar2 & 0x2000) != 0) {
      *(uint *)(this + 0x1c) = uVar2 & 0xffffdfff | 0x4000;
      (**(code **)(*piVar1 + 0xc))(this);
      return;
    }
    *(uint *)(this + 0x1c) = uVar2 | 0x4000;
  }
  return;
}
}

// =================================================
// Function: CHmsItem::PickDisable
// =================================================
void __thiscall CHmsItem::PickDisable(CHmsItem *this,CHmsItem *param_1)
{
{
  CPlugTree *this_00;
  CHmsItem *pCVar1;
  CPlugTree *pCVar2;
  CPlugTree *unaff_ESI;
  
  this_00 = *(CPlugTree **)(*(int *)(this + 0x14) + 100);
  *(uint *)(this_00 + 0x9c) = *(uint *)(this_00 + 0x9c) & 0xffffffbf;
  pCVar1 = (CHmsItem *)CPlugTree::GetAllChildStart(this_00,unaff_ESI);
  while (pCVar1 != (CHmsItem *)0xffffffff) {
    pCVar2 = CPlugTree::GetAllChildNext(this_00,(CPlugTree *)&stack0x00000000,(ulong *)this);
    *(uint *)(pCVar2 + 0x9c) = *(uint *)(pCVar2 + 0x9c) & 0xffffffbf;
    pCVar1 = param_1;
  }
  return;
}
}

// =================================================
// Function: CHmsItem::PickEnableAtLevel
// =================================================
void __thiscall CHmsItem::PickEnableAtLevel(CHmsItem *this,CHmsItem *param_1,ulong param_2)
{
{
  CPlugTree *this_00;
  int iVar1;
  byte bVar2;
  ulong uVar3;
  CPlugTree *pCVar4;
  CHmsItem *pCVar5;
  ulong *unaff_ESI;
  CPlugTree *unaff_EDI;
  ulong in_stack_0000000c;
  
  this_00 = *(CPlugTree **)(*(int *)(this + 0x14) + 100);
  *(uint *)(this_00 + 0x9c) =
       *(uint *)(this_00 + 0x9c) ^
       ((uint)(param_1 == (CHmsItem *)0x0) << 6 ^ *(uint *)(this_00 + 0x9c)) & 0x40;
  param_2 = CPlugTree::GetAllChildStart(this_00,unaff_EDI);
  uVar3 = param_2;
  do {
    while( true ) {
      if (uVar3 == 0xffffffff) {
        return;
      }
      pCVar4 = CPlugTree::GetAllChildNext(this_00,(CPlugTree *)&param_2,unaff_ESI);
      uVar3 = in_stack_0000000c;
      if (param_1 != (CHmsItem *)0x0) break;
      *(uint *)(pCVar4 + 0x9c) = *(uint *)(pCVar4 + 0x9c) & 0xffffffbf;
    }
    pCVar5 = (CHmsItem *)0x1;
    for (iVar1 = *(int *)(*(int *)(pCVar4 + 0x24) + 0x24); iVar1 != 0;
        iVar1 = *(int *)(iVar1 + 0x24)) {
      if (param_1 <= pCVar5) {
        if (iVar1 != 0) goto LAB_0053baef;
        break;
      }
      pCVar5 = pCVar5 + 1;
    }
    if (param_1 == pCVar5) {
      bVar2 = 1;
    }
    else {
LAB_0053baef:
      bVar2 = 0;
    }
    *(uint *)(pCVar4 + 0x9c) =
         *(uint *)(pCVar4 + 0x9c) ^ ((uint)bVar2 << 6 ^ *(uint *)(pCVar4 + 0x9c)) & 0x40;
  } while( true );
}
}

// =================================================
// Function: CHmsItem::RemoveCorpus
// =================================================
void __thiscall CHmsItem::RemoveCorpus(CHmsItem *this,CHmsZoneOverlay *param_1,CHmsCorpus *param_2)
{
{
  CPlugBitmap **unaff_retaddr;
  
  CFastBuffer<class_CPlugBitmap*>::ReplaceByLast
            (this + 0x34,(CFastBuffer<class_CPlugBitmap*> *)&param_1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsItem::RemovePortal
// =================================================
void __thiscall CHmsItem::RemovePortal(CHmsItem *this,CHmsItem *param_1,CHmsPortal *param_2)
{
{
  CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *pCVar1;
  ulong unaff_ESI;
  ulong unaff_EDI;
  CHmsPortal *unaff_retaddr;
  CHmsPortal *in_stack_0000000c;
  
  pCVar1 = (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)
           CFastArray<class_CGameMenuFrame*>::Find
                     (this + 0x28,(CFastArray<class_GxTexCoordSet> *)&param_1,(GxTexCoordSet *)0x1);
  CFastArray<class_CCrystalVertex*>::RemoveAt(this + 0x28,pCVar1,unaff_EDI,unaff_ESI);
  CHmsPortal::UnbindFromBuild(in_stack_0000000c,unaff_retaddr);
  CMwNod::MwRelease((CMwNod *)in_stack_0000000c,(CMwNod *)param_1);
  param_1 = (CHmsItem *)0x53d726;
  UpdateIsBuild(this,(CHmsItem *)param_2);
  return;
}
}

// =================================================
// Function: CHmsItem::ResetDynamicState
// =================================================
void __thiscall CHmsItem::ResetDynamicState(CHmsItem *this,CHmsItem *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  GmFrustumIso4 *unaff_EBX;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x34,pCVar3,unaff_ESI);
      unaff_ESI = 0x53d364;
      CHmsCorpus::Reset(*(CHmsCorpus **)pSVar2,unaff_EBX);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CHmsItem::RestoreStaticState
// =================================================
void __thiscall
CHmsItem::RestoreStaticState
          (CHmsItem *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,int param_3,
          ulong param_4,ulong param_5,int param_6)
{
{
  SCasterCat *pSVar1;
  ulong unaff_ESI;
  ulong unaff_retaddr;
  
  if (param_2 == (CClassicBufferMemory *)0x0) {
    *(int *)(this + 0x4c) = param_3;
  }
  else {
    *(int *)(this + 0x48) = param_3;
  }
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x34,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  CHmsCorpus::RestoreStaticState
            (*(CHmsCorpus **)pSVar1,(CSceneToyBoat *)param_2,param_2,param_5,unaff_retaddr,
             (ulong)param_1,(int)param_2);
  return;
}
}

// =================================================
// Function: CHmsItem::RotateOf
// =================================================
void __thiscall CHmsItem::RotateOf(CHmsItem *this,CHmsCorpus *param_1,GmMat3 *param_2)
{
{
  GmMat3 *pGVar1;
  undefined4 local_2c;
  undefined1 local_24 [36];
  
  pGVar1 = *(GmMat3 **)(param_1 + 8);
  local_2c = *(undefined4 *)(param_1 + 0xc);
  GmMat3::Set(local_24,*(CMwCmdScriptVarBool **)param_1,*(int *)(param_1 + 4));
  RotateOf(this,(CHmsCorpus *)&local_2c,pGVar1);
  return;
}
}

// =================================================
// Function: CHmsItem::SaveState
// =================================================
void __thiscall
CHmsItem::SaveState(CHmsItem *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,
                   ulong *param_3,ulong param_4)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  ulong in_stack_00000014;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x34,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      unaff_retaddr);
  if (*(void **)(*(int *)pSVar1 + 0x58) != (void *)0x0) {
    CHmsDyna::SaveState(*(void **)(*(int *)pSVar1 + 0x58),(CSceneToyBoat *)param_2,
                        (CClassicBufferMemory *)param_3,(ulong *)param_4,in_stack_00000014);
    return;
  }
  return;
}
}

// =================================================
// Function: CHmsItem::SetAngularSpeed
// =================================================
void __thiscall CHmsItem::SetAngularSpeed(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  GmVec3 *unaff_EBP;
  GmVec3 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x34,pCVar3,(ulong)unaff_EBP);
      if (*(void **)(*(int *)pSVar2 + 0x58) != (void *)0x0) {
        unaff_EBP = param_2;
        CHmsDyna::SetLocalAngularSpeed
                  (*(void **)(*(int *)pSVar2 + 0x58),(CHmsDyna *)param_2,unaff_ESI);
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CHmsItem::SetCollisionGroup
// =================================================
void __thiscall
CHmsItem::SetCollisionGroup(CHmsItem *this,CHmsItem *param_1,ECollisionGroup param_2)
{
{
  CHmsItem *this_00;
  int *piVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  int unaff_retaddr;
  
  if (param_1 != (CHmsItem *)(*(uint *)(this + 0x18) >> 0xd & 0xf)) {
    this_00 = this + 0x34;
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_ESI)
        ;
        piVar1 = *(int **)(*(int *)pSVar3 + 0x14);
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_EBX)
        ;
        unaff_EBX = *(ulong *)pSVar3;
        unaff_ESI = 0x53cc45;
        (**(code **)(*piVar1 + 0x84))();
        pCVar4 = pCVar4 + 1;
        param_1 = (CHmsItem *)param_2;
      } while (pCVar4 < pCVar2);
    }
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    *(uint *)(unaff_retaddr + 0x18) =
         *(uint *)(unaff_retaddr + 0x18) ^
         ((int)param_1 << 0xd ^ *(uint *)(unaff_retaddr + 0x18)) & 0x1e000;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_ESI)
        ;
        piVar1 = *(int **)(*(int *)pSVar3 + 0x14);
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_EBX)
        ;
        unaff_EBX = *(ulong *)pSVar3;
        unaff_ESI = 0x53cc95;
        (**(code **)(*piVar1 + 0x88))();
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar2);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsItem::SetContactInterest
// =================================================
void __thiscall
CHmsItem::SetContactInterest(CHmsItem *this,CHmsItem *param_1,EContactInterest param_2)
{
{
  *(uint *)(this + 0x18) =
       *(uint *)(this + 0x18) ^ ((int)param_1 << 0x11 ^ *(uint *)(this + 0x18)) & 0x60000;
  return;
}
}

// =================================================
// Function: CHmsItem::SetCountShadowTexCasted
// =================================================
void __thiscall
CHmsItem::SetCountShadowTexCasted(CHmsItem *this,CHmsItem *param_1,uchar param_2,int param_3)
{
{
  CHmsItem *unaff_ESI;
  undefined3 in_stack_00000009;
  
  if ((SUB41(*(uint *)(this + 0x18),0) != param_1._0_1_) ||
     ((*(uint *)(this + 0x18) >> 0x17 & 1) != (uint)(_param_2 != 0))) {
    this[0x18] = param_1._0_1_;
    *(uint *)(this + 0x18) =
         *(uint *)(this + 0x18) ^
         ((uint)(_param_2 != 0) << 0x17 ^ *(uint *)(this + 0x18)) & 0x800000;
    if ((this[0x18] != (CHmsItem)0x0) && ((*(uint *)(this + 0x1c) & 0xfff) == 0)) {
      *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) & 0xfffff001 | 1;
    }
    UpdateCorpusCat(this,unaff_ESI);
  }
  return;
}
}

// =================================================
// Function: CHmsItem::SetDynamicType
// =================================================
void __thiscall CHmsItem::SetDynamicType(CHmsItem *this,CHmsItem *param_1,EDynamicType param_2)
{
{
  CFastBuffer<class_CSystemFidsFolder*> *pCVar1;
  SCasterCat *pSVar2;
  SCasterCat *pSVar3;
  undefined4 *puVar4;
  int iVar5;
  SCasterCat *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  void *unaff_EBP;
  ulong unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  ulong uVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffcc;
  CHmsItem *pCVar9;
  CHmsItem *pCStack_24;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_20;
  undefined1 local_1c [4];
  SCasterCat *local_18;
  int *local_14;
  SCasterCat *local_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  local_10 = (SCasterCat *)&LAB_00a95808;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (param_1 != (CHmsItem *)(*(uint *)(this + 0x18) >> 0xb & 3)) {
    pCVar9 = this;
    pCVar1 = (CFastBuffer<class_CSystemFidsFolder*> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this + 0x34,
                        (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffc0))
    ;
    CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(local_1c,unaff_EDI);
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    unaff_EBP = (void *)0x0;
    CFastArray<struct_SCorpusData>::SetCount(&local_18,pCVar1,unaff_ESI);
    pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
      do {
        local_18 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this + 0x34,pCVar6,(ulong)unaff_EBX);
        uVar8 = 0x53cd39;
        pSVar2 = CFastBuffer<struct_SChildGen>::operator[]
                           (&local_10,pCVar6,(ulong)in_stack_ffffffcc);
        *(undefined4 *)pSVar2 = *(undefined4 *)(*local_14 + 0x14);
        unaff_EBX = (SCasterCat *)0x53cd52;
        in_stack_ffffffcc = pCVar6;
        local_10 = pSVar2;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x34,pCVar6,(ulong)pCVar9);
        pCVar9 = (CHmsItem *)0x53cd5b;
        puVar4 = (undefined4 *)(**(code **)(**(int **)pSVar3 + 0x78))();
        for (iVar5 = 0xc; pSVar2 = pSVar2 + 4, iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined4 *)pSVar2 = *puVar4;
          puVar4 = puVar4 + 1;
        }
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar1 + 0x34,pCVar6,uVar8);
        pCVar6 = pCVar6 + 1;
        *(undefined4 *)(local_18 + 0x34) = *(undefined4 *)pSVar2;
        this = pCStack_24;
        pCVar7 = pCStack_20;
      } while (pCVar6 < pCStack_20);
    }
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar7 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<struct_SChildGen>::operator[](&local_14,pCVar6,(ulong)unaff_EBX);
        unaff_EBX = *(SCasterCat **)(pSVar2 + 0x34);
        (**(code **)(**(int **)pSVar2 + 0x7c))();
        pCVar6 = pCVar6 + 1;
      } while (pCVar6 < pCVar7);
    }
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    *(uint *)(this + 0x18) =
         *(uint *)(this + 0x18) ^ ((int)param_1 << 0xb ^ *(uint *)(this + 0x18)) & 0x1800;
    if (pCVar7 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<struct_SChildGen>::operator[](&local_14,pCVar6,(ulong)unaff_EBX);
        unaff_EBX = pSVar2 + 4;
        (**(code **)(**(int **)pSVar2 + 0x78))();
        pCVar6 = pCVar6 + 1;
      } while (pCVar6 < pCVar7);
    }
    CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>
              (&local_14,(CFastArray<class_CFuncShader*> *)unaff_EBX);
  }
  ExceptionList = unaff_EBP;
  return;
}
}

// =================================================
// Function: CHmsItem::SetForce
// =================================================
void __thiscall CHmsItem::SetForce(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  GmVec3 *unaff_EBP;
  GmVec3 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x34,pCVar3,(ulong)unaff_EBP);
      if (*(void **)(*(int *)pSVar2 + 0x58) != (void *)0x0) {
        unaff_EBP = param_2;
        CHmsDyna::SetLocalForce(*(void **)(*(int *)pSVar2 + 0x58),(CHmsDyna *)param_2,unaff_ESI);
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CHmsItem::SetIsBackground
// =================================================
void __thiscall CHmsItem::SetIsBackground(CHmsItem *this,CHmsItem *param_1,int param_2)
{
{
  CHmsItem *unaff_retaddr;
  
  *(uint *)(this + 0x18) =
       *(uint *)(this + 0x18) ^
       ((uint)(param_1 != (CHmsItem *)0x0) << 9 ^ *(uint *)(this + 0x18)) & 0x200;
  UpdateCorpusCat(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsItem::SetIsCollisionStatic
// =================================================
void __thiscall CHmsItem::SetIsCollisionStatic(CHmsItem *this,CHmsItem *param_1,int param_2)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x18);
  if ((uVar1 >> 0x13 & 1) != (uint)(param_1 != (CHmsItem *)0x0)) {
    *(uint *)(this + 0x18) = ((uint)(param_1 != (CHmsItem *)0x0) << 0x13 ^ uVar1) & 0x80000 ^ uVar1;
  }
  return;
}
}

// =================================================
// Function: CHmsItem::SetIsForcePointDynamicCollisionResponse
// =================================================
void __thiscall
CHmsItem::SetIsForcePointDynamicCollisionResponse(CHmsItem *this,CHmsItem *param_1,int param_2)
{
{
  *(uint *)(this + 0x1c) =
       *(uint *)(this + 0x1c) ^
       ((uint)(param_1 != (CHmsItem *)0x0) << 0xc ^ *(uint *)(this + 0x1c)) & 0x1000;
  return;
}
}

// =================================================
// Function: CHmsItem::SetIsKinematicOnly
// =================================================
void __thiscall CHmsItem::SetIsKinematicOnly(CHmsItem *this,CHmsItem *param_1,int param_2)
{
{
  *(uint *)(this + 0x18) =
       *(uint *)(this + 0x18) ^
       ((uint)(param_1 != (CHmsItem *)0x0) << 0x14 ^ *(uint *)(this + 0x18)) & 0x100000;
  return;
}
}

// =================================================
// Function: CHmsItem::SetIsVisionStatic
// =================================================
void __thiscall CHmsItem::SetIsVisionStatic(CHmsItem *this,CHmsItem *param_1,int param_2)
{
{
  uint uVar1;
  CHmsItem *unaff_retaddr;
  
  uVar1 = *(uint *)(this + 0x18);
  if ((uVar1 >> 8 & 1) != (uint)(param_1 != (CHmsItem *)0x0)) {
    *(uint *)(this + 0x18) = ((uint)(param_1 != (CHmsItem *)0x0) << 8 ^ uVar1) & 0x100 ^ uVar1;
    UpdateCorpusCat(this,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CHmsItem::SetIsZombie
// =================================================
void __thiscall CHmsItem::SetIsZombie(CHmsItem *this,CHmsItem *param_1,int param_2)
{
{
  CHmsItem *this_00;
  int *piVar1;
  uint uVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBX;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CHmsItem *unaff_retaddr;
  
  uVar2 = *(uint *)(this + 0x18) >> 0x15 & 1;
  if ((((uVar2 == 0) || (param_1 == (CHmsItem *)0x0)) &&
      ((uVar2 != 0 || (param_1 != (CHmsItem *)0x0)))) && ((*(uint *)(this + 0x18) & 0x1800) != 0)) {
    this_00 = this + 0x34;
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar5,unaff_ESI)
        ;
        piVar1 = *(int **)(*(int *)pSVar4 + 0x14);
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar5,unaff_EBX)
        ;
        unaff_EBX = *(ulong *)pSVar4;
        unaff_ESI = 0x53d155;
        (**(code **)(*piVar1 + 0x8c))();
        pCVar5 = pCVar5 + 1;
        this = unaff_retaddr;
      } while (pCVar5 < pCVar3);
    }
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    *(uint *)(this + 0x18) =
         *(uint *)(this + 0x18) ^ ((uint)(param_2 != 0) << 0x15 ^ *(uint *)(this + 0x18)) & 0x200000
    ;
    if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar5,unaff_ESI)
        ;
        piVar1 = *(int **)(*(int *)pSVar4 + 0x14);
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar5,unaff_EBX)
        ;
        unaff_EBX = *(ulong *)pSVar4;
        unaff_ESI = 0x53d1a5;
        (**(code **)(*piVar1 + 0x90))();
        pCVar5 = pCVar5 + 1;
      } while (pCVar5 < pCVar3);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsItem::SetLightEmitter
// =================================================
void __thiscall CHmsItem::SetLightEmitter(CHmsItem *this,CHmsItem *param_1,int param_2)
{
{
  ushort uVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  int unaff_EBP;
  CHmsItem *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  uVar1 = *(ushort *)(this + 0x20);
  if ((uVar1 & 1) != (ushort)(param_1 != (CHmsItem *)0x0)) {
    *(ushort *)(this + 0x20) = (byte)(param_1 != (CHmsItem *)0x0 ^ (byte)uVar1) & 1 ^ uVar1;
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EDI);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x34,pCVar4,(ulong)unaff_ESI);
        unaff_ESI = param_1;
        CHmsZone::CorpusChangeLightEmitter
                  (*(CHmsZone **)(*(CHmsZone **)pSVar3 + 0x14),*(CHmsZone **)pSVar3,
                   (CHmsCorpus *)param_1,unaff_EBP);
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar2);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsItem::SetLightLensFlareEnable
// =================================================
void __thiscall CHmsItem::SetLightLensFlareEnable(CHmsItem *this,CHmsItem *param_1,int param_2)
{
{
  *(uint *)(this + 0x18) =
       *(uint *)(this + 0x18) ^
       ((uint)(param_1 != (CHmsItem *)0x0) << 0x1c ^ *(uint *)(this + 0x18)) & 0x10000000;
  return;
}
}

// =================================================
// Function: CHmsItem::SetLinearSpeed
// =================================================
void __thiscall CHmsItem::SetLinearSpeed(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  GmVec3 *unaff_EBP;
  GmVec3 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x34,pCVar3,(ulong)unaff_EBP);
      if (*(void **)(*(int *)pSVar2 + 0x58) != (void *)0x0) {
        unaff_EBP = param_2;
        CHmsDyna::SetLocalLinearSpeed
                  (*(void **)(*(int *)pSVar2 + 0x58),(CHmsDyna *)param_2,unaff_ESI);
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CHmsItem::SetLocation
// =================================================
void __thiscall CHmsItem::SetLocation(CHmsItem *this,CPlugTree *param_1,GmIso4 *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  GmScaleTrans2 *pGVar4;
  GmIso3 *pGVar5;
  int iVar6;
  ulong unaff_EBX;
  CHmsCorpus *pCVar7;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CHmsItem *this_00;
  undefined4 *puVar8;
  CHmsZone *unaff_EDI;
  undefined4 *puVar9;
  CPlugTree *in_stack_00000010;
  GmIso4 *pGVar10;
  GmIso4 *pGVar11;
  GmIso3 *pGVar12;
  GmMat3 *pGVar13;
  GmIso4 *in_stack_ffffff60;
  CHmsItem *pCStack_94;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_90;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_8c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *apCStack_88 [2];
  undefined4 auStack_80 [9];
  undefined1 auStack_5c [4];
  CPlugTree aCStack_58 [8];
  undefined4 auStack_50 [8];
  undefined1 auStack_30 [4];
  SPlugFaceCull aSStack_2c [44];
  
  pGVar10 = param_2;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           GetCorpusIndex(this,(CHmsItem *)param_2,unaff_EDI);
  this_00 = this + 0x34;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
  pGVar11 = (GmIso4 *)0x53d58a;
  local_8c = pCVar2;
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar1,unaff_EBX);
  pCVar7 = *(CHmsCorpus **)pSVar3;
  local_8c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar7;
  if ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1 < pCVar2) {
    pGVar13 = (GmMat3 *)0x53d5a3;
    pGVar4 = (GmScaleTrans2 *)(**(code **)(*(int *)pCVar7 + 0x78))();
    GmIso4::SetInverse(auStack_30,pGVar4,(GmScaleTrans2 *)pGVar10);
    GmIso4::SetMult(&local_8c,(SPlugFaceCull *)param_2,aSStack_2c,pGVar11);
    GmMat3::OrthoNormalize(apCStack_88,pGVar13);
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        if (pCVar1 != pCStack_90) {
          pGVar12 = (GmIso3 *)0x53d5e6;
          pCVar2 = pCVar1;
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar1,unaff_EBP);
          pCVar7 = *(CHmsCorpus **)pSVar3;
          puVar8 = auStack_80;
          puVar9 = auStack_50;
          for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          unaff_EBP = 0x53d600;
          pGVar5 = (GmIso3 *)(**(code **)(*(int *)pCVar7 + 0x78))();
          GmIso4::Mult(auStack_5c,pGVar5,pGVar12);
          CHmsCorpus::SetLocation(pCVar7,aCStack_58,(GmIso4 *)pCVar2);
          pCVar7 = (CHmsCorpus *)local_8c;
          this_00 = pCStack_94;
          pCVar2 = apCStack_88[0];
        }
        pCVar1 = pCVar1 + 1;
      } while (pCVar1 < pCVar2);
    }
  }
  CHmsCorpus::SetLocation(pCVar7,in_stack_00000010,in_stack_ffffff60);
  return;
}
}

// =================================================
// Function: CHmsItem::SetOccluderForLightMap
// =================================================
void __thiscall CHmsItem::SetOccluderForLightMap(CHmsItem *this,CHmsItem *param_1,int param_2)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x18);
  if ((uVar1 >> 0x16 & 1) != (uint)(param_1 != (CHmsItem *)0x0)) {
    *(uint *)(this + 0x18) = ((uint)(param_1 != (CHmsItem *)0x0) << 0x16 ^ uVar1) & 0x400000 ^ uVar1
    ;
  }
  return;
}
}

// =================================================
// Function: CHmsItem::SetShadowCasterGroupMask
// =================================================
void __thiscall CHmsItem::SetShadowCasterGroupMask(CHmsItem *this,CHmsItem *param_1,ulong param_2)
{
{
  *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) ^ (*(uint *)(this + 0x1c) ^ (uint)param_1) & 0xfff
  ;
  if ((this[0x18] != (CHmsItem)0x0) && ((*(uint *)(this + 0x1c) & 0xfff) == 0)) {
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) & 0xfffff001 | 1;
  }
  return;
}
}

// =================================================
// Function: CHmsItem::SetShadowFakeEnable
// =================================================
void __thiscall CHmsItem::SetShadowFakeEnable(CHmsItem *this,CHmsItem *param_1,int param_2)
{
{
  *(uint *)(this + 0x18) =
       *(uint *)(this + 0x18) ^
       ((uint)(param_1 != (CHmsItem *)0x0) << 0x1b ^ *(uint *)(this + 0x18)) & 0x8000000;
  return;
}
}

// =================================================
// Function: CHmsItem::SetShadowReceiverGroupMask
// =================================================
void __thiscall CHmsItem::SetShadowReceiverGroupMask(CHmsItem *this,CHmsItem *param_1,ulong param_2)
{
{
  *(uint *)(this + 0x1c) = (int)param_1 << 0x14 | *(uint *)(this + 0x1c) & 0xfffff;
  return;
}
}

// =================================================
// Function: CHmsItem::SetSolid
// =================================================
void __thiscall CHmsItem::SetSolid(CHmsItem *this,CSceneToyMotorbike *param_1,CPlugSolid *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CMwNod *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CMwNod *unaff_EDI;
  ulong unaff_retaddr;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    if (*(int *)(this + 0x14) != 0) {
      *(undefined4 *)(*(int *)(this + 0x14) + 0x14) = 0;
      CMwNod::MwRelease(*(CMwNod **)(this + 0x14),unaff_ESI);
    }
    *(CSceneToyMotorbike **)(this + 0x14) = param_1;
    *(CHmsItem **)(param_1 + 0x14) = this;
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EBX);
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x34,pCVar3,unaff_retaddr);
        unaff_retaddr = 0x53cbe3;
        CHmsCorpus::RefreshFromSolid(*(CHmsCorpus **)pSVar2,(CHmsCorpus *)param_1);
        pCVar3 = pCVar3 + 1;
      } while (pCVar3 < pCVar1);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsItem::SetTorque
// =================================================
void __thiscall CHmsItem::SetTorque(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  GmVec3 *unaff_EBP;
  GmVec3 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x34,pCVar3,(ulong)unaff_EBP);
      if (*(void **)(*(int *)pSVar2 + 0x58) != (void *)0x0) {
        unaff_EBP = param_2;
        CHmsDyna::SetLocalTorque(*(void **)(*(int *)pSVar2 + 0x58),(CHmsDyna *)param_2,unaff_ESI);
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CHmsItem::StaticInit
// =================================================
void __cdecl CHmsItem::StaticInit(void)
{
{
  SCasterCat *pSVar1;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  ulong in_stack_00000004;
  ulong in_stack_00000008;
  ulong in_stack_0000000c;
  ulong in_stack_00000010;
  ulong in_stack_00000014;
  ulong in_stack_00000018;
  ulong in_stack_0000001c;
  ulong in_stack_00000020;
  ulong in_stack_00000024;
  ulong in_stack_00000028;
  ulong in_stack_0000002c;
  ulong in_stack_00000030;
  ulong in_stack_00000034;
  ulong in_stack_00000038;
  ulong in_stack_0000003c;
  ulong in_stack_00000040;
  ulong in_stack_00000044;
  ulong in_stack_00000048;
  ulong in_stack_0000004c;
  ulong in_stack_00000050;
  ulong in_stack_00000054;
  ulong in_stack_00000058;
  ulong in_stack_0000005c;
  
  CFastArray<struct_CSceneToySea::SThreadInfo>::SetCount
            (&DAT_00d67590,(CFastBuffer<class_CSystemFidsFolder*> *)&DAT_00000005,unaff_EDI);
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI)
  ;
  *(undefined4 *)pSVar1 = 3;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      unaff_retaddr);
  *(undefined4 *)(pSVar1 + 4) = 1;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      in_stack_00000004);
  *(undefined4 *)(pSVar1 + 0xc) = 0;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      in_stack_00000008);
  *(undefined4 *)(pSVar1 + 0x10) = 1;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      in_stack_0000000c);
  *(undefined4 *)(pSVar1 + 8) = 0;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                      in_stack_00000010);
  *(undefined4 *)pSVar1 = 2;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                      in_stack_00000014);
  *(undefined4 *)(pSVar1 + 4) = 4;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                      in_stack_00000018);
  *(undefined4 *)(pSVar1 + 0xc) = 1;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                      in_stack_0000001c);
  *(undefined4 *)(pSVar1 + 0x10) = 0;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                      in_stack_00000020);
  *(undefined4 *)(pSVar1 + 8) = 0;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                      in_stack_00000024);
  *(undefined4 *)pSVar1 = 3;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                      in_stack_00000028);
  *(undefined4 *)(pSVar1 + 4) = 3;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                      in_stack_0000002c);
  *(undefined4 *)(pSVar1 + 0xc) = 1;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                      in_stack_00000030);
  *(undefined4 *)(pSVar1 + 0x10) = 1;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                      in_stack_00000034);
  *(undefined4 *)(pSVar1 + 8) = 1;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                      in_stack_00000038);
  *(undefined4 *)pSVar1 = 3;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                      in_stack_0000003c);
  *(undefined4 *)(pSVar1 + 4) = 4;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                      in_stack_00000040);
  *(undefined4 *)(pSVar1 + 0xc) = 1;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                      in_stack_00000044);
  *(undefined4 *)(pSVar1 + 0x10) = 1;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                      in_stack_00000048);
  *(undefined4 *)(pSVar1 + 8) = 1;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004,
                      in_stack_0000004c);
  *(undefined4 *)pSVar1 = 1;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004,
                      in_stack_00000050);
  *(undefined4 *)(pSVar1 + 4) = 5;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004,
                      in_stack_00000054);
  *(undefined4 *)(pSVar1 + 0xc) = 1;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004,
                      in_stack_00000058);
  *(undefined4 *)(pSVar1 + 0x10) = 0;
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                     (&DAT_00d67590,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004,
                      in_stack_0000005c);
  *(undefined4 *)(pSVar1 + 8) = 0;
  return;
}
}

// =================================================
// Function: CHmsItem::TransformOf
// =================================================
/* WARNING: Type propagation algorithm not settling */

void __thiscall CHmsItem::TransformOf(CHmsItem *this,CHmsItem *param_1,GmIso4 *param_2)
{
{
  CHmsCorpus *this_00;
  SCasterCat *pSVar1;
  int iVar2;
  GmIso3 *unaff_EBX;
  GmIso3 *pGVar3;
  GmIso3 *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CHmsItem *this_01;
  undefined4 *puVar4;
  undefined4 *puVar5;
  ulong unaff_EDI;
  undefined4 *in_stack_0000000c;
  undefined4 *in_stack_00000010;
  GmIso3 *pGVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_38;
  CHmsItem *pCStack_34;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_30 [2];
  undefined4 local_28 [2];
  undefined4 local_20 [8];
  
  local_30[0] = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_ESI);
  local_38 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  this_01 = this + 0x34;
  if (local_30[0] != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pGVar6 = (GmIso3 *)0x53bd20;
      pCVar7 = local_38;
      pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_01,local_38,unaff_EDI)
      ;
      this_00 = *(CHmsCorpus **)pSVar1;
      if ((*(int *)(this_00 + 0x58) == 0) ||
         (pGVar3 = (GmIso3 *)(*(int *)(*(int *)(this_00 + 0x58) + 0x32c) + 0x10),
         pGVar3 == (GmIso3 *)0x0)) {
        puVar5 = in_stack_0000000c;
        puVar4 = local_28;
        for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar4 = puVar4 + 1;
        }
        unaff_EDI = 0x53bdaf;
        pGVar3 = (GmIso3 *)(**(code **)(*(int *)this_00 + 0x78))();
        GmIso4::Mult(&pCStack_34,pGVar3,pGVar6);
        CHmsCorpus::SetLocation(this_00,(CPlugTree *)local_30,(GmIso4 *)pCVar7);
      }
      else {
        puVar5 = in_stack_0000000c;
        puVar4 = local_28;
        for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar4 = puVar4 + 1;
        }
        GmIso4::Mult(local_28,pGVar3,unaff_EBP);
        puVar5 = local_28;
        for (iVar2 = 0xc; puVar5 = (undefined4 *)((int)puVar5 + 4), iVar2 != 0; iVar2 = iVar2 + -1)
        {
          *(undefined4 *)pGVar3 = *puVar5;
          pGVar3 = pGVar3 + 4;
        }
        if (*(int *)(this_00 + 0x58) == 0) {
          pGVar6 = (GmIso3 *)0x0;
        }
        else {
          pGVar6 = (GmIso3 *)(*(int *)(*(int *)(this_00 + 0x58) + 0x328) + 0x10);
        }
        puVar5 = local_28;
        puVar4 = in_stack_00000010;
        for (iVar2 = 0xc; puVar5 = (undefined4 *)((int)puVar5 + 4), iVar2 != 0; iVar2 = iVar2 + -1)
        {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
        }
        unaff_EDI = 0x53bd87;
        unaff_EBP = pGVar6;
        GmIso4::Mult(local_28 + 1,pGVar6,unaff_EBX);
        puVar5 = local_28 + 2;
        for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
          *(undefined4 *)pGVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          pGVar6 = pGVar6 + 4;
        }
      }
      local_38 = local_38 + 1;
      this_01 = pCStack_34;
    } while (local_38 < local_30[0]);
  }
  return;
}
}

// =================================================
// Function: CHmsItem::UpdateCorpusCat
// =================================================
void __thiscall CHmsItem::UpdateCorpusCat(CHmsItem *this,CHmsItem *param_1)
{
{
  CHmsZone *this_00;
  CHmsItem *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  CHmsItem *unaff_EBX;
  CHmsItem *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CHmsItem *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CHmsZone *in_stack_00000008;
  EHmsCorpusCat in_stack_fffffff0;
  int local_4;
  
  pCVar1 = (CHmsItem *)GetCorpusCat(this,unaff_EDI);
  param_1 = (CHmsItem *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_ESI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (param_1 != (CHmsItem *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x34,pCVar4,(ulong)unaff_EBP);
      local_4 = *(int *)pSVar2;
      this_00 = *(CHmsZone **)(local_4 + 0x14);
      unaff_EBP = (CHmsItem *)register0x00000010;
      iVar3 = CFastBufferCat<class_CMwCmd*,struct_SFastCat>::FindIndexInAll
                        (this_00 + 0x1c,(CFastBufferCat<class_CMwCmd*,struct_SFastCat> *)&local_4,
                         (CMwCmd **)&param_1,(ulong *)&stack0x00000000,(ulong *)unaff_EBX);
      if ((iVar3 != 0) && (param_1 != pCVar1)) {
        unaff_EBP = param_1;
        unaff_EBX = pCVar1;
        CHmsZone::CorpusChangeCat
                  (this_00,in_stack_00000008,(ulong)param_1,(EHmsCorpusCat)pCVar1,in_stack_fffffff0)
        ;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < param_1);
  }
  return;
}
}

// =================================================
// Function: CHmsItem::UpdateIsBuild
// =================================================
void __thiscall CHmsItem::UpdateIsBuild(CHmsItem *this,CHmsItem *param_1)
{
{
  CHmsZone *this_00;
  int iVar1;
  CHmsCorpus *pCVar2;
  SCasterCat *pSVar3;
  ulong uVar4;
  uint uVar5;
  CHmsCorpus *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CHmsItem *this_01;
  CHmsZone *unaff_EDI;
  CHmsItem *unaff_retaddr;
  CHmsZone *pCVar7;
  int in_stack_fffffff4;
  
  CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x28,unaff_ESI);
  pCVar2 = (CHmsCorpus *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EBP);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  this_01 = this + 0x34;
  if (pCVar2 != (CHmsCorpus *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_01,pCVar6,(ulong)unaff_EDI);
      pCVar7 = *(CHmsZone **)pSVar3;
      this_00 = *(CHmsZone **)(pCVar7 + 0x14);
      iVar1 = *(int *)(this_00 + 0x2c);
      unaff_EDI = (CHmsZone *)0x53d21c;
      uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (this_00 + 0x28,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
      uVar5 = 0;
      if (uVar4 != 0) {
        do {
          if (*(CHmsZone **)(iVar1 + uVar5 * 4) == pCVar7) {
            unaff_EBX = pCVar2;
            CHmsZone::CorpusChangeBuild(this_00,pCVar7,pCVar2,in_stack_fffffff4);
            unaff_EDI = pCVar7;
            break;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar4);
      }
      pCVar6 = pCVar6 + 1;
      this_01 = unaff_retaddr;
    } while (pCVar6 < pCVar2);
  }
  return;
}
}

// =================================================
// Function: CHmsItem::VirtualParam_Get
// =================================================
ulong __thiscall
CHmsItem::VirtualParam_Get
          (CHmsItem *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  CHmsItem *pCVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  CMwParamVec3 *this_00;
  CMwParamVec3 *this_01;
  GmVec3 *unaff_EDI;
  
  iVar2 = *(int *)(param_1 + 0x18);
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + iVar2 * 4);
  *(int *)(param_1 + 0x18) = iVar2 + -1;
  uVar4 = *(uint *)(iVar3 + 4);
  if (uVar4 < 0x600301d) {
    if (uVar4 == 0x600301c) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x1c & 1;
      return 0;
    }
    switch(uVar4) {
    case 0x6003003:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0xd & 0xf;
      return 0;
    case 0x6003004:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0xb & 3;
      return 0;
    case 0x6003005:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x11 & 3;
      return 0;
    case 0x6003006:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x14 & 1;
      return 0;
    case 0x6003007:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 8 & 1;
      return 0;
    case 0x6003008:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x13 & 1;
      return 0;
    case 0x6003009:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 9 & 1;
      return 0;
    case 0x600300a:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x19 & 1;
      return 0;
    case 0x600300b:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x1a & 1;
      return 0;
    case 0x600300c:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 10 & 1;
      return 0;
    case 0x600300d:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x16 & 1;
      return 0;
    case 0x600300e:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) >> 0xc & 1;
      return 0;
    case 0x600300f:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (uint)(byte)this[0x18];
      return 0;
    case 0x6003010:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x17 & 1;
      return 0;
    case 0x6003011:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x1b & 1;
      return 0;
    case 0x6003012:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) & 1;
      return 0;
    case 0x6003013:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) & 2;
      return 0;
    case 0x6003014:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) & 4;
      return 0;
    case 0x6003015:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) & 8;
      return 0;
    case 0x6003016:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) >> 0x14 & 1;
      return 0;
    case 0x6003017:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) >> 0x14 & 2;
      return 0;
    case 0x6003018:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) >> 0x14 & 4;
      return 0;
    case 0x6003019:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) >> 0x14 & 8;
      return 0;
    case 0x600301b:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x1b] & 1;
      return 0;
    }
  }
  else if (uVar4 < 0x6003029) {
    if (uVar4 == 0x6003028) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (uint)((byte)this[0x20] >> 7);
      return 0;
    }
    switch(uVar4) {
    case 0x600301d:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x1e] & 1;
      return 0;
    case 0x600301e:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x1e] & 2;
      return 0;
    case 0x600301f:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x1e] & 4;
      return 0;
    case 0x6003020:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x1e] & 8;
      return 0;
    case 0x6003021:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x20] & 1;
      return 0;
    case 0x6003022:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x20] >> 1 & 1;
      return 0;
    case 0x6003023:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x20] >> 2 & 1;
      return 0;
    case 0x6003024:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x20] >> 3 & 1;
      return 0;
    case 0x6003025:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x20] >> 4 & 1;
      return 0;
    case 0x6003026:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x20] >> 5 & 1;
      return 0;
    case 0x6003027:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x20] >> 6 & 1;
      return 0;
    }
  }
  else if (uVar4 < 0x600302f) {
    if (uVar4 == 0x600302e) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0x20) >> 0xd & 1;
      return 0;
    }
    switch(uVar4) {
    case 0x6003029:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x21] & 1;
      return 0;
    case 0x600302a:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0x20) >> 9 & 1;
      return 0;
    case 0x600302b:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0x20) >> 10 & 1;
      return 0;
    case 0x600302c:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0x20) >> 0xb & 1;
      return 0;
    case 0x600302d:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0x20) >> 0xc & 1;
      return 0;
    }
  }
  else {
    if (0x6003032 < uVar4) {
      if (uVar4 == 0x6003033) {
        pCVar1 = (CHmsItem *)(param_2 + 4);
        *(CHmsItem **)param_2 = pCVar1;
        GetLinearSpeed(this,pCVar1,unaff_EDI);
        CMwParamVec3::GetValue(this_01,(CFuncColorGradient *)pCVar1,(float)param_1);
      }
      else if (uVar4 != 0xffffffff) goto switchD_0053c498_caseD_600301a;
      return 0;
    }
    if (uVar4 == 0x6003032) {
      pCVar1 = (CHmsItem *)(param_2 + 4);
      *(CHmsItem **)param_2 = pCVar1;
      GetAngularSpeed(this,pCVar1,unaff_EDI);
      CMwParamVec3::GetValue(this_00,(CFuncColorGradient *)pCVar1,(float)param_1);
      return 0;
    }
    if (uVar4 == 0x600302f) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0x20) >> 0xe & 1;
      return 0;
    }
    if (uVar4 == 0x6003030) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) >> 0xf & 1;
      return 0;
    }
  }
switchD_0053c498_caseD_600301a:
  *(int *)(param_1 + 0x18) = iVar2;
  uVar5 = CMwNod::VirtualParam_Get((CMwNod *)this,param_1,param_2,(CMwValueStd *)unaff_EDI);
  return uVar5;
}
}

// =================================================
// Function: CHmsItem::VirtualParam_Set
// =================================================
ulong __thiscall
CHmsItem::VirtualParam_Set(CHmsItem *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  CHmsItem *pCVar7;
  GmVec3 *pGVar8;
  ulong uVar9;
  ushort uVar10;
  GmVec3 *unaff_ESI;
  CPlugSolid *unaff_EDI;
  CHmsItem local_c [4];
  CHmsItem local_8 [8];
  
  iVar2 = *(int *)(param_1 + 0x18);
  piVar3 = *(int **)(param_1 + 0x10);
  iVar4 = piVar3[iVar2];
  iVar1 = iVar2 + -1;
  *(int *)(param_1 + 0x18) = iVar1;
  uVar6 = *(uint *)(iVar4 + 4);
  if (uVar6 < 0x6003021) {
    cVar5 = (char)uVar6;
    if (0x600301c < uVar6) {
      uVar6 = *(uint *)(this + 0x1c);
      *(uint *)(this + 0x1c) =
           ((~(1 << (cVar5 - 0x1dU & 0x1f)) << 0x10 & uVar6 |
            ((uint)(*(int *)param_2 != 0) << (cVar5 - 0x1dU & 0x1f)) << 0x10) ^ uVar6) & 0xf0000 ^
           uVar6;
      return 0;
    }
    switch(uVar6) {
    case 0x6003000:
      if (-1 < iVar1) {
        CMwParamClass::SetValue((CMwParamClass *)param_2,(CMwCmdAffectParamBool *)(this + 0x14));
        return 0;
      }
      SetSolid(this,(CSceneToyMotorbike *)param_2,unaff_EDI);
      return 0;
    case 0x6003003:
      SetCollisionGroup(this,*(CHmsItem **)param_2,(ECollisionGroup)unaff_EDI);
      return 0;
    case 0x6003004:
      SetDynamicType(this,*(CHmsItem **)param_2,(EDynamicType)unaff_EDI);
      return 0;
    case 0x6003005:
      SetContactInterest(this,*(CHmsItem **)param_2,(EContactInterest)unaff_EDI);
      return 0;
    case 0x6003006:
      SetIsKinematicOnly(this,*(CHmsItem **)param_2,(int)unaff_EDI);
      return 0;
    case 0x6003007:
      SetIsVisionStatic(this,*(CHmsItem **)param_2,(int)unaff_EDI);
      return 0;
    case 0x6003008:
      SetIsCollisionStatic(this,*(CHmsItem **)param_2,(int)unaff_EDI);
      return 0;
    case 0x6003009:
      if ((CHmsItem *)(uint)(*(int *)param_2 != 0) == (CHmsItem *)(*(uint *)(this + 0x18) >> 9 & 1))
      {
        return 0;
      }
      SetIsBackground(this,(CHmsItem *)(uint)(*(int *)param_2 != 0),(int)unaff_EDI);
      return 0;
    case 0x600300a:
      *(uint *)(this + 0x18) =
           *(uint *)(this + 0x18) ^
           ((uint)(*(int *)param_2 != 0) << 0x19 ^ *(uint *)(this + 0x18)) & 0x2000000;
      return 0;
    case 0x600300b:
      *(uint *)(this + 0x18) =
           *(uint *)(this + 0x18) ^
           ((uint)(*(int *)param_2 != 0) << 0x1a ^ *(uint *)(this + 0x18)) & 0x4000000;
      return 0;
    case 0x600300c:
      *(uint *)(this + 0x18) =
           *(uint *)(this + 0x18) ^
           ((uint)(*(int *)param_2 != 0) << 10 ^ *(uint *)(this + 0x18)) & 0x400;
      return 0;
    case 0x600300d:
      SetOccluderForLightMap(this,*(CHmsItem **)param_2,(int)unaff_EDI);
      return 0;
    case 0x600300e:
      SetIsForcePointDynamicCollisionResponse(this,*(CHmsItem **)param_2,(int)unaff_EDI);
      return 0;
    case 0x600300f:
      pCVar7 = *(CHmsItem **)param_2;
      if ((CHmsItem *)0xff < pCVar7) {
        pCVar7 = (CHmsItem *)0xff;
      }
      SetCountShadowTexCasted(this,pCVar7,(byte)(*(uint *)(this + 0x18) >> 0x17) & 1,(int)unaff_EDI)
      ;
      return 0;
    case 0x6003010:
      *(uint *)(this + 0x18) =
           *(uint *)(this + 0x18) ^
           ((uint)(*(int *)param_2 != 0) << 0x17 ^ *(uint *)(this + 0x18)) & 0x800000;
      return 0;
    case 0x6003011:
      SetShadowFakeEnable(this,*(CHmsItem **)param_2,(int)unaff_EDI);
      return 0;
    case 0x6003012:
    case 0x6003013:
    case 0x6003014:
    case 0x6003015:
      uVar6 = *(uint *)(this + 0x1c);
      uVar6 = ((~(1 << (cVar5 - 0x12U & 0x1f)) & uVar6 |
               (uint)(*(int *)param_2 != 0) << (cVar5 - 0x12U & 0x1f)) ^ uVar6) & 0xfff ^ uVar6;
      *(uint *)(this + 0x1c) = uVar6;
      if (this[0x18] == (CHmsItem)0x0) {
        return 0;
      }
      if ((uVar6 & 0xfff) != 0) {
        return 0;
      }
      *(uint *)(this + 0x1c) = uVar6 & 0xfffff001 | 1;
      return 0;
    case 0x6003016:
    case 0x6003017:
    case 0x6003018:
    case 0x6003019:
      *(uint *)(this + 0x1c) =
           (~(1 << (cVar5 - 0x16U & 0x1f)) << 0x14 & *(uint *)(this + 0x1c) |
           ((uint)(*(int *)param_2 != 0) << (cVar5 - 0x16U & 0x1f)) << 0x14) ^
           *(uint *)(this + 0x1c) & 0xfffff;
      return 0;
    case 0x600301b:
      *(uint *)(this + 0x18) =
           *(uint *)(this + 0x18) ^ (*(int *)param_2 << 0x18 ^ *(uint *)(this + 0x18)) & 0x1000000;
      return 0;
    case 0x600301c:
      SetLightLensFlareEnable(this,*(CHmsItem **)param_2,(int)unaff_EDI);
      return 0;
    }
  }
  else {
    if (uVar6 < 0x600302c) {
      if (uVar6 == 0x600302b) {
        param_2 = (CMwStack *)
                  CONCAT22(param_2._2_2_,
                           ((ushort)(*(int *)param_2 != 0) << 10 ^ *(ushort *)(this + 0x20)) & 0x400
                           ^ *(ushort *)(this + 0x20));
        VisibleIdSet(this,(CHmsItem *)&param_2,(SPlugVisibleId *)unaff_EDI);
        return 0;
      }
      switch(uVar6) {
      case 0x6003021:
        uVar10 = (*(int *)param_2 != 0 ^ (byte)this[0x20]) & 1;
        break;
      case 0x6003022:
        uVar10 = (byte)((*(int *)param_2 != 0) * '\x02' ^ (byte)this[0x20]) & 2;
        break;
      case 0x6003023:
        uVar10 = (byte)((*(int *)param_2 != 0) * '\x04' ^ (byte)this[0x20]) & 4;
        break;
      case 0x6003024:
        uVar10 = (byte)((*(int *)param_2 != 0) * '\b' ^ (byte)this[0x20]) & 8;
        break;
      case 0x6003025:
        uVar10 = (byte)((*(int *)param_2 != 0) << 4 ^ (byte)this[0x20]) & 0x10;
        break;
      case 0x6003026:
        uVar10 = (byte)((*(int *)param_2 != 0) << 5 ^ (byte)this[0x20]) & 0x20;
        break;
      case 0x6003027:
        uVar10 = (byte)((*(int *)param_2 != 0) << 6 ^ (byte)this[0x20]) & 0x40;
        break;
      case 0x6003028:
        uVar10 = (byte)((*(int *)param_2 != 0) << 7 ^ (byte)this[0x20]) & 0x80;
        break;
      case 0x6003029:
        param_2 = (CMwStack *)
                  CONCAT22(param_2._2_2_,
                           ((ushort)(*(int *)param_2 != 0) << 8 ^ *(ushort *)(this + 0x20)) & 0x100
                           ^ *(ushort *)(this + 0x20));
        VisibleIdSet(this,(CHmsItem *)&param_2,(SPlugVisibleId *)unaff_EDI);
        return 0;
      case 0x600302a:
        param_2 = (CMwStack *)
                  CONCAT22(param_2._2_2_,
                           ((ushort)(*(int *)param_2 != 0) << 9 ^ *(ushort *)(this + 0x20)) & 0x200
                           ^ *(ushort *)(this + 0x20));
        VisibleIdSet(this,(CHmsItem *)&param_2,(SPlugVisibleId *)unaff_EDI);
        return 0;
      default:
        goto switchD_0053d8f4_caseD_6003001;
      }
      param_2 = (CMwStack *)CONCAT22(param_2._2_2_,uVar10 ^ *(ushort *)(this + 0x20));
      VisibleIdSet(this,(CHmsItem *)&param_2,(SPlugVisibleId *)unaff_EDI);
      return 0;
    }
    if (uVar6 < 0x6003031) {
      if (uVar6 == 0x6003030) {
        IsVisibleSet(this,*(CHmsItem **)param_2,(int)unaff_EDI);
        return 0;
      }
      switch(uVar6) {
      case 0x600302c:
        param_2 = (CMwStack *)
                  CONCAT22(param_2._2_2_,
                           ((ushort)(*(int *)param_2 != 0) << 0xb ^ *(ushort *)(this + 0x20)) &
                           0x800 ^ *(ushort *)(this + 0x20));
        VisibleIdSet(this,(CHmsItem *)&param_2,(SPlugVisibleId *)unaff_EDI);
        return 0;
      case 0x600302d:
        param_2 = (CMwStack *)
                  CONCAT22(param_2._2_2_,
                           ((ushort)(*(int *)param_2 != 0) << 0xc ^ *(ushort *)(this + 0x20)) &
                           0x1000 ^ *(ushort *)(this + 0x20));
        VisibleIdSet(this,(CHmsItem *)&param_2,(SPlugVisibleId *)unaff_EDI);
        return 0;
      case 0x600302e:
        param_2 = (CMwStack *)
                  CONCAT22(param_2._2_2_,
                           ((ushort)(*(int *)param_2 != 0) << 0xd ^ *(ushort *)(this + 0x20)) &
                           0x2000 ^ *(ushort *)(this + 0x20));
        VisibleIdSet(this,(CHmsItem *)&param_2,(SPlugVisibleId *)unaff_EDI);
        return 0;
      case 0x600302f:
        param_2 = (CMwStack *)
                  CONCAT22(param_2._2_2_,
                           ((ushort)(*(int *)param_2 != 0) << 0xe ^ *(ushort *)(this + 0x20)) &
                           0x4000 ^ *(ushort *)(this + 0x20));
        VisibleIdSet(this,(CHmsItem *)&param_2,(SPlugVisibleId *)unaff_EDI);
        return 0;
      }
    }
    else if (uVar6 < 0x6003034) {
      if (uVar6 == 0x6003033) {
        if (-1 < iVar1) {
          iVar1 = *piVar3;
          GetLinearSpeed(this,local_c,(GmVec3 *)unaff_EDI);
          *(undefined4 *)(local_8 + iVar1 * 4) = *(undefined4 *)param_3;
          SetLinearSpeed(this,local_8,unaff_ESI);
          return 0;
        }
        SetLinearSpeed(this,(CHmsItem *)param_2,(GmVec3 *)unaff_EDI);
        return 0;
      }
      if (uVar6 == 0x6003031) {
        param_2 = (CMwStack *)0xffffffff;
        pCVar7 = (CHmsItem *)
                 CMwStack::GetArgument
                           ((CMwStack *)param_1,(CMwStack *)0x0,0x10000006,(EStackType)&param_2,
                            (ulong *)unaff_EDI);
        pGVar8 = (GmVec3 *)
                 CMwStack::GetArgument
                           ((CMwStack *)param_1,(CMwStack *)0x1,0x10000006,(EStackType)&param_3,
                            (ulong *)unaff_ESI);
        if ((pCVar7 != (CHmsItem *)0x0) && (pGVar8 != (GmVec3 *)0x0)) {
          AddImpulse(this,pCVar7,pGVar8);
          return 0;
        }
        return 0;
      }
      if (uVar6 == 0x6003032) {
        if (-1 < iVar1) {
          iVar1 = *piVar3;
          GetAngularSpeed(this,local_c,(GmVec3 *)unaff_EDI);
          *(undefined4 *)(local_8 + iVar1 * 4) = *(undefined4 *)param_3;
          SetAngularSpeed(this,local_8,unaff_ESI);
          return 0;
        }
        SetAngularSpeed(this,(CHmsItem *)param_2,(GmVec3 *)unaff_EDI);
        return 0;
      }
    }
    else if (uVar6 == 0xffffffff) {
      return 0;
    }
  }
switchD_0053d8f4_caseD_6003001:
  *(int *)(param_1 + 0x18) = iVar2;
  uVar9 = CMwNod::VirtualParam_Set((CMwNod *)this,param_1,param_2,unaff_EDI);
  return uVar9;
}
}

// =================================================
// Function: CHmsItem::VisibleIdSet
// =================================================
void __thiscall CHmsItem::VisibleIdSet(CHmsItem *this,CHmsItem *param_1,SPlugVisibleId *param_2)
{
{
  int unaff_EDI;
  
  if ((((byte)this[0x20] ^ (byte)*(ushort *)param_1) & 1) != 0) {
    SetLightEmitter(this,(CHmsItem *)(*(ushort *)param_1 & 1),unaff_EDI);
    *(undefined2 *)(this + 0x20) = *(undefined2 *)param_1;
    return;
  }
  *(undefined2 *)(this + 0x20) = *(undefined2 *)param_1;
  return;
}
}

// =================================================
// Function: CHmsItem::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CHmsItem::_scalar_deleting_destructor_(CHmsItem *this,CPfmHeap *param_1,uint param_2)
{
{
  CHmsItem *unaff_ESI;
  
  ~CHmsItem(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CHmsItem::~CHmsItem
// =================================================
void __thiscall CHmsItem::~CHmsItem(CHmsItem *this,CHmsItem *param_1)
{
{
  void *this_00;
  SCallbackList *pSVar1;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  void *in_stack_0000000c;
  undefined4 uStack00000010;
  CHmsItem *pCVar2;
  CFastArray<class_CFuncShader*> *pCVar3;
  CMwNod *pCVar4;
  
  pCVar3 = ExceptionList;
  pCVar4 = (CMwNod *)&LAB_00a95889;
  pSVar1 = (SCallbackList *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &stack0xfffffff4;
  *(undefined ***)this = vftable;
  pCVar2 = this;
  operator_delete(*(void **)(this + 0x54));
  this_00 = *(void **)(this + 0x24);
  *(undefined4 *)(this + 0x54) = 0;
  if (this_00 != (void *)0x0) {
    SCallbackList::~SCallbackList(this_00,pSVar1);
    operator_delete(this_00);
  }
  *(undefined4 *)(this + 0x24) = 0;
  if (*(int *)(this + 0x14) != 0) {
    *(undefined4 *)(*(int *)(this + 0x14) + 0x14) = 0;
    CMwNod::MwRelease(*(CMwNod **)(this + 0x14),unaff_EDI);
  }
  CFastArray<class_CFuncKeysPath*>::ReleaseAll
            (this + 0x28,(CFastBuffer<class_CSystemPackDesc*> *)unaff_EDI);
  if (*(CMwNod **)(this + 0x44) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x44),unaff_ESI);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0x34,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar2);
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>(this + 0x28,pCVar3);
  uStack00000010 = 0xffffffff;
  CMwNod::~CMwNod((CMwNod *)this,pCVar4);
  ExceptionList = in_stack_0000000c;
  return;
}
}

