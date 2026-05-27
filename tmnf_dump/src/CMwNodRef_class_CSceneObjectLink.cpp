// Class implementation: CMwNodRef_class_CSceneObjectLink

// =================================================
// Function: CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>
// =================================================
void __thiscall
CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>
          (void *this,CMwNodRef<class_CSceneObjectLink> *param_1)
{
{
  if (*(CMwNod **)this != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)this,(CMwNod *)param_1);
    return;
  }
  return;
}
}

