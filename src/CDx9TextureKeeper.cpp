// Class implementation: CDx9TextureKeeper

// =================================================
// Function: CDx9TextureKeeper::AddSkipLevelExtDelta
// =================================================
void __thiscall
CDx9TextureKeeper::AddSkipLevelExtDelta
          (void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2,int param_3,char *param_4)
{
{
  void *this_00;
  void *this_01;
  uint *puVar1;
  CDx9TextureKeeper *pCVar2;
  int iVar3;
  bool bVar4;
  CPlugBitmap *pCVar5;
  uint uVar6;
  int extraout_EAX;
  CPlugFileGpuBuilder *pCVar7;
  CPlugFileGpuBuilder *pCVar8;
  uint uVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  SCasterCat *pSVar11;
  ulong uVar12;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar13;
  char *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  CPlugFileGpuBuilder *unaff_EBP;
  CDx9VStreamKeeper *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar15;
  ulong unaff_EDI;
  ulong uVar16;
  void *in_stack_00000018;
  char *in_stack_00000020;
  int in_stack_00000024;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000002c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack00000030;
  char *pcVar17;
  CPlugBitmap *pCVar18;
  char *in_stack_ffffffe8;
  char *in_stack_ffffffec;
  CPlugFileGpuBuilder *pCVar19;
  int in_stack_fffffff0;
  char *pcVar20;
  CFastBuffer<class_CCrystalFace*> *pCVar21;
  undefined1 *puVar22;
  
  pCVar18 = param_2;
  puVar22 = &LAB_00aea138;
  ExceptionList = &stack0xfffffff4;
  pCVar5 = param_2 + (*(uint *)((int)this + 0x20) & 7);
  param_2 = pCVar5;
  if ((pCVar5 != (CPlugBitmap *)0x0) &&
     (param_2 = (CPlugBitmap *)&DAT_00000007, pCVar5 < (CPlugBitmap *)&DAT_00000007)) {
    param_2 = pCVar5;
  }
  if (param_2 != (CPlugBitmap *)(*(uint *)((int)this + 0x20) & 7)) {
    if (0 < (int)pCVar18) {
      if ((*(uint *)((int)this + 0x20) & 8) == 0) {
        in_stack_ffffffec =
             (char *)GetLevelByteSize(this,(CDx9TextureKeeper *)pCVar18,1,
                                      DAT_00cca150 ^ (uint)&stack0xffffffd8);
        uVar16 = GetLevelByteSize(this,(CDx9TextureKeeper *)0x0,1,unaff_EDI);
        param_1 = (CDx9TextureKeeper *)(uVar16 - in_stack_fffffff0);
      }
      else {
        param_1 = (CDx9TextureKeeper *)
                  GetLevelByteSize(this,(CDx9TextureKeeper *)0x0,(ulong)pCVar18,
                                   DAT_00cca150 ^ (uint)&stack0xffffffd8);
        in_stack_ffffffec = "deallocated";
      }
    }
    *(uint *)((int)this + 0x20) =
         *(uint *)((int)this + 0x20) ^ (*(uint *)((int)this + 0x20) ^ (uint)param_2) & 7;
    if ((int)pCVar18 < 0) {
      if ((*(uint *)((int)this + 0x20) & 8) == 0) {
        uVar16 = GetLevelByteSize(this,(CDx9TextureKeeper *)-(int)pCVar18,1,(ulong)unaff_ESI);
        unaff_ESI = (CDx9VStreamKeeper *)0x1;
        uVar12 = GetLevelByteSize(this,(CDx9TextureKeeper *)0x0,1,(ulong)unaff_EBP);
        param_1 = (CDx9TextureKeeper *)(uVar12 - uVar16);
      }
      else {
        param_1 = (CDx9TextureKeeper *)
                  GetLevelByteSize(this,(CDx9TextureKeeper *)0x0,-(int)pCVar18,(ulong)unaff_ESI);
      }
    }
    bVar4 = false;
    if (*(int *)((int)this + 0x10) == 0) {
      pCVar8 = (CPlugFileGpuBuilder *)param_4;
      (**(code **)(**(int **)((int)this + 0xc) + 0x2c))(*(int **)((int)this + 0xc));
      (**(code **)(**(int **)((int)this + 0xc) + 0x30))(*(int **)((int)this + 0xc));
      iVar3 = DAT_00d7569c;
      bVar4 = true;
      if ((int)pCVar18 < 1) {
        *(int *)(DAT_00d7569c + 0x210) = (int)(param_1 + *(int *)(DAT_00d7569c + 0x210));
        puVar1 = (uint *)(iVar3 + 0x1f8);
        pCVar2 = (CDx9TextureKeeper *)*puVar1;
        *puVar1 = *puVar1 - (int)param_1;
        *(int *)(iVar3 + 0x1fc) =
             (*(int *)(iVar3 + 0x1fc) - ((int)param_1 >> 0x1f)) - (uint)(pCVar2 < param_1);
        *(int *)((int)this + 0x30) = (int)(param_1 + *(int *)((int)this + 0x30));
      }
      else {
        uVar6 = -(int)param_1;
        *(int *)(DAT_00d7569c + 0x210) = *(int *)(DAT_00d7569c + 0x210) + uVar6;
        puVar1 = (uint *)(iVar3 + 0x1f8);
        uVar9 = *puVar1;
        *puVar1 = (uint)(param_1 + *puVar1);
        *(int *)(iVar3 + 0x1fc) =
             (*(int *)(iVar3 + 0x1fc) - ((int)uVar6 >> 0x1f)) - (uint)(uVar9 < uVar6);
        *(int *)((int)this + 0x30) = *(int *)((int)this + 0x30) - (int)param_1;
      }
    }
    else {
      Release(this,unaff_ESI);
      unaff_ESI = (CDx9VStreamKeeper *)0x0;
      pCVar8 = (CPlugFileGpuBuilder *)0x0;
      pCVar18 = (CPlugBitmap *)0x0;
      Create(this,(CDx9VertexBuffer *)param_4);
      if ((extraout_EAX != 0) && (*(int *)((int)this + 8) != 0)) {
        UpLoadTexture(this,(CDx9TextureKeeper *)param_4,pCVar18);
      }
    }
    pcVar20 = (char *)0x0;
    pcVar17 = " KBytes ";
    uVar16 = 0;
    pCVar19 = (CPlugFileGpuBuilder *)in_stack_ffffffec;
    pCVar21 = (CFastBuffer<class_CCrystalFace*> *)PTR_DAT_00bbf7d8;
    pCVar7 = CFastString::operator<<
                       ((CFastString *)&stack0xfffffff0,(CPlugFileGpuBuilder *)"[Dx9] ",
                        (char *)((uint)(param_1 + 0x3ff) >> 10));
    pCVar7 = CFastString::operator<<
                       ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)pcVar17,in_stack_ffffffec);
    pCVar8 = CFastString::operator<<((CFastString *)pCVar7,pCVar8,(char *)unaff_ESI);
    CFastString::operator<<((CFastString *)pCVar8,unaff_EBP,unaff_EBX);
    pCVar8 = (CPlugFileGpuBuilder *)&DAT_00b2c98c;
    if (bVar4) {
      pcVar17 = " with SetLOD() ";
    }
    else {
      pcVar17 = " with Release()+Create() ";
    }
    pCVar7 = CFastString::operator<<
                       ((CFastString *)&stack0x00000000,(CPlugFileGpuBuilder *)pcVar17,
                        in_stack_00000020);
    pCVar8 = CFastString::operator<<((CFastString *)pCVar7,pCVar8,in_stack_ffffffe8);
    CFastString::operator<<((CFastString *)pCVar8,pCVar19,pcVar20);
    if (param_4 != PTR_DAT_00bbf7d8) {
      pcVar17 = param_4 + -1;
      if ((param_4[-1] & 0x80U) != 0) {
        pcVar17 = param_4 + -4;
      }
      operator_delete__(pcVar17);
    }
    uVar9 = *(uint *)(in_stack_00000024 + 0x4c) & 0xff;
    if ((((uVar9 == 3) || (uVar9 == 0xf)) || (uVar9 == 0x16)) || (uVar9 == 7)) {
      pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CFastBuffer<class_CCrystalFace*>::GetCount((void *)(DAT_00d7569c + 0x264),pCVar21);
      pCStack00000030 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar10 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pCVar15 = pCStack00000030;
          pSVar11 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                              ((void *)(DAT_00d7569c + 0x264),pCStack00000030,(ulong)puVar22);
          if (*(int *)(*(int *)(pSVar11 + 8) + 0x118) != 0) {
            this_00 = (void *)(*(int *)(*(int *)(pSVar11 + 8) + 0x118) + 0x1c);
            puVar22 = (undefined1 *)0x968fe0;
            uVar12 = CFastBuffer<class_CCrystalFace*>::GetCount
                               (this_00,(CFastBuffer<class_CCrystalFace*> *)0x968fe0);
            pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            if (uVar12 != 0) {
              do {
                pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                    (this_00,pCVar14,(ulong)puVar22);
                iVar3 = *(int *)pSVar11;
                if ((*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x120) ==
                     in_stack_0000002c) ||
                   (*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0x124) ==
                    in_stack_0000002c)) {
                  pCVar15 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar3 + 0xe4);
                  this_01 = (void *)(*(int *)(DAT_00d7569c + 0x240) + 0x20);
                  puVar22 = (undefined1 *)0x969024;
                  pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                            CFastBuffer<class_CCrystalFace*>::GetCount
                                      (this_01,(CFastBuffer<class_CCrystalFace*> *)0x969024);
                  if (pCVar15 < pCVar13) {
                    puVar22 = (undefined1 *)0x969030;
                    pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                        (this_01,pCVar15,uVar16);
                    *(uint *)(*(int *)pSVar11 + 0x30) = *(uint *)(*(int *)pSVar11 + 0x30) | 0x20000;
                  }
                }
                pCVar14 = pCVar14 + 1;
                pCVar15 = pCStack00000030;
              } while (pCVar14 < in_stack_0000002c);
            }
          }
          pCStack00000030 = pCVar15 + 1;
        } while (pCStack00000030 < pCVar10);
      }
    }
  }
  ExceptionList = in_stack_00000018;
  return;
}
}

