// Class implementation: CGameMasterServer

// =================================================
// Function: CGameMasterServer::AddAbuse
// =================================================
CNetMasterServerRequest * __thiscall
CGameMasterServer::AddAbuse
          (CGameMasterServer *this,CGameMasterServer *param_1,CFastString *param_2,
          CFastStringInt *param_3,CFastStringInt *param_4,CFastStringInt *param_5,
          CSystemPackDesc *param_6,CSystemPackDesc *param_7,CFastStringInt *param_8,CMwId *param_9)
{
{
  CClassicBuffer *pCVar1;
  int iVar2;
  CNetMasterServerRequest *pCVar3;
  int extraout_EAX;
  TiXmlText *extraout_EAX_00;
  CClassicBuffer *this_00;
  uint uVar4;
  SLoadedLight *this_01;
  void *pvVar5;
  CNetMasterServer *pCVar6;
  undefined *puVar7;
  TiXmlNode *unaff_EBX;
  TiXmlNode *unaff_EBP;
  char *unaff_ESI;
  CFastStringInt *unaff_EDI;
  undefined1 uStack0000002c;
  undefined1 uStack00000030;
  void *in_stack_00000034;
  undefined1 uStack00000038;
  undefined1 uStack00000040;
  undefined1 uStack00000044;
  void *in_stack_0000004c;
  undefined1 uStack00000054;
  undefined1 uStack00000058;
  void *in_stack_0000006c;
  undefined1 in_stack_00000074;
  undefined1 in_stack_00000078;
  undefined1 in_stack_00000080;
  void *in_stack_00000084;
  undefined1 in_stack_00000088;
  undefined1 in_stack_00000090;
  undefined1 uStack00000094;
  undefined1 in_stack_00000098;
  undefined1 in_stack_0000009c;
  int in_stack_000000a0;
  int in_stack_000000a4;
  undefined1 in_stack_000000a8;
  undefined1 in_stack_000000ac;
  undefined1 uStack000000b0;
  undefined1 uStack000000b4;
  undefined1 in_stack_000000b8;
  undefined1 in_stack_000000bc;
  undefined1 in_stack_000000c4;
  undefined1 in_stack_000000c8;
  undefined1 in_stack_000000cc;
  undefined1 in_stack_000000d0;
  undefined1 in_stack_000000d4;
  undefined1 in_stack_000000d8;
  undefined1 in_stack_000000dc;
  undefined1 uStack000000e0;
  undefined1 uStack000000e4;
  undefined1 uStack000000e8;
  undefined1 uStack000000ec;
  undefined1 uStack000000f0;
  undefined1 uStack000000f4;
  undefined1 uStack000000f8;
  undefined1 uStack000000fc;
  void *in_stack_00000100;
  undefined4 uStack00000104;
  int in_stack_fffff9a8;
  CFastStringInt *in_stack_fffff9ac;
  char *in_stack_fffff9b0;
  TiXmlNode *in_stack_fffff9b4;
  TiXmlNode *in_stack_fffff9b8;
  int in_stack_fffff9bc;
  CFastStringInt *in_stack_fffff9c0;
  char *in_stack_fffff9c4;
  TiXmlNode *in_stack_fffff9c8;
  TiXmlNode *in_stack_fffff9cc;
  int in_stack_fffff9d0;
  CFastStringInt *in_stack_fffff9d4;
  char *in_stack_fffff9d8;
  TiXmlNode *in_stack_fffff9dc;
  TiXmlNode *in_stack_fffff9e0;
  int in_stack_fffff9e4;
  CFastStringInt *in_stack_fffff9e8;
  char *in_stack_fffff9ec;
  TiXmlNode *in_stack_fffff9f0;
  TiXmlNode *in_stack_fffff9f4;
  CMwStatsValue *in_stack_fffff9f8;
  CFastString *in_stack_fffff9fc;
  CMwStatsValue *pCVar8;
  CFastString *pCVar9;
  CFastStringInt *in_stack_fffffa08;
  char *pcVar10;
  TiXmlNode *in_stack_fffffa14;
  TiXmlElement *in_stack_fffffa18;
  TiXmlNode *in_stack_fffffa1c;
  CFastStringInt *in_stack_fffffa20;
  ulong uVar11;
  CGameMasterServer *pCVar12;
  CClassicBuffer *pCVar13;
  CFastString *in_stack_fffffa28;
  SStringParam *in_stack_fffffa2c;
  CFastStringInt *in_stack_fffffa30;
  char cVar14;
  TiXmlNode *in_stack_fffffa34;
  TiXmlNode *pTVar15;
  TiXmlNode *pTVar16;
  CFastStringInt *pCVar17;
  CFastString *in_stack_fffffa40;
  char *pcVar18;
  CFastStringInt *pCVar19;
  TiXmlNode *pTVar20;
  TiXmlNode *pTVar21;
  TiXmlNode *in_stack_fffffa4c;
  CFastStringInt *pCVar22;
  TiXmlNode *in_stack_fffffa50;
  TiXmlNode *in_stack_fffffa54;
  TiXmlText *pTVar23;
  TiXmlNode *pTVar24;
  TiXmlElement *pTVar25;
  TiXmlNode *in_stack_fffffa60;
  TiXmlElement *in_stack_fffffa64;
  TiXmlNode *in_stack_fffffa68;
  TiXmlElement *in_stack_fffffa6c;
  CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
  *in_stack_fffffa70;
  CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*> *pCVar26;
  TiXmlElement *in_stack_fffffa74;
  TiXmlNode *in_stack_fffffa78;
  TiXmlElement *in_stack_fffffa7c;
  TiXmlNode *in_stack_fffffa80;
  TiXmlElement *in_stack_fffffa84;
  TiXmlNode *pTVar27;
  undefined *in_stack_fffffa8c;
  TiXmlElement *pTVar28;
  TiXmlNode *in_stack_fffffa90;
  TiXmlElement *in_stack_fffffa94;
  TiXmlNode *in_stack_fffffa98;
  TiXmlElement *in_stack_fffffa9c;
  TiXmlText local_558 [4];
  undefined4 local_554;
  undefined *local_550;
  undefined4 local_54c;
  CNetMasterServer *pCStack_548;
  undefined **local_544 [2];
  TiXmlNode local_53c [8];
  TiXmlText aTStack_534 [8];
  TiXmlNode aTStack_52c [4];
  CFastString aCStack_528 [4];
  undefined4 local_524;
  undefined *local_520;
  undefined4 *local_51c [2];
  undefined4 local_514;
  undefined *local_510;
  TiXmlNode local_50c [12];
  undefined **local_500;
  undefined1 local_4fc [4];
  TiXmlNode local_4f8 [8];
  undefined **appuStack_4f0 [2];
  TiXmlNode local_4e8 [12];
  TiXmlNode aTStack_4dc [4];
  TiXmlNode local_4d8 [52];
  TiXmlElement local_4a4 [4];
  TiXmlNode local_4a0 [4];
  TiXmlNode local_49c [4];
  TiXmlElement local_498 [4];
  TiXmlElement local_494 [16];
  TiXmlText local_484 [8];
  TiXmlNode local_47c [4];
  undefined **local_478 [5];
  TiXmlText aTStack_464 [8];
  TiXmlNode aTStack_45c [12];
  undefined **local_450 [4];
  undefined **local_440 [4];
  TiXmlElement aTStack_430 [4];
  TiXmlNode aTStack_42c [4];
  TiXmlNode aTStack_428 [24];
  TiXmlElement local_410 [4];
  TiXmlNode local_40c [4];
  TiXmlNode local_408 [4];
  TiXmlElement local_404 [16];
  TiXmlElement aTStack_3f4 [20];
  TiXmlElement local_3e0 [4];
  TiXmlNode local_3dc [4];
  TiXmlNode local_3d8 [24];
  TiXmlElement aTStack_3c0 [4];
  TiXmlNode aTStack_3bc [4];
  TiXmlNode aTStack_3b8 [4];
  TiXmlElement aTStack_3b4 [16];
  TiXmlElement local_3a4 [36];
  TiXmlText local_380 [4];
  TiXmlNode local_37c [4];
  TiXmlText local_378 [8];
  TiXmlNode local_370 [20];
  TiXmlElement local_35c [40];
  TiXmlText local_334 [8];
  TiXmlNode local_32c [8];
  TiXmlNode local_324 [20];
  undefined **appuStack_310 [18];
  TiXmlText local_2c8 [8];
  TiXmlNode local_2c0 [8];
  undefined **appuStack_2b8 [15];
  TiXmlText local_27c [4];
  undefined **ppuStack_278;
  TiXmlNode local_274 [36];
  undefined **appuStack_250 [2];
  TiXmlNode aTStack_248 [16];
  undefined **appuStack_238 [8];
  undefined **appuStack_218 [8];
  TiXmlElement aTStack_1f8 [8];
  CNetMasterServer aCStack_1f0 [12];
  TiXmlNode aTStack_1e4 [20];
  undefined **ppuStack_1d0;
  TiXmlNode aTStack_1cc [24];
  TiXmlElement aTStack_1b4 [12];
  TiXmlElement local_1a8 [4];
  TiXmlNode local_1a4 [4];
  TiXmlNode local_1a0 [24];
  TiXmlElement aTStack_188 [4];
  TiXmlNode aTStack_184 [4];
  TiXmlNode aTStack_180 [12];
  TiXmlElement aTStack_174 [8];
  TiXmlElement local_16c [4];
  TiXmlNode local_168 [4];
  TiXmlNode local_164 [96];
  TiXmlElement aTStack_104 [16];
  TiXmlElement local_f4 [4];
  TiXmlNode local_f0 [4];
  TiXmlNode local_ec [12];
  TiXmlElement local_e0 [4];
  TiXmlNode local_dc [4];
  TiXmlNode local_d8 [44];
  TiXmlElement aTStack_ac [64];
  TiXmlElement aTStack_6c [24];
  TiXmlElement local_54 [4];
  TiXmlNode local_50 [4];
  TiXmlNode local_4c [64];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ab8967;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(this + 0x184) == 0) {
    *(undefined4 *)(this + 0x34) = 0xfffffffd;
    pCVar3 = (CNetMasterServerRequest *)0x0;
  }
  else {
    pCVar12 = this;
    TiXmlElement::TiXmlElement
              ((TiXmlElement *)&stack0xfffffa64,(TiXmlElement *)"params",
               (char *)(DAT_00cca150 ^ (uint)&stack0xfffff998));
    TiXmlText::TiXmlText(local_378,*(TiXmlText **)(param_2 + 4),unaff_EDI);
    TiXmlElement::TiXmlElement(local_54,(TiXmlElement *)"faultylogin",unaff_ESI);
    TiXmlNode::InsertEndChild(local_50,local_370,unaff_EBP);
    TiXmlNode::InsertEndChild((TiXmlNode *)&stack0xfffffa74,local_4c,unaff_EBX);
    pCVar8 = (CMwStatsValue *)0x0;
    pCVar9 = (CFastString *)PTR_DAT_00bbf7d8;
    CFastStringInt::GetUtf8
              (param_7,(CFastStringInt *)&stack0xfffffa00,(CFastString *)0x0,in_stack_fffff9a8);
    TiXmlText::TiXmlText(local_334,(TiXmlText *)in_stack_fffffa08,in_stack_fffff9ac);
    TiXmlElement::TiXmlElement(local_e0,(TiXmlElement *)"nickname",in_stack_fffff9b0);
    TiXmlNode::InsertEndChild(local_dc,local_32c,in_stack_fffff9b4);
    TiXmlNode::InsertEndChild((TiXmlNode *)&stack0xfffffa88,local_d8,in_stack_fffff9b8);
    pcVar10 = (char *)0x0;
    param_9 = (CMwId *)CONCAT31(param_9._1_3_,6);
    pTVar27 = (TiXmlNode *)PTR_DAT_00bbf7d8;
    CFastStringInt::GetUtf8
              (in_stack_00000034,(CFastStringInt *)&stack0xfffffa0c,(CFastString *)0x0,
               in_stack_fffff9bc);
    TiXmlText::TiXmlText(local_380,(TiXmlText *)in_stack_fffffa14,in_stack_fffff9c0);
    uStack0000002c = 7;
    TiXmlElement::TiXmlElement(local_16c,(TiXmlElement *)"reason",in_stack_fffff9c4);
    uStack00000030 = 8;
    TiXmlNode::InsertEndChild(local_168,(TiXmlNode *)local_378,in_stack_fffff9c8);
    TiXmlNode::InsertEndChild((TiXmlNode *)&stack0xfffffa9c,local_164,in_stack_fffff9cc);
    pTVar15 = (TiXmlNode *)0x0;
    uStack00000038 = 9;
    pTVar16 = (TiXmlNode *)PTR_DAT_00bbf7d8;
    CFastStringInt::GetUtf8
              (in_stack_0000004c,(CFastStringInt *)&stack0xfffffa38,(CFastString *)0x0,
               in_stack_fffff9d0);
    TiXmlText::TiXmlText(local_27c,(TiXmlText *)in_stack_fffffa40,in_stack_fffff9d4);
    uStack00000040 = 10;
    TiXmlElement::TiXmlElement(local_1a8,(TiXmlElement *)&DAT_00b6a640,in_stack_fffff9d8);
    uStack00000044 = 0xb;
    TiXmlNode::InsertEndChild(local_1a4,local_274,in_stack_fffff9dc);
    TiXmlNode::InsertEndChild((TiXmlNode *)&local_550,local_1a0,in_stack_fffff9e0);
    pCVar19 = (CFastStringInt *)0x0;
    in_stack_0000004c = (void *)CONCAT31(in_stack_0000004c._1_3_,0xc);
    pTVar21 = (TiXmlNode *)PTR_DAT_00bbf7d8;
    CFastStringInt::GetUtf8
              (in_stack_0000006c,(CFastStringInt *)&stack0xfffffa44,(CFastString *)0x0,
               in_stack_fffff9e4);
    TiXmlText::TiXmlText(local_2c8,(TiXmlText *)in_stack_fffffa4c,in_stack_fffff9e8);
    uStack00000054 = 0xd;
    TiXmlElement::TiXmlElement(local_f4,(TiXmlElement *)"challenge_name",in_stack_fffff9ec);
    uStack00000058 = 0xe;
    TiXmlNode::InsertEndChild(local_f0,local_2c0,in_stack_fffff9f0);
    TiXmlNode::InsertEndChild(local_53c,local_ec,in_stack_fffff9f4);
    pvVar5 = in_stack_00000084;
    CMwId::GetString(in_stack_00000084,in_stack_fffff9f8,in_stack_fffff9fc);
    if (extraout_EAX != 0) {
      CMwId::GetString(pvVar5,pCVar8,pCVar9);
      TiXmlText::TiXmlText(local_558,extraout_EAX_00,in_stack_fffffa08);
      in_stack_00000074 = 0xf;
      TiXmlElement::TiXmlElement(local_4a4,(TiXmlElement *)"challenge_id",pcVar10);
      in_stack_00000078 = 0x10;
      TiXmlNode::InsertEndChild(local_4a0,(TiXmlNode *)&local_550,pTVar27);
      TiXmlNode::InsertEndChild((TiXmlNode *)local_51c,local_49c,in_stack_fffffa14);
      in_stack_00000080 = 0xf;
      TiXmlElement::~TiXmlElement(local_498,in_stack_fffffa18);
      in_stack_00000084 = (void *)CONCAT31(in_stack_00000084._1_3_,0xe);
      local_544[0] = TiXmlText::vftable;
      TiXmlNode::~TiXmlNode((TiXmlNode *)local_544,in_stack_fffffa1c);
    }
    if (in_stack_000000a4 != 0) {
      pTVar24 = (TiXmlNode *)0x0;
      pTVar20 = (TiXmlNode *)0x0;
      pCVar17 = *(CFastStringInt **)(in_stack_000000a4 + 0x20);
      in_stack_00000088 = 0x13;
      pTVar21 = (TiXmlNode *)PTR_DAT_00bbf7d8;
      pTVar25 = (TiXmlElement *)PTR_DAT_00bbf7dc;
      CFastStringInt::SetString
                (&stack0xfffffa58,(CFastStringInt *)&stack0xfffffa4c,
                 (SStringParam *)in_stack_fffffa20);
      pcVar10 = *(char **)(in_stack_000000a4 + 0x28);
      pTVar27 = *(TiXmlNode **)(in_stack_000000a4 + 0x24);
      CFastString::SetString
                ((CFastString *)&stack0xfffffa48,(CFastStringInt *)&stack0xfffffa50,
                 (SStringParam *)pCVar12);
      in_stack_fffffa9c = *(TiXmlElement **)(in_stack_000000a4 + 0x3c);
      in_stack_fffffa98 = *(TiXmlNode **)(in_stack_000000a4 + 0x38);
      CSystemPackDesc::ConvertChecksumToString
                ((SNat128 *)&stack0xfffffa98,(CFastString *)&stack0xfffffa44,0);
      pCVar19 = (CFastStringInt *)0x0;
      in_stack_fffffa20 = (CFastStringInt *)&stack0xfffffa3c;
      in_stack_00000090 = 0x14;
      pcVar18 = PTR_DAT_00bbf7d8;
      CFastStringInt::GetUtf8
                (&stack0xfffffa60,in_stack_fffffa20,(CFastString *)0x0,(int)in_stack_fffffa28);
      pCVar12 = (CGameMasterServer *)0x6cb8a8;
      TiXmlText::TiXmlText(local_484,(TiXmlText *)pTVar20,(CFastStringInt *)in_stack_fffffa2c);
      in_stack_00000098 = 0x15;
      in_stack_fffffa28 = (CFastString *)0x6cb8c1;
      TiXmlElement::TiXmlElement(local_3e0,(TiXmlElement *)"skin_name",(char *)in_stack_fffffa30);
      in_stack_0000009c = 0x16;
      in_stack_fffffa2c = (SStringParam *)0x6cb8dd;
      TiXmlNode::InsertEndChild(local_3dc,local_47c,in_stack_fffffa34);
      in_stack_fffffa30 = (CFastStringInt *)0x6cb8f1;
      TiXmlNode::InsertEndChild(local_4f8,local_3d8,pTVar15);
      in_stack_fffffa34 = (TiXmlNode *)0x6cb902;
      TiXmlText::TiXmlText((TiXmlText *)local_4a4,(TiXmlText *)in_stack_fffffa64,pCVar19);
      in_stack_000000a8 = 0x17;
      pTVar15 = (TiXmlNode *)0x6cb91b;
      TiXmlElement::TiXmlElement((TiXmlElement *)local_380,(TiXmlElement *)"skin_url",pcVar18);
      in_stack_000000ac = 0x18;
      pTVar16 = (TiXmlNode *)0x6cb937;
      TiXmlNode::InsertEndChild(local_37c,local_49c,pTVar20);
      in_stack_fffffa40 = (CFastString *)0x6cb94b;
      TiXmlNode::InsertEndChild(local_4e8,(TiXmlNode *)local_378,pTVar21);
      pCVar19 = (CFastStringInt *)0x6cb95c;
      TiXmlText::TiXmlText((TiXmlText *)&local_514,(TiXmlText *)in_stack_fffffa6c,pCVar17);
      in_stack_000000b8 = 0x19;
      pTVar21 = (TiXmlNode *)0x6cb975;
      TiXmlElement::TiXmlElement(local_410,(TiXmlElement *)"skin_checksum",pcVar10);
      in_stack_000000bc = 0x1a;
      in_stack_fffffa4c = (TiXmlNode *)0x6cb991;
      TiXmlNode::InsertEndChild(local_40c,local_50c,pTVar27);
      in_stack_fffffa54 = local_408;
      in_stack_fffffa50 = (TiXmlNode *)0x6cb9a5;
      TiXmlNode::InsertEndChild(local_4d8,in_stack_fffffa54,pTVar24);
      in_stack_000000c4 = 0x19;
      TiXmlElement::~TiXmlElement(local_404,pTVar25);
      in_stack_000000c8 = 0x18;
      local_500 = TiXmlText::vftable;
      TiXmlNode::~TiXmlNode((TiXmlNode *)&local_500,in_stack_fffffa60);
      in_stack_000000cc = 0x17;
      in_stack_fffffa60 = (TiXmlNode *)0x6cb9e8;
      TiXmlElement::~TiXmlElement(local_35c,in_stack_fffffa64);
      in_stack_000000d0 = 0x16;
      local_478[0] = TiXmlText::vftable;
      in_stack_fffffa64 = (TiXmlElement *)0x6cba03;
      TiXmlNode::~TiXmlNode((TiXmlNode *)local_478,in_stack_fffffa68);
      in_stack_000000d4 = 0x15;
      in_stack_fffffa68 = (TiXmlNode *)0x6cba17;
      TiXmlElement::~TiXmlElement(local_3a4,in_stack_fffffa6c);
      in_stack_000000d8 = 0x14;
      local_440[0] = TiXmlText::vftable;
      in_stack_fffffa6c = (TiXmlElement *)0x6cba32;
      TiXmlNode::~TiXmlNode((TiXmlNode *)local_440,(TiXmlNode *)in_stack_fffffa70);
      if (in_stack_fffffa8c != PTR_DAT_00bbf7d8) {
        in_stack_fffffa70 =
             (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
              *)(in_stack_fffffa8c + -1);
        if ((in_stack_fffffa8c[-1] & 0x80) != 0) {
          in_stack_fffffa70 =
               (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
                *)(in_stack_fffffa8c + -4);
        }
        in_stack_fffffa6c = (TiXmlElement *)0x6cba51;
        operator_delete__(in_stack_fffffa70);
        in_stack_fffffa8c = PTR_DAT_00bbf7d8;
      }
      if (in_stack_fffffa94 != (TiXmlElement *)PTR_DAT_00bbf7d8) {
        in_stack_fffffa70 =
             (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
              *)(in_stack_fffffa94 + -1);
        if (((byte)in_stack_fffffa94[-1] & 0x80) != 0) {
          in_stack_fffffa70 =
               (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
                *)(in_stack_fffffa94 + -4);
        }
        in_stack_fffffa6c = (TiXmlElement *)0x6cba7b;
        operator_delete__(in_stack_fffffa70);
        in_stack_fffffa90 = (TiXmlNode *)0x0;
        in_stack_fffffa94 = (TiXmlElement *)PTR_DAT_00bbf7d8;
      }
      if (in_stack_fffffa9c != (TiXmlElement *)PTR_DAT_00bbf7d8) {
        in_stack_fffffa70 =
             (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
              *)(in_stack_fffffa9c + -1);
        if (((byte)in_stack_fffffa9c[-1] & 0x80) != 0) {
          in_stack_fffffa70 =
               (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
                *)(in_stack_fffffa9c + -4);
        }
        in_stack_fffffa6c = (TiXmlElement *)0x6cbaa5;
        operator_delete__(in_stack_fffffa70);
        in_stack_fffffa98 = (TiXmlNode *)0x0;
        in_stack_fffffa9c = (TiXmlElement *)PTR_DAT_00bbf7d8;
      }
      in_stack_000000dc = 0xe;
      if (local_550 != PTR_DAT_00bbf7dc) {
        in_stack_fffffa70 =
             (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
              *)(local_550 + -4);
        if ((local_550[-1] & 0x80) == 0) {
          in_stack_fffffa70 =
               (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
                *)(local_550 + -2);
        }
        in_stack_fffffa6c = (TiXmlElement *)0x6cbadb;
        operator_delete__(in_stack_fffffa70);
      }
    }
    iVar2 = in_stack_000000a0;
    if (in_stack_000000a0 != 0) {
      pTVar20 = (TiXmlNode *)0x0;
      pTVar16 = (TiXmlNode *)0x0;
      pCVar17 = (CFastStringInt *)0x0;
      in_stack_00000088 = 0x1d;
      pTVar27 = (TiXmlNode *)PTR_DAT_00bbf7d8;
      pcVar10 = PTR_DAT_00bbf7d8;
      pTVar25 = (TiXmlElement *)PTR_DAT_00bbf7dc;
      CFastStringInt::SetString
                (&stack0xfffffa58,(CFastStringInt *)&stack0xfffffa4c,
                 (SStringParam *)in_stack_fffffa20);
      pTVar23 = *(TiXmlText **)(iVar2 + 0x24);
      CFastString::SetString
                ((CFastString *)&stack0xfffffa38,(CFastStringInt *)&stack0xfffffa50,
                 (SStringParam *)pCVar12);
      in_stack_fffffa9c = *(TiXmlElement **)(iVar2 + 0x3c);
      in_stack_fffffa98 = *(TiXmlNode **)(iVar2 + 0x38);
      CSystemPackDesc::ConvertChecksumToString
                ((SNat128 *)&stack0xfffffa98,(CFastString *)&stack0xfffffa44,0);
      pCVar22 = (CFastStringInt *)0x0;
      in_stack_fffffa20 = (CFastStringInt *)&stack0xfffffa4c;
      in_stack_00000090 = 0x1e;
      pcVar18 = PTR_DAT_00bbf7d8;
      CFastStringInt::GetUtf8
                (&stack0xfffffa60,in_stack_fffffa20,(CFastString *)0x0,(int)in_stack_fffffa28);
      pCVar12 = (CGameMasterServer *)0x6cbbbc;
      TiXmlText::TiXmlText(aTStack_534,pTVar23,(CFastStringInt *)in_stack_fffffa2c);
      in_stack_00000098 = 0x1f;
      in_stack_fffffa28 = (CFastString *)0x6cbbd5;
      TiXmlElement::TiXmlElement
                (aTStack_430,(TiXmlElement *)"avatar_name",(char *)in_stack_fffffa30);
      in_stack_0000009c = 0x20;
      in_stack_fffffa2c = (SStringParam *)0x6cbbf1;
      TiXmlNode::InsertEndChild(aTStack_42c,aTStack_52c,pTVar16);
      in_stack_fffffa30 = (CFastStringInt *)0x6cbc05;
      TiXmlNode::InsertEndChild(local_4f8,aTStack_428,pTVar27);
      in_stack_fffffa34 = (TiXmlNode *)0x6cbc16;
      TiXmlText::TiXmlText((TiXmlText *)local_4a4,pTVar23,pCVar17);
      in_stack_000000a8 = 0x21;
      pTVar15 = (TiXmlNode *)0x6cbc2f;
      TiXmlElement::TiXmlElement((TiXmlElement *)local_380,(TiXmlElement *)"avatar_url",pcVar10);
      in_stack_000000ac = 0x22;
      pTVar16 = (TiXmlNode *)0x6cbc4b;
      TiXmlNode::InsertEndChild(local_37c,local_49c,(TiXmlNode *)pCVar19);
      in_stack_fffffa40 = (CFastString *)0x6cbc5f;
      TiXmlNode::InsertEndChild(local_4e8,(TiXmlNode *)local_378,pTVar21);
      pCVar19 = (CFastStringInt *)0x6cbc70;
      TiXmlText::TiXmlText(aTStack_464,(TiXmlText *)in_stack_fffffa6c,pCVar22);
      in_stack_000000b8 = 0x23;
      pTVar21 = (TiXmlNode *)0x6cbc89;
      TiXmlElement::TiXmlElement(aTStack_3c0,(TiXmlElement *)"avatar_checksum",pcVar18);
      in_stack_000000bc = 0x24;
      in_stack_fffffa4c = (TiXmlNode *)0x6cbca5;
      TiXmlNode::InsertEndChild(aTStack_3bc,aTStack_45c,(TiXmlNode *)pTVar23);
      in_stack_fffffa54 = aTStack_3b8;
      in_stack_fffffa50 = (TiXmlNode *)0x6cbcb9;
      TiXmlNode::InsertEndChild(local_4d8,in_stack_fffffa54,pTVar20);
      in_stack_000000c4 = 0x23;
      TiXmlElement::~TiXmlElement(aTStack_3b4,pTVar25);
      in_stack_000000c8 = 0x22;
      local_450[0] = TiXmlText::vftable;
      TiXmlNode::~TiXmlNode((TiXmlNode *)local_450,in_stack_fffffa60);
      in_stack_000000cc = 0x21;
      in_stack_fffffa60 = (TiXmlNode *)0x6cbcfc;
      TiXmlElement::~TiXmlElement(local_35c,in_stack_fffffa64);
      in_stack_000000d0 = 0x20;
      local_478[0] = TiXmlText::vftable;
      in_stack_fffffa64 = (TiXmlElement *)0x6cbd17;
      TiXmlNode::~TiXmlNode((TiXmlNode *)local_478,in_stack_fffffa68);
      in_stack_000000d4 = 0x1f;
      in_stack_fffffa68 = (TiXmlNode *)0x6cbd2b;
      TiXmlElement::~TiXmlElement(aTStack_3f4,in_stack_fffffa6c);
      in_stack_000000d8 = 0x1e;
      appuStack_4f0[0] = TiXmlText::vftable;
      in_stack_fffffa6c = (TiXmlElement *)0x6cbd46;
      TiXmlNode::~TiXmlNode((TiXmlNode *)appuStack_4f0,(TiXmlNode *)in_stack_fffffa70);
      if (in_stack_fffffa9c != (TiXmlElement *)PTR_DAT_00bbf7d8) {
        in_stack_fffffa70 =
             (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
              *)(in_stack_fffffa9c + -1);
        if (((byte)in_stack_fffffa9c[-1] & 0x80) != 0) {
          in_stack_fffffa70 =
               (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
                *)(in_stack_fffffa9c + -4);
        }
        in_stack_fffffa6c = (TiXmlElement *)0x6cbd65;
        operator_delete__(in_stack_fffffa70);
        in_stack_fffffa98 = (TiXmlNode *)0x0;
        in_stack_fffffa9c = (TiXmlElement *)PTR_DAT_00bbf7d8;
      }
      if (in_stack_fffffa94 != (TiXmlElement *)PTR_DAT_00bbf7d8) {
        in_stack_fffffa70 =
             (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
              *)(in_stack_fffffa94 + -1);
        if (((byte)in_stack_fffffa94[-1] & 0x80) != 0) {
          in_stack_fffffa70 =
               (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
                *)(in_stack_fffffa94 + -4);
        }
        in_stack_fffffa6c = (TiXmlElement *)0x6cbd8f;
        operator_delete__(in_stack_fffffa70);
        in_stack_fffffa90 = (TiXmlNode *)0x0;
        in_stack_fffffa94 = (TiXmlElement *)PTR_DAT_00bbf7d8;
      }
      if (in_stack_fffffa8c != PTR_DAT_00bbf7d8) {
        in_stack_fffffa70 =
             (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
              *)(in_stack_fffffa8c + -1);
        if ((in_stack_fffffa8c[-1] & 0x80) != 0) {
          in_stack_fffffa70 =
               (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
                *)(in_stack_fffffa8c + -4);
        }
        in_stack_fffffa6c = (TiXmlElement *)0x6cbdb9;
        operator_delete__(in_stack_fffffa70);
      }
      in_stack_000000dc = 0xe;
      if (local_550 != PTR_DAT_00bbf7dc) {
        if ((local_550[-1] & 0x80) == 0) {
          in_stack_fffffa70 =
               (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
                *)(local_550 + -2);
        }
        else {
          in_stack_fffffa70 =
               (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
                *)(local_550 + -4);
        }
        in_stack_fffffa6c = (TiXmlElement *)0x6cbdf2;
        operator_delete__(in_stack_fffffa70);
      }
    }
    CFastString::CFastString
              ((CFastString *)&stack0xfffffa60,(CFastString *)"AddAbuse",(char *)in_stack_fffffa20);
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&pCStack_548,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar12);
    in_stack_00000090 = 0x26;
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x48) != 0)) {
      uVar11 = 1;
      this_00 = (CClassicBuffer *)(**(code **)**(undefined4 **)(*(int *)(iVar2 + 0x48) + 0x6c))();
      if ((this_00 != (CClassicBuffer *)0x0) &&
         ((uVar4 = (**(code **)(*(int *)this_00 + 0x18))(), 10 < uVar4 &&
          (uVar4 = (**(code **)(*(int *)this_00 + 0x18))(), uVar4 < 0xc800)))) {
        this_01 = CFastBuffer<class_CFastString>::AddNewElem
                            (local_544,
                             (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                             in_stack_fffffa28);
        cVar14 = (char)in_stack_fffffa34;
        in_stack_fffffa28 = (CFastString *)(**(code **)(*(int *)this_00 + 0x18))();
        pCVar13 = (CClassicBuffer *)0x6cbe76;
        CFastString::SetLength
                  ((CFastString *)this_01,in_stack_fffffa28,(ulong)in_stack_fffffa2c,
                   (int)in_stack_fffffa30,cVar14);
        pCVar1 = *(CClassicBuffer **)(this_01 + 4);
        in_stack_fffffa34 = (TiXmlNode *)0x6cbe82;
        pvVar5 = (void *)(**(code **)(*(int *)this_00 + 0x18))();
        CClassicBuffer::ReadAll(this_00,pCVar1,pvVar5,uVar11);
        CSystemFid::BufferClose(*(CSystemFid **)(iVar2 + 0x48),(CSystemFid *)this_00,pCVar13);
        this = (CGameMasterServer *)pCStack_548;
      }
    }
    TiXmlElement::TiXmlElement(aTStack_1f8,(TiXmlElement *)"request",(char *)in_stack_fffffa28);
    local_554 = 0;
    local_550 = PTR_DAT_00bbf7d8;
    uStack00000094 = 0x28;
    pTVar25 = in_stack_fffffa6c;
    pCVar26 = in_stack_fffffa70;
    CFastString::SetString
              ((CFastString *)&local_554,(CFastStringInt *)&stack0xfffffa58,in_stack_fffffa2c);
    pCStack_548 = aCStack_1f0;
    TiXmlText::TiXmlText
              ((TiXmlText *)appuStack_250,(TiXmlText *)in_stack_fffffa74,in_stack_fffffa30);
    in_stack_0000009c = 0x29;
    TiXmlElement::TiXmlElement
              ((TiXmlElement *)&local_c,(TiXmlElement *)&DAT_00b32cb4,(char *)in_stack_fffffa34);
    in_stack_000000a0 = CONCAT31(in_stack_000000a0._1_3_,0x2a);
    TiXmlNode::InsertEndChild((TiXmlNode *)&puStack_8,aTStack_248,pTVar15);
    TiXmlNode::InsertEndChild(aTStack_1e4,(TiXmlNode *)&uStack_4,pTVar16);
    pTVar27 = (TiXmlNode *)0x0;
    in_stack_000000a8 = 0x2b;
    pTVar28 = (TiXmlElement *)PTR_DAT_00bbf7d8;
    CNetMasterServer::FindValidationData
              ((CNetMasterServer *)this,(CNetMasterServer *)&stack0xfffffa80,
               (CFastString *)&stack0xfffffa88,in_stack_fffffa40);
    TiXmlText::TiXmlText((TiXmlText *)local_32c,(TiXmlText *)in_stack_fffffa90,pCVar19);
    uStack000000b0 = 0x2c;
    TiXmlElement::TiXmlElement(aTStack_188,(TiXmlElement *)"validation",(char *)pTVar21);
    uStack000000b4 = 0x2d;
    TiXmlNode::InsertEndChild(aTStack_184,local_324,in_stack_fffffa4c);
    if (in_stack_fffffa98 != (TiXmlNode *)0x0) {
      TiXmlNode::InsertEndChild((TiXmlNode *)&ppuStack_1d0,aTStack_180,in_stack_fffffa50);
    }
    TiXmlNode::InsertEndChild(aTStack_1cc,aTStack_4dc,in_stack_fffffa54);
    local_51c[0] = &local_514;
    pCVar3 = CNetMasterServer::SendMasterServerRequest
                       ((CNetMasterServer *)this,(CNetMasterServer *)&stack0xfffffa98,aCStack_528,
                        (SRequestElement *)0x0,in_stack_fffffa70);
    in_stack_000000c4 = 0x2c;
    TiXmlElement::~TiXmlElement(aTStack_174,in_stack_fffffa6c);
    in_stack_000000c8 = 0x2b;
    appuStack_310[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)appuStack_310,in_stack_fffffa60);
    if (local_550 != PTR_DAT_00bbf7d8) {
      puVar7 = local_550 + -1;
      if ((local_550[-1] & 0x80) != 0) {
        puVar7 = local_550 + -4;
      }
      operator_delete__(puVar7);
      local_554 = 0;
      local_550 = PTR_DAT_00bbf7d8;
    }
    in_stack_000000cc = 0x29;
    TiXmlElement::~TiXmlElement((TiXmlElement *)&param_9,in_stack_fffffa64);
    in_stack_000000d0 = 0x28;
    appuStack_218[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)appuStack_218,in_stack_fffffa68);
    if (local_510 != PTR_DAT_00bbf7d8) {
      puVar7 = local_510 + -1;
      if ((local_510[-1] & 0x80) != 0) {
        puVar7 = local_510 + -4;
      }
      operator_delete__(puVar7);
      local_514 = 0;
      local_510 = PTR_DAT_00bbf7d8;
    }
    in_stack_000000d4 = 0x26;
    TiXmlElement::~TiXmlElement(aTStack_1b4,pTVar25);
    in_stack_000000d8 = 0x25;
    CFastBuffer<class_CFastString>::~CFastBuffer<class_CFastString>
              (local_4fc,(CFastBuffer<class_CFastString> *)pCVar26);
    if (pCStack_548 != (CNetMasterServer *)PTR_DAT_00bbf7d8) {
      pCVar6 = pCStack_548 + -1;
      if (((byte)pCStack_548[-1] & 0x80) != 0) {
        pCVar6 = pCStack_548 + -4;
      }
      operator_delete__(pCVar6);
      local_54c = 0;
      pCStack_548 = (CNetMasterServer *)PTR_DAT_00bbf7d8;
    }
    in_stack_000000dc = 0xd;
    TiXmlElement::~TiXmlElement(aTStack_6c,in_stack_fffffa74);
    uStack000000e0 = 0xc;
    appuStack_238[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)appuStack_238,in_stack_fffffa78);
    if (local_520 != PTR_DAT_00bbf7d8) {
      puVar7 = local_520 + -1;
      if ((local_520[-1] & 0x80) != 0) {
        puVar7 = local_520 + -4;
      }
      operator_delete__(puVar7);
      local_524 = 0;
      local_520 = PTR_DAT_00bbf7d8;
    }
    uStack000000e4 = 10;
    TiXmlElement::~TiXmlElement(aTStack_104,in_stack_fffffa7c);
    uStack000000e8 = 9;
    ppuStack_1d0 = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)&ppuStack_1d0,in_stack_fffffa80);
    if (local_510 != PTR_DAT_00bbf7d8) {
      puVar7 = local_510 + -1;
      if ((local_510[-1] & 0x80) != 0) {
        puVar7 = local_510 + -4;
      }
      operator_delete__(puVar7);
      local_514 = 0;
      local_510 = PTR_DAT_00bbf7d8;
    }
    uStack000000ec = 7;
    TiXmlElement::~TiXmlElement(aTStack_ac,in_stack_fffffa84);
    uStack000000f0 = 6;
    appuStack_2b8[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)appuStack_2b8,pTVar27);
    if (local_520 != PTR_DAT_00bbf7d8) {
      puVar7 = local_520 + -1;
      if ((local_520[-1] & 0x80) != 0) {
        puVar7 = local_520 + -4;
      }
      operator_delete__(puVar7);
      local_524 = 0;
      local_520 = PTR_DAT_00bbf7d8;
    }
    uStack000000f4 = 4;
    TiXmlElement::~TiXmlElement((TiXmlElement *)&uStack_4,pTVar28);
    uStack000000f8 = 3;
    appuStack_250[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)appuStack_250,in_stack_fffffa90);
    if (local_510 != PTR_DAT_00bbf7d8) {
      puVar7 = local_510 + -1;
      if ((local_510[-1] & 0x80) != 0) {
        puVar7 = local_510 + -4;
      }
      operator_delete__(puVar7);
      local_514 = 0;
      local_510 = PTR_DAT_00bbf7d8;
    }
    uStack000000fc = 1;
    TiXmlElement::~TiXmlElement((TiXmlElement *)&stack0x000000a4,in_stack_fffffa94);
    in_stack_00000100 = (void *)((uint)in_stack_00000100 & 0xffffff00);
    ppuStack_278 = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)&ppuStack_278,in_stack_fffffa98);
    uStack00000104 = 0xffffffff;
    TiXmlElement::~TiXmlElement(local_494,in_stack_fffffa9c);
  }
  ExceptionList = in_stack_00000100;
  return pCVar3;
}
}

