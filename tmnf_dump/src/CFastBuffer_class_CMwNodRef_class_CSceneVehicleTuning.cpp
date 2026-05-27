// Class implementation: CFastBuffer_class_CMwNodRef_class_CSceneVehicleTuning

// =================================================
// Function: CFastBuffer<class_CMwNodRef<class_CSceneVehicleTuning>_>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<class_CMwNodRef<class_CSceneVehicleTuning>_>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(*(int *)((int)this + 4) + iVar1 * 4);
}
}

// =================================================
// Function: CFastBuffer<class_CMwNodRef<class_CSceneVehicleTuning>_>::ArchiveFastBufferNodRef
// =================================================
void __thiscall
CFastBuffer<class_CMwNodRef<class_CSceneVehicleTuning>_>::ArchiveFastBufferNodRef
          (void *this,CFastBuffer<class_CMwNodRef<class_CMwNod>_> *param_1,CClassicArchive *param_2)
{
{
  int *piVar1;
  CClassicArchive *pCVar2;
  uint uVar3;
  CMwNod *unaff_ESI;
  CClassicArchive *unaff_EDI;
  
  ArchiveFastBuffer(this,(CFastBuffer<class_CGameCtnChallengeGroup*> *)param_1,unaff_EDI);
  uVar3 = 0;
  if (*(int *)this != 0) {
    do {
      param_2 = *(CClassicArchive **)(*(int *)((int)this + 4) + uVar3 * 4);
      piVar1 = (int *)(*(int *)((int)this + 4) + uVar3 * 4);
      (**(code **)(*(int *)param_1 + 4))(&param_2);
      pCVar2 = param_2;
      if (param_2 != (CClassicArchive *)*piVar1) {
        if (param_2 != (CClassicArchive *)0x0) {
          CMwNod::MwAddRef((CMwNod *)param_2,unaff_ESI);
        }
        if ((CMwNod *)*piVar1 != (CMwNod *)0x0) {
          CMwNod::MwRelease((CMwNod *)*piVar1,unaff_ESI);
        }
        *piVar1 = (int)pCVar2;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)this);
  }
  return;
}
}

