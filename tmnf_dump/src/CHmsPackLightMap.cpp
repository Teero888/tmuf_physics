// Class implementation: CHmsPackLightMap

// =================================================
// Function: CHmsPackLightMap::BlockAdd
// =================================================
void __thiscall
CHmsPackLightMap::BlockAdd(CHmsPackLightMap *this,CHmsPackLightMap *param_1,CHmsCorpus *param_2)
{
{
  int iVar1;
  bool bVar2;
  CHmsPackLightMap *pCVar3;
  CMwId CVar4;
  SLoadedLight *pSVar5;
  int *piVar6;
  undefined3 extraout_var;
  CFastStringInt *unaff_EBP;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  CHmsCorpus *unaff_EDI;
  ulong uVar7;
  
  pCVar3 = param_1;
  if (*(int *)(this + 0x1c4) == 1) {
    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 0x68);
    if (iVar1 == 0) {
      return;
    }
    uVar7 = *(uint *)(iVar1 + 0x70) >> 1 & 0xff;
  }
  else {
    if (*(int *)(this + 0x1c4) == 2) {
      return;
    }
    uVar7 = Corpus_GetLightMapBlockCount(this,param_1,unaff_EDI);
  }
  if (uVar7 == 0) {
    return;
  }
  pSVar5 = CFastBuffer<class_GmIso4>::AddNewElem(this + 0x48,unaff_ESI);
  *(CHmsPackLightMap **)(pSVar5 + 0xc) = param_1;
  *(undefined4 *)(pSVar5 + 0x10) = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 100);
  *(undefined4 *)pSVar5 = 0xffffffff;
  *(undefined4 *)(pSVar5 + 4) = 0xffffffff;
  *(ulong *)(pSVar5 + 8) = uVar7;
  *(undefined4 *)(pSVar5 + 0x2c) = 0;
  if (uVar7 != 1) goto LAB_00544800;
  if ((*(int *)(*(int *)(param_1 + 0x48) + 0x40) == 0) ||
     (piVar6 = (int *)(**(code **)(**(int **)(*(int *)(param_1 + 0x48) + 0x40) + 0x14))(),
     piVar6 == (int *)0x0)) {
LAB_005447d4:
    bVar2 = false;
  }
  else {
    CVar4 = CMwId::CreateFromLocalName(&stack0x0000000c);
    param_1 = (CHmsPackLightMap *)0x1;
    if (*piVar6 != *(int *)CONCAT31(extraout_var,CVar4)) goto LAB_005447d4;
    bVar2 = true;
  }
  if (((uint)param_1 & 1) != 0) {
    OnAccessViolation_ConcatToCrashFileName(unaff_EBP);
  }
  if (bVar2) {
    *(undefined4 *)(pSVar5 + 0x2c) = 1;
    *(int *)(pSVar5 + 8) = DAT_00d67618 * DAT_00d67614;
  }
LAB_00544800:
  GmBoxAligned::SetMult
            (pSVar5 + 0x14,
             (SPlugFaceCull *)(*(int *)(*(int *)(*(int *)(pCVar3 + 0x48) + 0x14) + 100) + 0x34),
             (SPlugFaceCull *)(pCVar3 + 0x18),(GmIso4 *)unaff_EBP);
  return;
}
}

// =================================================
// Function: CHmsPackLightMap::BlockSkipLightMap
// =================================================
int __thiscall
CHmsPackLightMap::BlockSkipLightMap
          (CHmsPackLightMap *this,CHmsPackLightMap *param_1,CHmsCorpus *param_2)
{
{
  ulong uVar1;
  CHmsCorpus *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  uVar1 = Corpus_GetLightMapBlockCount(this,param_1,unaff_ESI);
  if (uVar1 != 0) {
    if (*(int *)(this + 0x1c4) != 1) {
      return 0;
    }
    if (*(CMwNod **)(this + 0x20) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x20),unaff_retaddr);
      *(undefined4 *)(this + 0x20) = 0;
    }
    *(undefined4 *)(this + 0x14) = 0xffffffff;
    *(undefined4 *)(this + 0x18) = 0xffffffff;
    *(undefined4 *)(this + 0x2c) = 0;
  }
  return 1;
}
}

