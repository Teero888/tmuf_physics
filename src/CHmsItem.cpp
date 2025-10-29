// TODO: CALLBACK TYPES OF THIS THING
// CCallback
// CCallbackAbsorbContact
// CCallbackAfterContacts
// CCallbackComputeForces
// CCallbackOnVisibleWake
// CCallbackRenderBeforeItem
// CCallbackRenderBeforeTree
// CCallbackSortCustom

/* public: virtual void * __thiscall CHmsItem::`scalar deleting
 * destructor'(unsigned int) */

void *__thiscall CHmsItem::`scalar_deleting_destructor'(CHmsItem *this,uint param_1)

{
  ~CHmsItem(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
/* public: void __thiscall CHmsItem::AddCorpus(class CHmsCorpus *) */

void __thiscall CHmsItem::AddCorpus(CHmsItem *this, CHmsCorpus *param_1)

{
  CFastBuffer<>::Add((CFastBuffer<> *)(this + 0x34),
                     (CDx9TextureKeeper **)&param_1);
  return;
}

/* public: void __thiscall CHmsItem::AddForce(class GmVec3 const &) */

void __thiscall CHmsItem::AddForce(CHmsItem *this, GmVec3 *param_1)

{
  ulong uVar1;
  int *piVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      if (*(CHmsDyna **)(*piVar2 + 0x58) != (CHmsDyna *)0x0) {
        CHmsDyna::AddLocalForce(*(CHmsDyna **)(*piVar2 + 0x58), param_1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* public: void __thiscall CHmsItem::AddForce(class GmVec3 const &,class GmVec3
 * const &) */

void __thiscall CHmsItem::AddForce(CHmsItem *this, GmVec3 *param_1,
                                   GmVec3 *param_2)

{
  ulong uVar1;
  int *piVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      if (*(CHmsDyna **)(*piVar2 + 0x58) != (CHmsDyna *)0x0) {
        CHmsDyna::AddLocalForce(*(CHmsDyna **)(*piVar2 + 0x58), param_1,
                                param_2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* public: void __thiscall CHmsItem::AddImpulse(class GmVec3 const &,class
 * GmVec3 const &) */

void __thiscall CHmsItem::AddImpulse(CHmsItem *this, GmVec3 *param_1,
                                     GmVec3 *param_2)

{
  ulong uVar1;
  int *piVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      if (*(CHmsDyna **)(*piVar2 + 0x58) != (CHmsDyna *)0x0) {
        CHmsDyna::AddLocalImpulse(*(CHmsDyna **)(*piVar2 + 0x58), param_1,
                                  param_2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* public: void __thiscall CHmsItem::AddImpulse(class GmVec3 const &) */

void __thiscall CHmsItem::AddImpulse(CHmsItem *this, GmVec3 *param_1)

{
  ulong uVar1;
  int *piVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      if (*(CHmsDyna **)(*piVar2 + 0x58) != (CHmsDyna *)0x0) {
        CHmsDyna::AddLocalImpulse(*(CHmsDyna **)(*piVar2 + 0x58), param_1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* public: void __thiscall CHmsItem::AddStateForPrediction(class
   CClassicBufferMemory &,unsigned long,enum CHmsItem::ESaveStateVersion) */

void __thiscall CHmsItem::AddStateForPrediction(CHmsItem *this,
                                                CClassicBufferMemory *param_1,
                                                ulong param_2,
                                                ESaveStateVersion param_3)

{
  int *piVar1;

  piVar1 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x34), 0);
  if (*(int *)(*piVar1 + 0x58) != 0) {
    piVar1 =
        (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x34), 0);
    CHmsDyna::AddStateForPrediction(*(CHmsDyna **)(*piVar1 + 0x58), param_1,
                                    param_2, (uchar)param_3);
    return;
  }
  return;
}

/* public: void __thiscall CHmsItem::AddTorque(class GmVec3 const &) */

void __thiscall CHmsItem::AddTorque(CHmsItem *this, GmVec3 *param_1)

{
  ulong uVar1;
  int *piVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      if (*(CHmsDyna **)(*piVar2 + 0x58) != (CHmsDyna *)0x0) {
        CHmsDyna::AddLocalTorque(*(CHmsDyna **)(*piVar2 + 0x58), param_1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* public: void __thiscall CHmsItem::CallbackSet(enum CHmsItem::ECallback,class
 *CHmsItem::CCallback
 *) */

void __thiscall CHmsItem::CallbackSet(CHmsItem *this, ECallback param_1,
                                      CCallback *param_2)

{
  int iVar1;
  int *piVar2;
  ECallback EVar3;
  SCallbackList *this_00;
  undefined4 uVar4;

  if ((param_2 != (CCallback *)0x0) &&
      (EVar3 = (**(code **)(*(int *)param_2 + 8))(), EVar3 != param_1)) {
    return;
  }
  if (*(int *)(this + 0x24) == 0) {
    if (param_2 == (CCallback *)0x0) {
      return;
    }
    this_00 = (SCallbackList *)operator_new(0x18);
    if (this_00 == (SCallbackList *)0x0) {
      uVar4 = 0;
    } else {
      uVar4 = SCallbackList::SCallbackList(this_00);
    }
    *(undefined4 *)(this + 0x24) = uVar4;
  }
  iVar1 = *(int *)(this + 0x24);
  piVar2 = *(int **)(iVar1 + param_1 * 4);
  if (piVar2 != (int *)param_2) {
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))();
    }
    *(CCallback **)(iVar1 + param_1 * 4) = param_2;
  }
  return;
}

/* public: static void __cdecl CHmsItem::CallbackSetRenderBeforeTree(class
   CHmsItem::CCallbackRenderBeforeTree *) */

void __cdecl CHmsItem::CallbackSetRenderBeforeTree(
    CCallbackRenderBeforeTree *param_1)

{
  s_CallbackRenderBeforeTree = param_1;
  return;
}

/* public: virtual __thiscall CHmsItem::CCallback::~CCallback(void) */

void __thiscall CHmsItem::CCallback::~CCallback(CCallback *this)

{
  *(undefined ***)this = vftable;
  return;
}

/* public: __thiscall CHmsItem::CHmsItem(void) */

CHmsItem *__thiscall CHmsItem::CHmsItem(CHmsItem *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a957d9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwNod::CMwNod((CMwNod *)this);
  local_4 = 0;
  *(undefined ***)this = vftable;
  CFastArray<>::CFastArray<>((CFastArray<> *)(this + 0x28));
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x34));
  *(undefined4 *)(this + 0x44) = 0;
  local_4 = CONCAT31(local_4._1_3_, 3);
  CFastBuffer<int>::SetSizeAtLeast(
      (CFastBuffer<int> *)(CFastBuffer<> *)(this + 0x34), 1);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x50) = 0xbf800000;
  this[0x18] = (CHmsItem)0x0;
  *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0xff8004ff | 0x19800000;
  *(undefined4 *)(this + 0x1c) = 0xfff1c000;
  *(undefined2 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0xffffffff;
  ExceptionList = local_c;
  return this;
}

/* public: virtual void __thiscall CHmsItem::Chunk(class CClassicArchive
 * &,unsigned long) */

void __thiscall CHmsItem::Chunk(CHmsItem *this, CClassicArchive *param_1,
                                ulong param_2)

{
  uint *puVar1;
  uint uVar2;
  CClassicArchive *this_00;
  CPlugSolid *pCVar3;
  int local_18;
  int local_14;
  int local_10;
  ulong local_c;
  undefined4 local_8;
  uint local_4;

  this_00 = param_1;
  if (0x6003009 < param_2) {
    if (param_2 < 0x600300f) {
      if (param_2 == 0x600300e) {
        *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0x1fffffff;
        puVar1 = (uint *)(this + 0x18);
        CClassicArchive::DoData(param_1, puVar1, 8);
        CClassicArchive::DoNat16(this_00, (ushort *)(this + 0x20), 1, 0);
        *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0xfff00000;
        *puVar1 = *puVar1 & 0xfffffbff | 0x11000000;
        return;
      }
      switch (param_2) {
      case 0x600300a:
        CClassicArchive::DoData(param_1, &local_8, 8);
        *(uint *)(this + 0x18) = local_8;
        *(uint *)(this + 0x1c) = local_4;
        if (0xb < (local_4 & 0xfff)) {
          local_4 = local_4 & 0xfffff000;
        }
        *(uint *)(this + 0x1c) = 1 << ((byte)local_4 & 0x1f) & 0xfffU |
                                 *(uint *)(this + 0x1c) & 0x7000 | 0xfff18000;
        *(ushort *)(this + 0x20) = (ushort)local_8._3_1_;
        *(uint *)(this + 0x18) = local_8 & 0xefffbff | 0x11000000;
        SetLightEmitter(this, local_8 >> 10 & 1);
        return;
      case 0x600300b:
        *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0x1fffffff;
        puVar1 = (uint *)(this + 0x18);
        CClassicArchive::DoData(param_1, puVar1, 8);
        *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) & 0x7fff | 0xfff18000;
        *puVar1 = *puVar1 & 0xfffffbff | 0x11000000;
        CClassicArchive::DoNat16(this_00, (ushort *)(this + 0x20), 1, 0);
        if (0xb < (*(uint *)(this + 0x1c) & 0xfff)) {
          *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) & 0xfffff000;
        }
        uVar2 = *(uint *)(this + 0x1c);
        *(uint *)(this + 0x1c) =
            (1 << ((byte)uVar2 & 0x1f) ^ uVar2) & 0xfff ^ uVar2;
        return;
      case 0x600300c:
        *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0x1fffffff;
        puVar1 = (uint *)(this + 0x18);
        CClassicArchive::DoData(param_1, puVar1, 8);
        *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) & 0x7fff | 0xfff18000;
        *puVar1 = *puVar1 & 0xfffffbff | 0x11000000;
        CClassicArchive::DoNat16(this_00, (ushort *)(this + 0x20), 1, 0);
        return;
      case 0x600300d:
        *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0x1fffffff;
        puVar1 = (uint *)(this + 0x18);
        CClassicArchive::DoData(param_1, puVar1, 8);
        CClassicArchive::DoNat16(this_00, (ushort *)(this + 0x20), 1, 0);
        *puVar1 = *puVar1 & 0xfffffbff | 0x11000000;
        *(uint *)(this + 0x1c) = *(ushort *)(this + 0x1c) | 0xfff10000;
        return;
      }
    } else if (param_2 < 0x6003012) {
      if (param_2 == 0x6003011) {
        *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0x1fffffff;
        CClassicArchive::DoData(param_1, this + 0x18, 8);
        CClassicArchive::DoNat16(this_00, (ushort *)(this + 0x20), 1, 0);
        return;
      }
      if (param_2 == 0x600300f) {
        *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0x1fffffff;
        puVar1 = (uint *)(this + 0x18);
        CClassicArchive::DoData(param_1, puVar1, 8);
        CClassicArchive::DoNat16(this_00, (ushort *)(this + 0x20), 1, 0);
        *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0xfff00000;
        *puVar1 = *puVar1 & 0xfffffbff | 0x10000000;
        return;
      }
      if (param_2 == 0x6003010) {
        *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0x1fffffff;
        puVar1 = (uint *)(this + 0x18);
        CClassicArchive::DoData(param_1, puVar1, 8);
        CClassicArchive::DoNat16(this_00, (ushort *)(this + 0x20), 1, 0);
        *puVar1 = *puVar1 | 0x10000000;
        return;
      }
    } else if (param_2 == 0xffffffff) {
      return;
    }
  switchD_0053e0ec_caseD_9:
    CMwNod::Chunk((CMwNod *)this, param_1, param_2);
    return;
  }
  if (param_2 == 0x6003009) {
    CClassicArchive::DoData(param_1, &param_1, 4);
    *(uint *)(this + 0x1c) = (uint)(((uint)param_1 & 0xff) != 0) |
                             *(uint *)(this + 0x1c) & 0x7000 | 0xfff18000;
    *(uint *)(this + 0x18) = (uint)param_1 & 0xfffffbff | 0x11000000;
    SetLightEmitter(this, (uint)param_1 >> 10 & 1);
    return;
  }
  switch (param_2) {
  case 0x6003000:
    CClassicArchive::DoNatural(param_1, &local_c, 1, 0);
    CClassicArchive::DoBool(this_00, (int *)&param_1, 1);
    SetCollisionGroup(this, -(uint)(param_1 != (CClassicArchive *)0x0) & 4);
    CClassicArchive::DoBool(this_00, (int *)&param_2, 1);
    SetContactInterest(this, -(uint)(param_2 != 0) & 2);
    CClassicArchive::DoBool(this_00, &local_18, 1);
    SetDynamicType(this, (uint)(local_18 != 0));
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0xfff00000;
    *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0xfffffbff | 0x10000000;
    return;
  case 0x6003001:
    param_2 = *(ulong *)(this + 0x14);
    (**(code **)(*(int *)param_1 + 4))(&param_2);
    if (*(int *)(this_00 + 8) != 0) {
      return;
    }
    if (*(int *)(param_1 + 8) != 0) {
      pCVar3 = CPlugSolid::CreateModelInstance((CPlugSolid *)param_1);
      SetSolid(this, pCVar3);
      return;
    }
    SetSolid(this, (CPlugSolid *)param_1);
    return;
  case 0x6003002:
    CFastArray<>::ArchiveCountAndNods((CFastArray<> *)(this + 0x28), param_1);
    CFastArray<>::DeleteAll((CFastArray<> *)(CFastArray<> *)(this + 0x28));
    return;
  case 0x6003003:
    CClassicArchive::DoNatural(param_1, &local_c, 1, 0);
    CClassicArchive::DoBool(this_00, (int *)&param_1, 1);
    SetCollisionGroup(this, -(uint)(param_1 != (CClassicArchive *)0x0) & 4);
    CClassicArchive::DoBool(this_00, (int *)&param_2, 1);
    SetContactInterest(this, -(uint)(param_2 != 0) & 2);
    CClassicArchive::DoBool(this_00, &local_18, 1);
    SetDynamicType(this, (uint)(local_18 != 0));
    CClassicArchive::DoBool(this_00, &local_14, 1);
    local_c._0_1_ = -(local_14 != 0) & 2;
    break;
  case 0x6003004:
    CClassicArchive::DoNatural(param_1, &local_c, 1, 0);
    CClassicArchive::DoBool(this_00, (int *)&param_1, 1);
    SetCollisionGroup(this, -(uint)(param_1 != (CClassicArchive *)0x0) & 4);
    CClassicArchive::DoBool(this_00, (int *)&param_2, 1);
    SetContactInterest(this, -(uint)(param_2 != 0) & 2);
    CClassicArchive::DoBool(this_00, &local_14, 1);
    SetDynamicType(this, (uint)(local_14 != 0));
    CClassicArchive::DoNat8(this_00, (uchar *)&local_18, 1, 0);
    local_10._0_1_ = (uchar)local_18;
    goto LAB_0053e2cd;
  case 0x6003005:
    CClassicArchive::DoNatural(param_1, &local_c, 1, 0);
    CClassicArchive::DoBool(this_00, (int *)&param_1, 1);
    CClassicArchive::DoBool(this_00, (int *)&param_2, 1);
    *(uint *)(this + 0x18) = *(uint *)(this + 0x18) ^
                             ((uint)(param_1 != (CClassicArchive *)0x0) << 9 ^
                              *(uint *)(this + 0x18)) &
                                 0x200;
    SetCollisionGroup(this, -(uint)(param_2 != 0) & 4);
    CClassicArchive::DoBool(this_00, &local_14, 1);
    SetContactInterest(this, -(uint)(local_14 != 0) & 2);
    CClassicArchive::DoBool(this_00, &local_18, 1);
    SetDynamicType(this, (uint)(local_18 != 0));
    CClassicArchive::DoNat8(this_00, (uchar *)&local_10, 1, 0);
  LAB_0053e2cd:
    SetCountShadowTexCasted(this, (uchar)local_10, 1);
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0xfff00000;
    *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0xfffffbff | 0x10000000;
    return;
  case 0x6003006:
    CClassicArchive::DoNatural(param_1, &local_8, 1, 0);
    CClassicArchive::DoBool(this_00, (int *)&param_2, 1);
    CClassicArchive::DoBool(this_00, (int *)&param_1, 1);
    CClassicArchive::DoBool(this_00, &local_10, 1);
    *(uint *)(this + 0x18) = *(uint *)(this + 0x18) ^
                             ((uint)(param_1 != (CClassicArchive *)0x0) << 9 ^
                              *(uint *)(this + 0x18)) &
                                 0x200;
    SetLightEmitter(this, param_2);
    SetCollisionGroup(this, -(uint)(local_10 != 0) & 4);
    CClassicArchive::DoBool(this_00, &local_14, 1);
    SetContactInterest(this, -(uint)(local_14 != 0) & 2);
    CClassicArchive::DoBool(this_00, &local_18, 1);
    SetDynamicType(this, (uint)(local_18 != 0));
    CClassicArchive::DoNat8(this_00, (uchar *)&local_c, 1, 0);
    break;
  case 0x6003007:
    CClassicArchive::DoNatural(param_1, &local_8, 1, 0);
    CClassicArchive::DoBool(this_00, (int *)&param_2, 1);
    CClassicArchive::DoBool(this_00, (int *)&param_1, 1);
    CClassicArchive::DoBool(this_00, (int *)&local_c, 1);
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0xfff00000;
    *(uint *)(this + 0x18) = (param_1 != (CClassicArchive *)0x0 | 0x80000)
                                 << 9 |
                             *(uint *)(this + 0x18) & 0xfffffdff;
    SetLightEmitter(this, param_2);
    SetCollisionGroup(this, -(uint)(local_c != 0) & 4);
    CClassicArchive::DoBool(this_00, &local_10, 1);
    SetContactInterest(this, -(uint)(local_10 != 0) & 2);
    CClassicArchive::DoBool(this_00, &local_14, 1);
    SetDynamicType(this, (uint)(local_14 != 0));
    CClassicArchive::DoNat8(this_00, (uchar *)&local_18, 1, 0);
    SetCountShadowTexCasted(this, (uchar)local_18, 1);
    return;
  case 0x6003008:
    CClassicArchive::DoNatural(param_1, &local_8, 1, 0);
    CClassicArchive::DoData(this_00, &param_1, 4);
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0xfff00000;
    this[0x18] = SUB41(param_1, 0);
    *(uint *)(this + 0x18) =
        *(uint *)(this + 0x18) & 0xfff600ff | (uint)param_1 & 0x100 |
        ((uint)param_1 & 0x100) << 0xb | (uint)param_1 & 0x200 |
        ((uint)param_1 & 0x800 | 0x1100000) << 4;
    CClassicArchive::DoBool(this_00, (int *)&param_2, 1);
    SetLightEmitter(this, (uint)param_1 >> 10 & 1);
    SetContactInterest(this, -(uint)(param_2 != 0) & 2);
    *(undefined2 *)(this + 0x20) = 0;
    return;
  default:
    goto switchD_0053e0ec_caseD_9;
  }
  SetCountShadowTexCasted(this, (byte)local_c, 1);
  *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0xfff00000;
  *(uint *)(this + 0x18) = *(uint *)(this + 0x18) & 0xfffffbff | 0x10000000;
  return;
}

/* public: virtual void __thiscall CHmsItem::CreateDefaultData(void) */

void __thiscall CHmsItem::CreateDefaultData(CHmsItem *this)

{
  uint uVar1;
  CPlugSolid *this_00;
  int *piVar2;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a958bb;
  local_c = ExceptionList;
  uVar1 = ___security_cookie ^ (uint)&stack0xffffffe8;
  ExceptionList = &local_c;
  this_00 = (CPlugSolid *)operator_new(0x74);
  piVar2 = (int *)0x0;
  local_4 = 0;
  if (this_00 != (CPlugSolid *)0x0) {
    piVar2 = (int *)CPlugSolid::CPlugSolid(this_00);
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 0x4c))(uVar1);
  SetSolid(this, (CPlugSolid *)piVar2);
  ExceptionList = local_c;
  return;
}

/* public: void __thiscall CHmsItem::CreatePortal(class CHmsPortal * &,class
 * CPlugTree *) */

void __thiscall CHmsItem::CreatePortal(CHmsItem *this, CHmsPortal **param_1,
                                       CPlugTree *param_2)

{
  CHmsPortal *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a958eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*param_1 == (CHmsPortal *)0x0) {
    pCVar1 = (CHmsPortal *)operator_new(0x108);
    local_4 = 0;
    if (pCVar1 == (CHmsPortal *)0x0) {
      pCVar1 = (CHmsPortal *)0x0;
    } else {
      pCVar1 = (CHmsPortal *)CHmsPortal::CHmsPortal(pCVar1);
    }
    *param_1 = pCVar1;
  }
  local_4 = 0xffffffff;
  CHmsPortal::BindToBuild(*param_1, this, param_2);
  CFastArray<>::AddTail((CFastArray<> *)(this + 0x28),
                        (CFastBuffer<> **)param_1);
  CMwNod::MwAddRef((CMwNod *)*param_1);
  UpdateIsBuild(this);
  ExceptionList = local_c;
  return;
}

/* public: void __thiscall CHmsItem::GetAngularSpeed(class GmVec3 &)const  */

void __thiscall CHmsItem::GetAngularSpeed(CHmsItem *this, GmVec3 *param_1)

{
  ulong uVar1;
  int *piVar2;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  if (uVar1 != 0) {
    piVar2 = (int *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), 0);
    if (*(CHmsDyna **)(*piVar2 + 0x58) != (CHmsDyna *)0x0) {
      CHmsDyna::GetLocalAngularSpeed(*(CHmsDyna **)(*piVar2 + 0x58), param_1);
      return;
    }
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)param_1 = 0;
  return;
}

/* public: float __thiscall
 * CHmsItem::GetAsyncBlendBetweenPreviousAndNextStates(void) */

float __thiscall CHmsItem::GetAsyncBlendBetweenPreviousAndNextStates(
    CHmsItem *this)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  uint *puVar5;
  CMwCmdBufferCore *this_00;
  int iVar6;
  float fVar7;

  this_00 = *(CMwCmdBufferCore **)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x14);
  if ((*(uint *)(this + 0x18) & 0x200000) == 0) {
    if (this_00 == (CMwCmdBufferCore *)0x0) {
      this_00 = CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0;
    }
    puVar5 = (uint *)CPlugAudio::MwGetId((CPlugAudio *)this_00);
    uVar1 = *puVar5;
    puVar5 = (uint *)CMwCmdBufferCore::GetSchemeProperies(
        CMwCmdBufferCore::TheCoreCmdBuffer, 0x8c);
    uVar2 = *puVar5;
    iVar6 = uVar1 - (uVar1 / uVar2) * uVar2;
    fVar7 = (float)iVar6;
    if (iVar6 < 0) {
      fVar7 = fVar7 + 4.294967e+09;
    }
    fVar4 = (float)uVar2;
    if ((int)uVar2 < 0) {
      fVar4 = fVar4 + 4.294967e+09;
    }
    return fVar7 / fVar4;
  }
  if (this_00 == (CMwCmdBufferCore *)0x0) {
    this_00 = CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0;
  }
  puVar5 = (uint *)CPlugAudio::MwGetId((CPlugAudio *)this_00);
  uVar1 = *puVar5;
  uVar2 = *(uint *)(this + 0x4c);
  if (((uVar2 != 0xffffffff) &&
       (uVar3 = *(uint *)(this + 0x48), uVar2 != uVar3)) &&
      (uVar3 <= uVar1)) {
    fVar7 = 1.0;
    if (uVar1 <= uVar2) {
      fVar7 = (float)(uVar1 - uVar3);
      if ((int)(uVar1 - uVar3) < 0) {
        fVar7 = fVar7 + 4.294967e+09;
      }
      fVar4 = (float)(uVar2 - uVar3);
      if ((int)(uVar2 - uVar3) < 0) {
        fVar4 = fVar4 + 4.294967e+09;
      }
      fVar7 = GmFunc::ClampReal(fVar7 / fVar4, 0.0, 1.0);
    }
    return fVar7;
  }
  return 0.0;
}

/* WARNING: Switch with 1 destination removed at 0x0053b59b : 4 cases all go to
 * same destination */
/* public: virtual unsigned long __thiscall CHmsItem::GetChunkInfo(unsigned
 * long)const  */

ulong __thiscall CHmsItem::GetChunkInfo(CHmsItem *this, ulong param_1)

{
  ulong uVar1;

  if (0x6003009 < param_1) {
    if (param_1 < 0x600300f) {
      if (param_1 == 0x600300e) {
        return 1;
      }
      if (param_1 + 0xf9ffcff6 < 4) {
        return 1;
      }
    } else if (param_1 < 0x6003012) {
      if (param_1 == 0x6003011) {
        return 3;
      }
      if (param_1 == 0x600300f) {
        return 1;
      }
      if (param_1 == 0x6003010) {
        return 1;
      }
    } else if (param_1 == 0xffffffff) {
      return 0xffffffff;
    }
  switchD_0053b578_caseD_9:
    uVar1 = CMwNod::GetChunkInfo((CMwNod *)this, param_1);
    return uVar1;
  }
  if (param_1 == 0x6003009) {
  switchD_0053b578_caseD_6003000:
    return 1;
  }
  switch (param_1) {
  case 0x6003000:
  case 0x6003002:
  case 0x6003003:
  case 0x6003004:
  case 0x6003005:
  case 0x6003006:
  case 0x6003007:
  case 0x6003008:
    goto switchD_0053b578_caseD_6003000;
  case 0x6003001:
    return 3;
  default:
    goto switchD_0053b578_caseD_9;
  }
}

/* public: class CHmsCorpus * __thiscall CHmsItem::GetCorpus(class CHmsZone
 * const *)const  */

CHmsCorpus *__thiscall CHmsItem::GetCorpus(CHmsItem *this, CHmsZone *param_1)

{
  ulong uVar1;
  CHmsCorpus **ppCVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      ppCVar2 = (CHmsCorpus **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      if (*(CHmsZone **)(*ppCVar2 + 0x14) == param_1) {
        return *ppCVar2;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return (CHmsCorpus *)0x0;
}

/* public: enum EHmsCorpusCat __thiscall CHmsItem::GetCorpusCat(void) */

EHmsCorpusCat __thiscall CHmsItem::GetCorpusCat(CHmsItem *this)

{
  uint uVar1;

  uVar1 = *(uint *)(this + 0x18);
  if ((uVar1 & 0x200) != 0) {
    SetCountShadowTexCasted(this, '\0', 1);
    SetIsVisionStatic(this, 0);
    return 4;
  }
  if ((char)uVar1 != '\0') {
    return 2 - ((uVar1 & 0x100) != 0);
  }
  return (-(uint)((uVar1 & 0x100) != 0) & 0xfffffffd) + 3;
}

/* public: unsigned long __thiscall CHmsItem::GetCorpusIndex(class CHmsZone
 * const *)const  */

ulong __thiscall CHmsItem::GetCorpusIndex(CHmsItem *this, CHmsZone *param_1)

{
  ulong uVar1;
  int *piVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      if (*(CHmsZone **)(*piVar2 + 0x14) == param_1) {
        return uVar3;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 0xffffffff;
}

/* public: class CHmsCorpus * __thiscall CHmsItem::GetCurrentCorpus(void)const
 */

CHmsCorpus *__thiscall CHmsItem::GetCurrentCorpus(CHmsItem *this)

{
  ulong uVar1;
  CHmsCorpus **ppCVar2;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  if (uVar1 != 0) {
    ppCVar2 = (CHmsCorpus **)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), 0);
    return *ppCVar2;
  }
  return (CHmsCorpus *)0x0;
}

/* public: void __thiscall CHmsItem::GetForce(class GmVec3 &) */

void __thiscall CHmsItem::GetForce(CHmsItem *this, GmVec3 *param_1)

{
  ulong uVar1;
  int *piVar2;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  if (uVar1 != 0) {
    piVar2 = (int *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), 0);
    if (*(CHmsDyna **)(*piVar2 + 0x58) != (CHmsDyna *)0x0) {
      CHmsDyna::GetLocalForce(*(CHmsDyna **)(*piVar2 + 0x58), param_1);
      return;
    }
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)param_1 = 0;
  return;
}

/* public: void __thiscall CHmsItem::GetLinearSpeed(class GmVec3 &)const  */

void __thiscall CHmsItem::GetLinearSpeed(CHmsItem *this, GmVec3 *param_1)

{
  ulong uVar1;
  int *piVar2;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  if (uVar1 != 0) {
    piVar2 = (int *)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), 0);
    if (*(CHmsDyna **)(*piVar2 + 0x58) != (CHmsDyna *)0x0) {
      CHmsDyna::GetLocalLinearSpeed(*(CHmsDyna **)(*piVar2 + 0x58), param_1);
      return;
    }
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)param_1 = 0;
  return;
}

/* public: class GmIso4 const & __thiscall CHmsItem::GetLocation(class CHmsZone
 * const *)const  */

GmIso4 *__thiscall CHmsItem::GetLocation(CHmsItem *this, CHmsZone *param_1)

{
  int *piVar1;
  GmIso4 *pGVar2;

  piVar1 = (int *)GetCorpus(this, param_1);
  pGVar2 = (GmIso4 *)(**(code **)(*piVar1 + 0x78))();
  return pGVar2;
}

/* public: virtual unsigned long __thiscall CHmsItem::GetMwClassId(void)const */

ulong __thiscall CHmsItem::GetMwClassId(CHmsItem *this)

{
  return 0x6003000;
}

/* public: static unsigned long __cdecl CHmsItem::GetSaveStateSize(enum
 * CHmsItem::ESaveStateVersion)
 */

ulong __cdecl CHmsItem::GetSaveStateSize(ESaveStateVersion param_1)

{
  if (param_1 == 0) {
    return 0xf;
  }
  if (param_1 != 1) {
    return 0;
  }
  return 0x1a;
}

/* public: virtual unsigned long __thiscall
 * CHmsItem::GetUidChunkFromIndex(unsigned long)const  */

ulong __thiscall CHmsItem::GetUidChunkFromIndex(CHmsItem *this, ulong param_1)

{
  if (param_1 == 0) {
    return 0x1001000;
  }
  return param_1 - 1 | 0x6003000;
}

/* public: class CHmsZone const * __thiscall CHmsItem::GetZone(unsigned long) */

CHmsZone *__thiscall CHmsItem::GetZone(CHmsItem *this, ulong param_1)

{
  int *piVar1;

  piVar1 =
      (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x34), param_1);
  return *(CHmsZone **)(*piVar1 + 0x14);
}

/* public: int __thiscall CHmsItem::IsStateDifferentFrom(class GmIso4 &)const */

int __thiscall CHmsItem::IsStateDifferentFrom(CHmsItem *this, GmIso4 *param_1)

{
  int *piVar1;
  int iVar2;

  piVar1 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x34), 0);
  if (*(CHmsDyna **)(*piVar1 + 0x58) != (CHmsDyna *)0x0) {
    iVar2 =
        CHmsDyna::IsStateDifferentFrom(*(CHmsDyna **)(*piVar1 + 0x58), param_1);
    return iVar2;
  }
  return 0;
}

/* public: void __thiscall CHmsItem::IsVisibleSet(int) */

void __thiscall CHmsItem::IsVisibleSet(CHmsItem *this, int param_1)

{
  uint uVar1;
  ulong uVar2;
  int *piVar3;
  ulong uVar4;

  uVar1 = *(uint *)(this + 0x1c);
  if ((uVar1 >> 0xf & 1) != (uint)(param_1 != 0)) {
    *(uint *)(this + 0x1c) =
        ((uint)(param_1 != 0) << 0xf ^ uVar1) & 0x8000 ^ uVar1;
    uVar2 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
    uVar4 = 0;
    if (uVar2 != 0) {
      do {
        piVar3 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar4);
        (**(code **)(**(int **)(*piVar3 + 0x14) + 0x80))(*piVar3);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
    }
  }
  return;
}

/* public: virtual class CMwClassInfo const * __thiscall
 * CHmsItem::MwGetClassInfo(void)const  */

CMwClassInfo *__thiscall CHmsItem::MwGetClassInfo(CHmsItem *this)

{
  return &m_MwClassInfo_CHmsItem;
}

/* public: virtual int __thiscall CHmsItem::MwIsKindOf(unsigned long)const  */

int __thiscall CHmsItem::MwIsKindOf(CHmsItem *this, ulong param_1)

{
  if (param_1 == 0x6003000) {
    return 1;
  }
  return (uint)(param_1 == 0x1001000);
}

/* public: static class CMwNod * __cdecl CHmsItem::MwNewCHmsItem(void) */

CMwNod *__cdecl CHmsItem::MwNewCHmsItem(void)

{
  CHmsItem *this;
  CMwNod *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a9583b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = (CHmsItem *)operator_new(0x58);
  local_4 = 0;
  if (this != (CHmsItem *)0x0) {
    pCVar1 = (CMwNod *)CHmsItem(this);
    ExceptionList = local_c;
    return pCVar1;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}

/* public: void __thiscall CHmsItem::OldRestoreStaticState(class
   CClassicBufferMemory &,int,unsigned long,unsigned char,int) */

void __thiscall CHmsItem::OldRestoreStaticState(CHmsItem *this,
                                                CClassicBufferMemory *param_1,
                                                int param_2, ulong param_3,
                                                uchar param_4, int param_5)

{
  CHmsCorpus **ppCVar1;

  if (param_2 == 0) {
    *(ulong *)(this + 0x4c) = param_3;
  } else {
    *(ulong *)(this + 0x48) = param_3;
  }
  ppCVar1 = (CHmsCorpus **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(this + 0x34), 0);
  CHmsCorpus::OldRestoreStaticState(*ppCVar1, param_1, param_2, param_4,
                                    param_5);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: virtual int __thiscall CHmsItem::OnCrashDump(class CFastString &) */

int __thiscall CHmsItem::OnCrashDump(CHmsItem *this, CFastString *param_1)

{
  int *piVar1;
  int iVar2;

  iVar2 = CMwNod::OnCrashDump((CMwNod *)this, param_1);
  if (iVar2 == 0) {
    return 0;
  }
  (**(code **)(_s_SystemCrashDump + 0x14))();
  CSystemCrashDump::IsValid_DumpFidAndMwId(&CSystemCrashDump::s_SystemCrashDump,
                                           param_1, "SceneMobil",
                                           *(CMwNod **)(this + 0x40), 1);
  piVar1 = *(int **)(this + 0x14);
  iVar2 = CSystemCrashDump::IsValid_DumpFidAndMwId(
      &CSystemCrashDump::s_SystemCrashDump, param_1, "PlugSolid",
      (CMwNod *)piVar1, 1);
  if (iVar2 != 0) {
    (**(code **)(*piVar1 + 0x58))(param_1);
  }
  (**(code **)(_s_SystemCrashDump + 0x18))();
  return 1;
}

/* public: virtual void __thiscall CHmsItem::OnNodLoaded(void) */

void __thiscall CHmsItem::OnNodLoaded(CHmsItem *this)

{
  CScene2d::OnNodLoaded((CScene2d *)this);
  if (((*(uint *)(this + 0x18) & 0x200) != 0) &&
      (*(CPlugSolid **)(this + 0x14) != (CPlugSolid *)0x0)) {
    CPlugSolid::ExclusionEllipsoidRadiusCompute(*(CPlugSolid **)(this + 0x14));
    return;
  }
  return;
}

/* public: void __thiscall CHmsItem::OnVisible_WakeOrKeepAwake(void) */

void __thiscall CHmsItem::OnVisible_WakeOrKeepAwake(CHmsItem *this)

{
  int *piVar1;
  uint uVar2;

  if ((*(int ***)(this + 0x24) != (int **)0x0) &&
      (piVar1 = **(int ***)(this + 0x24), piVar1 != (int *)0x0)) {
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

/* public: void __thiscall CHmsItem::PickDisable(void) */

void __thiscall CHmsItem::PickDisable(CHmsItem *this)

{
  CPlugTree *this_00;
  CPlugTree *pCVar1;
  CHmsItem *local_4;

  this_00 = *(CPlugTree **)(*(int *)(this + 0x14) + 100);
  *(uint *)(this_00 + 0x9c) = *(uint *)(this_00 + 0x9c) & 0xffffffbf;
  local_4 = this;
  local_4 = (CHmsItem *)CPlugTree::GetAllChildStart(this_00);
  while (local_4 != (CHmsItem *)0xffffffff) {
    pCVar1 = CPlugTree::GetAllChildNext(this_00, (ulong *)&local_4);
    *(uint *)(pCVar1 + 0x9c) = *(uint *)(pCVar1 + 0x9c) & 0xffffffbf;
  }
  return;
}

/* public: void __thiscall CHmsItem::PickEnableAtLevel(unsigned long) */

void __thiscall CHmsItem::PickEnableAtLevel(CHmsItem *this, ulong param_1)

{
  CPlugTree *this_00;
  int iVar1;
  byte bVar2;
  ulong uVar3;
  CPlugTree *pCVar4;
  uint uVar5;

  uVar3 = param_1;
  this_00 = *(CPlugTree **)(*(int *)(this + 0x14) + 100);
  *(uint *)(this_00 + 0x9c) =
      *(uint *)(this_00 + 0x9c) ^
      ((uint)(param_1 == 0) << 6 ^ *(uint *)(this_00 + 0x9c)) & 0x40;
  param_1 = CPlugTree::GetAllChildStart(this_00);
  do {
    while (true) {
      if (param_1 == 0xffffffff) {
        return;
      }
      pCVar4 = CPlugTree::GetAllChildNext(this_00, &param_1);
      if (uVar3 != 0)
        break;
      *(uint *)(pCVar4 + 0x9c) = *(uint *)(pCVar4 + 0x9c) & 0xffffffbf;
    }
    uVar5 = 1;
    for (iVar1 = *(int *)(*(int *)(pCVar4 + 0x24) + 0x24); iVar1 != 0;
         iVar1 = *(int *)(iVar1 + 0x24)) {
      if (uVar3 <= uVar5) {
        if (iVar1 != 0)
          goto LAB_0053baef;
        break;
      }
      uVar5 = uVar5 + 1;
    }
    if (uVar3 == uVar5) {
      bVar2 = 1;
    } else {
    LAB_0053baef:
      bVar2 = 0;
    }
    *(uint *)(pCVar4 + 0x9c) =
        *(uint *)(pCVar4 + 0x9c) ^
        ((uint)bVar2 << 6 ^ *(uint *)(pCVar4 + 0x9c)) & 0x40;
  } while (true);
}

/* public: void __thiscall CHmsItem::RemoveCorpus(class CHmsCorpus *) */

void __thiscall CHmsItem::RemoveCorpus(CHmsItem *this, CHmsCorpus *param_1)

{
  CFastBuffer<>::ReplaceByLast((CFastBuffer<> *)(this + 0x34),
                               (CPlugBitmap **)&param_1);
  return;
}

/* public: void __thiscall CHmsItem::RemovePortal(class CHmsPortal *) */

void __thiscall CHmsItem::RemovePortal(CHmsItem *this, CHmsPortal *param_1)

{
  CHmsPortal *this_00;
  ulong uVar1;
  ulong uVar2;

  uVar2 = 1;
  uVar1 = CFastArray<>::Find((CFastArray<> *)(this + 0x28),
                             (CGameMenuFrame **)&param_1);
  CFastArray<>::RemoveAt((CFastArray<> *)(CFastArray<> *)(this + 0x28), uVar1,
                         uVar2);
  this_00 = param_1;
  CHmsPortal::UnbindFromBuild(param_1);
  CMwNod::MwRelease((CMwNod *)this_00);
  UpdateIsBuild(this);
  return;
}

/* public: void __thiscall CHmsItem::ResetDynamicState(void) */

void __thiscall CHmsItem::ResetDynamicState(CHmsItem *this)

{
  ulong uVar1;
  CHmsCorpus **ppCVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      ppCVar2 = (CHmsCorpus **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      CHmsCorpus::Reset(*ppCVar2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* public: void __thiscall CHmsItem::RestoreStaticState(class
   CClassicBufferMemory &,int,unsigned long,enum CHmsItem::ESaveStateVersion) */

void __thiscall CHmsItem::RestoreStaticState(CHmsItem *this,
                                             CClassicBufferMemory *param_1,
                                             int param_2, ulong param_3,
                                             ESaveStateVersion param_4)

{
  CHmsCorpus **ppCVar1;

  if (param_2 == 0) {
    *(ulong *)(this + 0x4c) = param_3;
  } else {
    *(ulong *)(this + 0x48) = param_3;
  }
  ppCVar1 = (CHmsCorpus **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(this + 0x34), 0);
  CHmsCorpus::RestoreStaticState(*ppCVar1, param_1, param_2, param_4);
  return;
}

/* public: void __thiscall CHmsItem::RotateOf(class GmMat3 const &) */

void __thiscall CHmsItem::RotateOf(CHmsItem *this, GmMat3 *param_1)

{
  ulong uVar1;
  CHmsCorpus **ppCVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      ppCVar2 = (CHmsCorpus **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      CHmsCorpus::RotateOf(*ppCVar2, param_1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* public: void __thiscall CHmsItem::RotateOf(class GmQuat const &) */

void __thiscall CHmsItem::RotateOf(CHmsItem *this, GmQuat *param_1)

{
  GmMat3 local_24[36];

  GmMat3::Set(local_24, *(float *)param_1, *(float *)(param_1 + 4),
              *(float *)(param_1 + 8), *(float *)(param_1 + 0xc));
  RotateOf(this, local_24);
  return;
}

/* public: void __thiscall CHmsItem::SaveState(class CClassicBufferMemory &,enum
   CHmsItem::ESaveStateVersion)const  */

void __thiscall CHmsItem::SaveState(CHmsItem *this,
                                    CClassicBufferMemory *param_1,
                                    ESaveStateVersion param_2)

{
  int *piVar1;

  piVar1 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x34), 0);
  if (*(CHmsDyna **)(*piVar1 + 0x58) != (CHmsDyna *)0x0) {
    CHmsDyna::SaveState(*(CHmsDyna **)(*piVar1 + 0x58), param_1, param_2);
    return;
  }
  return;
}

/* public: __thiscall CHmsItem::SCallbackList::SCallbackList(void) */

void __thiscall CHmsItem::SCallbackList::SCallbackList(SCallbackList *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  return;
}

/* public: __thiscall CHmsItem::SCallbackList::~SCallbackList(void) */

void __thiscall CHmsItem::SCallbackList::~SCallbackList(SCallbackList *this)

{
  uint uVar1;

  uVar1 = 0;
  do {
    if (*(int **)(this + uVar1 * 4) != (int *)0x0) {
      (**(code **)(**(int **)(this + uVar1 * 4) + 4))();
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 6);
  return;
}

/* public: void __thiscall CHmsItem::SetAngularSpeed(class GmVec3 const &) */

void __thiscall CHmsItem::SetAngularSpeed(CHmsItem *this, GmVec3 *param_1)

{
  ulong uVar1;
  int *piVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      if (*(CHmsDyna **)(*piVar2 + 0x58) != (CHmsDyna *)0x0) {
        CHmsDyna::SetLocalAngularSpeed(*(CHmsDyna **)(*piVar2 + 0x58), param_1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* public: void __thiscall CHmsItem::SetCollisionGroup(enum
 * CHmsItem::ECollisionGroup) */

void __thiscall CHmsItem::SetCollisionGroup(CHmsItem *this,
                                            ECollisionGroup param_1)

{
  CFastBuffer<> *this_00;
  ulong uVar1;
  int *piVar2;
  undefined4 *puVar3;
  ulong uVar4;

  if (param_1 != (*(uint *)(this + 0x18) >> 0xd & 0xf)) {
    this_00 = (CFastBuffer<> *)(this + 0x34);
    uVar1 = CFastBuffer<>::GetCount(this_00);
    uVar4 = 0;
    if (uVar1 != 0) {
      do {
        piVar2 =
            (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar4);
        piVar2 = *(int **)(*piVar2 + 0x14);
        puVar3 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)this_00, uVar4);
        (**(code **)(*piVar2 + 0x84))(*puVar3);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar1);
    }
    uVar4 = 0;
    *(ECollisionGroup *)(this + 0x18) =
        *(uint *)(this + 0x18) ^
        (param_1 << 0xd ^ *(uint *)(this + 0x18)) & 0x1e000;
    if (uVar1 != 0) {
      do {
        piVar2 =
            (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar4);
        piVar2 = *(int **)(*piVar2 + 0x14);
        puVar3 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)this_00, uVar4);
        (**(code **)(*piVar2 + 0x88))(*puVar3);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar1);
    }
  }
  return;
}

/* public: void __thiscall CHmsItem::SetContactInterest(enum
 * CHmsItem::EContactInterest) */

void __thiscall CHmsItem::SetContactInterest(CHmsItem *this,
                                             EContactInterest param_1)

{
  *(EContactInterest *)(this + 0x18) =
      *(uint *)(this + 0x18) ^
      (param_1 << 0x11 ^ *(uint *)(this + 0x18)) & 0x60000;
  return;
}

/* public: void __thiscall CHmsItem::SetCountShadowTexCasted(unsigned char,int)
 */

void __thiscall CHmsItem::SetCountShadowTexCasted(CHmsItem *this, uchar param_1,
                                                  int param_2)

{
  if (((uchar) * (uint *)(this + 0x18) != param_1) ||
      ((*(uint *)(this + 0x18) >> 0x17 & 1) != (uint)(param_2 != 0))) {
    this[0x18] = (CHmsItem)param_1;
    *(uint *)(this + 0x18) =
        *(uint *)(this + 0x18) ^
        ((uint)(param_2 != 0) << 0x17 ^ *(uint *)(this + 0x18)) & 0x800000;
    if ((this[0x18] != (CHmsItem)0x0) &&
        ((*(uint *)(this + 0x1c) & 0xfff) == 0)) {
      *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) & 0xfffff001 | 1;
    }
    UpdateCorpusCat(this);
  }
  return;
}

/* public: void __thiscall CHmsItem::SetDynamicType(enum CHmsItem::EDynamicType)
 */

void __thiscall CHmsItem::SetDynamicType(CHmsItem *this, EDynamicType param_1)

{
  ulong uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int **ppiVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  ulong uVar8;
  CFastArray<> local_20[12];
  void *local_14;
  undefined *puStack_10;
  undefined4 local_c;

  local_c = 0xffffffff;
  puStack_10 = &LAB_00a95808;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (param_1 != (*(uint *)(this + 0x18) >> 0xb & 3)) {
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
    CFastArray<>::CFastArray<>(local_20);
    uVar8 = 0;
    local_c = 0;
    CFastArray<>::SetCount((CFastArray<> *)local_20, uVar1);
    if (uVar1 != 0) {
      do {
        piVar2 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x34), uVar8);
        puVar3 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)local_20, uVar8);
        *puVar3 = *(undefined4 *)(*piVar2 + 0x14);
        ppiVar4 = (int **)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x34), uVar8);
        puVar5 = (undefined4 *)(**(code **)(**ppiVar4 + 0x78))();
        puVar6 = puVar3;
        for (iVar7 = 0xc; puVar6 = puVar6 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
        }
        puVar6 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x34), uVar8);
        uVar8 = uVar8 + 1;
        puVar3[0xd] = *puVar6;
      } while (uVar8 < uVar1);
    }
    uVar8 = 0;
    if (uVar1 != 0) {
      do {
        ppiVar4 =
            (int **)CFastBuffer<>::operator[]((CFastBuffer<> *)local_20, uVar8);
        (**(code **)(**ppiVar4 + 0x7c))(ppiVar4[0xd]);
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar1);
    }
    uVar8 = 0;
    *(EDynamicType *)(this + 0x18) =
        *(uint *)(this + 0x18) ^
        (param_1 << 0xb ^ *(uint *)(this + 0x18)) & 0x1800;
    if (uVar1 != 0) {
      do {
        ppiVar4 =
            (int **)CFastBuffer<>::operator[]((CFastBuffer<> *)local_20, uVar8);
        (**(code **)(**ppiVar4 + 0x78))(this, ppiVar4 + 1);
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar1);
    }
    CFastArray<>::~CFastArray<>((CFastArray<> *)local_20);
  }
  ExceptionList = local_14;
  return;
}

/* public: void __thiscall CHmsItem::SetForce(class GmVec3 const &) */

void __thiscall CHmsItem::SetForce(CHmsItem *this, GmVec3 *param_1)

{
  ulong uVar1;
  int *piVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      if (*(CHmsDyna **)(*piVar2 + 0x58) != (CHmsDyna *)0x0) {
        CHmsDyna::SetLocalForce(*(CHmsDyna **)(*piVar2 + 0x58), param_1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* public: void __thiscall CHmsItem::SetIsBackground(int) */

void __thiscall CHmsItem::SetIsBackground(CHmsItem *this, int param_1)

{
  *(uint *)(this + 0x18) =
      *(uint *)(this + 0x18) ^
      ((uint)(param_1 != 0) << 9 ^ *(uint *)(this + 0x18)) & 0x200;
  UpdateCorpusCat(this);
  return;
}

/* public: void __thiscall CHmsItem::SetIsCollisionStatic(int) */

void __thiscall CHmsItem::SetIsCollisionStatic(CHmsItem *this, int param_1)

{
  uint uVar1;

  uVar1 = *(uint *)(this + 0x18);
  if ((uVar1 >> 0x13 & 1) != (uint)(param_1 != 0)) {
    *(uint *)(this + 0x18) =
        ((uint)(param_1 != 0) << 0x13 ^ uVar1) & 0x80000 ^ uVar1;
  }
  return;
}

/* public: void __thiscall
 * CHmsItem::SetIsForcePointDynamicCollisionResponse(int) */

void __thiscall CHmsItem::SetIsForcePointDynamicCollisionResponse(
    CHmsItem *this, int param_1)

{
  *(uint *)(this + 0x1c) =
      *(uint *)(this + 0x1c) ^
      ((uint)(param_1 != 0) << 0xc ^ *(uint *)(this + 0x1c)) & 0x1000;
  return;
}

/* public: void __thiscall CHmsItem::SetIsKinematicOnly(int) */

void __thiscall CHmsItem::SetIsKinematicOnly(CHmsItem *this, int param_1)

{
  *(uint *)(this + 0x18) =
      *(uint *)(this + 0x18) ^
      ((uint)(param_1 != 0) << 0x14 ^ *(uint *)(this + 0x18)) & 0x100000;
  return;
}

/* public: void __thiscall CHmsItem::SetIsVisionStatic(int) */

void __thiscall CHmsItem::SetIsVisionStatic(CHmsItem *this, int param_1)

{
  uint uVar1;

  uVar1 = *(uint *)(this + 0x18);
  if ((uVar1 >> 8 & 1) != (uint)(param_1 != 0)) {
    *(uint *)(this + 0x18) =
        ((uint)(param_1 != 0) << 8 ^ uVar1) & 0x100 ^ uVar1;
    UpdateCorpusCat(this);
  }
  return;
}

/* public: void __thiscall CHmsItem::SetIsZombie(int) */

void __thiscall CHmsItem::SetIsZombie(CHmsItem *this, int param_1)

{
  CFastBuffer<> *this_00;
  uint uVar1;
  ulong uVar2;
  int *piVar3;
  undefined4 *puVar4;
  ulong uVar5;

  uVar1 = *(uint *)(this + 0x18) >> 0x15 & 1;
  if ((((uVar1 == 0) || (param_1 == 0)) && ((uVar1 != 0 || (param_1 != 0)))) &&
      ((*(uint *)(this + 0x18) & 0x1800) != 0)) {
    this_00 = (CFastBuffer<> *)(this + 0x34);
    uVar2 = CFastBuffer<>::GetCount(this_00);
    uVar5 = 0;
    if (uVar2 != 0) {
      do {
        piVar3 =
            (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar5);
        piVar3 = *(int **)(*piVar3 + 0x14);
        puVar4 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)this_00, uVar5);
        (**(code **)(*piVar3 + 0x8c))(*puVar4);
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar2);
    }
    uVar5 = 0;
    *(uint *)(this + 0x18) =
        *(uint *)(this + 0x18) ^
        ((uint)(param_1 != 0) << 0x15 ^ *(uint *)(this + 0x18)) & 0x200000;
    if (uVar2 != 0) {
      do {
        piVar3 =
            (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar5);
        piVar3 = *(int **)(*piVar3 + 0x14);
        puVar4 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)this_00, uVar5);
        (**(code **)(*piVar3 + 0x90))(*puVar4);
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar2);
    }
  }
  return;
}

/* public: void __thiscall CHmsItem::SetLightEmitter(int) */

void __thiscall CHmsItem::SetLightEmitter(CHmsItem *this, int param_1)

{
  ushort uVar1;
  ulong uVar2;
  CHmsCorpus **ppCVar3;
  ulong uVar4;

  uVar1 = *(ushort *)(this + 0x20);
  if ((uVar1 & 1) != (ushort)(param_1 != 0)) {
    *(ushort *)(this + 0x20) = (byte)(param_1 != 0 ^ (byte)uVar1) & 1 ^ uVar1;
    uVar2 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
    uVar4 = 0;
    if (uVar2 != 0) {
      do {
        ppCVar3 = (CHmsCorpus **)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar4);
        CHmsZone::CorpusChangeLightEmitter(*(CHmsZone **)(*ppCVar3 + 0x14),
                                           *ppCVar3, param_1);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
    }
  }
  return;
}

/* public: void __thiscall CHmsItem::SetLightLensFlareEnable(int) */

void __thiscall CHmsItem::SetLightLensFlareEnable(CHmsItem *this, int param_1)

{
  *(uint *)(this + 0x18) =
      *(uint *)(this + 0x18) ^
      ((uint)(param_1 != 0) << 0x1c ^ *(uint *)(this + 0x18)) & 0x10000000;
  return;
}

/* public: void __thiscall CHmsItem::SetLinearSpeed(class GmVec3 const &) */

void __thiscall CHmsItem::SetLinearSpeed(CHmsItem *this, GmVec3 *param_1)

{
  ulong uVar1;
  int *piVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      if (*(CHmsDyna **)(*piVar2 + 0x58) != (CHmsDyna *)0x0) {
        CHmsDyna::SetLocalLinearSpeed(*(CHmsDyna **)(*piVar2 + 0x58), param_1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* public: void __thiscall CHmsItem::SetLocation(class GmIso4 const &,class
 * CHmsZone const *) */

void __thiscall CHmsItem::SetLocation(CHmsItem *this, GmIso4 *param_1,
                                      CHmsZone *param_2)

{
  int *this_00;
  int *this_01;
  ulong uVar1;
  ulong uVar2;
  int **ppiVar3;
  GmIso4 *pGVar4;
  int iVar5;
  ulong uVar6;
  CFastBuffer<> *this_02;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 auStack_90[12];
  undefined4 auStack_60[12];
  GmIso4 aGStack_30[48];

  uVar1 = GetCorpusIndex(this, param_2);
  this_02 = (CFastBuffer<> *)(this + 0x34);
  uVar2 = CFastBuffer<>::GetCount(this_02);
  ppiVar3 = (int **)CFastBuffer<>::operator[]((CFastBuffer<> *)this_02, uVar1);
  this_00 = *ppiVar3;
  if (1 < uVar2) {
    pGVar4 = (GmIso4 *)(**(code **)(*this_00 + 0x78))();
    GmIso4::SetInverse(aGStack_30, pGVar4);
    GmIso4::SetMult((GmIso4 *)auStack_90, param_1, aGStack_30);
    GmMat3::OrthoNormalize((GmMat3 *)auStack_90);
    uVar6 = 0;
    if (uVar2 != 0) {
      do {
        if (uVar6 != uVar1) {
          ppiVar3 = (int **)CFastBuffer<>::operator[]((CFastBuffer<> *)this_02,
                                                      uVar6);
          this_01 = *ppiVar3;
          puVar7 = auStack_90;
          puVar8 = auStack_60;
          for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          pGVar4 = (GmIso4 *)(**(code **)(*this_01 + 0x78))();
          GmIso4::Mult((GmIso4 *)auStack_60, pGVar4);
          CHmsCorpus::SetLocation((CHmsCorpus *)this_01, (GmIso4 *)auStack_60);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar2);
    }
  }
  CHmsCorpus::SetLocation((CHmsCorpus *)this_00, param_1);
  return;
}

/* public: void __thiscall CHmsItem::SetOccluderForLightMap(int) */

void __thiscall CHmsItem::SetOccluderForLightMap(CHmsItem *this, int param_1)

{
  uint uVar1;

  uVar1 = *(uint *)(this + 0x18);
  if ((uVar1 >> 0x16 & 1) != (uint)(param_1 != 0)) {
    *(uint *)(this + 0x18) =
        ((uint)(param_1 != 0) << 0x16 ^ uVar1) & 0x400000 ^ uVar1;
  }
  return;
}

/* public: void __thiscall CHmsItem::SetShadowCasterGroupMask(unsigned long) */

void __thiscall CHmsItem::SetShadowCasterGroupMask(CHmsItem *this,
                                                   ulong param_1)

{
  *(uint *)(this + 0x1c) =
      *(uint *)(this + 0x1c) ^ (*(uint *)(this + 0x1c) ^ param_1) & 0xfff;
  if ((this[0x18] != (CHmsItem)0x0) &&
      ((*(uint *)(this + 0x1c) & 0xfff) == 0)) {
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) & 0xfffff001 | 1;
  }
  return;
}

/* public: void __thiscall CHmsItem::SetShadowFakeEnable(int) */

void __thiscall CHmsItem::SetShadowFakeEnable(CHmsItem *this, int param_1)

{
  *(uint *)(this + 0x18) =
      *(uint *)(this + 0x18) ^
      ((uint)(param_1 != 0) << 0x1b ^ *(uint *)(this + 0x18)) & 0x8000000;
  return;
}

/* public: void __thiscall CHmsItem::SetShadowReceiverGroupMask(unsigned long)
 */

void __thiscall CHmsItem::SetShadowReceiverGroupMask(CHmsItem *this,
                                                     ulong param_1)

{
  *(ulong *)(this + 0x1c) = param_1 << 0x14 | *(uint *)(this + 0x1c) & 0xfffff;
  return;
}

/* public: void __thiscall CHmsItem::SetSolid(class CPlugSolid *) */

void __thiscall CHmsItem::SetSolid(CHmsItem *this, CPlugSolid *param_1)

{
  ulong uVar1;
  CHmsCorpus **ppCVar2;
  ulong uVar3;

  if (*(int *)(param_1 + 0x14) == 0) {
    CMwNod::MwAddRef((CMwNod *)param_1);
    if (*(int *)(this + 0x14) != 0) {
      *(undefined4 *)(*(int *)(this + 0x14) + 0x14) = 0;
      CMwNod::MwRelease(*(CMwNod **)(this + 0x14));
    }
    *(CPlugSolid **)(this + 0x14) = param_1;
    *(CHmsItem **)(param_1 + 0x14) = this;
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
    uVar3 = 0;
    if (uVar1 != 0) {
      do {
        ppCVar2 = (CHmsCorpus **)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
        CHmsCorpus::RefreshFromSolid(*ppCVar2);
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar1);
    }
  }
  return;
}

/* public: void __thiscall CHmsItem::SetTorque(class GmVec3 const &) */

void __thiscall CHmsItem::SetTorque(CHmsItem *this, GmVec3 *param_1)

{
  ulong uVar1;
  int *piVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar3);
      if (*(CHmsDyna **)(*piVar2 + 0x58) != (CHmsDyna *)0x0) {
        CHmsDyna::SetLocalTorque(*(CHmsDyna **)(*piVar2 + 0x58), param_1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* public: static unsigned long __cdecl CHmsItem::StaticInit(void) */

ulong __cdecl CHmsItem::StaticInit(void)

{
  undefined4 *puVar1;
  SProjectorReceivers *pSVar2;

  CFastArray<>::SetCount((CFastArray<> *)&s_CollisionGroupPairs, 5);
  puVar1 = (undefined4 *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)&s_CollisionGroupPairs, 0);
  *puVar1 = 3;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 0);
  *(undefined4 *)(pSVar2 + 4) = 1;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 0);
  *(undefined4 *)(pSVar2 + 0xc) = 0;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 0);
  *(undefined4 *)(pSVar2 + 0x10) = 1;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 0);
  *(undefined4 *)(pSVar2 + 8) = 0;
  puVar1 = (undefined4 *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)&s_CollisionGroupPairs, 1);
  *puVar1 = 2;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 1);
  *(undefined4 *)(pSVar2 + 4) = 4;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 1);
  *(undefined4 *)(pSVar2 + 0xc) = 1;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 1);
  *(undefined4 *)(pSVar2 + 0x10) = 0;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 1);
  *(undefined4 *)(pSVar2 + 8) = 0;
  puVar1 = (undefined4 *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)&s_CollisionGroupPairs, 2);
  *puVar1 = 3;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 2);
  *(undefined4 *)(pSVar2 + 4) = 3;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 2);
  *(undefined4 *)(pSVar2 + 0xc) = 1;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 2);
  *(undefined4 *)(pSVar2 + 0x10) = 1;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 2);
  *(undefined4 *)(pSVar2 + 8) = 1;
  puVar1 = (undefined4 *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)&s_CollisionGroupPairs, 3);
  *puVar1 = 3;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 3);
  *(undefined4 *)(pSVar2 + 4) = 4;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 3);
  *(undefined4 *)(pSVar2 + 0xc) = 1;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 3);
  *(undefined4 *)(pSVar2 + 0x10) = 1;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 3);
  *(undefined4 *)(pSVar2 + 8) = 1;
  puVar1 = (undefined4 *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)&s_CollisionGroupPairs, 4);
  *puVar1 = 1;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 4);
  *(undefined4 *)(pSVar2 + 4) = 5;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 4);
  *(undefined4 *)(pSVar2 + 0xc) = 1;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 4);
  *(undefined4 *)(pSVar2 + 0x10) = 0;
  pSVar2 =
      CFastBuffer<>::operator[]((CFastBuffer<> *)&s_CollisionGroupPairs, 4);
  *(undefined4 *)(pSVar2 + 8) = 0;
  return 0;
}

/* public: void __thiscall CHmsItem::TransformOf(class GmIso4 const &) */

void __thiscall CHmsItem::TransformOf(CHmsItem *this, GmIso4 *param_1)

{
  int *this_00;
  ulong uVar1;
  int **ppiVar2;
  GmIso4 *pGVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint local_3c;
  undefined4 local_30[12];

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  local_3c = 0;
  if (uVar1 != 0) {
    do {
      ppiVar2 = (int **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), local_3c);
      this_00 = *ppiVar2;
      if ((this_00[0x16] == 0) ||
          (puVar5 = (undefined4 *)(*(int *)(this_00[0x16] + 0x32c) + 0x10),
           puVar5 == (undefined4 *)0x0)) {
        puVar5 = (undefined4 *)param_1;
        puVar6 = local_30;
        for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        pGVar3 = (GmIso4 *)(**(code **)(*this_00 + 0x78))();
        GmIso4::Mult((GmIso4 *)local_30, pGVar3);
        CHmsCorpus::SetLocation((CHmsCorpus *)this_00, (GmIso4 *)local_30);
      } else {
        puVar6 = (undefined4 *)param_1;
        puVar7 = local_30;
        for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        GmIso4::Mult((GmIso4 *)local_30, (GmIso4 *)puVar5);
        puVar6 = local_30;
        for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar5 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar5 = puVar5 + 1;
        }
        if (this_00[0x16] == 0) {
          puVar5 = (undefined4 *)0x0;
        } else {
          puVar5 = (undefined4 *)(*(int *)(this_00[0x16] + 0x328) + 0x10);
        }
        puVar6 = (undefined4 *)param_1;
        puVar7 = local_30;
        for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        GmIso4::Mult((GmIso4 *)local_30, (GmIso4 *)puVar5);
        puVar6 = local_30;
        for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar5 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar5 = puVar5 + 1;
        }
      }
      local_3c = local_3c + 1;
    } while (local_3c < uVar1);
  }
  return;
}

/* protected: void __thiscall CHmsItem::UpdateCorpusCat(void) */

void __thiscall CHmsItem::UpdateCorpusCat(CHmsItem *this)

{
  CHmsZone *this_00;
  EHmsCorpusCat EVar1;
  CMwCmd **ppCVar2;
  int iVar3;
  ulong uVar4;
  CMwCmd *local_10;
  EHmsCorpusCat local_c;
  ulong local_8;
  ulong local_4;

  EVar1 = GetCorpusCat(this);
  local_4 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar4 = 0;
  if (local_4 != 0) {
    do {
      ppCVar2 = (CMwCmd **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar4);
      local_10 = *ppCVar2;
      this_00 = *(CHmsZone **)(local_10 + 0x14);
      iVar3 = CFastBufferCat<>::FindIndexInAll(
          (CFastBufferCat<> *)(this_00 + 0x1c), &local_10, &local_8, &local_c);
      if ((iVar3 != 0) && (local_c != EVar1)) {
        CHmsZone::CorpusChangeCat(this_00, local_8, local_c, EVar1);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < local_4);
  }
  return;
}

/* protected: void __thiscall CHmsItem::UpdateIsBuild(void) */

void __thiscall CHmsItem::UpdateIsBuild(CHmsItem *this)

{
  CHmsCorpus *pCVar1;
  CHmsZone *this_00;
  int iVar2;
  ulong uVar3;
  CHmsCorpus **ppCVar4;
  ulong uVar5;
  uint uVar6;
  ulong uVar7;
  int local_c;

  uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x28));
  if ((uVar3 != 0) || (local_c = 0, *(int *)(this + 0x30) != 0)) {
    local_c = 1;
  }
  uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x34));
  uVar7 = 0;
  if (uVar3 != 0) {
    do {
      ppCVar4 = (CHmsCorpus **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x34), uVar7);
      pCVar1 = *ppCVar4;
      this_00 = *(CHmsZone **)(pCVar1 + 0x14);
      iVar2 = *(int *)(this_00 + 0x2c);
      uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this_00 + 0x28));
      uVar6 = 0;
      if (uVar5 != 0) {
        do {
          if (*(CHmsCorpus **)(iVar2 + uVar6 * 4) == pCVar1) {
            CHmsZone::CorpusChangeBuild(this_00, pCVar1, local_c);
            break;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar5);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar3);
  }
  return;
}

/* public: virtual unsigned long __thiscall CHmsItem::VirtualParam_Get(class
   CMwStack *,class CMwValueStd *) */

ulong __thiscall CHmsItem::VirtualParam_Get(CHmsItem *this, CMwStack *param_1,
                                            CMwValueStd *param_2)

{
  GmVec3 *pGVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;

  iVar2 = *(int *)(param_1 + 0x18);
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + iVar2 * 4);
  *(int *)(param_1 + 0x18) = iVar2 + -1;
  uVar4 = *(uint *)(iVar3 + 4);
  if (uVar4 < 0x600301d) {
    if (uVar4 == 0x600301c) {
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x1c & 1;
      return 0;
    }
    switch (uVar4) {
    case 0x6003003:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0xd & 0xf;
      return 0;
    case 0x6003004:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0xb & 3;
      return 0;
    case 0x6003005:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x11 & 3;
      return 0;
    case 0x6003006:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x14 & 1;
      return 0;
    case 0x6003007:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 8 & 1;
      return 0;
    case 0x6003008:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x13 & 1;
      return 0;
    case 0x6003009:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 9 & 1;
      return 0;
    case 0x600300a:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x19 & 1;
      return 0;
    case 0x600300b:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x1a & 1;
      return 0;
    case 0x600300c:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 10 & 1;
      return 0;
    case 0x600300d:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x16 & 1;
      return 0;
    case 0x600300e:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) >> 0xc & 1;
      return 0;
    case 0x600300f:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (uint)(byte)this[0x18];
      return 0;
    case 0x6003010:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x17 & 1;
      return 0;
    case 0x6003011:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x18) >> 0x1b & 1;
      return 0;
    case 0x6003012:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) & 1;
      return 0;
    case 0x6003013:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) & 2;
      return 0;
    case 0x6003014:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) & 4;
      return 0;
    case 0x6003015:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) & 8;
      return 0;
    case 0x6003016:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) >> 0x14 & 1;
      return 0;
    case 0x6003017:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) >> 0x14 & 2;
      return 0;
    case 0x6003018:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) >> 0x14 & 4;
      return 0;
    case 0x6003019:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) >> 0x14 & 8;
      return 0;
    case 0x600301b:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x1b] & 1;
      return 0;
    }
  } else if (uVar4 < 0x6003029) {
    if (uVar4 == 0x6003028) {
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (uint)((byte)this[0x20] >> 7);
      return 0;
    }
    switch (uVar4) {
    case 0x600301d:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x1e] & 1;
      return 0;
    case 0x600301e:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x1e] & 2;
      return 0;
    case 0x600301f:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x1e] & 4;
      return 0;
    case 0x6003020:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x1e] & 8;
      return 0;
    case 0x6003021:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x20] & 1;
      return 0;
    case 0x6003022:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x20] >> 1 & 1;
      return 0;
    case 0x6003023:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x20] >> 2 & 1;
      return 0;
    case 0x6003024:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x20] >> 3 & 1;
      return 0;
    case 0x6003025:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x20] >> 4 & 1;
      return 0;
    case 0x6003026:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x20] >> 5 & 1;
      return 0;
    case 0x6003027:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x20] >> 6 & 1;
      return 0;
    }
  } else if (uVar4 < 0x600302f) {
    if (uVar4 == 0x600302e) {
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0x20) >> 0xd & 1;
      return 0;
    }
    switch (uVar4) {
    case 0x6003029:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (byte)this[0x21] & 1;
      return 0;
    case 0x600302a:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0x20) >> 9 & 1;
      return 0;
    case 0x600302b:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0x20) >> 10 & 1;
      return 0;
    case 0x600302c:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0x20) >> 0xb & 1;
      return 0;
    case 0x600302d:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0x20) >> 0xc & 1;
      return 0;
    }
  } else {
    if (0x6003032 < uVar4) {
      if (uVar4 == 0x6003033) {
        pGVar1 = (GmVec3 *)(param_2 + 4);
        *(GmVec3 **)param_2 = pGVar1;
        GetLinearSpeed(this, pGVar1);
        CMwParamVec3::GetValue(pGVar1, param_1, param_2);
      } else if (uVar4 != 0xffffffff)
        goto switchD_0053c498_caseD_600301a;
      return 0;
    }
    if (uVar4 == 0x6003032) {
      pGVar1 = (GmVec3 *)(param_2 + 4);
      *(GmVec3 **)param_2 = pGVar1;
      GetAngularSpeed(this, pGVar1);
      CMwParamVec3::GetValue(pGVar1, param_1, param_2);
      return 0;
    }
    if (uVar4 == 0x600302f) {
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(ushort *)(this + 0x20) >> 0xe & 1;
      return 0;
    }
    if (uVar4 == 0x6003030) {
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) >> 0xf & 1;
      return 0;
    }
  }
switchD_0053c498_caseD_600301a:
  *(int *)(param_1 + 0x18) = iVar2;
  uVar5 = CMwNod::VirtualParam_Get((CMwNod *)this, param_1, param_2);
  return uVar5;
}

/* public: virtual unsigned long __thiscall CHmsItem::VirtualParam_Set(class
 * CMwStack *,void *) */

ulong __thiscall CHmsItem::VirtualParam_Set(CHmsItem *this, CMwStack *param_1,
                                            void *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  GmVec3 *pGVar7;
  GmVec3 *pGVar8;
  ulong uVar9;
  ushort uVar10;
  undefined4 local_c[3];

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
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x1c) =
          ((~(1 << (cVar5 - 0x1dU & 0x1f)) << 0x10 & uVar6 |
            ((uint)(*param_2 != 0) << (cVar5 - 0x1dU & 0x1f)) << 0x10) ^
           uVar6) &
              0xf0000 ^
          uVar6;
      return 0;
    }
    switch (uVar6) {
    case 0x6003000:
      if (iVar1 < 0) {
        SetSolid(this, (CPlugSolid *)param_2);
        return 0;
      }
      CMwParamClass::SetValue((CMwNod **)(this + 0x14), param_1, param_2);
      return 0;
    case 0x6003003:
      /* WARNING: Load size is inaccurate */
      SetCollisionGroup(this, *param_2);
      return 0;
    case 0x6003004:
      /* WARNING: Load size is inaccurate */
      SetDynamicType(this, *param_2);
      return 0;
    case 0x6003005:
      /* WARNING: Load size is inaccurate */
      SetContactInterest(this, *param_2);
      return 0;
    case 0x6003006:
      /* WARNING: Load size is inaccurate */
      SetIsKinematicOnly(this, *param_2);
      return 0;
    case 0x6003007:
      /* WARNING: Load size is inaccurate */
      SetIsVisionStatic(this, *param_2);
      return 0;
    case 0x6003008:
      /* WARNING: Load size is inaccurate */
      SetIsCollisionStatic(this, *param_2);
      return 0;
    case 0x6003009:
      /* WARNING: Load size is inaccurate */
      if ((uint)(*param_2 != 0) == (*(uint *)(this + 0x18) >> 9 & 1)) {
        return 0;
      }
      SetIsBackground(this, (uint)(*param_2 != 0));
      return 0;
    case 0x600300a:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x18) =
          *(uint *)(this + 0x18) ^
          ((uint)(*param_2 != 0) << 0x19 ^ *(uint *)(this + 0x18)) & 0x2000000;
      return 0;
    case 0x600300b:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x18) =
          *(uint *)(this + 0x18) ^
          ((uint)(*param_2 != 0) << 0x1a ^ *(uint *)(this + 0x18)) & 0x4000000;
      return 0;
    case 0x600300c:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x18) =
          *(uint *)(this + 0x18) ^
          ((uint)(*param_2 != 0) << 10 ^ *(uint *)(this + 0x18)) & 0x400;
      return 0;
    case 0x600300d:
      /* WARNING: Load size is inaccurate */
      SetOccluderForLightMap(this, *param_2);
      return 0;
    case 0x600300e:
      /* WARNING: Load size is inaccurate */
      SetIsForcePointDynamicCollisionResponse(this, *param_2);
      return 0;
    case 0x600300f:
      /* WARNING: Load size is inaccurate */
      uVar6 = *param_2;
      if (0xff < uVar6) {
        uVar6 = 0xff;
      }
      SetCountShadowTexCasted(this, (uchar)uVar6,
                              *(uint *)(this + 0x18) >> 0x17 & 1);
      return 0;
    case 0x6003010:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x18) =
          *(uint *)(this + 0x18) ^
          ((uint)(*param_2 != 0) << 0x17 ^ *(uint *)(this + 0x18)) & 0x800000;
      return 0;
    case 0x6003011:
      /* WARNING: Load size is inaccurate */
      SetShadowFakeEnable(this, *param_2);
      return 0;
    case 0x6003012:
    case 0x6003013:
    case 0x6003014:
    case 0x6003015:
      uVar6 = *(uint *)(this + 0x1c);
      /* WARNING: Load size is inaccurate */
      uVar6 = ((~(1 << (cVar5 - 0x12U & 0x1f)) & uVar6 |
                (uint)(*param_2 != 0) << (cVar5 - 0x12U & 0x1f)) ^
               uVar6) &
                  0xfff ^
              uVar6;
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
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x1c) =
          (~(1 << (cVar5 - 0x16U & 0x1f)) << 0x14 & *(uint *)(this + 0x1c) |
           ((uint)(*param_2 != 0) << (cVar5 - 0x16U & 0x1f)) << 0x14) ^
          *(uint *)(this + 0x1c) & 0xfffff;
      return 0;
    case 0x600301b:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x18) =
          *(uint *)(this + 0x18) ^
          (*param_2 << 0x18 ^ *(uint *)(this + 0x18)) & 0x1000000;
      return 0;
    case 0x600301c:
      /* WARNING: Load size is inaccurate */
      SetLightLensFlareEnable(this, *param_2);
      return 0;
    }
  } else {
    if (uVar6 < 0x600302c) {
      if (uVar6 == 0x600302b) {
        /* WARNING: Load size is inaccurate */
        param_2 = (void *)CONCAT22(
            param_2._2_2_,
            ((ushort)(*param_2 != 0) << 10 ^ *(ushort *)(this + 0x20)) & 0x400 ^
                *(ushort *)(this + 0x20));
        VisibleIdSet(this, (SPlugVisibleId *)&param_2);
        return 0;
      }
      switch (uVar6) {
      case 0x6003021:
        /* WARNING: Load size is inaccurate */
        uVar10 = (*param_2 != 0 ^ (byte)this[0x20]) & 1;
        break;
      case 0x6003022:
        /* WARNING: Load size is inaccurate */
        uVar10 = (byte)((*param_2 != 0) * '\x02' ^ (byte)this[0x20]) & 2;
        break;
      case 0x6003023:
        /* WARNING: Load size is inaccurate */
        uVar10 = (byte)((*param_2 != 0) * '\x04' ^ (byte)this[0x20]) & 4;
        break;
      case 0x6003024:
        /* WARNING: Load size is inaccurate */
        uVar10 = (byte)((*param_2 != 0) * '\b' ^ (byte)this[0x20]) & 8;
        break;
      case 0x6003025:
        /* WARNING: Load size is inaccurate */
        uVar10 = (byte)((*param_2 != 0) << 4 ^ (byte)this[0x20]) & 0x10;
        break;
      case 0x6003026:
        /* WARNING: Load size is inaccurate */
        uVar10 = (byte)((*param_2 != 0) << 5 ^ (byte)this[0x20]) & 0x20;
        break;
      case 0x6003027:
        /* WARNING: Load size is inaccurate */
        uVar10 = (byte)((*param_2 != 0) << 6 ^ (byte)this[0x20]) & 0x40;
        break;
      case 0x6003028:
        /* WARNING: Load size is inaccurate */
        uVar10 = (byte)((*param_2 != 0) << 7 ^ (byte)this[0x20]) & 0x80;
        break;
      case 0x6003029:
        /* WARNING: Load size is inaccurate */
        param_2 = (void *)CONCAT22(
            param_2._2_2_,
            ((ushort)(*param_2 != 0) << 8 ^ *(ushort *)(this + 0x20)) & 0x100 ^
                *(ushort *)(this + 0x20));
        VisibleIdSet(this, (SPlugVisibleId *)&param_2);
        return 0;
      case 0x600302a:
        /* WARNING: Load size is inaccurate */
        param_2 = (void *)CONCAT22(
            param_2._2_2_,
            ((ushort)(*param_2 != 0) << 9 ^ *(ushort *)(this + 0x20)) & 0x200 ^
                *(ushort *)(this + 0x20));
        VisibleIdSet(this, (SPlugVisibleId *)&param_2);
        return 0;
      default:
        goto switchD_0053d8f4_caseD_6003001;
      }
      param_2 =
          (void *)CONCAT22(param_2._2_2_, uVar10 ^ *(ushort *)(this + 0x20));
      VisibleIdSet(this, (SPlugVisibleId *)&param_2);
      return 0;
    }
    if (uVar6 < 0x6003031) {
      if (uVar6 == 0x6003030) {
        /* WARNING: Load size is inaccurate */
        IsVisibleSet(this, *param_2);
        return 0;
      }
      switch (uVar6) {
      case 0x600302c:
        /* WARNING: Load size is inaccurate */
        param_2 =
            (void *)CONCAT22(param_2._2_2_, ((ushort)(*param_2 != 0) << 0xb ^
                                             *(ushort *)(this + 0x20)) &
                                                    0x800 ^
                                                *(ushort *)(this + 0x20));
        VisibleIdSet(this, (SPlugVisibleId *)&param_2);
        return 0;
      case 0x600302d:
        /* WARNING: Load size is inaccurate */
        param_2 =
            (void *)CONCAT22(param_2._2_2_, ((ushort)(*param_2 != 0) << 0xc ^
                                             *(ushort *)(this + 0x20)) &
                                                    0x1000 ^
                                                *(ushort *)(this + 0x20));
        VisibleIdSet(this, (SPlugVisibleId *)&param_2);
        return 0;
      case 0x600302e:
        /* WARNING: Load size is inaccurate */
        param_2 =
            (void *)CONCAT22(param_2._2_2_, ((ushort)(*param_2 != 0) << 0xd ^
                                             *(ushort *)(this + 0x20)) &
                                                    0x2000 ^
                                                *(ushort *)(this + 0x20));
        VisibleIdSet(this, (SPlugVisibleId *)&param_2);
        return 0;
      case 0x600302f:
        /* WARNING: Load size is inaccurate */
        param_2 =
            (void *)CONCAT22(param_2._2_2_, ((ushort)(*param_2 != 0) << 0xe ^
                                             *(ushort *)(this + 0x20)) &
                                                    0x4000 ^
                                                *(ushort *)(this + 0x20));
        VisibleIdSet(this, (SPlugVisibleId *)&param_2);
        return 0;
      }
    } else if (uVar6 < 0x6003034) {
      if (uVar6 == 0x6003033) {
        if (iVar1 < 0) {
          SetLinearSpeed(this, (GmVec3 *)param_2);
          return 0;
        }
        iVar1 = *piVar3;
        GetLinearSpeed(this, (GmVec3 *)local_c);
        /* WARNING: Load size is inaccurate */
        local_c[iVar1] = *param_2;
        SetLinearSpeed(this, (GmVec3 *)local_c);
        return 0;
      }
      if (uVar6 == 0x6003031) {
        param_2 = (void *)0xffffffff;
        pGVar7 = (GmVec3 *)CMwStack::GetArgument(param_1, 0, 0x10000006,
                                                 (ulong *)&param_2);
        pGVar8 = (GmVec3 *)CMwStack::GetArgument(param_1, 1, 0x10000006,
                                                 (ulong *)&param_2);
        if ((pGVar7 != (GmVec3 *)0x0) && (pGVar8 != (GmVec3 *)0x0)) {
          AddImpulse(this, pGVar7, pGVar8);
          return 0;
        }
        return 0;
      }
      if (uVar6 == 0x6003032) {
        if (iVar1 < 0) {
          SetAngularSpeed(this, (GmVec3 *)param_2);
          return 0;
        }
        iVar1 = *piVar3;
        GetAngularSpeed(this, (GmVec3 *)local_c);
        /* WARNING: Load size is inaccurate */
        local_c[iVar1] = *param_2;
        SetAngularSpeed(this, (GmVec3 *)local_c);
        return 0;
      }
    } else if (uVar6 == 0xffffffff) {
      return 0;
    }
  }
switchD_0053d8f4_caseD_6003001:
  *(int *)(param_1 + 0x18) = iVar2;
  uVar9 = CMwNod::VirtualParam_Set((CMwNod *)this, param_1, param_2);
  return uVar9;
}

/* public: void __thiscall CHmsItem::VisibleIdSet(struct SPlugVisibleId const &)
 */

void __thiscall CHmsItem::VisibleIdSet(CHmsItem *this, SPlugVisibleId *param_1)

{
  if ((((byte)this[0x20] ^ (byte) * (ushort *)param_1) & 1) != 0) {
    SetLightEmitter(this, *(ushort *)param_1 & 1);
    *(undefined2 *)(this + 0x20) = *(undefined2 *)param_1;
    return;
  }
  *(undefined2 *)(this + 0x20) = *(undefined2 *)param_1;
  return;
}

/* public: virtual __thiscall CHmsItem::~CHmsItem(void) */

void __thiscall CHmsItem::~CHmsItem(CHmsItem *this)

{
  SCallbackList *this_00;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00a95889;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 3;
  operator_delete(*(void **)(this + 0x54));
  this_00 = *(SCallbackList **)(this + 0x24);
  *(undefined4 *)(this + 0x54) = 0;
  if (this_00 != (SCallbackList *)0x0) {
    SCallbackList::~SCallbackList(this_00);
    operator_delete(this_00);
  }
  *(undefined4 *)(this + 0x24) = 0;
  if (*(int *)(this + 0x14) != 0) {
    *(undefined4 *)(*(int *)(this + 0x14) + 0x14) = 0;
    CMwNod::MwRelease(*(CMwNod **)(this + 0x14));
  }
  CFastArray<>::ReleaseAll((CFastArray<> *)(this + 0x28));
  local_4 = CONCAT31(local_4._1_3_, 2);
  if (*(CMwNod **)(this + 0x44) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x44));
  }
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x34));
  CFastArray<>::~CFastArray<>((CFastArray<> *)(CFastArray<> *)(this + 0x28));
  local_4 = 0xffffffff;
  CMwNod::~CMwNod((CMwNod *)this);
  ExceptionList = local_c;
  return;
}
