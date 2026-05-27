// Class implementation: CGameCtnArticle

// =================================================
// Function: CGameCtnArticle::CreateIcon
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CFuncEnum * __thiscall
CGameCtnArticle::CreateIcon
          (CGameCtnArticle *this,CGameCtnArticle *param_1,ulong param_2,int param_3)
{
{
  CPlugShaderApply *pCVar1;
  CFuncEnum *pCVar2;
  CFuncEnum *extraout_EAX;
  CPlugShaderApply *pCVar3;
  CPlugShaderGeneric *extraout_EAX_00;
  CPlugShaderGeneric *extraout_EAX_01;
  EGxBlendFactor unaff_EBX;
  ulong unaff_ESI;
  CPlugShaderGeneric *pCVar4;
  CFuncEnum *unaff_EDI;
  undefined4 uStack00000010;
  void *in_stack_00000014;
  CPlugShaderApply *pCStack00000018;
  EGxBlendFactor in_stack_ffffffd4;
  GxColor *pGVar5;
  ulong uVar6;
  EGxBlendFactor EVar7;
  EGxBlendFactor EVar8;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00ab2201;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar4 = (CPlugShaderGeneric *)0x0;
  if (((param_2 == 0) || (param_1 != (CGameCtnArticle *)0xffffffff)) ||
     (pCVar1 = *(CPlugShaderApply **)(this + 0x24), pCVar1 == (CPlugShaderApply *)0x0)) {
    pCVar1 = (CPlugShaderApply *)
             GetSkinIconByIndex(this,param_1,DAT_00cca150 ^ (uint)&stack0xffffffc8);
  }
  pCVar2 = operator_new(0x50);
  if (pCVar2 == (CFuncEnum *)0x0) {
    pCVar2 = (CFuncEnum *)0x0;
  }
  else {
    CFuncEnum::CFuncEnum(pCVar2,unaff_EDI);
    pCVar2 = extraout_EAX;
  }
  CControlButton::InitFuncEnum(pCVar2);
  pCVar3 = operator_new(0xa8);
  if (pCVar3 != (CPlugShaderApply *)0x0) {
    CPlugShaderApply::CPlugShaderApply(pCVar3,(CPlugShaderApply *)unaff_EDI);
    pCVar4 = extraout_EAX_00;
  }
  pGVar5 = (GxColor *)0x3f800000;
  uVar6 = 0x3f800000;
  EVar7 = 0x3f800000;
  EVar8 = 0x3f800000;
  CPlugShaderGeneric::SetVertexColor
            (pCVar4,(CPlugShaderGeneric *)0x0,(EPlugShaderVertexColor)&stack0xffffffd8,
             (GxColor *)unaff_EDI);
  if (pCVar1 != (CPlugShaderApply *)0x0) {
    CPlugShaderApply::AddTextureApply
              ((CPlugShaderApply *)pCVar4,pCVar1,(CPlugBitmap *)0x1,0,unaff_ESI);
  }
  CPlugShaderApply::SetBlending
            ((CPlugShaderApply *)pCVar4,(CPlugShaderPass *)0x1,unaff_EBX,in_stack_ffffffd4);
  pCVar3 = (CPlugShaderApply *)0x0;
  CFuncEnum::SetValue(pCVar2,(CMwCmdAffectParamBool *)pCVar4);
  pCStack00000018 = operator_new(0xa8);
  if (pCStack00000018 == (CPlugShaderApply *)0x0) {
    pCVar4 = (CPlugShaderGeneric *)0x0;
  }
  else {
    CPlugShaderApply::CPlugShaderApply(pCStack00000018,pCVar3);
    pCVar4 = extraout_EAX_01;
  }
  puStack_8 = _DAT_00b36144;
  puStack_4 = _DAT_00b36144;
  uStack00000010 = 0xffffffff;
  CPlugShaderGeneric::SetVertexColor
            (pCVar4,(CPlugShaderGeneric *)0x0,(EPlugShaderVertexColor)&puStack_8,pGVar5);
  if (pCVar1 != (CPlugShaderApply *)0x0) {
    CPlugShaderApply::AddTextureApply((CPlugShaderApply *)pCVar4,pCVar1,(CPlugBitmap *)0x1,0,uVar6);
  }
  CPlugShaderApply::SetBlending((CPlugShaderApply *)pCVar4,(CPlugShaderPass *)0x1,EVar7,EVar8);
  CFuncEnum::SetValue(pCVar2,(CMwCmdAffectParamBool *)pCVar4);
  ExceptionList = in_stack_00000014;
  return pCVar2;
}
}

