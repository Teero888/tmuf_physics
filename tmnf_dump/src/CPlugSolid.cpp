// Class implementation: CPlugSolid

// =================================================
// Function: CPlugSolid::AddTree
// =================================================
void __cdecl CPlugSolid::AddTree(CPlugTree *param_1)
{
{
  CMwNod *this;
  undefined1 *puVar1;
  CPlugTree *pCVar2;
  CPlugSolid *pCVar3;
  CPlugSolid *extraout_EAX;
  CPlugSolid *pCVar4;
  int iVar5;
  CPlugSolid *extraout_EAX_00;
  CPlugSolid *in_ECX;
  CMwNod *unaff_ESI;
  int unaff_EDI;
  int *in_stack_0000000c;
  void *pvVar6;
  undefined1 *puVar7;
  
  puVar7 = &LAB_00ad5536;
  pCVar2 = (CPlugTree *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  puVar1 = &stack0xfffffff4;
  pCVar3 = in_ECX;
  pvVar6 = ExceptionList;
  if (*(int *)(in_ECX + 100) == 0) {
    ExceptionList = &stack0xfffffff4;
    pCVar3 = operator_new(0xac);
    if (pCVar3 == (CPlugSolid *)0x0) {
      pCVar4 = (CPlugSolid *)0x0;
    }
    else {
      CPlugTree::CPlugTree((CPlugTree *)pCVar3,pCVar2);
      pCVar4 = extraout_EAX;
    }
    SetTree(in_ECX,pCVar4,(CPlugTree *)0x1,unaff_EDI);
    puVar1 = ExceptionList;
  }
  ExceptionList = puVar1;
  iVar5 = (**(code **)(**(int **)(in_ECX + 100) + 0xc))();
  if (iVar5 != 0x904f000) {
    this = *(CMwNod **)(in_ECX + 100);
    CMwNod::MwAddRef(this,unaff_ESI);
    pCVar2 = operator_new(0xac);
    if (pCVar2 == (CPlugTree *)0x0) {
      pCVar3 = (CPlugSolid *)0x0;
    }
    else {
      CPlugTree::CPlugTree(pCVar2,(CPlugTree *)pCVar3);
      pCVar3 = extraout_EAX_00;
    }
    in_stack_0000000c = (int *)0xffffffff;
    SetTree(in_ECX,pCVar3,(CPlugTree *)0x1,(int)pvVar6);
    pCVar3 = (CPlugSolid *)0x8552b3;
    CMwNod::MwForceRef(this,(CMwNod *)0x0,(ulong)puVar7);
    (**(code **)(**(int **)(in_ECX + 100) + 0x88))();
  }
  (**(code **)(**(int **)(in_ECX + 100) + 0x88))();
  (**(code **)(*in_stack_0000000c + 0xbc))(1);
  (**(code **)(**(int **)(in_ECX + 100) + 0xbc))(0);
  ExceptionList = pCVar3;
  return;
}
}

// =================================================
// Function: CPlugSolid::ApplyFidParameters
// =================================================
void __thiscall
CPlugSolid::ApplyFidParameters
          (CPlugSolid *this,CPlugFontBitmap *param_1,CSystemFidParameters *param_2,
          CSystemFidParameters *param_3,CFastBuffer<struct_CMwNod::SManuallyLoadedFid> *param_4)
{
{
  CPlugTree *pCVar1;
  CSystemFidParameters *this_00;
  int iVar2;
  SParam *pSVar3;
  SParam *pSVar4;
  SParam_Id *pSVar5;
  int local_2c;
  undefined4 local_28;
  SParam_Id aSStack_24 [4];
  SParam_Id local_20 [16];
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  this_00 = param_2;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad5468;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CVisionViewportNull::SetFullScreenGammaRamp
            ((CVisionViewportNull *)this,(CVisionViewportNull *)param_1,(float)param_2,
             (float)param_3,(float)(DAT_00cca150 ^ (uint)&stack0xffffffc8));
  pSVar5 = (SParam_Id *)0x0;
  pSVar4 = (SParam *)0x0;
  pSVar3 = (SParam *)0x0;
  CSystemFidParameters::SParam_Id::SParam_Id(local_20,(SParam_Id *)&DAT_00d6e968);
  local_c = (void *)0x0;
  CSystemFidParameters::GetParamValue
            ((CSystemFidParameters *)param_1,(CSystemFidParameters *)&local_2c,pSVar3);
  CSystemFidParameters::AddParam(this_00,(CSystemFidParameters *)&local_28,pSVar4);
  if ((local_10 != 0) && (*(int *)(this + 0x68) == 0)) {
    if (*(int *)(DAT_00d54380 + 0x20) == 0) {
      iVar2 = *(int *)(DAT_00d54380 + 0x24);
    }
    else {
      iVar2 = *(int *)(DAT_00d54380 + 0x28);
    }
    DAT_00d6e924 = *(undefined4 *)(iVar2 + 0x5c);
    pCVar1 = *(CPlugTree **)(this + 100);
    param_2 = (CSystemFidParameters *)0x0;
    CPlugTree_PackShaderRecur(pCVar1,(ulong *)&param_2);
    if (param_2 != (CSystemFidParameters *)0x0) {
      (**(code **)(*(int *)pCVar1 + 0xbc))(0);
    }
  }
  if (*(int *)(this + 0x68) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(this + 0x68) + 8);
  }
  if (iVar2 != 0) {
    local_28 = 1;
    local_2c = iVar2;
    CFastBuffer<class_GmNat2>::Add(param_3,(TiXmlAttributeSet *)&local_2c,(TiXmlAttribute *)pSVar5);
  }
  uStack_4 = 0xffffffff;
  CSystemFidParameters::SParam_Id::~SParam_Id(aSStack_24,pSVar5);
  ExceptionList = puStack_8;
  return;
}
}

