// Class implementation: CFastMapTable_unsigned_long

// =================================================
// Function: CFastMapTable<unsigned_long>::Add
// =================================================
void __thiscall
CFastMapTable<unsigned_long>::Add
          (CFastMapTable<unsigned_long> *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  if ((uint)(*(int *)(this + 0xc) * 3) <= (uint)(*(int *)(this + 8) * 4)) {
    Resize(this,(CVisionViewportDx9 *)(*(int *)(this + 8) * 2 + 2));
  }
  uVar1 = *(uint *)(this + 0xc);
  uVar4 = (uint)param_2 % uVar1;
  iVar2 = *(int *)(this + 4);
  if (*(int *)(iVar2 + uVar4 * 8) != -1) {
    piVar3 = (int *)(iVar2 + uVar4 * 8);
    do {
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 2;
      if (uVar1 <= uVar4) {
        uVar4 = uVar4 - uVar1;
        piVar3 = piVar3 + uVar1 * -2;
      }
    } while (*piVar3 != -1);
  }
  *(TiXmlAttribute **)(iVar2 + uVar4 * 8) = param_2;
  *(undefined4 *)(*(int *)(this + 4) + 4 + uVar4 * 8) = *(undefined4 *)param_1;
  *(int *)(this + 8) = *(int *)(this + 8) + 1;
  return;
}
}

// =================================================
// Function: CFastMapTable<unsigned_long>::CFastMapTable<unsigned_long>
// =================================================
void __thiscall
CFastMapTable<unsigned_long>::CFastMapTable<unsigned_long>
          (CFastMapTable<unsigned_long> *this,CFastMapTable<unsigned_long> *param_1,ulong param_2)
{
{
  ulong uVar1;
  void *pvVar2;
  TiXmlNode *unaff_ESI;
  
  *(undefined ***)this = vftable;
  uVar1 = CFastAlgo::ComputeHashSize((ulong)param_1);
  *(ulong *)(this + 0xc) = uVar1;
  pvVar2 = operator_new__(-(uint)((int)((ulonglong)uVar1 * 8 >> 0x20) != 0) |
                          (uint)((ulonglong)uVar1 * 8));
  *(void **)(this + 4) = pvVar2;
  Clear(this,unaff_ESI);
  return;
}
}

// =================================================
// Function: CFastMapTable<unsigned_long>::Clear
// =================================================
void __thiscall
CFastMapTable<unsigned_long>::Clear(CFastMapTable<unsigned_long> *this,TiXmlNode *param_1)
{
{
  ulong unaff_retaddr;
  
  CFastMapTable<unsigned_char>::ClearAndShrink
            ((CFastMapTable<unsigned_char> *)this,(CFastMapTable<unsigned_char> *)0xffffffff,
             unaff_retaddr);
  return;
}
}

// =================================================
// Function: CFastMapTable<unsigned_long>::GetElem
// =================================================
CFastString __thiscall
CFastMapTable<unsigned_long>::GetElem
          (CFastMapTable<unsigned_long> *this,CVirtualisedBuffer<class_CFastString> *param_1,
          ulong param_2)
{
{
  ulong uVar1;
  SLocationAlloc *unaff_ESI;
  undefined4 *in_stack_0000000c;
  
  uVar1 = GetIndex(this,(SStackLocation *)param_1,unaff_ESI);
  if (uVar1 < *(uint *)(this + 0xc)) {
    *in_stack_0000000c = *(undefined4 *)(*(int *)(this + 4) + 4 + uVar1 * 8);
    return (CFastString)0x1;
  }
  return (CFastString)0x0;
}
}

// =================================================
// Function: CFastMapTable<unsigned_long>::GetIndex
// =================================================
ulong __thiscall
CFastMapTable<unsigned_long>::GetIndex
          (CFastMapTable<unsigned_long> *this,SStackLocation *param_1,SLocationAlloc *param_2)
{
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  if (*(int *)(this + 8) == 0) {
    return 0xffffffff;
  }
  uVar1 = *(uint *)(this + 0xc);
  uVar4 = (uint)param_1 % uVar1;
  iVar2 = *(int *)(*(int *)(this + 4) + uVar4 * 8);
  piVar3 = (int *)(*(int *)(this + 4) + uVar4 * 8);
  while( true ) {
    if (iVar2 == -1) {
      return 0xffffffff;
    }
    if ((SStackLocation *)*piVar3 == param_1) break;
    uVar4 = uVar4 + 1;
    piVar3 = piVar3 + 2;
    if (uVar1 <= uVar4) {
      uVar4 = uVar4 - uVar1;
      piVar3 = piVar3 + uVar1 * -2;
    }
    iVar2 = *piVar3;
  }
  return uVar4;
}
}

