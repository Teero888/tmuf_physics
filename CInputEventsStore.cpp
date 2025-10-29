
/* public: void __thiscall CFastBuffer<struct
   CInputEventsStore::SCachedValue>::Add(struct CInputEventsStore::SCachedValue
   const &) */

void __thiscall CFastBuffer<>::Add(CFastBuffer<> *this, SCachedValue *param_1)

{
  undefined4 *puVar1;
  int iVar2;

  iVar2 = *(int *)this;
  CFastBuffer<>::SetSizeAtLeast((CFastBuffer<> *)this, iVar2 + 1U);
  puVar1 = (undefined4 *)(*(int *)(this + 4) + *(int *)this * 0xc);
  *puVar1 = *(undefined4 *)param_1;
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 8);
  *(ulong *)this = iVar2 + 1U;
  return;
}

/* public: int __thiscall CInputEventsStore::Add(struct SInputEvent const
 * &,unsigned long) */

int __thiscall CInputEventsStore::Add(CInputEventsStore *this,
                                      SInputEvent *param_1, ulong param_2)

{
  int iVar1;

  iVar1 = InsertSorted(this, param_1, param_2);
  return iVar1;
}

/* public: void __thiscall CFastBuffer<struct
   CInputEventsStore::SCachedValue>::Add(struct CInputEventsStore::SCachedValue
   const &) */

void __thiscall CFastBuffer<>::Add(CFastBuffer<> *this, SCachedValue *param_1)

{
  undefined4 *puVar1;
  int iVar2;

  iVar2 = *(int *)this;
  CFastBuffer<>::SetSizeAtLeast((CFastBuffer<> *)this, iVar2 + 1U);
  puVar1 = (undefined4 *)(*(int *)(this + 4) + *(int *)this * 0xc);
  *puVar1 = *(undefined4 *)param_1;
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 8);
  *(ulong *)this = iVar2 + 1U;
  return;
}

/* public: void __thiscall CInputEventsStore::Archive(class CClassicArchive &)
 */

void __thiscall CInputEventsStore::Archive(CInputEventsStore *this,
                                           CClassicArchive *param_1)

