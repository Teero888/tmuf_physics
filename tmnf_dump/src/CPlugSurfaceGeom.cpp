// Class implementation: CPlugSurfaceGeom

// =================================================
// Function: CPlugSurfaceGeom::CPlugSurfaceGeom
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CPlugSurfaceGeom::CPlugSurfaceGeom(CPlugSurfaceGeom *this,CPlugSurfaceGeom *param_1)
{
{
  undefined4 uVar1;
  CMwId *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00adb708;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CPlug::CPlug((CPlug *)this,(CPlug *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x14,unaff_ESI);
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)(this + 0x28) = _DAT_00b2c060;
  *(undefined4 *)(this + 0x2c) = uVar1;
  *(undefined4 *)(this + 0x30) = uVar1;
  *(undefined4 *)(this + 0x18) = 1;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CPlugSurfaceGeom::Chunk
// =================================================
void __thiscall
CPlugSurfaceGeom::Chunk
          (CPlugSurfaceGeom *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  int iVar1;
  CFuncSegment *this_00;
  undefined1 *puVar2;
  CPlugVisualStrip *pCVar3;
  GmSurfMesh *extraout_EAX;
  GmSurfMesh *pGVar4;
  undefined4 *extraout_EAX_00;
  undefined4 *extraout_EAX_01;
  undefined4 *extraout_EAX_02;
  GmSurfMesh *extraout_EAX_03;
  undefined4 *extraout_EAX_04;
  undefined4 *puVar5;
  undefined4 *extraout_EAX_05;
  undefined4 *extraout_EAX_06;
  undefined4 *extraout_EAX_07;
  undefined4 *extraout_EAX_08;
  undefined4 *extraout_EAX_09;
  GmSurfMesh *extraout_EAX_10;
  CClassicArchive *unaff_EBX;
  ulong unaff_ESI;
  CClassicArchive *unaff_EDI;
  ulong unaff_retaddr;
  undefined4 in_stack_00000010;
  void *in_stack_00000014;
  GmSurfEllipsoid *in_stack_00000018;
  GmSurfEllipsoid *in_stack_0000001c;
  GmSurfSphere *in_stack_00000020;
  undefined2 uStack00000024;
  undefined2 in_stack_00000028;
  GmSurfEllipsoid *in_stack_ffffffe8;
  GmSurfEllipsoid *in_stack_ffffffec;
  CClassicArchive *pCVar6;
  GmSurfSphere *in_stack_fffffff0;
  CPlugVisualStrip *pCVar7;
  GmSurfBox *pGVar8;
  CPlugVisualStrip *pCVar9;
  void *pvVar10;
  
  this_00 = param_1;
  pvVar10 = (void *)0xffffffff;
  pCVar9 = (CPlugVisualStrip *)&LAB_00adb7b4;
  pCVar3 = (CPlugVisualStrip *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  if (param_2 < (CClassicArchive *)0x900f001) {
    if (param_2 == (CClassicArchive *)0x900f000) {
      ExceptionList = in_stack_00000014;
      return;
    }
    if (param_2 == (CClassicArchive *)0x900c000) {
      ExceptionList = &stack0xfffffff4;
      CMwId::Archive(this + 0x14,(CFastCrypt<unsigned_long> *)param_1,(CClassicArchive *)pCVar3);
      ExceptionList = pCVar9;
      return;
    }
    if (param_2 == (CClassicArchive *)0x900c001) {
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoBool
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x18),(int *)0x1,
                 (ulong)pCVar3);
      ExceptionList = pCVar9;
      return;
    }
    if (param_2 == (CClassicArchive *)0x900d002) {
      ExceptionList = &stack0xfffffff4;
      if (*(undefined4 **)(this + 0x34) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(this + 0x34))(1);
      }
      param_2 = operator_new(0x2c);
      if (param_2 == (CClassicArchive *)0x0) {
        pGVar4 = (GmSurfMesh *)0x0;
      }
      else {
        GmSurfMesh::GmSurfMesh((GmSurfMesh *)param_2,(GmSurfMesh *)pCVar3);
        pGVar4 = extraout_EAX;
      }
      *(GmSurfMesh **)(this + 0x34) = pGVar4;
      GmSurfMesh::Archive(pGVar4,(CFastCrypt<unsigned_long> *)param_1,(CClassicArchive *)pCVar3);
      ExceptionList = pCVar9;
      return;
    }
LAB_008bb935:
    ExceptionList = &stack0xfffffff4;
    CMwNod::Chunk((CMwNod *)this,param_1,param_2,(ulong)pCVar3);
    ExceptionList = pCVar9;
    return;
  }
  if ((CClassicArchive *)0x900f003 < param_2) {
    if (param_2 != (CClassicArchive *)0x900f004) {
      if (param_2 == (CClassicArchive *)0xffffffff) {
        ExceptionList = in_stack_00000014;
        return;
      }
      goto LAB_008bb935;
    }
    puVar2 = &stack0xfffffff4;
    pCVar6 = ExceptionList;
    if (*(int *)(param_1 + 8) != 0) {
      ExceptionList = &stack0xfffffff4;
      ComputeBoundingBox(this,pCVar3,(ulong)unaff_EDI,unaff_ESI);
      puVar2 = ExceptionList;
    }
    ExceptionList = puVar2;
    CMwId::Archive(this + 0x14,(CFastCrypt<unsigned_long> *)this_00,unaff_EBX);
    GmBoxAligned::ArchiveABox
              (this + 0x1c,(GmBoxAligned *)this_00,(CClassicArchive *)in_stack_ffffffe8);
    param_1 = (CFuncSegment *)(*(float *)(this + 0x1c) - *(float *)(this + 0x28));
    *(undefined4 *)(*(int *)(this_00 + 4) + 8) = 1;
    CClassicArchive::WriteNatural
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_1,(ulong *)0x1,0,
               (int)in_stack_ffffffec);
    *(undefined4 *)(*(int *)(this_00 + 4) + 8) = 0;
    if (*(int *)(this_00 + 8) != 0) {
      param_1 = (CFuncSegment *)(uint)*(byte *)(*(int *)(this + 0x34) + 6);
    }
    CClassicArchive::DoNatural
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_1,(ulong *)0x1,0,
               (int)in_stack_fffffff0);
    switch(param_2) {
    case (CClassicArchive *)0x0:
      puVar5 = *(undefined4 **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (puVar5 != (undefined4 *)0x0) {
          (**(code **)*puVar5)();
        }
        in_stack_00000020 = operator_new(0xc);
        in_stack_00000018 = (GmSurfEllipsoid *)0x8;
        if (in_stack_00000020 == (GmSurfSphere *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          GmSurfSphere::GmSurfSphere(in_stack_00000020,(GmSurfSphere *)pCVar6);
          puVar5 = extraout_EAX_07;
        }
        in_stack_00000018 = (GmSurfEllipsoid *)0xffffffff;
        *(undefined4 **)(this + 0x34) = puVar5;
      }
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(puVar5 + 2),(float *)0x1,
                 (ulong)pCVar6);
      break;
    case (CClassicArchive *)0x1:
      puVar5 = *(undefined4 **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (puVar5 != (undefined4 *)0x0) {
          (**(code **)*puVar5)();
        }
        in_stack_00000020 = operator_new(0x14);
        in_stack_00000018 = (GmSurfEllipsoid *)0xa;
        if (in_stack_00000020 == (GmSurfSphere *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          GmSurfEllipsoid::GmSurfEllipsoid
                    ((GmSurfEllipsoid *)in_stack_00000020,(GmSurfEllipsoid *)pCVar6);
          puVar5 = extraout_EAX_09;
        }
        in_stack_00000018 = (GmSurfEllipsoid *)0xffffffff;
        *(undefined4 **)(this + 0x34) = puVar5;
      }
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(puVar5 + 2),(float *)0x1,
                 (ulong)pCVar6);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(puVar5 + 3),(float *)0x1,
                 (ulong)pCVar9);
      pCVar6 = (CClassicArchive *)(puVar5 + 4);
      CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar6,(float *)0x1,(ulong)pvVar10);
      break;
    case (CClassicArchive *)0x6:
      puVar5 = *(undefined4 **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (puVar5 != (undefined4 *)0x0) {
          (**(code **)*puVar5)();
        }
        in_stack_00000020 = operator_new(0x20);
        in_stack_00000018 = (GmSurfEllipsoid *)0x9;
        if (in_stack_00000020 == (GmSurfSphere *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          GmSurfBox::GmSurfBox((GmSurfBox *)in_stack_00000020,(GmSurfBox *)pCVar6);
          puVar5 = extraout_EAX_08;
        }
        in_stack_00000018 = (GmSurfEllipsoid *)0xffffffff;
        *(undefined4 **)(this + 0x34) = puVar5;
      }
      GmBoxAligned::ArchiveABoxOld1(puVar5 + 2,(GmBoxAligned *)this_00,pCVar6);
      break;
    case (CClassicArchive *)0x7:
      pGVar4 = *(GmSurfMesh **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (pGVar4 != (GmSurfMesh *)0x0) {
          (*(code *)**(undefined4 **)pGVar4)();
        }
        in_stack_00000020 = operator_new(0x2c);
        in_stack_00000018 = (GmSurfEllipsoid *)0xb;
        if (in_stack_00000020 == (GmSurfSphere *)0x0) {
          pGVar4 = (GmSurfMesh *)0x0;
        }
        else {
          GmSurfMesh::GmSurfMesh((GmSurfMesh *)in_stack_00000020,(GmSurfMesh *)pCVar6);
          pGVar4 = extraout_EAX_10;
        }
        in_stack_00000018 = (GmSurfEllipsoid *)0xffffffff;
        *(GmSurfMesh **)(this + 0x34) = pGVar4;
      }
      GmSurfMesh::Archive(pGVar4,(CFastCrypt<unsigned_long> *)this_00,pCVar6);
    }
    _uStack00000024 = (GmSurfBox *)0x0;
    if (*(int *)(this + 0x34) != 0) {
      _uStack00000024 = (GmSurfBox *)(uint)*(ushort *)(*(int *)(this + 0x34) + 4);
    }
    CClassicArchive::DoNat16
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000024,(ushort *)0x1,0,
               (int)pCVar6);
    if (*(int *)(this_00 + 8) != 0) {
      ExceptionList = in_stack_00000014;
      return;
    }
    iVar1 = *(int *)(this + 0x34);
