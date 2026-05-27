// Class implementation: CFastBuffer_class_CMwNodRef_class_CGameCtnGhost

// =================================================
// Function: CFastBuffer<class_CMwNodRef<class_CGameCtnGhost>_>::AddRefAll
// =================================================
void __thiscall
CFastBuffer<class_CMwNodRef<class_CGameCtnGhost>_>::AddRefAll
          (void *this,CFastBuffer<class_CMwNod*> *param_1)
{
{
  CMwNod *this_00;
  uint uVar1;
  CMwNod *unaff_EDI;
  
  uVar1 = 0;
  if (*(int *)this != 0) {
    do {
      this_00 = *(CMwNod **)(*(int *)((int)this + 4) + uVar1 * 4);
      if (this_00 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(this_00,unaff_EDI);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)this);
  }
  return;
}
}

