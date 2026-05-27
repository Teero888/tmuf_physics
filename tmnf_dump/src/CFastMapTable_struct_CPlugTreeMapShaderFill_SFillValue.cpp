// Class implementation: CFastMapTable_struct_CPlugTreeMapShaderFill_SFillValue

// =================================================
// Function: CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue>::GetElem
// =================================================
CFastString __thiscall
CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue>::GetElem
          (CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> *this,
          CVirtualisedBuffer<class_CFastString> *param_1,ulong param_2)
{
{
  ulong uVar1;
  SLocationAlloc *unaff_ESI;
  int *in_stack_0000000c;
  
  uVar1 = GetIndex(this,(SStackLocation *)param_1,unaff_ESI);
  if (uVar1 < *(uint *)(this + 0xc)) {
    *in_stack_0000000c = uVar1 * 0x10 + 4 + *(int *)(this + 4);
    return (CFastString)0x1;
  }
  return (CFastString)0x0;
}
}

// =================================================
// Function: CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue>::RemoveIfFound
// =================================================
void __thiscall
CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue>::RemoveIfFound
          (CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> *this,
          CFastBuffer<unsigned_int> *param_1,uint *param_2)
{
{
  uint uVar1;
  TiXmlAttribute *pTVar2;
  ulong uVar3;
  uint *puVar4;
  SLocationAlloc *unaff_EDI;
  uint local_8;
  uint local_4;
  
  uVar3 = GetIndex(this,(SStackLocation *)param_1,unaff_EDI);
  if (uVar3 < *(uint *)(this + 0xc)) {
    *(undefined4 *)(uVar3 * 0x10 + *(int *)(this + 4)) = 0xffffffff;
    *(int *)(this + 8) = *(int *)(this + 8) + -1;
    while( true ) {
      uVar1 = *(uint *)(this + 0xc);
      uVar3 = uVar3 + 1;
      if (uVar1 <= uVar3) {
        uVar3 = uVar3 - uVar1;
      }
      puVar4 = (uint *)(*(int *)(this + 4) + uVar3 * 0x10);
      if (*puVar4 == 0xffffffff) break;
      if (*puVar4 % uVar1 != uVar3) {
        local_4 = puVar4[2];
        local_8 = puVar4[1];
        pTVar2 = (TiXmlAttribute *)*puVar4;
        *puVar4 = 0xffffffff;
        *(int *)(this + 8) = *(int *)(this + 8) + -1;
        Add(this,(TiXmlAttributeSet *)&local_8,pTVar2);
      }
    }
  }
  return;
}
}

