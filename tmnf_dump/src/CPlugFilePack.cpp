// Class implementation: CPlugFilePack

// =================================================
// Function: CPlugFilePack::GetPackListFid
// =================================================
CSystemFid * __cdecl CPlugFilePack::GetPackListFid(CSystemFids *param_1,int param_2)
{
{
  char *pcVar1;
  CSystemEngine *extraout_EAX;
  SCasterCat *pSVar2;
  CSystemFids *this;
  undefined *puVar3;
  CSystemFids *extraout_EAX_00;
  CSystemFid *pCVar4;
  CSystemFids *extraout_EAX_01;
  ulong unaff_ESI;
  undefined *unaff_retaddr;
  void *in_stack_0000000c;
  undefined4 uStack00000010;
  int in_stack_00000018;
  CSystemFids *pCVar5;
  CFastStringInt *pCVar6;
  int in_stack_ffffffc4;
  EFindWay in_stack_ffffffc8;
  char *in_stack_ffffffcc;
  EFindWay in_stack_ffffffd0;
  undefined *local_28;
  undefined1 *local_1c;
  char *local_18;
  undefined1 *local_14;
  char *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad65b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 == (CSystemFids *)0x0) {
    in_stack_ffffffcc = "Config\\";
    in_stack_ffffffd0 = 7;
    CFastStringInt::CFastStringInt
              (&stack0xffffffc4,(CFastStringInt *)&stack0xffffffcc,
               (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffc0));
    unaff_retaddr = (undefined *)0x0;
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(DAT_00d73300 + 0x20),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,unaff_ESI);
    pCVar6 = (CFastStringInt *)0x0;
    pCVar5 = (CSystemFids *)0x1;
    this = CSystemEngine::GetLocationUser(*(CSystemEngine **)pSVar2,extraout_EAX);
    param_1 = CSystemFids::FindLocationDown(this,pCVar5,pCVar6,in_stack_ffffffc4,in_stack_ffffffc8);
    in_stack_0000000c = (void *)0xffffffff;
    if (local_28 != PTR_DAT_00bbf7dc) {
      if ((local_28[-1] & 0x80) == 0) {
        puVar3 = local_28 + -2;
      }
      else {
        puVar3 = local_28 + -4;
      }
      operator_delete__(puVar3);
    }
  }
  PackList_StaticInit_CryptSfNormal();
  if (in_stack_00000018 == 0) {
    local_14 = &DAT_00d6eb90;
    pcVar1 = &DAT_00d6eb90;
    do {
      local_10 = pcVar1;
      pcVar1 = local_10 + 1;
    } while (*local_10 != '\0');
    local_10 = local_10 + -0xd6eb90;
    CFastStringInt::CFastStringInt
              (&local_4,(CFastStringInt *)&local_14,(SStringParam *)in_stack_ffffffcc);
    uStack00000010 = 2;
    pCVar4 = CSystemFids::FindOrAddFid
                       (param_1,extraout_EAX_01,(CFastStringInt *)0x0,(ulong *)0x0,in_stack_ffffffd0
                       );
  }
  else {
    local_1c = &DAT_00d6eb90;
    pcVar1 = &DAT_00d6eb90;
    do {
      local_18 = pcVar1;
      pcVar1 = local_18 + 1;
    } while (*local_18 != '\0');
    local_18 = local_18 + -0xd6eb90;
    CFastStringInt::CFastStringInt
              (&local_c,(CFastStringInt *)&local_1c,(SStringParam *)in_stack_ffffffcc);
    uStack00000010 = 1;
    pCVar4 = CSystemFids::FindFid(param_1,extraout_EAX_00,(CFastStringInt *)0x1,0,in_stack_ffffffd0)
    ;
    param_2 = (int)unaff_retaddr;
  }
  if ((undefined *)param_2 != PTR_DAT_00bbf7dc) {
    if ((*(byte *)(param_2 + -1) & 0x80) == 0) {
      puVar3 = (undefined *)(param_2 + -2);
    }
    else {
      puVar3 = (undefined *)(param_2 + -4);
    }
    operator_delete__(puVar3);
  }
  ExceptionList = in_stack_0000000c;
  return pCVar4;
}
}

