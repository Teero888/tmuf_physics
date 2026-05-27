// Class implementation: CSceneMobil

// =================================================
// Function: CSceneMobil::AbsorbContact
// =================================================
void __thiscall
CSceneMobil::AbsorbContact
          (CSceneMobil *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2,
          CHmsPhysicalContact *param_3)
{
{
  CSceneMessageHandler *this_00;
  CHmsPhysicalContact *unaff_EDI;
  
  if (*(int **)(this + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x20) + 0xb4))(param_1);
  }
  this_00 = *(CSceneMessageHandler **)(this + 0x44);
  if ((this_00 != (CSceneMessageHandler *)0x0) && (*(int *)(this_00 + 0x18) != 0)) {
    CSceneMessageHandler::AbsorbContact
              (this_00,(CSceneMobilAbsorbContact *)this,(CHmsItem *)param_1,unaff_EDI);
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::AddMotionSolid
// =================================================
void __thiscall CSceneMobil::AddMotionSolid(CSceneMobil *this,CSceneMobil *param_1,CMotion *param_2)
{
{
  CMwId *pCVar1;
  int iVar2;
  CMotions *this_00;
  CMotions *extraout_EAX;
  int unaff_EDI;
  CSceneObject *unaff_retaddr;
  CMwNod *in_stack_ffffffcc;
  CMwId *in_stack_ffffffd0;
  int in_stack_ffffffd4;
  CMwNod *pCVar3;
  CSceneMobil *pCVar4;
  CMotions *pCVar5;
  void *local_c;
  CSceneObject *pCStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  pCStack_8 = (CSceneObject *)&LAB_00acb88b;
  local_c = ExceptionList;
  pCVar1 = (CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  if (*(int **)(this + 0x30) == (int *)0x0) {
    if (param_1 == (CSceneMobil *)0x0) {
      return;
    }
    ExceptionList = &local_c;
    if (param_1 == (CSceneMobil *)0x0) goto LAB_007b29fe;
  }
  else {
    pCVar5 = (CMotions *)0x8028000;
    ExceptionList = &local_c;
    iVar2 = (**(code **)(**(int **)(this + 0x30) + 0x10))();
    if (iVar2 != 0) {
      CMotions::AddMotion(*(CMotions **)(this + 0x30),unaff_retaddr,(CMwNod *)pCVar5,pCVar1,
                          unaff_EDI);
      ExceptionList = pvStack_4;
      return;
    }
    this_00 = operator_new(0x24);
    pCStack_8 = (CSceneObject *)0x0;
    if (this_00 == (CMotions *)0x0) {
      param_1 = (CSceneMobil *)0x0;
    }
    else {
      CMotions::CMotions(this_00,pCVar5);
      param_1 = (CSceneMobil *)extraout_EAX;
    }
    pCStack_8 = (CSceneObject *)0xffffffff;
    pCVar3 = (CMwNod *)0x7b29cd;
    pCVar4 = this;
    (**(code **)(*(int *)param_1 + 0x94))();
    CMotions::AddMotion((CMotions *)param_1,*(CSceneObject **)(this + 0x30),in_stack_ffffffcc,
                        in_stack_ffffffd0,in_stack_ffffffd4);
    CMotions::AddMotion((CMotions *)param_1,pCStack_8,pCVar3,(CMwId *)pCVar4,(int)pCVar5);
    if (param_1 == (CSceneMobil *)*(CMotions **)(this + 0x30)) {
      ExceptionList = local_c;
      return;
    }
  }
  CMwNod::MwAddRef((CMwNod *)param_1,(CMwNod *)pCVar1);
LAB_007b29fe:
  if (*(CMwNod **)(this + 0x30) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x30),(CMwNod *)pCVar1);
  }
  *(CSceneMobil **)(this + 0x30) = param_1;
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CSceneMobil::AddObject
// =================================================
void __thiscall
CSceneMobil::AddObject
          (CSceneMobil *this,CSceneMobil *param_1,CSceneObject *param_2,CSceneObjectLink **param_3)
{
{
  int iVar1;
  CSceneObjectLink *pCVar2;
  CSceneObjectLink *this_00;
  CSceneObjectLink *extraout_EAX;
  CSceneObjectLink *unaff_EBX;
  CSceneMobil *unaff_EBP;
  CSceneObject *unaff_ESI;
  int unaff_EDI;
  CSceneObject local_2c [32];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00acbbfb;
  local_c = ExceptionList;
  pCVar2 = (CSceneObjectLink *)(DAT_00cca150 ^ (uint)&stack0xffffffb0);
  ExceptionList = &local_c;
  if (param_1 != this) {
    if (*(int *)param_2 == 0) {
      this_00 = operator_new(100);
      local_4 = 0;
      if (this_00 == (CSceneObjectLink *)0x0) {
        pCVar2 = (CSceneObjectLink *)0x0;
      }
      else {
        CSceneObjectLink::CSceneObjectLink(this_00,pCVar2);
        pCVar2 = extraout_EAX;
      }
      *(CSceneObjectLink **)param_2 = pCVar2;
      CSceneObjectLink::SetIsActive(pCVar2,(CSceneObjectLink *)0x1,unaff_EDI);
    }
    CSceneObjectLink::SetObject(*(CSceneObjectLink **)param_2,(CSceneObjectLink *)param_1,unaff_ESI)
    ;
    CSceneObjectLink::SetMobil(*(CSceneObjectLink **)param_2,(CSceneObjectLink *)this,unaff_EBP);
    LinkAdd(this,*(CSceneMobil **)param_2,unaff_EBX);
    *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 0x400;
    if (*(int *)(this + 0x14) != 0) {
      iVar1 = **(int **)(this + 0x14);
      CSceneObject::SceneLocGet((CSceneObject *)this,local_2c);
      (**(code **)(iVar1 + 0x78))();
      CSceneObjectLink::OnEnterScene
                (*(CSceneObjectLink **)param_2,*(CSceneToyBroomstick **)(this + 0x14));
    }
  }
  ExceptionList = param_2;
  return;
}
}

// =================================================
// Function: CSceneMobil::AddSolidMotionFromTree
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneMobil::AddSolidMotionFromTree(CSceneMobil *this,CSceneMobil *param_1)
{
{
  int *piVar1;
  CPlugMaterial *this_00;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *pCVar2;
  CSceneMobil *pCVar3;
  CPlugTree *pCVar4;
  CSceneMobil *this_01;
  CPlugTree *pCVar5;
  SLoadedLight *pSVar6;
  ulong uVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  SCasterCat *pSVar9;
  int iVar10;
  CMotionPlayer *extraout_EAX;
  CMotionLight *extraout_EAX_00;
  SSamplerState *pSVar11;
  CMotionPlayer *this_02;
  CMotionPlayer *extraout_EAX_01;
  CMotionLight *extraout_EAX_02;
  CMotionPlayer *pCVar12;
  CMotionPlayer *extraout_EAX_03;
  CMotionLight *extraout_EAX_04;
  CMotionDayTime *pCVar13;
  CMotionDayTime *extraout_EAX_05;
  undefined4 uVar14;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBX;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *pCVar15;
  CMotionLight *pCVar16;
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> *unaff_ESI;
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> *unaff_EDI;
  undefined2 in_FPUControlWord;
  undefined1 uStack0000000c;
  undefined1 in_stack_00000010;
  undefined1 in_stack_00000014;
  undefined1 in_stack_00000018;
  void *in_stack_0000002c;
  CMotionTrackTree *pCVar17;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar18;
  CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *pCVar19;
  CFuncTree *pCVar20;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffff50;
  CFastArray<class_GxTexCoordSet> *pCVar21;
  CMotionPlayer *this_03;
  CMotionTrack *pCVar22;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffff54;
  CMotionPlayer *this_04;
  float fVar23;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_ffffff58;
  CMotion *pCVar24;
  CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
  *in_stack_ffffff5c;
  CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
  *pCVar25;
  CFuncPlug *in_stack_ffffff60;
  undefined2 uVar26;
  CMotionLight *in_stack_ffffff68;
  CFuncPlug *in_stack_ffffff6c;
  CFuncPlug *pCVar27;
  CFuncPlug *pCVar28;
  undefined4 in_stack_ffffff78;
  longlong lVar29;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
  *pCStack_80;
  CMotionPlayer *pCStack_7c;
  CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
  *local_78;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_74;
  CSceneMobil *local_70;
  int local_6c;
  int local_68;
  undefined1 local_64 [4];
  undefined4 uStack_60;
  undefined1 local_5c [4];
  undefined1 local_58 [4];
  undefined1 auStack_54 [4];
  undefined1 local_50 [4];
  undefined1 auStack_4c [8];
  undefined1 auStack_44 [8];
  undefined1 auStack_3c [4];
  undefined1 local_38 [12];
  undefined1 auStack_2c [8];
  undefined1 auStack_24 [16];
  void *local_14;
  undefined1 *local_10;
  undefined4 uStack_c;
  
  pCVar18 = (CFastBuffer<class_CPlugFileSndGen*> *)&stack0xfffffffc;
  uStack_c = 0xffffffff;
  local_10 = &LAB_00acbbca;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  pCVar4 = GetTree(this,(SVolatileTreePointer *)(DAT_00cca150 ^ (uint)&stack0xffffff40));
  if (pCVar4 != (CPlugTree *)0x0) {
    this_01 = (CSceneMobil *)CSystemFile_testerror(unaff_EDI,unaff_ESI);
    CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>::
    CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>(local_38,unaff_EDI);
    CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>::
    CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>(local_58,unaff_ESI);
    pCVar17 = (CMotionTrackTree *)0x7b400a;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(&local_78,pCVar18);
    pCVar19 = (CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)0x7b4013;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(local_5c,unaff_EBX);
    pCVar20 = (CFuncTree *)0x7b401c;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (local_64,in_stack_ffffff50);
    uStack0000000c = 4;
    local_74 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    pCVar3 = this_01;
    while (pCVar3 != (CSceneMobil *)0xffffffff) {
      pCVar20 = (CFuncTree *)0x7b403d;
      pCVar5 = CPlugTree::GetAllTreeNext(pCVar4,(CPlugTree *)&local_70,(ulong *)in_stack_ffffff54);
      if ((*(int *)(pCVar5 + 0xa8) != 0) && (*(int *)(*(int *)(pCVar5 + 0xa8) + 0x14) != 0)) {
        pSVar6 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                           (local_50,in_stack_ffffff58);
        *(CPlugTree **)pSVar6 = pCVar5;
        *(undefined4 *)(pSVar6 + 4) = *(undefined4 *)(pCVar5 + 0xa8);
      }
      if (((*(int *)(pCVar5 + 0x90) != 0) &&
          (piVar1 = *(int **)(*(int *)(pCVar5 + 0x90) + 0x6c), piVar1 != (int *)0x0)) &&
         (*piVar1 != 0)) {
        if (piVar1 == (int *)0x0) {
          iVar10 = 0;
        }
        else {
          iVar10 = *piVar1;
        }
        if (*(int *)(iVar10 + 0x14) != 0) {
          pSVar6 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                             (local_58,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                                       in_stack_ffffff5c);
          *(undefined4 *)pSVar6 = *(undefined4 *)(pCVar5 + 0x90);
          if (*(undefined4 **)(*(int *)(pCVar5 + 0x90) + 0x6c) == (undefined4 *)0x0) {
            uVar14 = 0;
          }
          else {
            uVar14 = **(undefined4 **)(*(int *)(pCVar5 + 0x90) + 0x6c);
          }
          *(undefined4 *)(pSVar6 + 4) = uVar14;
        }
      }
      if (((DAT_00d6ce84 != 0) && (local_6c == 0)) &&
         (this_00 = *(CPlugMaterial **)(pCVar5 + 0x98), this_00 != (CPlugMaterial *)0x0)) {
        uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount
                          (this_00 + 0x20,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff5c);
        if (uVar7 != 0) {
          in_stack_ffffff5c =
               (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                *)0x7b40e1;
          pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CPlugMaterial::GetSupportedDeviceMatIndex
                             (this_00,(CPlugMaterial *)in_stack_ffffff60);
          if (pCVar8 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
            in_stack_ffffff5c =
                 (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                  *)0x7b40ee;
            pSVar9 = CFastArray<struct_CPlugMaterial::SDeviceMat>::operator[]
                               (this_00 + 0x20,pCVar8,(ulong)this);
            in_stack_ffffff60 = (CFuncPlug *)pCVar8;
            if ((pSVar9 != (SCasterCat *)0x0) && (*(int *)(pSVar9 + 8) != *(int *)(pSVar9 + 4))) {
              uStack_60 = 1;
            }
          }
        }
      }
      in_stack_ffffff58 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x9062000;
      in_stack_ffffff54 = (CFastBuffer<class_CCrystalFace*> *)0x7b4110;
      iVar10 = (**(code **)(*(int *)pCVar5 + 0x10))();
      pCVar3 = local_70;
      if ((((iVar10 != 0) &&
           (in_stack_ffffff6c = *(CFuncPlug **)(*(int *)(pCVar5 + 0xac) + 0x14),
           in_stack_ffffff6c != (CFuncPlug *)0x0)) && (*(int *)(in_stack_ffffff6c + 0x14) != 0)) &&
         (*(int *)(pCVar5 + 0xb0) != 0)) {
        pCVar21 = (CFastArray<class_GxTexCoordSet> *)&stack0xffffff6c;
        pCVar20 = (CFuncTree *)
                  CFastArray<class_CGameMenuFrame*>::Find
                            (&local_6c,pCVar21,(GxTexCoordSet *)in_stack_ffffff54);
        if (pCVar20 == (CFuncTree *)0xffffffff) {
          pCVar20 = (CFuncTree *)
                    CFastBuffer<class_CCrystalFace*>::GetCount
                              (&local_68,(CFastBuffer<class_CCrystalFace*> *)pCVar21);
          in_stack_ffffff54 = (CFastBuffer<class_CCrystalFace*> *)0x7b4162;
          CFastBuffer<class_CDx9TextureKeeper*>::Add
                    (local_64,(TiXmlAttributeSet *)&stack0xffffff74,
                     (TiXmlAttribute *)in_stack_ffffff5c);
          in_stack_ffffff5c =
               (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                *)(pCVar20 + 1);
          in_stack_ffffff58 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x7b416f;
          CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetCatCount
                    (auStack_3c,in_stack_ffffff5c,(ulong)in_stack_ffffff60);
        }
        in_stack_ffffff68 = *(CMotionLight **)(pCVar5 + 0xb0);
        pCVar19 = (CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)
                  &stack0xffffff68;
        pCVar17 = (CMotionTrackTree *)0x7b4188;
        CFastBufferCat<class_CNetHttpResult*,struct_SFastCat>::AddInCat
                  (auStack_4c,pCVar19,(CHmsCorpus **)pCVar20,(ulong)pCVar21);
        pCVar3 = local_70;
      }
    }
    this_03 = (CMotionPlayer *)0x7b419c;
    uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount(&local_6c,in_stack_ffffff54);
    lVar29 = CONCAT44(in_stack_ffffff78,uVar7);
    pCVar27 = (CFuncPlug *)0x0;
    if (uVar7 != 0) {
      do {
        pCStack_7c = operator_new(0x58);
        in_stack_00000010 = 5;
        if (pCStack_7c == (CMotionPlayer *)0x0) {
          this_03 = (CMotionPlayer *)0x0;
        }
        else {
          CMotionPlayer::CMotionPlayer(pCStack_7c,(CMotionPlayer *)in_stack_ffffff58);
          this_03 = extraout_EAX;
        }
        in_stack_00000010 = 4;
        uVar7 = 0x7b41ee;
        (**(code **)(*(int *)this_03 + 0x94))();
        pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (&pCStack_7c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar27,
                            (ulong)pCVar17);
        pCVar4 = *(CPlugTree **)pSVar9;
        in_stack_ffffff5c =
             (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
              *)CONCAT22((short)((uint)*(float *)(pCVar4 + 0x20) >> 0x10),in_FPUControlWord);
        lVar29 = (longlong)ROUND(*(float *)(pCVar4 + 0x20) * (float)_DAT_00c418d8);
        CMotionCmdBase::SetPeriod
                  (*(CMotionCmdBase **)(this_03 + 0x30),(CFuncPlug *)lVar29,(float)pCVar19);
        uVar14 = (undefined4)lVar29;
        *(undefined4 *)(*(int *)(this_03 + 0x30) + 0x48) = 1;
        if (*(int *)(pCVar4 + 0x18) == 0) {
          in_stack_ffffff60 = *(CFuncPlug **)(pCVar4 + 0x24);
        }
        else {
          iVar10 = _rand();
          lVar29 = CONCAT44((float)iVar10 / (float)_DAT_00b530f8,uVar14);
          in_stack_ffffff60 = (CFuncPlug *)(((float)iVar10 / (float)_DAT_00b530f8) * 1.0 + 0.0);
        }
        pCVar17 = (CMotionTrackTree *)0x7b4284;
        CMotionCmdBase::SetPhase
                  (*(CMotionCmdBase **)(this_03 + 0x30),in_stack_ffffff60,(float)pCVar20);
        pCVar19 = (CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)0x7b428e;
        pSVar9 = CFastBuffer<struct_SFastCat>::operator[]
                           (auStack_4c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar27,
                            uVar7);
        pCVar2 = *(CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                   **)(pSVar9 + 4);
        pCVar15 = (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                   *)0x0;
        if (pCVar2 != (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                       *)0x0) {
          do {
            pCVar22 = (CMotionTrack *)&DAT_00000038;
            pCVar20 = (CFuncTree *)0x7b42a2;
            in_stack_ffffff68 = operator_new(0x38);
            uStack0000000c = 6;
            if (in_stack_ffffff68 == (CMotionLight *)0x0) {
              pCVar16 = (CMotionLight *)0x0;
              pCVar27 = in_stack_ffffff6c;
            }
            else {
              pCVar22 = (CMotionTrack *)0x7b42bc;
              CMotionLight::CMotionLight(in_stack_ffffff68,(CMotionLight *)pCStack_80);
              pCVar16 = extraout_EAX_00;
              pCVar27 = in_stack_ffffff6c;
            }
            pSVar11 = CFastBufferCat<class_CSceneMobil*,struct_SFastCat>::GetElemInCat
                                (local_58,pCVar15,(ulong)in_stack_ffffff5c,(ulong)pCVar17);
            CMotionLight::SetLight(pCVar16,*(CMotionLight **)pSVar11,(GxLight *)pCVar19);
            pCVar17 = (CMotionTrackTree *)0x7b42eb;
            CMotionTrackTree::SetFuncTree((CMotionTrackTree *)pCVar16,pCVar4,pCVar20);
            pCVar19 = (CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)
                      0x7b42f3;
            CMotionPlayer::AddTrack(this_03,(CMotionPlayer *)pCVar16,pCVar22);
            pCVar15 = pCVar15 + 1;
            in_stack_ffffff6c = pCVar27;
          } while (pCVar15 < pCVar2);
        }
        pCVar20 = (CFuncTree *)0x7b430a;
        AddMotionSolid(this_01,(CSceneMobil *)this_03,(CMotion *)pCStack_80);
        pCVar27 = pCVar27 + 1;
        pCStack_80 = pCVar2;
      } while (pCVar27 < (CFuncPlug *)lVar29);
    }
    this_02 = (CMotionPlayer *)((ulonglong)lVar29 >> 0x20);
    this_04 = (CMotionPlayer *)0x7b4324;
    local_78 = (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                *)CFastBuffer<class_CCrystalFace*>::GetCount
                            (local_50,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff58);
    pCVar28 = (CFuncPlug *)0x0;
    if (local_78 !=
        (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
         *)0x0) {
      do {
        uVar26 = (undefined2)((uint)this >> 0x10);
        this_02 = operator_new(0x58);
        in_stack_00000014 = 7;
        if (this_02 == (CMotionPlayer *)0x0) {
          this_04 = (CMotionPlayer *)0x0;
        }
        else {
          CMotionPlayer::CMotionPlayer(this_02,(CMotionPlayer *)in_stack_ffffff5c);
          this_04 = extraout_EAX_01;
        }
        in_stack_00000014 = 4;
        fVar23 = 1.1319965e-38;
        pSVar9 = CFastBuffer<struct_SFastCat>::operator[]
                           (auStack_4c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar28,
                            (ulong)in_stack_ffffff5c);
        pCVar4 = *(CPlugTree **)(pSVar9 + 4);
        pCVar24 = (CMotion *)0x7b438b;
        in_stack_ffffff5c = local_78;
        (**(code **)(*(int *)this_04 + 0x94))();
        in_stack_ffffff60 = operator_new(0x40);
        if (in_stack_ffffff60 == (CFuncPlug *)0x0) {
          pCVar16 = (CMotionLight *)0x0;
        }
        else {
          CMotionTrackTree::CMotionTrackTree((CMotionTrackTree *)in_stack_ffffff60,pCVar17);
          pCVar16 = extraout_EAX_02;
        }
        CMotionPlayer::AddTrack(this_04,(CMotionPlayer *)pCVar16,(CMotionTrack *)pCVar17);
        CMotionLight::SetLight(pCVar16,*(CMotionLight **)pSVar9,(GxLight *)pCVar19);
        pCVar17 = (CMotionTrackTree *)0x7b43d4;
        CMotionTrackTree::SetFuncTree((CMotionTrackTree *)pCVar16,pCVar4,pCVar20);
        this = (CSceneMobil *)CONCAT22(uVar26,in_FPUControlWord);
        in_stack_ffffff6c =
             (CFuncPlug *)(longlong)ROUND(*(float *)(pCVar4 + 0x20) * (float)_DAT_00c418d8);
        pCVar19 = (CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)0x7b4410;
        CMotionCmdBase::SetPeriod
                  (*(CMotionCmdBase **)(this_04 + 0x30),in_stack_ffffff6c,(float)this_03);
        *(undefined4 *)(*(int *)(this_04 + 0x30) + 0x48) = 1;
        pCVar27 = *(CFuncPlug **)(pCVar4 + 0x24);
        pCVar20 = (CFuncTree *)0x7b4431;
        CMotionCmdBase::SetPhase(*(CMotionCmdBase **)(this_04 + 0x30),pCVar27,fVar23);
        this_03 = (CMotionPlayer *)0x7b443b;
        AddMotionSolid((CSceneMobil *)pCStack_80,(CSceneMobil *)this_04,pCVar24);
        pCVar28 = pCVar28 + 1;
      } while (pCVar28 < local_78);
    }
    local_74 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (local_58,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff5c);
    pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (local_74 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        uVar26 = (undefined2)((uint)in_stack_ffffff68 >> 0x10);
        pCVar12 = operator_new(0x58);
        in_stack_00000018 = 9;
        if (pCVar12 == (CMotionPlayer *)0x0) {
          pCVar12 = (CMotionPlayer *)0x0;
        }
        else {
          CMotionPlayer::CMotionPlayer(pCVar12,(CMotionPlayer *)in_stack_ffffff60);
          pCVar12 = extraout_EAX_03;
        }
        in_stack_00000018 = 4;
        fVar23 = 1.1320394e-38;
        pCVar25 = local_78;
        (**(code **)(*(int *)pCVar12 + 0x94))();
        in_stack_ffffff60 = operator_new(0x3c);
        if (in_stack_ffffff60 == (CFuncPlug *)0x0) {
          pCVar16 = (CMotionLight *)0x0;
        }
        else {
          CMotionTrackVisual::CMotionTrackVisual
                    ((CMotionTrackVisual *)in_stack_ffffff60,(CMotionTrackVisual *)pCVar17);
          pCVar16 = extraout_EAX_04;
        }
        CMotionPlayer::AddTrack(pCVar12,(CMotionPlayer *)pCVar16,(CMotionTrack *)pCVar17);
        pSVar9 = CFastBuffer<struct_SFastCat>::operator[](&local_6c,pCVar8,(ulong)pCVar19);
        pCVar17 = (CMotionTrackTree *)0x7b44f4;
        CMotionLight::SetLight(pCVar16,*(CMotionLight **)pSVar9,(GxLight *)pCVar20);
        pCVar4 = *(CPlugTree **)(pSVar9 + 4);
        pCVar19 = (CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)0x7b44ff;
        CMotionTrackTree::SetFuncTree((CMotionTrackTree *)pCVar16,pCVar4,(CFuncTree *)this_03);
        in_stack_ffffff68 = (CMotionLight *)CONCAT22(uVar26,in_FPUControlWord);
        pCVar27 = (CFuncPlug *)(longlong)ROUND(*(float *)(pCVar4 + 0x20) * (float)_DAT_00c418d8);
        pCVar20 = (CFuncTree *)0x7b453b;
        CMotionCmdBase::SetPeriod(*(CMotionCmdBase **)(pCVar12 + 0x30),pCVar27,(float)this_04);
        *(undefined4 *)(*(int *)(pCVar12 + 0x30) + 0x48) = 1;
        pCVar28 = *(CFuncPlug **)(pCVar4 + 0x24);
        this_03 = (CMotionPlayer *)0x7b455c;
        CMotionCmdBase::SetPhase(*(CMotionCmdBase **)(pCVar12 + 0x30),pCVar28,fVar23);
        this_04 = (CMotionPlayer *)0x7b4566;
        AddMotionSolid((CSceneMobil *)pCStack_7c,(CSceneMobil *)pCVar12,(CMotion *)pCVar25);
        pCVar8 = pCVar8 + 1;
      } while (pCVar8 < local_74);
    }
    pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)local_78;
    if (local_68 != 0) {
      pCVar13 = operator_new(0x48);
      in_stack_00000018 = 0xb;
      if (pCVar13 == (CMotionDayTime *)0x0) {
        pCVar13 = (CMotionDayTime *)0x0;
      }
      else {
        CMotionDayTime::CMotionDayTime(pCVar13,(CMotionDayTime *)in_stack_ffffff60);
        pCVar13 = extraout_EAX_05;
      }
      in_stack_00000018 = 4;
      CMotionDayTime::SetMaterialMode
                (pCVar13,(CMotionDayTime *)0x1,(EMaterialMode)in_stack_ffffff60);
      pCVar8 = local_74;
      pCVar24 = (CMotion *)0x7b45c3;
      in_stack_ffffff60 = (CFuncPlug *)local_74;
      (**(code **)(*(int *)pCVar13 + 0x94))();
      AddMotionSolid((CSceneMobil *)pCVar8,(CSceneMobil *)pCVar13,pCVar24);
    }
    if (*(int **)(pCVar8 + 0x30) != (int *)0x0) {
      (**(code **)(**(int **)(pCVar8 + 0x30) + 0x78))();
    }
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (auStack_54,(CFastBuffer<class_CPlugFileGPUV*> *)in_stack_ffffff60);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (auStack_44,(CFastBuffer<class_CPlugFileGPUV*> *)this);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (local_58,(CFastBuffer<class_CPlugFileGPUV*> *)in_stack_ffffff68);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (auStack_24,(CFastBuffer<class_CPlugFileGPUV*> *)in_stack_ffffff6c);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (auStack_2c,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar27);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (&stack0x00000008,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar28);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (&stack0x00000000,(CFastBuffer<class_CPlugFileGPUV*> *)this_02);
  }
  ExceptionList = in_stack_0000002c;
  return;
}
}

