// Class implementation: CSystemPackManager

// =================================================
// Function: CSystemPackManager::AddPackDesc
// =================================================
CSystemPackDesc * __thiscall
CSystemPackManager::AddPackDesc
          (CSystemPackManager *this,CSystemPackManager *param_1,CSystemFidFile *param_2,
          SNat128 *param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  CSystemPackDesc *pCVar4;
  undefined *puVar5;
  CFastStringInt *unaff_ESI;
  CSystemFid *unaff_EDI;
  ulong in_stack_ffffffdc;
  uchar *in_stack_ffffffe0;
  undefined *local_1c;
  undefined *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *local_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  local_8 = &LAB_00a83d78;
  local_c = ExceptionList;
  if (param_1 == (CSystemPackManager *)0x0) {
    return (CSystemPackDesc *)0x0;
  }
  ExceptionList = &local_c;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           GetIndexForFid(this,param_1,(CSystemFidFile *)(DAT_00cca150 ^ (uint)&stack0xffffffd4));
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x44,pCVar1,(ulong)unaff_EDI);
    ExceptionList = local_4;
    return *(CSystemPackDesc **)pSVar2;
  }
  if (param_3 == (SNat128 *)0x0) {
    iVar3 = CanComputeChecksum(this,param_1,unaff_EDI);
    if (iVar3 == 0) {
      CSystemPackDesc::SetChecksumNull((SNat128 *)&local_14);
    }
    else {
      CSystemPackDesc::ComputeChecksum
                ((ulong)param_1,(ulong)&local_14,(ulong)unaff_ESI,in_stack_ffffffdc,
                 in_stack_ffffffe0);
    }
  }
  else {
    local_14 = *(undefined4 *)(param_3 + 4);
    local_10 = *(undefined4 *)(param_3 + 8);
    local_c = *(void **)(param_3 + 0xc);
  }
  local_1c = (undefined *)0x0;
  local_18 = PTR_DAT_00bbf7dc;
  if (*(int *)(param_1 + 0x14) == *(int *)(this + 0x50)) {
    ExtractNameFromFileNameInCache(this,param_1 + 0x74,(CFastStringInt *)&local_1c,unaff_ESI);
  }
  else {
    GetPackNameFromFid(this,param_1,(CSystemFidFile *)&local_1c,unaff_ESI);
  }
  pCVar4 = AddPackDesc(this,(CSystemPackManager *)&local_10,(CSystemFidFile *)&local_18,
                       (SNat128 *)param_1);
  if (local_1c != PTR_DAT_00bbf7dc) {
    if ((local_1c[-1] & 0x80) == 0) {
      puVar5 = local_1c + -2;
    }
    else {
      puVar5 = local_1c + -4;
    }
    operator_delete__(puVar5);
  }
  ExceptionList = local_8;
  return pCVar4;
}
}