// =================================================
// Function: CGameMasterServer::GetFeatureFromId
// =================================================
SFeature * __thiscall
CGameMasterServer::GetFeatureFromId
          (CGameMasterServer *this,CGameMasterServer *param_1,CMwId *param_2)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2b0,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    iVar1 = *(int *)param_2;
    do {
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this + 0x2b0,pCVar4,unaff_ESI);
      if (*(int *)pSVar3 == iVar1) {
        return (SFeature *)pSVar3;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return (SFeature *)0x0;
}
}

// =================================================
// Function: CGameMasterServer::GetFeatureFromName
// =================================================
SFeature * __thiscall
CGameMasterServer::GetFeatureFromName
          (CGameMasterServer *this,CGameMasterServer *param_1,char *param_2)
{
{
  CMwId CVar1;
  undefined3 extraout_var;
  SFeature *pSVar2;
  CMwId *unaff_ESI;
  CFastStringInt *unaff_retaddr;
  
  CVar1 = CMwId::CreateFromLocalName((char *)&param_1);
  pSVar2 = GetFeatureFromId(this,(CGameMasterServer *)CONCAT31(extraout_var,CVar1),unaff_ESI);
  OnAccessViolation_ConcatToCrashFileName(unaff_retaddr);
  return pSVar2;
}
}

