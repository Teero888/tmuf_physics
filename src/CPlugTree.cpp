// Class implementation: CPlugTree

// =================================================
// Function: CPlugTree::AddChild
// =================================================
CControlBase * __thiscall
CPlugTree::AddChild(CPlugTree *this,SGridAddChildContext *param_1,char *param_2,CMwNod *param_3,
                   char *param_4,ulong param_5)
{
{
  char *pcVar1;
  CControlBase *extraout_EAX;
  int unaff_ESI;
  TiXmlAttribute *unaff_EDI;
  
  CFastBuffer<class_CDx9TextureKeeper*>::Add(this + 0x28,(TiXmlAttributeSet *)&param_1,unaff_EDI);
  pcVar1 = param_2;
  if (*(int *)(this + 0x14) != 0) {
    (**(code **)(*(int *)param_2 + 0x78))(0);
  }
  ConnectAsChild(this,(CPlugTree *)pcVar1,(CPlugTree *)0x1,unaff_ESI);
  return extraout_EAX;
}
}

// =================================================
// Function: CPlugTree::ApplyFidParameters
// =================================================
void __thiscall
CPlugTree::ApplyFidParameters
          (CPlugTree *this,CPlugFontBitmap *param_1,CSystemFidParameters *param_2,
          CSystemFidParameters *param_3,CFastBuffer<struct_CMwNod::SManuallyLoadedFid> *param_4)
{
{
  float unaff_EDI;
  
  CVisionViewportNull::SetFullScreenGammaRamp
            ((CVisionViewportNull *)this,(CVisionViewportNull *)param_1,(float)param_2,
             (float)param_3,unaff_EDI);
  if (*(int *)(this + 0x94) != 0) {
    PlugTree_SetRenderBeforeForSpecialFidParametrization
              (this,(CSystemFidParameters *)param_1,param_2);
  }
  return;
}
}

// =================================================
// Function: CPlugTree::CPlugTree
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CPlugTree::CPlugTree(CPlugTree *this,CPlugTree *param_1)
{
{
  undefined4 uVar1;
  CMwId *unaff_ESI;
  CMwId *unaff_EDI;
  void *in_stack_00000008;
  undefined1 uStack0000000c;
  CPlugTree *pCVar2;
  GmMat43 *pGVar3;
  
  pGVar3 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar2 = this;
  CPlug::CPlug((CPlug *)this,(CPlug *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x18,unaff_EDI);
  CMwId::CMwId(this + 0x20,unaff_ESI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x28,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar2);
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa8) = 0;
  uStack0000000c = 9;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  GmIso4::SetIdentity(this + 0x5c,pGVar3);
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)(this + 0x40) = _DAT_00b2c060;
  *(undefined4 *)(this + 0x44) = uVar1;
  *(undefined4 *)(this + 0x48) = uVar1;
  *(undefined4 *)(this + 0x4c) = DAT_00d6e638;
  *(undefined4 *)(this + 0x50) = DAT_00d6e63c;
  *(undefined4 *)(this + 0x9c) = 0;
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x1e80a;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  ExceptionList = in_stack_00000008;
  return;
}
}

// =================================================
// Function: CPlugTree::ChangeShaderClass
// =================================================
CPlugShader * __thiscall
CPlugTree::ChangeShaderClass(CPlugTree *this,CPlugTree *param_1,ulong param_2)
{
{
  bool bVar1;
  int iVar2;
  CMwClassInfo *this_00;
  ulong uVar3;
  CPlugTree *pCVar4;
  CMwNod *pCVar5;
  CPlugMaterial *unaff_EBP;
  ulong *unaff_ESI;
  undefined4 *puVar6;
  undefined4 *puVar7;
  CMwClassInfo *pCVar8;
  CPlugShader *pCVar9;
  undefined4 local_5c [23];
  
  local_5c[0] = 0x9068000;
  iVar2 = (**(code **)(**(int **)(this + 0x90) + 0x78))();
  if ((iVar2 == 7) && ((*(byte *)(*(int *)(this + 0x90) + 0xb0) & 7) == 0)) {
    puVar6 = local_5c;
    pCVar8 = (CMwClassInfo *)0x1;
    this_00 = CMwNod::StaticGetClassInfo((ulong)param_1);
    uVar3 = CMwClassInfo::MwGetNearestFather(this_00,pCVar8,(ulong)puVar6,unaff_ESI);
    if (uVar3 == 0xffffffff) goto LAB_00849d38;
  }
  if (*(int **)(this + 0x94) == (int *)0x0) goto LAB_00849d38;
  pCVar4 = (CPlugTree *)(**(code **)(**(int **)(this + 0x94) + 0xc))();
  if (pCVar4 == param_1) goto LAB_00849d38;
  pCVar5 = CMwNod::CreateByMwClassId((ulong)param_1);
  pCVar9 = (CPlugShader *)0x9004000;
  iVar2 = (**(code **)(**(int **)(this + 0x94) + 0x10))();
  if (iVar2 == 0) {
LAB_00849d46:
    bVar1 = false;
  }
  else {
    iVar2 = (**(code **)(*(int *)pCVar5 + 0x10))(0x9004000);
    if (iVar2 == 0) goto LAB_00849d46;
    puVar6 = (undefined4 *)(*(int *)(this + 0x94) + 0x38);
    puVar7 = local_5c;
    for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    bVar1 = true;
  }
  SetShader(this,(CPlugBitmapShader *)pCVar5,pCVar9);
  (**(code **)(**(int **)(this + 0x90) + 0x7c))(*(undefined4 *)(this + 0x94));
  if (bVar1) {
    CPlugShaderGeneric::SetMaterial
              (*(CPlugShaderGeneric **)(this + 0x94),(CPlugMaterialCustom *)local_5c,unaff_EBP);
  }
LAB_00849d38:
  return *(CPlugShader **)(this + 0x94);
}
}

// =================================================
// Function: CPlugTree::Chunk
// =================================================
void __thiscall
CPlugTree::Chunk(CPlugTree *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  CNetNod_CheckedArchive *pCVar1;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  uint uVar5;
  CPlugTree *unaff_EBX;
  TiXmlAttribute *unaff_ESI;
  CPlugTree *pCVar6;
  CClassicArchive *pCVar7;
  SCasterCat *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  undefined4 in_stack_00000010;
  CVisionVisualKeeper *in_stack_00000014;
  CPlugVisual *pCVar9;
  CFuncSegment *pCVar10;
  CMwNod *pCVar11;
  int iVar12;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar13;
  CClassicArchive *pCVar14;
  CPlugTree *local_24;
  CVisionVisualKeeper *local_20;
  CVisionVisualKeeper *local_1c;
  CMwNod *local_18;
  CClassicArchive *local_14;
  undefined1 auStack_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pCVar10 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad5130;
  local_c = ExceptionList;
  pCVar2 = (CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffcc);
  ExceptionList = &local_c;
  if (param_2 < (CClassicArchive *)0x904f011) {
    if (param_2 == (CClassicArchive *)0x904f010) {
      CClassicArchive::DoData
                ((CClassicArchive *)param_1,(CNetNod_CheckedArchive *)&param_1,&DAT_00000004,
                 (ulong)pCVar2);
      *(uint *)(this + 0x9c) = (uint)param_2 & 0x1ffff;
      if (((uint)param_2 & 4) != 0) {
        GmIso4::ArchiveGmIso4(this + 0x5c,(GmIso4 *)pCVar10,(CClassicArchive *)unaff_EDI);
      }
      if (*(int *)(pCVar10 + 8) != 0) {
        ExceptionList = puStack_8;
        return;
      }
      *(uint *)(this + 0x9c) =
           (-(*(uint *)(this + 0x9c) >> 0xe) - 1 & 1) << 0xe |
           *(uint *)(this + 0x9c) & 0xffffbfff | 0x2000 | 0x8800;
      ExceptionList = puStack_8;
      return;
    }
    switch(param_2) {
    case (CClassicArchive *)0x904f000:
    case (CClassicArchive *)0x904f001:
    case (CClassicArchive *)0x904f002:
    case (CClassicArchive *)0x904f003:
    case (CClassicArchive *)0x904f004:
    case (CClassicArchive *)0x904f005:
    case (CClassicArchive *)0x904f007:
    case (CClassicArchive *)0x904f008:
    case (CClassicArchive *)0x904f009:
    case (CClassicArchive *)0x904f00a:
    case (CClassicArchive *)0x904f00b:
    case (CClassicArchive *)0x904f00f:
      ExceptionList = puStack_8;
      return;
    case (CClassicArchive *)0x904f006:
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (*(int *)(param_1 + 8) == 0) {
        pCVar6 = this + 0x28;
        CFastBuffer<class_CPlugMaterial*>::ArchiveFastBufferNod
                  (pCVar6,(CFastBuffer<class_CPlugMaterial*> *)param_1,(CClassicArchive *)pCVar2);
        iVar12 = 0x84e1c8;
        pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           (pCVar6,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
        if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          ExceptionList = puStack_8;
          return;
        }
        do {
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (pCVar6,pCVar8,(ulong)pCVar10);
          pCVar10 = (CFuncSegment *)0x0;
          ConnectAsChild(this,*(CPlugTree **)pSVar4,(CPlugTree *)0x0,iVar12);
          pCVar8 = pCVar8 + 1;
        } while (pCVar8 < pCVar3);
        ExceptionList = puStack_8;
        return;
      }
      if (*(int *)(this + 0x1c) == 0) {
        iVar12 = *(int *)(this + 0xa0);
        if (((iVar12 == 0) || ((*(byte *)(iVar12 + 0x14) & 1) != 0)) ||
           ((*(int *)(param_1 + 0x10) != 0 && ((*(byte *)(iVar12 + 0x14) & 2) == 0)))) {
          CFastBuffer<class_CPlugMaterial*>::ArchiveFastBufferNod
                    (this + 0x28,(CFastBuffer<class_CPlugMaterial*> *)param_1,
                     (CClassicArchive *)pCVar2);
          ExceptionList = puStack_8;
          return;
        }
        pCVar7 = (CClassicArchive *)0x84e272;
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(&local_18,pCVar2);
        pCVar6 = this + 0x28;
        pCVar13 = (CFastBuffer<class_CPlugFileGPUV*> *)0x84e284;
        pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           (pCVar6,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
        if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (pCVar6,pCVar8,(ulong)pCVar7);
            pCVar7 = (CClassicArchive *)0x84e29f;
            iVar12 = GetIsRooted(*(CPlugTree **)pSVar4,(CPlugTree *)pCVar13);
            if (iVar12 != 0) {
              pCVar7 = (CClassicArchive *)0x84e2ab;
              unaff_EDI = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                    (pCVar6,pCVar8,(ulong)unaff_EDI);
              pCVar13 = (CFastBuffer<class_CPlugFileGPUV*> *)0x84e2b5;
              CFastBuffer<class_CDx9TextureKeeper*>::Add
                        (auStack_10,(TiXmlAttributeSet *)unaff_EDI,unaff_ESI);
            }
            pCVar8 = pCVar8 + 1;
          } while (pCVar8 < pCVar3);
        }
      }
      else {
        pCVar7 = (CClassicArchive *)0x84e200;
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(&local_18,pCVar2);
        pCVar6 = this + 0x28;
        pCVar13 = (CFastBuffer<class_CPlugFileGPUV*> *)0x84e20e;
        pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           (pCVar6,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
        pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pCVar8 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (pCVar6,pCVar3,(ulong)pCVar7);
            pCVar7 = (CClassicArchive *)0x84e22f;
            iVar12 = GetIsRooted(*(CPlugTree **)pSVar4,(CPlugTree *)pCVar13);
            if (iVar12 != 0) {
              pCVar7 = (CClassicArchive *)0x84e23b;
              unaff_EDI = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                    (pCVar6,pCVar3,(ulong)unaff_EDI);
              pCVar13 = (CFastBuffer<class_CPlugFileGPUV*> *)0x84e245;
              CFastBuffer<class_CDx9TextureKeeper*>::Add
                        (auStack_10,(TiXmlAttributeSet *)unaff_EDI,unaff_ESI);
            }
            pCVar3 = pCVar3 + 1;
          } while (pCVar3 < pCVar8);
        }
      }
      CFastBuffer<class_CPlugMaterial*>::ArchiveFastBufferNod
                (&local_1c,(CFastBuffer<class_CPlugMaterial*> *)pCVar10,pCVar7);
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(&local_18,pCVar13);
      ExceptionList = puStack_8;
      return;
    case (CClassicArchive *)0x904f00c:
      if (*(int *)(param_1 + 8) != 0) {
        ExceptionList = puStack_8;
        return;
      }
      CClassicArchive::DoNatural
                ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(ulong *)0x1,0,(int)pCVar2);
      if (param_2 == (CClassicArchive *)0x0) {
        ExceptionList = puStack_8;
        return;
      }
      pCVar14 = (CClassicArchive *)0x84e314;
      CMwId::CMwId(&param_3,(CMwId *)unaff_EDI);
      pCVar7 = (CClassicArchive *)0x0;
      param_1 = (CFuncSegment *)0x2;
      if (param_3 != 0) {
        do {
          CMwId::Archive(&param_2,(CFastCrypt<unsigned_long> *)pCVar10,pCVar14);
          pCVar7 = pCVar7 + 1;
        } while (pCVar7 < param_2);
      }
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)unaff_EDI);
      ExceptionList = puStack_8;
      return;
    case (CClassicArchive *)0x904f00d:
      CMwId::Archive(this + 0x18,(CFastCrypt<unsigned_long> *)param_1,(CClassicArchive *)pCVar2);
      param_2 = *(CClassicArchive **)(this + 0x1c);
      (**(code **)(*(int *)pCVar10 + 4))(&param_2);
      if (param_2 == (CClassicArchive *)0x0) {
        ExceptionList = puStack_8;
        return;
      }
      CMwId::Archive(this + 0x20,(CFastCrypt<unsigned_long> *)pCVar10,(CClassicArchive *)unaff_EDI);
      if (*(int *)(pCVar10 + 8) != 0) {
        ExceptionList = puStack_8;
        return;
      }
      CMwNod::MwAddRef((CMwNod *)param_3,(CMwNod *)0x84e396);
      *(undefined4 *)(this + 0x1c) = in_stack_00000010;
      ExceptionList = puStack_8;
      return;
    case (CClassicArchive *)0x904f00e:
      if (*(int *)(this + 0x1c) != 0) {
        ExceptionList = puStack_8;
        return;
      }
      param_2 = *(CClassicArchive **)(this + 0x94);
      local_24 = *(CPlugTree **)(this + 0x8c);
      local_20 = *(CVisionVisualKeeper **)(this + 0x90);
      (**(code **)(*(int *)param_1 + 4))(&local_20);
      (**(code **)(*(int *)pCVar10 + 4))(&param_1);
      (**(code **)(*(int *)pCVar10 + 4))(&stack0xffffffd4);
      if (*(int *)(pCVar10 + 8) != 0) {
        ExceptionList = puStack_8;
        return;
      }
      pCVar11 = (CMwNod *)0x0;
      SetVisual(this,local_1c,(CPlugVisual *)param_3);
      InternalLoadSetSurface(this,unaff_EBX,pCVar11);
      ExceptionList = puStack_8;
      return;
    }
switchD_0084e1a4_default:
    CMwNod::Chunk((CMwNod *)this,param_1,param_2,(ulong)pCVar2);
    ExceptionList = puStack_8;
    return;
  }
  if ((CClassicArchive *)0x904f018 < param_2) {
    if (param_2 < (CClassicArchive *)0x9050001) {
      if (param_2 == (CClassicArchive *)0x9050000) {
        param_2 = *(CClassicArchive **)(this + 0x90);
        (**(code **)(*(int *)param_1 + 4))(&param_2);
        SetVisual(this,in_stack_00000014,(CPlugVisual *)0x0);
        ExceptionList = puStack_8;
        return;
      }
      if (param_2 == (CClassicArchive *)0x904f019) {
        pCVar1 = (CNetNod_CheckedArchive *)(this + 0x9c);
        CClassicArchive::DoData((CClassicArchive *)param_1,pCVar1,&DAT_00000004,(ulong)pCVar2);
        if (((byte)*pCVar1 & 4) != 0) {
          GmIso4::ArchiveGmIso4(this + 0x5c,(GmIso4 *)pCVar10,(CClassicArchive *)unaff_EDI);
        }
        if (*(int *)(pCVar10 + 8) != 0) {
          ExceptionList = puStack_8;
          return;
        }
        *(uint *)pCVar1 = *(uint *)pCVar1 | 0x2800;
      }
      else {
        if (param_2 != (CClassicArchive *)0x904f01a) goto switchD_0084e1a4_default;
        pCVar1 = (CNetNod_CheckedArchive *)(this + 0x9c);
        CClassicArchive::DoData((CClassicArchive *)param_1,pCVar1,&DAT_00000004,(ulong)pCVar2);
        if (((byte)*pCVar1 & 4) != 0) {
          GmIso4::ArchiveGmIso4(this + 0x5c,(GmIso4 *)pCVar10,(CClassicArchive *)unaff_EDI);
        }
        if (*(int *)(pCVar10 + 8) != 0) {
          ExceptionList = puStack_8;
          return;
        }
        *(uint *)pCVar1 = *(uint *)pCVar1 | 0x2000;
      }
      if (*(int *)(pCVar10 + 0x10) == 0) {
        ExceptionList = puStack_8;
        return;
      }
      *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x8000;
      ExceptionList = puStack_8;
      return;
    }
    if (param_2 < (CClassicArchive *)0x9050004) {
      if (param_2 == (CClassicArchive *)0x9050003) {
        param_2 = *(CClassicArchive **)(this + 0x8c);
        (**(code **)(*(int *)param_1 + 4))(&param_2);
        if (*(int *)(pCVar10 + 8) != 0) {
          ExceptionList = puStack_8;
          return;
        }
        InternalLoadSetSurface(this,(CPlugTree *)param_3,(CMwNod *)unaff_EDI);
        ExceptionList = puStack_8;
        return;
      }
      if (param_2 == (CClassicArchive *)0x9050001) {
        CClassicArchive::DoBool
                  ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(int *)0x1,(ulong)pCVar2);
        if (param_2 != (CClassicArchive *)0x0) {
          GmIso4::ArchiveGmIso4(this + 0x5c,(GmIso4 *)pCVar10,(CClassicArchive *)unaff_EDI);
        }
        (**(code **)(*(int *)pCVar10 + 4))();
        (**(code **)(*(int *)pCVar10 + 4))(this + 0x14);
        *(uint *)(this + 0x9c) =
             *(uint *)(this + 0x9c) ^
             ((uint)(param_2 != (CClassicArchive *)0x0) * 4 ^ *(uint *)(this + 0x9c)) & 4;
        ExceptionList = puStack_8;
        return;
      }
      if (param_2 == (CClassicArchive *)0x9050002) {
        CClassicArchive::DoBool
                  ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(int *)0x1,(ulong)pCVar2);
        if (param_2 != (CClassicArchive *)0x0) {
          GmIso4::ArchiveGmIso4(this + 0x5c,(GmIso4 *)pCVar10,(CClassicArchive *)unaff_EDI);
        }
        *(uint *)(this + 0x9c) =
             *(uint *)(this + 0x9c) ^
             ((uint)(param_2 != (CClassicArchive *)0x0) * 4 ^ *(uint *)(this + 0x9c)) & 4;
        ExceptionList = puStack_8;
        return;
      }
    }
    else if (param_2 == (CClassicArchive *)0xffffffff) {
      ExceptionList = puStack_8;
      return;
    }
    goto switchD_0084e1a4_default;
  }
  if (param_2 == (CClassicArchive *)0x904f018) {
    CClassicArchive::DoData
              ((CClassicArchive *)param_1,(CNetNod_CheckedArchive *)&local_18,&DAT_00000008,
               (ulong)pCVar2);
    *(uint *)(this + 0x9c) = (uint)local_14 & 0x1ffff;
LAB_0084e563:
    if (((uint)local_14 & 4) != 0) {
      GmIso4::ArchiveGmIso4(this + 0x5c,(GmIso4 *)pCVar10,(CClassicArchive *)unaff_EDI);
    }
    if (*(int *)(pCVar10 + 8) != 0) {
      ExceptionList = puStack_8;
      return;
    }
    *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x2800;
    uVar5 = *(uint *)(this + 0x9c);
LAB_0084e524:
    if (*(int *)(pCVar10 + 0x10) != 0) {
      *(uint *)(this + 0x9c) = uVar5 | 0x8000;
    }
  }
  else {
    switch(param_2) {
    case (CClassicArchive *)0x904f011:
      iVar12 = *(int *)param_1;
      if (*(int *)(param_1 + 8) == 0) {
        param_1 = (CFuncSegment *)0x0;
        (**(code **)(iVar12 + 4))(&param_1);
        if (*(int *)(pCVar10 + 8) == 0) {
          SetFuncTree(this,(CPlugTree *)param_2,(CFuncTree *)unaff_EDI);
        }
      }
      else {
        (**(code **)(iVar12 + 4))(this + 0xa8);
      }
      break;
    case (CClassicArchive *)0x904f012:
      if (*(int *)(this + 0x1c) == 0) {
        local_24 = *(CPlugTree **)(this + 0x90);
        local_20 = *(CVisionVisualKeeper **)(this + 0x94);
        local_1c = *(CVisionVisualKeeper **)(this + 0x8c);
        param_2 = *(CClassicArchive **)(this + 0xa0);
        if ((*(int *)(param_1 + 0x10) != 0) &&
           ((param_2 == (CClassicArchive *)0x0 ||
            (iVar12 = (**(code **)(*(int *)param_2 + 0x10))(0x903f000), iVar12 == 0)))) {
          param_2 = (CClassicArchive *)0x0;
        }
        (**(code **)(*(int *)pCVar10 + 4))(&local_24);
        (**(code **)(*(int *)pCVar10 + 4))(&local_24);
        (**(code **)(*(int *)pCVar10 + 4))(&local_24);
        (**(code **)(*(int *)pCVar10 + 4))(&local_4);
        if (*(int *)(pCVar10 + 8) == 0) {
          iVar12 = 0;
          pCVar11 = (CMwNod *)0x0;
          SetVisual(this,local_20,(CPlugVisual *)local_1c);
          InternalLoadSetSurface(this,(CPlugTree *)local_20,pCVar11);
          SetGenerator(this,(CPlugTree *)param_2,(CPlugTreeGenerator *)0x0,iVar12);
        }
      }
      break;
    case (CClassicArchive *)0x904f013:
      CClassicArchive::DoData
                ((CClassicArchive *)param_1,(CNetNod_CheckedArchive *)&param_1,&DAT_00000004,
                 (ulong)pCVar2);
      *(uint *)(this + 0x9c) = (uint)param_2 & 0x1ffff;
      if (((uint)param_2 & 4) != 0) {
        GmIso4::ArchiveGmIso4(this + 0x5c,(GmIso4 *)pCVar10,(CClassicArchive *)unaff_EDI);
      }
      if (*(int *)(pCVar10 + 8) != 0) {
        ExceptionList = puStack_8;
        return;
      }
      uVar5 = *(uint *)(this + 0x9c) | 0x2000;
      uVar5 = ((-1 - ((*(uint *)(this + 0x9c) & 0x4000) >> 0xe)) * 0x4000 ^ uVar5) & 0x4000 ^ uVar5
              | 0x800;
      *(uint *)(this + 0x9c) = uVar5;
      goto LAB_0084e524;
    case (CClassicArchive *)0x904f014:
      if (*(int *)(this + 0x1c) == 0) {
        param_2 = *(CClassicArchive **)(this + 0x90);
        local_20 = *(CVisionVisualKeeper **)(this + 0x94);
        local_1c = *(CVisionVisualKeeper **)(this + 0x98);
        local_18 = *(CMwNod **)(this + 0x8c);
        local_24 = *(CPlugTree **)(this + 0xa0);
        if ((*(int *)(param_1 + 0x10) != 0) &&
           ((local_24 == (CPlugTree *)0x0 ||
            (iVar12 = (**(code **)(*(int *)local_24 + 0x10))(0x903f000), iVar12 == 0)))) {
          local_24 = (CPlugTree *)0x0;
        }
        (**(code **)(*(int *)pCVar10 + 4))(&param_2);
        (**(code **)(*(int *)pCVar10 + 4))(&local_24);
        (**(code **)(*(int *)pCVar10 + 4))(&local_24);
        (**(code **)(*(int *)pCVar10 + 4))(&local_24);
        (**(code **)(*(int *)pCVar10 + 4))(&stack0xffffffcc);
        if (*(int *)(pCVar10 + 8) == 0) {
          iVar12 = 0;
          if (local_18 == (CMwNod *)0x0) {
            pCVar11 = (CMwNod *)0x0;
            pCVar9 = (CPlugVisual *)local_1c;
          }
          else {
            pCVar9 = (CPlugVisual *)0x0;
            pCVar11 = local_18;
          }
          SetVisual(this,(CVisionVisualKeeper *)param_3,pCVar9);
          InternalLoadSetSurface(this,(CPlugTree *)local_1c,pCVar11);
          SetGenerator(this,local_24,(CPlugTreeGenerator *)0x0,iVar12);
        }
      }
      break;
    case (CClassicArchive *)0x904f015:
      CClassicArchive::DoData
                ((CClassicArchive *)param_1,(CNetNod_CheckedArchive *)&param_1,&DAT_00000004,
                 (ulong)pCVar2);
      *(uint *)(this + 0x9c) = (uint)param_2 & 0x1ffff;
      local_14 = param_2;
      goto LAB_0084e563;
    case (CClassicArchive *)0x904f016:
      if (*(int *)(this + 0x1c) != 0) {
        ExceptionList = puStack_8;
        return;
      }
      local_18 = *(CMwNod **)(this + 0x8c);
      local_24 = *(CPlugTree **)(this + 0x90);
      local_20 = *(CVisionVisualKeeper **)(this + 0xa0);
      param_2 = *(CClassicArchive **)(this + 0x94);
      if (*(CClassicArchive **)(this + 0x98) != (CClassicArchive *)0x0) {
        param_2 = *(CClassicArchive **)(this + 0x98);
      }
      if ((*(int *)(param_1 + 0x10) == 0) ||
         ((local_20 != (CVisionVisualKeeper *)0x0 && (((byte)local_20[0x14] & 2) != 0)))) {
        if ((local_20 != (CVisionVisualKeeper *)0x0) && (((byte)local_20[0x14] & 1) == 0)) {
          local_24 = (CPlugTree *)0x0;
        }
      }
      else {
        local_20 = (CVisionVisualKeeper *)0x0;
      }
      (**(code **)(*(int *)param_1 + 4))(&local_24);
      (**(code **)(*(int *)pCVar10 + 4))(&param_1);
      (**(code **)(*(int *)pCVar10 + 4))(&local_20);
      (**(code **)(*(int *)pCVar10 + 4))(&stack0xffffffd4);
      if (*(int *)(pCVar10 + 8) != 0) {
        ExceptionList = puStack_8;
        return;
      }
      if (param_3 == 0) {
        pCVar11 = (CMwNod *)0x0;
LAB_0084e874:
        pCVar9 = (CPlugVisual *)0x0;
      }
      else {
        iVar12 = (**(code **)(*(int *)param_3 + 0x10))(0x9079000);
        pCVar11 = (CMwNod *)param_3;
        if (iVar12 != 0) goto LAB_0084e874;
        pCVar11 = (CMwNod *)0x0;
        pCVar9 = (CPlugVisual *)param_3;
      }
      iVar12 = 0;
      SetVisual(this,local_20,pCVar9);
      InternalLoadSetSurface(this,(CPlugTree *)local_1c,pCVar11);
      SetGenerator(this,(CPlugTree *)local_20,(CPlugTreeGenerator *)0x0,iVar12);
      break;
    case (CClassicArchive *)0x904f017:
      param_2 = (CClassicArchive *)0x0;
      local_4 = 3;
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)param_1,(CClassicArchive *)&param_2,
                 (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
      if (param_3 != 0) {
        CMwNod::MwRelease((CMwNod *)param_3,(CMwNod *)unaff_EDI);
      }
      break;
    default:
      goto switchD_0084e1a4_default;
    }
  }
  ExceptionList = puStack_8;
  return;
}
}

