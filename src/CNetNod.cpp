// Class implementation: CNetNod

// =================================================
// Function: CNetNod::CNetNod
// =================================================
void __thiscall CNetNod::CNetNod(CNetNod *this,CNetNod *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0xffffffff;
  return;
}
}

// =================================================
// Function: CNetNod::DumpToBuffer
// =================================================
/* WARNING: Removing unreachable block (ram,0x00508ae9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CNetNod::DumpToBuffer
          (CNetNod *this,CNetNod *param_1,CClassicBufferMemory *param_2,SNetConfig *param_3,
          ulong *param_4)
{
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  CClassicBufferMemory *this_00;
  int iVar4;
  ulong unaff_EBP;
  int unaff_ESI;
  CClassicArchive *unaff_EDI;
  int *piVar5;
  CNetNod **ppCVar6;
  CPlugFileOggVorbis *pCVar7;
  SStreamContext **ppSVar8;
  ulong uVar9;
  CPlugFileOggVorbis *pCVar10;
  CClassicArchive *pCVar11;
  CClassicBufferMemory *pCVar12;
  CClassicBufferMemory *pCVar13;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  undefined4 local_4c;
  undefined **local_48;
  CClassicArchive aCStack_44 [4];
  CClassicArchive aCStack_40 [4];
  undefined4 local_3c;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a91e58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CClassicArchive::CClassicArchive
            ((CClassicArchive *)&local_4c,(CClassicArchive *)(DAT_00cca150 ^ (uint)&stack0xffffff94)
            );
  local_48 = CNetArchive::vftable;
  local_3c = 0;
  iVar4 = (**(code **)(*(int *)this + 0x7c))();
  iStack_54 = (**(code **)(*(int *)this + 0xc))();
  this_00 = param_2;
  iStack_50 = (**(code **)(*(int *)param_2 + 0x14))();
  if (*(int *)(param_3 + 0x3c) == 2) {
    piVar5 = *(int **)(param_3 + 0x40);
    iVar2 = *piVar5;
    while (iVar2 != iStack_54) {
      if (iVar2 == -1) goto LAB_00508d2f;
      piVar1 = piVar5 + 7;
      piVar5 = piVar5 + 7;
      iVar2 = *piVar1;
    }
    pCVar12 = (CClassicBufferMemory *)0x1;
    param_2 = (CClassicBufferMemory *)
              CONCAT31((int3)((uint)param_2 >> 8),
                       iVar4 != 0 | 0x80U | -(piVar5[2] != 0) & 2U | -(piVar5[3] != 0) & 4U |
                       -(piVar5[5] != 0) & 8U);
    pCVar10 = (CPlugFileOggVorbis *)&param_2;
    (**(code **)(*(int *)this_00 + 8))();
    param_1 = (CNetNod *)CONCAT31(param_1._1_3_,(char)piVar5[1]);
    ppSVar8 = (SStreamContext **)0x1;
    ppCVar6 = &param_1;
    (**(code **)(*(int *)this_00 + 8))();
    if ((piVar5[3] != 0) || (piVar5[5] != 0)) {
      _DAT_00000000 = _DAT_00000000 & 0xffff;
      (**(code **)(*(int *)this_00 + 8))(&stack0xffffff98,2);
      _DAT_00000000 = _DAT_00000000 + 1 & 0xffff;
    }
    if (piVar5[2] != 0) {
      (**(code **)(*(int *)this_00 + 0x14))();
      (**(code **)(*(int *)this_00 + 8))(&stack0x00000000,4);
    }
    if (iVar4 == 0) {
      (**(code **)(*(int *)this_00 + 0x14))();
      CNetArchive::StartStoring
                ((CNetArchive *)&iStack_58,(CNetArchive *)this_00,(CClassicBufferMemory *)0x0,
                 (int)ppCVar6);
      (**(code **)(*(int *)this + 0x34))(&iStack_54);
      CNetArchive::EndReading((CNetArchive *)&iStack_50,pCVar10,(SStreamContext **)pCVar12);
    }
    else {
      CNetArchive::StartStoring
                ((CNetArchive *)&iStack_58,(CNetArchive *)&DAT_00d66b2c,(CClassicBufferMemory *)0x1,
                 (int)ppCVar6);
      pCVar7 = (CPlugFileOggVorbis *)&iStack_54;
      (**(code **)(*(int *)this + 0x34))();
      CNetArchive::EndReading((CNetArchive *)&iStack_58,pCVar7,ppSVar8);
      (**(code **)(*(int *)this_00 + 0x14))();
      uVar3 = DAT_00d66b3c;
      pCVar13 = (CClassicBufferMemory *)((DAT_00d66b3c >> 6) + 0x13 + DAT_00d66b3c);
      uVar9 = 0x508b76;
      iVar4 = (**(code **)(*(int *)this_00 + 0x14))();
      CClassicBufferMemory::PreAlloc(this_00,pCVar13 + iVar4 + 4,uVar9);
      param_2 = pCVar13;
      lzo1x_1_compress();
      *(uint *)(*(int *)(this_00 + 0x14) + *(int *)(this_00 + 0xc)) = uVar3;
      CClassicBufferMemory::WriteVoid(this_00,param_2 + 4,(ulong)pCVar10);
      CClassicBufferMemory::Empty((CClassicBufferMemory *)&DAT_00d66b2c,pCVar12);
    }
    iVar4 = iStack_50;
    if (piVar5[2] != 0) {
      iVar2 = *(int *)(this_00 + 0xc);
      *(int *)(iVar2 + iStack_58) = 0;
      iStack_30 = *(int *)(this_00 + 0xc) + iStack_50;
      iStack_2c = (**(code **)(*(int *)this_00 + 0x14))();
      iStack_2c = iStack_2c - iVar4;
      uStack_14 = DAT_00b51514;
      uStack_18 = DAT_00b51510;
      uStack_10 = DAT_00b51518;
      local_c = DAT_00b5151c;
      CFastAlgo::ComputeHMAC_MD5_Digest((SHMAC_MD5_Data *)&iStack_30);
      local_4c = 0;
      *(int *)(iVar2 + iStack_58) = iStack_24 + iStack_28 + iStack_20 + iStack_1c;
    }
  }
  else if (*(int *)(param_3 + 0x3c) == 1) {
    param_4 = (ulong *)(iVar4 != 0 | 0x10000);
    if (iVar4 == 0) {
      CNetArchive::StartStoring
                ((CNetArchive *)&local_48,(CNetArchive *)this_00,(CClassicBufferMemory *)0x0,
                 (int)unaff_EDI);
      pCVar11 = (CClassicArchive *)&stack0x00000014;
      CClassicArchive::WriteNatural(aCStack_44,pCVar11,(ulong *)0x1,0,unaff_ESI);
    }
    else {
      pCVar11 = (CClassicArchive *)&DAT_00d66b2c;
      CNetArchive::StartStoring
                ((CNetArchive *)&local_48,(CNetArchive *)&DAT_00d66b2c,(CClassicBufferMemory *)0x1,
                 (int)unaff_EDI);
    }
    unaff_EDI = (CClassicArchive *)&local_4c;
    ppSVar8 = (SStreamContext **)0x508ceb;
    CClassicArchive::WriteMask(aCStack_40,unaff_EDI,(ulong *)0x1,unaff_EBP);
    (**(code **)(*(int *)this + 0x34))();
    CNetArchive::EndReading((CNetArchive *)&iStack_50,(CPlugFileOggVorbis *)pCVar11,ppSVar8);
    if (iVar4 != 0) {
      pCVar13 = (CClassicBufferMemory *)&DAT_00000004;
      pCVar12 = (CClassicBufferMemory *)&param_4;
      (**(code **)(*(int *)this_00 + 8))();
      CClassicBuffer::AddCompressedBlock
                ((CClassicBuffer *)this_00,(CClassicBuffer *)&DAT_00d66b2c,pCVar12);
      CClassicBufferMemory::Empty((CClassicBufferMemory *)&DAT_00d66b2c,pCVar13);
    }
  }
LAB_00508d2f:
  CClassicArchive::~CClassicArchive((CClassicArchive *)&local_48,unaff_EDI);
  ExceptionList = pvStack_4;
  return;
}
}

// =================================================
// Function: CNetNod::~CNetNod
// =================================================
void __thiscall CNetNod::~CNetNod(CNetNod *this,CNetNod *param_1)
{
{
  CMwNod *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00a91e28;
  local_c = ExceptionList;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 0;
  if (*(undefined4 **)(this + 0x14) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(this + 0x14))(1);
  }
  local_4 = 0xffffffff;
  CMwNod::~CMwNod((CMwNod *)this,pCVar1);
  ExceptionList = puStack_8;
  return;
}
}

