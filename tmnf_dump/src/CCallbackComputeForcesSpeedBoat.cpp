// Class implementation: CCallbackComputeForcesSpeedBoat

// =================================================
// Function: CCallbackComputeForcesSpeedBoat::ComputeForces
// =================================================
void __thiscall
CCallbackComputeForcesSpeedBoat::ComputeForces
          (CCallbackComputeForcesSpeedBoat *this,CCallbackSceneToyBroomStickComputeForces *param_1,
          CHmsItem *param_2,float param_3)
{
{
  CHmsItem *unaff_retaddr;
  
  CSceneVehicleSpeedBoat::ComputeForces
            (*(CSceneVehicleSpeedBoat **)(param_1 + 0x40),
             (CCallbackSceneToyBroomStickComputeForces *)param_2,unaff_retaddr,(float)param_1);
  return;
}
}

// =================================================
// Function: CCallbackComputeForcesSpeedBoat::_vector_deleting_destructor_
// =================================================
void * __thiscall
CCallbackComputeForcesSpeedBoat::_vector_deleting_destructor_
          (CCallbackComputeForcesSpeedBoat *this,CRpcCallInternal *param_1,uint param_2)
{
{
  CCallback *unaff_ESI;
  
  CHmsItem::CCallback::~CCallback((CCallback *)this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

