// Class implementation: CSystemArchiveNod_SHeaderFolderDep

// =================================================
// Function: CSystemArchiveNod::SHeaderFolderDep::Archive
// =================================================
void __thiscall
CSystemArchiveNod::SHeaderFolderDep::Archive
          (void *this,CFastCrypt<unsigned_long> *param_1,CClassicArchive *param_2)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  CSystemFids *this_00;
  int iVar3;
  ulong unaff_EBX;
  int unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  undefined4 uStack0000000c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  TiXmlAttributeSet *pTVar6;
  CClassicArchive *pCVar7;
  ulong in_stack_ffffffc4;
  CSystemFids *pCVar8;
  CSystemEngine *in_stack_ffffffc8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_34;
  ulong local_30;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *local_2c;
  CSystemFids *pCStack_28;
  undefined1 *puStack_24;
  int local_20;
  CClassicArchive aCStack_1c [4];
  undefined4 local_18;
  undefined *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00a80c58;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if ((*(int *)(param_1 + 8) != 0) &&
     (uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (this,(CFastBuffer<class_CCrystalFace*> *)
                              (DAT_00cca150 ^ (uint)&stack0xffffffb8)), uVar1 == 0)) {
    ExceptionList = puStack_10;
    return;
  }
  local_30 = CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
  CClassicArchive::DoNatural
            ((CClassicArchive *)param_1,(CClassicArchive *)&local_30,(ulong *)0x1,0,unaff_ESI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4182fb;
  CFastBuffer<int>::SetSizeAtLeast(this,local_2c,unaff_EBX);
  pCVar7 = (CClassicArchive *)&DAT_0000000b;
  pTVar6 = (TiXmlAttributeSet *)0x41830b;
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d73300 + 0x20),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                      in_stack_ffffffc4);
  pCVar8 = (CSystemFids *)0x418312;
  this_00 = CSystemEngine::GetLocationData(*(CSystemEngine **)pSVar2,in_stack_ffffffc8);
  local_18 = 0;
  local_14 = PTR_DAT_00bbf7dc;
  uStack0000000c = 0;
  if (local_20 != 0) {
    do {
      if (*(int *)(param_1 + 8) == 0) {
        CClassicArchive::ReadString
                  ((CClassicArchive *)param_1,(CClassicArchive *)&local_2c,(CFastStringInt *)0x1,
                   (ulong)pCVar5);
        if (pCStack_28 != (CSystemFids *)0x0) {
          pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          pCStack_28 = CSystemFids::FindLocationDown
                                 (this_00,(CSystemFids *)&pCStack_28,(CFastStringInt *)0x1,0,
                                  (EFindWay)pTVar6);
          if (pCStack_28 != (CSystemFids *)0x0) {
            pTVar6 = (TiXmlAttributeSet *)&pCStack_28;
            pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x418379;
            CFastBuffer<class_CDx9TextureKeeper*>::Add(this,pTVar6,(TiXmlAttribute *)pCVar7);
          }
        }
      }
      else {
        puStack_24 = &DAT_00b2c878;
        local_20 = 0;
        CFastStringInt::SetString(&local_2c,(CFastStringInt *)&puStack_24,(SStringParam *)pCVar5);
        pCVar5 = pCVar4;
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this,pCVar4,(ulong)pTVar6);
        if (*(int *)pSVar2 == 0) {
LAB_004183d3:
          puStack_10 = &DAT_00b2c878;
          local_c = 0;
          CFastStringInt::SetString(&local_20,(CFastStringInt *)&puStack_10,(SStringParam *)pCVar8);
        }
        else {
          pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x4183b1;
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this,pCVar4,(ulong)pCVar7);
          if (this_00 == *(CSystemFids **)pSVar2) goto LAB_004183d3;
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this,pCVar4,(ulong)pCVar8);
          pCVar8 = this_00;
          iVar3 = (**(code **)(**(int **)pSVar2 + 0x9c))();
          if (iVar3 == 0) goto LAB_004183d3;
        }
        pCVar8 = (CSystemFids *)0x1;
        pCVar7 = aCStack_1c;
        pTVar6 = (TiXmlAttributeSet *)0x418400;
        CClassicArchive::WriteString
                  ((CClassicArchive *)param_1,pCVar7,(CFastStringInt *)0x1,(ulong)in_stack_ffffffc8)
        ;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCStack_34);
    if (pCStack_28 != (CSystemFids *)PTR_DAT_00bbf7dc) {
      if (((byte)pCStack_28[-1] & 0x80) == 0) {
        pCVar8 = pCStack_28 + -2;
      }
      else {
        pCVar8 = pCStack_28 + -4;
      }
      operator_delete__(pCVar8);
    }
  }
  ExceptionList = puStack_10;
  return;
}
}

// =================================================
// Function: CSystemArchiveNod::SHeaderFolderDep::FillHeaderUserData
// =================================================
int __thiscall
CSystemArchiveNod::SHeaderFolderDep::FillHeaderUserData
          (void *this,SHeader *param_1,ulong param_2,CGameSkin *param_3,int *param_4)
{
{
  ulong uVar1;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_retaddr;
  
  CFastBuffer<class_CGameFid*>::CopyFromFastBuffer
            (this,(CFastBuffer<struct_CDx9StateBlock::STexStageState> *)(param_2 + 0x40),unaff_ESI);
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_retaddr);
  return (uint)(uVar1 != 0);
}
}

