// Class implementation: CGameLeagueManager

// =================================================
// Function: CGameLeagueManager::ForceUpdate
// =================================================
void __thiscall
CGameLeagueManager::ForceUpdate(CGameLeagueManager *this,CGameLeagueManager *param_1)
{
{
  SSystemTime::SetInvalid(this + 0x14,(CGameScoresVersion *)param_1);
  return;
}
}

// =================================================
// Function: CGameLeagueManager::GetLeagueFromFullPath
// =================================================
CGameLeague * __thiscall
CGameLeagueManager::GetLeagueFromFullPath
          (CGameLeagueManager *this,CGameLeagueManager *param_1,CFastStringInt *param_2)
{
{
  CGameLeague *pCVar1;
  undefined *puVar2;
  undefined4 local_1c;
  undefined *local_18;
  undefined4 local_14;
  undefined *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00abb260;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_14 = 0;
  local_10 = PTR_DAT_00bbf7dc;
  local_1c = 0;
  local_18 = PTR_DAT_00bbf7dc;
  local_4 = 1;
  CGameLeague::GetNameAndPathFromFullPath
            ((CFastStringInt *)param_1,(CFastStringInt *)&local_14,(CFastStringInt *)&local_1c);
  pCVar1 = InternalGetLeagueFromPathAndName
                     ((CFastBufferRef<class_CGameLeague> *)(this + 0x20),(CFastStringInt *)&local_14
                      ,(CFastStringInt *)&local_1c);
  if (local_18 != PTR_DAT_00bbf7dc) {
    if ((local_18[-1] & 0x80) == 0) {
      puVar2 = local_18 + -2;
    }
    else {
      puVar2 = local_18 + -4;
    }
    operator_delete__(puVar2);
    local_1c = 0;
    local_18 = PTR_DAT_00bbf7dc;
  }
  if (local_10 != PTR_DAT_00bbf7dc) {
    if ((local_10[-1] & 0x80) == 0) {
      puVar2 = local_10 + -2;
    }
    else {
      puVar2 = local_10 + -4;
    }
    operator_delete__(puVar2);
  }
  ExceptionList = local_c;
  return pCVar1;
}
}

// =================================================
// Function: CGameLeagueManager::GetStepLeaguesFromFullPath
// =================================================
void __thiscall
CGameLeagueManager::GetStepLeaguesFromFullPath
          (CGameLeagueManager *this,CGameLeagueManager *param_1,CFastStringInt *param_2,
          CFastBuffer<class_CGameLeague*> *param_3,int param_4)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  CGameLeagueManager *pCVar2;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  int in_stack_00000014;
  CFastStringInt *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  undefined1 local_18 [4];
  CFastBuffer<class_CFastStringInt> local_14 [4];
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00abb2f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (local_18,(CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffd8)
            );
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  CGameLeague::GetRecursivesPathsFromFullPath(param_2,local_14);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(local_14,unaff_EDI);
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pCVar4 = (CFastStringInt *)0x6e6f6a;
      pCVar5 = pCVar3;
      pCVar2 = (CGameLeagueManager *)
               CFastBuffer<struct_SFastCat>::operator[](local_10,pCVar3,(ulong)unaff_ESI);
      if (in_stack_00000014 != 0) {
        unaff_ESI = pCVar1 + (-1 - (int)pCVar3);
        pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x6e6f7f;
        pCVar2 = (CGameLeagueManager *)
                 CFastBuffer<struct_SFastCat>::operator[](&local_c,unaff_ESI,unaff_EBP);
      }
      param_2 = (CFastStringInt *)GetLeagueFromFullPath(this,pCVar2,pCVar4);
      if (param_2 != (CFastStringInt *)0x0) {
        CFastBuffer<class_CDx9TextureKeeper*>::Add
                  (param_3,(TiXmlAttributeSet *)&param_2,(TiXmlAttribute *)pCVar5);
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  CFastBuffer<class_CFastStringInt>::~CFastBuffer<class_CFastStringInt>
            (local_10,(CFastBuffer<class_CFastStringInt> *)unaff_ESI);
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: CGameLeagueManager::InternalGetLeagueFromPathAndName
// =================================================
CGameLeague * __cdecl
CGameLeagueManager::InternalGetLeagueFromPathAndName
          (CFastBufferRef<class_CGameLeague> *param_1,CFastStringInt *param_2,
          CFastStringInt *param_3)
{
{
  CFastStringInt *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  int extraout_EAX;
  int extraout_EAX_00;
  int *unaff_EBX;
  SParam_Fids *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  int *in_stack_00000010;
  int *in_stack_ffffffe0;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_1,unaff_EDI);
  pCVar1 = param_3;
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](param_2,pCVar4,unaff_ESI);
      local_10 = in_stack_00000010[1];
      local_c = *in_stack_00000010;
      local_8 = 0;
      if (local_c == *(int *)(*(int *)pSVar3 + 0x1c)) {
        unaff_ESI = 0;
        CFastStringInt::Compare
                  ((int *)(*(int *)pSVar3 + 0x1c),(SParam_Fids *)&local_10,(SParam *)0x0,
                   (int *)unaff_EBP,unaff_EBX);
        if (extraout_EAX == 0) {
          param_1 = *(CFastBufferRef<class_CGameLeague> **)(pCVar1 + 4);
          param_2 = *(CFastStringInt **)pCVar1;
          param_3 = (CFastStringInt *)0x0;
          if (param_2 == *(CFastStringInt **)(*(int *)pSVar3 + 0x14)) {
            unaff_EBX = (int *)0x0;
            unaff_EBP = (SParam_Fids *)&param_1;
            unaff_ESI = 0x6e693e;
            CFastStringInt::Compare
                      ((int *)(*(int *)pSVar3 + 0x14),unaff_EBP,(SParam *)0x0,in_stack_ffffffe0,
                       (int *)pCVar2);
            if (extraout_EAX_00 == 0) {
              return *(CGameLeague **)pSVar3;
            }
          }
        }
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return (CGameLeague *)0x0;
}
}

