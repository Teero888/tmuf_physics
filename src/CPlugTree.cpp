
/* public: virtual void * __thiscall CPlugTree::`scalar deleting
 * destructor'(unsigned int) */

void *__thiscall CPlugTree::`scalar_deleting_destructor'(CPlugTree *this,uint param_1)

{
  ~CPlugTree(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: virtual void __thiscall CPlugTree::AddChild(class CPlugTree *) */

void __thiscall CPlugTree::AddChild(CPlugTree *this, CPlugTree *param_1)

{
  CPlugTree *pCVar1;

  CFastBuffer<>::Add((CFastBuffer<> *)(this + 0x28),
                     (CDx9TextureKeeper **)&param_1);
  pCVar1 = param_1;
  if (*(int *)(this + 0x14) != 0) {
    (**(code **)(*(int *)param_1 + 0x78))(0);
  }
  ConnectAsChild(this, pCVar1, 1);
  return;
}

/* public: virtual void __thiscall CPlugTree::ApplyFidParameters(class
 *CSystemFidParameters const ,class CSystemFidParameters *,class
 *CFastBuffer<struct CMwNod::SManuallyLoadedFid> &) */

void __thiscall CPlugTree::ApplyFidParameters(CPlugTree *this,
                                              CSystemFidParameters *param_1,
                                              CSystemFidParameters *param_2,
                                              CFastBuffer<> *param_3)

{
  CVisionViewportNull::SetFullScreenGammaRamp((CVisionViewportNull *)this,
                                              (float)param_1, (float)param_2,
                                              (float)param_3);
  if (*(int *)(this + 0x94) != 0) {
    PlugTree_SetRenderBeforeForSpecialFidParametrization(this, param_1,
                                                         param_2);
  }
  return;
}

/* public: class CPlugShader * __thiscall CPlugTree::ChangeShaderClass(unsigned
 * long) */

CPlugShader *__thiscall CPlugTree::ChangeShaderClass(CPlugTree *this,
                                                     ulong param_1)

{
  int iVar1;
  CMwClassInfo *this_00;
  int *piVar2;
  ulong *puVar3;
  ulong *puVar4;
  ulong uVar5;
  ulong local_5c[22];
  int iStack_4;

  local_5c[0] = 0x9068000;
  iVar1 = (**(code **)(**(int **)(this + 0x90) + 0x78))();
  if ((iVar1 == 7) && ((*(byte *)(*(int *)(this + 0x90) + 0xb0) & 7) == 0)) {
    puVar3 = local_5c;
    uVar5 = 1;
    this_00 = CMwNod::StaticGetClassInfo(param_1);
    uVar5 = CMwClassInfo::MwGetNearestFather(this_00, uVar5, puVar3);
    if (uVar5 == 0xffffffff)
      goto LAB_00849d38;
  }
  if ((*(int **)(this + 0x94) != (int *)0x0) &&
      (uVar5 = (**(code **)(**(int **)(this + 0x94) + 0xc))(),
       uVar5 != param_1)) {
    piVar2 = (int *)CMwNod::CreateByMwClassId(param_1);
    iVar1 = (**(code **)(**(int **)(this + 0x94) + 0x10))(0x9004000);
    if ((iVar1 != 0) &&
        (iVar1 = (**(code **)(*piVar2 + 0x10))(0x9004000), iVar1 != 0)) {
      puVar3 = (ulong *)(*(int *)(this + 0x94) + 0x38);
      puVar4 = local_5c;
      for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
    SetShader(this, (CPlugShader *)piVar2);
    (**(code **)(**(int **)(this + 0x90) + 0x7c))(*(undefined4 *)(this + 0x94));
    if (iStack_4 != 0) {
      CPlugShaderGeneric::SetMaterial(*(CPlugShaderGeneric **)(this + 0x94),
                                      (SMaterial *)&stack0xffffffa0);
    }
  }
LAB_00849d38:
  return *(CPlugShader **)(this + 0x94);
}

/* public: virtual void __thiscall CPlugTree::Chunk(class CClassicArchive
 * &,unsigned long) */

void __thiscall CPlugTree::Chunk(CPlugTree *this, CClassicArchive *param_1,
                                 ulong param_2)

{
  CFastBuffer<> *this_00;
  uint *puVar1;
  CClassicArchive *pCVar2;
  ulong uVar3;
  CPlugTree **ppCVar4;
  int iVar5;
  CDx9TextureKeeper **ppCVar6;
  uint uVar7;
  CFastBuffer<> *pCVar8;
  CClassicArchive *pCVar9;
  ulong uVar10;
  CPlugShader *pCVar11;
  CPlugMaterial *pCVar12;
  int *local_24;
  CPlugVisual *local_20;
  CMwNod *local_1c;
  CMwNod *local_18[3];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  pCVar2 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad5130;
  local_c = ExceptionList;
  if (param_2 < 0x904f011) {
    switch (param_2) {
    case 0x904f000:
    case 0x904f001:
    case 0x904f002:
    case 0x904f003:
    case 0x904f004:
    case 0x904f005:
    case 0x904f007:
    case 0x904f008:
    case 0x904f009:
    case 0x904f00a:
    case 0x904f00b:
    case 0x904f00f:
      return;
    case 0x904f006:
      uVar10 = 0;
      if (*(int *)(param_1 + 8) == 0) {
        this_00 = (CFastBuffer<> *)(this + 0x28);
        ExceptionList = &local_c;
        CFastBuffer<>::ArchiveFastBufferNod(this_00, param_1);
        uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)this_00);
        if (uVar3 == 0) {
          ExceptionList = local_c;
          return;
        }
        do {
          ppCVar4 = (CPlugTree **)CFastBuffer<>::operator[](
              (CFastBuffer<> *)this_00, uVar10);
          ConnectAsChild(this, *ppCVar4, 0);
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar3);
        ExceptionList = local_c;
        return;
      }
      if (*(int *)(this + 0x1c) == 0) {
        iVar5 = *(int *)(this + 0xa0);
        if (((iVar5 == 0) || ((*(byte *)(iVar5 + 0x14) & 1) != 0)) ||
            ((*(int *)(param_1 + 0x10) != 0 &&
              ((*(byte *)(iVar5 + 0x14) & 2) == 0)))) {
          ExceptionList = &local_c;
          CFastBuffer<>::ArchiveFastBufferNod((CFastBuffer<> *)(this + 0x28),
                                              param_1);
          ExceptionList = local_c;
          return;
        }
        ExceptionList = &local_c;
        CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)local_18);
        pCVar8 = (CFastBuffer<> *)(this + 0x28);
        local_4 = 1;
        uVar3 = CFastBuffer<>::GetCount(pCVar8);
        if (uVar3 != 0) {
          do {
            ppCVar4 = (CPlugTree **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)pCVar8, uVar10);
            iVar5 = GetIsRooted(*ppCVar4);
            if (iVar5 != 0) {
              ppCVar6 = (CDx9TextureKeeper **)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)pCVar8, uVar10);
              CFastBuffer<>::Add((CFastBuffer<> *)local_18, ppCVar6);
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 < uVar3);
        }
      } else {
        ExceptionList = &local_c;
        CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)local_18);
        local_4 = 0;
        pCVar8 = (CFastBuffer<> *)(this + 0x28);
        uVar10 = CFastBuffer<>::GetCount(pCVar8);
        uVar3 = 0;
        if (uVar10 != 0) {
          do {
            ppCVar4 = (CPlugTree **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)pCVar8, uVar3);
            iVar5 = GetIsRooted(*ppCVar4);
            if (iVar5 != 0) {
              ppCVar6 = (CDx9TextureKeeper **)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)pCVar8, uVar3);
              CFastBuffer<>::Add((CFastBuffer<> *)local_18, ppCVar6);
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < uVar10);
        }
      }
      CFastBuffer<>::ArchiveFastBufferNod((CFastBuffer<> *)local_18, pCVar2);
      CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)local_18);
      ExceptionList = local_c;
      return;
    case 0x904f00c:
      if (*(int *)(param_1 + 8) != 0) {
        return;
      }
      ExceptionList = &local_c;
      CClassicArchive::DoNatural(param_1, (ulong *)&param_1, 1, 0);
      if (param_1 == (CClassicArchive *)0x0) {
        ExceptionList = local_c;
        return;
      }
      CMwId::CMwId((CMwId *)&param_2);
      pCVar9 = (CClassicArchive *)0x0;
      local_4 = 2;
      if (param_1 != (CClassicArchive *)0x0) {
        do {
          CMwId::Archive((CMwId *)&param_2, pCVar2);
          pCVar9 = pCVar9 + 1;
        } while (pCVar9 < param_1);
      }
      local_4 = 0xffffffff;
      CScene2d::OnNodLoaded((CScene2d *)&param_2);
      ExceptionList = local_c;
      return;
    case 0x904f00d:
      ExceptionList = &local_c;
      CMwId::Archive((CMwId *)(this + 0x18), param_1);
      param_1 = *(CClassicArchive **)(this + 0x1c);
      (**(code **)(*(int *)pCVar2 + 4))(&param_1);
      if (param_1 == (CClassicArchive *)0x0) {
        ExceptionList = local_c;
        return;
      }
      CMwId::Archive((CMwId *)(this + 0x20), pCVar2);
      if (*(int *)(pCVar2 + 8) != 0) {
        ExceptionList = local_c;
        return;
      }
      CMwNod::MwAddRef((CMwNod *)param_1);
      *(CClassicArchive **)(this + 0x1c) = param_1;
      ExceptionList = local_c;
      return;
    case 0x904f00e:
      if (*(int *)(this + 0x1c) != 0) {
        return;
      }
      param_2 = *(ulong *)(this + 0x94);
      local_24 = *(int **)(this + 0x8c);
      local_20 = *(CPlugVisual **)(this + 0x90);
      ExceptionList = &local_c;
      (**(code **)(*(int *)param_1 + 4))(&local_20);
      (**(code **)(*(int *)pCVar2 + 4))(&param_1);
      (**(code **)(*(int *)pCVar2 + 4))(&stack0xffffffd4);
      if (*(int *)(pCVar2 + 8) != 0) {
        ExceptionList = local_c;
        return;
      }
      SetVisual(this, local_20, (CPlugShader *)param_2, (CPlugMaterial *)0x0,
                0);
      InternalLoadSetSurface(this, (CMwNod *)local_24);
      ExceptionList = local_c;
      return;
    default:
      ExceptionList = &local_c;
      CClassicArchive::DoData(param_1, &param_1, 4);
      *(uint *)(this + 0x9c) = (uint)param_1 & 0x1ffff;
      if (((uint)param_1 & 4) != 0) {
        GmIso4::ArchiveGmIso4((GmIso4 *)(this + 0x5c), pCVar2);
      }
      if (*(int *)(pCVar2 + 8) != 0) {
        ExceptionList = local_c;
        return;
      }
      *(uint *)(this + 0x9c) =
          (-(*(uint *)(this + 0x9c) >> 0xe) - 1 & 1) << 0xe |
          *(uint *)(this + 0x9c) & 0xffffbfff | 0x2000 | 0x8800;
      ExceptionList = local_c;
      return;
    case 0xbad1abe1:
      goto switchD_0084e1a4_caseD_10;
    }
  }
  if (0x904f018 < param_2) {
    if (0x9050000 < param_2) {
      if (param_2 < 0x9050004) {
        if (param_2 == 0x9050003) {
          param_2 = *(ulong *)(this + 0x8c);
          ExceptionList = &local_c;
          (**(code **)(*(int *)param_1 + 4))(
              &param_2, ___security_cookie ^ (uint)&stack0xffffffcc);
          if (*(int *)(pCVar2 + 8) != 0) {
            ExceptionList = local_c;
            return;
          }
          InternalLoadSetSurface(this, (CMwNod *)param_2);
          ExceptionList = local_c;
          return;
        }
        if (param_2 == 0x9050001) {
          ExceptionList = &local_c;
          CClassicArchive::DoBool(param_1, (int *)&param_1, 1);
          if (param_1 != (CClassicArchive *)0x0) {
            GmIso4::ArchiveGmIso4((GmIso4 *)(this + 0x5c), pCVar2);
          }
          (**(code **)(*(int *)pCVar2 + 4))(this + 0x24);
          (**(code **)(*(int *)pCVar2 + 4))(this + 0x14);
          *(uint *)(this + 0x9c) =
              *(uint *)(this + 0x9c) ^
              ((uint)(param_1 != (CClassicArchive *)0x0) * 4 ^
               *(uint *)(this + 0x9c)) &
                  4;
          ExceptionList = local_c;
          return;
        }
        if (param_2 == 0x9050002) {
          ExceptionList = &local_c;
          CClassicArchive::DoBool(param_1, (int *)&param_1, 1);
          if (param_1 != (CClassicArchive *)0x0) {
            GmIso4::ArchiveGmIso4((GmIso4 *)(this + 0x5c), pCVar2);
          }
          *(uint *)(this + 0x9c) =
              *(uint *)(this + 0x9c) ^
              ((uint)(param_1 != (CClassicArchive *)0x0) * 4 ^
               *(uint *)(this + 0x9c)) &
                  4;
          ExceptionList = local_c;
          return;
        }
      } else if (param_2 == 0xffffffff) {
        return;
      }
    switchD_0084e1a4_caseD_10:
      ExceptionList = &local_c;
      CMwNod::Chunk((CMwNod *)this, param_1, param_2);
      ExceptionList = local_c;
      return;
    }
    if (param_2 == 0x9050000) {
      param_2 = *(ulong *)(this + 0x90);
      ExceptionList = &local_c;
      (**(code **)(*(int *)param_1 + 4))(&param_2);
      SetVisual(this, (CPlugVisual *)param_2, (CPlugShader *)0x0,
                (CPlugMaterial *)0x0, 0);
      ExceptionList = local_c;
      return;
    }
    if (param_2 == 0x904f019) {
      puVar1 = (uint *)(this + 0x9c);
      ExceptionList = &local_c;
      CClassicArchive::DoData(param_1, puVar1, 4);
      if ((*(byte *)puVar1 & 4) != 0) {
        GmIso4::ArchiveGmIso4((GmIso4 *)(this + 0x5c), pCVar2);
      }
      if (*(int *)(pCVar2 + 8) != 0) {
        ExceptionList = local_c;
        return;
      }
      *puVar1 = *puVar1 | 0x2800;
    } else {
      if (param_2 != 0x904f01a)
        goto switchD_0084e1a4_caseD_10;
      puVar1 = (uint *)(this + 0x9c);
      ExceptionList = &local_c;
      CClassicArchive::DoData(param_1, puVar1, 4);
      if ((*(byte *)puVar1 & 4) != 0) {
        GmIso4::ArchiveGmIso4((GmIso4 *)(this + 0x5c), pCVar2);
      }
      if (*(int *)(pCVar2 + 8) != 0) {
        ExceptionList = local_c;
        return;
      }
      *puVar1 = *puVar1 | 0x2000;
    }
    if (*(int *)(pCVar2 + 0x10) == 0) {
      ExceptionList = local_c;
      return;
    }
    *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x8000;
    ExceptionList = local_c;
    return;
  }
  if (param_2 == 0x904f018) {
    ExceptionList = &local_c;
    CClassicArchive::DoData(param_1, local_18, 8);
    *(uint *)(this + 0x9c) = (uint)local_18[0] & 0x1ffff;
  LAB_0084e563:
    if (((uint)local_18[0] & 4) != 0) {
      GmIso4::ArchiveGmIso4((GmIso4 *)(this + 0x5c), pCVar2);
    }
    if (*(int *)(pCVar2 + 8) != 0) {
      ExceptionList = local_c;
      return;
    }
    *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x2800;
    uVar7 = *(uint *)(this + 0x9c);
  LAB_0084e524:
    if (*(int *)(pCVar2 + 0x10) != 0) {
      *(uint *)(this + 0x9c) = uVar7 | 0x8000;
    }
  } else {
    switch (param_2) {
    case 0x904f011:
      iVar5 = *(int *)param_1;
      if (*(int *)(param_1 + 8) == 0) {
        param_1 = (CClassicArchive *)0x0;
        ExceptionList = &local_c;
        (**(code **)(iVar5 + 4))(&param_1);
        if (*(int *)(pCVar2 + 8) == 0) {
          SetFuncTree(this, (CFuncTree *)param_1);
        }
      } else {
        ExceptionList = &local_c;
        (**(code **)(iVar5 + 4))(this + 0xa8);
      }
      break;
    case 0x904f012:
      if (*(int *)(this + 0x1c) == 0) {
        local_24 = *(int **)(this + 0x90);
        local_20 = *(CPlugVisual **)(this + 0x94);
        local_1c = *(CMwNod **)(this + 0x8c);
        param_2 = *(ulong *)(this + 0xa0);
        ExceptionList = &local_c;
        if ((*(int *)(param_1 + 0x10) != 0) &&
            (((int *)param_2 == (int *)0x0 ||
              (iVar5 = (**(code **)(*(int *)param_2 + 0x10))(0x903f000),
               iVar5 == 0)))) {
          param_2 = 0;
        }
        (**(code **)(*(int *)pCVar2 + 4))(&local_24);
        (**(code **)(*(int *)pCVar2 + 4))(&local_24);
        (**(code **)(*(int *)pCVar2 + 4))(&local_24);
        (**(code **)(*(int *)pCVar2 + 4))(&local_4);
        if (*(int *)(pCVar2 + 8) == 0) {
          SetVisual(this, (CPlugVisual *)local_24, (CPlugShader *)local_20,
                    (CPlugMaterial *)0x0, 0);
          InternalLoadSetSurface(this, local_1c);
          SetGenerator(this, (CPlugTreeGenerator *)param_2, 0);
        }
      }
      break;
    case 0x904f013:
      ExceptionList = &local_c;
      CClassicArchive::DoData(param_1, &param_1, 4);
      *(uint *)(this + 0x9c) = (uint)param_1 & 0x1ffff;
      if (((uint)param_1 & 4) != 0) {
        GmIso4::ArchiveGmIso4((GmIso4 *)(this + 0x5c), pCVar2);
      }
      if (*(int *)(pCVar2 + 8) != 0) {
        ExceptionList = local_c;
        return;
      }
      uVar7 = *(uint *)(this + 0x9c) | 0x2000;
      uVar7 =
          ((-1 - ((*(uint *)(this + 0x9c) & 0x4000) >> 0xe)) * 0x4000 ^ uVar7) &
                  0x4000 ^
              uVar7 |
          0x800;
      *(uint *)(this + 0x9c) = uVar7;
      goto LAB_0084e524;
    case 0x904f014:
      if (*(int *)(this + 0x1c) == 0) {
        param_2 = *(ulong *)(this + 0x90);
        local_20 = *(CPlugVisual **)(this + 0x94);
        local_1c = *(CMwNod **)(this + 0x98);
        local_18[0] = *(CMwNod **)(this + 0x8c);
        local_24 = *(int **)(this + 0xa0);
        ExceptionList = &local_c;
        if ((*(int *)(param_1 + 0x10) != 0) &&
            ((local_24 == (int *)0x0 ||
              (iVar5 = (**(code **)(*local_24 + 0x10))(0x903f000),
               iVar5 == 0)))) {
          local_24 = (int *)0x0;
        }
        (**(code **)(*(int *)pCVar2 + 4))(&param_2);
        (**(code **)(*(int *)pCVar2 + 4))(&local_24);
        (**(code **)(*(int *)pCVar2 + 4))(&local_24);
        (**(code **)(*(int *)pCVar2 + 4))(&local_24);
        (**(code **)(*(int *)pCVar2 + 4))(&stack0xffffffcc);
        if (*(int *)(pCVar2 + 8) == 0) {
          if (local_1c == (CMwNod *)0x0) {
            pCVar12 = (CPlugMaterial *)0x0;
            pCVar11 = (CPlugShader *)local_20;
          } else {
            pCVar11 = (CPlugShader *)0x0;
            pCVar12 = (CPlugMaterial *)local_1c;
          }
          SetVisual(this, (CPlugVisual *)param_2, pCVar11, pCVar12, 0);
          InternalLoadSetSurface(this, local_18[0]);
          SetGenerator(this, (CPlugTreeGenerator *)local_24, 0);
        }
      }
      break;
    case 0x904f015:
      ExceptionList = &local_c;
      CClassicArchive::DoData(param_1, &param_1, 4);
      *(uint *)(this + 0x9c) = (uint)param_1 & 0x1ffff;
      local_18[0] = (CMwNod *)param_1;
      goto LAB_0084e563;
    case 0x904f016:
      if (*(int *)(this + 0x1c) != 0) {
        return;
      }
      local_18[0] = *(CMwNod **)(this + 0x8c);
      local_24 = *(int **)(this + 0x90);
      local_20 = *(CPlugVisual **)(this + 0xa0);
      param_2 = *(ulong *)(this + 0x94);
      if (*(ulong *)(this + 0x98) != 0) {
        param_2 = *(ulong *)(this + 0x98);
      }
      if ((*(int *)(param_1 + 0x10) == 0) ||
          ((local_20 != (CPlugVisual *)0x0 &&
            (((byte)((CPlugTreeGenerator *)local_20)[0x14] & 2) != 0)))) {
        if ((local_20 != (CPlugVisual *)0x0) &&
            (((byte)((CPlugTreeGenerator *)local_20)[0x14] & 1) == 0)) {
          local_24 = (int *)0x0;
        }
      } else {
        local_20 = (CPlugVisual *)0x0;
      }
      ExceptionList = &local_c;
      (**(code **)(*(int *)param_1 + 4))(&local_24);
      (**(code **)(*(int *)pCVar2 + 4))(&param_1);
      (**(code **)(*(int *)pCVar2 + 4))(&local_20);
      (**(code **)(*(int *)pCVar2 + 4))(&stack0xffffffd4);
      if (*(int *)(pCVar2 + 8) != 0) {
        ExceptionList = local_c;
        return;
      }
      if (param_2 == 0) {
        pCVar12 = (CPlugMaterial *)0x0;
      LAB_0084e874:
        pCVar11 = (CPlugShader *)0x0;
      } else {
        iVar5 = (**(code **)(*(int *)param_2 + 0x10))(0x9079000);
        pCVar12 = (CPlugMaterial *)param_2;
        if (iVar5 != 0)
          goto LAB_0084e874;
        pCVar12 = (CPlugMaterial *)0x0;
        pCVar11 = (CPlugShader *)param_2;
      }
      SetVisual(this, (CPlugVisual *)local_24, pCVar11, pCVar12, 0);
      InternalLoadSetSurface(this, local_18[0]);
      SetGenerator(this, (CPlugTreeGenerator *)local_20, 0);
      break;
    case 0x904f017:
      param_2 = 0;
      local_4 = 3;
      ExceptionList = &local_c;
      CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)&param_2);
      local_4 = 0xffffffff;
      if (param_2 != 0) {
        CMwNod::MwRelease((CMwNod *)param_2);
      }
      break;
    default:
      goto switchD_0084e1a4_caseD_10;
    }
  }
  ExceptionList = local_c;
  return;
}

/* protected: void __thiscall CPlugTree::ConnectAsChild(class CPlugTree *,int)
 */

void __thiscall CPlugTree::ConnectAsChild(CPlugTree *this, CPlugTree *param_1,
                                          int param_2)

{
  *(CPlugTree **)(param_1 + 0x24) = this;
  if ((param_2 != 0) && (*(CPlugSolid **)(this + 0x14) != (CPlugSolid *)0x0)) {
    CPlugSolid::InternalConnectSubTree(*(CPlugSolid **)(this + 0x14), param_1);
  }
  return;
}

/* private: virtual void __thiscall CPlugTree::CopyFrom(class CMwNod *) */

void __thiscall CPlugTree::CopyFrom(CPlugTree *this, CMwNod *param_1)

{
  (**(code **)(*(int *)this + 0xb0))(param_1, 1);
  return;
}

/* public: virtual void __thiscall CPlugTree::CopyFromModel(class CPlugTree
 * const *,int) */

void __thiscall CPlugTree::CopyFromModel(CPlugTree *this, CPlugTree *param_1,
                                         int param_2)

{
  CFastBuffer<> *this_00;
  void *this_01;
  uint uVar1;
  CFastBuffer<> *this_02;
  int *piVar2;
  CPlugMaterial *pCVar3;
  CPlugVisual *pCVar4;
  CPlugSurface *this_03;
  ulong uVar5;
  void **ppvVar6;
  CMwNod *pCVar7;
  CMwNod **ppCVar8;
  CFuncTree *pCVar9;
  int iVar10;
  CPlugSurface *pCVar11;
  CFastBufferRef<> *this_04;
  ulong uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  CPlugShader *pCVar15;
  CPlugSurface *local_1c;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad508b;
  local_c = ExceptionList;
  uVar1 = ___security_cookie ^ (uint)&stack0xffffffd4;
  ExceptionList = &local_c;
  if (param_1 != (CPlugTree *)0x0) {
    if (*(int *)(param_1 + 0xa4) != 0) {
      this_00 = *(CFastBuffer<> **)(this + 0xa4);
      if (this_00 != (CFastBuffer<> *)0x0) {
        CFastBuffer<>::~CFastBuffer<>(this_00);
        operator_delete(this_00);
      }
      this_02 = (CFastBuffer<> *)operator_new(0xc);
      if (this_02 == (CFastBuffer<> *)0x0) {
        this_02 = (CFastBuffer<> *)0x0;
      } else {
        CFastBuffer<>::CFastBuffer<>(this_02);
      }
      *(CFastBuffer<> **)(this + 0xa4) = this_02;
      CFastBuffer<>::CopyFromFastBuffer((CFastBuffer<> *)this_02,
                                        *(CFastBuffer<> **)(param_1 + 0xa4));
    }
    if (*(int **)(this + 0xa0) != (int *)0x0) {
      (**(code **)(**(int **)(this + 0xa0) + 0x7c))(this, uVar1);
    }
    piVar2 = (int *)FUN_00848b60(*(void **)(param_1 + 0xa0), (CMwNod *)this);
    if (piVar2 == (int *)0x0) {
      this_01 = *(void **)(param_1 + 0x90);
      iVar10 = 0;
      if (*(void **)(param_1 + 0x98) == (void *)0x0) {
        pCVar3 = (CPlugMaterial *)0x0;
        pCVar15 = (CPlugShader *)FUN_00848b60(*(void **)(param_1 + 0x94),
                                              (CMwNod *)this);
      } else {
        pCVar3 = (CPlugMaterial *)FUN_00848b60(*(void **)(param_1 + 0x98),
                                               (CMwNod *)this);
        pCVar15 = (CPlugShader *)0x0;
      }
      pCVar4 = (CPlugVisual *)FUN_00848b60(this_01, (CMwNod *)this);
      SetVisual(this, pCVar4, pCVar15, pCVar3, iVar10);
      iVar10 = *(int *)(param_1 + 0x8c);
      pCVar11 = (CPlugSurface *)0x0;
      local_1c = (CPlugSurface *)0x0;
      if (iVar10 != 0) {
        this_03 = (CPlugSurface *)operator_new(0x24);
        local_4 = 0;
        if (this_03 != (CPlugSurface *)0x0) {
          pCVar11 = (CPlugSurface *)CPlugSurface::CPlugSurface(this_03);
        }
        pCVar7 = *(CMwNod **)(iVar10 + 0x14);
        local_4 = 0xffffffff;
        if (pCVar7 != *(CMwNod **)(pCVar11 + 0x14)) {
          if (pCVar7 != (CMwNod *)0x0) {
            CMwNod::MwAddRef(pCVar7);
          }
          if (*(CMwNod **)(pCVar11 + 0x14) != (CMwNod *)0x0) {
            CMwNod::MwRelease(*(CMwNod **)(pCVar11 + 0x14));
          }
          *(CMwNod **)(pCVar11 + 0x14) = pCVar7;
        }
        this_04 = (CFastBufferRef<> *)(pCVar11 + 0x18);
        uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)(iVar10 + 0x18));
        CFastBufferRef<>::AllocSetCount(this_04, uVar5);
        uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)this_04);
        uVar12 = 0;
        local_1c = pCVar11;
        if (uVar5 != 0) {
          do {
            ppvVar6 = (void **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(CFastBuffer<> *)(iVar10 + 0x18), uVar12);
            pCVar7 = (CMwNod *)FUN_00848b60(*ppvVar6, (CMwNod *)this);
            ppCVar8 = (CMwNod **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)this_04, uVar12);
            if (pCVar7 != *ppCVar8) {
              if (pCVar7 != (CMwNod *)0x0) {
                CMwNod::MwAddRef(pCVar7);
              }
              if (*ppCVar8 != (CMwNod *)0x0) {
                CMwNod::MwRelease(*ppCVar8);
              }
              *ppCVar8 = pCVar7;
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < uVar5);
        }
      }
      SetSurface(this, local_1c);
      SetGenerator(this, (CPlugTreeGenerator *)0x0, 1);
    } else {
      (**(code **)(*piVar2 + 0x80))(param_1, this);
    }
    pCVar9 =
        (CFuncTree *)FUN_00848b60(*(void **)(param_1 + 0xa8), (CMwNod *)this);
    SetFuncTree(this, pCVar9);
    *(uint *)(this + 0x9c) =
        *(uint *)(this + 0x9c) ^
        (*(uint *)(param_1 + 0x9c) ^ *(uint *)(this + 0x9c)) & 0x10;
    uVar1 = (*(uint *)(param_1 + 0x9c) ^ *(uint *)(this + 0x9c)) & 0x20 ^
            *(uint *)(this + 0x9c);
    *(uint *)(this + 0x9c) = uVar1;
    uVar1 = (*(uint *)(param_1 + 0x9c) ^ uVar1) & 1 ^ uVar1;
    *(uint *)(this + 0x9c) = uVar1;
    uVar1 = (*(uint *)(param_1 + 0x9c) ^ uVar1) & 0x4000 ^ uVar1;
    *(uint *)(this + 0x9c) = uVar1;
    uVar1 = (*(uint *)(param_1 + 0x9c) ^ uVar1) & 0x8000 ^ uVar1;
    *(uint *)(this + 0x9c) = uVar1;
    if (param_2 != 0) {
      uVar1 = uVar1 | 0x10000;
      *(uint *)(this + 0x9c) = uVar1;
      uVar1 = (*(uint *)(param_1 + 0x9c) ^ uVar1) & 4 ^ uVar1;
      *(uint *)(this + 0x9c) = uVar1;
      puVar13 = (undefined4 *)(param_1 + 0x5c);
      puVar14 = (undefined4 *)(this + 0x5c);
      for (iVar10 = 0xc; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar14 = *puVar13;
        puVar13 = puVar13 + 1;
        puVar14 = puVar14 + 1;
      }
      *(uint *)(this + 0x9c) =
          *(uint *)(this + 0x9c) ^ (*(uint *)(param_1 + 0x9c) ^ uVar1) & 8;
      uVar1 = (*(uint *)(param_1 + 0x9c) ^ *(uint *)(this + 0x9c)) & 0x80 ^
              *(uint *)(this + 0x9c);
      *(uint *)(this + 0x9c) = uVar1;
      uVar1 = (*(uint *)(param_1 + 0x9c) ^ uVar1) & 0x40 ^ uVar1;
      *(uint *)(this + 0x9c) = uVar1;
      *(uint *)(this + 0x9c) =
          (*(uint *)(param_1 + 0x9c) ^ uVar1) & 0x1000 ^ uVar1;
    }
    (**(code **)(*(int *)this + 0xbc))(0);
  }
  ExceptionList = local_c;
  return;
}

/* public: __thiscall CPlugTree::CPlugTree(void) */

CPlugTree *__thiscall CPlugTree::CPlugTree(CPlugTree *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4ccd;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CPlug::CPlug((CPlug *)this);
  local_4 = 0;
  *(undefined ***)this = vftable;
  CMwId::CMwId((CMwId *)(this + 0x18));
  local_4._0_1_ = 1;
  CMwId::CMwId((CMwId *)(this + 0x20));
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x28));
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa8) = 0;
  local_4 = CONCAT31(local_4._1_3_, 9);
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  GmIso4::SetIdentity((GmIso4 *)(this + 0x5c));
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x40) = 0xbf800000;
  *(undefined4 *)(this + 0x44) = 0xbf800000;
  *(undefined4 *)(this + 0x48) = 0xbf800000;
  *(ulong *)(this + 0x4c) = s_VisionDataUnlinkValue;
  *(ulong *)(this + 0x50) = s_CollisionDataUnlinkValue;
  *(undefined4 *)(this + 0x9c) = 0;
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x1e80a;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  ExceptionList = local_c;
  return this;
}

/* public: class CPlugTree * __thiscall CPlugTree::CreateChildFromVisual(class
 * CPlugVisual *) */

CPlugTree *__thiscall CPlugTree::CreateChildFromVisual(CPlugTree *this,
                                                       CPlugVisual *param_1)

{
  uint uVar1;
  CPlugTree *this_00;
  CPlugTree *this_01;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4f1b;
  local_c = ExceptionList;
  uVar1 = ___security_cookie ^ (uint)&stack0xffffffe8;
  ExceptionList = &local_c;
  this_00 = (CPlugTree *)operator_new(0xac);
  local_4 = 0;
  if (this_00 == (CPlugTree *)0x0) {
    this_01 = (CPlugTree *)0x0;
  } else {
    this_01 = (CPlugTree *)CPlugTree(this_00);
  }
  local_4 = 0xffffffff;
  if (param_1 != (CPlugVisual *)0x0) {
    SetVisual(this_01, param_1, (CPlugShader *)0x0, (CPlugMaterial *)0x0, 0);
  }
  (**(code **)(*(int *)this + 0x88))(this_01, uVar1);
  ExceptionList = this_00;
  return this_01;
}

/* protected: class CPlugSurface * __thiscall
   CPlugTree::CreateGroupSurface(struct SPlugTreeOptimGroup *) */

CPlugSurface *__thiscall CPlugTree::CreateGroupSurface(
    CPlugTree *this, SPlugTreeOptimGroup *param_1)

{
  return *(CPlugSurface **)(param_1 + 0x10);
}

/* protected: class CPlugVisual * __thiscall CPlugTree::CreateGroupVisual(struct
 *SPlugTreeOptimGroup
 *) */

CPlugVisual *__thiscall CPlugTree::CreateGroupVisual(
    CPlugTree *this, SPlugTreeOptimGroup *param_1)

{
  short *psVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  ulong *puVar11;
  ulong *_Size;
  ulong uVar12;
  GxVertex *pGVar13;
  ushort *puVar14;
  int *piVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  CPlugVisualIndexedTriangles *this_00;
  int *piVar19;
  uint *puVar20;
  STexStageCat *_Dst;
  ulong uVar21;
  int iVar22;
  float *pfVar23;
  int iVar24;
  CFastBuffer<> *this_01;
  void *_Src;
  size_t _Size_00;
  ulong local_48;
  uint local_44;
  CPlugVisual *pCStack_3c;
  ulong local_38;
  uint local_34;
  int local_2c;
  float **local_28;
  CFastBuffer<> *local_24;
  uint uStack_14;
  void *pvStack_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4dc3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(param_1 + 0xc) == 0) {
    pCStack_3c = (CPlugVisual *)0x0;
  } else {
    this_01 = (CFastBuffer<> *)(param_1 + 0x3c);
    uVar12 = CFastBuffer<>::GetCount(this_01);
    pGVar13 = (GxVertex *)operator_new[](
        -(uint)((int)((ulonglong) * (uint *)(param_1 + 0x38) * 0x28 >> 0x20) !=
                0) |
        (uint)((ulonglong) * (uint *)(param_1 + 0x38) * 0x28));
    puVar14 = (ushort *)operator_new[](
        -(uint)((int)((ulonglong) * (uint *)(param_1 + 0x30) * 2 >> 0x20) !=
                0) |
        (uint)((ulonglong) * (uint *)(param_1 + 0x30) * 2));
    local_2c = 0;
    local_28 = (float **)0x0;
    local_48 = 0;
    local_38 = 0;
    local_44 = 0;
    local_24 = this_01;
    if (uVar12 != 0) {
      do {
        piVar15 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_01,
                                                   local_44);
        piVar19 = *(int **)(*piVar15 + 0x90);
        if (piVar19 != (int *)0x0) {
          if ((piVar19[7] & 0x100U) != 0) {
            local_2c = 1;
          }
          if ((char)piVar19[7] < '\0') {
            local_28 = (float **)0x1;
          }
          iVar16 = (**(code **)(*piVar19 + 0xb8))();
          (**(code **)(*piVar19 + 0xc0))(pGVar13 + local_48 * 0x28);
          if ((piVar15[1] != 0) && (iVar16 != 0)) {
            uVar21 = uVar12;
            pfVar23 = (float *)(pGVar13 + local_48 * 0x28 + 0x14);
            do {
              GmVec3::Mult((GmVec3 *)(pfVar23 + -5), (GmIso4 *)(piVar15 + 2));
              uVar21 = uVar21 - 1;
              local_24 = (CFastBuffer<> *)((float)piVar15[4] * *pfVar23 +
                                           pfVar23[-1] * (float)piVar15[3] +
                                           pfVar23[-2] * (float)piVar15[2]);
              fVar2 = (float)piVar15[6];
              fVar3 = (float)piVar15[5];
              fVar4 = pfVar23[-2];
              fVar5 = (float)piVar15[7];
              fVar6 = pfVar23[-1];
              fVar7 = (float)piVar15[9];
              fVar8 = pfVar23[-2];
              fVar9 = (float)piVar15[8];
              fVar10 = (float)piVar15[10];
              pfVar23[-2] = (float)local_24;
              pfVar23[-1] =
                  *pfVar23 * fVar5 + fVar3 * fVar4 + pfVar23[-1] * fVar2;
              *pfVar23 = fVar10 * *pfVar23 + fVar8 * fVar9 + fVar6 * fVar7;
              pfVar23 = pfVar23 + 10;
            } while (uVar21 != 0);
          }
          uVar17 = (**(code **)(*piVar19 + 0xcc))(0);
          iVar22 = iVar16 + uVar12 * 2;
          (**(code **)(*piVar19 + 0xd0))(iVar22);
          uVar18 = 0;
          if (uVar17 != 0) {
            do {
              psVar1 = (short *)(iVar22 + uVar18 * 2);
              *psVar1 = *psVar1 + (short)local_48;
              uVar18 = uVar18 + 1;
            } while (uVar18 < uVar17);
          }
          local_48 = local_48 + iVar16;
          local_38 = local_38 + uVar17;
          this_01 = local_24;
        }
        local_44 = local_44 + 1;
      } while (local_44 < uVar12);
    }
    this_00 = (CPlugVisualIndexedTriangles *)operator_new(0x9c);
    uStack_4 = 0;
    if (this_00 == (CPlugVisualIndexedTriangles *)0x0) {
      pCStack_3c = (CPlugVisual *)0x0;
    } else {
      pCStack_3c = (CPlugVisual *)
          CPlugVisualIndexedTriangles::CPlugVisualIndexedTriangles(this_00);
    }
    uStack_4 = 0xffffffff;
    CPlugVisualIndexed::SetVerticesAndIndices(
        (CPlugVisualIndexed *)pCStack_3c, local_48, pGVar13, local_38, puVar14);
    CPlugVisual::EnableVertexColor(pCStack_3c, local_2c);
    CPlugVisual::EnableVertexNormal(pCStack_3c, (int)local_28);
    uVar17 = *(uint *)(*(int *)(param_1 + 0xc) + 0x20) & 0xf;
    local_34 = 0;
    if (uVar17 != 0) {
      do {
        uStack_14 = 0x100;
        pvStack_10 = (void *)0x0;
        uStack_4 = 1;
        piVar19 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_01, 0);
        puVar20 = (uint *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(*(int *)(*piVar19 + 0x90) + 0x5c), local_34);
        uStack_14 = *puVar20 & 0xff ^ 0x100;
        GxTexCoordSet::Alloc((GxTexCoordSet *)&uStack_14,
                             *(ulong *)(param_1 + 0x34));
        local_38 = 0;
        local_44 = 0;
        if (uVar12 != 0) {
          do {
            piVar19 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_01,
                                                       local_44);
            piVar19 = *(int **)(*piVar19 + 0x90);
            if (piVar19 != (int *)0x0) {
              puVar20 = (uint *)CFastBuffer<>::operator[](
                  (CFastBuffer<> *)(piVar19 + 0x17), local_34);
              iVar16 = (**(code **)(*piVar19 + 0xbc))();
              uVar18 = uStack_14 & 0xff;
              if (uVar18 == (*puVar20 & 0xff)) {
                _memcpy(
                    (void *)((int)(&GxTexCoordSet::s_ByteSizeByKinds)[uVar18] *
                                 local_38 +
                             (int)pvStack_10),
                    (void *)puVar20[1],
                    (int)(&GxTexCoordSet::s_ByteSizeByKinds)[uVar18] * iVar16);
              } else {
                puVar11 = (&GxTexCoordSet::s_ByteSizeByKinds)[uVar18];
                _Size = (&GxTexCoordSet::s_ByteSizeByKinds)[*puVar20 & 0xff];
                local_28 = &GxTexCoordSet::s_DefaultZW_11;
                if (_Size == (ulong *)0x1) {
                  local_28 = (float **)&DAT_00c40e90;
                }
                if (iVar16 != 0) {
                  iVar22 = 0;
                  iVar24 = (int)puVar11 * local_38;
                  local_2c = iVar16;
                  do {
                    _memcpy((void *)(iVar24 + (int)pvStack_10),
                            (void *)(puVar20[1] + iVar22), (size_t)_Size);
                    _memcpy((void *)((int)_Size + iVar24 + (int)pvStack_10),
                            local_28, (int)puVar11 - (int)_Size);
                    iVar24 = iVar24 + (int)puVar11;
                    iVar22 = iVar22 + (int)_Size;
                    local_2c = local_2c + -1;
                  } while (local_2c != 0);
                }
              }
              local_38 = local_38 + iVar16;
              this_01 = local_24;
            }
            local_44 = local_44 + 1;
          } while (local_44 < uVar12);
        }
        CPlugVisual::AddTexCoordSet(pCStack_3c, (GxTexCoordSet *)&uStack_14);
        uStack_4 = 0xffffffff;
        if ((uStack_14 & 0x100) != 0) {
          operator_delete[](pvStack_10);
        }
        local_34 = local_34 + 1;
      } while (local_34 < uVar17);
    }
    if ((*(uint *)(*(int *)(param_1 + 0xc) + 0x24) & 0x8000000) != 0) {
      CFastArray<>::SetCount((CFastArray<> *)(pCStack_3c + 0x84),
                             *(ulong *)(param_1 + 0x38));
      uVar21 = 0;
      local_48 = 0;
      if (uVar12 != 0) {
        do {
          piVar19 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_01,
                                                     uVar21);
          piVar19 = *(int **)(*piVar19 + 0x90);
          if (piVar19 != (int *)0x0) {
            iVar16 = (**(code **)(*piVar19 + 0xb8))();
            if (piVar19[0x22] == 0) {
              (**(code **)(*piVar19 + 0x138))(0, 0, 1, 0);
            }
            _Src = (void *)piVar19[0x22];
            _Size_00 = iVar16 * 0xc;
            _Dst = CFastBuffer<>::operator[](
                (CFastBuffer<> *)(pCStack_3c + 0x84), local_48);
            _memcpy(_Dst, _Src, _Size_00);
            local_48 = local_48 + iVar16;
          }
          uVar21 = uVar21 + 1;
        } while (uVar21 < uVar12);
      }
    }
  }
  ExceptionList = local_c;
  return pCStack_3c;
}

/* public: class CPlugTree * __thiscall
 * CPlugTree::CreateModelInstance(void)const  */

CPlugTree *__thiscall CPlugTree::CreateModelInstance(CPlugTree *this)

{
  CMwNod *this_00;
  int iVar1;
  int *piVar2;
  CSystemFidParameters *pCVar3;
  CSystemFidParameters *pCVar4;
  undefined *puVar5;
  CPlugTree *pCStack_5c;
  undefined4 uStack_58;
  uint uStack_54;
  CSystemFidParameters aCStack_44[36];
  void *pvStack_20;
  undefined4 uStack_18;
  undefined4 local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4c30;
  local_c = ExceptionList;
  uStack_54 = ___security_cookie ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_c;
  uStack_58 = 0x848aae;
  iVar1 = (**(code **)(*(int *)this + 8))();
  uStack_58 = 0x848ab3;
  piVar2 = (int *)(**(code **)(iVar1 + 0x1c))();
  this_00 = *(CMwNod **)(this + 0x14);
  piVar2[7] = (int)this_00;
  uStack_58 = 0x848ac0;
  CMwNod::MwAddRef(this_00);
  if ((*(int *)(this + 0x24) == 0) &&
      ((*(uint *)(this + 0x18) & 0xc0000000) != 0x40000000)) {
    piVar2[8] = -1;
  } else {
    piVar2[8] = *(int *)(this + 0x18);
  }
  uStack_58 = 1;
  pCStack_5c = this;
  (**(code **)(*piVar2 + 0xb0))();
  CSystemFidParameters::CSystemFidParameters(aCStack_44);
  local_c = (void *)0x0;
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)&stack0xffffffb0);
  iVar1 = *piVar2;
  puVar5 = &stack0xffffffb0;
  pCVar4 = aCStack_44;
  local_c = (void *)CONCAT31(local_c._1_3_, 1);
  pCVar3 = CSystemFidParameters::GetCurrentParameters();
  (**(code **)(iVar1 + 0x54))(pCVar3, pCVar4, puVar5);
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)&pCStack_5c);
  uStack_18 = 0xffffffff;
  CSystemFidParameters::~CSystemFidParameters(
      (CSystemFidParameters *)&stack0xffffffb0);
  ExceptionList = pvStack_20;
  return (CPlugTree *)piVar2;
}

/* protected: void __thiscall CPlugTree::DeconnectAsChild(class CPlugTree *) */

void __thiscall CPlugTree::DeconnectAsChild(CPlugTree *this, CPlugTree *param_1)

{
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    CPlugSolid::InternalDisconnectSubTree(*(CPlugSolid **)(this + 0x14),
                                          param_1);
    return;
  }
  return;
}

/* public: virtual void __thiscall CPlugTree::DeleteAllChilds(void) */

void __thiscall CPlugTree::DeleteAllChilds(CPlugTree *this)

{
  int iVar1;

  for (iVar1 = (**(code **)(*(int *)this + 0x7c))(); iVar1 != 0;
       iVar1 = iVar1 + -1) {
    (**(code **)(*(int *)this + 0x9c))(0);
  }
  return;
}

/* public: virtual void __thiscall CPlugTree::DeleteAllVolatileChilds(void) */

void __thiscall CPlugTree::DeleteAllVolatileChilds(CPlugTree *this)

{
  uint uVar1;
  CPlugTree *this_00;
  int iVar2;
  uint uVar3;

  uVar1 = (**(code **)(*(int *)this + 0x7c))();
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))(uVar3);
      iVar2 = GetIsRooted(this_00);
      if (iVar2 == 0) {
        (**(code **)(*(int *)this + 0x9c))(uVar3);
        uVar3 = uVar3 - 1;
        uVar1 = uVar1 - 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* public: virtual void __thiscall CPlugTree::DeleteChild(unsigned long) */

void __thiscall CPlugTree::DeleteChild(CPlugTree *this, ulong param_1)

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

/* public: virtual void __thiscall CPlugTree::DeleteChildPtr(class CPlugTree *)
 */

void __thiscall CPlugTree::DeleteChildPtr(CPlugTree *this, CPlugTree *param_1)

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

/* public: virtual class CPlugTree * __thiscall CPlugTree::DetachChild(unsigned
 * long) */

CPlugTree *__thiscall CPlugTree::DetachChild(CPlugTree *this, ulong param_1)

{
  CPlugTree *pCVar1;
  CPlugTree **ppCVar2;

  ppCVar2 = (CPlugTree **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(this + 0x28), param_1);
  pCVar1 = *ppCVar2;
  CFastBuffer<>::ReplaceByLastAt(
      (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x28), param_1, 1);
  DeconnectAsChild(this, pCVar1);
  return pCVar1;
}

/* public: virtual class CPlugTree * __thiscall CPlugTree::DetachChildPtr(class
 * CPlugTree *) */

CPlugTree *__thiscall CPlugTree::DetachChildPtr(CPlugTree *this,
                                                CPlugTree *param_1)

{
  int iVar1;
  CPlugTree *pCVar2;

  iVar1 = CFastArray<>::Find((CFastArray<> *)(this + 0x28),
                             (CGameMenuFrame **)&param_1);
  if (iVar1 == -1) {
    return (CPlugTree *)0x0;
  }
  pCVar2 = (CPlugTree *)(**(code **)(*(int *)this + 0xa4))(iVar1);
  return pCVar2;
}

/* public: void __thiscall CPlugTree::DisconnectFromModel(int,unsigned long) */

void __thiscall CPlugTree::DisconnectFromModel(CPlugTree *this, int param_1,
                                               ulong param_2)

{
  uint uVar1;
  CPlugTree *this_00;
  int unaff_EBX;
  uint uVar2;
  int iVar3;
  ulong uVar4;

  (**(code **)(*(int *)this + 0xac))(param_1, param_2);
  uVar1 = (**(code **)(*(int *)this + 0x7c))();
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      iVar3 = unaff_EBX;
      uVar4 = param_2;
      this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))(uVar2);
      DisconnectFromModel(this_00, iVar3, uVar4);
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}

/* public: virtual void __thiscall
 * CPlugTree::DisconnectThisFromModel(int,unsigned long) */

void __thiscall CPlugTree::DisconnectThisFromModel(CPlugTree *this, int param_1,
                                                   ulong param_2)

{
  CPlugVisual *pCVar1;
  uint uVar2;
  ulong uVar3;
  CPlugMaterial *pCVar4;
  CPlugVisual *local_4;

  local_4 = (CPlugVisual *)this;
  if (*(CMwNod **)(this + 0x1c) == (CMwNod *)0x0) {
    if (param_1 == 0) {
      return;
    }
  } else {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1c));
  }
  uVar3 = param_2;
  param_1 = *(int *)(this + 0xa0);
  *(undefined4 *)(this + 0x1c) = 0;
  if (param_1 == 0) {
    pCVar1 = *(CPlugVisual **)(this + 0x90);
    if (pCVar1 != (CPlugVisual *)0x0) {
      uVar2 = param_2 & 2;
      param_2 = *(ulong *)(this + 0x94);
      pCVar4 = *(CPlugMaterial **)(this + 0x98);
      local_4 = pCVar1;
      if (uVar2 != 0) {
        CSystemArchiveNod::Duplicate((CMwNod **)&local_4, 0);
      }
      if (((uVar3 & 4) != 0) && (*(int *)(this + 0x94) != 0)) {
        CSystemArchiveNod::Duplicate((CMwNod **)&param_2, 0);
        pCVar4 = (CPlugMaterial *)0x0;
      }
      SetVisual(this, local_4, (CPlugShader *)param_2, pCVar4, 0);
    }
    if ((*(ulong *)(this + 0x8c) != 0) && ((uVar3 & 1) != 0)) {
      param_2 = *(ulong *)(this + 0x8c);
      CSystemArchiveNod::Duplicate((CMwNod **)&param_2, 0);
      SetSurface(this, (CPlugSurface *)param_2);
    }
  } else if ((param_2 & 0x10) != 0) {
    CSystemArchiveNod::Duplicate((CMwNod **)&param_1, 0);
    SetGenerator(this, (CPlugTreeGenerator *)param_1, 1);
  }
  if ((*(ulong *)(this + 0xa8) != 0) && ((uVar3 & 0x20) != 0)) {
    param_2 = *(ulong *)(this + 0xa8);
    CSystemArchiveNod::Duplicate((CMwNod **)&param_2, 0);
    SetFuncTree(this, (CFuncTree *)param_2);
  }
  (**(code **)(*(int *)this + 0xbc))(1);
  return;
}

/* public: class CPlugTree * __thiscall CPlugTree::DuplicateRecursive(void)const
 */

CPlugTree *__thiscall CPlugTree::DuplicateRecursive(CPlugTree *this)

{
  int *piVar1;

  piVar1 = (int *)(**(code **)(*(int *)this + 200))(DuplicateThis, 1, 0);
  (**(code **)(*piVar1 + 0x78))(0);
  (**(code **)(*piVar1 + 0xbc))(1);
  return (CPlugTree *)piVar1;
}

/* public: class CPlugTree * __thiscall CPlugTree::DuplicateThis(void)const  */

CPlugTree *__thiscall CPlugTree::DuplicateThis(CPlugTree *this)

{
  CPlugTree *this_00;
  int *this_01;
  CMwId *pCVar1;
  int iVar2;
  CSystemFidParameters *pCVar3;
  CSystemFidParameters *pCVar4;
  CFastBuffer<> *pCVar5;
  uint uStack_54;
  CFastBuffer<> aCStack_48[12];
  CSystemFidParameters aCStack_3c[36];
  void *pvStack_18;
  undefined4 uStack_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4d30;
  local_c = ExceptionList;
  uStack_54 = ___security_cookie ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_c;
  if (*(int *)(this + 0x1c) == 0) {
    iVar2 = (**(code **)(*(int *)this + 8))();
    this_01 = (int *)(**(code **)(iVar2 + 0x1c))();
    (**(code **)(*this_01 + 0xb0))(this, 1);
  } else {
    this_00 = GetModelTree(this);
    this_01 = (int *)CreateModelInstance(this_00);
  }
  pCVar1 = (CMwId *)(**(code **)(*(int *)this + 0x14))();
  InternalSetMwId((CPlugTree *)this_01, pCVar1);
  iVar2 = GetIsRooted(this);
  SetIsRooted((CPlugTree *)this_01, iVar2);
  CSystemFidParameters::CSystemFidParameters(aCStack_3c);
  uStack_4 = 0;
  CFastBuffer<>::CFastBuffer<>(aCStack_48);
  iVar2 = *this_01;
  pCVar5 = aCStack_48;
  pCVar4 = aCStack_3c;
  uStack_4 = CONCAT31(uStack_4._1_3_, 1);
  pCVar3 = CSystemFidParameters::GetCurrentParameters();
  (**(code **)(iVar2 + 0x54))(pCVar3, pCVar4, pCVar5);
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)&uStack_54);
  uStack_10 = 0xffffffff;
  CSystemFidParameters::~CSystemFidParameters(
      (CSystemFidParameters *)aCStack_48);
  ExceptionList = pvStack_18;
  return (CPlugTree *)this_01;
}

/* public: int __thiscall CPlugTree::FindTree(class CPlugTree const *)const  */

int __thiscall CPlugTree::FindTree(CPlugTree *this, CPlugTree *param_1)

{
  while (true) {
    if (param_1 == (CPlugTree *)0x0) {
      return 0;
    }
    if (param_1 == this)
      break;
    param_1 = *(CPlugTree **)(param_1 + 0x24);
  }
  return 1;
}

/* public: virtual void __thiscall CPlugTree::Generate(int) */

void __thiscall CPlugTree::Generate(CPlugTree *this, int param_1)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;

  if (((*(int *)(this + 0xa0) != 0) &&
       ((param_1 != 0 ||
         ((*(int *)(this + 0x90) == 0 &&
           (uVar1 = GetVolatileChildCount(this), uVar1 == 0)))))) ||
      ((*(int **)(this + 0xa0) != (int *)0x0 &&
        ((iVar2 = (**(code **)(**(int **)(this + 0xa0) + 0x10))(0x909a000),
          iVar2 != 0 && (uVar1 = GetRootedChildCount(this), uVar1 != 0)))))) {
    (**(code **)(**(int **)(this + 0xa0) + 0x78))(this);
    (**(code **)(*(int *)this + 0xbc))(1);
  }
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

/* public: virtual void __thiscall CPlugTree::GenerateOptimizedTree(class
   CPlugTree * &,struct SPlugTreeOptimCriteria const &) */

void __thiscall CPlugTree::GenerateOptimizedTree(
    CPlugTree *this, CPlugTree **param_1, SPlugTreeOptimCriteria *param_2)

{
  CPlugMaterial *pCVar1;
  byte bVar2;
  uint uVar3;
  ulong uVar4;
  SPlugTreeOptimGroup **ppSVar5;
  int *piVar6;
  CPlugTree *pCVar7;
  int iVar8;
  CPlugVisual *pCVar9;
  ulong uVar10;
  int **ppiVar11;
  SPlugTreeOptimCriteria *pSVar12;
  CFastBuffer<> *pCVar13;
  CFastBuffer<> local_4c[12];
  undefined4 local_40;
  GmIso4 local_3c[32];
  void *pvStack_1c;
  undefined uStack_10;
  void *local_c;
  int **ppiStack_8;
  SPlugTreeOptimCriteria *local_4;

  local_4 = (SPlugTreeOptimCriteria *)0xffffffff;
  ppiStack_8 = (int **)&LAB_00ad50c3;
  local_c = ExceptionList;
  uVar3 = ___security_cookie ^ (uint)&stack0xffffff9c;
  ExceptionList = &local_c;
  uVar10 = 0;
  local_40 = 0;
  GmIso4::SetIdentity(local_3c);
  CFastBuffer<>::CFastBuffer<>(local_4c);
  local_4 = (SPlugTreeOptimCriteria *)0x0;
  CFastBuffer<>::InitSize((CFastBuffer<> *)local_4c, 0x32);
  pCVar13 = local_4c;
  (**(code **)(*(int *)this + 0xdc))(pCVar13, param_2, &local_40, uVar3);
  uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)&stack0xffffffa8);
  if (uVar4 == 1) {
    pSVar12 = param_2;
    ppSVar5 = (SPlugTreeOptimGroup **)CFastBuffer<>::operator[](
        (CFastBuffer<> *)&stack0xffffffa8, 0);
    piVar6 = (int *)MakeGroupTree(this, *ppSVar5, pSVar12);
    *ppiStack_8 = piVar6;
    ppiVar11 = ppiStack_8;
  } else {
    pCVar7 = (CPlugTree *)operator_new(0xac);
    uStack_10 = 1;
    if (pCVar7 == (CPlugTree *)0x0) {
      piVar6 = (int *)0x0;
    } else {
      piVar6 = (int *)CPlugTree(pCVar7);
    }
    ppiVar11 = ppiStack_8;
    uStack_10 = 0;
    *ppiStack_8 = piVar6;
    SetIsRooted((CPlugTree *)piVar6, 1);
    if (uVar4 != 0) {
      do {
        ppSVar5 = (SPlugTreeOptimGroup **)CFastBuffer<>::operator[](
            (CFastBuffer<> *)&stack0xffffffa8, uVar10);
        pCVar7 = MakeGroupTree(this, *ppSVar5, param_2);
        (**(code **)(**ppiVar11 + 0x88))(pCVar7);
        piVar6 = *ppiVar11;
        if (((*(byte *)(piVar6 + 0x27) & 0x80) == 0) &&
            (((byte)pCVar7[0x9c] & 0x80) == 0)) {
          bVar2 = 0;
        } else {
          bVar2 = 1;
        }
        piVar6[0x27] = piVar6[0x27] ^ ((uint)bVar2 << 7 ^ piVar6[0x27]) & 0x80;
        piVar6 = *ppiVar11;
        if (((*(byte *)(piVar6 + 0x27) & 8) == 0) &&
            (((byte)pCVar7[0x9c] & 8) == 0)) {
          bVar2 = 0;
        } else {
          bVar2 = 1;
        }
        piVar6[0x27] = piVar6[0x27] ^ ((uint)bVar2 * 8 ^ piVar6[0x27]) & 8;
        piVar6 = *ppiVar11;
        if (((piVar6[0x27] & 0x4000U) == 0) &&
            ((*(uint *)(pCVar7 + 0x9c) & 0x4000) == 0)) {
          bVar2 = 0;
        } else {
          bVar2 = 1;
        }
        piVar6[0x27] =
            piVar6[0x27] ^ ((uint)bVar2 << 0xe ^ piVar6[0x27]) & 0x4000;
        piVar6 = *ppiVar11;
        if (((*(byte *)(piVar6 + 0x27) & 0x10) == 0) &&
            (((byte)pCVar7[0x9c] & 0x10) == 0)) {
          bVar2 = 0;
        } else {
          bVar2 = 1;
        }
        piVar6[0x27] = piVar6[0x27] ^ ((uint)bVar2 << 4 ^ piVar6[0x27]) & 0x10;
        piVar6 = *ppiVar11;
        if (((*(byte *)(piVar6 + 0x27) & 0x20) == 0) &&
            (((byte)pCVar7[0x9c] & 0x20) == 0)) {
          bVar2 = 0;
        } else {
          bVar2 = 1;
        }
        piVar6[0x27] = piVar6[0x27] ^ ((uint)bVar2 << 5 ^ piVar6[0x27]) & 0x20;
        piVar6 = *ppiVar11;
        if (((*(byte *)(piVar6 + 0x27) & 0x40) == 0) &&
            (((byte)pCVar7[0x9c] & 0x40) == 0)) {
          bVar2 = 0;
        } else {
          bVar2 = 1;
        }
        uVar10 = uVar10 + 1;
        piVar6[0x27] = piVar6[0x27] ^ ((uint)bVar2 << 6 ^ piVar6[0x27]) & 0x40;
        param_2 = local_4;
      } while (uVar10 < uVar4);
    }
  }
  CFastBuffer<>::DeleteAll((CFastBuffer<> *)&stack0xffffffa8);
  if ((*(int *)(param_2 + 0xc) != 0) || (*(int *)(param_2 + 0x10) != 0)) {
    ppiStack_8 = (int **)__InitClassInfo_CFuncShader((CMwClassInfo *)pCVar13);
  joined_r0x0084de0c:
    if (ppiStack_8 != (int **)0xffffffff) {
      pCVar7 = GetAllTreeNext((CPlugTree *)*ppiVar11, (ulong *)&ppiStack_8);
      piVar6 = *(int **)(pCVar7 + 0x90);
      if ((piVar6 != (int *)0x0) && (*(int *)(pCVar7 + 0x1c) == 0)) {
        if (*(int *)(local_4 + 0xc) != 0) {
          if (*(int *)(pCVar7 + 0x94) != 0) {
            CPlugVisual::UpdateVisualFromShaderRequirement(
                (CPlugVisual *)piVar6, (CPlugShader **)&stack0xffffffa0,
                (CPlugShader *)0x0);
          }
          (**(code **)(*piVar6 + 0xf8))(
              *(undefined4 *)(local_4 + 0x20), *(undefined4 *)(local_4 + 0x24),
              *(undefined4 *)(local_4 + 0x28), *(undefined4 *)(local_4 + 0x2c),
              *(undefined4 *)(local_4 + 0x30));
          iVar8 = (**(code **)(*piVar6 + 0x10))(0x906a000);
          if ((iVar8 != 0) && (uVar4 = CFastBuffer<>::GetCount(
                                   (CFastBuffer<> *)(piVar6[0x26] + 0x1c)),
                               uVar4 == 0)) {
            *(uint *)(pCVar7 + 0x9c) = *(uint *)(pCVar7 + 0x9c) & 0xfffffff7;
            goto joined_r0x0084de0c;
          }
        }
        if ((*(int *)(local_4 + 0x10) != 0) &&
            (pCVar9 = (CPlugVisual *)(**(code **)(*piVar6 + 0x88))(
                 *(undefined4 *)(local_4 + 0x14), 0x10),
             pCVar9 != (CPlugVisual *)0x0)) {
          pCVar1 = *(CPlugMaterial **)(pCVar7 + 0x98);
          SetVisual(pCVar7, pCVar9, *(CPlugShader **)(pCVar7 + 0x94),
                    (CPlugMaterial *)0x0, 0);
          if (pCVar1 != (CPlugMaterial *)0x0) {
            SetMaterial(pCVar7, pCVar1);
          }
        }
      }
      goto joined_r0x0084de0c;
    }
  }
  (**(code **)(**ppiVar11 + 0xbc))(1);
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)&stack0xffffffa4);
  ExceptionList = pvStack_1c;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: class CPlugTree * __thiscall CPlugTree::GetAllChildNext(unsigned long
 * &) */

CPlugTree *__thiscall CPlugTree::GetAllChildNext(CPlugTree *this,
                                                 ulong *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  CClassicBufferMemory *pCVar4;
  CClassicBufferMemory **ppCVar5;
  ulong uVar6;
  CPlugTree *pCStack_4;

  piVar2 = DAT_00d6e680;
  DAT_00d6e680 = (int *)0x0;
  pCStack_4 = this;
  iVar3 = (**(code **)(*piVar2 + 0x7c))();
  if (iVar3 == 0) {
    for (piVar1 = (int *)piVar2[9]; piVar1 != (int *)0x0;
         piVar1 = (int *)piVar1[9]) {
      pCVar4 = (CClassicBufferMemory *)(**(code **)(*piVar1 + 0x7c))();
      ppCVar5 = CFastBuffer<>::GetLastElem((CFastBuffer<> *)&DAT_00d6e674);
      if (*ppCVar5 + 1 < pCVar4) {
        *ppCVar5 = *ppCVar5 + 1;
        DAT_00d6e680 = (int *)(**(code **)(*piVar1 + 0x80))(*ppCVar5);
        break;
      }
      uVar6 = CFastBuffer<>::GetCount((CFastBuffer<> *)&DAT_00d6e674);
      if (uVar6 < 2)
        break;
      _DAT_00d6e674 = _DAT_00d6e674 + -1;
    }
  } else {
    pCStack_4 = (CPlugTree *)0x0;
    CFastBuffer<>::Add((CFastBuffer<> *)&DAT_00d6e674,
                       (CDx9TextureKeeper **)&pCStack_4);
    DAT_00d6e680 = (int *)(**(code **)(*piVar2 + 0x80))(0);
  }
  if (DAT_00d6e680 != (int *)0x0) {
    *param_1 = *param_1 + 1;
    return (CPlugTree *)piVar2;
  }
  _DataAllChildTravel = 0;
  *param_1 = 0xffffffff;
  return (CPlugTree *)piVar2;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: unsigned long __thiscall CPlugTree::GetAllChildStart(void) */

ulong __thiscall CPlugTree::GetAllChildStart(CPlugTree *this)

{
  int iVar1;
  CPlugTree *pCStack_4;

  pCStack_4 = this;
  CFastBuffer<>::Reset((CFastBuffer<> *)&DAT_00d6e674);
  iVar1 = (**(code **)(*(int *)this + 0x7c))();
  if (iVar1 != 0) {
    _DataAllChildTravel = 1;
    pCStack_4 = (CPlugTree *)0x0;
    CFastBuffer<>::Add((CFastBuffer<> *)&DAT_00d6e674,
                       (CDx9TextureKeeper **)&pCStack_4);
    DAT_00d6e680 = (**(code **)(*(int *)this + 0x80))(0);
    return 0;
  }
  _DataAllChildTravel = 0;
  DAT_00d6e680 = 0;
  return 0xffffffff;
}

/* public: class CPlugTree * __thiscall CPlugTree::GetAllTreeNext(unsigned long
 * &) */

CPlugTree *__thiscall CPlugTree::GetAllTreeNext(CPlugTree *this, ulong *param_1)

{
  ulong *puVar1;
  ulong uVar2;
  CPlugTree *pCVar3;

  puVar1 = param_1;
  if (*param_1 != 0) {
    param_1 = (ulong *)(*param_1 - 1);
    pCVar3 = GetAllChildNext(this, (ulong *)&param_1);
    if (param_1 == (ulong *)0xffffffff) {
      *puVar1 = 0xffffffff;
      return pCVar3;
    }
    *puVar1 = (int)param_1 + 1;
    return pCVar3;
  }
  uVar2 = GetAllChildStart(this);
  if (uVar2 == 0xffffffff) {
    *puVar1 = 0xffffffff;
    return this;
  }
  *puVar1 = uVar2 + 1;
  return this;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: class CPlugVisual * __thiscall CPlugTree::GetAllVisualNext(unsigned
 * long &) */

CPlugVisual *__thiscall CPlugTree::GetAllVisualNext(CPlugTree *this,
                                                    ulong *param_1)

{
  CPlugTree *pCVar1;
  int iVar2;
  ulong local_c;
  CPlugVisual *local_8;
  CGameMenuFrame *local_4;

  local_8 = *(CPlugVisual **)((int)DAT_00d6e68c + 0x90);
  CFastBuffer<>::Add((CFastBuffer<> *)&DAT_00d6e690,
                     (CDx9TextureKeeper **)&local_8);
  DAT_00d6e68c = (CPlugTree *)0x0;
  if (DAT_00d6e688 == 0xffffffff) {
    local_c = GetAllChildStart(this);
    do {
      pCVar1 = DAT_00d6e68c;
      if (local_c == 0xffffffff)
        goto LAB_0084a417;
      pCVar1 = GetAllChildNext(this, &local_c);
      local_4 = *(CGameMenuFrame **)(pCVar1 + 0x90);
    } while (
        (local_4 == (CGameMenuFrame *)0x0) ||
        (iVar2 = CFastArray<>::Find((CFastArray<> *)&DAT_00d6e690, &local_4),
         iVar2 != -1));
    DAT_00d6e688 = local_c;
  } else {
    do {
      pCVar1 = GetAllChildNext(this, &DAT_00d6e688);
      local_4 = *(CGameMenuFrame **)(pCVar1 + 0x90);
      if ((local_4 != (CGameMenuFrame *)0x0) &&
          (iVar2 = CFastArray<>::Find((CFastArray<> *)&DAT_00d6e690, &local_4),
           iVar2 == -1))
        break;
      pCVar1 = DAT_00d6e68c;
    } while (DAT_00d6e688 != 0xffffffff);
  }
LAB_0084a417:
  DAT_00d6e68c = pCVar1;
  if (DAT_00d6e68c == (CPlugTree *)0x0) {
    _DataAllVisualTravel = 0;
    *param_1 = 0xffffffff;
    return local_8;
  }
  *param_1 = *param_1 + 1;
  return local_8;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: unsigned long __thiscall CPlugTree::GetAllVisualStart(void) */

ulong __thiscall CPlugTree::GetAllVisualStart(CPlugTree *this)

{
  CPlugTree *pCVar1;
  CPlugTree *local_4;

  local_4 = this;
  CFastBuffer<>::Reset((CFastBuffer<> *)&DAT_00d6e690);
  if (*(int *)(this + 0x90) != 0) {
    DAT_00d6e68c = this;
    _DataAllVisualTravel = 1;
    DAT_00d6e688 = (CPlugTree *)0xffffffff;
    return 0;
  }
  local_4 = (CPlugTree *)GetAllChildStart(this);
  do {
    if (local_4 == (CPlugTree *)0xffffffff) {
      _DataAllVisualTravel = 0;
      return 0xffffffff;
    }
    pCVar1 = GetAllChildNext(this, (ulong *)&local_4);
  } while (*(int *)(pCVar1 + 0x90) == 0);
  DAT_00d6e68c = pCVar1;
  _DataAllVisualTravel = 1;
  DAT_00d6e688 = local_4;
  return 0;
}

/* public: virtual class CPlugTree * __thiscall CPlugTree::GetChild(unsigned
 * long)const  */

CPlugTree *__thiscall CPlugTree::GetChild(CPlugTree *this, ulong param_1)

{
  CPlugTree **ppCVar1;

  ppCVar1 = (CPlugTree **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(this + 0x28), param_1);
  return *ppCVar1;
}

/* public: virtual unsigned long __thiscall CPlugTree::GetChildCount(void)const
 */

ulong __thiscall CPlugTree::GetChildCount(CPlugTree *this)

{
  ulong uVar1;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x28));
  return uVar1;
}

/* public: class CPlugTree * __thiscall CPlugTree::GetChildFromId(class CMwId
 * const &)const  */

CPlugTree *__thiscall CPlugTree::GetChildFromId(CPlugTree *this, CMwId *param_1)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;

  uVar1 = (**(code **)(*(int *)this + 0x7c))();
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)(**(code **)(*(int *)this + 0x80))(uVar4);
      piVar3 = (int *)(**(code **)(*piVar2 + 0x14))();
      if ((piVar3 != (int *)0x0) && (*piVar3 == *(int *)param_1)) {
        return (CPlugTree *)piVar2;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return (CPlugTree *)0x0;
}

/* public: virtual unsigned long __thiscall CPlugTree::GetChildIndex(class
 * CPlugTree *) */

ulong __thiscall CPlugTree::GetChildIndex(CPlugTree *this, CPlugTree *param_1)

{
  ulong uVar1;
  CPlugTree **ppCVar2;
  ulong uVar3;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x28));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      ppCVar2 = (CPlugTree **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x28), uVar3);
      if (param_1 == *ppCVar2) {
        return uVar3;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 0xffffffff;
}

/* public: virtual unsigned long __thiscall CPlugTree::GetChunkCount(void)const
 */

ulong __thiscall CPlugTree::GetChunkCount(CPlugTree *this)

{
  return 0x1c;
}

/* public: virtual unsigned long __thiscall CPlugTree::GetChunkInfo(unsigned
 * long)const  */

ulong __thiscall CPlugTree::GetChunkInfo(CPlugTree *this, ulong param_1)

{
  ulong uVar1;

  if (param_1 < 0x904f00f) {
    if (param_1 != 0x904f00e) {
      switch (param_1) {
      case 0x904f000:
      case 0x904f001:
      case 0x904f002:
      case 0x904f003:
      case 0x904f004:
      case 0x904f005:
      case 0x904f007:
      case 0x904f008:
      case 0x904f009:
      case 0x904f00a:
      case 0x904f00b:
      case 0x904f00c:
        break;
      case 0x904f006:
      case 0x904f00d:
      switchD_008483c8_caseD_904f006:
        return 3;
      default:
        goto switchD_008483c8_caseD_e;
      }
    }
  } else {
    if (0x904f015 < param_1) {
      if (param_1 < 0x904f01a) {
        if (param_1 == 0x904f019) {
          return 1;
        }
        if (param_1 == 0x904f016) {
          return (uint)(*(int *)(this + 0x1c) == 0) * 2 + 1;
        }
        if (param_1 == 0x904f017) {
          return 5;
        }
        if (param_1 == 0x904f018) {
          return 1;
        }
      } else {
        if (param_1 == 0x904f01a) {
          return 3;
        }
        if (param_1 == 0xffffffff) {
          return 0xffffffff;
        }
      }
    switchD_008483c8_caseD_e:
      uVar1 = CMwNod::GetChunkInfo((CMwNod *)this, param_1);
      return uVar1;
    }
    if (param_1 != 0x904f015) {
      switch (param_1) {
      case 0x904f00f:
      case 0x904f010:
      case 0x904f012:
      case 0x904f013:
      case 0x904f014:
        break;
      case 0x904f011:
        goto switchD_008483c8_caseD_904f006;
      default:
        goto switchD_008483c8_caseD_e;
      }
    }
  }
  return 1;
}

/* protected: virtual int __thiscall
   CPlugTree::GetDecorationBoundingBox(int,class GmBoxAligned
   &)const  */

int __thiscall CPlugTree::GetDecorationBoundingBox(CPlugTree *this, int param_1,
                                                   GmBoxAligned *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  CFastBuffer<> *this_00;
  CPlugSurfaceGeom *this_01;
  int iVar3;
  ulong uVar4;
  SKey *pSVar5;
  SVertexDataLayer *pSVar6;
  ulong uVar7;
  int iVar8;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  piVar2 = *(int **)(this + 0x90);
  iVar8 = 0;
  if (piVar2 != (int *)0x0) {
    this_00 = *(CFastBuffer<> **)(this + 0xa4);
    if ((this_00 == (CFastBuffer<> *)0x0) || (piVar2[0x14] == 0)) {
      if (param_1 != 0) {
        (**(code **)(*piVar2 + 0x118))(0xffffffff, 0xffffffff);
      }
      iVar8 = *(int *)(this + 0x90);
      *(undefined4 *)param_2 = *(undefined4 *)(iVar8 + 0x34);
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(iVar8 + 0x38);
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar8 + 0x3c);
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(iVar8 + 0x40);
      *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(iVar8 + 0x44);
      uVar1 = *(undefined4 *)(iVar8 + 0x48);
    } else {
      iVar8 = piVar2[0x14];
      uVar4 = CFastBuffer<>::GetCount(this_00);
      uVar7 = 0;
      if (uVar4 != 0) {
        do {
          pSVar5 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar7);
          pSVar6 =
              CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar8 + 0x24), uVar7);
          GmBoxAligned::SetMult((GmBoxAligned *)&local_18,
                                (GmBoxAligned *)pSVar6, (GmIso4 *)pSVar5);
          if (uVar7 == 0) {
            local_30 = local_18;
            local_2c = local_14;
            local_28 = local_10;
            local_24 = local_c;
            local_20 = local_8;
            local_1c = local_4;
          } else {
            GmBoxAligned::Union((GmBoxAligned *)&local_30,
                                (GmBoxAligned *)&local_18);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar4);
      }
      *(undefined4 *)param_2 = local_30;
      *(undefined4 *)(param_2 + 4) = local_2c;
      *(undefined4 *)(param_2 + 8) = local_28;
      *(undefined4 *)(param_2 + 0xc) = local_24;
      *(undefined4 *)(param_2 + 0x10) = local_20;
      uVar1 = local_1c;
    }
    *(undefined4 *)(param_2 + 0x14) = uVar1;
    iVar8 = 1;
  }
  if ((*(int *)(this + 0x8c) != 0) &&
      (this_01 = *(CPlugSurfaceGeom **)(*(int *)(this + 0x8c) + 0x14),
       this_01 != (CPlugSurfaceGeom *)0x0)) {
    if (param_1 != 0) {
      CPlugSurfaceGeom::ComputeBoundingBox(this_01);
    }
    iVar3 = *(int *)(*(int *)(this + 0x8c) + 0x14);
    if (0.0 <= *(float *)(iVar3 + 0x28)) {
      if (iVar8 != 0) {
        GmBoxAligned::Union(param_2, (GmBoxAligned *)(iVar3 + 0x1c));
        return 1;
      }
      *(undefined4 *)param_2 = *(undefined4 *)(iVar3 + 0x1c);
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(iVar3 + 0x20);
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar3 + 0x24);
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(iVar3 + 0x28);
      *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(iVar3 + 0x2c);
      *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(iVar3 + 0x30);
      return 1;
    }
  }
  return iVar8;
}

/* public: class CPlugTree * __thiscall
 * CPlugTree::GetFirstParentOfClassId(unsigned long)const  */

CPlugTree *__thiscall CPlugTree::GetFirstParentOfClassId(CPlugTree *this,
                                                         ulong param_1)

{
  int *piVar1;
  int iVar2;

  piVar1 = *(int **)(this + 0x24);
  while ((piVar1 != (int *)0x0 &&
          (iVar2 = (**(code **)(*piVar1 + 0x10))(param_1), iVar2 == 0))) {
    piVar1 = (int *)piVar1[9];
  }
  return (CPlugTree *)piVar1;
}

/* public: int __thiscall CPlugTree::GetIsRooted(void)const  */

int __thiscall CPlugTree::GetIsRooted(CPlugTree *this)

{
  if ((*(int *)(this + 0x24) != 0) &&
      ((*(uint *)(this + 0x9c) & 0x8000) == 0)) {
    return 0;
  }
  return 1;
}

/* public: virtual class CPlugTree * __thiscall
 * CPlugTree::GetLastChild(void)const  */

CPlugTree *__thiscall CPlugTree::GetLastChild(CPlugTree *this)

{
  ulong uVar1;
  CPlugTree **ppCVar2;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x28));
  ppCVar2 = (CPlugTree **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(CFastBuffer<> *)(this + 0x28), uVar1 - 1);
  return *ppCVar2;
}

/* public: class CPlugTree * __thiscall CPlugTree::GetModelTree(void)const  */

CPlugTree *__thiscall CPlugTree::GetModelTree(CPlugTree *this)

{
  CPlugTree *pCVar1;

  if (*(int **)(*(int *)(this + 0x1c) + 100) != (int *)0x0) {
    pCVar1 = (CPlugTree *)(**(code **)(**(int **)(*(int *)(this + 0x1c) + 100) +
                                       0xb4))(this + 0x20);
    return pCVar1;
  }
  return (CPlugTree *)0x0;
}

/* public: virtual unsigned long __thiscall CPlugTree::GetMwClassId(void)const
 */

ulong __thiscall CPlugTree::GetMwClassId(CPlugTree *this)

{
  return 0x904f000;
}

/* public: virtual void __thiscall CPlugTree::GetOptimizedGroups(class
   CFastBuffer<struct SPlugTreeOptimGroup *> &,struct SPlugTreeOptimCriteria
   const &,struct SPlugTreeOptimTravel const
   &) */

void __thiscall CPlugTree::GetOptimizedGroups(CPlugTree *this,
                                              CFastBuffer<> *param_1,
                                              SPlugTreeOptimCriteria *param_2,
                                              SPlugTreeOptimTravel *param_3)

{
  CPlugTree CVar1;
  byte bVar2;
  SPlugTreeOptimGroup *pSVar3;
  uint uVar4;
  ulong uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  int **ppiVar9;
  ulong uVar10;
  SPlugTreeOptimGroup **ppSVar11;
  CPlugTree *pCVar12;
  undefined4 *puVar13;
  int iVar14;
  code *pcVar15;
  CPlugTree **ppCVar16;
  CPlugTree **ppCVar17;
  CFastBuffer<> *unaff_retaddr;
  SPlugTreeOptimCriteria *pSVar18;
  undefined4 *puStack_e4;
  undefined4 *puStack_e0;
  float fStack_dc;
  CFastBuffer<> aCStack_d8[12];
  CFastBuffer<> aCStack_cc[12];
  int local_c0;
  undefined4 *puStack_bc;
  int *piStack_b8;
  undefined4 uStack_b4;
  CPlugTree *local_b0[12];
  undefined4 uStack_80;
  CPlugTree *apCStack_7c[14];
  undefined4 *puStack_44;
  undefined4 uStack_40;
  GmIso4 aGStack_3c[48];
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4fe0;
  local_c = ExceptionList;
  uVar4 = ___security_cookie ^ (uint)&stack0xffffff0c;
  ExceptionList = &local_c;
  local_b0[0] = *(CPlugTree **)param_3;
  CVar1 = this[0x9c];
  ppCVar17 = local_b0;
  local_c0 = 0;
  ppCVar16 = (CPlugTree **)(param_3 + 4);
  for (iVar14 = 0xc; ppCVar17 = ppCVar17 + 1, iVar14 != 0;
       iVar14 = iVar14 + -1) {
    *ppCVar17 = *ppCVar16;
    ppCVar16 = ppCVar16 + 1;
  }
  if (((byte)CVar1 & 4) != 0) {
    local_b0[0] = (CPlugTree *)0x1;
    GmIso4::SetMult((GmIso4 *)(local_b0 + 1), (GmIso4 *)(this + 0x5c),
                    (GmIso4 *)(param_3 + 4));
  }
  iVar14 = IsOptimizable(this, param_2);
  if (((iVar14 == 0) ||
       ((*(int **)(this + 0x90) != (int *)0x0 &&
         (iVar14 = (**(code **)(**(int **)(this + 0x90) + 0xcc))(0, uVar4),
          iVar14 == 0)))) ||
      ((iVar14 = *(int *)(this + 0x90),
        iVar14 != 0 &&
            ((uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)(iVar14 + 100)),
              1 < uVar5 ||
                  ((iVar14 != 0 && (*(int *)(iVar14 + 0x50) != 0)))))))) {
    puStack_e4 = (undefined4 *)operator_new(0x48);
    if (puStack_e4 == (undefined4 *)0x0) {
      puStack_e4 = (undefined4 *)0x0;
    } else {
      CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(puStack_e4 + 0xf));
    }
    *puStack_e4 = 1;
    puStack_e4[1] = 1;
    puStack_e4[6] = *(undefined4 *)(this + 0x34);
    apCStack_7c[0] = this;
    ppCVar17 = local_b0;
    puStack_e4[7] = *(undefined4 *)(this + 0x38);
    puStack_e4[8] = *(undefined4 *)(this + 0x3c);
    puStack_e4[9] = *(undefined4 *)(this + 0x40);
    puStack_e4[10] = *(undefined4 *)(this + 0x44);
    puStack_e4[0xb] = *(undefined4 *)(this + 0x48);
    puStack_e4[2] = *(undefined4 *)(this + 0x98);
    puStack_e4[3] = *(undefined4 *)(this + 0x94);
    puStack_e4[4] = *(undefined4 *)(this + 0x8c);
    puStack_e4[5] = *(undefined4 *)(this + 0x9c);
    apCStack_7c[1] = local_b0[0];
    ppCVar16 = apCStack_7c + 2;
    for (iVar14 = 0xc; ppCVar17 = ppCVar17 + 1, iVar14 != 0;
         iVar14 = iVar14 + -1) {
      *ppCVar16 = *ppCVar17;
      ppCVar16 = ppCVar16 + 1;
    }
    CFastBuffer<>::Add((CFastBuffer<> *)(puStack_e4 + 0xf),
                       (SPlugTreeOptimTransf *)apCStack_7c);
    CFastBuffer<>::Add((CFastBuffer<> *)param_1,
                       (CDx9TextureKeeper **)&puStack_e4);
  }
  if (*(int **)(this + 0xa0) == (int *)0x0) {
    if ((*(int *)(this + 0x94) != 0) || (*(int *)(this + 0x8c) != 0)) {
      uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)param_1);
      uVar10 = 0;
      if (uVar5 != 0) {
        while (true) {
          ppSVar11 = (SPlugTreeOptimGroup **)CFastBuffer<>::operator[](
              (CFastBuffer<> *)param_1, uVar10);
          pSVar3 = *ppSVar11;
          puStack_e4 = (undefined4 *)IsEqual(this, pSVar3, param_2,
                                             (SPlugTreeOptimTravel *)local_b0);
          if (puStack_e4 != (undefined4 *)0x0)
            break;
          uVar10 = uVar10 + 1;
          if (uVar5 <= uVar10)
            goto LAB_0084c456;
          puStack_e4 = (undefined4 *)0x0;
        }
        apCStack_7c[0] = this;
        apCStack_7c[1] = local_b0[0];
        ppCVar17 = local_b0;
        ppCVar16 = apCStack_7c + 2;
        for (iVar14 = 0xc; ppCVar17 = ppCVar17 + 1, iVar14 != 0;
             iVar14 = iVar14 + -1) {
          *ppCVar16 = *ppCVar17;
          ppCVar16 = ppCVar16 + 1;
        }
        CFastBuffer<>::Add((CFastBuffer<> *)(pSVar3 + 0x3c),
                           (SPlugTreeOptimTransf *)apCStack_7c);
        if (*(int *)(pSVar3 + 0x10) == 0) {
          *(undefined4 *)(pSVar3 + 0x10) = *(undefined4 *)(this + 0x8c);
        }
        if (*(int *)(pSVar3 + 8) == 0) {
          *(undefined4 *)(pSVar3 + 8) = *(undefined4 *)(this + 0x98);
        }
        if (*(int *)(pSVar3 + 0xc) == 0) {
          *(undefined4 *)(pSVar3 + 0xc) = *(undefined4 *)(this + 0x94);
        }
      LAB_0084c456:
        if (puStack_e4 != (undefined4 *)0x0)
          goto LAB_0084c565;
      }
      puVar7 = (undefined4 *)operator_new(0x48);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      } else {
        CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(puVar7 + 0xf));
      }
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[6] = *(undefined4 *)(this + 0x34);
      puVar7[7] = *(undefined4 *)(this + 0x38);
      puVar7[8] = *(undefined4 *)(this + 0x3c);
      puVar7[9] = *(undefined4 *)(this + 0x40);
      puVar7[10] = *(undefined4 *)(this + 0x44);
      puVar7[0xb] = *(undefined4 *)(this + 0x48);
      puVar7[2] = *(undefined4 *)(this + 0x98);
      puVar7[3] = *(undefined4 *)(this + 0x94);
      puVar7[4] = *(undefined4 *)(this + 0x8c);
      puVar7[5] = *(undefined4 *)(this + 0x9c);
      puStack_e4 = puVar7;
      if (*(int **)(this + 0x90) == (int *)0x0) {
        uVar6 = 0;
      } else {
        uVar6 = (**(code **)(**(int **)(this + 0x90) + 0xcc))(0);
      }
      puVar7[0xc] = uVar6;
      if (*(int **)(this + 0x90) == (int *)0x0) {
        uVar6 = 0;
      } else {
        uVar6 = (**(code **)(**(int **)(this + 0x90) + 0xbc))();
      }
      puVar7[0xd] = uVar6;
      if (*(int **)(this + 0x90) == (int *)0x0) {
        uVar6 = 0;
      } else {
        uVar6 = (**(code **)(**(int **)(this + 0x90) + 0xb8))();
      }
      puVar7[0xe] = uVar6;
      apCStack_7c[0] = this;
      apCStack_7c[1] = local_b0[0];
      ppCVar17 = local_b0;
      ppCVar16 = apCStack_7c + 2;
      for (iVar14 = 0xc; ppCVar17 = ppCVar17 + 1, iVar14 != 0;
           iVar14 = iVar14 + -1) {
        *ppCVar16 = *ppCVar17;
        ppCVar16 = ppCVar16 + 1;
      }
      CFastBuffer<>::Add((CFastBuffer<> *)(puVar7 + 0xf),
                         (SPlugTreeOptimTransf *)apCStack_7c);
      CFastBuffer<>::Add((CFastBuffer<> *)param_1,
                         (CDx9TextureKeeper **)&puStack_e4);
    }
  } else {
    (**(code **)(**(int **)(this + 0xa0) + 0x84))(param_1, param_2, local_b0,
                                                  this);
    local_c0 = 1;
  }
LAB_0084c565:
  puVar7 = (undefined4 *)(**(code **)(*(int *)this + 0x7c))();
  if (puVar7 != (undefined4 *)0x0) {
    puStack_e0 = puVar7;
    CFastBuffer<>::CFastBuffer<>(aCStack_d8);
    uStack_4 = 0;
    CFastBuffer<>::CFastBuffer<>(aCStack_cc);
    uStack_4._0_1_ = 1;
    CFastBuffer<>::InitSize((CFastBuffer<> *)aCStack_d8, 10);
    CFastBuffer<>::InitSize((CFastBuffer<> *)aCStack_cc, 10);
    puStack_e4 = (undefined4 *)0x0;
    if (puVar7 != (undefined4 *)0x0) {
      do {
        piVar8 = (int *)(**(code **)(*(int *)this + 0x80))(puStack_e4);
        if ((local_c0 == 0) ||
            (iVar14 = GetIsRooted((CPlugTree *)piVar8), iVar14 != 0)) {
          iVar14 = (**(code **)(*piVar8 + 0x10))(0x9015000);
          if (iVar14 == 0) {
            pcVar15 = *(code **)(*piVar8 + 0xdc);
          } else {
            uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)(piVar8 + 0x2b));
            ppiVar9 = (int **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)(piVar8 + 0x2b), uVar5 - 1);
            piStack_b8 = *ppiVar9;
            if ((1 < uVar5) &&
                (iVar14 = IsOptimizable((CPlugTree *)piStack_b8,
                                        (SPlugTreeOptimCriteria *)param_1),
                 iVar14 != 0)) {
              CPlugTreeVisualMip::GetMipOptimizedGroups(
                  (CPlugTreeVisualMip *)piVar8, 1, unaff_retaddr,
                  (SPlugTreeOptimCriteria *)param_1,
                  (SPlugTreeOptimTravel *)&uStack_b4);
              uVar10 = CFastBuffer<>::GetCount((CFastBuffer<> *)&fStack_dc);
              if (uVar10 == 0) {
                puVar7 = (undefined4 *)CFastBuffer<>::operator[](
                    (CFastBuffer<> *)(piVar8 + 0x2d), uVar5 - 2);
                local_c0 = piVar8[0x27];
                puStack_e0 = (undefined4 *)*puVar7;
              } else {
                puStack_bc = (undefined4 *)CFastBuffer<>::operator[](
                    (CFastBuffer<> *)(piVar8 + 0x2d), uVar5 - 2);
                puStack_bc = (undefined4 *)*puStack_bc;
                if ((float)puStack_e0 < (float)puStack_bc !=
                    (NAN((float)puStack_e0) || NAN((float)puStack_bc))) {
                  puStack_e0 = puStack_bc;
                }
              }
              bVar2 = *(byte *)(piVar8 + 0x27);
              uStack_80 = uStack_b4;
              ppCVar17 = local_b0;
              ppCVar16 = apCStack_7c;
              for (iVar14 = 0xc; iVar14 != 0; iVar14 = iVar14 + -1) {
                *ppCVar16 = *ppCVar17;
                ppCVar17 = ppCVar17 + 1;
                ppCVar16 = ppCVar16 + 1;
              }
              if ((bVar2 & 4) != 0) {
                uStack_80 = 1;
                GmIso4::SetMult((GmIso4 *)apCStack_7c,
                                (GmIso4 *)(piVar8 + 0x17), (GmIso4 *)local_b0);
              }
              (**(code **)(*piStack_b8 + 0xdc))(&fStack_dc, param_1,
                                                &uStack_80);
              CPlugTreeVisualMip::GetMipOptimizedGroups(
                  (CPlugTreeVisualMip *)piVar8, 0, (CFastBuffer<> *)aCStack_cc,
                  (SPlugTreeOptimCriteria *)param_1,
                  (SPlugTreeOptimTravel *)local_b0);
              goto LAB_0084c755;
            }
            pcVar15 = *(code **)(*piVar8 + 0xdc);
          }
          (*pcVar15)(unaff_retaddr, param_1, &uStack_b4);
        }
      LAB_0084c755:
        puStack_e4 = (undefined4 *)((int)puStack_e4 + 1);
      } while (puStack_e4 < puStack_e0);
    }
    uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)aCStack_d8);
    if (uVar5 != 0) {
      puStack_e0 = (undefined4 *)operator_new(0xd4);
      uVar5 = 0;
      uStack_4._0_1_ = 2;
      if (puStack_e0 == (undefined4 *)0x0) {
        puStack_e4 = (undefined4 *)0x0;
      } else {
        puStack_e4 = (undefined4 *)CPlugTreeVisualMip::CPlugTreeVisualMip(
            (CPlugTreeVisualMip *)puStack_e0);
      }
      uStack_4._0_1_ = 1;
      uVar10 = CFastBuffer<>::GetCount((CFastBuffer<> *)aCStack_cc);
      if (uVar10 == 1) {
        pSVar18 = param_2;
        ppSVar11 = (SPlugTreeOptimGroup **)CFastBuffer<>::operator[](
            (CFastBuffer<> *)aCStack_cc, 0);
        piVar8 = (int *)MakeGroupTree(this, *ppSVar11, pSVar18);
      } else {
        puStack_e0 = (undefined4 *)operator_new(0xac);
        uStack_4._0_1_ = 3;
        if (puStack_e0 == (undefined4 *)0x0) {
          piVar8 = (int *)0x0;
        } else {
          piVar8 = (int *)CPlugTree((CPlugTree *)puStack_e0);
        }
        uStack_4._0_1_ = 1;
        uVar10 = CFastBuffer<>::GetCount((CFastBuffer<> *)aCStack_cc);
        if (uVar10 != 0) {
          do {
            pSVar18 = param_2;
            ppSVar11 = (SPlugTreeOptimGroup **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)aCStack_cc, uVar5);
            pCVar12 = MakeGroupTree(this, *ppSVar11, pSVar18);
            (**(code **)(*piVar8 + 0x88))(pCVar12);
            uVar5 = uVar5 + 1;
            uVar10 = CFastBuffer<>::GetCount((CFastBuffer<> *)aCStack_cc);
          } while (uVar5 < uVar10);
        }
      }
      CPlugTreeVisualMip::AddLevel((CPlugTreeVisualMip *)puStack_e4,
                                   (CPlugTree *)piVar8, fStack_dc);
      uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)aCStack_d8);
      if (uVar5 == 1) {
        ppSVar11 = (SPlugTreeOptimGroup **)CFastBuffer<>::operator[](
            (CFastBuffer<> *)aCStack_d8, 0);
        piVar8 = (int *)MakeGroupTree(this, *ppSVar11, param_2);
      } else {
        puStack_e0 = (undefined4 *)operator_new(0xac);
        uStack_4._0_1_ = 4;
        if (puStack_e0 == (undefined4 *)0x0) {
          piVar8 = (int *)0x0;
        } else {
          piVar8 = (int *)CPlugTree((CPlugTree *)puStack_e0);
        }
        uStack_4._0_1_ = 1;
        uVar10 = 0;
        uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)aCStack_d8);
        if (uVar5 != 0) {
          do {
            pSVar18 = param_2;
            ppSVar11 = (SPlugTreeOptimGroup **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)aCStack_d8, uVar10);
            pCVar12 = MakeGroupTree(this, *ppSVar11, pSVar18);
            (**(code **)(*piVar8 + 0x88))(pCVar12);
            uVar10 = uVar10 + 1;
            uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)aCStack_d8);
          } while (uVar10 < uVar5);
        }
      }
      puVar7 = puStack_e4;
      CPlugTreeVisualMip::AddLevel((CPlugTreeVisualMip *)puStack_e4,
                                   (CPlugTree *)piVar8, 3.402823e+38);
      piVar8[0x27] = piVar8[0x27] & 0xffffff7f;
      puVar13 = (undefined4 *)operator_new(0x48);
      if (puVar13 == (undefined4 *)0x0) {
        puVar13 = (undefined4 *)0x0;
      } else {
        CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(puVar13 + 0xf));
      }
      *puVar13 = 3;
      puVar13[1] = 1;
      puVar13[5] = puStack_bc;
      puStack_44 = puVar7;
      uStack_40 = 0;
      puStack_e0 = puVar13;
      GmIso4::SetIdentity(aGStack_3c);
      CFastBuffer<>::Add((CFastBuffer<> *)(puVar13 + 0xf),
                         (SPlugTreeOptimTransf *)&puStack_44);
      CFastBuffer<>::Add((CFastBuffer<> *)param_1,
                         (CDx9TextureKeeper **)&puStack_e0);
    }
    CFastBuffer<>::DeleteAll((CFastBuffer<> *)aCStack_d8);
    CFastBuffer<>::DeleteAll((CFastBuffer<> *)aCStack_cc);
    CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)aCStack_cc);
    CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)aCStack_d8);
  }
  ExceptionList = local_c;
  return;
}

/* public: virtual class CPlugTree * __thiscall CPlugTree::GetPlugFromId(class
 * CMwId const &) */

CPlugTree *__thiscall CPlugTree::GetPlugFromId(CPlugTree *this, CMwId *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  CPlugTree *pCVar4;
  uint uVar5;

  iVar1 = GetIsRooted(this);
  if (iVar1 == 0) {
    return (CPlugTree *)0x0;
  }
  if ((*(int *)param_1 != *(int *)(this + 0x18)) &&
      ((*(int *)param_1 != -1 || (*(int *)(this + 0x24) != 0)))) {
    uVar2 = (**(code **)(*(int *)this + 0x7c))();
    uVar5 = 0;
    if (uVar2 != 0) {
      do {
        piVar3 = (int *)(**(code **)(*(int *)this + 0x80))(uVar5);
        pCVar4 = (CPlugTree *)(**(code **)(*piVar3 + 0xb4))(param_1);
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

/* public: virtual class CPlugTree * __thiscall
 * CPlugTree::GetPlugFromModelId(class CMwId const &)
 */

CPlugTree *__thiscall CPlugTree::GetPlugFromModelId(CPlugTree *this,
                                                    CMwId *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  CPlugTree *pCVar4;
  uint uVar5;

  iVar1 = GetIsRooted(this);
  if (iVar1 == 0) {
    return (CPlugTree *)0x0;
  }
  if (*(int *)param_1 != *(int *)(this + 0x20)) {
    uVar2 = (**(code **)(*(int *)this + 0x7c))();
    uVar5 = 0;
    if (uVar2 != 0) {
      do {
        piVar3 = (int *)(**(code **)(*(int *)this + 0x80))(uVar5);
        pCVar4 = (CPlugTree *)(**(code **)(*piVar3 + 0xb8))(param_1);
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

/* public: unsigned long __thiscall
 * CPlugTree::GetRecursiveTreeCount(int,int)const  */

ulong __thiscall CPlugTree::GetRecursiveTreeCount(CPlugTree *this, int param_1,
                                                  int param_2)

{
  int iVar1;
  uint uVar2;
  CPlugTree *this_00;
  ulong uVar3;
  ulong uVar4;
  uint uVar5;

  if ((param_2 != 0) && (iVar1 = GetIsRooted(this), iVar1 == 0)) {
    return 0;
  }
  if ((param_1 != 0) && (((byte)this[0x9c] & 8) == 0)) {
    return 0;
  }
  uVar4 = 1;
  uVar2 = (**(code **)(*(int *)this + 0x7c))();
  uVar5 = 0;
  if (uVar2 != 0) {
    do {
      this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))(uVar5);
      uVar3 = GetRecursiveTreeCount(this_00, param_1, param_2);
      uVar5 = uVar5 + 1;
      uVar4 = uVar4 + uVar3;
    } while (uVar5 < uVar2);
  }
  return uVar4;
}

/* public: virtual unsigned long __thiscall
 * CPlugTree::GetRecursiveVertexCount(int,int)const  */

ulong __thiscall CPlugTree::GetRecursiveVertexCount(CPlugTree *this,
                                                    int param_1, int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;

  iVar1 = param_1;
  if ((param_1 != 0) && (((byte)this[0x9c] & 8) == 0)) {
    return 0;
  }
  if (*(int **)(this + 0x90) == (int *)0x0) {
    param_1 = 0;
  } else {
    param_1 = (**(code **)(**(int **)(this + 0x90) + 0xb8))();
  }
  uVar2 = (**(code **)(*(int *)this + 0x7c))();
  if (uVar2 != 0) {
    uVar5 = 0;
    do {
      piVar3 = (int *)(**(code **)(*(int *)this + 0x80))(uVar5);
      if ((iVar1 == 0) || ((*(byte *)(piVar3 + 0x27) & 8) != 0)) {
        iVar4 = (**(code **)(*piVar3 + 0xc0))(iVar1, param_2);
        param_1 = param_1 + iVar4;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar2);
  }
  return param_1;
}

/* public: unsigned long __thiscall CPlugTree::GetRootedChildCount(void)const */

ulong __thiscall CPlugTree::GetRootedChildCount(CPlugTree *this)

{
  uint uVar1;
  CPlugTree *this_00;
  int iVar2;
  ulong uVar3;
  uint uVar4;

  uVar3 = 0;
  uVar1 = (**(code **)(*(int *)this + 0x7c))();
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))(uVar4);
      if (this_00 != (CPlugTree *)0x0) {
        iVar2 = GetIsRooted(this_00);
        if (iVar2 != 0) {
          uVar3 = uVar3 + 1;
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return uVar3;
}

/* public: void __thiscall CPlugTree::GetThisAndVolatileChildsBoundingBox(class
 * GmBoxAligned &) */

void __thiscall CPlugTree::GetThisAndVolatileChildsBoundingBox(
    CPlugTree *this, GmBoxAligned *param_1)

{
  int iVar1;
  uint uVar2;
  CPlugTree *this_00;
  int extraout_ECX;
  uint uVar3;

  iVar1 = (**(code **)(*(int *)this + 0xcc))(0, param_1);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(param_1 + 0xc) = 0xbf800000;
    *(undefined4 *)(param_1 + 0x10) = 0xbf800000;
    *(undefined4 *)(param_1 + 0x14) = 0xbf800000;
  }
  uVar2 = (**(code **)(*(int *)this + 0x7c))();
  uVar3 = 0;
  if (uVar2 != 0) {
    do {
      this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))(uVar3);
      iVar1 = GetIsRooted(this_00);
      if (iVar1 == 0) {
        GmBoxAligned::Union(param_1, (GmBoxAligned *)(extraout_ECX + 0x34));
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return;
}

/* public: void __thiscall CPlugTree::GetThisToRootTransfo(class GmIso4
 *&,int,class CPlugTree )const  */

void __thiscall CPlugTree::GetThisToRootTransfo(CPlugTree *this,
                                                GmIso4 *param_1, int param_2,
                                                CPlugTree *param_3)

{
  CPlugTree *this_00;
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_30[12];

  this_00 = *(CPlugTree **)(this + 0x24);
  if ((this_00 != (CPlugTree *)0x0) && (this_00 != param_3)) {
    GetThisToRootTransfo(this_00, (GmIso4 *)local_30, 1, param_3);
    if ((param_2 != 0) && (((byte)this[0x9c] & 4) != 0)) {
      GmIso4::SetMult(param_1, (GmIso4 *)(this + 0x5c), (GmIso4 *)local_30);
      return;
    }
    puVar2 = local_30;
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)param_1 = *puVar2;
      puVar2 = puVar2 + 1;
      param_1 = (GmIso4 *)((int)param_1 + 4);
    }
    return;
  }
  if ((param_2 != 0) && (((byte)this[0x9c] & 4) != 0)) {
    puVar2 = (undefined4 *)(this + 0x5c);
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)param_1 = *puVar2;
      puVar2 = puVar2 + 1;
      param_1 = (GmIso4 *)((int)param_1 + 4);
    }
    return;
  }
  GmIso4::SetIdentity(param_1);
  return;
}

/* public: virtual unsigned long __thiscall
 * CPlugTree::GetUidChunkFromIndex(unsigned long)const  */

ulong __thiscall CPlugTree::GetUidChunkFromIndex(CPlugTree *this, ulong param_1)

{
  if (param_1 == 0) {
    return 0x1001000;
  }
  return param_1 - 1 | 0x904f000;
}

/* public: unsigned long __thiscall CPlugTree::GetVolatileChildCount(void)const
 */

ulong __thiscall CPlugTree::GetVolatileChildCount(CPlugTree *this)

{
  uint uVar1;
  CPlugTree *this_00;
  int iVar2;
  ulong uVar3;
  uint uVar4;

  uVar3 = 0;
  uVar1 = (**(code **)(*(int *)this + 0x7c))();
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))(uVar4);
      iVar2 = GetIsRooted(this_00);
      if (iVar2 == 0) {
        uVar3 = uVar3 + 1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return uVar3;
}

/* public: void __thiscall CPlugTree::GetVolatileTreePointer(enum
   CPlugTree::EVolatileTreeType,struct CPlugTree::SVolatileTreePointer &)const
 */

void __thiscall CPlugTree::GetVolatileTreePointer(CPlugTree *this,
                                                  EVolatileTreeType param_1,
                                                  SVolatileTreePointer *param_2)

{
  int *this_00;
  int iVar1;
  undefined4 *puVar2;
  CPlugTree *this_01;
  uint uVar3;
  uint uVar4;

  *(undefined4 *)param_2 = 0;
  iVar1 = GetIsRooted(this);
  this_00 = (int *)this;
  while (iVar1 == 0) {
    this_00 = (int *)this_00[9];
    iVar1 = GetIsRooted((CPlugTree *)this_00);
  }
  *(undefined4 *)param_2 = *(undefined4 *)(this + 0x14);
  puVar2 = (undefined4 *)(**(code **)(*this_00 + 0x14))();
  *(undefined4 *)(param_2 + 4) = *puVar2;
  *(EVolatileTreeType *)(param_2 + 8) = param_1;
  if (param_1 == 0) {
    *(undefined4 *)(param_2 + 0xc) = 0xffffffff;
  } else if (param_1 == 1) {
    iVar1 = HasPlugCrystal((CPlugTree *)this_00);
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(this + 0x18);
      return;
    }
    uVar4 = 0;
    iVar1 = (**(code **)(*this_00 + 0x7c))();
    if (iVar1 != 0) {
      do {
        this_01 = (CPlugTree *)(**(code **)(*this_00 + 0x80))(uVar4);
        iVar1 = GetIsRooted(this_01);
        if (iVar1 == 0)
          break;
        uVar4 = uVar4 + 1;
        uVar3 = (**(code **)(*this_00 + 0x7c))();
      } while (uVar4 < uVar3);
    }
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(this + 0x18);
    return;
  }
  return;
}

/* public: int __thiscall CPlugTree::HasPlugCrystal(void)const  */

int __thiscall CPlugTree::HasPlugCrystal(CPlugTree *this)

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

/* public: int __thiscall CPlugTree::HideInvalidTrees(void) */

int __thiscall CPlugTree::HideInvalidTrees(CPlugTree *this)

{
  uint uVar1;
  CPlugTree *this_00;
  int iVar2;
  int iVar3;
  uint uVar4;

  if (((byte)this[0x9c] & 8) != 0) {
    iVar3 = 0;
    uVar1 = (**(code **)(*(int *)this + 0x7c))();
    uVar4 = 0;
    if (uVar1 != 0) {
      do {
        this_00 = (CPlugTree *)(**(code **)(*(int *)this + 0x80))(uVar4);
        iVar2 = HideInvalidTrees(this_00);
        if (iVar2 != 0) {
          iVar3 = 1;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar1);
    }
    if (*(int *)(this + 0x90) != 0) {
      iVar3 = IsVisualValid(this);
    }
    if (iVar3 == 0) {
      *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) & 0xfffffff7;
    }
    return *(uint *)(this + 0x9c) >> 3 & 1;
  }
  return 0;
}

/* public: void __thiscall CPlugTree::InternalCopyVolatileChilds(class CPlugTree
 * const *) */

void __thiscall CPlugTree::InternalCopyVolatileChilds(CPlugTree *this,
                                                      CPlugTree *param_1)

{
  (**(code **)(*(int *)param_1 + 200))(InternalCreateSolidModelInstanceThis, 0,
                                       this);
  return;
}

/* public: class CPlugTree * __thiscall
 * CPlugTree::InternalCreateSolidModelInstance(void)const  */

CPlugTree *__thiscall CPlugTree::InternalCreateSolidModelInstance(
    CPlugTree *this)

{
  CPlugTree *pCVar1;

  pCVar1 = (CPlugTree *)(**(code **)(*(int *)this + 200))(
      InternalCreateSolidModelInstanceThis, 1, 0);
  return pCVar1;
}

/* protected: class CPlugTree * __thiscall
   CPlugTree::InternalCreateSolidModelInstanceThis(void)const  */

CPlugTree *__thiscall CPlugTree::InternalCreateSolidModelInstanceThis(
    CPlugTree *this)

{
  int iVar1;
  int *this_00;
  CMwId *pCVar2;
  CSystemFidParameters *pCVar3;
  CSystemFidParameters *pCVar4;
  undefined *puVar5;
  CPlugTree *pCStack_5c;
  undefined4 uStack_58;
  uint uStack_54;
  CSystemFidParameters aCStack_44[36];
  void *pvStack_20;
  undefined4 uStack_18;
  undefined4 local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4d60;
  local_c = ExceptionList;
  uStack_54 = ___security_cookie ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_c;
  uStack_58 = 0x84977e;
  iVar1 = (**(code **)(*(int *)this + 8))();
  uStack_58 = 0x849783;
  this_00 = (int *)(**(code **)(iVar1 + 0x1c))();
  uStack_58 = 1;
  pCStack_5c = this;
  (**(code **)(*this_00 + 0xb0))();
  pCVar2 = (CMwId *)(**(code **)(*(int *)this + 0x14))();
  InternalSetMwId((CPlugTree *)this_00, pCVar2);
  iVar1 = GetIsRooted(this);
  SetIsRooted((CPlugTree *)this_00, iVar1);
  CSystemFidParameters::CSystemFidParameters(aCStack_44);
  local_c = (void *)0x0;
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)&stack0xffffffb0);
  iVar1 = *this_00;
  puVar5 = &stack0xffffffb0;
  pCVar4 = aCStack_44;
  local_c = (void *)CONCAT31(local_c._1_3_, 1);
  pCVar3 = CSystemFidParameters::GetCurrentParameters();
  (**(code **)(iVar1 + 0x54))(pCVar3, pCVar4, puVar5);
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)&pCStack_5c);
  uStack_18 = 0xffffffff;
  CSystemFidParameters::~CSystemFidParameters(
      (CSystemFidParameters *)&stack0xffffffb0);
  ExceptionList = pvStack_20;
  return (CPlugTree *)this_00;
}

/* public: class CPlugTree * __thiscall
   CPlugTree::InternalGetChildFromPointer(struct CPlugTree::SVolatileTreePointer
   const &) */

CPlugTree *__thiscall CPlugTree::InternalGetChildFromPointer(
    CPlugTree *this, SVolatileTreePointer *param_1)

{
  int iVar1;
  int *this_00;
  uint uVar2;
  CPlugTree *pCVar3;
  uint uVar4;
  CMwId *pCVar5;

  if (*(int *)(param_1 + 8) != 0) {
    if (*(int *)(param_1 + 8) != 1) {
      return (CPlugTree *)0x0;
    }
    iVar1 = HasPlugCrystal(this);
    if (iVar1 != 0) {
      uVar4 = 0;
      iVar1 = (**(code **)(*(int *)this + 0x7c))();
      this_00 = (int *)param_1;
      if (iVar1 != 0) {
        do {
          this_00 = (int *)(**(code **)(*(int *)this + 0x80))(uVar4);
          iVar1 = GetIsRooted((CPlugTree *)this_00);
          if (iVar1 == 0)
            break;
          uVar4 = uVar4 + 1;
          uVar2 = (**(code **)(*(int *)this + 0x7c))();
        } while (uVar4 < uVar2);
      }
      pCVar5 = (CMwId *)&DAT_00000001;
      pCVar3 = (CPlugTree *)(**(code **)(*this_00 + 0x80))(1, param_1 + 0xc);
      pCVar3 = GetChildFromId(pCVar3, pCVar5);
      return pCVar3;
    }
    if (*(int *)(this + 0x18) != *(int *)(param_1 + 0xc)) {
      pCVar3 = GetChildFromId(this, (CMwId *)(param_1 + 0xc));
      return pCVar3;
    }
  }
  return this;
}

/* public: void __thiscall CPlugTree::InternalLoadSetSurface(class CMwNod *) */

void __thiscall CPlugTree::InternalLoadSetSurface(CPlugTree *this,
                                                  CMwNod *param_1)

{
  CFastBuffer<> *this_00;
  CMwNod *pCVar1;
  int iVar2;
  SRpcSkinInfo *pSVar3;
  ulong uVar4;
  ulong *puVar5;
  CMwNod **ppCVar6;
  CMwNod *pCVar7;
  ulong uVar8;
  CMwNod *pCVar9;
  CPlugSurface *local_28;
  CGameMenuFrame *pCStack_24;
  ulong uStack_20;
  CPlugTree *local_1c;
  CFastBuffer<> aCStack_18[12];
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  pCVar1 = param_1;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad50f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_28 = (CPlugSurface *)0x0;
  local_1c = this;
  if (param_1 != (CMwNod *)0x0) {
    iVar2 = (**(code **)(*(int *)param_1 + 0x10))(
        0x900c000, ___security_cookie ^ (uint)&stack0xffffffc8);
    if (iVar2 == 0) {
      local_28 = *(CPlugSurface **)(pCVar1 + 0x38);
      if (local_28 == (CPlugSurface *)0x0) {
        param_1 = (CMwNod *)operator_new(0x24);
        uStack_4 = 0;
        if (param_1 == (CMwNod *)0x0) {
          param_1 = (CMwNod *)0x0;
        } else {
          param_1 =
              (CMwNod *)CPlugSurface::CPlugSurface((CPlugSurface *)param_1);
        }
        local_28 = (CPlugSurface *)param_1;
        *(CMwNod **)(pCVar1 + 0x38) = param_1;
        CFastBuffer<>::CFastBuffer<>(aCStack_18);
        iVar2 = *(int *)(pCVar1 + 0x34);
        uStack_4 = 1;
        pCVar9 = (CMwNod *)local_28;
        if (*(char *)(iVar2 + 6) == '\a') {
          this_00 = (CFastBuffer<> *)(iVar2 + 0x10);
          uStack_20 = CFastBuffer<>::GetCount(this_00);
          uVar8 = 0;
          if (uStack_20 != 0) {
            do {
              pSVar3 =
                  CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar8);
              pCStack_24 = (CGameMenuFrame *)(uint)(byte)pSVar3[0x1c];
              uVar4 =
                  CFastArray<>::Find((CFastArray<> *)aCStack_18, &pCStack_24);
              if (uVar4 == 0xffffffff) {
                uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)aCStack_18);
                CFastBuffer<>::Add((CFastBuffer<> *)aCStack_18,
                                   (CDx9TextureKeeper **)&pCStack_24);
              }
              pSVar3 =
                  CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar8);
              uVar8 = uVar8 + 1;
              *(short *)(pSVar3 + 0x1c) = (short)uVar4;
              pCVar9 = param_1;
            } while (uVar8 < uStack_20);
          }
        } else {
          param_1 = (CMwNod *)(uint) * (byte *)(iVar2 + 4);
          CFastBuffer<>::Add((CFastBuffer<> *)aCStack_18,
                             (CDx9TextureKeeper **)&param_1);
          *(undefined2 *)(iVar2 + 4) = 0;
        }
        pCVar7 = (CMwNod *)0x0;
        if (pCVar1 != *(CMwNod **)(pCVar9 + 0x14)) {
          CMwNod::MwAddRef(pCVar1);
          if (*(CMwNod **)(pCVar9 + 0x14) != (CMwNod *)0x0) {
            CMwNod::MwRelease(*(CMwNod **)(pCVar9 + 0x14));
          }
          *(CMwNod **)(pCVar9 + 0x14) = pCVar1;
        }
        param_1 =
            (CMwNod *)CFastBuffer<>::GetCount((CFastBuffer<> *)aCStack_18);
        if (param_1 != (CMwNod *)0x0) {
          do {
            puVar5 = (ulong *)CFastBuffer<>::operator[](
                (CFastBuffer<> *)aCStack_18, (ulong)pCVar7);
            ppCVar6 = (CMwNod **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)&s_DefaultSurfaceMaterials, *puVar5);
            pCVar1 = *ppCVar6;
            ppCVar6 = (CMwNod **)CFastBuffer<>::AddNewElem(
                (CFastBuffer<> *)(pCVar9 + 0x18));
            if (pCVar1 != *ppCVar6) {
              if (pCVar1 != (CMwNod *)0x0) {
                CMwNod::MwAddRef(pCVar1);
              }
              if (*ppCVar6 != (CMwNod *)0x0) {
                CMwNod::MwRelease(*ppCVar6);
              }
              *ppCVar6 = pCVar1;
            }
            pCVar7 = pCVar7 + 1;
          } while (pCVar7 < param_1);
        }
        uStack_4 = 0xffffffff;
        CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)aCStack_18);
      }
    } else {
      local_28 = (CPlugSurface *)pCVar1;
    }
  }
  SetSurface(local_1c, local_28);
  ExceptionList = local_c;
  return;
}

/* public: virtual class CPlugTree * __thiscall
   CPlugTree::InternalRecursiveCreate(class CPlugTree *
   (__thiscall CPlugTree::*)(void)const,int,class CPlugTree *)const  */

CPlugTree *__thiscall CPlugTree::InternalRecursiveCreate(
    CPlugTree *this, _func_CPlugTree_ptr *param_1, int param_2,
    CPlugTree *param_3)

{
  ulong uVar1;
  CPlugTree **ppCVar2;
  int iVar3;
  int **ppiVar4;
  undefined4 uVar5;
  CFastBuffer<> *this_00;
  ulong uVar6;

  if (param_3 == (CPlugTree *)0x0) {
    param_3 = (*param_1)();
  }
  this_00 = (CFastBuffer<> *)(this + 0x28);
  uVar1 = CFastBuffer<>::GetCount(this_00);
  uVar6 = 0;
  if (uVar1 != 0) {
    do {
      ppCVar2 = (CPlugTree **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)this_00, uVar6);
      iVar3 = GetIsRooted(*ppCVar2);
      if (param_2 == 0) {
        if (iVar3 == 0)
          goto LAB_008498f0;
      } else if (iVar3 != 0) {
      LAB_008498f0:
        ppiVar4 =
            (int **)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar6);
        iVar3 = *(int *)param_3;
        uVar5 = (**(code **)(**ppiVar4 + 200))(param_1, param_2, 0);
        (**(code **)(iVar3 + 0x88))(uVar5);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar1);
  }
  return (CPlugTree *)(int *)param_3;
}

/* public: void __thiscall CPlugTree::InternalSetMwId(class CMwId const &) */

void __thiscall CPlugTree::InternalSetMwId(CPlugTree *this, CMwId *param_1)

{
  *(undefined4 *)(this + 0x18) = *(undefined4 *)param_1;
  return;
}

/* protected: int __thiscall CPlugTree::IsEqual(struct SPlugTreeOptimGroup
   *,struct SPlugTreeOptimCriteria const &,struct SPlugTreeOptimTravel const &)
 */

int __thiscall CPlugTree::IsEqual(CPlugTree *this, SPlugTreeOptimGroup *param_1,
                                  SPlugTreeOptimCriteria *param_2,
                                  SPlugTreeOptimTravel *param_3)

{
  uint uVar1;
  uint uVar2;
  CMwNod *pCVar3;
  CMwNod *pCVar4;
  SPlugTreeOptimCriteria *pSVar5;
  int iVar6;
  ulong uVar7;
  int *piVar8;
  ulong uVar9;
  int unaff_retaddr;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;

  pSVar5 = param_2;
  if (*(int *)(param_1 + 4) != 0) {
    return 0;
  }
  if (((byte)*param_2 & 8) != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar2 = *(uint *)(this + 0x9c);
    if (((uVar1 ^ uVar2) & 0x8000) != 0) {
      return 0;
    }
    if (((uVar1 ^ uVar2) & 8) != 0) {
      return 0;
    }
    if (((uVar1 ^ uVar2) & 0x10) != 0) {
      return 0;
    }
    if (((uVar1 ^ uVar2) & 0x20) != 0) {
      return 0;
    }
    if (((uVar1 ^ uVar2) & 0x4000) != 0) {
      return 0;
    }
  }
  if (((*(int **)(this + 0x90) != (int *)0x0) &&
       (iVar6 = (**(code **)(**(int **)(this + 0x90) + 0xb8))(),
        ((byte)*pSVar5 & 2) != 0)) &&
      (*(uint *)(pSVar5 + 0x1c) < (uint)(*(int *)(param_1 + 0x38) + iVar6))) {
    return 0;
  }
  iVar6 = 0;
  uVar7 = CFastBuffer<>::GetCount((CFastBuffer<> *)(param_1 + 0x3c));
  uVar9 = 0;
  if (uVar7 != 0) {
    do {
      piVar8 = (int *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(CFastBuffer<> *)(param_1 + 0x3c), uVar9);
      if ((*piVar8 != 0) && (iVar6 = *(int *)(*piVar8 + 0x90), iVar6 != 0))
        break;
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar7);
  }
  if ((*(int *)(this + 0x90) != 0) && (iVar6 != 0)) {
    uVar1 = *(uint *)(*(int *)(this + 0x90) + 0x1c);
    if (((*(uint *)(iVar6 + 0x1c) ^ uVar1) & 0x100) != 0) {
      return 0;
    }
    if ((char)((byte) * (uint *)(iVar6 + 0x1c) ^ (byte)uVar1) < '\0') {
      return 0;
    }
  }
  uStack_18 = *(undefined4 *)(param_1 + 0x18);
  uStack_14 = *(undefined4 *)(param_1 + 0x1c);
  uStack_10 = *(undefined4 *)(param_1 + 0x20);
  fStack_c = *(float *)(param_1 + 0x24);
  fStack_8 = *(float *)(param_1 + 0x28);
  fStack_4 = *(float *)(param_1 + 0x2c);
  GmBoxAligned::Union((GmBoxAligned *)&uStack_18,
                      (GmBoxAligned *)(this + 0x34));
  if (((byte)*param_2 & 1) != 0) {
    if (*(float *)(param_2 + 0x18) < fStack_c * 2.0 !=
        (NAN(*(float *)(param_2 + 0x18)) || NAN(fStack_c * 2.0))) {
      return 0;
    }
    if (*(float *)(param_2 + 0x18) < fStack_8 * 2.0 !=
        (NAN(*(float *)(param_2 + 0x18)) || NAN(fStack_8 * 2.0))) {
      return 0;
    }
    if (*(float *)(param_2 + 0x18) < fStack_4 * 2.0 !=
        (NAN(*(float *)(param_2 + 0x18)) || NAN(fStack_4 * 2.0))) {
      return 0;
    }
  }
  if (((*(int *)(param_1 + 0x10) == 0) || (*(int *)(this + 0x8c) == 0)) &&
      (*(int *)(param_1 + 8) == *(int *)(this + 0x98))) {
    pCVar3 = *(CMwNod **)(param_1 + 0xc);
    if (((pCVar3 != (CMwNod *)0x0) &&
         (pCVar4 = *(CMwNod **)(this + 0x94), pCVar4 != (CMwNod *)0x0)) &&
        (pCVar3 != pCVar4)) {
      param_2 = (SPlugTreeOptimCriteria *)0x0;
      CSystemArchiveNod::Compare(pCVar3, pCVar4, (int *)&param_2);
      if (param_2 == (SPlugTreeOptimCriteria *)0x0) {
        return 0;
      }
    }
    *(undefined4 *)(param_1 + 0x18) = uStack_18;
    *(undefined4 *)(param_1 + 0x1c) = uStack_14;
    *(undefined4 *)(param_1 + 0x20) = uStack_10;
    *(float *)(param_1 + 0x24) = fStack_c;
    *(float *)(param_1 + 0x28) = fStack_8;
    *(float *)(param_1 + 0x2c) = fStack_4;
    if (*(int **)(this + 0x90) != (int *)0x0) {
      iVar6 = (**(code **)(**(int **)(this + 0x90) + 0xcc))(0);
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + iVar6;
      iVar6 = (**(code **)(**(int **)(this + 0x90) + 0xbc))();
      *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + iVar6;
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + unaff_retaddr;
    }
    return 1;
  }
  return 0;
}

/* protected: int __thiscall CPlugTree::IsOptimizable(struct
 * SPlugTreeOptimCriteria const &)const
 */

int __thiscall CPlugTree::IsOptimizable(CPlugTree *this,
                                        SPlugTreeOptimCriteria *param_1)

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

/* protected: int __thiscall CPlugTree::IsVisualValid(void)const  */

int __thiscall CPlugTree::IsVisualValid(CPlugTree *this)

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

/* protected: class CPlugTree * __thiscall CPlugTree::MakeGroupTree(struct
 *SPlugTreeOptimGroup ,struct SPlugTreeOptimCriteria const &) */

CPlugTree *__thiscall CPlugTree::MakeGroupTree(CPlugTree *this,
                                               SPlugTreeOptimGroup *param_1,
                                               SPlugTreeOptimCriteria *param_2)

{
  CPlugMaterial **ppCVar1;
  SPlugTreeOptimGroup *pSVar2;
  uint uVar3;
  CPlugTree *this_00;
  CPlugSurface *pCVar4;
  CPlugVisual *pCVar5;
  CPlugTree **ppCVar6;
  int **ppiVar7;
  int iVar8;
  void *unaff_EBX;
  int *this_01;
  CPlugTree **ppCVar9;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  pSVar2 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4f7b;
  local_c = ExceptionList;
  uVar3 = ___security_cookie ^ (uint)&stack0xffffffe4;
  ExceptionList = &local_c;
  this_01 = (int *)0x0;
  switch (*(undefined4 *)param_1) {
  case 0:
    this_00 = (CPlugTree *)operator_new(0xac);
    local_4 = 0;
    if (this_00 == (CPlugTree *)0x0) {
      this_01 = (int *)0x0;
    } else {
      this_01 = (int *)CPlugTree(this_00);
    }
    local_4 = 0xffffffff;
    pCVar4 = CreateGroupSurface(this, param_1);
    SetSurface((CPlugTree *)this_01, pCVar4);
    pCVar5 = CreateGroupVisual(this, param_1);
    SetVisual((CPlugTree *)this_01, pCVar5, *(CPlugShader **)(param_1 + 0xc),
              (CPlugMaterial *)0x0, 0);
    ppCVar1 = (CPlugMaterial **)(param_1 + 8);
    param_1 = (SPlugTreeOptimGroup *)this_00;
    if (*ppCVar1 != (CPlugMaterial *)0x0) {
      SetMaterial((CPlugTree *)this_01, *ppCVar1);
    }
    break;
  case 1:
    ppCVar6 = (CPlugTree **)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(param_1 + 0x3c), 0);
    this_01 = (int *)DuplicateThis(*ppCVar6);
    this_01[0x27] = this_01[0x27] ^ ((int)ppCVar6[1] * 4 ^ this_01[0x27]) & 4U;
    goto LAB_0084c0a0;
  case 2:
    ppCVar6 = (CPlugTree **)CFastBuffer<>::operator[](
        (CFastBuffer<> *)(param_1 + 0x3c), 0);
    this_01 = (int *)DuplicateRecursive(*ppCVar6);
    this_01[0x27] = this_01[0x27] ^ ((int)ppCVar6[1] * 4 ^ this_01[0x27]) & 4U;
  LAB_0084c0a0:
    ppCVar6 = ppCVar6 + 2;
    ppCVar9 = (CPlugTree **)(this_01 + 0x17);
    for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
      *ppCVar9 = *ppCVar6;
      ppCVar6 = ppCVar6 + 1;
      ppCVar9 = ppCVar9 + 1;
    }
    break;
  case 3:
    ppiVar7 =
        (int **)CFastBuffer<>::operator[]((CFastBuffer<> *)(param_1 + 0x3c), 0);
    this_01 = *ppiVar7;
  }
  (**(code **)(*this_01 + 0xbc))(1, uVar3);
  if (this_01[0x23] != 0) {
    this_01[0x27] = this_01[0x27] | 0x80;
  }
  if ((((*(int *)(param_1 + 8) != 0) && (iVar8 = this_01[0x24], iVar8 != 0)) &&
       (uVar3 = *(uint *)(iVar8 + 0x1c), (uVar3 & 8) == 0)) &&
      ((*(uint *)(iVar8 + 0x1c) = uVar3 | 8,
        (uVar3 & 0x400) == 0 && (*(uint *)(iVar8 + 0x1c) = uVar3 | 0x408,
                                 CPlugVisual::s_CallbackVisionOnDirty !=
                                     (CFastCallback1P<> *)0x0)))) {
    (***(code ***)CPlugVisual::s_CallbackVisionOnDirty)(iVar8);
  }
  if (((byte)*param_1 & 8) != 0) {
    this_01[0x27] =
        this_01[0x27] ^ (this_01[0x27] ^ *(uint *)(pSVar2 + 0x14)) & 0x100;
    uVar3 = (*(uint *)(pSVar2 + 0x14) ^ this_01[0x27]) & 1 ^ this_01[0x27];
    this_01[0x27] = uVar3;
    uVar3 = (*(uint *)(pSVar2 + 0x14) ^ uVar3) & 0x10 ^ uVar3;
    this_01[0x27] = uVar3;
    uVar3 = (*(uint *)(pSVar2 + 0x14) ^ uVar3) & 0x20 ^ uVar3;
    this_01[0x27] = uVar3;
    uVar3 = (*(uint *)(pSVar2 + 0x14) ^ uVar3) & 8 ^ uVar3;
    this_01[0x27] = uVar3;
    uVar3 = (*(uint *)(pSVar2 + 0x14) ^ uVar3) & 0x4000 ^ uVar3;
    this_01[0x27] = uVar3;
    uVar3 = (*(uint *)(pSVar2 + 0x14) ^ uVar3) & 0x8000 ^ uVar3;
    this_01[0x27] = uVar3;
    this_01[0x27] = (*(uint *)(pSVar2 + 0x14) ^ uVar3) & 0x40 ^ uVar3;
  }
  ExceptionList = unaff_EBX;
  return (CPlugTree *)this_01;
}

/* public: static class CPlugTree * __cdecl CPlugTree::MakeQuad2D(class CPlug
   *,float,float,class CPlugVisual *,float,unsigned long,unsigned long,unsigned
   long,class GmVec2 const &,class GmVec2 const &,class GmVec2 const &) */

CPlugTree *__cdecl CPlugTree::MakeQuad2D(CPlug *param_1, float param_2,
                                         float param_3, CPlugVisual *param_4,
                                         float param_5, ulong param_6,
                                         ulong param_7, ulong param_8,
                                         GmVec2 *param_9, GmVec2 *param_10,
                                         GmVec2 *param_11)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int *this;
  CPlugBitmapApply *pCVar8;
  CPlugTree *pCVar9;
  CPlugVisualQuads2D *this_00;
  GxTexCoord *pGVar10;
  uint uVar11;
  CPlugVisualQuads2D *unaff_retaddr;
  float *pfVar12;
  float *pfVar13;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  float fStack_2c;
  undefined4 uStack_28;
  float fStack_24;
  undefined4 uStack_20;
  void *pvStack_1c;
  void *pvStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  CPlugTree *local_c;
  CPlugTree *pCStack_8;
  CPlugShaderApply *local_4;

  local_4 = (CPlugShaderApply *)0xffffffff;
  pCStack_8 = (CPlugTree *)&LAB_00ad5060;
  local_c = (CPlugTree *)ExceptionList;
  uVar5 = ___security_cookie ^ (uint)&stack0xffffffac;
  ExceptionList = &local_c;
  piVar6 = (int *)param_1;
  if (param_1 == (CPlug *)0x0) {
    param_1 = (CPlug *)operator_new(0x50);
    local_4 = (CPlugShaderApply *)0x0;
    if (param_1 == (CPlug *)0x0) {
      piVar6 = (int *)0x0;
    } else {
      piVar6 = (int *)CPlugFileGen::CPlugFileGen((CPlugFileGen *)param_1);
    }
    local_4 = (CPlugShaderApply *)0xffffffff;
    CPlugFileGen::GenChecker((CPlugFileGen *)piVar6, 1);
  }
  iVar7 = (**(code **)(*piVar6 + 0x10))(0x9025000, uVar5);
  this = piVar6;
  if (iVar7 != 0) {
    unaff_retaddr = (CPlugVisualQuads2D *)operator_new(0x78);
    pCStack_8 = (CPlugTree *)0x1;
    if (unaff_retaddr == (CPlugVisualQuads2D *)0x0) {
      this = (int *)0x0;
    } else {
      this = (int *)CPlugBitmap::CPlugBitmap((CPlugBitmap *)unaff_retaddr);
    }
    pCStack_8 = (CPlugTree *)0xffffffff;
    CPlugBitmap::SetImage((CPlugBitmap *)this, (CPlugFileImg *)piVar6);
    CPlugBitmap::SetDefaultTexAddress((CPlugBitmap *)this, 2, 2, 0);
  }
  iVar7 = (**(code **)(*this + 0x10))(0x9011000);
  piVar6 = this;
  if (iVar7 != 0) {
    local_4 = (CPlugShaderApply *)operator_new(0xa8);
    local_c = (CPlugTree *)0x2;
    if (local_4 == (CPlugShaderApply *)0x0) {
      piVar6 = (int *)0x0;
    } else {
      piVar6 = (int *)CPlugShaderApply::CPlugShaderApply(local_4);
    }
    local_c = (CPlugTree *)0xffffffff;
    pCVar8 = CPlugShaderApply::AddTextureApply((CPlugShaderApply *)piVar6,
                                               (CPlugBitmap *)this, 1, 0);
    if (pCVar8 != (CPlugBitmapApply *)0x0) {
      if ((DAT_00d6e6b8 & 1) == 0) {
        DAT_00d6e6b8 = DAT_00d6e6b8 | 1;
        local_c = (CPlugTree *)0x3;
        CMwId::CreateFromLocalName((CMwId *)&DAT_00d6e6b4, "Diffuse");
        _atexit((_func_4879 *)&LAB_00b23260);
        local_c = (CPlugTree *)0xffffffff;
      }
      *(undefined4 *)(pCVar8 + 0x18) = DAT_00d6e6b4;
    }
    CPlugShaderGeneric::SetVertexColor((CPlugShaderGeneric *)piVar6, 1,
                                       (GxColor *)0x0);
    CPlugShader::SetReceiverShadowGroupMask((CPlugShader *)piVar6, 0);
    CHmsItem::SetIsForcePointDynamicCollisionResponse((CHmsItem *)piVar6, 0);
    CPlugShaderApply::SetBlending((CPlugShaderApply *)piVar6, 4, 5);
    CPlugShaderApply::SetForceIsAlphaBlend((CPlugShaderApply *)piVar6, 1);
  }
  iVar7 = (**(code **)(*piVar6 + 0x10))(&DAT_09002000);
  if ((iVar7 == 0) &&
      (iVar7 = (**(code **)(*piVar6 + 0x10))(0x9079000), iVar7 == 0)) {
    pCStack_8 = (CPlugTree *)operator_new(0xac);
    uStack_10 = 6;
    if (pCStack_8 == (CPlugTree *)0x0) {
      uRam0000009c = uRam0000009c & 0xfffffff7;
      ExceptionList = pvStack_18;
      return (CPlugTree *)0x0;
    }
    pCVar9 = (CPlugTree *)CPlugTree(pCStack_8);
    *(uint *)(pCVar9 + 0x9c) = *(uint *)(pCVar9 + 0x9c) & 0xfffffff7;
    ExceptionList = pvStack_18;
    return pCVar9;
  }
  iVar7 = (**(code **)(*piVar6 + 0x10))(0x9079000);
  local_c = (CPlugTree *)operator_new(0xac);
  uStack_14 = 4;
  if (local_c == (CPlugTree *)0x0) {
    local_c = (CPlugTree *)0x0;
  } else {
    local_c = (CPlugTree *)CPlugTree(local_c);
  }
  uStack_14 = 0xffffffff;
  if (unaff_retaddr == (CPlugVisualQuads2D *)0x0) {
    this_00 = (CPlugVisualQuads2D *)operator_new(0x84);
    uStack_14 = 5;
    if (this_00 == (CPlugVisualQuads2D *)0x0) {
      unaff_retaddr = (CPlugVisualQuads2D *)0x0;
    } else {
      unaff_retaddr =
          (CPlugVisualQuads2D *)CPlugVisualQuads2D::CPlugVisualQuads2D(this_00);
    }
    uStack_14 = 0xffffffff;
    CPlugVisualQuads2D::SetQuadCount(unaff_retaddr, 1);
    if (NAN((float)pCStack_8) != ((float)pCStack_8 == -1.0)) {
      pCStack_8 = (CPlugTree *)0x3dcccccd;
    }
    if (NAN((float)local_4) != ((float)local_4 == -1.0)) {
      local_4 = (CPlugShaderApply *)0x3dcccccd;
    }
    fStack_3c = 1.0;
    fStack_38 = 1.0;
    uStack_34 = 0x3f800000;
    uStack_30 = 0x3f800000;
    CPlugVisualQuads2D::CreateQuad(unaff_retaddr, 0.0, 0.0, (float)pCStack_8,
                                   (float)local_4, &fStack_3c, 0,
                                   (float)param_1);
    if ((param_3 == 0.0) || (param_4 == (CPlugVisual *)0x0)) {
      fStack_24 = *(float *)param_5;
      uStack_20 = *(undefined4 *)(param_6 + 4);
      fStack_2c = *(float *)param_6;
      uStack_28 = *(undefined4 *)((int)param_5 + 4);
      pGVar10 = (GxTexCoord *)operator_new[](0x20);
      CPlugVisual::AddTexCoordSet((CPlugVisual *)unaff_retaddr, pGVar10);
      pfVar13 = &fStack_2c;
      pfVar12 = &fStack_24;
    } else {
      uVar5 = (uint)param_2 / (uint)param_3;
      uVar11 = (uint)param_2 % (uint)param_3;
      fVar1 = *(float *)(param_6 + 4) - *(float *)((int)param_5 + 4);
      fVar2 = (float)(int)param_3;
      if ((int)param_3 < 0) {
        fVar2 = fVar2 + 4.294967e+09;
      }
      fVar3 = (float)uVar11;
      if ((int)uVar11 < 0) {
        fVar3 = fVar3 + 4.294967e+09;
      }
      fStack_3c = (*(float *)param_5 +
                   (*(float *)param_6 - *(float *)param_5) * (fVar2 / fVar3)) -
                  *(float *)param_7;
      fVar3 = (float)(int)param_4;
      if ((int)param_4 < 0) {
        fVar3 = fVar3 + 4.294967e+09;
      }
      fVar4 = (float)(uVar5 + 1);
      if ((int)(uVar5 + 1) < 0) {
        fVar4 = fVar4 + 4.294967e+09;
      }
      fStack_38 = *(float *)(param_7 + 4) + *(float *)((int)param_5 + 4) +
                  fVar1 * (fVar3 / fVar4);
      fVar4 = (float)(uVar11 + 1);
      if ((int)(uVar11 + 1) < 0) {
        fVar4 = fVar4 + 4.294967e+09;
      }
      fStack_44 = *(float *)param_7 + *(float *)param_5 +
                  (fVar2 / fVar4) * (*(float *)param_6 - *(float *)param_5);
      fVar2 = (float)uVar5;
      if ((int)uVar5 < 0) {
        fVar2 = fVar2 + 4.294967e+09;
      }
      fStack_40 = ((fVar2 / fVar3) * fVar1 + *(float *)((int)param_5 + 4)) -
                  *(float *)(param_7 + 4);
      pGVar10 = (GxTexCoord *)operator_new[](0x20);
      CPlugVisual::AddTexCoordSet((CPlugVisual *)unaff_retaddr, pGVar10);
      pfVar13 = &fStack_44;
      pfVar12 = &fStack_3c;
    }
    CPlugVisualQuads2D::SetQuadUVs(unaff_retaddr, 0, (GmVec2 *)pfVar12,
                                   (GmVec2 *)pfVar13);
    uVar5 = *(uint *)(unaff_retaddr + 0x1c);
    if ((((uVar5 & 8) == 0) &&
         (*(uint *)(unaff_retaddr + 0x1c) = uVar5 | 8, (uVar5 & 0x400) == 0)) &&
        (*(uint *)(unaff_retaddr + 0x1c) = uVar5 | 0x408,
         CPlugVisual::s_CallbackVisionOnDirty != (CFastCallback1P<> *)0x0)) {
      (***(code ***)CPlugVisual::s_CallbackVisionOnDirty)(unaff_retaddr);
    }
    uVar5 = *(uint *)(unaff_retaddr + 0x1c);
    if ((((uVar5 & 0x20) == 0) &&
         (*(uint *)(unaff_retaddr + 0x1c) = uVar5 | 0x20,
          (uVar5 & 0x400) == 0)) &&
        (*(uint *)(unaff_retaddr + 0x1c) = uVar5 | 0x420,
         CPlugVisual::s_CallbackVisionOnDirty != (CFastCallback1P<> *)0x0)) {
      (***(code ***)CPlugVisual::s_CallbackVisionOnDirty)(unaff_retaddr);
    }
  }
  SetVisual(local_c, (CPlugVisual *)unaff_retaddr,
            (CPlugShader *)(~-(uint)(iVar7 != 0) & (uint)piVar6),
            (CPlugMaterial *)(-(uint)(iVar7 != 0) & (uint)piVar6), 0);
  ExceptionList = pvStack_1c;
  return local_c;
}

/* public: int __thiscall CPlugTree::MergePrimitivesInTree(class CPlugShader
   *,class CFastBuffer<class CPlugVisual *> &) */

int __thiscall CPlugTree::MergePrimitivesInTree(CPlugTree *this,
                                                CPlugShader *param_1,
                                                CFastBuffer<> *param_2)

{
  short *psVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  ulong uVar5;
  int **ppiVar6;
  int iVar7;
  GxVertex *pGVar8;
  ushort *puVar9;
  CPlugVisualIndexedTriangles *this_00;
  GxTexCoord *pGVar10;
  int iVar11;
  SFastCat *pSVar12;
  int unaff_EBX;
  uint uVar13;
  ulong uVar14;
  size_t _Size;
  ulong local_2c;
  CPlugVisualIndexed *pCStack_24;
  uint local_20;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4f4b;
  local_c = ExceptionList;
  uVar4 = ___security_cookie ^ (uint)&stack0xffffffc4;
  ExceptionList = &local_c;
  uVar5 = CFastBuffer<>::GetCount((CFastBuffer<> *)param_2);
  uVar13 = 0;
  if ((uVar5 == 0) || (param_1 == (CPlugShader *)0x0)) {
    iVar7 = 0;
  } else {
    uVar2 = *(uint *)(param_1 + 0x20);
    uVar14 = 0;
    local_20 = 0;
    if (uVar5 != 0) {
      do {
        ppiVar6 =
            (int **)CFastBuffer<>::operator[]((CFastBuffer<> *)param_2, uVar14);
        piVar3 = *ppiVar6;
        iVar7 = (**(code **)(*piVar3 + 0xb8))(uVar4);
        uVar13 = uVar13 + iVar7;
        iVar7 = (**(code **)(*piVar3 + 0xcc))(0);
        unaff_EBX = unaff_EBX + iVar7;
        iVar7 = (**(code **)(*piVar3 + 0xbc))();
        local_20 = local_20 + iVar7;
        uVar14 = uVar14 + 1;
      } while (uVar14 < uVar5);
    }
    pGVar8 = (GxVertex *)operator_new[](
        -(uint)((int)((ulonglong)uVar13 * 0x28 >> 0x20) != 0) |
        (uint)((ulonglong)uVar13 * 0x28));
    puVar9 = (ushort *)operator_new[](0);
    uVar14 = 0;
    local_2c = 0;
    pCStack_24 = (CPlugVisualIndexed *)0x0;
    if (uVar5 != 0) {
      do {
        ppiVar6 = (int **)CFastBuffer<>::operator[]((CFastBuffer<> *)param_2,
                                                    (ulong)pCStack_24);
        piVar3 = *ppiVar6;
        (**(code **)(*piVar3 + 0xc0))(pGVar8 + uVar14 * 0x28);
        iVar7 = local_20 + unaff_EBX * 2;
        (**(code **)(*piVar3 + 0xd0))(iVar7);
        uVar4 = (**(code **)(*piVar3 + 0xcc))(0);
        uVar13 = 0;
        if (uVar4 != 0) {
          do {
            psVar1 = (short *)(iVar7 + uVar13 * 2);
            *psVar1 = *psVar1 + (short)uVar14;
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar4);
        }
        iVar7 = (**(code **)(*piVar3 + 0xb8))();
        local_2c = local_2c + uVar4;
        uVar14 = uVar14 + iVar7;
        pCStack_24 = (CPlugVisualIndexed *)((int)pCStack_24 + 1);
      } while (pCStack_24 < uVar5);
    }
    this_00 = (CPlugVisualIndexedTriangles *)operator_new(0x9c);
    uStack_4 = 0;
    if (this_00 == (CPlugVisualIndexedTriangles *)0x0) {
      pCStack_24 = (CPlugVisualIndexed *)0x0;
    } else {
      pCStack_24 = (CPlugVisualIndexed *)
          CPlugVisualIndexedTriangles::CPlugVisualIndexedTriangles(this_00);
    }
    uStack_4 = 0xffffffff;
    CPlugVisualIndexed::SetVerticesAndIndices(pCStack_24, uVar14, pGVar8,
                                              local_2c, puVar9);
    CPlugVisual::EnableVertexColor((CPlugVisual *)pCStack_24, 0);
    SetVisual(this, (CPlugVisual *)pCStack_24, (CPlugShader *)0x0,
              (CPlugMaterial *)0x0, 0);
    (**(code **)(*(int *)this + 0xbc))(1);
    local_2c = 0;
    if ((uVar2 & 0xf) != 0) {
      do {
        iVar7 = 0;
        pGVar10 = (GxTexCoord *)operator_new[](
            -(uint)((int)((ulonglong)local_20 * 8 >> 0x20) != 0) |
            (uint)((ulonglong)local_20 * 8));
        uVar14 = 0;
        if (uVar5 != 0) {
          do {
            ppiVar6 = (int **)CFastBuffer<>::operator[](
                (CFastBuffer<> *)param_2, uVar14);
            piVar3 = *ppiVar6;
            iVar11 = (**(code **)(*piVar3 + 0xbc))();
            _Size = iVar11 * 8;
            pSVar12 = CFastBuffer<>::operator[](
                (CFastBuffer<> *)(piVar3 + 0x17), local_2c);
            _memcpy(pGVar10 + iVar7 * 8, *(void **)(pSVar12 + 4), _Size);
            uVar14 = uVar14 + 1;
            iVar7 = iVar7 + iVar11;
          } while (uVar14 < uVar5);
        }
        CPlugVisual::AddTexCoordSet((CPlugVisual *)pCStack_24, pGVar10);
        local_2c = local_2c + 1;
      } while (local_2c < (uVar2 & 0xf));
    }
    SetShader(this, param_1);
    iVar7 = 1;
  }
  ExceptionList = local_c;
  return iVar7;
}

/* public: virtual class CMwClassInfo const * __thiscall
 * CPlugTree::MwGetClassInfo(void)const  */

CMwClassInfo *__thiscall CPlugTree::MwGetClassInfo(CPlugTree *this)

{
  return &m_MwClassInfo_CPlugTree;
}

/* public: virtual int __thiscall CPlugTree::MwIsKindOf(unsigned long)const  */

int __thiscall CPlugTree::MwIsKindOf(CPlugTree *this, ulong param_1)

{
  if ((param_1 != 0x904f000) && (param_1 != 0x902b000)) {
    return (uint)(param_1 == 0x1001000);
  }
  return 1;
}

/* public: static class CMwNod * __cdecl CPlugTree::MwNewCPlugTree(void) */

CMwNod *__cdecl CPlugTree::MwNewCPlugTree(void)

{
  CPlugTree *this;
  CMwNod *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4e1b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = (CPlugTree *)operator_new(0xac);
  local_4 = 0;
  if (this != (CPlugTree *)0x0) {
    pCVar1 = (CMwNod *)CPlugTree(this);
    ExceptionList = local_c;
    return pCVar1;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}

/* public: virtual void __thiscall CPlugTree::OnNodLoaded(void) */

void __thiscall CPlugTree::OnNodLoaded(CPlugTree *this)

{
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x10000;
  if (*(int *)(this + 0x1c) != 0) {
    RefreshThisFromModel(this);
    return;
  }
  return;
}

/* public: void __thiscall CPlugTree::RefreshThisFromModel(void) */

void __thiscall CPlugTree::RefreshThisFromModel(CPlugTree *this)

{
  int iVar1;
  CPlugTree *pCVar2;
  undefined4 uVar3;

  iVar1 = *(int *)this;
  uVar3 = 0;
  pCVar2 = GetModelTree(this);
  (**(code **)(iVar1 + 0xb0))(pCVar2, uVar3);
  (**(code **)(*(int *)this + 0x78))(0);
  return;
}

/* public: virtual void __thiscall CPlugTree::RenderBefore(class GmFrustum const
   &,class GmBoxAligned const &,class GmIso4 const &,class GmIso4 const &,int
   &,struct SPlugTreeInRenderFlags) */

void __thiscall CPlugTree::RenderBefore(void)

{
  return;
}

/* public: virtual void __thiscall CPlugTree::SetChild(class CPlugTree
 * *,unsigned long) */

void __thiscall CPlugTree::SetChild(CPlugTree *this, CPlugTree *param_1,
                                    ulong param_2)

{
  int *piVar1;
  int **ppiVar2;
  CPlugTree **ppCVar3;

  ppiVar2 = (int **)CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x28),
                                              param_2);
  piVar1 = *ppiVar2;
  ppCVar3 = (CPlugTree **)CFastBuffer<>::operator[](
      (CFastBuffer<> *)(this + 0x28), param_2);
  *ppCVar3 = param_1;
  if (*(int *)(this + 0x14) != 0) {
    (**(code **)(*(int *)param_1 + 0x78))(0);
  }
  ConnectAsChild(this, param_1, 1);
  DeconnectAsChild(this, (CPlugTree *)piVar1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(1);
  }
  return;
}

/* public: void __thiscall CPlugTree::SetFuncTree(class CFuncTree *) */

void __thiscall CPlugTree::SetFuncTree(CPlugTree *this, CFuncTree *param_1)

{
  if (param_1 != *(CFuncTree **)(this + 0xa8)) {
    if (param_1 != (CFuncTree *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1);
    }
    if (*(CMwNod **)(this + 0xa8) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xa8));
    }
    *(CFuncTree **)(this + 0xa8) = param_1;
  }
  return;
}

/* public: void __thiscall CPlugTree::SetGenerator(class CPlugTreeGenerator
 * *,int) */

void __thiscall CPlugTree::SetGenerator(CPlugTree *this,
                                        CPlugTreeGenerator *param_1,
                                        int param_2)

{
  if (*(int **)(this + 0xa0) == (int *)0x0) {
  LAB_00849bd7:
    if ((param_2 != 0) || (param_1 != (CPlugTreeGenerator *)0x0))
      goto LAB_00849bf7;
  } else if ((param_2 != 0) || (param_1 != (CPlugTreeGenerator *)0x0)) {
    (**(code **)(**(int **)(this + 0xa0) + 0x7c))(this);
    goto LAB_00849bd7;
  }
  if (*(int *)(this + 0xa0) != 0) {
    FUN_00849b00((int *)this);
    FUN_00848c00((int *)this);
  }
LAB_00849bf7:
  if (param_1 != *(CPlugTreeGenerator **)(this + 0xa0)) {
    if (param_1 != (CPlugTreeGenerator *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1);
    }
    if (*(CMwNod **)(this + 0xa0) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xa0));
    }
    *(CPlugTreeGenerator **)(this + 0xa0) = param_1;
  }
  if ((*(int **)(this + 0xa0) != (int *)0x0) && (param_2 != 0)) {
    (**(code **)(**(int **)(this + 0xa0) + 0x78))(this);
  }
  return;
}

/* public: virtual void __thiscall CPlugTree::SetIdName(char const *) */

void __thiscall CPlugTree::SetIdName(CPlugTree *this, char *param_1)

{
  CMwId *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4cf8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = CMwId::CreateFromLocalName((CMwId *)&param_1, param_1);
  local_4 = 0;
  SetPlugId(this, pCVar1);
  local_4 = 0xffffffff;
  CScene2d::OnNodLoaded((CScene2d *)&param_1);
  ExceptionList = local_c;
  return;
}

/* public: void __thiscall CPlugTree::SetIsPickableVisual(int) */

void __thiscall CPlugTree::SetIsPickableVisual(CPlugTree *this, int param_1)

{
  *(uint *)(this + 0x9c) =
      *(uint *)(this + 0x9c) ^
      ((uint)(param_1 != 0) << 0xb ^ *(uint *)(this + 0x9c)) & 0x800;
  return;
}

/* public: void __thiscall CPlugTree::SetIsRooted(int) */

void __thiscall CPlugTree::SetIsRooted(CPlugTree *this, int param_1)

{
  *(uint *)(this + 0x9c) =
      *(uint *)(this + 0x9c) ^
      ((uint)(param_1 != 0) << 0xf ^ *(uint *)(this + 0x9c)) & 0x8000;
  if ((param_1 != 0) && (*(CPlugSolid **)(this + 0x14) != (CPlugSolid *)0x0)) {
    CPlugSolid::MakeTreeIdsUnique(*(CPlugSolid **)(this + 0x14));
  }
  return;
}

/* public: void __thiscall CPlugTree::SetIsVisible(int) */

void __thiscall CPlugTree::SetIsVisible(CPlugTree *this, int param_1)

{
  *(uint *)(this + 0x9c) =
      *(uint *)(this + 0x9c) ^
      ((uint)(param_1 != 0) * 8 ^ *(uint *)(this + 0x9c)) & 8;
  return;
}

/* public: void __thiscall CPlugTree::SetLocation(class GmTransQuat const &) */

void __thiscall CPlugTree::SetLocation(CPlugTree *this, GmTransQuat *param_1)

{
  GmIso4::Set((GmIso4 *)(this + 0x5c), param_1);
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x10000;
  return;
}

/* public: void __thiscall CPlugTree::SetLocation(class GmIso4 const &) */

void __thiscall CPlugTree::SetLocation(CPlugTree *this, GmIso4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;

  puVar2 = (undefined4 *)(this + 0x5c);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *(undefined4 *)param_1;
    param_1 = (GmIso4 *)((int)param_1 + 4);
    puVar2 = puVar2 + 1;
  }
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x10000;
  return;
}

/* public: void __thiscall CPlugTree::SetMaterial(class CPlugMaterial *) */

void __thiscall CPlugTree::SetMaterial(CPlugTree *this, CPlugMaterial *param_1)

{
  CPlugShader *this_00;

  if ((*(int *)(this + 0x94) != 0) &&
      (param_1 != *(CPlugMaterial **)(this + 0x98))) {
    if (param_1 != (CPlugMaterial *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1);
    }
    if (*(CMwNod **)(this + 0x98) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x98));
    }
    *(CPlugMaterial **)(this + 0x98) = param_1;
    if ((param_1 != (CPlugMaterial *)0x0) &&
        (this_00 = CPlugMaterial::GetSupportedShader(param_1),
         this_00 != *(CPlugShader **)(this + 0x94))) {
      if (this_00 != (CPlugShader *)0x0) {
        CMwNod::MwAddRef((CMwNod *)this_00);
      }
      if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x94));
      }
      *(CPlugShader **)(this + 0x94) = this_00;
    }
  }
  return;
}

/* public: void __thiscall CPlugTree::SetPlugId(class CMwId const &) */

void __thiscall CPlugTree::SetPlugId(CPlugTree *this, CMwId *param_1)

{
  int iVar1;
  CPlugTree *extraout_ECX;

  iVar1 = GetIsRooted(this);
  *(undefined4 *)(extraout_ECX + 0x18) = *(undefined4 *)param_1;
  if ((iVar1 != 0) &&
      (*(CPlugSolid **)(extraout_ECX + 0x14) != (CPlugSolid *)0x0)) {
    CPlugSolid::InternalConnectSubTree(*(CPlugSolid **)(extraout_ECX + 0x14),
                                       extraout_ECX);
    return;
  }
  return;
}

/* public: void __thiscall CPlugTree::SetRotation(class GmMat3 const &) */

void __thiscall CPlugTree::SetRotation(CPlugTree *this, GmMat3 *param_1)

{
  GmMat3::Set((GmMat3 *)(this + 0x5c), param_1);
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x10000;
  return;
}

/* public: void __thiscall CPlugTree::SetShader(class CPlugShader *) */

void __thiscall CPlugTree::SetShader(CPlugTree *this, CPlugShader *param_1)

{
  int iVar1;

  if ((*(CPlugShader **)(this + 0x94) != (CPlugShader *)0x0) &&
      (*(CPlugShader **)(this + 0x94) != param_1)) {
    if (param_1 != (CPlugShader *)0x0) {
      (**(code **)(*(int *)param_1 + 0xa8))();
    }
    if (param_1 != *(CPlugShader **)(this + 0x94)) {
      if (param_1 != (CPlugShader *)0x0) {
        CMwNod::MwAddRef((CMwNod *)param_1);
      }
      if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x94));
      }
      *(CPlugShader **)(this + 0x94) = param_1;
    }
    if (((*(CPlugMaterial **)(this + 0x98) != (CPlugMaterial *)0x0) &&
         (iVar1 = CPlugMaterial::DoesContainShader(
              *(CPlugMaterial **)(this + 0x98), param_1, (ulong *)0x0),
          iVar1 == 0)) &&
        (*(CMwNod **)(this + 0x98) != (CMwNod *)0x0)) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x98));
      *(undefined4 *)(this + 0x98) = 0;
    }
  }
  return;
}

/* public: void __thiscall CPlugTree::SetSubVisualIndex(unsigned long,unsigned
 * long,float) */

void __thiscall CPlugTree::SetSubVisualIndex(CPlugTree *this, ulong param_1,
                                             ulong param_2, float param_3)

{
  float fVar1;

  fVar1 = param_3 * 255.0;
  *(ulong *)(this + 0x54) = (param_2 & 0xfff) << 0xc |
                            *(uint *)(this + 0x54) & 0xff000000 |
                            param_1 & 0xfff;
  if (fVar1 < 0.0 == (fVar1 == 0.0)) {
    if (255.0 <= fVar1) {
      fVar1 = 255.0;
    }
  } else {
    fVar1 = 0.0;
  }
  param_1._0_1_ = SUB41((int)ROUND(fVar1), 0);
  this[0x57] = param_1._0_1_;
  return;
}

/* public: void __thiscall CPlugTree::SetSurface(class CPlugSurface *) */

void __thiscall CPlugTree::SetSurface(CPlugTree *this, CPlugSurface *param_1)

{
  if (param_1 != *(CPlugSurface **)(this + 0x8c)) {
    if (param_1 != (CPlugSurface *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1);
    }
    if (*(CMwNod **)(this + 0x8c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x8c));
    }
    *(CPlugSurface **)(this + 0x8c) = param_1;
  }
  return;
}

/* public: void __thiscall CPlugTree::SetTranslation(class GmVec3 const &) */

void __thiscall CPlugTree::SetTranslation(CPlugTree *this, GmVec3 *param_1)

{
  *(undefined4 *)(this + 0x80) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 8);
  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x10000;
  return;
}

/* public: void __thiscall CPlugTree::SetUseLocation(int) */

void __thiscall CPlugTree::SetUseLocation(CPlugTree *this, int param_1)

{
  *(uint *)(this + 0x9c) =
      (param_1 != 0 | 0x4000) * 4 | *(uint *)(this + 0x9c) & 0xfffffffb;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall CPlugTree::SetVisual(class CPlugVisual *,class
   CPlugShader *,class CPlugMaterial *,int) */

void __thiscall CPlugTree::SetVisual(CPlugTree *this, CPlugVisual *param_1,
                                     CPlugShader *param_2,
                                     CPlugMaterial *param_3, int param_4)

{
  CFastBuffer<> *this_00;
  CFastBuffer<> *this_01;
  int iVar1;
  uint uVar2;
  ulong uVar3;
  CFastBuffer<> *this_02;
  SKey *pSVar4;
  SKey *this_03;
  CPlugShader *this_04;
  int iVar5;
  int *piVar6;
  CSystemEngine **ppCVar7;
  CMwNod *this_05;
  int iVar8;
  ulong uVar9;
  CPlugMaterial *pCVar10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  pCVar10 = param_3;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad4eeb;
  local_c = ExceptionList;
  uVar2 = ___security_cookie ^ (uint)&stack0xffffffe4;
  ExceptionList = &local_c;
  if (((param_1 != *(CPlugVisual **)(this + 0x90)) ||
       ((param_2 != (CPlugShader *)0x0 &&
         (param_2 != *(CPlugShader **)(this + 0x94))))) ||
      ((param_3 != (CPlugMaterial *)0x0 &&
        (param_3 != *(CPlugMaterial **)(this + 0x98))))) {
    if (param_1 != *(CPlugVisual **)(this + 0x90)) {
      if (param_1 != (CPlugVisual *)0x0) {
        CMwNod::MwAddRef((CMwNod *)param_1);
      }
      if (*(CMwNod **)(this + 0x90) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x90));
      }
      *(CPlugVisual **)(this + 0x90) = param_1;
    }
    iVar5 = *(int *)(this + 0x90);
    if (iVar5 == 0) {
      if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x94));
        *(undefined4 *)(this + 0x94) = 0;
      }
      if (*(CMwNod **)(this + 0x98) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x98));
        *(undefined4 *)(this + 0x98) = 0;
      }
    } else {
      uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)(iVar5 + 0x20));
      if (uVar3 != 0) {
        uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)(iVar5 + 0x20));
        *(undefined2 *)(this + 0x54) = 0;
        *(short *)(this + 0x56) = (short)uVar3;
      }
      if (*(int *)(iVar5 + 0x50) != 0) {
        this_01 = *(CFastBuffer<> **)(this + 0xa4);
        if (this_01 != (CFastBuffer<> *)0x0) {
          CFastBuffer<>::~CFastBuffer<>(this_01);
          operator_delete(this_01);
        }
        this_02 = (CFastBuffer<> *)operator_new(0xc);
        if (this_02 == (CFastBuffer<> *)0x0) {
          this_02 = (CFastBuffer<> *)0x0;
        } else {
          CFastBuffer<>::CFastBuffer<>(this_02);
        }
        *(CFastBuffer<> **)(this + 0xa4) = this_02;
        this_00 =
            (CFastBuffer<> *)(*(int *)(*(int *)(this + 0x90) + 0x50) + 0xc);
        uVar3 = CFastBuffer<>::GetCount(this_00);
        CFastBuffer<>::AllocSetCount((CFastBuffer<> *)this_02, uVar3);
        uVar3 = CFastBuffer<>::GetCount(this_00);
        uVar9 = 0;
        pCVar10 = param_3;
        if (uVar3 != 0) {
          do {
            pSVar4 = CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar9);
            this_03 = CFastBuffer<>::operator[](
                *(CFastBuffer<> **)(this + 0xa4), uVar9);
            GmIso4::SetInverse((GmIso4 *)this_03, (GmIso4 *)pSVar4);
            uVar9 = uVar9 + 1;
            pCVar10 = param_3;
          } while (uVar9 < uVar3);
        }
      }
      if (pCVar10 == (CPlugMaterial *)0x0) {
        if (param_2 == (CPlugShader *)0x0) {
          if (*(int **)(this + 0x94) == (int *)0x0) {
            param_3 = (CPlugMaterial *)operator_new(0xa8);
            this_05 = (CMwNod *)0x0;
            local_4 = 0;
            if (param_3 != (CPlugMaterial *)0x0) {
              this_05 = (CMwNod *)CPlugShaderApply::CPlugShaderApply(
                  (CPlugShaderApply *)param_3);
            }
            local_4 = 0xffffffff;
            if (this_05 != *(CMwNod **)(this + 0x94)) {
              if (this_05 != (CMwNod *)0x0) {
                CMwNod::MwAddRef(this_05);
              }
              if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
                CMwNod::MwRelease(*(CMwNod **)(this + 0x94));
              }
              *(CMwNod **)(this + 0x94) = this_05;
            }
          } else {
            (**(code **)(**(int **)(this + 0x94) + 0x94))(uVar2);
          }
        } else if ((param_2 != *(CPlugShader **)(this + 0x94)) &&
                   ((**(code **)(*(int *)param_2 + 0xa8))(),
                    param_2 != *(CPlugShader **)(this + 0x94))) {
          CMwNod::MwAddRef((CMwNod *)param_2);
          if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
            CMwNod::MwRelease(*(CMwNod **)(this + 0x94));
          }
          *(CPlugShader **)(this + 0x94) = param_2;
        }
        if (((*(CPlugMaterial **)(this + 0x98) != (CPlugMaterial *)0x0) &&
             (iVar5 = CPlugMaterial::DoesContainShader(
                  *(CPlugMaterial **)(this + 0x98),
                  *(CPlugShader **)(this + 0x94), (ulong *)0x0),
              iVar5 == 0)) &&
            (*(CMwNod **)(this + 0x98) != (CMwNod *)0x0)) {
          CMwNod::MwRelease(*(CMwNod **)(this + 0x98));
          *(undefined4 *)(this + 0x98) = 0;
        }
      } else if (pCVar10 != (CPlugMaterial *)*(CMwNod **)(this + 0x98)) {
        CMwNod::MwAddRef((CMwNod *)pCVar10);
        if (*(CMwNod **)(this + 0x98) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(this + 0x98));
        }
        *(CPlugMaterial **)(this + 0x98) = pCVar10;
        if (pCVar10 != (CPlugMaterial *)0x0) {
          this_04 = CPlugMaterial::GetSupportedShader(pCVar10);
          if (this_04 != *(CPlugShader **)(this + 0x94)) {
            if (this_04 != (CPlugShader *)0x0) {
              CMwNod::MwAddRef((CMwNod *)this_04);
            }
            if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
              CMwNod::MwRelease(*(CMwNod **)(this + 0x94));
            }
            *(CPlugShader **)(this + 0x94) = this_04;
          }
          if (*(int *)(this + 0x94) == 0) {
            ExceptionList = local_c;
            return;
          }
        }
      }
      iVar5 = (**(code **)(**(int **)(this + 0x90) + 0x78))();
      if ((iVar5 == 7) &&
          ((*(byte *)(*(int *)(this + 0x90) + 0xb0) & 7) == 0)) {
        iVar5 = 1;
      } else {
        iVar5 = 0;
      }
      iVar1 = *(int *)(this + 0x94);
      iVar8 = 0;
      uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)(iVar1 + 0x2c));
      if (uVar3 != 0) {
        piVar6 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(CFastBuffer<> *)(iVar1 + 0x2c), 0);
        if ((*(int *)(*piVar6 + 0x3c) == 0) ||
            ((*(byte *)(*(int *)(*piVar6 + 0x3c) + 0xc4) & 0x10) == 0)) {
          iVar8 = 0;
        } else {
          iVar8 = 1;
        }
      }
      if (iVar5 != iVar8) {
        if (iVar5 == 0) {
          ChangeShaderClass(this, 0x9026000);
        } else {
          CSystemArchiveNod::LoadResource(0x4000001d, (CMwNod **)&param_3);
          ppCVar7 = (CSystemEngine **)CFastBuffer<>::operator[](
              (CFastBuffer<> *)(CMwEngineMain::TheMainEngine + 0x20), 0xb);
          CSystemEngine::UnbindFid(*ppCVar7, (CMwNod *)param_3);
          pCVar10 = param_3;
          if (param_3 != *(CPlugMaterial **)(this + 0x94)) {
            if (param_3 != (CPlugMaterial *)0x0) {
              CMwNod::MwAddRef((CMwNod *)param_3);
            }
            if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
              CMwNod::MwRelease(*(CMwNod **)(this + 0x94));
            }
            *(CPlugMaterial **)(this + 0x94) = pCVar10;
          }
        }
      }
      if (param_4 != 0) {
        (**(code **)(**(int **)(this + 0x90) + 0x7c))(
            *(undefined4 *)(this + 0x94));
      }
      if ((((*(byte *)(*(int *)(this + 0x94) + 0x29) & 1) != 0) &&
           (_s_SupportedDevice >> 0x10 < 3)) &&
          ((*(int **)(this + 0x90))[5] == 0)) {
        (**(code **)(**(int **)(this + 0x90) + 0xf4))(1);
      }
    }
  }
  ExceptionList = local_c;
  return;
}

/* public: virtual void __thiscall CPlugTree::TransformByNOMat(class GmIso4
 * const &) */

void __thiscall CPlugTree::TransformByNOMat(CPlugTree *this, GmIso4 *param_1)

{
  CPlugSurfaceGeom *this_00;
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 local_30[9];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  *(uint *)(this + 0x9c) = *(uint *)(this + 0x9c) | 0x10000;
  if ((*(uint *)(this + 0x9c) & 4) == 0) {
    GmIso4::SetIdentity((GmIso4 *)(this + 0x5c));
    SetUseLocation(this, 1);
  }
  puVar4 = (undefined4 *)param_1;
  puVar6 = local_30;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  local_4 = 0;
  local_8 = 0;
  local_c = 0;
  GmVec3::Mult((GmVec3 *)(this + 0x80), param_1);
  if (*(int **)(this + 0x90) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x90) + 0x108))(local_30);
  }
  if ((*(int *)(this + 0x8c) != 0) &&
      (this_00 = *(CPlugSurfaceGeom **)(*(int *)(this + 0x8c) + 0x14),
       this_00 != (CPlugSurfaceGeom *)0x0)) {
    CPlugSurfaceGeom::TransformByNOMat(this_00, (GmIso4 *)local_30);
  }
  uVar1 = (**(code **)(*(int *)this + 0x7c))();
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)(**(code **)(*(int *)this + 0x80))(uVar5);
      (**(code **)(*piVar2 + 0xc4))(&stack0xffffffcc);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  return;
}

/* public: virtual int __thiscall CPlugTree::UpdateBoundingBox(int) */

int __thiscall CPlugTree::UpdateBoundingBox(CPlugTree *this, int param_1)

{
  uint uVar1;
  int iVar2;
  int unaff_EBX;
  uint uVar3;
  int unaff_EBP;
  int *piVar4;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;

  uVar1 = (**(code **)(*(int *)this + 0x7c))();
  iVar2 = (**(code **)(*(int *)this + 0xcc))(param_1, &iStack_18);
  if (iVar2 == 0) {
    if (uVar1 == 0) {
      *(undefined4 *)(this + 0x3c) = 0;
      *(undefined4 *)(this + 0x38) = 0;
      *(undefined4 *)(this + 0x34) = 0;
      *(undefined4 *)(this + 0x40) = 0xbf800000;
      *(undefined4 *)(this + 0x44) = 0xbf800000;
      *(undefined4 *)(this + 0x48) = 0xbf800000;
      return ~(*(uint *)(this + 0x9c) >> 3) & 1;
    }
    uVar3 = 0;
    piVar4 = (int *)0x0;
    if (uVar1 != 0) {
      do {
        piVar4 = (int *)(**(code **)(*(int *)this + 0x80))(uVar3);
        iVar2 = (**(code **)(*piVar4 + 0xbc))(uStack_8);
        if ((iVar2 != 0) && (0.0 <= (float)piVar4[0x10]))
          break;
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar1);
    }
    if (uVar3 == uVar1) {
      *(undefined4 *)(this + 0x3c) = 0;
      *(undefined4 *)(this + 0x38) = 0;
      *(undefined4 *)(this + 0x34) = 0;
      *(undefined4 *)(this + 0x40) = 0xbf800000;
      *(undefined4 *)(this + 0x44) = 0xbf800000;
      *(undefined4 *)(this + 0x48) = 0xbf800000;
      return 0;
    }
    uVar3 = uVar3 + 1;
    unaff_EBP = piVar4[0xd];
    unaff_EBX = piVar4[0xe];
    iStack_18 = piVar4[0xf];
    iStack_14 = piVar4[0x10];
    iStack_10 = piVar4[0x11];
    iStack_c = piVar4[0x12];
  } else {
    uVar3 = 0;
  }
  for (; uVar3 < uVar1; uVar3 = uVar3 + 1) {
    piVar4 = (int *)(**(code **)(*(int *)this + 0x80))(uVar3);
    iVar2 = (**(code **)(*piVar4 + 0xbc))(uStack_8);
    if ((iVar2 != 0) && (0.0 <= (float)piVar4[0x10])) {
      GmBoxAligned::Union((GmBoxAligned *)&stack0xffffffe0,
                          (GmBoxAligned *)(piVar4 + 0xd));
    }
  }
  if (((byte)this[0x9c] & 4) != 0) {
    GmBoxAligned::SetMult((GmBoxAligned *)(this + 0x34),
                          (GmBoxAligned *)&stack0xffffffe0,
                          (GmIso4 *)(this + 0x5c));
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

/* public: virtual unsigned long __thiscall CPlugTree::VirtualParam_Get(class
   CMwStack *,class CMwValueStd *) */

ulong __thiscall CPlugTree::VirtualParam_Get(CPlugTree *this, CMwStack *param_1,
                                             CMwValueStd *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  GmVec3 *pGVar5;
  CFastBuffer<> *pCVar6;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 < 0x904f00d) {
    if (uVar3 == 0x904f00c) {
      iVar1 = *(int *)(this + 0x1c);
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (uint)(iVar1 != 0);
      return 0;
    }
    switch (uVar3) {
    case 0x904f001:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 3 & 1;
      return 0;
    case 0x904f002:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 7 & 1;
      return 0;
    case 0x904f003:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 0xf & 1;
      return 0;
    case 0x904f004:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 9 & 1;
      return 0;
    case 0x904f005:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 10 & 1;
      return 0;
    case 0x904f006:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 2 & 1;
      return 0;
    case 0x904f007:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 0xe & 1;
      return 0;
    case 0x904f008:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 8 & 1;
      return 0;
    case 0x904f009:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 6 & 1;
      return 0;
    case 0x904f00a:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 0xb & 1;
      return 0;
    case 0x904f00b:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) & 1;
      return 0;
    }
  } else {
    if (0x904f014 < uVar3) {
      if (uVar3 < 0x904f01e) {
        if (uVar3 != 0x904f01d) {
          if (uVar3 == 0x904f015) {
            *(CMwValueStd **)param_2 = param_2 + 4;
            *(uint *)(param_2 + 4) = (uint) * (ushort *)(this + 0x56);
            return 0;
          }
          goto switchD_0084af77_caseD_b;
        }
        pGVar5 = (GmVec3 *)(this + 0x34);
      } else {
        if (uVar3 != 0x904f01e) {
          if (uVar3 == 0x904f01f) {
            pCVar6 = *(CFastBuffer<> **)(this + 0xa4);
            if (pCVar6 == (CFastBuffer<> *)0x0) {
              pCVar6 = (CFastBuffer<> *)&DAT_00d6e6a8;
            }
            CMwParamFastBuffer<>::GetValue(pCVar6, param_1, param_2);
            return 0;
          }
          if (uVar3 == 0xffffffff) {
            return 0;
          }
          goto switchD_0084af77_caseD_b;
        }
        pGVar5 = (GmVec3 *)(this + 0x40);
      }
      CMwParamVec3::GetValue(pGVar5, param_1, param_2);
      return 0;
    }
    if (uVar3 == 0x904f014) {
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (uint) * (ushort *)(this + 0x54);
      return 0;
    }
    switch (uVar3) {
    case 0x904f00d:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 0xd & 1;
      return 0;
    case 0x904f00e:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x9c) >> 0xc & 1;
      return 0;
    case 0x904f011:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x54) & 0xfff;
      return 0;
    case 0x904f012:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = *(uint *)(this + 0x54) >> 0xc & 0xfff;
      return 0;
    case 0x904f013:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = (float)(uint)(byte)this[0x57] / 255.0;
      return 0;
    }
  }
switchD_0084af77_caseD_b:
  *(int *)(param_1 + 0x18) = iVar1;
  uVar4 = CMwNod::VirtualParam_Get((CMwNod *)this, param_1, param_2);
  return uVar4;
}

/* public: virtual unsigned long __thiscall CPlugTree::VirtualParam_Set(class
 * CMwStack *,void *) */

ulong __thiscall CPlugTree::VirtualParam_Set(CPlugTree *this, CMwStack *param_1,
                                             void *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  void *pvVar4;
  CPlugShader *this_00;
  uint uVar5;
  int iVar6;
  ulong uVar7;
  void *pvVar8;
  uint uVar9;
  float fVar10;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = (*(int **)(param_1 + 0x10))[iVar1];
  iVar6 = iVar1 + -1;
  *(int *)(param_1 + 0x18) = iVar6;
  uVar9 = *(uint *)(iVar2 + 4);
  if (uVar9 < 0x904f012) {
    if (uVar9 == 0x904f011) {
      /* WARNING: Load size is inaccurate */
      uVar9 = *param_2;
      uVar5 = CFastBuffer<>::GetCount(
          (CFastBuffer<> *)(*(int *)(this + 0x90) + 100));
      if (uVar5 != 0) {
        uVar5 = uVar5 - 1;
      }
      if (uVar9 <= uVar5) {
        uVar5 = uVar9;
      }
      *(uint *)(this + 0x54) =
          *(uint *)(this + 0x54) ^ (*(uint *)(this + 0x54) ^ uVar5) & 0xfff;
      return 0;
    }
    switch (uVar9) {
    case 0x904f001:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x9c) =
          *(uint *)(this + 0x9c) ^
          ((uint)(*param_2 != 0) * 8 ^ *(uint *)(this + 0x9c)) & 8;
      return 0;
    case 0x904f002:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x9c) =
          *(uint *)(this + 0x9c) ^
          ((uint)(*param_2 != 0) << 7 ^ *(uint *)(this + 0x9c)) & 0x80;
      return 0;
    case 0x904f003:
      /* WARNING: Load size is inaccurate */
      SetIsRooted(this, *param_2);
      return 0;
    case 0x904f004:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x9c) =
          *(uint *)(this + 0x9c) ^
          ((uint)(*param_2 != 0) << 9 ^ *(uint *)(this + 0x9c)) & 0x200;
      return 0;
    case 0x904f005:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x9c) =
          *(uint *)(this + 0x9c) ^
          ((uint)(*param_2 != 0) << 10 ^ *(uint *)(this + 0x9c)) & 0x400;
      return 0;
    case 0x904f006:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x9c) =
          *(uint *)(this + 0x9c) ^
          ((uint)(*param_2 != 0) * 4 ^ *(uint *)(this + 0x9c)) & 4;
      return 0;
    case 0x904f007:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x9c) =
          *(uint *)(this + 0x9c) ^
          ((uint)(*param_2 != 0) << 0xe ^ *(uint *)(this + 0x9c)) & 0x4000;
      return 0;
    case 0x904f008:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x9c) =
          *(uint *)(this + 0x9c) ^
          ((uint)(*param_2 != 0) << 8 ^ *(uint *)(this + 0x9c)) & 0x100;
      return 0;
    case 0x904f009:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x9c) =
          *(uint *)(this + 0x9c) ^
          ((uint)(*param_2 != 0) << 6 ^ *(uint *)(this + 0x9c)) & 0x40;
      return 0;
    case 0x904f00a:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x9c) =
          *(uint *)(this + 0x9c) ^
          ((uint)(*param_2 != 0) << 0xb ^ *(uint *)(this + 0x9c)) & 0x800;
      return 0;
    case 0x904f00b:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x9c) =
          *(uint *)(this + 0x9c) ^
          ((uint)(*param_2 != 0) ^ *(uint *)(this + 0x9c)) & 1;
      return 0;
    default:
      goto switchD_0084cfeb_caseD_904f00c;
    case 0x904f00d:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x9c) =
          *(uint *)(this + 0x9c) ^
          ((uint)(*param_2 != 0) << 0xd ^ *(uint *)(this + 0x9c)) & 0x2000;
      return 0;
    case 0x904f00e:
      /* WARNING: Load size is inaccurate */
      *(uint *)(this + 0x9c) =
          *(uint *)(this + 0x9c) ^
          ((uint)(*param_2 != 0) << 0xc ^ *(uint *)(this + 0x9c)) & 0x1000;
      return 0;
    case 0x904f010:
      if (iVar6 < 0) {
        SetVisual(this, (CPlugVisual *)param_2, (CPlugShader *)0x0,
                  (CPlugMaterial *)0x0, 0);
        return 0;
      }
      if (((**(int **)(param_1 + 0x14) == 0) &&
           (uVar9 = *(uint *)(**(int **)(param_1 + 0x10) + 4),
            (uVar9 & 0xfffff000) == 0x9010000)) &&
          (iVar6 = CMwClassInfo::IsMwParamIdEqualName(
               &CPlugVisualSprite::m_MwClassInfo_CPlugVisualSprite, uVar9,
               "RenderMode", 1),
           iVar6 != 0)) {
        bVar3 = true;
        pvVar8 = (void *)(*(uint *)(*(int *)(this + 0x90) + 0xb0) & 7);
      } else {
        bVar3 = false;
        pvVar8 = param_2;
      }
      CMwParamClass::SetValue((CMwNod **)(this + 0x90), param_1, param_2);
      if (((bVar3) &&
           (pvVar4 = (void *)(*(uint *)(*(CMwNod **)(this + 0x90) + 0xb0) & 7),
            pvVar4 != pvVar8)) &&
          (pvVar4 != (void *)0x0)) {
        this_00 = ChangeShaderClass(this, 0x9026000);
        CPlugShader::RemovePasses(this_00);
        return 0;
      }
    }
  } else if (uVar9 < 0x904f019) {
    if (uVar9 == 0x904f018) {
      if (-1 < iVar6) {
        CMwParamClass::SetValue((CMwNod **)(this + 0x94), param_1, param_2);
        return 0;
      }
      if ((*(int *)(this + 0x94) != 0) && (param_2 != (void *)0x0)) {
        /* WARNING: Load size is inaccurate */
        iVar6 = (**(code **)(*param_2 + 0x10))(&DAT_09002000);
        if (iVar6 != 0) {
          SetShader(this, (CPlugShader *)param_2);
          return 0;
        }
        /* WARNING: Load size is inaccurate */
        iVar6 = (**(code **)(*param_2 + 0x10))(0x9079000);
        if (iVar6 != 0) {
          SetMaterial(this, (CPlugMaterial *)param_2);
          return 0;
        }
      }
    } else {
      switch (uVar9) {
      case 0x904f012:
        /* WARNING: Load size is inaccurate */
        uVar9 = *param_2;
        uVar5 = CFastBuffer<>::GetCount(
            (CFastBuffer<> *)(*(int *)(this + 0x90) + 100));
        if (uVar5 != 0) {
          uVar5 = uVar5 - 1;
        }
        if (uVar9 <= uVar5) {
          uVar5 = uVar9;
        }
        *(uint *)(this + 0x54) =
            *(uint *)(this + 0x54) ^
            (uVar5 << 0xc ^ *(uint *)(this + 0x54)) & 0xfff000;
        return 0;
      case 0x904f013:
        /* WARNING: Load size is inaccurate */
        fVar10 = GmFunc::ClampReal(*param_2 * 255.0, 0.0, 255.0);
        param_1._0_1_ = SUB41((int)ROUND(fVar10), 0);
        this[0x57] = param_1._0_1_;
        return 0;
      case 0x904f014:
        /* WARNING: Load size is inaccurate */
        uVar9 = *param_2;
        uVar5 = CFastBuffer<>::GetCount(
            (CFastBuffer<> *)(*(int *)(this + 0x90) + 0x20));
        if (uVar5 != 0) {
          uVar5 = uVar5 - 1;
        }
        if (uVar9 <= uVar5) {
          uVar5 = uVar9;
        }
        *(short *)(this + 0x54) = (short)uVar5;
        return 0;
      case 0x904f015:
        /* WARNING: Load size is inaccurate */
        uVar9 = *param_2;
        uVar7 = CFastBuffer<>::GetCount(
            (CFastBuffer<> *)(*(int *)(this + 0x90) + 0x20));
        if (1 < uVar9) {
          if (uVar7 <= uVar9) {
            uVar9 = uVar7;
          }
          *(short *)(this + 0x56) = (short)uVar9;
          return 0;
        }
        *(undefined2 *)(this + 0x56) = 1;
        return 0;
      case 0x904f016:
        if (-1 < iVar6) {
          CMwParamClass::SetValue((CMwNod **)(this + 0xa0), param_1, param_2);
          return 0;
        }
        if (param_2 == (void *)0x0) {
          SetGenerator(this, (CPlugTreeGenerator *)0x0, 0);
          return 0;
        }
        SetGenerator(this, (CPlugTreeGenerator *)param_2, 1);
        return 0;
      case 0x904f017:
        if (-1 < iVar6) {
          CMwParamClass::SetValue((CMwNod **)(this + 0x98), param_1, param_2);
          return 0;
        }
        if ((*(int *)(this + 0x94) != 0) && (param_2 != (void *)0x0)) {
          SetMaterial(this, (CPlugMaterial *)param_2);
          return 0;
        }
        break;
      default:
        goto switchD_0084cfeb_caseD_904f00c;
      }
    }
  } else if (uVar9 < 0x904f01d) {
    if (uVar9 != 0x904f01c) {
      if (uVar9 == 0x904f019) {
        if (-1 < iVar6) {
          CMwParamClass::SetValue((CMwNod **)(this + 0x8c), param_1, param_2);
          return 0;
        }
        SetSurface(this, (CPlugSurface *)param_2);
        return 0;
      }
      if (uVar9 == 0x904f01a) {
        (**(code **)(*(int *)this + 0xbc))(1);
        return 0;
      }
      if (uVar9 == 0x904f01b) {
        (**(code **)(*(int *)this + 0x78))(1);
        return 0;
      }
    switchD_0084cfeb_caseD_904f00c:
      *(int *)(param_1 + 0x18) = iVar1;
      uVar7 = CMwNod::VirtualParam_Set((CMwNod *)this, param_1, param_2);
      return uVar7;
    }
    if (iVar6 < 0) {
      SetFuncTree(this, (CFuncTree *)param_2);
      return 0;
    }
    if (*(CMwNod **)(this + 0xa8) != (CMwNod *)0x0) {
      CMwParamClass::SetValue((CMwNod **)(this + 0xa8), param_1, param_2);
      return 0;
    }
  } else if (uVar9 == 0x904f01f) {
    CMwParamFastBuffer<>::SetValue(*(CFastBuffer<> **)(this + 0xa4), param_1,
                                   param_2);
  } else if (uVar9 != 0xffffffff)
    goto switchD_0084cfeb_caseD_904f00c;
  return 0;
}

/* public: virtual unsigned long __thiscall CPlugTree::VirtualParam_Sub(class
 * CMwStack *,void *) */

ulong __thiscall CPlugTree::VirtualParam_Sub(CPlugTree *this, CMwStack *param_1,
                                             void *param_2)

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
      /* WARNING: Load size is inaccurate */
      (**(code **)(*(int *)this + 0x9c))(*param_2);
      return 0;
    }
    CMwParamFastBuffer<>::SubValue((CFastBuffer<> *)(this + 0x28), param_1,
                                   param_2);
  } else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CMwNod::VirtualParam_Sub((CMwNod *)this, param_1, param_2);
    return uVar3;
  }
  return 0;
}

/* public: virtual __thiscall CPlugTree::~CPlugTree(void) */

void __thiscall CPlugTree::~CPlugTree(CPlugTree *this)

{
  CFastBuffer<> *this_00;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00ad4ebd;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 9;
  if (*(CMwNod **)(this + 0x1c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1c));
  }
  DeleteAllChilds(this);
  if (*(int *)(this + 0xc) != 0) {
    CMwNod::DependantSendMwIsKilled((CMwNod *)this);
  }
  if (*(void **)(this + 0x58) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x58));
  }
  this_00 = *(CFastBuffer<> **)(this + 0xa4);
  if (this_00 != (CFastBuffer<> *)0x0) {
    CFastBuffer<>::~CFastBuffer<>(this_00);
    operator_delete(this_00);
  }
  CPlugTreeMapShaderFill::SubTree(this);
  local_4._0_1_ = 8;
  if (*(CMwNod **)(this + 0xa8) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xa8));
  }
  local_4._0_1_ = 7;
  if (*(CMwNod **)(this + 0xa0) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xa0));
  }
  local_4._0_1_ = 6;
  if (*(CMwNod **)(this + 0x98) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x98));
  }
  local_4._0_1_ = 5;
  if (*(CMwNod **)(this + 0x94) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x94));
  }
  local_4._0_1_ = 4;
  if (*(CMwNod **)(this + 0x90) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x90));
  }
  local_4._0_1_ = 3;
  if (*(CMwNod **)(this + 0x8c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x8c));
  }
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x28));
  local_4._0_1_ = 1;
  CScene2d::OnNodLoaded((CScene2d *)(this + 0x20));
  local_4 = (uint)local_4._1_3_ << 8;
  CScene2d::OnNodLoaded((CScene2d *)(this + 0x18));
  local_4 = 0xffffffff;
  CPlug::~CPlug((CPlug *)this);
  ExceptionList = local_c;
  return;
}
