// Class implementation: CSystemDataFolders

// =================================================
// Function: CSystemDataFolders::FindDirIndexFromRelPath
// =================================================
ulong __thiscall
CSystemDataFolders::FindDirIndexFromRelPath
          (void *this,CSystemDataFolders *param_1,ulong param_2,CFastStringInt *param_3)
{
{
  int *piVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  int iVar4;
  undefined *puVar5;
  void *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  undefined *puVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  undefined *local_2c;
  undefined *local_28;
  undefined *puStack_24;
  undefined *local_20;
  undefined *puStack_1c;
  undefined *puStack_18;
  void *local_14;
  undefined1 *puStack_10;
  void *pvStack_c;
  void *local_8;
  
  pvStack_c = (void *)0xffffffff;
  puStack_10 = &LAB_00a841c0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  CFastStringInt::CFastStringInt
            (&local_2c,(CFastStringInt *)param_2,
             (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffb0));
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  local_8 = (void *)0x0;
  CSystemFileName::FixFileName((CFastStringInt *)&local_28,3);
  if (param_1 == (CSystemDataFolders *)0x0) {
    this_00 = (void *)((int)this + 8);
  }
  else {
    this_00 = (void *)((int)this + 0x10);
  }
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      puVar6 = PTR_DAT_00bbf7dc;
      local_2c = (undefined *)0x0;
      local_28 = PTR_DAT_00bbf7dc;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar7,(ulong)unaff_ESI);
      piVar1 = *(int **)pSVar3;
      if (((piVar1 != (int *)0x0) && (piVar1[6] == *(int *)(pCVar2 + 0x18))) &&
         (unaff_ESI = pCVar2, iVar4 = (**(code **)(*piVar1 + 0x9c))(), puVar6 = local_28, iVar4 != 0
         )) {
        puStack_1c = local_28;
        puStack_18 = local_2c;
        local_14 = (void *)0x0;
        if ((local_2c == puStack_24) &&
           (iVar4 = CFastStringInt::CompareNoCase
                              (&puStack_24,(CFastStringInt *)&puStack_1c,(SStringParam *)0x0,
                               (ulong)unaff_ESI), puVar6 = puStack_24, iVar4 == 0)) {
          if (puStack_24 != PTR_DAT_00bbf7dc) {
            if ((puStack_24[-1] & 0x80) == 0) {
              puStack_24 = puStack_24 + -2;
            }
            else {
              puStack_24 = puStack_24 + -4;
            }
            operator_delete__(puStack_24);
            local_28 = (undefined *)0x0;
            puStack_24 = PTR_DAT_00bbf7dc;
          }
          if (puStack_1c != PTR_DAT_00bbf7dc) {
            if ((puStack_1c[-1] & 0x80) != 0) {
              operator_delete__(puStack_1c + -4);
              ExceptionList = local_8;
              return (ulong)pCVar7;
            }
            operator_delete__(puStack_1c + -2);
          }
          ExceptionList = local_8;
          return (ulong)pCVar7;
        }
      }
      if (puVar6 != PTR_DAT_00bbf7dc) {
        puVar5 = puVar6 + -4;
        if ((puVar6[-1] & 0x80) == 0) {
          puVar5 = puVar6 + -2;
        }
        operator_delete__(puVar5);
        local_2c = (undefined *)0x0;
        local_28 = PTR_DAT_00bbf7dc;
      }
      pCVar7 = pCVar7 + 1;
    } while (pCVar7 < pCVar2);
  }
  if (local_20 != PTR_DAT_00bbf7dc) {
    if ((local_20[-1] & 0x80) == 0) {
      local_20 = local_20 + -2;
    }
    else {
      local_20 = local_20 + -4;
    }
    operator_delete__(local_20);
  }
  ExceptionList = pvStack_c;
  return 0xffffffff;
}
}

