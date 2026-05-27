// Class implementation: CPlugFileGen

// =================================================
// Function: CPlugFileGen::CPlugFileGen
// =================================================
void __thiscall CPlugFileGen::CPlugFileGen(CPlugFileGen *this,CPlugFileGen *param_1)
{
{
  CPlugFileImg *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_retaddr;
  CFastArray<class_CManoeuvre*> *in_stack_00000008;
  
  CPlugFileImg::CPlugFileImg((CPlugFileImg *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x38,unaff_retaddr);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>
            (this + 0x40,(CFastArray<class_CManoeuvre*> *)param_1);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x48,in_stack_00000008);
  return;
}
}

// =================================================
// Function: CPlugFileGen::GenChecker
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall CPlugFileGen::GenChecker(CPlugFileGen *this,CPlugFileGen *param_1,ulong param_2)
{
{
  uchar uVar1;
  SCasterCat *pSVar2;
  void *pvVar3;
  uchar *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ulong unaff_EBX;
  ulong unaff_EBP;
  CPlugFileGen **ppCVar10;
  ulong unaff_ESI;
  int *piVar11;
  ulong unaff_EDI;
  CPlugFileImg *pCVar12;
  undefined4 in_stack_0000000c;
  ulong in_stack_ffffffa8;
  CPlugFileImg *in_stack_ffffffac;
  ulong local_44;
  CPlugFileGen **local_40;
  int local_3c;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)&stack0xffffffa8;
  *(undefined4 *)(this + 0x34) = 0;
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (this + 0x38,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_EDI);
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  *(undefined4 *)pSVar2 = in_stack_0000000c;
  CFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint>::SetCount
            (this + 0x40,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,unaff_EBX);
  CFastArray<float>::SetCount
            (this + 0x48,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,in_stack_ffffffa8);
  CPlugFileImg::DeletePixels((CPlugFileImg *)this,in_stack_ffffffac);
  uVar8 = *(uint *)(this + 0x24);
  *(uint *)(this + 0x24) = uVar8 & 0xfff0fe1d | 0x8001;
  switch(in_stack_0000000c) {
  case 0:
    uVar8 = uVar8 & 0xfff0fe0d | 0x800d;
    *(uint *)(this + 0x24) = uVar8;
    in_stack_0000000c = 0xffffff00;
    param_1 = (CPlugFileGen *)0xffffff;
    param_2 = 0;
    *(undefined4 *)(this + 0x18) = 2;
    *(undefined4 *)(this + 0x1c) = 2;
    pvVar3 = operator_new__(uVar8 & 0x1c);
    *(void **)(this + 0x28) = pvVar3;
    local_44 = 0;
    if (*(int *)(this + 0x1c) != 0) {
      ppCVar10 = &param_1;
      do {
        pCVar12 = (CPlugFileImg *)0x0;
        local_40 = ppCVar10;
        if (*(int *)(this + 0x18) != 0) {
          do {
            puVar4 = CPlugFileImg::GetPixel((CPlugFileImg *)this,pCVar12,local_44,unaff_EBP);
            uVar1 = *(uchar *)((int)ppCVar10 + 2);
            *(undefined2 *)puVar4 = *(undefined2 *)ppCVar10;
            pCVar12 = pCVar12 + 1;
            puVar4[2] = uVar1;
            ppCVar10 = (CPlugFileGen **)((int)ppCVar10 + 3);
          } while (pCVar12 < *(CPlugFileImg **)(this + 0x18));
        }
        local_44 = local_44 + 1;
        ppCVar10 = (CPlugFileGen **)((int)local_40 + 6);
      } while (local_44 < *(uint *)(this + 0x1c));
      return;
    }
    break;
  case 1:
    uVar8 = uVar8 & 0xfff0fe0d | 0x800d;
    *(uint *)(this + 0x24) = uVar8;
    local_3c = -1;
    local_35 = 0xff;
    local_31 = 0xff;
    local_2e = 0xff;
    local_2d = 0xff;
    local_2c = 0xff;
    local_2b = 0xff;
    local_2a = 0xff;
    local_26 = 0xff;
    local_23 = 0xff;
    local_1f = 0xff;
    local_1e = 0xff;
    local_1d = 0xff;
    local_1c = 0xff;
    local_1b = 0xff;
    local_18 = 0xff;
    local_14 = 0xff;
    local_10 = 0xff;
    local_f = 0xff;
    local_e = 0xff;
    local_d = 0xff;
    local_38 = 0;
    local_37 = 0;
    local_36 = 0;
    local_34 = 0;
    local_33 = 0;
    local_32 = 0;
    local_30 = 0;
    local_2f = 0;
    local_29 = 0;
    local_28 = 0;
    local_27 = 0;
    local_25 = 0;
    local_24 = 0;
    local_22 = 0;
    local_21 = 0;
    local_20 = 0;
    local_1a = 0;
    local_19 = 0;
    local_17 = 0;
    local_16 = 0;
    local_15 = 0;
    local_13 = 0;
    local_12 = 0;
    local_11 = 0;
    *(undefined4 *)(this + 0x18) = 4;
    *(undefined4 *)(this + 0x1c) = 4;
    piVar6 = operator_new__(((uVar8 & 0x1c) >> 2) << 4);
    *(int **)(this + 0x28) = piVar6;
    iVar9 = 0xc;
    goto LAB_0087405a;
  case 2:
    uVar8 = uVar8 & 0xfff0fe11 | 0x8011;
    *(uint *)(this + 0x24) = uVar8;
    local_35 = 0xff;
    local_34 = 0xff;
    local_32 = 0xff;
    local_30 = 0xff;
    local_2d = 0xff;
    local_2c = 0xff;
    local_20 = 0xff;
    local_1e = 0xff;
    local_1c = 0xff;
    local_1a = 0xff;
    local_18 = 0xff;
    local_15 = 0xff;
    local_d = 0xff;
    local_8 = 0xff;
    local_6 = 0xff;
    local_3c = 0xffffff;
    local_31 = 0;
    local_2e = 0;
    local_2a = 0;
    local_29 = 0x80;
    local_25 = 0x40;
    local_21 = 0x80;
    local_1d = 0x40;
    local_19 = 0;
    local_16 = 0;
    local_11 = 0;
    local_9 = 0x80;
    local_5 = 0x40;
    local_4 = 0x800000ff;
    *(undefined4 *)(this + 0x18) = 4;
    *(undefined4 *)(this + 0x1c) = 4;
    uVar8 = ((uVar8 & 0x1c) >> 2) << 4;
    goto LAB_00874034;
  case 3:
    uVar8 = uVar8 & 0xfff0fe05 | 0x8005;
    *(uint *)(this + 0x24) = uVar8;
    *(undefined4 *)(this + 0x18) = 0x10;
    *(undefined4 *)(this + 0x1c) = 0x10;
    pvVar3 = operator_new__(((uVar8 & 0x1c) >> 2) << 8);
    uVar8 = 0;
    *(void **)(this + 0x28) = pvVar3;
    if (*(int *)(this + 0x1c) != 0) {
      do {
        pCVar12 = (CPlugFileImg *)0x0;
        if (*(int *)(this + 0x18) != 0) {
          local_40 = (CPlugFileGen **)((uVar8 >> 3) * 2);
          do {
            puVar4 = CPlugFileImg::GetPixel((CPlugFileImg *)this,pCVar12,uVar8,unaff_EBP);
            uVar7 = (uint)pCVar12 >> 3;
            pCVar12 = pCVar12 + 1;
            *puVar4 = *(uchar *)((int)&local_40 + uVar7 + local_3c);
          } while (pCVar12 < *(CPlugFileImg **)(this + 0x18));
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(uint *)(this + 0x1c));
      return;
    }
    break;
  case 4:
    uVar8 = uVar8 & 0xfff0fe11 | 0x8011;
    *(uint *)(this + 0x24) = uVar8;
    local_35 = 0xff;
    local_34 = 0xff;
    local_32 = 0xff;
    local_30 = 0xff;
    local_2d = 0xff;
    local_2c = 0xff;
    local_20 = 0xff;
    local_1e = 0xff;
    local_1c = 0xff;
    local_1a = 0xff;
    local_18 = 0xff;
    local_15 = 0xff;
    local_d = 0xff;
    local_8 = 0xff;
    local_6 = 0xff;
    local_3c = 0xffffff;
    local_31 = 0;
    local_2e = 0;
    local_2a = 0;
    local_19 = 0;
    local_16 = 0;
    local_11 = 0;
    local_4 = 0xff0000ff;
    *(undefined4 *)(this + 0x18) = 4;
    *(undefined4 *)(this + 0x1c) = 4;
    uVar8 = ((uVar8 & 0x1c) >> 2) << 4;
    goto LAB_0087402c;
  case 5:
    uVar8 = uVar8 & 0xfff0fe05 | 0x8005;
    *(uint *)(this + 0x24) = uVar8;
    local_3c = -1;
    local_37 = 0xff;
    local_36 = 0xff;
    local_35 = 0xff;
    local_34 = 0xff;
    local_32 = 0xff;
    local_31 = 0xff;
    local_30 = 0xff;
    local_2f = 0xff;
    local_2e = 0xff;
    local_2c = 0xff;
    local_2b = 0xff;
    local_2a = 0xff;
    local_29 = 0xff;
    local_23 = 0xff;
    local_22 = 0xff;
    local_21 = 0xff;
    local_20 = 0xff;
    local_1c = 0xff;
    local_1a = 0xff;
    local_19 = 0xff;
    local_b = 0xff;
    local_2d = 0;
    local_26 = 0;
    local_25 = 0;
    local_1f = 0;
    local_1e = 0;
    local_1d = 0;
    local_18 = 0;
    local_16 = 0;
    local_15 = 0;
    local_11 = 0;
    local_10 = 0;
    local_d = 0;
    local_9 = 0;
    local_8 = 0;
    local_7 = 0;
    local_6 = 0;
    local_5 = 0;
    local_4 = 0xff;
    *(undefined4 *)(this + 0x18) = 8;
    *(undefined4 *)(this + 0x1c) = 8;
    uVar8 = ((uVar8 & 0x1c) >> 2) << 6;
    goto LAB_00874038;
  case 6:
    uVar8 = uVar8 & 0xfff0fe0d | 0x800d;
    *(uint *)(this + 0x24) = uVar8;
    in_stack_0000000c = 0xffffffff;
    param_1 = (CPlugFileGen *)0xff;
    param_2 = 0xff;
    *(undefined4 *)(this + 0x18) = 2;
    *(undefined4 *)(this + 0x1c) = 2;
    puVar5 = operator_new__(uVar8 & 0x1c);
    *(undefined4 **)(this + 0x28) = puVar5;
    *puVar5 = param_1;
    puVar5[1] = param_2;
    puVar5[2] = in_stack_0000000c;
    break;
  case 7:
    local_3c = -1;
    local_31 = 0xff;
    local_2e = 0xff;
    local_2a = 0xff;
    local_19 = 0xff;
    local_16 = 0xff;
    local_11 = 0xff;
    uVar8 = uVar8 & 0xfff0fe11 | 0x8011;
    *(uint *)(this + 0x24) = uVar8;
    *(undefined4 *)(this + 0x18) = 4;
    *(undefined4 *)(this + 0x1c) = 4;
    uVar8 = ((uVar8 & 0x1c) >> 2) *
            *(int *)(this + 0x20) * *(int *)(this + 0x1c) * *(int *)(this + 0x18);
    local_35 = 0;
    local_34 = 0;
    local_32 = 0;
    local_30 = 0;
    local_2d = 0;
    local_2c = 0;
    local_20 = 0;
    local_1e = 0;
    local_1c = 0;
    local_1a = 0;
    local_18 = 0;
    local_15 = 0;
    local_d = 0;
    local_8 = 0;
    local_6 = 0;
    local_4 = 0xffff0000;
LAB_0087402c:
    local_9 = 0xff;
    local_1d = 0;
    local_21 = 0xff;
    local_25 = 0;
    local_29 = 0xff;
    local_5 = 0;
LAB_00874034:
    local_7 = 0xff;
    local_10 = 0xff;
    local_1f = 0xff;
    local_22 = 0;
    local_23 = 0;
    local_26 = 0xff;
    local_2b = 0;
    local_2f = 0;
    local_36 = 0;
    local_37 = 0;
    local_b = 0;
LAB_00874038:
    local_c = 0xff;
    local_12 = 0xff;
    local_13 = 0xff;
    local_14 = 0xff;
    local_17 = 0;
    local_1b = 0xff;
    local_24 = 0xff;
    local_27 = 0xff;
    local_28 = 0xff;
    local_33 = 0xff;
    local_38 = 0xff;
    local_a = 0;
    local_e = 0;
    local_f = 0;
    local_4._0_2_ = (ushort)(byte)local_4;
    piVar6 = operator_new__(uVar8);
    *(int **)(this + 0x28) = piVar6;
    iVar9 = 0x10;
LAB_0087405a:
    piVar11 = &local_3c;
    for (; iVar9 != 0; iVar9 = iVar9 + -1) {
      *piVar6 = *piVar11;
      piVar11 = piVar11 + 1;
      piVar6 = piVar6 + 1;
    }
  }
  return;
}
}

