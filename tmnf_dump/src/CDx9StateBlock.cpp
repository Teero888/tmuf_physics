// Class implementation: CDx9StateBlock

// =================================================
// Function: CDx9StateBlock::Apply
// =================================================
void __thiscall CDx9StateBlock::Apply(void *this,CDx9StateBlock *param_1)
{
{
  short sVar1;
  int *piVar2;
  SCasterCat *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *pCVar5;
  uint uVar6;
  CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat> *unaff_EBX;
  uint uVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  ulong uVar8;
  ulong uVar9;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  void *pvVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  int iVar12;
  CFastBuffer<class_CCrystalFace*> *pCVar13;
  uint uVar14;
  SCasterCat *unaff_EDI;
  int iVar15;
  uint *puVar16;
  ulong in_stack_00000008;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000010;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000014;
  ulong in_stack_00000018;
  int *piStack0000001c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000020;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000024;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack00000028;
  void *pvVar17;
  ulong in_stack_ffffffec;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff0;
  ulong in_stack_fffffff8;
  ulong in_stack_fffffffc;
  
  piVar2 = DAT_00d76f70;
  pCVar4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)this + 4);
  pvVar17 = this;
  if ((pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) &&
     (pCVar4 != DAT_00d388f4)) {
    iVar15 = *DAT_00d76f70;
    pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>::operator[]
                       (&DAT_00d77048,pCVar4,(ulong)unaff_EDI);
    unaff_EDI = pSVar3 + 4;
    (**(code **)(iVar15 + 0xc4))(piVar2);
    DAT_00d388f4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)this + 4);
  }
  if (*(int *)((int)this + 0xc) == 0) {
    pvVar10 = (void *)0x0;
  }
  else {
    pvVar10 = *(void **)(*(int *)((int)this + 0xc) + 0x1c);
  }
  if (pvVar10 != DAT_00d7568c) {
    if (pvVar10 == (void *)0x0) {
      (**(code **)(*DAT_00d75680 + 0x1ac))(DAT_00d75680,0);
      DAT_00d7568c = pvVar10;
    }
    else {
      CDx9PixelShader::UndirtyAndSetPixelShader(pvVar10,(CDx9PixelShader *)unaff_EDI);
      DAT_00d7568c = pvVar10;
    }
  }
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     ((void *)((int)this + 0x10),(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
  pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                         ((void *)((int)this + 0x10),pCVar11,(ulong)unaff_ESI);
      unaff_ESI = *(CFastBuffer<class_CCrystalFace*> **)(pSVar3 + 4);
      FilterRenderState(*(_D3DRENDERSTATETYPE *)pSVar3,(ulong)unaff_ESI);
      pCVar11 = pCVar11 + 1;
    } while (pCVar11 < pCVar4);
  }
  pvVar10 = (void *)(in_stack_ffffffec + 0x18);
  uVar8 = in_stack_ffffffec;
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(pvVar10,unaff_ESI);
  pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (*(int *)(in_stack_ffffffec + 0x20) != 0) {
    pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[](pvVar10,pCVar11,(ulong)unaff_EBP);
      if (*(int *)(pSVar3 + 4) == 0) {
        iVar15 = 0;
      }
      else {
        iVar15 = *(int *)(*(int *)(pSVar3 + 4) + 0x14);
      }
      iVar12 = *(int *)pSVar3;
      if ((&DAT_00d756a8)[iVar12] != iVar15) {
        if (iVar15 == 0) {
          unaff_EBP = (CFastBuffer<class_CCrystalFace*> *)0x0;
        }
        else {
          unaff_EBP = *(CFastBuffer<class_CCrystalFace*> **)(iVar15 + 0xc);
        }
        (**(code **)(*DAT_00d75698 + 0x104))(DAT_00d75698,iVar12);
        (&DAT_00d756a8)[iVar12] = iVar15;
      }
      pCVar11 = pCVar11 + 1;
    } while (pCVar11 < *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                        (in_stack_fffffff0 + 0x20));
  }
  if (pCVar11 < pCVar4) {
    do {
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[](pvVar10,pCVar11,(ulong)unaff_EBP);
      if (*(int *)(pSVar3 + 4) == 0) {
        iVar15 = 0;
      }
      else {
        iVar15 = *(int *)(*(int *)(pSVar3 + 4) + 0x14);
      }
      iVar12 = *(int *)pSVar3 + -0x101;
      if (*(int *)(&DAT_00d756e8 + iVar12 * 4) != iVar15) {
        if (iVar15 == 0) {
          unaff_EBP = (CFastBuffer<class_CCrystalFace*> *)0x0;
        }
        else {
          unaff_EBP = *(CFastBuffer<class_CCrystalFace*> **)(iVar15 + 0xc);
        }
        (**(code **)(*DAT_00d75698 + 0x104))(DAT_00d75698,*(int *)pSVar3);
        *(int *)(&DAT_00d756e8 + iVar12 * 4) = iVar15;
      }
      pCVar11 = pCVar11 + 1;
    } while (pCVar11 < pCVar4);
  }
  sVar1 = *(short *)(in_stack_fffffff0 + 0x7c);
  if ((sVar1 != -1) && (DAT_00d388f8 != sVar1)) {
    DAT_00d388f8 = sVar1;
    (**(code **)(*DAT_00d76f70 + 0x124))(DAT_00d76f70,sVar1);
  }
  pCVar13 = in_stack_fffffff0 + 0x24;
  pCVar5 = (CFastBuffer<class_CCrystalFace*> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(pCVar13,unaff_EBP);
  if (pCVar5 != (CFastBuffer<class_CCrystalFace*> *)0x0) {
    CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat>::SetParsingAll(pCVar13,unaff_EBX);
    pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    in_stack_fffffffc = 0;
    pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (pCVar13,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)pvVar17
                       );
    iVar15 = *(int *)(pSVar3 + 4);
    pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (pCVar13,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,uVar8);
    uVar8 = (ulong)(byte)pSVar3[8];
    while (iVar15 != 0) {
      pSVar3 = CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat>::operator[]
                         (pCVar13,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                          (ulong)in_stack_fffffff0);
      in_stack_fffffff0 = *(CFastBuffer<class_CCrystalFace*> **)(pSVar3 + 4);
      FilterTexStageState(uVar8,*(_D3DTEXTURESTAGESTATETYPE *)pSVar3,(ulong)in_stack_fffffff0);
      in_stack_00000008 = in_stack_00000008 + 1;
      iVar15 = iVar15 + -1;
      if (iVar15 == 0) {
        pCVar11 = pCVar11 + 1;
        if (in_stack_00000010 <= pCVar11) break;
        pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (pCVar13,pCVar11,(ulong)pCVar4);
        iVar15 = *(int *)(pSVar3 + 4);
        in_stack_fffffff0 = (CFastBuffer<class_CCrystalFace*> *)0x980976;
        pCVar4 = pCVar11;
        pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (pCVar13,pCVar11,in_stack_fffffff8);
        uVar8 = (ulong)(byte)pSVar3[8];
      }
    }
  }
  pCVar13 = pCVar5 + 0x48;
  uVar8 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar13,in_stack_fffffff0);
  if (uVar8 != 0) {
    CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat>::SetParsingAll
              (pCVar13,(CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat> *)pCVar4);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (pCVar13,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        in_stack_fffffff8);
    iVar15 = *(int *)(pSVar3 + 4);
    pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (pCVar13,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        in_stack_fffffffc);
    uVar9 = (ulong)(byte)pSVar3[8];
    while (iVar15 != 0) {
      pSVar3 = CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat>::operator[]
                         (pCVar13,in_stack_00000014,(ulong)pCVar5);
      pCVar5 = *(CFastBuffer<class_CCrystalFace*> **)(pSVar3 + 4);
      FilterSamplerState(uVar9,*(_D3DSAMPLERSTATETYPE *)pSVar3,(ulong)pCVar5);
      in_stack_00000018 = in_stack_00000018 + 1;
      iVar15 = iVar15 + -1;
      if (iVar15 == 0) {
        pCVar4 = pCVar4 + 1;
        if (in_stack_00000020 <= pCVar4) break;
        pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (pCVar13,pCVar4,(ulong)param_1);
        iVar15 = *(int *)(pSVar3 + 4);
        pCVar5 = (CFastBuffer<class_CCrystalFace*> *)0x980a02;
        pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (pCVar13,pCVar4,in_stack_00000008);
        uVar9 = (ulong)(byte)pSVar3[8];
        param_1 = (CDx9StateBlock *)pCVar4;
      }
    }
  }
  pCStack00000028 =
       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
       CFastBuffer<class_CCrystalFace*>::GetCount((void *)(uVar8 + 0x6c),pCVar5);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCStack00000028 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         ((void *)(uVar8 + 0x6c),pCVar4,(ulong)param_1);
      iVar15 = *(int *)pSVar3;
      pCStack00000028 =
           (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           (*(uint *)(&DAT_00d76ed8 + iVar15 * 4) & *(uint *)(pSVar3 + 8));
      uVar14 = *(uint *)(pSVar3 + 4);
      uVar7 = (*(uint *)(&DAT_00d76e70 + iVar15 * 4) ^ uVar14) & (uint)pCStack00000028;
      if (uVar7 != 0) {
        switch(iVar15) {
        case 0:
          do {
            piVar2 = DAT_00d76f70;
            iVar15 = 0;
            if (uVar7 != 0) {
              for (; (uVar7 >> iVar15 & 1) == 0; iVar15 = iVar15 + 1) {
              }
            }
            if ((&DAT_00d76cf0)[iVar15 * 3] == DAT_00d388fc) {
              param_1 = *(CDx9StateBlock **)
                         (&DAT_00d38900 + (*(uint *)(pSVar3 + 4) >> 0x1e & 1) * 4);
            }
            else {
              uVar14 = (&DAT_00d76cf8)[iVar15 * 3];
              param_1 = (CDx9StateBlock *)
                        ((*(uint *)(pSVar3 + 4) >> ((byte)(uVar14 >> 8) & 0x1f) & uVar14 & 0xff) +
                        (uVar14 >> 0x11 & 7));
            }
            (&DAT_00d769e0)[(&DAT_00d76cf0)[iVar15 * 3]] = param_1;
            (**(code **)(*piVar2 + 0xe4))(piVar2);
            uVar7 = uVar7 & (&DAT_00d76cf4)[iVar15 * 3];
          } while (uVar7 != 0);
          break;
        case 1:
        case 2:
        case 3:
        case 4:
          uVar8 = iVar15 * 4 - 4;
          piStack0000001c = &DAT_00d76248 + uVar8 * 0xe;
          do {
            if ((uVar7 & 3) != 0) {
              param_1 = *(CDx9StateBlock **)(&DAT_00d76f60 + (uVar14 & 3) * 4);
              FilterSamplerState(uVar8,5,(ulong)param_1);
              FilterSamplerState(uVar8,6,*(ulong *)(&DAT_00d76f50 + (uVar14 & 3) * 4));
              uVar7 = uVar7 & 0xfffffffc;
              if (uVar7 == 0) break;
            }
            if ((uVar7 & 0xc) != 0) {
              param_1 = *(CDx9StateBlock **)(&DAT_00d76f40 + (uVar14 >> 2 & 3) * 4);
              FilterSamplerState(uVar8,7,(ulong)param_1);
              uVar7 = uVar7 & 0xfffffff3;
              if (uVar7 == 0) break;
            }
            if ((uVar7 & 0x30) != 0) {
              param_1 = (CDx9StateBlock *)((uVar14 >> 4 & 3) + 1);
              piStack0000001c[-1] = (int)param_1;
              (**(code **)(*DAT_00d76f70 + 0x114))(DAT_00d76f70,uVar8);
              uVar7 = uVar7 & 0xffffffcf;
              if (uVar7 == 0) break;
            }
            if ((uVar7 & 0xc0) != 0) {
              param_1 = (CDx9StateBlock *)((uVar14 >> 6 & 3) + 1);
              *piStack0000001c = (int)param_1;
              (**(code **)(*DAT_00d76f70 + 0x114))(DAT_00d76f70,uVar8);
              uVar7 = uVar7 & 0xffffff3f;
              if (uVar7 == 0) break;
            }
            uVar7 = uVar7 >> 8;
            uVar14 = uVar14 >> 8;
            uVar8 = uVar8 + 1;
            piStack0000001c = piStack0000001c + 0xe;
          } while( true );
        case 6:
        case 7:
          iVar15 = iVar15 * 8 + -0x30;
          puVar16 = (uint *)(&DAT_00d76264 + iVar15 * 0x38);
          do {
            piVar2 = DAT_00d76f70;
            if ((uVar7 & 0xf) != 0) {
              param_1 = (CDx9StateBlock *)(uVar14 & 0xf);
              *puVar16 = (uint)param_1;
              (**(code **)(*piVar2 + 0x114))(piVar2,iVar15);
              uVar7 = uVar7 & 0xfffffff0;
              if (uVar7 == 0) break;
            }
            uVar7 = uVar7 >> 4;
            uVar14 = uVar14 >> 4;
            iVar15 = iVar15 + 1;
            puVar16 = puVar16 + 0xe;
          } while( true );
        case 8:
        case 9:
          uVar6 = -(uint)(iVar15 != 8) & 4;
          puVar16 = (uint *)(&DAT_00d76620 + uVar6 * 0x84);
          do {
            piVar2 = DAT_00d76f70;
            if ((uVar7 >> 3 & 3) != 0 || (uVar7 & 7) != 0) {
              param_1 = (CDx9StateBlock *)((uVar14 & 0x18) << 0xd | uVar14 & 7);
              puVar16[-0xd] = (uint)param_1;
              (**(code **)(*piVar2 + 0x10c))(piVar2,uVar6);
              uVar7 = uVar7 & 0xffffffe0;
              if (uVar7 == 0) break;
            }
            piVar2 = DAT_00d76f70;
            if ((uVar7 >> 2 & 0x20) != 0 || (uVar7 & 0x60) != 0) {
              param_1 = (CDx9StateBlock *)
                        ((uVar14 & 0x80) * 2 | *(uint *)(&DAT_00d388e4 + (uVar14 >> 5 & 3) * 4));
              *puVar16 = (uint)param_1;
              (**(code **)(*piVar2 + 0x10c))(piVar2,uVar6);
              uVar7 = uVar7 & 0xffffff1f;
              if (uVar7 == 0) break;
            }
            uVar7 = uVar7 >> 8;
            uVar14 = uVar14 >> 8;
            uVar6 = uVar6 + 1;
            puVar16 = puVar16 + 0x21;
          } while( true );
        case 10:
        case 0xb:
        case 0xc:
        case 0xd:
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x11:
          iVar15 = iVar15 + -10;
          if ((uVar7 & 0x1f) != 0) {
            param_1 = (CDx9StateBlock *)(uVar14 & 0x1f);
            (&DAT_00d765c4)[iVar15 * 0x21] = param_1;
            (**(code **)(*DAT_00d76f70 + 0x10c))(DAT_00d76f70,iVar15);
            uVar7 = uVar7 & 0xffffffe0;
            if (uVar7 == 0) break;
          }
          if ((uVar7 & 0x3e0) != 0) {
            param_1 = (CDx9StateBlock *)(uVar14 >> 5 & 0x1f);
            *(CDx9StateBlock **)(&DAT_00d765d0 + iVar15 * 0x84) = param_1;
            (**(code **)(*DAT_00d76f70 + 0x10c))(DAT_00d76f70,iVar15);
            uVar7 = uVar7 & 0xfffffc1f;
            if (uVar7 == 0) break;
          }
          if ((uVar7 >> 3 & 0xc00) != 0 || (uVar7 & 0x1c00) != 0) {
            param_1 = (CDx9StateBlock *)((uVar14 >> 1 & 0xe00 | uVar14 & 0x6000) >> 9);
            (&DAT_00d765c8)[iVar15 * 0x21] = param_1;
            (**(code **)(*DAT_00d76f70 + 0x10c))(DAT_00d76f70,iVar15);
            uVar7 = uVar7 & 0xffff83ff;
            if (uVar7 == 0) break;
          }
          if ((uVar7 >> 3 & 0x18000) != 0 || (uVar7 & 0x38000) != 0) {
            param_1 = (CDx9StateBlock *)((uVar14 >> 1 & 0x1c000 | uVar14 & 0xc0000) >> 0xe);
            *(CDx9StateBlock **)(&DAT_00d765cc + iVar15 * 0x84) = param_1;
            (**(code **)(*DAT_00d76f70 + 0x10c))(DAT_00d76f70,iVar15);
            uVar7 = uVar7 & 0xfff07fff;
            if (uVar7 == 0) break;
          }
          if ((uVar7 >> 3 & 0x100000) != 0 || (uVar7 & 0x700000) != 0) {
            param_1 = (CDx9StateBlock *)((uVar14 >> 1 & 0x380000 | uVar14 & 0x800000) >> 0x13);
            *(CDx9StateBlock **)(&DAT_00d765d4 + iVar15 * 0x84) = param_1;
            (**(code **)(*DAT_00d76f70 + 0x10c))(DAT_00d76f70,iVar15);
            uVar7 = uVar7 & 0xff0fffff;
            if (uVar7 == 0) break;
          }
          if ((uVar7 >> 3 & 0x1000000) != 0 || (uVar7 & 0x7000000) != 0) {
            param_1 = (CDx9StateBlock *)((uVar14 >> 1 & 0x3800000 | uVar14 & 0x8000000) >> 0x17);
            *(CDx9StateBlock **)(&DAT_00d765d8 + iVar15 * 0x84) = param_1;
            (**(code **)(*DAT_00d76f70 + 0x10c))(DAT_00d76f70,iVar15);
            uVar7 = uVar7 & 0xf0ffffff;
            if (uVar7 == 0) break;
          }
          piVar2 = DAT_00d76f70;
          if ((uVar7 & 0x70000000) != 0) {
            param_1 = (CDx9StateBlock *)(uVar14 >> 0x1c & 7);
            *(CDx9StateBlock **)(&DAT_00d76630 + iVar15 * 0x84) = param_1;
            (**(code **)(*piVar2 + 0x10c))(piVar2,iVar15);
          }
          break;
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
          iVar15 = iVar15 + -10;
          if ((uVar7 >> 3 & 3) != 0 || (uVar7 & 7) != 0) {
            param_1 = (CDx9StateBlock *)((uVar14 & 0x18) * 2 | uVar14 & 7);
            *(CDx9StateBlock **)(&DAT_00d76628 + iVar15 * 0x84) = param_1;
            (**(code **)(*DAT_00d76f70 + 0x10c))(DAT_00d76f70,iVar15);
            uVar7 = uVar7 & 0xffffffe0;
            if (uVar7 == 0) break;
          }
          piVar2 = DAT_00d76f70;
          if ((uVar7 >> 3 & 0x20) != 0 || (uVar7 & 0xe0) != 0) {
            param_1 = (CDx9StateBlock *)((uVar14 >> 1 & 0x70 | uVar14 & 0x100) >> 4);
            *(CDx9StateBlock **)(&DAT_00d7662c + iVar15 * 0x84) = param_1;
            (**(code **)(*piVar2 + 0x10c))(piVar2,iVar15);
          }
        }
        *(uint *)(&DAT_00d76e70 + *(int *)pSVar3 * 4) =
             ~(uint)pCStack00000028 & *(uint *)(&DAT_00d76e70 + *(int *)pSVar3 * 4) |
             *(uint *)(pSVar3 + 4) & (uint)pCStack00000028;
        uVar8 = in_stack_00000018;
        pCVar4 = in_stack_00000024;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCStack00000028);
  }
  DAT_00d76f7c = uVar8;
  return;
}
}