// =================================================
// Function: CSystemPackManager::ArchivePackDesc
// =================================================
void __thiscall
CSystemPackManager::ArchivePackDesc
          (CSystemPackManager *this,CSystemPackManager *param_1,CClassicArchive *param_2,
          CSystemPackDesc **param_3)
{
{
  int extraout_EAX;
  CSystemPackDesc *pCVar1;
  undefined *puVar2;
  CFastStringInt *pCVar3;
  ulong unaff_EBP;
  SStringParam *unaff_ESI;
  ulong unaff_EDI;
  undefined4 *in_stack_00000010;
  undefined4 *in_stack_0000001c;
  undefined3 in_stack_ffffffc4;
  SStringParamInt *in_stack_ffffffc8;
  SNationConfig *pSVar4;
  undefined4 local_30;
  undefined4 local_2c;
  undefined *local_28;
  undefined *local_24;
  undefined *local_20 [2];
  undefined *local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a83d48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar3 = (CFastStringInt *)CONCAT13(2,in_stack_ffffffc4);
  CClassicArchive::DoNat8
            ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xffffffc7,(uchar *)0x1,0,
             DAT_00cca150 ^ (uint)&stack0xffffffb8);
  if (*(int *)(param_1 + 8) == 0) {
    pSVar4 = (SNationConfig *)0x0;
    local_30 = PTR_DAT_00bbf7dc;
    CClassicArchive::ReadString
              ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xffffffcc,(CFastStringInt *)0x1,
               unaff_EDI);
    if (local_30 == (undefined *)0x0) {
      *in_stack_00000010 = 0;
    }
    else {
      CSystemFileName::Normalize(&local_30,(GmQuat *)&local_30);
      local_24 = (undefined *)0x0;
      local_20[0] = PTR_DAT_00bbf7d8;
      param_2 = (CClassicArchive *)CONCAT31(param_2._1_3_,3);
      if (local_30._3_1_ != '\0') {
        CClassicArchive::ReadString
                  ((CClassicArchive *)param_1,(CClassicArchive *)&local_24,(CFastStringInt *)0x1,
                   unaff_EBP);
      }
      if (local_2c._3_1_ < 2) {
        local_18 = &DAT_00b32ddc;
        local_14 = 6;
        CFastStringInt::CFastStringInt(local_10,(CFastStringInt *)&local_18,(SStringParam *)pCVar3);
        local_4 = *(undefined4 *)(extraout_EAX + 4);
        pCVar3 = (CFastStringInt *)&local_4;
        CFastStringInt::ConcatBefore(&local_24,pCVar3,in_stack_ffffffc8);
        CGameCtnApp::SNationConfig::~SNationConfig(&local_8,pSVar4);
      }
      pCVar1 = FindOrAddPackDescFromNameAndUrl
                         (this,(CSystemPackManager *)&local_28,(CFastStringInt *)local_20,
                          (CFastString *)0x0,(CSystemFidsFolder *)pCVar3);
      *in_stack_0000001c = pCVar1;
      if (local_18 != PTR_DAT_00bbf7d8) {
        puVar2 = local_18 + -1;
        if ((local_18[-1] & 0x80) != 0) {
          puVar2 = local_18 + -4;
        }
        operator_delete__(puVar2);
      }
    }
    if (local_20[0] == PTR_DAT_00bbf7dc) {
      ExceptionList = param_2;
      return;
    }
    if ((local_20[0][-1] & 0x80) == 0) {
      pCVar3 = (CFastStringInt *)(local_20[0] + -2);
    }
    else {
      pCVar3 = (CFastStringInt *)(local_20[0] + -4);
    }
  }
  else {
    if (*param_3 != (CSystemPackDesc *)0x0) {
      CClassicArchive::WriteString
                ((CClassicArchive *)param_1,(CClassicArchive *)(*param_3 + 0x1c),
                 (CFastStringInt *)0x1,unaff_EDI);
      pCVar1 = *param_3;
      if (*(int *)(pCVar1 + 0x1c) == 0) {
        ExceptionList = param_2;
        return;
      }
      local_30 = (undefined *)0x0;
      local_2c = PTR_DAT_00bbf7d8;
      local_28 = *(undefined **)(pCVar1 + 0x28);
      local_24 = *(undefined **)(pCVar1 + 0x24);
      CFastString::SetString((CFastString *)&local_30,(CFastStringInt *)&local_28,unaff_ESI);
      CClassicArchive::WriteString
                ((CClassicArchive *)param_1,(CClassicArchive *)&local_2c,(CFastStringInt *)0x1,
                 unaff_EBP);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_28,(SHeaderCommunity *)pCVar3);
      ExceptionList = param_2;
      return;
    }
    local_2c = (undefined *)0x0;
    local_28 = PTR_DAT_00bbf7d8;
    CClassicArchive::WriteString
              ((CClassicArchive *)param_1,(CClassicArchive *)&local_2c,(CFastStringInt *)0x1,
               unaff_EDI);
    if (local_24 == PTR_DAT_00bbf7d8) {
      ExceptionList = param_2;
      return;
    }
  }
  operator_delete__(pCVar3);
  ExceptionList = param_2;
  return;
}
}

// =================================================
// Function: CSystemPackManager::CanComputeChecksum
// =================================================
int __thiscall
CSystemPackManager::CanComputeChecksum
          (CSystemPackManager *this,CSystemPackManager *param_1,CSystemFid *param_2)
{
{
  int iVar1;
  
  iVar1 = CanComputeChecksum(this,param_1 + 0x74,param_2);
  return iVar1;
}
}

