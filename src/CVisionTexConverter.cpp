// Class implementation: CVisionTexConverter

// =================================================
// Function: CVisionTexConverter::GetImage
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009b517d) overlaps instruction at (ram,0x009b517c)
    */
/* WARNING: Removing unreachable block (ram,0x009b5172) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CPlugFileImg * __thiscall
CVisionTexConverter::GetImage(CVisionTexConverter *this,CVisionTexConverter *param_1)
{
{
  int iVar1;
  bool bVar2;
  byte bVar3;
  ulonglong uVar4;
  short sVar5;
  char cVar6;
  short sVar7;
  undefined4 in_EAX;
  uint uVar8;
  byte *pbVar9;
  char cVar13;
  byte *pbVar11;
  uint *puVar12;
  byte bVar14;
  byte bVar15;
  byte bVar17;
  int in_EDX;
  undefined2 uVar18;
  int iVar16;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  byte *pbVar19;
  int *unaff_EDI;
  uint *puVar20;
  char *pcVar21;
  byte in_AF;
  undefined1 auStack_4 [4];
  uint uVar10;
  
  bVar3 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  uVar8 = CONCAT31((int3)((uint)in_EAX >> 8),(byte)in_EAX + bVar3 * -6) & 0xffffff0f;
  cVar6 = (char)uVar8;
  bVar15 = (byte)unaff_EBX;
  puVar20 = (uint *)*(undefined6 *)(*unaff_EDI * 0x3f883f76);
  bVar14 = (byte)in_EDX;
  puVar12 = (uint *)CONCAT31((int3)(CONCAT22((short)(uVar8 >> 0x10),
                                             CONCAT11((char)((uint)in_EAX >> 8) - bVar3,cVar6)) >> 8
                                   ),cVar6 + bVar14);
  pbVar9 = (byte *)((uint)puVar12 ^ *puVar12);
  pbVar9[-0x201000] = pbVar9[-0x201000] + (byte)pbVar9;
  *(char *)(in_EDX + -0x4ecf5ad0) = *(char *)(in_EDX + -0x4ecf5ad0) + bVar15;
  pbVar11 = (byte *)CONCAT31((int3)(CONCAT22((short)((uint)unaff_EBX >> 0x10),CONCAT11(0x3f,bVar15))
                                   >> 8),bVar15 ^ (byte)pbVar9);
  *pbVar11 = *pbVar11 ^ (byte)((uint)pbVar9 >> 8);
  uVar18 = (undefined2)((uint)in_EDX >> 0x10);
  bVar17 = (byte)((uint)in_EDX >> 8) ^ *pbVar9;
  bVar15 = bVar14 ^ (byte)*puVar20;
  uVar8 = CONCAT31((int3)(CONCAT22(uVar18,CONCAT11(bVar17,bVar14)) >> 8),bVar15);
  pbVar9 = (byte *)((uint)pbVar9 ^ 0x35b73570);
  pbVar19 = (byte *)_DAT_39e13776;
  if (uVar8 <= *(uint *)(uVar8 + 0x3a)) {
    pcVar21 = (char *)((int)puVar20 + 1);
    bVar3 = 9 < ((byte)unaff_EBP & 0xf) | bVar3;
    uVar10 = CONCAT31((int3)((uint)unaff_EBP >> 8),(byte)unaff_EBP + bVar3 * -6) & 0xffffff0f;
    sVar7 = CONCAT11((char)((uint)unaff_EBP >> 8) - bVar3,(char)uVar10);
    sVar5 = (short)*pcVar21;
    cVar6 = (char)(sVar7 / sVar5);
    cVar13 = (char)(sVar7 % sVar5);
    puVar12 = (uint *)CONCAT31((int3)(CONCAT22((short)(uVar10 >> 0x10),CONCAT11(cVar13,cVar6)) >> 8)
                               ,cVar6 + cVar13);
    pbVar9 = (byte *)((uint)puVar12 ^ *puVar12);
    puVar20 = (uint *)((int)puVar20 + 2);
    cVar6 = in((short)uVar8);
    *pcVar21 = cVar6;
    *pbVar9 = *pbVar9 + (char)pbVar9;
    *pbVar11 = *pbVar11 + (char)((uint)pbVar9 >> 8);
    pbVar9[(int)pbVar19] = pbVar9[(int)pbVar19] ^ (byte)((uint)this >> 8);
  }
  bVar17 = bVar17 ^ *pbVar9;
  iVar16 = CONCAT22(uVar18,CONCAT11(bVar17,bVar15));
  if ((char)bVar17 < '\0') {
    *(int *)pbVar9 = *(int *)pbVar9 >> 0x17;
  }
  else {
    *pbVar19 = *pbVar19 ^ (byte)pbVar9 ^ 0x3f;
    pbVar19 = (byte *)((uint)pbVar19 ^ (uint)pbVar9 ^ 0x3f);
    pbVar11 = (byte *)((uint)pbVar9 ^ 0x35733518);
    DAT_35ae35a1 = DAT_35ae35a1 ^ 0x33;
    iVar16 = CONCAT31((int3)((uint)iVar16 >> 8),bVar15 ^ (byte)*this) + 1;
    bVar3 = (byte)this & 0x1f;
    iVar1 = *(int *)pbVar19;
    *(int *)pbVar19 = *(int *)pbVar19 << bVar3;
    bVar2 = ((uint)this & 0x1f) != 0 && iVar1 << bVar3 - 1 < 0;
    this = this + -1;
    puVar12 = puVar20;
    if (this != (CVisionTexConverter *)0x0) goto LAB_009b5176;
    bVar14 = (byte)((uint)iVar16 >> 8);
    uVar8 = *puVar20;
    bVar3 = bVar14 + (char)*puVar20;
    *(ushort *)puVar20 =
         (short)*puVar20 +
         (ushort)(CARRY1(bVar14,(byte)*puVar20) || CARRY1(bVar3,bVar2)) *
         (((ushort)pbVar19 & 3) - ((ushort)*puVar20 & 3));
    if (SCARRY1(bVar14,(char)uVar8) == SCARRY1(bVar3,bVar2)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar8 = *puVar20;
    *puVar20 = *puVar20;
    uVar4 = CONCAT44(CONCAT22((short)((uint)iVar16 >> 0x10),CONCAT11((char)uVar8,(char)iVar16)),
                     pbVar9) ^ 0x35733518;
    puVar12 = (uint *)(uVar4 / *puVar20);
    iVar16 = (int)(uVar4 % (ulonglong)*puVar20);
    puVar20 = (uint *)((uint)puVar20 ^ *puVar12);
    pbVar9 = (byte *)((int)puVar12 + 1);
  }
  LOCK();
  puVar12 = *(uint **)this;
  *(uint **)this = puVar20;
  UNLOCK();
  _DAT_153adc3a = pbVar9;
  *(uint *)pbVar19 =
       (*(int *)pbVar19 - (int)puVar12) - (uint)(this < *(CVisionTexConverter **)(pbVar19 + 0x3b));
  pbVar11 = pbVar9 + 0x4ac15cc2;
  *pbVar19 = (char)*pbVar19 >> ((byte)this & 0x1f);
LAB_009b5176:
  puVar20 = (uint *)CONCAT31((int3)((uint)pbVar11 >> 8),(char)pbVar11 + (char)((uint)iVar16 >> 8));
  pcVar21 = (char *)((uint)puVar20 ^ *puVar20);
  *pcVar21 = *pcVar21 + (byte)pcVar21;
  *(char *)puVar12 = (char)*puVar12 + (char)((uint)this >> 8);
  pbVar19[0x5530dd30] = pbVar19[0x5530dd30] ^ (byte)pcVar21;
  *(uint *)this = *(uint *)this ^ (uint)auStack_4;
  *puVar12 = *puVar12 ^ 0x37a3378d;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: CVisionTexConverter::GetPixels
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009b5362) overlaps instruction at (ram,0x009b5361)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uchar * __thiscall
CVisionTexConverter::GetPixels
          (CVisionTexConverter *this,CVisionTexConverter *param_1,ulong param_2,ulong param_3,
          ulong *param_4,GmNat3 *param_5)
{
{
  CVisionTexConverter CVar1;
  int *piVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  code *pcVar10;
  undefined6 uVar11;
  byte bVar12;
  byte bVar13;
  char cVar14;
  undefined4 in_EAX;
  undefined4 uVar15;
  uint *puVar17;
  undefined3 uVar20;
  uint uVar18;
  uint uVar19;
  CVisionTexConverter *pCVar21;
  int extraout_ECX;
  byte bVar22;
  byte bVar23;
  byte *in_EDX;
  int unaff_EBX;
  int iVar24;
  int iVar25;
  byte *pbVar26;
  int unaff_EBP;
  uint *unaff_ESI;
  uint *puVar27;
  int *unaff_EDI;
  undefined1 *puVar28;
  byte in_AF;
  bool in_ZF;
  bool in_SF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined8 uVar29;
  uint uStack_4;
  char *pcVar16;
  
  pCVar21 = this + -1;
  if (pCVar21 == (CVisionTexConverter *)0x0 || in_ZF == false) {
    uVar8 = CONCAT44(in_EDX,in_EAX) / (ulonglong)_DAT_36643646;
    uVar15 = (undefined4)uVar8;
    in_EDX = (byte *)(CONCAT44(in_EDX,in_EAX) % (ulonglong)_DAT_36643646);
    if (in_ZF) goto LAB_009b52a6;
    if (!in_SF) {
      *unaff_ESI = *unaff_ESI ^ 0xffffff91;
      piVar2 = (int *)((int)unaff_EDI + 1);
      *(char *)unaff_EDI = (char)uVar8;
      *(undefined2 *)piVar2 = *(undefined2 *)piVar2;
      pCVar21 = this + -2;
      unaff_EDI = piVar2;
      goto LAB_009b52b7;
    }
  }
  else {
    bVar12 = (byte)in_EAX;
    uVar15 = CONCAT31((int3)(CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(bVar12 / 0x3b,bVar12))
                            >> 8),bVar12 % 0x3b);
LAB_009b52a6:
    unaff_EBX = CONCAT22((short)((uint)unaff_EBX >> 0x10),
                         CONCAT11((byte)((uint)unaff_EBX >> 8) | (byte)*pCVar21,(char)unaff_EBX));
  }
  *(uint *)(in_EDX + (int)unaff_ESI) = *(uint *)(in_EDX + (int)unaff_ESI) & (uint)unaff_EDI;
LAB_009b52b7:
  *unaff_EDI = (int)unaff_EDI + (uint)((byte)*unaff_ESI < 0xa6) + *unaff_EDI;
  bVar7 = 9 < ((byte)uVar15 & 0xf);
  bVar22 = bVar7 | in_AF;
  bVar12 = (byte)uVar15 + bVar22 * '\x06';
  bVar6 = 9 < (bVar12 & 0xf);
  bVar22 = bVar6 | bVar22;
  bVar13 = bVar12 + bVar22 * -6 & 0xf;
  iVar24 = *unaff_EDI;
  bVar12 = 9 < bVar13 | bVar22;
  uVar18 = CONCAT31((int3)((uint)uVar15 >> 8),bVar13 + bVar12 * -6) & 0xffff000f;
  cVar14 = (char)uVar18;
  pcVar16 = (char *)CONCAT22((short)(uVar18 >> 0x10),
                             CONCAT11(((char)((uint)uVar15 >> 8) - bVar22) - bVar12,cVar14));
  *pcVar16 = *pcVar16 + cVar14;
  *pcVar16 = *pcVar16 + (byte)in_EDX;
  puVar17 = (uint *)((uint)pcVar16 & 0xffffff00);
  *(char *)puVar17 = (char)*puVar17;
  uVar18 = *puVar17;
  uVar19 = *puVar17;
  uVar4 = *puVar17;
  uVar5 = (int)unaff_ESI + uVar19 + *puVar17;
  bVar22 = bVar12 * '\x06';
  uVar20 = (undefined3)((uint)pcVar16 >> 8);
  *(byte *)(unaff_EBP + 0x30) = *(byte *)(unaff_EBP + 0x30) ^ (byte)in_EDX;
  bVar23 = (byte)((uint)in_EDX >> 8);
  *pCVar21 = (CVisionTexConverter)((byte)*pCVar21 | bVar23);
  CVar1 = *pCVar21;
  *pCVar21 = (CVisionTexConverter)((char)*pCVar21 + bVar23);
  puVar27 = (uint *)(uVar5 + CARRY4((uint)unaff_ESI,uVar18) & *(uint *)pCVar21 ^ *(uint *)pCVar21);
  puVar17 = (uint *)(unaff_EBP + 0x31);
  *puVar17 = *puVar17 ^ (uint)puVar27;
  uStack_4 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
             (uint)((int)*puVar17 < 0) * 0x80 | (uint)(*puVar17 == 0) * 0x40 |
             (uint)(byte)(9 < bVar13 | bVar6 | bVar7 | in_AF & 1) * 0x10 |
             (uint)((POPCOUNT(*puVar17 & 0xff) & 1U) == 0) * 4 | (uint)(in_ID & 1) * 0x200000 |
             (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
             (uint)(in_AC & 1) * 0x40000;
  *(uint *)(in_EDX + (int)puVar27) = *(uint *)(in_EDX + (int)puVar27) ^ (uint)&uStack_4;
  *in_EDX = *in_EDX - bVar23;
  *in_EDX = *in_EDX ^ bVar23;
  uVar18 = CONCAT31(uVar20,(bVar22 + (0x90 < (bVar22 & 0xf0) |
                                     (CARRY4((int)unaff_ESI + uVar19,uVar4) ||
                                     CARRY4(uVar5,(uint)CARRY4((uint)unaff_ESI,uVar18))) |
                                     bVar12 * (0xf9 < bVar22)) * '`' + 0x31 | 0x31) +
                           CARRY1((byte)CVar1,bVar23) + -1) ^ 0x32;
  uVar3 = *(undefined1 *)(unaff_EBX + 0x33);
  puVar28 = (undefined1 *)
            (iVar24 * -0x5e + 1U ^ *(uint *)((int)&ProcessEnvironmentBlock + uVar18 + 3));
  *(int *)(puVar28 + -0x6ecba0cc) = *(int *)(puVar28 + -0x6ecba0cc) + (int)puVar27;
  *puVar27 = *puVar27 << ((byte)(pCVar21 + 1) & 0x1f);
  uVar8 = CONCAT44(CONCAT31((int3)((uint)in_EDX >> 8),uVar3),CONCAT31(uVar20,(char)uVar18)) ^
          0x3203690328;
  uVar9 = uVar8 % (ulonglong)*puVar27;
  uVar18 = (uint)(uVar8 / *puVar27) & 0xc737b137;
  bVar12 = 9 < ((byte)uVar18 & 0xf) | bVar12;
  uVar19 = CONCAT31((int3)(uVar18 >> 8),(byte)uVar18 + bVar12 * '\x06') & 0xffffff0f;
  _DAT_c739b339 =
       CONCAT22((short)(uVar19 >> 0x10),CONCAT11((char)(uVar18 >> 8) + bVar12,(char)uVar19)) +
       -0x7cc7ddc8;
  iVar24 = CONCAT22((short)((uint)unaff_EBX >> 0x10),CONCAT11(*(undefined1 *)uVar9,(char)unaff_EBX))
  ;
  iVar25 = iVar24 + 1;
  *puVar27 = (uint)(puVar28 + *puVar27);
  out((char)*puVar27,(short)uVar9);
  *(undefined4 *)((int)puVar27 + 1) = puVar28;
  uVar18 = (int)puVar27 + 2;
  *puVar28 = *(undefined1 *)((int)puVar27 + 1);
  pcVar10 = (code *)swi(0x3f);
  uVar29 = (*pcVar10)();
  pcVar16 = (char *)uVar29;
  *pcVar16 = *pcVar16 + (char)uVar29;
  *pcVar16 = *pcVar16 + (char)((ulonglong)uVar29 >> 8);
  uVar11 = *(undefined6 *)pcVar16;
  bVar12 = (byte)uVar11;
  *(char *)uVar11 = *(char *)uVar11 + bVar12;
  pbVar26 = (byte *)(iVar24 + -0x44cf5dcf);
  bVar22 = (byte)((ulonglong)uVar29 >> 0x20);
  *pbVar26 = *pbVar26 ^ bVar22;
  pbVar26 = (byte *)CONCAT31((int3)((uint)iVar25 >> 8),(byte)iVar25 ^ bVar12 ^ 0x30);
  *pbVar26 = *pbVar26 ^ bVar22;
  *(uint *)(extraout_ECX + uVar18) = *(uint *)(extraout_ECX + uVar18) ^ uVar18;
  puVar17 = (uint *)(extraout_ECX + 0x73 + uVar18);
  *puVar17 = *puVar17 ^ (uint)&stack0xffffffef;
  *(uint *)(pbVar26 + -0x40ce5dce) =
       *(uint *)(pbVar26 + -0x40ce5dce) ^ (uint)((ulonglong)uVar29 >> 0x20);
  *(uint *)(pbVar26 + 1) =
       *(uint *)(pbVar26 + 1) ^
       CONCAT31((int3)(CONCAT22((short)((uint6)uVar11 >> 0x10),
                                CONCAT11((byte)((uint6)uVar11 >> 8) ^ (byte)extraout_ECX,bVar12)) >>
                      8),bVar12 ^ 0x30 ^ (byte)((ulonglong)uVar29 >> 0x28));
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: CVisionTexConverter::HeightToBumpNormal
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009b517d) overlaps instruction at (ram,0x009b517c)
    */