{
  ulong *puVar1;
  CClassicArchive *this_00;
  uint uVar2;
  GmVector2<> *pGVar3;
  ulong uVar4;
  CGameMenuFrame **ppCVar5;
  int iVar6;
  ulong uVar7;
  uint uVar8;
  CClassicArchive *pCVar9;
  uint local_2c;
  ulong local_28;
  uint local_24;
  ulong local_20;
  uint local_1c;
  CFastBuffer<> local_18[12];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  this_00 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae0368;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar8 = 0;
  local_28 = 0;
  CClassicArchive::DoNatural(param_1, &local_28, 1, 0);
  CFastBuffer<>::CFastBuffer<>(local_18);
  local_4 = 0;
  if (*(int *)(this_00 + 8) == 0) {
    ClearStore(this);
    CFastBuffer<>::ArchiveCount((CFastBuffer<> *)local_18, this_00);
    uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)local_18);
    if (uVar4 != 0) {
      uVar4 = 0;
      do {
        pCVar9 = this_00;
        pGVar3 = CFastBuffer<>::operator[]((CFastBuffer<> *)local_18, uVar4);
        CMwId::Archive((CMwId *)pGVar3, pCVar9);
        pGVar3 = CFastBuffer<>::operator[]((CFastBuffer<> *)local_18, uVar4);
        RegisterInput(this, (SInputActionDesc *)0x0, (CMwId *)pGVar3);
        uVar4 = uVar4 + 1;
        uVar7 = CFastBuffer<>::GetCount((CFastBuffer<> *)local_18);
      } while (uVar4 < uVar7);
    }
    CClassicArchive::DoNatural(this_00, &local_2c, 1, 0);
    CClassicArchive::DoNatural(this_00, (ulong *)(this + 0x10), 1, 0);
    if (local_2c != 0) {
      do {
        CClassicArchive::DoNatural(this_00, &local_20, 1, 0);
        CClassicArchive::DoNat8(this_00, (uchar *)&param_1, 1, 0);
        CClassicArchive::DoNatural(this_00, &local_24, 1, 0);
        uVar2 = local_1c ^ (local_1c ^ local_24) & 0xffffff;
        local_1c = uVar2;
        ppCVar5 = (CGameMenuFrame **)CFastBuffer<>::operator[](
            (CFastBuffer<> *)local_18, (uint)param_1 & 0xff);
        iVar6 = CFastArray<>::Find((CFastArray<> *)(this + 0x2c), ppCVar5);
        local_1c = iVar6 << 0x18 | uVar2 & 0xffffff;
        CFastBufferWheel<>::Push((CFastBufferWheel<> *)this,
                                 (GmVec2 *)&local_20);
        uVar8 = uVar8 + 1;
      } while (uVar8 < local_2c);
    }
  } else {
    uVar8 = 0;
    if (*(int *)this != 0) {
      do {
        uVar2 = *(int *)(this + 0xc) + uVar8;
        if (*(uint *)(this + 8) <= uVar2) {
          uVar2 = uVar2 - *(uint *)(this + 8);
        }
        pGVar3 = CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x2c),
            (uint) * (byte *)(*(int *)(this + 4) + 7 + uVar2 * 8));
        CFastBuffer<>::FindOrAdd((CFastBuffer<> *)local_18, (CMwId *)pGVar3);
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(uint *)this);
    }
    CFastBuffer<>::ArchiveCount((CFastBuffer<> *)local_18, this_00);
    uVar7 = 0;
    uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)local_18);
    if (uVar4 != 0) {
      do {
        pCVar9 = this_00;
        pGVar3 = CFastBuffer<>::operator[]((CFastBuffer<> *)local_18, uVar7);
        CMwId::Archive((CMwId *)pGVar3, pCVar9);
        uVar7 = uVar7 + 1;
        uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)local_18);
      } while (uVar7 < uVar4);
    }
    CClassicArchive::DoNatural(this_00, (ulong *)this, 1, 0);
    CClassicArchive::DoNatural(this_00, (ulong *)(this + 0x10), 1, 0);
    uVar8 = *(uint *)this;
    uVar2 = 0;
    if (uVar8 != 0) {
      do {
        uVar8 = (*(int *)(this + 0xc) - uVar2) + -1 + uVar8;
        if (*(uint *)(this + 8) <= uVar8) {
          uVar8 = uVar8 - *(uint *)(this + 8);
        }
        puVar1 = (ulong *)(*(int *)(this + 4) + uVar8 * 8);
        ppCVar5 = (CGameMenuFrame **)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x2c), (uint) * (byte *)((int)puVar1 + 7));
        iVar6 = CFastArray<>::Find((CFastArray<> *)local_18, ppCVar5);
        param_1 = (CClassicArchive *)CONCAT31(param_1._1_3_, (char)iVar6);
        local_2c = puVar1[1] & 0xffffff;
        CClassicArchive::DoNatural(this_00, puVar1, 1, 0);
        CClassicArchive::DoNat8(this_00, (uchar *)&param_1, 1, 0);
        CClassicArchive::DoNatural(this_00, &local_2c, 1, 0);
        uVar8 = *(uint *)this;
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar8);
    }
  }
  local_4 = 0xffffffff;
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)local_18);
  ExceptionList = local_c;
  return;
}

/* protected: unsigned long __thiscall
   CInputEventsStore::AutoRegisterInput(struct SInputActionDesc const *) */

ulong __thiscall CInputEventsStore::AutoRegisterInput(CInputEventsStore *this,
                                                      SInputActionDesc *param_1)

{
  ulong uVar1;
  undefined4 *puVar2;
  SCachedValue *pSVar3;
  undefined4 local_1c;
  SCachedValue local_18[12];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae0338;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x20));
  puVar2 = CMwId::CreateFromLocalIndex(&local_1c, uVar1);
  local_4 = 0;
  CFastBuffer<>::Add((CFastBuffer<> *)(this + 0x2c), (CMwId *)puVar2);
  local_4 = 0xffffffff;
  CScene2d::OnNodLoaded((CScene2d *)&local_1c);
  CFastBuffer<>::Add((CFastBuffer<> *)(CFastBuffer<> *)(this + 0x20),
                     (CDx9TextureKeeper **)&param_1);
  pSVar3 = (SCachedValue *)SCachedValue::SCachedValue(local_18, uVar1);
  CFastBuffer<>::Add((CFastBuffer<> *)(this + 0x38), pSVar3);
  ExceptionList = local_c;
  return uVar1;
}

/* public: __thiscall CInputEventsStore::CInputEventsStore(unsigned long,int) */