// =================================================
// Function: CDx9StateBlock::FilterRenderState
// =================================================
void __cdecl CDx9StateBlock::FilterRenderState(_D3DRENDERSTATETYPE param_1,ulong param_2)
{
{
  int *piVar1;
  uint unaff_ESI;
  uint unaff_EDI;
  ulong uStack_18;
  
  piVar1 = DAT_00d76f70;
  if (((&DAT_00d769e0)[param_1] != param_2) && (*(int *)(&DAT_00d75f30 + param_1 * 4) == 0)) {
    uStack_18 = param_2;
    (&DAT_00d769e0)[param_1] = param_2;
    (**(code **)(*piVar1 + 0xe4))(piVar1,param_1);
    if (*(int *)(&DAT_00d75c20 + param_1 * 4) != 0) {
      PackRenderState(param_1,param_2,(SPackedDesc *)&uStack_18);
      *(uint *)(&DAT_00d76e70 + uStack_18 * 4) =
           ~unaff_ESI & *(uint *)(&DAT_00d76e70 + uStack_18 * 4) | unaff_EDI & unaff_ESI;
    }
  }
  return;
}
}

// =================================================
// Function: CDx9StateBlock::FilterSamplerState
// =================================================
void __cdecl
CDx9StateBlock::FilterSamplerState(ulong param_1,_D3DSAMPLERSTATETYPE param_2,ulong param_3)
{
{
  int iVar1;
  uint unaff_ESI;
  uint unaff_EDI;
  ulong uStack_1c;
  
  iVar1 = param_2 + param_1 * 0xe;
  if ((&DAT_00d76240)[iVar1] != param_3) {
    uStack_1c = param_3;
    (&DAT_00d76240)[iVar1] = param_3;
    (**(code **)(*DAT_00d76f70 + 0x114))(DAT_00d76f70,param_1,param_2);
    if (*(int *)(&DAT_00d75b5c + param_2 * 4) != 0) {
      PackSamplerState(param_1,param_2,param_3,(SPackedDesc *)&uStack_1c);
      *(uint *)(&DAT_00d76e70 + uStack_1c * 4) =
           ~unaff_ESI & *(uint *)(&DAT_00d76e70 + uStack_1c * 4) | unaff_EDI & unaff_ESI;
    }
  }
  return;
}
}

