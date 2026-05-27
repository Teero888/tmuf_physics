// Class implementation: CMotionManagerWeathers

// =================================================
// Function: CMotionManagerWeathers::ChangeWeatherAt
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CMotionManagerWeathers::ChangeWeatherAt
          (CMotionManagerWeathers *this,CMotionManagerWeathers *param_1,ulong param_2)
{
{
  CMotionManagerWeathers *pCVar1;
  uint *puVar2;
  CSystemFid *pCVar3;
  bool bVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  uint uVar7;
  CMwNodRef<class_CGameCamera> *extraout_EAX;
  ulong uVar8;
  CMotionWeather *this_00;
  CSceneMobilClouds *this_01;
  CMwNodRef<class_CGameCamera> *extraout_EAX_00;
  CMwNodRef<class_CGameCamera> *pCVar9;
  CMotionWeather *extraout_EAX_01;
  CSystemFid *pCVar10;
  CSceneFxNod *pCVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  void *pvVar15;
  CLoadGeomDynaSprite *unaff_EBX;
  CScene *unaff_EBP;
  ulong unaff_ESI;
  undefined4 *puVar16;
  CMotionWeather *pCVar17;
  ulong unaff_EDI;
  undefined4 *puVar18;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar19;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000000c;
  undefined4 in_stack_00000018;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffff5c;
  TiXmlAttribute *in_stack_ffffff60;
  CMotionWeather *in_stack_ffffff64;
  CPlugVisualSprite *in_stack_ffffff68;
  CScene *this_02;
  CSceneFxNod *in_stack_ffffff70;
  CMotionWeather *in_stack_ffffff74;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffff78;
  CMotionWeather *pCVar20;
  CMotionWeather *local_80;
  CSceneMobilSnow *local_7c;
  CMotionWeather *pCStack_78;
  undefined1 local_74 [8];
  undefined1 local_6c [8];
  CPlugVisualSprite local_64 [12];
  CVisionViewportDx9 local_58 [8];
  undefined1 local_50 [20];
  CMotionWeather local_3c [12];
  undefined4 auStack_30 [9];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a987dd;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((*(int *)(this + 0xbc) != 1) || (iVar13 = *(int *)(this + 0xf0), iVar13 == 0)) {
    ExceptionList = (void *)param_2;
    return 0;
  }
  pCVar19 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x70);
  pCVar1 = this + 100;
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (pCVar1,(CFastBuffer<class_CCrystalFace*> *)
                             (DAT_00cca150 ^ (uint)&stack0xffffff4c));
  if (pCVar19 < pCVar5) {
    pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](pCVar1,pCVar19,unaff_EDI);
    pCVar11 = *(CSceneFxNod **)pSVar6;
    in_stack_ffffff70 = pCVar11;
  }
  else {
    pCVar11 = (CSceneFxNod *)0x0;
  }
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,in_stack_0000000c,unaff_ESI);
  pCVar17 = *(CMotionWeather **)pSVar6;
  iVar13 = *(int *)(iVar13 + 0x38);
  *(uint *)(iVar13 + 0xac) =
       *(uint *)(iVar13 + 0xac) ^ (*(uint *)(iVar13 + 0xac) ^ *(uint *)(pCVar17 + 0x48)) & 6;
  uVar7 = (*(uint *)(pCVar17 + 0x48) ^ *(uint *)(iVar13 + 0xac)) & 8 ^ *(uint *)(iVar13 + 0xac);
  *(uint *)(iVar13 + 0xac) = uVar7;
  *(uint *)(iVar13 + 0xac) = (*(uint *)(pCVar17 + 0x48) ^ uVar7) & 1 ^ uVar7;
  this_02 = *(CScene **)(*(int *)(this + 0xf0) + 0x14);
  *(undefined4 *)(this_02 + 0x148) = *(undefined4 *)(pCVar17 + 0xd0);
  if (*(int *)(this + 0x114) == 0) {
    *(undefined4 *)(this_02 + 0x14c) = *(undefined4 *)(this + 0x118);
    *(undefined4 *)(this_02 + 0x150) = *(undefined4 *)(this + 0x11c);
    uVar12 = *(undefined4 *)(this + 0x120);
  }
  else {
    *(undefined4 *)(this_02 + 0x14c) = *(undefined4 *)(iVar13 + 0x94);
    *(undefined4 *)(this_02 + 0x150) = *(undefined4 *)(iVar13 + 0x98);
    uVar12 = *(undefined4 *)(iVar13 + 0x9c);
  }
  *(undefined4 *)(this_02 + 0x154) = uVar12;
  pCVar20 = pCVar17;
  CScene::CameraPropertiesUpdate(this_02,unaff_EBP);
  if (pCVar11 == (CSceneFxNod *)0x0) {
    pCVar10 = (CSystemFid *)0x0;
  }
  else {
    pCVar10 = *(CSystemFid **)(pCVar11 + 0xbc);
  }
  pCVar3 = *(CSystemFid **)(pCVar17 + 0xbc);
  if (pCVar3 != pCVar10) {
    if (pCVar3 == (CSystemFid *)0x0) {
      (**(code **)(**(int **)(*(int *)(this + 0xf0) + 0x14) + 0x7c))();
    }
    else {
      pCVar1 = this + 0x10c;
      if (*(int *)(this + 0x10c) == 0) {
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                  (&local_7c,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_EBX);
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                  (local_6c,in_stack_ffffff5c);
        CSystemArchiveNod::LoadFromFid((CMwNod **)&stack0xffffff74,pCVar3,7);
        unaff_EBX = (CLoadGeomDynaSprite *)0x57244e;
        CFastBuffer<class_CDx9TextureKeeper*>::Add
                  (local_74,(TiXmlAttributeSet *)&stack0xffffff74,in_stack_ffffff60);
        local_80 = (CMotionWeather *)0x190;
        in_stack_ffffff5c = (CFastBuffer<class_CPlugFileSndGen*> *)0x572464;
        CFastBuffer<class_CDx9TextureKeeper*>::Add
                  (local_64,(TiXmlAttributeSet *)&local_80,(TiXmlAttribute *)in_stack_ffffff64);
        local_7c = operator_new(0x70);
        if (local_7c == (CSceneMobilSnow *)0x0) {
          pCVar9 = (CMwNodRef<class_CGameCamera> *)0x0;
        }
        else {
          CSceneMobilSnow::CSceneMobilSnow(local_7c,(CSceneMobilSnow *)in_stack_ffffff68);
          pCVar9 = extraout_EAX;
        }
        CMwNodRef<class_CGameCamera>::MwSetNod(pCVar1,pCVar9,(CGameCamera *)this_02);
        in_stack_ffffff68 = local_64;
        in_stack_ffffff64 = (CMotionWeather *)0x1;
        in_stack_ffffff60 = (TiXmlAttribute *)0x5724ac;
        CSceneMobilSnow::Init
                  (*(CSceneMobilSnow **)pCVar1,(CLoadGeomDynaSprite *)0x1,in_stack_ffffff68,local_58
                   ,(ESpriteColor0 *)in_stack_ffffff70);
        in_stack_ffffff70 = (CSceneFxNod *)0x5724b3;
        CSceneMobil::InstallRenderBeforeMechanism
                  (*(CSceneMobil **)pCVar1,(CSceneMobil *)in_stack_ffffff74);
        CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                  (local_50,in_stack_ffffff78);
        CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                  (local_58,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar20);
      }
      pvVar15 = *(void **)(this + 0xf0);
      in_stack_ffffff78 = *(CFastBuffer<class_CPlugFileGPUV*> **)pCVar1;
      puVar16 = (undefined4 *)PTR_DAT_00cdfd64;
      pCVar17 = local_3c;
      for (iVar13 = 0xc; iVar13 != 0; iVar13 = iVar13 + -1) {
        *(undefined4 *)pCVar17 = *puVar16;
        puVar16 = puVar16 + 1;
        pCVar17 = pCVar17 + 4;
      }
      pCVar20 = local_3c;
      in_stack_ffffff74 = (CMotionWeather *)0x5724ff;
      local_c = pvVar15;
      (**(code **)(**(int **)((int)pvVar15 + 0x14) + 0x78))();
      pCVar17 = local_80;
    }
  }
  iVar14 = DAT_00d54380;
  iVar13 = *(int *)(this + 0x110);
  pCVar1 = this + 0x110;
  if (((iVar13 == 0) || (in_stack_ffffff78 == (CFastBuffer<class_CPlugFileGPUV*> *)0x0)) ||
     (*(int *)(in_stack_ffffff78 + 0xe4) == 0)) {
LAB_0057255c:
    in_stack_ffffff74 = (CMotionWeather *)0x0;
  }
  else {
    uVar8 = CFastBuffer<class_CCrystalFace*>::GetCount
                      ((void *)(*(int *)(in_stack_ffffff78 + 0xe4) + 0x24),
                       (CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
    in_stack_ffffff78 = (CFastBuffer<class_CPlugFileGPUV*> *)0x1;
    if (uVar8 == 0) goto LAB_0057255c;
  }
  if (((*(int *)(pCVar17 + 0xe4) == 0) ||
      (uVar8 = CFastBuffer<class_CCrystalFace*>::GetCount
                         ((void *)(*(int *)(pCVar17 + 0xe4) + 0x24),
                          (CFastBuffer<class_CCrystalFace*> *)unaff_EBX), uVar8 == 0)) ||
     ((iVar14 == 0 || (*(int *)(iVar14 + 0x170) < 1)))) {
    pCVar20 = (CMotionWeather *)0x0;
    this_00 = (CMotionWeather *)0x0;
  }
  else {
    this_00 = (CMotionWeather *)0x1;
    local_80 = (CMotionWeather *)0x1;
  }
  if (this_00 == in_stack_ffffff74) {
LAB_0057267e:
    if ((this_00 != (CMotionWeather *)0x0) &&
       (*(CSceneMobilClouds **)pCVar1 != (CSceneMobilClouds *)0x0)) {
      CMotionWeather::ChangeClouds(*(CSceneMobilClouds **)pCVar1,(CFuncWeather *)pCVar17);
    }
  }
  else {
    if (this_00 != (CMotionWeather *)0x0) {
      this_00 = pCVar20;
      if (iVar13 == 0) {
        this_01 = operator_new(0x9c);
        if (this_01 == (CSceneMobilClouds *)0x0) {
          pCVar9 = (CMwNodRef<class_CGameCamera> *)0x0;
        }
        else {
          CSceneMobilClouds::CSceneMobilClouds(this_01,(CSceneMobilClouds *)unaff_EBX);
          pCVar9 = extraout_EAX_00;
        }
        CMwNodRef<class_CGameCamera>::MwSetNod(pCVar1,pCVar9,(CGameCamera *)unaff_EBX);
        unaff_EBX = *(CLoadGeomDynaSprite **)(pCVar17 + 0xe4);
        CSceneMobilClouds::Init
                  (*(CSceneMobilClouds **)pCVar1,unaff_EBX,(CPlugVisualSprite *)in_stack_ffffff5c,
                   (CVisionViewportDx9 *)in_stack_ffffff60,(ESpriteColor0 *)in_stack_ffffff64);
        this_00 = operator_new(0x38);
        if (this_00 == (CMotionWeather *)0x0) {
          in_stack_ffffff64 = (CMotionWeather *)0x0;
        }
        else {
          CMotionWeather::CMotionWeather(this_00,(CMotionWeather *)in_stack_ffffff68);
          in_stack_ffffff64 = extraout_EAX_01;
        }
        in_stack_ffffff68 = (CPlugVisualSprite *)0x0;
        in_stack_ffffff60 = (TiXmlAttribute *)0x572644;
        (**(code **)(**(int **)pCVar1 + 0xa8))();
      }
      iVar13 = *(int *)(this + 0xf0);
      puVar16 = (undefined4 *)PTR_DAT_00cdfd64;
      puVar18 = auStack_30;
      for (iVar14 = 0xc; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar18 = *puVar16;
        puVar16 = puVar16 + 1;
        puVar18 = puVar18 + 1;
      }
      (**(code **)(**(int **)(iVar13 + 0x14) + 0x78))();
      pCVar17 = local_80;
      goto LAB_0057267e;
    }
    (**(code **)(**(int **)(*(int *)(this + 0xf0) + 0x14) + 0x7c))();
  }
  if (in_stack_ffffff78 == (CFastBuffer<class_CPlugFileGPUV*> *)0x0) {
    pCVar10 = (CSystemFid *)0x0;
  }
  else {
    pCVar10 = *(CSystemFid **)(in_stack_ffffff78 + 0xc0);
  }
  pCVar3 = *(CSystemFid **)(pCVar17 + 0xc0);
  if ((pCVar3 != pCVar10) &&
     (pCVar11 = *(CSceneFxNod **)(in_stack_ffffff70 + 0x158), pCVar11 != (CSceneFxNod *)0x0)) {
    if (pCVar3 != (CSystemFid *)0x0) {
      pCVar10 = pCVar3;
    }
    CSystemArchiveNod::LoadFromFid((CMwNod **)&stack0xffffff70,pCVar10,7);
    pCVar11 = CSceneFxNod::NodFindFromFx(pCVar11,in_stack_ffffff70,(CSceneFx *)unaff_EBX);
    if (pCVar11 != (CSceneFxNod *)0x0) {
      unaff_EBX = (CLoadGeomDynaSprite *)(uint)(pCVar3 != (CSystemFid *)0x0);
      CSceneFxNod::StartStopSafe(pCVar11,(CSceneFxNod *)unaff_EBX,(int)in_stack_ffffff5c);
    }
  }
  puVar2 = (uint *)(*(int *)(this + 0xc4) + 0x14);
  *puVar2 = *puVar2 ^ ((uint)(*(int *)(this + 0xb4) != 0) * 4 ^
                      *(uint *)(*(int *)(this + 0xc4) + 0x14)) & 4;
  if (*(int *)(this + 0xb4) == 0) {
    pCVar20 = pCVar17 + 0xa4;
    if ((*(int *)(pCVar17 + 0xa8) == 0) && (*(int *)pCVar20 == 0)) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    puVar2 = (uint *)(*(int *)(this + 0xc4) + 0x14);
    *puVar2 = *puVar2 ^ ((uint)!bVar4 << 5 ^ *(uint *)(*(int *)(this + 0xc4) + 0x14)) & 0x20;
    *(uint *)(*(int *)(this + 0xc4) + 0x14) = *(uint *)(*(int *)(this + 0xc4) + 0x14) & 0xffffffef;
    *(undefined4 *)(*(int *)(this + 0xc4) + 100) = 0;
    if ((*(int *)(pCVar17 + 0xa8) == 0) && (*(int *)pCVar20 == 0)) goto LAB_0057280d;
    iVar13 = *(int *)(*(int *)(this + 200) + 0x30);
    unaff_EBX = (CLoadGeomDynaSprite *)
                CSysFidNodRef<class_CPlugMaterial>::GetNod
                          (pCVar20,(CSysFidNodRef<class_CPlugMaterial> *)unaff_EBX);
    pvVar15 = (void *)(iVar13 + 0x6c);
  }
  else {
    *(uint *)(*(int *)(this + 0xc4) + 0x14) = *(uint *)(*(int *)(this + 0xc4) + 0x14) & 0xffffffdf;
    uVar12 = _DAT_00b58c48;
    pCVar20 = pCVar17 + 0x9c;
    if ((*(int *)(pCVar17 + 0xa0) == 0) && (*(int *)pCVar20 == 0)) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    puVar2 = (uint *)(*(int *)(this + 0xc4) + 0x14);
    *puVar2 = *puVar2 ^ ((uint)!bVar4 << 4 ^ *(uint *)(*(int *)(this + 0xc4) + 0x14)) & 0x10;
    *(undefined4 *)(*(int *)(this + 0xc4) + 100) = uVar12;
    if ((*(int *)(pCVar17 + 0xa0) == 0) && (*(int *)pCVar20 == 0)) goto LAB_0057280d;
    iVar13 = *(int *)(*(int *)(this + 200) + 0x30);
    unaff_EBX = (CLoadGeomDynaSprite *)
                CSysFidNodRef<class_CPlugMaterial>::GetNod
                          (pCVar20,(CSysFidNodRef<class_CPlugMaterial> *)unaff_EBX);
    pvVar15 = (void *)(iVar13 + 0x68);
  }
  CMwNodRef<class_CGameCamera>::MwSetNod
            (pvVar15,(CMwNodRef<class_CGameCamera> *)unaff_EBX,(CGameCamera *)in_stack_ffffff5c);
LAB_0057280d:
  pCVar19 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  *(undefined4 *)(this + 0x104) = 0;
  *(undefined4 *)(this + 0x108) = 0;
  uVar8 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this + 0x74,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
  if (uVar8 != 0) {
    do {
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x74,pCVar19,(ulong)in_stack_ffffff5c);
      pCVar17 = *(CMotionWeather **)pSVar6;
      CMotionWeather::OnWeatherChange
                (pCVar17,pCStack_78,*(CFuncWeather **)(this + 0xb4),(EDayTime4)in_stack_ffffff60);
      in_stack_ffffff5c = (CFastBuffer<class_CPlugFileSndGen*> *)0x572856;
      CMotionWeather::GetSkyGradVBitmapAdr
                (pCVar17,(CMotionWeather *)(this + 0x104),(CPlugBitmapAddress **)in_stack_ffffff64);
      in_stack_ffffff64 = (CMotionWeather *)(this + 0x108);
      in_stack_ffffff60 = (TiXmlAttribute *)0x572864;
      CMotionWeather::GetTreeStars(pCVar17,in_stack_ffffff64,(CPlugTree **)in_stack_ffffff68);
      pCVar19 = pCVar19 + 1;
    } while (pCVar19 < local_7c);
  }
  *(undefined4 *)(this + 0x70) = in_stack_00000018;
  if (*(int *)(this + 0xfc) != 0) {
    (**(code **)(*(int *)this + 0x74))();
  }
  ExceptionList = (void *)param_2;
  return 1;
}
}