// =================================================
// Function: CPlugFileGen::GenCubeNormals
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugFileGen::GenCubeNormals
          (CPlugFileGen *this,CPlugFileGen *param_1,ulong param_2,ulong param_3,GxColor *param_4,
          GxColor *param_5)
{
{
  int iVar1;
  GxColor *pGVar2;
  float fVar3;
  float fVar4;
  GxColor *pGVar5;
  float fVar6;
  GxColor *pGVar7;
  float *pfVar8;
  SCasterCat *pSVar9;
  CPlugFileImg *pCVar10;
  uint uVar11;
  ulong unaff_EBX;
  CPlugFileGen *pCVar12;
  ulong unaff_EBP;
  ulong uVar13;
  ulong unaff_ESI;
  ulong unaff_EDI;
  undefined2 in_FPUControlWord;
  float10 fVar14;
  CPlugFileGen *pCVar15;
  float in_stack_00000018;
  float in_stack_0000001c;
  float in_stack_00000020;
  float *in_stack_00000024;
  GxColor *in_stack_0000002c;
  GxColor *pGStack00000030;
  uint uStack00000034;
  float *in_stack_00000038;
  ulong in_stack_ffffffcc;
  ulong in_stack_ffffffd0;
  ulong in_stack_ffffffd4;
  ulong in_stack_ffffffd8;
  CPlugFileImg *in_stack_ffffffdc;
  CPlugFileImg *in_stack_ffffffe0;
  CMwCmdBufferCore *in_stack_ffffffe4;
  CPlugFileImg *local_c;
  
  CMwCmdBufferCore::HighFrequencyEnterSafeSection(DAT_00d731e0,(CMwCmdBufferCore *)0x1,unaff_EDI);
  uVar13 = param_3;
  if (((param_3 != 1) && (param_3 != 3)) && (param_3 != 4)) {
    uVar13 = 3;
  }
  iVar1 = 0x1f;
  if (param_2 != 0) {
    for (; param_2 >> iVar1 == 0; iVar1 = iVar1 + -1) {
    }
  }
  pCVar12 = (CPlugFileGen *)(1 << ((byte)iVar1 & 0x1f));
  pCVar15 = this + 0x38;
  *(undefined4 *)(this + 0x34) = 7;
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (pCVar15,(CFastBuffer<class_CSystemFidsFolder*> *)0x2,unaff_ESI);
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar15,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBP);
  *(CPlugFileGen **)pSVar9 = pCVar12;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar15,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,unaff_EBX);
  *(ulong *)pSVar9 = uVar13;
  CFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint>::SetCount
            (this + 0x40,(CFastBuffer<class_CSystemFidsFolder*> *)0x2,in_stack_ffffffcc);
  pSVar9 = CFastBuffer<class_GxColor>::operator[]
                     (this + 0x40,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      in_stack_ffffffd0);
  pfVar8 = in_stack_00000024;
  *(float *)pSVar9 = *in_stack_00000024;
  *(float *)(pSVar9 + 4) = in_stack_00000024[1];
  *(float *)(pSVar9 + 8) = in_stack_00000024[2];
  *(float *)(pSVar9 + 0xc) = in_stack_00000024[3];
  pSVar9 = CFastBuffer<class_GxColor>::operator[]
                     (this + 0x40,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                      in_stack_ffffffd4);
  *(undefined4 *)pSVar9 = *(undefined4 *)in_stack_0000002c;
  *(undefined4 *)(pSVar9 + 4) = *(undefined4 *)(in_stack_0000002c + 4);
  *(undefined4 *)(pSVar9 + 8) = *(undefined4 *)(in_stack_0000002c + 8);
  *(undefined4 *)(pSVar9 + 0xc) = *(undefined4 *)(in_stack_0000002c + 0xc);
  CFastArray<float>::SetCount
            (this + 0x48,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,in_stack_ffffffd8);
  CPlugFileImg::DeletePixels((CPlugFileImg *)this,in_stack_ffffffdc);
  *(CPlugFileGen **)(this + 0x18) = pCVar12;
  *(CPlugFileGen **)(this + 0x1c) = pCVar12;
  *(uint *)(this + 0x24) =
       ((-(uint)(uVar13 != 4) & 6) * 8 | uVar13 & 7) * 4 | *(uint *)(this + 0x24) & 0xfff0fe02 |
       0x8002;
  pCVar10 = CPlugFileImg::AllocatePixels((CPlugFileImg *)this,in_stack_ffffffe0);
  pGStack00000030 = (GxColor *)(float)(int)pCVar12;
  uStack00000034 = 0;
  if ((int)pCVar12 < 0) {
    pGStack00000030 = (GxColor *)((float)pGStack00000030 + _DAT_00c418d0);
  }
  fVar4 = (float)_DAT_00b33a58 / ((float)pGStack00000030 - (float)_DAT_00b2c188);
  fVar3 = ((float)pGStack00000030 - (float)_DAT_00b313b8) / (float)pGStack00000030;
  local_c = pCVar10;
  pGVar5 = _DAT_00b2c060;
  do {
    param_1 = (CPlugFileGen *)0x0;
    if (pCVar12 != (CPlugFileGen *)0x0) {
      do {
        fVar6 = (float)(int)param_1;
        if ((int)param_1 < 0) {
          fVar6 = fVar6 + _DAT_00c418d0;
        }
        pCVar15 = (CPlugFileGen *)0x0;
        pGVar2 = (GxColor *)((fVar6 * fVar4 - (float)_DAT_00b2c188) * fVar3);
        in_stack_0000002c = pGVar2;
        do {
          fVar6 = (float)(int)pCVar15;
          if ((int)pCVar15 < 0) {
            fVar6 = fVar6 + _DAT_00c418d0;
          }
          pGVar7 = (GxColor *)((fVar6 * fVar4 - (float)_DAT_00b2c188) * fVar3);
          switch(uStack00000034) {
          case 0:
            param_3 = 0x3f800000;
            param_4 = (GxColor *)-(float)pGVar2;
            param_5 = (GxColor *)-(float)pGVar7;
            break;
          case 1:
            param_4 = (GxColor *)-(float)pGVar2;
            param_3 = (ulong)pGVar5;
            param_5 = pGVar7;
            break;
          case 2:
            param_4 = (GxColor *)0x3f800000;
            param_3 = (ulong)pGVar7;
            param_5 = pGVar2;
            break;
          case 3:
            param_3 = (ulong)pGVar7;
            param_4 = pGVar5;
            param_5 = (GxColor *)-(float)pGVar2;
            break;
          case 4:
            param_5 = (GxColor *)0x3f800000;
            param_3 = (ulong)pGVar7;
            param_4 = (GxColor *)-(float)pGVar2;
            break;
          case 5:
            param_3 = (ulong)-(float)pGVar7;
            param_4 = (GxColor *)-(float)pGVar2;
            param_5 = pGVar5;
          }
          pGStack00000030 =
               (GxColor *)
               ((float)param_5 * (float)param_5 +
               (float)param_3 * (float)param_3 + (float)param_4 * (float)param_4);
          if (_DAT_00d133a0 < (float)pGStack00000030) {
            fVar14 = (float10)func_0x009c1b40();
            pGStack00000030 = (GxColor *)(1.0 / (float)fVar14);
            param_3 = (ulong)((float)pGStack00000030 * (float)param_3);
            param_4 = (GxColor *)((float)param_4 * (float)pGStack00000030);
            param_5 = (GxColor *)((float)pGStack00000030 * (float)param_5);
            pGVar2 = in_stack_0000002c;
          }
          uVar11 = *(uint *)(this + 0x24) >> 2 & 7;
          if (uVar11 == 1) {
            pGVar5 = param_5;
            if ((float)param_5 < (float)_PTR_00b2c178 != ((float)param_5 == (float)_PTR_00b2c178)) {
              pGVar5 = (GxColor *)0x0;
            }
            pGStack00000030 = (GxColor *)CONCAT22((short)((uint)pGVar5 >> 0x10),in_FPUControlWord);
            param_2._0_2_ = (undefined2)(int)ROUND((float)pGVar5 * (float)_DAT_00b52a58);
            *(undefined2 *)pCVar10 = (undefined2)param_2;
          }
          else if (uVar11 == 3) {
            CPlugFileImg::SetPixelFromNormal
                      ((CPlugFileImg *)this,pCVar10,(ushort *)&param_3,(GmVec3 *)in_stack_ffffffe4);
            pGVar2 = pGStack00000030;
          }
          else if (uVar11 == 4) {
            pGStack00000030 = (GxColor *)param_3;
            if ((float)param_3 < (float)_PTR_00b2c178 != ((float)param_3 == (float)_PTR_00b2c178)) {
              pGStack00000030 = (GxColor *)0x0;
            }
            in_stack_00000018 = *pfVar8 + (float)pGStack00000030 * (*in_stack_00000038 - *pfVar8);
            in_stack_0000001c =
                 (in_stack_00000038[1] - pfVar8[1]) * (float)pGStack00000030 + pfVar8[1];
            in_stack_00000020 =
                 (in_stack_00000038[2] - pfVar8[2]) * (float)pGStack00000030 + pfVar8[2];
            in_stack_00000024 =
                 (float *)((in_stack_00000038[3] - pfVar8[3]) * (float)pGStack00000030 + pfVar8[3]);
            GxBGRAColor::Set(local_c,(CMwCmdScriptVarBool *)&stack0x00000018,(int)in_stack_ffffffe4)
            ;
            pGVar2 = pGStack00000030;
          }
          local_c = local_c + 4;
          pCVar10 = pCVar10 + (*(uint *)(this + 0x24) >> 2 & 7) * 2;
          pCVar15 = pCVar15 + 1;
          pGVar5 = _DAT_00b2c060;
        } while (pCVar15 < pCVar12);
        param_1 = param_1 + 1;
      } while (param_1 < pCVar12);
    }
    uStack00000034 = uStack00000034 + 1;
  } while (uStack00000034 < 6);
  CMwCmdBufferCore::HighFrequencyLeaveSafeSection(DAT_00d731e0,in_stack_ffffffe4);
  return;
}
}

