// --- START GmCollision_Sphere_Box ---
// Function: GmCollision_Sphere_Box @ 008e8d10
// =================================================

int __cdecl
GmCollision_Sphere_Box(LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3)

{
  GmMat3 *pGVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  LocatedGmSurf *pLVar5;
  LocatedGmSurf *pLVar6;
  float fVar7;
  float fVar8;
  CGmCollisionBuffer *pCVar9;
  float *pfVar10;
  uint uVar11;
  GmIso3 *unaff_ESI;
  GmMat3 *unaff_EDI;
  float10 fVar12;
  float10 fVar13;
  float fStack00000010;
  undefined4 *in_stack_00000014;
  LocatedGmSurf *local_34;
  LocatedGmSurf *local_30;
  LocatedGmSurf *local_2c;
  LocatedGmSurf *local_28;
  LocatedGmSurf *local_24;
  LocatedGmSurf *local_20;
  LocatedGmSurf *local_1c;
  LocatedGmSurf *local_18;
  LocatedGmSurf *local_14;
  LocatedGmSurf *local_10;
  LocatedGmSurf *local_c;
  LocatedGmSurf *local_8;
  LocatedGmSurf *local_4;
  
  pGVar1 = *(GmMat3 **)(param_2 + 4);
  iVar2 = *(int *)param_1;
  iVar3 = *(int *)param_2;
  iVar4 = *(int *)(param_1 + 4);
  local_24 = (LocatedGmSurf *)(*(float *)(iVar4 + 0x24) - *(float *)(pGVar1 + 0x24));
  local_20 = (LocatedGmSurf *)(*(float *)(iVar4 + 0x28) - *(float *)(pGVar1 + 0x28));
  local_1c = (LocatedGmSurf *)(*(float *)(iVar4 + 0x2c) - *(float *)(pGVar1 + 0x2c));
  GmVec3::MultTranspose(&local_24,pGVar1,unaff_EDI);
  local_8 = (LocatedGmSurf *)(*(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x14));
  local_4 = (LocatedGmSurf *)(*(float *)(iVar3 + 0x18) + *(float *)(iVar3 + 0xc));
  local_28 = (LocatedGmSurf *)(*(float *)(iVar3 + 0x1c) + *(float *)(iVar3 + 0x10));
  local_14 = (LocatedGmSurf *)(*(float *)(iVar3 + 8) - *(float *)(iVar3 + 0x14));
  local_10 = (LocatedGmSurf *)(*(float *)(iVar3 + 0xc) - *(float *)(iVar3 + 0x18));
  local_c = (LocatedGmSurf *)(*(float *)(iVar3 + 0x10) - *(float *)(iVar3 + 0x1c));
  if ((float)local_14 <= (float)local_20) {
    if ((float)local_20 <= (float)local_8) {
      if ((float)local_10 <= (float)local_1c) {
        if ((float)local_1c <= (float)local_4) {
          if ((float)local_c <= (float)local_18) {
            if ((float)local_18 <= (float)local_28) {
              return 0;
            }
            uVar11 = 6;
            param_2 = local_28;
          }
          else {
            uVar11 = 5;
            param_2 = local_c;
          }
        }
        else {
          uVar11 = 4;
          param_2 = local_4;
        }
      }
      else {
        uVar11 = 3;
        param_2 = local_10;
      }
      param_3 = (CGmCollisionBuffer *)local_20;
      pLVar5 = param_2;
      param_2 = (LocatedGmSurf *)((float)local_1c - (float)param_2);
      local_34 = local_8;
      local_30 = local_14;
      goto LAB_008e8e62;
    }
    uVar11 = 2;
    pLVar5 = local_8;
  }
  else {
    uVar11 = 1;
    pLVar5 = local_14;
  }
  param_3 = (CGmCollisionBuffer *)local_1c;
  param_2 = (LocatedGmSurf *)((float)local_20 - (float)pLVar5);
  local_34 = local_4;
  local_30 = local_10;
LAB_008e8e62:
  pCVar9 = param_3;
  if (uVar11 < 5) {
    local_2c = local_18;
    local_24 = local_c;
  }
  else {
    local_2c = local_1c;
    param_2 = (LocatedGmSurf *)((float)local_18 - (float)pLVar5);
    local_28 = local_4;
    local_24 = local_10;
  }
  fVar7 = (float)param_2 * (float)param_2;
  if (*(float *)(iVar2 + 8) * *(float *)(iVar2 + 8) < fVar7) {
    return 0;
  }
  if ((float)param_3 <= (float)local_34) {
    if ((float)param_3 < (float)local_30) {
      param_3 = (CGmCollisionBuffer *)local_30;
    }
  }
  else {
    param_3 = (CGmCollisionBuffer *)local_34;
  }
  if ((float)local_2c <= (float)local_28) {
    if ((float)local_24 <= (float)local_2c) {
      param_2 = local_2c;
    }
    else {
      param_2 = local_24;
    }
  }
  else {
    param_2 = local_28;
  }
  local_24 = (LocatedGmSurf *)((float)local_2c - (float)param_2);
  if ((float)local_24 * (float)local_24 +
      ((float)pCVar9 - (float)param_3) * ((float)pCVar9 - (float)param_3) + fVar7 <=
      *(float *)(iVar2 + 8) * *(float *)(iVar2 + 8)) {
    pLVar6 = pLVar5;
    switch(uVar11) {
    case 1:
    case 2:
      pLVar6 = (LocatedGmSurf *)param_3;
      param_3 = (CGmCollisionBuffer *)pLVar5;
    case 3:
    case 4:
      local_18 = param_2;
      local_20 = (LocatedGmSurf *)param_3;
      local_1c = pLVar6;
      break;
    case 5:
    case 6:
      local_20 = (LocatedGmSurf *)param_3;
      local_1c = param_2;
      local_18 = pLVar5;
    }
    GmVec3::Mult(&local_20,(GmIso3 *)pGVar1,unaff_ESI);
    local_4 = (LocatedGmSurf *)(*(float *)(iVar4 + 0x24) - (float)local_1c);
    fVar7 = *(float *)(iVar4 + 0x28) - (float)local_18;
    fVar8 = *(float *)(iVar4 + 0x2c) - (float)local_14;
    fVar12 = (float10)func_0x009c1b40();
    fStack00000010 = 1.0 / (float)fVar12;
    local_20 = (LocatedGmSurf *)(*(float *)(iVar2 + 8) * *(float *)(iVar2 + 8));
    pfVar10 = (float *)(**(code **)*in_stack_00000014)();
    pfVar10[6] = (float)local_1c;
    pfVar10[7] = (float)local_18;
    pfVar10[8] = (float)local_14;
    pfVar10[3] = fStack00000010 * (float)local_4;
    pfVar10[4] = fVar7 * fStack00000010;
    pfVar10[5] = fStack00000010 * fVar8;
    fVar13 = (float10)func_0x009c1b40();
    fVar7 = -((float)fVar13 - (float)fVar12);
    *pfVar10 = fVar7 * pfVar10[3];
    pfVar10[1] = pfVar10[4] * fVar7;
    pfVar10[2] = fVar7 * pfVar10[5];
    *(undefined2 *)(pfVar10 + 9) = *(undefined2 *)(iVar2 + 4);
    *(undefined2 *)((int)pfVar10 + 0x26) = *(undefined2 *)(iVar3 + 4);
    return 1;
  }
  return 0;
}
// --- END GmCollision_Sphere_Box ---

// --- START GmCollision_Sphere_Ellipsoid ---
// Function: GmCollision_Sphere_Ellipsoid @ 008e9130
// =================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
GmCollision_Sphere_Ellipsoid
          (LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3)

{
  void *pvVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float *pfVar10;
  float10 fVar11;
  undefined4 *in_stack_00000010;
  float local_18 [2];
  undefined2 local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00ade4a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar3 = *(int *)param_1;
  iVar4 = *(int *)param_2;
  GmSurfSphere::GmSurfSphere
            ((GmSurfSphere *)local_18,(GmSurfSphere *)(DAT_00cca150 ^ (uint)&stack0xffffffcc));
  local_10 = *(undefined2 *)(iVar4 + 4);
  pvVar1 = *(void **)(iVar4 + 8);
  local_c = *(void **)(iVar4 + 0xc);
  if ((float)local_c < (float)pvVar1 != ((float)local_c == (float)pvVar1)) {
    local_c = pvVar1;
  }
  pvVar1 = *(void **)(iVar4 + 0x10);
  if ((float)pvVar1 < (float)local_c == ((float)pvVar1 == (float)local_c)) {
    local_c = pvVar1;
  }
  iVar5 = *(int *)(param_2 + 4);
  iVar6 = *(int *)(param_1 + 4);
  fVar7 = *(float *)(iVar5 + 0x24) - *(float *)(iVar6 + 0x24);
  fVar8 = *(float *)(iVar5 + 0x28) - *(float *)(iVar6 + 0x28);
  local_18[0] = *(float *)(iVar5 + 0x2c) - *(float *)(iVar6 + 0x2c);
  fVar2 = (float)local_c + *(float *)(iVar3 + 8);
  if (fVar2 * fVar2 <= local_18[0] * local_18[0] + fVar7 * fVar7 + fVar8 * fVar8) {
    ExceptionList = local_8;
    return 0;
  }
  fVar11 = (float10)func_0x009c1b40();
  fVar2 = (float)fVar11;
  if (fVar2 <= _DAT_00bbdc5c) {
    pfVar10 = (float *)(**(code **)*in_stack_00000010)();
    pfVar10[3] = 0.0;
    pfVar10[4] = _DAT_00b2c060;
    pfVar10[5] = 0.0;
    fVar2 = (float)local_c + *(float *)(iVar3 + 8);
    fVar7 = (float)_PTR_00b2c178 * fVar2;
    *pfVar10 = fVar7;
    pfVar10[2] = fVar7;
    pfVar10[1] = fVar2;
    pfVar10[6] = *(float *)(iVar6 + 0x24);
    pfVar10[7] = *(float *)(iVar6 + 0x28);
    fVar2 = *(float *)(iVar6 + 0x2c);
  }
  else {
    pfVar10 = (float *)(**(code **)*in_stack_00000010)();
    fVar9 = 1.0 / fVar2;
    fVar7 = fVar9 * fVar7;
    fVar8 = fVar8 * fVar9;
    fVar9 = fVar9 * local_18[0];
    pfVar10[3] = -fVar7;
    pfVar10[4] = -fVar8;
    pfVar10[5] = -fVar9;
    fVar2 = ((float)local_c + *(float *)(iVar3 + 8)) - fVar2;
    *pfVar10 = fVar2 * fVar7;
    pfVar10[1] = fVar8 * fVar2;
    pfVar10[2] = fVar2 * fVar9;
    fVar2 = *(float *)(iVar3 + 8);
    pfVar10[6] = fVar2 * fVar7;
    pfVar10[7] = fVar8 * fVar2;
    pfVar10[8] = fVar2 * fVar9;
    pfVar10[6] = pfVar10[6] + *(float *)(iVar6 + 0x24);
    pfVar10[7] = *(float *)(iVar6 + 0x28) + pfVar10[7];
    fVar2 = *(float *)(iVar6 + 0x2c) + pfVar10[8];
  }
  pfVar10[8] = fVar2;
  *(undefined2 *)(pfVar10 + 9) = *(undefined2 *)(iVar3 + 4);
  *(undefined2 *)((int)pfVar10 + 0x26) = *(undefined2 *)(iVar4 + 4);
  ExceptionList = local_8;
  return 1;
}
// --- END GmCollision_Sphere_Ellipsoid ---

// --- START GmCollision_Sphere_Polygon ---
// Function: GmCollision_Sphere_Polygon @ 008e93b0
// =================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
GmCollision_Sphere_Polygon
          (LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3)

