
/* public: void __thiscall CHmsDyna::AddForce(class GmVec3 const &,class GmVec3
 * const &) */

void __thiscall CHmsDyna::AddForce(CHmsDyna *this, GmVec3 *param_1,
                                   GmVec3 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float *pfVar10;

  iVar5 = *(int *)(this + 0x32c);
  iVar6 = *(int *)(this + 0x108);
  pfVar10 = (float *)(iVar6 + 0x38);
  *(float *)(iVar5 + 100) = *(float *)param_1 + *(float *)(iVar5 + 100);
  *(float *)(iVar5 + 0x68) = *(float *)(iVar5 + 0x68) + *(float *)(param_1 + 4);
  *(float *)(iVar5 + 0x6c) = *(float *)(iVar5 + 0x6c) + *(float *)(param_1 + 8);
  fVar7 =
      *(float *)param_2 - (*(float *)(iVar5 + 0x18) * *(float *)(iVar6 + 0x40) +
                           *pfVar10 * *(float *)(iVar5 + 0x10) +
                           *(float *)(iVar5 + 0x14) * *(float *)(iVar6 + 0x3c) +
                           *(float *)(iVar5 + 0x34));
  fVar8 = *(float *)(param_2 + 4) -
          (*(float *)(iVar5 + 0x24) * *(float *)(iVar6 + 0x40) +
           *(float *)(iVar5 + 0x1c) * *pfVar10 +
           *(float *)(iVar5 + 0x20) * *(float *)(iVar6 + 0x3c) +
           *(float *)(iVar5 + 0x38));
  fVar9 = *(float *)(param_2 + 8) -
          (*(float *)(iVar5 + 0x30) * *(float *)(iVar6 + 0x40) +
           *(float *)(iVar5 + 0x28) * *pfVar10 +
           *(float *)(iVar5 + 0x2c) * *(float *)(iVar6 + 0x3c) +
           *(float *)(iVar5 + 0x3c));
  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_1 + 8);
  fVar3 = *(float *)(param_1 + 4);
  fVar4 = *(float *)param_1;
  *(float *)(iVar5 + 0x70) =
      *(float *)(iVar5 + 0x70) +
      (fVar8 * *(float *)(param_1 + 8) - fVar9 * *(float *)(param_1 + 4));
  *(float *)(iVar5 + 0x74) =
      *(float *)(iVar5 + 0x74) + (fVar1 * fVar9 - fVar7 * fVar2);
  *(float *)(iVar5 + 0x78) =
      *(float *)(iVar5 + 0x78) + (fVar3 * fVar7 - fVar8 * fVar4);
  return;
}

/* public: void __thiscall CHmsDyna::AddForce(class GmVec3 const &) */

void __thiscall CHmsDyna::AddForce(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;

  iVar1 = *(int *)(this + 0x32c);
  *(float *)(iVar1 + 100) = *(float *)(iVar1 + 100) + *(float *)param_1;
  *(float *)(iVar1 + 0x68) = *(float *)(param_1 + 4) + *(float *)(iVar1 + 0x68);
  *(float *)(iVar1 + 0x6c) = *(float *)(param_1 + 8) + *(float *)(iVar1 + 0x6c);
  return;
}

/* private: struct CHmsDyna::SHistoryPoint * __thiscall
   CHmsDyna::AddHistoryPoint(class GmVec3 const
   &,class GmMat3 const &,unsigned long) */

SHistoryPoint *__thiscall CHmsDyna::AddHistoryPoint(CHmsDyna *this,
                                                    GmVec3 *param_1,
                                                    GmMat3 *param_2,
                                                    ulong param_3)

{
  ulong uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;

  uVar1 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x344));
  if (uVar1 != 0) {
    uVar2 = *(uint *)(this + 0x350);
    if (*(uint *)(this + 0x34c) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(this + 0x34c);
    }
    if (param_3 <= *(uint *)(uVar2 * 0xe0 + 0xa8 + *(int *)(this + 0x348))) {
      return (SHistoryPoint *)0x0;
    }
  }
  puVar3 = (undefined4 *)CFastBufferWheel<>::PushNewElem(
      (CFastBufferWheel<> *)(CFastBuffer<> *)(this + 0x344));
  *puVar3 = *(undefined4 *)param_1;
  puVar3[1] = *(undefined4 *)(param_1 + 4);
  puVar3[2] = *(undefined4 *)(param_1 + 8);
  puVar5 = puVar3 + 9;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *(undefined4 *)param_2;
    param_2 = (GmMat3 *)((int)param_2 + 4);
    puVar5 = puVar5 + 1;
  }
  puVar3[5] = 0;
  puVar3[4] = 0;
  puVar3[3] = 0;
  puVar3[0x14] = 0;
  puVar3[0x13] = 0;
  puVar3[0x12] = 0;
  puVar3[0x17] = 0;
  puVar3[0x16] = 0;
  puVar3[0x15] = 0;
  puVar3[0x1a] = 0;
  puVar3[0x19] = 0;
  puVar3[0x18] = 0;
  puVar3[0x2a] = param_3;
  puVar3[0x2b] = 0;
  return (SHistoryPoint *)puVar3;
}

/* public: void __thiscall CHmsDyna::AddImpulse(class GmVec3 const &,class
 * GmVec3 const &) */

void __thiscall CHmsDyna::AddImpulse(CHmsDyna *this, GmVec3 *param_1,
                                     GmVec3 *param_2)

{
  int iVar1;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  if (*(int *)(this + 0x340) != 2) {
    if (*(int *)(this + 0x33c) == 0) {
      *(undefined4 *)(this + 0x33c) = 1;
    }
    iVar1 = *(int *)(this + 0x32c);
    local_1c = 1.0 / **(float **)(this + 0x108);
    local_24 = local_1c * *(float *)param_1;
    local_20 = *(float *)(param_1 + 4) * local_1c;
    local_1c = local_1c * *(float *)(param_1 + 8);
    *(float *)(iVar1 + 0x40) = *(float *)(iVar1 + 0x40) + local_24;
    *(float *)(iVar1 + 0x44) = *(float *)(iVar1 + 0x44) + local_20;
    *(float *)(iVar1 + 0x48) = local_1c + *(float *)(iVar1 + 0x48);
    if (*(int *)(this + 0x340) == 1) {
      GmVec3::SetMult((GmVec3 *)&local_c,
                      (GmVec3 *)(*(int *)(this + 0x108) + 0x38),
                      (GmIso4 *)(iVar1 + 0x10));
      local_18 = *(float *)param_2 - local_c;
      local_14 = *(float *)(param_2 + 4) - local_8;
      local_10 = *(float *)(param_2 + 8) - local_4;
      local_24 = local_14 * *(float *)(param_1 + 8) -
                 local_10 * *(float *)(param_1 + 4);
      local_20 =
          local_10 * *(float *)param_1 - local_18 * *(float *)(param_1 + 8);
      local_1c =
          local_18 * *(float *)(param_1 + 4) - *(float *)param_1 * local_14;
      GmVec3::Mult((GmVec3 *)&local_24, (GmMat3 *)(iVar1 + 0x7c));
      *(float *)(iVar1 + 0x58) = *(float *)(iVar1 + 0x58) + local_24;
      *(float *)(iVar1 + 0x5c) = *(float *)(iVar1 + 0x5c) + local_20;
      *(float *)(iVar1 + 0x60) = local_1c + *(float *)(iVar1 + 0x60);
    }
  }
  return;
}

/* public: void __thiscall CHmsDyna::AddImpulse(class GmVec3 const &) */

void __thiscall CHmsDyna::AddImpulse(CHmsDyna *this, GmVec3 *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;

  if (*(int *)(this + 0x340) != 2) {
    if (*(int *)(this + 0x33c) == 0) {
      *(undefined4 *)(this + 0x33c) = 1;
    }
    fVar4 = 1.0 / **(float **)(this + 0x108);
    fVar1 = *(float *)(param_1 + 4);
    fVar2 = *(float *)(param_1 + 8);
    iVar3 = *(int *)(this + 0x32c);
    *(float *)(iVar3 + 0x40) =
        fVar4 * *(float *)param_1 + *(float *)(iVar3 + 0x40);
    *(float *)(iVar3 + 0x44) = *(float *)(iVar3 + 0x44) + fVar1 * fVar4;
    *(float *)(iVar3 + 0x48) = fVar4 * fVar2 + *(float *)(iVar3 + 0x48);
  }
  return;
}

/* public: void __thiscall CHmsDyna::AddLocalForce(class GmVec3 const &,class
 * GmVec3 const &) */

void __thiscall CHmsDyna::AddLocalForce(CHmsDyna *this, GmVec3 *param_1,
                                        GmVec3 *param_2)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  iVar1 = *(int *)(this + 0x32c);
  local_c = *(float *)(iVar1 + 0x18) * *(float *)(param_1 + 8) +
            *(float *)param_1 * *(float *)(iVar1 + 0x10) +
            *(float *)(iVar1 + 0x14) * *(float *)(param_1 + 4);
  local_8 = *(float *)(iVar1 + 0x24) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x20) * *(float *)(param_1 + 4) +
            *(float *)(iVar1 + 0x1c) * *(float *)param_1;
  local_4 = *(float *)(iVar1 + 0x30) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x2c) * *(float *)(param_1 + 4) +
            *(float *)(iVar1 + 0x28) * *(float *)param_1;
  local_18 = *(float *)(iVar1 + 0x18) * *(float *)(param_2 + 8) +
             *(float *)(iVar1 + 0x10) * *(float *)param_2 +
             *(float *)(iVar1 + 0x14) * *(float *)(param_2 + 4) +
             *(float *)(iVar1 + 0x34);
  local_14 = *(float *)(iVar1 + 0x24) * *(float *)(param_2 + 8) +
             *(float *)(iVar1 + 0x1c) * *(float *)param_2 +
             *(float *)(iVar1 + 0x20) * *(float *)(param_2 + 4) +
             *(float *)(iVar1 + 0x38);
  local_10 = *(float *)(iVar1 + 0x30) * *(float *)(param_2 + 8) +
             *(float *)(iVar1 + 0x28) * *(float *)param_2 +
             *(float *)(iVar1 + 0x2c) * *(float *)(param_2 + 4) +
             *(float *)(iVar1 + 0x3c);
  AddForce(this, (GmVec3 *)&local_c, (GmVec3 *)&local_18);
  return;
}

/* public: void __thiscall CHmsDyna::AddLocalForce(class GmVec3 const &) */

void __thiscall CHmsDyna::AddLocalForce(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;

  iVar1 = *(int *)(this + 0x32c);
  local_c = *(float *)(iVar1 + 0x18) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x10) * *(float *)param_1 +
            *(float *)(iVar1 + 0x14) * *(float *)(param_1 + 4);
  local_8 = *(float *)(iVar1 + 0x24) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x20) * *(float *)(param_1 + 4) +
            *(float *)(iVar1 + 0x1c) * *(float *)param_1;
  local_4 = *(float *)(iVar1 + 0x30) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x2c) * *(float *)(param_1 + 4) +
            *(float *)(iVar1 + 0x28) * *(float *)param_1;
  AddForce(this, (GmVec3 *)&local_c);
  return;
}

/* public: void __thiscall CHmsDyna::AddLocalImpulse(class GmVec3 const &,class
 * GmVec3 const &) */

void __thiscall CHmsDyna::AddLocalImpulse(CHmsDyna *this, GmVec3 *param_1,
                                          GmVec3 *param_2)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  iVar1 = *(int *)(this + 0x32c);
  local_c = *(float *)(iVar1 + 0x18) * *(float *)(param_1 + 8) +
            *(float *)param_1 * *(float *)(iVar1 + 0x10) +
            *(float *)(iVar1 + 0x14) * *(float *)(param_1 + 4);
  local_8 = *(float *)(iVar1 + 0x24) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x20) * *(float *)(param_1 + 4) +
            *(float *)(iVar1 + 0x1c) * *(float *)param_1;
  local_4 = *(float *)(iVar1 + 0x30) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x2c) * *(float *)(param_1 + 4) +
            *(float *)(iVar1 + 0x28) * *(float *)param_1;
  local_18 = *(float *)(iVar1 + 0x18) * *(float *)(param_2 + 8) +
             *(float *)(iVar1 + 0x10) * *(float *)param_2 +
             *(float *)(iVar1 + 0x14) * *(float *)(param_2 + 4) +
             *(float *)(iVar1 + 0x34);
  local_14 = *(float *)(iVar1 + 0x24) * *(float *)(param_2 + 8) +
             *(float *)(iVar1 + 0x1c) * *(float *)param_2 +
             *(float *)(iVar1 + 0x20) * *(float *)(param_2 + 4) +
             *(float *)(iVar1 + 0x38);
  local_10 = *(float *)(iVar1 + 0x30) * *(float *)(param_2 + 8) +
             *(float *)(iVar1 + 0x28) * *(float *)param_2 +
             *(float *)(iVar1 + 0x2c) * *(float *)(param_2 + 4) +
             *(float *)(iVar1 + 0x3c);
  AddImpulse(this, (GmVec3 *)&local_c, (GmVec3 *)&local_18);
  return;
}

/* public: void __thiscall CHmsDyna::AddLocalImpulse(class GmVec3 const &) */

void __thiscall CHmsDyna::AddLocalImpulse(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;

  iVar1 = *(int *)(this + 0x32c);
  local_c = *(float *)(iVar1 + 0x18) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x10) * *(float *)param_1 +
            *(float *)(iVar1 + 0x14) * *(float *)(param_1 + 4);
  local_8 = *(float *)(iVar1 + 0x24) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x20) * *(float *)(param_1 + 4) +
            *(float *)(iVar1 + 0x1c) * *(float *)param_1;
  local_4 = *(float *)(iVar1 + 0x30) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x2c) * *(float *)(param_1 + 4) +
            *(float *)(iVar1 + 0x28) * *(float *)param_1;
  AddImpulse(this, (GmVec3 *)&local_c);
  return;
}

/* public: void __thiscall CHmsDyna::AddLocalTorque(class GmVec3 const &) */

void __thiscall CHmsDyna::AddLocalTorque(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;

  iVar1 = *(int *)(this + 0x32c);
  local_c = *(float *)(iVar1 + 0x18) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x10) * *(float *)param_1 +
            *(float *)(iVar1 + 0x14) * *(float *)(param_1 + 4);
  local_8 = *(float *)(iVar1 + 0x24) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x20) * *(float *)(param_1 + 4) +
            *(float *)(iVar1 + 0x1c) * *(float *)param_1;
  local_4 = *(float *)(iVar1 + 0x30) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x2c) * *(float *)(param_1 + 4) +
            *(float *)(iVar1 + 0x28) * *(float *)param_1;
  AddTorque(this, (GmVec3 *)&local_c);
  return;
}

/* public: void __thiscall CHmsDyna::AddReplacement(class GmVec3 const &) */

void __thiscall CHmsDyna::AddReplacement(CHmsDyna *this, GmVec3 *param_1)

{
  if (*(int *)(this + 0x33c) == 0) {
    *(undefined4 *)(this + 0x33c) = 1;
  }
  CFastBuffer<>::Add((CFastBuffer<> *)(this + 0x330), (SCachedValue *)param_1);
  return;
}

