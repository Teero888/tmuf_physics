
/* public: void __thiscall CPlugSolid::AddTree(class CPlugTree *) */

void __thiscall CPlugSolid::AddTree(CPlugSolid *this, CPlugTree *param_1)

{
  CMwNod *this_00;
  uint uVar1;
  CPlugTree *pCVar2;
  int iVar3;
  void *unaff_EDI;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad5536;
  local_c = ExceptionList;
  uVar1 = ___security_cookie ^ (uint)&stack0xffffffe8;
  ExceptionList = &local_c;
  if (*(int *)(this + 100) == 0) {
    pCVar2 = (CPlugTree *)operator_new(0xac);
    local_4 = 0;
    if (pCVar2 == (CPlugTree *)0x0) {
      pCVar2 = (CPlugTree *)0x0;
    } else {
      pCVar2 = (CPlugTree *)CPlugTree::CPlugTree(pCVar2);
    }
    local_4 = 0xffffffff;
    SetTree(this, pCVar2, 1);
  }
  iVar3 = (**(code **)(**(int **)(this + 100) + 0xc))(uVar1);
  if (iVar3 != 0x904f000) {
    this_00 = *(CMwNod **)(this + 100);
    CMwNod::MwAddRef(this_00);
    pCVar2 = (CPlugTree *)operator_new(0xac);
    local_4 = 1;
    if (pCVar2 == (CPlugTree *)0x0) {
      pCVar2 = (CPlugTree *)0x0;
    } else {
      pCVar2 = (CPlugTree *)CPlugTree::CPlugTree(pCVar2);
    }
    local_4 = 0xffffffff;
    SetTree(this, pCVar2, 1);
    CMwNod::MwForceRef(this_00, 0);
    (**(code **)(**(int **)(this + 100) + 0x88))(this_00);
  }
  (**(code **)(**(int **)(this + 100) + 0x88))(param_1);
  (**(code **)(*(int *)param_1 + 0xbc))(1);
  (**(code **)(**(int **)(this + 100) + 0xbc))(0);
  ExceptionList = unaff_EDI;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00854a08) */
/* public: virtual void __thiscall CPlugSolid::ApplyFidParameters(class
 *CSystemFidParameters const ,class CSystemFidParameters *,class
 *CFastBuffer<struct CMwNod::SManuallyLoadedFid> &) */

void __thiscall CPlugSolid::ApplyFidParameters(CPlugSolid *this,
                                               CSystemFidParameters *param_1,
                                               CSystemFidParameters *param_2,
                                               CFastBuffer<> *param_3)

{
  int iVar1;
  int local_2c;
  undefined4 local_28;
  SParam_Id local_24[20];
  int local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad5468;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CVisionViewportNull::SetFullScreenGammaRamp((CVisionViewportNull *)this,
                                              (float)param_1, (float)param_2,
                                              (float)param_3);
  CSystemFidParameters::SParam_Id::SParam_Id(
      local_24, &s_ParamId_PackBrotherShaders, 0, (ulong *)0x0, 0);
  local_4 = 0;
  CSystemFidParameters::GetParamValue(param_1, (SParam *)local_24);
  CSystemFidParameters::AddParam(param_2, (SParam *)local_24);
  if ((local_10 != 0) && (*(int *)(this + 0x68) == 0)) {
    if (*(int *)(CSystemConfig::s_SystemConfig + 0x20) == 0) {
      iVar1 = *(int *)(CSystemConfig::s_SystemConfig + 0x24);
    } else {
      iVar1 = *(int *)(CSystemConfig::s_SystemConfig + 0x28);
    }
    DAT_00d6e924 = *(undefined4 *)(iVar1 + 0x5c);
    FUN_00854290(*(int **)(this + 100));
  }
  if (*(int *)(this + 0x68) == 0) {
    iVar1 = 0;
  } else {
    iVar1 = *(int *)(*(int *)(this + 0x68) + 8);
  }
  if (iVar1 != 0) {
    local_28 = 1;
    local_2c = iVar1;
    CFastBuffer<>::Add((CFastBuffer<> *)param_3, (GmNat2 *)&local_2c);
  }
  local_4 = 0xffffffff;
  CSystemFidParameters::SParam_Id::~SParam_Id(local_24);
  ExceptionList = local_c;
  return;
}

/* public: virtual void __thiscall CPlugSolid::Chunk(class CClassicArchive
 * &,unsigned long) */

void __thiscall CPlugSolid::Chunk(CPlugSolid *this, CClassicArchive *param_1,
                                  ulong param_2)