// =================================================
// Function: CPlugTree::ConnectAsChild
// =================================================
void __thiscall
CPlugTree::ConnectAsChild(CPlugTree *this,CPlugTree *param_1,CPlugTree *param_2,int param_3)
{
{
  CPlugTree *unaff_retaddr;
  
  *(CPlugTree **)(param_1 + 0x24) = this;
  if ((param_2 != (CPlugTree *)0x0) && (*(CPlugSolid **)(this + 0x14) != (CPlugSolid *)0x0)) {
    CPlugSolid::InternalConnectSubTree
              (*(CPlugSolid **)(this + 0x14),(CPlugSolid *)param_1,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CPlugTree::CopyFrom
// =================================================
void __thiscall CPlugTree::CopyFrom(CPlugTree *this,SParam_Set *param_1,SParam *param_2)
{
{
  (**(code **)(*(int *)this + 0xb0))(param_1,1);
  return;
}
}

// =================================================
// Function: CPlugTree::CopyFromModel
// =================================================
void __thiscall
CPlugTree::CopyFromModel(CPlugTree *this,CPlugTreeLight *param_1,CPlugTree *param_2,int param_3)
{
{
  void *pvVar1;
  CMwNod *pCVar2;
  CMwNod *pCVar3;
  CPlugSurface *this_00;
  CPlugTree *extraout_EAX;
  int iVar4;
  CFastBuffer<class_GxVertex2> *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *this_01;
  SCasterCat *pSVar6;
  uint uVar7;
  int iVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CPlugTree *unaff_ESI;
  CPlugTree *pCVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CPlugTreeLight *pCVar11;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  undefined1 *this_02;
  SCasterCat *in_stack_00000018;
  SCasterCat *in_stack_00000020;
  int in_stack_00000024;
  CMwNod *pCVar12;
  CFastBuffer<class_CCrystalFace*> *pCVar13;
  CPlugTree *pCVar14;
  CPlugTree *in_stack_ffffffe8;
  CPlugTree *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad508b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 != (CPlugTreeLight *)0x0) {
    if (*(int *)(param_1 + 0xa4) != 0) {
      pvVar1 = *(void **)(this + 0xa4);
      if (pvVar1 != (void *)0x0) {
        CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                  (pvVar1,(CFastBuffer<class_CPlugFileGPUV*> *)
                          (DAT_00cca150 ^ (uint)&stack0xffffffd4));
        operator_delete(pvVar1);
      }
      pvVar1 = operator_new(0xc);
      if (pvVar1 == (void *)0x0) {
        pvVar1 = (void *)0x0;
      }
      else {
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(pvVar1,unaff_EDI);
      }
      *(void **)(this + 0xa4) = pvVar1;
      CFastBuffer<class_GmIso4>::CopyFromFastBuffer
                (pvVar1,*(CFastBuffer<struct_CDx9StateBlock::STexStageState> **)(param_1 + 0xa4),
                 (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)unaff_EDI);
    }
    if (*(int **)(this + 0xa0) != (int *)0x0) {
      (**(code **)(**(int **)(this + 0xa0) + 0x7c))();
    }
    pCVar2 = GetParametrizedNodFromModel((CMwNod *)this,unaff_ESI);
    if (pCVar2 == (CMwNod *)0x0) {
      pCVar13 = (CFastBuffer<class_CCrystalFace*> *)0x0;
      if (*(int *)(param_1 + 0x98) == 0) {
        pCVar2 = (CMwNod *)0x0;
        pCVar12 = GetParametrizedNodFromModel((CMwNod *)this,(CPlugTree *)0x0);
      }
      else {
        pCVar2 = GetParametrizedNodFromModel((CMwNod *)this,(CPlugTree *)0x0);
        pCVar12 = (CMwNod *)0x0;
      }
      pCVar3 = GetParametrizedNodFromModel((CMwNod *)this,(CPlugTree *)pCVar12);
      SetVisual(this,(CVisionVisualKeeper *)pCVar3,(CPlugVisual *)pCVar12);
      iVar8 = *(int *)(param_1 + 0x8c);
      pCVar9 = (CPlugTree *)0x0;
      pCVar14 = (CPlugTree *)0x0;
      if (iVar8 != 0) {
        this_00 = operator_new(0x24);
        uStack_4 = 0;
        if (this_00 != (CPlugSurface *)0x0) {
          CPlugSurface::CPlugSurface(this_00,(CPlugSurface *)pCVar2);
          pCVar9 = extraout_EAX;
        }
        pCVar2 = *(CMwNod **)(iVar8 + 0x14);
        in_stack_ffffffe8 = pCVar9;
        if (pCVar2 != *(CMwNod **)(pCVar9 + 0x14)) {
          iVar4 = 0;
          if (pCVar2 != (CMwNod *)0x0) {
            CMwNod::MwAddRef(pCVar2,(CMwNod *)pCVar13);
            iVar4 = param_3;
          }
          if (*(CMwNod **)(pCVar9 + 0x14) != (CMwNod *)0x0) {
            CMwNod::MwRelease(*(CMwNod **)(pCVar9 + 0x14),(CMwNod *)pCVar13);
            iVar4 = param_3;
          }
          *(int *)(pCVar9 + 0x14) = iVar4;
        }
        pCVar5 = (CFastBuffer<class_GxVertex2> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount((undefined1 *)(iVar8 + 0x18),pCVar13);
        CFastBufferRef<class_CPlugMaterial>::AllocSetCount(pCVar9 + 0x18,pCVar5,(ulong)unaff_ESI);
        this_01 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                  CFastBuffer<class_CCrystalFace*>::GetCount(pCVar9 + 0x18,unaff_EBP);
        pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        this_02 = (undefined1 *)(iVar8 + 0x18);
        if (this_01 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      (this_02,pCVar10,(ulong)unaff_EBX);
            pCVar2 = GetParametrizedNodFromModel((CMwNod *)this,pCVar14);
            unaff_EBX = pCVar10;
            pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_01,pCVar10,(ulong)pCVar14);
            if (pCVar2 != *(CMwNod **)pSVar6) {
              if (pCVar2 != (CMwNod *)0x0) {
                pCVar14 = (CPlugTree *)0x84d8ca;
                CMwNod::MwAddRef(pCVar2,(CMwNod *)unaff_EBX);
                pSVar6 = in_stack_00000020;
              }
              if (*(CMwNod **)pSVar6 != (CMwNod *)0x0) {
                CMwNod::MwRelease(*(CMwNod **)pSVar6,(CMwNod *)unaff_EBX);
                pSVar6 = in_stack_00000018;
              }
              *(CMwNod **)pSVar6 = pCVar2;
            }
            pCVar10 = pCVar10 + 1;
            this_02 = puStack_8;
          } while (pCVar10 < this_01);
        }
      }
      SetSurface(this,local_c,(CPlugSurface *)unaff_EBX);
      SetGenerator(this,(CPlugTree *)0x0,(CPlugTreeGenerator *)0x1,(int)pCVar14);
    }
    else {
      (**(code **)(*(int *)pCVar2 + 0x80))(param_1);
    }
    pCVar2 = GetParametrizedNodFromModel((CMwNod *)this,in_stack_ffffffe8);
    SetFuncTree(this,(CPlugTree *)pCVar2,(CFuncTree *)in_stack_ffffffe8);
    *(uint *)(this + 0x9c) =
         *(uint *)(this + 0x9c) ^ (*(uint *)(param_1 + 0x9c) ^ *(uint *)(this + 0x9c)) & 0x10;
    uVar7 = (*(uint *)(param_1 + 0x9c) ^ *(uint *)(this + 0x9c)) & 0x20 ^ *(uint *)(this + 0x9c);
    *(uint *)(this + 0x9c) = uVar7;
    uVar7 = (*(uint *)(param_1 + 0x9c) ^ uVar7) & 1 ^ uVar7;
    *(uint *)(this + 0x9c) = uVar7;
    uVar7 = (*(uint *)(param_1 + 0x9c) ^ uVar7) & 0x4000 ^ uVar7;
    *(uint *)(this + 0x9c) = uVar7;
    uVar7 = (*(uint *)(param_1 + 0x9c) ^ uVar7) & 0x8000 ^ uVar7;
    *(uint *)(this + 0x9c) = uVar7;
    if (in_stack_00000024 != 0) {
      uVar7 = uVar7 | 0x10000;
      *(uint *)(this + 0x9c) = uVar7;
      uVar7 = (*(uint *)(param_1 + 0x9c) ^ uVar7) & 4 ^ uVar7;
      *(uint *)(this + 0x9c) = uVar7;
      pCVar11 = param_1 + 0x5c;
      pCVar9 = this + 0x5c;
      for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined4 *)pCVar9 = *(undefined4 *)pCVar11;
        pCVar11 = pCVar11 + 4;
        pCVar9 = pCVar9 + 4;
      }
      *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) ^ (*(uint *)(param_1 + 0x9c) ^ uVar7) & 8;
      uVar7 = (*(uint *)(param_1 + 0x9c) ^ *(uint *)(this + 0x9c)) & 0x80 ^ *(uint *)(this + 0x9c);
      *(uint *)(this + 0x9c) = uVar7;
      uVar7 = (*(uint *)(param_1 + 0x9c) ^ uVar7) & 0x40 ^ uVar7;
      *(uint *)(this + 0x9c) = uVar7;
      *(uint *)(this + 0x9c) = (*(uint *)(param_1 + 0x9c) ^ uVar7) & 0x1000 ^ uVar7;
    }
    (**(code **)(*(int *)this + 0xbc))();
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CPlugTree::CreateChildFromVisual
// =================================================
CPlugTree * __thiscall
CPlugTree::CreateChildFromVisual(CPlugTree *this,CPlugTree *param_1,CPlugVisual *param_2)
{
{
  CPlugTree *pCVar1;
  CPlugTree *this_00;
  CPlugTree *extraout_EAX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4f1b;
  local_c = ExceptionList;
  pCVar1 = (CPlugTree *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  this_00 = operator_new(0xac);
  local_4 = 0;
  if (this_00 == (CPlugTree *)0x0) {
    pCVar1 = (CPlugTree *)0x0;
  }
  else {
    CPlugTree(this_00,pCVar1);
    pCVar1 = extraout_EAX;
  }
  if (param_2 != (CPlugVisual *)0x0) {
    SetVisual(pCVar1,(CVisionVisualKeeper *)param_2,(CPlugVisual *)0x0);
  }
  (**(code **)(*(int *)this + 0x88))(pCVar1);
  ExceptionList = local_c;
  return pCVar1;
}
}

// =================================================
// Function: CPlugTree::CreateGroupSurface
// =================================================
CPlugSurface * __thiscall
CPlugTree::CreateGroupSurface(CPlugTree *this,CPlugTree *param_1,SPlugTreeOptimGroup *param_2)
{
{
  return *(CPlugSurface **)(param_1 + 0x10);
}
}

// =================================================
// Function: CPlugTree::CreateGroupVisual
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CPlugVisual * __thiscall
CPlugTree::CreateGroupVisual(CPlugTree *this,CPlugTree *param_1,SPlugTreeOptimGroup *param_2)
{
{
  int iVar1;
  short *psVar2;
  int *piVar3;
  SCasterCat *pSVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  GxVertex *extraout_EAX;
  ulong unaff_EBX;
  CPlugVisualIndexed *pCVar8;
  CPlugTree *pCVar9;
  GxTexCoordSet *pGVar10;
  int iVar11;
  int unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  int unaff_ESI;
  GmIso3 *pGVar13;
  int iVar14;
  CPlugVisual *pCVar15;
  GmIso3 *unaff_EDI;
  CPlugTree *this_00;
  undefined4 in_stack_0000000c;
  CPlugTree *in_stack_00000014;
  float fVar16;
  ulong uVar17;
  float fVar18;
  void *pvVar19;
  float fVar20;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar21;
  GxTexCoordSet *in_stack_ffffffb8;
  CPlugVisualIndexed *pCVar22;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_40;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_3c;
  CPlugVisualIndexed *local_38;
  GxVertex *local_34;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_30;
  CPlugVisual *local_2c;
  CPlugTree *local_28;
  CPlugVisual *local_24;
  CPlugTree *local_20;
  CPlugVisual *pCStack_1c;
  float fStack_18;
  CPlugVisualIndexedTriangles *pCStack_14;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_10;
  void *local_c;
  undefined1 *puStack_8;
  uint uStack_4;
  
  pCVar9 = param_1;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4dc3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(param_1 + 0xc) == 0) {
    local_2c = (CPlugVisual *)0x0;
  }
  else {
    this_00 = param_1 + 0x3c;
    local_3c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (this_00,(CFastBuffer<class_CCrystalFace*> *)
                                  (DAT_00cca150 ^ (uint)&stack0xffffffa8));
    local_2c = operator_new__(-(uint)((int)((ulonglong)*(uint *)(pCVar9 + 0x38) * 0x28 >> 0x20) != 0
                                     ) | (uint)((ulonglong)*(uint *)(pCVar9 + 0x38) * 0x28));
    local_30 = operator_new__(-(uint)((int)((ulonglong)*(uint *)(pCVar9 + 0x30) * 2 >> 0x20) != 0) |
                              (uint)((ulonglong)*(uint *)(pCVar9 + 0x30) * 2));
    local_24 = (CPlugVisual *)0x0;
    pCVar22 = (CPlugVisualIndexed *)0x0;
    local_34 = (GxVertex *)0x0;
    local_40 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (local_3c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<struct_SChildGen>::operator[](this_00,local_40,(ulong)unaff_EDI);
        piVar3 = *(int **)(*(int *)pSVar4 + 0x90);
        if (piVar3 != (int *)0x0) {
          if ((piVar3[7] & 0x100U) != 0) {
            local_24 = (CPlugVisual *)0x1;
          }
          if ((char)piVar3[7] < '\0') {
            local_20 = (CPlugTree *)0x1;
          }
          iVar5 = (**(code **)(*piVar3 + 0xb8))();
          unaff_EDI = (GmIso3 *)((int)local_40 * 0x28);
          (**(code **)(*piVar3 + 0xc0))();
          if ((*(int *)(pSVar4 + 4) != 0) && (iVar5 != 0)) {
            pCVar8 = local_38;
            pGVar13 = (GmIso3 *)((int)local_40 * 0x28) + 0x14;
            do {
              GmVec3::Mult(pGVar13 + -0x14,(GmIso3 *)(pSVar4 + 8),unaff_EDI);
              pCVar8 = pCVar8 + -1;
              fStack_18 = *(float *)(pSVar4 + 0x10) * *(float *)pGVar13 +
                          *(float *)(pGVar13 + -4) * *(float *)(pSVar4 + 0xc) +
                          *(float *)(pGVar13 + -8) * *(float *)(pSVar4 + 8);
              pCStack_14 = (CPlugVisualIndexedTriangles *)
                           (*(float *)pGVar13 * *(float *)(pSVar4 + 0x1c) +
                           *(float *)(pSVar4 + 0x14) * *(float *)(pGVar13 + -8) +
                           *(float *)(pGVar13 + -4) * *(float *)(pSVar4 + 0x18));
              pCStack_10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                           (*(float *)(pSVar4 + 0x28) * *(float *)pGVar13 +
                           *(float *)(pGVar13 + -8) * *(float *)(pSVar4 + 0x20) +
                           *(float *)(pGVar13 + -4) * *(float *)(pSVar4 + 0x24));
              *(float *)(pGVar13 + -8) = fStack_18;
              *(CPlugVisualIndexedTriangles **)(pGVar13 + -4) = pCStack_14;
              *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pGVar13 = pCStack_10;
              pGVar13 = pGVar13 + 0x28;
            } while (pCVar8 != (CPlugVisualIndexed *)0x0);
          }
          uVar6 = (**(code **)(*piVar3 + 0xcc))(0);
          iVar1 = iVar5 + (int)local_38 * 2;
          (**(code **)(*piVar3 + 0xd0))(iVar1);
          uVar7 = 0;
          if (uVar6 != 0) {
            do {
              psVar2 = (short *)(iVar1 + uVar7 * 2);
              *psVar2 = *psVar2 + (short)pCVar22;
              uVar7 = uVar7 + 1;
            } while (uVar7 < uVar6);
          }
          pCVar22 = pCVar22 + (int)local_38;
          local_34 = (GxVertex *)(iVar5 + uVar6);
          pCVar9 = (CPlugTree *)param_2;
          this_00 = local_20;
        }
        local_40 = local_40 + 1;
      } while (local_40 < local_3c);
    }
    pCStack_14 = operator_new(0x9c);
    if (pCStack_14 == (CPlugVisualIndexedTriangles *)0x0) {
      local_38 = (CPlugVisualIndexed *)0x0;
    }
    else {
      CPlugVisualIndexedTriangles::CPlugVisualIndexedTriangles
                (pCStack_14,(CPlugVisualIndexedTriangles *)unaff_EDI);
      local_34 = extraout_EAX;
    }
    CPlugVisualIndexed::SetVerticesAndIndices
              (local_38,pCVar22,(ulong)local_2c,local_34,(ulong)local_30,(ushort *)unaff_EDI);
    fVar16 = 1.2182523e-38;
    CPlugVisual::EnableVertexColor((CPlugVisual *)local_38,local_24,unaff_ESI);
    uVar17 = 0x84a7f7;
    CPlugVisual::EnableVertexNormal((CPlugVisual *)local_38,pCStack_1c,unaff_EBP);
    pCStack_10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 (*(uint *)(*(int *)(pCVar9 + 0xc) + 0x20) & 0xf);
    local_24 = (CPlugVisual *)0x0;
    pCVar15 = (CPlugVisual *)local_38;
    if (pCStack_10 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        uStack_4 = 0x100;
        in_stack_0000000c = 1;
        fVar18 = 1.2182635e-38;
        pSVar4 = CFastBuffer<struct_SChildGen>::operator[]
                           (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBX)
        ;
        fVar20 = 1.2182659e-38;
        pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                           ((void *)(*(int *)(*(int *)pSVar4 + 0x90) + 0x5c),
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)local_24,
                            (ulong)in_stack_ffffffb8);
        in_stack_ffffffb8 = *(GxTexCoordSet **)(pCVar9 + 0x34);
        param_1 = (CPlugTree *)(*(uint *)pSVar4 & 0xff ^ 0x100);
        unaff_EBX = 0x84a86d;
        GxTexCoordSet::Alloc(&param_1,in_stack_ffffffb8,(ulong)pCVar22);
        pGVar10 = (GxTexCoordSet *)0x0;
        local_28 = (CPlugTree *)0x0;
        if (local_24 != (CPlugVisual *)0x0) {
          do {
            pSVar4 = CFastBuffer<struct_SChildGen>::operator[]
                               (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar10,
                                (ulong)local_34);
            piVar3 = *(int **)(*(int *)pSVar4 + 0x90);
            if (piVar3 != (int *)0x0) {
              pSVar4 = CFastBuffer<struct_SFastCat>::operator[]
                                 (piVar3 + 0x17,
                                  (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)local_24,
                                  (ulong)fVar16);
              fVar16 = 1.2182805e-38;
              pCStack_14 = (CPlugVisualIndexedTriangles *)pSVar4;
              iVar5 = (**(code **)(*piVar3 + 0xbc))();
              uVar6 = (uint)fStack_18 & 0xff;
              if (uVar6 == (*(uint *)pSVar4 & 0xff)) {
                _memcpy(pCStack_14 + *(int *)(&DAT_00c40e80 + uVar6 * 4) * (int)local_3c,
                        *(void **)(pSVar4 + 4),*(int *)(&DAT_00c40e80 + uVar6 * 4) * iVar5);
                local_34 = (GxVertex *)local_24;
              }
              else {
                iVar1 = *(int *)(&DAT_00c40e80 + uVar6 * 4);
                uVar6 = *(uint *)(&DAT_00c40e80 + (*(uint *)pSVar4 & 0xff) * 4);
                local_2c = (CPlugVisual *)&DAT_00c40e8c;
                if (uVar6 == 1) {
                  local_2c = (CPlugVisual *)&DAT_00c40e90;
                }
                local_34 = (GxVertex *)local_24;
                if (iVar5 != 0) {
                  iVar11 = 0;
                  iVar14 = iVar1 * (int)local_3c;
                  pGVar10 = in_stack_ffffffb8;
                  local_30 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)iVar5;
                  do {
                    _memcpy(pCStack_14 + iVar14,(void *)(_DAT_00000004 + iVar11),uVar6);
                    _memcpy(pCStack_14 + uVar6 + iVar14,local_2c,iVar1 - uVar6);
                    iVar14 = iVar14 + iVar1;
                    iVar11 = iVar11 + uVar6;
                    local_30 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                               ((int)local_30 + -1);
                  } while (local_30 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0);
                  local_30 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
                  local_34 = (GxVertex *)local_24;
                }
              }
              local_3c = local_3c + iVar5;
              local_24 = (CPlugVisual *)local_38;
              this_00 = local_28;
            }
            pGVar10 = pGVar10 + 1;
            in_stack_ffffffb8 = pGVar10;
          } while (pGVar10 < pCVar22);
        }
        CPlugVisual::AddTexCoordSet
                  ((CPlugVisual *)local_40,(CPlugVisualSprite *)&fStack_18,(float)local_34,fVar16,
                   uVar17,fVar18,fVar20);
        in_stack_0000000c = 0xffffffff;
        if ((uStack_4 & 0x100) != 0) {
          operator_delete__((void *)0x0);
        }
        local_24 = local_24 + 1;
        pCVar9 = in_stack_00000014;
        pCVar15 = local_2c;
      } while (local_24 < pCStack_10);
    }
    if ((*(uint *)(*(int *)(pCVar9 + 0xc) + 0x24) & 0x8000000) != 0) {
      CFastArray<class_GmVec3>::SetCount
                (pCVar15 + 0x84,*(CFastBuffer<class_CSystemFidsFolder*> **)(pCVar9 + 0x38),unaff_EBX
                );
      pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (local_2c != (CPlugVisual *)0x0) {
        do {
          pCVar21 = pCVar12;
          pSVar4 = CFastBuffer<struct_SChildGen>::operator[](this_00,pCVar12,unaff_EBX);
          piVar3 = *(int **)(*(int *)pSVar4 + 0x90);
          if (piVar3 != (int *)0x0) {
            unaff_EBX = 0x84aa37;
            iVar5 = (**(code **)(*piVar3 + 0xb8))();
            if (piVar3[0x22] == 0) {
              (**(code **)(*piVar3 + 0x138))(0,0);
            }
            pvVar19 = (void *)(iVar5 * 0xc);
            pSVar4 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                               (local_30 + 0x84,local_3c,piVar3[0x22]);
            _memcpy(pSVar4,pvVar19,(uint)pCVar21);
          }
          pCVar12 = pCVar12 + 1;
        } while (pCVar12 < local_30);
      }
    }
  }
  ExceptionList = param_1;
  return local_2c;
}
}

// =================================================
// Function: CPlugTree::CreateModelInstance
// =================================================
CPlugSolid * __thiscall CPlugTree::CreateModelInstance(CPlugTree *this,CPlugSolid *param_1)
{
{
  CMwNod *this_00;
  CMwNod *pCVar1;
  int iVar2;
  CPlugSolid *pCVar3;
  CSystemFidParameters *pCVar4;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  CSystemFidParameters *pCVar5;
  undefined1 auStack_44 [4];
  CSystemFidParameters aCStack_40 [4];
  CSystemFidParameters aCStack_3c [8];
  CSystemFidParameters aCStack_34 [40];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4c30;
  local_c = ExceptionList;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffb0);
  ExceptionList = &local_c;
  iVar2 = (**(code **)(*(int *)this + 8))();
  pCVar3 = (CPlugSolid *)(**(code **)(iVar2 + 0x1c))();
  this_00 = *(CMwNod **)(this + 0x14);
  *(CMwNod **)(pCVar3 + 0x1c) = this_00;
  CMwNod::MwAddRef(this_00,pCVar1);
  if ((*(int *)(this + 0x24) == 0) && ((*(uint *)(this + 0x18) & 0xc0000000) != 0x40000000)) {
    *(int *)(pCVar3 + 0x20) = -1;
  }
  else {
    *(int *)(pCVar3 + 0x20) = *(int *)(this + 0x18);
  }
  pCVar5 = (CSystemFidParameters *)0x1;
  (**(code **)(*(int *)pCVar3 + 0xb0))();
  CSystemFidParameters::CSystemFidParameters(aCStack_40,(CSystemFidParameters *)this,pCVar5);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(auStack_44,unaff_EDI);
  iVar2 = *(int *)pCVar3;
  pCVar5 = aCStack_34;
  pCVar4 = CSystemFidParameters::GetCurrentParameters();
  (**(code **)(iVar2 + 0x54))();
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (&stack0xffffffb4,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar4);
  uStack_4 = 0xffffffff;
  CSystemFidParameters::~CSystemFidParameters(aCStack_3c,pCVar5);
  ExceptionList = puStack_8;
  return pCVar3;
}
}

// =================================================
// Function: CPlugTree::DeconnectAsChild
// =================================================
void __thiscall CPlugTree::DeconnectAsChild(CPlugTree *this,CPlugTree *param_1,CPlugTree *param_2)
{
{
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    CPlugSolid::InternalDisconnectSubTree
              (*(CPlugSolid **)(this + 0x14),(CPlugSolid *)param_1,param_2);
    return;
  }
  return;
}
}

// =================================================
// Function: CPlugTree::DeleteAllChilds
// =================================================
void __thiscall CPlugTree::DeleteAllChilds(CPlugTree *this,CPlugTreeVisualMip *param_1)
{
{
  int iVar1;
  
  for (iVar1 = (**(code **)(*(int *)this + 0x7c))(); iVar1 != 0; iVar1 = iVar1 + -1) {
    (**(code **)(*(int *)this + 0x9c))(0);
  }
  return;
}
}

// =================================================
// Function: CPlugTree::DeleteAllVolatileChilds
// =================================================
void __thiscall CPlugTree::DeleteAllVolatileChilds(CPlugTree *this,CPlugTree *param_1)
{
{
  CPlugTree *pCVar1;
  CPlugTree *this_00;
  int iVar2;
  CPlugTree *pCVar3;
  CPlugTree *pCVar4;
  
  pCVar1 = (CPlugTree *)(**(code **)(*(int *)this + 0x7c))();
  pCVar3 = (CPlugTree *)0x0;
  if (pCVar1 != (CPlugTree *)0x0) {
    do {
      pCVar4 = pCVar3;
      this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))();
      iVar2 = GetIsRooted(this_00,pCVar4);
      if (iVar2 == 0) {
        (**(code **)(*(int *)this + 0x9c))(pCVar3);
        pCVar3 = pCVar3 + -1;
        pCVar1 = pCVar1 + -1;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CPlugTree::DeleteChild
// =================================================
void __thiscall CPlugTree::DeleteChild(CPlugTree *this,CPlugTree *param_1,ulong param_2)
{
{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*(int *)this + 0xa4))(param_1);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0086a9c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 4))();
    return;
  }
  return;
}
}

// =================================================
// Function: CPlugTree::DeleteChildPtr
// =================================================
void __thiscall CPlugTree::DeleteChildPtr(CPlugTree *this,CPlugTree *param_1,CPlugTree *param_2)
{
{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*(int *)this + 0xa8))(param_1);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00848542. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 4))();
    return;
  }
  return;
}
}

// =================================================
// Function: CPlugTree::DetachChild
// =================================================
CPlugTree * __thiscall
CPlugTree::DetachChild(CPlugTree *this,CPlugTreeVisualMip *param_1,ulong param_2)
{
{
  CPlugTree *pCVar1;
  SCasterCat *pSVar2;
  CPlugTree *unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x28,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_EDI);
  pCVar1 = *(CPlugTree **)pSVar2;
  CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt
            (this + 0x28,(CFastBufferRef<class_CGameMobil> *)param_1,1,unaff_ESI);
  DeconnectAsChild(this,pCVar1,unaff_EBP);
  return pCVar1;
}
}

// =================================================
// Function: CPlugTree::DetachChildPtr
// =================================================
CPlugTree * __thiscall
CPlugTree::DetachChildPtr(CPlugTree *this,CPlugTree *param_1,CPlugTree *param_2)
{
{
  int iVar1;
  CPlugTree *pCVar2;
  GxTexCoordSet *unaff_ESI;
  
  iVar1 = CFastArray<class_CGameMenuFrame*>::Find
                    (this + 0x28,(CFastArray<class_GxTexCoordSet> *)&param_1,unaff_ESI);
  if (iVar1 == -1) {
    return (CPlugTree *)0x0;
  }
  pCVar2 = (CPlugTree *)(**(code **)(*(int *)this + 0xa4))(iVar1);
  return pCVar2;
}
}

