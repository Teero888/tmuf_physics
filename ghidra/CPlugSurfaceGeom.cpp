
/* public: virtual void * __thiscall CPlugSurfaceGeom::`scalar deleting
 * destructor'(unsigned int) */

void *__thiscall CPlugSurfaceGeom::`scalar_deleting_destructor'(CPlugSurfaceGeom *this,uint param_1)

{
  ~CPlugSurfaceGeom(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: virtual void __thiscall CPlugSurfaceGeom::Chunk(class CClassicArchive
 * &,unsigned long) */

void __thiscall CPlugSurfaceGeom::Chunk(CPlugSurfaceGeom *this,
                                        CClassicArchive *param_1, ulong param_2)

{
  CClassicArchive *this_00;
  GmSurfMesh *this_01;
  undefined4 *puVar1;
  int iVar2;
  float *pfVar3;
  uint local_18;
  uint local_14;
  float local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  this_00 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00adb7b4;
  local_c = ExceptionList;
  if (param_2 < 0x900f001) {
    if (param_2 == 0x900f000) {
      return;
    }
    if (param_2 == 0x900c000) {
      ExceptionList = &local_c;
      CMwId::Archive((CMwId *)(this + 0x14), param_1);
      ExceptionList = local_c;
      return;
    }
    if (param_2 == 0x900c001) {
      ExceptionList = &local_c;
      CClassicArchive::DoBool(param_1, (int *)(this + 0x18), 1);
      ExceptionList = local_c;
      return;
    }
    if (param_2 == 0x900d002) {
      ExceptionList = &local_c;
      if (*(undefined4 **)(this + 0x34) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(this + 0x34))(
            1, ___security_cookie ^ (uint)&stack0xffffffdc);
      }
      param_2 = (ulong)operator_new(0x2c);
      local_4 = 0;
      if ((GmSurfMesh *)param_2 == (GmSurfMesh *)0x0) {
        this_01 = (GmSurfMesh *)0x0;
      } else {
        this_01 = (GmSurfMesh *)GmSurfMesh::GmSurfMesh((GmSurfMesh *)param_2);
      }
      local_4 = 0xffffffff;
      *(GmSurfMesh **)(this + 0x34) = this_01;
      GmSurfMesh::Archive(this_01, param_1);
      ExceptionList = local_c;
      return;
    }
  LAB_008bb935:
    ExceptionList = &local_c;
    CMwNod::Chunk((CMwNod *)this, param_1, param_2);
    ExceptionList = local_c;
    return;
  }
  if (0x900f003 < param_2) {
    if (param_2 != 0x900f004) {
      if (param_2 == 0xffffffff) {
        return;
      }
      goto LAB_008bb935;
    }
    ExceptionList = &local_c;
    if (*(int *)(param_1 + 8) != 0) {
      ComputeBoundingBox(this);
    }
    CMwId::Archive((CMwId *)(this + 0x14), this_00);
    GmBoxAligned::ArchiveABox((GmBoxAligned *)(this + 0x1c), this_00);
    local_10 = *(float *)(this + 0x1c) - *(float *)(this + 0x28);
    *(undefined4 *)(*(int *)(this_00 + 4) + 8) = 1;
    CClassicArchive::WriteNatural(this_00, (ulong *)&local_10, 1, 0);
    *(undefined4 *)(*(int *)(this_00 + 4) + 8) = 0;
    if (*(int *)(this_00 + 8) != 0) {
      local_14 = (uint) * (byte *)(*(int *)(this + 0x34) + 6);
    }
    CClassicArchive::DoNatural(this_00, &local_14, 1, 0);
    switch (local_14) {
    case 0:
      puVar1 = *(undefined4 **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        param_1 = (CClassicArchive *)operator_new(0xc);
        local_4 = 8;
        if (param_1 == (CClassicArchive *)0x0) {
          puVar1 = (undefined4 *)0x0;
        } else {
          puVar1 =
              (undefined4 *)GmSurfSphere::GmSurfSphere((GmSurfSphere *)param_1);
        }
        local_4 = 0xffffffff;
        *(undefined4 **)(this + 0x34) = puVar1;
      }
      CClassicArchive::DoReal(this_00, (float *)(puVar1 + 2), 1);
      break;
    case 1:
      puVar1 = *(undefined4 **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        param_1 = (CClassicArchive *)operator_new(0x14);
        local_4 = 10;
        if (param_1 == (CClassicArchive *)0x0) {
          puVar1 = (undefined4 *)0x0;
        } else {
          puVar1 = (undefined4 *)GmSurfEllipsoid::GmSurfEllipsoid(
              (GmSurfEllipsoid *)param_1);
        }
        local_4 = 0xffffffff;
        *(undefined4 **)(this + 0x34) = puVar1;
      }
      CClassicArchive::DoReal(this_00, (float *)(puVar1 + 2), 1);
      CClassicArchive::DoReal(this_00, (float *)(puVar1 + 3), 1);
      CClassicArchive::DoReal(this_00, (float *)(puVar1 + 4), 1);
      break;
    case 6:
      puVar1 = *(undefined4 **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        param_1 = (CClassicArchive *)operator_new(0x20);
        local_4 = 9;
        if (param_1 == (CClassicArchive *)0x0) {
          puVar1 = (undefined4 *)0x0;
        } else {
          puVar1 = (undefined4 *)GmSurfBox::GmSurfBox((GmSurfBox *)param_1);
        }
        local_4 = 0xffffffff;
        *(undefined4 **)(this + 0x34) = puVar1;
      }
      GmBoxAligned::ArchiveABoxOld1((GmBoxAligned *)(puVar1 + 2), this_00);
      break;
    case 7:
      puVar1 = *(undefined4 **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        param_1 = (CClassicArchive *)operator_new(0x2c);
        local_4 = 0xb;
        if (param_1 == (CClassicArchive *)0x0) {
          puVar1 = (undefined4 *)0x0;
        } else {
          puVar1 = (undefined4 *)GmSurfMesh::GmSurfMesh((GmSurfMesh *)param_1);
        }
        local_4 = 0xffffffff;
        *(undefined4 **)(this + 0x34) = puVar1;
      }
      GmSurfMesh::Archive((GmSurfMesh *)puVar1, this_00);
    }
    param_2 = 0;
    if (*(int *)(this + 0x34) != 0) {
      param_2 = (ulong) * (ushort *)(*(int *)(this + 0x34) + 4);
    }
    CClassicArchive::DoNat16(this_00, (ushort *)&param_2, 1, 0);
    if (*(int *)(this_00 + 8) != 0) {
      ExceptionList = local_c;
      return;
    }
    iVar2 = *(int *)(this + 0x34);
    if (iVar2 == 0) {
      ExceptionList = local_c;
      return;
    }
    param_1._0_2_ = (undefined2)param_2;
  LAB_008bbb81:
    *(undefined2 *)(iVar2 + 4) = param_1._0_2_;
    ExceptionList = local_c;
    return;
  }
  if (param_2 == 0x900f003) {
    ExceptionList = &local_c;
    CMwId::Archive((CMwId *)(this + 0x14), param_1);
    GmBoxAligned::ArchiveABox((GmBoxAligned *)(this + 0x1c), this_00);
    ExceptionList = local_c;
    return;
  }
  if (param_2 != 0x900f001) {
    if (param_2 != 0x900f002)
      goto LAB_008bb935;
    if (*(int *)(param_1 + 8) != 0) {
      local_18 = (uint) * (byte *)(*(int *)(this + 0x34) + 6);
    }
    ExceptionList = &local_c;
    CClassicArchive::DoNatural(param_1, &local_18, 1, 0);
    switch (local_18) {
    case 0:
      puVar1 = *(undefined4 **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        param_2 = (ulong)operator_new(0xc);
        local_4 = 4;
        if ((GmSurfSphere *)param_2 == (GmSurfSphere *)0x0) {
          puVar1 = (undefined4 *)0x0;
        } else {
          puVar1 =
              (undefined4 *)GmSurfSphere::GmSurfSphere((GmSurfSphere *)param_2);
        }
        local_4 = 0xffffffff;
        *(undefined4 **)(this + 0x34) = puVar1;
      }
      CClassicArchive::DoReal(this_00, (float *)(puVar1 + 2), 1);
      break;
    case 1:
      puVar1 = *(undefined4 **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        param_2 = (ulong)operator_new(0x14);
        local_4 = 6;
        if ((GmSurfEllipsoid *)param_2 == (GmSurfEllipsoid *)0x0) {
          puVar1 = (undefined4 *)0x0;
        } else {
          puVar1 = (undefined4 *)GmSurfEllipsoid::GmSurfEllipsoid(
              (GmSurfEllipsoid *)param_2);
        }
        local_4 = 0xffffffff;
        *(undefined4 **)(this + 0x34) = puVar1;
      }
      CClassicArchive::DoReal(this_00, (float *)(puVar1 + 2), 1);
      CClassicArchive::DoReal(this_00, (float *)(puVar1 + 3), 1);
      CClassicArchive::DoReal(this_00, (float *)(puVar1 + 4), 1);
      break;
    case 6:
      puVar1 = *(undefined4 **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        param_2 = (ulong)operator_new(0x20);
        local_4 = 5;
        if ((GmSurfBox *)param_2 == (GmSurfBox *)0x0) {
          puVar1 = (undefined4 *)0x0;
        } else {
          puVar1 = (undefined4 *)GmSurfBox::GmSurfBox((GmSurfBox *)param_2);
        }
        local_4 = 0xffffffff;
        *(undefined4 **)(this + 0x34) = puVar1;
      }
      GmBoxAligned::ArchiveABoxOld1((GmBoxAligned *)(puVar1 + 2), this_00);
      break;
    case 7:
      puVar1 = *(undefined4 **)(this + 0x34);
      if (*(int *)(this_00 + 8) == 0) {
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        param_2 = (ulong)operator_new(0x2c);
        local_4 = 7;
        if ((GmSurfMesh *)param_2 == (GmSurfMesh *)0x0) {
          puVar1 = (undefined4 *)0x0;
        } else {
          puVar1 = (undefined4 *)GmSurfMesh::GmSurfMesh((GmSurfMesh *)param_2);
        }
        local_4 = 0xffffffff;
        *(undefined4 **)(this + 0x34) = puVar1;
      }
      GmSurfMesh::Archive((GmSurfMesh *)puVar1, this_00);
    }
    if (*(int *)(this_00 + 8) == 0) {
      ComputeBoundingBox(this);
    }
    param_1 = (CClassicArchive *)0x0;
    if (*(int *)(this + 0x34) != 0) {
      param_1 =
          (CClassicArchive *)(uint) * (ushort *)(*(int *)(this + 0x34) + 4);
    }
    CClassicArchive::DoNat16(this_00, (ushort *)&param_1, 1, 0);
    if (*(int *)(this_00 + 8) != 0) {
      ExceptionList = local_c;
      return;
    }
    iVar2 = *(int *)(this + 0x34);
    if (iVar2 == 0) {
      ExceptionList = local_c;
      return;
    }
    goto LAB_008bbb81;
  }
  if (*(int *)(param_1 + 8) != 0) {
    param_1 = (CClassicArchive *)(uint) * (byte *)(*(int *)(this + 0x34) + 6);
  }
  ExceptionList = &local_c;
  CClassicArchive::DoNatural(this_00, (ulong *)&param_1, 1, 0);
  if (param_1 == (CClassicArchive *)0x0) {
    puVar1 = *(undefined4 **)(this + 0x34);
    if (*(int *)(this_00 + 8) == 0) {
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      param_2 = (ulong)operator_new(0xc);
      local_4 = 1;
      if ((GmSurfSphere *)param_2 == (GmSurfSphere *)0x0) {
        puVar1 = (undefined4 *)0x0;
      } else {
        puVar1 =
            (undefined4 *)GmSurfSphere::GmSurfSphere((GmSurfSphere *)param_2);
      }
      local_4 = 0xffffffff;
      *(undefined4 **)(this + 0x34) = puVar1;
    }
    pfVar3 = (float *)(puVar1 + 2);
  } else {
    if (param_1 != (CClassicArchive *)&DAT_00000001) {
      if (param_1 == (CClassicArchive *)&DAT_00000006) {
        puVar1 = *(undefined4 **)(this + 0x34);
        if (*(CClassicArchive **)(this_00 + 8) == param_1 + -6) {
          if (puVar1 != (undefined4 *)0x0) {
            (**(code **)*puVar1)(1);
          }
          param_2 = (ulong)operator_new(0x20);
          local_4 = 2;
          if ((GmSurfBox *)param_2 == (GmSurfBox *)0x0) {
            puVar1 = (undefined4 *)0x0;
          } else {
            puVar1 = (undefined4 *)GmSurfBox::GmSurfBox((GmSurfBox *)param_2);
          }
          local_4 = 0xffffffff;
          *(undefined4 **)(this + 0x34) = puVar1;
        }
        GmBoxAligned::ArchiveABoxOld1((GmBoxAligned *)(puVar1 + 2), this_00);
      }
      goto LAB_008bb8d4;
    }
    puVar1 = *(undefined4 **)(this + 0x34);
    if (*(int *)(this_00 + 8) == 0) {
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      param_2 = (ulong)operator_new(0x14);
      local_4 = 3;
      if ((GmSurfEllipsoid *)param_2 == (GmSurfEllipsoid *)0x0) {
        puVar1 = (undefined4 *)0x0;
      } else {
        puVar1 = (undefined4 *)GmSurfEllipsoid::GmSurfEllipsoid(
            (GmSurfEllipsoid *)param_2);
      }
      local_4 = 0xffffffff;
      *(undefined4 **)(this + 0x34) = puVar1;
    }
    CClassicArchive::DoReal(this_00, (float *)(puVar1 + 2), 1);
    CClassicArchive::DoReal(this_00, (float *)(puVar1 + 3), 1);
    pfVar3 = (float *)(puVar1 + 4);
  }
  CClassicArchive::DoReal(this_00, pfVar3, 1);
LAB_008bb8d4:
  if (*(int *)(this_00 + 8) != 0) {
    ExceptionList = local_c;
    return;
  }
  ComputeBoundingBox(this);
  ExceptionList = local_c;
  return;
}

/* public: void __thiscall CPlugSurfaceGeom::ComputeBoundingBox(void) */

void __thiscall CPlugSurfaceGeom::ComputeBoundingBox(CPlugSurfaceGeom *this)

{
  GmSurf::GetBoundingBox(*(GmSurf **)(this + 0x34),
                         (GmBoxAligned *)(this + 0x1c));
  return;
}

/* public: __thiscall CPlugSurfaceGeom::CPlugSurfaceGeom(void) */

CPlugSurfaceGeom *__thiscall CPlugSurfaceGeom::CPlugSurfaceGeom(
    CPlugSurfaceGeom *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00adb708;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CPlug::CPlug((CPlug *)this);
  local_4 = 0;
  *(undefined ***)this = vftable;
  CMwId::CMwId((CMwId *)(this + 0x14));
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x28) = 0xbf800000;
  *(undefined4 *)(this + 0x2c) = 0xbf800000;
  *(undefined4 *)(this + 0x30) = 0xbf800000;
  *(undefined4 *)(this + 0x18) = 1;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  ExceptionList = local_c;
  return this;
}

/* public: virtual void __thiscall CPlugSurfaceGeom::CreateDefaultData(void) */

void __thiscall CPlugSurfaceGeom::CreateDefaultData(CPlugSurfaceGeom *this)

{
  GmSurfSphere *this_00;
  int iVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00adb68b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = (GmSurfSphere *)operator_new(0xc);
  local_4 = 0;
  if (this_00 == (GmSurfSphere *)0x0) {
    iVar1 = 0;
  } else {
    iVar1 = GmSurfSphere::GmSurfSphere(this_00);
  }
  *(int *)(this + 0x34) = iVar1;
  *(undefined4 *)(iVar1 + 8) = 0x3f800000;
  ExceptionList = local_c;
  return;
}

/* public: virtual unsigned long __thiscall
 * CPlugSurfaceGeom::GetChunkInfo(unsigned long)const  */

ulong __thiscall CPlugSurfaceGeom::GetChunkInfo(CPlugSurfaceGeom *this,
                                                ulong param_1)

{
  ulong uVar1;

  if (param_1 < 0x900f001) {
    if ((((param_1 == 0x900f000) || (param_1 == 0x900c000)) ||
         (param_1 == 0x900c001)) ||
        (param_1 == 0x900d002)) {
      return 1;
    }
  } else if (param_1 < 0x900f004) {
    if (param_1 == 0x900f003) {
      return 1;
    }
    if (param_1 == 0x900f001) {
      return 1;
    }
    if (param_1 == 0x900f002) {
      return 1;
    }
  } else {
    if (param_1 == 0x900f004) {
      return 3;
    }
    if (param_1 == 0xffffffff) {
      return 0xffffffff;
    }
  }
  uVar1 = CMwNod::GetChunkInfo((CMwNod *)this, param_1);
  return uVar1;
}

/* public: virtual unsigned long __thiscall
 * CPlugSurfaceGeom::GetMwClassId(void)const  */

ulong __thiscall CPlugSurfaceGeom::GetMwClassId(CPlugSurfaceGeom *this)

{
  return 0x900f000;
}

/* public: virtual unsigned long __thiscall
   CPlugSurfaceGeom::GetUidChunkFromIndex(unsigned long)const  */

ulong __thiscall CPlugSurfaceGeom::GetUidChunkFromIndex(CPlugSurfaceGeom *this,
                                                        ulong param_1)

{
  if (param_1 == 0) {
    return 0x1001000;
  }
  return param_1 - 1 | 0x900f000;
}

/* public: float __thiscall CPlugSurfaceGeom::GetVolume(void) */

float __thiscall CPlugSurfaceGeom::GetVolume(CPlugSurfaceGeom *this)

{
  char cVar1;
  int iVar2;

  iVar2 = *(int *)(this + 0x34);
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + 6);
    if (cVar1 == '\0') {
      return *(float *)(iVar2 + 8) * 4.18879 * *(float *)(iVar2 + 8) *
             *(float *)(iVar2 + 8);
    }
    if (cVar1 == '\x01') {
      return *(float *)(iVar2 + 8) * 4.18879 * *(float *)(iVar2 + 0xc) *
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

/* public: void __thiscall CPlugSurfaceGeom::GetWeightDistrib(unsigned
 * long,class GmVec3 &) */

void __thiscall CPlugSurfaceGeom::GetWeightDistrib(CPlugSurfaceGeom *this,
                                                   ulong param_1,
                                                   GmVec3 *param_2)

{
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)param_2 = 0;
  return;
}

/* public: unsigned long __thiscall
 * CPlugSurfaceGeom::GetWeightDistribCount(void) */

ulong __thiscall CPlugSurfaceGeom::GetWeightDistribCount(CPlugSurfaceGeom *this)

{
  return (uint)(*(int *)(this + 0x18) != 0);
}

/* public: virtual class CMwClassInfo const * __thiscall
 * CPlugSurfaceGeom::MwGetClassInfo(void)const
 */

CMwClassInfo *__thiscall CPlugSurfaceGeom::MwGetClassInfo(
    CPlugSurfaceGeom *this)

{
  return &m_MwClassInfo_CPlugSurfaceGeom;
}

/* public: virtual int __thiscall CPlugSurfaceGeom::MwIsKindOf(unsigned
 * long)const  */

int __thiscall CPlugSurfaceGeom::MwIsKindOf(CPlugSurfaceGeom *this,
                                            ulong param_1)

{
  if ((param_1 != 0x900f000) && (param_1 != 0x902b000)) {
    return (uint)(param_1 == 0x1001000);
  }
  return 1;
}

/* public: static class CMwNod * __cdecl
 * CPlugSurfaceGeom::MwNewCPlugSurfaceGeom(void) */

CMwNod *__cdecl CPlugSurfaceGeom::MwNewCPlugSurfaceGeom(void)

{
  CPlugSurfaceGeom *this;
  CMwNod *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00adb7db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = (CPlugSurfaceGeom *)operator_new(0x3c);
  local_4 = 0;
  if (this != (CPlugSurfaceGeom *)0x0) {
    pCVar1 = (CMwNod *)CPlugSurfaceGeom(this);
    ExceptionList = local_c;
    return pCVar1;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}

/* public: void __thiscall CPlugSurfaceGeom::SetGmSurfType(enum
 * GmSurf::EGmSurfType const &) */

void __thiscall CPlugSurfaceGeom::SetGmSurfType(CPlugSurfaceGeom *this,
                                                EGmSurfType *param_1)

{
  undefined4 *puVar1;
  void **ppvVar2;
  GmSurfSphere *this_00;
  GmSurfPolygon *this_01;
  GmSurfBox *this_02;
  GmSurf *this_03;
  GmSurfEllipsoid *this_04;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00adb6dc;
  local_c = ExceptionList;
  puVar1 = *(undefined4 **)(this + 0x34);
  ppvVar2 = &local_c;
  if (puVar1 != (undefined4 *)0x0) {
    if ((uint) * (byte *)((int)puVar1 + 6) == *param_1) {
      return;
    }
    if (puVar1 != (undefined4 *)0x0) {
      ExceptionList = &local_c;
      (**(code **)*puVar1)(1, ___security_cookie ^ (uint)&stack0xffffffec);
      ppvVar2 = (void **)ExceptionList;
    }
  }
  ExceptionList = ppvVar2;
  *(undefined4 *)(this + 0x34) = 0;
  switch (*param_1) {
  case 0:
    this_00 = (GmSurfSphere *)operator_new(0xc);
    local_4 = 0;
    if (this_00 == (GmSurfSphere *)0x0) {
    LAB_008bb15e:
      this_03 = (GmSurf *)0x0;
    } else {
      this_03 = (GmSurf *)GmSurfSphere::GmSurfSphere(this_00);
    }
    break;
  case 1:
    this_04 = (GmSurfEllipsoid *)operator_new(0x14);
    local_4 = 3;
    if (this_04 == (GmSurfEllipsoid *)0x0)
      goto LAB_008bb15e;
    this_03 = (GmSurf *)GmSurfEllipsoid::GmSurfEllipsoid(this_04);
    break;
  default:
    goto switchD_008bb0c9_caseD_2;
  case 5:
    this_01 = (GmSurfPolygon *)operator_new(0x4c);
    local_4 = 1;
    if (this_01 == (GmSurfPolygon *)0x0)
      goto LAB_008bb15e;
    this_03 = (GmSurf *)GmSurfPolygon::GmSurfPolygon(this_01, '\x03');
    break;
  case 6:
    this_02 = (GmSurfBox *)operator_new(0x20);
    local_4 = 2;
    if (this_02 == (GmSurfBox *)0x0)
      goto LAB_008bb15e;
    this_03 = (GmSurf *)GmSurfBox::GmSurfBox(this_02);
  }
  local_4 = 0xffffffff;
  *(GmSurf **)(this + 0x34) = this_03;
  GmSurf::CreateDefaultData(this_03);
  ComputeBoundingBox(this);
switchD_008bb0c9_caseD_2:
  ExceptionList = local_c;
  return;
}

/* public: void __thiscall CPlugSurfaceGeom::TransformByNOMat(class GmIso4 const
 * &) */

void __thiscall CPlugSurfaceGeom::TransformByNOMat(CPlugSurfaceGeom *this,
                                                   GmIso4 *param_1)

{
  GmSurfMesh *this_00;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  this_00 = *(GmSurfMesh **)(this + 0x34);
  if (this_00 != (GmSurfMesh *)0x0) {
    if (this_00[6] == (GmSurfMesh)0x0) {
      local_c = *(undefined4 *)(this_00 + 8);
      local_8 = 0;
      local_4 = 0;
      GmVec3::Mult((GmVec3 *)&local_c, param_1);
      *(undefined4 *)(this_00 + 8) = local_c;
    } else if (this_00[6] == (GmSurfMesh)0x7) {
      GmSurfMesh::TransformByNOMat(this_00, param_1);
      return;
    }
  }
  return;
}

/* public: virtual unsigned long __thiscall
 *CPlugSurfaceGeom::VirtualParam_Get(class CMwStack ,class CMwValueStd *) */

ulong __thiscall CPlugSurfaceGeom::VirtualParam_Get(CPlugSurfaceGeom *this,
                                                    CMwStack *param_1,
                                                    CMwValueStd *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  GmVec3 *pGVar6;

  iVar2 = *(int *)(param_1 + 0x18);
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + iVar2 * 4);
  *(int *)(param_1 + 0x18) = iVar2 + -1;
  uVar4 = *(uint *)(iVar3 + 4);
  if (uVar4 < 0x900f003) {
    if (uVar4 == 0x900f002) {
      iVar2 = *(int *)(this + 0x34);
      pGVar6 = (GmVec3 *)&DAT_00d181f4;
      if ((iVar2 != 0) && (*(char *)(iVar2 + 6) == '\x01')) {
        pGVar6 = (GmVec3 *)(iVar2 + 8);
      }
      CMwParamVec3::GetValue(pGVar6, param_1, param_2);
      return 0;
    }
    if (uVar4 == 0x900f000) {
      if (*(int *)(this + 0x34) != 0) {
        bVar1 = *(byte *)(*(int *)(this + 0x34) + 6);
        *(CMwValueStd **)param_2 = param_2 + 4;
        *(uint *)(param_2 + 4) = (uint)bVar1;
        return 0;
      }
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(undefined4 *)(param_2 + 4) = 0xffffffff;
      return 0;
    }
    if (uVar4 != 0x900f001) {
    LAB_008bb448:
      *(int *)(param_1 + 0x18) = iVar2;
      uVar5 = CMwNod::VirtualParam_Get((CMwNod *)this, param_1, param_2);
      return uVar5;
    }
    iVar2 = *(int *)(this + 0x34);
    param_1 = (CMwStack *)&DAT_3f800000;
    if ((iVar2 != 0) && (*(char *)(iVar2 + 6) == '\0')) {
      param_1 = *(CMwStack **)(iVar2 + 8);
    }
    *(CMwStack **)(param_2 + 4) = param_1;
    *(CMwValueStd **)param_2 = param_2 + 4;
  } else if (uVar4 != 0xffffffff)
    goto LAB_008bb448;
  return 0;
}

/* public: virtual unsigned long __thiscall
 *CPlugSurfaceGeom::VirtualParam_Set(class CMwStack *,void
 *) */

ulong __thiscall CPlugSurfaceGeom::VirtualParam_Set(CPlugSurfaceGeom *this,
                                                    CMwStack *param_1,
                                                    void *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 < 0x900f003) {
    if (uVar3 == 0x900f002) {
      iVar1 = *(int *)(this + 0x34);
      if ((iVar1 != 0) && (*(char *)(iVar1 + 6) == '\x01')) {
        CMwParamVec3::SetValue((GmVec3 *)(iVar1 + 8), param_1, param_2);
        ComputeBoundingBox(this);
        return 0;
      }
    } else {
      if (uVar3 == 0x900f000) {
        SetGmSurfType(this, (EGmSurfType *)param_2);
        return 0;
      }
      if (uVar3 != 0x900f001)
        goto LAB_008bb359;
      iVar1 = *(int *)(this + 0x34);
      if ((iVar1 != 0) && (*(char *)(iVar1 + 6) == '\0')) {
        /* WARNING: Load size is inaccurate */
        *(undefined4 *)(iVar1 + 8) = *param_2;
        ComputeBoundingBox(this);
      }
    }
  } else if (uVar3 != 0xffffffff) {
  LAB_008bb359:
    *(int *)(param_1 + 0x18) = iVar1;
    uVar4 = CMwNod::VirtualParam_Set((CMwNod *)this, param_1, param_2);
    return uVar4;
  }
  return 0;
}

/* public: virtual __thiscall CPlugSurfaceGeom::~CPlugSurfaceGeom(void) */

void __thiscall CPlugSurfaceGeom::~CPlugSurfaceGeom(CPlugSurfaceGeom *this)

{
  uint uVar1;
  void *local_c;
  undefined *puStack_8;
  uint local_4;

  puStack_8 = &LAB_00adb663;
  local_c = ExceptionList;
  uVar1 = ___security_cookie ^ (uint)&stack0xffffffec;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 1;
  if (*(undefined4 **)(this + 0x34) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(this + 0x34))(1, uVar1);
  }
  local_4 = local_4 & 0xffffff00;
  CScene2d::OnNodLoaded((CScene2d *)(this + 0x14));
  local_4 = 0xffffffff;
  CPlug::~CPlug((CPlug *)this);
  ExceptionList = local_c;
  return;
}
