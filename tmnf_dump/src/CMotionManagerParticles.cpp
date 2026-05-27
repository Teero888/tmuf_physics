// Class implementation: CMotionManagerParticles

// =================================================
// Function: CMotionManagerParticles::EmitterGetEmitParamsAsync
// =================================================
void __thiscall
CMotionManagerParticles::EmitterGetEmitParamsAsync
          (CMotionManagerParticles *this,CMotionManagerParticles *param_1,
          CMotionEmitterParticles *param_2,SEmitParams *param_3)
{
{
  int *piVar1;
  GmIso3 *pGVar2;
  int iVar3;
  int unaff_EBX;
  CMotionManagerParticles *pCVar4;
  CMotionEmitterParticles *pCVar5;
  GmIso3 *pGVar6;
  GmIso3 *pGVar7;
  
  pCVar4 = param_1 + 0x24;
  pCVar5 = param_2;
  for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pCVar5 = *(undefined4 *)pCVar4;
    pCVar4 = pCVar4 + 4;
    pCVar5 = pCVar5 + 4;
  }
  piVar1 = (int *)(**(code **)(*(int *)param_1 + 0x98))();
  if (*(int *)(param_1 + 0x7c) != 0) {
    pGVar7 = (GmIso3 *)0xa011000;
    iVar3 = (**(code **)(*piVar1 + 0x10))();
    if (iVar3 != 0) {
      pGVar6 = *(GmIso3 **)(unaff_EBX + 0x24);
      pGVar2 = (GmIso3 *)(**(code **)(*piVar1 + 0x80))();
      GmIso4::Mult(param_2,pGVar2,pGVar6);
      GmVec3::Mult(param_2 + 0x3c,pGVar2,pGVar7);
    }
  }
  return;
}
}

// =================================================
// Function: CMotionManagerParticles::GroupEmitParticles
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionManagerParticles::GroupEmitParticles
          (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2,
          ulong param_3)
{
{
  void *this_00;
  float fVar1;
  float fVar2;
  ushort uVar3;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar4;
  int *piVar5;
  CMotionParticleType *pCVar6;
  float fVar7;
  float fVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  SCasterCat *this_01;
  ulong uVar10;
  SCasterCat *pSVar11;
  int iVar12;
  SLoadedLight *pSVar13;
  CMotionManagerParticles *pCVar14;
  uint uVar15;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar16;
  CMotionEmitterParticles *unaff_EBP;
  GmFrustumIso4 *unaff_ESI;
  float *pfVar17;
  CMotionParticleType *pCVar18;
  ulong unaff_EDI;
  CMotionEmitterParticles *pCVar19;
  float10 fVar20;
  CMotionEmitterParticles *in_stack_00000018;
  CMotionManagerParticles *in_stack_0000001c;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffff1c;
  CMotionParticleType *in_stack_ffffff20;
  SEmitParams *pSVar21;
  SEmitParams *in_stack_ffffff28;
  CMotionManagerParticles *pCStack_c8;
  CMotionManagerParticles *pCStack_c4;
  ulonglong uStack_c0;
  void *pvStack_b8;
  undefined4 uStack_b4;
  float fStack_b0;
  float fStack_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  CMotionParticleType aCStack_8c [36];
  float fStack_68;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pSVar21 = (SEmitParams *)this;
  this_01 = CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                      (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                       unaff_EDI);
  if (*(int *)(*(int *)(this_01 + 0xc) + 0x1c) != 0) {
    if (*(int *)(*(int *)(this_01 + 0xc) + 0x14) == 2) {
      CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_01,unaff_ESI);
    }
    local_a0 = 0.0;
    this_00 = (void *)(*(int *)(*(int *)(this + 0x24) + 0x14) + 0x38);
    local_a4 = 0.0;
    local_a8 = 0.0;
    uVar10 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,in_stack_ffffff1c);
    if (uVar10 != 0) {
      pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                           (ulong)in_stack_ffffff20);
      in_stack_ffffff20 = (CMotionParticleType *)0x0;
      iVar12 = (**(code **)(**(int **)pSVar11 + 0x7c))();
      local_a4 = *(float *)(iVar12 + 0x24);
      local_a0 = *(float *)(iVar12 + 0x28);
      fStack_9c = *(float *)(iVar12 + 0x2c);
    }
    pCStack_18 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount(this_01 + 0x1c,unaff_EBX);
    pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCStack_18 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar11 = CFastBuffer<struct_SHmsVPackerObjectPacked>::operator[]
                            (this_01 + 0x1c,pCVar16,(ulong)unaff_EBP);
        unaff_EBP = (CMotionEmitterParticles *)&fStack_90;
        EmitterGetEmitParamsAsync
                  (pCStack_c8,*(CMotionManagerParticles **)pSVar11,unaff_EBP,
                   (SEmitParams *)in_stack_ffffff20);
        pCVar4 = *(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> **)(this_01 + 0xc);
        fVar1 = (fStack_90 - fStack_60) * (fStack_90 - fStack_60) +
                (fStack_98 - fStack_68) * (fStack_98 - fStack_68) +
                (fStack_94 - (float)pCStack_64) * (fStack_94 - (float)pCStack_64);
        if (fVar1 <= *(float *)(pCVar4 + 0x3c)) {
          if ((*(int *)(pCVar4 + 0x14) == 2) && (*(int *)(*(int *)pSVar11 + 0x8c) != 0)) {
            in_stack_ffffff20 = aCStack_8c;
            unaff_EBP = in_stack_00000018;
            pSVar13 = CFastBuffer<struct_CMotionManagerParticles::SPart>::AddNewElem
                                (pvStack_b8,pCVar4);
            PartInit((CMotionManagerParticles *)(SCasterCat *)uStack_c0,
                     (CMotionManagerParticles *)pSVar13,(SPart *)unaff_EBP,in_stack_ffffff20,
                     (ulong)pSVar21,in_stack_ffffff28);
          }
          else {
            piVar5 = *(int **)pSVar11;
            if (piVar5[0x21] == 0) {
              if (piVar5[0x23] == 0) {
                *(undefined4 *)(pSVar11 + 0x3c) = 1;
              }
              else {
                iVar12 = *(int *)(pCVar4 + 0x7c);
                if (iVar12 == 1) {
                  fStack_28 = *(float *)(pSVar11 + 0x28) - fStack_68;
                  fStack_24 = *(float *)(pSVar11 + 0x2c) - (float)pCStack_64;
                  fStack_20 = *(float *)(pSVar11 + 0x30) - fStack_60;
                  fVar1 = *(float *)(*(int *)((int)pvStack_b8 + 0xc) + 0x84);
                  if (fVar1 * fVar1 <
                      fStack_20 * fStack_20 + fStack_28 * fStack_28 + fStack_24 * fStack_24) {
LAB_0056513f:
                    in_stack_ffffff20 = aCStack_8c;
                    unaff_EBP = in_stack_00000018;
                    GroupEmitOnePart(pCStack_c4,in_stack_0000001c,(ulong)pCVar16,
                                     (ulong)in_stack_00000018,(ulong)in_stack_ffffff20,pSVar21);
                  }
                }
                else if (iVar12 == 4) {
                  if (*(int *)(pSVar11 + 0x3c) == 0) {
                    fStack_34 = fStack_68 - *(float *)(pSVar11 + 0x28);
                    fStack_30 = (float)pCStack_64 - *(float *)(pSVar11 + 0x2c);
                    fStack_2c = fStack_60 - *(float *)(pSVar11 + 0x30);
                    in_stack_ffffff20 = (CMotionParticleType *)0x564fef;
                    fVar20 = (float10)func_0x009c1b40();
                    fVar1 = (float)fVar20;
                    if (_DAT_00b59b68 < fVar1) {
                      fVar2 = *(float *)(pCVar4 + 0x84);
                      fVar7 = 1.0 / fVar1;
                      fStack_b0 = fVar2 * fVar7 * fStack_34;
                      fStack_ac = fStack_30 * fVar7 * fVar2;
                      pCVar14 = (CMotionManagerParticles *)0x0;
                      local_a8 = fVar7 * fStack_2c * fVar2;
                      fStack_68 = *(float *)(pSVar11 + 0x28) + fStack_b0;
                      pCStack_64 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                   (*(float *)(pSVar11 + 0x2c) + fStack_ac);
                      fStack_60 = *(float *)(pSVar11 + 0x30) + local_a8;
                      uStack_c0 = (ulonglong)ROUND(fVar1 / fVar2);
                      pCStack_c8 = (CMotionManagerParticles *)(SCasterCat *)uStack_c0;
                      if ((SCasterCat *)uStack_c0 != (SCasterCat *)0x0) {
                        do {
                          pCVar14 = pCVar14 + 1;
                          fStack_68 = fStack_b0 + fStack_68;
                          in_stack_ffffff20 = aCStack_8c;
                          pCStack_64 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                       (fStack_ac + (float)pCStack_64);
                          fStack_60 = local_a8 + fStack_60;
                          unaff_EBP = (CMotionEmitterParticles *)
                                      ((uint)(((int)in_stack_00000018 - *(int *)(pSVar11 + 0x34)) *
                                             (int)pCVar14) / (uint)(SCasterCat *)uStack_c0 +
                                      *(int *)(pSVar11 + 0x34));
                          GroupEmitOnePart(pCStack_c4,in_stack_0000001c,(ulong)pCVar16,
                                           (ulong)unaff_EBP,(ulong)in_stack_ffffff20,pSVar21);
                        } while (pCVar14 < pCStack_c4);
                      }
                    }
                  }
                  else {
                    in_stack_ffffff20 = aCStack_8c;
                    unaff_EBP = in_stack_00000018;
                    GroupEmitOnePart(pCStack_c4,in_stack_0000001c,(ulong)pCVar16,
                                     (ulong)in_stack_00000018,(ulong)in_stack_ffffff20,pSVar21);
                  }
                }
                else {
                  if (iVar12 == 2) goto LAB_0056513f;
                  if (iVar12 == 0) {
                    if ((*(CMotionEmitterParticles **)(pSVar11 + 0x34) < in_stack_00000018) &&
                       (uVar15 = (int)in_stack_00000018 -
                                 (int)*(CMotionEmitterParticles **)(pSVar11 + 0x34), uVar15 < 5000))
                    {
                      if (*(int *)(pSVar11 + 0x3c) == 0) {
                        in_stack_ffffff20 = *(CMotionParticleType **)(pCVar4 + 0x80);
                        unaff_EBP = (CMotionEmitterParticles *)0x5651b4;
                        pCStack_c8 = (CMotionManagerParticles *)
                                     CMwTimer::SecondsToMwTime((float)in_stack_ffffff20);
                        fVar2 = fStack_60;
                        pCVar9 = pCStack_64;
                        fVar1 = fStack_68;
                        if (pCStack_c8 == (CMotionManagerParticles *)0x0) {
                          pCStack_c8 = (CMotionManagerParticles *)&DAT_00000014;
                        }
                        pCVar19 = *(CMotionEmitterParticles **)(pSVar11 + 0x34);
                        if ((pCVar19 + (int)pCStack_c8 < in_stack_00000018) &&
                           (pCVar14 = pCStack_c8, uVar15 / (uint)pCStack_c8 != 0)) {
                          do {
                            pCVar19 = pCVar19 + (int)pCVar14;
                            iVar12 = (int)pCVar19 - *(int *)(pSVar11 + 0x34);
                            fVar7 = (float)iVar12;
                            if (iVar12 < 0) {
                              fVar7 = fVar7 + _DAT_00c418d0;
                            }
                            iVar12 = (int)in_stack_00000018 - *(int *)(pSVar11 + 0x34);
                            fVar8 = (float)iVar12;
                            if (iVar12 < 0) {
                              fVar8 = fVar8 + _DAT_00c418d0;
                            }
                            fVar7 = fVar7 / fVar8;
                            in_stack_ffffff20 = aCStack_8c;
                            uStack_c0 = (ulonglong)(uint)fVar7;
                            fStack_68 = fVar7 * (fVar1 - *(float *)(pSVar11 + 0x28)) +
                                        *(float *)(pSVar11 + 0x28);
                            pCStack_64 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                         (((float)pCVar9 - *(float *)(pSVar11 + 0x2c)) * fVar7 +
                                         *(float *)(pSVar11 + 0x2c));
                            fStack_60 = *(float *)(pSVar11 + 0x30) +
                                        fVar7 * (fVar2 - *(float *)(pSVar11 + 0x30));
                            unaff_EBP = pCVar19;
                            GroupEmitOnePart(pCStack_c4,in_stack_0000001c,(ulong)pCVar16,
                                             (ulong)pCVar19,(ulong)in_stack_ffffff20,pSVar21);
                            pCStack_c8 = pCStack_c8 + -1;
                            pCVar14 = pCStack_c4;
                          } while (pCStack_c8 != (CMotionManagerParticles *)0x0);
                          pCStack_c8 = (CMotionManagerParticles *)0x0;
                        }
                      }
                      else {
                        in_stack_ffffff20 = aCStack_8c;
                        unaff_EBP = in_stack_00000018;
                        GroupEmitOnePart(pCStack_c4,in_stack_0000001c,(ulong)pCVar16,
                                         (ulong)in_stack_00000018,(ulong)in_stack_ffffff20,pSVar21);
                      }
                    }
                    else {
                      in_stack_ffffff20 = (CMotionParticleType *)0x56531b;
                      (**(code **)(*piVar5 + 0x98))();
                      *(CMotionEmitterParticles **)(pSVar11 + 0x34) = in_stack_00000018;
                      pfVar17 = &fStack_94;
                      for (iVar12 = 0xc; pSVar11 = pSVar11 + 4, iVar12 != 0; iVar12 = iVar12 + -1) {
                        *(float *)pSVar11 = *pfVar17;
                        pfVar17 = pfVar17 + 1;
                      }
                    }
                  }
                  else if (iVar12 == 3) {
                    *(undefined4 *)(*(int *)((int)pvStack_b8 + 0xc) + 0x100) = 0;
                    *(undefined4 *)(*(int *)((int)pvStack_b8 + 0xc) + 0x104) = 0;
                    uVar3 = *(ushort *)(*(int *)(*(int *)((int)pvStack_b8 + 0xc) + 0x38) + 0x28);
                    uStack_b4 = CONCAT22(uStack_b4._2_2_,uVar3);
                    if ((uVar3 & 1) != 0) {
                      uStack_b4 = CONCAT22(uStack_b4._2_2_,uVar3) & 0xfffffffe;
                      in_stack_ffffff20 = (CMotionParticleType *)&uStack_b4;
                      unaff_EBP = (CMotionEmitterParticles *)0x565380;
                      CPlugShader::SetVisibleId
                                (*(CPlugShader **)(*(int *)((int)pvStack_b8 + 0xc) + 0x38),
                                 (CPlugShader *)in_stack_ffffff20,(SPlugVisibleId *)pSVar21);
                    }
                    fStack_10 = fStack_5c;
                    pCStack_18 = pCStack_64;
                    fStack_14 = fStack_60;
                    fStack_9c = fStack_48;
                    if (ABS(fStack_48) <= _DAT_00b41d80) {
                      fStack_98 = 0.0;
                      local_a0 = 0.0;
                    }
                    else {
                      fStack_98 = 1.0 / ABS(fStack_48);
                      local_a0 = fStack_98 * fStack_4c;
                      fStack_98 = fStack_98 * fStack_44;
                    }
                    uStack_c0 = uStack_c0 & 0xffffffff;
                    pCVar6 = *(CMotionParticleType **)(*(int *)((int)pvStack_b8 + 0xc) + 0x14c);
                    pCVar18 = (CMotionParticleType *)0x0;
                    if (pCVar6 != (CMotionParticleType *)0x0) {
                      do {
                        CMotionParticleType::GenerateSplashPart
                                  (*(CMotionParticleType **)(uStack_b4 + 0xc),pCVar18,
                                   (ulong)&pCStack_64,(GmVec3 *)&fStack_4c,
                                   (GmVec3 *)in_stack_ffffff28);
                        fStack_60 = fStack_14 + fStack_60;
                        fStack_5c = fStack_10 + fStack_5c;
                        fStack_58 = fStack_c + fStack_58;
                        pvStack_b8 = (void *)(fStack_40 * fStack_40 +
                                             fStack_48 * fStack_48 + fStack_44 * fStack_44);
                        pSVar21 = *(SEmitParams **)(*(int *)((int)fStack_b0 + 0xc) + 0x160);
                        pCStack_c4 = (CMotionManagerParticles *)
                                     GmFunc::RandReal((float)pSVar21,
                                                      *(float *)(*(int *)((int)fStack_b0 + 0xc) +
                                                                0x164));
                        in_stack_ffffff28 = (SEmitParams *)0x5654ee;
                        fVar20 = (float10)func_0x009c1b40();
                        fStack_4 = (float)fVar20 * fVar1;
                        in_stack_ffffff20 = aCStack_8c;
                        uStack_c0 = (ulonglong)(uint)fStack_4;
                        fStack_c = fStack_4 * local_a4;
                        fStack_8 = (float)_PTR_00b2c178 * fStack_4;
                        fStack_4 = fStack_4 * fStack_9c;
                        fStack_50 = fStack_c + fStack_50;
                        fStack_4c = fStack_8 + fStack_4c;
                        fStack_48 = fStack_4 + fStack_48;
                        unaff_EBP = in_stack_00000018;
                        GroupEmitOnePart(pCStack_c4,in_stack_0000001c,(ulong)pCVar16,
                                         (ulong)in_stack_00000018,(ulong)in_stack_ffffff20,pSVar21);
                        pCVar18 = pCVar18 + 1;
                      } while (pCVar18 < pCVar6);
                    }
                  }
                  else if (iVar12 == 5) {
                    for (iVar12 = *(int *)(pCVar4 + 0x14c); iVar12 != 0; iVar12 = iVar12 + -1) {
                      in_stack_ffffff20 = aCStack_8c;
                      unaff_EBP = in_stack_00000018;
                      GroupEmitOnePart(pCStack_c4,in_stack_0000001c,(ulong)pCVar16,
                                       (ulong)in_stack_00000018,(ulong)in_stack_ffffff20,pSVar21);
                    }
                  }
                }
              }
            }
            else {
              *(undefined4 *)(pSVar11 + 0x3c) = 1;
              piVar5[0x21] = 0;
            }
          }
        }
        pCVar16 = pCVar16 + 1;
        if (pCStack_18 <= pCVar16) {
          return;
        }
        this_01 = (SCasterCat *)uStack_c0;
      } while( true );
    }
  }
  return;
}
}