// =================================================
// Function: CPlugSolid::CPlugSolid
// =================================================
void __thiscall CPlugSolid::CPlugSolid(CPlugSolid *this,CPlugSolid *param_1)
{
{
  CPlugPhysicalObject *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ad5358;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CPlug::CPlug((CPlug *)this,(CPlug *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  CPlugPhysicalObject::CPlugPhysicalObject(this + 0x18,unaff_EDI);
  *(undefined4 *)(this + 0x60) = 1;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(uint *)(this + 0x70) = *(uint *)(this + 0x70) | 1;
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CPlugSolid::Chunk
// =================================================
void __thiscall
CPlugSolid::Chunk(CPlugSolid *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  CFuncSegment *this_00;
  CMwNodRef<class_CMwRefBuffer> *pCVar1;
  code *pcVar2;
  GmVec3 *unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CMwNod *unaff_EDI;
  CClassicArchive *unaff_retaddr;
  int in_stack_00000014;
  CPlugSolid *in_stack_00000018;
  CPlugSolid *in_stack_0000001c;
  CPlugSolid *in_stack_00000020;
  CPlugSolid *in_stack_00000024;
  CPlugSolid *in_stack_00000028;
  undefined4 in_stack_0000002c;
  int in_stack_00000030;
  void *in_stack_0000003c;
  int in_stack_0000004c;
  int in_stack_00000058;
  ulong in_stack_ffffffcc;
  ulong uVar3;
  GmVec3 *in_stack_ffffffd0;
  ulong uVar4;
  ulong in_stack_ffffffd4;
  ulong uVar5;
  ulong in_stack_ffffffdc;
  ulong in_stack_ffffffe0;
  int in_stack_ffffffe4;
  ulong in_stack_ffffffe8;
  ulong in_stack_ffffffec;
  ulong in_stack_fffffff0;
  CClassicArchive *pCVar6;
  void *pvVar7;
  undefined1 *puVar8;
  CPlugSolid *pCVar9;
  
  this_00 = param_1;
  pCVar9 = (CPlugSolid *)0xffffffff;
  puVar8 = &LAB_00ad55b0;
  pCVar1 = (CMwNodRef<class_CMwRefBuffer> *)(DAT_00cca150 ^ (uint)&stack0xffffffbc);
  if ((CClassicArchive *)0x900500a < param_2) {
    if (param_2 < (CClassicArchive *)0x9005010) {
      if (param_2 == (CClassicArchive *)0x900500f) {
        ExceptionList = &stack0xfffffff4;
        CClassicArchive::DoReal
                  ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xffffffe0,(float *)0x1,
                   (ulong)pCVar1);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffe8,(float *)0x1,
                   (ulong)unaff_EDI);
        ExceptionList = in_stack_0000003c;
        return;
      }
      switch(param_2) {
      case (CClassicArchive *)0x900500b:
        ExceptionList = &stack0xfffffff4;
        CClassicArchive::DoBool
                  ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(int *)0x1,(ulong)pCVar1);
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffec,(int *)0x1,
                   (ulong)unaff_EDI);
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffe8,(int *)0x1,
                   unaff_ESI);
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffe8,(int *)0x1,
                   unaff_EBP);
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffe8,(int *)0x1,
                   (ulong)unaff_EBX);
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffe8,(int *)0x1,
                   in_stack_ffffffcc);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffe8,(float *)0x1,
                   (ulong)in_stack_ffffffd0);
        CClassicArchive::DoNatural
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffe8,(ulong *)0x1,0,
                   in_stack_ffffffd4);
        ExceptionList = in_stack_0000003c;
        return;
      case (CClassicArchive *)0x900500c:
        uVar4 = 0;
        uVar3 = 0;
        uVar5 = 0;
        pvVar7 = ExceptionList;
        ExceptionList = &stack0xfffffff4;
        CClassicArchive::DoBool
                  ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xffffffcc,(int *)0x1,
                   (ulong)pCVar1);
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffd0,(int *)0x1,
                   (ulong)unaff_EDI);
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffd4,(int *)0x1,
                   unaff_ESI);
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffd8,(int *)0x1,
                   unaff_EBP);
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffdc,(int *)0x1,
                   (ulong)unaff_EBX);
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffe0,(int *)0x1,uVar3);
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffe4,(int *)0x1,uVar4);
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffe8,(int *)0x1,
                   in_stack_ffffffd4);
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffec,(int *)0x1,uVar5);
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xfffffff0,(int *)0x1,
                   in_stack_ffffffdc);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xfffffff8,(float *)0x1,
                   in_stack_ffffffe0);
        CClassicArchive::DoNatural
                  ((CClassicArchive *)this_00,(CClassicArchive *)&param_1,(ulong *)0x1,0,
                   in_stack_ffffffe4);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000000,(float *)0x1,
                   in_stack_ffffffe8);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)&param_1,(float *)0x1,
                   in_stack_ffffffec);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)&param_2,(float *)0x1,
                   in_stack_fffffff0);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)&param_3,(float *)0x1,(ulong)pvVar7
                  );
        CClassicArchive::DoNatural
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000018,(ulong *)0x1,0,
                   (int)puVar8);
        CClassicArchive::DoNatural
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x0000001c,(ulong *)0x1,0,
                   (int)pCVar9);
        ExceptionList = in_stack_0000003c;
        return;
      case (CClassicArchive *)0x900500d:
        goto switchD_008557c0_caseD_900500d;
      case (CClassicArchive *)0x900500e:
        ExceptionList = &stack0xfffffff4;
        CClassicArchive::DoReal
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x18),(float *)0x1,
                   (ulong)pCVar1);
        pCVar6 = *(CClassicArchive **)(this + 0x54);
        uVar3 = *(ulong *)(this + 0x58);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffec,(float *)0x1,
                   (ulong)unaff_EDI);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xfffffff4,(float *)0x1,
                   unaff_ESI);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xfffffffc,(float *)0x1,
                   unaff_EBP);
        if (*(int *)(this_00 + 8) == 0) {
          CPlugPhysicalObject::SetComPos
                    ((CClassicArchive *)(this + 0x18),(CPlugPhysicalObject *)&stack0xfffffff8,
                     unaff_EBX);
        }
        GmMat3::ArchiveGmMat3(this + 0x1c,(GmMat3 *)this_00,pCVar6);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x40),(float *)0x1,uVar3);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x44),(float *)0x1,
                   (ulong)puVar8);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x48),(float *)0x1,
                   (ulong)pCVar9);
        ExceptionList = in_stack_0000003c;
        return;
      default:
        goto switchD_008554f4_default;
      }
    }
    if ((CClassicArchive *)0x9005012 < param_2) {
      if (param_2 == (CClassicArchive *)0xffffffff) {
        ExceptionList = in_stack_0000003c;
        return;
      }
switchD_008554f4_default:
      ExceptionList = &stack0xfffffff4;
      CMwNod::Chunk((CMwNod *)this,param_1,param_2,(ulong)pCVar1);
      ExceptionList = in_stack_0000003c;
      return;
    }
    if (param_2 == (CClassicArchive *)0x9005012) {
      param_2 = (CClassicArchive *)CONCAT31(0x90050,(char)(*(uint *)(this + 0x70) >> 1));
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoNat8
                ((CClassicArchive *)param_1,(CClassicArchive *)&param_2,(uchar *)0x1,0,(int)pCVar1);
      *(ulong *)(this + 0x70) = (param_3 & 0xff) * 2 | *(uint *)(this + 0x70) & 0xfffffe01;
      ExceptionList = in_stack_0000003c;
      return;
    }
    if (param_2 == (CClassicArchive *)0x9005010) {
      param_1 = (CFuncSegment *)0x0;
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)this_00,(CClassicArchive *)&param_1,pCVar1);
      if (param_2 == (CClassicArchive *)0x0) {
        ExceptionList = in_stack_0000003c;
        return;
      }
      CMwNod::MwRelease((CMwNod *)param_2,unaff_EDI);
      ExceptionList = in_stack_0000003c;
      return;
    }
    if (param_2 != (CClassicArchive *)0x9005011) goto switchD_008554f4_default;
    pvVar7 = ExceptionList;
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoBool
              ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xffffffd4,(int *)0x1,
               (ulong)pCVar1);
    param_2 = (CClassicArchive *)(uint)(*(int *)(this + 0x68) != 0);
    CClassicArchive::DoBool
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_2,(int *)0x1,(ulong)unaff_EDI);
    if (param_3 != 0) {
      if (*(int *)(this_00 + 8) == 0) {
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xfffffff0,(int *)0x1,
                   unaff_ESI);
        if (pvVar7 == (void *)0x0) {
          (**(code **)(*(int *)this_00 + 4))();
          SetModel(this,in_stack_00000024,pCVar9);
        }
        else {
          (**(code **)(*(int *)this_00 + 8))();
          in_stack_00000024 = LoadFromFidForBeingUseAsAModel((CSystemFid *)in_stack_00000020,0);
          SetModel(this,in_stack_00000024,pCVar9);
        }
      }
      else {
        CClassicArchive::DoBool
                  ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffe0,(int *)0x1,
                   unaff_ESI);
        if (in_stack_ffffffe4 == 0) {
          pcVar2 = *(code **)(*(int *)this_00 + 4);
        }
        else {
          pcVar2 = *(code **)(*(int *)this_00 + 8);
        }
        (*pcVar2)();
      }
    }
    if (in_stack_0000001c == (CPlugSolid *)0x0) {
      if (in_stack_0000004c != 0) {
        if (*(int *)(this_00 + 8) != 0) {
          ExceptionList = in_stack_0000003c;
          return;
        }
        SetUseModel(this,(CPlugSolid *)0x1,(int)unaff_retaddr);
        SetModel(this,*(CPlugSolid **)(this + 0x68),(CPlugSolid *)param_1);
        param_1 = (CFuncSegment *)0x0;
        unaff_retaddr = (CClassicArchive *)0x855c7e;
        SetUseModel(this,(CPlugSolid *)0x0,(int)param_2);
        goto LAB_00855c3a;
      }
    }
    else if (in_stack_0000004c != 0) goto LAB_00855c3a;
    (**(code **)(*(int *)this_00 + 4))();
    if (*(int *)(this_00 + 8) != 0) {
      ExceptionList = in_stack_0000003c;
      return;
    }
    *(undefined4 *)(this + 0x5c) = *(undefined4 *)(this + 100);