// =================================================
// Function: CSystemDataFolders::FindFidFromRelativeName
// =================================================
CSystemFidFile * __thiscall
CSystemDataFolders::FindFidFromRelativeName
          (void *this,CSystemDataFolders *param_1,ulong param_2,CFastStringInt *param_3,int param_4,
          int param_5,int param_6)
{
{
  CSystemFidsFolder *pCVar1;
  CSystemFidsFolder *this_00;
  int iVar2;
  undefined *puVar3;
  CSystemFid *pCVar4;
  SStringParam *unaff_EBX;
  void *unaff_EBP;
  ulong unaff_ESI;
  CSystemFidsFolder *this_01;
  ulong unaff_EDI;
  CFastStringInt *pCVar5;
  SStringParam *pSVar6;
  CFastStringInt *in_stack_ffffffb8;
  SStringParam *in_stack_ffffffbc;
  CSystemFidsFolder *local_3c;
  CSystemFidsFolder *local_38;
  CSystemFidsFolder *local_34;
  CSystemFids *local_30;
  undefined *local_2c;
  undefined *local_28;
  undefined1 *local_24;
  undefined *local_20;
  int local_1c;
  undefined *puStack_18;
  undefined *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined1 *puStack_8;
  
  puStack_c = (undefined *)0xffffffff;
  puStack_10 = &LAB_00a84190;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  pSVar6 = (SStringParam *)0x0;
  GetDir(this,(CSystemDataFolders *)(uint)(param_3 == (CFastStringInt *)0x0),(ulong)param_1,
         DAT_00cca150 ^ (uint)&stack0xffffffa8);
  this_00 = GetDir(this,(CSystemDataFolders *)(uint)(param_3 != (CFastStringInt *)0x0),
                   (ulong)param_1,unaff_EDI);
  local_3c = GetDir(this,(CSystemDataFolders *)0x1,(ulong)param_1,unaff_ESI);
  local_28 = (undefined *)0x0;
  local_24 = PTR_DAT_00bbf7dc;
  this_01 = local_38;
  if (param_4 != 0) {
    CFastStringInt::CFastStringInt(&local_20,(CFastStringInt *)param_2,unaff_EBX);
    CSystemFileName::FixFileName((CFastStringInt *)&local_1c,6);
    this_01 = local_34;
    local_2c = (undefined1 *)0x0;
    local_28 = PTR_DAT_00bbf7dc;
    if (local_34 == (CSystemFidsFolder *)0x0) {
LAB_00443657:
      if (this_00 != (CSystemFidsFolder *)0x0) {
        local_34 = (CSystemFidsFolder *)0x0;
        local_30 = (CSystemFids *)PTR_DAT_00bbf7dc;
        pCVar5 = (CFastStringInt *)0x0;
        (**(code **)(*(int *)this_00 + 0x98))();
        iVar2 = CSystemFileName::GetRelativeName
                          ((CFastStringInt *)&local_20,(CFastStringInt *)&local_38,
                           (CFastStringInt *)&local_30);
        if (((iVar2 != 0) &&
            (local_3c = (CSystemFidsFolder *)
                        CSystemFids::FindFid
                                  ((CSystemFids *)this_00,(CSystemFids *)&local_30,
                                   (CFastStringInt *)0x1,0,(EFindWay)pCVar5), local_38 == this_00))
           && (local_24 == (undefined1 *)0x0)) {
          pCVar5 = (CFastStringInt *)&local_14;
          local_14 = local_28;
          puStack_10 = local_2c;
          puStack_c = (undefined *)0x0;
          CFastStringInt::SetString(&local_24,pCVar5,pSVar6);
        }
        CGameCtnApp::SNationConfig::~SNationConfig(&local_38,(SNationConfig *)pCVar5);
      }
    }
    else {
      local_34 = (CSystemFidsFolder *)0x0;
      local_30 = (CSystemFids *)PTR_DAT_00bbf7dc;
      pCVar5 = (CFastStringInt *)0x0;
      (**(code **)(*(int *)this_01 + 0x98))();
      iVar2 = CSystemFileName::GetRelativeName
                        ((CFastStringInt *)&local_20,(CFastStringInt *)&local_38,
                         (CFastStringInt *)&local_30);
      if (((iVar2 != 0) &&
          (local_3c = (CSystemFidsFolder *)
                      CSystemFids::FindFid
                                ((CSystemFids *)this_01,(CSystemFids *)&local_30,
                                 (CFastStringInt *)0x1,0,(EFindWay)pCVar5), local_38 == this_01)) &&
         (local_24 == (undefined1 *)0x0)) {
        pCVar5 = (CFastStringInt *)&local_14;
        local_14 = local_28;
        puStack_10 = local_2c;
        puStack_c = (undefined *)0x0;
        CFastStringInt::SetString(&local_24,pCVar5,pSVar6);
      }
      CGameCtnApp::SNationConfig::~SNationConfig(&local_38,(SNationConfig *)pCVar5);
      if (local_3c == (CSystemFidsFolder *)0x0) goto LAB_00443657;
    }
    if (local_28 != PTR_DAT_00bbf7dc) {
      if ((local_28[-1] & 0x80) == 0) {
        puVar3 = local_28 + -2;
      }
      else {
        puVar3 = local_28 + -4;
      }
      operator_delete__(puVar3);
      local_2c = (undefined1 *)0x0;
      local_28 = PTR_DAT_00bbf7dc;
    }
    if (puStack_18 != PTR_DAT_00bbf7dc) {
      if ((puStack_18[-1] & 0x80) == 0) {
        puStack_18 = puStack_18 + -2;
      }
      else {
        puStack_18 = puStack_18 + -4;
      }
      operator_delete__(puStack_18);
    }
    pCVar1 = local_3c;
    if (local_3c != (CSystemFidsFolder *)0x0) goto LAB_00443873;
  }
  CFastStringInt::CFastStringInt(&local_2c,(CFastStringInt *)param_2,pSVar6);
  pCVar5 = (CFastStringInt *)0x2;
  CSystemFileName::FixFileName((CFastStringInt *)&local_28,2);
  iVar2 = CSystemFileName::IsDirectoryName((CFastStringInt *)&local_28);
  if (iVar2 == 0) {
    if (this_01 != (CSystemFidsFolder *)0x0) {
      pCVar5 = (CFastStringInt *)0x0;
      pCVar4 = CSystemFids::FindFid
                         ((CSystemFids *)this_01,(CSystemFids *)&local_28,(CFastStringInt *)0x1,0,
                          (EFindWay)in_stack_ffffffb8);
      local_34 = (CSystemFidsFolder *)pCVar4;
      if ((local_30 == (CSystemFids *)this_01) && (local_1c == 0)) {
        in_stack_ffffffb8 = (CFastStringInt *)&puStack_c;
        puStack_c = local_20;
        puStack_8 = local_24;
        unaff_EBP = (void *)0x0;
        pCVar5 = (CFastStringInt *)0x4437cf;
        CFastStringInt::SetString(&local_1c,in_stack_ffffffb8,in_stack_ffffffbc);
      }
      if (pCVar4 != (CSystemFid *)0x0) goto LAB_0044381c;
    }
    if (((this_00 != (CSystemFidsFolder *)0x0) &&
        (local_38 = (CSystemFidsFolder *)
                    CSystemFids::FindFid
                              ((CSystemFids *)this_00,(CSystemFids *)&local_2c,(CFastStringInt *)0x1
                               ,0,(EFindWay)pCVar5), local_34 == this_00)) &&
       (local_20 == (undefined *)0x0)) {
      pCVar5 = (CFastStringInt *)&puStack_10;
      puStack_c = local_28;
      puStack_10 = local_24;
      puStack_8 = (undefined1 *)0x0;
      CFastStringInt::SetString(&local_20,pCVar5,(SStringParam *)in_stack_ffffffb8);
    }
  }
LAB_0044381c:
  if (local_28 != PTR_DAT_00bbf7dc) {
    if ((local_28[-1] & 0x80) == 0) {
      puVar3 = local_28 + -2;
    }
    else {
      puVar3 = local_28 + -4;
    }
    operator_delete__(puVar3);
  }
  pCVar1 = local_3c;
  if (((local_3c == (CSystemFidsFolder *)0x0) && (param_5 != 0)) &&
     ((pCVar1 = (CSystemFidsFolder *)0x0, local_38 != (CSystemFidsFolder *)0x0 &&
      (local_24 != (undefined1 *)0x0)))) {
    local_38 = (CSystemFidsFolder *)
               CSystemFids::FindOrAddFid
                         ((CSystemFids *)local_38,(CSystemFids *)&local_24,(CFastStringInt *)0x0,
                          (ulong *)0x0,(int)pCVar5);
    pCVar1 = local_3c;
  }
LAB_00443873:
  local_3c = pCVar1;
  if (local_20 != PTR_DAT_00bbf7dc) {
    if ((local_20[-1] & 0x80) == 0) {
      local_20 = local_20 + -2;
    }
    else {
      local_20 = local_20 + -4;
    }
    operator_delete__(local_20);
  }
  ExceptionList = unaff_EBP;
  return (CSystemFidFile *)local_3c;
}
}