/* public: void __thiscall CHmsDyna::AddStateForPrediction(class
   CClassicBufferMemory &,unsigned long,unsigned char) */

void __thiscall CHmsDyna::AddStateForPrediction(CHmsDyna *this,
                                                CClassicBufferMemory *param_1,
                                                ulong param_2, uchar param_3)

{
  CHmsStateDyna local_b4[180];

  CHmsStateDyna::RestoreState(local_b4, param_1, param_3);
  DoPHBInterpolation(this, param_2, local_b4);
  return;
}

/* public: void __thiscall CHmsDyna::AddTorque(class GmVec3 const &) */

void __thiscall CHmsDyna::AddTorque(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;

  iVar1 = *(int *)(this + 0x32c);
  *(float *)(iVar1 + 0x70) = *(float *)(iVar1 + 0x70) + *(float *)param_1;
  *(float *)(iVar1 + 0x74) = *(float *)(param_1 + 4) + *(float *)(iVar1 + 0x74);
  *(float *)(iVar1 + 0x78) = *(float *)(param_1 + 8) + *(float *)(iVar1 + 0x78);
  return;
}

/* public: void __thiscall CHmsDyna::AddTorque(class GmVec3 const &) */

void __thiscall CHmsDyna::AddTorque(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;

  iVar1 = *(int *)(this + 0x32c);
  *(float *)(iVar1 + 0x70) = *(float *)(iVar1 + 0x70) + *(float *)param_1;
  *(float *)(iVar1 + 0x74) = *(float *)(param_1 + 4) + *(float *)(iVar1 + 0x74);
  *(float *)(iVar1 + 0x78) = *(float *)(param_1 + 8) + *(float *)(iVar1 + 0x78);
  return;
}

/* public: __thiscall CHmsDyna::CHmsDyna(void) */

CHmsDyna *__thiscall CHmsDyna::CHmsDyna(CHmsDyna *this)

{
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x330));
  CFastBufferWheel<float>::CFastBufferWheel<float>(
      (CFastBufferWheel<float> *)(this + 0x344));
  *(undefined4 *)(this + 0xc4) = 0x461c4000;
  *(CHmsDyna **)(this + 0x1bc) = this;
  *(CHmsDyna **)(this + 0x270) = this;
  *(undefined4 *)(this + 0x33c) = 1;
  *(undefined4 *)(this + 0x340) = 0;
  *(undefined4 *)(this + 0x108) = 0;
  *(undefined4 *)(this + 0xc0) = 0;
  Reset(this);
  CFastBufferWheel<>::ClearWheel(
      (CFastBufferWheel<> *)(CFastBufferWheel<float> *)(this + 0x344));
  *(undefined4 *)(this + 0x360) = 0;
  *(undefined4 *)(this + 0x35c) = 0;
  *(undefined4 *)(this + 0x358) = 0;
  *(undefined4 *)(this + 0x36c) = 0;
  *(undefined4 *)(this + 0x368) = 0;
  *(undefined4 *)(this + 0x364) = 0;
  *(undefined4 *)(this + 900) = 0;
  *(undefined4 *)(this + 0x380) = 0;
  *(undefined4 *)(this + 0x37c) = 0;
  *(undefined4 *)(this + 0x390) = 0;
  *(undefined4 *)(this + 0x38c) = 0;
  *(undefined4 *)(this + 0x388) = 0;
  *(undefined4 *)(this + 0x39c) = 0;
  *(undefined4 *)(this + 0x398) = 0;
  *(undefined4 *)(this + 0x394) = 0;
  *(undefined4 *)(this + 0x3a8) = 0;
  *(undefined4 *)(this + 0x3a4) = 0;
  *(undefined4 *)(this + 0x3a0) = 0;
  *(undefined4 *)(this + 0x3b4) = 0;
  *(undefined4 *)(this + 0x3b0) = 0;
  *(undefined4 *)(this + 0x3ac) = 0;
  *(undefined4 *)(this + 0x3c0) = 0;
  *(undefined4 *)(this + 0x3bc) = 0;
  *(undefined4 *)(this + 0x3b8) = 0;
  *(undefined4 *)(this + 0x400) = 0;
  *(undefined4 *)(this + 0x440) = 0;
  *(undefined4 *)(this + 0x43c) = 0;
  *(undefined4 *)(this + 0x438) = 0;
  *(undefined4 *)(this + 0x44c) = 0;
  *(undefined4 *)(this + 0x448) = 0;
  *(undefined4 *)(this + 0x444) = 0;
  *(undefined4 *)(this + 0x464) = 0;
  *(undefined4 *)(this + 0x460) = 0;
  *(undefined4 *)(this + 0x45c) = 0;
  *(undefined4 *)(this + 0x470) = 0;
  *(undefined4 *)(this + 0x46c) = 0;
  *(undefined4 *)(this + 0x468) = 0;
  *(undefined4 *)(this + 0x47c) = 0;
  *(undefined4 *)(this + 0x478) = 0;
  *(undefined4 *)(this + 0x474) = 0;
  *(undefined4 *)(this + 0x488) = 0;
  *(undefined4 *)(this + 0x484) = 0;
  *(undefined4 *)(this + 0x480) = 0;
  *(undefined4 *)(this + 0x494) = 0;
  *(undefined4 *)(this + 0x490) = 0;
  *(undefined4 *)(this + 0x48c) = 0;
  *(undefined4 *)(this + 0x4a0) = 0;
  *(undefined4 *)(this + 0x49c) = 0;
  *(undefined4 *)(this + 0x498) = 0;
  *(undefined4 *)(this + 0x104) = 0;
  *(undefined4 *)(this + 0x4e0) = 0;
  *(undefined4 *)(this + 0x518) = 0;
  *(undefined4 *)(this + 0x51c) = 0;
  *(undefined4 *)(this + 0x520) = 0;
  *(undefined4 *)(this + 0x524) = 0;
  *(undefined4 *)(this + 0x528) = 0;
  *(undefined4 *)(this + 0x58c) = 0;
  return this;
}

/* private: void __thiscall CHmsDyna::ChooseInterpolationMethods(float,enum
   CHmsDyna::EPredictionType &,enum CHmsDyna::EPredictionType &) */

void __thiscall CHmsDyna::ChooseInterpolationMethods(CHmsDyna *this,
                                                     float param_1,
                                                     EPredictionType *param_2,
                                                     EPredictionType *param_3)

{
  if (ABS(param_1) < s_SmallMediumAngleThreshold) {
    *param_2 = 3;
    *param_3 = 3;
    return;
  }
  *param_2 = 4;
  *param_3 = 4;
  return;
}

/* private: void __thiscall CHmsDyna::ChooseInterpolationMethods(class GmVec3
   const &,struct CHmsDyna::SPredictionTypeVector &,struct
   CHmsDyna::SPredictionTypeVector &) */

void __thiscall CHmsDyna::ChooseInterpolationMethods(
    CHmsDyna *this, GmVec3 *param_1, SPredictionTypeVector *param_2,
    SPredictionTypeVector *param_3)

{
  ChooseInterpolationMethods(this, *(float *)param_1,
                             (EPredictionType *)param_2,
                             (EPredictionType *)param_3);
  ChooseInterpolationMethods(this, *(float *)(param_1 + 4),
                             (EPredictionType *)(param_2 + 4),
                             (EPredictionType *)(param_3 + 4));
  ChooseInterpolationMethods(this, *(float *)(param_1 + 8),
                             (EPredictionType *)(param_2 + 8),
                             (EPredictionType *)(param_3 + 8));
  return;
}

/* private: void __thiscall CHmsDyna::ComputeEmbraceAngle(class GmVec3 const
   &,class GmVec3 const
   &,class GmVec3 const &,float,float,float,class GmVec3 &) */

void __thiscall CHmsDyna::ComputeEmbraceAngle(CHmsDyna *this, GmVec3 *param_1,
                                              GmVec3 *param_2, GmVec3 *param_3,
                                              float param_4, float param_5,
                                              float param_6, GmVec3 *param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;

  fVar3 = param_4 - param_5;
  fVar1 = param_6 - param_5;
  fVar2 = ComputeEmbraceAngleForValue(
      this, *(float *)param_1 - *(float *)param_2,
      *(float *)param_3 - *(float *)param_2, fVar3, fVar1);
  *(float *)param_7 = fVar2;
  fVar2 = ComputeEmbraceAngleForValue(
      this, *(float *)(param_1 + 4) - *(float *)(param_2 + 4),
      *(float *)(param_3 + 4) - *(float *)(param_2 + 4), fVar3, fVar1);
  *(float *)(param_7 + 4) = fVar2;
  fVar3 = ComputeEmbraceAngleForValue(
      this, *(float *)(param_1 + 8) - *(float *)(param_2 + 8),
      *(float *)(param_3 + 8) - *(float *)(param_2 + 8), fVar3, fVar1);
  *(float *)(param_7 + 8) = fVar3;
  return;
}

/* private: float __thiscall
 * CHmsDyna::ComputeEmbraceAngleForValue(float,float,float,float) */

float __thiscall CHmsDyna::ComputeEmbraceAngleForValue(
    CHmsDyna *this, float param_1, float param_2, float param_3, float param_4)

{
  float10 fVar1;

  __CIsqrt();
  fVar1 = (float10)__CIacos();
  return (float)fVar1;
}

/* private: void __thiscall CHmsDyna::ComputeInterpolationConvergencePoint(void)
 */

void __thiscall CHmsDyna::ComputeInterpolationConvergencePoint(CHmsDyna *this)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  int extraout_EDX;
  undefined4 *puVar12;
  undefined4 *puVar13;
  float local_8;

  uVar10 = *(uint *)(this + 0x350);
  if (*(uint *)(this + 0x34c) <= uVar10) {
    uVar10 = uVar10 - *(uint *)(this + 0x34c);
  }
  puVar11 = (undefined4 *)(uVar10 * 0xe0 + *(int *)(this + 0x348));
  uVar10 = *(int *)(this + 0x350) + 1;
  if (*(uint *)(this + 0x34c) <= uVar10) {
    uVar10 = uVar10 - *(uint *)(this + 0x34c);
  }
  iVar5 = uVar10 * 0xe0 + *(int *)(this + 0x348);
  *(undefined4 *)(this + 0x358) = *(undefined4 *)(this + 0x52c);
  uVar1 = *(undefined4 *)(this + 0x534);
  *(undefined4 *)(this + 0x35c) = *(undefined4 *)(this + 0x530);
  puVar12 = (undefined4 *)(this + 0x538);
  puVar13 = (undefined4 *)(this + 0x37c);
  for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar13 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar13 = puVar13 + 1;
  }
  *(undefined4 *)(this + 0x364) = *(undefined4 *)(this + 0x55c);
  *(undefined4 *)(this + 0x360) = uVar1;
  *(undefined4 *)(this + 0x368) = *(undefined4 *)(this + 0x560);
  uVar10 = *(uint *)(this + 0x58c);
  *(undefined4 *)(this + 0x36c) = *(undefined4 *)(this + 0x564);
  puVar12 = (undefined4 *)(this + 0x568);
  puVar13 = (undefined4 *)(this + 0x3a0);
  for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar13 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar13 = puVar13 + 1;
  }
  *(uint *)(this + 0x400) = uVar10;
  if ((uVar10 < *(uint *)(this + 0x51c)) ||
      (uVar9 = uVar10 - *(uint *)(this + 0x51c), 99 < uVar9)) {
    uVar9 = 100;
  }
  if ((uint)puVar11[0x2a] < uVar10 + uVar9) {
    if (uVar9 < 0x33) {
      uVar9 = 0x32;
    }
    *(uint *)(this + 0x4e0) = uVar10 + uVar9;
    uVar6 = (uVar10 + uVar9) - puVar11[0x2a];
    ComputeNextPosition(this, (GmVec3 *)puVar11, (GmVec3 *)(puVar11 + 3),
                        (GmVec3 *)(puVar11 + 6), uVar6,
                        (GmVec3 *)(this + 0x438));
    fVar2 = (float)uVar6;
    if ((int)uVar6 < 0) {
      fVar2 = fVar2 + 4.294967e+09;
    }
    fVar4 = (float)*(int *)(extraout_EDX + 0xa8);
    if (*(int *)(extraout_EDX + 0xa8) < 0) {
      fVar4 = fVar4 + 4.294967e+09;
    }
    fVar3 = (float)*(int *)(iVar5 + 0xa8);
    if (*(int *)(iVar5 + 0xa8) < 0) {
      fVar3 = fVar3 + 4.294967e+09;
    }
    local_8 = (fVar2 * 0.001) / (fVar4 * 0.001 - fVar3 * 0.001) + 1.0;
    if (2.0 < local_8 != NAN(local_8)) {
      local_8 = 2.0;
    }
    GmMat3::SetBlend((GmMat3 *)(this + 0x45c), (GmMat3 *)(iVar5 + 0x24),
                     (GmMat3 *)(extraout_EDX + 0x24), local_8);
    uVar7 = GmMat3::IsOrthonormal((GmMat3 *)(this + 0x45c));
    if (uVar7 == 0) {
      GmMat3::OrthoNormalize((GmMat3 *)(this + 0x45c));
    }
    ComputeNextSpeed(this, (GmVec3 *)(puVar11 + 3), (GmVec3 *)(puVar11 + 6),
                     uVar6, (GmVec3 *)(this + 0x444));
    return;
  }
  if (uVar9 != 0) {
    *(undefined4 *)(this + 0x520) = 0;
    *(undefined4 *)(this + 0x51c) = 0;
    *(undefined4 *)(this + 0x4e0) = puVar11[0x2a];
    *(undefined4 *)(this + 0x438) = *puVar11;
    *(undefined4 *)(this + 0x43c) = puVar11[1];
    *(undefined4 *)(this + 0x440) = puVar11[2];
    puVar12 = puVar11 + 9;
    puVar13 = (undefined4 *)(this + 0x45c);
    for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar13 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar13 = puVar13 + 1;
    }
    *(undefined4 *)(this + 0x444) = puVar11[3];
    *(undefined4 *)(this + 0x448) = puVar11[4];
    *(undefined4 *)(this + 0x44c) = puVar11[5];
    puVar11 = puVar11 + 0x12;
    puVar12 = (undefined4 *)(this + 0x480);
    for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
    return;
  }
  *(undefined4 *)(this + 0x528) = 0;
  return;
}

/* private: void __thiscall CHmsDyna::ComputeInterpolationMethods(void) */