// =================================================
// Function: CMotionManagerParticles::GroupKillParticle
// =================================================
void __thiscall
CMotionManagerParticles::GroupKillParticle
          (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2,
          ulong param_3)
{
{
  SCasterCat *pSVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_retaddr;
  
  pSVar1 = CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                     (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,param_2)
  ;
  pSVar1 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                     (pSVar1,unaff_retaddr,(ulong)param_1);
  *(undefined4 *)pSVar1 = 0;
  *(undefined4 *)(pSVar1 + 4) = 0;
  *(undefined4 *)(pSVar1 + 0x84) = 0xffffffff;
  *(undefined4 *)(pSVar1 + 0x80) = 0xffffffff;
  *(undefined4 *)(pSVar1 + 0x88) = 0;
  *(undefined4 *)(pSVar1 + 0x8c) = 0;
  *(undefined4 *)(pSVar1 + 0xc) = 0xffffffff;
  *(undefined4 *)(pSVar1 + 8) = 0xffffffff;
  return;
}
}

// =================================================
// Function: CMotionManagerParticles::GroupUpdateMultiState
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionManagerParticles::GroupUpdateMultiState
          (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2,
          ulong param_3,GmVec3 *param_4,GmVec3 *param_5,ulong *param_6)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  CMotionParticleType *pCVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CMotionManagerParticles *pCVar5;
  SCasterCat *this_00;
  SCasterCat *pSVar6;
  SCasterCat *pSVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CMotionManagerParticles *pCVar8;
  GmFrustumIso4 *unaff_EBP;
  CMotionManagerParticles *this_01;
  ulong *puVar9;
  GmFrustumIso4 *unaff_ESI;
  ulong unaff_EDI;
  float10 fVar10;
  ulong *in_stack_0000001c;
  undefined4 *in_stack_00000020;
  undefined4 *in_stack_00000024;
  CPlugVisual *pCVar11;
  GmVec3 *pGVar12;
  SPart *in_stack_fffffecc;
  SEmitParams *in_stack_fffffed0;
  undefined1 *in_stack_fffffed4;
  SEmitParams *in_stack_fffffed8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_11c;
  int local_118;
  float local_114;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_10c;
  CMotionManagerParticles *local_108;
  CMotionManagerParticles *local_104;
  undefined4 uStack_100;
  ulong local_fc;
  ulong local_f8;
  ulong uStack_f4;
  int local_f0;
  SCasterCat *pSStack_ec;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  CMotionManagerParticles aCStack_d0 [60];
  float local_94;
  float local_90;
  float fStack_8c;
  float fStack_4c;
  CMotionEmitterParticles aCStack_44 [8];
  undefined1 auStack_3c [60];
  
  pCVar5 = _DAT_00b59b78;
  local_108 = _DAT_00b59b74;
  local_104 = _DAT_00b59b74;
  pCVar8 = (CMotionManagerParticles *)0x0;
  this_00 = CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                      (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                       unaff_EDI);
  iVar1 = *(int *)(*(int *)(this_00 + 0xc) + 0x24);
  if (0 < iVar1) {
    if (iVar1 < 3) {
      iVar1 = *(int *)(this_00 + 0x14);
      CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset((void *)(iVar1 + 0x78),unaff_ESI);
      CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                ((void *)(*(int *)(iVar1 + 0x98) + 0x1c),unaff_EBP);
    }
    else if (iVar1 == 3) {
      CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                ((void *)(*(int *)(this_00 + 0x14) + 0x78),unaff_ESI);
    }
  }
  local_e0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00 + 0x1c,unaff_EBX);
  local_10c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  this_01 = this;
  if (local_e0 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pGVar12 = (GmVec3 *)local_10c;
      pSStack_ec = CFastBuffer<struct_SHmsVPackerObjectPacked>::operator[]
                             (this_00 + 0x1c,local_10c,(ulong)in_stack_fffffecc);
      pCVar2 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSStack_ec + 0x38);
      local_11c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      local_114 = 1.4013e-45;
      local_118 = -1;
      puVar9 = in_stack_0000001c;
      if (((*(int *)(*(int *)(this_00 + 0xc) + 0x28) == 0) || (*(int *)(pSStack_ec + 0x3c) != 0)) ||
         (*(int *)(*(CMotionManagerParticles **)pSStack_ec + 0x8c) == 0)) {
joined_r0x00565b2a:
        pCVar4 = pCVar2;
        if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
          pSVar6 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                             (this_00,pCVar4,(ulong)pGVar12);
          if ((*(ulong **)pSVar6 <= puVar9) && (puVar9 <= *(ulong **)(pSVar6 + 4)))
          goto code_r0x00565b43;
          if (local_11c == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
            *(undefined4 *)(local_f0 + 0x38) = 0xffffffff;
          }
          else {
            pSVar6 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                               (this_00,local_11c,(ulong)in_stack_fffffecc);
            *(undefined4 *)(pSVar6 + 0x80) = 0xffffffff;
            pGVar12 = (GmVec3 *)local_11c;
          }
          while (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
            pSVar6 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                               (this_00,pCVar4,(ulong)pGVar12);
            pCVar4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar6 + 0x80);
            *(undefined4 *)(pSVar6 + 0x8c) = 0;
            *(undefined4 *)(pSVar6 + 0x80) = 0xffffffff;
            *(undefined4 *)(pSVar6 + 0x84) = 0xffffffff;
          }
        }
        goto LAB_00565be8;
      }
      if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
        EmitterGetEmitParamsAsync
                  (this_01,*(CMotionManagerParticles **)pSStack_ec,aCStack_44,in_stack_fffffed0);
        pSVar6 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                           (this_00,pCVar2,(ulong)in_stack_fffffed4);
        in_stack_fffffed4 = auStack_3c;
        in_stack_fffffecc = *(SPart **)(this_00 + 0xc);
        in_stack_fffffed0 = (SEmitParams *)0x0;
        PartInit(local_104,aCStack_d0,in_stack_fffffecc,(CMotionParticleType *)0x0,
                 (ulong)in_stack_fffffed4,in_stack_fffffed8);
        local_dc = *(float *)(pSVar6 + 0x38) - local_94;
        pCVar3 = *(CMotionParticleType **)(this_00 + 0xc);
        local_d8 = *(float *)(pSVar6 + 0x3c) - local_90;
        local_d4 = *(float *)(pSVar6 + 0x40) - fStack_8c;
        local_114 = local_d4 * local_d4 + local_dc * local_dc + local_d8 * local_d8;
        in_stack_fffffed8 = (SEmitParams *)0x565ae1;
        fVar10 = (float10)func_0x009c1b40();
        pGVar12 = (GmVec3 *)&local_108;
        fStack_4c = (float)fVar10 * *(float *)(pCVar3 + 0x50) + *(float *)(pSVar6 + 0x90);
        MultiStateAddLinkVisual
                  ((ulong)param_6,pCVar3,(SPart *)pSVar6,(SPart *)&local_dc,
                   *(CPlugVisual **)(this_00 + 0x14),(GmVec3 *)&local_fc,pGVar12);
        puVar9 = param_6;
        goto joined_r0x00565b2a;
      }
