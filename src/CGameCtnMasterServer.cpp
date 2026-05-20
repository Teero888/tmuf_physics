// Class implementation: CGameCtnMasterServer

// =================================================
// Function: CGameCtnMasterServer::ReadData
// =================================================
void __thiscall
CGameCtnMasterServer::ReadData
          (CGameCtnMasterServer *this,CClassicArchive *param_1,void *param_2,ulong param_3)
{
{
  TiXmlNode *this_00;
  TiXmlElement *pTVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  CSystemFid *pCVar3;
  SLoadedLight *this_01;
  int iVar4;
  undefined *puVar5;
  TiXmlNode *pTVar6;
  CFastStringInt *unaff_EBX;
  CFastStringInt *unaff_ESI;
  char *unaff_EDI;
  SCasterCat *pSVar7;
  CSystemFids *in_stack_00000010;
  CSystemDataFolders *in_stack_00000014;
  TiXmlNode *in_stack_00000018;
  char *in_stack_ffffff54;
  CSystemFids *in_stack_ffffff58;
  CFastBuffer<class_CCrystalFace*> *pCVar8;
  ulong in_stack_ffffff64;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_ffffff68;
  CFastStringInt *pCVar9;
  SStringParam *pSVar10;
  undefined4 uVar11;
  CClassicBufferMemory *pCVar12;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar13;
  TiXmlNode *pTVar14;
  TiXmlNode *in_stack_ffffff80;
  undefined *local_7c;
  ulong local_74;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *local_70;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_6c;
  undefined4 local_68;
  undefined *local_64;
  undefined4 local_60;
  TiXmlNode *local_5c;
  TiXmlElement *local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int iStack_48;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *local_38;
  ulong local_34;
  undefined4 local_30;
  CFastStringInt local_28 [4];
  TiXmlNode *pTStack_24;
  undefined4 uStack_20;
  void *local_14;
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0xffffffff;
  local_10 = &LAB_00ab5029;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  this_00 = (TiXmlNode *)
            TiXmlNode::FirstChildElement
                      ((TiXmlNode *)param_1,in_stack_00000018,
                       (char *)(DAT_00cca150 ^ (uint)&stack0xffffff48));
  pTVar14 = (TiXmlNode *)0x0;
  pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pCVar9 = (CFastStringInt *)this_00;
  if (this_00 == (TiXmlNode *)0x0) {
    ExceptionList = local_10;
    return;
  }
  do {
    pCVar8 = (CFastBuffer<class_CCrystalFace*> *)0x0;
    local_8 = 0;
    puVar5 = PTR_DAT_00bbf7dc;
    pTVar1 = TiXmlNode::FirstChildElement(this_00,(TiXmlNode *)&DAT_00b2ef98,unaff_EDI);
    if (pTVar1 == (TiXmlElement *)0x0) {
      local_54 = DAT_00d71d5c;
      local_50 = DAT_00d71d58;
      local_4c = 0;
      CFastStringInt::SetString
                (&stack0xffffff60,(CFastStringInt *)&local_54,(SStringParam *)unaff_ESI);
    }
    else {
      uVar11 = 0;
      pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)PTR_DAT_00bbf7d8;
      CXmlEngine::ReadAssociatedText(pTVar1,(CFastStringInt *)&stack0xffffff74);
      local_6c = pCVar13;
      local_68 = uVar11;
      CFastStringInt::SetUtf8
                (&stack0xffffff60,(CFastStringInt *)&local_6c,(SStringParam *)unaff_ESI);
      if (pTVar14 != (TiXmlNode *)PTR_DAT_00bbf7d8) {
        pTVar6 = pTVar14 + -1;
        if (((byte)pTVar14[-1] & 0x80) != 0) {
          pTVar6 = pTVar14 + -4;
        }
        operator_delete__(pTVar6);
        pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        pTVar14 = (TiXmlNode *)PTR_DAT_00bbf7d8;
      }
    }
    local_74 = 0;
    local_70 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)PTR_DAT_00bbf7dc;
    local_30 = 0;
    local_38 = in_stack_ffffff68;
    local_34 = in_stack_ffffff64;
    CFastStringInt::SetString(&local_74,(CFastStringInt *)&local_38,(SStringParam *)unaff_EBX);
    unaff_EBX = (CFastStringInt *)&stack0xffffff68;
    unaff_ESI = (CFastStringInt *)&local_70;
    CPlugFont::GetPureString(unaff_ESI,unaff_EBX);
    unaff_EDI = (char *)0x2;
    CSystemFileName::FixFileName((CFastStringInt *)&stack0xffffff68,2);
    if (local_6c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)PTR_DAT_00bbf7dc) {
      unaff_EBX = (CFastStringInt *)(local_6c + -4);
      if (((byte)local_6c[-1] & 0x80) == 0) {
        unaff_EBX = (CFastStringInt *)(local_6c + -2);
      }
      unaff_ESI = (CFastStringInt *)0x6b0352;
      operator_delete__(unaff_EBX);
      local_70 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x0;
      local_6c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)PTR_DAT_00bbf7dc;
    }
    if (in_stack_ffffff68 == (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x0) {
      if (pCVar9 != (CFastStringInt *)PTR_DAT_00bbf7dc) {
        unaff_EBX = pCVar9 + -4;
        if (((byte)pCVar9[-1] & 0x80) == 0) {
          unaff_EBX = pCVar9 + -2;
        }
        unaff_ESI = (CFastStringInt *)0x6b0391;
        operator_delete__(unaff_EBX);
        in_stack_ffffff68 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x0;
        pCVar9 = (CFastStringInt *)PTR_DAT_00bbf7dc;
      }
    }
    else {
      pSVar10 = (SStringParam *)0x0;
      unaff_ESI = (CFastStringInt *)0x6b03c8;
      pCVar12 = (CClassicBufferMemory *)PTR_DAT_00bbf7d8;
      unaff_EBX = (CFastStringInt *)
                  TiXmlNode::FirstChildElement(this_00,(TiXmlNode *)&DAT_00b5dc68,in_stack_ffffff54)
      ;
      if (unaff_EBX == (CFastStringInt *)0x0) {
        local_58 = (TiXmlElement *)&DAT_00b2c878;
        local_54 = 0;
        unaff_EBX = (CFastStringInt *)0x6b03f2;
        CFastString::SetString
                  ((CFastString *)&stack0xffffff74,(CFastStringInt *)&local_58,
                   (SStringParam *)in_stack_ffffff58);
      }
      else {
        unaff_ESI = (CFastStringInt *)0x6b03d7;
        CXmlEngine::ReadAssociatedText((TiXmlElement *)unaff_EBX,(CFastStringInt *)&stack0xffffff74)
        ;
      }
      pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)param_2 + 0x2c),pCVar8);
      if (local_6c < pCVar2) {
        pSVar7 = CFastBuffer<struct_SFastCat>::operator[]
                           ((void *)((int)param_2 + 0x2c),local_6c,(ulong)puVar5);
      }
      else {
        pSVar7 = (SCasterCat *)0x0;
      }
      if ((in_stack_ffffff80 == (TiXmlNode *)0x0) &&
         ((pSVar7 == (SCasterCat *)0x0 || (*(int *)pSVar7 == 0)))) {
        local_64 = (undefined *)0x0;
        if (local_7c != PTR_DAT_00bbf7d8) {
          puVar5 = local_7c + -1;
          if ((local_7c[-1] & 0x80) != 0) {
            puVar5 = local_7c + -4;
          }
          operator_delete__(puVar5);
        }
        if (pTVar14 != (TiXmlNode *)PTR_DAT_00bbf7dc) {
          if (((byte)pTVar14[-1] & 0x80) == 0) {
            pTVar14 = pTVar14 + -2;
          }
          else {
            pTVar14 = pTVar14 + -4;
          }
          operator_delete__(pTVar14);
        }
        goto LAB_006b0623;
      }
      if (in_stack_00000010 == (CSystemFids *)0x0) {
        in_stack_ffffff58 = (CSystemFids *)0x0;
        in_stack_ffffff54 = &stack0xffffff78;
        unaff_ESI = (CFastStringInt *)0x6b0462;
        unaff_EBX = (CFastStringInt *)in_stack_00000014;
        pCVar3 = (CSystemFid *)
                 CSystemDataFolders::FindFidFromRelativeName
                           ((void *)(*(int *)(local_58 + 0x6b0) + 0x148),in_stack_00000014,
                            (ulong)in_stack_ffffff54,(CFastStringInt *)0x0,0,1,in_stack_ffffff64);
      }
      else {
        in_stack_ffffff58 = (CSystemFids *)&stack0xffffff78;
        in_stack_ffffff54 = (char *)0x6b043e;
        pCVar3 = CSystemFids::FindOrAddFid
                           (in_stack_00000010,in_stack_ffffff58,(CFastStringInt *)0x0,(ulong *)0x0,
                            in_stack_ffffff64);
      }
      this_01 = CFastBuffer<struct_CGameCtnMasterServer::SDownloadedData>::AddNewElem
                          ((void *)param_3,in_stack_ffffff68);
      uStack_20 = 0;
      in_stack_ffffff64 = 0x6b0492;
      pTStack_24 = in_stack_ffffff80;
      CFastStringInt::SetString(this_01,local_28,(SStringParam *)pCVar9);
      *(CSystemFid **)(this_01 + 0x10) = pCVar3;
      local_38 = local_70;
      pCVar9 = (CFastStringInt *)&local_38;
      local_34 = local_74;
      in_stack_ffffff68 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x6b04b2;
      CFastString::SetString((CFastString *)(this_01 + 8),pCVar9,pSVar10);
      *(undefined4 *)(this_01 + 0x14) = 0;
      if ((pSVar7 != (SCasterCat *)0x0) && (*(int *)pSVar7 != 0)) {
        local_5c = local_5c + 1;
        CClassicBufferMemory::CClassicBufferMemory((CClassicBufferMemory *)&local_8,pCVar12);
        pCVar9 = (CFastStringInt *)0x6b04ee;
        CClassicBuffer::WriteAll
                  ((CClassicBuffer *)&stack0xfffffffc,*(CClassicBuffer **)(pSVar7 + 4),
                   *(void **)pSVar7,(ulong)pCVar13);
        iVar4 = CSystemArchiveNod::SaveMemoryToFile(pCVar3,(CClassicBufferMemory *)&stack0x00000000)
        ;
        if (iVar4 != 0) {
          *(undefined4 *)(this_01 + 0x14) = 1;
        }
        CClassicBufferMemory::~CClassicBufferMemory
                  ((CClassicBufferMemory *)&stack0x00000000,(CClassicBufferMemory *)pTVar14);
      }
      pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x6b052b;
      pTVar14 = in_stack_00000018;
      local_58 = TiXmlNode::NextSiblingElement(local_5c,in_stack_00000018,(char *)in_stack_ffffff80)
      ;
      iStack_48 = iStack_48 + 1;
      if (local_5c != (TiXmlNode *)PTR_DAT_00bbf7d8) {
        in_stack_ffffff80 = local_5c + -1;
        if (((byte)local_5c[-1] & 0x80) != 0) {
          in_stack_ffffff80 = local_5c + -4;
        }
        pTVar14 = (TiXmlNode *)0x6b0552;
        operator_delete__(in_stack_ffffff80);
        local_60 = 0;
        local_5c = (TiXmlNode *)PTR_DAT_00bbf7d8;
      }
      this_00 = (TiXmlNode *)local_58;
      if (local_64 != PTR_DAT_00bbf7dc) {
        in_stack_ffffff80 = (TiXmlNode *)(local_64 + -4);
        if ((local_64[-1] & 0x80) == 0) {
          in_stack_ffffff80 = (TiXmlNode *)(local_64 + -2);
        }
        pTVar14 = (TiXmlNode *)0x6b0591;
        operator_delete__(in_stack_ffffff80);
        local_68 = 0;
        local_64 = PTR_DAT_00bbf7dc;
        this_00 = (TiXmlNode *)local_58;
      }
    }
    if (this_00 == (TiXmlNode *)0x0) {
LAB_006b0623:
      if (local_6c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        CFastBuffer<class_CFastString>::RemoveAt
                  ((void *)((int)param_2 + 0x2c),
                   (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)0x0,
                   (ulong)local_6c,in_stack_ffffff64);
      }
      ExceptionList = (void *)param_3;
      return;
    }
  } while( true );
}
}