joined_r0x008bbb7a:
    if (iVar1 != 0) {
      *(undefined2 *)(iVar1 + 4) = in_stack_00000028;
    }
    ExceptionList = in_stack_00000014;
    return;
  }
  if (param_2 == (CClassicArchive *)0x900f003) {
    ExceptionList = &stack0xfffffff4;
    CMwId::Archive(this + 0x14,(CFastCrypt<unsigned_long> *)param_1,(CClassicArchive *)pCVar3);
    GmBoxAligned::ArchiveABox(this + 0x1c,(GmBoxAligned *)this_00,unaff_EDI);
    ExceptionList = pvVar10;
    return;
  }
  if (param_2 != (CClassicArchive *)0x900f001) {
    if (param_2 != (CClassicArchive *)0x900f002) goto LAB_008bb935;
    if (*(int *)(param_1 + 8) != 0) {
      in_stack_ffffffe8 = (GmSurfEllipsoid *)(uint)*(byte *)(*(int *)(this + 0x34) + 6);
    }
    pCVar7 = ExceptionList;
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xffffffe8,(ulong *)0x1,0,
               (int)pCVar3);
    switch(in_stack_ffffffec) {
    case (GmSurfEllipsoid *)0x0:
      puVar5 = *(undefined4 **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (puVar5 != (undefined4 *)0x0) {
          (**(code **)*puVar5)(1);
        }
        in_stack_00000020 = operator_new(0xc);
        in_stack_00000014 = (void *)0x4;
        if (in_stack_00000020 == (GmSurfSphere *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          GmSurfSphere::GmSurfSphere(in_stack_00000020,in_stack_fffffff0);
          puVar5 = extraout_EAX_00;
        }
        in_stack_00000014 = (void *)0xffffffff;
        *(undefined4 **)(this + 0x34) = puVar5;
      }
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(puVar5 + 2),(float *)0x1,
                 (ulong)in_stack_fffffff0);
      break;
    case (GmSurfEllipsoid *)0x1:
      puVar5 = *(undefined4 **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (puVar5 != (undefined4 *)0x0) {
          (**(code **)*puVar5)(1);
        }
        in_stack_00000018 = operator_new(0x14);
        param_3 = 6;
        if (in_stack_00000018 == (GmSurfEllipsoid *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          GmSurfEllipsoid::GmSurfEllipsoid(in_stack_00000018,in_stack_ffffffe8);
          puVar5 = extraout_EAX_02;
        }
        param_3 = 0xffffffff;
        *(undefined4 **)(this + 0x34) = puVar5;
      }
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(puVar5 + 2),(float *)0x1,
                 (ulong)in_stack_ffffffe8);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(puVar5 + 3),(float *)0x1,
                 (ulong)in_stack_ffffffec);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(puVar5 + 4),(float *)0x1,
                 (ulong)in_stack_fffffff0);
      break;
    case (GmSurfEllipsoid *)0x6:
      puVar5 = *(undefined4 **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (puVar5 != (undefined4 *)0x0) {
          (**(code **)*puVar5)(1);
        }
        in_stack_00000020 = operator_new(0x20);
        in_stack_00000014 = (void *)0x5;
        if (in_stack_00000020 == (GmSurfSphere *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          GmSurfBox::GmSurfBox((GmSurfBox *)in_stack_00000020,(GmSurfBox *)in_stack_fffffff0);
          puVar5 = extraout_EAX_01;
        }
        in_stack_00000014 = (void *)0xffffffff;
        *(undefined4 **)(this + 0x34) = puVar5;
      }
      GmBoxAligned::ArchiveABoxOld1
                (puVar5 + 2,(GmBoxAligned *)this_00,(CClassicArchive *)in_stack_fffffff0);
      break;
    case (GmSurfEllipsoid *)0x7:
      pGVar4 = *(GmSurfMesh **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (pGVar4 != (GmSurfMesh *)0x0) {
          (*(code *)**(undefined4 **)pGVar4)(1);
        }
        in_stack_00000020 = operator_new(0x2c);
        in_stack_00000014 = (void *)0x7;
        if (in_stack_00000020 == (GmSurfSphere *)0x0) {
          pGVar4 = (GmSurfMesh *)0x0;
        }
        else {
          GmSurfMesh::GmSurfMesh((GmSurfMesh *)in_stack_00000020,(GmSurfMesh *)in_stack_fffffff0);
          pGVar4 = extraout_EAX_03;
        }
        in_stack_00000014 = (void *)0xffffffff;
        *(GmSurfMesh **)(this + 0x34) = pGVar4;
      }
      GmSurfMesh::Archive(pGVar4,(CFastCrypt<unsigned_long> *)this_00,
                          (CClassicArchive *)in_stack_fffffff0);
    }
    if (*(int *)(this_00 + 8) == 0) {
      ComputeBoundingBox(this,pCVar7,(ulong)pCVar9,(ulong)pvVar10);
    }
    in_stack_00000020 = (GmSurfSphere *)0x0;
    if (*(int *)(this + 0x34) != 0) {
      in_stack_00000020 = (GmSurfSphere *)(uint)*(ushort *)(*(int *)(this + 0x34) + 4);
    }
    CClassicArchive::DoNat16
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000020,(ushort *)0x1,0,
               (int)pCVar7);
    if (*(int *)(this_00 + 8) != 0) {
      ExceptionList = in_stack_00000014;
      return;
    }
    iVar1 = *(int *)(this + 0x34);
    in_stack_00000028 = uStack00000024;
    goto joined_r0x008bbb7a;
  }
  if (*(int *)(param_1 + 8) != 0) {
    param_1 = (CFuncSegment *)(uint)*(byte *)(*(int *)(this + 0x34) + 6);
  }
  pGVar8 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  CClassicArchive::DoNatural
            ((CClassicArchive *)this_00,(CClassicArchive *)&param_1,(ulong *)0x1,0,(int)pCVar3);
  if (param_2 == (CClassicArchive *)0x0) {
    puVar5 = *(undefined4 **)(this + 0x34);
    if (*(int *)(this_00 + 8) == 0) {
      if (puVar5 != (undefined4 *)0x0) {
        (**(code **)*puVar5)(1);
      }
      _uStack00000024 = operator_new(0xc);
      in_stack_00000018 = (GmSurfEllipsoid *)0x1;
      if (_uStack00000024 == (GmSurfBox *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        GmSurfSphere::GmSurfSphere((GmSurfSphere *)_uStack00000024,(GmSurfSphere *)pGVar8);
        puVar5 = extraout_EAX_06;
      }
      in_stack_00000018 = (GmSurfEllipsoid *)0xffffffff;
      *(undefined4 **)(this + 0x34) = puVar5;
    }
    pCVar6 = (CClassicArchive *)(puVar5 + 2);
  }
  else {
    if (param_2 != (CClassicArchive *)0x1) {
      if (param_2 == (CClassicArchive *)&DAT_00000006) {
        puVar5 = *(undefined4 **)(this + 0x34);
        if (*(int *)(this_00 + 8) == 0) {
          if (puVar5 != (undefined4 *)0x0) {
            (**(code **)*puVar5)(1);
          }
          _uStack00000024 = operator_new(0x20);
          in_stack_00000018 = (GmSurfEllipsoid *)0x2;
          if (_uStack00000024 == (GmSurfBox *)0x0) {
            puVar5 = (undefined4 *)0x0;
          }
          else {
            GmSurfBox::GmSurfBox(_uStack00000024,pGVar8);
            puVar5 = extraout_EAX_04;
          }
          in_stack_00000018 = (GmSurfEllipsoid *)0xffffffff;
          *(undefined4 **)(this + 0x34) = puVar5;
        }
        GmBoxAligned::ArchiveABoxOld1(puVar5 + 2,(GmBoxAligned *)this_00,(CClassicArchive *)pGVar8);
      }
      goto LAB_008bb8d4;
    }
    puVar5 = *(undefined4 **)(this + 0x34);
    if (*(int *)(this_00 + 8) == 0) {
      if (puVar5 != (undefined4 *)0x0) {
        (**(code **)*puVar5)(1);
      }
      in_stack_0000001c = operator_new(0x14);
      in_stack_00000010 = 3;
      if (in_stack_0000001c == (GmSurfEllipsoid *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        GmSurfEllipsoid::GmSurfEllipsoid(in_stack_0000001c,in_stack_ffffffec);
        puVar5 = extraout_EAX_05;
      }
      in_stack_00000010 = 0xffffffff;
      *(undefined4 **)(this + 0x34) = puVar5;
    }
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(puVar5 + 2),(float *)0x1,
               (ulong)in_stack_ffffffec);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(puVar5 + 3),(float *)0x1,
               (ulong)in_stack_fffffff0);
    pCVar6 = (CClassicArchive *)(puVar5 + 4);
  }
  CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar6,(float *)0x1,(ulong)pGVar8);