CInputEventsStore *__thiscall CInputEventsStore::CInputEventsStore(
    CInputEventsStore *this, ulong param_1, int param_2)

{
  CFastBufferWheel<>::CFastBufferWheel<>((CFastBufferWheel<> *)this, param_1);
  *(int *)(this + 0x18) = param_2;
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x20));
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x2c));
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x38));
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  return this;
}

/* public: void __thiscall CInputEventsStore::ClearStore(void) */

void __thiscall CInputEventsStore::ClearStore(CInputEventsStore *this)

{
  ulong uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  ulong uVar4;
  SCachedValue local_c[12];

  CFastBufferWheel<>::ClearWheel((CFastBufferWheel<> *)this);
  *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x20));
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      puVar2 = (undefined4 *)SCachedValue::SCachedValue(local_c, uVar4);
      puVar3 = (undefined4 *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(this + 0x38), uVar4);
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[1];
      uVar4 = uVar4 + 1;
      puVar3[2] = puVar2[2];
    } while (uVar4 < uVar1);
  }
  Lock(this, 0);
  return;
}

/* protected: void __thiscall CInputEventsStore::Convert(struct
   SInputEventsStoreElem const &,struct SInputEvent &)const  */

void __thiscall CInputEventsStore::Convert(CInputEventsStore *this,
                                           SInputEventsStoreElem *param_1,
                                           SInputEvent *param_2)

{
  undefined4 *puVar1;
  float fVar2;

  puVar1 = (undefined4 *)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(this + 0x20), (uint)(byte)param_1[3]);
  puVar1 = (undefined4 *)*puVar1;
  *(undefined4 **)param_2 = puVar1;
  switch (*puVar1) {
  case 0:
  case 3:
    *(uint *)(param_2 + 4) = *(uint *)param_1 & 0xffffff;
    return;
  case 1:
    *(float *)(param_2 + 4) =
        (float)((*(int *)param_1 << 8) >> 8) * 1.525879e-05;
    return;
  case 2:
    break;
  case 4:
    *(undefined4 *)param_2 = DAT_00d71448;
    *(undefined4 *)(param_2 + 4) = DAT_00d7144c;
  default:
    return;
  }
  if ((*(uint *)param_1 & 0xffffff) != 0) {
    fVar2 = GmFunc::Nat16ToReal(*(short *)param_1 - 100, 0.0, 360.0);
    *(float *)(param_2 + 4) = fVar2;
    return;
  }
  *(undefined4 *)(param_2 + 4) = 0xbf800000;
  return;
}

/* protected: int __thiscall CInputEventsStore::Convert(struct SInputEvent const
   &,struct SInputEventsStoreElem &)const  */

int __thiscall CInputEventsStore::Convert(CInputEventsStore *this,
                                          SInputEvent *param_1,
                                          SInputEventsStoreElem *param_2)

{
  ushort uVar1;
  ulong uVar2;
  uint uVar3;
  float fVar4;
  uint local_8;

  uVar2 = CFastArray<>::Find((CFastArray<> *)(this + 0x20),
                             (CGameMenuFrame **)param_1);
  if (uVar2 == 0xffffffff) {
    if (*(int *)(this + 0x18) != 0) {
      return 0;
    }
    uVar2 = AutoRegisterInput(this, *(SInputActionDesc **)param_1);
  }
  param_2[3] = SUB41(uVar2, 0);
  switch (**(undefined4 **)param_1) {
  case 0:
    *(uint *)param_2 =
        *(uint *)param_2 ^
        ((uint)(*(int *)(param_1 + 4) != 0) ^ *(uint *)param_2) & 0xffffff;
    return 1;
  case 1:
    fVar4 = GmFunc::ClampReal(*(float *)(param_1 + 4), -100.0, 100.0);
    local_8 = (uint)(longlong)ROUND(fVar4 * 65536.0);
    *(uint *)param_2 =
        *(uint *)param_2 ^ (local_8 ^ *(uint *)param_2) & 0xffffff;
    return 1;
  case 2:
    break;
  case 3:
    *(uint *)param_2 = *(uint *)param_2 ^
                       (*(uint *)(param_1 + 4) ^ *(uint *)param_2) & 0xffffff;
    return 1;
  case 4:
    DAT_00d7144c = *(undefined4 *)(param_1 + 4);
    DAT_00d71448 = *(undefined4 **)param_1;
    *(uint *)param_2 = *(uint *)param_2 & 0xff0004d2 | 0x4d2;
    return 1;
  default:
    return 0;
  }
  if (-0.5 <= *(float *)(param_1 + 4)) {
    uVar1 = GmFunc::RealToNat16(*(float *)(param_1 + 4), 0.0, 360.0);
    uVar3 = uVar1 + 100;
  } else {
    uVar3 = 0;
  }
  *(uint *)param_2 = *(uint *)param_2 ^ (*(uint *)param_2 ^ uVar3) & 0xffffff;
  return 1;
}

