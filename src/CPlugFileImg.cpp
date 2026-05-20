// Class implementation: CPlugFileImg

// =================================================
// Function: CPlugFileImg::AddAlpha_BGRA
// =================================================
void __thiscall CPlugFileImg::AddAlpha_BGRA(CPlugFileImg *this,CPlugFileImg *param_1,uchar param_2)
{
{
  SDesc *pSVar1;
  longlong lVar2;
  int iVar3;
  uchar *puVar4;
  uint uVar5;
  SDesc *pSVar6;
  uint uVar7;
  uchar *puVar8;
  ulong unaff_ESI;
  GmNat3 *unaff_EDI;
  uint uVar9;
  int local_2c;
  undefined4 local_28;
  undefined4 local_1c;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  local_c = *(undefined4 *)(this + 0x1c);
  local_8 = *(undefined4 *)(this + 0x20);
  local_1c = *(int *)(this + 0x1c);
  local_4 = *(uint *)(this + 0x24);
  uVar9 = local_4 >> 2 & 7;
  puVar4 = GetFaceLevel(this,(CPlugFileImg *)0x0,0,0,(ulong *)0x0,unaff_EDI);
  uVar5 = local_1c * local_2c;
  lVar2 = (ulonglong)uVar5 * 4;
  pSVar6 = operator_new__(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  if (local_1c != 0) {
    pSVar1 = pSVar6;
    iVar3 = local_2c;
    local_28 = pSVar6;
    puVar8 = puVar4;
    do {
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        uVar7 = 0;
        if (uVar9 == 0) {
LAB_008509c8:
          _memset(pSVar1 + uVar7,0,3 - uVar7);
        }
        else {
          do {
            pSVar1[uVar7] = *(SDesc *)(puVar4 + uVar7);
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar9);
          if (uVar7 < 3) goto LAB_008509c8;
        }
        pSVar1[3] = (SDesc)param_2;
        puVar4 = puVar4 + uVar9;
        pSVar1 = pSVar1 + 4;
      }
      pSVar1 = local_28 + local_2c * 4;
      puVar4 = puVar8 + uVar9 * local_2c;
      local_1c = local_1c + -1;
      iVar3 = local_2c;
      local_28 = pSVar1;
      puVar8 = puVar4;
    } while (local_1c != 0);
  }
  SetPixels(this,(CPlugFileImg *)&local_c,pSVar6,(uchar *)(uVar5 * 4),unaff_ESI);
  return;
}
}

// =================================================
// Function: CPlugFileImg::AllocatePixels
// =================================================
void * __thiscall CPlugFileImg::AllocatePixels(CPlugFileImg *this,CPlugFileImg *param_1)
{
{
  ulong uVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  int unaff_ESI;
  
  if (*(void **)(this + 0x28) == (void *)0x0) {
    uVar1 = ComputeByteSize(this,(CPlugFileImg *)0x1,unaff_ESI);
    *(ulong *)(this + 0x2c) = uVar1;
    switch(*(uint *)(this + 0x24) >> 5 & 0xf) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      pvVar2 = operator_new__(uVar1);
      *(void **)(this + 0x28) = pvVar2;
      return pvVar2;
    case 6:
    case 7:
      uVar3 = uVar1 >> 1;
      uVar4 = 2;
      break;
    case 8:
      uVar3 = uVar1 >> 2;
      uVar4 = 4;
      break;
    default:
      return (void *)0x0;
    }
    pvVar2 = operator_new__(-(uint)((int)((ulonglong)uVar3 * (ulonglong)uVar4 >> 0x20) != 0) |
                            (uint)((ulonglong)uVar3 * (ulonglong)uVar4));
    *(void **)(this + 0x28) = pvVar2;
    return pvVar2;
  }
  return *(void **)(this + 0x28);
}
}

