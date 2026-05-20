// Class implementation: public_void_thiscall_CGameOutlineBox

// =================================================
// Function: ::__l35::SLocal::IsFilledCoord
// =================================================
int __cdecl
`public:_void___thiscall_CGameOutlineBox::
UpdateBox(class_CFastBuffer<int>_const&,class_GmNat3_const&)'::__l35::SLocal::IsFilledCoord
          (GmNat3 *param_1,GmNat3 *param_2,CFastBuffer<int> *param_3)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (param_3,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                              ((*(int *)(param_2 + 4) * *(int *)param_1 + *(int *)(param_1 + 4)) *
                               *(int *)(param_2 + 8) + *(int *)(param_1 + 8)),unaff_retaddr);
  return *(int *)pSVar1;
}
}

// =================================================
// Function: ::__l35::SLocal::IsValidCoord
// =================================================
int __cdecl
`public:_void___thiscall_CGameOutlineBox::
UpdateBox(class_CFastBuffer<int>_const&,class_GmNat3_const&)'::__l35::SLocal::IsValidCoord
          (GmNat3 *param_1,GmNat3 *param_2)
{
{
  if (((*(uint *)param_1 < *(uint *)param_2) && (*(uint *)(param_1 + 4) < *(uint *)(param_2 + 4)))
     && (*(uint *)(param_1 + 8) < *(uint *)(param_2 + 8))) {
    return 1;
  }
  return 0;
}
}