// =================================================
// Function: CGameMasterServer::GetLadderRankAsStringInt
// =================================================
void __cdecl
CGameMasterServer::GetLadderRankAsStringInt(ulong param_1,ulong param_2,CFastStringInt *param_3)
{
{
  wchar_t wVar1;
  wchar_t *pwVar2;
  SStringParamInt *pSVar3;
  SStringParam *unaff_ESI;
  SStringParam *unaff_EDI;
  void *unaff_retaddr;
  void *in_stack_00000010;
  void *in_stack_00000014;
  SStringParam *pSVar4;
  SStringParam *pSVar5;
  undefined4 local_20;
  undefined4 local_1c;
  SStringParam *local_18;
  wchar_t *local_14;
  wchar_t *local_10;
  SStringParam *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a9d638;
  local_c = ExceptionList;
  pwVar2 = (wchar_t *)(DAT_00cca150 ^ (uint)&stack0xffffffd0);
  ExceptionList = &local_c;
  if (param_2 == 0) {
    local_14 = CClassicI18n::GetTranslatedStringInternal
                         ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"|Ladder|Unknown",pwVar2);
    if (local_14 == (wchar_t *)0x0) {
      local_10 = (wchar_t *)0x0;
    }
    else {
      pwVar2 = local_14;
      do {
        wVar1 = *pwVar2;
        pwVar2 = pwVar2 + 1;
      } while (wVar1 != L'\0');
      local_10 = (wchar_t *)((int)pwVar2 - (int)(local_14 + 1) >> 1);
    }
    local_c = (SStringParam *)0x1;
    CFastStringInt::SetString(in_stack_00000010,(CFastStringInt *)&local_14,unaff_EDI);
    ExceptionList = local_4;
    return;
  }
  if (param_1 == 0xffffffff) {
    pSVar3 = (SStringParamInt *)
             CClassicI18n::GetTranslatedStringInternal
                       ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"|Ladder|Not ranked",pwVar2);
    SStringParamInt::SStringParamInt(&local_14,pSVar3,(wchar_t *)unaff_EDI);
    CFastStringInt::SetString(in_stack_00000014,(CFastStringInt *)&local_10,unaff_ESI);
    ExceptionList = unaff_retaddr;
    return;
  }
  pSVar4 = (SStringParam *)0x0;
  local_4 = (void *)0x0;
  pSVar5 = (SStringParam *)PTR_DAT_00bbf7d8;
  CFastString::SetNatural
            ((CFastString *)&stack0xffffffd8,(CFastString *)param_1,1,0,0,0,1,(int)pwVar2);
  local_1c = local_20;
  local_18 = pSVar5;
  CFastStringInt::SetString(in_stack_00000010,(CFastStringInt *)&local_1c,unaff_EDI);
  if (param_2 != 0xffffffff) {
    CFastString::SetNatural
              ((CFastString *)&local_20,(CFastString *)param_2,1,0,0,0,1,(int)unaff_ESI);
    local_14 = L"⼠ 呃慲正慍楮剡捡乥瑥慌獰";
    local_10 = (wchar_t *)0x3;
    CFastStringInt::Concat(in_stack_00000010,(CFastStringInt *)&local_14,pSVar4);
    local_10 = local_14;
    local_c = local_18;
    CFastStringInt::Concat(in_stack_00000010,(CFastStringInt *)&local_10,pSVar5);
  }
  if (local_10 != (wchar_t *)PTR_DAT_00bbf7d8) {
    pwVar2 = (wchar_t *)((int)local_10 + -1);
    if ((*(byte *)((int)local_10 + -1) & 0x80) != 0) {
      pwVar2 = local_10 + -2;
    }
    operator_delete__(pwVar2);
  }
  ExceptionList = (void *)param_2;
  return;
}
}