{
  float fVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float *this;
  float *pfVar9;
  float *this_00;
  GmIso3 *unaff_EBX;
  GmIso3 *unaff_EBP;
  GmIso3 *unaff_ESI;
  GmIso3 *unaff_EDI;
  float10 fVar10;
  float10 fVar11;
  undefined4 *in_stack_00000010;
  uint uStack_54;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar3 = *(int *)param_1;
  iVar4 = *(int *)param_2;
  if (*(int *)(param_1 + 8) == 0) {
    local_34 = 0.0;
    local_38 = 0.0;
    local_3c = 0.0;
  }
  else {
    iVar5 = *(int *)(param_1 + 4);
    local_3c = *(float *)(iVar5 + 0x24);
    local_38 = *(float *)(iVar5 + 0x28);
    local_34 = *(float *)(iVar5 + 0x2c);
  }
  if (*(int *)(param_2 + 8) != 0) {
    GmVec3::MultInverse(&local_3c,*(GmIso3 **)(param_2 + 4),unaff_EDI);
  }
  local_3c = local_30 - *(float *)(iVar4 + 0x10);
  fVar1 = *(float *)(iVar4 + 0x44) * local_3c +
          (local_38 - *(float *)(iVar4 + 8)) * *(float *)(iVar4 + 0x3c) +
          *(float *)(iVar4 + 0x40) * (local_34 - *(float *)(iVar4 + 0xc));
  if ((*(float *)(iVar3 + 8) < fVar1) || ((fVar1 < 0.0 && (*(int *)(iVar4 + 0x48) == 0)))) {
    return 0;
  }
  fVar10 = (float10)func_0x009c1b40();
  bVar2 = *(byte *)(iVar4 + 0x38);
  uStack_54 = 0;
  fVar6 = -fVar1;
  fStack_2c = fVar6 * *(float *)(iVar4 + 0x3c) + local_38;
  fStack_28 = *(float *)(iVar4 + 0x40) * fVar6 + local_34;
  fVar6 = fVar6 * *(float *)(iVar4 + 0x44) + local_30;
  fStack_24 = fVar6;
  if (bVar2 != 0) {
    pfVar9 = (float *)(iVar4 + 0x10);
    do {
      if (uStack_54 == bVar2 - 1) {
        param_3 = (CGmCollisionBuffer *)0x0;
      }
      else {
        param_3 = (CGmCollisionBuffer *)(uStack_54 + 1);
      }
      iVar5 = iVar4 + 8 + (int)param_3 * 0xc;
      fStack_20 = *(float *)(iVar4 + 8 + (int)param_3 * 0xc) - pfVar9[-2];
      fStack_1c = *(float *)(iVar5 + 4) - pfVar9[-1];
      fStack_18 = *(float *)(iVar5 + 8) - *pfVar9;
      if (_DAT_00d1a938 < fStack_1c * fStack_1c + fStack_20 * fStack_20 + fStack_18 * fStack_18) {
        fVar11 = (float10)func_0x009c1b40();
        fVar6 = 1.0 / (float)fVar11;
        fStack_20 = fVar6 * fStack_20;
        fStack_1c = fStack_1c * fVar6;
        fStack_18 = fVar6 * fStack_18;
        fVar6 = fStack_24;
      }
      fStack_8 = *(float *)(iVar4 + 0x44) * fStack_1c - fStack_18 * *(float *)(iVar4 + 0x40);
      fStack_4 = fStack_18 * *(float *)(iVar4 + 0x3c) - *(float *)(iVar4 + 0x44) * fStack_20;
      fVar8 = fStack_20 * *(float *)(iVar4 + 0x40) - fStack_1c * *(float *)(iVar4 + 0x3c);
      fStack_14 = fStack_2c - pfVar9[-2];
      fStack_10 = fStack_28 - pfVar9[-1];
      fStack_c = fVar6 - *pfVar9;
      fVar7 = fStack_c * fVar8 + fStack_10 * fStack_4 + fStack_14 * fStack_8;
      if ((float)fVar10 < fVar7) {
        return 0;
      }
      if (0.0 <= fVar1) {
        if (0.0 < fVar7) {
          if (_DAT_00c418e0 <= fStack_c * fStack_18 + fStack_10 * fStack_1c + fStack_20 * fStack_14)
          {
            fStack_14 = fStack_2c - *(float *)(iVar4 + 8 + (int)param_3 * 0xc);
            pfVar9 = (float *)(iVar4 + 8 + (int)param_3 * 0xc);
            fStack_10 = fStack_28 - pfVar9[1];
            fStack_c = fVar6 - pfVar9[2];
            if (fStack_14 * fStack_20 + fStack_10 * fStack_1c + fStack_c * fStack_18 <=
                _DAT_00c418e0) {
              fVar7 = -fVar7;
              fStack_20 = fVar7 * fStack_8 + fStack_2c;
              fStack_1c = fStack_28 + fStack_4 * fVar7;
              fStack_18 = fVar6 + fVar7 * fVar8;
              fVar1 = local_38 - fStack_20;
              fVar6 = local_34 - fStack_1c;
              local_3c = local_30 - fStack_18;
              fVar10 = (float10)func_0x009c1b40();
              this = (float *)(**(code **)*in_stack_00000010)();
              this[3] = *(float *)(iVar4 + 0x3c);
              this[4] = *(float *)(iVar4 + 0x40);
              this[5] = *(float *)(iVar4 + 0x44);
              fVar7 = ((float)fVar10 - *(float *)(iVar3 + 8)) * (1.0 / (float)fVar10);
              fStack_8 = fVar7 * fVar1;
              fStack_4 = fVar6 * fVar7;
              fVar1 = *(float *)(iVar4 + 0x44) * fVar7 * local_3c +
                      fStack_8 * *(float *)(iVar4 + 0x3c) + *(float *)(iVar4 + 0x40) * fStack_4;
              this_00 = this + 6;
              *this = fVar1 * *(float *)(iVar4 + 0x3c);
              this[1] = *(float *)(iVar4 + 0x40) * fVar1;
              this[2] = fVar1 * *(float *)(iVar4 + 0x44);
              *this_00 = fStack_20;
              this[7] = fStack_1c;
              fVar1 = fStack_18;
            }
            else {
              fVar6 = local_38 - *pfVar9;
              fVar7 = local_34 - pfVar9[1];
              local_3c = local_30 - pfVar9[2];
              fVar10 = (float10)func_0x009c1b40();
              fVar1 = (float)fVar10;
              if (*(float *)(iVar3 + 8) < fVar1) {
                return 0;
              }
              this = (float *)(**(code **)*in_stack_00000010)();
              this[3] = *(float *)(iVar4 + 0x3c);
              this_00 = this + 6;
              this[4] = *(float *)(iVar4 + 0x40);
              this[5] = *(float *)(iVar4 + 0x44);
              fVar1 = (fVar1 - *(float *)(iVar3 + 8)) * (1.0 / fVar1);
              fStack_8 = fVar1 * fVar6;
              fStack_4 = fVar7 * fVar1;
              fVar1 = *(float *)(iVar4 + 0x44) * fVar1 * local_3c +
                      *(float *)(iVar4 + 0x3c) * fStack_8 + *(float *)(iVar4 + 0x40) * fStack_4;
              *this = fVar1 * *(float *)(iVar4 + 0x3c);
              this[1] = *(float *)(iVar4 + 0x40) * fVar1;
              this[2] = fVar1 * *(float *)(iVar4 + 0x44);
              *this_00 = *pfVar9;
              this[7] = pfVar9[1];
              fVar1 = pfVar9[2];
            }
          }
          else {
            pfVar9 = (float *)(iVar4 + 8 + uStack_54 * 0xc);
            fVar6 = local_38 - *pfVar9;
            fVar7 = local_34 - pfVar9[1];
            local_3c = local_30 - pfVar9[2];
            fVar10 = (float10)func_0x009c1b40();
            fVar1 = (float)fVar10;
            if (*(float *)(iVar3 + 8) < fVar1) {
              return 0;
            }
            this = (float *)(**(code **)*in_stack_00000010)();
            this[3] = *(float *)(iVar4 + 0x3c);
            this_00 = this + 6;
            this[4] = *(float *)(iVar4 + 0x40);
            this[5] = *(float *)(iVar4 + 0x44);
            fVar1 = (fVar1 - *(float *)(iVar3 + 8)) * (1.0 / fVar1);
            fStack_8 = fVar1 * fVar6;
            fStack_4 = fVar7 * fVar1;
            fVar1 = *(float *)(iVar4 + 0x44) * fVar1 * local_3c +
                    fStack_8 * *(float *)(iVar4 + 0x3c) + *(float *)(iVar4 + 0x40) * fStack_4;
            *this = fVar1 * *(float *)(iVar4 + 0x3c);
            this[1] = *(float *)(iVar4 + 0x40) * fVar1;
            this[2] = fVar1 * *(float *)(iVar4 + 0x44);
            *this_00 = *pfVar9;
            this[7] = pfVar9[1];
            fVar1 = pfVar9[2];
          }
          goto LAB_008e9b5c;
        }
      }
      else if (0.0 < fVar7) {
        return 0;
      }
      uStack_54 = uStack_54 + 1;
      pfVar9 = pfVar9 + 3;
    } while (uStack_54 < *(byte *)(iVar4 + 0x38));
  }
  if (fVar1 <= 0.0) {
    pfVar9 = (float *)(**(code **)*in_stack_00000010)();
    pfVar9[3] = -*(float *)(iVar4 + 0x3c);
    pfVar9[4] = -*(float *)(iVar4 + 0x40);
    pfVar9[5] = -*(float *)(iVar4 + 0x44);
    fVar1 = fVar1 - *(float *)(iVar3 + 8);
    *pfVar9 = fVar1 * *(float *)(iVar4 + 0x3c);
    pfVar9[1] = *(float *)(iVar4 + 0x40) * fVar1;
    pfVar9[2] = fVar1 * *(float *)(iVar4 + 0x44);
    if (*(int *)(param_2 + 8) != 0) {
      GmVec3::Mult(pfVar9 + 6,*(GmIso3 **)(param_2 + 4),unaff_EBX);
      GmVec3::Mult(pfVar9 + 3,*(GmIso3 **)(param_2 + 4),unaff_ESI);
      GmVec3::Mult(pfVar9,*(GmIso3 **)(param_2 + 4),unaff_EBP);
    }
    pfVar9[6] = fStack_2c;
    pfVar9[7] = fStack_28;
    pfVar9[8] = fStack_24;
    *(undefined2 *)(pfVar9 + 9) = *(undefined2 *)(iVar3 + 4);
    *(undefined2 *)((int)pfVar9 + 0x26) = *(undefined2 *)(iVar4 + 4);
    return 1;
  }
  this = (float *)(**(code **)*in_stack_00000010)();
  this[3] = *(float *)(iVar4 + 0x3c);
  this_00 = this + 6;
  this[4] = *(float *)(iVar4 + 0x40);
  this[5] = *(float *)(iVar4 + 0x44);
  fVar1 = fVar1 - *(float *)(iVar3 + 8);
  *this = fVar1 * *(float *)(iVar4 + 0x3c);
  this[1] = *(float *)(iVar4 + 0x40) * fVar1;
  this[2] = fVar1 * *(float *)(iVar4 + 0x44);
  *this_00 = fStack_2c;
  this[7] = fStack_28;
  fVar1 = fStack_24;
LAB_008e9b5c:
  this_00[2] = fVar1;
  if (*(int *)(param_2 + 8) != 0) {
    GmVec3::Mult(this_00,*(GmIso3 **)(param_2 + 4),unaff_EBX);
    GmVec3::Mult(this + 3,*(GmIso3 **)(param_2 + 4),unaff_ESI);
    GmVec3::Mult(this,*(GmIso3 **)(param_2 + 4),unaff_EBP);
  }
  *(undefined2 *)(this + 9) = *(undefined2 *)(iVar3 + 4);
  *(undefined2 *)((int)this + 0x26) = *(undefined2 *)(iVar4 + 4);
  return 1;
}
// --- END GmCollision_Sphere_Polygon ---

