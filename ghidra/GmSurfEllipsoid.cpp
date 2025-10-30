
/* public: virtual void * __thiscall GmSurfEllipsoid::`vector deleting
 * destructor'(unsigned int) */

void *__thiscall GmSurfEllipsoid::`vector_deleting_destructor'(GmSurfEllipsoid *this,uint param_1)

{
  ~GmSurfEllipsoid(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: void __thiscall GmSurfEllipsoid::CreateEllipsoidDefaultData(void) */

void __thiscall GmSurfEllipsoid::CreateEllipsoidDefaultData(
    GmSurfEllipsoid *this)

{
  *(undefined4 *)(this + 8) = 0x3f800000;
  *(undefined4 *)(this + 0xc) = 0x3f800000;
  *(undefined4 *)(this + 0x10) = 0x3f800000;
  return;
}

/* public: void __thiscall GmSurfEllipsoid::GetEllipsoidBoundingBox(class
 * GmBoxAligned &)const  */

void __thiscall GmSurfEllipsoid::GetEllipsoidBoundingBox(GmSurfEllipsoid *this,
                                                         GmBoxAligned *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;

  uVar1 = *(undefined4 *)(this + 8);
  uVar2 = *(undefined4 *)(this + 0xc);
  uVar3 = *(undefined4 *)(this + 0x10);
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  *(undefined4 *)(param_1 + 0x14) = uVar3;
  return;
}

/* public: __thiscall GmSurfEllipsoid::GmSurfEllipsoid(void) */

GmSurfEllipsoid *__thiscall GmSurfEllipsoid::GmSurfEllipsoid(
    GmSurfEllipsoid *this)

{
  GmSurf::GmSurf((GmSurf *)this);
  *(undefined ***)this = vftable;
  this[6] = (GmSurfEllipsoid)0x1;
  return this;
}

/* public: virtual __thiscall GmSurfEllipsoid::~GmSurfEllipsoid(void) */

void __thiscall GmSurfEllipsoid::~GmSurfEllipsoid(GmSurfEllipsoid *this)

{
  *(undefined ***)this = vftable;
  GmSurf::~GmSurf((GmSurf *)this);
  return;
}