LAB_00565be8:
      pCVar8 = this + (int)local_114;
      local_10c = local_10c + 1;
      this_01 = pCVar5;
    } while (local_10c < local_e0);
  }
  *in_stack_00000024 = pCVar8;
  *in_stack_0000001c = local_fc;
  in_stack_0000001c[1] = local_f8;
  in_stack_0000001c[2] = uStack_f4;
  *in_stack_00000020 = local_108;
  in_stack_00000020[1] = local_104;
  in_stack_00000020[2] = uStack_100;
  return;
code_r0x00565b43:
  if ((local_11c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) &&
     (local_118 == 0)) {
    pGVar12 = (GmVec3 *)&local_108;
    pCVar11 = (CPlugVisual *)&local_fc;
    pSVar7 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                       (this_00,local_11c,*(ulong *)(this_00 + 0x14));
    MultiStateAddLinkVisual
              ((ulong)puVar9,*(CMotionParticleType **)(this_00 + 0xc),(SPart *)pSVar6,
               (SPart *)pSVar7,pCVar11,pGVar12,(GmVec3 *)in_stack_fffffecc);
  }
  local_118 = *(int *)(pSVar6 + 0x88);
  pCVar2 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar6 + 0x80);
  local_11c = pCVar4;
  goto joined_r0x00565b2a;
}
}

// =================================================
// Function: CMotionManagerParticles::GroupUpdateMultistateLightTrail
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionManagerParticles::GroupUpdateMultistateLightTrail
          (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2,
          ulong param_3,GmVec3 *param_4,GmVec3 *param_5,ulong *param_6)
{
{
  int iVar1;
  CMotionManagerParticles *this_00;
  SPartGroup *this_01;
  SCasterCat *pSVar2;
  ulong uVar3;
  GmVec3 *pGVar4;
  TiXmlAttribute *pTVar5;
  GmFrustumIso4 *unaff_EBX;
  GmVec3 *unaff_EBP;
  uint uVar6;
  ulong unaff_ESI;
  void *this_02;
  ulong unaff_EDI;
  void *pvVar7;
  float10 fVar8;
  undefined4 *in_stack_00000020;
  uint *in_stack_00000024;
  int *in_stack_00000028;
  GmFrustumIso4 *in_stack_fffffe48;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffe4c;
  GmVec3 *in_stack_fffffe50;
  GmVec3 *in_stack_fffffe54;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffe58;
  GmVec3 *pGVar9;
  TiXmlAttribute *in_stack_fffffe5c;
  TiXmlAttribute *in_stack_fffffe60;
  TiXmlAttribute *pTVar10;
  TiXmlAttribute *in_stack_fffffe68;
  GmVec3 *pGVar11;
  GmVec3 *pGStack_18c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_188;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_184;
  void *local_180;
  CFastBuffer<class_GxVertex> *local_17c;
  void *local_178;
  CFastBuffer<class_GxVertex> *local_174;
  CFastBuffer<class_GxVertex> *local_170;
  CFastBuffer<class_GxVertex> *local_16c;
  GxTexCoord *local_168;
  CFastBuffer<class_GxVertex> *pCStack_164;
  SCasterCat *local_160;
  undefined4 uStack_15c;
  undefined4 local_158;
  uint local_154;
  CMotionManagerParticles *local_150 [2];
  SCasterCat *pSStack_148;
  SPartGroup *local_140;
  float local_138;
  CMotionManagerParticles *local_134;
  float local_130;
  SCasterCat *pSStack_12c;
  SPartState aSStack_128 [4];
  SPartState local_124 [44];
  float local_f8;
  float local_f4;
  float local_f0;
  float fStack_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  CMotionManagerParticles local_cc [4];
  SPart local_c8 [92];
  float local_6c;
  float local_68;
  float local_64;
  float fStack_40;
  CMotionEmitterParticles local_3c [4];
  undefined1 local_38 [56];
  
  local_174 = _DAT_00b59b74;
  local_170 = _DAT_00b59b74;
  local_16c = _DAT_00b59b74;
  local_180 = _DAT_00b59b78;
  local_17c = _DAT_00b59b78;
  local_178 = _DAT_00b59b78;
  local_150[0] = this;
  this_01 = (SPartGroup *)
            CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                      (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                       unaff_EDI);
  iVar1 = *(int *)(this_01 + 0x14);
  local_160 = (SCasterCat *)this_01;
  pSVar2 = CFastBuffer<struct_SFastCat>::operator[]
                     ((void *)(iVar1 + 0x5c),(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      unaff_ESI);
  local_17c = *(CFastBuffer<class_GxVertex> **)(pSVar2 + 4);
  local_180 = *(void **)(iVar1 + 0x88);
  this_02 = (void *)(*(int *)(iVar1 + 0x98) + 0x1c);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset((void *)(iVar1 + 0x78),unaff_EBX);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_02,in_stack_fffffe48);
  local_140 = (SPartGroup *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        ((SCasterCat *)(this_01 + 0x1c),in_stack_fffffe4c);
  local_188 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (local_140 != (SPartGroup *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_SHmsVPackerObjectPacked>::operator[]
                         (this_01 + 0x1c,local_188,(ulong)unaff_EBP);
      local_188 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      pGVar9 = *(GmVec3 **)(pSVar2 + 0x38);
      pTVar10 = (TiXmlAttribute *)0x1;
      pGVar11 = (GmVec3 *)0xffffffff;
      unaff_EBP = (GmVec3 *)0x566b09;
      local_134 = (CMotionManagerParticles *)pSVar2;
      uVar3 = CMotionParticleType::GetVertPerPartCount
                        (*(CMotionParticleType **)(this_01 + 0xc),
                         (CMotionParticleType *)in_stack_fffffe50);
      this_00 = local_134;
      if ((*(int *)(pSVar2 + 0x3c) != 0) ||
         (*(int *)(*(CMotionManagerParticles **)pSVar2 + 0x8c) == 0)) {
joined_r0x00566c78:
        pGVar4 = pGVar11;
        if (pGVar9 != (GmVec3 *)0xffffffff) {
          unaff_EBP = (GmVec3 *)0x566c88;
          in_stack_fffffe50 = pGVar9;
          pSVar2 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                             (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar9,
                              (ulong)in_stack_fffffe54);
          pSStack_148 = pSVar2;
          if ((*(int **)pSVar2 <= in_stack_00000028) && (in_stack_00000028 <= *(int **)(pSVar2 + 4))
             ) goto code_r0x00566ca7;
          if (local_188 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
            *(undefined4 *)(pSStack_12c + 0x38) = 0xffffffff;
          }
          else {
            in_stack_fffffe50 = (GmVec3 *)0x566e68;
            in_stack_fffffe54 = (GmVec3 *)local_188;
            pSVar2 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                               (this_01,local_188,(ulong)in_stack_fffffe58);
            *(undefined4 *)(pSVar2 + 0x80) = 0xffffffff;
          }
          while (pGVar9 != (GmVec3 *)0xffffffff) {
            in_stack_fffffe54 = (GmVec3 *)0x566e8c;
            pSVar2 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                               (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar9,
                                (ulong)in_stack_fffffe5c);
            local_184 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar2 + 0x80);
            *(undefined4 *)(pSVar2 + 0x8c) = 0;
            *(undefined4 *)(pSVar2 + 0x80) = 0xffffffff;
            *(undefined4 *)(pSVar2 + 0x84) = 0xffffffff;
            in_stack_fffffe58 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar9;
            pGVar9 = (GmVec3 *)local_184;
          }
        }
        goto LAB_00566eb0;
      }
      if (pGVar9 != (GmVec3 *)0xffffffff) {
        in_stack_fffffe68 = (TiXmlAttribute *)0x0;
        EmitterGetEmitParamsAsync
                  (local_134,*(CMotionManagerParticles **)pSVar2,local_3c,
                   (SEmitParams *)in_stack_fffffe54);
        PartInit(this_00,local_cc,*(SPart **)(this_01 + 0xc),(CMotionParticleType *)0x0,
                 (ulong)local_38,(SEmitParams *)in_stack_fffffe58);
        PartGetState(0,local_c8,this_01,local_124);
        local_d8 = local_6c * local_d8;
        local_d4 = local_68 * local_d4;
        local_d0 = local_64 * local_d0;
        in_stack_fffffe54 = (GmVec3 *)0x566bce;
        in_stack_fffffe58 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar9;
        pSVar2 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                           (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar9,
                            (ulong)in_stack_fffffe5c);
        local_138 = *(float *)(pSVar2 + 0x38) - local_f8;
        local_134 = (CMotionManagerParticles *)(*(float *)(pSVar2 + 0x3c) - local_f4);
        local_130 = *(float *)(pSVar2 + 0x40) - local_f0;
        pGVar11 = (GmVec3 *)
                  (local_130 * local_130 +
                  local_138 * local_138 + (float)local_134 * (float)local_134);
        in_stack_fffffe5c = (TiXmlAttribute *)0x566c23;
        fVar8 = (float10)func_0x009c1b40();
        pTVar10 = (TiXmlAttribute *)(float)fVar8;
        unaff_EBP = (GmVec3 *)&pCStack_164;
        fStack_40 = (float)pTVar10 * *(float *)(*(CMotionParticleType **)(this_01 + 0xc) + 0x50) +
                    *(float *)(pSVar2 + 0x90);
        in_stack_fffffe50 = (GmVec3 *)local_16c;
        LightTrailAddPartVerts
                  (*(CMotionParticleType **)(this_01 + 0xc),local_17c,local_168,(SPart *)&local_d0,
                   (SPartState *)&pSStack_12c,uVar3,(GmVec3 *)&local_158,unaff_EBP,
                   (GmVec3 *)local_16c);
        goto joined_r0x00566c78;
      }
LAB_00566eb0:
      local_17c = local_17c + (int)pGStack_18c;
      local_188 = local_188 + 1;
    } while (local_188 < local_140);
  }
  *in_stack_00000028 = (int)local_17c;
  *in_stack_00000020 = local_160;
  in_stack_00000020[1] = uStack_15c;
  in_stack_00000020[2] = local_158;
  *in_stack_00000024 = (uint)local_16c;
  in_stack_00000024[1] = (uint)local_168;
  in_stack_00000024[2] = (uint)pCStack_164;
  return;
code_r0x00566ca7:
  PartGetState((ulong)in_stack_00000028,(SPart *)pSVar2,this_01,aSStack_128);
  fStack_dc = *(float *)(pSVar2 + 0x5c) * fStack_dc;
  local_d8 = *(float *)(pSVar2 + 0x60) * local_d8;
  local_d4 = *(float *)(pSVar2 + 100) * local_d4;
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (local_178,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffe58);
  in_stack_fffffe54 = (GmVec3 *)&uStack_15c;
  in_stack_fffffe50 = (GmVec3 *)local_150;
  unaff_EBP = pGStack_18c;
  in_stack_fffffe58 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCStack_164;
  LightTrailAddPartVerts
            (*(CMotionParticleType **)(this_01 + 0xc),local_174,(GxTexCoord *)local_160,
             (SPart *)pSVar2,local_124,(ulong)pGStack_18c,in_stack_fffffe50,in_stack_fffffe54,
             (GmVec3 *)pCStack_164);
  if (pGVar4 == (GmVec3 *)0x0) {
    pGVar4 = pGStack_18c;
    if (*(int *)(*(int *)(this_01 + 0xc) + 0x24) == 7) {
      pGVar4 = pGStack_18c + -1;
    }
    pvVar7 = (void *)0x0;
    if (pGVar4 != (GmVec3 *)0x0) {
      local_184 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar3 - (int)pGStack_18c);
      do {
        uVar6 = (uint)pvVar7 & 0xffff;
        local_180 = (void *)(uVar3 + uVar6);
        pTVar5 = (TiXmlAttribute *)((uint)local_180 & 0xffff);
        in_stack_fffffe54 = (GmVec3 *)0x566d8d;
        CFastBuffer<unsigned_short>::Add
                  (this_02,(TiXmlAttributeSet *)&stack0xfffffe6c,in_stack_fffffe5c);
        pvVar7 = (void *)((int)pvVar7 + 1);
        local_16c = (CFastBuffer<class_GxVertex> *)((uint)pvVar7 % (uint)local_188);
        pCStack_164 = local_16c + (uVar3 - (int)local_188);
        pGVar4 = (GmVec3 *)((uint)pCStack_164 & 0xffff);
        in_stack_fffffe58 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x566dba;
        CFastBuffer<unsigned_short>::Add
                  (this_02,(TiXmlAttributeSet *)&stack0xfffffe70,in_stack_fffffe60);
        pGStack_18c = (GmVec3 *)((uint)(local_17c + uVar6) & 0xffff);
        in_stack_fffffe5c = (TiXmlAttribute *)0x566dd3;
        CFastBuffer<unsigned_short>::Add(this_02,(TiXmlAttributeSet *)&pGStack_18c,pTVar10);
        local_174 = (CFastBuffer<class_GxVertex> *)((uint)local_174 & 0xffff);
        in_stack_fffffe60 = (TiXmlAttribute *)0x566de8;
        CFastBuffer<unsigned_short>::Add(this_02,(TiXmlAttributeSet *)&local_174,in_stack_fffffe68);
        local_160 = (SCasterCat *)((uint)(local_160 + uVar3) & 0xffff);
        pTVar10 = (TiXmlAttribute *)0x566e01;
        CFastBuffer<unsigned_short>::Add(this_02,(TiXmlAttributeSet *)&local_160,pTVar5);
        local_154 = local_154 & 0xffff;
        in_stack_fffffe68 = (TiXmlAttribute *)0x566e16;
        CFastBuffer<unsigned_short>::Add
                  (this_02,(TiXmlAttributeSet *)&local_154,(TiXmlAttribute *)pGVar4);
        pSVar2 = pSStack_12c;
      } while (pvVar7 < local_178);
    }
    local_17c = local_17c + 1;
    this_01 = local_140;
  }
  in_stack_fffffe68 = *(TiXmlAttribute **)(pSVar2 + 0x88);
  pGVar9 = *(GmVec3 **)(pSVar2 + 0x80);
  pGVar11 = pGVar9;
  pGStack_18c = pGVar4;
  goto joined_r0x00566c78;
}
}

