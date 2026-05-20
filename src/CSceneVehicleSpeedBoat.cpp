// Class implementation: CSceneVehicleSpeedBoat

// =================================================
// Function: CSceneVehicleSpeedBoat::AbsorbContact
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleSpeedBoat::AbsorbContact
          (CSceneVehicleSpeedBoat *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2,
          CHmsPhysicalContact *param_3)
{
{
  CSceneMobilAbsorbContact *pCVar1;
  int iVar2;
  int iVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBX;
  float unaff_EBP;
  GmVec3 *unaff_ESI;
  GmVec3 *pGVar5;
  GmIso4 *unaff_EDI;
  float10 fVar6;
  float fVar7;
  CSceneVehicleSpeedBoat *pCStack00000010;
  CSceneVehicleSpeedBoat *pCStack_38;
  GmVec3 local_34 [4];
  float fStack_30;
  float fStack_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c [4];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(this + 0x2e4) = 1;
  if (*(short *)(param_1 + 0x48) != 0xd) {
    *(undefined4 *)(this + 0x2e0) = 1;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    pCVar1 = param_1 + 0x24;
    pGVar5 = (GmVec3 *)(param_1 + 0xc);
    if ((*(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x2c) +
         *(float *)(param_1 + 0xc) * *(float *)pCVar1 +
         *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x28) <= _DAT_00c418e0) &&
       (iVar2 = *(int *)(this + 100), iVar2 != 0)) {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar2 + 0x14),
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24),
                          unaff_EBX);
      iVar2 = *(int *)pSVar4;
      local_20 = *(float *)(iVar2 + 300) * *(float *)(iVar2 + 0x38);
      local_1c[0] = 0.0;
      local_1c[1] = 0.0;
      local_1c[3] = *(float *)(iVar2 + 0x3c) * *(float *)(iVar2 + 300);
      local_1c[2] = 0.0;
      local_c = 0;
      local_8 = 0;
      local_4 = 0;
      GmMat3::Inverse(&local_20,unaff_EDI);
      if (_DAT_00d0d4fc <
          *(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x14) +
          *(float *)pGVar5 * *(float *)pGVar5 +
          *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x10)) {
        fVar6 = (float10)func_0x009c1b40();
        fVar7 = 1.0 / (float)fVar6;
        *(float *)pGVar5 = fVar7 * *(float *)pGVar5;
        *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) * fVar7;
        *(float *)(param_1 + 0x14) = fVar7 * *(float *)(param_1 + 0x14);
      }
      iVar3 = *(int *)(*(int *)(this + 0x28) + 0x14);
      local_28 = *(float *)(param_3 + 0x18) - *(float *)(iVar3 + 0x50);
      local_24 = *(float *)(param_3 + 0x1c) - *(float *)(iVar3 + 0x54);
      local_20 = *(float *)(param_3 + 0x20) - *(float *)(iVar3 + 0x58);
      ComputeImpulse(this,pCStack_38,(float)local_1c,*(GmMat3 **)(iVar2 + 0x124),(float)pCVar1,
                     pGVar5,(GmVec3 *)&local_28,local_34,unaff_ESI);
      pCStack00000010 =
           (CSceneVehicleSpeedBoat *)
           (*(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x14) +
           *(float *)pGVar5 * *(float *)pGVar5 +
           *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x10));
      if (_DAT_00d0d4fc < (float)pCStack00000010) {
        fVar6 = (float10)func_0x009c1b40();
        fVar7 = 1.0 / (float)fVar6;
        *(float *)pGVar5 = fVar7 * *(float *)pGVar5;
        *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) * fVar7;
        *(float *)(param_1 + 0x14) = fVar7 * *(float *)(param_1 + 0x14);
      }
      pCStack00000010 = *(CSceneVehicleSpeedBoat **)(iVar2 + 0x128);
      fStack_30 = (float)pCStack00000010 * fStack_30;
      fStack_2c = fStack_2c * (float)pCStack00000010;
      local_28 = (float)pCStack00000010 * local_28;
      CHmsItem::AddImpulse(*(CHmsItem **)(this + 0x28),(CHmsItem *)&fStack_30,(GmVec3 *)pCStack_38);
      local_20 = *(float *)(param_1 + 0x28);
      local_24 = *(float *)pCVar1;
      local_1c[0] = *(float *)(param_1 + 0x2c);
      pCStack00000010 =
           (CSceneVehicleSpeedBoat *)
           ABS(local_1c[0] * local_28 + local_24 * fStack_30 + local_20 * fStack_2c);
      fVar7 = LimitTo(this,pCStack00000010,*(float *)(iVar2 + 0x144),unaff_EBP);
      *(float *)(this + 0x2e8) = fVar7;
    }
    return;
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}
}