// =================================================
// Function: CDx9TextureKeeper::AutoGenMipMapGetSurface0
// =================================================
IDirect3DSurface9 * __thiscall
CDx9TextureKeeper::AutoGenMipMapGetSurface0(void *this,CDx9TextureKeeper *param_1)
{
{
  CFastBuffer<class_CSystemFidsFolder*> *pCVar1;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar2;
  SCasterCat *pSVar3;
  CMwNod *extraout_EAX;
  CFastString *this_00;
  undefined *puVar4;
  IDirect3DSurface9 *unaff_EBX;
  int *piVar5;
  CMwNod *this_01;
  EPixelUpdate in_stack_ffffff9c;
  int iVar6;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffa4;
  EGxTexAddress EVar7;
  EGxTexFilter EVar8;
  ulong uVar9;
  CFastBuffer<class_CCrystalFace*> *pCVar10;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar11;
  CMwNod *pCVar12;
  CFastBuffer<class_CSystemFidsFolder*> *pCStack_38;
  undefined1 auStack_30 [4];
  int iStack_2c;
  int iStack_28;
  CPlugBitmap *pCStack_24;
  undefined *puStack_20;
  undefined *puStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  pCVar12 = (CMwNod *)&stack0xfffffffc;
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00aea1a3;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((((*(byte *)((int)this + 0x20) & 8) != 0) && ((*(uint *)((int)this + 4) & 0x400) == 0)) &&
     (*(int *)(DAT_00d756a0 + 0x6d0) == 0)) {
    pCVar10 = *(CFastBuffer<class_CCrystalFace*> **)((int)this + 0xc);
    uVar9 = 0x969291;
    pCVar1 = (CFastBuffer<class_CSystemFidsFolder*> *)
             (**(code **)(*(int *)pCVar10 + 0x34))(pCVar10,DAT_00cca150 ^ (uint)&stack0xffffffb8);
    piVar5 = DAT_00d7569c + 0x557;
    iVar6 = 0x9692aa;
    pCVar11 = pCVar1;
    pCVar2 = (CFastBuffer<class_CSystemFidsFolder*> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(piVar5,in_stack_ffffffa4);
    if (pCVar2 < pCVar1) {
      pCVar2 = (CFastBuffer<class_CSystemFidsFolder*> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(piVar5,pCVar10);
      CFastArray<class_CMwNodRef<class_CPlugBitmap>_>::SetCount(piVar5,pCVar1,uVar9);
      iStack_2c = 1 << ((byte)pCVar2 & 0x1f);
      iStack_28 = iStack_2c;
      if (pCVar2 < pCVar1) {
        do {
          puVar4 = PTR_DAT_00bbf7d8;
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (piVar5,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar2,
                              (ulong)pCVar10);
          puStack_20 = (undefined *)0x0;
          uStack_c = 0;
          EVar7 = 0x96930c;
          pCVar10 = (CFastBuffer<class_CCrystalFace*> *)pCVar2;
          puStack_1c = puVar4;
          CFastString::Format(this_00,(CFastString *)&puStack_20,"Dx9AutoMipChain%02d");
          uVar9 = 0x78;
          EVar8 = 0x969313;
          pCStack_24 = operator_new(0x78);
          if (pCStack_24 == (CPlugBitmap *)0x0) {
            this_01 = (CMwNod *)0x0;
          }
          else {
            CPlugBitmap::CPlugBitmap(pCStack_24,(CPlugBitmap *)pCVar11);
            this_01 = extraout_EAX;
          }
          if (this_01 != *(CMwNod **)pSVar3) {
            if (this_01 != (CMwNod *)0x0) {
              pCVar11 = (CFastBuffer<class_CSystemFidsFolder*> *)0x969344;
              CMwNod::MwAddRef(this_01,pCVar12);
            }
            if (*(CMwNod **)pSVar3 != (CMwNod *)0x0) {
              pCVar11 = (CFastBuffer<class_CSystemFidsFolder*> *)0x96934f;
              CMwNod::MwRelease(*(CMwNod **)pSVar3,pCVar12);
            }
            *(CMwNod **)pSVar3 = this_01;
          }
          CPlugBitmap::GenerateRender
                    (*(CPlugBitmap **)pSVar3,(CPlugBitmap *)&stack0xffffffc0,(GmNat2 *)0x1,0,0,
                     in_stack_ffffff9c);
          CPlugBitmap::SetMipMapping(*(CPlugBitmap **)pSVar3,(CPlugBitmap *)0x0,iVar6);
          in_stack_ffffff9c = 2;
          CPlugBitmap::SetDefaultTexAddress(*(CPlugBitmap **)pSVar3,(CPlugBitmap *)0x2,2,0,EVar7);
          iVar6 = 0x969382;
          CPlugBitmap::SetDefaultTexFilter(*(CPlugBitmap **)pSVar3,(CPlugBitmap *)0x1,EVar8);
          CPlugBitmap::SetMipLevelSkipCountMax(*(CPlugBitmap **)pSVar3,(CPlugBitmap *)0x0,uVar9);
          iStack_2c = iStack_2c << 1;
          iStack_28 = iStack_28 << 1;
          puStack_10 = (undefined1 *)0xffffffff;
          if (puStack_20 != PTR_DAT_00bbf7d8) {
            puVar4 = puStack_20 + -1;
            if ((puStack_20[-1] & 0x80) != 0) {
              puVar4 = puStack_20 + -4;
            }
            operator_delete__(puVar4);
            pCStack_24 = (CPlugBitmap *)0x0;
            puStack_20 = PTR_DAT_00bbf7d8;
          }
          pCVar2 = pCVar2 + 1;
          pCVar1 = pCStack_38;
        } while (pCVar2 < pCStack_38);
      }
    }
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (piVar5,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(pCVar1 + -1),
                        (ulong)pCVar10);
    iVar6 = *(int *)pSVar3;
    if (*(int *)(iVar6 + 0x14) == 0) {
      (**(code **)(*DAT_00d7569c + 0xb0))(iVar6);
    }
    piVar5 = *(int **)(*(int *)(iVar6 + 0x14) + 0xc);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x48))(piVar5,0,auStack_30);
      ExceptionList = puStack_20;
      return unaff_EBX;
    }
  }
  ExceptionList = local_14;
  return (IDirect3DSurface9 *)0x0;
}
}