// =================================================
// Function: CPlugFileGen::GenHueGradient
// =================================================
/* WARNING: Removing unreachable block (ram,0x00877bd3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugFileGen::GenHueGradient
          (CPlugFileGen *this,CPlugFileGen *param_1,GmNat2 param_2,float param_3,float param_4,
          float param_5,float param_6)
{
{
  CPlugFileGen *pCVar1;
  int iVar2;
  ulonglong uVar3;
  SCasterCat SVar4;
  uint uVar5;
  SCasterCat *pSVar6;
  void *pvVar7;
  SCasterCat *pSVar8;
  GxColor *pGVar9;
  ulong unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ushort in_FPUControlWord;
  undefined3 in_stack_00000009;
  void *pvStack00000020;
  ulong in_stack_ffffff9c;
  ulong in_stack_ffffffa0;
  ulong in_stack_ffffffa4;
  ulong in_stack_ffffffa8;
  ulong in_stack_ffffffac;
  CPlugFileImg *in_stack_ffffffb0;
  ulong uVar10;
  CFastArray<class_CManoeuvre*> *in_stack_ffffffb4;
  ulong in_stack_ffffffb8;
  CFastArray<class_CFuncShader*> *in_stack_ffffffbc;
  ulong in_stack_ffffffc0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffc4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffc8;
  int iStack_34;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_28;
  SCasterCat *local_24;
  float local_20;
  CPlugFileGen *local_1c;
  CPlugFileGen *local_18;
  void *local_14;
  undefined8 local_10;
  
  local_10 = -NAN;
  local_14 = ExceptionList;
  uVar5 = DAT_00cca150 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  pCVar1 = this + 0x38;
  *(undefined4 *)(this + 0x34) = 0x15;
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (pCVar1,(CFastBuffer<class_CSystemFidsFolder*> *)0x2,uVar5);
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EDI);
  *(CPlugFileGen **)pSVar6 = param_1;
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,unaff_ESI);
  *(int *)pSVar6 = _param_2;
  CFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint>::SetCount
            (this + 0x40,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,unaff_EBX);
  pCVar1 = this + 0x48;
  CFastArray<float>::SetCount
            (pCVar1,(CFastBuffer<class_CSystemFidsFolder*> *)&DAT_00000004,in_stack_ffffff9c);
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,in_stack_ffffffa0
                     );
  *(float *)pSVar6 = param_3;
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,in_stack_ffffffa4
                     );
  *(float *)pSVar6 = param_4;
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,in_stack_ffffffa8
                     );
  *(float *)pSVar6 = param_5;
  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,in_stack_ffffffac
                     );
  *(float *)pSVar6 = param_6;
  CPlugFileImg::DeletePixels((CPlugFileImg *)this,in_stack_ffffffb0);
  iVar2 = _param_2;
  uVar5 = *(uint *)(this + 0x24) & 0xfff0fe0d | 0x800d;
  *(uint *)(this + 0x24) = uVar5;
  *(CPlugFileGen **)(this + 0x18) = param_1;
  *(int *)(this + 0x1c) = _param_2;
  pvVar7 = operator_new__((uVar5 >> 2 & 7) * _param_2 * (int)param_1);
  *(void **)(this + 0x28) = pvVar7;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(&local_20,in_stack_ffffffb4);
  pGVar9 = (GxColor *)((*(uint *)(this + 0x24) >> 2 & 7) * (int)param_1);
  pvStack00000020 = (void *)0x0;
  uVar10 = 0x877b8e;
  CFastArray<char>::SetCount
            ((CFastArray<char> *)&local_1c,(CFastBuffer<class_CSystemFidsFolder*> *)pGVar9,
             in_stack_ffffffb8);
  local_1c = param_1 + -1;
  local_20 = (float)(int)local_1c;
  if ((int)local_1c < 0) {
    local_20 = local_20 + _DAT_00c418d0;
  }
  local_28 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pSVar6 = local_24;
  if (param_1 != (CPlugFileGen *)0x0) {
    local_10 = (double)(param_6 - param_5);
    do {
      pGVar9 = (GxColor *)&stack0xfffffffc;
      uVar10 = 0x877c46;
      GxColor::SetHSV(&param_2,pGVar9,(GmVec3 *)0x3f800000,(float)in_stack_ffffffbc);
      local_18 = (CPlugFileGen *)(int)ROUND(param_5 * (float)_DAT_00b55d50);
      SVar4 = local_18._0_1_;
      in_stack_ffffffb8 = 0x877c81;
      pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                         (&local_14,local_28,in_stack_ffffffc0);
      *pSVar6 = SVar4;
      local_28 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uint)in_FPUControlWord;
      local_14 = (void *)(int)ROUND(param_5 * (float)_DAT_00b55d50);
      SVar4 = local_14._0_1_;
      in_stack_ffffffbc = (CFastArray<class_CFuncShader*> *)0x877cc1;
      pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                         (&local_10,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(local_24 + 1)
                          ,(ulong)in_stack_ffffffc4);
      *pSVar6 = SVar4;
      in_stack_ffffffc4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)local_20 + 2);
      local_24 = (SCasterCat *)CONCAT22(local_24._2_2_,in_FPUControlWord);
      uVar3 = (ulonglong)local_10 >> 0x20;
      local_10._0_1_ = SUB41((int)ROUND(param_5 * (float)_DAT_00b55d50),0);
      SVar4 = local_10._0_1_;
      in_stack_ffffffc0 = 0x877d01;
      local_10 = (double)CONCAT44((int)uVar3,(int)ROUND(param_5 * (float)_DAT_00b55d50));
      pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                         ((void *)((int)&local_10 + 4),in_stack_ffffffc4,(ulong)in_stack_ffffffc8);
      *pSVar6 = SVar4;
      local_1c = local_1c + (*(uint *)(this + 0x24) >> 2 & 7);
      local_18 = local_18 + 1;
      iVar2 = _param_2;
      pSVar6 = local_24;
    } while (local_18 < param_1);
  }
  for (; local_24 = pSVar6, iVar2 != 0; iVar2 = iVar2 + -1) {
    if (param_1 != (CPlugFileGen *)0x0) {
      local_28 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1;
      do {
        pSVar8 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                           (&local_24,in_stack_ffffffc8,uVar10);
        *pSVar6 = *pSVar8;
        pSVar8 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                           (&local_20,
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(iStack_34 + 1),
                            (ulong)pGVar9);
        pGVar9 = (GxColor *)(iVar2 + 2);
        pSVar6[1] = *pSVar8;
        uVar10 = 0x877d7f;
        pSVar8 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                           (&local_1c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar9,
                            in_stack_ffffffb8);
        pSVar6[2] = *pSVar8;
        pSVar6 = pSVar6 + (*(uint *)(this + 0x24) >> 2 & 7);
        local_28 = local_28 + -1;
      } while (local_28 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0);
    }
    pSVar6 = local_24 + (*(uint *)(this + 0x24) >> 2 & 7) * (int)param_1;
  }
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>(&local_18,in_stack_ffffffbc);
  ExceptionList = pvStack00000020;
  return;
}
}

// =================================================
// Function: CPlugFileGen::GenRenderCube
// =================================================
void __thiscall
CPlugFileGen::GenRenderCube(CPlugFileGen *this,CPlugFileGen *param_1,ulong param_2,ulong param_3)
{
{
  CPlugFileGen *this_00;
  SCasterCat *pSVar1;
  ulong unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  undefined4 in_stack_00000014;
  uint in_stack_0000001c;
  
  this_00 = this + 0x38;
  *(undefined4 *)(this + 0x34) = 6;
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)0x2,unaff_EDI);
  CFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint>::SetCount
            (this + 0x40,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,unaff_ESI);
  CFastArray<float>::SetCount(this + 0x48,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,unaff_EBX);
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_retaddr);
  *(undefined4 *)pSVar1 = in_stack_00000014;
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,(ulong)param_1);
  *(uint *)pSVar1 = in_stack_0000001c;
  CPlugFileImg::DeletePixels((CPlugFileImg *)this,(CPlugFileImg *)param_2);
  *(uint *)(this + 0x24) =
       (in_stack_0000001c & 7) * 4 | *(uint *)(this + 0x24) & 0xfff0fe02 | 0x8002;
  *(undefined4 *)(this + 0x18) = in_stack_00000014;
  *(undefined4 *)(this + 0x1c) = in_stack_00000014;
  return;
}
}

// =================================================
// Function: CPlugFileGen::GenSLGradient
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugFileGen::GenSLGradient(CPlugFileGen *this,CPlugFileGen *param_1,GmNat2 param_2,float param_3)
{
{
  CPlugFileGen *this_00;
  float fVar1;
  float fVar2;
  SCasterCat *pSVar3;
  uint uVar4;
  float fVar5;
  ulong unaff_EBX;
  ulong unaff_EBP;
  float fVar6;
  ulong unaff_ESI;
  ulong unaff_EDI;
  GxColor *pGVar7;
  undefined2 in_FPUControlWord;
  float in_stack_00000010;
  float in_stack_00000014;
  float in_stack_00000018;
  float in_stack_00000024;
  ulong in_stack_ffffffc8;
  ulong in_stack_ffffffcc;
  CPlugFileImg *in_stack_ffffffd0;
  float in_stack_ffffffd4;
  undefined4 local_18;
  
  this_00 = this + 0x38;
  *(undefined4 *)(this + 0x34) = 0x16;
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)0x2,unaff_EDI);
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  fVar2 = param_3;
  *(float *)pSVar3 = param_3;
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,unaff_EBP);
  fVar6 = in_stack_00000014;
  *(float *)pSVar3 = in_stack_00000014;
  CFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint>::SetCount
            (this + 0x40,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,unaff_EBX);
  CFastArray<float>::SetCount
            (this + 0x48,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,in_stack_ffffffc8);
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x48,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      in_stack_ffffffcc);
  *(float *)pSVar3 = in_stack_00000024;
  CPlugFileImg::DeletePixels((CPlugFileImg *)this,in_stack_ffffffd0);
  uVar4 = *(uint *)(this + 0x24) & 0xfff0fe0d | 0x800d;
  *(uint *)(this + 0x24) = uVar4;
  *(float *)(this + 0x18) = fVar2;
  *(float *)(this + 0x1c) = fVar6;
  local_18 = operator_new__((uVar4 >> 2 & 7) * (int)fVar6 * (int)fVar2);
  *(GxColor **)(this + 0x28) = local_18;
  fVar1 = (float)((int)fVar6 + -1);
  if ((int)fVar6 + -1 < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  fVar5 = 0.0;
  if (fVar6 != 0.0) {
    do {
      fVar6 = 0.0;
      pGVar7 = local_18;
      if (fVar2 != 0.0) {
        do {
          GxColor::SetHSV(&param_3,(GxColor *)&stack0x00000000,(GmVec3 *)0x3f800000,
                          in_stack_ffffffd4);
          fVar5 = (float)_DAT_00b55d50;
          fVar6 = (float)((int)fVar6 + 1);
          *pGVar7 = SUB41((int)ROUND(in_stack_00000018 * fVar5),0);
          pGVar7[1] = SUB41((int)ROUND(in_stack_00000014 * fVar5),0);
          local_18 = (GxColor *)CONCAT22(in_FPUControlWord,(undefined2)local_18);
          pGVar7[2] = SUB41((int)ROUND(fVar5 * in_stack_00000010),0);
          fVar5 = fVar1;
          pGVar7 = pGVar7 + (*(uint *)(this + 0x24) >> 2 & 7);
        } while ((uint)fVar6 < (uint)fVar2);
      }
      local_18 = local_18 + (*(uint *)(this + 0x24) >> 2 & 7) * (int)fVar2;
      fVar5 = (float)((int)fVar5 + 1);
    } while ((uint)fVar5 < (uint)in_stack_00000024);
  }
  return;
}
}

// =================================================
// Function: CPlugFileGen::GenSpecularCubeVect
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugFileGen::GenSpecularCubeVect
          (CPlugFileGen *this,CPlugFileGen *param_1,GmVec3 *param_2,ulong param_3,float param_4)
{
{
  CPlugFileGen *this_00;
  float fVar1;
  float fVar2;
  float fVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBX;
  ulong unaff_EBP;
  undefined1 *puVar5;
  ulong unaff_ESI;
  ulong unaff_EDI;
  uint uVar6;
  undefined2 in_FPUControlWord;
  float10 fVar7;
  uint in_stack_00000014;
  float fStack00000018;
  undefined1 uStack0000001c;
  float in_stack_00000020;
  float in_stack_00000024;
  float in_stack_00000028;
  float *in_stack_00000030;
  float fStack00000034;
  ulong in_stack_ffffffdc;
  ulong in_stack_ffffffe0;
  ulong in_stack_ffffffe4;
  ulong in_stack_ffffffe8;
  float fVar8;
  CPlugFileImg *in_stack_fffffff0;
  CPlugFileImg *pCVar9;
  CMwCmdBufferCore *pCVar10;
  
  pCVar10 = *(CMwCmdBufferCore **)(param_1 + 4);
  pCVar9 = *(CPlugFileImg **)param_1;
  fVar8 = *(float *)(param_1 + 8) * *(float *)(param_1 + 8) +
          (float)pCVar9 * (float)pCVar9 + (float)pCVar10 * (float)pCVar10;
  if (_DAT_00d133a0 < fVar8) {
    fVar7 = (float10)func_0x009c1b40();
    fVar8 = 1.0 / (float)fVar7;
    pCVar9 = (CPlugFileImg *)(fVar8 * (float)pCVar9);
    pCVar10 = (CMwCmdBufferCore *)(fVar8 * (float)pCVar10);
  }
  CMwCmdBufferCore::HighFrequencyEnterSafeSection(DAT_00d731e0,(CMwCmdBufferCore *)0x1,unaff_EDI);
  *(undefined4 *)(this + 0x34) = 0x18;
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (this + 0x38,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_ESI);
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBP);
  *(uint *)pSVar4 = in_stack_00000014;
  CFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint>::SetCount
            (this + 0x40,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,unaff_EBX);
  this_00 = this + 0x48;
  CFastArray<float>::SetCount
            (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)&DAT_00000004,in_stack_ffffffdc);
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      in_stack_ffffffe0);
  *(ulong *)pSVar4 = param_3;
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                      in_stack_ffffffe4);
  *(uint *)pSVar4 = in_stack_00000014;
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                      in_stack_ffffffe8);
  *(undefined4 *)pSVar4 = _uStack0000001c;
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,(ulong)fVar8);
  *(float **)pSVar4 = in_stack_00000030;
  CPlugFileImg::DeletePixels((CPlugFileImg *)this,in_stack_fffffff0);
  *(uint *)(this + 0x24) = *(uint *)(this + 0x24) & 0xfff0fe06 | 0x8006;
  *(uint *)(this + 0x18) = in_stack_00000014;
  *(uint *)(this + 0x1c) = in_stack_00000014;
  CPlugFileImg::AllocatePixels((CPlugFileImg *)this,pCVar9);
  puVar5 = *(undefined1 **)(this + 0x28);
  fStack00000034 = (float)(int)in_stack_00000014;
  param_2 = (GmVec3 *)0x0;
  if ((int)in_stack_00000014 < 0) {
    fStack00000034 = fStack00000034 + _DAT_00c418d0;
  }
  fVar8 = (float)_DAT_00b33a58 / (fStack00000034 - (float)_DAT_00b2c188);
  fStack00000018 = (fStack00000034 - (float)_DAT_00b313b8) / fStack00000034;
  fVar1 = _DAT_00b2c060;
  do {
    param_3 = 0;
    if (in_stack_00000014 != 0) {
      do {
        fVar2 = (float)(int)param_3;
        if ((int)param_3 < 0) {
          fVar2 = fVar2 + _DAT_00c418d0;
        }
        uVar6 = 0;
        fVar2 = (fVar2 * fVar8 - (float)_DAT_00b2c188) * fStack00000018;
        do {
          fVar3 = (float)(int)uVar6;
          if ((int)uVar6 < 0) {
            fVar3 = fVar3 + _DAT_00c418d0;
          }
          fVar3 = (fVar3 * fVar8 - (float)_DAT_00b2c188) * fStack00000018;
          switch(param_2) {
          case (GmVec3 *)0x0:
            in_stack_00000020 = 1.0;
            in_stack_00000024 = -fVar2;
            in_stack_00000028 = -fVar3;
            break;
          case (GmVec3 *)0x1:
            in_stack_00000024 = -fVar2;
            in_stack_00000020 = fVar1;
            in_stack_00000028 = fVar3;
            break;
          case (GmVec3 *)0x2:
            in_stack_00000024 = 1.0;
            in_stack_00000020 = fVar3;
            in_stack_00000028 = fVar2;
            break;
          case (GmVec3 *)0x3:
            in_stack_00000020 = fVar3;
            in_stack_00000024 = fVar1;
            in_stack_00000028 = -fVar2;
            break;
          case (GmVec3 *)0x4:
            in_stack_00000028 = 1.0;
            in_stack_00000020 = fVar3;
            in_stack_00000024 = -fVar2;
            break;
          case (GmVec3 *)0x5:
            in_stack_00000020 = -fVar3;
            in_stack_00000024 = -fVar2;
            in_stack_00000028 = fVar1;
          }
          fStack00000034 =
               in_stack_00000028 * in_stack_00000028 +
               in_stack_00000024 * in_stack_00000024 + in_stack_00000020 * in_stack_00000020;
          if (_DAT_00d133a0 < fStack00000034) {
            fVar7 = (float10)func_0x009c1b40();
            fVar1 = 1.0 / (float)fVar7;
            in_stack_00000020 = fVar1 * in_stack_00000020;
            in_stack_00000024 = in_stack_00000024 * fVar1;
            in_stack_00000028 = fVar1 * in_stack_00000028;
          }
          fStack00000034 =
               in_stack_00000028 * in_stack_00000030[2] +
               in_stack_00000030[1] * in_stack_00000024 + *in_stack_00000030 * in_stack_00000020;
          if (fStack00000034 < (float)_PTR_00b2c178 != (fStack00000034 == (float)_PTR_00b2c178)) {
            fStack00000034 = 0.0;
          }
          fVar7 = (float10)func_0x009c2390();
          fStack00000034 = (float)fVar7 * (float)_DAT_00b55d50;
          if (fStack00000034 < 0.0 == (fStack00000034 == 0.0)) {
            if ((float)_DAT_00b55d50 <= fStack00000034) {
              fStack00000034 = _DAT_00b5e844;
            }
          }
          else {
            fStack00000034 = 0.0;
          }
          fVar1 = fStack00000034;
          uVar6 = uVar6 + 1;
          fStack00000034 = (float)CONCAT22(fStack00000034._2_2_,in_FPUControlWord);
          uStack0000001c = (undefined1)(int)ROUND(fVar1);
          *puVar5 = uStack0000001c;
          puVar5 = puVar5 + (*(uint *)(this + 0x24) >> 2 & 7);
          fVar1 = _DAT_00b2c060;
        } while (uVar6 < in_stack_00000014);
        param_3 = param_3 + 1;
      } while (param_3 < in_stack_00000014);
    }
    param_2 = param_2 + 1;
  } while (param_2 < (GmVec3 *)&DAT_00000006);
  CMwCmdBufferCore::HighFrequencyLeaveSafeSection(DAT_00d731e0,pCVar10);
  return;
}
}

// =================================================
// Function: CPlugFileGen::GenSpecularCubeVectRgb
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugFileGen::GenSpecularCubeVectRgb
          (CPlugFileGen *this,CPlugFileGen *param_1,GmVec3 *param_2,GmVec3 *param_3,ulong param_4,
          float param_5)
{
{
  CPlugFileGen *pCVar1;
  float fVar2;
  float fVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBX;
  ulong unaff_EBP;
  float fVar5;
  ulong unaff_ESI;
  undefined1 *puVar6;
  ulong unaff_EDI;
  float10 fVar7;
  CMwCmdBufferCore *unaff_retaddr;
  float in_stack_00000018;
  float *in_stack_0000001c;
  float fStack00000020;
  undefined1 uStack00000024;
  float in_stack_00000028;
  float in_stack_0000002c;
  float in_stack_00000030;
  undefined4 in_stack_0000003c;
  float in_stack_00000040;
  ulong in_stack_ffffffdc;
  ulong in_stack_ffffffe0;
  ulong in_stack_ffffffe4;
  ulong in_stack_ffffffe8;
  float fVar8;
  ulong in_stack_fffffff0;
  float fVar9;
  CPlugFileImg *pCVar10;
  CPlugFileImg *pCVar11;
  
  pCVar10 = *(CPlugFileImg **)(param_1 + 4);
  fVar9 = *(float *)param_1;
  pCVar11 = *(CPlugFileImg **)(param_1 + 8);
  fVar8 = (float)pCVar11 * (float)pCVar11 + fVar9 * fVar9 + (float)pCVar10 * (float)pCVar10;
  if (_DAT_00d133a0 < fVar8) {
    fVar7 = (float10)func_0x009c1b40();
    fVar8 = 1.0 / (float)fVar7;
    fVar9 = fVar8 * fVar9;
    pCVar10 = (CPlugFileImg *)(fVar8 * (float)pCVar10);
    pCVar11 = (CPlugFileImg *)(fVar8 * (float)pCVar11);
  }
  CMwCmdBufferCore::HighFrequencyEnterSafeSection(DAT_00d731e0,(CMwCmdBufferCore *)0x1,unaff_EDI);
  *(undefined4 *)(this + 0x34) = 0x1a;
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (this + 0x38,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_ESI);
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBP);
  pCVar1 = this + 0x40;
  *(float *)pSVar4 = in_stack_00000018;
  CFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint>::SetCount
            (pCVar1,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_EBX);
  pSVar4 = CFastBuffer<class_GxColor>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,in_stack_ffffffdc
                     );
  *(float *)pSVar4 = *in_stack_0000001c;
  *(float *)(pSVar4 + 4) = in_stack_0000001c[1];
  *(float *)(pSVar4 + 8) = in_stack_0000001c[2];
  pSVar4 = CFastBuffer<class_GxColor>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,in_stack_ffffffe0
                     );
  pCVar1 = this + 0x48;
  *(undefined4 *)(pSVar4 + 0xc) = 0x3f800000;
  CFastArray<float>::SetCount
            (pCVar1,(CFastBuffer<class_CSystemFidsFolder*> *)&DAT_00000004,in_stack_ffffffe4);
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,in_stack_ffffffe8
                     );
  *(float *)pSVar4 = param_5;
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,(ulong)fVar8);
  *(float **)pSVar4 = in_stack_0000001c;
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,in_stack_fffffff0
                     );
  *(undefined4 *)pSVar4 = _uStack00000024;
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,(ulong)fVar9);
  *(undefined4 *)pSVar4 = in_stack_0000003c;
  CPlugFileImg::DeletePixels((CPlugFileImg *)this,pCVar10);
  *(uint *)(this + 0x24) = *(uint *)(this + 0x24) & 0xfff0fe0e | 0x800e;
  *(float *)(this + 0x18) = in_stack_00000018;
  *(float *)(this + 0x1c) = in_stack_00000018;
  CPlugFileImg::AllocatePixels((CPlugFileImg *)this,pCVar11);
  puVar6 = *(undefined1 **)(this + 0x28);
  fStack00000020 = (float)(int)in_stack_00000018;
  param_4 = 0;
  if ((int)in_stack_00000018 < 0) {
    fStack00000020 = fStack00000020 + _DAT_00c418d0;
  }
  fVar9 = (float)_DAT_00b33a58 / (fStack00000020 - (float)_DAT_00b2c188);
  fStack00000020 = (fStack00000020 - (float)_DAT_00b313b8) / fStack00000020;
  fVar8 = _DAT_00b2c060;
  do {
    param_5 = 0.0;
    if (in_stack_00000018 != 0.0) {
      do {
        fVar2 = (float)(int)param_5;
        if ((int)param_5 < 0) {
          fVar2 = fVar2 + _DAT_00c418d0;
        }
        fVar5 = 0.0;
        fVar2 = (fVar2 * fVar9 - (float)_DAT_00b2c188) * fStack00000020;
        do {
          fVar3 = (float)(int)fVar5;
          if ((int)fVar5 < 0) {
            fVar3 = fVar3 + _DAT_00c418d0;
          }
          fVar3 = (fVar3 * fVar9 - (float)_DAT_00b2c188) * fStack00000020;
          switch(param_4) {
          case 0:
            in_stack_00000028 = 1.0;
            in_stack_0000002c = -fVar2;
            in_stack_00000030 = -fVar3;
            break;
          case 1:
            in_stack_0000002c = -fVar2;
            in_stack_00000028 = fVar8;
            in_stack_00000030 = fVar3;
            break;
          case 2:
            in_stack_0000002c = 1.0;
            in_stack_00000028 = fVar3;
            in_stack_00000030 = fVar2;
            break;
          case 3:
            in_stack_00000028 = fVar3;
            in_stack_0000002c = fVar8;
            in_stack_00000030 = -fVar2;
            break;
          case 4:
            in_stack_00000030 = 1.0;
            in_stack_00000028 = fVar3;
            in_stack_0000002c = -fVar2;
            break;
          case 5:
            in_stack_00000028 = -fVar3;
            in_stack_0000002c = -fVar2;
            in_stack_00000030 = fVar8;
          }
          if (_DAT_00d133a0 <
              in_stack_00000030 * in_stack_00000030 +
              in_stack_0000002c * in_stack_0000002c + in_stack_00000028 * in_stack_00000028) {
            fVar7 = (float10)func_0x009c1b40();
            fVar8 = 1.0 / (float)fVar7;
            in_stack_00000028 = fVar8 * in_stack_00000028;
            in_stack_0000002c = fVar8 * in_stack_0000002c;
            in_stack_00000030 = fVar8 * in_stack_00000030;
          }
          fVar7 = (float10)func_0x009c2390();
          fVar5 = (float)((int)fVar5 + 1);
          fVar8 = (float)((int)ROUND((float)fVar7 * (float)_DAT_00b55d50) & 0xff);
          uStack00000024 = (undefined1)(int)ROUND(fVar8 * in_stack_0000001c[2]);
          *puVar6 = uStack00000024;
          uStack00000024 = (undefined1)(int)ROUND(fVar8 * in_stack_0000001c[1]);
          puVar6[1] = uStack00000024;
          uStack00000024 = (undefined1)(int)ROUND(fVar8 * *in_stack_0000001c);
          puVar6[2] = uStack00000024;
          puVar6 = puVar6 + (*(uint *)(this + 0x24) >> 2 & 7);
          fVar8 = _DAT_00b2c060;
        } while ((uint)fVar5 < (uint)in_stack_00000040);
        param_5 = (float)((int)param_5 + 1);
        in_stack_00000018 = in_stack_00000040;
      } while ((uint)param_5 < (uint)in_stack_00000040);
    }
    param_4 = param_4 + 1;
  } while (param_4 < 6);
  CMwCmdBufferCore::HighFrequencyLeaveSafeSection(DAT_00d731e0,unaff_retaddr);
  return;
}
}

