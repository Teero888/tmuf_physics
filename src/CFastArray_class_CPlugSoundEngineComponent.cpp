// Class implementation: CFastArray_class_CPlugSoundEngineComponent

// =================================================
// Function: >::ArchiveCountAndNods
// =================================================
void __thiscall
CFastArray<class_CPlugSoundEngineComponent*>::ArchiveCountAndNods
          (void *this,CFastArray<class_CPlugSoundEngineComponent*> *param_1,CClassicArchive *param_2
          )
{
{
  CFastArray<class_CPlugSoundEngineComponent*> *pCVar1;
  ulong unaff_ESI;
  uint uVar2;
  int unaff_EDI;
  
  pCVar1 = param_1;
  if (*(int *)(param_1 + 8) == 0) {
    CClassicArchive::ReadNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(ulong *)0x1,0,unaff_EDI);
    if (((CClassicArchive *)0x10000000 < param_2) && (DAT_00d72e8c != (code *)0x0)) {
      (*DAT_00d72e8c)();
    }
    CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
              (this,(CFastBuffer<class_CSystemFidsFolder*> *)param_2,unaff_ESI);
  }
  else {
    CClassicArchive::WriteNatural((CClassicArchive *)param_1,this,(ulong *)0x1,0,unaff_EDI);
  }
  uVar2 = 0;
  if (*(int *)this != 0) {
    do {
      (**(code **)(*(int *)pCVar1 + 4))(*(int *)((int)this + 4) + uVar2 * 4);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)this);
  }
  return;
}
}