{
  int *piVar1;
  CClassicArchive *this_00;
  uint uVar2;
  CPlugSolid **ppCVar3;
  code *pcVar4;
  CPlugSolid **ppCVar5;
  CPlugSolid *local_34;
  float local_30;
  uint local_2c;
  CPlugSolid *local_28;
  CSystemFid *local_24;
  CPlugSolid *local_20;
  float local_1c;
  CPlugSolid *local_18;
  float local_14;
  float local_10;
  void *local_c;
  undefined *puStack_8;
  uint local_4;

  this_00 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad55b0;
  local_c = ExceptionList;
  uVar2 = ___security_cookie ^ (uint)&stack0xffffffbc;
  if (param_2 < 0x900500b) {
    switch (param_2) {
    case 0x9005000:
      ExceptionList = &local_c;
      CClassicArchive::DoNatural(param_1, (ulong *)(this + 0x60), 1, 0);
      break;
    case 0x9005001:
    case 0x9005002:
    case 0x9005003:
    case 0x9005004:
    case 0x9005005:
    case 0x9005008:
    case 0x9005009:
      break;
    case 0x9005006:
      local_20 = (CPlugSolid *)0x0;
      local_24 = (CSystemFid *)0x0;
      ExceptionList = &local_c;
      CClassicArchive::DoReal(param_1, (float *)&local_20, 1);
      CClassicArchive::DoReal(this_00, (float *)&local_24, 1);
      CClassicArchive::DoReal(this_00, (float *)(this + 0x18), 1);
      local_18 = *(CPlugSolid **)(this + 0x50);
      local_14 = *(float *)(this + 0x54);
      local_10 = *(float *)(this + 0x58);
      CClassicArchive::DoReal(this_00, (float *)&local_18, 1);
      CClassicArchive::DoReal(this_00, &local_14, 1);
      CClassicArchive::DoReal(this_00, &local_10, 1);
      if (*(int *)(this_00 + 8) == 0) {
        CPlugPhysicalObject::SetComPos((CPlugPhysicalObject *)(this + 0x18),
                                       (GmVec3 *)&local_18);
      }
      GmMat3::ArchiveGmMat3((GmMat3 *)(this + 0x1c), this_00);
      break;
    case 0x9005007:
      local_20 = (CPlugSolid *)0x0;
      ExceptionList = &local_c;
      CClassicArchive::DoBool(param_1, (int *)&local_20, 1);
      break;
    default:
      local_30 = (float)(*(uint *)(this + 0x70) & 1);
      ExceptionList = &local_c;
      CClassicArchive::DoBool(param_1, (int *)&local_30, 1);
      param_1 = (CClassicArchive *)(uint)(*(int *)(this + 0x68) != 0);
      CClassicArchive::DoBool(this_00, (int *)&param_1, 1);
      if (param_1 != (CClassicArchive *)0x0) {
        local_28 = *(CPlugSolid **)(this + 0x68);
        (**(code **)(*(int *)this_00 + 4))(&local_28);
        if (*(int *)(this_00 + 8) == 0) {
          SetModel(this, local_28);
        }
      }
      if ((local_30 == 0.0) || (param_1 == (CClassicArchive *)0x0)) {
        local_2c = 1;
        CClassicArchive::DoNatural(this_00, &local_2c, 1, 0);
        if ((local_2c != 0) && (local_2c == 3)) {
          local_2c = 1;
        }
        local_20 = (CPlugSolid *)0x0;
        local_24 = (CSystemFid *)0x0;
        CClassicArchive::DoBool(this_00, (int *)&local_24, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_20, 1);
        local_34 = (CPlugSolid *)0x0;
        local_28 = (CPlugSolid *)0x0;
        if (local_2c == 0) {
          if ((local_30 == 0.0) && (param_1 != (CClassicArchive *)0x0)) {
            local_18 = (CPlugSolid *)0x0;
            (**(code **)(*(int *)this_00 + 4))(&local_18);
            if (*(int *)(this_00 + 8) == 0) {
              SetUseModel(this, 1);
              SetModel(this, *(CPlugSolid **)(this + 0x68));
              SetUseModel(this, 0);
              local_34 = *(CPlugSolid **)(this + 100);
            }
          } else {
            ppCVar3 = &local_34;
          LAB_00855762:
            pcVar4 = *(code **)(*(int *)this_00 + 4);
          LAB_00855768:
            (*pcVar4)(ppCVar3);
          }
        LAB_0085576c:
          if (local_34 != (CPlugSolid *)0x0) {
            *(CPlugSolid **)(this + 100) = local_34;
            *(CPlugSolid **)(this + 0x5c) = local_34;
            goto LAB_00855786;
          }
        } else {
          if (local_2c == 1) {
            if (local_24 != (CSystemFid *)0x0) {
              if ((local_30 == 0.0) && (param_1 != (CClassicArchive *)0x0)) {
                local_18 = (CPlugSolid *)0x0;
                (**(code **)(*(int *)this_00 + 4))(&local_18);
                if (*(int *)(this_00 + 8) == 0) {
                  SetUseModel(this, 1);
                  SetModel(this, *(CPlugSolid **)(this + 0x68));
                  SetUseModel(this, 0);
                  local_34 = *(CPlugSolid **)(this + 100);
                }
              } else {
                (**(code **)(*(int *)this_00 + 4))(&local_34);
              }
            }
            if (local_20 != (CPlugSolid *)0x0) {
              pcVar4 = *(code **)(*(int *)this_00 + 4);
              ppCVar3 = &local_28;
              goto LAB_00855768;
            }
            goto LAB_0085576c;
          }
          if (local_2c == 2) {
            ppCVar3 = &local_28;
            goto LAB_00855762;
          }
        }
        *(CPlugSolid **)(this + 100) = local_28;
        *(CPlugSolid **)(this + 0x5c) = local_28;
      }
    LAB_00855786:
      if (*(int *)(this_00 + 8) == 0) {
        SetUseModel(this, (int)local_30);
      }
      break;
    case 0xbad1abe1:
      goto switchD_008554f4_caseD_a;
    }
  } else {
    if (param_2 < 0x9005010) {
      if (param_2 == 0x900500f) {
        local_18 = (CPlugSolid *)0x0;
        local_14 = 0.0;
        local_20 = (CPlugSolid *)0x0;
        local_1c = 0.0;
        ExceptionList = &local_c;
        CClassicArchive::DoReal(param_1, (float *)&local_20, 1);
        CClassicArchive::DoReal(this_00, &local_1c, 1);
        ExceptionList = local_c;
        return;
      }
      switch (param_2) {
      case 0x900500b:
        ExceptionList = &local_c;
        CClassicArchive::DoBool(param_1, (int *)&param_1, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_18, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_20, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_24, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_28, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_2c, 1);
        CClassicArchive::DoReal(this_00, &local_30, 1);
        CClassicArchive::DoNatural(this_00, (ulong *)&local_34, 1, 0);
        ExceptionList = local_c;
        return;
      case 0x900500c:
        local_30 = 0.0;
        local_34 = (CPlugSolid *)0x0;
        local_28 = (CPlugSolid *)0x0;
        ExceptionList = &local_c;
        CClassicArchive::DoBool(param_1, (int *)&local_34, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_34, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_34, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_34, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_34, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_34, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_34, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_34, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_34, 1);
        CClassicArchive::DoBool(this_00, (int *)&local_34, 1);
        CClassicArchive::DoReal(this_00, &local_30, 1);
        CClassicArchive::DoNatural(this_00, (ulong *)&local_28, 1, 0);
        CClassicArchive::DoReal(this_00, &local_30, 1);
        CClassicArchive::DoReal(this_00, &local_30, 1);
        CClassicArchive::DoReal(this_00, &local_30, 1);
        CClassicArchive::DoReal(this_00, &local_30, 1);
        CClassicArchive::DoNatural(this_00, (ulong *)&local_28, 1, 0);
        CClassicArchive::DoNatural(this_00, (ulong *)&local_28, 1, 0);
        ExceptionList = local_c;
        return;
      case 0x900500d:
        local_28 = (CPlugSolid *)(*(uint *)(this + 0x70) & 1);
        ExceptionList = &local_c;
        CClassicArchive::DoBool(param_1, (int *)&local_28, 1);
        param_1 = (CClassicArchive *)(uint)(*(int *)(this + 0x68) != 0);
        CClassicArchive::DoBool(this_00, (int *)&param_1, 1);
        if (param_1 != (CClassicArchive *)0x0) {
          local_20 = *(CPlugSolid **)(this + 0x68);
          (**(code **)(*(int *)this_00 + 4))(&local_20);
          if (*(int *)(this_00 + 8) == 0) {
            SetModel(this, local_20);
          }
        }
        if (local_28 == (CPlugSolid *)0x0) {
          if (param_1 != (CClassicArchive *)0x0) {
            if (*(int *)(this_00 + 8) != 0) {
              ExceptionList = local_c;
              return;
            }
            SetUseModel(this, 1);
            SetModel(this, *(CPlugSolid **)(this + 0x68));
            SetUseModel(this, 0);
            goto LAB_008558e9;
          }
        } else if (param_1 != (CClassicArchive *)0x0)
          goto LAB_008558e9;
        (**(code **)(*(int *)this_00 + 4))(this + 100);
        if (*(int *)(this_00 + 8) != 0) {
          ExceptionList = local_c;
          return;
        }
        *(undefined4 *)(this + 0x5c) = *(undefined4 *)(this + 100);
      LAB_008558e9:
        if (*(int *)(this_00 + 8) != 0) {
          ExceptionList = local_c;
          return;
        }
        SetUseModel(this, (int)local_28);
        ExceptionList = local_c;
        return;
      case 0x900500e:
        ExceptionList = &local_c;
        CClassicArchive::DoReal(param_1, (float *)(this + 0x18), 1);
        local_18 = *(CPlugSolid **)(this + 0x50);
        local_14 = *(float *)(this + 0x54);
        local_10 = *(float *)(this + 0x58);
        CClassicArchive::DoReal(this_00, (float *)&local_18, 1);
        CClassicArchive::DoReal(this_00, &local_14, 1);
        CClassicArchive::DoReal(this_00, &local_10, 1);
        if (*(int *)(this_00 + 8) == 0) {
          CPlugPhysicalObject::SetComPos((CPlugPhysicalObject *)(this + 0x18),
                                         (GmVec3 *)&local_18);
        }
        GmMat3::ArchiveGmMat3((GmMat3 *)(this + 0x1c), this_00);
        CClassicArchive::DoReal(this_00, (float *)(this + 0x40), 1);
        CClassicArchive::DoReal(this_00, (float *)(this + 0x44), 1);
        CClassicArchive::DoReal(this_00, (float *)(this + 0x48), 1);
        ExceptionList = local_c;
        return;
      }
    } else if (param_2 < 0x9005013) {
      if (param_2 == 0x9005012) {
        param_2 = CONCAT31(0x90050, (char)(*(uint *)(this + 0x70) >> 1));
        ExceptionList = &local_c;
        CClassicArchive::DoNat8(param_1, (uchar *)&param_2, 1, 0);
        *(ulong *)(this + 0x70) =
            (param_2 & 0xff) * 2 | *(uint *)(this + 0x70) & 0xfffffe01;
        ExceptionList = local_c;
        return;
      }
      if (param_2 == 0x9005010) {
        piVar1 = (int *)(param_1 + 0x10);
        param_1 = (CClassicArchive *)0x0;
        local_4 = (uint)(*piVar1 == 0);
        ExceptionList = &local_c;
        CClassicArchive::MwDoNodRef<>(this_00, (CMwNodRef<> *)&param_1);
        local_4 = 0xffffffff;
        if (param_1 == (CClassicArchive *)0x0) {
          ExceptionList = local_c;
          return;
        }
        CMwNod::MwRelease((CMwNod *)param_1);
        ExceptionList = local_c;
        return;
      }
      if (param_2 == 0x9005011) {
        local_2c = *(uint *)(this + 0x70) & 1;
        ExceptionList = &local_c;
        CClassicArchive::DoBool(param_1, (int *)&local_2c, 1);
        ppCVar3 = (CPlugSolid **)(this + 0x68);
        param_1 = (CClassicArchive *)(uint)(*ppCVar3 != (CPlugSolid *)0x0);
        CClassicArchive::DoBool(this_00, (int *)&param_1, 1);
        if (param_1 != (CClassicArchive *)0x0) {
          if (*(int *)(this_00 + 8) == 0) {
            CClassicArchive::DoBool(this_00, (int *)&local_18, 1);
            if (local_18 == (CPlugSolid *)0x0) {
              (**(code **)(*(int *)this_00 + 4))(&local_20);
              SetModel(this, local_20);
            } else {
              (**(code **)(*(int *)this_00 + 8))(&local_24);
              local_20 = LoadFromFidForBeingUseAsAModel(local_24, 0);
              SetModel(this, local_20);
            }
          } else {
            if ((*ppCVar3 == (CPlugSolid *)0x0) ||
                (local_28 = (CPlugSolid *)&DAT_00000001,
                 *(int *)(*ppCVar3 + 8) == 0)) {
              local_28 = (CPlugSolid *)0x0;
            }
            CClassicArchive::DoBool(this_00, (int *)&local_28, 1);
            if (local_28 == (CPlugSolid *)0x0) {
              pcVar4 = *(code **)(*(int *)this_00 + 4);
              ppCVar5 = ppCVar3;
            } else {
              local_18 = *(CPlugSolid **)(*ppCVar3 + 8);
              pcVar4 = *(code **)(*(int *)this_00 + 8);
              ppCVar5 = &local_18;
            }
            (*pcVar4)(ppCVar5, uVar2);
          }
        }
        if (local_2c == 0) {
          if (param_1 != (CClassicArchive *)0x0) {
            if (*(int *)(this_00 + 8) != 0) {
              ExceptionList = local_c;
              return;
            }
            SetUseModel(this, 1);
            SetModel(this, *ppCVar3);
            SetUseModel(this, 0);
            goto LAB_00855c3a;
          }
        } else if (param_1 != (CClassicArchive *)0x0)
          goto LAB_00855c3a;
        (**(code **)(*(int *)this_00 + 4))(this + 100);
        if (*(int *)(this_00 + 8) != 0) {
          ExceptionList = local_c;
          return;
        }
        *(undefined4 *)(this + 0x5c) = *(undefined4 *)(this + 100);
      LAB_00855c3a:
        if (*(int *)(this_00 + 8) != 0) {
          ExceptionList = local_c;
          return;
        }
        SetUseModel(this, local_2c);
        ExceptionList = local_c;
        return;
      }
    } else if (param_2 == 0xffffffff) {
      return;
    }
  switchD_008554f4_caseD_a:
    ExceptionList = &local_c;
    CMwNod::Chunk((CMwNod *)this, param_1, param_2);
  }
  ExceptionList = local_c;
  return;
}

