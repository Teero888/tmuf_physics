// Class implementation: CDx9VisualKeeper

// =================================================
// Function: CDx9VisualKeeper::LoadStaticGeometry
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CDx9VisualKeeper::LoadStaticGeometry(CDx9VisualKeeper *this,CDx9VisualKeeper *param_1,ulong param_2)
{
{
  uchar **ppuVar1;
  int iVar2;
  undefined4 uVar3;
  uint *this_00;
  CDx9VisualKeeper *pCVar4;
  byte bVar5;
  undefined2 extraout_AX;
  undefined2 extraout_AX_00;
  undefined2 extraout_AX_01;
  undefined2 extraout_AX_02;
  undefined2 extraout_AX_03;
  undefined2 extraout_AX_04;
  undefined2 extraout_AX_05;
  undefined2 extraout_AX_06;
  undefined2 extraout_AX_07;
  int iVar6;
  SCasterCat *pSVar7;
  ulong uVar8;
  SNormalDec3N *pSVar9;
  undefined4 *puVar10;
  uint extraout_EAX;
  int extraout_EAX_00;
  uint extraout_EAX_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  uint extraout_EAX_02;
  int extraout_EAX_03;
  uint extraout_EAX_04;
  int iVar12;
  GxVertex *unaff_EBP;
  SNormalDec3N *pSVar13;
  uchar **unaff_ESI;
  uint uVar14;
  uint uVar15;
  GxVertex2 *pGVar16;
  uint *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar17;
  uint uVar18;
  GmVec3 *pGVar19;
  SStreamDecl *pSVar20;
  CFastBuffer<class_CCrystalFace*> *pCVar21;
  uint *puStack_74;
  uint *puStack_70;
  GxVertex *pGVar22;
  uint uStack_5c;
  int iStack_58;
  int iStack_54;
  undefined4 uStack_50;
  SNormalDec3N *pSStack_4c;
  SNormalDec3N *pSStack_48;
  CDx9VisualKeeper *pCStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  CDx9VisualKeeper *local_30;
  float fStack_2c;
  SNormalDec3N *pSStack_28;
  uint uStack_24;
  uchar **ppuStack_20;
  GxVertex *pGStack_1c;
  int iStack_18;
  CDx9VisualKeeper *pCStack_10;
  ulong uStack_c;
  int *piStack_4;
  
  puStack_70 = (uint *)0x97833a;
  local_30 = this;
  iVar6 = (**(code **)(**(int **)(this + 4) + 0xb8))();
  piStack_4 = *(int **)(this + (*(int *)(this + 0x98) + 4) * 0xc);
  puStack_70 = (uint *)0x0;
  puStack_74 = &uStack_5c;
  pCVar21 = (CFastBuffer<class_CCrystalFace*> *)piStack_4[5];
  (**(code **)(*(int *)pCVar21 + 0x2c))
            (pCVar21,*(int *)(this + (*(int *)(this + 0x98) + 4) * 0xc + 4) * *piStack_4,
             *piStack_4 * iVar6);
  bVar5 = (byte)this[0xe] & 0x3f;
  if (bVar5 == 7) {
    iVar6 = *(int *)(this + 4);
    pGVar19 = (GmVec3 *)0x97838a;
    uStack_c = CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar6 + 0x78),pCVar21);
    pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (uStack_c != 0) {
      do {
        pSVar7 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                           ((void *)(iVar6 + 0x78),pCVar17,(ulong)pGVar19);
        *unaff_EDI = *(uint *)pSVar7;
        pGVar19 = (GmVec3 *)(pSVar7 + 0x18);
        unaff_EDI[1] = *(uint *)(pSVar7 + 4);
        unaff_EDI[2] = *(uint *)(pSVar7 + 8);
        unaff_EDI[3] = *(uint *)(pSVar7 + 0xc);
        uVar8 = GetDx9Color(pGVar19,(float)pCVar21);
        unaff_EDI[4] = uVar8;
        pCVar17 = pCVar17 + 1;
        unaff_EDI = puStack_70 + 5;
        puStack_70 = unaff_EDI;
      } while (pCVar17 < pCStack_10);
    }
  }
  else if (bVar5 == 8) {
    iVar6 = *(int *)(this + 4);
    uStack_40 = *(uint *)(iVar6 + 0x98);
    ppuVar1 = *(uchar ***)(iVar6 + 0x7c);
    uVar14 = 0;
    if (uStack_40 != 0) {
      pCStack_10 = this + (int)pCStack_10 * 4 + 0x14;
      do {
        iVar2 = *(int *)(iVar6 + 0x9c);
        iVar12 = 2;
        do {
          RecordVertex3InVB(pCStack_44,(CLoadGeomVertexGen<671098945> *)&puStack_70,ppuVar1,
                            (GxVertex *)(iVar2 + uVar14),(ulong)pCStack_10);
          iVar2 = *(int *)(iVar6 + 0xa0);
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
        uVar14 = uVar14 + 1;
        this = pCStack_44;
      } while (uVar14 < uStack_40);
    }
  }
  else if (bVar5 < 0xb) {
    iStack_54 = (**(code **)(**(int **)(this + 4) + 0x8c))();
    while (iStack_54 != -1) {
      (**(code **)(**(int **)(this + 4) + 0x90))(&iStack_54,&stack0xffffff9c,&stack0xffffff98);
      uVar14 = *(uint *)(this + (int)pCStack_10 * 4 + 0x14);
      if (uVar14 == 0x841) {
        pSStack_48 = *(SNormalDec3N **)(this + 4);
        CLoadGeomVertexGen<2113>::RecordVertex3InVB
                  (&pSStack_48,(CLoadGeomVertexGen<671098945> *)&puStack_70,unaff_ESI,unaff_EBP,
                   (ulong)pCVar21);
      }
      else if (uVar14 == 0x28002841) {
        pSStack_48 = *(SNormalDec3N **)(this + 4);
        CLoadGeomVertexGen<671098945>::RecordVertex3InVB
                  (&pSStack_48,(CLoadGeomVertexGen<671098945> *)&puStack_70,unaff_ESI,unaff_EBP,
                   (ulong)pCVar21);
      }
      else {
        uStack_5c = *(uint *)(this + 4);
        pGVar22 = (GxVertex *)0x0;
        if (unaff_EBP != (GxVertex *)0x0) {
          local_30 = (CDx9VisualKeeper *)(uVar14 >> 9 & 1);
          uStack_24 = uVar14 >> 0x1b & 1;
          iStack_58 = 0;
          pSStack_48 = (SNormalDec3N *)0x0;
          uStack_38 = uVar14 & 1;
          uStack_34 = uVar14 >> 5 & 1;
          uStack_3c = uVar14 >> 6 & 1;
          ppuStack_20 = (uchar **)(uVar14 >> 0x1d & 1);
          pSVar13 = (SNormalDec3N *)(unaff_ESI + 3);
          pGStack_1c = unaff_EBP;
          do {
            if (uStack_38 != 0) {
              *puStack_70 = *(uint *)(pSVar13 + -0xc);
              puStack_70[1] = *(uint *)(pSVar13 + -8);
              puStack_70[2] = *(uint *)(pSVar13 + -4);
              puStack_70 = puStack_70 + 3;
            }
            if (uStack_34 != 0) {
              switch(uVar14 >> 3 & 3) {
              case 0:
                *puStack_70 = (uint)(byte)pGVar22[*(int *)(*(int *)(uStack_5c + 0x50) + 4)];
                goto LAB_009786a6;
              case 1:
                iVar6 = *(int *)(*(int *)(uStack_5c + 0x50) + 4);
                *puStack_70 = *(uint *)(iVar6 + 4 + (int)pGVar22 * 8);
                puStack_70 = puStack_70 + 1;
                uVar15 = (uint)*(ushort *)(iVar6 + (int)pGVar22 * 8);
                goto LAB_009786a4;
              case 2:
                pSVar9 = (SNormalDec3N *)(*(int *)(*(int *)(uStack_5c + 0x50) + 4) + iStack_58);
                *puStack_70 = *(uint *)(pSVar9 + 4);
                puStack_70[1] = *(uint *)(pSVar9 + 8);
                puStack_70 = puStack_70 + 2;
                uVar15 = (uint)*(ushort *)(pSVar9 + 1);
                break;
              case 3:
                pSVar9 = pSStack_48 + *(int *)(*(int *)(uStack_5c + 0x50) + 4);
                *puStack_70 = *(uint *)(pSVar9 + 4);
                puStack_70[1] = *(uint *)(pSVar9 + 8);
                puStack_70[2] = *(uint *)(pSVar9 + 0xc);
                puStack_70 = puStack_70 + 3;
                uVar15 = (uint)*(uint3 *)(pSVar9 + 1);
                break;
              default:
                goto switchD_009785d7_default;
              }
              uVar15 = uVar15 << 8 | (uint)(byte)*pSVar9;
LAB_009786a4:
              *puStack_70 = uVar15;
LAB_009786a6:
              puStack_70 = puStack_70 + 1;
            }
switchD_009785d7_default:
            this_00 = puStack_70;
            pSStack_4c = pSVar13;
            if (uStack_3c != 0) {
              if ((int)uVar14 < 0) {
                if (DAT_00d77b08 != 0) {
                  if (DAT_00d77b08 == 1) {
                    puStack_70 = puStack_70 + 2;
                    __ftol2_sse();
                    *(undefined2 *)this_00 = extraout_AX;
                    __ftol2_sse();
                    *(undefined2 *)((int)this_00 + 2) = extraout_AX_00;
                    __ftol2_sse();
                    *(undefined2 *)(this_00 + 1) = extraout_AX_01;
                    *(undefined2 *)((int)this_00 + 6) = 0;
                  }
                  else if (DAT_00d77b08 == 2) {
                    puStack_70 = puStack_70 + 1;
                    SNormalDec3N::operator=(this_00,pSVar13,(GmVec3 *)pCVar21);
                  }
                  goto LAB_0097875b;
                }
                *puStack_70 = *(uint *)pSVar13;
                puStack_70[1] = *(uint *)(pSVar13 + 4);
                puStack_70[2] = *(uint *)(pSVar13 + 8);
              }
              else {
                *puStack_70 = *(uint *)pSVar13;
                puStack_70[1] = *(uint *)(pSVar13 + 4);
                puStack_70[2] = *(uint *)(pSVar13 + 8);
              }
              puStack_70 = puStack_70 + 3;
            }
LAB_0097875b:
            if (local_30 != (CDx9VisualKeeper *)0x0) {
              pSStack_28 = pSVar13 + 0xc;
              fStack_2c = _DAT_00b5e844;
              uStack_50 = CONCAT22((short)ROUND(*(float *)pSStack_28 * _DAT_00b5e844),
                                   (short)ROUND(*(float *)(pSVar13 + 0x14) * _DAT_00b5e844));
              uStack_40 = CONCAT22((short)ROUND(*(float *)(pSVar13 + 0x18) * _DAT_00b5e844),
                                   (short)ROUND(*(float *)(pSVar13 + 0x10) * _DAT_00b5e844));
              uStack_50 = uStack_50 | uStack_40 << 8;
              *puStack_70 = uStack_50;
              puStack_70 = puStack_70 + 1;
            }
            pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            uVar18 = 0;
            uVar15 = uVar14;
            do {
              uVar15 = (uVar15 >> ((byte)uVar18 & 0x1f)) >> 0xb & 3;
              if (uVar15 == 0) break;
              pSVar7 = CFastBuffer<struct_SFastCat>::operator[]
                                 ((void *)(uStack_5c + 0x5c),pCVar17,(ulong)pCVar21);
              if ((uVar15 == 1) || (uVar15 != 2)) {
                uVar3 = *(undefined4 *)(*(int *)(pSVar7 + 4) + 4 + (int)unaff_ESI * 8);
                *(undefined4 *)pGVar22 = *(undefined4 *)(*(int *)(pSVar7 + 4) + (int)unaff_ESI * 8);
                *(undefined4 *)(pGVar22 + 4) = uVar3;
                pGVar22 = pGVar22 + 8;
              }
              else {
                puVar10 = (undefined4 *)(*(int *)(pSVar7 + 4) + iStack_54);
                *(undefined4 *)pGVar22 = *puVar10;
                *(undefined4 *)(pGVar22 + 4) = puVar10[1];
                *(undefined4 *)(pGVar22 + 8) = puVar10[2];
                pGVar22 = pGVar22 + 0xc;
              }
              uVar18 = uVar18 + 2;
              pCVar17 = pCVar17 + 1;
              uVar15 = uStack_5c;
            } while (uVar18 < 0x10);
            pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar22;
            if (uStack_24 != 0) {
              pSVar7 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                                 ((void *)(uStack_5c + 0x84),
                                  (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar22,
                                  (ulong)pCVar21);
              if ((uStack_5c & 0x80000000) == 0) {
                *(undefined4 *)pGVar22 = *(undefined4 *)pSVar7;
                *(undefined4 *)(pGVar22 + 4) = *(undefined4 *)(pSVar7 + 4);
                *(undefined4 *)(pGVar22 + 8) = *(undefined4 *)(pSVar7 + 8);
              }
              else {
                if (DAT_00d77b08 != 0) {
                  if (DAT_00d77b08 == 1) {
                    pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(pGVar22 + 8);
                    __ftol2_sse();
                    *(undefined2 *)pGVar22 = extraout_AX_02;
                    __ftol2_sse();
                    *(undefined2 *)(pGVar22 + 2) = extraout_AX_03;
                    pCVar21 = (CFastBuffer<class_CCrystalFace*> *)0x978924;
                    __ftol2_sse();
                    *(undefined2 *)(pGVar22 + 4) = extraout_AX_04;
                    *(undefined2 *)(pGVar22 + 6) = 0;
                  }
                  else if (DAT_00d77b08 == 2) {
                    pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(pGVar22 + 4);
                    __ftol2_sse();
                    *(uint *)pGVar22 = *(uint *)pGVar22 ^ (extraout_EAX ^ *(uint *)pGVar22) & 0x3ff;
                    uVar15 = *(uint *)pGVar22;
                    __ftol2_sse();
                    uVar15 = (extraout_EAX_00 << 10 ^ uVar15) & 0xffc00 ^ uVar15;
                    *(uint *)pGVar22 = uVar15;
                    pCVar21 = (CFastBuffer<class_CCrystalFace*> *)0x9788d5;
                    __ftol2_sse();
                    *(uint *)pGVar22 = (extraout_EAX_01 & 0x3ff) << 0x14 | uVar15 & 0xfffff;
                    pSVar13 = pSStack_48;
                  }
                  goto LAB_0097895f;
                }
                *(undefined4 *)pGVar22 = *(undefined4 *)pSVar7;
                *(undefined4 *)(pGVar22 + 4) = *(undefined4 *)(pSVar7 + 4);
                *(undefined4 *)(pGVar22 + 8) = *(undefined4 *)(pSVar7 + 8);
              }
              pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(pGVar22 + 0xc);
            }
LAB_0097895f:
            pCVar11 = pCVar17;
            if (ppuStack_20 != (uchar **)0x0) {
              pSVar7 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                                 ((void *)(uStack_5c + 0x8c),pCVar17,(ulong)pCVar21);
              if ((uStack_5c & 0x80000000) == 0) {
                *(undefined4 *)pCVar17 = *(undefined4 *)pSVar7;
                *(undefined4 *)(pCVar17 + 4) = *(undefined4 *)(pSVar7 + 4);
                *(undefined4 *)(pCVar17 + 8) = *(undefined4 *)(pSVar7 + 8);
              }
              else {
                if (DAT_00d77b08 != 0) {
                  if (DAT_00d77b08 == 1) {
                    pCVar11 = pCVar17 + 8;
                    __ftol2_sse();
                    *(undefined2 *)pCVar17 = extraout_AX_05;
                    __ftol2_sse();
                    *(undefined2 *)(pCVar17 + 2) = extraout_AX_06;
                    pCVar21 = (CFastBuffer<class_CCrystalFace*> *)0x978a45;
                    __ftol2_sse();
                    *(undefined2 *)(pCVar17 + 4) = extraout_AX_07;
                    *(undefined2 *)(pCVar17 + 6) = 0;
                  }
                  else if (DAT_00d77b08 == 2) {
                    pCVar11 = pCVar17 + 4;
                    __ftol2_sse();
                    *(uint *)pCVar17 =
                         *(uint *)pCVar17 ^ (extraout_EAX_02 ^ *(uint *)pCVar17) & 0x3ff;
                    uVar15 = *(uint *)pCVar17;
                    __ftol2_sse();
                    uVar15 = (extraout_EAX_03 << 10 ^ uVar15) & 0xffc00 ^ uVar15;
                    *(uint *)pCVar17 = uVar15;
                    pCVar21 = (CFastBuffer<class_CCrystalFace*> *)0x9789f6;
                    __ftol2_sse();
                    *(uint *)pCVar17 = (extraout_EAX_04 & 0x3ff) << 0x14 | uVar15 & 0xfffff;
                    pSVar13 = pSStack_48;
                  }
                  goto LAB_00978a80;
                }
                *(undefined4 *)pCVar17 = *(undefined4 *)pSVar7;
                *(undefined4 *)(pCVar17 + 4) = *(undefined4 *)(pSVar7 + 4);
                *(undefined4 *)(pCVar17 + 8) = *(undefined4 *)(pSVar7 + 8);
              }
              pCVar11 = pCVar17 + 0xc;
            }
LAB_00978a80:
            pSStack_48 = pSStack_48 + 0x10;
            iStack_58 = iStack_58 + 0xc;
            pGVar22 = (GxVertex *)(pCVar11 + 1);
            pSVar13 = pSVar13 + 0x28;
            this = pCStack_44;
            pSStack_4c = pSVar13;
          } while (pGVar22 < pGStack_1c);
        }
      }
    }
  }
  else {
    uStack_40 = (**(code **)(**(int **)(this + 4) + 0xb0))();
    pCVar4 = pCStack_10;
    while (uStack_40 != 0xffffffff) {
      pSVar20 = (SStreamDecl *)&pGStack_1c;
      (**(code **)(**(int **)(this + 4) + 0xb4))(&uStack_40,&pCStack_10);
      pGVar16 = (GxVertex2 *)0x0;
      if (pCStack_10 != (CDx9VisualKeeper *)0x0) {
        do {
          RecordVertex2InVB(this,(CDx9VisualKeeper *)&puStack_74,ppuStack_20,pGVar16,
                            (ulong)(this + (int)pCVar4 * 4 + 0x14),pSVar20);
          pGVar16 = pGVar16 + 1;
        } while (pGVar16 < pCStack_10);
      }
    }
  }
  (**(code **)(**(int **)(iStack_18 + 0x14) + 0x30))(*(int **)(iStack_18 + 0x14));
  uVar14 = *(uint *)(*(int *)(this + 4) + 0x1c);
  if ((uVar14 & 0x10) != 0) {
    *(uint *)(*(int *)(this + 4) + 0x1c) = uVar14 & 0xffffffef;
  }
  return;
}
}

