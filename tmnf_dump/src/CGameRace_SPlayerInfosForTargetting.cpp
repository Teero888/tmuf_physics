// Class implementation: CGameRace_SPlayerInfosForTargetting

// =================================================
// Function: CGameRace::SPlayerInfosForTargetting::SPlayerInfosForTargetting
// =================================================
void __thiscall
CGameRace::SPlayerInfosForTargetting::SPlayerInfosForTargetting
          (void *this,SPlayerInfosForTargetting *param_1)
{
{
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_retaddr;
  
  *(undefined4 *)this = 0;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>((void *)((int)this + 0x14),unaff_ESI)
  ;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>
            ((void *)((int)this + 0x1c),unaff_retaddr);
  return;
}
}

// =================================================
// Function: CGameRace::SPlayerInfosForTargetting::~SPlayerInfosForTargetting
// =================================================
void __thiscall
CGameRace::SPlayerInfosForTargetting::~SPlayerInfosForTargetting
          (void *this,SPlayerInfosForTargetting *param_1)
{
{
  CFastArray<class_CFuncShader*> *unaff_ESI;
  CFastArray<class_CFuncShader*> *unaff_retaddr;
  CMwNod *in_stack_0000000c;
  
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>
            ((void *)((int)this + 0x1c),unaff_ESI);
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>
            ((void *)((int)this + 0x14),unaff_retaddr);
  if (*(CMwNod **)this != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)this,in_stack_0000000c);
    return;
  }
  return;
}
}

