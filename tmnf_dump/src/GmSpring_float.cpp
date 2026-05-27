// Class implementation: GmSpring_float

// =================================================
// Function: GmSpring<float>::ClearVals
// =================================================
void __thiscall GmSpring<float>::ClearVals(void *this,GmSpring<float> *param_1)
{
{
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  return;
}
}

// =================================================
// Function: GmSpring<float>::GmSpring<float>
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmSpring<float>::GmSpring<float>(void *this,GmSpring<float> *param_1)
{
{
  GmSpring<class_GmVec3> *unaff_ESI;
  float fVar1;
  GmSpring<float> *unaff_retaddr;
  
  *(undefined4 *)this = _DAT_00b313e0;
  fVar1 = GmSpring<class_GmVec3>::GetCriticalKa(this,unaff_ESI);
  *(float *)((int)this + 4) = fVar1;
  ClearVals(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: GmSpring<float>::Integrate
// =================================================
void __thiscall GmSpring<float>::Integrate(void *this,SRealTimeState *param_1,float param_2)
{
{
  float fVar1;
  
  fVar1 = *(float *)((int)this + 0x10) +
          (float)param_1 *
          ((*(float *)((int)this + 0xc) - *(float *)((int)this + 8)) * *(float *)this -
          *(float *)((int)this + 4) * *(float *)((int)this + 0x10));
  *(float *)((int)this + 0x10) = fVar1;
  *(float *)((int)this + 8) = fVar1 * (float)param_1 + *(float *)((int)this + 8);
  return;
}
}