// =================================================
// Function: CDx9VisualKeeper::PackStaticGeometry
// =================================================
void __cdecl CDx9VisualKeeper::PackStaticGeometry(void)
{
{
  int *piVar1;
  int *this;
  int *this_00;
  void *this_01;
  CDx9VisualKeeper *this_02;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  SSamplerState *pSVar4;
  uint uVar5;
  int iVar6;
  CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
  *unaff_EBX;
  int iVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *pCVar10;
  undefined4 uStack00000004;
  undefined1 uStack00000008;
  void *in_stack_00000014;
  ulong uVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  TiXmlAttribute *pTVar13;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffac;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffffb0;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffffb4;
  TiXmlAttributeSet *pTStack_48;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_44;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_40;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_3c;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *local_38;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_34;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_30;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_2c;
  undefined1 auStack_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [8];
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  iVar7 = DAT_00d75a60;
  local_4 = 0xffffffff;
  local_8 = &LAB_00aea520;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     ((void *)(DAT_00d75a60 + 0x5b4),
                      (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffff9c));
  pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar7 + 0x5b4),pCVar9,(ulong)unaff_EDI);
      uVar5 = *(uint *)(*(int *)pSVar3 + 0x1c);
      if (((uVar5 & 0x400) != 0) || ((uVar5 & 0x50) != 0)) {
        unaff_EDI = (CFastBuffer<class_CPlugFileSndGen*> *)0x1;
        Undirty(*(CDx9VisualKeeper **)(*(int *)pSVar3 + 0x14),(CDx9IndexBuffer *)0x1);
        iVar7 = DAT_00d75a60;
      }
      pCVar9 = pCVar9 + 1;
    } while (pCVar9 < pCVar2);
  }
  uVar11 = 0x97ce7c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(&local_38,unaff_EDI);
  uStack00000004 = 0;
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>::
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>(auStack_28,unaff_ESI);
  uStack00000008 = 1;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar7 + 0x5b4),unaff_EBP);
  local_3c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  local_30 = pCVar2;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pCVar9 = local_3c;
      pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x97cebd;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar7 + 0x5b4),local_3c,(ulong)unaff_EBX);
      local_30 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(*(int *)pSVar3 + 0x14);
      if (((*(uint *)(local_30 + 0xc) & 0x4000000) == 0) ||
         (local_3c = pCVar9, *(int *)(iVar7 + 0x328) == 0)) {
        pCVar9 = local_30 + 0x30;
        local_3c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2;
        pCStack_40 = pCVar9;
        do {
          this = *(int **)pCVar9;
          pCVar8 = pCVar12;
          if (this != (int *)0x0) {
            pTVar13 = (TiXmlAttribute *)0x97cefe;
            pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     CFastBuffer<class_CCrystalFace*>::GetCount
                               (&local_2c,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
            pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            local_34 = pCVar2;
            if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
              do {
                pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (&local_3c,pCVar8,uVar11);
                this_00 = *(int **)pSVar3;
                if (this_00 == this) break;
                if (((*this_00 == *this) && (this_00[3] == this[3])) &&
                   ((uint)(this[2] + this_00[2]) < DAT_00d387a0)) {
                  iVar7 = *(int *)(in_stack_ffffffb0 + 8);
                  iVar6 = *this;
                  this[2] = this[2] - iVar7 * iVar6;
                  piVar1 = this + 4;
                  *piVar1 = *piVar1 + -1;
                  if (*piVar1 == 0) {
                    CDx9VertexBuffer::~CDx9VertexBuffer(this,(CDx9VertexBuffer *)pTVar13);
                    operator_delete(this);
                  }
                  else {
                    *(undefined4 *)(*(int *)in_stack_ffffffb0 + 4) = 0;
                  }
                  *(undefined4 *)in_stack_ffffffb4 = 0;
                  this_00[4] = this_00[4] + 1;
                  this_00[2] = this_00[2] + iVar7 * iVar6;
                  this_00[1] = 0;
                  CDx9VertexBuffer::Release(this_00,(CDx9VStreamKeeper *)pCVar12);
                  pCVar2 = local_3c;
                  break;
                }
                pCVar8 = pCVar8 + 1;
              } while (pCVar8 < pCVar2);
            }
            if (pCVar8 == pCVar2) {
              CFastBuffer<class_CDx9TextureKeeper*>::Add(&local_30,pTStack_48,pTVar13);
              uVar11 = CFastBuffer<class_CCrystalFace*>::GetCount
                                 (local_20,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
              unaff_EBX = (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                           *)(uVar11 + 1);
              pTVar13 = (TiXmlAttribute *)0x97cfc2;
              CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetCatCount
                        (local_1c,unaff_EBX,(ulong)in_stack_ffffffac);
            }
            uVar11 = 0x97cfd1;
            CFastBufferCat<class_CNetHttpResult*,struct_SFastCat>::AddInCat
                      (local_24,(CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat>
                                 *)&local_38,(CHmsCorpus **)pCVar8,(ulong)pTVar13);
          }
          pCVar9 = pCStack_44 + 0xc;
          pCStack_40 = pCStack_40 + -1;
          pCVar2 = local_30;
          iVar7 = DAT_00d75a60;
          pCVar12 = pCVar8;
          pCStack_44 = pCVar9;
        } while (pCStack_40 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0);
      }
      local_3c = local_3c + 1;
    } while (local_3c < pCVar2);
  }
  local_2c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (&local_2c,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
  pCStack_40 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (local_2c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (auStack_28,pCStack_40,(ulong)in_stack_ffffffac);
      this_01 = *(void **)pSVar3;
      if (*(int *)((int)this_01 + 4) == 0) {
        in_stack_ffffffac = pCStack_40;
        pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                           (local_18,pCStack_40,(ulong)in_stack_ffffffb0);
        local_30 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar3 + 4);
        *(undefined4 *)((int)this_01 + 4) = *(undefined4 *)((int)this_01 + 8);
        in_stack_ffffffb0 = (CFastBuffer<class_CPlugFileGPUV*> *)0x97d050;
        CDx9VertexBuffer::Create(this_01,(CDx9VertexBuffer *)in_stack_ffffffb4);
        pCVar10 = (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                   *)0x0;
        if (local_2c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          iVar7 = 0;
          do {
            pSVar4 = CFastBufferCat<class_CSceneMobil*,struct_SFastCat>::GetElemInCat
                               (local_1c,pCVar10,(ulong)pCStack_40,(ulong)in_stack_ffffffac);
            this_02 = *(CDx9VisualKeeper **)pSVar4;
            uVar5 = *(uint *)((int)this_01 + 0xc) >> 4 & 1;
            *(void **)(this_02 + (uVar5 * 3 + 0xc) * 4) = this_01;
            *(int *)(this_02 + uVar5 * 0xc + 0x34) = iVar7;
            in_stack_ffffffac = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            *(uint *)(this_02 + 0x98) = uVar5;
            LoadStaticGeometry(this_02,(CDx9VisualKeeper *)0x0,(ulong)in_stack_ffffffb0);
            in_stack_ffffffb0 = (CFastBuffer<class_CPlugFileGPUV*> *)0x97d0a0;
            iVar6 = (**(code **)(**(int **)(this_02 + 4) + 0xb8))();
            pCVar10 = pCVar10 + 1;
            iVar7 = iVar7 + iVar6;
          } while (pCVar10 < local_38);
        }
      }
      pCStack_40 = pCStack_40 + 1;
    } while (pCStack_40 < local_2c);
  }
  DAT_00d75a7c = 0;
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (local_10,(CFastBuffer<class_CPlugFileGPUV*> *)in_stack_ffffffac);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(local_18,in_stack_ffffffb0);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(local_20,in_stack_ffffffb4);
  ExceptionList = in_stack_00000014;
  return;
}
}