// =================================================
// Function: CDx9TextureKeeper::AutoGenMipMapSetDirty
// =================================================
void __thiscall CDx9TextureKeeper::AutoGenMipMapSetDirty(void *this,CDx9TextureKeeper *param_1)
{
{
  int *piVar1;
  CVisionViewportDx9 *pCVar2;
  uint uVar3;
  int *piVar4;
  SCasterCat *pSVar5;
  int iVar6;
  int *unaff_EBX;
  int *piVar7;
  CVisionViewportDx9 *pCVar8;
  CVisionViewportDx9 *unaff_ESI;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  CPlugBitmap *pCVar12;
  CPlugBitmap *pCVar13;
  int *piVar14;
  CPlugBitmap *pCVar15;
  CVisionViewportDx9 *pCVar16;
  CPlugBitmap *local_18;
  CVisionViewportDx9 *pCStack_14;
  uint local_10;
  CVisionViewportDx9 *pCStack_c;
  uint local_8;
  void *local_4;
  
  local_4 = this;
  if ((*(uint *)((int)this + 4) & 0x400) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x38))();
    return;
  }
  if (*(int *)(DAT_00d756a0 + 0x6d0) == 0) {
    pCVar15 = *(CPlugBitmap **)((int)this + 0xc);
    local_8 = (uint)(*(int *)this == 5);
    local_18 = pCVar15;
    uVar3 = (**(code **)(*(CVisionViewportDx9 **)pCVar15 + 0x34))();
    pCStack_14 = DAT_00d7569c + 0x155c;
    uVar9 = 0;
    pCVar8 = (CVisionViewportDx9 *)0x0;
    if (uVar3 != 0) {
      do {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCStack_14,
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((uVar3 - uVar9) + -1)
                            ,(ulong)pCVar15);
        pCVar2 = *(CVisionViewportDx9 **)pSVar5;
        if (pCVar8 != (CVisionViewportDx9 *)0x0) {
          pCStack_c = DAT_00d7569c;
          pCVar16 = pCVar2;
          iVar6 = (**(code **)(*(int *)DAT_00d7569c + 0xb4))();
          if (iVar6 != 0) {
            func_0x009b4e70(*(undefined4 *)(pCVar2 + 0x14),0,0,0,0);
          }
          CVisionViewportDx9::TextureBlitOnFullQuad(DAT_00d7569c,pCVar8,(CPlugBitmap *)pCVar16);
        }
        if (local_8 == 0) {
          pCVar15 = (CPlugBitmap *)&pCStack_14;
          pCVar12 = (CPlugBitmap *)0x9634ad;
          pCVar13 = local_18;
          (**(code **)(*(CVisionViewportDx9 **)local_18 + 0x48))(local_18,uVar9);
        }
        else {
          pCVar15 = (CPlugBitmap *)&pCStack_14;
          pCVar13 = (CPlugBitmap *)&DAT_00000004;
          pCVar12 = local_18;
          (**(code **)(*(CVisionViewportDx9 **)local_18 + 0x48))(local_18,4,uVar9);
        }
        CVisionViewportDx9::RenderTargetSet
                  (DAT_00d7569c,unaff_ESI,(IDirect3DSurface9 *)0x0,(IDirect3DSurface9 *)pCStack_14,
                   (CDx9TextureKeeper *)0x0,(CDx9TextureKeeper *)0x0,(ulong *)pCVar12);
        CVisionViewportDx9::TextureBlitOnFullQuad(DAT_00d7569c,pCVar2,pCVar13);
        (**(code **)(*unaff_EBX + 8))(unaff_EBX);
        uVar9 = uVar9 + 1;
        pCVar8 = pCVar2;
      } while (uVar9 < uVar3);
    }
  }
  else {
    piVar1 = *(int **)((int)this + 0xc);
    iVar6 = *(int *)this;
    local_10 = (uint)(iVar6 == 5);
    uVar3 = (**(code **)(*piVar1 + 0x34))();
    if (1 < uVar3) {
      piVar7 = (int *)(*(uint *)(DAT_00d756a0 + 0x558) >> 8 & 2);
      if ((iVar6 == 5) == 0) {
        piVar10 = (int *)0x963387;
        piVar11 = piVar1;
        (**(code **)(*piVar1 + 0x48))(piVar1,0,&local_18);
      }
      else {
        piVar11 = (int *)&DAT_00000004;
        piVar10 = piVar1;
        (**(code **)(*piVar1 + 0x48))(piVar1,4);
      }
      piVar4 = (int *)0x0;
      uVar9 = 1;
      piVar14 = (int *)0x0;
      if (1 < uVar3) {
        do {
          if (unaff_ESI == (CVisionViewportDx9 *)0x0) {
            (**(code **)(*piVar1 + 0x48))(piVar1,uVar9,&stack0xffffffd4);
            piVar4 = piVar14;
          }
          else {
            (**(code **)(*piVar1 + 0x48))(piVar1,4);
            piVar4 = piVar14;
          }
          (**(code **)(*DAT_00d75698 + 0x88))(DAT_00d75698,piVar11,0,piVar10,0);
          (**(code **)(*piVar7 + 8))(piVar7);
          uVar9 = uVar9 + 1;
          piVar14 = piVar4;
        } while (uVar9 < uVar3);
      }
      (**(code **)(*piVar4 + 8))(piVar4);
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CDx9TextureKeeper::BiggerMipGetSizeToWin
// =================================================
ulong __thiscall
CDx9TextureKeeper::BiggerMipGetSizeToWin
          (void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2,ulong *param_3)
{
{
  uint uVar1;
  ulong uVar2;
  CDx9TextureKeeper *pCVar3;
  ulong uVar4;
  ulong unaff_EBX;
  int iVar5;
  ulong unaff_ESI;
  CPlugBitmap *unaff_EDI;
  
  if (param_2 == (CPlugBitmap *)0x0) {
    iVar5 = 1;
  }
  else {
    iVar5 = *(int *)param_2;
  }
  uVar1 = *(uint *)(param_1 + 0x4c);
  if (((-1 < (int)uVar1) &&
      (((((uVar1 & 0x100000) != 0 || (uVar1 = uVar1 & 0xff, uVar1 == 3)) || (uVar1 == 0xf)) ||
       ((uVar1 == 0x16 || (uVar1 == 7)))))) && (((byte)*(undefined4 *)((int)this + 0x20) & 7) != 7))
  {
    uVar2 = GetMipLevelSkipCountMax(this,param_1,unaff_EDI);
    uVar1 = *(uint *)((int)this + 0x1c) >> 0x1c;
    if (*(int *)((int)this + 0x10) == 0) {
      uVar1 = uVar1 + (*(uint *)((int)this + 0x20) & 7);
    }
    if (uVar2 < uVar1) {
      uVar1 = uVar2;
    }
    if (uVar1 + iVar5 <= uVar2) {
      uVar2 = uVar1 + iVar5;
    }
    pCVar3 = (CDx9TextureKeeper *)(-(uint)(uVar2 - uVar1 != 0) & uVar2 - uVar1);
    if (param_2 != (CPlugBitmap *)0x0) {
      *(CDx9TextureKeeper **)param_2 = pCVar3;
    }
    if (pCVar3 != (CDx9TextureKeeper *)0x0) {
      if ((*(byte *)((int)this + 0x20) & 8) != 0) {
        uVar2 = GetLevelByteSize(this,(CDx9TextureKeeper *)0x0,(ulong)pCVar3,unaff_ESI);
        return uVar2;
      }
      uVar2 = GetLevelByteSize(this,pCVar3,1,unaff_ESI);
      uVar4 = GetLevelByteSize(this,(CDx9TextureKeeper *)0x0,1,unaff_EBX);
      return uVar4 - uVar2;
    }
  }
  return 0;
}
}

// =================================================
// Function: CDx9TextureKeeper::BiggerMipLevelFree
// =================================================
void __thiscall
CDx9TextureKeeper::BiggerMipLevelFree
          (void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2,ulong param_3)
{
{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  CPlugFileGpuBuilder *pCVar5;
  undefined *puVar6;
  ulong unaff_ESI;
  char *unaff_EDI;
  int *piVar7;
  char *pcVar8;
  char *pcVar9;
  CPlugFileGpuBuilder *pCVar10;
  char *in_stack_ffffffc4;
  CPlugFileGpuBuilder *pCVar11;
  char *pcVar12;
  CPlugFileGpuBuilder *pCVar13;
  char *pcVar14;
  undefined4 local_18;
  undefined *local_14;
  undefined *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00aea170;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar11 = (CPlugFileGpuBuilder *)0x9690a7;
  uVar1 = BiggerMipGetSizeToWin
                    (this,param_1,(CPlugBitmap *)&param_2,
                     (ulong *)(DAT_00cca150 ^ (uint)&stack0xffffffd8));
  if (uVar1 != 0) {
    piVar7 = *(int **)(param_1 + 8);
    if ((piVar7 == (int *)0x0) && (*(int *)(param_1 + 0x48) != 0)) {
      piVar7 = *(int **)(*(int *)(param_1 + 0x48) + 8);
    }
    local_18 = 0;
    local_14 = PTR_DAT_00bbf7d8;
    if (piVar7 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar7 + 0x10))();
      if (iVar2 != 0) {
        CFastStringInt::GetLatin1(piVar7 + 0x1d,(CFastStringInt *)&local_18);
      }
    }
    if (*(int *)((int)this + 0xc) == 0) {
      uVar3 = (*(uint *)((int)this + 0x20) & 7) + param_3;
      if (0xf < uVar3) {
        uVar3 = 0xf;
      }
      if ((*(uint *)((int)this + 0x20) & 8) == 0) {
        pcVar12 = "j\x01j";
        uVar1 = GetLevelByteSize(this,(CDx9TextureKeeper *)param_3,1,(ulong)unaff_EDI);
        pcVar14 = (char *)0x0;
        pCVar13 = (CPlugFileGpuBuilder *)0x969164;
        uVar4 = GetLevelByteSize(this,(CDx9TextureKeeper *)0x0,1,unaff_ESI);
        uVar4 = uVar4 - uVar1;
      }
      else {
        pCVar13 = (CPlugFileGpuBuilder *)0x0;
        pcVar12 = (char *)0x96914d;
        pcVar14 = (char *)param_3;
        uVar4 = GetLevelByteSize(this,(CDx9TextureKeeper *)0x0,param_3,(ulong)unaff_EDI);
      }
      pCVar10 = (CPlugFileGpuBuilder *)&DAT_00b2c98c;
      pcVar9 = &stack0xffffffd4;
      pcVar8 = " KBytes allocation skipped ";
      local_14 = (undefined *)CONCAT31(local_14._1_3_,1);
      pCVar5 = CFastString::operator<<
                         ((CFastString *)&stack0xffffffdc,(CPlugFileGpuBuilder *)"[Dx9] ",
                          (char *)(uVar4 + 0x3ff >> 10));
      pCVar5 = CFastString::operator<<((CFastString *)pCVar5,(CPlugFileGpuBuilder *)pcVar8,pcVar9);
      pCVar5 = CFastString::operator<<((CFastString *)pCVar5,pCVar10,in_stack_ffffffc4);
      pCVar11 = CFastString::operator<<((CFastString *)pCVar5,pCVar11,pcVar12);
      CFastString::operator<<((CFastString *)pCVar11,pCVar13,pcVar14);
      *(uint *)((int)this + 0x20) =
           *(uint *)((int)this + 0x20) ^ (*(uint *)((int)this + 0x20) ^ uVar3) & 7;
      if (local_c != PTR_DAT_00bbf7d8) {
        puVar6 = local_c + -1;
        if ((local_c[-1] & 0x80) != 0) {
          puVar6 = local_c + -4;
        }
        operator_delete__(puVar6);
      }
    }
    else {
      AddSkipLevelExtDelta(this,param_1,(CPlugBitmap *)param_3,(int)local_14,unaff_EDI);
    }
    if (local_14 != PTR_DAT_00bbf7d8) {
      puVar6 = local_14 + -1;
      if ((local_14[-1] & 0x80) != 0) {
        puVar6 = local_14 + -4;
      }
      operator_delete__(puVar6);
    }
  }
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CDx9TextureKeeper::GetLevelByteSize
// =================================================
ulong __thiscall
CDx9TextureKeeper::GetLevelByteSize
          (void *this,CDx9TextureKeeper *param_1,ulong param_2,ulong param_3)
{
{
  int iVar1;
  ulong uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar5 = *(uint *)((int)this + 0x24);
  uVar6 = *(uint *)((int)this + 0x28);
  uVar8 = *(uint *)((int)this + 0x2c);
  if (*(int *)((int)this + 0x10) == 0) {
    bVar3 = (byte)*(undefined4 *)((int)this + 0x20) & 7;
    uVar5 = uVar5 >> bVar3;
    uVar6 = uVar6 >> bVar3;
    uVar8 = uVar8 >> bVar3;
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    if (uVar6 == 0) {
      uVar6 = 1;
    }
    if (uVar8 == 0) {
      uVar8 = 1;
    }
  }
  iVar7 = (-(uint)(*(int *)this != 5) & 0xfffffffb) + 6;
  uVar4 = *(uint *)((int)this + 0x18) & 0xff;
  if (uVar4 != 0) {
    uVar2 = CPlugFileImg::GetMipMapTotalNbPixel(uVar5,uVar6,(ulong)param_1,param_2,uVar8);
    return uVar2 * uVar4 * iVar7;
  }
  iVar1 = *(int *)((int)this + 0x14);
  uVar2 = CPlugFileImg::GetMipMapTotalNbBlock4x4(uVar5,uVar6,(ulong)param_1,param_2,uVar8);
  return uVar2 * ((uint)(iVar1 != 0x31545844) * 8 + 8) * iVar7;
}
}

// =================================================
// Function: CDx9TextureKeeper::GetMipLevelSkipCountMax
// =================================================
ulong __thiscall
CDx9TextureKeeper::GetMipLevelSkipCountMax
          (void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2)
{
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar2 = *(uint *)((int)this + 0x24);
  uVar3 = *(uint *)(param_1 + 0x50) >> 0x19 & 0xf;
  param_1 = (CDx9TextureKeeper *)0x1;
  if (1 < uVar2) {
    bVar4 = false;
    iVar1 = 0;
    if (uVar2 != 0) {
      for (; (uVar2 >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
      }
    }
    if (uVar2 != 0) {
      bVar4 = uVar2 >> ((char)iVar1 + 1U & 0x1f) == 0;
    }
    if (bVar4) {
      param_1 = *(CDx9TextureKeeper **)((int)this + 0x24);
    }
  }
  uVar2 = *(uint *)((int)this + 0x28);
  if (1 < uVar2) {
    bVar4 = false;
    iVar1 = 0;
    if (uVar2 != 0) {
      for (; (uVar2 >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
      }
    }
    if (uVar2 != 0) {
      bVar4 = uVar2 >> ((char)iVar1 + 1U & 0x1f) == 0;
    }
    if ((bVar4) && (*(CDx9TextureKeeper **)((int)this + 0x28) < param_1)) {
      param_1 = *(CDx9TextureKeeper **)((int)this + 0x28);
    }
  }
  if ((CDx9TextureKeeper *)0x1 < param_1) {
    iVar1 = 0x1f;
    if (param_1 != (CDx9TextureKeeper *)0x0) {
      for (; (uint)param_1 >> iVar1 == 0; iVar1 = iVar1 + -1) {
      }
    }
    uVar2 = iVar1 - 4U & ((int)(iVar1 - 4U) < 1) - 1;
    if (uVar2 < uVar3) {
      uVar3 = uVar2;
    }
  }
  if (*(char *)((int)this + 0x18) == '\0') {
    param_1 = *(CDx9TextureKeeper **)((int)this + 0x24);
    if (*(CDx9TextureKeeper **)((int)this + 0x28) < *(CDx9TextureKeeper **)((int)this + 0x24)) {
      param_1 = *(CDx9TextureKeeper **)((int)this + 0x28);
    }
    iVar1 = 0x1f;
    if (param_1 != (CDx9TextureKeeper *)0x0) {
      for (; (uint)param_1 >> iVar1 == 0; iVar1 = iVar1 + -1) {
      }
    }
    uVar2 = iVar1 - 2U & ((int)(iVar1 - 2U) < 1) - 1;
    if (uVar2 < uVar3) {
      return uVar2;
    }
  }
  return uVar3;
}
}

// =================================================
// Function: CDx9TextureKeeper::ResetCache
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CDx9TextureKeeper::ResetCache(void)
{
{
  DAT_00d756a8 = 0xffffffff;
  _DAT_00d756ac = 0xffffffff;
  _DAT_00d756b0 = 0xffffffff;
  _DAT_00d756b4 = 0xffffffff;
  _DAT_00d756b8 = 0xffffffff;
  _DAT_00d756bc = 0xffffffff;
  _DAT_00d756c0 = 0xffffffff;
  _DAT_00d756c4 = 0xffffffff;
  _DAT_00d756c8 = 0xffffffff;
  _DAT_00d756cc = 0xffffffff;
  _DAT_00d756d0 = 0xffffffff;
  _DAT_00d756d4 = 0xffffffff;
  _DAT_00d756d8 = 0xffffffff;
  _DAT_00d756dc = 0xffffffff;
  _DAT_00d756e0 = 0xffffffff;
  _DAT_00d756e4 = 0xffffffff;
  _DAT_00d756e8 = 0xffffffff;
  _DAT_00d756ec = 0xffffffff;
  _DAT_00d756f0 = 0xffffffff;
  _DAT_00d756f4 = 0xffffffff;
  return;
}
}

// =================================================
// Function: CDx9TextureKeeper::RtWheelToCpuGetToRead
// =================================================
IDirect3DSurface9 * __thiscall
CDx9TextureKeeper::RtWheelToCpuGetToRead(void *this,CDx9TextureKeeper *param_1)
{
{
  void *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  int iVar4;
  ulong uVar5;
  CSystemEngine *extraout_ECX;
  CSystemEngine *this_01;
  CSystemEngine *extraout_ECX_00;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_EDI;
  ulong uVar6;
  uint unaff_retaddr;
  
  this_00 = (void *)((int)this + 0x68);
  pCVar1 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)this + 0x78);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
  if (pCVar2 <= pCVar1) {
    return (IDirect3DSurface9 *)0x0;
  }
  pSVar3 = CFastBuffer<class_GxColor>::operator[](this_00,pCVar1,unaff_EDI);
  if (*(int *)(pSVar3 + 4) != 0) {
    iVar4 = (**(code **)(**(int **)(pSVar3 + 4) + 0x1c))(*(int **)(pSVar3 + 4),&stack0x00000000,4,0)
    ;
    if (iVar4 == 1) {
      uVar6 = *(int *)((int)this + 0x74) + 1;
      uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
      if (uVar6 == uVar5) {
        uVar6 = 0;
      }
      this_01 = extraout_ECX;
      if (uVar6 != *(ulong *)((int)this + 0x78)) {
        return (IDirect3DSurface9 *)0x0;
      }
      do {
        CSystemEngine::Sleep(this_01,(CMwCmdBlock *)0x0,1);
        unaff_EBP = (CFastBuffer<class_CCrystalFace*> *)&DAT_00000004;
        iVar4 = (**(code **)(**(int **)(pSVar3 + 4) + 0x1c))
                          (*(int **)(pSVar3 + 4),&stack0x00000008,4,1);
        this_01 = extraout_ECX_00;
      } while (iVar4 == 1);
    }
    if (iVar4 != 0) {
      return (IDirect3DSurface9 *)0x0;
    }
  }
  CMwProfiler::GetTimeStamp((int64 *)&stack0x00000000);
  uVar5 = CMwProfiler::GetTimeFromDeltaTimeStamp
                    (CONCAT44(param_1 + (-(uint)(unaff_retaddr < *(uint *)(pSVar3 + 8)) -
                                        *(int *)(pSVar3 + 0xc)),
                              unaff_retaddr - *(uint *)(pSVar3 + 8)));
  *(ulong *)((int)this + 0x7c) = uVar5;
  uVar6 = *(int *)((int)this + 0x78) + 1;
  uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
  if (uVar6 == uVar5) {
    uVar6 = 0;
  }
  *(ulong *)((int)this + 0x78) = uVar6;
  return *(IDirect3DSurface9 **)pSVar3;
}
}

// =================================================
// Function: CDx9TextureKeeper::RtWheelToCpuGetToWrite
// =================================================
IDirect3DSurface9 * __thiscall
CDx9TextureKeeper::RtWheelToCpuGetToWrite(void *this,CDx9TextureKeeper *param_1)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<class_GxColor>::operator[]
                     ((void *)((int)this + 0x68),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)this + 0x74),
                      unaff_retaddr);
  return *(IDirect3DSurface9 **)pSVar1;
}
}

