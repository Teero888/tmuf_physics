// Class implementation: CSystemXmlTools

// =================================================
// Function: CSystemXmlTools::NodParamToXml
// =================================================
int __cdecl
CSystemXmlTools::NodParamToXml
          (CMwNod *param_1,SMwParamInfo *param_2,TiXmlNode *param_3,CFastStringInt *param_4)
{
{
  CSystemFidFile *this;
  CMwStack *pCVar1;
  ulong uVar2;
  int iVar3;
  TiXmlNode *extraout_EAX;
  TiXmlNode *extraout_EAX_00;
  TiXmlNode *extraout_EAX_01;
  TiXmlNode *extraout_EAX_02;
  TiXmlNode *extraout_EAX_03;
  TiXmlNode *extraout_EAX_04;
  TiXmlNode *extraout_EAX_05;
  TiXmlNode *this_00;
  TiXmlNode *extraout_EAX_06;
  TiXmlNode *extraout_EAX_07;
  undefined4 *extraout_EAX_08;
  CMwStack *unaff_EBX;
  TiXmlNode *pTVar4;
  void *unaff_EBP;
  CMwValueStd *unaff_ESI;
  ulong unaff_EDI;
  TiXmlNode *in_stack_fffffda8;
  TiXmlNode *in_stack_fffffdac;
  CFastStringInt *in_stack_fffffdb0;
  TiXmlNode *in_stack_fffffdb4;
  CFastStringInt *pCVar5;
  CFastStringInt *pCVar6;
  CFastString *pCVar7;
  TiXmlNode *pTVar8;
  CFastStringInt *in_stack_fffffdc0;
  SHeaderCommunity *pSVar9;
  SMwParamInfo *pSVar10;
  TiXmlNode *pTVar11;
  CFastStringInt *pCVar12;
  CMwStack *pCVar13;
  CMwStack *pCVar14;
  TiXmlNode *pTVar15;
  CMwNod *pCVar16;
  char *pcVar17;
  SNationConfig *pSVar18;
  undefined4 *puStack_21c;
  uint uStack_218;
  CMwStack *pCStack_214;
  CMwStack *pCStack_210;
  undefined *puStack_20c;
  int iStack_204;
  CMwNod *pCStack_1fc;
  undefined4 uStack_1f8;
  int local_1f4;
  CMwStack local_1f0 [4];
  CMwNod local_1ec [4];
  int local_1e8;
  int local_1e4;
  int iStack_1e0;
  uint uStack_1dc;
  undefined4 *local_1d8;
  int local_1d4;
  int local_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  CFastString *pCStack_1c4;
  undefined **ppuStack_1c0;
  undefined **ppuStack_1bc;
  CMwNod aCStack_1b8 [4];
  int aiStack_1b4 [2];
  CMwStack aCStack_1ac [8];
  undefined4 *puStack_1a4;
  int aiStack_1a0 [2];
  undefined **ppuStack_198;
  undefined4 *puStack_194;
  TiXmlText aTStack_18c [4];
  TiXmlElement aTStack_188 [4];
  undefined **ppuStack_184;
  TiXmlElement aTStack_180 [4];
  TiXmlElement aTStack_17c [60];
  TiXmlNode *pTStack_140;
  int iStack_138;
  int iStack_134;
  int iStack_12c;
  CMwNod *local_128 [14];
  int *piStack_f0;
  CMwStack aCStack_ec [12];
  int *piStack_e0;
  TiXmlElement aTStack_c4 [8];
  TiXmlElement aTStack_bc [40];
  TiXmlElement aTStack_94 [8];
  TiXmlElement aTStack_8c [88];
  undefined1 uStack_34;
  undefined1 uStack_30;
  undefined1 uStack_28;
  undefined1 uStack_24;
  undefined1 uStack_20;
  undefined1 uStack_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  uint uStack_c;
  undefined4 local_8;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00a829b3;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  pCVar14 = (CMwStack *)0x42c23d;
  CMwStack::CMwStack((CMwStack *)&local_1f4,(CMwStack *)0x1,DAT_00cca150 ^ (uint)&stack0xfffffdd8);
  pTVar4 = (TiXmlNode *)0x0;
  local_8 = 0;
  CMwStack::InsertBaseVal(local_1f0,(CMwStack *)param_2,unaff_EDI);
  *local_1d8 = 0;
  local_1d4 = local_1e8 + -1;
  pCVar16 = local_1ec;
  pTVar15 = (TiXmlNode *)0x42c279;
  uVar2 = CMwNod::Param_Get(param_1,pCVar16,(CMwStack *)local_128,unaff_ESI);
  if (uVar2 != 0) {
LAB_0042c952:
    CMwStack::~CMwStack((CMwStack *)&local_1e8,unaff_EBX);
    ExceptionList = unaff_EBP;
    return 0;
  }
  local_1d0 = local_1e4 + -1;
  pSVar18 = (SNationConfig *)0x1007000;
  (**(code **)(**(int **)(param_2 + 8) + 0x10))();
  pcVar17 = (char *)0x42c2a8;
  iVar3 = (**(code **)(**(int **)(param_2 + 8) + 0xa8))();
  if (iVar3 == 0) {
    if (*(int *)param_2 == 5) {
      if (iStack_138 != 0) {
        pTVar11 = (TiXmlNode *)0x42c3d3;
        TiXmlElement::TiXmlElement(aTStack_188,*(TiXmlElement **)(param_2 + 0x10),(char *)pCVar14);
        puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,4);
        pSVar18 = (SNationConfig *)0x42c3e4;
        pCVar14 = (CMwStack *)extraout_EAX_01;
        pTVar4 = TiXmlNode::InsertEndChild(param_3,extraout_EAX_01,pTVar15);
        uStack_c = uStack_c & 0xffffff00;
        TiXmlElement::~TiXmlElement(aTStack_180,(TiXmlElement *)pCVar16);
        this = *(CSystemFidFile **)(iStack_12c + 8);
        iStack_204 = iStack_12c;
        if ((this == (CSystemFidFile *)0x0) ||
           (iVar3 = (**(code **)(*(int *)this + 0x10))(), iVar3 == 0)) {
          iVar3 = NodParamsToXml(pCStack_1fc,pTVar4,param_4);
          if (iVar3 == 0) goto LAB_0042c952;
        }
        else {
          pCVar6 = (CFastStringInt *)0x1;
          uStack_20 = 5;
          CSystemFidFile::GetFullName(this,(CPlugFile *)&stack0xfffffddc,(CFastStringInt *)0x1);
          TiXmlText::TiXmlText((TiXmlText *)&uStack_1c8,(TiXmlText *)&stack0xfffffdd8,pCVar6);
          uStack_20 = 6;
          TiXmlNode::InsertEndChild(pTVar4,extraout_EAX_02,(TiXmlNode *)in_stack_fffffdc0);
          uStack_1c = 5;
          ppuStack_1c0 = TiXmlText::vftable;
          TiXmlNode::~TiXmlNode((TiXmlNode *)&ppuStack_1c0,pTVar11);
          CGameCtnApp::SNationConfig::~SNationConfig(&puStack_21c,pSVar18);
        }
      }
    }
    else {
      pCVar13 = (CMwStack *)0x42c4b7;
      iVar3 = CMwParam::IsIndexed(*(CMwParam **)(param_2 + 8),(CMwParam *)pCVar14);
      if (iVar3 == 0) {
        SStringParam::SStringParam(&ppuStack_1c0,*(SStringParam **)(param_2 + 0x10),(char *)pTVar15)
        ;
        CFastStringInt::CFastStringInt
                  (&local_1d8,(CFastStringInt *)&ppuStack_1bc,(SStringParam *)pCVar16);
        uStack_1cc = extraout_EAX_08[1];
        uStack_1c8 = *extraout_EAX_08;
        uStack_1f8 = *(undefined4 *)param_4;
        pCStack_1fc = *(CMwNod **)(param_4 + 4);
        local_8 = CONCAT31(local_8._1_3_,0x11);
        pCStack_1c4 = (CFastString *)0x0;
        local_1f4 = 0;
        SStringParam::SStringParam
                  (&ppuStack_1c0,(SStringParam *)"%1Uhandled Param type for param %2",pcVar17);
        CFastStringInt::SetCompose
                  (param_4,(CFastStringInt *)&ppuStack_1bc,(SStringParam *)&uStack_1f8,
                   (SStringParamInt *)&uStack_1c8);
        CGameCtnApp::SNationConfig::~SNationConfig(&local_1d0,pSVar18);
        goto LAB_0042c952;
      }
      iStack_1e0 = local_1f4 + -1;
      CMwStack::CMwStack((CMwStack *)aiStack_1b4,(CMwStack *)pTVar15,(ulong)pCVar16);
      local_8 = CONCAT31(local_8._1_3_,7);
      pCVar14 = (CMwStack *)0x42c4ee;
      CMwStack::CopyFrom(aCStack_1ac,(SParam_Set *)local_1f0,(SParam *)0x1);
      pCVar16 = (CMwNod *)0x42c4fb;
      CMwStack::InsertBaseVal(aCStack_1ac,(CMwStack *)0x0,(ulong)pcVar17);
      *puStack_194 = 1;
      pCStack_210 = (CMwStack *)0x0;
      puStack_20c = PTR_DAT_00bbf7dc;
      pCVar6 = (CFastStringInt *)local_128;
      unaff_EBP = (void *)CONCAT31((int3)((uint)unaff_EBP >> 8),8);
      pTVar15 = (TiXmlNode *)0x42c532;
      pCStack_210 = (CMwStack *)(**(code **)(**(int **)(param_2 + 8) + 0x88))();
      if (pCStack_210 != (CMwStack *)0x0) {
        TiXmlElement::TiXmlElement(aTStack_c4,*(TiXmlElement **)(param_2 + 0x10),(char *)pCVar13);
        local_14 = (void *)CONCAT31(local_14._1_3_,9);
        pCVar13 = (CMwStack *)extraout_EAX_03;
        pTVar4 = TiXmlNode::InsertEndChild(param_3,extraout_EAX_03,(TiXmlNode *)pCVar14);
        puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,8);
        pCVar14 = (CMwStack *)0x42c571;
        TiXmlElement::~TiXmlElement(aTStack_bc,(TiXmlElement *)pCVar16);
      }
      pCStack_214 = (CMwStack *)0x0;
      if (pCStack_210 != (CMwStack *)0x0) {
        do {
          pCVar1 = pCStack_214;
          CMwStack::ChangeBaseVal((CMwStack *)&ppuStack_1bc,pCStack_214,(ulong)pCVar13);
          *puStack_1a4 = 1;
          pCVar13 = (CMwStack *)&iStack_138;
          aiStack_1a0[0] = aiStack_1b4[0] + -1;
          uVar2 = CMwNod::Param_Get(param_1,aCStack_1b8,pCVar13,(CMwValueStd *)pCVar14);
          if (uVar2 != 0) {
LAB_0042c62e:
            CGameCtnApp::SNationConfig::~SNationConfig(&stack0xfffffddc,(SNationConfig *)pCVar13);
            local_14 = (void *)((uint)local_14 & 0xffffff00);
            CMwStack::~CMwStack((CMwStack *)aCStack_1b8,pCVar14);
            goto LAB_0042c952;
          }
          if (*(int *)(param_2 + 0x24) == 5) {
            if (iStack_134 != 0) {
              pCVar13 = (CMwStack *)0x42c5eb;
              TiXmlElement::TiXmlElement
                        ((TiXmlElement *)&ppuStack_184,*(TiXmlElement **)(param_2 + 0x20),
                         (char *)pCVar16);
              uStack_c = CONCAT31(uStack_c._1_3_,10);
              pTVar15 = TiXmlNode::InsertEndChild(pTVar4,extraout_EAX_04,pTVar15);
              local_8 = CONCAT31(local_8._1_3_,8);
              TiXmlElement::~TiXmlElement(aTStack_17c,(TiXmlElement *)pCVar6);
              pCVar14 = (CMwStack *)0x42c623;
              pCVar16 = local_128[0];
              pCVar6 = param_4;
              iVar3 = NodParamsToXml(local_128[0],pTVar15,param_4);
              if (iVar3 == 0) goto LAB_0042c62e;
            }
          }
          else {
            uStack_1dc = 0;
            local_1d8 = (undefined4 *)PTR_DAT_00bbf7dc;
            pCVar13 = aCStack_ec;
            puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,0xb);
            pCVar12 = (CFastStringInt *)0x42c67f;
            pCVar14 = (CMwStack *)param_1;
            CMwStack::MakeInfoFromStack
                      ((CMwStack *)aiStack_1b4,pCVar13,(SMwParamInfo *)param_1,pCVar16);
            pCVar16 = (CMwNod *)0x42c690;
            iVar3 = (**(code **)(*piStack_e0 + 0xa8))();
            if (iVar3 != 0) {
              if (*(int *)(param_2 + 0x24) == 0x24) {
                pCVar7 = *(CFastString **)pTStack_140;
                unaff_EBX = (CMwStack *)0x0;
                puStack_21c = (undefined4 *)PTR_DAT_00bbf7d8;
                uStack_1c = 0xc;
                pcVar17 = (char *)0x42c6dc;
                pCStack_1c4 = pCVar7;
                CFastString::SetReal
                          ((CFastString *)&stack0xfffffde0,pCVar7,4.2039e-45,(ulong)pCVar12);
                pCVar12 = (CFastStringInt *)&uStack_1dc;
                local_1d8 = puStack_21c;
                uStack_1dc = uStack_218;
                pSVar9 = (SHeaderCommunity *)0x42c6fa;
                CFastStringInt::Concat(&stack0xfffffddc,pCVar12,(SStringParam *)pCVar13);
                if (pCVar1 < (CMwStack *)(puStack_20c + -1)) {
                  if (uStack_218 < 4) {
                    iVar3 = 4 - uStack_218;
                    do {
                      in_stack_fffffda8 = (TiXmlNode *)0x42c72e;
                      SStringParam::SStringParam
                                (&local_1e8,(SStringParam *)&DAT_00b2d0d4,(char *)in_stack_fffffdb0)
                      ;
                      in_stack_fffffdb0 = (CFastStringInt *)&local_1e4;
                      in_stack_fffffdac = (TiXmlNode *)0x42c73c;
                      CFastStringInt::Concat
                                (&stack0xfffffdc8,in_stack_fffffdb0,
                                 (SStringParam *)in_stack_fffffdb4);
                      iVar3 = iVar3 + -1;
                    } while (iVar3 != 0);
                  }
                  in_stack_fffffdb0 = (CFastStringInt *)0x42c74f;
                  SStringParam::SStringParam(&local_1d8,(SStringParam *)&DAT_00b2d0d4,pcVar17);
                  in_stack_fffffdb4 = (TiXmlNode *)0x42c75d;
                  CFastStringInt::Concat
                            (&stack0xfffffdd0,(CFastStringInt *)&local_1d4,(SStringParam *)pCVar7);
                }
                CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xfffffddc,pSVar9);
              }
              else {
                pCStack_210 = (CMwStack *)0x0;
                puStack_20c = PTR_DAT_00bbf7dc;
                pTVar11 = (TiXmlNode *)&pCStack_210;
                uStack_1c = 0xd;
                pCVar5 = (CFastStringInt *)0x42c7a3;
                pTVar8 = pTStack_140;
                pSVar10 = param_2;
                (**(code **)(*piStack_f0 + 0xb4))();
                TiXmlElement::TiXmlElement
                          (aTStack_94,*(TiXmlElement **)(param_2 + 0x20),(char *)in_stack_fffffda8);
                uStack_34 = 0xe;
                in_stack_fffffda8 = extraout_EAX_05;
                this_00 = TiXmlNode::InsertEndChild(pTVar4,extraout_EAX_05,in_stack_fffffdac);
                uStack_30 = 0xd;
                TiXmlElement::~TiXmlElement(aTStack_8c,(TiXmlElement *)in_stack_fffffdb0);
                in_stack_fffffdac = (TiXmlNode *)0x42c7ea;
                TiXmlText::TiXmlText((TiXmlText *)aiStack_1a0,(TiXmlText *)&stack0xfffffde0,pCVar5);
                uStack_28 = 0xf;
                in_stack_fffffdb0 = (CFastStringInt *)0x42c7fa;
                in_stack_fffffdb4 = extraout_EAX_06;
                TiXmlNode::InsertEndChild(this_00,extraout_EAX_06,pTVar11);
                uStack_24 = 0xd;
                ppuStack_198 = TiXmlText::vftable;
                TiXmlNode::~TiXmlNode((TiXmlNode *)&ppuStack_198,pTVar8);
                CGameCtnApp::SNationConfig::~SNationConfig(&pCStack_214,(SNationConfig *)pSVar10);
              }
            }
            uStack_1c = 8;
            CGameCtnApp::SNationConfig::~SNationConfig(&local_1e8,(SNationConfig *)pCVar12);
          }
          pCStack_214 = pCStack_214 + 1;
        } while (pCStack_214 < pCStack_210);
      }
      if ((pSVar18 != (SNationConfig *)0x0) && (pTVar4 != (TiXmlNode *)0x0)) {
        TiXmlText::TiXmlText(aTStack_18c,(TiXmlText *)&stack0xfffffddc,(CFastStringInt *)pCVar13);
        local_14 = (void *)CONCAT31(local_14._1_3_,0x10);
        pCVar13 = (CMwStack *)extraout_EAX_07;
        TiXmlNode::InsertEndChild(pTVar4,extraout_EAX_07,(TiXmlNode *)pCVar14);
        puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,8);
        ppuStack_184 = TiXmlText::vftable;
        pCVar14 = (CMwStack *)0x42c893;
        TiXmlNode::~TiXmlNode((TiXmlNode *)&ppuStack_184,(TiXmlNode *)pCVar16);
      }
      if (unaff_EBX != (CMwStack *)PTR_DAT_00bbf7dc) {
        if (((byte)unaff_EBX[-1] & 0x80) == 0) {
          unaff_EBX = unaff_EBX + -2;
        }
        else {
          unaff_EBX = unaff_EBX + -4;
        }
        operator_delete__(unaff_EBX);
      }
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      CMwStack::~CMwStack((CMwStack *)&ppuStack_1bc,pCVar13);
    }
  }
  else {
    pTVar11 = (TiXmlNode *)0x42c2c0;
    TiXmlElement::TiXmlElement(aTStack_188,*(TiXmlElement **)(param_2 + 0x10),(char *)pCVar14);
    puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,1);
    pTVar4 = TiXmlNode::InsertEndChild(param_3,extraout_EAX,pTVar15);
    uStack_c = uStack_c & 0xffffff00;
    TiXmlElement::~TiXmlElement(aTStack_180,(TiXmlElement *)pCVar16);
    pCStack_214 = (CMwStack *)0x0;
    pCStack_210 = (CMwStack *)PTR_DAT_00bbf7dc;
    pCVar14 = (CMwStack *)&pCStack_214;
    local_8 = CONCAT31(local_8._1_3_,2);
    pTVar15 = (TiXmlNode *)0x42c317;
    (**(code **)(**(int **)(param_2 + 8) + 0xb4))();
    TiXmlText::TiXmlText((TiXmlText *)&pCStack_1c4,(TiXmlText *)&stack0xfffffdd4,in_stack_fffffdc0);
    uStack_1c = 3;
    TiXmlNode::InsertEndChild(pTVar4,extraout_EAX_00,pTVar11);
    pvStack_18 = (void *)CONCAT31(pvStack_18._1_3_,2);
    ppuStack_1bc = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)&ppuStack_1bc,pTVar15);
    if (puStack_21c != (undefined4 *)PTR_DAT_00bbf7dc) {
      if ((*(byte *)((int)puStack_21c + -1) & 0x80) == 0) {
        puStack_21c = (undefined4 *)((int)puStack_21c + -2);
      }
      else {
        puStack_21c = puStack_21c + -1;
      }
      operator_delete__(puStack_21c);
      puStack_21c = (undefined4 *)PTR_DAT_00bbf7dc;
    }
  }
  local_14 = (void *)0xffffffff;
  CMwStack::~CMwStack((CMwStack *)&pCStack_1fc,pCVar14);
  ExceptionList = pvStack_18;
  return 1;
}
}