// =================================================
// Function: CHmsPackLightMap::BlockSub
// =================================================
void __thiscall
CHmsPackLightMap::BlockSub(CHmsPackLightMap *this,CHmsPackLightMap *param_1,CHmsCorpus *param_2)
{
{
  int iVar1;
  CFastBuffer<struct_CHmsPackLightMap::SBlock> *unaff_ESI;
  CMwNod *unaff_EDI;
  CFastBuffer<struct_CHmsPackLightMap::SBlock> *unaff_retaddr;
  
  if (*(int *)(this + 0x1c4) != 2) {
    if (*(int *)(this + 0x1c4) == 1) {
      if (*(CMwNod **)(this + 0x20) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x20),unaff_EDI);
        *(undefined4 *)(this + 0x20) = 0;
      }
      *(undefined4 *)(this + 0x14) = 0xffffffff;
      *(undefined4 *)(this + 0x18) = 0xffffffff;
      *(undefined4 *)(this + 0x2c) = 0;
    }
    iVar1 = BlockSub_IsFound(this,(CHmsPackLightMap *)param_2,(CHmsCorpus *)(this + 0x3c),unaff_ESI)
    ;
    if (iVar1 == 0) {
      BlockSub_IsFound(this,(CHmsPackLightMap *)param_2,(CHmsCorpus *)(this + 0x48),unaff_retaddr);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsPackLightMap::BlockSub_IsFound
// =================================================
int __thiscall
CHmsPackLightMap::BlockSub_IsFound
          (CHmsPackLightMap *this,CHmsPackLightMap *param_1,CHmsCorpus *param_2,
          CFastBuffer<struct_CHmsPackLightMap::SBlock> *param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_2,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
               ::operator[](param_2,pCVar3,unaff_ESI);
      if (*(CHmsCorpus **)(pSVar2 + 0xc) == param_2) {
        CFastBuffer<struct_CHmsPackLightMap::SBlock>::ReplaceByLastAt
                  (param_2,(CFastBufferRef<class_CGameMobil> *)pCVar3,1,unaff_EBP);
        return 1;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0;
}
}

// =================================================
// Function: CHmsPackLightMap::Corpus_GetLightMapBlockCount
// =================================================
ulong __thiscall
CHmsPackLightMap::Corpus_GetLightMapBlockCount
          (CHmsPackLightMap *this,CHmsPackLightMap *param_1,CHmsCorpus *param_2)
{
{
  int iVar1;
  uint uVar2;
  CPlugShader *pCVar3;
  undefined1 *this_00;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_ESI;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [8];
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a96048;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CPlugTree::CIteratorShader::CIteratorShader
            (local_20,*(CIteratorShader **)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 100),
             (CPlugTree *)0x0,(EMode)((uint)DAT_00cca150 ^ (uint)&stack0xffffffdc));
  do {
    this_00 = local_1c;
    if (local_10 == 0) goto LAB_005446a5;
    pCVar3 = CPlugTree::CIteratorShader::GetNextShader
                       (this_00,(CIteratorShader *)0x0,(CPlugTree **)unaff_ESI);
  } while ((*(ushort *)(pCVar3 + 0x28) & 0x1000) == 0);
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 0x68);
  this_00 = local_18;
  if (iVar1 != 0) {
    uVar2 = *(uint *)(iVar1 + 0x70);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (this_00,(CFastBuffer<class_CPlugFileGPUV*> *)0x544690);
    ExceptionList = (void *)0x0;
    return uVar2 >> 1 & 0xff;
  }
LAB_005446a5:
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this_00,unaff_ESI);
  ExceptionList = pvStack_4;
  return 0;
}
}

// =================================================
// Function: CHmsPackLightMap::DynaDbgLightGet
// =================================================
EDbgLight __thiscall
CHmsPackLightMap::DynaDbgLightGet(CHmsPackLightMap *this,CHmsPackLightMap *param_1)
{
{
  return *(EDbgLight *)(*(int *)(this + 0x30) + 0x28);
}
}

// =================================================
// Function: CHmsPackLightMap::LmUsageIsPotentiallySupported
// =================================================
int __cdecl CHmsPackLightMap::LmUsageIsPotentiallySupported(void)
{
{
  int iVar1;
  
  if (DAT_00d54380 != 0) {
    if (*(int *)(DAT_00d54380 + 0x20) == 0) {
      iVar1 = *(int *)(DAT_00d54380 + 0x24);
    }
    else {
      iVar1 = *(int *)(DAT_00d54380 + 0x28);
    }
    if (*(int *)(iVar1 + 0x58) != 0) {
      return (uint)(2 < DAT_00d123b8._2_2_);
    }
  }
  return 0;
}
}

// =================================================
// Function: CHmsPackLightMap::LmUsageIsSupported
// =================================================
int __thiscall
CHmsPackLightMap::LmUsageIsSupported
          (CHmsPackLightMap *this,CHmsPackLightMap *param_1,CHmsZoneVPacker *param_2)
{
{
  int iVar1;
  
  if ((*(int *)(this + 0x1bc) == 0) && (param_1 == (CHmsPackLightMap *)0x0)) {
    return 0;
  }
  iVar1 = LmUsageIsPotentiallySupported();
  return iVar1;
}
}

// =================================================
// Function: CHmsPackLightMap::SetPacker
// =================================================
void __thiscall
CHmsPackLightMap::SetPacker
          (CHmsPackLightMap *this,CHmsPackLightMap *param_1,CHmsZoneVPacker *param_2)
{
{
  GmFrustumIso4 *unaff_ESI;
  GmFrustumIso4 *unaff_retaddr;
  
  if (*(CHmsPackLightMap **)(this + 0x1bc) != param_1) {
    *(CHmsPackLightMap **)(this + 0x1bc) = param_1;
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x3c,unaff_ESI);
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x48,unaff_retaddr);
    *(undefined4 *)(this + 0x1c4) = 0;
  }
  return;
}
}