// =================================================
// Function: CMotionManagerParticles::GroupUpdateMultistateWaterSplash
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionManagerParticles::GroupUpdateMultistateWaterSplash
          (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2,
          ulong param_3,GmVec3 *param_4,GmVec3 *param_5,ulong *param_6)
{
{
  int iVar1;
  void *this_00;
  SPartGroup *pSVar2;
  SPartGroup *this_01;
  SCasterCat *pSVar3;
  SLoadedLight *pSVar4;
  SLoadedLight *pSVar5;
  SLoadedLight *pSVar6;
  SLoadedLight *pSVar7;
  TiXmlAttribute *pTVar8;
  GmFrustumIso4 *unaff_EBX;
  CMotionEmitterParticles *unaff_EBP;
  ulong unaff_ESI;
  void *pvVar9;
  ulong unaff_EDI;
  TiXmlAttribute *this_02;
  float10 fVar10;
  undefined4 in_stack_0000001c;
  float *in_stack_00000020;
  float *in_stack_00000024;
  int *in_stack_00000028;
  GmFrustumIso4 *in_stack_fffffef8;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffefc;
  SEmitParams *in_stack_ffffff00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar13;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar15;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar16;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar17;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff1c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar18;
  TiXmlAttribute *in_stack_ffffff20;
  TiXmlAttribute *in_stack_ffffff24;
  TiXmlAttributeSet *in_stack_ffffff28;
  TiXmlAttribute *pTVar19;
  void *pvStack_d0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_cc;
  float local_c8;
  TiXmlAttribute *pTStack_c4;
  SPartGroup *local_c0;
  void *local_bc;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_b8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_b4;
  void *pvStack_b0;
  SPartGroup *local_a8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_a0;
  int iStack_98;
  void *pvStack_94;
  undefined4 uStack_90;
  SCasterCat *local_8c;
  float local_88;
  float local_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  CMotionManagerParticles *local_70;
  float fStack_6c;
  float fStack_68;
  float local_64;
  float local_60;
  float local_5c;
  CMotionManagerParticles *local_58;
  float local_54;
  float fStack_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_3c;
  float local_30;
  float local_24;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  pCVar11 = _DAT_00b59b74;
  pCVar13 = _DAT_00b59b74;
  pCVar14 = _DAT_00b59b74;
  pCVar15 = _DAT_00b59b78;
  pCVar16 = _DAT_00b59b78;
  pCVar17 = _DAT_00b59b78;
  local_70 = this;
  this_01 = (SPartGroup *)
            CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                      (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                       unaff_EDI);
  iVar1 = *(int *)(this_01 + 0x14);
  pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                     ((void *)(iVar1 + 0x5c),(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      unaff_ESI);
  local_c0 = *(SPartGroup **)(pSVar3 + 4);
  this_02 = (TiXmlAttribute *)(iVar1 + 0x78);
  pvVar9 = (void *)(*(int *)(iVar1 + 0x98) + 0x1c);
  pTVar19 = this_02;
  local_bc = pvVar9;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_02,unaff_EBX);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(pvVar9,in_stack_fffffef8);
  local_a0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       ((SCasterCat *)(this_01 + 0x1c),in_stack_fffffefc);
  local_b8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (local_a0 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      local_8c = CFastBuffer<struct_SHmsVPackerObjectPacked>::operator[]
                           (this_01 + 0x1c,local_b8,(ulong)unaff_EBP);
      local_cc = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(local_8c + 0x38);
      local_b8 = (void *)0x0;
      local_c8 = 1.4013e-45;
      pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff;
      pSVar2 = this_01;
      pCVar12 = local_cc;
      if (*(int *)(*(CMotionManagerParticles **)local_8c + 0x8c) == 0) {
joined_r0x005660ec:
        this_01 = pSVar2;
        local_cc = pCVar12;
        if (pCVar12 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
          unaff_EBP = (CMotionEmitterParticles *)pCVar12;
          pSVar3 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                             (this_01,pCVar12,(ulong)in_stack_ffffff00);
          if ((*(float **)pSVar3 <= in_stack_00000024) &&
             (in_stack_00000024 <= *(float **)(pSVar3 + 4))) goto code_r0x00566114;
          if (in_stack_ffffff1c == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
            *(undefined4 *)((int)local_88 + 0x38) = 0xffffffff;
          }
          else {
            unaff_EBP = (CMotionEmitterParticles *)0x566597;
            pCVar18 = in_stack_ffffff1c;
            pSVar3 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                               (this_01,in_stack_ffffff1c,(ulong)pCVar11);
            *(undefined4 *)(pSVar3 + 0x80) = 0xffffffff;
            in_stack_ffffff00 = (SEmitParams *)in_stack_ffffff1c;
            in_stack_ffffff1c = pCVar18;
          }
          while (pCVar12 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
            in_stack_ffffff00 = (SEmitParams *)0x5665bc;
            pSVar3 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                               (this_01,pCVar12,(ulong)pCVar13);
            local_c0 = *(SPartGroup **)(pSVar3 + 0x80);
            *(undefined4 *)(pSVar3 + 0x8c) = 0;
            *(undefined4 *)(pSVar3 + 0x80) = 0xffffffff;
            *(undefined4 *)(pSVar3 + 0x84) = 0xffffffff;
            pCVar11 = pCVar12;
            pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)local_c0;
          }
        }
        goto LAB_005665e0;
      }
      if (local_cc != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
        unaff_EBP = (CMotionEmitterParticles *)&local_54;
        local_c8 = 0.0;
        EmitterGetEmitParamsAsync
                  (local_58,*(CMotionManagerParticles **)local_8c,unaff_EBP,in_stack_ffffff00);
        in_stack_ffffff00 = (SEmitParams *)0x565d6b;
        in_stack_ffffff1c =
             (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this_02,(CFastBuffer<class_CCrystalFace*> *)pCVar11);
        pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x565d76;
        pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem
                           (this_02,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar13)
        ;
        pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x565d7f;
        pSVar5 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem
                           (this_02,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar14)
        ;
        pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x565d88;
        pSVar6 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem
                           (this_02,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar15)
        ;
        pSVar7 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem
                           (this_02,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar16)
        ;
        pSVar2 = local_a8;
        local_64 = local_3c * 0.0;
        local_60 = local_30 * 0.0;
        local_5c = local_24 * 0.0;
        *(float *)pSVar4 = local_18 - local_64;
        *(float *)(pSVar4 + 4) = local_14 - local_60;
        *(float *)(pSVar4 + 8) = local_10 - local_5c;
        *(float *)pSVar5 = local_18 - local_64;
        *(float *)(pSVar5 + 4) = local_14 - local_60;
        *(float *)(pSVar5 + 8) = local_10 - local_5c;
        *(float *)pSVar6 = local_18 + local_64;
        *(float *)(pSVar6 + 4) = local_60 + local_14;
        *(float *)(pSVar6 + 8) = local_5c + local_10;
        *(float *)pSVar7 = local_18 + local_64;
        *(float *)(pSVar7 + 4) = local_60 + local_14;
        *(float *)(pSVar7 + 8) = local_5c + local_10;
        in_stack_00000020 = (float *)param_3;
        in_stack_00000024 = (float *)param_3;
        in_stack_00000028 = (int *)param_3;
        *(ulong *)(pSVar4 + 0x18) = param_3;
        *(ulong *)(pSVar4 + 0x1c) = param_3;
        *(ulong *)(pSVar4 + 0x20) = param_3;
        *(undefined4 *)(pSVar4 + 0x24) = 0x3f800000;
        *(undefined4 *)(pSVar5 + 0x24) = 0x3f800000;
        *(ulong *)(pSVar5 + 0x18) = param_3;
        *(ulong *)(pSVar5 + 0x1c) = param_3;
        *(ulong *)(pSVar5 + 0x20) = param_3;
        *(ulong *)(pSVar6 + 0x18) = param_3;
        *(ulong *)(pSVar6 + 0x1c) = param_3;
        *(ulong *)(pSVar6 + 0x20) = param_3;
        *(undefined4 *)(pSVar6 + 0x24) = 0x3f800000;
        *(undefined4 *)(pSVar7 + 0x24) = 0x3f800000;
        *(ulong *)(pSVar7 + 0x18) = param_3;
        *(ulong *)(pSVar7 + 0x1c) = param_3;
        *(ulong *)(pSVar7 + 0x20) = param_3;
        pCVar16 = local_b4;
        in_stack_ffffff28 = (TiXmlAttributeSet *)param_3;
        local_4c = local_64;
        local_48 = local_60;
        local_44 = local_5c;
        pSVar3 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                           (local_a8,local_b4,(ulong)pCVar17);
        local_8c = (SCasterCat *)(*(float *)(pSVar3 + 0x38) - local_14);
        local_88 = *(float *)(pSVar3 + 0x3c) - local_10;
        local_84 = *(float *)(pSVar3 + 0x40) - local_c;
        pTVar19 = (TiXmlAttribute *)
                  (local_84 * local_84 + local_88 * local_88 + (float)local_8c * (float)local_8c);
        pCVar17 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x565f9f;
        fVar10 = (float10)func_0x009c1b40();
        pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                  ((float)fVar10 * *(float *)(*(int *)(pSVar2 + 0xc) + 0x50) +
                  *(float *)(pSVar3 + 0x90));
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)pvStack_b0 + (int)pCVar16 * 8 + 4)
             = pCVar15;
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
         ((int)pvStack_b0 + (int)pCVar16 * 8 + 0xc) = pCVar15;
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
         ((int)pvStack_b0 + (int)pCVar16 * 8 + 0x14) = pCVar15;
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
         ((int)pvStack_b0 + (int)pCVar16 * 8 + 0x1c) = pCVar15;
        if (*(float *)pSVar4 < (float)in_stack_ffffff1c) {
          in_stack_ffffff1c = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar4;
        }
        if (*(float *)(pSVar4 + 4) < (float)in_stack_ffffff20) {
          in_stack_ffffff20 = *(TiXmlAttribute **)(pSVar4 + 4);
        }
        if (*(float *)(pSVar4 + 8) < (float)in_stack_ffffff24) {
          in_stack_ffffff24 = *(TiXmlAttribute **)(pSVar4 + 8);
        }
        if (*(float *)pSVar7 < (float)in_stack_ffffff1c) {
          in_stack_ffffff1c = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar7;
        }
        if (*(float *)(pSVar7 + 4) < (float)in_stack_ffffff20) {
          in_stack_ffffff20 = *(TiXmlAttribute **)(pSVar7 + 4);
        }
        if (*(float *)(pSVar7 + 8) < (float)in_stack_ffffff24) {
          in_stack_ffffff24 = *(TiXmlAttribute **)(pSVar7 + 8);
        }
        if ((float)in_stack_ffffff28 < *(float *)pSVar4) {
          in_stack_ffffff28 = *(TiXmlAttributeSet **)pSVar4;
        }
        if ((float)pTVar19 < *(float *)(pSVar4 + 4)) {
          pTVar19 = *(TiXmlAttribute **)(pSVar4 + 4);
        }
        if ((float)pvStack_d0 < *(float *)(pSVar4 + 8)) {
          pvStack_d0 = *(void **)(pSVar4 + 8);
        }
        if ((float)in_stack_ffffff28 < *(float *)pSVar7) {
          in_stack_ffffff28 = *(TiXmlAttributeSet **)pSVar7;
        }
        if ((float)pTVar19 < *(float *)(pSVar7 + 4)) {
          pTVar19 = *(TiXmlAttribute **)(pSVar7 + 4);
        }
        this_02 = pTStack_c4;
        pCVar12 = local_cc;
        if ((float)pvStack_d0 < *(float *)(pSVar7 + 8)) {
          pvStack_d0 = *(void **)(pSVar7 + 8);
        }
        goto joined_r0x005660ec;
      }