/* public: __thiscall CPlugSolid::CPlugSolid(void) */

CPlugSolid *__thiscall CPlugSolid::CPlugSolid(CPlugSolid *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad5358;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CPlug::CPlug((CPlug *)this);
  local_4 = 0;
  *(undefined ***)this = vftable;
  CPlugPhysicalObject::CPlugPhysicalObject(
      (CPlugPhysicalObject *)(this + 0x18));
  *(undefined4 *)(this + 0x60) = 1;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(uint *)(this + 0x70) = *(uint *)(this + 0x70) | 1;
  ExceptionList = local_c;
  return this;
}

/* public: virtual void __thiscall CPlugSolid::CreateDefaultData(void) */

void __thiscall CPlugSolid::CreateDefaultData(CPlugSolid *this)

{
  CPlugTree *pCVar1;
  CPlugVisualQuads *this_00;
  CPlugVisualQuads *this_01;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad5576;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = (CPlugTree *)operator_new(0xac);
  this_01 = (CPlugVisualQuads *)0x0;
  local_4 = 0;
  if (pCVar1 == (CPlugTree *)0x0) {
    pCVar1 = (CPlugTree *)0x0;
  } else {
    pCVar1 = (CPlugTree *)CPlugTree::CPlugTree(pCVar1);
  }
  local_4 = 0xffffffff;
  this_00 = (CPlugVisualQuads *)operator_new(0x98);
  local_4 = 1;
  if (this_00 != (CPlugVisualQuads *)0x0) {
    this_01 = (CPlugVisualQuads *)CPlugVisualQuads::CPlugVisualQuads(this_00);
  }
  local_1c = 0x3f800000;
  local_18 = 0x3f800000;
  local_14 = 0x3f800000;
  local_10 = 0x3f800000;
  local_4 = 0xffffffff;
  CPlugVisualQuads::BoxQuadAdd(this_01, 0.5, 0xffffffff, (GxColor *)&local_1c);
  CPlugTree::SetVisual(pCVar1, (CPlugVisual *)this_01, (CPlugShader *)0x0,
                       (CPlugMaterial *)0x0, 1);
  SetTree(this, pCVar1, 1);
  ExceptionList = local_c;
  return;
}