// =================================================
// Function: CGameCtnArticle::GetDefaultSkinChecksum
// =================================================
void __thiscall
CGameCtnArticle::GetDefaultSkinChecksum
          (CGameCtnArticle *this,CGameCtnArticle *param_1,SNat128 *param_2)
{
{
  CGameCtnArticle *pCVar1;
  ulong unaff_ESI;
  SNat128 *unaff_retaddr;
  
  pCVar1 = (CGameCtnArticle *)GetDefaultSkinIndex(this,param_1);
  GetSkinChecksum(this,pCVar1,unaff_ESI,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CGameCtnArticle::GetDefaultSkinIndex
// =================================================
ulong __thiscall
CGameCtnArticle::GetDefaultSkinIndex(CGameCtnArticle *this,CGameCtnArticle *param_1)
{
{
  ulong uVar1;
  CFastStringInt *unaff_retaddr;
  
  uVar1 = GetSkinIndexFromDisplayName(this,(CGameCtnArticle *)&DAT_00d69ea0,unaff_retaddr);
  return uVar1;
}
}

// =================================================
// Function: CGameCtnArticle::GetSkinChecksum
// =================================================
void __thiscall
CGameCtnArticle::GetSkinChecksum
          (CGameCtnArticle *this,CGameCtnArticle *param_1,ulong param_2,SNat128 *param_3)
{
{
  int iVar1;
  CGameCtnArticle *pCVar2;
  SCasterCat *pSVar3;
  SNat128 *unaff_ESI;
  CGameCtnArticle *this_00;
  CGameCtnArticle *unaff_EDI;
  ulong unaff_retaddr;
  undefined4 *in_stack_00000014;
  undefined4 *in_stack_00000018;
  
  if (param_1 == (CGameCtnArticle *)0xffffffff) {
    iVar1 = HasDefaultSkin(this,unaff_EDI);
    if (iVar1 != 0) {
      GetDefaultSkinChecksum(this,(CGameCtnArticle *)param_3,unaff_ESI);
      return;
    }
  }
  this_00 = this + 0x90;
  pCVar2 = (CGameCtnArticle *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this_00,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
  if (param_1 < pCVar2) {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                        unaff_retaddr);
    if (*(int *)pSVar3 != 0) {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                          (ulong)param_1);
      iVar1 = *(int *)pSVar3;
      *in_stack_00000018 = *(undefined4 *)(iVar1 + 0x38);
      in_stack_00000018[1] = *(undefined4 *)(iVar1 + 0x3c);
      in_stack_00000018[2] = *(undefined4 *)(iVar1 + 0x40);
      in_stack_00000018[3] = *(undefined4 *)(iVar1 + 0x44);
      return;
    }
  }
  *in_stack_00000014 = DAT_00d55a00;
  in_stack_00000014[1] = DAT_00d55a04;
  in_stack_00000014[2] = DAT_00d55a08;
  in_stack_00000014[3] = DAT_00d55a0c;
  return;
}
}

// =================================================
// Function: CGameCtnArticle::GetSkinDisplayName
// =================================================
void __thiscall
CGameCtnArticle::GetSkinDisplayName
          (CGameCtnArticle *this,CGameSkin *param_1,CSystemPackDesc *param_2,CFastStringInt *param_3
          )
{
{
  wchar_t wVar1;
  CGameSkin *this_00;
  CSystemPackDesc *pCVar2;
  SCasterCat *pSVar3;
  wchar_t *pwVar4;
  wchar_t *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CSystemPackDesc *in_stack_00000010;
  CFastStringInt *in_stack_fffffff4;
  wchar_t *local_4;
  
  pCVar2 = (CSystemPackDesc *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x90,unaff_EDI);
  if ((param_2 < pCVar2) && (this_00 = *(CGameSkin **)(this + 0x58), this_00 != (CGameSkin *)0x0)) {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x90,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                        (ulong)unaff_ESI);
    CGameSkin::GetSkinDisplayName(this_00,*(CGameSkin **)pSVar3,in_stack_00000010,in_stack_fffffff4)
    ;
    return;
  }
  local_4 = CClassicI18n::GetTranslatedStringInternal
                      ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"|SkinName|Default",unaff_ESI)
  ;
  pwVar4 = local_4;
  if (local_4 != (wchar_t *)0x0) {
    do {
      wVar1 = *pwVar4;
      pwVar4 = pwVar4 + 1;
    } while (wVar1 != L'\0');
  }
  CFastStringInt::SetString
            (in_stack_00000010,(CFastStringInt *)&local_4,(SStringParam *)in_stack_fffffff4);
  return;
}
}

