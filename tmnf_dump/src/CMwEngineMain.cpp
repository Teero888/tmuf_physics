// Class implementation: CMwEngineMain

// =================================================
// Function: CMwEngineMain::AddEngine
// =================================================
void __thiscall
CMwEngineMain::AddEngine
          (CMwEngineMain *this,CMwEngineMain *param_1,ulong param_2,CMwEngine *param_3)
{
{
  CMwEngine *pCVar1;
  SCasterCat *pSVar2;
  TiXmlAttribute *unaff_ESI;
  ulong unaff_EDI;
  
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x20,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((uint)param_1 >> 0x18),
                      unaff_EDI);
  pCVar1 = param_3;
  *(CMwEngine **)pSVar2 = param_3;
  CFastBuffer<class_CDx9TextureKeeper*>::Add(this + 0x28,(TiXmlAttributeSet *)&param_3,unaff_ESI);
  (**(code **)(*(int *)pCVar1 + 0x80))();
  return;
}
}

// =================================================
// Function: CMwEngineMain::CMwEngineMain
// =================================================
void __thiscall CMwEngineMain::CMwEngineMain(CMwEngineMain *this,CMwEngineMain *param_1)
{
{
  CMwEngineMain *this_00;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_EDI;
  void *in_stack_00000008;
  CMwEngineMain *pCVar1;
  CSystemFidFile **ppCVar2;
  
  ppCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CMwEngine::CMwEngine((CMwEngine *)this,(CMwEngine *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  this_00 = this + 0x20;
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this_00,unaff_EDI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x28,unaff_ESI);
  in_stack_00000008 = (void *)CONCAT31(in_stack_00000008._1_3_,2);
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)0x64,(ulong)pCVar1);
  CFastArray<class_CSystemFidFile*>::InitValue
            (this_00,(CFastArray<class_CSystemFidFile*> *)&stack0x00000000,ppCVar2);
  DAT_00d73300 = this;
  ExceptionList = in_stack_00000008;
  return;
}
}