LAB_00855c3a:
    if (*(int *)(this_00 + 8) != 0) {
      ExceptionList = in_stack_0000003c;
      return;
    }
    SetUseModel(this,in_stack_0000001c,(int)unaff_retaddr);
    ExceptionList = in_stack_0000003c;
    return;
  }
  if (param_2 != (CClassicArchive *)0x900500a) {
    switch(param_2) {
    case (CClassicArchive *)0x9005000:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoNatural
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x60),(ulong *)0x1,0,
                 (int)pCVar1);
      ExceptionList = in_stack_0000003c;
      return;
    case (CClassicArchive *)0x9005001:
    case (CClassicArchive *)0x9005002:
    case (CClassicArchive *)0x9005003:
    case (CClassicArchive *)0x9005004:
    case (CClassicArchive *)0x9005005:
    case (CClassicArchive *)0x9005008:
    case (CClassicArchive *)0x9005009:
      ExceptionList = in_stack_0000003c;
      return;
    case (CClassicArchive *)0x9005006:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoReal
                ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xffffffe0,(float *)0x1,
                 (ulong)pCVar1);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xffffffe0,(float *)0x1,
                 (ulong)unaff_EDI);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x18),(float *)0x1,unaff_ESI)
      ;
      pCVar6 = *(CClassicArchive **)(this + 0x58);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xfffffff4,(float *)0x1,
                 unaff_EBP);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xfffffffc,(float *)0x1,
                 (ulong)unaff_EBX);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)&param_1,(float *)0x1,
                 in_stack_ffffffcc);
      if (*(int *)(this_00 + 8) == 0) {
        CPlugPhysicalObject::SetComPos
                  ((CClassicArchive *)(this + 0x18),(CPlugPhysicalObject *)&stack0x00000000,
                   in_stack_ffffffd0);
      }
      GmMat3::ArchiveGmMat3(this + 0x1c,(GmMat3 *)this_00,pCVar6);
      ExceptionList = in_stack_0000003c;
      return;
    case (CClassicArchive *)0x9005007:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoBool
                ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xffffffe0,(int *)0x1,
                 (ulong)pCVar1);
      ExceptionList = in_stack_0000003c;
      return;
    }
    goto switchD_008554f4_default;
  }
  ExceptionList = &stack0xfffffff4;
  CClassicArchive::DoBool
            ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xffffffd0,(int *)0x1,(ulong)pCVar1
            );
  param_2 = (CClassicArchive *)(uint)(*(int *)(this + 0x68) != 0);
  CClassicArchive::DoBool
            ((CClassicArchive *)this_00,(CClassicArchive *)&param_2,(int *)0x1,(ulong)unaff_EDI);
  if ((param_3 != 0) && ((**(code **)(*(int *)this_00 + 4))(), *(int *)(this_00 + 8) == 0)) {
    SetModel(this,in_stack_00000020,(CPlugSolid *)unaff_retaddr);
  }
  if ((in_stack_00000018 != (CPlugSolid *)0x0) && (in_stack_0000004c != 0)) goto LAB_00855786;
  in_stack_0000001c = (CPlugSolid *)0x1;
  CClassicArchive::DoNatural
            ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x0000001c,(ulong *)0x1,0,
             (int)unaff_retaddr);
  if ((in_stack_00000020 != (CPlugSolid *)0x0) && (in_stack_00000020 == (CPlugSolid *)0x3)) {
    in_stack_00000020 = (CPlugSolid *)0x1;
  }
  in_stack_0000002c = 0;
  in_stack_00000028 = (CPlugSolid *)0x0;
  CClassicArchive::DoBool
            ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000028,(int *)0x1,
             (ulong)param_1);
  param_1 = (CFuncSegment *)0x1;
  unaff_retaddr = (CClassicArchive *)&stack0x00000030;
  CClassicArchive::DoBool((CClassicArchive *)this_00,unaff_retaddr,(int *)0x1,(ulong)param_2);
  in_stack_00000020 = (CPlugSolid *)0x0;
  in_stack_0000002c = 0;
  if (in_stack_00000028 == (CPlugSolid *)0x0) {
    if ((in_stack_00000024 == (CPlugSolid *)0x0) && (in_stack_00000058 != 0)) {
      param_2 = (CClassicArchive *)&stack0x0000003c;
      in_stack_0000003c = (void *)0x0;
      param_1 = (CFuncSegment *)0x855735;
      (**(code **)(*(int *)this_00 + 4))();
      if (*(int *)(this_00 + 8) == 0) {
        SetUseModel(this,(CPlugSolid *)0x1,(int)unaff_retaddr);
        SetModel(this,*(CPlugSolid **)(this + 0x68),(CPlugSolid *)param_1);
        param_1 = (CFuncSegment *)0x0;
        unaff_retaddr = (CClassicArchive *)0x855755;
        SetUseModel(this,(CPlugSolid *)0x0,(int)param_2);
        in_stack_00000020 = *(CPlugSolid **)(this + 100);
      }
    }
    else {
LAB_00855762:
      pcVar2 = *(code **)(*(int *)this_00 + 4);
LAB_00855768:
      (*pcVar2)();
    }
LAB_0085576c:
    if (in_stack_00000014 != 0) {
      *(int *)(this + 100) = in_stack_00000014;
      *(int *)(this + 0x5c) = in_stack_00000014;
      goto LAB_00855786;
    }
  }
  else {
    if (in_stack_00000028 == (CPlugSolid *)0x1) {
      if (in_stack_00000030 != 0) {
        if ((in_stack_00000024 == (CPlugSolid *)0x0) && (in_stack_00000058 != 0)) {
          param_2 = (CClassicArchive *)&stack0x0000003c;
          in_stack_0000003c = (void *)0x0;
          param_1 = (CFuncSegment *)0x8556ce;
          (**(code **)(*(int *)this_00 + 4))();
          if (*(int *)(this_00 + 8) == 0) {
            SetUseModel(this,(CPlugSolid *)0x1,(int)unaff_retaddr);
            SetModel(this,*(CPlugSolid **)(this + 0x68),(CPlugSolid *)param_1);
            param_1 = (CFuncSegment *)0x0;
            unaff_retaddr = (CClassicArchive *)0x8556ee;
            SetUseModel(this,(CPlugSolid *)0x0,(int)param_2);
            in_stack_00000020 = *(CPlugSolid **)(this + 100);
          }
        }
        else {
          param_2 = (CClassicArchive *)&stack0x00000020;
          param_1 = (CFuncSegment *)0x855705;
          (**(code **)(*(int *)this_00 + 4))();
        }
      }
      if (in_stack_00000028 != (CPlugSolid *)0x0) {
        pcVar2 = *(code **)(*(int *)this_00 + 4);
        goto LAB_00855768;
      }
      goto LAB_0085576c;
    }
    if (in_stack_00000028 == (CPlugSolid *)0x2) goto LAB_00855762;
  }
  *(CPlugSolid **)(this + 100) = in_stack_00000020;
  *(CPlugSolid **)(this + 0x5c) = in_stack_00000020;
LAB_00855786:
  if (*(int *)(this_00 + 8) == 0) {
    SetUseModel(this,in_stack_00000018,(int)unaff_retaddr);
  }
  ExceptionList = in_stack_0000003c;
  return;
switchD_008557c0_caseD_900500d:
  ExceptionList = &stack0xfffffff4;
  CClassicArchive::DoBool
            ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xffffffd8,(int *)0x1,(ulong)pCVar1
            );
  param_2 = (CClassicArchive *)(uint)(*(int *)(this + 0x68) != 0);
  CClassicArchive::DoBool
            ((CClassicArchive *)this_00,(CClassicArchive *)&param_2,(int *)0x1,(ulong)unaff_EDI);
  if ((param_3 != 0) && ((**(code **)(*(int *)this_00 + 4))(), *(int *)(this_00 + 8) == 0)) {
    SetModel(this,in_stack_00000028,(CPlugSolid *)unaff_retaddr);
  }
  if (in_stack_00000020 == (CPlugSolid *)0x0) {
    if (in_stack_0000004c != 0) {
      if (*(int *)(this_00 + 8) != 0) {
        ExceptionList = in_stack_0000003c;
        return;
      }
      SetUseModel(this,(CPlugSolid *)0x1,(int)unaff_retaddr);
      SetModel(this,*(CPlugSolid **)(this + 0x68),(CPlugSolid *)param_1);
      param_1 = (CFuncSegment *)0x0;
      unaff_retaddr = (CClassicArchive *)0x85592e;
      SetUseModel(this,(CPlugSolid *)0x0,(int)param_2);
      goto LAB_008558e9;
    }
  }
  else if (in_stack_0000004c != 0) goto LAB_008558e9;
  (**(code **)(*(int *)this_00 + 4))();
  if (*(int *)(this_00 + 8) != 0) {
    ExceptionList = in_stack_0000003c;
    return;
  }
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(this + 100);
LAB_008558e9:
  if (*(int *)(this_00 + 8) != 0) {
    ExceptionList = in_stack_0000003c;
    return;
  }
  SetUseModel(this,in_stack_00000020,(int)unaff_retaddr);
  ExceptionList = in_stack_0000003c;
  return;
}
}

