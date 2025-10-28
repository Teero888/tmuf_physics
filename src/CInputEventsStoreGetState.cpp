
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
