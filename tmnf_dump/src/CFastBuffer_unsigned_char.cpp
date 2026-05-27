// Class implementation: CFastBuffer_unsigned_char

// =================================================
// Function: CFastBuffer<unsigned_char>::RemoveAt
// =================================================
void __thiscall
CFastBuffer<unsigned_char>::RemoveAt
          (void *this,CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *param_1,
          ulong param_2,ulong param_3)
{
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = *(int *)this;
  uVar2 = 0;
  if (iVar1 - (int)param_1 != param_2) {
    do {
      iVar3 = *(int *)((int)this + 4) + uVar2;
      uVar2 = uVar2 + 1;
      param_1[iVar3] = (param_1 + iVar3)[param_2];
    } while (uVar2 < (iVar1 - (int)param_1) - param_2);
  }
  *(ulong *)this = *(int *)this - param_2;
  return;
}
}

// =================================================
// Function: CFastBuffer<unsigned_char>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<unsigned_char>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = *(uint *)((int)this + 8);
  if (0 < (int)((int)param_1 - uVar2)) {
    if ((int)((int)param_1 - uVar2) <= (int)(uVar2 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar2 >> 1) + uVar2);
    }
    pvVar1 = operator_new__((uint)param_1);
    uVar2 = 0;
    if (*(int *)this != 0) {
      do {
        *(undefined1 *)(uVar2 + (int)pvVar1) = *(undefined1 *)(uVar2 + *(int *)((int)this + 4));
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)this);
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    operator_delete__(*(void **)((int)this + 4));
    *(void **)((int)this + 4) = pvVar1;
  }
  return;
}
}

