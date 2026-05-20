// Class implementation: CGameSkin

// =================================================
// Function: CGameSkin::GetIcon
// =================================================
void __thiscall
CGameSkin::GetIcon(CGameSkin *this,CMwParamFastBuffer<class_CMwParamVec4> *param_1,
                  EMwIconList *param_2,EMwIconList *param_3)
{
{
  CPlugBitmap *pCVar1;
  CPlugBitmap *this_00;
  CPlugBitmap *extraout_EAX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CSystemFid *pCVar4;
  int iVar5;
  ulong unaff_EBX;
  CGameSkin *unaff_EBP;
  EGxTexAddress unaff_ESI;
  int unaff_EDI;
  bool bVar6;
  void *in_stack_00000014;
  CSystemPackManager *in_stack_00000018;
  CVisionTexConverter *in_stack_00000020;
  CMwNod *in_stack_ffffffec;
  SHeaderCommunity *in_stack_fffffff0;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00abd0f4;
  local_c = ExceptionList;
  pCVar1 = (CPlugBitmap *)(DAT_00cca150 ^ (uint)&stack0xffffffd8);
  ExceptionList = &local_c;
  this_00 = operator_new(0x78);
  local_4 = 0;
  if (this_00 == (CPlugBitmap *)0x0) {
    pCVar1 = (CPlugBitmap *)0x0;
  }
  else {
    CPlugBitmap::CPlugBitmap(this_00,pCVar1);
    pCVar1 = extraout_EAX;
  }
  CPlugBitmap::SetMipMapping(pCVar1,(CPlugBitmap *)0x0,unaff_EDI);
  CPlugBitmap::SetDefaultTexAddress(pCVar1,(CPlugBitmap *)0x2,2,0,unaff_ESI);
  if ((DAT_00d54250 != (CSystemPackManager *)0x0) &&
     (pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)GetIconIndex(this,unaff_EBP),
     pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff)) {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this + 0x34,pCVar2,unaff_EBX)
    ;
    pCVar4 = *(CSystemFid **)pSVar3;
    if (pCVar4 != (CSystemFid *)0x0) {
      bVar6 = in_stack_00000018 != (CSystemPackManager *)0x0;
      if (bVar6) {
        CFastString::CFastString
                  ((CFastString *)&stack0x00000000,(CFastString *)PTR_DAT_00cf8890,(char *)this_00);
        in_stack_00000014 = (void *)0x1;
        pCVar4 = (CSystemFid *)
                 CSystemPackManager::GetPackElem
                           (DAT_00d54250,in_stack_00000018,(CSystemPackDesc *)&param_1,
                            (CFastString *)0x9025000,(ulong)pCVar4,(CSystemFid *)pCVar1,
                            in_stack_ffffffec);
      }
      in_stack_00000018 = (CSystemPackManager *)0xffffffff;
      if (bVar6) {
        CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&param_2,in_stack_fffffff0);
      }
      in_stack_00000020 = (CVisionTexConverter *)0x0;
      iVar5 = CSystemArchiveNod::LoadFromFid((CMwNod **)&stack0x00000020,pCVar4,7);
      if ((iVar5 != 0) && (in_stack_00000020 != (CVisionTexConverter *)0x0)) {
        CPlugBitmap::SetImage(pCVar1,in_stack_00000020,(CPlugFileImg *)in_stack_fffffff0);
        ExceptionList = in_stack_00000014;
        return;
      }
    }
  }
  CPlugBitmap::GenerateChecker(pCVar1,(CPlugBitmap *)0x0,(ulong)in_stack_fffffff0);
  ExceptionList = in_stack_00000014;
  return;
}
}

// =================================================
// Function: CGameSkin::GetIconIndex
// =================================================
ulong __thiscall CGameSkin::GetIconIndex(CGameSkin *this,CGameSkin *param_1)
{
{
  char cVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  char *pcVar3;
  int iVar4;
  SCasterCat *pSVar5;
  ulong unaff_EBX;
  char *pcVar6;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EDI);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pcVar6 = PTR_DAT_00cf8890;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      if (pcVar6 == (char *)0x0) {
        iVar4 = 0;
      }
      else {
        pcVar3 = pcVar6;
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        iVar4 = (int)pcVar3 - (int)(pcVar6 + 1);
      }
      pSVar5 = CFastBuffer<struct_SFastCat>::operator[](this + 0x40,pCVar7,unaff_ESI);
      if (iVar4 == *(int *)pSVar5) {
        unaff_ESI = 0;
        iVar4 = CFastString::CompareNoCase
                          ((CFastString *)pSVar5,(CFastStringInt *)&stack0x00000000,
                           (SStringParam *)0x0,unaff_EBP);
        pcVar6 = PTR_DAT_00cf8890;
        if (iVar4 == 0) {
          pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this + 0x4c,pCVar7,unaff_EBX);
          unaff_EBP = *(ulong *)pSVar5;
          unaff_EBX = 0x9025000;
          unaff_ESI = 0x6fbb8d;
          iVar4 = CMwNod::StaticMwIsKindOf(unaff_EBP,0x9025000);
          pcVar6 = PTR_DAT_00cf8890;
          if (iVar4 != 0) {
            return (ulong)pCVar7;
          }
        }
      }
      pCVar7 = pCVar7 + 1;
    } while (pCVar7 < pCVar2);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CGameSkin::GetSkinDisplayName
// =================================================
void __thiscall
CGameSkin::GetSkinDisplayName
          (CGameSkin *this,CGameSkin *param_1,CSystemPackDesc *param_2,CFastStringInt *param_3)
{
{
  CFastStringInt *unaff_ESI;
  undefined1 *local_20;
  undefined *local_1c;
  undefined4 local_18;
  undefined *local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00abd3a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 == (CGameSkin *)0x0) {
    local_1c = (undefined *)0x0;
    local_20 = &DAT_00b2c878;
    CFastStringInt::SetString
              (param_2,(CFastStringInt *)&local_20,
               (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffdc));
  }
  else {
    local_20 = (undefined1 *)0x0;
    local_1c = PTR_DAT_00bbf7dc;
    local_18 = *(undefined4 *)(param_1 + 0x20);
    local_14 = *(undefined **)(param_1 + 0x1c);
    local_4 = (void *)0x0;
    local_10 = 0;
    CFastStringInt::SetString
              (&local_20,(CFastStringInt *)&local_18,
               (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffdc));
    GetSkinDisplayName(this,(CGameSkin *)&local_1c,(CSystemPackDesc *)param_3,unaff_ESI);
    if (local_14 != PTR_DAT_00bbf7dc) {
      if ((local_14[-1] & 0x80) != 0) {
        operator_delete__(local_14 + -4);
        ExceptionList = local_4;
        return;
      }
      operator_delete__(local_14 + -2);
      ExceptionList = local_4;
      return;
    }
  }
  ExceptionList = puStack_8;
  return;
}
}

