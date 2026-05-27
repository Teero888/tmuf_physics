// Class implementation: CSystemFid

// =================================================
// Function: CSystemFid::ArchiveHeaderUserData
// =================================================
int __thiscall
CSystemFid::ArchiveHeaderUserData(CSystemFid *this,CSystemFid *param_1,CClassicArchive *param_2)
{
{
  void *this_00;
  CSystemFid *this_01;
  void *pvVar1;
  int iVar2;
  SHeaderUserData *unaff_EBX;
  void *pvVar3;
  ulong unaff_ESI;
  SHeaderUserData *unaff_EDI;
  void *in_stack_0000000c;
  
  this_01 = param_1;
  if (*(int *)(param_1 + 8) != 0) {
    if (*(void **)(this + 0x68) < (void *)0x2) {
      param_1 = (CSystemFid *)0x0;
    }
    else {
      param_2 = (CClassicArchive *)
                SHeaderUserData::ComputeByteSizeTotalInFile(*(void **)(this + 0x68),unaff_EDI);
      if (param_2 != (CClassicArchive *)0x0) {
        CClassicArchive::WriteNatural
                  ((CClassicArchive *)this_01,(CClassicArchive *)&param_2,(ulong *)0x1,0,unaff_ESI);
        CClassicArchive::WriteData
                  ((CClassicArchive *)this_01,*(CClassicArchive **)(this + 0x68),in_stack_0000000c,
                   (ulong)unaff_EBX);
        return 1;
      }
    }
    CClassicArchive::WriteNatural
              ((CClassicArchive *)this_01,(CClassicArchive *)&stack0x00000000,(ulong *)0x1,0,
               unaff_ESI);
    return 1;
  }
  CClassicArchive::ReadNatural
            ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(ulong *)0x1,0,(int)unaff_EDI);
  if (param_2 < (CClassicArchive *)0x200000) {
    if (*(uint *)(this + 0x68) < 2) {
      if (param_2 == (CClassicArchive *)0x0) {
        *(undefined4 *)(this + 0x68) = 1;
        pvVar3 = (void *)0x0;
      }
      else {
        iVar2 = HeaderUserDataCreateFromArchive(this,this_01,param_2,unaff_ESI);
        pvVar3 = in_stack_0000000c;
        if (iVar2 == 0) {
          in_stack_0000000c = (void *)0xffffffff;
          pvVar3 = (void *)0xffffffff;
        }
      }
    }
    else {
      CClassicArchive::SkipData((CClassicArchive *)this_01,param_2,unaff_ESI);
      pvVar3 = in_stack_0000000c;
    }
    this_00 = *(void **)(this + 0x68);
    if (this_00 < (void *)0x2) {
      pvVar1 = (void *)0x0;
    }
    else {
      pvVar1 = (void *)SHeaderUserData::ComputeByteSizeTotalInFile(this_00,unaff_EBX);
    }
    if (pvVar1 == pvVar3) {
      return 1;
    }
    if ((void *)0x1 < this_00) {
      operator_delete__(this_00);
    }
    *(undefined4 *)(this + 0x68) = 0;
  }
  return 0;
}
}

// =================================================
// Function: CSystemFid::BufferClose
// =================================================
void __thiscall
CSystemFid::BufferClose(CSystemFid *this,CSystemFid *param_1,CClassicBuffer *param_2)
{
{
  (**(code **)(**(int **)(this + 0x6c) + 4))(this,param_1);
  return;
}
}