// =================================================
// Function: CGameCtnArticle::GetSkinIconByChecksum
// =================================================
CPlugBitmap * __thiscall
CGameCtnArticle::GetSkinIconByChecksum
          (CGameCtnArticle *this,CGameCtnArticle *param_1,SNat128 *param_2)
{
{
  CGameSkin *this_00;
  CPlugBitmap *pCVar1;
  undefined1 *puVar2;
  ulong uVar3;
  CPlugBitmap *extraout_EAX;
  CPlugBitmap *extraout_EAX_00;
  CSystemPackDesc *unaff_ESI;
  CFastStringInt *unaff_EDI;
  CPlugBitmap *pCStack00000010;
  CPlugBitmap *pCStack00000018;
  EMwIconList *pEVar4;
  EGxTexAddress EVar5;
  EMwIconList *pEVar6;
  CPlugBitmap *pCVar7;
  
  pCVar7 = (CPlugBitmap *)0xffffffff;
  pEVar6 = (EMwIconList *)&LAB_00ab20db;
  puVar2 = &stack0xfffffff4;
  if ((*(CGameSkin **)(this + 0x58) != (CGameSkin *)0x0) &&
     (pEVar4 = ExceptionList, ExceptionList = &stack0xfffffff4,
     uVar3 = CGameSkin::GetIconIndex
                       (*(CGameSkin **)(this + 0x58),
                        (CGameSkin *)(DAT_00cca150 ^ (uint)&stack0xffffffec)),
     puVar2 = ExceptionList, uVar3 != 0xffffffff)) {
    this_00 = *(CGameSkin **)(this + 0x58);
    unaff_ESI = CSystemPackManager::FindPackDesc
                          (DAT_00d54250,(CSystemPackManager *)param_2,unaff_EDI,(int)unaff_ESI);
    CGameSkin::GetIcon(this_00,(CMwParamFastBuffer<class_CMwParamVec4> *)unaff_ESI,pEVar4,pEVar6);
    puVar2 = ExceptionList;
    if (extraout_EAX != (CPlugBitmap *)0x0) {
      ExceptionList = param_2;
      return extraout_EAX;
    }
  }
  ExceptionList = puVar2;
  pCVar1 = *(CPlugBitmap **)(this + 0x24);
  if (pCVar1 == (CPlugBitmap *)0x0) {
    uVar3 = 0x78;
    EVar5 = 0x699f82;
    pCStack00000018 = operator_new(0x78);
    pCStack00000010 = pCVar1;
    if (pCStack00000018 == (CPlugBitmap *)0x0) {
      pCVar7 = (CPlugBitmap *)0x0;
    }
    else {
      uVar3 = 0x699f98;
      CPlugBitmap::CPlugBitmap(pCStack00000018,pCVar7);
      pCVar7 = extraout_EAX_00;
    }
    CPlugBitmap::SetMipMapping(pCVar7,(CPlugBitmap *)0x0,(int)unaff_ESI);
    CPlugBitmap::SetDefaultTexAddress(pCVar7,(CPlugBitmap *)0x2,2,0,EVar5);
    CPlugBitmap::GenerateChecker(pCVar7,(CPlugBitmap *)0x0,uVar3);
  }
  ExceptionList = param_2;
  return pCVar1;
}
}

// =================================================
// Function: CGameCtnArticle::GetSkinIconByIndex
// =================================================
CPlugBitmap * __thiscall
CGameCtnArticle::GetSkinIconByIndex(CGameCtnArticle *this,CGameCtnArticle *param_1,ulong param_2)
{
{
  CPlugBitmap *pCVar1;
  SNat128 *unaff_ESI;
  SNat128 *in_stack_fffffff0;
  CGameCtnArticle local_c [12];
  
  GetSkinChecksum(this,param_1,(ulong)&stack0xfffffff0,unaff_ESI);
  pCVar1 = GetSkinIconByChecksum(this,local_c,in_stack_fffffff0);
  return pCVar1;
}
}