// =================================================
// Function: CDx9TextureKeeper::RtWheelToCpuInit
// =================================================
int __thiscall
CDx9TextureKeeper::RtWheelToCpuInit
          (void *this,CDx9TextureKeeper *param_1,GmNat2 *param_2,ulong param_3)
{
{
  void *this_00;
  CFastBuffer<class_GxVertex2> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  ulong unaff_EBP;
  CDx9TextureKeeper *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<class_GxVertex2> *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CDx9TextureKeeper *unaff_retaddr;
  ulong uStack00000018;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000020;
  
  pCVar4 = (CFastBuffer<class_GxVertex2> *)0x1;
  if (((byte)DAT_00d777ac & 2) != 0) {
    pCVar4 = (CFastBuffer<class_GxVertex2> *)param_2;
  }
  this_00 = (void *)((int)this + 0x68);
  pCVar1 = (CFastBuffer<class_GxVertex2> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (((pCVar1 != pCVar4) || (*(int *)((int)this + 0x80) != *(int *)param_2)) ||
     (*(int *)((int)this + 0x84) != *(int *)(param_2 + 4))) {
    RtWheelToCpuReleaseAll(this,unaff_ESI);
    *(undefined4 *)((int)this + 0x80) = *(undefined4 *)param_2;
    *(undefined4 *)((int)this + 0x84) = *(undefined4 *)(param_2 + 4);
    CFastBuffer<class_GmVec4>::AllocSetCount(this_00,pCVar4,unaff_EBP);
    uStack00000018 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBX);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (uStack00000018 != 0) {
      do {
        pSVar2 = CFastBuffer<class_GxColor>::operator[](this_00,pCVar5,(ulong)param_2);
        iVar3 = RtWheelToCpuInitOne(this,(CDx9TextureKeeper *)pSVar2,(SRtWheelToCpu *)unaff_retaddr,
                                    (GmNat2 *)param_1);
        if (iVar3 == 0) {
          if (in_stack_00000020 <= pCVar5) {
            return 1;
          }
          RtWheelToCpuReleaseAll(this,unaff_retaddr);
          return 0;
        }
        pCVar5 = pCVar5 + 1;
      } while (pCVar5 < in_stack_00000020);
    }
  }
  return 1;
}
}

// =================================================
// Function: CDx9TextureKeeper::RtWheelToCpuInitOne
// =================================================
int __thiscall
CDx9TextureKeeper::RtWheelToCpuInitOne
          (void *this,CDx9TextureKeeper *param_1,SRtWheelToCpu *param_2,GmNat2 *param_3)
{
{
  int iVar1;
  CPlugFileGpuBuilder *pCVar2;
  int iVar3;
  char *unaff_EBX;
  CPlugFileGpuBuilder *unaff_EBP;
  uint uVar4;
  char *unaff_ESI;
  CPlugFileGpuBuilder *unaff_EDI;
  char *unaff_retaddr;
  CPlugFileGpuBuilder *pCVar5;
  char *pcVar6;
  char *pcVar7;
  LPCSTR *ppCVar8;
  CVisionViewportDx9 *pCVar9;
  
  uVar4 = 0;
  pCVar9 = (CVisionViewportDx9 *)0x0;
  while( true ) {
    iVar1 = (**(code **)(*DAT_00d75698 + 0x70))
                      (DAT_00d75698,*(undefined4 *)param_2,*(undefined4 *)(param_2 + 4),
                       *(undefined4 *)((int)this + 0x14),0,0,0,&stack0xfffffffc,0);
    uVar4 = uVar4 + 1;
    if (iVar1 == -0x7789fe84) {
      if (DAT_00d71e54 != 0) {
        DAT_00d71e54 = 0;
        *DAT_00d71e58 = 0;
      }
      pcVar6 = *(char **)(param_2 + 4);
      ppCVar8 = &lpOutputString_00b2bcc4;
      pcVar7 = " render target";
      pCVar5 = (CPlugFileGpuBuilder *)&DAT_00b2edc8;
      pCVar2 = CFastString::operator<<
                         ((CFastString *)&DAT_00d71e54,
                          (CPlugFileGpuBuilder *)"[Dx9] OutOfVideoMemory ",*(char **)param_2);
      pCVar2 = CFastString::operator<<((CFastString *)pCVar2,pCVar5,pcVar6);
      pCVar2 = CFastString::operator<<
                         ((CFastString *)pCVar2,(CPlugFileGpuBuilder *)pcVar7,(char *)ppCVar8);
      pCVar2 = CFastString::operator<<((CFastString *)pCVar2,unaff_EDI,unaff_ESI);
      unaff_ESI = (char *)0x9635a4;
      pCVar2 = CFastString::operator<<((CFastString *)pCVar2,unaff_EBP,unaff_EBX);
      CFastString::operator<<((CFastString *)pCVar2,(CPlugFileGpuBuilder *)pCVar9,unaff_retaddr);
      CClassicLog::AddLogStringInFile();
      pCVar9 = (CVisionViewportDx9 *)((uint)(*(int *)(param_2 + 4) * *(int *)param_2 * 2) >> 3);
      unaff_retaddr = (char *)0x0;
      unaff_EBX = (char *)0x9635ca;
      iVar3 = CVisionViewportDx9::TextureMemoryMipFree(DAT_00d7569c,pCVar9,0,(CPlugBitmap *)param_1)
      ;
      if (iVar3 == 0) {
        return 0;
      }
    }
    if (4 < uVar4) break;
    if (iVar1 != -0x7789fe84) {
LAB_009635df:
      *(CVisionViewportDx9 **)param_1 = pCVar9;
      if (((byte)DAT_00d777ac & 2) == 0) {
        *(undefined4 *)(param_1 + 4) = 0;
        return 1;
      }
      (**(code **)(*DAT_00d75698 + 0x1d8))(DAT_00d75698,8,param_1 + 4);
      return 1;
    }
  }
  if (iVar1 == -0x7789fe84) {
    return 0;
  }
  goto LAB_009635df;
}
}

// =================================================
// Function: CDx9TextureKeeper::RtWheelToCpuReleaseAll
// =================================================
void __thiscall CDx9TextureKeeper::RtWheelToCpuReleaseAll(void *this,CDx9TextureKeeper *param_1)
{
{
  void *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  GmFrustumIso4 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  void *unaff_retaddr;
  
  this_00 = (void *)((int)this + 0x68);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GxColor>::operator[](this_00,pCVar3,(ulong)unaff_ESI);
      unaff_ESI = *(GmFrustumIso4 **)pSVar2;
      (**(code **)(*(int *)unaff_ESI + 8))();
      (**(code **)(**(int **)(pSVar2 + 4) + 8))(*(int **)(pSVar2 + 4));
      pCVar3 = pCVar3 + 1;
      this = unaff_retaddr;
    } while (pCVar3 < pCVar1);
  }
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_00,unaff_ESI);
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x78) = 0xffffffff;
  *(undefined4 *)((int)this + 0x80) = 0;
  *(undefined4 *)((int)this + 0x84) = 0;
  return;
}
}

// =================================================
// Function: CDx9TextureKeeper::RtWheelToCpusIssueQuery
// =================================================
void __thiscall CDx9TextureKeeper::RtWheelToCpusIssueQuery(void *this,CDx9TextureKeeper *param_1)
{
{
  void *this_00;
  SCasterCat *pSVar1;
  ulong uVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_EDI;
  ulong uVar3;
  
  this_00 = (void *)((int)this + 0x68);
  pSVar1 = CFastBuffer<class_GxColor>::operator[]
                     (this_00,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)this + 0x74)
                      ,unaff_EDI);
  if (*(int *)(pSVar1 + 4) != 0) {
    (**(code **)(**(int **)(pSVar1 + 4) + 0x18))(*(int **)(pSVar1 + 4),1);
    CMwProfiler::GetTimeStamp((int64 *)(pSVar1 + 8));
  }
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
  if (uVar2 <= *(uint *)((int)this + 0x78)) {
    *(undefined4 *)((int)this + 0x78) = *(undefined4 *)((int)this + 0x74);
  }
  uVar3 = *(int *)((int)this + 0x74) + 1;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBX);
  if (uVar3 == uVar2) {
    *(undefined4 *)((int)this + 0x74) = 0;
    return;
  }
  *(ulong *)((int)this + 0x74) = uVar3;
  return;
}
}