// =================================================
// Function: CSystemXmlTools::NodParamsToXml
// =================================================
int __cdecl
CSystemXmlTools::NodParamsToXml(CMwNod *param_1,TiXmlNode *param_2,CFastStringInt *param_3)
{
{
  int iVar1;
  SMwParamInfo *pSVar2;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar3;
  void *pvVar4;
  SCasterCat *pSVar5;
  int iVar6;
  int *piVar7;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_EBX;
  CFastStringInt *unaff_EBP;
  TiXmlAttribute *unaff_ESI;
  uint uVar8;
  GmFrustumIso4 *unaff_EDI;
  void *pvVar9;
  void *in_stack_00000010;
  uint in_stack_00000014;
  TiXmlNode *in_stack_00000018;
  CFastStringInt *in_stack_0000001c;
  undefined1 auStack_18 [4];
  ulong uStack_14;
  undefined1 auStack_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a82b08;
  local_c = ExceptionList;
  pCVar3 = (CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffd0);
  ExceptionList = &local_c;
  pvVar4 = (void *)(**(code **)(*(int *)param_1 + 8))();
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(auStack_18,pCVar3);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(&uStack_14,unaff_EDI);
  pvVar9 = pvVar4;
  while (pvVar9 != (void *)0x0) {
    CFastBuffer<class_CDx9TextureKeeper*>::Add(auStack_10,(TiXmlAttributeSet *)&param_3,unaff_ESI);
    pvVar9 = *(void **)((int)pvVar9 + 8);
    in_stack_00000010 = pvVar9;
  }
  uStack_14 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (auStack_10,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
  in_stack_00000010 = (void *)0x0;
  if (uStack_14 != 0) {
    do {
      uVar8 = (uint)in_stack_00000010;
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (&local_c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                   ((uStack_14 - (int)in_stack_00000010) + -1),(ulong)unaff_EBP);
      iVar1 = *(int *)pSVar5;
      local_c = *(void **)(iVar1 + 0x24);
      pvVar9 = (void *)0x0;
      if (local_c != (void *)0x0) {
        do {
          pSVar2 = *(SMwParamInfo **)(*(int *)(iVar1 + 0x20) + (int)pvVar9 * 4);
          if (((*(uint *)(pSVar2 + 0x14) & 0x11) != 0) && ((*(uint *)(pSVar2 + 0x14) & 0x22) != 0))
          {
            if (*(int *)(pSVar2 + 4) == 0x1001000) {
              unaff_EBP = (CFastStringInt *)0x42d7d8;
              iVar6 = (**(code **)(*(int *)param_1 + 0x14))();
              if (iVar6 != 0) {
                unaff_EBP = (CFastStringInt *)0x42d7e6;
                piVar7 = (int *)(**(code **)(*(int *)param_1 + 0x14))();
                if (*piVar7 != -1) goto LAB_0042d7f6;
              }
            }
            else if ((*(uint *)(pSVar2 + 0x18) & 0x400000) != 0) {
LAB_0042d7f6:
              unaff_EBP = in_stack_0000001c;
              iVar6 = NodParamToXml(param_1,pSVar2,in_stack_00000018,in_stack_0000001c);
              if (iVar6 == 0) {
                CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                          (&puStack_8,unaff_EBX);
                ExceptionList = param_2;
                return 0;
              }
            }
          }
          pvVar9 = (void *)((int)pvVar9 + 1);
          uVar8 = in_stack_00000014;
        } while (pvVar9 < local_c);
      }
      in_stack_00000010 = (void *)(uVar8 + 1);
    } while (in_stack_00000010 < uStack_14);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (&local_c,(CFastBuffer<class_CPlugFileGPUV*> *)unaff_EBP);
  ExceptionList = pvVar4;
  return 1;
}
}

// =================================================
// Function: CSystemXmlTools::NodToXml
// =================================================
int __cdecl CSystemXmlTools::NodToXml(CMwNod *param_1,CSystemFid *param_2)
{
{
  char cVar1;
  bool bVar2;
  int iVar3;
  TiXmlNode *extraout_EAX;
  TiXmlNode *pTVar4;
  CPlugFileGpuBuilder *pCVar5;
  TiXmlDocument *pTVar6;
  char *pcVar7;
  undefined4 *extraout_EAX_00;
  TiXmlElement *unaff_EBX;
  TiXmlNode *unaff_ESI;
  char *unaff_EDI;
  undefined1 uStack0000000c;
  void *in_stack_00000010;
  undefined4 uStack00000014;
  SNationConfig *in_stack_00000018;
  CPlugFileGpuBuilder *in_stack_ffffff30;
  char *in_stack_ffffff34;
  CFastStringInt *in_stack_ffffff38;
  SStringParam *in_stack_ffffff3c;
  SStringParamInt *pSVar8;
  SNationConfig *pSVar9;
  CPlugFileGpuBuilder *in_stack_ffffff48;
  char *in_stack_ffffff4c;
  SNationConfig *in_stack_ffffff50;
  char *pcStack_ac;
  int iStack_a8;
  TiXmlDocument local_a4 [4];
  char *pcStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined **ppuStack_8c;
  undefined1 auStack_88 [48];
  undefined4 *puStack_58;
  int iStack_54;
  TiXmlElement aTStack_50 [68];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a82b99;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  TiXmlDocument::TiXmlDocument(local_a4,(TiXmlDocument *)(DAT_00cca150 ^ (uint)&stack0xffffff24));
  iVar3 = (**(code **)(*(int *)param_2 + 8))();
  TiXmlElement::TiXmlElement((TiXmlElement *)&puStack_58,*(TiXmlElement **)(iVar3 + 0x14),unaff_EDI)
  ;
  pTVar4 = TiXmlNode::InsertEndChild((TiXmlNode *)&uStack_9c,extraout_EAX,unaff_ESI);
  TiXmlElement::~TiXmlElement(aTStack_50,unaff_EBX);
  pSVar8 = (SStringParamInt *)0x0;
  uStack0000000c = 2;
  pSVar9 = (SNationConfig *)PTR_DAT_00bbf7dc;
  iVar3 = NodParamsToXml((CMwNod *)param_2,pTVar4,(CFastStringInt *)&stack0xffffff40);
  if (iVar3 == 0) {
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar5 = CFastString::operator<<
                       ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)&stack0xffffff40,
                        (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)pCVar5,in_stack_ffffff30,in_stack_ffffff34);
    CClassicLog::ConsoleAddLogString(1,(CFastString *)&DAT_00d71e54);
    if (in_stack_ffffff4c != PTR_DAT_00bbf7dc) {
      if ((in_stack_ffffff4c[-1] & 0x80U) == 0) {
        in_stack_ffffff4c = in_stack_ffffff4c + -2;
      }
      else {
        in_stack_ffffff4c = in_stack_ffffff4c + -4;
      }
      operator_delete__(in_stack_ffffff4c);
    }
  }
  else {
    pTVar6 = (TiXmlDocument *)(**(code **)**(undefined4 **)(in_stack_00000018 + 0x6c))();
    if (pTVar6 == (TiXmlDocument *)0x0) {
      if (in_stack_ffffff4c != PTR_DAT_00bbf7dc) {
        if ((in_stack_ffffff4c[-1] & 0x80U) == 0) {
          operator_delete__(in_stack_ffffff4c + -2);
        }
        else {
          operator_delete__(in_stack_ffffff4c + -4);
        }
      }
    }
    else {
      bVar2 = TiXmlDocument::SaveFile_Gbx
                        ((TiXmlDocument *)&ppuStack_8c,pTVar6,(CClassicBuffer *)in_stack_ffffff38);
      if (bVar2) {
        (**(code **)(**(int **)(in_stack_00000018 + 0x6c) + 4))();
        CGameCtnApp::SNationConfig::~SNationConfig(&stack0xffffff44,in_stack_00000018);
        uStack00000014 = 0xffffffff;
        ppuStack_8c = TiXmlDocument::vftable;
        if (puStack_58 != &DAT_00d72f38) {
          operator_delete__(puStack_58);
        }
        TiXmlNode::~TiXmlNode((TiXmlNode *)&ppuStack_8c,(TiXmlNode *)pTVar6);
        ExceptionList = in_stack_00000010;
        return 1;
      }
      pcStack_ac = (char *)(iStack_54 + 8);
      if (pcStack_ac == (char *)0x0) {
        iStack_a8 = 0;
      }
      else {
        pcVar7 = pcStack_ac;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        iStack_a8 = (int)pcVar7 - (iStack_54 + 9);
      }
      CFastStringInt::CFastStringInt(&uStack_90,(CFastStringInt *)&pcStack_ac,in_stack_ffffff3c);
      uStack_98 = extraout_EAX_00[1];
      uStack_94 = *extraout_EAX_00;
      in_stack_ffffff38 = (CFastStringInt *)&pcStack_a0;
      uStack_90 = 0;
      pcStack_a0 = "Could not save .xml : %1";
      uStack_9c = 0x18;
      CFastStringInt::SetCompose
                (&stack0xffffff50,in_stack_ffffff38,(SStringParam *)&uStack_98,pSVar8);
      CGameCtnApp::SNationConfig::~SNationConfig(auStack_88,pSVar9);
      if (DAT_00d71e54 != 0) {
        DAT_00d71e54 = 0;
        *DAT_00d71e58 = 0;
      }
      pCVar5 = CFastString::operator<<
                         ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)&iStack_a8,
                          (char *)&lpOutputString_00b2bcc4);
      CFastString::operator<<((CFastString *)pCVar5,in_stack_ffffff48,in_stack_ffffff4c);
      CClassicLog::ConsoleAddLogString(1,(CFastString *)&DAT_00d71e54);
      CGameCtnApp::SNationConfig::~SNationConfig(&pcStack_a0,in_stack_ffffff50);
    }
  }
  ppuStack_8c = TiXmlDocument::vftable;
  uStack00000014 = 0xffffffff;
  if (puStack_58 != &DAT_00d72f38) {
    operator_delete__(puStack_58);
  }
  TiXmlNode::~TiXmlNode((TiXmlNode *)&ppuStack_8c,(TiXmlNode *)in_stack_ffffff38);
  ExceptionList = in_stack_00000010;
  return 0;
}
}

