// Class implementation: CGameAdvertising

// =================================================
// Function: CGameAdvertising::ImpressionHelpers_Update
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameAdvertising::ImpressionHelpers_Update(CGameAdvertising *this,CGameAdvertising *param_1)
{
{
  uint uVar1;
  CPlugShaderGeneric *this_00;
  CPlugVisualIndexedLines *pCVar2;
  float fVar3;
  CGameAdvertising *pCVar4;
  CSceneObject *pCVar5;
  CMwNod *extraout_EAX;
  CPlugVisualIndexedLines *extraout_EAX_00;
  CPlugTree *pCVar6;
  CGameAdvertising *pCVar7;
  SCasterCat *pSVar8;
  GmIso3 *pGVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  SCasterCat *pSVar11;
  GmBoxOriented *pGVar12;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  SVolatileTreePointer *unaff_ESI;
  CMwNod *this_01;
  CPlugVisualIndexedLines *pCVar13;
  undefined4 *puVar14;
  CMwNod *unaff_EDI;
  undefined4 *puVar15;
  void *this_02;
  void *in_stack_00000008;
  CFastArray<class_GxTexCoordSet> *in_stack_fffffe1c;
  GxColor *in_stack_fffffe20;
  CPlugVisualIndexedLines *in_stack_fffffe24;
  CPlugVisualIndexedLines *in_stack_fffffe28;
  int iVar16;
  CPlugMaterial *pCVar17;
  GxColor *pGVar18;
  GmVec3 *pGVar19;
  uchar uVar20;
  ulong uVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  CPlugTree *pCVar24;
  SScanner *pSVar25;
  GmIso3 *pGVar26;
  GmIso3 *pGVar27;
  SFillValue *in_stack_fffffe40;
  GxColor *pGVar28;
  SFillValue *in_stack_fffffe44;
  float fStack_1b8;
  undefined4 uStack_1b4;
  int local_1b0;
  int local_1a8;
  ulong uStack_1a4;
  CPlugVisualIndexedLines *pCStack_1a0;
  CPlugVisualIndexedLines *pCStack_19c;
  float fStack_198;
  CSceneMobil *local_194;
  CGameAdvertising *local_190;
  CPlugVisualIndexedLines *local_18c;
  int local_188;
  CPlugVisualIndexedLines *pCStack_180;
  int iStack_17c;
  CGameAdvertising *pCStack_178;
  SScanner aSStack_174 [4];
  CPlugTree *pCStack_170;
  float fStack_16c;
  float fStack_168;
  float fStack_164;
  undefined4 local_160 [2];
  int local_158;
  undefined4 local_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  CGameAdvertising *pCStack_148;
  undefined4 local_144;
  SScanner local_140 [4];
  float local_13c;
  undefined4 local_138;
  undefined4 uStack_134;
  CGameAdvertising *pCStack_130;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 auStack_bc [3];
  GmIso3 aGStack_b0 [4];
  GmIso3 aGStack_ac [4];
  CPlugTree aCStack_a8 [24];
  undefined4 uStack_90;
  CPlugVisualIndexedLines aCStack_8c [4];
  undefined4 auStack_88 [12];
  undefined4 uStack_58;
  undefined4 uStack_44;
  CPlugVisualIndexedLines aCStack_40 [44];
  void *local_14;
  undefined1 *puStack_10;
  void *local_c;
  undefined4 local_8;
  
  puVar22 = &stack0xfffffffc;
  puVar23 = &stack0xfffffffc;
  local_c = (void *)0xffffffff;
  puStack_10 = &LAB_00abcc1c;
  local_14 = ExceptionList;
  pCVar5 = (CSceneObject *)(DAT_00cca150 ^ (uint)&stack0xfffffe30);
  ExceptionList = &local_14;
  local_190 = this;
  if (*(int *)(this + 200) != 0) {
    if ((*(int *)(this + 0xd0) != 0) && (*(int *)(this + 0xcc) == 0)) {
      local_194 = operator_new(0x48);
      local_c = (void *)0x0;
      if (local_194 == (CSceneMobil *)0x0) {
        this_01 = (CMwNod *)0x0;
      }
      else {
        CSceneMobil::CSceneMobil(local_194,(CSceneMobil *)pCVar5);
        this_01 = extraout_EAX;
      }
      local_8 = 0xffffffff;
      if (this_01 != *(CMwNod **)(this + 0xcc)) {
        if (this_01 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(this_01,unaff_EDI);
        }
        if (*(CMwNod **)(this + 0xcc) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(this + 0xcc),unaff_EDI);
        }
        *(CMwNod **)(this + 0xcc) = this_01;
      }
      local_190 = operator_new(0xa0);
      local_8 = 1;
      if (local_190 == (CGameAdvertising *)0x0) {
        pCVar13 = (CPlugVisualIndexedLines *)0x0;
      }
      else {
        CPlugVisualIndexedLines::CPlugVisualIndexedLines
                  ((CPlugVisualIndexedLines *)local_190,(CPlugVisualIndexedLines *)unaff_EDI);
        pCVar13 = extraout_EAX_00;
      }
      uVar20 = (uchar)unaff_EDI;
      uStack_150 = 0x3f800000;
      uStack_14c = 0x3f800000;
      pCStack_148 = (CGameAdvertising *)0x3f800000;
      local_144 = 0x3f800000;
      local_8 = 0xffffffff;
      fStack_16c = 1.0;
      fStack_168 = 1.0;
      fStack_164 = 1.0;
      local_160[0] = 0x3f800000;
      pCStack_19c = (CPlugVisualIndexedLines *)0x0;
      fStack_198 = 0.0;
      local_194 = (CSceneMobil *)_DAT_00b3380c;
      in_stack_fffffe44 = (SFillValue *)0x0;
      fStack_1b8 = 0.0;
      uStack_1b4 = 0;
      pCVar17 = (CPlugMaterial *)0x3f800000;
      iVar16 = 0;
      CPlugVisualIndexedLines::AddNewLine
                (pCVar13,(CPlugVisualIndexedLines *)&stack0xfffffe44,(ushort)&pCStack_19c,
                 (GmVec3 *)&fStack_16c,(GxColor *)&uStack_150,1.0,1.0);
      CPlugVisual::EnableVertexColor((CPlugVisual *)pCVar13,(CPlugVisual *)0x1,iVar16);
      uVar1 = *(uint *)(pCVar13 + 0x1c);
      if ((uVar1 & 8) != 0) {
        *(uint *)(pCVar13 + 0x1c) = uVar1 & 0xfffffff7;
        if (((uVar1 & 0x400) == 0) &&
           (*(uint *)(pCVar13 + 0x1c) = uVar1 & 0xfffffff7 | 0x400,
           DAT_00d6eb04 != (undefined4 *)0x0)) {
          (**(code **)*DAT_00d6eb04)(pCVar13);
        }
      }
      uVar1 = *(uint *)(pCVar13 + 0x1c);
      if ((uVar1 & 0x20) != 0) {
        *(uint *)(pCVar13 + 0x1c) = uVar1 & 0xffffffdf;
        if (((uVar1 & 0x400) == 0) &&
           (*(uint *)(pCVar13 + 0x1c) = uVar1 & 0xffffffdf | 0x400,
           DAT_00d6eb04 != (undefined4 *)0x0)) {
          (**(code **)*DAT_00d6eb04)(pCVar13);
        }
      }
      in_stack_fffffe1c = (CFastArray<class_GxTexCoordSet> *)0x6f8cd3;
      pCVar6 = CSceneMobil::AddVisual
                         (*(CSceneMobil **)(this + 0xcc),(CSceneMobil *)pCVar13,(CPlugVisual *)0x0,
                          (CPlugShader *)0x0,pCVar17);
      pGVar18 = (GxColor *)0x1;
      (**(code **)(*(int *)pCVar6 + 0xbc))();
      this_00 = *(CPlugShaderGeneric **)(pCVar6 + 0x94);
      in_stack_fffffe24 = (CPlugVisualIndexedLines *)0x1;
      in_stack_fffffe20 = (GxColor *)0x6f8cf3;
      CPlugShaderGeneric::SetVertexColor(this_00,(CPlugShaderGeneric *)0x1,0,pGVar18);
      CPlugShader::SetBiasZ((CPlugShader *)this_00,(CPlugShader *)0x1f,uVar20);
      pCVar6 = CSceneMobil::GetTree(*(CSceneMobil **)(this + 0xcc),unaff_ESI);
      unaff_ESI = (SVolatileTreePointer *)0x1;
      (**(code **)(*(int *)pCVar6 + 0xbc))();
      puVar14 = (undefined4 *)PTR_DAT_00cf859c;
      puVar15 = auStack_88;
      for (iVar16 = 0xc; iVar16 != 0; iVar16 = iVar16 + -1) {
        *puVar15 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar15 = puVar15 + 1;
      }
      uStack_58 = 0;
      in_stack_fffffe28 = (CPlugVisualIndexedLines *)0x6f8d4f;
      (**(code **)(**(int **)(*(int *)(this + 0xd0) + 0x14) + 0x78))(*(undefined4 *)(this + 0xcc));
      goto LAB_006f8d81;
    }
    if ((*(int *)(this + 200) != 0) && (puVar22 = &stack0xfffffffc, *(int *)(this + 0xd0) != 0))
    goto LAB_006f8d81;
  }
  puVar22 = &stack0xfffffffc;
  if (*(CSceneObject **)(this + 0xcc) != (CSceneObject *)0x0) {
    in_stack_fffffe28 = (CPlugVisualIndexedLines *)0x6f8d6c;
    CSceneObject::RemoveFromScene(*(CSceneObject **)(this + 0xcc),pCVar5);
    puVar22 = puVar23;
    if (*(CMwNod **)(this + 0xcc) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xcc),unaff_EDI);
      *(undefined4 *)(this + 0xcc) = 0;
      puVar22 = puVar23;
    }
  }