// =================================================
// Function: CPlugTree::DisconnectFromModel
// =================================================
void __thiscall CPlugTree::DisconnectFromModel(CPlugTree *this,CPlugSolid *param_1,int param_2)
{
{
  uint uVar1;
  CPlugTree *this_00;
  CPlugSolid *unaff_EBX;
  uint uVar2;
  CPlugSolid *pCVar3;
  int iVar4;
  
  (**(code **)(*(int *)this + 0xac))(param_1,param_2);
  uVar1 = (**(code **)(*(int *)this + 0x7c))();
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      pCVar3 = unaff_EBX;
      iVar4 = param_2;
      this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))(uVar2);
      DisconnectFromModel(this_00,pCVar3,iVar4);
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}
}

// =================================================
// Function: CPlugTree::DisconnectThisFromModel
// =================================================
void __thiscall
CPlugTree::DisconnectThisFromModel
          (CPlugTree *this,CPlugTreeLight *param_1,int param_2,ulong param_3)
{
{
  uint uVar1;
  ulong uVar2;
  CSystemArchiveNod *extraout_ECX;
  CSystemArchiveNod *extraout_ECX_00;
  CSystemArchiveNod *extraout_ECX_01;
  CSystemArchiveNod *extraout_ECX_02;
  CSystemArchiveNod *this_00;
  CPlugSurface *unaff_EBX;
  CMwNod *unaff_ESI;
  CPlugVisual *in_stack_00000010;
  CPlugTree *pCVar3;
  
  pCVar3 = this;
  if (*(CMwNod **)(this + 0x1c) == (CMwNod *)0x0) {
    if (param_1 == (CPlugTreeLight *)0x0) {
      return;
    }
    this_00 = (CSystemArchiveNod *)0x0;
  }
  else {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1c),unaff_ESI);
    this_00 = extraout_ECX;
  }
  uVar2 = param_3;
  param_2 = *(int *)(this + 0xa0);
  *(undefined4 *)(this + 0x1c) = 0;
  if (param_2 == 0) {
    if (*(int *)(this + 0x90) != 0) {
      uVar1 = param_3 & 2;
      param_3 = *(ulong *)(this + 0x94);
      if (uVar1 != 0) {
        CSystemArchiveNod::Duplicate(this_00,(CPlugVisualVertexs *)&stack0x00000000);
      }
      if (((uVar2 & 4) != 0) && (*(int *)(this + 0x94) != 0)) {
        CSystemArchiveNod::Duplicate
                  ((CSystemArchiveNod *)&stack0x00000010,(CPlugVisualVertexs *)&stack0x00000010);
      }
      SetVisual(this,(CVisionVisualKeeper *)param_1,in_stack_00000010);
      this_00 = extraout_ECX_01;
    }
    if ((*(int *)(this + 0x8c) != 0) && ((uVar2 & 1) != 0)) {
      param_2 = *(int *)(this + 0x8c);
      CSystemArchiveNod::Duplicate((CSystemArchiveNod *)&param_2,(CPlugVisualVertexs *)&param_2);
      SetSurface(this,(CPlugTree *)param_3,unaff_EBX);
      this_00 = extraout_ECX_02;
    }
  }
  else if ((param_3 & 0x10) != 0) {
    CSystemArchiveNod::Duplicate(this_00,(CPlugVisualVertexs *)&param_2);
    unaff_EBX = (CPlugSurface *)0x1;
    SetGenerator(this,(CPlugTree *)param_3,(CPlugTreeGenerator *)0x1,(int)pCVar3);
    this_00 = extraout_ECX_00;
  }
  if ((*(int *)(this + 0xa8) != 0) && ((uVar2 & 0x20) != 0)) {
    param_2 = *(int *)(this + 0xa8);
    CSystemArchiveNod::Duplicate(this_00,(CPlugVisualVertexs *)&param_2);
    SetFuncTree(this,(CPlugTree *)param_3,(CFuncTree *)unaff_EBX);
  }
  (**(code **)(*(int *)this + 0xbc))(1);
  return;
}
}

// =================================================
// Function: CPlugTree::DuplicateRecursive
// =================================================
CPlugTree * __thiscall CPlugTree::DuplicateRecursive(CPlugTree *this,CPlugTree *param_1)
{
{
  CPlugTree *pCVar1;
  
  pCVar1 = (CPlugTree *)(**(code **)(*(int *)this + 200))(DuplicateThis,1,0);
  (**(code **)(*(int *)pCVar1 + 0x78))(0);
  (**(code **)(*(int *)pCVar1 + 0xbc))(1);
  return pCVar1;
}
}

// =================================================
// Function: CPlugTree::DuplicateThis
// =================================================
CPlugTree * __thiscall CPlugTree::DuplicateThis(CPlugTree *this,CPlugTree *param_1)
{
{
  CPlugTree *pCVar1;
  CPlugSolid *this_00;
  int iVar2;
  CSystemFidParameters *pCVar3;
  CMwId *unaff_ESI;
  CPlugSolid *unaff_EDI;
  void *in_stack_00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000018;
  undefined1 uStack0000001c;
  CPlugTree *in_stack_ffffffb8;
  int in_stack_ffffffbc;
  CSystemFidParameters *in_stack_ffffffc0;
  CSystemFidParameters *in_stack_ffffffc4;
  CSystemFidParameters *pCVar4;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffffc8;
  undefined1 auStack_34 [8];
  undefined1 auStack_2c [4];
  CSystemFidParameters aCStack_28 [4];
  CSystemFidParameters aCStack_24 [8];
  CSystemFidParameters aCStack_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4d30;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(this + 0x1c) == 0) {
    iVar2 = (**(code **)(*(int *)this + 8))();
    this_00 = (CPlugSolid *)(**(code **)(iVar2 + 0x1c))();
    (**(code **)(*(int *)this_00 + 0xb0))(this,1);
  }
  else {
    pCVar1 = GetModelTree(this,(CPlugTree *)(DAT_00cca150 ^ (uint)&stack0xffffffb0));
    this_00 = CreateModelInstance(pCVar1,unaff_EDI);
  }
  pCVar1 = (CPlugTree *)(**(code **)(*(int *)this + 0x14))();
  InternalSetMwId((CPlugTree *)this_00,pCVar1,unaff_ESI);
  pCVar1 = (CPlugTree *)GetIsRooted(this,in_stack_ffffffb8);
  SetIsRooted((CPlugTree *)this_00,pCVar1,in_stack_ffffffbc);
  CSystemFidParameters::CSystemFidParameters(aCStack_28,in_stack_ffffffc0,in_stack_ffffffc4);
  uStack00000018 = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (auStack_2c,in_stack_ffffffc8);
  iVar2 = *(int *)this_00;
  pCVar4 = aCStack_1c;
  uStack0000001c = 1;
  pCVar3 = CSystemFidParameters::GetCurrentParameters();
  (**(code **)(iVar2 + 0x54))();
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (auStack_34,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar3);
  uStack00000014 = 0xffffffff;
  CSystemFidParameters::~CSystemFidParameters(aCStack_24,pCVar4);
  ExceptionList = in_stack_00000010;
  return (CPlugTree *)this_00;
}
}

// =================================================
// Function: CPlugTree::FindTree
// =================================================
int __thiscall CPlugTree::FindTree(CPlugTree *this,CPlugTree *param_1,CPlugTree *param_2)
{
{
  while( true ) {
    if (param_1 == (CPlugTree *)0x0) {
      return 0;
    }
    if (param_1 == this) break;
    param_1 = *(CPlugTree **)(param_1 + 0x24);
  }
  return 1;
}
}

// =================================================
// Function: CPlugTree::Generate
// =================================================
void __thiscall CPlugTree::Generate(CPlugTree *this,CPlugTree *param_1,int param_2)
{
{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  CPlugTree *unaff_EDI;
  uint uVar5;
  CPlugTree *pCVar6;
  
  if ((*(int *)(this + 0xa0) == 0) ||
     ((param_1 == (CPlugTree *)0x0 &&
      ((*(int *)(this + 0x90) != 0 || (uVar1 = GetVolatileChildCount(this,unaff_EDI), uVar1 != 0))))
     )) {
    if (*(int **)(this + 0xa0) == (int *)0x0) goto LAB_0084b4b9;
    pCVar6 = (CPlugTree *)0x909a000;
    iVar2 = (**(code **)(**(int **)(this + 0xa0) + 0x10))();
    if ((iVar2 == 0) || (uVar1 = GetRootedChildCount(this,pCVar6), uVar1 == 0)) goto LAB_0084b4b9;
  }
  (**(code **)(**(int **)(this + 0xa0) + 0x78))(this);
  (**(code **)(*(int *)this + 0xbc))(1);
LAB_0084b4b9:
  uVar3 = (**(code **)(*(int *)this + 0x7c))();
  uVar5 = 0;
  if (uVar3 != 0) {
    do {
      piVar4 = (int *)(**(code **)(*(int *)this + 0x80))(uVar5);
      (**(code **)(*piVar4 + 0x78))(param_1);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar3);
  }
  return;
}
}

// =================================================
// Function: CPlugTree::GenerateOptimizedTree
// =================================================
void __thiscall
CPlugTree::GenerateOptimizedTree
          (CPlugTree *this,CPlugTree *param_1,CPlugTree **param_2,SPlugTreeOptimCriteria *param_3)
{
{
  CPlugVisual *this_00;
  CPlugMaterialCustom *pCVar1;
  byte bVar2;
  ulong uVar3;
  SCasterCat *pSVar4;
  CPlugTree *pCVar5;
  CPlugTree *extraout_EAX;
  int iVar6;
  CVisionVisualKeeper *pCVar7;
  int iVar8;
  CPlugTree *unaff_EBX;
  CFastArray<class_CCrystalEdge*> *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  ulong unaff_ESI;
  SPlugTreeOptimGroup *pSVar10;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  SPlugTreeOptimCriteria *in_stack_00000010;
  SPlugTreeOptimGroup *in_stack_00000014;
  int in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  CFastBuffer<class_CCrystalFace*> *pCVar11;
  SPlugTreeOptimGroup *pSVar12;
  SPlugTreeOptimCriteria *pSVar13;
  CPlugMaterial *pCVar14;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar15;
  CPlugShader *in_stack_ffffffac;
  CPlugTree *pCStack_4c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_48;
  undefined1 local_44 [4];
  int local_40;
  undefined1 local_3c [8];
  SPlugTreeOptimCriteria local_34 [40];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad50c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  local_40 = 0;
  GmIso4::SetIdentity(local_3c,(GmMat43 *)(DAT_00cca150 ^ (uint)&stack0xffffff9c));
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(&local_48,unaff_EDI);
  CFastBuffer<struct_CGameCampaignScores::SFilterInfos*>::InitSize
            (local_44,(CFastBuffer<struct_SMeshOctreeCell> *)&DAT_00000032,unaff_ESI);
  pSVar10 = in_stack_00000014;
  pSVar13 = local_34;
  pCVar11 = (CFastBuffer<class_CCrystalFace*> *)&local_40;
  pSVar12 = in_stack_00000014;
  (**(code **)(*(int *)this + 0xdc))();
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(&pCStack_4c,pCVar11);
  if (uVar3 == 1) {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (&local_48,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)pSVar10);
    pCVar5 = MakeGroupTree(this,*(CPlugTree **)pSVar4,pSVar12,pSVar13);
    *(CPlugTree **)in_stack_00000010 = pCVar5;
  }
  else {
    pCStack_4c = operator_new(0xac);
    if (pCStack_4c == (CPlugTree *)0x0) {
      pCVar5 = (CPlugTree *)0x0;
    }
    else {
      CPlugTree(pCStack_4c,(CPlugTree *)pSVar12);
      pCVar5 = extraout_EAX;
    }
    *(CPlugTree **)param_3 = pCVar5;
    SetIsRooted(pCVar5,(CPlugTree *)0x1,(int)pSVar13);
    in_stack_00000010 = param_3;
    if (local_48 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (&local_40,pCVar9,(ulong)unaff_EBP);
        pCVar5 = MakeGroupTree(this,*(CPlugTree **)pSVar4,pSVar10,
                               (SPlugTreeOptimCriteria *)unaff_EBX);
        unaff_EBP = (CFastArray<class_CCrystalEdge*> *)0x84dc84;
        unaff_EBX = pCVar5;
        (**(code **)(**(int **)param_3 + 0x88))();
        iVar8 = *(int *)param_3;
        if (((*(byte *)(iVar8 + 0x9c) & 0x80) == 0) && (((byte)pCVar5[0x9c] & 0x80) == 0)) {
          bVar2 = 0;
        }
        else {
          bVar2 = 1;
        }
        *(uint *)(iVar8 + 0x9c) =
             *(uint *)(iVar8 + 0x9c) ^ ((uint)bVar2 << 7 ^ *(uint *)(iVar8 + 0x9c)) & 0x80;
        iVar8 = *(int *)param_3;
        if (((*(byte *)(iVar8 + 0x9c) & 8) == 0) && (((byte)pCVar5[0x9c] & 8) == 0)) {
          bVar2 = 0;
        }
        else {
          bVar2 = 1;
        }
        *(uint *)(iVar8 + 0x9c) =
             *(uint *)(iVar8 + 0x9c) ^ ((uint)bVar2 * 8 ^ *(uint *)(iVar8 + 0x9c)) & 8;
        iVar8 = *(int *)param_3;
        if (((*(uint *)(iVar8 + 0x9c) & 0x4000) == 0) && ((*(uint *)(pCVar5 + 0x9c) & 0x4000) == 0))
        {
          bVar2 = 0;
        }
        else {
          bVar2 = 1;
        }
        *(uint *)(iVar8 + 0x9c) =
             *(uint *)(iVar8 + 0x9c) ^ ((uint)bVar2 << 0xe ^ *(uint *)(iVar8 + 0x9c)) & 0x4000;
        iVar8 = *(int *)param_3;
        if (((*(byte *)(iVar8 + 0x9c) & 0x10) == 0) && (((byte)pCVar5[0x9c] & 0x10) == 0)) {
          bVar2 = 0;
        }
        else {
          bVar2 = 1;
        }
        *(uint *)(iVar8 + 0x9c) =
             *(uint *)(iVar8 + 0x9c) ^ ((uint)bVar2 << 4 ^ *(uint *)(iVar8 + 0x9c)) & 0x10;
        iVar8 = *(int *)param_3;
        if (((*(byte *)(iVar8 + 0x9c) & 0x20) == 0) && (((byte)pCVar5[0x9c] & 0x20) == 0)) {
          bVar2 = 0;
        }
        else {
          bVar2 = 1;
        }
        *(uint *)(iVar8 + 0x9c) =
             *(uint *)(iVar8 + 0x9c) ^ ((uint)bVar2 << 5 ^ *(uint *)(iVar8 + 0x9c)) & 0x20;
        iVar8 = *(int *)param_3;
        if (((*(byte *)(iVar8 + 0x9c) & 0x40) == 0) && (((byte)pCVar5[0x9c] & 0x40) == 0)) {
          bVar2 = 0;
        }
        else {
          bVar2 = 1;
        }
        pCVar9 = pCVar9 + 1;
        *(uint *)(iVar8 + 0x9c) =
             *(uint *)(iVar8 + 0x9c) ^ ((uint)bVar2 << 6 ^ *(uint *)(iVar8 + 0x9c)) & 0x40;
        pSVar10 = in_stack_00000014;
      } while (pCVar9 < local_48);
    }
  }
  CFastBuffer<struct_SPlugTreeOptimGroup*>::DeleteAll(&local_40,unaff_EBP);
  if ((*(int *)(pSVar10 + 0xc) != 0) || (*(int *)(pSVar10 + 0x10) != 0)) {
    in_stack_00000014 = (SPlugTreeOptimGroup *)CSystemFile_testerror(unaff_EBX,in_stack_ffffffac);
joined_r0x0084de0c:
    if (in_stack_00000014 != (SPlugTreeOptimGroup *)0xffffffff) {
      pCVar5 = GetAllTreeNext(*(CPlugTree **)in_stack_00000010,(CPlugTree *)&stack0x00000014,
                              (ulong *)unaff_EBX);
      this_00 = *(CPlugVisual **)(pCVar5 + 0x90);
      if ((this_00 != (CPlugVisual *)0x0) && (*(int *)(pCVar5 + 0x1c) == 0)) {
        iVar8 = in_stack_0000001c;
        if (*(int *)(in_stack_0000001c + 0xc) != 0) {
          if (*(int *)(pCVar5 + 0x94) != 0) {
            unaff_EBX = (CPlugTree *)0x0;
            local_40 = *(int *)(pCVar5 + 0x94);
            CPlugVisual::UpdateVisualFromShaderRequirement
                      (this_00,(CPlugVisual *)&local_40,(CPlugShader **)0x0,in_stack_ffffffac);
            iVar8 = in_stack_00000020;
          }
          (**(code **)(*(int *)this_00 + 0xf8))
                    (*(undefined4 *)(iVar8 + 0x20),*(undefined4 *)(iVar8 + 0x24));
          iVar6 = (**(code **)(*(int *)this_00 + 0x10))(0x906a000);
          iVar8 = in_stack_00000018;
          if ((iVar6 != 0) &&
             (uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                                ((void *)(*(int *)(this_00 + 0x98) + 0x1c),
                                 (CFastBuffer<class_CCrystalFace*> *)unaff_EBX),
             iVar8 = in_stack_00000018, uVar3 == 0)) {
            *(uint *)(pCVar5 + 0x9c) = *(uint *)(pCVar5 + 0x9c) & 0xfffffff7;
            goto joined_r0x0084de0c;
          }
        }
        if ((*(int *)(iVar8 + 0x10) != 0) &&
           (pCVar7 = (CVisionVisualKeeper *)(**(code **)(*(int *)this_00 + 0x88))(),
           pCVar7 != (CVisionVisualKeeper *)0x0)) {
          pCVar1 = *(CPlugMaterialCustom **)(pCVar5 + 0x98);
          pCVar14 = (CPlugMaterial *)0x0;
          SetVisual(pCVar5,pCVar7,*(CPlugVisual **)(pCVar5 + 0x94));
          if (pCVar1 != (CPlugMaterialCustom *)0x0) {
            SetMaterial(pCVar5,pCVar1,pCVar14);
          }
        }
      }
      goto joined_r0x0084de0c;
    }
  }
  pCVar15 = (CFastBuffer<class_CPlugFileGPUV*> *)0x1;
  (**(code **)(**(int **)in_stack_00000010 + 0xbc))();
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(&local_40,pCVar15);
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: CPlugTree::GetAllChildNext
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CPlugTree * __thiscall CPlugTree::GetAllChildNext(CPlugTree *this,CPlugTree *param_1,ulong *param_2)
{
{
  int *piVar1;
  CPlugTree *pCVar2;
  int iVar3;
  uint uVar4;
  SNewTriangleVert *pSVar5;
  ulong uVar6;
  TiXmlAttribute *unaff_EBX;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *in_stack_ffffffe8;
  CFastBuffer<class_CCrystalFace*> *pCVar7;
  CPlugTree *pCStack_4;
  
  pCVar2 = DAT_00d6e680;
  DAT_00d6e680 = (CPlugTree *)0x0;
  pCStack_4 = this;
  iVar3 = (**(code **)(*(int *)pCVar2 + 0x7c))();
  if (iVar3 == 0) {
    for (piVar1 = *(int **)(pCVar2 + 0x24); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[9]) {
      pCVar7 = (CFastBuffer<class_CCrystalFace*> *)0x84a26d;
      uVar4 = (**(code **)(*piVar1 + 0x7c))();
      pSVar5 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem
                         (&DAT_00d6e674,in_stack_ffffffe8);
      if (*(int *)pSVar5 + 1U < uVar4) {
        *(int *)pSVar5 = *(int *)pSVar5 + 1;
        DAT_00d6e680 = (CPlugTree *)(**(code **)(*piVar1 + 0x80))(*(undefined4 *)pSVar5);
        break;
      }
      in_stack_ffffffe8 =
           (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)0x84a28c;
      uVar6 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d6e674,pCVar7);
      if (uVar6 < 2) break;
      _DAT_00d6e674 = _DAT_00d6e674 + -1;
    }
  }
  else {
    pCStack_4 = (CPlugTree *)0x0;
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (&DAT_00d6e674,(TiXmlAttributeSet *)&pCStack_4,unaff_EBX);
    DAT_00d6e680 = (CPlugTree *)(**(code **)(*(int *)pCVar2 + 0x80))(0);
  }
  if (DAT_00d6e680 != (CPlugTree *)0x0) {
    *(int *)param_1 = *(int *)param_1 + 1;
    return pCVar2;
  }
  _DAT_00d6e670 = 0;
  *(undefined4 *)param_1 = 0xffffffff;
  return pCVar2;
}
}

// =================================================
// Function: CPlugTree::GetAllChildStart
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall CPlugTree::GetAllChildStart(CPlugTree *this,CPlugTree *param_1)
{
{
  int iVar1;
  GmFrustumIso4 *unaff_ESI;
  CPlugTree *pCVar2;
  
  pCVar2 = this;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(&DAT_00d6e674,unaff_ESI);
  iVar1 = (**(code **)(*(int *)this + 0x7c))();
  if (iVar1 != 0) {
    _DAT_00d6e670 = 1;
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (&DAT_00d6e674,(TiXmlAttributeSet *)&stack0x00000000,(TiXmlAttribute *)pCVar2);
    DAT_00d6e680 = (**(code **)(*(int *)this + 0x80))(0);
    return 0;
  }
  _DAT_00d6e670 = 0;
  DAT_00d6e680 = 0;
  return 0xffffffff;
}
}

// =================================================
// Function: CPlugTree::GetAllTreeNext
// =================================================
CPlugTree * __thiscall CPlugTree::GetAllTreeNext(CPlugTree *this,CPlugTree *param_1,ulong *param_2)
{
{
  CPlugTree *pCVar1;
  ulong uVar2;
  CPlugTree *pCVar3;
  CPlugTree *unaff_EDI;
  
  pCVar1 = param_1;
  if (*(int *)param_1 != 0) {
    param_1 = (CPlugTree *)(*(int *)param_1 + -1);
    pCVar3 = GetAllChildNext(this,(CPlugTree *)&param_1,(ulong *)unaff_EDI);
    if (param_2 == (ulong *)0xffffffff) {
      *(undefined4 *)pCVar1 = 0xffffffff;
      return pCVar3;
    }
    *(int *)pCVar1 = (int)param_2 + 1;
    return pCVar3;
  }
  uVar2 = GetAllChildStart(this,unaff_EDI);
  if (uVar2 == 0xffffffff) {
    *(undefined4 *)pCVar1 = 0xffffffff;
    return this;
  }
  *(ulong *)pCVar1 = uVar2 + 1;
  return this;
}
}

// =================================================
// Function: CPlugTree::GetAllVisualNext
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CPlugVisual * __thiscall
CPlugTree::GetAllVisualNext(CPlugTree *this,CPlugTree *param_1,ulong *param_2)
{
{
  CPlugTree *pCVar1;
  int iVar2;
  CFastArray<class_GxTexCoordSet> *unaff_EBP;
  CPlugTree *unaff_ESI;
  TiXmlAttribute *unaff_EDI;
  CPlugVisual *unaff_retaddr;
  int *in_stack_0000000c;
  GxTexCoordSet *in_stack_fffffff4;
  undefined4 local_8;
  ulong local_4;
  
  local_8 = *(undefined4 *)((int)DAT_00d6e68c + 0x90);
  CFastBuffer<class_CDx9TextureKeeper*>::Add(&DAT_00d6e690,(TiXmlAttributeSet *)&local_8,unaff_EDI);
  DAT_00d6e68c = (CPlugTree *)0x0;
  if (DAT_00d6e688 == (CPlugTree *)0xffffffff) {
    local_4 = GetAllChildStart(this,unaff_ESI);
    do {
      do {
        pCVar1 = DAT_00d6e68c;
        if (local_4 == 0xffffffff) goto LAB_0084a417;
        pCVar1 = GetAllChildNext(this,(CPlugTree *)&local_4,(ulong *)unaff_EBP);
        param_2 = *(ulong **)(pCVar1 + 0x90);
      } while (param_2 == (ulong *)0x0);
      unaff_EBP = (CFastArray<class_GxTexCoordSet> *)&param_2;
      iVar2 = CFastArray<class_CGameMenuFrame*>::Find(&DAT_00d6e690,unaff_EBP,in_stack_fffffff4);
    } while (iVar2 != -1);
    DAT_00d6e688 = param_1;
  }
  else {
    do {
      pCVar1 = GetAllChildNext(this,(CPlugTree *)&DAT_00d6e688,(ulong *)unaff_EBP);
      param_2 = *(ulong **)(pCVar1 + 0x90);
      if (param_2 != (ulong *)0x0) {
        unaff_EBP = (CFastArray<class_GxTexCoordSet> *)&param_2;
        iVar2 = CFastArray<class_CGameMenuFrame*>::Find(&DAT_00d6e690,unaff_EBP,in_stack_fffffff4);
        if (iVar2 == -1) break;
      }
      pCVar1 = DAT_00d6e68c;
    } while (DAT_00d6e688 != (CPlugTree *)0xffffffff);
  }
LAB_0084a417:
  DAT_00d6e68c = pCVar1;
  if (DAT_00d6e68c == (CPlugTree *)0x0) {
    _DAT_00d6e684 = 0;
    *in_stack_0000000c = -1;
    return unaff_retaddr;
  }
  *in_stack_0000000c = *in_stack_0000000c + 1;
  return unaff_retaddr;
}
}

// =================================================
// Function: CPlugTree::GetAllVisualStart
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall CPlugTree::GetAllVisualStart(CPlugTree *this,CPlugTree *param_1)
{
{
  CPlugTree *pCVar1;
  GmFrustumIso4 *unaff_ESI;
  ulong *unaff_retaddr;
  CPlugTree *in_stack_00000008;
  CPlugTree *pCVar2;
  
  pCVar2 = this;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(&DAT_00d6e690,unaff_ESI);
  if (*(int *)(this + 0x90) != 0) {
    DAT_00d6e68c = this;
    _DAT_00d6e684 = 1;
    DAT_00d6e688 = (CPlugTree *)0xffffffff;
    return 0;
  }
  param_1 = (CPlugTree *)GetAllChildStart(this,pCVar2);
  pCVar2 = param_1;
  do {
    if (pCVar2 == (CPlugTree *)0xffffffff) {
      _DAT_00d6e684 = 0;
      return 0xffffffff;
    }
    pCVar1 = GetAllChildNext(this,(CPlugTree *)&param_1,unaff_retaddr);
    pCVar2 = in_stack_00000008;
  } while (*(int *)(pCVar1 + 0x90) == 0);
  DAT_00d6e68c = pCVar1;
  _DAT_00d6e684 = 1;
  DAT_00d6e688 = in_stack_00000008;
  return 0;
}
}

// =================================================
// Function: CPlugTree::GetChild
// =================================================
CPlugTree * __thiscall
CPlugTree::GetChild(CPlugTree *this,CPlugTreeVisualMip *param_1,ulong param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x28,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_retaddr);
  return *(CPlugTree **)pSVar1;
}
}

// =================================================
// Function: CPlugTree::GetChildCount
// =================================================
ulong __thiscall CPlugTree::GetChildCount(CPlugTree *this,CPlugTreeVisualMip *param_1)
{
{
  ulong uVar1;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this + 0x28,(CFastBuffer<class_CCrystalFace*> *)param_1);
  return uVar1;
}
}

// =================================================
// Function: CPlugTree::GetChildFromId
// =================================================
CPlugTree * __thiscall CPlugTree::GetChildFromId(CPlugTree *this,CPlugTree *param_1,CMwId *param_2)
{
{
  uint uVar1;
  CPlugTree *pCVar2;
  int *piVar3;
  uint uVar4;
  
  uVar1 = (**(code **)(*(int *)this + 0x7c))();
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      pCVar2 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))(uVar4);
      piVar3 = (int *)(**(code **)(*(int *)pCVar2 + 0x14))();
      if ((piVar3 != (int *)0x0) && (*piVar3 == *(int *)param_1)) {
        return pCVar2;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return (CPlugTree *)0x0;
}
}

