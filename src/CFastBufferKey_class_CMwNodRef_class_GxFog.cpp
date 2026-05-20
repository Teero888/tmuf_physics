// Class implementation: CFastBufferKey_class_CMwNodRef_class_GxFog

// =================================================
// Function: CFastBufferKey<class_CMwNodRef<class_GxFog>_>::ComputeBlendCoefDichoWrap01
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CFastBufferKey<class_CMwNodRef<class_GxFog>_>::ComputeBlendCoefDichoWrap01
          (CFastBufferKey<class_CMwNodRef<class_GxFog>_> *this,
          CFastBufferKey<class_CMwNodRef<class_GxFog>_> *param_1,float param_2,ulong *param_3,
          ulong *param_4,float *param_5)
{
{
  float fVar1;
  float fVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  int *piVar4;
  ulong uVar5;
  ulong uVar6;
  SCasterCat *pSVar7;
  CMwNod *unaff_EBP;
  ulong unaff_ESI;
  CFastBufferKey<class_CMwNodRef<class_GxFog>_> *this_00;
  ulong unaff_EDI;
  float fStack00000018;
  float *in_stack_0000001c;
  CFastBufferKey<class_CMwNodRef<class_GxFog>_> *pCStack_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  CMwNod *pCStack_4;
  
  pCStack_4 = (CMwNod *)0xffffffff;
  puStack_8 = &LAB_00ad3e78;
  local_c = ExceptionList;
  piVar4 = (int *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  ExceptionList = &local_c;
  uVar5 = (*(code *)**(undefined4 **)this)();
  uStack_10 = 0;
  pCStack_14 = param_1;
  this_00 = this + 4;
  pCStack_4 = (CMwNod *)0x0;
  uVar6 = CFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_GxFog>_>::SKey>::QFindPrev
                    (this_00,(CFastBuffer<class_CMwNodRef<class_CGameCalendarEvent>_> *)&pCStack_14,
                     (CMwNodRef<class_CGameCalendarEvent> *)SKey::sSortAscending,
                     (_func___cdecl_int_CMwNodRef<class_CGameCalendarEvent>_ptr_CMwNodRef<class_CGameCalendarEvent>_ptr
                      *)0x0,piVar4);
  *param_4 = uVar6;
  *param_3 = uVar6 - 1;
  if (*param_4 == 0) {
    *param_3 = uVar5 - 1;
  }
  else if (*param_4 == uVar5) {
    *param_4 = 0;
  }
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)*param_3;
  pSVar7 = CFastBuffer<struct_SFastCat>::operator[](this_00,pCVar3,unaff_EDI);
  fVar1 = *(float *)pSVar7;
  pSVar7 = CFastBuffer<struct_SFastCat>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)*param_4,unaff_ESI);
  fVar2 = *(float *)pSVar7;
  fStack00000018 = ABS(fVar2 - (float)param_5);
  if (_DAT_00babae8 <= fStack00000018) {
    if (pCVar3 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar5 - 1)) {
      *in_stack_0000001c = (fVar1 - (float)param_5) / (fVar2 - (float)param_5);
    }
    else {
      if (fVar1 < (fVar2 + (float)param_5) * (float)_DAT_00b313b8) {
        fVar1 = fVar1 + 1.0;
      }
      *in_stack_0000001c = (fVar1 - (float)param_5) / ((fVar2 + 1.0) - (float)param_5);
    }
  }
  else {
    *in_stack_0000001c = 0.0;
  }
  if (pCStack_4 != (CMwNod *)0x0) {
    CMwNod::MwRelease(pCStack_4,unaff_EBP);
  }
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CFastBufferKey<class_CMwNodRef<class_GxFog>_>::GetCount
// =================================================
ulong __thiscall
CFastBufferKey<class_CMwNodRef<class_GxFog>_>::GetCount
          (CFastBufferKey<class_CMwNodRef<class_GxFog>_> *this,
          CFastBuffer<class_CCrystalFace*> *param_1)
{
{
  ulong uVar1;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 4,param_1);
  return uVar1;
}
}