/* public: class CPlugSolid * __thiscall CPlugSolid::CreateModelInstance(void)
 */

CPlugSolid *__thiscall CPlugSolid::CreateModelInstance(CPlugSolid *this)

{
  CPlugSolid *this_00;
  CPlugSolid *this_01;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad55db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = (CPlugSolid *)operator_new(0x74);
  this_01 = (CPlugSolid *)0x0;
  local_4 = 0;
  if (this_00 != (CPlugSolid *)0x0) {
    this_01 = (CPlugSolid *)CPlugSolid(this_00);
  }
  local_4 = 0xffffffff;
  SetModel(this_01, this);
  ExceptionList = local_c;
  return this_01;
}

/* public: void __thiscall CPlugSolid::DisconnectFromModel(int) */

void __thiscall CPlugSolid::DisconnectFromModel(CPlugSolid *this, int param_1)

{
  if (param_1 == 0) {
    CPlugTree::DisconnectFromModel(*(CPlugTree **)(this + 100), 1, 0xffffffff);
    (**(code **)(**(int **)(this + 100) + 0x78))(0);
    (**(code **)(**(int **)(this + 100) + 0xbc))(1);
  }
  CMwNod::MwRelease(*(CMwNod **)(this + 0x68));
  *(undefined4 *)(this + 0x68) = 0;
  return;
}

/* public: void __thiscall CPlugSolid::ExclusionEllipsoidRadiusCompute(void) */

void __thiscall CPlugSolid::ExclusionEllipsoidRadiusCompute(CPlugSolid *this)

{
  float fVar1;
  CPlugTree *pCVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  ulong uVar6;
  float *pfVar7;
  ulong uVar8;
  float10 fVar9;
  CPlugTree *pCStack_98;
  CPlugTree *pCStack_90;
  CPlugTree *pCStack_8c;
  CPlugTree *pCStack_88;
  CPlugTree *pCStack_84;
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
  CIteratorVisual aCStack_50[12];
  int iStack_44;
  GmIso4 aGStack_3c[36];
  float fStack_18;
  float fStack_14;
  float fStack_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad54f8;
  local_c = ExceptionList;
  uVar3 = ___security_cookie ^ (uint)&stack0xffffff58;
  ExceptionList = &local_c;
  *(undefined4 *)(this + 0x6c) = 0;
  if (*(int **)(this + 100) != (int *)0x0) {
    (**(code **)(**(int **)(this + 100) + 0xbc))(0, uVar3);
    pCVar2 = *(CPlugTree **)(this + 100);
    if (0.0 <= *(float *)(pCVar2 + 0x40)) {
      fStack_80 = *(float *)(pCVar2 + 0x34);
      fStack_7c = *(float *)(pCVar2 + 0x38);
      fStack_78 = *(float *)(pCVar2 + 0x3c);
      pCStack_8c = *(CPlugTree **)(pCVar2 + 0x40);
      pCStack_88 = *(CPlugTree **)(pCVar2 + 0x44);
      pCStack_84 = *(CPlugTree **)(pCVar2 + 0x48);
      pCStack_98 = pCStack_84;
      if ((float)pCStack_88 <= (float)pCStack_84) {
        pCStack_98 = pCStack_88;
      }
      pCStack_90 = pCStack_8c;
      if ((float)pCStack_98 < (float)pCStack_8c) {
        pCStack_90 = pCStack_98;
      }
      pCStack_98 = pCStack_84;
      if ((float)pCStack_84 <= (float)pCStack_88) {
        pCStack_98 = pCStack_88;
      }
      if ((float)pCStack_98 < (float)pCStack_8c !=
          ((float)pCStack_98 == (float)pCStack_8c)) {
        pCStack_98 = pCStack_8c;
      }
      if (((float)pCStack_90 < 0.1 == NAN((float)pCStack_90)) &&
          ((float)pCStack_98 / (float)pCStack_90 <= 20.0)) {
        fStack_54 = (float)pCStack_8c / 1.0;
        fStack_68 = (float)pCStack_88 / 1.0;
        fStack_58 = 1.0 / (float)pCStack_84;
        pCStack_98 = (CPlugTree *)0x7f7fffff;
        CPlugTree::CIteratorVisual::CIteratorVisual(aCStack_50, pCVar2, 0);
        uStack_4 = 0;
        while (iStack_44 != 0) {
          piVar4 = (int *)CPlugTree::CIteratorVisual::GetNextVisual(
              aCStack_50, &pCStack_90);
          iVar5 = (**(code **)(*piVar4 + 0x10))(0x902c000);
          if (iVar5 == 0)
            goto LAB_00855119;
          CPlugTree::GetThisToRootTransfo(pCStack_90, aGStack_3c, 1,
                                          (CPlugTree *)0x0);
          pCStack_8c = (CPlugTree *)(fStack_80 - fStack_18);
          pCStack_88 = (CPlugTree *)(fStack_7c - fStack_14);
          pCStack_84 = (CPlugTree *)(fStack_78 - fStack_10);
          GmVec3::MultTranspose((GmVec3 *)&pCStack_8c, (GmMat3 *)aGStack_3c);
          uVar6 = CFastBuffer<>::GetCount((CFastBuffer<> *)(piVar4 + 0x1e));
          uVar8 = 0;
          if (uVar6 != 0) {
            do {
              pfVar7 = (float *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(piVar4 + 0x1e), uVar8);
              fStack_74 = *pfVar7 - (float)pCStack_8c;
              fStack_70 = pfVar7[1] - (float)pCStack_88;
              fStack_6c = pfVar7[2] - (float)pCStack_84;
              fStack_64 = fStack_74 * fStack_54;
              fStack_60 = fStack_70 * fStack_68;
              fStack_5c = fStack_6c * fStack_58;
              fVar9 = (float10)__CIsqrt();
              fVar1 = (float)fVar9;
              if ((fVar1 < (float)pCStack_98) &&
                  (pCStack_98 = (CPlugTree *)fVar1, fVar1 < 0.1 != NAN(fVar1)))
                goto LAB_00855119;
              uVar8 = uVar8 + 1;
            } while (uVar8 < uVar6);
          }
        }
        *(CPlugTree **)(this + 0x6c) = pCStack_98;
      LAB_00855119:
        CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)aCStack_50);
      }
    }
  }
  ExceptionList = local_c;
  return;
}