LAB_005665e0:
      local_c0 = local_c0 + (int)local_bc;
      local_b8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)local_b8 + 1);
    } while (local_b8 < local_a0);
  }
  *in_stack_00000028 = (int)local_c0;
  *in_stack_00000020 = (float)pCVar17;
  in_stack_00000020[1] = (float)in_stack_ffffff1c;
  in_stack_00000020[2] = (float)in_stack_ffffff20;
  *in_stack_00000024 = (float)in_stack_ffffff24;
  in_stack_00000024[1] = (float)in_stack_ffffff28;
  in_stack_00000024[2] = (float)pTVar19;
  return;
code_r0x00566114:
  PartGetState((ulong)in_stack_00000024,(SPart *)pSVar3,this_01,(SPartState *)&fStack_50);
  pvStack_94 = *(void **)(pSVar3 + 0x14);
  uStack_90 = *(undefined4 *)(pSVar3 + 0x20);
  local_8c = *(SCasterCat **)(pSVar3 + 0x2c);
  in_stack_ffffff00 = (SEmitParams *)0x566143;
  pTVar8 = (TiXmlAttribute *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this_02,(CFastBuffer<class_CCrystalFace*> *)pCVar11);
  pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x56614e;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem
                     (this_02,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar13);
  pCVar17 = local_b8;
  pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x56615b;
  pSVar5 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem
                     (local_b8,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar14);
  pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x566164;
  pSVar6 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem
                     (pCVar17,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar15);
  pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x56616f;
  pSVar7 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem
                     (pvStack_b0,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar16);
  param_1 = (CMotionManagerParticles *)
            (((float)_DAT_00b33a58 - *(float *)(pSVar3 + 0x74)) * (float)param_1);
  local_70 = (CMotionManagerParticles *)((float)param_1 * fStack_80);
  fStack_6c = fStack_7c * (float)param_1;
  fStack_68 = fStack_78 * (float)param_1;
  fStack_50 = (float)param_1 * (float)_DAT_00b313b8;
  local_58 = (CMotionManagerParticles *)(fStack_50 * fStack_80);
  local_54 = fStack_7c * fStack_50;
  fStack_50 = fStack_78 * fStack_50;
  *(float *)pSVar4 = *(float *)(pSVar3 + 0x38) - (float)local_70;
  *(float *)(pSVar4 + 4) = *(float *)(pSVar3 + 0x3c) - fStack_6c;
  *(float *)(pSVar4 + 8) = *(float *)(pSVar3 + 0x40) - fStack_68;
  *(float *)pSVar5 = *(float *)(pSVar3 + 0x38) - (float)local_58;
  *(float *)(pSVar5 + 4) = *(float *)(pSVar3 + 0x3c) - local_54;
  *(float *)(pSVar5 + 8) = *(float *)(pSVar3 + 0x40) - fStack_50;
  *(float *)pSVar6 = *(float *)(pSVar3 + 0x38) + (float)local_58;
  *(float *)(pSVar6 + 4) = local_54 + *(float *)(pSVar3 + 0x3c);
  *(float *)(pSVar6 + 8) = fStack_50 + *(float *)(pSVar3 + 0x40);
  *(float *)pSVar7 = *(float *)(pSVar3 + 0x38) + (float)local_70;
  *(float *)(pSVar7 + 4) = fStack_6c + *(float *)(pSVar3 + 0x3c);
  *(float *)(pSVar7 + 8) = fStack_68 + *(float *)(pSVar3 + 0x40);
  *(GmVec3 **)(pSVar4 + 0x18) = param_4;
  *(GmVec3 **)(pSVar4 + 0x1c) = param_5;
  *(ulong **)(pSVar4 + 0x20) = param_6;
  *(undefined4 *)(pSVar4 + 0x24) = in_stack_0000001c;
  *(GmVec3 **)(pSVar5 + 0x18) = param_4;
  *(GmVec3 **)(pSVar5 + 0x1c) = param_5;
  *(ulong **)(pSVar5 + 0x20) = param_6;
  *(undefined4 *)(pSVar5 + 0x24) = in_stack_0000001c;
  *(GmVec3 **)(pSVar6 + 0x18) = param_4;
  *(GmVec3 **)(pSVar6 + 0x1c) = param_5;
  *(ulong **)(pSVar6 + 0x20) = param_6;
  *(undefined4 *)(pSVar6 + 0x24) = in_stack_0000001c;
  *(GmVec3 **)(pSVar7 + 0x18) = param_4;
  *(GmVec3 **)(pSVar7 + 0x1c) = param_5;
  *(ulong **)(pSVar7 + 0x20) = param_6;
  *(undefined4 *)(pSVar7 + 0x24) = in_stack_0000001c;
  pvStack_d0 = (void *)(local_3c * *(float *)(pSVar3 + 0x70) -
                       *(float *)(pSVar3 + 0x58) * (float)_DAT_00b313b8 * local_3c * local_3c);
  if ((float)pvStack_d0 < 0.0) {
    pvStack_d0 = (void *)0x0;
  }
  *(float *)(pSVar4 + 4) = *(float *)(pSVar4 + 4) + (float)pvStack_d0;
  *(float *)(pSVar7 + 4) = (float)pvStack_d0 + *(float *)(pSVar7 + 4);
  pTVar19 = *(TiXmlAttribute **)(pSVar3 + 0x90);
  *(TiXmlAttribute **)(iStack_98 + 4 + (int)in_stack_ffffff28 * 8) = pTVar19;
  *(TiXmlAttribute **)(iStack_98 + 0xc + (int)in_stack_ffffff28 * 8) = pTVar19;
  *(TiXmlAttribute **)(iStack_98 + 0x14 + (int)in_stack_ffffff28 * 8) = pTVar19;
  *(TiXmlAttribute **)(iStack_98 + 0x1c + (int)in_stack_ffffff28 * 8) = pTVar19;
  if (*(float *)pSVar4 < (float)local_cc) {
    local_cc = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar4;
  }
  if (*(float *)(pSVar4 + 4) < local_c8) {
    local_c8 = *(float *)(pSVar4 + 4);
  }
  if (*(float *)(pSVar4 + 8) < (float)pTStack_c4) {
    pTStack_c4 = *(TiXmlAttribute **)(pSVar4 + 8);
  }
  if (*(float *)pSVar7 < (float)local_cc) {
    local_cc = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar7;
  }
  if (*(float *)(pSVar7 + 4) < local_c8) {
    local_c8 = *(float *)(pSVar7 + 4);
  }
  if (*(float *)(pSVar7 + 8) < (float)pTStack_c4) {
    pTStack_c4 = *(TiXmlAttribute **)(pSVar7 + 8);
  }
  if ((float)local_c0 < *(float *)pSVar4) {
    local_c0 = *(SPartGroup **)pSVar4;
  }
  if ((float)local_bc < *(float *)(pSVar4 + 4)) {
    local_bc = *(void **)(pSVar4 + 4);
  }
  if ((float)local_b8 < *(float *)(pSVar4 + 8)) {
    local_b8 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar4 + 8);
  }
  if ((float)local_c0 < *(float *)pSVar7) {
    local_c0 = *(SPartGroup **)pSVar7;
  }
  if ((float)local_bc < *(float *)(pSVar7 + 4)) {
    local_bc = *(void **)(pSVar7 + 4);
  }
  if ((float)local_b8 < *(float *)(pSVar7 + 8)) {
    local_b8 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar7 + 8);
  }
  if (pvStack_b0 == (void *)0x0) {
    pvVar9 = (void *)((uint)in_stack_ffffff28 & 0xffff);
    pvStack_b0 = (void *)0x3;
    pvStack_d0 = pvVar9;
    do {
      this_00 = pvStack_94;
      pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x5664e0;
      CFastBuffer<unsigned_short>::Add(pvStack_94,(TiXmlAttributeSet *)&pvStack_d0,pTVar8);
      pvStack_d0 = (void *)((int)pvVar9 - 4U & 0xffff);
      pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x5664f6;
      CFastBuffer<unsigned_short>::Add
                (this_00,(TiXmlAttributeSet *)&pvStack_d0,(TiXmlAttribute *)in_stack_ffffff1c);
      local_cc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)pvVar9 - 3U & 0xffff);
      pTVar8 = (TiXmlAttribute *)0x56650c;
      CFastBuffer<unsigned_short>::Add(this_00,(TiXmlAttributeSet *)&local_cc,in_stack_ffffff20);
      in_stack_ffffff1c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x566518;
      CFastBuffer<unsigned_short>::Add(this_00,(TiXmlAttributeSet *)&pTStack_c4,in_stack_ffffff24);
      pTStack_c4 = (TiXmlAttribute *)((int)pvVar9 - 3U & 0xffff);
      in_stack_ffffff20 = (TiXmlAttribute *)0x56652b;
      CFastBuffer<unsigned_short>::Add
                (this_00,(TiXmlAttributeSet *)&pTStack_c4,(TiXmlAttribute *)in_stack_ffffff28);
      local_c0 = (SPartGroup *)((int)pvVar9 + 1U & 0xffff);
      in_stack_ffffff28 = (TiXmlAttributeSet *)&local_c0;
      in_stack_ffffff24 = (TiXmlAttribute *)0x566541;
      CFastBuffer<unsigned_short>::Add(this_00,in_stack_ffffff28,pTVar19);
      iStack_98 = iStack_98 + -1;
      pvVar9 = (void *)((int)pvVar9 + 1U & 0xffff);
      local_b8 = pvVar9;
    } while (iStack_98 != 0);
    local_88 = (float)((int)local_88 + 1);
  }
  local_c8 = *(float *)(pSVar3 + 0x88);
  pSVar2 = local_c0;
  this_02 = pTStack_c4;
  unaff_EBP = (CMotionEmitterParticles *)this_01;
  pCVar17 = local_cc;
  pCVar12 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar3 + 0x80);
  goto joined_r0x005660ec;
}
}