// =================================================
// Function: CSceneVehicleSpeedBoat::ComputeForces
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleSpeedBoat::ComputeForces
          (CSceneVehicleSpeedBoat *this,CCallbackSceneToyBroomStickComputeForces *param_1,
          CHmsItem *param_2,float param_3)
{
{
  SCasterCat *pSVar1;
  GmMat3 *pGVar2;
  CSceneToySea *pCVar3;
  CGameCtnZone *pCVar4;
  int iVar5;
  int iVar6;
  CSceneVehicleSpeedBoat *this_00;
  CSceneVehicleSpeedBoat *this_01;
  CSceneVehicleSpeedBoat *this_02;
  CSceneVehicleSpeedBoat *this_03;
  CSceneVehicleSpeedBoat *this_04;
  CSceneVehicleSpeedBoat *this_05;
  CSceneVehicleSpeedBoat *this_06;
  CSceneVehicleSpeedBoat *this_07;
  CSceneVehicleSpeedBoat *this_08;
  CSceneVehicleSpeedBoat *this_09;
  CSceneVehicleSpeedBoat *this_10;
  ulong unaff_EBX;
  CSceneVehicleSpeedBoat *unaff_ESI;
  ulong unaff_EDI;
  float *pfVar7;
  float10 fVar8;
  GmVec3 *pGVar9;
  GmMat3 *pGVar10;
  CSceneVehicleSpeedBoat *pCVar11;
  GmMat3 *pGVar12;
  GmMat3 *pGVar13;
  float fVar14;
  double in_stack_00000034;
  double in_stack_00000064;
  GmVec3 *in_stack_fffffdc4;
  GmVec3 *in_stack_fffffdc8;
  GmIso4 *in_stack_fffffdcc;
  GmMat3 *pGVar15;
  GmMat3 *in_stack_fffffdd0;
  GmMat3 *pGVar16;
  CSceneVehicleSpeedBoat *pCVar17;
  GmMat3 *in_stack_fffffdd8;
  GmMat3 *pGVar18;
  GmMat3 *in_stack_fffffddc;
  GmMat3 *pGVar19;
  CSceneVehicleSpeedBoat *pCVar20;
  GmMat3 *pGVar21;
  undefined8 in_stack_fffffde0;
  GmMat3 *pGVar22;
  GmMat3 *in_stack_fffffde8;
  GmMat3 *pGVar23;
  GmMat3 *in_stack_fffffdec;
  CSceneVehicleSpeedBoat *pCVar24;
  float fVar25;
  GmMat3 *pGVar26;
  GmVec3 *in_stack_fffffdf0;
  float fVar27;
  CSceneSector *pCVar28;
  float fVar29;
  GmMat3 *pGVar30;
  CMwId *in_stack_fffffdf8;
  GmMat3 *pGVar31;
  GmMat3 *in_stack_fffffe04;
  GmMat3 *in_stack_fffffe0c;
  GmMat3 *in_stack_fffffe10;
  CSceneVehicleSpeedBoat *pCVar32;
  float fVar33;
  GmVec3 *pGVar34;
  GmVec3 *pGVar35;
  GmVec3 *pGVar36;
  float fVar37;
  GmVec3 *pGVar38;
  float fVar39;
  GmVec3 *pGVar40;
  GmMat3 *in_stack_fffffe44;
  GmMat3 *in_stack_fffffe48;
  CSceneVehicleSpeedBoat *pCVar41;
  GmMat3 *pGVar42;
  CSceneVehicleSpeedBoat *pCVar44;
  double dVar43;
  GmMat3 *pGVar45;
  CSceneVehicleSpeedBoat *pCStack_19c;
  GmMat3 *pGStack_198;
  CSceneVehicleSpeedBoat *pCStack_194;
  CSceneVehicleSpeedBoat *pCStack_190;
  GmMat3 *pGStack_18c;
  CSceneVehicleSpeedBoat *pCStack_188;
  GmMat3 *pGStack_184;
  GmMat3 *pGStack_180;
  CSceneVehicleSpeedBoat *pCStack_17c;
  CSceneVehicleSpeedBoat *pCStack_178;
  GmMat3 *pGStack_174;
  CSceneVehicleSpeedBoat *pCStack_170;
  GmMat3 *pGStack_16c;
  GmMat3 *pGStack_168;
  CSceneVehicleSpeedBoat *pCStack_164;
  float fStack_160;
  GmMat3 *pGStack_15c;
  CSceneVehicleSpeedBoat *pCStack_158;
  CSceneVehicleSpeedBoat *pCStack_154;
  GmMat3 *pGStack_150;
  CSceneVehicleSpeedBoat *pCStack_14c;
  float fStack_148;
  GmMat3 *pGStack_144;
  float fStack_140;
  CSceneVehicleSpeedBoat *pCStack_13c;
  float fStack_138;
  CSceneVehicleSpeedBoat *pCStack_134;
  GmMat3 *pGStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  undefined4 uStack_11c;
  float fStack_118;
  float fStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  GmMat3 *pGStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  GmMat3 *pGStack_ec;
  CSceneVehicleSpeedBoat *pCStack_e8;
  GmMat3 *pGStack_e4;
  GmMat3 *pGStack_e0;
  GmMat3 *pGStack_dc;
  GmMat3 *pGStack_d8;
  GmMat3 *pGStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  CSceneVehicleSpeedBoat *pCStack_c0;
  GmMat3 *pGStack_bc;
  GmMat3 *pGStack_b8;
  CSceneVehicleSpeedBoat *pCStack_b4;
  GmMat3 *pGStack_b0;
  CSceneVehicleSpeedBoat *pCStack_ac;
  CSceneVehicleSpeedBoat *pCStack_a8;
  GmMat3 *pGStack_a4;
  CSceneVehicleSpeedBoat *pCStack_a0;
  CSceneVehicleSpeedBoat *pCStack_9c;
  GmMat3 *pGStack_98;
  CSceneVehicleSpeedBoat *pCStack_94;
  float fStack_90;
  GmMat3 *pGStack_8c;
  CSceneVehicleSpeedBoat *pCStack_88;
  GmVec3 *pGStack_84;
  GmMat3 *pGStack_80;
  float fStack_7c;
  GmMat3 *pGStack_78;
  GmMat3 *pGStack_74;
  CSceneVehicleSpeedBoat *pCStack_70;
  float fStack_6c;
  GmMat3 *pGStack_68;
  CSceneVehicleSpeedBoat *pCStack_64;
  GmMat43 *pGStack_60;
  GmMat3 *pGStack_5c;
  float fStack_58;
  double dStack_54;
  float fStack_48;
  GmMat3 aGStack_44 [4];
  GmMat3 aGStack_40 [4];
  float fStack_3c;
  GmMat3 aGStack_38 [4];
  GmMat3 aGStack_34 [4];
  float fStack_30;
  GmMat3 aGStack_2c [4];
  GmMat3 aGStack_28 [4];
  undefined8 uStack_24;
  float afStack_18 [3];
  float fStack_c;
  
  iVar6 = *(int *)(this + 100);
  if (iVar6 != 0) {
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(iVar6 + 0x14),
                        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar6 + 0x24),unaff_EDI
                       );
    iVar6 = *(int *)pSVar1;
    ComputeIntertiaMatrix(this,unaff_ESI);
    *(undefined4 *)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x4c) = *(undefined4 *)(iVar6 + 0x100);
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(this + 0x28) + 0x34),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBX);
    pGVar2 = (GmMat3 *)(**(code **)(**(int **)pSVar1 + 0x78))();
    pGVar16 = pGVar2;
    CHmsItem::GetLinearSpeed(*(CHmsItem **)(this + 0x28),(CHmsItem *)&fStack_138,in_stack_fffffdc4);
    CHmsItem::GetAngularSpeed
              (*(CHmsItem **)(this + 0x28),(CHmsItem *)&stack0xfffffe10,in_stack_fffffdc8);
    pGVar35 = (GmVec3 *)0x0;
    pGVar34 = (GmVec3 *)0x0;
    fVar33 = 0.0;
    uStack_110 = 0;
    fStack_114 = 0.0;
    fStack_118 = 0.0;
    pGVar40 = (GmVec3 *)0x0;
    fVar39 = 0.0;
    pGVar38 = (GmVec3 *)0x0;
    fStack_140 = 0.0;
    pGStack_144 = (GmMat3 *)0x0;
    fStack_148 = 0.0;
    pCStack_134 = (CSceneVehicleSpeedBoat *)0x0;
    fStack_138 = 0.0;
    pCStack_13c = (CSceneVehicleSpeedBoat *)0x0;
    uStack_104 = 0;
    uStack_108 = 0;
    uStack_10c = 0;
    fStack_d0 = 0.0;
    pGStack_d4 = (GmMat3 *)0x0;
    pGStack_d8 = (GmMat3 *)0x0;
    fStack_c4 = 0.0;
    fStack_c8 = 0.0;
    fStack_cc = 0.0;
    uStack_11c = 0;
    fStack_120 = 0.0;
    fStack_124 = 0.0;
    pfVar7 = &fStack_48;
    for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pfVar7 = *(float *)pGVar2;
      pGVar2 = pGVar2 + 4;
      pfVar7 = pfVar7 + 1;
    }
    iVar6 = (int)((ulonglong)in_stack_fffffde0 >> 0x20);
    pGVar9 = *(GmVec3 **)(in_stack_fffffddc + 0x24);
    fVar14 = *(float *)(in_stack_fffffddc + 0x28);
    fVar37 = *(float *)(in_stack_fffffddc + 0x2c);
    pGVar2 = *(GmMat3 **)(iVar6 + 0xe0);
    pGVar23 = (GmMat3 *)in_stack_fffffde0;
    pCVar28 = *(CSceneSector **)(iVar6 + 0xe4);
    fVar25 = (float)_DAT_00b313b8;
    pCVar41 = (CSceneVehicleSpeedBoat *)
              (*(float *)(iVar6 + 0xd8) * *(float *)(iVar6 + 0xdc) * fVar25);
    dStack_54 = (double)((float)pGVar2 * fVar25);
    pGVar13 = (GmMat3 *)((float)pGVar2 * fVar25 * *(float *)(iVar6 + 0xd8));
    pCVar32 = (CSceneVehicleSpeedBoat *)(-(float)pCVar28 * fVar25 * *(float *)(iVar6 + 0xd8));
    pCStack_170 = (CSceneVehicleSpeedBoat *)((float)pCVar28 * fVar25 * *(float *)(iVar6 + 0xd8));
    uStack_24 = (double)(-(float)pGVar2 * fVar25);
    pGStack_18c = (GmMat3 *)(-(float)pGVar2 * fVar25 * *(float *)(iVar6 + 0xd8));
    pCVar24 = (CSceneVehicleSpeedBoat *)
              (*(float *)(iVar6 + 0xd8) * -*(float *)(iVar6 + 0xdc) * fVar25);
    pGVar12 = (GmMat3 *)pCVar41;
    pCStack_19c = pCVar24;
    pGStack_198 = pGVar13;
    pCStack_194 = pCVar32;
    pCStack_190 = pCVar24;
    pCStack_188 = pCVar32;
    pGStack_184 = (GmMat3 *)pCVar41;
    pGStack_180 = pGStack_18c;
    pCStack_17c = pCVar32;
    pCStack_178 = pCVar24;
    pGStack_174 = pGVar13;
    pGStack_16c = (GmMat3 *)pCVar41;
    pGStack_168 = pGStack_18c;
    pCStack_164 = pCStack_170;
    pCStack_154 = pCVar24;
    pGStack_150 = pGStack_18c;
    pCStack_14c = pCStack_170;
    pGVar42 = pGVar13;
    pCVar44 = pCStack_170;
    GmMat3::Inverse(&fStack_48,in_stack_fffffdcc);
    GmVec3::MultTranspose(&stack0xfffffe5c,aGStack_44,in_stack_fffffdd0);
    pGVar15 = (GmMat3 *)0x814c3b;
    GmVec3::MultTranspose(&stack0xfffffe54,aGStack_40,pGVar16);
    pGVar16 = (GmMat3 *)0x814c4f;
    GmVec3::MultTranspose(&fStack_160,(GmMat3 *)&fStack_3c,in_stack_fffffdd8);
    pCVar17 = (CSceneVehicleSpeedBoat *)0x814c63;
    GmVec3::MultTranspose(&pGStack_174,aGStack_38,(GmMat3 *)pCVar24);
    pGVar18 = (GmMat3 *)0x814c77;
    GmVec3::MultTranspose(&pCStack_188,aGStack_34,pGVar23);
    GmVec3::MultTranspose(&fStack_160,(GmMat3 *)&fStack_30,pGVar2);
    pCVar20 = (CSceneVehicleSpeedBoat *)0x814c9f;
    GmVec3::MultTranspose(&fStack_138,aGStack_2c,in_stack_fffffde8);
    GmVec3::MultTranspose(&pCStack_170,aGStack_28,in_stack_fffffdec);
    pGStack_184 = (GmMat3 *)((float)pGVar42 + (float)pGStack_184);
    pGStack_180 = (GmMat3 *)((float)pCVar44 + (float)pGStack_180);
    pCStack_17c = (CSceneVehicleSpeedBoat *)((float)pGVar12 + (float)pCStack_17c);
    pCStack_190 = (CSceneVehicleSpeedBoat *)((float)pCStack_190 + (float)pGVar42);
    pGStack_18c = (GmMat3 *)((float)pGStack_18c + (float)pCVar44);
    pCStack_188 = (CSceneVehicleSpeedBoat *)((float)pCStack_188 + (float)pGVar12);
    fStack_148 = fStack_148 + (float)pGVar42;
    pGStack_144 = (GmMat3 *)((float)pGStack_144 + (float)pCVar44);
    fStack_140 = fStack_140 + (float)pGVar12;
    fStack_160 = fStack_160 + (float)pGVar42;
    pGStack_15c = (GmMat3 *)((float)pGStack_15c + (float)pCVar44);
    pCStack_158 = (CSceneVehicleSpeedBoat *)((float)pCStack_158 + (float)pGVar12);
    pCStack_178 = (CSceneVehicleSpeedBoat *)((float)pCStack_178 + (float)pGVar42);
    pGStack_174 = (GmMat3 *)((float)pGStack_174 + (float)pCVar44);
    pCStack_170 = (CSceneVehicleSpeedBoat *)((float)pCStack_170 + (float)pGVar12);
    pCStack_154 = (CSceneVehicleSpeedBoat *)((float)pCStack_154 + (float)pGVar42);
    pGStack_150 = (GmMat3 *)((float)pGStack_150 + (float)pCVar44);
    pCStack_14c = (CSceneVehicleSpeedBoat *)((float)pCStack_14c + (float)pGVar12);
    pGStack_130 = (GmMat3 *)((float)pGStack_130 + (float)pGVar42);
    fStack_12c = fStack_12c + (float)pCVar44;
    fStack_128 = fStack_128 + (float)pGVar12;
    pGStack_16c = (GmMat3 *)((float)pGStack_16c + (float)pGVar42);
    pGStack_168 = (GmMat3 *)((float)pCVar44 + (float)pGStack_168);
    pCStack_164 = (CSceneVehicleSpeedBoat *)((float)pGVar12 + (float)pCStack_164);
    pGVar23 = (GmMat3 *)0x814e5b;
    CPlugPhysicalObject::SetComPos
              ((void *)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x18),
               (CPlugPhysicalObject *)(iVar6 + 0x2c),in_stack_fffffdf0);
    pCVar24 = (CSceneVehicleSpeedBoat *)0x814e65;
    pCVar3 = CScene::SeaGet(*(CScene **)(this + 0x14),(CScene *)0x0,pCVar28);
    pGVar2 = (GmMat3 *)((float)pGVar12 - *(float *)(iVar6 + 0x150));
    fStack_12c = (float)pCVar32 - *(float *)(iVar6 + 0x150);
    pCStack_134 = (CSceneVehicleSpeedBoat *)pGVar12;
    pGStack_130 = pGVar13;
    if (pCVar3 == (CSceneToySea *)0x0) {
      pGVar45 = pGVar13;
      pCVar11 = pCVar32;
      pCVar4 = CHmsItem::GetZone(*(CHmsItem **)(this + 0x28),(CGameCtnCollection *)0x0,
                                 in_stack_fffffdf8);
      pCStack_70 = pCVar44;
      iVar5 = (**(code **)(*(int *)pCVar4 + 0xa8))();
      pGStack_68 = *(GmMat3 **)(iVar5 + 0x178);
      pGVar19 = pGStack_68;
      in_stack_fffffe04 = pGStack_68;
      pGVar10 = pGStack_68;
      in_stack_fffffe0c = pGStack_68;
      in_stack_fffffe10 = pGStack_68;
      in_stack_fffffe44 = pGStack_68;
      in_stack_fffffe48 = pGStack_68;
      pGStack_100 = pGStack_68;
    }
    else {
      pGVar9 = (GmVec3 *)GetWaterElevation(this,(CSceneVehicleSpeedBoat *)pGVar12,SUB41(pGVar13,0));
      pGVar10 = (GmMat3 *)
                GetWaterElevation(this,(CSceneVehicleSpeedBoat *)in_stack_fffffe10,SUB41(pGVar2,0));
      pCVar24 = pCStack_134;
      GetWaterElevation(this,pCStack_13c,SUB41(fStack_138,0));
      pGVar23 = pGStack_180;
      pCVar11 = (CSceneVehicleSpeedBoat *)GetWaterElevation(this,pCStack_188,SUB41(pGStack_184,0));
      pGVar34 = (GmVec3 *)
                GetWaterElevation(this,(CSceneVehicleSpeedBoat *)pGStack_198,SUB41(pCStack_194,0));
      pCVar20 = pCStack_14c;
      pGStack_ec = (GmMat3 *)GetWaterElevation(this,pCStack_154,SUB41(pGStack_150,0));
      pGVar19 = pGStack_168;
      pGVar12 = (GmMat3 *)GetWaterElevation(this,pCStack_170,SUB41(pGStack_16c,0));
      pGVar18 = pGStack_184;
      pGVar2 = (GmMat3 *)
               GetWaterElevation(this,(CSceneVehicleSpeedBoat *)pGStack_18c,SUB41(pCStack_188,0));
      pCVar17 = pCStack_164;
      pGVar45 = pGVar13;
      pGVar13 = (GmMat3 *)
                GetWaterElevation(this,(CSceneVehicleSpeedBoat *)pGStack_16c,SUB41(pGStack_168,0));
      pGVar16 = pGStack_144;
      GetWaterElevation(this,pCStack_14c,SUB41(fStack_148,0));
      pGVar15 = pGStack_184;
      pGStack_68 = (GmMat3 *)
                   GetWaterElevation(this,(CSceneVehicleSpeedBoat *)pGStack_18c,SUB41(pCStack_188,0)
                                    );
      pCStack_70 = pCVar44;
    }
    pCStack_c0 = (CSceneVehicleSpeedBoat *)pGStack_16c;
    pGStack_bc = pGStack_100;
    pGStack_b8 = (GmMat3 *)pCStack_164;
    pGStack_60 = (GmMat43 *)pGStack_184;
    fStack_58 = (float)pCStack_17c;
    pCStack_a8 = pCStack_19c;
    pCStack_a0 = pCStack_194;
    fStack_90 = (float)pCStack_178;
    pCStack_88 = pCStack_170;
    fStack_6c = (float)pCStack_190;
    pCStack_64 = pCStack_188;
    pCStack_b4 = (CSceneVehicleSpeedBoat *)pGVar12;
    pGStack_b0 = in_stack_fffffe44;
    pCStack_ac = pCVar11;
    pGStack_a4 = pGVar10;
    pCStack_9c = (CSceneVehicleSpeedBoat *)pGVar12;
    pGStack_98 = in_stack_fffffe44;
    pCStack_94 = pCVar11;
    pGStack_8c = in_stack_fffffe10;
    pGStack_84 = pGVar9;
    pGStack_80 = in_stack_fffffe04;
    fStack_7c = fVar37;
    pGStack_78 = (GmMat3 *)pCVar41;
    pGStack_74 = in_stack_fffffe0c;
    pGStack_5c = in_stack_fffffe48;
    pCVar44 = pCStack_70;
    GmMat3::SetIdentity(afStack_18,(GmMat43 *)pGVar15);
    fVar25 = fVar14 - (float)pCVar24;
    fVar27 = (float)pGVar10 - (float)pGVar23;
    fVar29 = (float)pGVar38 - (float)pGVar38;
    pGVar15 = (GmMat3 *)(fVar25 * fVar25 + fVar27 * fVar27 + fVar29 * fVar29);
    if (_DAT_00d0d4fc < (float)pGVar15) {
      fVar8 = (float10)func_0x009c1b40();
      pGVar15 = (GmMat3 *)(1.0 / (float)fVar8);
      fVar25 = (float)pGVar15 * fVar25;
      fVar27 = (float)pGVar15 * fVar27;
      fVar29 = (float)pGVar15 * fVar29;
    }
    pGVar12 = (GmMat3 *)(fVar14 - fVar14);
    pGVar31 = (GmMat3 *)((float)pGVar10 - (float)pCVar20);
    pGVar23 = (GmMat3 *)((float)pGVar38 - (float)pCStack_154);
    pGVar21 = (GmMat3 *)
              ((float)pGVar23 * (float)pGVar23 +
              (float)pGVar31 * (float)pGVar31 + (float)pGVar12 * (float)pGVar12);
    pGVar22 = (GmMat3 *)((ulonglong)(double)(float)pGVar23 >> 0x20);
    fStack_f4 = fVar27;
    fStack_f0 = fVar29;
    fStack_f8 = fVar25;
    if (_DAT_00d0d4fc < (float)pGVar21) {
      fVar8 = (float10)func_0x009c1b40();
      pGVar21 = (GmMat3 *)(1.0 / (float)fVar8);
      pGVar12 = (GmMat3 *)((float)pGVar21 * (float)pGVar12);
      pGVar31 = (GmMat3 *)((float)pGVar21 * (float)pGVar31);
      pGVar23 = (GmMat3 *)((float)pGVar21 * (float)pGVar23);
      fStack_f4 = fVar27;
      fStack_f0 = fVar29;
      fStack_f8 = fVar25;
    }
    pGVar26 = (GmMat3 *)((float)pGVar31 * fStack_f0 - (float)pGVar23 * fStack_f4);
    pCVar24 = (CSceneVehicleSpeedBoat *)(fStack_f8 * (float)pGVar23 - (float)pGVar12 * fStack_f0);
    pGVar30 = (GmMat3 *)((float)pGVar12 * fStack_f4 - fStack_f8 * (float)pGVar31);
    pGStack_15c = pGVar26;
    pCStack_158 = pCVar24;
    pCStack_154 = (CSceneVehicleSpeedBoat *)pGVar30;
    pGStack_ec = pGVar26;
    pCStack_e8 = pCVar24;
    pGStack_e4 = pGVar30;
    pGStack_e0 = pGVar12;
    pGStack_dc = pGVar31;
    pGStack_d8 = pGVar23;
    GmVec3::MultTranspose(&stack0xfffffdec,in_stack_fffffddc,pGVar16);
    GmVec3::MultTranspose(&stack0xfffffe34,(GmMat3 *)&fStack_f4,(GmMat3 *)pCVar17);
    GmVec3::MultTranspose(&pCStack_19c,(GmMat3 *)&fStack_f0,pGVar18);
    GmVec3::MultTranspose(&stack0xfffffe5c,(GmMat3 *)&pGStack_ec,pGVar19);
    GmVec3::MultTranspose(&pCStack_158,(GmMat3 *)&pCStack_e8,pGVar21);
    GmVec3::MultTranspose(&pGStack_16c,(GmMat3 *)&pGStack_e4,pGVar22);
    GmVec3::MultTranspose(&pGStack_180,(GmMat3 *)&pGStack_e0,pGVar15);
    GmVec3::MultTranspose(&pCStack_158,(GmMat3 *)&pGStack_dc,pGVar26);
    GmVec3::MultTranspose(&pGStack_130,(GmMat3 *)&pGStack_d8,(GmMat3 *)pCVar24);
    GmVec3::MultTranspose(&pGStack_168,(GmMat3 *)&pGStack_d4,pGVar30);
    GmVec3::MultTranspose(&fStack_58,(GmMat3 *)&fStack_d0,pGVar12);
    GmVec3::MultTranspose(&fStack_6c,(GmMat3 *)&fStack_cc,pGVar31);
    GmVec3::MultTranspose(aGStack_44,(GmMat3 *)&fStack_c8,pGVar23);
    GmVec3::MultTranspose(&pCStack_88,(GmMat3 *)&fStack_c4,in_stack_fffffe04);
    GmVec3::MultTranspose(&uStack_24,(GmMat3 *)&pCStack_c0,pGVar10);
    GmVec3::MultTranspose(&pGStack_74,(GmMat3 *)&pGStack_bc,in_stack_fffffe0c);
    GmVec3::MultTranspose(&pCStack_64,(GmMat3 *)&pGStack_b8,in_stack_fffffe10);
    GmVec3::MultTranspose(&fStack_48,(GmMat3 *)&pCStack_b4,pGVar2);
    GmVec3::MultTranspose((void *)((int)&uStack_24 + 4),(GmMat3 *)&pGStack_b0,pGVar13);
    pGStack_180 = (GmMat3 *)((float)pGStack_180 - fStack_30);
    pCStack_154 = (CSceneVehicleSpeedBoat *)((float)pCStack_154 - fStack_48);
    fStack_160 = fStack_160 - (float)uStack_24;
    fStack_118 = fStack_118 - fStack_6c;
    pGStack_130 = (GmMat3 *)((float)pGStack_130 - fStack_c);
    fStack_148 = fStack_148 - (float)pGStack_60;
    fStack_124 = fStack_124 - dStack_54._0_4_;
    pGStack_100 = (GmMat3 *)((float)pGStack_100 - fStack_3c);
    pCStack_13c = (CSceneVehicleSpeedBoat *)((float)pCStack_13c - afStack_18[0]);
    fVar14 = Min8(this,pCStack_154,fStack_160,fStack_118,(float)pGStack_130,fStack_148,fStack_124,
                  (float)pGStack_100,(float)pCStack_13c,(float)pCVar32);
    pGVar36 = (GmVec3 *)(fVar14 + *(float *)(iVar6 + 0x10c));
    fVar33 = Max8(this_00,(CSceneVehicleSpeedBoat *)pGStack_150,(float)pGStack_15c,fStack_114,
                  fStack_12c,(float)pGStack_144,fStack_120,fStack_fc,fStack_138,fVar33);
    if (fVar37 <= (float)_DAT_00ba718c) {
      if (_DAT_00b36144 <= fVar33 + *(float *)(iVar6 + 0x10c)) {
        if (fVar37 < (float)_DAT_00ba718c != (fVar37 == (float)_DAT_00ba718c)) {
          fVar33 = LimitTo(this_01,(CSceneVehicleSpeedBoat *)-fVar37,_DAT_00b32ea8,(float)pGVar34);
          dVar43 = (double)(*(float *)(iVar6 + 0xd8) * (float)_DAT_00b5b9d8 *
                            *(float *)(iVar6 + 0xd8) * fVar33);
          fVar8 = (float10)func_0x009c2390();
          pCVar24 = (CSceneVehicleSpeedBoat *)(float)fVar8;
          fVar33 = (float)pCVar24 * (float)dVar43;
          pGStack_198 = (GmMat3 *)(*(float *)(iVar6 + 0xd4) * fVar33);
          if ((0.0 < (float)pGStack_174) &&
             (pCVar24 = (CSceneVehicleSpeedBoat *)ABS((float)in_stack_fffffe48),
             _DAT_00b31460 < (float)pCVar24)) {
            fStack_160 = *(float *)(iVar6 + 0xd8) * (float)(double)CONCAT44(param_3,param_2);
            fStack_160 = (fStack_160 - (float)pGStack_174) / fStack_160;
            if (fStack_160 < 0.0) {
              fStack_160 = 0.0;
            }
            pCVar24 = (CSceneVehicleSpeedBoat *)(fStack_160 * (float)pGStack_198);
            pGStack_198 = (GmMat3 *)((float)pCVar24 * *(float *)(iVar6 + 0x154));
          }
          pGVar2 = in_stack_fffffe48;
          if (((float)pGStack_174 < (float)_DAT_00b43300) &&
             (pCVar24 = (CSceneVehicleSpeedBoat *)ABS((float)in_stack_fffffe48),
             _DAT_00b36134 <= (float)pCVar24)) {
            pCVar24 = (CSceneVehicleSpeedBoat *)((float)_DAT_00b43300 - (float)pGStack_174);
            in_stack_fffffe48 = (GmMat3 *)pCVar41;
            fVar39 = LimitTo(this,pCVar24,_DAT_00b31460,(float)pGVar35);
            pCStack_194 = (CSceneVehicleSpeedBoat *)
                          ((fVar39 * *(float *)(iVar6 + 0x110) + (float)_DAT_00b2c188) *
                          (float)pCStack_194);
            pCVar41 = (CSceneVehicleSpeedBoat *)in_stack_fffffe48;
          }
          pGStack_b0 = (GmMat3 *)((float)pGStack_198 * (float)in_stack_fffffe44);
          pCStack_ac = (CSceneVehicleSpeedBoat *)((float)pGStack_198 * (float)in_stack_fffffe48);
          pCStack_a8 = (CSceneVehicleSpeedBoat *)((float)pCVar41 * (float)pGStack_198);
          fVar39 = MultCoeff(this,pCVar41,*(float *)(iVar6 + 0x118),_DAT_00b36160);
          pCVar32 = (CSceneVehicleSpeedBoat *)
                    (-*(float *)(iVar6 + 0xf8) * fVar39 * *(float *)(iVar6 + 0xd8));
          fVar39 = LimitTo(this_06,pCVar32,(float)pGVar35,(float)pGVar9);
          fVar14 = MultCoeff(this_07,pCVar41,*(float *)(iVar6 + 0x118),_DAT_00b36160);
          pCVar17 = (CSceneVehicleSpeedBoat *)
                    (-*(float *)(iVar6 + 0xf4) * fVar14 * *(float *)(iVar6 + 0xd8));
          pGStack_60 = (GmMat43 *)LimitTo(this_08,pCVar17,(float)pGVar36,fVar37);
          pGStack_5c = (GmMat3 *)_DAT_00ba718c;
          fStack_58 = fVar33;
          CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pCStack_a0,
                             (GmVec3 *)&pGStack_60,(GmVec3 *)pCVar24);
          if ((float)pGStack_184 != 0.0) {
            if ((float)pGVar45 <= _DAT_00b36144) {
              pCStack_154 = (CSceneVehicleSpeedBoat *)
                            ((float)pGStack_bc * (float)pGStack_18c * *(float *)(iVar6 + 0x54));
              pGStack_150 = (GmMat3 *)
                            (*(float *)(iVar6 + 0x58) * (float)pGStack_18c * (float)pGStack_b8);
              pCStack_158 = (CSceneVehicleSpeedBoat *)
                            ((float)pGStack_18c * *(float *)(iVar6 + 0x50) * (float)pCStack_c0);
              pCStack_19c = (CSceneVehicleSpeedBoat *)
                            (-(*(float *)(iVar6 + 0xf0) / (ABS((float)pCStack_17c) + 1.0)) * fVar33
                            * *(float *)(iVar6 + 0xd8));
              pCVar41 = (CSceneVehicleSpeedBoat *)
                        (*(float *)(iVar6 + 0xe8) / (ABS((float)pGStack_174) + 1.0));
              pCStack_b4 = (CSceneVehicleSpeedBoat *)
                           (-(float)pCVar41 * fVar39 * *(float *)(iVar6 + 0xd8));
              pGStack_b0 = (GmMat3 *)_DAT_00ba718c;
              pCStack_ac = pCStack_19c;
              CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pCStack_158,
                                 (GmVec3 *)&pCStack_b4,(GmVec3 *)pCVar32);
            }
            else {
              fStack_f0 = 0.0;
              pGStack_ec = (GmMat3 *)
                           (*(float *)(iVar6 + 0x54) * (float)pGStack_18c * (float)pGStack_bc);
              pCStack_e8 = (CSceneVehicleSpeedBoat *)0x0;
              GmVec3::MultTranspose(&fStack_f0,in_stack_fffffddc,(GmMat3 *)pCVar32);
              pGVar16 = pGStack_e4;
              if ((float)pGStack_e4 < 0.0) {
                pGVar16 = (GmMat3 *)0x0;
              }
              pCStack_14c = (CSceneVehicleSpeedBoat *)
                            (*(float *)(iVar6 + 0x148) * (float)pGVar16 +
                            (float)pCStack_b4 *
                            *(float *)(iVar6 + 0x58) *
                            (float)pCStack_188 * *(float *)(iVar6 + 0x14c));
              pCStack_154 = (CSceneVehicleSpeedBoat *)
                            ((float)pCStack_188 * *(float *)(iVar6 + 0x50) * (float)pGStack_bc);
              pGStack_150 = (GmMat3 *)pCStack_e8;
              pGStack_198 = (GmMat3 *)
                            (-(*(float *)(iVar6 + 0xf0) / (ABS((float)pCStack_178) + 1.0)) *
                             (float)pCStack_19c * *(float *)(iVar6 + 0xd8));
              pGStack_b0 = (GmMat3 *)
                           (-(*(float *)(iVar6 + 0xe8) / (ABS((float)pCStack_170) + 1.0)) *
                            (float)pGVar45 * *(float *)(iVar6 + 0xd8));
              pCStack_ac = _DAT_00ba718c;
              pCStack_a8 = (CSceneVehicleSpeedBoat *)pGStack_198;
              CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pCStack_154,
                                 (GmVec3 *)&pGStack_b0,pGVar40);
            }
          }
          if ((*(int *)(this + 0x2e0) != 0) &&
             (fVar33 = *(float *)(iVar6 + 0x144) * (float)_DAT_00b313b8,
             fVar33 < *(float *)(this + 0x2e8) != (fVar33 == *(float *)(this + 0x2e8)))) {
            pGStack_198 = (GmMat3 *)
                          ((float)pGStack_b8 * (float)pCStack_188 * *(float *)(iVar6 + 0x54));
            pCStack_14c = (CSceneVehicleSpeedBoat *)
                          (*(float *)(iVar6 + 0x58) * (float)pCStack_188 * (float)pCStack_b4 *
                          *(float *)(iVar6 + 0x130) * *(float *)(this + 0x2e8));
            pCStack_154 = (CSceneVehicleSpeedBoat *)
                          ((float)pCStack_188 * *(float *)(iVar6 + 0x50) * (float)pGStack_bc);
            pCStack_a8 = (CSceneVehicleSpeedBoat *)
                         (-*(float *)(iVar6 + 0xf0) * (float)pCStack_19c * *(float *)(iVar6 + 0xd8))
            ;
            pGStack_b0 = (GmMat3 *)
                         (-*(float *)(iVar6 + 0xe8) * (float)pGVar45 * *(float *)(iVar6 + 0xd8));
            pCStack_ac = _DAT_00ba718c;
            pGStack_150 = pGStack_198;
            CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pCStack_154,
                               (GmVec3 *)&pGStack_b0,pGVar40);
          }
          pCStack_188 = *(CSceneVehicleSpeedBoat **)(iVar6 + 0x74);
          if ((*(float *)(iVar6 + 200) < ABS((float)pCStack_178)) && (fVar39 < (float)_DAT_00b362c0)
             ) {
            pCStack_188 = (CSceneVehicleSpeedBoat *)((float)pCStack_188 * (float)_DAT_00b40f28);
          }
          dVar43 = (double)(float)pGStack_174;
          fVar33 = GmFunc::Sign((float)pGStack_174,(float)pGVar40);
          fVar33 = fVar33 * (float)((float10)dVar43 * (float10)dVar43) * *(float *)(iVar6 + 0x6c);
          dVar43 = (double)(float)pCStack_170;
          fVar39 = GmFunc::Sign((float)pCStack_170,(float)pGVar40);
          pGStack_198 = (GmMat3 *)
                        (fVar39 * (float)((float10)dVar43 * (float10)dVar43) *
                        *(float *)(iVar6 + 0x70));
          dVar43 = (double)(float)pCStack_178;
          fVar39 = GmFunc::Sign((float)pCStack_178,(float)pGVar40);
          pGVar34 = (GmVec3 *)(float)((float10)dVar43 * (float10)dVar43);
          pGStack_d4 = (GmMat3 *)(fVar39 * (float)pGVar34 * *(float *)(iVar6 + 0x68));
          fStack_cc = (float)pGStack_198;
          fStack_d0 = fVar33;
          CHmsItem::AddTorque(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pGStack_d4,pGVar40);
          pCVar24 = (CSceneVehicleSpeedBoat *)(*(float *)(iVar6 + 0x78) * (float)pCStack_170);
          pGVar35 = (GmVec3 *)LimitTo(this,pCVar24,_DAT_00b36adc,(float)pCVar17);
          pCVar32 = (CSceneVehicleSpeedBoat *)((float)pGStack_180 * (float)pCStack_170);
          pGStack_bc = (GmMat3 *)LimitTo(this_09,pCVar32,_DAT_00b313e0,(float)pGVar2);
          pGStack_b8 = (GmMat3 *)pCStack_19c;
          pCVar17 = (CSceneVehicleSpeedBoat *)((float)pCStack_17c * (float)pCStack_164);
          pGStack_b0 = (GmMat3 *)LimitTo(this_10,pCVar17,_DAT_00b313e0,(float)pCVar41);
          CHmsItem::AddTorque(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pGStack_b8,pGVar34);
          if ((((float)in_stack_00000064 < fStack_148) && (fStack_148 < (float)in_stack_00000034))
             && ((float)pCStack_188 < *(float *)(iVar6 + 0x4c))) {
            fVar33 = *(float *)(this + 0x50) - *(float *)(this + 0x54);
            if (fVar33 <= 0.0) {
              fVar33 = fVar33 * *(float *)(iVar6 + 0x44);
              if ((float)pCStack_a0 <= 0.0) {
                pGStack_150 = (GmMat3 *)(fVar33 * *(float *)(iVar6 + 0x108));
                pCStack_19c = (CSceneVehicleSpeedBoat *)((float)pGStack_150 * 0.0);
                pCStack_158 = pCStack_19c;
                pCStack_154 = pCStack_19c;
                CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pCStack_158,
                                   (GmVec3 *)pCVar24,(GmVec3 *)pCVar32);
              }
              else {
                pGStack_150 = (GmMat3 *)(fVar33 * *(float *)(iVar6 + 0x104));
                pCStack_19c = (CSceneVehicleSpeedBoat *)((float)pGStack_150 * 0.0);
                pCStack_158 = pCStack_19c;
                pCStack_154 = pCStack_19c;
                CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pCStack_158,
                                   (GmVec3 *)pCVar24,(GmVec3 *)pCVar32);
              }
            }
            else {
              pGStack_150 = (GmMat3 *)(fVar33 * *(float *)(iVar6 + 0x44));
              pCStack_19c = (CSceneVehicleSpeedBoat *)((float)pGStack_150 * 0.0);
              pCStack_158 = pCStack_19c;
              pCStack_154 = pCStack_19c;
              CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pCStack_158,
                                 (GmVec3 *)pCVar24,(GmVec3 *)pCVar32);
            }
          }
          if ((float)pGStack_98 < 0.0) {
            pGStack_18c = *(GmMat3 **)(iVar6 + 0xc0);
            pCStack_194 = (CSceneVehicleSpeedBoat *)ABS((float)pGStack_98);
            fVar33 = LimitTo(this,pCStack_194,_DAT_00b3618c,(float)pCVar17);
            fVar33 = (fVar33 * *(float *)(this + 0x58)) / (float)_DAT_00b3d380;
            pCStack_190 = (CSceneVehicleSpeedBoat *)((float)_PTR_00b2c178 * fVar33);
            pGStack_80 = (GmMat3 *)((float)pCStack_188 * fVar33);
            pGStack_84 = (GmVec3 *)pCStack_190;
            fStack_7c = (float)pCStack_190;
            CHmsItem::AddTorque(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pGStack_84,pGVar35);
          }
          else {
            pGStack_18c = (GmMat3 *)(*(float *)(iVar6 + 0xc0) * *(float *)(this + 0x58));
            pCStack_17c = (CSceneVehicleSpeedBoat *)
                          (*(float *)(iVar6 + 0xc4) * *(float *)(this + 0x58));
            pCStack_88 = (CSceneVehicleSpeedBoat *)
                         (ABS(*(float *)(this + 0x58)) * *(float *)(iVar6 + 0xbc));
            pCStack_194 = (CSceneVehicleSpeedBoat *)ABS((float)pGStack_98);
            fVar33 = LimitTo(this,pCStack_194,_DAT_00b3618c,(float)pCVar17);
            pCStack_190 = (CSceneVehicleSpeedBoat *)(fVar33 / (float)_DAT_00b3d380);
            pGStack_84 = (GmVec3 *)((float)pCStack_190 * (float)pGStack_84);
            pGStack_80 = (GmMat3 *)((float)pCStack_190 * (float)pCStack_188);
            fStack_7c = (float)pCStack_190 * (float)pCStack_178;
            CHmsItem::AddTorque(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pGStack_84,pGVar35);
          }
        }
      }
      else {
        pGVar40 = *(GmVec3 **)(iVar6 + 0x120);
        pCStack_b4 = (CSceneVehicleSpeedBoat *)0x0;
        pCStack_ac = (CSceneVehicleSpeedBoat *)0x0;
        pGStack_b0 = (GmMat3 *)pGVar40;
        GmVec3::MultTranspose(&pCStack_b4,in_stack_fffffddc,(GmMat3 *)pGVar34);
        CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pGStack_b0,pGVar35,pGVar9);
        fVar33 = (fStack_c4 * (float)pCVar44 +
                 fStack_c8 * (float)pGVar42 + fStack_cc * (float)pCVar41) * *(float *)(iVar6 + 0xd0)
        ;
        pCStack_164 = (CSceneVehicleSpeedBoat *)(fVar33 * (float)pCVar41);
        fStack_160 = fVar33 * (float)pGVar42;
        pGStack_15c = (GmMat3 *)((float)pCVar44 * fVar33);
        CHmsItem::AddForce(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pCStack_164,pGVar36,pGVar40);
        pGStack_184 = *(GmMat3 **)(iVar6 + 0x98);
        fVar14 = _DAT_00b2c060;
        if (-1 < (int)pCStack_178) {
          fVar14 = 1.0;
        }
        fVar37 = _DAT_00b2c060;
        if (-1 < (int)pCStack_17c) {
          fVar37 = 1.0;
        }
        fVar25 = _DAT_00b2c060;
        if (-1 < (int)pGStack_180) {
          fVar25 = 1.0;
        }
        pCStack_14c = (CSceneVehicleSpeedBoat *)
                      ((float)pCStack_17c * (float)pCStack_17c * fVar37 * *(float *)(iVar6 + 0x6c));
        pGStack_d4 = (GmMat3 *)
                     ((float)pCStack_178 * (float)pCStack_178 * fVar14 * *(float *)(iVar6 + 0x70));
        pGVar34 = (GmVec3 *)((float)pGStack_180 * (float)pGStack_180);
        pGStack_dc = (GmMat3 *)
                     (fVar25 * (float)_DAT_00b3d2c0 * (float)pGVar34 * *(float *)(iVar6 + 0x68));
        pGStack_d8 = (GmMat3 *)pCStack_14c;
        CHmsItem::AddTorque(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pGStack_dc,pGVar38);
        pCVar41 = (CSceneVehicleSpeedBoat *)(*(float *)(iVar6 + 0x78) * (float)pCStack_178);
        LimitTo(this,pCVar41,_DAT_00b36adc,fVar39);
        fStack_c4 = LimitTo(this_04,(CSceneVehicleSpeedBoat *)
                                    ((float)pCStack_17c * (float)pCStack_178),_DAT_00b313e0,fVar33);
        pCStack_c0 = (CSceneVehicleSpeedBoat *)pGVar45;
        pGStack_b8 = (GmMat3 *)
                     LimitTo(this_05,(CSceneVehicleSpeedBoat *)
                                     ((float)pCStack_178 * (float)pGStack_16c),_DAT_00b313e0,
                             (float)in_stack_fffffe44);
        CHmsItem::AddTorque(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pCStack_c0,pGVar34);
        if (((float)pCStack_178 < 0.0) || (ABS((float)pCStack_194) < (float)_DAT_00b4fbd0)) {
          fStack_58 = *(float *)(iVar6 + 0xa4) * (float)pCStack_190;
          dStack_54 = (double)((ulonglong)(uint)(*(float *)(iVar6 + 0xac) * (float)pGStack_198) <<
                              0x20);
          CHmsItem::AddTorque(*(CHmsItem **)(this + 0x28),(CHmsItem *)&fStack_58,(GmVec3 *)pCVar41);
        }
      }
    }
    else {
      pGStack_198 = *(GmMat3 **)(iVar6 + 0x8c);
      fVar33 = _DAT_00b2c060;
      if (-1 < (int)pGStack_18c) {
        fVar33 = 1.0;
      }
      fVar39 = _DAT_00b2c060;
      if (-1 < (int)pCStack_190) {
        fVar39 = 1.0;
      }
      fVar14 = _DAT_00b2c060;
      if (-1 < (int)pCStack_194) {
        fVar14 = 1.0;
      }
      pGStack_ec = (GmMat3 *)
                   ((float)pCStack_190 * (float)pCStack_190 * fVar39 * *(float *)(iVar6 + 0x6c));
      pCStack_e8 = (CSceneVehicleSpeedBoat *)
                   ((float)pGStack_18c * (float)pGStack_18c * fVar33 * *(float *)(iVar6 + 0x70));
      pGVar38 = (GmVec3 *)((float)pCStack_194 * (float)pCStack_194);
      fStack_f0 = (float)pGVar38 * fVar14 * *(float *)(iVar6 + 0x68);
      CHmsItem::AddTorque(*(CHmsItem **)(this + 0x28),(CHmsItem *)&fStack_f0,pGVar34);
      LimitTo(this,(CSceneVehicleSpeedBoat *)(*(float *)(iVar6 + 0x78) * (float)pGStack_18c),
              _DAT_00b36adc,(float)pGVar35);
      pGStack_d8 = (GmMat3 *)
                   LimitTo(this_02,(CSceneVehicleSpeedBoat *)
                                   ((float)pGStack_18c * (float)pCStack_190),_DAT_00b313e0,
                           (float)pGVar9);
      pGStack_d4 = in_stack_fffffe48;
      fStack_cc = LimitTo(this_03,(CSceneVehicleSpeedBoat *)
                                  ((float)pGStack_180 * (float)pGStack_18c),_DAT_00b313e0,
                          (float)pGVar36);
      CHmsItem::AddTorque(*(CHmsItem **)(this + 0x28),(CHmsItem *)&pGStack_d4,pGVar38);
    }
    *(undefined4 *)(this + 0x2e8) = 0;
    *(undefined4 *)(this + 0x2e0) = 0;
    *(undefined4 *)(this + 0x2e4) = 0;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleSpeedBoat::ComputeImpulse
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleSpeedBoat::ComputeImpulse
          (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2,
          GmMat3 *param_3,float param_4,GmVec3 *param_5,GmVec3 *param_6,GmVec3 *param_7,
          GmVec3 *param_8)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  GmIso3 *unaff_EDI;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  local_18 = *(float *)(param_5 + 8) * *(float *)(param_6 + 4) -
             *(float *)(param_5 + 4) * *(float *)(param_6 + 8);
  local_14 = *(float *)param_5 * *(float *)(param_6 + 8) -
             *(float *)param_6 * *(float *)(param_5 + 8);
  local_10 = *(float *)param_6 * *(float *)(param_5 + 4) -
             *(float *)param_5 * *(float *)(param_6 + 4);
  GmVec3::Mult(&local_18,(GmIso3 *)param_2,unaff_EDI);
  fVar1 = *(float *)(param_5 + 4);
  fVar2 = *(float *)(param_5 + 4);
  fVar3 = *(float *)param_5;
  fVar4 = *(float *)param_5;
  fVar5 = *(float *)(param_5 + 8);
  fVar6 = *(float *)(param_5 + 8);
  fVar7 = 1.0 / param_2 +
          (local_14 * *(float *)(param_6 + 4) - *(float *)param_6 * local_10) *
          *(float *)(param_5 + 8) +
          *(float *)(param_5 + 4) *
          (*(float *)param_6 * local_c - local_14 * *(float *)(param_6 + 8)) +
          *(float *)param_5 *
          (*(float *)(param_6 + 8) * local_10 - local_c * *(float *)(param_6 + 4));
  if (ABS(fVar7) < _DAT_00ba6fc8) {
    *(undefined4 *)(param_8 + 8) = 0;
    *(undefined4 *)(param_8 + 4) = 0;
    *(undefined4 *)param_8 = 0;
  }
  fVar7 = ((param_4 - 1.0) * (fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2)) / fVar7;
  *(float *)param_8 = fVar7 * *(float *)param_5;
  *(float *)(param_8 + 4) = *(float *)(param_5 + 4) * fVar7;
  *(float *)(param_8 + 8) = fVar7 * *(float *)(param_5 + 8);
  return;
}
}

