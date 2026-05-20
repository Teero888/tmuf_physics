// Class implementation: CPlugShaderGeneric

// =================================================
// Function: CPlugShaderGeneric::CPlugShaderGeneric
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugShaderGeneric::CPlugShaderGeneric(CPlugShaderGeneric *this,CPlugShaderGeneric *param_1)
{
{
  CPlugShader *unaff_EDI;
  
  CPlugShader::CPlugShader((CPlugShader *)this,unaff_EDI);
  *(undefined ***)this = vftable;
  _memset(this + 0x38,0,0x58);
  *(uint *)(this + 0x8c) = *(uint *)(this + 0x8c) & 0xfffffffd | 1;
  *(undefined4 *)(this + 0x38) = 0x3f800000;
  *(undefined4 *)(this + 0x3c) = 0x3f800000;
  *(undefined4 *)(this + 0x40) = 0x3f800000;
  *(uint *)(this + 0x8c) = *(uint *)(this + 0x8c) & 0xfffffff7 | 4;
  *(undefined4 *)(this + 0x44) = 0x3f800000;
  *(undefined4 *)(this + 0x48) = 0x3f800000;
  *(undefined4 *)(this + 0x4c) = 0x3f800000;
  *(undefined4 *)(this + 0x50) = 0x3f800000;
  *(uint *)(this + 0x8c) = *(uint *)(this + 0x8c) & 0xffffffef;
  *(undefined4 *)(this + 0x54) = 0x3f800000;
  *(undefined4 *)(this + 0x58) = 0x3f800000;
  *(undefined4 *)(this + 0x5c) = 0x3f800000;
  *(uint *)(this + 0x8c) = *(uint *)(this + 0x8c) & 0xffffff9f;
  *(undefined4 *)(this + 0x60) = _DAT_00b36160;
  *(undefined4 *)(this + 100) = 0x3f800000;
  *(undefined4 *)(this + 0x68) = 0x3f800000;
  *(undefined4 *)(this + 0x6c) = 0x3f800000;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(uint *)(this + 0x8c) = *(uint *)(this + 0x8c) & 0xfffffe7f;
  *(undefined4 *)(this + 0x7c) = 0x3f800000;
  *(undefined4 *)(this + 0x80) = 0x3f800000;
  *(undefined4 *)(this + 0x84) = 0x3f800000;
  *(undefined4 *)(this + 0x88) = 0x3f800000;
  *(uint *)(this + 0x8c) = *(uint *)(this + 0x8c) & 0x7ff;
  return;
}
}

// =================================================
// Function: CPlugShaderGeneric::SetClassicLighting
// =================================================
void __thiscall
CPlugShaderGeneric::SetClassicLighting
          (CPlugShaderGeneric *this,CPlugShaderGeneric *param_1,GxColor *param_2,int param_3,
          int param_4)
{
{
  undefined4 uVar1;
  
  *(uint *)(this + 0x8c) =
       (uint)(param_2 != (GxColor *)0x0) | *(uint *)(this + 0x8c) & 0xfffffff4 | 4;
  *(undefined4 *)(this + 0x38) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 8);
  if (param_3 == 0) {
    uVar1 = 0;
    *(undefined4 *)(this + 0x44) = 0;
    *(undefined4 *)(this + 0x48) = 0;
  }
  else {
    *(undefined4 *)(this + 0x44) = *(undefined4 *)param_1;
    *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 4);
    uVar1 = *(undefined4 *)(param_1 + 8);
  }
  *(undefined4 *)(this + 0x4c) = uVar1;
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0xc);
  if ((param_2 == (GxColor *)0x0) && (param_3 == 0)) {
    *(uint *)(this + 0x8c) = *(uint *)(this + 0x8c) & 0xffffffbf | 0x20;
    *(undefined4 *)(this + 100) = *(undefined4 *)param_1;
    *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 8);
    CPlugShader::SetDirty((CPlugShader *)this,(CPlugVertexStream *)0x1,1);
    return;
  }
  *(uint *)(this + 0x8c) = *(uint *)(this + 0x8c) & 0xffffffdf;
  CPlugShader::SetDirty((CPlugShader *)this,(CPlugVertexStream *)0x1,1);
  return;
}
}

// =================================================
// Function: CPlugShaderGeneric::SetClassicVertexLighting
// =================================================
void __thiscall
CPlugShaderGeneric::SetClassicVertexLighting
          (CPlugShaderGeneric *this,CPlugShaderGeneric *param_1,int param_2,int param_3)
{
{
  *(uint *)(this + 0x8c) = *(uint *)(this + 0x8c) | 10;
  if ((param_1 == (CPlugShaderGeneric *)0x0) && (param_2 == 0)) {
    *(uint *)(this + 0x8c) = *(uint *)(this + 0x8c) & 0xfffffffa;
  }
  else {
    *(uint *)(this + 0x8c) =
         (uint)(param_2 != 0) * 4 | (uint)(param_1 != (CPlugShaderGeneric *)0x0) |
         *(uint *)(this + 0x8c) & 0xfffffffa;
  }
  *(uint *)(this + 0x8c) = *(uint *)(this + 0x8c) & 0xffffffdf;
  CPlugShader::SetDirty((CPlugShader *)this,(CPlugVertexStream *)0x1,1);
  return;
}
}