// =================================================
// Function: CMotionManagerParticles::GroupUpdateParticles
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CMotionManagerParticles::GroupUpdateParticles
          (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2,
          ulong param_3)
{
{
  int iVar1;
  int iVar2;
  CPlugVisualSprite *this_00;
  SCasterCat *this_01;
  SCasterCat *pSVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  GmVec3 *unaff_EBP;
  GmFrustumIso4 *unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  ulong in_stack_00000014;
  SPartGroup *pSVar5;
  CMotionManagerParticles *pCVar6;
  ulong uVar7;
  undefined4 local_78;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c [11];
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_18;
  GmVec3 *pGStack_14;
  GxColor *pGStack_10;
  undefined1 local_c [12];
  
  pCVar6 = param_1;
  this_01 = CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                      (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                       unaff_EDI);
  local_64 = _DAT_00b59b74;
  local_60 = _DAT_00b59b74;
  local_78 = 0;
  local_5c[0] = _DAT_00b59b74;
  local_70 = _DAT_00b59b78;
  local_6c = _DAT_00b59b78;
  local_68 = _DAT_00b59b78;
  iVar1 = *(int *)(this_01 + 0xc);
  iVar2 = *(int *)(iVar1 + 0x14);
  if (iVar2 == 0) {
    switch(*(undefined4 *)(iVar1 + 0x20)) {
    case 0:
      GroupUpdateStandardQuadCamera
                (this,param_1,param_3,(ulong)&local_64,(GmVec3 *)&local_70,(GmVec3 *)&local_78,
                 (ulong *)unaff_ESI);
      break;
    case 1:
      GroupUpdateStandardWaterSplash
                (this,param_1,param_3,(ulong)&local_64,(GmVec3 *)&local_70,(GmVec3 *)&local_78,
                 (ulong *)unaff_ESI);
      break;
    case 2:
      GroupUpdateStandardQuadSpeed
                (this,param_1,param_3,(ulong)&local_64,(GmVec3 *)&local_70,(GmVec3 *)&local_78,
                 (ulong *)unaff_ESI);
      break;
    case 3:
      GroupUpdateStandardLinesSpeedCamera
                (this,param_1,param_3,(ulong)&local_64,(GmVec3 *)&local_70,(GmVec3 *)&local_78,
                 (ulong *)unaff_ESI);
    }
  }
  else if (iVar2 == 2) {
    this_00 = *(CPlugVisualSprite **)(this_01 + 0x14);
    *(undefined4 *)(this_00 + 0xa4) = *(undefined4 *)(iVar1 + 0x5c);
    *(undefined4 *)(this_00 + 0xa8) = *(undefined4 *)(iVar1 + 0x60);
    uVar7 = 0x56829d;
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_00 + 0x78,unaff_ESI);
    local_70 = (float)CFastBuffer<class_CCrystalFace*>::GetCount(this_01,unaff_EBX);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (local_70 != 0.0) {
      do {
        pSVar5 = (SPartGroup *)local_5c;
        pSVar3 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                           (this_01,pCVar4,(ulong)this_01);
        PartGetState(in_stack_00000014,(SPart *)pSVar3,pSVar5,(SPartState *)pCVar6);
        if (fStack_30 < local_64) {
          local_64 = fStack_30;
        }
        if (fStack_2c < local_60) {
          local_60 = fStack_2c;
        }
        if (fStack_28 < local_5c[0]) {
          local_5c[0] = fStack_28;
        }
        if (local_70 < fStack_30) {
          local_70 = fStack_30;
        }
        if (local_6c < fStack_2c) {
          local_6c = fStack_2c;
        }
        if (local_68 < fStack_28) {
          local_68 = fStack_28;
        }
        pCVar6 = (CMotionManagerParticles *)0x0;
        pCStack_74 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     (fStack_18 / (float)pGStack_14);
        CPlugVisualSprite::AddSprite
                  (this_00,(CPlugVisualSprite *)&fStack_30,pGStack_14,(float)local_c,pGStack_10,
                   (float)pCStack_74,0.0,uVar7);
        pCVar4 = pCVar4 + 1;
        unaff_EBX = (CFastBuffer<class_CCrystalFace*> *)unaff_EBP;
      } while (pCVar4 < pCStack_74);
    }
  }
  else if (iVar2 == 1) {
    if (*(int *)(iVar1 + 0x24) == 5) {
      GroupUpdateMultistateWaterSplash
                (this,param_1,param_3,(ulong)&local_64,(GmVec3 *)&local_70,(GmVec3 *)&local_78,
                 (ulong *)unaff_ESI);
    }
    else if (*(int *)(iVar1 + 0x24) - 6U < 2) {
      GroupUpdateMultistateLightTrail
                (this,param_1,param_3,(ulong)&local_64,(GmVec3 *)&local_70,(GmVec3 *)&local_78,
                 (ulong *)unaff_ESI);
    }
    else {
      GroupUpdateMultiState
                (this,param_1,param_3,(ulong)&local_64,(GmVec3 *)&local_70,(GmVec3 *)&local_78,
                 (ulong *)unaff_ESI);
    }
  }
  CPlugVisual::SetBoundingMinMax
            (*(CPlugVisual **)(this_01 + 0x14),(CPlugVisual *)&local_60,(GmVec3 *)&local_6c,
             (GmVec3 *)unaff_EBX);
  iVar1 = *(int *)(this_01 + 0x10);
  iVar2 = *(int *)(this_01 + 0x14);
  *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar2 + 0x34);
  *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(iVar2 + 0x38);
  *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(iVar2 + 0x3c);
  *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar2 + 0x40);
  *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(iVar2 + 0x44);
  *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(iVar2 + 0x48);
  *(uint *)(iVar1 + 0x9c) =
       *(uint *)(iVar1 + 0x9c) ^ ((uint)(local_70 != 0.0) * 8 ^ *(uint *)(iVar1 + 0x9c)) & 8;
  return *(uint *)(*(int *)(this_01 + 0x10) + 0x9c) >> 3 & 1;
}
}

// =================================================
// Function: CMotionManagerParticles::GroupUpdateStandardLinesSpeedCamera
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionManagerParticles::GroupUpdateStandardLinesSpeedCamera
          (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2,
          ulong param_3,GmVec3 *param_4,GmVec3 *param_5,ulong *param_6)
{
{
  float fVar1;
  CPlugVisualIndexedLines *this_00;
  float fVar2;
  SCasterCat *this_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  int iVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  GmFrustumIso4 *unaff_EBP;
  GmFrustumIso4 *unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  float *in_stack_0000001c;
  float *in_stack_00000020;
  float *in_stack_00000024;
  SPartState *pSVar7;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_54;
  float local_50;
  float local_4c;
  SPartState local_48 [40];
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  fVar2 = _DAT_00b59b78;
  local_74 = _DAT_00b59b78;
  pSVar7 = _DAT_00b59b74;
  this_01 = CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                      (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                       unaff_EDI);
  this_00 = *(CPlugVisualIndexedLines **)(this_01 + 0x14);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_00 + 0x78,unaff_ESI);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
            ((void *)(*(int *)(this_00 + 0x98) + 0x1c),unaff_EBP);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  local_60 = 0.0;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_01,unaff_EBX);
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                         (this_01,pCVar6,(ulong)pSVar7);
      pSVar7 = local_48;
      iVar5 = PartGetState((ulong)in_stack_0000001c,(SPart *)pSVar4,(SPartGroup *)this_01,pSVar7);
      if (iVar5 != 0) {
        if (local_20 < local_74) {
          local_74 = local_20;
        }
        if (local_1c < local_70) {
          local_70 = local_1c;
        }
        if (local_18 < local_6c) {
          local_6c = local_18;
        }
        if (local_68 < local_20) {
          local_68 = local_20;
        }
        if (local_64 < local_1c) {
          local_64 = local_1c;
        }
        if (local_60 < local_18) {
          local_60 = local_18;
        }
        fVar1 = *(float *)(*(int *)(this_01 + 0xc) + 0xe0);
        local_54 = fVar1 * local_14 + local_20;
        local_50 = local_1c + local_10 * fVar1;
        local_4c = local_18 + fVar1 * local_c;
        local_5c = local_8 * (float)_DAT_00b313b8;
        pSVar7 = (SPartState *)0x3f800000;
        CPlugVisualIndexedLines::AddNewLine
                  (this_00,(CPlugVisualIndexedLines *)&local_54,(ushort)&local_20,(GmVec3 *)&param_1
                   ,(GxColor *)&param_1,local_5c,local_5c);
        local_60 = (float)((int)local_60 + 1);
      }
      pCVar6 = pCVar6 + 1;
    } while (pCVar6 < pCVar3);
  }
  *in_stack_00000024 = local_5c;
  *in_stack_0000001c = fVar2;
  in_stack_0000001c[1] = local_74;
  in_stack_0000001c[2] = local_70;
  *in_stack_00000020 = local_6c;
  in_stack_00000020[1] = local_68;
  in_stack_00000020[2] = local_64;
  return;
}
}

// =================================================
// Function: CMotionManagerParticles::GroupUpdateStandardQuadCamera
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionManagerParticles::GroupUpdateStandardQuadCamera
          (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2,
          ulong param_3,GmVec3 *param_4,GmVec3 *param_5,ulong *param_6)
{
{
  CPlugVisualSprite *this_00;
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  SCasterCat *this_01;
  SCasterCat *pSVar4;
  int iVar5;
  SPartState *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  GmFrustumIso4 *unaff_ESI;
  ulong unaff_EDI;
  float *in_stack_0000001c;
  undefined4 *in_stack_00000020;
  ulong in_stack_ffffff80;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_6c;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  SPartState local_4c [40];
  float local_24;
  float local_20;
  float local_1c;
  float local_c;
  GmVec3 *local_8;
  GxColor *local_4;
  
  fVar3 = _DAT_00b59b78;
  uVar2 = _DAT_00b59b74;
  local_64 = _DAT_00b59b78;
  local_60 = _DAT_00b59b78;
  this_01 = CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                      (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                       unaff_EDI);
  iVar5 = *(int *)(this_01 + 0xc);
  this_00 = *(CPlugVisualSprite **)(this_01 + 0x14);
  *(undefined4 *)(this_00 + 0xa4) = *(undefined4 *)(iVar5 + 0x5c);
  *(undefined4 *)(this_00 + 0xa8) = *(undefined4 *)(iVar5 + 0x60);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_00 + 0x78,unaff_ESI);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  local_6c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_01,unaff_EBP);
  if (local_6c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                         (this_01,pCVar6,(ulong)unaff_EBX);
      unaff_EBX = local_4c;
      iVar5 = PartGetState((ulong)param_6,(SPart *)pSVar4,(SPartGroup *)this_01,unaff_EBX);
      if (iVar5 != 0) {
        if (local_24 < local_64) {
          local_64 = local_24;
        }
        if (local_20 < local_60) {
          local_60 = local_20;
        }
        if (local_1c < local_5c) {
          local_5c = local_1c;
        }
        if (local_58 < local_24) {
          local_58 = local_24;
        }
        if (local_54 < local_20) {
          local_54 = local_20;
        }
        if (local_50 < local_1c) {
          local_50 = local_1c;
        }
        unaff_EBX = *(SPartState **)(pSVar4 + 0x7c);
        fVar1 = local_c / (float)local_8;
        CPlugVisualSprite::AddSprite
                  (this_00,(CPlugVisualSprite *)&local_24,local_8,(float)&stack0x00000000,local_4,
                   fVar1,(float)unaff_EBX,in_stack_ffffff80);
        local_6c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)fVar1 + 1);
      }
      pCVar6 = pCVar6 + 1;
    } while (pCVar6 < local_6c);
  }
  *in_stack_00000020 = uVar2;
  *param_6 = (ulong)fVar3;
  param_6[1] = (ulong)local_64;
  param_6[2] = (ulong)local_60;
  *in_stack_0000001c = local_5c;
  in_stack_0000001c[1] = local_58;
  in_stack_0000001c[2] = local_54;
  return;
}
}

