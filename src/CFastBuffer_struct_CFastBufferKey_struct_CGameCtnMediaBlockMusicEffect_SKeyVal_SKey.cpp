// Class implementation: CFastBuffer_struct_CFastBufferKey_struct_CGameCtnMediaBlockMusicEffect_SKeyVal_SKey

// =================================================
// Function: InsertNewElemAt
// =================================================
SBitmapSpecular * __thiscall
CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal>::SKey>::
InsertNewElemAt(void *this,CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *param_1,
               ulong param_2)
{
{
  int iVar1;
  int iVar2;
  int iVar3;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  iVar1 = iVar1 + -1;
  if ((int)param_2 <= iVar1) {
    iVar3 = iVar1 * 0xc;
    iVar1 = (iVar1 - param_2) + 1;
    do {
      iVar2 = *(int *)((int)this + 4) + iVar3;
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)((int)this + 4) + iVar3);
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar2 + 4);
      iVar3 = iVar3 + -0xc;
      iVar1 = iVar1 + -1;
      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar2 + 8);
    } while (iVar1 != 0);
  }
  return (SBitmapSpecular *)(*(int *)((int)this + 4) + param_2 * 0xc);
}
}

