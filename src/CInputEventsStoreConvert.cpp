
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
