// Class implementation: CFuncKeys

// =================================================
// Function: CFuncKeys::CFuncKeys
// =================================================
void __thiscall CFuncKeys::CFuncKeys(CFuncKeys *this,CFuncKeys *param_1)
{
{
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  CFuncKeys *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a9ae53;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CFunc::CFunc((CFunc *)this,(CFunc *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x14,unaff_ESI);
  CMwId::CMwId(this + 0x1c,(CMwId *)pCVar1);
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: CFuncKeys::ComputeBlendCoef
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CFuncKeys::ComputeBlendCoef
          (CFuncKeys *this,CFastBufferKey<struct_CGameCtnMediaBlockTime::SKeyVal> *param_1,
          float param_2,ulong *param_3,ulong *param_4,float *param_5,int param_6)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  ulong unaff_ESI;
  int unaff_EDI;
  float *in_stack_0000001c;
  
  GetBoundingIndices(this,(CFastBufferKey<struct_SOldKeyVal> *)param_1,param_2,param_3,
                     (ulong *)param_5,unaff_EDI);
  pCVar1 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_2;
  if (pCVar1 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    return 0;
  }
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)*param_3;
  if (pCVar1 == pCVar2) {
    *param_5 = 0.0;
    return 1;
  }
  CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this + 0x14,pCVar1,unaff_ESI);
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this + 0x14,pCVar2,unaff_EBX);
  if (ABS(*(float *)pSVar3 - (float)param_6) < _DAT_00b5f068) {
    *in_stack_0000001c = 0.0;
    return 1;
  }
  *in_stack_0000001c = ((float)param_4 - (float)param_6) / (*(float *)pSVar3 - (float)param_6);
  return 1;
}
}

// =================================================
// Function: CFuncKeys::GetBoundingIndices
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CFuncKeys::GetBoundingIndices
          (CFuncKeys *this,CFastBufferKey<struct_SOldKeyVal> *param_1,float param_2,ulong *param_3,
          ulong *param_4,int param_5)
{
{
  CFuncKeys *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ulong unaff_retaddr;
  undefined4 *in_stack_00000018;
  int in_stack_0000001c;
  
  this_00 = this + 0x14;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (pCVar1 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    *param_3 = 0xffffffff;
    *param_4 = 0xffffffff;
    return;
  }
  if (pCVar1 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1) {
    *param_3 = 0;
    *param_4 = 0;
    return;
  }
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBX);
  if ((float)param_3 < *(float *)pSVar2 - (float)_DAT_00b36288) {
    *param_4 = 0;
    *(undefined4 *)param_5 = 0;
    return;
  }
  pCVar4 = pCVar1 + -1;
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_ESI);
  if ((float)param_4 <= *(float *)pSVar2 + (float)_DAT_00b36288) {
    pCVar4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_5;
    if (in_stack_0000001c != 0) {
      if (pCVar1 <= pCVar4) {
        pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      }
      pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      do {
        pCVar5 = pCVar4;
        pCVar4 = pCVar5 + 1;
        if (pCVar1 <= pCVar4) {
          pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        }
        pCVar3 = pCVar3 + 1;
      } while ((pCVar3 <= pCVar1) &&
              ((pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (this_00,pCVar5,(ulong)unaff_EBP),
               (float)param_5 < *(float *)pSVar2 - (float)_DAT_00b36288 ||
               (unaff_EBP = pCVar4,
               pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                  (this_00,pCVar4,unaff_retaddr),
               *(float *)pSVar2 + (float)_DAT_00b36288 < (float)in_stack_00000018))));
      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_5 = pCVar5;
      *in_stack_00000018 = pCVar4;
      return;
    }
    pCVar4 = pCVar4 + 1;
    if ((int)pCVar4 < 0) {
      pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    }
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      pCVar5 = pCVar4;
      pCVar4 = pCVar5 + -1;
      if ((int)(pCVar5 + -1) < 0) {
        pCVar4 = pCVar1;
      }
      pCVar3 = pCVar3 + 1;
    } while ((pCVar3 <= pCVar1) &&
            ((pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (this_00,pCVar4,(ulong)unaff_EBP),
             (float)param_5 < *(float *)pSVar2 - (float)_DAT_00b36288 ||
             (unaff_EBP = pCVar5,
             pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                (this_00,pCVar5,unaff_retaddr),
             *(float *)pSVar2 + (float)_DAT_00b36288 < (float)in_stack_00000018))));
    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_5 = pCVar4;
    *in_stack_00000018 = pCVar5;
    return;
  }
  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_5 = pCVar4;
  *in_stack_00000018 = pCVar4;
  return;
}
}

// =================================================
// Function: CFuncKeys::InsertKeyX
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall CFuncKeys::InsertKeyX(CFuncKeys *this,CFuncKeys *param_1,float param_2)
{
{
  CFuncKeys *this_00;
  CFastArray<class_CControlBase*> *pCVar1;
  SCasterCat *pSVar2;
  ulong uVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CControlBase **unaff_retaddr;
  int *in_stack_0000000c;
  float in_stack_00000010;
  float in_stack_00000014;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  
  this_00 = this + 0x14;
  pCVar1 = (CFastArray<class_CControlBase*> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if ((pCVar1 == (CFastArray<class_CControlBase*> *)0x0) ||
     (pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI),
     (float)in_stack_0000000c < *(float *)pSVar2)) {
    pCVar1 = (CFastArray<class_CControlBase*> *)0x0;
  }
  else {
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar3 - 1);
    pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x5918b9;
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,(ulong)this);
    if (in_stack_00000014 <= *(float *)pSVar2) {
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      do {
        pCVar5 = pCVar6;
        pCVar6 = pCVar5 + 1;
        if (pCVar1 <= pCVar6) break;
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar5,(ulong)pCVar7);
      } while ((in_stack_00000010 < *(float *)pSVar2) ||
              (pCVar7 = pCVar6,
              pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (this_00,pCVar6,(ulong)pCVar4),
              *(float *)pSVar2 < in_stack_00000014));
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar5,(ulong)pCVar7);
      if ((float)_DAT_00b36288 <= in_stack_00000010 - *(float *)pSVar2) {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar6,(ulong)pCVar4);
        pCVar1 = (CFastArray<class_CControlBase*> *)pCVar6;
        if (*(float *)pSVar2 - in_stack_00000014 < (float)_DAT_00b36288) {
          (**(code **)(*in_stack_0000000c + 0x8c))(pCVar6);
        }
      }
      else {
        (**(code **)(*(int *)param_2 + 0x8c))(pCVar5);
        pCVar1 = (CFastArray<class_CControlBase*> *)pCVar5;
      }
    }
  }
  CFastArray<float>::InsertAt(this_00,pCVar1,(ulong)&stack0x00000014,unaff_retaddr);
  return (ulong)pCVar1;
}
}