// --- START GmCollision_Ellipsoid_Polygon ---
// Function: GmCollision_Ellipsoid_Polygon @ 008e9c50
// =================================================

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
GmCollision_Ellipsoid_Polygon
          (LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  GmIso3 *pGVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  float *pfVar9;
  GmSurfSphere *unaff_EBX;
  GmIso3 *unaff_EBP;
  GmMat43 *unaff_ESI;
  undefined4 *puVar10;
  uint uVar11;
  GmVec3 *unaff_EDI;
  float10 fVar12;
  undefined1 uStack00000010;
  CGmCollisionBuffer *in_stack_00000020;
  GmIso3 *pGVar13;
  GmVec3 *pGVar14;
  GmIso3 *pGVar15;
  GmSurfPolygon *local_110;
  GmSurfPolygon *local_108;
  undefined *local_104;
  float local_100;
  float *local_fc;
  undefined *local_f8;
  float local_f4;
  float fStack_f0;
  float fStack_ec;
  float local_e8 [4];
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  GmIso3 aGStack_b8 [4];
  float local_b4;
  float fStack_b0;
  float local_ac;
  float local_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  GmIso3 local_80 [4];
  float local_7c;
  GmIso3 aGStack_78 [36];
  GmSurfPolygon local_54 [8];
  GmSurfPolygon local_4c [8];
  undefined2 local_44 [28];
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00ade4e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar4 = *(int *)param_1;
  iVar6 = *(int *)param_2;
  if (*(int *)(param_1 + 8) == 0) {
    local_f8 = (undefined *)0x0;
    local_fc = (float *)0x0;
    local_100 = 0.0;
  }
  else {
    iVar8 = *(int *)(param_1 + 4);
    local_100 = *(float *)(iVar8 + 0x24);
    local_fc = *(float **)(iVar8 + 0x28);
    local_f8 = *(undefined **)(iVar8 + 0x2c);
  }
  if (*(int *)(param_2 + 8) != 0) {
    GmVec3::MultInverse(&local_100,*(GmIso3 **)(param_2 + 4),
                        (GmIso3 *)(DAT_00cca150 ^ (uint)&stack0xfffffed8));
  }
  local_108 = (GmSurfPolygon *)((float)local_fc - *(float *)(iVar6 + 8));
  local_104 = (undefined *)((float)local_f8 - *(float *)(iVar6 + 0xc));
  local_100 = local_f4 - *(float *)(iVar6 + 0x10);
  fVar2 = *(float *)(iVar6 + 0x44) * local_100 +
          *(float *)(iVar6 + 0x3c) * (float)local_108 + *(float *)(iVar6 + 0x40) * (float)local_104;
  fVar1 = *(float *)(iVar4 + 8);
  local_110 = *(GmSurfPolygon **)(iVar4 + 0xc);
  if ((float)local_110 < fVar1 != ((float)local_110 == fVar1)) {
    local_110 = (GmSurfPolygon *)fVar1;
  }
  fVar1 = *(float *)(iVar4 + 0x10);
  if (fVar1 < (float)local_110 == (fVar1 == (float)local_110)) {
    local_110 = (GmSurfPolygon *)fVar1;
  }
  if (((float)local_110 < fVar2) || ((fVar2 < 0.0 && (*(int *)(iVar6 + 0x48) == 0)))) {
    iVar6 = 0;
  }
  else {
    local_110 = (GmSurfPolygon *)CONCAT31(local_110._1_3_,*(undefined1 *)(iVar6 + 0x38));
    GmSurfPolygon::GmSurfPolygon(local_54,local_110,(uchar)unaff_EDI);
    if (*(int *)(param_2 + 8) == 0) {
      unaff_EDI = (GmVec3 *)0x8e9dd7;
      GmIso4::SetIdentity(local_80,unaff_ESI);
    }
    else {
      puVar10 = *(undefined4 **)(param_2 + 4);
      pGVar5 = local_80;
      for (iVar8 = 0xc; param_1 = (LocatedGmSurf *)param_3, iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined4 *)pGVar5 = *puVar10;
        puVar10 = puVar10 + 1;
        pGVar5 = pGVar5 + 4;
      }
    }
    if (*(int *)(param_1 + 8) != 0) {
      unaff_EDI = (GmVec3 *)0x8e9ded;
      GmIso4::MultInverse(&local_7c,*(GmIso3 **)(param_1 + 4),unaff_EBP);
    }
    fVar1 = 1.0 / *(float *)(iVar4 + 8);
    pfVar7 = &local_7c;
    pfVar9 = local_e8;
    for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pfVar9 = *pfVar7;
      pfVar7 = pfVar7 + 1;
      pfVar9 = pfVar9 + 1;
    }
    uVar11 = (uint)local_108 & 0xff;
    local_e8[0] = fVar1 * local_7c;
    local_e8[1] = local_e8[1] * fVar1;
    local_e8[2] = fVar1 * local_e8[2];
    fVar2 = 1.0 / *(float *)(iVar4 + 0xc);
    local_e8[3] = fVar2 * local_e8[3];
    local_d8 = local_d8 * fVar2;
    local_d4 = fVar2 * local_d4;
    fVar3 = 1.0 / *(float *)(iVar4 + 0x10);
    local_d0 = fVar3 * local_d0;
    local_cc = local_cc * fVar3;
    local_c8 = fVar3 * local_c8;
    local_c4 = local_c4 * fVar1;
    local_c0 = local_c0 * fVar2;
    local_bc = fVar3 * local_bc;
    if (uVar11 != 0) {
      pfVar7 = (float *)(iVar6 + 0x10);
      pfVar9 = (float *)local_44;
      do {
        uVar11 = uVar11 - 1;
        *pfVar9 = *pfVar7 * local_e8[2] + local_e8[0] * pfVar7[-2] + local_e8[1] * pfVar7[-1] +
                  local_c4;
        pfVar9[1] = *pfVar7 * local_d4 + local_e8[3] * pfVar7[-2] + local_d8 * pfVar7[-1] + local_c0
        ;
        *(float *)(aGStack_78 + (0x20 - iVar6) + (int)(pfVar7 + 3)) =
             *pfVar7 * local_c8 + local_d0 * pfVar7[-2] + local_cc * pfVar7[-1] + local_bc;
        pfVar7 = pfVar7 + 3;
        pfVar9 = pfVar9 + 3;
      } while (uVar11 != 0);
    }
    pGVar13 = (GmIso3 *)0x8e9f5d;
    GmSurfPolygon::ComputeNormalFromVertices(local_4c,(GmSurfPolygon *)unaff_EBP);
    local_44[0] = *(undefined2 *)(iVar6 + 4);
    pGVar14 = (GmVec3 *)0x8e9f7c;
    GmSurfSphere::GmSurfSphere((GmSurfSphere *)&local_b4,unaff_EBX);
    local_a8 = 1.0;
    local_ac = (float)CONCAT22(local_ac._2_2_,*(undefined2 *)(iVar4 + 4));
    uStack00000010 = 1;
    pGVar15 = (GmIso3 *)0x8e9fa3;
    pGVar5 = (GmIso3 *)(**(code **)(*(int *)in_stack_00000020 + 8))();
    local_108 = local_54;
    local_104 = PTR_DAT_00d1a940;
    local_f8 = PTR_DAT_00d1a940;
    local_fc = &local_c0;
    local_100 = 0.0;
    local_f4 = 0.0;
    iVar6 = GmCollision_Sphere_Polygon
                      ((LocatedGmSurf *)&local_fc,(LocatedGmSurf *)&local_108,in_stack_00000020);
    if (iVar6 != 0) {
      local_108 = (GmSurfPolygon *)0x0;
      local_104 = (undefined *)0x0;
      local_100 = 0.0;
      GmIso4::SetNUScaleTrans(&local_b4,(GmIso4 *)(iVar4 + 8),(GmVec3 *)&local_108,unaff_EDI);
      GmIso4::MultInverse(&fStack_b0,local_80,pGVar13);
      local_100 = 0.0;
      local_fc = (float *)0x0;
      local_f8 = (undefined *)0x0;
      local_f4 = 1.0 / *(float *)(iVar4 + 8);
      fStack_f0 = 1.0 / *(float *)(iVar4 + 0xc);
      fStack_ec = 1.0 / *(float *)(iVar4 + 0x10);
      GmIso4::SetNUScaleTrans(local_e8,(GmIso4 *)&local_f4,(GmVec3 *)&local_100,pGVar14);
      GmIso4::MultInverse(local_e8 + 1,aGStack_78,pGVar15);
      pGVar13 = (GmIso3 *)(**(code **)(*(int *)in_stack_00000020 + 8))();
      for (; pGVar5 < pGVar13; pGVar5 = pGVar5 + 1) {
        pGVar15 = pGVar5;
        pfVar7 = (float *)(**(code **)(*(int *)in_stack_00000020 + 4))();
        GmVec3::Mult(pfVar7 + 6,aGStack_b8,pGVar15);
        fVar1 = pfVar7[3];
        fVar2 = pfVar7[3];
        fVar3 = pfVar7[4];
        pfVar7[3] = pfVar7[5] * local_e8[0] + pfVar7[4] * fStack_ec + fStack_f0 * pfVar7[3];
        pfVar7[4] = pfVar7[5] * local_e8[3] + pfVar7[4] * local_e8[2] + local_e8[1] * fVar1;
        pfVar7[5] = pfVar7[5] * local_d0 + fVar3 * local_d4 + local_d8 * fVar2;
        if (_DAT_00d1a938 < pfVar7[5] * pfVar7[5] + pfVar7[3] * pfVar7[3] + pfVar7[4] * pfVar7[4]) {
          fVar12 = (float10)func_0x009c1b40();
          fVar1 = 1.0 / (float)fVar12;
          pfVar7[3] = fVar1 * pfVar7[3];
          pfVar7[4] = fVar1 * pfVar7[4];
          pfVar7[5] = fVar1 * pfVar7[5];
        }
        fVar1 = *pfVar7;
        fVar2 = *pfVar7;
        fVar3 = pfVar7[1];
        *pfVar7 = pfVar7[2] * local_ac + pfVar7[1] * fStack_b0 + local_b4 * *pfVar7;
        pfVar7[1] = pfVar7[2] * fStack_a0 + pfVar7[1] * fStack_a4 + local_a8 * fVar1;
        pfVar7[2] = pfVar7[2] * fStack_94 + fVar3 * fStack_98 + fStack_9c * fVar2;
        fVar1 = pfVar7[0xb];
        fVar2 = pfVar7[0xc];
        fVar3 = pfVar7[0xb];
        pfVar7[0xb] = pfVar7[0xd] * local_e8[0] + fStack_f0 * pfVar7[0xb] + fStack_ec * pfVar7[0xc];
        pfVar7[0xc] = pfVar7[0xd] * local_e8[3] + local_e8[1] * fVar1 + local_e8[2] * pfVar7[0xc];
        pfVar7[0xd] = pfVar7[0xd] * local_d0 + local_d8 * fVar3 + local_d4 * fVar2;
        if (_DAT_00d1a938 <
            pfVar7[0xd] * pfVar7[0xd] + pfVar7[0xb] * pfVar7[0xb] + pfVar7[0xc] * pfVar7[0xc]) {
          fVar12 = (float10)func_0x009c1b40();
          fVar1 = 1.0 / (float)fVar12;
          pfVar7[0xb] = fVar1 * pfVar7[0xb];
          pfVar7[0xc] = pfVar7[0xc] * fVar1;
          pfVar7[0xd] = fVar1 * pfVar7[0xd];
        }
      }
    }
  }
  ExceptionList = local_8;
  return iVar6;
}
// --- END GmCollision_Ellipsoid_Polygon ---