/* public: void __thiscall CInputEventsStore::CopyStore(class CInputEventsStore
 * const &) */

void __thiscall CInputEventsStore::CopyStore(CInputEventsStore *this,
                                             CInputEventsStore *param_1)

{
  ulong uVar1;
  SInputActionDesc **ppSVar2;
  GmVector2<> *pGVar3;
  ulong uVar4;
  CFastBuffer<> *this_00;

  ReInit(this);
  this_00 = (CFastBuffer<> *)(param_1 + 0x20);
  uVar4 = 0;
  uVar1 = CFastBuffer<>::GetCount(this_00);
  if (uVar1 != 0) {
    do {
      ppSVar2 = (SInputActionDesc **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)this_00, uVar4);
      pGVar3 =
          CFastBuffer<>::operator[]((CFastBuffer<> *)(param_1 + 0x2c), uVar4);
      RegisterInput(this, *ppSVar2, (CMwId *)pGVar3);
      uVar4 = uVar4 + 1;
      uVar1 = CFastBuffer<>::GetCount(this_00);
    } while (uVar4 < uVar1);
  }
  CFastBufferWheel<>::CopyFromWheel((CFastBufferWheel<> *)this,
                                    (CFastBufferWheel<> *)param_1);
  return;
}

/* private: __thiscall CInputEventsStore::CScanner::CScanner(unsigned
   long,unsigned long,class CInputEventsStore const *) */

CScanner *__thiscall CInputEventsStore::CScanner::CScanner(
    CScanner *this, ulong param_1, ulong param_2, CInputEventsStore *param_3)

{
  ulong uVar1;
  uint uVar2;

  *(CInputEventsStore **)this = param_3;
  *(ulong *)(this + 8) = param_1;
  *(ulong *)(this + 0xc) = param_2;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_3 + 0x1c);
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)param_3);
  *(ulong *)(this + 0x14) = uVar1;
  *(undefined4 *)(this + 4) = 0;
  if (uVar1 != 0) {
    do {
      uVar2 = *(int *)(param_3 + 0xc) + *(int *)(this + 4);
      if (*(uint *)(param_3 + 8) <= uVar2) {
        uVar2 = uVar2 - *(uint *)(param_3 + 8);
      }
    } while ((param_1 < *(uint *)(*(int *)(param_3 + 4) + uVar2 * 8)) &&
             (uVar2 = *(int *)(this + 4) + 1, *(uint *)(this + 4) = uVar2,
              uVar2 < *(uint *)(this + 0x14)));
  }
  return this;
}

/* public: class CInputEventsStore::CScanner __thiscall
   CInputPort::GetEvents(unsigned long,unsigned long) */

CScanner *__thiscall CInputPort::GetEvents(CInputPort *this, CScanner *param_1,
                                           ulong param_2, ulong param_3)

{
  InternalGatherLatestInputs(this);
  CInputEventsStore::Lock((CInputEventsStore *)(this + 0x40), param_3);
  CInputEventsStore::Scan((CInputEventsStore *)(this + 0x40), param_1, param_2,
                          param_3);
  return param_1;
}

/* public: class CInputEventsStore::CScanner __thiscall
 * CInputPort::GetEventsNotTimed(void) */

CScanner *__thiscall CInputPort::GetEventsNotTimed(CInputPort *this,
                                                   CScanner *param_1)

{
  InternalGatherLatestInputs(this);
  *(int *)(this + 0x38) = *(int *)(this + 0x38) + 1;
  CInputEventsStore::Lock((CInputEventsStore *)(this + 0x40),
                          *(int *)(this + 0x38) - 1);
  CInputEventsStore::Scan((CInputEventsStore *)(this + 0x40), param_1,
                          *(int *)(this + 0x38) - 2, *(int *)(this + 0x38) - 1);
  return param_1;
}