// =================================================
// Function: CSceneMobil::AddTree
// =================================================
void __cdecl CSceneMobil::AddTree(CPlugTree *param_1)
{
{
  CPlugSolid *pCVar1;
  CPlugSolid *this;
  CSceneToyMotorbike *extraout_EAX;
  CSceneToyMotorbike *pCVar2;
  int in_ECX;
  CPlugTree *in_stack_00000008;
  void *local_c;
  undefined1 *local_8;
  CSceneToyMotorbike *local_4;
  
  local_4 = (CSceneToyMotorbike *)0xffffffff;
  local_8 = &LAB_00acb8bb;
  local_c = ExceptionList;
  pCVar1 = (CPlugSolid *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  pCVar2 = *(CSceneToyMotorbike **)(*(int *)(in_ECX + 0x28) + 0x14);
  if (pCVar2 == (CSceneToyMotorbike *)0x0) {
    this = operator_new(0x74);
    local_4 = pCVar2;
    if (this == (CPlugSolid *)0x0) {
      pCVar2 = (CSceneToyMotorbike *)0x0;
    }
    else {
      CPlugSolid::CPlugSolid(this,pCVar1);
      pCVar2 = extraout_EAX;
    }
  }
  CPlugSolid::AddTree(in_stack_00000008);
  if (*(int *)(*(CHmsItem **)(in_ECX + 0x28) + 0x14) == 0) {
    CHmsItem::SetSolid(*(CHmsItem **)(in_ECX + 0x28),pCVar2,(CPlugSolid *)in_stack_00000008);
  }
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CSceneMobil::AddVisual
// =================================================
CPlugTree * __thiscall
CSceneMobil::AddVisual
          (CSceneMobil *this,CSceneMobil *param_1,CPlugVisual *param_2,CPlugShader *param_3,
          CPlugMaterial *param_4)
{
{
  CPlugTree *pCVar1;
  CPlugTree *this_00;
  CPlugTree *extraout_EAX;
  void *unaff_ESI;
  CPlugTree *this_01;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00acb95b;
  local_c = ExceptionList;
  pCVar1 = (CPlugTree *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  this_00 = operator_new(0xac);
  this_01 = (CPlugTree *)0x0;
  local_4 = 0;
  if (this_00 != (CPlugTree *)0x0) {
    CPlugTree::CPlugTree(this_00,pCVar1);
    this_01 = extraout_EAX;
  }
  CPlugTree::SetVisual(this_01,(CVisionVisualKeeper *)param_2,(CPlugVisual *)param_3);
  AddTree(this_01);
  ExceptionList = unaff_ESI;
  return this_01;
}
}

// =================================================
// Function: CSceneMobil::ArchiveOwnDataOld
// =================================================
void __thiscall
CSceneMobil::ArchiveOwnDataOld(CSceneMobil *this,CSceneToyTrain *param_1,CClassicArchive *param_2)
{
{
  CFastArray<struct_CDx9DeviceCaps::SFormat> *pCVar1;
  ulong uVar2;
  int iVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  CClassicArchive *unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CClassicArchive *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CClassicArchive *in_stack_0000000c;
  CClassicArchive *pCVar7;
  CClassicArchive *pCVar8;
  CFastArray<class_CManoeuvre*> *pCVar9;
  CClassicArchive *pCVar10;
  undefined4 local_24;
  int local_20;
  undefined1 auStack_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 auStack_10 [4];
  void *local_c;
  undefined1 *local_8;
  CClassicArchive *pCStack_4;
  
  pCStack_4 = (CClassicArchive *)0xffffffff;
  local_8 = &LAB_00acbc90;
  local_c = ExceptionList;
  pCVar1 = (CFastArray<struct_CDx9DeviceCaps::SFormat> *)(DAT_00cca150 ^ (uint)&stack0xffffffcc);
  ExceptionList = &local_c;
  pCVar10 = (CClassicArchive *)0x0;
  pCVar9 = (CFastArray<class_CManoeuvre*> *)0x1;
  pCVar8 = (CClassicArchive *)&local_24;
  local_24 = 2;
  pCVar7 = (CClassicArchive *)0x7b4a85;
  CClassicArchive::DoNatural((CClassicArchive *)param_1,pCVar8,(ulong *)0x1,0,(int)pCVar1);
  if (local_20 == 0) {
    CMwId::Archive(this + 0x18,(CFastCrypt<unsigned_long> *)param_1,unaff_EDI);
  }
  else {
    if (local_20 != 1) {
      if (local_20 != 2) {
        ExceptionList = pCStack_4;
        return;
      }
      if (*(int *)(param_1 + 8) == 0) {
        pCVar10 = (CClassicArchive *)&param_2;
        pCVar9 = (CFastArray<class_CManoeuvre*> *)0x7b4ab7;
        CClassicArchive::ReadMask((CClassicArchive *)param_1,pCVar10,(ulong *)0x1,(ulong)unaff_EDI);
        pCVar1 = (CFastArray<struct_CDx9DeviceCaps::SFormat> *)0x7b4ac1;
        uVar2 = CMwDeprecated::WrapClassId((ulong)in_stack_0000000c);
        unaff_EDI = in_stack_0000000c;
        while (uVar2 != 0xffffffff) {
          CClassicArchive::ReadNatural
                    ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xffffffd4,(ulong *)0x1,0,
                     (int)pCVar8);
          pCVar8 = unaff_EBX;
          (**(code **)(*(int *)this + 0xcc))(param_1);
          CClassicArchive::ReadMask
                    ((CClassicArchive *)param_1,(CClassicArchive *)&local_c,(ulong *)0x1,uVar2);
          uVar2 = CMwDeprecated::WrapClassId((ulong)local_8);
        }
      }
      else {
        pCVar1 = (CFastArray<struct_CDx9DeviceCaps::SFormat> *)0x7b4b23;
        iVar3 = (**(code **)(*(int *)this + 8))();
        for (; (iVar3 != 0 &&
               (pCVar4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 4),
               pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xa011000));
            iVar3 = *(int *)(iVar3 + 8)) {
          local_c = (void *)(**(code **)(*(int *)this + 0xd0))(pCVar4);
          if (local_c != (void *)0x0) {
            CClassicArchive::WriteMask
                      ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xffffffd0,(ulong *)0x1,
                       (ulong)pCVar7);
            CClassicArchive::WriteNatural
                      ((CClassicArchive *)param_1,(CClassicArchive *)&local_8,(ulong *)0x1,0,
                       (int)pCVar8);
            pCVar7 = unaff_EBX;
            pCVar8 = pCStack_4;
            (**(code **)(*(int *)this + 0xcc))(param_1);
          }
          unaff_ESI = pCVar4;
        }
        unaff_EBP = 0xffffffff;
        CClassicArchive::WriteMask
                  ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xffffffd4,(ulong *)0x1,
                   (ulong)pCVar7);
      }
    }
    CMwId::Archive(this + 0x18,(CFastCrypt<unsigned_long> *)param_1,pCVar8);
    if (*(int *)(param_1 + 8) == 0) {
      CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(&local_24,pCVar9);
      local_8 = (undefined1 *)0x0;
      CFastArray<class_CPlugSoundEngineComponent*>::ArchiveCountAndNods
                (&local_20,(CFastArray<class_CPlugSoundEngineComponent*> *)param_1,pCVar10);
      pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (auStack_1c,(CFastBuffer<class_CCrystalFace*> *)pCVar1);
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (local_18,pCVar6,(ulong)unaff_EDI);
          AddObject(this,*(CSceneMobil **)(*(int *)pSVar5 + 0x18),(CSceneObject *)pSVar5,
                    (CSceneObjectLink **)unaff_ESI);
          unaff_EDI = (CClassicArchive *)0x7b4c05;
          unaff_ESI = pCVar6;
          pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (auStack_10,pCVar6,unaff_EBP);
          *(uint *)(*(int *)pSVar5 + 0x14) = *(uint *)(*(int *)pSVar5 + 0x14) & 0xffffffdf;
          pCVar6 = pCVar6 + 1;
        } while (pCVar6 < pCVar4);
      }
      CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>
                (local_18,(CFastArray<class_CFuncShader*> *)unaff_EDI);
    }
    else {
      CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(auStack_1c,pCVar9);
      local_8 = (undefined1 *)0x1;
      pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (this + 0x38,(CFastBuffer<class_CCrystalFace*> *)pCVar10);
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this + 0x38,pCVar6,(ulong)pCVar1);
          param_2 = *(CClassicArchive **)pSVar5;
          if (((*(uint *)(param_2 + 0x14) & 0x10) != 0) && ((*(uint *)(param_2 + 0x14) & 0x20) == 0)
             ) {
            pCVar1 = (CFastArray<struct_CDx9DeviceCaps::SFormat> *)&param_2;
            CFastArray<class_CFastBuffer<class_CSceneMobil*>*>::AddTail
                      (auStack_10,pCVar1,(SFormat *)unaff_EDI);
          }
          pCVar6 = pCVar6 + 1;
        } while (pCVar6 < pCVar4);
      }
      CFastArray<class_CPlugSoundEngineComponent*>::ArchiveCountAndNods
                (local_14,(CFastArray<class_CPlugSoundEngineComponent*> *)param_1,
                 (CClassicArchive *)pCVar1);
      CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>
                (auStack_10,(CFastArray<class_CFuncShader*> *)unaff_EDI);
    }
  }
  ExceptionList = pCStack_4;
  return;
}
}

