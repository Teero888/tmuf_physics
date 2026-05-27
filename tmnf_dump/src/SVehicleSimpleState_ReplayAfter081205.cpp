// Class implementation: SVehicleSimpleState_ReplayAfter081205

// =================================================
// Function: SVehicleSimpleState_ReplayAfter081205::RestoreFromStruct
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
SVehicleSimpleState_ReplayAfter081205::RestoreFromStruct
          (void *this,SVehicleSimpleState_ReplayAfter040104 *param_1,SVehicleCarState *param_2,
          SState *param_3,SState *param_4,SState *param_5,SState *param_6)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar2 = (float)_DAT_00b52a58;
  fVar1 = (float)_DAT_00c418d8;
  *(float *)param_1 = ((float)*(ushort *)this / fVar2) * (float)_DAT_00b9f5e8 - fVar1;
  *(float *)(param_1 + 4) =
       ((float)*(ushort *)((int)this + 2) / fVar2) * (float)_DAT_00b2f710 - fVar1;
  *(float *)(param_1 + 0x80) =
       ((float)*(ushort *)((int)this + 4) / fVar2) * ((float)_DAT_00b9f5e0 - 0.0) + 0.0;
  fVar1 = (float)_DAT_00b55d50;
  *(float *)(param_1 + 0x18) = ((float)*(byte *)((int)this + 0x15) / fVar1) * 1.0 + 0.0;
  *(uint *)(param_1 + 0x14) = *(uint *)((int)this + 0x1c) >> 0x1f;
  fVar3 = ((float)*(byte *)((int)this + 0x16) / fVar1) * (float)_DAT_00b59bb8 - (float)_DAT_00b36110
  ;
  *(float *)(param_2 + 8) = fVar3;
  *(float *)(param_3 + 8) = fVar3;
  *(undefined4 *)(param_4 + 8) = 0;
  *(undefined4 *)(param_5 + 8) = 0;
  fVar4 = (float)_DAT_00b3d2c8;
  fVar3 = (float)_DAT_00b33a58;
  *(float *)param_2 = ((float)*(byte *)((int)this + 0x17) / fVar1) * fVar4 - fVar3;
  *(float *)param_3 = ((float)*(byte *)((int)this + 0x19) / fVar1) * fVar4 - fVar3;
  *(float *)param_4 = ((float)*(byte *)((int)this + 0x1b) / fVar1) * fVar4 - fVar3;
  *(float *)param_5 = ((float)*(byte *)((int)this + 0x1d) / fVar1) * fVar4 - fVar3;
  fVar4 = (float)_DAT_00b9efd8 - 0.0;
  *(float *)(param_2 + 4) = ((float)*(ushort *)((int)this + 6) / fVar2) * fVar4 + 0.0;
  *(float *)(param_3 + 4) = ((float)*(ushort *)((int)this + 8) / fVar2) * fVar4 + 0.0;
  *(float *)(param_4 + 4) = ((float)*(ushort *)((int)this + 10) / fVar2) * fVar4 + 0.0;
  *(float *)(param_5 + 4) = fVar4 * ((float)*(ushort *)((int)this + 0xc) / fVar2) + 0.0;
  *(ushort *)(param_2 + 0xc) = (ushort)*(byte *)((int)this + 0x18);
  *(ushort *)(param_3 + 0xc) = (ushort)*(byte *)((int)this + 0x1a);
  *(ushort *)(param_4 + 0xc) = (ushort)*(byte *)((int)this + 0x1c);
  *(ushort *)(param_5 + 0xc) = (ushort)*(byte *)((int)this + 0x1e);
  *(uint *)(param_2 + 0x14) = *(byte *)((int)this + 0x20) >> 6 & 1;
  *(uint *)(param_2 + 0x10) = (uint)(*(byte *)((int)this + 0x20) >> 7);
  *(uint *)(param_3 + 0x14) = *(byte *)((int)this + 0x21) & 1;
  *(uint *)(param_3 + 0x10) = *(byte *)((int)this + 0x21) >> 1 & 1;
  *(uint *)(param_4 + 0x14) = *(byte *)((int)this + 0x21) >> 2 & 1;
  *(uint *)(param_4 + 0x10) = *(byte *)((int)this + 0x21) >> 3 & 1;
  *(uint *)(param_5 + 0x14) = *(byte *)((int)this + 0x21) >> 4 & 1;
  *(uint *)(param_5 + 0x10) = *(byte *)((int)this + 0x21) >> 5 & 1;
  *(uint *)(param_1 + 100) = *(uint *)((int)this + 0x1c) >> 0x1b & 3;
  *(uint *)(param_1 + 0x68) = *(uint *)((int)this + 0x1c) >> 0x1d & 3;
  *(uint *)(param_1 + 0x1c) = (uint)(*(byte *)((int)this + 0x21) >> 7);
  *(uint *)(param_1 + 0x88) = *(byte *)((int)this + 0x1f) & 7;
  *(uint *)(param_1 + 0x8c) = *(byte *)((int)this + 0x21) >> 6 & 1;
  *(float *)(param_1 + 8) = ((float)*(byte *)((int)this + 0xe) / fVar1) * fVar3 - 1.0;
  *(float *)(param_1 + 0xc) = ((float)*(byte *)((int)this + 0xf) / fVar1) * 1.0 + 0.0;
  *(float *)(param_1 + 0x10) = ((float)*(byte *)((int)this + 0x10) / fVar1) * 1.0 + 0.0;
  *(float *)(param_1 + 0x24) = ((float)*(byte *)((int)this + 0x13) / fVar1) * fVar3 - 1.0;
  *(float *)(param_1 + 0x28) = ((float)*(byte *)((int)this + 0x14) / fVar1) * fVar3 - 1.0;
  return;
}
}