// =================================================
// Function: CSystemXmlTools::XmlToNod
// =================================================
CMwNod * __cdecl CSystemXmlTools::XmlToNod(CSystemFid *param_1)
{
{
  bool bVar1;
  char *pcVar2;
  TiXmlDocument *pTVar3;
  TiXmlElement *pTVar4;
  CMwClassInfo *pCVar5;
  CPlugFileGpuBuilder *pCVar6;
  CFastString *this;
  CFastStringInt *unaff_EBP;
  void *unaff_retaddr;
  TiXmlNode *in_stack_00000010;
  TiXmlDocument *pTVar7;
  CSystemFid *pCVar8;
  CFastStringInt *pCVar9;
  TiXmlEncoding TVar10;
  char *pcVar11;
  TiXmlNode *pTVar12;
  SHeaderCommunity *pSVar13;
  CPlugFileGpuBuilder *pCVar14;
  char *pcVar15;
  undefined **ppuStack_64;
  TiXmlDocument aTStack_60 [4];
  TiXmlDocument aTStack_5c [4];
  TiXmlNode aTStack_58 [12];
  undefined **appuStack_4c [4];
  int iStack_3c;
  undefined4 *puStack_30;
  undefined4 *puStack_18;
  undefined4 uStack_14;
  TiXmlNode *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a82b50;
  local_c = ExceptionList;
  pcVar2 = (char *)(DAT_00cca150 ^ (uint)&stack0xffffff8c);
  ExceptionList = &local_c;
  pTVar12 = (TiXmlNode *)0x0;
  TVar10 = 1;
  pCVar8 = param_1;
  pTVar3 = (TiXmlDocument *)(**(code **)**(undefined4 **)(param_1 + 0x6c))();
  if (pTVar3 != (TiXmlDocument *)0x0) {
    TiXmlDocument::TiXmlDocument(aTStack_60,(TiXmlDocument *)pCVar8);
    pCVar9 = (CFastStringInt *)0x0;
    local_c = (TiXmlNode *)0x0;
    pTVar7 = pTVar3;
    bVar1 = TiXmlDocument::LoadFile_Gbx(aTStack_5c,pTVar3,(CClassicBuffer *)0x0,TVar10);
    if (bVar1) {
      pcVar11 = (char *)0x42d8b8;
      pTVar4 = TiXmlNode::FirstChildElement(aTStack_58,pTVar12,pcVar2);
      pcVar2 = (char *)0x42d8be;
      pCVar5 = XmlGetClassInfo(pTVar4);
      if (pCVar5 != (CMwClassInfo *)0x0) {
        pSVar13 = (SHeaderCommunity *)0x42d90c;
        pTVar12 = (TiXmlNode *)(**(code **)(pCVar5 + 0x1c))();
        local_c = pTVar12;
        if (pTVar12 != (TiXmlNode *)0x0) {
          pCVar14 = (CPlugFileGpuBuilder *)0x0;
          uStack_14 = CONCAT31(uStack_14._1_3_,1);
          pcVar15 = PTR_DAT_00bbf7dc;
          pTVar4 = TiXmlNode::FirstChildElement((TiXmlNode *)&ppuStack_64,pTVar12,&stack0xffffff8c);
          XmlToNodParams(pTVar4,(CMwNod *)pTVar7,pCVar9);
          if (unaff_EBP != (CFastStringInt *)0x0) {
            pCVar6 = (CPlugFileGpuBuilder *)(iStack_3c + 8);
            if (pCVar6 == (CPlugFileGpuBuilder *)0x0) {
              pCVar6 = (CPlugFileGpuBuilder *)&DAT_00b304c0;
            }
            CFastString::CFastString
                      ((CFastString *)&ppuStack_64,(CFastString *)"while loading xml ",pcVar11);
            puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
            pCVar6 = CFastString::operator<<(this,pCVar6,pcVar2);
            OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar6);
            uStack_4 = CONCAT31(uStack_4._1_3_,4);
            CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(aTStack_5c,pSVar13);
            if (DAT_00d71e54 != 0) {
              DAT_00d71e54 = 0;
              *DAT_00d71e58 = 0;
            }
            pCVar6 = CFastString::operator<<
                               ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)aTStack_60,
                                (char *)&lpOutputString_00b2bcc4);
            CFastString::operator<<((CFastString *)pCVar6,pCVar14,pcVar15);
            CClassicLog::ConsoleAddLogString(1,(CFastString *)&DAT_00d71e54);
            OnAccessViolation_ConcatToCrashFileName(unaff_EBP);
            pTVar12 = in_stack_00000010;
          }
          (**(code **)(**(int **)(param_1 + 0x6c) + 4))();
          CGameCtnApp::SNationConfig::~SNationConfig(aTStack_60,(SNationConfig *)param_1);
          appuStack_4c[0] = TiXmlDocument::vftable;
          if (puStack_18 != &DAT_00d72f38) {
            operator_delete__(puStack_18);
          }
          TiXmlNode::~TiXmlNode((TiXmlNode *)appuStack_4c,(TiXmlNode *)pTVar3);
          ExceptionList = unaff_retaddr;
          return (CMwNod *)pTVar12;
        }
      }
    }
    ppuStack_64 = TiXmlDocument::vftable;
    uStack_14 = 0xffffffff;
    if (puStack_30 != &DAT_00d72f38) {
      operator_delete__(puStack_30);
    }
    TiXmlNode::~TiXmlNode((TiXmlNode *)&ppuStack_64,(TiXmlNode *)pTVar7);
  }
  ExceptionList = puStack_18;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CSystemXmlTools::XmlToNodClassId