// =================================================
// Function: CPlugTree::GetChildIndex
// =================================================
ulong __thiscall
CPlugTree::GetChildIndex(CPlugTree *this,CPlugTreeVisualMip *param_1,CPlugTree *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x28,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x28,pCVar3,unaff_ESI);
      if (param_2 == *(CPlugTree **)pSVar2) {
        return (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CPlugTree::GetChunkCount
// =================================================
ulong __thiscall CPlugTree::GetChunkCount(CPlugTree *this,CPlugSoundMood *param_1)
{
{
  return 0x1c;
}
}

// =================================================
// Function: CPlugTree::GetChunkInfo
// =================================================
ulong __thiscall CPlugTree::GetChunkInfo(CPlugTree *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 < (CFuncSegment *)0x904f00f) {
    if (param_1 != (CFuncSegment *)0x904f00e) {
      switch(param_1) {
      case (CFuncSegment *)0x904f000:
      case (CFuncSegment *)0x904f001:
      case (CFuncSegment *)0x904f002:
      case (CFuncSegment *)0x904f003:
      case (CFuncSegment *)0x904f004:
      case (CFuncSegment *)0x904f005:
      case (CFuncSegment *)0x904f007:
      case (CFuncSegment *)0x904f008:
      case (CFuncSegment *)0x904f009:
      case (CFuncSegment *)0x904f00a:
      case (CFuncSegment *)0x904f00b:
      case (CFuncSegment *)0x904f00c:
        break;
      case (CFuncSegment *)0x904f006:
      case (CFuncSegment *)0x904f00d:
switchD_008483c8_caseD_904f006:
        return 3;
      default:
        goto switchD_008483c8_default;
      }
    }
  }
  else {
    if ((CFuncSegment *)0x904f015 < param_1) {
      if (param_1 < (CFuncSegment *)0x904f01a) {
        if (param_1 == (CFuncSegment *)0x904f019) {
          return 1;
        }
        if (param_1 == (CFuncSegment *)0x904f016) {
          return (uint)(*(int *)(this + 0x1c) == 0) * 2 + 1;
        }
        if (param_1 == (CFuncSegment *)0x904f017) {
          return 5;
        }
        if (param_1 == (CFuncSegment *)0x904f018) {
          return 1;
        }
      }
      else {
        if (param_1 == (CFuncSegment *)0x904f01a) {
          return 3;
        }
        if (param_1 == (CFuncSegment *)0xffffffff) {
          return 0xffffffff;
        }
      }
switchD_008483c8_default:
      uVar1 = CMwNod::GetChunkInfo((CMwNod *)this,param_1,param_2);
      return uVar1;
    }
    if (param_1 != (CFuncSegment *)0x904f015) {
      switch(param_1) {
      case (CFuncSegment *)0x904f00f:
      case (CFuncSegment *)0x904f010:
      case (CFuncSegment *)0x904f012:
      case (CFuncSegment *)0x904f013:
      case (CFuncSegment *)0x904f014:
        break;
      case (CFuncSegment *)0x904f011:
        goto switchD_008483c8_caseD_904f006;
      default:
        goto switchD_008483c8_default;
      }
    }
  }
  return 1;
}
}

// =================================================
// Function: CPlugTree::GetDecorationBoundingBox
// =================================================
int __thiscall
CPlugTree::GetDecorationBoundingBox
          (CPlugTree *this,CPlugTreeLight *param_1,int param_2,GmBoxAligned *param_3)
{
{
  int *piVar1;
  void *this_00;
  CPlugSurfaceGeom *this_01;
  int iVar2;
  int this_02;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  GmRectAligned *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  SPlugFaceCull *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *unaff_EDI;
  int iVar6;
  undefined4 unaff_retaddr;
  void *in_stack_00000010;
  CPlugTree *pCVar7;
  CPlugTree *pCStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  CPlugTreeLight *local_14;
  int local_10;
  GmBoxAligned *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  this_02 = param_2;
  piVar1 = *(int **)(this + 0x90);
  iVar6 = 0;
  pCVar7 = this;
  if (piVar1 != (int *)0x0) {
    this_00 = *(void **)(this + 0xa4);
    if ((this_00 == (void *)0x0) || (piVar1[0x14] == 0)) {
      if (param_1 != (CPlugTreeLight *)0x0) {
        (**(code **)(*piVar1 + 0x118))(0xffffffff,0xffffffff);
      }
      iVar6 = *(int *)(this + 0x90);
      *(undefined4 *)param_2 = *(undefined4 *)(iVar6 + 0x34);
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(iVar6 + 0x38);
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar6 + 0x3c);
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(iVar6 + 0x40);
      *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(iVar6 + 0x44);
      local_18 = *(undefined4 *)(iVar6 + 0x48);
      pCStack_30 = this;
    }
    else {
      iVar6 = piVar1[0x14];
      pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar4 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
                   ::operator[](this_00,pCVar5,(ulong)unaff_EDI);
          unaff_EDI = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                                (in_stack_00000010,pCVar5,(ulong)pSVar4);
          GmBoxAligned::SetMult(&local_c,(SPlugFaceCull *)unaff_EDI,unaff_ESI,(GmIso4 *)unaff_EBX);
          if (pCVar5 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            local_20 = local_8;
            local_1c = local_4;
            local_14 = param_1;
            local_18 = unaff_retaddr;
            local_10 = iVar6;
            local_c = param_3 + 0x24;
          }
          else {
            unaff_EBX = (GmRectAligned *)&local_8;
            unaff_ESI = (SPlugFaceCull *)0x849e41;
            GmBoxAligned::Union(&local_20,unaff_EBX,(GmVec2 *)this);
          }
          pCVar5 = pCVar5 + 1;
        } while (pCVar5 < pCVar3);
      }
      *(undefined4 *)param_2 = uStack_2c;
      *(undefined4 *)(param_2 + 4) = uStack_28;
      *(undefined4 *)(param_2 + 8) = local_24;
      *(undefined4 *)(param_2 + 0xc) = local_20;
      *(undefined4 *)(param_2 + 0x10) = local_1c;
      param_2 = iVar6;
      pCVar7 = this;
    }
    *(undefined4 *)(this_02 + 0x14) = local_18;
    iVar6 = 1;
    this = pCStack_30;
  }
  if ((*(int *)(this + 0x8c) != 0) &&
     (this_01 = *(CPlugSurfaceGeom **)(*(int *)(this + 0x8c) + 0x14),
     this_01 != (CPlugSurfaceGeom *)0x0)) {
    if (param_2 != 0) {
      CPlugSurfaceGeom::ComputeBoundingBox
                (this_01,(CPlugVisualStrip *)unaff_ESI,(ulong)unaff_EBX,(ulong)pCVar7);
    }
    iVar2 = *(int *)(*(int *)(this + 0x8c) + 0x14);
    if (0.0 <= *(float *)(iVar2 + 0x28)) {
      if (iVar6 != 0) {
        GmBoxAligned::Union((void *)this_02,(GmRectAligned *)(iVar2 + 0x1c),(GmVec2 *)unaff_ESI);
        return 1;
      }
      *(undefined4 *)this_02 = *(undefined4 *)(iVar2 + 0x1c);
      *(undefined4 *)(this_02 + 4) = *(undefined4 *)(iVar2 + 0x20);
      *(undefined4 *)(this_02 + 8) = *(undefined4 *)(iVar2 + 0x24);
      *(undefined4 *)(this_02 + 0xc) = *(undefined4 *)(iVar2 + 0x28);
      *(undefined4 *)(this_02 + 0x10) = *(undefined4 *)(iVar2 + 0x2c);
      *(undefined4 *)(this_02 + 0x14) = *(undefined4 *)(iVar2 + 0x30);
      return 1;
    }
  }
  return iVar6;
}
}

// =================================================
// Function: CPlugTree::GetFirstParentOfClassId
// =================================================
CPlugTree * __thiscall
CPlugTree::GetFirstParentOfClassId(CPlugTree *this,CPlugTree *param_1,ulong param_2)
{
{
  CPlugTree *pCVar1;
  int iVar2;
  
  pCVar1 = *(CPlugTree **)(this + 0x24);
  while ((pCVar1 != (CPlugTree *)0x0 &&
         (iVar2 = (**(code **)(*(int *)pCVar1 + 0x10))(param_1), iVar2 == 0))) {
    pCVar1 = *(CPlugTree **)(pCVar1 + 0x24);
  }
  return pCVar1;
}
}

// =================================================
// Function: CPlugTree::GetIsRooted
// =================================================
int __thiscall CPlugTree::GetIsRooted(CPlugTree *this,CPlugTree *param_1)
{
{
  if ((*(int *)(this + 0x24) != 0) && ((*(uint *)(this + 0x9c) & 0x8000) == 0)) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CPlugTree::GetLastChild
// =================================================
CPlugTree * __thiscall CPlugTree::GetLastChild(CPlugTree *this,CPlugTree *param_1)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_retaddr;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x28,unaff_ESI);
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x28,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar1 - 1),
                      unaff_retaddr);
  return *(CPlugTree **)pSVar2;
}
}

// =================================================
// Function: CPlugTree::GetModelTree
// =================================================
CPlugTree * __thiscall CPlugTree::GetModelTree(CPlugTree *this,CPlugTree *param_1)
{
{
  CPlugTree *pCVar1;
  
  if (*(int **)(*(int *)(this + 0x1c) + 100) != (int *)0x0) {
    pCVar1 = (CPlugTree *)(**(code **)(**(int **)(*(int *)(this + 0x1c) + 100) + 0xb4))(this + 0x20)
    ;
    return pCVar1;
  }
  return (CPlugTree *)0x0;
}
}

// =================================================
// Function: CPlugTree::GetMwClassId
// =================================================
ulong __thiscall CPlugTree::GetMwClassId(CPlugTree *this,CControlStyle *param_1)
{
{
  return 0x904f000;
}
}

// =================================================
// Function: CPlugTree::GetOptimizedGroups
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugTree::GetOptimizedGroups
          (CPlugTree *this,CPlugCrystal *param_1,CFastBuffer<struct_SPlugTreeOptimGroup*> *param_2,
          SPlugTreeOptimCriteria *param_3,SPlugTreeOptimTravel *param_4,CPlugTree *param_5)
{
{
  CPlugTree CVar1;
  CFastBuffer<struct_SPlugTreeOptimGroup*> *pCVar2;
  ulong uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  CPlugTree *pCVar6;
  CPlugTree *this_00;
  SCasterCat *pSVar7;
  ulong uVar8;
  CPlugTreeVisualMip *pCVar9;
  CPlugTree *extraout_EAX;
  CPlugTreeVisualMip *extraout_EAX_00;
  SPlugTreeOptimCriteria *this_01;
  CPlugTreeVisualMip *extraout_EAX_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar11;
  int iVar12;
  code *pcVar13;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  TiXmlAttribute *unaff_EBP;
  TiXmlAttributeSet *unaff_ESI;
  SPlugFaceCull *pSVar14;
  TiXmlAttributeSet *pTVar15;
  undefined4 *puVar16;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar17;
  SPlugTreeOptimCriteria *unaff_EDI;
  undefined4 *puVar18;
  CPlugTree *pCVar19;
  void *unaff_retaddr;
  SPlugTreeOptimCriteria *in_stack_00000018;
  CFastBuffer<class_CCrystalFace*> *pCVar20;
  CPlugTree *in_stack_fffffee0;
  SPlugTreeOptimCriteria *in_stack_fffffee4;
  SPlugTreeOptimTravel *in_stack_fffffee8;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffeec;
  CFastBuffer<struct_SPlugTreeOptimGroup*> *in_stack_fffffef0;
  CPlugTree *in_stack_fffffef4;
  CPlugTree *in_stack_fffffef8;
  SPlugFaceCull *in_stack_ffffff00;
  CPlugTree *pCVar21;
  TiXmlAttribute *pTVar22;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar23;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffff1c;
  ulong in_stack_ffffff20;
  undefined4 *in_stack_ffffff24;
  CPlugTree *pCStack_d8;
  int iStack_d4;
  int iStack_d0;
  TiXmlAttributeSet *pTStack_cc;
  undefined4 uStack_c8;
  int *piStack_c4;
  undefined4 local_c0 [2];
  undefined1 auStack_b8 [8];
  undefined4 local_b0;
  undefined4 local_ac;
  CPlugTree *pCStack_a8;
  undefined4 uStack_a4;
  TiXmlAttributeSet aTStack_a0 [16];
  int *piStack_90;
  CPlugTree aCStack_8c [24];
  CPlugTree *pCStack_74;
  CPlugTree *pCStack_70;
  undefined4 auStack_6c [7];
  CPlugTreeVisualMip *pCStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [32];
  undefined4 uStack_28;
  CPlugTree *pCStack_24;
  CPlugTree *pCStack_1c;
  ulong uStack_18;
  ulong uStack_14;
  void *local_c;
  CFastBuffer<struct_SPlugTreeOptimGroup*> *pCStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pCStack_8 = (CFastBuffer<struct_SPlugTreeOptimGroup*> *)&LAB_00ad4fe0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_b0 = *(undefined4 *)param_3;
  CVar1 = this[0x9c];
  local_c0[0] = 0;
  pSVar14 = (SPlugFaceCull *)(param_3 + 4);
  puVar4 = &local_ac;
  for (iVar12 = 0xc; iVar12 != 0; iVar12 = iVar12 + -1) {
    *puVar4 = *(undefined4 *)pSVar14;
    pSVar14 = pSVar14 + 4;
    puVar4 = puVar4 + 1;
  }
  if (((byte)CVar1 & 4) != 0) {
    in_stack_ffffff00 = (SPlugFaceCull *)(this + 0x5c);
    local_b0 = 1;
    GmIso4::SetMult(&local_ac,in_stack_ffffff00,(SPlugFaceCull *)(param_3 + 4),
                    (GmIso4 *)(DAT_00cca150 ^ (uint)&stack0xffffff0c));
  }
  pCVar21 = (CPlugTree *)0x84c252;
  iVar12 = IsOptimizable(this,(CPlugTree *)param_3,unaff_EDI);
  if (iVar12 == 0) {
LAB_0084c29d:
    in_stack_ffffff24 = operator_new(0x48);
    if (in_stack_ffffff24 == (undefined4 *)0x0) {
      in_stack_ffffff24 = (undefined4 *)0x0;
    }
    else {
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (in_stack_ffffff24 + 0xf,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_ESI);
    }
    *in_stack_ffffff24 = 1;
    in_stack_ffffff24[1] = 1;
    in_stack_ffffff24[6] = *(undefined4 *)(this + 0x34);
    pCStack_74 = this;
    in_stack_ffffff24[7] = *(undefined4 *)(this + 0x38);
    in_stack_ffffff24[8] = *(undefined4 *)(this + 0x3c);
    in_stack_ffffff24[9] = *(undefined4 *)(this + 0x40);
    in_stack_ffffff24[10] = *(undefined4 *)(this + 0x44);
    in_stack_ffffff24[0xb] = *(undefined4 *)(this + 0x48);
    in_stack_ffffff24[2] = *(undefined4 *)(this + 0x98);
    in_stack_ffffff24[3] = *(undefined4 *)(this + 0x94);
    in_stack_ffffff24[4] = *(undefined4 *)(this + 0x8c);
    in_stack_ffffff24[5] = *(undefined4 *)(this + 0x9c);
    pCStack_70 = pCStack_a8;
    puVar4 = &uStack_a4;
    puVar16 = auStack_6c;
    for (iVar12 = 0xc; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar16 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar16 = puVar16 + 1;
    }
    param_3 = (SPlugTreeOptimCriteria *)0x84c342;
    CFastBuffer<struct_SPlugTreeOptimTransf>::Add
              (in_stack_ffffff24 + 0xf,(TiXmlAttributeSet *)&pCStack_74,(TiXmlAttribute *)unaff_ESI)
    ;
    unaff_ESI = (TiXmlAttributeSet *)&pCStack_d8;
    unaff_EDI = (SPlugTreeOptimCriteria *)0x84c355;
    CFastBuffer<class_CDx9TextureKeeper*>::Add(param_4,unaff_ESI,unaff_EBP);
    param_5 = (CPlugTree *)param_4;
  }
  else {
    if (*(int **)(this + 0x90) != (int *)0x0) {
      unaff_EDI = (SPlugTreeOptimCriteria *)0x0;
      param_3 = (SPlugTreeOptimCriteria *)0x84c26c;
      iVar12 = (**(code **)(**(int **)(this + 0x90) + 0xcc))();
      if (iVar12 == 0) goto LAB_0084c29d;
    }
    iVar12 = *(int *)(this + 0x90);
    if (iVar12 != 0) {
      unaff_EDI = (SPlugTreeOptimCriteria *)0x84c286;
      uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                        ((void *)(iVar12 + 100),(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
      if ((1 < uVar3) || ((iVar12 != 0 && (*(int *)(iVar12 + 0x50) != 0)))) goto LAB_0084c29d;
    }
  }
  if (*(int **)(this + 0xa0) == (int *)0x0) {
    if ((*(int *)(this + 0x94) != 0) || (*(int *)(this + 0x8c) != 0)) {
      pTVar22 = (TiXmlAttribute *)0x84c3ab;
      pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CFastBuffer<class_CCrystalFace*>::GetCount(param_5,unaff_EBX);
      pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar17 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        while( true ) {
          pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (param_5,pCVar10,(ulong)unaff_EDI);
          pCVar6 = *(CPlugTree **)pSVar7;
          unaff_EDI = (SPlugTreeOptimCriteria *)&pCStack_a8;
          in_stack_ffffff00 = (SPlugFaceCull *)0x84c3e6;
          pCVar21 = pCVar6;
          param_3 = (SPlugTreeOptimCriteria *)param_4;
          pCStack_d8 = (CPlugTree *)
                       IsEqual(this,pCVar6,(SPlugTreeOptimGroup *)param_4,unaff_EDI,
                               (SPlugTreeOptimTravel *)unaff_ESI);
          if (pCStack_d8 != (CPlugTree *)0x0) break;
          pCVar10 = pCVar10 + 1;
          if (pCVar17 <= pCVar10) {
            iStack_d4 = 0;
            goto LAB_0084c456;
          }
          pCStack_d8 = (CPlugTree *)0x0;
          param_5 = (CPlugTree *)param_4;
        }
        pCStack_70 = this;
        auStack_6c[0] = uStack_a4;
        puVar4 = auStack_6c;
        pTVar15 = aTStack_a0;
        for (iVar12 = 0xc; puVar4 = puVar4 + 1, iVar12 != 0; iVar12 = iVar12 + -1) {
          *puVar4 = *(undefined4 *)pTVar15;
          pTVar15 = pTVar15 + 4;
        }
        unaff_ESI = (TiXmlAttributeSet *)&pCStack_70;
        unaff_EDI = (SPlugTreeOptimCriteria *)0x84c425;
        CFastBuffer<struct_SPlugTreeOptimTransf>::Add(pCVar6 + 0x3c,unaff_ESI,pTVar22);
        if (*(int *)(pCVar6 + 0x10) == 0) {
          *(undefined4 *)(pCVar6 + 0x10) = *(undefined4 *)(this + 0x8c);
        }
        if (*(int *)(pCVar6 + 8) == 0) {
          *(undefined4 *)(pCVar6 + 8) = *(undefined4 *)(this + 0x98);
        }
        if (*(int *)(pCVar6 + 0xc) == 0) {
          *(undefined4 *)(pCVar6 + 0xc) = *(undefined4 *)(this + 0x94);
        }
LAB_0084c456:
        if (iStack_d4 != 0) goto LAB_0084c565;
      }
      puVar4 = operator_new(0x48);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                  (puVar4 + 0xf,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_ESI);
      }
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[6] = *(undefined4 *)(this + 0x34);
      puVar4[7] = *(undefined4 *)(this + 0x38);
      puVar4[8] = *(undefined4 *)(this + 0x3c);
      puVar4[9] = *(undefined4 *)(this + 0x40);
      puVar4[10] = *(undefined4 *)(this + 0x44);
      puVar4[0xb] = *(undefined4 *)(this + 0x48);
      puVar4[2] = *(undefined4 *)(this + 0x98);
      puVar4[3] = *(undefined4 *)(this + 0x94);
      puVar4[4] = *(undefined4 *)(this + 0x8c);
      puVar4[5] = *(undefined4 *)(this + 0x9c);
      in_stack_ffffff24 = puVar4;
      if (*(int **)(this + 0x90) == (int *)0x0) {
        uVar5 = 0;
      }
      else {
        uVar5 = (**(code **)(**(int **)(this + 0x90) + 0xcc))();
      }
      puVar4[0xc] = uVar5;
      if (*(int **)(this + 0x90) == (int *)0x0) {
        uVar5 = 0;
      }
      else {
        uVar5 = (**(code **)(**(int **)(this + 0x90) + 0xbc))();
      }
      puVar4[0xd] = uVar5;
      if (*(int **)(this + 0x90) == (int *)0x0) {
        uVar5 = 0;
      }
      else {
        uVar5 = (**(code **)(**(int **)(this + 0x90) + 0xb8))();
      }
      puVar4[0xe] = uVar5;
      pCStack_74 = this;
      pCStack_70 = pCStack_a8;
      puVar16 = &uStack_a4;
      puVar18 = auStack_6c;
      for (iVar12 = 0xc; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar18 = *puVar16;
        puVar16 = puVar16 + 1;
        puVar18 = puVar18 + 1;
      }
      param_3 = (SPlugTreeOptimCriteria *)0x84c554;
      CFastBuffer<struct_SPlugTreeOptimTransf>::Add
                (puVar4 + 0xf,(TiXmlAttributeSet *)&pCStack_74,(TiXmlAttribute *)unaff_ESI);
      unaff_ESI = (TiXmlAttributeSet *)&pCStack_d8;
      unaff_EDI = (SPlugTreeOptimCriteria *)0x84c565;
      CFastBuffer<class_CDx9TextureKeeper*>::Add(param_4,unaff_ESI,pTVar22);
    }
  }
  else {
    unaff_ESI = aTStack_a0;
    pCVar21 = (CPlugTree *)0x84c381;
    (**(code **)(**(int **)(this + 0xa0) + 0x84))();
    local_b0 = 1;
    param_3 = (SPlugTreeOptimCriteria *)param_5;
    unaff_EDI = in_stack_00000018;
  }
LAB_0084c565:
  iVar12 = (**(code **)(*(int *)this + 0x7c))();
  if (iVar12 != 0) {
    pCVar23 = (CFastBuffer<class_CPlugFileGPUV*> *)0x84c586;
    iStack_d0 = iVar12;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&uStack_c8,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_EBX);
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (auStack_b8,in_stack_ffffff1c);
    CFastBuffer<struct_CGameCampaignScores::SFilterInfos*>::InitSize
              (local_c0,(CFastBuffer<struct_SMeshOctreeCell> *)&DAT_0000000a,in_stack_ffffff20);
    CFastBuffer<struct_CGameCampaignScores::SFilterInfos*>::InitSize
              (&local_b0,(CFastBuffer<struct_SMeshOctreeCell> *)&DAT_0000000a,
               (ulong)in_stack_ffffff24);
    pCVar6 = (CPlugTree *)0x0;
    piStack_c4 = (int *)0x0;
    if (iVar12 != 0) {
      do {
        this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))();
        pCVar19 = in_stack_fffffee0;
        if ((pCVar23 == (CFastBuffer<class_CPlugFileGPUV*> *)0x0) ||
           (iVar12 = GetIsRooted(this_00,pCVar6), pCVar19 = in_stack_fffffee0, iVar12 != 0)) {
          pCVar20 = (CFastBuffer<class_CCrystalFace*> *)0x9015000;
          iVar12 = (**(code **)(*(int *)this_00 + 0x10))();
          if (iVar12 == 0) {
            pcVar13 = *(code **)(*(int *)this_00 + 0xdc);
            pCVar6 = pCStack_24;
            in_stack_fffffee0 = pCVar19;
          }
          else {
            uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00 + 0xac,pCVar20);
            pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00 + 0xac,
                                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar3 - 1),
                                (ulong)pCVar19);
            in_stack_fffffee0 = pCStack_1c;
            pCStack_d8 = *(CPlugTree **)pSVar7;
            if ((1 < uVar3) &&
               (pCVar19 = pCStack_1c,
               iVar12 = IsOptimizable(pCStack_d8,pCStack_1c,in_stack_fffffee4), iVar12 != 0)) {
              in_stack_fffffee4 = (SPlugTreeOptimCriteria *)&iStack_d0;
              pCVar6 = pCStack_1c;
              CPlugTreeVisualMip::GetMipOptimizedGroups
                        ((CPlugTreeVisualMip *)this_00,(CPlugTreeVisualMip *)0x1,(int)pCStack_1c,
                         (CFastBuffer<struct_SPlugTreeOptimGroup*> *)in_stack_fffffee0,
                         in_stack_fffffee4,in_stack_fffffee8);
              uVar8 = CFastBuffer<class_CCrystalFace*>::GetCount(&stack0xffffff0c,in_stack_fffffeec)
              ;
              if (uVar8 == 0) {
                pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (this_00 + 0xb4,
                                    (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar3 - 2),
                                    (ulong)in_stack_fffffef0);
                iStack_d0 = *(int *)(this_00 + 0x9c);
                unaff_ESI = *(TiXmlAttributeSet **)pSVar7;
              }
              else {
                pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (this_00 + 0xb4,
                                    (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar3 - 2),
                                    (ulong)in_stack_fffffef0);
                pTStack_cc = *(TiXmlAttributeSet **)pSVar7;
                if ((float)unaff_ESI < (float)pTStack_cc) {
                  unaff_ESI = pTStack_cc;
                }
              }
              CVar1 = this_00[0x9c];
              piStack_90 = piStack_c4;
              puVar4 = local_c0;
              pCVar19 = aCStack_8c;
              for (iVar12 = 0xc; iVar12 != 0; iVar12 = iVar12 + -1) {
                *(undefined4 *)pCVar19 = *puVar4;
                puVar4 = puVar4 + 1;
                pCVar19 = pCVar19 + 4;
              }
              if (((byte)CVar1 & 4) != 0) {
                piStack_90 = (int *)0x1;
                GmIso4::SetMult(aCStack_8c,(SPlugFaceCull *)(this_00 + 0x5c),
                                (SPlugFaceCull *)local_c0,(GmIso4 *)in_stack_fffffef4);
              }
              pCVar2 = pCStack_8;
              in_stack_fffffef4 = aCStack_8c;
              in_stack_fffffeec = (CFastBuffer<class_CCrystalFace*> *)&stack0xffffff18;
              in_stack_fffffee8 = (SPlugTreeOptimTravel *)0x84c70e;
              in_stack_fffffef0 = pCStack_8;
              (**(code **)(*piStack_c4 + 0xdc))();
              CPlugTreeVisualMip::GetMipOptimizedGroups
                        ((CPlugTreeVisualMip *)this_00,(CPlugTreeVisualMip *)0x0,
                         (int)&stack0xffffff08,pCVar2,(SPlugTreeOptimCriteria *)&stack0xffffff24,
                         (SPlugTreeOptimTravel *)pCVar6);
              goto LAB_0084c755;
            }
            pcVar13 = *(code **)(*(int *)this_00 + 0xdc);
            pCVar6 = in_stack_fffffee0;
            in_stack_fffffee0 = pCVar19;
          }
          (*pcVar13)(uStack_28,pCVar6,&stack0xffffff24);
        }
