// Class implementation: CFastBuffer_struct_CInputDevice_SRumble

// =================================================
// Function: CFastBuffer<struct_CInputDevice::SRumble>::InsertElemAt
// =================================================
void __thiscall
CFastBuffer<struct_CInputDevice::SRumble>::InsertElemAt
          (void *this,CFastBuffer<struct_CInputDevice::SRumble> *param_1,ulong param_2,
          SRumble *param_3)
{
{
  SBitmapSpecular *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlock3dStereo::SKeyVal>::SKey>::
           InsertNewElemAt(this,(CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *)param_1,
                           unaff_retaddr);
  *(undefined4 *)pSVar1 = *(undefined4 *)param_3;
  *(undefined4 *)(pSVar1 + 4) = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)(pSVar1 + 8) = *(undefined4 *)(param_3 + 8);
  return;
}
}