// =================================================
ulong __cdecl CSystemXmlTools::XmlToNodClassId(CSystemFid *param_1)
{
{
  bool bVar1;
  TiXmlDocument *pTVar2;
  int iVar3;
  TiXmlDocument *pTVar4;
  TiXmlElement *pTVar5;
  char *unaff_EBX;
  CMwClassInfo *pCVar6;
  TiXmlNode *unaff_ESI;
  ulong uVar7;
  TiXmlEncoding unaff_EDI;
  CSystemFidFile *pCVar8;
  TiXmlDocument aTStack_54 [4];
  TiXmlDocument aTStack_50 [4];
  undefined **appuStack_4c [13];
  undefined4 *puStack_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a828c8;
  local_c = ExceptionList;
  pTVar2 = (TiXmlDocument *)(DAT_00cca150 ^ (uint)&stack0xffffffa0);
  ExceptionList = &local_c;
  pCVar8 = (CSystemFidFile *)0xb00a000;
  iVar3 = (**(code **)(*(int *)param_1 + 0x10))();
  if ((iVar3 != 0) &&
     (iVar3 = CSystemFidFile::OSCheckIfExists((CSystemFidFile *)param_1,pCVar8), iVar3 == 0)) {
    ExceptionList = local_c;
    return 0xffffffff;
  }
  pTVar4 = (TiXmlDocument *)(**(code **)**(undefined4 **)(param_1 + 0x6c))(param_1,1,0);
  if (pTVar4 == (TiXmlDocument *)0x0) {
    ExceptionList = local_c;
    return 0xffffffff;
  }
  TiXmlDocument::TiXmlDocument(aTStack_54,pTVar2);
  pCVar6 = (CMwClassInfo *)0x0;
  bVar1 = TiXmlDocument::LoadFile_Gbx(aTStack_50,pTVar4,(CClassicBuffer *)0x0,unaff_EDI);
  if (bVar1) {
    pTVar5 = TiXmlNode::FirstChildElement((TiXmlNode *)appuStack_4c,unaff_ESI,unaff_EBX);
    pCVar6 = XmlGetClassInfo(pTVar5);
  }
  (**(code **)(**(int **)(param_1 + 0x6c) + 4))();
  uVar7 = 0xffffffff;
  if (pCVar6 != (CMwClassInfo *)0x0) {
    uVar7 = *(ulong *)(pCVar6 + 4);
  }
  appuStack_4c[0] = TiXmlDocument::vftable;
  if (puStack_18 != &DAT_00d72f38) {
    operator_delete__(puStack_18);
  }
  TiXmlNode::~TiXmlNode((TiXmlNode *)appuStack_4c,(TiXmlNode *)param_1);
  ExceptionList = (void *)0x0;
  return uVar7;
}
}

