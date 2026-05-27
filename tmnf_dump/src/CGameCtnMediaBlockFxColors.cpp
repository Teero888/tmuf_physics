// Class implementation: CGameCtnMediaBlockFxColors

// =================================================
// Function: CGameCtnMediaBlockFxColors::GetValue
// =================================================
GmVec3 __thiscall
CGameCtnMediaBlockFxColors::GetValue
          (CGameCtnMediaBlockFxColors *this,CFuncColorGradient *param_1,float param_2)
{
{
  float *this_00;
  SParam *pSVar1;
  SParam *pSVar2;
  GmVec3 extraout_AL;
  GmVec3 extraout_AL_00;
  int iVar3;
  SCasterCat *pSVar4;
  SCasterCat *pSVar5;
  ulong unaff_EBX;
  float unaff_ESI;
  ulong unaff_EDI;
  CFuncColorGradient *pCVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  void *local_c;
  SParam *local_8;
  SParam *pSStack_4;
  
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&param_1;
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&local_c;
  local_c = (void *)0x0;
  local_8 = (SParam *)0x0;
  pCVar6 = param_1;
  iVar3 = (**(code **)(*(int *)(this + 0x34) + 0x18))(param_1,pCVar7,&local_8,pCVar8,1);
  if (iVar3 == 0) {
    SKeyVal::Reset(local_c,(GmFrustumIso4 *)pCVar6);
    return extraout_AL;
  }
  if ((0.0 <= unaff_ESI) && (unaff_ESI <= 1.0)) {
    pSVar4 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal>::SKey>::
             operator[](this + 0x38,pCVar7,unaff_EDI);
    pSVar5 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal>::SKey>::
             operator[](this + 0x38,pCVar8,unaff_EBX);
    pSVar2 = pSStack_4;
    *(float *)pSStack_4 =
         (float)local_8 * (*(float *)(pSVar5 + 4) - *(float *)(pSVar4 + 4)) + *(float *)(pSVar4 + 4)
    ;
    *(float *)((int)pSStack_4 + 100) =
         *(float *)(pSVar4 + 0x68) +
         (float)local_8 * (*(float *)(pSVar5 + 0x68) - *(float *)(pSVar4 + 0x68));
    *(float *)((int)pSStack_4 + 0x68) =
         *(float *)(pSVar4 + 0x6c) +
         (float)local_8 * (*(float *)(pSVar5 + 0x6c) - *(float *)(pSVar4 + 0x6c));
    pSVar1 = *(SParam **)(pSVar4 + 0x70);
    *(float *)((int)pSStack_4 + 0x6c) =
         (float)pSVar1 + (float)local_8 * (*(float *)(pSVar5 + 0x70) - (float)pSVar1);
    this_00 = (float *)((int)pSStack_4 + 4);
    pSStack_4 = pSVar1;
    CSceneFxColors::SParam::SetBlend
              (this_00,(SParam *)(pSVar4 + 8),(SParam *)(pSVar5 + 8),local_8,(float)pCVar6);
    CSceneFxColors::SParam::SetBlend
              ((float *)((int)pSVar2 + 0x34),(SParam *)(pSVar4 + 0x38),(SParam *)(pSVar5 + 0x38),
               pSStack_4,(float)pCVar7);
    return extraout_AL_00;
  }
  return (GmVec3)0x0;
}
}

