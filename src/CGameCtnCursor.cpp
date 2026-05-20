// Class implementation: CGameCtnCursor

// =================================================
// Function: CGameCtnCursor::AddBlocksToCursor
// =================================================
void __thiscall
CGameCtnCursor::AddBlocksToCursor
          (CGameCtnCursor *this,CGameCtnCursor *param_1,CGameCtnBlockInfo *param_2,int param_3,
          ulong param_4)
{
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  CGameCtnCursor *this_00;
  CGameCtnBlockInfo *pCVar6;
  CGameCtnBlockUnitInfo *pCVar7;
  SCasterCat *pSVar8;
  ulong uVar9;
  CPlugTree *pCVar10;
  uchar *unaff_EBX;
  CGameCtnBlockInfo *pCVar11;
  ulong unaff_EBP;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  uint uVar12;
  CGameCtnBlockInfo *pCVar13;
  int unaff_EDI;
  CGameCtnBlockInfo *in_stack_00000014;
  CGameCtnBlockInfo *in_stack_00000018;
  CGameCtnBlockInfo *pCStack0000001c;
  CGameCtnBlockInfo *in_stack_00000020;
  CGameCtnBlockInfo *pCVar14;
  ulong in_stack_ffffffd0;
  SVolatileTreePointer *in_stack_ffffffd4;
  CGameCtnBlockInfo *local_24;
  CGameCtnCursor *local_20;
  uint local_1c;
  undefined1 local_18 [4];
  int local_14;
  int local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00aae238;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((param_1 != (CGameCtnCursor *)0x0) &&
     (pCVar6 = (CGameCtnBlockInfo *)
               CGameCtnBlockInfo::GetNbBlockUnitInfos
                         ((CGameCtnBlockInfo *)param_1,param_2,DAT_00cca150 ^ (uint)&stack0xffffffbc
                         ), pCVar6 != (CGameCtnBlockInfo *)0x0)) {
    pCVar14 = param_2;
    pCVar7 = CGameCtnBlockInfo::GetBlockUnitInfo
                       ((CGameCtnBlockInfo *)param_1,(CGameCtnBlockInfo *)0x0,(ulong)param_2,
                        unaff_EDI);
    local_24 = *(CGameCtnBlockInfo **)(pCVar7 + 0x2c);
    local_20 = *(CGameCtnCursor **)(pCVar7 + 0x30);
    pCVar11 = (CGameCtnBlockInfo *)0x1;
    pCVar13 = *(CGameCtnBlockInfo **)(pCVar7 + 0x28);
    uVar12 = (uint)local_20;
    if (1 < param_4) {
      do {
        pCVar14 = pCVar11;
        pCVar7 = CGameCtnBlockInfo::GetBlockUnitInfo(pCVar6,pCVar11,(ulong)param_2,(int)unaff_ESI);
        if (local_24 < *(CGameCtnBlockInfo **)(pCVar7 + 0x28)) {
          local_24 = *(CGameCtnBlockInfo **)(pCVar7 + 0x28);
        }
        if (local_20 < *(uint *)(pCVar7 + 0x2c)) {
          local_20 = (CGameCtnCursor *)*(uint *)(pCVar7 + 0x2c);
        }
        if (local_1c < *(uint *)(pCVar7 + 0x30)) {
          local_1c = *(uint *)(pCVar7 + 0x30);
        }
        pCVar11 = pCVar11 + 1;
        pCVar13 = local_24;
        uVar12 = local_1c;
      } while (pCVar11 < in_stack_00000014);
    }
    local_24 = in_stack_00000014 + (int)(local_24 + 1);
    local_20 = (CGameCtnCursor *)(uVar12 + 1);
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(&local_1c,unaff_ESI);
    CFastBuffer<class_GmVector2<unsigned_short>_>::AllocSetCount
              (local_18,(CFastBuffer<class_GxVertex2> *)
                        ((int)(uVar12 + 1) * (int)(pCVar13 + 1) * (int)local_20),unaff_EBP);
    pCVar13 = (CGameCtnBlockInfo *)0x0;
    pCStack0000001c = (CGameCtnBlockInfo *)0x0;
    CFastBuffer<int>::FillWith
              (&local_14,(CFixedArray<unsigned_char,8,unsigned_long> *)&stack0x0000001c,unaff_EBX);
    pCVar6 = pCStack0000001c;
    if (pCStack0000001c != (CGameCtnBlockInfo *)0x0) {
      do {
        pCVar7 = CGameCtnBlockInfo::GetBlockUnitInfo
                           (in_stack_00000018,pCVar13,(ulong)param_2,(int)this);
        this = (CGameCtnCursor *)
               ((int)(in_stack_00000014 +
                     *(int *)(pCVar7 + 0x28) * local_14 + *(int *)(pCVar7 + 0x2c)) * local_10 +
               *(int *)(pCVar7 + 0x30));
        pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (&local_c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)this,
                            in_stack_ffffffd0);
        pCVar13 = pCVar13 + 1;
        *(undefined4 *)pSVar8 = 1;
      } while (pCVar13 < pCVar6);
    }
    if (in_stack_00000014 != (CGameCtnBlockInfo *)0x0) {
      pCVar6 = *(CGameCtnBlockInfo **)(in_stack_00000018 + 0x10c);
      pCVar13 = (CGameCtnBlockInfo *)0x0;
      in_stack_00000020 = (CGameCtnBlockInfo *)0x0;
      pCStack0000001c = pCVar6;
      uVar9 = CGameCtnBlockInfo::GetNbBlockUnitInfos(pCVar6,param_2,(int)this);
      if (uVar9 != 0) {
        do {
          pCVar11 = param_2;
          pCVar7 = CGameCtnBlockInfo::GetBlockUnitInfo(pCVar6,pCVar13,(ulong)param_2,(int)this);
          if (pCVar7 != (CGameCtnBlockUnitInfo *)0x0) {
            iVar1 = *(int *)(pCVar7 + 0x28);
            iVar2 = *(int *)(pCVar7 + 0x30);
            pCVar13 = (CGameCtnBlockInfo *)0x0;
            pCVar6 = in_stack_00000020;
            if (in_stack_00000014 != (CGameCtnBlockInfo *)0x0) {
              do {
                this = (CGameCtnCursor *)((int)(pCVar13 + iVar1 * local_14) * local_10 + iVar2);
                pCVar11 = (CGameCtnBlockInfo *)0x660014;
                pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (&local_c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)this,
                                    in_stack_ffffffd0);
                pCVar13 = pCVar13 + 1;
                *(undefined4 *)pSVar8 = 1;
                pCVar6 = in_stack_00000020;
              } while (pCVar13 < in_stack_00000014);
            }
          }
          pCVar13 = pCStack0000001c + 1;
          pCStack0000001c = pCVar13;
          pCVar11 = (CGameCtnBlockInfo *)
                    CGameCtnBlockInfo::GetNbBlockUnitInfos(pCVar6,param_2,(int)pCVar11);
        } while (pCVar13 < pCVar11);
      }
    }
    this_00 = local_20;
    iVar1 = *(int *)(local_20 + 0x50);
    uVar3 = *(undefined4 *)(local_20 + 0x30);
    uVar4 = *(undefined4 *)(local_20 + 0x34);
    uVar5 = *(undefined4 *)(local_20 + 0x38);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(local_20 + 0x2c);
    *(undefined4 *)(iVar1 + 0x34) = uVar3;
    *(undefined4 *)(iVar1 + 0x38) = uVar4;
    *(undefined4 *)(iVar1 + 0x3c) = uVar5;
    CGameOutlineBox::UpdateBox
              (*(CGameOutlineBox **)(local_20 + 0x50),(CGameOutlineBox *)&local_10,
               (CFastBuffer<int> *)&local_1c,(GmNat3 *)this);
    UpdateShadow(this_00,(CGameCtnCursor *)pCStack0000001c,param_2,in_stack_ffffffd0);
    pCVar10 = CSceneMobil::GetTree(*(CSceneMobil **)(this_00 + 0x44),in_stack_ffffffd4);
    (**(code **)(*(int *)pCVar10 + 0xbc))();
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (&local_24,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar14);
  }
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CGameCtnCursor::CGameCtnCursor
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameCtnCursor::CGameCtnCursor(CGameCtnCursor *this,CGameCtnCursor *param_1)
{
{
  uint *puVar1;
  float fVar2;
  CGameOutlineBox *pCVar3;
  float fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  CSceneMobil *pCVar7;
  CMwNod *extraout_EAX;
  CPlugTree *pCVar8;
  CPlugSolid *extraout_EAX_00;
  CMwNod *extraout_EAX_01;
  CPlugSolid *extraout_EAX_02;
  CSceneMobil *this_00;
  CMwNod *extraout_EAX_03;
  CPlugTree *pCVar9;
  CPlugSolid *extraout_EAX_04;
  CPlugSolid *pCVar10;
  CPlugVisualLines *this_01;
  CPlugVisual *extraout_EAX_05;
  CPlugShaderApply *this_02;
  CPlugShaderGeneric *extraout_EAX_06;
  int extraout_EAX_07;
  int iVar11;
  CGameOutlineBox *pCVar12;
  CGameOutlineBox *extraout_EAX_08;
  int unaff_EBX;
  CMwNod *unaff_EBP;
  CSceneMobil *unaff_ESI;
  CPlugShaderGeneric *this_03;
  CMwNod *unaff_EDI;
  CMwNod *pCVar13;
  CPlugVisual *this_04;
  int unaff_retaddr;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  CPlugTree *in_stack_0000001c;
  GxColor *in_stack_00000028;
  ulong in_stack_0000002c;
  int in_stack_00000030;
  EGxBlendFactor in_stack_00000034;
  int iVar14;
  CPlugVisualSprite *pCVar15;
  CVisionViewportDx9 *pCVar16;
  ESpriteColor0 *pEVar17;
  SVolatileTreePointer *in_stack_00000050;
  CPlugTree *in_stack_00000054;
  undefined1 uStack00000070;
  undefined1 uStack00000074;
  void *in_stack_00000084;
  CGameCtnCursor *pCVar18;
  int in_stack_ffffffe0;
  int in_stack_ffffffe4;
  CSceneMobil *in_stack_fffffff0;
  undefined1 *puVar19;
  CHmsItem *pCVar20;
  
  pCVar20 = (CHmsItem *)0xffffffff;
  puVar19 = &LAB_00aae207;
  pCVar9 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar18 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffcc),unaff_EDI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  uVar5 = _DAT_00b3cd40;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x18) = 1;
  *(undefined4 *)(this + 0x20) = 1;
  *(undefined4 *)(this + 0x24) = 1;
  *(undefined4 *)(this + 0x28) = 1;
  *(undefined4 *)(this + 0xd8) = 1;
  *(undefined4 *)(this + 0xf4) = 1;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0xec) = 0xffffffff;
  *(undefined4 *)(this + 0xe0) = 0xffffffff;
  *(undefined4 *)(this + 0xe4) = 0xffffffff;
  *(undefined4 *)(this + 0xe8) = 0xffffffff;
  *(undefined4 *)(this + 0xf0) = 0;
  *(undefined4 *)(this + 0x58) = uVar5;
  uVar6 = _DAT_00b3cd3c;
  *(undefined4 *)(this + 0x5c) = _DAT_00b3cd3c;
  *(undefined4 *)(this + 0x60) = uVar5;
  *(undefined4 *)(this + 100) = 0x3f800000;
  *(undefined4 *)(this + 0x74) = 0x3f800000;
  *(undefined4 *)(this + 0x68) = uVar5;
  *(undefined4 *)(this + 0x6c) = uVar5;
  *(undefined4 *)(this + 0x70) = uVar6;
  *(undefined4 *)(this + 0x78) = uVar6;
  *(undefined4 *)(this + 0x7c) = uVar5;
  *(undefined4 *)(this + 0x80) = uVar5;
  *(undefined4 *)(this + 0x84) = 0x3f800000;
  *(undefined4 *)(this + 0x94) = 0x3f800000;
  *(undefined4 *)(this + 0x88) = uVar5;
  *(undefined4 *)(this + 0x8c) = uVar5;
  *(undefined4 *)(this + 0x90) = uVar5;
  *(undefined4 *)(this + 0x98) = uVar6;
  *(undefined4 *)(this + 0x9c) = uVar6;
  *(undefined4 *)(this + 0xa0) = uVar6;
  *(undefined4 *)(this + 0xa4) = 0x3f800000;
  *(undefined4 *)(this + 0xa8) = uVar6;
  *(undefined4 *)(this + 0xac) = 0;
  uVar5 = _DAT_00b50954;
  *(undefined4 *)(this + 0xb0) = _DAT_00b50954;
  *(undefined4 *)(this + 0xb4) = 0x3f800000;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xbc) = uVar6;
  *(undefined4 *)(this + 0xc0) = uVar5;
  *(undefined4 *)(this + 0xc4) = 0x3f800000;
  uVar5 = _DAT_00b31460;
  *(undefined4 *)(this + 200) = _DAT_00b31460;
  *(undefined4 *)(this + 0xd0) = uVar5;
  *(undefined4 *)(this + 0xcc) = uVar6;
  *(undefined4 *)(this + 0xd4) = 0x3f800000;
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(this + 0xb8);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(this + 0xbc);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(this + 0xc0);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(this + 0xc4);
  *(undefined4 *)(this + 0xdc) = 0xffffffff;
  pCVar7 = operator_new(0x48);
  if (pCVar7 == (CSceneMobil *)0x0) {
    pCVar13 = (CMwNod *)0x0;
  }
  else {
    CSceneMobil::CSceneMobil(pCVar7,unaff_ESI);
    pCVar13 = extraout_EAX;
  }
  if (pCVar13 != *(CMwNod **)(this + 0x40)) {
    if (pCVar13 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar13,unaff_EBP);
    }
    if (*(CMwNod **)(this + 0x40) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x40),unaff_EBP);
    }
    *(CMwNod **)(this + 0x40) = pCVar13;
  }
  pCVar8 = operator_new(0xac);
  if (pCVar8 == (CPlugTree *)0x0) {
    pCVar10 = (CPlugSolid *)0x0;
  }
  else {
    CPlugTree::CPlugTree(pCVar8,(CPlugTree *)unaff_EBP);
    pCVar10 = extraout_EAX_00;
  }
  CSceneMobil::SetTree(*(CSceneMobil **)(this + 0x40),pCVar10,(CPlugTree *)unaff_EBP,unaff_EBX);
  CHmsItem::PickDisable(*(CHmsItem **)(*(int *)(this + 0x40) + 0x28),(CHmsItem *)pCVar18);
  CHmsItem::SetLightEmitter
            (*(CHmsItem **)(*(int *)(this + 0x40) + 0x28),(CHmsItem *)0x1,in_stack_ffffffe0);
  CHmsItem::SetIsCollisionStatic
            (*(CHmsItem **)(*(int *)(this + 0x40) + 0x28),(CHmsItem *)0x1,in_stack_ffffffe4);
  CHmsItem::SetCountShadowTexCasted
            (*(CHmsItem **)(*(int *)(this + 0x40) + 0x28),(CHmsItem *)0x0,'\x01',(int)pCVar7);
  CHmsItem::SetShadowCasterGroupMask
            (*(CHmsItem **)(*(int *)(this + 0x40) + 0x28),(CHmsItem *)&DAT_00000004,(ulong)pCVar8);
  SetBlockMobilVisible(*(CSceneMobil **)(this + 0xd8),(int)in_stack_fffffff0,(int)pCVar9);
  pCVar7 = operator_new(0x48);
  if (pCVar7 == (CSceneMobil *)0x0) {
    pCVar13 = (CMwNod *)0x0;
  }
  else {
    CSceneMobil::CSceneMobil(pCVar7,in_stack_fffffff0);
    pCVar13 = extraout_EAX_01;
  }
  if (pCVar13 != *(CMwNod **)(this + 0x48)) {
    if (pCVar13 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar13,(CMwNod *)pCVar9);
    }
    if (*(CMwNod **)(this + 0x48) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x48),(CMwNod *)pCVar9);
    }
    *(CMwNod **)(this + 0x48) = pCVar13;
  }
  pCVar8 = operator_new(0xac);
  if (pCVar8 == (CPlugTree *)0x0) {
    pCVar10 = (CPlugSolid *)0x0;
  }
  else {
    CPlugTree::CPlugTree(pCVar8,pCVar9);
    pCVar10 = extraout_EAX_02;
  }
  in_stack_00000028 = (GxColor *)CONCAT31(in_stack_00000028._1_3_,3);
  CSceneMobil::SetTree(*(CSceneMobil **)(this + 0x48),pCVar10,pCVar9,(int)puVar19);
  CHmsItem::PickDisable(*(CHmsItem **)(*(int *)(this + 0x48) + 0x28),pCVar20);
  CHmsItem::SetCountShadowTexCasted
            (*(CHmsItem **)(*(int *)(this + 0x48) + 0x28),(CHmsItem *)0x0,'\x01',unaff_retaddr);
  CHmsItem::SetShadowCasterGroupMask
            (*(CHmsItem **)(*(int *)(this + 0x48) + 0x28),(CHmsItem *)&DAT_00000004,4);
  this_00 = operator_new(0x48);
  if (this_00 == (CSceneMobil *)0x0) {
    pCVar13 = (CMwNod *)0x0;
  }
  else {
    CSceneMobil::CSceneMobil(this_00,pCVar7);
    pCVar13 = extraout_EAX_03;
  }
  if (pCVar13 != *(CMwNod **)(this + 0x44)) {
    if (pCVar13 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar13,(CMwNod *)pCVar8);
    }
    if (*(CMwNod **)(this + 0x44) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x44),(CMwNod *)pCVar8);
    }
    *(CMwNod **)(this + 0x44) = pCVar13;
  }
  pCVar9 = operator_new(0xac);
  if (pCVar9 == (CPlugTree *)0x0) {
    pCVar10 = (CPlugSolid *)0x0;
  }
  else {
    CPlugTree::CPlugTree(pCVar9,pCVar8);
    pCVar10 = extraout_EAX_04;
  }
  CSceneMobil::SetTree(*(CSceneMobil **)(this + 0x44),pCVar10,pCVar8,in_stack_00000010);
  CHmsItem::SetLightEmitter
            (*(CHmsItem **)(*(int *)(this + 0x44) + 0x28),(CHmsItem *)0x0,in_stack_00000014);
  CHmsItem::SetIsCollisionStatic
            (*(CHmsItem **)(*(int *)(this + 0x44) + 0x28),(CHmsItem *)0x0,in_stack_00000018);
  CSceneMobil::GetTree(*(CSceneMobil **)(this + 0x44),(SVolatileTreePointer *)0x0);
  TreeSetVisible(in_stack_0000001c,(int)this_00);
  this_01 = operator_new(0x98);
  in_stack_00000054 = (CPlugTree *)CONCAT31(in_stack_00000054._1_3_,10);
  if (this_01 == (CPlugVisualLines *)0x0) {
    this_04 = (CPlugVisual *)0x0;
  }
  else {
    CPlugVisualLines::CPlugVisualLines(this_01,(CPlugVisualLines *)this_00);
    this_04 = extraout_EAX_05;
  }
  this_02 = operator_new(0xa8);
  if (this_02 == (CPlugShaderApply *)0x0) {
    this_03 = (CPlugShaderGeneric *)0x0;
  }
  else {
    CPlugShaderApply::CPlugShaderApply(this_02,(CPlugShaderApply *)pCVar9);
    this_03 = extraout_EAX_06;
  }
  fVar2 = *(float *)(this + 0x78);
  fVar4 = (float)_DAT_00b3d380;
  pEVar17 = *(ESpriteColor0 **)(this + 0x84);
  pCVar15 = (CPlugVisualSprite *)(*(float *)(this + 0x7c) * fVar4);
  pCVar16 = (CVisionViewportDx9 *)(fVar4 * *(float *)(this + 0x80));
  CPlugVisual::EnableVertexColor(this_04,(CPlugVisual *)0x1,(int)pCVar9);
  CPlugShaderGeneric::SetVertexColor
            (this_03,(CPlugShaderGeneric *)0x0,(EPlugShaderVertexColor)&stack0x00000044,
             in_stack_00000028);
  CPlugShader::SetReceiverShadowGroupMask
            ((CPlugShader *)this_03,(CPlugShader *)0x0,in_stack_0000002c);
  CHmsItem::SetIsForcePointDynamicCollisionResponse
            ((CHmsItem *)this_03,(CHmsItem *)0x0,in_stack_00000030);
  CPlugShaderApply::SetBlending
            ((CPlugShaderApply *)this_03,(CPlugShaderPass *)0x2,in_stack_00000034,
             (EGxBlendFactor)this_01);
  in_stack_00000054 = operator_new(0xac);
  uStack00000070 = 0xc;
  if (in_stack_00000054 == (CPlugTree *)0x0) {
    iVar11 = 0;
  }
  else {
    CPlugTree::CPlugTree(in_stack_00000054,(CPlugTree *)this_02);
    iVar11 = extraout_EAX_07;
  }
  iVar14 = 0;
  *(int *)(this + 0x4c) = iVar11;
  *(uint *)(iVar11 + 0x9c) = *(uint *)(iVar11 + 0x9c) & 0xffffbfff;
  uStack00000074 = 3;
  CPlugTree::SetVisual
            (*(CPlugTree **)(this + 0x4c),(CVisionVisualKeeper *)this_04,(CPlugVisual *)this_03);
  CPlugTree::SetUseLocation(*(CPlugTree **)(this + 0x4c),(CPlugTree *)0x1,iVar14);
  *(uint *)(*(int *)(this + 0x4c) + 0x9c) = *(uint *)(*(int *)(this + 0x4c) + 0x9c) & 0xffffffbf;
  UpdateShadow(this,(CGameCtnCursor *)0x0,(CGameCtnBlockInfo *)0x0,0);
  TreeSetVisible((CPlugTree *)0x0,(int)(fVar2 * fVar4));
  pCVar9 = CSceneMobil::GetTree
                     (*(CSceneMobil **)(this + 0x44),(SVolatileTreePointer *)(fVar2 * fVar4));
  pCVar3 = *(CGameOutlineBox **)(this + 0x4c);
  (**(code **)(*(int *)pCVar9 + 0x88))();
  pCVar12 = operator_new(0x40);
  uStack00000074 = 0xd;
  if (pCVar12 == (CGameOutlineBox *)0x0) {
    pCVar12 = (CGameOutlineBox *)0x0;
  }
  else {
    CGameOutlineBox::CGameOutlineBox(pCVar12,pCVar3);
    pCVar12 = extraout_EAX_08;
  }
  uStack00000074 = 3;
  *(CGameOutlineBox **)(this + 0x50) = pCVar12;
  CGameOutlineBox::Init(pCVar12,(CLoadGeomDynaSprite *)pCVar3,pCVar15,pCVar16,pEVar17);
  pCVar9 = CSceneMobil::GetTree(*(CSceneMobil **)(this + 0x44),in_stack_00000050);
  in_stack_00000050 = *(SVolatileTreePointer **)(*(int *)(this + 0x50) + 0x14);
  (**(code **)(*(int *)pCVar9 + 0x88))();
  pCVar9 = CSceneMobil::GetTree(*(CSceneMobil **)(this + 0x44),in_stack_00000050);
  in_stack_00000050 = *(SVolatileTreePointer **)(*(int *)(this + 0x50) + 0x18);
  (**(code **)(*(int *)pCVar9 + 0x88))();
  CPlugTree::SetUseLocation
            (*(CPlugTree **)(*(int *)(this + 0x50) + 0x14),(CPlugTree *)0x1,(int)in_stack_00000050);
  in_stack_00000050 = (SVolatileTreePointer *)0x1;
  CPlugTree::SetUseLocation
            (*(CPlugTree **)(*(int *)(this + 0x50) + 0x18),(CPlugTree *)0x1,(int)in_stack_00000054);
  puVar1 = (uint *)(*(int *)(*(int *)(this + 0x50) + 0x14) + 0x9c);
  *puVar1 = *puVar1 & 0xffffffbf;
  puVar1 = (uint *)(*(int *)(*(int *)(this + 0x50) + 0x18) + 0x9c);
  *puVar1 = *puVar1 & 0xffffffbf;
  *(undefined4 *)(this + 0x54) = 0;
  ExceptionList = in_stack_00000084;
  return;
}
}

