// Class implementation: CFastBuffer_int

// =================================================
// Function: CFastBuffer<int>::FillWith
// =================================================
void __thiscall
CFastBuffer<int>::FillWith
          (void *this,CFixedArray<unsigned_char,8,unsigned_long> *param_1,uchar *param_2)
{
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)this;
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      *(undefined4 *)(*(int *)((int)this + 4) + uVar2 * 4) = *(undefined4 *)param_1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}
}

// =================================================
// Function: CFastBuffer<int>::FindAfter
// =================================================
ulong __thiscall
CFastBuffer<int>::FindAfter(void *this,CFastBuffer<int> *param_1,int *param_2,ulong param_3)
{
{
  uint uVar1;
  int *piVar2;
  
  uVar1 = (int)param_2 + 1;
  if (uVar1 < *(uint *)this) {
    piVar2 = (int *)(*(int *)((int)this + 4) + uVar1 * 4);
    do {
      if (*piVar2 == *(int *)param_1) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (uVar1 < *(uint *)this);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CFastBuffer<int>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<int>::SetSizeAtLeast
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
    pvVar1 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 4 >> 0x20) != 0) |
                            (uint)(ZEXT48(param_1) * 4));
    uVar2 = 0;
    if (*(int *)this != 0) {
      do {
        *(undefined4 *)((int)pvVar1 + uVar2 * 4) =
             *(undefined4 *)(*(int *)((int)this + 4) + uVar2 * 4);
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

