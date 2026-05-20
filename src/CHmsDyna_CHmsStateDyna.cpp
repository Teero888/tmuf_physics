// Class implementation: CHmsDyna_CHmsStateDyna

// =================================================
// Function: CHmsDyna::CHmsStateDyna::OldRestoreState
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsDyna::CHmsStateDyna::OldRestoreState
          (void *this,CHmsStateDyna *param_1,CClassicBufferMemory *param_2,uchar param_3)
{
{
  float fVar1;
  uint uVar2;
  int iVar3;
  undefined4 *this_00;
  byte bVar4;
  float *pfVar5;
  float *pfVar6;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST0_04;
  float10 extraout_ST0_05;
  float10 extraout_ST0_06;
  float10 extraout_ST0_07;
  float10 extraout_ST0_08;
  float10 extraout_ST0_09;
  float10 extraout_ST0_10;
  float10 fVar7;
  float10 extraout_ST0_11;
  float10 extraout_ST0_12;
  float10 extraout_ST0_13;
  float10 extraout_ST0_14;
  float10 extraout_ST0_15;
  float10 extraout_ST0_16;
  float10 extraout_ST0_17;
  float10 extraout_ST0_18;
  float10 extraout_ST0_19;
  float10 extraout_ST0_20;
  float fVar8;
  uint local_34;
  float local_2c;
  float local_28;
  float local_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pfVar5 = (float *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc));
  bVar4 = (byte)param_2;
  if ((byte)param_2 == 0xff) {
    bVar4 = *(byte *)pfVar5;
    pfVar5 = (float *)((int)pfVar5 + 1);
  }
  uVar2 = (uint)bVar4;
  this_00 = (undefined4 *)(uVar2 & 0x10);
  local_24 = (float)(uVar2 & 0x20);
  uVar2 = uVar2 & 0x80;
  local_34 = uVar2;
  if ((bVar4 & 0xf) == 0) {
    local_34 = 1;
  }
  iVar3 = 0x10;
  if ((bVar4 & 0x10) == 0) {
    if ((bVar4 & 0x20) != 0) {
      if (local_34 != 0) {
        iVar3 = 0x1c;
      }
      if ((bVar4 & 0x40) != 0) {
        iVar3 = iVar3 + 0xc;
      }
    }
  }
  else if ((bVar4 & 0x20) != 0) {
    if (local_34 != 0) {
      iVar3 = 0x14;
    }
    if ((bVar4 & 0x40) != 0) {
      iVar3 = iVar3 + 4;
    }
  }
  iVar3 = iVar3 - (uint)((byte)param_2 != 0xff);
  (**(code **)(*(int *)param_1 + 0x28))();
  if ((bVar4 & 0xf) == 0) {
    uVar2 = 1;
  }
  if ((bVar4 & 0x40) == 0) {
    fStack_1c = (float)_DAT_00b55d40;
    local_24 = (float)(int)((*(byte *)pfVar5 - 0x80) * 0x10000 + (uint)*(ushort *)((int)pfVar5 + 1))
               * fStack_1c;
    fStack_20 = (float)(int)((*(byte *)((int)pfVar5 + 3) - 0x80) * 0x10000 +
                            (uint)*(ushort *)(pfVar5 + 1)) * fStack_1c;
    pfVar6 = (float *)((int)pfVar5 + 9);
    fStack_1c = fStack_1c *
                (float)(int)((*(byte *)((int)pfVar5 + 6) - 0x80) * 0x10000 +
                            (uint)*(ushort *)((int)pfVar5 + 7));
  }
  else {
    local_24 = *pfVar5;
    pfVar6 = pfVar5 + 3;
    fStack_20 = pfVar5[1];
    fStack_1c = pfVar5[2];
  }
  this_00[0xd] = local_24;
  this_00[0xe] = fStack_20;
  this_00[0xf] = fStack_1c;
  if ((bVar4 & 0x40) == 0) {
    fVar8 = ((float)*(ushort *)pfVar6 * (float)_DAT_00b36110) / (float)_DAT_00b52a58;
    pfVar5 = (float *)((int)pfVar6 + 6);
    __CIcos();
    __CIcos();
    local_2c = (float)extraout_ST0_06;
    local_24 = local_2c * (float)extraout_ST0_05;
    __CIsin();
    fStack_20 = (float)extraout_ST0_07 * (float)extraout_ST0_05;
    __CIsin();
    fStack_1c = (float)extraout_ST0_08;
    __CIsin();
    fStack_8 = (float)extraout_ST0_09;
    fStack_10 = fStack_8 * local_24;
    fStack_c = fStack_20 * fStack_8;
    fStack_8 = fStack_8 * fStack_1c;
    __CIcos();
    fVar7 = extraout_ST0_10;
  }
  else {
    pfVar5 = (float *)((int)pfVar6 + 3);
    fVar8 = ((float)(int)(char)*(byte *)((int)pfVar6 + 2) * (float)_DAT_00b36be8) /
            (float)_DAT_00b55d48;
    __CIcos();
    __CIcos();
    local_2c = (float)extraout_ST0_00;
    local_24 = local_2c * (float)extraout_ST0;
    __CIsin();
    fStack_20 = (float)extraout_ST0_01 * (float)extraout_ST0;
    __CIsin();
    fStack_1c = (float)extraout_ST0_02;
    __CIsin();
    fStack_8 = (float)extraout_ST0_03;
    fStack_10 = fStack_8 * local_24;
    fStack_c = fStack_20 * fStack_8;
    fStack_8 = fStack_8 * fStack_1c;
    __CIcos();
    fVar7 = extraout_ST0_04;
  }
  local_24 = (float)fVar7;
  fStack_20 = fStack_10;
  fStack_18 = fStack_8;
  fStack_1c = fStack_c;
  fStack_14 = local_24;
  GmVec4::Set(this_00,(CMwCmdScriptVarBool *)&local_24,iVar3);
  GmMat3::Set(this_00 + 4,(CMwCmdScriptVarBool *)*this_00,this_00[1]);
  if (local_2c != 0.0) {
    pfVar6 = pfVar5;
    if (uVar2 != 0) {
      if ((bVar4 & 0x40) == 0) {
        local_28 = *pfVar5;
        pfVar6 = pfVar5 + 3;
        local_24 = pfVar5[1];
        fStack_20 = pfVar5[2];
      }
      else {
        if (*(ushort *)pfVar5 == 0x8000) {
          fVar1 = 0.0;
        }
        else {
          __CIexp();
          fVar1 = (float)extraout_ST0_11;
        }
        fStack_4 = (float)(int)(char)*(byte *)((int)pfVar5 + 3);
        pfVar6 = pfVar5 + 1;
        __CIcos();
        fStack_4 = (float)extraout_ST0_12;
        __CIcos();
        fStack_18 = (float)extraout_ST0_13 * fStack_4;
        __CIsin();
        fStack_14 = (float)extraout_ST0_14 * fStack_4;
        __CIsin();
        fStack_10 = (float)extraout_ST0_15;
        local_28 = fVar1 * fStack_18;
        local_24 = fStack_14 * fVar1;
        fStack_20 = fVar1 * fStack_10;
      }
      this_00[0x10] = local_28;
      this_00[0x11] = local_24;
      this_00[0x12] = fStack_20;
    }
    if (fVar8 != 0.0) {
      if ((bVar4 & 0x40) == 0) {
        local_28 = *pfVar6;
        local_24 = pfVar6[1];
        fVar8 = pfVar6[2];
      }
      else {
        if (*(ushort *)pfVar6 == 0x8000) {
          fVar8 = 0.0;
        }
        else {
          __CIexp();
          fVar8 = (float)extraout_ST0_16;
        }
        fStack_4 = (float)(int)(char)*(byte *)((int)pfVar6 + 3);
        __CIcos();
        fStack_4 = (float)extraout_ST0_17;
        __CIcos();
        fStack_18 = (float)extraout_ST0_18 * fStack_4;
        __CIsin();
        fStack_14 = (float)extraout_ST0_19 * fStack_4;
        __CIsin();
        local_28 = fVar8 * fStack_18;
        local_24 = fStack_14 * fVar8;
        fVar8 = fVar8 * (float)extraout_ST0_20;
      }
      this_00[0x16] = local_28;
      this_00[0x17] = local_24;
      this_00[0x18] = fVar8;
    }
  }
  return;
}
}

