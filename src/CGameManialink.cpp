// Class implementation: CGameManialink

// =================================================
// Function: CGameManialink::AddPageToContainer
// =================================================
void __cdecl
CGameManialink::AddPageToContainer(CGameManialinkPage *param_1,CControlFrame *param_2,float param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *this;
  CGameManialinkPage *pCVar2;
  float fVar3;
  CGameManialinkPage *pCVar4;
  
  fVar3 = *(float *)(param_1 + 0x2c);
  pCVar2 = param_1 + 0x30;
  pCVar4 = pCVar2;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           (**(code **)(*(int *)param_2 + 0x1f8))();
  this = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>::
         operator[](param_2 + 0x158,pCVar1,(ulong)param_1);
  GmIso4::SetUScaleTrans(this,(GmIso4 *)pCVar2,fVar3,(GmVec3 *)pCVar4);
  return;
}
}

// =================================================
// Function: CGameManialink::BuildPage
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CGameManialinkPage * __cdecl
CGameManialink::BuildPage(SBuildPageParams *param_1,EErrorCode *param_2)
{
{
  CFastStringInt *pCVar1;
  CGameManialinkPage *pCVar2;
  undefined4 uVar3;
  undefined *puVar4;
  CMwId CVar5;
  CControlBase *pCVar6;
  undefined3 extraout_var;
  CFastStringInt *this;
  CControlFrame *this_00;
  CControlLabel *extraout_EAX;
  int iVar7;
  TiXmlNode *pTVar8;
  char *pcVar9;
  TiXmlElement *pTVar10;
  int *piVar11;
  int *piVar12;
  int *extraout_EAX_00;
  CControlGrid *this_01;
  TiXmlElement *extraout_EAX_01;
  TiXmlElement *pTVar13;
  CControlEntry *pCVar14;
  CControlQuad *this_02;
  TiXmlNode *pTVar15;
  int *extraout_EAX_02;
  SCasterCat *pSVar16;
  ulong uVar17;
  CMwNod *unaff_EBX;
  CMwNod *pCVar18;
  CMwNod *unaff_ESI;
  CMwNod *pCVar19;
  char *pcVar20;
  CFastStringInt *unaff_EDI;
  char *pcVar21;
  bool bVar22;
  undefined1 uStack00000010;
  undefined1 uStack00000018;
  CMwNod *in_stack_0000001c;
  void *in_stack_0000002c;
  undefined4 uStack00000030;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffe0c;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffe10;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffe14;
  SStringParam *in_stack_fffffe18;
  SBuildPageParams *in_stack_fffffe1c;
  SManialinkFormat *in_stack_fffffe20;
  double *in_stack_fffffe24;
  SStringParam *pSVar23;
  TiXmlElement *pTVar24;
  char *in_stack_fffffe28;
  char *in_stack_fffffe2c;
  CControlStyleSheet *pCVar25;
  CControlStyleSheet *in_stack_fffffe30;
  SBuildPageParams *pSVar26;
  CControlStyleSheet *pCVar27;
  SStringParam *in_stack_fffffe38;
  SManialinkFormat *pSVar28;
  TiXmlElement *pTVar29;
  SManialinkFormat *pSVar30;
  CControlBase *pCVar31;
  CControlStyleSheet *pCVar32;
  SManialinkFormat *pSVar33;
  SManialinkFormat *pSVar34;
  CControlLabel *in_stack_fffffe4c;
  int *piStack_1b0;
  CFastStringInt *pCStack_1a8;
  CGameManialinkPage *pCStack_1a4;
  TiXmlElement *local_1a0;
  CControlLabel *local_19c;
  SManialinkFormat *pSStack_198;
  TiXmlElement *pTStack_194;
  CControlGrid *pCStack_190;
  TiXmlNode *pTStack_18c;
  TiXmlNode *pTStack_188;
  CControlGrid *pCStack_184;
  int iStack_180;
  int *piStack_17c;
  int iStack_178;
  undefined4 uStack_174;
  float fStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  int iStack_164;
  SDico aSStack_160 [8];
  SDico aSStack_158 [4];
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  CControlLabel *pCStack_13c;
  SManialinkFormat *pSStack_138;
  int *piStack_120;
  int iStack_11c;
  int *piStack_108;
  int iStack_104;
  int *piStack_f8;
  int iStack_f4;
  undefined4 uStack_f0;
  float fStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_d8;
  float fStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  float fStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  float fStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  float fStack_a4;
  undefined4 uStack_a0;
  undefined4 auStack_9c [2];
  float fStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  SManialinkFormat aSStack_84 [32];
  CMwNod *pCStack_64;
  undefined8 uStack_60;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  CMwNod *pCStack_30;
  undefined4 uStack_28;
  char acStack_18 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00ac0e65;
  local_14 = ExceptionList;
  pCVar6 = (CControlBase *)(DAT_00cca150 ^ (uint)&stack0xfffffe00);
  ExceptionList = &local_14;
  CVar5 = CMwId::CreateFromLocalName(&stack0xfffffe2c);
  pCVar18 = (CMwNod *)0x0;
  local_c = 0;
  DAT_00d6b060 = CControlStyleSheet::GetStyleSheetElem
                           (*(CControlStyleSheet **)(param_1 + 0xc),
                            (CControlStyleSheet *)CONCAT31(extraout_var,CVar5),(CMwId *)0x0,pCVar6);
  local_8 = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(unaff_EDI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (&local_1a0,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_EDI);
  DicoCopy((SDico *)(param_1 + 0x40),(SDico *)&local_19c);
  this = operator_new(0x50);
  if (this == (CFastStringInt *)0x0) {
    in_stack_fffffe30 = (CControlStyleSheet *)0x0;
  }
  else {
    pCVar19 = (CMwNod *)this;
    CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_EBX);
    *(undefined ***)this = CGameManialinkPage::vftable;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              ((CMwNod *)(this + 0x14),in_stack_fffffe0c);
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              ((CMwNod *)(this + 0x20),in_stack_fffffe10);
    *(undefined4 *)(this + 0x2c) = 0;
    *(undefined4 *)(this + 0x3c) = 0;
    *(undefined **)(this + 0x40) = PTR_DAT_00bbf7d8;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              ((CMwNod *)(this + 0x44),in_stack_fffffe14);
    pCVar18 = (CMwNod *)this;
    this = (CFastStringInt *)pCVar19;
  }
  uStack00000010 = 1;
  this_00 = operator_new(0x160);
  uStack00000010 = 3;
  if (this_00 == (CControlFrame *)0x0) {
    local_1a0 = (TiXmlElement *)0x0;
    pCVar19 = (CMwNod *)0x0;
  }
  else {
    CControlFrame::CControlFrame(this_00,(CControlFrame *)in_stack_fffffe18);
    pCVar19 = (CMwNod *)extraout_EAX;
    local_19c = extraout_EAX;
  }
  pSVar30 = *(SManialinkFormat **)(param_1 + 4);
  pTVar15 = *(TiXmlNode **)param_1;
  uStack00000010 = 1;
  CFastString::SetString
            ((CFastString *)(pCVar19 + 0x138),(CFastStringInt *)&stack0xfffffe3c,in_stack_fffffe18);
  (**(code **)(*(int *)pCVar19 + 0x4c))();
  if (pCVar19 != *(CMwNod **)(pCVar18 + 0x2c)) {
    CMwNod::MwAddRef(pCVar19,(CMwNod *)in_stack_fffffe1c);
    if (*(CMwNod **)(pCVar18 + 0x2c) != (CMwNod *)0x0) {
      in_stack_fffffe1c = (SBuildPageParams *)0x721176;
      CMwNod::MwRelease(*(CMwNod **)(pCVar18 + 0x2c),(CMwNod *)in_stack_fffffe20);
    }
    *(CMwNod **)(pCVar18 + 0x2c) = pCVar19;
  }
  SManialinkFormat::SManialinkFormat(&fStack_b0,(SManialinkFormat *)in_stack_fffffe1c);
  fStack_94 = 0.0;
  pCStack_190 = (CControlGrid *)0x3f800000;
  pTStack_18c = (TiXmlNode *)0x3f800000;
  pTStack_188 = (TiXmlNode *)0x3f800000;
  uStack_90 = 0;
  pCStack_184 = (CControlGrid *)0x3f800000;
  uStack_8c = 0;
  uStack_88 = 0;
  uStack_ac = 0x3f800000;
  uStack_a8 = 0x3f800000;
  pTVar13 = *(TiXmlElement **)(param_1 + 0x1c);
  fStack_a4 = 1.0;
  pSVar33 = *(SManialinkFormat **)(param_1 + 0x20);
  uStack00000018 = 4;
  auStack_9c[0] = 1;
  uStack_a0 = 0x3f800000;
  if (*(int *)(param_1 + 0x24) != 0) {
    iVar7 = TiXmlElement::QueryDoubleAttribute
                      (*(TiXmlElement **)(param_1 + 8),(TiXmlElement *)&DAT_00b87500,
                       (char *)&uStack_174,(double *)in_stack_fffffe20);
    if (iVar7 == 0) {
      pSVar33 = (SManialinkFormat *)(float)(double)CONCAT44(uStack_16c,fStack_170);
    }
    in_stack_fffffe20 = (SManialinkFormat *)&fStack_170;
    in_stack_fffffe1c = (SBuildPageParams *)&DAT_00b874f8;
    iVar7 = TiXmlElement::QueryDoubleAttribute
                      (*(TiXmlElement **)(param_1 + 8),(TiXmlElement *)&DAT_00b874f8,
                       (char *)in_stack_fffffe20,in_stack_fffffe24);
    if (iVar7 == 0) {
      piStack_1b0 = (int *)(float)(double)CONCAT44(uStack_168,uStack_16c);
    }
  }
  pCStack_1a4 = (CGameManialinkPage *)0x0;
  *(CControlLabel **)(pCVar18 + 0x30) = in_stack_fffffe4c;
  pCStack_1a8 = (CFastStringInt *)0x0;
  *(int **)(pCVar18 + 0x34) = piStack_1b0;
  *(undefined4 *)(pCVar18 + 0x38) = 0;
  pSVar23 = (SStringParam *)0x72128a;
  pTVar8 = (TiXmlNode *)
           TiXmlNode::FirstChildElement
                     (*(TiXmlNode **)(param_1 + 8),(TiXmlNode *)in_stack_fffffe28,in_stack_fffffe2c)
  ;
  pCVar1 = (CFastStringInt *)PTR_DAT_00bbf7d8;
  pCVar2 = pCStack_1a4;
  uVar3 = in_stack_0000002c;
  do {
    in_stack_0000002c._1_3_ = (undefined3)((uint)uVar3 >> 8);
    PTR_DAT_00bbf7d8 = pCVar1;
    pCStack_1a4 = pCVar2;
    pTStack_18c = pTVar8;
    if (pTVar8 == (TiXmlNode *)0x0) {
      BuildFrameRecurse(param_1,pCVar2,*(TiXmlElement **)(param_1 + 8),
                        *(CControlFrame **)(pCVar2 + 0x2c),(SManialinkFormat *)auStack_9c,
                        (SDico *)&fStack_170);
      ControlClampZRecurse
                (*(CControlContainer **)(pCVar2 + 0x2c),0.0,*(float *)(param_1 + 0x34),
                 *(float *)(param_1 + 0x38));
      uVar17 = CFastBuffer<class_CCrystalFace*>::GetCount
                         ((void *)(*(int *)(pCVar2 + 0x2c) + 0x144),
                          (CFastBuffer<class_CCrystalFace*> *)in_stack_fffffe30);
      *param_2 = (uint)(uVar17 == 0);
      in_stack_0000002c = (void *)CONCAT31(in_stack_0000002c._1_3_,1);
      if (pCStack_64 != (CMwNod *)0x0) {
        CMwNod::MwRelease(pCStack_64,(CMwNod *)this);
      }
      uStack00000030 = 0xffffffff;
      CFastBuffer<struct_CGameManialink::SDicoEntry>::
      ~CFastBuffer<struct_CGameManialink::SDicoEntry>
                (&uStack_168,(CFastBuffer<struct_CGameManialink::SDicoEntry> *)in_stack_fffffe38);
      ExceptionList = in_stack_0000002c;
      return pCVar2;
    }
    pcVar9 = (char *)(*(int *)(pTVar8 + 0x20) + 8);
    iVar7 = 5;
    bVar22 = true;
    pcVar20 = pcVar9;
    pcVar21 = "dico";
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar22 = *pcVar20 == *pcVar21;
      pcVar20 = pcVar20 + 1;
      pcVar21 = pcVar21 + 1;
    } while (bVar22);
    in_stack_0000002c = (void *)uVar3;
    if (bVar22) {
      pCVar25 = (CControlStyleSheet *)0x7212bd;
      pTVar10 = TiXmlNode::FirstChildElement(pTVar8,(TiXmlNode *)in_stack_fffffe30,(char *)this);
      while (pTVar10 != (TiXmlElement *)0x0) {
        iVar7 = 9;
        bVar22 = true;
        pcVar9 = (char *)(*(int *)(pTVar10 + 0x20) + 8);
        pcVar20 = "language";
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar22 = *pcVar9 == *pcVar20;
          pcVar9 = pcVar9 + 1;
          pcVar20 = pcVar20 + 1;
        } while (bVar22);
        if (bVar22) {
          pTVar24 = (TiXmlElement *)&DAT_00b3d3d8;
          in_stack_fffffe20 = (SManialinkFormat *)0x7212f6;
          TiXmlElement::Attribute
                    (pTVar10,(TiXmlElement *)&DAT_00b3d3d8,in_stack_fffffe28,(int *)pCVar25);
          pCVar25 = (CControlStyleSheet *)0x7212ff;
          pTVar8 = (TiXmlNode *)
                   TiXmlNode::FirstChildElement
                             ((TiXmlNode *)pTVar10,(TiXmlNode *)in_stack_fffffe30,(char *)this);
          pTVar29 = pTVar13;
          while (pTVar13 = pTVar10, pTVar8 != (TiXmlNode *)0x0) {
            DicoAddElem((SDico *)in_stack_fffffe20,pTVar24,in_stack_fffffe28);
            pTVar8 = (TiXmlNode *)
                     TiXmlNode::NextSiblingElement
                               (pTVar8,(TiXmlNode *)in_stack_fffffe20,(char *)pTVar24);
            pTVar10 = pTVar29;
          }
        }
        else {
          pTVar24 = (TiXmlElement *)0x72132a;
          DicoAddElem((SDico *)in_stack_fffffe28,(TiXmlElement *)pCVar25,(char *)in_stack_fffffe30);
        }
        in_stack_fffffe1c = (SBuildPageParams *)0x721335;
        pTVar10 = TiXmlNode::NextSiblingElement
                            ((TiXmlNode *)pTVar13,(TiXmlNode *)in_stack_fffffe20,(char *)pTVar24);
        pTVar13 = pTVar10;
      }
    }
    else {
      iVar7 = 0xb;
      bVar22 = true;
      pcVar20 = pcVar9;
      pcVar21 = "background";
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar22 = *pcVar20 == *pcVar21;
        pcVar20 = pcVar20 + 1;
        pcVar21 = pcVar21 + 1;
      } while (bVar22);
      if (bVar22) {
        SManialinkFormat::SManialinkFormat
                  ((void *)((int)&uStack_60 + 4),(SManialinkFormat *)in_stack_fffffe30);
        uStack_144 = 0;
        in_stack_0000002c = (void *)CONCAT31(in_stack_0000002c._1_3_,5);
        uStack_140 = 0;
        pCStack_13c = (CControlLabel *)0x0;
        pSStack_138 = (SManialinkFormat *)0x0;
        uStack_40 = 0;
        uStack_154 = 0x3f800000;
        uStack_150 = 0x3f800000;
        uStack_38 = 0;
        uStack_3c = 0;
        uStack_14c = 0x3f800000;
        uStack_148 = 0x3f800000;
        uStack_34 = 0;
        uStack_54 = 0x3f800000;
        uStack_58 = 0x3f800000;
        uStack_50 = 0x3f800000;
        in_stack_fffffe30 = *(CControlStyleSheet **)(param_1 + 0xc);
        uStack_4c = 0x3f800000;
        uStack_48 = 1;
        in_stack_fffffe28 = (char *)0x72142b;
        pCVar25 = (CControlStyleSheet *)pTVar8;
        ElemModifyManialinkFormat((TiXmlElement *)pTVar8,in_stack_fffffe30,(SManialinkFormat *)this)
        ;
        uStack_28 = _DAT_00b33a54;
        if (pSStack_198 == (SManialinkFormat *)0x0) {
          pCVar25 = (CControlStyleSheet *)MainGridCreate((SBuildPageParams *)in_stack_fffffe28);
          fStack_a4 = 0.0;
          uStack_a0 = 0;
          in_stack_fffffe30 = (CControlStyleSheet *)&fStack_a4;
          auStack_9c[0] = 0;
          in_stack_fffffe28 = (char *)0x72147c;
          pSStack_198 = (SManialinkFormat *)pCVar25;
          (**(code **)(*(int *)pCStack_184 + 0x1f8))();
          pTVar8 = (TiXmlNode *)pTStack_194;
        }
        in_stack_fffffe20 = (SManialinkFormat *)&pCStack_64;
        in_stack_fffffe1c = param_1;
        QuadSetStyle((TiXmlElement *)pTVar8,(CControlBase *)pCStack_1a4,param_1,in_stack_fffffe20,
                     (SDico *)&iStack_178);
        if (pCStack_30 != (CMwNod *)0x0) {
          CMwNod::MwRelease(pCStack_30,(CMwNod *)in_stack_fffffe28);
        }
      }
      else {
        iVar7 = 6;
        bVar22 = true;
        pcVar20 = pcVar9;
        pcVar21 = "music";
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar22 = *pcVar20 == *pcVar21;
          pcVar20 = pcVar20 + 1;
          pcVar21 = pcVar21 + 1;
        } while (bVar22);
        if (bVar22) {
          pCVar25 = (CControlStyleSheet *)&DAT_00b32c4c;
          in_stack_fffffe28 = (char *)0x7214f7;
          piVar11 = (int *)TiXmlElement::Attribute
                                     ((TiXmlElement *)pTVar8,(TiXmlElement *)&DAT_00b32c4c,
                                      (char *)in_stack_fffffe30,(int *)this);
          if (piVar11 != (int *)0x0) {
            piVar12 = piVar11;
            do {
              iVar7 = *piVar12;
              piVar12 = (int *)((int)piVar12 + 1);
            } while ((char)iVar7 != '\0');
            this = (CFastStringInt *)&piStack_120;
            iStack_11c = (int)piVar12 - ((int)piVar11 + 1);
            in_stack_fffffe30 = (CControlStyleSheet *)0x721528;
            piStack_120 = piVar11;
            CFastString::SetString((CFastString *)&pCStack_1a4,this,in_stack_fffffe38);
          }
          puVar4 = PTR_DAT_00d34100;
          CFastString::TrimLeft
                    ((CFastString *)&stack0xfffffe40,(CFastString *)PTR_DAT_00d34100,
                     (char *)in_stack_fffffe1c);
          CFastString::TrimRight
                    ((CFastString *)&stack0xfffffe44,(CFastString *)puVar4,(char *)in_stack_fffffe20
                    );
          in_stack_fffffe20 = (SManialinkFormat *)&pCStack_13c;
          in_stack_fffffe1c = (SBuildPageParams *)0x72156d;
          pCStack_13c = in_stack_fffffe4c;
          pSStack_138 = pSVar33;
          CFastString::SetString
                    ((CFastString *)(piStack_1b0 + 0xf),(CFastStringInt *)in_stack_fffffe20,pSVar23)
          ;
          pCStack_1a8 = pCVar1;
          if (piStack_1b0 != (int *)PTR_DAT_00bbf7d8) {
            piVar11 = (int *)((int)piStack_1b0 + -1);
            if ((*(byte *)((int)piStack_1b0 + -1) & 0x80) != 0) {
              piVar11 = piStack_1b0 + -1;
            }
            in_stack_fffffe20 = (SManialinkFormat *)0x721597;
            operator_delete__(piVar11);
            in_stack_fffffe4c = (CControlLabel *)0x0;
            piStack_1b0 = (int *)PTR_DAT_00bbf7d8;
          }
        }
        else {
          iVar7 = 5;
          bVar22 = true;
          pcVar20 = "line";
          do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            bVar22 = *pcVar9 == *pcVar20;
            pcVar9 = pcVar9 + 1;
            pcVar20 = pcVar20 + 1;
          } while (bVar22);
          if (bVar22) {
            pCStack_184 = operator_new(0x1c0);
            if (pCStack_184 == (CControlGrid *)0x0) {
              in_stack_fffffe4c = (CControlLabel *)0x0;
              piVar11 = (int *)0x0;
            }
            else {
              CControlGrid::CControlGrid(pCStack_184,(CControlGrid *)in_stack_fffffe30);
              piVar11 = extraout_EAX_00;
              piStack_1b0 = extraout_EAX_00;
            }
            (**(code **)(*piVar11 + 0x4c))();
            *(undefined4 *)(piVar11[0x60] + 0x1c) = 0;
            *(undefined4 *)(piVar11[0x60] + 0x20) = 0;
            pCVar25 = (CControlStyleSheet *)&pCStack_64;
            pCStack_190 = _DAT_00b2c060;
            in_stack_fffffe28 = "height";
            piVar11[0x61] = 0;
            piVar11[0x46] = 1;
            iVar7 = TiXmlElement::QueryDoubleAttribute
                              ((TiXmlElement *)pTVar8,(TiXmlElement *)"height",(char *)pCVar25,
                               (double *)in_stack_fffffe30);
            if (iVar7 == 0) {
              pTStack_18c = (TiXmlNode *)(float)uStack_60;
            }
            iStack_180 = 0;
            pTVar10 = TiXmlNode::FirstChildElement
                                (pTVar8,(TiXmlNode *)this,(char *)in_stack_fffffe38);
            while (pTStack_18c = (TiXmlNode *)pTVar10, pTVar10 != (TiXmlElement *)0x0) {
              iVar7 = 5;
              bVar22 = true;
              pcVar9 = (char *)(*(int *)(pTVar10 + 0x20) + 8);
              pcVar20 = "cell";
              do {
                if (iVar7 == 0) break;
                iVar7 = iVar7 + -1;
                bVar22 = *pcVar9 == *pcVar20;
                pcVar9 = pcVar9 + 1;
                pcVar20 = pcVar20 + 1;
              } while (bVar22);
              pSVar28 = (SManialinkFormat *)&uStack_90;
              if (bVar22) {
                SManialinkFormat::SManialinkFormat(&puStack_10,pSVar28);
                ElemModifyManialinkFormat(pTVar10,*(CControlStyleSheet **)(param_1 + 0xc),pSVar30);
                this_01 = operator_new(0x1c0);
                if (this_01 == (CControlGrid *)0x0) {
                  pCStack_1a4 = (CGameManialinkPage *)0x0;
                  pTVar24 = (TiXmlElement *)0x0;
                }
                else {
                  CControlGrid::CControlGrid(this_01,(CControlGrid *)pSVar30);
                  pTVar24 = extraout_EAX_01;
                  local_1a0 = extraout_EAX_01;
                }
                (**(code **)(*(int *)pTVar24 + 0x4c))();
                *(undefined4 *)(*(int *)(pTVar24 + 0x180) + 0x1c) = 0;
                *(undefined4 *)(*(int *)(pTVar24 + 0x180) + 0x20) = 0;
                pTStack_188 = (TiXmlNode *)_DAT_00b2c060;
                iVar7 = TiXmlElement::QueryDoubleAttribute
                                  (pTVar10,(TiXmlElement *)"width",acStack_18,(double *)pSVar30);
                pTVar8 = pTStack_188;
                pTVar10 = local_1a0;
                if (iVar7 == 0) {
                  pCStack_184 = (CControlGrid *)(float)(double)CONCAT44(puStack_10,local_14);
                }
                *(int *)(local_1a0 + 0x194) = iStack_180;
                piStack_108 = (int *)0x3f800000;
                pSVar28 = (SManialinkFormat *)0x3;
                iStack_104 = 0x3f800000;
                *(undefined4 *)(local_1a0 + 0x184) = 0;
                pCVar27 = (CControlStyleSheet *)pTStack_188;
                ControlSetSizeAndAlign
                          ((CControlBase *)pTStack_188,(TiXmlElement *)0x3,(GmVec2 *)0x1,
                           (EAlignHorizontal)pTVar15,(EAlignVertical)pTVar13,(int)pSVar33);
                pCVar25 = (CControlStyleSheet *)&local_c;
                in_stack_fffffe1c = (SBuildPageParams *)0x7217a2;
                in_stack_fffffe20 = (SManialinkFormat *)pTVar8;
                in_stack_fffffe28 = (char *)param_1;
                QuadSetStyle((TiXmlElement *)pTVar8,(CControlBase *)pTVar10,param_1,
                             (SManialinkFormat *)pCVar25,aSStack_160);
                pSVar30 = (SManialinkFormat *)0x7217b0;
                pTVar13 = TiXmlNode::FirstChildElement(pTVar8,pTVar15,(char *)pTVar13);
                pSVar34 = pSVar33;
                pSVar33 = pSStack_198;
                pTVar10 = (TiXmlElement *)pTStack_18c;
                while (local_1a0 = pTVar13, pSStack_198 = pSVar33,
                      pTStack_18c = (TiXmlNode *)pTVar10, pTVar13 != (TiXmlElement *)0x0) {
                  pcVar9 = (char *)(*(int *)(pTVar13 + 0x20) + 8);
                  iVar7 = 5;
                  bVar22 = true;
                  pcVar20 = pcVar9;
                  pcVar21 = "text";
                  do {
                    if (iVar7 == 0) break;
                    iVar7 = iVar7 + -1;
                    bVar22 = *pcVar20 == *pcVar21;
                    pcVar20 = pcVar20 + 1;
                    pcVar21 = pcVar21 + 1;
                  } while (bVar22);
                  if (bVar22) {
                    pTVar24 = pTVar13;
                    pCVar6 = ElemCreateLabel(pTVar13,param_1,(CGameManialinkPage *)pTVar10,
                                             aSStack_158);
                    pCVar27 = (CControlStyleSheet *)&stack0xfffffffc;
                    pTVar10 = *(TiXmlElement **)(param_1 + 0xc);
                    pCVar25 = (CControlStyleSheet *)pTVar13;
                    ControlTextSetStyle((CControlBase *)pTVar13,pTVar10,pCVar27,
                                        (SManialinkFormat *)pTVar24);
                    in_stack_fffffe28 = (char *)0x1;
                    piStack_108 = piStack_17c;
                    iStack_104 = iStack_178;
                    in_stack_fffffe1c = (SBuildPageParams *)0x721834;
                    in_stack_fffffe20 = (SManialinkFormat *)pTVar13;
                    ControlSetSizeAndAlign
                              ((CControlBase *)pTVar13,(TiXmlElement *)0x3,(GmVec2 *)0x1,
                               (EAlignHorizontal)pCVar25,(EAlignVertical)pTVar10,(int)pCVar27);
                    uStack_b4 = 0;
                    local_1a0 = (TiXmlElement *)pCStack_1a4;
                    fStack_b0 = (float)(int)pCStack_1a4;
                    if ((int)pCStack_1a4 < 0) {
                      fStack_b0 = fStack_b0 + _DAT_00c418d0;
                    }
                    uStack_ac = 0;
                    pCVar32 = (CControlStyleSheet *)&uStack_b4;
                    pCVar31 = (CControlBase *)0x72187d;
                    pTVar15 = (TiXmlNode *)pCVar6;
                    (**(code **)(*(int *)pSStack_198 + 0x1f8))();
                    pSVar28 = (SManialinkFormat *)0x721884;
                    CControlBase::RefreshSizeAndAlignment(pCVar6,pCVar31);
                  }
                  else {
                    iVar7 = 6;
                    bVar22 = true;
                    pcVar20 = pcVar9;
                    pcVar21 = "entry";
                    do {
                      if (iVar7 == 0) break;
                      iVar7 = iVar7 + -1;
                      bVar22 = *pcVar20 == *pcVar21;
                      pcVar20 = pcVar20 + 1;
                      pcVar21 = pcVar21 + 1;
                    } while (bVar22);
                    if (bVar22) {
                      pCVar14 = ElemCreateEntry(pTVar10,(CGameManialinkPage *)pSVar34);
                      pCVar32 = (CControlStyleSheet *)&stack0xfffffffc;
                      pTVar24 = *(TiXmlElement **)(param_1 + 0xc);
                      pTVar29 = pTVar13;
                      ControlTextSetStyle((CControlBase *)pTVar13,pTVar24,pCVar32,
                                          (SManialinkFormat *)pTVar10);
                      pCVar27 = (CControlStyleSheet *)0x1;
                      piStack_f8 = piStack_17c;
                      iStack_f4 = iStack_178;
                      in_stack_fffffe28 = (char *)0x7218f5;
                      pCVar25 = (CControlStyleSheet *)pTVar13;
                      ControlSetSizeAndAlign
                                ((CControlBase *)pTVar13,(TiXmlElement *)0x3,(GmVec2 *)0x1,
                                 (EAlignHorizontal)pTVar29,(EAlignVertical)pTVar24,(int)pCVar32);
                      uStack_d8 = 0;
                      local_1a0 = (TiXmlElement *)pCStack_1a4;
                      fStack_d4 = (float)(int)pCStack_1a4;
                      if ((int)pCStack_1a4 < 0) {
                        fStack_d4 = fStack_d4 + _DAT_00c418d0;
                      }
                      uStack_d0 = 0;
                      pCVar32 = (CControlStyleSheet *)&uStack_d8;
                      pCVar6 = (CControlBase *)0x72193e;
                      pTVar15 = (TiXmlNode *)pCVar14;
                      (**(code **)(*(int *)pSStack_198 + 0x1f8))();
                      pSVar28 = (SManialinkFormat *)0x721945;
                      CControlBase::RefreshSizeAndAlignment((CControlBase *)pCVar14,pCVar6);
                    }
                    else {
                      iVar7 = 10;
                      bVar22 = true;
                      pcVar20 = pcVar9;
                      pcVar21 = "fileentry";
                      do {
                        if (iVar7 == 0) break;
                        iVar7 = iVar7 + -1;
                        bVar22 = *pcVar20 == *pcVar21;
                        pcVar20 = pcVar20 + 1;
                        pcVar21 = pcVar21 + 1;
                      } while (bVar22);
                      if (bVar22) {
                        pTVar24 = pTVar13;
                        pCVar14 = ElemCreateFileEntry(pTVar13,(CGameManialinkPage *)pTVar10);
                        pCVar32 = (CControlStyleSheet *)&stack0xfffffffc;
                        pTVar10 = *(TiXmlElement **)(param_1 + 0xc);
                        pCVar27 = (CControlStyleSheet *)pTVar13;
                        ControlTextSetStyle((CControlBase *)pTVar13,pTVar10,pCVar32,
                                            (SManialinkFormat *)pTVar24);
                        piStack_120 = piStack_17c;
                        pCVar25 = (CControlStyleSheet *)0x3;
                        iStack_11c = iStack_178;
                        in_stack_fffffe28 = (char *)pTVar13;
                        ControlSetSizeAndAlign
                                  ((CControlBase *)pTVar13,(TiXmlElement *)0x3,(GmVec2 *)0x1,
                                   (EAlignHorizontal)pCVar27,(EAlignVertical)pTVar10,(int)pCVar32);
                        uStack_cc = 0;
                        local_1a0 = (TiXmlElement *)pCStack_1a4;
                        fStack_c8 = (float)(int)pCStack_1a4;
                        if ((int)pCStack_1a4 < 0) {
                          fStack_c8 = fStack_c8 + _DAT_00c418d0;
                        }
                        uStack_c4 = 0;
                        pCVar32 = (CControlStyleSheet *)&uStack_cc;
                        pCVar6 = (CControlBase *)0x7219fe;
                        pTVar15 = (TiXmlNode *)pCVar14;
                        (**(code **)(*(int *)pSStack_198 + 0x1f8))();
                        pSVar28 = (SManialinkFormat *)0x721a05;
                        CControlBase::RefreshSizeAndAlignment((CControlBase *)pCVar14,pCVar6);
                      }
                      else {
                        iVar7 = 5;
                        bVar22 = true;
                        pcVar20 = pcVar9;
                        pcVar21 = "icon";
                        do {
                          if (iVar7 == 0) break;
                          iVar7 = iVar7 + -1;
                          bVar22 = *pcVar20 == *pcVar21;
                          pcVar20 = pcVar20 + 1;
                          pcVar21 = pcVar21 + 1;
                        } while (bVar22);
                        if ((bVar22) && (*(int *)(param_1 + 0x10) != 0)) {
                          this_02 = ElemCreateQuad(pTVar13,(SBuildPageParams *)pTVar10,
                                                   (CGameManialinkPage *)aSStack_158,
                                                   (SDico *)pSVar34);
                          in_stack_fffffe1c = (SBuildPageParams *)local_1a0;
                          pCVar27 = (CControlStyleSheet *)aSStack_84;
                          in_stack_fffffe28 = (char *)local_1a0;
                          pCVar25 = (CControlStyleSheet *)this_02;
                          pSVar26 = param_1;
                          QuadSetStyle(local_1a0,(CControlBase *)this_02,param_1,
                                       (SManialinkFormat *)pCVar27,aSStack_158);
                          uStack_14c = _DAT_00b3380c;
                          in_stack_fffffe20 = (SManialinkFormat *)0x3;
                          uStack_148 = _DAT_00b3380c;
                          ControlSetSizeAndAlign
                                    ((CControlBase *)in_stack_fffffe1c,(TiXmlElement *)0x3,
                                     (GmVec2 *)0x1,(EAlignHorizontal)in_stack_fffffe28,
                                     (EAlignVertical)pCVar25,(int)pSVar26);
                          uStack_a8 = 0;
                          fStack_a4 = (float)(int)pCStack_1a4;
                          if ((int)pCStack_1a4 < 0) {
                            fStack_a4 = fStack_a4 + _DAT_00c418d0;
                          }
                          uStack_a0 = 0;
                          pCVar32 = (CControlStyleSheet *)&uStack_a8;
                          pCVar6 = (CControlBase *)0x721ad5;
                          pTVar15 = (TiXmlNode *)this_02;
                          (**(code **)(*(int *)pSStack_198 + 0x1f8))();
                          pSVar28 = (SManialinkFormat *)0x721adc;
                          CControlBase::RefreshSizeAndAlignment((CControlBase *)this_02,pCVar6);
                          pTVar13 = (TiXmlElement *)pCStack_1a8;
                        }
                        else {
                          iVar7 = 6;
                          bVar22 = true;
                          pcVar20 = pcVar9;
                          pcVar21 = "audio";
                          do {
                            if (iVar7 == 0) break;
                            iVar7 = iVar7 + -1;
                            bVar22 = *pcVar20 == *pcVar21;
                            pcVar20 = pcVar20 + 1;
                            pcVar21 = pcVar21 + 1;
                          } while (bVar22);
                          if (bVar22) {
LAB_00721b10:
                            if (*(int *)(param_1 + 0x10) != 0) {
                              pCVar27 = (CControlStyleSheet *)0x721b29;
                              pSVar28 = (SManialinkFormat *)pTVar13;
                              pTVar15 = (TiXmlNode *)
                                        ElemCreateMediaPlayer(pTVar13,param_1,aSStack_158,1);
                              uStack_f0 = 0;
                              local_1a0 = (TiXmlElement *)pCStack_1a4;
                              fStack_ec = (float)(int)pCStack_1a4;
                              if ((int)pCStack_1a4 < 0) {
                                fStack_ec = fStack_ec + _DAT_00c418d0;
                              }
                              pCVar32 = (CControlStyleSheet *)&uStack_f0;
                              uStack_e8 = 0;
                              (**(code **)(*(int *)pSStack_198 + 0x1f8))();
                              goto LAB_00721b94;
                            }
                          }
                          else {
                            iVar7 = 6;
                            bVar22 = true;
                            pcVar20 = "video";
                            do {
                              if (iVar7 == 0) break;
                              iVar7 = iVar7 + -1;
                              bVar22 = *pcVar9 == *pcVar20;
                              pcVar9 = pcVar9 + 1;
                              pcVar20 = pcVar20 + 1;
                            } while (bVar22);
                            if (bVar22) goto LAB_00721b10;
                          }
                          pTVar15 = *(TiXmlNode **)(param_1 + 0xc);
                          pCVar32 = (CControlStyleSheet *)aSStack_84;
                          ScanFormatTags((TiXmlElement *)pTVar15,pCVar32,pSVar34);
                        }
                      }
                    }
                  }
LAB_00721b94:
                  pSVar30 = (SManialinkFormat *)0x721b9b;
                  pTVar13 = TiXmlNode::NextSiblingElement
                                      ((TiXmlNode *)pTVar13,pTVar15,(char *)pCVar32);
                  pSVar33 = pSStack_198;
                  pTVar10 = (TiXmlElement *)pTStack_18c;
                }
                uVar17 = CFastBuffer<class_CCrystalFace*>::GetCount
                                   (pSVar33 + 0x144,(CFastBuffer<class_CCrystalFace*> *)pSVar34);
                if (uVar17 == 0) {
                  local_19c = operator_new(0x14c);
                  if (local_19c == (CControlLabel *)0x0) {
                    piVar11 = (int *)0x0;
                  }
                  else {
                    CControlLabel::CControlLabel(local_19c,in_stack_fffffe4c);
                    piVar11 = extraout_EAX_02;
                  }
                  in_stack_fffffe4c = (CControlLabel *)&uStack_b8;
                  piVar11[0x46] = 1;
                  uStack_b8 = 0;
                  uStack_b4 = 0;
                  fStack_b0 = 0.0;
                  (**(code **)(*(int *)pSVar33 + 0x1f8))();
                  (**(code **)(*piVar11 + 0x4c))();
                  (**(code **)(*piVar11 + 0x104))();
                }
                pSVar16 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                    (pSVar33 + 0x1a0,
                                     (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                     (ulong)in_stack_fffffe4c);
                iVar7 = iStack_164;
                *(undefined4 *)pSVar16 = uStack_174;
                fStack_94 = (float)iStack_164;
                if (iStack_164 < 0) {
                  fStack_94 = fStack_94 + _DAT_00c418d0;
                }
                uStack_90 = 0;
                in_stack_fffffe4c = (CControlLabel *)&fStack_94;
                uStack_8c = 0;
                pTVar13 = (TiXmlElement *)0x721c94;
                (**(code **)(*(int *)pTStack_194 + 0x1f8))();
                iStack_180 = iVar7 + 1;
                in_stack_0000002c._1_3_ = (undefined3)((uint)in_stack_0000002c >> 8);
                in_stack_0000002c = (void *)CONCAT31(in_stack_0000002c._1_3_,4);
                if (in_stack_0000001c != (CMwNod *)0x0) {
                  CMwNod::MwRelease(in_stack_0000001c,(CMwNod *)pCVar27);
                }
              }
              else {
                pCVar27 = *(CControlStyleSheet **)(param_1 + 0xc);
                ScanFormatTags((TiXmlElement *)pCVar27,(CControlStyleSheet *)pSVar28,pSVar30);
              }
              pTVar10 = TiXmlNode::NextSiblingElement
                                  ((TiXmlNode *)pTStack_194,(TiXmlNode *)pCVar27,(char *)pSVar28);
            }
            if (pCStack_190 == (CControlGrid *)0x0) {
              pCStack_190 = MainGridCreate((SBuildPageParams *)pSVar30);
              uStack_f0 = 0;
              fStack_ec = 0.0;
              uStack_e8 = 0;
              (**(code **)(*piStack_17c + 0x1f8))();
            }
            pTVar10 = pTStack_194;
            uStack_174 = 0;
            fStack_170 = (float)(int)pTStack_194;
            if ((int)pTStack_194 < 0) {
              fStack_170 = fStack_170 + _DAT_00c418d0;
            }
            in_stack_fffffe38 = (SStringParam *)&uStack_174;
            uStack_16c = 0;
            this = pCStack_1a8;
            (**(code **)(*(int *)pCStack_190 + 0x1f8))();
            in_stack_fffffe30 = (CControlStyleSheet *)0x721d67;
            (**(code **)(*(int *)pCStack_1a8 + 0x1a8))();
            pCStack_1a8 = (CFastStringInt *)(pTVar10 + 1);
          }
          else {
            in_stack_fffffe28 = *(char **)(param_1 + 0xc);
            pCVar25 = (CControlStyleSheet *)auStack_9c;
            ScanFormatTags((TiXmlElement *)in_stack_fffffe28,pCVar25,
                           (SManialinkFormat *)in_stack_fffffe30);
          }
        }
      }
    }
    pSVar23 = (SStringParam *)0x721d92;
    pTVar8 = (TiXmlNode *)
             TiXmlNode::NextSiblingElement
                       ((TiXmlNode *)pTStack_194,(TiXmlNode *)in_stack_fffffe28,(char *)pCVar25);
    pCVar1 = (CFastStringInt *)PTR_DAT_00bbf7d8;
    pCVar2 = pCStack_1a4;
    uVar3 = in_stack_0000002c;
  } while( true );
}
}