/* WARNING: Removing unreachable block (ram,0x009b5172) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionTexConverter::HeightToBumpNormal
          (CVisionTexConverter *this,CVisionTexConverter *param_1,ENormalFormat param_2,
          GxRGBAColor *param_3)
{
{
  int iVar1;
  bool bVar2;
  byte bVar3;
  ulonglong uVar4;
  short sVar5;
  char cVar6;
  short sVar7;
  byte *in_EAX;
  byte *pbVar8;
  char cVar13;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  byte bVar14;
  byte bVar16;
  int in_EDX;
  undefined2 uVar17;
  int iVar15;
  undefined4 unaff_EBX;
  byte *pbVar18;
  undefined4 unaff_EBP;
  byte *pbVar19;
  uint *unaff_EDI;
  char *pcVar20;
  byte in_AF;
  uint uVar9;
  
  in_EAX[-0x201000] = in_EAX[-0x201000] + (byte)in_EAX;
  *(char *)(in_EDX + -0x4ecf5ad0) = *(char *)(in_EDX + -0x4ecf5ad0) + (byte)unaff_EBX;
  pbVar18 = (byte *)CONCAT31((int3)((uint)unaff_EBX >> 8),(byte)unaff_EBX ^ (byte)in_EAX);
  *pbVar18 = *pbVar18 ^ (byte)((uint)in_EAX >> 8);
  uVar17 = (undefined2)((uint)in_EDX >> 0x10);
  bVar16 = (byte)((uint)in_EDX >> 8) ^ *in_EAX;
  bVar14 = (byte)in_EDX ^ (byte)*unaff_EDI;
  uVar10 = CONCAT31((int3)(CONCAT22(uVar17,CONCAT11(bVar16,(byte)in_EDX)) >> 8),bVar14);
  pbVar8 = (byte *)((uint)in_EAX ^ 0x35b73570);
  pbVar19 = (byte *)_DAT_39e13776;
  if (uVar10 <= *(uint *)(uVar10 + 0x3a)) {
    pcVar20 = (char *)((int)unaff_EDI + 1);
    bVar3 = 9 < ((byte)unaff_EBP & 0xf) | in_AF;
    uVar9 = CONCAT31((int3)((uint)unaff_EBP >> 8),(byte)unaff_EBP + bVar3 * -6) & 0xffffff0f;
    sVar7 = CONCAT11((char)((uint)unaff_EBP >> 8) - bVar3,(char)uVar9);
    sVar5 = (short)*pcVar20;
    cVar6 = (char)(sVar7 / sVar5);
    cVar13 = (char)(sVar7 % sVar5);
    puVar11 = (uint *)CONCAT31((int3)(CONCAT22((short)(uVar9 >> 0x10),CONCAT11(cVar13,cVar6)) >> 8),
                               cVar6 + cVar13);
    pbVar8 = (byte *)((uint)puVar11 ^ *puVar11);
    unaff_EDI = (uint *)((int)unaff_EDI + 2);
    cVar6 = in((short)uVar10);
    *pcVar20 = cVar6;
    *pbVar8 = *pbVar8 + (char)pbVar8;
    *pbVar18 = *pbVar18 + (char)((uint)pbVar8 >> 8);
    pbVar8[(int)pbVar19] = pbVar8[(int)pbVar19] ^ (byte)((uint)this >> 8);
  }
  bVar16 = bVar16 ^ *pbVar8;
  iVar15 = CONCAT22(uVar17,CONCAT11(bVar16,bVar14));
  if ((char)bVar16 < '\0') {
    *(int *)pbVar8 = *(int *)pbVar8 >> 0x17;
  }
  else {
    bVar16 = (byte)pbVar8 ^ (byte)((uint)unaff_EBX >> 8);
    uVar10 = CONCAT31((int3)((uint)pbVar8 >> 8),bVar16);
    *pbVar19 = *pbVar19 ^ bVar16;
    pbVar19 = (byte *)((uint)pbVar19 ^ uVar10);
    pbVar8 = (byte *)(uVar10 ^ 0x35733527);
    DAT_35ae35a1 = DAT_35ae35a1 ^ 0x33;
    iVar15 = CONCAT31((int3)((uint)iVar15 >> 8),bVar14 ^ (byte)*this) + 1;
    bVar14 = (byte)this & 0x1f;
    iVar1 = *(int *)pbVar19;
    *(int *)pbVar19 = *(int *)pbVar19 << bVar14;
    bVar2 = ((uint)this & 0x1f) != 0 && iVar1 << bVar14 - 1 < 0;
    this = this + -1;
    puVar11 = unaff_EDI;
    if (this != (CVisionTexConverter *)0x0) goto LAB_009b5176;
    bVar16 = (byte)((uint)iVar15 >> 8);
    uVar9 = *unaff_EDI;
    bVar14 = bVar16 + (char)*unaff_EDI;
    *(ushort *)unaff_EDI =
         (short)*unaff_EDI +
         (ushort)(CARRY1(bVar16,(byte)*unaff_EDI) || CARRY1(bVar14,bVar2)) *
         (((ushort)pbVar19 & 3) - ((ushort)*unaff_EDI & 3));
    if (SCARRY1(bVar16,(char)uVar9) == SCARRY1(bVar14,bVar2)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar9 = *unaff_EDI;
    *unaff_EDI = *unaff_EDI;
    uVar4 = CONCAT44(CONCAT22((short)((uint)iVar15 >> 0x10),CONCAT11((char)uVar9,(char)iVar15)),
                     uVar10) ^ 0x35733527;
    puVar11 = (uint *)(uVar4 / *unaff_EDI);
    iVar15 = (int)(uVar4 % (ulonglong)*unaff_EDI);
    unaff_EDI = (uint *)((uint)unaff_EDI ^ *puVar11);
    pbVar8 = (byte *)((int)puVar11 + 1);
  }
  LOCK();
  puVar11 = *(uint **)this;
  *(uint **)this = unaff_EDI;
  UNLOCK();
  _DAT_153adc3a = pbVar8;
  *(uint *)pbVar19 =
       (*(int *)pbVar19 - (int)puVar11) - (uint)(this < *(CVisionTexConverter **)(pbVar19 + 0x3b));
  pbVar8 = pbVar8 + 0x4ac15cc2;
  *pbVar19 = (char)*pbVar19 >> ((byte)this & 0x1f);
LAB_009b5176:
  puVar12 = (uint *)CONCAT31((int3)((uint)pbVar8 >> 8),(char)pbVar8 + (char)((uint)iVar15 >> 8));
  pcVar20 = (char *)((uint)puVar12 ^ *puVar12);
  *pcVar20 = *pcVar20 + (byte)pcVar20;
  *(char *)puVar11 = (char)*puVar11 + (char)((uint)this >> 8);
  pbVar19[0x5530dd30] = pbVar19[0x5530dd30] ^ (byte)pcVar20;
  *(uint *)this = *(uint *)this ^ (uint)&stack0x00000000;
  *puVar11 = *puVar11 ^ 0x37a3378d;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: CVisionTexConverter::HeightToDispH01
// =================================================
/* WARNING: Control flow encountered bad instruction data */

