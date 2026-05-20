// Class implementation: CFastBuffer_struct_CVisionHmsZone_SCasterCat

// =================================================
// Function: CFastBuffer<struct_CVisionHmsZone::SCasterCat>::SetSizeAtLeast
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009ab9ba) overlaps instruction at (ram,0x009ab9b7)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x009aba98) */
/* WARNING: Removing unreachable block (ram,0x009aba9a) */
/* WARNING: Removing unreachable block (ram,0x009ab958) */
/* WARNING: Removing unreachable block (ram,0x009ab980) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CFastBuffer<struct_CVisionHmsZone::SCasterCat>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  unkbyte10 Var1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  longlong lVar6;
  code *pcVar7;
  undefined1 uVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  char cVar16;
  uint uVar12;
  ushort uVar19;
  int iVar13;
  uint3 uVar17;
  undefined3 uVar18;
  byte *pbVar15;
  int *piVar20;
  undefined4 extraout_ECX;
  int iVar21;
  undefined2 uVar22;
  byte *pbVar23;
  byte bVar24;
  undefined4 *puVar25;
  int unaff_ESI;
  uint *puVar26;
  byte *pbVar27;
  byte *pbVar28;
  uint uVar29;
  undefined1 *puVar30;
  uint *puVar31;
  undefined2 in_ES;
  undefined2 in_SS;
  int in_GS_OFFSET;
  bool bVar32;
  byte in_AF;
  byte bVar33;
  bool bVar34;
  unkbyte10 in_ST0;
  float10 extraout_ST0;
  float10 fVar35;
  unkbyte10 extraout_ST1;
  undefined8 uVar36;
  uint *unaff_retaddr;
  undefined4 in_stack_00000010;
  int in_stack_00000018;
  uint in_stack_0000001c;
  int in_stack_00000020;
  char *pcVar14;
  
  bVar34 = false;
  _DAT_35283523 = _DAT_35283523 - unaff_ESI;
  uVar12 = in_stack_0000001c ^ 0x35743567;
  if ((int)uVar12 < 0) {
    if (0 < (int)uVar12) {
      return;
    }
  }
  else {
    in_AF = 9 < ((byte)uVar12 & 0xf) | in_AF;
    uVar29 = CONCAT31((int3)(uVar12 >> 8),(byte)uVar12 + in_AF * '\x06') & 0xffffff0f;
    uVar12 = CONCAT22((short)(uVar29 >> 0x10),CONCAT11((char)(uVar12 >> 8) + in_AF,(char)uVar29));
  }
  bVar9 = 9 < ((byte)uVar12 & 0xf) | in_AF;
  uVar29 = CONCAT31((int3)(uVar12 >> 8),(byte)uVar12 + bVar9 * '\x06') & 0xffffff0f;
  uVar8 = (undefined1)uVar29;
  piVar20 = (int *)CONCAT22((short)(uVar29 >> 0x10),CONCAT11((char)(uVar12 >> 8) + bVar9,uVar8));
  puVar26 = (uint *)(*(int *)param_1 * 0x3674366e);
  uVar12 = *puVar26;
  *puVar26 = *puVar26 << 0x17;
  uVar5 = (uint)((int)(uVar12 << 0x16) < 0);
  uVar29 = *unaff_retaddr;
  uVar12 = *unaff_retaddr;
  *unaff_retaddr = uVar12 + (int)puVar26 + uVar5;
  pbVar15 = (byte *)CONCAT31((int3)((uint)in_stack_00000010 >> 8),0x37);
  out(0x37,piVar20);
  iVar13 = (uint)(CARRY4(uVar29,(uint)puVar26) || CARRY4(uVar12 + (int)puVar26,uVar5)) + *piVar20;
  if ((int *)*(undefined1 **)(pbVar15 + 0x633cb13c) != &stack0x00000020) {
    out(0x3e,uVar8);
    FUN_009ab8d2();
    return;
  }
  bVar10 = (byte)((uint)&stack0x00000020 >> 8);
  bVar33 = (bVar10 + *pbVar15) - *pbVar15;
  uVar22 = CONCAT11(bVar33 - CARRY1(bVar10,*pbVar15),(char)&stack0x00000020);
  if ((byte)(bVar10 + *pbVar15) < *pbVar15 || bVar33 < CARRY1(bVar10,*pbVar15)) {
    uVar12 = CONCAT31((int3)((uint)piVar20 >> 8),uVar8) ^ 0x356735ea;
    _DAT_31342b13 = (int)puVar26 + *puVar26;
    _DAT_31342b0f = (uint *)((int)unaff_retaddr + iVar13 + 5);
    uVar2 = in(uVar22);
    _DAT_31342b2f = in_SS;
    *(undefined4 *)((int)unaff_retaddr + iVar13 + 1) = uVar2;
    bVar9 = 9 < ((byte)uVar12 & 0xf) | bVar9;
    uVar29 = CONCAT31((int3)(uVar12 >> 8),(byte)uVar12 + bVar9 * '\x06') & 0xffffff0f;
    uVar19 = (ushort)(uVar29 >> 0x10);
    bVar10 = (byte)uVar29;
    cVar16 = (char)(uVar12 >> 8) + bVar9;
    _DAT_31342b2b = CONCAT22(uVar19,CONCAT11(cVar16,bVar10));
    _DAT_31342b27 = in_stack_00000018;
    _DAT_31342b1b = &DAT_31342b2f;
    _DAT_31342b17 = param_2;
    bVar33 = 9 < bVar10 | bVar9;
    bVar10 = bVar10 + bVar33 * '\x06' & 0xf;
    bVar9 = 9 < bVar10 | bVar33;
    uVar12 = CONCAT31((int3)(((uint)uVar19 << 0x10) >> 8),bVar10 + bVar9 * '\x06') & 0xffffff0f;
    Var1 = to_bcd(in_ST0);
    _DAT_31342b1f = pbVar15;
    _DAT_31342b23 = CONCAT22((short)((uint)&stack0x00000020 >> 0x10),uVar22);
    *(unkbyte10 *)_DAT_31342b0f = Var1;
    pbVar15 = (byte *)CONCAT22((short)((uint)in_stack_00000010 >> 0x10),
                               CONCAT11(((char)((uint)in_stack_00000010 >> 8) -
                                        *(char *)CONCAT22((short)(uVar12 >> 0x10),
                                                          CONCAT11(cVar16 + bVar33 + bVar9,
                                                                   (char)uVar12))) - bVar9,0x37));
    puVar26 = _DAT_31342b0f;
  }
  bVar10 = bVar9 * -6 + 0x39 & 0xf;
  _DAT_3e803e0b = _DAT_3e803e0b >> 3;
  bVar33 = 9 < bVar10 | bVar9;
  uVar12 = CONCAT31(0x2839f0,bVar10 + bVar33 * -6) & 0xffff000f;
  iVar13 = CONCAT22((short)(uVar12 >> 0x10),CONCAT11((-0x10 - bVar9) - bVar33,(char)uVar12)) +
           0x6c3f2d3f + (uint)bVar33;
  bVar33 = 9 < ((byte)iVar13 & 0xf) | bVar33;
  uVar12 = CONCAT31((int3)((uint)iVar13 >> 8),(byte)iVar13 + bVar33 * -6) & 0xffffff0f;
  bVar9 = (byte)uVar12;
  pbVar23 = (byte *)CONCAT22((short)(uVar12 >> 0x10),
                             CONCAT11((char)((uint)iVar13 >> 8) - bVar33,bVar9));
  piVar20 = (int *)(in_stack_00000018 + -1);
  if (piVar20 != (int *)0x0 && bVar9 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *pbVar23 = *pbVar23 + (char)&stack0x00000020;
  uVar17 = (uint3)((uint)pbVar23 >> 8);
  bVar9 = bVar9 & *pbVar23;
  puVar31 = (uint *)CONCAT31(uVar17,bVar9);
  *(undefined2 *)puVar31 = in_ES;
  *(byte *)puVar31 = (char)*puVar31 + bVar9;
  *puVar31 = *puVar31 ^ 0xffffff94;
  *(byte *)((int)(puVar31 + 0xc58cc3a) + (int)puVar26) =
       *(byte *)((int)(puVar31 + 0xc58cc3a) + (int)puVar26) ^ (byte)((uint)piVar20 >> 8);
  bVar33 = 9 < bVar9 | bVar33;
  iVar13 = *piVar20;
  puVar31 = (uint *)((longlong)iVar13 * 0x39d539c3);
  cVar16 = *(char *)((int)((uint)(uVar17 >> 8) << 0x10) >> 0x1f);
  pcVar7 = (code *)swi(0x3a);
  uVar36 = (*pcVar7)();
  pbVar23 = (byte *)((ulonglong)uVar36 >> 0x20);
  iVar13 = CONCAT22((short)((uint)pbVar15 >> 0x10),
                    CONCAT11((char)((uint)pbVar15 >> 8) + cVar16 +
                             ((longlong)(int)puVar31 != (longlong)iVar13 * 0x39d539c3),(char)pbVar15
                            )) + 1;
  if (-1 < (int)uVar36 + -0x3d723d4f) {
    *puVar26 = *puVar26 & (uint)puVar31;
    uVar12 = in((short)((ulonglong)uVar36 >> 0x20));
    *puVar31 = uVar12;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(uint *)((int)puVar26 + 0x38323131) = *(uint *)((int)puVar26 + 0x38323131) ^ (uint)puVar31;
  bVar10 = (byte)((ulonglong)uVar36 >> 0x28);
  bVar24 = (byte)iVar13 ^ bVar10;
  pbVar15 = (byte *)CONCAT31((int3)((uint)iVar13 >> 8),bVar24);
  bVar9 = (byte)extraout_ECX ^ *(byte *)((int)puVar26 + -0x17cb28cd);
  iVar21 = CONCAT31((int3)((uint)extraout_ECX >> 8),bVar9);
  pbVar27 = (byte *)_DAT_35cc35c8;
  bVar32 = DAT_35d835d4 < '\0';
  DAT_35d835d4 = DAT_35d835d4 << 1;
  fVar35 = extraout_ST0 / (float10)_DAT_36543650;
  *(uint **)(in_stack_00000020 + -4) = puVar26;
  *(int *)(in_stack_00000020 + -8) = iVar21;
  *(byte **)(in_stack_00000020 + -0xc) = pbVar23;
  *(byte **)(in_stack_00000020 + -0x10) = pbVar15;
  *(int *)(in_stack_00000020 + -0x14) = in_stack_00000020;
  *(ulong *)(in_stack_00000020 + -0x18) = param_2;
  *(byte **)(in_stack_00000020 + -0x1c) = pbVar27;
  *(uint **)(in_stack_00000020 + -0x20) = puVar31;
  bVar11 = (byte)((uint)iVar13 >> 8);
  puVar25 = (undefined4 *)(in_stack_00000020 + -0x20);
  if (bVar32) {
    LOCK();
    bVar33 = *pbVar27;
    *pbVar27 = bVar10;
    pbVar23 = (byte *)CONCAT22((short)((ulonglong)uVar36 >> 0x30),
                               CONCAT11(bVar33,(char)((ulonglong)uVar36 >> 0x20)));
    UNLOCK();
    uVar18 = (undefined3)((uint)puVar26 >> 8);
    bVar10 = pbVar15[(uint)puVar26 & 0xff];
    pcVar14 = (char *)CONCAT31(uVar18,bVar10);
    fVar35 = fVar35 / (float10)*(short *)pbVar27;
    puVar31 = (uint *)((int)puVar31 + -1);
    *pcVar14 = *pcVar14 >> 7;
    bVar34 = (*(uint *)(in_stack_00000020 + -0x20) & 0x400) != 0;
    bVar33 = (*(uint *)(in_stack_00000020 + -0x20) & 0x10) != 0;
    *pbVar15 = *pbVar15 - bVar11;
    *pbVar15 = *pbVar15 ^ bVar11;
    puVar26 = (uint *)(CONCAT31(uVar18,bVar10 - 0x3b) ^ 0x3b);
    puVar25 = (undefined4 *)(in_stack_00000020 + -0x1c);
  }
  *(undefined2 *)(puVar25 + -1) = in_SS;
  pbVar28 = pbVar27 + (uint)bVar34 * -8 + 4;
  out(*(undefined4 *)pbVar27,(short)pbVar23);
  if (puVar26 == (uint *)0x3e033dce) {
    *pbVar28 = *pbVar28 + 1;
    bVar10 = (byte)((uint)pbVar23 >> 8);
    bRam3e033dcf = bRam3e033dcf + bVar10;
    puVar26 = (uint *)(int)(short)CONCAT31(0x3e033d,bRam3e033dcf & 0xcf);
    *(byte *)puVar26 = (char)*puVar26 + (bRam3e033dcf & 0xcf);
    *(byte *)puVar26 = (char)*puVar26 + bVar9;
    pbVar15[0x30] = pbVar15[0x30] ^ bVar10;
    *puVar26 = *puVar26 ^ 0x31133103;
    pbVar23 = pbVar23 + -1;
    *(uint *)(param_2 + 0x31) = *(uint *)(param_2 + 0x31) ^ param_2;
    puVar25 = puVar25 + -1;
  }
  else {
    iVar21 = iVar21 + 1;
    puVar31 = (uint *)((int)puVar31 + -1);
    pbVar28 = (byte *)*puVar25;
    *puVar25 = 0x80367636;
  }
  uVar12 = CONCAT31(0xb36f9,bVar33 * '\x06' + '6') & 0xffffff0f;
  bVar9 = (byte)uVar12;
  uVar29 = *(int *)pbVar28 + 4 + (uint)bVar34 * -8 & *puVar31;
  *(char *)puVar31 = (char)*puVar31 - (char)((uint)pbVar23 >> 8);
  *(uint *)((int)puVar25 + -4) = CONCAT22((short)(uVar12 >> 0x10),CONCAT11(bVar33 - 7,bVar9));
  *(int *)((int)puVar25 + -8) = iVar21;
  *(byte **)((int)puVar25 + -0xc) = pbVar23;
  *(byte **)((int)puVar25 + -0x10) = pbVar15;
  *(undefined4 **)((int)puVar25 + -0x14) = puVar25;
  *(ulong *)((int)puVar25 + -0x18) = param_2;
  *(uint *)((int)puVar25 + -0x1c) = uVar29;
  *(uint **)((int)puVar25 + -0x20) = puVar31;
  bVar33 = 9 < bVar9 | bVar33;
  bVar9 = bVar9 + bVar33 * '\x06' & 0xf;
  uVar12 = in((short)pbVar23);
  *puVar31 = uVar12;
  bVar33 = 9 < bVar9 | bVar33;
  bVar10 = bVar9 + bVar33 * '\x06' & 0xf;
  LOCK();
  bVar9 = *pbVar23;
  DAT_6c380b37 = bVar10;
  *pbVar23 = bVar11;
  UNLOCK();
  bVar33 = 9 < bVar10 | bVar33;
  bVar10 = bVar10 + bVar33 * -6 & 0xf;
  bVar33 = 9 < bVar10 | bVar33;
  puVar30 = (undefined1 *)(uVar29 + 1);
  uVar2 = *(undefined4 *)((int)puVar25 + -0x20);
  bVar10 = 9 < ((byte)uVar2 & 0xf) | 9 < (bVar10 + bVar33 * -6 & 0xf) | bVar33;
  bVar11 = (byte)uVar2 + bVar10 * -6 & 0xf;
  out(*puVar30,(short)pbVar23);
  bVar33 = 9 < bVar11 | bVar10;
  uVar12 = CONCAT31((int3)((uint)uVar2 >> 8),bVar11 + bVar33 * -6) & 0xffff000f;
  bVar11 = (byte)uVar12;
  uVar12 = CONCAT22((short)(uVar12 >> 0x10),
                    CONCAT11(((char)((uint)uVar2 >> 8) - bVar10) - bVar33,bVar11));
  bVar10 = (byte)iVar21;
  uVar17 = (uint3)((uint)iVar21 >> 8);
  if ((POPCOUNT((uint)puVar30 & 0xff) & 1U) == 0) {
    bVar3 = *(byte *)(param_2 + 0xe032cf32);
    bVar4 = *pbVar23;
    uVar12 = uVar12 ^ *(uint *)(in_GS_OFFSET +
                               CONCAT31(uVar17,bVar10 ^ *(byte *)(uVar12 + 0xab329a32)) + 0x1b33dd33
                               );
    uVar29 = uVar12 ^ 0x5500b2;
    DAT_36003592 = DAT_36003592 ^ 0x2b;
    bVar10 = (byte)uVar29;
    bVar33 = 9 < (bVar10 & 0xf) | bVar33;
    uVar29 = CONCAT31((int3)(uVar29 >> 8),bVar10 + bVar33 * '\x06') & 0xffffff0f;
    pbVar15 = (byte *)CONCAT22((short)(uVar29 >> 0x10),
                               CONCAT11((char)(uVar12 >> 8) + bVar33,(char)uVar29));
    *(int *)((int)puVar25 + -0x20) = _DAT_133eef3e;
    *pbVar15 = *pbVar15 | (byte)(CONCAT11(bVar9 ^ bVar3 ^ bVar11,bVar24 ^ bVar4) - 1 >> 8);
    return;
  }
  bVar33 = 9 < (bVar10 & 0xf) | bVar33;
  bVar10 = bVar10 + bVar33 * -6 & 0xf;
  bVar34 = 9 < bVar10 || (*(uint *)((int)puVar25 + -0x1c) & 0x10) != 0;
  uVar12 = CONCAT31((int3)(((uint)(uVar17 >> 8) << 0x10) >> 8),bVar10 + bVar34 * -6) & 0xffffff0f;
  _DAT_133eef3e = (longlong)ROUND(fVar35);
  lVar6 = CONCAT44(pbVar23,CONCAT22((short)(uVar12 >> 0x10),
                                    CONCAT11(((char)((uint)iVar21 >> 8) - bVar33) - bVar34,
                                             (char)uVar12))) / (longlong)_DAT_133eef3e;
  pcVar14 = (char *)((int)lVar6 + 0x22);
  *pcVar14 = *pcVar14 + (char)lVar6;
  pcVar14 = (char *)((int)lVar6 * 2 + 0x30080000);
  *pcVar14 = *pcVar14 + bVar9;
  Var1 = to_bcd(extraout_ST1);
  *(unkbyte10 *)CONCAT31((int3)((ulonglong)lVar6 >> 8),(char)lVar6 + -0x30) = Var1;
  pcVar7 = (code *)swi(1);
  (*pcVar7)();
  return;
}
}

