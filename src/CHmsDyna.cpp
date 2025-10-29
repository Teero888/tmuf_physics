
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
