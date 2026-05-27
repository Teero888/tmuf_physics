// Class implementation: CGamePlayerProfile

// =================================================
// Function: CGamePlayerProfile::FindVehicleProfileFromVehicleIdent
// =================================================
ulong __thiscall
CGamePlayerProfile::FindVehicleProfileFromVehicleIdent
          (CGamePlayerProfile *this,CGamePlayerProfile *param_1,SGameCtnIdentifier *param_2)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  int in_stack_0000000c;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x124,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    iVar1 = *(int *)param_2;
    do {
      pSVar3 = CFastBuffer<struct_SChildGen>::operator[](this + 0x124,pCVar4,unaff_ESI);
      if ((*(int *)pSVar3 == iVar1) && (*(int *)(pSVar3 + 4) == *(int *)(in_stack_0000000c + 4))) {
        return (ulong)pCVar4;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CGamePlayerProfile::ForceFavouriteAdd
// =================================================
void __thiscall
CGamePlayerProfile::ForceFavouriteAdd
          (CGamePlayerProfile *this,CGamePlayerProfile *param_1,CFastString *param_2)
{
{
  SLoadedLight *this_00;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  SStringParam *in_stack_fffffff8;
  undefined4 local_4;
  
  this_00 = CFastBuffer<struct_CGamePlayerProfile::SFavouriteInfo>::AddNewElem
                      (this + 0x278,unaff_ESI);
  local_4 = *(undefined4 *)(param_2 + 4);
  CFastString::SetString((CFastString *)this_00,(CFastStringInt *)&local_4,in_stack_fffffff8);
  *(undefined4 *)(this_00 + 8) = 0;
  return;
}
}

// =================================================
// Function: CGamePlayerProfile::GetAnalogSensibility
// =================================================
void __thiscall
CGamePlayerProfile::GetAnalogSensibility
          (CGamePlayerProfile *this,CGamePlayerProfile *param_1,ulong param_2,float *param_3,
          float *param_4)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<struct_SChildGen>::operator[]
                     (this + 0x124,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_retaddr);
  *param_3 = *(float *)(pSVar1 + 0x28);
  *param_4 = *(float *)(pSVar1 + 0x2c);
  return;
}
}

// =================================================
// Function: CGamePlayerProfile::UpdateLeagueSteps
// =================================================
void __thiscall
CGamePlayerProfile::UpdateLeagueSteps(CGamePlayerProfile *this,CGamePlayerProfile *param_1)
{
{
  CFastBuffer<class_CFastStringInt> *unaff_retaddr;
  
  CGameLeague::GetPathSteps
            (*(CGameLeague **)(this + 0x28),(CGameLeague *)(this + 0x54),unaff_retaddr);
  return;
}
}