// =================================================
// Function: CSystemDataFolders::GetDir
// =================================================
CSystemFidsFolder * __thiscall
CSystemDataFolders::GetDir(void *this,CSystemDataFolders *param_1,ulong param_2,ulong param_3)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  if (param_2 == 0xfffffffe) {
    if (param_1 == (CSystemDataFolders *)0x0) {
      return *(CSystemFidsFolder **)this;
    }
    return *(CSystemFidsFolder **)((int)this + 4);
  }
  if (param_2 == 0xffffffff) {
    return (CSystemFidsFolder *)0x0;
  }
  if (param_1 == (CSystemDataFolders *)0x0) {
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)((int)this + 8),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,unaff_retaddr);
    return *(CSystemFidsFolder **)pSVar1;
  }
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)((int)this + 0x10),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,unaff_retaddr);
  return *(CSystemFidsFolder **)pSVar1;
}
}

// =================================================
// Function: CSystemDataFolders::GetRelativeNameFromFid
// =================================================
int __thiscall
CSystemDataFolders::GetRelativeNameFromFid
          (void *this,CSystemDataFolders *param_1,CSystemFid *param_2,CFastStringInt *param_3,
          ulong param_4)
{
{
  CSystemFid *this_00;
  CSystemFid *this_01;
  ulong uVar1;
  CSystemFidsFolder *pCVar2;
  int iVar3;
  SStringParam *unaff_EBX;
  ulong unaff_EBP;
  CSystemFids *unaff_ESI;
  SStringParam *unaff_EDI;
  SStringParam *unaff_retaddr;
  undefined4 uStack00000014;
  undefined1 *puVar4;
  CSystemFids *pCVar5;
  
  this_00 = param_2;
  puVar4 = &DAT_00b2c878;
  pCVar5 = (CSystemFids *)0x0;
  CFastStringInt::SetString(param_2,(CFastStringInt *)&stack0xfffffff8,unaff_EDI);
  uVar1 = param_4;
  this_01 = param_2;
  if (param_2 == (CSystemFid *)0x0) {
    return 0;
  }
  pCVar2 = GetDir(this,(CSystemDataFolders *)0x1,param_4,unaff_EBP);
  if ((*(int *)(*(int *)(this_01 + 0x14) + 0x18) == *(int *)(pCVar2 + 0x18)) &&
     (iVar3 = CSystemFidFile::GetFullNameUpTo
                        ((CSystemFidFile *)this_01,(CSystemFidsDrive *)this_00,
                         (CFastStringInt *)pCVar2,unaff_ESI), iVar3 != 0)) {
    return 1;
  }
  param_1 = (CSystemDataFolders *)&DAT_00b2c878;
  param_2 = (CSystemFid *)0x0;
  CFastStringInt::SetString(this_00,(CFastStringInt *)&param_1,unaff_EBX);
  pCVar2 = GetDir(this,(CSystemDataFolders *)0x0,uVar1,(ulong)puVar4);
  if ((*(int *)(*(int *)(this_01 + 0x14) + 0x18) == *(int *)(pCVar2 + 0x18)) &&
     (iVar3 = CSystemFidFile::GetFullNameUpTo
                        ((CSystemFidFile *)this_01,(CSystemFidsDrive *)this_00,
                         (CFastStringInt *)pCVar2,pCVar5), iVar3 != 0)) {
    return 1;
  }
  param_4 = (ulong)&DAT_00b2c878;
  uStack00000014 = 0;
  CFastStringInt::SetString(this_00,(CFastStringInt *)&param_4,unaff_retaddr);
  return 0;
}
}

// =================================================
// Function: CSystemDataFolders::GetUserDir
// =================================================
CSystemFidsFolder * __thiscall
CSystemDataFolders::GetUserDir(void *this,CSystemDataFolders *param_1,ulong param_2)
{
{
  CSystemFidsFolder *pCVar1;
  ulong unaff_retaddr;
  
  pCVar1 = GetDir(this,(CSystemDataFolders *)0x1,(ulong)param_1,unaff_retaddr);
  return pCVar1;
}
}