// =================================================
// Function: CGameMasterServer::IsCoppersTransactionPaid
// =================================================
CNetMasterServerRequest * __thiscall
CGameMasterServer::IsCoppersTransactionPaid
          (CGameMasterServer *this,CGameMasterServer *param_1,ulong param_2)
{
{
  CNetMasterServerRequest *pCVar1;
  undefined *puVar2;
  char *unaff_EBP;
  CFastStringInt *unaff_ESI;
  int unaff_EDI;
  undefined1 uStack0000000c;
  undefined1 uStack00000018;
  undefined1 uStack0000001c;
  undefined1 uStack00000024;
  undefined1 uStack00000028;
  undefined1 uStack00000030;
  undefined1 uStack00000038;
  undefined1 uStack0000003c;
  undefined1 uStack0000004c;
  undefined1 uStack00000050;
  undefined1 uStack00000054;
  undefined1 uStack00000058;
  undefined1 uStack0000005c;
  undefined1 uStack00000060;
  void *in_stack_00000064;
  undefined4 uStack00000068;
  TiXmlNode *in_stack_fffffda4;
  TiXmlNode *in_stack_fffffda8;
  char *in_stack_fffffdac;
  char *in_stack_fffffdb0;
  SStringParam *in_stack_fffffdb4;
  CFastStringInt *pCVar3;
  char *pcVar4;
  TiXmlNode *in_stack_fffffdc0;
  TiXmlNode *in_stack_fffffdc4;
  CFastString *in_stack_fffffdc8;
  CFastStringInt *in_stack_fffffdcc;
  char *in_stack_fffffdd0;
  TiXmlNode *in_stack_fffffdd4;
  TiXmlNode *in_stack_fffffdd8;
  TiXmlNode *pTVar5;
  CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*> *pCVar6;
  TiXmlElement *pTVar7;
  TiXmlText *pTVar8;
  CFastString *pCVar9;
  TiXmlNode *pTVar10;
  TiXmlElement *in_stack_fffffdf4;
  TiXmlElement *in_stack_fffffdf8;
  TiXmlNode *in_stack_fffffdfc;
  TiXmlElement *in_stack_fffffe00;
  undefined *local_1f8;
  undefined *local_1f4 [2];
  undefined4 local_1ec [2];
  undefined4 local_1e4;
  undefined *local_1e0;
  undefined *local_1dc;
  undefined **local_1d0 [15];
  undefined **local_194 [2];
  TiXmlNode local_18c [12];
  TiXmlElement local_180 [8];
  undefined **local_178 [3];
  TiXmlNode local_16c [20];
  TiXmlNode local_158 [4];
  TiXmlNode local_154 [24];
  TiXmlElement local_13c [44];
  TiXmlElement local_110 [4];
  TiXmlNode local_10c [4];
  TiXmlNode local_108 [12];
  TiXmlElement local_fc [12];
  TiXmlElement local_f0 [4];
  TiXmlNode local_ec [4];
  TiXmlNode local_e8 [80];
  TiXmlElement local_98 [20];
  TiXmlElement local_84 [4];
  TiXmlNode local_80 [4];
  TiXmlNode local_7c [32];
  TiXmlElement local_5c [8];
  TiXmlElement local_54 [12];
  TiXmlNode local_48 [52];
  TiXmlNode local_14 [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ab7c61;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(this + 0x184) == 0) {
    *(undefined4 *)(this + 0x34) = 0xfffffffd;
    pCVar1 = (CNetMasterServerRequest *)0x0;
  }
  else {
    TiXmlElement::TiXmlElement
              (local_5c,(TiXmlElement *)"params",(char *)(DAT_00cca150 ^ (uint)&stack0xfffffd98));
    pCVar3 = (CFastStringInt *)0x0;
    pcVar4 = PTR_DAT_00bbf7d8;
    CFastString::SetNatural
              ((CFastString *)&stack0xfffffdb8,(CFastString *)param_2,0,0,0,0,1,unaff_EDI);
    TiXmlText::TiXmlText((TiXmlText *)local_1f4,(TiXmlText *)in_stack_fffffdc0,unaff_ESI);
    TiXmlElement::TiXmlElement(local_f0,(TiXmlElement *)&DAT_00b4a56c,unaff_EBP);
    uStack0000000c = 3;
    TiXmlNode::InsertEndChild(local_ec,(TiXmlNode *)local_1ec,in_stack_fffffda4);
    TiXmlNode::InsertEndChild(local_48,local_e8,in_stack_fffffda8);
    CFastString::CFastString
              ((CFastString *)&stack0xfffffdbc,(CFastString *)"IsCoppersTransactionPaid",
               in_stack_fffffdac);
    uStack00000018 = 4;
    TiXmlElement::TiXmlElement(local_180,(TiXmlElement *)"request",in_stack_fffffdb0);
    pTVar5 = (TiXmlNode *)0x0;
    uStack0000001c = 6;
    pCVar9 = in_stack_fffffdc8;
    pTVar10 = in_stack_fffffdc4;
    CFastString::SetString
              ((CFastString *)&stack0xfffffddc,(CFastStringInt *)&stack0xfffffdec,in_stack_fffffdb4)
    ;
    pTVar8 = (TiXmlText *)local_178;
    TiXmlText::TiXmlText((TiXmlText *)&stack0xfffffdf8,(TiXmlText *)in_stack_fffffdcc,pCVar3);
    uStack00000024 = 7;
    TiXmlElement::TiXmlElement(local_84,(TiXmlElement *)&DAT_00b32cb4,pcVar4);
    uStack00000028 = 8;
    TiXmlNode::InsertEndChild(local_80,(TiXmlNode *)&stack0xfffffe00,in_stack_fffffdc0);
    TiXmlNode::InsertEndChild(local_16c,local_7c,in_stack_fffffdc4);
    pCVar6 = (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
              *)0x0;
    uStack00000030 = 9;
    pTVar7 = (TiXmlElement *)PTR_DAT_00bbf7d8;
    CNetMasterServer::FindValidationData
              ((CNetMasterServer *)this,(CNetMasterServer *)&stack0xfffffdd8,
               (CFastString *)&stack0xfffffde0,in_stack_fffffdc8);
    TiXmlText::TiXmlText((TiXmlText *)local_194,pTVar8,in_stack_fffffdcc);
    uStack00000038 = 10;
    TiXmlElement::TiXmlElement(local_110,(TiXmlElement *)"validation",in_stack_fffffdd0);
    uStack0000003c = 0xb;
    TiXmlNode::InsertEndChild(local_10c,local_18c,in_stack_fffffdd4);
    if (pTVar10 != (TiXmlNode *)0x0) {
      TiXmlNode::InsertEndChild(local_158,local_108,in_stack_fffffdd8);
    }
    TiXmlNode::InsertEndChild(local_154,local_14,pTVar5);
    local_1ec[0] = 0;
    pCVar1 = CNetMasterServer::SendMasterServerRequest
                       ((CNetMasterServer *)this,(CNetMasterServer *)&stack0xfffffdf0,
                        (CFastString *)&local_1f8,(SRequestElement *)0x0,pCVar6);
    uStack0000004c = 10;
    TiXmlElement::~TiXmlElement(local_fc,pTVar7);
    uStack00000050 = 9;
    local_178[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)local_178,(TiXmlNode *)pTVar8);
    if (local_1f8 != PTR_DAT_00bbf7d8) {
      puVar2 = local_1f8 + -1;
      if ((local_1f8[-1] & 0x80) != 0) {
        puVar2 = local_1f8 + -4;
      }
      operator_delete__(puVar2);
      local_1f8 = PTR_DAT_00bbf7d8;
    }
    uStack00000054 = 7;
    TiXmlElement::~TiXmlElement(local_54,(TiXmlElement *)pCVar9);
    uStack00000058 = 6;
    local_1d0[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)local_1d0,pTVar10);
    if (local_1e0 != PTR_DAT_00bbf7d8) {
      puVar2 = local_1e0 + -1;
      if ((local_1e0[-1] & 0x80) != 0) {
        puVar2 = local_1e0 + -4;
      }
      operator_delete__(puVar2);
      local_1e4 = 0;
      local_1e0 = PTR_DAT_00bbf7d8;
    }
    uStack0000005c = 4;
    TiXmlElement::~TiXmlElement(local_13c,in_stack_fffffdf4);
    if (local_1f4[0] != PTR_DAT_00bbf7d8) {
      puVar2 = local_1f4[0] + -1;
      if ((local_1f4[0][-1] & 0x80) != 0) {
        puVar2 = local_1f4[0] + -4;
      }
      operator_delete__(puVar2);
      local_1f8 = (undefined *)0x0;
      local_1f4[0] = PTR_DAT_00bbf7d8;
    }
    uStack00000060 = 2;
    TiXmlElement::~TiXmlElement(local_98,in_stack_fffffdf8);
    in_stack_00000064 = (void *)CONCAT31(in_stack_00000064._1_3_,1);
    local_194[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)local_194,in_stack_fffffdfc);
    if (local_1dc != PTR_DAT_00bbf7d8) {
      puVar2 = local_1dc + -1;
      if ((local_1dc[-1] & 0x80) != 0) {
        puVar2 = local_1dc + -4;
      }
      operator_delete__(puVar2);
      local_1e0 = (undefined *)0x0;
      local_1dc = PTR_DAT_00bbf7d8;
    }
    uStack00000068 = 0xffffffff;
    TiXmlElement::~TiXmlElement((TiXmlElement *)&stack0x00000010,in_stack_fffffe00);
  }
  ExceptionList = in_stack_00000064;
  return pCVar1;
}
}

