// Class implementation: CFastBufferCat_struct_CSystemFidParameters_SParam_struct_SFastCatSmall

// =================================================
// Function: struct_SFastCatSmall>::AddInCat
// =================================================
void __thiscall
CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::AddInCat
          (void *this,CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *param_1,
          CHmsCorpus **param_2,ulong param_3)
{
{
  SCasterCat SVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  TiXmlAttribute *unaff_EDI;
  ulong unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000018;
  
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            ((void *)((int)this + 0xc),(TiXmlAttributeSet *)param_1,unaff_EDI);
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_ESI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar2 - 1);
  pSVar3 = CFastBuffer<unsigned_short>::operator[](this,pCVar4,unaff_EBX);
  SVar1 = pSVar3[1];
  pSVar3 = CFastBuffer<unsigned_short>::operator[](this,pCVar4,unaff_retaddr);
  pSVar3[1] = (SCasterCat)((char)pSVar3[1] + '\x01');
  if (in_stack_00000018 != pCVar4) {
    ChangeCatAt(this,(CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> *)
                     (uint)(byte)SVar1,(ulong)pCVar4,(ulong)in_stack_00000018,(ulong)param_1);
  }
  return;
}
}

// =================================================
// Function: struct_SFastCatSmall>::DeleteAll
// =================================================
void __thiscall
CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::DeleteAll
          (void *this,CFastArray<class_CCrystalEdge*> *param_1)
{
{
  CFastArray<class_CCrystalEdge*> *unaff_ESI;
  CFastBufferCat<enum__D3DFORMAT,struct_CDx9DeviceCaps::STextureRenderCat> *in_stack_00000008;
  
  CFastBuffer<struct_CSystemFidParameters::SParam*>::DeleteAll((void *)((int)this + 0xc),unaff_ESI);
  ResetCatDescs(this,in_stack_00000008);
  return;
}
}

// =================================================
// Function: struct_SFastCatSmall>::GetCatIndexFromIndexInAll
// =================================================
ulong __thiscall
CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::GetCatIndexFromIndexInAll
          (void *this,CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *param_1,
          ulong param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<unsigned_short>::operator[](this,pCVar3,unaff_ESI);
      if (param_2 < (uint)(byte)pSVar2[1] + (uint)(byte)*pSVar2) {
        return (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: struct_SFastCatSmall>::ReplaceByLastInAllAt
// =================================================
void __thiscall
CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::ReplaceByLastInAllAt
          (void *this,
          CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall> *param_1,
          ulong param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           GetCatIndexFromIndexInAll
                     (this,(CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)
                           param_1,unaff_EDI);
  pSVar2 = CFastBuffer<unsigned_short>::operator[](this,pCVar1,unaff_ESI);
  ReplaceByLastInCatAt
            (this,(CFastBufferCat<class_CMwCmd*,struct_SFastCat> *)(param_1 + -(uint)(byte)*pSVar2),
             (ulong)pCVar1,unaff_EBX);
  return;
}
}

// =================================================
// Function: struct_SFastCatSmall>::ReplaceByLastInCatAt
// =================================================
void __thiscall
CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::ReplaceByLastInCatAt
          (void *this,CFastBufferCat<class_CMwCmd*,struct_SFastCat> *param_1,ulong param_2,
          ulong param_3)
{
{
  SCasterCat SVar1;
  undefined4 uVar2;
  ulong uVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  ulong unaff_retaddr;
  uint in_stack_00000010;
  uint uStack00000014;
  int in_stack_00000018;
  undefined4 *in_stack_00000020;
  
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar3 - 1);
  if ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_3 != pCVar5) {
    ChangeCatAt(this,(CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> *)
                     param_2,param_3,(ulong)pCVar5,unaff_ESI);
  }
  pSVar4 = CFastBuffer<unsigned_short>::operator[](this,pCVar5,unaff_retaddr);
  uStack00000014 = (byte)pSVar4[1] - 1;
  if (in_stack_00000010 < uStack00000014) {
    pSVar4 = CFastBuffer<unsigned_short>::operator[](this,pCVar5,unaff_EBP);
    SVar1 = *pSVar4;
    CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
              ((void *)((int)this + 0xc),
               (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               ((uint)(byte)SVar1 + in_stack_00000018),unaff_EBX);
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)((int)this + 0xc),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        ((uint)(byte)SVar1 + in_stack_00000018),(ulong)param_1);
    uVar2 = *(undefined4 *)pSVar4;
    *(undefined4 *)pSVar4 = *in_stack_00000020;
    *in_stack_00000020 = uVar2;
  }
  pSVar4 = CFastBuffer<unsigned_short>::operator[](this,pCVar5,in_stack_00000010);
  pSVar4[1] = (SCasterCat)((char)pSVar4[1] + -1);
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1;
  return;
}
}

// =================================================
// Function: struct_SFastCatSmall>::ResetCatDescs
// =================================================
void __thiscall
CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::ResetCatDescs
          (void *this,
          CFastBufferCat<enum__D3DFORMAT,struct_CDx9DeviceCaps::STextureRenderCat> *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<unsigned_short>::operator[](this,pCVar3,(ulong)unaff_ESI);
      *pSVar2 = (SCasterCat)0x0;
      unaff_ESI = pCVar3;
      pSVar2 = CFastBuffer<unsigned_short>::operator[](this,pCVar3,unaff_EBP);
      pCVar3 = pCVar3 + 1;
      pSVar2[1] = (SCasterCat)0x0;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: struct_SFastCatSmall>::SetCatCount
// =================================================
void __thiscall
CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::SetCatCount
          (void *this,
          CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
          *param_1,ulong param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_retaddr;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this,unaff_EDI);
  if ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2 != pCVar1) {
    CFastBuffer<unsigned_short>::SetSizeAtLeast
              (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_2,unaff_ESI);
    CFastBuffer<class_CSystemFidsFolder*>::SetCount
              (this,(CFastBuffer<class_CSystemFidsFolder*> *)param_2,unaff_EBP);
    if (param_2 <= pCVar1) {
      CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat>::SetParsingAll
                (this,(CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat> *)unaff_retaddr);
      return;
    }
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0xc),unaff_EBX);
    for (; pCVar1 < param_2; pCVar1 = pCVar1 + 1) {
      pSVar3 = CFastBuffer<unsigned_short>::operator[](this,pCVar1,(ulong)unaff_retaddr);
      *pSVar3 = SUB41(uVar2,0);
      unaff_retaddr = pCVar1;
      pSVar3 = CFastBuffer<unsigned_short>::operator[](this,pCVar1,(ulong)param_1);
      pSVar3[1] = (SCasterCat)0x0;
    }
  }
  return;
}
}