// =================================================
// Function: CDx9TextureKeeper::UpLoadTexture
// =================================================
int __thiscall
CDx9TextureKeeper::UpLoadTexture(void *this,CDx9TextureKeeper *param_1,CPlugBitmap *param_2)
{
{
  CPlugFileImg *pCVar1;
  int iVar2;
  CPlugFileGpuBuilder *pCVar3;
  undefined4 uVar4;
  SNationConfig *unaff_EBX;
  int *piVar5;
  CDx9TextureKeeper *pCVar6;
  char *unaff_EBP;
  CPlugFileImg *unaff_ESI;
  ulong uVar7;
  CPlugFileVideo *unaff_EDI;
  uint uVar8;
  undefined4 uStack0000000c;
  CVisionViewportDx9 *in_stack_00000010;
  char *pcVar9;
  char *pcVar10;
  LPCSTR *ppCVar11;
  CPlugFileGpuBuilder *in_stack_ffffffbc;
  char *pcVar12;
  CPlugFileGpuBuilder *pCVar13;
  CVisionTexConverter *pCVar14;
  IDirect3DBaseTexture9 *pIVar15;
  char *pcVar16;
  CMwCmdBufferCore *pCVar17;
  GxRGBAColor *in_stack_ffffffd8;
  ulong in_stack_ffffffdc;
  CVisionTexConverter *pCStack_20;
  int local_1c;
  uint local_18;
  undefined *local_14 [2];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aea0b0;
  local_c = ExceptionList;
  pCVar1 = (CPlugFileImg *)(DAT_00cca150 ^ (uint)&stack0xffffffc8);
  ExceptionList = &local_c;
  pcVar12 = (char *)0x968545;
  iVar2 = CPlugFileImg::IsInSystemMemory(*(CPlugFileImg **)(param_1 + 0x48),pCVar1);
  if (iVar2 == 0) {
    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x40000;
    pCVar1 = (CPlugFileImg *)0x96855b;
    CPlugBitmap::ReGenerate((CPlugBitmap *)param_1,unaff_EDI);
    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) & 0xfffbffff;
    unaff_EDI = (CPlugFileVideo *)0x96856a;
    iVar2 = CPlugFileImg::IsInSystemMemory(*(CPlugFileImg **)(param_1 + 0x48),unaff_ESI);
    if (iVar2 == 0) {
      if (*(CSystemFidFile **)(param_1 + 8) != (CSystemFidFile *)0x0) {
        local_18 = 0;
        local_14[0] = PTR_DAT_00bbf7dc;
        pCVar13 = (CPlugFileGpuBuilder *)0x0;
        param_2 = (CPlugBitmap *)0x0;
        CSystemFidFile::GetFullName
                  (*(CSystemFidFile **)(param_1 + 8),(CPlugFile *)&local_18,(CFastStringInt *)0x0);
        if (DAT_00d71e54 != 0) {
          DAT_00d71e54 = 0;
          *DAT_00d71e58 = 0;
        }
        pCVar3 = CFastString::operator<<
                           ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)&local_1c,
                            (char *)&lpOutputString_00b2bcc4);
        CFastString::operator<<((CFastString *)pCVar3,pCVar13,unaff_EBP);
        CClassicLog::AddLogStringInFile();
        CGameCtnApp::SNationConfig::~SNationConfig(local_14,unaff_EBX);
      }
      ExceptionList = param_2;
      return 0;
    }
  }
  piVar5 = *(int **)((int)this + 8);
  pCVar14 = (CVisionTexConverter *)0x9685e6;
  func_0x009b5030();
  local_c = (void *)0x1;
  pcVar16 = (char *)0x0;
  if (piVar5 == (int *)0x0) {
    piVar5 = *(int **)((int)this + 0xc);
    iVar2 = (**(code **)(*DAT_00d75698 + 0x5c))
                      (DAT_00d75698,*(undefined4 *)((int)this + 0x24),
                       *(undefined4 *)((int)this + 0x28),*(uint *)((int)this + 0x20) >> 9 & 0x1f,0,
                       *(undefined4 *)((int)this + 0x14),2,&stack0xffffffd0,0);
    if ((iVar2 == -0x7789fe84) || (iVar2 == -0x7ff8fff2)) {
      if (DAT_00d71e54 != 0) {
        DAT_00d71e54 = 0;
        *DAT_00d71e58 = 0;
      }
      pcVar9 = *(char **)((int)this + 0x28);
      ppCVar11 = &lpOutputString_00b2bcc4;
      pcVar10 = " system";
      pCVar3 = (CPlugFileGpuBuilder *)&DAT_00b2edc8;
      pCVar13 = CFastString::operator<<
                          ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)"[Dx9] OutOfMemory ",
                           *(char **)((int)this + 0x24));
      pCVar13 = CFastString::operator<<((CFastString *)pCVar13,pCVar3,pcVar9);
      pCVar13 = CFastString::operator<<
                          ((CFastString *)pCVar13,(CPlugFileGpuBuilder *)pcVar10,(char *)ppCVar11);
      pCVar13 = CFastString::operator<<((CFastString *)pCVar13,in_stack_ffffffbc,pcVar12);
      pCVar13 = CFastString::operator<<
                          ((CFastString *)pCVar13,(CPlugFileGpuBuilder *)pCVar1,(char *)unaff_EDI);
      CFastString::operator<<((CFastString *)pCVar13,(CPlugFileGpuBuilder *)pCVar14,pcVar16);
      CClassicLog::AddLogStringInFile();
      goto LAB_0096869d;
    }
  }
  func_0x009b55c0(param_1);
  if ((((*(uint *)(param_1 + 0x4c) & 0x100000) != 0) &&
      (pCVar1 = CVisionTexConverter::GetImage((CVisionTexConverter *)local_14,pCVar14),
      (*(uint *)(pCVar1 + 0x24) & 0xf8000) == 0x8000)) &&
     (iVar2 = CPlugBitmap::ComputeMipMapLevels((CPlugBitmap *)param_1,(CPlugBitmap *)unaff_EBX),
     iVar2 == 0)) {
LAB_0096869d:
    uStack0000000c = 0xffffffff;
    CVisionTexConverter::~CVisionTexConverter
              ((CVisionTexConverter *)&local_c,(CVisionTexConverter *)unaff_EBX);
    ExceptionList = param_2;
    return 0;
  }
  pCVar17 = (CMwCmdBufferCore *)0x1;
  pIVar15 = (IDirect3DBaseTexture9 *)0x9686f8;
  CMwCmdBufferCore::HighFrequencyEnterSafeSection
            (DAT_00d731e0,(CMwCmdBufferCore *)0x1,(ulong)unaff_EBX);
  if ((*(uint *)(*(int *)(param_1 + 0x48) + 0x24) >> 5 & 0xf) - 1 < 5)
  goto switchD_0096872b_caseD_3;
  switch(*(uint *)(param_1 + 0x4c) & 0xff) {
  case 2:
    pCVar17 = (CMwCmdBufferCore *)0x0;
    pIVar15 = (IDirect3DBaseTexture9 *)0x968746;
    func_0x009b52b0();
    break;
  case 4:
  case 0x10:
    pCVar17 = (CMwCmdBufferCore *)0x1;
    pIVar15 = (IDirect3DBaseTexture9 *)0x968757;
    func_0x009b52b0();
    break;
  case 5:
  case 6:
  case 9:
    iVar2 = *(int *)((int)this + 0x14);
    if (iVar2 < 0x41) {
      if (iVar2 == 0x40) {
LAB_009687cc:
        pCVar17 = (CMwCmdBufferCore *)&DAT_00000004;
      }
      else {
        switch(iVar2) {
        case 0x15:
        case 0x16:
          pCVar17 = (CMwCmdBufferCore *)0x0;
          break;
        default:
          goto switchD_0096872b_caseD_3;
        case 0x1f:
          pCVar17 = (CMwCmdBufferCore *)&DAT_00000005;
          break;
        case 0x22:
          goto switchD_0096879a_caseD_22;
        case 0x3c:
switchD_0096879a_caseD_3c:
          pCVar17 = (CMwCmdBufferCore *)0x2;
          break;
        case 0x3f:
          pCVar17 = (CMwCmdBufferCore *)0x1;
        }
      }
    }
    else if (iVar2 < 0x5348564f) {
      if (iVar2 == 0x5348564e) goto LAB_009687cc;
      if (iVar2 != 0x43) {
        if (iVar2 != 0x75) break;
        goto switchD_0096879a_caseD_3c;
      }
      pCVar17 = (CMwCmdBufferCore *)&DAT_00000006;
    }
    else {
      if (iVar2 != 0x5548564e) break;
switchD_0096879a_caseD_22:
      pCVar17 = (CMwCmdBufferCore *)0x3;
    }
    goto LAB_009687db;
  case 8:
    CVisionTexConverter::HeightToDispH01
              ((CVisionTexConverter *)&puStack_8,(CVisionTexConverter *)in_stack_ffffffd8);
    break;
  case 0x13:
    pCVar17 = (CMwCmdBufferCore *)&DAT_00000007;
    goto LAB_009687db;
  case 0x18:
    pCVar17 = (CMwCmdBufferCore *)&DAT_00000009;
    goto LAB_009687db;
  case 0x1a:
    pCVar17 = (CMwCmdBufferCore *)&DAT_00000008;
LAB_009687db:
    pIVar15 = (IDirect3DBaseTexture9 *)0x9687e4;
    CVisionTexConverter::HeightToBumpNormal
              ((CVisionTexConverter *)&puStack_8,(CVisionTexConverter *)pCVar17,0,in_stack_ffffffd8)
    ;
    break;
  case 0x1c:
    CVisionTexConverter::RxGyBz_To_R0GyBzAx
              ((CVisionTexConverter *)&puStack_8,(CVisionTexConverter *)in_stack_ffffffd8);
  }
switchD_0096872b_caseD_3:
  if (((*(uint *)(param_1 + 0x4c) & 0x80000) != 0) && (*(int *)this != 5)) {
    CVisionTexConverter::InvertYCubeMapFace
              ((CVisionTexConverter *)&uStack_4,
               (CVisionTexConverter *)((*(uint *)(param_1 + 0x50) >> 0xe & 7) - 1),in_stack_ffffffdc
              );
  }
  uVar8 = -(uint)(*(int *)this != 5) & 0xfffffffb;
  pCVar14 = (CVisionTexConverter *)0x968821;
  local_18 = (**(code **)(*piVar5 + 0x34))();
  pCVar6 = (CDx9TextureKeeper *)0x0;
  if (uVar8 != 0xfffffffa) {
    do {
      uVar7 = 0;
      if (local_18 != 0) {
        do {
          UpLoadTextureLevel(this,pCVar6,uVar7,(ulong)local_14,pCStack_20,pIVar15);
          uVar7 = uVar7 + 1;
        } while (uVar7 < local_18);
      }
      pCVar6 = pCVar6 + 1;
      param_1 = (CDx9TextureKeeper *)in_stack_00000010;
    } while (pCVar6 < (CDx9TextureKeeper *)(uVar8 + 6));
  }
  if (*(int *)((int)this + 0x10) == 1) {
    if (*(CVisionViewportDx9 *)(param_1 + 0x4d) == (CVisionViewportDx9)0x3) {
      iVar2 = *(int *)(param_1 + 0x74);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x10) != 0)) {
        *(undefined4 *)(iVar2 + 0xc) = 1;
        CVisionViewportDx9::TexRender_UpdateTexture
                  (DAT_00d7569c,(CVisionViewportDx9 *)param_1,(CPlugBitmap *)pCVar17);
      }
    }
    else {
      (**(code **)(*DAT_00d75698 + 0x7c))(DAT_00d75698);
    }
  }
  if ((*(int *)((int)this + 0x10) == 0) && (*(int **)((int)this + 0xc) != (int *)0x0)) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x24))();
    uVar4 = (**(code **)(*DAT_00d75698 + 0x10))();
    *(undefined4 *)(DAT_00d7569c + 0x200) = uVar4;
    *(undefined4 *)(DAT_00d7569c + 0x204) = 0;
  }
  if (local_1c != 0) {
    (**(code **)(*DAT_00d75698 + 0x7c))(DAT_00d75698);
    (**(code **)(*piVar5 + 8))(piVar5);
  }
  CMwCmdBufferCore::HighFrequencyLeaveSafeSection(DAT_00d731e0,pCVar17);
  uStack0000000c = 0xffffffff;
  CVisionTexConverter::~CVisionTexConverter((CVisionTexConverter *)&local_c,pCVar14);
  ExceptionList = param_2;
  return 1;
}
}