/* public: int __thiscall CPlugSolid::ExclusionEllipsoidRadiusIsCulled(class
   GmFrustum const &,class GmIso4 const &) */

int __thiscall CPlugSolid::ExclusionEllipsoidRadiusIsCulled(CPlugSolid *this,
                                                            GmFrustum *param_1,
                                                            GmIso4 *param_2)

{
  float fVar1;
  uint uVar2;
  GmVec3 *pGVar3;
  float10 fVar4;
  GmVec3 local_6c[12];
  GmVec3 local_60[48];
  GmVec3 local_30[48];

  if (((*(int *)(this + 100) != 0) &&
       (0.0 <= *(float *)(*(int *)(this + 100) + 0x40))) &&
      (NAN(*(float *)(this + 0x6c)) == (*(float *)(this + 0x6c) == 0.0))) {
    if (*(int *)param_1 == 0) {
      fVar1 = *(float *)(param_1 + 0xc);
    } else {
      fVar1 = *(float *)(param_1 + 0xc) - *(float *)(param_1 + 0x18);
    }
    GmFrustum::GetVertices4AtZ(param_1, local_60, fVar1);
    if (*(int *)param_1 == 0) {
      fVar1 = *(float *)(param_1 + 0x18);
    } else {
      fVar1 = *(float *)(param_1 + 0x18) + *(float *)(param_1 + 0xc);
    }
    GmFrustum::GetVertices4AtZ(param_1, local_30, fVar1);
    uVar2 = 0;
    pGVar3 = local_60;
    do {
      GmVec3::SetMult(local_6c, pGVar3, param_2);
      fVar4 = (float10)__CIsqrt();
      if (*(float *)(this + 0x6c) < (float)fVar4 !=
          (*(float *)(this + 0x6c) == (float)fVar4)) {
        return 0;
      }
      uVar2 = uVar2 + 1;
      pGVar3 = pGVar3 + 0xc;
    } while (uVar2 < 8);
    return 1;
  }
  return 0;
}

/* public: virtual unsigned long __thiscall CPlugSolid::GetChunkInfo(unsigned
 * long)const  */

ulong __thiscall CPlugSolid::GetChunkInfo(CPlugSolid *this, ulong param_1)

{
  ulong uVar1;

  if (param_1 < 0x900500b) {
    if (param_1 != 0x900500a) {
      switch (param_1) {
      case 0x9005000:
      switchD_00853a68_caseD_9005000:
        return 3;
      case 0x9005001:
      case 0x9005002:
      case 0x9005003:
      case 0x9005004:
      case 0x9005005:
      case 0x9005006:
      case 0x9005007:
      case 0x9005008:
      case 0x9005009:
        break;
      default:
        goto switchD_00853a68_caseD_a;
      }
    }
  } else {
    if (0x900500f < param_1) {
      if (param_1 < 0x9005013) {
        if (param_1 == 0x9005012) {
          return 3;
        }
        if (param_1 == 0x9005010) {
          return 3;
        }
        if (param_1 == 0x9005011) {
          return 3;
        }
      } else if (param_1 == 0xffffffff) {
        return 0xffffffff;
      }
    switchD_00853a68_caseD_a:
      uVar1 = CMwNod::GetChunkInfo((CMwNod *)this, param_1);
      return uVar1;
    }
    if (param_1 != 0x900500f) {
      switch (param_1) {
      case 0x900500b:
      case 0x900500c:
      case 0x900500d:
        break;
      case 0x900500e:
        goto switchD_00853a68_caseD_9005000;
      default:
        goto switchD_00853a68_caseD_a;
      }
    }
  }
  return 1;
}

/* public: virtual unsigned long __thiscall CPlugSolid::GetMwClassId(void)const
 */

ulong __thiscall CPlugSolid::GetMwClassId(CPlugSolid *this)

{
  return 0x9005000;
}

/* public: class CPlugTree * __thiscall CPlugSolid::GetPlugFromId(class CMwId
 * const &)const  */

CPlugTree *__thiscall CPlugSolid::GetPlugFromId(CPlugSolid *this,
                                                CMwId *param_1)

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

/* public: virtual unsigned long __thiscall
 * CPlugSolid::GetUidChunkFromIndex(unsigned long)const  */

ulong __thiscall CPlugSolid::GetUidChunkFromIndex(CPlugSolid *this,
                                                  ulong param_1)

{
  if (param_1 == 0) {
    return 0x1001000;
  }
  return param_1 - 1 | 0x9005000;
}

/* public: void __thiscall CPlugSolid::GivePlugId(class CMwId &)const  */

void __thiscall CPlugSolid::GivePlugId(CPlugSolid *this, CMwId *param_1)

{
  int iVar1;

  iVar1 = *(int *)(this + 0x60);
  *(int *)(this + 0x60) = iVar1 + 1;
  *(int *)param_1 = iVar1;
  return;
}

/* public: void __thiscall CPlugSolid::InternalConnectSubTree(class CPlugTree *)
 */

void __thiscall CPlugSolid::InternalConnectSubTree(CPlugSolid *this,
                                                   CPlugTree *param_1)

{
  FUN_00853b60((int *)param_1, (ulong)this);
  MakeTreeIdsUnique(this);
  return;
}

/* public: void __thiscall CPlugSolid::InternalDisconnectSubTree(class CPlugTree
 * *) */

void __thiscall CPlugSolid::InternalDisconnectSubTree(CPlugSolid *this,
                                                      CPlugTree *param_1)