// =================================================
// Function: CGameCtnMasterServer::ReadForcedManialinksParams
// =================================================
int __thiscall
CGameCtnMasterServer::ReadForcedManialinksParams
          (CGameCtnMasterServer *this,CGameCtnMasterServer *param_1,TiXmlElement *param_2)
{
{
  TiXmlElement *pTVar1;
  int iVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  SStringParam *unaff_EBX;
  char *unaff_ESI;
  ulong unaff_EDI;
  void *in_stack_0000000c;
  undefined4 uStack00000010;
  char *in_stack_ffffffe4;
  SStringParam *in_stack_ffffffe8;
  undefined *local_10;
  undefined1 *local_c;
  undefined1 *local_8;
  undefined *local_4;
  
  local_4 = (undefined *)0xffffffff;
  local_8 = &LAB_00ab3a18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pTVar1 = TiXmlNode::FirstChildElement
                     ((TiXmlNode *)param_1,(TiXmlNode *)&DAT_00b73bd0,
                      (char *)(DAT_00cca150 ^ (uint)&stack0xffffffd8));
  if (pTVar1 == (TiXmlElement *)0x0) {
    *(undefined4 *)(*(int *)(this + 0x108) + 0x6c4) = *(undefined4 *)(DAT_00d54380 + 0x144);
  }
  else {
    in_stack_ffffffe8 = (SStringParam *)0x0;
    CXmlEngine::ReadAssociatedText(pTVar1,(CFastStringInt *)&stack0xffffffe8);
    iVar2 = CFastString::GetNatural
                      ((CFastString *)&stack0xffffffe8,
                       (CFastString *)(*(int *)(this + 0x108) + 0x6c4),(ulong *)0x0,0,unaff_EDI);
    if (iVar2 == 0) {
      *(undefined4 *)(*(int *)(this + 0x108) + 0x6c4) = *(undefined4 *)(DAT_00d54380 + 0x144);
    }
    if (local_10 != PTR_DAT_00bbf7d8) {
      puVar3 = local_10 + -1;
      if ((local_10[-1] & 0x80) != 0) {
        puVar3 = local_10 + -4;
      }
      operator_delete__(puVar3);
    }
  }
  pTVar1 = TiXmlNode::FirstChildElement((TiXmlNode *)param_1,(TiXmlNode *)&DAT_00b2edcc,unaff_ESI);
  if (pTVar1 == (TiXmlElement *)0x0) {
    local_8 = &DAT_00b2c878;
    local_4 = (undefined *)0x0;
    CFastStringInt::SetString
              ((void *)(*(int *)(this + 0x108) + 0x6bc),(CFastStringInt *)&local_8,unaff_EBX);
  }
  else {
    local_10 = (undefined *)0x0;
    local_c = PTR_DAT_00bbf7d8;
    CXmlEngine::ReadAssociatedText(pTVar1,(CFastStringInt *)&local_10);
    local_4 = local_10;
    local_8 = local_c;
    CFastStringInt::SetUtf8
              ((void *)(*(int *)(this + 0x108) + 0x6bc),(CFastStringInt *)&local_8,unaff_EBX);
    in_stack_0000000c = (void *)0xffffffff;
    if (local_8 != PTR_DAT_00bbf7d8) {
      puVar4 = local_8 + -1;
      if ((local_8[-1] & 0x80) != 0) {
        puVar4 = local_8 + -4;
      }
      operator_delete__(puVar4);
    }
  }
  pTVar1 = TiXmlNode::FirstChildElement
                     ((TiXmlNode *)param_1,(TiXmlNode *)&DAT_00b519fc,in_stack_ffffffe4);
  if (pTVar1 == (TiXmlElement *)0x0) {
    local_8 = &DAT_00b2c878;
    local_4 = (undefined *)0x0;
    CFastStringInt::SetString
              ((void *)(*(int *)(this + 0x6b0) + 0x3fc),(CFastStringInt *)&local_8,in_stack_ffffffe8
              );
  }
  else {
    local_8 = (undefined1 *)0x0;
    local_4 = PTR_DAT_00bbf7d8;
    uStack00000010 = 2;
    CXmlEngine::ReadAssociatedText(pTVar1,(CFastStringInt *)&local_8);
    puVar3 = local_4;
    CFastStringInt::SetUtf8
              ((void *)(*(int *)(this + 0x6b0) + 0x3fc),(CFastStringInt *)&stack0x00000000,
               in_stack_ffffffe8);
    if (puVar3 != PTR_DAT_00bbf7d8) {
      puVar5 = puVar3 + -1;
      if ((puVar3[-1] & 0x80) != 0) {
        puVar5 = puVar3 + -4;
      }
      operator_delete__(puVar5);
    }
  }
  ExceptionList = in_stack_0000000c;
  return 1;
}
}