// =================================================
// Function: CSceneVehicleSpeedBoat::ComputeIntertiaMatrix
// =================================================
void __thiscall
CSceneVehicleSpeedBoat::ComputeIntertiaMatrix
          (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1)
{
{
  int iVar1;
  SCasterCat *pSVar2;
  int extraout_EAX;
  GmVec3 *unaff_ESI;
  ulong unaff_EDI;
  GmIso4 *in_stack_ffffffd8;
  int iVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 100) + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                       (*(int *)(this + 100) + 0x24),unaff_EDI);
  iVar1 = *(int *)pSVar2;
  local_1c = 0;
  local_18 = 0;
  local_10 = *(undefined4 *)(iVar1 + 0x3c);
  local_14 = 0;
  local_c = 0;
  iVar3 = *(int *)(iVar1 + 0x40);
  local_8 = 0;
  local_4 = 0;
  CPlugPhysicalObject::SetComPos
            ((void *)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x18),
             (CPlugPhysicalObject *)(iVar1 + 0x2c),unaff_ESI);
  GmMat3::Inverse(&local_1c,in_stack_ffffffd8);
  if (extraout_EAX != 0) {
    GmMat3::Set((void *)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x1c),
                (CMwCmdScriptVarBool *)&local_18,iVar3);
  }
  *(undefined4 *)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x18) = *(undefined4 *)(iVar1 + 0xcc);
  return;
}
}

