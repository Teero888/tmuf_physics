// Class implementation: CVisionEngine

// =================================================
// Function: CVisionEngine::CVisionEngine
// =================================================
void __thiscall CVisionEngine::CVisionEngine(CVisionEngine *this,CVisionEngine *param_1)
{
{
  CMwEngine *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  
  CMwEngine::CMwEngine((CMwEngine *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x24,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CVisionEngine::FindOrCreateViewport
// =================================================
CHmsViewport * __thiscall
CVisionEngine::FindOrCreateViewport
          (CVisionEngine *this,CVisionEngine *param_1,CSystemWindow *param_2)
{
{
  CVisionEngine *this_00;
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CMwNod *extraout_EAX;
  CMwNod *extraout_EAX_00;
  CMwNod *this_01;
  CMwNod *unaff_EBP;
  CVisionViewportNull *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  ulong unaff_EDI;
  void *local_c;
  CVisionViewportNull *local_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  local_8 = (CVisionViewportNull *)&LAB_00ae8fb6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = this + 0x24;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this_00,(CFastBuffer<class_CCrystalFace*> *)
                              (DAT_00cca150 ^ (uint)&stack0xffffffe0));
  if (param_2 == (CSystemWindow *)0x0) {
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EDI);
      ExceptionList = local_4;
      return *(CHmsViewport **)pSVar3;
    }
    ExceptionList = local_4;
    return (CHmsViewport *)0x0;
  }
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    iVar1 = *(int *)(param_2 + 0x90);
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,unaff_EDI);
      if (iVar1 == *(int *)(*(int *)(*(CHmsViewport **)pSVar3 + 0x260) + 0x90)) {
        ExceptionList = local_4;
        return *(CHmsViewport **)pSVar3;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  if (DAT_00d54244 == 0) {
    local_8 = operator_new(0x1618);
    if (local_8 != (CVisionViewportNull *)0x0) {
      CVisionViewportDx9::CVisionViewportDx9
                ((CVisionViewportDx9 *)local_8,(CVisionViewportDx9 *)unaff_ESI);
      this_01 = extraout_EAX_00;
      goto LAB_0095597a;
    }
  }
  else {
    local_8 = operator_new(0x7f8);
    if (local_8 != (CVisionViewportNull *)0x0) {
      CVisionViewportNull::CVisionViewportNull(local_8,unaff_ESI);
      this_01 = extraout_EAX;
      goto LAB_0095597a;
    }
  }
  this_01 = (CMwNod *)0x0;
LAB_0095597a:
  local_8 = (CVisionViewportNull *)this_01;
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (this_00,(TiXmlAttributeSet *)&local_8,(TiXmlAttribute *)unaff_ESI);
  CMwNod::MwAddRef(this_01,unaff_EBP);
  (**(code **)(*(int *)this_01 + 0x80))();
  ExceptionList = local_4;
  return (CHmsViewport *)this_01;
}
}