void __thiscall CHmsDyna::ComputeInterpolationMethods(CHmsDyna *this)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  GmVec3 *pGVar6;
  GmVec3 *pGVar7;
  uint uVar8;
  GmVec3 *pGVar9;
  GmVec3 local_3c[12];
  GmQuat local_30[16];
  GmQuat local_20[16];
  GmQuat local_10[16];

  uVar1 = *(uint *)(this + 0x34c);
  uVar5 = *(int *)(this + 0x350) + 2;
  if (uVar1 <= uVar5) {
    uVar5 = uVar5 - uVar1;
  }
  pGVar6 = (GmVec3 *)(uVar5 * 0xe0 + *(int *)(this + 0x348));
  uVar5 = *(int *)(this + 0x350) + 1;
  if (uVar1 <= uVar5) {
    uVar5 = uVar5 - uVar1;
  }
  uVar8 = *(uint *)(this + 0x350);
  pGVar7 = (GmVec3 *)(uVar5 * 0xe0 + *(int *)(this + 0x348));
  if (uVar1 <= uVar8) {
    uVar8 = uVar8 - uVar1;
  }
  pGVar9 = (GmVec3 *)(uVar8 * 0xe0 + *(int *)(this + 0x348));
  fVar2 = (float)*(int *)(pGVar9 + 0xa8);
  if (*(int *)(pGVar9 + 0xa8) < 0) {
    fVar2 = fVar2 + 4.294967e+09;
  }
  fVar4 = (float)*(int *)(pGVar7 + 0xa8);
  if (*(int *)(pGVar7 + 0xa8) < 0) {
    fVar4 = fVar4 + 4.294967e+09;
  }
  fVar3 = (float)*(int *)(pGVar6 + 0xa8);
  if (*(int *)(pGVar6 + 0xa8) < 0) {
    fVar3 = fVar3 + 4.294967e+09;
  }
  ComputeEmbraceAngle(this, pGVar6, pGVar7, pGVar9, fVar3 * 0.001,
                      fVar4 * 0.001, fVar2 * 0.001, local_3c);
  ChooseInterpolationMethods(this, local_3c,
                             (SPredictionTypeVector *)(pGVar9 + 0xb0),
                             (SPredictionTypeVector *)(this + 0x4e8));
  ComputeInterpolationParameters(
      this, pGVar9 + 0xc, pGVar9 + 0x18,
      (SPredictionTypeVector *)(pGVar9 + 0xb0), pGVar6, pGVar7, pGVar9,
      *(ulong *)(pGVar6 + 0xa8), *(ulong *)(pGVar7 + 0xa8),
      *(ulong *)(pGVar9 + 0xa8));
  GmQuat::Set(local_30, (GmMat3 *)(pGVar6 + 0x24));
  GmQuat::Set(local_20, (GmMat3 *)(pGVar7 + 0x24));
  GmQuat::Set(local_10, (GmMat3 *)(pGVar9 + 0x24));
  return;
}

/* private: void __thiscall CHmsDyna::ComputeInterpolationParameters(float
   &,float &,enum CHmsDyna::EPredictionType,float,float,float,unsigned
   long,unsigned long,unsigned long) */

void __thiscall CHmsDyna::ComputeInterpolationParameters(
    CHmsDyna *this, float *param_1, float *param_2, EPredictionType param_3,
    float param_4, float param_5, float param_6, ulong param_7, ulong param_8,
    ulong param_9)

{
  if (param_3 == 4) {
    ComputeSpeedAndAccelerationAtTime2(this, param_1, param_2, param_4, param_5,
                                       param_6, param_7, param_8, param_9);
    return;
  }
  if (param_3 == 3) {
    ComputeSpeed(this, param_1, param_5, param_6, param_8, param_9);
    *param_2 = 0.0;
    return;
  }
  *param_1 = 0.0;
  *param_2 = 0.0;
  return;
}

/* private: void __thiscall CHmsDyna::ComputeInterpolationParameters(class
   GmVec3 &,class GmVec3
   &,struct CHmsDyna::SPredictionTypeVector const &,class GmVec3 const &,class
   GmVec3 const &,class GmVec3 const &,unsigned long,unsigned long,unsigned
   long) */

void __thiscall CHmsDyna::ComputeInterpolationParameters(
    CHmsDyna *this, GmVec3 *param_1, GmVec3 *param_2,
    SPredictionTypeVector *param_3, GmVec3 *param_4, GmVec3 *param_5,
    GmVec3 *param_6, ulong param_7, ulong param_8, ulong param_9)

{
  ComputeInterpolationParameters(this, (float *)param_1, (float *)param_2,
                                 *(EPredictionType *)param_3, *(float *)param_4,
                                 *(float *)param_5, *(float *)param_6, param_7,
                                 param_8, param_9);
  ComputeInterpolationParameters(
      this, (float *)(param_1 + 4), (float *)(param_2 + 4),
      *(EPredictionType *)(param_3 + 4), *(float *)(param_4 + 4),
      *(float *)(param_5 + 4), *(float *)(param_6 + 4), param_7, param_8,
      param_9);
  ComputeInterpolationParameters(
      this, (float *)(param_1 + 8), (float *)(param_2 + 8),
      *(EPredictionType *)(param_3 + 8), *(float *)(param_4 + 8),
      *(float *)(param_5 + 8), *(float *)(param_6 + 8), param_7, param_8,
      param_9);
  return;
}

/* private: void __thiscall CHmsDyna::ComputeNextPosition(class GmVec3 const
   &,class GmVec3 const
   &,class GmVec3 const &,unsigned long,class GmVec3 &) */

void __thiscall CHmsDyna::ComputeNextPosition(CHmsDyna *this, GmVec3 *param_1,
                                              GmVec3 *param_2, GmVec3 *param_3,
                                              ulong param_4, GmVec3 *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;

  fVar6 = (float)param_4;
  if ((int)param_4 < 0) {
    fVar6 = fVar6 + 4.294967e+09;
  }
  fVar6 = fVar6 * 0.001;
  fVar1 = *(float *)(param_2 + 4);
  fVar2 = *(float *)(param_2 + 8);
  fVar7 = fVar6 * 0.5 * fVar6;
  fVar3 = *(float *)param_3;
  fVar4 = *(float *)(param_3 + 4);
  fVar5 = *(float *)(param_3 + 8);
  *(float *)param_5 = *(float *)param_1 + fVar6 * *(float *)param_2;
  *(float *)(param_5 + 4) = *(float *)(param_1 + 4) + fVar1 * fVar6;
  *(float *)(param_5 + 8) = *(float *)(param_1 + 8) + fVar2 * fVar6;
  *(float *)param_5 = *(float *)param_5 + fVar7 * fVar3;
  *(float *)(param_5 + 4) = *(float *)(param_5 + 4) + fVar4 * fVar7;
  *(float *)(param_5 + 8) = *(float *)(param_5 + 8) + fVar7 * fVar5;
  return;
}

/* private: void __thiscall CHmsDyna::ComputeNextSpeed(class GmVec3 const
   &,class GmVec3 const
   &,unsigned long,class GmVec3 &) */

void __thiscall CHmsDyna::ComputeNextSpeed(CHmsDyna *this, GmVec3 *param_1,
                                           GmVec3 *param_2, ulong param_3,
                                           GmVec3 *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;

  fVar3 = (float)param_3;
  if ((int)param_3 < 0) {
    fVar3 = fVar3 + 4.294967e+09;
  }
  fVar3 = fVar3 * 0.001;
  fVar1 = *(float *)(param_2 + 4);
  fVar2 = *(float *)(param_2 + 8);
  *(float *)param_4 = *(float *)param_1 + fVar3 * *(float *)param_2;
  *(float *)(param_4 + 4) = *(float *)(param_1 + 4) + fVar1 * fVar3;
  *(float *)(param_4 + 8) = *(float *)(param_1 + 8) + fVar3 * fVar2;
  return;
}

/* private: void __thiscall CHmsDyna::ComputeSpeed(float &,float,float,unsigned
 * long,unsigned long)
 */

void __thiscall CHmsDyna::ComputeSpeed(CHmsDyna *this, float *param_1,
                                       float param_2, float param_3,
                                       ulong param_4, ulong param_5)

{
  float fVar1;
  float fVar2;

  fVar1 = (float)param_5;
  if ((int)param_5 < 0) {
    fVar1 = fVar1 + 4.294967e+09;
  }
  fVar2 = (float)param_4;
  if ((int)param_4 < 0) {
    fVar2 = fVar2 + 4.294967e+09;
  }
  fVar1 = fVar1 * 0.001 - fVar2 * 0.001;
  if (fVar1 < 1e-05 != NAN(fVar1)) {
    *param_1 = 0.0;
    return;
  }
  *param_1 = (param_3 - param_2) / fVar1;
  return;
}

/* private: void __thiscall CHmsDyna::ComputeSpeed(class GmVec3 &,class GmVec3
   &,class GmVec3
   &,unsigned long,unsigned long) */

void __thiscall CHmsDyna::ComputeSpeed(CHmsDyna *this, GmVec3 *param_1,
                                       GmVec3 *param_2, GmVec3 *param_3,
                                       ulong param_4, ulong param_5)

{
  ComputeSpeed(this, (float *)param_1, *(float *)param_2, *(float *)param_3,
               param_4, param_5);
  ComputeSpeed(this, (float *)(param_1 + 4), *(float *)(param_2 + 4),
               *(float *)(param_3 + 4), param_4, param_5);
  ComputeSpeed(this, (float *)(param_1 + 8), *(float *)(param_2 + 8),
               *(float *)(param_3 + 8), param_4, param_5);
  return;
}

/* private: void __thiscall CHmsDyna::ComputeSpeedAndAccelerationAtTime2(float
   &,float
   &,float,float,float,unsigned long,unsigned long,unsigned long) */

void __thiscall CHmsDyna::ComputeSpeedAndAccelerationAtTime2(
    CHmsDyna *this, float *param_1, float *param_2, float param_3,
    float param_4, float param_5, ulong param_6, ulong param_7, ulong param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;

  fVar1 = (float)param_7;
  if ((int)param_7 < 0) {
    fVar1 = fVar1 + 4.294967e+09;
  }
  fVar2 = (float)param_6;
  if ((int)param_6 < 0) {
    fVar2 = fVar2 + 4.294967e+09;
  }
  fVar3 = fVar1 * 0.001 - fVar2 * 0.001;
  fVar2 = (float)param_8;
  if ((int)param_8 < 0) {
    fVar2 = fVar2 + 4.294967e+09;
  }
  fVar1 = fVar2 * 0.001 - fVar1 * 0.001;
  if ((fVar3 < 1e-05 == NAN(fVar3)) && (fVar1 < 1e-05 == NAN(fVar1))) {
    fVar2 = fVar3 / 1.0;
    fVar4 = 1.0 / fVar1;
    fVar3 = 1.0 / (fVar1 + fVar3);
    *param_1 = (fVar3 + fVar4) * param_5 +
               (fVar2 * fVar3 * param_3 * fVar1 - param_4 * (fVar4 + fVar2));
    *param_2 = fVar3 * param_5 * 2.0 * fVar4 +
               (fVar2 * fVar3 * param_3 * 2.0 - fVar4 * param_4 * 2.0 * fVar2);
    return;
  }
  *param_1 = 0.0;
  *param_2 = 0.0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall CHmsDyna::ComputeSynthetizedReplacement(class GmVec3
 * &) */

void __thiscall CHmsDyna::ComputeSynthetizedReplacement(CHmsDyna *this,
                                                        GmVec3 *param_1)

{
  CFastBuffer<> *this_00;
  float fVar1;
  float fVar2;
  float fVar3;
  ulong uVar4;
  float *pfVar5;
  ulong uVar6;
  float10 fVar7;
  float local_18;
  float local_14;
  float local_10;

  this_00 = (CFastBuffer<> *)(this + 0x330);
  uVar4 = CFastBuffer<>::GetCount(this_00);
  if (uVar4 == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)param_1 = 0;
    return;
  }
  pfVar5 = (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, 0);
  local_18 = *pfVar5;
  uVar6 = 1;
  local_14 = pfVar5[1];
  local_10 = pfVar5[2];
  if (1 < uVar4) {
    do {
      pfVar5 =
          (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar6);
      fVar1 = local_10 * pfVar5[2] + local_14 * pfVar5[1] + local_18 * *pfVar5;
      if ((0.0 < fVar1) &&
          (fVar2 =
               local_18 * local_18 + local_14 * local_14 + local_10 * local_10,
           _DAT_00cdb690 < fVar2 != (NAN(_DAT_00cdb690) || NAN(fVar2)))) {
        if (fVar2 < fVar1 != (NAN(fVar2) || NAN(fVar1))) {
          fVar1 = fVar2;
        }
        fVar1 = fVar1 / fVar2;
        local_18 = local_18 - fVar1 * local_18;
        local_14 = local_14 - fVar1 * local_14;
        local_10 = local_10 - fVar1 * local_10;
      }
      uVar6 = uVar6 + 1;
      local_18 = *pfVar5 + local_18;
      local_14 = local_14 + pfVar5[1];
      local_10 = local_10 + pfVar5[2];
    } while (uVar6 < uVar4);
  }
  fVar1 = local_18 * local_18 + local_14 * local_14 + local_10 * local_10;
  if (s_EpsilonRepl * s_EpsilonRepl < fVar1 ==
      (NAN(s_EpsilonRepl * s_EpsilonRepl) || NAN(fVar1))) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)param_1 = 0;
    return;
  }
  fVar7 = (float10)__CIsqrt();
  fVar1 = 1.0 / (float)fVar7;
  fVar2 = s_EpsilonRepl * local_14 * fVar1;
  fVar3 = s_EpsilonRepl * local_10 * fVar1;
  *(float *)param_1 = local_18 - s_EpsilonRepl * local_18 * fVar1;
  *(float *)(param_1 + 4) = local_14 - fVar2;
  *(float *)(param_1 + 8) = local_10 - fVar3;
  return;
}

/* public: void __thiscall CHmsDyna::CopyStateToTemp(void) */

void __thiscall CHmsDyna::CopyStateToTemp(CHmsDyna *this)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;

  puVar2 = *(undefined4 **)(this + 0x32c);
  puVar3 = (undefined4 *)(this + 0x274);
  for (iVar1 = 0x2d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}

/* public: void __thiscall CHmsDyna::CopyTempToState(void) */

void __thiscall CHmsDyna::CopyTempToState(CHmsDyna *this)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;

  puVar2 = (undefined4 *)(this + 0x274);
  puVar3 = *(undefined4 **)(this + 0x328);
  for (iVar1 = 0x2d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}

/* public: void __thiscall CHmsDyna::DoPHBInterpolation(unsigned long,struct
   CHmsDyna::CHmsStateDyna
   &) */

void __thiscall CHmsDyna::DoPHBInterpolation(CHmsDyna *this, ulong param_1,
                                             CHmsStateDyna *param_2)

