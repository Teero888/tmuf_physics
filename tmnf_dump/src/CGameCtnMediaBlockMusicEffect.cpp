// Class implementation: CGameCtnMediaBlockMusicEffect

// =================================================
// Function: CGameCtnMediaBlockMusicEffect::GetValue
// =================================================
GmVec3 __thiscall
CGameCtnMediaBlockMusicEffect::GetValue
          (CGameCtnMediaBlockMusicEffect *this,CFuncColorGradient *param_1,float param_2)
{
{
  int iVar1;
  SCasterCat *pSVar2;
  SCasterCat *pSVar3;
  float unaff_ESI;
  ulong unaff_EDI;
  CFuncColorGradient *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  undefined4 *local_c;
  float local_8;
  float *pfStack_4;
  
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&param_1;
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&local_c;
  local_c = (undefined4 *)0x0;
  local_8 = 0.0;
  pCVar4 = param_1;
  iVar1 = (**(code **)(*(int *)(this + 0x24) + 0x18))(param_1,pCVar5,&local_8,pCVar6,1);
  if (iVar1 == 0) {
    *local_c = 0x3f800000;
    local_c[1] = 0x3f800000;
    return SUB41(local_c,0);
  }
  if ((0.0 <= unaff_ESI) && (unaff_ESI <= 1.0)) {
    pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (this + 0x28,pCVar5,unaff_EDI);
    pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (this + 0x28,pCVar6,(ulong)pCVar4);
    *pfStack_4 = local_8 * (*(float *)(pSVar3 + 4) - *(float *)(pSVar2 + 4)) +
                 *(float *)(pSVar2 + 4);
    pfStack_4[1] = *(float *)(pSVar2 + 8) +
                   (*(float *)(pSVar3 + 8) - *(float *)(pSVar2 + 8)) * local_8;
    return (GmVec3)((char)pSVar3 + '\x04');
  }
  return (GmVec3)0x0;
}
}