// =================================================
// Function: CSystemPackManager::ExtractNameFromFileNameInCache
// =================================================
void __thiscall
CSystemPackManager::ExtractNameFromFileNameInCache
          (CSystemPackManager *this,CSystemPackManager *param_1,CFastStringInt *param_2,
          CFastStringInt *param_3)
{
{
  undefined *puVar1;
  ulong unaff_ESI;
  void *unaff_retaddr;
  void *in_stack_00000010;
  CFastString *pCVar2;
  undefined *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined *local_4;
  
  local_4 = (undefined *)0xffffffff;
  puStack_8 = &LAB_00a83938;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(uint *)param_1 < 0x22) {
    local_10 = (undefined *)0x0;
    CFastStringInt::SetString
              (param_2,(CFastStringInt *)&stack0xffffffec,
               (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  }
  else {
    pCVar2 = (CFastString *)0x0;
    local_10 = PTR_DAT_00bbf7d8;
    local_4 = (undefined *)0x0;
    CFastStringInt::GetAscii
              (param_1,(CFastStringInt *)&stack0xffffffec,
               (CFastString *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
    CFastString::TruncBefore
              ((CFastString *)&local_10,(CFastString *)(*(int *)param_1 + -0x21),unaff_ESI);
    CFastStringInt::SetEscaped(in_stack_00000010,(CFastStringInt *)&local_c,pCVar2);
    if (local_4 != PTR_DAT_00bbf7d8) {
      puVar1 = local_4 + -1;
      if ((local_4[-1] & 0x80) != 0) {
        puVar1 = local_4 + -4;
      }
      operator_delete__(puVar1);
      ExceptionList = unaff_retaddr;
      return;
    }
  }
  ExceptionList = puStack_8;
  return;
}
}

// =================================================
// Function: CSystemPackManager::FindOrAddPackDescFromNameAndUrl
// =================================================
CSystemPackDesc * __thiscall
CSystemPackManager::FindOrAddPackDescFromNameAndUrl
          (CSystemPackManager *this,CSystemPackManager *param_1,CFastStringInt *param_2,
          CFastString *param_3,CSystemFidsFolder *param_4)
{
{
  CSystemPackDesc *this_00;
  SCasterCat *pSVar1;
  CFastString *unaff_EBP;
  EFindWay unaff_ESI;
  SNat128 *pSVar2;
  int unaff_EDI;
  
  this_00 = FindPackDescFromNameAndUrl(this,param_1,param_2,(CFastString *)0x1,unaff_EDI);
  if (this_00 == (CSystemPackDesc *)0x0) {
    pSVar2 = (SNat128 *)0x0;
    if (param_4 == (CSystemFidsFolder *)0x0) {
      if (**(short **)(param_1 + 4) == 0x3a) {
        pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(DAT_00d73300 + 0x20),
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                            unaff_ESI);
        pSVar2 = (SNat128 *)
                 CSystemEngine::FindOrAddFidAt
                           (*(CSystemEngine **)pSVar1,(CSystemEngine *)0x0,(CSystemFids *)param_1,
                            (CFastStringInt *)0x0,(int *)unaff_EBP);
      }
    }
    else {
      pSVar2 = (SNat128 *)
               CSystemFids::FindFid
                         ((CSystemFids *)param_4,(CSystemFids *)param_1,(CFastStringInt *)0x1,0,
                          unaff_ESI);
    }
    unaff_EBP = (CFastString *)0x0;
    this_00 = AddPackDesc(this,(CSystemPackManager *)&DAT_00d55a00,(CSystemFidFile *)param_1,pSVar2)
    ;
  }
  else {
    pSVar2 = *(SNat128 **)(this_00 + 0x4c);
  }
  if (pSVar2 == (SNat128 *)0x0) {
    if (param_4 == (CSystemFidsFolder *)0x0) {
      param_4 = *(CSystemFidsFolder **)(this + 0x50);
    }
    *(CSystemFidsFolder **)(this_00 + 0x4c) = param_4;
  }
  if (*(int *)param_3 != 0) {
    CSystemPackDesc::SetURL(this_00,(CSystemPackDesc *)param_3,unaff_EBP);
  }
  return this_00;
}
}

// =================================================
// Function: CSystemPackManager::FindOrAddPackDescFromUrl
// =================================================
CSystemPackDesc * __thiscall
CSystemPackManager::FindOrAddPackDescFromUrl
          (CSystemPackManager *this,CSystemPackManager *param_1,CFastString *param_2,
          CFastString *param_3,CSystemFidsFolder *param_4)
{
{
  CSystemPackManager *pCVar1;
  CSystemPackDesc *pCVar2;
  undefined *puVar3;
  CSystemFidsFolder *unaff_EBP;
  SStringParam *unaff_ESI;
  SStringParam *unaff_EDI;
  CFastString *in_stack_00000018;
  undefined4 local_34;
  undefined *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined *local_24;
  undefined4 local_20;
  undefined *local_1c [3];
  undefined4 local_10;
  undefined *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  pCVar1 = param_1;
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a83db8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_24 = *(undefined **)param_1;
  local_28 = *(undefined4 *)(param_1 + 4);
  CFastStringInt::CFastStringInt
            (&local_20,(CFastStringInt *)&local_28,
             (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffbc));
  local_34 = 0;
  local_30 = PTR_DAT_00bbf7dc;
  CSystemFileName::ExtractShortName((CFastStringInt *)local_1c,(CFastStringInt *)&local_34);
  local_24 = *(undefined **)(param_3 + 4);
  local_20 = *(undefined4 *)param_3;
  CFastStringInt::CFastStringInt(&local_2c,(CFastStringInt *)&local_24,unaff_EDI);
  local_10 = local_2c;
  param_1 = (CSystemPackManager *)CONCAT31(param_1._1_3_,2);
  local_c = local_30;
  local_8 = (undefined1 *)0x0;
  CFastStringInt::Concat(&local_28,(CFastStringInt *)&local_10,unaff_ESI);
  pCVar2 = FindOrAddPackDescFromNameAndUrl
                     (this,(CSystemPackManager *)&local_24,(CFastStringInt *)pCVar1,
                      in_stack_00000018,unaff_EBP);
  if (local_1c[0] != PTR_DAT_00bbf7dc) {
    puVar3 = local_1c[0] + -4;
    if ((local_1c[0][-1] & 0x80) == 0) {
      puVar3 = local_1c[0] + -2;
    }
    operator_delete__(puVar3);
    local_20 = 0;
    local_1c[0] = PTR_DAT_00bbf7dc;
  }
  if (local_24 != PTR_DAT_00bbf7dc) {
    puVar3 = local_24 + -4;
    if ((local_24[-1] & 0x80) == 0) {
      puVar3 = local_24 + -2;
    }
    operator_delete__(puVar3);
    local_28 = 0;
    local_24 = PTR_DAT_00bbf7dc;
  }
  if (local_c != PTR_DAT_00bbf7dc) {
    puVar3 = local_c + -4;
    if ((local_c[-1] & 0x80) == 0) {
      puVar3 = local_c + -2;
    }
    operator_delete__(puVar3);
  }
  ExceptionList = param_1;
  return pCVar2;
}
}

// =================================================
// Function: CSystemPackManager::FindPackDesc
// =================================================
CSystemPackDesc * __thiscall
CSystemPackManager::FindPackDesc
          (CSystemPackManager *this,CSystemPackManager *param_1,CFastStringInt *param_2,int param_3)
{
{
  CSystemPackDesc *pCVar1;
  int unaff_retaddr;
  
  pCVar1 = FindPackDescFromNameAndUrl
                     (this,param_1,(CFastStringInt *)&DAT_00d71c9c,(CFastString *)param_2,
                      unaff_retaddr);
  return pCVar1;
}
}

// =================================================
// Function: CSystemPackManager::FindPackDescFromNameAndUrl
// =================================================
CSystemPackDesc * __thiscall
CSystemPackManager::FindPackDescFromNameAndUrl
          (CSystemPackManager *this,CSystemPackManager *param_1,CFastStringInt *param_2,
          CFastString *param_3,int param_4)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  int extraout_EAX;
  ulong uVar4;
  undefined *puVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  undefined *puVar6;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CSystemPackDesc *pCVar7;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  void *in_stack_00000014;
  SParam_Fids *in_stack_ffffff7c;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffff80;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffff84;
  TiXmlAttributeSet *in_stack_ffffff88;
  TiXmlAttribute *pTVar10;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffff90;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_60;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_5c;
  undefined4 local_58;
  undefined *local_54;
  undefined *local_50;
  undefined4 local_4c;
  undefined *local_48;
  undefined *local_44;
  undefined *local_40;
  undefined *local_3c;
  int local_38;
  undefined *local_34;
  int local_30;
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> local_24 [4];
  undefined1 local_20 [4];
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> local_1c [8];
  void *local_14;
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0xffffffff;
  local_10 = &LAB_00a83ac8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (*(int *)param_1 == 0) {
    ExceptionList = param_3;
    return (CSystemPackDesc *)0x0;
  }
  CFastString::CFastString
            ((CFastString *)&local_60,(CFastString *)param_2,
             (char *)(DAT_00cca150 ^ (uint)&stack0xffffff70));
  local_8 = 0;
  NormalizeUrl((CFastString *)&local_5c);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(local_2c,unaff_EDI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(&local_34,unaff_ESI);
  pTVar10 = (TiXmlAttribute *)0x0;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x44,unaff_EBX);
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x44,pCVar8,(ulong)in_stack_ffffff7c);
      pCVar7 = *(CSystemPackDesc **)pSVar2;
      if ((param_3 != (CFastString *)0x0) || (*(int *)(pCVar7 + 0x48) != 0)) {
        local_3c = *(undefined **)(pCVar7 + 0x20);
        local_38 = *(int *)(pCVar7 + 0x1c);
        local_34 = (undefined *)0x0;
        if (local_38 == *(int *)param_1) {
          in_stack_ffffff7c = (SParam_Fids *)0x0;
          iVar3 = CFastStringInt::CompareNoCase
                            (param_1,(CFastStringInt *)&local_3c,(SStringParam *)0x0,
                             (ulong)in_stack_ffffff80);
          if (iVar3 == 0) {
            if ((((*(int *)(pCVar7 + 0x38) == DAT_00cce628) &&
                 (*(int *)(pCVar7 + 0x3c) == DAT_00cce62c)) &&
                (*(int *)(pCVar7 + 0x40) == DAT_00cce630)) &&
               (*(int *)(pCVar7 + 0x44) == DAT_00cce634)) goto LAB_0043dd93;
            if (local_60 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
LAB_0043daa3:
              pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&local_10;
            }
            else {
              local_40 = *(undefined **)(pCVar7 + 0x28);
              local_3c = *(undefined **)(pCVar7 + 0x24);
              if (local_3c == local_48) {
                in_stack_ffffff80 = (CFastBuffer<class_CCrystalFace*> *)0x0;
                in_stack_ffffff7c = (SParam_Fids *)&local_40;
                CFastString::Compare
                          ((CFastString *)&local_48,in_stack_ffffff7c,(SParam *)0x0,
                           (int *)in_stack_ffffff84,(int *)in_stack_ffffff88);
                if (extraout_EAX == 0) goto LAB_0043daa3;
              }
              if (*(int *)(pCVar7 + 0x24) != 0) goto LAB_0043dab1;
              pCVar9 = local_1c;
            }
            in_stack_ffffff88 = (TiXmlAttributeSet *)&local_5c;
            in_stack_ffffff84 = (CFastBuffer<class_CCrystalFace*> *)0x43dab1;
            CFastBuffer<class_CDx9TextureKeeper*>::Add(pCVar9,in_stack_ffffff88,pTVar10);
          }
        }
      }
LAB_0043dab1:
      pCVar8 = pCVar8 + 1;
    } while (pCVar8 < pCVar1);
    if (in_stack_ffffff90 != (CFastBuffer<class_CPlugFileGPUV*> *)0x0) {
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                (local_2c,(CFastBuffer<class_CPlugFileGPUV*> *)in_stack_ffffff7c);
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                (local_1c,(CFastBuffer<class_CPlugFileGPUV*> *)in_stack_ffffff80);
      if (local_44 != PTR_DAT_00bbf7d8) {
        puVar6 = local_44 + -1;
        if ((local_44[-1] & 0x80) != 0) {
          puVar6 = local_44 + -4;
        }
        operator_delete__(puVar6);
      }
      ExceptionList = param_1;
      return pCVar7;
    }
  }
  uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (local_20,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff7c);
  if (uVar4 == 0) {
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(local_28,in_stack_ffffff80);
    if (uVar4 == 0) {
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                (local_24,(CFastBuffer<class_CPlugFileGPUV*> *)in_stack_ffffff84);
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                (&local_14,(CFastBuffer<class_CPlugFileGPUV*> *)in_stack_ffffff88);
      if (local_3c == PTR_DAT_00bbf7d8) {
        ExceptionList = param_3;
        return (CSystemPackDesc *)0x0;
      }
      puVar6 = local_3c + -1;
      if ((local_3c[-1] & 0x80) != 0) {
        puVar6 = local_3c + -4;
      }
      operator_delete__(puVar6);
      ExceptionList = param_3;
      return (CSystemPackDesc *)0x0;
    }
    pCVar8 = local_24;
  }
  else {
    pCVar8 = local_1c;
  }
  local_60 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(pCVar8,in_stack_ffffff84);
  if (local_60 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (pCVar8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)in_stack_ffffff88);
    pCVar7 = *(CSystemPackDesc **)pSVar2;
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (local_1c,(CFastBuffer<class_CPlugFileGPUV*> *)pTVar10);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (&local_c,in_stack_ffffff90);
    if (local_34 == PTR_DAT_00bbf7d8) {
      ExceptionList = in_stack_00000014;
      return pCVar7;
    }
    puVar6 = local_34 + -1;
    if ((local_34[-1] & 0x80) != 0) {
      puVar6 = local_34 + -4;
    }
  }
  else {
    pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    local_5c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    local_30 = 0;
    local_4c = 0;
    local_48 = PTR_DAT_00bbf7dc;
    CSystemFileName::ExtractShortName((CFastStringInt *)param_1,(CFastStringInt *)&local_4c);
    if (local_60 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      puVar6 = (undefined *)0x0;
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar8,pCVar9,(ulong)in_stack_ffffff88);
        pCVar7 = *(CSystemPackDesc **)pSVar2;
        if (*(int *)(pCVar7 + 0x48) != 0) {
          if ((*(undefined **)(*(int *)(pCVar7 + 0x48) + 0x74) == local_48) &&
             (iVar3 = CFastStringInt::CompareNoCase
                                (&local_48,(CFastStringInt *)&stack0xfffffffc,(SStringParam *)0x0,
                                 (ulong)pTVar10), iVar3 == 0)) {
            if (local_40 != PTR_DAT_00bbf7dc) {
              operator_delete__((void *)0x43dd66);
              local_44 = (undefined *)0x0;
              local_40 = PTR_DAT_00bbf7dc;
            }
            goto LAB_0043dd93;
          }
          local_54 = (undefined *)0x0;
          local_50 = PTR_DAT_00bbf7dc;
          in_stack_ffffff88 = (TiXmlAttributeSet *)0x0;
          in_stack_00000014 = (void *)CONCAT31(in_stack_00000014._1_3_,4);
          CSystemFidFile::GetFullName
                    (*(CSystemFidFile **)(pCVar7 + 0x48),(CPlugFile *)&local_54,
                     (CFastStringInt *)0x0);
          CSystemManagerFile::GetTimeWrite((CFastStringInt *)&local_58,(uint64 *)&local_3c);
          iVar3 = CSystemManagerFile::CompareFileTime
                            (CONCAT44(local_30,puVar6),CONCAT44(local_38,local_3c));
          if (iVar3 < 0) {
            local_30 = local_38;
            puVar6 = local_3c;
            local_5c = pCVar9;
          }
          if (local_54 != PTR_DAT_00bbf7dc) {
            if ((local_54[-1] & 0x80) == 0) {
              puVar5 = local_54 + -2;
            }
            else {
              puVar5 = local_54 + -4;
            }
            operator_delete__(puVar5);
            local_58 = 0;
            local_54 = PTR_DAT_00bbf7dc;
          }
        }
        pCVar9 = pCVar9 + 1;
        pCVar8 = pCVar1;
      } while (pCVar9 < local_60);
    }
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (pCVar8,local_5c,(ulong)in_stack_ffffff88);
    pCVar7 = *(CSystemPackDesc **)pSVar2;
    if (local_44 != PTR_DAT_00bbf7dc) {
      if ((local_44[-1] & 0x80) == 0) {
        local_44 = local_44 + -2;
      }
      else {
        local_44 = local_44 + -4;
      }
      operator_delete__(local_44);
      local_48 = (undefined *)0x0;
      local_44 = PTR_DAT_00bbf7dc;
    }
