// Class implementation: CGameAvatar

// =================================================
// Function: CGameAvatar::BitmapGet
// =================================================
CPlugBitmap * __thiscall
CGameAvatar::BitmapGet(CGameAvatar *this,CGameAvatar *param_1,EAvatarVariant param_2)
{
{
  ulong uVar1;
  CPlugBitmap *this_00;
  SLoadedLight *pSVar2;
  SCasterCat *pSVar3;
  CSystemFidFile *pCVar4;
  CPlugBitmap *pCVar5;
  undefined *puVar6;
  ulong unaff_EBX;
  uint uVar7;
  CMwNod *unaff_EBP;
  CGameAvatar *unaff_ESI;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EDI;
  CMwNod *unaff_retaddr;
  undefined *in_stack_0000000c;
  void *in_stack_00000010;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000001c;
  CPlugBitmap *pCVar8;
  ulong in_stack_ffffffe4;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_ffffffe8;
  CGameAvatar *in_stack_ffffffec;
  CMwNod *in_stack_fffffff0;
  CPlugBitmap *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00aa1348;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (DAT_00d692c8 == (CPlugBitmap *)0x0) {
    pCVar8 = (CPlugBitmap *)0x0;
  }
  else {
    pCVar8 = DAT_00d692c8;
    if (*(int *)(this + 0x20) != 0) {
      pCVar5 = (CPlugBitmap *)(this + 0x14);
      pCVar8 = pCVar5;
      uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (pCVar5,(CFastBuffer<class_CCrystalFace*> *)
                                (DAT_00cca150 ^ (uint)&stack0xffffffd0));
      if (uVar1 == 0) {
        this_00 = LoadAvatarVariant((CPlugBitmap *)PTR_s__normal_00ceb924,(CSystemPackDesc *)this,
                                    (char *)unaff_EDI,unaff_ESI);
        if (this_00 == (CPlugBitmap *)0x0) {
          this_00 = DAT_00d692c8;
        }
        pSVar2 = CFastBuffer<class_CMwNodRef<class_CPlugBitmap>_>::AddNewElem(pCVar5,unaff_EDI);
        if (this_00 != (CPlugBitmap *)*(CMwNod **)pSVar2) {
          if (this_00 != (CPlugBitmap *)0x0) {
            CMwNod::MwAddRef((CMwNod *)this_00,(CMwNod *)unaff_ESI);
          }
          if (*(CMwNod **)pSVar2 != (CMwNod *)0x0) {
            CMwNod::MwRelease(*(CMwNod **)pSVar2,unaff_EBP);
          }
          *(CPlugBitmap **)pSVar2 = this_00;
        }
      }
      if (*(int *)(*(int *)(this + 0x20) + 0x48) == 0) {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar5,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            (ulong)unaff_EBP);
        pCVar8 = *(CPlugBitmap **)pSVar3;
      }
      else {
        uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                          (pCVar5,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
        if (uVar1 == 1) {
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (pCVar5,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBX
                             );
          puStack_8 = *(undefined1 **)pSVar3;
          uVar7 = 4;
          do {
            CFastString::CFastString
                      ((CFastString *)&stack0x00000000,
                       *(CFastString **)((int)&PTR_s__normal_00ceb924 + uVar7),(char *)pCVar8);
            pCVar8 = (CPlugBitmap *)0x0;
            in_stack_00000014 = 0;
            pCVar4 = CSystemPackManager::SimpleGetPackElem
                               (*(CSystemPackManager **)(DAT_00d66e1c + 0x50),
                                *(CSystemPackManager **)(this + 0x20),(CSystemPackDesc *)&param_1,
                                (CFastString *)0x9025000,(ulong)&stack0x00000000,(int *)0x0,
                                in_stack_ffffffe4);
            in_stack_00000018 = 0xffffffff;
            if (in_stack_0000000c != PTR_DAT_00bbf7d8) {
              puVar6 = in_stack_0000000c + -1;
              if ((in_stack_0000000c[-1] & 0x80) != 0) {
                puVar6 = in_stack_0000000c + -4;
              }
              pCVar8 = (CPlugBitmap *)0x5d8477;
              operator_delete__(puVar6);
              param_2 = 0;
              in_stack_0000000c = PTR_DAT_00bbf7d8;
            }
            if (pCVar4 == (CSystemFidFile *)0x0) {
LAB_005d84ab:
              pCVar5 = (CPlugBitmap *)unaff_retaddr;
            }
            else {
              pCVar8 = *(CPlugBitmap **)((int)&PTR_s__normal_00ceb924 + uVar7);
              pCVar5 = LoadAvatarVariant(pCVar8,(CSystemPackDesc *)this,(char *)in_stack_ffffffe8,
                                         in_stack_ffffffec);
              if (pCVar5 == (CPlugBitmap *)0x0) goto LAB_005d84ab;
            }
            in_stack_ffffffe4 = 0x5d84b8;
            pSVar2 = CFastBuffer<class_CMwNodRef<class_CPlugBitmap>_>::AddNewElem
                               (local_4,in_stack_ffffffe8);
            if (pCVar5 != (CPlugBitmap *)*(CMwNod **)pSVar2) {
              if (pCVar5 != (CPlugBitmap *)0x0) {
                in_stack_ffffffe8 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x5d84c9
                ;
                CMwNod::MwAddRef((CMwNod *)pCVar5,(CMwNod *)in_stack_ffffffec);
              }
              if (*(CMwNod **)pSVar2 != (CMwNod *)0x0) {
                in_stack_ffffffec = (CGameAvatar *)0x5d84d4;
                CMwNod::MwRelease(*(CMwNod **)pSVar2,in_stack_fffffff0);
              }
              *(CPlugBitmap **)pSVar2 = pCVar5;
            }
            uVar7 = uVar7 + 4;
            pCVar5 = local_c;
          } while (uVar7 < 0xc);
        }
        uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                          (pCVar5,(CFastBuffer<class_CCrystalFace*> *)pCVar8);
        pCVar8 = DAT_00d692c8;
        if (uVar1 != 0) {
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (pCVar5,in_stack_0000001c,in_stack_ffffffe4);
          pCVar8 = *(CPlugBitmap **)pSVar3;
        }
      }
    }
  }
  ExceptionList = in_stack_00000010;
  return pCVar8;
}
}