// =================================================
// Function: CSystemFid::BuildHeaderUserData
// =================================================
void __thiscall
CSystemFid::BuildHeaderUserData(CSystemFid *this,CSystemFid *param_1,CSystemArchiveNod *param_2)
{
{
  int *piVar1;
  CSystemFid *pCVar2;
  int iVar3;
  ulong uVar4;
  SLoadedLight *pSVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  ulong *puVar7;
  SCasterCat *pSVar8;
  CVisionVisualKeeper *this_00;
  CPlugVisual *unaff_EBX;
  int unaff_EBP;
  CPlugVisual *pCVar9;
  CClassicBufferMemory *unaff_ESI;
  uint uVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  int unaff_retaddr;
  int in_stack_00000010;
  ulong in_stack_00000018;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_ffffff8c;
  CPlugVisual *in_stack_ffffff90;
  CClassicBufferMemory *pCVar12;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar13;
  CPlugVisual *pCVar14;
  CSystemFid *in_stack_ffffffac;
  SVertexDataLayer *in_stack_ffffffb0;
  CGameSkin *in_stack_ffffffb4;
  CSystemFid *pCVar15;
  CClassicArchive *in_stack_ffffffbc;
  CIteratorMaterial *pCVar16;
  CVisionVisualKeeper aCStack_34 [4];
  CClassicBufferMemory aCStack_30 [8];
  uint local_28;
  void *local_24;
  int local_20;
  CVisionVisualKeeper local_1c [8];
  undefined1 local_14 [4];
  undefined1 auStack_10 [4];
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a82048;
  local_c = ExceptionList;
  pCVar2 = (CSystemFid *)(DAT_00cca150 ^ (uint)&stack0xffffff9c);
  ExceptionList = &local_c;
  pCVar15 = this;
  if ((void *)0x1 < *(void **)(this + 0x68)) {
    in_stack_ffffff90 = (CPlugVisual *)0x426ecb;
    operator_delete__(*(void **)(this + 0x68));
  }
  *(undefined4 *)(this + 0x68) = 0;
  pCVar12 = (CClassicBufferMemory *)0x426eda;
  iVar3 = IsLoaded(this,pCVar2);
  if (iVar3 != 0) {
    piVar1 = *(int **)(this + 0x20);
    pCVar13 = (CFastBuffer<class_CPlugFileGPUV*> *)0x426eee;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&stack0xffffffc0,unaff_EDI);
    CClassicBufferMemory::CClassicBufferMemory((CClassicBufferMemory *)&local_24,unaff_ESI);
    this_00 = (CVisionVisualKeeper *)PTR_DAT_00ccbf98;
    iVar3 = *(int *)(PTR_DAT_00ccbf98 + 4);
    *(undefined4 *)(PTR_DAT_00ccbf98 + 0xc) = 0;
    *(undefined4 *)(this_00 + 8) = 1;
    if (iVar3 != 0) {
      CClassicArchive::DetachBuffer((CClassicArchive *)this_00,(CClassicArchive *)0x1,unaff_EBP);
      this_00 = (CVisionVisualKeeper *)PTR_DAT_00ccbf98;
    }
    CVisionVisualKeeper::SetVisual(this_00,local_1c,unaff_EBX);
    pCVar16 = (CIteratorMaterial *)0x0;
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                      ((void *)(in_stack_00000018 + 0x40),
                       (CFastBuffer<class_CCrystalFace*> *)in_stack_ffffffac);
    if (uVar4 != 0) {
      SVertexDataLayer::SVertexDataLayer(&local_20,in_stack_ffffffb0);
      in_stack_ffffffac = (CSystemFid *)0x1001000;
      iVar3 = CSystemArchiveNod::SHeaderFolderDep::FillHeaderUserData
                        (local_1c,(SHeader *)0x1001000,in_stack_00000018,in_stack_ffffffb4,
                         (int *)pCVar15);
      if (iVar3 != 0) {
        CSystemArchiveNod::SHeaderFolderDep::Archive
                  (local_14,(CFastCrypt<unsigned_long> *)PTR_DAT_00ccbf98,in_stack_ffffffbc);
      }
      uVar10 = in_stack_00000010 - unaff_retaddr;
      if (uVar10 != 0) {
        pSVar5 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                           (local_1c,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar16
                           );
        *(undefined4 *)pSVar5 = 0x1001000;
        *(uint *)(pSVar5 + 4) = uVar10 & 0x7fffffff;
        local_28 = uVar10;
      }
      CPlugTree::CIteratorMaterial::~CIteratorMaterial(auStack_10,pCVar16);
    }
    pCVar9 = (CPlugVisual *)0x0;
    iVar3 = (**(code **)(*piVar1 + 0x68))();
    pCVar14 = (CPlugVisual *)0x0;
    if (iVar3 != 0) {
      do {
        this = in_stack_ffffffac;
        CClassicArchive::DetachBuffer
                  ((CClassicArchive *)PTR_DAT_00ccbf98,(CClassicArchive *)0x1,(int)in_stack_ffffff8c
                  );
        CVisionVisualKeeper::SetVisual
                  ((CVisionVisualKeeper *)PTR_DAT_00ccbf98,aCStack_34,in_stack_ffffff90);
        in_stack_ffffff90 = pCVar9;
        uStack_4 = (**(code **)(*piVar1 + 100))();
        iVar3 = local_20;
        in_stack_ffffff8c = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)&stack0xffffffa8
        ;
        pCVar14 = (CPlugVisual *)0x1;
        (**(code **)(*piVar1 + 0x60))(PTR_DAT_00ccbf98,&uStack_4);
        uVar10 = (int)local_24 - iVar3;
        if (uVar10 != 0) {
          pSVar5 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                             (&stack0xffffffb0,in_stack_ffffff8c);
          *(uint *)(pSVar5 + 4) =
               *(uint *)(pSVar5 + 4) ^ (*(uint *)(pSVar5 + 4) ^ uVar10) & 0x7fffffff;
          *(undefined4 *)pSVar5 = uStack_4;
          *(uint *)(pSVar5 + 4) =
               (uint)(pCVar14 == (CPlugVisual *)0x0) << 0x1f | *(uint *)(pSVar5 + 4) & 0x7fffffff;
        }
        pCVar9 = pCVar9 + 1;
        in_stack_ffffffac = this;
      } while (pCVar9 < pCVar14);
    }
    CClassicArchive::DetachBuffer
              ((CClassicArchive *)PTR_DAT_00ccbf98,(CClassicArchive *)0x1,(int)in_stack_ffffff8c);
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (&stack0xffffffb4,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff90);
    if (pCVar6 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      *(undefined4 *)(this + 0x68) = 1;
    }
    else {
      puVar7 = operator_new__((uint)(pCVar14 + (int)pCVar6 * 8 + 4));
      pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      *(ulong **)(this + 0x68) = puVar7;
      *puVar7 = (ulong)pCVar6;
      if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar8 = CFastBuffer<struct_SFastCat>::operator[](&stack0xffffffb8,pCVar11,(ulong)pCVar12)
          ;
          iVar3 = *(int *)(this + 0x68);
          *(undefined4 *)(iVar3 + 4 + (int)pCVar11 * 8) = *(undefined4 *)pSVar8;
          *(undefined4 *)(iVar3 + 8 + (int)pCVar11 * 8) = *(undefined4 *)(pSVar8 + 4);
          pCVar11 = pCVar11 + 1;
        } while (pCVar11 < pCVar6);
      }
      _memcpy((void *)(*(int *)(this + 0x68) + 4 + (int)pCVar6 * 8),local_24,(uint)pCVar14);
    }
    local_8 = (undefined1 *)((uint)local_8 & 0xffffff00);
    CClassicBufferMemory::~CClassicBufferMemory(aCStack_30,pCVar12);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(&stack0xffffffbc,pCVar13);
  }
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CSystemFid::CSystemFid
// =================================================
void __thiscall CSystemFid::CSystemFid(CSystemFid *this,CSystemFid *param_1)
{
{
  CSystemFidParameters *unaff_EBX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CMwNod *unaff_EDI;
  undefined1 uStack00000008;
  void *in_stack_0000000c;
  undefined1 uStack00000010;
  CSystemFid *pCVar1;
  GmVec3 *pGVar2;
  
  pGVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe4),unaff_EDI);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x24,unaff_ESI);
  uStack00000008 = 1;
  CSystemFidParameters::CSystemFidParameters
            ((CSystemFidParameters *)(this + 0x34),unaff_EBX,(CSystemFidParameters *)pCVar1);
  uStack00000010 = 2;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined ***)(this + 0x6c) = &PTR_vftable_00ccbf90;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 100) = 0xffffffff;
  CSystemFidParameters::operator=
            ((CSystemFidParameters *)(this + 0x34),(SNormalDec3N *)&DAT_00d554d0,pGVar2);
  *(undefined4 *)(this + 0x1c) = 0x400;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  ExceptionList = in_stack_0000000c;
  return;
}
}

