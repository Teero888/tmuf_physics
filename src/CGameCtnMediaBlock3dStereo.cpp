// Class implementation: CGameCtnMediaBlock3dStereo

// =================================================
// Function: CGameCtnMediaBlock3dStereo::GetValue
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

GmVec3 __thiscall
CGameCtnMediaBlock3dStereo::GetValue
          (CGameCtnMediaBlock3dStereo *this,CFuncColorGradient *param_1,float param_2)
{
{
  GmVec3 extraout_AL;
  int iVar1;
  SCasterCat *pSVar2;
  SCasterCat *pSVar3;
  void *unaff_ESI;
  ulong unaff_EDI;
  CFuncColorGradient *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  float *local_8;
  float *local_4;
  
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&param_1;
  local_8 = *(float **)(this + 0x34);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&local_8;
  pCVar4 = param_1;
  local_4 = local_8;
  iVar1 = (**(code **)(*(int *)(this + 0x24) + 0x18))(param_1,pCVar5,&local_4,pCVar6,1);
  if (iVar1 != 0) {
    __CIcos();
    pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (this + 0x28,pCVar5,unaff_EDI);
    pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (this + 0x28,pCVar6,(ulong)pCVar4);
    *local_4 = *(float *)(pSVar2 + 4) * (1.0 - (float)local_8) +
               (float)local_8 * *(float *)(pSVar3 + 4);
    local_4[1] = (1.0 - (float)local_8) * *(float *)(pSVar2 + 8) +
                 *(float *)(pSVar3 + 8) * (float)local_8;
    return SUB41(pSVar3 + 4,0);
  }
  SKeyVal::Reset(unaff_ESI,(GmFrustumIso4 *)pCVar4);
  return extraout_AL;
}
}