// --- START GmCollision_Sphere_Mesh ---
// Function: GmCollision_Sphere_Mesh @ 008ea2d0
// =================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
GmCollision_Sphere_Mesh(LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3)

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
  undefined2 uVar10;
  GmIso3 *pGVar11;
  int iVar12;
  SCasterCat *pSVar13;
  SCasterCat *pSVar14;
  SCasterCat *pSVar15;
  GmIso3 *pGVar16;
  float *pfVar17;
  undefined2 uVar18;
  int iVar19;
  LocatedGmSurf *pLVar20;
  CPlugVolumeProjector *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  GmIso3 *unaff_ESI;
  undefined4 *puVar21;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar22;
  GmMat43 *unaff_EDI;
  SCasterCat **ppSVar23;
  float10 fVar24;
  int *in_stack_00000010;
  GmIso3 *pGVar25;
  GmBoxAligned *in_stack_ffffff14;
  GmIso4 *in_stack_ffffff18;
  ulong in_stack_ffffff1c;
  ulong in_stack_ffffff20;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff24;
  ulong in_stack_ffffff28;
  int iStack_c8;
  SCasterCat *pSStack_c4;
  uint uStack_c0;
  SCasterCat *local_bc;
  float fStack_b8;
  float fStack_b4;
  GmIso3 *pGStack_b0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_ac;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_80;
  SCasterCat *apSStack_50 [3];
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  pGVar11 = *(GmIso3 **)(param_2 + 4);
  iVar12 = *(int *)param_1;
  if (*(int *)(param_1 + 8) == 0) {
    GmIso4::SetIdentity(apSStack_50 + 2,unaff_EDI);
    pLVar20 = (LocatedGmSurf *)param_3;
  }
  else {
    puVar21 = *(undefined4 **)(param_1 + 4);
    ppSVar23 = apSStack_50 + 2;
    for (iVar19 = 0xc; pLVar20 = param_2, iVar19 != 0; iVar19 = iVar19 + -1) {
      *ppSVar23 = (SCasterCat *)*puVar21;
      puVar21 = puVar21 + 1;
      ppSVar23 = ppSVar23 + 1;
    }
  }
  if (*(int *)(pLVar20 + 8) != 0) {
    GmIso4::MultInverse(&fStack_44,pGVar11,unaff_ESI);
  }
  local_bc = (SCasterCat *)0x0;
  fStack_b8 = (float)(**(code **)(*in_stack_00000010 + 8))();
  uStack_8 = *(undefined4 *)(iVar12 + 8);
  uStack_4 = *(undefined4 *)(iVar12 + 8);
  uStack_c = 0;
  uStack_10 = 0;
  uStack_14 = 0;
  GmBoxAligned::Mult(&uStack_14,(GmIso3 *)&fStack_44,unaff_ESI);
  pCVar22 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pCStack_ac = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iStack_c8 + 0x20),unaff_EBP);
  if (pCStack_ac != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSStack_c4 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                             (pSStack_c4 + 0x20,pCVar22,(ulong)unaff_EBX);
      unaff_EBX = (CPlugVolumeProjector *)(pSStack_c4 + 4);
      iVar19 = GmBoxAligned::TestInter(&uStack_8,unaff_EBX,in_stack_ffffff14,in_stack_ffffff18);
      if (iVar19 == 0) {
        pCVar22 = pCVar22 + (int)*(float *)local_bc;
      }
      else {
        if (*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(local_bc + 0x1c) !=
            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
          in_stack_ffffff14 = (GmBoxAligned *)0x8ea41d;
          pSVar15 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                              ((void *)((int)fStack_b8 + 0x10),
                               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(local_bc + 0x1c)
                               ,in_stack_ffffff1c);
          in_stack_ffffff18 = (GmIso4 *)0x8ea42f;
          CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                    ((void *)((int)fStack_b4 + 8),
                     *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar15 + 0x10),
                     in_stack_ffffff20);
          in_stack_ffffff1c = 0x8ea446;
          apSStack_50[0] =
               CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (pGStack_b0 + 8,
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar15 + 0x14),
                          (ulong)in_stack_ffffff24);
          in_stack_ffffff24 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar15 + 0x18);
          in_stack_ffffff20 = 0x8ea45d;
          apSStack_50[2] =
               CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (pCStack_ac + 8,in_stack_ffffff24,in_stack_ffffff28);
          fStack_b8 = (float)param_1 - *(float *)apSStack_50[0];
          uVar10 = *(undefined2 *)(pSVar15 + 0x1c);
          fStack_b4 = (float)param_2 - *(float *)(apSStack_50[0] + 4);
          pGStack_b0 = (GmIso3 *)((float)param_3 - *(float *)(apSStack_50[0] + 8));
          fVar1 = (float)pGStack_b0 * *(float *)(pSVar15 + 8) +
                  *(float *)pSVar15 * fStack_b8 + fStack_b4 * *(float *)(pSVar15 + 4);
          pCVar22 = pCStack_80;
          if ((fVar1 <= *(float *)(iVar12 + 8)) && (0.0 <= fVar1)) {
            in_stack_ffffff28 = 0x8ea4f3;
            fVar24 = (float10)func_0x009c1b40();
            pSStack_c4 = (SCasterCat *)(float)fVar24;
            fVar2 = -fVar1;
            uStack_c0 = 0;
            fVar3 = fVar2 * *(float *)pSVar15 + (float)param_1;
            fVar4 = *(float *)(pSVar15 + 4) * fVar2 + (float)param_2;
            fVar2 = fVar2 * *(float *)(pSVar15 + 8) + (float)param_3;
            do {
              if (uStack_c0 == 2) {
                pCStack_ac = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
              }
              else {
                pCStack_ac = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uStack_c0 + 1);
              }
              pSVar13 = apSStack_50[(int)pCStack_ac];
              pSVar14 = apSStack_50[uStack_c0];
              fStack_8c = *(float *)pSVar13 - *(float *)pSVar14;
              fStack_88 = *(float *)(pSVar13 + 4) - *(float *)(pSVar14 + 4);
              fStack_84 = *(float *)(pSVar13 + 8) - *(float *)(pSVar14 + 8);
              if (_DAT_00d1a938 <
                  fStack_88 * fStack_88 + fStack_8c * fStack_8c + fStack_84 * fStack_84) {
                in_stack_ffffff28 = 0x8ea5f6;
                fVar24 = (float10)func_0x009c1b40();
                fVar5 = 1.0 / (float)fVar24;
                fStack_8c = fVar5 * fStack_8c;
                fStack_88 = fStack_88 * fVar5;
                fStack_84 = fVar5 * fStack_84;
              }
              pSVar13 = apSStack_50[uStack_c0];
              fVar6 = fStack_88 * *(float *)(pSVar15 + 8) - fStack_84 * *(float *)(pSVar15 + 4);
              fVar7 = *(float *)pSVar15 * fStack_84 - *(float *)(pSVar15 + 8) * fStack_8c;
              fVar5 = *(float *)(pSVar15 + 4) * fStack_8c - *(float *)pSVar15 * fStack_88;
              pSVar14 = (SCasterCat *)
                        ((fVar2 - *(float *)(pSVar13 + 8)) * fVar5 +
                        (fVar4 - *(float *)(pSVar13 + 4)) * fVar7 +
                        (fVar3 - *(float *)pSVar13) * fVar6);
              local_bc = pSVar14;
              if ((float)pSStack_c4 < (float)pSVar14) goto LAB_008eaca1;
              if (0.0 < (float)pSVar14) {
                if (_DAT_00c418e0 <=
                    (fVar2 - *(float *)(pSVar13 + 8)) * fStack_84 +
                    (fVar4 - *(float *)(pSVar13 + 4)) * fStack_88 +
                    fStack_8c * (fVar3 - *(float *)pSVar13)) {
                  local_bc = apSStack_50[(int)pCStack_ac];
                  if ((fVar3 - *(float *)local_bc) * fStack_8c +
                      (fVar4 - *(float *)(local_bc + 4)) * fStack_88 +
                      (fVar2 - *(float *)(local_bc + 8)) * fStack_84 <= _DAT_00c418e0) {
                    fVar1 = -(float)pSVar14;
                    fVar3 = fVar1 * fVar6 + fVar3;
                    fVar4 = fVar4 + fVar7 * fVar1;
                    fVar2 = fVar2 + fVar1 * fVar5;
                    fStack_b8 = (float)param_1 - fVar3;
                    fStack_b4 = (float)param_2 - fVar4;
                    pGStack_b0 = (GmIso3 *)((float)param_3 - fVar2);
                    pSStack_c4 = (SCasterCat *)
                                 (fStack_b8 * fStack_b8 + fStack_b4 * fStack_b4 +
                                 (float)pGStack_b0 * (float)pGStack_b0);
                    if ((float)pSStack_c4 <= _DAT_00bbdc5c) goto LAB_008eaca1;
                    fVar24 = (float10)func_0x009c1b40();
                    fVar1 = 1.0 / (float)fVar24;
                    in_stack_ffffff28 = 0x8eabd0;
                    pfVar17 = (float *)(**(code **)*in_stack_00000010)();
                    pfVar17[3] = fVar1 * fStack_b8;
                    pfVar17[4] = fStack_b4 * fVar1;
                    pfVar17[5] = (float)pGStack_b0 * fVar1;
                    fStack_3c = ((float)fVar24 - *(float *)(iVar12 + 8)) * fVar1;
                    fStack_44 = fStack_3c * fStack_b8;
                    fStack_40 = fStack_b4 * fStack_3c;
                    fStack_3c = (float)pGStack_b0 * fStack_3c;
                    pSStack_c4 = (SCasterCat *)
                                 (fStack_3c * *(float *)(pSVar15 + 8) +
                                 fStack_40 * *(float *)(pSVar15 + 4) + *(float *)pSVar15 * fStack_44
                                 );
                    *pfVar17 = (float)pSStack_c4 * *(float *)pSVar15;
                    pfVar17[1] = (float)pSStack_c4 * *(float *)(pSVar15 + 4);
                    pfVar17[2] = (float)pSStack_c4 * *(float *)(pSVar15 + 8);
                    pfVar17[6] = fVar3;
                    pfVar17[7] = fVar4;
                    pfVar17[8] = fVar2;
                    uVar18 = *(undefined2 *)(iVar12 + 4);
                    pfVar17[10] = 0.0;
                    goto LAB_008ea76a;
                  }
                  fStack_b8 = (float)param_1 - *(float *)local_bc;
                  fStack_b4 = (float)param_2 - *(float *)(local_bc + 4);
                  pGStack_b0 = (GmIso3 *)((float)param_3 - *(float *)(local_bc + 8));
                  in_stack_ffffff28 = 0x8eaa07;
                  fVar24 = (float10)func_0x009c1b40();
                  pSStack_c4 = (SCasterCat *)(float)fVar24;
                  fVar1 = *(float *)(iVar12 + 8) * *(float *)(iVar12 + 8);
                  if (((float)pSStack_c4 < fVar1 == ((float)pSStack_c4 == fVar1)) ||
                     ((float)pSStack_c4 <= _DAT_00d1a938)) goto LAB_008eaca1;
                  fVar24 = (float10)func_0x009c1b40();
                  fVar1 = 1.0 / (float)fVar24;
                  in_stack_ffffff28 = 0x8eaa65;
                  pfVar17 = (float *)(**(code **)*in_stack_00000010)();
                  pfVar17[3] = fVar1 * fStack_b8;
                  pfVar17[4] = fStack_b4 * fVar1;
                  pfVar17[5] = (float)pGStack_b0 * fVar1;
                  fStack_24 = ((float)fVar24 - *(float *)(iVar12 + 8)) * fVar1;
                  fStack_2c = fStack_24 * fStack_b8;
                  fStack_28 = fStack_b4 * fStack_24;
                  fStack_24 = (float)pGStack_b0 * fStack_24;
                  pSStack_c4 = (SCasterCat *)
                               (fStack_24 * *(float *)(pSVar15 + 8) +
                               fStack_28 * *(float *)(pSVar15 + 4) + *(float *)pSVar15 * fStack_2c);
                  *pfVar17 = (float)pSStack_c4 * *(float *)pSVar15;
                  fVar1 = (float)pSStack_c4 * *(float *)(pSVar15 + 4);
                }
                else {
                  local_bc = apSStack_50[uStack_c0];
                  fStack_b8 = (float)param_1 - *(float *)local_bc;
                  fStack_b4 = (float)param_2 - *(float *)(local_bc + 4);
                  pGStack_b0 = (GmIso3 *)((float)param_3 - *(float *)(local_bc + 8));
                  pSStack_c4 = (SCasterCat *)
                               (fStack_b8 * fStack_b8 + fStack_b4 * fStack_b4 +
                               (float)pGStack_b0 * (float)pGStack_b0);
                  fVar1 = *(float *)(iVar12 + 8) * *(float *)(iVar12 + 8);
                  if (((float)pSStack_c4 < fVar1 == ((float)pSStack_c4 == fVar1)) ||
                     ((float)pSStack_c4 <= _DAT_00d1a938)) goto LAB_008eaca1;
                  fVar24 = (float10)func_0x009c1b40();
                  fVar1 = 1.0 / (float)fVar24;
                  in_stack_ffffff28 = 0x8ea882;
                  pfVar17 = (float *)(**(code **)*in_stack_00000010)();
                  pfVar17[3] = fVar1 * fStack_b8;
                  pfVar17[4] = fStack_b4 * fVar1;
                  pfVar17[5] = (float)pGStack_b0 * fVar1;
                  fStack_30 = ((float)fVar24 - *(float *)(iVar12 + 8)) * fVar1;
                  fStack_38 = fStack_30 * fStack_b8;
                  fStack_34 = fStack_b4 * fStack_30;
                  fStack_30 = (float)pGStack_b0 * fStack_30;
                  pSStack_c4 = (SCasterCat *)
                               (fStack_30 * *(float *)(pSVar15 + 8) +
                               fStack_34 * *(float *)(pSVar15 + 4) + *(float *)pSVar15 * fStack_38);
                  *pfVar17 = (float)pSStack_c4 * *(float *)pSVar15;
                  fVar1 = *(float *)(pSVar15 + 4) * (float)pSStack_c4;
                }
                pfVar17[1] = fVar1;
                pfVar17[2] = (float)pSStack_c4 * *(float *)(pSVar15 + 8);
                pfVar17[6] = *(float *)local_bc;
                pfVar17[7] = *(float *)(local_bc + 4);
                pfVar17[8] = *(float *)(local_bc + 8);
                uVar18 = *(undefined2 *)(iVar12 + 4);
                pfVar17[10] = 0.0;
                goto LAB_008ea76a;
              }
              uStack_c0 = uStack_c0 + 1;
            } while (uStack_c0 < 3);
            if (0.0 < fVar1) {
              in_stack_ffffff28 = 0x8ea712;
              pfVar17 = (float *)(**(code **)*in_stack_00000010)();
              pfVar17[3] = *(float *)pSVar15;
              pfVar17[4] = *(float *)(pSVar15 + 4);
              pfVar17[5] = *(float *)(pSVar15 + 8);
              pSStack_c4 = (SCasterCat *)(fVar1 - *(float *)(iVar12 + 8));
              *pfVar17 = (float)pSStack_c4 * *(float *)pSVar15;
              pfVar17[1] = (float)pSStack_c4 * *(float *)(pSVar15 + 4);
              pfVar17[2] = (float)pSStack_c4 * *(float *)(pSVar15 + 8);
              pfVar17[6] = fVar3;
              pfVar17[7] = fVar4;
              pfVar17[8] = fVar2;
              uVar18 = *(undefined2 *)(iVar12 + 4);
              pfVar17[10] = 1.4013e-45;
LAB_008ea76a:
              *(undefined2 *)(pfVar17 + 9) = uVar18;
              *(undefined2 *)((int)pfVar17 + 0x26) = uVar10;
              pfVar17[0xb] = *(float *)pSVar15;
              pfVar17[0xc] = *(float *)(pSVar15 + 4);
              pfVar17[0xd] = *(float *)(pSVar15 + 8);
            }
          }
        }
LAB_008eaca1:
        pCVar22 = pCVar22 + 1;
      }
    } while (pCVar22 < pCStack_ac);
    if (fStack_b4 != 0.0) {
      pGVar16 = (GmIso3 *)(**(code **)(*in_stack_00000010 + 8))();
      for (; pGStack_b0 < pGVar16; pGStack_b0 = pGStack_b0 + 1) {
        pGVar25 = pGStack_b0;
        pfVar17 = (float *)(**(code **)(*in_stack_00000010 + 4))();
        fVar1 = *(float *)(pGVar11 + 0x10);
        fVar2 = *(float *)(pGVar11 + 0xc);
        fVar3 = pfVar17[3];
        fVar4 = *(float *)(pGVar11 + 0x14);
        fVar5 = *(float *)(pGVar11 + 0x1c);
        fVar6 = pfVar17[4];
        fVar7 = pfVar17[3];
        fVar8 = *(float *)(pGVar11 + 0x18);
        fVar9 = *(float *)(pGVar11 + 0x20);
        pfVar17[3] = *(float *)(pGVar11 + 8) * pfVar17[5] +
                     pfVar17[4] * *(float *)(pGVar11 + 4) + *(float *)pGVar11 * pfVar17[3];
        pfVar17[4] = pfVar17[5] * fVar4 + fVar2 * fVar3 + pfVar17[4] * fVar1;
        pfVar17[5] = fVar9 * pfVar17[5] + fVar7 * fVar8 + fVar5 * fVar6;
        fStack_b4 = pfVar17[2] * *(float *)(pGVar11 + 0x14) +
                    pfVar17[1] * *(float *)(pGVar11 + 0x10) + *(float *)(pGVar11 + 0xc) * *pfVar17;
        fVar1 = *(float *)(pGVar11 + 0x1c);
        fVar2 = pfVar17[1];
        fVar3 = *(float *)(pGVar11 + 0x18);
        fVar4 = *pfVar17;
        fVar5 = *(float *)(pGVar11 + 0x20);
        *pfVar17 = *(float *)(pGVar11 + 8) * pfVar17[2] +
                   pfVar17[1] * *(float *)(pGVar11 + 4) + *(float *)pGVar11 * *pfVar17;
        pfVar17[1] = fStack_b4;
        pfVar17[2] = fVar5 * pfVar17[2] + fVar3 * fVar4 + fVar1 * fVar2;
        GmVec3::Mult(pfVar17 + 6,pGVar11,pGVar25);
      }
    }
  }
  return (int)fStack_b4;
}
// --- END GmCollision_Sphere_Mesh ---

// --- START GmCollision_Ellipsoid_Mesh ---
// Function: GmCollision_Ellipsoid_Mesh @ 008eadc0
// =================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
GmCollision_Ellipsoid_Mesh
          (LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3)