// =================================================
// Function: CSystemFid::ConcatLocation
// =================================================
void __thiscall CSystemFid::ConcatLocation(CSystemFid *this,CSystemFid *param_1,int param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  int unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  int unaff_retaddr;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     ((void *)(*(int *)(this + 0x14) + 0x28),unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 0x14) + 0x28),pCVar4,unaff_ESI);
      unaff_ESI = param_2;
      iVar3 = CSystemFids::TruncLocals
                        (*(CSystemFids **)pSVar2,(CSystemFids *)this,(CSystemFid *)param_2,unaff_EBP
                        );
      if (iVar3 != 0) {
        return;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  if (*(int *)(this + 0x14) == unaff_retaddr) {
    (**(code **)(**(int **)(this + 0x14) + 0x88))(this,param_2);
  }
  (**(code **)(*(int *)this + 0x84))();
  return;
}
}

// =================================================
// Function: CSystemFid::DetachNod
// =================================================
void __thiscall CSystemFid::DetachNod(CSystemFid *this,CSystemFid *param_1,CMwNod *param_2)
{
{
  if (param_1 != (CSystemFid *)0x0) {
    *(undefined4 *)(this + 0x20) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}
}

// =================================================
// Function: CSystemFid::GetClassId
// =================================================
ulong __thiscall CSystemFid::GetClassId(CSystemFid *this,CSystemFid *param_1)
{
{
  ulong uVar1;
  CSystemFid *unaff_ESI;
  
  if (*(int *)(this + 100) == -1) {
    if (*(CSystemFid **)(this + 0x30) != (CSystemFid *)0x0) {
      uVar1 = GetClassId(*(CSystemFid **)(this + 0x30),unaff_ESI);
      *(ulong *)(this + 100) = uVar1;
      return uVar1;
    }
    if (*(int **)(this + 0x20) != (int *)0x0) {
      uVar1 = (**(code **)(**(int **)(this + 0x20) + 0xc))();
      *(ulong *)(this + 100) = uVar1;
      return uVar1;
    }
    LoadHeaderUserData(this,(CSystemFid *)0x0,(CClassicBuffer *)unaff_ESI);
  }
  return *(ulong *)(this + 100);
}
}

// =================================================
// Function: CSystemFid::GetNod
// =================================================
CPlugMaterial * __thiscall
CSystemFid::GetNod(CSystemFid *this,CSysFidNodRef<class_CPlugMaterial> *param_1)
{
{
  CSystemFid *pCVar1;
  CSystemFidParameters *unaff_retaddr;
  
  pCVar1 = ParametrizedGetFid(this,(CSystemFid *)param_1,unaff_retaddr);
  if (pCVar1 != (CSystemFid *)0x0) {
    return *(CPlugMaterial **)(pCVar1 + 0x20);
  }
  return (CPlugMaterial *)0x0;
}
}

// =================================================
// Function: CSystemFid::HeaderUserDataCreateFromArchive
// =================================================
int __thiscall
CSystemFid::HeaderUserDataCreateFromArchive
          (CSystemFid *this,CSystemFid *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  uint uVar1;
  CFastArray<class_GxTexCoordSet> *pCVar2;
  uint *puVar3;
  ulong uVar4;
  int iVar5;
  void *pvVar6;
  ulong unaff_EBX;
  uint uVar7;
  GxTexCoordSet *unaff_EBP;
  CClassicArchive *pCVar8;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_EDI;
  uint unaff_retaddr;
  CClassicArchive *in_stack_00000010;
  uint in_stack_00000014;
  CSystemFid *local_4;
  
  local_4 = this;
  if ((void *)0x1 < *(void **)(this + 0x68)) {
    operator_delete__(*(void **)(this + 0x68));
    *(undefined4 *)(this + 0x68) = 0;
  }
  CClassicArchive::ReadData
            ((CClassicArchive *)param_1,(CClassicArchive *)&local_4,&DAT_00000004,unaff_EDI);
  uVar1 = unaff_retaddr * 8 + 4;
  if ((unaff_retaddr < 0x32) && (uVar1 <= param_3)) {
    puVar3 = operator_new__(uVar1);
    *(uint **)(this + 0x68) = puVar3;
    *puVar3 = unaff_retaddr;
    CClassicArchive::ReadData
              ((CClassicArchive *)param_1,(CClassicArchive *)(*(int *)(this + 0x68) + 4),
               (void *)(unaff_retaddr * 8),unaff_EBX);
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d543f4,unaff_ESI);
    if ((uVar4 != 0) && (uVar7 = 0, param_2 != (CClassicArchive *)0x0)) {
      do {
        pCVar2 = (CFastArray<class_GxTexCoordSet> *)(*(int *)(this + 0x68) + 4 + uVar7 * 8);
        iVar5 = CFastArray<class_CGameMenuFrame*>::Find(&DAT_00d543f4,pCVar2,unaff_EBP);
        if (iVar5 != -1) {
          pCVar2 = pCVar2 + 4;
          *(uint *)pCVar2 = *(uint *)pCVar2 | 0x80000000;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < param_3);
    }
    puVar3 = *(uint **)(this + 0x68);
    uVar7 = *puVar3;
    iVar5 = 0;
    if (uVar7 != 0) {
      do {
        puVar3 = puVar3 + 2;
        if (-1 < (int)*puVar3) {
          iVar5 = iVar5 + (*puVar3 & 0x7fffffff);
        }
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
      if (iVar5 != 0) {
        if (in_stack_00000014 < iVar5 + uVar1) {
          return 0;
        }
        pvVar6 = operator_new__(iVar5 + uVar1);
        _memcpy(pvVar6,*(void **)(this + 0x68),uVar1);
        operator_delete__(*(void **)(this + 0x68));
        uVar7 = 0;
        pCVar8 = (CClassicArchive *)(uVar1 + (int)pvVar6);
        *(void **)(this + 0x68) = pvVar6;
        if (param_2 != (CClassicArchive *)0x0) {
          do {
            iVar5 = *(int *)(this + 0x68);
            uVar1 = *(uint *)(iVar5 + 8 + uVar7 * 8);
            if ((int)uVar1 < 0) {
              CClassicArchive::SkipData
                        (in_stack_00000010,(CClassicArchive *)(uVar1 & 0x7fffffff),(ulong)unaff_EBP)
              ;
            }
            else {
              CClassicArchive::ReadData
                        (in_stack_00000010,pCVar8,(void *)(uVar1 & 0x7fffffff),(ulong)unaff_EBP);
              pCVar8 = pCVar8 + (*(uint *)(iVar5 + uVar7 * 8 + 8) & 0x7fffffff);
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < param_3);
        }
      }
    }
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CSystemFid::IsLoaded
// =================================================
int __thiscall CSystemFid::IsLoaded(CSystemFid *this,CSystemFid *param_1)
{
{
  CSystemFid *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CSystemFid *unaff_retaddr;
  
  if (*(int *)(this + 0x20) != 0) {
    return 1;
  }
  this_00 = this + 0x24;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar4,(ulong)unaff_ESI);
      if (*(int *)pSVar2 != 0) {
        unaff_ESI = pCVar4;
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_EBX)
        ;
        unaff_EBX = 0x426d8d;
        iVar3 = IsLoaded(*(CSystemFid **)pSVar2,unaff_retaddr);
        if (iVar3 != 0) {
          return 1;
        }
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return 0;
}
}

// =================================================
// Function: CSystemFid::LoadHeaderUserData
// =================================================
void __thiscall
CSystemFid::LoadHeaderUserData(CSystemFid *this,CSystemFid *param_1,CClassicBuffer *param_2)
{
{
  CSystemArchiveNod *pCVar1;
  CClassicBuffer *unaff_ESI;
  CSystemArchiveNod *in_stack_ffffff04;
  CSystemArchiveNod local_f8 [4];
  CSystemArchiveNod local_f4 [76];
  CSystemFid *local_a8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a81f5b;
  local_c = ExceptionList;
  pCVar1 = (CSystemArchiveNod *)(DAT_00cca150 ^ (uint)&stack0xffffff00);
  ExceptionList = &local_c;
  if ((void *)0x1 < *(void **)(this + 0x68)) {
    operator_delete__(*(void **)(this + 0x68));
  }
  *(undefined4 *)(this + 0x68) = 0;
  CSystemArchiveNod::CSystemArchiveNod((CSystemArchiveNod *)&stack0xffffff04,pCVar1);
  local_a8 = this;
  CSystemArchiveNod::DoFidLoadRefs(local_f8,(CSystemArchiveNod *)0x1,(EArchive)param_2,unaff_ESI);
  if (*(int *)(this + 0x68) == 0) {
    *(undefined4 *)(this + 0x68) = 1;
  }
  CSystemArchiveNod::~CSystemArchiveNod(local_f4,in_stack_ffffff04);
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: CSystemFid::LoadHeaderUserDataFromChunkId_Begin
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CClassicArchive * __thiscall
CSystemFid::LoadHeaderUserDataFromChunkId_Begin
          (CSystemFid *this,CSystemFid *param_1,ulong param_2,int param_3)
{
{
  uint *puVar1;
  uint uVar2;
  undefined *puVar3;
  ulong uVar4;
  CClassicBuffer *this_00;
  uint uVar5;
  CClassicArchive *pCVar6;
  CSystemFid *pCVar7;
  uint uVar8;
  CPlugVisual *unaff_ESI;
  CClassicBuffer *unaff_EDI;
  CClassicBuffer *pCStack_c;
  int local_8;
  
  while( true ) {
    if (*(int *)(this + 0x68) == 0) {
      LoadHeaderUserData(this,(CSystemFid *)0x0,unaff_EDI);
    }
    if (*(uint *)(this + 0x68) < 2) {
      return (CClassicArchive *)0x0;
    }
    uVar5 = **(uint **)(this + 0x68);
    local_8 = uVar5 * 8 + 4;
    pCStack_c = (CClassicBuffer *)(uVar5 * 8 + 0x15);
    uVar8 = 0;
    if (uVar5 == 0) {
      return (CClassicArchive *)0x0;
    }
    while( true ) {
      puVar1 = (uint *)(*(int *)(this + 0x68) + 4 + uVar8 * 8);
      if (param_2 == 0) {
        pCVar7 = (CSystemFid *)*puVar1;
      }
      else {
        uVar2 = *puVar1;
        uVar4 = CMwDeprecated::WrapClassId(uVar2 & 0xfffff000);
        pCVar7 = (CSystemFid *)*puVar1;
        if ((uVar2 & 0xfffff000) != uVar4) {
          pCVar7 = (CSystemFid *)((uint)pCVar7 & 0xfff | uVar4);
        }
      }
      if (param_1 == pCVar7) break;
      uVar2 = puVar1[1];
      pCStack_c = pCStack_c + (uVar2 & 0x7fffffff);
      if (-1 < (int)uVar2) {
        local_8 = local_8 + (uVar2 & 0x7fffffff);
      }
      uVar8 = uVar8 + 1;
      if (uVar5 <= uVar8) {
        return (CClassicArchive *)0x0;
      }
    }
    if (uVar5 <= uVar8) {
      return (CClassicArchive *)0x0;
    }
    if ((puVar1[1] & 0x80000000) == 0) break;
    this_00 = (CClassicBuffer *)(**(code **)**(undefined4 **)(this + 0x6c))(this,1,0);
    if (this_00 == (CClassicBuffer *)0x0) {
      return (CClassicArchive *)0x0;
    }
    uVar5 = (**(code **)(*(int *)this_00 + 0x18))();
    if ((*(uint *)(this + 0x80) == 0 && *(int *)(this + 0x84) == 0) ||
       ((uVar5 == *(uint *)(this + 0x80) && (*(int *)(this + 0x84) == 0)))) {
      CClassicBuffer::Skip(this_00,pCStack_c,(ulong)unaff_EDI);
      _DAT_00d543c4 = (puVar1[1] & 0x7fffffff) + local_8;
      if (uVar5 < _DAT_00d543c4) {
        (**(code **)(**(int **)(this + 0x6c) + 4))(this,this_00);
        _DAT_00d543c4 = 0;
        return (CClassicArchive *)0x0;
      }
      goto LAB_0042689a;
    }
    (**(code **)(**(int **)(this + 0x6c) + 4))(this);
    CSystemFidFile::ForceUpdateFidProps((CSystemFidFile *)this,(CSystemFidFile *)this_00);
    if (uVar5 != *(uint *)(this + 0x80)) {
      return (CClassicArchive *)0x0;
    }
    if (*(int *)(this + 0x84) != 0) {
      return (CClassicArchive *)0x0;
    }
  }
  CClassicBufferMemory::Attach
            ((CClassicBufferMemory *)PTR_DAT_00ccbf9c,
             (CClassicBufferMemory *)(*(int *)(this + 0x68) + local_8),
             (void *)(puVar1[1] & 0x7fffffff),(ulong)unaff_EDI);
  _DAT_00d543c4 = puVar1[1] & 0x7fffffff;
  this_00 = (CClassicBuffer *)PTR_DAT_00ccbf9c;
LAB_0042689a:
  if (*(int *)(PTR_DAT_00ccbf98 + 4) != 0) {
    CClassicArchive::DetachBuffer
              ((CClassicArchive *)PTR_DAT_00ccbf98,(CClassicArchive *)0x1,(int)unaff_ESI);
  }
  CVisionVisualKeeper::SetVisual
            ((CVisionVisualKeeper *)PTR_DAT_00ccbf98,(CVisionVisualKeeper *)this_00,unaff_ESI);
  puVar3 = PTR_DAT_00ccbf98;
  pCVar6 = (CClassicArchive *)PTR_DAT_00ccbf98;
  *(undefined4 *)(PTR_DAT_00ccbf98 + 8) = 0;
  *(undefined4 *)(puVar3 + 0xc) = 0;
  return pCVar6;
}
}

// =================================================
// Function: CSystemFid::LoadHeaderUserDataFromChunkId_End
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSystemFid::LoadHeaderUserDataFromChunkId_End
          (CSystemFid *this,CSystemFid *param_1,CClassicArchive **param_2)
{
{
  CClassicArchive *this_00;
  undefined *puVar1;
  int unaff_ESI;
  ulong unaff_EDI;
  
  this_00 = *(CClassicArchive **)param_1;
  if (this_00 == (CClassicArchive *)PTR_DAT_00ccbf98) {
    puVar1 = *(undefined **)(this_00 + 4);
    CClassicArchive::DetachBuffer(this_00,(CClassicArchive *)0x1,unaff_ESI);
    if (puVar1 == PTR_DAT_00ccbf9c) {
      CClassicBufferMemory::Attach
                ((CClassicBufferMemory *)PTR_DAT_00ccbf9c,(CClassicBufferMemory *)0x0,(void *)0x0,
                 unaff_EDI);
    }
    else {
      (**(code **)(**(int **)(this + 0x6c) + 4))(this,puVar1);
    }
    *(undefined4 *)param_1 = 0;
    _DAT_00d543c4 = 0;
  }
  return;
}
}

// =================================================
// Function: CSystemFid::MergeLocation
// =================================================
void __thiscall CSystemFid::MergeLocation(CSystemFid *this,CSystemFid *param_1,int param_2)
{
{
  int unaff_ESI;
  
  CSystemFids::TruncLocals(*(CSystemFids **)(this + 0x14),(CSystemFids *)this,param_1,unaff_ESI);
  (**(code **)(*(int *)this + 0x84))();
  return;
}
}

// =================================================
// Function: CSystemFid::ParametrizedAddFid
// =================================================
void __thiscall
CSystemFid::ParametrizedAddFid(CSystemFid *this,CSystemFid *param_1,CSystemFid *param_2)
{
{
  CSystemFid *pCVar1;
  CSystemFid *unaff_ESI;
  TiXmlAttribute *unaff_retaddr;
  int in_stack_0000000c;
  
  pCVar1 = ParametrizedGetLoadableFid(this,unaff_ESI);
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (pCVar1 + 0x24,(TiXmlAttributeSet *)&param_2,unaff_retaddr);
  *(CSystemFid **)(in_stack_0000000c + 0x30) = pCVar1;
  return;
}
}

// =================================================
// Function: CSystemFid::ParametrizedGetAnyLoadedNodLooselyFittingTheParams
// =================================================
CMwNod * __thiscall
CSystemFid::ParametrizedGetAnyLoadedNodLooselyFittingTheParams
          (CSystemFid *this,CSystemFid *param_1,CSystemFidParameters *param_2)
{
{
  CSystemFid *this_00;
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CSystemFidParameters *pCVar4;
  CSystemFid *unaff_ESI;
  CSystemFid *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CSystemFidParameters *in_stack_0000000c;
  CSystemFidParameters *in_stack_00000014;
  CSystemFid *pCVar6;
  
  pCVar6 = this;
  this_00 = ParametrizedGetLoadableFid(this,unaff_EDI);
  if (*(int *)(param_2 + 0x2c) == 0) {
    pCVar4 = (CSystemFidParameters *)0xffffffff;
  }
  else {
    pCVar4 = (CSystemFidParameters *)GetClassId(this_00,unaff_ESI);
  }
  if (*(int *)(this + 0x20) != 0) {
    iVar1 = CSystemFidParameters::Includes
                      (param_2,(CSystemFidParameters *)(this + 0x34),pCVar4,1,(int)unaff_EBP);
    if (iVar1 != 0) {
LAB_00426666:
      return *(CMwNod **)(this + 0x20);
    }
  }
  if (*(int *)(this_00 + 0x20) != 0) {
    iVar1 = CSystemFidParameters::Includes
                      (param_2,(CSystemFidParameters *)(this_00 + 0x34),pCVar4,1,(int)unaff_EBP);
    if (iVar1 != 0) {
      return *(CMwNod **)(this_00 + 0x20);
    }
  }
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00 + 0x24,unaff_EBP);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00 + 0x24,pCVar5,unaff_EBX);
      this = *(CSystemFid **)pSVar3;
      if (*(int *)(this + 0x20) != 0) {
        unaff_EBX = 1;
        iVar1 = CSystemFidParameters::Includes
                          (in_stack_00000014,(CSystemFidParameters *)(this + 0x34),in_stack_0000000c
                           ,1,(int)pCVar6);
        if (iVar1 != 0) goto LAB_00426666;
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar2);
  }
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CSystemFid::ParametrizedGetFid
// =================================================
CSystemFid * __thiscall
CSystemFid::ParametrizedGetFid(CSystemFid *this,CSystemFid *param_1,CSystemFidParameters *param_2)
{
{
  CSystemFid *pCVar1;
  CSystemFid *this_00;
  int iVar2;
  SCasterCat *pSVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  int unaff_EBP;
  CSystemFidParameters *pCVar4;
  CSystemFid *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CSystemFid *unaff_EDI;
  int unaff_retaddr;
  ulong uStack0000000c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000014;
  CSystemFidParameters *in_stack_00000018;
  
  this_00 = ParametrizedGetLoadableFid(this,unaff_EDI);
  if (*(int *)(param_2 + 0x2c) == 0) {
    pCVar4 = (CSystemFidParameters *)0xffffffff;
  }
  else {
    pCVar4 = (CSystemFidParameters *)GetClassId(this_00,unaff_ESI);
  }
  iVar2 = CSystemFidParameters::Includes
                    (param_2,(CSystemFidParameters *)(this_00 + 0x34),pCVar4,0,unaff_EBP);
  if (iVar2 != 0) {
    return this_00;
  }
  uStack0000000c = CFastBuffer<class_CCrystalFace*>::GetCount(this_00 + 0x24,unaff_EBX);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (uStack0000000c != 0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00 + 0x24,pCVar5,(ulong)this);
      pCVar1 = *(CSystemFid **)pSVar3;
      this = (CSystemFid *)0x0;
      iVar2 = CSystemFidParameters::Includes
                        (in_stack_00000018,(CSystemFidParameters *)(pCVar1 + 0x34),pCVar4,0,
                         unaff_retaddr);
      if (iVar2 != 0) {
        return pCVar1;
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < in_stack_00000014);
  }
  return (CSystemFid *)0x0;
}
}

// =================================================
// Function: CSystemFid::ParametrizedGetLoadableFid
// =================================================
CSystemFid * __thiscall CSystemFid::ParametrizedGetLoadableFid(CSystemFid *this,CSystemFid *param_1)
{
{
  CSystemFid *pCVar1;
  
  pCVar1 = *(CSystemFid **)(this + 0x30);
  if (*(CSystemFid **)(this + 0x30) == (CSystemFid *)0x0) {
    pCVar1 = this;
  }
  return pCVar1;
}
}

// =================================================
// Function: CSystemFid::ResetHeaderUserDatas
// =================================================
void __thiscall CSystemFid::ResetHeaderUserDatas(CSystemFid *this,CSystemFid *param_1)
{
{
  if ((void *)0x1 < *(void **)(this + 0x68)) {
    operator_delete__(*(void **)(this + 0x68));
  }
  *(undefined4 *)(this + 100) = 0xffffffff;
  *(undefined4 *)(this + 0x68) = 0;
  return;
}
}

// =================================================
// Function: CSystemFid::SetNoHeaderUserDatas
// =================================================
void __thiscall CSystemFid::SetNoHeaderUserDatas(CSystemFid *this,CSystemFid *param_1)
{
{
  if ((void *)0x1 < *(void **)(this + 0x68)) {
    operator_delete__(*(void **)(this + 0x68));
  }
  *(undefined4 *)(this + 0x68) = 1;
  return;
}
}

// =================================================
// Function: CSystemFid::SetNod
// =================================================
void __thiscall
CSystemFid::SetNod(CSystemFid *this,CSysFidNodRef<class_CScene3d> *param_1,CScene3d *param_2)
{
{
  *(CSysFidNodRef<class_CScene3d> **)(this + 0x20) = param_1;
  *(CSystemFid **)(param_1 + 8) = this;
  return;
}
}

// =================================================
// Function: CSystemFid::SetVirtualLoader
// =================================================
void __thiscall
CSystemFid::SetVirtualLoader(CSystemFid *this,CSystemFid *param_1,CLoader *param_2,ulong param_3)
{
{
  CSystemFid *pCVar1;
  int unaff_EDI;
  
  if (param_1 == (CSystemFid *)0x0) {
    param_1 = (CSystemFid *)&PTR_vftable_00ccbf90;
  }
  pCVar1 = *(CSystemFid **)(this + 0x6c);
  if (param_1 != pCVar1) {
    if (((pCVar1 != (CSystemFid *)0x0) && (pCVar1 != (CSystemFid *)&PTR_vftable_00ccbf90)) &&
       (pCVar1 != (CSystemFid *)&PTR_vftable_00ccbf94)) {
      (**(code **)(*(undefined **)pCVar1 + 8))(this,param_1);
    }
    *(CSystemFid **)(this + 0x6c) = param_1;
    *(CLoader **)(this + 0x70) = param_2;
    if (*(CSystemFids **)(this + 0x14) != (CSystemFids *)0x0) {
      CSystemFids::RefreshVirtualRecursive
                (*(CSystemFids **)(this + 0x14),
                 (CSystemFids *)(uint)(param_1 != (CSystemFid *)&PTR_vftable_00ccbf90),unaff_EDI);
    }
  }
  return;
}
}

// =================================================
// Function: CSystemFid::UpdateFidProps
// =================================================
void __thiscall
CSystemFid::UpdateFidProps(CSystemFid *this,CLoaderFidContainer *param_1,CSystemFid *param_2)
{
{
  if (this[0x1c] != (CSystemFid)0x0) {
    (**(code **)(**(int **)(this + 0x6c) + 0xc))(this);
    this[0x1c] = (CSystemFid)0x0;
  }
  return;
}
}

// =================================================
// Function: CSystemFid::VirtualParam_Get
// =================================================
ulong __thiscall
CSystemFid::VirtualParam_Get
          (CSystemFid *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0xb008001) {
    *(CMwStack **)param_2 = param_2 + 4;
    *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) >> 9 & 1;
  }
  else {
    if (iVar2 == 0xb008002) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x1c) >> 10 & 1;
      return 0;
    }
    if (iVar2 != -1) {
      *(int *)(param_1 + 0x18) = iVar1;
      uVar3 = CMwNod::VirtualParam_Get((CMwNod *)this,param_1,param_2,param_3);
      return uVar3;
    }
  }
  return 0;
}
}

