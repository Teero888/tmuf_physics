// Class implementation: CFuncPuffLull

// =================================================
// Function: CFuncPuffLull::UpdateStateCurrent
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CFuncPuffLull::UpdateStateCurrent
          (CFuncPuffLull *this,CFuncPuffLull *param_1,ulong param_2,EState param_3,float param_4)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  uint uVar7;
  double *unaff_ESI;
  uint uVar8;
  SCasterCat *pSVar9;
  CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat> *unaff_EDI;
  CFuncPuffLull *this_00;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  double dVar10;
  int local_bc;
  int local_b8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_b4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_b0;
  float local_ac;
  int local_98;
  CFuncPuffLull *local_90;
  float local_8c;
  CFuncPuffLull *local_88;
  float local_84;
  ulong local_80;
  float local_7c;
  float local_78;
  float local_74;
  undefined4 local_70;
  undefined4 local_6c;
  float local_68;
  undefined4 local_64;
  undefined8 local_60;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> local_58 [16];
  double local_48;
  double local_40 [7];
  
  this_00 = this + 0x14;
  local_90 = this_00;
  uVar4 = CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat>::SetParsingAll(this_00,unaff_EDI);
  local_b0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             (int)ROUND((float)param_3 / (float)_DAT_00b5b8d8);
  local_ac = (float)(int)local_b0 * (float)_DAT_00b5b8d8;
  uVar8 = 0;
  local_80 = uVar4;
  do {
    __CIsin();
    *(float *)(local_58 + uVar8 * 8 + -4) = -(float)extraout_ST0;
    __CIcos();
    uVar8 = uVar8 + 1;
    *(float *)(local_58 + uVar8 * 8 + -8) = -(float)extraout_ST0_00;
  } while (uVar8 < 2);
  if (param_2 == 0) {
    local_b0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (uVar4 != 0) {
      local_90 = (CFuncPuffLull *)0x3f800000;
      local_84 = 1.0;
      local_88 = (CFuncPuffLull *)0x0;
      do {
        pSVar5 = CFastBufferCat<struct_CFuncPuffLull::SPuffLull,struct_SFastCat>::operator[]
                           (this_00,local_b0,(ulong)unaff_ESI);
        local_b0 = local_58;
        local_b8 = 2;
        pSVar9 = pSVar5 + 0x20;
        do {
          fVar1 = *(float *)(local_b0 + 4);
          local_78 = *(float *)pSVar5;
          uVar8 = *(uint *)(pSVar5 + 0x14);
          local_70 = *(undefined4 *)(pSVar5 + 8);
          local_6c = *(undefined4 *)(pSVar5 + 0xc);
          uVar7 = (uint)param_1 % uVar8;
          local_74 = *(float *)(pSVar5 + 4);
          local_68 = *(float *)(pSVar5 + 0x10);
          fVar3 = (float)(int)uVar7;
          if ((int)uVar7 < 0) {
            fVar3 = fVar3 + _DAT_00c418d0;
          }
          fVar2 = fVar3 * local_68 * *(float *)local_b0 + local_78;
          *(float *)(pSVar9 + -4) = fVar2;
          *(float *)pSVar9 = fVar1 * fVar3 * local_68 + local_74;
          dVar10 = _modf((double)fVar2,(double *)&local_60);
          unaff_ESI = &local_48;
          *(float *)(pSVar9 + -4) =
               (float)(&local_90)[-((int)(float)dVar10 >> 0x1f)] + (float)dVar10;
          dVar10 = _modf((double)*(float *)pSVar9,unaff_ESI);
          *(float *)pSVar9 = (&local_84)[-((int)(float)dVar10 >> 0x1f)] + (float)dVar10;
          fVar1 = (float)(int)uVar8;
          if ((int)uVar8 < 0) {
            fVar1 = fVar1 + _DAT_00c418d0;
          }
          if ((float)_DAT_00b362c0 * fVar1 <= fVar3) {
            if ((float)_DAT_00b41ea8 * fVar1 <= fVar3) {
              fVar3 = (float)(int)(uVar8 - uVar7);
              if ((int)(uVar8 - uVar7) < 0) {
                fVar3 = fVar3 + _DAT_00c418d0;
              }
              fVar3 = fVar3 / (fVar1 - (float)_DAT_00b41ea8 * fVar1);
            }
            else {
              fVar3 = 1.0;
            }
          }
          else {
            fVar3 = fVar3 / ((float)_DAT_00b362c0 * fVar1);
          }
          local_b0 = local_b0 + 8;
          *(float *)(pSVar9 + -8) = fVar3;
          local_b8 = local_b8 + -1;
          *(float *)(pSVar9 + 4) = *(float *)(pSVar5 + 8);
          pSVar9 = pSVar9 + 0x10;
        } while (local_b8 != 0);
        local_ac = (float)((int)local_ac + 1);
        *(float *)(pSVar5 + 0x28) = *(float *)(pSVar5 + 0x28) * (float)this;
        this_00 = local_88;
      } while ((uint)local_ac < (uint)local_7c);
      return;
    }
  }
  else {
    local_b4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (uVar4 != 0) {
      local_88 = (CFuncPuffLull *)0x0;
      local_84 = 1.0;
      local_60._0_4_ = 0x3f800000;
      local_64 = 0;
      do {
        pSVar5 = CFastBufferCat<struct_CFuncPuffLull::SPuffLull,struct_SFastCat>::operator[]
                           (this_00,local_b4,(ulong)unaff_ESI);
        pCVar6 = local_58;
        local_bc = 2;
        pSVar9 = pSVar5 + 0x40;
        do {
          local_90 = *(CFuncPuffLull **)pCVar6;
          local_8c = *(float *)(pCVar6 + 4);
          uVar8 = *(uint *)(pSVar5 + 0x14);
          local_74 = *(float *)(pSVar5 + 4);
          local_70 = *(undefined4 *)(pSVar5 + 8);
          local_68 = *(float *)(pSVar5 + 0x10);
          uVar7 = (uint)param_1 % uVar8;
          local_78 = *(float *)pSVar5;
          local_6c = *(undefined4 *)(pSVar5 + 0xc);
          fVar1 = (float)(int)uVar7;
          if ((int)uVar7 < 0) {
            fVar1 = fVar1 + _DAT_00c418d0;
          }
          fVar3 = fVar1 * local_68 * (float)local_90 + local_78;
          *(float *)(pSVar9 + -4) = fVar3;
          *(float *)pSVar9 = local_8c * fVar1 * local_68 + local_74;
          dVar10 = _modf((double)fVar3,&local_48);
          unaff_ESI = local_40;
          *(float *)(pSVar9 + -4) = (&local_84)[-((int)(float)dVar10 >> 0x1f)] + (float)dVar10;
          dVar10 = _modf((double)*(float *)pSVar9,unaff_ESI);
          *(float *)pSVar9 =
               *(float *)(local_58 + ((int)(float)dVar10 >> 0x1f) * -4 + -8) + (float)dVar10;
          fVar3 = (float)(int)uVar8;
          if ((int)uVar8 < 0) {
            fVar3 = fVar3 + _DAT_00c418d0;
          }
          local_b4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     ((float)_DAT_00b362c0 * fVar3);
          if ((float)local_b4 <= fVar1) {
            if ((float)_DAT_00b41ea8 * fVar3 <= fVar1) {
              fVar1 = (float)(int)(uVar8 - uVar7);
              if ((int)(uVar8 - uVar7) < 0) {
                fVar1 = fVar1 + _DAT_00c418d0;
              }
              fVar1 = fVar1 / (fVar3 - (float)_DAT_00b41ea8 * fVar3);
            }
            else {
              fVar1 = 1.0;
            }
          }
          else {
            fVar1 = fVar1 / (float)local_b4;
          }
          *(float *)(pSVar9 + -8) = fVar1;
          fVar1 = *(float *)(local_98 + 0x5c);
          pCVar6 = pCVar6 + 8;
          local_bc = local_bc + -1;
          *(float *)(pSVar9 + -4) = fVar1 * *(float *)(pSVar9 + -4);
          *(float *)pSVar9 = fVar1 * *(float *)pSVar9;
          *(float *)(pSVar9 + 4) =
               (*(float *)(pSVar5 + 8) * *(float *)(pSVar9 + -8) +
               *(float *)(pSVar5 + 8) * *(float *)(pSVar9 + -8)) * *(float *)(local_98 + 0x5c);
          pSVar9 = pSVar9 + 0x10;
        } while (local_bc != 0);
        local_b0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)local_b0 + 1);
        *(float *)(pSVar5 + 0x48) = (float)this * *(float *)(pSVar5 + 0x48);
        *(float *)(pSVar5 + 0x54) = (float)this * *(float *)(pSVar5 + 0x54);
        this_00 = local_88;
      } while (local_b0 < (uint)local_7c);
    }
  }
  return;
}
}

