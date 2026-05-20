// Class implementation: CSceneVehicleStruct

// =================================================
// Function: CSceneVehicleStruct::CSceneVehicleStruct
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleStruct::CSceneVehicleStruct(CSceneVehicleStruct *this,CSceneVehicleStruct *param_1)
{
{
  CFuncKeysReal *pCVar1;
  CMwNod *extraout_EAX;
  CFuncKeysReal *this_00;
  CMwNod *extraout_EAX_00;
  CMwNod *extraout_EAX_01;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBP;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CMwNod *unaff_EDI;
  CMwNod *this_01;
  CMwNod *pCVar2;
  CFuncKeysReal *unaff_retaddr;
  float in_stack_0000000c;
  CFuncKeysReal *in_stack_00000010;
  CMwNod *in_stack_00000014;
  float in_stack_0000001c;
  undefined1 uStack00000024;
  undefined1 uStack00000034;
  undefined1 uStack00000038;
  void *in_stack_0000003c;
  CSceneVehicleStruct *pCVar3;
  CFuncKeysReal *in_stack_fffffff0;
  undefined1 *puVar4;
  float fVar5;
  
  fVar5 = -NAN;
  puVar4 = &LAB_00ad0416;
  pCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar3 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffdc),unaff_EDI);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x14,unaff_ESI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x20,unaff_EBP);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x2c,unaff_EBX);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x38,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar3);
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  pCVar1 = operator_new(0x2c);
  in_stack_00000014 = (CMwNod *)CONCAT31(in_stack_00000014._1_3_,8);
  if (pCVar1 == (CFuncKeysReal *)0x0) {
    this_01 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar1,in_stack_fffffff0);
    this_01 = extraout_EAX;
  }
  if (this_01 != *(CMwNod **)(this + 0x4c)) {
    if (this_01 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_01,pCVar2);
    }
    if (*(CMwNod **)(this + 0x4c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x4c),pCVar2);
    }
    *(CMwNod **)(this + 0x4c) = this_01;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x4c),(CFuncKeysReal *)0x0,0.0,(float)pCVar2);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x4c),_DAT_00b36198,0.0,(float)puVar4);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x4c),_DAT_00b36adc,1.0,fVar5);
  this_00 = operator_new(0x2c);
  uStack00000024 = 9;
  if (this_00 == (CFuncKeysReal *)0x0) {
    pCVar2 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(this_00,unaff_retaddr);
    pCVar2 = extraout_EAX_00;
  }
  if (pCVar2 != *(CMwNod **)(this + 0x44)) {
    if (pCVar2 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar2,(CMwNod *)0x0);
    }
    if (*(CMwNod **)(this + 0x44) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x44),(CMwNod *)0x0);
    }
    *(CMwNod **)(this + 0x44) = pCVar2;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x44),(CFuncKeysReal *)0x0,0.0,0.0);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x44),_DAT_00b36198,_DAT_00b3380c,(float)pCVar1);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x44),_DAT_00b36adc,_DAT_00b36144,in_stack_0000000c);
  pCVar1 = operator_new(0x2c);
  uStack00000034 = 10;
  if (pCVar1 == (CFuncKeysReal *)0x0) {
    pCVar2 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar1,in_stack_00000010);
    pCVar2 = extraout_EAX_01;
  }
  uStack00000038 = 7;
  if (pCVar2 != *(CMwNod **)(this + 0x48)) {
    if (pCVar2 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar2,in_stack_00000014);
    }
    if (*(CMwNod **)(this + 0x48) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x48),in_stack_00000014);
    }
    *(CMwNod **)(this + 0x48) = pCVar2;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x48),(CFuncKeysReal *)0x0,0.0,(float)in_stack_00000014);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x48),_DAT_00b36198,_DAT_00b41d80,(float)this_00);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x48),_DAT_00b36adc,_DAT_00b3cd40,in_stack_0000001c);
  ExceptionList = in_stack_0000003c;
  return;
}
}

// =================================================
// Function: CSceneVehicleStruct::GetVisualIndexFromMobilQuality
// =================================================
ulong __thiscall
CSceneVehicleStruct::GetVisualIndexFromMobilQuality
          (CSceneVehicleStruct *this,CSceneVehicleStruct *param_1,ESceneMobilQuality param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x20,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>::operator[]
                         (this + 0x20,pCVar3,unaff_ESI);
      if (*(ESceneMobilQuality *)pSVar2 == param_2) {
        return (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0;
}
}

