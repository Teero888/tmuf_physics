
/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall GmSurfPolygon::ComputeNormalFromVertices(void) */

void __thiscall GmSurfPolygon::ComputeNormalFromVertices(GmSurfPolygon *this)

{
  float fVar1;
  float10 fVar2;

  *(float *)(this + 0x3c) =
      (*(float *)(this + 0x18) - *(float *)(this + 0xc)) *
          (*(float *)(this + 0x28) - *(float *)(this + 0x10)) -
      (*(float *)(this + 0x1c) - *(float *)(this + 0x10)) *
          (*(float *)(this + 0x24) - *(float *)(this + 0xc));
  *(float *)(this + 0x40) =
      (*(float *)(this + 0x20) - *(float *)(this + 8)) *
          (*(float *)(this + 0x1c) - *(float *)(this + 0x10)) -
      (*(float *)(this + 0x14) - *(float *)(this + 8)) *
          (*(float *)(this + 0x28) - *(float *)(this + 0x10));
  *(float *)(this + 0x44) =
      (*(float *)(this + 0x24) - *(float *)(this + 0xc)) *
          (*(float *)(this + 0x14) - *(float *)(this + 8)) -
      (*(float *)(this + 0x18) - *(float *)(this + 0xc)) *
          (*(float *)(this + 0x20) - *(float *)(this + 8));
  if (*(float *)(this + 0x44) * *(float *)(this + 0x44) +
          *(float *)(this + 0x3c) * *(float *)(this + 0x3c) +
          *(float *)(this + 0x40) * *(float *)(this + 0x40) <
      _DAT_00d1fc38) {
    *(undefined4 *)(this + 0x3c) = 0x3f800000;
    *(undefined4 *)(this + 0x40) = 0;
    *(undefined4 *)(this + 0x44) = 0;
    return;
  }
  fVar2 = (float10)__CIsqrt();
  fVar1 = 1.0 / (float)fVar2;
  *(float *)(this + 0x3c) = fVar1 * *(float *)(this + 0x3c);
  *(float *)(this + 0x40) = *(float *)(this + 0x40) * fVar1;
  *(float *)(this + 0x44) = fVar1 * *(float *)(this + 0x44);
  return;
}

/* public: __thiscall GmSurfPolygon::GmSurfPolygon(unsigned char) */

GmSurfPolygon *__thiscall GmSurfPolygon::GmSurfPolygon(GmSurfPolygon *this,
                                                       uchar param_1)

{
  GmSurf::GmSurf((GmSurf *)this);
  this[0x38] = (GmSurfPolygon)param_1;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x48) = 0;
  this[6] = (GmSurfPolygon)0x5;
  return this;
}

/* public: virtual __thiscall GmSurfPolygon::~GmSurfPolygon(void) */

void __thiscall GmSurfPolygon::~GmSurfPolygon(GmSurfPolygon *this)

{
  *(undefined ***)this = GmSurf::vftable;
  return;
}
