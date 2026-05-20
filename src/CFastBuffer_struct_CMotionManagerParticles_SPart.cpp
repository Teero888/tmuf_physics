// Class implementation: CFastBuffer_struct_CMotionManagerParticles_SPart

// =================================================
// Function: CFastBuffer<struct_CMotionManagerParticles::SPart>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_CMotionManagerParticles::SPart>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(iVar1 * 0x94 + *(int *)((int)this + 4));
}
}

