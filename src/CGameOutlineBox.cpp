// Class implementation: CGameOutlineBox

// =================================================
// Function: CGameOutlineBox::CGameOutlineBox
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameOutlineBox::CGameOutlineBox(CGameOutlineBox *this,CGameOutlineBox *param_1)
{
{
  undefined4 uVar1;
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined4 *)(this + 0x1c) = _DAT_00b3618c;
  uVar1 = _DAT_00b41140;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x20) = uVar1;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x2c) = 1;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 1;
  *(undefined ***)this = vftable;
  return;
}
}

// =================================================
// Function: CGameOutlineBox::Init
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameOutlineBox::Init
          (CGameOutlineBox *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2,
          CVisionViewportDx9 *param_3,ESpriteColor0 *param_4)
{
{
  CPlugTree *pCVar1;
  CPlugTree *this_00;
  undefined4 extraout_EAX;
  CPlugVisualQuads *this_01;
  CVisionVisualKeeper *extraout_EAX_00;
  CPlugShaderApply *pCVar2;
  CPlugShaderGeneric *extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 uVar3;
  CPlugVisual *extraout_EAX_03;
  CPlugShaderGeneric *extraout_EAX_04;
  CVisionVisualKeeper *pCVar4;
  CPlugVisual *this_02;
  int unaff_EBP;
  CPlugTree *unaff_ESI;
  CPlugVisualQuads *unaff_EDI;
  CPlugShaderGeneric *pCVar5;
  int iVar6;
  GxColor *pGVar7;
  CPlugTree *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00aade92;
  local_c = ExceptionList;
  pCVar1 = (CPlugTree *)(DAT_00cca150 ^ (uint)&stack0xffffffd0);
  ExceptionList = &local_c;
  pCVar5 = (CPlugShaderGeneric *)0x0;
  local_18 = _DAT_00b3cd40;
  local_14 = _DAT_00b3cd3c;
  local_10 = 0x3f800000;
  if (*(int *)(this + 0x14) == 0) {
    this_00 = operator_new(0xac);
    local_4 = (void *)0x0;
    if (this_00 == (CPlugTree *)0x0) {
      uVar3 = 0;
    }
    else {
      CPlugTree::CPlugTree(this_00,pCVar1);
      uVar3 = extraout_EAX;
    }
    *(undefined4 *)(this + 0x14) = uVar3;
    this_01 = operator_new(0x98);
    if (this_01 == (CPlugVisualQuads *)0x0) {
      pCVar4 = (CVisionVisualKeeper *)0x0;
    }
    else {
      CPlugVisualQuads::CPlugVisualQuads(this_01,unaff_EDI);
      pCVar4 = extraout_EAX_00;
    }
    pCVar2 = operator_new(0xa8);
    if (pCVar2 != (CPlugShaderApply *)0x0) {
      CPlugShaderApply::CPlugShaderApply(pCVar2,(CPlugShaderApply *)unaff_EDI);
      pCVar5 = extraout_EAX_01;
    }
    CPlugShaderGeneric::SetVertexColor
              (pCVar5,(CPlugShaderGeneric *)0x0,(EPlugShaderVertexColor)&local_18,
               (GxColor *)unaff_EDI);
    CPlugShader::SetReceiverShadowGroupMask
              ((CPlugShader *)pCVar5,(CPlugShader *)0x0,(ulong)unaff_ESI);
    CHmsItem::SetIsForcePointDynamicCollisionResponse((CHmsItem *)pCVar5,(CHmsItem *)0x0,unaff_EBP);
    unaff_EBP = 0;
    unaff_ESI = (CPlugTree *)0x0;
    CPlugTree::SetVisual(*(CPlugTree **)(this + 0x14),pCVar4,(CPlugVisual *)pCVar5);
    *(uint *)(*(int *)(this + 0x14) + 0x9c) = *(uint *)(*(int *)(this + 0x14) + 0x9c) | 0x4000;
  }
  if (*(int *)(this + 0x18) == 0) {
    local_18 = operator_new(0xac);
    if (local_18 == (CPlugTree *)0x0) {
      uVar3 = 0;
    }
    else {
      CPlugTree::CPlugTree(local_18,unaff_ESI);
      uVar3 = extraout_EAX_02;
    }
    pGVar7 = (GxColor *)&DAT_00000098;
    *(undefined4 *)(this + 0x18) = uVar3;
    iVar6 = 0x65b086;
    local_18 = operator_new(0x98);
    if (local_18 == (CPlugTree *)0x0) {
      this_02 = (CPlugVisual *)0x0;
    }
    else {
      pGVar7 = (GxColor *)0x65b0a0;
      CPlugVisualLines::CPlugVisualLines((CPlugVisualLines *)local_18,(CPlugVisualLines *)unaff_ESI)
      ;
      this_02 = extraout_EAX_03;
    }
    local_4 = (void *)0xffffffff;
    CPlugVisual::EnableVertexColor(this_02,(CPlugVisual *)0x1,iVar6);
    pCVar2 = operator_new(0xa8);
    if (pCVar2 == (CPlugShaderApply *)0x0) {
      pCVar5 = (CPlugShaderGeneric *)0x0;
    }
    else {
      CPlugShaderApply::CPlugShaderApply(pCVar2,(CPlugShaderApply *)pGVar7);
      pCVar5 = extraout_EAX_04;
    }
    CPlugShaderGeneric::SetVertexColor(pCVar5,(CPlugShaderGeneric *)0x1,0,pGVar7);
    CPlugShader::SetReceiverShadowGroupMask
              ((CPlugShader *)pCVar5,(CPlugShader *)0x0,(ulong)unaff_ESI);
    CHmsItem::SetIsForcePointDynamicCollisionResponse((CHmsItem *)pCVar5,(CHmsItem *)0x0,unaff_EBP);
    *(uint *)(*(int *)(this + 0x18) + 0x9c) = *(uint *)(*(int *)(this + 0x18) + 0x9c) & 0xffffbfff;
    CPlugTree::SetVisual
              (*(CPlugTree **)(this + 0x18),(CVisionVisualKeeper *)this_02,(CPlugVisual *)pCVar5);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CGameOutlineBox::UpdateBox
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __thiscall
CGameOutlineBox::UpdateBox
          (CGameOutlineBox *this,CGameOutlineBox *param_1,CFastBuffer<int> *param_2,GmNat3 *param_3)
{
{
  uint *puVar1;
  CPlugShaderGeneric *this_00;
  CPlugVisual *pCVar2;
  CPlugShaderGeneric *this_01;
  CGameOutlineBox *pCVar3;
  byte bVar4;
  void *this_02;
  GmNat3 *pGVar5;
  CFastBuffer<class_CCrystalFace*> *pCVar6;
  SCasterCat *pSVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  SLoadedLight *pSVar9;
  int iVar10;
  float fVar11;
  SCasterCat *pSVar12;
  ulong uVar13;
  float *pfVar14;
  uint uVar15;
  int extraout_EDX;
  EGxBlendFactor unaff_EBX;
  uint uVar16;
  CFastBuffer<class_CCrystalFace*> *pCVar17;
  int unaff_EBP;
  uint uVar18;
  CGameOutlineBox *pCVar19;
  GmFrustumIso4 *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  CPlugVisual **ppCVar20;
  CGameOutlineBox *pCVar21;
  bool bVar22;
  float10 extraout_ST0;
  float10 fVar23;
  float10 extraout_ST1;
  float10 fVar24;
  void *in_stack_00000010;
  undefined4 in_stack_00000014;
  float fStack00000018;
  CFastBuffer<int> *in_stack_0000001c;
  void *in_stack_00000024;
  void *in_stack_00000028;
  GmNat3 *in_stack_0000002c;
  CPlugShaderPass *pCVar25;
  EGxBlendFactor in_stack_ffffff20;
  ulong uVar26;
  int in_stack_ffffff24;
  EGxBlendFactor in_stack_ffffff28;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar27;
  GxColor *pGVar28;
  EGxBlendFactor in_stack_ffffff2c;
  CGameOutlineBox *pCVar29;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffff30;
  CGameOutlineBox *pCVar30;
  GmBoxAligned *in_stack_ffffff38;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffff3c;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffff40;
  CGameOutlineBox *local_bc;
  void *local_b8;
  CGameOutlineBox *local_b4;
  CGameOutlineBox *local_b0;
  CPlugVisual *local_ac;
  CPlugVisual *local_a8;
  CPlugVisual *local_a4;
  float local_a0;
  float local_9c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_98;
  CFastBuffer<class_CCrystalFace*> *local_94;
  CGameOutlineBox *local_90;
  float local_8c;
  float local_88;
  CPlugVisual **local_84;
  CFastBuffer<class_CCrystalFace*> *local_80;
  CPlugVisual **local_7c;
  CPlugVisual *local_78;
  float local_74;
  CPlugVisual *local_70;
  float local_6c;
  CPlugVisual *local_68;
  float local_64;
  CPlugVisual *local_60;
  CPlugVisual *local_5c;
  float local_58;
  CPlugVisual *local_54;
  CPlugVisual *local_50;
  float local_4c;
  CPlugVisual *local_48;
  CPlugVisual *local_44;
  float local_40;
  CPlugVisual *local_3c;
  CPlugVisual *local_38;
  float local_34;
  undefined4 local_30;
  CPlugVisual *local_2c;
  void *local_28;
  CPlugVisual *local_24;
  CPlugVisual *local_20;
  float local_1c;
  float local_18;
  CPlugVisualLines *local_14;
  void *local_10;
  CPlugVisual *local_c;
  float local_8;
  CPlugVisual *local_4;
  
  local_8 = *(float *)(*(int *)(this + 0x14) + 0x90);
  this_00 = *(CPlugShaderGeneric **)(*(int *)(this + 0x14) + 0x94);
  pCVar2 = *(CPlugVisual **)(*(int *)(this + 0x18) + 0x90);
  this_01 = *(CPlugShaderGeneric **)(*(int *)(this + 0x18) + 0x94);
  local_28 = (void *)((int)local_8 + 0x78);
  pCVar30 = this;
  local_2c = pCVar2;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(local_28,unaff_EDI);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(pCVar2 + 0x78,unaff_ESI);
  CPlugShaderGeneric::SetEmissive
            (this_00,(CPlugShaderGeneric *)0x1,(int)(this + 0x30),(GmVec3 *)0x0,unaff_EBP);
  if ((float)_DAT_00b44a20 <= *(float *)(this + 0x3c)) {
    pCVar25 = (CPlugShaderPass *)0x2;
  }
  else {
    pCVar25 = (CPlugShaderPass *)0x1;
  }
  CPlugShaderApply::SetBlending((CPlugShaderApply *)this_00,pCVar25,unaff_EBX,in_stack_ffffff20);
  CPlugShaderGeneric::SetEmissive
            (this_01,(CPlugShaderGeneric *)0x1,(int)(this + 0x30),(GmVec3 *)0x1,in_stack_ffffff24);
  if ((float)_DAT_00b44a20 <= *(float *)(this + 0x3c)) {
    pCVar25 = (CPlugShaderPass *)0x2;
  }
  else {
    pCVar25 = (CPlugShaderPass *)0x0;
  }
  CPlugShaderApply::SetBlending
            ((CPlugShaderApply *)this_01,pCVar25,in_stack_ffffff28,in_stack_ffffff2c);
  pCVar6 = (CFastBuffer<class_CCrystalFace*> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(in_stack_00000024,in_stack_ffffff30);
  pGVar5 = in_stack_0000002c;
  local_94 = (CFastBuffer<class_CCrystalFace*> *)0x0;
  local_80 = pCVar6;
  if (pCVar6 != (CFastBuffer<class_CCrystalFace*> *)0x0) {
    do {
      pCVar17 = local_94;
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (in_stack_00000028,
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)local_94,(ulong)pCVar30)
      ;
      if (*(int *)pSVar7 != 0) {
        pCVar30 = *(CGameOutlineBox **)(pGVar5 + 8);
        GetCoordFromIndex(this,(CGameOutlineBox *)&local_b8,(ulong)pCVar17,
                          SUB41(*(undefined4 *)pGVar5,0));
        uVar18 = 0;
        do {
          uVar16 = 0;
          do {
            param_3 = (GmNat3 *)local_bc;
            in_stack_00000010 = local_b8;
            pCVar27 = *(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> **)pGVar5;
            in_stack_00000014 = local_b4;
            (&param_3)[uVar18] = (&param_3)[uVar18] + (uint)(uVar16 != 0) * 2 + -1;
            pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     GetIndexFromCoord(this,(CGameOutlineBox *)param_3,SUB41(in_stack_00000010,0),
                                       SUB41(in_stack_00000014,0));
            if (uVar16 == 0) {
              bVar22 = *(int *)(&stack0xffffff38 + uVar18 * 4) == 0;
LAB_0065b30b:
              if (!bVar22) goto LAB_0065b30d;
LAB_0065b323:
              local_44 = (CPlugVisual *)(float)(int)in_stack_ffffff38;
              if ((int)in_stack_ffffff38 < 0) {
                local_44 = (CPlugVisual *)((float)local_44 + _DAT_00c418d0);
              }
              local_40 = (float)(int)in_stack_ffffff3c;
              if ((int)in_stack_ffffff3c < 0) {
                local_40 = local_40 + _DAT_00c418d0;
              }
              local_3c = (CPlugVisual *)(float)(int)in_stack_ffffff40;
              if ((int)in_stack_ffffff40 < 0) {
                local_3c = (CPlugVisual *)((float)local_3c + _DAT_00c418d0);
              }
              local_9c = (float)(uint)(uVar16 != 0);
              uVar15 = (uVar18 + 1) % 3;
              (&local_44)[uVar18] =
                   (CPlugVisual *)((float)(int)local_9c + (float)(&local_44)[uVar18]);
              local_44 = (CPlugVisual *)((float)_DAT_00ce9474 * (float)local_44);
              local_40 = _DAT_00ce9478 * local_40;
              local_3c = (CPlugVisual *)((float)_DAT_00ce9474 * (float)local_3c);
              local_78 = _DAT_00ce9474;
              local_70 = _DAT_00ce9474;
              local_74 = _DAT_00ce9478;
              (&local_78)[uVar18] = (CPlugVisual *)0x0;
              local_c = local_78;
              local_8 = local_74;
              local_4 = local_70;
              local_60 = local_70;
              local_68 = local_78;
              local_64 = local_74;
              if (uVar16 == 0) {
                (&local_c)[uVar15] = (CPlugVisual *)0x0;
                (&local_68)[(uVar18 + 2) % 3] = (CPlugVisual *)0x0;
              }
              else {
                (&local_68)[uVar15] = (CPlugVisual *)0x0;
                (&local_c)[(uVar18 + 2) % 3] = (CPlugVisual *)0x0;
              }
              local_38 = (CPlugVisual *)((float)local_44 + (float)local_c);
              local_34 = local_40 + local_8;
              local_30 = (CPlugVisual *)((float)local_3c + (float)local_4);
              local_2c = (CPlugVisual *)((float)local_68 + (float)local_44);
              local_28 = (void *)(local_64 + local_40);
              local_24 = (CPlugVisual *)((float)local_60 + (float)local_3c);
              local_20 = (CPlugVisual *)((float)local_78 + (float)local_44);
              local_1c = local_40 + local_74;
              local_18 = (float)local_3c + (float)local_70;
              local_90 = (CGameOutlineBox *)0x0;
              local_94 = (CFastBuffer<class_CCrystalFace*> *)0x0;
              local_98 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
              pCVar8 = _DAT_00b2c060;
              if (uVar16 != 0) {
                pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
              }
              ppCVar20 = &local_3c;
              local_bc = (CGameOutlineBox *)&DAT_00000004;
              (&local_98)[uVar18] = pCVar8;
              do {
                pSVar9 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem(local_10,pCVar27);
                local_ac = ppCVar20[-2];
                local_a8 = ppCVar20[-1];
                local_a4 = *ppCVar20;
                if ((float)local_a8 < _DAT_00b773a0) {
                  local_a8 = (CPlugVisual *)
                             ((float)local_a8 - (float)*(CPlugVisual **)(local_b0 + 0x24));
                }
                *(CPlugVisual **)pSVar9 = local_ac;
                ppCVar20 = ppCVar20 + 3;
                local_b8 = (void *)((int)local_b8 + -1);
                *(CPlugVisual **)(pSVar9 + 4) = local_a8;
                *(CPlugVisual **)(pSVar9 + 8) = local_a4;
                *(CFastBuffer<class_CCrystalFace*> **)(pSVar9 + 0xc) = local_94;
                *(CGameOutlineBox **)(pSVar9 + 0x10) = local_90;
                *(float *)(pSVar9 + 0x14) = local_8c;
                *(CPlugVisual **)(pSVar9 + 0x18) = *(CPlugVisual **)(local_b0 + 0x30);
                *(CPlugVisual **)(pSVar9 + 0x1c) = *(CPlugVisual **)(local_b0 + 0x34);
                *(CPlugVisual **)(pSVar9 + 0x20) = *(CPlugVisual **)(local_b0 + 0x38);
                *(CPlugVisual **)(pSVar9 + 0x24) = *(CPlugVisual **)(local_b0 + 0x3c);
                this = local_b0;
              } while (local_b8 != (void *)0x0);
            }
            else {
              if (uVar16 == 1) {
                bVar22 = *(int *)(&stack0xffffff38 + uVar18 * 4) ==
                         *(int *)(pGVar5 + uVar18 * 4) + -1;
                goto LAB_0065b30b;
              }
LAB_0065b30d:
              pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (in_stack_0000001c,pCVar8,(ulong)pCVar27);
              if (*(int *)pSVar7 == 0) goto LAB_0065b323;
            }
            uVar16 = uVar16 + 1;
          } while (uVar16 < 2);
          uVar18 = uVar18 + 1;
          pCVar17 = local_94;
          pCVar6 = local_80;
        } while (uVar18 < 3);
      }
      local_94 = pCVar17 + 1;
    } while (local_94 < pCVar6);
  }
  local_bc = (CGameOutlineBox *)0x0;
  pCVar29 = local_90;
  do {
    local_90 = pCVar29;
    fStack00000018 = (float)(int)local_bc;
    local_b8 = (void *)0x0;
    pCVar29 = local_90;
    if ((int)local_bc < 0) {
      fStack00000018 = fStack00000018 + _DAT_00c418d0;
    }
    do {
      local_90 = pCVar29;
      local_ac = (CPlugVisual *)(float)(int)local_b8;
      local_b4 = (CGameOutlineBox *)0x0;
      pCVar29 = local_90;
      if ((int)local_b8 < 0) {
        local_ac = (CPlugVisual *)((float)local_ac + _DAT_00c418d0);
      }
      do {
        local_90 = pCVar29;
        pGVar28 = *(GxColor **)pGVar5;
        pCVar29 = *(CGameOutlineBox **)(pGVar5 + 4);
        uVar18 = *(uint *)(pGVar5 + 8);
        local_8c = (float)GetIndexFromCoord((CGameOutlineBox *)local_a8,local_bc,SUB41(local_b8,0),
                                            SUB41(local_b4,0));
        local_44 = (CPlugVisual *)((float)_DAT_00ce9474 * (float)param_3);
        local_40 = _DAT_00ce9478 * (float)local_b8;
        fVar11 = (float)extraout_EDX;
        if (extraout_EDX < 0) {
          fVar11 = fVar11 + _DAT_00c418d0;
        }
        local_3c = (CPlugVisual *)(fVar11 * (float)_DAT_00ce9474);
        local_38 = (CPlugVisual *)((float)_DAT_00ce9474 + (float)local_44);
        local_28 = (void *)(local_40 + _DAT_00ce9478);
        local_18 = (float)local_3c + (float)_DAT_00ce9474;
        local_34 = local_40;
        local_30 = local_3c;
        local_2c = local_44;
        local_24 = local_3c;
        local_20 = local_44;
        local_1c = local_40;
        iVar10 = `public:_void___thiscall_CGameOutlineBox::
                 UpdateBox(class_CFastBuffer<int>_const&,class_GmNat3_const&)'::__l35::SLocal::
                 IsValidCoord((GmNat3 *)&stack0xffffff38,pGVar5);
        if (iVar10 == 0) {
          local_78 = (CPlugVisual *)0x0;
        }
        else {
          local_78 = (CPlugVisual *)
                     `public:_void___thiscall_CGameOutlineBox::
                     UpdateBox(class_CFastBuffer<int>_const&,class_GmNat3_const&)'::__l35::SLocal::
                     IsFilledCoord((GmNat3 *)&stack0xffffff38,pGVar5,in_stack_0000001c);
        }
        local_7c = &local_5c;
        local_bc = (CGameOutlineBox *)&local_30;
        local_a0 = 2.8026e-45;
        local_9c = 4.2039e-45;
        do {
          local_58 = -NAN;
          local_54 = (CPlugVisual *)0xffffffff;
          local_5c = (CPlugVisual *)0xffffffff;
          *local_7c = (CPlugVisual *)0x0;
          local_60 = local_54;
          local_48 = local_54;
          local_68 = local_5c;
          local_64 = local_58;
          local_50 = local_5c;
          local_4c = local_58;
          local_88 = 0.0;
          local_80 = (CFastBuffer<class_CCrystalFace*> *)0x0;
          (&local_68)[((int)local_a0 - 1U) % 3] = (CPlugVisual *)0x0;
          (&local_50)[(uint)local_a0 % 3] = (CPlugVisual *)0x0;
          local_84 = &local_60;
          do {
            pCVar21 = (CGameOutlineBox *)(in_stack_ffffff38 + (int)local_84[-2]);
            pCVar6 = in_stack_ffffff3c + (int)local_84[-1];
            pCVar19 = (CGameOutlineBox *)(in_stack_ffffff40 + (int)*local_84);
            local_98 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar21;
            local_94 = pCVar6;
            local_90 = pCVar19;
            iVar10 = `public:_void___thiscall_CGameOutlineBox::
                     UpdateBox(class_CFastBuffer<int>_const&,class_GmNat3_const&)'::__l35::SLocal::
                     IsValidCoord((GmNat3 *)&local_98,pGVar5);
            if (iVar10 == 0) {
              fVar11 = 0.0;
            }
            else {
              fVar11 = (float)`public:_void___thiscall_CGameOutlineBox::
                              UpdateBox(class_CFastBuffer<int>_const&,class_GmNat3_const&)'::__l35::
                              SLocal::IsFilledCoord((GmNat3 *)&local_98,pGVar5,in_stack_0000001c);
            }
            uVar13 = *(ulong *)pGVar5;
            (&local_74)[(int)local_80] = fVar11;
            uVar26 = *(ulong *)(pGVar5 + 4);
            pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     GetIndexFromCoord(local_b4,pCVar21,SUB41(pCVar6,0),SUB41(pCVar19,0));
            this_02 = in_stack_00000010;
            pCVar3 = *(CGameOutlineBox **)pGVar5;
            if (((pCVar29 < pCVar3) && (uVar18 < *(uint *)(pGVar5 + 4))) &&
               (pCVar30 < *(CGameOutlineBox **)(pGVar5 + 8))) {
              if (((pCVar21 < pCVar3) &&
                  (pCVar6 < *(CFastBuffer<class_CCrystalFace*> **)(pGVar5 + 4))) &&
                 (pCVar19 < *(CGameOutlineBox **)(pGVar5 + 8))) {
                pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (in_stack_00000010,pCVar8,uVar13);
                pSVar12 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                    (this_02,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                             local_94,uVar26);
                bVar22 = *(int *)pSVar12 == *(int *)pSVar7;
              }
              else {
                pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (in_stack_00000010,local_98,uVar13);
                bVar22 = *(int *)pSVar7 == 0;
              }
LAB_0065b8e2:
              fVar23 = (float10)1;
              fVar24 = (float10)0;
              if (!bVar22) {
                local_90 = (CGameOutlineBox *)0x1;
              }
            }
            else {
              fVar23 = extraout_ST0;
              fVar24 = extraout_ST1;
              if (((pCVar21 < pCVar3) &&
                  (pCVar6 < *(CFastBuffer<class_CCrystalFace*> **)(pGVar5 + 4))) &&
                 (pCVar19 < *(CGameOutlineBox **)(pGVar5 + 8))) {
                pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (in_stack_00000010,pCVar8,uVar13);
                bVar22 = *(int *)pSVar7 == 0;
                goto LAB_0065b8e2;
              }
            }
            local_84 = local_84 + 3;
            local_80 = local_80 + 1;
          } while (local_80 < (CFastBuffer<class_CCrystalFace*> *)0x3);
          if (local_88 != 0.0) {
            bVar22 = false;
            if ((local_78 == local_70) || (local_74 == local_6c)) {
              bVar22 = true;
              local_b0 = (CGameOutlineBox *)
                         (*(float *)(local_b4 + 0x1c) * *(float *)(local_b4 + 0x30));
              local_ac = (CPlugVisual *)(*(float *)(local_b4 + 0x34) * *(float *)(local_b4 + 0x1c));
              local_a8 = (CPlugVisual *)(*(float *)(local_b4 + 0x38) * *(float *)(local_b4 + 0x1c));
            }
            else {
              local_b0 = (CGameOutlineBox *)
                         (*(float *)(local_b4 + 0x20) * *(float *)(local_b4 + 0x30));
              local_ac = (CPlugVisual *)(*(float *)(local_b4 + 0x34) * *(float *)(local_b4 + 0x20));
              local_a8 = (CPlugVisual *)(*(float *)(local_b4 + 0x38) * *(float *)(local_b4 + 0x20));
            }
            if ((float10)(float)local_b0 <= fVar23) {
              if ((float10)(float)local_b0 < fVar24) {
                local_b0 = (CGameOutlineBox *)(float)fVar24;
              }
            }
            else {
              local_b0 = (CGameOutlineBox *)(float)fVar23;
            }
            if ((float10)(float)local_ac <= fVar23) {
              if ((float10)(float)local_ac < fVar24) {
                local_ac = (CPlugVisual *)(float)fVar24;
              }
            }
            else {
              local_ac = (CPlugVisual *)(float)fVar23;
            }
            if ((float10)(float)local_a8 <= fVar23) {
              if ((float10)(float)local_a8 < fVar24) {
                local_a8 = (CPlugVisual *)(float)fVar24;
              }
            }
            else {
              local_a8 = (CPlugVisual *)(float)fVar23;
            }
            local_68 = local_44;
            pfVar14 = &local_64;
            iVar10 = 2;
            local_64 = local_40;
            local_60 = local_3c;
            local_5c = local_38;
            local_58 = local_34;
            local_54 = local_30;
            do {
              if (*pfVar14 < _DAT_00b773a0) {
                *pfVar14 = *pfVar14 - *(float *)(local_b4 + 0x24);
              }
              pfVar14 = pfVar14 + 3;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
            if (bVar22) {
              CPlugVisualLines::AddLine
                        (local_14,(CPlugVisualLines2D *)&local_68,(GmVec2 *)&local_5c,
                         (GmVec2 *)&local_b0,pGVar28);
              fVar24 = (float10)0;
            }
          }
          local_70 = local_70 + 4;
          local_94 = local_94 + 1;
          local_b0 = (CGameOutlineBox *)&local_24;
          local_90 = local_90 + -1;
        } while (local_90 != (CGameOutlineBox *)0x0);
        local_b4 = local_b4 + 1;
        pCVar29 = (CGameOutlineBox *)0x0;
      } while (local_b4 <= *(CGameOutlineBox **)(pGVar5 + 8));
      local_b8 = (void *)((int)local_b8 + 1);
    } while (local_b8 <= (uint)*(float *)(pGVar5 + 4));
    local_bc = (CGameOutlineBox *)((int)&local_30 + 1);
    if (*(CGameOutlineBox **)pGVar5 < local_bc) {
      local_8c = (float)*(int *)pGVar5;
      if (*(int *)pGVar5 < 0) {
        local_8c = local_8c + _DAT_00c418d0;
      }
      local_8c = (float)_DAT_00ce9474 * local_8c;
      local_88 = (float)*(int *)(pGVar5 + 4);
      if (*(int *)(pGVar5 + 4) < 0) {
        local_88 = local_88 + _DAT_00c418d0;
      }
      local_88 = local_88 * _DAT_00ce9478;
      fVar11 = (float)*(int *)(pGVar5 + 8);
      if (*(int *)(pGVar5 + 8) < 0) {
        fVar11 = fVar11 + _DAT_00c418d0;
      }
      local_84 = (CPlugVisual **)(fVar11 * (float)_DAT_00ce9474);
      local_a4 = (CPlugVisual *)(float)fVar24;
      local_a0 = (float)fVar24;
      local_9c = (float)fVar24;
      CPlugVisual::SetBoundingMinMax
                ((CPlugVisual *)in_stack_0000001c,(CPlugVisual *)&local_a4,(GmVec3 *)&local_8c,
                 (GmVec3 *)pCVar30);
      CPlugVisual::SetBoundingBox
                (local_4,(CPlugVisual *)(in_stack_0000001c + 0x34),in_stack_ffffff38);
      uVar13 = CFastBuffer<class_CCrystalFace*>::GetCount(param_1,in_stack_ffffff3c);
      fVar11 = local_9c;
      if ((uVar13 == 0) || (*(int *)((int)local_9c + 0x2c) == 0)) {
        bVar4 = 0;
      }
      else {
        bVar4 = 1;
      }
      puVar1 = (uint *)(*(int *)((int)local_9c + 0x14) + 0x9c);
      *puVar1 = *puVar1 ^ ((uint)bVar4 * 8 ^ *(uint *)(*(int *)((int)local_9c + 0x14) + 0x9c)) & 8;
      uVar13 = CFastBuffer<class_CCrystalFace*>::GetCount(in_stack_0000002c,in_stack_ffffff40);
      if ((uVar13 == 0) || (*(int *)((int)fVar11 + 0x28) == 0)) {
        bVar4 = 0;
      }
      else {
        bVar4 = 1;
      }
      iVar10 = *(int *)((int)fVar11 + 0x18);
      puVar1 = (uint *)(iVar10 + 0x9c);
      *puVar1 = *puVar1 ^ ((uint)bVar4 * 8 ^ *(uint *)(iVar10 + 0x9c)) & 8;
      return;
    }
  } while( true );
}
}