{
  CMwCmdBufferCore *this_00;
  uint *puVar1;
  SHistoryPoint *pSVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;

  *(undefined4 *)(this + 4) = 1;
  this_00 = *(CMwCmdBufferCore **)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x14);
  if (this_00 == (CMwCmdBufferCore *)0x0) {
    this_00 = CMwCmdBufferCore::TheCoreCmdBuffer + 0xa0;
  }
  puVar1 = (uint *)CPlugAudio::MwGetId((CPlugAudio *)this_00);
  uVar7 = *puVar1;
  UpdateHistory(this, uVar7);
  if ((param_1 <= s_MaxFutureUpdateAllowed + uVar7) &&
      (pSVar2 = AddHistoryPoint(this, (GmVec3 *)(param_2 + 0x34),
                                (GmMat3 *)(param_2 + 0x10), param_1),
       pSVar2 != (SHistoryPoint *)0x0)) {
    uVar3 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x344));
    iVar4 = TestIfRespawn(this);
    *(int *)(pSVar2 + 0xac) = iVar4;
    if (s_PredictionDelayPHBInterpolation < uVar7) {
      uVar7 = uVar7 - s_PredictionDelayPHBInterpolation;
    } else {
      uVar7 = 0;
    }
    if ((iVar4 == 0) && (1 < uVar3)) {
      uVar5 = GetTimeLastHistoryPointMinusOne(this);
      if ((param_1 - uVar5 < 1000) && (uVar7 < param_1 + 1000)) {
        if ((uVar3 < 3) || (pSVar2 = GetLastHistoryPointMinusOne(this),
                            *(int *)(pSVar2 + 0xb0) == 2)) {
          SetAllInterpolationLinear(this);
        } else {
          ComputeInterpolationMethods(this);
        }
        iVar4 = *(int *)(this + 0x524);
        if (iVar4 == 0) {
          if (*(int *)(this + 0x518) != 0) {
            *(int *)(this + 0x518) = *(int *)(this + 0x518) + -1;
          }
        } else {
          iVar6 = IsTwoLastHistoryPointsDifferent(this);
          if ((iVar6 != 0) &&
              (*(int *)(this + 0x518) = *(int *)(this + 0x518) + 1,
               0x32 < *(uint *)(this + 0x518))) {
            *(undefined4 *)(this + 0x518) = 0x32;
          }
        }
        if (*(int *)(this + 0x520) == 0) {
          return;
        }
        if (iVar4 != 0) {
          return;
        }
        *(undefined4 *)(this + 0x528) = 1;
        ComputeInterpolationConvergencePoint(this);
        return;
      }
      iVar4 = IsTwoLastHistoryPointsDifferent(this);
      if ((iVar4 != 0) && (*(int *)(this + 0x518) = *(int *)(this + 0x518) + 1,
                           0x32 < *(uint *)(this + 0x518))) {
        *(undefined4 *)(this + 0x518) = 0x32;
      }
    }
    SetAllInterpolationConstant(this);
  }
  return;
}

/* public: void __thiscall CHmsDyna::DoPostCollisionDynamic(void) */

void __thiscall CHmsDyna::DoPostCollisionDynamic(CHmsDyna *this)

{
  GmVec3 local_c[12];

  ComputeSynthetizedReplacement(this, local_c);
  ApplyReplacement(this, local_c);
  return;
}

/* public: void __thiscall CHmsDyna::DoPreCollisionDynamic(float) */

void __thiscall CHmsDyna::DoPreCollisionDynamic(CHmsDyna *this, float param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_c0[47];

  puVar1 = *(undefined4 **)(this + 0x32c);
  puVar3 = puVar1;
  puVar4 = local_c0;
  for (iVar2 = 0x2d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  IntegrateStep(this, (CHmsStateDyna *)local_c0, (CHmsStateDyna *)puVar1,
                param_1);
  CFastBuffer<>::Reset((CFastBuffer<> *)(this + 0x330));
  return;
}

/* public: void __thiscall CHmsDyna::GetAngularSpeed(class GmVec3 &)const  */

void __thiscall CHmsDyna::GetAngularSpeed(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;

  iVar1 = *(int *)(this + 0x32c);
  *(undefined4 *)param_1 = *(undefined4 *)(iVar1 + 0x58);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar1 + 0x5c);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0x60);
  return;
}

/* public: void __thiscall CHmsDyna::GetForce(class GmVec3 &)const  */

void __thiscall CHmsDyna::GetForce(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;

  iVar1 = *(int *)(this + 0x32c);
  *(undefined4 *)param_1 = *(undefined4 *)(iVar1 + 100);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar1 + 0x68);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0x6c);
  return;
}

/* private: struct CHmsDyna::SHistoryPoint & __thiscall
 * CHmsDyna::GetLastHistoryPointMinusOne(void)
 */

SHistoryPoint *__thiscall CHmsDyna::GetLastHistoryPointMinusOne(CHmsDyna *this)

{
  uint uVar1;

  uVar1 = *(int *)(this + 0x350) + 1;
  if (*(uint *)(this + 0x34c) <= uVar1) {
    uVar1 = uVar1 - *(uint *)(this + 0x34c);
  }
  return (SHistoryPoint *)(uVar1 * 0xe0 + *(int *)(this + 0x348));
}

/* private: struct CHmsDyna::SHistoryPoint & __thiscall
 * CHmsDyna::GetLastHistoryPointMinusTwo(void)
 */

SHistoryPoint *__thiscall CHmsDyna::GetLastHistoryPointMinusTwo(CHmsDyna *this)

{
  uint uVar1;

  uVar1 = *(int *)(this + 0x350) + 2;
  if (*(uint *)(this + 0x34c) <= uVar1) {
    uVar1 = uVar1 - *(uint *)(this + 0x34c);
  }
  return (SHistoryPoint *)(uVar1 * 0xe0 + *(int *)(this + 0x348));
}

/* public: void __thiscall CHmsDyna::GetLinearSpeed(class GmVec3 &)const  */

void __thiscall CHmsDyna::GetLinearSpeed(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;

  iVar1 = *(int *)(this + 0x32c);
  *(undefined4 *)param_1 = *(undefined4 *)(iVar1 + 0x40);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar1 + 0x44);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0x48);
  return;
}

/* public: void __thiscall CHmsDyna::GetLocalAngularSpeed(class GmVec3 &)const
 */

void __thiscall CHmsDyna::GetLocalAngularSpeed(CHmsDyna *this, GmVec3 *param_1)

{
  int extraout_EDX;

  GetAngularSpeed(this, param_1);
  GmVec3::MultTranspose(param_1, (GmMat3 *)(extraout_EDX + 0x10));
  return;
}

/* public: void __thiscall CHmsDyna::GetLocalForce(class GmVec3 &)const  */

void __thiscall CHmsDyna::GetLocalForce(CHmsDyna *this, GmVec3 *param_1)

{
  int extraout_EDX;

  GetForce(this, param_1);
  GmVec3::MultTranspose(param_1, (GmMat3 *)(extraout_EDX + 0x10));
  return;
}

/* public: void __thiscall CHmsDyna::GetLocalLinearSpeed(class GmVec3 &)const */

void __thiscall CHmsDyna::GetLocalLinearSpeed(CHmsDyna *this, GmVec3 *param_1)

{
  int extraout_EDX;

  GetLinearSpeed(this, param_1);
  GmVec3::MultTranspose(param_1, (GmMat3 *)(extraout_EDX + 0x10));
  return;
}

/* public: void __thiscall CHmsDyna::GetSpeed(class GmVec3 const &,class GmVec3
 * &)const  */

void __thiscall CHmsDyna::GetSpeed(CHmsDyna *this, GmVec3 *param_1,
                                   GmVec3 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  float local_c;
  float local_8;
  float local_4;

  iVar8 = *(int *)(this + 0x32c);
  if (*(int *)(this + 0x340) == 2) {
    *(undefined4 *)(param_2 + 8) = 0;
    *(undefined4 *)(param_2 + 4) = 0;
    *(undefined4 *)param_2 = 0;
    return;
  }
  *(undefined4 *)param_2 = *(undefined4 *)(iVar8 + 0x40);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(iVar8 + 0x44);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar8 + 0x48);
  if (*(int *)(this + 0x340) == 1) {
    GmVec3::SetMult((GmVec3 *)&local_c,
                    (GmVec3 *)(*(int *)(this + 0x108) + 0x38),
                    (GmIso4 *)(iVar8 + 0x10));
    fVar1 = *(float *)param_1;
    fVar2 = *(float *)(param_1 + 4);
    fVar3 = *(float *)(param_1 + 8);
    fVar4 = *(float *)(iVar8 + 0x60);
    fVar5 = *(float *)(iVar8 + 0x58);
    fVar6 = *(float *)(iVar8 + 0x58);
    fVar7 = *(float *)(iVar8 + 0x5c);
    *(float *)param_2 =
        *(float *)param_2 + ((fVar3 - local_4) * *(float *)(iVar8 + 0x5c) -
                             (fVar2 - local_8) * *(float *)(iVar8 + 0x60));
    *(float *)(param_2 + 4) =
        *(float *)(param_2 + 4) +
        ((fVar1 - local_c) * fVar4 - fVar5 * (fVar3 - local_4));
    *(float *)(param_2 + 8) =
        *(float *)(param_2 + 8) +
        ((fVar2 - local_8) * fVar6 - fVar7 * (fVar1 - local_c));
  }
  return;
}

/* private: unsigned long __thiscall
 * CHmsDyna::GetTimeLastHistoryPointMinusOne(void)const  */

ulong __thiscall CHmsDyna::GetTimeLastHistoryPointMinusOne(CHmsDyna *this)

{
  uint uVar1;

  uVar1 = *(int *)(this + 0x350) + 1;
  if (*(uint *)(this + 0x34c) <= uVar1) {
    uVar1 = uVar1 - *(uint *)(this + 0x34c);
  }
  return *(ulong *)(uVar1 * 0xe0 + 0xa8 + *(int *)(this + 0x348));
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall CHmsDyna::IntegrateStep(struct
   CHmsDyna::CHmsStateDyna const &,struct CHmsDyna::CHmsStateDyna &,float)const
 */

void __thiscall CHmsDyna::IntegrateStep(CHmsDyna *this, CHmsStateDyna *param_1,
                                        CHmsStateDyna *param_2, float param_3)

{
  GmMat3 *this_00;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float10 fVar8;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  if (*(int *)(this + 0x340) == 2) {
    for (iVar7 = 0x2d; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined4 *)param_2 = *(undefined4 *)param_1;
      param_1 = (CHmsStateDyna *)((int)param_1 + 4);
      param_2 = (CHmsStateDyna *)((int)param_2 + 4);
    }
    return;
  }
  fVar6 = 1.0 / **(float **)(this + 0x108);
  fVar1 = *(float *)(param_1 + 100);
  fVar2 = *(float *)(param_1 + 0x68);
  fVar3 = *(float *)(param_1 + 0x6c);
  fVar4 = *(float *)(param_1 + 0x44);
  fVar5 = *(float *)(param_1 + 0x48);
  *(float *)(param_2 + 0x34) =
      param_3 * *(float *)(param_1 + 0x40) + *(float *)(param_1 + 0x34);
  *(float *)(param_2 + 0x38) = *(float *)(param_1 + 0x38) + fVar4 * param_3;
  *(float *)(param_2 + 0x3c) = *(float *)(param_1 + 0x3c) + fVar5 * param_3;
  fVar4 = *(float *)(param_1 + 0x50);
  fVar5 = *(float *)(param_1 + 0x54);
  *(float *)(param_2 + 0x34) =
      *(float *)(param_2 + 0x34) + *(float *)(param_1 + 0x4c) * param_3;
  *(float *)(param_2 + 0x38) = *(float *)(param_2 + 0x38) + fVar4 * param_3;
  *(float *)(param_2 + 0x3c) = *(float *)(param_2 + 0x3c) + fVar5 * param_3;
  *(undefined4 *)(param_2 + 0x54) = 0;
  *(undefined4 *)(param_2 + 0x50) = 0;
  *(undefined4 *)(param_2 + 0x4c) = 0;
  *(float *)(param_2 + 0x40) =
      *(float *)(param_1 + 0x40) + fVar6 * fVar1 * param_3;
  *(float *)(param_2 + 0x44) =
      *(float *)(param_1 + 0x44) + fVar2 * fVar6 * param_3;
  *(float *)(param_2 + 0x48) =
      *(float *)(param_1 + 0x48) + param_3 * fVar6 * fVar3;
  if (*(int *)(this + 0x340) != 0) {
    GmVec3::SetMult((GmVec3 *)&local_c, (GmVec3 *)(param_1 + 0x70),
                    (GmMat3 *)(param_1 + 0x7c));
    fVar1 = *(float *)(param_1 + 0x60) * *(float *)(param_1 + 0x60) +
            *(float *)(param_1 + 0x58) * *(float *)(param_1 + 0x58) +
            *(float *)(param_1 + 0x5c) * *(float *)(param_1 + 0x5c);
    if (_DAT_00cdb690 < fVar1 == (NAN(_DAT_00cdb690) || NAN(fVar1))) {
      GmMat3::Set((GmMat3 *)(param_2 + 0x10), (GmMat3 *)(param_1 + 0x10));
      GmVec4::Set((GmVec4 *)param_2, (GmVec4 *)param_1);
    } else {
      local_1c = ((-*(float *)(param_1 + 0x58) * *(float *)(param_1 + 4) -
                   *(float *)(param_1 + 0x5c) * *(float *)(param_1 + 8)) -
                  *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x60)) *
                 0.5;
      local_18 = ((*(float *)(param_1 + 0x5c) * *(float *)(param_1 + 0xc) +
                   *(float *)param_1 * *(float *)(param_1 + 0x58)) -
                  *(float *)(param_1 + 8) * *(float *)(param_1 + 0x60)) *
                 0.5;
      local_14 = (*(float *)(param_1 + 0x60) * *(float *)(param_1 + 4) +
                  (*(float *)(param_1 + 0x5c) * *(float *)param_1 -
                   *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x58))) *
                 0.5;
      local_10 = (*(float *)param_1 * *(float *)(param_1 + 0x60) +
                  (*(float *)(param_1 + 8) * *(float *)(param_1 + 0x58) -
                   *(float *)(param_1 + 0x5c) * *(float *)(param_1 + 4))) *
                 0.5;
      GmVec4::Set((GmVec4 *)param_2, (GmVec4 *)param_1);
      *(float *)param_2 = *(float *)param_2 + param_3 * local_1c;
      *(float *)(param_2 + 4) = local_18 * param_3 + *(float *)(param_2 + 4);
      *(float *)(param_2 + 8) = local_14 * param_3 + *(float *)(param_2 + 8);
      *(float *)(param_2 + 0xc) =
          param_3 * local_10 + *(float *)(param_2 + 0xc);
      GmQuat::Normalize((GmQuat *)param_2);
      GmMat3::Set((GmMat3 *)(param_2 + 0x10), *(float *)param_2,
                  *(float *)(param_2 + 4), *(float *)(param_2 + 8),
                  *(float *)(param_2 + 0xc));
      iVar7 = *(int *)(this + 0x108);
      GmVec3::SetMult((GmVec3 *)&local_1c, (GmVec3 *)(iVar7 + 0x38),
                      (GmMat3 *)(param_1 + 0x10));
      GmVec3::SetMult((GmVec3 *)&local_28, (GmVec3 *)(iVar7 + 0x38),
                      (GmMat3 *)(param_2 + 0x10));
      *(float *)(param_2 + 0x34) =
          *(float *)(param_2 + 0x34) - (local_28 - local_1c);
      *(float *)(param_2 + 0x38) =
          *(float *)(param_2 + 0x38) - (local_24 - local_18);
      *(float *)(param_2 + 0x3c) =
          *(float *)(param_2 + 0x3c) - (local_20 - local_14);
    }
    *(float *)(param_2 + 0x58) = *(float *)(param_1 + 0x58) + param_3 * local_c;
    *(float *)(param_2 + 0x5c) = *(float *)(param_1 + 0x5c) + local_8 * param_3;
    *(float *)(param_2 + 0x60) = *(float *)(param_1 + 0x60) + param_3 * local_4;
    if ((*(int *)(this + 0xc0) != 0) &&
        (fVar1 = *(float *)(this + 0xc4),
         fVar1 * fVar1 <
             *(float *)(param_2 + 0x60) * *(float *)(param_2 + 0x60) +
                 *(float *)(param_2 + 0x58) * *(float *)(param_2 + 0x58) +
                 *(float *)(param_2 + 0x5c) * *(float *)(param_2 + 0x5c))) {
      fVar8 = (float10)__CIsqrt();
      fVar1 = fVar1 / (float)fVar8;
      *(float *)(param_2 + 0x58) = fVar1 * *(float *)(param_2 + 0x58);
      *(float *)(param_2 + 0x5c) = fVar1 * *(float *)(param_2 + 0x5c);
      *(float *)(param_2 + 0x60) = fVar1 * *(float *)(param_2 + 0x60);
    }
    this_00 = (GmMat3 *)(param_2 + 0x7c);
    GmMat3::SetTranspose(this_00, (GmMat3 *)(param_2 + 0x10));
    GmMat3::Mult(this_00, (GmMat3 *)(*(int *)(this + 0x108) + 4));
    GmMat3::Mult(this_00, (GmMat3 *)(param_2 + 0x10));
    return;
  }
  GmMat3::Set((GmMat3 *)(param_2 + 0x10), (GmMat3 *)(param_1 + 0x10));
  return;
}

