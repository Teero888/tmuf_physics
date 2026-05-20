// Class implementation: GmSurfPolygon

// =================================================
// Function: GmSurfPolygon::GmSurfPolygon
// =================================================
void __thiscall
GmSurfPolygon::GmSurfPolygon(GmSurfPolygon *this,GmSurfPolygon *param_1,uchar param_2)
{
{
  GmSurf *unaff_ESI;
  
  GmSurf::GmSurf((GmSurf *)this,unaff_ESI);
  this[0x38] = (GmSurfPolygon)param_2;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x48) = 0;
  this[6] = (GmSurfPolygon)0x5;
  return;
}
}

