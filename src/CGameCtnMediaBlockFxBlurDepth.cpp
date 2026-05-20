// Class implementation: CGameCtnMediaBlockFxBlurDepth

// =================================================
// Function: CGameCtnMediaBlockFxBlurDepth::GetValue
// =================================================
/* WARNING: Removing unreachable block (ram,0x00738da8) */
/* WARNING: Removing unreachable block (ram,0x00738daa) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

GmVec3 __thiscall
CGameCtnMediaBlockFxBlurDepth::GetValue
          (CGameCtnMediaBlockFxBlurDepth *this,CFuncColorGradient *param_1,float param_2)
{
{
  GmVec3 GVar1;
  float fVar2;
  GmVec3 extraout_AL;
  int iVar3;
  SCasterCat *pSVar4;
  SCasterCat *pSVar5;
  void *unaff_ESI;
  ulong unaff_EDI;
  CFuncColorGradient *pCVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  float local_8;
  float *local_4;
  
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&local_8;
  local_8 = 0.0;
  local_4 = (float *)0x0;
  pCVar6 = param_1;
  iVar3 = (**(code **)(*(int *)(this + 0x34) + 0x18))(param_1,pCVar7,&local_4);
  if (iVar3 != 0) {
    pSVar4 = CFastBuffer<class_GxColor>::operator[](this + 0x38,pCVar7,unaff_EDI);
    pSVar5 = CFastBuffer<class_GxColor>::operator[]
                       (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&param_1,
                        (ulong)pCVar6);
    fVar2 = 1.0 - local_8;
    *local_4 = *(float *)(pSVar4 + 4) * fVar2 + local_8 * *(float *)(pSVar5 + 4);
    GVar1 = (GmVec3)((float)_DAT_00b313b8 <
                    (float)*(int *)(pSVar4 + 8) * fVar2 + (float)*(int *)(pSVar5 + 8) * local_8);
    local_4[1] = (float)(uint)(byte)GVar1;
    local_4[2] = fVar2 * *(float *)(pSVar4 + 0xc) + *(float *)(pSVar5 + 0xc) * local_8;
    return GVar1;
  }
  SKeyVal::Reset(unaff_ESI,(GmFrustumIso4 *)pCVar6);
  return extraout_AL;
}
}