LAB_0043dd93:
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (local_1c,(CFastBuffer<class_CPlugFileGPUV*> *)pTVar10);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (&local_c,in_stack_ffffff90);
    if (local_34 == PTR_DAT_00bbf7d8) {
      ExceptionList = in_stack_00000014;
      return pCVar7;
    }
    puVar6 = local_34 + -1;
    if ((local_34[-1] & 0x80) != 0) {
      puVar6 = local_34 + -4;
    }
  }
  operator_delete__(puVar6);
  ExceptionList = in_stack_00000014;
  return pCVar7;
}
}

// =================================================
// Function: CSystemPackManager::GetIndexForFid
// =================================================
ulong __thiscall
CSystemPackManager::GetIndexForFid
          (CSystemPackManager *this,CSystemPackManager *param_1,CSystemFidFile *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  if (param_1 == (CSystemPackManager *)0x0) {
    return 0xffffffff;
  }
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x44,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x44,pCVar3,unaff_ESI);
      if (*(CSystemPackManager **)(*(int *)pSVar2 + 0x48) == param_1) {
        return (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CSystemPackManager::GetPackElem
// =================================================
CSystemFidFile * __thiscall
CSystemPackManager::GetPackElem
          (CSystemPackManager *this,CSystemPackManager *param_1,CSystemPackDesc *param_2,
          CFastString *param_3,ulong param_4,CSystemFid *param_5,CMwNod *param_6)
{
{
  CSystemPackManager *pCVar1;
  CSystemPackManager *pCVar2;
  CFastString *pCVar3;
  CMwNod *pCVar4;
  CSystemFidFile *pCVar5;
  SLoadedLight *pSVar6;
  SStringParam *unaff_EBX;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EBP;
  CSystemFidFile *pCVar7;
  int unaff_ESI;
  int unaff_EDI;
  int unaff_retaddr;
  int in_stack_0000001c;
  undefined4 in_stack_00000020;
  CMwNod *in_stack_00000024;
  CMwNod *in_stack_fffffff8;
  int local_4;
  
  pCVar3 = param_3;
  pCVar2 = param_1;
  if ((((param_1 == (CSystemPackManager *)0x0) || (*(int *)(param_1 + 0x38) != DAT_00cce628)) ||
      (*(int *)(param_1 + 0x3c) != DAT_00cce62c)) ||
     ((*(int *)(param_1 + 0x40) != DAT_00cce630 ||
      (pCVar1 = param_1 + 0x44, param_1 = (CSystemPackManager *)0x1, *(int *)pCVar1 != DAT_00cce634)
      ))) {
    param_1 = (CSystemPackManager *)0x0;
  }
  pCVar5 = SimpleGetPackElem(this,pCVar2,param_2,param_3,(ulong)&stack0xfffffff8,(int *)0x1,
                             unaff_EDI);
  if (((pCVar5 == (CSystemFidFile *)0x0) && (local_4 == 0)) &&
     ((*(code **)(this + 0x38) != (code *)0x0 &&
      (((param_2 == (CSystemPackDesc *)0x0 && (pCVar2 != (CSystemPackManager *)0x0)) &&
       (*(int *)(pCVar2 + 0x6c) != 0)))))) {
    (**(code **)(this + 0x38))(pCVar2,0);
  }
  if (((*(code **)(this + 0x3c) != (code *)0x0) && (*(int *)(this + 0x40) != 0)) &&
     ((pCVar2 != (CSystemPackManager *)0x0 && (param_2 != (CSystemPackDesc *)0x0)))) {
    pCVar5 = (CSystemFidFile *)(**(code **)(this + 0x3c))(pCVar2,param_6,pCVar5);
  }
  if (((*(int *)(this + 0x20) == 0) || (pCVar2 == (CSystemPackManager *)0x0)) ||
     ((*(int *)(pCVar2 + 0x60) == 0 || (param_2 != (CSystemPackDesc *)0x0)))) {
    if ((pCVar5 == (CSystemFidFile *)0x0) && (param_5 != (CSystemFid *)0x0)) {
      pCVar7 = SimpleGetPackElem(this,pCVar2,(CSystemPackDesc *)param_3,pCVar3,(ulong)&param_2,
                                 (int *)0x0,unaff_ESI);
      pCVar4 = (CMwNod *)pCVar7;
      if (pCVar7 != (CSystemFidFile *)0x0) goto LAB_00440b89;
    }
    else {
      pCVar7 = (CSystemFidFile *)0x0;
      if (pCVar5 != (CSystemFidFile *)0x0) {
        return pCVar5;
      }
    }
  }
  else {
    pCVar7 = (CSystemFidFile *)0x0;
  }
  pCVar4 = param_6;
LAB_00440b89:
  param_6 = pCVar4;
  if (((unaff_retaddr == 0) && (in_stack_0000001c != 0)) && (param_6 != (CMwNod *)0x0)) {
    pSVar6 = CFastBuffer<struct_CSystemPackManager::SQueueElem>::AddNewElem(this + 0x14,unaff_EBP);
    *(CSystemPackManager **)pSVar6 = pCVar2;
    param_1 = *(CSystemPackManager **)(param_5 + 4);
    param_2 = *(CSystemPackDesc **)param_5;
    CFastString::SetString((CFastString *)(pSVar6 + 4),(CFastStringInt *)&param_1,unaff_EBX);
    *(int *)(pSVar6 + 0xc) = in_stack_0000001c;
    *(undefined4 *)(pSVar6 + 0x10) = in_stack_00000020;
    *(CMwNod **)(pSVar6 + 0x14) = in_stack_00000024;
    CMwNod::MwAddDependant(in_stack_00000024,(CMwNod *)this,in_stack_fffffff8);
    *(uint *)(pSVar6 + 0x18) = (uint)(pCVar7 != (CSystemFidFile *)0x0);
  }
  return (CSystemFidFile *)param_6;
}
}

// =================================================
// Function: CSystemPackManager::GetPackNameFromFid
// =================================================
void __thiscall
CSystemPackManager::GetPackNameFromFid
          (CSystemPackManager *this,CSystemPackManager *param_1,CSystemFidFile *param_2,
          CFastStringInt *param_3)
{
{
  ulong in_stack_fffffff8;
  
  if (param_1 != (CSystemPackManager *)0x0) {
    CSystemDataFolders::GetRelativeNameFromFid
              (*(void **)(this + 0x24),(CSystemDataFolders *)param_1,(CSystemFid *)param_2,
               (CFastStringInt *)0xfffffffe,in_stack_fffffff8);
    return;
  }
  CFastStringInt::SetString
            (param_2,(CFastStringInt *)&stack0xfffffff8,(SStringParam *)&DAT_00b2c878);
  return;
}
}

// =================================================
// Function: CSystemPackManager::IsPackDescInCache
// =================================================
int __thiscall
CSystemPackManager::IsPackDescInCache
          (CSystemPackManager *this,CSystemPackManager *param_1,CSystemPackDesc *param_2)
{
{
  CSystemFids *pCVar1;
  int iVar2;
  
  if (param_1 != (CSystemPackManager *)0x0) {
    if (*(int *)(param_1 + 0x48) == 0) {
      pCVar1 = *(CSystemFids **)(param_1 + 0x4c);
    }
    else {
      pCVar1 = *(CSystemFids **)(*(int *)(param_1 + 0x48) + 0x14);
    }
    if (pCVar1 != (CSystemFids *)0x0) {
      iVar2 = CSystemFids::IsOneBaseOf(*(CSystemFids **)(this + 0x50),pCVar1,(CSystemFids *)param_2)
      ;
      return iVar2;
    }
  }
  return 0;
}
}

// =================================================
// Function: CSystemPackManager::NormalizeUrl
// =================================================
void __cdecl CSystemPackManager::NormalizeUrl(CFastString *param_1)
{
{
  undefined *puVar1;
  CFastString *this;
  char *unaff_ESI;
  char *unaff_EDI;
  undefined4 uStack00000008;
  ulong in_stack_fffffff0;
  ulong in_stack_fffffff4;
  undefined1 *local_8;
  undefined *local_4;
  
  this = param_1;
  puVar1 = PTR_DAT_00d34100;
  CFastString::TrimLeft(param_1,(CFastString *)PTR_DAT_00d34100,unaff_EDI);
  CFastString::TrimRight(this,(CFastString *)puVar1,unaff_ESI);
  local_8 = &DAT_00b2c878;
  local_4 = (undefined *)0x0;
  param_1 = (CFastString *)0x1;
  CFastString::ReplaceFirst
            (this,(CFastString *)&stack0x00000000,(SStringParam *)&local_8,(SStringParam *)0x0,
             0xffffffff,in_stack_fffffff0);
  param_1 = (CFastString *)&DAT_00b2c878;
  uStack00000008 = 0;
  local_4 = &DAT_00b32c2c;
  CFastString::ReplaceFirst
            (this,(CFastString *)&local_4,(SStringParam *)&param_1,(SStringParam *)0x0,0xffffffff,
             in_stack_fffffff4);
  return;
}
}

// =================================================
// Function: CSystemPackManager::Reset
// =================================================
void __thiscall CSystemPackManager::Reset(CSystemPackManager *this,GmFrustumIso4 *param_1)
{
{
  CSystemPackManager *this_00;
  code *pcVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CSystemPackManager *unaff_retaddr;
  GmFrustumIso4 *in_stack_00000008;
  ulong uVar5;
  
  this_00 = this + 0x44;
  uVar5 = 0x43c0b5;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pcVar1 = *(code **)(this + 0x2c);
      if (pcVar1 != (code *)0x0) {
        uVar5 = 0x43c0d3;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_ESI)
        ;
        unaff_ESI = *(ulong *)pSVar3;
        unaff_EDI = (CFastBuffer<class_CCrystalFace*> *)0x43c0d8;
        (*pcVar1)();
      }
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,uVar5);
      uVar5 = 0x43c0ea;
      CMwNod::MwRelease(*(CMwNod **)pSVar3,(CMwNod *)unaff_EDI);
      pCVar4 = pCVar4 + 1;
      this = unaff_retaddr;
    } while (pCVar4 < pCVar2);
  }
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_00,in_stack_00000008);
  return;
}
}