// =================================================
// Function: CGameMasterServer::IsPayingAccountConnected
// =================================================
int __thiscall
CGameMasterServer::IsPayingAccountConnected(CGameMasterServer *this,CGameMasterServer *param_1)
{
{
  int extraout_EAX;
  undefined *puVar1;
  int *unaff_ESI;
  uint uVar2;
  void *unaff_retaddr;
  int *piVar3;
  undefined1 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined *puStack_14;
  undefined *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00a9d668;
  local_c = ExceptionList;
  uVar2 = 0;
  if ((*(int *)(this + 0x184) != 0) && (*(int *)(this + 0x1c0) != 0)) {
    piVar3 = (int *)0x0;
    local_20 = PTR_DAT_00bbf7d8;
    local_4 = 0;
    local_1c = 0;
    local_18 = 0;
    ExceptionList = &local_c;
    CClassicCrypto_BlowFish::DoString
              (*(void **)(this + 0x1d0),(CClassicCrypto_BlowFish *)(this + 0x1c0),
               (CFastString *)&stack0xffffffdc,(CFastString *)0x0,(ECipherOpMode)&local_1c,
               (uint64 *)0x1,DAT_00cca150 ^ (uint)&stack0xffffffd8);
    local_10 = &DAT_00b62000;
    local_c = (void *)0x4;
    if (local_20 == &DAT_00000004) {
      CFastString::Compare
                ((CFastString *)&local_20,(SParam_Fids *)&local_10,(SParam *)0x0,unaff_ESI,piVar3);
      uVar2 = (uint)(extraout_EAX == 0);
    }
    if (puStack_14 != PTR_DAT_00bbf7d8) {
      puVar1 = puStack_14 + -1;
      if ((puStack_14[-1] & 0x80) != 0) {
        puVar1 = puStack_14 + -4;
      }
      operator_delete__(puVar1);
    }
    ExceptionList = unaff_retaddr;
    return uVar2;
  }
  return 0;
}
}