{
  GmIso4 *pGVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined2 uVar5;
  float fVar6;
  float fVar7;
  SCasterCat *pSVar8;
  SCasterCat *pSVar9;
  GmIso3 *pGVar10;
  float *pfVar11;
  GmIso3 *pGVar12;
  int iVar13;
  CPlugVolumeProjector *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  GmIso3 *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  float *pfVar15;
  void *this;
  uint uVar16;
  float10 fVar17;
  GmBoxAligned *in_stack_fffffdac;
  GmIso4 *in_stack_fffffdb0;
  GmScaleTrans2 *pGVar18;
  ulong in_stack_fffffdb8;
  GmIso3 *in_stack_fffffdbc;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffdc0;
  GmSurf *in_stack_fffffdc4;
  GmIso4 *in_stack_fffffdc8;
  GmVec3 *in_stack_fffffdd0;
  float fVar19;
  GmIso3 *pGVar20;
  float fVar21;
  GmIso3 *pGVar22;
  float fStack_220;
  float fStack_214;
  int iStack_20c;
  float fStack_1f4;
  int iStack_1e8;
  float fStack_1e0;
  float fStack_1dc;
  float fStack_1d8;
  float afStack_1c4 [4];
  float fStack_1b4;
  float fStack_1b0;
  float fStack_1ac;
  float fStack_1a8;
  float local_1a4;
  float local_1a0;
  GmIso3 *pGStack_19c;
  float fStack_198;
  float fStack_194;
  float fStack_190;
  float fStack_18c;
  float fStack_188;
  undefined2 auStack_184 [2];
  float fStack_180;
  undefined2 uStack_17c;
  float fStack_178;
  float fStack_174;
  GmIso3 *pGStack_170;
  float fStack_16c;
  float fStack_168;
  GmIso3 *pGStack_164;
  float fStack_160;
  float fStack_158;
  float fStack_154;
  float fStack_150;
  float fStack_14c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_148;
  float fStack_144;
  GmIso3 **ppGStack_140;
  float *pfStack_13c;
  float *pfStack_138;
  float fStack_134;
  float fStack_130;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  float fStack_118;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  undefined4 uStack_104;
  float fStack_100;
  float fStack_fc;
  double dStack_f8;
  float fStack_f0;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_80;
  float fStack_7c;
  float local_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float afStack_60 [12];
  undefined1 auStack_30 [4];
  float afStack_2c [4];
  GmIso3 aGStack_1c [8];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  void *pvStack_8;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00ade51b;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_1a4 = *(float *)param_2;
  local_1a0 = *(float *)(param_2 + 4);
  if (*(int *)(param_1 + 8) == 0) {
    GmIso4::SetIdentity(&local_78,(GmMat43 *)(DAT_00cca150 ^ (uint)&stack0xfffffda0));
  }
  else {
    pfVar11 = *(float **)(param_1 + 4);
    pfVar15 = &local_78;
    for (iVar13 = 0xc; iVar13 != 0; iVar13 = iVar13 + -1) {
      *pfVar15 = *pfVar11;
      pfVar11 = pfVar11 + 1;
      pfVar15 = pfVar15 + 1;
    }
  }
  if (*(int *)(param_2 + 8) != 0) {
    GmIso4::MultInverse(&fStack_74,pGStack_19c,unaff_EDI);
  }
  (**(code **)(*(int *)param_3 + 8))();
  pGVar18 = *(GmScaleTrans2 **)(iStack_20c + 0xc);
  dStack_f8 = *(double *)(iStack_20c + 8);
  fStack_220 = *(float *)(iStack_20c + 0x10);
  fStack_fc = 0.0;
  fStack_100 = 0.0;
  uStack_104 = 0;
  fStack_f0 = fStack_220;
  GmBoxAligned::Mult(&uStack_104,(GmIso3 *)&fStack_74,unaff_EDI);
  pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pCStack_148 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CFastBuffer<class_CCrystalFace*>::GetCount(pGStack_19c + 0x20,unaff_ESI);
  if (pCStack_148 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    ExceptionList = pvStack_8;
    return 0;
  }
  do {
    pSVar8 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                       ((void *)((int)fStack_198 + 0x20),pCVar14,(ulong)unaff_EBX);
    unaff_EBX = (CPlugVolumeProjector *)(pSVar8 + 4);
    iVar13 = GmBoxAligned::TestInter(&dStack_f8,unaff_EBX,in_stack_fffffdac,in_stack_fffffdb0);
    if (iVar13 == 0) {
      pCVar14 = pCVar14 + *(int *)pSVar8;
    }
    else {
      if (*(int *)(pSVar8 + 0x1c) != -1) {
        in_stack_fffffdac = (GmBoxAligned *)0x8eaf38;
        GmIso4::SetInverse(auStack_30,(GmScaleTrans2 *)afStack_60,pGVar18);
        pCVar14 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar8 + 0x1c);
        pfVar11 = afStack_2c;
        pfVar15 = afStack_1c4;
        for (iVar13 = 0xc; fVar2 = fStack_188, iVar13 != 0; iVar13 = iVar13 + -1) {
          *pfVar15 = *pfVar11;
          pfVar11 = pfVar11 + 1;
          pfVar15 = pfVar15 + 1;
        }
        fVar3 = 1.0 / *(float *)((int)fStack_1f4 + 8);
        afStack_1c4[0] = fVar3 * afStack_2c[0];
        afStack_1c4[1] = afStack_1c4[1] * fVar3;
        afStack_1c4[2] = fVar3 * afStack_1c4[2];
        fVar19 = 1.0 / *(float *)((int)fStack_1f4 + 0xc);
        afStack_1c4[3] = fVar19 * afStack_1c4[3];
        fStack_1b4 = fStack_1b4 * fVar19;
        fStack_1b0 = fVar19 * fStack_1b0;
        pGVar12 = (GmIso3 *)(1.0 / *(float *)((int)fStack_1f4 + 0x10));
        fStack_1ac = (float)pGVar12 * fStack_1ac;
        fStack_1a8 = fStack_1a8 * (float)pGVar12;
        local_1a4 = (float)pGVar12 * local_1a4;
        local_1a0 = local_1a0 * fVar3;
        pGStack_19c = (GmIso3 *)((float)pGStack_19c * fVar19);
        fStack_198 = (float)pGVar12 * fStack_198;
        in_stack_fffffdb0 = (GmIso4 *)0x8eb061;
        pSVar8 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                           ((void *)((int)fStack_188 + 0x10),pCVar14,in_stack_fffffdb8);
        this = (void *)((int)fVar2 + 8);
        pGVar18 = (GmScaleTrans2 *)0x8eb071;
        pSVar9 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar8 + 0x10)
                            ,(ulong)in_stack_fffffdbc);
        fStack_178 = fStack_1b4 * *(float *)(pSVar9 + 8) +
                     afStack_1c4[2] * *(float *)pSVar9 + afStack_1c4[3] * *(float *)(pSVar9 + 4) +
                     fStack_198;
        fStack_174 = fStack_1a8 * *(float *)(pSVar9 + 8) +
                     fStack_1b0 * *(float *)pSVar9 + fStack_1ac * *(float *)(pSVar9 + 4) +
                     fStack_194;
        pGStack_170 = (GmIso3 *)
                      ((float)pGStack_19c * *(float *)(pSVar9 + 8) +
                       local_1a4 * *(float *)pSVar9 + local_1a0 * *(float *)(pSVar9 + 4) +
                      fStack_190);
        in_stack_fffffdb8 = 0x8eb109;
        pSVar9 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar8 + 0x14)
                            ,(ulong)in_stack_fffffdc0);
        fStack_150 = fStack_1b0 * *(float *)(pSVar9 + 8) +
                     *(float *)pSVar9 * afStack_1c4[3] + fStack_1b4 * *(float *)(pSVar9 + 4) +
                     fStack_194;
        fStack_14c = local_1a4 * *(float *)(pSVar9 + 8) +
                     fStack_1ac * *(float *)pSVar9 + fStack_1a8 * *(float *)(pSVar9 + 4) +
                     fStack_190;
        pCStack_148 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                      (fStack_198 * *(float *)(pSVar9 + 8) +
                       local_1a0 * *(float *)pSVar9 + (float)pGStack_19c * *(float *)(pSVar9 + 4) +
                      fStack_18c);
        in_stack_fffffdc0 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar8 + 0x18);
        in_stack_fffffdbc = (GmIso3 *)0x8eb1a1;
        pSVar9 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this,in_stack_fffffdc0,(ulong)in_stack_fffffdc4);
        fStack_158 = fStack_1ac * *(float *)(pSVar9 + 8) +
                     fStack_1b4 * *(float *)pSVar9 + fStack_1b0 * *(float *)(pSVar9 + 4) +
                     fStack_190;
        pfStack_13c = &fStack_14c;
        pfStack_138 = &fStack_158;
        fStack_154 = local_1a0 * *(float *)(pSVar9 + 8) +
                     fStack_1a8 * *(float *)pSVar9 + local_1a4 * *(float *)(pSVar9 + 4) + fStack_18c
        ;
        ppGStack_140 = &pGStack_170;
        fStack_150 = fStack_194 * *(float *)(pSVar9 + 8) +
                     (float)pGStack_19c * *(float *)pSVar9 + fStack_198 * *(float *)(pSVar9 + 4) +
                     fStack_188;
        fStack_118 = fStack_14c - (float)pGStack_170;
        fStack_114 = (float)pCStack_148 - fStack_16c;
        fStack_110 = fStack_144 - fStack_168;
        fStack_100 = fStack_158 - (float)pGStack_170;
        fStack_fc = fStack_154 - fStack_16c;
        fVar2 = fStack_150 - fStack_168;
        dStack_f8 = (double)CONCAT44(dStack_f8._4_4_,fVar2);
        fVar3 = fStack_114 * fVar2 - fStack_110 * fStack_fc;
        fVar2 = fStack_100 * fStack_110 - fStack_118 * fVar2;
        fStack_214 = fStack_fc * fStack_118 - fStack_114 * fStack_100;
        if (_DAT_00d1a938 < fStack_214 * fStack_214 + fVar3 * fVar3 + fVar2 * fVar2) {
          fVar17 = (float10)func_0x009c1b40();
          fVar3 = (1.0 / (float)fVar17) * fVar3;
          fVar2 = fVar2 * (1.0 / (float)fVar17);
          in_stack_fffffdc4 = (GmSurf *)0x8eb3ad;
          GmSurfSphere::GmSurfSphere((GmSurfSphere *)auStack_184,(GmSurfSphere *)in_stack_fffffdc8);
          fStack_178 = 1.0;
          uStack_17c = *(undefined2 *)((int)fStack_1e0 + 4);
          uVar16 = 0;
          in_stack_fffffdc8 = (GmIso4 *)0x8eb3d8;
          pGVar10 = (GmIso3 *)(**(code **)(*(int *)param_3 + 8))();
          uVar5 = *(undefined2 *)(pSVar8 + 0x1c);
          fStack_214 = 0.0 - fStack_174;
          afStack_1c4[2] =
               (0.0 - fStack_16c) * fVar2 +
               (0.0 - (float)pGStack_170) * fVar3 + fStack_214 * fStack_220;
          if ((afStack_1c4[2] <= fStack_180) && (0.0 <= afStack_1c4[2])) {
            dStack_f8 = (double)(fStack_180 * fStack_180);
            fVar17 = (float10)func_0x009c1b40();
            fVar19 = (float)fVar17;
            fVar4 = -afStack_1c4[2];
            fStack_1f4 = fStack_220 * fVar4 + 0.0;
            fVar21 = fVar3 * fVar4 + 0.0;
            fVar4 = fVar2 * fVar4 + 0.0;
            do {
              if (uVar16 == 2) {
                pGVar22 = (GmIso3 *)0x0;
              }
              else {
                pGVar22 = (GmIso3 *)(uVar16 + 1);
              }
              pfVar11 = (float *)(&fStack_144)[(int)pGVar22];
              pfVar15 = (float *)(&fStack_144)[uVar16];
              fStack_1e0 = *pfVar11 - *pfVar15;
              fStack_1dc = pfVar11[1] - pfVar15[1];
              fStack_1d8 = pfVar11[2] - pfVar15[2];
              if (_DAT_00d1a938 <
                  fStack_1d8 * fStack_1d8 + fStack_1e0 * fStack_1e0 + fStack_1dc * fStack_1dc) {
                fVar17 = (float10)func_0x009c1b40();
                fVar6 = 1.0 / (float)fVar17;
                fStack_1e0 = fVar6 * fStack_1e0;
                fStack_1dc = fStack_1dc * fVar6;
                fStack_1d8 = fVar6 * fStack_1d8;
              }
              fStack_168 = fStack_1dc * fVar2 - fStack_1d8 * fVar3;
              pGStack_164 = (GmIso3 *)(fStack_1d8 * fStack_220 - fVar2 * fStack_1e0);
              fStack_160 = fVar3 * fStack_1e0 - fStack_1dc * fStack_220;
              fVar6 = (fVar4 - pfVar15[2]) * fStack_160 +
                      (fStack_1f4 - *pfVar15) * fStack_168 +
                      (fVar21 - pfVar15[1]) * (float)pGStack_164;
              if (fVar19 < fVar6) goto LAB_008ebf34;
              if (0.0 < fVar6) {
                if ((fVar4 - pfVar15[2]) * fStack_1d8 +
                    (fStack_1f4 - *pfVar15) * fStack_1e0 + (fVar21 - pfVar15[1]) * fStack_1dc <
                    _DAT_00c418e0) {
                  fStack_214 = 0.0 - *pfVar15;
                  fVar19 = 0.0 - pfVar15[1];
                  fVar4 = 0.0 - pfVar15[2];
                  fVar21 = fVar19 * fVar19 + fStack_214 * fStack_214 + fVar4 * fVar4;
                  if ((fVar21 < (float)dStack_f8 == (fVar21 == (float)dStack_f8)) ||
                     (fVar21 <= _DAT_00d1a938)) goto LAB_008ebf34;
                  fVar17 = (float10)func_0x009c1b40();
                  pGVar22 = (GmIso3 *)(float)fVar17;
                  fVar21 = 1.0 / (float)pGVar22;
                  pfVar11 = (float *)(*(code *)**(undefined4 **)param_3)();
                  pfVar11[3] = fVar21 * fStack_214;
                  pfVar11[4] = fVar19 * fVar21;
                  pfVar11[5] = fVar4 * fVar21;
                  fStack_130 = ((float)pGVar22 - fStack_180) * fVar21;
                  pfStack_138 = (float *)(fStack_130 * fStack_214);
                  fStack_134 = fVar19 * fStack_130;
                  fStack_130 = fVar4 * fStack_130;
                  pGVar20 = (GmIso3 *)
                            (fStack_220 * (float)pfStack_138 + fVar3 * fStack_134 +
                            fVar2 * fStack_130);
                  *pfVar11 = (float)pGVar20 * fStack_220;
                  pfVar11[1] = fVar3 * (float)pGVar20;
                  pfVar11[2] = (float)pGVar20 * fVar2;
                  pfVar11[6] = *pfVar15;
                  pfVar11[7] = pfVar15[1];
                  pfVar11[8] = pfVar15[2];
                  *(undefined2 *)(pfVar11 + 9) = auStack_184[0];
                  *(undefined2 *)((int)pfVar11 + 0x26) = uVar5;
                  pfVar11[10] = 0.0;
                  pfVar11[0xb] = fStack_220;
                }
                else {
                  pfVar15 = (float *)(&fStack_144)[(int)pGVar22];
                  if ((fVar21 - pfVar15[1]) * fStack_1dc + (fStack_1f4 - *pfVar15) * fStack_1e0 +
                      (fVar4 - pfVar15[2]) * fStack_1d8 <= _DAT_00c418e0) {
                    fVar6 = -fVar6;
                    fVar7 = fVar6 * fStack_168 + fStack_1f4;
                    afStack_1c4[0] = (float)pGStack_164 * fVar6 + fVar21;
                    afStack_1c4[1] = fVar4 + fVar6 * fStack_160;
                    fStack_214 = 0.0 - fVar7;
                    fVar19 = 0.0 - afStack_1c4[0];
                    fVar4 = 0.0 - afStack_1c4[1];
                    if (fVar19 * fVar19 + fStack_214 * fStack_214 + fVar4 * fVar4 <= _DAT_00bbdc5c)
                    goto LAB_008ebf34;
                    fVar17 = (float10)func_0x009c1b40();
                    pGVar22 = (GmIso3 *)(float)fVar17;
                    fVar21 = 1.0 / (float)pGVar22;
                    pfVar11 = (float *)(*(code *)**(undefined4 **)param_3)();
                    pfVar11[3] = fVar21 * fStack_214;
                    pfVar11[4] = fVar19 * fVar21;
                    pfVar11[5] = fVar4 * fVar21;
                    fStack_108 = ((float)pGVar22 - fStack_180) * fVar21;
                    fStack_110 = fStack_108 * fStack_214;
                    fStack_10c = fVar19 * fStack_108;
                    fStack_108 = fVar4 * fStack_108;
                    pGVar20 = (GmIso3 *)
                              (fVar3 * fStack_10c + fStack_220 * fStack_110 + fVar2 * fStack_108);
                    *pfVar11 = (float)pGVar20 * fStack_220;
                    pfVar11[1] = fVar3 * (float)pGVar20;
                    pfVar11[2] = (float)pGVar20 * fVar2;
                    pfVar11[6] = fVar7;
                    pfVar11[7] = afStack_1c4[0];
                    pfVar11[8] = afStack_1c4[1];
                    pfVar11[10] = 0.0;
                    goto LAB_008eb706;
                  }
                  fStack_214 = 0.0 - *pfVar15;
                  fVar19 = pfVar15[1];
                  fVar4 = pfVar15[2];
                  fVar17 = (float10)func_0x009c1b40();
                  fVar21 = (float)fVar17;
                  if ((fVar21 < (float)dStack_f8 == (fVar21 == (float)dStack_f8)) ||
                     (fVar21 <= _DAT_00d1a938)) goto LAB_008ebf34;
                  fVar17 = (float10)func_0x009c1b40();
                  pGVar22 = (GmIso3 *)(float)fVar17;
                  fVar21 = 1.0 / (float)pGVar22;
                  pfVar11 = (float *)(*(code *)**(undefined4 **)param_3)();
                  pfVar11[3] = fVar21 * fStack_214;
                  pfVar11[4] = (0.0 - fVar19) * fVar21;
                  pfVar11[5] = (0.0 - fVar4) * fVar21;
                  fStack_120 = ((float)pGVar22 - fStack_180) * fVar21;
                  fStack_128 = fStack_120 * fStack_214;
                  fStack_124 = (0.0 - fVar19) * fStack_120;
                  fStack_120 = (0.0 - fVar4) * fStack_120;
                  pGVar20 = (GmIso3 *)
                            (fStack_220 * fStack_128 + fVar3 * fStack_124 + fVar2 * fStack_120);
                  *pfVar11 = (float)pGVar20 * fStack_220;
                  pfVar11[1] = fVar3 * (float)pGVar20;
                  pfVar11[2] = (float)pGVar20 * fVar2;
                  pfVar11[6] = *pfVar15;
                  pfVar11[7] = pfVar15[1];
                  pfVar11[8] = pfVar15[2];
                  *(undefined2 *)(pfVar11 + 9) = auStack_184[0];
                  *(undefined2 *)((int)pfVar11 + 0x26) = uVar5;
                  pfVar11[10] = 0.0;
                  pfVar11[0xb] = fStack_220;
                }
                goto LAB_008eb718;
              }
              uVar16 = uVar16 + 1;
            } while (uVar16 < 3);
            if (0.0 < afStack_1c4[2]) {
              pfVar11 = (float *)(*(code *)**(undefined4 **)param_3)();
              pfVar11[3] = fStack_220;
              pfVar11[4] = fVar3;
              pfVar11[5] = fVar2;
              pGVar20 = (GmIso3 *)(afStack_1c4[2] - fStack_180);
              *pfVar11 = (float)pGVar20 * fStack_220;
              pfVar11[1] = fVar3 * (float)pGVar20;
              pfVar11[2] = (float)pGVar20 * fVar2;
              pfVar11[6] = fStack_1f4;
              pfVar11[7] = fVar21;
              pfVar11[8] = fVar4;
              pfVar11[10] = 1.4013e-45;
LAB_008eb706:
              *(undefined2 *)(pfVar11 + 9) = auStack_184[0];
              *(undefined2 *)((int)pfVar11 + 0x26) = uVar5;
              pfVar11[0xb] = fStack_220;
LAB_008eb718:
              pfVar11[0xc] = fVar3;
              pGVar1 = (GmIso4 *)(iStack_1e8 + 8);
              pfVar11[0xd] = fVar2;
              fStack_bc = 0.0;
              fStack_b8 = 0.0;
              fStack_b4 = 0.0;
              in_stack_fffffdb8 = 0x8eb751;
              in_stack_fffffdbc = (GmIso3 *)pGVar1;
              GmIso4::SetNUScaleTrans
                        (&fStack_b0,pGVar1,(GmVec3 *)&fStack_bc,(GmVec3 *)in_stack_fffffdc4);
              GmIso4::MultInverse(&fStack_ac,aGStack_1c,(GmIso3 *)in_stack_fffffdc8);
              GmIso4::Mult(&fStack_a8,pGStack_170,pGVar12);
              uStack_e0 = 0;
              uStack_dc = 0;
              uStack_d8 = 0;
              in_stack_fffffdc8 = (GmIso4 *)&fStack_bc;
              fStack_220 = 1.0 / *(float *)pGVar1;
              fStack_b8 = 1.0 / *(float *)(iStack_1e8 + 0xc);
              fStack_b4 = 1.0 / *(float *)(iStack_1e8 + 0x10);
              in_stack_fffffdc4 = (GmSurf *)0x8eb7eb;
              fStack_bc = fStack_220;
              GmIso4::SetNUScaleTrans
                        (&fStack_74,in_stack_fffffdc8,(GmVec3 *)&uStack_e0,in_stack_fffffdd0);
              GmIso4::MultInverse(&fStack_70,(GmIso3 *)&puStack_10,pGVar20);
              in_stack_fffffdd0 = (GmVec3 *)0x8eb813;
              GmIso4::Mult(&fStack_6c,pGStack_164,pGVar22);
              pGVar12 = (GmIso3 *)(**(code **)(*(int *)param_3 + 8))();
              for (; pGVar10 < pGVar12; pGVar10 = pGVar10 + 1) {
                pGVar22 = pGVar10;
                pfVar11 = (float *)(**(code **)(*(int *)param_3 + 4))();
                in_stack_fffffdbc = (GmIso3 *)&fStack_b4;
                in_stack_fffffdb8 = 0x8eb84c;
                GmVec3::Mult(pfVar11 + 6,in_stack_fffffdbc,pGVar22);
                fVar2 = pfVar11[3];
                fVar3 = pfVar11[3];
                fVar19 = pfVar11[4];
                pfVar11[3] = local_78 * pfVar11[5] + fStack_7c * pfVar11[4] + fStack_80 * pfVar11[3]
                ;
                pfVar11[4] = fStack_6c * pfVar11[5] + fStack_70 * pfVar11[4] + fStack_74 * fVar2;
                pfVar11[5] = afStack_60[0] * pfVar11[5] + fStack_64 * fVar19 + fStack_68 * fVar3;
                if (_DAT_00d1a938 <
                    pfVar11[5] * pfVar11[5] + pfVar11[3] * pfVar11[3] + pfVar11[4] * pfVar11[4]) {
                  fVar17 = (float10)func_0x009c1b40();
                  fVar2 = 1.0 / (float)fVar17;
                  pfVar11[3] = fVar2 * pfVar11[3];
                  pfVar11[4] = fVar2 * pfVar11[4];
                  pfVar11[5] = fVar2 * pfVar11[5];
                }
                fVar2 = *pfVar11;
                fVar3 = *pfVar11;
                fVar19 = pfVar11[1];
                *pfVar11 = fStack_a8 * pfVar11[2] + fStack_ac * pfVar11[1] + *pfVar11 * fStack_b0;
                pfVar11[1] = fStack_9c * pfVar11[2] + fStack_a0 * pfVar11[1] + fStack_a4 * fVar2;
                pfVar11[2] = fStack_90 * pfVar11[2] + fStack_94 * fVar19 + fStack_98 * fVar3;
              }
              in_stack_fffffdc0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x8ebf1e;
              GmSurf::~GmSurf((GmSurf *)&fStack_188,in_stack_fffffdc4);
              fStack_1f4 = 1.4013e-45;
              goto LAB_008ebf4f;
            }
          }
LAB_008ebf34:
          in_stack_fffffdc0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x8ebf4b;
          GmSurf::~GmSurf((GmSurf *)&fStack_188,in_stack_fffffdc4);
        }
      }