LAB_006f8d81:
  if ((*(int *)(this + 200) != 0) && (*(int *)(this + 0xd0) != 0)) {
    pCVar6 = CSceneMobil::GetTree(*(CSceneMobil **)(this + 0xcc),unaff_ESI);
    uVar21 = 0;
    iVar16 = (**(code **)(*(int *)pCVar6 + 0x80))();
    pCVar2 = *(CPlugVisualIndexedLines **)(iVar16 + 0x90);
    pCVar13 = pCVar2 + 0x78;
    pGVar19 = (GmVec3 *)0x6f8dcb;
    pCStack_19c = pCVar2;
    local_18c = pCVar13;
    CFastBuffer<class_CSystemFidsFolder*>::SetCount
              (pCVar13,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,uVar21);
    pGVar18 = (GxColor *)0x6f8ddb;
    CFastBuffer<class_CSystemFidsFolder*>::SetCount
              ((void *)(*(int *)(pCVar2 + 0x98) + 0x1c),(CFastBuffer<class_CSystemFidsFolder*> *)0x0
               ,(ulong)puVar22);
    pCVar7 = (CGameAdvertising *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x90,unaff_EBX);
    pCStack_178 = (CGameAdvertising *)0x0;
    pCStack_130 = pCVar7;
    if (pCVar7 != (CGameAdvertising *)0x0) {
      do {
        pCVar4 = pCStack_178;
        pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x90,
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCStack_178,
                            (ulong)in_stack_fffffe40);
        fStack_168 = (float)(*(int *)pSVar8 + 0x48);
        in_stack_fffffe40 = (SFillValue *)&pCStack_19c;
        pSVar25 = (SScanner *)&fStack_16c;
        local_158 = *(int *)pSVar8 + 0x58;
        local_154 = 0;
        iVar16 = CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>
                 ::SScanner::GetNext(&local_158,pSVar25,(ulong *)in_stack_fffffe40,in_stack_fffffe44
                                    );
        pCVar13 = pCStack_180;
        while (pCStack_180 = pCVar13, iVar16 != 0) {
          if (*(int *)(pCStack_1a0 + 0x18) != 0) {
            pSVar25 = local_140;
            pCStack_148 = this + 0xb4;
            local_144 = 0;
            iVar16 = CFastMapTable<struct_CGameAdvertising::SInstanceId>::SScanner::GetNext
                               (&pCStack_148,aSStack_174,(ulong *)pSVar25,in_stack_fffffe40);
            pCVar6 = pCStack_170;
            while (pCStack_170 = pCVar6, iVar16 != 0) {
              if (local_13c == fStack_16c) {
                pCVar24 = aCStack_a8;
                uVar21 = 0x6f8eab;
                CPlugTree::GetThisToRootTransfo
                          (pCVar6,pCVar24,(GmIso4 *)0x1,0,(CPlugTree *)in_stack_fffffe44);
                pGVar27 = *(GmIso3 **)(this + 0xd0);
                in_stack_fffffe44 = (SFillValue *)0x6f8ec1;
                pGVar9 = (GmIso3 *)
                         (**(code **)(**(int **)(*(int *)(*(int *)(pCVar6 + 0x14) + 0x14) + 0x40) +
                                     0x78))();
                if (pGVar9 == pGVar27) {
                  pGVar26 = (GmIso3 *)0x6f8eda;
                  pGVar9 = (GmIso3 *)
                           (**(code **)(**(int **)(*(int *)(*(int *)(pCVar6 + 0x14) + 0x14) + 0x40)
                                       + 0x7c))();
                  GmIso4::Mult(&uStack_d0,pGVar9,(GmIso3 *)in_stack_fffffe1c);
                  fStack_16c = *(float *)(pCVar6 + 0x90);
                  in_stack_fffffe1c = (CFastArray<class_GxTexCoordSet> *)&fStack_16c;
                  pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                            CFastArray<class_CGameMenuFrame*>::Find
                                      (this + 0x9c,in_stack_fffffe1c,
                                       (GxTexCoordSet *)in_stack_fffffe20);
                  if (pCVar10 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
                    in_stack_fffffe1c = (CFastArray<class_GxTexCoordSet> *)0x6f8f1a;
                    in_stack_fffffe20 = (GxColor *)pCVar10;
                    pSVar8 = CFastBuffer<struct_CGameAdvertising::SImpressionAxe>::operator[]
                                       (this + 0xa8,pCVar10,(ulong)in_stack_fffffe24);
                    if ((0.0 <= *(float *)(pSVar8 + 0x3c)) &&
                       ((*(byte *)((int)fStack_1b8 + 0xc) & 2) == 0)) {
                      uStack_1a4 = *(ulong *)(pSVar8 + 0x30);
                      pCStack_1a0 = *(CPlugVisualIndexedLines **)(pSVar8 + 0x34);
                      pCStack_19c = *(CPlugVisualIndexedLines **)(pSVar8 + 0x38);
                      pSVar11 = CFastBuffer<struct_CGameAdvertising::SImpressionAxe>::operator[]
                                          (this + 0xa8,pCVar10,(ulong)in_stack_fffffe28);
                      fVar3 = (float)_DAT_00b3d380;
                      pGVar27 = (GmIso3 *)((float)pCStack_1a0 + *(float *)pSVar11 * fVar3);
                      in_stack_fffffe44 =
                           (SFillValue *)(*(float *)(pSVar11 + 4) * fVar3 + (float)pCStack_19c);
                      fStack_1b8 = fVar3 * *(float *)(pSVar11 + 8) + fStack_198;
                      GmVec3::Mult(&stack0xfffffe40,(GmIso3 *)&uStack_c0,(GmIso3 *)pGVar19);
                      GmVec3::Mult(&pCStack_19c,(GmIso3 *)auStack_bc,(GmIso3 *)pGVar18);
                      uStack_108 = 0x3f800000;
                      uStack_104 = 0x3f800000;
                      in_stack_fffffe20 = (GxColor *)&uStack_108;
                      uStack_100 = 0x3f800000;
                      in_stack_fffffe1c = (CFastArray<class_GxTexCoordSet> *)&uStack_c8;
                      uStack_fc = 0x3f800000;
                      uStack_c8 = 0;
                      uStack_c4 = 0;
                      uStack_c0 = 0x3f800000;
                      auStack_bc[0] = 0x3f800000;
                      pGVar18 = (GxColor *)0x3f800000;
                      pGVar9 = (GmIso3 *)0x0;
                      CPlugVisualIndexedLines::AddNewLine
                                (pCStack_19c,(CPlugVisualIndexedLines *)&fStack_198,
                                 (ushort)&fStack_1b8,(GmVec3 *)in_stack_fffffe1c,in_stack_fffffe20,
                                 1.0,1.0);
                      pSVar11 = pSVar8 + 0xc;
                      puVar14 = &uStack_90;
                      for (iVar16 = 0xf; iVar16 != 0; iVar16 = iVar16 + -1) {
                        *puVar14 = *(undefined4 *)pSVar11;
                        pSVar11 = pSVar11 + 4;
                        puVar14 = puVar14 + 1;
                      }
                      GmBoxOriented::Mult(&uStack_90,(GmIso3 *)&uStack_c0,pGVar9);
                      if (*(uint *)(iStack_17c + 0xc) < *(uint *)(local_1b0 + 0x18)) {
                        pGVar12 = (GmBoxOriented *)&local_13c;
                        local_13c = 0.0;
                        local_138 = 0x3f800000;
                        pCStack_130 = (CGameAdvertising *)0x3f800000;
                        uStack_134 = 0;
                      }
                      else {
                        pGVar12 = (GmBoxOriented *)&uStack_dc;
                        uStack_dc = 0x3f800000;
                        uStack_d8 = 0;
                        uStack_d4 = 0;
                        uStack_d0 = 0x3f800000;
                      }
                      in_stack_fffffe28 = aCStack_8c;
                      in_stack_fffffe24 = (CPlugVisualIndexedLines *)0x6f90e3;
                      CPlugVisualIndexedLines::AddNewBox
                                (pCStack_1a0,in_stack_fffffe28,pGVar12,pGVar18);
                    }
                    this_02 = (void *)(local_188 + 0xa8);
                    pGVar19 = (GmVec3 *)0x6f90f5;
                    pGVar18 = (GxColor *)pCVar10;
                    pSVar11 = CFastBuffer<struct_CGameAdvertising::SImpressionAxe>::operator[]
                                        (this_02,pCVar10,uVar21);
                    this = pCStack_178;
                    if ((0.0 <= *(float *)(pSVar8 + 0x3c)) &&
                       ((*(byte *)(local_1a8 + 0xc) & 2) != 0)) {
                      pCStack_170 = *(CPlugTree **)(pSVar11 + 0x78);
                      fStack_16c = *(float *)(pSVar11 + 0x7c);
                      fStack_168 = *(float *)(pSVar11 + 0x80);
                      pSVar8 = CFastBuffer<struct_CGameAdvertising::SImpressionAxe>::operator[]
                                         (this_02,pCVar10,(ulong)pCVar24);
                      fVar3 = (float)_DAT_00b3d380;
                      pCStack_1a0 = (CPlugVisualIndexedLines *)
                                    (*(float *)(pSVar8 + 0x48) * fVar3 + fStack_16c);
                      pCStack_19c = (CPlugVisualIndexedLines *)
                                    (*(float *)(pSVar8 + 0x4c) * fVar3 + fStack_168);
                      fStack_198 = fVar3 * *(float *)(pSVar8 + 0x50) + fStack_164;
                      GmVec3::Mult(&pCStack_1a0,aGStack_b0,pGVar26);
                      GmVec3::Mult(&fStack_168,aGStack_ac,pGVar27);
                      uStack_d8 = 0x3f800000;
                      uStack_d4 = 0x3f800000;
                      pGVar18 = (GxColor *)&uStack_d8;
                      uStack_d0 = 0x3f800000;
                      pGVar19 = (GmVec3 *)&uStack_118;
                      uStack_cc = 0x3f800000;
                      in_stack_fffffe28 = (CPlugVisualIndexedLines *)&fStack_198;
                      uStack_118 = 0x3f800000;
                      uStack_114 = 0;
                      uStack_110 = 0x3f800000;
                      uStack_10c = 0x3f800000;
                      pGVar28 = (GxColor *)0x3f800000;
                      pGVar27 = (GmIso3 *)0x0;
                      in_stack_fffffe24 = (CPlugVisualIndexedLines *)&fStack_164;
                      in_stack_fffffe20 = (GxColor *)0x6f922c;
                      CPlugVisualIndexedLines::AddNewLine
                                (local_18c,in_stack_fffffe24,(ushort)in_stack_fffffe28,pGVar19,
                                 pGVar18,1.0,1.0);
                      pSVar8 = pSVar11 + 0x54;
                      puVar14 = &uStack_44;
                      for (iVar16 = 0xf; iVar16 != 0; iVar16 = iVar16 + -1) {
                        *puVar14 = *(undefined4 *)pSVar8;
                        pSVar8 = pSVar8 + 4;
                        puVar14 = puVar14 + 1;
                      }
                      GmBoxOriented::Mult(&uStack_44,aGStack_b0,pGVar27);
                      if (*(uint *)((int)fStack_16c + 0xc) < *(uint *)(pCStack_1a0 + 0x18)) {
                        pGVar12 = (GmBoxOriented *)&uStack_10c;
                        uStack_10c = 0;
                        uStack_108 = 0x3f800000;
                        uStack_100 = 0x3f800000;
                        uStack_104 = 0;
                      }
                      else {
                        pGVar12 = (GmBoxOriented *)&uStack_ec;
                        uStack_ec = 0x3f800000;
                        uStack_e8 = 0;
                        uStack_e4 = 0;
                        uStack_e0 = 0x3f800000;
                      }
                      CPlugVisualIndexedLines::AddNewBox
                                ((CPlugVisualIndexedLines *)local_190,aCStack_40,pGVar12,pGVar28);
                      this = pCStack_178;
                    }
                  }
                }
              }
              in_stack_fffffe40 = (SFillValue *)&local_13c;
              pSVar25 = (SScanner *)&pCStack_170;
              iVar16 = CFastMapTable<struct_CGameAdvertising::SInstanceId>::SScanner::GetNext
                                 (&local_144,pSVar25,(ulong *)in_stack_fffffe40,in_stack_fffffe44);
              pCVar6 = pCStack_170;
            }
          }
          pGVar18 = (GxColor *)0x6f92f8;
          iVar16 = CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>
                   ::SScanner::GetNext(local_160,aSStack_174,&uStack_1a4,(SFillValue *)pSVar25);
          pCVar7 = pCStack_130;
          pCVar13 = pCStack_180;
          pCVar4 = pCStack_178;
        }
        pCStack_178 = pCVar4 + 1;
      } while (pCStack_178 < pCVar7);
    }
    uVar21 = CFastBuffer<class_CCrystalFace*>::GetCount
                       (pCVar13,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffe40);
    if (uVar21 == 0) {
      pCVar6 = CSceneMobil::GetTree
                         (*(CSceneMobil **)(this + 0xcc),(SVolatileTreePointer *)in_stack_fffffe44);
      *(uint *)(pCVar6 + 0x9c) = *(uint *)(pCVar6 + 0x9c) & 0xfffffff7;
      ExceptionList = in_stack_00000008;
      return;
    }
    pCVar6 = CSceneMobil::GetTree
                       (*(CSceneMobil **)(this + 0xcc),(SVolatileTreePointer *)in_stack_fffffe44);
    (**(code **)(*(int *)pCVar6 + 0xbc))();
    pCVar6 = CSceneMobil::GetTree(*(CSceneMobil **)(this + 0xcc),(SVolatileTreePointer *)pGVar18);
    *(uint *)(pCVar6 + 0x9c) = *(uint *)(pCVar6 + 0x9c) | 8;
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CGameAdvertising::IsInit
// =================================================
int __thiscall CGameAdvertising::IsInit(CGameAdvertising *this,SVisualHandler *param_1)
{
{
  return (uint)(*(int *)(this + 0x84) != 0);
}
}

