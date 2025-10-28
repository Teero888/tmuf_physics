
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