// =================================================
// Function: CMotionManagerWeathers::UpdateAsync
// =================================================
/* WARNING: Removing unreachable block (ram,0x0057400b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionManagerWeathers::UpdateAsync(CMotionManagerWeathers *this,CInputPortDx8 *param_1)
{
{
  uint *puVar1;
  CPlugFileGen *this_00;
  float fVar2;
  CMwCmdScriptVarBool *pCVar3;
  CPlugFileGen *this_01;
  CMotionWeather *this_02;
  CMwNod *this_03;
  float *pfVar4;
  byte bVar5;
  bool bVar6;
  ulong uVar7;
  int iVar8;
  GxLight *pGVar9;
  CSceneLight *pCVar10;
  CHmsViewport *pCVar11;
  CMwCmdScriptVarBool *pCVar12;
  SCasterCat *pSVar13;
  CPlugMaterial *pCVar14;
  GxBGRAColor_conflict *pGVar15;
  CFastBuffer<class_CCrystalFace*> *pCVar16;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar17;
  uint uVar18;
  CPlugBitmapAddress *pCVar19;
  GmVec4 *pGVar20;
  ulong uVar21;
  CHmsViewport *this_04;
  void *extraout_ECX;
  void *this_05;
  GxLight *unaff_EBX;
  CMotionTimerLoop *unaff_EBP;
  ulong unaff_ESI;
  CMwCmdScriptVarBool *pCVar22;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar23;
  CSystemWindow *unaff_EDI;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  GxBGRAColor_conflict *pGVar24;
  CMotionWeather *pCVar25;
  GmVec3 *in_stack_fffffed8;
  CMotionWeather *pCVar26;
  GxFogBlender *pGVar27;
  float in_stack_fffffedc;
  EGxTexAddress EVar28;
  EDayTime4 EVar29;
  CPlugTree **ppCVar30;
  CPlugMaterial *in_stack_fffffee0;
  CMwCmdScriptVarBool *in_stack_fffffee4;
  CPlugFileGen *in_stack_fffffee8;
  CPlugShader *in_stack_fffffeec;
  CFastArray<float*> *pCVar31;
  CMwCmdScriptVarBool *in_stack_fffffef0;
  CSceneSector *in_stack_fffffef4;
  CMwNod *pCVar32;
  CFastArray<float*> *pCVar33;
  CMotionWeather *in_stack_fffffef8;
  CMwId *pCVar34;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar35;
  CPlugMaterial *pCVar36;
  CPlugFileImg *pCVar37;
  ulong *puVar38;
  GxBGRAColor_conflict *pGVar39;
  CMwNod *pCVar40;
  CMwCmdScriptVarBool *pCVar41;
  CPlugFileImg *pCVar42;
  CMwCmdScriptVarBool *this_06;
  CSysFidNodRef<class_CPlugMaterial> *in_stack_ffffff14;
  SHeaderCommunity *pSVar43;
  CPlugFileImg *in_stack_ffffff18;
  EGxTexAddress in_stack_ffffff1c;
  CSysFidNodRef<class_CPlugMaterial> *pCVar44;
  GxBGRAColor_conflict *pGVar45;
  undefined4 uVar46;
  CPlugFileImg *in_stack_ffffff24;
  GxBGRAColor_conflict *pGVar47;
  EGxTexAddress in_stack_ffffff28;
  CSysFidNodRef<class_CPlugMaterial> *in_stack_ffffff2c;
  SParam *pSVar48;
  CPlugFileImg *pCVar49;
  float in_stack_ffffff38;
  SParam *pSVar50;
  CMotionManagerWeathers *pCVar51;
  SParam *in_stack_ffffff40;
  float fVar52;
  float fVar53;
  GmIso3 *in_stack_ffffff44;
  SParam *in_stack_ffffff48;
  CMwCmdScriptVarBool *pCStack_b4;
  CMwCmdScriptVarBool *pCStack_b0;
  float fStack_ac;
  CMwCmdScriptVarBool *pCStack_a8;
  float fStack_a4;
  CMwCmdScriptVarBool *pCStack_a0;
  CMwCmdScriptVarBool *pCStack_9c;
  SHeaderCommunity *pSStack_98;
  float fStack_94;
  int iStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  float fStack_80;
  float afStack_7c [7];
  float fStack_60;
  float fStack_5c;
  undefined4 uStack_58;
  GmMat3 aGStack_54 [8];
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined1 auStack_18 [12];
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a98876;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar51 = this + 100;
  pCVar35 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x572c69;
  uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (pCVar51,(CFastBuffer<class_CCrystalFace*> *)
                             (DAT_00cca150 ^ (uint)&stack0xffffff04));
  if (uVar7 == 0) {
    ExceptionList = local_8;
    return;
  }
  iVar8 = (**(code **)(*(int *)this + 0x80))();
  if (iVar8 == 0) {
    ExceptionList = local_8;
    return;
  }
  if (*(int *)(this + 0xbc) == 2) {
    ExceptionList = local_8;
    return;
  }
  if (*(int *)(this + 0xbc) == 0) {
    pGVar9 = Sector_GetGxLight(*(CSceneSector **)(this + 0xf0),0);
    in_stack_fffffef4 = *(CSceneSector **)(this + 0xf0);
    in_stack_fffffef8 = (CMotionWeather *)0x1;
    *(GxLight **)(this + 0xc0) = pGVar9;
    pGVar9 = Sector_GetGxLight(in_stack_fffffef4,1);
    in_stack_fffffeec = *(CPlugShader **)(this + 0xf0);
    in_stack_fffffef0 = (CMwCmdScriptVarBool *)0x1;
    *(GxLight **)(this + 0xc4) = pGVar9;
    in_stack_fffffee8 = (CPlugFileGen *)0x572cd4;
    pCVar10 = Sector_GetLight((CSceneSector *)in_stack_fffffeec,1);
    *(CSceneLight **)(this + 200) = pCVar10;
    if (*(int *)(this + 0xc0) == 0) {
      ExceptionList = local_8;
      return;
    }
    if (*(int *)(this + 0xc4) == 0) {
      ExceptionList = local_8;
      return;
    }
    if (pCVar10 == (CSceneLight *)0x0) {
      ExceptionList = local_8;
      return;
    }
    pCVar35 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x572d03;
    pCVar11 = CHmsViewport::FindOrCreateViewport(this_04,(CVisionEngine *)0x0,unaff_EDI);
    *(CHmsViewport **)(this + 0xf4) = pCVar11;
    if (*(int *)(*(int *)(this + 0xf0) + 0x14) == 0) {
      ExceptionList = local_8;
      return;
    }
    if (pCVar11 == (CHmsViewport *)0x0) {
      ExceptionList = local_8;
      return;
    }
    *(undefined4 *)(this + 0xbc) = 1;
  }
  pCStack_9c = *(CMwCmdScriptVarBool **)(*(int *)(this + 0xf0) + 0x38);
  uStack_8c = *(undefined4 *)(this + 0xb0);
  pCVar44 = *(CSysFidNodRef<class_CPlugMaterial> **)(this + 0xb4);
  pCVar3 = *(CMwCmdScriptVarBool **)(this + 0x70);
  pCStack_a0 = pCVar3;
  pCVar12 = (CMwCmdScriptVarBool *)
            CFastBuffer<class_CCrystalFace*>::GetCount
                      (pCVar51,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
  if (pCVar12 <= pCVar3) {
    *(undefined4 *)(this + 0x70) = 0;
  }
  pGVar39 = *(GxBGRAColor_conflict **)(this + 0x70);
  pCVar37 = (CPlugFileImg *)0x572d6e;
  pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      (pCVar51,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar39,unaff_ESI);
  pCVar3 = *(CMwCmdScriptVarBool **)pSVar13;
  pCStack_9c = pCVar3;
  if (*(CMotionTimerLoop **)(this + 0x1c) == (CMotionTimerLoop *)0x0) {
    pCStack_a8 = (CMwCmdScriptVarBool *)0x0;
    this_05 = (void *)0x0;
  }
  else {
    pCStack_a8 = (CMwCmdScriptVarBool *)
                 CMotionTimerLoop::GetNormedTime(*(CMotionTimerLoop **)(this + 0x1c),unaff_EBP);
    this_05 = extraout_ECX;
  }
  if (((float)pCStack_a8 < *(float *)(this + 0x24)) || (*(float *)(this + 0x28) < (float)pCStack_a8)
     ) {
    *(undefined4 *)(this + 0xb0) = 0;
    *(undefined4 *)(this + 0xb4) = 0;
    in_stack_ffffff38 = (*(float *)(this + 0x24) + 1.0) - *(float *)(this + 0x28);
    pSVar48 = (SParam *)((*(float *)(this + 0x28) + *(float *)(this + 0x24)) * (float)_DAT_00b313b8)
    ;
    if ((float)pCStack_a8 <= (float)pSVar48) {
      in_stack_ffffff40 = (SParam *)0x0;
      fVar52 = (1.0 - *(float *)(this + 0x28)) + (float)pCStack_a8;
    }
    else {
      in_stack_ffffff40 = (SParam *)0x3f800000;
      fVar52 = (float)pCStack_a8 - *(float *)(this + 0x28);
    }
    fVar52 = (fVar52 * (float)_DAT_00b3d298) / in_stack_ffffff38;
LAB_00572ed0:
    *(float *)(this + 0xb8) = fVar52;
  }
  else {
    pSVar48 = (SParam *)
              (((float)pCStack_a8 - *(float *)(this + 0x24)) /
              (*(float *)(this + 0x28) - *(float *)(this + 0x24)));
    GmFunc::Saturate(this_05,pSVar48);
    in_stack_ffffff44 = (GmIso3 *)(float)extraout_ST0;
    if (*(float *)(this + 0x2c) <= (float)in_stack_ffffff44) {
      if (1.0 - *(float *)(this + 0x2c) <= (float)in_stack_ffffff44) {
        *(undefined4 *)(this + 0xb0) = 0;
        *(undefined4 *)(this + 0xb4) = 3;
        fVar52 = ((((float)in_stack_ffffff44 - 1.0) + *(float *)(this + 0x2c)) /
                 *(float *)(this + 0x2c)) * (float)_DAT_00b3d298 + (float)_DAT_00b5b5d0;
      }
      else {
        *(undefined4 *)(this + 0xb0) = 1;
        *(undefined4 *)(this + 0xb4) = 2;
        fVar52 = (((float)in_stack_ffffff44 - *(float *)(this + 0x2c)) /
                 (1.0 - *(float *)(this + 0x2c))) * (float)_DAT_00b3d298 + (float)_DAT_00b313b8;
      }
      goto LAB_00572ed0;
    }
    *(undefined4 *)(this + 0xb0) = 0;
    *(undefined4 *)(this + 0xb4) = 1;
    *(float *)(this + 0xb8) =
         (float)_DAT_00b3d298 +
         ((float)in_stack_ffffff44 / *(float *)(this + 0x2c)) * (float)_DAT_00b3d298;
  }
  iVar8 = *(int *)(this + 0xb4);
  if (iVar8 == 0) {
    pSVar50 = (SParam *)0x3f800000;
  }
  else if (iVar8 == 2) {
    pSVar50 = (SParam *)0x0;
  }
  else if (iVar8 == 1) {
    pSVar50 = (SParam *)(1.0 - (*(float *)(this + 0xb8) * (float)_DAT_00b3d2c8 - 1.0));
  }
  else {
    pSVar50 = (SParam *)(*(float *)(this + 0xb8) * (float)_DAT_00b3d2c8 - (float)_DAT_00b3d2c0);
  }
  fStack_ac = 1.0 - (float)pSVar50;
  if (*(CHmsZoneVPacker **)(iStack_90 + 0x104) != (CHmsZoneVPacker *)0x0) {
    pGVar39 = (GxBGRAColor_conflict *)0x572f34;
    CHmsZoneVPacker::SetDayTimeFactor
              (*(CHmsZoneVPacker **)(iStack_90 + 0x104),*(CHmsZoneVPacker **)(this + 0xb8),0.0,
               (int)unaff_EBX);
  }
  CSysFidNodRef<class_CPlugMaterial>::GetNod
            (pCVar3 + 0x6c,*(CSysFidNodRef<class_CPlugMaterial> **)(this + 0xb8));
  pCVar42 = (CPlugFileImg *)0x572f53;
  GxLight_SetColorFromImage(unaff_EBX,(CPlugFileImg *)in_stack_ffffff14,(float)in_stack_ffffff18);
  pCVar49 = *(CPlugFileImg **)(this + 0xb8);
  pCVar14 = CSysFidNodRef<class_CPlugMaterial>::GetNod(pCVar3 + 0x74,in_stack_ffffff14);
  iVar8 = CPlugFileImg::IsInSystemMemory((CPlugFileImg *)pCVar14,in_stack_ffffff18);
  if (iVar8 == 0) {
    DAT_00d6e6c0 = DAT_00d6e6c0 + 1;
    iVar8 = (**(code **)(*(int *)pCVar14 + 0x80))();
    DAT_00d6e6c0 = DAT_00d6e6c0 + -1;
    if (iVar8 != 0) goto LAB_00572fbc;
    pCVar12 = (CMwCmdScriptVarBool *)&pCStack_b0;
    pCStack_b0 = (CMwCmdScriptVarBool *)0x3f800000;
    fStack_ac = 1.0;
    pCStack_a8 = (CMwCmdScriptVarBool *)0x3f800000;
    fStack_a4 = 1.0;
    pSVar43 = (SHeaderCommunity *)0x572fb6;
    GxBGRAColor::Set(&stack0xffffff3c,pCVar12,in_stack_ffffff1c);
  }
  else {
LAB_00572fbc:
    in_stack_ffffff40 = in_stack_ffffff48;
    pSVar48 = pSVar50;
    pCVar12 = (CMwCmdScriptVarBool *)0x0;
    pSVar43 = (SHeaderCommunity *)0x0;
    pCVar42 = (CPlugFileImg *)&DAT_00000004;
    pCVar49 = (CPlugFileImg *)0x0;
    pGVar39 = (GxBGRAColor_conflict *)&stack0xffffff30;
    pCVar37 = (CPlugFileImg *)&stack0xffffff44;
    pCVar35 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x572fe5;
    pSVar50 = pSVar48;
    CPlugFileImg::FilterWrappedPixel
              ((CPlugFileImg *)pCVar14,pCVar37,pGVar39,(GxTexCoord *)0x1,4,0,0,0,in_stack_ffffff1c);
  }
  fVar52 = *(float *)(this + 0xb8);
  pCVar14 = CSysFidNodRef<class_CPlugMaterial>::GetNod(pCVar3 + 0x7c,pCVar44);
  iVar8 = CPlugFileImg::IsInSystemMemory((CPlugFileImg *)pCVar14,in_stack_ffffff24);
  if (iVar8 == 0) {
    DAT_00d6e6c0 = DAT_00d6e6c0 + 1;
    iVar8 = (**(code **)(*(int *)pCVar14 + 0x80))();
    DAT_00d6e6c0 = DAT_00d6e6c0 + -1;
    if (iVar8 != 0) goto LAB_00573053;
    pGVar47 = (GxBGRAColor_conflict *)&fStack_a4;
    fStack_a4 = 1.0;
    pCStack_a0 = (CMwCmdScriptVarBool *)0x3f800000;
    pCStack_9c = (CMwCmdScriptVarBool *)0x3f800000;
    pSStack_98 = (SHeaderCommunity *)0x3f800000;
    pGVar45 = (GxBGRAColor_conflict *)0x57304d;
    GxBGRAColor::Set(&stack0xffffff48,(CMwCmdScriptVarBool *)pGVar47,in_stack_ffffff28);
  }
  else {
LAB_00573053:
    pSVar50 = in_stack_ffffff40;
    pGVar47 = (GxBGRAColor_conflict *)0x0;
    pGVar45 = (GxBGRAColor_conflict *)0x0;
    pCVar12 = (CMwCmdScriptVarBool *)&DAT_00000004;
    fVar52 = 0.0;
    pSVar43 = (SHeaderCommunity *)0x1;
    pCVar42 = (CPlugFileImg *)&pCStack_b4;
    in_stack_ffffff40 = pSVar50;
    CPlugFileImg::FilterWrappedPixel
              ((CPlugFileImg *)pCVar14,pCVar42,(GxBGRAColor_conflict *)&stack0xffffff3c,
               (GxTexCoord *)0x1,4,0,0,0,in_stack_ffffff28);
    pCStack_b4 = pCStack_b0;
  }
  pCVar14 = CSysFidNodRef<class_CPlugMaterial>::GetNod(pCVar3 + 0x84,in_stack_ffffff2c);
  pCVar22 = pCStack_a8;
  pCVar41 = pCStack_a8;
  if (pCVar14 != (CPlugMaterial *)0x0) {
    fStack_ac = *(float *)(this + 0xb8);
    in_stack_ffffff2c = (CSysFidNodRef<class_CPlugMaterial> *)0x5730a9;
    pCVar14 = CSysFidNodRef<class_CPlugMaterial>::GetNod
                        (pCVar3 + 0x84,(CSysFidNodRef<class_CPlugMaterial> *)pSVar48);
    iVar8 = CPlugFileImg::IsInSystemMemory((CPlugFileImg *)pCVar14,pCVar49);
    if (iVar8 == 0) {
      DAT_00d6e6c0 = DAT_00d6e6c0 + 1;
      iVar8 = (**(code **)(*(int *)pCVar14 + 0x80))();
      DAT_00d6e6c0 = DAT_00d6e6c0 + -1;
      if (iVar8 == 0) {
        fStack_94 = 1.0;
        iStack_90 = 0x3f800000;
        uStack_8c = 0x3f800000;
        uStack_88 = 0x3f800000;
        GxBGRAColor::Set(&fStack_a4,(CMwCmdScriptVarBool *)&fStack_94,(int)in_stack_ffffff38);
        pCVar22 = pCStack_a0;
        pCVar41 = pCStack_9c;
        goto LAB_00573134;
      }
    }
    afStack_7c[0] = fStack_a4;
    in_stack_ffffff2c = (CSysFidNodRef<class_CPlugMaterial> *)0x0;
    afStack_7c[1] = 0.0;
    pGVar47 = (GxBGRAColor_conflict *)0x1;
    pGVar45 = (GxBGRAColor_conflict *)afStack_7c;
    pCVar12 = (CMwCmdScriptVarBool *)0x573124;
    CPlugFileImg::FilterWrappedPixel
              ((CPlugFileImg *)pCVar14,(CPlugFileImg *)&pCStack_b4,pGVar45,(GxTexCoord *)0x1,4,0,0,0
               ,(EGxTexAddress)in_stack_ffffff38);
    pCVar22 = pCStack_b0;
    pCVar41 = pCStack_9c;
  }
LAB_00573134:
  iVar8 = *(int *)(this + 0xc4);
  fStack_44 = (float)_DAT_00b3d080;
  *(float *)(iVar8 + 0x80) = (float)((uint)pCVar22 >> 0x10 & 0xff) * fStack_44;
  *(float *)(iVar8 + 0x84) = (float)((uint)pCVar22 >> 8 & 0xff) * fStack_44;
  *(float *)(iVar8 + 0x88) = (float)((uint)pCVar22 & 0xff) * fStack_44;
  fStack_40 = (float)((uint)pCVar41 >> 0x10 & 0xff) * fStack_44;
  fStack_3c = (float)((uint)pCVar41 >> 8 & 0xff) * fStack_44;
  fStack_38 = (float)((uint)pCVar41 & 0xff) * fStack_44;
  fStack_4c = (float)((uint)fStack_a4 >> 0x10 & 0xff) * fStack_44;
  fStack_48 = (float)((uint)fStack_a4 >> 8 & 0xff) * fStack_44;
  fStack_44 = fStack_44 * (float)((uint)fStack_a4 & 0xff);
  pCStack_b0 = (CMwCmdScriptVarBool *)
               (fStack_4c * fStack_4c + fStack_48 * fStack_48 + fStack_44 * fStack_44);
  if (fStack_40 * fStack_40 + fStack_3c * fStack_3c + fStack_38 * fStack_38 <= (float)pCStack_b0) {
    GmMat3::GetLine(this + 0x30,(GmMat3 *)0x2,(ulong)&fStack_60,(GmVec3 *)pSVar50);
    pCVar51 = (CMotionManagerWeathers *)0x0;
    (**(code **)(**(int **)(this + 200) + 0x88))();
    pGVar24 = (GxBGRAColor_conflict *)0x5733e3;
    GxLight::SetBaseRGB(*(GxLight **)(this + 0xc4),(GxLight *)&pCStack_b0,in_stack_fffffed8);
    pCVar26 = (CMotionWeather *)0x3f800000;
    pCVar25 = (CMotionWeather *)0x5733f4;
    GxLight::SetIntensity(*(GxLight **)(this + 0xc4),(GxLight *)0x3f800000,in_stack_fffffedc);
    *(uint *)(*(int *)(this + 0xc4) + 0x14) = *(uint *)(*(int *)(this + 0xc4) + 0x14) & 0xfffffffb;
    this_06 = pCVar3 + 0xa4;
    pCVar41 = pCVar3 + 0xb8;
    pCVar22 = (CMwCmdScriptVarBool *)0x0;
  }
  else {
    fStack_a4 = fStack_94 * (float)_DAT_00b36110;
    pCStack_b0 = *(CMwCmdScriptVarBool **)(this + 0x20);
    pCStack_9c = (CMwCmdScriptVarBool *)
                 (((float)_DAT_00b36110 * (float)pCStack_b0) / (float)_DAT_00b36ab8);
    __CIsin();
    pCStack_b0 = (CMwCmdScriptVarBool *)(float)extraout_ST0_00;
    pCStack_a0 = pCStack_b0;
    __CIcos();
    pCStack_b0 = (CMwCmdScriptVarBool *)(float)extraout_ST0_01;
    fStack_5c = -(float)pCStack_a0;
    uStack_58 = 0;
    fStack_60 = (float)pCStack_b0;
    GmMat3::SetIdentity(&stack0x0000000c,(GmMat43 *)pSVar50);
    GmMat3::RotateX(&stack0x00000010,(GmIso4 *)-(float)pSStack_98,fVar52);
    GmVec3::Mult(&uStack_58,(GmIso3 *)&stack0x00000014,in_stack_ffffff44);
    pCVar51 = (CMotionManagerWeathers *)0x573329;
    GmMat3::SetDOV(auStack_18,aGStack_54,(GmVec3 *)0x0,(ulong)in_stack_ffffff40);
    in_stack_00000018 = 0;
    in_stack_00000014 = 0;
    in_stack_ffffff40 = (SParam *)0x0;
    in_stack_00000010 = 0;
    fVar52 = 8.00811e-39;
    (**(code **)(**(int **)(this + 200) + 0x88))();
    pGVar24 = (GxBGRAColor_conflict *)0x57336d;
    GxLight::SetBaseRGB(*(GxLight **)(this + 0xc4),(GxLight *)&fStack_a4,in_stack_fffffed8);
    pCVar26 = (CMotionWeather *)0x3f800000;
    pCVar25 = (CMotionWeather *)0x57337e;
    GxLight::SetIntensity(*(GxLight **)(this + 0xc4),(GxLight *)0x3f800000,in_stack_fffffedc);
    *(uint *)(*(int *)(this + 0xc4) + 0x14) = *(uint *)(*(int *)(this + 0xc4) + 0x14) | 4;
    if (*(int *)(this + 0xb4) == 0) {
      pCVar22 = (CMwCmdScriptVarBool *)0x0;
    }
    else {
      pCVar22 = pCVar3 + 0x9c;
    }
    pCVar41 = pCVar3 + 0xb4;
    this_06 = (CMwCmdScriptVarBool *)0x0;
  }
  if (((*(int *)(this + 0xb4) == 0) || (pCVar22 == (CMwCmdScriptVarBool *)0x0)) ||
     (iVar8 = CSysFidNodRef<class_CPlugBitmap>::IsNull
                        (pCVar22,(CSysFidNodRef<class_CPlugBitmap> *)in_stack_fffffee0), iVar8 != 0)
     ) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  puVar1 = (uint *)(*(int *)(this + 0xc4) + 0x14);
  *puVar1 = *puVar1 ^ ((uint)bVar6 << 4 ^ *(uint *)(*(int *)(this + 0xc4) + 0x14)) & 0x10;
  if (bVar6) {
    *(undefined4 *)(*(int *)(this + 0xc4) + 0x60) = *(undefined4 *)pCVar41;
    iVar8 = *(int *)(*(int *)(this + 200) + 0x30);
    in_stack_fffffee0 =
         CSysFidNodRef<class_CPlugMaterial>::GetNod
                   (pCVar22,(CSysFidNodRef<class_CPlugMaterial> *)in_stack_fffffee0);
    CMwNodRef<class_CGameCamera>::MwSetNod
              ((void *)(iVar8 + 0x68),(CMwNodRef<class_CGameCamera> *)in_stack_fffffee0,
               (CGameCamera *)in_stack_fffffee4);
  }
  if (((*(int *)(this + 0xb4) == 0) && (this_06 != (CMwCmdScriptVarBool *)0x0)) &&
     (iVar8 = CSysFidNodRef<class_CPlugBitmap>::IsNull
                        (this_06,(CSysFidNodRef<class_CPlugBitmap> *)in_stack_fffffee0), iVar8 == 0)
     ) {
    bVar6 = true;
  }
  else {
    bVar6 = false;
  }
  puVar1 = (uint *)(*(int *)(this + 0xc4) + 0x14);
  *puVar1 = *puVar1 ^ ((uint)bVar6 << 5 ^ *(uint *)(*(int *)(this + 0xc4) + 0x14)) & 0x20;
  if (bVar6) {
    *(undefined4 *)(*(int *)(this + 0xc4) + 0x60) = *(undefined4 *)pCVar41;
    iVar8 = *(int *)(*(int *)(this + 200) + 0x30);
    in_stack_fffffee0 =
         CSysFidNodRef<class_CPlugMaterial>::GetNod
                   (this_06,(CSysFidNodRef<class_CPlugMaterial> *)in_stack_fffffee0);
    CMwNodRef<class_CGameCamera>::MwSetNod
              ((void *)(iVar8 + 0x6c),(CMwNodRef<class_CGameCamera> *)in_stack_fffffee0,
               (CGameCamera *)in_stack_fffffee4);
  }
  if (*(int *)(this + 0x60) != 0) {
    this_01 = *(CPlugFileGen **)(*(int *)(this + 0x60) + 0x48);
    GxLight::GetIntensRGB(*(GxLight **)(this + 0xc4),(GxLight *)&stack0xffffff14);
    this_00 = this_01 + 0x48;
    pCVar26 = (CMotionWeather *)0x57350d;
    pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                        (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                         (ulong)in_stack_fffffee0);
    pCVar41 = *(CMwCmdScriptVarBool **)pSVar13;
    pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                        (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                         (ulong)in_stack_fffffee4);
    pCVar35 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar13;
    in_stack_fffffee4 = (CMwCmdScriptVarBool *)0x0;
    in_stack_fffffee0 = (CPlugMaterial *)0x57352b;
    pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                        (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                         (ulong)in_stack_fffffee8);
    fStack_80 = *(float *)pSVar13;
    pCVar51 = (CMotionManagerWeathers *)-fStack_ac;
    fVar52 = -(float)pCStack_a8;
    pCVar37 = (CPlugFileImg *)
              (fVar52 * (float)this_06 +
              fStack_80 * -(float)pCStack_b0 + (float)pCVar51 * (float)pCVar37);
    if ((float)pCVar37 < (float)_DAT_00b41ea8) {
      pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                           (ulong)in_stack_fffffeec);
      pGVar39 = *(GxBGRAColor_conflict **)pSVar13;
      pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          (this_01 + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                           (ulong)in_stack_fffffef0);
      in_stack_fffffef0 = pCVar41;
      in_stack_fffffeec = *(CPlugShader **)pSVar13;
      pCVar41 = in_stack_fffffef0;
      if (*(int *)(this_01 + 0x34) == 0x18) {
        in_stack_fffffee8 = (CPlugFileGen *)&stack0xffffff40;
        in_stack_fffffee4 = (CMwCmdScriptVarBool *)0x5735bc;
        CPlugFileGen::GenSpecularCubeVect
                  (this_01,in_stack_fffffee8,(GmVec3 *)in_stack_fffffeec,(ulong)in_stack_fffffef0,
                   (float)in_stack_fffffef4);
      }
      else {
        in_stack_fffffee8 = (CPlugFileGen *)&stack0xffffff28;
        in_stack_fffffee4 = (CMwCmdScriptVarBool *)&stack0xffffff40;
        in_stack_fffffee0 = (CPlugMaterial *)0x5735cf;
        CPlugFileGen::GenSpecularCubeVectRgb
                  (this_01,(CPlugFileGen *)in_stack_fffffee4,(GmVec3 *)in_stack_fffffee8,
                   (GmVec3 *)in_stack_fffffeec,(ulong)in_stack_fffffef0,(float)in_stack_fffffef4);
      }
    }
  }
  *(float *)(*(int *)(this + 0xc4) + 0x58) =
       (float)pGVar47 * *(float *)(pCVar3 + 0xd8) + (float)pCVar42 * *(float *)(pCVar3 + 0xd4);
  *(float *)(*(int *)(this + 0xc4) + 0x54) =
       *(float *)(pCVar3 + 0xdc) * (float)pCVar42 + *(float *)(pCVar3 + 0xe0) * (float)pGVar47;
  if (*(int *)(pCVar3 + 0xe4) != 0) {
    pGVar15 = *(GxBGRAColor_conflict **)(this + 0xb8);
    EVar28 = 0x57364c;
    pCVar14 = CSysFidNodRef<class_CPlugMaterial>::GetNod
                        ((void *)(*(int *)(pCVar3 + 0xe4) + 0x14),
                         (CSysFidNodRef<class_CPlugMaterial> *)in_stack_fffffee0);
    in_stack_fffffee0 = (CPlugMaterial *)0x573655;
    iVar8 = CPlugFileImg::IsInSystemMemory
                      ((CPlugFileImg *)pCVar14,(CPlugFileImg *)in_stack_fffffee4);
    if (iVar8 == 0) {
      DAT_00d6e6c0 = DAT_00d6e6c0 + 1;
      in_stack_fffffee4 = (CMwCmdScriptVarBool *)0x57366b;
      iVar8 = (**(code **)(*(int *)pCVar14 + 0x80))();
      DAT_00d6e6c0 = DAT_00d6e6c0 + -1;
      if (iVar8 != 0) goto LAB_0057369b;
      pGVar39 = (GxBGRAColor_conflict *)0x3f800000;
      pCVar41 = (CMwCmdScriptVarBool *)0x3f800000;
      pCVar42 = (CPlugFileImg *)0x3f800000;
      this_06 = (CMwCmdScriptVarBool *)0x3f800000;
      GxBGRAColor::Set(&stack0xfffffee4,(CMwCmdScriptVarBool *)&stack0xffffff04,(int)pGVar24);
    }
    else {
LAB_0057369b:
      in_stack_fffffee8 = (CPlugFileGen *)in_stack_fffffef8;
      pGVar45 = (GxBGRAColor_conflict *)0x0;
      CPlugFileImg::FilterWrappedPixel
                ((CPlugFileImg *)pCVar14,(CPlugFileImg *)&stack0xfffffef4,
                 (GxBGRAColor_conflict *)&stack0xffffff1c,(GxTexCoord *)0x1,4,0,0,0,
                 (EGxTexAddress)pGVar24);
      in_stack_fffffef8 = (CMotionWeather *)in_stack_fffffee8;
    }
    _DAT_00d6e7bc = (float)_DAT_00b3d080;
    _DAT_00d6e7b4 = (float)((uint)in_stack_fffffee8 >> 0x10 & 0xff) * _DAT_00d6e7bc;
    _DAT_00d6e7b8 = (float)((uint)in_stack_fffffee8 >> 8 & 0xff) * _DAT_00d6e7bc;
    _DAT_00d6e7bc = _DAT_00d6e7bc * (float)((uint)in_stack_fffffee8 & 0xff);
    in_stack_fffffee8 = *(CPlugFileGen **)(this + 0xb8);
    pGVar24 = (GxBGRAColor_conflict *)0x57372e;
    pCVar14 = CSysFidNodRef<class_CPlugMaterial>::GetNod
                        ((void *)(*(int *)(pCVar3 + 0xe4) + 0x1c),
                         (CSysFidNodRef<class_CPlugMaterial> *)pCVar25);
    iVar8 = CPlugFileImg::IsInSystemMemory((CPlugFileImg *)pCVar14,(CPlugFileImg *)pCVar26);
    if (iVar8 == 0) {
      DAT_00d6e6c0 = DAT_00d6e6c0 + 1;
      iVar8 = (**(code **)(*(int *)pCVar14 + 0x80))();
      DAT_00d6e6c0 = DAT_00d6e6c0 + -1;
      if (iVar8 != 0) goto LAB_0057377d;
      pCVar26 = (CMotionWeather *)&stack0xffffff10;
      this_06 = (CMwCmdScriptVarBool *)0x3f800000;
      pSVar43 = (SHeaderCommunity *)0x3f800000;
      pCVar12 = (CMwCmdScriptVarBool *)0x3f800000;
      pCVar25 = (CMotionWeather *)0x573777;
      GxBGRAColor::Set(&stack0xfffffef0,(CMwCmdScriptVarBool *)pCVar26,EVar28);
    }
    else {
LAB_0057377d:
      pGVar15 = pGVar39;
      pCVar26 = (CMotionWeather *)0x0;
      pCVar25 = (CMotionWeather *)0x0;
      pGVar24 = (GxBGRAColor_conflict *)0x0;
      in_stack_ffffff2c = (CSysFidNodRef<class_CPlugMaterial> *)0x0;
      CPlugFileImg::FilterWrappedPixel
                ((CPlugFileImg *)pCVar14,(CPlugFileImg *)&stack0xffffff00,
                 (GxBGRAColor_conflict *)&stack0xffffff28,(GxTexCoord *)0x1,4,0,0,0,EVar28);
      pGVar39 = pGVar15;
    }
    _DAT_00d6e7cc = (float)_DAT_00b3d080;
    _DAT_00d6e7c4 = (float)((uint)pGVar15 >> 0x10 & 0xff) * _DAT_00d6e7cc;
    _DAT_00d6e7c8 = (float)((uint)pGVar15 >> 8 & 0xff) * _DAT_00d6e7cc;
    _DAT_00d6e7cc = _DAT_00d6e7cc * (float)((uint)pGVar15 & 0xff);
  }
  if ((*(int *)(pCVar3 + 0x90) == 0) && (*(int *)(pCVar3 + 0x8c) == 0)) {
    *(float *)((int)fVar52 + 0x94) = *(float *)(pCVar3 + 0x4c) - *(float *)(pCVar3 + 0x30);
    *(float *)((int)fVar52 + 0x98) = *(float *)(pCVar3 + 0x50) - *(float *)(pCVar3 + 0x34);
    *(float *)((int)fVar52 + 0x9c) = *(float *)(pCVar3 + 0x54) - *(float *)(pCVar3 + 0x38);
    fVar2 = *(float *)((int)fVar52 + 0x94) * (float)pGVar47;
    *(float *)((int)fVar52 + 0x94) = fVar2;
    fVar53 = *(float *)((int)fVar52 + 0x98) * (float)pGVar47;
    *(float *)((int)fVar52 + 0x98) = fVar53;
    pCVar16 = (CFastBuffer<class_CCrystalFace*> *)(*(float *)((int)fVar52 + 0x9c) * (float)pGVar47);
    *(CFastBuffer<class_CCrystalFace*> **)((int)fVar52 + 0x9c) = pCVar16;
    *(float *)((int)fVar52 + 0x94) = *(float *)(pCVar3 + 0x30) + fVar2;
    *(float *)((int)fVar52 + 0x98) = fVar53 + *(float *)(pCVar3 + 0x34);
    *(float *)((int)fVar52 + 0x9c) = (float)pCVar16 + *(float *)(pCVar3 + 0x38);
  }
  else {
    pCVar14 = CSysFidNodRef<class_CPlugMaterial>::GetNod
                        (pCVar3 + 0x8c,(CSysFidNodRef<class_CPlugMaterial> *)in_stack_fffffee0);
    iVar8 = CPlugFileImg::IsInSystemMemory
                      ((CPlugFileImg *)pCVar14,(CPlugFileImg *)in_stack_fffffee4);
    pCVar22 = (CMwCmdScriptVarBool *)pCVar37;
    if (iVar8 == 0) {
      DAT_00d6e6c0 = DAT_00d6e6c0 + 1;
      iVar8 = (**(code **)(*(int *)pCVar14 + 0x80))();
      DAT_00d6e6c0 = DAT_00d6e6c0 + -1;
      pCVar22 = (CMwCmdScriptVarBool *)pCVar37;
      if (iVar8 != 0) goto LAB_0057387a;
      in_stack_fffffee4 = (CMwCmdScriptVarBool *)&stack0xffffff1c;
      pGVar45 = (GxBGRAColor_conflict *)0x3f800000;
      pGVar47 = (GxBGRAColor_conflict *)0x3f800000;
      in_stack_fffffee0 = (CPlugMaterial *)0x573874;
      GxBGRAColor::Set(&stack0xfffffefc,in_stack_fffffee4,(int)in_stack_fffffee8);
      pCVar22 = (CMwCmdScriptVarBool *)pCVar37;
    }
    else {
LAB_0057387a:
      pCVar37 = (CPlugFileImg *)this_06;
      in_stack_fffffee4 = (CMwCmdScriptVarBool *)0x0;
      in_stack_fffffee0 = (CPlugMaterial *)0x0;
      pCVar26 = (CMotionWeather *)&DAT_00000004;
      pCVar25 = (CMotionWeather *)0x1;
      pGVar24 = (GxBGRAColor_conflict *)&stack0xffffff34;
      CPlugFileImg::FilterWrappedPixel
                ((CPlugFileImg *)pCVar14,(CPlugFileImg *)&stack0xffffff0c,pGVar24,(GxTexCoord *)0x1,
                 4,0,0,0,(EGxTexAddress)in_stack_fffffee8);
      this_06 = (CMwCmdScriptVarBool *)pCVar37;
    }
    fVar53 = (float)_DAT_00b3d080;
    pCVar16 = (CFastBuffer<class_CCrystalFace*> *)((uint)pCVar37 & 0xff);
    *(float *)((int)fVar52 + 0x94) = (float)((uint)pCVar37 >> 0x10 & 0xff) * fVar53;
    *(float *)((int)fVar52 + 0x98) = (float)((uint)pCVar37 >> 8 & 0xff) * fVar53;
    *(float *)((int)fVar52 + 0x9c) = fVar53 * (float)(int)pCVar16;
    pCVar37 = (CPlugFileImg *)pCVar22;
  }
  *(float *)((int)fVar52 + 0xa0) =
       *(float *)(pCVar3 + 0x3c) * (float)pCVar42 + *(float *)(pCVar3 + 0x58) * (float)pGVar47;
  *(float *)((int)fVar52 + 0xa4) =
       *(float *)(pCVar3 + 0x40) * (float)pCVar42 + *(float *)(pCVar3 + 0x5c) * (float)pGVar47;
  *(float *)((int)fVar52 + 0xa8) =
       (float)pGVar47 * *(float *)(pCVar3 + 0x60) + *(float *)(pCVar3 + 0x44) * (float)pCVar42;
  fVar53 = fVar52;
  if ((*(GxFogBlender **)(pCVar3 + 0x68) != (GxFogBlender *)0x0) &&
     (pGVar27 = *(GxFogBlender **)((int)fVar52 + 0xb0), pGVar27 != (GxFogBlender *)0x0)) {
    pCVar25 = (CMotionWeather *)0x57395a;
    GxFogBlender::BlendFogAtX_Wrap01
              (*(GxFogBlender **)(pCVar3 + 0x68),pGVar27,*(GxFog **)(this + 0xb8),
               (float)in_stack_fffffee0);
    pCVar26 = (CMotionWeather *)pGVar27;
  }
  iVar8 = *(int *)(this + 0xf4);
  if (*(int *)(this + 0x114) == 0) {
    *(undefined4 *)(iVar8 + 0x38) = *(undefined4 *)(this + 0x118);
    *(undefined4 *)(iVar8 + 0x3c) = *(undefined4 *)(this + 0x11c);
    *(undefined4 *)(iVar8 + 0x40) = *(undefined4 *)(this + 0x120);
    *(undefined4 *)(iVar8 + 0x44) = *(undefined4 *)(this + 0x124);
  }
  else {
    *(undefined4 *)(iVar8 + 0x38) = *(undefined4 *)((int)fVar52 + 0x94);
    *(undefined4 *)(iVar8 + 0x3c) = *(undefined4 *)((int)fVar52 + 0x98);
    *(undefined4 *)(iVar8 + 0x40) = *(undefined4 *)((int)fVar52 + 0x9c);
  }
  if (pCStack_b0 != (CMwCmdScriptVarBool *)*(float *)(this + 0xb0)) {
    EVar29 = 0x573a59;
    pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        (this + 0x80,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffee0);
    pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar17 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (this + 0x80,pCVar23,(ulong)pCVar25);
        pCVar25 = *(CMotionWeather **)(this + 0xb0);
        pGVar24 = (GxBGRAColor_conflict *)0x573a77;
        CMotionDayTime::OnDayTimeChange
                  (*(CMotionDayTime **)pSVar13,pCVar25,(CFuncWeather *)pCVar26,EVar29);
        pCVar23 = pCVar23 + 1;
      } while (pCVar23 < pCVar17);
    }
  }
  if (pCVar51 != *(CMotionManagerWeathers **)(this + 0x70)) {
    pCVar26 = (CMotionWeather *)0x573a8f;
    ChangeWeatherAt(this,*(CMotionManagerWeathers **)(this + 0x70),(ulong)in_stack_fffffee0);
  }
  if (pCVar35 != *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0xb4)) {
    *(undefined4 *)(this + 0x104) = 0;
    *(undefined4 *)(this + 0x108) = 0;
    ppCVar30 = (CPlugTree **)0x573abd;
    pCVar37 = (CPlugFileImg *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        (this + 0x74,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffee0);
    pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar37 != (CPlugFileImg *)0x0) {
      do {
        pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (this + 0x74,pCVar17,(ulong)pGVar24);
        this_02 = *(CMotionWeather **)pSVar13;
        CMotionWeather::OnDayTimeChange
                  (this_02,(CMotionWeather *)in_stack_ffffff2c,*(CFuncWeather **)(this + 0xb4),
                   (EDayTime4)pCVar25);
        pGVar24 = (GxBGRAColor_conflict *)0x573aed;
        CMotionWeather::GetSkyGradVBitmapAdr
                  (this_02,(CMotionWeather *)(this + 0x104),(CPlugBitmapAddress **)pCVar26);
        pCVar26 = (CMotionWeather *)(this + 0x108);
        pCVar25 = (CMotionWeather *)0x573afb;
        CMotionWeather::GetTreeStars(this_02,pCVar26,ppCVar30);
        pCVar17 = pCVar17 + 1;
      } while (pCVar17 < pCVar35);
    }
    if (*(int *)(this + 0xfc) != 0) {
      pCVar35 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x9002000;
      (**(code **)(*(int *)this + 0x74))(&stack0xfffffefc,*(int *)(this + 0xfc),0);
    }
  }
  iVar8 = *(int *)(this + 0x10c);
  if (iVar8 != 0) {
    *(undefined4 *)(iVar8 + 0x48) = _DAT_00b36144;
    *(undefined4 *)(iVar8 + 0x4c) = 0;
    *(undefined4 *)(iVar8 + 0x50) = 0;
  }
  CScene3d::SceneFxFindFromClassId
            (*(CScene3d **)(*(int *)(this + 0xf0) + 0x14),(CScene3d *)0xa07b000,(ulong)&iStack_90,
             (CSceneFxNod **)in_stack_fffffee0);
  _DAT_00d6e778 = *(undefined4 *)(this + 0xb8);
  uVar18 = *(uint *)(this + 0xf8);
  if (*(uint *)(*(int *)(this + 0x14) + 0xf8) <= *(uint *)(this + 0xf8)) {
    uVar18 = *(uint *)(*(int *)(this + 0x14) + 0xf8);
  }
  _DAT_00d6e774 = in_stack_ffffff2c;
  *(uint *)(this + 0xf8) = uVar18;
  if (*(int *)(this + 0xfc) == 0) {
    if (uVar18 != 0xffffffff) {
      pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      pCVar40 = (CMwNod *)0x0;
      pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CFastBuffer<class_CCrystalFace*>::GetCount
                          (this + 0x74,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffee4);
      pGVar39 = pGVar47;
      if (pCVar17 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        ExceptionList = local_8;
        return;
      }
      do {
        pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (this + 0x74,pCVar23,(ulong)in_stack_fffffef8);
        in_stack_fffffef8 = (CMotionWeather *)&stack0xffffff1c;
        pCVar32 = (CMwNod *)0x573bd4;
        iVar8 = CMotionWeather::GetTreeSea
                          (*(CMotionWeather **)pSVar13,in_stack_fffffef8,(CPlugTree **)pCVar35);
        if (iVar8 != 0) break;
        pCVar23 = pCVar23 + 1;
      } while (pCVar23 < pCVar17);
      if (pGVar45 == (GxBGRAColor_conflict *)0x0) {
        ExceptionList = local_8;
        return;
      }
      pCVar14 = *(CPlugMaterial **)(pGVar45 + 0x98);
      if (pCVar14 == (CPlugMaterial *)0x0) {
        ExceptionList = local_8;
        return;
      }
      this_03 = *(CMwNod **)(pGVar45 + 0x94);
      if (this_03 != *(CMwNod **)(this + 0xfc)) {
        if (this_03 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(this_03,pCVar40);
        }
        if (*(CMwNod **)(this + 0xfc) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(this + 0xfc),pCVar40);
        }
        *(CMwNod **)(this + 0xfc) = this_03;
      }
      pCVar36 = *(CPlugMaterial **)(this + 0xfc);
      if (pCVar36 == (CPlugMaterial *)0x0) {
        ExceptionList = local_8;
        return;
      }
      pCVar34 = (CMwId *)0x573c42;
      CPlugMaterial::DoesContainShader
                (pCVar14,pCVar36,(CPlugShader *)&stack0xffffff20,(ulong *)pCVar40);
      puVar38 = (ulong *)0x573c4f;
      pGVar47 = pGVar39;
      pSVar13 = CFastArray<struct_CPlugMaterial::SDeviceMat>::operator[]
                          (pCVar14 + 0x20,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar39,
                           (ulong)pCVar41);
      if (*(ushort *)(pSVar13 + 2) < 2) {
        pGVar39 = (GxBGRAColor_conflict *)0x573c64;
        CFastString::CFastString
                  ((CFastString *)&pCStack_a8,(CFastString *)"FresnelDayTime",(char *)pCVar42);
        in_stack_0000000c = 0;
        pCVar41 = (CMwCmdScriptVarBool *)0x573c7f;
        pCVar19 = CPlugShader::FindLayerByName
                            (*(CPlugShader **)(this + 0xfc),(CPlugShader *)&fStack_a4,
                             (CFastString *)this_06);
        *(CPlugBitmapAddress **)(this + 0x100) = pCVar19;
        in_stack_00000010 = 0xffffffff;
        this_06 = (CMwCmdScriptVarBool *)0x573c99;
        CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&pCStack_a0,pSVar43);
      }
      else {
        *(undefined4 *)(this + 0x100) = 0;
      }
      CMwNod::MwAddReceiver(*(CMwNod **)(this + 0xfc),(CMwNod *)this,pCVar32);
      CMwId::CMwId(&stack0xffffff40,pCVar34);
      pCVar33 = *(CFastArray<float*> **)(this + 0xfc);
      local_8 = (undefined1 *)0x1;
      TwkInitReal(pCVar33,(CPlugShader *)"ReflecIntens",(char *)pCVar36);
      pCVar31 = *(CFastArray<float*> **)(this + 0xfc);
      TwkInitReal(pCVar31,(CPlugShader *)"ReflecIntensMid",(char *)pCVar33);
      in_stack_fffffee4 = *(CMwCmdScriptVarBool **)(this + 0xfc);
      TwkInitReal((CFastArray<float*> *)in_stack_fffffee4,(CPlugShader *)"ReflecIntensTM",
                  (char *)pCVar31);
      TwkInitReal(*(CFastArray<float*> **)(this + 0xfc),(CPlugShader *)"ReflecIntensTMmid",
                  (char *)in_stack_fffffee4);
      CMwId::SetLocalName(&stack0xffffff44,(CMwId *)"WaterColor",(CFastStringInt *)pCVar36);
      pCVar35 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      in_stack_fffffef8 = (CMotionWeather *)0x0;
      pCVar16 = (CFastBuffer<class_CCrystalFace*> *)0x0;
      in_stack_fffffef0 = (CMwCmdScriptVarBool *)0x0;
      in_stack_fffffeec = (CPlugShader *)&stack0xffffff48;
      in_stack_fffffee8 = (CPlugFileGen *)0x573d4a;
      pGVar20 = CPlugShader::GetLoadFxValue
                          (*(CPlugShader **)(this + 0xfc),in_stack_fffffeec,(CMwId *)0x0,
                           (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,(EPlugGpuPipeline *)0x0,
                           puVar38);
      *(GmVec4 **)(this + 0xec) = pGVar20;
      pCVar37 = (CPlugFileImg *)0x573d64;
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pGVar39);
    }
    if (*(int *)(this + 0xfc) == 0) goto LAB_005740ec;
  }
  uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this + 0xcc,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffee4);
  if (uVar7 != 0) {
    pGVar39 = (GxBGRAColor_conflict *)
              (*(float *)((int)fVar53 + 0xe8) * (float)pSVar43 +
              *(float *)((int)fVar53 + 0xec) * (float)in_stack_ffffff2c);
    pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        (this + 0xcc,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffeec);
    pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar17 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (this + 0xcc,pCVar23,(ulong)in_stack_fffffee8);
        pCVar23 = pCVar23 + 1;
        **(undefined4 **)pSVar13 = pCVar41;
      } while (pCVar23 < pCVar17);
    }
  }
  uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this + 0xd4,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffeec);
  if (uVar7 != 0) {
    pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xd4,pCVar16);
    pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar17 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (this + 0xd4,pCVar23,(ulong)in_stack_fffffef0);
        pCVar23 = pCVar23 + 1;
        **(undefined4 **)pSVar13 = this_06;
      } while (pCVar23 < pCVar17);
    }
  }
  uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xdc,pCVar16);
  if (uVar7 != 0) {
    pSVar43 = (SHeaderCommunity *)
              (*(float *)((int)fVar53 + 0xf8) * (float)pGVar47 +
              *(float *)((int)fVar53 + 0xfc) * (float)pCVar51);
    pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        (this + 0xdc,(CFastBuffer<class_CCrystalFace*> *)pCVar35);
    pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar17 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (this + 0xdc,pCVar23,(ulong)in_stack_fffffef8);
        pCVar23 = pCVar23 + 1;
        **(undefined4 **)pSVar13 = pCVar12;
      } while (pCVar23 < pCVar17);
    }
  }
  pCVar51 = this + 0xe4;
  EVar28 = 0x573e98;
  uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (pCVar51,(CFastBuffer<class_CCrystalFace*> *)pCVar35);
  if (uVar7 != 0) {
    pCVar35 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x573ebd;
    pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        (pCVar51,(CFastBuffer<class_CCrystalFace*> *)pGVar39);
    pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar17 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        EVar28 = 0x573ecd;
        pCVar35 = pCVar23;
        pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (pCVar51,pCVar23,(ulong)pCVar37);
        pCVar23 = pCVar23 + 1;
        **(undefined4 **)pSVar13 = pGVar45;
      } while (pCVar23 < pCVar17);
    }
  }
  pfVar4 = *(float **)(this + 0xec);
  if (pfVar4 != (float *)0x0) {
    if ((*(int *)((int)fStack_a4 + 0x98) == 0) && (*(int *)((int)fStack_a4 + 0x94) == 0)) {
      *pfVar4 = *(float *)((int)fStack_a4 + 0x114) - *(float *)((int)fStack_a4 + 0x108);
      pfVar4[1] = *(float *)((int)fStack_a4 + 0x118) - *(float *)((int)fStack_a4 + 0x10c);
      pfVar4[2] = *(float *)((int)fStack_a4 + 0x11c) - *(float *)((int)fStack_a4 + 0x110);
      fVar52 = *pfVar4;
      *pfVar4 = (float)in_stack_ffffff40 * fVar52;
      fVar53 = pfVar4[1];
      pfVar4[1] = fVar53 * (float)in_stack_ffffff40;
      fVar2 = pfVar4[2];
      pfVar4[2] = fVar2 * (float)in_stack_ffffff40;
      *pfVar4 = *(float *)((int)fStack_a4 + 0x108) + (float)in_stack_ffffff40 * fVar52;
      pfVar4[1] = *(float *)((int)fStack_a4 + 0x10c) + fVar53 * (float)in_stack_ffffff40;
      pfVar4[2] = fVar2 * (float)in_stack_ffffff40 + *(float *)((int)fStack_a4 + 0x110);
    }
    else {
      uVar46 = *(undefined4 *)(this + 0xb8);
      uVar7 = 0x573f15;
      pCVar14 = CSysFidNodRef<class_CPlugMaterial>::GetNod
                          ((int *)((int)fStack_a4 + 0x94),
                           (CSysFidNodRef<class_CPlugMaterial> *)pGVar39);
      pCVar16 = (CFastBuffer<class_CCrystalFace*> *)0x573f1e;
      iVar8 = CPlugFileImg::IsInSystemMemory((CPlugFileImg *)pCVar14,(CPlugFileImg *)pCVar41);
      if (iVar8 == 0) {
        DAT_00d6e6c0 = DAT_00d6e6c0 + 1;
        iVar8 = (**(code **)(*(int *)pCVar14 + 0x80))();
        DAT_00d6e6c0 = DAT_00d6e6c0 + -1;
        if (iVar8 != 0) goto LAB_00573f69;
        GxBGRAColor::Set(&stack0xffffff14,(CMwCmdScriptVarBool *)&stack0xffffff2c,EVar28);
      }
      else {
LAB_00573f69:
        fStack_94 = 0.0;
        pSStack_98 = pSVar43;
        CPlugFileImg::FilterWrappedPixel
                  ((CPlugFileImg *)pCVar14,(CPlugFileImg *)&fStack_ac,
                   (GxBGRAColor_conflict *)&pSStack_98,(GxTexCoord *)0x1,4,0,0,0,EVar28);
        pCVar12 = pCStack_a8;
      }
      pfVar4 = *(float **)(this + 0xec);
      fVar52 = (float)_DAT_00b3d080;
      *pfVar4 = (float)((uint)pCVar12 >> 0x10 & 0xff) * fVar52;
      pCVar51 = this + 0xcc;
      pfVar4[1] = (float)((uint)pCVar12 >> 8 & 0xff) * fVar52;
      pfVar4[2] = fVar52 * (float)((uint)pCVar12 & 0xff);
      uVar21 = CFastBuffer<class_CCrystalFace*>::GetCount
                         (pCVar51,(CFastBuffer<class_CCrystalFace*> *)pCVar35);
      if (uVar21 != 0) {
        pCVar35 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                  CFastBuffer<class_CCrystalFace*>::GetCount(pCVar51,pCVar16);
        pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pCVar35 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                (pCVar51,pCVar17,uVar7);
            pCVar17 = pCVar17 + 1;
            **(undefined4 **)pSVar13 = uVar46;
          } while (pCVar17 < pCVar35);
        }
      }
    }
  }
  if ((*(int *)(this + 0x100) != 0) && (iVar8 = *(int *)(*(int *)(this + 0x100) + 0x34), iVar8 != 0)
     ) {
    *(undefined4 *)(iVar8 + 0x10) = *(undefined4 *)(this + 0xb8);
  }
LAB_005740ec:
  if ((*(int *)(this + 0x104) != 0) && (iVar8 = *(int *)(*(int *)(this + 0x104) + 0x34), iVar8 != 0)
     ) {
    *(undefined4 *)(iVar8 + 0x10) = *(undefined4 *)(this + 0xb8);
  }
  iVar8 = *(int *)(this + 0x108);
  if (iVar8 != 0) {
    if (((*(int *)((int)fStack_a4 + 0xa0) == 0) && (*(int *)((int)fStack_a4 + 0x9c) == 0)) ||
       (*(int *)(this + 0xb4) == 2)) {
      bVar5 = 0;
    }
    else {
      bVar5 = 1;
    }
    *(uint *)(iVar8 + 0x9c) =
         *(uint *)(iVar8 + 0x9c) ^ ((uint)bVar5 * 8 ^ *(uint *)(iVar8 + 0x9c)) & 8;
  }
  ExceptionList = local_8;
  return;
}
}