// =================================================
// Function: CGameCtnCursor::GetMobilLocation
// =================================================
void __thiscall
CGameCtnCursor::GetMobilLocation(CGameCtnCursor *this,CGameCtnCursor *param_1,GmIso4 *param_2)
{
{
  CGameCtnBlock::GetMobilLoc
            ((CGameCtnBlock *)(this + 0x14),(CGameCtnBlock *)param_1,(GmIso4 *)(this + 0x14));
  return;
}
}

// =================================================
// Function: CGameCtnCursor::Update
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CGameCtnCursor::Update(CGameCtnCursor *this,SGmSmoothReal2 *param_1,int param_2,ulong param_3)
{
{
  uint uVar1;
  int iVar2;
  GmIso4 *pGVar3;
  CSceneMobil *pCVar4;
  CGameCtnBlockInfo *pCVar5;
  CGameCtnBlockInfo *extraout_EAX;
  CGameCtnBlockInfo *pCVar6;
  void *this_00;
  int iVar7;
  int unaff_EBX;
  GmIso4 *unaff_EBP;
  ulong unaff_ESI;
  GmIso4 *pGVar8;
  float *pfVar9;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 *puVar10;
  CPlugTree *pCVar11;
  float *pfVar12;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 fVar13;
  int in_stack_00000010;
  CGameCtnBlockInfo *in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  CGameCtnBlockInfo *in_stack_00000024;
  int in_stack_0000002c;
  int in_stack_00000030;
  int in_stack_00000034;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  int in_stack_00000040;
  int in_stack_00000048;
  int in_stack_0000004c;
  CPlugTree *pCVar14;
  CGameCtnCursor *pCVar15;
  int in_stack_ffffff60;
  GmIso4 *in_stack_ffffff64;
  GmIso4 *in_stack_ffffff68;
  GmIso4 *in_stack_ffffff6c;
  float fStack_84;
  float fStack_80;
  CPlugTree aCStack_7c [28];
  CGameCtnCursor aCStack_60 [4];
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_30;
  CPlugTree aCStack_24 [4];
  CGameCtnCursor aCStack_20 [20];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aae29e;
  local_c = ExceptionList;
  uVar1 = DAT_00cca150 ^ (uint)&stack0xffffff50;
  ExceptionList = &local_c;
  iVar2 = (**(code **)(**(int **)(this + 0x44) + 0x108))();
  fVar13 = extraout_ST0;
  if (iVar2 != 0) {
    UpdateColor(this,(CGameCtnCursor *)param_2,param_3,in_stack_00000010,in_stack_0000001c,
                in_stack_00000020,(int)in_stack_00000024,in_stack_0000002c,uVar1);
    pGVar8 = (GmIso4 *)0x0;
    if (param_2 == 0) {
      CPlugTree::SetUseLocation
                (*(CPlugTree **)(*(int *)(this + 0x50) + 0x18),(CPlugTree *)0x0,(int)unaff_EDI);
      CPlugTree::SetUseLocation
                (*(CPlugTree **)(*(int *)(this + 0x50) + 0x14),(CPlugTree *)0x0,unaff_ESI);
      pCVar5 = operator_new(0x130);
      if (pCVar5 == (CGameCtnBlockInfo *)0x0) {
        pCVar5 = (CGameCtnBlockInfo *)0x0;
      }
      else {
        CGameCtnBlockInfo::CGameCtnBlockInfo(pCVar5,(CGameCtnBlockInfo *)unaff_EBP);
        pCVar5 = extraout_EAX;
      }
      pCVar6 = in_stack_00000024;
      CGameCtnBlockInfo::AddBlock(pCVar5,(CGameCtnBlockInfo *)0x0,(GmNat3)0x0,0,0,0);
      pCVar15 = (CGameCtnCursor *)0x660508;
      AddBlocksToCursor(this,(CGameCtnCursor *)pCVar5,in_stack_00000024,0,(ulong)pCVar6);
      pCVar6 = pCVar5 + 0x58;
      if (in_stack_00000024 == (CGameCtnBlockInfo *)0x0) {
        pCVar6 = pCVar5 + 100;
      }
      *(undefined4 *)(this + 0x20) = *(undefined4 *)pCVar6;
      *(undefined4 *)(this + 0x24) = *(undefined4 *)(pCVar6 + 4);
      *(undefined4 *)(this + 0x28) = *(undefined4 *)(pCVar6 + 8);
      if (in_stack_00000040 == 0) {
        CPlugTree::SetUseLocation
                  (*(CPlugTree **)(*(int *)(this + 0x50) + 0x18),(CPlugTree *)0x0,unaff_EBX);
        CPlugTree::SetUseLocation
                  (*(CPlugTree **)(*(int *)(this + 0x50) + 0x14),(CPlugTree *)0x0,in_stack_ffffff60)
        ;
        TreeSetVisible((CPlugTree *)0x0,(int)in_stack_ffffff64);
        CPlugTree::SetUseLocation
                  (*(CPlugTree **)(this + 0x4c),(CPlugTree *)0x0,(int)in_stack_ffffff64);
      }
      else {
        CPlugTree::SetUseLocation(*(CPlugTree **)(this + 0x4c),(CPlugTree *)0x1,unaff_EBX);
        iVar2 = (**(code **)(**(int **)(this + 0x44) + 0x108))();
        TreeSetVisible((CPlugTree *)(uint)(iVar2 != 0),(int)in_stack_ffffff64);
        puVar10 = (undefined4 *)(*(int *)(*(int *)(this + 0x50) + 0x18) + 0x5c);
        pCVar14 = aCStack_24;
        for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
          *(undefined4 *)pCVar14 = *puVar10;
          puVar10 = puVar10 + 1;
          pCVar14 = pCVar14 + 4;
        }
        CPlugTree::SetLocation(*(CPlugTree **)(this + 0x4c),aCStack_24,in_stack_ffffff64);
      }
      GetMobilLocation(this,aCStack_20,in_stack_ffffff68);
      (**(code **)(**(int **)(this + 0x44) + 0x88))();
      UpdateCursorColor(this,pCVar15);
      fVar13 = extraout_ST0_01;
      if (pCVar5 != (CGameCtnBlockInfo *)0x0) {
        fVar13 = (float10)(**(code **)(*(int *)pCVar5 + 4))(1);
      }
    }
    else {
      this_00 = (void *)(param_2 + 0xfc);
      if (in_stack_00000018 == (CGameCtnBlockInfo *)0x0) {
        this_00 = (void *)(param_2 + 0x104);
      }
      pGVar3 = (GmIso4 *)CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
      if (pGVar3 != (GmIso4 *)0x0) {
        do {
          pCVar14 = (CPlugTree *)0x6601f3;
          pCVar4 = CGameCtnBlockInfo::GetMobil
                             ((CGameCtnBlockInfo *)param_2,in_stack_00000018,(int)pGVar8,0,unaff_ESI
                             );
          if (pCVar4 != (CSceneMobil *)0x0) {
            if (in_stack_00000034 == 0) {
              uVar1 = 0;
            }
            else {
              uVar1 = ((int)in_stack_0000003c < 0) - 1 & in_stack_0000003c;
            }
            pCVar15 = (CGameCtnCursor *)0x66024a;
            AddBlocksToCursor(this,(CGameCtnCursor *)param_2,in_stack_00000018,uVar1,
                              (ulong)unaff_EBP);
            if (in_stack_00000018 == (CGameCtnBlockInfo *)0x0) {
              puVar10 = (undefined4 *)(param_2 + 100);
            }
            else {
              puVar10 = (undefined4 *)(param_2 + 0x58);
            }
            *(undefined4 *)(this + 0x20) = *puVar10;
            *(undefined4 *)(this + 0x24) = puVar10[1];
            *(undefined4 *)(this + 0x28) = puVar10[2];
            goto LAB_00660299;
          }
          pGVar8 = pGVar8 + 1;
        } while (pGVar8 < in_stack_ffffff6c);
      }
      if (in_stack_00000030 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = ((int)in_stack_00000038 < 0) - 1 & in_stack_00000038;
      }
      pCVar14 = (CPlugTree *)0x66027c;
      pCVar15 = (CGameCtnCursor *)param_2;
      AddBlocksToCursor(this,(CGameCtnCursor *)param_2,
                        (CGameCtnBlockInfo *)(uint)(in_stack_00000018 == (CGameCtnBlockInfo *)0x0),
                        uVar1,unaff_ESI);
      if (in_stack_00000018 == (CGameCtnBlockInfo *)0x0) {
        puVar10 = (undefined4 *)(param_2 + 0x58);
      }
      else {
        puVar10 = (undefined4 *)(param_2 + 100);
      }
      *(undefined4 *)(this + 0x20) = *puVar10;
      *(undefined4 *)(this + 0x24) = puVar10[1];
      *(undefined4 *)(this + 0x28) = puVar10[2];
      in_stack_0000003c = in_stack_00000038;
LAB_00660299:
      GetMobilLocation(this,aCStack_60,unaff_EBP);
      if ((in_stack_00000038 == 0) || ((int)in_stack_0000003c < 1)) {
        if (in_stack_0000003c == 0) {
          CPlugTree::SetUseLocation
                    (*(CPlugTree **)(*(int *)(this + 0x50) + 0x18),(CPlugTree *)0x0,unaff_EBX);
          CPlugTree::SetUseLocation
                    (*(CPlugTree **)(*(int *)(this + 0x50) + 0x14),(CPlugTree *)0x0,
                     in_stack_ffffff60);
          TreeSetVisible((CPlugTree *)0x0,(int)in_stack_ffffff64);
          CPlugTree::SetUseLocation
                    (*(CPlugTree **)(this + 0x4c),(CPlugTree *)0x0,(int)in_stack_ffffff64);
        }
        else {
          CPlugTree::SetUseLocation
                    (*(CPlugTree **)(*(int *)(this + 0x50) + 0x18),(CPlugTree *)0x0,unaff_EBX);
          CPlugTree::SetUseLocation
                    (*(CPlugTree **)(*(int *)(this + 0x50) + 0x14),(CPlugTree *)0x0,
                     in_stack_ffffff60);
          CPlugTree::SetUseLocation
                    (*(CPlugTree **)(this + 0x4c),(CPlugTree *)0x1,(int)in_stack_ffffff64);
          pGVar8 = (GmIso4 *)0x660393;
          iVar2 = (**(code **)(**(int **)(this + 0x44) + 0x108))();
          TreeSetVisible((CPlugTree *)(uint)(iVar2 != 0),(int)pGVar8);
          pfVar9 = (float *)PTR_DAT_00cf3338;
          pfVar12 = &fStack_84;
          for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
            *pfVar12 = *pfVar9;
            pfVar9 = pfVar9 + 1;
            pfVar12 = pfVar12 + 1;
          }
          fStack_5c = (float)_DAT_00b313b8 - (float)in_stack_00000048 * _DAT_00ce9478;
          CPlugTree::SetLocation(*(CPlugTree **)(this + 0x4c),(CPlugTree *)&fStack_84,pGVar8);
        }
      }
      else {
        TreeSetVisible((CPlugTree *)0x0,unaff_EBX);
        CPlugTree::SetUseLocation(*(CPlugTree **)(this + 0x4c),(CPlugTree *)0x0,unaff_EBX);
        CPlugTree::SetUseLocation
                  (*(CPlugTree **)(*(int *)(this + 0x50) + 0x18),(CPlugTree *)0x1,in_stack_ffffff60)
        ;
        CPlugTree::SetUseLocation
                  (*(CPlugTree **)(*(int *)(this + 0x50) + 0x14),(CPlugTree *)0x1,
                   (int)in_stack_ffffff64);
        fStack_84 = (float)in_stack_0000004c;
        iVar2 = *(int *)(this + 0x50);
        pfVar9 = (float *)(*(int *)(iVar2 + 0x18) + 0x5c);
        pfVar12 = &fStack_80;
        for (iVar7 = 0xc; iVar7 != 0; iVar7 = iVar7 + -1) {
          *pfVar12 = *pfVar9;
          pfVar9 = pfVar9 + 1;
          pfVar12 = pfVar12 + 1;
        }
        fStack_58 = -(fStack_84 * _DAT_00ce9478);
        CPlugTree::SetLocation(*(CPlugTree **)(iVar2 + 0x18),(CPlugTree *)&fStack_80,pGVar3);
        iVar2 = *(int *)(this + 0x50);
        puVar10 = (undefined4 *)(*(int *)(iVar2 + 0x14) + 0x5c);
        pCVar11 = aCStack_7c;
        for (iVar7 = 0xc; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined4 *)pCVar11 = *puVar10;
          puVar10 = puVar10 + 1;
          pCVar11 = pCVar11 + 4;
        }
        fStack_54 = -(fStack_80 * _DAT_00ce9478);
        CPlugTree::SetLocation(*(CPlugTree **)(iVar2 + 0x14),aCStack_7c,in_stack_ffffff6c);
      }
      (**(code **)(**(int **)(this + 0x44) + 0x88))();
      fStack_30 = fStack_30 + (float)_DAT_00b313b8;
      (**(code **)(**(int **)(this + 0x40) + 0x88))();
      (**(code **)(**(int **)(this + 0x48) + 0x88))();
      SetBlockMobilVisible(*(CSceneMobil **)(this + 0xd8),(int)pCVar14,(int)pCVar15);
      CSceneMobil::GetTree(*(CSceneMobil **)(this + 0x48),*(SVolatileTreePointer **)(this + 0xf4));
      TreeSetVisible(pCVar14,(int)pCVar15);
      UpdateCursorColor(this,pCVar15);
      fVar13 = extraout_ST0_00;
    }
  }
  ExceptionList = local_c;
  return (float)fVar13;
}
}