LAB_0084c755:
        pCVar6 = in_stack_fffffef4 + 1;
        in_stack_fffffef4 = pCVar6;
      } while (pCVar6 < in_stack_fffffef8);
    }
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (&stack0xffffff00,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffee0);
    if (uVar3 != 0) {
      pCVar9 = operator_new(0xd4);
      pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      uStack_28._0_1_ = 2;
      if (pCVar9 == (CPlugTreeVisualMip *)0x0) {
        in_stack_fffffef8 = (CPlugTree *)0x0;
        pCVar6 = (CPlugTree *)0x0;
        this_01 = unaff_EDI;
      }
      else {
        CPlugTreeVisualMip::CPlugTreeVisualMip(pCVar9,(CPlugTreeVisualMip *)in_stack_fffffee4);
        pCVar6 = extraout_EAX;
        this_01 = unaff_EDI;
      }
      uStack_28 = CONCAT31(uStack_28._1_3_,1);
      uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (&stack0xffffff10,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffee4);
      if (uVar3 == 1) {
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (&stack0xffffff14,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            uStack_18);
        pCVar9 = (CPlugTreeVisualMip *)
                 MakeGroupTree(this,*(CPlugTree **)pSVar7,(SPlugTreeOptimGroup *)in_stack_fffffee8,
                               (SPlugTreeOptimCriteria *)in_stack_fffffeec);
      }
      else {
        in_stack_ffffff00 = operator_new(0xac);
        pCStack_24._0_1_ = 3;
        if (in_stack_ffffff00 == (SPlugFaceCull *)0x0) {
          pCVar9 = (CPlugTreeVisualMip *)0x0;
        }
        else {
          CPlugTree((CPlugTree *)in_stack_ffffff00,(CPlugTree *)in_stack_fffffee8);
          pCVar9 = extraout_EAX_00;
        }
        pCStack_24 = (CPlugTree *)CONCAT31(pCStack_24._1_3_,1);
        uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                          (&stack0xffffff14,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffee8);
        if (uVar3 != 0) {
          do {
            pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (&stack0xffffff18,pCVar17,uStack_14);
            pCVar19 = *(CPlugTree **)pSVar7;
            in_stack_fffffef0 =
                 (CFastBuffer<struct_SPlugTreeOptimGroup*> *)
                 MakeGroupTree(this,pCVar19,(SPlugTreeOptimGroup *)in_stack_fffffeec,
                               (SPlugTreeOptimCriteria *)in_stack_fffffef0);
            in_stack_fffffeec = (CFastBuffer<class_CCrystalFace*> *)0x84c849;
            (**(code **)(*(int *)pCVar9 + 0x88))();
            pCVar17 = pCVar17 + 1;
            pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                      CFastBuffer<class_CCrystalFace*>::GetCount
                                (&stack0xffffff14,(CFastBuffer<class_CCrystalFace*> *)pCVar19);
          } while (pCVar17 < pCVar10);
        }
      }
      CPlugTreeVisualMip::AddLevel
                ((CPlugTreeVisualMip *)in_stack_ffffff00,pCVar9,(CPlugTree *)param_3,
                 (float)in_stack_fffffeec);
      uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (&stack0xffffff10,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffef0);
      if (uVar3 == 1) {
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (&stack0xffffff14,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            (ulong)local_c);
        pCVar9 = (CPlugTreeVisualMip *)
                 MakeGroupTree(this,*(CPlugTree **)pSVar7,(SPlugTreeOptimGroup *)in_stack_fffffef4,
                               (SPlugTreeOptimCriteria *)in_stack_fffffef8);
      }
      else {
        this_01 = operator_new(0xac);
        uStack_18._0_1_ = 4;
        if (this_01 == (SPlugTreeOptimCriteria *)0x0) {
          pCVar9 = (CPlugTreeVisualMip *)0x0;
        }
        else {
          CPlugTree((CPlugTree *)this_01,in_stack_fffffef4);
          pCVar9 = extraout_EAX_01;
        }
        uStack_18 = CONCAT31(uStack_18._1_3_,1);
        pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                          (&stack0xffffff14,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffef4);
        if (uVar3 != 0) {
          do {
            pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (&stack0xffffff18,pCVar17,(ulong)pCStack_8);
            pCVar19 = *(CPlugTree **)pSVar7;
            pCVar6 = MakeGroupTree(this,pCVar19,(SPlugTreeOptimGroup *)in_stack_fffffef8,
                                   (SPlugTreeOptimCriteria *)pCVar6);
            in_stack_fffffef8 = (CPlugTree *)0x84c909;
            (**(code **)(*(int *)pCVar9 + 0x88))();
            pCVar17 = pCVar17 + 1;
            pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                      CFastBuffer<class_CCrystalFace*>::GetCount
                                (&stack0xffffff14,(CFastBuffer<class_CCrystalFace*> *)pCVar19);
          } while (pCVar17 < pCVar10);
        }
      }
      unaff_EDI = this_01;
      CPlugTreeVisualMip::AddLevel
                ((CPlugTreeVisualMip *)this_01,pCVar9,_DAT_00bad5c4,(float)in_stack_fffffef8);
      *(uint *)(pCVar9 + 0x9c) = *(uint *)(pCVar9 + 0x9c) & 0xffffff7f;
      pCVar11 = operator_new(0x48);
      if (pCVar11 == (CFastBuffer<class_CPlugFileGPUV*> *)0x0) {
        pCVar11 = (CFastBuffer<class_CPlugFileGPUV*> *)0x0;
      }
      else {
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                  (pCVar11 + 0x3c,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar6);
      }
      *(undefined4 *)pCVar11 = 3;
      *(undefined4 *)(pCVar11 + 4) = 1;
      *(undefined4 *)(pCVar11 + 0x14) = uStack_c8;
      uStack_4c = 0;
      pCVar23 = pCVar11;
      pCStack_50 = (CPlugTreeVisualMip *)this_01;
      GmIso4::SetIdentity(auStack_48,(GmMat43 *)pCVar6);
      CFastBuffer<struct_SPlugTreeOptimTransf>::Add
                (pCVar11 + 0x3c,(TiXmlAttributeSet *)&uStack_4c,(TiXmlAttribute *)in_stack_ffffff00)
      ;
      CFastBuffer<class_CDx9TextureKeeper*>::Add
                (unaff_retaddr,(TiXmlAttributeSet *)&stack0xffffff1c,(TiXmlAttribute *)pCVar21);
    }
    CFastBuffer<struct_SPlugTreeOptimGroup*>::DeleteAll
              (&pCStack_d8,(CFastArray<class_CCrystalEdge*> *)param_3);
    CFastBuffer<struct_SPlugTreeOptimGroup*>::DeleteAll
              (&uStack_c8,(CFastArray<class_CCrystalEdge*> *)unaff_EDI);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (&piStack_c4,(CFastBuffer<class_CPlugFileGPUV*> *)unaff_ESI);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(&pTStack_cc,pCVar23);
  }
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CPlugTree::GetPlugFromId
// =================================================
CPlugTree * __thiscall CPlugTree::GetPlugFromId(CPlugTree *this,CPlugSolid *param_1,CMwId *param_2)
{
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  CPlugTree *pCVar4;
  CPlugTree *unaff_ESI;
  uint uVar5;
  
  iVar1 = GetIsRooted(this,unaff_ESI);
  if (iVar1 == 0) {
    return (CPlugTree *)0x0;
  }
  if ((*(int *)param_2 != *(int *)(this + 0x18)) &&
     ((*(int *)param_2 != -1 || (*(int *)(this + 0x24) != 0)))) {
    uVar2 = (**(code **)(*(int *)this + 0x7c))();
    uVar5 = 0;
    if (uVar2 != 0) {
      do {
        piVar3 = (int *)(**(code **)(*(int *)this + 0x80))(uVar5);
        pCVar4 = (CPlugTree *)(**(code **)(*piVar3 + 0xb4))(param_2);
        if (pCVar4 != (CPlugTree *)0x0) {
          return pCVar4;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar2);
    }
    return (CPlugTree *)0x0;
  }
  return this;
}
}

// =================================================
// Function: CPlugTree::GetPlugFromModelId
// =================================================
CPlugTree * __thiscall
CPlugTree::GetPlugFromModelId(CPlugTree *this,CPlugTree *param_1,CMwId *param_2)
{
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  CPlugTree *pCVar4;
  CPlugTree *unaff_ESI;
  uint uVar5;
  
  iVar1 = GetIsRooted(this,unaff_ESI);
  if (iVar1 == 0) {
    return (CPlugTree *)0x0;
  }
  if (*(int *)param_2 != *(int *)(this + 0x20)) {
    uVar2 = (**(code **)(*(int *)this + 0x7c))();
    uVar5 = 0;
    if (uVar2 != 0) {
      do {
        piVar3 = (int *)(**(code **)(*(int *)this + 0x80))(uVar5);
        pCVar4 = (CPlugTree *)(**(code **)(*piVar3 + 0xb8))(param_2);
        if (pCVar4 != (CPlugTree *)0x0) {
          return pCVar4;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar2);
    }
    return (CPlugTree *)0x0;
  }
  return this;
}
}

// =================================================
// Function: CPlugTree::GetRecursiveTreeCount
// =================================================
ulong __thiscall
CPlugTree::GetRecursiveTreeCount(CPlugTree *this,CPlugTree *param_1,int param_2,int param_3)
{
{
  int iVar1;
  uint uVar2;
  CPlugTree *this_00;
  ulong uVar3;
  ulong uVar4;
  uint uVar5;
  CPlugTree *unaff_EDI;
  uint uVar6;
  
  if ((param_2 != 0) && (iVar1 = GetIsRooted(this,unaff_EDI), iVar1 == 0)) {
    return 0;
  }
  if ((param_2 != 0) && (((byte)this[0x9c] & 8) == 0)) {
    return 0;
  }
  uVar4 = 1;
  uVar2 = (**(code **)(*(int *)this + 0x7c))();
  uVar5 = 0;
  if (uVar2 != 0) {
    do {
      uVar6 = uVar5;
      this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))();
      uVar3 = GetRecursiveTreeCount(this_00,param_1,param_2,uVar6);
      uVar5 = uVar5 + 1;
      uVar4 = uVar4 + uVar3;
    } while (uVar5 < uVar2);
  }
  return uVar4;
}
}

// =================================================
// Function: CPlugTree::GetRecursiveVertexCount
// =================================================
ulong __thiscall
CPlugTree::GetRecursiveVertexCount
          (CPlugTree *this,CPlugTreeVisualMip *param_1,int param_2,int param_3)
{
{
  CPlugTreeVisualMip *pCVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  pCVar1 = param_1;
  if ((param_1 != (CPlugTreeVisualMip *)0x0) && (((byte)this[0x9c] & 8) == 0)) {
    return 0;
  }
  if (*(int **)(this + 0x90) == (int *)0x0) {
    param_1 = (CPlugTreeVisualMip *)0x0;
  }
  else {
    param_1 = (CPlugTreeVisualMip *)(**(code **)(**(int **)(this + 0x90) + 0xb8))();
  }
  uVar2 = (**(code **)(*(int *)this + 0x7c))();
  if (uVar2 != 0) {
    uVar5 = 0;
    do {
      piVar3 = (int *)(**(code **)(*(int *)this + 0x80))(uVar5);
      if ((pCVar1 == (CPlugTreeVisualMip *)0x0) || ((*(byte *)(piVar3 + 0x27) & 8) != 0)) {
        iVar4 = (**(code **)(*piVar3 + 0xc0))(pCVar1,param_2);
        param_1 = param_1 + iVar4;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar2);
  }
  return (ulong)param_1;
}
}

// =================================================
// Function: CPlugTree::GetRootedChildCount
// =================================================
ulong __thiscall CPlugTree::GetRootedChildCount(CPlugTree *this,CPlugTree *param_1)
{
{
  uint uVar1;
  CPlugTree *this_00;
  int iVar2;
  ulong uVar3;
  CPlugTree *unaff_EDI;
  uint uVar4;
  
  uVar3 = 0;
  uVar1 = (**(code **)(*(int *)this + 0x7c))();
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))(uVar4);
      if (this_00 != (CPlugTree *)0x0) {
        iVar2 = GetIsRooted(this_00,unaff_EDI);
        if (iVar2 != 0) {
          uVar3 = uVar3 + 1;
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return uVar3;
}
}

// =================================================
// Function: CPlugTree::GetThisAndVolatileChildsBoundingBox
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugTree::GetThisAndVolatileChildsBoundingBox
          (CPlugTree *this,CPlugTree *param_1,GmBoxAligned *param_2)
{
{
  undefined4 uVar1;
  int iVar2;
  GmVec2 *pGVar3;
  CPlugTree *this_00;
  int extraout_ECX;
  GmVec2 *pGVar4;
  CPlugTree *pCVar5;
  GmVec2 *pGVar6;
  
  iVar2 = (**(code **)(*(int *)this + 0xcc))(0,param_1);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)param_1 = 0;
    uVar1 = _DAT_00b2c060;
    *(undefined4 *)(param_1 + 0xc) = _DAT_00b2c060;
    *(undefined4 *)(param_1 + 0x10) = uVar1;
    *(undefined4 *)(param_1 + 0x14) = uVar1;
  }
  pGVar3 = (GmVec2 *)(**(code **)(*(int *)this + 0x7c))();
  pGVar4 = (GmVec2 *)0x0;
  if (pGVar3 != (GmVec2 *)0x0) {
    do {
      pCVar5 = (CPlugTree *)0x849fa3;
      pGVar6 = pGVar4;
      this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))();
      iVar2 = GetIsRooted(this_00,pCVar5);
      if (iVar2 == 0) {
        GmBoxAligned::Union(param_1,(GmRectAligned *)(extraout_ECX + 0x34),pGVar6);
      }
      pGVar4 = pGVar4 + 1;
    } while (pGVar4 < pGVar3);
  }
  return;
}
}

// =================================================
// Function: CPlugTree::GetThisToRootTransfo
// =================================================
void __thiscall
CPlugTree::GetThisToRootTransfo
          (CPlugTree *this,CPlugTree *param_1,GmIso4 *param_2,int param_3,CPlugTree *param_4)
{
{
  int iVar1;
  GmIso4 *unaff_ESI;
  SPlugFaceCull *pSVar2;
  CPlugTree *pCVar3;
  GmMat43 *unaff_EDI;
  CPlugTree local_30 [4];
  SPlugFaceCull local_2c [44];
  
  pCVar3 = *(CPlugTree **)(this + 0x24);
  if ((pCVar3 != (CPlugTree *)0x0) && (pCVar3 != (CPlugTree *)param_3)) {
    GetThisToRootTransfo(pCVar3,local_30,(GmIso4 *)0x1,param_3,(CPlugTree *)unaff_EDI);
    if ((param_3 != 0) && (((byte)this[0x9c] & 4) != 0)) {
      GmIso4::SetMult(param_2,(SPlugFaceCull *)(this + 0x5c),local_2c,unaff_ESI);
      return;
    }
    pSVar2 = local_2c;
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)param_2 = *(undefined4 *)pSVar2;
      pSVar2 = pSVar2 + 4;
      param_2 = param_2 + 4;
    }
    return;
  }
  if ((param_2 != (GmIso4 *)0x0) && (((byte)this[0x9c] & 4) != 0)) {
    pCVar3 = this + 0x5c;
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)param_1 = *(undefined4 *)pCVar3;
      pCVar3 = pCVar3 + 4;
      param_1 = param_1 + 4;
    }
    return;
  }
  GmIso4::SetIdentity(param_1,unaff_EDI);
  return;
}
}

// =================================================
// Function: CPlugTree::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CPlugTree::GetUidChunkFromIndex(CPlugTree *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0x904f000;
}
}

// =================================================
// Function: CPlugTree::GetVolatileChildCount
// =================================================
ulong __thiscall CPlugTree::GetVolatileChildCount(CPlugTree *this,CPlugTree *param_1)
{
{
  CPlugTree *pCVar1;
  CPlugTree *this_00;
  int iVar2;
  ulong uVar3;
  CPlugTree *pCVar4;
  CPlugTree *pCVar5;
  
  uVar3 = 0;
  pCVar1 = (CPlugTree *)(**(code **)(*(int *)this + 0x7c))();
  pCVar4 = (CPlugTree *)0x0;
  if (pCVar1 != (CPlugTree *)0x0) {
    do {
      pCVar5 = pCVar4;
      this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))();
      iVar2 = GetIsRooted(this_00,pCVar5);
      if (iVar2 == 0) {
        uVar3 = uVar3 + 1;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return uVar3;
}
}

// =================================================
// Function: CPlugTree::GetVolatileTreePointer
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugTree::GetVolatileTreePointer
          (CPlugTree *this,CPlugTree *param_1,EVolatileTreeType param_2,
          SVolatileTreePointer *param_3)
{
{
  CPlugTree *this_00;
  int iVar1;
  undefined4 *puVar2;
  CPlugTree *this_01;
  CPlugTree *pCVar3;
  CPlugTree *unaff_EBP;
  CPlugTree *unaff_ESI;
  CPlugTree *pCVar4;
  
  *(undefined4 *)param_2 = 0;
  iVar1 = GetIsRooted(this,unaff_ESI);
  this_00 = this;
  while (iVar1 == 0) {
    this_00 = *(CPlugTree **)(this_00 + 0x24);
    iVar1 = GetIsRooted(this_00,unaff_EBP);
  }
  *(undefined4 *)param_2 = *(undefined4 *)(this + 0x14);
  puVar2 = (undefined4 *)(**(code **)(*(int *)this_00 + 0x14))();
  *(undefined4 *)(param_2 + 4) = *puVar2;
  *(EVolatileTreeType *)(param_2 + 8) = param_2;
  if (param_2 == 0) {
    _DAT_0000000c = 0xffffffff;
  }
  else if (param_2 == 1) {
    iVar1 = HasPlugCrystal(this_00,unaff_EBP);
    if (iVar1 == 0) {
      _DAT_0000000d = (undefined3)*(undefined4 *)(this + 0x18);
      uRam00000010 = (undefined1)((uint)*(undefined4 *)(this + 0x18) >> 0x18);
      return;
    }
    pCVar4 = (CPlugTree *)0x0;
    iVar1 = (**(code **)(*(int *)this_00 + 0x7c))();
    if (iVar1 != 0) {
      do {
        pCVar3 = pCVar4;
        this_01 = (CPlugTree *)(**(code **)(*(int *)this_00 + 0x80))();
        iVar1 = GetIsRooted(this_01,pCVar3);
        if (iVar1 == 0) break;
        pCVar4 = pCVar4 + 1;
        pCVar3 = (CPlugTree *)(**(code **)(*(int *)this_00 + 0x7c))();
      } while (pCVar4 < pCVar3);
    }
    _DAT_0000000d = (undefined3)*(undefined4 *)(this + 0x18);
    uRam00000010 = (undefined1)((uint)*(undefined4 *)(this + 0x18) >> 0x18);
    return;
  }
  return;
}
}

// =================================================
// Function: CPlugTree::HasPlugCrystal
// =================================================
int __thiscall CPlugTree::HasPlugCrystal(CPlugTree *this,CPlugTree *param_1)
{
{
  int iVar1;
  
  if (*(int **)(this + 0xa0) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(this + 0xa0) + 0x10))(0x9003000);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CPlugTree::HideInvalidTrees
// =================================================
int __thiscall CPlugTree::HideInvalidTrees(CPlugTree *this,CPlugTree *param_1)
{
{
  CPlugTree *pCVar1;
  CPlugTree *this_00;
  int iVar2;
  int iVar3;
  CPlugTree *unaff_EDI;
  CPlugTree *pCVar4;
  CPlugTree *pCVar5;
  
  if (((byte)this[0x9c] & 8) != 0) {
    iVar3 = 0;
    pCVar1 = (CPlugTree *)(**(code **)(*(int *)this + 0x7c))();
    pCVar4 = (CPlugTree *)0x0;
    if (pCVar1 != (CPlugTree *)0x0) {
      do {
        pCVar5 = pCVar4;
        this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))();
        iVar2 = HideInvalidTrees(this_00,pCVar5);
        if (iVar2 != 0) {
          iVar3 = 1;
        }
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar1);
    }
    if (*(int *)(this + 0x90) != 0) {
      iVar3 = IsVisualValid(this,unaff_EDI);
    }
    if (iVar3 == 0) {
      *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) & 0xfffffff7;
    }
    return *(uint *)(this + 0x9c) >> 3 & 1;
  }
  return 0;
}
}

// =================================================
// Function: CPlugTree::InternalCopyVolatileChilds
// =================================================
void __thiscall
CPlugTree::InternalCopyVolatileChilds(CPlugTree *this,CPlugTree *param_1,CPlugTree *param_2)
{
{
  (**(code **)(*(int *)param_1 + 200))(InternalCreateSolidModelInstanceThis,0,this);
  return;
}
}

// =================================================
// Function: CPlugTree::InternalCreateSolidModelInstance
// =================================================
CPlugTree * __thiscall
CPlugTree::InternalCreateSolidModelInstance(CPlugTree *this,CPlugTree *param_1)
{
{
  CPlugTree *pCVar1;
  
  pCVar1 = (CPlugTree *)(**(code **)(*(int *)this + 200))(InternalCreateSolidModelInstanceThis,1,0);
  return pCVar1;
}
}

// =================================================
// Function: CPlugTree::InternalCreateSolidModelInstanceThis
// =================================================
CPlugTree * __thiscall
CPlugTree::InternalCreateSolidModelInstanceThis(CPlugTree *this,CPlugTree *param_1)
{
{
  uint uVar1;
  int iVar2;
  CPlugTree *this_00;
  CPlugTree *pCVar3;
  CPlugTree *pCVar4;
  CSystemFidParameters *pCVar5;
  CSystemFidParameters *unaff_ESI;
  CSystemFidParameters *unaff_EDI;
  void *unaff_retaddr;
  undefined4 uStack00000008;
  undefined1 uStack0000000c;
  CPlugTree *pCVar6;
  CSystemFidParameters *pCVar7;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffffb8;
  undefined1 auStack_44 [8];
  undefined1 auStack_3c [4];
  CSystemFidParameters aCStack_38 [4];
  CSystemFidParameters aCStack_34 [8];
  CSystemFidParameters aCStack_2c [32];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4d60;
  local_c = ExceptionList;
  uVar1 = DAT_00cca150 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_c;
  iVar2 = (**(code **)(*(int *)this + 8))();
  this_00 = (CPlugTree *)(**(code **)(iVar2 + 0x1c))();
  pCVar6 = (CPlugTree *)0x1;
  pCVar4 = this;
  (**(code **)(*(int *)this_00 + 0xb0))();
  pCVar3 = (CPlugTree *)(**(code **)(*(int *)this + 0x14))();
  InternalSetMwId(this_00,pCVar3,(CMwId *)pCVar4);
  pCVar4 = (CPlugTree *)GetIsRooted(this,pCVar6);
  SetIsRooted(this_00,pCVar4,uVar1);
  CSystemFidParameters::CSystemFidParameters(aCStack_38,unaff_EDI,unaff_ESI);
  uStack00000008 = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (auStack_3c,in_stack_ffffffb8);
  iVar2 = *(int *)this_00;
  pCVar7 = aCStack_2c;
  uStack0000000c = 1;
  pCVar5 = CSystemFidParameters::GetCurrentParameters();
  (**(code **)(iVar2 + 0x54))();
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (auStack_44,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar5);
  CSystemFidParameters::~CSystemFidParameters(aCStack_34,pCVar7);
  ExceptionList = unaff_retaddr;
  return this_00;
}
}

// =================================================
// Function: CPlugTree::InternalGetChildFromPointer
// =================================================
CPlugTree * __thiscall
CPlugTree::InternalGetChildFromPointer
          (CPlugTree *this,CPlugTree *param_1,SVolatileTreePointer *param_2)
{
{
  int iVar1;
  CPlugTree *pCVar2;
  CMwId *unaff_EBP;
  CPlugTree *unaff_ESI;
  CPlugTree *pCVar3;
  CPlugTree *pCVar4;
  
  if (*(int *)(param_1 + 8) != 0) {
    if (*(int *)(param_1 + 8) != 1) {
      return (CPlugTree *)0x0;
    }
    iVar1 = HasPlugCrystal(this,unaff_ESI);
    if (iVar1 != 0) {
      pCVar3 = (CPlugTree *)0x0;
      iVar1 = (**(code **)(*(int *)this + 0x7c))();
      if (iVar1 != 0) {
        do {
          pCVar2 = pCVar3;
          param_2 = (SVolatileTreePointer *)(**(code **)(*(int *)this + 0x80))();
          iVar1 = GetIsRooted((CPlugTree *)param_2,pCVar2);
          if (iVar1 == 0) break;
          pCVar3 = pCVar3 + 1;
          pCVar2 = (CPlugTree *)(**(code **)(*(int *)this + 0x7c))();
        } while (pCVar3 < pCVar2);
      }
      pCVar2 = param_1 + 0xc;
      pCVar4 = (CPlugTree *)0x1;
      pCVar3 = (CPlugTree *)(**(code **)(*(int *)param_2 + 0x80))();
      pCVar3 = GetChildFromId(pCVar3,pCVar4,(CMwId *)pCVar2);
      return pCVar3;
    }
    if (*(int *)(this + 0x18) != *(int *)(param_1 + 0xc)) {
      pCVar3 = GetChildFromId(this,param_1 + 0xc,unaff_EBP);
      return pCVar3;
    }
  }
  return this;
}
}

// =================================================
// Function: CPlugTree::InternalLoadSetSurface
// =================================================
void __thiscall
CPlugTree::InternalLoadSetSurface(CPlugTree *this,CPlugTree *param_1,CMwNod *param_2)
{
{
  void *this_00;
  CMwNod *this_01;
  CPlugTree *pCVar1;
  CPlugSurface *pCVar2;
  int iVar3;
  CPlugSurface *this_02;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *extraout_EAX;
  SCasterCat *pSVar4;
  ulong uVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SLoadedLight *pSVar7;
  CMwNod *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000010;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffffb4;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffb8;
  CFastArray<class_GxTexCoordSet> *pCVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  CPlugTree *local_28;
  undefined1 auStack_24 [4];
  TiXmlAttributeSet aTStack_20 [4];
  CPlugTree *local_1c;
  undefined1 auStack_18 [4];
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad50f3;
  local_c = ExceptionList;
  pCVar2 = (CPlugSurface *)(DAT_00cca150 ^ (uint)&stack0xffffffc8);
  ExceptionList = &local_c;
  local_28 = (CPlugTree *)0x0;
  pCVar1 = local_28;
  local_1c = this;
  if (param_1 != (CPlugTree *)0x0) {
    iVar3 = (**(code **)(*(int *)param_1 + 0x10))(0x900c000);
    if (iVar3 == 0) {
      pCVar1 = *(CPlugTree **)(param_1 + 0x38);
      if (*(CPlugTree **)(param_1 + 0x38) == (CPlugTree *)0x0) {
        pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x24;
        pCVar10 = (CFastArray<class_GxTexCoordSet> *)0x84dfc0;
        this_02 = operator_new(0x24);
        uStack_4 = 0;
        if (this_02 == (CPlugSurface *)0x0) {
          pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        }
        else {
          pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x84dfd6;
          CPlugSurface::CPlugSurface(this_02,pCVar2);
          pCVar9 = extraout_EAX;
        }
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(param_1 + 0x38) = pCVar9;
        pCVar12 = pCVar9;
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                  (&local_28,in_stack_ffffffb4);
        iVar3 = *(int *)(param_1 + 0x34);
        uStack_10 = 1;
        if (*(char *)(iVar3 + 6) == '\a') {
          this_00 = (void *)(iVar3 + 0x10);
          local_28 = (CPlugTree *)
                     CFastBuffer<class_CCrystalFace*>::GetCount(this_00,in_stack_ffffffb8);
          pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          if (local_28 != (CPlugTree *)0x0) {
            do {
              pSVar4 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                                 (this_00,pCVar8,(ulong)pCVar10);
              local_28 = (CPlugTree *)(uint)(byte)pSVar4[0x1c];
              pCVar10 = (CFastArray<class_GxTexCoordSet> *)&local_28;
              uVar5 = CFastArray<class_CGameMenuFrame*>::Find
                                (&local_1c,pCVar10,(GxTexCoordSet *)pCVar11);
              if (uVar5 == 0xffffffff) {
                uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount
                                  (auStack_18,(CFastBuffer<class_CCrystalFace*> *)pCVar2);
                pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x84e05e;
                CFastBuffer<class_CDx9TextureKeeper*>::Add
                          (&pCStack_14,aTStack_20,(TiXmlAttribute *)pCVar12);
              }
              pCVar2 = (CPlugSurface *)0x84e066;
              pCVar12 = pCVar8;
              pSVar4 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                                 (this_00,pCVar8,unaff_ESI);
              pCVar8 = pCVar8 + 1;
              *(short *)(pSVar4 + 0x1c) = (short)uVar5;
              pCVar9 = in_stack_00000010;
            } while (pCVar8 < pCStack_14);
          }
        }
        else {
          puStack_8 = (undefined1 *)(uint)*(byte *)(iVar3 + 4);
          CFastBuffer<class_CDx9TextureKeeper*>::Add
                    (auStack_24,(TiXmlAttributeSet *)&puStack_8,(TiXmlAttribute *)in_stack_ffffffb8)
          ;
          *(undefined2 *)(iVar3 + 4) = 0;
        }
        pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (param_1 != *(CPlugTree **)(pCVar9 + 0x14)) {
          CMwNod::MwAddRef((CMwNod *)param_1,(CMwNod *)pCVar10);
          if (*(CMwNod **)(pCVar9 + 0x14) != (CMwNod *)0x0) {
            pCVar10 = (CFastArray<class_GxTexCoordSet> *)0x84e091;
            CMwNod::MwRelease(*(CMwNod **)(pCVar9 + 0x14),(CMwNod *)0x84e091);
          }
          *(CPlugTree **)(pCVar9 + 0x14) = param_1;
        }
        pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           (aTStack_20,(CFastBuffer<class_CCrystalFace*> *)pCVar10);
        if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (&local_1c,pCVar8,(ulong)pCVar11);
            pCVar11 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar4;
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (&DAT_00d6efb8,pCVar11,(ulong)pCVar2);
            this_01 = *(CMwNod **)pSVar4;
            pCVar2 = (CPlugSurface *)0x84e0d0;
            pSVar7 = CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>::AddNewElem
                               (pCVar9 + 0x18,
                                (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar12);
            if (this_01 != *(CMwNod **)pSVar7) {
              if (this_01 != (CMwNod *)0x0) {
                pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x84e0e1;
                CMwNod::MwAddRef(this_01,(CMwNod *)pCVar11);
              }
              if (*(CMwNod **)pSVar7 != (CMwNod *)0x0) {
                CMwNod::MwRelease(*(CMwNod **)pSVar7,unaff_EBP);
              }
              *(CMwNod **)pSVar7 = this_01;
            }
            pCVar8 = pCVar8 + 1;
          } while (pCVar8 < pCVar6);
        }
        puStack_8 = (undefined1 *)0xffffffff;
        CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                  (&local_1c,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar11);
        pCVar1 = local_28;
      }
    }
    else {
      local_28 = param_1;
      pCVar1 = local_28;
    }
  }
  local_28 = pCVar1;
  SetSurface(local_1c,local_28,pCVar2);
  ExceptionList = puStack_8;
  return;
}
}

