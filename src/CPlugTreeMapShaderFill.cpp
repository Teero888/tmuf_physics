// Class implementation: CPlugTreeMapShaderFill

// =================================================
// Function: CPlugTreeMapShaderFill::GetTreeShaderFill
// =================================================
SFillValue * __cdecl CPlugTreeMapShaderFill::GetTreeShaderFill(CPlugTree *param_1)
{
{
  CFastString CVar1;
  undefined3 extraout_var;
  uint local_4;
  
  CVar1 = CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue>::GetElem
                    ((CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> *)&DAT_00d6f618,
                     (CVirtualisedBuffer<class_CFastString> *)param_1,(ulong)&local_4);
  return (SFillValue *)(-(uint)(CONCAT31(extraout_var,CVar1) != 0) & local_4);
}
}

// =================================================
// Function: CPlugTreeMapShaderFill::SubTree
// =================================================
void __cdecl CPlugTreeMapShaderFill::SubTree(CPlugTree *param_1)
{
{
  SFillValue *pSVar1;
  uint *unaff_ESI;
  
  pSVar1 = GetTreeShaderFill(param_1);
  if (pSVar1 != (SFillValue *)0x0) {
    if (DAT_00d6f614 != (undefined4 *)0x0) {
      (**(code **)*DAT_00d6f614)(pSVar1);
    }
    CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue>::RemoveIfFound
              ((CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> *)&DAT_00d6f618,
               (CFastBuffer<unsigned_int> *)param_1,unaff_ESI);
  }
  return;
}
}

