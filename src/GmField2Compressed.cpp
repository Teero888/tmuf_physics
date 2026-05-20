// Class implementation: GmField2Compressed

// =================================================
// Function: GmField2Compressed::GetAxeXAt
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmField2Compressed::GetAxeXAt(void *this,GmField2Compressed *param_1,GmNat2 *param_2,float *param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  GmNat2 *unaff_EDI;
  float *in_stack_00000010;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           GmBinTree2::GetCellAt((void *)((int)this + 0x34),(GmBinTree2 *)param_1,unaff_EDI);
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)((int)this + 0x38),pCVar1,unaff_ESI);
  *in_stack_00000010 =
       (float)param_3 +
       ((float)((byte)pSVar2[1] & 0x7f) / (float)_DAT_00b55d48) *
       (*(float *)((int)this + 0x30) - (float)param_3);
  return;
}
}

// =================================================
// Function: GmField2Compressed::GetScaleAndRotationAt
// =================================================
void __thiscall
GmField2Compressed::GetScaleAndRotationAt
          (void *this,GmField2Compressed *param_1,GmVec2 *param_2,float *param_3,float *param_4)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  GmVec2 *pGVar4;
  GmField2Compressed *pGVar5;
  int iVar6;
  GmVec2 *unaff_EBX;
  GmVec2 *unaff_EBP;
  GmVec2 *unaff_ESI;
  GmVec2 *unaff_EDI;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST0_04;
  float10 extraout_ST0_05;
  float10 extraout_ST0_06;
  float10 fVar7;
  float10 extraout_ST0_07;
  float unaff_retaddr;
  float fStack00000014;
  float *pfStack00000018;
  undefined4 *in_stack_0000001c;
  float *in_stack_00000020;
  GmVec2 *in_stack_ffffffc8;
  GmNat2 local_30 [8];
  GmVec2 *local_28;
  float local_24;
  GmVec2 *local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  GmField2Compressed *local_c;
  float local_8;
  GmField2Compressed *local_4;
  
  iVar6 = GmField2Base::GetBoundingCoords
                    (this,(GmField2Base *)param_1,(GmVec2 *)&local_8,local_30,
                     (GmNat2 *)&stack0xffffffc8,unaff_ESI);
  pGVar5 = local_4;
  if (iVar6 == 0) {
    *param_3 = *(float *)((int)this + 0x24);
    *param_4 = *(float *)((int)this + 0x28);
    return;
  }
  local_c = local_4;
  local_8 = unaff_retaddr;
  GetVec2At(this,(GmField2Compressed *)&local_c,(GmNat2 *)&local_24,unaff_EDI);
  __CIsin();
  param_3 = (float *)(float)extraout_ST0;
  local_10 = (float)param_3 * (float)local_20;
  __CIcos();
  param_3 = (float *)(float)extraout_ST0_00;
  local_c = (GmField2Compressed *)((float)param_3 * (float)local_20);
  GetVec2At(this,(GmField2Compressed *)&stack0x00000000,(GmNat2 *)&local_20,unaff_EBP);
  __CIsin();
  param_4 = (float *)(float)extraout_ST0_01;
  local_14 = (float)param_4 * local_1c;
  __CIcos();
  pGVar4 = local_20;
  param_4 = (float *)(float)extraout_ST0_02;
  local_10 = (float)param_4 * local_1c;
  param_1 = pGVar5;
  param_2 = local_20;
  GetVec2At(this,(GmField2Compressed *)&param_1,(GmNat2 *)&local_1c,unaff_EBX);
  __CIsin();
  fStack00000014 = (float)extraout_ST0_03;
  fVar1 = fStack00000014 * local_18;
  __CIcos();
  fStack00000014 = (float)extraout_ST0_04;
  param_1 = (GmField2Compressed *)(fStack00000014 * local_18);
  param_2 = local_28;
  param_3 = (float *)pGVar4;
  GetVec2At(this,(GmField2Compressed *)&param_2,(GmNat2 *)&local_18,in_stack_ffffffc8);
  __CIsin();
  pfStack00000018 = (float *)(float)extraout_ST0_05;
  param_3 = (float *)((float)pfStack00000018 * local_14);
  __CIcos();
  param_4 = (float *)((float)extraout_ST0_06 * local_14);
  fVar3 = (1.0 - local_24) * (1.0 - (float)local_20);
  fVar2 = local_24 * (1.0 - (float)local_20);
  local_1c = (1.0 - local_24) * (float)local_20;
  local_14 = fVar2 * (float)local_c + fVar3 * (float)local_4 + local_1c * (float)param_1 +
             local_24 * (float)local_20 * (float)param_3;
  local_10 = local_24 * (float)local_20 * (float)param_4 +
             local_1c * (float)param_2 + local_8 * fVar2 + fVar1 * fVar3;
  pfStack00000018 = (float *)(local_14 * local_14 + local_10 * local_10);
  local_24 = fVar3;
  fVar7 = (float10)func_0x009c1b40();
  param_3 = (float *)(float)fVar7;
  pfStack00000018 = param_3;
  __CIatan2();
  *in_stack_0000001c = param_3;
  *in_stack_00000020 = (float)extraout_ST0_07;
  return;
}
}

