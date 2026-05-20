// Class implementation: CHmsZoneElem

// =================================================
// Function: CHmsZoneElem::CHmsZoneElem
// =================================================
void __thiscall CHmsZoneElem::CHmsZoneElem(CHmsZoneElem *this,CHmsZoneElem *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  return;
}
}

// =================================================
// Function: CHmsZoneElem::~CHmsZoneElem
// =================================================
void __thiscall CHmsZoneElem::~CHmsZoneElem(CHmsZoneElem *this,CHmsZoneElem *param_1)
{
{
  *(undefined ***)this = vftable;
  CMwNod::~CMwNod((CMwNod *)this,(CMwNod *)param_1);
  return;
}
}