// =================================================
// Function: CMotionManagerParticles::GroupUpdateStandardQuadSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionManagerParticles::GroupUpdateStandardQuadSpeed
          (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2,
          ulong param_3,GmVec3 *param_4,GmVec3 *param_5,ulong *param_6)
{
{
  void *this_00;
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  SCasterCat *pSVar6;
  float fVar7;
  float fVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  SPartGroup *this_01;
  SCasterCat *pSVar10;
  int iVar11;
  ulong uVar12;
  SLoadedLight *pSVar13;
  ulong unaff_EBX;
  undefined4 unaff_EBP;
  GmFrustumIso4 *unaff_ESI;
  ulong unaff_EDI;
  float10 fVar14;
  undefined4 unaff_retaddr;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar15;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar16;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffff34;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar17;
  SPartState *in_stack_ffffff38;
  float fStack_c0;
  float fStack_bc;
  SCasterCat *local_b8;
  float local_a4;
  float local_a0;
  SCasterCat *local_98;
  SCasterCat *local_94;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_90;
  int local_8c;
  SCasterCat *local_88;
  SCasterCat *local_84;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_80;
  SPartGroup *local_7c;
  float fStack_68;
  float local_64;
  float local_60;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_5c;
  SPartState local_54 [4];
  float local_50;
  float local_44;
  undefined4 uStack_3c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_38;
  float fStack_34;
  float fStack_30;
  SCasterCat *local_2c;
  SCasterCat *local_28;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  pSVar6 = _DAT_00b59b74;
  local_98 = _DAT_00b59b74;
  local_94 = _DAT_00b59b74;
  local_a4 = _DAT_00b59b78;
  this_01 = (SPartGroup *)
            CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                      (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                       unaff_EDI);
  iVar1 = *(int *)(this_01 + 0x14);
  this_00 = (void *)(iVar1 + 0x78);
  local_88 = (SCasterCat *)this_01;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_00,unaff_ESI);
  pSVar10 = CFastBuffer<struct_SFastCat>::operator[]
                      ((void *)(iVar1 + 0x5c),(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                       unaff_EBX);
  iVar1 = *(int *)(pSVar10 + 4);
  local_84 = (SCasterCat *)0x0;
  local_5c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_01,in_stack_ffffff34);
  local_90 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (local_5c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      local_b8 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                           (this_01,local_90,(ulong)in_stack_ffffff38);
      in_stack_ffffff38 = local_54;
      pCVar15 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x566fc2;
      pCVar16 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)param_2;
      pSVar10 = local_b8;
      iVar11 = PartGetState(param_2,(SPart *)local_b8,this_01,in_stack_ffffff38);
      pCVar9 = local_38;
      fVar8 = local_44;
      fVar7 = local_50;
      if (iVar11 != 0) {
        local_64 = local_50;
        local_60 = local_44;
        local_5c = local_38;
        if ((float)local_2c < (float)local_88) {
          local_88 = local_2c;
        }
        if ((float)local_28 < (float)local_84) {
          local_84 = local_28;
        }
        if ((float)local_24 < (float)local_80) {
          local_80 = local_24;
        }
        if ((float)local_98 < (float)local_2c) {
          local_98 = local_2c;
        }
        if ((float)local_94 < (float)local_28) {
          local_94 = local_28;
        }
        if ((float)local_90 < (float)local_24) {
          local_90 = local_24;
        }
        if (local_18 * local_18 + local_20 * local_20 + local_1c * local_1c <= _DAT_00cdeb20) {
          local_a4 = 0.0;
          local_a0 = 0.0;
          fVar2 = 1.0;
        }
        else {
          fVar14 = (float10)func_0x009c1b40();
          fVar2 = 1.0 / (float)fVar14;
          fStack_bc = fVar2 * (float)local_38;
          local_b8 = (SCasterCat *)(fStack_34 * fVar2);
          fVar2 = fVar2 * fStack_30;
        }
        pCVar17 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
                  ((float)local_2c * (float)_DAT_00b313b8);
        in_stack_ffffff38 = (SPartState *)((float)pCVar17 * fStack_68);
        fVar3 = (float)pCVar17 * fStack_c0;
        fVar4 = (float)local_28 * fStack_bc;
        fVar5 = (float)local_b8 * (float)local_28;
        fVar2 = (float)local_28 * fVar2;
        uVar12 = CFastBuffer<class_CCrystalFace*>::GetCount
                           (this_00,(CFastBuffer<class_CCrystalFace*> *)param_1);
        if (*(ulong *)(pCVar17 + 0x7c) != 0xffffffff) {
          GetUvsFromAtlas(*(ulong *)(*(int *)(local_8c + 0xc) + 0x44),
                          *(ulong *)(*(int *)(local_8c + 0xc) + 0x48),*(ulong *)(pCVar17 + 0x7c),
                          (GmVec2 *)&local_80,(GmVec2 *)&local_88);
          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + uVar12 * 8) = local_80;
          *(SCasterCat **)(iVar1 + 4 + uVar12 * 8) = local_84;
          *(SCasterCat **)(iVar1 + 8 + uVar12 * 8) = local_88;
          *(SCasterCat **)(iVar1 + 0xc + uVar12 * 8) = local_84;
          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x10 + uVar12 * 8) = local_80
          ;
          *(SPartGroup **)(iVar1 + 0x14 + uVar12 * 8) = local_7c;
          *(SCasterCat **)(iVar1 + 0x18 + uVar12 * 8) = local_88;
          *(SPartGroup **)(iVar1 + 0x1c + uVar12 * 8) = local_7c;
        }
        param_1 = (CMotionManagerParticles *)0x5671ef;
        pSVar13 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem(this_00,pCVar15);
        *(undefined4 *)pSVar13 = uStack_3c;
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar13 + 4) = local_38;
        *(float *)(pSVar13 + 8) = fStack_34;
        *(float *)pSVar13 = *(float *)pSVar13 + fVar3;
        *(float *)(pSVar13 + 4) = *(float *)(pSVar13 + 4) + fVar4;
        *(float *)(pSVar13 + 8) = *(float *)(pSVar13 + 8) + fVar5;
        *(float *)(pSVar13 + 0x18) = local_18;
        *(undefined4 *)(pSVar13 + 0x1c) = local_14;
        *(undefined4 *)(pSVar13 + 0x20) = uStack_10;
        *(undefined4 *)(pSVar13 + 0x24) = uStack_c;
        pSVar13 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem(this_00,pCVar16);
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar13 = local_38;
        *(float *)(pSVar13 + 4) = fStack_34;
        *(float *)(pSVar13 + 8) = fStack_30;
        *(float *)pSVar13 = *(float *)pSVar13 - fVar4;
        *(float *)(pSVar13 + 4) = *(float *)(pSVar13 + 4) - fVar5;
        *(float *)(pSVar13 + 8) = *(float *)(pSVar13 + 8) - fVar2;
        *(undefined4 *)(pSVar13 + 0x18) = local_14;
        *(undefined4 *)(pSVar13 + 0x1c) = uStack_10;
        *(undefined4 *)(pSVar13 + 0x20) = uStack_c;
        *(undefined4 *)(pSVar13 + 0x24) = uStack_8;
        pSVar13 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem
                            (this_00,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pSVar10
                            );
        *(float *)pSVar13 = fStack_34;
        *(float *)(pSVar13 + 4) = fStack_30;
        *(SCasterCat **)(pSVar13 + 8) = local_2c;
        *(float *)pSVar13 = *(float *)pSVar13 + fVar5 + fVar8;
        *(float *)(pSVar13 + 4) = *(float *)(pSVar13 + 4) + fVar2 + (float)pCVar9;
        fStack_c0 = *(float *)(pSVar13 + 8) + fVar7;
        *(float *)(pSVar13 + 8) = fStack_c0 + local_a4;
        *(undefined4 *)(pSVar13 + 0x18) = uStack_10;
        *(undefined4 *)(pSVar13 + 0x1c) = uStack_c;
        *(undefined4 *)(pSVar13 + 0x20) = uStack_8;
        *(undefined4 *)(pSVar13 + 0x24) = unaff_EBP;
        pSVar13 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem(this_00,pCVar17);
        local_80 = local_80 + 1;
        *(float *)pSVar13 = fStack_30;
        *(SCasterCat **)(pSVar13 + 4) = local_2c;
        *(SCasterCat **)(pSVar13 + 8) = local_28;
        *(float *)pSVar13 = (*(float *)pSVar13 - fVar2) + (float)pCVar9;
        *(float *)(pSVar13 + 4) = (*(float *)(pSVar13 + 4) - fVar7) + local_a4;
        fStack_bc = *(float *)(pSVar13 + 8) - fVar8;
        *(float *)(pSVar13 + 8) = fStack_bc + local_a0;
        *(undefined4 *)(pSVar13 + 0x18) = uStack_c;
        *(undefined4 *)(pSVar13 + 0x1c) = uStack_8;
        *(undefined4 *)(pSVar13 + 0x20) = unaff_EBP;
        *(undefined4 *)(pSVar13 + 0x24) = unaff_retaddr;
        this_01 = local_7c;
      }
      local_90 = local_90 + 1;
    } while (local_90 < local_5c);
  }
  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_5 = local_80;
  *(int *)param_3 = local_8c;
  *(SCasterCat **)(param_3 + 4) = local_88;
  *(SCasterCat **)(param_3 + 8) = local_84;
  *(SCasterCat **)param_4 = pSVar6;
  *(SCasterCat **)(param_4 + 4) = local_98;
  *(SCasterCat **)(param_4 + 8) = local_94;
  return;
}
}

