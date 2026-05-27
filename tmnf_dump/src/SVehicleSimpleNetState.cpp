// Class implementation: SVehicleSimpleNetState

// =================================================
// Function: SVehicleSimpleNetState::RestoreFromStruct
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
SVehicleSimpleNetState::RestoreFromStruct
          (void *this,SVehicleSimpleState_ReplayAfter040104 *param_1,SVehicleCarState *param_2,
          SState *param_3,SState *param_4,SState *param_5,SState *param_6)
{
{
  byte bVar1;
  float10 fVar2;
  
  bVar1 = *(byte *)this;
  *(undefined2 *)(param_3 + 0xc) = 0x10;
  if ((bVar1 & 1) == 0) {
    *(undefined4 *)(param_3 + 0x14) = 0;
    *(undefined4 *)(param_3 + 0x10) = 0;
  }
  else {
    *(undefined4 *)(param_3 + 0x14) = 1;
    *(undefined4 *)(param_3 + 0x10) = 1;
  }
  bVar1 = *(byte *)this;
  *(undefined2 *)(param_4 + 0xc) = 0x10;
  if ((bVar1 & 2) == 0) {
    *(undefined4 *)(param_4 + 0x14) = 0;
    *(undefined4 *)(param_4 + 0x10) = 0;
  }
  else {
    *(undefined4 *)(param_4 + 0x14) = 1;
    *(undefined4 *)(param_4 + 0x10) = 1;
  }
  bVar1 = *(byte *)this;
  *(undefined2 *)(param_5 + 0xc) = 0x10;
  if ((bVar1 & 4) == 0) {
    *(undefined4 *)(param_5 + 0x14) = 0;
    *(undefined4 *)(param_5 + 0x10) = 0;
  }
  else {
    *(undefined4 *)(param_5 + 0x14) = 1;
    *(undefined4 *)(param_5 + 0x10) = 1;
  }
  bVar1 = *(byte *)this;
  *(undefined2 *)(param_6 + 0xc) = 0x10;
  if ((bVar1 & 8) == 0) {
    *(undefined4 *)(param_6 + 0x14) = 0;
    *(undefined4 *)(param_6 + 0x10) = 0;
  }
  else {
    *(undefined4 *)(param_6 + 0x14) = 1;
    *(undefined4 *)(param_6 + 0x10) = 1;
  }
  *(uint *)(param_1 + 100) = *(byte *)this >> 4 & 3;
  fVar2 = (float10)func_0x009c2390();
  *(float *)(param_1 + 0x80) = (float)fVar2 * (float)param_2;
  return;
}
}

// =================================================
// Function: SVehicleSimpleNetState::SaveToStruct
// =================================================
void __thiscall
SVehicleSimpleNetState::SaveToStruct
          (void *this,SVehicleSimpleNetState *param_1,SVehicleCarState *param_2,float param_3,
          ulong param_4,int param_5,SState *param_6,int param_7,SState *param_8,int param_9,
          SState *param_10,int param_11,SState *param_12,int param_13)
{
{
  short sVar1;
  char cVar2;
  uchar uVar3;
  byte bVar4;
  float10 fVar5;
  float fVar6;
  float fVar7;
  
  sVar1 = *(short *)(param_5 + 0xc);
  if (((((sVar1 == 0) || (sVar1 == 0x10)) || (sVar1 == 0x13)) && (*(int *)(param_5 + 0x10) != 0)) &&
     ((*(int *)(param_5 + 0x14) != 0 ||
      ((*(int *)(param_1 + 0x1c) != 0 && (param_6 == (SState *)0x0)))))) {
    bVar4 = 1;
  }
  else {
    bVar4 = 0;
  }
  *(byte *)this = *(byte *)this ^ (*(byte *)this ^ bVar4) & 1;
  sVar1 = *(short *)(param_7 + 0xc);
  if (((((sVar1 == 0) || (sVar1 == 0x10)) || (sVar1 == 0x13)) && (*(int *)(param_7 + 0x10) != 0)) &&
     ((*(int *)(param_7 + 0x14) != 0 ||
      ((*(int *)(param_1 + 0x1c) != 0 && (param_8 == (SState *)0x0)))))) {
    cVar2 = '\x01';
  }
  else {
    cVar2 = '\0';
  }
  bVar4 = (cVar2 * '\x02' ^ *(byte *)this) & 2 ^ *(byte *)this;
  *(byte *)this = bVar4;
  sVar1 = *(short *)(param_9 + 0xc);
  if ((((sVar1 == 0) || (sVar1 == 0x10)) || (sVar1 == 0x13)) &&
     ((*(int *)(param_9 + 0x10) != 0 &&
      ((*(int *)(param_9 + 0x14) != 0 ||
       ((*(int *)(param_1 + 0x1c) != 0 && (param_10 == (SState *)0x0)))))))) {
    cVar2 = '\x01';
  }
  else {
    cVar2 = '\0';
  }
  bVar4 = (cVar2 * '\x04' ^ bVar4) & 4 ^ bVar4;
  *(byte *)this = bVar4;
  sVar1 = *(short *)(param_11 + 0xc);
  if ((((sVar1 == 0) || (sVar1 == 0x10)) || (sVar1 == 0x13)) &&
     ((*(int *)(param_11 + 0x10) != 0 &&
      ((*(int *)(param_11 + 0x14) != 0 ||
       ((*(int *)(param_1 + 0x1c) != 0 && (param_12 == (SState *)0x0)))))))) {
    cVar2 = '\x01';
  }
  else {
    cVar2 = '\0';
  }
  bVar4 = (cVar2 << 3 ^ bVar4) & 8 ^ bVar4;
  *(byte *)this = bVar4;
  fVar7 = 1.0;
  *(byte *)this = ((char)param_1[100] << 4 ^ bVar4) & 0x30 ^ bVar4;
  fVar6 = 0.0;
  fVar5 = (float10)func_0x009c2390();
  uVar3 = GmFunc::RealToNat7((float)fVar5,fVar6,fVar7);
  *(byte *)this = *(byte *)this & 0x3f | param_3._0_1_ << 6;
  *(uchar *)((int)this + 1) = param_4 != 0 ^ uVar3 * '\x02';
  return;
}
}

