// Class implementation: CFastBuffer_struct_CAudioPort_SAutoBalancedSound

// =================================================
// Function: CFastBuffer<struct_CAudioPort::SAutoBalancedSound>::InsertElemAt
// =================================================
void __thiscall
CFastBuffer<struct_CAudioPort::SAutoBalancedSound>::InsertElemAt
          (void *this,CFastBuffer<struct_CInputDevice::SRumble> *param_1,ulong param_2,
          SRumble *param_3)
{
{
  SBitmapSpecular *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = InsertNewElemAt(this,(CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *)param_1,
                           unaff_retaddr);
  *(undefined4 *)pSVar1 = *(undefined4 *)param_3;
  *(undefined4 *)(pSVar1 + 4) = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)(pSVar1 + 8) = *(undefined4 *)(param_3 + 8);
  *(undefined4 *)(pSVar1 + 0xc) = *(undefined4 *)(param_3 + 0xc);
  return;
}
}

