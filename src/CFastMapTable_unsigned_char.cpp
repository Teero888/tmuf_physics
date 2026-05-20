// Class implementation: CFastMapTable_unsigned_char

// =================================================
// Function: CFastMapTable<unsigned_char>::ClearAndShrink
// =================================================
void __thiscall
CFastMapTable<unsigned_char>::ClearAndShrink
          (CFastMapTable<unsigned_char> *this,CFastMapTable<unsigned_char> *param_1,ulong param_2)
{
{
  ulong uVar1;
  void *pvVar2;
  uint uVar3;
  
  if ((param_1 != (CFastMapTable<unsigned_char> *)0xffffffff) &&
     (uVar1 = CFastAlgo::ComputeHashSize((ulong)param_1), uVar1 < *(uint *)(this + 0xc))) {
    operator_delete__(*(void **)(this + 4));
    *(ulong *)(this + 0xc) = uVar1;
    pvVar2 = operator_new__(-(uint)((int)((ulonglong)uVar1 * 8 >> 0x20) != 0) |
                            (uint)((ulonglong)uVar1 * 8));
    *(void **)(this + 4) = pvVar2;
  }
  uVar3 = 0;
  if (*(int *)(this + 0xc) != 0) {
    do {
      *(undefined4 *)(*(int *)(this + 4) + uVar3 * 8) = 0xffffffff;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(this + 0xc));
  }
  *(undefined4 *)(this + 8) = 0;
  return;
}
}

