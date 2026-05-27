// Class implementation: CHmsZone_CVisionData

// =================================================
// Function: CHmsZone::CVisionData::_vector_deleting_destructor_
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009c0f9a) overlaps instruction at (ram,0x009c0f99)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * __thiscall
CHmsZone::CVisionData::_vector_deleting_destructor_
          (CVisionData *this,CRpcCallInternal *param_1,uint param_2)
{
{
  uint uVar1;
  byte bVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  byte bVar13;
  undefined2 uVar15;
  uint *puVar7;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  undefined3 uVar14;
  int *piVar12;
  uint *puVar16;
  byte bVar17;
  CRpcCallInternal *pCVar18;
  CRpcCallInternal *pCVar19;
  CRpcCallInternal *pCVar20;
  char *pcVar21;
  undefined2 in_SS;
  undefined2 in_DS;
  byte in_AF;
  uint in_stack_00000010;
  undefined4 in_stack_00000014;
  int in_stack_00000018;
  uint *in_stack_0000001c;
  uint *in_stack_00000020;
  uint uVar2;
  byte *pbVar11;
  
  DAT_3e003de6 = DAT_3e003de6 >> 1;
  bRamd53ec73e = (byte)in_stack_00000010;
  puVar16 = (uint *)(in_stack_00000018 + -1);
  if (puVar16 == (uint *)0x0 || param_2 == 1) {
    pcVar21 = (char *)((uint)in_stack_00000020 & *in_stack_00000020);
    bVar13 = 9 < ((bRamd53ec73e ^ 0x3f) & 0xf) | in_AF;
    bVar3 = (bRamd53ec73e ^ 0x3f) + bVar13 * -6 & 0xf;
    bVar6 = 9 < bVar3 | bVar13;
    bVar5 = bVar3 + bVar6 * -6 & 0xf;
    pCVar18 = param_1 + 1;
    out(*param_1,(short)CONCAT31((int3)((uint)in_stack_00000014 >> 8),0x3d));
    bVar3 = 9 < bVar5 | bVar6;
    uVar8 = CONCAT31((int3)(in_stack_00000010 >> 8),bVar5 + bVar3 * -6) & 0xffff000f;
    uVar15 = (undefined2)(uVar8 >> 0x10);
    cVar4 = (char)uVar8;
    bVar13 = (((char)(in_stack_00000010 >> 8) - bVar13) - bVar6) - bVar3;
    pcVar9 = (char *)CONCAT22(uVar15,CONCAT11(bVar13,cVar4));
    if ((bRamd53ec73e ^ 0x3f) == 0) {
      *pcVar21 = *pcVar21 + '\x01';
      *pcVar9 = *pcVar9 + cVar4;
      puVar7 = (uint *)CONCAT31((int3)((uint)pcVar9 >> 8),cVar4 + '=');
      pcVar9 = (char *)((int)puVar7 * 2 + 0x30160000);
      *pcVar9 = *pcVar9 + (byte)in_stack_0000001c;
      bVar17 = (byte)((uint)in_stack_00000014 >> 8) ^ (byte)*puVar7;
      pbVar11 = (byte *)CONCAT22((short)((uint)in_stack_00000014 >> 0x10),CONCAT11(bVar17,0x3d));
      pCVar18 = param_1 + 2;
      *(byte *)(param_2 + 0x2f) = *(byte *)(param_2 + 0x2f) ^ bVar13;
      *puVar7 = *puVar7 ^ 0x30b43095;
      *(char *)puVar7 = (char)*puVar7 << 1;
      bVar5 = in(0x30);
      uVar8 = *puVar16;
      pCVar19 = pCVar18 + *puVar16;
      uVar1 = *puVar16;
      uVar2 = *puVar16;
      pCVar20 = pCVar19 + uVar2 + CARRY4((uint)pCVar18,uVar8);
      bVar3 = 9 < (bVar5 & 0xf) | bVar3;
      bVar5 = bVar5 + bVar3 * '\x06';
      *(uint *)(pCVar20 + -0x10ce58cf) = *(uint *)(pCVar20 + -0x10ce58cf) ^ (uint)in_stack_0000001c;
      *in_stack_0000001c = *in_stack_0000001c ^ (uint)pCVar20;
      bVar6 = *pbVar11;
      uVar8 = CONCAT22(uVar15,CONCAT11(bVar13 ^ pbVar11[0x32],
                                       bVar5 + (0x90 < (bVar5 & 0xf0) |
                                               (CARRY4((uint)pCVar19,uVar1) ||
                                               CARRY4((uint)(pCVar19 + uVar2),
                                                      (uint)CARRY4((uint)pCVar18,uVar8))) |
                                               bVar3 * (0xf9 < bVar5)) * '`')) ^
              *(uint *)(pcVar21 + 0x33);
      *pCVar20 = (CRpcCallInternal)((byte)*pCVar20 ^ (byte)(uVar8 >> 8));
      iVar10 = (CONCAT31((int3)((uint)in_stack_0000001c >> 8),(byte)in_stack_0000001c ^ bVar6) ^
               0x3e) + 1;
      bVar5 = (byte)((uint)iVar10 >> 8);
      uVar14 = (undefined3)((uint)iVar10 >> 8);
      bVar6 = (char)iVar10 + bVar5;
      pbVar11 = (byte *)CONCAT31(uVar14,bVar6);
      _DAT_c43cc039 = puVar16;
      *pbVar11 = *pbVar11 + (char)uVar8;
      *pbVar11 = *pbVar11 + bVar6;
      bVar13 = *pbVar11;
      LOCK();
      *puVar16 = (uint)pCVar20;
      UNLOCK();
      bVar3 = 9 < (bVar6 & 0xf) | bVar3;
      bVar6 = bVar6 + bVar3 * -6;
      piVar12 = (int *)(CONCAT31(uVar14,bVar6 + (0x9f < bVar6 |
                                                bVar17 < bVar13 | bVar3 * (bVar6 < 6)) * -0x60 ^
                                        bVar5) ^ 0x35c335ae);
      _DAT_365735e4 = _DAT_365735e4 << (((byte)puVar16 ^ *(byte *)puVar16) & 0x1f);
      *piVar12 = *piVar12 << 1;
      _DAT_c43cc035 = in_DS;
      _DAT_c43cc031 = in_SS;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  else {
    pCVar18 = (CRpcCallInternal *)((uint)param_1 ^ *(uint *)((int)in_stack_0000001c + 0x33));
    *(byte *)in_stack_0000001c = (byte)*in_stack_0000001c ^ 0xab;
    pcVar9 = (char *)(in_stack_00000010 ^ *(uint *)((uint)in_stack_0000001c ^ in_stack_00000010) ^
                     0x39);
  }
  *pCVar18 = (CRpcCallInternal)((byte)*pCVar18 ^ 0xac);
  return (void *)((uint)pcVar9 ^ 0x35cf35c9);
}
}

// =================================================
// Function: CHmsZone::CVisionData::~CVisionData
// =================================================
void __thiscall CHmsZone::CVisionData::~CVisionData(CVisionData *this,CVisionData *param_1)
{
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
}

