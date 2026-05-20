
/* public: virtual void * __thiscall GmSurfSphere::`vector deleting
 * destructor'(unsigned int) */

void *__thiscall GmSurfSphere::`vector_deleting_destructor'(GmSurfSphere *this,uint param_1)

{
  GmSurf::~GmSurf((GmSurf *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: int __thiscall GmSurfSphere::ClipSegment(class GmVec3 const &,class
   GmVec3 const &,class GmVec3 const &,float &)const  */

int __thiscall GmSurfSphere::ClipSegment(GmSurfSphere *this, GmVec3 *param_1,
                                         GmVec3 *param_2, GmVec3 *param_3,
                                         float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;

  fVar1 = *(float *)param_1 - *(float *)param_3;
  fVar2 = *(float *)(param_1 + 4) - *(float *)(param_3 + 4);
  fVar3 = *(float *)(param_1 + 8) - *(float *)(param_3 + 8);
  fVar4 = fVar3 * *(float *)(param_2 + 8) + fVar2 * *(float *)(param_2 + 4) +
          fVar1 * *(float *)param_2;
  fVar5 = *(float *)(param_2 + 8) * *(float *)(param_2 + 8) +
          *(float *)param_2 * *(float *)param_2 +
          *(float *)(param_2 + 4) * *(float *)(param_2 + 4);
  fVar1 =
      fVar4 * fVar4 * 4.0 - ((fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3) -
                             *(float *)(this + 8) * *(float *)(this + 8)) *
                                fVar5 * 4.0;
  if (fVar1 < 0.0 == NAN(fVar1)) {
    fVar6 = (float10)__CIsqrt();
    fVar5 = (-fVar4 - (float)fVar6 * 0.5) / fVar5;
    if ((fVar5 < 0.0 == NAN(fVar5)) && (1.0 < fVar5 == NAN(fVar5))) {
      *param_4 = fVar5;
      return 1;
    }
  }
  return 0;
}

/* public: void __thiscall GmSurfSphere::GetSphereBoundingBox(class GmBoxAligned
 * &)const  */

void __thiscall GmSurfSphere::GetSphereBoundingBox(GmSurfSphere *this,
                                                   GmBoxAligned *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;

  uVar1 = *(undefined4 *)(this + 8);
  uVar2 = *(undefined4 *)(this + 8);
  uVar3 = *(undefined4 *)(this + 8);
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  *(undefined4 *)(param_1 + 0x14) = uVar3;
  return;
}

/* public: __thiscall GmSurfSphere::GmSurfSphere(void) */

GmSurfSphere *__thiscall GmSurfSphere::GmSurfSphere(GmSurfSphere *this)

{
  GmSurf::GmSurf((GmSurf *)this);
  *(undefined ***)this = vftable;
  this[6] = (GmSurfSphere)0x0;
  return this;
}