// =================================================
// Function: SVehicleSimpleState_ReplayAfter081205::SaveToStruct
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
SVehicleSimpleState_ReplayAfter081205::SaveToStruct
          (void *this,SVehicleSimpleNetState *param_1,SVehicleCarState *param_2,float param_3,
          ulong param_4,int param_5,SState *param_6,int param_7,SState *param_8,int param_9,
          SState *param_10,int param_11,SState *param_12,int param_13)
{
{
  int iVar1;
  float fVar2;
  float fVar3;
  uchar uVar4;
  byte bVar5;
  ushort uVar6;
  
  uVar6 = GmFunc::RealToNat16(*(float *)param_1,_DAT_00b69838,_DAT_00b3d270);
  fVar2 = _DAT_00b58724;
  *(ushort *)this = uVar6;
  uVar6 = GmFunc::RealToNat16(*(float *)(param_1 + 4),_DAT_00b69838,fVar2);
  fVar2 = _DAT_00b4ff34;
  *(ushort *)((int)this + 2) = uVar6;
  uVar6 = GmFunc::RealToNat16(*(float *)(param_1 + 0x80),0.0,fVar2);
  *(ushort *)((int)this + 4) = uVar6;
  uVar4 = GmFunc::RealToNat8(*(float *)(param_1 + 0x18),0.0,1.0);
  fVar3 = _DAT_00b9f5cc;
  fVar2 = _DAT_00b5b910;
  *(uchar *)((int)this + 0x15) = uVar4;
  *(uint *)((int)this + 0x1c) =
       (uint)(*(int *)(param_1 + 0x14) != 0) << 0x1f | *(uint *)((int)this + 0x1c) & 0x7fffffff;
  uVar4 = GmFunc::RealToNat8(*(float *)(param_2 + 8),fVar2,fVar3);
  fVar2 = _DAT_00b313ac;
  *(uchar *)((int)this + 0x16) = uVar4;
  uVar4 = GmFunc::RealToNat8(*(float *)param_2,_DAT_00b362b0,fVar2);
  fVar2 = _DAT_00b313ac;
  *(uchar *)((int)this + 0x17) = uVar4;
  uVar4 = GmFunc::RealToNat8(*(float *)param_3,_DAT_00b362b0,fVar2);
  fVar2 = _DAT_00b313ac;
  *(uchar *)((int)this + 0x19) = uVar4;
  uVar4 = GmFunc::RealToNat8(*(float *)param_4,_DAT_00b362b0,fVar2);
  fVar2 = _DAT_00b313ac;
  *(uchar *)((int)this + 0x1b) = uVar4;
  uVar4 = GmFunc::RealToNat8(*(float *)param_5,_DAT_00b362b0,fVar2);
  fVar2 = _DAT_00b9ef64;
  *(uchar *)((int)this + 0x1d) = uVar4;
  uVar6 = GmFunc::RealToNat16(*(float *)(param_2 + 4),0.0,fVar2);
  fVar2 = _DAT_00b9ef64;
  *(ushort *)((int)this + 6) = uVar6;
  uVar6 = GmFunc::RealToNat16(*(float *)((int)param_3 + 4),0.0,fVar2);
  fVar2 = _DAT_00b9ef64;
  *(ushort *)((int)this + 8) = uVar6;
  uVar6 = GmFunc::RealToNat16(*(float *)(param_4 + 4),0.0,fVar2);
  fVar2 = _DAT_00b9ef64;
  *(ushort *)((int)this + 10) = uVar6;
  uVar6 = GmFunc::RealToNat16(*(float *)(param_5 + 4),0.0,fVar2);
  *(ushort *)((int)this + 0xc) = uVar6;
  *(SVehicleCarState *)((int)this + 0x18) = param_2[0xc];
  *(undefined1 *)((int)this + 0x1a) = *(undefined1 *)((int)param_3 + 0xc);
  *(undefined1 *)((int)this + 0x1c) = *(undefined1 *)(param_4 + 0xc);
  *(undefined1 *)((int)this + 0x1e) = *(undefined1 *)(param_5 + 0xc);
  *(byte *)((int)this + 0x20) =
       *(byte *)((int)this + 0x20) ^
       ((*(int *)(param_2 + 0x14) != 0) << 6 ^ *(byte *)((int)this + 0x20)) & 0x40;
  *(byte *)((int)this + 0x20) =
       (*(int *)(param_2 + 0x10) != 0) << 7 | *(byte *)((int)this + 0x20) & 0x7f;
  *(byte *)((int)this + 0x21) =
       *(byte *)((int)this + 0x21) ^
       (*(int *)((int)param_3 + 0x14) != 0 ^ *(byte *)((int)this + 0x21)) & 1;
  fVar2 = _DAT_00b2c060;
  bVar5 = ((*(int *)((int)param_3 + 0x10) != 0) * '\x02' ^ *(byte *)((int)this + 0x21)) & 2 ^
          *(byte *)((int)this + 0x21);
  *(byte *)((int)this + 0x21) = bVar5;
  bVar5 = ((*(int *)(param_4 + 0x14) != 0) * '\x04' ^ bVar5) & 4 ^ bVar5;
  *(byte *)((int)this + 0x21) = bVar5;
  bVar5 = ((*(int *)(param_4 + 0x10) != 0) * '\b' ^ bVar5) & 8 ^ bVar5;
  *(byte *)((int)this + 0x21) = bVar5;
  bVar5 = ((*(int *)(param_5 + 0x14) != 0) << 4 ^ bVar5) & 0x10 ^ bVar5;
  *(byte *)((int)this + 0x21) = bVar5;
  *(byte *)((int)this + 0x21) = ((*(int *)(param_5 + 0x10) != 0) << 5 ^ bVar5) & 0x20 ^ bVar5;
  *(uint *)((int)this + 0x1c) =
       *(uint *)((int)this + 0x1c) ^
       (*(int *)(param_1 + 100) << 0x1b ^ *(uint *)((int)this + 0x1c)) & 0x18000000;
  *(uint *)((int)this + 0x1c) =
       (*(int *)(param_1 + 0x68) << 0x1d ^ *(uint *)((int)this + 0x1c)) & 0x60000000 ^
       *(uint *)((int)this + 0x1c);
  *(byte *)((int)this + 0x21) = (char)param_1[0x1c] << 7 | *(byte *)((int)this + 0x21) & 0x7f;
  *(uint *)((int)this + 0x1c) =
       *(uint *)((int)this + 0x1c) ^
       (*(int *)(param_1 + 0x88) << 0x18 ^ *(uint *)((int)this + 0x1c)) & 0x7000000;
  iVar1 = *(int *)(param_1 + 0x8c);
  *(undefined1 *)((int)this + 0x11) = 0;
  *(byte *)((int)this + 0x20) = *(byte *)((int)this + 0x20) & 0xc0;
  *(undefined1 *)((int)this + 0x12) = 0;
  *(byte *)((int)this + 0x21) =
       *(byte *)((int)this + 0x21) ^ ((iVar1 != 0) << 6 ^ *(byte *)((int)this + 0x21)) & 0x40;
  uVar4 = GmFunc::RealToNat8(*(float *)(param_1 + 8),fVar2,1.0);
  *(uchar *)((int)this + 0xe) = uVar4;
  uVar4 = GmFunc::RealToNat8(*(float *)(param_1 + 0xc),0.0,1.0);
  *(uchar *)((int)this + 0xf) = uVar4;
  uVar4 = GmFunc::RealToNat8(*(float *)(param_1 + 0x10),0.0,1.0);
  *(uchar *)((int)this + 0x10) = uVar4;
  uVar4 = GmFunc::RealToNat8(*(float *)(param_1 + 0x24),_DAT_00b2c060,1.0);
  *(uchar *)((int)this + 0x13) = uVar4;
  uVar4 = GmFunc::RealToNat8(*(float *)(param_1 + 0x28),_DAT_00b2c060,1.0);
  *(uchar *)((int)this + 0x14) = uVar4;
  return;
}
}

