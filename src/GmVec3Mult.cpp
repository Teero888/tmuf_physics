
/* public: void __thiscall GmVec3::Mult(class GmIso4 const &) */

void __thiscall GmVec3::Mult(GmVec3 *this, GmIso4 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;

  fVar1 = *(float *)this;
  fVar2 = *(float *)(this + 4);
  fVar3 = *(float *)(this + 8);
  *(float *)this = fVar2 * *(float *)(param_1 + 4) + fVar1 * *(float *)param_1 +
                   fVar3 * *(float *)(param_1 + 8) + *(float *)(param_1 + 0x24);
  *(float *)(this + 4) =
      *(float *)(param_1 + 0x14) * fVar3 + *(float *)(param_1 + 0x10) * fVar2 +
      *(float *)(param_1 + 0xc) * fVar1 + *(float *)(param_1 + 0x28);
  *(float *)(this + 8) =
      *(float *)(param_1 + 0x18) * fVar1 + *(float *)(param_1 + 0x1c) * fVar2 +
      *(float *)(param_1 + 0x20) * fVar3 + *(float *)(param_1 + 0x2c);
  return;
}

/* public: void __thiscall GmVec3::Mult(class GmMat3 const &) */

void __thiscall GmVec3::Mult(GmVec3 *this, GmMat3 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;

  fVar1 = *(float *)(param_1 + 0xc);
  fVar2 = *(float *)this;
  fVar3 = *(float *)(param_1 + 0x10);
  fVar4 = *(float *)(param_1 + 0x14);
  fVar5 = *(float *)(param_1 + 0x18);
  fVar6 = *(float *)this;
  fVar7 = *(float *)(param_1 + 0x1c);
  fVar8 = *(float *)(this + 4);
  fVar9 = *(float *)(param_1 + 0x20);
  *(float *)this = *(float *)(param_1 + 8) * *(float *)(this + 8) +
                   *(float *)param_1 * *(float *)this +
                   *(float *)(param_1 + 4) * *(float *)(this + 4);
  *(float *)(this + 4) = fVar4 * *(float *)(this + 8) +
                         fVar3 * *(float *)(this + 4) + fVar1 * fVar2;
  *(float *)(this + 8) =
      fVar9 * *(float *)(this + 8) + fVar7 * fVar8 + fVar5 * fVar6;
  return;
}

/* public: void __thiscall GmVec3::Mult(class GmMat4 const &) */

void __thiscall GmVec3::Mult(GmVec3 *this, GmMat4 *param_1)

{
  float fVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_20 = *(undefined4 *)this;
  local_1c = *(undefined4 *)(this + 4);
  local_18 = *(undefined4 *)(this + 8);
  local_14 = 0x3f800000;
  GmVec4::SetMult((GmVec4 *)&local_10, (GmVec4 *)&local_20, param_1);
  fVar1 = 1.0 / ABS(local_4);
  *(float *)this = fVar1 * local_10;
  *(float *)(this + 4) = local_c * fVar1;
  *(float *)(this + 8) = fVar1 * local_8;
  return;
}