// =================================================
// Function: CSceneMobil::CSceneMobil
// =================================================
void __thiscall CSceneMobil::CSceneMobil(CSceneMobil *this,CSceneMobil *param_1)
{
{
  int extraout_EAX;
  int iVar1;
  CHmsItem *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  void *local_c;
  CHmsItem *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = (CHmsItem *)&LAB_00acbb1a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSceneObject::CSceneObject
            ((CSceneObject *)this,(CSceneObject *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x38,unaff_EDI);
  *(undefined4 *)(this + 0x44) = 0;
  local_8 = operator_new(0x58);
  if (local_8 == (CHmsItem *)0x0) {
    iVar1 = 0;
  }
  else {
    CHmsItem::CHmsItem(local_8,unaff_ESI);
    iVar1 = extraout_EAX;
  }
  *(int *)(this + 0x28) = iVar1;
  *(CSceneMobil **)(iVar1 + 0x40) = this;
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: CSceneMobil::Chunk
// =================================================
void __thiscall
CSceneMobil::Chunk(CSceneMobil *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  CFastArray<class_CManoeuvre*> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CSceneMobil *pCVar4;
  code *pcVar5;
  CFastArray<class_CFuncShader*> *unaff_EBX;
  void *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CClassicArchive *unaff_EDI;
  undefined1 *puVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffd4;
  ulong in_stack_ffffffd8;
  undefined1 local_24 [4];
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_20;
  undefined1 local_1c [4];
  undefined1 auStack_18 [4];
  void *local_14;
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0xffffffff;
  local_10 = &LAB_00acbc60;
  local_14 = ExceptionList;
  pCVar1 = (CFastArray<class_CManoeuvre*> *)(DAT_00cca150 ^ (uint)&stack0xffffffc8);
  if (param_2 < (CClassicArchive *)0xa011005) {
    if (param_2 != (CClassicArchive *)0xa011004) {
      switch(param_2) {
      case (CClassicArchive *)0xa011000:
      case (CClassicArchive *)0xa011001:
      case (CClassicArchive *)0xa011002:
        goto switchD_007b4841_caseD_a011000;
      case (CClassicArchive *)0xa011003:
        if (*(int *)(param_1 + 8) == 0) {
          ExceptionList = &local_14;
          CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(&stack0xffffffd8,pCVar1);
          local_8 = 0;
          CFastArray<class_CPlugSoundEngineComponent*>::ArchiveCountAndNods
                    (local_24,(CFastArray<class_CPlugSoundEngineComponent*> *)param_1,unaff_EDI);
          pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<class_CCrystalFace*>::GetCount(&local_20,unaff_ESI);
          pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            do {
              pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (local_1c,pCVar6,(ulong)unaff_EBX);
              AddObject(this,*(CSceneMobil **)(*(int *)pSVar3 + 0x18),(CSceneObject *)pSVar3,
                        (CSceneObjectLink **)in_stack_ffffffd4);
              unaff_EBX = (CFastArray<class_CFuncShader*> *)0x7b48a2;
              in_stack_ffffffd4 = pCVar6;
              pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (&local_14,pCVar6,in_stack_ffffffd8);
              *(uint *)(*(int *)pSVar3 + 0x14) = *(uint *)(*(int *)pSVar3 + 0x14) | 0x20;
              pCVar6 = pCVar6 + 1;
            } while (pCVar6 < pCVar2);
          }
          CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>(local_1c,unaff_EBX);
          ExceptionList = unaff_EBP;
          return;
        }
        ExceptionList = &local_14;
        CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(&local_20,pCVar1);
        local_8 = 1;
        local_20 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<class_CCrystalFace*>::GetCount
                             (this + 0x38,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
        pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (local_20 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pCVar6 = pCVar2;
            pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this + 0x38,pCVar2,(ulong)unaff_ESI);
            local_20 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar3;
            if ((*(uint *)(local_20 + 0x14) & 0x10) != 0) {
              if ((*(uint *)(local_20 + 0x14) & 0x20) == 0) {
                unaff_ESI = (CFastBuffer<class_CCrystalFace*> *)0x7b4912;
                pCVar4 = GetModel(this,(CSceneMobil *)0x7b4912);
                if (pCVar4 != (CSceneMobil *)0x0) goto LAB_007b4924;
              }
              CFastArray<class_CFastBuffer<class_CSceneMobil*>*>::AddTail
                        (local_1c,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)&stack0xffffffd8,
                         (SFormat *)pCVar6);
            }
LAB_007b4924:
            pCVar2 = pCVar2 + 1;
          } while (pCVar2 < local_20);
        }
        CFastArray<class_CPlugSoundEngineComponent*>::ArchiveCountAndNods
                  (auStack_18,(CFastArray<class_CPlugSoundEngineComponent*> *)param_1,
                   (CClassicArchive *)unaff_ESI);
        CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>(&local_14,unaff_EBX);
        ExceptionList = unaff_EBP;
        return;
      default:
        goto switchD_007b4841_default;
      }
    }
    pcVar5 = *(code **)(*(int *)param_1 + 4);
    puVar7 = &stack0xffffffd8;
    ExceptionList = &local_14;
  }
  else {
    if (param_2 != (CClassicArchive *)0xa011005) {
      if (param_2 == (CClassicArchive *)0xa011006) {
        pCVar4 = *(CSceneMobil **)(this + 0x44);
        ExceptionList = &local_14;
        (**(code **)(*(int *)param_1 + 4))(&stack0xffffffd4);
        if (*(int *)(param_1 + 8) != 0) {
          ExceptionList = local_14;
          return;
        }
        SetMessageHandler(this,pCVar4,(CSceneMessageHandler *)pCVar1);
        ExceptionList = local_10;
        return;
      }
      if (param_2 == (CClassicArchive *)0xffffffff) {
        return;
      }
switchD_007b4841_default:
      ExceptionList = &local_14;
      CSceneObject::Chunk((CSceneObject *)this,param_1,param_2,(ulong)pCVar1);
      ExceptionList = local_10;
      return;
    }
    ExceptionList = &local_14;
    (**(code **)(**(int **)(this + 0x28) + 0x34))(param_1);
    if (*(int *)(param_1 + 8) != 0) {
      ExceptionList = local_14;
      return;
    }
    puVar7 = *(undefined1 **)(*(int *)(this + 0x28) + 0x14);
    pcVar5 = *(code **)(*(int *)this + 0xd8);
  }
  (*pcVar5)(puVar7);
switchD_007b4841_caseD_a011000:
  ExceptionList = local_14;
  return;
}
}

// =================================================
// Function: CSceneMobil::CopyLinksFromMobil
// =================================================
void __thiscall
CSceneMobil::CopyLinksFromMobil(CSceneMobil *this,CSceneMobil *param_1,CSceneMobil *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CSceneObjectLink **unaff_EBX;
  CSceneMobil *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 in_stack_0000000c;
  int in_stack_00000010;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_1 + 0x38,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_1 + 0x38,pCVar3,(ulong)unaff_ESI);
      in_stack_0000000c = *(undefined4 *)pSVar2;
      CSystemArchiveNod::Duplicate
                ((CSystemArchiveNod *)&stack0x0000000c,(CPlugVisualVertexs *)&stack0x0000000c);
      unaff_ESI = *(CSceneMobil **)(in_stack_00000010 + 0x18);
      AddObject(this,unaff_ESI,(CSceneObject *)&stack0x00000010,unaff_EBX);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::CreateDefaultData