LAB_008bb8d4:
  if (*(int *)(this_00 + 8) != 0) {
    ExceptionList = in_stack_00000014;
    return;
  }
  ComputeBoundingBox(this,pCVar9,(ulong)pvVar10,unaff_retaddr);
  ExceptionList = in_stack_00000020;
  return;
}
}

// =================================================
// Function: CPlugSurfaceGeom::ComputeBoundingBox
// =================================================
void __thiscall
CPlugSurfaceGeom::ComputeBoundingBox
          (CPlugSurfaceGeom *this,CPlugVisualStrip *param_1,ulong param_2,ulong param_3)
{
{
  GmBoxAligned *unaff_retaddr;
  
  GmSurf::GetBoundingBox(*(GmSurf **)(this + 0x34),(GmSurf *)(this + 0x1c),unaff_retaddr);
  return;
}
}

// =================================================
// Function: CPlugSurfaceGeom::CreateDefaultData
// =================================================
void __thiscall CPlugSurfaceGeom::CreateDefaultData(CPlugSurfaceGeom *this,CCrystal *param_1)
{
{
  GmSurfSphere *pGVar1;
  GmSurfSphere *this_00;
  int extraout_EAX;
  int iVar2;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00adb68b;
  local_c = ExceptionList;
  pGVar1 = (GmSurfSphere *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  this_00 = operator_new(0xc);
  local_4 = 0;
  if (this_00 == (GmSurfSphere *)0x0) {
    iVar2 = 0;
  }
  else {
    GmSurfSphere::GmSurfSphere(this_00,pGVar1);
    iVar2 = extraout_EAX;
  }
  *(int *)(this + 0x34) = iVar2;
  *(undefined4 *)(iVar2 + 8) = 0x3f800000;
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CPlugSurfaceGeom::GetChunkInfo
// =================================================
ulong __thiscall
CPlugSurfaceGeom::GetChunkInfo(CPlugSurfaceGeom *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 < (CFuncSegment *)0x900f001) {
    if ((((param_1 == (CFuncSegment *)0x900f000) || (param_1 == (CFuncSegment *)0x900c000)) ||
        (param_1 == (CFuncSegment *)0x900c001)) || (param_1 == (CFuncSegment *)0x900d002)) {
      return 1;
    }
  }
  else if (param_1 < (CFuncSegment *)0x900f004) {
    if (param_1 == (CFuncSegment *)0x900f003) {
      return 1;
    }
    if (param_1 == (CFuncSegment *)0x900f001) {
      return 1;
    }
    if (param_1 == (CFuncSegment *)0x900f002) {
      return 1;
    }
  }
  else {
    if (param_1 == (CFuncSegment *)0x900f004) {
      return 3;
    }
    if (param_1 == (CFuncSegment *)0xffffffff) {
      return 0xffffffff;
    }
  }
  uVar1 = CMwNod::GetChunkInfo((CMwNod *)this,param_1,param_2);
  return uVar1;
}
}

// =================================================
// Function: CPlugSurfaceGeom::GetMwClassId
// =================================================
ulong __thiscall CPlugSurfaceGeom::GetMwClassId(CPlugSurfaceGeom *this,CControlStyle *param_1)
{
{
  return 0x900f000;
}
}

// =================================================
// Function: CPlugSurfaceGeom::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CPlugSurfaceGeom::GetUidChunkFromIndex
          (CPlugSurfaceGeom *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0x900f000;
}
}