// =================================================
// Function: CGameCtnMasterServer::StopOfficialRecord
// =================================================
CGameMasterServerRequest * __thiscall
CGameCtnMasterServer::StopOfficialRecord
          (CGameCtnMasterServer *this,CGameCtnMasterServer *param_1,SOfficialRecordState *param_2)
{
{
  CGameMasterServerRequest *pCVar1;
  ulong uVar2;
  TiXmlElement *pTVar3;
  undefined *puVar4;
  char *unaff_EBX;
  CFastStringInt *unaff_EBP;
  int unaff_ESI;
  char *unaff_EDI;
  undefined1 uStack0000000c;
  undefined1 uStack00000010;
  undefined1 uStack00000018;
  undefined1 uStack00000020;
  undefined1 uStack00000024;
  undefined1 uStack0000002c;
  undefined1 uStack00000034;
  undefined1 uStack00000038;
  undefined1 uStack00000058;
  TiXmlElement TStack00000060;
  undefined1 uStack00000068;
  undefined1 uStack0000006c;
  undefined1 uStack00000074;
  undefined1 uStack0000007c;
  undefined1 uStack00000080;
  undefined1 uStack00000094;
  undefined1 uStack00000098;
  undefined1 uStack0000009c;
  undefined1 uStack000000a0;
  undefined1 uStack000000a4;
  undefined1 uStack000000a8;
  undefined1 uStack000000ac;
  undefined1 uStack000000b0;
  undefined1 uStack000000b4;
  undefined1 uStack000000b8;
  void *in_stack_000000bc;
  undefined4 uStack000000c0;
  TiXmlNode *in_stack_fffffc14;
  TiXmlNode *in_stack_fffffc18;
  int in_stack_fffffc1c;
  CFastStringInt *in_stack_fffffc20;
  char *in_stack_fffffc24;
  TiXmlNode *in_stack_fffffc28;
  TiXmlNode *in_stack_fffffc2c;
  int in_stack_fffffc30;
  CFastStringInt *in_stack_fffffc34;
  char *in_stack_fffffc38;
  TiXmlNode *pTVar5;
  CFastStringInt *in_stack_fffffc44;
  char *in_stack_fffffc48;
  TiXmlNode *in_stack_fffffc4c;
  TiXmlNode *in_stack_fffffc50;
  TiXmlElement *in_stack_fffffc54;
  TiXmlNode *pTVar6;
  SStringParam *pSVar7;
  TiXmlText *in_stack_fffffc60;
  char *pcVar8;
  SStringParam *in_stack_fffffc64;
  CFastStringInt *in_stack_fffffc68;
  char *in_stack_fffffc6c;
  TiXmlNode *pTVar9;
  char *pcVar10;
  CFastStringInt *pCVar11;
  CFastStringInt *pCVar12;
  CFastString *pCVar13;
  TiXmlNode *in_stack_fffffc88;
  TiXmlNode *in_stack_fffffc8c;
  CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
  *in_stack_fffffc90;
  TiXmlAttribute *in_stack_fffffc94;
  TiXmlElement *in_stack_fffffc98;
  TiXmlNode *in_stack_fffffca4;
  TiXmlElement *pTVar14;
  TiXmlElement *pTVar15;
  TiXmlNode *in_stack_fffffcb0;
  TiXmlElement *pTVar16;
  TiXmlNode *in_stack_fffffcb8;
  TiXmlElement *in_stack_fffffcbc;
  TiXmlNode *in_stack_fffffcc0;
  TiXmlElement *in_stack_fffffcc4;
  undefined *local_338;
  CFastString local_32c [4];
  TiXmlText local_328 [8];
  undefined4 local_320;
  undefined *local_31c;
  undefined4 local_314;
  undefined *local_310;
  TiXmlText local_30c [4];
  undefined4 local_308;
  undefined *local_304 [7];
  TiXmlElement local_2e8 [40];
  TiXmlText local_2c0 [8];
  TiXmlNode local_2b8 [12];
  undefined **local_2ac [6];
  TiXmlText local_294 [8];
  TiXmlNode local_28c [24];
  undefined **local_274 [7];
  undefined **local_258 [2];
  TiXmlNode local_250 [12];
  undefined **local_244 [14];
  undefined **local_20c [7];
  TiXmlText local_1f0 [8];
  TiXmlNode local_1e8 [12];
  TiXmlElement local_1dc [8];
  TiXmlElement local_1d4 [4];
  undefined **local_1d0 [2];
  TiXmlNode local_1c8 [20];
  TiXmlNode local_1b4 [4];
  TiXmlNode local_1b0 [28];
  TiXmlElement local_194 [20];
  TiXmlElement local_180 [4];
  TiXmlNode local_17c [4];
  TiXmlNode local_178 [20];
  TiXmlElement local_164 [4];
  TiXmlNode local_160 [4];
  TiXmlNode local_15c [16];
  TiXmlElement local_14c [92];
  TiXmlElement local_f0 [24];
  TiXmlElement local_d8 [4];
  TiXmlNode local_d4 [4];
  TiXmlNode local_d0 [4];
  TiXmlElement local_cc [4];
  TiXmlNode local_c8 [4];
  TiXmlNode local_c4 [16];
  TiXmlElement local_b4 [80];
  TiXmlElement local_64 [4];
  TiXmlNode local_60 [4];
  TiXmlNode local_5c [4];
  TiXmlElement local_58 [12];
  TiXmlElement local_4c [4];
  TiXmlNode local_48 [4];
  TiXmlNode local_44 [56];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ab3149;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 == (CGameCtnMasterServer *)0x0) {
    *(undefined4 *)(this + 0x34) = 0xfffffff9;
    pCVar1 = (CGameMasterServerRequest *)0x0;
  }
  else if ((*(int *)(this + 0x184) == 0) && (*(int *)(param_1 + 4) == 0)) {
    *(undefined4 *)(this + 0x34) = 0xfffffffd;
    pCVar1 = (CGameMasterServerRequest *)0x0;
  }
  else {
    uVar2 = CMwTimer::GetElapsedTimeSinceInit
                      ((void *)(DAT_00d731e0 + 0x70),
                       (CMwTimer *)(DAT_00cca150 ^ (uint)&stack0xfffffc04));
    *(ulong *)(param_1 + 0x30) = uVar2;
    TiXmlElement::TiXmlElement((TiXmlElement *)&stack0xfffffc58,(TiXmlElement *)"params",unaff_EDI);
    pTVar5 = (TiXmlNode *)0x0;
    pTVar9 = (TiXmlNode *)PTR_DAT_00bbf7d8;
    CFastStringInt::GetUtf8
              (this + 0x144,(CFastStringInt *)&stack0xfffffc3c,(CFastString *)0x0,unaff_ESI);
    TiXmlText::TiXmlText(local_2c0,(TiXmlText *)in_stack_fffffc44,unaff_EBP);
    uStack0000000c = 2;
    TiXmlElement::TiXmlElement(local_4c,(TiXmlElement *)&DAT_00b7ddec,unaff_EBX);
    uStack00000010 = 3;
    TiXmlNode::InsertEndChild(local_48,local_2b8,in_stack_fffffc14);
    TiXmlNode::InsertEndChild((TiXmlNode *)&stack0xfffffc6c,local_44,in_stack_fffffc18);
    pTVar6 = (TiXmlNode *)0x0;
    uStack00000018 = 4;
    CFastString::SetNatural
              ((CFastString *)&stack0xfffffc58,*(CFastString **)(param_1 + 0xc),0,0,0,0,1,
               in_stack_fffffc1c);
    TiXmlText::TiXmlText(local_30c,in_stack_fffffc60,in_stack_fffffc20);
    uStack00000020 = 5;
    TiXmlElement::TiXmlElement(local_d8,(TiXmlElement *)&DAT_00b7de20,in_stack_fffffc24);
    uStack00000024 = 6;
    TiXmlNode::InsertEndChild(local_d4,(TiXmlNode *)local_304,in_stack_fffffc28);
    TiXmlNode::InsertEndChild((TiXmlNode *)&stack0xfffffc80,local_d0,in_stack_fffffc2c);
    pSVar7 = (SStringParam *)0x0;
    uStack0000002c = 7;
    pcVar8 = PTR_DAT_00bbf7d8;
    CFastString::SetNatural
              ((CFastString *)&stack0xfffffc5c,*(CFastString **)(param_1 + 0x10),0,0,0,0,1,
               in_stack_fffffc30);
    TiXmlText::TiXmlText(local_328,(TiXmlText *)in_stack_fffffc64,in_stack_fffffc34);
    uStack00000034 = 8;
    TiXmlElement::TiXmlElement(local_164,(TiXmlElement *)&DAT_00b7de1c,in_stack_fffffc38);
    uStack00000038 = 9;
    TiXmlNode::InsertEndChild(local_160,(TiXmlNode *)&local_320,pTVar5);
    TiXmlNode::InsertEndChild((TiXmlNode *)&stack0xfffffc94,local_15c,pTVar9);
    if (*(int *)(param_1 + 4) != 0) {
      TiXmlText::TiXmlText((TiXmlText *)local_258,*(TiXmlText **)(param_1 + 0x5c),in_stack_fffffc44)
      ;
      TiXmlElement::TiXmlElement(local_64,(TiXmlElement *)"cdata",in_stack_fffffc48);
      TiXmlNode::InsertEndChild(local_60,local_250,in_stack_fffffc4c);
      TiXmlNode::InsertEndChild((TiXmlNode *)&stack0xfffffca4,local_5c,in_stack_fffffc50);
      TiXmlElement::~TiXmlElement(local_58,in_stack_fffffc54);
      local_244[0] = TiXmlText::vftable;
      TiXmlNode::~TiXmlNode((TiXmlNode *)local_244,pTVar6);
    }
    pTVar9 = (TiXmlNode *)0x0;
    uStack00000058 = 0xc;
    if (*(int *)(param_1 + 4) == 0) {
      pcVar10 = "StopOfficialRecord";
      pCVar11 = (CFastStringInt *)&DAT_00000012;
    }
    else {
      pcVar10 = "StopCustomOfficialRecord";
      pCVar11 = (CFastStringInt *)0x18;
    }
    pTVar5 = (TiXmlNode *)PTR_DAT_00bbf7d8;
    CFastString::SetString
              ((CFastString *)&stack0xfffffc70,(CFastStringInt *)&stack0xfffffc78,pSVar7);
    TiXmlElement::TiXmlElement(local_1dc,(TiXmlElement *)"request",pcVar8);
    pTVar14 = (TiXmlElement *)0x0;
    TStack00000060 = (TiXmlElement)0xe;
    pCVar12 = pCVar11;
    pCVar13 = (CFastString *)pcVar10;
    pTVar15 = (TiXmlElement *)PTR_DAT_00bbf7d8;
    CFastString::SetString
              ((CFastString *)&stack0xfffffca8,(CFastStringInt *)&stack0xfffffc80,in_stack_fffffc64)
    ;
    pTVar16 = local_1d4;
    TiXmlText::TiXmlText(local_294,(TiXmlText *)pCVar12,in_stack_fffffc68);
    uStack00000068 = 0xf;
    TiXmlElement::TiXmlElement(local_180,(TiXmlElement *)&DAT_00b32cb4,in_stack_fffffc6c);
    uStack0000006c = 0x10;
    TiXmlNode::InsertEndChild(local_17c,local_28c,pTVar9);
    TiXmlNode::InsertEndChild(local_1c8,local_178,pTVar5);
    pTVar9 = (TiXmlNode *)0x0;
    uStack00000074 = 0x11;
    pTVar3 = (TiXmlElement *)PTR_DAT_00bbf7d8;
    CNetMasterServer::FindValidationData
              ((CNetMasterServer *)this,(CNetMasterServer *)&stack0xfffffc8c,
               (CFastString *)&stack0xfffffc9c,(CFastString *)pcVar10);
    TiXmlText::TiXmlText(local_1f0,(TiXmlText *)in_stack_fffffca4,pCVar11);
    uStack0000007c = 0x12;
    TiXmlElement::TiXmlElement(local_cc,(TiXmlElement *)"validation",(char *)pCVar12);
    uStack00000080 = 0x13;
    TiXmlNode::InsertEndChild(local_c8,local_1e8,(TiXmlNode *)pCVar13);
    if (pTVar15 != (TiXmlElement *)0x0) {
      TiXmlNode::InsertEndChild(local_1b4,local_c4,in_stack_fffffc88);
    }
    TiXmlNode::InsertEndChild(local_1b0,(TiXmlNode *)&local_320,in_stack_fffffc8c);
    local_320 = 0;
    pCVar1 = (CGameMasterServerRequest *)
             CNetMasterServer::SendMasterServerRequest
                       ((CNetMasterServer *)this,(CNetMasterServer *)&stack0xfffffca4,local_32c,
                        (SRequestElement *)0x0,in_stack_fffffc90);
    if (pCVar1 != (CGameMasterServerRequest *)0x0) {
      in_stack_fffffcb0 = operator_new(4);
      *(CGameCtnMasterServer **)in_stack_fffffcb0 = param_1;
      CFastBuffer<class_CDx9TextureKeeper*>::Add
                ((CNetMasterServerRequest *)(pCVar1 + 0x68),(TiXmlAttributeSet *)&stack0xfffffcb0,
                 in_stack_fffffc94);
    }
    uStack00000094 = 0x12;
    TiXmlElement::~TiXmlElement(local_b4,in_stack_fffffc98);
    uStack00000098 = 0x11;
    local_1d0[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)local_1d0,pTVar9);
    if (local_338 != PTR_DAT_00bbf7d8) {
      puVar4 = local_338 + -1;
      if ((local_338[-1] & 0x80) != 0) {
        puVar4 = local_338 + -4;
      }
      operator_delete__(puVar4);
      in_stack_fffffcc4 = (TiXmlElement *)0x0;
    }
    uStack0000009c = 0xf;
    TiXmlElement::~TiXmlElement(local_14c,pTVar3);
    uStack000000a0 = 0xe;
    local_258[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)local_258,in_stack_fffffca4);
    if (local_310 != PTR_DAT_00bbf7d8) {
      puVar4 = local_310 + -1;
      if ((local_310[-1] & 0x80) != 0) {
        puVar4 = local_310 + -4;
      }
      operator_delete__(puVar4);
      local_314 = 0;
      local_310 = PTR_DAT_00bbf7d8;
    }
    uStack000000a4 = 0xc;
    TiXmlElement::~TiXmlElement(local_194,pTVar14);
    if (in_stack_fffffcc4 != (TiXmlElement *)PTR_DAT_00bbf7d8) {
      pTVar3 = in_stack_fffffcc4 + -1;
      if (((byte)in_stack_fffffcc4[-1] & 0x80) != 0) {
        pTVar3 = in_stack_fffffcc4 + -4;
      }
      operator_delete__(pTVar3);
      in_stack_fffffcc0 = (TiXmlNode *)0x0;
      in_stack_fffffcc4 = (TiXmlElement *)PTR_DAT_00bbf7d8;
    }
    uStack000000a8 = 8;
    TiXmlElement::~TiXmlElement(local_f0,pTVar15);
    uStack000000ac = 7;
    local_2ac[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)local_2ac,in_stack_fffffcb0);
    if (local_31c != PTR_DAT_00bbf7d8) {
      puVar4 = local_31c + -1;
      if ((local_31c[-1] & 0x80) != 0) {
        puVar4 = local_31c + -4;
      }
      operator_delete__(puVar4);
      local_320 = 0;
      local_31c = PTR_DAT_00bbf7d8;
    }
    uStack000000b0 = 5;
    TiXmlElement::~TiXmlElement((TiXmlElement *)local_48,pTVar16);
    uStack000000b4 = 4;
    local_274[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)local_274,in_stack_fffffcb8);
    if (local_304[0] != PTR_DAT_00bbf7d8) {
      puVar4 = local_304[0] + -1;
      if ((local_304[0][-1] & 0x80) != 0) {
        puVar4 = local_304[0] + -4;
      }
      operator_delete__(puVar4);
      local_308 = 0;
      local_304[0] = PTR_DAT_00bbf7d8;
    }
    uStack000000b8 = 2;
    TiXmlElement::~TiXmlElement(&stack0x00000060,in_stack_fffffcbc);
    in_stack_000000bc = (void *)CONCAT31(in_stack_000000bc._1_3_,1);
    local_20c[0] = TiXmlText::vftable;
    TiXmlNode::~TiXmlNode((TiXmlNode *)local_20c,in_stack_fffffcc0);
    if (local_304[0] != PTR_DAT_00bbf7d8) {
      puVar4 = local_304[0] + -1;
      if ((local_304[0][-1] & 0x80) != 0) {
        puVar4 = local_304[0] + -4;
      }
      operator_delete__(puVar4);
      local_308 = 0;
      local_304[0] = PTR_DAT_00bbf7d8;
    }
    uStack000000c0 = 0xffffffff;
    TiXmlElement::~TiXmlElement(local_2e8,in_stack_fffffcc4);
  }
  ExceptionList = in_stack_000000bc;
  return pCVar1;
}
}

