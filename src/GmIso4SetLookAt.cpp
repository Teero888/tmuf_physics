
/* public: void __thiscall GmIso4::SetLookAt(class GmVec3 const &,class GmVec3
   const &,class GmVec3 const &) */

void __thiscall GmIso4::SetLookAt(GmIso4 *this, GmVec3 *param_1,
                                  GmVec3 *param_2, GmVec3 *param_3)

{
  float local_c;
  float local_8;
  float local_4;

  local_c = *(float *)param_2 - *(float *)param_1;
  local_8 = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  local_4 = *(float *)(param_2 + 8) - *(float *)(param_1 + 8);
  GmMat3::SetDOVandUpV((GmMat3 *)this, (GmVec3 *)&local_c, param_3);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 8);
  return;
}

/* public: void __thiscall GmIso4::SetLookAt(class GmVec3 const &,class GmVec3
   const &,unsigned long) */

void __thiscall GmIso4::SetLookAt(GmIso4 *this, GmVec3 *param_1,
                                  GmVec3 *param_2, ulong param_3)

{
  float local_c;
  float local_8;
  float local_4;

  local_c = *(float *)param_2 - *(float *)param_1;
  local_8 = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  local_4 = *(float *)(param_2 + 8) - *(float *)(param_1 + 8);
  GmMat3::SetDOV((GmMat3 *)this, (GmVec3 *)&local_c, param_3);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 8);
  return;
}