// =================================================
// Function: CGameMasterServer::ReadForceOffline
// =================================================
int __thiscall
CGameMasterServer::ReadForceOffline
          (CGameMasterServer *this,CGameMasterServer *param_1,TiXmlElement *param_2)
{
{
  CGameMasterServer *this_00;
  TiXmlElement *pTVar1;
  int iVar2;
  TiXmlElement *pTVar3;
  undefined *puVar4;
  SStringParam *unaff_EBX;
  char *unaff_EBP;
  ulong unaff_ESI;
  char *unaff_EDI;
  undefined4 uStack0000000c;
  uint in_stack_00000010;
  undefined4 local_18;
  undefined *local_14;
  undefined *local_10;
  undefined *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  pTVar3 = param_2;
  local_4 = 0xffffffff;
  local_8 = &LAB_00ab57f0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = this + 0x2dc;
  if (*(int *)this_00 != 0) {
    CFastStringBase<wchar_t>::AllocAtLeast
              (this_00,(CFastStringBase<wchar_t> *)0x0,1,0,
               (SOldChars *)(DAT_00cca150 ^ (uint)&stack0xffffffd0));
    **(undefined2 **)(this + 0x2e0) = 0;
    *(int *)this_00 = 0;
  }
  pTVar1 = TiXmlNode::FirstChildElement((TiXmlNode *)param_2,(TiXmlNode *)&DAT_00b73bd0,unaff_EDI);
  if (pTVar1 == (TiXmlElement *)0x0) {
    *(undefined4 *)(this + 0x178) = 0;
  }
  else {
    local_18 = 0;
    local_14 = PTR_DAT_00bbf7d8;
    CXmlEngine::ReadAssociatedText(pTVar1,(CFastStringInt *)&local_18);
    iVar2 = CFastString::GetNatural
                      ((CFastString *)&local_18,(CFastString *)&stack0x0000000c,(ulong *)0x0,0,
                       unaff_ESI);
    param_2 = (TiXmlElement *)0xffffffff;
    *(uint *)(this + 0x178) = -(uint)(iVar2 != 0) & in_stack_00000010;
    if (local_10 != PTR_DAT_00bbf7d8) {
      puVar4 = local_10 + -1;
      if ((local_10[-1] & 0x80) != 0) {
        puVar4 = local_10 + -4;
      }
      operator_delete__(puVar4);
    }
  }
  pTVar3 = TiXmlNode::FirstChildElement((TiXmlNode *)pTVar3,(TiXmlNode *)&DAT_00b2edcc,unaff_EBP);
  if (pTVar3 == (TiXmlElement *)0x0) {
    local_4 = DAT_00d71d58;
    local_8 = (undefined1 *)DAT_00d71d5c;
    CFastStringInt::SetString(this_00,(CFastStringInt *)&local_8,unaff_EBX);
  }
  else {
    local_10 = (undefined *)0x0;
    local_c = PTR_DAT_00bbf7d8;
    uStack0000000c = 1;
    CXmlEngine::ReadAssociatedText(pTVar3,(CFastStringInt *)&local_10);
    local_4 = local_10;
    local_8 = local_c;
    CFastStringInt::SetUtf8(this_00,(CFastStringInt *)&local_8,unaff_EBX);
    if (local_8 != PTR_DAT_00bbf7d8) {
      puVar4 = local_8 + -1;
      if ((local_8[-1] & 0x80) != 0) {
        puVar4 = local_8 + -4;
      }
      operator_delete__(puVar4);
    }
  }
  ExceptionList = param_2;
  return 1;
}
}

