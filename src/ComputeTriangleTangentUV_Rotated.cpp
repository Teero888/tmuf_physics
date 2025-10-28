
/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* unsigned long __cdecl ComputeTriangleTangentUV_Rotated(struct
   GmVec3::STri_PosTexTgt &,unsigned long) */

ulong __cdecl ComputeTriangleTangentUV_Rotated(STri_PosTexTgt *param_1,
                                               ulong param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  bool bVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  uint uVar16;

  pfVar5 = *(float **)
            (param_1 +
            (int)(&`unsigned_long___cdecl_ComputeTriangleTangentUV_Rotated(struct_GmVec3::STri_PosTe xTgt&,unsigned_long)'
                   ::`2'::RotIndexs)[param_2 * 3] * 4);
  pfVar6 = *(float **)
            (param_1 +
            (int)(&`unsigned_long___cdecl_ComputeTriangleTangentUV_Rotated(struct_GmVec3::STri_PosTe xTgt&,unsigned_long)'
                   ::`2'::RotIndexs)[param_2 * 3] * 4 + 0xc);
  pfVar7 = *(float **)(param_1 + *(int *)(&DAT_00d1a8cc + param_2 * 0xc) * 4);
  fVar1 = *pfVar7;
  fVar2 = *pfVar5;
  pfVar8 = *(float **)(param_1 + *(int *)(&DAT_00d1a8d0 + param_2 * 0xc) * 4);
  fVar10 = **(float **)(param_1 + *(int *)(&DAT_00d1a8cc + param_2 * 0xc) * 4 + 0xc) - *pfVar6;
  fVar11 = (*(float **)(param_1 + *(int *)(&DAT_00d1a8cc + param_2 * 0xc) * 4 + 0xc))[1] - pfVar6[1]
  ;
  fVar3 = *pfVar8;
  fVar4 = *pfVar5;
  fVar12 = **(float **)(param_1 + *(int *)(&DAT_00d1a8d0 + param_2 * 0xc) * 4 + 0xc) - *pfVar6;
  fVar13 = (*(float **)(param_1 + *(int *)(&DAT_00d1a8d0 + param_2 * 0xc) * 4 + 0xc))[1] - pfVar6[1]
  ;
  fVar14 = fVar10 * fVar13 - fVar11 * fVar12;
  bVar9 = _DAT_00d1a8f0 < ABS(fVar14) == (NAN(_DAT_00d1a8f0) || NAN(ABS(fVar14)));
  if (bVar9) {
    fVar1 = 0.0;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else {
    *(float *)(param_1 + 0x18) =
        -(fVar11 * (fVar3 - fVar4) - fVar13 * (fVar1 - fVar2)) / fVar14;
    fVar1 = -(fVar12 * (fVar1 - fVar2) - fVar10 * (fVar3 - fVar4)) / fVar14;
  }
  uVar16 = (uint)!bVar9;
  *(float *)(param_1 + 0x24) = fVar1;
  fVar15 = _DAT_00d1a8f0;
  fVar1 = pfVar7[1];
  fVar2 = pfVar5[1];
  fVar3 = pfVar8[1];
  fVar4 = pfVar5[1];
  if (_DAT_00d1a8f0 < ABS(fVar14) == (NAN(_DAT_00d1a8f0) || NAN(ABS(fVar14)))) {
    fVar1 = 0.0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  else {
    uVar16 = uVar16 | 2;
    *(float *)(param_1 + 0x1c) =
        -(fVar11 * (fVar3 - fVar4) - fVar13 * (fVar1 - fVar2)) / fVar14;
    fVar1 = -(fVar12 * (fVar1 - fVar2) - fVar10 * (fVar3 - fVar4)) / fVar14;
  }
  *(float *)(param_1 + 0x28) = fVar1;
  fVar1 = pfVar7[2];
  fVar2 = pfVar5[2];
  fVar3 = pfVar8[2];
  fVar4 = pfVar5[2];
  if (fVar15 < ABS(fVar14)) {
    *(float *)(param_1 + 0x20) =
        -((fVar3 - fVar4) * fVar11 - (fVar1 - fVar2) * fVar13) / fVar14;
    *(float *)(param_1 + 0x2c) =
        -(fVar12 * (fVar1 - fVar2) - fVar10 * (fVar3 - fVar4)) / fVar14;
    return uVar16 | 4;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return uVar16;
}
