// Class implementation: CGameCtnMediaBlockTime

// =================================================
// Function: CGameCtnMediaBlockTime::GetValue
// =================================================
GmVec3 __thiscall
CGameCtnMediaBlockTime::GetValue
          (CGameCtnMediaBlockTime *this,CFuncColorGradient *param_1,float param_2)
{
{
  float fVar1;
  float fVar2;
  int iVar3;
  SCasterCat *pSVar4;
  CFuncColorGradient *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  undefined4 *local_10;
  undefined4 *local_c;
  float fStack_8;
  float *pfStack_4;
  
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&param_1;
  local_10 = *(undefined4 **)(this + 0x54);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&local_10;
  pCVar5 = param_1;
  local_c = local_10;
  iVar3 = (**(code **)(*(int *)(this + 0x24) + 0x18))(param_1,pCVar6,&local_c,pCVar7,1);
  if (iVar3 == 0) {
    *local_c = 0;
    local_c[1] = 0;
    return SUB41(local_c,0);
  }
  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x54) = pCVar6;
  if ((0.0 <= (float)local_10) && ((float)local_10 <= 1.0)) {
    pSVar4 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (this + 0x28,pCVar6,(ulong)pCVar5);
    fVar1 = *(float *)(pSVar4 + 4);
    fVar2 = 1.0 - (float)local_c;
    pSVar4 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (this + 0x28,pCVar7,(ulong)pCVar6);
    *pfStack_4 = *(float *)(pSVar4 + 4) * fStack_8 +
                 (float)(double)CONCAT44(local_10,(int)((ulonglong)(double)(fVar2 * fVar1) >> 0x20))
    ;
    pfStack_4[1] = 0.0;
    return SUB41(pfStack_4,0);
  }
  return (GmVec3)0x0;
}
}

