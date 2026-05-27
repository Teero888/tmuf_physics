// Class implementation: CDx9GpuBuilder

// =================================================
// Function: CDx9GpuBuilder::BuildVHlsl
// =================================================
void __thiscall
CDx9GpuBuilder::BuildVHlsl
          (CDx9GpuBuilder *this,CDx9GpuBuilder *param_1,CMwNodRef<class_CPlugFileGPUV> *param_2,
          EStdGpuV param_3,SStdGpuMask param_4,CFastString *param_5)
{
{
  uint *puVar1;
  uint *unaff_EDI;
  uint *unaff_retaddr;
  
  in(0x35);
  func_0xf0d040ec();
  puVar1 = unaff_EDI + 1;
  *puVar1 = (int)(unaff_retaddr + 1) + (uint)(*unaff_retaddr < *unaff_EDI) + *puVar1;
  *puVar1 = *puVar1 & (uint)(unaff_retaddr + 1);
  return;
}
}

// =================================================
// Function: CDx9GpuBuilder::CDx9GpuBuilder
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009a545d) overlaps instruction at (ram,0x009a545c)
    */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall CDx9GpuBuilder::CDx9GpuBuilder(CDx9GpuBuilder *this,CDx9GpuBuilder *param_1)
{
{
  uint uVar1;
  uint3 uVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  char cVar6;
  byte bVar7;
  char cVar14;
  undefined4 in_EAX;
  int *piVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  undefined3 uVar15;
  char *pcVar12;
  undefined2 uVar16;
  byte *pbVar13;
  int iVar17;
  int iVar18;
  uint in_EDX;
  uint *unaff_EBX;
  undefined4 *unaff_EBP;
  undefined4 uVar19;
  undefined1 *unaff_ESI;
  uint *puVar20;
  int unaff_EDI;
  bool bVar21;
  byte in_AF;
  
  bVar3 = (byte)(in_EDX >> 8);
  piVar8 = (int *)CONCAT31((int3)((uint)in_EAX >> 8),(byte)in_EAX + bVar3);
  pbVar9 = (byte *)((int)piVar8 + (uint)CARRY1((byte)in_EAX,bVar3) + *piVar8);
  bVar3 = (byte)pbVar9;
  *pbVar9 = bVar3;
  *pbVar9 = *pbVar9 + bVar3;
  DAT_40312f31 = DAT_40312f31 ^ bVar3;
  *(uint *)((int)unaff_EBX + 0x31) = *(uint *)((int)unaff_EBX + 0x31) ^ in_EDX;
  out(*unaff_ESI,(short)in_EDX);
  *(uint *)((int)unaff_EBX + 0x432f131) = *(uint *)((int)unaff_EBX + 0x432f131) ^ (uint)this;
  puVar20 = (uint *)((uint)(unaff_ESI + 1) ^ *unaff_EBX);
  uVar1 = *(uint *)((uint)&stack0x00000000 ^ *(uint *)this);
  uVar11 = *(uint *)((int)unaff_EBP + 0x33);
  iVar17 = CONCAT22((short)((uint)this >> 0x10),0x3533);
  uVar19 = *unaff_EBP;
  uVar4 = in((short)in_EDX);
  uVar10 = CONCAT31((uint3)((uint)pbVar9 >> 8) ^
                    (uint3)((uint)*(undefined4 *)(unaff_EDI + 0x33) >> 8),uVar4) ^ 0x365b3609;
  *puVar20 = *puVar20 ^ (uint)puVar20;
  *unaff_EBP = uVar19;
  bVar3 = 9 < ((byte)uVar10 & 0xf) | in_AF;
  bVar5 = (byte)uVar10 + bVar3 * '\x06' & 0xf;
  cVar14 = (char)(uVar10 >> 8) + bVar3;
  uVar2 = (uint3)(uVar10 >> 8);
  iVar18 = iVar17 + -1;
  if (iVar18 == 0) {
    bVar3 = 9 < bVar5 | bVar3;
    uVar11 = CONCAT31(uVar2,bVar5 + bVar3 * '\x06') & 0xffff000f;
    cVar6 = (char)uVar11;
    uVar15 = (undefined3)(CONCAT22((short)(uVar11 >> 0x10),CONCAT11(cVar14 + bVar3,cVar6)) >> 8);
    cVar6 = cVar6 + '8';
    pbVar9 = (byte *)CONCAT31(uVar15,cVar6);
    bVar7 = (byte)((uint)unaff_EBX >> 8);
    *pbVar9 = *pbVar9 | bVar7;
    pbVar9 = (byte *)(CONCAT31(uVar15,cVar6) | 0x38);
    bVar3 = *pbVar9;
    *pbVar9 = *pbVar9 + bVar7;
    bVar5 = (byte)pbVar9 + 0x38;
    bVar21 = 199 < (byte)pbVar9 || CARRY1(bVar5,CARRY1(bVar3,bVar7));
    cVar14 = bVar5 + CARRY1(bVar3,bVar7);
    pbVar9 = (byte *)CONCAT31(uVar15,cVar14);
    bVar3 = *pbVar9;
    bVar5 = *pbVar9;
    *pbVar9 = (bVar5 - bVar7) - bVar21;
    cVar14 = (cVar14 + -0x38) - (bVar3 < bVar7 || (byte)(bVar5 - bVar7) < bVar21);
    pbVar9 = (byte *)CONCAT31(uVar15,cVar14);
    *pbVar9 = *pbVar9 & bVar7;
    pcVar12 = (char *)(CONCAT31(uVar15,cVar14) & 0xffffff38);
    *pcVar12 = *pcVar12 - bVar7;
    pbVar9 = (byte *)CONCAT31((int3)((uint)pcVar12 >> 8),(char)pcVar12 + -0x38);
    *pbVar9 = *pbVar9 ^ bVar7;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(byte *)(uVar1 ^ uVar11) = bVar5;
  bVar3 = 9 < bVar5 | bVar3;
  bVar7 = bVar5 + bVar3 * -6 & 0xf;
  bVar5 = 9 < bVar7 | bVar3;
  uVar11 = CONCAT31((int3)(((uint)(uVar2 >> 8) << 0x10) >> 8),bVar7 + bVar5 * -6) & 0xffffff0f;
  uVar16 = (undefined2)(uVar11 >> 0x10);
  bVar7 = (byte)uVar11;
  pbVar9 = (byte *)CONCAT22(uVar16,CONCAT11((cVar14 - bVar3) - bVar5,bVar7));
  *pbVar9 = *pbVar9 + bVar7;
  bVar3 = *pbVar9;
  *pbVar9 = *pbVar9 + bVar7;
  bVar7 = bVar7 + CARRY1(bVar3,bVar7);
  pbVar13 = (byte *)CONCAT22(uVar16,(ushort)bVar7);
  bVar3 = *pbVar13;
  *pbVar13 = *pbVar13 + bVar7;
  pbVar9 = (byte *)(iVar17 + 0x4330a92f);
  *pbVar9 = *pbVar9 ^ (byte)iVar18;
  *(uint *)(pbVar13 + CARRY1(bVar3,bVar7) + 0x54303f61) =
       *(uint *)(pbVar13 + CARRY1(bVar3,bVar7) + 0x54303f61) ^ in_EDX - 1;
  return;
}
}

