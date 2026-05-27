// Class implementation: CFuncCurvesReal

// =================================================
// Function: CFuncCurvesReal::GetValue
// =================================================
GmVec3 __thiscall
CFuncCurvesReal::GetValue(CFuncCurvesReal *this,CFuncColorGradient *param_1,float param_2)
{
{
  GmVec3 GVar1;
  int iVar2;
  SCasterCat *pSVar3;
  CFuncColorGradient *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> **ppCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> **ppCStack_20;
  undefined1 *puStack_1c;
  undefined4 uStack_18;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_10;
  ulong uStack_c;
  undefined1 local_4 [4];
  
  uStack_18 = 1;
  puStack_1c = local_4;
  ppCStack_20 = &local_10;
  iVar2 = (**(code **)(*(int *)(this + 0x18) + 0x18))(param_1);
  if (iVar2 != 0) {
    ppCVar5 = &local_10;
    pCVar4 = (CFuncColorGradient *)&puStack_1c;
    pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this + 0x1c,local_10,uStack_c);
    CFuncKeysReal::GetValue(*(CFuncKeysReal **)(pSVar3 + 4),pCVar4,(float)ppCVar5);
    ppCVar5 = &local_10;
    pCVar4 = (CFuncColorGradient *)&ppCStack_20;
    pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                       (this + 0x1c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&param_1,
                        uStack_c);
    GVar1 = CFuncKeysReal::GetValue(*(CFuncKeysReal **)(pSVar3 + 4),pCVar4,(float)ppCVar5);
    return GVar1;
  }
  return (GmVec3)0x0;
}
}

