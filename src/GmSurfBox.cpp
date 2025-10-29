
/* public: __thiscall GmSurfBox::GmSurfBox(void) */

GmSurfBox *__thiscall GmSurfBox::GmSurfBox(GmSurfBox *this)

{
  GmSurf::GmSurf((GmSurf *)this);
  *(undefined ***)this = vftable;
  this[6] = (GmSurfBox)0x6;
  return this;
}