// =================================================
// Function: CPlugFileImg::CPlugFileImg
// =================================================
void __thiscall CPlugFileImg::CPlugFileImg(CPlugFileImg *this,CPlugFileImg *param_1)
{
{
  CPlugFile *unaff_ESI;
  
  CPlugFile::CPlugFile((CPlugFile *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x1c) = 1;
  *(undefined4 *)(this + 0x20) = 1;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(uint *)(this + 0x24) = *(uint *)(this + 0x24) & 0xfff0fa0d | 0x800d;
  return;
}
}

// =================================================
// Function: CPlugFileImg::ComputeByteSize
// =================================================
ulong __thiscall CPlugFileImg::ComputeByteSize(CPlugFileImg *this,CPlugFileImg *param_1,int param_2)
{
{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  uint uVar5;
  ulong uVar6;
  int iVar7;
  
  if ((param_1 == (CPlugFileImg *)0x0) || ((*(uint *)(this + 0x24) & 0xf8000) == 0x8000)) {
    uVar6 = 1;
  }
  else {
    uVar6 = *(uint *)(this + 0x24) >> 0xf & 0x1f;
  }
  uVar5 = *(uint *)(this + 0x24) & 3;
  uVar3 = *(uint *)(this + 0x24) >> 5 & 0xf;
  iVar1 = *(int *)(&DAT_00d11aa0 + uVar3 * 4);
  iVar2 = *(int *)(&DAT_00d11a78 + uVar3 * 4);
  iVar7 = (-(uint)(uVar5 != 2) & 0xfffffffb) + 6;
  if (iVar1 != 0) {
    if (uVar5 == 3) {
      uVar4 = *(ulong *)(this + 0x20);
    }
    else {
      uVar4 = 1;
    }
    uVar6 = GetMipMapTotalNbBlock4x4(*(ulong *)(this + 0x18),*(ulong *)(this + 0x1c),0,uVar6,uVar4);
    return uVar6 * iVar1 * iVar7;
  }
  if (uVar5 == 3) {
    uVar4 = *(ulong *)(this + 0x20);
  }
  else {
    uVar4 = 1;
  }
  uVar6 = GetMipMapTotalNbPixel(*(ulong *)(this + 0x18),*(ulong *)(this + 0x1c),0,uVar6,uVar4);
  return uVar6 * (*(uint *)(this + 0x24) >> 2 & 7) * iVar2 * iVar7;
}
}

// =================================================
// Function: CPlugFileImg::DeletePixels
// =================================================
void __thiscall CPlugFileImg::DeletePixels(CPlugFileImg *this,CPlugFileImg *param_1)
{
{
  switch(*(uint *)(this + 0x24) >> 5 & 0xf) {
  case 0:
  case 7:
    operator_delete__(*(void **)(this + 0x28));
    *(undefined4 *)(this + 0x28) = 0;
    return;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 8:
    operator_delete__(*(void **)(this + 0x28));
    *(undefined4 *)(this + 0x28) = 0;
    return;
  case 6:
  case 9:
    operator_delete__(*(void **)(this + 0x28));
    *(undefined4 *)(this + 0x28) = 0;
  }
  return;
}
}

// =================================================
// Function: CPlugFileImg::FilterWrappedPixel
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugFileImg::FilterWrappedPixel
          (CPlugFileImg *this,CPlugFileImg *param_1,GxBGRAColor_conflict *param_2,
          GxTexCoord *param_3,EGxTexFilter param_4,ulong param_5,ulong param_6,ECubeFace param_7,
          EGxTexAddress param_8)
{
{
  GxBGRAColor_conflict *pGVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uchar *puVar6;
  ulong uVar7;
  byte *extraout_EAX;
  int extraout_EAX_00;
  uint uVar8;
  byte *pbVar9;
  GxTexCoord *pGVar10;
  ECubeFace unaff_EBX;
  uint uVar11;
  GxBGRAColor_conflict *pGVar12;
  ulong unaff_EBP;
  ECubeFace unaff_ESI;
  GxTexCoord *pGVar13;
  ECubeFace unaff_EDI;
  float unaff_retaddr;
  GxBGRAColor_conflict *in_stack_00000024;
  uint in_stack_00000028;
  ulong in_stack_0000002c;
  uint in_stack_00000030;
  byte bStack00000034;
  byte bStack0000003c;
  GxTexCoord *pGVar14;
  GxBGRAColor_conflict *pGVar15;
  float fVar16;
  float local_20;
  float local_1c;
  CPlugFileImg *local_18;
  int local_c;
  float local_4;
  
  if (param_3 == (GxTexCoord *)0x0) {
    fVar16 = *(float *)param_2;
    local_1c = *(float *)(param_2 + 4);
    local_20 = fVar16;
    if (param_7 == 2) {
      local_20 = 0.0;
      if ((0.0 <= fVar16) && (local_20 = fVar16, (float)_DAT_00b37448 < fVar16)) {
        local_20 = _DAT_00bad9f4;
      }
      if (0.0 <= local_1c) {
        if ((float)_DAT_00b37448 < local_1c) {
          local_1c = _DAT_00bad9f4;
        }
      }
      else {
        local_1c = 0.0;
      }
    }
    puVar6 = GetWrappedPixel(this,(CPlugFileImg *)&local_20,(GxTexCoord *)param_6,unaff_EDI);
    uVar8 = *(uint *)(this + 0x24) >> 2 & 7;
    if (param_5 <= uVar8) {
      _memcpy(param_2,puVar6,param_5);
      return;
    }
    _memcpy(param_2,puVar6,uVar8);
    if (((byte)*(undefined4 *)(this + 0x24) & 0x1c) < 0xc) {
      param_2[1] = *param_2;
      param_2[2] = *param_2;
    }
    param_2[3] = (GxBGRAColor_conflict)0xff;
    return;
  }
  uVar8 = *(uint *)(this + 0x18);
  uVar11 = *(uint *)(this + 0x1c);
  for (uVar7 = param_5; uVar7 != 0; uVar7 = uVar7 - 1) {
    if (1 < uVar8) {
      uVar8 = uVar8 >> 1;
    }
    if (1 < uVar11) {
      uVar11 = uVar11 >> 1;
    }
  }
  fVar16 = (float)(int)uVar8;
  if ((int)uVar8 < 0) {
    fVar16 = fVar16 + _DAT_00c418d0;
  }
  fVar16 = fVar16 * *(float *)param_2;
  local_20 = (float)(int)uVar11;
  if ((int)uVar11 < 0) {
    local_20 = local_20 + _DAT_00c418d0;
  }
  local_20 = local_20 * *(float *)(param_2 + 4);
  pGVar14 = (GxTexCoord *)(int)ROUND((fVar16 - (float)_DAT_00b313b8) - (float)_DAT_00b313b8);
  pGVar1 = (GxBGRAColor_conflict *)
           (int)ROUND((local_20 - (float)_DAT_00b313b8) - (float)_DAT_00b313b8);
  pGVar15 = pGVar1 + 1;
  pGVar10 = pGVar14 + 1;
  if ((param_7 == 0) || (param_7 != 2)) {
    param_3 = (GxTexCoord *)((uint)(pGVar14 + uVar8 * 0x80) % uVar8);
    pGVar10 = (GxTexCoord *)((uint)(pGVar10 + uVar8 * 0x80) % uVar8);
    param_7 = (uint)(pGVar1 + uVar11 * 0x80) % uVar11;
    pGVar12 = (GxBGRAColor_conflict *)((uint)(pGVar15 + uVar11 * 0x80) % uVar11);
  }
  else {
    pGVar13 = (GxTexCoord *)(uVar8 - 1);
    if ((int)pGVar14 < 1) {
      param_3 = (GxTexCoord *)0x0;
    }
    else {
      param_3 = pGVar14;
      if ((int)pGVar13 <= (int)pGVar14) {
        param_3 = pGVar13;
      }
    }
    if ((int)pGVar10 < 1) {
      pGVar10 = (GxTexCoord *)0x0;
    }
    else if ((int)pGVar13 <= (int)pGVar10) {
      pGVar10 = pGVar13;
    }
    pGVar12 = (GxBGRAColor_conflict *)(uVar11 - 1);
    if ((int)pGVar1 < 1) {
      param_7 = (ECubeFace)(GxBGRAColor_conflict *)0x0;
    }
    else {
      param_7 = (ECubeFace)pGVar12;
      if ((int)pGVar1 < (int)pGVar12) {
        param_7 = (ECubeFace)pGVar1;
      }
    }
    if ((int)pGVar15 < 1) {
      pGVar12 = (GxBGRAColor_conflict *)0x0;
    }
    else if ((int)pGVar15 < (int)pGVar12) {
      pGVar12 = pGVar15;
    }
  }
  GetPixelMip(this,(CPlugFileImg *)param_3,(GxBGRAColor_conflict *)param_7,param_5,param_6,unaff_EBP
              ,unaff_EBX);
  GetPixelMip(this,(CPlugFileImg *)pGVar15,in_stack_00000024,param_7,param_6,unaff_EDI,unaff_ESI);
  GetPixelMip(this,(CPlugFileImg *)param_7,pGVar12,(ulong)in_stack_00000024,param_6,(ulong)pGVar10,
              (ECubeFace)pGVar14);
  GetPixelMip(this,local_18,pGVar12,in_stack_0000002c,param_6,(ulong)pGVar15,(ECubeFace)fVar16);
  local_4 = local_4 - ((float)local_c + (float)_DAT_00b313b8);
  fVar16 = unaff_retaddr - ((float)(int)in_stack_00000028 + (float)_DAT_00b313b8);
  fVar3 = (1.0 - local_4) * (1.0 - fVar16);
  fVar4 = local_4 * (1.0 - fVar16);
  fVar2 = (1.0 - local_4) * fVar16;
  fVar16 = fVar16 * local_4;
  uVar8 = *(uint *)(this + 0x24) >> 2 & 7;
  fVar5 = 1.0 / (fVar16 + fVar2 + fVar3 + fVar4);
  if (in_stack_00000030 <= uVar8) {
    if (in_stack_00000030 != 0) {
      pbVar9 = extraout_EAX;
      do {
        in_stack_00000030 = in_stack_00000030 - 1;
        bStack00000034 =
             (byte)(int)ROUND(((float)pbVar9[extraout_EAX_00 - (int)extraout_EAX] * fVar16 +
                              (float)pbVar9[param_6 - (int)extraout_EAX] * fVar2 +
                              (float)*pbVar9 * fVar3 +
                              (float)pbVar9[param_5 - (int)extraout_EAX] * fVar4) * fVar5);
        pbVar9[(int)in_stack_00000024 - (int)extraout_EAX] = bStack00000034;
        pbVar9 = pbVar9 + 1;
      } while (in_stack_00000030 != 0);
    }
    return;
  }
  in_stack_00000028 = 0;
  if (uVar8 != 0) {
    pbVar9 = extraout_EAX;
    do {
      bStack0000003c =
           (byte)(int)ROUND(((float)pbVar9[extraout_EAX_00 - (int)extraout_EAX] * fVar16 +
                            (float)pbVar9[param_6 - (int)extraout_EAX] * fVar2 +
                            (float)*pbVar9 * fVar3 +
                            (float)pbVar9[param_5 - (int)extraout_EAX] * fVar4) * fVar5);
      pbVar9[(int)in_stack_00000024 - (int)extraout_EAX] = bStack0000003c;
      in_stack_00000028 = in_stack_00000028 + 1;
      pbVar9 = pbVar9 + 1;
    } while (in_stack_00000028 < (*(uint *)(this + 0x24) >> 2 & 7));
  }
  if (((byte)*(undefined4 *)(this + 0x24) & 0x1c) < 0xc) {
    in_stack_00000024[1] = *in_stack_00000024;
    in_stack_00000024[2] = *in_stack_00000024;
  }
  in_stack_00000024[3] = (GxBGRAColor_conflict)0xff;
  return;
}
}

// =================================================
// Function: CPlugFileImg::Force1stPixelAlpha0
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall CPlugFileImg::Force1stPixelAlpha0(CPlugFileImg *this,CPlugFileImg *param_1)
{
{
  int iVar1;
  uchar *puVar2;
  byte *pbVar3;
  uint *puVar4;
  uint uVar5;
  GmNat3 *unaff_EBX;
  GmNat3 *unaff_ESI;
  ulong uVar6;
  GmNat3 *unaff_EDI;
  uint uVar7;
  undefined4 uStack_10;
  uint local_c;
  undefined1 uStack_8;
  undefined1 local_7;
  undefined1 local_6 [2];
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)&uStack_10;
  uVar5 = *(uint *)(this + 0x24) >> 5 & 0xf;
  uVar7 = *(uint *)(this + 0x24) >> 0xf & 0x1f;
  if (uVar7 == 0) {
    local_c = *(uint *)(this + 0x18);
    if (*(uint *)(this + 0x18) < *(uint *)(this + 0x1c)) {
      local_c = *(uint *)(this + 0x1c);
    }
    iVar1 = 0x1f;
    if (local_c != 0) {
      for (; local_c >> iVar1 == 0; iVar1 = iVar1 + -1) {
      }
    }
    uVar7 = iVar1 + 1;
  }
  if (uVar5 == 0) {
    if (((byte)*(undefined4 *)(this + 0x24) & 0x1c) < 0xd) {
      AddAlpha_BGRA(this,(CPlugFileImg *)0xff,(uchar)unaff_EDI);
    }
    uVar6 = 0;
    if (uVar7 != 0) {
      do {
        puVar2 = GetFaceLevel(this,(CPlugFileImg *)0x0,uVar6,0,(ulong *)0x0,unaff_ESI);
        uVar6 = uVar6 + 1;
        puVar2[3] = '\0';
      } while (uVar6 < uVar7);
      return;
    }
  }
  else if (uVar5 == 1) {
    GxBGRColor565::SetRGB8(&local_c,(GxBGRColor565 *)0x0,'\0','\0',(uchar)unaff_EBX);
    GxBGRColor565::SetRGB8(local_6,(GxBGRColor565 *)0xff,0xff,0xff,(uchar)unaff_EDI);
    uVar6 = 0;
    if (uVar7 != 0) {
      do {
        puVar2 = GetFaceLevel(this,(CPlugFileImg *)0x0,uVar6,0,(ulong *)0x0,unaff_ESI);
        uVar6 = uVar6 + 1;
        puVar2[0] = 0xff;
        puVar2[1] = 0xff;
        puVar2[2] = 0xff;
        puVar2[3] = 0xff;
        puVar2[4] = 0xff;
        puVar2[5] = 0xff;
        puVar2[6] = 0xff;
        puVar2[7] = 0xff;
      } while (uVar6 < uVar7);
      return;
    }
  }
  else if (uVar5 - 2 < 2) {
    uVar6 = 0;
    if (uVar7 != 0) {
      do {
        pbVar3 = GetFaceLevel(this,(CPlugFileImg *)0x0,uVar6,0,(ulong *)0x0,unaff_EBX);
        *pbVar3 = *pbVar3 & 0xf0;
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar7);
      return;
    }
  }
  else if (uVar5 - 4 < 2) {
    uStack_10 = (uint)(uint3)uStack_10;
    CFixedArray<unsigned_char,8,unsigned_long>::FillWith
              (&local_c,(CFixedArray<unsigned_char,8,unsigned_long> *)((int)&uStack_10 + 3),
               (uchar *)unaff_EBX);
    uVar5 = local_4;
    uVar6 = 0;
    _uStack_8 = CONCAT11(0xff,uStack_8);
    if (uVar7 != 0) {
      do {
        puVar4 = (uint *)GetFaceLevel(this,(CPlugFileImg *)0x0,uVar6,0,(ulong *)0x0,unaff_EDI);
        if (*(byte *)((int)puVar4 + 1) < (byte)*puVar4) {
          *puVar4 = local_4;
          puVar4[1] = uVar5;
        }
        else {
          *(byte *)((int)puVar4 + 2) = *(byte *)((int)puVar4 + 2) & 0xfe | 6;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar7);
    }
  }
  return;
}
}

// =================================================
// Function: CPlugFileImg::ForceBorders_BGRA
// =================================================
void __thiscall
CPlugFileImg::ForceBorders_BGRA
          (CPlugFileImg *this,CPlugFileImg *param_1,GxBGRAColor_conflict *param_2,int param_3,
          int param_4,ulong param_5)
{
{
  uint uVar1;
  uchar *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  GmNat3 *unaff_ESI;
  int iVar9;
  uchar unaff_DI;
  uchar *puVar10;
  int iVar11;
  int unaff_retaddr;
  uchar *in_stack_00000018;
  uint local_10;
  uint local_c;
  uint local_8;
  int local_4;
  
  if ((uint)param_4 < 2) {
    param_4 = 1;
  }
  uVar1 = *(uint *)(this + 0x1c);
  if ((((byte)*(undefined4 *)(this + 0x24) & 0x1c) < 0xd) && (param_3 != 0)) {
    AddAlpha_BGRA(this,(CPlugFileImg *)0xff,unaff_DI);
  }
  uVar7 = *(uint *)(this + 0x24) >> 2 & 7;
  puVar2 = GetFaceLevel(this,(CPlugFileImg *)0x0,0,0,(ulong *)0x0,unaff_ESI);
  iVar9 = (-(uint)(param_4 != 0) & 0xfffffffd) + 3;
  uVar3 = (param_5 != 0) + 3;
  puVar10 = puVar2;
  uVar6 = param_4;
  param_5 = uVar7;
  if (uVar3 < uVar7) {
    param_5 = uVar3;
  }
  for (; param_4 != 0; param_4 = param_4 + -1) {
    if (uVar1 != 0) {
      local_10 = uVar1;
      do {
        _memcpy(puVar10 + iVar9,(void *)(iVar9 + param_3),param_5 - iVar9);
        puVar10 = puVar10 + uVar7;
        local_10 = local_10 - 1;
        uVar6 = (uint)in_stack_00000018;
      } while (local_10 != 0);
    }
  }
  if (uVar6 < local_c) {
    iVar4 = uVar7 * uVar6;
    local_4 = local_c - uVar6;
    do {
      if (uVar6 != 0) {
        local_8 = (uint)in_stack_00000018;
        do {
          _memcpy(puVar10 + iVar9,(void *)(iVar9 + param_3),param_5 - iVar9);
          puVar10 = puVar10 + uVar7;
          local_8 = local_8 - 1;
          uVar6 = (uint)in_stack_00000018;
        } while (local_8 != 0);
      }
      puVar10 = puVar10 + (unaff_retaddr - iVar4);
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  iVar4 = unaff_retaddr * uVar6;
  uVar3 = local_c - uVar6;
  iVar11 = (int)puVar10 - iVar4;
  if (uVar3 < local_c) {
    iVar5 = uVar7 * uVar6;
    param_4 = local_c - uVar3;
    do {
      iVar11 = iVar11 + iVar5;
      if (uVar6 < uVar1) {
        iVar8 = uVar1 - (int)in_stack_00000018;
        do {
          _memcpy((void *)(iVar9 + iVar11),(void *)(param_3 + iVar9),param_5 - iVar9);
          iVar11 = iVar11 + uVar7;
          iVar8 = iVar8 + -1;
          uVar6 = (uint)in_stack_00000018;
        } while (iVar8 != 0);
      }
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  in_stack_00000018 = puVar2 + iVar4;
  if (uVar6 < local_c) {
    uVar6 = uVar1 - uVar6;
    do {
      in_stack_00000018 = in_stack_00000018 + uVar6 * uVar7;
      if (uVar6 < uVar1) {
        iVar4 = uVar1 - uVar6;
        do {
          _memcpy(in_stack_00000018 + iVar9,(void *)(iVar9 + param_3),param_5 - iVar9);
          in_stack_00000018 = in_stack_00000018 + uVar7;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}
}

// =================================================
// Function: CPlugFileImg::GetByteSizePerComp
// =================================================
ulong __thiscall CPlugFileImg::GetByteSizePerComp(CPlugFileImg *this,CPlugFileImg *param_1)
{
{
  return *(ulong *)(&DAT_00d11a78 + (*(uint *)(this + 0x24) >> 5 & 0xf) * 4);
}
}

// =================================================
// Function: CPlugFileImg::GetFaceLevel
// =================================================
uchar * __thiscall
CPlugFileImg::GetFaceLevel
          (CPlugFileImg *this,CPlugFileImg *param_1,ulong param_2,ulong param_3,ulong *param_4,
          GmNat3 *param_5)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  int iVar7;
  ulong uVar8;
  uint local_18;
  int local_14;
  uint local_8;
  
  local_14 = *(int *)(this + 0x28);
  local_8 = *(uint *)(this + 0x1c);
  uVar6 = *(ulong *)(this + 0x20);
  uVar5 = *(uint *)(this + 0x24) >> 5 & 0xf;
  iVar7 = 0;
  uVar8 = *(ulong *)(this + 0x18);
  if (uVar5 != 9) {
    iVar1 = *(int *)(&DAT_00d11aa0 + uVar5 * 4);
    iVar2 = *(int *)(&DAT_00d11a78 + uVar5 * 4);
    uVar5 = *(uint *)(this + 0x24) >> 0xf & 0x1f;
    if (iVar1 == 0) {
      uVar3 = GetMipMapTotalNbPixel(uVar8,local_8,0,uVar5,uVar6);
      iVar4 = (*(uint *)(this + 0x24) >> 2 & 7) * uVar3 * iVar2;
      local_18 = 0;
    }
    else {
      uVar3 = GetMipMapTotalNbBlock4x4(uVar8,local_8,0,uVar5,uVar6);
      iVar4 = uVar3 * iVar1;
      local_18 = 0;
    }
    do {
      if (local_18 != 0) {
        local_14 = local_14 + iVar7;
        if (1 < uVar8) {
          uVar8 = uVar8 >> 1;
        }
        if (1 < local_8) {
          local_8 = local_8 >> 1;
        }
        if (1 < uVar6) {
          uVar6 = uVar6 >> 1;
        }
      }
      if (iVar1 == 0) {
        iVar7 = (*(uint *)(this + 0x24) >> 2 & 7) * uVar6 * local_8 * uVar8 * iVar2;
      }
      else {
        iVar7 = (local_8 + 3 >> 2) * (uVar8 + 3 >> 2) * uVar6 * iVar1;
      }
      local_18 = local_18 + 1;
    } while (local_18 <= param_2);
    if (param_3 != 0) {
      *(int *)param_3 = iVar7;
    }
    if (param_4 != (ulong *)0x0) {
      *param_4 = uVar8;
      param_4[1] = local_8;
      param_4[2] = uVar6;
    }
    return (uchar *)(iVar4 * (int)param_1 + local_14);
  }
  if (param_3 != 0) {
    *(undefined4 *)param_3 = *(undefined4 *)(this + 0x2c);
  }
  if (param_4 != (ulong *)0x0) {
    *param_4 = uVar8;
    param_4[1] = local_8;
    param_4[2] = uVar6;
  }
  return *(uchar **)(this + 0x28);
}
}

// =================================================
// Function: CPlugFileImg::GetMipMapTotalNbBlock4x4
// =================================================
ulong __cdecl
CPlugFileImg::GetMipMapTotalNbBlock4x4
          (ulong param_1,ulong param_2,ulong param_3,ulong param_4,ulong param_5)
{
{
  int iVar1;
  ulong uVar2;
  bool bVar3;
  
  bVar3 = false;
  iVar1 = 0;
  if (param_1 != 0) {
    for (; (param_1 >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
    }
  }
  if (param_1 != 0) {
    bVar3 = param_1 >> ((char)iVar1 + 1U & 0x1f) == 0;
  }
  if (bVar3) {
    bVar3 = false;
    iVar1 = 0;
    if (param_2 != 0) {
      for (; (param_2 >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
      }
    }
    if (param_2 != 0) {
      bVar3 = param_2 >> ((char)iVar1 + 1U & 0x1f) == 0;
    }
    if ((bVar3) && (iVar1 = 0, param_5 != 0)) {
      for (; (param_5 >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
      }
    }
  }
  while ((param_3 != 0 && (((1 < param_1 || (1 < param_2)) || (1 < param_5))))) {
    param_3 = param_3 - 1;
    if (1 < param_1) {
      param_1 = param_1 >> 1;
    }
    if (1 < param_2) {
      param_2 = param_2 >> 1;
    }
    if (1 < param_5) {
      param_5 = param_5 >> 1;
    }
  }
  uVar2 = 0;
  if (param_4 == 0) {
    param_4 = 0xffffffff;
  }
  else if (param_4 == 0) {
    return 0;
  }
  do {
    if (((param_1 < 2) && (param_2 < 2)) && (param_5 < 2)) {
      if (param_4 != 0) {
        uVar2 = uVar2 + 1;
      }
      return uVar2;
    }
    uVar2 = uVar2 + (param_2 + 3 >> 2) * (param_1 + 3 >> 2) * param_5;
    if (1 < param_1) {
      param_1 = param_1 >> 1;
    }
    if (1 < param_2) {
      param_2 = param_2 >> 1;
    }
    if (1 < param_5) {
      param_5 = param_5 >> 1;
    }
    param_4 = param_4 - 1;
  } while (param_4 != 0);
  return uVar2;
}
}

// =================================================
// Function: CPlugFileImg::GetMipMapTotalNbPixel
// =================================================
ulong __cdecl
CPlugFileImg::GetMipMapTotalNbPixel
          (ulong param_1,ulong param_2,ulong param_3,ulong param_4,ulong param_5)
{
{
  int iVar1;
  ulong uVar2;
  bool bVar3;
  
  bVar3 = false;
  iVar1 = 0;
  if (param_1 != 0) {
    for (; (param_1 >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
    }
  }
  if (param_1 != 0) {
    bVar3 = param_1 >> ((char)iVar1 + 1U & 0x1f) == 0;
  }
  if (bVar3) {
    bVar3 = false;
    iVar1 = 0;
    if (param_2 != 0) {
      for (; (param_2 >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
      }
    }
    if (param_2 != 0) {
      bVar3 = param_2 >> ((char)iVar1 + 1U & 0x1f) == 0;
    }
    if (bVar3) {
      bVar3 = false;
      iVar1 = 0;
      if (param_5 != 0) {
        for (; (param_5 >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
        }
      }
      if (param_5 != 0) {
        bVar3 = param_5 >> ((char)iVar1 + 1U & 0x1f) == 0;
      }
      if (bVar3) {
        bVar3 = true;
        goto LAB_0084f407;
      }
    }
  }
  bVar3 = false;
LAB_0084f407:
  if ((((param_3 == 0) && (param_4 == 0)) && (param_5 == 1)) && (bVar3)) {
    if ((param_1 == param_2) && (param_1 < 0x1001)) {
      iVar1 = 0x1f;
      if (param_1 != 0) {
        for (; param_1 >> iVar1 == 0; iVar1 = iVar1 + -1) {
        }
      }
      return (&DAT_00d11ac8)[iVar1];
    }
    if (param_1 == 1) {
      return param_2 * 2 - 1;
    }
    if (param_2 == 1) {
      return param_1 * 2 - 1;
    }
  }
  while ((param_3 != 0 && (((1 < param_1 || (1 < param_2)) || (1 < param_5))))) {
    param_3 = param_3 - 1;
    if (1 < param_1) {
      param_1 = param_1 >> 1;
    }
    if (1 < param_2) {
      param_2 = param_2 >> 1;
    }
    if (1 < param_5) {
      param_5 = param_5 >> 1;
    }
  }
  uVar2 = param_5 * param_2 * param_1;
  do {
    param_4 = param_4 - 1;
    if (param_4 == 0) {
      return uVar2;
    }
    if (param_1 < 2) {
      if (param_2 < 2) {
        if (param_5 < 2) {
          return uVar2;
        }
        goto LAB_0084f4b3;
      }
LAB_0084f4b8:
      param_2 = param_2 >> 1;
    }
    else {
      param_1 = param_1 >> 1;
LAB_0084f4b3:
      if (1 < param_2) goto LAB_0084f4b8;
    }
    if (1 < param_5) {
      param_5 = param_5 >> 1;
    }
    uVar2 = uVar2 + param_5 * param_2 * param_1;
  } while( true );
}
}

// =================================================
// Function: CPlugFileImg::GetPixel
// =================================================
uchar * __thiscall
CPlugFileImg::GetPixel(CPlugFileImg *this,CPlugFileImg *param_1,ulong param_2,ulong param_3)
{
{
  return (uchar *)((int)(param_1 + *(int *)(this + 0x18) * param_2) *
                   (*(uint *)(this + 0x24) >> 2 & 7) + *(int *)(this + 0x28));
}
}

// =================================================
// Function: CPlugFileImg::GetPixelMip
// =================================================
void __thiscall
CPlugFileImg::GetPixelMip
          (CPlugFileImg *this,CPlugFileImg *param_1,GxBGRAColor_conflict *param_2,ulong param_3,
          ulong param_4,ulong param_5,ECubeFace param_6)
{
{
  uchar *puVar1;
  undefined4 *puVar2;
  int iVar3;
  GmNat3 *unaff_EDI;
  uint uVar4;
  ulong local_c;
  int local_8;
  
  uVar4 = *(uint *)(this + 0x24) >> 5 & 0xf;
  puVar1 = GetFaceLevel(this,(CPlugFileImg *)param_5,param_4,0,&local_c,unaff_EDI);
  if (uVar4 == 0) {
    iVar3 = (local_8 * param_4 + param_3) * (*(uint *)(this + 0x24) >> 2 & 7);
    *param_2 = *(GxBGRAColor_conflict *)(puVar1 + iVar3);
    param_2[1] = *(GxBGRAColor_conflict *)(puVar1 + iVar3 + 1);
    param_2[2] = *(GxBGRAColor_conflict *)(puVar1 + iVar3 + 2);
    if (0xf < ((byte)*(undefined4 *)(this + 0x24) & 0x1c)) {
      param_2[3] = *(GxBGRAColor_conflict *)(puVar1 + iVar3 + 3);
      return;
    }
    param_2[3] = (GxBGRAColor_conflict)0xff;
  }
  else if (uVar4 < 6) {
    puVar2 = (undefined4 *)
             GxDXT1_Block::GetTexel
                       (puVar1 + ((local_8 + 3U >> 2) * (param_4 >> 2) + (param_3 >> 2)) *
                                 *(int *)(&DAT_00d11aa0 + uVar4 * 4),(GxDXT1_Block *)&param_4,
                        param_3 & 3,param_4 & 3);
    *(undefined4 *)param_2 = *puVar2;
    return;
  }
  return;
}
}

// =================================================
// Function: CPlugFileImg::GetWrappedPixel
// =================================================
uchar * __thiscall
CPlugFileImg::GetWrappedPixel
          (CPlugFileImg *this,CPlugFileImg *param_1,GxTexCoord *param_2,ECubeFace param_3)
{
{
  GxTexCoord *extraout_EAX;
  CPlugFileImg *extraout_EAX_00;
  uchar *puVar1;
  GxTexCoord *pGVar2;
  
  __ftol2_sse();
  pGVar2 = extraout_EAX;
  __ftol2_sse();
  puVar1 = GetWrappedPixel(this,extraout_EAX_00,pGVar2,(ECubeFace)param_2);
  return puVar1;
}
}

// =================================================
// Function: CPlugFileImg::IsInSystemMemory
// =================================================
int __thiscall CPlugFileImg::IsInSystemMemory(CPlugFileImg *this,CPlugFileImg *param_1)
{
{
  return (uint)(*(int *)(this + 0x28) != 0);
}
}

// =================================================
// Function: CPlugFileImg::ReGenerateForceTexelLoading
// =================================================
int __thiscall CPlugFileImg::ReGenerateForceTexelLoading(CPlugFileImg *this,CPlugFileImg *param_1)
{
{
  int iVar1;
  
  DAT_00d6e6c0 = DAT_00d6e6c0 + 1;
  iVar1 = (**(code **)(*(int *)this + 0x80))();
  DAT_00d6e6c0 = DAT_00d6e6c0 + -1;
  return iVar1;
}
}

// =================================================
// Function: CPlugFileImg::SetPixelFromNormal
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugFileImg::SetPixelFromNormal
          (CPlugFileImg *this,CPlugFileImg *param_1,ushort *param_2,GmVec3 *param_3)
{
{
  float fVar1;
  CPlugFileImg *pCVar2;
  undefined2 local_10;
  float local_c;
  float local_8;
  float local_4;
  
  pCVar2 = param_1;
  local_4 = (float)_DAT_00b530f8;
  local_c = (*(float *)param_2 + 1.0) * local_4;
  local_8 = (*(float *)(param_2 + 2) + 1.0) * local_4;
  local_4 = local_4 * (*(float *)(param_2 + 4) + 1.0);
  fVar1 = (float)_DAT_00b52a58;
  if (fVar1 < local_c) {
    local_c = _DAT_00b9f5d8;
  }
  if (fVar1 < local_8) {
    local_8 = _DAT_00b9f5d8;
  }
  if (fVar1 < local_4) {
    local_4 = _DAT_00b9f5d8;
  }
  if (local_c < 0.0) {
    local_c = 0.0;
  }
  if (local_8 < 0.0) {
    local_8 = 0.0;
  }
  if (local_4 < 0.0) {
    local_4 = 0.0;
  }
  local_10 = (undefined2)(int)ROUND(local_c);
  *(undefined2 *)param_1 = local_10;
  param_1._0_2_ = (undefined2)(int)ROUND(local_8);
  *(undefined2 *)(pCVar2 + 2) = param_1._0_2_;
  if (0xb < ((byte)*(undefined4 *)(this + 0x24) & 0x1c)) {
    param_1._0_2_ = (undefined2)(int)ROUND(local_4);
    *(undefined2 *)(pCVar2 + 4) = param_1._0_2_;
  }
  return;
}
}

// =================================================
// Function: CPlugFileImg::SetPixels
// =================================================
void __thiscall
CPlugFileImg::SetPixels
          (CPlugFileImg *this,CPlugFileImg *param_1,SDesc *param_2,uchar *param_3,ulong param_4)
{
{
  uint uVar1;
  longlong lVar2;
  ulong uVar3;
  uchar *puVar4;
  int iVar5;
  CPlugFileImg *unaff_ESI;
  CPlugFileImg *unaff_EDI;
  
  DeletePixels(this,unaff_EDI);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)param_2;
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_2 + 0xc);
  uVar1 = *(uint *)(param_2 + 0xc);
  uVar3 = GetMipMapTotalNbPixel
                    (*(ulong *)param_2,*(ulong *)(param_2 + 4),0,uVar1 >> 0xf & 0x1f,
                     *(ulong *)(param_2 + 8));
  iVar5 = uVar3 * ((-(uint)(((byte)uVar1 & 3) != 2) & 0xfffffffb) + 6);
  puVar4 = param_3;
  switch(*(uint *)(this + 0x24) >> 5 & 0xf) {
  case 0:
    if (param_3 == (uchar *)0x0) {
      puVar4 = operator_new__((*(uint *)(param_2 + 0xc) >> 2 & 7) * iVar5);
    }
    *(uchar **)(this + 0x28) = puVar4;
    if (param_3 != (uchar *)0x0) {
      return;
    }
    _memset(puVar4,0,(*(uint *)(param_2 + 0xc) >> 2 & 7) * iVar5);
    return;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
    if ((param_3 != (uchar *)0x0) && (param_4 != 0)) {
      *(uchar **)(this + 0x28) = param_3;
      *(ulong *)(this + 0x2c) = param_4;
      return;
    }
    AllocatePixels(this,unaff_ESI);
    return;
  case 6:
  case 7:
    if (param_3 == (uchar *)0x0) {
      lVar2 = (ulonglong)((*(uint *)(param_2 + 0xc) >> 2 & 7) * iVar5) * 2;
      puVar4 = operator_new__(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
    }
    *(uchar **)(this + 0x28) = puVar4;
    if (param_3 != (uchar *)0x0) {
      return;
    }
    iVar5 = (*(uint *)(param_2 + 0xc) >> 2 & 7) * iVar5;
    break;
  case 8:
    if (param_3 == (uchar *)0x0) {
      lVar2 = (ulonglong)((*(uint *)(param_2 + 0xc) >> 2 & 7) * iVar5) * 4;
      puVar4 = operator_new__(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
    }
    *(uchar **)(this + 0x28) = puVar4;
    if (param_3 != (uchar *)0x0) {
      return;
    }
    iVar5 = (*(uint *)(param_2 + 0xc) >> 2 & 7) * iVar5 * 2;
    break;
  default:
    goto switchD_0084fc50_default;
  }
  _memset(puVar4,0,iVar5 * 2);
switchD_0084fc50_default:
  return;
}
}