// =================================================
// Function: CPlugTree::InternalRecursiveCreate
// =================================================
CPlugTree * __thiscall
CPlugTree::InternalRecursiveCreate
          (CPlugTree *this,CPlugTreeVisualMip *param_1,_func___cdecl_CPlugTree_ptr *param_2,
          int param_3,CPlugTree *param_4)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  undefined4 uVar4;
  ulong unaff_EBX;
  CPlugTree *this_00;
  CPlugTree *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  ulong in_stack_00000014;
  CPlugTree *in_stack_00000018;
  
  if (param_3 == 0) {
    param_3 = (*(code *)param_1)();
  }
  this_00 = this + 0x28;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar5,unaff_ESI);
      unaff_ESI = 0x8498df;
      iVar3 = GetIsRooted(*(CPlugTree **)pSVar2,unaff_EBP);
      if (in_stack_00000014 == 0) {
        if (iVar3 == 0) goto LAB_008498f0;
      }
      else if (iVar3 != 0) {
LAB_008498f0:
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar5,unaff_EBX)
        ;
        iVar3 = *(int *)param_3;
        unaff_EBX = 0;
        unaff_ESI = in_stack_00000014;
        unaff_EBP = in_stack_00000018;
        uVar4 = (**(code **)(**(int **)pSVar2 + 200))();
        (**(code **)(iVar3 + 0x88))(uVar4);
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar1);
  }
  return (CPlugTree *)param_3;
}
}

// =================================================
// Function: CPlugTree::InternalSetMwId
// =================================================
void __thiscall CPlugTree::InternalSetMwId(CPlugTree *this,CPlugTree *param_1,CMwId *param_2)
{
{
  *(undefined4 *)(this + 0x18) = *(undefined4 *)param_1;
  return;
}
}

// =================================================
// Function: CPlugTree::IsEqual
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CPlugTree::IsEqual(CPlugTree *this,CPlugTree *param_1,SPlugTreeOptimGroup *param_2,
                  SPlugTreeOptimCriteria *param_3,SPlugTreeOptimTravel *param_4)
{
{
  float fVar1;
  uint uVar2;
  uint uVar3;
  CSystemArchiveNod *this_00;
  SParam *pSVar4;
  float fVar5;
  CPlugTree *pCVar6;
  ulong uVar7;
  SCasterCat *pSVar8;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  ulong unaff_EBP;
  int iVar9;
  int *unaff_ESI;
  GmVec2 *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  undefined4 in_stack_00000014;
  int in_stack_00000018;
  int in_stack_00000020;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffdc;
  float fStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  pCVar6 = param_1;
  if (*(int *)(param_1 + 4) != 0) {
    return 0;
  }
  if (((byte)*param_2 & 8) != 0) {
    uVar2 = *(uint *)(param_1 + 0x14);
    uVar3 = *(uint *)(this + 0x9c);
    if (((uVar2 ^ uVar3) & 0x8000) != 0) {
      return 0;
    }
    if (((uVar2 ^ uVar3) & 8) != 0) {
      return 0;
    }
    if (((uVar2 ^ uVar3) & 0x10) != 0) {
      return 0;
    }
    if (((uVar2 ^ uVar3) & 0x20) != 0) {
      return 0;
    }
    if (((uVar2 ^ uVar3) & 0x4000) != 0) {
      return 0;
    }
  }
  param_1 = (CPlugTree *)0x0;
  if (((*(int **)(this + 0x90) != (int *)0x0) &&
      (param_1 = (CPlugTree *)(**(code **)(**(int **)(this + 0x90) + 0xb8))(),
      ((byte)*param_2 & 2) != 0)) &&
     (*(CPlugTree **)(param_2 + 0x1c) < param_1 + *(int *)(pCVar6 + 0x38))) {
    return 0;
  }
  iVar9 = 0;
  uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar6 + 0x3c,unaff_EBX);
  pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (uVar7 != 0) {
    do {
      pSVar8 = CFastBuffer<struct_SChildGen>::operator[](pCVar6 + 0x3c,pCVar10,unaff_EBP);
      if ((*(int *)pSVar8 != 0) && (iVar9 = *(int *)(*(int *)pSVar8 + 0x90), iVar9 != 0)) break;
      pCVar10 = pCVar10 + 1;
    } while (pCVar10 < in_stack_ffffffdc);
  }
  if ((*(int *)(in_stack_ffffffdc + 0x90) != 0) && (iVar9 != 0)) {
    uVar2 = *(uint *)(*(int *)(in_stack_ffffffdc + 0x90) + 0x1c);
    if (((*(uint *)(iVar9 + 0x1c) ^ uVar2) & 0x100) != 0) {
      return 0;
    }
    if ((char)((byte)*(uint *)(iVar9 + 0x1c) ^ (byte)uVar2) < '\0') {
      return 0;
    }
  }
  fStack_14 = *(float *)(pCVar6 + 0x18);
  uStack_10 = *(undefined4 *)(pCVar6 + 0x1c);
  uStack_c = *(undefined4 *)(pCVar6 + 0x20);
  uStack_8 = *(undefined4 *)(pCVar6 + 0x24);
  fStack_4 = *(float *)(pCVar6 + 0x28);
  fVar1 = *(float *)(pCVar6 + 0x2c);
  GmBoxAligned::Union(&fStack_14,(GmRectAligned *)(in_stack_ffffffdc + 0x34),unaff_EDI);
  if (((byte)*param_4 & 1) != 0) {
    fVar5 = (float)_DAT_00b33a58;
    fStack_14 = fVar5 * (float)param_1;
    if (*(float *)(param_4 + 0x18) < fStack_4 * fVar5) {
      return 0;
    }
    if (*(float *)(param_4 + 0x18) < fVar1 * fVar5) {
      return 0;
    }
    if (*(float *)(param_4 + 0x18) < fStack_14) {
      return 0;
    }
  }
  if (((*(int *)(pCVar6 + 0x10) == 0) || (*(int *)(in_stack_ffffffdc + 0x8c) == 0)) &&
     (*(int *)(pCVar6 + 8) == *(int *)(in_stack_ffffffdc + 0x98))) {
    this_00 = *(CSystemArchiveNod **)(pCVar6 + 0xc);
    if (((this_00 != (CSystemArchiveNod *)0x0) &&
        (pSVar4 = *(SParam **)(in_stack_ffffffdc + 0x94), pSVar4 != (SParam *)0x0)) &&
       (this_00 != (CSystemArchiveNod *)pSVar4)) {
      param_4 = (SPlugTreeOptimTravel *)0x0;
      CSystemArchiveNod::Compare(this_00,(SParam_Fids *)this_00,pSVar4,(int *)&param_4,unaff_ESI);
      if (in_stack_00000020 == 0) {
        return 0;
      }
    }
    *(float *)(pCVar6 + 0x18) = fVar1;
    *(CPlugTree **)(pCVar6 + 0x1c) = param_1;
    *(SPlugTreeOptimGroup **)(pCVar6 + 0x20) = param_2;
    *(SPlugTreeOptimCriteria **)(pCVar6 + 0x24) = param_3;
    *(SPlugTreeOptimTravel **)(pCVar6 + 0x28) = param_4;
    *(undefined4 *)(pCVar6 + 0x2c) = in_stack_00000014;
    if (*(int **)(in_stack_ffffffdc + 0x90) != (int *)0x0) {
      iVar9 = (**(code **)(**(int **)(in_stack_ffffffdc + 0x90) + 0xcc))(0);
      *(int *)(pCVar6 + 0x30) = *(int *)(pCVar6 + 0x30) + iVar9;
      iVar9 = (**(code **)(**(int **)(in_stack_ffffffdc + 0x90) + 0xbc))();
      *(int *)(pCVar6 + 0x34) = *(int *)(pCVar6 + 0x34) + iVar9;
      *(int *)(pCVar6 + 0x38) = *(int *)(pCVar6 + 0x38) + in_stack_00000018;
    }
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CPlugTree::IsOptimizable
// =================================================
int __thiscall
CPlugTree::IsOptimizable(CPlugTree *this,CPlugTree *param_1,SPlugTreeOptimCriteria *param_2)
{
{
  uint uVar1;
  
  if (*(int *)(this + 0x1c) == 0) {
    return 1;
  }
  if (*(int **)(this + 0x90) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(this + 0x90) + 0xb8))();
    return (uint)(uVar1 <= *(uint *)(param_1 + 0x38));
  }
  return 1;
}
}

// =================================================
// Function: CPlugTree::IsVisualValid
// =================================================
int __thiscall CPlugTree::IsVisualValid(CPlugTree *this,CPlugTree *param_1)
{
{
  int iVar1;
  
  if (*(int **)(this + 0x90) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(this + 0x90) + 0xb8))();
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CPlugTree::MakeGroupTree
// =================================================
CPlugTree * __thiscall
CPlugTree::MakeGroupTree
          (CPlugTree *this,CPlugTree *param_1,SPlugTreeOptimGroup *param_2,
          SPlugTreeOptimCriteria *param_3)
{
{
  CPlugTree *pCVar1;
  CPlugTree *extraout_EAX;
  CPlugSurface *pCVar2;
  CPlugVisual *pCVar3;
  SCasterCat *pSVar4;
  uint uVar5;
  int iVar6;
  CPlugTree *pCVar7;
  SPlugTreeOptimGroup *unaff_ESI;
  CPlugSurface *unaff_EDI;
  CPlugMaterial *pCVar8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4f7b;
  local_c = ExceptionList;
  pCVar1 = (CPlugTree *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  pCVar7 = (CPlugTree *)0x0;
  switch(*(undefined4 *)param_1) {
  case 0:
    pCVar7 = operator_new(0xac);
    local_4 = 0;
    if (pCVar7 == (CPlugTree *)0x0) {
      pCVar7 = (CPlugTree *)0x0;
    }
    else {
      CPlugTree(pCVar7,pCVar1);
      pCVar7 = extraout_EAX;
    }
    local_4 = 0xffffffff;
    pCVar2 = CreateGroupSurface(this,param_1,(SPlugTreeOptimGroup *)pCVar1);
    SetSurface(pCVar7,(CPlugTree *)pCVar2,unaff_EDI);
    pCVar3 = CreateGroupVisual(this,param_1,unaff_ESI);
    pCVar8 = (CPlugMaterial *)0x0;
    SetVisual(pCVar7,(CVisionVisualKeeper *)pCVar3,*(CPlugVisual **)(param_1 + 0xc));
    if (*(CPlugMaterialCustom **)(param_1 + 8) != (CPlugMaterialCustom *)0x0) {
      SetMaterial(pCVar7,*(CPlugMaterialCustom **)(param_1 + 8),pCVar8);
    }
    break;
  case 1:
    pSVar4 = CFastBuffer<struct_SChildGen>::operator[]
                       (param_1 + 0x3c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)pCVar1);
    pCVar7 = DuplicateThis(*(CPlugTree **)pSVar4,(CPlugTree *)unaff_EDI);
    *(uint *)(pCVar7 + 0x9c) =
         *(uint *)(pCVar7 + 0x9c) ^ (*(int *)(pSVar4 + 4) * 4 ^ *(uint *)(pCVar7 + 0x9c)) & 4;
    goto LAB_0084c0a0;
  case 2:
    pSVar4 = CFastBuffer<struct_SChildGen>::operator[]
                       (param_1 + 0x3c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)pCVar1);
    pCVar7 = DuplicateRecursive(*(CPlugTree **)pSVar4,(CPlugTree *)unaff_EDI);
    *(uint *)(pCVar7 + 0x9c) =
         *(uint *)(pCVar7 + 0x9c) ^ (*(int *)(pSVar4 + 4) * 4 ^ *(uint *)(pCVar7 + 0x9c)) & 4;
LAB_0084c0a0:
    pSVar4 = pSVar4 + 8;
    pCVar1 = pCVar7 + 0x5c;
    for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(int *)pCVar1 = *(int *)pSVar4;
      pSVar4 = pSVar4 + 4;
      pCVar1 = pCVar1 + 4;
    }
    break;
  case 3:
    pSVar4 = CFastBuffer<struct_SChildGen>::operator[]
                       (param_1 + 0x3c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)pCVar1);
    pCVar7 = *(CPlugTree **)pSVar4;
  }
  (**(code **)(*(int *)pCVar7 + 0xbc))();
  if (*(int *)(pCVar7 + 0x8c) != 0) {
    *(uint *)(pCVar7 + 0x9c) = *(uint *)(pCVar7 + 0x9c) | 0x80;
  }
  if ((((*(int *)(param_3 + 8) != 0) && (iVar6 = *(int *)(pCVar7 + 0x90), iVar6 != 0)) &&
      (uVar5 = *(uint *)(iVar6 + 0x1c), (uVar5 & 8) == 0)) &&
     ((*(uint *)(iVar6 + 0x1c) = uVar5 | 8, (uVar5 & 0x400) == 0 &&
      (*(uint *)(iVar6 + 0x1c) = uVar5 | 0x408, DAT_00d6eb04 != (undefined4 *)0x0)))) {
    (**(code **)*DAT_00d6eb04)(iVar6);
  }
  if (((byte)*param_3 & 8) != 0) {
    *(uint *)(pCVar7 + 0x9c) =
         *(uint *)(pCVar7 + 0x9c) ^ (*(uint *)(pCVar7 + 0x9c) ^ *(uint *)(param_1 + 0x14)) & 0x100;
    uVar5 = (*(uint *)(param_1 + 0x14) ^ *(uint *)(pCVar7 + 0x9c)) & 1 ^ *(uint *)(pCVar7 + 0x9c);
    *(uint *)(pCVar7 + 0x9c) = uVar5;
    uVar5 = (*(uint *)(param_1 + 0x14) ^ uVar5) & 0x10 ^ uVar5;
    *(uint *)(pCVar7 + 0x9c) = uVar5;
    uVar5 = (*(uint *)(param_1 + 0x14) ^ uVar5) & 0x20 ^ uVar5;
    *(uint *)(pCVar7 + 0x9c) = uVar5;
    uVar5 = (*(uint *)(param_1 + 0x14) ^ uVar5) & 8 ^ uVar5;
    *(uint *)(pCVar7 + 0x9c) = uVar5;
    uVar5 = (*(uint *)(param_1 + 0x14) ^ uVar5) & 0x4000 ^ uVar5;
    *(uint *)(pCVar7 + 0x9c) = uVar5;
    uVar5 = (*(uint *)(param_1 + 0x14) ^ uVar5) & 0x8000 ^ uVar5;
    *(uint *)(pCVar7 + 0x9c) = uVar5;
    *(uint *)(pCVar7 + 0x9c) = (*(uint *)(param_1 + 0x14) ^ uVar5) & 0x40 ^ uVar5;
  }
  ExceptionList = puStack_8;
  return pCVar7;
}
}