// =================================================
// Function: CGameAvatar::ComputeVariantFromText
// =================================================
EAvatarVariant __cdecl CGameAvatar::ComputeVariantFromText(CFastStringInt *param_1)
{
{
  undefined4 *puVar1;
  char cVar2;
  char *pcVar3;
  ulong uVar4;
  undefined4 *puVar5;
  int unaff_EDI;
  int iVar6;
  undefined **local_10;
  char *local_c;
  int local_8;
  
  CFastStringInt::GetUtf8(param_1,(CFastStringInt *)&DAT_00d71ca4,(CFastString *)0x0,unaff_EDI);
  iVar6 = 3;
  local_10 = &PTR_PTR_00ceb938;
  while (puVar5 = (undefined4 *)*local_10, puVar5 != (undefined4 *)0x0) {
    local_c = (char *)*puVar5;
    while (local_c != (char *)0x0) {
      if (local_c == (char *)0x0) {
        local_8 = 0;
      }
      else {
        pcVar3 = local_c;
        do {
          cVar2 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar2 != '\0');
        local_8 = (int)pcVar3 - (int)(local_c + 1);
      }
      uVar4 = CFastString::FindFirst((CFastString *)&DAT_00d71ca4,(CFastStringInt *)&local_c,0,1);
      if (uVar4 != 0xffffffff) goto LAB_005d7bfb;
      puVar1 = puVar5 + 1;
      puVar5 = puVar5 + 1;
      local_c = (char *)*puVar1;
    }
    local_10 = local_10 + -1;
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) {
      return 0;
    }
  }
LAB_005d7bfb:
  return iVar6 - 1;
}
}