// =================================================
// Function: CGameCtnCursor::UpdateColor
// =================================================
void __thiscall
CGameCtnCursor::UpdateColor
          (CGameCtnCursor *this,CGameCtnCursor *param_1,int param_2,int param_3,int param_4,
          int param_5,int param_6,int param_7,int param_8)
{
{
  undefined4 uVar1;
  CGameCtnCursor *pCVar2;
  
  if (param_5 == 0) {
    if (param_6 == 0) {
      if (param_4 == 0) {
        if (param_7 == 0) {
          if (param_3 == 0) {
            if (param_2 != 0) {
              pCVar2 = this + 0x68;
              goto LAB_0065e448;
            }
          }
          else {
            if (param_1 != (CGameCtnCursor *)0x0) {
              pCVar2 = this + 0x58;
              goto LAB_0065e448;
            }
            pCVar2 = this + 0x68;
            if (param_2 != 0) goto LAB_0065e448;
          }
          pCVar2 = this + 0x78;
        }
        else {
          pCVar2 = this + 200;
        }
      }
      else {
        pCVar2 = this + 0x98;
      }
    }
    else {
      pCVar2 = this + 0xb8;
    }
  }
  else {
    pCVar2 = this + 0xa8;
  }
LAB_0065e448:
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)pCVar2;
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(pCVar2 + 4);
  uVar1 = *(undefined4 *)(pCVar2 + 0xc);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(pCVar2 + 8);
  *(undefined4 *)(this + 0x38) = uVar1;
  return;
}
}