// =================================================
// Function: GmField2Compressed::GetScaleAt
// =================================================
void __thiscall
GmField2Compressed::GetScaleAt
          (void *this,GmField2Compressed *param_1,GmVec2 *param_2,float *param_3)
{
{
  float fVar1;
  int iVar2;
  float *unaff_EBX;
  float *unaff_EBP;
  GmVec2 *unaff_ESI;
  float *unaff_EDI;
  float in_stack_00000010;
  float *in_stack_0000001c;
  float *in_stack_ffffffd8;
  GmNat2 local_20 [4];
  float local_1c;
  undefined4 local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar2 = GmField2Base::GetBoundingCoords
                    (this,(GmField2Base *)param_1,(GmVec2 *)&local_18,(GmNat2 *)&local_10,
                     (GmNat2 *)&local_8,unaff_ESI);
  local_c = local_10;
  fVar1 = local_14;
  if (iVar2 == 0) {
    *param_3 = *(float *)((int)this + 0x24);
    return;
  }
  local_1c = local_14;
  local_18 = local_10;
  GetAxeXAt(this,(GmField2Compressed *)&local_1c,local_20,unaff_EDI);
  local_10 = local_8;
  GetAxeXAt(this,(GmField2Compressed *)&local_10,local_20,unaff_EBP);
  local_c = fVar1;
  GetAxeXAt(this,(GmField2Compressed *)&local_c,(GmNat2 *)&local_14,unaff_EBX);
  GetAxeXAt(this,(GmField2Compressed *)&stack0x00000000,(GmNat2 *)&local_8,in_stack_ffffffd8);
  *in_stack_0000001c =
       (float)param_3 * in_stack_00000010 * local_4 +
       in_stack_00000010 * (1.0 - (float)param_3) * local_c +
       (1.0 - (float)param_3) * (1.0 - in_stack_00000010) * local_10 +
       (float)param_3 * (1.0 - in_stack_00000010) * local_14;
  return;
}
}

// =================================================
// Function: GmField2Compressed::GetVec2At
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmField2Compressed::GetVec2At
          (void *this,GmField2Compressed *param_1,GmNat2 *param_2,GmVec2 *param_3)
{
{
  uint uVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  GmNat2 *unaff_EDI;
  float *in_stack_00000010;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           GmBinTree2::GetCellAt((void *)((int)this + 0x34),(GmBinTree2 *)param_1,unaff_EDI);
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)((int)this + 0x38),pCVar2,unaff_ESI);
  uVar1 = *(uint *)pSVar3;
  *in_stack_00000010 =
       *(float *)((int)this + 0x2c) +
       ((float)((byte)(uVar1 >> 8) & 0x7f) / (float)_DAT_00b55d48) *
       (*(float *)((int)this + 0x30) - *(float *)((int)this + 0x2c));
  in_stack_00000010[1] =
       ((float)(uVar1 & 0xff) / (float)_DAT_00b55d50) * (float)_DAT_00b59bb8 - (float)_DAT_00b36110;
  return;
}
}

