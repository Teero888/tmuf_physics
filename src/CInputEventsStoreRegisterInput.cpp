
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
