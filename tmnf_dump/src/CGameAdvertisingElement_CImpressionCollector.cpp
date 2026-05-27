// Class implementation: CGameAdvertisingElement_CImpressionCollector

// =================================================
// Function: CGameAdvertisingElement::CImpressionCollector::ClearAll
// =================================================
void __thiscall
CGameAdvertisingElement::CImpressionCollector::ClearAll(void *this,CImpressionCollector *param_1)
{
{
  TiXmlNode *unaff_ESI;
  GmFrustumIso4 *in_stack_00000008;
  
  CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>::Clear
            ((CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>
              *)((int)this + 0x10),unaff_ESI);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
            ((void *)((int)this + 0x20),in_stack_00000008);
  return;
}
}

// =================================================
// Function: CGameAdvertisingElement::CImpressionCollector::ReportFrameFinished
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameAdvertisingElement::CImpressionCollector::ReportFrameFinished
          (void *this,CImpressionCollector *param_1)
{
{
  void *pvVar1;
  float *pfVar2;
  int iVar3;
  SLoadedLight *pSVar4;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EBP;
  float *pfVar5;
  SFillValue *unaff_EDI;
  SLoadedLight *pSVar6;
  __time64_t _Var7;
  void *local_14;
  float *local_10;
  void *local_c;
  int local_8;
  float *local_4;
  
  local_8 = (int)this + 0x10;
  local_4 = (float *)0x0;
  local_c = this;
  iVar3 = CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>::
          SScanner::GetNext(&local_8,(SScanner *)&local_10,(ulong *)&local_14,unaff_EDI);
  pfVar2 = local_10;
  do {
    if (iVar3 == 0) {
      return;
    }
    local_10 = pfVar2;
    if (((uint)pfVar2[3] & 1) == 0) {
LAB_007444bb:
      if ((uint)*(float *)((int)this + 0xc) <= (uint)pfVar2[6]) {
        pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem
                           ((float *)((int)this + 0x20),unaff_EBP);
        unaff_EBP = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x0;
        pfVar5 = pfVar2;
        pSVar6 = pSVar4;
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(float *)pSVar6 = *pfVar5;
          pfVar5 = pfVar5 + 1;
          pSVar6 = pSVar6 + 4;
        }
        _Var7 = __time64((__time64_t *)0x0);
        *(__time64_t *)(pSVar4 + 0x20) = _Var7;
        this = local_4;
      }
      if (pfVar2[6] != 0.0) {
        *pfVar2 = 0.0;
        pfVar2[6] = 0.0;
        pfVar2[1] = 0.0;
        pfVar2[3] = 0.0;
        pfVar2[4] = 0.0;
        pfVar2[8] = 0.0;
        pfVar2[2] = 0.0;
        pfVar2[9] = 0.0;
        pfVar2[5] = 0.0;
      }
    }
    else {
      pvVar1 = (void *)(pfVar2[1] * (float)_DAT_00b362c0 + pfVar2[2] * (float)_DAT_00b41ea8);
      local_c = (void *)pfVar2[1];
      local_14 = local_c;
      if ((float)local_c < (float)pvVar1 != ((float)local_c == (float)pvVar1)) {
        local_14 = pvVar1;
      }
      pfVar2[2] = (float)local_14;
      if ((*(float *)this < (float)local_14) || ((float)local_14 < *(float *)((int)this + 4))) {
        pfVar2[3] = (float)((uint)pfVar2[3] & 0xfffffffe);
      }
      else {
        pfVar2[6] = (float)((int)pfVar2[6] + *(int *)(DAT_00d731e0 + 0x7c));
        pfVar2[3] = (float)(((uint)pfVar2[3] & 0xfffffffc) + 4 ^ (uint)pfVar2[3] & 3);
        pfVar2[4] = pfVar2[4] + pfVar2[1];
        pfVar2[5] = pfVar2[5] + *pfVar2;
      }
      if (((uint)pfVar2[3] & 1) == 0) goto LAB_007444bb;
    }
    pfVar2[3] = (float)((uint)pfVar2[3] & 0xfffffffe);
    iVar3 = CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>::
            SScanner::GetNext(&local_4,(SScanner *)&local_c,(ulong *)&local_10,
                              (SFillValue *)unaff_EBP);
    pfVar2 = local_10;
  } while( true );
}
}