// =================================================
// Function: CGameCtnCursor::UpdateCursorColor
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameCtnCursor::UpdateCursorColor(CGameCtnCursor *this,CGameCtnCursor *param_1)
{
{
  GxColor *unaff_ESI;
  GxColor *in_stack_fffffff0;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)(this + 0x54) != 0) {
    local_8 = (float)_DAT_00b3d2c0;
    in_stack_fffffff0 = (GxColor *)(*(float *)(this + 0x2c) * local_8);
    local_4 = *(float *)(this + 0x38);
    local_c = *(float *)(this + 0x30) * local_8;
    local_8 = local_8 * *(float *)(this + 0x34);
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(*(int *)(this + 0x54) + 0x94),(CPlugShaderGeneric *)0x0,
               (EPlugShaderVertexColor)&stack0xfffffff0,unaff_ESI);
  }
  local_4 = (float)_DAT_00b3d380;
  local_c = *(float *)(this + 0x2c) * local_4;
  local_8 = *(float *)(this + 0x30) * local_4;
  local_4 = local_4 * *(float *)(this + 0x34);
  CPlugShaderGeneric::SetVertexColor
            (*(CPlugShaderGeneric **)(*(int *)(this + 0x4c) + 0x94),(CPlugShaderGeneric *)0x0,
             (EPlugShaderVertexColor)&local_c,in_stack_fffffff0);
  return;
}
}