// =================================================
// Function: CPlugSurfaceGeom::GetVolume
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall CPlugSurfaceGeom::GetVolume(CPlugSurfaceGeom *this,CPlugSurfaceGeom *param_1)
{
{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 0x34);
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + 6);
    if (cVar1 == '\0') {
      return *(float *)(iVar2 + 8) * (float)_DAT_00bb8ac0 * *(float *)(iVar2 + 8) *
             *(float *)(iVar2 + 8);
    }
    if (cVar1 == '\x01') {
      return *(float *)(iVar2 + 8) * (float)_DAT_00bb8ac0 * *(float *)(iVar2 + 0xc) *
             *(float *)(iVar2 + 0x10);
    }
    if (cVar1 == '\x06') {
      return ((*(float *)(iVar2 + 0x18) + *(float *)(iVar2 + 0xc)) -
             (*(float *)(iVar2 + 0xc) - *(float *)(iVar2 + 0x18))) *
             ((*(float *)(iVar2 + 0x14) + *(float *)(iVar2 + 8)) -
             (*(float *)(iVar2 + 8) - *(float *)(iVar2 + 0x14))) *
             ((*(float *)(iVar2 + 0x1c) + *(float *)(iVar2 + 0x10)) -
             (*(float *)(iVar2 + 0x10) - *(float *)(iVar2 + 0x1c)));
    }
  }
  return 0.0;
}
}