{
  uint uVar1;
  CPlugTree *pCVar2;
  uint uVar3;

  CInputEventsStore::Lock((CInputEventsStore *)param_1, 0);
  uVar1 = (**(code **)(*(int *)param_1 + 0x7c))();
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      pCVar2 = (CPlugTree *)(**(code **)(*(int *)param_1 + 0x80))(uVar3);
      InternalDisconnectSubTree(this, pCVar2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* public: static class CPlugSolid * __cdecl
   CPlugSolid::LoadFromFidForBeingUseAsAModel(class CSystemFid *,int) */

CPlugSolid *__cdecl CPlugSolid::LoadFromFidForBeingUseAsAModel(
    CSystemFid *param_1, int param_2)

{
  CMwNod *pCVar1;
  CSystemFidParameters *this;
  CMwNod *local_88;
  SParam_Id local_84[24];
  SParam_Id local_6c[24];
  SParam_Id local_54[24];
  CSystemFidParameters local_3c[48];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad5403;
  local_c = ExceptionList;
  if (param_1 == (CSystemFid *)0x0) {
    return (CPlugSolid *)0x0;
  }
  ExceptionList = &local_c;
  this = CSystemFidParameters::GetCurrentParameters();
  CSystemFidParameters::CSystemFidParameters(local_3c,
                                             &CSystemFidParameters::Empty);
  local_4 = 0;
  CSystemFidParameters::SParam_Id::SParam_Id(local_54, (CMwId *)&DAT_00d6e954,
                                             0, (ulong *)0x0, 0);
  local_4._0_1_ = 1;
  CSystemFidParameters::GetParamValue(this, (SParam *)local_54);
  CSystemFidParameters::AddParam(local_3c, (SParam *)local_54);
  if (param_2 == 0) {
    CSystemFidParameters::SParam_Id::SParam_Id(local_6c, (CMwId *)&DAT_00d6e958,
                                               0, (ulong *)0x0, 0);
    local_4._0_1_ = 2;
    CSystemFidParameters::GetParamValue(this, (SParam *)local_6c);
    CSystemFidParameters::AddParam(local_3c, (SParam *)local_6c);
    CSystemFidParameters::SParam_Id::SParam_Id(local_84, (CMwId *)&DAT_00d6e95c,
                                               0, (ulong *)0x0, 0);
    local_4._0_1_ = 3;
    CSystemFidParameters::GetParamValue(this, (SParam *)local_84);
    CSystemFidParameters::AddParam(local_3c, (SParam *)local_84);
    local_4._0_1_ = 2;
    CSystemFidParameters::SParam_Id::~SParam_Id(local_84);
    local_4._0_1_ = 1;
    CSystemFidParameters::SParam_Id::~SParam_Id(local_6c);
  }
  local_88 = CSystemFid::ParametrizedGetAnyLoadedNodLooselyFittingTheParams(
      param_1, local_3c);
  if (local_88 == (CMwNod *)0x0) {
    CSystemArchiveNod::LoadFromFid(&local_88, param_1, 7);
  }
  pCVar1 = local_88;
  local_4 = (uint)local_4._1_3_ << 8;
  CSystemFidParameters::SParam_Id::~SParam_Id(local_54);
  local_4 = 0xffffffff;
  CSystemFidParameters::~CSystemFidParameters(local_3c);
  ExceptionList = local_c;
  return (CPlugSolid *)pCVar1;
}

/* public: void __thiscall CPlugSolid::MakeTreeIdsUnique(void) */

void __thiscall CPlugSolid::MakeTreeIdsUnique(CPlugSolid *this)

{
  CMwClassInfo *pCVar1;
  ulong uVar2;
  int *piVar3;
  int iVar4;
  CMwId *pCVar5;
  ulong *puVar6;
  char *pcVar7;
  CFastString *extraout_ECX;
  CFastString *this_00;
  CFastString *extraout_ECX_00;
  undefined4 *this_01;
  undefined4 *puVar8;
  uint uVar9;
  ulong uStack_48;
  ulong uStack_44;
  undefined4 *local_40;
  CPlugSolid *local_3c;
  ulong local_38;
  CFastMapTable<> *local_34;
  undefined4 uStack_30;
  char *pcStack_2c;
  undefined4 uStack_28;
  char *pcStack_24;
  undefined4 uStack_20;
  char *pcStack_1c;
  void *local_14;
  undefined *puStack_10;
  undefined4 local_c;

  local_c = 0xffffffff;
  puStack_10 = &LAB_00ad54c9;
  local_14 = ExceptionList;
  pCVar1 = (CMwClassInfo *)(___security_cookie ^ (uint)&stack0xffffffa8);
  ExceptionList = &local_14;
  puVar8 = (undefined4 *)0x0;
  local_3c = this;
  uVar2 = CPlugTree::GetRecursiveTreeCount(*(CPlugTree **)(this + 100), 0, 1);
  if (uVar2 < 2) {
    piVar3 = (int *)(**(code **)(**(int **)(this + 100) + 0x14))();
    if (*piVar3 == -1) {
      CMwId::CMwId((CMwId *)&uStack_44);
      local_c = 0;
      GivePlugId(this, (CMwId *)&uStack_44);
      CPlugTree::InternalSetMwId(*(CPlugTree **)(this + 100),
                                 (CMwId *)&uStack_44);
      local_c = 0xffffffff;
      CScene2d::OnNodLoaded((CScene2d *)&uStack_44);
      ExceptionList = local_14;
      return;
    }
  } else {
    if ((DAT_00d6e984 & 1) == 0) {
      DAT_00d6e984 = DAT_00d6e984 | 1;
      local_c = 1;
      CFastMapTable<>::CFastMapTable<>((CFastMapTable<> *)&DAT_00d6e974, 0x23);
      _atexit((_func_4879 *)&LAB_00b233e0);
      local_c = 0xffffffff;
    }
    local_40 = (undefined4 *)0x0;
    if (uVar2 < 0x21) {
      CFastMapTable<>::Clear((CFastMapTable<> *)&DAT_00d6e974);
    } else {
      local_34 = (CFastMapTable<> *)operator_new(0x10);
      local_c = 2;
      if (local_34 == (CFastMapTable<> *)0x0) {
        local_c = 0xffffffff;
        local_40 = (undefined4 *)0x0;
        puVar8 = (undefined4 *)0x0;
      } else {
        puVar8 =
            (undefined4 *)CFastMapTable<>::CFastMapTable<>(local_34, uVar2 + 3);
        local_c = 0xffffffff;
        local_40 = puVar8;
      }
    }
    this_01 = (undefined4 *)&DAT_00d6e974;
    if (0x20 < uVar2) {
      this_01 = puVar8;
    }
    local_38 = __InitClassInfo_CFuncShader(pCVar1);
    while (local_38 != 0xffffffff) {
      piVar3 = (int *)CPlugTree::GetAllTreeNext(*(CPlugTree **)(this + 100),
                                                &local_38);
      iVar4 = CPlugTree::GetIsRooted((CPlugTree *)piVar3);
      puVar8 = local_40;
      if (iVar4 != 0) {
        pCVar5 = (CMwId *)(**(code **)(*piVar3 + 0x14))();
        CMwId::CMwId((CMwId *)&uStack_48, pCVar5);
        uVar9 = uStack_48;
        local_c = 3;
        if (uStack_48 == 0xffffffff) {
          GivePlugId(this, (CMwId *)&uStack_48);
          CPlugTree::InternalSetMwId((CPlugTree *)piVar3, (CMwId *)&uStack_48);
          local_34 = (CFastMapTable<> *)0x0;
          CFastMapTable<>::Add((CFastMapTable<> *)this_01, (ulong *)&local_34,
                               uStack_48);
        } else if ((uStack_48 & 0xc0000000) == 0) {
          if ((*(uint *)(this + 0x60) <= uStack_48) ||
              (iVar4 = CFastMapTable<>::GetElem((CFastMapTable<> *)this_01,
                                                uStack_48, &uStack_44),
               iVar4 != 0)) {
            GivePlugId(this, (CMwId *)&uStack_48);
            CPlugTree::InternalSetMwId((CPlugTree *)piVar3,
                                       (CMwId *)&uStack_48);
            uVar9 = uStack_48;
          }
          local_34 = (CFastMapTable<> *)0x0;
          CFastMapTable<>::Add((CFastMapTable<> *)this_01, (ulong *)&local_34,
                               uVar9);
        } else {
          iVar4 = CFastMapTable<>::GetElem((CFastMapTable<> *)this_01,
                                           uStack_48, &uStack_44);
          if (iVar4 == 0) {
            local_34 = (CFastMapTable<> *)0x0;
            CFastMapTable<>::Add((CFastMapTable<> *)this_01, (ulong *)&local_34,
                                 uVar9);
          } else {
            uStack_30 = 0;
            pcStack_2c = "";
            local_c._0_1_ = 4;
            CMwId::GetName((CMwId *)&uStack_48, &uStack_28);
            local_c = CONCAT31(local_c._1_3_, 5);
            this_00 = extraout_ECX;
            uVar2 = uStack_44;
            do {
              uVar2 = uVar2 + 1;
              CFastString::Format(this_00, (char *)&uStack_30, "%s_%2d",
                                  pcStack_24, uVar2);
              CMwId::SetLocalName((CMwId *)&uStack_48, pcStack_2c);
              CMwId::GetName((CMwId *)&uStack_48, &uStack_20);
              if (pcStack_1c != "") {
                pcVar7 = pcStack_1c + -1;
                if ((pcStack_1c[-1] & 0x80U) != 0) {
                  pcVar7 = pcStack_1c + -4;
                }
                operator_delete[](pcVar7);
                uStack_20 = 0;
                pcStack_1c = "";
              }
              iVar4 = CFastMapTable<>::IsPresent((CFastMapTable<> *)this_01,
                                                 uStack_48);
              this_00 = extraout_ECX_00;
            } while (iVar4 != 0);
            uStack_44 = uVar2;
            CPlugTree::InternalSetMwId((CPlugTree *)piVar3,
                                       (CMwId *)&uStack_48);
            local_34 = (CFastMapTable<> *)0x0;
            CFastMapTable<>::Add((CFastMapTable<> *)this_01, (ulong *)&local_34,
                                 uStack_48);
            puVar6 =
                CFastMapTable<>::operator[]((CFastMapTable<> *)this_01, uVar9);
            *puVar6 = uVar2;
            if (pcStack_24 != "") {
              pcVar7 = pcStack_24 + -1;
              if ((pcStack_24[-1] & 0x80U) != 0) {
                pcVar7 = pcStack_24 + -4;
              }
              operator_delete[](pcVar7);
              uStack_28 = 0;
              pcStack_24 = "";
            }
            this = local_3c;
            if (pcStack_2c != "") {
              pcVar7 = pcStack_2c + -1;
              if ((pcStack_2c[-1] & 0x80U) != 0) {
                pcVar7 = pcStack_2c + -4;
              }
              operator_delete[](pcVar7);
              uStack_30 = 0;
              pcStack_2c = "";
              this = local_3c;
            }
          }
        }
        local_c = 0xffffffff;
        CScene2d::OnNodLoaded((CScene2d *)&uStack_48);
        puVar8 = local_40;
      }
    }
    if (puVar8 != (undefined4 *)0x0) {
      (**(code **)*puVar8)(1);
    }
  }
  ExceptionList = local_14;
  return;
}

/* public: virtual class CMwClassInfo const * __thiscall
 * CPlugSolid::MwGetClassInfo(void)const  */

CMwClassInfo *__thiscall CPlugSolid::MwGetClassInfo(CPlugSolid *this)

{
  return &m_MwClassInfo_CPlugSolid;
}

/* public: virtual int __thiscall CPlugSolid::MwIsKindOf(unsigned long)const  */

int __thiscall CPlugSolid::MwIsKindOf(CPlugSolid *this, ulong param_1)

{
  if ((param_1 != 0x9005000) && (param_1 != 0x902b000)) {
    return (uint)(param_1 == 0x1001000);
  }
  return 1;
}

/* public: static class CMwNod * __cdecl CPlugSolid::MwNewCPlugSolid(void) */

CMwNod *__cdecl CPlugSolid::MwNewCPlugSolid(void)

{
  CPlugSolid *this;
  CMwNod *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad53bb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = (CPlugSolid *)operator_new(0x74);
  local_4 = 0;
  if (this != (CPlugSolid *)0x0) {
    pCVar1 = (CMwNod *)CPlugSolid(this);
    ExceptionList = local_c;
    return pCVar1;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: virtual int __thiscall CPlugSolid::OnCrashDump(class CFastString &)
 */

int __thiscall CPlugSolid::OnCrashDump(CPlugSolid *this, CFastString *param_1)

{
  int iVar1;

  iVar1 = CMwNod::OnCrashDump((CMwNod *)this, param_1);
  if (iVar1 == 0) {
    return 0;
  }
  (**(code **)(_s_SystemCrashDump + 0x14))();
  CSystemCrashDump::ContextPush(&CSystemCrashDump::s_SystemCrashDump, "Tree");
  FUN_008546a0((char *)param_1, *(int **)(this + 100));
  CSystemCrashDump::ContextPop(&CSystemCrashDump::s_SystemCrashDump);
  if (*(CMwNod **)(this + 0x68) != (CMwNod *)0x0) {
    iVar1 = CSystemCrashDump::IsValid_DumpFidAndMwId(
        &CSystemCrashDump::s_SystemCrashDump, param_1, "Solid Model",
        *(CMwNod **)(this + 0x68), 1);
    if (iVar1 != 0) {
      (**(code **)(**(int **)(this + 0x68) + 0x58))(param_1);
    }
  }
  (**(code **)(_s_SystemCrashDump + 0x18))();
  return 1;
}

/* public: virtual void __thiscall CPlugSolid::OnNodLoaded(void) */

void __thiscall CPlugSolid::OnNodLoaded(CPlugSolid *this)

{
  CScene2d::OnNodLoaded((CScene2d *)this);
  if (*(int *)(*(CPlugTree **)(this + 100) + 0x14) == 0) {
    InternalConnectSubTree(this, *(CPlugTree **)(this + 100));
  }
  if (*(int *)(this + 100) != 0) {
    (**(code **)(**(int **)(this + 100) + 0x78))(0);
  }
  (**(code **)(**(int **)(this + 100) + 0xbc))(1);
  return;
}

/* protected: void __thiscall CPlugSolid::SetModel(class CPlugSolid *) */

void __thiscall CPlugSolid::SetModel(CPlugSolid *this, CPlugSolid *param_1)

{
  CPlugTree *pCVar1;

  if (param_1 != (CPlugSolid *)0x0) {
    CMwNod::MwAddRef((CMwNod *)param_1);
  }
  if (*(CMwNod **)(this + 0x68) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x68));
  }
  *(CPlugSolid **)(this + 0x68) = param_1;
  if ((param_1 != (CPlugSolid *)0x0) && (((byte)this[0x70] & 1) != 0)) {
    *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
    CPlugPhysicalObject::CopyFrom((CPlugPhysicalObject *)(this + 0x18),
                                  (CPlugPhysicalObject *)(param_1 + 0x18));
    pCVar1 = CPlugTree::InternalCreateSolidModelInstance(
        *(CPlugTree **)(*(int *)(this + 0x68) + 100));
    SetTree(this, pCVar1, 0);
  }
  return;
}

/* public: void __thiscall CPlugSolid::SetTree(class CPlugTree *,int) */

void __thiscall CPlugSolid::SetTree(CPlugSolid *this, CPlugTree *param_1,
                                    int param_2)

{
  int *piVar1;

  piVar1 = *(int **)(this + 100);
  if ((int *)param_1 != piVar1) {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(1);
    }
    *(CPlugTree **)(this + 100) = param_1;
    *(CPlugTree **)(this + 0x5c) = param_1;
    if (param_1 != (CPlugTree *)0x0) {
      (**(code **)(*(int *)param_1 + 0x78))(0);
      InternalConnectSubTree(this, *(CPlugTree **)(this + 100));
      (**(code **)(**(int **)(this + 100) + 0xbc))(param_1);
    }
  }
  return;
}

/* public: void __thiscall CPlugSolid::SetUseModel(int) */

void __thiscall CPlugSolid::SetUseModel(CPlugSolid *this, int param_1)

{
  uint uVar1;

  uVar1 = *(uint *)(this + 0x70);
  if ((uVar1 & 1) != (uint)(param_1 != 0)) {
    uVar1 = (param_1 != 0 ^ uVar1) & 1 ^ uVar1;
    *(uint *)(this + 0x70) = uVar1;
    if (*(CPlugSolid **)(this + 0x68) != (CPlugSolid *)0x0) {
      if ((uVar1 & 1) != 0) {
        SetModel(this, *(CPlugSolid **)(this + 0x68));
        return;
      }
      if (*(CPlugTree **)(this + 100) != (CPlugTree *)0x0) {
        CPlugTree::DisconnectFromModel(*(CPlugTree **)(this + 100), 1,
                                       0xffffffff);
      }
    }
  }
  return;
}

/* public: virtual unsigned long __thiscall CPlugSolid::VirtualParam_Get(class
   CMwStack *,class CMwValueStd *) */

ulong __thiscall CPlugSolid::VirtualParam_Get(CPlugSolid *this,
                                              CMwStack *param_1,
                                              CMwValueStd *param_2)

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
      *(CMwValueStd **)param_2 = param_2 + 4;
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
    uVar4 = CMwNod::VirtualParam_Get((CMwNod *)this, param_1, param_2);
    return uVar4;
  }
  if (uVar3 == 0x9005006) {
    *(CMwValueStd **)param_2 = param_2 + 4;
    *(uint *)(param_2 + 4) = *(uint *)(this + 0x70) >> 1 & 0xff;
  } else {
    if (uVar3 == 0x9005007) {
      *(CPlugSolid **)param_2 = this + 0x48;
      return 0;
    }
    if (uVar3 != 0xffffffff)
      goto LAB_00853fd1;
  }
  return 0;
}