/* private: void __thiscall CHmsDyna::Interpolate(float,float,enum
   CHmsDyna::EPredictionType
   &,float,float,float,float,float &,float &) */

void __thiscall CHmsDyna::Interpolate(CHmsDyna *this, float param_1,
                                      float param_2, EPredictionType *param_3,
                                      float param_4, float param_5,
                                      float param_6, float param_7,
                                      float *param_8, float *param_9)

{
  float fVar1;
  float fVar2;
  float fVar3;

  if (*param_3 != 4) {
    if (*param_3 != 3) {
      return;
    }
    *param_8 = param_4 + param_1 * (param_5 - param_4);
    *param_9 = param_7;
    return;
  }
  fVar3 = param_1 * param_1;
  fVar1 = fVar3 * param_1;
  fVar2 = fVar3 * 3.0;
  fVar1 = (fVar1 - fVar3) * param_7 * param_2 +
          param_4 * (((fVar1 + fVar1) - fVar2) + 1.0) +
          param_5 * (fVar2 - (fVar1 + fVar1)) +
          param_2 * param_6 * (param_1 + (fVar1 - (fVar3 + fVar3)));
  *param_8 = fVar1;
  if (param_5 <= param_4) {
    if (fVar1 <= param_4) {
      if (fVar1 < param_5 != (NAN(fVar1) || NAN(param_5)))
        goto LAB_00533114;
    } else {
      *param_8 = param_4;
    }
  } else if (fVar1 < param_4 == (NAN(fVar1) || NAN(param_4))) {
    if (param_5 < fVar1) {
    LAB_00533114:
      *param_8 = param_5;
    }
  } else {
    *param_8 = param_4;
  }
  fVar1 = ((fVar2 - param_1 * 4.0) + 1.0) * param_6 +
          (1.0 / param_2) * (param_1 * 6.0 - fVar3 * 6.0) * param_5 +
          (1.0 / param_2) * (fVar3 * 6.0 - param_1 * 6.0) * param_4 +
          param_7 * (fVar2 - (param_1 + param_1));
  *param_9 = fVar1;
  if (param_6 < param_7 == (NAN(param_6) || NAN(param_7))) {
    if (param_6 < fVar1 != (NAN(param_6) || NAN(fVar1)))
      goto LAB_005331bf;
    if (fVar1 < param_7 != (NAN(fVar1) || NAN(param_7))) {
      *param_9 = param_7;
      return;
    }
  } else {
    if (fVar1 < param_6) {
    LAB_005331bf:
      *param_9 = param_6;
      return;
    }
    if (param_7 < fVar1) {
      *param_9 = param_7;
      return;
    }
  }
  return;
}

/* private: void __thiscall CHmsDyna::Interpolate(float,float,struct
   CHmsDyna::SPredictionTypeVector
   &,class GmVec3 &,class GmVec3 &,class GmVec3 &,class GmVec3 &,class GmVec3
   &,class GmVec3 &) */

void __thiscall CHmsDyna::Interpolate(CHmsDyna *this, float param_1,
                                      float param_2,
                                      SPredictionTypeVector *param_3,
                                      GmVec3 *param_4, GmVec3 *param_5,
                                      GmVec3 *param_6, GmVec3 *param_7,
                                      GmVec3 *param_8, GmVec3 *param_9)

{
  Interpolate(this, param_1, param_2, (EPredictionType *)param_3,
              *(float *)param_4, *(float *)param_5, *(float *)param_6,
              *(float *)param_7, (float *)param_8, (float *)param_9);
  Interpolate(this, param_1, param_2, (EPredictionType *)(param_3 + 4),
              *(float *)(param_4 + 4), *(float *)(param_5 + 4),
              *(float *)(param_6 + 4), *(float *)(param_7 + 4),
              (float *)(param_8 + 4), (float *)(param_9 + 4));
  Interpolate(this, param_1, param_2, (EPredictionType *)(param_3 + 8),
              *(float *)(param_4 + 8), *(float *)(param_5 + 8),
              *(float *)(param_6 + 8), *(float *)(param_7 + 8),
              (float *)(param_8 + 8), (float *)(param_9 + 8));
  return;
}

/* private: void __thiscall CHmsDyna::Interpolate(class GmVec3 &,class GmMat3
   &,class GmVec3 &,class GmMat3 &,unsigned long,struct CHmsDyna::SHistoryPoint
   &,struct CHmsDyna::SHistoryPoint &) */

void __thiscall CHmsDyna::Interpolate(CHmsDyna *this, GmVec3 *param_1,
                                      GmMat3 *param_2, GmVec3 *param_3,
                                      GmMat3 *param_4, ulong param_5,
                                      SHistoryPoint *param_6,
                                      SHistoryPoint *param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  ulong uVar4;

  fVar1 = (float)*(int *)(param_6 + 0xa8);
  if (*(int *)(param_6 + 0xa8) < 0) {
    fVar1 = fVar1 + 4.294967e+09;
  }
  fVar2 = (float)*(int *)(param_7 + 0xa8);
  if (*(int *)(param_7 + 0xa8) < 0) {
    fVar2 = fVar2 + 4.294967e+09;
  }
  fVar3 = fVar2 * 0.001 - fVar1 * 0.001;
  fVar2 = (float)param_5;
  if ((int)param_5 < 0) {
    fVar2 = fVar2 + 4.294967e+09;
  }
  fVar1 = (fVar2 * 0.001 - fVar1 * 0.001) / fVar3;
  Interpolate(this, fVar1, fVar3, (SPredictionTypeVector *)(param_7 + 0xb0),
              (GmVec3 *)param_6, (GmVec3 *)param_7, (GmVec3 *)(param_6 + 0xc),
              (GmVec3 *)(param_7 + 0xc), param_1, param_3);
  GmMat3::SetBlend(param_2, (GmMat3 *)(param_6 + 0x24),
                   (GmMat3 *)(param_7 + 0x24), fVar1);
  uVar4 = GmMat3::IsOrthonormal(param_2);
  if (uVar4 == 0) {
    GmMat3::OrthoNormalize(param_2);
  }
  return;
}

/* public: int __thiscall CHmsDyna::IsStateDifferentFrom(class GmIso4 &) */

int __thiscall CHmsDyna::IsStateDifferentFrom(CHmsDyna *this, GmIso4 *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;

  iVar1 = *(int *)(this + 0x328);
  fVar2 = *(float *)(param_1 + 0x24) - *(float *)(iVar1 + 0x34);
  fVar3 = *(float *)(param_1 + 0x28) - *(float *)(iVar1 + 0x38);
  fVar4 = *(float *)(param_1 + 0x2c) - *(float *)(iVar1 + 0x3c);
  fVar2 = fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3;
  if ((((1e-05 < fVar2 == NAN(fVar2)) &&
        (fVar2 = *(float *)param_1 - *(float *)(iVar1 + 0x10),
         fVar3 = *(float *)(param_1 + 4) - *(float *)(iVar1 + 0x14),
         fVar4 = *(float *)(param_1 + 8) - *(float *)(iVar1 + 0x18),
         fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3 <= 1e-05)) &&
       (fVar2 = *(float *)(param_1 + 0xc) - *(float *)(iVar1 + 0x1c),
        fVar3 = *(float *)(param_1 + 0x10) - *(float *)(iVar1 + 0x20),
        fVar4 = *(float *)(param_1 + 0x14) - *(float *)(iVar1 + 0x24),
        fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3 <= 1e-05)) &&
      (fVar2 = *(float *)(param_1 + 0x18) - *(float *)(iVar1 + 0x28),
       fVar3 = *(float *)(param_1 + 0x1c) - *(float *)(iVar1 + 0x2c),
       fVar4 = *(float *)(param_1 + 0x20) - *(float *)(iVar1 + 0x30),
       fVar2 = fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3,
       1e-05 < fVar2 == NAN(fVar2))) {
    return 0;
  }
  return 1;
}

/* public: int __thiscall CHmsDyna::IsTwoLastHistoryPointsDifferent(void) */

int __thiscall CHmsDyna::IsTwoLastHistoryPointsDifferent(CHmsDyna *this)

{
  float fVar1;
  uint uVar2;
  float *pfVar3;
  float *pfVar4;

  uVar2 = *(uint *)(this + 0x350);
  if (*(uint *)(this + 0x34c) <= uVar2) {
    uVar2 = uVar2 - *(uint *)(this + 0x34c);
  }
  pfVar3 = (float *)(uVar2 * 0xe0 + *(int *)(this + 0x348));
  uVar2 = *(int *)(this + 0x350) + 1;
  if (*(uint *)(this + 0x34c) <= uVar2) {
    uVar2 = uVar2 - *(uint *)(this + 0x34c);
  }
  pfVar4 = (float *)(uVar2 * 0xe0 + *(int *)(this + 0x348));
  fVar1 = (pfVar3[2] - pfVar4[2]) * (pfVar3[2] - pfVar4[2]) +
          (pfVar3[1] - pfVar4[1]) * (pfVar3[1] - pfVar4[1]) +
          (*pfVar3 - *pfVar4) * (*pfVar3 - *pfVar4);
  if ((((1e-05 < fVar1 == NAN(fVar1)) &&
        ((pfVar3[0xb] - pfVar4[0xb]) * (pfVar3[0xb] - pfVar4[0xb]) +
             (pfVar3[10] - pfVar4[10]) * (pfVar3[10] - pfVar4[10]) +
             (pfVar3[9] - pfVar4[9]) * (pfVar3[9] - pfVar4[9]) <=
         1e-05)) &&
       ((pfVar3[0xe] - pfVar4[0xe]) * (pfVar3[0xe] - pfVar4[0xe]) +
            (pfVar3[0xd] - pfVar4[0xd]) * (pfVar3[0xd] - pfVar4[0xd]) +
            (pfVar3[0xc] - pfVar4[0xc]) * (pfVar3[0xc] - pfVar4[0xc]) <=
        1e-05)) &&
      (fVar1 = (pfVar3[0x11] - pfVar4[0x11]) * (pfVar3[0x11] - pfVar4[0x11]) +
               (pfVar3[0x10] - pfVar4[0x10]) * (pfVar3[0x10] - pfVar4[0x10]) +
               (pfVar3[0xf] - pfVar4[0xf]) * (pfVar3[0xf] - pfVar4[0xf]),
       1e-05 < fVar1 == NAN(fVar1))) {
    return 0;
  }
  return 1;
}

/* public: void __thiscall CHmsDyna::OldRestoreStaticState(class
   CClassicBufferMemory &,int,unsigned char) */

void __thiscall CHmsDyna::OldRestoreStaticState(CHmsDyna *this,
                                                CClassicBufferMemory *param_1,
                                                int param_2, uchar param_3)

{
  if (param_2 != 0) {
    CHmsStateDyna::OldRestoreState(*(CHmsStateDyna **)(this + 0x328), param_1,
                                   param_3);
    return;
  }
  CHmsStateDyna::OldRestoreState(*(CHmsStateDyna **)(this + 0x32c), param_1,
                                 param_3);
  return;
}

/* public: void __thiscall CHmsDyna::PredictPointForInterpolation(class GmVec3
   &,class GmMat3
   &,unsigned long) */

