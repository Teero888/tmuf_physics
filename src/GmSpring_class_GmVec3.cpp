// Class implementation: GmSpring_class_GmVec3

// =================================================
// Function: GmSpring<class_GmVec3>::ClearVals
// =================================================
void __thiscall GmSpring<class_GmVec3>::ClearVals(void *this,GmSpring<float> *param_1)
{
{
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  return;
}
}

// =================================================
// Function: GmSpring<class_GmVec3>::GetCriticalKa
// =================================================
float __thiscall GmSpring<class_GmVec3>::GetCriticalKa(void *this,GmSpring<class_GmVec3> *param_1)
{
{
  float10 fVar1;
  
  fVar1 = (float10)func_0x009c1b40(this);
  return (float)fVar1 + (float)fVar1;
}
}

// =================================================
// Function: GmSpring<class_GmVec3>::Integrate
// =================================================
void __thiscall GmSpring<class_GmVec3>::Integrate(void *this,SRealTimeState *param_1,float param_2)
{
{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)this;
  fVar2 = -*(float *)((int)this + 4);
  *(float *)((int)this + 0x20) =
       *(float *)((int)this + 0x20) +
       (float)param_1 *
       (fVar2 * *(float *)((int)this + 0x20) +
       fVar1 * (*(float *)((int)this + 0x14) - *(float *)((int)this + 8)));
  *(float *)((int)this + 0x24) =
       *(float *)((int)this + 0x24) +
       (*(float *)((int)this + 0x24) * fVar2 +
       (*(float *)((int)this + 0x18) - *(float *)((int)this + 0xc)) * fVar1) * (float)param_1;
  *(float *)((int)this + 0x28) =
       (fVar2 * *(float *)((int)this + 0x28) +
       fVar1 * (*(float *)((int)this + 0x1c) - *(float *)((int)this + 0x10))) * (float)param_1 +
       *(float *)((int)this + 0x28);
  *(float *)((int)this + 8) =
       *(float *)((int)this + 8) + *(float *)((int)this + 0x20) * (float)param_1;
  *(float *)((int)this + 0xc) =
       *(float *)((int)this + 0x24) * (float)param_1 + *(float *)((int)this + 0xc);
  *(float *)((int)this + 0x10) =
       *(float *)((int)this + 0x10) + (float)param_1 * *(float *)((int)this + 0x28);
  return;
}
}