// =================================================
// Function: CSystemXmlTools::XmlToNodParam
// =================================================
int __cdecl
CSystemXmlTools::XmlToNodParam(TiXmlElement *param_1,CMwNod *param_2,CFastStringInt *param_3)
{
{
  CMwId CVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *extraout_EAX;
  TiXmlDocument *pTVar4;
  CFastStringInt *extraout_EAX_00;
  SCasterCat *pSVar5;
  CSystemFid *pCVar6;
  EConvertMethod *extraout_EAX_01;
  CFastString *pCVar7;
  undefined4 *extraout_EAX_02;
  TiXmlElement *this;
  undefined3 extraout_var;
  SStringParam *extraout_EDX;
  SMwParamInfo *unaff_EBX;
  CFastString *unaff_ESI;
  CMwStack *pCVar8;
  ulong unaff_EDI;
  void *in_stack_00000010;
  void *in_stack_00000014;
  SStringParam *pSVar9;
  char *in_stack_fffffe7c;
  SFastTokenInt *pSVar10;
  CMwStack *in_stack_fffffe80;
  char *pcVar11;
  CFastStringInt *pCVar12;
  SStringParam *pSVar13;
  SNationConfig *pSVar14;
  SHeaderCommunity *pSVar15;
  CMwStack *pCVar16;
  CMwNod *in_stack_fffffe88;
  CFastString *in_stack_fffffe8c;
  CFastStringInt *in_stack_fffffe90;
  ulong uVar17;
  CMwStack *in_stack_fffffe94;
  undefined *puVar18;
  CMwNod *in_stack_fffffe98;
  undefined *puVar19;
  CMwStack *in_stack_fffffe9c;
  CMwNod *in_stack_fffffea0;
  CMwNod *in_stack_fffffea4;
  char cVar20;
  CMwStack *in_stack_fffffeac;
  CMwNod *pCVar21;
  char *in_stack_fffffeb0;
  CMwStack *local_14c;
  undefined4 local_148;
  CFastStringInt aCStack_144 [4];
  int local_140;
  EConvertMethod local_13c;
  EConvertMethod local_138;
  undefined4 local_134;
  undefined *local_130;
  CMwNod *local_12c;
  undefined4 local_128;
  int iStack_124;
  CMwNod aCStack_120 [4];
  int local_11c;
  CMwNod local_118 [4];
  int local_114;
  int local_110;
  CFastStringInt aCStack_10c [4];
  int iStack_108;
  undefined4 uStack_104;
  int iStack_100;
  undefined4 local_fc;
  undefined4 local_f8;
  wchar_t *local_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined *puStack_e8;
  CMwStack aCStack_e0 [4];
  CMwStack aCStack_dc [4];
  CMwStack aCStack_d8 [4];
  CMwStack aCStack_d4 [4];
  int local_d0;
  int local_cc [2];
  CMwStack aCStack_c4 [4];
  CMwNod aCStack_c0 [4];
  int *piStack_bc;
  uint local_b8;
  CMwParam *pCStack_b4;
  int *piStack_b0;
  byte local_ac;
  int aiStack_a8 [2];
  int iStack_a0;
  uint uStack_9c;
  int iStack_94;
  int iStack_8c;
  int iStack_84;
  CMwStack *pCStack_80;
  CMwNod *pCStack_78;
  CFastString *pCStack_74;
  CMwStack aCStack_24 [4];
  CMwNod *pCStack_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00a82ad3;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  pSVar13 = (SStringParam *)0x0;
  CMwStack::CMwStack((CMwStack *)&local_140,(CMwStack *)(DAT_00cca150 ^ (uint)&stack0xfffffe70),
                     unaff_EDI);
  iVar2 = ComputeStackAndParamInfo
                    ((char *)(*(int *)(param_1 + 0x20) + 8),(CMwNod *)&local_d0,
                     (CMwStack *)unaff_ESI,unaff_EBX);
  if (iVar2 == 0) {
    pcVar3 = (char *)(*(int *)(param_1 + 0x20) + 8);
    if (pcVar3 != (char *)0x0) {
      do {
        cVar20 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar20 != '\0');
    }
    CFastStringInt::CFastStringInt
              (&stack0xfffffe8c,(CFastStringInt *)&stack0xfffffe84,(SStringParam *)unaff_ESI);
    local_14c = *(CMwStack **)param_3;
    local_148 = 0;
    CFastStringInt::SetCompose
              (param_3,(CFastStringInt *)&stack0xfffffe98,(SStringParam *)&stack0xfffffeb0,
               (SStringParamInt *)&stack0xfffffea4);
    if (in_stack_fffffe94 != (CMwStack *)PTR_DAT_00bbf7dc) {
      if (((byte)in_stack_fffffe94[-1] & 0x80) == 0) {
        operator_delete__(in_stack_fffffe94 + -2);
      }
      else {
        operator_delete__(in_stack_fffffe94 + -4);
      }
    }
  }
  else {
    if (((local_b8 & 0x400000) == 0) && (local_cc[0] != 0x1001000)) {
      pcVar3 = (char *)(*(int *)(param_1 + 0x20) + 8);
      if (pcVar3 != (char *)0x0) {
        do {
          cVar20 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar20 != '\0');
      }
      CFastStringInt::CFastStringInt
                (&local_11c,(CFastStringInt *)&stack0xfffffe94,(SStringParam *)unaff_ESI);
      local_14c = *(CMwStack **)param_3;
      local_148 = 0;
      CFastStringInt::SetCompose
                (param_3,(CFastStringInt *)&stack0xfffffe90,(SStringParam *)&stack0xfffffeb0,
                 (SStringParamInt *)&stack0xfffffea4);
      pCVar21 = local_118;
    }
    else {
      if (local_d0 == 5) {
        pcVar3 = TiXmlElement::Attribute
                           (param_1,(TiXmlElement *)"Action",(char *)unaff_ESI,(int *)unaff_EBX);
        if ((pcVar3 != (char *)0x0) &&
           (iVar2 = XmlParamActionGet(in_stack_fffffe7c,(EXmlParamAction)in_stack_fffffe80),
           iVar2 == 0)) {
          SStringParam::SStringParam(&local_114,extraout_EDX,in_stack_fffffe7c);
          CFastStringInt::CFastStringInt
                    (&local_148,(CFastStringInt *)&local_110,(SStringParam *)in_stack_fffffe80);
          local_138 = *(EConvertMethod *)(param_3 + 4);
          local_14c = (CMwStack *)*extraout_EAX;
          local_134 = *(undefined4 *)param_3;
          local_148 = 0;
          local_130 = (undefined *)0x0;
          SStringParam::SStringParam
                    (&stack0xfffffea4,(SStringParam *)"%1Unknown Action attribute : %2\r\n",
                     (char *)pSVar13);
          CFastStringInt::SetCompose
                    (param_3,(CFastStringInt *)&stack0xfffffea8,(SStringParam *)&local_134,
                     (SStringParamInt *)&local_14c);
          pCVar21 = (CMwNod *)&local_140;
          goto LAB_0042d652;
        }
        if (*(int **)(param_1 + 0x18) == (int *)0x0) {
LAB_0042cebe:
          in_stack_fffffea4 = CMwNod::CreateByMwClassId(*(ulong *)(uStack_9c + 4));
        }
        else {
          pSVar9 = (SStringParam *)0x42cc94;
          iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x2c))();
          if (iVar2 == 0) goto LAB_0042cebe;
          pCVar21 = (CMwNod *)0x0;
          in_stack_00000014 = (void *)CONCAT31(in_stack_00000014._1_3_,4);
          in_stack_fffffe88 = (CMwNod *)0x42ccbb;
          puVar19 = PTR_DAT_00bbf7dc;
          iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x2c))();
          SStringParam::SStringParam
                    (&stack0xfffffeac,(SStringParam *)(*(int *)(iVar2 + 0x20) + 8),(char *)unaff_ESI
                    );
          CFastStringInt::SetString(&stack0xfffffe98,(CFastStringInt *)&stack0xfffffeb0,pSVar9);
          iVar2 = CSystemFileName::IsValidShortFileName((CFastStringInt *)&stack0xfffffe9c);
          if (iVar2 == 0) {
LAB_0042cdaf:
            pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(DAT_00d73300 + 0x20),
                                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                                (ulong)in_stack_fffffe80);
            pcVar11 = (char *)0x1;
            pCVar12 = (CFastStringInt *)&stack0xfffffea4;
            pcVar3 = (char *)0x0;
            pCVar6 = CSystemEngine::FindFid
                               (*(CSystemEngine **)pSVar5,(CSystemFids *)0x0,pCVar12,1,
                                (EFindWay)pSVar13);
            if (pCVar6 == (CSystemFid *)0x0) {
              pSVar14 = (SNationConfig *)0x42ce3a;
              iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x2c))();
              SStringParam::SStringParam
                        (&stack0xfffffeb0,(SStringParam *)(*(int *)(iVar2 + 0x20) + 8),pcVar3);
              CFastStringInt::CFastStringInt
                        (&stack0xfffffea8,(CFastStringInt *)&local_14c,(SStringParam *)pCVar12);
              local_13c = extraout_EAX_01[1];
              local_138 = *extraout_EAX_01;
              uStack_104 = *(undefined4 *)param_3;
              iStack_108 = *(int *)(param_3 + 4);
              local_134 = 0;
              iStack_100 = 0;
              SStringParam::SStringParam
                        (&local_110,(SStringParam *)"%1File not found : %2\r\n",pcVar11);
              CFastStringInt::SetCompose
                        (param_3,aCStack_10c,(SStringParam *)&uStack_104,
                         (SStringParamInt *)&local_138);
              CGameCtnApp::SNationConfig::~SNationConfig(&stack0xfffffeb0,pSVar14);
              pCVar21 = (CMwNod *)&stack0xfffffea8;
              goto LAB_0042d652;
            }
          }
          else {
            pTVar4 = TiXmlNode::GetDocument((TiXmlNode *)param_1,(TiXmlNode *)in_stack_fffffe80);
            if ((SStringParam *)(*(int *)(pTVar4 + 0x20) + 8) == (SStringParam *)0x0)
            goto LAB_0042cdaf;
            uVar17 = 0;
            param_2 = (CMwNod *)CONCAT31(param_2._1_3_,5);
            puVar18 = PTR_DAT_00bbf7dc;
            SStringParam::SStringParam
                      (&local_148,(SStringParam *)(*(int *)(pTVar4 + 0x20) + 8),
                       (char *)in_stack_fffffe80);
            CFastStringInt::CFastStringInt(aCStack_10c,aCStack_144,pSVar13);
            in_stack_fffffe80 = (CMwStack *)extraout_EAX_00;
            CSystemFileName::ExtractFullPathName(extraout_EAX_00,(CFastStringInt *)&stack0xfffffe98)
            ;
            in_stack_00000010 = (void *)CONCAT31(in_stack_00000010._1_3_,5);
            CGameCtnApp::SNationConfig::~SNationConfig
                      (&iStack_108,(SNationConfig *)in_stack_fffffe88);
            local_128 = 0;
            local_130 = puVar19;
            local_12c = pCVar21;
            CFastStringInt::Concat
                      (&stack0xfffffe9c,(CFastStringInt *)&local_130,
                       (SStringParam *)in_stack_fffffe8c);
            pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(DAT_00d73300 + 0x20),
                                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                                uVar17);
            in_stack_fffffe8c = (CFastString *)&stack0xfffffea4;
            in_stack_fffffe88 = (CMwNod *)0x0;
            pSVar13 = (SStringParam *)0x42cd98;
            pCVar6 = CSystemEngine::FindFid
                               (*(CSystemEngine **)pSVar5,(CSystemFids *)0x0,
                                (CFastStringInt *)in_stack_fffffe8c,0,(EFindWay)puVar18);
            CGameCtnApp::SNationConfig::~SNationConfig
                      (&stack0xfffffea8,(SNationConfig *)in_stack_fffffe98);
            if (pCVar6 == (CSystemFid *)0x0) goto LAB_0042cdaf;
          }
          iVar2 = CMwNod::StaticMwIsKindOf(*(ulong *)(iStack_a0 + 4),0xb00a000);
          if (iVar2 == 0) {
            CSystemArchiveNod::LoadFromFid((CMwNod **)&stack0xfffffea0,pCVar6,7);
            in_stack_00000010 = (void *)((uint)in_stack_00000010 & 0xffffff00);
            CGameCtnApp::SNationConfig::~SNationConfig
                      (&stack0xfffffea8,(SNationConfig *)in_stack_fffffe88);
          }
          else {
            in_stack_00000010 = (void *)((uint)in_stack_00000010 & 0xffffff00);
            CGameCtnApp::SNationConfig::~SNationConfig
                      (&stack0xfffffea8,(SNationConfig *)in_stack_fffffe88);
          }
        }
        iVar2 = XmlToNodParams(param_1,in_stack_fffffea4,param_3);
        if (iVar2 != 0) {
          uVar17 = CMwNod::Param_Set(param_2,aCStack_120,(CFastString *)in_stack_fffffea4,
                                     (CFastStringInt *)in_stack_fffffe8c);
          pCVar16 = (CMwStack *)&local_11c;
          if (uVar17 == 0) {
            CMwStack::~CMwStack(pCVar16,(CMwStack *)0x42cf1d);
            ExceptionList = in_stack_00000014;
            return 1;
          }
          goto LAB_0042d666;
        }
        goto LAB_0042d65b;
      }
      local_13c = 0;
      pCVar7 = (CFastString *)
               TiXmlElement::Attribute
                         (param_1,(TiXmlElement *)&DAT_00b3043c,(char *)unaff_ESI,(int *)unaff_EBX);
      if (pCVar7 == (CFastString *)0x0) {
LAB_0042cf85:
        cVar20 = '\0';
      }
      else {
        CFastString::CFastString((CFastString *)&stack0xfffffe8c,pCVar7,in_stack_fffffe7c);
        unaff_EBX = (SMwParamInfo *)&local_130;
        unaff_ESI = (CFastString *)&stack0xfffffe90;
        in_stack_fffffe98 = (CMwNod *)0x1;
        iVar2 = GmUnit::ConvertMethodGet(unaff_ESI,(EConvertMethod *)unaff_EBX,param_3);
        cVar20 = '\x01';
        if (iVar2 != 0) goto LAB_0042cf85;
      }
      if (((uint)in_stack_fffffe98 & 1) != 0) {
        CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                  (&stack0xfffffe90,(SHeaderCommunity *)in_stack_fffffe80);
      }
      if (cVar20 == '\0') {
        pSVar10 = (SFastTokenInt *)0x42d02c;
        iVar2 = (**(code **)(*piStack_bc + 0xac))();
        if (iVar2 != 0) {
          if ((*(int **)(param_1 + 0x18) != (int *)0x0) &&
             (iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x2c))(), iVar2 != 0)) {
            pSVar15 = (SHeaderCommunity *)0x1013000;
            iVar2 = (**(code **)(*(int *)pCStack_b4 + 0x10))();
            if (iVar2 == 0) {
              param_3 = (CFastStringInt *)CONCAT31(param_3._1_3_,0xc);
              iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x2c))();
              pCVar12 = (CFastStringInt *)0x42d11e;
              SStringParam::SStringParam
                        (&stack0xfffffeb0,(SStringParam *)(*(int *)(iVar2 + 0x20) + 8),
                         (char *)pSVar15);
              pSVar15 = (SHeaderCommunity *)0x42d12c;
              CFastStringInt::SetUtf8
                        (&stack0xfffffe98,(CFastStringInt *)&local_14c,
                         (SStringParam *)in_stack_fffffe88);
              in_stack_fffffe88 = (CMwNod *)0x1013000;
              pSVar14 = (SNationConfig *)0x42d13f;
              iVar2 = (**(code **)(*piStack_b0 + 0x10))();
              if (iVar2 != 0) {
                GmUnit::ConvertRealString(local_138,(CFastStringInt *)&stack0xfffffe88);
              }
              CFastString::CFastString
                        ((CFastString *)&stack0xfffffe98,
                         (CFastString *)(*(int *)(param_1 + 0x20) + 8),(char *)unaff_EBX);
              CMwNod::Param_Set((CMwNod *)0x0,(CMwNod *)&stack0xfffffe9c,
                                (CFastString *)&stack0xfffffe8c,pCVar12);
              CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xfffffea0,pSVar15);
              CGameCtnApp::SNationConfig::~SNationConfig(&stack0xfffffe94,pSVar14);
            }
            else {
              param_3 = (CFastStringInt *)CONCAT31(param_3._1_3_,0xb);
              pCVar12 = (CFastStringInt *)0x42d089;
              puVar19 = PTR_DAT_00bbf7d8;
              iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x2c))();
              SStringParam::SStringParam
                        (&stack0xfffffea0,(SStringParam *)(*(int *)(iVar2 + 0x20) + 8),
                         (char *)unaff_ESI);
              CFastString::SetString
                        ((CFastString *)&stack0xfffffe88,(CFastStringInt *)&stack0xfffffea4,
                         (SStringParam *)unaff_EBX);
              iVar2 = CFastString::GetReal
                                ((CFastString *)&stack0xfffffe8c,(CFastString *)&stack0xfffffe94,
                                 (float *)pSVar10);
              if (iVar2 != 0) {
                GmUnit::ConvertReal((EConvertMethod)local_130,(float)puVar19);
                CMwNod::Param_Set((CMwNod *)0x0,(CMwNod *)&local_12c,(CFastString *)&stack0xfffffe98
                                  ,pCVar12);
              }
              CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xfffffe94,pSVar15);
            }
          }