// =================================================
// Function: CSceneVehicleSpeedBoat::GetWaterElevation
// =================================================
float __thiscall
CSceneVehicleSpeedBoat::GetWaterElevation
          (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,GmVec3 param_2)
{
{
  CSceneToySea *this_00;
  float *unaff_retaddr;
  undefined3 in_stack_00000009;
  float in_stack_00000010;
  
  this_00 = CScene::SeaGet(*(CScene **)(this + 0x14),(CScene *)0x0,(CSceneSector *)this);
  CSceneToySea::GetPointElevation
            (this_00,_param_2,in_stack_00000010,(float)&stack0x00000000,unaff_retaddr);
  return (float)param_1;
}
}

// =================================================
// Function: CSceneVehicleSpeedBoat::LimitTo
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleSpeedBoat::LimitTo
          (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2,float param_3)
{
{
  float fVar1;
  
  fVar1 = ABS((float)param_1);
  if (param_2 < fVar1) {
    fVar1 = param_2;
  }
  if ((int)param_1 < 0) {
    return _DAT_00b2c060 * fVar1;
  }
  return fVar1 * 1.0;
}
}

// =================================================
// Function: CSceneVehicleSpeedBoat::Max8
// =================================================
float __thiscall
CSceneVehicleSpeedBoat::Max8
          (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2,float param_3,
          float param_4,float param_5,float param_6,float param_7,float param_8,float param_9)
{
{
  if (param_2 < (float)param_1 != (param_2 == (float)param_1)) {
    param_2 = (float)param_1;
  }
  if (param_3 < param_2 != (param_3 == param_2)) {
    param_3 = param_2;
  }
  if (param_4 < param_3 != (param_4 == param_3)) {
    param_4 = param_3;
  }
  if (param_6 < param_5 != (param_6 == param_5)) {
    param_6 = param_5;
  }
  if (param_7 < param_6 != (param_7 == param_6)) {
    param_7 = param_6;
  }
  if (param_8 < param_7 != (param_8 == param_7)) {
    param_8 = param_7;
  }
  if (param_8 < param_4 == (param_8 == param_4)) {
    return param_8;
  }
  return param_4;
}
}