void __thiscall
CVisionTexConverter::HeightToDispH01(CVisionTexConverter *this,CVisionTexConverter *param_1)
{
{
  uint *puVar1;
  uint uVar2;
  code *pcVar3;
  undefined6 uVar4;
  byte bVar5;
  char *pcVar6;
  int extraout_ECX;
  byte bVar7;
  undefined2 in_DX;
  int unaff_EBX;
  byte *pbVar8;
  int *unaff_ESI;
  undefined1 *unaff_EDI;
  undefined8 uVar9;
  
  *unaff_ESI = (int)(unaff_EDI + *unaff_ESI);
  out((char)*unaff_ESI,in_DX);
  *(undefined4 *)((int)unaff_ESI + 1) = unaff_EDI;
  uVar2 = (int)unaff_ESI + 2;
  *unaff_EDI = *(undefined1 *)((int)unaff_ESI + 1);
  pcVar3 = (code *)swi(0x3f);
  uVar9 = (*pcVar3)();
  pcVar6 = (char *)uVar9;
  *pcVar6 = *pcVar6 + (char)uVar9;
  *pcVar6 = *pcVar6 + (char)((ulonglong)uVar9 >> 8);
  uVar4 = *(undefined6 *)pcVar6;
  bVar5 = (byte)uVar4;
  *(char *)uVar4 = *(char *)uVar4 + bVar5;
  bVar7 = (byte)((ulonglong)uVar9 >> 0x20);
  *(byte *)(unaff_EBX + -0x44cf5dcf) = *(byte *)(unaff_EBX + -0x44cf5dcf) ^ bVar7;
  pbVar8 = (byte *)CONCAT31((int3)((uint)(unaff_EBX + 1) >> 8),(byte)(unaff_EBX + 1) ^ bVar5 ^ 0x30)
  ;
  *pbVar8 = *pbVar8 ^ bVar7;
  *(uint *)(extraout_ECX + uVar2) = *(uint *)(extraout_ECX + uVar2) ^ uVar2;
  puVar1 = (uint *)(extraout_ECX + 0x73 + uVar2);
  *puVar1 = *puVar1 ^ (uint)&stack0xffffffff;
  *(uint *)(pbVar8 + -0x40ce5dce) =
       *(uint *)(pbVar8 + -0x40ce5dce) ^ (uint)((ulonglong)uVar9 >> 0x20);
  *(uint *)(pbVar8 + 1) =
       *(uint *)(pbVar8 + 1) ^
       CONCAT31((int3)(CONCAT22((short)((uint6)uVar4 >> 0x10),
                                CONCAT11((byte)((uint6)uVar4 >> 8) ^ (byte)extraout_ECX,bVar5)) >> 8
                      ),bVar5 ^ 0x30 ^ (byte)((ulonglong)uVar9 >> 0x28));
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: CVisionTexConverter::InvertYCubeMapFace
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009b55e3) overlaps instruction at (ram,0x009b55e0)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x009b54fe) */

