// Class implementation: CHmsZoneVPacker_SLocationAlloc

// =================================================
// Function: CHmsZoneVPacker::SLocationAlloc::FreeAt
// =================================================
void __thiscall
CHmsZoneVPacker::SLocationAlloc::FreeAt(void *this,SLocationAlloc *param_1,ulong param_2)
{
{
  int *this_00;
  SCasterCat *pSVar1;
  ulong uVar2;
  SNewTriangleVert *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  TiXmlAttribute *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  ulong unaff_EDI;
  void *this_01;
  ulong unaff_retaddr;
  
  this_00 = (int *)((int)this + 0xc);
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_EDI);
  *(int *)pSVar1 = *(int *)pSVar1 + -1;
  if (*(int *)pSVar1 == 0) {
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
    if (param_1 != (SLocationAlloc *)(uVar2 - 1)) {
      CFastBuffer<class_CDx9TextureKeeper*>::Add
                ((void *)((int)this + 0x18),(TiXmlAttributeSet *)&stack0x0000000c,unaff_EBX);
      return;
    }
    do {
      *(int *)this = *(int *)this + -1;
      *this_00 = *this_00 + -1;
      if (*this_00 == 0) break;
      pSVar3 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem
                         (this_00,(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                   *)unaff_EBX);
    } while (*(int *)pSVar3 == 0);
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
    this_01 = (void *)((int)this + 0x18);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this_01,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_01,pCVar5,unaff_retaddr);
        if (uVar2 <= *(uint *)pSVar1) {
          unaff_retaddr = 1;
          CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt
                    (this_01,(CFastBufferRef<class_CGameMobil> *)pCVar5,1,(ulong)param_1);
          pCVar5 = pCVar5 + -1;
          pCVar4 = pCVar4 + -1;
        }
        pCVar5 = pCVar5 + 1;
      } while (pCVar5 < pCVar4);
    }
  }
  return;
}
}

// =================================================
// Function: CHmsZoneVPacker::SLocationAlloc::UseNew
// =================================================
ulong __thiscall CHmsZoneVPacker::SLocationAlloc::UseNew(void *this,SLocationAlloc *param_1)
{
{
  int *this_00;
  ulong uVar1;
  SNewTriangleVert *pSVar2;
  SCasterCat *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SLoadedLight *pSVar5;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EBX;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_retaddr;
  
  this_00 = (int *)((int)this + 0x18);
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (uVar1 != 0) {
    pSVar2 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem(this_00,unaff_ESI);
    pCVar4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar2;
    *this_00 = *this_00 + -1;
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)((int)this + 0xc),pCVar4,(ulong)unaff_EBX);
    *(int *)pSVar3 = *(int *)pSVar3 + 1;
    return (ulong)pCVar4;
  }
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
  CFastBuffer<class_GmIso4>::AddNewElem(this,unaff_EBX);
  pSVar5 = CFastBuffer<struct_SIfBlock>::AddNewElem((void *)((int)this + 0xc),unaff_retaddr);
  *(undefined4 *)pSVar5 = 0;
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)((int)this + 0xc),pCVar4,(ulong)param_1);
  *(int *)pSVar3 = *(int *)pSVar3 + 1;
  return (ulong)pCVar4;
}
}

