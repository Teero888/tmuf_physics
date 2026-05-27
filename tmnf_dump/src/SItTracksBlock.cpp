// Class implementation: SItTracksBlock

// =================================================
// Function: SItTracksBlock::NextBlock
// =================================================
int __thiscall SItTracksBlock::NextBlock(void *this,SItTracksBlock *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong uVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_EDI;
  
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
  if (*(int *)((int)this + 0xc) == *(int *)((int)this + 0x10)) {
    pCVar1 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)this + 8);
    do {
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
      if (*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)this + 4) == pCVar1) {
        return 0;
      }
      *(undefined4 *)((int)this + 0xc) = 0;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (*(void **)this,
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)this + 4),
                          unaff_EDI);
      unaff_EDI = 0x696f37;
      uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)(*(int *)pSVar2 + 0x1c),unaff_ESI);
      *(ulong *)((int)this + 0x10) = uVar3;
    } while (uVar3 == 0);
  }
  return 1;
}
}

// =================================================
// Function: SItTracksBlock::SItTracksBlock
// =================================================
void __thiscall
SItTracksBlock::SItTracksBlock
          (void *this,SItTracksBlock *param_1,CFastBufferRef<class_CGameCtnMediaTrack> *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<class_CCrystalFace*> *unaff_retaddr;
  
  *(SItTracksBlock **)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_1,unaff_EDI);
  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)this + 8) = pCVar1;
  *(undefined4 *)((int)this + 0xc) = 0;
  if (pCVar1 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    uVar2 = 0;
  }
  else {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (param_1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)(*(int *)pSVar3 + 0x1c),unaff_EBP);
  }
  *(ulong *)((int)this + 0x10) = uVar2;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    while (uVar2 == 0) {
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
      if (*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)this + 4) == pCVar1) {
        return;
      }
      *(undefined4 *)((int)this + 0xc) = 0;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_1,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                   ((int)this + 4),unaff_EBX);
      unaff_EBX = 0x696ee5;
      uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                        ((void *)(*(int *)pSVar3 + 0x1c),unaff_retaddr);
      *(ulong *)((int)this + 0x10) = uVar2;
    }
  }
  return;
}
}