void __thiscall
CVisionTexConverter::InvertYCubeMapFace
          (CVisionTexConverter *this,CVisionTexConverter *param_1,ulong param_2)
{
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  short sVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  byte bVar9;
  byte bVar10;
  char cVar11;
  char *in_EAX;
  char *pcVar12;
  uint uVar13;
  int *piVar14;
  char cVar16;
  int *piVar18;
  undefined1 uVar19;
  byte *in_EDX;
  char *unaff_EBX;
  uint *puVar20;
  int unaff_ESI;
  uint uVar21;
  uint *puVar22;
  byte in_CF;
  byte in_AF;
  bool in_SF;
  undefined1 uStack_1;
  ushort *puVar15;
  byte *pbVar17;
  
  if (in_SF) {
    LOCK();
    cVar11 = *in_EAX;
    *in_EAX = (char)((uint)in_EDX >> 8);
    in_EDX = (byte *)CONCAT22((short)((uint)in_EDX >> 0x10),CONCAT11(cVar11,(char)in_EDX));
    UNLOCK();
    uVar21 = unaff_ESI + *(int *)this + (uint)in_CF;
    *(uint *)this = *(uint *)this & uVar21;
    if (!SBORROW1(cVar11,(char)*this)) {
      *(uint *)(unaff_EBX + 0x33342a32) = *(uint *)(unaff_EBX + 0x33342a32) ^ (uint)in_EDX;
      pcVar12 = (char *)(CONCAT31((int3)((uint)&stack0x00000000 >> 8),0x7e) ^ 0x1d);
      in_EAX = unaff_EBX;
      goto LAB_009b5534;
    }
  }
  else {
    uVar21 = unaff_ESI + 1;
    in_AF = 9 < ((byte)in_EAX & 0xf) | in_AF;
    uVar13 = CONCAT31((int3)((uint)in_EAX >> 8),(byte)in_EAX + in_AF * -6) & 0xffffff0f;
    in_EAX = (char *)CONCAT22((short)(uVar13 >> 0x10),
                              CONCAT11((char)((uint)in_EAX >> 8) - in_AF,(char)uVar13));
    *(int *)in_EDX = *(int *)in_EDX >> 1;
    out(0x3a,in_EAX);
  }
  pcVar12 = (char *)CONCAT31((int3)(CONCAT22((short)((uint)unaff_EBX >> 0x10),
                                             CONCAT11((char)((uint)unaff_EBX >> 8) + *unaff_EBX,
                                                      (char)unaff_EBX)) >> 8),(char)unaff_EBX);
LAB_009b5534:
  bVar9 = (byte)pcVar12;
  *pcVar12 = *pcVar12 + bVar9;
  cVar16 = (char)this + bVar9;
  pbVar17 = (byte *)CONCAT31((int3)((uint)this >> 8),cVar16);
  puVar20 = (uint *)CONCAT31((int3)((uint)in_EAX >> 8),(byte)in_EAX ^ (byte)in_EDX);
  puVar22 = (uint *)CONCAT31((int3)((uint)pcVar12 >> 8),bVar9 ^ *in_EDX);
  uVar13 = *puVar20;
  uVar2 = *puVar22;
  uVar3 = *(uint *)(pbVar17 + -0x2dcc48cd);
  *(byte *)puVar22 = (char)*puVar22 + (bVar9 ^ *in_EDX);
  *pbVar17 = *pbVar17 ^ 0x34;
  uVar6 = (ulonglong)*(uint *)((int)puVar20 + uVar21);
  uVar7 = CONCAT44((uint)in_EDX ^ uVar13,puVar22);
  uVar8 = uVar7 / uVar6;
  bVar9 = 9 < ((byte)uVar8 & 0xf) | in_AF;
  bVar10 = (byte)uVar8 + bVar9 * '\x06' & 0xf;
  bVar4 = 9 < bVar10 | bVar9;
  uVar13 = CONCAT31((int3)(((uint)(uint3)((uint3)(uVar8 >> 8) >> 8) << 0x10) >> 8),
                    bVar10 + bVar4 * '\x06') & 0xffffff0f;
  piVar14 = (int *)CONCAT22((short)(uVar13 >> 0x10),
                            CONCAT11((char)(uVar8 >> 8) + bVar9 + bVar4,(char)uVar13));
  uVar19 = (undefined1)(uVar7 % uVar6);
  cVar11 = in(CONCAT11(0x37,uVar19));
  puVar15 = (ushort *)CONCAT31((int3)((uint)piVar14 >> 8),cVar11);
  uVar1 = *piVar14 + 4;
  *pbVar17 = *pbVar17 + cVar16;
  bVar9 = (byte)((uint)this >> 8);
  pbVar17[0x34] = pbVar17[0x34] + bVar9;
  *(char *)((int)pbVar17 * 2) = *(char *)((int)pbVar17 * 2) + cVar11;
  piVar14 = (int *)CONCAT31(0x703b63,bVar9 + 0x39);
  *(byte *)(uVar21 + 0x35) = *(byte *)(uVar21 + 0x35) ^ bVar9 ^ 0x37;
  *(uint *)((int)piVar14 + -0x2ccd39ce) =
       *(uint *)((int)piVar14 + -0x2ccd39ce) ^ *(int *)puVar15 * -0x2e;
  uVar13 = *(uint *)(CONCAT31((int3)(CONCAT22((short)((uint)this >> 0x10),CONCAT11(bVar9,cVar16)) >>
                                    8),cVar16) ^ 0x37ba);
  sVar5 = ((ushort)uVar1 & 3) - (*puVar15 & 3);
  *puVar15 = *puVar15 + (ushort)(uVar1 < uVar13) * sVar5;
  if (!SBORROW4(uVar1,uVar13)) {
    piVar18 = (int *)((int)puVar15 + -1);
    if (piVar18 == (int *)0x0 || sVar5 < 1) {
      *(undefined1 *)piVar14 = 99;
      *piVar14 = *piVar14 >> 0x1a;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    *piVar18 = *piVar18 << 0x14;
    in(CONCAT11(0x36,uVar19));
  }
  puVar22 = *(uint **)(((uint)&uStack_1 ^ uVar2 ^ uVar3) + 4);
  *puVar22 = *puVar22 ^ 0xffffff98;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: CVisionTexConverter::RxGyBz_To_R0GyBzAx
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009b5362) overlaps instruction at (ram,0x009b5361)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x009b527e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionTexConverter::RxGyBz_To_R0GyBzAx(CVisionTexConverter *this,CVisionTexConverter *param_1)
{
{
  byte *pbVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  code *pcVar8;
  undefined6 uVar9;
  uint uVar10;
  undefined1 uVar11;
  byte bVar12;
  byte bVar13;
  char cVar14;
  byte bVar15;
  undefined4 uVar16;
  uint uVar17;
  uint *puVar19;
  undefined3 uVar21;
  uint uVar20;
  uint *puVar22;
  int extraout_ECX;
  byte bVar24;
  uint *in_EDX;
  byte *pbVar23;
  int unaff_EBX;
  int *piVar25;
  uint uVar26;
  int iVar27;
  int iVar28;
  uint uVar29;
  undefined1 *puVar30;
  undefined1 *puVar31;
  int unaff_EBP;
  uint *unaff_ESI;
  uint *puVar32;
  uint unaff_EDI;
  byte *pbVar33;
  undefined1 *puVar34;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined8 uVar35;
  undefined4 uStack_4;
  char *pcVar18;
  
  *in_EDX = *in_EDX ^ unaff_EDI;
  piVar25 = (int *)(unaff_EBX + 1);
  pbVar33 = (byte *)((unaff_EDI - *piVar25) + *unaff_ESI + (uint)(_DAT_d33ab73a + 1U < 0x3d2e3d22));
  *(byte *)unaff_ESI = (byte)*unaff_ESI & (byte)((uint)piVar25 >> 8);
  uVar16 = in((short)in_EDX);
  bVar3 = 9 < ((byte)uVar16 & 0xf);
  bVar15 = bVar3 | in_AF;
  uVar20 = CONCAT31((int3)((uint)uVar16 >> 8),(byte)uVar16 + bVar15 * -6) & 0xffffff0f;
  uVar11 = (undefined1)uVar20;
  uStack_4 = 0x3f;
  if (this != (CVisionTexConverter *)0x0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar29 = (uint)&uStack_4 ^ *(uint *)(unaff_EBX + -0x22cc33cc);
  uVar26 = (uint)piVar25 ^ *unaff_ESI;
  uVar20 = CONCAT31((int3)(CONCAT22((short)(uVar20 >> 0x10),
                                    CONCAT11((char)((uint)uVar16 >> 8) - bVar15,uVar11)) >> 8),
                    uVar11);
  uVar17 = uVar20 ^ 0x35e135d1;
  uVar6 = CONCAT44(in_EDX,uVar20) ^ 0x35e135d1;
  uVar7 = uVar6 / _DAT_36643646;
  uVar6 = uVar6 % (ulonglong)_DAT_36643646;
  pbVar23 = (byte *)uVar6;
  *(undefined4 *)(uVar29 - 4) = 0x70366c36;
  bVar12 = (byte)uVar7;
  if (uVar17 == 0) {
    uVar26 = CONCAT22((short)(uVar26 >> 0x10),
                      CONCAT11((byte)(uVar26 >> 8) | DAT_00000000,(char)uVar26));
  }
  else if (-1 < (int)uVar17) {
    *unaff_ESI = *unaff_ESI ^ 0xffffff91;
    pbVar1 = pbVar33 + 1;
    *pbVar33 = bVar12;
    *(undefined2 *)pbVar1 = *(undefined2 *)pbVar1;
    puVar22 = (uint *)0xffffffff;
    pbVar33 = pbVar1;
    goto LAB_009b52b5;
  }
  *(uint *)(pbVar23 + (int)unaff_ESI) = *(uint *)(pbVar23 + (int)unaff_ESI) & (uint)pbVar33;
  puVar22 = (uint *)0x0;
LAB_009b52b5:
  *(byte **)pbVar33 = pbVar33 + (uint)((byte)*unaff_ESI < 0xa6) + *(int *)pbVar33;
  bVar5 = 9 < (bVar12 & 0xf);
  bVar15 = bVar5 | bVar15;
  bVar12 = bVar12 + bVar15 * '\x06';
  bVar4 = 9 < (bVar12 & 0xf);
  bVar15 = bVar4 | bVar15;
  bVar13 = bVar12 + bVar15 * -6 & 0xf;
  iVar27 = *(int *)pbVar33;
  bVar12 = 9 < bVar13 | bVar15;
  uVar20 = CONCAT31((int3)(((uint)(uint3)((uint3)(uVar7 >> 8) >> 8) << 0x10) >> 8),
                    bVar13 + bVar12 * -6) & 0xffffff0f;
  cVar14 = (char)uVar20;
  pcVar18 = (char *)CONCAT22((short)(uVar20 >> 0x10),
                             CONCAT11(((char)(uVar7 >> 8) - bVar15) - bVar12,cVar14));
  *pcVar18 = *pcVar18 + cVar14;
  *pcVar18 = *pcVar18 + (byte)uVar6;
  puVar19 = (uint *)((uint)pcVar18 & 0xffffff00);
  *(char *)puVar19 = (char)*puVar19;
  uVar20 = *puVar19;
  uVar17 = *puVar19;
  uVar2 = *puVar19;
  pbVar33 = (byte *)((int)unaff_ESI + uVar17) + *puVar19;
  bVar15 = bVar12 * '\x06';
  uVar21 = (undefined3)((uint)pcVar18 >> 8);
  *(byte *)(unaff_EBP + 0x30) = *(byte *)(unaff_EBP + 0x30) ^ (byte)uVar6;
  bVar24 = (byte)(uVar6 >> 8);
  *(byte *)puVar22 = (byte)*puVar22 | bVar24;
  uVar10 = *puVar22;
  *(byte *)puVar22 = (byte)*puVar22 + bVar24;
  puVar32 = (uint *)((uint)(pbVar33 + CARRY4((uint)unaff_ESI,uVar20)) & *puVar22 ^ *puVar22);
  puVar19 = (uint *)(unaff_EBP + 0x31);
  *puVar19 = *puVar19 ^ (uint)puVar32;
  *(uint *)(uVar29 - 8) =
       (uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
       (uint)((int)*puVar19 < 0) * 0x80 | (uint)(*puVar19 == 0) * 0x40 |
       (uint)(byte)(9 < bVar13 | bVar4 | bVar5 | bVar3 | in_AF & 1) * 0x10 |
       (uint)((POPCOUNT(*puVar19 & 0xff) & 1U) == 0) * 4 | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  *(uint *)(pbVar23 + (int)puVar32) = *(uint *)(pbVar23 + (int)puVar32) ^ uVar29 - 8;
  *pbVar23 = *pbVar23 - bVar24;
  *pbVar23 = *pbVar23 ^ bVar24;
  uVar20 = CONCAT31(uVar21,(bVar15 + (0x90 < (bVar15 & 0xf0) |
                                     (CARRY4((int)unaff_ESI + uVar17,uVar2) ||
                                     CARRY4((uint)pbVar33,(uint)CARRY4((uint)unaff_ESI,uVar20))) |
                                     bVar12 * (0xf9 < bVar15)) * '`' + 0x31 | 0x31) +
                           CARRY1((byte)uVar10,bVar24) + -1) ^ 0x32;
  uVar11 = *(undefined1 *)(uVar26 + 0x33);
  puVar34 = (undefined1 *)
            (iVar27 * -0x5e + 1U ^ *(uint *)((int)&ProcessEnvironmentBlock + uVar20 + 3));
  *(int *)(puVar34 + -0x6ecba0cc) = *(int *)(puVar34 + -0x6ecba0cc) + (int)puVar32;
  puVar30 = (undefined1 *)(uVar29 - 0xc);
  *(undefined4 *)(uVar29 - 0xc) = 0xfd35d135;
  *puVar32 = *puVar32 << ((byte)(byte *)((int)puVar22 + 1) & 0x1f);
  if ((byte *)((int)puVar22 + 1) == (byte *)0x0) {
    puVar30 = (undefined1 *)(uVar29 - 0x10);
    *(uint **)(uVar29 - 0x10) = puVar32;
  }
  uVar6 = CONCAT44(CONCAT31((int3)(uVar6 >> 8),uVar11),CONCAT31(uVar21,(char)uVar20)) ^ 0x3203690328
  ;
  uVar7 = uVar6 % (ulonglong)*puVar32;
  uVar20 = (uint)(uVar6 / *puVar32) & 0xc737b137;
  bVar12 = 9 < ((byte)uVar20 & 0xf) | bVar12;
  uVar17 = CONCAT31((int3)(uVar20 >> 8),(byte)uVar20 + bVar12 * '\x06') & 0xffffff0f;
  _DAT_c739b339 =
       CONCAT22((short)(uVar17 >> 0x10),CONCAT11((char)(uVar20 >> 8) + bVar12,(char)uVar17)) +
       -0x7cc7ddc8;
  *(undefined4 *)(puVar30 + -4) = 0x39;
  iVar27 = CONCAT22((short)(uVar26 >> 0x10),CONCAT11(*(undefined1 *)uVar7,(char)uVar26));
  iVar28 = iVar27 + 1;
  *puVar32 = (uint)(puVar34 + *puVar32);
  puVar31 = puVar30 + -5;
  out((char)*puVar32,(short)uVar7);
  *(undefined4 *)((int)puVar32 + 1) = puVar34;
  uVar20 = (int)puVar32 + 2;
  *puVar34 = *(undefined1 *)((int)puVar32 + 1);
  pcVar8 = (code *)swi(0x3f);
  uVar35 = (*pcVar8)();
  pcVar18 = (char *)uVar35;
  *pcVar18 = *pcVar18 + (char)uVar35;
  *pcVar18 = *pcVar18 + (char)((ulonglong)uVar35 >> 8);
  uVar9 = *(undefined6 *)pcVar18;
  bVar15 = (byte)uVar9;
  *(char *)uVar9 = *(char *)uVar9 + bVar15;
  *(int *)(puVar31 + -4) = unaff_EBP;
  pbVar33 = (byte *)(iVar27 + -0x44cf5dcf);
  bVar12 = (byte)((ulonglong)uVar35 >> 0x20);
  *pbVar33 = *pbVar33 ^ bVar12;
  pbVar33 = (byte *)CONCAT31((int3)((uint)iVar28 >> 8),(byte)iVar28 ^ bVar15 ^ 0x30);
  *pbVar33 = *pbVar33 ^ bVar12;
  *(uint *)(extraout_ECX + uVar20) = *(uint *)(extraout_ECX + uVar20) ^ uVar20;
  puVar22 = (uint *)(extraout_ECX + 0x73 + uVar20);
  *puVar22 = *puVar22 ^ (uint)(puVar31 + -4);
  *(uint *)(pbVar33 + -0x40ce5dce) =
       *(uint *)(pbVar33 + -0x40ce5dce) ^ (uint)((ulonglong)uVar35 >> 0x20);
  *(uint *)(pbVar33 + 1) =
       *(uint *)(pbVar33 + 1) ^
       CONCAT31((int3)(CONCAT22((short)((uint6)uVar9 >> 0x10),
                                CONCAT11((byte)((uint6)uVar9 >> 8) ^ (byte)extraout_ECX,bVar15)) >>
                      8),bVar15 ^ 0x30 ^ (byte)((ulonglong)uVar35 >> 0x28));
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: CVisionTexConverter::~CVisionTexConverter
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009b517d) overlaps instruction at (ram,0x009b517c)
    */
/* WARNING: Removing unreachable block (ram,0x009b5172) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionTexConverter::~CVisionTexConverter(CVisionTexConverter *this,CVisionTexConverter *param_1)
{
{
  bool bVar1;
  ulonglong uVar2;
  short sVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  short sVar7;
  undefined4 in_EAX;
  uint uVar8;
  byte *pbVar9;
  char cVar13;
  byte *pbVar11;
  uint *puVar12;
  int iVar14;
  int iVar15;
  uint *puVar16;
  byte bVar17;
  byte bVar18;
  int in_EDX;
  undefined2 uVar19;
  byte bVar20;
  undefined4 unaff_EBX;
  int *piVar21;
  undefined4 unaff_EBP;
  char *unaff_ESI;
  byte *pbVar22;
  int unaff_EDI;
  uint *puVar23;
  char *pcVar24;
  byte in_AF;
  undefined1 auStack_8 [4];
  uint uVar10;
  
  iVar15 = CONCAT31((int3)((uint)this >> 8),0x31);
  uVar19 = (undefined2)((uint)unaff_EBX >> 0x10);
  piVar21 = (int *)CONCAT22(uVar19,CONCAT11(0x31,(byte)unaff_EBX));
  iVar14 = iVar15 + -1;
  bVar17 = (byte)in_EAX;
  if (iVar14 == 0) {
    *piVar21 = *piVar21 << (bVar17 & 0x1f);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *unaff_ESI = *unaff_ESI >> ((byte)iVar14 & 0x1f);
  iVar15 = iVar15 + -2;
  puVar16 = (uint *)0x0;
  if (iVar15 != 0) {
    puVar16 = (uint *)CONCAT31((int3)((uint)iVar15 >> 8),0x35);
    piVar21 = (int *)CONCAT22(uVar19,(ushort)(byte)unaff_EBX);
  }
  bVar20 = (byte)piVar21;
  bVar18 = 9 < (bVar17 & 0xf) | in_AF;
  bVar4 = bVar17 + bVar18 * -6 & 0xf;
  bVar17 = 9 < bVar4 | bVar18;
  bVar5 = bVar4 + bVar17 * -6 & 0xf;
  bVar4 = 9 < bVar5 | bVar17;
  uVar8 = CONCAT31((int3)((uint)in_EAX >> 8),bVar5 + bVar4 * -6) & 0xffff000f;
  cVar6 = (char)uVar8;
  puVar23 = (uint *)*(undefined6 *)(*(int *)(unaff_EDI + 1) * 0x3f883f76);
  bVar5 = (byte)in_EDX;
  puVar12 = (uint *)CONCAT31((int3)(CONCAT22((short)(uVar8 >> 0x10),
                                             CONCAT11((((char)((uint)in_EAX >> 8) - bVar18) - bVar17
                                                      ) - bVar4,cVar6)) >> 8),cVar6 + bVar5);
  pbVar9 = (byte *)((uint)puVar12 ^ *puVar12);
  pbVar9[-0x201000] = pbVar9[-0x201000] + (byte)pbVar9;
  *(char *)(in_EDX + -0x4ecf5ad0) = *(char *)(in_EDX + -0x4ecf5ad0) + bVar20;
  pbVar11 = (byte *)CONCAT31((int3)(CONCAT22((short)((uint)piVar21 >> 0x10),CONCAT11(0x3f,bVar20))
                                   >> 8),bVar20 ^ (byte)pbVar9);
  *pbVar11 = *pbVar11 ^ (byte)((uint)pbVar9 >> 8);
  uVar19 = (undefined2)((uint)in_EDX >> 0x10);
  bVar18 = (byte)((uint)in_EDX >> 8) ^ *pbVar9;
  bVar17 = bVar5 ^ (byte)*puVar23;
  uVar8 = CONCAT31((int3)(CONCAT22(uVar19,CONCAT11(bVar18,bVar5)) >> 8),bVar17);
  pbVar9 = (byte *)((uint)pbVar9 ^ 0x35b73570);
  pbVar22 = (byte *)_DAT_39e13776;
  if (uVar8 <= *(uint *)(uVar8 + 0x3a)) {
    pcVar24 = (char *)((int)puVar23 + 1);
    bVar4 = 9 < ((byte)unaff_EBP & 0xf) | bVar4;
    uVar10 = CONCAT31((int3)((uint)unaff_EBP >> 8),(byte)unaff_EBP + bVar4 * -6) & 0xffffff0f;
    sVar7 = CONCAT11((char)((uint)unaff_EBP >> 8) - bVar4,(char)uVar10);
    sVar3 = (short)*pcVar24;
    cVar6 = (char)(sVar7 / sVar3);
    cVar13 = (char)(sVar7 % sVar3);
    puVar12 = (uint *)CONCAT31((int3)(CONCAT22((short)(uVar10 >> 0x10),CONCAT11(cVar13,cVar6)) >> 8)
                               ,cVar6 + cVar13);
    pbVar9 = (byte *)((uint)puVar12 ^ *puVar12);
    puVar23 = (uint *)((int)puVar23 + 2);
    cVar6 = in((short)uVar8);
    *pcVar24 = cVar6;
    *pbVar9 = *pbVar9 + (char)pbVar9;
    *pbVar11 = *pbVar11 + (char)((uint)pbVar9 >> 8);
    pbVar9[(int)pbVar22] = pbVar9[(int)pbVar22] ^ (byte)((uint)puVar16 >> 8);
  }
  bVar18 = bVar18 ^ *pbVar9;
  iVar14 = CONCAT22(uVar19,CONCAT11(bVar18,bVar17));
  if ((char)bVar18 < '\0') {
    *(int *)pbVar9 = *(int *)pbVar9 >> 0x17;
  }
  else {
    *pbVar22 = *pbVar22 ^ (byte)pbVar9 ^ 0x3f;
    pbVar22 = (byte *)((uint)pbVar22 ^ (uint)pbVar9 ^ 0x3f);
    pbVar11 = (byte *)((uint)pbVar9 ^ 0x35733518);
    DAT_35ae35a1 = DAT_35ae35a1 ^ 0x33;
    iVar14 = CONCAT31((int3)((uint)iVar14 >> 8),bVar17 ^ (byte)*puVar16) + 1;
    bVar17 = (byte)puVar16 & 0x1f;
    iVar15 = *(int *)pbVar22;
    *(int *)pbVar22 = *(int *)pbVar22 << bVar17;
    bVar1 = ((uint)puVar16 & 0x1f) != 0 && iVar15 << bVar17 - 1 < 0;
    puVar16 = (uint *)((int)puVar16 + -1);
    puVar12 = puVar23;
    if (puVar16 != (uint *)0x0) goto LAB_009b5176;
    bVar18 = (byte)((uint)iVar14 >> 8);
    uVar8 = *puVar23;
    bVar17 = bVar18 + (char)*puVar23;
    *(ushort *)puVar23 =
         (short)*puVar23 +
         (ushort)(CARRY1(bVar18,(byte)*puVar23) || CARRY1(bVar17,bVar1)) *
         (((ushort)pbVar22 & 3) - ((ushort)*puVar23 & 3));
    if (SCARRY1(bVar18,(char)uVar8) == SCARRY1(bVar17,bVar1)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar8 = *puVar23;
    *puVar23 = *puVar23;
    uVar2 = CONCAT44(CONCAT22((short)((uint)iVar14 >> 0x10),CONCAT11((char)uVar8,(char)iVar14)),
                     pbVar9) ^ 0x35733518;
    puVar12 = (uint *)(uVar2 / *puVar23);
    iVar14 = (int)(uVar2 % (ulonglong)*puVar23);
    puVar23 = (uint *)((uint)puVar23 ^ *puVar12);
    pbVar9 = (byte *)((int)puVar12 + 1);
  }
  LOCK();
  puVar12 = (uint *)*puVar16;
  *puVar16 = (uint)puVar23;
  UNLOCK();
  _DAT_153adc3a = pbVar9;
  *(uint *)pbVar22 = (*(int *)pbVar22 - (int)puVar12) - (uint)(puVar16 < *(uint **)(pbVar22 + 0x3b))
  ;
  pbVar11 = pbVar9 + 0x4ac15cc2;
  *pbVar22 = (char)*pbVar22 >> ((byte)puVar16 & 0x1f);
LAB_009b5176:
  puVar23 = (uint *)CONCAT31((int3)((uint)pbVar11 >> 8),(char)pbVar11 + (char)((uint)iVar14 >> 8));
  pcVar24 = (char *)((uint)puVar23 ^ *puVar23);
  *pcVar24 = *pcVar24 + (byte)pcVar24;
  *(char *)puVar12 = (char)*puVar12 + (char)((uint)puVar16 >> 8);
  pbVar22[0x5530dd30] = pbVar22[0x5530dd30] ^ (byte)pcVar24;
  *puVar16 = *puVar16 ^ (uint)auStack_8;
  *puVar12 = *puVar12 ^ 0x37a3378d;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