LAB_008ebf4f:
      pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)fStack_1e0 + 1);
    }
    if (pCStack_148 <= pCVar14) {
      ExceptionList = pvStack_8;
      return (int)fStack_214;
    }
  } while( true );
}
// --- END GmCollision_Ellipsoid_Mesh ---

// --- START GmCollision_Mesh_Mesh ---
// Function: GmCollision_Mesh_Mesh @ 008f1b30
// =================================================

int __cdecl
GmCollision_Mesh_Mesh(LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3)

{
  GmIso3 *pGVar1;
  float *pfVar2;
  int iVar3;
  ulong unaff_ESI;
  undefined4 *puVar4;
  GmIso3 *unaff_EDI;
  undefined4 *puVar5;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80 [13];
  float local_4c [8];
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_18;
  int local_10;
  int local_c;
  CGmCollisionBuffer *local_8;
  GmIso3 *local_4;
  
  local_10 = *(int *)param_1;
  pGVar1 = *(GmIso3 **)(param_1 + 4);
  local_8c = *(undefined4 *)(local_10 + 0x20);
  local_c = *(int *)param_2;
  local_88 = *(undefined4 *)(local_c + 0x24);
  local_84 = *(undefined4 *)(local_c + 0x20);
  local_8 = param_3;
  local_2c = 0;
  local_28 = 1;
  local_24 = 0;
  local_20 = 0xffffffff;
  local_18 = 0xffffffff;
  puVar4 = *(undefined4 **)(param_2 + 4);
  puVar5 = local_80;
  local_4 = pGVar1;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  GmIso4::MultInverse(local_80,pGVar1,unaff_EDI);
  local_24 = 1;
  iVar3 = 3;
  pfVar2 = local_4c;
  do {
    iVar3 = iVar3 + -1;
    *pfVar2 = ABS(pfVar2[-0xc]);
    pfVar2[1] = ABS(pfVar2[-0xb]);
    pfVar2[2] = ABS(pfVar2[-10]);
    pfVar2 = pfVar2 + 3;
  } while (iVar3 != 0);
  SMeshMeshCollide::TreeTree(&local_8c,(SMeshMeshCollide *)0x0,0,unaff_ESI);
  return local_24;
}
// --- END GmCollision_Mesh_Mesh ---