// =================================================
// Function: CDx9StateBlock::FilterSetStreamSource
// =================================================
void __cdecl
CDx9StateBlock::FilterSetStreamSource
          (ulong param_1,IDirect3DVertexBuffer9 *param_2,ulong param_3,ulong param_4)
{
{
  if (((param_2 != (IDirect3DVertexBuffer9 *)(&DAT_00d76f88)[param_1 * 3]) ||
      (param_3 != (&DAT_00d76f90)[param_1 * 3])) || (param_4 != (&DAT_00d76f8c)[param_1 * 3])) {
    (**(code **)(*DAT_00d76f70 + 400))(DAT_00d76f70,param_1,param_2,param_4,param_3);
    (&DAT_00d76f88)[param_1 * 3] = param_2;
    (&DAT_00d76f90)[param_1 * 3] = param_3;
    (&DAT_00d76f8c)[param_1 * 3] = param_4;
  }
  return;
}
}

// =================================================
// Function: CDx9StateBlock::FilterTexStageState
// =================================================
void __cdecl
CDx9StateBlock::FilterTexStageState(ulong param_1,_D3DTEXTURESTAGESTATETYPE param_2,ulong param_3)
{
{
  int iVar1;
  uint unaff_ESI;
  uint unaff_EDI;
  ulong uStack_1c;
  
  iVar1 = param_1 * 0x21 + param_2;
  if ((&DAT_00d765c0)[iVar1] != param_3) {
    uStack_1c = param_3;
    (&DAT_00d765c0)[iVar1] = param_3;
    (**(code **)(*DAT_00d76f70 + 0x10c))(DAT_00d76f70,param_1,param_2);
    if (*(int *)(&DAT_00d75b98 + param_2 * 4) != 0) {
      PackTexStage(param_1,param_2,param_3,(SPackedDesc *)&uStack_1c);
      *(uint *)(&DAT_00d76e70 + uStack_1c * 4) =
           ~unaff_ESI & *(uint *)(&DAT_00d76e70 + uStack_1c * 4) | unaff_EDI & unaff_ESI;
    }
  }
  return;
}
}