// =================================================
// Function: CFastMapTable<unsigned_long>::IsPresent
// =================================================
int __thiscall
CFastMapTable<unsigned_long>::IsPresent
          (CFastMapTable<unsigned_long> *this,CFastMapTable<unsigned_long> *param_1,ulong param_2)
{
{
  ulong uVar1;
  SLocationAlloc *unaff_ESI;
  
  uVar1 = GetIndex(this,(SStackLocation *)param_1,unaff_ESI);
  return (uint)(uVar1 < *(uint *)(this + 0xc));
}
}

// =================================================
// Function: CFastMapTable<unsigned_long>::RemoveIfFound
// =================================================
void __thiscall
CFastMapTable<unsigned_long>::RemoveIfFound
          (CFastMapTable<unsigned_long> *this,CFastBuffer<unsigned_int> *param_1,uint *param_2)
{
{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  TiXmlAttribute *pTVar4;
  ulong uVar5;
  SLocationAlloc *unaff_EDI;
  
  uVar5 = GetIndex(this,(SStackLocation *)param_1,unaff_EDI);
  if (uVar5 < *(uint *)(this + 0xc)) {
    *(undefined4 *)(*(int *)(this + 4) + uVar5 * 8) = 0xffffffff;
    *(int *)(this + 8) = *(int *)(this + 8) + -1;
    while( true ) {
      uVar2 = *(uint *)(this + 0xc);
      uVar5 = uVar5 + 1;
      if (uVar2 <= uVar5) {
        uVar5 = uVar5 - uVar2;
      }
      uVar3 = *(uint *)(*(int *)(this + 4) + uVar5 * 8);
      puVar1 = (undefined4 *)(*(int *)(this + 4) + uVar5 * 8);
      if (uVar3 == 0xffffffff) break;
      if (uVar3 % uVar2 != uVar5) {
        param_2 = (uint *)puVar1[1];
        pTVar4 = (TiXmlAttribute *)*puVar1;
        *puVar1 = 0xffffffff;
        *(int *)(this + 8) = *(int *)(this + 8) + -1;
        Add(this,(TiXmlAttributeSet *)&param_2,pTVar4);
      }
    }
  }
  return;
}
}

// =================================================
// Function: CFastMapTable<unsigned_long>::Resize
// =================================================
int __thiscall
CFastMapTable<unsigned_long>::Resize(CFastMapTable<unsigned_long> *this,CVisionViewportDx9 *param_1)
{
{
  CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> *pCVar1;
  int extraout_EAX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong in_stack_0000000c;
  CFastMapTable<unsigned_long> *in_stack_ffffffe4;
  CFastMapTable<unsigned_long> local_14 [4];
  CFastMapTable<unsigned_long> local_10 [4];
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a82cc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastMapTable<unsigned_long>
            ((CFastMapTable<unsigned_long> *)&stack0xffffffe4,
             (CFastMapTable<unsigned_long> *)(DAT_00cca150 ^ (uint)&stack0xffffffdc),unaff_EDI);
  pCVar1 = (CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> *)
           CFastAlgo::ComputeHashSize(in_stack_0000000c);
  SetFastMapTable(local_14,(CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> *)this,pCVar1,
                  unaff_ESI);
  operator_delete__(*(void **)(this + 4));
  *(undefined4 *)(this + 0xc) = local_4;
  *(void **)(this + 4) = local_c;
  local_c = (void *)0x0;
  local_8 = (undefined1 *)0x0;
  local_4 = 0;
  ~CFastMapTable<unsigned_long>(local_10,in_stack_ffffffe4);
  ExceptionList = (void *)0x0;
  return extraout_EAX;
}
}

