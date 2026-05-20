// Class implementation: CFastBuffer_class_CMwNodRef_class_CGameControlDataType

// =================================================
// Function: CFastBuffer<class_CMwNodRef<class_CGameControlDataType>_>::ArchiveFastBufferNod
// =================================================
void __thiscall
CFastBuffer<class_CMwNodRef<class_CGameControlDataType>_>::ArchiveFastBufferNod
          (void *this,CFastBuffer<class_CPlugMaterial*> *param_1,CClassicArchive *param_2)
{
{
  uint uVar1;
  CClassicArchive *unaff_EDI;
  
  ArchiveFastBuffer(this,(CFastBuffer<class_CGameCtnChallengeGroup*> *)param_1,unaff_EDI);
  uVar1 = 0;
  if (*(int *)this != 0) {
    do {
      (**(code **)(*(int *)param_1 + 4))(*(int *)((int)this + 4) + uVar1 * 4);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)this);
  }
  return;
}
}

