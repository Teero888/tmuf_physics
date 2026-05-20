// Class implementation: CAudioMusic

// =================================================
// Function: CAudioMusic::CAudioMusic
// =================================================
void __thiscall
CAudioMusic::CAudioMusic
          (CAudioMusic *this,CAudioMusic *param_1,CPlugMusic *param_2,CAudioPort *param_3)
{
{
  CAudioMusic *this_00;
  ulong uVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_EDI;
  undefined4 uStack00000018;
  CAudioMusic *pCVar3;
  void *pvVar4;
  
  pvVar4 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar3 = this;
  CAudioSound::CAudioSound
            ((CAudioSound *)this,(CAudioSound *)param_1,(CPlugSound *)param_2,
             (CAudioPort *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  this_00 = this + 0x78;
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this_00,unaff_EDI);
  uVar1 = CMwRefBuffer::GetCount(*(CMwRefBuffer **)(param_1 + 0x74),unaff_ESI);
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)(uVar1 + 1),unaff_EBX);
  uStack00000018 = 0;
  CFastArray<class_CSystemFidFile*>::InitValue
            (this_00,(CFastArray<class_CSystemFidFile*> *)&stack0x00000018,(CSystemFidFile **)pCVar3
            );
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)pvVar4);
  *(undefined4 *)pSVar2 = 1;
  ExceptionList = param_3;
  return;
}
}

