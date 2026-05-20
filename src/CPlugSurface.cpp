// Class implementation: CPlugSurface

// =================================================
// Function: CPlugSurface::CPlugSurface
// =================================================
void __thiscall CPlugSurface::CPlugSurface(CPlugSurface *this,CPlugSurface *param_1)
{
{
  CPlug *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  
  CPlug::CPlug((CPlug *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x18,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CPlugSurface::Chunk
// =================================================
void __thiscall
CPlugSurface::Chunk(CPlugSurface *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  int iVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  CPlugSurface *this_00;
  CClassicArchive *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  GxTexCoordSet *unaff_ESI;
  SCasterCat *unaff_EDI;
  CPlugSurface *in_stack_00000010;
  undefined4 in_stack_00000014;
  CMwNod *pCVar5;
  CPlugSurface *pCVar6;
  ulong in_stack_fffffff4;
  CMwNod *in_stack_fffffff8;
  CMwNod *in_stack_fffffffc;
  
  if (param_2 == (CClassicArchive *)0x900c000) {
    param_2 = *(CClassicArchive **)(this + 0x14);
    pCVar5 = (CMwNod *)&param_2;
    (**(code **)(*(int *)param_1 + 4))();
    if (param_1 != *(CFuncSegment **)(this + 0x14)) {
      if (param_1 != (CFuncSegment *)0x0) {
        CMwNod::MwAddRef((CMwNod *)param_1,pCVar5);
      }
      if (*(CMwNod **)(this + 0x14) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x14),pCVar5);
      }
      *(CFuncSegment **)(this + 0x14) = param_1;
    }
    this_00 = this + 0x18;
    pCVar6 = this_00;
    CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>::ArchiveCount
              (this_00,(CFastArray<class_CPlugFileSnd*> *)param_1,unaff_EBP);
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this_00,(CFastBuffer<class_CCrystalFace*> *)pCVar5);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        if (*(int *)(param_1 + 8) != 0) {
          unaff_EDI = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                (this_00,pCVar4,(ulong)unaff_EDI);
          iVar2 = CFastArray<class_CGameMenuFrame*>::Find
                            (&DAT_00d6efb8,(CFastArray<class_GxTexCoordSet> *)unaff_EDI,unaff_ESI);
          in_stack_00000010 = (CPlugSurface *)(uint)(iVar2 == -1);
        }
        CClassicArchive::DoBool
                  ((CClassicArchive *)param_1,(CClassicArchive *)&param_2,(int *)0x1,
                   (ulong)unaff_EDI);
        if (param_3 == 0) {
          if (*(int *)(param_1 + 8) != 0) {
            pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar4,(ulong)unaff_ESI);
            in_stack_fffffffc = (CMwNod *)(uint)*(byte *)(*(int *)pSVar3 + 0x18);
          }
          unaff_ESI = (GxTexCoordSet *)0x0;
          unaff_EDI = (SCasterCat *)0x1;
          CClassicArchive::DoNat16
                    ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffffc,(ushort *)0x1,0,
                     unaff_EBX);
          if (*(int *)(param_1 + 8) == 0) {
            unaff_ESI = (GxTexCoordSet *)0x8bd742;
            pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (&DAT_00d6efb8,
                                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                ((uint)pCVar1 & 0xffff),(ulong)pCVar6);
            pCVar5 = *(CMwNod **)pSVar3;
            unaff_EBX = 0x8bd74c;
            pCVar6 = (CPlugSurface *)pCVar4;
            pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar4,in_stack_fffffff4);
            this_00 = in_stack_00000010;
            if (pCVar5 != *(CMwNod **)pSVar3) {
              if (pCVar5 != (CMwNod *)0x0) {
                in_stack_fffffff4 = 0x8bd75d;
                CMwNod::MwAddRef(pCVar5,in_stack_fffffff8);
              }
              if (*(CMwNod **)pSVar3 != (CMwNod *)0x0) {
                in_stack_fffffff8 = (CMwNod *)0x8bd768;
                CMwNod::MwRelease(*(CMwNod **)pSVar3,in_stack_fffffffc);
              }
              *(CMwNod **)pSVar3 = pCVar5;
              this_00 = in_stack_00000010;
            }
          }
        }
        else {
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar4,(ulong)unaff_ESI);
          in_stack_00000014 = *(undefined4 *)pSVar3;
          unaff_ESI = (GxTexCoordSet *)&stack0x00000014;
          unaff_EDI = (SCasterCat *)0x8bd6d8;
          (**(code **)(*(int *)param_1 + 4))();
          in_stack_fffffffc = (CMwNod *)param_3;
          if (param_3 != *(ulong *)pSVar3) {
            if (param_3 != 0) {
              CMwNod::MwAddRef((CMwNod *)param_3,(CMwNod *)unaff_EDI);
            }
            if (*(CMwNod **)pSVar3 != (CMwNod *)0x0) {
              CMwNod::MwRelease(*(CMwNod **)pSVar3,(CMwNod *)unaff_EDI);
            }
            *(CMwNod **)pSVar3 = in_stack_fffffffc;
          }
        }
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar1);
    }
  }
  else if (param_2 != (CClassicArchive *)0xffffffff) {
    CMwNod::Chunk((CMwNod *)this,param_1,param_2,unaff_EBX);
    return;
  }
  return;
}
}