// =================================================
// Function: CGameCtnArticle::GetSkinIndexFromDisplayName
// =================================================
ulong __thiscall
CGameCtnArticle::GetSkinIndexFromDisplayName
          (CGameCtnArticle *this,CGameCtnArticle *param_1,CFastStringInt *param_2)
{
{
  CGameSkin *pCVar1;
  int iVar2;
  undefined *unaff_ESI;
  CGameSkin *pCVar3;
  CFastStringInt *unaff_EDI;
  void *in_stack_0000000c;
  undefined4 local_1c;
  undefined *local_18;
  undefined *local_14;
  undefined *local_10;
  undefined *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00ab2158;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = (CGameSkin *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this + 0x90,
                      (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffd0));
  pCVar3 = (CGameSkin *)0x0;
  if (pCVar1 != (CGameSkin *)0x0) {
    do {
      local_1c = 0;
      local_18 = PTR_DAT_00bbf7dc;
      GetSkinDisplayName(this,pCVar3,(CSystemPackDesc *)&local_1c,unaff_EDI);
      unaff_EDI = (CFastStringInt *)0x0;
      local_10 = local_14;
      local_c = local_18;
      local_8 = (undefined1 *)0x0;
      iVar2 = CFastStringInt::CompareNoCase
                        (in_stack_0000000c,(CFastStringInt *)&local_10,(SStringParam *)0x0,
                         (ulong)unaff_ESI);
      if (iVar2 == 0) {
        if (local_10 == PTR_DAT_00bbf7dc) {
          ExceptionList = local_8;
          return (ulong)pCVar3;
        }
        if ((local_10[-1] & 0x80) == 0) {
          operator_delete__(local_10 + -2);
          ExceptionList = local_8;
          return (ulong)pCVar3;
        }
        operator_delete__(local_10 + -4);
        ExceptionList = local_8;
        return (ulong)pCVar3;
      }
      if (local_10 != PTR_DAT_00bbf7dc) {
        unaff_ESI = local_10 + -4;
        if ((local_10[-1] & 0x80) == 0) {
          unaff_ESI = local_10 + -2;
        }
        unaff_EDI = (CFastStringInt *)0x69a2d7;
        operator_delete__(unaff_ESI);
        local_14 = (undefined *)0x0;
        local_10 = PTR_DAT_00bbf7dc;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  ExceptionList = local_8;
  return 0xffffffff;
}
}

// =================================================
// Function: CGameCtnArticle::HasDefaultSkin
// =================================================
int __thiscall CGameCtnArticle::HasDefaultSkin(CGameCtnArticle *this,CGameCtnArticle *param_1)
{
{
  ulong uVar1;
  CGameCtnArticle *unaff_retaddr;
  
  uVar1 = GetDefaultSkinIndex(this,unaff_retaddr);
  return (uint)(uVar1 != 0xffffffff);
}
}

// =================================================
// Function: CGameCtnArticle::Purge
// =================================================
void __thiscall CGameCtnArticle::Purge(CGameCtnArticle *this,CGameCtnArticle *param_1)
{
{
  CMwNod *unaff_ESI;
  CGameCtnArticle *pCVar1;
  
  if (*(CMwNod **)(this + 0x5c) != (CMwNod *)0x0) {
    pCVar1 = this;
    CMwNod::MwRelease(*(CMwNod **)(this + 0x5c),unaff_ESI);
    CFastBuffer<class_CGameCtnBlock*>::Remove
              (&DAT_00d69e88,
               (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)&stack0x00000000,
               (ulong)pCVar1);
    *(undefined4 *)(this + 0x5c) = 0;
  }
  return;
}
}

// =================================================
// Function: CGameCtnArticle::PurgeAllForce
// =================================================
void __cdecl CGameCtnArticle::PurgeAllForce(void)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *unaff_EDI;
  undefined1 uStack0000000c;
  void *in_stack_00000010;
  undefined1 uStack00000014;
  CMwId *in_stack_ffffffdc;
  CMwId *in_stack_ffffffe0;
  CMwId *in_stack_ffffffe4;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffffe8;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ab2128;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (&stack0xffffffe8,
             (CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffd4));
  CFastBuffer<class_CGameFid*>::CopyFromFastBuffer
            (local_14,(CFastBuffer<struct_CDx9StateBlock::STexStageState> *)&DAT_00d69e88,unaff_EDI)
  ;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(local_10,unaff_ESI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (&local_c,pCVar3,(ulong)in_stack_ffffffdc);
      in_stack_ffffffdc = (CMwId *)0x69a0f6;
      Purge(*(CGameCtnArticle **)pSVar2,(CGameCtnArticle *)in_stack_ffffffe0);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  DAT_00d69e48 = 0;
  CMwId::CMwId(&stack0xffffffe8,in_stack_ffffffdc);
  uStack0000000c = 1;
  CMwId::CMwId(local_10,in_stack_ffffffe0);
  in_stack_00000010 = (void *)CONCAT31(in_stack_00000010._1_3_,2);
  CMwId::CMwId(&local_8,in_stack_ffffffe4);
  DAT_00d69e94 = local_c;
  DAT_00d69e98 = local_8;
  DAT_00d69e9c = local_4;
  uStack00000014 = 4;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffffe8);
  uStack00000014 = 3;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffffe8);
  uStack00000014 = 0;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffffe8);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (&stack0x00000000,in_stack_ffffffe8);
  ExceptionList = in_stack_00000010;
  return;
}
}