// =================================================
// Function: CDx9TextureKeeper::UpLoadTextureLevel
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CDx9TextureKeeper::UpLoadTextureLevel
          (void *this,CDx9TextureKeeper *param_1,ulong param_2,ulong param_3,
          CVisionTexConverter *param_4,IDirect3DBaseTexture9 *param_5)
{
{
  CPlugFileImg CVar1;
  CVisionTexConverter *pCVar2;
  CPlugFileImg *pCVar3;
  CPlugFileImg *pCVar4;
  CPlugFileImg **ppCVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ushort *extraout_EAX;
  ushort *extraout_EAX_00;
  CPlugFileImg *pCVar10;
  int iVar11;
  undefined1 *puVar12;
  CReal16 **ppCVar13;
  undefined1 *puVar14;
  ulong uVar15;
  CReal16 *unaff_EBP;
  int unaff_ESI;
  CPlugFileImg *pCVar16;
  CVisionTexConverter *unaff_EDI;
  ulong uVar17;
  CPlugFileImg *pCVar18;
  CVisionTexConverter *pCVar19;
  bool bVar20;
  CPlugFileImg *unaff_retaddr;
  undefined4 uVar21;
  undefined4 uVar22;
  CPlugFileImg **ppCVar23;
  int iVar24;
  undefined4 uVar25;
  float fVar26;
  CPlugFileImg **ppCVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  CVisionTexConverter *pCStack_a0;
  CPlugFileImg *local_9c;
  CReal16 *pCStack_98;
  int iStack_94;
  CReal16 *pCStack_90;
  CPlugFileImg **ppCStack_8c;
  CPlugFileImg *local_88;
  CReal16 *local_84;
  CPlugFileImg *local_80;
  CPlugFileImg *pCStack_7c;
  CPlugFileImg *local_78;
  CPlugFileImg *local_74;
  CReal16 *pCStack_70;
  undefined4 uStack_6c;
  CVisionTexConverter *pCStack_68;
  CPlugFileImg *pCStack_64;
  CReal16 *pCStack_60;
  int *piStack_5c;
  CVisionTexConverter *pCStack_58;
  CPlugFileImg *pCStack_54;
  undefined1 auStack_4c [4];
  void *local_48;
  CPlugFileImg *pCStack_44;
  undefined1 local_38 [4];
  CVisionTexConverter *pCStack_34;
  CVisionTexConverter *pCStack_30;
  CReal16 *pCStack_2c;
  CPlugFileImg *pCStack_28;
  undefined1 local_1c [4];
  CVisionTexConverter *pCStack_18;
  CVisionTexConverter *pCStack_10;
  CVisionTexConverter *pCStack_c;
  int iStack_8;
  
  uVar17 = (*(uint *)((int)this + 0x1c) >> 0x1c) + param_2;
  local_48 = this;
  pCVar3 = CVisionTexConverter::GetImage((CVisionTexConverter *)param_3,unaff_EDI);
  local_84 = (CReal16 *)(*(uint *)(pCVar3 + 0x24) >> 2 & 7);
  pCVar16 = (CPlugFileImg *)(*(uint *)(pCVar3 + 0x24) >> 5 & 0xf);
  local_9c = (CPlugFileImg *)(uint)(pCVar16 + -1 < (CPlugFileImg *)&DAT_00000005);
  if (param_5 == (IDirect3DBaseTexture9 *)0x0) {
    local_74 = *(CPlugFileImg **)((int)this + 8);
  }
  else {
    local_74 = (CPlugFileImg *)param_5;
  }
  local_78 = *(CPlugFileImg **)((int)this + 8);
  iVar24 = *(int *)this;
  pCVar4 = local_74;
  if (iVar24 == 3) {
LAB_00964920:
    puVar12 = local_1c;
  }
  else {
    if (iVar24 != 4) {
      if (iVar24 == 5) {
        pCVar4 = local_78;
      }
      goto LAB_00964920;
    }
    puVar12 = local_38;
    pCVar4 = local_78;
  }
  local_88 = pCVar16;
  local_80 = pCVar3;
  (**(code **)((int)*(float *)pCVar4 + 0x44))();
  if (*(int *)this == 4) {
    local_9c = pCStack_44;
    pCStack_a0 = pCStack_30;
    pCStack_98 = pCStack_2c;
    pCVar19 = pCStack_34;
  }
  else {
    local_9c = pCStack_28;
    pCStack_a0 = pCStack_c;
    pCStack_98 = (CReal16 *)0x1;
    pCVar19 = pCStack_10;
  }
  if (pCVar16 == (CPlugFileImg *)&DAT_00000009) {
    local_84 = (CReal16 *)0x0;
    ppCVar5 = (CPlugFileImg **)
              CPlugFileImg::GetFaceLevel
                        (pCVar3,(CPlugFileImg *)0x0,0,(ulong)&local_84,(ulong *)0x0,(GmNat3 *)pCVar4
                        );
    pCStack_98 = (CReal16 *)0x0;
    (**(code **)((int)*(float *)pCStack_7c + 0x48))(pCStack_7c,param_1,&pCStack_98);
    uVar28 = 0;
    ppCVar27 = (CPlugFileImg **)0x0;
    uVar25 = 1;
    iVar24 = 0;
    uVar22 = 0;
    uVar21 = 0;
    ppCVar23 = ppCStack_8c;
    _D3DXLoadSurfaceFromFileInMemory_36();
    pCStack_a0 = pCVar19;
    ppCStack_8c = ppCVar5;
    ppCVar5 = ppCVar27;
    goto LAB_009663a2;
  }
  local_84 = (CReal16 *)
             CVisionTexConverter::GetPixels
                       ((CVisionTexConverter *)param_1,(CVisionTexConverter *)0x0,uVar17,
                        (ulong)auStack_4c,(ulong *)&piStack_5c,(GmNat3 *)pCVar4);
  if ((pCVar19 == (CVisionTexConverter *)0x0) ||
     (pCVar16[DAT_00d756a0 + 0x75f] != (CPlugFileImg)0x0)) {
    bVar20 = false;
  }
  else {
    bVar20 = true;
  }
  if ((pCStack_58 == pCStack_a0) && (pCStack_54 == local_9c)) {
    if (!bVar20) {
      iVar24 = *(int *)this;
      if (iVar24 == 3) {
LAB_00964a92:
        ppCVar13 = &pCStack_60;
LAB_00964a9a:
        iVar24 = 0;
        pCVar3 = (CPlugFileImg *)0x964aaf;
        (**(code **)((int)*(float *)pCStack_7c + 0x4c))(pCStack_7c,param_1,ppCVar13,0);
        unaff_retaddr = pCStack_7c;
      }
      else {
        if (iVar24 == 4) {
          ppCVar13 = &pCStack_70;
          pCStack_7c = local_80;
          goto LAB_00964a9a;
        }
        if (iVar24 != 5) goto LAB_00964a92;
        iVar24 = 0;
        pCVar3 = local_80;
        (**(code **)((int)*(float *)local_80 + 0x4c))(local_80,unaff_retaddr,param_1,&pCStack_60,0);
      }
      pCVar4 = (CPlugFileImg *)local_84;
      pCVar18 = local_88;
      pCVar16 = local_80;
      if (*(int *)this != 4) {
        uVar15 = param_3;
        if (pCVar19 != (CVisionTexConverter *)0x0) {
          uVar15 = param_3 + 3 >> 2;
        }
        pCVar4 = (CPlugFileImg *)(uVar15 * (int)local_78);
        pCVar18 = local_78;
        pCVar16 = local_74;
      }
      pCVar3 = (CPlugFileImg *)
               CVisionTexConverter::GetPixels
                         (pCStack_10,pCStack_18,uVar17,(ulong)&piStack_5c,(ulong *)0x0,
                          (GmNat3 *)pCVar3);
      if (iVar24 != 0) {
        uVar6 = (uint)(puVar12 + 3) >> 2;
        pCVar10 = (CPlugFileImg *)
                  (((uint)((*(uint *)(local_9c + 0x24) & 0x1e0) != 0x20) * 8 + 8) *
                  (param_3 + 3 >> 2));
        if ((pCVar18 == pCVar10) && (pCVar4 == (CPlugFileImg *)(uVar6 * (int)pCVar18))) {
          _memcpy(pCVar16,pCVar3,(int)pCVar10 * uVar6 * (int)unaff_EBP);
        }
        else if (unaff_EBP != (CReal16 *)0x0) {
          iVar24 = uVar6 * (int)puVar12;
          puVar14 = puVar12;
          do {
            for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
              _memcpy(pCVar16,pCVar3,(uint)pCVar10);
              pCVar3 = pCVar3 + (int)pCVar10;
              pCVar16 = pCVar16 + (int)pCVar18;
            }
            pCVar16 = pCVar16 + ((int)pCVar4 - iVar24);
            unaff_EBP = unaff_EBP + -1;
            puVar14 = puVar12;
          } while (unaff_EBP != (CReal16 *)0x0);
        }
        goto switchD_00964c25_caseD_1b;
      }
      if (unaff_ESI == 0x15) {
        bVar20 = pCStack_a0 == (CVisionTexConverter *)&DAT_00000004;
LAB_00964bd3:
        pCVar2 = pCVar19;
        if (bVar20) {
LAB_00964bda:
          if (pCVar2 == (CVisionTexConverter *)0x0) {
LAB_00964c87:
            uVar17 = CPlugFileImg::GetByteSizePerComp(local_9c,unaff_retaddr);
            pCVar10 = (CPlugFileImg *)(uVar17 * (int)local_9c * (int)puVar12);
            if ((pCVar18 == pCVar10) && (pCVar4 == (CPlugFileImg *)((int)pCVar18 * unaff_ESI))) {
              _memcpy(pCVar16,pCVar3,
                      uVar17 * (int)local_9c * (int)pCVar19 * unaff_ESI * (int)puVar12);
            }
            else if (pCVar19 != (CVisionTexConverter *)0x0) {
              iVar7 = (int)pCVar18 * unaff_ESI;
              iVar24 = unaff_ESI;
              pCStack_a0 = pCVar19;
              do {
                for (; iVar24 != 0; iVar24 = iVar24 + -1) {
                  _memcpy(pCVar16,pCVar3,(uint)pCVar10);
                  pCVar3 = pCVar3 + (int)pCVar10;
                  pCVar16 = pCVar16 + (int)pCVar18;
                }
                pCVar16 = pCVar16 + ((int)pCVar4 - iVar7);
                pCStack_a0 = pCStack_a0 + -1;
                iVar24 = unaff_ESI;
              } while (pCStack_a0 != (CVisionTexConverter *)0x0);
            }
            goto switchD_00964c25_caseD_1b;
          }
        }
      }
      else {
        if (unaff_ESI == 0x14) {
          bVar20 = pCStack_a0 == (CVisionTexConverter *)0x3;
          goto LAB_00964bd3;
        }
        if (unaff_ESI == 0x33) {
          bVar20 = pCStack_a0 == (CVisionTexConverter *)0x2;
          goto LAB_00964bd3;
        }
        if ((unaff_ESI != 0x5548564e) && (unaff_ESI != 0x22)) {
          if (unaff_ESI == 0x51) {
            bVar20 = pCStack_a0 == (CVisionTexConverter *)0x1;
            goto LAB_00964c4e;
          }
          if (((unaff_ESI != 0x71) || (pCStack_a0 != (CVisionTexConverter *)&DAT_00000004)) ||
             (pCVar19 != (CVisionTexConverter *)&DAT_00000007)) goto LAB_00964be0;
          goto LAB_00964c87;
        }
        bVar20 = pCStack_a0 == (CVisionTexConverter *)0x2;
LAB_00964c4e:
        if (bVar20) {
          pCVar2 = pCVar19 + -6;
          goto LAB_00964bda;
        }
      }
LAB_00964be0:
      fVar26 = 1.3802556e-38;
      uVar17 = CPlugFileImg::GetByteSizePerComp(local_9c,unaff_retaddr);
      iVar24 = uVar17 * (int)local_9c;
      if ((int)unaff_EBP < 0x5348564f) {
        if (unaff_EBP == (CReal16 *)0x5348564e) {
          iStack_94 = (int)pCVar4 - (int)pCVar18 * unaff_ESI;
          for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0; pCVar19 = pCVar19 + -1) {
            for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
              for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                *(ushort *)pCVar16 = *(ushort *)(pCVar3 + 2) + 0x8001;
                *(ushort *)(pCVar16 + 2) = *(ushort *)pCVar3 + 0x8001;
                pCVar16 = pCVar16 + 4;
                pCVar3 = pCVar3 + iVar24;
              }
              pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -4);
            }
            pCVar16 = pCVar16 + iStack_94;
          }
        }
        else {
          switch(unaff_EBP) {
          case (CReal16 *)0x15:
            if (uVar17 == 1) {
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    *pCVar16 = (CPlugFileImg)0xff;
                    pCVar16[1] = (CPlugFileImg)0xff;
                    pCVar16[2] = (CPlugFileImg)0xff;
                    pCVar16[3] = *pCVar3;
                    pCVar16 = pCVar16 + 4;
                    pCVar3 = pCVar3 + iVar24;
                  }
                  pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -4);
                }
                pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
              }
            }
            else {
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    uVar6 = *(ushort *)(pCVar3 + 4) + 0x7f;
                    if (0xffff < uVar6) {
                      uVar6 = 0xffff;
                    }
                    *pCVar16 = SUB41(uVar6 >> 8,0);
                    uVar6 = *(ushort *)(pCVar3 + 2) + 0x7f;
                    if (0xffff < uVar6) {
                      uVar6 = 0xffff;
                    }
                    pCVar16[1] = SUB41(uVar6 >> 8,0);
                    uVar6 = *(ushort *)pCVar3 + 0x7f;
                    if (0xffff < uVar6) {
                      uVar6 = 0xffff;
                    }
                    pCVar16[2] = SUB41(uVar6 >> 8,0);
                    uVar6 = *(ushort *)(pCVar3 + 6) + 0x7f;
                    if (0xffff < uVar6) {
                      uVar6 = 0xffff;
                    }
                    pCVar16[3] = SUB41(uVar6 >> 8,0);
                    pCVar16 = pCVar16 + 4;
                    pCVar3 = pCVar3 + iVar24;
                  }
                  pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -4);
                }
                pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
              }
            }
            break;
          case (CReal16 *)0x16:
            if (local_9c == (CPlugFileImg *)0x3) {
              if (uVar17 == 1) {
                for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                    pCVar19 = pCVar19 + -1) {
                  for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                    for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                      *pCVar16 = *pCVar3;
                      pCVar16[1] = pCVar3[1];
                      pCVar16[2] = pCVar3[2];
                      pCVar16 = pCVar16 + 4;
                      pCVar3 = pCVar3 + iVar24;
                    }
                    pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -4);
                  }
                  pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
                }
              }
              else {
                for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                    pCVar19 = pCVar19 + -1) {
                  for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                    for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                      uVar6 = *(ushort *)(pCVar3 + 4) + 0x7f;
                      if (0xffff < uVar6) {
                        uVar6 = 0xffff;
                      }
                      *pCVar16 = SUB41(uVar6 >> 8,0);
                      uVar6 = *(ushort *)(pCVar3 + 2) + 0x7f;
                      if (0xffff < uVar6) {
                        uVar6 = 0xffff;
                      }
                      pCVar16[1] = SUB41(uVar6 >> 8,0);
                      uVar6 = *(ushort *)pCVar3 + 0x7f;
                      if (0xffff < uVar6) {
                        uVar6 = 0xffff;
                      }
                      pCVar16[2] = SUB41(uVar6 >> 8,0);
                      pCVar16 = pCVar16 + 4;
                      pCVar3 = pCVar3 + iVar24;
                    }
                    pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -4);
                  }
                  pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
                }
              }
            }
            else {
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    *pCVar16 = *pCVar3;
                    pCVar16[1] = *pCVar3;
                    pCVar16[2] = *pCVar3;
                    pCVar16 = pCVar16 + 4;
                    pCVar3 = pCVar3 + iVar24;
                  }
                  pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -4);
                }
                pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
              }
            }
            break;
          case (CReal16 *)0x17:
            if (local_9c == (CPlugFileImg *)0x3) {
              local_9c = pCVar4 + -((int)pCVar18 * unaff_ESI);
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    *(ushort *)pCVar16 =
                         (((byte)pCVar3[2] & 0xfff8) << 5 | (byte)pCVar3[1] & 0xfffc) * 8 |
                         (ushort)((byte)*pCVar3 >> 3);
                    pCVar16 = pCVar16 + 2;
                    pCVar3 = pCVar3 + iVar24;
                  }
                  pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -2);
                }
                pCVar16 = pCVar16 + (int)local_9c;
              }
            }
            else {
              pCStack_98 = (CReal16 *)(pCVar4 + -((int)pCVar18 * unaff_ESI));
              local_9c = pCVar18 + (int)puVar12 * -2;
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    CVar1 = *pCVar3;
                    pCVar3 = pCVar3 + iVar24;
                    *(ushort *)pCVar16 =
                         (((byte)CVar1 & 0xfff8) << 5 | (byte)CVar1 & 0xfffc) * 8 |
                         (ushort)((byte)CVar1 >> 3);
                    pCVar16 = pCVar16 + 2;
                  }
                  pCVar16 = pCVar16 + (int)local_9c;
                }
                pCVar16 = pCVar16 + (int)pCStack_98;
              }
            }
            break;
          case (CReal16 *)0x18:
            if (local_9c == (CPlugFileImg *)0x3) {
              local_9c = pCVar4 + -((int)pCVar18 * unaff_ESI);
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    *(ushort *)pCVar16 =
                         (((byte)pCVar3[2] & 0xfff8) << 5 | (byte)pCVar3[1] & 0xfff8) * 4 |
                         (ushort)((byte)*pCVar3 >> 3);
                    pCVar16 = pCVar16 + 2;
                    pCVar3 = pCVar3 + iVar24;
                  }
                  pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -2);
                }
                pCVar16 = pCVar16 + (int)local_9c;
              }
            }
            else {
              pCStack_98 = (CReal16 *)(pCVar4 + -((int)pCVar18 * unaff_ESI));
              local_9c = pCVar18 + (int)puVar12 * -2;
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    CVar1 = *pCVar3;
                    pCVar3 = pCVar3 + iVar24;
                    *(ushort *)pCVar16 =
                         (((byte)CVar1 & 0xfff8) << 5 | (byte)CVar1 & 0xfff8) * 4 |
                         (ushort)((byte)CVar1 >> 3);
                    pCVar16 = pCVar16 + 2;
                  }
                  pCVar16 = pCVar16 + (int)local_9c;
                }
                pCVar16 = pCVar16 + (int)pCStack_98;
              }
            }
            break;
          case (CReal16 *)0x19:
            local_9c = pCVar4 + -((int)pCVar18 * unaff_ESI);
            for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0; pCVar19 = pCVar19 + -1)
            {
              for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                  *(ushort *)pCVar16 =
                       (((byte)pCVar3[2] & 0xfff8) << 5 | (byte)pCVar3[1] & 0xfff8 |
                       ((byte)pCVar3[3] & 0xff80) << 6) * 4 | (ushort)((byte)*pCVar3 >> 3);
                  pCVar16 = pCVar16 + 2;
                  pCVar3 = pCVar3 + iVar24;
                }
                pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -2);
              }
              pCVar16 = pCVar16 + (int)local_9c;
            }
            break;
          case (CReal16 *)0x1a:
            pCStack_98 = (CReal16 *)(pCVar4 + -((int)pCVar18 * unaff_ESI));
            local_9c = pCVar18 + (int)puVar12 * -2;
            for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0; pCVar19 = pCVar19 + -1)
            {
              for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                  *(ushort *)pCVar16 =
                       ((byte)pCVar3[2] & 0xfff0) << 4 | (byte)pCVar3[1] & 0xfff0 |
                       ((byte)pCVar3[3] & 0xf0) << 8 | (ushort)((byte)*pCVar3 >> 4);
                  pCVar16 = pCVar16 + 2;
                  pCVar3 = pCVar3 + iVar24;
                }
                pCVar16 = pCVar16 + (int)local_9c;
              }
              pCVar16 = pCVar16 + (int)pCStack_98;
            }
            break;
          case (CReal16 *)0x1c:
          case (CReal16 *)0x32:
            if (uVar17 == 1) {
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    *pCVar16 = *pCVar3;
                    pCVar16 = pCVar16 + 1;
                    pCVar3 = pCVar3 + iVar24;
                  }
                  pCVar16 = pCVar16 + ((int)pCVar18 - (int)puVar12);
                }
                pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
              }
            }
            else {
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    uVar6 = *(ushort *)pCVar3 + 0x7f;
                    if (0xffff < uVar6) {
                      uVar6 = 0xffff;
                    }
                    *pCVar16 = SUB41(uVar6 >> 8,0);
                    pCVar16 = pCVar16 + 1;
                    pCVar3 = pCVar3 + iVar24;
                  }
                  pCVar16 = pCVar16 + ((int)pCVar18 - (int)puVar12);
                }
                pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
              }
            }
            break;
          case (CReal16 *)0x1f:
            pCStack_98 = (CReal16 *)(pCVar4 + -((int)pCVar18 * unaff_ESI));
            local_9c = pCVar18 + (int)puVar12 * -4;
            for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0; pCVar19 = pCVar19 + -1)
            {
              for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                  uVar6 = *(ushort *)pCVar3 + 0x1f;
                  if (0xffff < uVar6) {
                    uVar6 = 0xffff;
                  }
                  uVar8 = *(ushort *)(pCVar3 + 2) + 0x1f;
                  if (0xffff < uVar8) {
                    uVar8 = 0xffff;
                  }
                  uVar9 = *(ushort *)(pCVar3 + 4) + 0x1f;
                  if (0xffff < uVar9) {
                    uVar9 = 0xffff;
                  }
                  *(uint *)pCVar16 =
                       ((uVar9 & 0xffffffc0) << 10 | uVar8 & 0xffffffc0) << 4 | uVar6 >> 6;
                  pCVar16 = pCVar16 + 4;
                  pCVar3 = pCVar3 + iVar24;
                }
                pCVar16 = pCVar16 + (int)local_9c;
              }
              pCVar16 = pCVar16 + (int)pCStack_98;
            }
            break;
          case (CReal16 *)0x22:
            for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0; pCVar19 = pCVar19 + -1)
            {
              for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                  *(ushort *)pCVar16 = *(ushort *)pCVar3;
                  *(ushort *)(pCVar16 + 2) = *(ushort *)(pCVar3 + 2);
                  pCVar16 = pCVar16 + 4;
                  pCVar3 = pCVar3 + iVar24;
                }
                pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -4);
              }
              pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
            }
            break;
          case (CReal16 *)0x28:
            for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0; pCVar19 = pCVar19 + -1)
            {
              for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                  *pCVar16 = (CPlugFileImg)0x0;
                  pCVar16[1] = *pCVar3;
                  pCVar16 = pCVar16 + 2;
                  pCVar3 = pCVar3 + iVar24;
                }
                pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -2);
              }
              pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
            }
            break;
          case (CReal16 *)0x29:
            for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0; pCVar19 = pCVar19 + -1)
            {
              for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                  *pCVar16 = *pCVar3;
                  pCVar16 = pCVar16 + 1;
                  pCVar3 = pCVar3 + iVar24;
                }
                pCVar16 = pCVar16 + ((int)pCVar18 - (int)puVar12);
              }
              pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
            }
            break;
          case (CReal16 *)0x33:
            if (*(char *)(*(int *)(iStack_8 + 4) + 0x4c) == '\x01') {
              local_9c = pCVar4 + -((int)pCVar18 * unaff_ESI);
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    *pCVar16 = *pCVar3;
                    pCVar16[1] = (CPlugFileImg)0xff;
                    pCVar16 = pCVar16 + 2;
                    pCVar3 = pCVar3 + iVar24;
                  }
                  pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -2);
                }
                pCVar16 = pCVar16 + (int)local_9c;
              }
            }
            else {
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    *pCVar16 = (CPlugFileImg)0x0;
                    pCVar16[1] = *pCVar3;
                    pCVar16 = pCVar16 + 2;
                    pCVar3 = pCVar3 + iVar24;
                  }
                  pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -2);
                }
                pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
              }
            }
            break;
          case (CReal16 *)0x3c:
            for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0; pCVar19 = pCVar19 + -1)
            {
              for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                  iVar11 = (byte)*pCVar3 - 0x7f;
                  if (0x7f < iVar11) {
                    iVar11 = 0x7f;
                  }
                  *pCVar16 = SUB41(iVar11,0);
                  iVar11 = (byte)pCVar3[1] - 0x7f;
                  if (0x7f < iVar11) {
                    iVar11 = 0x7f;
                  }
                  pCVar16[1] = SUB41(iVar11,0);
                  pCVar16 = pCVar16 + 2;
                  pCVar3 = pCVar3 + iVar24;
                }
                pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -2);
              }
              pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
            }
            break;
          case (CReal16 *)0x3f:
            if (local_9c == (CPlugFileImg *)0x3) {
              if (uVar17 == 1) {
                for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                    pCVar19 = pCVar19 + -1) {
                  for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                    for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                      iVar11 = (byte)pCVar3[2] - 0x7f;
                      if (0x7f < iVar11) {
                        iVar11 = 0x7f;
                      }
                      *pCVar16 = SUB41(iVar11,0);
                      iVar11 = (byte)pCVar3[1] - 0x7f;
                      if (0x7f < iVar11) {
                        iVar11 = 0x7f;
                      }
                      pCVar16[1] = SUB41(iVar11,0);
                      iVar11 = (byte)*pCVar3 - 0x7f;
                      if (0x7f < iVar11) {
                        iVar11 = 0x7f;
                      }
                      pCVar16[2] = SUB41(iVar11,0);
                      pCVar16[3] = (CPlugFileImg)0x0;
                      pCVar16 = pCVar16 + 4;
                      pCVar3 = pCVar3 + iVar24;
                    }
                    pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -4);
                  }
                  pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
                }
              }
              else {
                local_9c = pCVar4 + -((int)pCVar18 * unaff_ESI);
                for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                    pCVar19 = pCVar19 + -1) {
                  for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                    for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                      iVar11 = (int)((*(ushort *)pCVar3 - 0x7fff) +
                                    ((int)(*(ushort *)pCVar3 - 0x7fff) >> 0x1f & 0xffU)) >> 8;
                      if (iVar11 < -0x7e) {
                        iVar11 = -0x7f;
                      }
                      else if (0x7e < iVar11) {
                        iVar11 = 0x7f;
                      }
                      *pCVar16 = SUB41(iVar11,0);
                      iVar11 = (int)((*(ushort *)(pCVar3 + 2) - 0x7fff) +
                                    ((int)(*(ushort *)(pCVar3 + 2) - 0x7fff) >> 0x1f & 0xffU)) >> 8;
                      if (iVar11 < -0x7e) {
                        iVar11 = -0x7f;
                      }
                      else if (0x7e < iVar11) {
                        iVar11 = 0x7f;
                      }
                      pCVar16[1] = SUB41(iVar11,0);
                      iVar11 = (int)((*(ushort *)(pCVar3 + 4) - 0x7fff) +
                                    ((int)(*(ushort *)(pCVar3 + 4) - 0x7fff) >> 0x1f & 0xffU)) >> 8;
                      if (iVar11 < -0x7e) {
                        iVar11 = -0x7f;
                      }
                      else if (0x7e < iVar11) {
                        iVar11 = 0x7f;
                      }
                      pCVar16[2] = SUB41(iVar11,0);
                      pCVar16 = pCVar16 + 4;
                      pCVar3 = pCVar3 + iVar24;
                    }
                    pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -4);
                  }
                  pCVar16 = pCVar16 + (int)local_9c;
                }
              }
            }
            else {
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    iVar11 = (byte)pCVar3[2] - 0x7f;
                    if (0x7f < iVar11) {
                      iVar11 = 0x7f;
                    }
                    *pCVar16 = SUB41(iVar11,0);
                    iVar11 = (byte)pCVar3[1] - 0x7f;
                    if (0x7f < iVar11) {
                      iVar11 = 0x7f;
                    }
                    pCVar16[1] = SUB41(iVar11,0);
                    iVar11 = (byte)*pCVar3 - 0x7f;
                    if (0x7f < iVar11) {
                      iVar11 = 0x7f;
                    }
                    pCVar16[2] = SUB41(iVar11,0);
                    iVar11 = (byte)pCVar3[3] - 0x7f;
                    if (0x7f < iVar11) {
                      iVar11 = 0x7f;
                    }
                    pCVar16[3] = SUB41(iVar11,0);
                    pCVar16 = pCVar16 + 4;
                    pCVar3 = pCVar3 + iVar24;
                  }
                  pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -4);
                }
                pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
              }
            }
            break;
          case (CReal16 *)0x40:
            for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0; pCVar19 = pCVar19 + -1)
            {
              for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                  *(ushort *)pCVar16 = *(ushort *)pCVar3 + 0x8001;
                  *(ushort *)(pCVar16 + 2) = *(ushort *)(pCVar3 + 2) + 0x8001;
                  pCVar16 = pCVar16 + 4;
                  pCVar3 = pCVar3 + iVar24;
                }
                pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -4);
              }
              pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
            }
            break;
          case (CReal16 *)0x43:
            pCStack_98 = (CReal16 *)(pCVar4 + -((int)pCVar18 * unaff_ESI));
            local_9c = pCVar18 + (int)puVar12 * -4;
            for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0; pCVar19 = pCVar19 + -1)
            {
              for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                  uVar6 = (int)((*(ushort *)pCVar3 - 0x7fff) +
                               ((int)(*(ushort *)pCVar3 - 0x7fff) >> 0x1f & 0x3fU)) >> 6;
                  if ((int)uVar6 < -0x1ff) {
                    uVar8 = 0xfffffe00;
                  }
                  else {
                    uVar8 = 0x1ff;
                    if ((int)uVar6 < 0x1ff) {
                      uVar8 = uVar6;
                    }
                  }
                  uVar6 = (int)((*(ushort *)(pCVar3 + 2) - 0x7fff) +
                               ((int)(*(ushort *)(pCVar3 + 2) - 0x7fff) >> 0x1f & 0x3fU)) >> 6;
                  if ((int)uVar6 < -0x1ff) {
                    uVar9 = 0xfffffe00;
                  }
                  else {
                    uVar9 = 0x1ff;
                    if ((int)uVar6 < 0x1ff) {
                      uVar9 = uVar6;
                    }
                  }
                  uVar6 = (int)((*(ushort *)(pCVar3 + 4) - 0x7fff) +
                               ((int)(*(ushort *)(pCVar3 + 4) - 0x7fff) >> 0x1f & 0x3fU)) >> 6;
                  if ((int)uVar6 < -0x1ff) {
                    uVar6 = 0xfffffe00;
                  }
                  else if (0x1fe < (int)uVar6) {
                    uVar6 = 0x1ff;
                  }
                  pCVar3 = pCVar3 + iVar24;
                  *(uint *)pCVar16 = ((uVar6 & 0x3ff) << 10 | uVar9 & 0x3ff) << 10 | uVar8 & 0x3ff;
                  pCVar16 = pCVar16 + 4;
                }
                pCVar16 = pCVar16 + (int)local_9c;
              }
              pCVar16 = pCVar16 + (int)pCStack_98;
            }
            break;
          case (CReal16 *)0x51:
            for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0; pCVar19 = pCVar19 + -1)
            {
              for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                  CVar1 = *pCVar3;
                  pCVar3 = pCVar3 + iVar24;
                  *(ushort *)pCVar16 = (ushort)(byte)CVar1 << 8;
                  pCVar16 = pCVar16 + 2;
                }
                pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -2);
              }
              pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
            }
            break;
          case (CReal16 *)0x6f:
            if ((*(uint *)(pCStack_98 + 0x24) & 0x1e0) == 0xe0) {
              iStack_94 = (int)pCVar4 - (int)pCVar18 * unaff_ESI;
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    *(ushort *)pCVar16 = *(ushort *)pCVar3;
                    pCVar16 = pCVar16 + 2;
                    pCVar3 = pCVar3 + iVar24;
                  }
                  pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -2);
                }
                pCVar16 = pCVar16 + iStack_94;
              }
            }
            else {
              local_88 = pCVar4 + -((int)pCVar18 * unaff_ESI);
              local_84 = (CReal16 *)(pCVar18 + (int)puVar12 * -2);
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    pCStack_98 = (CReal16 *)((float)(byte)*pCVar3 / (float)_DAT_00b55d50);
                    CReal16::CReal16(&stack0xffffff58,pCStack_98,(float)unaff_retaddr);
                    *(ushort *)pCVar16 = *extraout_EAX_00;
                    pCVar16 = pCVar16 + 2;
                    pCVar3 = pCVar3 + iVar24;
                  }
                  pCVar16 = pCVar16 + (int)local_84;
                }
                pCVar16 = pCVar16 + (int)local_88;
              }
            }
            break;
          case (CReal16 *)0x70:
            if ((*(uint *)(pCStack_98 + 0x24) & 0x1e0) == 0xe0) {
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    *(ushort *)pCVar16 = *(ushort *)pCVar3;
                    *(ushort *)(pCVar16 + 2) = *(ushort *)(pCVar3 + 2);
                    pCVar16 = pCVar16 + 4;
                    pCVar3 = pCVar3 + iVar24;
                  }
                  pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -4);
                }
                pCVar16 = pCVar16 + ((int)pCVar4 - (int)pCVar18 * unaff_ESI);
              }
            }
            else {
              iStack_94 = (int)pCVar4 - (int)pCVar18 * unaff_ESI;
              local_84 = (CReal16 *)(pCVar18 + (int)puVar12 * -4);
              for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0;
                  pCVar19 = pCVar19 + -1) {
                for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
                  for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
                    pCStack_90 = (CReal16 *)((float)(byte)*pCVar3 / (float)_DAT_00b55d50);
                    CReal16::CReal16(&stack0xffffff5c,pCStack_90,fVar26);
                    fVar26 = 0.0;
                    *(ushort *)pCVar16 = *extraout_EAX;
                    CReal16::CReal16(&local_9c,(CReal16 *)0x0,(float)unaff_retaddr);
                    *(ushort *)(pCVar16 + 2) = (ushort)pCStack_98;
                    pCVar16 = pCVar16 + 4;
                    pCVar3 = pCVar3 + iVar24;
                  }
                  pCVar16 = pCVar16 + (int)local_84;
                }
                pCVar16 = pCVar16 + iStack_94;
              }
            }
            break;
          case (CReal16 *)0x72:
            pCStack_98 = (CReal16 *)(pCVar4 + -((int)pCVar18 * unaff_ESI));
            local_9c = pCVar18 + (int)puVar12 * -4;
            if (pCVar19 != (CVisionTexConverter *)0x0) {
              fVar26 = (float)_DAT_00b55d50;
              iVar7 = unaff_ESI;
              do {
                for (; iVar7 != 0; iVar7 = iVar7 + -1) {
                  puVar14 = (undefined1 *)0x0;
                  if (3 < (int)puVar12) {
                    iVar11 = ((uint)(puVar12 + -4) >> 2) + 1;
                    puVar14 = (undefined1 *)(iVar11 * 4);
                    pCVar4 = pCVar16;
                    do {
                      pCVar18 = pCVar3 + iVar24;
                      pCVar16 = pCVar4 + 0x10;
                      *(float *)pCVar4 = (float)(byte)*pCVar3 / fVar26;
                      pCVar10 = pCVar18 + iVar24;
                      *(float *)(pCVar4 + 4) = (float)(byte)*pCVar18 / fVar26;
                      *(float *)(pCVar4 + 8) = (float)(byte)*pCVar10 / fVar26;
                      pCVar3 = pCVar10 + iVar24 + iVar24;
                      iVar11 = iVar11 + -1;
                      *(float *)(pCVar4 + 0xc) = (float)(byte)pCVar10[iVar24] / fVar26;
                      pCVar4 = pCVar16;
                    } while (iVar11 != 0);
                  }
                  if (puVar14 < puVar12) {
                    iVar11 = (int)puVar12 - (int)puVar14;
                    pCVar4 = pCVar16;
                    do {
                      CVar1 = *pCVar3;
                      pCVar3 = pCVar3 + iVar24;
                      pCVar16 = pCVar4 + 4;
                      iVar11 = iVar11 + -1;
                      *(float *)pCVar4 = (float)(byte)CVar1 / fVar26;
                      pCVar4 = pCVar16;
                    } while (iVar11 != 0);
                  }
                  pCVar16 = pCVar16 + (int)local_9c;
                }
                pCVar16 = pCVar16 + (int)pCStack_98;
                pCVar19 = pCVar19 + -1;
                iVar7 = unaff_ESI;
              } while (pCVar19 != (CVisionTexConverter *)0x0);
            }
          }
        }
      }
      else if (unaff_EBP == (CReal16 *)0x5548564e) {
        iStack_94 = (int)pCVar4 - (int)pCVar18 * unaff_ESI;
        for (; iVar7 = unaff_ESI, pCVar19 != (CVisionTexConverter *)0x0; pCVar19 = pCVar19 + -1) {
          for (; puVar14 = puVar12, iVar7 != 0; iVar7 = iVar7 + -1) {
            for (; puVar14 != (undefined1 *)0x0; puVar14 = puVar14 + -1) {
              *(ushort *)pCVar16 = *(ushort *)(pCVar3 + 2);
              *(ushort *)(pCVar16 + 2) = *(ushort *)pCVar3;
              pCVar16 = pCVar16 + 4;
              pCVar3 = pCVar3 + iVar24;
            }
            pCVar16 = pCVar16 + (int)(pCVar18 + (int)puVar12 * -4);
          }
          pCVar16 = pCVar16 + iStack_94;
        }
      }