/* public: int __thiscall CInputEventsStore::CScanner::GetNext(struct
   SMwTimedValueInstant<struct SInputEvent> &) */

int __thiscall CInputEventsStore::CScanner::GetNext(
    CScanner *this, SMwTimedValueInstant<> *param_1)

{
  CFastBuffer<> *this_00;
  int iVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;

  *(int *)(this + 4) = *(int *)(this + 4) + -1;
  uVar4 = *(uint *)(this + 4);
  if ((uVar4 != 0xffffffff) &&
      (this_00 = *(CFastBuffer<> **)this,
       *(int *)(this_00 + 0x1c) == *(int *)(this + 0x10))) {
    uVar2 = CFastBuffer<>::GetCount(this_00);
    if (uVar4 < uVar2) {
      uVar3 = *(int *)(this_00 + 0xc) + uVar4;
      if (*(uint *)(this_00 + 8) <= uVar3) {
        uVar3 = uVar3 - *(uint *)(this_00 + 8);
      }
      if (*(uint *)(*(int *)(this_00 + 4) + uVar3 * 8) <=
          *(uint *)(this + 0xc)) {
        uVar4 = *(int *)(this_00 + 0xc) + uVar4;
        if (*(uint *)(this_00 + 8) <= uVar4) {
          uVar4 = uVar4 - *(uint *)(this_00 + 8);
        }
        iVar1 = *(int *)(this_00 + 4);
        *(undefined4 *)param_1 = *(undefined4 *)(iVar1 + uVar4 * 8);
        Convert(*(CInputEventsStore **)this,
                (SInputEventsStoreElem *)(iVar1 + uVar4 * 8 + 4),
                (SInputEvent *)(param_1 + 4));
        return 1;
      }
    }
  }
  *(undefined4 *)(this + 4) = 0;
  return 0;
}

/* protected: void __thiscall CInputEventsStore::GetState(unsigned char,unsigned
   long,struct SMwTimedValueInstant<struct SInputEventsStoreElem> &,int)const */

void __thiscall CInputEventsStore::GetState(CInputEventsStore *this,
                                            uchar param_1, ulong param_2,
                                            SMwTimedValueInstant<> *param_3,
                                            int param_4)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint local_10;

  puVar2 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x38),
                                             (uint)param_1);
  local_10 = 0;
  if (*(uint *)this != 0) {
    iVar1 = *(int *)(this + 4);
    uVar5 = *(uint *)(this + 0xc);
    iVar4 = uVar5 * 8;
    do {
      iVar3 = iVar4;
      if (*(uint *)(this + 8) <= uVar5) {
        iVar3 = iVar4 + *(uint *)(this + 8) * -8;
      }
      if (((puVar2[1] <= param_2) && (*(uint *)(iVar3 + iVar1) <= *puVar2)) &&
          (*puVar2 != 0)) {
        *(uint *)param_3 = puVar2[1];
        *(uint *)(param_3 + 4) = puVar2[2];
        *puVar2 = param_2;
        return;
      }
      if ((*(uint *)(iVar3 + iVar1) <= param_2) &&
          (*(uchar *)(iVar3 + 7 + iVar1) == param_1)) {
        *(undefined4 *)param_3 = *(undefined4 *)(iVar3 + iVar1);
        *(undefined4 *)(param_3 + 4) = *(undefined4 *)(iVar3 + 4 + iVar1);
        if (param_4 != 0) {
          return;
        }
        *puVar2 = param_2;
        puVar2[1] = *(uint *)(iVar3 + iVar1);
        puVar2[2] = *(uint *)(iVar3 + 4 + iVar1);
        return;
      }
      local_10 = local_10 + 1;
      iVar4 = iVar4 + 8;
      uVar5 = uVar5 + 1;
    } while (local_10 < *(uint *)this);
  }
  if ((puVar2[1] <= param_2) && (*puVar2 != 0)) {
    *(uint *)param_3 = puVar2[1];
    *(uint *)(param_3 + 4) = puVar2[2];
    *puVar2 = param_2;
    return;
  }
  param_3[7] = (SMwTimedValueInstant<>)param_1;
  *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) & 0xff000000;
  *(undefined4 *)param_3 = 0;
  *puVar2 = param_2;
  puVar2[1] = *(uint *)param_3;
  puVar2[2] = *(uint *)(param_3 + 4);
  return;
}