// =================================================
// Function: CSceneVehicleSpeedBoat::Min8
// =================================================
float __thiscall
CSceneVehicleSpeedBoat::Min8
          (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2,float param_3,
          float param_4,float param_5,float param_6,float param_7,float param_8,float param_9)
{
{
  if ((float)param_1 <= param_2) {
    param_2 = (float)param_1;
  }
  if (param_2 <= param_3) {
    param_3 = param_2;
  }
  if (param_3 <= param_4) {
    param_4 = param_3;
  }
  if (param_5 <= param_6) {
    param_6 = param_5;
  }
  if (param_6 <= param_7) {
    param_7 = param_6;
  }
  if (param_7 <= param_8) {
    param_8 = param_7;
  }
  if (param_8 < param_4) {
    return param_8;
  }
  return param_4;
}
}

// =================================================
// Function: CSceneVehicleSpeedBoat::MultCoeff
// =================================================
float __thiscall
CSceneVehicleSpeedBoat::MultCoeff
          (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2,float param_3)
{
{
  if (ABS(param_2) <= 1.0) {
    return (float)param_1;
  }
  if (ABS((float)param_1) < 1.0) {
    if (param_2 != 1.0) {
      return (ABS((float)param_1) + 1.0) * (param_2 - 1.0) * (float)param_1;
    }
    return (float)param_1;
  }
  return param_2 * (float)param_1;
}
}

