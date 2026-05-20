// Class implementation: CFuncCurves2Real

// =================================================
// Function: CFuncCurves2Real::GetValue
// =================================================
GmVec3 __thiscall
CFuncCurves2Real::GetValue(CFuncCurves2Real *this,CFuncColorGradient *param_1,float param_2)
{
{
  GmVec3 GVar1;
  int iVar2;
  SCasterCat *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  float unaff_retaddr;
  CFuncColorGradient *pCVar4;
  CFuncColorGradient **ppCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> local_c [4];
  CFuncColorGradient *pCStack_8;
  CFuncColorGradient *local_4;
  
  ppCVar5 = &param_1;
  pCVar4 = param_1;
  iVar2 = (**(code **)(*(int *)(this + 0x18) + 0x18))();
  if (iVar2 != 0) {
    pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this + 0x1c,unaff_ESI,(ulong)pCVar4);
    CFuncCurvesReal::GetValue(*(CFuncCurvesReal **)(pSVar3 + 4),pCStack_8,(float)local_4);
    pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this + 0x1c,local_c,(ulong)ppCVar5);
    GVar1 = CFuncCurvesReal::GetValue(*(CFuncCurvesReal **)(pSVar3 + 4),local_4,unaff_retaddr);
    return GVar1;
  }
  return (GmVec3)0x0;
}
}