// =================================================
// Function: CDx9VisualKeeper::RecordVertex2InVB
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CDx9VisualKeeper::RecordVertex2InVB
          (CDx9VisualKeeper *this,CDx9VisualKeeper *param_1,uchar **param_2,GxVertex2 *param_3,
          ulong param_4,SStreamDecl *param_5)
{
{
  uchar *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  GxVertex2 *pGVar5;
  uchar **ppuVar6;
  SCasterCat *pSVar7;
  uint uVar8;
  ulong unaff_EDI;
  uint uVar9;
  
  pGVar5 = param_3;
  ppuVar6 = param_2 + (int)param_3 * 8;
  if ((*(byte *)param_4 & 1) != 0) {
    puVar2 = *(undefined4 **)param_1;
    puVar1 = ppuVar6[1];
    *puVar2 = *ppuVar6;
    puVar2[1] = puVar1;
    puVar2[2] = 0;
    *(int *)param_1 = *(int *)param_1 + 0xc;
  }
  if ((*(byte *)param_4 & 0x40) != 0) {
    puVar2 = *(undefined4 **)param_1;
    puVar1 = ppuVar6[3];
    *puVar2 = ppuVar6[2];
    puVar2[1] = puVar1;
    puVar2[2] = 0;
    *(int *)param_1 = *(int *)param_1 + 0xc;
  }
  if ((*(uint *)param_4 & 0x200) != 0) {
    param_3 = (GxVertex2 *)
              CONCAT22((short)ROUND((float)ppuVar6[4] * _DAT_00b5e844),
                       (short)ROUND((float)ppuVar6[6] * _DAT_00b5e844));
    param_2 = (uchar **)
              CONCAT22((short)ROUND((float)ppuVar6[7] * _DAT_00b5e844),
                       (short)ROUND((float)ppuVar6[5] * _DAT_00b5e844));
    **(uint **)param_1 = (uint)param_3 | (int)param_2 << 8;
    *(int *)param_1 = *(int *)param_1 + 4;
  }
  uVar8 = 0;
  do {
    uVar9 = (*(uint *)param_4 >> ((byte)uVar8 & 0x1f)) >> 0xb & 3;
    if (uVar9 == 0) {
      return;
    }
    pSVar7 = CFastBuffer<struct_SFastCat>::operator[]
                       ((void *)(*(int *)(this + 4) + 0x5c),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EDI);
    if ((uVar9 == 1) || (uVar9 != 2)) {
      iVar4 = *(int *)(pSVar7 + 4);
      puVar2 = *(undefined4 **)param_1;
      *puVar2 = *(undefined4 *)(iVar4 + (int)pGVar5 * 8);
      puVar2[1] = *(undefined4 *)(iVar4 + 4 + (int)pGVar5 * 8);
      *(int *)param_1 = *(int *)param_1 + 8;
    }
    else {
      puVar2 = (undefined4 *)(*(int *)(pSVar7 + 4) + (int)pGVar5 * 0xc);
      puVar3 = *(undefined4 **)param_1;
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[1];
      puVar3[2] = puVar2[2];
      *(int *)param_1 = *(int *)param_1 + 0xc;
    }
    uVar8 = uVar8 + 2;
    param_4 = (ulong)param_5;
  } while (uVar8 < 0x10);
  return;
}
}