// =================================================
// Function: CPlugSurfaceGeom::GetWeightDistrib
// =================================================
void __thiscall
CPlugSurfaceGeom::GetWeightDistrib
          (CPlugSurfaceGeom *this,CPlugSurfaceGeom *param_1,ulong param_2,GmVec3 *param_3)
{
{
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)param_2 = 0;
  return;
}
}

// =================================================
// Function: CPlugSurfaceGeom::GetWeightDistribCount
// =================================================
ulong __thiscall
CPlugSurfaceGeom::GetWeightDistribCount(CPlugSurfaceGeom *this,CPlugSurfaceGeom *param_1)
{
{
  return (uint)(*(int *)(this + 0x18) != 0);
}
}

// =================================================
// Function: CPlugSurfaceGeom::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall
CPlugSurfaceGeom::MwGetClassInfo(CPlugSurfaceGeom *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d6fb1c;
}
}

// =================================================
// Function: CPlugSurfaceGeom::MwIsKindOf
// =================================================
int __thiscall
CPlugSurfaceGeom::MwIsKindOf(CPlugSurfaceGeom *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if ((param_1 != (CMwCmdAffectParam *)0x900f000) && (param_1 != (CMwCmdAffectParam *)0x902b000)) {
    return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
  }
  return 1;
}
}

