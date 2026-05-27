// Class implementation: CSceneFxVisionK

// =================================================
// Function: CSceneFxVisionK::BranchingArc_Step
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneFxVisionK::BranchingArc_Step(CSceneFxVisionK *this,CSceneFxVisionK *param_1)
{
{
  GmMat3 *pGVar1;
  uint *puVar2;
  float fVar3;
  float fVar4;
  CSceneFxVisionK *pCVar5;
  SCasterCat *pSVar6;
  SCasterCat *pSVar7;
  SCasterCat *pSVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  int iVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  ulong unaff_EBP;
  SCasterCat *pSVar11;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar13;
  float unaff_retaddr;
  float in_stack_00000008;
  float in_stack_0000000c;
  float in_stack_00000010;
  float in_stack_00000014;
  float in_stack_00000018;
  GmMat3 *in_stack_ffffff94;
  CSceneFxVisionK *pCVar14;
  CSceneFxVisionK *pCVar15;
  CSceneFxVisionK *local_60;
  CSceneFxVisionK *local_5c;
  CFastBufferRef<class_CGameMobil> *local_54;
  SCasterCat *local_50;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_4c;
  undefined8 local_48;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float fStack_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  pCVar15 = this;
  GmFunc::SetRandSeed(*(ulong *)(this + 0x130));
  pSVar11 = (SCasterCat *)(*(int *)(*(int *)(this + 0x118) + 0x90) + 0x78);
  pCVar5 = (CSceneFxVisionK *)CFastBuffer<class_CCrystalFace*>::GetCount(pSVar11,unaff_EDI);
  *(int *)(this + 0x124) = *(int *)(this + 0x124) + 1;
  if ((*(int *)(this + 0x124) == *(int *)(this + 0xc0)) &&
     (*(undefined4 *)(this + 0x124) = 0, pCVar5 < (CSceneFxVisionK *)0x4000)) {
    pCVar14 = pCVar5;
    CFastBuffer<struct_CPlugVisual::SSplit>::AllocSetCount
              (pSVar11,(CFastBuffer<class_GxVertex2> *)((int)pCVar5 * 2),unaff_ESI);
    __CItan();
    local_60 = (CSceneFxVisionK *)0x0;
    if (pCVar5 != (CSceneFxVisionK *)0x0) {
      do {
        iVar10 = *(int *)(this + 300);
        pSVar6 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                           (pSVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                    (local_60 + iVar10),unaff_EBP);
        pSVar7 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                           (pSVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                    (local_60 + (1 - iVar10)),(ulong)unaff_EBX);
        unaff_EBP = 0x80eb6d;
        pSVar8 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                           (pSVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                    (local_60 + iVar10) + (int)local_5c,(ulong)in_stack_ffffff94);
        pSVar11 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                            (pSVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                     (local_60 + (1 - iVar10)) + (int)local_4c,(ulong)pCVar14);
        *(undefined4 *)pSVar8 = *(undefined4 *)pSVar6;
        *(undefined4 *)(pSVar8 + 4) = *(undefined4 *)(pSVar6 + 4);
        *(undefined4 *)(pSVar8 + 8) = *(undefined4 *)(pSVar6 + 8);
        *(undefined4 *)(pSVar8 + 0xc) = *(undefined4 *)(pSVar6 + 0xc);
        *(undefined4 *)(pSVar8 + 0x10) = *(undefined4 *)(pSVar6 + 0x10);
        *(undefined4 *)(pSVar8 + 0x14) = *(undefined4 *)(pSVar6 + 0x14);
        *(undefined4 *)(pSVar8 + 0x18) = *(undefined4 *)(pSVar6 + 0x18);
        *(undefined4 *)(pSVar8 + 0x1c) = *(undefined4 *)(pSVar6 + 0x1c);
        *(undefined4 *)(pSVar8 + 0x20) = *(undefined4 *)(pSVar6 + 0x20);
        *(undefined4 *)(pSVar8 + 0x24) = *(undefined4 *)(pSVar6 + 0x24);
        _rand();
        fVar3 = local_48._4_4_;
        local_48 = (ulonglong)(uint)local_48._4_4_ << 0x20;
        __CIcos();
        local_3c = (float)extraout_ST0;
        local_18 = local_3c * fVar3;
        __CIsin();
        local_3c = (float)extraout_ST0_00;
        pCVar14 = (CSceneFxVisionK *)0x1;
        local_14 = local_3c * fVar3;
        pGVar1 = (GmMat3 *)(pSVar6 + 0xc);
        unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x80ec29;
        in_stack_ffffff94 = pGVar1;
        GmMat3::SetDOV(&local_c,pGVar1,(GmVec3 *)0x1,(ulong)pCVar15);
        *(float *)(pSVar7 + 0xc) = local_14 * local_8 + local_10 * local_4 + unaff_retaddr * 0.0;
        *(float *)(pSVar7 + 0x10) =
             in_stack_0000000c * 0.0 + in_stack_00000008 * local_10 + (float)param_1 * local_14;
        *(float *)(pSVar7 + 0x14) =
             in_stack_00000014 * local_10 + in_stack_00000010 * local_14 + in_stack_00000018 * 0.0;
        *(float *)(pSVar7 + 0xc) = *(float *)(pSVar7 + 0xc) + *(float *)pGVar1;
        *(float *)(pSVar7 + 0x10) = *(float *)(pSVar7 + 0x10) + *(float *)(pSVar6 + 0x10);
        *(float *)(pSVar7 + 0x14) = *(float *)(pSVar7 + 0x14) + *(float *)(pSVar6 + 0x14);
        local_38 = *(float *)(pSVar7 + 0x14) * *(float *)(pSVar7 + 0x14) +
                   *(float *)(pSVar7 + 0xc) * *(float *)(pSVar7 + 0xc) +
                   *(float *)(pSVar7 + 0x10) * *(float *)(pSVar7 + 0x10);
        fVar3 = local_14;
        fVar4 = local_10;
        pCVar5 = pCVar15;
        if (_DAT_00d0ca90 < local_38) {
          pCVar5 = (CSceneFxVisionK *)0x80ecd9;
          fVar13 = (float10)func_0x009c1b40();
          fVar3 = 1.0 / (float)fVar13;
          *(float *)(pSVar7 + 0xc) = fVar3 * *(float *)(pSVar7 + 0xc);
          *(float *)(pSVar7 + 0x10) = fVar3 * *(float *)(pSVar7 + 0x10);
          *(float *)(pSVar7 + 0x14) = fVar3 * *(float *)(pSVar7 + 0x14);
          fVar3 = local_28;
          fVar4 = local_24;
        }
        local_28 = -fVar3;
        local_24 = -fVar4;
        fVar3 = (float)_DAT_00b56ec0;
        *(float *)(pSVar11 + 0xc) = local_28 * fStack_1c + local_24 * local_18 + local_14 * fVar3;
        *(float *)(pSVar11 + 0x10) = local_8 * fVar3 + local_c * local_24 + local_10 * local_28;
        *(float *)(pSVar11 + 0x14) =
             fVar3 * (float)param_1 + local_4 * local_28 + unaff_retaddr * local_24;
        *(float *)(pSVar11 + 0xc) = *(float *)pGVar1 + *(float *)(pSVar11 + 0xc);
        *(float *)(pSVar11 + 0x10) = *(float *)(pSVar11 + 0x10) + *(float *)(pSVar6 + 0x10);
        *(float *)(pSVar11 + 0x14) = *(float *)(pSVar6 + 0x14) + *(float *)(pSVar11 + 0x14);
        if (_DAT_00d0ca90 <
            *(float *)(pSVar11 + 0x14) * *(float *)(pSVar11 + 0x14) +
            *(float *)(pSVar11 + 0xc) * *(float *)(pSVar11 + 0xc) +
            *(float *)(pSVar11 + 0x10) * *(float *)(pSVar11 + 0x10)) {
          fVar13 = (float10)func_0x009c1b40();
          fVar3 = 1.0 / (float)fVar13;
          *(float *)(pSVar11 + 0xc) = fVar3 * *(float *)(pSVar11 + 0xc);
          *(float *)(pSVar11 + 0x10) = *(float *)(pSVar11 + 0x10) * fVar3;
          *(float *)(pSVar11 + 0x14) = fVar3 * *(float *)(pSVar11 + 0x14);
        }
        fVar3 = *(float *)(local_5c + 0xac);
        *(float *)pSVar7 = fVar3 * *(float *)(pSVar7 + 0xc);
        *(float *)(pSVar7 + 4) = *(float *)(pSVar7 + 0x10) * fVar3;
        *(float *)(pSVar7 + 8) = fVar3 * *(float *)(pSVar7 + 0x14);
        *(float *)pSVar7 = *(float *)pSVar7 + *(float *)pSVar6;
        *(float *)(pSVar7 + 4) = *(float *)(pSVar7 + 4) + *(float *)(pSVar6 + 4);
        *(float *)(pSVar7 + 8) = *(float *)(pSVar7 + 8) + *(float *)(pSVar6 + 8);
        *(float *)(pSVar7 + 0x24) = (1.0 - *(float *)(local_5c + 200)) * *(float *)(pSVar6 + 0x24);
        local_4c = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(local_5c + 0xac);
        *(float *)pSVar11 = (float)local_4c * *(float *)(pSVar11 + 0xc);
        *(float *)(pSVar11 + 4) = *(float *)(pSVar11 + 0x10) * (float)local_4c;
        *(float *)(pSVar11 + 8) = (float)local_4c * *(float *)(pSVar11 + 0x14);
        *(float *)pSVar11 = *(float *)pSVar11 + *(float *)pSVar6;
        *(float *)(pSVar11 + 4) = *(float *)(pSVar11 + 4) + *(float *)(pSVar6 + 4);
        *(float *)(pSVar11 + 8) = *(float *)(pSVar11 + 8) + *(float *)(pSVar6 + 8);
        local_60 = local_60 + 2;
        *(float *)(pSVar11 + 0x24) = (1.0 - *(float *)(local_5c + 200)) * *(float *)(pSVar6 + 0x24);
        this = local_5c;
        pSVar11 = local_50;
        pCVar15 = pCVar5;
      } while (local_60 < pCVar5);
    }
    *(int *)(this + 300) = 1 - *(int *)(this + 300);
  }
  else {
    pCVar14 = pCVar5;
    __CItan();
    local_54 = (CFastBufferRef<class_CGameMobil> *)0x0;
    if (pCVar5 != (CSceneFxVisionK *)0x0) {
      do {
        pCVar5 = pCVar15;
        pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                  (local_54 + (1 - *(int *)(this + 300)));
        pSVar6 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                           (pSVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                    (local_54 + *(int *)(this + 300)),unaff_EBP);
        if (*(float *)(this + 0xbc) <= *(float *)(pSVar6 + 0x24)) {
          pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                             (pSVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)local_48,
                              (ulong)unaff_EBX);
          unaff_EBP = 0x80ef72;
          pSVar6 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                             (pSVar11,pCVar12,(ulong)in_stack_ffffff94);
          local_54 = (CFastBufferRef<class_CGameMobil> *)0x0;
          in_stack_ffffff94 = (GmMat3 *)0x80ef85;
          local_40 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     CFastBuffer<class_CCrystalFace*>::GetCount
                               (this + 0x134,(CFastBuffer<class_CCrystalFace*> *)pCVar14);
          *(undefined4 *)(pSVar6 + 0x20) = 0;
          *(undefined4 *)(pSVar6 + 0x1c) = 0;
          *(undefined4 *)(pSVar6 + 0x18) = 0;
          local_4c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          fStack_1c = 0.0;
          local_20 = 0.0;
          local_24 = 0.0;
          unaff_EBX = pCVar12;
          local_50 = (SCasterCat *)pCVar9;
          if (local_40 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            do {
              in_stack_ffffff94 = (GmMat3 *)0x80f159;
              pCVar14 = (CSceneFxVisionK *)local_4c;
              pSVar7 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                                 (this + 0x134,local_4c,(ulong)pCVar5);
              local_14 = *(float *)pSVar7 - *(float *)pSVar6;
              local_10 = *(float *)(pSVar7 + 4) - *(float *)(pSVar6 + 4);
              local_c = *(float *)(pSVar7 + 8) - *(float *)(pSVar6 + 8);
              local_38 = local_c * local_c + local_14 * local_14 + local_10 * local_10;
              pCVar5 = (CSceneFxVisionK *)0x80f1a0;
              fVar13 = (float10)func_0x009c1b40();
              fVar3 = 1.0 / ((float)fVar13 + (float)_DAT_00b30a18);
              local_3c = fVar3 * fVar3;
              local_24 = local_3c * local_18 + local_24;
              local_20 = local_14 * local_3c + local_20;
              fStack_1c = local_3c * local_10 + fStack_1c;
              local_18 = *(float *)(pSVar7 + 0xc) * fVar3;
              local_14 = *(float *)(pSVar7 + 0x10) * fVar3;
              local_10 = *(float *)(pSVar7 + 0x14) * fVar3;
              *(float *)(pSVar6 + 0x18) = local_18 + *(float *)(pSVar6 + 0x18);
              *(float *)(pSVar6 + 0x1c) = local_14 + *(float *)(pSVar6 + 0x1c);
              *(float *)(pSVar6 + 0x20) = *(float *)(pSVar6 + 0x20) + local_10;
              local_50 = (SCasterCat *)(fVar3 + (float)local_50);
              local_4c = local_4c + 1;
              pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)local_48;
              unaff_EBX = pCVar12;
            } while (local_4c < local_40);
          }
          fVar3 = 1.0 / (float)local_50;
          *(float *)(pSVar6 + 0x18) = fVar3 * *(float *)(pSVar6 + 0x18);
          *(float *)(pSVar6 + 0x1c) = *(float *)(pSVar6 + 0x1c) * fVar3;
          *(float *)(pSVar6 + 0x20) = *(float *)(pSVar6 + 0x20) * fVar3;
          local_24 = local_24 * fVar3;
          local_20 = local_20 * fVar3;
          fStack_1c = fVar3 * fStack_1c;
          *(float *)(pSVar6 + 0x24) = (1.0 - *(float *)(this + 0xb4)) * *(float *)(pCVar9 + 0x24);
          local_3c = fStack_1c * fStack_1c + local_20 * local_20 + local_24 * local_24;
          if (local_3c <= _DAT_00d0ca90) {
LAB_0080f26d:
            local_30 = *(float *)(pCVar9 + 0xc);
            local_2c = *(float *)(pCVar9 + 0x10);
            local_38 = *(float *)(pCVar9 + 0x14);
          }
          else {
            pCVar14 = (CSceneFxVisionK *)0x80f03c;
            fVar13 = (float10)func_0x009c1b40();
            fVar3 = 1.0 / (float)fVar13;
            local_24 = fVar3 * local_24;
            local_20 = local_20 * fVar3;
            fStack_1c = fVar3 * fStack_1c;
            fVar3 = *(float *)(this + 0xb8);
            local_30 = fVar3 * (local_24 - *(float *)(pCVar9 + 0xc)) + *(float *)(pCVar9 + 0xc);
            local_2c = *(float *)(pCVar9 + 0x10) + (local_20 - *(float *)(pCVar9 + 0x10)) * fVar3;
            local_28 = fVar3 * (fStack_1c - *(float *)(pCVar9 + 0x14)) + *(float *)(pCVar9 + 0x14);
            local_3c = local_2c * local_2c + local_30 * local_30 + local_28 * local_28;
            if (local_3c <= _DAT_00d0ca90) goto LAB_0080f26d;
            pCVar14 = (CSceneFxVisionK *)0x80f116;
            fVar13 = (float10)func_0x009c1b40();
            fVar3 = 1.0 / (float)fVar13;
            local_40 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(fVar3 * (float)local_40);
            local_3c = local_3c * fVar3;
            local_38 = fVar3 * local_38;
          }
          GmVec3_SetRandomDir((GmVec3 *)(pSVar6 + 0xc),(GmVec3 *)&local_40,
                              (float)(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)local_48);
          fVar3 = *(float *)(this + 0xac);
          *(float *)pSVar6 = fVar3 * *(float *)(pSVar6 + 0xc);
          *(float *)(pSVar6 + 4) = *(float *)(pSVar6 + 0x10) * fVar3;
          *(float *)(pSVar6 + 8) = fVar3 * *(float *)(pSVar6 + 0x14);
          *(float *)pSVar6 = *(float *)pSVar6 + *(float *)pCVar9;
          *(float *)(pSVar6 + 4) = *(float *)(pCVar9 + 4) + *(float *)(pSVar6 + 4);
          *(float *)(pSVar6 + 8) = *(float *)(pCVar9 + 8) + *(float *)(pSVar6 + 8);
        }
        else {
          unaff_EBP = 2;
          CFastBuffer<class_GxVertex>::ReplaceByLastAt(pSVar11,local_54,2,(ulong)unaff_EBX);
          local_54 = local_54 + -2;
        }
        local_54 = local_54 + 2;
        pCVar15 = pCVar5;
      } while (local_54 < pCVar5);
    }
    *(int *)(this + 300) = 1 - *(int *)(this + 300);
  }
  puVar2 = (uint *)(*(int *)(this + 0x118) + 0x9c);
  *puVar2 = *puVar2 ^ ((uint)(pCVar5 != (CSceneFxVisionK *)0x0) * 8 ^
                      *(uint *)(*(int *)(this + 0x118) + 0x9c)) & 8;
  iVar10 = _rand();
  local_48._0_4_ =
       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
       (longlong)ROUND((double)iVar10 * _DAT_00b3dca8 * _DAT_00b9d558 + _PTR_00b2c178);
  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x130) =
       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)local_48;
  return;
}
}