// =================================================
// Function: CDx9VisualKeeper::RecordVertex3InVB
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CDx9VisualKeeper::RecordVertex3InVB
          (CDx9VisualKeeper *this,CLoadGeomVertexGen<671098945> *param_1,uchar **param_2,
          GxVertex *param_3,ulong param_4)
{
{
  uchar **ppuVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  GxVertex *pGVar6;
  byte *pbVar7;
  SCasterCat *pSVar8;
  uint *puVar9;
  uint uVar10;
  ulong unaff_EDI;
  
  pGVar6 = param_3;
  ppuVar1 = param_2 + (int)param_3 * 10;
  if ((*(byte *)param_4 & 1) != 0) {
    puVar3 = *(undefined4 **)param_1;
    *puVar3 = *ppuVar1;
    puVar3[1] = ppuVar1[1];
    puVar3[2] = ppuVar1[2];
    *(int *)param_1 = *(int *)param_1 + 0xc;
  }
  if ((*(uint *)param_4 & 0x20) == 0) goto switchD_009739e4_default;
  switch(*(uint *)param_4 >> 3 & 3) {
  case 0:
    **(uint **)param_1 = (uint)(byte)param_3[*(int *)(*(int *)(*(int *)(this + 4) + 0x50) + 4)];
    goto LAB_00973aa3;
  case 1:
    iVar5 = *(int *)(*(int *)(*(int *)(this + 4) + 0x50) + 4);
    puVar3 = *(undefined4 **)param_1;
    *puVar3 = *(undefined4 *)(iVar5 + 4 + (int)param_3 * 8);
    puVar9 = puVar3 + 1;
    *(uint **)param_1 = puVar9;
    uVar10 = (uint)*(ushort *)(iVar5 + (int)param_3 * 8);
    goto LAB_00973aa1;
  case 2:
    iVar5 = *(int *)(*(int *)(*(int *)(this + 4) + 0x50) + 4);
    puVar3 = *(undefined4 **)param_1;
    pbVar7 = (byte *)(iVar5 + (int)param_3 * 0xc);
    *puVar3 = *(undefined4 *)(iVar5 + 4 + (int)param_3 * 0xc);
    *(undefined4 **)param_1 = puVar3 + 1;
    puVar3[1] = *(undefined4 *)(pbVar7 + 8);
    puVar9 = puVar3 + 2;
    *(uint **)param_1 = puVar9;
    uVar10 = (uint)*(ushort *)(pbVar7 + 1);
    break;
  case 3:
    puVar3 = *(undefined4 **)param_1;
    pbVar7 = (byte *)((int)param_3 * 0x10 + *(int *)(*(int *)(*(int *)(this + 4) + 0x50) + 4));
    uVar2 = *(undefined4 *)(pbVar7 + 4);
    *(undefined4 **)param_1 = puVar3 + 1;
    *puVar3 = uVar2;
    uVar2 = *(undefined4 *)(pbVar7 + 8);
    *(undefined4 **)param_1 = puVar3 + 2;
    puVar3[1] = uVar2;
    puVar9 = puVar3 + 3;
    puVar3[2] = *(undefined4 *)(pbVar7 + 0xc);
    *(uint **)param_1 = puVar9;
    uVar10 = (uint)*(uint3 *)(pbVar7 + 1);
    break;
  default:
    goto switchD_009739e4_default;
  }
  uVar10 = uVar10 << 8 | (uint)*pbVar7;
LAB_00973aa1:
  *puVar9 = uVar10;
LAB_00973aa3:
  *(int *)param_1 = *(int *)param_1 + 4;
switchD_009739e4_default:
  if ((*(byte *)param_4 & 0x40) != 0) {
    puVar3 = *(undefined4 **)param_1;
    *puVar3 = ppuVar1[3];
    puVar3[1] = ppuVar1[4];
    puVar3[2] = ppuVar1[5];
    *(int *)param_1 = *(int *)param_1 + 0xc;
  }
  if ((*(uint *)param_4 & 0x200) != 0) {
    param_3 = (GxVertex *)
              CONCAT22((short)ROUND((float)ppuVar1[6] * _DAT_00b5e844),
                       (short)ROUND((float)ppuVar1[8] * _DAT_00b5e844));
    param_2 = (uchar **)
              CONCAT22((short)ROUND((float)ppuVar1[9] * _DAT_00b5e844),
                       (short)ROUND((float)ppuVar1[7] * _DAT_00b5e844));
    **(uint **)param_1 = (uint)param_3 | (int)param_2 << 8;
    *(int *)param_1 = *(int *)param_1 + 4;
  }
  param_3 = (GxVertex *)0x0;
  do {
    uVar10 = *(uint *)param_4 >> 0xb & 3;
    if (uVar10 == 0) break;
    pSVar8 = CFastBuffer<struct_SFastCat>::operator[]
                       ((void *)(*(int *)(this + 4) + 0x5c),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_3,unaff_EDI);
    if ((uVar10 == 1) || (uVar10 != 2)) {
      iVar5 = *(int *)(pSVar8 + 4);
      puVar3 = *(undefined4 **)param_1;
      *puVar3 = *(undefined4 *)(iVar5 + (int)pGVar6 * 8);
      puVar3[1] = *(undefined4 *)(iVar5 + 4 + (int)pGVar6 * 8);
      *(int *)param_1 = *(int *)param_1 + 8;
    }
    else {
      puVar3 = (undefined4 *)(*(int *)(pSVar8 + 4) + (int)pGVar6 * 0xc);
      puVar4 = *(undefined4 **)param_1;
      *puVar4 = *puVar3;
      puVar4[1] = puVar3[1];
      puVar4[2] = puVar3[2];
      *(int *)param_1 = *(int *)param_1 + 0xc;
    }
    param_4 = param_4 + 1;
    param_3 = param_3 + 2;
  } while (param_3 < (GxVertex *)0x10);
  if ((*(uint *)param_4 & 0x8000000) != 0) {
    pSVar8 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       ((void *)(*(int *)(this + 4) + 0x84),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar6,unaff_EDI);
    puVar3 = *(undefined4 **)param_1;
    *puVar3 = *(undefined4 *)pSVar8;
    puVar3[1] = *(undefined4 *)(pSVar8 + 4);
    puVar3[2] = *(undefined4 *)(pSVar8 + 8);
    *(int *)param_1 = *(int *)param_1 + 0xc;
  }
  if ((*(uint *)param_4 & 0x20000000) != 0) {
    pSVar8 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       ((void *)(*(int *)(this + 4) + 0x8c),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar6,unaff_EDI);
    puVar3 = *(undefined4 **)param_1;
    *puVar3 = *(undefined4 *)pSVar8;
    puVar3[1] = *(undefined4 *)(pSVar8 + 4);
    puVar3[2] = *(undefined4 *)(pSVar8 + 8);
    *(int *)param_1 = *(int *)param_1 + 0xc;
  }
  return;
}
}

// =================================================
// Function: CDx9VisualKeeper::StaticInit
// =================================================
void __cdecl CDx9VisualKeeper::StaticInit(void)
{
{
  DAT_00d75a6c = 0;
  DAT_00d75a70 = 0;
  return;
}
}