// =================================================
// Function: CPlugSurfaceGeom::MwNewCPlugSurfaceGeom
// =================================================
CMwNod * __cdecl CPlugSurfaceGeom::MwNewCPlugSurfaceGeom(void)
{
{
  CPlugSurfaceGeom *pCVar1;
  CMwNod *extraout_EAX;
  CPlugSurfaceGeom *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00adb7db;
  local_c = ExceptionList;
  pCVar1 = (CPlugSurfaceGeom *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x3c);
  local_4 = 0;
  if (local_10 != (CPlugSurfaceGeom *)0x0) {
    CPlugSurfaceGeom(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CPlugSurfaceGeom::SetGmSurfType
// =================================================
void __thiscall
CPlugSurfaceGeom::SetGmSurfType
          (CPlugSurfaceGeom *this,CPlugSurfaceGeom *param_1,EGmSurfType *param_2)
{
{
  undefined4 *puVar1;
  void **ppvVar2;
  GmSurfSphere *pGVar3;
  GmSurfSphere *this_00;
  GmSurf *extraout_EAX;
  GmSurfPolygon *this_01;
  GmSurf *extraout_EAX_00;
  GmSurfBox *this_02;
  GmSurf *extraout_EAX_01;
  GmSurfEllipsoid *this_03;
  GmSurf *extraout_EAX_02;
  GmSurf *this_04;
  CCrystal *in_stack_ffffffd8;
  CPlugVisualStrip *in_stack_ffffffdc;
  ulong uVar4;
  ulong uVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00adb6dc;
  local_c = ExceptionList;
  pGVar3 = (GmSurfSphere *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  puVar1 = *(undefined4 **)(this + 0x34);
  ppvVar2 = &local_c;
  if (puVar1 != (undefined4 *)0x0) {
    if ((uint)*(byte *)((int)puVar1 + 6) == *(uint *)param_1) {
      return;
    }
    if (puVar1 != (undefined4 *)0x0) {
      ExceptionList = &local_c;
      (**(code **)*puVar1)(1);
      ppvVar2 = ExceptionList;
    }
  }
  ExceptionList = ppvVar2;
  *(undefined4 *)(this + 0x34) = 0;
  switch(*(undefined4 *)param_1) {
  case 0:
    uVar5 = 0xc;
    uVar4 = 0x8bb0d7;
    this_00 = operator_new(0xc);
    uStack_4 = 0;
    if (this_00 == (GmSurfSphere *)0x0) {
LAB_008bb15e:
      this_04 = (GmSurf *)0x0;
    }
    else {
      uVar5 = 0x8bb0f1;
      GmSurfSphere::GmSurfSphere(this_00,pGVar3);
      this_04 = extraout_EAX;
    }
    break;
  case 1:
    uVar5 = 0x14;
    uVar4 = 0x8bb142;
    this_03 = operator_new(0x14);
    uStack_4 = 3;
    if (this_03 == (GmSurfEllipsoid *)0x0) goto LAB_008bb15e;
    uVar5 = 0x8bb15c;
    GmSurfEllipsoid::GmSurfEllipsoid(this_03,(GmSurfEllipsoid *)pGVar3);
    this_04 = extraout_EAX_02;
    break;
  default:
    goto switchD_008bb0c9_caseD_2;
  case 5:
    uVar5 = 0x4c;
    uVar4 = 0x8bb0fa;
    this_01 = operator_new(0x4c);
    uStack_4 = 1;
    if (this_01 == (GmSurfPolygon *)0x0) goto LAB_008bb15e;
    uVar5 = 3;
    uVar4 = 0x8bb116;
    GmSurfPolygon::GmSurfPolygon(this_01,(GmSurfPolygon *)0x3,(uchar)pGVar3);
    this_04 = extraout_EAX_00;
    break;
  case 6:
    uVar5 = 0x20;
    uVar4 = 0x8bb11f;
    this_02 = operator_new(0x20);
    uStack_4 = 2;
    if (this_02 == (GmSurfBox *)0x0) goto LAB_008bb15e;
    uVar5 = 0x8bb139;
    GmSurfBox::GmSurfBox(this_02,(GmSurfBox *)pGVar3);
    this_04 = extraout_EAX_01;
  }
  *(GmSurf **)(this + 0x34) = this_04;
  GmSurf::CreateDefaultData(this_04,in_stack_ffffffd8);
  ComputeBoundingBox(this,in_stack_ffffffdc,uVar4,uVar5);
switchD_008bb0c9_caseD_2:
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CPlugSurfaceGeom::TransformByNOMat
// =================================================
void __thiscall
CPlugSurfaceGeom::TransformByNOMat(CPlugSurfaceGeom *this,GmSurfMesh *param_1,GmIso4 *param_2)
{
{
  GmSurfMesh *this_00;
  GmIso4 *unaff_ESI;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  this_00 = *(GmSurfMesh **)(this + 0x34);
  if (this_00 != (GmSurfMesh *)0x0) {
    if (this_00[6] == (GmSurfMesh)0x0) {
      local_c = *(undefined4 *)(this_00 + 8);
      local_8 = 0;
      local_4 = 0;
      GmVec3::Mult(&local_c,(GmIso3 *)param_1,(GmIso3 *)unaff_ESI);
      *(undefined4 *)(this_00 + 8) = local_8;
    }
    else if (this_00[6] == (GmSurfMesh)0x7) {
      GmSurfMesh::TransformByNOMat(this_00,param_1,unaff_ESI);
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CPlugSurfaceGeom::VirtualParam_Get
// =================================================
ulong __thiscall
CPlugSurfaceGeom::VirtualParam_Get
          (CPlugSurfaceGeom *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  CFuncColorGradient *pCVar6;
  
  iVar2 = *(int *)(param_1 + 0x18);
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + iVar2 * 4);
  *(int *)(param_1 + 0x18) = iVar2 + -1;
  uVar4 = *(uint *)(iVar3 + 4);
  if (uVar4 < 0x900f003) {
    if (uVar4 == 0x900f002) {
      iVar2 = *(int *)(this + 0x34);
      pCVar6 = (CFuncColorGradient *)&DAT_00d181f4;
      if ((iVar2 != 0) && (*(char *)(iVar2 + 6) == '\x01')) {
        pCVar6 = (CFuncColorGradient *)(iVar2 + 8);
      }
      CMwParamVec3::GetValue((CMwParamVec3 *)param_2,pCVar6,(float)param_1);
      return 0;
    }
    if (uVar4 == 0x900f000) {
      if (*(int *)(this + 0x34) != 0) {
        bVar1 = *(byte *)(*(int *)(this + 0x34) + 6);
        *(CMwStack **)param_2 = param_2 + 4;
        *(uint *)(param_2 + 4) = (uint)bVar1;
        return 0;
      }
      *(CMwStack **)param_2 = param_2 + 4;
      *(undefined4 *)(param_2 + 4) = 0xffffffff;
      return 0;
    }
    if (uVar4 != 0x900f001) {
LAB_008bb448:
      *(int *)(param_1 + 0x18) = iVar2;
      uVar5 = CMwNod::VirtualParam_Get((CMwNod *)this,param_1,param_2,param_3);
      return uVar5;
    }
    iVar2 = *(int *)(this + 0x34);
    param_1 = (CPlugBlendShapes *)0x3f800000;
    if ((iVar2 != 0) && (*(char *)(iVar2 + 6) == '\0')) {
      param_1 = *(CPlugBlendShapes **)(iVar2 + 8);
    }
    *(CPlugBlendShapes **)(param_2 + 4) = param_1;
    *(CMwStack **)param_2 = param_2 + 4;
  }
  else if (uVar4 != 0xffffffff) goto LAB_008bb448;
  return 0;
}
}

// =================================================
// Function: CPlugSurfaceGeom::VirtualParam_Set
// =================================================
ulong __thiscall
CPlugSurfaceGeom::VirtualParam_Set
          (CPlugSurfaceGeom *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  CPlugVisualStrip *unaff_ESI;
  CPlugVisualStrip *unaff_EDI;
  ulong unaff_retaddr;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 < 0x900f003) {
    if (uVar3 == 0x900f002) {
      iVar1 = *(int *)(this + 0x34);
      if ((iVar1 != 0) && (*(char *)(iVar1 + 6) == '\x01')) {
        CMwParamVec3::SetValue((CMwParamVec3 *)(iVar1 + 8),(CMwCmdAffectParamBool *)(iVar1 + 8));
        ComputeBoundingBox(this,unaff_ESI,unaff_retaddr,(ulong)param_1);
        return 0;
      }
    }
    else {
      if (uVar3 == 0x900f000) {
        SetGmSurfType(this,(CPlugSurfaceGeom *)param_2,(EGmSurfType *)unaff_EDI);
        return 0;
      }
      if (uVar3 != 0x900f001) goto LAB_008bb359;
      iVar1 = *(int *)(this + 0x34);
      if ((iVar1 != 0) && (*(char *)(iVar1 + 6) == '\0')) {
        *(undefined4 *)(iVar1 + 8) = *(undefined4 *)param_2;
        ComputeBoundingBox(this,unaff_EDI,(ulong)unaff_ESI,unaff_retaddr);
      }
    }
  }
  else if (uVar3 != 0xffffffff) {
LAB_008bb359:
    *(int *)(param_1 + 0x18) = iVar1;
    uVar4 = CMwNod::VirtualParam_Set((CMwNod *)this,param_1,param_2,unaff_EDI);
    return uVar4;
  }
  return 0;
}
}

// =================================================
// Function: CPlugSurfaceGeom::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CPlugSurfaceGeom::_scalar_deleting_destructor_
          (CPlugSurfaceGeom *this,CPfmHeap *param_1,uint param_2)
{
{
  CPlugSurfaceGeom *unaff_ESI;
  
  ~CPlugSurfaceGeom(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CPlugSurfaceGeom::~CPlugSurfaceGeom
// =================================================
void __thiscall
CPlugSurfaceGeom::~CPlugSurfaceGeom(CPlugSurfaceGeom *this,CPlugSurfaceGeom *param_1)
{
{
  CFastStringInt *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00adb663;
  local_c = ExceptionList;
  pCVar1 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 1;
  if (*(undefined4 **)(this + 0x34) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(this + 0x34))(1);
  }
  local_4 = local_4 & 0xffffff00;
  OnAccessViolation_ConcatToCrashFileName(pCVar1);
  local_4 = 0xffffffff;
  CPlug::~CPlug((CPlug *)this,(CPlug *)pCVar1);
  ExceptionList = puStack_8;
  return;
}
}