// =================================================
// Function: CPlugSolid::CreateDefaultData
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CPlugSolid::CreateDefaultData(CPlugSolid *this,CCrystal *param_1)
{
{
  CPlugTree *pCVar1;
  CPlugTree *this_00;
  CPlugTree *extraout_EAX;
  CPlugVisualQuads *this_01;
  CPlugVisualQuads *extraout_EAX_00;
  CPlugVisualQuads *this_02;
  CPlugVisualQuads *unaff_EDI;
  int iVar2;
  undefined4 uStack_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ad5576;
  local_c = ExceptionList;
  pCVar1 = (CPlugTree *)(DAT_00cca150 ^ (uint)&stack0xffffffd4);
  ExceptionList = &local_c;
  this_00 = operator_new(0xac);
  this_02 = (CPlugVisualQuads *)0x0;
  local_4 = 0;
  if (this_00 == (CPlugTree *)0x0) {
    pCVar1 = (CPlugTree *)0x0;
  }
  else {
    CPlugTree::CPlugTree(this_00,pCVar1);
    pCVar1 = extraout_EAX;
  }
  this_01 = operator_new(0x98);
  if (this_01 != (CPlugVisualQuads *)0x0) {
    CPlugVisualQuads::CPlugVisualQuads(this_01,unaff_EDI);
    this_02 = extraout_EAX_00;
  }
  uStack_18 = 0x3f800000;
  local_14 = 0x3f800000;
  local_10 = 0x3f800000;
  local_c = (void *)0x3f800000;
  CPlugVisualQuads::BoxQuadAdd(this_02,_DAT_00b31460,-NAN,(ulong)&uStack_18,(GxColor *)unaff_EDI);
  iVar2 = 0;
  CPlugTree::SetVisual(pCVar1,(CVisionVisualKeeper *)this_02,(CPlugVisual *)0x0);
  SetTree(this,(CPlugSolid *)pCVar1,(CPlugTree *)0x1,iVar2);
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CPlugSolid::CreateModelInstance
// =================================================
CPlugSolid * __thiscall CPlugSolid::CreateModelInstance(CPlugSolid *this,CPlugSolid *param_1)
{
{
  CPlugSolid *pCVar1;
  CPlugSolid *this_00;
  CPlugSolid *extraout_EAX;
  CPlugSolid *this_01;
  CPlugSolid *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ad55db;
  local_c = ExceptionList;
  pCVar1 = (CPlugSolid *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  this_00 = operator_new(0x74);
  this_01 = (CPlugSolid *)0x0;
  local_4 = (void *)0x0;
  if (this_00 != (CPlugSolid *)0x0) {
    CPlugSolid(this_00,pCVar1);
    this_01 = extraout_EAX;
  }
  SetModel(this_01,this,unaff_EDI);
  ExceptionList = local_4;
  return this_01;
}
}

// =================================================
// Function: CPlugSolid::DisconnectFromModel
// =================================================
void __thiscall CPlugSolid::DisconnectFromModel(CPlugSolid *this,CPlugSolid *param_1,int param_2)
{
{
  CMwNod *unaff_ESI;
  
  if (param_1 == (CPlugSolid *)0x0) {
    CPlugTree::DisconnectFromModel(*(CPlugTree **)(this + 100),(CPlugSolid *)0x1,-1);
    (**(code **)(**(int **)(this + 100) + 0x78))(0);
    (**(code **)(**(int **)(this + 100) + 0xbc))(1);
  }
  CMwNod::MwRelease(*(CMwNod **)(this + 0x68),unaff_ESI);
  *(undefined4 *)(this + 0x68) = 0;
  return;
}
}

// =================================================
// Function: CPlugSolid::ExclusionEllipsoidRadiusCompute
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CPlugSolid::ExclusionEllipsoidRadiusCompute(CPlugSolid *this,CPlugSolid *param_1)
{
{
  float fVar1;
  CIteratorVisual *pCVar2;
  GmMat3 *pGVar3;
  CPlugVisual *pCVar4;
  int iVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SCasterCat *pSVar7;
  float unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float10 fVar9;
  GmMat3 *pGVar10;
  float fStack_98;
  CPlugTree *pCStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  undefined1 auStack_50 [8];
  int iStack_48;
  int iStack_40;
  GmMat3 aGStack_3c [36];
  float fStack_18;
  float fStack_14;
  float fStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad54f8;
  local_c = ExceptionList;
  pGVar3 = (GmMat3 *)(DAT_00cca150 ^ (uint)&stack0xffffff58);
  ExceptionList = &local_c;
  *(undefined4 *)(this + 0x6c) = 0;
  if (*(int **)(this + 100) != (int *)0x0) {
    (**(code **)(**(int **)(this + 100) + 0xbc))(0);
    pCVar2 = *(CIteratorVisual **)(this + 100);
    if (0.0 <= *(float *)(pCVar2 + 0x40)) {
      fStack_80 = *(float *)(pCVar2 + 0x34);
      fStack_7c = *(float *)(pCVar2 + 0x38);
      fStack_78 = *(float *)(pCVar2 + 0x3c);
      fStack_8c = *(float *)(pCVar2 + 0x40);
      fStack_88 = *(float *)(pCVar2 + 0x44);
      fStack_84 = *(float *)(pCVar2 + 0x48);
      fStack_98 = fStack_84;
      if (fStack_88 <= fStack_84) {
        fStack_98 = fStack_88;
      }
      fStack_90 = fStack_8c;
      if (fStack_98 < fStack_8c) {
        fStack_90 = fStack_98;
      }
      fStack_98 = fStack_84;
      if (fStack_84 <= fStack_88) {
        fStack_98 = fStack_88;
      }
      if (fStack_98 < fStack_8c != (fStack_98 == fStack_8c)) {
        fStack_98 = fStack_8c;
      }
      if (((float)_DAT_00b362c0 <= fStack_90) && (fStack_98 / fStack_90 <= (float)_DAT_00b48cb8)) {
        pGVar10 = (GmMat3 *)0x0;
        fStack_54 = 1.0 / fStack_8c;
        fStack_68 = 1.0 / fStack_88;
        fStack_58 = 1.0 / fStack_84;
        CPlugTree::CIteratorVisual::CIteratorVisual
                  (auStack_50,pCVar2,(CPlugTree *)0x0,(EMode)pGVar3);
        while (iStack_40 != 0) {
          pCVar4 = CPlugTree::CIteratorVisual::GetNextVisual
                             (&fStack_54,(CIteratorVisual *)&pCStack_94,(CPlugTree **)pGVar10);
          pGVar10 = (GmMat3 *)0x902c000;
          iVar5 = (**(code **)(*(int *)pCVar4 + 0x10))();
          if (iVar5 == 0) goto LAB_00855119;
          CPlugTree::GetThisToRootTransfo
                    (pCStack_94,(CPlugTree *)&iStack_40,(GmIso4 *)0x1,0,(CPlugTree *)pGVar10);
          fStack_8c = fStack_80 - fStack_18;
          pGVar10 = aGStack_3c;
          fStack_88 = fStack_7c - fStack_14;
          fStack_84 = fStack_78 - fStack_10;
          GmVec3::MultTranspose(&fStack_8c,pGVar10,pGVar3);
          pGVar3 = (GmMat3 *)0x855049;
          pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<class_CCrystalFace*>::GetCount(pCVar4 + 0x78,unaff_EDI);
          pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          iStack_40 = iStack_48;
          if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            do {
              pSVar7 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                                 (pCVar4 + 0x78,pCVar8,(ulong)pGVar10);
              fStack_74 = *(float *)pSVar7 - fStack_8c;
              fStack_70 = *(float *)(pSVar7 + 4) - fStack_88;
              fStack_6c = *(float *)(pSVar7 + 8) - fStack_84;
              fStack_64 = fStack_74 * fStack_54;
              fStack_60 = fStack_70 * fStack_68;
              fStack_5c = fStack_6c * fStack_58;
              pCStack_94 = (CPlugTree *)
                           (fStack_5c * fStack_5c + fStack_64 * fStack_64 + fStack_60 * fStack_60);
              pGVar10 = (GmMat3 *)0x8550ca;
              fVar9 = (float10)func_0x009c1b40();
              fVar1 = (float)fVar9;
              if ((fVar1 < unaff_EBX) && (unaff_EBX = fVar1, fVar1 < (float)_DAT_00b362c0))
              goto LAB_00855119;
              pCVar8 = pCVar8 + 1;
              iStack_40 = iStack_48;
            } while (pCVar8 < pCVar6);
          }
        }
        *(float *)(this + 0x6c) = unaff_EBX;
LAB_00855119:
        CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                  (&fStack_54,(CFastBuffer<class_CPlugFileGPUV*> *)pGVar10);
      }
    }
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CPlugSolid::ExclusionEllipsoidRadiusIsCulled
// =================================================
int __thiscall
CPlugSolid::ExclusionEllipsoidRadiusIsCulled
          (CPlugSolid *this,CPlugSolid *param_1,GmFrustum *param_2,GmIso4 *param_3)
{
{
  GmVec3 *pGVar1;
  GmIso4 *unaff_EBP;
  float unaff_ESI;
  uint uVar2;
  float unaff_EDI;
  SPlugFaceCull *pSVar3;
  float10 fVar4;
  SPlugFaceCull *in_stack_00000010;
  undefined1 local_64 [4];
  GmFrustum local_60 [8];
  SPlugFaceCull local_58 [44];
  GmFrustum local_2c [44];
  
  if (((*(int *)(this + 100) != 0) && (0.0 <= *(float *)(*(int *)(this + 100) + 0x40))) &&
     (*(float *)(this + 0x6c) != 0.0)) {
    if (*(int *)param_1 == 0) {
      pGVar1 = *(GmVec3 **)(param_1 + 0xc);
    }
    else {
      pGVar1 = (GmVec3 *)(*(float *)(param_1 + 0xc) - *(float *)(param_1 + 0x18));
    }
    GmFrustum::GetVertices4AtZ(param_1,local_60,pGVar1,unaff_ESI);
    if (*(int *)param_1 == 0) {
      pGVar1 = *(GmVec3 **)(param_1 + 0x18);
    }
    else {
      pGVar1 = (GmVec3 *)(*(float *)(param_1 + 0x18) + *(float *)(param_1 + 0xc));
    }
    GmFrustum::GetVertices4AtZ(param_1,local_2c,pGVar1,unaff_EDI);
    uVar2 = 0;
    pSVar3 = local_58;
    do {
      GmVec3::SetMult(local_64,pSVar3,in_stack_00000010,unaff_EBP);
      unaff_EBP = (GmIso4 *)0x85464e;
      fVar4 = (float10)func_0x009c1b40();
      if (*(float *)(this + 0x6c) < (float)fVar4 != (*(float *)(this + 0x6c) == (float)fVar4)) {
        return 0;
      }
      uVar2 = uVar2 + 1;
      pSVar3 = pSVar3 + 0xc;
    } while (uVar2 < 8);
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CPlugSolid::GetChunkInfo
// =================================================
ulong __thiscall CPlugSolid::GetChunkInfo(CPlugSolid *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 < (CFuncSegment *)0x900500b) {
    if (param_1 != (CFuncSegment *)0x900500a) {
      switch(param_1) {
      case (CFuncSegment *)0x9005000:
switchD_00853a68_caseD_9005000:
        return 3;
      case (CFuncSegment *)0x9005001:
      case (CFuncSegment *)0x9005002:
      case (CFuncSegment *)0x9005003:
      case (CFuncSegment *)0x9005004:
      case (CFuncSegment *)0x9005005:
      case (CFuncSegment *)0x9005006:
      case (CFuncSegment *)0x9005007:
      case (CFuncSegment *)0x9005008:
      case (CFuncSegment *)0x9005009:
        break;
      default:
        goto switchD_00853a68_default;
      }
    }
  }
  else {
    if ((CFuncSegment *)0x900500f < param_1) {
      if (param_1 < (CFuncSegment *)0x9005013) {
        if (param_1 == (CFuncSegment *)0x9005012) {
          return 3;
        }
        if (param_1 == (CFuncSegment *)0x9005010) {
          return 3;
        }
        if (param_1 == (CFuncSegment *)0x9005011) {
          return 3;
        }
      }
      else if (param_1 == (CFuncSegment *)0xffffffff) {
        return 0xffffffff;
      }
switchD_00853a68_default:
      uVar1 = CMwNod::GetChunkInfo((CMwNod *)this,param_1,param_2);
      return uVar1;
    }
    if (param_1 != (CFuncSegment *)0x900500f) {
      switch(param_1) {
      case (CFuncSegment *)0x900500b:
      case (CFuncSegment *)0x900500c:
      case (CFuncSegment *)0x900500d:
        break;
      case (CFuncSegment *)0x900500e:
        goto switchD_00853a68_caseD_9005000;
      default:
        goto switchD_00853a68_default;
      }
    }
  }
  return 1;
}
}

// =================================================
// Function: CPlugSolid::GetMwClassId
// =================================================
ulong __thiscall CPlugSolid::GetMwClassId(CPlugSolid *this,CControlStyle *param_1)
{
{
  return 0x9005000;
}
}

// =================================================
// Function: CPlugSolid::GetPlugFromId
// =================================================
CPlugTree * __thiscall
CPlugSolid::GetPlugFromId(CPlugSolid *this,CPlugSolid *param_1,CMwId *param_2)
{
{
  CPlugTree *pCVar1;
  
  if ((*(int *)(this + 100) != 0) && (*(int *)param_1 != -1)) {
                    /* WARNING: Could not recover jumptable at 0x00854123. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pCVar1 = (CPlugTree *)(**(code **)(**(int **)(this + 100) + 0xb4))();
    return pCVar1;
  }
  return (CPlugTree *)0x0;
}
}

// =================================================
// Function: CPlugSolid::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CPlugSolid::GetUidChunkFromIndex(CPlugSolid *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0x9005000;
}
}

// =================================================
// Function: CPlugSolid::GivePlugId
// =================================================
void __thiscall CPlugSolid::GivePlugId(CPlugSolid *this,CPlugSolid *param_1,CMwId *param_2)
{
{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x60);
  *(int *)(this + 0x60) = iVar1 + 1;
  *(int *)param_1 = iVar1;
  return;
}
}

// =================================================
// Function: CPlugSolid::InternalConnectSubTree
// =================================================
void __thiscall
CPlugSolid::InternalConnectSubTree(CPlugSolid *this,CPlugSolid *param_1,CPlugTree *param_2)
{
{
  CPlugSolid *unaff_ESI;
  
  RecursiveSetSolid((CPlugTree *)param_1,this);
  MakeTreeIdsUnique(this,unaff_ESI);
  return;
}
}

// =================================================
// Function: CPlugSolid::InternalDisconnectSubTree
// =================================================
void __thiscall
CPlugSolid::InternalDisconnectSubTree(CPlugSolid *this,CPlugSolid *param_1,CPlugTree *param_2)
{
{
  CPlugTree *pCVar1;
  CPlugSolid *pCVar2;
  ulong *unaff_EBX;
  uchar **unaff_EBP;
  ulong unaff_ESI;
  CPlugTree *pCVar3;
  ulong unaff_EDI;
  CPlugTree *pCVar4;
  
  CInputEventsStore::Lock(param_1,(CDx9DynamicVB *)0x0,unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX);
  pCVar1 = (CPlugTree *)(**(code **)(*(int *)param_1 + 0x7c))();
  pCVar3 = (CPlugTree *)0x0;
  if (pCVar1 != (CPlugTree *)0x0) {
    do {
      pCVar4 = pCVar3;
      pCVar2 = (CPlugSolid *)(**(code **)(*(int *)param_1 + 0x80))();
      InternalDisconnectSubTree(this,pCVar2,pCVar4);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CPlugSolid::LoadFromFidForBeingUseAsAModel
// =================================================
CPlugSolid * __cdecl CPlugSolid::LoadFromFidForBeingUseAsAModel(CSystemFid *param_1,int param_2)
{
{
  CMwNod *pCVar1;
  CSystemFidParameters *pCVar2;
  CSystemFidParameters *this;
  CSystemFidParameters *unaff_ESI;
  SParam_Id *unaff_EDI;
  SParam *pSVar3;
  SParam_Id *pSVar4;
  SParam *pSVar5;
  SParam_Id *pSVar6;
  SParam_Id local_88 [4];
  CMwNod *local_84 [3];
  CSystemFidParameters local_78 [4];
  CSystemFidParameters local_74 [4];
  SParam_Id local_70 [4];
  SParam_Id local_6c [16];
  CSystemFidParameters local_5c [4];
  CSystemFidParameters local_58 [8];
  SParam_Id local_50 [8];
  CSystemFidParameters local_48 [4];
  CSystemFidParameters local_44 [4];
  CSystemFidParameters local_40 [4];
  CSystemFidParameters local_3c [8];
  CSystemFidParameters local_34 [32];
  undefined1 local_14;
  undefined1 local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00ad5403;
  local_c = ExceptionList;
  pCVar2 = (CSystemFidParameters *)(DAT_00cca150 ^ (uint)&stack0xffffff70);
  if (param_1 == (CSystemFid *)0x0) {
    return (CPlugSolid *)0x0;
  }
  ExceptionList = &local_c;
  this = CSystemFidParameters::GetCurrentParameters();
  CSystemFidParameters::CSystemFidParameters(local_3c,(CSystemFidParameters *)&DAT_00d55500,pCVar2);
  pCVar2 = (CSystemFidParameters *)0x0;
  pSVar5 = (SParam *)0x0;
  pSVar3 = (SParam *)0x0;
  CSystemFidParameters::SParam_Id::SParam_Id(local_50,(SParam_Id *)&DAT_00d6e954);
  local_c._0_1_ = 1;
  CSystemFidParameters::GetParamValue(this,local_5c,pSVar3);
  CSystemFidParameters::AddParam(local_40,local_58,pSVar5);
  if (param_2 == 0) {
    pSVar6 = (SParam_Id *)0x0;
    pSVar5 = (SParam *)0x0;
    pSVar3 = (SParam *)0x0;
    CSystemFidParameters::SParam_Id::SParam_Id(local_6c,(SParam_Id *)&DAT_00d6e958);
    local_10 = 2;
    CSystemFidParameters::GetParamValue(this,local_78,pSVar3);
    CSystemFidParameters::AddParam(local_44,local_74,pSVar5);
    pSVar4 = (SParam_Id *)0x0;
    pSVar5 = (SParam *)0x0;
    pSVar3 = (SParam *)0x0;
    CSystemFidParameters::SParam_Id::SParam_Id(local_88,(SParam_Id *)&DAT_00d6e95c);
    local_14 = 3;
    CSystemFidParameters::GetParamValue(this,(CSystemFidParameters *)&stack0xffffff6c,pSVar3);
    CSystemFidParameters::AddParam(local_48,(CSystemFidParameters *)&stack0xffffff70,pSVar5);
    local_c._0_1_ = 2;
    CSystemFidParameters::SParam_Id::~SParam_Id((SParam_Id *)&stack0xffffff74,pSVar4);
    local_8 = (undefined1 *)CONCAT31(local_8._1_3_,1);
    CSystemFidParameters::SParam_Id::~SParam_Id(local_70,pSVar6);
  }
  local_84[0] = CSystemFid::ParametrizedGetAnyLoadedNodLooselyFittingTheParams
                          (param_1,(CSystemFid *)local_3c,pCVar2);
  if (local_84[0] == (CMwNod *)0x0) {
    CSystemArchiveNod::LoadFromFid(local_84,param_1,7);
  }
  pCVar1 = local_84[0];
  CSystemFidParameters::SParam_Id::~SParam_Id((SParam_Id *)local_50,unaff_EDI);
  CSystemFidParameters::~CSystemFidParameters(local_34,unaff_ESI);
  ExceptionList = (void *)0x0;
  return (CPlugSolid *)pCVar1;
}
}

// =================================================
// Function: CPlugSolid::MakeTreeIdsUnique
// =================================================
void __thiscall CPlugSolid::MakeTreeIdsUnique(CPlugSolid *this,CPlugSolid *param_1)
{
{
  CFastString CVar1;
  ulong uVar2;
  int *piVar3;
  CFastMapTable<unsigned_long> *extraout_EAX;
  CPlugTree *this_00;
  int iVar4;
  CMwId *pCVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  SCasterCat *pSVar6;
  CVirtualisedBuffer<class_CFastString> *pCVar7;
  CFastString *extraout_ECX;
  CFastString *this_01;
  undefined *puVar8;
  CFastString *extraout_ECX_00;
  CMwId *unaff_EBX;
  CFastMapTable<unsigned_long> *this_02;
  CFastMapTable<unsigned_long> *pCVar9;
  TiXmlAttributeSet *unaff_ESI;
  ulong unaff_EDI;
  CPlugSolid *pCVar10;
  undefined4 uStack00000008;
  CMwId *pCVar11;
  CFastStringInt *in_stack_ffffffb8;
  CMwId *in_stack_ffffffbc;
  CVirtualisedBuffer<class_CFastString> *in_stack_ffffffc0;
  CPlugSolid *local_3c;
  CFastMapTable<unsigned_long> *local_38;
  CFastMapTable<unsigned_long> *local_34;
  int iStack_30;
  CFastMapTable<unsigned_long> *local_2c;
  undefined4 uStack_28;
  undefined *local_24;
  CTrackManiaEditorIconPage aCStack_20 [4];
  CPlugSolid *pCStack_1c;
  undefined4 uStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined *local_8;
  
  pCVar11 = (CMwId *)&stack0xfffffffc;
  puStack_c = (undefined *)0xffffffff;
  puStack_10 = &LAB_00ad54c9;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  pCVar9 = (CFastMapTable<unsigned_long> *)0x0;
  local_3c = this;
  uVar2 = CPlugTree::GetRecursiveTreeCount
                    (*(CPlugTree **)(this + 100),(CPlugTree *)0x0,1,
                     DAT_00cca150 ^ (uint)&stack0xffffffa8);
  if (uVar2 < 2) {
    piVar3 = (int *)(**(code **)(**(int **)(this + 100) + 0x14))();
    if (*piVar3 == -1) {
      CMwId::CMwId(&local_3c,(CMwId *)unaff_ESI);
      GivePlugId(this,(CPlugSolid *)&local_38,pCVar11);
      CPlugTree::InternalSetMwId(*(CPlugTree **)(this + 100),(CPlugTree *)&local_34,unaff_EBX);
      uStack00000008 = 0xffffffff;
      OnAccessViolation_ConcatToCrashFileName(in_stack_ffffffb8);
      ExceptionList = (void *)0x0;
      return;
    }
  }
  else {
    if ((DAT_00d6e984 & 1) == 0) {
      DAT_00d6e984 = DAT_00d6e984 | 1;
      local_8 = (undefined *)0x1;
      CFastMapTable<unsigned_long>::CFastMapTable<unsigned_long>
                ((CFastMapTable<unsigned_long> *)&DAT_00d6e974,
                 (CFastMapTable<unsigned_long> *)&DAT_00000023,unaff_EDI);
      _atexit(`public:_void___thiscall_CPlugSolid::MakeTreeIdsUnique(void)'::__l8::
              _dynamic_atexit_destructor_for__StaticUsedIds__);
    }
    local_38 = (CFastMapTable<unsigned_long> *)0x0;
    if (uVar2 < 0x21) {
      CFastMapTable<unsigned_long>::Clear
                ((CFastMapTable<unsigned_long> *)&DAT_00d6e974,(TiXmlNode *)unaff_ESI);
    }
    else {
      local_2c = operator_new(0x10);
      if (local_2c == (CFastMapTable<unsigned_long> *)0x0) {
        local_38 = (CFastMapTable<unsigned_long> *)0x0;
        pCVar9 = (CFastMapTable<unsigned_long> *)0x0;
      }
      else {
        CFastMapTable<unsigned_long>::CFastMapTable<unsigned_long>
                  (local_2c,(CFastMapTable<unsigned_long> *)(uVar2 + 3),(ulong)unaff_ESI);
        pCVar9 = extraout_EAX;
        local_34 = extraout_EAX;
      }
    }
    this_02 = (CFastMapTable<unsigned_long> *)&DAT_00d6e974;
    if (0x20 < uVar2) {
      this_02 = pCVar9;
    }
    iStack_30 = CSystemFile_testerror(unaff_ESI,pCVar11);
    while (iStack_30 != -1) {
      this_00 = CPlugTree::GetAllTreeNext
                          (*(CPlugTree **)(this + 100),(CPlugTree *)&iStack_30,(ulong *)unaff_ESI);
      unaff_ESI = (TiXmlAttributeSet *)0x854bdc;
      iVar4 = CPlugTree::GetIsRooted(this_00,(CPlugTree *)pCVar11);
      pCVar9 = local_38;
      if (iVar4 != 0) {
        pCVar11 = (CMwId *)0x854bee;
        pCVar5 = (CMwId *)(**(code **)(*(int *)this_00 + 0x14))();
        CMwId::CMwId(&stack0xffffffc0,pCVar5);
        if (in_stack_ffffffc0 == (CVirtualisedBuffer<class_CFastString> *)0xffffffff) {
          GivePlugId(this,(CPlugSolid *)&stack0xffffffc0,(CMwId *)unaff_ESI);
          CPlugTree::InternalSetMwId(this_00,(CPlugTree *)&local_3c,pCVar11);
          unaff_ESI = (TiXmlAttributeSet *)&local_24;
          local_24 = (undefined *)0x0;
          pCVar11 = (CMwId *)local_38;
          CFastMapTable<unsigned_long>::Add(this_02,unaff_ESI,(TiXmlAttribute *)local_38);
          pCVar7 = in_stack_ffffffc0;
        }
        else {
          pCVar7 = in_stack_ffffffc0;
          if (((uint)in_stack_ffffffc0 & 0xc0000000) == 0) {
            if ((*(CVirtualisedBuffer<class_CFastString> **)(this + 0x60) <= in_stack_ffffffc0) ||
               (CVar1 = CFastMapTable<unsigned_long>::GetElem
                                  (this_02,in_stack_ffffffc0,(ulong)&local_3c),
               CONCAT31(extraout_var,CVar1) != 0)) {
              GivePlugId(this,(CPlugSolid *)&stack0xffffffc0,(CMwId *)unaff_ESI);
              unaff_ESI = (TiXmlAttributeSet *)&local_3c;
              CPlugTree::InternalSetMwId(this_00,(CPlugTree *)unaff_ESI,pCVar11);
              in_stack_ffffffc0 = (CVirtualisedBuffer<class_CFastString> *)local_38;
            }
            local_2c = (CFastMapTable<unsigned_long> *)0x0;
            CFastMapTable<unsigned_long>::Add
                      (this_02,(TiXmlAttributeSet *)&local_2c,(TiXmlAttribute *)in_stack_ffffffc0);
          }
          else {
            CVar1 = CFastMapTable<unsigned_long>::GetElem
                              (this_02,in_stack_ffffffc0,(ulong)&local_3c);
            if (CONCAT31(extraout_var_00,CVar1) == 0) {
              local_2c = (CFastMapTable<unsigned_long> *)0x0;
              CFastMapTable<unsigned_long>::Add
                        (this_02,(TiXmlAttributeSet *)&local_2c,(TiXmlAttribute *)in_stack_ffffffc0)
              ;
            }
            else {
              uStack_28 = 0;
              local_24 = PTR_DAT_00bbf7d8;
              CMwId::GetName(&stack0xffffffc0,aCStack_20);
              this_01 = extraout_ECX;
              pCVar10 = local_3c;
              do {
                pCVar10 = pCVar10 + 1;
                CFastString::Format(this_01,(CFastString *)&uStack_28,"%s_%2d");
                unaff_ESI = (TiXmlAttributeSet *)0x854cfe;
                CMwId::SetLocalName(&local_38,(CMwId *)pCStack_1c,(CFastStringInt *)unaff_EBX);
                CMwId::GetName(&local_34,(CTrackManiaEditorIconPage *)&puStack_c);
                if (local_8 != PTR_DAT_00bbf7d8) {
                  puVar8 = local_8 + -1;
                  if ((local_8[-1] & 0x80) != 0) {
                    puVar8 = local_8 + -4;
                  }
                  operator_delete__(puVar8);
                  puStack_c = (undefined *)0x0;
                  local_8 = PTR_DAT_00bbf7d8;
                }
                pCVar11 = (CMwId *)0x854d4a;
                unaff_EBX = (CMwId *)local_34;
                iVar4 = CFastMapTable<unsigned_long>::IsPresent
                                  (this_02,local_34,(ulong)in_stack_ffffffb8);
                this_01 = extraout_ECX_00;
              } while (iVar4 != 0);
              local_2c = (CFastMapTable<unsigned_long> *)pCVar10;
              CPlugTree::InternalSetMwId(this_00,(CPlugTree *)&iStack_30,in_stack_ffffffbc);
              uStack_18 = 0;
              unaff_EBX = (CMwId *)0x854d75;
              CFastMapTable<unsigned_long>::Add
                        (this_02,(TiXmlAttributeSet *)&uStack_18,(TiXmlAttribute *)local_2c);
              in_stack_ffffffb8 = (CFastStringInt *)0x854d7d;
              pSVar6 = CFastMapTable<unsigned_long>::operator[]
                                 (this_02,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                          in_stack_ffffffc0,(ulong)pCVar7);
              *(CPlugSolid **)pSVar6 = pCVar10;
              in_stack_ffffffbc = (CMwId *)in_stack_ffffffc0;
              if (PTR_DAT_00bbf7d8 != &DAT_00000005) {
                pCVar7 = (CVirtualisedBuffer<class_CFastString> *)&DAT_00000004;
                if ((DAT_00000004 & 0x80) != 0) {
                  pCVar7 = (CVirtualisedBuffer<class_CFastString> *)0x1;
                }
                in_stack_ffffffbc = (CMwId *)0x854d9e;
                operator_delete__(pCVar7);
                local_8 = (undefined *)0x0;
              }
              this = pCStack_1c;
              if (puStack_c != PTR_DAT_00bbf7d8) {
                pCVar7 = (CVirtualisedBuffer<class_CFastString> *)(puStack_c + -1);
                if ((puStack_c[-1] & 0x80) != 0) {
                  pCVar7 = (CVirtualisedBuffer<class_CFastString> *)(puStack_c + -4);
                }
                in_stack_ffffffbc = (CMwId *)0x854dc8;
                operator_delete__(pCVar7);
                puStack_10 = (undefined1 *)0x0;
                puStack_c = PTR_DAT_00bbf7d8;
                this = pCStack_1c;
              }
            }
          }
        }
        OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)unaff_ESI);
        pCVar9 = local_38;
        in_stack_ffffffc0 = pCVar7;
      }
    }
    if (pCVar9 != (CFastMapTable<unsigned_long> *)0x0) {
      (*(code *)**(undefined4 **)pCVar9)();
    }
  }
  ExceptionList = puStack_c;
  return;
}
}

// =================================================
// Function: CPlugSolid::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CPlugSolid::MwGetClassInfo(CPlugSolid *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d6e928;
}
}

// =================================================
// Function: CPlugSolid::MwIsKindOf
// =================================================
int __thiscall CPlugSolid::MwIsKindOf(CPlugSolid *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if ((param_1 != (CMwCmdAffectParam *)0x9005000) && (param_1 != (CMwCmdAffectParam *)0x902b000)) {
    return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
  }
  return 1;
}
}

// =================================================
// Function: CPlugSolid::MwNewCPlugSolid
// =================================================
CMwNod * __cdecl CPlugSolid::MwNewCPlugSolid(void)
{
{
  CPlugSolid *pCVar1;
  CMwNod *extraout_EAX;
  CPlugSolid *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ad53bb;
  local_c = ExceptionList;
  pCVar1 = (CPlugSolid *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x74);
  local_4 = 0;
  if (local_10 != (CPlugSolid *)0x0) {
    CPlugSolid(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CPlugSolid::OnCrashDump
// =================================================
int __thiscall CPlugSolid::OnCrashDump(CPlugSolid *this,CMwNod *param_1,CFastString *param_2)
{
{
  int iVar1;
  char *unaff_ESI;
  CFastString *unaff_EDI;
  CSystemCrashDump *unaff_retaddr;
  
  iVar1 = CMwNod::OnCrashDump((CMwNod *)this,param_1,unaff_EDI);
  if (iVar1 == 0) {
    return 0;
  }
  (**(code **)(DAT_00d5546c + 0x14))();
  CSystemCrashDump::ContextPush
            ((CSystemCrashDump *)&DAT_00d5546c,(CSystemCrashDump *)&DAT_00b586d0,unaff_ESI);
  OnCrashCheckTreeRecursive((CFastString *)param_1,*(CPlugTree **)(this + 100));
  CSystemCrashDump::ContextPop((CSystemCrashDump *)&DAT_00d5546c,unaff_retaddr);
  if (*(char **)(this + 0x68) != (char *)0x0) {
    iVar1 = CSystemCrashDump::IsValid_DumpFidAndMwId
                      ((CSystemCrashDump *)&DAT_00d5546c,(CSystemCrashDump *)param_1,
                       (CFastString *)"Solid Model",*(char **)(this + 0x68),(CMwNod *)0x1,
                       (int)param_1);
    if (iVar1 != 0) {
      (**(code **)(**(int **)(this + 0x68) + 0x58))();
    }
  }
  (**(code **)(DAT_00d5546c + 0x18))();
  return 1;
}
}

// =================================================
// Function: CPlugSolid::OnNodLoaded
// =================================================
void __thiscall CPlugSolid::OnNodLoaded(CPlugSolid *this,CDx9DeviceCaps *param_1)
{
{
  CFastStringInt *unaff_ESI;
  
  OnAccessViolation_ConcatToCrashFileName(unaff_ESI);
  if (*(int *)(*(CPlugSolid **)(this + 100) + 0x14) == 0) {
    InternalConnectSubTree(this,*(CPlugSolid **)(this + 100),(CPlugTree *)unaff_ESI);
  }
  if (*(int *)(this + 100) != 0) {
    (**(code **)(**(int **)(this + 100) + 0x78))(0);
  }
  (**(code **)(**(int **)(this + 100) + 0xbc))(1);
  return;
}
}

// =================================================
// Function: CPlugSolid::SetModel
// =================================================
void __thiscall CPlugSolid::SetModel(CPlugSolid *this,CPlugSolid *param_1,CPlugSolid *param_2)
{
{
  CPlugTree *pCVar1;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  CPlugTree *unaff_retaddr;
  
  if (param_1 != (CPlugSolid *)0x0) {
    CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
  }
  if (*(CMwNod **)(this + 0x68) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x68),unaff_ESI);
  }
  *(CPlugSolid **)(this + 0x68) = param_1;
  if ((param_1 != (CPlugSolid *)0x0) && (((byte)this[0x70] & 1) != 0)) {
    *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
    CPlugPhysicalObject::CopyFrom(this + 0x18,(SParam_Set *)(param_1 + 0x18),(SParam *)unaff_ESI);
    pCVar1 = CPlugTree::InternalCreateSolidModelInstance
                       (*(CPlugTree **)(*(int *)(this + 0x68) + 100),unaff_retaddr);
    SetTree(this,(CPlugSolid *)pCVar1,(CPlugTree *)0x0,(int)param_1);
  }
  return;
}
}

// =================================================
// Function: CPlugSolid::SetTree
// =================================================
void __thiscall
CPlugSolid::SetTree(CPlugSolid *this,CPlugSolid *param_1,CPlugTree *param_2,int param_3)
{
{
  CPlugSolid *pCVar1;
  CPlugTree *pCVar2;
  
  pCVar1 = *(CPlugSolid **)(this + 100);
  if (param_1 != pCVar1) {
    if (pCVar1 != (CPlugSolid *)0x0) {
      (**(code **)(*(int *)pCVar1 + 4))(1);
    }
    *(CPlugSolid **)(this + 100) = param_1;
    *(CPlugSolid **)(this + 0x5c) = param_1;
    if (param_1 != (CPlugSolid *)0x0) {
      pCVar2 = (CPlugTree *)0x0;
      (**(code **)(*(int *)param_1 + 0x78))();
      InternalConnectSubTree(this,*(CPlugSolid **)(this + 100),pCVar2);
      (**(code **)(**(int **)(this + 100) + 0xbc))(param_2);
    }
  }
  return;
}
}

// =================================================
// Function: CPlugSolid::SetUseModel
// =================================================
void __thiscall CPlugSolid::SetUseModel(CPlugSolid *this,CPlugSolid *param_1,int param_2)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x70);
  if ((uVar1 & 1) != (uint)(param_1 != (CPlugSolid *)0x0)) {
    uVar1 = (param_1 != (CPlugSolid *)0x0 ^ uVar1) & 1 ^ uVar1;
    *(uint *)(this + 0x70) = uVar1;
    if (*(CPlugSolid **)(this + 0x68) != (CPlugSolid *)0x0) {
      if ((uVar1 & 1) != 0) {
        SetModel(this,*(CPlugSolid **)(this + 0x68),(CPlugSolid *)param_2);
        return;
      }
      if (*(CPlugTree **)(this + 100) != (CPlugTree *)0x0) {
        CPlugTree::DisconnectFromModel(*(CPlugTree **)(this + 100),(CPlugSolid *)0x1,-1);
      }
    }
  }
  return;
}
}

// =================================================
// Function: CPlugSolid::VirtualParam_Get
// =================================================
ulong __thiscall
CPlugSolid::VirtualParam_Get
          (CPlugSolid *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 < 0x9005006) {
    if (uVar3 == 0x9005005) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x70) & 1;
      return 0;
    }
    if (uVar3 == 0x9005000) {
      *(CPlugSolid **)param_2 = this + 0x18;
      return 0;
    }
    if (uVar3 == 0x9005001) {
      *(CPlugSolid **)param_2 = this + 0x40;
      return 0;
    }
    if (uVar3 == 0x9005002) {
      *(CPlugSolid **)param_2 = this + 0x44;
      return 0;
    }
LAB_00853fd1:
    *(int *)(param_1 + 0x18) = iVar1;
    uVar4 = CMwNod::VirtualParam_Get((CMwNod *)this,param_1,param_2,param_3);
    return uVar4;
  }
  if (uVar3 == 0x9005006) {
    *(CMwStack **)param_2 = param_2 + 4;
    *(uint *)(param_2 + 4) = *(uint *)(this + 0x70) >> 1 & 0xff;
  }
  else {
    if (uVar3 == 0x9005007) {
      *(CPlugSolid **)param_2 = this + 0x48;
      return 0;
    }
    if (uVar3 != 0xffffffff) goto LAB_00853fd1;
  }
  return 0;
}
}

// =================================================
// Function: CPlugSolid::VirtualParam_Set
// =================================================
ulong __thiscall
CPlugSolid::VirtualParam_Set(CPlugSolid *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  CFastStringInt *unaff_EDI;
  
  iVar2 = *(int *)(param_1 + 0x18);
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + iVar2 * 4);
  iVar1 = iVar2 + -1;
  *(int *)(param_1 + 0x18) = iVar1;
  uVar4 = *(uint *)(iVar3 + 4);
  if (uVar4 < 0x9005004) {
    if (uVar4 != 0x9005003) {
      if (uVar4 == 0x9005000) {
        *(undefined4 *)(this + 0x18) = *(undefined4 *)param_2;
        return 0;
      }
      if (uVar4 == 0x9005001) {
        *(undefined4 *)(this + 0x40) = *(undefined4 *)param_2;
        return 0;
      }
      if (uVar4 == 0x9005002) {
        *(undefined4 *)(this + 0x44) = *(undefined4 *)param_2;
        return 0;
      }
LAB_008540a2:
      *(int *)(param_1 + 0x18) = iVar2;
      uVar5 = CMwNod::VirtualParam_Set((CMwNod *)this,param_1,param_2,param_3);
      return uVar5;
    }
    if (-1 < iVar1) {
      CMwNod::Param_Set(*(CMwNod **)(this + 100),(CMwNod *)param_1,(CFastString *)param_2,unaff_EDI)
      ;
      return 0;
    }
  }
  else if (uVar4 == 0x9005004) {
    if (iVar1 < 0) {
      if ((*(int *)(this + 0x68) != 0) && (param_2 == (CMwStack *)0x0)) {
        DisconnectFromModel(this,(CPlugSolid *)0x0,(int)unaff_EDI);
        return 0;
      }
    }
    else {
      CMwNod::Param_Set(*(CMwNod **)(this + 0x68),(CMwNod *)param_1,(CFastString *)param_2,unaff_EDI
                       );
    }
  }
  else {
    if (uVar4 == 0x9005007) {
      *(undefined4 *)(this + 0x48) = *(undefined4 *)param_2;
      return 0;
    }
    if (uVar4 != 0xffffffff) goto LAB_008540a2;
  }
  return 0;
}
}

// =================================================
// Function: CPlugSolid::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CPlugSolid::_scalar_deleting_destructor_(CPlugSolid *this,CPfmHeap *param_1,uint param_2)
{
{
  CPlugSolid *unaff_ESI;
  
  ~CPlugSolid(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CPlugSolid::~CPlugSolid
// =================================================
void __thiscall CPlugSolid::~CPlugSolid(CPlugSolid *this,CPlugSolid *param_1)
{
{
  CMwNod *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00ad5388;
  local_c = ExceptionList;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 0;
  if (*(int **)(this + 100) != (int *)0x0) {
    (**(code **)(**(int **)(this + 100) + 4))(1);
  }
  if (*(CMwNod **)(this + 0x68) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x68),pCVar1);
    *(undefined4 *)(this + 0x68) = 0;
  }
  local_4 = 0xffffffff;
  CPlug::~CPlug((CPlug *)this,(CPlug *)pCVar1);
  ExceptionList = puStack_8;
  return;
}
}