// =================================================
// Function: CSystemFid::~CSystemFid
// =================================================
void __thiscall CSystemFid::~CSystemFid(CSystemFid *this,CSystemFid *param_1)
{
{
  uint uVar1;
  CPlugBitmap **unaff_ESI;
  void *in_stack_00000008;
  undefined4 uStack0000000c;
  CSystemFidParameters *in_stack_ffffffec;
  CSystemFid *pCVar2;
  CMwNod *pCVar3;
  
  pCVar3 = ExceptionList;
  uVar1 = DAT_00cca150 ^ (uint)&stack0xffffffe8;
  ExceptionList = &stack0xfffffff4;
  *(undefined ***)this = vftable;
  pCVar2 = this;
  SetVirtualLoader(this,(CSystemFid *)0x0,(CLoader *)0x0,uVar1);
  if (*(int *)(this + 0x30) != 0) {
    pCVar2 = this;
    CFastBuffer<class_CPlugBitmap*>::ReplaceByLast
              ((void *)(*(int *)(this + 0x30) + 0x24),
               (CFastBuffer<class_CPlugBitmap*> *)&stack0xfffffff0,unaff_ESI);
  }
  if (*(CSystemFid **)(this + 0x20) != (CSystemFid *)0x0) {
    DetachNod(this,*(CSystemFid **)(this + 0x20),(CMwNod *)in_stack_ffffffec);
  }
  if (*(CSystemFids **)(this + 0x14) != (CSystemFids *)0x0) {
    CSystemFids::RemoveLeaveSafe
              (*(CSystemFids **)(this + 0x14),(CSystemFids *)this,(CSystemFid *)in_stack_ffffffec);
  }
  if ((void *)0x1 < *(void **)(this + 0x68)) {
    operator_delete__(*(void **)(this + 0x68));
  }
  CSystemFids::SetTravelInfo((CMwNod *)this,0);
  CSystemFidParameters::~CSystemFidParameters
            ((CSystemFidParameters *)(this + 0x34),in_stack_ffffffec);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0x24,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar2);
  uStack0000000c = 0xffffffff;
  CMwNod::~CMwNod((CMwNod *)this,pCVar3);
  ExceptionList = in_stack_00000008;
  return;
}
}