// =================================================
// Function: CPlugSurface::ComputeCollision
// =================================================
int __cdecl
CPlugSurface::ComputeCollision
          (LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3)
{
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  SCasterCat *pSVar4;
  ulong uVar5;
  uint uVar6;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar1 = (**(code **)(*(int *)param_2 + 8))();
  uStack_18 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x14) + 0x34);
  uStack_14 = *(undefined4 *)(param_1 + 0xc);
  uStack_10 = 1;
  uStack_c = *(undefined4 *)(*(int *)(*(int *)param_1 + 0x14) + 0x34);
  uStack_8 = *(undefined4 *)(param_1 + 4);
  uStack_4 = 1;
  iVar2 = GmSurf::ComputeCollision
                    ((LocatedGmSurf *)&uStack_c,(LocatedGmSurf *)&uStack_18,
                     (CGmCollisionBuffer *)param_2);
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = (**(code **)(*(int *)param_2 + 8))();
  for (; uVar1 < uVar3; uVar1 = uVar1 + 1) {
    uVar5 = 0x5371da;
    uVar6 = uVar1;
    iVar2 = (**(code **)(*(int *)param_2 + 4))();
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)param_1 + 0x18),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        (uint)*(ushort *)(iVar2 + 0x24),uVar5);
    *(ushort *)(iVar2 + 0x24) = (ushort)*(byte *)(*(int *)pSVar4 + 0x18);
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(param_1 + 8) + 0x18),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        (uint)*(ushort *)(iVar2 + 0x26),uVar6);
    *(ushort *)(iVar2 + 0x26) = (ushort)*(byte *)(*(int *)pSVar4 + 0x18);
  }
  return 1;
}
}

// =================================================
// Function: CPlugSurface::GetChunkInfo
// =================================================
ulong __thiscall CPlugSurface::GetChunkInfo(CPlugSurface *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 == (CFuncSegment *)0x900c000) {
    return 3;
  }
  if (param_1 != (CFuncSegment *)0xffffffff) {
    uVar1 = CMwNod::GetChunkInfo((CMwNod *)this,param_1,param_2);
    return uVar1;
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CPlugSurface::GetMwClassId
// =================================================
ulong __thiscall CPlugSurface::GetMwClassId(CPlugSurface *this,CControlStyle *param_1)
{
{
  return 0x900c000;
}
}

// =================================================
// Function: CPlugSurface::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CPlugSurface::GetUidChunkFromIndex(CPlugSurface *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0x900c000;
}
}

// =================================================
// Function: CPlugSurface::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CPlugSurface::MwGetClassInfo(CPlugSurface *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d6fb74;
}
}

// =================================================
// Function: CPlugSurface::MwIsKindOf
// =================================================
int __thiscall CPlugSurface::MwIsKindOf(CPlugSurface *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if ((param_1 != (CMwCmdAffectParam *)0x900c000) && (param_1 != (CMwCmdAffectParam *)0x902b000)) {
    return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
  }
  return 1;
}
}

