// Class implementation: CFastBuffer_class_CMwNodRef_class_CGameCtnCampaign

// =================================================
// Function: CFastBuffer<class_CMwNodRef<class_CGameCtnCampaign>_>::ArchiveFastBuffer
// =================================================
void __thiscall
CFastBuffer<class_CMwNodRef<class_CGameCtnCampaign>_>::ArchiveFastBuffer
          (void *this,CFastBuffer<class_CGameCtnChallengeGroup*> *param_1,CClassicArchive *param_2)
{
{
  void *pvVar1;
  CFastBuffer<struct_SMeshOctreeCell> *pCVar2;
  int unaff_ESI;
  int unaff_EDI;
  ulong uVar3;
  
  uVar3 = 10;
  CClassicArchive::DoNatural
            ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffffc,(ulong *)0x1,0,unaff_EDI
            );
  CClassicArchive::DoNatural((CClassicArchive *)param_1,this,(ulong *)0x1,0,unaff_ESI);
  if (*(uint *)this != 0) {
    if ((0x10000000 < *(uint *)this) && (DAT_00d72e8c != (code *)0x0)) {
      (*DAT_00d72e8c)();
    }
    if (*(int *)(param_1 + 8) == 0) {
      pvVar1 = *(void **)((int)this + 4);
      pCVar2 = *(CFastBuffer<struct_SMeshOctreeCell> **)this;
      if (pvVar1 != (void *)0x0) {
        _eh_vector_destructor_iterator_
                  (pvVar1,4,*(int *)((int)pvVar1 + -4),
                   CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
        operator_delete__((void *)((int)pvVar1 + -4));
      }
      *(undefined4 *)((int)this + 4) = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)this = 0;
      InitSize(this,pCVar2,uVar3);
      *(CFastBuffer<struct_SMeshOctreeCell> **)this = pCVar2;
    }
  }
  return;
}
}