/* public: void __thiscall CInputEventsStore::GetState(struct SInputActionDesc
   const *,unsigned long,struct SMwTimedValueInstant<struct SInputEvent> &)const
 */

void __thiscall CInputEventsStore::GetState(CInputEventsStore *this,
                                            SInputActionDesc *param_1,
                                            ulong param_2,
                                            SMwTimedValueInstant<> *param_3)

{
  int iVar1;
  undefined4 local_8;
  SInputEventsStoreElem local_4[4];

  iVar1 = CFastArray<>::Find((CFastArray<> *)(this + 0x20),
                             (CGameMenuFrame **)&param_1);
  if (iVar1 == -1) {
    *(undefined4 *)(param_3 + 8) = 0;
    *(undefined4 *)param_3 = 0;
    *(SInputActionDesc **)(param_3 + 4) = param_1;
    return;
  }
  GetState(this, (uchar)iVar1, param_2, (SMwTimedValueInstant<> *)&local_8, 0);
  *(undefined4 *)param_3 = local_8;
  Convert(this, local_4, (SInputEvent *)(param_3 + 4));
  return;
}

/* public: void __thiscall CInputEventsStore::GetState(struct SInputActionDesc
   const *,unsigned long,struct SInputEvent &)const  */

void __thiscall CInputEventsStore::GetState(CInputEventsStore *this,
                                            SInputActionDesc *param_1,
                                            ulong param_2, SInputEvent *param_3)

{
  SMwTimedValueInstant<> local_c[4];
  undefined4 local_8;
  undefined4 local_4;

  GetState(this, param_1, param_2, local_c);
  *(undefined4 *)param_3 = local_8;
  *(undefined4 *)(param_3 + 4) = local_4;
  return;
}

/* public: void __thiscall CInputEventsStore::GetStats(int &,float &,unsigned
   long &,unsigned long
   &)const  */

void __thiscall CInputEventsStore::GetStats(CInputEventsStore *this,
                                            int *param_1, float *param_2,
                                            ulong *param_3, ulong *param_4)

{
  int iVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint local_2c;
  uint local_28;
  uint local_20;
  int local_1c;
  int local_18;
  int *local_8[2];

  local_20 = 0;
  local_18 = 1;
  local_1c = 0;
  local_2c = 0;
  local_28 = 0;
  uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)this);
  uVar7 = 0;
  if (uVar5 != 0) {
    iVar6 = *(int *)(this + 0xc);
    iVar1 = *(int *)(this + 4);
    uVar2 = *(uint *)(this + 8);
    uVar9 = 0;
    do {
      uVar8 = (iVar6 - uVar7) + -1 + uVar5;
      if (uVar2 <= uVar8) {
        uVar8 = uVar8 - uVar2;
      }
      Convert(this, (SInputEventsStoreElem *)(iVar1 + 4 + uVar8 * 8),
              (SInputEvent *)local_8);
      if (*local_8[0] == 1) {
        local_20 = local_20 + 1;
      }
      if (uVar9 == 0) {
        uVar8 = *(uint *)(iVar1 + uVar8 * 8);
        local_2c = uVar8;
      LAB_008f672e:
        local_28 = uVar8;
      } else {
        uVar8 = *(uint *)(iVar1 + uVar8 * 8);
        if ((uVar9 < uVar8) && (uVar8 < uVar9 + 0x9c4)) {
          local_1c = local_1c + 1;
          local_18 = local_18 + (uVar8 - uVar9);
        }
        if (uVar8 < local_2c) {
          local_2c = uVar8;
        }
        if (local_28 < uVar8)
          goto LAB_008f672e;
      }
      uVar7 = uVar7 + 1;
      uVar9 = uVar8;
    } while (uVar7 < uVar5);
    if ((10 < local_20) && (uVar5 >> 2 < local_20)) {
      iVar6 = 1;
      goto LAB_008f6756;
    }
  }
  iVar6 = 0;
LAB_008f6756:
  fVar3 = (float)local_1c;
  *param_1 = iVar6;
  if (local_1c < 0) {
    fVar3 = fVar3 + 4.294967e+09;
  }
  fVar4 = (float)local_18;
  if (local_18 < 0) {
    fVar4 = fVar4 + 4.294967e+09;
  }
  *param_2 = (fVar3 * 1000.0) / fVar4;
  *param_3 = local_2c;
  *param_4 = local_28;
  return;
}