// =================================================
// Function: CGameMasterServer::ReportInvalidReplay
// =================================================
CNetMasterServerRequest * __thiscall
CGameMasterServer::ReportInvalidReplay
          (CGameMasterServer *this,CGameMasterServer *param_1,CFastString *param_2,
          CClassicBufferMemory *param_3,CFastStringInt *param_4)
{
{
  GmFrustumIso4 *pGVar1;
  int iVar2;
  SLoadedLight *this_00;
  char *pcVar3;
  CNetMasterServerRequest *pCVar4;
  undefined *puVar5;
  CFastBuffer<class_CFastString> *pCVar6;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  char *pcVar7;
  SStringParam *in_stack_fffffc74;
  char *in_stack_fffffc78;
  CFastStringInt *in_stack_fffffc7c;
  char *in_stack_fffffc80;
  TiXmlNode *in_stack_fffffc84;
  TiXmlNode *in_stack_fffffc88;
  int in_stack_fffffc8c;
  CFastStringInt *in_stack_fffffc90;
  char *in_stack_fffffc94;
  TiXmlNode *in_stack_fffffc98;
  TiXmlNode *in_stack_fffffc9c;
  SStringParam *in_stack_fffffca8;
  CFastStringInt *in_stack_fffffcac;
  char *pcVar8;
  TiXmlNode *pTVar9;
  TiXmlNode *in_stack_fffffcb8;
  CFastString *in_stack_fffffcbc;
  CFastStringInt *in_stack_fffffcc0;
  TiXmlText *in_stack_fffffcc4;
  TiXmlNode *in_stack_fffffcc8;
  TiXmlNode *in_stack_fffffccc;
  TiXmlNode *in_stack_fffffcd0;
  CFastStringInt *pCVar10;
  TiXmlElement *pTVar11;
  TiXmlElement *pTVar12;
  TiXmlNode *in_stack_fffffce4;
  TiXmlElement *pTVar13;
  TiXmlElement *in_stack_fffffcec;
  TiXmlNode *in_stack_fffffcf0;
  TiXmlElement *in_stack_fffffcf4;
  TiXmlNode *in_stack_fffffcf8;
  TiXmlElement *in_stack_fffffcfc;
  CFastBuffer<class_CFastString> *pCVar14;
  undefined *puVar15;
  undefined4 uStack_2e8;
  undefined *puStack_2e4;
  undefined *puStack_2e0;
  TiXmlText aTStack_2d4 [8];
  undefined **appuStack_2cc [4];
  undefined1 auStack_2bc [8];
  undefined1 auStack_2b4 [4];
  undefined1 auStack_2b0 [32];
  undefined **appuStack_290 [12];
  TiXmlText aTStack_260 [8];
  undefined **appuStack_258 [3];
  TiXmlElement aTStack_24c [8];
  undefined **appuStack_244 [3];
  TiXmlNode aTStack_238 [16];
  TiXmlElement aTStack_228 [4];
  TiXmlNode aTStack_224 [4];
  TiXmlNode aTStack_220 [8];
  TiXmlNode aTStack_218 [16];
  TiXmlElement aTStack_208 [4];
  TiXmlNode aTStack_204 [52];
  TiXmlNode aTStack_1d0 [44];
  TiXmlElement aTStack_1a4 [4];
  TiXmlElement aTStack_1a0 [4];
  TiXmlNode aTStack_19c [4];
  TiXmlNode aTStack_198 [40];
  TiXmlElement aTStack_170 [4];
  TiXmlElement aTStack_16c [4];
  TiXmlNode aTStack_168 [4];
  TiXmlNode aTStack_164 [80];
  TiXmlElement aTStack_114 [40];
  TiXmlElement aTStack_ec [4];
  TiXmlNode aTStack_e8 [4];
  TiXmlNode aTStack_e4 [4];
  TiXmlElement aTStack_e0 [4];
  TiXmlNode aTStack_dc [4];
  TiXmlNode aTStack_d8 [76];
  undefined1 uStack_8c;
  undefined1 uStack_88;
  int iStack_84;
  undefined1 uStack_7c;
  undefined1 uStack_74;
  undefined1 uStack_70;
  void *apvStack_6c [2];
  undefined1 uStack_64;
  undefined1 uStack_60;
  undefined1 uStack_58;
  undefined1 uStack_54;
  undefined1 uStack_4c;
  undefined1 uStack_44;
  undefined1 uStack_40;
  undefined1 uStack_30;
  undefined1 uStack_2c;
  undefined1 uStack_28;
  undefined1 uStack_24;
  undefined1 uStack_20;
  undefined1 uStack_1c;
  undefined1 uStack_18;
  undefined1 uStack_14;
  undefined1 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ab8512;
  local_c = ExceptionList;
  pGVar1 = (GmFrustumIso4 *)(DAT_00cca150 ^ (uint)&stack0xfffffd08);
  ExceptionList = &local_c;
  if ((param_2 != (CFastString *)0x0) &&
     (iVar2 = (**(code **)(*(int *)param_2 + 0x18))(), iVar2 != 0)) {
    pCVar14 = (CFastBuffer<class_CFastString> *)0x6ca2e6;
    CClassicBufferMemory::Reset((CClassicBufferMemory *)param_2,pGVar1);
    puVar15 = (undefined *)0x6ca2ef;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(auStack_2b4,unaff_EDI);
    this_00 = CFastBuffer<class_CFastString>::AddNewElem(auStack_2b0,unaff_ESI);
    pcVar7 = (char *)(*(int *)(param_2 + 0x14) + *(int *)(param_2 + 0xc));
    pcVar3 = (char *)(**(code **)(*(int *)param_2 + 0x18))();
    CFastString::SetString
              ((CFastString *)this_00,(CFastStringInt *)&stack0xfffffca0,in_stack_fffffc74);
    TiXmlElement::TiXmlElement(aTStack_228,(TiXmlElement *)"params",in_stack_fffffc78);
    uStack_8c = 1;
    TiXmlText::TiXmlText(aTStack_2d4,*(TiXmlText **)(iStack_84 + 4),in_stack_fffffc7c);
    uStack_88 = 2;
    TiXmlElement::TiXmlElement(aTStack_e0,(TiXmlElement *)&DAT_00b47d3c,in_stack_fffffc80);
    iStack_84 = CONCAT31(iStack_84._1_3_,3);
    TiXmlNode::InsertEndChild(aTStack_dc,(TiXmlNode *)appuStack_2cc,in_stack_fffffc84);
    TiXmlNode::InsertEndChild(aTStack_218,aTStack_d8,in_stack_fffffc88);
    pcVar8 = (char *)0x0;
    uStack_7c = 4;
    pTVar9 = (TiXmlNode *)PTR_DAT_00bbf7d8;
    CFastStringInt::GetUtf8
              (apvStack_6c[0],(CFastStringInt *)&stack0xfffffcb0,(CFastString *)0x0,
               in_stack_fffffc8c);
    TiXmlText::TiXmlText
              ((TiXmlText *)&stack0xfffffd10,(TiXmlText *)in_stack_fffffcb8,in_stack_fffffc90);
    uStack_74 = 5;
    TiXmlElement::TiXmlElement(aTStack_16c,(TiXmlElement *)&DAT_00b51d10,in_stack_fffffc94);
    uStack_70 = 6;
    TiXmlNode::InsertEndChild(aTStack_168,(TiXmlNode *)&uStack_2e8,in_stack_fffffc98);
    TiXmlNode::InsertEndChild(aTStack_204,aTStack_164,in_stack_fffffc9c);
    CFastString::CFastString
              ((CFastString *)&stack0xfffffcb4,(CFastString *)"ReportInvalidReplay",pcVar7);
    uStack_64 = 7;
    TiXmlElement::TiXmlElement(aTStack_24c,(TiXmlElement *)"request",pcVar3);
    uStack_60 = 9;
    pCVar10 = in_stack_fffffcc0;
    pTVar12 = (TiXmlElement *)PTR_DAT_00bbf7d8;
    CFastString::SetString
              ((CFastString *)&stack0xfffffcdc,(CFastStringInt *)&stack0xfffffcd4,in_stack_fffffca8)
    ;
    pTVar13 = (TiXmlElement *)appuStack_244;
    TiXmlText::TiXmlText((TiXmlText *)&stack0xfffffcfc,in_stack_fffffcc4,in_stack_fffffcac);
    uStack_58 = 10;
    TiXmlElement::TiXmlElement(aTStack_1a0,(TiXmlElement *)&DAT_00b32cb4,pcVar8);
    uStack_54 = 0xb;
    TiXmlNode::InsertEndChild(aTStack_19c,(TiXmlNode *)&stack0xfffffd04,pTVar9);
    TiXmlNode::InsertEndChild(aTStack_238,aTStack_198,in_stack_fffffcb8);
    pTVar11 = (TiXmlElement *)0x0;
    uStack_4c = 0xc;
    pTVar9 = (TiXmlNode *)PTR_DAT_00bbf7d8;
    CNetMasterServer::FindValidationData
              ((CNetMasterServer *)this,(CNetMasterServer *)&stack0xfffffcd0,
               (CFastString *)&stack0xfffffcd8,in_stack_fffffcbc);
    TiXmlText::TiXmlText(aTStack_260,(TiXmlText *)pTVar12,in_stack_fffffcc0);
    uStack_44 = 0xd;
    TiXmlElement::TiXmlElement(aTStack_ec,(TiXmlElement *)"validation",(char *)in_stack_fffffcc4);
    uStack_40 = 0xe;
    TiXmlNode::InsertEndChild(aTStack_e8,(TiXmlNode *)appuStack_258,in_stack_fffffcc8);
    if (pTVar13 != (TiXmlElement *)0x0) {
      TiXmlNode::InsertEndChild(aTStack_224,aTStack_e4,in_stack_fffffccc);
    }
    TiXmlNode::InsertEndChild(aTStack_220,aTStack_1d0,in_stack_fffffcd0);
    pCVar4 = CNetMasterServer::SendMasterServerRequest
                       ((CNetMasterServer *)this,(CNetMasterServer *)&stack0xfffffce8,
                        (CFastString *)&stack0xfffffd08,(SRequestElement *)0x0,
                        (CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
                         *)pCVar10);
    uStack_30 = 0xd;
    TiXmlElement::~TiXmlElement((TiXmlElement *)aTStack_d8,pTVar11);
    uStack_2c = 0xc;
    appuStack_244[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)appuStack_244,pTVar9);
    if (pCVar14 != (CFastBuffer<class_CFastString> *)PTR_DAT_00bbf7d8) {
      pCVar6 = pCVar14 + -1;
      if (((byte)pCVar14[-1] & 0x80) != 0) {
        pCVar6 = pCVar14 + -4;
      }
      operator_delete__(pCVar6);
      in_stack_fffffcfc = (TiXmlElement *)0x0;
      pCVar14 = (CFastBuffer<class_CFastString> *)PTR_DAT_00bbf7d8;
    }
    uStack_28 = 10;
    TiXmlElement::~TiXmlElement(aTStack_170,pTVar12);
    uStack_24 = 9;
    appuStack_2cc[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)appuStack_2cc,in_stack_fffffce4);
    if (puStack_2e0 != PTR_DAT_00bbf7d8) {
      puVar5 = puStack_2e0 + -1;
      if ((puStack_2e0[-1] & 0x80) != 0) {
        puVar5 = puStack_2e0 + -4;
      }
      operator_delete__(puVar5);
      puStack_2e4 = (undefined *)0x0;
      puStack_2e0 = PTR_DAT_00bbf7d8;
    }
    uStack_20 = 7;
    TiXmlElement::~TiXmlElement(aTStack_208,pTVar13);
    if (puVar15 != PTR_DAT_00bbf7d8) {
      puVar5 = puVar15 + -1;
      if ((puVar15[-1] & 0x80) != 0) {
        puVar5 = puVar15 + -4;
      }
      operator_delete__(puVar5);
      pCVar14 = (CFastBuffer<class_CFastString> *)0x0;
    }
    uStack_1c = 5;
    TiXmlElement::~TiXmlElement(aTStack_114,in_stack_fffffcec);
    uStack_18 = 4;
    appuStack_290[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)appuStack_290,in_stack_fffffcf0);
    if (puStack_2e4 != PTR_DAT_00bbf7d8) {
      puVar15 = puStack_2e4 + -1;
      if ((puStack_2e4[-1] & 0x80) != 0) {
        puVar15 = puStack_2e4 + -4;
      }
      operator_delete__(puVar15);
      uStack_2e8 = 0;
      puStack_2e4 = PTR_DAT_00bbf7d8;
    }
    uStack_14 = 2;
    TiXmlElement::~TiXmlElement((TiXmlElement *)apvStack_6c,in_stack_fffffcf4);
    uStack_10 = 1;
    appuStack_258[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)appuStack_258,in_stack_fffffcf8);
    local_c = (void *)((uint)local_c & 0xffffff00);
    TiXmlElement::~TiXmlElement(aTStack_1a4,in_stack_fffffcfc);
    puStack_8 = (undefined1 *)0xffffffff;
    CFastBuffer<class_CFastString>::~CFastBuffer<class_CFastString>(auStack_2bc,pCVar14);
    ExceptionList = local_c;
    return pCVar4;
  }
  *(undefined4 *)(this + 0x34) = 0xfffffff9;
  ExceptionList = local_c;
  return (CNetMasterServerRequest *)0x0;
}
}

// =================================================
// Function: CGameMasterServer::SimulateSendAliveUpdate
// =================================================
void __thiscall
CGameMasterServer::SimulateSendAliveUpdate(CGameMasterServer *this,CGameMasterServer *param_1)
{
{
  ulong uVar1;
  CMwTimer *unaff_ESI;
  
  uVar1 = CMwTimer::GetElapsedTimeSinceInit((void *)(DAT_00d731e0 + 0x70),unaff_ESI);
  *(ulong *)(this + 0x1e0) = uVar1;
  return;
}
}

