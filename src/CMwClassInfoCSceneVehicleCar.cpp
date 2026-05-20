// Class implementation: CMwClassInfoCSceneVehicleCar

// =================================================
// Function: CMwClassInfoCSceneVehicleCar::ArchiveStateBuffer_FixedTimeStep
// =================================================
/* WARNING: Removing unreachable block (ram,0x007f31ae) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CMwClassInfoCSceneVehicleCar::ArchiveStateBuffer_FixedTimeStep
          (CMwClassInfoCSceneVehicleCar *this,CMwClassInfoCSceneVehicleCar *param_1,
          CClassicArchive *param_2,CClassicBufferMemory *param_3,ulong param_4,ulong param_5)
{
{
  float fVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  GmMat43 *pGVar5;
  SCasterCat *pSVar6;
  int extraout_EAX;
  ushort uVar7;
  int iVar8;
  ushort uVar9;
  GmVec3 *pGVar10;
  GmScaleTrans2 *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  GmIso4 *unaff_ESI;
  int iVar12;
  undefined4 *puVar13;
  GmScaleTrans2 *unaff_EDI;
  CMwClassInfoCSceneVehicleCar *pCVar14;
  GmIso4 **ppGVar15;
  undefined2 in_FPUControlWord;
  CMwClassInfoCSceneVehicleCar *in_stack_00000018;
  int in_stack_fffffda0;
  SStateSplit *in_stack_fffffda4;
  ulong uVar16;
  CClassicArchive *pCVar17;
  SQuat_6 *pSVar18;
  GmQuat *pGVar19;
  GmIso4 *pGVar20;
  SStateSplit *in_stack_fffffdcc;
  uint in_stack_fffffdd0;
  ulong uVar21;
  ulong in_stack_fffffdd4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffdd8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffddc;
  ulong in_stack_fffffde0;
  int iStack_218;
  undefined1 auStack_214 [4];
  float fStack_210;
  float fStack_20c;
  float fStack_208;
  uint uStack_1fa;
  uint uStack_1f6;
  undefined4 uStack_1f2;
  uint uStack_1ee;
  undefined2 uStack_1ea;
  undefined2 uStack_1e8;
  undefined1 uStack_1e6;
  byte bStack_1e5;
  undefined2 uStack_1e4;
  undefined1 uStack_1e2;
  byte bStack_1e1;
  SQuat_6 SStack_1e0;
  byte bStack_1df;
  undefined2 uStack_1de;
  uint uStack_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  float fStack_1c4;
  undefined4 uStack_1c0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 *puStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  int local_198 [4];
  SPlugFaceCull aSStack_188 [4];
  float fStack_184;
  float fStack_180;
  float fStack_17c;
  undefined1 auStack_178 [4];
  CMwCmdScriptVarBool *pCStack_174;
  int iStack_170;
  GmIso4 *pGStack_16c;
  GmScaleTrans2 *apGStack_168 [3];
  undefined1 auStack_15c [4];
  float fStack_158;
  float fStack_154;
  float fStack_150;
  uint uStack_13a;
  byte bStack_133;
  byte bStack_12d;
  char cStack_11f;
  undefined4 uStack_11c;
  SQuat_6 aSStack_110 [4];
  GmScaleTrans2 aGStack_10c [8];
  float fStack_104;
  undefined1 auStack_f8 [4];
  undefined1 auStack_f4 [4];
  undefined1 auStack_f0 [4];
  undefined1 auStack_ec [4];
  SPlugFaceCull aSStack_e8 [4];
  SStateSplit aSStack_e4 [4];
  SStateSplit aSStack_e0 [100];
  undefined1 auStack_7c [16];
  undefined1 auStack_6c [16];
  undefined1 auStack_5c [16];
  undefined1 auStack_4c [16];
  undefined1 auStack_3c [16];
  undefined1 auStack_2c [8];
  SPlugFaceCull aSStack_24 [8];
  undefined1 auStack_1c [8];
  undefined4 uStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00acfbbb;
  local_c = ExceptionList;
  uVar3 = DAT_00cca150 ^ (uint)&stack0xfffffdbc;
  ExceptionList = &local_c;
  if (param_3 == (CClassicBufferMemory *)&DAT_00000009) {
    uVar4 = (**(code **)(*(int *)this + 4))(9,local_198);
    pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    pGVar5 = (GmMat43 *)(uVar4 & 0xff);
    if ((local_198[0] == 0) && (pGVar5 == (GmMat43 *)0x1)) {
      pSVar18 = (SQuat_6 *)0x0;
      pCVar17 = (CClassicArchive *)&stack0xfffffdd3;
      uVar21 = in_stack_fffffdd0 & 0xffffff;
      uVar16 = 0x7f2b30;
      CClassicArchive::DoNat8((CClassicArchive *)param_1,pCVar17,(uchar *)0x1,0,uVar3);
      pGVar19 = (GmQuat *)0x7f2b40;
      uVar3 = (**(code **)(_DAT_00000009 + 0x18))();
      pGVar10 = (GmVec3 *)(uVar3 / 0x3d);
      CClassicArchive::DoNatural
                ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffdc4,(ulong *)0x1,0,
                 in_stack_fffffda0);
      _memset(&fStack_17c,0,0x3d);
      SStateSplit::SStateSplit(auStack_f4,in_stack_fffffda4);
      uStack_14 = 0;
      SStateSplit::Allocate(auStack_f0,in_stack_fffffdcc,uVar16);
      if (*(int *)(param_1 + 8) == 0) {
        SStateSplit::Archive(auStack_ec,(CFastCrypt<unsigned_long> *)param_1,pCVar17);
      }
      fStack_1c4 = (float)(int)param_2;
      uStack_1c0 = 0;
      uStack_1b0 = 0;
      puStack_1ac = (undefined4 *)0x0;
      uStack_1a8 = 0;
      uStack_1a4 = 0;
      if ((int)param_2 < 0) {
        fStack_1c4 = fStack_1c4 + _DAT_00c418d0;
      }
      fStack_1c4 = fStack_1c4 / (float)_DAT_00c418d8;
      uStack_1e8 = 0;
      uStack_1e6 = 0;
      bStack_1e5 = 0;
      uStack_1e4 = 0;
      uStack_1e2 = 0;
      bStack_1e1 = 0;
      SStack_1e0 = (SQuat_6)0x0;
      bStack_1df = 0;
      uStack_1de = 0;
      uStack_1dc = 0;
      uStack_1d8 = 0;
      uStack_1d4 = 0.0;
      uStack_1d0 = 0;
      uStack_1cc = 0;
      uStack_1c8 = 0;
      uStack_1b4 = 0;
      uStack_1b8 = 0;
      pCStack_1bc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      GmQuat::SetIdentity(&uStack_1d4,pGVar5);
      if (in_stack_fffffdd8 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        pCVar14 = (CMwClassInfoCSceneVehicleCar *)&DAT_00000009;
        do {
          if (*(int *)(param_1 + 8) == 0) {
            _memset(&stack0xfffffddc,0,0x3d);
          }
          else {
            (**(code **)(*(int *)pCVar14 + 4))(&stack0xfffffddc);
          }
          puStack_1ac = (undefined4 *)&stack0xfffffddc;
          pCStack_1bc = pCVar11;
          CompressPosition((SCompressPosition *)&uStack_1c0,aSStack_e4,(CClassicArchive *)param_1);
          uStack_1b8 = *puStack_1ac;
          uStack_1b4 = puStack_1ac[1];
          uStack_1b0 = puStack_1ac[2];
          uStack_1e4 = SUB42(pCVar11,0);
          uStack_1e2 = (undefined1)((uint)pCVar11 >> 0x10);
          bStack_1e1 = (byte)((uint)pCVar11 >> 0x18);
          SQuat_6::GetGmQuat(&iStack_218,&SStack_1e0,(GmQuat *)pSVar18);
          CompressRotation((SCompressRotation *)&SStack_1e0,aSStack_e0,(CClassicArchive *)param_1);
          pSVar18 = (SQuat_6 *)&uStack_1dc;
          SQuat_6::SetFromGmQuat(auStack_214,pSVar18,pGVar19);
          uStack_1c8 = uStack_1d8;
          fStack_1c4 = uStack_1d4;
          uStack_1c0 = uStack_1d0;
          pCStack_1bc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)uStack_1cc;
          if (*(int *)(param_1 + 8) != 0) {
            uVar21 = CONCAT31((int3)(uVar21 >> 8),
                              (char)((int)((uStack_1ee >> 0x18) - (uint)bStack_133) / 2) + '\x7f');
            pSVar18 = (SQuat_6 *)0x7f2d7d;
            pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                               (auStack_7c,pCVar11,(ulong)unaff_EDI);
            *pSVar6 = SUB41(in_stack_fffffdd4,0);
            in_stack_fffffdd4 =
                 CONCAT31((int3)(in_stack_fffffdd4 >> 8),
                          (char)((int)((uint)bStack_1e5 - (uint)bStack_12d) / 2) + '\x7f');
            pGVar19 = (GmQuat *)0x7f2dab;
            pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                               (auStack_6c,pCVar11,(ulong)unaff_ESI);
            *pSVar6 = SUB41(in_stack_fffffdd8,0);
            in_stack_fffffdd8 =
                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CONCAT31((int3)((uint)in_stack_fffffdd8 >> 8),
                          (char)((int)((uint)bStack_1df - (uint)bStack_1e1) / 2) + '\x7f');
            unaff_EDI = (GmScaleTrans2 *)0x7f2dd6;
            pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                               (auStack_5c,pCVar11,(ulong)pGVar10);
            *pSVar6 = SUB41(in_stack_fffffddc,0);
            in_stack_fffffddc =
                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CONCAT31((int3)((uint)in_stack_fffffddc >> 8),
                          (char)((int)((uStack_1dc >> 0x18) - (uint)bStack_1df) / 2) + '\x7f');
            unaff_ESI = (GmIso4 *)0x7f2e01;
            pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                               (auStack_4c,pCVar11,(ulong)unaff_EBX);
            *pSVar6 = SUB41(in_stack_fffffde0,0);
          }
          pGVar10 = (GmVec3 *)0x7f2e15;
          pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                             (auStack_6c,pCVar11,(ulong)in_stack_fffffdcc);
          uStack_1d8._0_2_ =
               CONCAT11(((char)*pSVar6 + -0x7f) * '\x02' + cStack_11f,(undefined1)uStack_1d8);
          unaff_EBX = (GmScaleTrans2 *)0x7f2e33;
          pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                             (auStack_5c,pCVar11,uVar21);
          uStack_1d4 = (float)CONCAT13(((char)*pSVar6 + -0x7f) * '\x02' + uStack_11c._3_1_,
                                       (undefined3)uStack_1d4);
          in_stack_fffffdcc = (SStateSplit *)0x7f2e51;
          pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                             (auStack_4c,pCVar11,in_stack_fffffdd4);
          uStack_1cc._0_2_ =
               CONCAT11(((char)*pSVar6 + -0x7f) * '\x02' + uStack_1d0._3_1_,(undefined1)uStack_1cc);
          uVar21 = 0x7f2e6d;
          pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                             (auStack_3c,pCVar11,(ulong)in_stack_fffffdd8);
          uStack_1c8 = CONCAT13(((char)*pSVar6 + -0x7f) * '\x02' + uStack_1cc._1_1_,
                                (undefined3)uStack_1c8);
          bVar2 = (byte)pCVar11;
          if (*(int *)(param_1 + 8) == 0) {
            in_stack_fffffdd8 =
                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((uint)pCVar11 >> 3);
            in_stack_fffffdd4 = 0x7f2ee0;
            pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                               (auStack_2c,in_stack_fffffdd8,(ulong)in_stack_fffffddc);
            uStack_1d0._0_3_ =
                 CONCAT12(-((((uint)*(ushort *)pSVar6 & 1 << (bVar2 & 7)) >> (bVar2 & 7) & 0xff) !=
                           0),(undefined2)uStack_1d0);
          }
          else {
            fStack_210 = (float)CONCAT31(fStack_210._1_3_,0x40 < uStack_1d4._2_1_);
            in_stack_fffffdd8 =
                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((uint)pCVar11 >> 3);
            in_stack_fffffdd4 = 0x7f2ea6;
            pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                               (auStack_2c,in_stack_fffffdd8,(ulong)in_stack_fffffddc);
            uVar7 = (ushort)fStack_20c._0_1_;
            fStack_20c = (float)CONCAT22(fStack_20c._2_2_,uVar7);
            uVar9 = (ushort)(1 << (bVar2 & 7));
            *(ushort *)pSVar6 = uVar7 << (bVar2 & 7) & uVar9 | ~uVar9 & *(ushort *)pSVar6;
          }
          if (*(int *)(param_1 + 8) == 0) {
            in_stack_fffffddc =
                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((uint)pCVar11 >> 3);
            in_stack_fffffdd8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7f2f88;
            pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                               (auStack_1c,in_stack_fffffddc,in_stack_fffffde0);
            uStack_1b8 = CONCAT31(uStack_1b8._1_3_,
                                  (char)(((uint)*(ushort *)pSVar6 & 0xf << (bVar2 & 4)) >>
                                        (bVar2 & 4)) << 4);
          }
          else if (((uint)pCVar11 & 3) == 0) {
            fStack_20c = (float)CONCAT31(fStack_20c._1_3_,(byte)pCStack_1bc >> 4);
            in_stack_fffffddc =
                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((uint)pCVar11 >> 3);
            in_stack_fffffdd8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7f2f3a;
            pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                               (auStack_1c,in_stack_fffffddc,in_stack_fffffde0);
            uVar7 = (ushort)fStack_208._0_1_;
            fStack_208 = (float)CONCAT22(fStack_208._2_2_,uVar7);
            uVar9 = (ushort)(0xf << (bVar2 & 4));
            *(ushort *)pSVar6 = uVar7 << (bVar2 & 4) & uVar9 | ~uVar9 & *(ushort *)pSVar6;
          }
          if (*(int *)(param_1 + 8) == 0) {
            uStack_1f6 = uStack_1f6 & 0xff7fff7f | 0x7f007f;
            uStack_1fa = uStack_1fa & 0xffffff | 0x7f000000;
            uStack_1ee = uStack_1ee & 0xafffffff | 0x28000000;
            SQuat_6::GetGmQuat(&iStack_218,(SQuat_6 *)&fStack_17c,(GmQuat *)pSVar18);
            if (pCVar11 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
              SQuat_6::GetGmQuat(auStack_15c,aSStack_110,pGVar19);
              GmQuat::SetInverse(auStack_ec,aGStack_10c,unaff_EDI);
              pSVar18 = (SQuat_6 *)0x7f3049;
              GmQuat::SetMult(auStack_f8,aSStack_e8,(SPlugFaceCull *)&iStack_170,unaff_ESI);
              GmQuat::GetRotation(auStack_f4,(GmQuat *)&stack0xfffffde0,(float *)&uStack_11c,pGVar10
                                 );
              if ((_DAT_00d6d6a0 & 1) == 0) {
                _DAT_00d6d6a0 = _DAT_00d6d6a0 | 1;
                _DAT_00d6d69c = _DAT_00ba33c0;
              }
              iVar8 = DAT_00d09370 + 0x7f;
              iVar12 = 0x7f - DAT_00d09370;
              __ftol2_sse();
              if ((iVar12 < extraout_EAX) && (iVar12 = extraout_EAX, iVar8 <= extraout_EAX)) {
                iVar12 = iVar8;
              }
              fStack_184 = fStack_210 - fStack_158;
              SStack_1e0 = SUB41(iVar12,0);
              fStack_180 = fStack_20c - fStack_154;
              fStack_17c = fStack_208 - fStack_150;
              GmQuat::SetInverse(auStack_178,(GmScaleTrans2 *)apGStack_168,unaff_EBX);
              pGVar20 = pGStack_16c;
              unaff_EBX = apGStack_168[0];
              GmMat3::Set(auStack_1c,pCStack_174,iStack_170);
              pGVar19 = (GmQuat *)0x7f3179;
              GmVec3::SetMult(aSStack_110,aSStack_188,aSStack_24,pGVar20);
              fVar1 = fStack_104 / (_DAT_00d0936c * (float)_DAT_00b59bb8);
              in_stack_fffffddc =
                   (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CONCAT22((short)((uint)fVar1 >> 0x10),in_FPUControlWord);
              iStack_218 = (int)ROUND(fVar1 * (float)_DAT_00b9a8c8 + (float)(uStack_13a >> 0x10));
              uStack_1f2 = CONCAT22((undefined2)iStack_218,(undefined2)uStack_1f2);
              uStack_1ee = CONCAT22((undefined2)iStack_218,(undefined2)iStack_218);
              pCVar14 = in_stack_00000018;
              uStack_1ea = (undefined2)iStack_218;
            }
            pGVar10 = (GmVec3 *)0x3d;
            unaff_ESI = (GmIso4 *)&fStack_210;
            unaff_EDI = (GmScaleTrans2 *)0x7f3237;
            (**(code **)(*(int *)pCVar14 + 8))();
          }
          puVar13 = (undefined4 *)&stack0xfffffddc;
          ppGVar15 = &pGStack_16c;
          for (iVar8 = 0xf; iVar8 != 0; iVar8 = iVar8 + -1) {
            *ppGVar15 = (GmIso4 *)*puVar13;
            puVar13 = puVar13 + 1;
            ppGVar15 = ppGVar15 + 1;
          }
          pCVar11 = pCVar11 + 1;
          *(undefined1 *)ppGVar15 = *(undefined1 *)puVar13;
          pCVar14 = param_1;
        } while (pCVar11 < in_stack_fffffdd8);
      }
      if (*(int *)(param_1 + 8) != 0) {
        SStateSplit::Archive
                  (aSStack_e4,(CFastCrypt<unsigned_long> *)param_1,(CClassicArchive *)pSVar18);
      }
      puStack_8 = (undefined1 *)0xffffffff;
      SStateSplit::~SStateSplit(aSStack_e4,(SStateSplit *)pSVar18);
      ExceptionList = local_c;
      return 1;
    }
  }
  ExceptionList = local_c;
  return 0;
}
}