/* protected: void __thiscall CInputEventsStore::InsertSorted(struct
   SInputEventsStoreElem const
   &,unsigned long) */

void __thiscall CInputEventsStore::InsertSorted(CInputEventsStore *this,
                                                SInputEventsStoreElem *param_1,
                                                ulong param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  int iVar5;
  uint uVar6;
  uint local_8;
  undefined4 local_4;

  uVar6 = *(uint *)(this + 0x14);
  uVar4 = param_2;
  if ((uVar6 != 0) && (param_2 <= uVar6)) {
    uVar4 = uVar6;
  }
  puVar1 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x38),
                                             (uint)(byte)param_1[3]);
  if (uVar4 <= *puVar1) {
    if ((uVar4 < 2) || (uVar4 - 1 < puVar1[1])) {
      *puVar1 = 0;
    } else {
      *puVar1 = uVar4 - 1;
    }
  }
  iVar3 = *(int *)this;
  local_4 = *(undefined4 *)param_1;
  local_8 = uVar4;
  if ((iVar3 == 0) ||
      (puVar1 = (uint *)CFastBufferWheel<>::Head((CFastBufferWheel<> *)this),
       *puVar1 <= uVar4)) {
    UpdateCacheForOverwrittenValue(this);
    CFastBufferWheel<>::Push((CFastBufferWheel<> *)this, (GmVec2 *)&local_8);
    return;
  }
  param_2 = 0;
  uVar6 = 0;
  if (iVar3 != 0) {
    uVar2 = *(uint *)(this + 0xc);
    iVar3 = uVar2 * 8;
    do {
      iVar5 = iVar3;
      if (*(uint *)(this + 8) <= uVar2) {
        iVar5 = iVar3 + *(int *)(this + 8) * -8;
      }
      uVar6 = param_2;
      if (*(uint *)(iVar5 + *(int *)(this + 4)) <= uVar4)
        break;
      uVar6 = param_2 + 1;
      iVar3 = iVar3 + 8;
      uVar2 = uVar2 + 1;
      param_2 = uVar6;
    } while (uVar6 < *(uint *)this);
  }
  if ((*(uint *)(this + 0x10) != 0) && (*(uint *)(this + 0x10) <= uVar6)) {
    return;
  }
  UpdateCacheForOverwrittenValue(this);
  CFastBufferWheel<>::InsertFromStart((CFastBufferWheel<> *)this, uVar6,
                                      (SMwTimedValueInstant<> *)&local_8);
  return;
}

/* public: int __thiscall CInputEventsStore::InsertSorted(struct SInputEvent
 * const &,unsigned long)
 */

int __thiscall CInputEventsStore::InsertSorted(CInputEventsStore *this,
                                               SInputEvent *param_1,
                                               ulong param_2)

{
  int iVar1;

  iVar1 = Convert(this, param_1, (SInputEventsStoreElem *)&param_1);
  if (iVar1 == 0) {
    return 0;
  }
  InsertSorted(this, (SInputEventsStoreElem *)&param_1, param_2);
  return 1;
}

/* public: void __thiscall CInputEventsStore::Lock(unsigned long) */

void __thiscall CInputEventsStore::Lock(CInputEventsStore *this, ulong param_1)

{
  *(ulong *)(this + 0x14) = param_1;
  return;
}

/* public: void __thiscall CInputEventsStore::RegisterInput(struct
   SInputActionDesc const *,class CMwId const &) */

void __thiscall CInputEventsStore::RegisterInput(CInputEventsStore *this,
                                                 SInputActionDesc *param_1,
                                                 CMwId *param_2)

{
  ulong uVar1;
  SCachedValue *pSVar2;
  SInputActionDesc **ppSVar3;
  SCachedValue local_c[12];

  uVar1 = CFastArray<>::Find((CFastArray<> *)(this + 0x2c),
                             (CGameMenuFrame **)param_2);
  if (uVar1 == 0xffffffff) {
    uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x20));
    CFastBuffer<>::Add((CFastBuffer<> *)(CFastArray<> *)(this + 0x2c), param_2);
    param_2 = (CMwId *)0x0;
    CFastBuffer<>::Add((CFastBuffer<> *)(CFastBuffer<> *)(this + 0x20),
                       (CDx9TextureKeeper **)&param_2);
    pSVar2 = (SCachedValue *)SCachedValue::SCachedValue(local_c, uVar1);
    CFastBuffer<>::Add((CFastBuffer<> *)(this + 0x38), pSVar2);
  }
  if (param_1 != (SInputActionDesc *)0x0) {
    ppSVar3 = (SInputActionDesc **)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(this + 0x20), uVar1);
    *ppSVar3 = param_1;
  }
  return;
}