// =================================================
// Function: CMotionManagerParticles::GroupUpdateStandardWaterSplash
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionManagerParticles::GroupUpdateStandardWaterSplash
          (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2,
          ulong param_3,GmVec3 *param_4,GmVec3 *param_5,ulong *param_6)
{
{
  SCasterCat *pSVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SPartGroup *this_00;
  SCasterCat *pSVar6;
  int iVar7;
  ulong uVar8;
  SLoadedLight *pSVar9;
  GmFrustumIso4 *unaff_EBX;
  ulong unaff_ESI;
  void *pvVar10;
  ulong unaff_EDI;
  uint uVar11;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  double dVar12;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffe74;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar13;
  TiXmlAttribute *pTVar14;
  TiXmlAttribute *pTVar15;
  TiXmlAttribute *pTVar16;
  TiXmlAttribute *pTVar17;
  GmFrustumIso4 *in_stack_fffffe8c;
  TiXmlAttributeSet *pTVar18;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffe90;
  SPartGroup *pSVar19;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffe94;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffe98;
  void *pvStack_150;
  SCasterCat *pSStack_148;
  float fStack_144;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  void *pvStack_134;
  void *pvStack_130;
  int local_12c;
  float local_128;
  uint local_124;
  SCasterCat *local_120;
  SCasterCat *local_11c;
  SCasterCat *local_118;
  ulong local_114;
  SCasterCat *local_110;
  SCasterCat *local_10c;
  SCasterCat *local_108;
  int local_104;
  SCasterCat *local_100;
  void *local_fc;
  void *local_f8;
  void *local_f4;
  void *local_f0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_ec;
  void *pvStack_e8;
  CMotionManagerParticles *local_e4;
  float local_e0;
  CMotionManagerParticles *local_cc;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_c8;
  void *local_c4;
  CMotionManagerParticles *local_c0;
  float local_bc;
  void *local_b8;
  void *pvStack_b4;
  void *apvStack_b0 [2];
  float fStack_a8;
  void *pvStack_a0;
  void *local_98;
  SPartState local_88 [32];
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  
  local_fc = _DAT_00b59b74;
  local_f8 = _DAT_00b59b74;
  local_f4 = _DAT_00b59b74;
  local_110 = _DAT_00b59b78;
  local_10c = _DAT_00b59b78;
  local_108 = _DAT_00b59b78;
  pCVar13 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x56747c;
  local_e4 = this;
  this_00 = (SPartGroup *)
            CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                      (this + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                       unaff_EDI);
  iVar7 = *(int *)(this_00 + 0x14);
  pTVar15 = (TiXmlAttribute *)0x0;
  pTVar14 = (TiXmlAttribute *)0x567490;
  local_11c = (SCasterCat *)this_00;
  pSVar6 = CFastBuffer<struct_SFastCat>::operator[]
                     ((void *)(iVar7 + 0x5c),(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      unaff_ESI);
  local_e0 = *(float *)(pSVar6 + 4);
  local_120 = (SCasterCat *)(iVar7 + 0x78);
  pvVar10 = (void *)(*(int *)(iVar7 + 0x98) + 0x1c);
  local_b8 = pvVar10;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(local_120,unaff_EBX);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(pvVar10,in_stack_fffffe8c);
  local_108 = (SCasterCat *)0x0;
  local_c8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,in_stack_fffffe90);
  local_ec = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (local_c8 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pCVar5 = local_ec;
      local_f0 = _DAT_00b59b74;
      local_100 = _DAT_00b59b78;
      local_118 = _DAT_00b59b78;
      pSVar6 = CFastBuffer<struct_CMotionManagerParticles::SPart>::operator[]
                         (this_00,local_ec,(ulong)in_stack_fffffe94);
      pTVar16 = (TiXmlAttribute *)0x567518;
      pTVar17 = (TiXmlAttribute *)param_2;
      pTVar18 = (TiXmlAttributeSet *)pSVar6;
      pSVar19 = this_00;
      iVar7 = PartGetState(param_2,(SPart *)pSVar6,this_00,local_88);
      if (iVar7 == 0) {
        in_stack_fffffe94 = pCVar5;
        GroupKillParticle(local_cc,param_1,(ulong)pCVar5,(ulong)in_stack_fffffe98);
        local_ec = pCVar5;
      }
      else {
        in_stack_fffffe94 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x56753e;
        local_114 = CFastBuffer<class_CCrystalFace*>::GetCount(local_110,in_stack_fffffe98);
        pSStack_148 = (SCasterCat *)0x0;
        local_100 = (SCasterCat *)0x0;
        do {
          pSVar1 = pSStack_148 + 1;
          fVar3 = (float)(int)pSVar1;
          if ((int)pSVar1 < 0) {
            fVar3 = fVar3 + _DAT_00c418d0;
          }
          fStack_13c = (float)_DAT_00b313b8;
          uVar11 = 0;
          local_f0 = (void *)(fVar3 * fStack_13c);
          local_e4 = (CMotionManagerParticles *)(float)(int)pSStack_148;
          if ((int)pSStack_148 < 0) {
            local_e4 = (CMotionManagerParticles *)((float)local_e4 + _DAT_00c418d0);
          }
          fStack_13c = (float)local_f0 * fStack_13c + fStack_13c;
          pSStack_148 = pSVar1;
          do {
            fVar3 = (float)(int)uVar11;
            if ((int)uVar11 < 0) {
              fVar3 = fVar3 + _DAT_00c418d0;
            }
            local_fc = (void *)(fVar3 / (float)_DAT_00b40f28);
            fStack_140 = (float)uVar11;
            __CIsin();
            fVar3 = (float)extraout_ST0;
            fStack_140 = fVar3;
            __CIcos();
            pvStack_130 = (void *)(float)extraout_ST0_00;
            uVar8 = CFastBuffer<class_CCrystalFace*>::GetCount(pvStack_134,in_stack_fffffe74);
            pSStack_148 = (SCasterCat *)
                          ((fStack_a8 * *(float *)(pSVar6 + 0x70) -
                           *(float *)(pSVar6 + 0x58) * (float)_DAT_00b313b8 * fStack_a8 * fStack_a8)
                          * (float)pvStack_e8);
            if ((float)pSStack_148 < 0.0) {
              pSStack_148 = (SCasterCat *)0x0;
            }
            if (local_124 == 0) {
              pvStack_150 = *(void **)(pSVar6 + 0x50);
            }
            else {
              dVar12 = _modf((double)(*(float *)(pSVar6 + 0x6c) + (float)local_f8),
                             (double *)apvStack_b0);
              local_c4 = (void *)0x0;
              local_c0 = (CMotionManagerParticles *)0x3f800000;
              fVar4 = (float)(&local_c4)[-((int)(float)dVar12 >> 0x1f)] + (float)dVar12;
              fStack_144 = fVar4 * (float)_DAT_00b59bb8;
              __CIsin();
              fStack_144 = (float)extraout_ST0_01 * fVar4 + (float)_DAT_00b2c188;
              pvStack_150 = (void *)(fStack_68 * (float)local_f4 * fStack_144 +
                                    *(float *)(pSVar6 + 0x50));
            }
            if ((float)pvStack_134 < (float)pvStack_150) {
              pvStack_134 = pvStack_150;
            }
            if ((float)local_11c < (float)pSStack_148) {
              local_11c = pSStack_148;
            }
            if ((float)pSStack_148 < (float)local_10c) {
              local_10c = pSStack_148;
            }
            in_stack_fffffe74 = (CFastBuffer<class_CCrystalFace*> *)0x56775b;
            pSVar9 = CFastBuffer<struct_CPlugVisual::SSplit>::AddNewElem(pvStack_130,pCVar13);
            local_128 = fVar3 * local_128;
            uVar11 = uVar11 + 1;
            *(float *)pSVar9 = local_128;
            *(float *)(pSVar9 + 4) = fStack_144;
            fStack_138 = fStack_138 * fVar3;
            *(float *)(pSVar9 + 8) = fStack_138;
            *(float *)pSVar9 = *(float *)(pSVar6 + 0x38) + local_128;
            *(float *)(pSVar9 + 4) = *(float *)(pSVar6 + 0x3c) + fStack_144;
            *(float *)(pSVar9 + 8) = fStack_138 + *(float *)(pSVar6 + 0x40);
            *(undefined4 *)(pSVar9 + 0x18) = uStack_58;
            *(undefined4 *)(pSVar9 + 0x1c) = uStack_54;
            *(undefined4 *)(pSVar9 + 0x20) = uStack_50;
            *(undefined4 *)(pSVar9 + 0x24) = uStack_4c;
            *(float *)(local_ec + uVar8 * 8) = fStack_13c;
            *(float *)(local_ec + uVar8 * 8 + 4) =
                 *(float *)(*(int *)(local_124 + 0xc) + 0x54) * (float)local_f4;
          } while (uVar11 < 10);
          local_120 = pSStack_148;
        } while (pSStack_148 < (SCasterCat *)0x2);
        uVar11 = 0;
        do {
          pvVar10 = local_c4;
          fStack_13c = (float)(uVar11 + 1);
          uVar2 = (uint)fStack_13c % 10 + (int)pvStack_134;
          pSStack_148 = (SCasterCat *)(uVar2 & 0xffff);
          in_stack_fffffe74 = (CFastBuffer<class_CCrystalFace*> *)0x567841;
          CFastBuffer<unsigned_short>::Add(local_c4,(TiXmlAttributeSet *)&pSStack_148,pTVar14);
          fStack_144 = (float)((int)pvStack_130 + (uVar11 & 0xffff) & 0xffff);
          pCVar13 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x56785d;
          CFastBuffer<unsigned_short>::Add(pvVar10,(TiXmlAttributeSet *)&fStack_144,pTVar15);
          uVar11 = local_12c + 10 + (uVar11 & 0xffff);
          fStack_140 = (float)(uVar11 & 0xffff);
          pTVar14 = (TiXmlAttribute *)0x567878;
          CFastBuffer<unsigned_short>::Add(pvVar10,(TiXmlAttributeSet *)&fStack_140,pTVar16);
          fStack_13c = (float)(uVar2 & 0xffff);
          pTVar15 = (TiXmlAttribute *)0x56788b;
          CFastBuffer<unsigned_short>::Add(pvVar10,(TiXmlAttributeSet *)&fStack_13c,pTVar17);
          fStack_138 = (float)(uVar11 & 0xffff);
          pTVar16 = (TiXmlAttribute *)0x56789e;
          CFastBuffer<unsigned_short>::Add
                    (pvVar10,(TiXmlAttributeSet *)&fStack_138,(TiXmlAttribute *)pTVar18);
          pvStack_134 = (void *)(uVar2 + 10 & 0xffff);
          pTVar18 = (TiXmlAttributeSet *)&pvStack_134;
          pTVar17 = (TiXmlAttribute *)0x5678b4;
          CFastBuffer<unsigned_short>::Add(pvVar10,pTVar18,(TiXmlAttribute *)pSVar19);
          uVar11 = local_124;
        } while (local_124 < 10);
        local_104 = local_104 + 1;
        local_b8 = (void *)((float)local_118 + fStack_64);
        pvStack_b4 = (void *)(fStack_60 + (float)local_100);
        apvStack_b0[0] = (void *)(fStack_5c + (float)local_118);
        pvStack_130 = (void *)-(float)local_118;
        local_c4 = (void *)((float)pvStack_130 + fStack_64);
        local_c0 = (CMotionManagerParticles *)((float)local_f0 + fStack_60);
        local_bc = fStack_5c + (float)pvStack_130;
        if ((float)local_c4 < (float)pvStack_e8) {
          pvStack_e8 = local_c4;
        }
        if ((float)local_c0 < (float)local_e4) {
          local_e4 = local_c0;
        }
        if (local_bc < local_e0) {
          local_e0 = local_bc;
        }
        if ((float)local_fc < (float)local_b8) {
          local_fc = local_b8;
        }
        if ((float)local_f8 < (float)pvStack_b4) {
          local_f8 = pvStack_b4;
        }
        this_00 = (SPartGroup *)local_10c;
        pvStack_a0 = pvStack_130;
        local_98 = pvStack_130;
        if ((float)local_f4 < (float)apvStack_b0[0]) {
          local_f4 = apvStack_b0[0];
        }
      }
      local_ec = local_ec + 1;
    } while (local_ec < local_c8);
  }
  *(int *)param_5 = local_104;
  *(void **)param_3 = pvStack_e8;
  *(CMotionManagerParticles **)(param_3 + 4) = local_e4;
  *(float *)(param_3 + 8) = local_e0;
  *(void **)param_4 = local_fc;
  *(void **)(param_4 + 4) = local_f8;
  *(void **)(param_4 + 8) = local_f4;
  return;
}
}

// =================================================
// Function: CMotionManagerParticles::PartInit
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionManagerParticles::PartInit
          (CMotionManagerParticles *this,CMotionManagerParticles *param_1,SPart *param_2,
          CMotionParticleType *param_3,ulong param_4,SEmitParams *param_5)
{
{
  int iVar1;
  int local_8;
  
  *(CMotionParticleType **)param_1 = param_3;
  iVar1 = _rand();
  local_8 = (int)(longlong)
                 ROUND(((((float)iVar1 / (float)_DAT_00b530f8 + (float)iVar1 / (float)_DAT_00b530f8)
                        - (float)_DAT_00b2c188) * *(float *)(param_2 + 0xc0) +
                       *(float *)(param_2 + 0xbc)) * (float)_DAT_00b59bb0);
  *(int *)(param_1 + 4) = *(int *)param_1 - local_8;
  *(undefined4 *)(param_1 + 8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
  PartBirthParamsInit((SPartBirthParams *)(param_1 + 0x10),(CMotionParticleType *)param_2,
                      (SEmitParams *)param_4);
  return;
}
}

// =================================================
// Function: CMotionManagerParticles::UpdateAsync
// =================================================
void __thiscall
CMotionManagerParticles::UpdateAsync(CMotionManagerParticles *this,CInputPortDx8 *param_1)
{
{
  CMotionManagerParticles *this_00;
  undefined4 uVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CPlugAudio *this_01;
  CMwId *pCVar4;
  SCasterCat *pSVar5;
  int iVar6;
  CPlugTree *pCVar7;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  SVolatileTreePointer *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CMotionManagerParticles *unaff_retaddr;
  CMotionManagerParticles *in_stack_0000000c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_8;
  
  this_00 = this + 0x38;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                         (this_00,pCVar8,(ulong)unaff_ESI);
      if (*(int *)(*(int *)(pSVar3 + 0xc) + 0x170) == 0) {
        pCVar4 = (CMwId *)CMwTimer::GetTickTime
                                    ((void *)(DAT_00d731e0 + 0x70),(CMwTimerAdapter *)unaff_EBP);
      }
      else {
        this_01 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
        if (this_01 == (CPlugAudio *)0x0) {
          this_01 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
        }
        pCVar4 = CPlugAudio::MwGetId(this_01,(CPlugAudio *)unaff_EBP);
      }
      uVar1 = *(undefined4 *)pCVar4;
      unaff_ESI = (SVolatileTreePointer *)0x5686f5;
      unaff_EBP = pCVar8;
      pSVar3 = CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[](this_00,pCVar8,unaff_EBX);
      pCVar8 = pCVar8 + 1;
      *(undefined4 *)(pSVar3 + 0x18) = uVar1;
      this = in_stack_0000000c;
    } while (pCVar8 < pCVar2);
  }
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                         (this_00,pCVar8,(ulong)unaff_ESI);
      unaff_ESI = *(SVolatileTreePointer **)(pSVar3 + 0x18);
      GroupEmitParticles(this,(CMotionManagerParticles *)pCVar8,(ulong)unaff_ESI,(ulong)unaff_EBP);
      pCVar8 = pCVar8 + 1;
    } while (pCVar8 < pCVar2);
  }
  pCStack_8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                         (this_00,pCStack_8,(ulong)unaff_ESI);
      unaff_ESI = (SVolatileTreePointer *)0x56874d;
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (pSVar3 + 0x1c,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
      pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar8 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar5 = CFastBuffer<struct_SHmsVPackerObjectPacked>::operator[]
                             (pSVar3 + 0x1c,pCVar9,(ulong)unaff_ESI);
          if (*(int *)(*(CMotionEmitterParticles **)pSVar5 + 0x80) != 0) {
            unaff_ESI = (SVolatileTreePointer *)0x0;
            CMotionEmitterParticles::SetIsActive
                      (*(CMotionEmitterParticles **)pSVar5,(CSceneObjectLink *)0x0,(int)unaff_EBP);
          }
          pCVar9 = pCVar9 + 1;
        } while (pCVar9 < pCVar8);
      }
      pCStack_8 = pCStack_8 + 1;
      this = unaff_retaddr;
    } while (pCStack_8 < pCVar2);
  }
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[]
                         (this_00,pCVar8,(ulong)unaff_ESI);
      unaff_ESI = *(SVolatileTreePointer **)(pSVar3 + 0x18);
      iVar6 = GroupUpdateParticles
                        (this,(CMotionManagerParticles *)pCVar8,(ulong)unaff_ESI,(ulong)unaff_EBP);
      if (iVar6 != 0) {
        unaff_retaddr = unaff_retaddr + 1;
      }
      pCVar8 = pCVar8 + 1;
    } while (pCVar8 < pCVar2);
    if (unaff_retaddr != (CMotionManagerParticles *)0x0) {
      pCVar7 = CSceneMobil::GetTree(*(CSceneMobil **)(this + 0x1c),unaff_ESI);
      *(uint *)(pCVar7 + 0x9c) = *(uint *)(pCVar7 + 0x9c) | 8;
      return;
    }
  }
  pCVar7 = CSceneMobil::GetTree(*(CSceneMobil **)(this + 0x1c),unaff_ESI);
  *(uint *)(pCVar7 + 0x9c) = *(uint *)(pCVar7 + 0x9c) & 0xfffffff7;
  return;
}
}