// =================================================
// Function: CPlugSurface::MwNewCPlugSurface
// =================================================
CMwNod * __cdecl CPlugSurface::MwNewCPlugSurface(void)
{
{
  CPlugSurface *pCVar1;
  CMwNod *extraout_EAX;
  CPlugSurface *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00adb9bb;
  local_c = ExceptionList;
  pCVar1 = (CPlugSurface *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x24);
  local_4 = 0;
  if (local_10 != (CPlugSurface *)0x0) {
    CPlugSurface(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CPlugSurface::StaticInit
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CPlugSurface::StaticInit(void)
{
{
  undefined4 uVar1;
  GmFrustumIso4 *pGVar2;
  uint uVar3;
  CMwNod *extraout_EAX;
  SLoadedLight *pSVar4;
  CMwNod *unaff_EBX;
  uint uVar5;
  CPlugShader *unaff_ESI;
  CMwNod *this;
  CPlugMaterial *unaff_EDI;
  CPlugMaterial *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00adb98b;
  local_c = ExceptionList;
  pGVar2 = (GmFrustumIso4 *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  GmSurf::StaticInit();
  uVar1 = _DAT_00b31460;
  uVar5 = 0;
  do {
    uVar3 = uVar5 + 8;
    *(undefined4 *)((int)&DAT_00d6eec4 + uVar5) = uVar1;
    *(undefined4 *)((int)&DAT_00d6eec0 + uVar5) = 0x3f800000;
    uVar5 = uVar3;
  } while (uVar3 < 0xf8);
  _DAT_00d6eedc = 0;
  _DAT_00d6eed8 = 0;
  _DAT_00d6ef14 = _DAT_00b36158;
  _DAT_00d6ef10 = 0;
  _DAT_00d6ef0c = 0;
  _DAT_00d6ef08 = 0;
  _DAT_00d6ef1c = 0;
  _DAT_00d6ef18 = 0;
  _DAT_00d6ef7c = _DAT_00b362a4;
  _DAT_00d6ef78 = 0x3f800000;
  _DAT_00d6ef84 = _DAT_00b41140;
  _DAT_00d6ef8c = _DAT_00b41140;
  _DAT_00d6ef80 = 0x3f800000;
  _DAT_00d6ef88 = 0x3f800000;
  CFastBufferRef<class_CPlugMaterial>::Reset(&DAT_00d6efb8,pGVar2);
  uVar5 = 0;
  do {
    local_c = operator_new(0x38);
    this = (CMwNod *)0x0;
    if (local_c != (CPlugMaterial *)0x0) {
      CPlugMaterial::CPlugMaterial(local_c,unaff_EDI,unaff_ESI);
      this = extraout_EAX;
    }
    pSVar4 = CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>::AddNewElem
                       (&DAT_00d6efb8,
                        (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)unaff_EDI);
    if (this != *(CMwNod **)pSVar4) {
      if (this != (CMwNod *)0x0) {
        unaff_EDI = (CPlugMaterial *)0x8bd8f7;
        CMwNod::MwAddRef(this,(CMwNod *)unaff_ESI);
      }
      if (*(CMwNod **)pSVar4 != (CMwNod *)0x0) {
        unaff_ESI = (CPlugShader *)0x8bd902;
        CMwNod::MwRelease(*(CMwNod **)pSVar4,unaff_EBX);
      }
      *(CMwNod **)pSVar4 = this;
    }
    this[0x18] = SUB41(uVar5,0);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x1f);
  ExceptionList = puStack_8;
  return;
}
}

// =================================================
// Function: CPlugSurface::StaticRelease
// =================================================
void __cdecl CPlugSurface::StaticRelease(void)
{
{
  CFastBuffer<struct_SInputActionDesc_const*> *in_stack_00000004;
  
  CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>::ResetAndFreeMemory
            (&DAT_00d6efb8,in_stack_00000004);
  return;
}
}

// =================================================
// Function: CPlugSurface::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CPlugSurface::_scalar_deleting_destructor_(CPlugSurface *this,CPfmHeap *param_1,uint param_2)
{
{
  CPlugSurface *unaff_ESI;
  
  ~CPlugSurface(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CPlugSurface::~CPlugSurface
// =================================================
void __thiscall CPlugSurface::~CPlugSurface(CPlugSurface *this,CPlugSurface *param_1)
{
{
  CFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_> *pCVar1;
  CMwNod *unaff_ESI;
  uint unaff_retaddr;
  CPlugSurface *pCVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00adb963;
  local_c = ExceptionList;
  pCVar1 = (CFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_> *)
           (DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 1;
  pCVar2 = this;
  CFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_>::
  ~CFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_>(this + 0x18,pCVar1);
  if (*(CMwNod **)(this + 0x14) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x14),unaff_ESI);
  }
  CPlug::~CPlug((CPlug *)this,(CPlug *)pCVar2);
  ExceptionList = (void *)(unaff_retaddr & 0xffffff00);
  return;
}
}

