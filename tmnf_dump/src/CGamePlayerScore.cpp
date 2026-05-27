// Class implementation: CGamePlayerScore

// =================================================
// Function: CGamePlayerScore::ForceNeedAllCampaignRecordsUpdate
// =================================================
void __thiscall
CGamePlayerScore::ForceNeedAllCampaignRecordsUpdate
          (CGamePlayerScore *this,CGamePlayerScore *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x68,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                         (this + 0x68,pCVar3,unaff_ESI);
      pCVar3 = pCVar3 + 1;
      *(undefined4 *)(pSVar2 + 0x14) = 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