// =================================================
// Function: CDx9StateBlock::LockRenderState
// =================================================
ulong __cdecl CDx9StateBlock::LockRenderState(_D3DRENDERSTATETYPE param_1,ulong param_2)
{
{
  ulong uVar1;
  int local_c [2];
  uint local_4;
  
  uVar1 = (&DAT_00d769e0)[param_1];
  FilterRenderState(param_1,param_2);
  *(undefined4 *)(&DAT_00d75f30 + param_1 * 4) = 1;
  if (*(int *)(&DAT_00d75c20 + param_1 * 4) != 0) {
    PackRenderState(param_1,param_2,(SPackedDesc *)local_c);
    *(uint *)(&DAT_00d76ed8 + local_c[0] * 4) = *(uint *)(&DAT_00d76ed8 + local_c[0] * 4) & ~local_4
    ;
  }
  return uVar1;
}
}

// =================================================
// Function: CDx9StateBlock::LockRenderStateReal
// =================================================
float __cdecl CDx9StateBlock::LockRenderStateReal(_D3DRENDERSTATETYPE param_1,float param_2)
{
{
  float fVar1;
  
  fVar1 = (float)LockRenderState(param_1,(ulong)param_2);
  return fVar1;
}
}

// =================================================
// Function: CDx9StateBlock::PackRenderState
// =================================================
int __cdecl
CDx9StateBlock::PackRenderState(_D3DRENDERSTATETYPE param_1,ulong param_2,SPackedDesc *param_3)
{
{
  *(undefined4 *)(param_3 + 4) = 0;
  *(undefined4 *)(param_3 + 8) = 0;
  switch(param_1) {
  case 8:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 0xc0000;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^ (param_2 << 0x12 ^ *(uint *)(param_3 + 4)) & 0xc0000;
    *(undefined4 *)param_3 = 0;
    return 1;
  case 0xf:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 2;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^ ((uint)(param_2 != 0) * 2 ^ *(uint *)(param_3 + 4)) & 2;
    *(undefined4 *)param_3 = 0;
    return 1;
  case 0x13:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 0x1e0;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^ (param_2 << 5 ^ *(uint *)(param_3 + 4)) & 0x1e0;
    *(undefined4 *)param_3 = 0;
    return 1;
  case 0x14:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 0x1e00;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^ (param_2 << 9 ^ *(uint *)(param_3 + 4)) & 0x1e00;
    *(undefined4 *)param_3 = 0;
    return 1;
  case 0x16:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 0x30000;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^ (param_2 << 0x10 ^ *(uint *)(param_3 + 4)) & 0x30000;
    *(undefined4 *)param_3 = 0;
    return 1;
  case 0x19:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 0xe000;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^ ((param_2 - 1) * 0x2000 ^ *(uint *)(param_3 + 4)) & 0xe000;
    *(undefined4 *)param_3 = 0;
    return 1;
  case 0x1b:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 1;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^ ((uint)(param_2 != 0) ^ *(uint *)(param_3 + 4)) & 1;
    *(undefined4 *)param_3 = 0;
    return 1;
  case 0x1c:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 0x4000000;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^
         ((uint)(param_2 != 0) << 0x1a ^ *(uint *)(param_3 + 4)) & 0x4000000;
    *(undefined4 *)param_3 = 0;
    return 1;
  case 0x89:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 8;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^ ((uint)(param_2 != 0) * 8 ^ *(uint *)(param_3 + 4)) & 8;
    *(undefined4 *)param_3 = 0;
    return 1;
  case 0x8f:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 4;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^ ((uint)(param_2 != 0) * 4 ^ *(uint *)(param_3 + 4)) & 4;
    *(undefined4 *)param_3 = 0;
    return 1;
  case 0x91:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 0xc00000;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^ (param_2 << 0x16 ^ *(uint *)(param_3 + 4)) & 0xc00000;
    *(undefined4 *)param_3 = 0;
    return 1;
  case 0x93:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 0x300000;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^ (param_2 << 0x14 ^ *(uint *)(param_3 + 4)) & 0x300000;
    *(undefined4 *)param_3 = 0;
    return 1;
  case 0x94:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 0x3000000;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^ (param_2 << 0x18 ^ *(uint *)(param_3 + 4)) & 0x3000000;
    *(undefined4 *)param_3 = 0;
    return 1;
  case 0x9a:
  case 0xb5:
    if (param_1 == 0xb5) {
      if (*(int *)(DAT_00d76f78 + 0x460) == 6) {
LAB_0097eeb1:
        *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 0x40000000;
        *(uint *)(param_3 + 4) =
             *(uint *)(param_3 + 4) ^
             ((uint)(param_2 == DAT_00d38904) << 0x1e ^ *(uint *)(param_3 + 4)) & 0x40000000;
        *(undefined4 *)param_3 = 0;
        return 1;
      }
    }
    else if ((param_1 != 0x9a) || (*(int *)(DAT_00d76f78 + 0x460) == 0)) goto LAB_0097eeb1;
    break;
  case 0x9c:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 0x10;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^ ((uint)(param_2 != 0) << 4 ^ *(uint *)(param_3 + 4)) & 0x10;
    *(undefined4 *)param_3 = 0;
    return 1;
  case 0xab:
    *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) | 0x38000000;
    *(uint *)(param_3 + 4) =
         *(uint *)(param_3 + 4) ^ (param_2 << 0x1b ^ *(uint *)(param_3 + 4)) & 0x38000000;
    *(undefined4 *)param_3 = 0;
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CDx9StateBlock::PackSamplerState
// =================================================
int __cdecl
CDx9StateBlock::PackSamplerState
          (ulong param_1,_D3DSAMPLERSTATETYPE param_2,ulong param_3,SPackedDesc *param_4)
{
{
  int iVar1;
  
  switch(param_2) {
  case 1:
  case 2:
  case 5:
  case 6:
  case 7:
    iVar1 = (param_1 >> 2) + 1;
    break;
  default:
    return 0;
  case 9:
    iVar1 = (param_1 >> 3) + 6;
  }
  *(int *)param_4 = iVar1;
  *(undefined4 *)(param_4 + 4) = 0;
  *(undefined4 *)(param_4 + 8) = 0;
                    /* WARNING: Could not recover jumptable at 0x0097f037. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)(&PTR_LAB_0097f138)[param_2 - 1])();
  return iVar1;
}
}

// =================================================
// Function: CDx9StateBlock::PackTexStage
// =================================================
int __cdecl
CDx9StateBlock::PackTexStage
          (ulong param_1,_D3DTEXTURESTAGESTATETYPE param_2,ulong param_3,SPackedDesc *param_4)
{
{
  byte bVar1;
  int iVar2;
  
  switch(param_2) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 0x1c:
    iVar2 = param_1 + 10;
    break;
  default:
    return 0;
  case 0xb:
  case 0x18:
    iVar2 = (param_1 >> 2) + 8;
    break;
  case 0x1a:
  case 0x1b:
    iVar2 = param_1 + 0x12;
  }
  *(int *)param_4 = iVar2;
  bVar1 = (&DAT_0097e84b)[param_2];
  *(undefined4 *)(param_4 + 4) = 0;
  *(undefined4 *)(param_4 + 8) = 0;
                    /* WARNING: Could not recover jumptable at 0x0097e5e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)(&PTR_LAB_0097e81c)[bVar1])();
  return iVar2;
}
}

// =================================================
// Function: CDx9StateBlock::RecordSetSamplerFilter
// =================================================
void __thiscall
CDx9StateBlock::RecordSetSamplerFilter
          (void *this,CDx9StateBlock *param_1,ulong param_2,EGxTexFilter param_3,int param_4)
{
{
  ulong unaff_ESI;
  ulong unaff_EDI;
  
  RecordSetSamplerState
            (this,param_1,5,*(_D3DSAMPLERSTATETYPE *)(&DAT_00bd26f8 + param_2 * 4),unaff_EDI);
  if (param_4 != 0) {
    RecordSetSamplerState
              (this,param_1,7,*(_D3DSAMPLERSTATETYPE *)(&DAT_00bd26e8 + param_2 * 4),unaff_ESI);
    return;
  }
  RecordSetSamplerState(this,param_1,7,0,unaff_ESI);
  return;
}
}

// =================================================
// Function: CDx9StateBlock::RecordSetSamplerState
// =================================================
void __thiscall
CDx9StateBlock::RecordSetSamplerState
          (void *this,CDx9StateBlock *param_1,ulong param_2,_D3DSAMPLERSTATETYPE param_3,
          ulong param_4)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  SPackedDesc *pSVar4;
  SHmsItem_CallbackSortCustom_Elem *pSVar5;
  SSamplerState *pSVar6;
  ulong unaff_EBX;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *pCVar7;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  void *pvVar9;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *pCVar10;
  uint unaff_retaddr;
  int in_stack_00000014;
  undefined4 in_stack_00000018;
  SPackedDesc local_c [4];
  int local_8;
  
  iVar1 = PackSamplerState((ulong)param_1,param_2,param_3,local_c);
  if (iVar1 == 0) {
    pvVar9 = (void *)((int)this + 0x48);
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(pvVar9,unaff_EDI);
    pCVar10 = (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (pvVar9,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar10,
                            (ulong)unaff_ESI);
        if ((byte)pSVar3[8] == param_3) break;
        pCVar10 = pCVar10 + 1;
      } while (pCVar10 < pCVar2);
    }
    if (pCVar10 == (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)pCVar2) {
      CFastBufferCat<struct_CHmsViewport::SVisibleCamera,struct_CHmsViewport::SVisibleZoneCat>::
      SetCatCount(pvVar9,(CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                          *)(pCVar2 + 1),(ulong)unaff_ESI);
      pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](pvVar9,pCVar2,unaff_EBP)
      ;
      pSVar3[8] = param_4._0_1_;
      unaff_ESI = pCVar2;
    }
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
             ::SetParsingCat(pvVar9,pCVar10,1,(ulong)unaff_ESI);
    pCVar7 = (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
              *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat>::operator[]
                           (pvVar9,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar7,
                            unaff_EBP);
        if (*(int *)pSVar3 == in_stack_00000014) break;
        pCVar7 = pCVar7 + 1;
      } while (pCVar7 < pCVar2);
    }
    if (pCVar7 == (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                   *)pCVar2) {
      pSVar5 = CFastBufferCat<struct_CDx9StateBlock::STexStageState,struct_CDx9StateBlock::STexStageCat>
               ::AddNewElemInCat(pvVar9,(CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat>
                                         *)pCVar10,unaff_EBP);
      *(int *)pSVar5 = in_stack_00000014;
    }
    pSVar6 = CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
             ::GetElemInCat(pvVar9,pCVar7,(ulong)pCVar10,unaff_EBP);
    *(undefined4 *)(pSVar6 + 4) = in_stack_00000018;
    return;
  }
  pvVar9 = (void *)((int)this + 0x6c);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(pvVar9,unaff_EDI);
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (pvVar9,pCVar8,(ulong)unaff_ESI);
      if (*(int *)pSVar3 == local_8) break;
      pCVar8 = pCVar8 + 1;
    } while (pCVar8 < pCVar2);
  }
  if (pCVar8 == pCVar2) {
    pSVar4 = CFastArray<struct_CDx9StateBlock::SPackedDesc>::AddNewTailElem
                       (pvVar9,(CFastArray<struct_CDx9StateBlock::SPackedDesc> *)unaff_ESI);
    *(int *)pSVar4 = local_8;
    *(undefined4 *)(pSVar4 + 4) = 0;
    *(undefined4 *)(pSVar4 + 8) = 0;
  }
  else {
    pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (pvVar9,pCVar8,(ulong)unaff_ESI);
    *(uint *)(pSVar3 + 4) = *(uint *)(pSVar3 + 4) & ~unaff_retaddr;
  }
  pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](pvVar9,pCVar8,unaff_EBP);
  *(uint *)(pSVar3 + 4) = *(uint *)(pSVar3 + 4) | (uint)param_1;
  pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[](pvVar9,pCVar8,unaff_EBX);
  *(uint *)(pSVar3 + 8) = *(uint *)(pSVar3 + 8) | unaff_retaddr;
  return;
}
}

// =================================================
// Function: CDx9StateBlock::RecordSetTexture
// =================================================
void __thiscall
CDx9StateBlock::RecordSetTexture
          (void *this,CDx9StateBlock *param_1,ulong param_2,CPlugBitmap *param_3)
{
{
  void *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  SBitmapSpecular *pSVar3;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 in_stack_00000014;
  
  this_00 = (void *)((int)this + 0x18);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_SFastCat>::operator[]
                         (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar4,unaff_ESI
                         );
      if (param_2 == *(uint *)pSVar2) {
        pSVar2 = CFastBuffer<struct_SFastCat>::operator[]
                           (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar4,
                            unaff_EBP);
        *(undefined4 *)(pSVar2 + 4) = in_stack_00000014;
        return;
      }
    } while ((*(uint *)pSVar2 <= param_2) && (pCVar4 = pCVar4 + 1, pCVar4 < pCVar1));
  }
  pSVar3 = CFastArray<struct_CPlugVertexStream::SDataDecl>::InsertNewElemAt
                     (this_00,pCVar4,unaff_ESI);
  *(ulong *)pSVar3 = param_2;
  pSVar2 = CFastBuffer<struct_SFastCat>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar4,unaff_EBP);
  *(undefined4 *)(pSVar2 + 4) = in_stack_00000014;
  if ((param_2 < 0x10) &&
     (*(CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> **)(param_2 + 0x20) <= pCVar4)) {
    *(CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> **)(param_2 + 0x20) = pCVar4 + 1;
  }
  return;
}
}

// =================================================
// Function: CDx9StateBlock::ResetCache
// =================================================
void __cdecl CDx9StateBlock::ResetCache(void)
{
{
  undefined *this;
  int iVar1;
  int *piVar2;
  
  piVar2 = DAT_00d76f70;
  (**(code **)(*DAT_00d76f70 + 0xc4))(DAT_00d76f70,&DAT_00d75b18);
  DAT_00d388f4 = 0xffffffff;
  DAT_00d388f8 = 0xffff;
  this = &DAT_00d77054;
  iVar1 = 2;
  do {
    CFastBuffer<class_GmVec4>::FillWith
              (this,(CFixedArray<unsigned_char,8,unsigned_long> *)&stack0xffffffe8,(uchar *)piVar2);
    this = this + 0xc;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}
}

// =================================================
// Function: CDx9StateBlock::UnlockRenderState
// =================================================
void __cdecl CDx9StateBlock::UnlockRenderState(_D3DRENDERSTATETYPE param_1,ulong param_2)
{
{
  int local_c [2];
  uint local_4;
  
  *(undefined4 *)(&DAT_00d75f30 + param_1 * 4) = 0;
  if (*(int *)(&DAT_00d75c20 + param_1 * 4) != 0) {
    PackRenderState(param_1,0xffffffff,(SPackedDesc *)local_c);
    *(uint *)(&DAT_00d76ed8 + local_c[0] * 4) = *(uint *)(&DAT_00d76ed8 + local_c[0] * 4) | local_4;
  }
  FilterRenderState(param_1,param_2);
  return;
}
}

