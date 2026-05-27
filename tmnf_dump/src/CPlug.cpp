// Class implementation: CPlug

// =================================================
// Function: CPlug::CPlug
// =================================================
void __thiscall CPlug::CPlug(CPlug *this,CPlug *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  return;
}
}

// =================================================
// Function: CPlug::~CPlug
// =================================================
void __thiscall CPlug::~CPlug(CPlug *this,CPlug *param_1)
{
{
  *(undefined ***)this = vftable;
  CMwNod::~CMwNod((CMwNod *)this,(CMwNod *)param_1);
  return;
}
}