// =================================================
// Function: CGameCtnCursor::UpdateShadow
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameCtnCursor::UpdateShadow
          (CGameCtnCursor *this,CGameCtnCursor *param_1,CGameCtnBlockInfo *param_2,int param_3)
{
{
  GmVec2 *pGVar1;
  int iVar2;
  uint uVar3;
  CGameCtnBlockInfo *pCVar4;
  float fVar5;
  CGameCtnBlockInfo *this_00;
  ulong uVar6;
  CGameCtnBlockUnitInfo *pCVar7;
  SCasterCat *pSVar8;
  CPlugVisualLines2D *pCVar9;
  GxColor *unaff_EBX;
  CGameCtnBlockInfo *pCVar10;
  CPlugVisualLines *pCVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  GxColor *unaff_EBP;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  uint uVar13;
  GxColor *unaff_EDI;
  uint uVar14;
  CGameCtnCursor *in_stack_00000010;
  undefined4 in_stack_00000014;
  float in_stack_0000001c;
  float in_stack_00000020;
  CGameCtnCursor *in_stack_00000024;
  CGameCtnBlockInfo *pCVar15;
  CPlugVisualLines2D *pCVar16;
  GmVec2 *in_stack_ffffffb8;
  CPlugVisualLines *this_01;
  CPlugVisualLines *local_34;
  CPlugVisualLines *local_30;
  CPlugVisualLines *local_2c;
  int local_28;
  int local_24;
  uint local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined *local_8;
  float local_4;
  
  local_4 = -NAN;
  local_8 = &DAT_00aae118;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar11 = *(CPlugVisualLines **)(*(int *)(this + 0x4c) + 0x90);
  this_01 = pCVar11 + 0x78;
  pCVar16 = (CPlugVisualLines2D *)pCVar11;
  pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)this;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
            (this_01,(GmFrustumIso4 *)(DAT_00cca150 ^ (uint)&stack0xffffffa4));
  this_00 = param_2;
  if (param_2 == (CGameCtnBlockInfo *)0x0) {
    pGVar1 = (GmVec2 *)(this + 0x2c);
    local_1c = 0;
    local_10 = 0;
    local_20 = 0;
    local_14 = 0;
    local_18 = 0;
    local_c = (void *)0x3f800000;
    CPlugVisualLines::AddLine
              (pCVar11,(CPlugVisualLines2D *)&local_20,(GmVec2 *)&local_14,pGVar1,unaff_EDI);
    local_1c = 0;
    local_10 = 0x3f800000;
    local_14 = 0x3f800000;
    local_8 = (undefined *)0x3f800000;
    CPlugVisualLines::AddLine
              (pCVar11,(CPlugVisualLines2D *)&local_1c,(GmVec2 *)&local_10,pGVar1,
               (GxColor *)unaff_ESI);
    local_18 = 0x3f800000;
    local_c = (void *)0x3f800000;
    local_10 = 0x3f800000;
    local_4 = 0.0;
    CPlugVisualLines::AddLine
              (pCVar11,(CPlugVisualLines2D *)&local_18,(GmVec2 *)&local_c,pGVar1,unaff_EBP);
    local_14 = 0x3f800000;
    local_8 = (undefined *)0x0;
    local_c = (void *)0x0;
    CPlugVisualLines::AddLine
              (pCVar11,(CPlugVisualLines2D *)&local_14,(GmVec2 *)&local_8,pGVar1,unaff_EBX);
  }
  else {
    uVar6 = CGameCtnBlockInfo::GetNbBlockUnitInfos(param_2,(CGameCtnBlockInfo *)0x0,(int)unaff_EDI);
    pCVar4 = (CGameCtnBlockInfo *)(uint)(uVar6 == 0);
    pCVar10 = this_00 + 0x58;
    if (pCVar4 == (CGameCtnBlockInfo *)0x0) {
      pCVar10 = this_00 + 100;
    }
    local_24 = *(int *)(pCVar10 + 4);
    iVar2 = *(int *)pCVar10;
    uVar3 = *(uint *)(pCVar10 + 8);
    local_28 = iVar2;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(&local_34,unaff_ESI);
    param_2 = (CGameCtnBlockInfo *)0x0;
    CFastBuffer<class_GmVector2<unsigned_short>_>::AllocSetCount
              (&local_30,(CFastBuffer<class_GxVertex2> *)(uVar3 * iVar2),(ulong)unaff_EBP);
    in_stack_00000014 = 0;
    CFastBuffer<int>::FillWith
              (&local_2c,(CFixedArray<unsigned_char,8,unsigned_long> *)&stack0x00000014,
               (uchar *)unaff_EBX);
    pCVar9 = (CPlugVisualLines2D *)pCVar4;
    uVar6 = CGameCtnBlockInfo::GetNbBlockUnitInfos(this_00,pCVar4,(int)pCVar16);
    if (uVar6 != 0) {
      pCVar10 = (CGameCtnBlockInfo *)0x0;
      do {
        pCVar15 = pCVar4;
        pCVar7 = CGameCtnBlockInfo::GetBlockUnitInfo(this_00,pCVar10,(ulong)pCVar4,(int)pCVar9);
        if (pCVar7 != (CGameCtnBlockUnitInfo *)0x0) {
          local_c = *(void **)(pCVar7 + 0x2c);
          pCVar9 = (CPlugVisualLines2D *)(*(int *)(pCVar7 + 0x28) * uVar3 + *(int *)(pCVar7 + 0x30))
          ;
          pCVar15 = (CGameCtnBlockInfo *)0x65f159;
          pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (&local_28,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar9,
                              (ulong)pCVar16);
          *(undefined4 *)pSVar8 = 1;
        }
        pCVar10 = pCVar10 + 1;
        pCVar15 = (CGameCtnBlockInfo *)
                  CGameCtnBlockInfo::GetNbBlockUnitInfos(this_00,pCVar4,(int)pCVar15);
      } while (pCVar10 < pCVar15);
    }
    uVar14 = 0;
    if (local_20 != 0) {
      do {
        uVar13 = 0;
        if (uVar3 != 0) {
          do {
            pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (&local_2c,
                                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                (uVar14 * uVar3 + uVar13),(ulong)pCVar9);
            if (*(int *)pSVar8 != 0) {
              local_c = (void *)0x0;
              if ((uVar14 == 0) ||
                 (pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                     (&local_28,
                                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                      ((uVar14 - 1) * uVar3 + uVar13),(ulong)pCVar16),
                 pCVar11 = local_2c, *(int *)pSVar8 == 0)) {
                pCVar11 = local_2c;
                fVar5 = (float)(int)uVar14;
                if ((int)uVar14 < 0) {
                  fVar5 = fVar5 + _DAT_00c418d0;
                }
                local_c = (void *)(_DAT_00ce9474 * fVar5);
                in_stack_0000001c = (float)(int)uVar13;
                if ((int)uVar13 < 0) {
                  in_stack_0000001c = in_stack_0000001c + _DAT_00c418d0;
                }
                local_4 = in_stack_0000001c * _DAT_00ce9474;
                in_stack_0000001c = in_stack_0000001c + (float)_DAT_00b2c188;
                param_2 = (CGameCtnBlockInfo *)(_DAT_00ce9474 * in_stack_0000001c);
                CPlugVisualLines::AddLine
                          (local_34,(CPlugVisualLines2D *)&local_c,(GmVec2 *)&stack0x00000000,
                           (GmVec2 *)(local_2c + 0x2c),(GxColor *)in_stack_ffffffb8);
              }
              if (uVar14 == local_18 - 1U) {
LAB_0065f27f:
                fVar5 = (float)(int)uVar14;
                if ((int)uVar14 < 0) {
                  fVar5 = fVar5 + _DAT_00c418d0;
                }
                local_c = (void *)(_DAT_00ce9474 * (fVar5 + 1.0));
                in_stack_0000001c = (float)(int)uVar13;
                if ((int)uVar13 < 0) {
                  in_stack_0000001c = in_stack_0000001c + _DAT_00c418d0;
                }
                local_4 = in_stack_0000001c * _DAT_00ce9474;
                in_stack_0000001c = in_stack_0000001c + 1.0;
                param_2 = (CGameCtnBlockInfo *)(_DAT_00ce9474 * in_stack_0000001c);
                pCVar9 = (CPlugVisualLines2D *)register0x00000010;
                CPlugVisualLines::AddLine
                          (local_34,(CPlugVisualLines2D *)&local_c,(GmVec2 *)&stack0x00000000,
                           (GmVec2 *)(pCVar11 + 0x2c),(GxColor *)in_stack_ffffffb8);
              }
              else {
                pCVar9 = (CPlugVisualLines2D *)0x65f276;
                pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (&local_24,
                                    (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                    ((uVar14 + 1) * uVar3 + uVar13),(ulong)in_stack_ffffffb8);
                if (*(int *)pSVar8 == 0) goto LAB_0065f27f;
              }
              if (uVar13 == 0) {
LAB_0065f327:
                fVar5 = (float)(int)uVar14;
                if ((int)uVar14 < 0) {
                  fVar5 = fVar5 + _DAT_00c418d0;
                }
                local_8 = (undefined *)(_DAT_00ce9474 * fVar5);
                param_1 = (CGameCtnCursor *)((fVar5 + (float)_DAT_00b2c188) * _DAT_00ce9474);
                fVar5 = (float)(int)uVar13;
                if ((int)uVar13 < 0) {
                  fVar5 = fVar5 + _DAT_00c418d0;
                }
                param_3 = (int)(fVar5 * _DAT_00ce9474);
                pCVar16 = (CPlugVisualLines2D *)&param_1;
                pCVar9 = (CPlugVisualLines2D *)&local_8;
                in_stack_00000020 = (float)param_3;
                CPlugVisualLines::AddLine
                          (local_30,pCVar9,(GmVec2 *)pCVar16,(GmVec2 *)(pCVar11 + 0x2c),
                           (GxColor *)pCVar12);
              }
              else {
                pCVar16 = (CPlugVisualLines2D *)0x65f31e;
                pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (&local_20,
                                    (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                    (local_2c + (uVar13 - 1)),(ulong)pCVar12);
                if (*(int *)pSVar8 == 0) goto LAB_0065f327;
              }
              if (uVar13 != uVar3 - 1) {
                pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(local_28 + 1 + uVar13);
                in_stack_ffffffb8 = (GmVec2 *)0x65f3c1;
                pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (&local_1c,pCVar12,(ulong)this_01);
                if (*(int *)pSVar8 != 0) goto LAB_0065f453;
              }
              fVar5 = (float)(int)uVar14;
              if ((int)uVar14 < 0) {
                fVar5 = fVar5 + _DAT_00c418d0;
              }
              local_4 = _DAT_00ce9474 * fVar5;
              param_2 = (CGameCtnBlockInfo *)((fVar5 + 1.0) * _DAT_00ce9474);
              fVar5 = (float)(int)uVar13;
              if ((int)uVar13 < 0) {
                fVar5 = fVar5 + _DAT_00c418d0;
              }
              pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(pCVar11 + 0x2c);
              in_stack_ffffffb8 = (GmVec2 *)&param_2;
              param_1 = (CGameCtnCursor *)(_DAT_00ce9474 * (fVar5 + 1.0));
              pCVar16 = (CPlugVisualLines2D *)&local_4;
              pCVar9 = (CPlugVisualLines2D *)0x65f453;
              in_stack_00000010 = param_1;
              in_stack_00000024 = param_1;
              CPlugVisualLines::AddLine
                        (local_2c,pCVar16,in_stack_ffffffb8,(GmVec2 *)pCVar12,(GxColor *)this_01);
            }
LAB_0065f453:
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar3);
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < local_20);
    }
    param_3 = -1;
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (&local_2c,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar9);
    this = (CGameCtnCursor *)local_30;
  }
  uVar6 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (local_2c,(CFastBuffer<class_CCrystalFace*> *)pCVar16);
  TreeSetVisible((CPlugTree *)(uint)(uVar6 != 0),(int)in_stack_ffffffb8);
  (**(code **)(**(int **)(this + 0x4c) + 0xbc))();
  ExceptionList = param_2;
  return;
}
}