// =================================================
// Function: CPlugTree::MakeQuad2D
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CPlugTree * __cdecl
CPlugTree::MakeQuad2D
          (CPlug *param_1,float param_2,float param_3,CPlugVisual *param_4,float param_5,
          ulong param_6,ulong param_7,ulong param_8,GmVec2 *param_9,GmVec2 *param_10,
          GmVec2 *param_11)
{
{
  uint uVar1;
  float fVar2;
  float fVar3;
  CPlugFileGen *pCVar4;
  CPlugFileGen *extraout_EAX;
  int iVar5;
  CPlugBitmap *extraout_EAX_00;
  CPlugShaderApply *extraout_EAX_01;
  CPlugBitmapApply *pCVar6;
  CPlugTree *this;
  CPlugTree *extraout_EAX_02;
  void *extraout_EAX_03;
  GmVec2 *this_00;
  CPlugVisualQuads2D *extraout_EAX_04;
  CPlugVisualSprite *pCVar7;
  EGxBlendFactor unaff_EBX;
  float unaff_EBP;
  CPlugFileGen *this_01;
  CPlugVisual *unaff_ESI;
  CVisionTexConverter *this_02;
  CPlugShaderApply *this_03;
  CPlugVisualQuads2D *this_04;
  ulong unaff_EDI;
  void *unaff_retaddr;
  CPlugVisualQuads2D *pCVar8;
  CPlugTree *pCVar9;
  CPlugShaderApply *pCVar10;
  CPlugVisualQuads2D *pCVar11;
  CPlugTree **ppCVar12;
  GmVec2 *pGVar13;
  int in_stack_ffffffbc;
  float fStack_30;
  float fStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  CPlugTree *pCStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  CPlugTree *local_4;
  
  local_4 = (CPlugTree *)0xffffffff;
  puStack_8 = &LAB_00ad5060;
  local_c = ExceptionList;
  pCVar4 = (CPlugFileGen *)(DAT_00cca150 ^ (uint)&stack0xffffffac);
  ExceptionList = &local_c;
  this_01 = (CPlugFileGen *)param_1;
  if (param_1 == (CPlug *)0x0) {
    param_1 = operator_new(0x50);
    local_4 = (CPlugTree *)0x0;
    if (param_1 == (CPlug *)0x0) {
      this_01 = (CPlugFileGen *)0x0;
    }
    else {
      CPlugFileGen::CPlugFileGen((CPlugFileGen *)param_1,pCVar4);
      this_01 = extraout_EAX;
    }
    unaff_retaddr = (void *)0xffffffff;
    CPlugFileGen::GenChecker(this_01,(CPlugFileGen *)0x1,unaff_EDI);
  }
  pCVar11 = (CPlugVisualQuads2D *)0x9025000;
  iVar5 = (**(code **)(*(int *)this_01 + 0x10))();
  this_02 = (CVisionTexConverter *)this_01;
  if (iVar5 != 0) {
    param_2 = (float)operator_new(0x78);
    if ((CPlugBitmap *)param_2 == (CPlugBitmap *)0x0) {
      this_02 = (CVisionTexConverter *)0x0;
    }
    else {
      CPlugBitmap::CPlugBitmap((CPlugBitmap *)param_2,(CPlugBitmap *)pCVar11);
      this_02 = (CVisionTexConverter *)extraout_EAX_00;
    }
    unaff_retaddr = (void *)0xffffffff;
    CPlugBitmap::SetImage
              ((CPlugBitmap *)this_02,(CVisionTexConverter *)this_01,(CPlugFileImg *)pCVar11);
    pCVar11 = (CPlugVisualQuads2D *)0x0;
    CPlugBitmap::SetDefaultTexAddress
              ((CPlugBitmap *)this_02,(CPlugBitmap *)0x2,2,0,(EGxTexAddress)unaff_ESI);
  }
  pCVar10 = (CPlugShaderApply *)0x9011000;
  iVar5 = (**(code **)(*(int *)this_02 + 0x10))();
  this_03 = (CPlugShaderApply *)this_02;
  if (iVar5 != 0) {
    param_1 = operator_new(0xa8);
    local_4 = (CPlugTree *)0x2;
    if (param_1 == (CPlug *)0x0) {
      this_03 = (CPlugShaderApply *)0x0;
    }
    else {
      CPlugShaderApply::CPlugShaderApply((CPlugShaderApply *)param_1,pCVar10);
      this_03 = extraout_EAX_01;
    }
    local_4 = (CPlugTree *)0xffffffff;
    pCVar6 = CPlugShaderApply::AddTextureApply
                       (this_03,(CPlugShaderApply *)this_02,(CPlugBitmap *)0x1,0,(ulong)pCVar10);
    if (pCVar6 != (CPlugBitmapApply *)0x0) {
      if ((DAT_00d6e6b8 & 1) == 0) {
        DAT_00d6e6b8 = DAT_00d6e6b8 | 1;
        CMwId::CreateFromLocalName((char *)&DAT_00d6e6b4);
        _atexit(`public:_static_class_MakeQuad2D*___cdecl_CPlugTree::
                MakeQuad2D(class_CPlug*,float,float,class_CPlugVisual*,float,unsigned_long,unsigned_long,unsigned_long,class_GmVec2_const&,class_GmVec2_const&,class_GmVec2_const&)'
                ::__l14::_dynamic_atexit_destructor_for__DiffuseId__);
        unaff_retaddr = (void *)0xffffffff;
      }
      *(undefined4 *)(pCVar6 + 0x18) = DAT_00d6e6b4;
    }
    CPlugShaderGeneric::SetVertexColor
              ((CPlugShaderGeneric *)this_03,(CPlugShaderGeneric *)0x1,0,(GxColor *)pCVar11);
    pCVar10 = (CPlugShaderApply *)0x84cb59;
    CPlugShader::SetReceiverShadowGroupMask
              ((CPlugShader *)this_03,(CPlugShader *)0x0,(ulong)unaff_ESI);
    CHmsItem::SetIsForcePointDynamicCollisionResponse
              ((CHmsItem *)this_03,(CHmsItem *)0x0,(int)unaff_EBP);
    unaff_ESI = (CPlugVisual *)&DAT_00000004;
    pCVar11 = (CPlugVisualQuads2D *)0x84cb6c;
    CPlugShaderApply::SetBlending(this_03,(CPlugShaderPass *)&DAT_00000004,5,unaff_EBX);
    unaff_EBP = 1.2195272e-38;
    CPlugShaderApply::SetForceIsAlphaBlend(this_03,(CPlugShaderApply *)0x1,in_stack_ffffffbc);
  }
  pCVar9 = (CPlugTree *)0x9002000;
  iVar5 = (**(code **)(*(int *)this_03 + 0x10))();
  if ((iVar5 == 0) && (iVar5 = (**(code **)(*(int *)this_03 + 0x10))(0x9079000), iVar5 == 0)) {
    this = operator_new(0xac);
    puStack_8 = (undefined1 *)0x6;
    if (this != (CPlugTree *)0x0) {
      CPlugTree(this,pCVar9);
      *(uint *)(extraout_EAX_02 + 0x9c) = *(uint *)(extraout_EAX_02 + 0x9c) & 0xfffffff7;
      ExceptionList = local_c;
      return extraout_EAX_02;
    }
    uRam0000009c = uRam0000009c & 0xfffffff7;
    ExceptionList = pvStack_10;
    return (CPlugTree *)0x0;
  }
  pCVar8 = (CPlugVisualQuads2D *)0x9079000;
  iVar5 = (**(code **)(*(int *)this_03 + 0x10))();
  local_4 = operator_new(0xac);
  local_c = (void *)0x4;
  if (local_4 == (CPlugTree *)0x0) {
    local_4 = (CPlugTree *)0x0;
  }
  else {
    CPlugTree(local_4,(CPlugTree *)pCVar8);
    unaff_retaddr = extraout_EAX_03;
  }
  local_c = (void *)0xffffffff;
  if (param_2 == 0.0) {
    this_00 = operator_new(0x84);
    local_c = (void *)0x5;
    if (this_00 == (GmVec2 *)0x0) {
      this_04 = (CPlugVisualQuads2D *)0x0;
    }
    else {
      CPlugVisualQuads2D::CPlugVisualQuads2D((CPlugVisualQuads2D *)this_00,pCVar8);
      this_04 = extraout_EAX_04;
    }
    local_c = (void *)0xffffffff;
    CPlugVisualQuads2D::SetQuadCount(this_04,(CPlugVisualQuads2D *)0x1,(ulong)pCVar8);
    if (_DAT_00b2c060 == (float)param_1) {
      param_1 = _DAT_00b3380c;
    }
    if (_DAT_00b2c060 == 0.0) {
      param_2 = (float)_DAT_00b3380c;
    }
    fStack_30 = 1.0;
    fStack_2c = 1.0;
    uStack_28 = 0x3f800000;
    uStack_24 = 0x3f800000;
    CPlugVisualQuads2D::CreateQuad
              (this_04,(CPlugVisualQuads2D *)0x0,(GmVec2)0x0,(float)param_1,param_2,
               (GxColor *)&fStack_30,0,(float)param_4);
    if ((param_6 == 0) || (param_7 == 0)) {
      uStack_18 = *(undefined4 *)param_8;
      uStack_14 = *(undefined4 *)(param_9 + 4);
      uStack_20 = *(undefined4 *)param_9;
      pCStack_1c = *(CPlugTree **)(param_8 + 4);
      pCVar7 = operator_new__(0x20);
      CPlugVisual::AddTexCoordSet
                ((CPlugVisual *)this_04,pCVar7,(float)pCVar9,(float)pCVar10,(ulong)pCVar11,
                 (float)unaff_ESI,unaff_EBP);
      pGVar13 = (GmVec2 *)&local_c;
      ppCVar12 = &local_4;
    }
    else {
      this_00 = (GmVec2 *)((uint)param_5 / param_6);
      fVar2 = (float)(int)param_6;
      if ((int)param_6 < 0) {
        fVar2 = fVar2 + _DAT_00c418d0;
      }
      fVar3 = (float)(int)((uint)param_5 % param_6);
      if ((int)((uint)param_5 % param_6) < 0) {
        fVar3 = fVar3 + _DAT_00c418d0;
      }
      fStack_30 = (*(float *)param_8 + (*(float *)param_9 - *(float *)param_8) * (fVar3 / fVar2)) -
                  *(float *)param_10;
      fVar2 = (float)(int)param_7;
      if ((int)param_7 < 0) {
        fVar2 = fVar2 + _DAT_00c418d0;
      }
      fVar3 = (float)(int)(this_00 + 1);
      if ((int)(this_00 + 1) < 0) {
        fVar3 = fVar3 + _DAT_00c418d0;
      }
      fStack_2c = *(float *)(param_10 + 4) +
                  *(float *)(param_8 + 4) +
                  (*(float *)(param_9 + 4) - *(float *)(param_8 + 4)) * (fVar3 / fVar2);
      pCVar7 = operator_new__(0x20);
      CPlugVisual::AddTexCoordSet
                ((CPlugVisual *)this_04,pCVar7,(float)pCVar9,(float)pCVar10,(ulong)pCVar11,
                 (float)unaff_ESI,unaff_EBP);
      pGVar13 = (GmVec2 *)&uStack_24;
      ppCVar12 = &pCStack_1c;
    }
    CPlugVisualQuads2D::SetQuadUVs
              (this_04,(CPlugVisualQuads2D *)0x0,(ulong)ppCVar12,pGVar13,this_00);
    uVar1 = *(uint *)(this_04 + 0x1c);
    if ((((uVar1 & 8) == 0) && (*(uint *)(this_04 + 0x1c) = uVar1 | 8, (uVar1 & 0x400) == 0)) &&
       (*(uint *)(this_04 + 0x1c) = uVar1 | 0x408, DAT_00d6eb04 != (undefined4 *)0x0)) {
      (**(code **)*DAT_00d6eb04)();
    }
    uVar1 = *(uint *)(this_04 + 0x1c);
    if ((((uVar1 & 0x20) == 0) && (*(uint *)(this_04 + 0x1c) = uVar1 | 0x20, (uVar1 & 0x400) == 0))
       && (*(uint *)(this_04 + 0x1c) = uVar1 | 0x420, DAT_00d6eb04 != (undefined4 *)0x0)) {
      (**(code **)*DAT_00d6eb04)();
    }
    unaff_ESI = (CPlugVisual *)(~-(uint)(iVar5 != 0) & (uint)this_03);
    pCVar11 = this_04;
  }
  SetVisual((CPlugTree *)param_6,(CVisionVisualKeeper *)pCVar11,unaff_ESI);
  ExceptionList = unaff_retaddr;
  return (CPlugTree *)param_4;
}
}

// =================================================
// Function: CPlugTree::MergePrimitivesInTree
// =================================================
int __thiscall
CPlugTree::MergePrimitivesInTree
          (CPlugTree *this,CPlugTree *param_1,CPlugShader *param_2,
          CFastBuffer<class_CPlugVisual*> *param_3)
{
{
  short *psVar1;
  uint uVar2;
  int *piVar3;
  CPlugVisual *pCVar4;
  SCasterCat *pSVar5;
  int iVar6;
  CPlugVisualSprite *pCVar7;
  void *pvVar8;
  uint uVar9;
  CPlugVisualIndexed *extraout_EAX;
  void *pvVar10;
  int iVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CPlugVisual *pCVar12;
  uint uVar13;
  int unaff_ESI;
  CPlugVisualIndexed *this_00;
  CPlugTree *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  CPlugVisualIndexed *pCVar15;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar16;
  CPlugTree *this_01;
  float in_stack_ffffffac;
  float fVar17;
  CPlugShader *pCVar18;
  CPlugVisualSprite *pCStack_2c;
  GxVertex *local_28;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_20;
  void *local_c;
  undefined1 *local_8;
  CPlugTree *pCStack_4;
  
  pCStack_4 = (CPlugTree *)0xffffffff;
  local_8 = &LAB_00ad4f4b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar4 = (CPlugVisual *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (param_2,(CFastBuffer<class_CCrystalFace*> *)
                              (DAT_00cca150 ^ (uint)&stack0xffffffc4));
  uVar13 = 0;
  if ((pCVar4 == (CPlugVisual *)0x0) || (param_2 == (CPlugShader *)0x0)) {
    iVar6 = 0;
  }
  else {
    uVar2 = *(uint *)(param_2 + 0x20);
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    local_28 = (GxVertex *)0x0;
    if (pCVar4 != (CPlugVisual *)0x0) {
      do {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (param_3,pCVar14,(ulong)unaff_EDI);
        piVar3 = *(int **)pSVar5;
        iVar6 = (**(code **)(*piVar3 + 0xb8))();
        uVar13 = uVar13 + iVar6;
        unaff_EDI = (CPlugTree *)0x0;
        iVar6 = (**(code **)(*piVar3 + 0xcc))();
        local_28 = (GxVertex *)((int)local_28 + iVar6);
        (**(code **)(*piVar3 + 0xbc))();
        pCVar14 = pCVar14 + 1;
      } while (pCVar14 < pCVar4);
    }
    pCVar7 = operator_new__(-(uint)((int)((ulonglong)uVar13 * 0x28 >> 0x20) != 0) |
                            (uint)((ulonglong)uVar13 * 0x28));
    pvVar8 = operator_new__(-(uint)((int)(ZEXT48(local_28) * 2 >> 0x20) != 0) |
                            (uint)(ZEXT48(local_28) * 2));
    pCVar15 = (CPlugVisualIndexed *)0x0;
    local_28 = (GxVertex *)0x0;
    pCStack_20 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar4 != (CPlugVisual *)0x0) {
      do {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (param_3,pCStack_20,(ulong)unaff_EDI);
        piVar3 = *(int **)pSVar5;
        unaff_EDI = (CPlugTree *)(uVar2 & 0xf) + (int)pCVar15 * 0x28;
        (**(code **)(*piVar3 + 0xc0))();
        pvVar10 = (void *)((int)pvVar8 + (int)local_28 * 2);
        (**(code **)(*piVar3 + 0xd0))(pvVar10);
        uVar13 = (**(code **)(*piVar3 + 0xcc))(0);
        uVar9 = 0;
        if (uVar13 != 0) {
          do {
            psVar1 = (short *)((int)pvVar10 + uVar9 * 2);
            *psVar1 = *psVar1 + (short)pCVar15;
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar13);
        }
        iVar6 = (**(code **)(*piVar3 + 0xb8))();
        local_28 = local_28 + uVar13;
        pCVar15 = pCVar15 + iVar6;
        pCStack_20 = pCStack_20 + 1;
      } while (pCStack_20 < pCVar4);
    }
    pCStack_20 = operator_new(0x9c);
    if (pCStack_20 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      pCStack_20 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      this_00 = (CPlugVisualIndexed *)0x0;
    }
    else {
      CPlugVisualIndexedTriangles::CPlugVisualIndexedTriangles
                ((CPlugVisualIndexedTriangles *)pCStack_20,(CPlugVisualIndexedTriangles *)unaff_EDI)
      ;
      this_00 = extraout_EAX;
    }
    fVar17 = 1.2190634e-38;
    CPlugVisualIndexed::SetVerticesAndIndices
              (this_00,pCVar15,(ulong)pCVar7,local_28,(ulong)pvVar8,(ushort *)unaff_EDI);
    CPlugVisual::EnableVertexColor((CPlugVisual *)this_00,(CPlugVisual *)0x0,unaff_ESI);
    this_01 = pCStack_4;
    SetVisual(pCStack_4,(CVisionVisualKeeper *)this_00,(CPlugVisual *)0x0);
    pCVar18 = (CPlugShader *)0x1;
    (**(code **)(*(int *)this_01 + 0xbc))();
    pCStack_2c = (CPlugVisualSprite *)0x0;
    pCVar12 = pCVar4;
    if (pCVar7 != (CPlugVisualSprite *)0x0) {
      do {
        iVar6 = 0;
        pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                  (-(uint)((int)(ZEXT48(pCStack_20) * 8 >> 0x20) != 0) |
                  (uint)(ZEXT48(pCStack_20) * 8));
        pvVar8 = (void *)0x84bedc;
        pvVar10 = operator_new__((uint)pCVar14);
        pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pCVar12 != (CPlugVisual *)0x0) {
          do {
            pCVar14 = pCVar16;
            pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (param_2,pCVar16,(ulong)pCVar18);
            piVar3 = *(int **)pSVar5;
            pCVar18 = (CPlugShader *)0x84bf01;
            iVar11 = (**(code **)(*piVar3 + 0xbc))();
            pSVar5 = CFastBuffer<struct_SFastCat>::operator[](piVar3 + 0x17,unaff_EBX,iVar11 * 8);
            pvVar8 = *(void **)(pSVar5 + 4);
            pCVar15 = (CPlugVisualIndexed *)((int)pvVar10 + iVar6 * 8);
            fVar17 = 1.2190861e-38;
            _memcpy(pCVar15,pvVar8,(uint)pCVar14);
            pCVar16 = pCVar16 + 1;
            iVar6 = iVar6 + iVar11;
            pCVar12 = (CPlugVisual *)local_28;
            this_00 = (CPlugVisualIndexed *)pCVar4;
          } while (pCVar16 < local_28);
        }
        CPlugVisual::AddTexCoordSet
                  ((CPlugVisual *)this_00,pCStack_2c,in_stack_ffffffac,fVar17,(ulong)pCVar15,
                   (float)pvVar8,(float)pCVar14);
        pCStack_2c = pCStack_2c + 1;
        this_01 = (CPlugTree *)(uVar2 & 0xf);
      } while (pCStack_2c < pCVar7);
    }
    SetShader(this_01,(CPlugBitmapShader *)param_1,pCVar18);
    iVar6 = 1;
  }
  ExceptionList = local_8;
  return iVar6;
}
}

// =================================================
// Function: CPlugTree::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CPlugTree::MwGetClassInfo(CPlugTree *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d6e644;
}
}

// =================================================
// Function: CPlugTree::MwIsKindOf
// =================================================
int __thiscall CPlugTree::MwIsKindOf(CPlugTree *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if ((param_1 != (CMwCmdAffectParam *)0x904f000) && (param_1 != (CMwCmdAffectParam *)0x902b000)) {
    return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
  }
  return 1;
}
}

// =================================================
// Function: CPlugTree::MwNewCPlugTree
// =================================================
CMwNod * __cdecl CPlugTree::MwNewCPlugTree(void)
{
{
  CPlugTree *pCVar1;
  CMwNod *extraout_EAX;
  CPlugTree *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ad4e1b;
  local_c = ExceptionList;
  pCVar1 = (CPlugTree *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0xac);
  local_4 = 0;
  if (local_10 != (CPlugTree *)0x0) {
    CPlugTree(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CPlugTree::OnNodLoaded
// =================================================
void __thiscall CPlugTree::OnNodLoaded(CPlugTree *this,CDx9DeviceCaps *param_1)
{
{
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x10000;
  if (*(int *)(this + 0x1c) != 0) {
    RefreshThisFromModel(this,(CPlugTree *)param_1);
    return;
  }
  return;
}
}

// =================================================
// Function: CPlugTree::RefreshThisFromModel
// =================================================
void __thiscall CPlugTree::RefreshThisFromModel(CPlugTree *this,CPlugTree *param_1)
{
{
  int iVar1;
  CPlugTree *pCVar2;
  
  iVar1 = *(int *)this;
  pCVar2 = GetModelTree(this,(CPlugTree *)0x0);
  (**(code **)(iVar1 + 0xb0))(pCVar2);
  (**(code **)(*(int *)this + 0x78))(0);
  return;
}
}

// =================================================
// Function: CPlugTree::RenderBefore
// =================================================
void __thiscall
CPlugTree::RenderBefore
          (CPlugTree *this,CPlugTreeFrustum *param_1,GmFrustum *param_2,GmBoxAligned *param_3,
          GmIso4 *param_4,GmIso4 *param_5,int *param_6,SPlugTreeInRenderFlags param_7)
{
{
  return;
}
}

// =================================================
// Function: CPlugTree::SetChild
// =================================================
void __thiscall
CPlugTree::SetChild(CPlugTree *this,CPlugTreeVisualMip *param_1,CPlugTree *param_2,ulong param_3)
{
{
  CPlugTree *pCVar1;
  SCasterCat *pSVar2;
  CPlugTree *unaff_EBX;
  int unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x28,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                      unaff_EDI);
  pCVar1 = *(CPlugTree **)pSVar2;
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x28,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                      unaff_ESI);
  *(ulong *)pSVar2 = param_3;
  if (*(int *)(this + 0x14) != 0) {
    (**(code **)(*(int *)param_3 + 0x78))(0);
  }
  ConnectAsChild(this,(CPlugTree *)param_3,(CPlugTree *)0x1,unaff_EBP);
  DeconnectAsChild(this,pCVar1,unaff_EBX);
  if (pCVar1 != (CPlugTree *)0x0) {
    (**(code **)(*(int *)pCVar1 + 4))(1);
  }
  return;
}
}

// =================================================
// Function: CPlugTree::SetFuncTree
// =================================================
void __thiscall CPlugTree::SetFuncTree(CPlugTree *this,CPlugTree *param_1,CFuncTree *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CPlugTree **)(this + 0xa8)) {
    if (param_1 != (CPlugTree *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0xa8) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xa8),unaff_ESI);
    }
    *(CPlugTree **)(this + 0xa8) = param_1;
  }
  return;
}
}

// =================================================
// Function: CPlugTree::SetGenerator
// =================================================
void __thiscall
CPlugTree::SetGenerator(CPlugTree *this,CPlugTree *param_1,CPlugTreeGenerator *param_2,int param_3)
{
{
  CMwNod *unaff_EDI;
  
  if (*(int **)(this + 0xa0) == (int *)0x0) {
LAB_00849bd7:
    if ((param_2 != (CPlugTreeGenerator *)0x0) || (param_1 != (CPlugTree *)0x0)) goto LAB_00849bf7;
  }
  else if ((param_2 != (CPlugTreeGenerator *)0x0) || (param_1 != (CPlugTree *)0x0)) {
    (**(code **)(**(int **)(this + 0xa0) + 0x7c))(this);
    goto LAB_00849bd7;
  }
  if (*(int *)(this + 0xa0) != 0) {
    RecursiveSetUnassigned(this);
    RecursiveSetRooted(this);
  }
LAB_00849bf7:
  if (param_1 != *(CPlugTree **)(this + 0xa0)) {
    if (param_1 != (CPlugTree *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0xa0) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xa0),unaff_EDI);
    }
    *(CPlugTree **)(this + 0xa0) = param_1;
  }
  if ((*(int **)(this + 0xa0) != (int *)0x0) && (param_2 != (CPlugTreeGenerator *)0x0)) {
    (**(code **)(**(int **)(this + 0xa0) + 0x78))(this);
  }
  return;
}
}

// =================================================
// Function: CPlugTree::SetIdName
// =================================================
void __thiscall CPlugTree::SetIdName(CPlugTree *this,CMwNod *param_1,char *param_2)
{
{
  CMwId CVar1;
  CMwId *pCVar2;
  undefined3 extraout_var;
  CFastStringInt *unaff_ESI;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ad4cf8;
  local_c = ExceptionList;
  pCVar2 = (CMwId *)(DAT_00cca150 ^ (uint)&stack0xfffffff0);
  ExceptionList = &local_c;
  CVar1 = CMwId::CreateFromLocalName((char *)&param_1);
  local_4 = 0;
  SetPlugId(this,(CPlugTree *)CONCAT31(extraout_var,CVar1),pCVar2);
  OnAccessViolation_ConcatToCrashFileName(unaff_ESI);
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CPlugTree::SetIsPickableVisual
// =================================================
void __thiscall CPlugTree::SetIsPickableVisual(CPlugTree *this,CPlugTree *param_1,int param_2)
{
{
  *(uint *)(this + 0x9c) =
       *(uint *)(this + 0x9c) ^
       ((uint)(param_1 != (CPlugTree *)0x0) << 0xb ^ *(uint *)(this + 0x9c)) & 0x800;
  return;
}
}

// =================================================
// Function: CPlugTree::SetIsRooted
// =================================================
void __thiscall CPlugTree::SetIsRooted(CPlugTree *this,CPlugTree *param_1,int param_2)
{
{
  CPlugSolid *unaff_retaddr;
  
  *(uint *)(this + 0x9c) =
       *(uint *)(this + 0x9c) ^
       ((uint)(param_1 != (CPlugTree *)0x0) << 0xf ^ *(uint *)(this + 0x9c)) & 0x8000;
  if ((param_1 != (CPlugTree *)0x0) && (*(CPlugSolid **)(this + 0x14) != (CPlugSolid *)0x0)) {
    CPlugSolid::MakeTreeIdsUnique(*(CPlugSolid **)(this + 0x14),unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CPlugTree::SetIsVisible
// =================================================
void __thiscall CPlugTree::SetIsVisible(CPlugTree *this,CPlugTree *param_1,int param_2)
{
{
  *(uint *)(this + 0x9c) =
       *(uint *)(this + 0x9c) ^
       ((uint)(param_1 != (CPlugTree *)0x0) * 8 ^ *(uint *)(this + 0x9c)) & 8;
  return;
}
}

// =================================================
// Function: CPlugTree::SetLocation
// =================================================
void __thiscall CPlugTree::SetLocation(CPlugTree *this,CPlugTree *param_1,GmIso4 *param_2)
{
{
  int iVar1;
  CPlugTree *pCVar2;
  
  pCVar2 = this + 0x5c;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pCVar2 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    pCVar2 = pCVar2 + 4;
  }
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x10000;
  return;
}
}

// =================================================
// Function: CPlugTree::SetMaterial
// =================================================
void __thiscall
CPlugTree::SetMaterial(CPlugTree *this,CPlugMaterialCustom *param_1,CPlugMaterial *param_2)
{
{
  CPlugShader *this_00;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  CMwNod *unaff_retaddr;
  
  if ((*(int *)(this + 0x94) != 0) && (param_1 != *(CPlugMaterialCustom **)(this + 0x98))) {
    if (param_1 != (CPlugMaterialCustom *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x98) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x98),unaff_ESI);
    }
    *(CPlugMaterialCustom **)(this + 0x98) = param_1;
    if ((param_1 != (CPlugMaterialCustom *)0x0) &&
       (this_00 = CPlugMaterial::GetSupportedShader
                            ((CPlugMaterial *)param_1,(CPlugMaterial *)unaff_ESI),
       this_00 != *(CPlugShader **)(this + 0x94))) {
      if (this_00 != (CPlugShader *)0x0) {
        CMwNod::MwAddRef((CMwNod *)this_00,unaff_retaddr);
      }
      if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x94),(CMwNod *)param_1);
      }
      *(CPlugShader **)(this + 0x94) = this_00;
    }
  }
  return;
}
}

// =================================================
// Function: CPlugTree::SetPlugId
// =================================================
void __thiscall CPlugTree::SetPlugId(CPlugTree *this,CPlugTree *param_1,CMwId *param_2)
{
{
  int iVar1;
  CPlugSolid *extraout_ECX;
  CPlugTree *unaff_retaddr;
  CPlugTree *in_stack_0000000c;
  
  iVar1 = GetIsRooted(this,unaff_retaddr);
  *(undefined4 *)(extraout_ECX + 0x18) = *(undefined4 *)param_2;
  if ((iVar1 != 0) && (*(CPlugSolid **)(extraout_ECX + 0x14) != (CPlugSolid *)0x0)) {
    CPlugSolid::InternalConnectSubTree
              (*(CPlugSolid **)(extraout_ECX + 0x14),extraout_ECX,in_stack_0000000c);
    return;
  }
  return;
}
}

// =================================================
// Function: CPlugTree::SetRotation
// =================================================
void __thiscall CPlugTree::SetRotation(CPlugTree *this,GmMat2 *param_1,float param_2)
{
{
  int unaff_ESI;
  
  GmMat3::Set(this + 0x5c,(CMwCmdScriptVarBool *)param_1,unaff_ESI);
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x10000;
  return;
}
}

// =================================================
// Function: CPlugTree::SetShader
// =================================================
void __thiscall
CPlugTree::SetShader(CPlugTree *this,CPlugBitmapShader *param_1,CPlugShader *param_2)
{
{
  int iVar1;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if ((*(CPlugBitmapShader **)(this + 0x94) != (CPlugBitmapShader *)0x0) &&
     (*(CPlugBitmapShader **)(this + 0x94) != param_1)) {
    if (param_1 != (CPlugBitmapShader *)0x0) {
      (**(code **)(*(int *)param_1 + 0xa8))();
    }
    if (param_1 != *(CPlugBitmapShader **)(this + 0x94)) {
      if (param_1 != (CPlugBitmapShader *)0x0) {
        CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
      }
      if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x94),unaff_EDI);
      }
      *(CPlugBitmapShader **)(this + 0x94) = param_1;
    }
    if (((*(CPlugMaterial **)(this + 0x98) != (CPlugMaterial *)0x0) &&
        (iVar1 = CPlugMaterial::DoesContainShader
                           (*(CPlugMaterial **)(this + 0x98),(CPlugMaterial *)param_1,
                            (CPlugShader *)0x0,(ulong *)unaff_EDI), iVar1 == 0)) &&
       (*(CMwNod **)(this + 0x98) != (CMwNod *)0x0)) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x98),unaff_ESI);
      *(undefined4 *)(this + 0x98) = 0;
    }
  }
  return;
}
}

// =================================================
// Function: CPlugTree::SetSubVisualIndex
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugTree::SetSubVisualIndex
          (CPlugTree *this,CPlugTree *param_1,ulong param_2,ulong param_3,float param_4)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)_DAT_00b55d50;
  fVar1 = (float)param_3 * fVar2;
  fVar3 = 0.0;
  *(ulong *)(this + 0x54) =
       (param_2 & 0xfff) << 0xc | *(uint *)(this + 0x54) & 0xff000000 | (uint)param_1 & 0xfff;
  if ((fVar1 < 0.0 == (fVar1 == 0.0)) && (fVar3 = fVar1, fVar2 <= fVar1)) {
    fVar3 = _DAT_00b5e844;
  }
  param_1._0_1_ = SUB41((int)ROUND(fVar3),0);
  this[0x57] = param_1._0_1_;
  return;
}
}

// =================================================
// Function: CPlugTree::SetSurface
// =================================================
void __thiscall CPlugTree::SetSurface(CPlugTree *this,CPlugTree *param_1,CPlugSurface *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CPlugTree **)(this + 0x8c)) {
    if (param_1 != (CPlugTree *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x8c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x8c),unaff_ESI);
    }
    *(CPlugTree **)(this + 0x8c) = param_1;
  }
  return;
}
}

// =================================================
// Function: CPlugTree::SetTranslation
// =================================================
void __thiscall CPlugTree::SetTranslation(CPlugTree *this,GmIso4 *param_1,GmVec3 *param_2)
{
{
  *(undefined4 *)(this + 0x80) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 8);
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x10000;
  return;
}
}

// =================================================
// Function: CPlugTree::SetUseLocation
// =================================================
void __thiscall CPlugTree::SetUseLocation(CPlugTree *this,CPlugTree *param_1,int param_2)
{
{
  *(uint *)(this + 0x9c) =
       (param_1 != (CPlugTree *)0x0 | 0x4000) * 4 | *(uint *)(this + 0x9c) & 0xfffffffb;
  return;
}
}

// =================================================
// Function: CPlugTree::SetVisual
// =================================================
void __thiscall
CPlugTree::SetVisual(CPlugTree *this,CVisionVisualKeeper *param_1,CPlugVisual *param_2)
{
{
  void *this_00;
  int iVar1;
  ulong uVar2;
  void *this_01;
  CFastBuffer<class_GxVertex2> *pCVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  CPlugShader *this_02;
  CMwNod *extraout_EAX;
  int iVar6;
  ulong uVar7;
  CMwNod *unaff_EBX;
  CMwNod *this_03;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_EBP;
  int iVar8;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CPlugMaterial *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  void *unaff_retaddr;
  CPlugShaderApply *in_stack_0000000c;
  CMwNod *in_stack_00000014;
  CPlugShaderApply *in_stack_00000018;
  CSystemEngine *in_stack_0000001c;
  CMwNod *in_stack_00000020;
  CFastBuffer<class_CCrystalFace*> *pCVar10;
  CFastBuffer<class_CCrystalFace*> *pCVar11;
  CFastBuffer<class_CPlugFileGPUV*> *this_04;
  CSystemEngine *pCVar12;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4eeb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (((param_1 != *(CVisionVisualKeeper **)(this + 0x90)) ||
      ((param_2 != (CPlugVisual *)0x0 && (param_2 != *(CPlugVisual **)(this + 0x94))))) ||
     ((in_stack_0000000c != (CPlugShaderApply *)0x0 &&
      (in_stack_0000000c != (CPlugShaderApply *)*(CMwNod **)(this + 0x98))))) {
    if (param_1 != *(CVisionVisualKeeper **)(this + 0x90)) {
      if (param_1 != (CVisionVisualKeeper *)0x0) {
        CMwNod::MwAddRef((CMwNod *)param_1,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
      }
      if (*(CMwNod **)(this + 0x90) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x90),(CMwNod *)unaff_EDI);
      }
      *(CVisionVisualKeeper **)(this + 0x90) = param_1;
    }
    iVar6 = *(int *)(this + 0x90);
    if (iVar6 == 0) {
      if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x94),(CMwNod *)unaff_EDI);
        *(undefined4 *)(this + 0x94) = 0;
      }
      if (*(CMwNod **)(this + 0x98) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x98),(CMwNod *)unaff_EDI);
        *(undefined4 *)(this + 0x98) = 0;
      }
    }
    else {
      pCVar10 = (CFastBuffer<class_CCrystalFace*> *)0x84b73f;
      uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                        ((void *)(iVar6 + 0x20),(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
      if (uVar2 != 0) {
        unaff_EDI = (CPlugMaterial *)0x84b74b;
        uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar6 + 0x20),unaff_ESI);
        *(undefined2 *)(this + 0x54) = 0;
        *(short *)(this + 0x56) = (short)uVar2;
      }
      if (*(int *)(iVar6 + 0x50) != 0) {
        this_04 = *(CFastBuffer<class_CPlugFileGPUV*> **)(this + 0xa4);
        if (this_04 != (CFastBuffer<class_CPlugFileGPUV*> *)0x0) {
          CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this_04,unaff_EBP);
          operator_delete(this_04);
          unaff_EBP = this_04;
        }
        pCVar11 = (CFastBuffer<class_CCrystalFace*> *)&DAT_0000000c;
        uVar2 = 0x84b784;
        this_01 = operator_new(0xc);
        if (this_01 == (void *)0x0) {
          this_01 = (void *)0x0;
        }
        else {
          pCVar11 = (CFastBuffer<class_CCrystalFace*> *)0x84b794;
          CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                    (this_01,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_EBP);
        }
        *(void **)(this + 0xa4) = this_01;
        this_00 = (void *)(*(int *)(*(int *)(this + 0x90) + 0x50) + 0xc);
        pCVar3 = (CFastBuffer<class_GxVertex2> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount(this_00,pCVar10);
        CFastBuffer<class_GmIso4>::AllocSetCount(this_01,pCVar3,uVar2);
        unaff_EDI = (CPlugMaterial *)0x84b7c0;
        pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount(this_00,pCVar11);
        pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        param_2 = (CPlugVisual *)in_stack_00000014;
        in_stack_0000000c = in_stack_00000018;
        if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar5 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
                     ::operator[](this_00,pCVar9,(ulong)pCVar3);
            pSVar5 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
                     ::operator[](*(void **)(this + 0xa4),pCVar9,(ulong)pSVar5);
            pCVar3 = (CFastBuffer<class_GxVertex2> *)0x84b7e4;
            GmIso4::SetInverse(pSVar5,(GmScaleTrans2 *)unaff_EDI,(GmScaleTrans2 *)pCVar11);
            pCVar9 = pCVar9 + 1;
            in_stack_0000000c = in_stack_00000018;
          } while (pCVar9 < pCVar4);
        }
      }
      if (in_stack_0000000c == (CPlugShaderApply *)0x0) {
        if (param_2 == (CPlugVisual *)0x0) {
          if (*(int **)(this + 0x94) == (int *)0x0) {
            unaff_EDI = (CPlugMaterial *)0x84b8c5;
            in_stack_00000018 = operator_new(0xa8);
            this_03 = (CMwNod *)0x0;
            if (in_stack_00000018 != (CPlugShaderApply *)0x0) {
              CPlugShaderApply::CPlugShaderApply(in_stack_00000018,(CPlugShaderApply *)unaff_EBP);
              this_03 = extraout_EAX;
            }
            if (this_03 != *(CMwNod **)(this + 0x94)) {
              if (this_03 != (CMwNod *)0x0) {
                CMwNod::MwAddRef(this_03,(CMwNod *)unaff_EBP);
              }
              if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
                CMwNod::MwRelease(*(CMwNod **)(this + 0x94),(CMwNod *)unaff_EBP);
              }
              *(CMwNod **)(this + 0x94) = this_03;
            }
          }
          else {
            (**(code **)(**(int **)(this + 0x94) + 0x94))();
          }
        }
        else if ((param_2 != (CPlugVisual *)*(CMwNod **)(this + 0x94)) &&
                ((**(code **)(*(int *)param_2 + 0xa8))(),
                param_2 != (CPlugVisual *)*(CMwNod **)(this + 0x94))) {
          CMwNod::MwAddRef((CMwNod *)param_2,(CMwNod *)unaff_EBP);
          if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
            unaff_EBP = (CFastBuffer<class_CPlugFileGPUV*> *)0x84b8a9;
            CMwNod::MwRelease(*(CMwNod **)(this + 0x94),(CMwNod *)0x84b8a9);
          }
          *(CPlugVisual **)(this + 0x94) = param_2;
        }
        if (*(CPlugMaterial **)(this + 0x98) != (CPlugMaterial *)0x0) {
          unaff_EDI = *(CPlugMaterial **)(this + 0x94);
          iVar6 = CPlugMaterial::DoesContainShader
                            (*(CPlugMaterial **)(this + 0x98),unaff_EDI,(CPlugShader *)0x0,
                             (ulong *)unaff_EBP);
          if ((iVar6 == 0) && (*(CMwNod **)(this + 0x98) != (CMwNod *)0x0)) {
            unaff_EBP = (CFastBuffer<class_CPlugFileGPUV*> *)0x84b946;
            CMwNod::MwRelease(*(CMwNod **)(this + 0x98),(CMwNod *)0x84b946);
            *(undefined4 *)(this + 0x98) = 0;
          }
        }
      }
      else if (in_stack_0000000c != (CPlugShaderApply *)*(CMwNod **)(this + 0x98)) {
        CMwNod::MwAddRef((CMwNod *)in_stack_0000000c,(CMwNod *)unaff_EBP);
        if (*(CMwNod **)(this + 0x98) != (CMwNod *)0x0) {
          unaff_EBP = (CFastBuffer<class_CPlugFileGPUV*> *)0x84b819;
          CMwNod::MwRelease(*(CMwNod **)(this + 0x98),unaff_EBX);
        }
        *(CPlugShaderApply **)(this + 0x98) = in_stack_0000000c;
        if (in_stack_0000000c != (CPlugShaderApply *)0x0) {
          this_02 = CPlugMaterial::GetSupportedShader
                              ((CPlugMaterial *)in_stack_0000000c,(CPlugMaterial *)unaff_EBP);
          if (this_02 != *(CPlugShader **)(this + 0x94)) {
            if (this_02 != (CPlugShader *)0x0) {
              unaff_EBP = (CFastBuffer<class_CPlugFileGPUV*> *)0x84b843;
              CMwNod::MwAddRef((CMwNod *)this_02,(CMwNod *)0x84b843);
            }
            if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
              CMwNod::MwRelease(*(CMwNod **)(this + 0x94),(CMwNod *)unaff_EBP);
            }
            *(CPlugShader **)(this + 0x94) = this_02;
          }
          if (*(int *)(this + 0x94) == 0) {
            ExceptionList = unaff_retaddr;
            return;
          }
        }
      }
      uVar2 = 0x84b95d;
      iVar6 = (**(code **)(**(int **)(this + 0x90) + 0x78))();
      if ((iVar6 == 7) && ((*(byte *)(*(int *)(this + 0x90) + 0xb0) & 7) == 0)) {
        iVar6 = 1;
      }
      else {
        iVar6 = 0;
      }
      iVar1 = *(int *)(this + 0x94);
      iVar8 = 0;
      uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount
                        ((void *)(iVar1 + 0x2c),(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
      if (uVar7 != 0) {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar1 + 0x2c),
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,uVar2);
        if ((*(int *)(*(int *)pSVar5 + 0x3c) == 0) ||
           ((*(byte *)(*(int *)(*(int *)pSVar5 + 0x3c) + 0xc4) & 0x10) == 0)) {
          iVar8 = 0;
        }
        else {
          iVar8 = 1;
        }
      }
      if (iVar6 != iVar8) {
        if (iVar6 == 0) {
          ChangeShaderClass(this,(CPlugTree *)0x9026000,(ulong)unaff_EBP);
        }
        else {
          CSystemArchiveNod::LoadResource(0x4000001d,(CMwNod **)&stack0x00000018);
          pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((void *)(DAT_00d73300 + 0x20),
                              (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                              (ulong)unaff_EBP);
          pCVar12 = in_stack_0000001c;
          CSystemEngine::UnbindFid(*(CSystemEngine **)pSVar5,in_stack_0000001c,unaff_EBX);
          if (in_stack_00000020 != *(CMwNod **)(this + 0x94)) {
            if (in_stack_00000020 != (CMwNod *)0x0) {
              CMwNod::MwAddRef(in_stack_00000020,(CMwNod *)pCVar12);
            }
            if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
              CMwNod::MwRelease(*(CMwNod **)(this + 0x94),(CMwNod *)pCVar12);
            }
            *(CMwNod **)(this + 0x94) = in_stack_00000020;
          }
        }
      }
      if (in_stack_0000001c != (CSystemEngine *)0x0) {
        (**(code **)(**(int **)(this + 0x90) + 0x7c))();
      }
      if ((((*(byte *)(*(int *)(this + 0x94) + 0x29) & 1) != 0) && (DAT_00d123b8 >> 0x10 < 3)) &&
         ((*(int **)(this + 0x90))[5] == 0)) {
        (**(code **)(**(int **)(this + 0x90) + 0xf4))();
      }
    }
  }
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CPlugTree::TransformByNOMat
// =================================================
void __thiscall CPlugTree::TransformByNOMat(CPlugTree *this,GmSurfMesh *param_1,GmIso4 *param_2)
{
{
  CPlugSurfaceGeom *this_00;
  uint uVar1;
  int *piVar2;
  int iVar3;
  GmIso3 *unaff_EBX;
  int unaff_ESI;
  GmIso3 *pGVar4;
  uint uVar5;
  GmMat43 *unaff_EDI;
  undefined4 *puVar6;
  GmIso3 *in_stack_0000000c;
  GmIso4 *in_stack_ffffffd0;
  undefined4 local_28;
  GmSurfMesh local_24 [32];
  undefined4 local_4;
  
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x10000;
  if ((*(uint *)(this + 0x9c) & 4) == 0) {
    GmIso4::SetIdentity(this + 0x5c,unaff_EDI);
    SetUseLocation(this,(CPlugTree *)0x1,unaff_ESI);
  }
  pGVar4 = in_stack_0000000c;
  puVar6 = &local_28;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *(undefined4 *)pGVar4;
    pGVar4 = pGVar4 + 4;
    puVar6 = puVar6 + 1;
  }
  local_4 = 0;
  GmVec3::Mult(this + 0x80,in_stack_0000000c,unaff_EBX);
  if (*(int **)(this + 0x90) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x90) + 0x108))(local_24);
  }
  if ((*(int *)(this + 0x8c) != 0) &&
     (this_00 = *(CPlugSurfaceGeom **)(*(int *)(this + 0x8c) + 0x14),
     this_00 != (CPlugSurfaceGeom *)0x0)) {
    CPlugSurfaceGeom::TransformByNOMat(this_00,local_24,in_stack_ffffffd0);
  }
  uVar1 = (**(code **)(*(int *)this + 0x7c))();
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)(**(code **)(*(int *)this + 0x80))(uVar5);
      (**(code **)(*piVar2 + 0xc4))(&local_28);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  return;
}
}

// =================================================
// Function: CPlugTree::UpdateBoundingBox
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall CPlugTree::UpdateBoundingBox(CPlugTree *this,CPlugTree *param_1,int param_2)
{
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int unaff_EBX;
  uint uVar4;
  int unaff_EBP;
  int *piVar5;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  uVar2 = (**(code **)(*(int *)this + 0x7c))();
  iVar3 = (**(code **)(*(int *)this + 0xcc))(param_1,&iStack_18);
  if (iVar3 == 0) {
    if (uVar2 == 0) {
      *(undefined4 *)(this + 0x3c) = 0;
      *(undefined4 *)(this + 0x38) = 0;
      *(undefined4 *)(this + 0x34) = 0;
      uVar1 = _DAT_00b2c060;
      *(undefined4 *)(this + 0x40) = _DAT_00b2c060;
      *(undefined4 *)(this + 0x44) = uVar1;
      *(undefined4 *)(this + 0x48) = uVar1;
      return ~(*(uint *)(this + 0x9c) >> 3) & 1;
    }
    uVar4 = 0;
    piVar5 = (int *)0x0;
    if (uVar2 != 0) {
      do {
        piVar5 = (int *)(**(code **)(*(int *)this + 0x80))(uVar4);
        iVar3 = (**(code **)(*piVar5 + 0xbc))(uStack_8);
        if ((iVar3 != 0) && (0.0 <= (float)piVar5[0x10])) break;
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
    }
    if (uVar4 == uVar2) {
      *(undefined4 *)(this + 0x3c) = 0;
      *(undefined4 *)(this + 0x38) = 0;
      *(undefined4 *)(this + 0x34) = 0;
      uVar1 = _DAT_00b2c060;
      *(undefined4 *)(this + 0x40) = _DAT_00b2c060;
      *(undefined4 *)(this + 0x44) = uVar1;
      *(undefined4 *)(this + 0x48) = uVar1;
      return 0;
    }
    uVar4 = uVar4 + 1;
    unaff_EBP = piVar5[0xd];
    unaff_EBX = piVar5[0xe];
    iStack_18 = piVar5[0xf];
    iStack_14 = piVar5[0x10];
    iStack_10 = piVar5[0x11];
    iStack_c = piVar5[0x12];
  }
  else {
    uVar4 = 0;
  }
  for (; uVar4 < uVar2; uVar4 = uVar4 + 1) {
    piVar5 = (int *)(**(code **)(*(int *)this + 0x80))(uVar4);
    iVar3 = (**(code **)(*piVar5 + 0xbc))(uStack_8);
    if ((iVar3 != 0) && (0.0 <= (float)piVar5[0x10])) {
      GmBoxAligned::Union(&stack0xffffffe0,(GmRectAligned *)(piVar5 + 0xd),(GmVec2 *)param_1);
    }
  }
  if (((byte)this[0x9c] & 4) != 0) {
    GmBoxAligned::SetMult
              (this + 0x34,(SPlugFaceCull *)&stack0xffffffe0,(SPlugFaceCull *)(this + 0x5c),
               (GmIso4 *)param_1);
    return 1;
  }
  *(int *)(this + 0x34) = unaff_EBP;
  *(int *)(this + 0x38) = unaff_EBX;
  *(int *)(this + 0x3c) = iStack_18;
  *(int *)(this + 0x40) = iStack_14;
  *(int *)(this + 0x44) = iStack_10;
  *(int *)(this + 0x48) = iStack_c;
  return 1;
}
}

// =================================================
// Function: CPlugTree::VirtualParam_Get
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CPlugTree::VirtualParam_Get
          (CPlugTree *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  CMwParamVec3 *this_00;
  CMwParamFastBuffer<class_CMwParamIso4> *this_01;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 < 0x904f00d) {
    if (uVar3 == 0x904f00c) {
      iVar1 = *(int *)(this + 0x1c);
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (uint)(iVar1 != 0);
      return 0;
    }
    switch(uVar3) {
    case 0x904f001:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 3 & 1;
      return 0;
    case 0x904f002:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 7 & 1;
      return 0;
    case 0x904f003:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 0xf & 1;
      return 0;
    case 0x904f004:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 9 & 1;
      return 0;
    case 0x904f005:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 10 & 1;
      return 0;
    case 0x904f006:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 2 & 1;
      return 0;
    case 0x904f007:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 0xe & 1;
      return 0;
    case 0x904f008:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 8 & 1;
      return 0;
    case 0x904f009:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 6 & 1;
      return 0;
    case 0x904f00a:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 0xb & 1;
      return 0;
    case 0x904f00b:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) & 1;
      return 0;
    }
  }
  else {
    if (0x904f014 < uVar3) {
      if (uVar3 < 0x904f01e) {
        if (uVar3 != 0x904f01d) {
          if (uVar3 == 0x904f015) {
            *(CMwStack **)param_2 = param_2 + 4;
            *(uint *)(param_2 + 4) = (uint)*(ushort *)(this + 0x56);
            return 0;
          }
          goto switchD_0084af77_default;
        }
        this_00 = (CMwParamVec3 *)(this + 0x34);
      }
      else {
        if (uVar3 != 0x904f01e) {
          if (uVar3 == 0x904f01f) {
            this_01 = *(CMwParamFastBuffer<class_CMwParamIso4> **)(this + 0xa4);
            if (this_01 == (CMwParamFastBuffer<class_CMwParamIso4> *)0x0) {
              this_01 = (CMwParamFastBuffer<class_CMwParamIso4> *)&DAT_00d6e6a8;
            }
            CMwParamFastBuffer<class_CMwParamIso4>::GetValue
                      (this_01,(CFuncColorGradient *)this_01,(float)param_1);
            return 0;
          }
          if (uVar3 == 0xffffffff) {
            return 0;
          }
          goto switchD_0084af77_default;
        }
        this_00 = (CMwParamVec3 *)(this + 0x40);
      }
      CMwParamVec3::GetValue(this_00,(CFuncColorGradient *)this_00,(float)param_1);
      return 0;
    }
    if (uVar3 == 0x904f014) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (uint)*(ushort *)(this + 0x54);
      return 0;
    }
    switch(uVar3) {
    case 0x904f00d:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 0xd & 1;
      return 0;
    case 0x904f00e:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 0xc & 1;
      return 0;
    case 0x904f011:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x54) & 0xfff;
      return 0;
    case 0x904f012:
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x54) >> 0xc & 0xfff;
      return 0;
    case 0x904f013:
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = (float)(byte)this[0x57] / (float)_DAT_00b55d50;
      return 0;
    }
  }
switchD_0084af77_default:
  *(int *)(param_1 + 0x18) = iVar1;
  uVar4 = CMwNod::VirtualParam_Get((CMwNod *)this,param_1,param_2,param_3);
  return uVar4;
}
}

// =================================================
// Function: CPlugTree::VirtualParam_Set
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CPlugTree::VirtualParam_Set(CPlugTree *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  CMwParamClass *this_00;
  int iVar1;
  CMwClassInfo *pCVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  CPlugShader *unaff_EBX;
  ulong unaff_EBP;
  void *pvVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  uint uVar8;
  float fVar9;
  CPlugMaterial *pCVar10;
  CPlugShader *pCVar11;
  
  iVar5 = *(int *)(param_1 + 0x18);
  iVar1 = (*(int **)(param_1 + 0x10))[iVar5];
  this_00 = (CMwParamClass *)(iVar5 + -1);
  *(CMwParamClass **)(param_1 + 0x18) = this_00;
  uVar8 = *(uint *)(iVar1 + 4);
  if (uVar8 < 0x904f012) {
    if (uVar8 == 0x904f011) {
      uVar8 = *(uint *)param_2;
      uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                        ((void *)(*(int *)(this + 0x90) + 100),unaff_EDI);
      if (uVar4 != 0) {
        uVar4 = uVar4 - 1;
      }
      if (uVar8 <= uVar4) {
        uVar4 = uVar8;
      }
      *(uint *)(this + 0x54) = *(uint *)(this + 0x54) ^ (*(uint *)(this + 0x54) ^ uVar4) & 0xfff;
      return 0;
    }
    switch(uVar8) {
    case 0x904f001:
      *(uint *)(this + 0x9c) =
           *(uint *)(this + 0x9c) ^ ((uint)(*(int *)param_2 != 0) * 8 ^ *(uint *)(this + 0x9c)) & 8;
      return 0;
    case 0x904f002:
      *(uint *)(this + 0x9c) =
           *(uint *)(this + 0x9c) ^
           ((uint)(*(int *)param_2 != 0) << 7 ^ *(uint *)(this + 0x9c)) & 0x80;
      return 0;
    case 0x904f003:
      SetIsRooted(this,*(CPlugTree **)param_2,(int)unaff_EDI);
      return 0;
    case 0x904f004:
      *(uint *)(this + 0x9c) =
           *(uint *)(this + 0x9c) ^
           ((uint)(*(int *)param_2 != 0) << 9 ^ *(uint *)(this + 0x9c)) & 0x200;
      return 0;
    case 0x904f005:
      *(uint *)(this + 0x9c) =
           *(uint *)(this + 0x9c) ^
           ((uint)(*(int *)param_2 != 0) << 10 ^ *(uint *)(this + 0x9c)) & 0x400;
      return 0;
    case 0x904f006:
      *(uint *)(this + 0x9c) =
           *(uint *)(this + 0x9c) ^ ((uint)(*(int *)param_2 != 0) * 4 ^ *(uint *)(this + 0x9c)) & 4;
      return 0;
    case 0x904f007:
      *(uint *)(this + 0x9c) =
           *(uint *)(this + 0x9c) ^
           ((uint)(*(int *)param_2 != 0) << 0xe ^ *(uint *)(this + 0x9c)) & 0x4000;
      return 0;
    case 0x904f008:
      *(uint *)(this + 0x9c) =
           *(uint *)(this + 0x9c) ^
           ((uint)(*(int *)param_2 != 0) << 8 ^ *(uint *)(this + 0x9c)) & 0x100;
      return 0;
    case 0x904f009:
      *(uint *)(this + 0x9c) =
           *(uint *)(this + 0x9c) ^
           ((uint)(*(int *)param_2 != 0) << 6 ^ *(uint *)(this + 0x9c)) & 0x40;
      return 0;
    case 0x904f00a:
      *(uint *)(this + 0x9c) =
           *(uint *)(this + 0x9c) ^
           ((uint)(*(int *)param_2 != 0) << 0xb ^ *(uint *)(this + 0x9c)) & 0x800;
      return 0;
    case 0x904f00b:
      *(uint *)(this + 0x9c) =
           *(uint *)(this + 0x9c) ^ ((uint)(*(int *)param_2 != 0) ^ *(uint *)(this + 0x9c)) & 1;
      return 0;
    default:
      goto switchD_0084cfeb_caseD_904f00c;
    case 0x904f00d:
      *(uint *)(this + 0x9c) =
           *(uint *)(this + 0x9c) ^
           ((uint)(*(int *)param_2 != 0) << 0xd ^ *(uint *)(this + 0x9c)) & 0x2000;
      return 0;
    case 0x904f00e:
      *(uint *)(this + 0x9c) =
           *(uint *)(this + 0x9c) ^
           ((uint)(*(int *)param_2 != 0) << 0xc ^ *(uint *)(this + 0x9c)) & 0x1000;
      return 0;
    case 0x904f010:
      if ((int)this_00 < 0) {
        SetVisual(this,(CVisionVisualKeeper *)param_2,(CPlugVisual *)0x0);
        return 0;
      }
      pvVar7 = param_3;
      if (((**(int **)(param_1 + 0x14) == 0) &&
          (pCVar2 = *(CMwClassInfo **)(**(int **)(param_1 + 0x10) + 4),
          ((uint)pCVar2 & 0xfffff000) == 0x9010000)) &&
         (iVar5 = CMwClassInfo::IsMwParamIdEqualName
                            ((CMwClassInfo *)PTR_DAT_00bb1e5c,pCVar2,0xb95dd0,(char *)0x1,
                             (int)unaff_EDI), iVar5 != 0)) {
        pvVar7 = (void *)(*(uint *)(*(int *)(this + 0x90) + 0xb0) & 7);
      }
      CMwParamClass::SetValue(param_3,(CMwCmdAffectParamBool *)(this + 0x90));
      if (((param_3 != (void *)0x0) &&
          (pvVar3 = (void *)(*(uint *)(*(int *)(this + 0x90) + 0xb0) & 7), pvVar3 != pvVar7)) &&
         (pvVar3 != (void *)0x0)) {
        pCVar11 = ChangeShaderClass(this,(CPlugTree *)0x9026000,unaff_EBP);
        CPlugShader::RemovePasses(pCVar11,unaff_EBX);
        return 0;
      }
    }
  }
  else if (uVar8 < 0x904f019) {
    if (uVar8 == 0x904f018) {
      if (-1 < (int)this_00) {
        CMwParamClass::SetValue(this_00,(CMwCmdAffectParamBool *)(this + 0x94));
        return 0;
      }
      if ((*(int *)(this + 0x94) != 0) && (param_2 != (CMwStack *)0x0)) {
        pCVar11 = (CPlugShader *)0x9002000;
        iVar5 = (**(code **)(*(int *)param_2 + 0x10))();
        if (iVar5 != 0) {
          SetShader(this,(CPlugBitmapShader *)param_2,pCVar11);
          return 0;
        }
        pCVar10 = (CPlugMaterial *)0x9079000;
        iVar5 = (**(code **)(*(int *)param_2 + 0x10))();
        if (iVar5 != 0) {
          SetMaterial(this,(CPlugMaterialCustom *)param_2,pCVar10);
          return 0;
        }
      }
    }
    else {
      switch(uVar8) {
      case 0x904f012:
        uVar8 = *(uint *)param_2;
        uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                          ((void *)(*(int *)(this + 0x90) + 100),unaff_EDI);
        if (uVar4 != 0) {
          uVar4 = uVar4 - 1;
        }
        if (uVar8 <= uVar4) {
          uVar4 = uVar8;
        }
        *(uint *)(this + 0x54) =
             *(uint *)(this + 0x54) ^ (uVar4 << 0xc ^ *(uint *)(this + 0x54)) & 0xfff000;
        return 0;
      case 0x904f013:
        fVar9 = GmFunc::ClampReal(*(float *)param_2 * (float)_DAT_00b55d50,0.0,_DAT_00b5e844);
        param_1._0_1_ = SUB41((int)ROUND(fVar9),0);
        this[0x57] = param_1._0_1_;
        return 0;
      case 0x904f014:
        uVar8 = *(uint *)param_2;
        uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                          ((void *)(*(int *)(this + 0x90) + 0x20),unaff_EDI);
        if (uVar4 != 0) {
          uVar4 = uVar4 - 1;
        }
        if (uVar8 <= uVar4) {
          uVar4 = uVar8;
        }
        *(short *)(this + 0x54) = (short)uVar4;
        return 0;
      case 0x904f015:
        uVar8 = *(uint *)param_2;
        uVar6 = CFastBuffer<class_CCrystalFace*>::GetCount
                          ((void *)(*(int *)(this + 0x90) + 0x20),unaff_EDI);
        if (uVar8 < 2) {
          *(undefined2 *)(this + 0x56) = 1;
          return 0;
        }
        if (uVar6 <= uVar8) {
          uVar8 = uVar6;
        }
        *(short *)(this + 0x56) = (short)uVar8;
        return 0;
      case 0x904f016:
        if (-1 < (int)this_00) {
          CMwParamClass::SetValue((CMwParamClass *)param_2,(CMwCmdAffectParamBool *)(this + 0xa0));
          return 0;
        }
        if (param_2 != (CMwStack *)0x0) {
          SetGenerator(this,(CPlugTree *)param_2,(CPlugTreeGenerator *)0x1,(int)unaff_EDI);
          return 0;
        }
        SetGenerator(this,(CPlugTree *)0x0,(CPlugTreeGenerator *)0x0,(int)unaff_EDI);
        return 0;
      case 0x904f017:
        if (-1 < (int)this_00) {
          CMwParamClass::SetValue(this_00,(CMwCmdAffectParamBool *)(this + 0x98));
          return 0;
        }
        if ((*(int *)(this + 0x94) != 0) && (param_2 != (CMwStack *)0x0)) {
          SetMaterial(this,(CPlugMaterialCustom *)param_2,(CPlugMaterial *)unaff_EDI);
          return 0;
        }
        break;
      default:
        goto switchD_0084cfeb_caseD_904f00c;
      }
    }
  }
  else if (uVar8 < 0x904f01d) {
    if (uVar8 != 0x904f01c) {
      if (uVar8 == 0x904f019) {
        if ((int)this_00 < 0) {
          SetSurface(this,(CPlugTree *)param_2,(CPlugSurface *)unaff_EDI);
          return 0;
        }
        CMwParamClass::SetValue(this_00,(CMwCmdAffectParamBool *)(this + 0x8c));
        return 0;
      }
      if (uVar8 == 0x904f01a) {
        (**(code **)(*(int *)this + 0xbc))(1);
        return 0;
      }
      if (uVar8 == 0x904f01b) {
        (**(code **)(*(int *)this + 0x78))(1);
        return 0;
      }
switchD_0084cfeb_caseD_904f00c:
      *(int *)(param_1 + 0x18) = iVar5;
      uVar6 = CMwNod::VirtualParam_Set((CMwNod *)this,param_1,param_2,unaff_EDI);
      return uVar6;
    }
    if ((int)this_00 < 0) {
      SetFuncTree(this,(CPlugTree *)param_2,(CFuncTree *)unaff_EDI);
      return 0;
    }
    if (*(int *)(this + 0xa8) != 0) {
      CMwParamClass::SetValue((CMwParamClass *)param_2,(CMwCmdAffectParamBool *)(this + 0xa8));
      return 0;
    }
  }
  else if (uVar8 == 0x904f01f) {
    CMwParamFastBuffer<class_CMwParamIso4>::SetValue
              ((CMwParamFastBuffer<class_CMwParamIso4> *)this_00,
               *(CMwCmdAffectParamBool **)(this + 0xa4));
  }
  else if (uVar8 != 0xffffffff) goto switchD_0084cfeb_caseD_904f00c;
  return 0;
}
}

// =================================================
// Function: CPlugTree::VirtualParam_Sub
// =================================================
ulong __thiscall
CPlugTree::VirtualParam_Sub
          (CPlugTree *this,CGameCtnDecorationMood *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0x904f000) {
    if (iVar1 + -1 < 0) {
      (**(code **)(*(int *)this + 0x9c))(*(undefined4 *)param_2);
      return 0;
    }
    CMwParamFastBuffer<class_CMwParamClass>::SubValue
              ((CFastBufferCat<class_GmVec2,struct_SFastCat> *)(this + 0x28),(CMwStack *)param_1,
               param_2);
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CMwNod::VirtualParam_Sub((CMwNod *)this,param_1,param_2,param_3);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CPlugTree::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CPlugTree::_scalar_deleting_destructor_(CPlugTree *this,CPfmHeap *param_1,uint param_2)
{
{
  CPlugTree *unaff_ESI;
  
  ~CPlugTree(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CPlugTree::~CPlugTree
// =================================================
void __thiscall CPlugTree::~CPlugTree(CPlugTree *this,CPlugTree *param_1)
{
{
  CMwNod *pCVar1;
  CMwNod *unaff_ESI;
  CPlugTreeVisualMip *unaff_EDI;
  void *in_stack_00000008;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar2;
  CFastBuffer<class_CPlugFileGPUV*> *this_00;
  CPlug *pCVar3;
  
  pCVar3 = ExceptionList;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &stack0xfffffff4;
  *(undefined ***)this = vftable;
  pCVar2 = (CFastBuffer<class_CPlugFileGPUV*> *)this;
  if (*(CMwNod **)(this + 0x1c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1c),pCVar1);
  }
  DeleteAllChilds(this,unaff_EDI);
  if (*(int *)(this + 0xc) != 0) {
    CMwNod::DependantSendMwIsKilled((CMwNod *)this,unaff_ESI);
  }
  if (*(void **)(this + 0x58) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x58));
  }
  this_00 = *(CFastBuffer<class_CPlugFileGPUV*> **)(this + 0xa4);
  if (this_00 != (CFastBuffer<class_CPlugFileGPUV*> *)0x0) {
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this_00,pCVar2);
    operator_delete(this_00);
    pCVar2 = this_00;
  }
  CPlugTreeMapShaderFill::SubTree(this);
  if (*(CMwNod **)(this + 0xa8) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xa8),(CMwNod *)pCVar2);
  }
  if (*(CMwNod **)(this + 0xa0) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xa0),(CMwNod *)pCVar2);
  }
  if (*(CMwNod **)(this + 0x98) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x98),(CMwNod *)pCVar2);
  }
  if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x94),(CMwNod *)pCVar2);
  }
  if (*(CMwNod **)(this + 0x90) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x90),(CMwNod *)pCVar2);
  }
  in_stack_00000008 = (void *)CONCAT31(in_stack_00000008._1_3_,3);
  if (*(CMwNod **)(this + 0x8c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x8c),(CMwNod *)pCVar2);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x28,pCVar2);
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar3);
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar3);
  CPlug::~CPlug((CPlug *)this,pCVar3);
  ExceptionList = in_stack_00000008;
  return;
}
}

