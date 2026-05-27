// Class implementation: CSysFidNodRef_class_CPlugMaterial

// =================================================
// Function: CSysFidNodRef<class_CPlugMaterial>::GetNod
// =================================================
CPlugMaterial * __thiscall
CSysFidNodRef<class_CPlugMaterial>::GetNod(void *this,CSysFidNodRef<class_CPlugMaterial> *param_1)
{
{
  CMwNod *pCVar1;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  CMwNod *local_4;
  
  if (*(int *)((int)this + 4) == 0) {
    if (*(CSystemFid **)this == (CSystemFid *)0x0) {
      return (CPlugMaterial *)0x0;
    }
    local_4 = this;
    CSystemArchiveNod::LoadFromFid(&local_4,*(CSystemFid **)this,7);
    pCVar1 = local_4;
    if ((local_4 != (CMwNod *)0x0) && (local_4 != *(CMwNod **)((int)this + 4))) {
      CMwNod::MwAddRef(local_4,unaff_EDI);
      if (*(CMwNod **)((int)this + 4) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)((int)this + 4),unaff_ESI);
      }
      *(CMwNod **)((int)this + 4) = pCVar1;
    }
  }
  return *(CPlugMaterial **)((int)this + 4);
}
}