// =================================================
void __thiscall CSceneMobil::CreateDefaultData(CSceneMobil *this,CCrystal *param_1)
{
{
                    /* WARNING: Could not recover jumptable at 0x007b2548. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(this + 0x28) + 0x4c))();
  return;
}
}

// =================================================
// Function: CSceneMobil::CreateModelInstance
// =================================================
CPlugSolid * __thiscall CSceneMobil::CreateModelInstance(CSceneMobil *this,CPlugSolid *param_1)
{
{
  CMwNod *pCVar1;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar2;
  SCasterCat *pSVar3;
  CSystemArchiveNod *extraout_ECX;
  CSystemArchiveNod *extraout_ECX_00;
  CSystemArchiveNod *this_00;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastArray<class_CManoeuvre*> *unaff_EDI;
  void *in_stack_0000000c;
  CFastBuffer<class_CCrystalFace*> *pCVar6;
  undefined1 *puVar7;
  CPlugSolid *in_stack_ffffffd0;
  CSystemEngine *pCVar8;
  CMwNod *in_stack_ffffffd4;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffffd8;
  undefined1 local_24 [4];
  CSceneMobil *local_20;
  CSceneMobil *pCStack_1c;
  CPlugSolid *pCStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  puVar7 = &stack0xfffffffc;
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00acba50;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (local_24,(CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffc0)
            );
  pCVar6 = (CFastBuffer<class_CCrystalFace*> *)&local_20;
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  local_8 = 0;
  (**(code **)(*(int *)this + 0xb4))();
  pCVar2 = (CFastBuffer<class_CSystemFidsFolder*> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(local_24,pCVar6);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(&stack0xffffffd8,unaff_EDI);
  CFastArray<struct_SNodFid>::SetCount(local_24,pCVar2,unaff_ESI);
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d73300 + 0x20),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,(ulong)puVar7)
  ;
  DAT_00d6ce94 = *(CSystemEngine **)pSVar3;
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  this_00 = extraout_ECX;
  if (pCVar2 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](&local_14,pCVar5,unaff_EBX)
      ;
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[](&pCStack_18,pCVar5,*(ulong *)pSVar3);
      unaff_EBX = 0x7b375e;
      SNodFid::SetNoDuplicate(pSVar3,(SNodFid *)in_stack_ffffffd0,in_stack_ffffffd4);
      pCVar5 = pCVar5 + 1;
      this_00 = extraout_ECX_00;
    } while (pCVar5 < pCVar2);
  }
  local_20 = this;
  CSystemArchiveNod::Duplicate(this_00,(CPlugVisualVertexs *)&local_20);
  SetModel(pCStack_1c,(CPlugSolid *)this,in_stack_ffffffd0);
  if (pCVar2 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
    do {
      pCVar5 = pCVar4;
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[](&local_14,pCVar4,(ulong)in_stack_ffffffd4);
      pCVar8 = *(CSystemEngine **)pSVar3;
      pCVar1 = *(CMwNod **)(pCVar8 + 8);
      if (*(int *)(pSVar3 + 4) == 0) {
        in_stack_ffffffd4 = pCVar1;
        CSystemEngine::UnbindFidNod(DAT_00d6ce94,pCVar8,pCVar1,(CSystemFid *)in_stack_ffffffd8);
        pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar8;
        if (pCVar1 != (CMwNod *)0x0) {
          in_stack_ffffffd8 = (CFastBuffer<class_CPlugFileGPUV*> *)0x1;
          in_stack_ffffffd4 = (CMwNod *)0x7b37b8;
          (**(code **)(*(int *)pCVar1 + 4))();
          pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar8;
        }
      }
      CMwNod::MwRelease(*(CMwNod **)pSVar3,(CMwNod *)pCVar5);
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>
            (&local_14,(CFastArray<class_CFuncShader*> *)in_stack_ffffffd4);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(&local_8,in_stack_ffffffd8);
  ExceptionList = in_stack_0000000c;
  return pCStack_18;
}
}

// =================================================
// Function: CSceneMobil::DisconnectFromModel
// =================================================
void __thiscall CSceneMobil::DisconnectFromModel(CSceneMobil *this,CPlugSolid *param_1,int param_2)
{
{
  CPlugSolid *unaff_retaddr;
  
  SetModel(this,(CPlugSolid *)0x0,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CSceneMobil::DoMobilPtr
// =================================================
void __cdecl
CSceneMobil::DoMobilPtr(CSceneMobil **param_1,CClassicArchive *param_2,EDoMobilPtrVersion param_3)
{
{
  CClassicArchive *this;
  EDoMobilPtrVersion EVar1;
  SCasterCat *pSVar2;
  CSceneMobil *pCVar3;
  int iVar4;
  CSystemArchiveNod *extraout_ECX;
  CSceneMobil *unaff_EBX;
  CClassicArchive *unaff_ESI;
  CSceneMobil **unaff_EDI;
  CClassicArchive *unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000010;
  
  this = param_2;
  if (param_3 == 0) {
    InternalDoMobilPtr(unaff_EDI,unaff_ESI);
    return;
  }
  if (*(int *)(param_2 + 8) == 0) {
    CClassicArchive::ReadNatural(param_2,(CClassicArchive *)&param_2,(ulong *)0x1,0,(int)unaff_EBX);
    if (param_3 == 0xffffffff) {
      *(undefined4 *)param_2 = 0;
      return;
    }
    if (param_3 == 0xfffffffe) {
      (**(code **)(*(int *)this + 4))(param_2);
      return;
    }
    pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (this + 0x34,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_3,
                        (ulong)unaff_EDI);
    EVar1 = param_3;
    iVar4 = *(int *)pSVar2;
    *(int *)param_3 = iVar4;
    if (iVar4 == 0) {
      InternalDoMobilPtr((CSceneMobil **)unaff_ESI,unaff_retaddr);
      pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this + 0x34,in_stack_00000010,(ulong)unaff_ESI);
      *(undefined4 *)pSVar2 = *(undefined4 *)EVar1;
      return;
    }
  }
  else {
    if (*param_1 == (CSceneMobil *)0x0) {
      param_2 = (CClassicArchive *)0xffffffff;
      CClassicArchive::WriteNatural(this,(CClassicArchive *)&param_2,(ulong *)0x1,0,(int)unaff_EBX);
      return;
    }
    pCVar3 = GetModel(*param_1,unaff_EBX);
    if (pCVar3 == (CSceneMobil *)0x0) {
      param_3 = 0xfffffffe;
      CClassicArchive::WriteNatural(this,(CClassicArchive *)&param_3,(ulong *)0x1,0,(int)unaff_EDI);
      (**(code **)(*(int *)this + 4))(param_1);
      return;
    }
    param_3 = 0;
    iVar4 = CSystemArchiveNod::AddInternalRef
                      ((CSystemArchiveNod *)this,extraout_ECX,(CMwNod *)&param_3,
                       (ulong *)"DoMobilPtr",(char *)unaff_EDI);
    CClassicArchive::WriteNatural
              (this,(CClassicArchive *)&stack0x00000010,(ulong *)0x1,0,(int)unaff_ESI);
    if (iVar4 != 0) {
      InternalDoMobilPtr((CSceneMobil **)unaff_retaddr,(CClassicArchive *)param_1);
    }
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::DoesMotionChangeLocations
// =================================================
int __thiscall CSceneMobil::DoesMotionChangeLocations(CSceneMobil *this,CSceneMobil *param_1)
{
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  if (*(int **)(this + 0x20) == (int *)0x0) {
LAB_007b2a50:
    bVar1 = false;
  }
  else {
    iVar3 = (**(code **)(**(int **)(this + 0x20) + 0xa0))();
    if (iVar3 == 0) goto LAB_007b2a50;
    bVar1 = true;
  }
  if (*(int **)(this + 0x30) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(this + 0x30) + 0xa0))();
    if (iVar3 != 0) {
      bVar2 = true;
      goto LAB_007b2a70;
    }
  }
  bVar2 = false;
LAB_007b2a70:
  if ((!bVar1) && (!bVar2)) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CSceneMobil::EnableAbsorbContactCallback
// =================================================
void __thiscall
CSceneMobil::EnableAbsorbContactCallback(CSceneMobil *this,CSceneMobil *param_1,int param_2)
{
{
  CCallback *unaff_retaddr;
  
  if (param_1 != (CSceneMobil *)0x0) {
    CHmsItem::CallbackSet(*(CHmsItem **)(this + 0x28),(CHmsItem *)0x2,0xd062ac,unaff_retaddr);
    return;
  }
  CHmsItem::CallbackSet(*(CHmsItem **)(this + 0x28),(CHmsItem *)0x2,0,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CSceneMobil::FindOrAddNewTreeWithId
// =================================================
CPlugTree * __thiscall
CSceneMobil::FindOrAddNewTreeWithId(CSceneMobil *this,CSceneMobil *param_1,CMwId *param_2)
{
{
  int *piVar1;
  CPlugTree *pCVar2;
  CPlugTree *pCVar3;
  CPlugTree *extraout_EAX;
  CPlugTree *this_00;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00acb8eb;
  local_c = ExceptionList;
  pCVar2 = (CPlugTree *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  this_00 = (CPlugTree *)0x0;
  if (((*(int *)(*(int *)(this + 0x28) + 0x14) != 0) &&
      (piVar1 = *(int **)(*(int *)(*(int *)(this + 0x28) + 0x14) + 100), piVar1 != (int *)0x0)) &&
     (pCVar3 = (CPlugTree *)(**(code **)(*piVar1 + 0xb4))(param_1), pCVar3 != (CPlugTree *)0x0)) {
    ExceptionList = local_c;
    return pCVar3;
  }
  pCVar3 = operator_new(0xac);
  uStack_4 = 0;
  if (pCVar3 != (CPlugTree *)0x0) {
    CPlugTree::CPlugTree(pCVar3,pCVar2);
    this_00 = extraout_EAX;
  }
  uStack_4 = 0xffffffff;
  CPlugTree::SetPlugId(this_00,(CPlugTree *)param_1,(CMwId *)pCVar2);
  AddTree(this_00);
  ExceptionList = local_c;
  return this_00;
}
}

// =================================================
// Function: CSceneMobil::GetChunkInfo
// =================================================
ulong __thiscall CSceneMobil::GetChunkInfo(CSceneMobil *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if ((CFuncSegment *)0xa011004 < param_1) {
    if ((param_1 == (CFuncSegment *)0xa011005) || (param_1 == (CFuncSegment *)0xa011006)) {
switchD_007b24e8_caseD_a011003:
      return 3;
    }
    if (param_1 == (CFuncSegment *)0xffffffff) {
      return 0xffffffff;
    }
switchD_007b24e8_default:
    uVar1 = CSceneObject::GetChunkInfo((CSceneObject *)this,param_1,param_2);
    return uVar1;
  }
  if (param_1 == (CFuncSegment *)0xa011004) {
switchD_007b24e8_caseD_a011000:
    return 1;
  }
  switch(param_1) {
  case (CFuncSegment *)0xa011000:
  case (CFuncSegment *)0xa011001:
  case (CFuncSegment *)0xa011002:
    goto switchD_007b24e8_caseD_a011000;
  case (CFuncSegment *)0xa011003:
    goto switchD_007b24e8_caseD_a011003;
  default:
    goto switchD_007b24e8_default;
  }
}
}

// =================================================
// Function: CSceneMobil::GetEdBoundingBox
// =================================================
void __thiscall
CSceneMobil::GetEdBoundingBox(CSceneMobil *this,CSceneSoundSource *param_1,GmBoxAligned *param_2)
{
{
  CPlugTree *pCVar1;
  SVolatileTreePointer *unaff_retaddr;
  
  pCVar1 = GetTree(this,unaff_retaddr);
  *(undefined4 *)param_2 = *(undefined4 *)(pCVar1 + 0x34);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(pCVar1 + 0x38);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(pCVar1 + 0x3c);
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(pCVar1 + 0x40);
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(pCVar1 + 0x44);
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(pCVar1 + 0x48);
  return;
}
}

// =================================================
// Function: CSceneMobil::GetInterpolatedLocation
// =================================================
GmIso4 * __thiscall
CSceneMobil::GetInterpolatedLocation(CSceneMobil *this,CSceneObject *param_1,CSceneSector *param_2)
{
{
  CHmsItem *this_00;
  CHmsCorpus *pCVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CHmsZone *unaff_retaddr;
  
  if (param_1 != (CSceneObject *)0x0) {
    pCVar1 = CHmsItem::GetCorpus(*(CHmsItem **)(this + 0x28),*(CHmsItem **)(param_1 + 0x38),
                                 unaff_retaddr);
    return (GmIso4 *)(pCVar1 + 0x18);
  }
  this_00 = *(CHmsItem **)(this + 0x28) + 0x34;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
  if (uVar2 != 0) {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)unaff_retaddr);
    return (GmIso4 *)(*(int *)pSVar3 + 0x18);
  }
  return (GmIso4 *)0x0;
}
}

// =================================================
// Function: CSceneMobil::GetIsVisible
// =================================================
int __thiscall CSceneMobil::GetIsVisible(CSceneMobil *this,CControlBase *param_1)
{
{
  CPlugTree *pCVar1;
  SVolatileTreePointer *unaff_retaddr;
  
  pCVar1 = GetTree(this,unaff_retaddr);
  if (pCVar1 != (CPlugTree *)0x0) {
    return *(uint *)(pCVar1 + 0x9c) >> 3 & 1;
  }
  return 0;
}
}

// =================================================
// Function: CSceneMobil::GetLocation
// =================================================
void __thiscall CSceneMobil::GetLocation(CSceneMobil *this,GmLocFreeVal *param_1,GmIso4 *param_2)
{
{
  CHmsItem *this_00;
  CHmsItem *this_01;
  ulong uVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  GmIso4 *unaff_retaddr;
  
  if (param_1 != (GmLocFreeVal *)0x0) {
    CHmsItem::GetLocation(*(CHmsItem **)(this + 0x28),*(GmLocFreeVal **)(param_1 + 0x38),param_2);
    return;
  }
  this_01 = *(CHmsItem **)(this + 0x28);
  this_00 = this_01 + 0x34;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (uVar1 != 0) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
    CHmsItem::GetLocation(this_01,*(GmLocFreeVal **)(*(int *)pSVar2 + 0x14),unaff_retaddr);
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::GetModel
// =================================================
CSceneMobil * __thiscall CSceneMobil::GetModel(CSceneMobil *this,CSceneMobil *param_1)
{
{
  return *(CSceneMobil **)(this + 0x2c);
}
}

// =================================================
// Function: CSceneMobil::GetMwClassId
// =================================================
ulong __thiscall CSceneMobil::GetMwClassId(CSceneMobil *this,CControlStyle *param_1)
{
{
  return 0xa011000;
}
}

// =================================================
// Function: CSceneMobil::GetNodsNotToDuplicate
// =================================================
void __thiscall
CSceneMobil::GetNodsNotToDuplicate
          (CSceneMobil *this,CSceneMobil *param_1,CFastBuffer<class_CMwNod*> *param_2)
{
{
  CSceneMobil *this_00;
  TiXmlAttribute *unaff_EDI;
  
  this_00 = param_1;
  if (*(int **)(this + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x20) + 0x9c))(param_1);
  }
  param_1 = *(CSceneMobil **)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x68);
  if (param_1 != (CSceneMobil *)0x0) {
    CFastBuffer<class_CDx9TextureKeeper*>::Add(this_00,(TiXmlAttributeSet *)&param_1,unaff_EDI);
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::GetSector
// =================================================
CSceneSector * __thiscall CSceneMobil::GetSector(CSceneMobil *this,CScenePoc *param_1)
{
{
  int iVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_retaddr;
  
  iVar1 = *(int *)(this + 0x28);
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar1 + 0x34),unaff_ESI);
  if (uVar2 != 0) {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar1 + 0x34),(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0
                        ,unaff_retaddr);
    if (*(int *)pSVar3 != 0) {
      return *(CSceneSector **)(*(int *)(*(int *)pSVar3 + 0x14) + 0x14);
    }
  }
  return (CSceneSector *)0x0;
}
}

// =================================================
// Function: CSceneMobil::GetTranslation
// =================================================
void __thiscall
CSceneMobil::GetTranslation
          (CSceneMobil *this,CSceneMobil *param_1,GmVec3 *param_2,CSceneSector *param_3)
{
{
  CHmsCorpus *pCVar1;
  int iVar2;
  CHmsZone *unaff_retaddr;
  
  pCVar1 = CHmsItem::GetCorpus(*(CHmsItem **)(this + 0x28),*(CHmsItem **)(param_2 + 0x38),
                               unaff_retaddr);
  iVar2 = (**(code **)(*(int *)pCVar1 + 0x78))();
  *(undefined4 *)param_2 = *(undefined4 *)(iVar2 + 0x24);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(iVar2 + 0x28);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar2 + 0x2c);
  return;
}
}

// =================================================
// Function: CSceneMobil::GetTree
// =================================================
CPlugTree * __thiscall CSceneMobil::GetTree(CSceneMobil *this,SVolatileTreePointer *param_1)
{
{
  return *(CPlugTree **)(*(int *)(*(int *)(this + 0x28) + 0x14) + 100);
}
}

// =================================================
// Function: CSceneMobil::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CSceneMobil::GetUidChunkFromIndex(CSceneMobil *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if ((CMwCmdExpIso4Ident *)&DAT_00000005 < param_1) {
    return (uint)(param_1 + -6) | 0xa011000;
  }
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0xa005000;
}
}

// =================================================
// Function: CSceneMobil::Hide
// =================================================
void __thiscall CSceneMobil::Hide(CSceneMobil *this,CSceneToyMotorbike *param_1)
{
{
  CPlugTree *pCVar1;
  SVolatileTreePointer *unaff_retaddr;
  
  pCVar1 = GetTree(this,unaff_retaddr);
  *(uint *)(pCVar1 + 0x9c) = *(uint *)(pCVar1 + 0x9c) & 0xfffffff7;
  return;
}
}

// =================================================
// Function: CSceneMobil::InstallRenderBeforeMechanism
// =================================================
void __thiscall CSceneMobil::InstallRenderBeforeMechanism(CSceneMobil *this,CSceneMobil *param_1)
{
{
  CCallback *unaff_retaddr;
  
  CHmsItem::CallbackSet(*(CHmsItem **)(this + 0x28),(CHmsItem *)0x1,0xd062b4,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CSceneMobil::IsZombie
// =================================================
int __thiscall CSceneMobil::IsZombie(CSceneMobil *this,CSceneMobil *param_1)
{
{
  return *(uint *)(*(int *)(this + 0x28) + 0x18) >> 0x15 & 1;
}
}

// =================================================
// Function: CSceneMobil::LinkAdd
// =================================================
ulong __thiscall
CSceneMobil::LinkAdd(CSceneMobil *this,CSceneMobil *param_1,CSceneObjectLink *param_2)
{
{
  SLoadedLight *pSVar1;
  ulong uVar2;
  CMwNod *unaff_EBX;
  CMwNod *unaff_ESI;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EDI;
  
  pSVar1 = CFastBuffer<class_CMwNodRef<class_CSceneObjectLink>_>::AddNewElem(this + 0x38,unaff_EDI);
  if (param_2 != *(CSceneObjectLink **)pSVar1) {
    if (param_2 != (CSceneObjectLink *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_2,unaff_ESI);
    }
    if (*(CMwNod **)pSVar1 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)pSVar1,unaff_EBX);
    }
    *(CSceneObjectLink **)pSVar1 = param_2;
  }
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this + 0x38,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
  return uVar2 - 1;
}
}

// =================================================
// Function: CSceneMobil::LinkFind
// =================================================
ulong __thiscall
CSceneMobil::LinkFind(CSceneMobil *this,CSceneMobil *param_1,CSceneObjectLink *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x38,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x38,pCVar3,unaff_ESI);
      if (*(CSceneObjectLink **)pSVar2 == param_2) {
        return (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CSceneMobil::LinkFindFromObjectId
// =================================================
ulong __thiscall
CSceneMobil::LinkFindFromObjectId(CSceneMobil *this,CSceneMobil *param_1,CMwId *param_2)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x38,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    iVar1 = *(int *)param_2;
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x38,pCVar4,unaff_ESI);
      if (*(int *)(*(int *)(*(int *)pSVar3 + 0x18) + 0x18) == iVar1) {
        return (ulong)pCVar4;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CSceneMobil::LinkRemove
// =================================================
void __thiscall CSceneMobil::LinkRemove(CSceneMobil *this,CSceneMobil *param_1,ulong param_2)
{
{
  CSceneObjectLink *this_00;
  CSceneObject *this_01;
  SCasterCat *pSVar1;
  CSceneObject *unaff_EBX;
  CSceneObject *unaff_EBP;
  CSceneToyRock *unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_EDI);
  this_00 = *(CSceneObjectLink **)pSVar1;
  CSceneObjectLink::OnLeaveScene(this_00,unaff_ESI);
  this_01 = *(CSceneObject **)(this_00 + 0x18);
  if ((this_01 != (CSceneObject *)0x0) && (*(int *)(this_01 + 0x14) != 0)) {
    CSceneObjectLink::SetObject(this_00,(CSceneObjectLink *)0x0,unaff_EBP);
    CSceneObject::RemoveFromScene(this_01,unaff_EBX);
  }
  CFastBufferRef<class_CGameCtnMediaClip>::RemoveAt
            (this + 0x38,(CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)param_1,1,
             unaff_retaddr);
  return;
}
}

// =================================================
// Function: CSceneMobil::MoveOneCorpusOf
// =================================================
void __thiscall
CSceneMobil::MoveOneCorpusOf
          (CSceneMobil *this,CSceneMobil *param_1,CHmsCorpus *param_2,float param_3,float param_4,
          float param_5,GmIso4 *param_6)
{
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 auStack_30 [9];
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  puVar2 = (undefined4 *)(**(code **)(*(int *)param_1 + 0x78))();
  iVar1 = *(int *)this;
  puVar4 = auStack_30;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  fStack_c = fStack_c + (float)param_2;
  fStack_8 = fStack_8 + param_3;
  fStack_4 = fStack_4 + param_4;
  (**(code **)(iVar1 + 0x88))(auStack_30,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x14));
  return;
}
}

// =================================================
// Function: CSceneMobil::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CSceneMobil::MwGetClassInfo(CSceneMobil *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d6ce98;
}
}

// =================================================
// Function: CSceneMobil::MwIsKindOf
// =================================================
int __thiscall CSceneMobil::MwIsKindOf(CSceneMobil *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if ((param_1 != (CMwCmdAffectParam *)0xa011000) && (param_1 != (CMwCmdAffectParam *)0xa005000)) {
    return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
  }
  return 1;
}
}

// =================================================
// Function: CSceneMobil::MwNewCSceneMobil
// =================================================
CMwNod * __cdecl CSceneMobil::MwNewCSceneMobil(void)
{
{
  CSceneMobil *pCVar1;
  CMwNod *extraout_EAX;
  CSceneMobil *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00acbc2b;
  local_c = ExceptionList;
  pCVar1 = (CSceneMobil *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x48);
  local_4 = 0;
  if (local_10 != (CSceneMobil *)0x0) {
    CSceneMobil(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CSceneMobil::OnEnterScene
// =================================================
void __thiscall CSceneMobil::OnEnterScene(CSceneMobil *this,CSceneToyBroomstick *param_1)
{
{
  CSceneMobil *this_00;
  SSceneLoc SVar1;
  CPlugMaterial *this_01;
  ulong uVar2;
  CPlugMaterialFx *pCVar3;
  int iVar4;
  CSceneToyFxDynaBump *extraout_EAX;
  CMwNod *extraout_EAX_00;
  SLoadedLight *pSVar5;
  SCasterCat *pSVar6;
  undefined3 extraout_var;
  CSceneToyFxDynaBump *this_02;
  CSceneMobil *unaff_ESI;
  CPlugMaterialFxFur *unaff_EDI;
  CMwNod *this_03;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  void *unaff_retaddr;
  CPlugTree *in_stack_ffffff74;
  CSceneObjectLink *in_stack_ffffff78;
  CSceneMobil *in_stack_ffffff7c;
  CSceneMobil *in_stack_ffffff80;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_ffffff84;
  CFastBuffer<class_CPlugFileGPUV*> *this_04;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CIteratorMaterial aCStack_5c [4];
  CSceneToyFxDynaBump *pCStack_58;
  undefined1 auStack_54 [4];
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *apCStack_50 [2];
  int iStack_48;
  int iStack_40;
  CSceneObject aCStack_34 [20];
  undefined1 uStack_20;
  undefined1 uStack_1c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00acbd3e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSceneObject::OnEnterScene
            ((CSceneObject *)this,(CSceneToyBroomstick *)(DAT_00cca150 ^ (uint)&stack0xffffff94));
  (**(code **)(*(int *)this + 0x78))();
  if (*(int *)(*(int *)(this + 0x28) + 0x14) != 0) {
    this_04 = (CFastBuffer<class_CPlugFileGPUV*> *)0x0;
    CPlugTree::CIteratorMaterial::CIteratorMaterial
              (apCStack_50,*(CIteratorMaterial **)(*(int *)(*(int *)(this + 0x28) + 0x14) + 100),
               (CPlugTree *)0x0,(EMode)unaff_EDI);
    while (iStack_40 != 0) {
      this_01 = CPlugTree::CIteratorMaterial::GetNextMaterial
                          (auStack_54,aCStack_5c,(CPlugTree **)this_04);
      this_04 = (CFastBuffer<class_CPlugFileGPUV*> *)0x7b5407;
      uVar2 = CPlugMaterial::GetModifyMask(this_01,unaff_EDI);
      iStack_40 = iStack_48;
      if ((uVar2 & 8) != 0) {
        pCVar3 = CPlugMaterial::AddMobil_GetMatFx(this_01,(CPlugMaterialFxs *)this_04);
        unaff_ESI = (CSceneMobil *)0x9081000;
        unaff_EDI = (CPlugMaterialFxFur *)0x7b5424;
        iVar4 = (**(code **)(*(int *)pCVar3 + 0x10))();
        iStack_40 = iStack_48;
        if (iVar4 != 0) {
          pCStack_58 = operator_new(0xc0);
          uStack_4 = CONCAT31(uStack_4._1_3_,1);
          if (pCStack_58 == (CSceneToyFxDynaBump *)0x0) {
            this_02 = (CSceneToyFxDynaBump *)0x0;
          }
          else {
            CSceneToyFxDynaBump::CSceneToyFxDynaBump(pCStack_58,(CSceneToyFxDynaBump *)this_04);
            this_02 = extraout_EAX;
          }
          uStack_20 = 0;
          CSceneToyFxDynaBump::InitFromMaterialFx
                    (this_02,(CSceneToyFxDynaBump *)0x7b5436,in_stack_ffffff74);
          this_04 = operator_new(100);
          uStack_1c = 2;
          if (this_04 == (CFastBuffer<class_CPlugFileGPUV*> *)0x0) {
            this_03 = (CMwNod *)0x0;
          }
          else {
            CSceneObjectLink::CSceneObjectLink((CSceneObjectLink *)this_04,in_stack_ffffff78);
            this_03 = extraout_EAX_00;
          }
          uStack_1c = 0;
          CMwNod::MwAddRef(this_03,(CMwNod *)in_stack_ffffff78);
          in_stack_ffffff74 = (CPlugTree *)0x7b549c;
          CSceneObjectLink::SetObject
                    ((CSceneObjectLink *)this_03,(CSceneObjectLink *)this_02,
                     (CSceneObject *)in_stack_ffffff7c);
          in_stack_ffffff78 = (CSceneObjectLink *)0x7b54a4;
          in_stack_ffffff7c = this;
          CSceneObjectLink::SetMobil
                    ((CSceneObjectLink *)this_03,(CSceneObjectLink *)this,in_stack_ffffff80);
          *(uint *)(this_03 + 0x14) = *(uint *)(this_03 + 0x14) & 0xffffffef;
          in_stack_ffffff80 = (CSceneMobil *)0x7b54af;
          pSVar5 = CFastBuffer<class_CMwNodRef<class_CSceneObjectLink>_>::AddNewElem
                             (this + 0x38,in_stack_ffffff84);
          iStack_40 = iStack_48;
          if (this_03 != *(CMwNod **)pSVar5) {
            in_stack_ffffff84 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x7b54bd;
            CMwNod::MwAddRef(this_03,(CMwNod *)this_04);
            if (*(CMwNod **)pSVar5 != (CMwNod *)0x0) {
              CMwNod::MwRelease(*(CMwNod **)pSVar5,(CMwNod *)this_04);
            }
            *(CMwNod **)pSVar5 = this_03;
            iStack_40 = iStack_48;
          }
        }
      }
    }
    uStack_4 = 0xffffffff;
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(auStack_54,this_04);
  }
  this_00 = this + 0x38;
  apCStack_50[0] =
       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
       CFastBuffer<class_CCrystalFace*>::GetCount
                 (this_00,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (apCStack_50[0] != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar7,(ulong)unaff_ESI);
      apCStack_50[0] = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)pSVar6 + 0x18);
      iVar4 = **(int **)(this + 0x14);
      SVar1 = CSceneObject::SceneLocGet((CSceneObject *)this,aCStack_34);
      unaff_ESI = (CSceneMobil *)CONCAT31(extraout_var,SVar1);
      pCVar8 = apCStack_50[0];
      (**(code **)(iVar4 + 0x78))();
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar7,(ulong)pCVar8);
      CSceneObjectLink::OnEnterScene
                (*(CSceneObjectLink **)pSVar6,*(CSceneToyBroomstick **)(this + 0x14));
      pCVar7 = pCVar7 + 1;
    } while (pCVar7 < apCStack_50[0]);
  }
  SolidObjectsAdd(this,unaff_ESI);
  if (*(int **)(this + 0x34) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x34) + 0x7c))();
  }
  if (*(int **)(this + 0x30) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x30) + 0xb8))();
    (**(code **)(**(int **)(this + 0x30) + 0x78))();
  }
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CSceneMobil::OnEnterSector
// =================================================
void __thiscall
CSceneMobil::OnEnterSector
          (CSceneMobil *this,CSceneLocation *param_1,CSceneSector *param_2,GmIso4 *param_3)
{
{
  (**(code **)(**(int **)(param_1 + 0x38) + 0x78))(*(undefined4 *)(this + 0x28),param_2);
  return;
}
}

// =================================================
// Function: CSceneMobil::OnLeaveScene
// =================================================
void __thiscall CSceneMobil::OnLeaveScene(CSceneMobil *this,CSceneToyRock *param_1)
{
{
  CSceneMobil *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CSceneMobil *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CSceneToyRock *unaff_EDI;
  ulong uVar4;
  CSceneToyRock *pCVar5;
  
  CSceneObject::OnLeaveScene((CSceneObject *)this,unaff_EDI);
  SolidObjectsRemove(this,unaff_ESI);
  this_00 = this + 0x38;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      uVar4 = 0x7b3f2c;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar3,unaff_EBX);
      unaff_EBX = *(ulong *)(*(int *)pSVar2 + 0x18);
      pCVar5 = (CSceneToyRock *)0x7b3f3c;
      (**(code **)(**(int **)(unaff_EBX + 0x14) + 0x7c))();
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar3,uVar4);
      CSceneObjectLink::OnLeaveScene(*(CSceneObjectLink **)pSVar2,pCVar5);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  if (*(int **)(this + 0x34) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x34) + 0x80))();
  }
  if (*(int **)(this + 0x30) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x30) + 0xc0))(*(undefined4 *)(this + 0x14));
                    /* WARNING: Could not recover jumptable at 0x007b3f87. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0x30) + 0x80))();
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::OnLeaveSector
// =================================================
void __thiscall
CSceneMobil::OnLeaveSector(CSceneMobil *this,CSceneLocation *param_1,CSceneSector *param_2)
{
{
  CHmsItem *unaff_retaddr;
  
  CHmsZone::RemoveItem(*(CHmsZone **)(param_1 + 0x38),*(CHmsZone **)(this + 0x28),unaff_retaddr);
  return;
}
}

// =================================================
// Function: CSceneMobil::OnRenderBefore
// =================================================
void __thiscall
CSceneMobil::OnRenderBefore
          (CSceneMobil *this,CMotionTrack *param_1,CHmsCamera *param_2,int *param_3)
{
{
  if (*(int **)(this + 0x20) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x007b317f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0x20) + 0xac))();
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::OnStillDrag
// =================================================
void __thiscall
CSceneMobil::OnStillDrag(CSceneMobil *this,CSceneMobil *param_1,CSceneInfoDrag *param_2)
{
{
  GmIso4 *unaff_retaddr;
  
  if ((*(uint *)(param_1 + 0x28) & 0xf0) != 0) {
    RotateOneCorpusOf(this,*(CSceneMobil **)(param_1 + 8),*(CHmsCorpus **)(param_1 + 0x40),
                      *(float *)(param_1 + 0x44),*(float *)(param_1 + 0x48),(float)(param_1 + 0x4c),
                      (GmIso4 *)0x0,(GmVec3 *)unaff_retaddr);
    return;
  }
  if ((*(uint *)(param_1 + 0x28) & 0xf) != 0) {
    MoveOneCorpusOf(this,*(CSceneMobil **)(param_1 + 8),*(CHmsCorpus **)(param_1 + 0x34),
                    *(float *)(param_1 + 0x38),*(float *)(param_1 + 0x3c),(float)(param_1 + 0x4c),
                    unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::OnStillFocus
// =================================================
void __thiscall
CSceneMobil::OnStillFocus
          (CSceneMobil *this,CSceneMessageHandler *param_1,CSceneMobil *param_2,
          CSceneInfoFocus *param_3,CSceneInfoFocus *param_4)
{
{
  CSceneMessageHandler *this_00;
  CSceneInfoFocus *unaff_retaddr;
  
  this_00 = *(CSceneMessageHandler **)(this + 0x44);
  if ((this_00 != (CSceneMessageHandler *)0x0) && (*(int *)(this_00 + 0x14) != 0)) {
    CSceneMessageHandler::OnStillFocus
              (this_00,(CSceneMessageHandler *)this,(CSceneMobil *)param_1,
               (CSceneInfoFocus *)param_2,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::OnVisibleGained
// =================================================
void __thiscall CSceneMobil::OnVisibleGained(CSceneMobil *this,CSceneMobil *param_1)
{
{
  if (*(int **)(this + 0x34) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x34) + 0x7c))();
  }
  if (*(int **)(this + 0x30) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x007b310e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0x30) + 0x78))();
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::OnVisibleLost
// =================================================
void __thiscall CSceneMobil::OnVisibleLost(CSceneMobil *this,CSceneMobil *param_1)
{
{
  if (*(int **)(this + 0x30) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x30) + 0x80))();
  }
  if (*(int **)(this + 0x34) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x007b3144. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0x34) + 0x80))();
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::ParseTreeLight
// =================================================
void __thiscall
CSceneMobil::ParseTreeLight(CSceneMobil *this,CSceneMobil *param_1,CPlugTree *param_2,int param_3)
{
{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  int extraout_EAX;
  char *extraout_EAX_00;
  char *pcVar6;
  int extraout_EAX_01;
  CSceneMobil *unaff_EBX;
  uint uVar7;
  SParam_Fids *in_stack_ffffff74;
  CFastString *pCVar8;
  CMwStatsValue *pCVar9;
  CFastString *pCVar10;
  int *piVar11;
  GmVec4 *in_stack_ffffff84;
  GmIso4 *pGVar12;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  CPlugTree *apCStack_54 [2];
  undefined1 auStack_4c [12];
  CPlugTree aCStack_40 [4];
  GmVec4 aGStack_3c [48];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00acbcfe;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar7 = 0;
  if (*(int *)(this + 0x14) != 0) {
    if ((DAT_00d6cedc & 1) == 0) {
      DAT_00d6cedc = DAT_00d6cedc | 1;
      local_4 = 0;
      CFastString::CFastString
                ((CFastString *)&DAT_00d6ced4,(CFastString *)"PlaneReflect",
                 (char *)(DAT_00cca150 ^ (uint)&stack0xffffff8c));
      in_stack_ffffff84 = (GmVec4 *)0x7b5003;
      _atexit(`public:_void___thiscall_CSceneMobil::ParseTreeLight(class_CPlugTree*,int)'::__l4::
              _dynamic_atexit_destructor_for__StrPlaneReflect__);
    }
    pGVar12 = (GmIso4 *)0x7b501c;
    uVar2 = (**(code **)(*(int *)param_2 + 0x7c))();
    if (uVar2 != 0) {
      do {
        piVar3 = (int *)(**(code **)(*(int *)param_2 + 0x80))(uVar7);
        pCVar9 = (CMwStatsValue *)0x7b503f;
        iVar4 = (**(code **)(*piVar3 + 0x14))();
        if (iVar4 != 0) {
          pCVar10 = (CFastString *)0x7b504c;
          pvVar5 = (void *)(**(code **)(*piVar3 + 0x14))();
          pCVar8 = (CFastString *)0x7b5053;
          CMwId::GetString(pvVar5,pCVar9,pCVar10);
          if (extraout_EAX != 0) {
            piVar11 = (int *)0x7b5060;
            pvVar5 = (void *)(**(code **)(*piVar3 + 0x14))();
            CMwId::GetString(pvVar5,(CMwStatsValue *)in_stack_ffffff74,pCVar8);
            if (extraout_EAX_00 == (char *)0x0) {
              unaff_EBX = (CSceneMobil *)0x0;
            }
            else {
              pcVar6 = extraout_EAX_00;
              do {
                cVar1 = *pcVar6;
                pcVar6 = pcVar6 + 1;
              } while (cVar1 != '\0');
              unaff_EBX = (CSceneMobil *)(pcVar6 + -(int)(extraout_EAX_00 + 1));
            }
            in_stack_ffffff74 = (SParam_Fids *)&stack0xffffff94;
            CFastString::Compare
                      ((CFastString *)&DAT_00d6ced4,in_stack_ffffff74,DAT_00d6ced4,(int *)pCVar9,
                       piVar11);
            if (extraout_EAX_01 == 0) {
              if (uVar7 < uVar2) {
                apCStack_54[0] = (CPlugTree *)(**(code **)(*(int *)param_2 + 0x80))(uVar7);
                if (apCStack_54[0] != (CPlugTree *)0x0) {
                  CPlugTree::GetThisToRootTransfo
                            (apCStack_54[0],aCStack_40,(GmIso4 *)0x1,0,
                             (CPlugTree *)in_stack_ffffff84);
                  uStack_60 = 0;
                  in_stack_ffffff84 = aGStack_3c;
                  uStack_5c = 0x3f800000;
                  uStack_58 = 0;
                  apCStack_54[0] = (CPlugTree *)0x0;
                  GmVec4::PlaneEqSetMult(auStack_4c,(GmVec4 *)&uStack_60,in_stack_ffffff84,pGVar12);
                }
                goto LAB_007b510a;
              }
              break;
            }
          }
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar2);
    }
    apCStack_54[0] = (CPlugTree *)0x0;
LAB_007b510a:
    ParseTreeLightInternal
              (unaff_EBX,(CSceneMobil *)param_2,(CPlugTree *)param_1,(int)apCStack_54,
               (SParseTreeLight *)in_stack_ffffff84);
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CSceneMobil::ParseTreeLightInternal
// =================================================
void __thiscall
CSceneMobil::ParseTreeLightInternal
          (CSceneMobil *this,CSceneMobil *param_1,CPlugTree *param_2,int param_3,
          SParseTreeLight *param_4)
{
{
  CHmsLight *this_00;
  CSceneLight *pCVar1;
  int iVar2;
  CSceneLight *extraout_EAX;
  undefined4 uVar3;
  int iVar4;
  CSceneObjectLink *this_01;
  CSceneMobil *pCVar5;
  CSceneMobil *unaff_EBP;
  uint uVar6;
  int unaff_ESI;
  CPlugTree *pCVar7;
  GxLight *in_stack_ffffff34;
  CGameCamera *in_stack_ffffff38;
  int in_stack_ffffff3c;
  CPlugTree *in_stack_ffffff40;
  GmScaleTrans2 *in_stack_ffffff44;
  GmIso4 *in_stack_ffffff48;
  GmVec3 *in_stack_ffffff4c;
  CSceneObjectLink *in_stack_ffffff50;
  CPlugTree *pCVar8;
  CPlugTree *pCVar9;
  ESceneLightUpdate EVar10;
  SParseTreeLight *pSVar11;
  CSceneMobil *pCStack_90;
  CSceneMobil *local_8c;
  CSceneLight *pCStack_88;
  undefined1 auStack_84 [4];
  float afStack_80 [10];
  CPlugTree aCStack_58 [4];
  GmScaleTrans2 aGStack_54 [40];
  undefined4 uStack_2c;
  undefined4 uStack_10;
  void *local_c;
  int *piStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  piStack_8 = (int *)&LAB_00acbccc;
  local_c = ExceptionList;
  pCVar1 = (CSceneLight *)(DAT_00cca150 ^ (uint)&stack0xffffff60);
  ExceptionList = &local_c;
  if (param_1 != (CSceneMobil *)0x0) {
    local_8c = this;
    iVar2 = (**(code **)(*(int *)param_1 + 0x10))(0x9062000);
    if (iVar2 == 0) {
      if ((param_2 == (CPlugTree *)0x0) || (((byte)param_1[0x9c] & 8) == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = 1;
      }
      pCVar9 = (CPlugTree *)(**(code **)(*(int *)param_1 + 0x7c))();
      pCVar7 = (CPlugTree *)0x0;
      if (pCVar9 != (CPlugTree *)0x0) {
        do {
          pCVar8 = pCVar7;
          iVar4 = iVar2;
          pSVar11 = (SParseTreeLight *)param_3;
          pCVar5 = (CSceneMobil *)(**(code **)(*(int *)param_1 + 0x80))();
          ParseTreeLightInternal(pCStack_90,pCVar5,pCVar8,iVar4,pSVar11);
          pCVar7 = pCVar7 + 1;
        } while (pCVar7 < pCVar9);
      }
    }
    else if ((((param_2 != (CPlugTree *)0x0) || (*(int *)(param_1 + 0xac) == 0)) ||
             ((*(byte *)(*(int *)(param_1 + 0xac) + 0x20) & 8) == 0)) &&
            (*(int *)(param_1 + 0xb0) != 0)) {
      iVar2 = 0x38;
      uVar6 = *(uint *)(*(int *)(this + 0x28) + 0x18) >> 8 & 1;
      pCVar9 = (CPlugTree *)0x7b4d4a;
      pCStack_88 = operator_new(0x38);
      uStack_4 = 0;
      if (pCStack_88 == (CSceneLight *)0x0) {
        pCVar1 = (CSceneLight *)0x0;
      }
      else {
        iVar2 = 0x7b4d67;
        CSceneLight::CSceneLight(pCStack_88,pCVar1);
        pCVar1 = extraout_EAX;
      }
      *(uint *)(pCVar1 + 0x24) = *(uint *)(pCVar1 + 0x24) & 0xfffffffe | 0x800;
      uStack_2c = 0xffffffff;
      CSceneLight::SetLight(pCVar1,*(CMotionLight **)(param_1 + 0xb0),in_stack_ffffff34);
      this_00 = *(CHmsLight **)(pCVar1 + 0x30);
      CMwNodRef<class_CGameCamera>::MwSetNod
                (this_00 + 0x68,*(CMwNodRef<class_CGameCamera> **)(in_stack_ffffff4c + 0x18),
                 in_stack_ffffff38);
      CHmsLight::SetReflectPlaneIsEnable
                (this_00,(CHmsLight *)(*(uint *)(in_stack_ffffff50 + 0x20) >> 1 & 1),
                 in_stack_ffffff3c);
      if (uVar6 == 0) {
        uVar3 = *(undefined4 *)(iVar2 + 0x28);
      }
      else {
        uVar3 = 0;
      }
      *(undefined4 *)(this_00 + 0x84) = uVar3;
      if (((byte)this_00[0x8c] & 4) != 0) {
        CPlugTree::GetThisToRootTransfo
                  ((CPlugTree *)param_1,aCStack_58,(GmIso4 *)0x1,0,in_stack_ffffff40);
        GmIso4::SetInverse(auStack_84,aGStack_54,in_stack_ffffff44);
        if (*piStack_8 == 0) {
          GmVec3::SetMult(&local_8c,(SPlugFaceCull *)&stack0xffffff68,(SPlugFaceCull *)afStack_80,
                          in_stack_ffffff48);
          unaff_EBP = (CSceneMobil *)-*(float *)(param_1 + 0x84);
          local_8c = (CSceneMobil *)((float)unaff_EBP * afStack_80[0]);
          GmVec4::PlaneEqSetNormPos
                    (this_00 + 0x74,(GmVec4 *)&pCStack_88,(GmVec3 *)&stack0xffffff6c,
                     in_stack_ffffff4c);
        }
        else {
          GmVec4::PlaneEqSetMult
                    (this_00 + 0x74,(GmVec4 *)(piStack_8 + 1),(GmVec4 *)afStack_80,in_stack_ffffff48
                    );
        }
      }
      if ((*(int **)(param_1 + 0xb0) != (int *)0x0) &&
         (iVar4 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x78))(), iVar4 == 4)) {
        CHmsLight::SetProjectorBitmap
                  (*(CHmsLight **)(pCVar1 + 0x30),*(CHmsLight **)(unaff_ESI + 0x1c),
                   (CPlugBitmap *)in_stack_ffffff50);
      }
      this_01 = operator_new(100);
      uStack_10 = 1;
      if (this_01 != (CSceneObjectLink *)0x0) {
        CSceneObjectLink::CSceneObjectLink(this_01,in_stack_ffffff50);
      }
      uStack_10 = 0xffffffff;
      AddObject(unaff_EBP,(CSceneMobil *)pCVar1,(CSceneObject *)&stack0xffffff64,
                (CSceneObjectLink **)in_stack_ffffff50);
      CSceneObjectLink::SetMobilTree
                ((CSceneObjectLink *)unaff_EBP,(CSceneObjectLink *)param_1,pCVar9);
      *(uint *)(unaff_EBP + 0x14) = *(uint *)(unaff_EBP + 0x14) & 0xffffffef;
      CSceneObjectLink::SetIsActive((CSceneObjectLink *)unaff_EBP,(CSceneObjectLink *)0x1,iVar2);
      if (uVar6 != 0) {
        EVar10 = 0x7b4f10;
        (**(code **)(*(int *)pCVar1 + 0xb4))();
        CSceneLight::SetLightUpdate(pCVar1,(CSceneLight *)0x0,EVar10);
      }
    }
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CSceneMobil::RotateOneCorpusOf
// =================================================
void __thiscall
CSceneMobil::RotateOneCorpusOf
          (CSceneMobil *this,CSceneMobil *param_1,CHmsCorpus *param_2,float param_3,float param_4,
          float param_5,GmIso4 *param_6,GmVec3 *param_7)
{
{
  float *pfVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  undefined4 *puVar4;
  int iVar5;
  GmMat43 *unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  undefined4 *puVar6;
  float *in_stack_00000020;
  GmIso4 *in_stack_00000024;
  float in_stack_ffffffac;
  float in_stack_ffffffb0;
  float in_stack_ffffffb4;
  GmScaleTrans2 *in_stack_ffffffb8;
  GmIso3 *in_stack_ffffffbc;
  GmMat3 *in_stack_ffffffc0;
  GmScaleTrans2 aGStack_3c [4];
  GmIso3 aGStack_38 [16];
  undefined4 auStack_28 [4];
  undefined1 auStack_18 [8];
  undefined1 auStack_10 [12];
  float fStack_4;
  
  if (param_1 == (CSceneMobil *)0x0) {
    iVar5 = *(int *)(this + 0x28);
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar5 + 0x34),unaff_ESI);
    if (uVar2 == 0) {
      return;
    }
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar5 + 0x34),(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0
                        ,unaff_EBP);
    param_1 = *(CSceneMobil **)pSVar3;
  }
  puVar4 = (undefined4 *)(**(code **)(*(int *)param_1 + 0x78))();
  pfVar1 = in_stack_00000020;
  puVar6 = auStack_28;
  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  if (in_stack_00000020 != (float *)0x0) {
    fStack_4 = fStack_4 - *in_stack_00000020;
  }
  GmMat3::SetIdentity(&stack0xffffffb4,unaff_EBX);
  GmMat3::RotateX(&stack0xffffffb8,(GmIso4 *)param_5,in_stack_ffffffac);
  GmMat3::RotateY(&stack0xffffffbc,(GmIso4 *)param_7,in_stack_ffffffb0);
  GmMat3::RotateZ(&stack0xffffffc0,in_stack_00000024,in_stack_ffffffb4);
  GmMat3::LeftMult(auStack_18,aGStack_3c,in_stack_ffffffb8);
  if (pfVar1 != (float *)0x0) {
    GmVec3::Mult(&param_4,aGStack_38,in_stack_ffffffbc);
  }
  GmMat3::OrthoNormalize(auStack_10,in_stack_ffffffc0);
  if (pfVar1 != (float *)0x0) {
    param_6 = (GmIso4 *)(*pfVar1 + (float)param_6);
    param_7 = (GmVec3 *)(pfVar1[1] + (float)param_7);
    in_stack_00000020 = (float *)(pfVar1[2] + (float)in_stack_00000020);
  }
  (**(code **)(*(int *)this + 0x88))();
  return;
}
}

// =================================================
// Function: CSceneMobil::SetIsVisible
// =================================================
void __thiscall CSceneMobil::SetIsVisible(CSceneMobil *this,CPlugTree *param_1,int param_2)
{
{
  if (param_1 != (CPlugTree *)0x0) {
    (**(code **)(*(int *)this + 0x100))();
    return;
  }
  (**(code **)(*(int *)this + 0x104))();
  return;
}
}

// =================================================
// Function: CSceneMobil::SetLocation
// =================================================
void __thiscall CSceneMobil::SetLocation(CSceneMobil *this,CPlugTree *param_1,GmIso4 *param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_ESI;
  
  if (*(int *)(this + 0x14) != 0) {
    if (param_2 != (GmIso4 *)0x0) {
      CHmsItem::SetLocation(*(CHmsItem **)(this + 0x28),param_1,*(GmIso4 **)(param_2 + 0x38));
      return;
    }
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(this + 0x28) + 0x34),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
    CHmsItem::SetLocation
              (*(CHmsItem **)(this + 0x28),(CPlugTree *)0x0,*(GmIso4 **)(*(int *)pSVar1 + 0x14));
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::SetMessageHandler
// =================================================
void __thiscall
CSceneMobil::SetMessageHandler(CSceneMobil *this,CSceneMobil *param_1,CSceneMessageHandler *param_2)
{
{
  CMwNod *unaff_ESI;
  int unaff_EDI;
  
  if ((param_1 != (CSceneMobil *)0x0) && (*(int *)(param_1 + 0x18) != 0)) {
    EnableAbsorbContactCallback(this,(CSceneMobil *)0x1,unaff_EDI);
  }
  if (param_1 != *(CSceneMobil **)(this + 0x44)) {
    if (param_1 != (CSceneMobil *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_ESI);
    }
    if (*(CMwNod **)(this + 0x44) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x44),unaff_ESI);
    }
    *(CSceneMobil **)(this + 0x44) = param_1;
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::SetModel
// =================================================
void __thiscall CSceneMobil::SetModel(CSceneMobil *this,CPlugSolid *param_1,CPlugSolid *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CPlugSolid **)(this + 0x2c)) {
    if (param_1 != (CPlugSolid *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x2c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x2c),unaff_ESI);
    }
    *(CPlugSolid **)(this + 0x2c) = param_1;
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::SetMotion
// =================================================
CMotion * __thiscall
CSceneMobil::SetMotion(CSceneMobil *this,CSceneObject *param_1,CMwNod *param_2,int param_3)
{
{
  CMotion *pCVar1;
  int iVar2;
  CSceneMobil *unaff_ESI;
  int unaff_EDI;
  
  pCVar1 = CSceneObject::SetMotion((CSceneObject *)this,param_1,param_2,unaff_EDI);
  if (*(int **)(this + 0x20) != (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(this + 0x20) + 0xa8))();
    if (iVar2 != 0) {
      InstallRenderBeforeMechanism(this,unaff_ESI);
    }
    iVar2 = (**(code **)(**(int **)(this + 0x20) + 0xb0))();
    if (iVar2 != 0) {
      EnableAbsorbContactCallback(this,(CSceneMobil *)0x1,(int)unaff_ESI);
    }
  }
  return pCVar1;
}
}

// =================================================
// Function: CSceneMobil::SetSolid
// =================================================
void __thiscall
CSceneMobil::SetSolid(CSceneMobil *this,CSceneToyMotorbike *param_1,CPlugSolid *param_2)
{
{
  CSceneToyMotorbike *pCVar1;
  CPlugSolid *pCVar2;
  CPlugSolid *this_00;
  CPlugSolid *extraout_EAX;
  CPlugTree *this_01;
  CPlugSolid *extraout_EAX_00;
  CSceneMobil *unaff_ESI;
  CPlugTree *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  CSceneToyMotorbike *local_4;
  
  local_4 = (CSceneToyMotorbike *)0xffffffff;
  puStack_8 = &LAB_00acbd76;
  local_c = ExceptionList;
  pCVar2 = (CPlugSolid *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  if (param_1 == (CSceneToyMotorbike *)0x0) {
    this_00 = operator_new(0x74);
    local_4 = param_1;
    if (this_00 == (CPlugSolid *)0x0) {
      param_1 = (CSceneToyMotorbike *)0x0;
    }
    else {
      CPlugSolid::CPlugSolid(this_00,pCVar2);
      param_1 = (CSceneToyMotorbike *)extraout_EAX;
    }
    this_01 = operator_new(0xac);
    if (this_01 == (CPlugTree *)0x0) {
      pCVar2 = (CPlugSolid *)0x0;
    }
    else {
      CPlugTree::CPlugTree(this_01,unaff_EDI);
      pCVar2 = extraout_EAX_00;
    }
    *(uint *)(pCVar2 + 0x9c) = *(uint *)(pCVar2 + 0x9c) & 0xfffffff7;
    CPlugSolid::SetTree((CPlugSolid *)param_1,pCVar2,(CPlugTree *)0x1,(int)unaff_EDI);
  }
  pCVar1 = *(CSceneToyMotorbike **)(*(CHmsItem **)(this + 0x28) + 0x14);
  if (param_1 != pCVar1) {
    if (*(int *)(param_1 + 0x14) != 0) {
      ExceptionList = local_4;
      return;
    }
    CHmsItem::SetSolid(*(CHmsItem **)(this + 0x28),param_1,(CPlugSolid *)unaff_ESI);
    if ((pCVar1 != (CSceneToyMotorbike *)0x0) && (*(int **)(this + 0x20) != (int *)0x0)) {
      unaff_ESI = *(CSceneMobil **)(this + 0x14);
      (**(code **)(**(int **)(this + 0x20) + 0xbc))();
    }
  }
  if (*(int *)(this + 0x14) != 0) {
    SolidObjectsRefresh(this,unaff_ESI);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CSceneMobil::SetTranslation
// =================================================
void __thiscall CSceneMobil::SetTranslation(CSceneMobil *this,GmIso4 *param_1,GmVec3 *param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  GmVec3 *in_stack_0000000c;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 0x28) + 0x34),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_retaddr);
  CHmsCorpus::SetTranslation(*(CHmsCorpus **)pSVar1,(GmIso4 *)param_2,in_stack_0000000c);
  return;
}
}

// =================================================
// Function: CSceneMobil::SetTree
// =================================================
void __thiscall
CSceneMobil::SetTree(CSceneMobil *this,CPlugSolid *param_1,CPlugTree *param_2,int param_3)
{
{
  CPlugSolid *pCVar1;
  CPlugSolid *this_00;
  CPlugSolid *extraout_EAX;
  CPlugSolid *unaff_ESI;
  CPlugSolid *this_01;
  int unaff_EDI;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00acb98b;
  local_c = ExceptionList;
  pCVar1 = (CPlugSolid *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  this_01 = (CPlugSolid *)0x0;
  if (*(CPlugSolid **)(*(int *)(this + 0x28) + 0x14) != (CPlugSolid *)0x0) {
    CPlugSolid::SetTree(*(CPlugSolid **)(*(int *)(this + 0x28) + 0x14),param_1,(CPlugTree *)0x1,
                        (int)pCVar1);
    ExceptionList = local_8;
    return;
  }
  this_00 = operator_new(0x74);
  local_4 = 0;
  if (this_00 != (CPlugSolid *)0x0) {
    CPlugSolid::CPlugSolid(this_00,pCVar1);
    this_01 = extraout_EAX;
  }
  CPlugSolid::SetTree(this_01,(CPlugSolid *)param_2,(CPlugTree *)0x1,unaff_EDI);
  CHmsItem::SetSolid(*(CHmsItem **)(this + 0x28),(CSceneToyMotorbike *)this_01,unaff_ESI);
  ExceptionList = (void *)0xffffffff;
  return;
}
}

// =================================================
// Function: CSceneMobil::SetVisual
// =================================================
void __thiscall
CSceneMobil::SetVisual(CSceneMobil *this,CVisionVisualKeeper *param_1,CPlugVisual *param_2)
{
{
  CPlugSolid *pCVar1;
  CPlugSolid *pCVar2;
  CPlugSolid *extraout_EAX;
  CPlugTree *extraout_EAX_00;
  CPlugTree *this_00;
  CPlugTree *unaff_EDI;
  CPlugVisual *in_stack_0000000c;
  CPlugSolid *in_stack_00000010;
  int iVar3;
  undefined4 uVar4;
  CPlugTree *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00acb926;
  local_c = ExceptionList;
  pCVar1 = (CPlugSolid *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  pCVar2 = *(CPlugSolid **)(*(int *)(this + 0x28) + 0x14);
  this_00 = (CPlugTree *)0x0;
  if (pCVar2 == (CPlugSolid *)0x0) {
    pCVar2 = operator_new(0x74);
    local_4 = 0;
    if (pCVar2 == (CPlugSolid *)0x0) {
      pCVar2 = (CPlugSolid *)0x0;
    }
    else {
      CPlugSolid::CPlugSolid(pCVar2,pCVar1);
      pCVar2 = extraout_EAX;
    }
  }
  local_c = operator_new(0xac);
  if (local_c != (CPlugTree *)0x0) {
    CPlugTree::CPlugTree(local_c,unaff_EDI);
    this_00 = extraout_EAX_00;
  }
  uVar4 = 1;
  CPlugTree::SetVisual(this_00,(CVisionVisualKeeper *)param_2,in_stack_0000000c);
  iVar3 = 1;
  (**(code **)(*(int *)this_00 + 0xbc))(1,in_stack_00000010,uVar4);
  CPlugSolid::SetTree(pCVar2,(CPlugSolid *)this_00,(CPlugTree *)0x1,iVar3);
  if (*(int *)(*(CHmsItem **)(this + 0x28) + 0x14) == 0) {
    CHmsItem::SetSolid(*(CHmsItem **)(this + 0x28),(CSceneToyMotorbike *)pCVar2,in_stack_00000010);
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CSceneMobil::SetZombie
// =================================================
void __thiscall CSceneMobil::SetZombie(CSceneMobil *this,CSceneMobil *param_1,int param_2)
{
{
  int unaff_ESI;
  
  CHmsItem::SetIsZombie(*(CHmsItem **)(this + 0x28),(CHmsItem *)param_1,unaff_ESI);
  (**(code **)(*(int *)this + 0x124))();
  return;
}
}

// =================================================
// Function: CSceneMobil::Show
// =================================================
void __thiscall CSceneMobil::Show(CSceneMobil *this,CSceneToyMotorbike *param_1)
{
{
  CPlugTree *pCVar1;
  SVolatileTreePointer *unaff_retaddr;
  
  pCVar1 = GetTree(this,unaff_retaddr);
  *(uint *)(pCVar1 + 0x9c) = *(uint *)(pCVar1 + 0x9c) | 8;
  return;
}
}

// =================================================
// Function: CSceneMobil::SolidObjectsAdd
// =================================================
void __thiscall CSceneMobil::SolidObjectsAdd(CSceneMobil *this,CSceneMobil *param_1)
{
{
  CSceneMobil *unaff_ESI;
  int unaff_retaddr;
  
  if (*(int *)(*(int *)(this + 0x28) + 0x14) != 0) {
    AddSolidMotionFromTree(this,unaff_ESI);
    ParseTreeLight(this,*(CSceneMobil **)(*(int *)(*(int *)(this + 0x28) + 0x14) + 100),
                   (CPlugTree *)0x1,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::SolidObjectsRefresh
// =================================================
void __thiscall CSceneMobil::SolidObjectsRefresh(CSceneMobil *this,CSceneMobil *param_1)
{
{
  CSceneMobil *unaff_ESI;
  CSceneMobil *in_stack_00000008;
  
  if (*(int *)(this + 0x14) != 0) {
    SolidObjectsRemove(this,unaff_ESI);
    SolidObjectsAdd(this,in_stack_00000008);
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::SolidObjectsRemove
// =================================================
void __thiscall CSceneMobil::SolidObjectsRemove(CSceneMobil *this,CSceneMobil *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  CMwNod *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (*(int *)(*(int *)(this + 0x28) + 0x14) != 0) {
    if (*(CMwNod **)(this + 0x30) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x30),unaff_ESI);
      *(undefined4 *)(this + 0x30) = 0;
    }
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x38,unaff_EDI);
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x38,pCVar3,(ulong)unaff_EBP);
        if ((*(uint *)(*(int *)(*(int *)pSVar2 + 0x18) + 0x24) & 0x800) != 0) {
          unaff_EBP = pCVar3;
          LinkRemove(this,(CSceneMobil *)pCVar3,unaff_EBX);
          pCVar3 = pCVar3 + -1;
          pCVar1 = pCVar1 + -1;
        }
        pCVar3 = pCVar3 + 1;
      } while (pCVar3 < pCVar1);
    }
  }
  return;
}
}

// =================================================
// Function: CSceneMobil::VehicleBlockSpeed2Set
// =================================================
void __thiscall
CSceneMobil::VehicleBlockSpeed2Set(CSceneMobil *this,CSceneMobil *param_1,int param_2)
{
{
  return;
}
}

// =================================================
// Function: CSceneMobil::VirtualParam_Add
// =================================================
ulong __thiscall
CSceneMobil::VirtualParam_Add
          (CSceneMobil *this,CMwCmdScriptVarClass *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if ((iVar2 != 0xa011007) && (iVar2 != -1)) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CSceneObject::VirtualParam_Add((CSceneObject *)this,param_1,param_2,param_3);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CSceneMobil::VirtualParam_Get
// =================================================
ulong __thiscall
CSceneMobil::VirtualParam_Get
          (CSceneMobil *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  CFuncColorGradient *pCVar1;
  CMwStack *pCVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  CMwParamClass *pCVar7;
  int iVar8;
  ulong uVar9;
  int *extraout_EDX;
  CSceneMobil *unaff_EDI;
  
  iVar4 = *(int *)(param_1 + 0x18);
  iVar5 = *(int *)(*(int *)(param_1 + 0x10) + iVar4 * 4);
  iVar8 = iVar4 + -1;
  *(int *)(param_1 + 0x18) = iVar8;
  uVar6 = *(uint *)(iVar5 + 4);
  if (uVar6 < 0xa011008) {
    if (uVar6 == 0xa011007) {
      pCVar2 = param_2 + 4;
      *(undefined4 *)pCVar2 = 0;
      *(CMwStack **)param_2 = pCVar2;
      if (-1 < *(int *)(param_1 + 0x18)) {
        CMwNod::Param_Get(*(CMwNod **)pCVar2,(CMwNod *)param_1,param_2,(CMwValueStd *)unaff_EDI);
        return 0;
      }
      *(undefined4 *)param_2 = *(undefined4 *)pCVar2;
      return 0;
    }
    if (uVar6 == 0xa011001) {
      *(CMwStack **)param_2 = param_2 + 4;
      iVar8 = IsZombie(this,unaff_EDI);
      *extraout_EDX = iVar8;
      return 0;
    }
    if (uVar6 == 0xa011003) {
      if (-1 < iVar8) {
        pCVar1 = (CFuncColorGradient *)(param_2 + 4);
        *(CFuncColorGradient **)param_2 = pCVar1;
        pCVar7 = *(CMwParamClass **)(*(int *)(this + 0x28) + 0x14);
        *(CMwParamClass **)pCVar1 = pCVar7;
        CMwParamClass::GetValue(pCVar7,pCVar1,(float)param_1);
        return 0;
      }
      *(undefined4 *)param_2 = *(undefined4 *)(*(int *)(this + 0x28) + 0x14);
      return 0;
    }
    if (uVar6 == 0xa011004) {
      if (-1 < iVar8) {
        pCVar1 = (CFuncColorGradient *)(param_2 + 4);
        *(CFuncColorGradient **)param_2 = pCVar1;
        pCVar7 = *(CMwParamClass **)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x68);
        *(CMwParamClass **)pCVar1 = pCVar7;
        CMwParamClass::GetValue(pCVar7,pCVar1,(float)param_1);
        return 0;
      }
      if ((*(int *)(this + 0x28) != 0) &&
         (iVar8 = *(int *)(*(int *)(this + 0x28) + 0x14), iVar8 != 0)) {
        *(undefined4 *)param_2 = *(undefined4 *)(iVar8 + 0x68);
        return 0;
      }
      *(undefined4 *)param_2 = 0;
      return 0;
    }
LAB_007b3511:
    *(int *)(param_1 + 0x18) = iVar4;
    uVar9 = CSceneObject::VirtualParam_Get((CSceneObject *)this,param_1,param_2,param_3);
    return uVar9;
  }
  if (uVar6 == 0xa01100b) {
    if (*(int *)(this + 0x28) != 0) {
      bVar3 = *(byte *)(*(int *)(this + 0x28) + 0x18);
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = (uint)bVar3;
      return 0;
    }
  }
  else {
    if (uVar6 != 0xa01100c) {
      if (uVar6 == 0xffffffff) {
        return 0;
      }
      goto LAB_007b3511;
    }
    if (*(int *)(this + 0x28) != 0) {
      uVar6 = *(uint *)(*(int *)(this + 0x28) + 0x18);
      *(CMwStack **)param_2 = param_2 + 4;
      *(uint *)(param_2 + 4) = uVar6 >> 0x17 & 1;
      return 0;
    }
  }
  *(undefined4 *)(param_2 + 4) = 0;
  *(CMwStack **)param_2 = param_2 + 4;
  return 0;
}
}

// =================================================
// Function: CSceneMobil::VirtualParam_Set
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CSceneMobil::VirtualParam_Set
          (CSceneMobil *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  CPlugSolid *pCVar5;
  ulong uVar6;
  CSceneMobil *unaff_ESI;
  CPlugSolid *unaff_EDI;
  
  iVar2 = *(int *)(param_1 + 0x18);
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + iVar2 * 4);
  iVar1 = iVar2 + -1;
  *(int *)(param_1 + 0x18) = iVar1;
  uVar4 = *(uint *)(iVar3 + 4);
  if (0xa01100a < uVar4) {
    if (uVar4 < 0xa01100e) {
      if (uVar4 == 0xa01100d) {
        SolidObjectsRemove(this,(CSceneMobil *)unaff_EDI);
        SolidObjectsAdd(this,unaff_ESI);
        return 0;
      }
      if (uVar4 == 0xa01100b) {
        DAT_00d6ce8c = *param_2;
        CHmsItem::SetCountShadowTexCasted
                  (*(CHmsItem **)(this + 0x28),(CHmsItem *)(uint)(byte)DAT_00d6ce8c,
                   (byte)(*(uint *)(*(CHmsItem **)(this + 0x28) + 0x18) >> 0x17) & 1,(int)unaff_EDI)
        ;
        return 0;
      }
      if (uVar4 == 0xa01100c) {
        _DAT_00d6ce90 = *(undefined4 *)param_2;
        CHmsItem::SetCountShadowTexCasted
                  (*(CHmsItem **)(this + 0x28),
                   (CHmsItem *)(uint)(byte)(*(CHmsItem **)(this + 0x28))[0x18],(uchar)_DAT_00d6ce90,
                   (int)unaff_EDI);
        return 0;
      }
    }
    else if (uVar4 == 0xffffffff) {
      return 0;
    }
switchD_007b51cb_caseD_4:
    *(int *)(param_1 + 0x18) = iVar2;
    uVar6 = CSceneObject::VirtualParam_Set((CSceneObject *)this,param_1,param_2,unaff_EDI);
    return uVar6;
  }
  if (uVar4 == 0xa01100a) {
    if (iVar1 < 0) {
      SetMessageHandler(this,(CSceneMobil *)param_2,(CSceneMessageHandler *)unaff_EDI);
      return 0;
    }
    CMwNod::Param_Set(*(CMwNod **)(this + 0x44),(CMwNod *)param_1,(CFastString *)param_2,
                      (CFastStringInt *)unaff_EDI);
    if (*(int *)(this + 0x44) == 0) {
      return 0;
    }
    if (*(int *)(*(int *)(this + 0x44) + 0x18) == 0) {
      return 0;
    }
    EnableAbsorbContactCallback(this,(CSceneMobil *)0x1,(int)unaff_ESI);
    return 0;
  }
  switch((CMwParamClass *)(uVar4 + 0xf5feefff)) {
  case (CMwParamClass *)0x0:
    SetZombie(this,*(CSceneMobil **)param_2,(int)unaff_EDI);
    return 0;
  case (CMwParamClass *)0x1:
    if (iVar1 < 0) {
      return 0;
    }
    CMwParamClass::SetValue
              ((CMwParamClass *)(uVar4 + 0xf5feefff),(CMwCmdAffectParamBool *)(this + 0x28));
    return 0;
  case (CMwParamClass *)0x2:
    if (iVar1 < 0) {
      (**(code **)(*(int *)this + 0xd8))(param_2);
      return 0;
    }
    break;
  case (CMwParamClass *)0x3:
    if (iVar1 < 0) {
      if (param_2 == (CMwStack *)0x0) {
        (**(code **)(*(int *)this + 0xd8))(0);
        return 0;
      }
      pCVar5 = CPlugSolid::CreateModelInstance((CPlugSolid *)param_2,unaff_EDI);
      (**(code **)(*(int *)this + 0xd8))(pCVar5);
      return 0;
    }
    break;
  default:
    goto switchD_007b51cb_caseD_4;
  case (CMwParamClass *)0x6:
    goto switchD_007b51cb_caseD_6;
  }
  param_1 = *(CSystemData **)(*(int *)(this + 0x28) + 0x14);
  CMwParamClass::SetValue((CMwParamClass *)param_2,(CMwCmdAffectParamBool *)&param_1);
switchD_007b51cb_caseD_6:
  return 0;
}
}

// =================================================
// Function: CSceneMobil::VirtualParam_Sub
// =================================================
ulong __thiscall
CSceneMobil::VirtualParam_Sub
          (CSceneMobil *this,CGameCtnDecorationMood *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  ulong unaff_EBX;
  ulong unaff_ESI;
  void *unaff_EDI;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 != 0xa011007) {
    if (iVar2 == 0xa011008) {
      if (iVar1 + -1 < 0) {
        pCVar3 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_2;
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x38,pCVar3,(ulong)unaff_EDI);
        if ((*(int *)(*(int *)pSVar5 + 0x18) != 0) &&
           (pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this + 0x38,pCVar3,unaff_ESI),
           (*(uint *)(*(int *)(*(int *)pSVar5 + 0x18) + 0x24) & 0x800) != 0)) {
          return 0;
        }
        LinkRemove(this,(CSceneMobil *)pCVar3,unaff_EBX);
        return 0;
      }
      CMwParamFastArray<class_CMwParamClass>::SubValue
                ((CFastBufferCat<class_GmVec2,struct_SFastCat> *)(this + 0x38),(CMwStack *)param_1,
                 param_2);
    }
    else if (iVar2 != -1) {
      *(int *)(param_1 + 0x18) = iVar1;
      uVar4 = CSceneObject::VirtualParam_Sub((CSceneObject *)this,param_1,param_2,unaff_EDI);
      return uVar4;
    }
  }
  return 0;
}
}

// =================================================
// Function: CSceneMobil::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CSceneMobil::_scalar_deleting_destructor_(CSceneMobil *this,CPfmHeap *param_1,uint param_2)
{
{
  CSceneMobil *unaff_ESI;
  
  ~CSceneMobil(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CSceneMobil::~CSceneMobil
// =================================================
void __thiscall CSceneMobil::~CSceneMobil(CSceneMobil *this,CSceneMobil *param_1)
{
{
  CMwNod *pCVar1;
  CMwNod *unaff_ESI;
  undefined4 unaff_retaddr;
  CSceneMobil *pCVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00acbaaf;
  local_c = ExceptionList;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 5;
  pCVar2 = this;
  if (*(int **)(this + 0x28) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x28) + 4))(1);
  }
  if (*(int **)(this + 0x34) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x34) + 0x80))();
  }
  local_4._0_1_ = 4;
  if (*(CMwNod **)(this + 0x44) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x44),pCVar1);
  }
  local_4 = CONCAT31(local_4._1_3_,3);
  CFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_>::
  ~CFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_>
            (this + 0x38,(CFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_> *)pCVar1);
  if (*(CMwNod **)(this + 0x34) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x34),unaff_ESI);
  }
  if (*(CMwNod **)(this + 0x30) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x30),(CMwNod *)pCVar2);
  }
  if (*(CMwNod **)(this + 0x2c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x2c),(CMwNod *)pCVar2);
  }
  CSceneObject::~CSceneObject((CSceneObject *)this,(CSceneObject *)pCVar2);
  ExceptionList = (void *)CONCAT31((int3)((uint)unaff_retaddr >> 8),2);
  return;
}
}

