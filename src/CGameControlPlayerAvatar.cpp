// Class implementation: CGameControlPlayerAvatar

// =================================================
// Function: CGameControlPlayerAvatar::Display
// =================================================
void __thiscall
CGameControlPlayerAvatar::Display
          (void *this,CGameControlPlayerAvatar *param_1,CGamePlayerInfo *param_2,
          EAvatarVariant param_3)
{
{
  CPlugBitmap *pCVar1;
  CGamePlayerInfo *pCVar2;
  SCasterCat *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  undefined4 *puVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CGamePlayerInfo *this_00;
  ulong unaff_EBP;
  CGamePlayerTagData *this_01;
  CGamePlayerInfo *pCVar6;
  CGamePlayerInfo *unaff_ESI;
  int iVar7;
  int *piVar8;
  int *piVar9;
  CMwNod *unaff_EDI;
  CGamePlayerTagData *unaff_retaddr;
  CGamePlayerInfo *in_stack_00000018;
  CGamePlayerInfo *in_stack_0000001c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  ulong uVar11;
  
  iVar7 = 0;
  if ((param_1 != (CGameControlPlayerAvatar *)0x0) && (*(int **)this != (int *)0x0)) {
    (**(code **)(**(int **)this + 0x1ac))();
    if (*(CGameAvatar **)(param_1 + 0x30) != (CGameAvatar *)0x0) {
      pCVar1 = CGameAvatar::BitmapGet
                         (*(CGameAvatar **)(param_1 + 0x30),(CGameAvatar *)param_2,
                          (EAvatarVariant)unaff_EDI);
      piVar8 = (int *)(*(int *)this + 0x138);
      if (pCVar1 != (CPlugBitmap *)*piVar8) {
        if (pCVar1 != (CPlugBitmap *)0x0) {
          unaff_EDI = (CMwNod *)0x5adaab;
          CMwNod::MwAddRef((CMwNod *)pCVar1,(CMwNod *)unaff_ESI);
        }
        if ((CMwNod *)*piVar8 != (CMwNod *)0x0) {
          CMwNod::MwRelease((CMwNod *)*piVar8,unaff_EDI);
        }
        *piVar8 = (int)pCVar1;
      }
      iVar7 = 1;
    }
    (**(code **)(**(int **)this + 0x1a8))();
  }
  CControlTools::ControlSetVisible(*(CControlBase **)this,iVar7);
  param_2 = (CGamePlayerInfo *)0x0;
  piVar8 = (int *)((int)this + 0x10);
  this_00 = (CGamePlayerInfo *)param_1;
  do {
    uVar11 = 0;
    pCVar6 = param_2;
    if ((this_00 != (CGamePlayerInfo *)0x0) &&
       (iVar7 = CGamePlayerInfo::PlayerTags_IsLoaded(this_00,(CGamePlayerInfo *)unaff_EDI),
       iVar7 != 0)) {
      unaff_EDI = (CMwNod *)0x5adb0c;
      pCVar2 = (CGamePlayerInfo *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (this_00 + 0x220,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
      if (param_2 < pCVar2) {
        unaff_EDI = (CMwNod *)0x5adb1c;
        unaff_ESI = param_2;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00 + 0x220,
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,unaff_EBP);
        pCVar10 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar3;
        unaff_EBP = 0x5adb2b;
        pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           (this_00 + 0x208,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
        if (pCVar10 < pCVar4) {
          unaff_EBP = 0x5adb37;
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00 + 0x208,pCVar10,uVar11);
          this_01 = *(CGamePlayerTagData **)pSVar3;
          unaff_EBX = pCVar10;
        }
        else {
          this_01 = (CGamePlayerTagData *)0x0;
        }
        this_00 = in_stack_00000018;
        pCVar6 = in_stack_0000001c;
        if (this_01 != (CGamePlayerTagData *)0x0) {
          if (piVar8[-3] != 0) {
            uVar11 = 0x5adb4e;
            pCVar1 = CGamePlayerTagData::GetBitmap(this_01,unaff_retaddr);
            piVar9 = (int *)(piVar8[-3] + 0x138);
            if (pCVar1 != (CPlugBitmap *)*piVar9) {
              if (pCVar1 != (CPlugBitmap *)0x0) {
                unaff_retaddr = (CGamePlayerTagData *)0x5adb68;
                CMwNod::MwAddRef((CMwNod *)pCVar1,(CMwNod *)param_1);
              }
              if ((CMwNod *)*piVar9 != (CMwNod *)0x0) {
                CMwNod::MwRelease((CMwNod *)*piVar9,(CMwNod *)param_2);
              }
              *piVar9 = (int)pCVar1;
            }
            param_1 = (CGameControlPlayerAvatar *)0x5adb82;
            (**(code **)(*(int *)piVar8[-3] + 0x1a8))();
          }
          if (*piVar8 != 0) {
            if ((byte)this_01[0x2c] < 4) {
              puVar5 = &DAT_00d68ea8 + (byte)this_01[0x2c];
            }
            else {
              puVar5 = &DAT_00d68ea8;
            }
            *(undefined4 *)(*piVar8 + 0x140) = *puVar5;
            uVar11 = 0x5adbb5;
            (**(code **)(*(int *)*piVar8 + 0x1a8))();
          }
        }
      }
    }
    CControlTools::ControlSetVisible((CControlBase *)piVar8[-3],uVar11);
    CControlTools::ControlSetVisible((CControlBase *)*piVar8,uVar11);
    param_2 = pCVar6 + 1;
    piVar8 = piVar8 + 1;
  } while (param_2 < (CGamePlayerInfo *)0x3);
  return;
}
}