// =================================================
// Function: CSystemPackManager::SimpleGetPackElem
// =================================================
CSystemFidFile * __thiscall
CSystemPackManager::SimpleGetPackElem
          (CSystemPackManager *this,CSystemPackManager *param_1,CSystemPackDesc *param_2,
          CFastString *param_3,ulong param_4,int *param_5,int param_6)
{
{
  char cVar1;
  char cVar2;
  int extraout_EAX;
  int iVar3;
  SCasterCat *pSVar4;
  CSystemFidFile *pCVar5;
  char *pcVar6;
  SNationConfig *unaff_EBX;
  SNationConfig *unaff_EBP;
  SStringParam *unaff_ESI;
  int *unaff_EDI;
  bool bVar7;
  CSystemFid *in_stack_0000001c;
  CSystemFidFile *in_stack_00000020;
  uint *in_stack_00000024;
  CSystemPackDesc *in_stack_ffffffd8;
  SNationConfig *in_stack_ffffffdc;
  CSystemPackDesc local_1c [4];
  CSystemFids *local_18;
  char *local_14;
  char *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a83a08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  cVar1 = **(char **)(param_2 + 4);
  local_14 = ".";
  local_10 = (char *)0x1;
  if (*(int *)param_2 == 1) {
    CFastString::Compare
              ((CFastString *)param_2,(SParam_Fids *)&local_14,(SParam *)0x0,
               (int *)(DAT_00cca150 ^ (uint)&stack0xffffffc8),unaff_EDI);
    bVar7 = extraout_EAX == 0;
  }
  else {
    bVar7 = false;
  }
  if (cVar1 == '*') {
    local_14 = (char *)(*(int *)(param_2 + 4) + 1);
  }
  else {
    local_14 = *(char **)(param_2 + 4);
  }
  if (local_14 == (char *)0x0) {
    local_10 = (char *)0x0;
  }
  else {
    local_10 = local_14;
    do {
      cVar2 = *local_10;
      local_10 = local_10 + 1;
    } while (cVar2 != '\0');
    local_10 = local_10 + -(int)(local_14 + 1);
  }
  CFastStringInt::CFastStringInt(local_1c,(CFastStringInt *)&local_14,unaff_ESI);
  iVar3 = param_6;
  if (param_4 == 0) {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(DAT_00d73300 + 0x20),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                        (ulong)unaff_EBP);
    if (iVar3 == -1) {
      pCVar5 = (CSystemFidFile *)
               CSystemEngine::FindFid
                         (*(CSystemEngine **)pSVar4,(CSystemFids *)0x0,(CFastStringInt *)&local_14,0
                          ,(EFindWay)unaff_EBX);
    }
    else {
      pCVar5 = (CSystemFidFile *)
               CSystemEngine::FindFidFromBaseNameAndClassId
                         (*(CSystemEngine **)pSVar4,(CSystemFids *)0x0,(CFastStringInt *)&local_14,
                          iVar3);
    }
    *(uint *)in_stack_00000020 = (uint)(pCVar5 == (CSystemFidFile *)0x0);
    param_6 = (int)pCVar5;
  }
  else {
    if (((*(int *)(this + 0x6c) != 0) && (in_stack_00000020 != (CSystemFidFile *)0x0)) &&
       (*(int *)(param_4 + 100) == 0)) {
      *(undefined4 *)in_stack_0000001c = 0;
      CGameCtnApp::SNationConfig::~SNationConfig(&local_18,unaff_EBP);
      ExceptionList = param_1;
      return (CSystemFidFile *)0x0;
    }
    CSystemPackDesc::GetContents
              ((CSystemPackDesc *)param_4,local_1c,(CSystemFids **)&param_5,(CSystemFid **)unaff_EBP
              );
    if (local_18 == (CSystemFids *)0x0) {
      if (param_6 == 0) {
        *(uint *)in_stack_00000020 = (uint)(*(int *)(param_4 + 0x58) == 0);
        CGameCtnApp::SNationConfig::~SNationConfig(&local_14,unaff_EBX);
        ExceptionList = param_1;
        return (CSystemFidFile *)0x0;
      }
      if ((in_stack_0000001c != (CSystemFid *)0xffffffff) && ((cVar1 == '*' || (bVar7)))) {
        unaff_EBP = (SNationConfig *)CSystemFid::GetClassId((CSystemFid *)param_6,in_stack_0000001c)
        ;
        iVar3 = CMwNod::StaticMwIsKindOf((ulong)unaff_EBP,(ulong)unaff_EBX);
        if (iVar3 != 0) {
          *in_stack_00000024 = 0;
          CSystemPackDesc::TouchLastTimeOfUse((CSystemPackDesc *)param_4,in_stack_ffffffd8);
          CGameCtnApp::SNationConfig::~SNationConfig(&local_c,in_stack_ffffffdc);
          ExceptionList = param_1;
          return in_stack_00000020;
        }
      }
      *(undefined4 *)in_stack_0000001c = 1;
      CGameCtnApp::SNationConfig::~SNationConfig(&local_18,unaff_EBP);
      ExceptionList = param_1;
      return (CSystemFidFile *)0x0;
    }
    in_stack_0000001c =
         CSystemFids::FindFidFromBaseNameAndClassId
                   (local_18,(CSystemFids *)&local_14,(CFastStringInt *)in_stack_0000001c,
                    (ulong)unaff_EBX);
    *in_stack_00000024 = (uint)(in_stack_0000001c == (CSystemFid *)0x0);
    pCVar5 = (CSystemFidFile *)0x0;
    if (in_stack_0000001c != (CSystemFid *)0x0) {
      CSystemPackDesc::TouchLastTimeOfUse((CSystemPackDesc *)param_4,in_stack_ffffffd8);
      pCVar5 = in_stack_00000020;
    }
  }
  if (local_10 != PTR_DAT_00bbf7dc) {
    if ((local_10[-1] & 0x80U) == 0) {
      pcVar6 = local_10 + -2;
    }
    else {
      pcVar6 = local_10 + -4;
    }
    operator_delete__(pcVar6);
  }
  ExceptionList = param_1;
  return pCVar5;
}
}

