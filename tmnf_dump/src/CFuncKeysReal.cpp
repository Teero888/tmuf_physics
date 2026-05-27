// Class implementation: CFuncKeysReal

// =================================================
// Function: CFuncKeysReal::CFuncKeysReal
// =================================================
void __thiscall CFuncKeysReal::CFuncKeysReal(CFuncKeysReal *this,CFuncKeysReal *param_1)
{
{
  CFuncKeys *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_retaddr;
  
  CFuncKeys::CFuncKeys((CFuncKeys *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x20,unaff_retaddr);
  *(undefined4 *)(this + 0x28) = 0;
  return;
}
}

// =================================================
// Function: CFuncKeysReal::GetRealAt
// =================================================
void __thiscall
CFuncKeysReal::GetRealAt
          (CFuncKeysReal *this,CFuncKeysReal *param_1,float param_2,float *param_3,ulong *param_4,
          ulong *param_5,float *param_6,ERealInterp param_7,int param_8)
{
{
  int iVar1;
  SCasterCat *pSVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  int unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  
  if (param_6 == (float *)0x1) {
    iVar1 = CFuncKeys::ComputeBlendCoef
                      ((CFuncKeys *)this,
                       (CFastBufferKey<struct_CGameCtnMediaBlockTime::SKeyVal> *)param_1,
                       (float)param_3,param_4,param_5,(float *)param_7,unaff_EDI);
    if (iVar1 != 0) {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x20,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)*param_3,
                          unaff_ESI);
      *param_4 = *(ulong *)pSVar2;
      return;
    }
    *param_3 = 0.0;
    return;
  }
  iVar1 = CFuncKeys::ComputeBlendCoef
                    ((CFuncKeys *)this,
                     (CFastBufferKey<struct_CGameCtnMediaBlockTime::SKeyVal> *)param_1,
                     (float)param_3,param_4,param_5,(float *)param_7,unaff_EBP);
  if (iVar1 != 0) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x20,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)*param_3,
                        unaff_EBX);
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x20,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)*param_4,
                        unaff_EDI);
    *param_5 = (ulong)((float)*param_5 * *(float *)pSVar3 +
                      (1.0 - (float)*param_5) * *(float *)pSVar2);
    return;
  }
  *param_3 = 0.0;
  return;
}
}

// =================================================
// Function: CFuncKeysReal::GetValue
// =================================================
GmVec3 __thiscall
CFuncKeysReal::GetValue(CFuncKeysReal *this,CFuncColorGradient *param_1,float param_2)
{
{
  float *pfVar1;
  GmVec3 extraout_AL;
  float fVar2;
  ulong local_4;
  
  if (param_2 == 0.0) {
    fVar2 = 0.0;
  }
  else {
    fVar2 = *(float *)param_2;
  }
  if (param_2 == 0.0) {
    param_2 = (float)&param_2;
  }
  pfVar1 = (float *)param_2;
  param_2 = fVar2;
  GetRealAt(this,(CFuncKeysReal *)param_1,(float)&param_1,pfVar1,(ulong *)&stack0xfffffff8,&local_4,
            *(float **)(this + 0x28),1,(int)fVar2 + 1);
  return extraout_AL;
}
}

// =================================================
// Function: CFuncKeysReal::InsertKeyReal
// =================================================
ulong __thiscall
CFuncKeysReal::InsertKeyReal(CFuncKeysReal *this,CFuncKeysReal *param_1,float param_2,float param_3)
{
{
  CFastArray<class_CControlBase*> *pCVar1;
  CControlBase **unaff_ESI;
  float unaff_EDI;
  
  pCVar1 = (CFastArray<class_CControlBase*> *)
           CFuncKeys::InsertKeyX((CFuncKeys *)this,(CFuncKeys *)param_1,unaff_EDI);
  if (pCVar1 == (CFastArray<class_CControlBase*> *)0xffffffff) {
    return 0xffffffff;
  }
  CFastArray<float>::InsertAt(this + 0x20,pCVar1,(ulong)&param_3,unaff_ESI);
  return (ulong)pCVar1;
}
}

