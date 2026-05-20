
/* public: virtual void * __thiscall CSceneVehicleMaterial::`scalar deleting
   destructor'(unsigned int) */

void *__thiscall CSceneVehicleMaterial::`scalar_deleting_destructor'(CSceneVehicleMaterial *this,uint param_1)

{
  ~CSceneVehicleMaterial(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: virtual void __thiscall CSceneVehicleMaterial::Chunk(class
   CClassicArchive &,unsigned long) */

void __thiscall CSceneVehicleMaterial::Chunk(CSceneVehicleMaterial *this,
                                             CClassicArchive *param_1,
                                             ulong param_2)

{
  CClassicArchive *this_00;
  ulong this_01;
  uint uVar1;
  undefined uVar2;
  CSceneVehicleMaterial **ppCVar3;
  CSceneVehicleMaterial *local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  this_00 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad0700;
  local_c = ExceptionList;
  uVar1 = ___security_cookie ^ (uint)&stack0xffffffe0;
  local_10 = this;
  if (0xa031008 < param_2) {
    if (param_2 < 0xa03100e) {
      if (param_2 == 0xa03100d) {
        param_2 = 0;
        local_4 = 0xb;
        ExceptionList = &local_c;
        CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)&param_2);
      } else {
        switch (param_2) {
        case 0xa031009:
          ExceptionList = &local_c;
          CClassicArchive::DoNat8(param_1, (uchar *)(this + 0x44), 1, 0);
          CClassicArchive::DoReal(this_00, (float *)(this + 0x30), 1);
          CClassicArchive::DoReal(this_00, (float *)(this + 0x34), 1);
          CClassicArchive::DoBool(this_00, (int *)&local_10, 1);
          param_2 = 0;
          local_4 = 6;
          CClassicArchive::MwDoNodRef<>(this_00, (CMwNodRef<> *)&param_2);
          this_01 = param_2;
          if (param_2 != 0) {
            CMwNod::MwAddRef((CMwNod *)param_2);
          }
          param_1 = (CClassicArchive *)0x0;
          local_4._0_1_ = 7;
          CClassicArchive::MwDoNodRef<>(this_00, (CMwNodRef<> *)&param_1);
          CClassicArchive::MwDoNodRef<>(this_00, (CMwNodRef<> *)&param_1);
          CClassicArchive::MwDoNodRef<>(this_00, (CMwNodRef<> *)&param_1);
          CClassicArchive::MwDoNodRef<>(this_00, (CMwNodRef<> *)&param_1);
          local_4 = CONCAT31(local_4._1_3_, 6);
          if (param_1 != (CClassicArchive *)0x0) {
            CMwNod::MwRelease((CMwNod *)param_1);
          }
          local_4 = 0xffffffff;
          if (this_01 == 0) {
            ExceptionList = local_c;
            return;
          }
          CMwNod::MwRelease((CMwNod *)this_01);
          ExceptionList = local_c;
          return;
        case 0xa03100a:
          param_2 = 0;
          local_4 = 8;
          ExceptionList = &local_c;
          CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)&param_2);
          break;
        case 0xa03100b:
          param_2 = 0;
          local_4 = 9;
          ExceptionList = &local_c;
          CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)&param_2);
          break;
        case 0xa03100c:
          param_2 = 0;
          local_4 = 10;
          ExceptionList = &local_c;
          CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)&param_2);
          break;
        default:
          goto switchD_007fdafb_caseD_8;
        }
      }
      goto LAB_007fdc54;
    }
    if (param_2 != 0xa03100e) {
      if (param_2 == 0xa03100f) {
        ExceptionList = &local_c;
        CClassicArchive::DoReal(param_1, (float *)(this + 0x3c), 1);
        ppCVar3 = (CSceneVehicleMaterial **)(this + 0x40);
        goto LAB_007fdf55;
      }
      if (param_2 == 0xffffffff) {
        return;
      }
    switchD_007fdafb_caseD_8:
      ExceptionList = &local_c;
      CMwNod::Chunk((CMwNod *)this, param_1, param_2);
      ExceptionList = local_c;
      return;
    }
    ExceptionList = &local_c;
    CClassicArchive::DoNat8(param_1, (uchar *)(this + 0x44), 1, 0);
  LAB_007fdf48:
    CClassicArchive::DoReal(this_00, (float *)(this + 0x30), 1);
    ppCVar3 = (CSceneVehicleMaterial **)(this + 0x34);
    goto LAB_007fdf55;
  }
  if (param_2 != 0xa031008) {
    switch (param_2) {
    case 0xa031000:
      ExceptionList = &local_c;
      CClassicArchive::DoNat8(param_1, (uchar *)(this + 0x44), 1, 0);
      CClassicArchive::DoBool(this_00, (int *)&param_2, 1);
      param_1 = (CClassicArchive *)0x0;
      local_4 = 0;
      CClassicArchive::MwDoNodRef<>(this_00, (CMwNodRef<> *)&param_1);
      local_4 = 0xffffffff;
      if (param_1 == (CClassicArchive *)0x0) {
        ExceptionList = local_c;
        return;
      }
      CMwNod::MwRelease((CMwNod *)param_1);
      ExceptionList = local_c;
      return;
    case 0xa031001:
      ExceptionList = &local_c;
      CClassicArchive::DoNat8(param_1, (uchar *)(this + 0x44), 1, 0);
      CClassicArchive::DoBool(this_00, (int *)&param_1, 1);
      (**(code **)(*(int *)this_00 + 4))(&param_2, uVar1);
      goto LAB_007fdf48;
    case 0xa031002:
      param_2 = 0;
      ExceptionList = &local_c;
      CClassicArchive::DoReal(param_1, (float *)&param_2, 1);
      CClassicArchive::DoReal(this_00, (float *)(this + 0x14), 1);
      CClassicArchive::DoReal(this_00, (float *)&param_1, 1);
      ppCVar3 = &local_10;
      break;
    case 0xa031003:
      ExceptionList = &local_c;
      CClassicArchive::DoReal(param_1, (float *)(this + 0x14), 1);
      ppCVar3 = (CSceneVehicleMaterial **)(this + 0x20);
      break;
    case 0xa031004:
      ExceptionList = &local_c;
      CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x24));
      GmVec2::ArchiveGmVec2((GmVec2 *)(this + 0x28), this_00);
      ExceptionList = local_c;
      return;
    case 0xa031005:
      ExceptionList = &local_c;
      CClassicArchive::DoReal(param_1, (float *)(this + 0x14), 1);
      CClassicArchive::DoReal(this_00, (float *)(this + 0x20), 1);
      CClassicArchive::DoReal(this_00, (float *)(this + 0x18), 1);
      ppCVar3 = (CSceneVehicleMaterial **)(this + 0x1c);
      break;
    case 0xa031006:
      param_2 = 0;
      local_4 = 1;
      ExceptionList = &local_c;
      CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)&param_2);
      goto LAB_007fdc54;
    case 0xa031007:
      ExceptionList = &local_c;
      CClassicArchive::DoNat8(param_1, (uchar *)(this + 0x44), 1, 0);
      CClassicArchive::DoReal(this_00, (float *)(this + 0x30), 1);
      CClassicArchive::DoReal(this_00, (float *)(this + 0x34), 1);
      CClassicArchive::DoBool(this_00, (int *)&local_10, 1);
      param_2 = 0;
      uVar2 = 2;
      local_4 = 2;
      CClassicArchive::MwDoNodRef<>(this_00, (CMwNodRef<> *)&param_2);
      param_1 = (CClassicArchive *)0x0;
      local_4 = CONCAT31(local_4._1_3_, 3);
      CClassicArchive::MwDoNodRef<>(this_00, (CMwNodRef<> *)&param_1);
      goto LAB_007fdce1;
    default:
      goto switchD_007fdafb_caseD_8;
    }
  LAB_007fdf55:
    CClassicArchive::DoReal(this_00, (float *)ppCVar3, 1);
    ExceptionList = local_c;
    return;
  }
  ExceptionList = &local_c;
  CClassicArchive::DoNat8(param_1, (uchar *)(this + 0x44), 1, 0);
  CClassicArchive::DoReal(this_00, (float *)(this + 0x30), 1);
  CClassicArchive::DoReal(this_00, (float *)(this + 0x34), 1);
  CClassicArchive::DoBool(this_00, (int *)&local_10, 1);
  param_2 = 0;
  uVar2 = 4;
  local_4 = 4;
  CClassicArchive::MwDoNodRef<>(this_00, (CMwNodRef<> *)&param_2);
  param_1 = (CClassicArchive *)0x0;
  local_4 = CONCAT31(local_4._1_3_, 5);
  CClassicArchive::MwDoNodRef<>(this_00, (CMwNodRef<> *)&param_1);
  CClassicArchive::MwDoNodRef<>(this_00, (CMwNodRef<> *)&param_1);
LAB_007fdce1:
  CClassicArchive::MwDoNodRef<>(this_00, (CMwNodRef<> *)&param_1);
  local_4 = CONCAT31(local_4._1_3_, uVar2);
  if (param_1 != (CClassicArchive *)0x0) {
    CMwNod::MwRelease((CMwNod *)param_1);
  }
LAB_007fdc54:
  local_4 = 0xffffffff;
  if (param_2 == 0) {
    ExceptionList = local_c;
    return;
  }
  CMwNod::MwRelease((CMwNod *)param_2);
  ExceptionList = local_c;
  return;
}

/* public: __thiscall CSceneVehicleMaterial::CSceneVehicleMaterial(void) */

CSceneVehicleMaterial *__thiscall CSceneVehicleMaterial::CSceneVehicleMaterial(
    CSceneVehicleMaterial *this)

{
  CMwNod::CMwNod((CMwNod *)this);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0x3f800000;
  *(undefined4 *)(this + 0x18) = 0x3f800000;
  *(undefined4 *)(this + 0x1c) = 0x3f800000;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x20) = 0x3f800000;
  this[0x44] = (CSceneVehicleMaterial)0x0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0x3f000000;
  *(undefined4 *)(this + 0x14) = 0x3f800000;
  *(undefined4 *)(this + 0x18) = 0x3f800000;
  *(undefined4 *)(this + 0x1c) = 0x3f800000;
  *(undefined4 *)(this + 0x20) = 0x3f800000;
  *(undefined4 *)(this + 0x28) = 0x42000000;
  *(undefined4 *)(this + 0x2c) = 0x42000000;
  *(undefined4 *)(this + 0x3c) = 0x40200000;
  *(undefined4 *)(this + 0x40) = 0x3f800000;
  return this;
}

/* WARNING: Switch with 1 destination removed at 0x007fd71b : 4 cases all go to
 * same destination */
/* public: virtual unsigned long __thiscall
 * CSceneVehicleMaterial::GetChunkInfo(unsigned long)const
 */

ulong __thiscall CSceneVehicleMaterial::GetChunkInfo(
    CSceneVehicleMaterial *this, ulong param_1)

{
  ulong uVar1;

  if (0xa031008 < param_1) {
    if (param_1 < 0xa03100e) {
      if (param_1 == 0xa03100d) {
        return 1;
      }
      if (param_1 + 0xf5fceff7 < 4) {
        return 1;
      }
    } else {
      if (param_1 == 0xa03100e) {
        return 3;
      }
      if (param_1 == 0xa03100f) {
        return 3;
      }
      if (param_1 == 0xffffffff) {
        return 0xffffffff;
      }
    }
  switchD_007fd6f8_caseD_8:
    uVar1 = CMwNod::GetChunkInfo((CMwNod *)this, param_1);
    return uVar1;
  }
  if (param_1 == 0xa031008) {
  switchD_007fd6f8_caseD_a031000:
    return 1;
  }
  switch (param_1) {
  case 0xa031000:
  case 0xa031001:
  case 0xa031002:
  case 0xa031003:
  case 0xa031006:
  case 0xa031007:
    goto switchD_007fd6f8_caseD_a031000;
  case 0xa031004:
  case 0xa031005:
    return 3;
  default:
    goto switchD_007fd6f8_caseD_8;
  }
}

/* public: virtual unsigned long __thiscall
 * CSceneVehicleMaterial::GetMwClassId(void)const  */

ulong __thiscall CSceneVehicleMaterial::GetMwClassId(
    CSceneVehicleMaterial *this)

{
  return 0xa031000;
}

/* public: virtual unsigned long __thiscall
   CSceneVehicleMaterial::GetUidChunkFromIndex(unsigned long)const  */

ulong __thiscall CSceneVehicleMaterial::GetUidChunkFromIndex(
    CSceneVehicleMaterial *this, ulong param_1)

{
  if (param_1 == 0) {
    return 0x1001000;
  }
  return param_1 - 1 | 0xa031000;
}

/* public: virtual class CMwClassInfo const * __thiscall
   CSceneVehicleMaterial::MwGetClassInfo(void)const  */

CMwClassInfo *__thiscall CSceneVehicleMaterial::MwGetClassInfo(
    CSceneVehicleMaterial *this)

{
  return &m_MwClassInfo_CSceneVehicleMaterial;
}

/* public: virtual int __thiscall CSceneVehicleMaterial::MwIsKindOf(unsigned
 * long)const  */

int __thiscall CSceneVehicleMaterial::MwIsKindOf(CSceneVehicleMaterial *this,
                                                 ulong param_1)

{
  if (param_1 == 0xa031000) {
    return 1;
  }
  return (uint)(param_1 == 0x1001000);
}

/* public: static class CMwNod * __cdecl
 * CSceneVehicleMaterial::MwNewCSceneVehicleMaterial(void) */

CMwNod *__cdecl CSceneVehicleMaterial::MwNewCSceneVehicleMaterial(void)

{
  CSceneVehicleMaterial *this;
  CMwNod *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad067b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = (CSceneVehicleMaterial *)operator_new(0x48);
  local_4 = 0;
  if (this != (CSceneVehicleMaterial *)0x0) {
    pCVar1 = (CMwNod *)CSceneVehicleMaterial(this);
    ExceptionList = local_c;
    return pCVar1;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}

/* public: virtual unsigned long __thiscall
 *CSceneVehicleMaterial::VirtualParam_Get(class CMwStack ,class CMwValueStd *)
 */

ulong __thiscall CSceneVehicleMaterial::VirtualParam_Get(
    CSceneVehicleMaterial *this, CMwStack *param_1, CMwValueStd *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 < 0xa031004) {
    if (uVar3 == 0xa031003) {
      *(CSceneVehicleMaterial **)param_2 = this + 0x1c;
      return 0;
    }
    if (uVar3 == 0xa031000) {
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (uint)(byte)this[0x44];
      return 0;
    }
    if (uVar3 == 0xa031001) {
      *(CSceneVehicleMaterial **)param_2 = this + 0x14;
      return 0;
    }
    if (uVar3 == 0xa031002) {
      *(CSceneVehicleMaterial **)param_2 = this + 0x18;
      return 0;
    }
  LAB_007fd807:
    *(int *)(param_1 + 0x18) = iVar1;
    uVar4 = CMwNod::VirtualParam_Get((CMwNod *)this, param_1, param_2);
    return uVar4;
  }
  if (uVar3 == 0xa031004) {
    *(CSceneVehicleMaterial **)param_2 = this + 0x20;
  } else if (uVar3 != 0xffffffff)
    goto LAB_007fd807;
  return 0;
}

/* public: virtual unsigned long __thiscall
 *CSceneVehicleMaterial::VirtualParam_Set(class CMwStack ,void *) */

ulong __thiscall CSceneVehicleMaterial::VirtualParam_Set(
    CSceneVehicleMaterial *this, CMwStack *param_1, void *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 < 0xa031004) {
    if (uVar3 == 0xa031003) {
      /* WARNING: Load size is inaccurate */
      *(undefined4 *)(this + 0x1c) = *param_2;
      return 0;
    }
    if (uVar3 == 0xa031000) {
      /* WARNING: Load size is inaccurate */
      this[0x44] = *param_2;
      return 0;
    }
    if (uVar3 == 0xa031001) {
      /* WARNING: Load size is inaccurate */
      *(undefined4 *)(this + 0x14) = *param_2;
      return 0;
    }
    if (uVar3 == 0xa031002) {
      /* WARNING: Load size is inaccurate */
      *(undefined4 *)(this + 0x18) = *param_2;
      return 0;
    }
  LAB_007fda59:
    *(int *)(param_1 + 0x18) = iVar1;
    uVar4 = CMwNod::VirtualParam_Set((CMwNod *)this, param_1, param_2);
    return uVar4;
  }
  if (uVar3 == 0xa031004) {
    /* WARNING: Load size is inaccurate */
    *(undefined4 *)(this + 0x20) = *param_2;
  } else {
    if (uVar3 == 0xa031007) {
      CMwNodRef<>::ParamSetValue((CMwNodRef<> *)(this + 0x24), param_1,
                                 param_2);
      return 0;
    }
    if (uVar3 != 0xffffffff)
      goto LAB_007fda59;
  }
  return 0;
}

/* public: virtual __thiscall
 * CSceneVehicleMaterial::~CSceneVehicleMaterial(void) */

void __thiscall CSceneVehicleMaterial::~CSceneVehicleMaterial(
    CSceneVehicleMaterial *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00ad0648;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 0;
  if (*(CMwNod **)(this + 0x24) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x24));
  }
  local_4 = 0xffffffff;
  CMwNod::~CMwNod((CMwNod *)this);
  ExceptionList = local_c;
  return;
}