/* public: virtual unsigned long __thiscall CPlugSolid::VirtualParam_Set(class
 * CMwStack *,void *) */

ulong __thiscall CPlugSolid::VirtualParam_Set(CPlugSolid *this,
                                              CMwStack *param_1, void *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;

  iVar2 = *(int *)(param_1 + 0x18);
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + iVar2 * 4);
  iVar1 = iVar2 + -1;
  *(int *)(param_1 + 0x18) = iVar1;
  uVar4 = *(uint *)(iVar3 + 4);
  if (uVar4 < 0x9005004) {
    if (uVar4 != 0x9005003) {
      if (uVar4 == 0x9005000) {
        /* WARNING: Load size is inaccurate */
        *(undefined4 *)(this + 0x18) = *param_2;
        return 0;
      }
      if (uVar4 == 0x9005001) {
        /* WARNING: Load size is inaccurate */
        *(undefined4 *)(this + 0x40) = *param_2;
        return 0;
      }
      if (uVar4 == 0x9005002) {
        /* WARNING: Load size is inaccurate */
        *(undefined4 *)(this + 0x44) = *param_2;
        return 0;
      }
    LAB_008540a2:
      *(int *)(param_1 + 0x18) = iVar2;
      uVar5 = CMwNod::VirtualParam_Set((CMwNod *)this, param_1, param_2);
      return uVar5;
    }
    if (-1 < iVar1) {
      CMwNod::Param_Set(*(CMwNod **)(this + 100), param_1, param_2);
      return 0;
    }
  } else if (uVar4 == 0x9005004) {
    if (iVar1 < 0) {
      if ((*(int *)(this + 0x68) != 0) && (param_2 == (void *)0x0)) {
        DisconnectFromModel(this, 0);
        return 0;
      }
    } else {
      CMwNod::Param_Set(*(CMwNod **)(this + 0x68), param_1, param_2);
    }
  } else {
    if (uVar4 == 0x9005007) {
      /* WARNING: Load size is inaccurate */
      *(undefined4 *)(this + 0x48) = *param_2;
      return 0;
    }
    if (uVar4 != 0xffffffff)
      goto LAB_008540a2;
  }
  return 0;
}

/* public: virtual __thiscall CPlugSolid::~CPlugSolid(void) */

void __thiscall CPlugSolid::~CPlugSolid(CPlugSolid *this)

{
  uint uVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00ad5388;
  local_c = ExceptionList;
  uVar1 = ___security_cookie ^ (uint)&stack0xffffffec;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 0;
  if (*(int **)(this + 100) != (int *)0x0) {
    (**(code **)(**(int **)(this + 100) + 4))(1, uVar1);
  }
  if (*(CMwNod **)(this + 0x68) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x68));
    *(undefined4 *)(this + 0x68) = 0;
  }
  local_4 = 0xffffffff;
  CPlug::~CPlug((CPlug *)this);
  ExceptionList = local_c;
  return;
}