// --- START GmCollision_Sphere_Sphere ---
// Function: GmCollision_Sphere_Sphere @ 008f49d0
// =================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
GmCollision_Sphere_Sphere(LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float *pfVar10;
  float10 fVar11;
  
  iVar4 = *(int *)(param_1 + 4);
  iVar5 = *(int *)param_1;
  iVar6 = *(int *)(param_2 + 4);
  fVar3 = *(float *)(iVar6 + 0x24) - *(float *)(iVar4 + 0x24);
  iVar7 = *(int *)param_2;
  fVar8 = *(float *)(iVar6 + 0x28) - *(float *)(iVar4 + 0x28);
  fVar2 = *(float *)(iVar6 + 0x2c) - *(float *)(iVar4 + 0x2c);
  fVar1 = *(float *)(iVar7 + 8) + *(float *)(iVar5 + 8);
  if (fVar2 * fVar2 + fVar3 * fVar3 + fVar8 * fVar8 < fVar1 * fVar1) {
    fVar11 = (float10)func_0x009c1b40();
    fVar1 = (float)fVar11;
    if (fVar1 <= _DAT_00bbe3f8) {
      pfVar10 = (float *)(*(code *)**(undefined4 **)param_3)();
      pfVar10[3] = 0.0;
      pfVar10[4] = _DAT_00b2c060;
      pfVar10[5] = 0.0;
      fVar3 = *(float *)(iVar7 + 8);
      fVar8 = (float)_PTR_00b2c178 * fVar3;
      *pfVar10 = fVar8;
      pfVar10[2] = fVar8;
      pfVar10[1] = fVar3;
      pfVar10[6] = *(float *)(iVar4 + 0x24);
      pfVar10[7] = *(float *)(iVar4 + 0x28);
      fVar3 = *(float *)(iVar4 + 0x2c);
    }
    else {
      pfVar10 = (float *)(*(code *)**(undefined4 **)param_3)();
      fVar9 = 1.0 / fVar1;
      fVar3 = fVar9 * fVar3;
      fVar8 = fVar8 * fVar9;
      fVar9 = fVar9 * fVar2;
      pfVar10[3] = -fVar3;
      pfVar10[4] = -fVar8;
      pfVar10[5] = -fVar9;
      fVar1 = (*(float *)(iVar7 + 8) + *(float *)(iVar5 + 8)) - fVar1;
      *pfVar10 = fVar1 * fVar3;
      pfVar10[1] = fVar8 * fVar1;
      pfVar10[2] = fVar1 * fVar9;
      fVar2 = *(float *)(iVar5 + 8);
      pfVar10[6] = fVar2 * fVar3;
      pfVar10[7] = fVar8 * fVar2;
      pfVar10[8] = fVar2 * fVar9;
      pfVar10[6] = *(float *)(iVar4 + 0x24) + pfVar10[6];
      pfVar10[7] = *(float *)(iVar4 + 0x28) + pfVar10[7];
      fVar3 = *(float *)(iVar4 + 0x2c) + pfVar10[8];
    }
    pfVar10[8] = fVar3;
    *(undefined2 *)(pfVar10 + 9) = *(undefined2 *)(iVar5 + 4);
    *(undefined2 *)((int)pfVar10 + 0x26) = *(undefined2 *)(iVar7 + 4);
    return 1;
  }
  return 0;
}
// --- END GmCollision_Sphere_Sphere ---

// --- START GmCollision_Box_Box ---
// Function: GmCollision_Box_Box @ 008f4bc0
// =================================================

int __cdecl
GmCollision_Box_Box(LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3)

{
  int iVar1;
  int iVar2;
  GmIso3 *pGVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  float *pfVar11;
  GmIso3 *unaff_EDI;
  float *pfVar12;
  float unaff_retaddr;
  undefined4 *in_stack_00000010;
  float local_50 [6];
  float local_38;
  float local_34;
  float local_30 [7];
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = *(int *)param_2;
  iVar2 = *(int *)param_1;
  pGVar3 = *(GmIso3 **)(param_1 + 4);
  pfVar11 = *(float **)(param_2 + 4);
  pfVar12 = local_30;
  for (iVar10 = 0xc; iVar10 != 0; iVar10 = iVar10 + -1) {
    *pfVar12 = *pfVar11;
    pfVar11 = pfVar11 + 1;
    pfVar12 = pfVar12 + 1;
  }
  GmIso4::MultInverse(local_30,pGVar3,unaff_EDI);
  uVar7 = 0;
  do {
    uVar8 = uVar7 + 0xc;
    *(float *)((int)local_50 + uVar7) = ABS(*(float *)((int)local_30 + uVar7 + 4));
    *(float *)((int)local_50 + uVar7 + 4) = ABS(*(float *)((int)local_30 + uVar7 + 8));
    *(float *)((int)local_50 + uVar7 + 8) = ABS(*(float *)((int)local_30 + uVar7 + 0xc));
    uVar7 = uVar8;
  } while (uVar8 < 0x24);
  fVar4 = (local_30[3] * *(float *)(iVar1 + 0x10) +
           local_30[1] * *(float *)(iVar1 + 8) + local_30[2] * *(float *)(iVar1 + 0xc) + local_8) -
          *(float *)(iVar2 + 8);
  if (((((ABS(fVar4) <=
          local_50[2] * *(float *)(iVar1 + 0x1c) +
          local_50[1] * *(float *)(iVar1 + 0x18) +
          local_50[0] * *(float *)(iVar1 + 0x14) + *(float *)(iVar2 + 0x14)) &&
        (fVar5 = (local_30[6] * *(float *)(iVar1 + 0x10) +
                  local_30[4] * *(float *)(iVar1 + 8) + local_30[5] * *(float *)(iVar1 + 0xc) +
                 local_4) - *(float *)(iVar2 + 0xc),
        ABS(fVar5) <=
        local_50[5] * *(float *)(iVar1 + 0x1c) +
        local_50[4] * *(float *)(iVar1 + 0x18) +
        local_50[3] * *(float *)(iVar1 + 0x14) + *(float *)(iVar2 + 0x18))) &&
       (fVar6 = (local_c * *(float *)(iVar1 + 0x10) +
                 local_14 * *(float *)(iVar1 + 8) + local_10 * *(float *)(iVar1 + 0xc) +
                unaff_retaddr) - *(float *)(iVar2 + 0x10),
       ABS(fVar6) <=
       local_30[0] * *(float *)(iVar1 + 0x1c) +
       local_34 * *(float *)(iVar1 + 0x18) +
       local_38 * *(float *)(iVar1 + 0x14) + *(float *)(iVar2 + 0x1c))) &&
      (((ABS(local_14 * fVar6 + local_30[1] * fVar4 + local_30[4] * fVar5) <=
         local_38 * *(float *)(iVar2 + 0x1c) +
         *(float *)(iVar2 + 0x18) * local_50[3] + local_50[0] * *(float *)(iVar2 + 0x14) +
         *(float *)(iVar1 + 0x14) &&
        (ABS(local_10 * fVar6 + local_30[2] * fVar4 + local_30[5] * fVar5) <=
         local_34 * *(float *)(iVar2 + 0x1c) +
         *(float *)(iVar2 + 0x18) * local_50[4] + local_50[1] * *(float *)(iVar2 + 0x14) +
         *(float *)(iVar1 + 0x18))) &&
       ((ABS(local_c * fVar6 + local_30[3] * fVar4 + local_30[6] * fVar5) <=
         local_30[0] * *(float *)(iVar2 + 0x1c) +
         *(float *)(iVar2 + 0x18) * local_50[5] + local_50[2] * *(float *)(iVar2 + 0x14) +
         *(float *)(iVar1 + 0x1c) &&
        ((ABS(local_30[4] * fVar6 - local_14 * fVar5) <=
          local_50[1] * *(float *)(iVar1 + 0x1c) +
          local_50[2] * *(float *)(iVar1 + 0x18) +
          *(float *)(iVar2 + 0x18) * local_38 + local_50[3] * *(float *)(iVar2 + 0x1c) &&
         (ABS(local_30[5] * fVar6 - local_10 * fVar5) <=
          local_50[0] * *(float *)(iVar1 + 0x1c) +
          local_50[2] * *(float *)(iVar1 + 0x14) +
          *(float *)(iVar2 + 0x18) * local_34 + local_50[4] * *(float *)(iVar2 + 0x1c))))))))) &&
     ((ABS(local_30[6] * fVar6 - local_c * fVar5) <=
       local_50[0] * *(float *)(iVar1 + 0x18) +
       local_50[1] * *(float *)(iVar1 + 0x14) +
       *(float *)(iVar2 + 0x18) * local_30[0] + local_50[5] * *(float *)(iVar2 + 0x1c) &&
      (((((ABS(local_14 * fVar4 - local_30[1] * fVar6) <=
           local_50[4] * *(float *)(iVar1 + 0x1c) +
           local_50[5] * *(float *)(iVar1 + 0x18) +
           local_50[0] * *(float *)(iVar2 + 0x1c) + local_38 * *(float *)(iVar2 + 0x14) &&
          (ABS(local_10 * fVar4 - local_30[2] * fVar6) <=
           local_50[3] * *(float *)(iVar1 + 0x1c) +
           local_50[5] * *(float *)(iVar1 + 0x14) +
           local_50[1] * *(float *)(iVar2 + 0x1c) + local_34 * *(float *)(iVar2 + 0x14))) &&
         (ABS(local_c * fVar4 - local_30[3] * fVar6) <=
          local_50[3] * *(float *)(iVar1 + 0x18) +
          local_50[4] * *(float *)(iVar1 + 0x14) +
          local_50[2] * *(float *)(iVar2 + 0x1c) + local_30[0] * *(float *)(iVar2 + 0x14))) &&
        ((ABS(local_30[1] * fVar5 - local_30[4] * fVar4) <=
          local_34 * *(float *)(iVar1 + 0x1c) +
          local_30[0] * *(float *)(iVar1 + 0x18) +
          *(float *)(iVar2 + 0x18) * local_50[0] + *(float *)(iVar2 + 0x14) * local_50[3] &&
         (ABS(local_30[2] * fVar5 - local_30[5] * fVar4) <=
          local_38 * *(float *)(iVar1 + 0x1c) +
          *(float *)(iVar2 + 0x18) * local_50[1] + local_50[4] * *(float *)(iVar2 + 0x14) +
          *(float *)(iVar1 + 0x14) * local_30[0])))) &&
       (ABS(local_30[3] * fVar5 - local_30[6] * fVar4) <=
        *(float *)(iVar2 + 0x18) * local_50[2] + local_50[5] * *(float *)(iVar2 + 0x14) +
        *(float *)(iVar1 + 0x14) * local_34 + *(float *)(iVar1 + 0x18) * local_38)))))) {
    puVar9 = (undefined4 *)(**(code **)*in_stack_00000010)();
    puVar9[6] = *(undefined4 *)(param_3 + 0x24);
    puVar9[7] = *(undefined4 *)(param_3 + 0x28);
    puVar9[8] = *(undefined4 *)(param_3 + 0x2c);
    puVar9[2] = 0;
    puVar9[1] = 0;
    *puVar9 = 0;
    puVar9[3] = 0x3f800000;
    puVar9[4] = 0;
    puVar9[5] = 0;
    *(undefined2 *)(puVar9 + 9) = *(undefined2 *)(iVar2 + 4);
    *(undefined2 *)((int)puVar9 + 0x26) = *(undefined2 *)(iVar1 + 4);
    return 1;
  }
  return 0;
}
// --- END GmCollision_Box_Box ---

// --- START GmCollision_Box_Mesh ---
// Function: GmCollision_Box_Mesh @ 008f5200
// =================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
GmCollision_Box_Mesh(LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3)

