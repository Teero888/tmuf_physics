// Class implementation: CMwNodRef_class_CGameCamera

// =================================================
// Function: CMwNodRef<class_CGameCamera>::MwSetNod
// =================================================
void __thiscall
CMwNodRef<class_CGameCamera>::MwSetNod
          (void *this,CMwNodRef<class_CGameCamera> *param_1,CGameCamera *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CMwNodRef<class_CGameCamera> **)this) {
    if (param_1 != (CMwNodRef<class_CGameCamera> *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)this != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)this,unaff_ESI);
    }
    *(CMwNodRef<class_CGameCamera> **)this = param_1;
  }
  return;
}
}

