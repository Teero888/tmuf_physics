// Class implementation: CGameCtnMediaBlockTransitionFade

// =================================================
// Function: CGameCtnMediaBlockTransitionFade::GetValue
// =================================================
GmVec3 __thiscall
CGameCtnMediaBlockTransitionFade::GetValue
          (CGameCtnMediaBlockTransitionFade *this,CFuncColorGradient *param_1,float param_2)
{
{
  float fVar1;
  float fVar2;
  SCasterCat *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFuncColorGradient *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  float local_10;
  float local_c;
  undefined4 *puStack_8;
  float *pfStack_4;
  
  local_10 = *(float *)(this + 0x4c);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&local_10;
  pCVar5 = param_1;
  local_c = local_10;
  (**(code **)(*(int *)(this + 0x24) + 0x18))();
  pCVar4 = pCVar6;
  if ((local_10 < 0.0 == (local_10 == 0.0)) &&
     (pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&local_c,
     NAN(local_10) || 1.0 < local_10 == (local_10 == 1.0))) {
    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x4c) = pCVar6;
    pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this + 0x28,pCVar6,(ulong)pCVar5);
    fVar1 = *(float *)(pSVar3 + 4);
    fVar2 = 1.0 - local_c;
    pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                       (this + 0x28,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&param_1,
                        (ulong)pCVar6);
    *pfStack_4 = *(float *)(pSVar3 + 4) * (float)puStack_8 +
                 (float)(double)CONCAT44(local_10,(int)((ulonglong)(double)(fVar2 * fVar1) >> 0x20))
    ;
    return SUB41(pSVar3,0);
  }
  pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this + 0x28,pCVar4,(ulong)pCVar5);
  *puStack_8 = *(undefined4 *)(pSVar3 + 4);
  return SUB41(puStack_8,0);
}
}

