// Class implementation: CFastBuffer_struct_CFastBufferKey_struct_CGameCtnMediaBlockCameraOrbital_SKeyVal_SKey

// =================================================
// Function: AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraOrbital::SKeyVal>::SKey>::
AddNewElem(void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(iVar1 * 0x30 + *(int *)((int)this + 4));
}
}

