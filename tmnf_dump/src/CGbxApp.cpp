// Class implementation: CGbxApp

// =================================================
// Function: CGbxApp::Init
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGbxApp::Init(CGbxApp *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2,
             CVisionViewportDx9 *param_3,ESpriteColor0 *param_4)
{
{
  CGbxApp *pCVar1;
  CVisionViewportDx9 *pCVar2;
  int iVar3;
  CMwEngineMain *pCVar4;
  CMwEngineMain *this_00;
  SCasterCat *pSVar5;
  CMwEngine *extraout_EAX;
  CMwEngine *extraout_EAX_00;
  CSystemEngine *pCVar6;
  CMwEngine *extraout_EAX_01;
  CMwEngine *extraout_EAX_02;
  CMwEngine *extraout_EAX_03;
  CMwEngine *extraout_EAX_04;
  CMwEngine *extraout_EAX_05;
  CMwEngine *extraout_EAX_06;
  CMwEngine *extraout_EAX_07;
  CMwEngine *extraout_EAX_08;
  CMwEngine *extraout_EAX_09;
  CMwEngine *extraout_EAX_10;
  CMwEngine *extraout_EAX_11;
  undefined4 extraout_EAX_12;
  undefined4 uVar7;
  CSystemFids *extraout_EAX_13;
  int iVar8;
  int unaff_EBX;
  CMwEngine *unaff_EBP;
  CMwCmdBufferCore *unaff_ESI;
  CMwEngine *pCVar9;
  CMwEngine *pCVar10;
  CMwNod *this_01;
  CMwNod *unaff_EDI;
  CMwEngine *pCVar11;
  CAudioEngine *in_stack_00000014;
  CMotionEngine *in_stack_00000018;
  CMwEngine *in_stack_0000001c;
  CMwEngine *in_stack_00000020;
  CVisionEngine *in_stack_00000024;
  CFunctionEngine *in_stack_00000028;
  CMwEngine *in_stack_0000002c;
  CMwEngine *in_stack_00000030;
  CMotionEngine *in_stack_00000034;
  CHmsEngine *in_stack_00000038;
  CMwEngine *in_stack_0000003c;
  CMwEngine *in_stack_00000040;
  CFunctionEngine *in_stack_00000044;
  CSceneEngine *in_stack_00000048;
  CMwEngine *in_stack_0000004c;
  CMwEngine *in_stack_00000050;
  CHmsEngine *in_stack_00000054;
  CGameEngine *in_stack_00000058;
  CMwEngine *in_stack_0000005c;
  CMwEngine *in_stack_00000060;
  CSceneEngine *in_stack_00000064;
  CInputEngine *in_stack_00000068;
  CMwEngine *in_stack_0000006c;
  CMwEngine *in_stack_00000070;
  CGameEngine *in_stack_00000074;
  CControlEngine *in_stack_00000078;
  CMwEngine *in_stack_0000007c;
  CMwEngine *in_stack_00000080;
  CInputEngine *in_stack_00000084;
  CNetEngine *in_stack_00000088;
  CMwEngine *in_stack_0000008c;
  CMwEngine *in_stack_00000090;
  CControlEngine *in_stack_00000094;
  CSystemFile *in_stack_00000098;
  SStringParam *in_stack_0000009c;
  SStringParam *in_stack_000000a0;
  CNetEngine *in_stack_000000a4;
  CMwNodRef<class_CSystemConfig> *in_stack_000000a8;
  CSystemEngine *in_stack_000000ac;
  CSystemConfig *in_stack_000000b0;
  CSystemFile *in_stack_000000b4;
  CSystemConfigDisplay *in_stack_000000b8;
  char *in_stack_000000bc;
  CSystemEngine *in_stack_000000c0;
  CSystemEngine *in_stack_000000c4;
  CSystemFids *in_stack_000000c8;
  CSystemFids *in_stack_000000cc;
  int in_stack_000000d0;
  SNationConfig *in_stack_000000d4;
  CSystemFids *in_stack_000000d8;
  ulong in_stack_000000dc;
  undefined1 in_stack_000000e0;
  SHeaderCommunity in_stack_000000e4;
  undefined1 in_stack_000000e8;
  undefined1 in_stack_000000ec;
  undefined1 uStack00000108;
  void *in_stack_0000011c;
  undefined4 uStack00000120;
  SStringParam *pSVar12;
  SNationConfig *in_stack_ffffffc0;
  ulong in_stack_ffffffc4;
  CMwEngine *in_stack_ffffffcc;
  CMwEngine *in_stack_ffffffd0;
  ulong in_stack_ffffffd4;
  CPlugEngine *in_stack_ffffffd8;
  CMwEngine *pCVar13;
  CMwEngine *pCVar14;
  CMwFoundationsEngine *in_stack_ffffffe4;
  CSystemEngine *in_stack_ffffffe8;
  CMwEngine *pCVar15;
  CPlugEngine *this_02;
  CAudioEngine *pCVar16;
  
  pSVar12 = (SStringParam *)&stack0xfffffffc;
  pCVar15 = (CMwEngine *)&LAB_00a94ced;
  pCVar4 = (CMwEngineMain *)(DAT_00cca150 ^ (uint)&stack0xffffffb0);
  pCVar10 = ExceptionList;
  ExceptionList = &stack0xffffffec;
  CFastAssert::StaticInit();
  CMwId::StaticInit();
  CMwNod::StaticInit();
  this_00 = operator_new(0x34);
  this_02 = (CPlugEngine *)0x0;
  if (this_00 != (CMwEngineMain *)0x0) {
    CMwEngineMain::CMwEngineMain(this_00,pCVar4);
  }
  pCVar16 = (CAudioEngine *)0xffffffff;
  CMwNod::MwAddRef(DAT_00d73300,unaff_EDI);
  CMwCmdBufferCore::CreateCoreCmdBuffer();
  CMwCmdBufferCore::InitCmdBuffer(DAT_00d731e0,unaff_ESI);
  DAT_00d72ec8 = OnAccessViolation_ConcatToCrashFileName;
  DAT_00d72ecc = OnAccessViolation;
  pCVar13 = (CMwEngine *)0x0;
  pCVar11 = (CMwEngine *)0x2;
  pCVar14 = (CMwEngine *)PTR_DAT_00bbf7dc;
  CSystemEngine::GetLogRootPath
            ((CFastString *)(this + 0xc4),(CFastStringInt *)(this + 0xcc),
             (CFastStringInt *)(this + 0xd4),(CFastStringInt *)&stack0xffffffdc);
  CSystemManagerFile::MakeDir((CFastStringInt *)&stack0xffffffdc);
  CFastStringInt::CFastStringInt(&stack0xffffffec,(CFastStringInt *)&DAT_00b30b8c,pSVar12);
  param_1 = (CLoadGeomDynaSprite *)CONCAT31(param_1._1_3_,3);
  CClassicLog::SetOutputFile
            ((CClassicLog *)&DAT_00d71e20,(CClassicLog *)&stack0xffffffdc,
             (CFastStringInt *)&stack0xfffffff0,(CFastStringInt *)0x0,unaff_EBX);
  param_2 = (CPlugVisualSprite *)CONCAT31(param_2._1_3_,2);
  CGameCtnApp::SNationConfig::~SNationConfig(&stack0xfffffff4,in_stack_ffffffc0);
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (DAT_00d73300 + 0x20,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                      in_stack_ffffffc4);
  if (*(int *)pSVar5 == 0) {
    in_stack_ffffffe4 = operator_new(0x20);
    param_4 = (ESpriteColor0 *)CONCAT31(param_4._1_3_,4);
    if (in_stack_ffffffe4 == (CMwFoundationsEngine *)0x0) {
      pCVar9 = (CMwEngine *)0x0;
    }
    else {
      CMwFoundationsEngine::CMwFoundationsEngine(in_stack_ffffffe4,(CMwFoundationsEngine *)this_00);
      pCVar9 = extraout_EAX;
    }
    in_stack_00000014 = (CAudioEngine *)CONCAT31(in_stack_00000014._1_3_,2);
    *(undefined4 *)(pCVar9 + 0x14) = 0x1000000;
    CMwEngine::AllocateGroups(pCVar9,in_stack_ffffffcc);
    CMwEngineMain::AddEngine
              ((CMwEngineMain *)DAT_00d73300,(CMwEngineMain *)0x1000000,(ulong)pCVar9,
               in_stack_ffffffd0);
  }
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (DAT_00d73300 + 0x20,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000009,
                      in_stack_ffffffd4);
  if (*(int *)pSVar5 == 0) {
    this_02 = operator_new(0x24);
    in_stack_00000020 = (CMwEngine *)CONCAT31(in_stack_00000020._1_3_,5);
    if (this_02 == (CPlugEngine *)0x0) {
      pCVar9 = (CMwEngine *)0x0;
    }
    else {
      CPlugEngine::CPlugEngine(this_02,in_stack_ffffffd8);
      pCVar9 = extraout_EAX_00;
    }
    in_stack_00000024 = (CVisionEngine *)CONCAT31(in_stack_00000024._1_3_,2);
    *(undefined4 *)(pCVar9 + 0x14) = 0x9000000;
    CMwEngine::AllocateGroups(pCVar9,pCVar13);
    CMwEngineMain::AddEngine
              ((CMwEngineMain *)DAT_00d73300,(CMwEngineMain *)0x9000000,(ulong)pCVar9,pCVar14);
  }
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (DAT_00d73300 + 0x20,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                      (ulong)in_stack_ffffffe4);
  if (*(int *)pSVar5 == 0) {
    pCVar6 = operator_new(0x70);
    in_stack_00000030 = (CMwEngine *)CONCAT31(in_stack_00000030._1_3_,6);
    if (pCVar6 == (CSystemEngine *)0x0) {
      param_1 = (CLoadGeomDynaSprite *)0x0;
    }
    else {
      CSystemEngine::CSystemEngine(pCVar6,in_stack_ffffffe8);
      param_1 = (CLoadGeomDynaSprite *)extraout_EAX_01;
    }
    in_stack_00000034 = (CMotionEngine *)CONCAT31(in_stack_00000034._1_3_,2);
    *(undefined4 *)(param_1 + 0x14) = 0xb000000;
    CMwEngine::AllocateGroups((CMwEngine *)param_1,pCVar10);
    CMwEngineMain::AddEngine
              ((CMwEngineMain *)DAT_00d73300,(CMwEngineMain *)0xb000000,(ulong)param_1,pCVar15);
  }
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (DAT_00d73300 + 0x20,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x10,
                      (ulong)this_02);
  if (*(int *)pSVar5 == 0) {
    in_stack_00000014 = operator_new(0x30);
    in_stack_00000040 = (CMwEngine *)CONCAT31(in_stack_00000040._1_3_,7);
    if (in_stack_00000014 == (CAudioEngine *)0x0) {
      pCVar10 = (CMwEngine *)0x0;
    }
    else {
      CAudioEngine::CAudioEngine(in_stack_00000014,pCVar16);
      pCVar10 = extraout_EAX_02;
    }
    in_stack_00000044 = (CFunctionEngine *)CONCAT31(in_stack_00000044._1_3_,2);
    *(undefined4 *)(pCVar10 + 0x14) = 0x10000000;
    CMwEngine::AllocateGroups(pCVar10,unaff_EBP);
    CMwEngineMain::AddEngine
              ((CMwEngineMain *)DAT_00d73300,(CMwEngineMain *)0x10000000,(ulong)pCVar10,pCVar11);
  }
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (DAT_00d73300 + 0x20,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000c,(ulong)param_1
                     );
  if (*(int *)pSVar5 == 0) {
    in_stack_00000024 = operator_new(0x30);
    in_stack_00000050 = (CMwEngine *)CONCAT31(in_stack_00000050._1_3_,8);
    if (in_stack_00000024 == (CVisionEngine *)0x0) {
      pCVar10 = (CMwEngine *)0x0;
    }
    else {
      CVisionEngine::CVisionEngine(in_stack_00000024,(CVisionEngine *)param_2);
      pCVar10 = extraout_EAX_03;
    }
    in_stack_00000054 = (CHmsEngine *)CONCAT31(in_stack_00000054._1_3_,2);
    *(undefined4 *)(pCVar10 + 0x14) = 0xc000000;
    CMwEngine::AllocateGroups(pCVar10,(CMwEngine *)param_3);
    CMwEngineMain::AddEngine
              ((CMwEngineMain *)DAT_00d73300,(CMwEngineMain *)0xc000000,(ulong)pCVar10,
               (CMwEngine *)param_4);
  }
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (DAT_00d73300 + 0x20,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000008,
                      (ulong)in_stack_00000014);
  if (*(int *)pSVar5 == 0) {
    in_stack_00000034 = operator_new(0x20);
    in_stack_00000060 = (CMwEngine *)CONCAT31(in_stack_00000060._1_3_,9);
    if (in_stack_00000034 == (CMotionEngine *)0x0) {
      pCVar10 = (CMwEngine *)0x0;
    }
    else {
      CMotionEngine::CMotionEngine(in_stack_00000034,in_stack_00000018);
      pCVar10 = extraout_EAX_04;
    }
    in_stack_00000064 = (CSceneEngine *)CONCAT31(in_stack_00000064._1_3_,2);
    *(undefined4 *)(pCVar10 + 0x14) = 0x8000000;
    CMwEngine::AllocateGroups(pCVar10,in_stack_0000001c);
    CMwEngineMain::AddEngine
              ((CMwEngineMain *)DAT_00d73300,(CMwEngineMain *)0x8000000,(ulong)pCVar10,
               in_stack_00000020);
  }
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (DAT_00d73300 + 0x20,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000005,
                      (ulong)in_stack_00000024);
  if (*(int *)pSVar5 == 0) {
    in_stack_00000044 = operator_new(0x20);
    in_stack_00000070 = (CMwEngine *)CONCAT31(in_stack_00000070._1_3_,10);
    if (in_stack_00000044 == (CFunctionEngine *)0x0) {
      pCVar10 = (CMwEngine *)0x0;
    }
    else {
      CFunctionEngine::CFunctionEngine(in_stack_00000044,in_stack_00000028);
      pCVar10 = extraout_EAX_05;
    }
    in_stack_00000074 = (CGameEngine *)CONCAT31(in_stack_00000074._1_3_,2);
    *(undefined4 *)(pCVar10 + 0x14) = 0x5000000;
    CMwEngine::AllocateGroups(pCVar10,in_stack_0000002c);
    CMwEngineMain::AddEngine
              ((CMwEngineMain *)DAT_00d73300,(CMwEngineMain *)0x5000000,(ulong)pCVar10,
               in_stack_00000030);
  }
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (DAT_00d73300 + 0x20,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000006,
                      (ulong)in_stack_00000034);
  if (*(int *)pSVar5 == 0) {
    in_stack_00000054 = operator_new(0x28);
    in_stack_00000080 = (CMwEngine *)CONCAT31(in_stack_00000080._1_3_,0xb);
    if (in_stack_00000054 == (CHmsEngine *)0x0) {
      pCVar10 = (CMwEngine *)0x0;
    }
    else {
      CHmsEngine::CHmsEngine(in_stack_00000054,in_stack_00000038);
      pCVar10 = extraout_EAX_06;
    }
    in_stack_00000084 = (CInputEngine *)CONCAT31(in_stack_00000084._1_3_,2);
    *(undefined4 *)(pCVar10 + 0x14) = 0x6000000;
    CMwEngine::AllocateGroups(pCVar10,in_stack_0000003c);
    CMwEngineMain::AddEngine
              ((CMwEngineMain *)DAT_00d73300,(CMwEngineMain *)0x6000000,(ulong)pCVar10,
               in_stack_00000040);
  }
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (DAT_00d73300 + 0x20,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000a,
                      (ulong)in_stack_00000044);
  if (*(int *)pSVar5 == 0) {
    in_stack_00000064 = operator_new(0x28);
    in_stack_00000090 = (CMwEngine *)CONCAT31(in_stack_00000090._1_3_,0xc);
    if (in_stack_00000064 == (CSceneEngine *)0x0) {
      pCVar10 = (CMwEngine *)0x0;
    }
    else {
      CSceneEngine::CSceneEngine(in_stack_00000064,in_stack_00000048);
      pCVar10 = extraout_EAX_07;
    }
    in_stack_00000094 = (CControlEngine *)CONCAT31(in_stack_00000094._1_3_,2);
    *(undefined4 *)(pCVar10 + 0x14) = 0xa000000;
    CMwEngine::AllocateGroups(pCVar10,in_stack_0000004c);
    CMwEngineMain::AddEngine
              ((CMwEngineMain *)DAT_00d73300,(CMwEngineMain *)0xa000000,(ulong)pCVar10,
               in_stack_00000050);
  }
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (DAT_00d73300 + 0x20,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                      (ulong)in_stack_00000054);
  if (*(int *)pSVar5 == 0) {
    in_stack_00000074 = operator_new(0x20);
    in_stack_000000a0 = (SStringParam *)CONCAT31(in_stack_000000a0._1_3_,0xd);
    if (in_stack_00000074 == (CGameEngine *)0x0) {
      pCVar10 = (CMwEngine *)0x0;
    }
    else {
      CGameEngine::CGameEngine(in_stack_00000074,in_stack_00000058);
      pCVar10 = extraout_EAX_08;
    }
    in_stack_000000a4 = (CNetEngine *)CONCAT31(in_stack_000000a4._1_3_,2);
    *(undefined4 *)(pCVar10 + 0x14) = 0x3000000;
    CMwEngine::AllocateGroups(pCVar10,in_stack_0000005c);
    CMwEngineMain::AddEngine
              ((CMwEngineMain *)DAT_00d73300,(CMwEngineMain *)0x3000000,(ulong)pCVar10,
               in_stack_00000060);
  }
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (DAT_00d73300 + 0x20,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000013,
                      (ulong)in_stack_00000064);
  if (*(int *)pSVar5 == 0) {
    in_stack_00000084 = operator_new(0x28);
    in_stack_000000b0 = (CSystemConfig *)CONCAT31(in_stack_000000b0._1_3_,0xe);
    if (in_stack_00000084 == (CInputEngine *)0x0) {
      pCVar10 = (CMwEngine *)0x0;
    }
    else {
      CInputEngine::CInputEngine(in_stack_00000084,in_stack_00000068);
      pCVar10 = extraout_EAX_09;
    }
    in_stack_000000b4 = (CSystemFile *)CONCAT31(in_stack_000000b4._1_3_,2);
    *(undefined4 *)(pCVar10 + 0x14) = 0x13000000;
    CMwEngine::AllocateGroups(pCVar10,in_stack_0000006c);
    CMwEngineMain::AddEngine
              ((CMwEngineMain *)DAT_00d73300,(CMwEngineMain *)0x13000000,(ulong)pCVar10,
               in_stack_00000070);
  }
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (DAT_00d73300 + 0x20,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000007,
                      (ulong)in_stack_00000074);
  if (*(int *)pSVar5 == 0) {
    in_stack_00000094 = operator_new(0x20);
    in_stack_000000c0 = (CSystemEngine *)CONCAT31(in_stack_000000c0._1_3_,0xf);
    if (in_stack_00000094 == (CControlEngine *)0x0) {
      pCVar10 = (CMwEngine *)0x0;
    }
    else {
      CControlEngine::CControlEngine(in_stack_00000094,in_stack_00000078);
      pCVar10 = extraout_EAX_10;
    }
    in_stack_000000c4 = (CSystemEngine *)CONCAT31(in_stack_000000c4._1_3_,2);
    *(undefined4 *)(pCVar10 + 0x14) = 0x7000000;
    CMwEngine::AllocateGroups(pCVar10,in_stack_0000007c);
    CMwEngineMain::AddEngine
              ((CMwEngineMain *)DAT_00d73300,(CMwEngineMain *)0x7000000,(ulong)pCVar10,
               in_stack_00000080);
  }
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (DAT_00d73300 + 0x20,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000012,
                      (ulong)in_stack_00000084);
  if (*(int *)pSVar5 == 0) {
    in_stack_000000a4 = operator_new(0x20);
    in_stack_000000d0 = CONCAT31(in_stack_000000d0._1_3_,0x10);
    if (in_stack_000000a4 == (CNetEngine *)0x0) {
      pCVar10 = (CMwEngine *)0x0;
    }
    else {
      CNetEngine::CNetEngine(in_stack_000000a4,in_stack_00000088);
      pCVar10 = extraout_EAX_11;
    }
    in_stack_000000d4 = (SNationConfig *)CONCAT31(in_stack_000000d4._1_3_,2);
    *(undefined4 *)(pCVar10 + 0x14) = 0x12000000;
    CMwEngine::AllocateGroups(pCVar10,in_stack_0000008c);
    CMwEngineMain::AddEngine
              ((CMwEngineMain *)DAT_00d73300,(CMwEngineMain *)0x12000000,(ulong)pCVar10,
               in_stack_00000090);
  }
  (**(code **)(*(int *)this + 0x98))();
  CSystemEngine::InitForGbxGame
            (in_stack_000000ac,*(CSystemEngine **)(this + 0x2c),(ulong)(this + 0xbc),
             (CFastString *)(this + 0xc4),(CFastString *)(this + 0xcc),
             (CFastStringInt *)(this + 0xd4),(CFastStringInt *)in_stack_00000094);
  if (*(int *)(this + 0xb4) == 0) {
    in_stack_000000b4 = operator_new(0x1028);
    in_stack_000000e0 = 0x11;
    if (in_stack_000000b4 == (CSystemFile *)0x0) {
      uVar7 = 0;
    }
    else {
      CSystemFile::CSystemFile(in_stack_000000b4,in_stack_00000098);
      uVar7 = extraout_EAX_12;
    }
    in_stack_000000e4 = (SHeaderCommunity)0x2;
    *(undefined4 *)(this + 0xec) = uVar7;
    CFastStringInt::CFastStringInt
              (&stack0x000000d0,(CFastStringInt *)&stack0x000000c0,in_stack_0000009c);
    in_stack_000000e8 = 0x12;
    in_stack_000000bc = "Logs\\";
    in_stack_000000c0 = (CSystemEngine *)0x5;
    CFastStringInt::Concat(&stack0x000000d4,(CFastStringInt *)&stack0x000000bc,in_stack_000000a0);
    CSystemManagerFile::MakeDir((CFastStringInt *)&stack0x000000d8);
    in_stack_000000d0 = 0;
    in_stack_000000d4 = (SNationConfig *)PTR_DAT_00bbf7d8;
    in_stack_000000ec = 0x14;
    GetCurrentProcessId();
    CFastString::Format((CFastString *)&stack0x000000d0,(CFastString *)&stack0x000000d0,
                        "ConsoleLog.%d.txt");
    in_stack_000000c8 = (CSystemFids *)in_stack_000000dc;
    in_stack_000000cc = in_stack_000000d8;
    CFastStringInt::Concat
              (&stack0x000000e0,(CFastStringInt *)&stack0x000000c8,(SStringParam *)in_stack_000000ac
              );
    in_stack_000000ac = (CSystemEngine *)0x1;
    in_stack_000000a8 = (CMwNodRef<class_CSystemConfig> *)0x0;
    in_stack_000000a4 = (CNetEngine *)0x1;
    in_stack_000000a0 = (SStringParam *)0x0;
    CSystemFile::Open((_D3DXINCLUDE_TYPE)&stack0x000000e4,(char *)0x2,(void *)0x0,(void **)0x1,
                      (uint *)0x0);
    in_stack_000000e0 = 0x12;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0x000000c4,&stack0x000000e4);
    in_stack_000000e4 = (SHeaderCommunity)0x2;
    CGameCtnApp::SNationConfig::~SNationConfig(&stack0x000000d0,(SNationConfig *)0x2);
  }
  CMwCmdBufferCore::ForceFpuCwForSimulationX86((char *)0x0);
  _DAT_00d6e640 = 0;
  in_stack_000000bc = (char *)0x3043005;
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (&DAT_00d543f4,(TiXmlAttributeSet *)&stack0x000000bc,(TiXmlAttribute *)in_stack_000000a0
            );
  in_stack_000000c0 = (CSystemEngine *)0x3093001;
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (&DAT_00d543f4,(TiXmlAttributeSet *)&stack0x000000c0,(TiXmlAttribute *)in_stack_000000a4
            );
  pCVar1 = this + 0x30;
  CSystemEngine::LoadSystemConfigAndBindToFid
            (in_stack_000000c0,(CSystemEngine *)(this + 0xdc),(CFastStringInt *)0x0,(int)pCVar1,
             in_stack_000000a8);
  if (*(int *)(this + 0x78) != 4) {
    iVar8 = *(int *)pCVar1;
    if (*(int *)(iVar8 + 0x20) == 0) {
      iVar8 = *(int *)(iVar8 + 0x24);
    }
    else {
      iVar8 = *(int *)(iVar8 + 0x28);
    }
    *(int *)(iVar8 + 0x1c) = *(int *)(this + 0x78);
  }
  DAT_00d54380 = *(int *)pCVar1;
  pCVar2 = *(CVisionViewportDx9 **)(DAT_00d66ff8 + 0x30);
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (DAT_00d73300 + 0x20,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                      (ulong)in_stack_000000ac);
  CSystemEngine::ApplySystemConfig
            (*(CSystemEngine **)pSVar5,pCVar2,in_stack_000000b0,(int)in_stack_000000b4);
  CSystemConfig::ApplyDynamicPresets(*(CSystemConfig **)(DAT_00d66ff8 + 0x30),in_stack_000000b8);
  CFastStringInt::CFastStringInt
            (&stack0x000000f0,(CFastStringInt *)L"Packs\\",(SStringParam *)in_stack_000000bc);
  uStack00000108 = 0x15;
  this_01 = DAT_00d73300 + 0x20;
  in_stack_000000bc = (char *)0xb;
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                      (ulong)in_stack_000000c0);
  iVar8 = *(int *)pSVar5;
  in_stack_000000c0 = (CSystemEngine *)0xb;
  in_stack_000000bc = (char *)0x52b6f9;
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                      (ulong)in_stack_000000c4);
  pCVar6 = *(CSystemEngine **)pSVar5;
  in_stack_000000c4 = (CSystemEngine *)0xb;
  in_stack_000000c0 = (CSystemEngine *)0x52b704;
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                      (ulong)in_stack_000000c8);
  iVar3 = *(int *)pSVar5;
  in_stack_000000c4 = *(CSystemEngine **)(iVar8 + 0x24);
  in_stack_000000c8 = (CSystemFids *)0x1;
  in_stack_000000c0 = (CSystemEngine *)0x52b713;
  in_stack_000000c4 = (CSystemEngine *)CSystemEngine::GetLocationData(pCVar6,in_stack_000000c4);
  in_stack_000000c0 = (CSystemEngine *)0x0;
  in_stack_000000bc = (char *)0x1;
  in_stack_000000c4 =
       (CSystemEngine *)
       CSystemFids::FindLocationDown
                 (*(CSystemFids **)(iVar3 + 0x2c),extraout_EAX_13,(CFastStringInt *)0x1,0,
                  (EFindWay)in_stack_000000c4);
  in_stack_000000c0 = (CSystemEngine *)0x0;
  in_stack_000000bc = (char *)0x0;
  CPlugFilePack::InstallPacks
            ("",0,(CClassicBuffer *)0x0,(CSystemFids *)in_stack_000000c4,in_stack_000000c8,
             in_stack_000000cc,in_stack_000000d0);
  in_stack_0000011c = (void *)CONCAT31(in_stack_0000011c._1_3_,2);
  in_stack_000000d0 = 0x52b741;
  CGameCtnApp::SNationConfig::~SNationConfig(&stack0x00000108,in_stack_000000d4);
  uStack00000120 = 0xffffffff;
  in_stack_000000d4 = (SNationConfig *)0x52b752;
  CGameCtnApp::SNationConfig::~SNationConfig(&stack0x000000fc,(SNationConfig *)in_stack_000000d8);
  ExceptionList = in_stack_0000011c;
  return;
}
}