// =================================================
// Function: CGameAdvertising::SetAdvertisingZone
// =================================================
void __thiscall
CGameAdvertising::SetAdvertisingZone
          (CGameAdvertising *this,CGameAdvertising *param_1,CFastString *param_2,
          CFastString *param_3,CFastString *param_4,CFastString *param_5,CFastString *param_6,
          CFastString *param_7,CFastString *param_8)
{
{
  CFastString *pCVar1;
  CMwNod *pCVar2;
  CFastString *pCVar3;
  int extraout_EAX;
  int extraout_EAX_00;
  SCasterCat *pSVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  int iVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  SStringParam *unaff_EBP;
  SStringParam *unaff_ESI;
  CGameAdvertising *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  int *unaff_EDI;
  undefined4 *in_stack_00000024;
  undefined4 in_stack_00000028;
  CMwNod *in_stack_0000002c;
  CMwNod *in_stack_00000030;
  undefined4 in_stack_00000034;
  undefined4 *in_stack_00000038;
  void *in_stack_0000003c;
  CFastString *in_stack_00000054;
  CGameAdvertising *in_stack_0000005c;
  CFastString *in_stack_00000060;
  CFastString *pCVar8;
  CGameAdvertising *pCVar9;
  SStringParam *in_stack_ffffffe0;
  SStringParam *in_stack_ffffffe4;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffe8;
  GmFrustumIso4 *in_stack_ffffffec;
  CGameAdvertising *in_stack_fffffff0;
  CMwNod *pCVar10;
  CGameAdvertisingRadial *pCVar11;
  CGameAdvertisingRadial *pCVar12;
  SFillValue *pSVar13;
  CFastBuffer<class_CCrystalFace*> *pCVar14;
  CFastBuffer<class_CCrystalFace*> *pCVar15;
  
  pCVar14 = (CFastBuffer<class_CCrystalFace*> *)&LAB_00abceb8;
  pCVar3 = (CFastString *)param_1;
  if (*(int *)(this + 0x28) != 0) {
    pCVar3 = param_3;
  }
  pCVar11 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar9 = this;
  CFastString::CFastString
            ((CFastString *)&stack0xffffffe4,pCVar3,(char *)(DAT_00cca150 ^ (uint)&stack0xffffffcc))
  ;
  if (*(int *)(this + 0x28) == 0) {
    param_4 = param_3;
  }
  else {
    param_4 = param_5;
  }
  this_00 = (CGameAdvertising *)param_8;
  if (*(int *)param_8 == 0) {
    this_00 = this + 0x38;
  }
  if ((in_stack_ffffffe8 != (CFastBuffer<class_CCrystalFace*> *)0x0) && (*(int *)this_00 != 0)) {
    in_stack_fffffff0 = (CGameAdvertising *)&DAT_00b83a8c;
    pCVar11 = (CGameAdvertisingRadial *)&DAT_00000004;
    if ((*(int *)this_00 == 4) &&
       (CFastString::Compare
                  ((CFastString *)this_00,(SParam_Fids *)&stack0xfffffff0,(SParam *)0x0,unaff_EDI,
                   (int *)unaff_ESI), extraout_EAX == 0)) {
      pCVar14 = DAT_00d71ca0;
      CFastString::SetString
                ((CFastString *)&stack0xfffffff0,(CFastStringInt *)&stack0xfffffff8,unaff_EBP);
    }
    else {
      CFastString::Concat((CFastString *)&stack0xffffffec,(CFastStringInt *)0x2e,unaff_ESI);
      pCVar14 = *(CFastBuffer<class_CCrystalFace*> **)(this_00 + 4);
      CFastString::Concat((CFastString *)&stack0xfffffff0,(CFastStringInt *)&stack0xfffffff8,
                          unaff_EBP);
    }
  }
  param_8 = (CFastString *)(this + 0x58);
  pCVar12 = pCVar11;
  pCVar15 = pCVar14;
  if ((pCVar11 == *(CGameAdvertisingRadial **)(this + 0x58)) &&
     (CFastString::Compare
                (param_8,(SParam_Fids *)&stack0xfffffffc,(SParam *)0x0,(int *)unaff_EBX,
                 (int *)pCVar9), extraout_EAX_00 == 0)) {
    if (pCVar11 == (CGameAdvertisingRadial *)PTR_DAT_00bbf7d8) {
      ExceptionList = in_stack_0000003c;
      return;
    }
  }
  else {
    param_7 = (CFastString *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x90,unaff_EBX);
    param_6 = (CFastString *)0x0;
    if (param_7 != (CFastString *)0x0) {
      do {
        pCVar8 = param_6;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x90,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_6,
                            (ulong)pCVar9);
        pCVar1 = *(CFastString **)pSVar4;
        pCVar3 = pCVar1 + 0x48;
        pCVar9 = (CGameAdvertising *)0x6fa5ac;
        CGameAdvertisingElement::CImpressionCollector::ReportFrameFinished
                  (pCVar3,(CImpressionCollector *)in_stack_ffffffe0);
        in_stack_ffffffe0 = (SStringParam *)0x6fa5b3;
        CGameAdvertisingElement::CImpressionCollector::ReportFrameFinished
                  (pCVar3,(CImpressionCollector *)in_stack_ffffffe4);
        in_stack_ffffffe4 = (SStringParam *)0x6fa5bb;
        pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x4c,in_stack_ffffffe8);
        pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        this = in_stack_fffffff0;
        if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (in_stack_ffffffec + 0x4c,pCVar7,(ulong)pCVar8);
            pCVar8 = pCVar1;
            (**(code **)(**(int **)pSVar4 + 0x90))();
            pCVar7 = pCVar7 + 1;
            this = in_stack_fffffff0;
          } while (pCVar7 < pCVar5);
        }
        CGameAdvertisingElement::CImpressionCollector::ClearAll
                  (pCVar3,(CImpressionCollector *)pCVar8);
        param_6 = param_6 + 1;
        in_stack_fffffff0 = this;
      } while (param_6 < param_7);
    }
    *(undefined4 *)(this + 0xd0) = 0;
    ImpressionHelpers_Update(this,pCVar9);
    param_1 = (CGameAdvertising *)in_stack_00000024[1];
    param_2 = (CFastString *)*in_stack_00000024;
    CFastString::SetString
              ((CFastString *)(this + 0x60),(CFastStringInt *)&param_1,in_stack_ffffffe0);
    param_2 = *(CFastString **)(in_stack_00000030 + 4);
    param_3 = *(CFastString **)in_stack_00000030;
    CFastString::SetString
              ((CFastString *)(this + 0x68),(CFastStringInt *)&param_2,in_stack_ffffffe4);
    param_3 = (CFastString *)in_stack_00000038[1];
    param_4 = (CFastString *)*in_stack_00000038;
    CFastString::SetString
              ((CFastString *)(this + 0x78),(CFastStringInt *)&param_3,
               (SStringParam *)in_stack_ffffffe8);
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0xa8,in_stack_ffffffec);
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (this + 0x9c,(GmFrustumIso4 *)in_stack_fffffff0);
    if (param_4 == (CFastString *)0x0) {
      pCVar10 = (CMwNod *)&param_2;
      param_6 = (CFastString *)(this + 0xb4);
      param_7 = (CFastString *)0x0;
      iVar6 = CFastMapTable<struct_CGameAdvertising::SInstanceId>::SScanner::GetNext
                        (&param_6,(SScanner *)&stack0x00000030,(ulong *)pCVar10,
                         (SFillValue *)pCVar12);
      if (iVar6 != 0) {
        do {
          pSVar13 = (SFillValue *)0x6fa6b8;
          pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x4c,pCVar14);
          pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            do {
              pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (this + 0x4c,pCVar7,(ulong)pCVar10);
              pCVar10 = (CMwNod *)0x0;
              (**(code **)(**(int **)pSVar4 + 0x94))();
              pCVar7 = pCVar7 + 1;
            } while (pCVar7 < pCVar5);
          }
          pCVar2 = in_stack_0000002c;
          CMwNod::MwSubDependant(in_stack_0000002c,(CMwNod *)this,pCVar10);
          *(uint *)(pCVar2 + 0x9c) = *(uint *)(pCVar2 + 0x9c) & 0xffffefff;
          pCVar10 = (CMwNod *)&param_2;
          iVar6 = CFastMapTable<struct_CGameAdvertising::SInstanceId>::SScanner::GetNext
                            (&param_6,(SScanner *)&stack0x00000030,(ulong *)pCVar10,pSVar13);
        } while (iVar6 != 0);
      }
      CFastMapTable<struct_CGameAdvertising::SInstanceId>::Clear
                ((CFastMapTable<struct_CGameAdvertising::SInstanceId> *)(this + 0xb4),
                 (TiXmlNode *)pCVar14);
    }
    iVar6 = CFastBuffer<class_CAudioSound*>::IsEmpty(this + 0x90,(SShaderCustom *)pCVar15);
    if ((iVar6 == 0) && (param_7 == (CFastString *)0x0)) {
      Flush(this,pCVar11);
      CFastBuffer<class_CPlugBitmapPackInput*>::DeleteAll
                (this + 0x90,(CFastArray<class_CCrystalEdge*> *)param_1);
    }
    param_1 = (CGameAdvertising *)0x6fa750;
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this + 0x4c,(CFastBuffer<class_CCrystalFace*> *)param_2);
    pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        param_1 = (CGameAdvertising *)0x6fa760;
        param_2 = (CFastString *)pCVar7;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x4c,pCVar7,(ulong)param_3);
        param_3 = *(CFastString **)(this + 0x28);
        param_2 = in_stack_00000060;
        param_1 = in_stack_0000005c;
        (**(code **)(**(int **)pSVar4 + 0x80))();
        pCVar7 = pCVar7 + 1;
      } while (pCVar7 < pCVar5);
    }
    param_2 = (CFastString *)&stack0x00000030;
    in_stack_00000030 = in_stack_0000002c;
    in_stack_00000034 = in_stack_00000028;
    param_1 = (CGameAdvertising *)0x6fa7a9;
    CFastString::SetString(in_stack_00000054,(CFastStringInt *)param_2,(SStringParam *)param_3);
    if (in_stack_00000030 == (CMwNod *)PTR_DAT_00bbf7d8) {
      ExceptionList = in_stack_0000003c;
      return;
    }
    param_3 = (CFastString *)(in_stack_00000030 + -1);
    if (((byte)in_stack_00000030[-1] & 0x80) != 0) {
      param_3 = (CFastString *)(in_stack_00000030 + -4);
    }
  }
  param_2 = (CFastString *)0x6fa7c7;
  operator_delete__(param_3);
  ExceptionList = in_stack_0000003c;
  return;
}
}