{
  float fVar1;
  int iVar2;
  GmIso3 *pGVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  SCasterCat *pSVar14;
  SCasterCat *pSVar15;
  undefined4 *puVar16;
  int iVar17;
  uint uVar18;
  CPlugVolumeProjector *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  GmIso3 *unaff_ESI;
  float *pfVar19;
  GmMat43 *unaff_EDI;
  float *pfVar20;
  void *this;
  int *in_stack_00000010;
  float in_stack_00000014;
  float in_stack_00000018;
  float in_stack_0000001c;
  float in_stack_00000020;
  float in_stack_00000024;
  float in_stack_00000028;
  float in_stack_0000002c;
  undefined4 *in_stack_00000040;
  GmBoxAligned *in_stack_ffffff04;
  GmIso4 *in_stack_ffffff08;
  ulong in_stack_ffffff0c;
  ulong in_stack_ffffff10;
  GmMat3 *in_stack_ffffff14;
  ulong in_stack_ffffff18;
  GmMat3 *in_stack_ffffff1c;
  undefined1 *in_stack_ffffff20;
  GmMat3 *pGVar21;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff28;
  GmIso4 *in_stack_ffffff2c;
  float fStack_c8;
  float fStack_c4;
  float fStack_a8;
  float afStack_88 [4];
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined4 uStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  float afStack_2c [7];
  GmMat3 aGStack_10 [8];
  GmMat3 aGStack_8 [8];
  
  iVar2 = *(int *)param_1;
  pGVar3 = *(GmIso3 **)(param_2 + 4);
  if (*(int *)(param_1 + 8) == 0) {
    GmIso4::SetIdentity(&local_30,unaff_EDI);
  }
  else {
    pfVar19 = *(float **)(param_1 + 4);
    pfVar20 = &local_30;
    for (iVar17 = 0xc; param_3 = (CGmCollisionBuffer *)param_2, iVar17 != 0; iVar17 = iVar17 + -1) {
      *pfVar20 = *pfVar19;
      pfVar19 = pfVar19 + 1;
      pfVar20 = pfVar20 + 1;
    }
  }
  if (*(int *)(param_3 + 8) != 0) {
    GmIso4::MultInverse(afStack_2c,pGVar3,unaff_ESI);
  }
  (**(code **)(*in_stack_00000010 + 8))();
  fStack_44 = *(float *)(iVar2 + 8);
  fStack_40 = *(float *)(iVar2 + 0xc);
  uStack_3c = *(undefined4 *)(iVar2 + 0x10);
  fStack_38 = *(float *)(iVar2 + 0x14);
  fStack_34 = *(float *)(iVar2 + 0x18);
  local_30 = *(float *)(iVar2 + 0x1c);
  GmBoxAligned::Mult(&fStack_44,(GmIso3 *)afStack_2c,unaff_ESI);
  pGVar21 = (GmMat3 *)0x0;
  pCStack_64 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)fStack_a8 + 0x20),unaff_EBP)
  ;
  if (pCStack_64 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar14 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                          ((void *)((int)fStack_a8 + 0x20),in_stack_ffffff28,(ulong)unaff_EBX);
      unaff_EBX = (CPlugVolumeProjector *)(pSVar14 + 4);
      iVar17 = GmBoxAligned::TestInter(&fStack_38,unaff_EBX,in_stack_ffffff04,in_stack_ffffff08);
      if ((iVar17 != 0) &&
         (*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar14 + 0x1c) !=
          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff)) {
        in_stack_ffffff04 = (GmBoxAligned *)0x8f5328;
        pSVar14 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                            ((void *)((int)fStack_a8 + 0x10),
                             *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar14 + 0x1c),
                             in_stack_ffffff0c);
        this = (void *)((int)fStack_a8 + 8);
        in_stack_ffffff08 = (GmIso4 *)0x8f5338;
        pSVar15 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                            (this,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                   (pSVar14 + 0x10),in_stack_ffffff10);
        afStack_88[2] = *(float *)pSVar15 - in_stack_00000014;
        afStack_88[3] = *(float *)(pSVar15 + 4) - in_stack_00000018;
        fStack_78 = *(float *)(pSVar15 + 8) - in_stack_0000001c;
        in_stack_ffffff0c = 0x8f5372;
        GmVec3::MultTranspose(afStack_88 + 2,aGStack_10,in_stack_ffffff14);
        in_stack_ffffff10 = 0x8f537d;
        pSVar15 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                            (this,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                   (pSVar14 + 0x14),in_stack_ffffff18);
        fStack_6c = *(float *)pSVar15 - in_stack_0000001c;
        fStack_68 = *(float *)(pSVar15 + 4) - in_stack_00000020;
        pCStack_64 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     (*(float *)(pSVar15 + 8) - in_stack_00000024);
        in_stack_ffffff14 = (GmMat3 *)0x8f53bd;
        GmVec3::MultTranspose(&fStack_6c,aGStack_8,in_stack_ffffff1c);
        in_stack_ffffff18 = 0x8f53c8;
        pSVar15 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                            (this,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                   (pSVar14 + 0x18),(ulong)in_stack_ffffff20);
        fStack_58 = *(float *)pSVar15 - in_stack_00000024;
        fStack_54 = *(float *)(pSVar15 + 4) - in_stack_00000028;
        fStack_50 = *(float *)(pSVar15 + 8) - in_stack_0000002c;
        in_stack_ffffff1c = (GmMat3 *)0x8f540e;
        in_stack_ffffff20 = (undefined1 *)register0x00000010;
        GmVec3::MultTranspose(&fStack_58,(GmMat3 *)&stack0x00000000,pGVar21);
        fVar4 = fStack_6c - *(float *)(iVar2 + 8);
        fVar5 = fStack_60 - *(float *)(iVar2 + 8);
        fVar6 = fStack_54 - *(float *)(iVar2 + 8);
        fStack_c4 = fVar4;
        if (fVar5 < fVar4) {
          fStack_c4 = fVar5;
        }
        fStack_c8 = fVar4;
        if (fVar4 < fVar5) {
          fStack_c8 = fVar5;
        }
        if (fVar6 < fStack_c4) {
          fStack_c4 = fVar6;
        }
        if (fStack_c8 < fVar6) {
          fStack_c8 = fVar6;
        }
        fStack_a8 = afStack_88[3];
        if ((fStack_c4 <= *(float *)(iVar2 + 0x14)) && (-*(float *)(iVar2 + 0x14) <= fStack_c8)) {
          fVar7 = fStack_68 - *(float *)(iVar2 + 0xc);
          fVar8 = fStack_5c - *(float *)(iVar2 + 0xc);
          fVar9 = fStack_50 - *(float *)(iVar2 + 0xc);
          fStack_c4 = fVar7;
          if (fVar8 < fVar7) {
            fStack_c4 = fVar8;
          }
          fStack_c8 = fVar7;
          if (fVar7 < fVar8) {
            fStack_c8 = fVar8;
          }
          if (fVar9 < fStack_c4) {
            fStack_c4 = fVar9;
          }
          if (fStack_c8 < fVar9) {
            fStack_c8 = fVar9;
          }
          if ((fStack_c4 <= *(float *)(iVar2 + 0x18)) && (-*(float *)(iVar2 + 0x18) <= fStack_c8)) {
            fVar10 = (float)pCStack_64 - *(float *)(iVar2 + 0x10);
            fVar11 = fStack_58 - *(float *)(iVar2 + 0x10);
            fVar12 = fStack_4c - *(float *)(iVar2 + 0x10);
            fStack_c4 = fVar10;
            if (fVar11 < fVar10) {
              fStack_c4 = fVar11;
            }
            fStack_c8 = fVar10;
            if (fVar10 < fVar11) {
              fStack_c8 = fVar11;
            }
            if (fVar12 < fStack_c4) {
              fStack_c4 = fVar12;
            }
            if (fStack_c8 < fVar12) {
              fStack_c8 = fVar12;
            }
            if ((fStack_c4 <= *(float *)(iVar2 + 0x1c)) && (-*(float *)(iVar2 + 0x1c) <= fStack_c8))
            {
              uVar18 = 0;
              fStack_48 = fVar5 - fVar4;
              fStack_44 = fVar8 - fVar7;
              fStack_40 = fVar11 - fVar10;
              fStack_78 = fVar6 - fVar5;
              fStack_74 = fVar9 - fVar8;
              fStack_70 = fVar12 - fVar11;
              afStack_88[0] = fStack_44 * fStack_70 - fStack_40 * fStack_74;
              afStack_88[1] = fStack_78 * fStack_40 - fStack_48 * fStack_70;
              afStack_88[2] = fStack_74 * fStack_48 - fStack_78 * fStack_44;
              fVar13 = -(afStack_88[2] * fVar10 + afStack_88[0] * fVar4 + afStack_88[1] * fVar7);
              do {
                fVar1 = *(float *)(uVar18 + 0x14 + iVar2);
                if (*(float *)((int)afStack_88 + uVar18) <= 0.0) {
                  *(float *)((int)afStack_2c + uVar18 + 0xc) = fVar1;
                  fVar1 = -*(float *)(uVar18 + 0x14 + iVar2);
                }
                else {
                  *(float *)((int)afStack_2c + uVar18 + 0xc) = -fVar1;
                  fVar1 = *(float *)(uVar18 + 0x14 + iVar2);
                }
                *(float *)((int)afStack_2c + uVar18) = fVar1;
                uVar18 = uVar18 + 4;
              } while (uVar18 < 9);
              if ((afStack_2c[5] * afStack_88[2] +
                   afStack_2c[3] * afStack_88[0] + afStack_2c[4] * afStack_88[1] + fVar13 <=
                   (float)_PTR_00b2c178) &&
                 ((float)_PTR_00b2c178 <=
                  afStack_2c[2] * afStack_88[2] +
                  afStack_2c[0] * afStack_88[0] + afStack_2c[1] * afStack_88[1] + fVar13)) {
                fStack_c4 = fStack_40 * fVar7 - fStack_44 * fVar10;
                fVar13 = fStack_40 * fVar9 - fStack_44 * fVar12;
                fStack_c8 = fVar13;
                if (fVar13 < fStack_c4) {
                  fStack_c8 = fStack_c4;
                  fStack_c4 = fVar13;
                }
                fVar13 = *(float *)(iVar2 + 0x1c) * ABS(fStack_44) +
                         *(float *)(iVar2 + 0x18) * ABS(fStack_40);
                if ((fStack_c4 <= fVar13) && (-fVar13 <= fStack_c8)) {
                  fStack_c4 = fStack_48 * fVar10 - fStack_40 * fVar4;
                  fVar13 = fStack_48 * fVar12 - fVar6 * fStack_40;
                  fStack_c8 = fVar13;
                  if (fVar13 < fStack_c4) {
                    fStack_c8 = fStack_c4;
                    fStack_c4 = fVar13;
                  }
                  fVar13 = ABS(fStack_40) * *(float *)(iVar2 + 0x14) +
                           *(float *)(iVar2 + 0x1c) * ABS(fStack_48);
                  if ((fStack_c4 <= fVar13) && (-fVar13 <= fStack_c8)) {
                    fStack_c4 = fStack_44 * fVar5 - fStack_48 * fVar8;
                    fVar13 = fStack_44 * fVar6 - fVar9 * fStack_48;
                    fStack_c8 = fVar13;
                    if (fVar13 < fStack_c4) {
                      fStack_c8 = fStack_c4;
                      fStack_c4 = fVar13;
                    }
                    fVar13 = ABS(fStack_44) * *(float *)(iVar2 + 0x14) +
                             *(float *)(iVar2 + 0x18) * ABS(fStack_48);
                    if ((fStack_c4 <= fVar13) && (-fVar13 <= fStack_c8)) {
                      fStack_c4 = fVar7 * fStack_70 - fStack_74 * fVar10;
                      fVar13 = fStack_70 * fVar9 - fStack_74 * fVar12;
                      fStack_c8 = fVar13;
                      if (fVar13 < fStack_c4) {
                        fStack_c8 = fStack_c4;
                        fStack_c4 = fVar13;
                      }
                      fVar13 = *(float *)(iVar2 + 0x1c) * ABS(fStack_74) +
                               *(float *)(iVar2 + 0x18) * ABS(fStack_70);
                      if ((fStack_c4 <= fVar13) && (-fVar13 <= fStack_c8)) {
                        fStack_c4 = fStack_78 * fVar10 - fStack_70 * fVar4;
                        fVar12 = fStack_78 * fVar12 - fVar6 * fStack_70;
                        fStack_c8 = fVar12;
                        if (fVar12 < fStack_c4) {
                          fStack_c8 = fStack_c4;
                          fStack_c4 = fVar12;
                        }
                        fVar12 = ABS(fStack_70) * *(float *)(iVar2 + 0x14) +
                                 *(float *)(iVar2 + 0x1c) * ABS(fStack_78);
                        if ((fStack_c4 <= fVar12) && (-fVar12 <= fStack_c8)) {
                          fStack_c4 = fStack_74 * fVar4 - fStack_78 * fVar7;
                          fVar12 = fStack_74 * fVar5 - fVar8 * fStack_78;
                          fStack_c8 = fVar12;
                          if (fVar12 < fStack_c4) {
                            fStack_c8 = fStack_c4;
                            fStack_c4 = fVar12;
                          }
                          fVar12 = ABS(fStack_74) * *(float *)(iVar2 + 0x14) +
                                   *(float *)(iVar2 + 0x18) * ABS(fStack_78);
                          if ((fStack_c4 <= fVar12) && (-fVar12 <= fStack_c8)) {
                            fStack_38 = fStack_6c - fStack_54;
                            fStack_34 = fStack_68 - fStack_50;
                            local_30 = (float)pCStack_64 - fStack_4c;
                            fStack_c4 = local_30 * fVar7 - fStack_34 * fVar10;
                            fVar7 = local_30 * fVar8 - fVar11 * fStack_34;
                            fStack_c8 = fVar7;
                            if (fVar7 < fStack_c4) {
                              fStack_c8 = fStack_c4;
                              fStack_c4 = fVar7;
                            }
                            fVar7 = *(float *)(iVar2 + 0x1c) * ABS(fStack_34) +
                                    *(float *)(iVar2 + 0x18) * ABS(local_30);
                            if ((fStack_c4 <= fVar7) && (-fVar7 <= fStack_c8)) {
                              fStack_c4 = fStack_38 * fVar10 - local_30 * fVar4;
                              fVar4 = fStack_38 * fVar11 - fVar5 * local_30;
                              fStack_c8 = fVar4;
                              if (fVar4 < fStack_c4) {
                                fStack_c8 = fStack_c4;
                                fStack_c4 = fVar4;
                              }
                              fVar4 = ABS(local_30) * *(float *)(iVar2 + 0x14) +
                                      *(float *)(iVar2 + 0x1c) * ABS(fStack_38);
                              if ((fStack_c4 <= fVar4) && (-fVar4 <= fStack_c8)) {
                                fStack_c4 = fStack_34 * fVar5 - fStack_38 * fVar8;
                                fVar4 = fStack_34 * fVar6 - fVar9 * fStack_38;
                                fStack_c8 = fVar4;
                                if (fVar4 < fStack_c4) {
                                  fStack_c8 = fStack_c4;
                                  fStack_c4 = fVar4;
                                }
                                fVar4 = ABS(fStack_34) * *(float *)(iVar2 + 0x14) +
                                        *(float *)(iVar2 + 0x18) * ABS(fStack_38);
                                if ((fStack_c4 <= fVar4) && (-fVar4 <= fStack_c8)) {
                                  puVar16 = (undefined4 *)(**(code **)*in_stack_00000040)();
                                  puVar16[2] = 0;
                                  puVar16[1] = 0;
                                  *puVar16 = 0;
                                  pSVar15 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::
                                            operator[]((void *)((int)afStack_88[3] + 8),
                                                       *(
                                                  CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                                  (pSVar14 + 0x10),(ulong)pGVar3);
                                  GmVec3::SetMult(puVar16 + 6,(SPlugFaceCull *)pSVar15,
                                                  (SPlugFaceCull *)in_stack_ffffff28,
                                                  in_stack_ffffff2c);
                                  puVar16[3] = *(float *)(pGVar3 + 8) * *(float *)(pSVar14 + 8) +
                                               *(float *)pSVar14 * *(float *)pGVar3 +
                                               *(float *)(pGVar3 + 4) * *(float *)(pSVar14 + 4);
                                  puVar16[4] = *(float *)(pGVar3 + 0x14) * *(float *)(pSVar14 + 8) +
                                               *(float *)(pGVar3 + 0xc) * *(float *)pSVar14 +
                                               *(float *)(pGVar3 + 0x10) * *(float *)(pSVar14 + 4);
                                  puVar16[5] = *(float *)(pGVar3 + 0x20) * *(float *)(pSVar14 + 8) +
                                               *(float *)(pGVar3 + 0x18) * *(float *)pSVar14 +
                                               *(float *)(pGVar3 + 0x1c) * *(float *)(pSVar14 + 4);
                                  *(undefined2 *)(puVar16 + 9) = *(undefined2 *)(iVar2 + 4);
                                  *(undefined2 *)((int)puVar16 + 0x26) =
                                       *(undefined2 *)(pSVar14 + 0x1c);
                                  return 1;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    } while (in_stack_ffffff28 < pCStack_64);
  }
  return 0;
}
// --- END GmCollision_Box_Mesh ---