void __thiscall CHmsDyna::PredictPointForInterpolation(CHmsDyna *this,
                                                       GmVec3 *param_1,
                                                       GmMat3 *param_2,
                                                       ulong param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  ulong uVar4;
  uint uVar5;
  SHistoryPoint *pSVar6;
  ulong uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  bool bVar13;
  uint local_38;
  GmVec3 local_30[12];
  GmMat3 local_24[36];

  uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x344));
  puVar11 = (undefined4 *)0x0;
  if (uVar4 == 0) {
    return;
  }
  local_38 = param_3;
  if (uVar4 == 1) {
    uVar5 = *(uint *)(this + 0x350);
    if (*(uint *)(this + 0x34c) <= uVar5) {
      uVar5 = uVar5 - *(uint *)(this + 0x34c);
    }
    puVar11 = (undefined4 *)(uVar5 * 0xe0 + *(int *)(this + 0x348));
    *(undefined4 *)param_1 = *puVar11;
    *(undefined4 *)(param_1 + 4) = puVar11[1];
    *(undefined4 *)(param_1 + 8) = puVar11[2];
    uVar5 = *(uint *)(this + 0x350);
    if (*(uint *)(this + 0x34c) <= uVar5) {
      uVar5 = uVar5 - *(uint *)(this + 0x34c);
    }
    puVar11 = (undefined4 *)(uVar5 * 0xe0 + 0x24 + *(int *)(this + 0x348));
    puVar10 = (undefined4 *)param_2;
    for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar10 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar10 = puVar10 + 1;
    }
    uVar5 = *(uint *)(this + 0x350);
    if (*(uint *)(this + 0x34c) <= uVar5) {
      uVar5 = uVar5 - *(uint *)(this + 0x34c);
    }
    uVar9 = *(uint *)(this + 0x350);
    if (*(uint *)(this + 0x34c) <= uVar9) {
      uVar9 = uVar9 - *(uint *)(this + 0x34c);
    }
    puVar11 = (undefined4 *)(uVar5 * 0xe0 + 0x48 + *(int *)(this + 0x348));
    puVar10 = (undefined4 *)(uVar9 * 0xe0 + 0xc + *(int *)(this + 0x348));
  } else {
    if ((*(int *)(this + 0x528) == 0) || (*(uint *)(this + 0x4e0) <= param_3)) {
      *(undefined4 *)(this + 0x528) = 0;
      uVar5 = *(int *)(this + 0x350) + -1 + uVar4;
      if (*(uint *)(this + 0x34c) <= uVar5) {
        uVar5 = uVar5 - *(uint *)(this + 0x34c);
      }
      if (param_3 < *(uint *)(uVar5 * 0xe0 + 0xa8 + *(int *)(this + 0x348))) {
        uVar5 = *(int *)(this + 0x350) + -1 + uVar4;
        if (*(uint *)(this + 0x34c) <= uVar5) {
          uVar5 = uVar5 - *(uint *)(this + 0x34c);
        }
        puVar11 = (undefined4 *)(uVar5 * 0xe0 + *(int *)(this + 0x348));
        *(undefined4 *)param_1 = *puVar11;
        *(undefined4 *)(param_1 + 4) = puVar11[1];
        *(undefined4 *)(param_1 + 8) = puVar11[2];
        uVar5 = *(int *)(this + 0x350) + -1 + uVar4;
        if (*(uint *)(this + 0x34c) <= uVar5) {
          uVar5 = uVar5 - *(uint *)(this + 0x34c);
        }
        puVar11 = (undefined4 *)(uVar5 * 0xe0 + 0x24 + *(int *)(this + 0x348));
        puVar10 = (undefined4 *)param_2;
        for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar10 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar10 = puVar10 + 1;
        }
        uVar5 = *(int *)(this + 0x350) + -1 + uVar4;
        if (*(uint *)(this + 0x34c) <= uVar5) {
          uVar5 = uVar5 - *(uint *)(this + 0x34c);
        }
        uVar9 = *(int *)(this + 0x350) + -1 + uVar4;
        if (*(uint *)(this + 0x34c) <= uVar9) {
          uVar9 = uVar9 - *(uint *)(this + 0x34c);
        }
        puVar11 = (undefined4 *)(uVar5 * 0xe0 + 0x48 + *(int *)(this + 0x348));
        puVar10 = (undefined4 *)(uVar9 * 0xe0 + 0xc + *(int *)(this + 0x348));
        goto LAB_005368db;
      }
      iVar8 = uVar4 - 1;
      bVar13 = iVar8 == 0;
      if (!bVar13) {
        do {
          uVar5 = *(int *)(this + 0x350) + -1 + iVar8;
          if (*(uint *)(this + 0x34c) <= uVar5) {
            uVar5 = uVar5 - *(uint *)(this + 0x34c);
          }
        } while ((*(uint *)(uVar5 * 0xe0 + 0xa8 + *(int *)(this + 0x348)) <=
                  param_3) &&
                 (iVar8 = iVar8 + -1, iVar8 != 0));
        bVar13 = iVar8 == 0;
      }
      uVar5 = *(uint *)(this + 0x350);
      uVar9 = *(uint *)(this + 0x34c);
      if (bVar13) {
        if (uVar9 <= uVar5) {
          uVar5 = uVar5 - uVar9;
        }
        iVar8 = *(int *)(uVar5 * 0xe0 + 0xa8 + *(int *)(this + 0x348));
        uVar5 = iVar8 + 500;
        if (uVar5 < param_3) {
          *(undefined4 *)(this + 0x524) = 1;
          local_38 = uVar5;
        } else {
          *(undefined4 *)(this + 0x524) = 0;
        }
        uVar5 = *(uint *)(this + 0x350);
        if (*(uint *)(this + 0x34c) <= uVar5) {
          uVar5 = uVar5 - *(uint *)(this + 0x34c);
        }
        puVar10 = (undefined4 *)(uVar5 * 0xe0 + *(int *)(this + 0x348));
        *(undefined4 *)(this + 0x520) = 1;
        if (*(int *)(this + 0x51c) == 0) {
          *(int *)(this + 0x51c) = iVar8;
        }
      } else {
        uVar5 = uVar5 + iVar8;
        if (uVar9 <= uVar5) {
          uVar5 = uVar5 - uVar9;
        }
        puVar10 = (undefined4 *)(uVar5 * 0xe0 + *(int *)(this + 0x348));
        uVar5 = *(int *)(this + 0x350) + -1 + iVar8;
        if (uVar9 <= uVar5) {
          uVar5 = uVar5 - uVar9;
        }
        puVar11 = (undefined4 *)(uVar5 * 0xe0 + *(int *)(this + 0x348));
        *(undefined4 *)(this + 0x520) = 0;
        *(undefined4 *)(this + 0x524) = 0;
        *(undefined4 *)(this + 0x51c) = 0;
        if (puVar11[0x2c] == 2) {
          *(undefined4 *)param_1 = *puVar11;
          *(undefined4 *)(param_1 + 4) = puVar11[1];
          *(undefined4 *)(param_1 + 8) = puVar11[2];
          puVar10 = puVar11 + 9;
          puVar12 = (undefined4 *)param_2;
          for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          SetLastPrediction(this, param_1, param_2, (GmVec3 *)(puVar11 + 3),
                            (GmMat3 *)(puVar11 + 0x12), param_3);
          return;
        }
      }
    } else {
      puVar10 = (undefined4 *)(this + 0x358);
      puVar11 = (undefined4 *)(this + 0x438);
    }
    if ((uint)puVar10[0x2a] <= local_38) {
      if (puVar11 == (undefined4 *)0x0) {
        if (100 < *(uint *)(this + 0x518)) {
          *(undefined4 *)param_1 = *puVar10;
          *(undefined4 *)(param_1 + 4) = puVar10[1];
          *(undefined4 *)(param_1 + 8) = puVar10[2];
          puVar11 = puVar10 + 9;
          puVar12 = (undefined4 *)param_2;
          for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
          SetLastPrediction(this, param_1, param_2, (GmVec3 *)(puVar10 + 3),
                            (GmMat3 *)(puVar10 + 0x12), local_38);
          *(undefined4 *)(this + 0x528) = 0;
          *(undefined4 *)(this + 0x520) = 0;
          return;
        }
        if (puVar10[0x2c] == 2) {
          *(undefined4 *)param_1 = *puVar10;
          *(undefined4 *)(param_1 + 4) = puVar10[1];
          *(undefined4 *)(param_1 + 8) = puVar10[2];
          puVar11 = puVar10 + 9;
          puVar12 = (undefined4 *)param_2;
          for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
          SetLastPrediction(this, param_1, param_2, (GmVec3 *)(puVar10 + 3),
                            (GmMat3 *)(puVar10 + 0x12), local_38);
          return;
        }
        uVar4 = local_38 - puVar10[0x2a];
        ComputeNextPosition(this, (GmVec3 *)puVar10, (GmVec3 *)(puVar10 + 3),
                            (GmVec3 *)(puVar10 + 6), uVar4, param_1);
        pSVar6 = GetLastHistoryPointMinusOne(this);
        fVar1 = (float)uVar4;
        if ((int)uVar4 < 0) {
          fVar1 = fVar1 + 4.294967e+09;
        }
        fVar3 = (float)puVar10[0x2a];
        if ((int)puVar10[0x2a] < 0) {
          fVar3 = fVar3 + 4.294967e+09;
        }
        fVar2 = (float)*(int *)(pSVar6 + 0xa8);
        if (*(int *)(pSVar6 + 0xa8) < 0) {
          fVar2 = fVar2 + 4.294967e+09;
        }
        GmMat3::SetBlend(
            param_2, (GmMat3 *)(pSVar6 + 0x24), (GmMat3 *)(puVar10 + 9),
            (fVar1 * 0.001) / (fVar3 * 0.001 - fVar2 * 0.001) + 1.0);
        uVar7 = GmMat3::IsOrthonormal(param_2);
        if (uVar7 == 0) {
          GmMat3::OrthoNormalize(param_2);
        }
        ComputeNextSpeed(this, (GmVec3 *)(puVar10 + 3), (GmVec3 *)(puVar10 + 6),
                         uVar4, local_30);
      } else {
        Interpolate(this, param_1, param_2, local_30, local_24, local_38,
                    (SHistoryPoint *)puVar10, (SHistoryPoint *)puVar11);
      }
      SetLastPrediction(this, param_1, param_2, local_30, local_24, local_38);
      return;
    }
    *(undefined4 *)param_1 = *puVar10;
    *(undefined4 *)(param_1 + 4) = puVar10[1];
    *(undefined4 *)(param_1 + 8) = puVar10[2];
    puVar11 = puVar10 + 9;
    puVar12 = (undefined4 *)param_2;
    for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
    puVar11 = puVar10 + 0x12;
    puVar10 = puVar10 + 3;
    param_3 = local_38;
  }
LAB_005368db:
  SetLastPrediction(this, param_1, param_2, (GmVec3 *)puVar10,
                    (GmMat3 *)puVar11, param_3);
  *(undefined4 *)(this + 0x528) = 0;
  *(undefined4 *)(this + 0x520) = 0;
  *(undefined4 *)(this + 0x524) = 0;
  *(undefined4 *)(this + 0x51c) = 0;
  return;
}

/* public: void __thiscall CHmsDyna::Reset(void) */

void __thiscall CHmsDyna::Reset(CHmsDyna *this)

{
  CHmsStateDyna *this_00;
  undefined4 uVar1;
  undefined4 extraout_ECX;

  this_00 = (CHmsStateDyna *)(this + 0x10c);
  CHmsStateDyna::Reset(this_00);
  CHmsStateDyna::Reset((CHmsStateDyna *)(this + 0x1c0));
  *(undefined4 *)(this + 0x32c) = extraout_ECX;
  *(CHmsStateDyna **)(this + 0x328) = this_00;
  CFastBuffer<>::Reset((CFastBuffer<> *)(this + 0x330));
  uVar1 = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 8) = 0;
  CHmsStateDyna::Reset((CHmsStateDyna *)(this + 0xc));
  *(undefined4 *)(this + 4) = uVar1;
  return;
}

/* public: void __thiscall CHmsDyna::RestoreStaticState(class
   CClassicBufferMemory &,int,unsigned char) */

void __thiscall CHmsDyna::RestoreStaticState(CHmsDyna *this,
                                             CClassicBufferMemory *param_1,
                                             int param_2, uchar param_3)

{
  if (param_2 != 0) {
    CHmsStateDyna::RestoreState(*(CHmsStateDyna **)(this + 0x328), param_1,
                                param_3);
    return;
  }
  CHmsStateDyna::RestoreState(*(CHmsStateDyna **)(this + 0x32c), param_1,
                              param_3);
  return;
}

/* public: void __thiscall CHmsDyna::RotateOf(class GmMat3 const &) */

void __thiscall CHmsDyna::RotateOf(CHmsDyna *this, GmMat3 *param_1)

{
  int iVar1;
  GmMat3 local_30[36];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  GmMat3::SetMult(local_30, param_1, (GmMat3 *)(*(int *)(this + 0x32c) + 0x10));
  GmMat3::OrthoNormalize(local_30);
  iVar1 = *(int *)(this + 0x32c);
  local_c = *(undefined4 *)(iVar1 + 0x34);
  local_8 = *(undefined4 *)(iVar1 + 0x38);
  local_4 = *(undefined4 *)(iVar1 + 0x3c);
  SetLocation(this, (GmIso4 *)local_30);
  return;
}

/* public: void __thiscall CHmsDyna::SaveState(class CClassicBufferMemory &,enum
   CHmsItem::ESaveStateVersion)const  */

void __thiscall CHmsDyna::SaveState(CHmsDyna *this,
                                    CClassicBufferMemory *param_1,
                                    ESaveStateVersion param_2)

{
  GmQuat *pGVar1;
  GmQuat *pGVar2;

  pGVar1 = *(GmQuat **)(this + 0x328);
  if (param_2 == 0) {
    GmArchive::WriteVec3Pos_9((CClassicBuffer *)param_1,
                              (GmVec3 *)(pGVar1 + 0x34));
    GmArchive::WriteQuat_6((CClassicBuffer *)param_1, pGVar1);
  } else if (param_2 == 1) {
    GmArchive::WriteVec3Pos_12((CClassicBuffer *)param_1,
                               (GmVec3 *)(pGVar1 + 0x34));
    GmArchive::WriteQuat_6((CClassicBuffer *)param_1, pGVar1);
    if ((CHmsZoneDynamic::s_IsTweakedSpeeds == 0) ||
        (pGVar2 = pGVar1 + 0xa4, *(int *)(pGVar1 + 0xa0) == 0)) {
      pGVar2 = pGVar1 + 0x40;
    }
    GmArchive::WriteVec3_4((CClassicBuffer *)param_1, (GmVec3 *)pGVar2);
    GmArchive::WriteVec3_4((CClassicBuffer *)param_1,
                           (GmVec3 *)(pGVar1 + 0x58));
    return;
  }
  return;
}

/* private: void __thiscall CHmsDyna::SetAllInterpolationConstant(void) */

void __thiscall CHmsDyna::SetAllInterpolationConstant(CHmsDyna *this)

{
  uint uVar1;
  int extraout_EDX;

  *(undefined4 *)(this + 0x528) = 0;
  uVar1 = *(uint *)(this + 0x350);
  if (*(uint *)(this + 0x34c) <= uVar1) {
    uVar1 = uVar1 - *(uint *)(this + 0x34c);
  }
  SetAllInterpolationMethods(
      this, (SHistoryPoint *)(uVar1 * 0xe0 + *(int *)(this + 0x348)), 2);
  SetAllInterpolationMethods(this, (SHistoryPoint *)(this + 0x438), 2);
  *(undefined4 *)(extraout_EDX + 0xc) = 0;
  *(undefined4 *)(extraout_EDX + 0x10) = 0;
  *(undefined4 *)(extraout_EDX + 0x14) = 0;
  *(undefined4 *)(extraout_EDX + 0x18) = 0;
  *(undefined4 *)(extraout_EDX + 0x1c) = 0;
  *(undefined4 *)(extraout_EDX + 0x20) = 0;
  *(undefined4 *)(extraout_EDX + 0x48) = 0;
  *(undefined4 *)(extraout_EDX + 0x4c) = 0;
  *(undefined4 *)(extraout_EDX + 0x50) = 0;
  *(undefined4 *)(extraout_EDX + 0x6c) = 0;
  *(undefined4 *)(extraout_EDX + 0x70) = 0;
  *(undefined4 *)(extraout_EDX + 0x74) = 0;
  *(undefined4 *)(extraout_EDX + 0x60) = 0;
  *(undefined4 *)(extraout_EDX + 100) = 0;
  *(undefined4 *)(extraout_EDX + 0x68) = 0;
  *(undefined4 *)(extraout_EDX + 0x84) = 0;
  *(undefined4 *)(extraout_EDX + 0x88) = 0;
  *(undefined4 *)(extraout_EDX + 0x8c) = 0;
  return;
}

/* private: void __thiscall CHmsDyna::SetAllInterpolationLinear(void) */

void __thiscall CHmsDyna::SetAllInterpolationLinear(CHmsDyna *this)

