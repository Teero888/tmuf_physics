// Class implementation: CSceneVehicle_SEnvironment

// =================================================
// Function: CSceneVehicle::SEnvironment::SEnvironment
// =================================================
void __thiscall CSceneVehicle::SEnvironment::SEnvironment(void *this,SEnvironment *param_1)
{
{
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  
  *(undefined4 *)this = 0;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>((void *)((int)this + 4),unaff_ESI);
  return;
}
}

// =================================================
// Function: CSceneVehicle::SEnvironment::~SEnvironment
// =================================================
void __thiscall CSceneVehicle::SEnvironment::~SEnvironment(void *this,SEnvironment *param_1)
{
{
  CMwNod *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00acce58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = (void *)0x0;
  CFastArray<class_CMwNodRef<class_CPlugVertexStream>_>::
  ~CFastArray<class_CMwNodRef<class_CPlugVertexStream>_>
            ((void *)((int)this + 4),
             (CFastArray<class_CMwNodRef<class_CPlugVertexStream>_> *)
             (DAT_00cca150 ^ (uint)&stack0xffffffec));
  if (*(CMwNod **)this != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)this,unaff_ESI);
  }
  ExceptionList = local_4;
  return;
}
}