LAB_0042d191:
          CMwStack::~CMwStack((CMwStack *)&iStack_124,(CMwStack *)in_stack_fffffe88);
          ExceptionList = param_3;
          return 1;
        }
        pCVar16 = (CMwStack *)0x42d1cc;
        iVar2 = CMwParam::IsIndexed(pCStack_b4,(CMwParam *)in_stack_fffffe88);
        if (iVar2 != 0) {
          iStack_108 = local_11c + -1;
          if (iStack_94 == 0x24) {
            in_stack_fffffe88 = (CMwNod *)0x42d1f7;
            iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x2c))();
            CFastString::CFastString
                      ((CFastString *)&stack0xfffffe88,(CFastString *)(*(int *)(iVar2 + 0x20) + 8),
                       (char *)unaff_EBX);
            local_f8 = 0;
            local_f4 = (wchar_t *)PTR_DAT_00bbf7d8;
            iStack_100 = 2;
            local_fc = 0xffffffff;
            uStack_f0 = 0;
            uStack_ec = 0;
            puStack_e8 = PTR_DAT_00d34100;
            pCVar8 = (CMwStack *)0x0;
            iVar2 = CFastString::GetNextToken
                              ((CFastString *)&stack0xfffffe8c,(CFastStringInt *)&iStack_100,pSVar10
                              );
            while (iVar2 != 0) {
              pCVar7 = (CFastString *)&stack0xfffffe98;
              iVar2 = CFastString::GetReal
                                ((CFastString *)&local_f4,pCVar7,(float *)in_stack_fffffe80);
              if (iVar2 != 0) {
                pCVar7 = (CFastString *)local_12c;
                in_stack_fffffe9c =
                     (CMwStack *)
                     GmUnit::ConvertReal((EConvertMethod)local_12c,(float)in_stack_fffffe9c);
                local_110 = iStack_124 + -1;
                if ((local_ac & 0x44) == 0) {
                  CMwStack::CMwStack(aCStack_dc,pCVar16,(ulong)in_stack_fffffe88);
                  in_stack_fffffe80 = (CMwStack *)0x42d2f3;
                  CMwStack::CopyFrom(aCStack_d4,(SParam_Set *)aCStack_120,(SParam *)0x1);
                  CMwStack::InsertBaseIndex(aCStack_d4,pCVar8,(ulong)in_stack_fffffe8c);
                  local_b8 = local_cc[0] - 1;
                  in_stack_fffffe8c = (CFastString *)&stack0xfffffea8;
                  in_stack_fffffe88 = (CMwNod *)&local_d0;
                  pCVar16 = (CMwStack *)0x42d325;
                  CMwNod::Param_Set((CMwNod *)0x0,in_stack_fffffe88,in_stack_fffffe8c,
                                    in_stack_fffffe90);
                  in_stack_fffffe90 = (CFastStringInt *)0x42d339;
                  CMwStack::~CMwStack((CMwStack *)local_cc,in_stack_fffffe94);
                }
                else {
                  in_stack_fffffe80 = (CMwStack *)&stack0xfffffe9c;
                  pCVar7 = (CFastString *)&local_128;
                  CMwNod::Param_Add((CMwNod *)0x0,(CMwNod *)pCVar7,in_stack_fffffe80,pCVar16);
                }
                pCVar8 = pCVar8 + 1;
              }
              iVar2 = CFastString::GetNextToken
                                ((CFastString *)&stack0xfffffe8c,(CFastStringInt *)&iStack_100,
                                 (SFastTokenInt *)pCVar7);
            }
            CGameMasterServer::SCriteria::~SCriteria(&local_fc,(SCriteria *)in_stack_fffffe80);
            CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                      (&stack0xfffffe94,(SHeaderCommunity *)pCVar16);
          }
          else {
            in_stack_fffffe88 = (CMwNod *)0x42d37b;
            for (this = TiXmlNode::FirstChildElement
                                  ((TiXmlNode *)param_1,(TiXmlNode *)in_stack_fffffe8c,
                                   (char *)in_stack_fffffe90); this != (TiXmlElement *)0x0;
                this = TiXmlNode::NextSiblingElement
                                 ((TiXmlNode *)this,(TiXmlNode *)in_stack_fffffeac,in_stack_fffffeb0
                                 )) {
              pCStack_80 = (CMwStack *)0x0;
              pCVar16 = (CMwStack *)0x0;
              pCVar12 = (CFastStringInt *)PTR_DAT_00bbf7dc;
              if (iStack_8c != 5) {
                if (*(int **)(this + 0x18) != (int *)0x0) {
                  iVar2 = (**(code **)(**(int **)(this + 0x18) + 0x2c))();
                  pCVar21 = pCStack_78;
                  if (iVar2 != 0) {
                    iVar2 = (**(code **)(**(int **)(this + 0x18) + 0x2c))();
                    SStringParam::SStringParam
                              (&local_140,(SStringParam *)(*(int *)(iVar2 + 0x20) + 8),
                               (char *)in_stack_fffffe94);
                    CFastStringInt::SetString
                              (&stack0xfffffea8,(CFastStringInt *)&local_13c,
                               (SStringParam *)in_stack_fffffe98);
                    in_stack_fffffe98 = (CMwNod *)aiStack_a8;
                    in_stack_fffffe94 = (CMwStack *)&stack0xfffffeac;
                    (**(code **)(*(int *)(&PTR_DAT_00bc6508)[iStack_84] + 0xb0))();
                    pCVar21 = pCStack_78;
                  }
LAB_0042d539:
                  pCStack_78 = pCVar21;
                  if (pCStack_80 != (CMwStack *)0x0) {
                    iStack_100 = local_114 + -1;
                    if ((uStack_9c & 0x44) == 0) {
                      CMwStack::CMwStack((CMwStack *)local_cc,in_stack_fffffe94,
                                         (ulong)in_stack_fffffe98);
                      CMwStack::CopyFrom(aCStack_c4,(SParam_Set *)&local_110,(SParam *)0x1);
                      CMwStack::InsertBaseIndex(aCStack_c4,local_14c,(ulong)in_stack_fffffe9c);
                      in_stack_fffffe98 = aCStack_c0;
                      aiStack_a8[0] = (int)piStack_bc + -1;
                      in_stack_fffffe94 = (CMwStack *)0x42d5ce;
                      in_stack_fffffe9c = (CMwStack *)pCStack_74;
                      CMwNod::Param_Set((CMwNod *)0x0,in_stack_fffffe98,pCStack_74,
                                        (CFastStringInt *)in_stack_fffffea0);
                      in_stack_fffffea0 = (CMwNod *)0x42d5e2;
                      CMwStack::~CMwStack((CMwStack *)&piStack_bc,pCVar16);
                    }
                    else {
                      in_stack_fffffe88 = (CMwNod *)0x42d56b;
                      CMwNod::Param_Add((CMwNod *)0x0,local_118,pCStack_80,in_stack_fffffe94);
                    }
                    local_140 = local_140 + 1;
                    goto LAB_0042d5e7;
                  }
                }
                local_f4 = L"Invalid xml param in array";
                uStack_f0 = 0x1a;
                uStack_ec = 1;
                in_stack_fffffe8c = (CFastString *)0x42d64e;
                CFastStringInt::SetString
                          (param_3,(CFastStringInt *)&local_f4,(SStringParam *)in_stack_fffffe94);
LAB_0042d64e:
                pCVar21 = (CMwNod *)&stack0xfffffe98;
                goto LAB_0042d652;
              }
              in_stack_fffffe8c = (CFastString *)0x42d3c8;
              pcVar3 = TiXmlElement::Attribute
                                 (param_1,(TiXmlElement *)&DAT_00b2f0d4,(char *)in_stack_fffffe94,
                                  (int *)in_stack_fffffe98);
              if (pcVar3 == (char *)0x0) {
                in_stack_fffffe98 = *(CMwNod **)(pCStack_80 + 4);
                pCVar21 = CMwNod::CreateByMwClassId((ulong)in_stack_fffffe98);
                in_stack_fffffe88 = (CMwNod *)0x42d4ba;
                in_stack_fffffe8c = (CFastString *)this;
                in_stack_fffffe94 = (CMwStack *)param_3;
                iVar2 = XmlToNodParams(this,pCVar21,param_3);
                if (iVar2 != 0) goto LAB_0042d539;
                goto LAB_0042d64e;
              }
              CMwStack::CMwStack(aCStack_e0,in_stack_fffffe9c,(ulong)in_stack_fffffea0);
              CMwStack::CopyFrom(aCStack_d8,(SParam_Set *)&iStack_108,(SParam *)0x1);
              in_stack_fffffe98 = (CMwNod *)0x42d404;
              CVar1 = CMwId::CreateFromLocalName((char *)&local_13c);
              CMwStack::InsertBaseNameIndex
                        (aCStack_d8,*(CMwStack **)CONCAT31(extraout_var,CVar1),(ulong)pCVar16);
              OnAccessViolation_ConcatToCrashFileName(pCVar12);
              in_stack_fffffea0 = (CMwNod *)aCStack_d4;
              piStack_bc = (int *)(local_d0 + -1);
              in_stack_fffffe9c = (CMwStack *)0x42d458;
              uVar17 = CMwNod::Param_Get((CMwNod *)0x0,in_stack_fffffea0,aCStack_24,
                                         (CMwValueStd *)pCVar12);
              if (uVar17 != 0) {
LAB_0042d60d:
                CMwStack::~CMwStack((CMwStack *)&local_d0,in_stack_fffffeac);
                goto LAB_0042d64e;
              }
              if (pCStack_20 != (CMwNod *)0x0) {
                in_stack_fffffe9c = (CMwStack *)0x42d479;
                in_stack_fffffea0 = (CMwNod *)param_1;
                iVar2 = XmlToNodParams(param_1,pCStack_20,param_3);
                if (iVar2 == 0) goto LAB_0042d60d;
              }
              pCVar12 = (CFastStringInt *)0x42d498;
              CMwStack::~CMwStack((CMwStack *)&local_d0,in_stack_fffffeac);
LAB_0042d5e7:
              CGameCtnApp::SNationConfig::~SNationConfig(&local_148,(SNationConfig *)pCVar12);
            }
          }
          goto LAB_0042d191;
        }
        goto LAB_0042d65b;
      }
      SStringParam::SStringParam(&stack0xfffffeac,(SStringParam *)pCVar7,(char *)in_stack_fffffe80);
      CFastStringInt::CFastStringInt(aCStack_144,(CFastStringInt *)&stack0xfffffeb0,pSVar13);
      iStack_100 = extraout_EAX_02[1];
      local_fc = *extraout_EAX_02;
      local_134 = *(undefined4 *)(param_3 + 4);
      local_130 = *(undefined **)param_3;
      in_stack_00000010 = (void *)CONCAT31(in_stack_00000010._1_3_,10);
      local_f8 = 0;
      local_12c = (CMwNod *)0x0;
      CFastStringInt::SetCompose
                (param_3,(CFastStringInt *)&stack0xfffffea8,(SStringParam *)&local_134,
                 (SStringParamInt *)&iStack_100);
      pCVar21 = (CMwNod *)&local_140;
    }