{
  uint uVar1;
  uint uVar2;
  GmVec3 *pGVar3;
  uint uVar4;
  SHistoryPoint *pSVar5;

  uVar1 = *(uint *)(this + 0x34c);
  uVar2 = *(int *)(this + 0x350) + 1;
  if (uVar1 <= uVar2) {
    uVar2 = uVar2 - uVar1;
  }
  uVar4 = *(uint *)(this + 0x350);
  pGVar3 = (GmVec3 *)(uVar2 * 0xe0 + *(int *)(this + 0x348));
  if (uVar1 <= uVar4) {
    uVar4 = uVar4 - uVar1;
  }
  pSVar5 = (SHistoryPoint *)(uVar4 * 0xe0 + *(int *)(this + 0x348));
  SetAllInterpolationMethods(this, pSVar5, 3);
  SetAllInterpolationMethods(this, (SHistoryPoint *)(this + 0x438), 3);
  ComputeSpeed(this, (GmVec3 *)(pSVar5 + 0xc), pGVar3, (GmVec3 *)pSVar5,
               *(ulong *)(pGVar3 + 0xa8), *(ulong *)(pSVar5 + 0xa8));
  *(undefined4 *)(pSVar5 + 0x18) = 0;
  *(undefined4 *)(pSVar5 + 0x1c) = 0;
  *(undefined4 *)(pSVar5 + 0x20) = 0;
  ComputeSpeed(this, (GmVec3 *)(pSVar5 + 0x48), pGVar3 + 0x24,
               (GmVec3 *)(pSVar5 + 0x24), *(ulong *)(pGVar3 + 0xa8),
               *(ulong *)(pSVar5 + 0xa8));
  *(undefined4 *)(pSVar5 + 0x6c) = 0;
  *(undefined4 *)(pSVar5 + 0x70) = 0;
  *(undefined4 *)(pSVar5 + 0x74) = 0;
  ComputeSpeed(this, (GmVec3 *)(pSVar5 + 0x60), pGVar3 + 0x3c,
               (GmVec3 *)(pSVar5 + 0x3c), *(ulong *)(pGVar3 + 0xa8),
               *(ulong *)(pSVar5 + 0xa8));
  *(undefined4 *)(pSVar5 + 0x84) = 0;
  *(undefined4 *)(pSVar5 + 0x88) = 0;
  *(undefined4 *)(pSVar5 + 0x8c) = 0;
  return;
}

/* private: void __thiscall CHmsDyna::SetAllInterpolationMethods(struct
   CHmsDyna::SHistoryPoint
   &,enum CHmsDyna::EPredictionType) */

void __thiscall CHmsDyna::SetAllInterpolationMethods(CHmsDyna *this,
                                                     SHistoryPoint *param_1,
                                                     EPredictionType param_2)

{
  *(EPredictionType *)(param_1 + 0xb0) = param_2;
  *(EPredictionType *)(param_1 + 0xb4) = param_2;
  *(EPredictionType *)(param_1 + 0xb8) = param_2;
  *(EPredictionType *)(param_1 + 0xbc) = param_2;
  *(EPredictionType *)(param_1 + 0xc0) = param_2;
  *(EPredictionType *)(param_1 + 0xc4) = param_2;
  *(EPredictionType *)(param_1 + 0xd4) = param_2;
  *(EPredictionType *)(param_1 + 0xd8) = param_2;
  *(EPredictionType *)(param_1 + 0xdc) = param_2;
  return;
}

/* public: void __thiscall CHmsDyna::SetAngularSpeed(class GmVec3 const &) */

void __thiscall CHmsDyna::SetAngularSpeed(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;

  iVar1 = *(int *)(this + 0x32c);
  *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)param_1;
  *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)(param_1 + 8);
  return;
}

/* public: void __thiscall CHmsDyna::SetAsyncPrevDeltaT_End(class GmIso4 const
 * &) */

void __thiscall CHmsDyna::SetAsyncPrevDeltaT_End(CHmsDyna *this,
                                                 GmIso4 *param_1)

{
  GmIso4 *this_00;
  float fVar1;
  GmIso4 local_30[36];
  float local_c;
  float local_8;
  float local_4;

  if (CHmsCamera::s_AsyncPrevDeltaT <= 0.0) {
    fVar1 = 1.0;
  } else {
    fVar1 = CHmsCamera::s_AsyncPrevDeltaT /
            (*(float *)(CMwCmdBufferCore::TheCoreCmdBuffer + 0x80) + 0.001);
  }
  this_00 = (GmIso4 *)(this + 200);
  GmIso4::SetBlend(local_30, param_1, this_00, fVar1);
  GmIso4::SetInverse(this_00, param_1);
  GmIso4::Mult(this_00, local_30);
  *(float *)(this + 0xf8) = local_c - *(float *)(param_1 + 0x24);
  *(float *)(this + 0xfc) = local_8 - *(float *)(param_1 + 0x28);
  *(float *)(this + 0x100) = local_4 - *(float *)(param_1 + 0x2c);
  return;
}

/* public: void __thiscall CHmsDyna::SetDynamicType(enum CHmsDyna::EDynamicType)
 */

void __thiscall CHmsDyna::SetDynamicType(CHmsDyna *this, EDynamicType param_1)

{
  int iVar1;

  *(EDynamicType *)(this + 0x340) = param_1;
  iVar1 = *(int *)(this + 0x328);
  *(undefined4 *)(iVar1 + 0x60) = 0;
  *(undefined4 *)(iVar1 + 0x5c) = 0;
  *(undefined4 *)(iVar1 + 0x58) = 0;
  iVar1 = *(int *)(this + 0x32c);
  *(undefined4 *)(iVar1 + 0x60) = 0;
  *(undefined4 *)(iVar1 + 0x5c) = 0;
  *(undefined4 *)(iVar1 + 0x58) = 0;
  iVar1 = *(int *)(this + 0x328);
  *(undefined4 *)(iVar1 + 0x78) = 0;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  *(undefined4 *)(iVar1 + 0x70) = 0;
  iVar1 = *(int *)(this + 0x32c);
  *(undefined4 *)(iVar1 + 0x78) = 0;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  *(undefined4 *)(iVar1 + 0x70) = 0;
  return;
}

/* public: void __thiscall CHmsDyna::SetForce(class GmVec3 const &) */

void __thiscall CHmsDyna::SetForce(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;

  iVar1 = *(int *)(this + 0x32c);
  *(undefined4 *)(iVar1 + 100) = *(undefined4 *)param_1;
  *(undefined4 *)(iVar1 + 0x68) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(param_1 + 8);
  return;
}

/* private: void __thiscall CHmsDyna::SetLastPrediction(class GmVec3 const
   &,class GmMat3 const
   &,class GmVec3 const &,class GmMat3 const &,unsigned long) */

void __thiscall CHmsDyna::SetLastPrediction(CHmsDyna *this, GmVec3 *param_1,
                                            GmMat3 *param_2, GmVec3 *param_3,
                                            GmMat3 *param_4, ulong param_5)

{
  int iVar1;
  undefined4 *puVar2;

  *(undefined4 *)(this + 0x52c) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x530) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x534) = *(undefined4 *)(param_1 + 8);
  puVar2 = (undefined4 *)(this + 0x538);
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *(undefined4 *)param_2;
    param_2 = (GmMat3 *)((int)param_2 + 4);
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(this + 0x55c) = *(undefined4 *)param_3;
  *(undefined4 *)(this + 0x560) = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)(this + 0x564) = *(undefined4 *)(param_3 + 8);
  puVar2 = (undefined4 *)(this + 0x568);
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *(undefined4 *)param_4;
    param_4 = (GmMat3 *)((int)param_4 + 4);
    puVar2 = puVar2 + 1;
  }
  *(ulong *)(this + 0x58c) = param_5;
  SetLinearSpeed(this, param_3);
  return;
}

/* public: void __thiscall CHmsDyna::SetLinearSpeed(class GmVec3 const &) */

void __thiscall CHmsDyna::SetLinearSpeed(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;

  iVar1 = *(int *)(this + 0x32c);
  *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)param_1;
  *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(param_1 + 8);
  return;
}

/* public: void __thiscall CHmsDyna::SetLocalAngularSpeed(class GmVec3 const &)
 */

void __thiscall CHmsDyna::SetLocalAngularSpeed(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;

  iVar1 = *(int *)(this + 0x32c);
  local_c = *(float *)(iVar1 + 0x18) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x10) * *(float *)param_1 +
            *(float *)(iVar1 + 0x14) * *(float *)(param_1 + 4);
  local_8 = *(float *)(iVar1 + 0x24) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x20) * *(float *)(param_1 + 4) +
            *(float *)(iVar1 + 0x1c) * *(float *)param_1;
  local_4 = *(float *)(iVar1 + 0x30) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x2c) * *(float *)(param_1 + 4) +
            *(float *)(iVar1 + 0x28) * *(float *)param_1;
  SetAngularSpeed(this, (GmVec3 *)&local_c);
  return;
}

/* public: void __thiscall CHmsDyna::SetLocalForce(class GmVec3 const &) */

void __thiscall CHmsDyna::SetLocalForce(CHmsDyna *this, GmVec3 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;

  iVar7 = *(int *)(this + 0x32c);
  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_1 + 4);
  fVar3 = *(float *)(param_1 + 8);
  fVar4 = *(float *)param_1;
  fVar5 = *(float *)(param_1 + 4);
  fVar6 = *(float *)(param_1 + 8);
  *(float *)(iVar7 + 100) = *(float *)(iVar7 + 0x18) * *(float *)(param_1 + 8) +
                            *(float *)(iVar7 + 0x10) * *(float *)param_1 +
                            *(float *)(iVar7 + 0x14) * *(float *)(param_1 + 4);
  *(float *)(iVar7 + 0x68) = *(float *)(iVar7 + 0x24) * fVar3 +
                             *(float *)(iVar7 + 0x20) * fVar2 +
                             *(float *)(iVar7 + 0x1c) * fVar1;
  *(float *)(iVar7 + 0x6c) = *(float *)(iVar7 + 0x30) * fVar6 +
                             *(float *)(iVar7 + 0x2c) * fVar5 +
                             *(float *)(iVar7 + 0x28) * fVar4;
  return;
}

/* public: void __thiscall CHmsDyna::SetLocalLinearSpeed(class GmVec3 const &)
 */

void __thiscall CHmsDyna::SetLocalLinearSpeed(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;

  iVar1 = *(int *)(this + 0x32c);
  local_c = *(float *)(iVar1 + 0x18) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x10) * *(float *)param_1 +
            *(float *)(iVar1 + 0x14) * *(float *)(param_1 + 4);
  local_8 = *(float *)(iVar1 + 0x24) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x20) * *(float *)(param_1 + 4) +
            *(float *)(iVar1 + 0x1c) * *(float *)param_1;
  local_4 = *(float *)(iVar1 + 0x30) * *(float *)(param_1 + 8) +
            *(float *)(iVar1 + 0x2c) * *(float *)(param_1 + 4) +
            *(float *)(iVar1 + 0x28) * *(float *)param_1;
  SetLinearSpeed(this, (GmVec3 *)&local_c);
  return;
}

/* public: void __thiscall CHmsDyna::SetLocalTorque(class GmVec3 const &) */

void __thiscall CHmsDyna::SetLocalTorque(CHmsDyna *this, GmVec3 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;

  iVar7 = *(int *)(this + 0x32c);
  fVar1 = *(float *)param_1;
  fVar2 = *(float *)(param_1 + 4);
  fVar3 = *(float *)(param_1 + 8);
  fVar4 = *(float *)param_1;
  fVar5 = *(float *)(param_1 + 4);
  fVar6 = *(float *)(param_1 + 8);
  *(float *)(iVar7 + 0x70) =
      *(float *)(iVar7 + 0x18) * *(float *)(param_1 + 8) +
      *(float *)(iVar7 + 0x10) * *(float *)param_1 +
      *(float *)(iVar7 + 0x14) * *(float *)(param_1 + 4);
  *(float *)(iVar7 + 0x74) = *(float *)(iVar7 + 0x24) * fVar3 +
                             *(float *)(iVar7 + 0x20) * fVar2 +
                             *(float *)(iVar7 + 0x1c) * fVar1;
  *(float *)(iVar7 + 0x78) = *(float *)(iVar7 + 0x30) * fVar6 +
                             *(float *)(iVar7 + 0x2c) * fVar5 +
                             *(float *)(iVar7 + 0x28) * fVar4;
  return;
}

/* public: void __thiscall CHmsDyna::SetLocation(class GmIso4 const &) */

void __thiscall CHmsDyna::SetLocation(CHmsDyna *this, GmIso4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;

  GmQuat::Set(*(GmQuat **)(this + 0x328), (GmMat3 *)param_1);
  puVar2 = (undefined4 *)param_1;
  puVar3 = (undefined4 *)(*(int *)(this + 0x328) + 0x10);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  GmMat3::SetMult((GmMat3 *)(*(int *)(this + 0x328) + 0x7c),
                  (GmMat3 *)(*(int *)(this + 0x328) + 0x10),
                  (GmMat3 *)(*(int *)(this + 0x108) + 4));
  GmMat3::MultTranspose((GmMat3 *)(*(int *)(this + 0x328) + 0x7c),
                        (GmMat3 *)(*(int *)(this + 0x328) + 0x10));
  GmVec4::Set(*(GmVec4 **)(this + 0x32c), *(GmVec4 **)(this + 0x328));
  puVar2 = (undefined4 *)(*(int *)(this + 0x32c) + 0x10);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *(undefined4 *)param_1;
    param_1 = (GmIso4 *)((int)param_1 + 4);
    puVar2 = puVar2 + 1;
  }
  GmMat3::Set((GmMat3 *)(*(int *)(this + 0x32c) + 0x7c),
              (GmMat3 *)(*(int *)(this + 0x328) + 0x7c));
  return;
}

/* public: void __thiscall CHmsDyna::SetTorque(class GmVec3 const &) */

void __thiscall CHmsDyna::SetTorque(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;

  iVar1 = *(int *)(this + 0x32c);
  *(undefined4 *)(iVar1 + 0x70) = *(undefined4 *)param_1;
  *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x78) = *(undefined4 *)(param_1 + 8);
  return;
}

/* public: void __thiscall CHmsDyna::SetTranslation(class GmVec3 const &) */

void __thiscall CHmsDyna::SetTranslation(CHmsDyna *this, GmVec3 *param_1)

{
  int iVar1;

  iVar1 = *(int *)(this + 0x328);
  *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)param_1;
  *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(param_1 + 8);
  iVar1 = *(int *)(this + 0x32c);
  *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)param_1;
  *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(param_1 + 8);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* private: int __thiscall CHmsDyna::TestIfRespawn(void) */