// =================================================
// Function: CHmsDyna::CHmsStateDyna::Reset
// =================================================
void __thiscall CHmsDyna::CHmsStateDyna::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined4 *)((int)this + 0x68) = 0;
  *(undefined4 *)((int)this + 100) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x70) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0xa0) = 0;
  *(undefined4 *)((int)this + 0xac) = 0;
  *(undefined4 *)((int)this + 0xa8) = 0;
  *(undefined4 *)((int)this + 0xa4) = 0;
  return;
}
}

// =================================================
// Function: CHmsDyna::CHmsStateDyna::RestoreState
// =================================================
void __thiscall
CHmsDyna::CHmsStateDyna::RestoreState
          (void *this,CHmsStateDyna *param_1,CClassicBufferMemory *param_2,uchar param_3)
{
{
  if (((uint)param_2 & 0xff) == 0) {
    GmArchive::ReadVec3Pos_9((CClassicBuffer *)param_1,(GmVec3 *)((int)this + 0x34));
    GmArchive::ReadQuat_6((CClassicBuffer *)param_1,this);
    GmMat3::Set((void *)((int)this + 0x10),*(CMwCmdScriptVarBool **)this,*(int *)((int)this + 4));
  }
  else if (((uint)param_2 & 0xff) == 1) {
    GmArchive::ReadVec3Pos_12((CClassicBuffer *)param_1,(GmVec3 *)((int)this + 0x34));
    GmArchive::ReadQuat_6((CClassicBuffer *)param_1,this);
    GmMat3::Set((void *)((int)this + 0x10),*(CMwCmdScriptVarBool **)this,*(int *)((int)this + 4));
    GmArchive::ReadVec3_4((CClassicBuffer *)param_1,(GmVec3 *)((int)this + 0x40));
    GmArchive::ReadVec3_4((CClassicBuffer *)param_1,(GmVec3 *)((int)this + 0x58));
    return;
  }
  return;
}
}