switchD_00964c25_caseD_1b:
      iVar24 = *piStack_5c;
      if (iVar24 != 3) {
        if (iVar24 == 4) {
          (**(code **)(*(int *)pCStack_90 + 0x50))(pCStack_90,pCStack_c);
          return;
        }
        if (iVar24 == 5) {
          (**(code **)(*(int *)pCStack_90 + 0x50))(pCStack_90,pCStack_10,pCStack_c);
          return;
        }
      }
      (**(code **)(*ppCStack_8c + 0x50))(ppCStack_8c,pCStack_c);
      return;
    }
LAB_0096628a:
    ppCVar27 = *(CPlugFileImg ***)(&DAT_00bd1acc + (int)pCVar16 * 4);
    ppCVar5 = (CPlugFileImg **)((uint)(ppCVar27 != (CPlugFileImg **)0x31545844) * 8 + 8);
    pCVar19 = (CVisionTexConverter *)((uint)(pCStack_58 + 3) >> 2);
  }
  else {
    if (bVar20) goto LAB_0096628a;
    ppCVar27 = (CPlugFileImg **)((ppCStack_8c != (CPlugFileImg **)0x3) + 0x14);
    ppCVar5 = ppCStack_8c;
    pCVar19 = pCStack_58;
  }
  iVar7 = *(int *)this;
  iVar24 = (int)pCVar19 * (int)ppCVar5;
  pCStack_68 = pCStack_58;
  pCStack_70 = (CReal16 *)0x0;
  uStack_6c = 0;
  pCStack_64 = pCStack_54;
  pCStack_98 = (CReal16 *)0x0;
  if (iVar7 == 3) {
LAB_0096631c:
    ppCVar13 = &pCStack_98;
LAB_00966324:
    (**(code **)((int)*(float *)pCStack_7c + 0x48))(pCStack_7c,param_1,ppCVar13);
  }
  else {
    if (iVar7 == 4) {
      ppCVar13 = (CReal16 **)&stack0xffffff5c;
      pCStack_7c = local_80;
      goto LAB_00966324;
    }
    if (iVar7 != 5) goto LAB_0096631c;
    (**(code **)((int)*(float *)local_80 + 0x48))(local_80,unaff_retaddr,param_1,&pCStack_98);
  }
  if ((pCStack_60 == unaff_EBP) && (piStack_5c == (int *)0x0)) {
    uVar28 = 1;
  }
  else if ((pCStack_60 != (CReal16 *)((int)unaff_EBP * 2)) || (uVar28 = 5, piStack_5c != (int *)0x0)
          ) {
    uVar28 = 4;
  }
  uVar29 = 0;
  ppCVar5 = &local_78;
  uVar25 = 0;
  uVar22 = 0;
  uVar21 = 0;
  _D3DXLoadSurfaceFromMemory_40();
  ppCVar23 = ppCVar27;
  if (ppCVar5 != (CPlugFileImg **)0x0) {
    (**(code **)(*ppCVar5 + 8))
              (ppCVar5,pCStack_a0,uVar21,uVar22,ppCStack_8c,ppCVar27,iVar24,uVar25,ppCVar5,uVar28,
               uVar29);
    ppCVar23 = ppCVar27;
  }
LAB_009663a2:
  if (ppCVar27 != (CPlugFileImg **)0x0) {
    (**(code **)(*ppCVar27 + 8))
              (ppCVar27,pCStack_a0,uVar21,uVar22,ppCStack_8c,ppCVar23,iVar24,uVar25,ppCVar5,uVar28);
  }
  return;
}
}