int __thiscall CHmsDyna::TestIfRespawn(CHmsDyna *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  ulong uVar9;
  uint uVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
  ushort uVar14;

  uVar9 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x344));
  if (uVar9 < 2) {
    return 1;
  }
  uVar10 = *(uint *)(this + 0x350);
  if (*(uint *)(this + 0x34c) <= uVar10) {
    uVar10 = uVar10 - *(uint *)(this + 0x34c);
  }
  pfVar11 = (float *)(uVar10 * 0xe0 + *(int *)(this + 0x348));
  uVar10 = *(int *)(this + 0x350) + 1;
  if (*(uint *)(this + 0x34c) <= uVar10) {
    uVar10 = uVar10 - *(uint *)(this + 0x34c);
  }
  pfVar12 = (float *)(uVar10 * 0xe0 + *(int *)(this + 0x348));
  fVar1 = pfVar12[0x2a];
  iVar13 = (int)pfVar11[0x2a] - (int)fVar1;
  if (iVar13 != 0) {
    fVar2 = (float)iVar13;
    if (iVar13 < 0) {
      fVar2 = fVar2 + 4.294967e+09;
    }
    fVar2 = 1.0 / fVar2;
    fVar3 = fVar2 * (*pfVar11 - *pfVar12);
    fVar4 = (pfVar11[1] - pfVar12[1]) * fVar2;
    fVar2 = fVar2 * (pfVar11[2] - pfVar12[2]);
    fVar5 = fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3;
    if (_DAT_00cdb68c < fVar5 != (NAN(_DAT_00cdb68c) || NAN(fVar5))) {
      return 1;
    }
    uVar9 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x344));
    if ((((2 < uVar9) && (pfVar11 = (float *)GetLastHistoryPointMinusTwo(this),
                          pfVar12[0x2b] == 0.0)) &&
         (pfVar11[0x2b] == 0.0)) &&
        (iVar13 = (int)fVar1 - (int)pfVar11[0x2a], iVar13 != 0)) {
      fVar1 = (float)iVar13;
      if (iVar13 < 0) {
        fVar1 = fVar1 + 4.294967e+09;
      }
      fVar1 = 1.0 / fVar1;
      fVar6 = fVar1 * (*pfVar12 - *pfVar11);
      fVar7 = (pfVar12[1] - pfVar11[1]) * fVar1;
      fVar1 = fVar1 * (pfVar12[2] - pfVar11[2]);
      fVar8 = fVar7 * fVar7 + fVar6 * fVar6 + fVar1 * fVar1;
      if (fVar8 <= 5e-05) {
        uVar14 = (ushort)(fVar5 < 0.0001) << 8 | (ushort)(fVar5 == 0.0001)
                                                     << 0xe;
      } else {
        fVar1 = fVar3 * fVar6 + fVar4 * fVar7 + fVar2 * fVar1;
        fVar2 = (fVar1 * fVar1) / fVar8;
        if (fVar1 < 0.0) {
          return 1;
        }
        if (fVar8 + fVar8 < fVar2 != (NAN(fVar8 + fVar8) || NAN(fVar2))) {
          return 1;
        }
        uVar14 = (ushort)(fVar5 * 0.2 < fVar2) << 8 |
                 (ushort)(fVar5 * 0.2 == fVar2) << 0xe;
      }
      if (uVar14 == 0) {
        return 1;
      }
    }
  }
  return 0;
}

/* private: void __thiscall CHmsDyna::UpdateHistory(unsigned long) */

void __thiscall CHmsDyna::UpdateHistory(CHmsDyna *this, ulong param_1)

{
  CFastBuffer<> *this_00;
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;

  this_00 = (CFastBuffer<> *)(this + 0x344);
  uVar1 = CFastBuffer<>::GetCount(this_00);
  if (uVar1 != 0) {
    uVar2 = *(uint *)(this + 0x350);
    if (*(uint *)(this + 0x34c) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(this + 0x34c);
    }
    if (s_MaxFutureUpdateAllowed + param_1 <
        *(uint *)(uVar2 * 0xe0 + 0xa8 + *(int *)(this + 0x348))) {
      CFastBufferWheel<>::ClearWheel((CFastBufferWheel<> *)this_00);
      return;
    }
    if (3 < uVar1) {
      iVar4 = 0;
      if (uVar1 != 0) {
        uVar3 = uVar1;
        do {
          uVar2 = *(int *)(this + 0x350) + -1 + uVar3;
          if (*(uint *)(this + 0x34c) <= uVar2) {
            uVar2 = uVar2 - *(uint *)(this + 0x34c);
          }
          if (param_1 - 1000 <=
              *(uint *)(uVar2 * 0xe0 + 0xa8 + *(int *)(this + 0x348)))
            break;
          iVar4 = iVar4 + 1;
          uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
        if (iVar4 != 0) {
          if (uVar1 - iVar4 < 3) {
            iVar4 = uVar1 - 3;
          }
          for (; iVar4 != 0; iVar4 = iVar4 + -1) {
            CFastBufferWheel<>::Pull((CFastBufferWheel<> *)this_00);
          }
        }
      }
    }
  }
  return;
}

/* public: void __thiscall CHmsDyna::ValidateDynamicState(void) */

void __thiscall CHmsDyna::ValidateDynamicState(CHmsDyna *this)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;

  puVar2 = *(undefined4 **)(this + 0x32c);
  puVar3 = *(undefined4 **)(this + 0x328);
  for (iVar1 = 0x2d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}

/* public: __thiscall CHmsDyna::~CHmsDyna(void) */

void __thiscall CHmsDyna::~CHmsDyna(CHmsDyna *this)

{
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x344));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x330));
  return;
}

// *************
// CHmsStateDyna
// *************

/* public: void __thiscall CHmsDyna::CHmsStateDyna::OldRestoreState(class
   CClassicBufferMemory
   &,unsigned char) */

void __thiscall CHmsDyna::CHmsStateDyna::OldRestoreState(
    CHmsStateDyna *this, CClassicBufferMemory *param_1, uchar param_2)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  float *this_00;
  float10 *extraout_ECX;
  float10 *extraout_ECX_00;
  float10 *extraout_ECX_01;
  float10 *extraout_ECX_02;
  float10 *extraout_ECX_03;
  float10 *extraout_ECX_04;
  float10 *extraout_ECX_05;
  float10 *extraout_ECX_06;
  float10 *extraout_ECX_07;
  float10 *extraout_ECX_08;
  undefined4 extraout_ECX_09;
  float10 *extraout_ECX_10;
  float10 *extraout_ECX_11;
  float10 *extraout_ECX_12;
  undefined4 extraout_ECX_13;
  undefined4 uVar4;
  float10 *extraout_ECX_14;
  float10 *extraout_ECX_15;
  float10 *extraout_ECX_16;
  byte bVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 extraout_EDX_08;
  undefined4 extraout_EDX_09;
  undefined4 extraout_EDX_10;
  undefined4 extraout_EDX_11;
  undefined4 extraout_EDX_12;
  undefined4 extraout_EDX_13;
  undefined4 extraout_EDX_14;
  float *pfVar6;
  float *pfVar7;
  float10 fVar8;
  float10 fVar9;
  uint local_34;
  float local_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;

  pfVar6 = (float *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc));
  bVar5 = param_2;
  if (param_2 == 0xff) {
    bVar5 = *(byte *)pfVar6;
    pfVar6 = (float *)((int)pfVar6 + 1);
  }
  uVar2 = (uint)bVar5;
  this_00 = (float *)(uVar2 & 0x10);
  local_24 = (float)(uVar2 & 0x20);
  uVar2 = uVar2 & 0x80;
  local_34 = uVar2;
  if ((bVar5 & 0xf) == 0) {
    local_34 = 1;
  }
  iVar3 = 0x10;
  if ((bVar5 & 0x10) == 0) {
    if ((bVar5 & 0x20) != 0) {
      if (local_34 != 0) {
        iVar3 = 0x1c;
      }
      if ((bVar5 & 0x40) != 0) {
        iVar3 = iVar3 + 0xc;
      }
    }
  } else if ((bVar5 & 0x20) != 0) {
    if (local_34 != 0) {
      iVar3 = 0x14;
    }
    if ((bVar5 & 0x40) != 0) {
      iVar3 = iVar3 + 4;
    }
  }
  (**(code **)(*(int *)param_1 + 0x28))(iVar3 - (uint)(param_2 != 0xff));
  if ((bVar5 & 0xf) == 0) {
    uVar2 = 1;
  }
  if ((bVar5 & 0x40) == 0) {
    local_24 = (float)((*(byte *)pfVar6 - 0x80) * 0x10000 +
                       (uint) * (ushort *)((int)pfVar6 + 1)) *
               0.002;
    fStack_20 = (float)((*(byte *)((int)pfVar6 + 3) - 0x80) * 0x10000 +
                        (uint) * (ushort *)(pfVar6 + 1)) *
                0.002;
    pfVar7 = (float *)((int)pfVar6 + 9);
    fStack_1c = (float)((*(byte *)((int)pfVar6 + 6) - 0x80) * 0x10000 +
                        (uint) * (ushort *)((int)pfVar6 + 7)) *
                0.002;
  } else {
    local_24 = *pfVar6;
    pfVar7 = pfVar6 + 3;
    fStack_20 = pfVar6[1];
    fStack_1c = pfVar6[2];
  }
  this_00[0xd] = local_24;
  this_00[0xe] = fStack_20;
  this_00[0xf] = fStack_1c;
  if ((bVar5 & 0x40) == 0) {
    pfVar6 = (float *)((int)pfVar7 + 6);
    fVar8 = (float10)__CIcos((float10 *)(uint) * (ushort *)pfVar7,
                             (int)*(short *)((int)pfVar7 + 2));
    fVar9 = (float10)__CIcos(extraout_ECX_04, extraout_EDX_04);
    local_24 = (float)fVar9 * (float)fVar8;
    fVar9 = (float10)__CIsin(extraout_ECX_05, extraout_EDX_05);
    fStack_20 = (float)fVar9 * (float)fVar8;
    fVar8 = (float10)__CIsin(extraout_ECX_06, extraout_EDX_06);
    fStack_1c = (float)fVar8;
    fVar8 = (float10)__CIsin(extraout_ECX_07, extraout_EDX_07);
    fStack_8 = (float)fVar8;
    fStack_10 = fStack_8 * local_24;
    fStack_c = fStack_20 * fStack_8;
    fStack_8 = fStack_8 * fStack_1c;
    fVar8 = (float10)__CIcos(extraout_ECX_08, extraout_EDX_08);
  } else {
    pfVar6 = (float *)((int)pfVar7 + 3);
    fVar8 = (float10)__CIcos((float10 *)(uint) * (byte *)pfVar7,
                             (int)*(char *)((int)pfVar7 + 1));
    fVar9 = (float10)__CIcos(extraout_ECX, extraout_EDX);
    local_24 = (float)fVar9 * (float)fVar8;
    fVar9 = (float10)__CIsin(extraout_ECX_00, extraout_EDX_00);
    fStack_20 = (float)fVar9 * (float)fVar8;
    fVar8 = (float10)__CIsin(extraout_ECX_01, extraout_EDX_01);
    fStack_1c = (float)fVar8;
    fVar8 = (float10)__CIsin(extraout_ECX_02, extraout_EDX_02);
    fStack_8 = (float)fVar8;
    fStack_10 = fStack_8 * local_24;
    fStack_c = fStack_20 * fStack_8;
    fStack_8 = fStack_8 * fStack_1c;
    fVar8 = (float10)__CIcos(extraout_ECX_03, extraout_EDX_03);
  }
  local_24 = (float)fVar8;
  fStack_20 = fStack_10;
  fStack_18 = fStack_8;
  fStack_1c = fStack_c;
  fStack_14 = local_24;
  GmVec4::Set((GmVec4 *)this_00, (GmVec4 *)&local_24);
  GmMat3::Set((GmMat3 *)(this_00 + 4), *this_00, this_00[1], this_00[2],
              this_00[3]);
  if (this != (CHmsStateDyna *)0x0) {
    uVar4 = extraout_ECX_09;
    pfVar7 = pfVar6;
    if (uVar2 != 0) {
      if ((bVar5 & 0x40) == 0) {
        local_24 = *pfVar6;
        pfVar7 = pfVar6 + 3;
        fStack_20 = pfVar6[1];
        fStack_1c = pfVar6[2];
      } else {
        if (*(short *)pfVar6 == -0x8000) {
          fVar1 = 0.0;
        } else {
          fVar8 = (float10)__CIexp(extraout_ECX_09);
          fVar1 = (float)fVar8;
        }
        pfVar7 = pfVar6 + 1;
        fVar8 = (float10)__CIcos((float10 *)(int)*(char *)((int)pfVar6 + 2),
                                 (int)*(char *)((int)pfVar6 + 3));
        fVar9 = (float10)__CIcos(extraout_ECX_10, extraout_EDX_09);
        fStack_14 = (float)fVar9 * (float)fVar8;
        fVar9 = (float10)__CIsin(extraout_ECX_11, extraout_EDX_10);
        fStack_10 = (float)fVar9 * (float)fVar8;
        fVar8 = (float10)__CIsin(extraout_ECX_12, extraout_EDX_11);
        fStack_c = (float)fVar8;
        local_24 = fVar1 * fStack_14;
        fStack_20 = fStack_10 * fVar1;
        fStack_1c = fVar1 * fStack_c;
        uVar4 = extraout_ECX_13;
      }
      this_00[0x10] = local_24;
      this_00[0x11] = fStack_20;
      this_00[0x12] = fStack_1c;
    }
    if (local_34 != 0) {
      if ((bVar5 & 0x40) == 0) {
        local_24 = *pfVar7;
        fStack_20 = pfVar7[1];
        fVar1 = pfVar7[2];
      } else {
        if (*(short *)pfVar7 == -0x8000) {
          fVar1 = 0.0;
        } else {
          fVar8 = (float10)__CIexp(uVar4);
          fVar1 = (float)fVar8;
        }
        fVar8 = (float10)__CIcos((float10 *)(int)*(char *)((int)pfVar7 + 2),
                                 (int)*(char *)((int)pfVar7 + 3));
        fVar9 = (float10)__CIcos(extraout_ECX_14, extraout_EDX_12);
        fStack_14 = (float)fVar9 * (float)fVar8;
        fVar9 = (float10)__CIsin(extraout_ECX_15, extraout_EDX_13);
        fStack_10 = (float)fVar9 * (float)fVar8;
        fVar8 = (float10)__CIsin(extraout_ECX_16, extraout_EDX_14);
        local_24 = fVar1 * fStack_14;
        fStack_20 = fStack_10 * fVar1;
        fVar1 = fVar1 * (float)fVar8;
      }
      this_00[0x16] = local_24;
      this_00[0x17] = fStack_20;
      this_00[0x18] = fVar1;
    }
  }
  return;
}

/* public: void __thiscall CHmsDyna::CHmsStateDyna::Reset(void) */

void __thiscall CHmsDyna::CHmsStateDyna::Reset(CHmsStateDyna *this)

{
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xac) = 0;
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0xa4) = 0;
  return;
}

/* public: void __thiscall CHmsDyna::CHmsStateDyna::RestoreState(class
   CClassicBufferMemory
   &,unsigned char) */

void __thiscall CHmsDyna::CHmsStateDyna::RestoreState(
    CHmsStateDyna *this, CClassicBufferMemory *param_1, uchar param_2)

{
  if (param_2 == '\0') {
    GmArchive::ReadVec3Pos_9((CClassicBuffer *)param_1,
                             (GmVec3 *)(this + 0x34));
    GmArchive::ReadQuat_6((CClassicBuffer *)param_1, (GmQuat *)this);
    GmMat3::Set((GmMat3 *)(this + 0x10), *(float *)this, *(float *)(this + 4),
                *(float *)(this + 8), *(float *)(this + 0xc));
  } else if (param_2 == '\x01') {
    GmArchive::ReadVec3Pos_12((CClassicBuffer *)param_1,
                              (GmVec3 *)(this + 0x34));
    GmArchive::ReadQuat_6((CClassicBuffer *)param_1, (GmQuat *)this);
    GmMat3::Set((GmMat3 *)(this + 0x10), *(float *)this, *(float *)(this + 4),
                *(float *)(this + 8), *(float *)(this + 0xc));
    GmArchive::ReadVec3_4((CClassicBuffer *)param_1, (GmVec3 *)(this + 0x40));
    GmArchive::ReadVec3_4((CClassicBuffer *)param_1, (GmVec3 *)(this + 0x58));
    return;
  }
  return;
}