LAB_0042d652:
    CGameCtnApp::SNationConfig::~SNationConfig(pCVar21,(SNationConfig *)in_stack_fffffe88);
  }
LAB_0042d65b:
  pCVar16 = (CMwStack *)aCStack_120;
LAB_0042d666:
  CMwStack::~CMwStack(pCVar16,(CMwStack *)in_stack_fffffe8c);
  ExceptionList = in_stack_00000010;
  return 0;
}
}

// =================================================
// Function: CSystemXmlTools::XmlToNodParams
// =================================================
int __cdecl
CSystemXmlTools::XmlToNodParams(TiXmlElement *param_1,CMwNod *param_2,CFastStringInt *param_3)
{
{
  TiXmlElement *this;
  int iVar1;
  char *unaff_EBX;
  TiXmlNode *unaff_EBP;
  char *unaff_ESI;
  TiXmlNode *unaff_EDI;
  int iVar2;
  CMwNod *in_stack_00000010;
  CFastStringInt *in_stack_00000014;
  
  if (param_1 == (TiXmlElement *)0x0) {
    return 0;
  }
  iVar2 = 1;
  for (this = TiXmlNode::FirstChildElement((TiXmlNode *)param_1,unaff_EDI,unaff_ESI);
      this != (TiXmlElement *)0x0;
      this = TiXmlNode::NextSiblingElement((TiXmlNode *)this,unaff_EBP,unaff_EBX)) {
    iVar1 = XmlToNodParam(this,in_stack_00000010,in_stack_00000014);
    if (iVar1 == 0) {
      iVar2 = 0;
    }
  }
  return iVar2;
}
}

