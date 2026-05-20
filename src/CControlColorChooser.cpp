// Class implementation: CControlColorChooser

// =================================================
// Function: CControlColorChooser::SetColorCursor
// =================================================
void __thiscall
CControlColorChooser::SetColorCursor
          (CControlColorChooser *this,CControlColorChooser *param_1,GxColor *param_2)
{
{
  GxColor *unaff_retaddr;
  
  if (*(CPlugVisualQuads2D **)(this + 0x178) != (CPlugVisualQuads2D *)0x0) {
    CPlugVisualQuads2D::SetQuadColors
              (*(CPlugVisualQuads2D **)(this + 0x178),(CPlugVisualQuads2D *)0x0,(ulong)param_1,
               (GxColor *)param_1,(GxColor *)param_1,(GxColor *)param_1,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CControlColorChooser::SetCursorPosition
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CControlColorChooser::SetCursorPosition
          (CControlColorChooser *this,CControlColorChooser *param_1,float param_2,float param_3)
{
{
  GmVec3 *pGVar1;
  float fVar2;
  GmVec3 *pGVar3;
  GmVec3 *local_c;
  float local_8;
  undefined4 local_4;
  
  fVar2 = (float)_DAT_00b313b8;
  pGVar1 = (GmVec3 *)(-*(float *)(this + 0x17c) * fVar2);
  pGVar3 = (GmVec3 *)(*(float *)(this + 0x17c) * fVar2);
  local_c = pGVar1;
  if (((float)pGVar1 < (float)param_1) &&
     (local_c = (GmVec3 *)param_1,
     (float)pGVar3 < (float)param_1 != ((float)pGVar3 == (float)param_1))) {
    local_c = pGVar3;
  }
  *(GmVec3 **)(this + 0x184) = local_c;
  local_8 = -*(float *)(this + 0x180) * fVar2;
  fVar2 = *(float *)(this + 0x180) * fVar2;
  if ((local_8 < param_2) && (local_8 = param_2, fVar2 < param_2 != (fVar2 == param_2))) {
    local_8 = fVar2;
  }
  *(float *)(this + 0x188) = local_8;
  if (*(CPlugTree **)(this + 0x174) == (CPlugTree *)0x0) {
    return;
  }
  local_4 = _DAT_00b36ac0;
  CPlugTree::SetTranslation(*(CPlugTree **)(this + 0x174),(GmIso4 *)&local_c,pGVar1);
  return;
}
}

// =================================================
// Function: CControlColorChooser::SetCursorPositionFromNormedPos
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CControlColorChooser::SetCursorPositionFromNormedPos
          (CControlColorChooser *this,CControlColorChooser *param_1,float param_2,float param_3)
{
{
  CControlColorChooser *pCVar1;
  
  pCVar1 = (CControlColorChooser *)
           (*(float *)(this + 0x17c) * ((float)_DAT_00b313b8 - (float)param_1));
  SetCursorPosition(this,pCVar1,(param_2 - (float)_DAT_00b313b8) * *(float *)(this + 0x180),
                    (float)pCVar1);
  return;
}
}

// =================================================
// Function: CControlColorChooser::SetParamsFromRGB
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CControlColorChooser::SetParamsFromRGB
          (CControlColorChooser *this,CControlColorChooser *param_1,GmVec3 *param_2,int param_3,
          int param_4,int param_5,int param_6)
{
{
  CPlugBitmap *pCVar1;
  int iVar2;
  undefined4 *puVar3;
  float unaff_EBX;
  float unaff_EBP;
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  int in_stack_00000024;
  GxColor *in_stack_ffffffc8;
  undefined4 local_34;
  float local_30;
  CControlColorChooser *local_2c;
  CControlColorChooser *local_28;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(int *)(this + 0x160) == 0) {
    local_20 = *(undefined4 *)param_1;
    local_1c = *(undefined4 *)(param_1 + 4);
    local_18 = *(undefined4 *)(param_1 + 8);
    local_14 = 0x3f800000;
    GxColor::GetHSV(&local_20,(GxColor *)&stack0xffffffc8,unaff_EDI);
    if (param_4 == 0) {
      if (param_3 == 0) goto LAB_00784d2b;
LAB_00784c51:
      local_c = *(undefined4 *)(this + 0x18c);
      local_8 = *(undefined4 *)(this + 400);
      local_4 = *(undefined4 *)(this + 0x194);
      GxColor::GetHSV(&local_c,(GxColor *)&local_28,unaff_ESI);
      if (param_3 == 0) {
        if (param_5 != 0) {
          local_24 = local_30;
          *(float *)(this + 0x198) = local_30;
          GxColor::SetHSV(&local_18,(GxColor *)&local_24,(GmVec3 *)0x3f800000,unaff_EBP);
          *(undefined4 *)(this + 0x18c) = local_14;
          *(undefined4 *)(this + 400) = local_10;
          *(undefined4 *)(this + 0x194) = local_c;
          goto LAB_00784ddc;
        }
      }
      else if (param_5 == 0) {
        local_30 = local_24;
        GxColor::SetHSV(&local_18,(GxColor *)&local_30,(GmVec3 *)0x3f800000,unaff_EBP);
        *(undefined4 *)(this + 0x18c) = local_14;
        *(undefined4 *)(this + 400) = local_10;
        *(undefined4 *)(this + 0x194) = local_c;
        iVar2 = (**(code **)(**(int **)(this + 0x1a0) + 0x8c))(0);
        pCVar1 = *(CPlugBitmap **)(iVar2 + 0x1c);
        CPlugFileGen::GenHueGradient
                  (*(CPlugFileGen **)(pCVar1 + 0x48),*(CPlugFileGen **)(this + 0x1a4),
                   SUB41(*(undefined4 *)(this + 0x1a8),0),(float)local_28,local_24,0.0,1.0);
        CPlugBitmap::SetDirty(pCVar1,(CPlugVertexStream *)0x1,(int)unaff_EBX);
      }
    }
    else {
      if (param_3 == 0) goto LAB_00784c51;
LAB_00784d2b:
      *(undefined4 *)(this + 0x18c) = *(undefined4 *)param_1;
      *(undefined4 *)(this + 400) = *(undefined4 *)(param_1 + 4);
      *(undefined4 *)(this + 0x194) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(this + 0x198) = local_34;
      iVar2 = (**(code **)(**(int **)(this + 0x1a0) + 0x8c))(0);
      pCVar1 = *(CPlugBitmap **)(iVar2 + 0x1c);
      CPlugFileGen::GenHueGradient
                (*(CPlugFileGen **)(pCVar1 + 0x48),*(CPlugFileGen **)(this + 0x1a4),
                 SUB41(*(undefined4 *)(this + 0x1a8),0),(float)local_2c,(float)local_28,0.0,1.0);
      CPlugBitmap::SetDirty(pCVar1,(CPlugVertexStream *)0x1,(int)unaff_EBP);
LAB_00784ddc:
      SetCursorPositionFromNormedPos(this,local_2c,_DAT_00b31460,unaff_EBX);
    }
    SetColorCursor(this,(CControlColorChooser *)&local_10,in_stack_ffffffc8);
    if (in_stack_00000024 == 0) goto LAB_00784e20;
    puVar3 = *(undefined4 **)(this + 0x164);
  }
  else {
    if (*(int *)(this + 0x160) != 1) goto LAB_00784e20;
    local_20 = *(undefined4 *)param_1;
    local_1c = *(undefined4 *)(param_1 + 4);
    local_18 = *(undefined4 *)(param_1 + 8);
    local_14 = 0x3f800000;
    GxColor::GetHSV(&local_20,(GxColor *)&stack0xffffffc8,unaff_EDI);
    if (param_4 == 0) {
      if (param_3 == 0) goto LAB_00784b3e;
LAB_00784a74:
      local_c = *(undefined4 *)(this + 0x18c);
      local_8 = *(undefined4 *)(this + 400);
      local_4 = *(undefined4 *)(this + 0x194);
      GxColor::GetHSV(&local_c,(GxColor *)&local_28,unaff_ESI);
      if (param_3 == 0) {
        if (param_5 != 0) {
          local_30 = local_24;
          GxColor::SetHSV(&local_18,(GxColor *)&local_30,(GmVec3 *)0x3f800000,unaff_EBP);
          *(undefined4 *)(this + 0x18c) = local_14;
          *(undefined4 *)(this + 400) = local_10;
          *(undefined4 *)(this + 0x194) = local_c;
          goto LAB_00784bd3;
        }
      }
      else if (param_5 == 0) {
        local_24 = local_30;
        *(float *)(this + 0x198) = local_30;
        GxColor::SetHSV(&local_18,(GxColor *)&local_24,(GmVec3 *)0x3f800000,unaff_EBP);
        *(undefined4 *)(this + 0x18c) = local_14;
        *(undefined4 *)(this + 400) = local_10;
        *(undefined4 *)(this + 0x194) = local_c;
        iVar2 = (**(code **)(**(int **)(this + 0x1a0) + 0x8c))(0);
        pCVar1 = *(CPlugBitmap **)(iVar2 + 0x1c);
        CPlugFileGen::GenSLGradient
                  (*(CPlugFileGen **)(pCVar1 + 0x48),*(CPlugFileGen **)(this + 0x1a4),
                   SUB41(*(undefined4 *)(this + 0x1a8),0),(float)local_2c);
        CPlugBitmap::SetDirty(pCVar1,(CPlugVertexStream *)0x1,(int)unaff_EBX);
      }
    }
    else {
      if (param_3 == 0) goto LAB_00784a74;
LAB_00784b3e:
      *(undefined4 *)(this + 0x18c) = *(undefined4 *)param_1;
      *(undefined4 *)(this + 400) = *(undefined4 *)(param_1 + 4);
      *(undefined4 *)(this + 0x194) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(this + 0x198) = local_34;
      iVar2 = (**(code **)(**(int **)(this + 0x1a0) + 0x8c))(0);
      pCVar1 = *(CPlugBitmap **)(iVar2 + 0x1c);
      CPlugFileGen::GenSLGradient
                (*(CPlugFileGen **)(pCVar1 + 0x48),*(CPlugFileGen **)(this + 0x1a4),
                 SUB41(*(undefined4 *)(this + 0x1a8),0),local_30);
      CPlugBitmap::SetDirty(pCVar1,(CPlugVertexStream *)0x1,(int)unaff_EBP);
LAB_00784bd3:
      SetCursorPositionFromNormedPos(this,local_28,local_24,unaff_EBX);
    }
    SetColorCursor(this,(CControlColorChooser *)&local_10,in_stack_ffffffc8);
    if (in_stack_00000024 == 0) goto LAB_00784e20;
    puVar3 = *(undefined4 **)(this + 0x168);
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(this + 0x18c);
  }
LAB_00784e20:
  (**(code **)(*(int *)this + 0x1a8))();
  return;
}
}

