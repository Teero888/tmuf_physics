// Class implementation: SVehicleSimpleState_ReplayAfter211003

// =================================================
// Function: SVehicleSimpleState_ReplayAfter211003::RestoreFromStruct
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
SVehicleSimpleState_ReplayAfter211003::RestoreFromStruct
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
  fVar2 = (float)_DAT_00b55d50;
  *(float *)(param_1 + 0x18) = ((float)*(byte *)((int)this + 6) / fVar2) * 1.0 + 0.0;
  *(uint *)(param_1 + 0x14) = *(byte *)((int)this + 0x14) & 1;
  fVar1 = (float)_DAT_00b59bb8;
  fVar3 = ((float)*(byte *)((int)this + 7) / fVar2) * fVar1 - (float)_DAT_00b36110;
  *(float *)(param_2 + 8) = fVar3;
  *(float *)(param_3 + 8) = fVar3;
  *(undefined4 *)(param_4 + 8) = 0;
  *(undefined4 *)(param_5 + 8) = 0;
  fVar4 = (float)_DAT_00b3d2c8;
  fVar3 = (float)_DAT_00b33a58;
  *(float *)param_2 = ((float)*(byte *)((int)this + 8) / fVar2) * fVar4 - fVar3;
  *(float *)param_3 = ((float)*(byte *)((int)this + 0xb) / fVar2) * fVar4 - fVar3;
  *(float *)param_4 = ((float)*(byte *)((int)this + 0xe) / fVar2) * fVar4 - fVar3;
  *(float *)param_5 = ((float)*(byte *)((int)this + 0x11) / fVar2) * fVar4 - fVar3;
  fVar1 = fVar1 - 0.0;
  *(float *)(param_2 + 4) = ((float)*(byte *)((int)this + 9) / fVar2) * fVar1 + 0.0;
  *(float *)(param_3 + 4) = ((float)*(byte *)((int)this + 0xc) / fVar2) * fVar1 + 0.0;
  *(float *)(param_4 + 4) = ((float)*(byte *)((int)this + 0xf) / fVar2) * fVar1 + 0.0;
  *(float *)(param_5 + 4) = fVar1 * ((float)*(byte *)((int)this + 0x12) / fVar2) + 0.0;
  *(ushort *)(param_2 + 0xc) = (ushort)*(byte *)((int)this + 10);
  *(ushort *)(param_3 + 0xc) = (ushort)*(byte *)((int)this + 0xd);
  *(ushort *)(param_4 + 0xc) = (ushort)*(byte *)((int)this + 0x10);
  *(ushort *)(param_5 + 0xc) = (ushort)*(byte *)((int)this + 0x13);
  *(uint *)(param_2 + 0x14) = *(byte *)((int)this + 0x14) >> 1 & 1;
  *(uint *)(param_2 + 0x10) = *(byte *)((int)this + 0x14) >> 2 & 1;
  *(uint *)(param_3 + 0x14) = *(byte *)((int)this + 0x14) >> 3 & 1;
  *(uint *)(param_3 + 0x10) = *(byte *)((int)this + 0x14) >> 4 & 1;
  *(uint *)(param_4 + 0x14) = *(byte *)((int)this + 0x14) >> 5 & 1;
  *(uint *)(param_4 + 0x10) = *(byte *)((int)this + 0x14) >> 6 & 1;
  *(uint *)(param_5 + 0x14) = (uint)(*(byte *)((int)this + 0x14) >> 7);
  *(uint *)(param_5 + 0x10) = *(byte *)((int)this + 0x15) & 1;
  *(uint *)(param_1 + 100) = *(ushort *)((int)this + 0x14) >> 9 & 3;
  *(uint *)(param_1 + 0x68) = *(ushort *)((int)this + 0x14) >> 0xb & 3;
  return;
}
}