/* public: void __thiscall CInputEventsStore::ReInit(void) */

void __thiscall CInputEventsStore::ReInit(CInputEventsStore *this)

{
  *(undefined4 *)(this + 0x14) = 0;
  ClearStore(this);
  CFastBuffer<>::ResetAndFreeMemory((CFastBuffer<> *)(this + 0x20));
  CFastBuffer<>::ResetAndFreeMemory((CFastBuffer<> *)(this + 0x2c));
  CFastBuffer<>::ResetAndFreeMemory((CFastBuffer<> *)(this + 0x38));
  return;
}

/* public: __thiscall CInputEventsStore::SCachedValue::SCachedValue(unsigned
 * long) */

void __thiscall CInputEventsStore::SCachedValue::SCachedValue(
    SCachedValue *this, ulong param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(ulong *)(this + 8) = param_1 << 0x18;
  return;
}

/* public: class CInputEventsStore::CScanner __thiscall
   CInputEventsStore::Scan(unsigned long,unsigned long)const  */

CScanner *__thiscall CInputEventsStore::Scan(CInputEventsStore *this,
                                             CScanner *param_1, ulong param_2,
                                             ulong param_3)

{
  CScanner::CScanner(param_1, param_2, param_3, this);
  return param_1;
}

/* public: int __thiscall CInputEventsStore::SetState(struct SInputEvent const
 * &,unsigned long) */

int __thiscall CInputEventsStore::SetState(CInputEventsStore *this,
                                           SInputEvent *param_1, ulong param_2)

{
  SInputEvent *pSVar1;
  ulong uVar2;
  int iVar3;
  SMwTimedValueInstant<> local_8[4];
  uint local_4;

  iVar3 = Convert(this, param_1, (SInputEventsStoreElem *)&param_1);
  uVar2 = param_2;
  pSVar1 = param_1;
  if (iVar3 == 0) {
    return 0;
  }
  GetState(this, (uchar)((uint)param_1 >> 0x18), param_2, local_8, 1);
  if (((local_4 ^ (uint)pSVar1) & 0xffffff) != 0) {
    InsertSorted(this, (SInputEventsStoreElem *)&param_1, uVar2);
  }
  return 1;
}

/* private: void __thiscall
 * CInputEventsStore::UpdateCacheForOverwrittenValue(void) */

void __thiscall CInputEventsStore::UpdateCacheForOverwrittenValue(
    CInputEventsStore *this)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;

  if ((*(uint *)(this + 0x10) != 0) &&
      (*(uint *)(this + 0x10) <= *(uint *)this)) {
    puVar3 = (uint *)CFastBufferWheel<>::Tail((CFastBufferWheel<> *)this);
    uVar1 = puVar3[1];
    uVar2 = *puVar3;
    puVar3 = (uint *)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x38),
                                               uVar1 >> 0x18);
    if (*puVar3 < uVar2) {
      puVar3[1] = uVar2;
      puVar3[2] = uVar1;
      *puVar3 = uVar2;
    }
  }
  return;
}

/* public: __thiscall CInputEventsStore::~CInputEventsStore(void) */

void __thiscall CInputEventsStore::~CInputEventsStore(CInputEventsStore *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00a84cd3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 1;
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x38));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x2c));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x20));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)this);
  ExceptionList = local_c;
  return;
}

/* public: void __thiscall CInputEventsStore::ClearStore(void) */

void __thiscall CInputEventsStore::ClearStore(CInputEventsStore *this)

{
  ulong uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  ulong uVar4;
  SCachedValue local_c[12];

  CFastBufferWheel<>::ClearWheel((CFastBufferWheel<> *)this);
  *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x20));
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      puVar2 = (undefined4 *)SCachedValue::SCachedValue(local_c, uVar4);
      puVar3 = (undefined4 *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(this + 0x38), uVar4);
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[1];
      uVar4 = uVar4 + 1;
      puVar3[2] = puVar2[2];
    } while (uVar4 < uVar1);
  }
  Lock(this, 0);
  return;
}
