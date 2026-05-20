// Class implementation: CFastBufferCat_struct_SHmsItem_CallbackSortCustom_Elem_struct_SFastCat

// =================================================
// Function: struct_SFastCat>::ChangeCatAt
// =================================================
/* WARNING: Control flow encountered bad instruction data */

ulong __thiscall
CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat>::ChangeCatAt
          (void *this,
          CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> *param_1,
          ulong param_2,ulong param_3,ulong param_4)
{
{
  uint in_EAX;
  byte *extraout_ECX;
  undefined2 extraout_DX;
  int unaff_EBX;
  uint unaff_ESI;
  int *piVar1;
  uint *unaff_EDI;
  undefined2 in_CS;
  bool in_ZF;
  byte *pbStack_4;
  
  if (in_ZF) {
    *(uint **)this = unaff_EDI;
    pbStack_4 = (byte *)CONCAT22(pbStack_4._2_2_,in_CS);
    func_0xe539c239();
    *pbStack_4 = *pbStack_4 + (byte)in_CS;
    *pbStack_4 = *pbStack_4 ^ (byte)in_CS;
    *(uint *)(extraout_ECX + unaff_ESI) = *(uint *)(extraout_ECX + unaff_ESI) ^ (uint)pbStack_4;
    *extraout_ECX = *extraout_ECX | (byte)((ushort)extraout_DX >> 8) ^ (byte)extraout_DX;
    return (ulong)pbStack_4;
  }
  piVar1 = (int *)(unaff_ESI & *(uint *)(unaff_EBX + unaff_ESI * 2));
  *unaff_EDI = in_EAX ^ 0x359935e6;
  *piVar1 = *piVar1 + (int)piVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: struct_SFastCat>::GetElemInCat
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

SSamplerState * __thiscall
CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat>::GetElemInCat
          (void *this,
          CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
          *param_1,ulong param_2,ulong param_3)
{
{
  undefined4 in_EAX;
  uint unaff_ESI;
  undefined1 *unaff_EDI;
  
  _DAT_356c351b = _DAT_356c351b | unaff_ESI;
  *unaff_EDI = 0x34;
  return (SSamplerState *)(CONCAT31((int3)((uint)in_EAX >> 8),0x34) ^ 0x36ef3661 | 0x79382237);
}
}