// =================================================
// Function: CPlugShaderGeneric::SetDiffuseSrc
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugShaderGeneric::SetDiffuseSrc
          (CPlugShaderGeneric *this,CPlugShaderGeneric *param_1,int param_2,GxColor *param_3)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x8c);
  if (((((uVar1 >> 3 & 1) == (uint)(param_1 != (CPlugShaderGeneric *)0x0)) &&
       (ABS(*(float *)(this + 0x44) - *(float *)param_2) < _DAT_00bae308)) &&
      (ABS(*(float *)(this + 0x48) - *(float *)(param_2 + 4)) < _DAT_00bae308)) &&
     (ABS(*(float *)(this + 0x4c) - *(float *)(param_2 + 8)) < _DAT_00bae308)) {
    if (*(float *)(param_2 + 0xc) == *(float *)(this + 0x50)) {
      return;
    }
    *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_2 + 0xc);
    CPlugShader::SetDirty((CPlugShader *)this,(CPlugVertexStream *)((byte)this[0x1e] & 1),1);
    return;
  }
  *(uint *)(this + 0x8c) = ((uint)(param_1 != (CPlugShaderGeneric *)0x0) * 8 ^ uVar1) & 8 ^ uVar1;
  *(undefined4 *)(this + 0x44) = *(undefined4 *)param_2;
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_2 + 0xc);
  CPlugShader::SetDirty((CPlugShader *)this,(CPlugVertexStream *)0x1,1);
  return;
}
}

// =================================================
// Function: CPlugShaderGeneric::SetEmissive
// =================================================
void __thiscall
CPlugShaderGeneric::SetEmissive
          (CPlugShaderGeneric *this,CPlugShaderGeneric *param_1,int param_2,GmVec3 *param_3,
          int param_4)
{
{
  uint uVar1;
  ulong uVar2;
  GmVec2 *unaff_EDI;
  
  uVar1 = *(uint *)(this + 0x8c);
  if (((uVar1 >> 5 & 1) != (uint)(param_1 != (CPlugShaderGeneric *)0x0)) ||
     ((uVar1 >> 6 & 1) != (uint)(param_3 != (GmVec3 *)0x0))) {
    *(uint *)(this + 0x8c) =
         ((uint)(param_3 != (GmVec3 *)0x0) * 2 | (uint)(param_1 != (CPlugShaderGeneric *)0x0)) << 5
         | uVar1 & 0xffffff9f;
    CPlugShader::SetDirty((CPlugShader *)this,(CPlugVertexStream *)0x1,1);
  }
  if (((*(uint *)(this + 0x8c) & 0x20) != 0) && ((*(uint *)(this + 0x8c) & 0x40) == 0)) {
    uVar2 = GmVec3::IsNearlyEqual(this + 100,(GmVec2 *)param_2,unaff_EDI);
    if (uVar2 == 0) {
      *(undefined4 *)(this + 100) = *(undefined4 *)param_2;
      *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_2 + 4);
      *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_2 + 8);
      CPlugShader::SetDirty((CPlugShader *)this,(CPlugVertexStream *)((byte)this[0x1e] & 1),1);
    }
  }
  return;
}
}

// =================================================
// Function: CPlugShaderGeneric::SetMaterial
// =================================================
void __thiscall
CPlugShaderGeneric::SetMaterial
          (CPlugShaderGeneric *this,CPlugMaterialCustom *param_1,CPlugMaterial *param_2)
{
{
  int iVar1;
  CPlugShaderGeneric *pCVar2;
  
  pCVar2 = this + 0x38;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pCVar2 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    pCVar2 = pCVar2 + 4;
  }
  CPlugShader::SetDirty((CPlugShader *)this,(CPlugVertexStream *)0x1,1);
  return;
}
}

// =================================================
// Function: CPlugShaderGeneric::SetVertexColor
// =================================================
void __thiscall
CPlugShaderGeneric::SetVertexColor
          (CPlugShaderGeneric *this,CPlugShaderGeneric *param_1,EPlugShaderVertexColor param_2,
          GxColor *param_3)
{
{
  int unaff_retaddr;
  
  switch(param_1) {
  default:
    SetClassicLighting(this,(CPlugShaderGeneric *)param_2,(GxColor *)0x0,0,unaff_retaddr);
    return;
  case (CPlugShaderGeneric *)0x1:
    SetClassicVertexLighting(this,(CPlugShaderGeneric *)0x0,0,(int)param_3);
    return;
  case (CPlugShaderGeneric *)0x2:
    SetClassicLighting(this,(CPlugShaderGeneric *)param_2,(GxColor *)0x1,1,unaff_retaddr);
    return;
  case (CPlugShaderGeneric *)0x3:
    SetClassicVertexLighting(this,(CPlugShaderGeneric *)0x1,1,(int)param_3);
    return;
  }
}
}

