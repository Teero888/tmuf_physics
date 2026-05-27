// Class implementation: CFastBufferKey_struct_CGameCtnMediaBlockCameraPath_SKeyVal

// =================================================
// Function: CFastBufferKey<struct_CGameCtnMediaBlockCameraPath::SKeyVal>::SetVal
// =================================================
void __thiscall
CFastBufferKey<struct_CGameCtnMediaBlockCameraPath::SKeyVal>::SetVal
          (CFastBufferKey<struct_CGameCtnMediaBlockCameraPath::SKeyVal> *this,
          CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> *param_1,ulong param_2,
          SKeyVal *param_3)
{
{
  SCasterCat *pSVar1;
  int iVar2;
  ulong unaff_EDI;
  
  pSVar1 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraPath::SKeyVal>::SKey>::
           operator[](this + 4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_EDI);
  for (iVar2 = 0x13; pSVar1 = pSVar1 + 4, iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pSVar1 = *(undefined4 *)param_3;
    param_3 = param_3 + 4;
  }
  return;
}
}