// =================================================
// Function: CPlugFilePack::InstallPacks
// =================================================
void __cdecl
CPlugFilePack::InstallPacks
          (char *param_1,int param_2,CClassicBuffer *param_3,CSystemFids *param_4,
          CSystemFids *param_5,CSystemFids *param_6,int param_7)
{
{
  CClassicBufferMemory *pCVar1;
  int iVar2;
  int extraout_EAX;
  CSystemFids *pCVar3;
  SParam_Set *pSVar4;
  int extraout_EAX_00;
  SPackListElem *pSVar5;
  byte unaff_BP;
  uint uVar6;
  SPackListElem *pSVar7;
  SParam *unaff_EDI;
  uint uVar8;
  CClassicArchive *in_stack_ffffff60;
  CClassicArchive *in_stack_ffffff64;
  CPlugVisual *in_stack_ffffff68;
  int in_stack_ffffff6c;
  CClassicArchive *pCVar9;
  CClassicArchive *in_stack_ffffff70;
  CSystemFids *in_stack_ffffff74;
  CSystemFids *in_stack_ffffff78;
  CSystemFid *in_stack_ffffff7c;
  CClassicArchive aCStack_68 [4];
  CClassicArchive aCStack_64 [4];
  uint local_60;
  ulong uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  CClassicBufferMemory *pCStack_50;
  char *pcStack_4c;
  CClassicArchive *pCStack_48;
  CClassicArchive aCStack_44 [24];
  CClassicBufferMemory local_2c [4];
  CClassicBuffer local_28 [8];
  undefined1 uStack_20;
  void *local_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ad65f0;
  local_c = ExceptionList;
  pCVar1 = (CClassicBufferMemory *)(DAT_00cca150 ^ (uint)&stack0xffffff88);
  ExceptionList = &local_c;
  PackList_StaticInit_CryptSfNormal();
  uVar6 = 0;
  local_60 = 0;
  do {
    CClassicBufferMemory::CClassicBufferMemory(local_2c,pCVar1);
    if (uVar6 == 0) {
      if ((param_4 != (CSystemFids *)0x0) &&
         (iVar2 = (**(code **)(*(int *)param_4 + 0x18))(), iVar2 != 0)) {
        iVar2 = 0x864db4;
        pCVar3 = param_4;
        CClassicBuffer::CopyFrom(local_28,(SParam_Set *)param_4,unaff_EDI);
        pSVar4 = (SParam_Set *)unaff_EDI;
        if (extraout_EAX != 0) {
LAB_00864e15:
          CClassicBufferMemory::Reset
                    ((CClassicBufferMemory *)&pCStack_50,(GmFrustumIso4 *)in_stack_ffffff60);
          CClassicArchive::CClassicArchive(aCStack_64,in_stack_ffffff64);
          uStack_20 = 1;
          uStack_58 = 0;
          uStack_54 = 0;
          pCStack_50 = (CClassicBufferMemory *)0x1;
          CVisionVisualKeeper::SetVisual
                    ((CVisionVisualKeeper *)&local_60,(CVisionVisualKeeper *)&pCStack_48,
                     in_stack_ffffff68);
          in_stack_ffffff68 = (CPlugVisual *)0x0;
          in_stack_ffffff64 = (CClassicArchive *)0x1;
          in_stack_ffffff60 = (CClassicArchive *)&stack0xffffff84;
          CClassicArchive::ReadNat8
                    ((CClassicArchive *)&uStack_5c,in_stack_ffffff60,(uchar *)0x1,0,
                     in_stack_ffffff6c);
          if ((char)pSVar4 == '\x01') {
            in_stack_ffffff6c = 0;
            in_stack_ffffff68 = (CPlugVisual *)0x1;
            in_stack_ffffff64 = (CClassicArchive *)&stack0xffffff84;
            in_stack_ffffff60 = (CClassicArchive *)0x864e71;
            CClassicArchive::ReadNat8
                      ((CClassicArchive *)&uStack_58,in_stack_ffffff64,(uchar *)0x1,0,
                       (int)in_stack_ffffff70);
            if ((char)pSVar4 != '\0') {
              CClassicArchive::ReadNatural
                        ((CClassicArchive *)&uStack_54,aCStack_68,(ulong *)0x1,0,
                         (int)in_stack_ffffff74);
              in_stack_ffffff70 = (CClassicArchive *)0x1;
              pCVar9 = aCStack_68;
              CClassicArchive::ReadNatural
                        ((CClassicArchive *)&pCStack_50,pCVar9,(ulong *)0x1,0,(int)in_stack_ffffff78
                        );
              in_stack_ffffff78 = (CSystemFids *)((uint)unaff_BP * 0x42);
              in_stack_ffffff74 = (CSystemFids *)0x864eb7;
              pSVar5 = operator_new__((uint)in_stack_ffffff78);
              uVar8 = 0;
              if (unaff_BP != 0) {
                pSVar7 = pSVar5 + 1;
                do {
                  CClassicArchive::ReadNat8
                            ((CClassicArchive *)&uStack_5c,(CClassicArchive *)(pSVar7 + -1),
                             (uchar *)0x1,0,(int)pCVar9);
                  in_stack_ffffff6c = 0;
                  in_stack_ffffff68 = (CPlugVisual *)0x1;
                  in_stack_ffffff60 = (CClassicArchive *)0x864ee5;
                  in_stack_ffffff64 = (CClassicArchive *)pSVar7;
                  CClassicArchive::ReadNat8
                            ((CClassicArchive *)&uStack_58,(CClassicArchive *)pSVar7,(uchar *)0x1,0,
                             (int)in_stack_ffffff70);
                  uVar6 = local_60;
                  if (0x1f < (byte)*(CClassicArchive *)pSVar7) goto LAB_00864fd6;
                  *(undefined4 *)(pSVar7 + 1) = 0;
                  *(undefined4 *)(pSVar7 + 5) = 0;
                  *(undefined4 *)(pSVar7 + 9) = 0;
                  *(undefined4 *)(pSVar7 + 0xd) = 0;
                  *(undefined4 *)(pSVar7 + 0x11) = 0;
                  *(undefined4 *)(pSVar7 + 0x15) = 0;
                  *(undefined4 *)(pSVar7 + 0x19) = 0;
                  *(undefined4 *)(pSVar7 + 0x1d) = 0;
                  CClassicArchive::ReadData
                            ((CClassicArchive *)&uStack_54,(CClassicArchive *)(pSVar7 + 1),
                             (void *)(uint)(byte)*(CClassicArchive *)pSVar7,(ulong)in_stack_ffffff74
                            );
                  in_stack_ffffff74 = (CSystemFids *)&DAT_00000020;
                  in_stack_ffffff70 = (CClassicArchive *)(pSVar7 + 0x21);
                  pCVar9 = (CClassicArchive *)0x864f27;
                  CClassicArchive::ReadData
                            ((CClassicArchive *)&pCStack_50,in_stack_ffffff70,&DAT_00000020,
                             (ulong)in_stack_ffffff78);
                  uVar8 = uVar8 + 1;
                  pSVar7 = pSVar7 + 0x42;
                } while (uVar8 < unaff_BP);
              }
              CClassicArchive::ReadData
                        ((CClassicArchive *)&pcStack_4c,(CClassicArchive *)&uStack_5c,(void *)0x10,
                         (ulong)in_stack_ffffff7c);
              CClassicArchive::DetachBuffer
                        ((CClassicArchive *)&pCStack_48,(CClassicArchive *)0x1,iVar2);
              in_stack_ffffff7c = (CSystemFid *)&DAT_00d6ebe4;
              in_stack_ffffff64 = (CClassicArchive *)local_2c;
              in_stack_ffffff60 = pCStack_48;
              in_stack_ffffff68 = (CPlugVisual *)param_1;
              in_stack_ffffff6c = param_2;
              in_stack_ffffff70 = (CClassicArchive *)param_4;
              in_stack_ffffff74 = param_5;
              in_stack_ffffff78 = param_6;
              iVar2 = PackList_InstallFromFile_CryptSfNormal
                                (aCStack_64[0],aCStack_68[0],uStack_58,uStack_5c,pSVar5,
                                 SUB41(uStack_54,0),pCStack_50,pcStack_4c,(int)pCStack_48,
                                 (CSystemFids *)in_stack_ffffff64,(CSystemFids *)param_1,
                                 (CSystemFids *)param_2,(CFastBuffer<class_CPlugFilePack*> *)param_4
                                 ,(int)param_5);
              operator_delete(pSVar5);
              uVar6 = local_60;
              if (iVar2 != 0) {
                pvStack_4 = (void *)((uint)pvStack_4 & 0xffffff00);
                CClassicArchive::~CClassicArchive(aCStack_44,(CClassicArchive *)pCVar3);
                CClassicBufferMemory::~CClassicBufferMemory
                          ((CClassicBufferMemory *)local_28,(CClassicBufferMemory *)pSVar4);
                ExceptionList = pvStack_4;
                return;
              }
            }
          }
LAB_00864fd6:
          pvStack_4 = (void *)((uint)pvStack_4 & 0xffffff00);
          CClassicArchive::~CClassicArchive(aCStack_44,(CClassicArchive *)pCVar3);
          unaff_EDI = (SParam *)pSVar4;
        }
      }
    }
    else {
      in_stack_ffffff7c = (CSystemFid *)0x864dd3;
      pCVar3 = (CSystemFids *)GetPackListFid((CSystemFids *)(-(uint)(uVar6 != 1) & (uint)param_5),1)
      ;
      if (pCVar3 != (CSystemFids *)0x0) {
        in_stack_ffffff78 = (CSystemFids *)0x864ded;
        in_stack_ffffff7c = (CSystemFid *)pCVar3;
        pSVar4 = (SParam_Set *)(**(code **)**(undefined4 **)(pCVar3 + 0x6c))(pCVar3,1);
        if ((pSVar4 != (SParam_Set *)0x0) &&
           (CClassicBuffer::CopyFrom(local_28,pSVar4,unaff_EDI), extraout_EAX_00 != 0)) {
          iVar2 = 0x864e15;
          (**(code **)(**(int **)(pCVar3 + 0x6c) + 4))();
          goto LAB_00864e15;
        }
      }
    }
    pCVar1 = (CClassicBufferMemory *)0x864ff5;
    CClassicBufferMemory::~CClassicBufferMemory
              ((CClassicBufferMemory *)local_28,(CClassicBufferMemory *)unaff_EDI);
    uVar6 = uVar6 + 1;
    uStack_58 = uVar6;
    if (2 < uVar6) {
      ExceptionList = pvStack_4;
      return;
    }
  } while( true );
}
}

